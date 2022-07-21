# VibratorInterface


## **概述**

**所属模块:**

[Vibrator](_vibrator.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| (&nbsp;[StartOnce](#startonce)&nbsp;)([in]&nbsp;uint32_t&nbsp;duration) | 控制马达以执行给定持续时间的一次性振动。&nbsp;[更多...](#startonce) | 
| (&nbsp;[Start](#start)&nbsp;)([in]&nbsp;const&nbsp;char&nbsp;\*effectType) | 控制马达以预置效果执行周期性振动。&nbsp;[更多...](#start) | 
| (&nbsp;[Stop](#stop)&nbsp;)([in]&nbsp;enum&nbsp;[VibratorMode](_vibrator.md#vibratormode)&nbsp;mode) | 停止马达振动。&nbsp;[更多...](#stop) | 
| (&nbsp;[GetVibratorInfo](#getvibratorinfo))([out]&nbsp;struct&nbsp;VibratorInfo&nbsp;\*\*vibratorInfo) | 获取有关系统中支持设置振幅和频率的所有马达信息。[更多...](#getvibratorinfo) | 
| (&nbsp;[EnableVibratorModulation](#enablevibratormodulation))(uint32_t&nbsp;duration,&nbsp;int32_t&nbsp;intensity,&nbsp;int32_t&nbsp;frequency) | 根据传入的振动效果启动马达。&nbsp;[更多...](#enablevibratormodulation) | 


## **详细描述**

提供Vibrator设备基本控制操作接口。

操作包括马达模式和效果振动、停止马达振动。


## **类成员变量说明**


### Start

  
```
int32_t(*VibratorInterface::Start) ([in] const char *effectType)
```

**描述：**

控制马达以预置效果执行周期性振动。

单次振动与周期振动相互排斥。在执行一次性振动之前，需退出周期性振动。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| effectType | 指向指示预置效果类型的指针。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since:**

2.2

**Version:**

1.0


### StartOnce

  
```
int32_t(*VibratorInterface::StartOnce) ([in] uint32_t duration)
```

**描述：**

控制马达以执行给定持续时间的一次性振动。

单次振动与周期振动相互排斥。在执行一次性振动之前，需退出周期性振动。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| duration | 指示一次性振动的持续时间，以毫秒为单位。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since:**

2.2

**Version:**

1.0


### Stop

  
```
int32_t(*VibratorInterface::Stop) ([in] enum VibratorMode mode)
```

**描述：**

停止马达振动。

马达启动前，必须在任何模式下停止振动。此功能用在振动过程之后。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| mode | 指示振动模式，可以是一次性或周期性的，详见[VibratorMode](_vibrator.md#vibratormode)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since:**

2.2

**Version:**

1.0


### GetVibratorInfo

  
```
int32_t (*VibratorInterface::GetVibratorInfo)([out] struct VibratorInfo **vibratorInfo)
```

**描述：**

获取有关系统中支持设置振幅和频率的所有马达信息。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| vibratorInfo | 表示指向马达信息的指针，详见&nbsp;[VibratorInfo](_vibrator.md#vibratorinfo)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since:**

3.2

**Version:**

1.1


### EnableVibratorModulation

  
```
int32_t (*VibratorInterface::EnableVibratorModulation)(uint32_t duration, int32_t intensity, int32_t frequency);
```

**描述：**

根据传入的振动效果启动马达。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| duration | 表示马达振动的持续时间，以毫秒为单位。 | 
| intensity | 表示振动周期内的马达振幅。 | 
| frequency | 表示振动周期内的马达频率。 | 

**返回：**

如果操作成功，则返回0。

如果不支持振动周期设置，则返回-1。

如果不支持振幅设置，则返回-2。

如果不支持频率设置，则返回-3。


**Since:**


3.2


**Version:**


1.1
