# 系统组件调用


系统组件为上层应用提供基础能力，包括SAMGR（系统服务框架子系统）、DFX子系统等。在板级系统移植过程中，只需要选择使用即可，不用对其进行适配。


## SAMGR

**基本介绍**


系统服务框架基于面向服务的架构，提供了服务开发、服务的子功能开发、对外接口的开发、以及多服务共进程、进程间服务调用等开发能力。


> ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
> 本组件在板级系统移植中必须要使用，否则其他服务组件无法运行。


**SAMGR使用说明，请参考：[SAMGR 使用指导](https://gitee.com/openharmony/distributedschedule_samgr_lite/blob/master/README_zh.md)**


## DFX

**基本介绍**

DFX子系统主要包含DFR（Design for Reliability，可靠性）和DFT（Design for Testability，可测试性）特性，为开发者提供代码维测信息。

**DFX子系统使用说明，请参考：[DFX子系统使用指导 ](../subsystems/subsys-dfx-overview.md)**