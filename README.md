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

===================
Supported platforms
===================

PS4EYECam is a USB 3 device and it is using libusb  so it can be ported to all platforms supported by libusb and with USB 3 controllers.

Implemetation reference was done in OSX Mavericks and i only tested it on this platform. 







