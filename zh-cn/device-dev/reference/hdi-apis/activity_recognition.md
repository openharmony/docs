# HdiActivityRecognition


## **概述**

提供订阅和获取用户行为的API。

MSDP（Multimodal Sensor Data Platform）可以获取行为识别驱动程序的对象或代理，然后调用该对象或代理提供的API， 获取设备支持的行为类型，订阅或取消订阅不同的行为事件，获取当前的行为事件，以及获取设备缓存的行为事件。

**Since**:

3.2

**Version**:

1.0


## **汇总**


### 文件

  | 名称 | 描述 | 
| -------- | -------- |
| [ActivityRecognitionTypes.idl](activity_recognition_types_idl.md) | 定义行为识别模块使用的数据类型。 | 
| [IActivityChangedCallback.idl](_i_activity_changed_callback_8idl.md) | 定义行为识别数据上报回调函数接口。 | 
| [IActivityInterface.idl](_i_activity_interface_8idl.md) | 声明行为识别模块提供的API，用于获取设备支持的行为类型，订阅或取消订阅不同的行为事件，获取当前的行为事件，以及获取设备缓存的行为事件。 | 


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [ActRecognitionEvent](_act_recognition_event.md) | 定义行为事件上报的数据结构。 | 
| [IActivityChangedCallback](interface_i_activity_changed_callback.md) | 定义上报行为事件的回调函数。 | 
| [IActivityInterface](interface_i_activity_interface.md) | 定义对行为识别进行基本操作的接口。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [ActRecognitionEventType](#actrecognitioneventtype)&nbsp;{&nbsp;ACT_RECOGNITION_EVENT_ENTER&nbsp;=&nbsp;0x01,&nbsp;ACT_RECOGNITION_EVENT_EXIT&nbsp;=&nbsp;0x02&nbsp;} | 枚举行为事件的类型。 | 
| [ActRecognitionPowerMode](#actrecognitionpowermode)&nbsp;{&nbsp;ACT_RECOGNITION_NORMAL_MODE&nbsp;=&nbsp;0,&nbsp;ACT_RECOGNITION_LOW_POWER_MODE&nbsp;=&nbsp;1&nbsp;} | 枚举功耗模式的类型。 | 


### 关键字

  | 名称 | 描述 | 
| -------- | -------- |
| package&nbsp;ohos.hdi.activity_recognition.v1_0 | 行为识别模块接口的包路径。 | 


## **枚举类型说明**


### ActRecognitionEventType

  
```
enum ActRecognitionEventType
```

**描述：**

枚举行为事件的类型。

支持的行为包括：车载、骑车、步行、跑步、静止、快走、高铁、未知、电梯、相对静止、手持步行、躺卧、乘机、地铁等。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ACT_RECOGNITION_EVENT_ENTER | 进入某一行为 | 
| ACT_RECOGNITION_EVENT_EXIT | 退出某一行为 | 


### ActRecognitionPowerMode

  
```
enum ActRecognitionPowerMode
```

**描述：**

枚举功耗模式的类型。

  | 枚举值 | 描述 | 
| -------- | -------- |
| ACT_RECOGNITION_NORMAL_MODE | 普通模式，不论主核是否休眠都会进行行为事件的上报。 | 
| ACT_RECOGNITION_LOW_POWER_MODE | 低功耗模式，主核休眠时，不会进行行为事件的上报。 | 
