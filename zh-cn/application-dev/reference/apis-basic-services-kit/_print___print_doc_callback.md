# Print_PrintDocCallback


## 概述

打印文档任务回调结构体。

**起始版本：** 13

**相关模块：**[OH_Print](_o_h___print.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [Print_OnStartLayoutWrite](_o_h___print.md#print_onstartlayoutwrite) [startLayoutWriteCb](#startlayoutwritecb) | 文件开始回写回调函数。  | 
| [Print_OnJobStateChanged](_o_h___print.md#print_onjobstatechanged) [jobStateChangedCb](#jobstatechangedcb) | 打印任务状态回调。  | 


## 结构体成员变量说明


### jobStateChangedCb

```
Print_OnJobStateChanged Print_PrintDocCallback::jobStateChangedCb
```
**描述**
打印任务状态回调。


### startLayoutWriteCb

```
Print_OnStartLayoutWrite Print_PrintDocCallback::startLayoutWriteCb
```
**描述**
文件开始回写回调函数。
