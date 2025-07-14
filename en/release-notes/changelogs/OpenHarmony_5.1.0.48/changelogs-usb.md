# Driver Subsystem Changelog

## cl.usb.1 USB Device HDI API Changes

**Access Level**

Public API

**Reason for the Change**

To adapt to feature-based reconstruction of the USB subsystem, the original HDI APIs are divided into three feature categories: Host, Device, and Port.

**Change Impact**

This change is a non-compatible change.

| API Capability    | Before Change    | After Change                                     |
|-----------------|-------------------------|---------------------------|
| USB device management (device query, open/close, and device configuration management), USB data transfer, and USB device access authorization in host mode| In v1_0, v1_1, and v1_2, the related APIs are contained in **IUsbInterface.idl** and called by **UsbService**.| In v2_0, the related APIs are contained in **IUsbHostInterface.idl** and called by **UsbHostManager**.|
| USB port configuration management (port list query and port role query and setting) | Same as the above| In v2_0, the related APIs are contained in **IUsbHostInterface.idl** and called by **UsbPortManager**.|
| USB function management (query/setting) | Same as the above| In v2_0, the related APIs are contained in **IUsbHostInterface.idl** and called by **UsbDeviceManager**.|
| All data types used by HDI APIs | In v1_0, v1_1, and v1_2, the related data types are defined in **UsbTypes.idl** and used by **UsbService**.| In v2_0, the related data types are defined in **UsbTypes.idl** and used by **UsbHostManager**, **UsbPortManager**, and **UsbDeviceManager**.|
| Asynchronous callbacks | In v1_0 and v1_2, data is returned via **UsbService**.| In v2_0, data is returned via **UsbHostManager**, **UsbDeviceManager**, and **UsbPortManager**.|
| Batch transfer callbacks | Same as the above| Same as the above|
| Device event and port change event processing APIs | In v1_0, device events are processed by **DeviceEvent** and **PortChangedEvent** in a unified manner.| In v2_0, device events are processed by **DeviceEvent** based on the Host Feature and Device Feature categories. The port change events are processed by **PortChangedEvent** based on the Port Feature category.|

**Start API Level**

API 9

**Change Since**

OpenHarmony 5.1.0.48

**Key API/Component Changes**

DeviceEvent and PortChangedEvent

**Adaptation Guide**

No adaptation is required. You do not need to configure the feature category for devices that do not support the USB host or USB device mode.
