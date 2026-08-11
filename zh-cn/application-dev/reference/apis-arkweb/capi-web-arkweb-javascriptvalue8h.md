# ArkWeb_JavaScriptValue*
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

```c
typedef struct ArkWeb_JavaScriptValue* ArkWeb_JavaScriptValuePtr
```

## 概述

ArkWeb_JavaScriptValue是用于在Native代码中封装JavaScript值的结构体，提供了JavaScript值的基本创建和操作能力。该结构体支持将Native数据转换为JavaScript可识别的格式，解决Native与JavaScript双向数据传递的类型安全与格式兼容问题，是JavaScript桥接通信中的数据传递基础类型，有助于减少手动转换成本、提升桥接通信效率并增强可维护性。

**起始版本：** 18

**相关模块：** [Web](capi-web.md)

**所在头文件：** [arkweb_type.h](capi-arkweb-type-h.md)

