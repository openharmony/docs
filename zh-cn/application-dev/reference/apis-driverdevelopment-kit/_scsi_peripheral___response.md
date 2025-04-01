# ScsiPeripheral_Response


## 概述

响应参数结构体。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)

**所在头文件：** [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t [senseData](#sensedata) [[SCSIPERIPHERAL_MAX_SENSE_DATA_LEN](_s_c_s_i.md#scsiperipheral_max_sense_data_len)] | sense data（SCSI设备返回给主机的信息，用于报告设备的状态、错误信息以及诊断信息）。 | 
| [ScsiPeripheral_Status](_s_c_s_i.md#scsiperipheral_status) [status](#status) | 调用完成时的状态，例如良好（Good）、忙（Busy）。 | 
| uint8_t [maskedStatus](#maskedstatus) | 在Linux的SCSI通用接口（SG）中，masked_status 字段用于存储经过处理后的SCSI状态， 以便应用程序可以更方便地读取和解析。 | 
| uint8_t [msgStatus](#msgstatus) | 消息状态。 | 
| uint8_t [sbLenWr](#sblenwr) | 指的是实际写入到 Sense Buffer（感应缓冲区）的字节数。 | 
| uint16_t [hostStatus](#hoststatus) | 主机适配器状态。 例如：成功（0x00）、无法连接（0x01）、总线忙（0x02）、超时（0x03）。 | 
| uint16_t [driverStatus](#driverstatus) | 驱动状态。 例如：成功（0x00）、设备或资源忙（0x01）。 | 
| int32_t [resId](#resid) | 实际传输的数据长度差值，即未传输的字节数。 | 
| uint32_t [duration](#duration) | 执行命令消耗的时间（单位：毫秒）。 | 


## 结构体成员变量说明


### driverStatus

```
uint16_t ScsiPeripheral_Response::driverStatus
```

**描述**

驱动状态。 例如：成功（0x00）、设备或资源忙（0x01）。


### duration

```
uint32_t ScsiPeripheral_Response::duration
```

**描述**

执行命令消耗的时间（单位：毫秒）。


### hostStatus

```
uint16_t ScsiPeripheral_Response::hostStatus
```

**描述**

主机适配器状态。 例如：成功（0x00）、无法连接（0x01）、总线忙（0x02）、超时（0x03）。


### maskedStatus

```
uint8_t ScsiPeripheral_Response::maskedStatus
```

**描述**

在Linux的SCSI通用接口（SG）中，masked_status 字段用于存储经过处理后的SCSI状态， 以便应用程序可以更方便地读取和解析。


### msgStatus

```
uint8_t ScsiPeripheral_Response::msgStatus
```

**描述**

消息状态。


### resId

```
int32_t ScsiPeripheral_Response::resId
```

**描述**

实际传输的数据长度差值，即未传输的字节数。


### sbLenWr

```
uint8_t ScsiPeripheral_Response::sbLenWr
```

**描述**

指的是实际写入到 Sense Buffer（感应缓冲区）的字节数。


### senseData

```
uint8_t ScsiPeripheral_Response::senseData[SCSIPERIPHERAL_MAX_SENSE_DATA_LEN]
```

**描述**

sense data（SCSI设备返回给主机的信息，用于报告设备的状态、错误信息以及诊断信息）。


### status

```
ScsiPeripheral_Status ScsiPeripheral_Response::status
```

**描述**

调用完成时的状态，例如良好（Good）、忙（Busy）。
