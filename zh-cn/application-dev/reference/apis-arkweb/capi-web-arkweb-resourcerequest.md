# ArkWeb_ResourceRequest_
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct ArkWeb_ResourceRequest_ ArkWeb_ResourceRequest
```

## 概述

ArkWeb_ResourceRequest是被拦截的Scheme请求的详细信息结构体，包含请求的URL、HTTP方法、请求头等元数据。该结构体在ArkWeb_SchemeHandler的onRequestStart回调中作为参数传入，适用于自定义协议处理、资源拦截等场景，帮助开发者实现跨域请求控制、本地资源映射等功能，从而增强安全性和性能。开发者通过它获取被拦截请求的完整信息，据此决定是否拦截以及如何构建自定义响应。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_scheme_handler.h](capi-arkweb-scheme-handler-h.md)
