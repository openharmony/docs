# NativeDisplaySoloist


## 概述

主要是用于UI线程以外的线程中进行帧率控制的Native侧业务。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_display_soloist.h](native__display__soloist_8h.md) | 定义获取和使用NativeDisplaySoloist的相关函数。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md) | 提供期望帧率范围结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_DisplaySoloist](#oh_displaysoloist)  [OH_DisplaySoloist](#oh_displaysoloist) | 提供OH_DisplaySoloist结构体声明。 | 
| typedef void(\* [OH_DisplaySoloist_FrameCallback](#oh_displaysoloist_framecallback)) (long long timestamp, long long targetTimestamp, void \*data) | OH_DisplaySoloist回调函数类型。 | 
| typedef struct [DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md)  [DisplaySoloist_ExpectedRateRange](#displaysoloist_expectedraterange) | 提供期望帧率范围结构体。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_DisplaySoloist](#oh_displaysoloist) \* [OH_DisplaySoloist_Create](#oh_displaysoloist_create) (bool useExclusiveThread) | 创建一个OH_DisplaySoloist实例，每次调用都会产生一个新的实例。 | 
| int32_t [OH_DisplaySoloist_Destroy](#oh_displaysoloist_destroy) ([OH_DisplaySoloist](#oh_displaysoloist) \*displaySoloist) | 销毁OH_DisplaySoloist实例并回收对象占用的内存。 | 
| int32_t [OH_DisplaySoloist_Start](#oh_displaysoloist_start) ([OH_DisplaySoloist](#oh_displaysoloist) \*displaySoloist, [OH_DisplaySoloist_FrameCallback](#oh_displaysoloist_framecallback) callback, void \*data) | 设置每帧回调函数，每次VSync信号到来时启动每帧回调。 | 
| int32_t [OH_DisplaySoloist_Stop](#oh_displaysoloist_stop) ([OH_DisplaySoloist](#oh_displaysoloist) \*displaySoloist) | 停止请求下一次VSync信号，并停止调用回调函数callback。 | 
| int32_t [OH_DisplaySoloist_SetExpectedFrameRateRange](#oh_displaysoloist_setexpectedframeraterange) ([OH_DisplaySoloist](#oh_displaysoloist) \*displaySoloist, [DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md) \*range) | 设置VSync期望帧率范围。 | 


## 类型定义说明


### DisplaySoloist_ExpectedRateRange

```
typedef struct DisplaySoloist_ExpectedRateRange DisplaySoloist_ExpectedRateRange
```

**描述**

提供期望帧率范围结构体。

**起始版本：** 12


### OH_DisplaySoloist

```
typedef struct OH_DisplaySoloist OH_DisplaySoloist
```

**描述**

提供OH_DisplaySoloist结构体声明。

**起始版本：** 12


### OH_DisplaySoloist_FrameCallback

```
typedef void(* OH_DisplaySoloist_FrameCallback) (long long timestamp, long long targetTimestamp, void *data)
```

**描述**

OH_DisplaySoloist回调函数类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| timestamp | VSync时间戳。 | 
| targetTimestamp | 预期的下一帧VSync时间戳。 | 
| data | 用户自定义数据。 | 


## 函数说明


### OH_DisplaySoloist_Create()

```
OH_DisplaySoloist* OH_DisplaySoloist_Create (bool useExclusiveThread)
```

**描述**

创建一个OH_DisplaySoloist实例，每次调用都会产生一个新的实例。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| useExclusiveThread | 表示此OH_DisplaySoloist实例是否是独占线程，true表示独占一个线程，false表示共享线程。 | 

**返回：**

返回一个指向[OH_DisplaySoloist](#oh_displaysoloist)实例的指针，如果返回空表示执行失败，可能的原因是内存不足。


### OH_DisplaySoloist_Destroy()

```
int32_t OH_DisplaySoloist_Destroy (OH_DisplaySoloist* displaySoloist)
```

**描述**

销毁OH_DisplaySoloist实例并回收对象占用的内存。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displaySoloist | 一个指向[OH_DisplaySoloist](#oh_displaysoloist)实例的指针。 | 

**返回：**

返回值为0表示执行成功，-1表示执行失败。


### OH_DisplaySoloist_SetExpectedFrameRateRange()

```
int32_t OH_DisplaySoloist_SetExpectedFrameRateRange (OH_DisplaySoloist* displaySoloist, DisplaySoloist_ExpectedRateRange* range )
```

**描述**

设置VSync期望帧率范围。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displaySoloist | 一个指向[OH_DisplaySoloist](#oh_displaysoloist)实例的指针。 | 
| range | 一个指向期望帧率范围[DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md)实例的指针。 | 

**返回：**

返回值为0表示执行成功，-1表示执行失败。


### OH_DisplaySoloist_Start()

```
int32_t OH_DisplaySoloist_Start (OH_DisplaySoloist* displaySoloist, OH_DisplaySoloist_FrameCallback callback, void* data )
```

**描述**

设置每帧回调函数，每次VSync信号到来时启动每帧回调。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displaySoloist | 一个指向[OH_DisplaySoloist](#oh_displaysoloist)实例的指针。 | 
| callback | 表示下一次VSync信号到来时执行的回调函数类型。 | 
| data | 一个指向用户自定义数据结构的指针，类型是void\*。 | 

**返回：**

返回值为0表示执行成功，-1表示执行失败。


### OH_DisplaySoloist_Stop()

```
int32_t OH_DisplaySoloist_Stop (OH_DisplaySoloist* displaySoloist)
```

**描述**

停止请求下一次VSync信号，并停止调用回调函数callback。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| displaySoloist | 一个指向[OH_DisplaySoloist](#oh_displaysoloist)实例的指针。 | 

**返回：**

返回值为0表示执行成功，-1表示执行失败。
