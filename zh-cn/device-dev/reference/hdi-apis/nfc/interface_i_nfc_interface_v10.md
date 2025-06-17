# INfcInterface


## 概述

声明操作Nfc芯片的API，包括关闭、打开Nfc，初始化Nfc，读写数据、配置RF参数、发送nci指令。

**起始版本：** 3.2

**相关模块：**[HdiNfc](_hdi_nfc_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [Open](#open) ([in] [INfcCallback](interface_i_nfc_callback_v10.md) callbackObj, [out] enum [NfcStatus](_hdi_nfc_v10.md#nfcstatus) status) | 打开Nfc，对Nfc初始化。 | 
| [CoreInitialized](#coreinitialized) ([in] List&lt; unsigned char &gt; data, [out] enum [NfcStatus](_hdi_nfc_v10.md#nfcstatus) status) | Nfc初始化。 | 
| [Prediscover](#prediscover) ([out] enum [NfcStatus](_hdi_nfc_v10.md#nfcstatus) status) | 启动RF discover之前对芯片进行预配置。 | 
| [Write](#write) ([in] List&lt; unsigned char &gt; data, [out] enum [NfcStatus](_hdi_nfc_v10.md#nfcstatus) status) | 发送数据给Nfc控制器。 | 
| [ControlGranted](#controlgranted) ([out] enum [NfcStatus](_hdi_nfc_v10.md#nfcstatus) status) | 允许HDF层发送NCI指令。 | 
| [PowerCycle](#powercycle) ([out] enum [NfcStatus](_hdi_nfc_v10.md#nfcstatus) status) | 周期性重启Nfc。 | 
| [Close](#close) ([out] enum [NfcStatus](_hdi_nfc_v10.md#nfcstatus) status) | 关闭Nfc。 | 
| [Ioctl](#ioctl) ([in] enum [NfcCommand](_hdi_nfc_v10.md#nfccommand) cmd, [in] List&lt; unsigned char &gt; data, [out] enum [NfcStatus](_hdi_nfc_v10.md#nfcstatus) status) | Nfc协议栈通过IO控制指令和数据发送给HDI。 | 


## 成员函数说明


### Close()

```
INfcInterface::Close ([out] enum NfcStatus status)
```

**描述**


关闭Nfc。

**起始版本：** 3.2

**返回：**

配置成功返回0，否则返回失败原因。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。


### ControlGranted()

```
INfcInterface::ControlGranted ([out] enum NfcStatus status)
```

**描述**


允许HDF层发送NCI指令。

**起始版本：** 3.2

**返回：**

配置成功返回0，否则返回失败原因。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。


### CoreInitialized()

```
INfcInterface::CoreInitialized ([in] List< unsigned char > data, [out] enum NfcStatus status)
```

**描述**


Nfc初始化。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | Nfc芯片发送给Nfc协议栈的数据和事件的回调对象。 | 

**返回：**

操作成功返回0，否则返回失败。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。


### Ioctl()

```
INfcInterface::Ioctl ([in] enum NfcCommand cmd, [in] List< unsigned char > data, [out] enum NfcStatus status)
```

**描述**


Nfc协议栈通过IO控制指令和数据发送给HDI。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cmd | NfcCommand中定义在控制指令，详见[NfcTypes](_nfc_types_8idl_v10.md)。 | 
| data | 发送给HDI的数据。 | 

**返回：**

配置成功返回0，否则返回失败原因。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。


### Open()

```
INfcInterface::Open ([in] INfcCallback callbackObj, [out] enum NfcStatus status)
```

**描述**


打开Nfc，对Nfc初始化。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | Nfc芯片发送给Nfc协议栈的数据和事件的回调对象 | 

**返回：**

操作成功返回0，否则返回失败。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。


### PowerCycle()

```
INfcInterface::PowerCycle ([out] enum NfcStatus status)
```

**描述**


周期性重启Nfc。

**起始版本：** 3.2

**返回：**

配置成功返回0，否则返回失败原因。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。


### Prediscover()

```
INfcInterface::Prediscover ([out] enum NfcStatus status)
```

**描述**


启动RF discover之前对芯片进行预配置。

**起始版本：** 3.2

**返回：**

配置成功返回0，否则返回失败原因。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。


### Write()

```
INfcInterface::Write ([in] List< unsigned char > data, [out] enum NfcStatus status)
```

**描述**


发送数据给Nfc控制器。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 待写入Nfc控制器的数据。 | 

**返回：**

配置成功返回0，否则返回失败原因。 具体类型详见[NfcTypes](_nfc_types_8idl_v10.md)。
