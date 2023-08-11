# @ohos.inputMethod (Input Method Framework)

The **inputMethod** module is oriented to common foreground applications (third-party applications and system applications such as Notes, Messaging, and Settings). It provides input method control and management capabilities, including displaying or hiding the soft keyboard, switching between input methods, and obtaining the list of all input methods.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import inputMethod from '@ohos.inputMethod';
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
| name<sup>9+</sup>  | string | Yes| No| Mandatory. Internal name of the input method.|
| id<sup>9+</sup>    | string | Yes| No| Mandatory. Unique ID of the input method.|
| label<sup>9+</sup>    | string | Yes| No| Optional. External name of the input method.|
| labelId<sup>10+</sup>    | string | Yes| No| Optional. External ID of the input method.|
| icon<sup>9+</sup>    | string | Yes| No| Optional. Icon of the input method. It can be obtained by using **iconId**. This parameter is reserved.|
| iconId<sup>9+</sup>    | number | Yes| No| Optional. Icon ID of the input method.|
| extra<sup>9+</sup>    | object | Yes| Yes| Extra information about the input method. This parameter is reserved and currently has no specific meaning.<br>- API version 10 and later: optional<br>- API version 9: mandatory|
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
| 12800006 | input method controller error. |

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
| 12800007 |  settings extension error. |

**Example**

```js
let inputMethodSetting = inputMethod.getSetting();
```

## inputMethod.switchInputMethod<sup>9+</sup>

switchInputMethod(target: InputMethodProperty, callback: AsyncCallback&lt;boolean&gt;): void

