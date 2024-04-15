# IUsbInterface


## Overview

Provides APIs to implement basic operations of the USB driver module.

The USB service can call related APIs to enable or disable a device, obtain a device descriptor, and read or write data in bulk mode.

**Since**: 5.0

**Related module**: [USB](_u_s_b_v10.md)


## Summary


### Public Member Functions

| Name| Description| 
| -------- | -------- |
| [GetDeviceSpeed](#getdevicespeed) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [out] unsigned char speed) | Obtains the speed of a device.| 
| [GetInterfaceActiveStatus](#getinterfaceactivestatus) ([in] struct [UsbDev](_usb_dev_v10.md) dev, [in] unsigned char interfaceid, [out] bool unactived) | Checks whether an interface is activated.| 

### GetDeviceSpeed()

```
IUsbInterface::GetDeviceSpeed ([in] struct UsbDev dev, [out] unsigned char speed )
```
**Description**<br>
Obtains the speed of a device.

**Since**: 5.0

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| speed | Speed of the device.| 

**Returns**

**0**: Unknown.
**1**: low-speed transmission.
**2**: full-speed transmission.
**3**: high-speed transmission.
**4**: wireless transmission.
**5**: rapid transmission.
**6**: overspeed transmission.
Other values: The operation fails.

### GetInterfaceActiveStatus()

```
IUsbInterface::GetInterfaceActiveStatus ([in] struct UsbDev dev, [in] unsigned char interfaceid, [out] bool unactived)
```
**Description**<br>
Checks whether an interface is activated.

**Since**: 5.0

**Parameters**

| Name| Description| 
| -------- | -------- |
| dev | USB device address. For details, see [UsbDev](_usb_dev_v10.md). | 
| interfaceid | USB interface ID. | 
| unactived | Whether the USB interface is activated. The value **true** means that the interface is not activated, and **false** means that the interface is activated.| 

**Returns**

**0**: The interface is activated.
**1**: The interface is not activated.
Other values: The operation fails.
