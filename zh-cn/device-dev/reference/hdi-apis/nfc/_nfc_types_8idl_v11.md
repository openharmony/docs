# NfcTypes.idl


## 概述

NFC事件（包括打开NFC完成、关闭NFC完成、预配置NFC完成等上报事件）的枚举定义。

模块包路径：ohos.hdi.nfc.v1_1

**起始版本：** 4.1

**相关模块：**[HdiNfc](_hdi_nfc_v11.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[NfcVendorConfig](_nfc_vendor_config_v11.md) | 厂家自定义的NFC配置。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [VendorProtocalDiscoveryCfg](_hdi_nfc_v11.md#vendorprotocaldiscoverycfg) {<br/>NCI_PROTOCOL_18092_ACTIVE = 0 , NCI_PROTOCOL_B_PRIME = 1 , NCI_PROTOCOL_DUAL = 2 , NCI_PROTOCOL_15693 = 3 , NCI_PROTOCOL_KOVIO = 4 , NCI_PROTOCOL_MIFARE = 5 , NCI_DISCOVERY_TYPE_POLL_KOVIO = 6 , NCI_DISCOVERY_TYPE_POLL_B_PRIME = 7 , NCI_DISCOVERY_TYPE_LISTEN_B_PRIME = 8 , VENDOR_PROPEIETARY_CFG_MAX = 9<br/>} | RF discover过程中厂家自定义支持的NFC协议类型。 | 
