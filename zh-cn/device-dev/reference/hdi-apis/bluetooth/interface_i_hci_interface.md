# IHciInterface

## 概述

声明接口以初始化HCI，向控制器发送数据及关闭HCI接口。

**起始版本：** 3.2

**相关模块：**[HdiHci](_hdi_hci.md)

## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [Init](#init) ([in] IHciCallback callbackObj) | 初始化HCI并注册回调函数。 | 
| [SendHciPacket](#sendhcipacket) ([in] enum BtType type, [in] unsigned char[] data) | 向控制器发送数据包。 | 
| [Close](#close) () | 关闭HCI接口。 | 


## 成员函数说明


### Close()

```
IHciInterface::Close ()
```

**描述**

关闭HCI接口。

**起始版本：** 3.2

**返回：**

如果操作成功返回0；否则返回负值。


### Init()

```
IHciInterface::Init ([in] IHciCallback callbackObj)
```

**描述**

初始化HCI并注册回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 声明回调函数。相关详细信息，请参考[IHciCallback](interface_i_hci_callback.md)。| 

**返回：**

如果操作成功返回0；否则返回负值。


### SendHciPacket()

```
IHciInterface::SendHciPacket ([in] enum BtType type, [in] unsigned char[] data )
```

**描述**

向控制器发送数据包。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| type | 声明HCI数据包类型。相关详细信息，请参考[BtType](_hdi_hci.md#bttype)。| 
| data | 表示发送到控制器的HCI数据包。 |

**返回：**

如果操作成功返回0；否则返回负值。