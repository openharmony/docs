# MultiAppMode (系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wendel-->
<!--Designer: @wendel-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

MultiAppMode用于定义应用是否支持多开模式，包括不支持多开、支持多实例模式和应用分身模式三种类型。

> **说明：**
> 
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。
> 本模块接口为系统接口。

## 使用说明

调用appManager的[getRunningMultiAppInfo](js-apis-app-ability-appManager-sys.md#appmanagergetrunningmultiappinfo12)方法获取MultiAppMode属性。

## MultiAppMode

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 值 | 说明 | 
| -------- |----|-------- |
| NOT_SUPPORTED | 0 | 应用不支持多开模式。 |
| MULTI_INSTANCE<sup>14+</sup>  | 1 | 应用支持多实例模式。<br>**说明：** 只支持2in1设备。 |
| APP_CLONE | 2 | 应用支持分身模式。分身模式允许为应用创建独立的副本实例，每个实例拥有独立的数据空间，适用于需要隔离用户数据的场景。 |