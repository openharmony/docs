# scsi_peripheral_api.h


## Overview

Declares the SCSI Peripheral DDK APIs used by the host to access the SCSI device.

**File to include**: &lt;scsi_peripheral/scsi_peripheral_api.h&gt;

**Library**: libscsi.z.so

**System capability**: SystemCapability.Driver.SCSI.Extension

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)


## Summary


### Function

| Name| Description| 
| -------- | -------- |
| int32_t [OH_ScsiPeripheral_Init](_s_c_s_i.md#oh_scsiperipheral_init) (void) | Initializes the SCSI Peripheral DDK.| 
| int32_t [OH_ScsiPeripheral_Release](_s_c_s_i.md#oh_scsiperipheral_release) (void) | Releases the SCSI Peripheral DDK.| 
| int32_t [OH_ScsiPeripheral_Open](_s_c_s_i.md#oh_scsiperipheral_open) (uint64_t deviceId, uint8_t interfaceIndex, [ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*\*dev) | Opens the SCSI device specified by **deviceId** and **interfaceIndex**.| 
| int32_t [OH_ScsiPeripheral_Close](_s_c_s_i.md#oh_scsiperipheral_close) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*\*dev) | Disables the SCSI device.| 
| int32_t [OH_ScsiPeripheral_TestUnitReady](_s_c_s_i.md#oh_scsiperipheral_testunitready) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_TestUnitReadyRequest](_scsi_peripheral___test_unit_ready_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Checks whether the logical units are ready.| 
| int32_t [OH_ScsiPeripheral_Inquiry](_s_c_s_i.md#oh_scsiperipheral_inquiry) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_InquiryRequest](_scsi_peripheral___inquiry_request.md) \*request, [ScsiPeripheral_InquiryInfo](_scsi_peripheral___inquiry_info.md) \*inquiryInfo, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Queries basic information about the SCSI device.| 
| int32_t [OH_ScsiPeripheral_ReadCapacity10](_s_c_s_i.md#oh_scsiperipheral_readcapacity10) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_ReadCapacityRequest](_scsi_peripheral___read_capacity_request.md) \*request, [ScsiPeripheral_CapacityInfo](_scsi_peripheral___capacity_info.md) \*capacityInfo, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Obtains the capacity information about the SCSI device.| 
| int32_t [OH_ScsiPeripheral_RequestSense](_s_c_s_i.md#oh_scsiperipheral_requestsense) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_RequestSenseRequest](_scsi_peripheral___request_sense_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Obtains sense data, that is, information returned by the SCSI device to the host to report the device status, error information, and diagnosis information.| 
| int32_t [OH_ScsiPeripheral_Read10](_s_c_s_i.md#oh_scsiperipheral_read10) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Reads data from a specified logical block.| 
| int32_t [OH_ScsiPeripheral_Write10](_s_c_s_i.md#oh_scsiperipheral_write10) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_IORequest](_scsi_peripheral___i_o_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Writes data to a specified logical block of a device.| 
| int32_t [OH_ScsiPeripheral_Verify10](_s_c_s_i.md#oh_scsiperipheral_verify10) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_VerifyRequest](_scsi_peripheral___verify_request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Verifies a specified logical block.| 
| int32_t [OH_ScsiPeripheral_SendRequestByCdb](_s_c_s_i.md#oh_scsiperipheral_sendrequestbycdb) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, [ScsiPeripheral_Request](_scsi_peripheral___request.md) \*request, [ScsiPeripheral_Response](_scsi_peripheral___response.md) \*response) | Sends SCSI commands in CDB mode.| 
| int32_t [OH_ScsiPeripheral_CreateDeviceMemMap](_s_c_s_i.md#oh_scsiperipheral_createdevicememmap) ([ScsiPeripheral_Device](_s_c_s_i.md#scsiperipheral_device) \*dev, size_t size, [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \*\*devMmap) | Creates a buffer. To avoid memory leakage, use [OH_ScsiPeripheral_DestroyDeviceMemMap](_s_c_s_i.md#oh_scsiperipheral_destroydevicememmap) to destroy a buffer after use.| 
| int32_t [OH_ScsiPeripheral_DestroyDeviceMemMap](_s_c_s_i.md#oh_scsiperipheral_destroydevicememmap) ([ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \*devMmap) | Destroys a buffer. To avoid resource leakage, destroy a buffer in time after use.| 
| int32_t [OH_ScsiPeripheral_ParseBasicSenseInfo](_s_c_s_i.md#oh_scsiperipheral_parsebasicsenseinfo) (uint8_t \*senseData, uint8_t senseDataLen, [ScsiPeripheral_BasicSenseInfo](_scsi_peripheral___basic_sense_info.md) \*senseInfo) | Parses basic sense data, including the **Information**, **Command specific information**, and **Sense key specific** fields.| 
