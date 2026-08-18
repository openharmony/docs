# Web
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui; @zourongchun-->
<!--Designer: @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

## 概述

声明ArkWeb NDK接口异常错误码，适用于Native层异常诊断与错误处理，帮助开发者快速定位问题、提升调试效率。

提供注入对象和执行JavaScript代码的API接口，适用于应用与前端页面的双向交互场景，能够增强页面能力、提升用户体验与开发效率。

提供用于拦截ArkWeb请求的API，适用于自定义协议处理、网络请求监控与数据安全等场景，能够增强应用可控性与安全性。

声明ArkWeb网络协议栈错误码，适用于网络请求失败诊断与异常处理，帮助开发者快速排查网络故障、优化连接稳定性。

提供ArkWeb Native侧能力，如网页刷新、执行JavaScript、注册回调等，适用于需要从Native侧控制WebView行为并响应前端事件的场景，能够增强应用的灵活性和交互能力。

更多详细介绍请参考[应用侧与前端页面的相互调用(C/C++)](../../web/arkweb-ndk-jsbridge.md)、[建立应用侧与前端页面数据通道(C/C++)](../../web/arkweb-ndk-page-data-channel.md)和[拦截Web组件发起的网络请求](../../web/web-scheme-handler.md)，这些内容帮助开发者实现高效的双向通信与请求拦截，提升应用性能与可控性。

**起始版本：** 12
## 文件汇总

| 名称 | 描述 |
| -- | -- |
| [arkweb_error_code.h](capi-arkweb-error-code-h.md) | 声明ArkWeb NDK接口异常错误码。 |
| [arkweb_interface.h](capi-arkweb-interface-h.md) | 提供ArkWeb在Native侧获取API的接口，及基础Native API类型。 |
| [arkweb_net_error_list.h](capi-arkweb-net-error-list-h.md) | 声明ArkWeb网络协议栈错误码。 |
| [arkweb_scheme_handler.h](capi-arkweb-scheme-handler-h.md) | 声明拦截来自ArkWeb的请求的API。 |
| [arkweb_type.h](capi-arkweb-type-h.md) | 定义ArkWeb Native侧公共类型。 |
| [native_interface_arkweb.h](capi-native-interface-arkweb-h.md) | 声明API接口，用于注入对象和执行JavaScript等功能。 |
