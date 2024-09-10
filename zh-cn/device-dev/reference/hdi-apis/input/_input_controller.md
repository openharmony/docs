# InputController


## 概述

提供Input设备业务控制相关的接口。

此类接口包含电源状态的设置、特性的使能、器件信息的获取，以及产线相关的测试功能接口。

**起始版本：** 1.0

**相关模块：**[Input](_input.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| int32_t(\* [SetPowerStatus](#setpowerstatus) )(uint32_t devIndex, uint32_t status) | 设置电源状态。 | 
| int32_t(\* [GetPowerStatus](#getpowerstatus) )(uint32_t devIndex, uint32_t \*status) | 获取电源状态。 | 
| int32_t(\* [GetDeviceType](#getdevicetype) )(uint32_t devIndex, uint32_t \*deviceType) | 获取devIndex对应的Input设备的类型。 | 
| int32_t(\* [GetChipInfo](#getchipinfo) )(uint32_t devIndex, char \*chipInfo, uint32_t length) | 获取器件对应的编码信息。 | 
| int32_t(\* [GetVendorName](#getvendorname) )(uint32_t devIndex, char \*vendorName, uint32_t length) | 获取devIndex对应的模组厂商名。 | 
| int32_t(\* [GetChipName](#getchipname) )(uint32_t devIndex, char \*chipName, uint32_t length) | 获取devIndex对应的驱动芯片名。 | 
| int32_t(\* [SetGestureMode](#setgesturemode) )(uint32_t devIndex, uint32_t gestureMode) | 设置手势模式。 | 
| int32_t(\* [RunCapacitanceTest](#runcapacitancetest) )(uint32_t devIndex, uint32_t testType, char \*result, uint32_t length) | 执行容值自检测试。 | 
| int32_t(\* [RunExtraCommand](#runextracommand) )(uint32_t devIndex, [InputExtraCmd](_input_extra_cmd.md) \*cmd) | 执行拓展指令。 | 


## 类成员变量说明


### GetChipInfo

```
int32_t(* InputController::GetChipInfo) (uint32_t devIndex, char *chipInfo, uint32_t length)
```

**描述**


获取器件对应的编码信息。

一款产品通常会有多家模组和Driver IC，上层应用如果关注具体器件型号，则通过此接口来获取。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
| chipInfo | 输出参数，获取的对应设备索引的器件编码信息。 | 
| length | 输入参数，保存器件芯片信息的内存长度。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### GetChipName

```
int32_t(* InputController::GetChipName) (uint32_t devIndex, char *chipName, uint32_t length)
```

**描述**


获取devIndex对应的驱动芯片名。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
| chipName | 输出参数，获取的对应设备索引的驱动芯片名。 | 
| length | 输入参数，保存驱动芯片名的内存长度。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### GetDeviceType

```
int32_t(* InputController::GetDeviceType) (uint32_t devIndex, uint32_t *deviceType)
```

**描述**


获取devIndex对应的Input设备的类型。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
| deviceType | 输出参数，获取的对应设备索引的设备类型，具体参考[InputDevType](_input.md#inputdevtype)。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### GetPowerStatus

```
int32_t(* InputController::GetPowerStatus) (uint32_t devIndex, uint32_t *status)
```

**描述**


获取电源状态。

在系统休眠或者唤醒时，Input服务或电源管理模块获取电源状态，以便驱动IC能正常进入对应的休眠模式。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
| status | 输出参数，获取的对应设备索引的电源状态，具体参考[PowerStatus](_input.md#powerstatus)。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### GetVendorName

```
int32_t(* InputController::GetVendorName) (uint32_t devIndex, char *vendorName, uint32_t length)
```

**描述**


获取devIndex对应的模组厂商名。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
| vendorName | 输出参数，获取的对应设备索引的模组厂商名。 | 
| length | 输入参数，保存模组厂商名的内存长度。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### RunCapacitanceTest

```
int32_t(* InputController::RunCapacitanceTest) (uint32_t devIndex, uint32_t testType, char *result, uint32_t length)
```

**描述**


执行容值自检测试。

启动不同检测场景下的容值自检测试，并获取测试结果，容值自检项由器件厂商自定义， 一般包括RawData测试、短路检测、开路检测、干扰检测、行列差检测等测试项。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
| testType | 输入参数，容值测试的测试类型，具体参考[CapacitanceTest](_input.md#capacitancetest)。 | 
| result | 输出参数，容值测试的结果，成功则输出“SUCC”，失败则返回对应的错误提示。 | 
| length | 输入参数，保存容值测试结果的内存长度。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### RunExtraCommand

```
int32_t(* InputController::RunExtraCommand) (uint32_t devIndex, InputExtraCmd *cmd)
```

**描述**


执行拓展指令。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
| cmd | 输入参数，拓展指令数据包，包括指令编码及参数，具体参考[InputExtraCmd](_input_extra_cmd.md)。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### SetGestureMode

```
int32_t(* InputController::SetGestureMode) (uint32_t devIndex, uint32_t gestureMode)
```

**描述**


设置手势模式。

上层应用开关手势模式，即设置手势模式的对应使能bit。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
| gestureMode | 输入参数，手势模式的开关状态。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。


### SetPowerStatus

```
int32_t(* InputController::SetPowerStatus) (uint32_t devIndex, uint32_t status)
```

**描述**


设置电源状态。

在系统休眠或者唤醒时，Input服务或电源管理模块设置电源状态，以使驱动IC能正常进入对应的休眠模式。

**起始版本：** 1.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | 输入参数，Input设备索引，用于标志多个Input设备，取值从0开始，最多支持32个设备。 | 
| status | 输入参数，设置的电源状态，Input服务控制Input设备进入resume或者suspend等状态[PowerStatus](_input.md#powerstatus)。 | 

**返回：**

INPUT_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[RetStatus](_input.md#retstatus)。
