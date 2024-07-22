# ArkUI子系统Changelog

## cl.arkui.1 MenuItem设置enable为false时字体颜色变更

**访问级别**

公开接口

**变更原因**

MenuItem设置enable为false时，无法自适应自定义字体颜色

**变更影响**

该变更为不兼容性变更。

变更前：MenuItem设置enable为false时，字体颜色为默认字体颜色 * 不透明度40%

变更后：MenuItem设置enable为false时，字体颜色为自定义字体颜色或默认字体颜色 * 不透明度40%

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.34开始。

**变更的接口/组件**

MenuIten组件。

**适配指导**

默认行为变更，无需适配。