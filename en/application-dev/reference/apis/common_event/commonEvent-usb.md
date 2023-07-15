# Common Events of the USB Subsystem
This document lists the common system events provided by the USB subsystem to applications. Applications can use [APIs](../js-apis-commonEventManager.md) to subscribe to common system events.

## COMMON_EVENT_USB_STATE
Indicates that the USB device state has changed.

- Constant value: "usual.event.hardware.usb.action.USB_STATE"
- Required subscriber permissions: none

When a USB device is connected to or disconnected from the device, the event notification service is triggered to publish this event.

## COMMON_EVENT_USB_PORT_CHANGED

Indicates that the USB port state of the device has changed.

- Constant value: "usual.event.hardware.usb.action.USB_PORT_CHANGED"
- Required subscriber permissions: none

When the USB port status changes, the event notification service is triggered to publish this event.

APIs related to this event: **dataRole** parameter in [setPortRoles](../js-apis-usbManager.md#usbsetportroles).

## COMMON_EVENT_USB_DEVICE_ATTACHED

Indicates that a USB device has been attached to the device functioning as a USB host.

- Constant value: "usual.event.hardware.usb.action.USB_DEVICE_ATTACHED"
- Required subscriber permissions: none

When a USB device is attached, the event notification service is triggered to publish this event.

APIs related to this event: [USBDevice](../js-apis-usbManager.md#usbdevice).

## COMMON_EVENT_USB_DEVICE_DETACHED

Indicates that a USB device has been detached from the device functioning as a USB host.

- Constant value: "usual.event.hardware.usb.action.USB_DEVICE_DETACHED"
- Required subscriber permissions: none

When a USB device is deattached, the event notification service is triggered to publish this event.

APIs related to this event: [USBDevice](../js-apis-usbManager.md#usbdevice).

## COMMON_EVENT_USB_ACCESSORY_ATTACHED

(Reserved, not supported yet) Indicates that a USB accessory was attached.

- Constant value: "usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED"
- Required subscriber permissions: none

## COMMON_EVENT_USB_ACCESSORY_DETACHED

(Reserved, not supported yet) Indicates that a USB accessory was detached.

- Constant value: "usual.event.data.DISK_MOUNTED"
- Required subscriber permissions: none
