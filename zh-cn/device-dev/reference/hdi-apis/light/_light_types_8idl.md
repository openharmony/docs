# LightTypes.idl


## 概述

定义灯的数据结构，包括灯类型ID、灯的基本信息、灯的模式、灯的闪烁参数、灯的颜色模式和灯的效果参数。

模块包路径：ohos.hdi.light.v1_0

**起始版本：** 3.1

**相关模块：**[Light](_light.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[HdfLightInfo](_hdf_light_info_v10.md) | 定义灯的基本信息。 | 
| struct&nbsp;&nbsp;[HdfLightFlashEffect](_hdf_light_flash_effect_v10.md) | 定义灯的闪烁参数。 | 
| struct&nbsp;&nbsp;[RGBColor](_r_g_b_color_v10.md) | 定义灯的RGB模式。 | 
| struct&nbsp;&nbsp;[WRGBColor](_w_r_g_b_color_v10.md) | 定义灯的WRGB模式。 | 
| union&nbsp;&nbsp;[ColorValue](union_color_value_v10.md) | 定义灯的颜色模式。 | 
| struct&nbsp;&nbsp;[HdfLightColor](_hdf_light_color_v10.md) | 定义亮灯参数。 | 
| struct&nbsp;&nbsp;[HdfLightEffect](_hdf_light_effect_v10.md) | 定义灯的效果参数。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [HdfLightId](_light.md#hdflightid) { HDF_LIGHT_ID_BATTERY = 1, HDF_LIGHT_ID_NOTIFICATIONS = 2, HDF_LIGHT_ID_ATTENTION = 3, HDF_LIGHT_ID_BUTT = 4 } | 枚举灯类型。 | 
| [HdfLightFlashMode](_light.md#hdflightflashmode) { HDF_LIGHT_FLASH_NONE = 0, HDF_LIGHT_FLASH_TIMED = 1, HDF_LIGHT_FLASH_GRADIENT = 2, HDF_LIGHT_FLASH_BUTT = 3 } | 枚举灯的模式。 | 
