# OH_ArkUI_FontConfigs
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiaxiaguang-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct OH_ArkUI_FontConfigs OH_ArkUI_FontConfigs
```

## 概述

定义文本的字体配置，当前支持通过相关接口设置和获取字体粗细配置，适用于需要自定义字体粗细显示效果的场景。可以通过[OH_ArkUI_FontConfigs_Create](capi-text-h.md#oh_arkui_fontconfigs_create)接口创建字体配置对象，通过[OH_ArkUI_FontConfigs_Destroy](capi-text-h.md#oh_arkui_fontconfigs_destroy)接口销毁字体配置对象。配置创建后，可通过以下接口进行设置和查询：通过[OH_ArkUI_FontConfigs_SetFontWeightConfigs](capi-text-h.md#oh_arkui_fontconfigs_setfontweightconfigs)接口设置字体粗细配置，通过[OH_ArkUI_FontConfigs_GetFontWeightConfigs](capi-text-h.md#oh_arkui_fontconfigs_getfontweightconfigs)接口获取字体粗细配置。

**起始版本：** 24

**相关模块：** [ArkUI_NativeModule](capi-arkui-nativemodule.md)

**所在头文件：** [text.h](capi-text-h.md)

