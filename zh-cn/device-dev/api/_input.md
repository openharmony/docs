# Input


## **汇总**


### 文件

  | 文件 | 描述 | 
| -------- | -------- |
| [input_controller.h](input__controller_8h.md) | 描述input设备业务控制相关的接口声明。 | 
| [input_manager.h](input__manager_8h.md) | 描述input设备管理相关的接口声明。 | 
| [input_reporter.h](input__reporter_8h.md) | 描述input设备数据上报相关的接口声明。 | 
| [input_type.h](input__type_8h.md) | input设备相关的类型定义，定义了input设备驱动接口所使用的结构体及枚举类型。 | 


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [InputController](_input_controller.md) | 提供input设备业务控制相关的接口。&nbsp;[更多...](_input_controller.md) | 
| [InputManager](_input_manager.md) | 提供input设备管理相关的接口。&nbsp;[更多...](_input_manager.md) | 
| [IInputInterface](_i_input_interface.md) | 定义用于提供输入设备驱动能力的接口。[更多...](_i_input_interface.md) | 
| [InputReporter](_input_reporter.md) | 提供input设备数据上报相关的接口。&nbsp;[更多...](_input_reporter.md) | 
| [EventPackage](_event_package.md) | input事件数据包结构&nbsp;[更多...](_event_package.md) | 
| [InputReportEventCb](_input_report_event_cb.md) | 此结构体定义了输入事件回调函数并提供给input服务使用&nbsp;[更多...](_input_report_event_cb.md) | 
| [DeviceInfo](_device_info.md) | input设备基础设备信息&nbsp;[更多...](_device_info.md) | 
| [InputExtraCmd](_input_extra_cmd.md) | 扩展指令的数据结构&nbsp;[更多...](_input_extra_cmd.md) | 


### 宏定义

  | 宏定义 | 描述 | 
| -------- | -------- |
| **MAX_INPUT_DEV_NUM**&nbsp;&nbsp;&nbsp;32 | Input设备最大数量。 | 
| **MAX_NODE_PATH_LEN**&nbsp;&nbsp;&nbsp;64 | 节点路径最大长度。 | 
| **CHIP_INFO_LEN**&nbsp;&nbsp;&nbsp;10 | 芯片信息长度。 | 
| **CHIP_NAME_LEN**&nbsp;&nbsp;&nbsp;10 | 芯片名称长度。 | 
| **VENDOR_NAME_LEN**&nbsp;&nbsp;&nbsp;10 | 厂商名称长度。 | 
| **SELF_TEST_RESULT_LEN**&nbsp;&nbsp;&nbsp;20 | 自测结果长度。 | 


### 枚举

  | 枚举 | 描述 | 
