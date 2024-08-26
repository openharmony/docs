# 泛Sensor子系统变更说明

## cl.sensors.1 vibrator VibratePreset的count属性由必选变更为可选

**访问级别**

公开接口

**变更原因**

VibratePreset中的效果振动次数参数count作为必选参数对于开发者使用不便，即使设为1也必须要填写。

**变更影响**

该变更为不兼容性变更。

变更前：VibratePreset中的属性count为必选属性，必须设置。

变更后：VibratePreset中的属性count变更为可选属性，默认值为1。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.27开始。

**变更的接口**

@ohos.vibrator.d.ts中VibratePreset的属性count。

**适配指导**

VibratePreset中的效果振动次数属性count变更为可选参数，如果开发者对改属性的类型存在依赖，需进行适配。
