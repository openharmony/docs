# arkweb_interface.h
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui; @zourongchun-->
<!--Designer: @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

## 概述

`arkweb_interface.h`是ArkWeb在Native侧（C/C++）的核心入口头文件：它定义了基础Native API类型[ArkWeb_AnyNativeAPI](capi-web-arkweb-anynativeapi.md)与API类型枚举[ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind)，并提供[OH_ArkWeb_GetNativeAPI](#oh_arkweb_getnativeapi)接口用于按需获取Controller、Component、CookieManager等具体Native API结构体，同时提供[OH_ArkWeb_RegisterScrollCallback](#oh_arkweb_registerscrollcallback)用于注册Web组件滚动事件回调；当开发者需要在Native代码中控制Web组件行为（如执行JavaScript、管理Cookie、监听组件生命周期或滚动事件）时，应首先通过本头文件获取对应的Native API，而页面渲染显示等能力仍需由ArkTS侧的Web组件提供。

**引用文件：** <web/arkweb_interface.h>

**库：** libohweb.so

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkWeb_AnyNativeAPI](capi-web-arkweb-anynativeapi.md) | ArkWeb_AnyNativeAPI | 定义基础Native API类型。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind) | ArkWeb_NativeAPIVariantKind | 定义Native API的类型枚举。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [ArkWeb_AnyNativeAPI* OH_ArkWeb_GetNativeAPI(ArkWeb_NativeAPIVariantKind type)](#oh_arkweb_getnativeapi) | 根据传入的API类型，获取对应的Native API结构体。 |
| [bool OH_ArkWeb_RegisterScrollCallback(const char* webTag, ArkWeb_OnScrollCallback callback, void* userData)](#oh_arkweb_registerscrollcallback) | 注册组件滚动时的回调函数。 |

## 枚举类型说明

### ArkWeb_NativeAPIVariantKind

```c
enum ArkWeb_NativeAPIVariantKind
```

**描述：**

定义Native API的类型枚举。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKWEB_NATIVE_COMPONENT | component相关API类型。 |
| ARKWEB_NATIVE_CONTROLLER | controller相关API类型。 |
| ARKWEB_NATIVE_WEB_MESSAGE_PORT | webMessagePort相关API类型。 |
| ARKWEB_NATIVE_WEB_MESSAGE | webMessage相关API类型。 |
| ARKWEB_NATIVE_COOKIE_MANAGER | cookieManager相关API类型。 |
| ARKWEB_NATIVE_JAVASCRIPT_VALUE | JavaScriptValue相关API类型。<br>**起始版本：** 18 |


## 函数说明

### OH_ArkWeb_GetNativeAPI()

```c
ArkWeb_AnyNativeAPI* OH_ArkWeb_GetNativeAPI(ArkWeb_NativeAPIVariantKind type)
```

**描述：**

根据传入的API类型，获取对应的Native API结构体。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ArkWeb_NativeAPIVariantKind](#arkweb_nativeapivariantkind) type | ArkWeb支持的Native API类型。 |

**返回：**

| 类型                                           | 说明 |
|----------------------------------------------| -- |
| [ArkWeb_AnyNativeAPI](capi-web-arkweb-anynativeapi.md)* | 根据传入的API类型，返回对应的Native API结构体指针，结构体第一个成员为当前结构体的大小。 |

### OH_ArkWeb_RegisterScrollCallback()

```c
bool OH_ArkWeb_RegisterScrollCallback(const char* webTag, ArkWeb_OnScrollCallback callback, void* userData)
```

**描述：**

注册组件滚动时的回调函数。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的名称。 |
| [ArkWeb_OnScrollCallback](capi-arkweb-type-h.md#arkweb_onscrollcallback) callback | 页面滚动时的回调函数。 |
| void* userData | 用户自定义的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果回调设置成功，则返回true，否则返回false。 |