| -------- | -------- |
| [RetStatus](#retstatus)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1300857390083931,link:zh-cn_topic_0000001295094392.xml#gga85d58a5185669daa4995e332b63eba7aa4b6c3821e689826c4323c4eb759b4d3a](#gga85d58a5185669daa4995e332b63eba7aa4b6c3821e689826c4323c4eb759b4d3a)&nbsp;=&nbsp;0,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1409989604083931,link:zh-cn_topic_0000001295094392.xml#gga85d58a5185669daa4995e332b63eba7aa07d986b0ee365020834af82a31dfce11](#gga85d58a5185669daa4995e332b63eba7aa07d986b0ee365020834af82a31dfce11)&nbsp;=&nbsp;-1,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref452864304083931,link:zh-cn_topic_0000001295094392.xml#gga85d58a5185669daa4995e332b63eba7aa5f54ab958e21a298da35c3c5c1c36d85](#gga85d58a5185669daa4995e332b63eba7aa5f54ab958e21a298da35c3c5c1c36d85)&nbsp;=&nbsp;-2,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref961590603083931,link:zh-cn_topic_0000001295094392.xml#gga85d58a5185669daa4995e332b63eba7aaddf6c11b0fac107e0123b83cfc4a1185](#gga85d58a5185669daa4995e332b63eba7aaddf6c11b0fac107e0123b83cfc4a1185)&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref924512393083931,link:zh-cn_topic_0000001295094392.xml#gga85d58a5185669daa4995e332b63eba7aa157cd4f4736dd1f05eb2e13dbc7123ed](#gga85d58a5185669daa4995e332b63eba7aa157cd4f4736dd1f05eb2e13dbc7123ed)&nbsp;=&nbsp;-4,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1348525150083931,link:zh-cn_topic_0000001295094392.xml#gga85d58a5185669daa4995e332b63eba7aabdaeb2a27983bd66ff6e24d4df255f59](#gga85d58a5185669daa4995e332b63eba7aabdaeb2a27983bd66ff6e24d4df255f59)&nbsp;=&nbsp;-5,&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1671886965083931,link:zh-cn_topic_0000001295094392.xml#gga85d58a5185669daa4995e332b63eba7aa8978f7ee3d0ddd70f5077c21efc4a97a](#gga85d58a5185669daa4995e332b63eba7aa8978f7ee3d0ddd70f5077c21efc4a97a)&nbsp;=&nbsp;-6&nbsp;} | 定义返回值类型&nbsp;[更多...](#retstatus) | 
| [InputDevType](#inputdevtype)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1555941679083931,link:zh-cn_topic_0000001295094392.xml#ggaa8225ba155dfa1ef2c4119c832bc4dd3a621678554aac2b37ac244b80fc33da0d](#ggaa8225ba155dfa1ef2c4119c832bc4dd3a621678554aac2b37ac244b80fc33da0d),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref490402822083931,link:zh-cn_topic_0000001295094392.xml#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4c4c8407342021cc06a95aa13ebeaca1](#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4c4c8407342021cc06a95aa13ebeaca1),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref233720602083931,link:zh-cn_topic_0000001295094392.xml#ggaa8225ba155dfa1ef2c4119c832bc4dd3a3a4137efe666a3aaccf267d597879fdc](#ggaa8225ba155dfa1ef2c4119c832bc4dd3a3a4137efe666a3aaccf267d597879fdc),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1190476620083931,link:zh-cn_topic_0000001295094392.xml#ggaa8225ba155dfa1ef2c4119c832bc4dd3abe68740c1d125d3d474fdadc7d31d11c](#ggaa8225ba155dfa1ef2c4119c832bc4dd3abe68740c1d125d3d474fdadc7d31d11c),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1309699275083931,link:zh-cn_topic_0000001295094392.xml#ggaa8225ba155dfa1ef2c4119c832bc4dd3a2815a25dde3e56e1f8eb57f20049e8c0](#ggaa8225ba155dfa1ef2c4119c832bc4dd3a2815a25dde3e56e1f8eb57f20049e8c0),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1202673028083931,link:zh-cn_topic_0000001295094392.xml#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4ef2ab6bc355e2321664709716d1d04f](#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4ef2ab6bc355e2321664709716d1d04f),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref2038943016083931,link:zh-cn_topic_0000001295094392.xml#ggaa8225ba155dfa1ef2c4119c832bc4dd3a8cd6b27ac631b9d3fa89a17ddca37291](#ggaa8225ba155dfa1ef2c4119c832bc4dd3a8cd6b27ac631b9d3fa89a17ddca37291),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref753753548083931,link:zh-cn_topic_0000001295094392.xml#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4097247eba52062f47a1aa99414033de](#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4097247eba52062f47a1aa99414033de)&nbsp;} | 定义input设备类型&nbsp;[更多...](#inputdevtype) | 
| [PowerStatus](#powerstatus)&nbsp;{&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref2104217090083931,link:zh-cn_topic_0000001295094392.xml#gga65e6bb4d942c22dba9975253b0a1d73fa5edb1acdc509659046de9cb61bd9508a](#gga65e6bb4d942c22dba9975253b0a1d73fa5edb1acdc509659046de9cb61bd9508a),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref612508396083931,link:zh-cn_topic_0000001295094392.xml#gga65e6bb4d942c22dba9975253b0a1d73fa2a6aab1b3d50dae2b6ba43779e185ea5](#gga65e6bb4d942c22dba9975253b0a1d73fa2a6aab1b3d50dae2b6ba43779e185ea5),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1485213206083931,link:zh-cn_topic_0000001295094392.xml#gga65e6bb4d942c22dba9975253b0a1d73fa8895c64802d558830d46bcd921830e9d](#gga65e6bb4d942c22dba9975253b0a1d73fa8895c64802d558830d46bcd921830e9d),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1055889242083931,link:zh-cn_topic_0000001295094392.xml#gga65e6bb4d942c22dba9975253b0a1d73fa728020b31c626f749d426cbe8f0f92fe](#gga65e6bb4d942c22dba9975253b0a1d73fa728020b31c626f749d426cbe8f0f92fe)&nbsp;} | 定义电源状态&nbsp;[更多...](#powerstatus) | 
| [CapacitanceTest](#capacitancetest)&nbsp;{&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref188734445083931,link:zh-cn_topic_0000001295094392.xml#ggae96e484cfd64ea37b5b7782f57f38a21aedd31f50c79a36cc8e084d69a3fc695b](#ggae96e484cfd64ea37b5b7782f57f38a21aedd31f50c79a36cc8e084d69a3fc695b),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref335398850083931,link:zh-cn_topic_0000001295094392.xml#ggae96e484cfd64ea37b5b7782f57f38a21abfe92c879dc84b5b071899a7ec5cc41d](#ggae96e484cfd64ea37b5b7782f57f38a21abfe92c879dc84b5b071899a7ec5cc41d),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1929415567083931,link:zh-cn_topic_0000001295094392.xml#ggae96e484cfd64ea37b5b7782f57f38a21a93335d88212604ade3b0bfe7e619916f](#ggae96e484cfd64ea37b5b7782f57f38a21a93335d88212604ade3b0bfe7e619916f),&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref2014653915083931,link:zh-cn_topic_0000001295094392.xml#ggae96e484cfd64ea37b5b7782f57f38a21a31afc25da895db4eaa2af6cec1d6b37c](#ggae96e484cfd64ea37b5b7782f57f38a21a31afc25da895db4eaa2af6cec1d6b37c),&nbsp;&nbsp;&nbsp;[ERROR:Invalid&nbsp;link:zh-cn_topic_0000001295094392.xml#xref1192159830083931,link:zh-cn_topic_0000001295094392.xml#ggae96e484cfd64ea37b5b7782f57f38a21a9d739cecefd291b39152e3815445aa20](#ggae96e484cfd64ea37b5b7782f57f38a21a9d739cecefd291b39152e3815445aa20)&nbsp;} | 定义容值测试类型&nbsp;[更多...](#capacitancetest) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [GetInputInterface](#getinputinterface)&nbsp;([IInputInterface](_i_input_interface.md)&nbsp;\*\*interface) | input服务通过调用此接口获取操作input设备的所有接口。&nbsp;[更多...](#getinputinterface) | 


## **详细描述**

Input模块驱动接口声明。

本模块为Input服务提供相关驱动接口，包括input设备的打开和关闭、input事件获取、设备信息查询、回调函数注册、特性状态控制等接口。

**Since：**

1.0

**Version：**

1.0


## **枚举类型说明**


### CapacitanceTest

  
```
enum CapacitanceTest
```

**描述：**

定义容值测试类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| BASE_TEST | 基础容值测试 | 
| FULL_TEST | 全量容值自检测试 | 
| MMI_TEST | MMI容值测试 | 
| RUNNING_TEST | 老化容值测试 | 
| TEST_TYPE_UNKNOWN | 未知的测试类型 | 


### InputDevType

  
```
enum InputDevType
```

**描述：**

定义input设备类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| INDEV_TYPE_TOUCH | 触摸屏。 | 
| INDEV_TYPE_KEY | 物理按键。 | 
| INDEV_TYPE_KEYBOARD | 键盘。 | 
| INDEV_TYPE_MOUSE | 鼠标。 | 
| INDEV_TYPE_BUTTON | 虚拟按键。 | 
| INDEV_TYPE_CROWN | 表冠。 | 
| INDEV_TYPE_ENCODER | 自定义编码的特定功能或者事件。 | 
| INDEV_TYPE_UNKNOWN | 未知输入设备类型。 | 


### PowerStatus

  
```
enum PowerStatus
```

**描述：**

定义电源状态

  | 枚举值 | 描述 | 
| -------- | -------- |
| INPUT_RESUME | 正常唤醒。 | 
| INPUT_SUSPEND | 休眠下电模式。 | 
| INPUT_LOW_POWER | 休眠低功耗模式。 | 
| INPUT_POWER_STATUS_UNKNOWN | 未知电源状态。 | 


### RetStatus

  
```
enum RetStatus
```

**描述：**

定义返回值类型

  | 枚举值 | 描述 | 
| -------- | -------- |
| INPUT_SUCCESS | 成功。 | 
| INPUT_FAILURE | 失败。 | 
| INPUT_INVALID_PARAM | 无效参数。 | 
| INPUT_NOMEM | 内存不足。 | 
| INPUT_NULL_PTR | 空指针。 | 
| INPUT_TIMEOUT | 执行超时。 | 
| INPUT_UNSUPPORTED | 特性不支持。 | 


## **函数说明**


### GetInputInterface()

  
```
int32_t GetInputInterface (IInputInterface **interface)
```

**描述：**

input服务通过调用此接口获取操作input设备的所有接口。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| interface | 对input设备进行接口操作的指针，通常在input服务启动后，通过调用此函数获取input设备操作接口 | 

**返回：**

Returns INPUT_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

**Since：**

1.0

**Version：**

1.0
