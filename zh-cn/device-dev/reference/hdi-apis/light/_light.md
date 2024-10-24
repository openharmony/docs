# Light


## 概述

灯驱动对灯服务提供通用的接口能力。

灯模块为灯服务提供通用的接口去访问灯驱动，服务获取灯驱动对象或代理后，可以通过调用的APIs接口获取相关的灯信息。 例如打开或关闭灯、根据灯类型ID设置灯闪烁模式。

**起始版本：** 3.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ILightInterface.idl](_i_light_interface_8idl.md) | 定义灯模块的通用接口能力，包括获取灯类型ID、打开或关闭灯光、设置灯的亮度和闪烁模式。 | 
| [LightTypes.idl](_light_types_8idl.md) | 定义灯的数据结构，包括灯类型ID、灯的基本信息、灯的模式、灯的闪烁参数、灯的颜色模式和灯的效果参数。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| interface&nbsp;&nbsp;[ILightInterface](interface_i_light_interface_v10.md) | 提供灯模块基本操作接口。 | 
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
| [HdfLightId](#hdflightid) { HDF_LIGHT_ID_BATTERY = 1, HDF_LIGHT_ID_NOTIFICATIONS = 2, HDF_LIGHT_ID_ATTENTION = 3, HDF_LIGHT_ID_BUTT = 4 } | 枚举灯类型。 | 
| [HdfLightFlashMode](#hdflightflashmode) { HDF_LIGHT_FLASH_NONE = 0, HDF_LIGHT_FLASH_TIMED = 1, HDF_LIGHT_FLASH_GRADIENT = 2, HDF_LIGHT_FLASH_BUTT = 3 } | 枚举灯的模式。 | 


## 枚举类型说明


### HdfLightFlashMode

```
enum HdfLightFlashMode
```

**描述**


枚举灯的模式。

**起始版本：** 3.1

| 枚举值 | 描述 | 
| -------- | -------- |
| HDF_LIGHT_FLASH_NONE | 常亮模式。 | 
| HDF_LIGHT_FLASH_BLINK | 闪烁模式。 | 
| HDF_LIGHT_FLASH_GRADIENT | 渐变。 | 
| HDF_LIGHT_FLASH_BUTT | 无效模式。 | 


### HdfLightId

```
enum HdfLightId
```

**描述**


枚举灯类型。

**起始版本：** 3.1

| 枚举值 | 描述 | 
| -------- | -------- |
| HDF_LIGHT_ID_BATTERY | 电源指示灯。 | 
| HDF_LIGHT_ID_NOTIFICATIONS | 通知灯。 | 
| HDF_LIGHT_ID_ATTENTION | 报警灯。 | 
| HDF_LIGHT_ID_BUTT | 无效ID。 | 
