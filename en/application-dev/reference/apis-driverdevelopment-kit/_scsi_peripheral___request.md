# ScsiPeripheral_Request


## Overview

Defines the request structure.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)


## Summary


### Member Variables

| **Name**| Description| 
| -------- | -------- |
| uint8_t [commandDescriptorBlock](#commanddescriptorblock) [[SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN](_s_c_s_i.md#scsiperipheral_max_cmd_desc_block_len)] | Command descriptor block.| 
| uint8_t [cdbLength](#cdblength) | Length of the command descriptor block.| 
| int8_t [dataTransferDirection](#datatransferdirection) | Data transmission direction.| 
| [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \* [data](#data) | Buffer for data transmission.| 
| uint32_t [timeout](#timeout) | Timeout duration, in ms.| 


## Member Variable Description


### cdbLength

```
uint8_t ScsiPeripheral_Request::cdbLength
```

**Description**

Length of the command descriptor block.


### commandDescriptorBlock

```
uint8_t ScsiPeripheral_Request::commandDescriptorBlock[SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN]
```

**Description**

Command descriptor block.


### data

```
ScsiPeripheral_DeviceMemMap* ScsiPeripheral_Request::data
```

**Description**

Buffer for data transmission.


### dataTransferDirection

```
int8_t ScsiPeripheral_Request::dataTransferDirection
```

**Description**

Data transmission direction.


### timeout

```
uint32_t ScsiPeripheral_Request::timeout
```

**Description**

Timeout duration, in ms.
