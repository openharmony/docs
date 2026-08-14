# ArkWeb_ProxyMethod
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct {...} ArkWeb_ProxyMethod
```

## 概述

ArkWeb_ProxyMethod是用于定义JavaScript代理方法的结构体，支持实现JavaScript与Native代码之间的安全通信，适用于需要从Web页面调用Native能力的场景。该结构体指定了一个可以从JavaScript调用的Native方法的基本信息，包含方法名称和对应的Native回调函数指针和需要携带的自定义数据三个字段。多个ArkWeb_ProxyMethod可以组合成ArkWeb_ProxyObject，以对象的形式整体注入到Web页面中，从而让Web应用能够方便地访问设备原生能力。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称                                                                                                  | 描述 |
|-----------------------------------------------------------------------------------------------------| -- |
| const char* methodName                                                                              | 注入的方法名。 |
| [ArkWeb_OnJavaScriptProxyCallback](capi-arkweb-type-h.md#arkweb_onjavascriptproxycallback) callback | JavaScript通过Proxy对象调用该方法时触发的回调函数，用于处理来自JavaScript的方法调用。回调函数中可以访问JavaScript传入的参数（dataArray）并执行相应的Native逻辑。 |
| void* userData                                                                                      | 需要在回调中携带的自定义数据。 |


