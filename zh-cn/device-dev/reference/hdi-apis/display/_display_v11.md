# Display (V1_1)


## 概述

显示模块驱动接口定义。

提供给上层图形服务使用的驱动接口，包括图层管理、设备控制、显示内存管理等相关接口。

**起始版本：** 4.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [IMetadata.idl](_i_metadata_8idl_v11.md) | 显示数据映射接口声明。 | 
| [DisplayComposerType.idl](_display_composer_type_8idl_v11.md) | 显示合成类型定义，定义显示图层合成操作相关接口所使用的数据类型。 | 
| [IDisplayComposer.idl](_i_display_composer_8idl_v11.md) | 显示合成接口声明。 | 
| [IModeCallback.idl](_i_mode_callback_8idl_v11.md) | 显示合成接口声明。 | 
| [ISeamlessChangeCallback.idl](_i_seamless_change_callback_8idl_v11.md) | 显示合成接口声明。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[IMetadata](interface_i_metadata_v11.md) | 定义显示数据映射接口。 | 
| struct&nbsp;&nbsp;[DisplayModeInfoExt](_display_mode_info_ext_v11.md) | 定义输出模式 ext 信息。 | 
| interface&nbsp;&nbsp;[IDisplayComposer](interface_i_display_composer_v11.md) | 显示合成接口声明。 | 
| interface&nbsp;&nbsp;[IModeCallback](interface_i_mode_callback_v11.md) | Display模块接口的包路径。 | 
| interface&nbsp;&nbsp;[ISeamlessChangeCallback](interface_i_seamless_change_callback_v11.md) | 更改帧速率需要使用的接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [PixelFormat](#pixelformat) : ohos.hdi.display.composer.v1_0.PixelFormat { PIXEL_FMT_YCBCR_P010 = 35 , PIXEL_FMT_YCRCB_P010 , PIXEL_FMT_RAW10 } | 像素格式类型定义。 | 
| [DispPowerStatus](#disppowerstatus) : ohos.hdi.display.composer.v1_0.DispPowerStatus { POWER_STATUS_OFF_FAKE = 4 , POWER_STATUS_BUTT_V1_1 } | 枚举显示状态。 | 
| [CompositionType](#compositiontype) : ohos.hdi.display.composer.v1_0.CompositionType { COMPOSITION_SOLID_COLOR = 7 , COMPOSITION_BUTT_V1_1 } | 枚举特殊层的组合类型。 | 


## 枚举类型说明


### CompositionType

```
enum CompositionType : ohos.hdi.display.composer.v1_0.CompositionType
```

**描述**


枚举特殊层的组合类型。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| COMPOSITION_SOLID_COLOR | Tunnel 组合类型，用于 tunnel. | 
| COMPOSITION_BUTT_V1_1 | 无效的合成类型 | 


### DispPowerStatus

```
enum DispPowerStatus : ohos.hdi.display.composer.v1_0.DispPowerStatus
```

**描述**


枚举显示状态。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| POWER_STATUS_OFF_FAKE | 当 hwc 关闭时，电源状态为 ON | 
| POWER_STATUS_BUTT_V1_1 | 电源状态无效 | 


### PixelFormat

```
enum PixelFormat : ohos.hdi.display.composer.v1_0.PixelFormat
```

**描述**


像素格式类型定义。

**起始版本：** 4.1

| 枚举值 | 描述 | 
| -------- | -------- |
| PIXEL_FMT_YCBCR_P010 | YCBCR420 半平面 10 位格式 | 
| PIXEL_FMT_YCRCB_P010 | YCRCB420 半平面 10 位格式 | 
| PIXEL_FMT_RAW10 | RAW 10bit 格式 | 
