# ArkWeb_ComponentAPI
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## Overview

Defines a native component API.

**Since**: 12

**Related module**: [Web](capi-web.md)

**Header file**: [arkweb_type.h](capi-arkweb-type-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| size_t size | Size of the struct.|


### Member Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [void (\*onControllerAttached)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)](#oncontrollerattached) | Triggered when a controller is attached to the **Web** component.                 |
| [void (\*onPageBegin)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)](#onpagebegin) | Triggered when the web page starts to be loaded. This callback is called only for the main frame content, and not for the iframe or frameset content.|
| [void (\*onPageEnd)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)](#onpageend) | Triggered when the web page loading is finished. This callback is called only for the main frame content, and not for the iframe or frameset content.  |
| [void (\*onDestroy)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)](#ondestroy) | Triggered when this **Web** component is destroyed.                               |

## Member Function Description

### onControllerAttached()

```
void (*onControllerAttached)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**Description**

Triggered when a controller is attached to the **Web** component.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| ArkWeb_OnComponentCallback callback | Callback of **onControllerAttached**.|
|  void* userData | User-defined data.|

### onPageBegin()

```
void (*onPageBegin)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**Description**

Triggered when the web page starts to be loaded. This callback is called only for the main frame content, and not for the iframe or frameset content.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| ArkWeb_OnComponentCallback callback | Callback of **onPageBegin**.|
|  void* userData | User-defined data.|

### onPageEnd()

```
void (*onPageEnd)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**Description**

Triggered when the web page loading is finished. This callback is called only for the main frame content, and not for the iframe or frameset content.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| ArkWeb_OnComponentCallback callback | Callback of **onPageEnd**.|
|  void* userData | User-defined data.|

### onDestroy()

```
void (*onDestroy)(const char* webTag, ArkWeb_OnComponentCallback callback, void* userData)
```

**Description**

Triggered when this **Web** component is destroyed.

**Parameters**

| Name| Description|
| -- | -- |
| const char* webTag | Name of the **Web** component.|
| ArkWeb_OnComponentCallback callback | Callback of **onDestroy**.|
|  void* userData | User-defined data.|
