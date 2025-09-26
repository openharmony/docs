# Custom Component Parameters
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ComponentOptions

Defines the custom component parameters used to configure whether component freezing is supported.

**Widget capability**: This API can be used in ArkTS widgets since API version 11.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

> **NOTE**
>
> Since API version 11, this parameter can be used to configure component freezing for [@Component](../../../ui/state-management/arkts-create-custom-components.md#component). For implementation examples, see [Freezing a Custom Component](../../../ui/state-management/arkts-custom-components-freeze.md).
>
> Since API version 12, this parameter can be used to configure component freezing for [@ComponentV2](../../../ui/state-management/arkts-new-componentV2.md). For implementation examples, see [Freezing a Custom Component](../../../ui/state-management/arkts-custom-components-freezeV2.md).
>

| Name| Type| Mandatory| Description    |
| ------ | ---- | ---- | ------------ |
|freezeWhenInactive|boolean|Yes|Whether to enable component freezing. The value **true** means to enable component freezing, and **false** means the opposite.|
