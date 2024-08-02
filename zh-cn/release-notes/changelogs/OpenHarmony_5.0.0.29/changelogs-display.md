# 窗口子系统Changelog

## cl.display.1 屏幕Display对象中的xDPI和yDPI属性的计算方法优化

**访问级别**

公开接口

**变更原因**

从API version 12开始，将屏幕Display对象中的xDPI和yDPI属性的计算修改为不跟随屏幕旋转变化。

**变更影响**

该变更为不兼容变更。

API version 11及以前，屏幕Display对象中的xDPI和yDPI属性的计算会跟随屏幕旋转变化而变化，导致应用查询到的xDPI和yDPI的值动态变化。

API version 12及以后，屏幕Display对象中的xDPI和yDPI属性的计算修改为不跟随屏幕旋转变化，应用查询到的是固定值。

**起始API Level**

首批接口从API version 7开始支持。

**变更发生版本**

从OpenHarmony SDK 5.0.0.29 版本开始。

**变更的接口/组件**

屏幕Display对象中的xDPI和yDPI属性。

**适配指导**

适配过程中应注意变更后的行为是否对界面显示效果产生影响。