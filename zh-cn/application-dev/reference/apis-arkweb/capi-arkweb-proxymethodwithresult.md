# ArkWeb_ProxyMethodWithResult

## 概述

注入的Proxy方法通用结构体。

**起始版本：** 18

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称                                                                                                                      | 描述 |
|-------------------------------------------------------------------------------------------------------------------------| -- |
| const char* methodName                                                                                                  | 注入的方法名。 |
| [ArkWeb_OnJavaScriptProxyCallbackWithResult](capi-arkweb-type-h.md#arkweb_onjavascriptproxycallbackwithresult) callback | Proxy方法执行的回调。 |
| void* userData                                                                                                          | 需要在回调中携带的自定义数据。 |


