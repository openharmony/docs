# ArkWeb_ResourceHandler_
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct ArkWeb_ResourceHandler_ ArkWeb_ResourceHandler
```

## 概述

ArkWeb_ResourceHandler是用于处理被拦截的Scheme请求的资源处理器结构体。在ArkWeb_SchemeHandler拦截到指定scheme的请求后，通过该结构体可以向Web组件返回自定义的响应数据，包括响应状态码、响应头、响应体等。该结构体在onRequestStart回调中作为参数传入，开发者通过它实现对被拦截请求的完全自定义响应。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_scheme_handler.h](capi-arkweb-scheme-handler-h.md)

