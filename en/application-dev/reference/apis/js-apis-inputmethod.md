# Input Method Framework

The **inputMethod** module provides an input method framework, which can be used to hide the keyboard, obtain the list of installed input methods, display the dialog box for input method selection, and more.

>  **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import inputMethod from '@ohos.inputmethod';
```

## inputMethod<sup>8+</sup>

Provides the constants.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| MAX_TYPE_NUM | number | Yes| No| Maximum number of supported input methods.|


## InputMethodProperty<sup>8+</sup>

Describes the input method application attributes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| packageName | string | Yes| No| Package name.|
| methodId | string | Yes| No| Ability name.|

## inputMethod.getInputMethodController

getInputMethodController(): InputMethodController

Obtains an **[InputMethodController](#inputmethodcontroller)** instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                           | Description                    |
| ----------------------------------------------- | ------------------------ |
| [InputMethodController](#inputmethodcontroller) | Current **InputMethodController** instance.|

**Example**

```js
  var InputMethodController = inputMethod.getInputMethodController();
```

## inputMethod.getInputMethodSetting<sup>8+</sup>

getInputMethodSetting(): InputMethodSetting

Obtains an **[InputMethodSetting](#inputmethodsetting8)** instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | Current **InputMethodSetting** instance.|


**Example**

```js
  var InputMethodSetting = inputMethod.getInputMethodSetting();
```
## inputMethod.switchInputMethod<sup>9+</sup>

switchInputMethod(target: InputMethodProperty, callback: AsyncCallback&lt;boolean&gt;): void

Switches to another input method. This API can be used only in the stage model. It uses an asynchronous callback to return the result. If the required two parameters are not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|target | [InputmethodProperty](#inputmethodproperty8) | Yes| Input method to switch to.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the execution result.|


**Example**

```js
inputMethod.switchInputMethod({packageName:'com.example.kikakeyboard', methodId:'com.example.kikakeyboard'} ,(err,result) => {
    if (err) {
        console.error('switchInputMethod err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to switchInputMethod.(callback)');
    } else {
        console.error('Failed to switchInputMethod.(callback)');
    }
});
```
## inputMethod.switchInputMethod<sup>9+</sup>
switchInputMethod(target: InputMethodProperty): Promise&lt;boolean&gt;

Switches to another input method. This API can be used only in the stage model. It uses a promise to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|target |  [InputmethodProperty](#inputmethodproperty8)| Yes| Input method to switch to.|

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the execution result.|

**Example**


```js
inputMethod.switchInputMethod({packageName:'com.example.kikakeyboard', methodId:'com.example.kikakeyboard'}).then((result) => {
    if (result) {
        console.info('Success to switchInputMethod.(promise)');
    } else {
        console.error('Failed to switchInputMethod.(promise)');
    }
}).catch((err) => {
    console.error('switchInputMethod promise err: ' + err);
})
```
## inputMethod.getCurrentInputMethod<sup>9+</sup>

getCurrentInputMethod(): InputMethodProperty

Obtains the current input method. This API synchronously returns the **InputmethodProperty** instance of the current input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                        | Description                    |
| -------------------------------------------- | ------------------------ |
| [InputmethodProperty](#inputmethodproperty8) | **InputmethodProperty** instance of the current input method.|

**Example**


```js
var currentIme = inputMethod.getCurrentInputMethod();
```

## InputMethodController

In the following API examples, you must first use **[getInputMethodController](#inputmethodgetinputmethodcontroller)** to obtain an **InputMethodController** instance, and then call the APIs using the obtained instance.

### stopInput

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

Hides the keyboard. This API uses an asynchronous callback to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return whether the keyboard is successfully hidden.|

**Example**

```js
InputMethodController.stopInput((error, result) => {
    if (error) {
        console.error('failed to stopInput because: ' + JSON.stringify(error));
        return;
    }
    if (result) {
        console.info('Success to stopInput.(callback)');
    } else {
        console.error('Failed to stopInput.(callback)');
    }
});
```

### stopInput

stopInput(): Promise&lt;boolean&gt;

Hides the keyboard. This API uses a promise to return the result. If any parameter is passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return whether the keyboard is successfully hidden.|

**Example**


```js
InputMethodController.stopInput().then((result) => {
    if (result) {
        console.info('Success to stopInput.(promise)');
    } else {
        console.error('Failed to stopInput.(promise)');
    }
}).catch((err) => {
    console.error('stopInput promise err: ' + err);
})
```

### showSoftKeyboard<sup>9+</sup> ###

showSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

Shows this soft keyboard. This API uses an asynchronous callback to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the execution result.|

**Example**

```js
InputMethodController.showSoftKeyboard((err) => {
    if (err === undefined) {
        console.info('showSoftKeyboard success');
    } else {
        console.error('showSoftKeyboard failed because : ' + JSON.stringify(err));
    }
})
```


### showSoftKeyboard<sup>9+</sup> ###

showSoftKeyboard(): Promise&lt;void&gt;

Shows this soft keyboard. This API uses a promise to return the result. If any parameter is passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
InputMethodController.showSoftKeyboard().then(async (err) => {
    console.log('showSoftKeyboard success');
}).catch((err) => {
    console.error('showSoftKeyboard promise err: ' + JSON.stringify(err));
});
```

