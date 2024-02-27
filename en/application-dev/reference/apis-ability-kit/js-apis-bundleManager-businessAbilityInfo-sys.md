# BusinessAbilityInfo (System API)

The **BusinessAbilityInfo** module provides basic information about a business ability.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## BusinessAbilityInfo

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                             | Type                                                        | Readable| Writable| Description                |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | -------------------- |
| bundleName                        | string                                                       | Yes  | No  | Bundle name.|
| moduleName                        | string                                                       | Yes  | No  | Module name.|
| name                              | string                                                       | Yes  | No  | Name of the business ability.|
| labelId                           | number                                                       | Yes  | No  | Label ID of the module.      |
| descriptionId                     | number                                                       | Yes  | No  | Description ID of the module.      |
| iconId                            | number                                                       | Yes  | No  | ID of the icon that describes the ability information.|
| businessType | [businessAbilityRouter.BusinessType](js-apis-businessAbilityRouter-sys.md#businesstype) | Yes| No| Type of the business ability.|
| applicationInfo | Array\<[ApplicationInfo](js-apis-bundleManager-applicationInfo.md)> | Yes  | No  | Application information. |
