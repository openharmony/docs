# Input Method Framework

The **inputMethod** module provides an input method framework, which can be used to hide the keyboard, obtain the list of installed input methods, display the dialog box for input method selection, and more.

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import inputMethod from '@ohos.inputmethod';
```

## Constants

Provides the constants.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

| Name| Type| Value| Description|
| -------- | -------- | -------- | -------- |
| MAX_TYPE_NUM | number | 128 | Maximum number of supported input methods.|

## InputMethodProperty

Describes the input method application attributes.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| packageName | string | Yes| No| Name of the input method package.<br>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. You are advised to use **name**.|
| methodId | string | Yes| No| Unique ID of the input method.<br>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. You are advised to use **id**.|



## inputMethod.getInputMethodController

getInputMethodController(): InputMethodController

Obtains an **[InputMethodController](#inputmethodcontroller)** instance.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Return value**

| Type                                           | Description                    |
| ----------------------------------------------- | ------------------------ |
| [InputMethodController](#inputmethodcontroller) | Current **InputMethodController** instance.|

**Example**

```js
let inputMethodController = inputMethod.getInputMethodController();
```

## inputMethod.getInputMethodSetting

getInputMethodSetting(): InputMethodSetting

Obtains an **[InputMethodSetting](#inputmethodsetting)** instance.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#inputmethodsetting) | Current **InputMethodSetting** instance.|

**Example**

```js
let inputMethodSetting = inputMethod.getInputMethodSetting();
```

## InputMethodController

In the following API examples, you must first use [getInputMethodController](#inputmethodgetinputmethodcontroller) to obtain an **InputMethodController** instance, and then call the APIs using the obtained instance.

### stopInput

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

Ends this input session. The invoking of this API takes effect only after the input session is enabled by clicking the text box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object. |

**Example**

```js
inputMethodController.stopInput((error, result) => {
    if (error) {
        console.error('Failed to stop inputmethod session: ' + JSON.stringify(error));
        return;
    }
    if (result) {
        console.info('Succeeded in stopping inputmethod session.');
    } else {
        console.error('Failed to stop inputmethod session.');
    }
});
```

### stopInput

stopInput(): Promise&lt;boolean&gt;

Ends this input session. The invoking of this API takes effect only after the input session is enabled by clicking the text box. This API uses a promise to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the hiding is successful, and **false** means the opposite.|

**Example**

```js
inputMethodController.stopInput().then((result) => {
    if (result) {
        console.info('Succeeded in stopping inputmethod session.');
    } else {
        console.error('Failed to stop inputmethod session');
    }
})
```

## InputMethodSetting

In the following API examples, you must first use [getInputMethodSetting](#inputmethodgetinputmethodsetting) to obtain an **InputMethodSetting** instance, and then call the APIs using the obtained instance.

### listInputMethod

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

Obtains a list of installed input methods. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty)>&gt; | Yes  | Callback used to return the list of installed input methods.|

**Example**

```js
inputMethodSetting.listInputMethod((err, data) => {
    if(err) {
        console.error('Failed to list inputmethods: ' + JSON.stringify(err));
        return;
    }
    console.log('Succeeded in listing inputmethods, data: ' + JSON.stringify(data));
 });
```

### listInputMethod

listInputMethod(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

Obtains a list of installed input methods. This API uses a promise to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Return value**

| Type                                                       | Description                  |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise used to return the list of installed input methods.|

**Example**

```js
inputMethodSetting.listInputMethod().then((data) => {
    console.info('Succeeded in listing inputMethod.');
}).catch((err) => {
    console.error('Failed to list inputMethod: ' + JSON.stringify(err));
})
```

### displayOptionalInputMethod

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

Displays a dialog box for selecting an input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Example**

```js
inputMethodSetting.displayOptionalInputMethod((err) => {
    if (err) {
        console.error('Failed to display optionalInputMethod:' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in displaying optionalInputMethod.');
});
```

### displayOptionalInputMethod

displayOptionalInputMethod(): Promise&lt;void&gt;

Displays a dialog box for selecting an input method. This API uses a promise to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
inputMethodSetting.displayOptionalInputMethod().then(() => {
    console.info('Succeeded in displaying optionalInputMethod.');
}).catch((err) => {
    console.error('Failed to display optionalInputMethod: ' + JSON.stringify(err));
})
```
