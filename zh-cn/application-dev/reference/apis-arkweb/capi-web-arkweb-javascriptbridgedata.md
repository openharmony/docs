# ArkWeb_JavaScriptBridgeData
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct {...} ArkWeb_JavaScriptBridgeData
```

## 概述

ArkWeb_JavaScriptBridgeData是JavaScript桥接数据定义结构体，用于在Native代码和Web页面之间传递JavaScript桥接相关的数据。该结构体封装了桥接调用中的参数数据，是JavaScript桥接子系统中的基本数据单元，配合ArkWeb_ControllerAPI中的JavaScript Proxy注册接口使用。

**起始版本：** 12

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| const uint8_t* buffer | 指向传输数据的指针。支持String和ArrayBuffer类型，其余类型会被json序列化后，以String类型传递。 |
| size_t size | 传输数据的长度。建议根据实际数据大小合理设置，与buffer的大小保持一致，避免过大或过小导致的性能或数据问题。 |


