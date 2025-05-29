# ScsiPeripheral_InquiryInfo


## 概述

SCSI inquiry 数据。

**起始版本：** 18

**相关模块：**[SCSI Peripheral DDK](_s_c_s_i.md)

**所在头文件：** [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint8_t [deviceType](#devicetype) | 设备类型。 | 
| char [idVendor](#idvendor) [[SCSIPERIPHERAL_VENDOR_ID_LEN](_s_c_s_i.md#scsiperipheral_vendor_id_len)+1] | 制造商 id。 | 
| char [idProduct](#idproduct) [[SCSIPERIPHERAL_PRODUCT_ID_LEN](_s_c_s_i.md#scsiperipheral_product_id_len)+1] | 生产商 id。 | 
| char [revProduct](#revproduct) [[SCSIPERIPHERAL_PRODUCT_REV_LEN](_s_c_s_i.md#scsiperipheral_product_rev_len)+1] | 产品版本。 | 
| [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \* [data](#data) | 所有的查询数据。 | 


## 结构体成员变量说明


### data

```
ScsiPeripheral_DeviceMemMap* ScsiPeripheral_InquiryInfo::data
```

**描述**

所有的查询数据。


### deviceType

```
uint8_t ScsiPeripheral_InquiryInfo::deviceType
```

**描述**

设备类型。


### idProduct

```
char ScsiPeripheral_InquiryInfo::idProduct[SCSIPERIPHERAL_PRODUCT_ID_LEN+1]
```

**描述**

生产商 id。


### idVendor

```
char ScsiPeripheral_InquiryInfo::idVendor[SCSIPERIPHERAL_VENDOR_ID_LEN+1]
```

**描述**

制造商 id。


### revProduct

```
char ScsiPeripheral_InquiryInfo::revProduct[SCSIPERIPHERAL_PRODUCT_REV_LEN+1]
```

**描述**

产品版本。
