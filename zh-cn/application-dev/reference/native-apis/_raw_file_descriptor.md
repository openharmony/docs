# RawFileDescriptor


## 概述

提供rawfile文件描述符信息。

RawFileDescriptor是[OH_ResourceManager_GetRawFileDescriptor()](rawfile.md#oh_resourcemanager_getrawfiledescriptor)的输出参数，涵盖了rawfile文件的文件描述符以及在HAP中的起始位置和长度。

**起始版本：**

8

**相关模块：**

[Rawfile](rawfile.md)


## 汇总


### 成员变量

| 成员变量名称 | 描述 |
| -------- | -------- |
| [fd](#fd) | rawfile文件描述符 |
| [start](#start) | rawfile在HAP中的长度 |
| [length](#length) | rawfile在HAP中的起始位置 |


## 结构体成员变量说明


### fd


```
int RawFileDescriptor::fd
```

**描述：**

rawfile文件描述符


### length


```
long RawFileDescriptor::length
```

**描述：**

rawfile在HAP中的长度


### start


```
long RawFileDescriptor::start
```

**描述：**

rawfile在HAP中的起始位置
