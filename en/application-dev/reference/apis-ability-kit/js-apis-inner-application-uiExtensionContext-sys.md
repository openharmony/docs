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

| Name | Type                                               | Mandatory| Description                     |
| ------- | --------------------------------------------------- | ---- | ------------------------- |
| want    | [Want](js-apis-app-ability-want.md)                 | Yes  | Want information about the target ability.  |
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No  | Parameters used for starting the ability.|

**Return value**

| Type                                                        | Description                     |
| ------------------------------------------------------------ | ------------------------- |
| Promise&lt;[AbilityResult](js-apis-inner-ability-abilityResult.md)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401| Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist.                   |
| 16000004 | Failed to start the invisible ability.                      |
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

## UIExtensionContext.startServiceExtensionAbility<sup>18+</sup>

startServiceExtensionAbility(want: Want): Promise\<void>

Starts a ServiceExtensionAbility. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------ |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information for starting the ServiceExtensionAbility.|

**Return value**

| Type| Description|
| ------ | ------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------ | ------ |
| 201 | The application does not have permission to call the interface. |
| 202 | The application is not system-app, can not use system-api. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      moduleName: 'entry',
      abilityName: 'ServiceExtensionAbility'
    };

    try {
      this.context.startServiceExtensionAbility(want)
        .then(() => {
          // Carry out normal service processing.
          console.info('startServiceExtensionAbility succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(`startServiceExtensionAbility failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startServiceExtensionAbility failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## UIExtensionContext.startServiceExtensionAbilityWithAccount<sup>18+</sup>

startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise\<void>

Starts a ServiceExtensionAbility under a specified system account. This API uses a promise to return the result.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
>
> Permission verification is not required when **accountId** specifies the current user.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------ |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information for starting the ServiceExtensionAbility.|
| accountId | number | Yes| ID of a system account. For details, see [getCreatedOsAccountsCount](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountcount9).|

**Return value**

| Type| Description|
| ------ | ------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------ | ------ |
| 201 | The application does not have permission to call the interface. |
| 202 | The application is not system-app, can not use system-api. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000011 | The context does not exist. |
| 16000012 | The application is controlled. |
| 16000013 | The application is controlled by EDM. |
| 16000019 | No matching ability is found. |
| 16000050 | Internal error. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIExtensionAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  onForeground() {
    let want: Want = {
      bundleName: 'com.example.myapplication',
      moduleName: 'entry',
      abilityName: 'ServiceExtensionAbility'
    };
    let accountId = 100;

    try {
      this.context.startServiceExtensionAbilityWithAccount(want, accountId)
        .then(() => {
          // Carry out normal service processing.
          console.info('startServiceExtensionAbilityWithAccount succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(`startServiceExtensionAbilityWithAccount failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`startServiceExtensionAbilityWithAccount failed, code is ${code}, message is ${message}`);
    }
  }
}
```

## UIExtensionContext.setHostPageOverlayForbidden<sup>15+</sup>

setHostPageOverlayForbidden(isForbidden: boolean) : void

Sets whether the page started by the [UIExtensionAbility](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md) can be overlaid by the page of the user.

> **NOTE**
>
> For details about the startup rules for the components in the stage model, see [Component Startup Rules (Stage Model)](../../application-models/component-startup-rules.md).
>
> This API must be called before a window is created. You are advised to call it within the [onCreate](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#uiextensionabilityoncreate) lifecycle of the [UIExtensionAbility](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md).

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------ |
| isForbidden | boolean | Yes| Whether the page started by the [UIExtensionAbility](../apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md) can be overlaid by the page of the user. The value **true** means that the page can be overlaid, and **false** means the opposite.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------ | ------ |
| 202 | The application is not system-app, can not use system-api. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |

**Example**

```ts
import { UIExtensionAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class UIExtAbility extends UIExtensionAbility {
  OnCreate() {
    try {
      this.context.setHostPageOverlayForbidden(true)
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`setHostPageOverlayForbidden failed, code is ${code}, message is ${message}`);
    }
  }
}
```
