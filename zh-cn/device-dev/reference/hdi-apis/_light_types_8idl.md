# LightTypes.idl


## **概述**

定义灯的数据结构，包括灯类型ID、灯的基本信息、灯的模式、灯的闪烁参数、灯的颜色模式和灯的效果参数。

**Since:**

3.1

**Version:**

1.0

**相关模块:**

[Light](light.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [HdfLightInfo](_hdf_light_info.md) | 定义灯的基本信息。 | 
| [HdfLightFlashEffect](_hdf_light_flash_effect.md) | 定义灯的闪烁参数。 | 
| [RGBColor](_r_g_b_color.md) | 定义灯的RGB模式。 | 
| [WRGBColor](_w_r_g_b_color.md) | 定义灯的WRGB模式。 | 
| [ColorValue](union_color_value.md) | 定义灯的颜色模式。 | 
| [HdfLightColor](_hdf_light_color.md) | 定义亮灯参数。 | 
| [HdfLightEffect](_hdf_light_effect.md) | 定义灯的效果参数。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [HdfLightId](light.md#hdflightid)&nbsp;{&nbsp;HDF_LIGHT_ID_BATTERY&nbsp;=&nbsp;1,&nbsp;HDF_LIGHT_ID_NOTIFICATIONS&nbsp;=&nbsp;2,&nbsp;HDF_LIGHT_ID_ATTENTION&nbsp;=&nbsp;3,&nbsp;HDF_LIGHT_ID_BUTT&nbsp;=&nbsp;4&nbsp;} | 枚举灯类型。 | 
| [HdfLightFlashMode](light.md#hdflightflashmode)&nbsp;{&nbsp;HDF_LIGHT_FLASH_NONE&nbsp;=&nbsp;0,&nbsp;HDF_LIGHT_FLASH_BLINK&nbsp;=&nbsp;1,&nbsp;HDF_LIGHT_FLASH_GRADIENT&nbsp;=&nbsp;2,&nbsp;HDF_LIGHT_FLASH_BUTT&nbsp;=&nbsp;3&nbsp;} | 枚举灯的模式。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.light.v1_0 | 灯模块接口的包路径。 | 
