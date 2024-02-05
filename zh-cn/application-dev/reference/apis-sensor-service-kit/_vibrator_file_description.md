# Vibrator_FileDescription


## 概述

振动文件描述。

**起始版本：** 11

**相关模块：**[Vibrator](_vibrator.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [fd](#fd) | 自定义振动序列的文件句柄。  |
| [offset](#offset) | 自定义振动序列的偏移地址。 |
| [length](#length) | 自定义振动序列的总长度。 |


## 结构体成员变量说明


### fd

```
int32_t Vibrator_FileDescription::fd
```
**描述：**

自定义振动序列的文件句柄。


### offset

```
int64_t Vibrator_FileDescription::offset
```
**描述：**

 自定义振动序列的偏移地址。

### length

```
int64_t Vibrator_FileDescription::length
```

**描述：**

自定义振动序列的总长度。