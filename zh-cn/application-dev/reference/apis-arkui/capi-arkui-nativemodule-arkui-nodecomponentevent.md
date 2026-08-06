# ArkUI_NodeComponentEvent
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @piggyguy; @wangyang2022-->
<!--Designer: @piggyguy; @wangyang2022-->
<!--Tester: @fredyuan912-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} ArkUI_NodeComponentEvent
```

## 概述

定义组件回调事件的参数类型，用于在组件回调触发时传递事件相关数据，便于应用获取回调事件参数。

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [native_node.h](capi-native-node-h.md)

## 汇总

### 成员变量

| 名称                                                      | 描述 |
|---------------------------------------------------------| -- |
| [ArkUI_NumberValue](capi-arkui-nativemodule-arkui-numbervalue.md) data[[MAX_COMPONENT_EVENT_ARG_NUM](capi-native-node-h.md#宏定义)] | 用于存储组件回调事件的参数数据，数组元素按照回调事件定义的参数顺序排列；各事件类型的参数定义详见[native_node.h](capi-native-node-h.md)相关说明。 |


