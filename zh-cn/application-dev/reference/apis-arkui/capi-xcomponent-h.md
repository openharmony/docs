# xcomponent.h
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

XComponent组件枚举类型定义，用于描述XComponent的渲染类型，支持EGL/OpenGLES绘制及媒体数据写入场景，可满足开发者定制内容单独或与组件合成展示的渲染需求。

**引用文件：** <arkui/node_attributes/xcomponent.h>

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**相关示例：** <!--RP1-->[xcomponent_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Native/XComponent3D)<!--RP1End-->

## 汇总

### 枚举

| 名称                                                                  | typedef关键字                      | 描述                                |
|---------------------------------------------------------------------|---------------------------------|-----------------------------------|
| [ArkUI_XComponentType](#arkui_xcomponenttype)                       | ArkUI_XComponentType            | 定义XComponent类型枚举值。                |

## 枚举类型说明

### ArkUI_XComponentType

```c
enum ArkUI_XComponentType
```

**描述：**

定义XComponent类型枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| ARKUI_XCOMPONENT_TYPE_SURFACE = 0 | 用于EGL/OpenGLES和媒体数据写入，开发者定制绘制内容单独显示在屏幕上。 |
| ARKUI_XCOMPONENT_TYPE_TEXTURE = 2 | 用于EGL/OpenGLES和媒体数据写入，开发者定制绘制内容和XComponent组件内容合成后显示在屏幕上。 |
