# IVibratorInterface


## 概述

Vibrator模块向上层服务提供统一的接口。

上层服务开发人员可根据Vibrator模块提供的统一接口，用于控制马达执行单次或周期性振动。

**起始版本：** 3.2

**相关模块：**[Vibrator](_vibrator_v11.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [StartOnce](#startonce) ([in] unsigned int duration) | 控制马达以执行给定持续时间的单次振动。 | 
| [Start](#start) ([in] String effectType) | 控制马达以预置效果执行周期性振动。 | 
| [Stop](#stop) ([in] enum [HdfVibratorMode](_vibrator_v11.md#hdfvibratormode) mode) | 停止马达振动。 | 
| [GetVibratorInfo](#getvibratorinfo) ([out] struct [HdfVibratorInfo](_hdf_vibrator_info_v11.md)[] vibratorInfo) | 获取有关系统中支持设置振幅和频率的所有马达信息。 | 
| [EnableVibratorModulation](#enablevibratormodulation) ([in] unsigned int duration, [in] int intensity, [in] int frequency) | 根据传入的振动效果启动马达。 | 
| [EnableCompositeEffect](#enablecompositeeffect) ([in] struct [HdfCompositeEffect](_hdf_composite_effect_v11.md) effect) | 控制可控震源以执行具有自定义复合效果的周期性振动。 | 
| [GetEffectInfo](#geteffectinfo) ([in] String effectType, [out] struct [HdfEffectInfo](_hdf_effect_info_v11.md) effectInfo) | 获取指定效果类型的振动效果信息。 | 
| [IsVibratorRunning](#isvibratorrunning) ([out] boolean state) | 获取振动器当前是否正在振动。 | 


## 成员函数说明


### EnableCompositeEffect()

```
IVibratorInterface::EnableCompositeEffect ([in] struct HdfCompositeEffect effect)
```

**描述**


控制可控震源以执行具有自定义复合效果的周期性振动。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| effect | 表示指向自定义复合效果类型的指针。关于细节，请参阅[HdfCompositeEffect](_hdf_composite_effect_v11.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### EnableVibratorModulation()

```
IVibratorInterface::EnableVibratorModulation ([in] unsigned int duration, [in] int intensity, [in] int frequency )
```

**描述**


根据传入的振动效果启动马达。

**起始版本：** 3.2

**参数:**

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


### GetEffectInfo()

```
IVibratorInterface::GetEffectInfo ([in] String effectType, [out] struct HdfEffectInfo effectInfo )
```

**描述**


获取指定效果类型的振动效果信息。


**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| effectType | 指示指向预设效果类型的指针。建议最大长度为64字节。 | 
| effectInfo | 表示指向振动效果信息的指针。关于细节，请参阅[HdfEffectInfo](_hdf_effect_info_v11.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetVibratorInfo()

```
IVibratorInterface::GetVibratorInfo ([out] struct HdfVibratorInfo[] vibratorInfo)
```

**描述**


获取有关系统中支持设置振幅和频率的所有马达信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| vibratorInfo | 表示指向马达信息的指针，详见[HdfVibratorInfo](_hdf_vibrator_info_v11.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### IsVibratorRunning()

```
IVibratorInterface::IsVibratorRunning ([out] boolean state)
```

**描述**


获取振动器当前是否正在振动。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| state | 表示可控震源的当前振动状态。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Start()

```
IVibratorInterface::Start ([in] String effectType)
```

**描述**


控制马达以预置效果执行周期性振动。

单次振动与周期振动相互排斥。在执行周期性振动之前，需退出单次振动。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| effectType | 表示马达振动的预设效果类型。建议最大长度为64字节。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### StartOnce()

```
IVibratorInterface::StartOnce ([in] unsigned int duration)
```

**描述**


控制马达以执行给定持续时间的单次振动。

单次振动与周期振动相互排斥。在执行单次振动之前，需退出周期性振动。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| duration | 表示单次振动的持续时间，以毫秒为单位。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Stop()

```
IVibratorInterface::Stop ([in] enum HdfVibratorMode mode)
```

**描述**


停止马达振动。

马达启动前，必须在任何模式下停止振动。此功能用在振动过程之后。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mode | 表示振动模式，可以是单次或周期性的，详见[HdfVibratorMode](_vibrator_v11.md#hdfvibratormode)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