### hideSoftKeyboard<sup>9+</sup> ###

hideSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

Hides this soft keyboard. This API uses an asynchronous callback to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the execution result.|

**Example**

```js
InputMethodController.hideSoftKeyboard((err) => {
    if (err === undefined) {
        console.info('hideSoftKeyboard success');
    } else {
        console.error('hideSoftKeyboard failed because : ' + JSON.stringify(err));
    }
})
```


### hideSoftKeyboard<sup>9+</sup> ###

hideSoftKeyboard(): Promise&lt;void&gt;

Hides this soft keyboard. This API uses a promise to return the result. If any parameter is passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
InputMethodController.hideSoftKeyboard().then(async (err) => {
    console.log('hideSoftKeyboard success');
}).catch((err) => {
    console.error('hideSoftKeyboard promise err: ' + JSON.stringify(err));
});
```

## InputMethodSetting<sup>8+</sup>

In the following API examples, you must first use **[getInputMethodSetting](#inputmethodgetinputmethodcontroller)** to obtain an **InputMethodSetting** instance, and then call the APIs using the obtained instance.

### listInputMethod<sup>9+</sup>

listInputMethod(enable: boolean, callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

Obtains a list of activated or deactivated input methods. This API uses an asynchronous callback to return the result. If the required two parameters are not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                               | Mandatory| Description                         |
| -------- | --------------------------------------------------- | ---- | ----------------------------- |
| enable   | boolean                                             | Yes  | Whether to return a list of activated input methods. The value **true** means to return a list of activated input methods, and **false** means to return a list of deactivated input methods.      |
| callback | Array<[InputMethodProperty](#inputmethodproperty8)> | Yes  | Callback used to return a list of activated or deactivated input methods.|

**Example**

```js
InputMethodSetting.listInputMethod(true, (err,data) => {
    if (err) {
        console.error('listInputMethod failed because: ' + JSON.stringify(err));
        return;
    }
    console.log('listInputMethod success');
 });
```

### listInputMethod<sup>9+</sup>

listInputMethod(enable: boolean): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

Obtains a list of activated or deactivated input methods. This API uses a promise to return the result. If any parameter is passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type   | Mandatory| Description                   |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | Yes  | Whether to return a list of activated input methods. The value **true** means to return a list of activated input methods, and **false** means to return a list of deactivated input methods.|

**Return value**

| Type                                                        | Description                         |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise used to return a list of activated or deactivated input methods.|

**Example**

```js
InputMethodSetting.listInputMethod(true).then((data) => {
    console.info('listInputMethod success');
}).catch((err) => {
    console.error('listInputMethod promise err: ' + err);
})
```

### listInputMethod

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

Obtains a list of installed input methods. This API uses an asynchronous callback to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | Array<[InputMethodProperty](#inputmethodproperty8)> | Yes  | Callback used to return the list of installed input methods.|

**Example**

```js
InputMethodSetting.listInputMethod((err,data) => {
    if (err) {
        console.error('listInputMethod failed because: ' + JSON.stringify(err));
        return;
    }
    console.log('listInputMethod success');
 });
```

### listInputMethod

listInputMethod(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

Obtains a list of installed input methods. This API uses a promise to return the result. If any parameter is passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                                       | Description                  |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise used to return the list of installed input methods.|

**Example**

```js
InputMethodSetting.listInputMethod().then((data) => {
    console.info('listInputMethod success');
}).catch((err) => {
    console.error('listInputMethod promise err: ' + err);
})
```

### displayOptionalInputMethod

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

Displays a dialog box for selecting an input method. This API uses an asynchronous callback to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

**Example**

```js
InputMethodSetting.displayOptionalInputMethod((err) => {
    if (err) {
        console.error('displayOptionalInputMethod failed because: ' + JSON.stringify(err));
        return;
    }
    console.info('displayOptionalInputMethod success');
});
```

### displayOptionalInputMethod

  displayOptionalInputMethod(): Promise&lt;void&gt;

  Displays a dialog box for selecting an input method. This API uses a promise to return the result. If any parameter is passed in, an exception is thrown.

  **System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
InputMethodSetting.displayOptionalInputMethod().then(() => {
    console.info('displayOptionalInputMethod success.(promise)');
}).catch((err) => {
    console.error('displayOptionalInputMethod promise err: ' + err);
})
```
