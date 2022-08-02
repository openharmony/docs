# LightInterface


## **概述**

**所属模块:**

[Light](_light.md)


## **汇总**


### Public 属性

| Public&nbsp;属性 | 描述 |
| -------- | -------- |
| (&nbsp;[GetLightInfo](#getlightinfo)&nbsp;)([out]&nbsp;struct&nbsp;[LightInfo](_light_info.md)&nbsp;\*\*lightInfo,&nbsp;[out]&nbsp;uint32_t&nbsp;\*count) | 获取当前系统中所有类型的灯信息。&nbsp;[更多...](#getlightinfo) |
| (&nbsp;[TurnOnLight](#turnonlight)&nbsp;)([in]&nbsp;uint32_t&nbsp;lightId,&nbsp;[in]&nbsp;struct&nbsp;[LightEffect](_light_effect.md)&nbsp;\*effect) | 根据指定的灯ID打开列表中的可用灯。&nbsp;[更多...](#turnonlight) |
| (&nbsp;[TurnOffLight](#turnofflight)&nbsp;)([in]&nbsp;uint32_t&nbsp;lightId) | 根据指定的灯ID关闭列表中的可用灯。&nbsp;[更多...](#turnofflight) |


## **详细描述**

定义可以在灯上执行的基本操作。

操作包括获取灯的信息、打开或关闭灯、设置灯的亮度和闪烁模式。


## **类成员变量说明**


### GetLightInfo


```
int32_t(* LightInterface::GetLightInfo) ([out] struct LightInfo **lightInfo,[out] uint32_t *count)
```

**描述：**

获取当前系统中所有类型的灯信息。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| lightInfo | 表示指向灯信息的二级指针，详见[LightInfo](_light_info.md)。 |
| count | 表示指向灯数量的指针。 |

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### TurnOffLight


```
int32_t(* LightInterface::TurnOffLight) ([in] uint32_t lightId)
```

**描述：**

根据指定的灯ID关闭列表中的可用灯。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| lightId | 表示灯ID，详见[LightId](_light.md#lightid)。 |

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### TurnOnLight


```
int32_t(* LightInterface::TurnOnLight) ([in] uint32_t lightId,[in] struct LightEffect *effect)
```

**描述：**

根据指定的灯ID打开列表中的可用灯。

**参数：**

| 名称 | 描述 |
| -------- | -------- |
| lightId | 表示灯ID，详见[LightId](_light.md#lightid)。 |
| effect | 表示指向灯效果的指针，如果lightbrightness字段为0时，&nbsp;灯的亮度根据HCS配置的默认亮度进行设置，详见[LightEffect](_light_effect.md)。 |

**返回：**

如果操作成功，则返回0。

如果不支持灯ID，则返回-1。

如果不支持闪烁设置，则返回-2。

如果不支持亮度设置，则返回-3。

