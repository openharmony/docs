# InputManager


## **概述**

提供Input设备管理相关的接口。

此类接口包含Input设备的扫描、打开和关闭、特定设备信息查询，以及所有设备列表信息获取等接口。

**相关模块:**

[Input](input.md)


## **汇总**


### Public 属性

  | 名称 | 描述 | 
| -------- | -------- |
| ([ScanInputDevice](#scaninputdevice)&nbsp;)([InputDevDesc](_input_dev_desc.md)&nbsp;\*staArr,&nbsp;uint32_t&nbsp;arrLen) | Input服务用于扫描所有在线设备。 | 
| ([OpenInputDevice](#openinputdevice)&nbsp;)(uint32_t&nbsp;devIndex) | Input服务打开对应设备的设备文件。 | 
| ([CloseInputDevice](#closeinputdevice)&nbsp;)(uint32_t&nbsp;devIndex) | Input服务关闭对应设备的设备文件。 | 
| ([GetInputDevice](#getinputdevice)&nbsp;)(uint32_t&nbsp;devIndex,&nbsp;[InputDeviceInfo](_input_device_info.md)&nbsp;\*\*devInfo) | Input服务获取对应ID的设备信息。 | 
| ([GetInputDeviceList](#getinputdevicelist)&nbsp;)(uint32_t&nbsp;\*devNum,&nbsp;[InputDeviceInfo](_input_device_info.md)&nbsp;\*\*devList,&nbsp;uint32_t&nbsp;size) | Input服务获取所有Input设备列表的设备信息。 | 


## **类成员变量说明**


### CloseInputDevice

  
```
int32_t(* InputManager::CloseInputDevice) (uint32_t devIndex)
```

**描述：**

Input服务关闭对应设备的设备文件。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 

**返回:**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](input.md#retstatus)。


### GetInputDevice

  
```
int32_t(* InputManager::GetInputDevice) (uint32_t devIndex, InputDeviceInfo **devInfo)
```

**描述：**

Input服务获取对应ID的设备信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
| devInfo | 输出参数，即devIndex对应的设备的设备信息，具体参考[InputDeviceInfo](_input_device_info.md)。 | 

**返回:**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](input.md#retstatus)。


### GetInputDeviceList

  
```
int32_t(* InputManager::GetInputDeviceList) (uint32_t *devNum, InputDeviceInfo **devList, uint32_t size)
```

**描述：**

Input服务获取所有Input设备列表的设备信息。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devNum | 输出参数，当前已经注册过的所有Input设备的总数。 | 
| devList | 输出参数，Input设备列表所对应的设备信息，具体参考[InputDeviceInfo](_input_device_info.md)。 | 
| size | 输入参数，即指定deviceList数组对应的元素个数。 | 

**返回:**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](input.md#retstatus)。


### OpenInputDevice

  
```
int32_t(* InputManager::OpenInputDevice) (uint32_t devIndex)
```

**描述：**

Input服务打开对应设备的设备文件。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 

**返回:**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](input.md#retstatus)。


### ScanInputDevice

  
```
int32_t(* InputManager::ScanInputDevice) (InputDevDesc *staArr, uint32_t arrLen)
```

**描述：**

Input服务用于扫描所有在线设备。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| staArr | 输出参数，存放Input设备扫描信息的数组，信息包含设备索引以及设备类型。 | 
| arrLen | 输入参数，staArr数组的长度信息。 | 

**返回:**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](input.md#retstatus)。
