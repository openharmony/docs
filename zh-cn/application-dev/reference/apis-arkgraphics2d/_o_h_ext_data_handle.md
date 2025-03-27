# OHExtDataHandle


## 概述

扩展数据句柄结构体定义。

**起始版本：** 9

**弃用：** 从API version 10开始废弃，不再提供替代接口。

**相关模块：** [NativeWindow](_native_window.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [fd](#fd) | 句柄Fd，-1代表不支持。 | 
| uint32_t [reserveInts](#reserveints) | Reserve数组的个数。 | 
| int32_t [reserve](#reserve) [0] | Reserve数组。 | 


## 结构体成员变量说明


### fd

```
int32_t OHExtDataHandle::fd
```

**描述：**

句柄 Fd，-1代表不支持。


### reserve

```
int32_t OHExtDataHandle::reserve[0]
```

**描述：**

Reserve数组。


### reserveInts

```
uint32_t OHExtDataHandle::reserveInts
```

**描述：**

Reserve数组的个数。
