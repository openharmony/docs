# ExtensionAbilityInfo

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. API version 9 is a canary version for trial use. The APIs of this version may be unstable.

## Modules to Import
```js
import bundle from "@ohos.bundle";
```


## AbilityInfo

Provides the ability information.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                   | Type                   | Readable  | Writable  | Description                      |
| --------------------- | --------------------- | ---- | ---- | ------------------------ |
| bundleName            | string                | Yes   | No   | Bundle name of the application.                    |
| moduleName            | string                | Yes   | No   | Name of the HAP file to which the ability belongs.       |
| name                  | string                | Yes   | No   | Ability name.               |
| labelId               | number                | Yes   | No   | Ability label ID.            |
| descriptionId         | number                | Yes   | No   | Ability description ID.            |
| iconId                | number                | Yes   | No   | Ability icon ID.            |
| isVisible             | boolean               | Yes   | No   | Whether the ability can be called by other applications.    |
| extensionAbilityType  | bundle.ExtensionAbilityType | Yes  | No  | Type of the Extension ability.     |
| permissions           | Array\<string>        | Yes   | No   | Permissions required for other applications to call the ability.|
| applicationInfo       | ApplicationInfo       | Yes   | No   | Application configuration information.               |
| metaData              | Array\<Metadata>      | Yes   | No   | Metadata of the ability.             |
| enabled               | boolean               | Yes   | No   | Whether the ability is enabled.             |
| readPermission        | string                | Yes   | No   | Permission required for reading the ability data.        |
| writePermission       | string                | Yes   | No   | Permission required for writing data to the ability.        |
