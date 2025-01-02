# IHciCallback

## 概述

定义HCI回调函数，包含初始化结果和从控制器接收的数据。

**起始版本：** 3.2

**相关模块：**[HdiHci](_hdi_hci.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnInited](#oninited) ([in] enum BtStatus status) | HCI 初始化回调函数。 | 
| [OnReceivedHciPacket](#onreceivedhcipacket) ([in] enum BtType type, [in] unsigned char[] data) | 接收控制器发送的数据包。 | 


## 成员函数说明


### OnInited()

```
IHciCallback::OnInited ([in] enum BtStatus status)
```

**描述**

HCI 初始化回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 声明HCI初始化结果。相关详细信息，请参考[BtType](_hdi_hci.md#bttype)。 | 

**返回：**

如果操作成功返回0；否则返回负值。


### OnReceivedHciPacket()

```
IHciCallback::OnReceivedHciPacket ([in] enum BtType type, [in] unsigned char[] data )
```

**描述**

接收控制器发送的数据包。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 声明HCI数据包类型。相关详细信息，请参考[BtType](_hdi_hci.md#bttype)。| 
| data | 表示从控制器接收的HCI数据包。 | 

**返回：**

如果操作成功返回0；否则返回负值。