# UIExtensionContext (System API)

**UIExtensionContext**, inherited from [ExtensionContext](js-apis-inner-application-extensionContext.md), provides the context environment for [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md). It provides UIExtensionAbility-related configuration and APIs for operating the UIExtensionAbility. For example, you can use the APIs to start a UIExtensionAbility.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## UIExtensionContext.startAbilityForResultAsCaller

startAbilityForResultAsCaller(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;

Starts an ability with the caller information specified. This API uses a promise to return the result.

The caller information is carried in **want** and identified at the system service layer. The ability can obtain the caller information from the **want** parameter in the **onCreate** lifecycle callback.

When this API is used to start an ability, the caller information carried in **want** is not overwritten by the current application information. The system service layer can obtain the initial caller information.

 - Normally, you can call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability. The result is returned to the caller.
 - If an exception occurs, for example, the ability is killed, an error message, in which **resultCode** is **-1**, is returned to the caller.
 - If different applications call this API to start an ability that uses the singleton mode and then call [terminateSelfWithResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to terminate the ability, the normal result is returned to the last caller, and an exception message, in which **resultCode** is **-1**, is returned to others.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type                                               | Mandatory | Description                     |
| ------- | --------------------------------------------------- | ---- | ------------------------- |
| want    | [Want](js-apis-app-ability-want.md)                 | Yes  | Want information about the target ability.  |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No  | Parameters used for starting the ability. |

**Return value**

| Type                                                        | Description                     |
| ------------------------------------------------------------ | ------------------------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise used to return the result. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID | Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401| Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist.                   |
| 16000004 | Can not start invisible component.                      |
| 16000050 | Internal error.                                         |
| 16000073 | The app clone index is invalid. |

**Example**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtension extends UIExtensionAbility {
  onForeground() {
    this.context.startAbilityForResultAsCaller({
      bundleName: 'com.example.startabilityforresultascaller',
      abilityName: 'EntryAbility',
      moduleName: 'entry'
    }).then((data) => {
      console.log('=======>startAbilityForResultAsCaller data Promise ======>' + JSON.stringify(data));
    }).catch((error: BusinessError) => {
      console.log('=======>startAbilityForResultAsCaller error.code Promise ======>' + error.code);
    });
  }
}
```
