# System Modules<a name="EN-US_TOPIC_0000001063871490"></a>

-   [SAMGR](#section105874301910)
-   [DFX](#section20064420420)

System modules, such as the system ability manager \(SAMGR\) and DFX subsystem, provide basic capabilities for upper-layer applications. During board-level system porting, you can directly select the system modules as required without any adaptation.

## SAMGR<a name="section105874301910"></a>

**Introduction**

This service-oriented framework enables you to develop services, features, and external APIs, and implement multi-service process sharing and service invocation for inter-process communication \(IPC\).

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>This module must be used during board-level system porting. Otherwise, other service modules cannot run properly.

For details about how to use SAMGR, see  [Service Framework Subsystem](https://gitee.com/openharmony/docs/blob/master/docs-en/readme/service-framework-subsystem.md).

## DFX<a name="section20064420420"></a>

**Introduction**

The design for X \(DFX\) subsystem mainly includes design for reliability \(DFR\) and design for testability \(DFT\), providing code maintenance and testing.

For details, see  **[DFX](../subsystems/DFX.md)**.

