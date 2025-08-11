# Web
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui; @zourongchun-->
<!--SE: @yaomingliu; @zhufenghao-->
<!--TSE: @ghiker-->

## 概述

为ArkWeb NDK接口发生异常提供错误码。

提供注入对象和执行JavaScript代码的API接口。

提供用于拦截ArkWeb请求的API。

为ArkWeb网络协议栈提供错误码。

提供ArkWeb在Native侧的能力，如网页刷新、执行JavaScript、注册回调等。

更多详细介绍请参考[应用侧与前端页面的相互调用(C/C++)](../../web/arkweb-ndk-jsbridge.md)、[建立应用侧与前端页面数据通道(C/C++)](../../web/arkweb-ndk-page-data-channel.md)和[拦截Web组件发起的网络请求](../../web/web-scheme-handler.md)。

**起始版本：** 12
## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [arkweb_error_code.h](capi-arkweb-error-code-h.md) | 声明ArkWeb NDK接口异常错误码。 |
| [arkweb_interface.h](capi-arkweb-interface-h.md) | 提供ArkWeb在Native侧获取API的接口，及基础Native API类型。 |
| [arkweb_net_error_list.h](capi-arkweb-net-error-list-h.md) | 声明ArkWeb网络协议栈错误码。 |
| [arkweb_scheme_handler.h](capi-arkweb-scheme-handler-h.md) | 声明用于拦截来自ArkWeb的请求的API。 |
| [arkweb_type.h](capi-arkweb-type-h.md) | 提供ArkWeb在Native侧的公共类型定义。 |
| [native_interface_arkweb.h](capi-native-interface-arkweb-h.md) | 声明API接口供开发者使用注入对象和执行JavaScript代码等功能。 |
