# 窗口子系统变更说明

## cl.window.1 module.json5的supportWindowMode属性配置fullscreen和split时，或在startOptions的supportWindowModes属性配置FULL_SCREEN和SPLIT时，PC/2in1设备窗口由自由窗口状态启动变更为全屏启动

**访问级别**

公开接口

**变更原因**

PC/2in1设备上，在module.json5的[supportWindowMode](../../../application-dev/quick-start/module-configuration-file.md#abilities标签)属性配置fullscreen和split时，或在startOptions的[supportWindowModes](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-startOptions.md)属性配置FULL_SCREEN和SPLIT时，窗口将以自由窗口状态启动，与预期效果不符。

**变更影响**

此变更涉及应用适配。

变更前：module.json5的supportWindowMode属性配置fullscreen和split时，或在startOptions的supportWindowModes属性配置FULL_SCREEN和SPLIT时，PC/2in1设备上以自由窗口启动。

变更后：module.json5的supportWindowMode属性配置fullscreen和split时，或在startOptions的supportWindowModes属性配置FULL_SCREEN和SPLIT时，2PC/2in1设备上窗口全屏启动。

**起始 API Level**

module.json5的supportWindowMode属性从API version 9开始支持。

startOptions的supportWindowModes属性从API version 14开始支持。

**变更发生版本**

从OpenHarmony SDK 5.1.0.52开始。

**变更的接口/组件**

module.json5中supportWindowMode标签

@ohos.app.ability.StartOptions的supportWindowModes属性

**适配指导**

API version 15及之后的版本, 开发者需要关注在module.json5的supportWindowMode属性配置fullscreen和split时，或在startOptions的supportWindowModes属性配置FULL_SCREEN和SPLIT时，2in1设备上窗口全屏启动。
若预期是以自由窗口启动，则需要在module.json5的supportWindowMode属性配置增加floating配置项，或在startOptions的supportWindowModes属性中增加FLOATING配置项。
