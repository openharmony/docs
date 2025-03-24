# INfcCallback


## 概述

用于从nfc芯片给nfc协议栈上报数据和事件的回调声明。

**起始版本：** 3.2

**相关模块：**[HdiNfc](_hdi_nfc_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnData](#ondata) ([in] List&lt; unsigned char &gt; data) | NFC芯片上报给协议栈NFC数据的函数定义。  | 
| [OnEvent](#onevent) ([in] enum [NfcEvent](_hdi_nfc_v10.md#nfcevent) event, [in] enum [NfcStatus](_hdi_nfc_v10.md#nfcstatus) status) | NFC芯片上报给协议栈事件的函数定义。  | 


## 成员函数说明


### OnData()

```
INfcCallback::OnData ([in] List< unsigned char > data)
```
**描述**

NFC芯片上报给协议栈NFC数据的函数定义。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | NFC芯片上报给NFC协议栈的数据。 | 


### OnEvent()

```
INfcCallback::OnEvent ([in] enum NfcEvent event, [in] enum NfcStatus status )
```
**描述**

NFC芯片上报给协议栈事件的函数定义。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 上报事件的事件ID。  | 
| status | NFC状态，具体定义见NfcStatus。 事件ID具体见 [**NfcTypes**](_nfc_types_8idl_v10.md)。| 
