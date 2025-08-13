# ElementName

The module provides element name information, which can be obtained through [Context.getElementName](js-apis-inner-app-context.md#contextgetelementname7).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { featureAbility } from '@kit.AbilityKit';
```

## ElementName

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

| Name                    | Type    | Read Only| Optional| Description                      |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| deviceId                | string   | No  |  Yes | Device ID.                  |
| bundleName              | string   | No  |  No | Bundle name.         |
| abilityName             | string   | No  |  No | Name of the ability.              |
| uri                     | string   | No  |  Yes | Resource ID.                |
| shortName               | string   | No  |  Yes | Short name of the ability.              |
| moduleName              | string   | No  |  Yes | Module name of the HAP file to which the ability belongs.  |
