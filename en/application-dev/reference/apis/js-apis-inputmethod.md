# Input Method Framework

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import inputMethod from '@ohos.inputMethod';
```

## inputMethod<sup>6+</sup>

Provides the constants.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| MAX_TYPE_NUM | number | Yes| No| Maximum number of supported input methods.|


## InputMethodProperty<sup>6+</sup>

Describes the input method application attributes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| packageName | string | Yes| No| Package name.|
| methodId | string | Yes| No| Ability name.|

## inputMethod.getInputMethodController

getInputMethodController(): InputMethodController

Obtains an [InputMethodController](#InputMethodController) instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| [InputMethodController](#InputMethodController) | Returns the current **InputMethodController** instance.|

**Example**

```js
  var InputMethodController = inputMethod.getInputMethodController();
```

## inputMethod.getInputMethodSetting<sup>6+</sup>

getInputMethodSetting(): InputMethodSetting

Obtains an [InputMethodSetting](#InputMethodSetting) instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#InputMethodSetting) | Returns the current **InputMethodSetting** instance.|

**Example**

```js
  var InputMethodSetting = inputMethod.getInputMethodSetting();
```

## InputMethodController

In the following API examples, you must first use [getInputMethodController](#getInputMethodController) to obtain an **InputMethodController** instance, and then call the APIs using the obtained instance.

### stopInput

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

Hides the keyboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return whether the keyboard is successfully hidden.|

**Example**

```js
 InputMethodController.stopInput((error)=>{
     console.info('stopInput');
 });
```

### stopInput

stopInput(): Promise&lt;boolean&gt;

Hides the keyboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return whether the keyboard is successfully hidden.|

**Example**


```js
  var isSuccess = InputMethodController.stopInput();
  console.info('stopInput isSuccess = ' + isSuccess);
```

## InputMethodSetting<sup>6+</sup>

In the following API examples, you must first use [getInputMethodSetting](#getInputMethodSetting) to obtain an **InputMethodSetting** instance, and then call the APIs using the obtained instance.

### listInputMethod

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

Obtains the list of installed input methods. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | Array<[InputMethodProperty](#InputMethodProperty)> | Yes  | Callback used to return the list of installed input methods.|

**Example**

```js
  InputMethodSetting.listInputMethod((properties)=>{
    for (var i = 0;i < properties.length; i++) {
     var property = properties[i];
     console.info(property.packageName + "/" + property.methodId);
    }
  });
```

### listInputMethod

listInputMethod(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

Obtains the list of installed input methods. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                                       | Description                  |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#InputMethodProperty)>> | Promise used to return the list of installed input methods.|

**Example**

```js
  var properties = InputMethodSetting.listInputMethod();
  for (var i = 0;i < properties.length; i++) {
    var property = properties[i];
    console.info(property.packageName + "/" + property.methodId);
  }
```

### displayOptionalInputMethod

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

Displays a dialog box for selecting an input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

- Parameters

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

**Example**
```js
  InputMethodSetting.displayOptionalInputMethod(()=>{
   console.info('displayOptionalInputMethod is called');
   });
```

### displayOptionalInputMethod

displayOptionalInputMethod(): Promise&lt;void&gt;

Displays a dialog box for selecting an input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the execution result.|

**Example**

```js
  InputMethodSetting.displayOptionalInputMethod();
```