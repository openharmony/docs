# ArkWeb_JavaScriptObject
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

## 概述

注入的JavaScript结构体。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称                                                                                        | 描述 |
|-------------------------------------------------------------------------------------------| -- |
| const uint8_t* buffer                                                                     | 注入的JavaScript代码。 |
| size_t size                                                                               | JavaScript代码长度。 |
| [ArkWeb_OnJavaScriptCallback](capi-arkweb-type-h.md#arkweb_onjavascriptcallback) callback | JavaScript执行完成的回调。 |
| void* userData                                                                            | 需要在回调中携带的自定义数据。 |

