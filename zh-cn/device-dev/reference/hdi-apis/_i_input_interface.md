# IInputInterface


## **概述**

**所属模块:**

[Input](_input.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [iInputManager](#iinputmanager) | input设备的设备管理接口。 | 
| [iInputController](#iinputcontroller) | input设备的业务控制接口。 | 
| [iInputReporter](#iinputreporter) | input设备的数据上报接口。 | 


## **详细描述**

定义用于提供输入设备驱动能力的接口。


## **类成员变量说明**


### iInputController

  
```
InputController* IInputInterface::iInputController
```

**描述：**

input设备的业务控制接口


### iInputManager

  
```
InputManager* IInputInterface::iInputManager
```

**描述：**

input设备的设备管理接口


### iInputReporter

  
```
InputReporter* IInputInterface::iInputReporter
```

**描述：**

input设备的数据上报接口
