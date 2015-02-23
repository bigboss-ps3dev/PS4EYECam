/*
 *	PlayStation 4 Camera driver
 *	Copyright (C) 2013,2014 Antonio Jose Ramos Marquez (aka bigboss) @psxdev on twitter
 *
 *  Repository https://github.com/bigboss-ps3dev/PS4EYECam
 *  some parts are based on PS3EYECamera driver https://github.com/inspirit/PS3EYEDriver
 *  some parts were commited to ps4eye https://github.com/ps4eye/ps4eye
 *
 *  This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public Licence as published by
 *	the Free Software Foundation; either version 2 of the Licence, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *	GNU General Public Licence for more details.
 *
 *	You should have received a copy of the GNU General Public Licence
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 *  If you redistribute this file in source form, modified or unmodified, you
 *  may:
 *  1) Leave this header intact and distribute it under the same terms,
 *  accompanying it with the GPL20 or later files, or
 *  In all cases you must keep the copyright notice intact
 * 
 *  Binary distributions must follow the binary distribution requirements of
 *  license.
 *
 */

#include <algorithm>
#include "ps4eye.h"
#include "ps4eye_regs.h"
#include "libusb.h"
#include <iostream>
#include <fstream>
#if defined WIN32 || defined _WIN32 || defined WINCE
#include <windows.h>
#else
#include <sys/time.h>
#include <time.h>
#if defined __MACH__ && defined __APPLE__
#include <mach/mach.h>
#include <mach/mach_time.h>
#endif
#endif

#define CHUNK_SIZE 512

using namespace std;

namespace ps4eye {

    //defines and uvc types from libuvc
    /** Converts an unaligned four-byte little-endian integer into an int32 */
#define DW_TO_INT(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))
    /** Converts an unaligned two-byte little-endian integer into an int16 */
#define SW_TO_SHORT(p) ((p)[0] | ((p)[1] << 8))
    /** Converts an int16 into an unaligned two-byte little-endian integer */
#define SHORT_TO_SW(s, p) \
(p)[0] = (s); \
(p)[1] = (s) >> 8;
    /** Converts an int32 into an unaligned four-byte little-endian integer */
#define INT_TO_DW(i, p) \
(p)[0] = (i); \
(p)[1] = (i) >> 8; \
(p)[2] = (i) >> 16; \
(p)[3] = (i) >> 24;
    typedef struct uvc_stream_ctrl {
        uint16_t bmHint;
        uint8_t bFormatIndex;
        uint8_t bFrameIndex;
        uint32_t dwFrameInterval;
        uint16_t wKeyFrameRate;
        uint16_t wPFrameRate;
        uint16_t wCompQuality;
        uint16_t wCompWindowSize;
        uint16_t wDelay;
        uint32_t dwMaxVideoFrameSize;
        uint32_t dwMaxPayloadTransferSize;
        uint32_t dwClockFrequency;
        uint8_t bmFramingInfo;
        uint8_t bPreferredVersion;
        uint8_t bMinVersion;
        uint8_t bMaxVersion;
        uint8_t bInterfaceNumber;
	} uvc_stream_ctrl_t;
    /** UVC request code (A.8) */
    enum uvc_req_code {
        UVC_RC_UNDEFINED = 0x00,
        UVC_SET_CUR = 0x01,
        UVC_GET_CUR = 0x81,
        UVC_GET_MIN = 0x82,
        UVC_GET_MAX = 0x83,
        UVC_GET_RES = 0x84,
        UVC_GET_LEN = 0x85,
        UVC_GET_INFO = 0x86,
        UVC_GET_DEF = 0x87
    };

#define  REQ_TYPE_SET  0x21
#define  REQ_TYPE_GET  0xa1
    enum uvc_device_power_mode {
        UVC_VC_VIDEO_POWER_MODE_FULL = 0x000b,
        UVC_VC_VIDEO_POWER_MODE_DEVICE_DEPENDENT = 0x001b,
    };

    /** Camera terminal control selector (A.9.4) */
    enum uvc_ct_ctrl_selector {
        UVC_CT_CONTROL_UNDEFINED = 0x00,
        UVC_CT_SCANNING_MODE_CONTROL = 0x01,
        UVC_CT_AE_MODE_CONTROL = 0x02,
        UVC_CT_AE_PRIORITY_CONTROL = 0x03,
        UVC_CT_EXPOSURE_TIME_ABSOLUTE_CONTROL = 0x04,
        UVC_CT_EXPOSURE_TIME_RELATIVE_CONTROL = 0x05,
        UVC_CT_FOCUS_ABSOLUTE_CONTROL = 0x06,
        UVC_CT_FOCUS_RELATIVE_CONTROL = 0x07,
        UVC_CT_FOCUS_AUTO_CONTROL = 0x08,
        UVC_CT_IRIS_ABSOLUTE_CONTROL = 0x09,
        UVC_CT_IRIS_RELATIVE_CONTROL = 0x0a,
        UVC_CT_ZOOM_ABSOLUTE_CONTROL = 0x0b,
        UVC_CT_ZOOM_RELATIVE_CONTROL = 0x0c,
        UVC_CT_PANTILT_ABSOLUTE_CONTROL = 0x0d,
        UVC_CT_PANTILT_RELATIVE_CONTROL = 0x0e,
        UVC_CT_ROLL_ABSOLUTE_CONTROL = 0x0f,
        UVC_CT_ROLL_RELATIVE_CONTROL = 0x10,
        UVC_CT_PRIVACY_CONTROL = 0x11,
        UVC_CT_FOCUS_SIMPLE_CONTROL = 0x12,
        UVC_CT_DIGITAL_WINDOW_CONTROL = 0x13,
        UVC_CT_REGION_OF_INTEREST_CONTROL = 0x14
    };

    /** Processing unit control selector (A.9.5) */
    enum uvc_pu_ctrl_selector {
        UVC_PU_CONTROL_UNDEFINED = 0x00,
        UVC_PU_BACKLIGHT_COMPENSATION_CONTROL = 0x01,
        UVC_PU_BRIGHTNESS_CONTROL = 0x02,
        UVC_PU_CONTRAST_CONTROL = 0x03,
        UVC_PU_GAIN_CONTROL = 0x04,
        UVC_PU_POWER_LINE_FREQUENCY_CONTROL = 0x05,
        UVC_PU_HUE_CONTROL = 0x06,
        UVC_PU_SATURATION_CONTROL = 0x07,
        UVC_PU_SHARPNESS_CONTROL = 0x08,
        UVC_PU_GAMMA_CONTROL = 0x09,
        UVC_PU_WHITE_BALANCE_TEMPERATURE_CONTROL = 0x0a,
        UVC_PU_WHITE_BALANCE_TEMPERATURE_AUTO_CONTROL = 0x0b,
        UVC_PU_WHITE_BALANCE_COMPONENT_CONTROL = 0x0c,
        UVC_PU_WHITE_BALANCE_COMPONENT_AUTO_CONTROL = 0x0d,
        UVC_PU_DIGITAL_MULTIPLIER_CONTROL = 0x0e,
        UVC_PU_DIGITAL_MULTIPLIER_LIMIT_CONTROL = 0x0f,
        UVC_PU_HUE_AUTO_CONTROL = 0x10,
        UVC_PU_ANALOG_VIDEO_STANDARD_CONTROL = 0x11,
        UVC_PU_ANALOG_LOCK_STATUS_CONTROL = 0x12,
        UVC_PU_CONTRAST_AUTO_CONTROL = 0x13
    };



#ifndef ARRAY_SIZE
#define ARRAY_SIZE(_A) (sizeof(_A) / sizeof((_A)[0]))
#endif
    // timestapms
    // WIN and MAC only
    static int64_t getTickCount()
    {
#if defined WIN32 || defined _WIN32 || defined WINCE
        LARGE_INTEGER counter;
        QueryPerformanceCounter( &counter );
        return (int64_t)counter.QuadPart;
#else
        return (int64_t)mach_absolute_time();
#endif
    }

    static double getTickFrequency()
    {
#if defined WIN32 || defined _WIN32 || defined WINCE
        LARGE_INTEGER freq;
        QueryPerformanceFrequency(&freq);
        return (double)freq.QuadPart;
#else
        static double freq = 0;
        if( freq == 0 )
        {
            mach_timebase_info_data_t sTimebaseInfo;
            mach_timebase_info(&sTimebaseInfo);
            freq = sTimebaseInfo.denom*1e9/sTimebaseInfo.numer;
        }
        return freq;
#endif
    }
    //

    /* Values for bmHeaderInfo (Video and Still Image Payload Headers, 2.4.3.3) */
#define UVC_STREAM_EOH	(1 << 7)
#define UVC_STREAM_ERR	(1 << 6)
#define UVC_STREAM_STI	(1 << 5)
#define UVC_STREAM_RES	(1 << 4)
#define UVC_STREAM_SCR	(1 << 3)
#define UVC_STREAM_PTS	(1 << 2)
#define UVC_STREAM_EOF	(1 << 1)
#define UVC_STREAM_FID	(1 << 0)

    /* packet types when moving from iso buf to frame buf */
    enum gspca_packet_type {
        DISCARD_PACKET,
        FIRST_PACKET,
        INTER_PACKET,
        LAST_PACKET
    };


    const uint16_t PS4EYECam::VENDOR_ID = 0x05a9;
    const uint16_t PS4EYECam::PRODUCT_ID = 0x058a;

    class USBMgr
    {
    public:
        USBMgr();
        ~USBMgr();

        static std::shared_ptr<USBMgr>  instance();
        static libusb_context* usbContext() { return instance()->usb_context; }
        static int listDevices(std::vector<PS4EYECam::PS4EYERef>& list);
        static bool handleEvents();

        static std::shared_ptr<USBMgr>  sInstance;
        static int                      sTotalDevices;

    private:
        libusb_context* usb_context;
        struct libusb_transfer * control_transfer;
        uint8_t * control_transfer_buffer;

        USBMgr(const USBMgr&);
        void operator=(const USBMgr&);
    };

    std::shared_ptr<USBMgr> USBMgr::sInstance;
    int                     USBMgr::sTotalDevices = 0;

    USBMgr::USBMgr()
    {
        libusb_init(&usb_context);
        libusb_set_debug(usb_context, 3);
    }

    USBMgr::~USBMgr()
    {
        debug("USBMgr destructor called\n");
        libusb_exit(usb_context);
        //  libusb_exit(NULL);

    }

    std::shared_ptr<USBMgr> USBMgr::instance()
    {
        if( !sInstance ) {
            sInstance = std::shared_ptr<USBMgr>( new USBMgr );
        }
        return sInstance;
    }

    bool USBMgr::handleEvents()
    {
        return (libusb_handle_events(instance()->usb_context) == 0);
    }

    int USBMgr::listDevices( std::vector<PS4EYECam::PS4EYERef>& list )
    {
        libusb_device *dev;
        libusb_device **devs;
        int i = 0;
        int cnt;

        cnt = libusb_get_device_list(instance()->usb_context, &devs);

        if (cnt < 0)
            debug("Error Device scan\n");

        cnt = 0;
        while ((dev = devs[i++]) != NULL)
        {
            struct libusb_device_descriptor desc;
            libusb_get_device_descriptor(dev, &desc);
            if(desc.idVendor == PS4EYECam::VENDOR_ID && desc.idProduct == PS4EYECam::PRODUCT_ID)
            {
                std::cout<<"Found PlayStation Camera" << std::endl;
                list.push_back( PS4EYECam::PS4EYERef( new PS4EYECam(dev,true) ) );
                libusb_ref_device(dev);
                cnt++;
            }
            if(desc.idVendor == 0x05a9 && desc.idProduct == 0x0580)
            {
                std::cout<<"Found ov580 boot mode Camera" << std::endl;
                list.push_back( PS4EYECam::PS4EYERef( new PS4EYECam(dev,false) ) );
                libusb_ref_device(dev);
                cnt++;
            }
        }

        libusb_free_device_list(devs, 1);

        return cnt;
    }


