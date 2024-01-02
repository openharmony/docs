# ArkUI子系统变更说明

## cl.arkui.1 菜单背板的默认视觉效果变更为模糊材质

**访问级别**

公开接口。

**变更原因**

增强视觉效果。

**变更影响**

该变更为兼容性变更。在统一渲染模式下，菜单背板的默认视觉效果变更为模糊材质。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.5.2 版本开始。

**变更的接口/组件**

涉及到左键菜单（[bindMenu](../../../application-dev/reference/arkui-ts/ts-universal-attributes-menu.md)）、右键菜单（[bindContextMenu](../../../application-dev/reference/arkui-ts/ts-universal-attributes-menu.md)）、下拉选项菜单（[Select](../../../application-dev/reference/arkui-ts/ts-basic-components-select.md)）、导航组件工具栏的更多悬浮菜单（[Navigation](../../../application-dev/reference/arkui-ts/ts-basic-components-navigation.md)）等菜单背板的默认视觉效果以及下拉选项菜单（Select）的[optionHeight](../../../application-dev/reference/arkui-ts/ts-basic-components-select.md#属性)接口：

- 变更前：菜单背板显示为白色。

  optionHeight接口设置Select组件下拉菜单项高度。

  Select组件下拉按钮文本到左边界距离与箭头图标到右边界距离为12vp。

  Select组件下拉按钮与下拉菜单之间对齐时横坐标略有偏移。

  Select组件下拉按钮与下拉菜单之间距离4vp。

- 变更后：菜单背板显示为模糊材质。

  optionHeight接口设置Select组件下拉菜单显示最大高度。

  Select组件下拉按钮文本到左边界距离与箭头图标到右边界距离为16vp。

  Select组件下拉按钮与下拉菜单之间横坐标无偏移。

  Select组件下拉按钮与下拉菜单之间距离8vp。

**适配指导**

无需适配。