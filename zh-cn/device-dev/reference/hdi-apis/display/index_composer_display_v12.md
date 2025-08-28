# Display (V1_2)


## 概述

显示模块驱动接口定义。

提供给上层图形服务使用的驱动接口，包括图层管理、设备控制、显示内存管理等相关接口。

**起始版本：** 5.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [DisplayComposerType.idl](files_composer_display_v12_display_composer_type_8idl.md) | 显示合成类型定义，定义显示图层合成操作相关接口所使用的数据类型。 | 
| [IDisplayComposer.idl](files_composer_display_v12_i_display_composer_8idl.md) | 显示合成接口声明。 | 
| [IVBlankIdleCallback.idl](files_composer_display_v12_i_v_blank_idle_callback_8idl.md) | 帧同步事件回调接口声明。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[PresentParam](annotated_composer_display_v12_present_param.md) | 定义显示参数。 | 
| interface&nbsp;&nbsp;[IDisplayComposer](annotated_composer_display_v12_interface_i_display_composer.md) | 显示合成接口声明。主要提供注册热插拔事件回调、获取显示设备能力集等功能，在v1_1.IDisplayComposer基础上新增注册更改VBlankIdle事件回调、清除缓冲区、硬光标特性等功能，具体方法使用详见函数说明。 | 
| interface&nbsp;&nbsp;[IVBlankIdleCallback](annotated_composer_display_v12_interface_i_v_blank_idle_callback.md) | 定义帧同步事件回调接口。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DispPowerStatus](#disppowerstatus) : ohos.hdi.display.composer.v1_1.DispPowerStatus {<br/>POWER_STATUS_PRE_ON = 5,<br/>POWER_STATUS_PRE_OFF = 6,<br/>POWER_STATUS_DOZE = 7,<br/>POWER_STATUS_DOZE_SUSPEND = 8,<br/>POWER_STATUS_BUTT_V1_2<br/>} | 定义电源状态。 | 
| [BufferUsage](#bufferusage) : ohos.hdi.display.composer.v1_0.BufferUsage {<br/>HBM_USE_CPU_HW_BOTH = (1ULL &lt;&lt; 17), HBM_USAGE_GPU_PERFORMANCE = (1ULL &lt;&lt; 18), HBM_USE_RGB_TO_YUV_CONVERSION = (1ULL &lt;&lt; 19), HBM_USE_AUXILLARY_BUFFER0 = (1ULL &lt;&lt; 20),<br/>HBM_USE_AUXILLARY_BUFFER1 = (1ULL &lt;&lt; 21), HBM_USE_AUXILLARY_BUFFER2 = (1ULL &lt;&lt; 22), HBM_USE_AUXILLARY_BUFFER3 = (1ULL &lt;&lt; 23), HBM_USE_VIDEO_DEC_MV = HBM_USE_VIDEO_DECODER \| HBM_USE_AUXILLARY_BUFFER2,<br/>HBM_USE_DRM_REDRAW = (1ULL &lt;&lt; 24)<br/>} | 定义缓冲区使用情况。 | 
| [PixelFormat](#pixelformat) : ohos.hdi.display.composer.v1_1.PixelFormat { PIXEL_FMT_RGBA16_FLOAT = 39 } | 像素格式类型定义。 | 
| [DispCmd](#dispcmd) : ohos.hdi.display.composer.v1_0.DispCmd {<br/>REQUEST_CMD_COMMIT_AND_GET_RELEASE_FENCE = 82, REQUEST_CMD_SET_DISPLAY_CONSTRAINT = 83, REQUEST_CMD_SET_LAYER_PERFRAME_PARAM = 84, REQUEST_CMD_BUTT_V1_2,<br/>REPLY_CMD_COMMIT_AND_GET_RELEASE_FENCE = 515, REPLY_CMD_BUTT_V1_2<br/>} | 枚举Display命令。 | 
| [DisplayPropertyID](#displaypropertyid) { DISPLAY_PROPERTY_ID_SKIP_VALIDATE = 1, DISPLAY_CAPBILITY_HARDWARE_CURSOR = 2, DISPLAY_PROPERTY_ID_ADAPTIVE_SYNC = 3 } | 定义显示属性ID。 | 


## 枚举类型说明


### BufferUsage

```
enum BufferUsage : ohos.hdi.display.composer.v1_0.BufferUsage
```

**描述**

定义缓冲区使用情况。

**起始版本：** 5.0

| 枚举值 | 描述 | 
| -------- | -------- |
| HBM_USE_CPU_HW_BOTH | 支持CPU和硬件 | 
| HBM_USAGE_GPU_PERFORMANCE | 首选性能而不是内存消耗 | 
| HBM_USE_RGB_TO_YUV_CONVERSION | 用于识别RGB到YUV的转换 | 
| HBM_USE_AUXILLARY_BUFFER0 | 保留缓冲区BUFFER0 | 
| HBM_USE_AUXILLARY_BUFFER1 | 保留缓冲区BUFFER1 | 
| HBM_USE_AUXILLARY_BUFFER2 | 保留缓冲区BUFFER2 | 
| HBM_USE_AUXILLARY_BUFFER3 | 保留缓冲区BUFFER3 | 
| HBM_USE_VIDEO_DEC_MV | 支持音视频解码 | 
| HBM_USE_DRM_REDRAW | 对DRM重绘帧缓冲区分配 | 


### DispCmd

```
enum DispCmd : ohos.hdi.display.composer.v1_0.DispCmd
```

**描述**

枚举Display命令。

**起始版本：** 5.0

| 枚举值 | 描述 | 
| -------- | -------- |
| REQUEST_CMD_COMMIT_AND_GET_RELEASE_FENCE | 请求cmd提交并释放Fence句柄 | 
| REQUEST_CMD_SET_DISPLAY_CONSTRAINT | 请求cmd设置显示约束 | 
| REQUEST_CMD_SET_LAYER_PERFRAME_PARAM | 设置图层cmd | 
| REQUEST_CMD_BUTT_V1_2 | 请求按键cmd | 
| REPLY_CMD_COMMIT_AND_GET_RELEASE_FENCE | 回复cmd提交并释放Fence句柄 | 
| REPLY_CMD_BUTT_V1_2 | 回复cmd提交并释放Fence句柄 | 


### DisplayPropertyID

```
enum DisplayPropertyID
```

**描述**

定义显示属性ID。

**起始版本：** 5.0

| 枚举值 | 描述 | 
| -------- | -------- |
| DISPLAY_PROPERTY_ID_SKIP_VALIDATE | 表示跳过验证特性 | 
| DISPLAY_CAPBILITY_HARDWARE_CURSOR | 表示硬光标特性 | 
| DISPLAY_PROPERTY_ID_ADAPTIVE_SYNC | 表示是否支持 Adaptive Sync（提前显示） | 


### DispPowerStatus

```
enum DispPowerStatus : ohos.hdi.display.composer.v1_1.DispPowerStatus
```

**描述**

定义电源状态。

**起始版本：** 5.0

| 枚举值 | 描述 | 
| -------- | -------- |
| POWER_STATUS_PRE_ON | 进入预点亮屏幕状态 | 
| POWER_STATUS_PRE_OFF | 退出预点亮屏幕状态 | 
| POWER_STATUS_DOZE | 电源状态为DOZE（省电） | 
| POWER_STATUS_DOZE_SUSPEND | 电源状态为DOZE_SUSPEND（超级省电） | 
| POWER_STATUS_BUTT_V1_2 | 无效状态 | 


### PixelFormat

```
enum PixelFormat : ohos.hdi.display.composer.v1_1.PixelFormat
```

**描述**

像素格式类型定义。

**起始版本：** 5.0

| 枚举值 | 描述 | 
| -------- | -------- |
| PIXEL_FMT_RGBA16_FLOAT | RGBA16 float格式 | 
