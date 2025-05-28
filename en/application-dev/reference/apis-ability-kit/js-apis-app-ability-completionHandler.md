# @ohos.app.ability.CompletionHandler (CompletionHandler)

**CompletionHandler** is an optional parameter of [StartOptions](js-apis-app-ability-startOptions.md) and is used to handle the results of application launching requests.


> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.


## Constraints

Currently, this module can be used in the following APIs:
- [startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-2)
- [startAbilityForResult](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability-2)

<!--Del-->
- [startAbilityForResultWithAccount](js-apis-inner-application-uiAbilityContext-sys.md#uiabilitycontextstartabilityforresultwithaccount-2)
- [startAbilityWithAccount](js-apis-inner-application-uiAbilityContext-sys.md#uiabilitycontextstartabilitywithaccount-2)
- [startRecentAbility](js-apis-inner-application-uiAbilityContext-sys.md#uiabilitycontextstartrecentability-2)
- [startAbilityAsCaller](js-apis-inner-application-uiAbilityContext-sys.md#uiabilitycontextstartabilityascaller10-2)
<!--DelEnd-->

## Modules to Import

```ts
import { CompletionHandler } from '@kit.AbilityKit';
```

## CompletionHandler

CompletionHandler provides two callback functions, [onRequestSuccess](#onrequestsuccess) and [onRequestFailure](#onrequestfailure), to handle the results of successful and failed application launching requests, respectively.

### onRequestSuccess

onRequestSuccess(elementName: ElementName, message: string): void

Callback invoked when the application is successfully launched.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | Yes| Element name of the launched application.|
| message | string | Yes| Message displayed when the application is successfully launched. This message is in JSON format, as follows:<br>{<br>    "errMsg": "Succeeded."<br>}<br>|

**Example**

See [Usage of CompletionHandler](#usage-of-completionhandler).

### onRequestFailure

onRequestFailure(elementName: ElementName, message: string): void

Callback invoked when the application fails to be launched.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md) | Yes| Element name of the application that fails to be launched.|
| message | string | Yes| Message displayed when the application fails to be launched. This message is in JSON format, as follows:<br>{<br>    "errMsg": "xxx"<br>}<br>The value of *xxx* is described as follows:<br>Failed to call \<api-name\>: An error occurs when calling the API. \<api-name\> is the specific API name, for example, **startAbility**.<br>User refused redirection: The user has closed the application redirection dialog box.<br>User closed the implicit startup picker: The user has closed the dialog box for selecting an application for implicit startup.<br>User closed the app clone picker: The user has closed the dialog box for selecting a cloned application.<br>Free installation failed: The free installation fails.<br>|

**Example**

See [Usage of CompletionHandler](#usage-of-completionhandler).

### Usage of CompletionHandler

  ```ts
  import { UIAbility, Want, StartOptions, CompletionHandler, bundleManager } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class EntryAbility extends UIAbility {
    onForeground() {
      let want: Want = {
        deviceId: '',
        bundleName: 'com.example.myapplication',
        abilityName: 'EntryAbility'
      };

      let completionHandler: CompletionHandler = {
        onRequestSuccess: (elementName: bundleManager.ElementName, message: string): void => {
          console.log(`${elementName.bundleName}-${elementName.moduleName}-${elementName.abilityName} start succeeded: ${message}`);
        },
        onRequestFailure: (elementName: bundleManager.ElementName, message: string): void => {
          console.log(`${elementName.bundleName}-${elementName.moduleName}-${elementName.abilityName} start failed: ${message}`);
        }
      };

      let options: StartOptions = {
        completionHandler: completionHandler
      };

      try {
        this.context.startAbility(want, options, (err: BusinessError) => {
          if (err.code) {
            // Process service logic errors.
            console.error(`startAbility failed, code is ${err.code}, message is ${err.message}`);
            return;
          }
          // Carry out normal service processing.
          console.info('startAbility succeed');
        });
      } catch (err) {
        // Process input parameter errors.
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        console.error(`startAbility failed, code is ${code}, message is ${message}`);
      }
    }
  }
  ```
