PS4EYECam
=========

==================
What is PS4EYECam?
==================

PS4EYECam is a Sony PlayStation 4 Camera driver implementation reference. 

The driver is using [libusb](https://github.com/libusb/libusb) to handle USB communications.

Part of code was based on [PS3EYEDriver](https://github.com/inspirit/PS3EYEDriver).

Payload parsing stuff parts from Linux kernel source(gspca).

UVC video control from  [libuvc](https://github.com/ktossell/libuvc).

Boot and initialization from dumped PlayStation 4 Camera firmware [ps4eye](https://github.com/ps4eye/ps4eye).

Other parts and research based on my experience adding support for different usb devices for Sony PlayStation 2 and Sony PlayStation 3 consoles (ps2eyetoy.irx,ps2mic.irx,ps3kinect.sprx,etc)  

=================================
About PlayStation 4 Camera device
=================================

PlayStation 4 Camera has a Sony propietary connector called AUX, it is an USB 3 connector without USB 2 differential data pair(d+ and d-). If you want to use it on other platform different than PlayStation 4 console you must adapt wire and connector to USB 3. Reference:

* [wikipedia](http://en.wikipedia.org/wiki/PlayStation_Camera).

* [ps4developerwiki](http://www.psdevwiki.com/ps4/PlayStation_4_Camera).

* [auxconnector](http://www.psdevwiki.com/ps4/Aux).

It is based on:

	OV580 asic from Omnivision is a usb bridge and control all other chips. 
	OV9713 cmos sensor camera from omnivision. It has 2. 
	5703 A/D converter from AKM. 
	4g51A eeprom sop-j8 package from ROHM?
	...

* usb descriptor when firmware is loaded

```
Bus 004 Device 002: ID 05a9:058a OmniVision Technologies, Inc. 
Device Descriptor:
  bLength                18
  bDescriptorType         1
  bcdUSB               3.00
  bDeviceClass          239 Miscellaneous Device
  bDeviceSubClass         2 ?
  bDeviceProtocol         1 Interface Association
  bMaxPacketSize0         9
  idVendor           0x05a9 OmniVision Technologies, Inc.
  idProduct          0x058a 
  bcdDevice            1.00
  iManufacturer           1 Omnivision Technologies, Inc.
  iProduct                2 USB Camera-OV580
  iSerial                 0 
  bNumConfigurations      1
  Configuration Descriptor:
    bLength                 9
    bDescriptorType         2
    wTotalLength          311
    bNumInterfaces          2
    bConfigurationValue     1
    iConfiguration          0 
    bmAttributes         0x80
      (Bus Powered)
    MaxPower              128mA
    Interface Association:
      bLength                 8
      bDescriptorType        11
      bFirstInterface         0
      bInterfaceCount         2
      bFunctionClass         14 Video
      bFunctionSubClass       3 Video Interface Collection
      bFunctionProtocol       0 
      iFunction               2 USB Camera-OV580
    Interface Descriptor:
      bLength                 9
      bDescriptorType         4
      bInterfaceNumber        0
      bAlternateSetting       0
      bNumEndpoints           0
      bInterfaceClass        14 Video
      bInterfaceSubClass      1 Video Control
      bInterfaceProtocol      0 
      iInterface              2 USB Camera-OV580
      VideoControl Interface Descriptor:
        bLength                13
        bDescriptorType        36
        bDescriptorSubtype      1 (HEADER)
        bcdUVC               1.00
        wTotalLength           77
        dwClockFrequency      125.000000MHz
        bInCollection           1
        baInterfaceNr( 0)       1
      VideoControl Interface Descriptor:
        bLength                18
        bDescriptorType        36
        bDescriptorSubtype      2 (INPUT_TERMINAL)
        bTerminalID             1
        wTerminalType      0x0201 Camera Sensor
        bAssocTerminal          0
        iTerminal               0 
        wObjectiveFocalLengthMin      0
        wObjectiveFocalLengthMax      0
        wOcularFocalLength            0
        bControlSize                  3
        bmControls           0x0000000a
          Auto-Exposure Mode
          Exposure Time (Absolute)
      VideoControl Interface Descriptor:
        bLength                 9
        bDescriptorType        36
        bDescriptorSubtype      3 (OUTPUT_TERMINAL)
        bTerminalID             2
        wTerminalType      0x0101 USB Streaming
        bAssocTerminal          0
        bSourceID               3
        iTerminal               0 
      VideoControl Interface Descriptor:
        bLength                11
        bDescriptorType        36
        bDescriptorSubtype      5 (PROCESSING_UNIT)
      Warning: Descriptor too short
        bUnitID                 3
        bSourceID               1
        wMaxMultiplier          0
        bControlSize            2
        bmControls     0x0000165f
          Brightness
          Contrast
          Hue
          Saturation
          Sharpness
          White Balance Temperature
          Gain
          Power Line Frequency
          White Balance Temperature, Auto
        iProcessing             2 USB Camera-OV580
        bmVideoStandards     0x1a
          NTSC - 525/60
          SECAM - 625/50
          NTSC - 625/50
      VideoControl Interface Descriptor:
        bLength                26
        bDescriptorType        36
        bDescriptorSubtype      6 (EXTENSION_UNIT)
        bUnitID                 4
        guidExtensionCode         {8a0f88dd-ba1c-5449-8a25-f7875967f0f7}
        bNumControl             1
        bNrPins                 1
        baSourceID( 0)          1
        bControlSize            1
        bmControls( 0)       0x01
        iExtension              2 USB Camera-OV580
    Interface Descriptor:
      bLength                 9
      bDescriptorType         4
      bInterfaceNumber        1
      bAlternateSetting       0
      bNumEndpoints           0
      bInterfaceClass        14 Video
      bInterfaceSubClass      2 Video Streaming
      bInterfaceProtocol      0 
      iInterface              0 
      VideoStreaming Interface Descriptor:
        bLength                            14
        bDescriptorType                    36
        bDescriptorSubtype                  1 (INPUT_HEADER)
        bNumFormats                         1
        wTotalLength                      177
        bEndPointAddress                  129
        bmInfo                              0
        bTerminalLink                       2
        bStillCaptureMethod                 0
        bTriggerSupport                     0
        bTriggerUsage                       0
        bControlSize                        1
        bmaControls( 0)                    27
      VideoStreaming Interface Descriptor:
        bLength                            27
        bDescriptorType                    36
        bDescriptorSubtype                  4 (FORMAT_UNCOMPRESSED)
        bFormatIndex                        1
        bNumFrameDescriptors                3
        guidFormat                            {59555932-0000-1000-8000-00aa00389b71}
        bBitsPerPixel                      16
        bDefaultFrameIndex                  1
        bAspectRatioX                       0
        bAspectRatioY                       0
        bmInterlaceFlags                 0x00
          Interlaced stream or variable: No
          Fields per frame: 2 fields
          Field 1 first: No
          Field pattern: Field 1 only
          bCopyProtect                      0
      VideoStreaming Interface Descriptor:
        bLength                            42
        bDescriptorType                    36
        bDescriptorSubtype                  5 (FRAME_UNCOMPRESSED)
        bFrameIndex                         1
        bmCapabilities                   0x00
          Still image unsupported
        wWidth                           3448
        wHeight                           808
        dwMinBitRate                  5571968
        dwMaxBitRate                167159040
        dwMaxVideoFrameBufferSize     5571968
        dwDefaultFrameInterval         166666
        bFrameIntervalType                  4
        dwFrameInterval( 0)            166666
        dwFrameInterval( 1)            333333
        dwFrameInterval( 2)            666666
        dwFrameInterval( 3)           1250000
      VideoStreaming Interface Descriptor:
        bLength                            46
        bDescriptorType                    36
        bDescriptorSubtype                  5 (FRAME_UNCOMPRESSED)
        bFrameIndex                         2
        bmCapabilities                   0x00
          Still image unsupported
        wWidth                           1748
        wHeight                           408
        dwMinBitRate                  1426368
        dwMaxBitRate                 42791040
        dwMaxVideoFrameBufferSize     1426368
        dwDefaultFrameInterval          83333
        bFrameIntervalType                  5
        dwFrameInterval( 0)             83333
        dwFrameInterval( 1)            166666
        dwFrameInterval( 2)            333333
        dwFrameInterval( 3)            666666
        dwFrameInterval( 4)           1250000
      VideoStreaming Interface Descriptor:
        bLength                            42
        bDescriptorType                    36
        bDescriptorSubtype                  5 (FRAME_UNCOMPRESSED)
        bFrameIndex                         3
        bmCapabilities                   0x00
          Still image unsupported
        wWidth                            898
        wHeight                           200
        dwMinBitRate                   359200
        dwMaxBitRate                 10776000
        dwMaxVideoFrameBufferSize      359200
        dwDefaultFrameInterval          41666
        bFrameIntervalType                  4
        dwFrameInterval( 0)             41666
        dwFrameInterval( 1)             83333
        dwFrameInterval( 2)            166666
        dwFrameInterval( 3)            333333
      VideoStreaming Interface Descriptor:
        bLength                             6
        bDescriptorType                    36
        bDescriptorSubtype                 13 (COLORFORMAT)
        bColorPrimaries                     1 (BT.709,sRGB)
        bTransferCharacteristics            1 (BT.709)
        bMatrixCoefficients                 4 (SMPTE 170M (BT.601))
    Interface Descriptor:
      bLength                 9
      bDescriptorType         4
      bInterfaceNumber        1
      bAlternateSetting       1
      bNumEndpoints           1
      bInterfaceClass        14 Video
      bInterfaceSubClass      2 Video Streaming
      bInterfaceProtocol      0 
      iInterface              0 
      Endpoint Descriptor:
        bLength                 7
        bDescriptorType         5
        bEndpointAddress     0x81  EP 1 IN
        bmAttributes            5
          Transfer Type            Isochronous
          Synch Type               Asynchronous
          Usage Type               Data
        wMaxPacketSize     0x0400  1x 1024 bytes
        bInterval               1
        bMaxBurst              15
        Mult                    2
Binary Object Store Descriptor:
  bLength                 5
  bDescriptorType        15
  wTotalLength           22
  bNumDeviceCaps          2
  USB 2.0 Extension Device Capability:
    bLength                 7
    bDescriptorType        16
    bDevCapabilityType      2
    bmAttributes   0x00000002
      Link Power Management (LPM) Supported
  SuperSpeed USB Device Capability:
    bLength                10
    bDescriptorType        16
    bDevCapabilityType      3
    bmAttributes         0x00
    wSpeedsSupported   0x000c
      Device can operate at High Speed (480Mbps)
      Device can operate at SuperSpeed (5Gbps)
    bFunctionalitySupport   2
      Lowest fully-functional device speed is High Speed (480Mbps)
    bU1DevExitLat          10 micro seconds
    bU2DevExitLat          32 micro seconds
Device Status:     0x0f0c
  (Bus Powered)
  U1 Enabled
  U2 Enabled
  
  
  information interesting about usb 2 superspeed
  USB 3.0 Endpoint Companion:
  bMaxBurst:        15
  bmAttributes:     0x02
  wBytesPerInterval: 49152
  
```

Interface 1 alt setting 0 describe all video modes see uvc_set_video(uint8_t mode,uint8_t fps) function with these possible options:

* mode 0 fps 60(default), 30, 15, 8  video left and video right frames 1280x800

* mode 1 fps 120(default), 60, 30, 15, 8 video left and video right frames 640x400

* mode 2 fps 240(default), 120, 60, 30 video left and video right frames 320x192

device frame format:

* mode 0  3448x2x808 bytes frame each row:
	* header 32 bytes 
	* audio 64 bytes 
	* video left 1280x2 bytes
	* video right 1280x2 bytes
	* video interleave 840x2 bytes
* mode 1 1748x2x408 bytes frame each row:
	* header 32 bytes 
	* audio 64 bytes 
	* video left 640x2 bytes 
	* video right 640x2 bytes
	* video interleave 420x2 bytes
* mode 2 898x2x200 bytes frame each row
	* header 32 bytes 
	* audio 64 bytes 
	* video left 320x2 bytes 
	* video right 320x2 bytes
	* video interleave 210x2 bytes

===================
Supported platforms
===================

PS4EYECam is a USB 3 device and it is using libusb so it can be ported to all platforms supported by libusb and with USB 3 controllers.

Implemetation reference was done in OSX Mavericks and i only tested it on this platform. 


=============
OSX Mavericks
=============

A sample PS4EYECapture with PS4EYECam tested on OSX Maverick is included using:

* [libcinder](https://github.com/cinder/Cinder).

* [ciUI](https://github.com/bigboss-ps3dev/ciUI) With little modification to use in Mavericks environment.

* [opencv-cinder](https://github.com/cinder/Cinder-OpenCV) 

Sample output with Cinder in OSX Mavericks:

![alt text](https://raw.github.com/bigboss-ps3dev/PS4EYECam/master/video.png "PS4EYECapture Running with Cinder mode 1 120 fps")

You will need a few things installed before:

* xcode

* macport or similar 

* libusb (with macport is installed in /local/opt/lib)
```
	$ pwd
	/opt/local/lib
	$ ls -l libusb-1.0.*
	-rwxr-xr-x  1 root  admin  190412 11 sep 22:17 libusb-1.0.0.dylib
	-rw-r--r--  1 root  admin  244528 11 sep 22:17 libusb-1.0.a
	lrwxr-xr-x  1 root  admin      18 11 sep 22:17 libusb-1.0.dylib -> libusb-1.0.0.dylib
```	
* Compile and install [libcinder](https://github.com/cinder/Cinder) follow [gitsetup](http://libcinder.org/docs/welcome/GitSetup.html).

* Install ciUI and Cinder-OpenCV blocks
```
	$ pwd
	/[YOUR_OWN_PATH]/cinder_master
	$ cd blocks
	$ git clone https://github.com/bigboss-ps3dev/ciUI
	$ git clone https://github.com/cinder/Cinder-OpenCV
```	
* Use TinderBox-Mac tool to create a PS4EYECapture project 	/[YOUR_OWN_PATH]/cinder_master/tools/TinderBox-Mac

1) Choose project name PS4EYECapture , path and choose cinder_master or your repository name and choose next_

![alt text](https://raw.github.com/bigboss-ps3dev/PS4EYECam/master/tinder0.png "Choose PS4EYECapture name")

2) Choose ciUI block and option copy

![alt text](https://raw.github.com/bigboss-ps3dev/PS4EYECam/master/tinder1.png "Mode copy ciUI")

3) Choose OpenCV block and option relative

![alt text](https://raw.github.com/bigboss-ps3dev/PS4EYECam/master/tinder2.png "Mode reference opencv")

4) Choose finish and project is created choose xcode project file and open it

![alt text](https://raw.github.com/bigboss-ps3dev/PS4EYECam/master/tinder3.png "project created")

![alt text](https://raw.github.com/bigboss-ps3dev/PS4EYECam/master/tinder4.png "xcode0")

5) Clone PS4EYECam repository  
```
	git clone https://github.com/bigboss-ps3dev/PS4EYECam 
```
6) Copy driver/src/*.cpp to your PS4EYECapture/src

7) Copy cinder/src/*.cpp to your PS4EYECapture/src

8) Copy driver/include/*.h to your PS4EYECapture/include

9) Copy cinder/resources/firmware.bin to your PS4EYECapture/resources

10) Copy /opt/local/inclide/libusb-1.0/libusb.h to your PS4EYECapture/include

11) Copy /opt/local/lib/libusb-1.0.0.dylib to your cinder_master/lib/macosx/

12) Incorporate cpp files from driver/src and cinder/src on src, firmware.bin to resources headers files to include and libusb lib.

![alt text](https://raw.github.com/bigboss-ps3dev/PS4EYECam/master/xcode.png "xcode ready")

13) Ready to compile and run 


Openframeworks ugly sample:
1) Create xcode empty PS4EYECapture project you can add opencv addons but it is very old and you can't use opencv conversion from it.
2) Import files included on openframeworks folder
3) Add libusb lib to the project
4) Remember 32 bits only

=======
CHANGES
=======

* Fixed support for left and right camera
* Added opencv support with functions to convert from raw YUYV to RGB
* Added sample capture to show mode 1 640x400 with left and rigth camera enabled at 120 fps 
* Added ugly support for openframework. Problems with openframeworks: opencv included in it is veryyyyy old , you wiil need opencv 2.4.9 to use CV_YUV2RGB_YUY2 conversion. Added a conversion method without opencv. Are you kidding? It supports 32 bits only. Personal experience it is a really pain in the ass compiling openframeworks with xcode 6.x. I will not give support to it until i see a 64 bit and updated opencv version on it.
* Identified unknown1, unknown2 and unknown3 formats


=========
TODO LIST
=========

* Calibration for stereo vision in progress

* Port driver to other platforms (linux , windows, android, oculus, unity3d...)

* Fix, improve , incorporate new features

* If someone has ov580 datasheet contact with me please 


========
Contacts
========

You can follow and contact me on twitter @psxdev



