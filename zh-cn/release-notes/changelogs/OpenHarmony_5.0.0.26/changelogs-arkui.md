# ArkUI子系统Changelog

## cl.arkui.1 线性DataPanel组件默认圆角尺寸变更并可以自定义圆角尺寸

**访问级别**

公开接口

**变更原因**

线性DataPanel组件的圆角尺寸不能改变，导致开发者无法自定义线性DataPanel组件的圆角尺寸。新增支持自定义线性DataPanel组件的圆角尺寸，增强开发者自定义能力。

**变更影响**

该变更为非兼容性变更。

变更前：
线性DataPanel组件默认是胶囊形状。不能自定义线性DataPanel组件的圆角。

变更后：
线性DataPanel组件默认圆角的是小圆角。可以自定义线性DataPanel组件的圆角尺寸，调用borderRadius设置圆角尺寸。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.26开始。

**适配指导**

默认圆角效果变更，无需适配，如不接受变更后的默认圆角效果，可以调用borderRadius自定义修改圆角尺寸以达到预期。