Switches to another input method. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| target | [InputMethodProperty](#inputmethodproperty8) | Yes| Input method to switch to.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**Example**

```js
let currentIme = inputMethod.getCurrentInputMethod();
try{
  inputMethod.switchInputMethod(currentIme, (err, result) => {
    if (err) {
      console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in switching inputmethod.');
    } else {
      console.error('Failed to switchInputMethod.');
    }
  });
} catch(err) {
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
}
```
## inputMethod.switchInputMethod<sup>9+</sup>
switchInputMethod(target: InputMethodProperty): Promise&lt;boolean&gt;

Switches to another input method. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

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
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**Example**

```js
let currentIme = inputMethod.getCurrentInputMethod();
try {
  inputMethod.switchInputMethod(currentIme).then((result) => {
    if (result) {
      console.log('Succeeded in switching inputmethod.');
    } else {
      console.error('Failed to switchInputMethod.');
    }
  }).catch((err) => {
    console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
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

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY

> **NOTE**
>
> - API version 10 and later: This API can be called by system applications and the current input method application.
> - API version 9: This API can be called by system applications only.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| target |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md)| Yes| Input method subtype to switch to.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**Example**

```js
try {
  inputMethod.switchCurrentInputMethodSubtype({
    id: "ServiceExtAbility",
    label: "",
    name: "com.example.kikakeyboard",
    mode: "upper",
    locale: "",
    language: "",
    icon: "",
    iconId: 0,
    extra: {}
  }, (err, result) => {
    if (err) {
      console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in switching currentInputMethodSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodSubtype');
    }
  });
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

## inputMethod.switchCurrentInputMethodSubtype<sup>9+</sup>

switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise&lt;boolean&gt;

Switches to another subtype of the current input method. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY

> **NOTE**
>
> - API version 10 and later: This API can be called by system applications and the current input method application.
> - API version 9: This API can be called by system applications only.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|target |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md)| Yes| Input method subtype to switch to.|

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the switching is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**Example**

```js
try {
  inputMethod.switchCurrentInputMethodSubtype({
    id: "ServiceExtAbility",
    label: "",
    name: "com.example.kikakeyboard",
    mode: "upper",
    locale: "",
    language: "",
    icon: "",
    iconId: 0,
    extra: {}
  }).then((result) => {
    if (result) {
      console.log('Succeeded in switching currentInputMethodSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodSubtype.');
    }
  }).catch((err) => {
    console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

## inputMethod.getCurrentInputMethodSubtype<sup>9+</sup>

getCurrentInputMethodSubtype(): InputMethodSubtype

Obtains the current input method subtype.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                        | Description                    |
| -------------------------------------------- | ------------------------ |
| [InputMethodSubtype](./js-apis-inputmethod-subtype.md) | Current input method subtype.|

**Example**

```js
let currentImeSubType = inputMethod.getCurrentInputMethodSubtype();
```

## inputMethod.switchCurrentInputMethodAndSubtype<sup>9+</sup>

switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void

Switches to a specified subtype of a specified input method. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|inputMethodProperty |  [InputMethodProperty](#inputmethodproperty8)| Yes| Input method to switch to.|
|inputMethodSubtype |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md)| Yes| Input method subtype to switch to.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**Example**

```js
let currentIme = inputMethod.getCurrentInputMethod();
let imSubType = inputMethod.getCurrentInputMethodSubtype();
try {
  inputMethod.switchCurrentInputMethodAndSubtype(currentIme, imSubType, (err,result) => {
    if (err) {
      console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in switching currentInputMethodAndSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodAndSubtype.');
    }
  });
} catch (err) {
  console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
}
```

## inputMethod.switchCurrentInputMethodAndSubtype<sup>9+</sup>

switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise&lt;boolean&gt;

Switches to a specified subtype of a specified input method. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|inputMethodProperty |  [InputMethodProperty](#inputmethodproperty8)| Yes| Input method to switch to.|
|inputMethodSubtype |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md)| Yes| Input method subtype to switch to.|

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the switching is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800005 | configuration persisting error.        |
| 12800008 | input method manager service error. |

**Example**

```js
let currentIme = inputMethod.getCurrentInputMethod();
let imSubType = inputMethod.getCurrentInputMethodSubtype();
try {
  inputMethod.switchCurrentInputMethodAndSubtype(currentIme, imSubType).then((result) => {
    if (result) {
      console.log('Succeeded in switching currentInputMethodAndSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodAndSubtype.');
    }
  }).catch((err) => {
    console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
}
```

## inputMethod.getInputMethodController<sup>(deprecated)</sup>

getInputMethodController(): InputMethodController

Obtains an **[InputMethodController](#inputmethodcontroller)** instance.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getController()](#inputmethodgetcontroller9) instead.

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
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getSetting()](#inputmethodgetsetting9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | Current **InputMethodSetting** instance.|

**Example**

```js
let inputMethodSetting = inputMethod.getInputMethodSetting();
```

## TextInputType<sup>10+</sup>

Enumerates the text input types.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value|Description|
| -------- | -------- |-------- |
| NONE  | -1 |None.|
| TEXT  | 0 |Text.|
| MULTILINE  | 1 |Multi-line.|
| NUMBER  | 2 |Number.|
| PHONE  | 3 |Phone number.|
| DATETIME  | 4 |Date.|
| EMAIL_ADDRESS  | 5 |Email address.|
| URL  | 6 |URL.|
| VISIBLE_PASSWORD  | 7 |Password.|

## EnterKeyType<sup>10+</sup>

Enumerates the function types represented by the Enter key of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value|Description|
| -------- | -------- |-------- |
| UNSPECIFIED  | 0 |Not specified.|
| NONE  | 1 |None.|
| GO  | 2 |Go.|
| SEARCH  | 3 |Search.|
| SEND  | 4 |Send.|
| NEXT  | 5 |Next.|
| DONE  | 6 |Done.|
| PREVIOUS  | 7 |Previous.|

## KeyboardStatus<sup>10+</sup>

Enumerates the soft keyboard states of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value|Description|
| -------- | -------- |-------- |
| NONE  | 0 |None.|
| HIDE  | 1 |Hidden.|
| SHOW  | 2 |Shown.|

## Direction<sup>10+</sup>

Enumerates the directions of cursor movement of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value|Description|
| -------- | -------- |-------- |
| CURSOR_UP  | 1 |Upward.|
| CURSOR_DOWN  | 2 |Downward.|
| CURSOR_LEFT  | 3 |Leftward.|
| CURSOR_RIGHT  | 4 |Rightward.|

## ExtendAction<sup>10+</sup>

Describes the type of the extended edit action on the text box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value|Description|
| -------- | -------- |-------- |
| SELECT_ALL  | 0 |Select all.|
| CUT  | 3 |Cut.|
| COPY  | 4 |Copy.|
| PASTE  | 5 |Paste.|

## FunctionKey<sup>10+</sup>

Describes the type of the input method function key.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| enterKeyType<sup>10+</sup>  | [EnterKeyType](#enterkeytype10) | Yes| Yes| Function type represented by the Enter key of the input method.|

## InputAttribute<sup>10+</sup>

Describes the attributes of the edit box, including the text input type and Enter key function type.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| textInputType<sup>10+</sup>  | [TextInputType](#textinputtype10) | Yes| Yes| Enumerates the text input types.|
| enterKeyType<sup>10+</sup>  | [EnterKeyType](#enterkeytype10) | Yes| Yes| Function type represented by the Enter key.|

## TextConfig<sup>10+</sup>

Describes the configuration of the editor component. When the editor component requests to bind the input method, this parameter is transferred to save the configuration of the editor component to the input method framework.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| inputAttribute<sup>10+</sup>  | [InputAttribute](#inputattribute10) | No| Yes| Edit box attribute.|
| cursorInfo<sup>10+</sup>  | [CursorInfo](#cursorinfo10) | No| No| Cursor information.|
| selection<sup>10+</sup>  | [Range](#range10) | No| No| Text selection range.|
| windowId<sup>10+</sup>  | number | No| No| ID of the window where the editor component is located.|

## CursorInfo<sup>10+</sup>

Describes the cursor information.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| left  | number | Yes| Yes| Left coordinate of the cursor.|
| top  | number | Yes| Yes| Top coordinate of the cursor.|
| width  | number | Yes| Yes| Width of the cursor.|
| height  | number | Yes| Yes| Height of the cursor.|

## Range<sup>10+</sup>

Describes the range of the selected text.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| start  | number | Yes| Yes| Index of the first selected character in the text box.|
| end  | number | Yes| Yes| Index of the last selected character in the text box.|

## Movement<sup>10+</sup>

Describes the direction in which the cursor moves when the text is selected.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| direction  | [Direction](#direction10) | Yes| Yes| Direction in which the cursor moves when the text is selected.|

## InputWindowInfo<sup>10+</sup>

Describes the window information of the input method keyboard.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| name  | string | Yes| Yes| Name of the input method keyboard window.|
| left  | number | Yes| Yes| Horizontal coordinate of the upper left corner of the input method keyboard window, in px.|
| top  | number | Yes| Yes| Vertical coordinate of the upper left corner of the input method keyboard window, in px.|
| width  | number | Yes| Yes| Width of the input method keyboard window, in px.|
| height  | number | Yes| Yes| Height of the input method keyboard window, in px.|

## InputMethodController

In the following API examples, you must first use [getController](#inputmethodgetcontroller9) to obtain an **InputMethodController** instance, and then call the APIs using the obtained instance.

### attach<sup>10+</sup>

attach(showKeyboard: boolean, textConfig: TextConfig, callback: AsyncCallback&lt;void&gt;): void

Attaches a self-drawing component to the input method. This API uses an asynchronous callback to return the result.

An input method can use the features provided by the input method framework only when it has a self-drawing component attached to it.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| showKeyboard | boolean | Yes| Whether to start the input method keyboard after the self-drawing component is attached to the input method.|
| textConfig | [TextConfig](#textconfig10) | Yes| Configuration of the editor component.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**Example**

```js
try {
  let textConfig: inputMethod.TextConfig = {
    inputAttribute: {
      textInputType: 0,
      enterKeyType: 1
    }
  };
  inputMethodController.attach(true, textConfig, (err) => {
    if (err) {
      console.error(`Failed to attach: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in attaching the inputMethod.');
  });
} catch(err) {
  console.error(`Failed to attach: ${JSON.stringify(err)}`);
}
```

### attach<sup>10+</sup>

attach(showKeyboard: boolean, textConfig: TextConfig): Promise&lt;void&gt;

Attaches a self-drawing component to the input method. This API uses a promise to return the result.

An input method can use the features provided by the input method framework only when it has a self-drawing component attached to it.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| showKeyboard | boolean | Yes| Whether to start the input method keyboard after the self-drawing component is attached to the input method.|
| textConfig | [TextConfig](#textconfig10) | Yes| Edit box attribute.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**Example**

```js
try {
  let textConfig: inputMethod.TextConfig = {
    inputAttribute: {
      textInputType: 0,
      enterKeyType: 1
    }
  };
  inputMethodController.attach(true, textConfig).then(() => {
    console.log('Succeeded in attaching inputMethod.');
  }).catch((err) => {
    console.error(`Failed to attach: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to attach: ${JSON.stringify(err)}`);
}
```

### showTextInput<sup>10+</sup>

showTextInput(callback: AsyncCallback&lt;void&gt;): void

Enters the text editing mode. This API uses an asynchronous callback to return the result.

This API can be called to start the soft keyboard after the editor component is attached to the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**Example**

```js
inputMethodController.showTextInput((err) => {
  if (err) {
    console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in showing the inputMethod.');
});
```

### showTextInput<sup>10+</sup>

showTextInput(): Promise&lt;void&gt;

Enters the text editing mode. This API uses a promise to return the result.

This API can be called to start the soft keyboard after the editor component is attached to the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**Example**

```js
inputMethodController.showTextInput().then(() => {
  console.log('Succeeded in showing text input.');
}).catch((err) => {
  console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);
});
```

### hideTextInput<sup>10+</sup>

hideTextInput(callback: AsyncCallback&lt;void&gt;): void

Exits the text editing mode. This API uses an asynchronous callback to return the result.

The editor component can call this API to exit the text editing mode. If the soft keyboard is displayed when this API is called, it will be hidden.

Calling this API does not detach the editor component from the input method. The editor component can call [showTextInput](#showtextinput10) again to reenter the text editing mode.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached.             |

**Example**

```js
inputMethodController.hideTextInput((err) => {
  if (err) {
    console.error(`Failed to hideTextInput: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in hiding text input.');
});
```

### hideTextInput<sup>10+</sup>

hideTextInput(): Promise&lt;void&gt;

Exits the text editing mode. This API uses a promise to return the result.

The editor component can call this API to exit the text editing mode. If the soft keyboard is displayed when this API is called, it will be hidden.

Calling this API does not detach the editor component from the input method. The editor component can call [showTextInput](#showtextinput10) again to reenter the text editing mode.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**Example**

```js
inputMethodController.hideTextInput().then(() => {
  console.log('Succeeded in hiding inputMethod.');
}).catch((err) => {
  console.error(`Failed to hideTextInput: ${JSON.stringify(err)}`);
})
```

### detach<sup>10+</sup>

detach(callback: AsyncCallback&lt;void&gt;): void

Detaches from the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**Example**

```js
inputMethodController.detach((err) => {
  if (err) {
    console.error(`Failed to detach: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in detaching inputMethod.');
});
```

### detach<sup>10+</sup>

detach(): Promise&lt;void&gt;

Detaches from the input method. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**Example**

```js
inputMethodController.detach().then(() => {
  console.log('Succeeded in detaching inputMethod.');
}).catch((err) => {
  console.error(`Failed to detach: ${JSON.stringify(err)}`);
});
```

### setCallingWindow<sup>10+</sup>

setCallingWindow(windowId: number, callback: AsyncCallback&lt;void&gt;): void

Sets the window to be avoided by the input method. This API uses an asynchronous callback to return the result.

After the window ID of the application bound to the input method is passed in the API, the input method window will not cover the window holding the application. This API is reserved. Currently, the window ID cannot be obtained.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowId | number | Yes| ID of the window to be avoided.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached.             |

**Example**

```js
try {
  let windowId: number = 2000;
  inputMethodController.setCallingWindow(windowId, (err) => {
    if (err) {
      console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in setting callingWindow.');
  });
} catch(err) {
  console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### setCallingWindow<sup>10+</sup>

setCallingWindow(windowId: number): Promise&lt;void&gt;

Sets the window to be avoided by the input method. This API uses a promise to return the result.

After the window ID of the application bound to the input method is passed in the API, the input method window will not cover the window holding the application. This API is reserved. Currently, the window ID cannot be obtained.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowId | number | Yes| ID of the window to be avoided.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  let windowId: number = 2000;
  inputMethodController.setCallingWindow(windowId).then(() => {
    console.log('Succeeded in setting callingWindow.');
  }).catch((err) => {
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### updateCursor<sup>10+</sup>

updateCursor(cursorInfo: CursorInfo, callback: AsyncCallback&lt;void&gt;): void

Updates the cursor information in this edit box. This API uses an asynchronous callback to return the result.

This API can be called to notify the input method of the cursor changes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| cursorInfo | [CursorInfo](#cursorinfo10) | Yes| Cursor information.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached.             |

**Example**

```js
try {
  inputMethodController.updateCursor({left: 0, top: 0, width: 600, height: 800}, (err) => {
    if (err) {
      console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in updating cursorInfo.');
  });
} catch(err) {
  console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
}
```

### updateCursor<sup>10+</sup>

updateCursor(cursorInfo: CursorInfo): Promise&lt;void&gt;

Updates the cursor information in this edit box. This API uses a promise to return the result.

This API can be called to notify the input method of the cursor changes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| cursorInfo | [CursorInfo](#cursorinfo10) | Yes| Cursor information.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.updateCursor({left: 0, top: 0, width: 600, height: 800}).then(() => {
    console.log('Succeeded in updating cursorInfo.');
  }).catch((err) => {
    console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
}
```

### changeSelection<sup>10+</sup>

changeSelection(text: string, start: number, end: number, callback: AsyncCallback&lt;void&gt;): void

Updates the information of selected text in this edit box, to notify the input method when the selected text content or text range changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| All input text.|
| start | number | Yes| Start position of the selected text.|
| end | number | Yes| End position of the selected text.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached.             |

**Example**

```js
try {
  inputMethodController.changeSelection('text', 0, 5, (err) => {
    if (err) {
      console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in changing selection.');
  });
} catch(err) {
  console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
}
```

### changeSelection<sup>10+</sup>

changeSelection(text: string, start: number, end: number): Promise&lt;void&gt;

Updates the information of selected text in this edit box, to notify the input method when the selected text content or text range changes. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| All input text.|
| start | number | Yes| Start position of the selected text.|
| end | number | Yes| End position of the selected text.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.changeSelection('test', 0, 5).then(() => {
    console.log('Succeeded in changing selection.');
  }).catch((err) => {
    console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
}
```

### updateAttribute<sup>10+</sup>

updateAttribute(attribute: InputAttribute, callback: AsyncCallback&lt;void&gt;): void

Updates the attribute configuration of the edit box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| attribute | [InputAttribute](#inputattribute10) | Yes| Attribute configuration.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached.             |

**Example**

```js
try {
  inputMethodController.updateAttribute({textInputType: 0, enterKeyType: 1}, (err) => {
    if (err) {
      console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in updating attribute.');
  });
} catch(err) {
  console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
}
```

### updateAttribute<sup>10+</sup>

updateAttribute(attribute: InputAttribute): Promise&lt;void&gt;

Updates the attribute configuration of the edit box. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| attribute | [InputAttribute](#inputattribute10) | Yes| Attribute configuration.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.updateAttribute({textInputType: 0, enterKeyType: 1}).then(() => {
    console.log('Succeeded in updating attribute.');
  }).catch((err) => {
    console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
}
```

### stopInputSession<sup>9+</sup>

stopInputSession(callback: AsyncCallback&lt;boolean&gt;): void

Ends this input session. This API uses an asynchronous callback to return the result.

This API must be used with the editor component (for example, a text box). It can be called only when the editor component is focused.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**Example**

```js
try {
  inputMethodController.stopInputSession((err, result) => {
    if (err) {
      console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.log('Succeeded in stopping inputSession.');
    } else {
      console.error('Failed to stopInputSession.');
    }
  });
} catch(err) {
  console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
}
```

### stopInputSession<sup>9+</sup>

stopInputSession(): Promise&lt;boolean&gt;

Ends this input session. This API uses a promise to return the result.

This API must be used with the editor component (for example, a text box). It can be called only when the editor component is focused.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the ending is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**Example**

```js
try {
  inputMethodController.stopInputSession().then((result) => {
    if (result) {
      console.log('Succeeded in stopping inputSession.');
    } else {
      console.error('Failed to stopInputSession.');
    }
  }).catch((err) => {
    console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
}
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

Shows this soft keyboard. This API uses an asynchronous callback to return the result.

This API must be used with the editor component (for example, a text box). It can be called only when the editor component is focused.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**Example**

```js
inputMethodController.showSoftKeyboard((err) => {
  if (!err) {
    console.log('Succeeded in showing softKeyboard.');
  } else {
    console.error(`Failed to show softKeyboard: ${JSON.stringify(err)}`);
  }
})
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(): Promise&lt;void&gt;

Shows this soft keyboard. This API uses a promise to return the result.

This API must be used with the editor component (for example, a text box). It can be called only when the editor component is focused.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**Example**

```js
inputMethodController.showSoftKeyboard().then(() => {
  console.log('Succeeded in showing softKeyboard.');
}).catch((err) => {
  console.error(`Failed to show softKeyboard: ${JSON.stringify(err)}`);
});
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

Hides this soft keyboard. This API uses an asynchronous callback to return the result.

This API must be used with the editor component (for example, a text box). It can be called only when the editor component is focused.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**Example**

```js
inputMethodController.hideSoftKeyboard((err) => {
  if (!err) {
    console.log('Succeeded in hiding softKeyboard.');
  } else {
    console.error(`Failed to hide softKeyboard: ${JSON.stringify(err)}`);
  }
})
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(): Promise&lt;void&gt;

Hides this soft keyboard. This API uses a promise to return the result.

This API must be used with the editor component (for example, a text box). It can be called only when the editor component is focused.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error.             |
| 12800008 | input method manager service error. |

**Example**

```js
inputMethodController.hideSoftKeyboard().then(() => {
  console.log('Succeeded in hiding softKeyboard.');
}).catch((err) => {
  console.error(`Failed to hide softKeyboard: ${JSON.stringify(err)}`);
});
```

### stopInput<sup>(deprecated)</sup>

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

Ends this input session. This API uses an asynchronous callback to return the result.

This API must be used with the editor component (for example, a text box). It can be called only when the editor component is focused.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [stopInputSession()](#stopinputsession9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Example**

```js
inputMethodController.stopInput((err, result) => {
  if (err) {
    console.error(`Failed to stopInput: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.log('Succeeded in stopping input.');
  } else {
    console.error('Failed to stopInput.');
  }
});
```

### stopInput<sup>(deprecated)</sup>

stopInput(): Promise&lt;boolean&gt;

Ends this input session. This API uses a promise to return the result.

This API must be used with the editor component (for example, a text box). It can be called only when the editor component is focused.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [stopInputSession()](#stopinputsession9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the hiding is successful, and **false** means the opposite.|

**Example**

```js
inputMethodController.stopInput().then((result) => {
  if (result) {
    console.log('Succeeded in stopping input.');
  } else {
    console.error('Failed to stopInput.');
  }
}).catch((err) => {
  console.error(`Failed to stopInput: ${JSON.stringify(err)}`);
})
```

### on('insertText')<sup>10+</sup>

on(type: 'insertText', callback: (text: string) => void): void;

Enables listening for the text insertion event of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Listening type.<br>The value **'insertText'** indicates the text insertion event.|
| callback | (text: string) => void | Yes  | Callback used to return the text to be inserted.<br>Your application needs to operate the content in the edit box based on the text content returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.on('insertText', (text) => {
    console.log(`Succeeded in subscribing insertText: ${text}`);
  });
} catch(err) {
  console.error(`Failed to subscribe insertText: ${JSON.stringify(err)}`);
}
```

### off('insertText')<sup>10+</sup>

off(type: 'insertText', callback?: (text: string) => void): void

Disables listening for the text insertion event of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| type     | string                 | Yes  | Listening type.<br>The value **'insertText'** indicates the text insertion event.|
| callback | (text: string) => void | No  | Callback used for disable listening, which must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
let onInsertTextCallback = (text: string) => {
    console.log(`Succeeded in subscribing insertText: ${text}`);
};
inputMethodController.off('insertText', onInsertTextCallback);
inputMethodController.off('insertText');
```

### on('deleteLeft')<sup>10+</sup>

on(type: 'deleteLeft', callback: (length: number) => void): void

Enables listening for the backward delete event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | ----- | ---- | ----- |
| type     | string  | Yes  | Listening type.<br>The value **'deleteLeft'** indicates the backward delete event.|
| callback | (length: number) => void | Yes  | Callback used to return the length of the text to be deleted backward.<br>Your application needs to operate the content in the edit box based on the length returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.on('deleteLeft', (length) => {
    console.log(`Succeeded in subscribing deleteLeft, length: ${length}`);
  });
} catch(err) {
  console.error(`Failed to subscribe deleteLeft: ${JSON.stringify(err)}`);
}
```

### on('deleteRight')<sup>10+</sup>

on(type: 'deleteRight', callback: (length: number) => void): void

Enables listening for the forward delete event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | ----- | ---- | ----- |
| type     | string  | Yes  | Listening type.<br>The value **'deleteRight'** indicates the forward delete event.|
| callback | (length: number) => void | Yes  | Callback used to return the length of the text to be deleted forward.<br>Your application needs to operate the content in the edit box based on the length returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.on('deleteRight', (length) => {
    console.log(`Succeeded in subscribing deleteRight, length: ${length}`);
  });
} catch(err) {
  console.error(`Failed to subscribe deleteRight: ${JSON.stringify(err)}`);
}
```
### off('deleteLeft')<sup>10+</sup>

off(type: 'deleteLeft', callback?: (length: number) => void): void

Disables listening for the backward delete event.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                    | Mandatory| Description                                                        |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                   | Yes  | Listening type.<br>The value **'deleteLeft'** indicates the backward delete event.|
| callback | (length: number) => void | No  | Callback used for disable listening, which must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
let onDeleteLeftCallback = (length: number) => {
    console.log(`Succeeded in subscribing deleteLeft, length: ${length}`);
};
inputMethodController.off('deleteLeft', onDeleteLeftCallback);
inputMethodController.off('deleteLeft');
```

### off('deleteRight')<sup>10+</sup>

off(type: 'deleteRight', callback?: (length: number) => void): void

Disables listening for the forward delete event.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                    | Mandatory| Description                                                        |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                   | Yes  | Listening type.<br>The value **'deleteRight'** indicates the forward delete event.|
| callback | (length: number) => void | No  | Callback used for disable listening, which must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
let onDeleteRightCallback = (length: number) => {
    console.log(`Succeeded in subscribing deleteRight, length: ${length}`);
};
inputMethodController.off('deleteRight', onDeleteRightCallback);
inputMethodController.off('deleteRight');
```

### on('sendKeyboardStatus')<sup>10+</sup>

on(type: 'sendKeyboardStatus', callback: (keyboardStatus: KeyboardStatus) => void): void

Enables listening for the keyboard status event of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type | Mandatory| Description   |
| -------- | ------ | ---- | ---- |
| type     | string  | Yes  | Listening type.<br>The value **'sendKeyboardStatus'** indicates the keyboard status event.|
| callback | (keyboardStatus: [KeyboardStatus](#keyboardstatus10)) => void | Yes  | Callback used to return the keyboard status.<br>Your application needs to perform operations based on the keyboard state returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.on('sendKeyboardStatus', (keyboardStatus) => {
    console.log(`Succeeded in subscribing sendKeyboardStatus, keyboardStatus: ${keyboardStatus}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sendKeyboardStatus: ${JSON.stringify(err)}`);
}
```

### off('sendKeyboardStatus')<sup>10+</sup>

off(type: 'sendKeyboardStatus', callback?: (keyboardStatus: KeyboardStatus) => void): void

Disables listening for the keyboard status event of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Listening type.<br>The value **'sendKeyboardStatus'** indicates the keyboard status event.|
| callback | (keyboardStatus: [KeyboardStatus](#keyboardstatus10)) => void | No  | Callback used for disable listening, which must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
let onSendKeyboardStatus = (keyboardStatus: KeyboardStatus) => {
    console.log(`Succeeded in subscribing sendKeyboardStatus, keyboardStatus: ${keyboardStatus}`);
};
inputMethodController.off('sendKeyboardStatus', onSendKeyboardStatus);
inputMethodController.off('sendKeyboardStatus');
```

### on('sendFunctionKey')<sup>10+</sup>

on(type: 'sendFunctionKey', callback: (functionKey: FunctionKey) => void): void

Enables listening for the function key sending event of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type | Mandatory| Description    |
| -------- | -------- | ---- | ----- |
| type     | string  | Yes  | Listening type.<br>The value **'sendFunctionKey'** indicates the function key sending event.|
| callback | (functionKey: [FunctionKey](#functionkey10)) => void | Yes  | Callback used to return the function key information sent by the input method.<br>Your application needs to perform operations based on the function key information returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.on('sendFunctionKey', (functionKey) => {
    console.log(`Succeeded in subscribing sendFunctionKey, functionKey.enterKeyType: ${functionKey.enterKeyType}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sendFunctionKey: ${JSON.stringify(err)}`);
}
```

### off('sendFunctionKey')<sup>10+</sup>

off(type: 'sendFunctionKey', callback?: (functionKey: FunctionKey) => void): void

Disables listening for the function key sending event of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                               | Yes  | Listening type.<br>The value **'sendFunctionKey'** indicates the function key sending event.|
| callback | (functionKey: [FunctionKey](#functionkey10)) => void | No  | Callback used for disable listening, which must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
let onSendFunctionKey = (functionKey: FunctionKey) => {
    console.log(`Succeeded in subscribing sendFunctionKey, functionKey: ${functionKey.enterKeyType}`);
};
inputMethodController.off('sendFunctionKey', onSendFunctionKey);
inputMethodController.off('sendFunctionKey');
```

### on('moveCursor')<sup>10+</sup>

on(type: 'moveCursor', callback: (direction: Direction) => void): void

Enables listening for the cursor movement event of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description  |
| -------- | ------ | ---- | ------ |
| type     | string | Yes  | Listening type.<br>The value **'moveCursor'** indicates the cursor movement event.|
| callback | callback: (direction: [Direction<sup>10+</sup>](#direction10)) => void | Yes  | Callback used to return the cursor movement direction.<br>Your application needs to change the cursor position based on the cursor movement direction returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                          |
| -------- | -------------------------------- |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.on('moveCursor', (direction) => {
    console.log(`Succeeded in subscribing moveCursor, direction: ${direction}`);
  });
} catch(err) {
  console.error(`Failed to subscribe moveCursor: ${JSON.stringify(err)}`);
}
```

### off('moveCursor')<sup>10+</sup>

off(type: 'moveCursor', callback?: (direction: Direction) => void): void

Disables listening for the cursor movement event of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name | Type   | Mandatory| Description |
| ------ | ------ | ---- | ---- |
| type   | string | Yes  | Listening type.<br>The value **'moveCursor'** indicates the cursor movement event.|
| callback | (direction: [Direction<sup>10+</sup>](#direction10)) => void | No| Callback used for disable listening, which must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
let onMoveCursorCallback = (direction: Direction) => {
    console.log(`Succeeded in subscribing moveCursor, direction: ${direction}`);
};
inputMethodController.off('moveCursor', onMoveCursorCallback);
inputMethodController.off('moveCursor');
```

### on('handleExtendAction')<sup>10+</sup>

on(type: 'handleExtendAction', callback: (action: ExtendAction) => void): void

Enables listening for the extended action handling event of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type | Mandatory| Description  |
| -------- | ------ | ---- | -------- |
| type     | string    | Yes  | Listening type.<br>The value **'handleExtendAction'** indicates the extended action handling event.|
| callback | callback: (action: [ExtendAction](#extendaction10)) => void | Yes  | Callback used to return the extended action type.<br>Your application needs to perform operations based on the extended action type returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.on('handleExtendAction', (action) => {
    console.log(`Succeeded in subscribing handleExtendAction, action: ${action}`);
  });
} catch(err) {
  console.error(`Failed to subscribe handleExtendAction: ${JSON.stringify(err)}`);
}
```

### off('handleExtendAction')<sup>10+</sup>

off(type: 'handleExtendAction', callback?: (action: ExtendAction) => void): void

Disables listening for the extended action handling event of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ------ | ---- | ------- |
| type   | string | Yes  | Listening type.<br>The value **'handleExtendAction'** indicates the extended action handling event.|
| callback | (action: [ExtendAction](#extendaction10)) => void | No| Callback used for disable listening, which must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
let onHandleExtendActionCallback = (action: ExtendAction) => {
    console.log(`Succeeded in subscribing handleExtendAction, action: ${action}`);
};
inputMethodController.off('handleExtendAction', onHandleExtendActionCallback);
inputMethodController.off('handleExtendAction');
```

### on('selectByRange')<sup>10+</sup>

on(type: 'selectByRange', callback: Callback&lt;Range&gt;): void

Enables listening for the select-by-range event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type    | Mandatory| Description    |
| -------- | ---- | ---- | ------- |
| type     | string  | Yes  | Listening type.<br>The value **'selectByRange'** indicates the select-by-range event.|
| callback | Callback&lt;[Range](#range10)&gt; | Yes  | Callback used to return the range of the text to be selected.<br>Your application needs to select the text in the returned range in the text box.|

**Example**

```js
inputMethodController.on('selectByRange', (range) => {
  console.log(`Succeeded in subscribing selectByRange: start: ${range.start} , end: ${range.end}`);
});
```

### off('selectByRange')<sup>10+</sup>

off(type: 'selectByRange', callback?:  Callback&lt;Range&gt;): void

Disables listening for the select-by-range event.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                             | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                            | Yes  | Listening type.<br>The value **'selectByRange'** indicates the select-by-range event.|
| callback | Callback&lt;[Range](#range10)&gt; | No  | Callback used for disable listening, which must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
let onSelectByRangeCallback = (range: Range) => {
    console.log(`Succeeded in subscribing selectByRange, range: ${JSON.stringify(range)}`);
};
inputMethodController.off('selectByRange', onSelectByRangeCallback);
inputMethodController.off('selectByRange');
```

### on('selectByMovement')<sup>10+</sup>

on(type: 'selectByMovement', callback: Callback&lt;Movement&gt;): void

Enables listening for the select-by-cursor-movement event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description    |
| -------- | ----- | ---- | ------ |
| type     | string  | Yes  | Listening type.<br>The value **'selectByMovement'** indicates the select-by-cursor-movement event.|
| callback | Callback&lt;[Movement](#movement10)&gt; | Yes  | Callback used to return the range of the text to be selected.<br>Your application needs to select the text in the returned range in the text box.|

**Example**

```js
inputMethodController.on('selectByMovement', (movement) => {
  console.log('Succeeded in subscribing selectByMovement: direction: ' + movement.direction);
});
```

### off('selectByMovement')<sup>10+</sup>

off(type: 'selectByMovement', callback?: Callback&lt;Movement&gt;): void

Disables listening for the select-by-cursor-movement event.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                               | Yes  | Listening type.<br>The value **'selectByMovement'** indicates the select-by-cursor-movement event.|
| callback | Callback&lt;[Movement](#movement10)> | No  | Callback used for disable listening, which must be the same as that passed by the **on** API. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
let onSelectByMovementCallback = (movement: Movement) => {
    console.log(`Succeeded in subscribing selectByMovement, movement.direction: ${movement.direction}`);
};
inputMethodController.off('selectByMovement', onSelectByMovementCallback);
inputMethodController.off('selectByMovement');
```

### on('getLeftTextOfCursor')<sup>10+</sup>

on(type: 'getLeftTextOfCursor', callback: (length: number) => string): void;

Enables listening for the event of obtaining the length of text deleted backward. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description    |
| -------- | ----- | ---- | ------ |
| type     | string  | Yes  | Listening type.<br>The value **'getLeftTextOfCursor'** indicates the event of obtaining the length of text deleted backward.|
| callback | (length: number) => string | Yes  | Callback used to obtain the text of the specified length deleted backward.<br>In this callback, obtain the text of the specified length on the left of the cursor in the latest state of the edit box and return the text.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.on('getLeftTextOfCursor', (length) => {
    console.info(`Succeeded in subscribing getLeftTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to subscribe getLeftTextOfCursor. Code: ${err.code}, message: ${err.message}`);
}
```

### off('getLeftTextOfCursor')<sup>10+</sup>

off(type: 'getLeftTextOfCursor', callback?: (length: number) => string): void;

Disables listening for the event of obtaining the length of text deleted backward.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Listening type.<br>The value **'getLeftTextOfCursor'** indicates the event of obtaining the length of text deleted backward.|
| callback | (length: number) => string | No | Callback used to obtain the text of the specified length deleted backward. The value must be the same as that passed in by the **on** API.|

**Example**

```js
try {
  inputMethodController.off('getLeftTextOfCursor', (length) => {
    console.info(`Succeeded in unsubscribing getLeftTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to unsubscribing getLeftTextOfCursor. Code: ${err.code}, message: ${err.message}`);
}
```

### on('getRightTextOfCursor')<sup>10+</sup>

on(type: 'getRightTextOfCursor', callback: (length: number) => string): void;

Enables listening for the event of obtaining the length of text deleted forward. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description    |
| -------- | ----- | ---- | ------ |
| type     | string  | Yes  | Listening type.<br>The value **'getRightTextOfCursor'** indicates the event of obtaining the length of text deleted forward.|
| callback | (length: number) => string | Yes  | Callback used to obtain the text of the specified length deleted forward.<br>In this callback, obtain the text of the specified length on the right of the cursor in the latest state of the edit box and return the text.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.on('getRightTextOfCursor', (length) => {
    console.info(`Succeeded in subscribing getRightTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to subscribe getRightTextOfCursor. Code: ${err.code}, message: ${err.message}`);
}
```

### off('getRightTextOfCursor')<sup>10+</sup>

off(type: 'getRightTextOfCursor', callback?: (length: number) => string): void;

Disables listening for the event of obtaining the length of text deleted forward.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Listening type.<br>The value **'getRightTextOfCursor'** indicates the event of obtaining the length of text deleted forward.|
| callback | (length: number) => string | No | Callback used to obtain the text of the specified length deleted forward. The value must be the same as that passed in by the **on** API.|

**Example**

```js
try {
  inputMethodController.off('getRightTextOfCursor', (length) => {
    console.info(`Succeeded in unsubscribing getRightTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to unsubscribing getRightTextOfCursor. Code: ${err.code}, message: ${err.message}`);
}
```

### on('getTextIndexAtCursor')<sup>10+</sup>

on(type: 'getTextIndexAtCursor', callback: () => number): void;

Enables listening for the event of obtaining the index of text at the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description    |
| -------- | ----- | ---- | ------ |
| type     | string  | Yes  | Listening type.<br>The value **'getTextIndexAtCursor'** indicates the event of obtaining the index of text at the cursor.|
| callback | () => number | Yes  | Callback used to obtain the index of text at the cursor.<br>In this callback, obtain the index of text at the cursor in the latest state of the edit box and return the index.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800009 | input method client is detached. |

**Example**

```js
try {
  inputMethodController.on('getTextIndexAtCursor', () => {
    console.info(`Succeeded in subscribing getTextIndexAtCursor.`);
    let index:number = 0;
    return index;
  });
} catch(err) {
  console.error(`Failed to subscribe getTextIndexAtCursor. Code: ${err.code}, message: ${err.message}`);
}
```

### off('getTextIndexAtCursor')<sup>10+</sup>

off(type: 'getTextIndexAtCursor', callback?: () => number): void;

Disables listening for the event of obtaining the index of text at the cursor.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Listening type.<br>The value **'getTextIndexAtCursor'** indicates the event of obtaining the index of text at the cursor.|
| callback | () => number | No | Callback used to obtain the index of text at the cursor. The value must be the same as that passed in by the **on** API.|

**Example**

```js
try {
  inputMethodController.off('getTextIndexAtCursor', () => {
    console.info(`Succeeded in unsubscribing getTextIndexAtCursor.`);
    let index:number = 0;
    return index;
  });
} catch(err) {
  console.error(`Failed to unsubscribing getTextIndexAtCursor. Code: ${err.code}, message: ${err.message}`);
}
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
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md)) => void  | Yes| Callback used to return the input method attributes and subtype.|

**Example**

```js
inputMethodSetting.on('imeChange', (inputMethodProperty, inputMethodSubtype) => {
  console.log('Succeeded in subscribing imeChange: inputMethodProperty: ' + JSON.stringify(inputMethodProperty) + " , inputMethodSubtype: " + JSON.stringify(inputMethodSubtype));
});
```

### off('imeChange')<sup>9+</sup>

off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void

Disables listening for the input method and subtype change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type   | Mandatory| Description         |
| -------- | --------- | ---- | --------------- |
| type     | string    | Yes  | Listening type.<br>The value **'imeChange'** indicates the input method and subtype change event.|
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md)) => void  | No| Callback used to return the input method attributes and subtype.|

**Example**

```js
inputMethodSetting.off('imeChange');
```

### on('imeShow')<sup>10+</sup>

on(type: 'imeShow', callback: (info: Array\<InputWindowInfo>) => void): void

Enables listening for the show event of the soft keyboard. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | ---- | ---- | ---- |
| type     | string | Yes| Listening type.<br>The value **'imeShow'** indicates the show event of the soft keyboard.|
| callback | (info: Array\<InputWindowInfo>) => void | Yes| Callback used to return the information about the soft keyboard of the input method.|

**Example**

```js
inputMethodSetting.on('imeShow', (info) => {
    console.info('Succeeded in subscribing imeShow event.');
});
```

### on('imeHide')<sup>10+</sup>

on(type: 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void

Enables listening for the hide event of the soft keyboard. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | ---- | ---- | ---- |
| type     | string | Yes| Listening type.<br>The value **'imeHide'** indicates the hide event of the soft keyboard.|
| callback | (info: Array\<InputWindowInfo>) => void | Yes| Callback used to return the information about the soft keyboard of the input method.|

**Example**

```js
inputMethodSetting.on('imeHide', (info) => {
    console.info('Succeeded in subscribing imeHide event.');
});
```

### off('imeShow')<sup>10+</sup>

off(type: 'imeShow', callback?: (info: Array\<InputWindowInfo>) => void): void

Disables listening for the show event of the soft keyboard.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description  |
| -------- | ---- | ---- | ------ |
| type     | string | Yes| Listening type.<br>The value **'imeShow'** indicates the show event of the soft keyboard.|
| callback | (info: Array\<InputWindowInfo>) => void  | No| Callback used for disable listening. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
inputMethodSetting.off('imeShow');
```

### off('imeHide')<sup>10+</sup>

off(type: 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void

Disables listening for the hide event of the soft keyboard.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description  |
| -------- | ---- | ---- | ------ |
| type     | string | Yes| Listening type.<br>The value **'imeHide'** indicates the hide event of the soft keyboard.|
| callback | (info: Array\<InputWindowInfo>) => void  | No| Callback used for disable listening. If this parameter is not specified, all callbacks corresponding to the set event are invoked.|

**Example**

```js
inputMethodSetting.off('imeHide');
```

### listInputMethodSubtype<sup>9+</sup>

listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback&lt;Array&lt;InputMethodSubtype&gt;&gt;): void

Obtains all subtypes of a specified input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| inputMethodProperty | [InputMethodProperty](#inputmethodproperty8)| Yes| Input method to which the subtypes belong.|
| callback | AsyncCallback&lt;Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md)>&gt; | Yes| Callback used to return all subtypes of the specified input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | package manager error.                 |
| 12800008 | input method manager service error. |

**Example**

```js
let inputMethodProperty = {
  name: 'com.example.kikakeyboard',
  id: 'propertyId',
}
try {
  inputMethodSetting.listInputMethodSubtype(inputMethodProperty, (err, data) => {
    if (err) {
      console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in listing inputMethodSubtype.');
  });
} catch (err) {
  console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

### listInputMethodSubtype<sup>9+</sup>

listInputMethodSubtype(inputMethodProperty: InputMethodProperty): Promise&lt;Array&lt;InputMethodSubtype&gt;&gt;

Obtains all subtypes of a specified input method. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| inputMethodProperty | [InputMethodProperty](#inputmethodproperty8)| Yes| Input method to which the subtypes belong.|

**Return value**

| Type                                                       | Description                  |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md)>> | Promise used to return all subtypes of the specified input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | package manager error.                 |
| 12800008 | input method manager service error. |

**Example**

```js
let inputMethodProperty = {
  name: 'com.example.kikakeyboard',
  id: 'propertyId',
}
try {
  inputMethodSetting.listInputMethodSubtype(inputMethodProperty).then((data) => {
    console.log('Succeeded in listing inputMethodSubtype.');
  }).catch((err) => {
    console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

### listCurrentInputMethodSubtype<sup>9+</sup>

listCurrentInputMethodSubtype(callback: AsyncCallback&lt;Array&lt;InputMethodSubtype&gt;&gt;): void

Obtains all subtypes of this input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md)>&gt; | Yes  | Callback used to return all subtypes of the current input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | package manager error.                 |
| 12800008 | input method manager service error. |

**Example**

```js
try {
  inputMethodSetting.listCurrentInputMethodSubtype((err, data) => {
    if (err) {
      console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in listing currentInputMethodSubtype.');
  });
} catch(err) {
  console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

### listCurrentInputMethodSubtype<sup>9+</sup>

listCurrentInputMethodSubtype(): Promise&lt;Array&lt;InputMethodSubtype&gt;&gt;

Obtains all subtypes of this input method. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                                       | Description                  |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md)>> | Promise used to return all subtypes of the current input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | package manager error.                 |
| 12800008 | input method manager service error. |

**Example**

```js
try {
  inputMethodSetting.listCurrentInputMethodSubtype().then((data) => {
    console.log('Succeeded in listing currentInputMethodSubtype.');
  }).catch((err) => {
    console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean, callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

Obtains a list of activated or deactivated input methods. This API uses an asynchronous callback to return the result.

In the current version, an activated input method is the input method in use, and a deactivated one is any of the installed input methods except the one in use.

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
| 12800001 | package manager error.                 |
| 12800008 | input method manager service error. |

**Example**

```js
try {
  inputMethodSetting.getInputMethods(true, (err, data) => {
    if (err) {
      console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in getting inputMethods.');
  });
} catch (err) {
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

Obtains a list of activated or deactivated input methods. This API uses a promise to return the result.

In the current version, an activated input method is the input method in use, and a deactivated one is any of the installed input methods except the one in use.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type   | Mandatory| Description                   |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | Yes  | Whether to return a list of activated input methods. The value **true** means to return a list of activated input methods, and **false** means to return a list of deactivated input methods.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | package manager error.                 |
| 12800008 |input method manager service error. |

**Return value**

| Type                                                        | Description                         |
| ------------------------------------------------------------ | ----------------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise used to return a list of activated or deactivated input methods.|

**Example**

```js
try {
  inputMethodSetting.getInputMethods(true).then((data) => {
    console.log('Succeeded in getting inputMethods.');
  }).catch((err) => {
    console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
}
```

### showOptionalInputMethods<sup>9+</sup>

showOptionalInputMethods(callback: AsyncCallback&lt;boolean&gt;): void

Displays a dialog box for selecting an input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. |

**Example**

```js
try {
  inputMethodSetting.showOptionalInputMethods((err, data) => {
    if (err) {
      console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Succeeded in showing optionalInputMethods.');
  });
} catch (err) {
  console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);
}
```

### showOptionalInputMethods<sup>9+</sup>

showOptionalInputMethods(): Promise&lt;boolean&gt;

Displays a dialog box for selecting an input method. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the operation is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. |

**Example**

```js
inputMethodSetting.showOptionalInputMethods().then((data) => {
  console.log('Succeeded in showing optionalInputMethods.');
}).catch((err) => {
  console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);
})
```

### listInputMethod<sup>(deprecated)</sup>

listInputMethod(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

Obtains a list of installed input methods. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getInputMethods](#getinputmethods9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; | Yes  | Callback used to return the list of installed input methods.|

**Example**

```js
inputMethodSetting.listInputMethod((err, data) => {
  if (err) {
    console.error(`Failed to listInputMethod: ${JSON.stringify(err)}`);
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
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getInputMethods](#getinputmethods9-1) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                                       | Description                  |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodProperty](#inputmethodproperty8)>> | Promise used to return the list of installed input methods.|

**Example**

```js
inputMethodSetting.listInputMethod().then((data) => {
  console.log('Succeeded in listing inputMethod.');
}).catch((err) => {
  console.error(`Failed to listInputMethod: ${JSON.stringify(err)}`);
})
```

### displayOptionalInputMethod<sup>(deprecated)</sup>

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

Displays a dialog box for selecting an input method. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [showOptionalInputMethods()](#showoptionalinputmethods9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```js
inputMethodSetting.displayOptionalInputMethod((err) => {
  if (err) {
    console.error(`Failed to displayOptionalInputMethod: ${JSON.stringify(err)}`);
    return;
  }
  console.log('Succeeded in displaying optionalInputMethod.');
});
```

### displayOptionalInputMethod<sup>(deprecated)</sup>

displayOptionalInputMethod(): Promise&lt;void&gt;

Displays a dialog box for selecting an input method. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [showOptionalInputMethods()](#showoptionalinputmethods9-1) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
inputMethodSetting.displayOptionalInputMethod().then(() => {
  console.log('Succeeded in displaying optionalInputMethod.');
}).catch((err) => {
  console.error(`Failed to displayOptionalInputMethod: ${JSON.stringify(err)}`);
})
```
