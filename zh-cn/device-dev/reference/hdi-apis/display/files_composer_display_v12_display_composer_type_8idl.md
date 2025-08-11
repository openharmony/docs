# DisplayComposerType.idl


## 概述

显示合成类型定义，定义显示图层合成操作相关接口所使用的数据类型。

模块包路径：ohos.hdi.display.composer.v1_2

引用：

- ohos.hdi.display.composer.v1_0.DisplayComposerType

- ohos.hdi.display.composer.v1_1.DisplayComposerType

**起始版本：** 5.0

**相关模块：**[Display](index_composer_display_v12.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[PresentParam](annotated_composer_display_v12_present_param.md) | 定义显示参数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [DispPowerStatus](index_composer_display_v12.md#disppowerstatus) : ohos.hdi.display.composer.v1_1.DispPowerStatus {<br/>[POWER_STATUS_PRE_ON](index_composer_display_v12.md) = 5,<br/>[POWER_STATUS_PRE_OFF](index_composer_display_v12.md) = 6,<br/>[POWER_STATUS_DOZE](index_composer_display_v12.md) = 7,<br/>[POWER_STATUS_DOZE_SUSPEND](index_composer_display_v12.md) = 8,<br/>[POWER_STATUS_BUTT_V1_2](index_composer_display_v12.md)<br/>} | 定义电源状态。 | 
| [BufferUsage](index_composer_display_v12.md#bufferusage) : ohos.hdi.display.composer.v1_0.BufferUsage {<br/>[HBM_USE_CPU_HW_BOTH](index_composer_display_v12.md) = (1ULL &lt;&lt; 17), [HBM_USAGE_GPU_PERFORMANCE](index_composer_display_v12.md) = (1ULL &lt;&lt; 18), [HBM_USE_RGB_TO_YUV_CONVERSION](index_composer_display_v12.md) = (1ULL &lt;&lt; 19), [HBM_USE_AUXILLARY_BUFFER0](index_composer_display_v12.md) = (1ULL &lt;&lt; 20),<br/>[HBM_USE_AUXILLARY_BUFFER1](index_composer_display_v12.md) = (1ULL &lt;&lt; 21), [HBM_USE_AUXILLARY_BUFFER2](index_composer_display_v12.md) = (1ULL &lt;&lt; 22), [HBM_USE_AUXILLARY_BUFFER3](index_composer_display_v12.md) = (1ULL &lt;&lt; 23), [HBM_USE_VIDEO_DEC_MV](index_composer_display_v12.md) = HBM_USE_VIDEO_DECODER \| HBM_USE_AUXILLARY_BUFFER2,<br/>[HBM_USE_DRM_REDRAW](index_composer_display_v12.md) = (1ULL &lt;&lt; 24)<br/>} | 定义缓冲区使用情况。 | 
| [PixelFormat](index_composer_display_v12.md#pixelformat) : ohos.hdi.display.composer.v1_1.PixelFormat { [PIXEL_FMT_RGBA16_FLOAT](index_composer_display_v12.md) = 39 } | 像素格式类型定义。 | 
| [DispCmd](index_composer_display_v12.md#dispcmd) : ohos.hdi.display.composer.v1_0.DispCmd {<br/>[REQUEST_CMD_COMMIT_AND_GET_RELEASE_FENCE](index_composer_display_v12.md) = 82, [REQUEST_CMD_SET_DISPLAY_CONSTRAINT](index_composer_display_v12.md) = 83, [REQUEST_CMD_SET_LAYER_PERFRAME_PARAM](index_composer_display_v12.md) = 84, [REQUEST_CMD_BUTT_V1_2](index_composer_display_v12.md),<br/>[REPLY_CMD_COMMIT_AND_GET_RELEASE_FENCE](index_composer_display_v12.md) = 515, [REPLY_CMD_BUTT_V1_2](index_composer_display_v12.md)<br/>} | 枚举Display命令。 | 
| [DisplayPropertyID](index_composer_display_v12.md#displaypropertyid) { [DISPLAY_PROPERTY_ID_SKIP_VALIDATE](index_composer_display_v12.md) = 1, [DISPLAY_CAPBILITY_HARDWARE_CURSOR](index_composer_display_v12.md) = 2, [DISPLAY_PROPERTY_ID_ADAPTIVE_SYNC](index_composer_display_v12.md) = 3 } | 定义显示属性ID。 | 
