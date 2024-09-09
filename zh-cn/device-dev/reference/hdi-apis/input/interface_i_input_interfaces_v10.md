# IInputInterfaces


## 概述

Input模块向上层服务提供了统一接口。

上层服务开发人员可根据Input模块提供的向上统一接口实现Input设备的打开和关闭、Input事件获取、设备信息查询、回调函数注册、特性状态控制等功能。

**起始版本：** 3.2

**相关模块：**[HdiInput](_hdi_input.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [ScanInputDevice](#scaninputdevice) ([out] struct [DevDesc](_dev_desc_v10.md)[] staArr) | Input服务用于扫描所有在线设备。  | 
| [OpenInputDevice](#openinputdevice) ([in] unsigned int devIndex) | Input服务打开对应设备的设备文件。  | 
| [CloseInputDevice](#closeinputdevice) ([in] unsigned int devIndex) | Input服务关闭对应设备的设备文件。  | 
| [GetInputDevice](#getinputdevice) ([in] unsigned int devIndex, [out] struct [DeviceInfo](_device_info_v10.md) devInfo) | Input服务获取devIndex对应的Input设备信息。  | 
| [GetInputDeviceList](#getinputdevicelist) ([out] unsigned int devNum, [out] struct [DeviceInfo](_device_info_v10.md)[] devList, [in]unsigned int size) | Input服务获取所有Input设备列表的设备信息。  | 
| [SetPowerStatus](#setpowerstatus) ([in] unsigned int devIndex, [in] unsigned int status) | 设置devIndex对应的Input设备的电源状态。  | 
| [GetPowerStatus](#getpowerstatus) ([in] unsigned int devIndex, [out] unsigned int status) | 获取devIndex对应Input设备的电源状态。  | 
| [GetDeviceType](#getdevicetype) ([in] unsigned int devIndex, [out] unsigned int deviceType) | 获取devIndex对应的Input设备的类型。  | 
| [GetChipInfo](#getchipinfo) ([in] unsigned int devIndex, [out] String chipInfo) | 获取devIndex对应的Input设备的编码信息。  | 
| [GetVendorName](#getvendorname) ([in] unsigned int devIndex, [out] String vendorName) | 获取devIndex对应的Input设备的模组厂商名。  | 
| [GetChipName](#getchipname) ([in] unsigned int devIndex, [out] String chipName) | 获取devIndex对应的Input设备的驱动芯片名。  | 
| [SetGestureMode](#setgesturemode) ([in] unsigned int devIndex, [in] unsigned int gestureMode) | 设置devIndex对应的Input设备的手势模式。  | 
| [RunCapacitanceTest](#runcapacitancetest) ([in] unsigned int devIndex, [in] unsigned int testType, [out] String result, [in] unsigned int length) | 执行容值自检测试。  | 
| [RunExtraCommand](#runextracommand) ([in] unsigned int devIndex, [in] struct [ExtraCmd](_extra_cmd_v10.md) cmd) | 执行拓展指令。  | 
| [RegisterReportCallback](#registerreportcallback) ([in] unsigned int devIndex, [in] [IInputCallback](interface_i_input_callback_v10.md) eventPkgCallback) | 注册devIndex对应的Input设备的回调函数。  | 
| [UnregisterReportCallback](#unregisterreportcallback) ([in] unsigned int devIndex) | 注销devIndex对应的Input设备的回调函数。  | 
| [RegisterHotPlugCallback](#registerhotplugcallback) ([in] [IInputCallback](interface_i_input_callback_v10.md) hotPlugCallback) | 注册Input设备的热插拔回调函数。  | 
| [UnregisterHotPlugCallback](#unregisterhotplugcallback) () | 注销Input设备的热插拔回调函数。  | 


## 成员函数说明


### CloseInputDevice()

```
IInputInterfaces::CloseInputDevice ([in] unsigned int devIndex)
```
**描述**

Input服务关闭对应设备的设备文件。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetChipInfo()

```
IInputInterfaces::GetChipInfo ([in] unsigned int devIndex, [out] String chipInfo )
```
**描述**

获取devIndex对应的Input设备的编码信息。

一款产品通常会有多家模组和Driver IC，上层应用如果关注具体器件型号，则通过此接口来获取。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| chipInfo | 获取的对应设备索引的器件编码信息。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetChipName()

```
IInputInterfaces::GetChipName ([in] unsigned int devIndex, [out] String chipName )
```
**描述**

获取devIndex对应的Input设备的驱动芯片名。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| chipName | 获取的对应设备索引的驱动芯片名。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetDeviceType()

```
IInputInterfaces::GetDeviceType ([in] unsigned int devIndex, [out] unsigned int deviceType )
```
**描述**

获取devIndex对应的Input设备的类型。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| deviceType | 获取的对应设备索引的设备类型，如0表示触屏、1表示物理按键、2表示键盘、3表示鼠标等。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetInputDevice()

```
IInputInterfaces::GetInputDevice ([in] unsigned int devIndex, [out] struct DeviceInfo devInfo )
```
**描述**

Input服务获取devIndex对应的Input设备信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| devInfo | 即devIndex对应的设备的设备信息，具体参考[DeviceInfo](_device_info_v10.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetInputDeviceList()

```
IInputInterfaces::GetInputDeviceList ([out] unsigned int devNum, [out] struct DeviceInfo[] devList, [in] unsigned int size )
```
**描述**

Input服务获取所有Input设备列表的设备信息。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devNum | 当前已经注册过的所有Input设备的总数。  | 
| devList | Input设备列表所对应的设备信息，具体参考[DeviceInfo](_device_info_v10.md)。  | 
| size | 即指定deviceList数组对应的元素个数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetPowerStatus()

```
IInputInterfaces::GetPowerStatus ([in] unsigned int devIndex, [out] unsigned int status )
```
**描述**

获取devIndex对应Input设备的电源状态。

在系统休眠或者唤醒时，Input服务或电源管理模块获取电源状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| status | 获取的对应设备索引的电源状态，如0表示正常唤醒、1表示休眠下电、2表示低功耗、3表示未知电源状态等。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### GetVendorName()

```
IInputInterfaces::GetVendorName ([in] unsigned int devIndex, [out] String vendorName )
```
**描述**

获取devIndex对应的Input设备的模组厂商名。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| vendorName | 获取的对应设备索引的模组厂商名。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### OpenInputDevice()

```
IInputInterfaces::OpenInputDevice ([in] unsigned int devIndex)
```
**描述**

Input服务打开对应设备的设备文件。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### RegisterHotPlugCallback()

```
IInputInterfaces::RegisterHotPlugCallback ([in] IInputCallback hotPlugCallback)
```
**描述**

注册Input设备的热插拔回调函数。

Input服务通过此接口注册回调函数到HDI中，所有Input设备由此函数进行热插拔事件上报。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| hotPlugCallback | 回调函数的函数指针。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### RegisterReportCallback()

```
IInputInterfaces::RegisterReportCallback ([in] unsigned int devIndex, [in] IInputCallback eventPkgCallback )
```
**描述**

注册devIndex对应的Input设备的回调函数。

Input服务通过此接口注册数据回调函数到HDI中，HDI通过此回调函数上报Input事件。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| eventPkgCallback | 回调函数的函数指针。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### RunCapacitanceTest()

```
IInputInterfaces::RunCapacitanceTest ([in] unsigned int devIndex, [in] unsigned int testType, [out] String result, [in] unsigned int length )
```
**描述**

执行容值自检测试。

启动不同检测场景下的容值自检测试，并获取测试结果，容值自检项由器件厂商自定义， 一般包括RawData测试、短路检测、开路检测、干扰检测、行列差检测等测试项。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| testType | 容值测试的测试类型，如0表示基础容值测试、1表示全量容值自检测试、2表示MMI容值测试、3表示老化容值测试等。  | 
| result | 容值测试的结果，成功则输出“SUCC”，失败则返回对应的错误提示。  | 
| length | 保存容值测试结果的内存长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### RunExtraCommand()

```
IInputInterfaces::RunExtraCommand ([in] unsigned int devIndex, [in] struct ExtraCmd cmd )
```
**描述**

执行拓展指令。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| cmd | 拓展指令数据包，包括指令编码及参数，具体参考[ExtraCmd](_extra_cmd_v10.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### ScanInputDevice()

```
IInputInterfaces::ScanInputDevice ([out] struct DevDesc[] staArr)
```
**描述**

Input服务用于扫描所有在线设备。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| staArr | 存放Input设备扫描信息的数组，信息包含设备索引以及设备类型，具体参考[DevDesc](_dev_desc_v10.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetGestureMode()

```
IInputInterfaces::SetGestureMode ([in] unsigned int devIndex, [in] unsigned int gestureMode )
```
**描述**

设置devIndex对应的Input设备的手势模式。

上层应用开关手势模式，即设置手势模式的对应使能bit。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| gestureMode | 手势模式的开关状态。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### SetPowerStatus()

```
IInputInterfaces::SetPowerStatus ([in] unsigned int devIndex, [in] unsigned int status )
```
**描述**

设置devIndex对应的Input设备的电源状态。

在系统休眠或者唤醒时，Input服务或电源管理模块设置电源状态，使驱动IC能正常进入对应的模式。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。  | 
| status | 设置的电源状态，如0表示正常唤醒、1表示休眠下电、2表示低功耗、3表示未知电源状态等。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### UnregisterHotPlugCallback()

```
IInputInterfaces::UnregisterHotPlugCallback ()
```
**描述**

注销Input设备的热插拔回调函数。

**起始版本：** 3.2

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### UnregisterReportCallback()

```
IInputInterfaces::UnregisterReportCallback ([in] unsigned int devIndex)
```
**描述**

注销devIndex对应的Input设备的回调函数。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| devIndex | Input设备索引，用于标志Input设备，取值从0开始，最多支持32个设备。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