    // URBDesc

    static void LIBUSB_CALL cb_xfr(struct libusb_transfer *xfr);

    class URBDesc
    {
    public:
        URBDesc(uint mode):num_transfers(0), last_packet_type(DISCARD_PACKET), last_pts(0), last_fid(0)
        {
            is_streaming=false;

            switch(mode) //set from dwMaxVideoFrameBufferSize
            {
                case 0:
                    frame_size=5571968;
                    break;
                case 1:
                    frame_size=1426368;
                    break;
                case 2:
                    frame_size=359200;
                    break;
                default:
                    frame_size=5571968;
                    break;
            }
            frame_buffer = (uint8_t*)malloc(frame_size * 16 + 49152*8*15);
            if(!frame_buffer)
            {
                debug("error reservando\n");
            }
            memset(frame_buffer, 0,frame_size * 16 + 5571968);//49152*8*15);

            frame_buffer_end = frame_buffer + frame_size * 16;

            frame_data_start = frame_buffer;
            frame_data_len = 0;
            frame_complete_ind = 0;
            frame_work_ind = 0;
            ff71status = -2;
            frame_counter=0;
            

        }
        URBDesc() : num_transfers(0), last_packet_type(DISCARD_PACKET), last_pts(0), last_fid(0)
        {
            // we allocate max possible size
            // 16 frames
            // size_t stride = 640*2;
            // size_t stride =32+64+1280*2+1280*2+840;//
           // size_t stride =3448; //hardcoded
            is_streaming=false;
            // const size_t fsz = stride*480;
            const size_t fsz = 5571968; //hardcoded interface dwMaxVideoFrameBufferSize 5571968

            //frame_buffer = (uint8_t*)malloc(fsz * 16 + 16384*2);
            frame_buffer = (uint8_t*)malloc(fsz * 16 + 49152*8*15);
            if(!frame_buffer)
            {
                debug("error reservando\n");
            }
            memset(frame_buffer, 0,fsz * 16 + 5571968);//49152*8*15);

            frame_buffer_end = frame_buffer + fsz * 16;

            frame_data_start = frame_buffer;
            frame_data_len = 0;
            frame_complete_ind = 0;
            frame_work_ind = 0;
            frame_size = fsz;
            ff71status = -2;
            frame_counter=0;

        }
        ~URBDesc()
        {
            debug("URBDesc destructor\n");
            if(num_transfers)
            {
                close_transfers();
            }
            if(frame_buffer != NULL)
                free(frame_buffer);
            frame_buffer = NULL;
        }

        bool start_transfers(libusb_device_handle *handle, uint32_t curr_frame_size)
        {
            int i;
            struct libusb_transfer *xfr0;


            for(i=0;i<8;i++)
            {
                xfr[i]=libusb_alloc_transfer(8);
                //  xfr[i]=xfr0;

                // prepare the data packet and populate the neccessary fields
                //transfer->flags = LIBUSB_TRANSFER_ADD_ZERO_PACKET;
                /* xfr[i]->dev_handle = handle;
                 xfr[i]->endpoint = 0x81;
                 xfr[i]->type = LIBUSB_TRANSFER_TYPE_ISOCHRONOUS;
                 xfr[i]->timeout = 10000;
                 xfr[i]->buffer = frame_buffer_end+49152*8*i;
                 xfr[i]->user_data = this;
                 xfr[i]->length = 49152*8; // max size in transfer 49152*8
                 xfr[i]->callback = cb_xfr;
                 xfr[i]->num_iso_packets = 8; //num isoc*/
                libusb_fill_iso_transfer(xfr[i],handle, 0x81, frame_buffer_end+49152*8*i,  49152*8, 8, cb_xfr, reinterpret_cast<void*>(this), 1000);
                libusb_set_iso_packet_lengths(xfr[i], 49152);


            }

            int res=0;
            for(i=0;i<8;i++)
            {
                res|=libusb_submit_transfer(xfr[i]);


            }
            num_transfers = 8;
            frame_complete_ind = 0;
            frame_work_ind = 0;
            last_pts = 0;
            last_fid = 0;
            last_frame_time = 0;

            return res == 0;

        }

        void close_transfers()
        {
            int i;
            for(i=0;i<num_transfers;i++)
            {
                libusb_cancel_transfer(xfr[i]);


            }
            while(num_transfers)
            {
                if( !USBMgr::instance()->handleEvents() || num_transfers==0 )
                {
                    break;
                }
            }
        }

        void frame_add(enum gspca_packet_type packet_type, const uint8_t *data, int len)
        {
            int i;
            if (packet_type == FIRST_PACKET)
            {
                frame_data_start = frame_buffer + frame_work_ind*frame_size;
                frame_data_len = 0;
                //debug("first packet\n");
            }
            else
            {
                switch(last_packet_type)
                {
                    case DISCARD_PACKET:
                        if (packet_type == LAST_PACKET) {
                            last_packet_type = packet_type;
                            frame_data_len = 0;
                        }
                        //      debug("discard packet\n");

                        return;
                    case LAST_PACKET:
                        return;
                }
            }

            /* append the packet to the frame buffer */
            if (len > 0)
            {
                if(frame_data_len + len > frame_size)
                {
                    debug("discard packet per size %d\n",frame_data_len);

                    packet_type = DISCARD_PACKET;
                    frame_data_len = 0;
                } else {
                    memcpy(frame_data_start+frame_data_len, data, len);
                    frame_data_len += len;
                }
            }

            last_packet_type = packet_type;

            if (packet_type == LAST_PACKET)
            {
                last_frame_time = getTickCount();
                frame_complete_ind = frame_work_ind;
                i = (frame_work_ind + 1) & 15;
                frame_work_ind = i;
                frame_data_len = 0;
                //debug("frame completed %d\n", frame_complete_ind);
                //debug("frame completed %d\n", frame_counter);
                frame_counter++;
            }
        }

        void pkt_scan(uint8_t *data, int len)
        {
            uint32_t this_pts;
            uint16_t this_fid;
            int remaining_len = len;
            int payload_len;
            //debug("lengh=%d\n",len);
            //payload_len = 2048; // bulk type
            payload_len =49152;// 49152; //49152*8; // isoc superspeed usb transfer

            do {
                len = std::min(remaining_len, payload_len);

                /* Payloads are prefixed with a UVC-style header.  We
                 consider a frame to start when the FID toggles, or the PTS
                 changes.  A frame ends when EOF is set, and we've received
                 the correct number of bytes. */

                /* Verify UVC header.  Header length is always 12 */
                if (data[0] != 0xc || len < 12) {
                    //   debug("bad header\n");
                    goto discard;
                }

                /* Check errors */
                if (data[1] & UVC_STREAM_ERR) {
                    debug("payload error\n");
                    goto discard;
                }

                /* Extract PTS and FID */
                if (!(data[1] & UVC_STREAM_PTS)) {
                    debug("PTS not present\n");
                    goto discard;
                }

                this_pts = (data[5] << 24) | (data[4] << 16) | (data[3] << 8) | data[2];
                this_fid = (data[1] & UVC_STREAM_FID) ? 1 : 0;

                /* If PTS or FID has changed, start a new frame. */
                if (this_pts != last_pts || this_fid != last_fid) {
                    if (last_packet_type == INTER_PACKET)
                    {
                        frame_add(LAST_PACKET, NULL, 0);
                    }
                    last_pts = this_pts;
                    last_fid = this_fid;
                    frame_add(FIRST_PACKET, data + 12, len - 12);
                } /* If this packet is marked as EOF, end the frame */
                else if (data[1] & UVC_STREAM_EOF)
                {
                    last_pts = 0;
                    if(frame_data_len + len - 12 != frame_size)
                    {
                        goto discard;
                    }
                    frame_add(LAST_PACKET, data + 12, len - 12);
                } else {
                    /* Add the data from this payload */
                    frame_add(INTER_PACKET, data + 12, len - 12);
                }


                /* Done this payload */
                goto scan_next;

            discard:
                /* Discard data until a new frame starts. */
                frame_add(DISCARD_PACKET, NULL, 0);
            scan_next:
                remaining_len -= len;
                data += len;
            } while (remaining_len > 0);
        }

        uint8_t num_transfers;
        enum gspca_packet_type last_packet_type;
        uint32_t last_pts;
        uint16_t last_fid;
        libusb_transfer *xfr[15];

        uint8_t *frame_buffer;
        uint8_t *frame_buffer_end;
        uint8_t *frame_data_start;
        uint32_t frame_data_len;
        uint32_t frame_size;
        uint8_t frame_complete_ind;
        uint8_t frame_work_ind;
        uint32_t frame_counter;
        int8_t ff71status;
        bool is_streaming;
        double last_frame_time;
    };

    static void LIBUSB_CALL cb_xfr(struct libusb_transfer *xfr)
    {
        URBDesc *urb = reinterpret_cast<URBDesc*>(xfr->user_data);
        enum libusb_transfer_status status = xfr->status;
        int i;
        //if(PS4EYECam::isStreaming())
        //{
        if (status != LIBUSB_TRANSFER_COMPLETED)
        {
            // debug("transfer status %d\n", status);
            if(status==LIBUSB_TRANSFER_CANCELLED)
            {
             libusb_free_transfer(xfr);
             urb->num_transfers--;
            }
            else
            {
            //  if(status != LIBUSB_TRANSFER_CANCELLED)
            //{
            //  urb->close_transfers();
            // }
                if(urb->is_streaming)
               {
                    if (libusb_submit_transfer(xfr) < 0) {
                        debug("error re-submitting URB\n");
                        urb->close_transfers();
                    }
               }
            }

            return;
        }
        if (xfr->type == LIBUSB_TRANSFER_TYPE_ISOCHRONOUS) {

            if(urb->ff71status<0)
            {
                urb->ff71status++;
            }
                for (i = 0; i < xfr->num_iso_packets; i++) {
                struct libusb_iso_packet_descriptor *pack = &xfr->iso_packet_desc[i];
                if (pack->status != LIBUSB_TRANSFER_COMPLETED) {
                    fprintf(stderr, "Error: pack %u status %d\n", i, pack->status);
                    //exit(5);
                }
                else
                {
                    if(pack->actual_length>0)
                    {
                        urb->pkt_scan(xfr->buffer+49152*i, pack->actual_length);
                    }
                }

            }
        }

        // debug("length:%u, actual_length:%u\n", xfr->length, xfr->actual_length);

        // urb->pkt_scan(xfr->buffer, xfr->actual_length);
        if(urb->is_streaming)
        {
            if (libusb_submit_transfer(xfr) < 0) {
            debug("error re-submitting URB\n");
            urb->close_transfers();
            }
        }
    }


    // PS4EYECam

    bool PS4EYECam::devicesEnumerated = false;
    std::vector<PS4EYECam::PS4EYERef> PS4EYECam::devices;

    const std::vector<PS4EYECam::PS4EYERef>& PS4EYECam::getDevices( bool forceRefresh )
    {
        if( devicesEnumerated && ( ! forceRefresh ) )
            return devices;

        devices.clear();

        USBMgr::instance()->sTotalDevices = USBMgr::instance()->listDevices(devices);

        devicesEnumerated = true;
        return devices;
    }

    bool PS4EYECam::updateDevices()
    {
        return USBMgr::instance()->handleEvents();
    }


