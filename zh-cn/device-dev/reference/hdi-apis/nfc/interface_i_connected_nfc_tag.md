# IConnectedNfcTag


## 概述

声明ConnectedNfcTag模块提供的API，这些API包含初始化或者去初始化ConnectedNfcTag驱动，往nfc卡中读写Ndef内容。

**起始版本：** 3.2

**相关模块：**[HdiConnectedNfcTag](_hdi_connected_nfc_tag.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [Init](#init) () | 初始化ConnecteNfcTag驱动。 | 
| [Uninit](#uninit) () | 去初始化ConnecteNfcTag驱动。 | 
| [ReadNdefTag](#readndeftag) ([out] String ndefData) | 从连接的NFC卡中读取NDEF内容。 | 
| [WriteNdefTag](#writendeftag) ([in] String ndefData) | 往已连接的NFC卡中写入NDEF数据。 | 


## 成员函数说明


### Init()

```
IConnectedNfcTag::Init ()
```

**描述**


初始化ConnecteNfcTag驱动。

**起始版本：** 3.2

**返回：**

初始化成功返回0，否则返回初始化失败原因。


### ReadNdefTag()

```
IConnectedNfcTag::ReadNdefTag ([out] String ndefData)
```

**描述**


从连接的NFC卡中读取NDEF内容。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ndefData | 返回NDEF内容字符串。 | 


### Uninit()

```
IConnectedNfcTag::Uninit ()
```

**描述**


去初始化ConnecteNfcTag驱动。

**起始版本：** 3.2

**返回：**

去初始化成功返回0，否则返回去初始化失败原因。


### WriteNdefTag()

```
IConnectedNfcTag::WriteNdefTag ([in] String ndefData)
```

**描述**


往已连接的NFC卡中写入NDEF数据。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ndefData | 待写入的NDEF数据字符串。 | 

**返回：**

写入成功返回0,否则返回写失败原因。
