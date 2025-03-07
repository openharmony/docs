# HdiNfc (V1_1)


## 概述

为nfc服务提供统一的访问nfc驱动的接口。

NFC服务通过获取的nfc驱动对象提供的API接口访问nfc驱动，包括开关NFC、初始化NFC、读写数据、配置RF参数、 通过IO控制发送NCI指令给nfc驱动。

**起始版本：** 4.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [INfcInterface.idl](_i_nfc_interface_8idl_v11.md) | 定义NFC扩展的查询配置、工厂级复位的适配接口文件。 | 
| [NfcTypes.idl](_nfc_types_8idl_v11.md) | NFC事件（包括打开NFC完成、关闭NFC完成、预配置NFC完成等上报事件）的枚举定义。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[INfcInterface](interface_i_nfc_interface_v11.md) | 声明操作nfc芯片的API，包括关闭、打开nfc，初始化nfc，读写数据、配置RF参数、发送nci指令。 | 
| struct&nbsp;&nbsp;[NfcVendorConfig](_nfc_vendor_config_v11.md) | 厂家自定义的NFC配置。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [VendorProtocalDiscoveryCfg](#vendorprotocaldiscoverycfg) {<br/>NCI_PROTOCOL_18092_ACTIVE = 0 , NCI_PROTOCOL_B_PRIME = 1 , NCI_PROTOCOL_DUAL = 2 , NCI_PROTOCOL_15693 = 3 , NCI_PROTOCOL_KOVIO = 4 , NCI_PROTOCOL_MIFARE = 5 , NCI_DISCOVERY_TYPE_POLL_KOVIO = 6 , NCI_DISCOVERY_TYPE_POLL_B_PRIME = 7 , NCI_DISCOVERY_TYPE_LISTEN_B_PRIME = 8 , VENDOR_PROPEIETARY_CFG_MAX = 9<br/>} | RF discover过程中厂家自定义支持的NFC协议类型。 | 


## 枚举类型说明


### VendorProtocalDiscoveryCfg

```
enum VendorProtocalDiscoveryCfg
```

**描述**


RF discover过程中厂家自定义支持的NFC协议类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| NCI_PROTOCOL_18092_ACTIVE | 遵循ISO18092协议的Felica | 
| NCI_PROTOCOL_B_PRIME | 遵循typeB类型的ISO-DEP | 
| NCI_PROTOCOL_DUAL | 厂商自定义的私有协议 | 
| NCI_PROTOCOL_15693 | 遵循ISO15693协议 | 
| NCI_PROTOCOL_KOVIO | Kovio公司的NFC条形码 | 
| NCI_PROTOCOL_MIFARE | 厂商定义的Mifare协议 | 
| NCI_DISCOVERY_TYPE_POLL_KOVIO | Kovio的polling | 
| NCI_DISCOVERY_TYPE_POLL_B_PRIME | typeB的polling | 
| NCI_DISCOVERY_TYPE_LISTEN_B_PRIME | typeB的卡模拟 | 
| VENDOR_PROPEIETARY_CFG_MAX | 自定义最大配置个数 | 
