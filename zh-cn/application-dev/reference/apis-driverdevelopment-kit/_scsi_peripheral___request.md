# ScsiPeripheral_Request


## 概述

请求参数结构体。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t [commandDescriptorBlock](#commanddescriptorblock) [[SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN](_s_c_s_i.md#scsiperipheral_max_cmd_desc_block_len)] | 命令描述符块。 | 
| uint8_t [cdbLength](#cdblength) | 命令描述符块的长度。 | 
| int8_t [dataTransferDirection](#datatransferdirection) | 数据传输方向。 | 
| [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \* [data](#data) | 数据传输的缓冲区。 | 
| uint32_t [timeout](#timeout) | 超时时间（单位：毫秒）。 | 


## 结构体成员变量说明


### cdbLength

```
uint8_t ScsiPeripheral_Request::cdbLength
```

**描述**

命令描述符块的长度。


### commandDescriptorBlock

```
uint8_t ScsiPeripheral_Request::commandDescriptorBlock[SCSIPERIPHERAL_MAX_CMD_DESC_BLOCK_LEN]
```

**描述**

命令描述符块。


### data

```
ScsiPeripheral_DeviceMemMap* ScsiPeripheral_Request::data
```

**描述**

数据传输的缓冲区。


### dataTransferDirection

```
int8_t ScsiPeripheral_Request::dataTransferDirection
```

**描述**

数据传输方向。


### timeout

```
uint32_t ScsiPeripheral_Request::timeout
```

**描述**

超时时间（单位：毫秒）。
