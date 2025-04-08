# Region


## 概述

表示本地窗口OHNativeWindow需要更新内容的矩形区域（脏区）。

**起始版本：** 8

**相关模块：**[NativeWindow](_native_window.md)

**所在头文件：**[external_window.h](external__window_8h.md)

## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[Rect](_rect.md) | 矩形区域。 | 


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| struct [Region::Rect](_rect.md) \* rects | 如果rects是空指针nullptr，默认Buffer大小为脏区。 | 
| int32_t [rectNumber](#rectnumber) | 如果rectNumber为0，默认Buffer大小为脏区。 | 


## 结构体成员变量说明


### rectNumber

```
int32_t Region::rectNumber
```

**描述：**

如果rectNumber为0，默认Buffer大小为脏区。


### \*rects

```
struct Rect Region::*rects
```

**描述：**

结构体指针，类型为[Rect](_rect.md)。如果rects是空指针nullptr，默认Buffer大小为脏区。
