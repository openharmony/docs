# IWlanInterface


## 概述

定义上层WLAN服务的扩展接口。

**起始版本：** 4.1

**相关模块：**[WLAN](_w_l_a_n_v12.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetApBandwidth](#getapbandwidth) ([in] String ifName, [out] unsigned char bandwidth) | 获取AP当前带宽 | 
| [ResetToFactoryMacAddress](#resettofactorymacaddress) ([in] String ifName) | 重置为出厂MAC地址(永久硬件地址) | 
| [SendActionFrame](#sendactionframe) ([in] String ifName, [in] unsigned int freq, [in] unsigned char[] frameData) | 向驱动程序发送动作帧 | 
| [RegisterActionFrameReceiver](#registeractionframereceiver) ([in] String ifName, [in] unsigned char[] match) | 寄存器动作帧接收机 | 
| [SetPowerSaveMode](#setpowersavemode) ([in] String ifName, [in] int frequency, [in] int mode) | 设置节能管理器模式 | 
| [SetDpiMarkRule](#setdpimarkrule) ([in] int uid, [in] int protocol, [in] int enable) | 设置数据包标识标记规则 | 


## 成员函数说明


### GetApBandwidth()

```
IWlanInterface::GetApBandwidth ([in] String ifName, [out] unsigned char bandwidth )
```

**描述**


获取AP当前带宽

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称 | 
| bandwidth | AP带宽： 1(20M), 2(40M), 4(80M), 8(160M) | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### RegisterActionFrameReceiver()

```
IWlanInterface::RegisterActionFrameReceiver ([in] String ifName, [in] unsigned char[] match )
```

**描述**


寄存器动作帧接收机

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称 | 
| txChannel | 表示数据匹配操作框架 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### ResetToFactoryMacAddress()

```
IWlanInterface::ResetToFactoryMacAddress ([in] String ifName)
```

**描述**


重置为出厂MAC地址(永久硬件地址)

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SendActionFrame()

```
IWlanInterface::SendActionFrame ([in] String ifName, [in] unsigned int freq, [in] unsigned char[] frameData )
```

**描述**


向驱动程序发送动作帧

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称 | 
| freq | 表示发送通道频率 | 
| ifName | 表示动作帧数据 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetDpiMarkRule()

```
IWlanInterface::SetDpiMarkRule ([in] int uid, [in] int protocol, [in] int enable )
```

**描述**


设置数据包标识标记规则

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| uid | 表示目标应用程序UID | 
| protocol | 表示目标协议类型，tcp/udp | 
| enable | 指示启用/禁用dpi标记规则 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetPowerSaveMode()

```
IWlanInterface::SetPowerSaveMode ([in] String ifName, [in] int frequency, [in] int mode )
```

**描述**


设置节能管理器模式

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡(NIC)名称 | 
| frequency | 表示连接的ap频率 | 
| mode | 表示省电模式：3（启用省电），4（禁用省电） | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。
