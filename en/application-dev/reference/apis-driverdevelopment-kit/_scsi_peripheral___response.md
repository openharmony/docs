# ScsiPeripheral_Response


## Overview

Defines the response structure.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t [senseData](#sensedata) [[SCSIPERIPHERAL_MAX_SENSE_DATA_LEN](_s_c_s_i.md#scsiperipheral_max_sense_data_len)] | Sense data, that is, information returned by the SCSI device to the host to report the device status, error information, and diagnosis information.| 
| [ScsiPeripheral_Status](_s_c_s_i.md#scsiperipheral_status) [status](#status) | Status when the call is complete, for example, **Good** or **Busy**.| 
| uint8_t [maskedStatus](#maskedstatus) | Masked status, which is used in SCSI Generic (SG) interfaces of Linux to store the processed SCSI status for easy access by applications.| 
| uint8_t [msgStatus](#msgstatus) | Message status.| 
| uint8_t [sbLenWr](#sblenwr) | Number of bytes that are actually written to the sense buffer.| 
| uint16_t [hostStatus](#hoststatus) | Host adapter status, for example, success (0x00), connection failure (0x01), busy bus (0x02), or timeout (0x03).| 
| uint16_t [driverStatus](#driverstatus) | Driver status, for example, success (0x00) or busy device or resource (0x01).| 
| int32_t [resId](#resid) | Length deviation of the actually transmitted data, that is, the number of bytes that are not transmitted.| 
| uint32_t [duration](#duration) | Command execution duration, in ms.| 


## Member Variable Description


### driverStatus

```
uint16_t ScsiPeripheral_Response::driverStatus
```

**Description**

Driver status, for example, success (0x00) or busy device or resource (0x01).


### duration

```
uint32_t ScsiPeripheral_Response::duration
```

**Description**

Command execution duration, in ms.


### hostStatus

```
uint16_t ScsiPeripheral_Response::hostStatus
```

**Description**

Host adapter status, for example, success (0x00), connection failure (0x01), busy bus (0x02), or timeout (0x03).


### maskedStatus

```
uint8_t ScsiPeripheral_Response::maskedStatus
```

**Description**

Masked status, which is used in SCSI Generic (SG) interfaces of Linux to store the processed SCSI status for easy access by applications.


### msgStatus

```
uint8_t ScsiPeripheral_Response::msgStatus
```

**Description**

Message status.


### resId

```
int32_t ScsiPeripheral_Response::resId
```

**Description**

Length deviation of the actually transmitted data, that is, the number of bytes that are not transmitted.


### sbLenWr

```
uint8_t ScsiPeripheral_Response::sbLenWr
```

**Description**

Number of bytes that are actually written to the sense buffer.


### senseData

```
uint8_t ScsiPeripheral_Response::senseData[SCSIPERIPHERAL_MAX_SENSE_DATA_LEN]
```

**Description**

Sense data, that is, information returned by the SCSI device to the host to report the device status, error information, and diagnosis information.


### status

```
ScsiPeripheral_Status ScsiPeripheral_Response::status
```

**Description**

Status when the call is complete, for example, **Good** or **Busy**.
