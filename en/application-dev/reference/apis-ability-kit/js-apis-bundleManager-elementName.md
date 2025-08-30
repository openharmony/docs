# ElementName
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

A structured identifier for an application component, containing fields such as **bundleName**, **moduleName**, and **abilityName**. It is usually used in [AbilityRunningInfo.ability](../apis-ability-kit/js-apis-inner-application-abilityRunningInfo.md) for component launch information and in the [connectOptions.onConnect](../apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect) callback for component connection.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
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
| shortName               | string   | No  |  Yes | Short name of the ability. It is a string starting with a period (.).              |
| moduleName              | string   | No  |  Yes | Module name of the HAP file to which the ability belongs.  |
