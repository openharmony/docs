# AppVersionInfo

The **AppVersionInfo** module defines the application version information. You can use [getAppVersionInfo](js-apis-inner-app-context.md#contextgetappversioninfo7) to obtain the version information of the current application.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import featureAbility from '@ohos.ability.featureAbility';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name       | Type  | Readable| Writable| Description          |
| ----------- | ------ | ---- | ---- | -------------- |
| appName     | string | Yes  | No  | Application name.    |
| versionCode | number | Yes  | No  | Application version code.|
| versionName | string | Yes  | No  | Application version name.  |
