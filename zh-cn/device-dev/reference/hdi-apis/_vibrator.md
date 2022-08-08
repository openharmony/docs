# Vibrator


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [vibrator_if.h](vibrator__if_8h.md) | 定义马达数据结构，包括马达模式和效果振动。 | 
| [vibrator_type.h](vibrator__type_8h.md) | 定义马达数据结构，包括马达模式和效果振动。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [VibratorInterface](_vibrator_interface.md) | 提供Vibrator设备基本控制操作接口。[更多...](_vibrator_interface.md) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [VibratorMode](#vibratormode)&nbsp;{&nbsp;VIBRATOR_MODE_ONCE&nbsp;=&nbsp;0,&nbsp;VIBRATOR_MODE_PRESET&nbsp;=&nbsp;1,&nbsp;VIBRATOR_MODE_BUTT&nbsp;} | 枚举马达振动模式。&nbsp;[更多...](#vibratormode) | 
| [VibratorStatus](#vibratorstatus)&nbsp;{&nbsp;VIBRATOR_SUCCESS&nbsp;=&nbsp;0,&nbsp;VIBRATOR_NOT_PERIOD&nbsp;=&nbsp;-1,&nbsp;&nbsp;VIBRATOR_NOT_INTENSITY&nbsp;&nbsp;=&nbsp;-2,&nbsp;&nbsp;VIBRATOR_NOT_FREQUENCY=&nbsp;-3} | 枚举马达振动模式。[更多...](#vibratorstatus) | 
| [VibratorInfo](#vibratorinfo)&nbsp;{&nbsp;isSupportIntensity,&nbsp;isSupportFrequency,&nbsp;intensityMaxValue,&nbsp;intensityMinValue,&nbsp;frequencyMaxValue,&nbsp;frequencyMinValue} | 定义马达参数。[更多...](#vibratorinfo) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [NewVibratorInterfaceInstance](#newvibratorinterfaceinstance)&nbsp;(void) | 创建一个VibratorInterface实例。&nbsp;[更多...](#newvibratorinterfaceinstance) | 
| [FreeVibratorInterfaceInstance](#freevibratorinterfaceinstance)&nbsp;(void) | 释放VibratorInterface实例以及相关资源。&nbsp;[更多...](#freevibratorinterfaceinstance) | 


## **详细描述**

马达驱动对马达服务提供通用的接口能力。

服务获取驱动对象或者代理后，马达服务启动或停止振动。 通过驱动程序对象或代理提供使用功能。

**Since：**

2.2

**版本**

1.0:


## **枚举类型说明**


### VibratorMode

  
```
enum VibratorMode
```

**描述：**

枚举马达振动模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VIBRATOR_MODE_ONCE | 表示给定持续时间内的一次性振动。 | 
| VIBRATOR_MODE_PRESET | 表示具有预置效果的周期性振动。 | 
| VIBRATOR_MODE_BUTT | 表示效果模式无效。 | 


### VibratorStatus

  
```
enum VibratorStatus
```

**描述：**

枚举马达振动模式。

  | 枚举值 | 描述 | 
| -------- | -------- |
| VIBRATOR_SUCCESS | 操作成功。 | 
| VIBRATOR_NOT_PERIOD | 不支持振动周期设置。 | 
| VIBRATOR_NOT_INTENSITY | 不支持振幅设置。 | 
| VIBRATOR_NOT_FREQUENCY | 不支持频率设置。 | 


### VibratorInfo

  
```
enum VibratorInfo
```

**描述：**

定义马达参数。

参数包括设置马达振幅和频率以及振幅和频率的范围。

  | 枚举值 | 描述 | 
| -------- | -------- |
| isSupportIntensity | 设置马达振幅。1表示支持，0表示不支持。 | 
| isSupportFrequency | 设置马达频率。1表示支持，0表示不支持。 | 
| intensityMaxValue | 最大振幅。 | 
| intensityMinValue | 最小振幅。 | 
| frequencyMaxValue | 最大频率。 | 
| frequencyMinValue | 最小频率。 | 


## **函数说明**


### FreeVibratorInterfaceInstance()

  
```
int32_t FreeVibratorInterfaceInstance (void )
```

**描述：**

释放VibratorInterface实例以及相关资源。

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since：**

2.2

**Version：**

1.0


### NewVibratorInterfaceInstance()

  
```
const struct VibratorInterface* NewVibratorInterfaceInstance (void )
```

**描述：**

创建一个VibratorInterface实例。

获的马达接口实例可用于控制马达按照配置进行振动。

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since：**

2.2

**Version：**

1.0