    PS4EYECam::PS4EYECam(libusb_device *device, bool firmware_check)
    {
        // default controls

        handle_ = NULL;


        is_streaming = false;
        rightflag=0;
        device_ = device;
        mgrPtr = USBMgr::instance();
        //urb = std::shared_ptr<URBDesc>( new URBDesc() );


        // create a usb control trasfer packet. This is used to send commands to the device.
        control_transfer= libusb_alloc_transfer(0);
        control_transfer_buffer = new uint8_t[72];
        //flag to check if firmware is loaded
        firmwareisloaded=firmware_check;

    }

    PS4EYECam::~PS4EYECam()
    {
        debug("PS4EYECAM destructor\n");
        stop();
        release();
    }

    void PS4EYECam::release()
    {
        debug("PS4EYECAM release called\n");

        if(handle_ != NULL)
            close_usb();
        if(control_transfer_buffer) free(control_transfer_buffer);
        if(myframe.unknown1)free(myframe.unknown1);
        if(myframe.unknown2)free(myframe.unknown2);
        if(myframe.videoLeftFrame)free(myframe.videoLeftFrame);
        if(myframe.videoRightFrame)free(myframe.videoRightFrame);
        if(myframe.unknown3)free(myframe.unknown3);

    }

    /*
     * Write multiple registers "a7" mode of the chips managed by ov580
     * data have register list address, value , subaddress
     * len number of register to write
     */
    void PS4EYECam::multia7_register_write(const uint16_t data[][3], uint8_t len)
    {
        int i;
        debug("BEGIN MULTIWRITE USB brequest a7\n");
        /* int size= ARRAY_SIZE(data);
         debug("size es %d\n",size);*/
        uint8_t *buffer_out=new unsigned char[len*4+16]();
        buffer_out[8]=0x02;
        for(i=0;i<len;i++)
        {
            buffer_out[16+(4*i)+1]=((data[i][0])>>8)&0xff;
            buffer_out[16+(4*i)]=(data[i][0])&0xff;
            buffer_out[16+(4*i)+2]=data[i][1];
            buffer_out[16+(4*i)+3]=data[i][2];
        }
        /* debug("USB HEADER\n");
         for(i=0;i<8;i++)
         {
         debug("0x%02x ",buffer_out[i]);
         }*/
        debug("\nUSB DATA HEADER BYTE 8 TO 15\n");
        for(i=8;i<16;i++)
        {
            debug("0x%02x ",buffer_out[i]);
        }
        debug("\nUSB DATA REGISTER LIST\n");

        i=16;
        while(i<=len*4+16-4)
        {


            debug("%i 0x%02x 0x%02x 0x%02x 0x%02x \n",i,buffer_out[i],buffer_out[i+1],buffer_out[i+2],buffer_out[i+3]);
            i=i+4;

        }
        /*Send register to write to subaddr*/
        submitAndWait_controlTransfer(LIBUSB_ENDPOINT_OUT|LIBUSB_REQUEST_TYPE_VENDOR|LIBUSB_RECIPIENT_DEVICE,
                                      SET_REGISTER,
                                      0,
                                      0,
                                      len*4+8,
                                      buffer_out);

        sleep(1);
        delete[] buffer_out;
        debug("END MULTIWRITE USB\n");
    }

    /*
     * Write multiple registers to one of the chips managed by ov580
     * data have register list address, value pairs
     * len number of register to write
     * subaddr to choose right device
     */
    void PS4EYECam::multi_register_write(const uint16_t data[][2], uint8_t len, uint8_t subaddr)
    {

        int i;
        debug("BEGIN MULTIWRITE USB brequest a4\n");
        /* int size= ARRAY_SIZE(data);
         debug("size es %d\n",size);*/
        uint8_t *buffer_out=new unsigned char[len*4+16]();
        switch (subaddr) {
            case OV9713_SENSOR1_SUBADDR:  /* for writing sensor1 only?*/
                buffer_out[8]=0x03;
                break;
            case OV9713_SENSOR2_SUBADDR: /* for writing sensor2 only?*/
                buffer_out[8]=0x03;
                break;
            case OV9713_SENSORS_SUBADDR: /*it seems that 0x03 is for writing registers in both image sensors at the same time*/
                buffer_out[8]=0x03;
                break;
            case 0xff: /*it seems that 0xff is for writing ov580 registers*/
                buffer_out[8]=0x03;
                break;
                /*  case 0xac:
                 buffer_out[0]=0x??;
                 break;*/
            case 0x30:
                buffer_out[8]=0x0f;
                break;
            case 0x24:
                buffer_out[8]=0x0b;
                break;
            default:
                break;
        }
        for(i=0;i<len;i++)
        {
            buffer_out[16+(4*i)+1]=((data[i][0])>>8)&0xff;
            buffer_out[16+(4*i)]=(data[i][0])&0xff;
            buffer_out[16+(4*i)+2]=data[i][1];
            buffer_out[16+(4*i)+3]=subaddr;
        }
        /* debug("USB HEADER\n");
         for(i=0;i<8;i++)
         {
         debug("0x%02x ",buffer_out[i]);
         }*/
        debug("\nUSB DATA HEADER BYTE 8 TO 15\n");
        for(i=8;i<16;i++)
        {
            debug("0x%02x ",buffer_out[i]);
        }
        debug("\nUSB DATA REGISTER LIST\n");

        i=16;
        while(i<=len*4+16-4)
        {
            debug("%i 0x%02x 0x%02x 0x%02x 0x%02x \n",i,buffer_out[i],buffer_out[i+1],buffer_out[i+2],buffer_out[i+3]);
            i=i+4;
        }
        /*Send register to write to subaddr*/
        submitAndWait_controlTransfer(LIBUSB_ENDPOINT_OUT|LIBUSB_REQUEST_TYPE_VENDOR|LIBUSB_RECIPIENT_DEVICE,
                                      SET_REGISTER,
                                      0,
                                      0,
                                      len*4+8,
                                      buffer_out);

        //sleep(1);
        usleep(1000);
        delete[] buffer_out;
        debug("END MULTIWRITE USB\n");
    }
    /*
     * Dump multiple registers from start address to finish address of the chips managed by ov580
     * start begin address
     * finish end address
     * subaddr to choose right device
     */
    void PS4EYECam::dump_registers(uint16_t start,uint16_t finish,uint8_t subaddr)
    {

        uint8_t val=0;
        debug("READ register BEGIN from 0x%04x - 0x%04x\n ",start,finish);
        while(start<=finish)
        {
            val=register_read(start,subaddr);
            if(val>=0)
            {
                debug("READ register 0x%04x: 0x%02x\n ",start,val);
            }
            else
            {
                debug("READ register 0x%04x: READ ERROR ",start);
            }
            //   sleep(1);
            start++;
        }
        debug("READ FROM SUBADDR 0x%02x END \n",subaddr);
    }
    /*
     * Read multiple registers from one of the chips managed by ov580
     * data have register list
     * len number of register to read
     * subaddr to choose right device
     */
    void PS4EYECam::multi_register_read(const uint16_t (*data),uint8_t len, uint8_t subaddr)
    {

        int i;
        uint8_t val;
        for(i=0;i<len;i++)
        {
            val=register_read(data[i],subaddr);
            if(val>=0)
            {
                debug("READ register 0x%04x: 0x%02x\n ",data[i],val);
            }
            else
            {
                debug("READ register 0x%04x: READ ERROR ",data[i]);
            }
            // sleep(1);
        }
    }


    /*
     * Write a register to one of the chips managed by ov580
     * We send reg to write, value and subaddr with brequest 0xa4
     * then in second phase with brequest 0xa6 we received value from register
     * reg 16 bit register to write
     * val 8 bit value to write
     * subaddr 8 bit subaddress chip select
     * usb control transfer user data format 64 bytes
     * OUT format
     * byte 0 it seem to depend to subbaddr value
     * byte 1-7 00
     * byte 8 reg low  byte
     * byte 9 reg high byte
     * byte 10 val
     * byte 11 subaddr
     */
    void PS4EYECam::register_write(uint16_t reg, uint8_t val,uint8_t subaddr)
    {
        //debug("reg: 0x%02x, val: 0x%02x", reg, val);

        uint8_t buffer_out[72]={};
        switch (subaddr) {
            case OV9713_SENSOR1_SUBADDR:  /* for writing sensor1 only?*/
                buffer_out[8]=0x03;
                break;
            case OV9713_SENSOR2_SUBADDR: /* for writing sensor2 only?*/
                buffer_out[8]=0x03;
                break;
            case OV9713_SENSORS_SUBADDR: /*it seems that 0x03 is for writing registers in both image sensors at the same time*/
                buffer_out[8]=0x03;
                break;
            case 0xff: /*it seems that 0xff is for writing ov580 registers*/
                buffer_out[8]=0x03;
                break;
                /*  case 0xac:
                 buffer_out[8]=0x??;
                 break;*/
            case 0x30:
                buffer_out[8]=0x0f;
                break;
            case 0x24:
                buffer_out[8]=0x0b;
                break;
            default:
                break;
        }
        buffer_out[17]=(reg>>8)&0xff;
        buffer_out[16]=reg&0xff;
        buffer_out[18]=val;
        buffer_out[19]=subaddr;

        /*Send register to write to subaddr*/
        submitAndWait_controlTransfer(LIBUSB_ENDPOINT_OUT|LIBUSB_REQUEST_TYPE_VENDOR|LIBUSB_RECIPIENT_DEVICE,
                                      SET_REGISTER,
                                      0,
                                      0,
                                      0X40,
                                      buffer_out);
    }

