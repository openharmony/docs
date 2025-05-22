# ScsiPeripheral_InquiryInfo


## Overview

Defines the SCSI inquiry data.

**Since**: 18

**Related module**: [SCSI Peripheral DDK](_s_c_s_i.md)

**Header file**: [scsi_peripheral_types.h](scsi__peripheral__types_8h.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint8_t [deviceType](#devicetype) | Device type.| 
| char [idVendor](#idvendor) [[SCSIPERIPHERAL_VENDOR_ID_LEN](_s_c_s_i.md#scsiperipheral_vendor_id_len)+1] | Vendor ID.| 
| char [idProduct](#idproduct) [[SCSIPERIPHERAL_PRODUCT_ID_LEN](_s_c_s_i.md#scsiperipheral_product_id_len)+1] | Product ID.| 
| char [revProduct](#revproduct) [[SCSIPERIPHERAL_PRODUCT_REV_LEN](_s_c_s_i.md#scsiperipheral_product_rev_len)+1] | Product version.| 
| [ScsiPeripheral_DeviceMemMap](_scsi_peripheral___device_mem_map.md) \* [data](#data) | Inquiry data.| 


## Member Variable Description


### data

```
ScsiPeripheral_DeviceMemMap* ScsiPeripheral_InquiryInfo::data
```

**Description**

Inquiry data.


### deviceType

```
uint8_t ScsiPeripheral_InquiryInfo::deviceType
```

**Description**

Device type.


### idProduct

```
char ScsiPeripheral_InquiryInfo::idProduct[SCSIPERIPHERAL_PRODUCT_ID_LEN+1]
```

**Description**

Product ID.


### idVendor

```
char ScsiPeripheral_InquiryInfo::idVendor[SCSIPERIPHERAL_VENDOR_ID_LEN+1]
```

**Description**

Vendor ID.


### revProduct

```
char ScsiPeripheral_InquiryInfo::revProduct[SCSIPERIPHERAL_PRODUCT_REV_LEN+1]
```

**Description**

Product version.
