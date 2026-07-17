# ArkWeb_RequestHeaderList_
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct ArkWeb_RequestHeaderList_ ArkWeb_RequestHeaderList
```

## 概述

ArkWeb_RequestHeaderList是HTTP请求头列表结构体，用于在ArkWeb NDK中表示和管理HTTP请求头的键值对集合。该结构体包含请求头数组（headers）和数组长度（headerCount），headers为ArkWeb_RequestHeader指针数组，headerCount表示数组元素个数。该结构体配合ArkWeb_ResourceRequest等结构体使用，提供对Web组件网络请求头的读取和设置能力。使用场景：在自定义协议处理器中处理HTTP请求头、在网络请求拦截器中修改请求头、在API鉴权场景中添加认证头、在缓存控制和内容协商等场景中配置请求头。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_scheme_handler.h](capi-arkweb-scheme-handler-h.md)

