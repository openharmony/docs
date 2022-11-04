# input_type.h


## **概述**

Input设备相关的类型定义。

定义了Input设备驱动接口所使用的结构体及枚举类型。

**Since**:

1.0

**Version**:

1.0

**相关模块:**

[Input](input.md)


## **汇总**


### 类

  | 名称 | 描述 | 
| -------- | -------- |
| [InputEventPackage](_input_event_package.md) | Input事件数据包结构。 | 
| [InputHotPlugEvent](_input_hot_plug_event.md) | 热插拔事件数据包结构。 | 
| [InputDevDesc](_input_dev_desc.md) | Input设备描述信息。 | 
| [InputEventCb](_input_event_cb.md) | 此结构体定义了输入事件回调函数并提供给Input服务使用。 | 
| [InputHostCb](_input_host_cb.md) | 此结构体定义了热插拔事件上报回调函数并提供给Input服务使用。 | 
| [InputDevAbility](_input_dev_ability.md) | Input设备的能力属性，存储支持事件的位图。 | 
| [InputDimensionInfo](_input_dimension_info.md) | Input设备的维度信息。 | 
| [InputDevIdentify](_input_dev_identify.md) | Input设备的识别信息。 | 
| [InputDevAttr](_input_dev_attr.md) | Input设备属性。 | 
| [InputDeviceInfo](_input_device_info.md) | Input设备基础设备信息。 | 
| [InputExtraCmd](_input_extra_cmd.md) | 扩展指令的数据结构。 | 


### 宏定义

  | 名称 | 描述 | 
| -------- | -------- |
| [MAX_INPUT_DEV_NUM](input.md#max_input_dev_num)&nbsp;&nbsp;&nbsp;32 | Input设备数量的最大值。 | 
| [CHIP_INFO_LEN](input.md#chip_info_len)&nbsp;&nbsp;&nbsp;10 | 芯片信息长度。 | 
| [CHIP_NAME_LEN](input.md#chip_name_len)&nbsp;&nbsp;&nbsp;10 | 芯片名称长度。 | 
| [VENDOR_NAME_LEN](input.md#vendor_name_len)&nbsp;&nbsp;&nbsp;10 | 厂商名称长度。 | 
| [DEV_NAME_LEN](input.md#dev_name_len)&nbsp;&nbsp;&nbsp;64 | Input设备名称长度。 | 
| [SELF_TEST_RESULT_LEN](input.md#self_test_result_len)&nbsp;&nbsp;&nbsp;20 | 自测结果长度。 | 
| [DEV_MANAGER_SERVICE_NAME](input.md#dev_manager_service_name)&nbsp;&nbsp;&nbsp;"hdf_input_host" | Input设备节点服务名称。 | 
| [DIV_ROUND_UP](input.md#div_round_up)(nr,&nbsp;d)&nbsp;&nbsp;&nbsp;(((nr)&nbsp;+&nbsp;(d)&nbsp;-&nbsp;1)&nbsp;/&nbsp;(d)) | 向上取整计算公式。 | 
| [BYTE_HAS_BITS](input.md#byte_has_bits)&nbsp;&nbsp;&nbsp;8 | 一个字节所包含的比特数。 | 
| [BITS_TO_UINT64](input.md#bits_to_uint64)(count)&nbsp;&nbsp;&nbsp;[DIV_ROUND_UP](input.md#div_round_up)(count,&nbsp;[BYTE_HAS_BITS](input.md#byte_has_bits)&nbsp;\*&nbsp;sizeof(uint64_t)) | 比特与64位无符号整数的转换公式。 | 
| [HDF_FF_CNT](input.md#hdf_ff_cnt)&nbsp;&nbsp;&nbsp;(0x7f&nbsp;+&nbsp;1) | Input设备发送力反馈命令的数量最大值。 | 


### 枚举

  | 名称 | 描述 | 
| -------- | -------- |
| [RetStatus](input.md#retstatus)&nbsp;{&nbsp;INPUT_SUCCESS&nbsp;=&nbsp;0,&nbsp;INPUT_FAILURE&nbsp;=&nbsp;-1,&nbsp;INPUT_INVALID_PARAM&nbsp;=&nbsp;-2,&nbsp;INPUT_NOMEM&nbsp;=&nbsp;-3,&nbsp;&nbsp;&nbsp;INPUT_NULL_PTR&nbsp;=&nbsp;-4,&nbsp;INPUT_TIMEOUT&nbsp;=&nbsp;-5,&nbsp;INPUT_UNSUPPORTED&nbsp;=&nbsp;-6&nbsp;} | 定义返回值类型。 | 
| [InputDevType](input.md#inputdevtype)&nbsp;{&nbsp;INDEV_TYPE_TOUCH,&nbsp;INDEV_TYPE_KEY,&nbsp;INDEV_TYPE_KEYBOARD,&nbsp;INDEV_TYPE_MOUSE,&nbsp;&nbsp;&nbsp;INDEV_TYPE_BUTTON,&nbsp;INDEV_TYPE_CROWN,&nbsp;INDEV_TYPE_ENCODER,&nbsp;INDEV_TYPE_UNKNOWN&nbsp;} | 定义Input设备类型。 | 
| [PowerStatus](input.md#powerstatus)&nbsp;{&nbsp;INPUT_RESUME,&nbsp;INPUT_SUSPEND,&nbsp;INPUT_LOW_POWER,&nbsp;INPUT_POWER_STATUS_UNKNOWN&nbsp;&nbsp;} | 定义电源状态。 | 
| [CapacitanceTest](input.md#capacitancetest)&nbsp;{&nbsp;BASE_TEST,&nbsp;FULL_TEST,&nbsp;MMI_TEST,&nbsp;RUNNING_TEST,&nbsp;&nbsp;&nbsp;TEST_TYPE_UNKNOWN&nbsp;} | 定义容值测试类型。 | 
