# InputMethodExtensionContext

The **InputMethodExtensionContext** module, inherited from **ExtensionContext**, provides context for **InputMethodExtension** abilities.

You can use the APIs of this module to start, terminate, connect, and disconnect abilities.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```
import InputMethodExtensionContext from '@ohos.inputmethodextensioncontext';
```

## Usage

Before using the **InputMethodExtensionContext** module, you must define a child class that inherits from **InputMethodExtensionAbility**.

```js
  import InputMethodExtensionAbility from '@ohos.inputmethodextensionability';
  class MainAbility extends InputMethodExtensionAbility {
      onCreate() {
          let context = this.context;
      }
  }
```

## InputMethodExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void;

Starts an ability with the **want** parameter. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | Yes| Information about the target ability, such as the ability name and bundle name.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
    let want = {
        'bundleName': 'com.example.myapp',
        'abilityName': 'MyAbility'
    };
    this.context.startAbility(want, (err) => {
        console.log('startAbility result:' + JSON.stringify(err));
    });
  ```

## InputMethodExtensionContext.startAbility

startAbility(want: Want, options?: StartOptions): Promise\<void>;

Starts an ability with the mandatory **want** and optional **options** parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | Yes| Information about the target ability, such as the ability name and bundle name.|
| options | [StartOptions](js-apis-application-StartOptions.md) | No| Parameters used for starting the ability.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.| 

**Example**

  ```js
    let want = {
        'bundleName': 'com.example.myapp',
        'abilityName': 'MyAbility'
    };
    this.context.startAbility(want).then((data) => {
        console.log('success:' + JSON.stringify(data));
    }).catch((error) => {
        console.log('failed:' + JSON.stringify(error));
    });

  ```

## InputMethodExtensionContext.startAbility

startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void

Starts an ability with the **want** and **options** parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md)  | Yes| Information about the target ability.|
| options | [StartOptions](js-apis-application-StartOptions.md) | Yes| Parameters used for starting the ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var want = {
  	'deviceId': '',
  	'bundleName': 'com.extreme.test',
  	'abilityName': 'MainAbility'
  };
  var options = {
  	windowMode: 0,
  };
  this.context.startAbility(want, options, (error) => {
      console.log('error.code = ' + error.code)
  })
  ```

## InputMethodExtensionContext.terminateSelf

terminateSelf(callback: AsyncCallback&lt;void&gt;): void;

Terminates this ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

  ```js
this.context.terminateSelf((err) => {
    console.log('terminateSelf result:' + JSON.stringify(err));
});
  ```

## InputMethodExtensionContext.terminateSelf

terminateSelf(): Promise&lt;void&gt;;

Terminates this ability. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.| 

**Example**

  ```js
  this.context.terminateSelf().then((data) => {
      console.log('success:' + JSON.stringify(data));
  }).catch((error) => {
      console.log('failed:' + JSON.stringify(error));
  });
  ```
