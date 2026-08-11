# Vibrator_Attribute
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @andeszhang-->
<!--Tester: @zhaofangyuan-->
<!--Adviser: @hu-zhiqiong-->

```c
typedef struct Vibrator_Attribute { ... } Vibrator_Attribute
```

## 概述

Vibrator_Attribute结构体用于描述马达的属性信息。开发者使用该结构体可以指定马达ID和振动场景。具体使用场景和实现机制请参见[Vibrator](capi-vibrator.md)模块文档。

**起始版本：** 11

**相关模块：** [Vibrator](capi-vibrator.md)

**所在头文件：** [vibrator_type.h](capi-vibrator-type-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t vibratorId | 马达ID，取值原则：通过系统接口获取有效值。指定要操作的马达设备标识，不同ID对应设备上不同的马达。取值范围为[0, 最大支持的马达数-1]。 |
| [Vibrator_Usage](capi-vibrator-type-h.md#vibrator_usage) usage | 振动场景。指定振动的应用场景，不同场景对应不同的振动模式（如通知、按键、闹钟等各有相应的振动效果），可选值见Vibrator_Usage枚举定义。 |