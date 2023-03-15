# @ohos.InputMethodExtensionContext (InputMethodExtensionContext)

The **InputMethodExtensionContext** module, inherited from **ExtensionContext**, provides context for **InputMethodExtension** abilities.

You can use the APIs of this module to start, terminate, connect, and disconnect abilities.

> **NOTE**
>
>The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```
import InputMethodExtensionContext from '@ohos.InputMethodExtensionContext';
```

## Usage

Before using the **InputMethodExtensionContext** module, you must define a child class that inherits from **InputMethodExtensionAbility**.

```js
import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
class EntryAbility extends InputMethodExtensionAbility {
    onCreate() {
        let context = this.context;
    }
}
```

## InputMethodExtensionContext.destroy

destroy(callback: AsyncCallback\<void>): void

Terminates this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```js
this.context.destroy((err) => {
    console.log('destroy result:' + JSON.stringify(err));
});
```

## InputMethodExtensionContext.destroy

destroy(): Promise\<void>;

Terminates this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void>; | Promise that returns no value.|

**Example**

```js
this.context.destroy().then(() => {
    console.log('Succeeded in destroying context.');
}).catch((error) => {
    console.log('Failed to destroy context: ' + JSON.stringify(error));
});
```
