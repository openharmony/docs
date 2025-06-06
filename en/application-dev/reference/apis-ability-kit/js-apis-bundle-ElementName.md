# ElementName

The ElementName module provides element name information, which can be obtained through [Context.getElementName](js-apis-inner-app-context.md).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module are deprecated since API version 9. You are advised to use [bundleManager-ElementName](js-apis-bundleManager-elementName.md) instead.

## ElementName<sup>(deprecated)</sup>

This API is deprecated since API version 9. You are advised to use [bundleManager-ElementName](js-apis-bundleManager-elementName.md#elementname-1) instead.

Describes the element name information, which identifies the basic information about an ability and is obtained through [Context.getElementName](js-apis-inner-app-context.md).

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                    | Type    | Read-Only| Optional| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| deviceId                | string   | No  | Yes  | Device ID.                  |
| bundleName              | string   | No  | No | Bundle name.         |
| abilityName             | string   | No  | No | Ability name.              |
| uri                     | string   | No  | Yes | Resource ID.                |
| shortName               | string   | No  | Yes | Short name of the ability.              |
