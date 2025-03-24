# FAQs

## What should I do if the device list obtained by using usbManager.getDevices is empty when the device is connected to a PC using a USB cable?

### Symptom

After a device is connected to a PC using a USB cable, the device list obtained by **usbManager.getDevices** is empty, and the PC is not identified as a USB device.

### Possible Causes

USB devices are classified into two types: host and device. The USB host takes charge of data transmission and USB port management, and USB devices are managed by the USB host.

If the current device functions as the USB host, the **usbManager.getDevices** API can be used to obtain the list of connected USB devices.

Based on the preceding description:

- When a device, for example, a phone, is connected to a PC using a USB cable, the PC is the USB host by default, and the phone is a USB device.
It is normal if the device list obtained by calling **usbManager.getDevices** on the phone is empty.
- When a device, for example, a phone, is connected to a mouse or keyboard using a USB cable, the phone is the USB host by default, and the mouse or keyboard is the USB device.
In this case, you can call the **usbManager.getDevices** API on the phone to obtain the device list.

### Solution

Ensure that the current device is the USB host and the connected device is the USB device. (Some devices can serve both as the USB host and USB device. In this case, you need to set such devices as USB devices so that the device list can be obtained by the USB host.)
