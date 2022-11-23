# RemoteAbilityInfo

The **RemoteAbilityInfo** module provides information about a remote ability, which can be obtained through [distributedBundle.getRemoteAbilityInfo](js-apis-distributedBundle.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## RemoteAbilityInfo

**System capability**: SystemCapability.BundleManager.DistributedBundleFramework

**System API**: This is a system API.

| Name       | Type                                        | Readable| Writable| Description                   |
| ----------- | -------------------------------------------- | ---- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | Yes  | No  | Element name information of the remote ability.      |
| label       | string                                       | Yes  | No  | Label of the remote ability.  |
| icon        | string                                       | Yes  | No  | Icon of the remote ability.|
