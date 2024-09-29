# ArkWeb_WebMessagePortAPI


## 概述

Post Message相关的Native API结构体。 在调用API前建议通过ARKWEB_MEMBER_MISSING校验该函数结构体是否有对应函数指针，避免SDK与设备ROM不匹配导致crash问题。

**起始版本：** 12

**相关模块：**[Web](_web.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| size_t [size](#size) | 结构体的大小。  | 
| [ArkWeb_ErrorCode](_web.md#arkweb_errorcode)(\* [postMessage](#postmessage) )(const [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) webMessagePort, const char \*webTag, const [ArkWeb_WebMessagePtr](_web.md#arkweb_webmessageptr) webMessage) | 发送消息到HTML。  | 
| void(\* [close](#close) )(const [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) webMessagePort, const char \*webTag) | 关闭消息端口。  | 
| void(\* [setMessageEventHandler](#setmessageeventhandler) )(const [ArkWeb_WebMessagePortPtr](_web.md#arkweb_webmessageportptr) webMessagePort, const char \*webTag, [ArkWeb_OnMessageEventHandler](_web.md#arkweb_onmessageeventhandler) messageEventHandler, void \*userData) | 设置接收HTML消息的回调。  | 


## 结构体成员变量说明


### close

```
void(* ArkWeb_WebMessagePortAPI::close) (const ArkWeb_WebMessagePortPtr webMessagePort, const char *webTag)
```
**描述：**

关闭消息端口。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webMessagePort | Post Message端口结构体指针。  | 
| webTag | Web组件名字。  | 


### postMessage

```
ArkWeb_ErrorCode(* ArkWeb_WebMessagePortAPI::postMessage) (const ArkWeb_WebMessagePortPtr webMessagePort, const char *webTag, const ArkWeb_WebMessagePtr webMessage)
```
**描述：**

发送消息到HTML。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webMessagePort | Post Message端口结构体指针。  | 
| webTag | Web组件名字。  | 
| webMessage | 需要发送的消息。  | 

**返回：**

返回值错误码。 [ARKWEB_SUCCESS](_web.md) 执行成功。 [ARKWEB_INVALID_PARAM](_web.md) 参数无效。 [ARKWEB_INIT_ERROR](_web.md) 初始化失败，没有找到与webTag绑定的Web组件。


### setMessageEventHandler

```
void(* ArkWeb_WebMessagePortAPI::setMessageEventHandler) (const ArkWeb_WebMessagePortPtr webMessagePort, const char *webTag, ArkWeb_OnMessageEventHandler messageEventHandler, void *userData)
```
**描述：**

设置接收HTML消息的回调。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| webMessagePort | Post Message端口结构体指针。  | 
| webTag | Web组件名字。  | 
| messageEventHandler | 处理消息的回调。  | 
| userData | 用户自定义数据。  | 


### size

```
size_t ArkWeb_WebMessagePortAPI::size
```
**描述：**

结构体的大小。
