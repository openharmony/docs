# Light


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [light_if.h](light__if_8h.md) | 声明light模块的通用API，可用于获取灯ID、打开或关闭灯、并设置灯光亮度和闪烁模式。 | 
| [light_type.h](light_8typeh.md) | 定义灯的数据结构，包括灯ID、灯的模式、灯的闪烁模式和持续时间、灯的状态、灯的效果。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [LightFlashEffect](_light_flash_effect.md) | 定义闪烁参数。&nbsp;[更多...](_light_flash_effect.md) | 
| [LightEffect](_light_effect.md) | 定义灯的效果参数。&nbsp;[更多...](_light_effect.md) | 
| [LightInfo](_light_info.md) | 定义灯的基本信息。&nbsp;[更多...](_light_info.md) | 
| [LightInterface](_light_interface.md) | 定义可以在灯上执行的基本操作。&nbsp;[更多...](_light_interface.md) | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [LightStatus](#lightstatus)&nbsp;{&nbsp;LIGHT_SUCCESS&nbsp;=&nbsp;0,&nbsp;LIGHT_NOT_SUPPORT&nbsp;=&nbsp;-1,&nbsp;LIGHT_NOT_FLASH&nbsp;=&nbsp;-2,&nbsp;LIGHT_NOT_BRIGHTNESS&nbsp;=&nbsp;-3&nbsp;} | 枚举灯模块的状态值。&nbsp;[更多...](#lightstatus) | 
| [LightId](#lightid)&nbsp;{&nbsp;LIGHT_ID_NONE&nbsp;=&nbsp;0,&nbsp;LIGHT_ID_BATTERY&nbsp;=&nbsp;1,&nbsp;LIGHT_ID_NOTIFICATIONS&nbsp;=&nbsp;2,&nbsp;LIGHT_ID_ATTENTION&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;LIGHT_ID_BUTT&nbsp;=&nbsp;4&nbsp;} | 枚举灯类型&nbsp;[更多...](#lightid) | 
| [LightFlashMode](#lightflashmode)&nbsp;{&nbsp;LIGHT_FLASH_NONE&nbsp;=&nbsp;0,&nbsp;LIGHT_FLASH_TIMED&nbsp;=&nbsp;1,&nbsp;LIGHT_FLASH_BUTT&nbsp;=&nbsp;2&nbsp;} | 枚举灯的模式&nbsp;[更多...](#lightflashmode) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [NewLightInterfaceInstance](#newlightinterfaceinstance)&nbsp;(void) | 创建LightInterface实例。&nbsp;[更多...](#newlightinterfaceinstance) | 
| [FreeLightInterfaceInstance](#freelightinterfaceinstance)&nbsp;(void) | 释放LightInterface实例和相关资源。&nbsp;[更多...](#freelightinterfaceinstance) | 


## **详细描述**

灯模块对灯服务提供通用的接口能力。

灯模块为灯服务提供通用的接口去访问灯驱动。 服务获取灯驱动对象或代理后，可以调用相关的APIs接口获取灯信息、打开或关闭灯，并根据灯ID设置灯闪烁模式。

**Since：**

3.1


## **枚举类型说明**


### LightFlashMode

  
```
enum LightFlashMode
```

**描述：**

枚举灯的模式

  | 枚举值 | 描述 | 
| -------- | -------- |
| LIGHT_FLASH_NONE | 常亮。 | 
| LIGHT_FLASH_TIMED | 闪烁。 | 
| LIGHT_FLASH_BUTT | 无效模式。 | 


### LightId

  
```
enum LightId
```

**描述：**

枚举灯类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| LIGHT_ID_NONE | 未知ID。 | 
| LIGHT_ID_BATTERY | 电源指示灯。 | 
| LIGHT_ID_NOTIFICATIONS | 通知灯。 | 
| LIGHT_ID_ATTENTION | 报警灯。 | 
| LIGHT_ID_BUTT | 无效ID。 | 


### LightStatus

  
```
enum LightStatus
```

**描述：**

枚举灯模块的状态值。

  | 枚举值 | 描述 | 
| -------- | -------- |
| LIGHT_SUCCESS | 操作成功。 | 
| LIGHT_NOT_SUPPORT | 灯ID不支持。 | 
| LIGHT_NOT_FLASH | 设置闪烁不支持。 | 
| LIGHT_NOT_BRIGHTNESS | 设置亮度不支持。 | 


## **函数说明**


### FreeLightInterfaceInstance()

  
```
int32_t FreeLightInterfaceInstance (void )
```

**描述：**

释放LightInterface实例和相关资源。

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since：**

3.1


### NewLightInterfaceInstance()

  
```
const struct LightInterface* NewLightInterfaceInstance (void )
```

**描述：**

创建LightInterface实例。

创建的LightInterface实例可用于执行相关的灯控制操作。

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

**Since：**

3.1
