# IVibratorInterface


## **概述**

Vibrator模块向上层服务提供统一的接口。

上层服务开发人员可根据Vibrator模块提供的统一接口，用于控制马达执行单次或周期性振动。

**Since:**

3.2

**Version:**

1.1

**相关模块:**

[Vibrator](vibrator.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [StartOnce](#startonce)&nbsp;([in]&nbsp;unsigned&nbsp;int&nbsp;duration) | 控制马达以执行给定持续时间的单次振动。 | 
| [Start](#start)&nbsp;([in]&nbsp;String&nbsp;effectType) | 控制马达以预置效果执行周期性振动。 | 
| [Stop](#stop)&nbsp;([in]&nbsp;enum&nbsp;[HdfVibratorMode](vibrator.md#hdfvibratormode)&nbsp;mode) | 停止马达振动。 | 
| [GetVibratorInfo](#getvibratorinfo)&nbsp;([out]&nbsp;struct&nbsp;[HdfVibratorInfo](_hdf_vibrator_info.md)[]&nbsp;vibratorInfo) | 获取有关系统中支持设置振幅和频率的所有马达信息。 | 
| [EnableVibratorModulation](#enablevibratormodulation)&nbsp;([in]&nbsp;unsigned&nbsp;int&nbsp;duration,&nbsp;[in]&nbsp;int&nbsp;intensity,&nbsp;[in]&nbsp;int&nbsp;frequency) | 根据传入的振动效果启动马达。 | 


## **成员函数说明**


### EnableVibratorModulation()

  
```
IVibratorInterface::EnableVibratorModulation ([in] unsigned int duration, [in] int intensity, [in] int frequency )
```

**描述：**

根据传入的振动效果启动马达。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| duration | 表示马达振动的持续时间，以毫秒为单位。 | 
| intensity | 表示振动周期内的马达振幅。 | 
| frequency | 表示振动周期内的马达频率。 | 

**返回:**

如果操作成功，则返回0。

如果不支持振动周期设置，则返回-1。

如果不支持振幅设置，则返回-2。

如果不支持频率设置，则返回-3。


### GetVibratorInfo()

  
```
IVibratorInterface::GetVibratorInfo ([out] struct HdfVibratorInfo[] vibratorInfo)
```

**描述：**

获取有关系统中支持设置振幅和频率的所有马达信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| vibratorInfo | 表示指向马达信息的指针，详见[HdfVibratorInfo](_hdf_vibrator_info.md)。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Start()

  
```
IVibratorInterface::Start ([in] String effectType)
```

**描述：**

控制马达以预置效果执行周期性振动。

单次振动与周期振动相互排斥。在执行周期性振动之前，需退出单次振动。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| effectType | 表示马达振动的预设效果类型。建议最大长度为64字节。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### StartOnce()

  
```
IVibratorInterface::StartOnce ([in] unsigned int duration)
```

**描述：**

控制马达以执行给定持续时间的单次振动。

单次振动与周期振动相互排斥。在执行单次振动之前，需退出周期性振动。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| duration | 表示单次振动的持续时间，以毫秒为单位。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### Stop()

  
```
IVibratorInterface::Stop ([in] enum HdfVibratorMode mode)
```

**描述：**

停止马达振动。

马达启动前，必须在任何模式下停止振动。此功能用在振动过程之后。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| mode | 表示振动模式，可以是单次或周期性的，详见[HdfVibratorMode](vibrator.md#hdfvibratormode)。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。
