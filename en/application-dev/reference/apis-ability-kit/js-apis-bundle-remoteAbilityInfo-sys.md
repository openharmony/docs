# RemoteAbilityInfo (System API)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The module provides information about a remote ability.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module are deprecated since API version 9. You are advised to use [bundleManager-RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md) instead.
> 
> The APIs provided by this module are system APIs.

## RemoteAbilityInfo<sup>(deprecated)<sup>

This API is deprecated since API version 9. You are advised to use [bundleManager-RemoteAbilityInfo](js-apis-bundleManager-remoteAbilityInfo-sys.md#remoteabilityinfo) instead.

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**System API**: This is a system API.

| Name       | Type                                        | Read-Only| Optional| Description                   |
| ----------- | -------------------------------------------- | ---- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundle-ElementName.md) | Yes  | No  | Element name information of the ability.      |
| label       | string                                       | Yes  | No  | Ability name.  |
| icon        | string                                       | Yes  | No  | Icon of the ability.|
