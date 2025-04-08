# INnrtDevice


## 概述

定义了与设备相关的接口，实现设备管理和模型编译等操作。

当有多个设备注册时，需要保证设备名称和设备商名称的组合全局唯一。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v20.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [GetDeviceName](#getdevicename) ([out] String name) | 获取设备名称。  | 
| [GetVendorName](#getvendorname) ([out] String name) | 获取设备商名称。  | 
| [GetDeviceType](#getdevicetype) ([out] enum [DeviceType](_n_n_rt_v20.md#devicetype) deviceType) | 获取设备类型。  | 
| [GetDeviceStatus](#getdevicestatus) ([out] enum [DeviceStatus](_n_n_rt_v20.md#devicestatus) status) | 获取设备当前状态。  | 
| [GetSupportedOperation](#getsupportedoperation) ([in] struct [Model](_model_v20.md) model, [out] boolean[] ops) | ops为true事支持查询设备对指定模型的算子支持程度，反之则不支持。  | 
| [IsFloat16PrecisionSupported](#isfloat16precisionsupported) ([out] boolean isSupported) | isSupported为true查询设备支持以Float16精度运算Float32的模型，反之则不支持。  | 
| [IsPerformanceModeSupported](#isperformancemodesupported) ([out] boolean isSupported) | isSupported为true查询设备支持性能偏好设置，性能偏好的定义可以参考[PerformanceMode](_n_n_rt_v20.md#performancemode)，反之则不支持。  | 
| [IsPrioritySupported](#isprioritysupported) ([out] boolean isSupported) | isSupported为true查询设备支持任务优先级设置，优先级的定义可以参考[Priority](_n_n_rt_v20.md#priority)，反之则不支持。  | 
| [IsDynamicInputSupported](#isdynamicinputsupported) ([out] boolean isSupported) | isSupported为true查询设备支持变尺寸输入，变尺寸输入意味着同一个模型的不同次运算输入的形状可以不一样，反之则不支持。  | 
| [PrepareModel](#preparemodel) ([in] struct [Model](_model_v20.md) model, [in] struct [ModelConfig](_model_config_v20.md) config, [out] [IPreparedModel](interface_i_prepared_model_v20.md) preparedModel) | 编译模型。  | 
| [IsModelCacheSupported](#ismodelcachesupported) ([out] boolean isSupported) | isSupported为true查询支持模型缓存功能，反之则不支持。  | 
| [PrepareModelFromModelCache](#preparemodelfrommodelcache) ([in] struct [SharedBuffer](_shared_buffer_v20.md)[] modelCache, [in] struct [ModelConfig](_model_config_v20.md) config, [out] [IPreparedModel](interface_i_prepared_model_v20.md) preparedModel) | 加载模型缓存，该模型缓存是通过ExportModelCache接口导出的。  | 
| [PrepareOfflineModel](#prepareofflinemodel) ([in] struct [SharedBuffer](_shared_buffer_v20.md)[] modelCache, [in] struct [ModelConfig](_model_config_v20.md) config, [out] [IPreparedModel](interface_i_prepared_model_v20.md) preparedModel) | 加载离线模型文件的缓存，该离线模型是由推理框架传入NNRt并由NNRt解析得到的。  | 
| [AllocateBuffer](#allocatebuffer) ([in] unsigned int length, [out] struct [SharedBuffer](_shared_buffer_v20.md) buffer) | 申请设备共享内存，以文件描述符的形式返回，共享内存主要用于推理输入输出数据的快速传递。  | 
| [ReleaseBuffer](#releasebuffer) ([in] struct [SharedBuffer](_shared_buffer_v20.md) buffer) | 释放共享内存。  | 


## 成员函数说明


### AllocateBuffer()

```
INnrtDevice::AllocateBuffer ([in] unsigned int length, [out] struct SharedBuffer buffer )
```
**描述**

申请设备共享内存，以文件描述符的形式返回，共享内存主要用于推理输入输出数据的快速传递。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| length | 申请共享内存的大小，单位是字节。  | 
| buffer | 共享内存的信息，包含共享内存的文件描述符和空间大小，SharedBuffer定义请查看[SharedBuffer](_shared_buffer_v20.md)。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### GetDeviceName()

```
INnrtDevice::GetDeviceName ([out] String name)
```
**描述**

获取设备名称。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 设备名称。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### GetDeviceStatus()

```
INnrtDevice::GetDeviceStatus ([out] enum DeviceStatus status)
```
**描述**

获取设备当前状态。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| status | 设备当前状态，DeviceStatus枚举定义了可选的设备状态，详细定义请查看[DeviceStatus](_n_n_rt_v20.md#devicestatus)。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### GetDeviceType()

```
INnrtDevice::GetDeviceType ([out] enum DeviceType deviceType)
```
**描述**

获取设备类型。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceType | 设备类型，DeviceType枚举定义了可选的设备类型，详细定义请查看[DeviceType](_n_n_rt_v20.md#devicetype)。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### GetSupportedOperation()

```
INnrtDevice::GetSupportedOperation ([in] struct Model model, [out] boolean[] ops )
```
**描述**

查询设备对指定模型的算子支持程度。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | AI模型，模型结构由Model定义，详细定义请查看[Model](_model_v20.md)。  | 
| ops | 算子是否支持列表，算子支持列表的顺序与在model中的顺序要一致。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### GetVendorName()

```
INnrtDevice::GetVendorName ([out] String name)
```
**描述**

获取设备商名称。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| name | 设备商名称。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### IsDynamicInputSupported()

```
INnrtDevice::IsDynamicInputSupported ([out] boolean isSupported)
```
**描述**

查询设备是否支持变尺寸输入，变尺寸输入意味着同一个模型的不同次运算输入的形状可以不一样。

如果支持变尺寸输入，模型输入Tensor的形状上用-1标记该维度是否可变。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| isSupported | 是否支持变尺寸输入。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### IsFloat16PrecisionSupported()

```
INnrtDevice::IsFloat16PrecisionSupported ([out] boolean isSupported)
```
**描述**

查询设备是否支持以Float16精度运算Float32的模型。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| isSupported | 是否支持Float16精度。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### IsModelCacheSupported()

```
INnrtDevice::IsModelCacheSupported ([out] boolean isSupported)
```
**描述**

查询是否支持模型缓存功能。

若支持，则需要实现PrepareModelFromModelCache和ExportModelCache两个接口。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| isSupported | 是否支持模型缓存。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### IsPerformanceModeSupported()

```
INnrtDevice::IsPerformanceModeSupported ([out] boolean isSupported)
```
**描述**

查询设备是否支持性能偏好设置，性能偏好的定义可以参考[PerformanceMode](_n_n_rt_v20.md#performancemode)。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| isSupported | 是否支持性能偏好设置。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### IsPrioritySupported()

```
INnrtDevice::IsPrioritySupported ([out] boolean isSupported)
```
**描述**

查询设备是否支持任务优先级设置，优先级的定义可以参考[Priority](_n_n_rt_v20.md#priority)。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| isSupported | 是否支持性能偏好设置。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### PrepareModel()

```
INnrtDevice::PrepareModel ([in] struct Model model, [in] struct ModelConfig config, [out] IPreparedModel preparedModel )
```
**描述**

编译模型。

如果是变尺寸输入模型，则模型输入的维度信息中至少有一个是-1。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 需要编译的模型，Model定义请查看[Model](_model_v20.md)。  | 
| config | 编译模型的配置，ModelConfig定义请查看[ModelConfig](_model_config_v20.md)。  | 
| preparedModel | 编译好的模型对象，用于后续的运算，IPreparedModel定义请查看[IPreparedModel](interface_i_prepared_model_v20.md)。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### PrepareModelFromModelCache()

```
INnrtDevice::PrepareModelFromModelCache ([in] struct SharedBuffer[] modelCache, [in] struct ModelConfig config, [out] IPreparedModel preparedModel )
```
**描述**

加载模型缓存，该模型缓存是通过ExportModelCache接口导出的。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| modelCache | 模型缓存文件的数组，数组顺序与导出时的数组顺序一致，数组元素类型请查看SharedBuffer定义[SharedBuffer](_shared_buffer_v20.md)。  | 
| config | 加载模型缓存的配置，配置参数的详细定义请参考[ModelConfig](_model_config_v20.md)。  | 
| preparedModel | 加载缓存得到的模型对象，用于后续的运算，IPreparedModel定义请查看[IPreparedModel](interface_i_prepared_model_v20.md)。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### PrepareOfflineModel()

```
INnrtDevice::PrepareOfflineModel ([in] struct SharedBuffer[] modelCache, [in] struct ModelConfig config, [out] IPreparedModel preparedModel )
```
**描述**

加载离线模型文件的缓存，该离线模型是由推理框架传入NNRt并由NNRt解析得到的。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| modelCache | 离线模型文件缓存的数组，元素顺序与用户传入的离线模型格式有关，元素类型请查看SharedBuffer定义[SharedBuffer](_shared_buffer_v20.md)。  | 
| config | 加载离线模型文件缓存的配置，配置参数的详细定义请参考[ModelConfig](_model_config_v20.md)。  | 
| preparedModel | 加载离线模型文件缓存得到的模型对象，用于后续的运算，IPreparedModel定义请查看[IPreparedModel](interface_i_prepared_model_v20.md)。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。


### ReleaseBuffer()

```
INnrtDevice::ReleaseBuffer ([in] struct SharedBuffer buffer)
```
**描述**

释放共享内存。

**起始版本：** 3.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| buffer | 共享内存的信息，包含共享内存的文件描述符和空间大小，SharedBuffer定义请查看[SharedBuffer](_shared_buffer_v20.md)。 | 

**返回：**

返回0表示成功。

返回非0表示失败，负数为HDF标准错误码，正数为NNRt定义的专用错误码（请查看[NNRT_ReturnCode](_n_n_rt_v20.md#nnrt_returncode)）。
