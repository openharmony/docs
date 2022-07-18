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

  | 枚举名称 | 描述 | 
| -------- | -------- |
| [RetStatus](_input.md#retstatus)&nbsp;{&nbsp;INPUT_SUCCESS&nbsp;=&nbsp;0,&nbsp;INPUT_FAILURE&nbsp;=&nbsp;-1,&nbsp;INPUT_INVALID_PARAM&nbsp;=&nbsp;-2,&nbsp;INPUT_NOMEM&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;INPUT_NULL_PTR&nbsp;=&nbsp;-4,&nbsp;INPUT_TIMEOUT&nbsp;=&nbsp;-5,&nbsp;INPUT_UNSUPPORTED&nbsp;=&nbsp;-6&nbsp;} | 定义返回值类型&nbsp;[更多...](_input.md#retstatus) | 
| [InputDevType](_input.md#inputdevtype)&nbsp;{&nbsp;INDEV_TYPE_TOUCH,&nbsp;INDEV_TYPE_KEY,&nbsp;INDEV_TYPE_KEYBOARD,&nbsp;INDEV_TYPE_MOUSE,&nbsp;&nbsp;&nbsp;INDEV_TYPE_BUTTON,&nbsp;INDEV_TYPE_CROWN,&nbsp;INDEV_TYPE_ENCODER,&nbsp;INDEV_TYPE_UNKNOWN&nbsp;} | 定义input设备类型&nbsp;[更多...](_input.md#inputdevtype) | 
| [PowerStatus](_input.md#powerstatus)&nbsp;{&nbsp;INPUT_RESUME,&nbsp;INPUT_SUSPEND,&nbsp;INPUT_LOW_POWER,&nbsp;INPUT_POWER_STATUS_UNKNOWN&nbsp;} | 定义电源状态&nbsp;[更多...](_input.md#powerstatus) | 
| [CapacitanceTest](_input.md#capacitancetest)&nbsp;{&nbsp;BASE_TEST,&nbsp;FULL_TEST,&nbsp;MMI_TEST,&nbsp;RUNNING_TEST,&nbsp;&nbsp;&nbsp;TEST_TYPE_UNKNOWN&nbsp;} | 定义容值测试类型&nbsp;[更多...](_input.md#capacitancetest) | 


## **详细描述**

input设备相关的类型定义，定义了input设备驱动接口所使用的结构体及枚举类型。

**Since：**

1.0

**Version：**

1.0
