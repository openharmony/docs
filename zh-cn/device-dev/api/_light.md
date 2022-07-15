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
| [LightStatus](#lightstatus)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref669817133083931,link:zh-cn_topic_0000001295094348.xml#gga7e734c01235aff210cae379b12e53e9da232a2bb4a97420c327e6f3ea0551eba9](#gga7e734c01235aff210cae379b12e53e9da232a2bb4a97420c327e6f3ea0551eba9)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref1922765945083931,link:zh-cn_topic_0000001295094348.xml#gga7e734c01235aff210cae379b12e53e9daa45f0187f0b5768ad0925ded9c89571a](#gga7e734c01235aff210cae379b12e53e9daa45f0187f0b5768ad0925ded9c89571a)&nbsp;=&nbsp;-1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref2144622860083931,link:zh-cn_topic_0000001295094348.xml#gga7e734c01235aff210cae379b12e53e9daf0b19776befd37739b12cf23d170ff30](#gga7e734c01235aff210cae379b12e53e9daf0b19776befd37739b12cf23d170ff30)&nbsp;=&nbsp;-2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref707352116083931,link:zh-cn_topic_0000001295094348.xml#gga7e734c01235aff210cae379b12e53e9dad2f1173892e1d07a8126c6c35a999a37](#gga7e734c01235aff210cae379b12e53e9dad2f1173892e1d07a8126c6c35a999a37)&nbsp;=&nbsp;-3&nbsp;} | 枚举灯模块的状态值。&nbsp;[更多...](#lightstatus) | 
| [LightId](#lightid)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref683206926083931,link:zh-cn_topic_0000001295094348.xml#gga8af1cb654f32fb5377425257b28748e5ac983420abafcd5130c932b845974f99b](#gga8af1cb654f32fb5377425257b28748e5ac983420abafcd5130c932b845974f99b)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref850328663083931,link:zh-cn_topic_0000001295094348.xml#gga8af1cb654f32fb5377425257b28748e5af15783cc343be88bf3008341ac0c6625](#gga8af1cb654f32fb5377425257b28748e5af15783cc343be88bf3008341ac0c6625)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref1639689805083931,link:zh-cn_topic_0000001295094348.xml#gga8af1cb654f32fb5377425257b28748e5a0130b68a96276084c65827c34a4e396d](#gga8af1cb654f32fb5377425257b28748e5a0130b68a96276084c65827c34a4e396d)&nbsp;=&nbsp;2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref1331872722083931,link:zh-cn_topic_0000001295094348.xml#gga8af1cb654f32fb5377425257b28748e5a3b03c358d0573b293fe648cf349e7083](#gga8af1cb654f32fb5377425257b28748e5a3b03c358d0573b293fe648cf349e7083)&nbsp;=&nbsp;3,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref1112243301083931,link:zh-cn_topic_0000001295094348.xml#gga8af1cb654f32fb5377425257b28748e5a25137b2ac5c4e6dc4f5edc47f175e38c](#gga8af1cb654f32fb5377425257b28748e5a25137b2ac5c4e6dc4f5edc47f175e38c)&nbsp;=&nbsp;4&nbsp;} | 枚举灯类型&nbsp;[更多...](#lightid) | 
| [LightFlashMode](#lightflashmode)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref1338345588083931,link:zh-cn_topic_0000001295094348.xml#ggaacf9823c64514a279833614add26ab5da72520ea2652cf669185239981de8a6f0](#ggaacf9823c64514a279833614add26ab5da72520ea2652cf669185239981de8a6f0)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref1733020795083931,link:zh-cn_topic_0000001295094348.xml#ggaacf9823c64514a279833614add26ab5da3d4dc48f86b6635811e497e5a27f475c](#ggaacf9823c64514a279833614add26ab5da3d4dc48f86b6635811e497e5a27f475c)&nbsp;=&nbsp;1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094348.xml#xref444541071083931,link:zh-cn_topic_0000001295094348.xml#ggaacf9823c64514a279833614add26ab5da87ae168f921bbab98e18bf80f7d9b8d5](#ggaacf9823c64514a279833614add26ab5da87ae168f921bbab98e18bf80f7d9b8d5)&nbsp;=&nbsp;2&nbsp;} | 枚举灯的模式&nbsp;[更多...](#lightflashmode) | 


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
