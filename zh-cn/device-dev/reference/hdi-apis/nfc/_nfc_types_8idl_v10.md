# NfcTypes.idl


## 概述

声明类型定义，包括开关NFC、初始化NFC、读写数据、配置RF参数等

模块包路径：ohos.hdi.nfc.v1_0

**起始版本：** 3.2

**相关模块：**[HdiNfc](_hdi_nfc_v10.md)


## 汇总


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [NfcEvent](_hdi_nfc_v10.md#nfcevent) {<br/>OPEN_CPLT = 0 , CLOSE_CPLT = 1 , POST_INIT_CPLT = 2 , PRE_DISCOVER_CPLT = 3 , REQUEST_CONTROL = 4 , RELEASE_CONTROL = 5 , ERROR = 6 , HCI_NETWORK_RESET = 7<br/>} | NFC事件（包括打开NFC完成、关闭NFC完成、预配置NFC完成等上报事件）的枚举定义。 | 
| [NfcStatus](_hdi_nfc_v10.md#nfcstatus) {<br/>OK = 0 , FAILED = 1 , ERR_TRANSPORT = 2 , ERR_CMD_TIMEOUT = 3 , REFUSED = 4<br/>} | NFC状态的枚举定义。 | 
| [NfcCommand](_hdi_nfc_v10.md#nfccommand) { CMD_INVALID = 0 } | NFC指令的枚举定义。 | 
