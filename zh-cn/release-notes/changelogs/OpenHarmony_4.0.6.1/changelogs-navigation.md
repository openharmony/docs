# ArkUI子系统ChangeLog

OpenHarmony 4.0.6.1 版本相较于OpenHarmony 之前的版本，Navigation、NavDestination 组件默认行为变更如下。

## Navigation、NavDestination组件默认扩展到非安全区

满足安全区可拓展的条件下，Navigation、NavDestination组件默认扩展到非安全区

**访问级别**

公开接口

**变更影响**

变更前：Navigation、NavDestination组件默认不会扩展到非安全区

变更后：Navigation与NavDestination组件默认扩展到非安全区。组件大小撑满整个屏幕，背景色延伸到顶部状态栏和底部导航栏。

**API Level**

11

**变更发生版本**

OpenHarmony SDK 4.0.6.1

**变更的接口/组件**

受影响组件有：Navigation与Navdestination

**适配指导**

默认行为变更，不涉及适配。