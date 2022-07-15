# input_type.h


## **概述**

**所属模块:**

[Input](_input.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
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
| [RetStatus](_input.md#retstatus)&nbsp;{&nbsp;&nbsp;&nbsp;[INPUT_SUCCESS](_input.md#gga85d58a5185669daa4995e332b63eba7aa4b6c3821e689826c4323c4eb759b4d3a)&nbsp;=&nbsp;0,&nbsp;[INPUT_FAILURE](_input.md#gga85d58a5185669daa4995e332b63eba7aa07d986b0ee365020834af82a31dfce11)&nbsp;=&nbsp;-1,&nbsp;[INPUT_INVALID_PARAM](_input.md#gga85d58a5185669daa4995e332b63eba7aa5f54ab958e21a298da35c3c5c1c36d85)&nbsp;=&nbsp;-2,&nbsp;[INPUT_NOMEM](_input.md#gga85d58a5185669daa4995e332b63eba7aaddf6c11b0fac107e0123b83cfc4a1185)&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;[INPUT_NULL_PTR](_input.md#gga85d58a5185669daa4995e332b63eba7aa157cd4f4736dd1f05eb2e13dbc7123ed)&nbsp;=&nbsp;-4,&nbsp;[INPUT_TIMEOUT](_input.md#gga85d58a5185669daa4995e332b63eba7aabdaeb2a27983bd66ff6e24d4df255f59)&nbsp;=&nbsp;-5,&nbsp;[INPUT_UNSUPPORTED](_input.md#gga85d58a5185669daa4995e332b63eba7aa8978f7ee3d0ddd70f5077c21efc4a97a)&nbsp;=&nbsp;-6&nbsp;} | 定义返回值类型&nbsp;[更多...](_input.md#retstatus) | 
| [InputDevType](_input.md#inputdevtype)&nbsp;{&nbsp;&nbsp;&nbsp;[INDEV_TYPE_TOUCH](_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a621678554aac2b37ac244b80fc33da0d),&nbsp;[INDEV_TYPE_KEY](_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4c4c8407342021cc06a95aa13ebeaca1),&nbsp;[INDEV_TYPE_KEYBOARD](_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a3a4137efe666a3aaccf267d597879fdc),&nbsp;[INDEV_TYPE_MOUSE](_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3abe68740c1d125d3d474fdadc7d31d11c),&nbsp;&nbsp;&nbsp;[INDEV_TYPE_BUTTON](_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a2815a25dde3e56e1f8eb57f20049e8c0),&nbsp;[INDEV_TYPE_CROWN](_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4ef2ab6bc355e2321664709716d1d04f),&nbsp;[INDEV_TYPE_ENCODER](_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a8cd6b27ac631b9d3fa89a17ddca37291),&nbsp;[INDEV_TYPE_UNKNOWN](_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4097247eba52062f47a1aa99414033de)&nbsp;} | 定义input设备类型&nbsp;[更多...](_input.md#inputdevtype) | 
| [PowerStatus](_input.md#powerstatus)&nbsp;{&nbsp;[INPUT_RESUME](_input.md#gga65e6bb4d942c22dba9975253b0a1d73fa5edb1acdc509659046de9cb61bd9508a),&nbsp;[INPUT_SUSPEND](_input.md#gga65e6bb4d942c22dba9975253b0a1d73fa2a6aab1b3d50dae2b6ba43779e185ea5),&nbsp;[INPUT_LOW_POWER](_input.md#gga65e6bb4d942c22dba9975253b0a1d73fa8895c64802d558830d46bcd921830e9d),&nbsp;[INPUT_POWER_STATUS_UNKNOWN](_input.md#gga65e6bb4d942c22dba9975253b0a1d73fa728020b31c626f749d426cbe8f0f92fe)&nbsp;} | 定义电源状态&nbsp;[更多...](_input.md#powerstatus) | 
| [CapacitanceTest](_input.md#capacitancetest)&nbsp;{&nbsp;&nbsp;&nbsp;[BASE_TEST](_input.md#ggae96e484cfd64ea37b5b7782f57f38a21aedd31f50c79a36cc8e084d69a3fc695b),&nbsp;[FULL_TEST](_input.md#ggae96e484cfd64ea37b5b7782f57f38a21abfe92c879dc84b5b071899a7ec5cc41d),&nbsp;[MMI_TEST](_input.md#ggae96e484cfd64ea37b5b7782f57f38a21a93335d88212604ade3b0bfe7e619916f),&nbsp;[RUNNING_TEST](_input.md#ggae96e484cfd64ea37b5b7782f57f38a21a31afc25da895db4eaa2af6cec1d6b37c),&nbsp;&nbsp;&nbsp;[TEST_TYPE_UNKNOWN](_input.md#ggae96e484cfd64ea37b5b7782f57f38a21a9d739cecefd291b39152e3815445aa20)&nbsp;} | 定义容值测试类型&nbsp;[更多...](_input.md#capacitancetest) | 


## **详细描述**

input设备相关的类型定义，定义了input设备驱动接口所使用的结构体及枚举类型。

**Since：**

1.0

**Version：**

1.0
