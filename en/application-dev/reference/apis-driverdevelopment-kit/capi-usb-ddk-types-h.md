# usb_ddk_types.h

## Overview

Provides the enumerated variables, structures, and macros used in USB DDK APIs.

**File to include**: <usb/usb_ddk_types.h>

**Library**: libusb_ndk.z.so

**System capability**: SystemCapability.Driver.USB.Extension

**Since**: 10

**Related module**: [UsbDDK](capi-usbddk.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [UsbControlRequestSetup](capi-usbddk-usbcontrolrequestsetup.md) | __attribute__((aligned(8))) UsbControlRequestSetup | Control transfer setup data, which corresponds to **Setup Data** in the USB protocol.|
| [UsbDeviceDescriptor](capi-usbddk-usbdevicedescriptor.md) | __attribute__((aligned(8))) UsbDeviceDescriptor | Standard device descriptor, which corresponds to **Standard Device Descriptor** in the USB protocol.|
| [UsbConfigDescriptor](capi-usbddk-usbconfigdescriptor.md) | __attribute__((packed)) UsbConfigDescriptor | Standard configuration descriptor, which corresponds to **Standard Configuration Descriptor** in the USB protocol.|
| [UsbInterfaceDescriptor](capi-usbddk-usbinterfacedescriptor.md) | __attribute__((packed)) UsbInterfaceDescriptor | Standard interface descriptor, which corresponds to **Standard Interface Descriptor** in the USB protocol.|
| [UsbEndpointDescriptor](capi-usbddk-usbendpointdescriptor.md) | __attribute__((packed)) UsbEndpointDescriptor | Standard endpoint descriptor, which corresponds to **Standard Endpoint Descriptor** in the USB protocol.|
| [UsbDdkEndpointDescriptor](capi-usbddk-usbddkendpointdescriptor.md) | UsbDdkEndpointDescriptor | Endpoint descriptor.|
| [UsbDdkInterfaceDescriptor](capi-usbddk-usbddkinterfacedescriptor.md) | UsbDdkInterfaceDescriptor | Interface descriptor.|
| [UsbDdkInterface](capi-usbddk-usbddkinterface.md) | UsbDdkInterface | USB DDK interface, which is a collection of alternate settings for a particular USB interface.|
| [UsbDdkConfigDescriptor](capi-usbddk-usbddkconfigdescriptor.md) | UsbDdkConfigDescriptor | Configuration descriptor.|
| [UsbRequestPipe](capi-usbddk-usbrequestpipe.md) | __attribute__((aligned(8))) UsbRequestPipe | Defines a USB request pipe.|
| [UsbDeviceMemMap](capi-usbddk-usbdevicememmap.md) | UsbDeviceMemMap | Device memory map created by calling **OH_Usb_CreateDeviceMemMap**. A buffer using the device memory map can provide better performance.|
| [Usb_DeviceArray](capi-usbddk-usb-devicearray.md) | Usb_DeviceArray | Defines the device ID list, which is used to store the device IDs and device quantity obtained using **OH_Usb_GetDevices**.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [UsbDdkErrCode](#usbddkerrcode) | UsbDdkErrCode | USB DDK error code definitions.|

## Enum Description

### UsbDdkErrCode

```
enum UsbDdkErrCode
```

**Description**

USB DDK error code definitions.

**Since**: 10

| Enum| Description|
| -- | -- |
| USB_DDK_SUCCESS = 0 | Operation succeeded.|
| USB_DDK_FAILED = -1 | Operation failed.|
| USB_DDK_INVALID_PARAMETER = -2 | Invalid parameter.|
| USB_DDK_MEMORY_ERROR = -3 | Memory-related error, for example, insufficient memory, memory data copy failure, or memory application failure.|
| USB_DDK_INVALID_OPERATION = -4 | Invalid operation.|
| USB_DDK_NULL_PTR = -5 | Null pointer.|
| USB_DDK_DEVICE_BUSY = -6 | Device busy.|
| USB_DDK_TIMEOUT = -7 | Transfer timeout.|
