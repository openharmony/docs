# ElementName

The **ElementName** module provides element name information, which can be obtained through [Context.getElementName](js-apis-inner-app-context.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## ElementName<sup>(deprecated)</sup>

> This API is deprecated since API version 9. You are advised to use [bundleManager-ElementName](js-apis-bundleManager-elementName.md) instead.

Describes the element name information, which identifies the basic information about an ability and is obtained through [Context.getElementName](js-apis-inner-app-context.md).

**System capability**: SystemCapability.BundleManager.BundleFramework

| Name                    | Type    | Readable| Writable| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| deviceId                | string   | Yes  | Yes  | Device ID.                  |
| bundleName              | string   | Yes  | Yes  | Bundle name.         |
| abilityName             | string   | Yes  | Yes  | Ability name.              |
| uri                     | string   | Yes  | Yes  | Resource ID.                |
| shortName               | string   | Yes  | Yes  | Short name of the ability.              |
