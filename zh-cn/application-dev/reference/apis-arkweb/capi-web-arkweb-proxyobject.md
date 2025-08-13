# ArkWeb_ProxyObject
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--SE: @yaomingliu-->
<!--TSE: @ghiker-->

## 概述

注入的Proxy对象通用结构体。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称                                       | 描述 |
|------------------------------------------| -- |
| const char* objName                      | 注入的对象名。 |
| const [ArkWeb_ProxyMethod](capi-web-arkweb-proxymethod.md)* methodList | 注入的对象携带的方法结构体数组。 |
| size_t size                              | 方法结构体数组的长度。 |


