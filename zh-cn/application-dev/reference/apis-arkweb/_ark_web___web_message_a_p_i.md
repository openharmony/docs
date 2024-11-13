# ArkWeb_WebMessageAPI


## 概述

Post Message数据相关的Native API结构体。 在调用API前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。

**起始版本：** 12

**相关模块：**[Web](_web.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| size_t [size](#size) | 结构体的大小。  | 
| [ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr)(\* [createWebMessage](#createwebmessage) )() | 创建消息。  | 
| void(\* [destroyWebMessage](#destroywebmessage) )([ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) \*webMessage) | 销毁消息。  | 
| void(\* [setType](#settype) )([ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) webMessage, [ArkWeb_WebMessageType](_web.md#arkweb_webmessagetype) type) | 设置消息类型。  | 
| [ArkWeb_WebMessageType](_web.md#arkweb_webmessagetype)(\* [getType](#gettype) )([ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) webMessage) | 获取消息类型。  | 
| void(\* [setData](#setdata) )([ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) webMessage, void \*data, size_t dataLength) | 设置数据。  | 
| void \*(\* [getData](#getdata) )([ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) webMessage, size_t \*dataLength) | 获取数据。  | 


## 结构体成员变量说明


### createWebMessage

```
ArkWeb_WebMessagePtr(* ArkWeb_WebMessageAPI::createWebMessage) ()
```
**描述：**

创建消息。

**返回：**

消息结构体。


### destroyWebMessage

```
void(* ArkWeb_WebMessageAPI::destroyWebMessage) (ArkWeb_WebMessagePtr *webMessage)
```
**描述：**

销毁消息。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webMessage | 需要销毁的消息。  | 


### getData

```
void*(* ArkWeb_WebMessageAPI::getData) (ArkWeb_WebMessagePtr webMessage, size_t *dataLength)
```
**描述：**

获取数据。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webMessage | 消息结构体指针。  | 
| dataLength | 出参，数据长度。  | 

**返回：**

数据指针。


### getType

```
ArkWeb_WebMessageType(* ArkWeb_WebMessageAPI::getType) (ArkWeb_WebMessagePtr webMessage)
```
**描述：**

获取消息类型。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webMessage | 消息结构体指针。  | 

**返回：**

消息类型。


### setData

```
void(* ArkWeb_WebMessageAPI::setData) (ArkWeb_WebMessagePtr webMessage, void *data, size_t dataLength)
```
**描述：**

设置数据。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webMessage | 消息结构体指针。  | 
| data | 数据指针。  | 
| dataLength | 数据长度。  | 


### setType

```
void(* ArkWeb_WebMessageAPI::setType) (ArkWeb_WebMessagePtr webMessage, ArkWeb_WebMessageType type)
```
**描述：**

设置消息类型。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webMessage | 消息结构体指针。  | 
| type | 消息类型。  | 


### size

```
size_t ArkWeb_WebMessageAPI::size
```
**描述：**

结构体的大小。
