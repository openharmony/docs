# IInputInterface


## **概述**

定义用于提供Input设备驱动程序功能的接口。

**相关模块:**

[Input](input.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| [iInputManager](#iinputmanager) | Input设备的设备管理接口 | 
| [iInputController](#iinputcontroller) | Input设备的业务控制接口 | 
| [iInputReporter](#iinputreporter) | Input设备的数据上报接口 | 


## **类成员变量说明**


### iInputController

  
```
InputController* IInputInterface::iInputController
```

**描述：**

Input设备的业务控制接口


### iInputManager

  
```
InputManager* IInputInterface::iInputManager
```

**描述：**

Input设备的设备管理接口


### iInputReporter

  
```
InputReporter* IInputInterface::iInputReporter
```

**描述：**

Input设备的数据上报接口
