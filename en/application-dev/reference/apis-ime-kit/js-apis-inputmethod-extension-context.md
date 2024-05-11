# @ohos.InputMethodExtensionContext (InputMethodExtensionContext)

The **InputMethodExtensionContext** module, inherited from **ExtensionContext**, provides context for **InputMethodExtension** abilities. You can use the APIs of this module to start, terminate, connect, and disconnect abilities.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import InputMethodExtensionContext from '@ohos.InputMethodExtensionContext';
```

## Usage

Before using the **InputMethodExtensionContext** module, you must define a child class that inherits from **InputMethodExtensionAbility**.

```ts
import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
import Want from '@ohos.app.ability.Want';
class InputMethodExtnAbility extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    let context = this.context;
  }
}
```

## InputMethodExtensionContext.destroy

destroy(callback: AsyncCallback\<void>): void

Destroys this input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class InputMethodExtnAbility extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    let context = this.context;
  }
  onDestroy() {
    this.context.destroy((err: BusinessError) => {
      if(err) {
        console.log(`Failed to destroy context, err code = ${err.code}`);
        return;
      }
      console.log('Succeeded in destroying context.');
    });
  }
}
```

## InputMethodExtensionContext.destroy

destroy(): Promise\<void>;

Destroys this input method. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

class InputMethodExtnAbility extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    let context = this.context;
  }
  onDestroy() {
    this.context.destroy().then(() => {
      console.log('Succeed in destroying context.');
    }).catch((err: BusinessError)=>{
      console.log(`Failed to destroy context, err code = ${err.code}`);
    });
  }
}
```

## InputMethodExtensionContext.startAbility

startAbility(want: Want): Promise<**void**>;

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Want information related to the extension ability to start, including the ability name and bundle name.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Ability Error Codes](../apis-ability-kit/errorcode-ability.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 16000001 | The specified ability does not exist.                   |
| 16000004 | Can not start invisible component.                      |
| 16000005 | The specified process does not have the permission.     |
| 16000006 | Cross-user operations are not allowed.                  |
| 16000008 | The crowdtesting application expires.                   |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.                             |
| 16000012 | The application is controlled.                          |
| 16000013 | The application is controlled by EDM.                   |
| 16000050 | Internal error.                                         |
| 16000053 | The ability is not on the top of the UI.                |
| 16000055 | Installation-free timed out.                            |
| 16000061 | Can not start component belongs to other bundle.        |
| 16200001 | The caller has been released.                           |

**Example**

```ts
import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

try {
  this.context.startAbility(want).then((err) => {
    if (err !== undefined) {
      this.addLog(`startAbility error: ${err} `);
    }
  }).catch((err) => {
    let error = err as BusinessError;
    this.addLog(`startAbility error: ${error.code} ${error.message}`);
  })
} catch (err) {
  let error = err as BusinessError;
  this.addLog(`startAbility error: ${error.code} ${error.message}`);
}
```
