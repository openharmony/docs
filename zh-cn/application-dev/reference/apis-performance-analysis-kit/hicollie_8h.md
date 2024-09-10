# hicollie.h


## 概述

定义HiCollie模块的调试功能。

**库：** libohhicollie.so

**系统能力：** SystemCapability.HiviewDFX.HiCollie

**起始版本：** 12

**相关模块：**[HiCollie](_hi_hicollie.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| HiCollie_ErrorCode [OH_HiCollie_Init_StuckDetection](_hi_hicollie.md#oh_hicollie_init_stuckdetection)(OH_HiCollie_Task task) | 注册应用业务线程卡死的周期性检测任务。  | 
| HiCollie_ErrorCode [OH_HiCollie_Init_JankDetection](_hi_hicollie.md#oh_hicollie_init_jankdetection)(OH_HiCollie_BeginFunc\* beginFunc, OH_HiCollie_EndFunc\* endFunc, HiCollie_DetectionParam param) | 注册应用业务线程卡顿检测的回调函数。线程卡顿监控功能需要开发者实现两个卡顿检测回调函数, 分别放在业务线程处理事件的前后。作为插桩函数，监控业务线程处理事件执行情况。  | 
| HiCollie_ErrorCode [OH_HiCollie_Report](_hi_hicollie.md#oh_hicollie_report)(bool\* isSixSecond) | 用于上报应用业务线程卡死事件，生成超时故障日志，辅助定位应用超时问题。  | 
