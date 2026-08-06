# Hid_EventProperties
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @zgene94-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Hid_EventProperties {...} Hid_EventProperties
```

## 概述

设备事件属性，包括事件类型、键值、绝对坐标、相对坐标等各类事件属性编码及取值范围。用于HID设备的属性配置，适用于需要精细化管理输入事件的场景。使用结构体前，需根据HID设备规范初始化所有成员变量。

**起始版本：** 11

**相关模块：** [HidDdk](capi-hidddk.md)

**所在头文件：** [hid_ddk_types.h](capi-hid-ddk-types-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| struct [Hid_EventTypeArray](capi-hidddk-hid-eventtypearray.md) hidEventTypes | 事件类型属性编码数组，包含设备支持的事件类型集合，用于配置HID设备可触发的事件。 |
| struct [Hid_KeyCodeArray](capi-hidddk-hid-keycodearray.md) hidKeys | 键值属性编码数组，包含设备支持的按键编码集合，用于配置HID设备支持的按键功能。 |
| struct [Hid_AbsAxesArray](capi-hidddk-hid-absaxesarray.md) hidAbs | 绝对坐标属性编码数组，用于配置绝对坐标输入（如触摸屏、手柄摇杆）。 |
| struct [Hid_RelAxesArray](capi-hidddk-hid-relaxesarray.md) hidRelBits | 相对坐标属性编码数组，用于配置相对坐标输入（如鼠标移动）。 |
| struct [Hid_MscEventArray](capi-hidddk-hid-msceventarray.md) hidMiscellaneous | 其他特殊事件属性编码数组，用于配置特殊输入事件（如音量调节、电源键）。 |
| int32_t hidAbsMax[64] | 绝对坐标属性最大值。数组元素按索引对应各坐标轴，必须不小于对应坐标轴的最小值。 |
| int32_t hidAbsMin[64] | 绝对坐标属性最小值。数组元素按索引对应各坐标轴，必须不大于对应坐标轴的最大值。 |
| int32_t hidAbsFuzz[64] | 绝对坐标属性模糊值。数组元素按索引对应各坐标轴，用于定义输入事件的模糊容差，建议不超过坐标范围。 |
| int32_t hidAbsFlat[64] | 绝对坐标属性平坦值。数组元素按索引对应各坐标轴，用于定义输入事件死区的平坦范围（此范围内的值不触发事件上报），建议不超过模糊值。 |


