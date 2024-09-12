# input_type.h


## 概述

Input设备相关的类型定义，定义了Input设备驱动接口所使用的结构体及枚举类型。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### 类

| 名称 | 描述 | 
| -------- | -------- |
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
| [MAX_INPUT_DEV_NUM](_input.md#max_input_dev_num)&nbsp;&nbsp;&nbsp;32 | Input设备数量的最大值。 | 
| [CHIP_INFO_LEN](_input.md#chip_info_len)&nbsp;&nbsp;&nbsp;10 | 芯片信息长度。 | 
| [CHIP_NAME_LEN](_input.md#chip_name_len)&nbsp;&nbsp;&nbsp;10 | 芯片名称长度。 | 
| [VENDOR_NAME_LEN](_input.md#vendor_name_len)&nbsp;&nbsp;&nbsp;10 | 厂商名称长度。 | 
| [DEV_NAME_LEN](_input.md#dev_name_len)&nbsp;&nbsp;&nbsp;64 | Input设备名称长度。 | 
| [SELF_TEST_RESULT_LEN](_input.md#self_test_result_len)&nbsp;&nbsp;&nbsp;20 | 自测结果长度。 | 
| [DEV_MANAGER_SERVICE_NAME](_input.md#dev_manager_service_name)&nbsp;&nbsp;&nbsp;"hdf_input_host" | Input设备节点服务名称。 | 
| [DIV_ROUND_UP](_input.md#div_round_up)(nr, d)&nbsp;&nbsp;&nbsp;(((nr) + (d) - 1) / (d)) | 向上取整计算公式。 | 
| [BYTE_HAS_BITS](_input.md#byte_has_bits)&nbsp;&nbsp;&nbsp;8 | 一个字节所包含的比特数。 | 
| [BITS_TO_UINT64](_input.md#bits_to_uint64)(count)&nbsp;&nbsp;&nbsp;[DIV_ROUND_UP](_input.md#div_round_up)(count, [BYTE_HAS_BITS](_input.md#byte_has_bits) \* sizeof(uint64_t)) | 比特与64位无符号整数的转换公式。 | 
| [HDF_FF_CNT](_input.md#hdf_ff_cnt)&nbsp;&nbsp;&nbsp;(0x7f + 1) | Input设备发送力反馈命令的数量最大值。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [RetStatus](_input.md#retstatus) { INPUT_SUCCESS = 0, INPUT_FAILURE = -1, INPUT_INVALID_PARAM = -2, INPUT_NOMEM = -3,&nbsp;&nbsp;&nbsp;INPUT_NULL_PTR = -4, INPUT_TIMEOUT = -5, INPUT_UNSUPPORTED = -6 } | 定义返回值类型。 | 
| [InputDevType](_input.md#inputdevtype) { INDEV_TYPE_TOUCH, INDEV_TYPE_KEY, INDEV_TYPE_KEYBOARD, INDEV_TYPE_MOUSE,&nbsp;&nbsp;&nbsp;INDEV_TYPE_BUTTON, INDEV_TYPE_CROWN, INDEV_TYPE_ENCODER, INDEV_TYPE_UNKNOWN } | 定义Input设备类型。 | 
| [PowerStatus](_input.md#powerstatus) { INPUT_RESUME, INPUT_SUSPEND, INPUT_LOW_POWER, INPUT_POWER_STATUS_UNKNOWN } | 定义电源状态。 | 
| [CapacitanceTest](_input.md#capacitancetest) { BASE_TEST, FULL_TEST, MMI_TEST, RUNNING_TEST,&nbsp;&nbsp;&nbsp;TEST_TYPE_UNKNOWN } | 定义容值测试类型。 | 
