# custom_attributes.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @wangyang2022-->
<!--Designer: @wangyang2022-->
<!--Tester: @sally__-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

为NativeNode API提供自定义组件的测量、布局和绘制事件类型定义，用于注册和处理测量、布局以及内容层、前景层和浮层的绘制事件。

**引用文件：** <arkui/node_attributes/custom_attributes.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[native_node_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/native_node_sample)<!--RP1End-->

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_NodeCustomEventType](#arkui_nodecustomeventtype) | ArkUI_NodeCustomEventType | 定义自定义组件事件类型。 |

## 枚举类型说明

### ArkUI_NodeCustomEventType

```c
enum ArkUI_NodeCustomEventType
```

**描述：**


定义自定义组件事件类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE = 1 << 0 | 自定义测量类型。 <br>**起始版本：** 12 |
| ARKUI_NODE_CUSTOM_EVENT_ON_LAYOUT = 1 << 1 | 自定义布局类型。 <br>**起始版本：** 12 |
| ARKUI_NODE_CUSTOM_EVENT_ON_DRAW = 1 << 2 | 自定义内容层绘制类型。 <br>**起始版本：** 12 |
| ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW = 1 << 3 | 自定义前景绘制类型。 <br>**起始版本：** 12 |
| ARKUI_NODE_CUSTOM_EVENT_ON_OVERLAY_DRAW = 1 << 4 | 自定义浮层绘制类型。 <br>**起始版本：** 12 |
| ARKUI_NODE_CUSTOM_EVENT_ON_DRAW_FRONT = 1 << 5 | 自定义内容层前景绘制类型。 <br>**起始版本：** 20 |
| ARKUI_NODE_CUSTOM_EVENT_ON_DRAW_BEHIND = 1 << 6 | 自定义内容层背景绘制类型。 <br>**起始版本：** 20 |
