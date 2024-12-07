# ICellbatchingInterface


## 概述

定义对基站轨迹数据记录模块进行基本操作的接口。

接口包含注册回调函数，取消注册回调函数，使能和去使能基站轨迹数据记录，主动获取基站轨迹数据。

**起始版本：** 4.0

**相关模块：**[HdiLpfenceCellbatching](_hdi_lpfence_cellbatching.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [RegisterCellbatchingCallback](#registercellbatchingcallback) ([in] [ICellbatchingCallback](interface_i_cellbatching_callback.md) callbackObj) | 注册回调函数。  | 
| [UnregisterCellbatchingCallback](#unregistercellbatchingcallback) ([in] [ICellbatchingCallback](interface_i_cellbatching_callback.md) callbackObj) | 取消注册回调函数。  | 
| [CellbatchingSwitch](#cellbatchingswitch) ([in] struct [CellbatchingRequest](_cellbatching_request.md) req) | 打开/关闭基站轨迹数据记录。  | 
| [FlushCellbatching](#flushcellbatching) () | 上报缓存的基站轨迹数据。  | 


## 成员函数说明


### CellbatchingSwitch()

```
ICellbatchingInterface::CellbatchingSwitch ([in] struct CellbatchingRequest req)
```
**描述**

打开/关闭基站轨迹数据记录。

功能打开后，会将设备接收到的基站数据进行缓存，若接收到的基站数据与上一次接收的数据相同，则不会进行此次的数据缓存。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| req | 设置基站轨迹数据记录参数。详见[CellbatchingRequest](_cellbatching_request.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### FlushCellbatching()

```
ICellbatchingInterface::FlushCellbatching ()
```
**描述**

上报缓存的基站轨迹数据。

上报基站数据的个数与设备的缓存buffer大小、设备接收的基站数据个数有关。flush之后，底层缓存基站数据会被清空。

**起始版本：** 4.0

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### RegisterCellbatchingCallback()

```
ICellbatchingInterface::RegisterCellbatchingCallback ([in] ICellbatchingCallback callbackObj)
```
**描述**

注册回调函数。

用户在开启基站轨迹数据记录功能前，需要先注册该回调函数。当应用主动获取基站轨迹数据时，会通过回调函数进行上报。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要注册的回调函数，只需成功订阅一次，无需重复订阅。详见[ICellbatchingCallback](interface_i_cellbatching_callback.md)。 | 

**返回：**

如果注册回调函数成功，则返回0。

如果注册回调函数失败，则返回负值。


### UnregisterCellbatchingCallback()

```
ICellbatchingInterface::UnregisterCellbatchingCallback ([in] ICellbatchingCallback callbackObj)
```
**描述**

取消注册回调函数。

取消之前注册的回调函数。当应用不需要使用基站轨迹数据记录功能，或需要更换回调函数时，需要取消注册回调函数。

**起始版本：** 4.0

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| callbackObj | 要取消注册的回调函数，只需成功取消订阅一次，无需重复取消订阅。详见[ICellbatchingCallback](interface_i_cellbatching_callback.md)。 | 

**返回：**

如果取消注册回调函数成功，则返回0。

如果取消注册回调函数失败，则返回负值。
