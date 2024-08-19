# 泛Sensor子系统Changelog

## cl.sensors.1 vibrator VibratePreset属性变更

**访问级别**

公开接口

**变更原因**

VibratePreset中的效果振动次数参数count作为必选参数对于开发者使用不便，即使设为1也必须要填写。

**变更影响**

VibratePreset中的属性count由必选属性变更为可选属性。

API version 11及以前：count为必选参数，必须设置。

API version 12及以后：count为可选参数，默认值为1。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.38开始。

**适配指导**

VibratePreset中的效果振动次数属性count变更为可选参数，如果开发者对改属性的类型存在依赖，需进行适配。
