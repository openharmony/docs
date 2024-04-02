# Hid_Device


## Overview

Defines basic device information.

**Since**

11

**Related module**

[HID DDK](_hid_ddk.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [deviceName](#devicename) | Device name.| 
| [vendorId](#vendorid) | Vendor ID.| 
| [productId](#productid) | Product ID.| 
| [version](#version) | Version number.| 
| [bustype](#bustype) | Bus type.| 
| [properties](#properties) | Device properties.| 
| [propLength](#proplength) | Number of device properties.| 


## Member Variable Description


### deviceName


```
const char Hid_Device::deviceName
```

**Description**

Device name.


### vendorId


```
uint16_t Hid_Device::vendorId
```

**Description**

Vendor ID.


### productId


```
uint16_t  Hid_Device::productId
```

**Description**

Product ID.


### version


```
uint16_t Hid_Device::version
```

**Description**

Version number.


### bustype


```
uint16_t Hid_Device::bustype
```

**Description**

Bus type.


### properties


```
Hid_DeviceProp Hid_Device::properties
```

**Description**

Device properties.


### propLength


```
uint16_t Hid_Device::propLength
```

**Description**

Number of device properties.
