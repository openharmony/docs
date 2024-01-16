# ArkUI子系统变更说明

## cl.arkui.1 Image组件autoResize interpolation属性默认行为变更

**访问级别**

公开接口

**变更原因**

应用侧需要设置autoResize为false、 interpolation设置为LOW来解决图片锯齿问题

**变更影响**

该变更为非兼容性变更。

变更前，Image组件的autoResize默认值为true， interpolation为None。

变更后，Image组件的autoResize默认值为false， interpolation为LOW，该修改会提升图片显示效果，但是image组件在大图显示成小组件时，默认内存会上涨，需要应用根据实际情况进行内存优化。
说明：该修改不影响大桌面效果。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.1 开始。

**变更的接口/组件**

受影响的组件有：Image。

**适配指导**

默认行为变更，不涉及适配。如果开发者需要保留原来Image组件显示的效果，可以将autoResize的值设置为true， interpolation的值设置为None。