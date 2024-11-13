# AudioTimeStamp


## 概述

音频时间戳。

时间定义，POSIX timespec的替代品。

**起始版本：** 4.1

**相关模块：**[HdiAudio](_hdi_audio_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| long [tvSec](#tvsec) | tvSec时间，单位：秒。  | 
| long [tvNSec](#tvnsec) | tvNSec时间，单位：纳秒。  | 


## 类成员变量说明


### tvNSec

```
long AudioTimeStamp::tvNSec
```
**描述**

tvNSec时间，单位：纳秒。


### tvSec

```
long AudioTimeStamp::tvSec
```
**描述**

tvSec时间，单位：秒。
