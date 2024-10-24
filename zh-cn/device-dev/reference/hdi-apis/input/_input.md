# Input


## 概述

Input模块驱动接口声明。

本模块为Input服务提供相关驱动接口，包括Input设备的打开和关闭、Input事件获取、设备信息查询、回调函数注册、特性状态控制等接口。

**起始版本：** 1.0


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [input_controller.h](input__controller_8h.md) | 描述Input设备业务控制相关的接口声明。 | 
| [input_manager.h](input__manager_8h.md) | 描述Input设备管理相关的接口声明。 | 
| [input_reporter.h](input__reporter_8h.md) | 描述Input设备数据上报相关的接口声明。 | 
| [input_type.h](input__type_8h.md) | Input设备相关的类型定义，定义了Input设备驱动接口所使用的结构体及枚举类型。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[InputController](_input_controller.md) | 提供Input设备业务控制相关的接口。 | 
| struct&nbsp;&nbsp;[InputManager](_input_manager.md) | 提供Input设备管理相关的接口。 | 
| struct&nbsp;&nbsp;[IInputInterface](_i_input_interface.md) | 定义用于提供Input设备驱动程序功能的接口。 | 
| struct&nbsp;&nbsp;[InputReporter](_input_reporter.md) | 提供Input设备数据上报相关的接口。 | 
| struct&nbsp;&nbsp;[InputEventPackage](_input_event_package.md) | Input事件数据包结构。 | 
| struct&nbsp;&nbsp;[InputHotPlugEvent](_input_hot_plug_event.md) | 热插拔事件数据包结构。 | 
| struct&nbsp;&nbsp;[InputDevDesc](_input_dev_desc.md) | Input设备描述信息。 | 
| struct&nbsp;&nbsp;[InputEventCb](_input_event_cb.md) | 此结构体定义了输入事件回调函数并提供给Input服务使用。 | 
| struct&nbsp;&nbsp;[InputHostCb](_input_host_cb.md) | 此结构体定义了热插拔事件上报回调函数并提供给Input服务使用。 | 
| struct&nbsp;&nbsp;[InputDevAbility](_input_dev_ability.md) | Input设备的能力属性，存储支持事件的位图。 | 
| struct&nbsp;&nbsp;[InputDimensionInfo](_input_dimension_info.md) | Input设备的维度信息。 | 
| struct&nbsp;&nbsp;[InputDevIdentify](_input_dev_identify.md) | Input设备的识别信息。 | 
| struct&nbsp;&nbsp;[InputDevAttr](_input_dev_attr.md) | Input设备属性。 | 
| struct&nbsp;&nbsp;[InputDeviceInfo](_input_device_info.md) | Input设备基础设备信息。 | 
| struct&nbsp;&nbsp;[InputExtraCmd](_input_extra_cmd.md) | 扩展指令的数据结构。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [MAX_INPUT_DEV_NUM](#max_input_dev_num)&nbsp;&nbsp;&nbsp;32 | Input设备数量的最大值。 | 
| [CHIP_INFO_LEN](#chip_info_len)&nbsp;&nbsp;&nbsp;10 | 芯片信息长度。 | 
| [CHIP_NAME_LEN](#chip_name_len)&nbsp;&nbsp;&nbsp;10 | 芯片名称长度。 | 
| [VENDOR_NAME_LEN](#vendor_name_len)&nbsp;&nbsp;&nbsp;10 | 厂商名称长度。 | 
| [DEV_NAME_LEN](#dev_name_len)&nbsp;&nbsp;&nbsp;64 | Input设备名称长度。 | 
| [SELF_TEST_RESULT_LEN](#self_test_result_len)&nbsp;&nbsp;&nbsp;20 | 自测结果长度。 | 
| [DEV_MANAGER_SERVICE_NAME](#dev_manager_service_name)&nbsp;&nbsp;&nbsp;"hdf_input_host" | Input设备节点服务名称。 | 
| [DIV_ROUND_UP](#div_round_up)(nr, d)&nbsp;&nbsp;&nbsp;(((nr) + (d) - 1) / (d)) | 向上取整计算公式。 | 
| [BYTE_HAS_BITS](#byte_has_bits)&nbsp;&nbsp;&nbsp;8 | 一个字节所包含的比特数。 | 
| [BITS_TO_UINT64](#bits_to_uint64)(count)&nbsp;&nbsp;&nbsp;[DIV_ROUND_UP](#div_round_up)(count, [BYTE_HAS_BITS](#byte_has_bits) \* sizeof(uint64_t)) | 比特与64位无符号整数的转换公式。 | 
| [HDF_FF_CNT](#hdf_ff_cnt)&nbsp;&nbsp;&nbsp;(0x7f + 1) | Input设备发送力反馈命令的数量最大值。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [RetStatus](#retstatus) { INPUT_SUCCESS = 0, INPUT_FAILURE = -1, INPUT_INVALID_PARAM = -2, INPUT_NOMEM = -3,&nbsp;&nbsp;&nbsp;INPUT_NULL_PTR = -4, INPUT_TIMEOUT = -5, INPUT_UNSUPPORTED = -6 } | 定义返回值类型。 | 
| [InputDevType](#inputdevtype) { INDEV_TYPE_TOUCH, INDEV_TYPE_KEY, INDEV_TYPE_KEYBOARD, INDEV_TYPE_MOUSE,&nbsp;&nbsp;&nbsp;INDEV_TYPE_BUTTON, INDEV_TYPE_CROWN, INDEV_TYPE_ENCODER, INDEV_TYPE_UNKNOWN } | 定义Input设备类型。 | 
| [PowerStatus](#powerstatus) { INPUT_RESUME, INPUT_SUSPEND, INPUT_LOW_POWER, INPUT_POWER_STATUS_UNKNOWN } | 定义电源状态。 | 
| [CapacitanceTest](#capacitancetest) { BASE_TEST, FULL_TEST, MMI_TEST, RUNNING_TEST,&nbsp;&nbsp;&nbsp;TEST_TYPE_UNKNOWN } | 定义容值测试类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [GetInputInterface](#getinputinterface) ([IInputInterface](_i_input_interface.md) \*\*interface) | Input服务通过调用此接口获取操作Input设备的所有接口。 | 


## 宏定义说明


### BITS_TO_UINT64

```
#define BITS_TO_UINT64( count)   DIV_ROUND_UP(count, BYTE_HAS_BITS * sizeof(uint64_t))
```

**描述**


比特与64位无符号整数的转换公式


### BYTE_HAS_BITS

```
#define BYTE_HAS_BITS   8
```

**描述**


一个字节所包含的比特数


### CHIP_INFO_LEN

```
#define CHIP_INFO_LEN   10
```

**描述**


芯片信息长度


### CHIP_NAME_LEN

```
#define CHIP_NAME_LEN   10
```

**描述**


芯片名称长度


### DEV_MANAGER_SERVICE_NAME

```
#define DEV_MANAGER_SERVICE_NAME   "hdf_input_host"
```

**描述**


Input设备节点服务名称


### DEV_NAME_LEN

```
#define DEV_NAME_LEN   64
```

**描述**


Input设备名称长度


### DIV_ROUND_UP

```
#define DIV_ROUND_UP( nr,  d )   (((nr) + (d) - 1) / (d))
```

**描述**


向上取整计算公式


### HDF_FF_CNT

```
#define HDF_FF_CNT   (0x7f + 1)
```

**描述**


Input设备发送力反馈命令的数量最大值


### MAX_INPUT_DEV_NUM

```
#define MAX_INPUT_DEV_NUM   32
```

**描述**


Input设备数量的最大值


### SELF_TEST_RESULT_LEN

```
#define SELF_TEST_RESULT_LEN   20
```

**描述**


自测试结果长度


### VENDOR_NAME_LEN

```
#define VENDOR_NAME_LEN   10
```

**描述**


厂商名称长度


## 枚举类型说明


### CapacitanceTest

```
enum CapacitanceTest
```

**描述**


定义容值测试类型。

**起始版本：** 1.0

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

**描述**


定义Input设备类型。

**起始版本：** 1.0

| 枚举值 | 描述 | 
| -------- | -------- |
| INDEV_TYPE_TOUCH | 触摸屏 | 
| INDEV_TYPE_KEY | 物理按键 | 
| INDEV_TYPE_KEYBOARD | 键盘 | 
| INDEV_TYPE_MOUSE | 鼠标 | 
| INDEV_TYPE_BUTTON | 虚拟按键 | 
| INDEV_TYPE_CROWN | 表冠 | 
| INDEV_TYPE_ENCODER | 自定义编码的特定功能或者事件 | 
| INDEV_TYPE_UNKNOWN | 未知输入设备类型 | 


### PowerStatus

```
enum PowerStatus
```

**描述**


定义电源状态。

**起始版本：** 1.0

| 枚举值 | 描述 | 
| -------- | -------- |
| INPUT_RESUME | 正常唤醒 | 
| INPUT_SUSPEND | 休眠下电模式 | 
| INPUT_LOW_POWER | 休眠低功耗模式 | 
| INPUT_POWER_STATUS_UNKNOWN | 未知电源状态 | 


### RetStatus

```
enum RetStatus
```

**描述**


定义返回值类型。

**起始版本：** 1.0

| 枚举值 | 描述 | 
| -------- | -------- |
| INPUT_SUCCESS | 成功 | 
| INPUT_FAILURE | 失败 | 
| INPUT_INVALID_PARAM | 无效参数 | 
| INPUT_NOMEM | 内存不足 | 
| INPUT_NULL_PTR | 空指针 | 
| INPUT_TIMEOUT | 执行超时 | 
| INPUT_UNSUPPORTED | 特性不支持 | 


## 函数说明


### GetInputInterface()

```
int32_t GetInputInterface (IInputInterface ** interface)
```

**描述**


Input服务通过调用此接口获取操作Input设备的所有接口。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| interface | 对Input设备进行接口操作的指针，通常在Input服务启动后，通过调用此函数获取Input设备操作接口。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](#retstatus)。
