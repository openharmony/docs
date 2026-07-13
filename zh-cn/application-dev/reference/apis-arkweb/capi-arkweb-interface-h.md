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

注册组件滚动时的回调函数。用于监听页面滚动事件，常见场景包括吸顶导航切换、虚拟列表渲染优化和滚动埋点上报等。

**系统能力：** SystemCapability.Web.Webview.Core

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件的名称，需与ArkTS侧Web组件的id属性保持一致，用于标识特定的Web组件实例。需先在ArkTS侧创建Web组件并设置对应的tag名称。 |
| [ArkWeb_OnScrollCallback](capi-arkweb-type-h.md#arkweb_onscrollcallback) callback | 页面滚动时的回调函数。由于滚动事件触发频率较高，建议在回调函数中避免执行耗时操作，并可考虑实现防抖或节流机制以提升性能。 |
| void* userData | 用户自定义的数据指针，在回调函数触发时会原样传回给回调函数，用于在Native侧保存和传递上下文信息。可以为NULL，如果不传递自定义数据则设置为NULL。该数据的生命周期应与回调注册周期保持一致，由调用方负责内存管理，确保数据在回调执行期间始终有效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 如果回调设置成功，则返回true，否则返回false。 |


