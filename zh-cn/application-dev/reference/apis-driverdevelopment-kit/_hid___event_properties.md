# Hid_EventProperties


## 概述

设备关注事件属性。

**起始版本：**

11

**相关模块：**

[HID DDK](_hid_ddk.md)

**所在头文件：** [hid_ddk_types.h](hid__ddk__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [hidEventTypes](#hideventtypes) | 事件类型属性编码数组 | 
| [hidKeys](#hidkeys) | 键值属性编码数组 | 
| [hidAbs](#hidabs) | 绝对坐标属性数组 | 
| [hidRelBits](#hidrelbits) | 相对坐标属性数组 | 
| [hidMiscellaneous](#hidmiscellaneous) | 其它特殊事件属性编码数组 | 
| [hidAbsMax](#hidabsmax) | 绝对坐标属性最大值 | 
| [hidAbsMin](#hidabsmin) | 绝对坐标属性最小值 | 
| [hidAbsFuzz](#hidabsfuzz) | 绝对坐标属性模糊值 | 
| [hidAbsFlat](#hidabsflat) | 绝对坐标属性固定值 | 


## 结构体成员变量说明


### hidEventTypes


```
struct Hid_EventTypeArray Hid_EventProperties::hidEventTypes
```

**描述:**

事件类型属性编码数组


### hidKeys


```
struct Hid_KeyCodeArray Hid_EventProperties::hidKeys
```

**描述:**

键值属性编码数组


### hidAbs


```
struct Hid_AbsAxesArray Hid_EventProperties::hidAbs
```

**描述:**

绝对坐标属性数组


### hidRelBits


```
struct Hid_RelAxesArray Hid_EventProperties::hidRelBits
```

**描述:**

相对坐标属性数组


### hidMiscellaneous


```
struct Hid_MscEventArray Hid_EventProperties::hidMiscellaneous
```

**描述:**

其它特殊事件属性编码数组


### hidAbsMax


```
int32_t Hid_EventProperties::hidAbsMax[64]
```

**描述:**

绝对坐标属性最大值


### hidAbsMin


```
int32_t Hid_EventProperties::hidAbsMin[64]
```

**描述:**

绝对坐标属性最小值


### hidAbsFuzz


```
int32_t Hid_EventProperties::hidAbsFuzz[64]
```

**描述:**

绝对坐标属性模糊值


### hidAbsFlat


```
int32_t Hid_EventProperties::hidAbsFlat[64]
```

**描述:**

绝对坐标属性固定值
