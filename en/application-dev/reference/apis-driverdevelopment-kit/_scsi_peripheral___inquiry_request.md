# ScsiPeripheral_InquiryRequest


## Overview

Defines the request structure of the **inquiry** command.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t [pageCode](#pagecode) | **Page code** field. Set this filed if you want to obtain certain types of device information. When an **Inquiry** command with a specific page code is run, the device returns details related to the page code. If the page code is set to **0x00**, it indicates that the standard inquiry data rather than the data of specific pages is requested.| 
| uint16_t [allocationLength](#allocationlength) | **Allocation length** field used to specify the size of the buffer prepared by the request initiator (usually the host) for the response data.| 
| uint8_t [control](#control) | **Control** field used to specify control information.| 
| uint8_t [byte1](#byte1) | First byte of the CDB.| 
| uint32_t [timeout](#timeout) | Timeout duration, in ms.| 


## Member Variable Description


### allocationLength

```
uint16_t ScsiPeripheral_InquiryRequest::allocationLength
```

**Description**

**Allocation length** field used to specify the size of the buffer prepared by the request initiator (usually the host) for the response data.


### byte1

```
uint8_t ScsiPeripheral_InquiryRequest::byte1
```

**Description**

First byte of the CDB.


### control

```
uint8_t ScsiPeripheral_InquiryRequest::control
```

**Description**

**Control** field used to specify control information.


### pageCode

```
uint8_t ScsiPeripheral_InquiryRequest::pageCode
```

**Description**

**Page code** field. Set this filed if you want to obtain certain types of device information. When an **Inquiry** command with a specific page code is run, the device returns details related to the page code. If the page code is set to **0x00**, it indicates that the standard inquiry data rather than the data of specific pages is requested.


### timeout

```
uint32_t ScsiPeripheral_InquiryRequest::timeout
```

**Description**

Timeout duration, in ms.
