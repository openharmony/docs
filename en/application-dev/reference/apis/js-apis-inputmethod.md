# @ohos.inputmethod

The **inputMethod** module provides an input method framework, which can be used to hide the keyboard, obtain the list of installed input methods, display the dialog box for input method selection, and more.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import inputMethod from '@ohos.inputmethod';
```

## Constants<sup>8+</sup>

Provides the constants.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Value| Description|
| -------- | -------- | -------- | -------- |
| MAX_TYPE_NUM | number | 128 | Maximum number of supported input methods.|

## InputMethodProperty<sup>8+</sup>

Describes the input method application attributes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| name<sup>9+</sup>  | string | Yes| No| Internal name of the input method. Mandatory.|
| id<sup>9+</sup>    | string | Yes| No| Unique ID of the input method. Mandatory.|
| label<sup>9+</sup>    | string | Yes| No| External display name of the input method. Optional.|
| icon<sup>9+</sup>    | string | Yes| No| Icon of the input method. Optional.|
| iconId<sup>9+</sup>    | number | Yes| No| Icon ID of the input method. Optional.|
| extra<sup>9+</sup>    | object | Yes| Yes| Extra information about the input method. Mandatory.|
| packageName<sup>(deprecated)</sup> | string | Yes| No| Name of the input method package. Mandatory.<br>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. You are advised to use **name**.|
| methodId<sup>(deprecated)</sup> | string | Yes| No| Unique ID of the input method. Mandatory.<br>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. You are advised to use **id**.|

## inputMethod.getController<sup>9+</sup>

getController(): InputMethodController

Obtains an **[InputMethodController](#inputmethodcontroller)** instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                           | Description                    |
| ----------------------------------------------- | ------------------------ |
| [InputMethodController](#inputmethodcontroller) | Current **InputMethodController** instance.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                    |
| -------- | ------------------------------ |
| 12800006 | Input method controller error. |

**Example**

```js
let inputMethodController = inputMethod.getController();
```

## inputMethod.getSetting<sup>9+</sup>

getSetting(): InputMethodSetting

Obtains an **[InputMethodSetting](#inputmethodsetting8)** instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | Current **InputMethodSetting** instance.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800007 | Input method settings extension error. |

**Example**

```js
let inputMethodSetting = inputMethod.getSetting();
```

## inputMethod.switchInputMethod<sup>9+</sup>

switchInputMethod(target: InputMethodProperty, callback: AsyncCallback&lt;boolean&gt;): void

Switches to another input method. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| target | [InputMethodProperty](#inputmethodproperty8) | Yes| Input method to switch to.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**Example**

```js
let im = inputMethod.getCurrentInputMethod();
let prop = {
    packageName: im.packageName,
    methodId: im.methodId,
    name: im.packageName,
    id: im.methodId,
    extra: {}
}
try{
    inputMethod.switchInputMethod(prop, (err, result) => {
        if (err !== undefined) {
            console.error('Failed to switchInputMethod: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Succeeded in switching inputmethod.');
        } else {
            console.error('Failed to switchInputMethod.');
        }
    });
} catch(err) {
    console.error('Failed to switchInputMethod: ' + JSON.stringify(err));
}
```
## inputMethod.switchInputMethod<sup>9+</sup>
switchInputMethod(target: InputMethodProperty): Promise&lt;boolean&gt;

Switches to another input method. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|target |  [InputMethodProperty](#inputmethodproperty8)| Yes| Input method to switch to.|

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the switching is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**Example**

```js
let im = inputMethod.getCurrentInputMethod();
let prop = {
    packageName: im.packageName,
    methodId: im.methodId,
    name: im.packageName,
    id: im.methodId,
    extra: {}
}
try {
    inputMethod.switchInputMethod(prop).then((result) => {
        if (result) {
            console.info('Succeeded in switching inputmethod.');
        } else {
            console.error('Failed to switchInputMethod.');
        }
    }).catch((err) => {
        console.error('Failed to switchInputMethod: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to switchInputMethod: ' + JSON.stringify(err));
}
```

## inputMethod.getCurrentInputMethod<sup>9+</sup>

getCurrentInputMethod(): InputMethodProperty

Obtains the current input method. This API synchronously returns the **InputmethodProperty** instance of the current input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                        | Description                    |
| -------------------------------------------- | ------------------------ |
| [InputMethodProperty](#inputmethodproperty8) | **InputmethodProperty** instance of the current input method.|

**Example**

```js
let currentIme = inputMethod.getCurrentInputMethod();
```

## inputMethod.switchCurrentInputMethodSubtype<sup>9+</sup>

switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void

Switches to another subtype of the current input method. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| target |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| Yes| Input method subtype to switch to.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**Example**

```js
try {
    inputMethod.switchCurrentInputMethodSubtype({
      id: "com.example.kikakeyboard",
      label: "ServiceExtAbility",
      name: "",
      mode: "upper",
      locale: "",
      language: "",
      icon: "",
      iconId: 0,
      extra: {}
    }, (err, result) => {
        if (err !== undefined) {
            console.error('Failed to switchCurrentInputMethodSubtype: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Succeeded in switching currentInputMethodSubtype.');
        } else {
            console.error('Failed to switchCurrentInputMethodSubtype');
        }
    });
} catch(err) {
    console.error('Failed to switchCurrentInputMethodSubtype: ' + JSON.stringify(err));
}
```

## inputMethod.switchCurrentInputMethodSubtype<sup>9+</sup>

switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise&lt;boolean&gt;

Switches to another subtype of the current input method. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|target |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| Yes| Input method subtype to switch to.|

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the switching is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**Example**

```js
try {
    inputMethod.switchCurrentInputMethodSubtype({
      id: "com.example.kikakeyboard",
      label: "ServiceExtAbility",
      name: "",
      mode: "upper",
      locale: "",
      language: "",
      icon: "",
      iconId: 0,
      extra: {}
    }).then((result) => {
        if (result) {
            console.info('Succeeded in switching currentInputMethodSubtype.');
        } else {
            console.error('Failed to switchCurrentInputMethodSubtype.');
        }
    }).catch((err) => {
        console.error('Failed to switchCurrentInputMethodSubtype: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to switchCurrentInputMethodSubtype: ' + JSON.stringify(err));
}
```

## inputMethod.getCurrentInputMethodSubtype<sup>9+</sup>

getCurrentInputMethodSubtype(): InputMethodSubtype

Obtains the current input method subtype.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                        | Description                    |
| -------------------------------------------- | ------------------------ |
| [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype) | Current input method subtype.|

**Example**

```js
let currentImeSubType = inputMethod.getCurrentInputMethodSubtype();
```

## inputMethod.switchCurrentInputMethodAndSubtype<sup>9+</sup>

switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void

Switches to a specified subtype of a specified input method. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|inputMethodProperty |  [InputMethodProperty](#inputmethodproperty8)| Yes| Input method to switch to.|
|inputMethodSubtype |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| Yes| Input method subtype to switch to.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**Example**

```js
let im = inputMethod.getCurrentInputMethod();
let inputMethodProperty = {
    packageName: im.packageName,
    methodId: im.methodId,
    name: im.packageName,
    id: im.methodId,
    extra: {}
}
try {
    inputMethod.switchCurrentInputMethodAndSubtype(inputMethodProperty, {
      id: "com.example.kikakeyboard",
      label: "ServiceExtAbility",
      name: "",
      mode: "upper",
      locale: "",
      language: "",
      icon: "",
      iconId: 0,
      extra: {}
    }, (err,result) => {
        if (err !== undefined) {
            console.error('Failed to switchCurrentInputMethodAndSubtype: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Succeeded in switching currentInputMethodAndSubtype.');
        } else {
            console.error('Failed to switchCurrentInputMethodAndSubtype.');
        }
    });
} catch (err) {
    console.error('Failed to switchCurrentInputMethodAndSubtype: ' + JSON.stringify(err));
}
```

## inputMethod.switchCurrentInputMethodAndSubtype<sup>9+</sup>

switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise&lt;boolean&gt;

Switches to a specified subtype of a specified input method. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|inputMethodProperty |  [InputMethodProperty](#inputmethodproperty8)| Yes| Input method to switch to.|
|inputMethodSubtype |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| Yes| Input method subtype to switch to.|

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the switching is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | Configuration persisting error.        |
| 12800008 | Input method manager service error. |

**Example**

```js
let im = inputMethod.getCurrentInputMethod();
let inputMethodProperty = {
    packageName: im.packageName,
    methodId: im.methodId,
    name: im.packageName,
    id: im.methodId,
    extra: {}
}
try {
    inputMethod.switchCurrentInputMethodAndSubtype(inputMethodProperty, {
      id: im.packageName,
      label: im.methodId,
      name: "",
      mode: "upper",
      locale: "",
      language: "",
      icon: "",
      iconId: 0,
      extra: {}
    }).then((result) => {
        if (result) {
            console.info('Succeeded in switching currentInputMethodAndSubtype.');
        } else {
            console.error('Failed to switchCurrentInputMethodAndSubtype.');
        }
    }).catch((err) => {
        console.error('Failed to switchCurrentInputMethodAndSubtype: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to switchCurrentInputMethodAndSubtype: ' + JSON.stringify(err));
}
```

## inputMethod.getInputMethodController<sup>(deprecated)</sup>

getInputMethodController(): InputMethodController

Obtains an **[InputMethodController](#inputmethodcontroller)** instance.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getController()](#inputmethodgetcontroller9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                           | Description                    |
| ----------------------------------------------- | ------------------------ |
| [InputMethodController](#inputmethodcontroller) | Current **InputMethodController** instance.|

**Example**

```js
let inputMethodController = inputMethod.getInputMethodController();
```

## inputMethod.getInputMethodSetting<sup>(deprecated)</sup>

getInputMethodSetting(): InputMethodSetting

Obtains an **[InputMethodSetting](#inputmethodsetting8)** instance.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getSetting()](#inputmethodgetsetting9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | Current **InputMethodSetting** instance.|

**Example**

```js
let inputMethodSetting = inputMethod.getInputMethodSetting();
```

## InputMethodController

In the following API examples, you must first use [getController](#inputmethodgetcontroller9) to obtain an **InputMethodController** instance, and then call the APIs using the obtained instance.

### stopInputSession<sup>9+</sup>

stopInputSession(callback: AsyncCallback&lt;boolean&gt;): void

Ends this input session. The invoking of this API takes effect only after the input session is enabled by clicking the text box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**Example**

```js
try {
    inputMethodController.stopInputSession((error, result) => {
        if (error !== undefined) {
            console.error('Failed to stopInputSession: ' + JSON.stringify(error));
            return;
        }
        if (result) {
            console.info('Succeeded in stopping inputSession.');
        } else {
            console.error('Failed to stopInputSession.');
        }
    });
} catch(error) {
    console.error('Failed to stopInputSession: ' + JSON.stringify(error));
}
```

### stopInputSession<sup>9+</sup>

stopInputSession(): Promise&lt;boolean&gt;

Ends this input session. The invoking of this API takes effect only after the input session is enabled by clicking the text box. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the ending is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**Example**

```js
try {
    inputMethodController.stopInputSession().then((result) => {
        if (result) {
            console.info('Succeeded in stopping inputSession.');
        } else {
            console.error('Failed to stopInputSession.');
        }
    }).catch((err) => {
        console.error('Failed to stopInputSession: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to stopInputSession: ' + JSON.stringify(err));
}
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

Shows this soft keyboard. This API must be used with the input text box and works only when the input text box is activated. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**Example**

```js
inputMethodController.showSoftKeyboard((err) => {
    if (err === undefined) {
        console.info('Succeeded in showing softKeyboard.');
    } else {
        console.error('Failed to showSoftKeyboard: ' + JSON.stringify(err));
    }
})
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(): Promise&lt;void&gt;

Shows this soft keyboard. This API must be used with the input text box and works only when the input text box is activated. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**Example**

```js
inputMethodController.showSoftKeyboard().then(() => {
    console.log('Succeeded in showing softKeyboard.');
}).catch((err) => {
    console.error('Failed to showSoftKeyboard: ' + JSON.stringify(err));
});
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

Hides this soft keyboard. This API must be used with the input text box and works only when the input text box is activated. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**Example**

```js
inputMethodController.hideSoftKeyboard((err) => {
    if (err === undefined) {
        console.info('Succeeded in hiding softKeyboard.');
    } else {
        console.error('Failed to hideSoftKeyboard: ' + JSON.stringify(err));
    }
})
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(): Promise&lt;void&gt;

Hides this soft keyboard. This API must be used with the input text box and works only when the input text box is activated. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | Input method client error.             |
| 12800008 | Input method manager service error. |

**Example**

```js
inputMethodController.hideSoftKeyboard().then(() => {
    console.log('Succeeded in hiding softKeyboard.');
}).catch((err) => {
    console.error('Failed to hideSoftKeyboard: ' + JSON.stringify(err));
});
```

### stopInput<sup>(deprecated)</sup>

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

Ends this input session. The invoking of this API takes effect only after the input session is enabled by clicking the text box. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [stopInputSession()](#stopinputsession9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object. |

**Example**

```js
inputMethodController.stopInput((error, result) => {
    if (error !== undefined) {
        console.error('Failed to stopInput: ' + JSON.stringify(error));
        return;
    }
    if (result) {
        console.info('Succeeded in stopping input.');
    } else {
        console.error('Failed to stopInput.');
    }
});
```

### stopInput<sup>(deprecated)</sup>

stopInput(): Promise&lt;boolean&gt;

Ends this input session. The invoking of this API takes effect only after the input session is enabled by clicking the text box. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [stopInputSession()](#stopinputsession9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the hiding is successful, and **false** means the opposite.|

**Example**

```js
inputMethodController.stopInput().then((result) => {
    if (result) {
        console.info('Succeeded in stopping input.');
    } else {
        console.error('Failed to stopInput.');
    }
}).catch((err) => {
    console.error('Failed to stopInput: ' + err);
})
```

## InputMethodSetting<sup>8+</sup>

In the following API examples, you must first use [getSetting](#inputmethodgetsetting9) to obtain an **InputMethodSetting** instance, and then call the APIs using the obtained instance.

### on('imeChange')<sup>9+</sup>

on(type: 'imeChange', callback: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void

Enables listening for the input method and subtype change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | Yes  | Listening type.<br>The value **'imeChange'** indicates the input method and subtype change event.|
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)) => void  | Yes| Callback used to return the input method attributes and subtype.|

**Example**

```js
inputMethodSetting.on('imeChange', (inputMethodProperty, inputMethodSubtype) => {
    console.info('Succeeded in subscribing imeChange: inputMethodProperty: ' + JSON.stringify(inputMethodProperty) + " , inputMethodSubtype: " + JSON.stringify(inputMethodSubtype));
});
```

### off('imeChange')<sup>9+</sup>

off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void

Disables listening for the input method and subtype change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | Yes  | Listening type.<br>The value **'imeChange'** indicates the input method and subtype change event.|
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)) => void  | No| Callback used to return the input method attributes and subtype.|

**Example**

```js
inputMethodSetting.off('imeChange');
```

### listInputMethodSubtype<sup>9+</sup>

listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback&lt;Array&lt;InputMethodSubtype&gt;&gt;): void

Obtains all subtypes of a specified input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| inputMethodProperty | InputMethodProperty| Yes| Input method to which the subtypes belong.|
| callback | AsyncCallback&lt;Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>&gt; | Yes| Callback used to return all subtypes of the specified input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**Example**

```js
let inputMethodProperty = {
    packageName: 'com.example.kikakeyboard',
    methodId: 'com.example.kikakeyboard',
    name: 'com.example.kikakeyboard',
    id: 'com.example.kikakeyboard',
    extra:{}
}
try {
    inputMethodSetting.listInputMethodSubtype(inputMethodProperty, (err,data) => {
        if (err !== undefined) {
            console.error('Failed to listInputMethodSubtype: ' + JSON.stringify(err));
            return;
        }
        console.log('Succeeded in listing inputMethodSubtype.');
    });
} catch (err) {
    console.error('Failed to listInputMethodSubtype: ' + JSON.stringify(err));
}
```

### listInputMethodSubtype<sup>9+</sup>

listInputMethodSubtype(inputMethodProperty: InputMethodProperty): Promise&lt;Array&lt;InputMethodSubtype&gt;&gt;

Obtains all subtypes of a specified input method. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| inputMethodProperty | InputMethodProperty| Yes| Input method to which the subtypes belong.|

**Return value**

| Type                                                       | Description                  |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>> | Promise used to return all subtypes of the specified input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**Example**

```js
let inputMethodProperty = {
    packageName: 'com.example.kikakeyboard',
    methodId: 'com.example.kikakeyboard',
    name: 'com.example.kikakeyboard',
    id: 'com.example.kikakeyboard',
    extra:{}
}
try {
    inputMethodSetting.listInputMethodSubtype(inputMethodProperty).then((data) => {
        console.info('Succeeded in listing inputMethodSubtype.');
    }).catch((err) => {
        console.error('Failed to listInputMethodSubtype: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to listInputMethodSubtype: ' + JSON.stringify(err));
}
```

### listCurrentInputMethodSubtype<sup>9+</sup>

listCurrentInputMethodSubtype(callback: AsyncCallback&lt;Array&lt;InputMethodSubtype&gt;&gt;): void

Obtains all subtypes of this input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>&gt; | Yes  | Callback used to return all subtypes of the current input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**Example**

```js
try {
    inputMethodSetting.listCurrentInputMethodSubtype((err, data) => {
        if (err !== undefined) {
            console.error('Failed to listCurrentInputMethodSubtype: ' + JSON.stringify(err));
            return;
        }
        console.log('Succeeded in listing currentInputMethodSubtype.');
    });
} catch(err) {
    console.error('Failed to listCurrentInputMethodSubtype: ' + JSON.stringify(err));
}
```

### listCurrentInputMethodSubtype<sup>9+</sup>

listCurrentInputMethodSubtype(): Promise&lt;Array&lt;InputMethodSubtype&gt;&gt;

Obtains all subtypes of this input method. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                                       | Description                  |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>> | Promise used to return all subtypes of the current input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**Example**

```js
try {
    inputMethodSetting.listCurrentInputMethodSubtype().then((data) => {
        console.info('Succeeded in listing currentInputMethodSubtype.');
    }).catch((err) => {
        console.error('Failed to listCurrentInputMethodSubtype: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to listCurrentInputMethodSubtype: ' + JSON.stringify(err));
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean, callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

Obtains a list of activated or deactivated input methods. In the current version, an activated input method is the input method in use, and a deactivated one is any of the installed input methods except the one in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                               | Mandatory| Description                         |
| -------- | --------------------------------------------------- | ---- | ----------------------------- |
| enable   | boolean                                             | Yes  | Whether to return a list of activated input methods. The value **true** means to return a list of activated input methods, and **false** means to return a list of deactivated input methods.      |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; | Yes  | Callback used to return a list of activated or deactivated input methods.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**Example**

```js
try {
    inputMethodSetting.getInputMethods(true, (err,data) => {
        if (err !== undefined) {
            console.error('Failed to getInputMethods: ' + JSON.stringify(err));
            return;
        }
        console.log('Succeeded in getting inputMethods.');
    });
} catch (err) {
    console.error('Failed to getInputMethods: ' + JSON.stringify(err));
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

Obtains a list of activated or deactivated input methods. In the current version, an activated input method is the input method in use, and a deactivated one is any of the installed input methods except the one in use. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type   | Mandatory| Description                   |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | Yes  | Whether to return a list of activated input methods. The value **true** means to return a list of activated input methods, and **false** means to return a list of deactivated input methods.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | Package manager error.                 |
| 12800008 | Input method manager service error. |

**Return value**

| Type                                                        | Description                         |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise used to return a list of activated or deactivated input methods.|

**Example**

```js
try {
    inputMethodSetting.getInputMethods(true).then((data) => {
        console.info('Succeeded in getting inputMethods.');
    }).catch((err) => {
        console.error('Failed to getInputMethods: ' + JSON.stringify(err));
    })
} catch(err) {
    console.error('Failed to getInputMethods: ' + JSON.stringify(err));
}
```

### showOptionalInputMethods<sup>9+</sup>

showOptionalInputMethods(callback: AsyncCallback&lt;boolean&gt;): void

Displays a dialog box for selecting an input method. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800008 | Input method manager service error. |

**Example**

```js
try {
    inputMethodSetting.showOptionalInputMethods((err, data) => {
        if (err !== undefined) {
            console.error('Failed to showOptionalInputMethods: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in showing optionalInputMethods.');
    });
} catch (err) {
    console.error('Failed to showOptionalInputMethods: ' + JSON.stringify(err));
}
```

### showOptionalInputMethods<sup>9+</sup>

showOptionalInputMethods(): Promise&lt;boolean&gt;

Displays a dialog box for selecting an input method. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (available only to system applications)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the operation is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800008 | Input method manager service error. |

**Example**

```js
inputMethodSetting.showOptionalInputMethods().then((data) => {
    console.info('Succeeded in showing optionalInputMethods.');
}).catch((err) => {
    console.error('Failed to showOptionalInputMethods: ' + JSON.stringify(err));
})
```

### listInputMethod<sup>(deprecated)</sup>

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

Obtains a list of installed input methods. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getInputMethods](#getinputmethods9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; | Yes  | Callback used to return the list of installed input methods.|

**Example**

```js
inputMethodSetting.listInputMethod((err,data) => {
    if (err !== undefined) {
        console.error('Failed to listInputMethod: ' + JSON.stringify(err));
        return;
    }
    console.log('Succeeded in listing inputMethod.');
 });
```

### listInputMethod<sup>(deprecated)</sup>

listInputMethod(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

Obtains a list of installed input methods. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getInputMethods](#getinputmethods9-1).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                                       | Description                  |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise used to return the list of installed input methods.|

**Example**

```js
inputMethodSetting.listInputMethod().then((data) => {
    console.info('Succeeded in listing inputMethod.');
}).catch((err) => {
    console.error('Failed to listInputMethod: ' + JSON.stringify(err));
})
```

### displayOptionalInputMethod<sup>(deprecated)</sup>

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

Displays a dialog box for selecting an input method. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [showOptionalInputMethods()](#showoptionalinputmethods9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Example**

```js
inputMethodSetting.displayOptionalInputMethod((err) => {
    if (err !== undefined) {
        console.error('Failed to displayOptionalInputMethod: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in displaying optionalInputMethod.');
});
```

### displayOptionalInputMethod<sup>(deprecated)</sup>

displayOptionalInputMethod(): Promise&lt;void&gt;

Displays a dialog box for selecting an input method. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [showOptionalInputMethods()](#showoptionalinputmethods9-1).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
inputMethodSetting.displayOptionalInputMethod().then(() => {
    console.info('Succeeded in displaying optionalInputMethod.');
}).catch((err) => {
    console.error('Failed to displayOptionalInputMethod: ' + JSON.stringify(err));
})
```
