# ArkWeb_ComponentAPI
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @kurli1-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct {...} ArkWeb_ComponentAPI
```

## 概述

ArkWeb_ComponentAPI是ArkWeb在Native侧提供的用于监听Web组件生命周期事件的API结构体，继承自基础Native API类型[ArkWeb_AnyNativeAPI](capi-web-arkweb-anynativeapi.md)。开发者通过[OH_ArkWeb_GetNativeAPI](capi-arkweb-interface-h.md#oh_arkweb_getnativeapi)并指定`ARKWEB_NATIVE_COMPONENT`类型获取该结构体，进而注册Web组件的Controller绑定、页面开始加载、页面加载完成以及组件销毁等事件回调。该结构体适用于需要在Native代码（C/C++）中感知Web组件关键状态变化的场景，例如初始化Native资源、同步页面加载状态、统计埋点或在组件销毁时释放关联资源；相关接口需在UI线程中调用，并建议在调用具体成员函数前通过[ARKWEB_MEMBER_MISSING](capi-arkweb-type-h.md#宏定义)宏校验函数指针是否存在。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| size_t size | 结构体的大小。 |


### 成员函数

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [void (\*onControllerAttached)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)](#oncontrollerattached) | 当Controller成功绑定到Web组件时触发该回调。                  |
| [void (\*onPageBegin)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)](#onpagebegin) | 网页开始加载时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。 |
| [void (\*onPageEnd)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)](#onpageend) | 网页加载完成时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。   |
| [void (\*onDestroy)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)](#ondestroy) | 当前Web组件销毁时触发该回调。                                |

## 成员函数说明

### onControllerAttached()

```c
void (*onControllerAttached)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**描述：**

当Controller成功绑定到Web组件时触发该回调。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
| ArkWeb_OnComponentCallback callback | onControllerAttached的回调函数。 |
|  void* userData | 用户自定义数据。 |

### onPageBegin()

```c
void (*onPageBegin)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**描述：**

注册网页开始加载事件的回调监听器，该回调只在主frame触发，不会为iframe或frameset内容加载触发。该回调需在UI线程中调用，调用前建议通过ARKWEB_MEMBER_MISSING宏校验函数指针是否存在。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
| ArkWeb_OnComponentCallback callback | 网页开始加载时触发的回调函数，用于处理页面加载开始时的业务逻辑。 |
| void* userData | 用户自定义数据指针，该数据会在回调触发时传递给回调函数，可用于保存上下文信息或状态数据。 |

### onPageEnd()

```c
void (*onPageEnd)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**描述：**

注册网页加载完成事件的回调监听器，该回调只在主frame触发，不会为iframe或frameset内容加载触发。该回调需在UI线程中调用，调用前建议通过ARKWEB_MEMBER_MISSING宏校验函数指针是否存在。

**参数：**

| 参数项 | 描述 |
|--| -- |
| const char* webTag | Web组件名称。 |
| [ArkWeb_OnComponentCallback](./capi-arkweb-type-h.md#arkweb_oncomponentcallback) callback | 网页加载完成时触发的回调函数，用于处理页面加载完成后的业务逻辑。 |
| void* userData | 用户自定义数据指针，该数据会在回调触发时传递给回调函数，可用于保存上下文信息或状态数据。 |

### onDestroy()

```c
void (*onDestroy)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**描述：**

当前Web组件销毁时触发该回调。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
| ArkWeb_OnComponentCallback callback | onDestroy的回调函数。 |
| void* userData | 用户自定义数据。 |

