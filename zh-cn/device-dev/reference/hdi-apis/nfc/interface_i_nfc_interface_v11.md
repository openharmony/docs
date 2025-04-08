# INfcInterface


## 概述

声明操作NFC芯片的API，包括关闭、打开NFC，初始化NFC，读写数据、配置RF参数、发送nci指令。

**起始版本：** 4.1

**相关模块：**[HdiNfc](_hdi_nfc_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetVendorConfig](#getvendorconfig) ([out] struct [NfcVendorConfig](_nfc_vendor_config_v11.md) config, [out] enum NfcStatus status) | 查询厂商自定义的NFC配置。 | 
| [DoFactoryReset](#dofactoryreset) ([out] enum NfcStatus status) | NFC芯片工厂级复位。 | 
| [Shutdown](#shutdown) ([out] enum NfcStatus status) | 关闭NFC。如果设备支持关机刷卡功能，需要实现该接口。 | 


## 成员函数说明


### DoFactoryReset()

```
INfcInterface::DoFactoryReset ([out] enum NfcStatus status)
```

**描述**


NFC芯片工厂级复位。

**起始版本：** 4.1

**返回：**

操作成功返回0，否则返回失败。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。


### GetVendorConfig()

```
INfcInterface::GetVendorConfig ([out] struct NfcVendorConfig config, [out] enum NfcStatus status )
```

**描述**


查询厂商自定义的NFC配置。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| config | 厂商自定义的NFC配置。 | 

**返回：**

操作成功返回0，否则返回失败。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。


### Shutdown()

```
INfcInterface::Shutdown ([out] enum NfcStatus status)
```

**描述**


关闭NFC。如果设备支持关机刷卡功能，需要实现该接口

**起始版本：** 4.1

**返回：**

操作成功返回0，否则返回失败。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。
