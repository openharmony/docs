# Region


## 概述

表示本地窗口NativeWindow需要更新内容的矩形区域（脏区）。

**相关模块：**

[NativeWindow](_native_window.md)


## 汇总


### 成员变量

  | 成员变量名称 | 描述 | 
| -------- | -------- |
| [*rects](#rects) | 如果rects是空指针nullptr， 默认Buffer大小为脏区。 | 
| [rectNumber](#rectnumber) | 如果rectNumber为0，默认Buffer大小为脏区。 | 


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

结构体指针，类型为[Rect](_rect.md)。如果rects是空指针nullptr， 默认Buffer大小为脏区。
