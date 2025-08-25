# 自定义组件参数
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## ComponentOptions<sup>11+</sup>

自定义组件参数，用于配置是否支持组件冻结。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

> **说明：**
>
> 从API version 11开始，支持通过此参数配置[@Component](../../../ui/state-management/arkts-create-custom-components.md#component)组件冻结。例子可见[自定义组件冻结](../../../ui/state-management/arkts-custom-components-freeze.md)。
>
> 从API version 12开始，支持通过此参数配置[@ComponentV2](../../../ui/state-management/arkts-new-componentV2.md)组件冻结。例子可见[自定义组件冻结](../../../ui/state-management/arkts-custom-components-freezeV2.md)。
>

| 名称 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | ------------ |
|freezeWhenInactive|boolean|是|配置自定义组件支持组件冻结。true：开启组件冻结，false：不开启组件冻结。|
