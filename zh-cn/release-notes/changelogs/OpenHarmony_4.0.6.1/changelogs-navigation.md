# ArkUI子系统ChangeLog

OpenHarmony 4.0.6.1 版本相较于OpenHarmony 之前的版本，navigation兼容性变更如下。

## Navigation容器组件忽略安全区

Navigation配置忽略安全区后，在满足安全区可拓展的条件下背景色可扩展到非安全区。

**访问级别**

公开接口

**变更原因**

该变更为兼容性变更。组件收到忽略安全区配置项后，忽略安全区配置项同时设置给内部封装的容器组件，包括主页容器组件NavBar，NavDestination切换容器组件，NavDestination容器组件。Navigation与NavDestination容器大小撑满整个屏幕，背景色延伸到状态栏和导航栏。


**变更影响**

变更前：Navigation容器组件未配置忽略安全区，Navigation容器组件未被撑大

变更后：Navigation容器组件默认配置忽略安全区，Navigation容器组件被撑大。Navigation与NavDestination默认配置.expandSafeArea([SafeAreaType.SYSTEM],[SafeAreaEdge.BOTTOM, SafeAreaEdge.TOP])。

**API Level**

10

**变更发生版本**

从OpenHarmony SDK 4.0.6.1开始。

**变更的接口/组件**

受影响组件有：Navigation与Navdestination

**适配指导**

默认行为变更，不涉及适配。