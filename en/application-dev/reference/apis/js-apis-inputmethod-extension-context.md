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
