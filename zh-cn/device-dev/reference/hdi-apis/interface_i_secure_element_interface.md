# ISecureElementInterface


## 概述

声明由SecureElement模块提供的用于获取SecureElement操作的API， 请参阅“Open Mobile API 规范”。

**起始版本：** 4.0

**相关模块：**[HdiSecureElement](_hdi_secure_element.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [init](#init) ([in] [ISecureElementCallback](interface_i_secure_element_callback.md) clientCallback, [out] enum [SecureElementStatus](_hdi_secure_element.md#secureelementstatus) status) | 初始化安全单元。 | 
| [getAtr](#getatr) ([out] List&lt; unsigned char &gt; response) | 获取此SE的ATR。 | 
| [isSecureElementPresent](#issecureelementpresent) ([out] boolean present) | 检查当前的安全单元是否可用。 | 
| [openLogicalChannel](#openlogicalchannel) ([in] List&lt; unsigned char &gt; aid, [in] unsigned char p2, [out] List&lt; unsigned char &gt; response, [out] unsigned char channelNumber, [out] enum [SecureElementStatus](_hdi_secure_element.md#secureelementstatus) status) | 使用SE打开一个逻辑通道，选择由给定AID代表的应用（当AID不为Null且AID的长度不为0时）。 | 
| [openBasicChannel](#openbasicchannel) ([in] List&lt; unsigned char &gt; aid, [in] unsigned char p2, [out] List&lt; unsigned char &gt; response, [out] enum [SecureElementStatus](_hdi_secure_element.md#secureelementstatus) status) | 访问[ISO 7816-4]中定义的基本通道（编号为0的通道）。所获得的对象是Channel类的一个实例。 | 
| [closeChannel](#closechannel) ([in] unsigned char channelNumber, [out] enum [SecureElementStatus](_hdi_secure_element.md#secureelementstatus) status) | 关闭此SE的逻辑通道。关闭基本通道必须返回SecureElementStatus:：FAILED。 | 
| [transmit](#transmit) ([in] List&lt; unsigned char &gt; command, [out] List&lt; unsigned char &gt; response, [out] enum [SecureElementStatus](_hdi_secure_element.md#secureelementstatus) status) | 向SE发送APDU指令（根据协议ISO/IEC 7816）。 | 
| [reset](#reset) ([out] enum [SecureElementStatus](_hdi_secure_element.md#secureelementstatus) status) | 向SE发送APDU指令（根据协议ISO/IEC 7816）。 | 


## 成员函数说明


### closeChannel()

```
ISecureElementInterface::closeChannel ([in] unsigned char channelNumber, [out] enum SecureElementStatus status )
```

**描述**

关闭此SE的逻辑通道。关闭基本通道必须返回SecureElementStatus:：FAILED。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| channelNumber | 要关闭的逻辑通道编号。 | 
| status | 需要关闭的逻辑通道的状态。 | 


### getAtr()

```
ISecureElementInterface::getAtr ([out] List< unsigned char > response)
```

**描述**

获取此SE的ATR。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| response | 返回SE的ATR，SE的ATR不可用时，返回空的数组。 | 


### init()

```
ISecureElementInterface::init ([in] ISecureElementCallback clientCallback, [out] enum SecureElementStatus status )
```

**描述**

初始化安全单元。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callback | 用于通知SE状态更改的回调。 | 
| status | 初始化SE的状态。 | 


### isSecureElementPresent()

```
ISecureElementInterface::isSecureElementPresent ([out] boolean present)
```

**描述**

检查当前的安全单元是否可用。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| present | 如果安全单元可用，则present等于True，否则为false。 | 


### openBasicChannel()

```
ISecureElementInterface::openBasicChannel ([in] List< unsigned char > aid, [in] unsigned char p2, [out] List< unsigned char > response, [out] enum SecureElementStatus status )
```

**描述**

访问[ISO 7816-4]中定义的基本通道（编号为0的通道）。所获得的对象是Channel类的一个实例。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| aid | 要在此通道上选择的应用的AID的byte数组。 | 
| p2 | 在该通道上执行的SELECT APDU。 | 
| response | SELECT指令的响应，如果失败则为空。 | 
| status | 打开基本通道的状态。 | 


### openLogicalChannel()

```
ISecureElementInterface::openLogicalChannel ([in] List< unsigned char > aid, [in] unsigned char p2, [out] List< unsigned char > response, [out] unsigned char channelNumber, [out] enum SecureElementStatus status )
```

**描述**

使用SE打开一个逻辑通道，选择由给定AID代表的应用（当AID不为Null且AID的长度不为0时）。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| aid | 要在此通道上选择的应用的AID的byte数组。 | 
| p2 | 在该通道上执行的SELECT APDU。 | 
| response | 对SELECT指令的响应，如果失败则为空。 | 
| channelNumber | 新逻辑通道的通道编号。 | 
| status | 打开逻辑通道的状态。 | 


### reset()

```
ISecureElementInterface::reset ([out] enum SecureElementStatus status)
```

**描述**

向SE发送APDU指令（根据协议ISO/IEC 7816）。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 重置安全单元的状态。 | 


### transmit()

```
ISecureElementInterface::transmit ([in] List< unsigned char > command, [out] List< unsigned char > response, [out] enum SecureElementStatus status )
```

**描述**

向SE发送APDU指令（根据协议ISO/IEC 7816）。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| command | 要发送的byte数组格式的APDU指令。 | 
| response | 以byte数组接收到的响应。 | 
| status | 传输指令的状态。 | 
