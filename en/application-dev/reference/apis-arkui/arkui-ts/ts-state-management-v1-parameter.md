# State Management V1 Decorator Parameters
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liwenzhen3-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ProvideOptions

[\@Provide](../../../ui/state-management/arkts-provide-and-consume.md) configuration options for controlling whether \@Provide can be overridden. For details, see [Support for the allowOverride Parameter](../../../ui/state-management/arkts-provide-and-consume.md#support-for-the-allowoverride-parameter).

**Widget capability**: This API can be used in ArkTS widgets since API version 11.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description    |
| ------ | ---- | ---- | ------------ |
|allowOverride|string|No|Whether \@Provide can be overridden. By default, overriding is not supported.|
