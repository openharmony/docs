# scsi_peripheral_api.h


## 概述

声明用于主机侧访问SCSI设备的SCSI Peripheral DDK接口。

**引用文件：** &lt;scsi_peripheral/scsi_peripheral_api.h&gt;

**系统能力：** SystemCapability.Driver.SCSI.Extension

**起始版本：** 16

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ScsiPeripheral_Init](_s_c_s_i.md#oh_scsiperipheral_init) (void) | 初始化SCSI Peripheral DDK。 | 
| int32_t [OH_ScsiPeripheral_Release](_s_c_s_i.md#oh_scsiperipheral_release) (void) | 释放SCSI Peripheral DDK。 | 
| int32_t [OH_ScsiPeripheral_Open](_s_c_s_i.md#oh_scsiperipheral_open) (uint64_t deviceId, uint8_t interfaceIndex, [ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*\*dev) | 打开deviceId和interfaceIndex指定的SCSI设备。 | 
| int32_t [OH_ScsiPeripheral_Close](_s_c_s_i.md#oh_scsiperipheral_close) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*\*dev) | 关闭SCSI设备。 | 
| int32_t [OH_ScsiPeripheral_TestUnitReady](_s_c_s_i.md#oh_scsiperipheral_testunitready) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 检查逻辑单元是否已经准备好。 | 
| int32_t [OH_ScsiPeripheral_Inquiry](_s_c_s_i.md#oh_scsiperipheral_inquiry) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md) \*request, [ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md) \*inquiryInfo, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 查询SCSI设备的基本信息。 | 
| int32_t [OH_ScsiPeripheral_ReadCapacity10](_s_c_s_i.md#oh_scsiperipheral_readcapacity10) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md) \*request, [ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md) \*capacityInfo, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 获取SCSI设备的容量信息。 | 
| int32_t [OH_ScsiPeripheral_RequestSense](_s_c_s_i.md#oh_scsiperipheral_requestsense) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 获取sense data（SCSI设备返回给主机的信息，用于报告设备的状态、错误信息以及诊断信息）。 | 
| int32_t [OH_ScsiPeripheral_Read10](_s_c_s_i.md#oh_scsiperipheral_read10) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 从指定逻辑块读取数据。 | 
| int32_t [OH_ScsiPeripheral_Write10](_s_c_s_i.md#oh_scsiperipheral_write10) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 写数据到设备的指定逻辑块。 | 
| int32_t [OH_ScsiPeripheral_Verify10](_s_c_s_i.md#oh_scsiperipheral_verify10) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 校验指定逻辑块。 | 
| int32_t [OH_ScsiPeripheral_SendRequestByCdb](_s_c_s_i.md#oh_scsiperipheral_sendrequestbycdb) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_Request](_scsi_peripheral___request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | 以CDB（Command Descriptor Block）方式发送SCSI命令。 | 
| int32_t [OH_ScsiPeripheral_CreateDeviceMemMap](_s_c_s_i.md#oh_scsiperipheral_createdevicememmap) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, size_t size, [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \*\*devMmap) | 创建缓冲区。请在缓冲区使用完后，调用[OH_ScsiPeripheral_DestroyDeviceMemMap](_s_c_s_i.md#oh_scsiperipheral_destroydevicememmap)销毁缓冲区，否则会造成资源泄露。 | 
| int32_t [OH_ScsiPeripheral_DestroyDeviceMemMap](_s_c_s_i.md#oh_scsiperipheral_destroydevicememmap) ([ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \*devMmap) | 销毁缓冲区。请在缓冲区使用完后及时销毁缓冲区，否则会造成资源泄露。 | 
| int32_t [OH_ScsiPeripheral_ParseBasicSenseInfo](_s_c_s_i.md#oh_scsiperipheral_parsebasicsenseinfo) (uint8_t \*senseData, uint8_t senseDataLen, [ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md) \*senseInfo) | 解析基本的sense data，包括Information、Command specific information、Sense key specific字段。 | 
