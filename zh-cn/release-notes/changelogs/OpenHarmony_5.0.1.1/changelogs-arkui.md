# ArkUI子系统Changelog

## cl.arkui.1 属性动画onFinish结束回调在UIAbility退后台时因有限循环动画被终止而提前触发

**访问级别**

公开接口

**变更原因**

属性动画在UIAbility退后台时不会停止而是继续步进，此时动画不显示但持续请求Vsync，造成了不必要的功耗浪费，故而需要变更动画行为。变更为，在UIAbility退后台时，其包含的有限循环动画会立即结束，无限循环动画依旧不结束。


**变更影响**

该变更为不兼容变更。

变更前：onFinish接口在相应属性动画结束时触发回调。动画不感知UIAbility的前后台状态，UIAbility退后台后，动画仍按照所设时长和循环次数步进至完成，并触发结束回调。

变更后：onFinish接口在相应属性动画结束时触发回调。动画感知UIAbility的前后台状态，UIAbility退后台时，如果此时有限循环动画还未结束，该动画会被停止至终点态并触发onFinish结束回调。无限循环动画不受退后台影响，不会停止。

**起始API Level**

7

**变更发生版本**

从OpenHarmony 5.0.1.1开始。

**变更的接口/组件**

AnimateParam和KeyframeAnimateParam的onFinish接口。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。