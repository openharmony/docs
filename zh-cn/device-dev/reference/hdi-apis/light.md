# Light


## **概述**

灯驱动对灯服务提供通用的接口能力。

灯模块为灯服务提供通用的接口去访问灯驱动，服务获取灯驱动对象或代理后，可以通过调用的APIs接口获取相关的灯信息。 例如打开或关闭灯、根据灯类型ID设置灯闪烁模式。

**Since**:

3.1

**Version**:

1.0


## **汇总**


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [ILightInterface.idl](_i_light_interface_8idl.md) | 定义灯模块的通用接口能力，包括获取灯类型ID、打开或关闭灯光、设置灯的亮度和闪烁模式。 | 
| [LightTypes.idl](_light_types_8idl.md) | 定义灯的数据结构，包括灯类型ID、灯的基本信息、灯的模式、灯的闪烁参数、灯的颜色模式和灯的效果参数。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [ILightInterface](interface_i_light_interface.md) | 提供灯模块基本操作接口。 | 
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
| [HdfLightId](#hdflightid)&nbsp;{&nbsp;HDF_LIGHT_ID_BATTERY&nbsp;=&nbsp;1,&nbsp;HDF_LIGHT_ID_NOTIFICATIONS&nbsp;=&nbsp;2,&nbsp;HDF_LIGHT_ID_ATTENTION&nbsp;=&nbsp;3,&nbsp;HDF_LIGHT_ID_BUTT&nbsp;=&nbsp;4&nbsp;} | 枚举灯类型。 | 
| [HdfLightFlashMode](#hdflightflashmode)&nbsp;{&nbsp;HDF_LIGHT_FLASH_NONE&nbsp;=&nbsp;0,&nbsp;HDF_LIGHT_FLASH_BLINK&nbsp;=&nbsp;1,&nbsp;HDF_LIGHT_FLASH_GRADIENT&nbsp;=&nbsp;2,&nbsp;HDF_LIGHT_FLASH_BUTT&nbsp;=&nbsp;3&nbsp;} | 枚举灯的模式。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.light.v1_0 | 灯模块接口的包路径。 | 


## **枚举类型说明**


### HdfLightFlashMode

  
```
enum HdfLightFlashMode
```

**描述：**

枚举灯的模式。

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

**描述：**

枚举灯类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| HDF_LIGHT_ID_BATTERY | 电源指示灯。 | 
| HDF_LIGHT_ID_NOTIFICATIONS | 通知灯。 | 
| HDF_LIGHT_ID_ATTENTION | 报警灯。 | 
| HDF_LIGHT_ID_BUTT | 无效ID。 | 
