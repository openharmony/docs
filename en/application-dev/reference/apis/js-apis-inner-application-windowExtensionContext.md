# WindowExtensionContext

The **WindowExtensionContext** module, inherited from [ExtensionContext](js-apis-inner-application-extensionContext.md), is the context environment of the WindowExtensionAbility.

The **WindowExtensionContext** module provides the capabilities of the [WindowExtensionAbility](js-apis-application-windowExtensionAbility.md), including starting the ability.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  - The APIs provided by this module are system APIs.
>
>  - The APIs of this module can be used only in the stage model.

## Usage

Before using the **WindowExtensionContext** module, you must define a child class that inherits from **WindowExtensionAbility**.

```ts
  import WindowExtensionAbility from '@ohos.application.WindowExtensionAbility';

  let context;
  class WindowExtAbility extends WindowExtensionAbility {
    onConnect() {
      context = this.context; // Obtain a WindowExtensionContext instance.
    }
  }
```

## WindowExtensionContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md)  | Yes| Want information about the target ability.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```ts
  let want = {
    bundleName: 'com.example.myapplication',
    abilityName: 'MainAbility'
  };
  let options = {
    windowMode: 102
  };

  try {
    this.context.startAbility(want, options, (error) => {
      if (error.code) {
        // Process service logic errors.
        console.log('startAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
        return;
      }
      // Carry out normal service processing.
      console.log('startAbility succeed');
    });
  } catch (paramError) {
    // Process input parameter errors.
    console.error('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```

## WindowExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise\<void>

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-want.md)  | Yes| Want information about the target ability, such as the ability name and bundle name.|
| options | [StartOptions](js-apis-app-ability-startOptions.md) | No| Parameters used for starting the ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```ts
  let want = {
    bundleName: 'com.example.myapp',
    abilityName: 'MainAbility'
  };
  let options = {
  	windowMode: 102,
  };

  try {
    this.context.startAbility(want, options)
      .then((data) => {
        // Carry out normal service processing.
        console.log('startAbility succeed');
      })
      .catch((error) => {
        // Process service logic errors.
        console.log('startAbility failed, error.code: ' + JSON.stringify(error.code) +
          ' error.message: ' + JSON.stringify(error.message));
      });
  } catch (paramError) {
    // Process input parameter errors.
    console.error('error.code: ' + JSON.stringify(paramError.code) +
      ' error.message: ' + JSON.stringify(paramError.message));
  }
  ```
