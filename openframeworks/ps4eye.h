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

 */

#ifndef PS4EYECAM_H
#define PS4EYECAM_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
// define shared_ptr in std

#if (defined( _MSC_VER ) && ( _MSC_VER >= 1600 )) || (__cplusplus >= 201103L)
#include <memory>
#else
#include <tr1/memory>
namespace std {
    using std::tr1::shared_ptr;
    using std::tr1::weak_ptr;
    using std::tr1::static_pointer_cast;
    using std::tr1::dynamic_pointer_cast;
    using std::tr1::const_pointer_cast;
    using std::tr1::enable_shared_from_this;
}
#endif

#include "libusb.h"

#ifndef __STDC_CONSTANT_MACROS
#  define __STDC_CONSTANT_MACROS
#endif

#include <stdint.h>

#if defined(DEBUG)
#define debug(x...) fprintf(stdout,x)
#else
#define debug(x...)
#endif

typedef struct eyeframe
{
    uint8_t *unknown1;
    uint8_t *unknown2;
    uint8_t *videoLeftFrame;
    uint8_t *videoRightFrame;
    uint8_t *unknown3;
    uint8_t mode; //0 1280x800 1 640x400 2 320x192

}eyeframe;

namespace ps4eye {


    class PS4EYECam
    {
    public:
        typedef std::shared_ptr<PS4EYECam> PS4EYERef;

        static const uint16_t VENDOR_ID;
        static const uint16_t PRODUCT_ID;
        std::string  firmware_path;
        int rightflag;
       



        PS4EYECam(libusb_device *device, bool firmware_check);
        ~PS4EYECam();


        bool init(uint32_t width, uint32_t height, uint8_t desiredFrameRate);
        bool init(uint8_t initmode, uint8_t desiredFrameRate);

        void start();
        void stop();
        void shutdown();


        //dump functions from lsusb.c
        void dump_endpoint_comp(const struct libusb_ss_endpoint_companion_descriptor *ep_comp);
        void dump_endpoint(const struct libusb_endpoint_descriptor *endpoint);
        void dump_altsetting(const struct libusb_interface_descriptor *interface);
        void dump_interface(const struct libusb_interface *interface);
        void dump_config(struct libusb_config_descriptor *config);
        void dump_device();

        //
        static const std::vector<PS4EYERef>& getDevices( bool forceRefresh = false );
        static bool updateDevices();
        void firmware_upload();

        bool isStreaming() const { return is_streaming; }
        bool isNewFrame() const;
        const uint8_t* getLastVideoLeftFramePointer();
        const uint8_t* getLastVideoRightFramePointer();
        eyeframe* getLastVideoFramePointer();

      //  const uint8_t* getLastVideoFramePointer();
        //const uint8_t* getLastDepthFramePointer();


        uint32_t getWidth() const { return frame_width; }
        uint32_t getHeight() const { return frame_height; }
        uint8_t getFrameRate() const { return frame_rate; }
        uint32_t getRowBytes() const { return frame_stride; }
        
        //uvc chip operations
        int uvc_set_video_mode(uint8_t mode,uint8_t fps);
        int uvc_show_video_mode();
        //don't tested some return pipe error -9 in libusb control transfer
        int uvc_get_hue(int16_t* hue, uint8_t req_code);
        int uvc_set_hue(int16_t hue);
        int uvc_get_sharpness(uint16_t* sharpness, uint8_t req_code);
        int uvc_set_sharpness(uint16_t sharpness);
        int uvc_get_brightness(int16_t* brightness, uint8_t req_code);
        int uvc_set_brightness(int16_t hue);
        int uvc_get_contrast(uint16_t* contrast, uint8_t req_code);
        int uvc_set_contrast(uint16_t contrast);
        int uvc_get_saturation(uint16_t* saturation,uint8_t req_code);
        int uvc_set_saturation(uint16_t saturation);
        int uvc_get_white_balance_temperature(uint16_t* temperature, uint8_t req_code);
        int uvc_set_white_balance_temperature(uint16_t temperature);
        int uvc_get_gain(uint16_t* gain, uint8_t req_code);
        int uvc_set_gain(uint16_t gain);
        int uvc_get_power_line_frequency(uint8_t* power_line_frequency, uint8_t req_code);
        int uvc_set_power_line_frequency(uint8_t power_line_frequency);



        //different chips operations
        bool read_sensor_id(uint8_t n);
        void set_led_on();
        void set_led_off();
        void set_sensor_video_mode(uint8_t mode, uint8_t n);
        void start_sensors_streaming();
        void stop_sensors_streaming();
        void reset_sensors();
        void set_mirror_sensors(uint8_t value);
        void set_flip_sensors(uint8_t value);
        void set_flip_and_mirror_sensors(uint8_t value);
        void dump_sensor_video_mode(uint8_t n);
        void dump_sensor_generalconf(uint8_t n);
        void check_ff71();


    private:
        bool controlTransferReturned;
        bool controlTransferError;
        unsigned int control_wLength;

        //firmware flag default false
        bool firmwareisloaded;
        uint32_t frame_width;
        uint32_t frame_height;
        uint32_t frame_stride;
        uint32_t linesize;
        uint8_t frame_rate;
        uint8_t frame[1280*808*2];
        uint8_t mode;
        eyeframe myframe;
         double last_qued_frame_time;

        std::shared_ptr<class URBDesc> urb;


        PS4EYECam(const PS4EYECam&);
        void operator=(const PS4EYECam&);


        void release();

        bool is_streaming;


        std::shared_ptr<class USBMgr> mgrPtr;

        static bool devicesEnumerated;
        static std::vector<PS4EYERef> devices;



        //usb stuff
        libusb_device *device_;
        libusb_device_handle *handle_;

        struct libusb_transfer * control_transfer;

        uint8_t * control_transfer_buffer;

        //initialization device functions
        bool check_sensors();
        bool init_registers();

        //register operation fuctions
        void multia7_register_write(const uint16_t data[][3], uint8_t len);
        void dump_registers(uint16_t start,uint16_t finish, uint8_t subaddr);
        void multi_register_write(const uint16_t data[][2], uint8_t len, uint8_t subaddr);
        void multi_register_read(const uint16_t (*data), uint8_t len,uint8_t subaddr);
        void register_write(uint16_t reg, uint8_t val,uint8_t subaddr);
        uint8_t register_read(uint16_t reg,uint8_t subaddr);


        void submitAndWait_controlTransfer(uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, uint16_t wLength, uint8_t *buffer);

        void submit_controlTransfer(uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue,uint16_t wIndex, uint16_t wLength, uint8_t*buffer);

        static uint8_t * controlTransferStatus(libusb_transfer_status x);
        void static LIBUSB_CALL ct_done(struct libusb_transfer * transfer);
        
        bool open_usb();
        void close_usb();
        
    };
}// namespace


#endif
