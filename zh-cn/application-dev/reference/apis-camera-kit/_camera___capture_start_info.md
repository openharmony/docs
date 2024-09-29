# Camera_CaptureStartInfo


## 概述

拍照开始信息。

**起始版本：** 12

**相关模块：**[OH_Camera](_o_h___camera.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [captureId](#captureid) | 拍照id。  | 
| int64_t [time](#time) | 预估的单次拍照底层出sensor采集帧时间，如果上报-1，代表没有预估时间。  | 


## 结构体成员变量说明


### captureId

```
int32_t Camera_CaptureStartInfo::captureId
```
**描述**
拍照id。


### time

```
int64_t Camera_CaptureStartInfo::time
```
**描述**
预估的单次拍照底层出sensor采集帧时间，如果上报-1，代表没有预估时间。
