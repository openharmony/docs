# ILightInterface


## **概述**

提供灯模块基本操作接口。

操作包括获取灯的信息、打开或关闭灯、设置灯的亮度或闪烁模式。

**Since:**

3.1

**Version:**

1.0

**相关模块:**

[Light](light.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [GetLightInfo](#getlightinfo)&nbsp;([out]&nbsp;struct&nbsp;[HdfLightInfo](_hdf_light_info.md)[]&nbsp;info) | 获取当前系统中所有类型的灯信息。 | 
| [TurnOnLight](#turnonlight)&nbsp;([in]&nbsp;int&nbsp;lightId,&nbsp;[in]&nbsp;struct&nbsp;[HdfLightEffect](_hdf_light_effect.md)&nbsp;effect) | 根据指定的灯类型ID打开列表中的可用灯。 | 
| [TurnOnMultiLights](#turnonmultilights)&nbsp;([in]&nbsp;int&nbsp;lightId,&nbsp;[in]&nbsp;struct&nbsp;[HdfLightColor](_hdf_light_color.md)[]&nbsp;colors) | 根据指定的灯类型ID打开相应灯中包含的多个子灯。 | 
| [TurnOffLight](#turnofflight)&nbsp;([in]&nbsp;int&nbsp;lightId) | 根据指定的灯类型ID关闭列表中的可用灯。 | 


## **成员函数说明**


### GetLightInfo()

  
```
ILightInterface::GetLightInfo ([out] struct HdfLightInfo[] info)
```

**描述：**

获取当前系统中所有类型的灯信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| info | 表示指向灯信息的二级指针。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### TurnOffLight()

  
```
ILightInterface::TurnOffLight ([in] int lightId)
```

**描述：**

根据指定的灯类型ID关闭列表中的可用灯。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| lightId | 表示灯类型ID，详见[HdfLightId](light.md#hdflightid)。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### TurnOnLight()

  
```
ILightInterface::TurnOnLight ([in] int lightId, [in] struct HdfLightEffect effect )
```

**描述：**

根据指定的灯类型ID打开列表中的可用灯。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| lightId | 表示灯类型ID。详见[HdfLightId](light.md#hdflightid)。 | 
| effect | 表示指向灯效果的指针，如果lightbrightness字段为0时，&nbsp;灯的亮度根据HCS配置的默认亮度进行设置。详见[HdfLightEffect](_hdf_light_effect.md)。 | 

**返回:**

如果操作成功，则返回0。

如果不支持灯类型ID，则返回-1。

如果不支持闪烁设置，则返回-2。

如果不支持亮度设置，则返回-3。


### TurnOnMultiLights()

  
```
ILightInterface::TurnOnMultiLights ([in] int lightId, [in] struct HdfLightColor[] colors )
```

**描述：**

根据指定的灯类型ID打开相应灯中包含的多个子灯。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| lightId | 表示灯类型ID，详见[HdfLightId](light.md#hdflightid)。 | 
| colors | 多个子灯对应的颜色和亮度,&nbsp;详见[HdfLightColor](_hdf_light_color.md)。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。
