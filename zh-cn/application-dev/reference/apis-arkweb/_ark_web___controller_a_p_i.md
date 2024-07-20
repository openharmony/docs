# ArkWeb_ControllerAPI


## 概述

Controller相关的Native API结构体。

**起始版本：** 12

**相关模块：**[Web](_web.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| size_t [size](#size) | 结构体的大小。  | 
| void(\* [runJavaScript](#runjavascript) )(const char \*webTag, const [ArkWeb_JavaScriptObject](_ark_web___java_script_object.md) \*javascriptObject) | 注入JavaScript脚本。  | 
| void(\* [registerJavaScriptProxy](#registerjavascriptproxy) )(const char \*webTag, const [ArkWeb_ProxyObject](_ark_web___proxy_object.md) \*proxyObject) | 注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。  | 
| void(\* [deleteJavaScriptRegister](#deletejavascriptregister) )(const char \*webTag, const char \*objName) | 删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。  | 
| void(\* [refresh](#refresh) )(const char \*webTag) | 刷新当前网页。  | 
| void(\* [registerAsyncJavaScriptProxy](#registerasyncjavascriptproxy) )(const char \*webTag, const [ArkWeb_ProxyObject](_ark_web___proxy_object.md) \*proxyObject) | 注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。  | 


## 结构体成员变量说明


### deleteJavaScriptRegister

```
void(* ArkWeb_ControllerAPI::deleteJavaScriptRegister) (const char *webTag, const char *objName)
```
**描述：**

删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。


### refresh

```
void(* ArkWeb_ControllerAPI::refresh) (const char *webTag)
```
**描述：**

刷新当前网页。


### registerAsyncJavaScriptProxy

```
void(* ArkWeb_ControllerAPI::registerAsyncJavaScriptProxy) (const char *webTag, const ArkWeb_ProxyObject *proxyObject)
```
**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的异步方法。


### registerJavaScriptProxy

```
void(* ArkWeb_ControllerAPI::registerJavaScriptProxy) (const char *webTag, const ArkWeb_ProxyObject *proxyObject)
```
**描述：**

注入JavaScript对象到window对象中，并在window对象中调用该对象的同步方法。


### runJavaScript

```
void(* ArkWeb_ControllerAPI::runJavaScript) (const char *webTag, const ArkWeb_JavaScriptObject *javascriptObject)
```
**描述：**

注入JavaScript脚本。


### size

```
size_t ArkWeb_ControllerAPI::size
```
**描述：**

结构体的大小。