    /*
     * Read a register from one of the chips managed by ov580
     * Read in done in 2 phases, first we send reg to read and subaddr with brequest 0xa5
     * then in second phase with brequest 0xa6 we received value from register
     * reg 16 bit register to read
     * subaddr 8 bit subaddress chip select
     * usb control transfer user data format 64 bytes
     * OUT format
     * byte 0 it seem to depend to subbaddr value
     * byte 1-7 00 always
     * byte 8 reg low  byte
     * byte 9 reg high byte
     * byte 10 00 (here we will received the value in second phase read)
     * byte 11 subaddr (chip select)
     * IN format like OUT format but include:
     * byte 10  value readed from reg address
     */
    uint8_t PS4EYECam::register_read(uint16_t reg,uint8_t subaddr)
    {
        int i;
        uint16_t aux;
        uint16_t aux_hi;
        uint16_t aux_lo;
        uint8_t buffer_in[72]={};
        uint8_t buffer_out[72]={};
        /*	for(i=0;i<20;i++)
         {
         debug("antes %d: 0x%02x \n",i,buffer_out[i]);
         }*/
        switch (subaddr) {
            case OV9713_SENSOR1_SUBADDR:
                buffer_out[8]=0x00;
                break;
            case OV9713_SENSOR2_SUBADDR:
                buffer_out[8]=0x00;
                break;
            case UNKNOWNFF_SUBADDR:
                buffer_out[8]=0x00;
                break;
            case C4G51A_SUBADDR:
                buffer_out[8]=0x18;
                break;
            case UNKNOWN30_SUBADDR:
                buffer_out[8]=0x0c;
                break;
            case AK5703_SUBADDR:
                buffer_out[8]=0x08;
                break;
            default:
                return -1;
                break;
        }
        buffer_out[17]=(reg>>8)&0xff;
        buffer_out[16]=reg&0xff;
        buffer_out[19]=subaddr;
        /*for(i=0;i<20;i++)
         {
         debug("pre %d: 0x%02x \n",i,buffer_out[i]);
         }*/


        /*Send register to read to subaddr*/
        submitAndWait_controlTransfer(LIBUSB_ENDPOINT_OUT|LIBUSB_REQUEST_TYPE_VENDOR|LIBUSB_RECIPIENT_DEVICE,
                                      0xa5,
                                      0,
                                      0,
                                      0X40,
                                      buffer_out);

        /*for(i=0;i<20;i++)
         {
         debug("post %d: 0x%02x \n",i,buffer_out[i]);
         }

         for(i=0;i<20;i++)
         {
         debug("prein %d: 0x%02x \n",i,buffer_out[i]);
         }*/

        usleep(1000);

        /*Receive register to read from subaddr*/
        submitAndWait_controlTransfer(LIBUSB_ENDPOINT_IN|LIBUSB_REQUEST_TYPE_VENDOR|LIBUSB_RECIPIENT_DEVICE,
                                      0xa6,
                                      0,
                                      0,
                                      0X40,
                                      buffer_in);
        /*  for(i=0;i<20;i++)
         {
         debug("postin %d: 0x%02x \n",i,buffer_out[i]);
         }*/

        aux_lo=buffer_in[16];
        aux_hi=buffer_in[17];
        aux=aux_lo|(aux_hi<<8);
        if(aux!=reg)
        {
            debug("phase 2 read failed register read  0x%04x not 0x%04x \n",aux,reg);

        }
        //   debug("read  register 0x%04x  value 0x%02x \n",reg,buffer_in[18]);
        return buffer_in[18];

    }
    /*
     * Stop OV9713 sensors streaming
     */
    void PS4EYECam::stop_sensors_streaming()
    {
        debug("stop_sensor_streaming called\n");

        register_write(OV9713_MODE_SELECT,0x0,0x3);
        is_streaming=false;

    }
    /*
     * Start OV9713 sensors streaming
     */
    void PS4EYECam::start_sensors_streaming()
    {
        register_write(OV9713_MODE_SELECT,0x1,0x3);
    }
    /*
     * Reset OV9713 sensors
     */
    void PS4EYECam::reset_sensors()
    {
        debug("reset_sensors called\n");

        register_write(OV9713_SOFTWARE_RESET,0x1,0x3);
    }
    /*
     * Set mirror OV9713 sensors
     */
    void PS4EYECam::set_mirror_sensors(uint8_t value)
    {

        stop_sensors_streaming();
        register_write(OV9713_IMAGE_ORIENTATION,value&0x1,0x3);
        start_sensors_streaming();
    }
    /*
     * Set flip OV9713 sensors
     */
    void PS4EYECam::set_flip_sensors(uint8_t value)
    {
        stop_sensors_streaming();
        register_write(OV9713_IMAGE_ORIENTATION,value&0x2,0x3);
        start_sensors_streaming();
    }
    /*
     * Set flip and mirror OV9713 sensors
     */
    void PS4EYECam::set_flip_and_mirror_sensors(uint8_t value)
    {
        stop_sensors_streaming();
        register_write(OV9713_IMAGE_ORIENTATION,value&0x3,0x3);
        start_sensors_streaming();
    }
    /*
     * Dump OV9713 general configuration and image size registers
     */
    void PS4EYECam::dump_sensor_generalconf(uint8_t n)
    {
        switch(n)
        {
            case 1:
                debug("Dumping Sensor 1 general conf registers\n");
                break;
            case 2:
                debug("Dumping Sensor 2 general conf registers\n");
                break;
            default:
                debug("%d is not a valid sensor number\n",n);
                return;
                break;
        }
        multi_register_read(sensor_generalconf_imagesize_reg_read,ARRAY_SIZE(sensor_generalconf_imagesize_reg_read),n);

    }
    /*
     * Dump OV9713 sensor video mode configuration
     */
    void PS4EYECam::dump_sensor_video_mode(uint8_t n)
    {
        switch(n)
        {
            case 1:
                break;
            case 2:
                break;
            default:
                debug("%d is not a valid sensor number\n",n);
                return;
                break;
        }
        multi_register_read(ov9713_video_mode_registers,ARRAY_SIZE(ov9713_video_mode_registers),n);


    }
    /*
     * Set OV9713 sensor video mode configuration
     */
    void PS4EYECam::set_sensor_video_mode(uint8_t mode, uint8_t n)
    {
        switch(n)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                debug("%d is not a valid sensor number\n",n);
                return;
                break;
        }

