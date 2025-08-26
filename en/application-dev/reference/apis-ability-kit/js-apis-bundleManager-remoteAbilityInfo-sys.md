# RemoteAbilityInfo (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module provides information about a remote ability, which can be obtained through [distributedBundle.getRemoteAbilityInfo](js-apis-distributedBundleManager-sys.md#distributedbundlegetremoteabilityinfo).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## RemoteAbilityInfo

 **System capability**: SystemCapability.BundleManager.DistributedBundleFramework

 **System API**: This is a system API.

| Name       | Type                                        | Read-Only| Optional| Description                   |
| ----------- | -------------------------------------------- | ---- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | Yes  | No  | Element name information of the remote ability.      |
| label       | string                                       | Yes  | No  | Label of the remote ability.  |
| icon        | string                                       | Yes  | No  | Icon of the remote ability.|
