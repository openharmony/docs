# ArkWeb_ComponentAPI
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

## 概述

Component相关的Native API结构体。

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

```
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

```
void (*onPageBegin)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**描述：**

网页开始加载时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
| ArkWeb_OnComponentCallback callback | onPageBegin的回调函数。 |
|  void* userData | 用户自定义数据。 |

### onPageEnd()

```
void (*onPageEnd)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**描述：**

网页加载完成时触发该回调，且只在主frame触发，iframe或者frameset的内容加载时不会触发此回调。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
| ArkWeb_OnComponentCallback callback | onPageEnd的回调函数。 |
|  void* userData | 用户自定义数据。 |

### onDestroy()

```
void (*onDestroy)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**描述：**

当前Web组件销毁时触发该回调。

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* webTag | Web组件名称。 |
| ArkWeb_OnComponentCallback callback | onDestroy的回调函数。 |
|  void* userData | 用户自定义数据。 |

