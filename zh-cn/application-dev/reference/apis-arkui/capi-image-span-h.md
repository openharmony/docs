# image_span.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Zhang-Dong-hui-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

定义ImageSpan相关的枚举，用于在富文本中嵌入图片并控制图片与文本的对齐方式。支持多种对齐模式，适用于图文混排场景，可实现图片与文本的精确对齐，提升富文本的展示效果。

**引用文件：** <arkui/node_attributes/image_span.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[native_type_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/NativeType/native_type_sample)<!--RP1End-->

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [ArkUI_ImageSpanAlignment](#arkui_imagespanalignment) | ArkUI_ImageSpanAlignment | 定义图片基于文本的对齐方式。 |

## 枚举类型说明

### ArkUI_ImageSpanAlignment

```c
enum ArkUI_ImageSpanAlignment
```

**描述**

定义图片基于文本的对齐方式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BASELINE = 0 | 图片下边沿与文本基线对齐。 |
| ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM = 1 | 图片下边沿与文本下边沿对齐。 |
| ARKUI_IMAGE_SPAN_ALIGNMENT_CENTER = 2 | 图片中间与文本中间对齐。 |
| ARKUI_IMAGE_SPAN_ALIGNMENT_TOP = 3 | 图片上边沿与文本上边沿对齐。 |
| ARKUI_IMAGE_SPAN_ALIGNMENT_FOLLOW_PARAGRAPH = 4 | 图片对齐方式跟随Text组件对齐方式。<br>**起始版本：** 20 |


