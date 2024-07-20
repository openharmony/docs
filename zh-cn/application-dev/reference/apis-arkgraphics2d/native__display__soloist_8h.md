# native_display_soloist.h


## 概述

定义获取和使用NativeDisplaySoloist的相关函数。

**引用文件**：&lt;native_display_soloist/native_display_soloist.h&gt;

**系统能力：** SystemCapability.Graphic.Graphic2D.HyperGraphicManager

**库：** libnative_display_soloist.so

**起始版本：** 12

**相关模块：**[NativeDisplaySoloist](_native_display_soloist.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md) | 提供期望帧率范围结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist)  [OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) | 提供OH_DisplaySoloist结构体声明。 | 
| typedef void(\* [OH_DisplaySoloist_FrameCallback](_native_display_soloist.md#oh_displaysoloist_framecallback)) (long long timestamp, long long targetTimestamp, void \*data) | OH_DisplaySoloist回调函数类型。 | 
| typedef struct [DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md)  [DisplaySoloist_ExpectedRateRange](_native_display_soloist.md#displaysoloist_expectedraterange) | 提供期望帧率范围结构体。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) \* [OH_DisplaySoloist_Create](_native_display_soloist.md#oh_displaysoloist_create) (bool useExclusiveThread) | 创建一个OH_DisplaySoloist实例，每次调用都会产生一个新的实例。 | 
| int32_t [OH_DisplaySoloist_Destroy](_native_display_soloist.md#oh_displaysoloist_destroy) ([OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) \*displaySoloist) | 销毁OH_DisplaySoloist实例并回收对象占用的内存。 | 
| int32_t [OH_DisplaySoloist_Start](_native_display_soloist.md#oh_displaysoloist_start) ([OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) \*displaySoloist, [OH_DisplaySoloist_FrameCallback](_native_display_soloist.md#oh_displaysoloist_framecallback) callback, void \*data) | 设置每帧回调函数，每次VSync信号到来时启动每帧回调。 | 
| int32_t [OH_DisplaySoloist_Stop](_native_display_soloist.md#oh_displaysoloist_stop) ([OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) \*displaySoloist) | 停止请求下一次VSync信号，并停止调用回调函数callback。 | 
| int32_t [OH_DisplaySoloist_SetExpectedFrameRateRange](_native_display_soloist.md#oh_displaysoloist_setexpectedframeraterange) ([OH_DisplaySoloist](_native_display_soloist.md#oh_displaysoloist) \*displaySoloist, [DisplaySoloist_ExpectedRateRange](_display_soloist___expected_rate_range.md) \*range) | 设置VSync期望帧率范围。 | 