        switch(mode)
        {
            case 0:
                multi_register_write(ov9713_video_mode_0,ARRAY_SIZE(ov9713_video_mode_0),n);
                break;
            case 1:
                multi_register_write(ov9713_video_mode_1,ARRAY_SIZE(ov9713_video_mode_1),n);
                break;
            case 2:
                multi_register_write(ov9713_video_mode_2,ARRAY_SIZE(ov9713_video_mode_2),n);
                break;
            case 3:
                multi_register_write(ov9713_video_mode_3,ARRAY_SIZE(ov9713_video_mode_3),n);
                break;
            case 4:
                multi_register_write(ov9713_video_mode_4,ARRAY_SIZE(ov9713_video_mode_4),n);
                break;
            case 5:
                multi_register_write(ov9713_video_mode_5,ARRAY_SIZE(ov9713_video_mode_5),n);
                break;
            case 6:
                multi_register_write(ov9713_video_mode_6,ARRAY_SIZE(ov9713_video_mode_6),n);
                break;
            case 7:
                multi_register_write(ov9713_video_mode_7,ARRAY_SIZE(ov9713_video_mode_7),n);
                break;
            case 8:
                multi_register_write(ov9713_video_mode_8,ARRAY_SIZE(ov9713_video_mode_8),n);
                break;
            case 9:
                multi_register_write(ov9713_video_mode_9,ARRAY_SIZE(ov9713_video_mode_9),n);
                break;
            case 10:
                multi_register_write(ov9713_video_mode_10,ARRAY_SIZE(ov9713_video_mode_10),n);
                break;
            case 11:
                multi_register_write(ov9713_video_mode_11,ARRAY_SIZE(ov9713_video_mode_11),n);
                break;
            case 12:
                multi_register_write(ov9713_video_mode_12,ARRAY_SIZE(ov9713_video_mode_12),n);
                break;
            case 13:
                multi_register_write(ov9713_video_mode_13,ARRAY_SIZE(ov9713_video_mode_13),n);
                break;
            case 14:
                multi_register_write(ov9713_video_mode_14,ARRAY_SIZE(ov9713_video_mode_14),n);
                break;
            case 15:
                multi_register_write(ov9713_video_mode_15,ARRAY_SIZE(ov9713_video_mode_15),n);
                break;
            case 16:
                multi_register_write(ov9713_video_mode_16,ARRAY_SIZE(ov9713_video_mode_16),n);
                break;
            case 17:
                multi_register_write(ov9713_video_mode_17,ARRAY_SIZE(ov9713_video_mode_17),n);
                break;
            case 18:
                multi_register_write(ov9713_video_mode_18,ARRAY_SIZE(ov9713_video_mode_18),n);
                break;
            case 19:
                multi_register_write(ov9713_video_mode_19,ARRAY_SIZE(ov9713_video_mode_19),n);
                break;
            case 20:
                multi_register_write(ov9713_video_mode_20,ARRAY_SIZE(ov9713_video_mode_20),n);
                break;
            case 21:
                multi_register_write(ov9713_video_mode_21,ARRAY_SIZE(ov9713_video_mode_21),n);
                break;
            case 22:
                multi_register_write(ov9713_video_mode_22,ARRAY_SIZE(ov9713_video_mode_22),n);
                break;
            case 23:
                multi_register_write(ov9713_video_mode_23,ARRAY_SIZE(ov9713_video_mode_23),n);
                break;
            case 24:
                multi_register_write(ov9713_video_mode_24,ARRAY_SIZE(ov9713_video_mode_24),n);
                break;
            case 25:
                multi_register_write(ov9713_video_mode_25,ARRAY_SIZE(ov9713_video_mode_25),n);
                break;
            case 26:
                multi_register_write(ov9713_video_mode_26,ARRAY_SIZE(ov9713_video_mode_26),n);
                break;
            case 27:
                multi_register_write(ov9713_video_mode_27,ARRAY_SIZE(ov9713_video_mode_27),n);
                break;
            case 28:
                multi_register_write(ov9713_video_mode_28,ARRAY_SIZE(ov9713_video_mode_28),n);
                break;
            default:
                debug("%d is not a valid mode number\n",mode);
                break;
        }

    }

    void PS4EYECam::set_led_off()
    {
        debug("set_led_off called\n");

        register_write(0x2706,0x00,0xff);
    }
    void PS4EYECam::set_led_on()
    {
        register_write(0x2706,0x01,0xff);
    }

    /*
     * Read OV9713_CHIP_ID register from  OV9713 sensor
     * n can be 1 for cmos sensor one and 2 for cmos sensor two
     * return true if success
     * false if value is not 0x9713
     */
    bool PS4EYECam::read_sensor_id(uint8_t n)
    {
        uint16_t sensor_id;
        uint8_t sensor_id_h;
        uint8_t sensor_id_l;
        switch(n)
        {
            case 1:
                break;
            case 2:
                break;
            default:
                debug("%d is not a valid sensor number\n",n);
                return false;
                break;
        }
        debug("read sensor_id from sensor %d\n",n);

        sensor_id_h=register_read(OV9713_CHIP_ID_HI, n);
        sleep(1);
        sensor_id_l=register_read(OV9713_CHIP_ID_LO, n);
        sensor_id=sensor_id_h<<8|sensor_id_l;
        debug("sensor %d id 0x%04x \n",n,sensor_id);
        if(sensor_id!=0x9713)
        {
            debug("Sensor %d is not ready, exit\n",n);
           // stop_sensors_streaming();
           // reset_sensors();
            //put led off
            //set_led_off();
            // exit(0);
            return false;
        }
        return true;
    }
    /*
     * Check  if OV9713_CHIP_ID register from  OV9713 sensors
     * has right values
     * return true if they have right values
     * false if sensor one or two have bad values
     */
    bool PS4EYECam::check_sensors()
    {
        bool ret;
        //for sensor 1 we read CHIP ID. Must be 0x9713 if not something is wrong.
        ret=read_sensor_id(1);
        if(!ret)
        {
            debug("Error reading Sensor 1\n");
            return false;
        }
        //for sensor 2 we read CHIP ID. Must be 0x9713 if not something is wrong.
        ret=read_sensor_id(2);
        if(!ret)
        {
            debug("Error reading Sensor 2\n");
            return false;
        }
        //optional only for learning purposes :P
        //dump_sensor_generalconf(1);
        //dump_sensor_generalconf(2);
        //dump_sensor_video_mode(1);
        //dump_sensor_video_mode(2);
        return true;
    }
    bool PS4EYECam::init_registers()
    {
        multia7_register_write(reg_init,ARRAY_SIZE(reg_init));

        //read sensor id from sensor 1 subaddress 0x01
        multi_register_read(sensor1_reg_read,ARRAY_SIZE(sensor1_reg_read),0x01);
        //read sensor id from sensor 2 subaddress 0x02
        multi_register_read(sensor2_reg_read,ARRAY_SIZE(sensor2_reg_read),0x02);

        //set ov580 registers subaddress 0xff
        multi_register_write(ov580_reg_init0,ARRAY_SIZE(ov580_reg_init0),0xff);

        //read from 0x30 subaddress unknown device
        multi_register_read(unknown30_reg_read,ARRAY_SIZE(unknown30_reg_read),0x30);

        //read register subaddress 0xac eeprom 4g5a? from 0xfd80 to 0xff16 one by one
        dump_registers(0xfd80,0xff16,0xac);

        //set ov580 registers subaddress 0xff
        multi_register_write(ov580_reg_init0,ARRAY_SIZE(ov580_reg_init0),0xff);
        //	//set ov580 registers subaddress 0xff inside led on
        multi_register_write(ov580_reg_init1,ARRAY_SIZE(ov580_reg_init1),0xff);

        //setting ov9713 registers in sync mode both sensor at the same time subaddres 0x03
        multi_register_write(ov9713_reg_init0,ARRAY_SIZE(ov9713_reg_init0),0x03);
        multi_register_write(ov9713_reg_init1,ARRAY_SIZE(ov9713_reg_init1),0x03);

        //set ov580 registers subaddress 0xff
        multi_register_write(ov580_reg_init2,ARRAY_SIZE(ov580_reg_init2),0xff);
        multi_register_write(ov580_reg_init3,ARRAY_SIZE(ov580_reg_init3),0xff);
        multi_register_write(ov580_reg_init4,ARRAY_SIZE(ov580_reg_init4),0xff);
        multi_register_write(ov580_reg_init5,ARRAY_SIZE(ov580_reg_init5),0xff);
        multi_register_write(ov580_reg_init6,ARRAY_SIZE(ov580_reg_init6),0xff);
        multi_register_write(ov580_reg_init7,ARRAY_SIZE(ov580_reg_init7),0xff);
        multi_register_write(ov580_reg_init8,ARRAY_SIZE(ov580_reg_init8),0xff);
        multi_register_write(ov580_reg_init9,ARRAY_SIZE(ov580_reg_init9),0xff);
        multi_register_write(ov580_reg_init10,ARRAY_SIZE(ov580_reg_init10),0xff);
        multi_register_write(ov580_reg_init11,ARRAY_SIZE(ov580_reg_init11),0xff);
        multi_register_write(ov580_reg_init12,ARRAY_SIZE(ov580_reg_init12),0xff);
        multi_register_write(ov580_reg_init13,ARRAY_SIZE(ov580_reg_init13),0xff);
        multi_register_write(ov580_reg_init14,ARRAY_SIZE(ov580_reg_init14),0xff);
        multi_register_write(ov580_reg_init15,ARRAY_SIZE(ov580_reg_init15),0xff);
        multi_register_write(ov580_reg_init16,ARRAY_SIZE(ov580_reg_init16),0xff);
        multi_register_write(ov580_reg_init17,ARRAY_SIZE(ov580_reg_init17),0xff);
        multi_register_write(ov580_reg_init18,ARRAY_SIZE(ov580_reg_init18),0xff);
        multi_register_write(ov580_reg_init19,ARRAY_SIZE(ov580_reg_init19),0xff);
        multi_register_write(ov580_reg_init20,ARRAY_SIZE(ov580_reg_init20),0xff);
        multi_register_write(ov580_reg_init21,ARRAY_SIZE(ov580_reg_init21),0xff);
        multi_register_write(ov580_reg_init22,ARRAY_SIZE(ov580_reg_init22),0xff);
        multi_register_write(ov580_reg_init23,ARRAY_SIZE(ov580_reg_init23),0xff);
        multi_register_write(ov580_reg_init24,ARRAY_SIZE(ov580_reg_init24),0xff);
        multi_register_write(ov580_reg_init25,ARRAY_SIZE(ov580_reg_init25),0xff);
        multi_register_write(ov580_reg_init26,ARRAY_SIZE(ov580_reg_init26),0xff);
        multi_register_write(ov580_reg_init27,ARRAY_SIZE(ov580_reg_init27),0xff);
        multi_register_write(ov580_reg_init28,ARRAY_SIZE(ov580_reg_init28),0xff);
        multi_register_write(ov580_reg_init29,ARRAY_SIZE(ov580_reg_init29),0xff);

        //set subaddress 0x30 unknown device registers
        multi_register_write(unknow30_reg_init0,ARRAY_SIZE(unknow30_reg_init0),0x30);
        //read from subaddress 0x30
        multi_register_read(unknow30_reg_read1,ARRAY_SIZE(unknow30_reg_read1),0x30);



        //set ak5703 registers subaddress 0x24
        multi_register_write(ak5703_reg_init0,ARRAY_SIZE(ak5703_reg_init0),0x24);
        multi_register_write(ak5703_reg_init1,ARRAY_SIZE(ak5703_reg_init1),0x24);
        multi_register_write(ak5703_reg_init2,ARRAY_SIZE(ak5703_reg_init2),0x24);
        multi_register_write(ak5703_reg_init3,ARRAY_SIZE(ak5703_reg_init3),0x24);
        multi_register_write(ak5703_reg_init4,ARRAY_SIZE(ak5703_reg_init4),0x24);
        multi_register_write(ak5703_reg_init5,ARRAY_SIZE(ak5703_reg_init5),0x24);
        multi_register_write(ak5703_reg_init6,ARRAY_SIZE(ak5703_reg_init6),0x24);
        multi_register_write(ak5703_reg_init7,ARRAY_SIZE(ak5703_reg_init7),0x24);
        multi_register_write(ak5703_reg_init8,ARRAY_SIZE(ak5703_reg_init8),0x24);
        multi_register_write(ak5703_reg_init9,ARRAY_SIZE(ak5703_reg_init9),0x24);
        //after write to ak5703 usb sniffer shows that it is reading these registers perhaps sony 's driver is checking after writing i don't know :P
        multi_register_read(ak5703_reg_read,ARRAY_SIZE(ak5703_reg_read),0x24);
        multi_register_read(ak5703_reg_read1,ARRAY_SIZE(ak5703_reg_read1),0x24);




        //more ov580 set registers subaddress 0xff
        multi_register_write(ov580_reg_init30,ARRAY_SIZE(ov580_reg_init30),0xff);
        multi_register_write(ov580_reg_init31,ARRAY_SIZE(ov580_reg_init31),0xff);
        multi_register_write(ov580_reg_init32,ARRAY_SIZE(ov580_reg_init32),0xff);
        multi_register_write(ov580_reg_init33,ARRAY_SIZE(ov580_reg_init33),0xff);
        multi_register_write(ov580_reg_init34,ARRAY_SIZE(ov580_reg_init34),0xff);
        multi_register_write(ov580_reg_init35,ARRAY_SIZE(ov580_reg_init35),0xff);
        multi_register_write(ov580_reg_init36,ARRAY_SIZE(ov580_reg_init36),0xff);
        multi_register_write(ov580_reg_init37,ARRAY_SIZE(ov580_reg_init37),0xff);
        multi_register_write(ov580_reg_init38,ARRAY_SIZE(ov580_reg_init38),0xff);
        multi_register_write(ov580_reg_init39,ARRAY_SIZE(ov580_reg_init39),0xff);
        multi_register_write(ov580_reg_init40,ARRAY_SIZE(ov580_reg_init40),0xff);
        multi_register_write(ov580_reg_init41,ARRAY_SIZE(ov580_reg_init41),0xff);
        multi_register_write(ov580_reg_init42,ARRAY_SIZE(ov580_reg_init42),0xff);
        multi_register_write(ov580_reg_init43,ARRAY_SIZE(ov580_reg_init43),0xff);
        multi_register_write(ov580_reg_init44,ARRAY_SIZE(ov580_reg_init44),0xff);
        multi_register_write(ov580_reg_init45,ARRAY_SIZE(ov580_reg_init45),0xff);
        multi_register_write(ov580_reg_init46,ARRAY_SIZE(ov580_reg_init46),0xff);
        multi_register_write(ov580_reg_init47,ARRAY_SIZE(ov580_reg_init47),0xff);
        multi_register_write(ov580_reg_init48,ARRAY_SIZE(ov580_reg_init48),0xff);
        multi_register_write(ov580_reg_init49,ARRAY_SIZE(ov580_reg_init49),0xff);


        return true;
    }

    bool PS4EYECam::init(uint32_t width, uint32_t height, uint8_t desiredFrameRate)
    {
        // open usb device so we can setup and go
        if(handle_ == NULL)
        {
            if( !open_usb() )
            {
                return false;
            }
        }
        // TODO play with different OV9713 frame modes
        frame_width=width;
        frame_height=height;
        frame_rate=desiredFrameRate;
        //pendiente de mirar esto
        frame_stride = frame_width * 2;

        //default mode 3348*808
        myframe.unknown1=(uint8_t * )malloc(32*800);
        myframe.unknown2=(uint8_t * )malloc(64*800);
        myframe.videoLeftFrame=(uint8_t * )malloc(1280*800*2);
        myframe.videoRightFrame=(uint8_t * )malloc(1280*800*2);
        myframe.unknown3=(uint8_t * )malloc(840*800*2);





        if(!check_sensors())
        {
            debug("Sanity check from sensors failed\n");
            //set_led_off();
            //reset_sensors();
            return false;
        }
    /*  TODO play with video modes perhaps we will need to go to uvc path without ov580 information.
        debug("Show video mode registers from sensor 1\n");
        dump_sensor_video_mode(1);
        debug("Show video mode registers from sensor 2\n");
        dump_sensor_video_mode(2);
        set_sensor_video_mode(5, 3);
        sleep(2);
        debug("Show video mode registers from sensor 1\n");
        dump_sensor_video_mode(1);
        debug("Show video mode registers from sensor 2\n");
        dump_sensor_video_mode(2);*/

/*
        if(!init_registers())
        {
            debug("Initialization registers failed\n");
            return false;
        }
*/
        return true;
    }
    bool PS4EYECam::init(uint8_t initmode, uint8_t desiredFrameRate)
    {

        //init with mode and framerate. Each mode need own init values 
        switch(initmode)
        {
            case 0:
                frame_width=1280;
                frame_height=800;
                frame_rate=desiredFrameRate;
                mode=initmode;
                myframe.unknown1=(uint8_t * )malloc(32*800);
                myframe.unknown2=(uint8_t * )malloc(64*800);
                myframe.videoLeftFrame=(uint8_t * )malloc(1280*800*2);
                myframe.videoRightFrame=(uint8_t * )malloc(1280*800*2);
                myframe.unknown3=(uint8_t * )malloc(840*800*2);
                myframe.mode=0;
                frame_stride=3448*2;
                linesize=3448;
             


                break;
            case 1:
                frame_width=640;
                frame_height=400;
                frame_rate=desiredFrameRate;
                mode=initmode;
                myframe.unknown1=(uint8_t * )malloc(32*400);
                myframe.unknown2=(uint8_t * )malloc(64*400);
                myframe.videoLeftFrame=(uint8_t * )malloc(640*400*2);
                myframe.videoRightFrame=(uint8_t * )malloc(640*400*2);
                myframe.unknown3=(uint8_t * )malloc(420*400*2);
                myframe.mode=1;
                frame_stride=1748*2;
                linesize=1748;



                break;
            case 2:
                frame_width=320;
                frame_height=192;
                frame_rate=desiredFrameRate;
                mode=initmode;
                myframe.unknown1=(uint8_t * )malloc(32*200);
                myframe.unknown2=(uint8_t * )malloc(64*200);
                myframe.videoLeftFrame=(uint8_t * )malloc(320*200*2);
                myframe.videoRightFrame=(uint8_t * )malloc(320*200*2);
                myframe.unknown3=(uint8_t * )malloc(210*200*2);
                myframe.mode=2;
                frame_stride=898*2;
                linesize=898;

                break;
            default:
                frame_width=1280;
                frame_height=800;
                frame_rate=60;
                mode=0;
                myframe.unknown1=(uint8_t * )malloc(32*800);
                myframe.unknown2=(uint8_t * )malloc(64*800);
                myframe.videoLeftFrame=(uint8_t * )malloc(1280*800*2);
                myframe.videoRightFrame=(uint8_t * )malloc(1280*800*2);
                myframe.unknown3=(uint8_t * )malloc(840*800*2);
                myframe.mode=0;
                frame_stride=3448*2;
                linesize=3448;


                break;
        }
        urb = std::shared_ptr<URBDesc>( new URBDesc(mode) );

        // open usb device so we can setup and go
        if(handle_ == NULL)
        {
            if( !open_usb() )
            {
                return false;
            }
        }

        frame_stride = frame_width * 2;
        if(!check_sensors())
        {
            debug("Sanity check from sensors failed\n");
            //set_led_off();
            //reset_sensors();
            return false;
        }

        if(!init_registers())
        {
            debug("Initialization registers failed\n");
            return false;
        }


        return true;
    }

    void PS4EYECam::start()
    {

        if(is_streaming) return;

       //TODO define different  modes to choose resolution and fps
         // init and start urb
        urb->is_streaming=true;
        urb->start_transfers(handle_, frame_stride*frame_height);

        last_qued_frame_time = 0;
        is_streaming = true;
    }
    void PS4EYECam::stop()
    {
        debug("stop is called is_streaming is: %d\n",is_streaming);
        if(!is_streaming) return;
        //set led off

        //set_led_off();

        //stop streaming data
        //stop_sensors_streaming();
       // reset_sensors();
        // close urb
        urb->close_transfers();
        is_streaming = false;
        sleep(1);

       // urb->is_streaming=false;




    }
    void PS4EYECam::shutdown()
    {
        debug("PS4EYECAM shutdown called wait...\n");
        stop();
        sleep(2);
        urb->num_transfers=0;
       // release();
    }
    void PS4EYECam::check_ff71()
    {
        uint8_t val=0xff;
        debug("frame number %d\n",urb->frame_counter);
        switch(urb->ff71status)
        {
            case 0:

                    val=register_read(0xff71,0xff);
                    if(val==0x0)
                    {
                        debug("i=%d Write register 0xff70 to f1\n",urb->ff71status);
                     //   usleep(1);
                        multi_register_write(ov580_reg_stream_w0,ARRAY_SIZE(ov580_reg_stream_w0),0xff);
                        urb->ff71status=1;
                    }

                break;
            case 1:

                    debug("i=%d Write register 0xff70 to 01\n",urb->ff71status);
                    multi_register_write(ov580_reg_stream_w1,ARRAY_SIZE(ov580_reg_stream_w1),0xff);
                    usleep(100);
                    val=register_read(0xff71,0xff);
                    debug("i=%d val=%d\n",urb->ff71status,val);
                    urb->ff71status=2;

                break;
            case 2:

                    val=register_read(0xff71,0xff);
                    debug("i=%d val=%d\n",urb->ff71status,val);
                    urb->ff71status=3;


                break;
            case 3:

                    val=register_read(0xff71,0xff);
                    debug("i=%d val=%d\n",urb->ff71status,val);
                    usleep(100);

                    val=register_read(0xff71,0xff);
                    debug("i=%d val=%d\n",urb->ff71status,val);
                    urb->ff71status=4;

                break;
            case 4:
                    val=register_read(0xff71,0xff);
                    debug("%d val=%d\n",urb->ff71status,val);
                    urb->ff71status=5;

                break;
            case 5:
                val=register_read(0xff71,0xff);
                debug("%d val=%d\n",urb->ff71status,val);
                urb->ff71status=6;

                break;

            default:
                break;
        }


        
    }
    bool PS4EYECam::isNewFrame() const
    {
        if(last_qued_frame_time < urb->last_frame_time)
        {
            
            return true;
        }
        return false;
    }
    eyeframe * PS4EYECam::getLastVideoFramePointer()
    {

        int i;
        last_qued_frame_time = urb->last_frame_time;

        uint8_t *rowpointer;
        rowpointer=&(urb->frame_buffer[urb->frame_complete_ind * urb->frame_size]);

        for(i=0;i<frame_height;i++)
        {
            memcpy(&myframe.videoLeftFrame[frame_width*2*i],&rowpointer[linesize*2*i+32+64], frame_width*2);
            memcpy(&myframe.videoRightFrame[frame_width*2*i],&rowpointer[linesize*2*i+32+64+frame_width*2], frame_width*2);

        }
        return &myframe;
        
    }

    const uint8_t* PS4EYECam::getLastVideoLeftFramePointer()
    {

        int i;
        last_qued_frame_time = urb->last_frame_time;

        uint8_t *rowpointer;
        rowpointer=&(urb->frame_buffer[urb->frame_complete_ind * urb->frame_size]);

        for(i=0;i<frame_height;i++)
        {
            memcpy(&myframe.videoLeftFrame[frame_width*2*i],&rowpointer[linesize*2*i+32+64], frame_width*2);
        }
        return myframe.videoLeftFrame;
        
    }

    const uint8_t* PS4EYECam::getLastVideoRightFramePointer()
    {
        int i;
        last_qued_frame_time = urb->last_frame_time;

        uint8_t *rowpointer;
        rowpointer=&(urb->frame_buffer[urb->frame_complete_ind * urb->frame_size]);

        for(i=0;i<frame_height;i++)
        {
             memcpy(&myframe.videoRightFrame[frame_width*2*i],&rowpointer[linesize*2*i+32+64+frame_width*2], frame_width*2);
        }

        return myframe.videoRightFrame;

    }
  /*  const uint8_t* PS4EYECam::getLastVideoFramePointer()
    {

        int i;
        last_qued_frame_time = urb->last_frame_time;

        uint8_t *rowpointer;
        //rowpointer=(urb->frame_buffer+ urb->frame_complete_ind * urb->frame_size);
        rowpointer=&(urb->frame_buffer[urb->frame_complete_ind * urb->frame_size]);
        

        //better almost 60 fps with memcpy
       // for(i=0;i<800;i++)

        for(i=0;i<frame_height;i++)
        {
            // memcpy(&myframe.unknown1[32*i],&rowpointer[linesize*2*i], 32);
            //memcpy(&myframe.unknown2[64*i],&rowpointer[linesize*2*i+32], 64);

         //   memcpy(&myframe.videoframe[1280*2*i],&rowpointer[linesize*2*i+32+64], 1280*2);
            memcpy(&myframe.videoLeftFrame[frame_width*2*i],&rowpointer[linesize*2*i+32+64], frame_width*2);


            // memcpy(&myframe.depthframe[1280*2*i],&rowpointer[linesize*2*i+32+64+1280*2], 1280*2);
            // memcpy(&myframe.unknown3[840*2*i],&rowpointer[linesize*2*i+32+64+1280*2+1280*2], 840*2);

        }

        //ugly loss almost 30 fps with this
        //or(i=0;i<800;i++)
         {
         rowpointeraux=rowpointer+linesize*i*2+32+64+1280*2*depthflag;
         for(j=0;j<1280;j++)
         {
         frame[1280*2*i+2*j]=rowpointeraux[2*j];
         frame[1280*2*i+2*j+1]=rowpointeraux[2*j+1];
         }
         }
         return frame;
      //  return myframe.videoLeftFrame;
        
    //}
    /*
     * dump fuctions from lsusb.c only for debug purposes to check if values are the same in
     * usb sniffer capture
     */
    void PS4EYECam::dump_endpoint_comp(const struct libusb_ss_endpoint_companion_descriptor *ep_comp)
    {
        debug("     USB 3.0 Endpoint Companion:\n");
        debug("       bMaxBurst:        %d\n", ep_comp->bMaxBurst);
        debug("       bmAttributes:     0x%02x\n", ep_comp->bmAttributes);
        debug("       wBytesPerInterval: %d\n", ep_comp->wBytesPerInterval);
    }

    void PS4EYECam::dump_endpoint(const struct libusb_endpoint_descriptor *endpoint)
    {
        int ret;

        debug("     Endpoint:\n");
        debug("       bEndpointAddress: %02xh\n", endpoint->bEndpointAddress);
        debug("       bmAttributes:     %02xh\n", endpoint->bmAttributes);
        debug("       wMaxPacketSize:   %d\n", endpoint->wMaxPacketSize);
        debug("       bInterval:        %d\n", endpoint->bInterval);
        debug("       bRefresh:         %d\n", endpoint->bRefresh);
        debug("       bSynchAddress:    %d\n", endpoint->bSynchAddress);


        struct libusb_ss_endpoint_companion_descriptor *ep_comp;

        ret = libusb_get_ss_endpoint_companion_descriptor(USBMgr::instance()->usbContext(), endpoint, &ep_comp);
        if (LIBUSB_SUCCESS != ret) {

        }

        dump_endpoint_comp(ep_comp);


        libusb_free_ss_endpoint_companion_descriptor(ep_comp);



    }
    void PS4EYECam::dump_altsetting(const struct libusb_interface_descriptor *interface)
    {
        int i;

        debug("   Interface Descriptor:\n"
              "     bLength            %5u\n"
              "     bDescriptorType    %5u\n"
              "     bInterfaceNumber   %5u\n"
              "     bAlternateSetting  %5u\n"
              "     bNumEndpoints      %5u\n"
              "     bInterfaceClass    %5u \n"
              "     bInterfaceSubClass %5u \n"
              "     bInterfaceProtocol %5u \n"
              "     iInterface         %5u \n",
              interface->bLength, interface->bDescriptorType, interface->bInterfaceNumber,
              interface->bAlternateSetting, interface->bNumEndpoints, interface->bInterfaceClass, /*cls,*/
              interface->bInterfaceSubClass, /*subcls,*/ interface->bInterfaceProtocol, /*proto,*/
              interface->iInterface/*, ifstr*/);
        //TODO get video control interfaces and video streaming interfaces
        for (i = 0; i < interface->bNumEndpoints; i++)
            dump_endpoint(&interface->endpoint[i]);

    }
    void PS4EYECam::dump_interface(const struct libusb_interface *interface)
    {
        int i;
        for (i = 0; i < interface->num_altsetting; i++)
            dump_altsetting(&interface->altsetting[i]);

    }
    void PS4EYECam::dump_config(struct libusb_config_descriptor *config)
    {
        int i;
        debug(" Configuration Descriptor:\n"
              "   bLength             %5u\n"
              "   bDescriptorType     %5u\n"
              "   wTotalLength        %5u\n"
              "   bNumInterfaces      %5u\n"
              "   bConfigurationValue %5u\n"
              "   iConfiguration      %5u \n"
              "   bmAttributes         0x%02x\n",

              config->bLength, config->bDescriptorType,
              libusb_cpu_to_le16(libusb_cpu_to_le16(config->wTotalLength)),
              config->bNumInterfaces, config->bConfigurationValue,
              config->iConfiguration,
              /*cfg,*/ config->bmAttributes);
        if (!(config->bmAttributes & 0x80))
            debug("    (Missing must-be-set bit!)\n");
        if (config->bmAttributes & 0x40)
            debug("    Self Powered\n");
        else
            debug("    (Bus Powered)\n");
        if (config->bmAttributes & 0x20)
            debug("  Remote Wakeup\n");
        if (config->bmAttributes & 0x10)
            debug("  Battery Powered\n");
        debug("   MaxPower            %5umA\n", config->MaxPower * 2);
        if (config->extra_length) {
            const unsigned char	*buf = config->extra;
            if(buf[1]==0x0b)
            {
                debug("   Interface Association:\n"
                      "     bLength %5u\n"
                      "     bDescriptorType   %5u\n"
                      "     bFirstInterface   %5u\n"
                      "     bInterfaceCount   %5u\n"
                      "     bFunctionClass    %5u \n"
                      "     bFunctionSubClass %5u \n"
                      "     bFunctionProtocol %5u \n"
                      "     iFunction         %5u \n",
                      buf[0], buf[1],
                      buf[2], buf[3],
                      buf[4], /*cls,*/
                      buf[5], /*subcls,*/
                      buf[6], /*proto,*/
                      buf[7]/*, func*/);
            }
        }

        for (i = 0 ; i < config->bNumInterfaces ; i++)
            dump_interface(&config->interface[i]);

    }

    void PS4EYECam::dump_device()
    {
        struct libusb_device_descriptor descriptor;
        int res;

        res=libusb_get_device_descriptor(device_, &descriptor);
        if(res)
        {
            debug("error getting device descriptor: %d\n", res);
            return;
        }
        debug("Device Descriptor:\n"
              " bLength            %5u\n"
              " bDescriptorType    %5u\n"
              " bcdUSB             %2x.%02x\n"
              " bDeviceClass       %5u \n"
              " bDeviceSubClass    %5u \n"
              " bDeviceProtocol    %5u \n"
              " bMaxPacketSize0    %5u\n"
              " idVendor          0x%04x \n"
              " idProduct         0x%04x \n"
              " bcdDevice          %2x.%02x\n"
              " iManufacturer      %5u \n"
              " iProduct           %5u \n"
              " iSerial            %5u \n"
              " bNumConfigurations %5u\n",
              descriptor.bLength, descriptor.bDescriptorType,
              descriptor.bcdUSB >> 8, descriptor.bcdUSB & 0xff,
              descriptor.bDeviceClass, /*cls,*/
              descriptor.bDeviceSubClass, /*subcls,*/
              descriptor.bDeviceProtocol, /*proto,*/
              descriptor.bMaxPacketSize0,
              descriptor.idVendor, /*vendor,*/ descriptor.idProduct, /*product,*/
              descriptor.bcdDevice >> 8, descriptor.bcdDevice & 0xff,
              descriptor.iManufacturer, /*mfg,*/
              descriptor.iProduct, /*prod,*/
              descriptor.iSerialNumber, /*serial,*/
              descriptor.bNumConfigurations);
        struct libusb_config_descriptor *config;
        res = libusb_get_config_descriptor(device_, 0, &config);
        if (LIBUSB_SUCCESS != res)
        {
            debug("error getting config descriptors\n");
            return;
        }
        dump_config(config);

    }
    int PS4EYECam::uvc_get_hue(int16_t *hue, uint8_t req_code){
        uint8_t data[2];
        int ret;

        ret = libusb_control_transfer(handle_,REQ_TYPE_GET, req_code,UVC_PU_HUE_CONTROL << 8,1 << 8,data,sizeof(data),1000);

        if (ret == sizeof(data)) {
            *hue = SW_TO_SHORT(data + 0);
            return 0;
        } else {
            return ret;
        }
    }


    int PS4EYECam::uvc_set_hue(int16_t hue){
        uint8_t data[2];
        int ret;

        SHORT_TO_SW(hue, data + 0);

        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_SET, UVC_SET_CUR,
                                      UVC_PU_HUE_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);

        if (ret == sizeof(data))
            return 0;
        else
            return ret;
    }
    int PS4EYECam::uvc_get_sharpness(uint16_t* sharpness, uint8_t req_code) {
        uint8_t data[2];
        int ret;

        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_GET, req_code,
                                      UVC_PU_SHARPNESS_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);



        if (ret == sizeof(data)) {
            *sharpness = SW_TO_SHORT(data + 0);
            return 0;
        } else {
            return ret;
        }
    }
    int PS4EYECam::uvc_set_sharpness(uint16_t sharpness) {
        uint8_t data[2];
        int ret;

        SHORT_TO_SW(sharpness, data + 0);

        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_SET, UVC_SET_CUR,
                                      UVC_PU_SHARPNESS_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);
        
        if (ret == sizeof(data))
            return 0;
        else
            return ret;
    }

    int PS4EYECam::uvc_get_brightness(int16_t* brightness, uint8_t  req_code) {
        uint8_t data[2];
        int ret;

        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_GET, req_code,
                                      UVC_PU_BRIGHTNESS_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);

        if (ret == sizeof(data)) {
            *brightness = SW_TO_SHORT(data + 0);
            return 0;
        } else {
            return ret;
        }
    }

    int PS4EYECam::uvc_set_brightness(int16_t brightness) {
        uint8_t data[2];
        int ret;

        SHORT_TO_SW(brightness, data + 0);

        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_SET, UVC_SET_CUR,
                                      UVC_PU_BRIGHTNESS_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);

        if (ret == sizeof(data))
            return 0;
        else
            return ret;
    }

    int PS4EYECam::uvc_get_contrast(uint16_t* contrast, uint8_t req_code) {
        uint8_t data[2];
        int ret;

        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_GET, req_code,
                                      UVC_PU_CONTRAST_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      1000);

        if (ret == sizeof(data)) {
            *contrast = SW_TO_SHORT(data + 0);
            return 0;
        } else {
            return ret;
        }
    }



    int PS4EYECam::uvc_set_contrast(uint16_t contrast) {
        uint8_t data[2];
        int ret;

        SHORT_TO_SW(contrast, data + 0);

        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_SET, UVC_SET_CUR,
                                      UVC_PU_CONTRAST_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);

        if (ret == sizeof(data))
            return 0;
        else
            return ret;
    }
    int PS4EYECam::uvc_get_saturation(uint16_t* saturation, uint8_t req_code) {
        uint8_t data[2];
        int ret;

        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_GET, req_code,
                                      UVC_PU_SATURATION_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);

        if (ret == sizeof(data)) {
            *saturation = SW_TO_SHORT(data + 0);
            return 0;
        } else {
            return ret;
        }
    }


    int PS4EYECam::uvc_set_saturation(uint16_t saturation) {
        uint8_t data[2];
        int ret;

        SHORT_TO_SW(saturation, data + 0);

        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_SET, UVC_SET_CUR,
                                      UVC_PU_SATURATION_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);

        if (ret == sizeof(data))
            return 0;
        else
            return ret;
    }
    int PS4EYECam::uvc_get_white_balance_temperature(uint16_t* temperature, uint8_t req_code){
        uint8_t data[2];
        int ret;

        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_GET, req_code,
                                      UVC_PU_WHITE_BALANCE_TEMPERATURE_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);
        
        if (ret == sizeof(data)) {
            *temperature = SW_TO_SHORT(data + 0);
            return 0;
        } else {
            return ret;
        }
    }
    int PS4EYECam::uvc_set_white_balance_temperature(uint16_t temperature) {
        uint8_t data[2];
        int ret;
        
        SHORT_TO_SW(temperature, data + 0);
        
        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_SET, UVC_SET_CUR,
                                      UVC_PU_WHITE_BALANCE_TEMPERATURE_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);
        
        if (ret == sizeof(data))
            return 0;
        else
            return ret;
    }
    
    int PS4EYECam::uvc_get_gain(uint16_t* gain, uint8_t req_code) {
        uint8_t data[2];
        int ret;
        
        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_GET, req_code,
                                      UVC_PU_GAIN_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);
        
        if (ret == sizeof(data)) {
            *gain = SW_TO_SHORT(data + 0);
            return 0;
        } else {
            return ret;
        }
    }
    int PS4EYECam::uvc_set_gain(uint16_t gain) {
        uint8_t data[2];
        int ret;
        
        SHORT_TO_SW(gain, data + 0);
        
        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_SET, UVC_SET_CUR,
                                      UVC_PU_GAIN_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);
        
        if (ret == sizeof(data))
            return 0;
        else
            return ret;
    }
    int PS4EYECam::uvc_get_power_line_frequency(uint8_t* power_line_frequency, uint8_t req_code) {
        uint8_t data[1];
        int ret;
        
        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_GET, req_code,
                                      UVC_PU_POWER_LINE_FREQUENCY_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);
        
        if (ret == sizeof(data)) {
            *power_line_frequency = data[0];
            return 0;
        } else {
            return ret;
        }
    }
    int PS4EYECam::uvc_set_power_line_frequency(uint8_t power_line_frequency) {
        uint8_t data[1];
        int ret;
        
        data[0] = power_line_frequency;
        
        ret = libusb_control_transfer(
                                      handle_,
                                      REQ_TYPE_SET, UVC_SET_CUR,
                                      UVC_PU_POWER_LINE_FREQUENCY_CONTROL << 8,
                                      1 << 8,
                                      data,
                                      sizeof(data),
                                      0);
        
        if (ret == sizeof(data))
            return 0;
        else
            return ret;
    }
   	int PS4EYECam::uvc_set_video_mode(uint8_t mode,uint8_t fps)
	{
		uvc_stream_ctrl_t ctrl;
	    uint8_t buf[26];
	    size_t len=26;
		int err;
        int frame_size;

		switch(mode)
		{
			case 0://3448x808
				frame_width=1280;
				frame_height=800;
				frame_size=3448*808*2;
				if(fps!=60 && fps!=30 && fps!=15 && fps!=8)
				{
					debug("Unsupported fps=%d take default 60 fps\n",fps);
					frame_rate=60;
				}
				else
				{
					frame_rate=fps;
				}
			    ctrl.bFrameIndex=1;
			    ctrl.wDelay=32773;
			    ctrl.dwMaxVideoFrameSize=frame_size;
			    ctrl.dwMaxPayloadTransferSize=49152;
	    		switch(frame_rate)
            {
                case 60:
                    ctrl.dwFrameInterval=166666;
                    ctrl.wDelay=0;
                    break;
                case 30:
                    ctrl.dwFrameInterval=333333;
                    ctrl.wDelay=32773;
                    break;
                case 15:
                    ctrl.dwFrameInterval=666666;
                    ctrl.wDelay=32773;
                    break;
                case 8:
                    ctrl.dwFrameInterval=1250000;
                    ctrl.wDelay=32773;
                    break;
            }

				break;
			case 1://1748x408
				frame_width=640;
				frame_height=400;
				frame_size=1748*408*2;

				if(fps!=120 && fps!=60 && fps!=30 && fps!=15 && fps!=8)
				{
					debug("Unsupported fps=%d take default 60 fps\n",fps);
					frame_rate=120;
				}
				else
				{
					frame_rate=fps;
				}
			    ctrl.bFrameIndex=2;
			    ctrl.dwMaxVideoFrameSize=frame_size;
			    ctrl.dwMaxPayloadTransferSize=49152;
	    		switch(frame_rate)
            {
                case 120:
                    ctrl.dwFrameInterval=83333;
                    ctrl.wDelay=0;
                    break;
                case 60:
                    ctrl.dwFrameInterval=166666;
                    ctrl.wDelay=49347;
                    break;
                case 30:
                    ctrl.dwFrameInterval=333333;
                    ctrl.wDelay=49347;
                    break;
                case 15:
                    ctrl.dwFrameInterval=666666;
                    ctrl.wDelay=49347;
                    break;
                case 8:
                    ctrl.dwFrameInterval=1250000;
                    ctrl.wDelay=49347;
                    break;

            }
				break;
			case 2://898x200
				frame_width=320;
				frame_height=192;
				frame_size=898*200*2;
				if(fps!=240 && fps!=120 && fps!=60 && fps!=30)
				{
					debug("Unsupported fps=%d take default 60 fps\n",fps);
					frame_rate=240;
				}
				else
				{
					frame_rate=fps;
				}
			    ctrl.bFrameIndex=3;
			    //ctrl.wDelay=8315;
			    ctrl.dwMaxVideoFrameSize=frame_size;
			    ctrl.dwMaxPayloadTransferSize=49152;
	    		switch(frame_rate)
            {
                case 240:
                    ctrl.dwFrameInterval=41666;
                    ctrl.wDelay=0;

                    break;
                case 120:
                    ctrl.dwFrameInterval=83333;
                    ctrl.wDelay=0;

                    break;
                case 60:
                    ctrl.dwFrameInterval=166666;
                    ctrl.wDelay=0;

                    break;
                case 30:
                    ctrl.dwFrameInterval=333333;
                    ctrl.wDelay=0;

                    break;
            }
				break;
			default:
				frame_width=1280;
				frame_height=800;
				frame_size=3448*808*2;
                ctrl.dwFrameInterval=166666;
                ctrl.wDelay=0;
				break;
		}
		debug("Frame resolutiion: %dx%d framerate: %d \n",frame_width,frame_height,frame_rate);
		ctrl.bmHint=1;
		ctrl.bFormatIndex=1;
	    ctrl.wKeyFrameRate=0;
	    ctrl.wPFrameRate=0;
	    ctrl.wCompQuality=0;
	    ctrl.wCompWindowSize=0;
	    ctrl.dwMaxPayloadTransferSize=49152;
	    ctrl.dwClockFrequency=0;
	    ctrl.bmFramingInfo='\0';
	    ctrl.bPreferredVersion='\0';
	    ctrl.bMinVersion='\0';
	    ctrl.bMaxVersion='\0';
	    ctrl.bInterfaceNumber=1;

        /* prepare for a SET transfer */
        SHORT_TO_SW(ctrl.bmHint, buf);
        buf[2] = ctrl.bFormatIndex;
        buf[3] = ctrl.bFrameIndex;
        INT_TO_DW(ctrl.dwFrameInterval, buf + 4);
        SHORT_TO_SW(ctrl.wKeyFrameRate, buf + 8);
        SHORT_TO_SW(ctrl.wPFrameRate, buf + 10);
        SHORT_TO_SW(ctrl.wCompQuality, buf + 12);
        SHORT_TO_SW(ctrl.wCompWindowSize, buf + 14);
        SHORT_TO_SW(ctrl.wDelay, buf + 16);
        INT_TO_DW(ctrl.dwMaxVideoFrameSize, buf + 18);
        INT_TO_DW(ctrl.dwMaxPayloadTransferSize, buf + 22);
        
        
	    
		err = libusb_control_transfer(
                                      handle_,
                                        0x21 ,
                                      0x01,
                                      (0x01 << 8) ,
                                      ctrl.bInterfaceNumber,
                                      buf, len, 0);
        if (err == len)
        {
            debug("control transfer for video set return %d\n",err);
            return 0;
        }
        else
        {
            debug("control transfer for video set error return %d\n",err);
            return err;
        }
	}
    int PS4EYECam::uvc_show_video_mode()
    {
        uvc_stream_ctrl_t ctrl;
        uint8_t buf[26];
        size_t len=26;
        int err;

        /* do the transfer */
        err = libusb_control_transfer(
                                      handle_,
                                      0xA1,
                                      0x81,
                                      (1 << 8),
                                      1,
                                      buf, len, 0
                                      );
        if (err == len)
        {
            debug("control transfer for video get return %d\n",err);
            ctrl.bmHint = SW_TO_SHORT(buf);
            ctrl.bFormatIndex = buf[2];
            ctrl.bFrameIndex = buf[3];
            ctrl.dwFrameInterval = DW_TO_INT(buf + 4);
            ctrl.wKeyFrameRate = SW_TO_SHORT(buf + 8);
            ctrl.wPFrameRate = SW_TO_SHORT(buf + 10);
            ctrl.wCompQuality = SW_TO_SHORT(buf + 12);
            ctrl.wCompWindowSize = SW_TO_SHORT(buf + 14);
            ctrl.wDelay = SW_TO_SHORT(buf + 16);
            ctrl.dwMaxVideoFrameSize = DW_TO_INT(buf + 18);
            ctrl.dwMaxPayloadTransferSize = DW_TO_INT(buf + 22);
            debug("bmHint: %04x\n", ctrl.bmHint);
            debug("bFormatIndex: %d\n", ctrl.bFormatIndex);
            debug("bFrameIndex: %d\n", ctrl.bFrameIndex);
            debug("dwFrameInterval: %u\n", ctrl.dwFrameInterval);
            debug("wKeyFrameRate: %d\n", ctrl.wKeyFrameRate);
            debug("wPFrameRate: %d\n", ctrl.wPFrameRate);
            debug("wCompQuality: %d\n", ctrl.wCompQuality);
            debug("wCompWindowSize: %d\n", ctrl.wCompWindowSize);
            debug("wDelay: %d\n", ctrl.wDelay);
            debug("dwMaxVideoFrameSize: %u\n", ctrl.dwMaxVideoFrameSize);
            debug("dwMaxPayloadTransferSize: %u\n", ctrl.dwMaxPayloadTransferSize);
            debug("bInterfaceNumber: %d\n", ctrl.bInterfaceNumber);
            

            return 0;
        }
        else
        {
            debug("control transfer for video ger error return %d\n",err);
            return err;
        }


    }
    bool PS4EYECam::open_usb()
    {
        // open
        int res = libusb_open(device_, &handle_);
        if(res != 0) {
            debug("device open error: %d\n", res);
            return false;
        }

        dump_device();

        //Follow steps showed in usb sniffer capture
        //set configuration 1
        res=libusb_set_configuration(handle_, 1);
        if(res != 0) {
            debug("set configuration error: %d\n", res);
            return false;
        }
        debug("configuration set to 1\n");

        //claim interface 1
        res = libusb_claim_interface(handle_, 1);
        if(res != 0) {
            debug("device claim interface error: %d\n", res);
            return false;
        }
        debug("claim interface 1\n");

        //set all setting 0 to interface 1
        //res=libusb_set_interface_alt_setting(handle_, 1, 0);
      

        //set alt setting 1 to interface 1
        res=libusb_set_interface_alt_setting(handle_, 1, 1);
        if(res != 0) {
            debug("set alt setting to interface error: %d\n", res);
            return false;
        }
        debug("set alt to 1 in interface 1\n");
        uvc_show_video_mode();
        uvc_set_video_mode(mode,frame_rate);
        uvc_show_video_mode();
      /*  uint16_t brightness;
        int sal;
        sal=uvc_get_sharpness(&brightness, UVC_GET_CUR);
        cout << sal << "Current brightness " << brightness<< endl;
        sal=uvc_get_sharpness(&brightness, UVC_GET_MIN);
        cout << sal << "Min brightness " << brightness<< endl;


        sal=uvc_get_sharpness(&brightness, UVC_GET_MAX);
        cout << sal << "Max brightness " << brightness<< endl;
        set_led_on();*/

        usleep(1000);


        return true;
    }

    void PS4EYECam::close_usb()
    {
        debug("closing device\n");
        libusb_release_interface(handle_, 1);
       libusb_close(handle_);
    libusb_unref_device(device_);

         handle_ = NULL;
         device_ = NULL;
        debug("device closed\n");

    }


    /*
     * Control error messages for usb transfers
     */
    uint8_t * PS4EYECam::controlTransferStatus(libusb_transfer_status x)
    {
        switch (x)
        {
            case LIBUSB_TRANSFER_COMPLETED:
                return (uint8_t *)"Transfer completed without error";
            case LIBUSB_TRANSFER_ERROR:
                return (uint8_t *)"Transfer failed";
            case LIBUSB_TRANSFER_TIMED_OUT:
                return (uint8_t *)"Transfer timed out";
            case LIBUSB_TRANSFER_CANCELLED:
                return (uint8_t *)"Transfer was cancelled";
            case LIBUSB_TRANSFER_STALL:
                return (uint8_t *)"Stall";
            case LIBUSB_TRANSFER_NO_DEVICE:
                return (uint8_t *)"Device was disconnected";
            case LIBUSB_TRANSFER_OVERFLOW:
                return (uint8_t *)"Transfer Overflow";
            default:
                return (uint8_t *)"Unknown error jur jur";
        }
    }

    /*
     * Called when control transfer is done
     */
    void  LIBUSB_CALL PS4EYECam::ct_done(struct libusb_transfer * transfer) {
        PS4EYECam * cam = (PS4EYECam *) transfer->user_data;
        if (transfer->status != LIBUSB_TRANSFER_COMPLETED)
        {
            debug("Control transfer error: %s\n", controlTransferStatus(transfer->status) );
            cam->controlTransferError = true;
        }
        if (cam->control_wLength != transfer->actual_length) {
            debug("phase 2 read failed received %d bytes instead of %d\n",transfer->actual_length ,cam->control_wLength);
            cam->controlTransferError = true;
        }
        cam->controlTransferReturned = true;
    }

    /*
     * Submit a control transfer to the usb system and wait until this packet has
     * been processed.
     */
    void PS4EYECam::submitAndWait_controlTransfer(uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, uint16_t wLength, uint8_t *buffer)
    {
        submit_controlTransfer(bmRequestType, bRequest, wValue, wIndex, wLength, buffer);
        controlTransferReturned = false;
        controlTransferError = false;
        while (!controlTransferReturned)
            USBMgr::handleEvents();
    }

    /*
     * Submit a control transfer to the usb system and continue with the program flow, i.e.
     * do not wait until the packet has been processed.
     */
    void PS4EYECam::submit_controlTransfer(uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, uint16_t wLength, uint8_t *buffer )
    {
        libusb_fill_control_setup(buffer, bmRequestType, bRequest,wValue, wIndex, wLength);
        libusb_fill_control_transfer(control_transfer, handle_, buffer,ct_done, NULL, 1000);
        control_transfer->user_data = this;
        control_wLength = wLength;
        libusb_submit_transfer(control_transfer);
    }


    void PS4EYECam::firmware_upload()
    {
        if(!firmwareisloaded)
        {
            handle_ = libusb_open_device_with_vid_pid(USBMgr::instance()->usbContext(), 0x05a9, 0x0580);
            if (handle_ == NULL)
            {
                cout <<"ov580 Camera boot mode not found..." << endl;
                exit(0);
            }
            //cout <<"ov580 Camera boot mode found..." << endl;

            device_ = libusb_get_device(handle_);

            libusb_reset_device(handle_);
            libusb_set_configuration(handle_, 1);
            libusb_ref_device(device_);
            libusb_claim_interface(handle_, 0);
            
            cout << "Uploading firmware to ov580 camera..." << endl;
            
            uint8_t chunk[CHUNK_SIZE+8];
            
            ifstream firmware(firmware_path.c_str(), ios::in|ios::binary|ios::ate);
            if (firmware.is_open())
            {
                uint32_t length = firmware.tellg();
                firmware.seekg(0, std::ios::beg);
                
                uint16_t index=0x14;
                uint16_t value=0;
                
                for (uint32_t pos=0; pos<length; pos+=CHUNK_SIZE)
                {
                    uint16_t size = ( CHUNK_SIZE > (length-pos) ? (length-pos) : CHUNK_SIZE);
                    firmware.read((char*)(chunk+8), size);
                    submitAndWait_controlTransfer(0x40, 0x0, value, index, size, chunk);
                    if ( ((uint32_t)value + size) > 0xFFFF ) index+=1;
                    value+=size;
                }
                firmware.close();
                
                chunk[8] = 0x5b;
                submit_controlTransfer(0x40, 0x0, 0x2200, 0x8018, 1, chunk);
                usleep(1000000);
                libusb_cancel_transfer(control_transfer);
                
                cout << "Firmware uploaded..." << endl;
            }
            else
            {
                cout << "Unable to open firmware.bin!" << endl;
            }
            exit(0);
        }
        else
        {
            cout << "Firmware already loaded..." << endl;
        }
        
        
        
    }

    
    
}