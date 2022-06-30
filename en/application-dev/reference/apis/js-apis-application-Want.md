# Want

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

**Want** is the basic communication component of the system.

## Modules to Import

```
import Want from '@ohos.application.Want';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityBase

| Name       | Readable/Writable| Type                | Mandatory| Description                                                        |
| ----------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| deviceId    | Read only    | string               | No  | ID of the device running the ability.                               |
| bundleName   | Read only    | string               | No  | Bundle name of the ability. If both **bundleName** and **abilityName** are specified in a **Want** object, the **Want** object can match a specific ability.|
| abilityName  | Read only    | string               | No  | Name of the ability. If both **package** and **abilityName** are specified in a **Want** object, the **Want** object can match a specific ability.|
| uri          | Read only    | string               | No  | URI information to match. If **uri** is specified in a **Want** object, the **Want** object will match the specified URI information, including **scheme**, **schemeSpecificPart**, **authority**, and **path**.|
| type         | Read only    | string               | No  | MIME type, for example, **text/plain** or **image/***.  |
| flags        | Read only    | number               | No  | How the **Want** object will be handled. By default, numbers are passed in. For details, see [flags](js-apis-featureAbility.md#flags).|
| action      | Read only    | string               | No  | Action option.                          |
| parameters   | Read only    | {[key: string]: any} | No  | List of parameters in the **Want** object.                                      |
| entities    | Read only    | Array\<string>       | No  | List of entities.                                   |
| moduleName<sup>9+</sup> | Read only  | string | No   | Module to which the ability belongs. Different abilities among HAP files in an application may use the same name. If the abilities cannot be distinguished by the combination of **bundleName** and **abilityName**, you can set **moduleName** for better distinguishing.|                              |
