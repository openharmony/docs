# @ohos.inputMethodEngine (Input Method Service)

The **inputMethodEngine** module is oriented to input method applications (including system and third-party input method applications). With the APIs of this module, input method applications are able to create soft keyboard windows, insert or delete characters, select text, and listen for physical keyboard events.

> **NOTE**
>
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import inputMethodEngine from '@ohos.inputMethodEngine';
```

## Constants

Provides the constant values of function keys, edit boxes, and the cursor.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Value| Description|
| -------- | -------- | -------- | -------- |
| ENTER_KEY_TYPE_UNSPECIFIED | number | 0 | No function is specified for the Enter key.|
| ENTER_KEY_TYPE_GO | number | 2 | The Enter key takes the user to the target.|
| ENTER_KEY_TYPE_SEARCH | number | 3 | The Enter key takes the user to the results of their searching.|
| ENTER_KEY_TYPE_SEND | number | 4 | The Enter key sends the text to its target.|
| ENTER_KEY_TYPE_NEXT | number | 5 | The Enter key takes the user to the next field.|
| ENTER_KEY_TYPE_DONE | number | 6 | The Enter key takes the user to the next line.|
| ENTER_KEY_TYPE_PREVIOUS | number | 7 | The Enter key takes the user to the previous field.|
| PATTERN_NULL | number | -1 | Any type of edit box.|
| PATTERN_TEXT | number | 0 | Text edit box.|
| PATTERN_NUMBER | number | 2 | Number edit box.|
| PATTERN_PHONE | number | 3 | Phone number edit box.|
| PATTERN_DATETIME | number | 4 | Date edit box.|
| PATTERN_EMAIL | number | 5 | Email edit box.|
| PATTERN_URI | number | 6 | URI edit box.|
| PATTERN_PASSWORD | number | 7 | Password edit box.|
| OPTION_ASCII | number | 20 | ASCII values are allowed.|
| OPTION_NONE | number | 0 | No input attribute is specified.|
| OPTION_AUTO_CAP_CHARACTERS | number | 2 | Characters are allowed.|
| OPTION_AUTO_CAP_SENTENCES | number | 8 | Sentences are allowed.|
| OPTION_AUTO_WORDS | number | 4 | Words are allowed.|
| OPTION_MULTI_LINE | number | 1 | Multiple lines are allowed.|
| OPTION_NO_FULLSCREEN | number | 10 | Half-screen style.|
| FLAG_SELECTING | number | 2 | The edit box is being selected.|
| FLAG_SINGLE_LINE | number | 1 | The edit box allows only single-line input.|
| DISPLAY_MODE_PART | number | 0 | The edit box is displayed in half-screen mode.|
| DISPLAY_MODE_FULL | number | 1 | The edit box is displayed in full screen.|
| CURSOR_UP<sup>9+</sup> | number | 1 | The caret moves upward.|
| CURSOR_DOWN<sup>9+</sup> | number | 2 | The caret moves downward.|
| CURSOR_LEFT<sup>9+</sup> | number | 3 | The caret moves leftward.|
| CURSOR_RIGHT<sup>9+</sup> | number | 4 | The caret moves rightward.|
| WINDOW_TYPE_INPUT_METHOD_FLOAT<sup>9+</sup> | number | 2105 | The input method is displayed in a floating window.|

## inputMethodEngine.getInputMethodAbility<sup>9+</sup>

getInputMethodAbility(): InputMethodAbility

Obtains an [InputMethodAbility](#inputmethodability) instance for the input method. The input method can use the obtained instance to subscribe to a soft keyboard display/hide request event, create/destroy an input method panel, and the like.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description              |
| ----------------------------------------- | ------------------ |
| [InputMethodAbility](#inputmethodability) | **InputMethodAbility** instance.|

**Example**

```js
let InputMethodAbility = inputMethodEngine.getInputMethodAbility();
```

## inputMethodEngine.getKeyboardDelegate<sup>9+</sup>

getKeyboardDelegate(): KeyboardDelegate

Obtains a [KeyboardDelegate](#keyboarddelegate) instance for the input method. The input method can use the obtained instance to subscribe to a physical keyboard event, text selection change event, and more.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                 | Description                    |
| ------------------------------------- | ------------------------ |
| [KeyboardDelegate](#keyboarddelegate) | **KeyboardDelegate** instance.|

**Example**

```js
let KeyboardDelegate = inputMethodEngine.getKeyboardDelegate();
```

## inputMethodEngine.getInputMethodEngine<sup>(deprecated)</sup>

getInputMethodEngine(): InputMethodEngine

Obtains an [InputMethodEngine](#inputmethodengine-1) instance for the input method. The input method can use the obtained instance to subscribe to a soft keyboard display/hide request event.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getInputMethodAbility()](#inputmethodenginegetinputmethodability9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description              |
| ----------------------------------------- | ------------------ |
| [InputMethodEngine](#inputmethodengine-1) | **InputMethodAbility** instance.|

**Example**

```js
let InputMethodEngine = inputMethodEngine.getInputMethodEngine();
```

## inputMethodEngine.createKeyboardDelegate<sup>(deprecated)</sup>

createKeyboardDelegate(): KeyboardDelegate

Obtains a [KeyboardDelegate](#keyboarddelegate) instance for the input method. The input method can use the obtained instance to subscribe to a physical keyboard event, text selection change event, and more.

> **NOTE**
>
>This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getKeyboardDelegate()](#inputmethodenginegetkeyboarddelegate9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                 | Description                    |
| ------------------------------------- | ------------------------ |
| [KeyboardDelegate](#keyboarddelegate) | **KeyboardDelegate** instance.|

**Example**

```js
let keyboardDelegate = inputMethodEngine.createKeyboardDelegate();
```

## InputMethodEngine

In the following API examples, you must first use **[getInputMethodEngine](#inputmethodenginegetinputmethodenginedeprecated)** to obtain an **InputMethodEngine** instance, and then call the APIs using the obtained instance.

### on('inputStart')

on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

Enables listening for the input method binding event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | Yes  | Listening type.<br>The value **'inputStart'** indicates the input method binding event.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclientdeprecated)) => void | Yes| Callback used to return the **KeyboardController** and **TextInputClient** instances.|

**Example**

```js
inputMethodEngine.getInputMethodEngine().on('inputStart', (kbController, textClient) => {
    let keyboardController = kbController;
    let textInputClient = textClient;
});
```

### off('inputStart')

off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

Cancels listening for the input method binding event.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | Yes  | Listening type.<br>The value **'inputStart'** indicates the input method binding event.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclientdeprecated)) => void | No| Callback used to return the **KeyboardController** and **TextInputClient** instances.|

**Example**

```js
inputMethodEngine.getInputMethodEngine().off('inputStart', (kbController, textInputClient) => {
    console.log('delete inputStart notification.');
});
```

### on('keyboardShow'|'keyboardHide')

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

Enables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event.|
| callback | () => void   | Yes  | Callback used to return the result.                                                  |

**Example**

```js
inputMethodEngine.getInputMethodEngine().on('keyboardShow', () => {
    console.log('inputMethodEngine keyboardShow.');
});
inputMethodEngine.getInputMethodEngine().on('keyboardHide', () => {
    console.log('inputMethodEngine keyboardHide.');
});
```

### off('keyboardShow'|'keyboardHide')

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

Disables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event.|
| callback | () => void   | No  | Callback used to return the result.|

**Example**

```js
inputMethodEngine.getInputMethodEngine().off('keyboardShow');
inputMethodEngine.getInputMethodEngine().off('keyboardHide');
```

## InputMethodAbility

In the following API examples, you must first use **[getInputMethodAbility](#inputmethodenginegetinputmethodability9)** to obtain an **InputMethodAbility** instance, and then call the APIs using the obtained instance.

### on('inputStart')<sup>9+</sup>

on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void

Enables listening for the input method binding event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | Yes  | Listening type.<br>The value **'inputStart'** indicates the input method binding event.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), inputClient: [InputClient](#inputclient9)) => void | Yes| Callback used to return the result.|

**Example**

```js
inputMethodEngine.getInputMethodAbility().on('inputStart', (kbController, client) => {
    let keyboardController = kbController;
    let inputClient = client;
});
```

### off('inputStart')<sup>9+</sup>

off(type: 'inputStart', callback?: (kbController: KeyboardController, inputClient: InputClient) => void): void

Cancels listening for the input method binding event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | Yes  | Listening type.<br>The value **'inputStart'** indicates the input method binding event.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), inputClient: [InputClient](#inputclient9)) => void | No| Callback used to return the result.|

**Example**

```js
inputMethodEngine.getInputMethodAbility().off('inputStart');
```

### on('inputStop')<sup>9+</sup>

on(type: 'inputStop', callback: () => void): void

Enables listening for the input method unbinding event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>The value **'inputStop'** indicates the input method unbinding event.|
| callback | () => void   | Yes  | Callback used to return the result.                                                  |

**Example**

```js
inputMethodEngine.getInputMethodAbility().on('inputStop', () => {
    console.log('inputMethodAbility inputStop');
});
```

### off('inputStop')<sup>9+</sup>

off(type: 'inputStop', callback: () => void): void

Cancels listening for the input method stop event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>The value **'inputStop'** indicates the input method unbinding event.|
| callback | () => void   | Yes  | Callback used to return the result.                                                  |

**Example**

```js
inputMethodEngine.getInputMethodAbility().off('inputStop', () => {
    console.log('inputMethodAbility delete inputStop notification.');
});
```

### on('setCallingWindow')<sup>9+</sup>

on(type: 'setCallingWindow', callback: (wid: number) => void): void

Enables listening for the window invocation setting event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>The value **'setCallingWindow'** indicates the window invocation setting event.|
| callback | (wid: number) => void | Yes  | Callback used to return the window ID of the caller.                                           |

**Example**

```js
inputMethodEngine.getInputMethodAbility().on('setCallingWindow', (wid) => {
    console.log('inputMethodAbility setCallingWindow');
});
```

### off('setCallingWindow')<sup>9+</sup>

off(type: 'setCallingWindow', callback: (wid:number) => void): void

Disables listening for the window invocation setting event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>The value **'setCallingWindow'** indicates the window invocation setting event.|
| callback | (wid:number) => void | Yes  | Callback used to return the window ID of the caller.                                |

**Example**

```js
inputMethodEngine.getInputMethodAbility().off('setCallingWindow', () => {
    console.log('inputMethodAbility delete setCallingWindow notification.');
});
```

### on('keyboardShow'|'keyboardHide')<sup>9+</sup>

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

Enables listening for a keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event.|
| callback | () => void   | Yes  | Callback used to return the result.                                                  |

**Example**

```js
inputMethodEngine.getInputMethodAbility().on('keyboardShow', () => {
    console.log('InputMethodAbility keyboardShow.');
});
inputMethodEngine.getInputMethodAbility().on('keyboardHide', () => {
    console.log('InputMethodAbility keyboardHide.');
});
```

### off('keyboardShow'|'keyboardHide')<sup>9+</sup>

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

Disables listening for a keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event.|
| callback | () => void   | No  | Callback used to return the result.    |

**Example**

```js
inputMethodEngine.getInputMethodAbility().off('keyboardShow', () => {
    console.log('InputMethodAbility delete keyboardShow notification.');
});
inputMethodEngine.getInputMethodAbility().off('keyboardHide', () => {
    console.log('InputMethodAbility delete keyboardHide notification.');
});
```

### on('setSubtype')<sup>9+</sup>

on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void

Enables listening for the input method subtype setting event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Listening type.<br>The value **'setSubtype'** indicates the input method subtype setting event.|
| callback | (inputMethodSubtype: [InputMethodSubtype](js-apis-inputmethod-subtype.md)) => void | Yes  | Callback used to return the input method subtype.                          |

**Example**

```js
inputMethodEngine.getInputMethodAbility().on('setSubtype', (inputMethodSubtype) => {
    console.log('InputMethodAbility setSubtype.');
});
```

### off('setSubtype')<sup>9+</sup>

off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void

Disables listening for the input method subtype setting event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Listening type.<br>The value **'setSubtype'** indicates the input method subtype setting event.|
| callback | (inputMethodSubtype: [InputMethodSubtype](js-apis-inputmethod-subtype.md)) => void | No  | Callback used to return the input method subtype. |

**Example**

```js
inputMethodEngine.getInputMethodAbility().off('setSubtype', () => {
    console.log('InputMethodAbility delete setSubtype notification.');
});
```

### createPanel<sup>10+</sup>

createPanel(ctx: BaseContext, info: PanelInfo, callback: AsyncCallback\<Panel>): void

Creates an input method panel. This API can be called only by input method applications and system applications with the system_core permission. Only one SOFT_KEYBOARD panel and one STATUS_BAR panel can be created for a single input method application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [BaseContext](./js-apis-inner-application-baseContext.md) | Yes  | Context of the current input method.|
| info    | [PanelInfo](#panelinfo10)   | Yes  | Information about the input method panel.|
| callback | AsyncCallback\<[Panel](#panel10)> | Yes  | Callback used to return the result. If the operation is successful, the created input method panel is returned. |

**Error codes**

| Error Code ID  | Error Message                      |
| ---------- | ----------------------------- |
| 12800004   | not an input method extension |

**Example**

```js
let panelInfo: inputMethodEngine.PanelInfo = {
  panelType: SOFT_KEYBOARD,
  panelFlag: FLG_FIXED
}
try {
  inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo, (err, panel) => {
    if (err !== undefined) {
      console.log('Failed to create panel, err: ' + JSON.stringify(err));
      return;
    }
    console.log('Succeed in creating panel.');
  })
} catch(err) {
  console.log('Failed to create panel, err: ' + JSON.stringify(err));
}
```

### createPanel<sup>10+</sup>

createPanel(ctx: BaseContext, info: PanelInfo): Promise\<Panel>

Creates an input method panel. This API can be called only by input method applications and system applications with the system_core permission. Only one SOFT_KEYBOARD panel and one STATUS_BAR panel can be created for a single input method application. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [BaseContext](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-inner-application-baseContext.md) | Yes  | Context of the current input method.|
| info    | [PanelInfo](#panelinfo10)   | Yes  | Information about the input method panel.|

**Return value**
| Type  | Description                                                                |
| ------- | ------------------------------------------------------------------ |
| Promise\<[Panel](#panel10)> | Promise used to return the result. If the operation is successful, the created input method panel is returned. |

**Error codes**

| Error Code ID  | Error Message                      |
| ---------- | ----------------------------- |
| 12800004   | not an input method extension |

**Example**

```js
let panelInfo: inputMethodEngine.PanelInfo = {
  panelType: SOFT_KEYBOARD,
  panelFlag: FLG_FIXED
}
inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo).then((panel) => {
  console.log('Succeed in creating panel.');
}).catch((err) => {
  console.log('Failed to create panel, err: ' + JSON.stringify(err));
})
```

### destroyPanel<sup>10+</sup>

destroyPanel(panel: Panel, callback: AsyncCallback\<void>): void;

Destroys an input method panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| panel     | [Panel](#panel10) | Yes  | Input method panel to destroy.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Example**

```js
let panelInfo: inputMethodEngine.PanelInfo = {
  panelType: SOFT_KEYBOARD,
  panelFlag: FLG_FIXED
}
try {
  inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo, (err, panel) => {
    if (err !== undefined) {
      console.log('Failed to create panel, err: ' + JSON.stringify(err));
      return;
    }
	globalThis.inputMethodPanel = panel;
    console.log('Succeed in creating panel.');
  })
} catch(err) {
  console.log('Failed to create panel, err: ' + JSON.stringify(err));
}

try {
  inputMethodEngine.getInputMethodAbility().destroyPanel(globalThis.inputMethodPanel, (err) => {
    if(err !== undefined) {
      console.log('Failed to destroy panel, err: ' + JSON.stringify(err));
      return;
    }
    console.log('Succeed in destroying panel.');
  })
} catch(err) {
  console.log('Failed to destroy panel, err: ' + JSON.stringify(err));
}
```

### destroyPanel<sup>10+</sup>

destroyPanel(panel: Panel): Promise\<void>;

Destroys an input method panel. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ---------| ----------- | ---- | ------------------------ |
| panel    | [Panel](#panel10)       | Yes  | Input method panel to destroy.     |

**Return value**
| Type   | Description                                                                |
| ------- | -------------------------------------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```js
let panelInfo: inputMethodEngine.PanelInfo = {
  panelType: SOFT_KEYBOARD,
  panelFlag: FLG_FIXED
}
try {
  inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo, (err, panel) => {
    if (err !== undefined) {
      console.log('Failed to create panel, err: ' + JSON.stringify(err));
      return;
    }
	globalThis.inputMethodPanel = panel;
    console.log('Succeed in creating panel.');
  })
} catch(err) {
  console.log('Failed to create panel, err: ' + JSON.stringify(err));
}

try {
  inputMethodEngine.getInputMethodAbility().destroyPanel(globalThis.inputMethodPanel).then(() => {
    console.log('Succeed in destroying panel.');
  }).catch((err) => {
    console.log('Failed to destroy panel, err: ' + JSON.stringify(err));
  });
} catch (err) {
  console.log('Failed to destroy panel, err: ' + JSON.stringify(err));
}
```

## KeyboardDelegate

In the following API examples, you must first use **[getKeyboardDelegate](#inputmethodenginegetkeyboarddelegate9)** to obtain a **KeyboardDelegate** instance, and then call the APIs using the obtained instance.

### on('keyDown'|'keyUp')

on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void

Enables listening for a keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type   | string         | Yes  | Listening type.<br>The value **'keyDown'** indicates the keydown event.<br>The value **'keyUp'** indicates the keyup event.|
| callback | (event: [KeyEvent](#keyevent)) => boolean | Yes| Callback used to return the key information.|

**Example**

```js
inputMethodEngine.getKeyboardDelegate().on('keyUp', (keyEvent) => {
    console.info('inputMethodEngine keyCode.(keyUp):' + JSON.stringify(keyEvent.keyCode));
    console.info('inputMethodEngine keyAction.(keyUp):' + JSON.stringify(keyEvent.keyAction));
    return true;
});
inputMethodEngine.getKeyboardDelegate().on('keyDown', (keyEvent) => {
    console.info('inputMethodEngine keyCode.(keyDown):' + JSON.stringify(keyEvent.keyCode));
    console.info('inputMethodEngine keyAction.(keyDown):' + JSON.stringify(keyEvent.keyAction));
    return true;
});
```

### off('keyDown'|'keyUp')

off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void

Disables listening for a keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | Yes  | Listening type.<br>The value **'keyDown'** indicates the keydown event.<br>The value **'keyUp'** indicates the keyup event.|
| callback | (event: [KeyEvent](#keyevent)) => boolean | No  | Callback used to return the key information. |

**Example**

```js
inputMethodEngine.getKeyboardDelegate().off('keyUp', (keyEvent) => {
    console.log('delete keyUp notification.');
    return true;
});
inputMethodEngine.getKeyboardDelegate().off('keyDown', (keyEvent) => {
    console.log('delete keyDown notification.');
    return true;
});
```

### on('cursorContextChange')

on(type: 'cursorContextChange', callback: (x: number, y:number, height:number) => void): void

Enables listening for the cursor change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                          | Mandatory| Description                                                        |
| -------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                         | Yes  | Listening type.<br>The value **'cursorContextChange'** indicates the cursor change event.|
| callback | (x: number, y: number, height: number) => void | Yes  | Callback used to return the cursor information.<br>- **x**: x coordinate of the top of the cursor.<br>- **y**: x coordinate of the bottom of the cursor.<br>- **height**: height of the cursor.|

**Example**

```js
inputMethodEngine.getKeyboardDelegate().on('cursorContextChange', (x, y, height) => {
    console.log('inputMethodEngine cursorContextChange x:' + x);
    console.log('inputMethodEngine cursorContextChange y:' + y);
    console.log('inputMethodEngine cursorContextChange height:' + height);
});
```

### off('cursorContextChange')

off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void

Cancels listening for cursor context changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name  | Type                                        | Mandatory| Description                                                        |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                       | Yes  | Listening type.<br>The value **'cursorContextChange'** indicates the cursor change event.|
| callback | (x: number, y:number, height:number) => void | No  | Callback used to return the cursor information.<br>- **x**: x coordinate of the top of the cursor.<br>- **y**: x coordinate of the bottom of the cursor.<br>- **height**: height of the cursor.<br>|


  **Example**

```js
inputMethodEngine.getKeyboardDelegate().off('cursorContextChange', (x, y, height) => {
    console.log('delete cursorContextChange notification.');
});
```
### on('selectionChange')

on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

Enables listening for the text selection change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Listening type.<br>The value **'selectionChange'** indicates the text selection change event.|
| callback | (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void | Yes  | Callback used to return the text selection information.<br>- **oldBegin**: start of the selected text before the change.<br>- **oldEnd**: end of the selected text before the change.<br>- **newBegin**: start of the selected text after the change.<br>- **newEnd**: end of the selected text after the change.|

**Example**

```js
inputMethodEngine.getKeyboardDelegate().on('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
    console.log('inputMethodEngine beforeEach selectionChange oldBegin:' + oldBegin);
    console.log('inputMethodEngine beforeEach selectionChange oldEnd:' + oldEnd);
    console.log('inputMethodEngine beforeEach selectionChange newBegin:' + newBegin);
    console.log('inputMethodEngine beforeEach selectionChange newEnd:' + newEnd);
});
```

### off('selectionChange')

off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

Cancels listening for text selection changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Listening type.<br>The value **'selectionChange'** indicates the text selection change event.|
| callback | (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void | No  | Callback used to return the text selection information.<br>- **oldBegin**: start of the selected text before the change.<br>- **oldEnd**: end of the selected text before the change.<br>- **newBegin**: start of the selected text after the change.<br>- **newEnd**: end of the selected text after the change.<br>|

**Example**

```js
inputMethodEngine.getKeyboardDelegate().off('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
  console.log('delete selectionChange notification.');
});
```


### on('textChange')

on(type: 'textChange', callback: (text: string) => void): void

Enables listening for the text change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>The value **'textChange'** indicates the text change event.|
| callback | (text: string) => void | Yes  | Callback used to return the text content.                                  |

**Example**

```js
inputMethodEngine.getKeyboardDelegate().on('textChange', (text) => {
    console.log('inputMethodEngine textChange. text:' + text);
});
```

### off('textChange')

off(type: 'textChange', callback?: (text: string) => void): void

Cancels listening for text changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>The value **'textChange'** indicates the text change event.|
| callback | (text: string) => void | No  | Callback used to return the text content.|

**Example**

```js
inputMethodEngine.getKeyboardDelegate().off('textChange', (text) => {
    console.log('delete textChange notification. text:' + text);
});
```

## Panel<sup>10+</sup>

In the following API examples, you must first use **[createPanel](#createpanel10)** to obtain a **Panel** instance, and then call the APIs using the obtained instance.

### setUiContent<sup>10+</sup>

setUiContent(path: string, callback: AsyncCallback\<void>): void

Loads content from a page to this panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  | Path of the page from which the content will be loaded.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```js
try {
  panel.setUiContent('pages/page2/page2', (err) => {
    if (err) {
      console.error('Failed to set the content. err:' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in setting the content.');
  });
} catch (exception) {
  console.error('Failed to set the content. err:' + JSON.stringify(exception));
}
```

### setUiContent<sup>10+</sup>

setUiContent(path: string): Promise\<void>

Loads content from a page to this panel. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  | Path of the page from which the content will be loaded.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```js
try {
  let promise = panel.setUiContent('pages/page2/page2');
  promise.then(() => {
    console.info('Succeeded in setting the content.');
  }).catch((err) =>{
    console.error('Failed to set the content. err: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to set the content. err: ' + JSON.stringify(exception));
}
```

### setUiContent<sup>10+</sup>

setUiContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void

Loads content from a page linked to LocalStorage to this panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  | Path of the page from which the content will be loaded.|
| storage | [LocalStorage](../../quick-start/arkts-state-mgmt-application-level.md#localstorage) | Yes  | Storage unit that provides storage for mutable and immutable state variables in the application.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```js
let storage = new LocalStorage();
storage.setOrCreate('storageSimpleProp',121);
try {
  panel.setUiContent('pages/page2/page2', storage, (err) => {
    if (err) {
      console.error('Failed to set the content. err:' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in setting the content.');
  });
} catch (exception) {
  console.error('Failed to set the content. err:' + JSON.stringify(exception));
}
```

### setUiContent<sup>10+</sup>

setUiContent(path: string, storage: LocalStorage): Promise\<void>

Loads content from a page linked to LocalStorage to this panel. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  | Path of the page from which the content will be loaded.|
| storage | [LocalStorage](../../quick-start/arkts-state-mgmt-application-level.md#localstorage) | Yes  | Storage unit that provides storage for mutable and immutable state variables in the application.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```js
let storage = new LocalStorage();
storage.setOrCreate('storageSimpleProp',121);
try {
  let promise = panel.setUiContent('pages/page2/page2');
  promise.then(() => {
    console.info('Succeeded in setting the content.');
  }).catch((err) =>{
    console.error('Failed to set the content. err: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to set the content. err: ' + JSON.stringify(exception));
}
```

### resize<sup>10+</sup>

resize(width: number, height: number, callback: AsyncCallback\<void>): void

Resizes this panel. This API uses an asynchronous callback to return the result.
The panel width cannot exceed the screen width, and the panel height cannot be higher than half of the screen height.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| width | number | Yes  | Target width of the panel, in pixels.|
| height | number | Yes  | Target height of the panel, in pixels.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```js
try {
  panel.resize(500, 1000, (err) => {
    if (err) {
      console.error('Failed to change the panel size. Cause:' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in changing the panel size.');
  });
} catch (exception) {
  console.error('Failed to change the panel size. Cause:' + JSON.stringify(exception));
}
```

### resize<sup>10+</sup>

resize(width: number, height: number): Promise\<void>;

Resizes this panel. This API uses a promise to return the result.
The panel width cannot exceed the screen width, and the panel height cannot be higher than half of the screen height.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| width | number | Yes  | Target width of the panel, in pixels.|
| height | number | Yes  | Target height of the panel, in pixels.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise<void> | Promise that returns no value. |

**Example**

```js
try {
  let promise = panel.resize(500, 1000);
  promise.then(() => {
    console.info('Succeeded in changing the panel size.');
  }).catch((err) =>{
    console.error('Failed to change the panel size. err: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to change the panel size. err: ' + JSON.stringify(exception));
}
```

### moveTo<sup>10+</sup>

moveTo(x: number, y: number, callback: AsyncCallback\<void>): void

Moves this panel to the specified position. This API uses an asynchronous callback to return the result. 
This API does not work on panels in the FLG_FIXED state.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| x | number | Yes  | Distance to move along the x-axis, in px. A positive value indicates moving rightwards.|
| y | number | Yes  | Distance to move along the y-axis, in pixels. A positive value indicates moving downwards.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```js
try {
  panel.moveTo(300, 300, (err) =>{
    if (err) {
      console.error('Failed to move the panel. err:' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in moving the panel.');
  });
} catch (exception) {
    console.error('Failed to move the panel. err:' + JSON.stringify(exception));
}
```

### moveTo<sup>10+</sup>

moveTo(x: number, y: number): Promise\<void>

Moves this panel to the specified position. This API uses a promise to return the result. 
This API does not work on panels in the FLG_FIXED state.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| x | number | Yes  | Distance to move along the x-axis, in pixels. A positive value indicates moving rightwards.|
| y | number | Yes  | Distance to move along the y-axis, in pixels. A positive value indicates moving downwards.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise<void> | Promise that returns no value. |

**Example**

```js
try {
  let promise = windowClass.moveTo(300, 300);
  promise.then(() => {
    console.info('Succeeded in moving the panel.');
  }).catch((err) =>{
    console.error('Failed to move the panel. Cause: ' + JSON.stringify(err));
  });
} catch (exception) {
  console.error('Failed to move the panel. Cause:' + JSON.stringify(exception));
}
```

### show<sup>10+</sup>

show(callback: AsyncCallback\<void>): void

Displays this panel. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```js
panel.show((err) => {
  if (err) {
    console.error('Failed to show the panel. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in showing the panel.');
});
```

### show<sup>10+</sup>

show(): Promise\<void>

Displays this panel. This API uses a promise to return the result. 

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```js
let promise = panel.show();
promise.then(() => {
  console.info('Succeeded in showing the panel.');
}).catch((err) =>{
  console.error('Failed to show the panel. err: ' + JSON.stringify(err));
});
```

### hide<sup>10+</sup>

hide(callback: AsyncCallback\<void>): void

Hides this panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```js
panel.hide((err) => {
  if (err) {
    console.error('Failed to hide the panel. Cause: ' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in hiding the panel.');
});
```

### hide<sup>10+</sup>

hide(): Promise\<void>

Hides this panel. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```js
let promise = panel.hide();
promise.then(() => {
  console.info('Succeeded in hiding the panel.');
}).catch((err) =>{
  console.error('Failed to hide the panel. err: ' + JSON.stringify(err));
});
```

### on<sup>10+</sup>

on(type: 'show' | 'hide', callback: () => void): void

Enables listening for a panel visibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| type | 'show'\|'hide' | Yes| Listening type.<br>- The value **'show'** indicates the panel display event.<br>- The value **'hide'** indicates the panel hiding event.|
| callback | () => void | Yes  | Callback used to return the result.|

**Example**

```js
panel.on('show', () => {
  console.info('Panel is showing.');
});
```

### off<sup>10+</sup>

off(type: 'show' | 'hide', callback?: () => void): void

Disables listening for a panel visibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| type | 'show'/'hide' | Yes| Listening type.<br>- The value **'show'** indicates the panel display event.<br>- The value **'hide'** indicates the panel hiding event.|
| callback | () => void | No  | Callback used to return the result.|

**Example**

```js
panel.off('show');
```

### changeFlag<sup>10+</sup>

changeFlag(flag: PanelFlag): void

Changes the panel state type. This API only works for SOFT_KEYBOARD panels.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| flag | [PanelFlag](#panelflag10) | Yes| State type of the panel to switch to.|

**Example**

```js
let panelFlag = inputMethodEngine.getInputMethodAbility().PanelFlag.FLG_FIXED;
panel.changeFlag(panelFlag);
```

## KeyboardController

In the following API examples, you must first use **[on('inputStart')](#oninputstart9)** to obtain a **KeyboardController** instance, and then call the APIs using the obtained instance.

### hide<sup>9+</sup>

hide(callback: AsyncCallback&lt;void&gt;): void

Hides the keyboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**Example**

```js
keyboardController.hide((err) => {
    if (err !== undefined) {
        console.error('Failed to hide keyboard: ' + JSON.stringify(err));
        return;
    }
    console.log('Succeeded in hiding keyboard.');
});
```

### hide<sup>9+</sup>

hide(): Promise&lt;void&gt;

Hides the keyboard. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type            | Description                     |
| ---------------- | ------------------------- |
| Promise&lt;void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**Example**

```js
keyboardController.hide().then(() => {
    console.info('Succeeded in hiding keyboard.');
}).catch((err) => {
    console.info('Failed to hide keyboard: ' + JSON.stringify(err));
});
```

### hideKeyboard<sup>(deprecated)</sup>

hideKeyboard(callback: AsyncCallback&lt;void&gt;): void

Hides the keyboard. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [hide](#hide9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```js
keyboardController.hideKeyboard((err) => {
    if (err !== undefined) {
        console.error('Failed to hide Keyboard: ' + JSON.stringify(err));
        return;
    }
    console.log('Succeeded in hiding keyboard.');
});
```

### hideKeyboard<sup>(deprecated)</sup>

hideKeyboard(): Promise&lt;void&gt;

Hides the keyboard. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [hide](#hide9-1).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type            | Description                     |
| ---------------- | ------------------------- |
| Promise&lt;void> | Promise that returns no value.|

**Example**

```js
keyboardController.hideKeyboard().then(() => {
    console.info('Succeeded in hiding keyboard.');
}).catch((err) => {
    console.info('Failed to hide Keyboard: ' + JSON.stringify(err));
});
```

## InputClient<sup>9+</sup>

In the following API examples, you must first use **[on('inputStart')](#oninputstart9)** to obtain an **InputClient** instance, and then call the APIs using the obtained instance.

### sendKeyFunction<sup>9+</sup>

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

Sends the function key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Action of the function key.<br>**0**: invalid key.<br>**1**: confirm key (Enter key).|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. |

 **Example**

```js
let action = 1;
try {
    inputClient.sendKeyFunction(action, (err, result) => {
        if (err !== undefined) {
            console.error('Failed to sendKeyFunction: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Succeeded in sending key function. ');
        } else {
            console.error('Failed to sendKeyFunction. ');
        }
    });
} catch (err) {
    console.error('sendKeyFunction err: ' + JSON.stringify(err));
}
```

### sendKeyFunction<sup>9+</sup>

sendKeyFunction(action: number): Promise&lt;boolean&gt;

Sends the function key. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Action of the function key.<br>**0**: invalid key.<br>**1**: confirm key (Enter key).|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise used to return the result. The value **true** means that the operation is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**Example**

```js
let action = 1;
try {
    inputClient.sendKeyFunction(action).then((result) => {
        if (result) {
            console.info('Succeeded in sending key function. ');
        } else {
            console.error('Failed to sendKeyFunction. ');
        }
    }).catch((err) => {
        console.error('Failed to sendKeyFunction:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Failed to sendKeyFunction: ' + JSON.stringify(err));
}
```

### getForward<sup>9+</sup>

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text before the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained text. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                    |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**Example**

```js
let length = 1;
try {
    inputClient.getForward(length, (err, text) => {
        if (err !== undefined) {
            console.error('Failed to getForward: ' + JSON.stringify(err));
            return;
        }
        console.log('Succeeded in getting forward, text: ' + text);
    });
} catch (err) {
    console.error('Failed to getForward: ' + JSON.stringify(err));
}
```

### getForward<sup>9+</sup>

getForward(length:number): Promise&lt;string&gt;

Obtains the specific-length text before the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt;           |  Promise used to return the specific-length text before the cursor.                    |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                    |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**Example**

```js
let length = 1;
try {
    inputClient.getForward(length).then((text) => {
        console.info('Succeeded in getting forward, text: ' + text);
    }).catch((err) => {
        console.error('Failed to getForward: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Failed to getForward: ' + JSON.stringify(err));
}
```

### getBackward<sup>9+</sup>

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text after the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained text. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                    |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**Example**

```js
let length = 1;
try {
    inputClient.getBackward(length, (err, text) => {
        if (err !== undefined) {
            console.error('Failed to getForward: ' + JSON.stringify(err));
            return;
        }
        console.log('Succeeded in getting backward, text: ' + text);
    });
} catch (err) {
    console.error('Failed to getForward: ' + JSON.stringify(err));
}
```

### getBackward<sup>9+</sup>

getBackward(length:number): Promise&lt;string&gt;

Obtains the specific-length text after the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt;           |  Promise used to return the specific-length text after the cursor.                    |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                    |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**Example**

```js
let length = 1;
try {
    inputClient.getBackward(length).then((text) => {
        console.info('Succeeded in getting backward, text: ' + text);
    }).catch((err) => {
        console.error('Failed to getForward: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Failed to getForward: ' + JSON.stringify(err));
}
```

### deleteForward<sup>9+</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text before the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**Example**

```js
let length = 1;
try {
    inputClient.deleteForward(length, (err, result) => {
        if (err !== undefined) {
            console.error('Failed to delete forward: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Succeeded in deleting forward. ');
        } else {
            console.error('Failed to delete forward: ' + JSON.stringify(err));
        }
    });
} catch (err) {
    console.error('Failed to delete forward: ' + JSON.stringify(err));
}
```

### deleteForward<sup>9+</sup>

deleteForward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text before the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length.|

**Return value** 

| Type                  | Description          |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the operation is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**Example**

```js
let length = 1;
try {
    inputClient.deleteForward(length).then((result) => {
        if (result) {
            console.info('Succeeded in deleting forward. ');
        } else {
            console.error('Failed to delete Forward. ');
        }
    }).catch((err) => {
        console.error('Failed to delete Forward: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Failed to delete Forward: ' + JSON.stringify(err));
}
```

### deleteBackward<sup>9+</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                        | Mandatory| Description          |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | Yes  | Text length.    |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**Example**

```js
let length = 1;
try {
    inputClient.deleteBackward(length, (err, result) => {
        if (err !== undefined) {
            console.error('Failed to delete Backward: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Succeeded in deleting backward. ');
        } else {
            console.error('Failed to delete Backward: ' + JSON.stringify(err));
        }
    });
} catch (err) {
    console.error('deleteBackward err: ' + JSON.stringify(err));
}
```

### deleteBackward<sup>9+</sup>

deleteBackward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise used to return the result. The value **true** means that the deletion is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**Example**

```js
let length = 1;
inputClient.deleteBackward(length).then((result) => {
    if (result) {
        console.info('Succeeded in deleting backward. ');
    } else {
        console.error('Failed to deleteBackward. ');
    }
}).catch((err) => {
    console.error('Failed to deleteBackward: ' + JSON.stringify(err));
});
```

### insertText<sup>9+</sup>

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

Inserts text. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Text to insert.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**Example**

```js
inputClient.insertText('test', (err, result) => {
    if (err !== undefined) {
        console.error('Failed to insertText: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Succeeded in inserting text. ');
    } else {
        console.error('Failed to insertText. ');
    }
});
```

### insertText<sup>9+</sup>

insertText(text:string): Promise&lt;boolean&gt;

Inserts text. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Text to insert.|

**Return value** 

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt;  |  Promise used to return the result. The value **true** means that the insertion is successful, and **false** means the opposite. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800002 | Input method engine error. |
| 12800003 | input method client error. |

**Example**

```js
try {
    inputClient.insertText('test').then((result) => {
        if (result) {
            console.info('Succeeded in inserting text. ');
        } else {
            console.error('Failed to insertText. ');
        }
    }).catch((err) => {
        console.error('Failed to insertText: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('Failed to insertText: ' + JSON.stringify(err));
}
```

### getEditorAttribute<sup>9+</sup>

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

Obtains the attribute of the edit box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name                        | Type                         | Mandatory                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[EditorAttribute](#editorattribute)&gt; | Yes|  Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the attribute of the edit box. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**Example**

```js
inputClient.getEditorAttribute((err, editorAttribute) => {
    if (err !== undefined) {
        console.error('Failed to getEditorAttribute: ' + JSON.stringify(err));
        return;
    }
    console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
    console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
});
```

### getEditorAttribute<sup>9+</sup>

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

Obtains the attribute of the edit box. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#editorattribute)&gt; |  Promise used to return the attribute of the edit box.          |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**Example**

```js
inputClient.getEditorAttribute().then((editorAttribute) => {
    console.info('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
    console.info('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
}).catch((err) => {
    console.error('Failed to getEditorAttribute: ' + JSON.stringify(err));
});
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number, callback: AsyncCallback&lt;void&gt;): void

Moves the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------- |
| direction | number                    | Yes  | Direction in which the cursor moves.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.   |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**Example**

```js
try {
    inputClient.moveCursor(inputMethodEngine.CURSOR_UP, (err) => {
        if (err !== undefined) {
            console.error('Failed to moveCursor: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in moving cursor.');
    });
} catch (err) {
    console.error('Failed to moveCursor: ' + JSON.stringify(err));
}
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number): Promise&lt;void&gt;

Moves the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type  | Mandatory| Description          |
| --------- | ------ | ---- | -------------- |
| direction | number | Yes  | Direction in which the cursor moves.|

**Return value** 

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. |

**Example**

```js
try {
    inputClient.moveCursor(inputMethodEngine.CURSOR_UP).then(() => {
        console.log('Succeeded in moving cursor.');
    }).catch((err) => {
        console.error('Failed to moveCursor: ' + JSON.stringify(err));
    });
} catch (err) {
    console.log('Failed to moveCursor: ' + JSON.stringify(err));
}
```

### selectByRange<sup>10+</sup>

selectByRange(range: Range, callback: AsyncCallback&lt;void&gt;): void

Selects text based on the specified range. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| range    | [Range](./js-apis-inputmethod-InputMethodCommon.md#range) | Yes  | Range of the selected text.                                            |
| callback | AsyncCallback&lt;void&gt;                                 | Yes  | Callback used to return the result. If the selection event is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error.           |
| 12800003 | input method client error. |

**Example**

```js
try {
    inputClient.selectByRange({start: 0, end: 1}, (err) => {
        if (err !== undefined) {
            console.error('Failed to selectByRange: ${err.message}');
            return;
        }
        console.info('Succeeded in selecting by range.');
    });
} catch (err) {
    console.error('Failed to selectByRange: ${err.message}');
}
```

### selectByRange<sup>10+</sup>

selectByRange(range: Range): Promise&lt;void&gt;

Selects text based on the specified range. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type                                                     | Mandatory| Description            |
| ------ | --------------------------------------------------------- | ---- | ---------------- |
| range  | [Range](./js-apis-inputmethod-InputMethodCommon.md#range) | Yes  | Range of the selected text.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error.           |
| 12800003 | input method client error. |

**Example**

```js
try {
    inputClient.selectByRange({start: 0, end:1}).then(() => {
        console.log('Succeeded in selecting by range.');
    }).catch((err) => {
        console.error('Failed to selectByRange: ${err.message}');
    });
} catch (err) {
    console.log('Failed to selectByRange: ${err.message}');
}
```

### selectByMovement<sup>10+</sup>

selectByMovement(movement: Movement, callback: AsyncCallback&lt;void&gt;): void

Selects text based on the cursor movement direction. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| movement | [Movement](./js-apis-inputmethod-InputMethodCommon.md#movement) | Yes  | Direction in which the cursor moves when the text is selected.                                      |
| callback | AsyncCallback&lt;void&gt;                                    | Yes  | Callback used to return the result. If the selection event is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error.           |
| 12800003 | input method client error. |

**Example**

```js
try {
    inputClient.selectByMovement({direction: 1}, (err) => {
        if (err !== undefined) {
            console.error('Failed to selectByMovement: ${err.message}');
            return;
        }
        console.info('Succeeded in selecting by movement.');
    });
} catch (err) {
    console.error('Failed to selectByMovement: ${err.message}');
}
```

### selectByMovement<sup>10+</sup>

selectByMovement(movement: Movement): Promise&lt;void&gt;

Selects text based on the specified range. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| movement | [Movement](./js-apis-inputmethod-InputMethodCommon.md#movement) | Yes  | Direction in which the cursor moves when the text is selected.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error.           |
| 12800003 | input method client error. |

**Example**

```js
try {
    inputClient.selectByMovement({direction: 1}).then(() => {
        console.log('Succeeded in selecting by movement.');
    }).catch((err) => {
        console.error('Failed to selectByMovement: ${err.message}');
    });
} catch (err) {
    console.log('Failed to selectByMovement: ${err.message}');
}
```

### getTextIndexAtCursor<sup>10+</sup>

getTextIndexAtCursor(callback: AsyncCallback&lt;number&gt;): void

Obtains the index of the text where the cursor is located. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the text index is obtained, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | parameter error.               |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**Example**

```js
inputClient.getTextIndexAtCursor((err, index) => {
    if (err !== undefined) {
        console.error('Failed to getTextIndexAtCursor: ${err.message}');
        return;
    }
    console.info('Succeeded in getTextIndexAtCursor: ' + index);
});
```

### getTextIndexAtCursor<sup>10+</sup>

getTextIndexAtCursor(): Promise&lt;number&gt;

Obtains the index of the text where the cursor is located. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                 | Description                                   |
| --------------------- | --------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](../errorcodes/errorcode-inputmethod-framework.md).

| Error Code ID| Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error.     |
| 12800006 | Input method controller error. |

**Example**

```js
inputClient.getTextIndexAtCursor().then((index) => {
    console.info('Succeeded in getTextIndexAtCursor: ' + index);
}).catch((err) => {
    console.error('Failed to getTextIndexAtCursor: ${err.message}');
});
```

## EditorAttribute

Attribute of the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Type| Readable| Writable| Description              |
| ------------ | -------- | ---- | ---- | ------------------ |
| enterKeyType | number   | Yes  | No  | Function attribute of the edit box.|
| inputPattern | number   | Yes  | No  | Text attribute of the edit box.|

## KeyEvent

Describes the attribute of a key.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name     | Type| Readable| Writable| Description        |
| --------- | -------- | ---- | ---- | ------------ |
| keyCode   | number   | Yes  | No  | Key value.|
| keyAction | number   | Yes  | No  | Key status.|

## PanelFlag<sup>10+</sup>

Enumerates the state types of the input method panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Value| Description              |
| ------------ | -- | ------------------ |
| FLG_FIXED  | 0 | Fixed state type.|
| FLG_FLOATING | 1 | Floating state type.|

## PanelType<sup>10+</sup>

Enumerates the types of the input method panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Value| Description              |
| ------------ | -- | ------------------ |
| SOFT_KEYBOARD | 0 | Soft keyboard type.|
| STATUS_BAR   | 1 | Status bar type.|

## PanelInfo<sup>10+</sup>

**System capability**: SystemCapability.MiscServices.InputMethodFramework

Describes the attributes of the input method panel.

| Name     | Type| Readable| Writable| Description        |
| --------- | -------- | ---- | ---- | ------------ |
| type   	| number   | Yes  | Yes  | Type of the panel.|
| flag	    | number   | Yes  | Yes  | State type of the panel.|

## TextInputClient<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [InputClient](#inputclient9).

In the following API examples, you must first use **[on('inputStart')](#oninputstart)** to obtain a **TextInputClient** instance, and then call the APIs using the obtained instance.

### getForward<sup>(deprecated)</sup>

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text before the cursor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getForward](#getforward9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained text. Otherwise, **err** is an error object.|

**Example**

```js
let length = 1;
textInputClient.getForward(length, (err, text) => {
    if (err !== undefined) {
        console.error('Failed to getForward: ' + JSON.stringify(err));
        return;
    }
    console.log('Succeeded in getting forward, text: ' + text);
});
```

### getForward<sup>(deprecated)</sup>

getForward(length:number): Promise&lt;string&gt;

Obtains the specific-length text before the cursor. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getForward](#getforward9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Promise used to return the specific-length text before the cursor.               |

**Example**

```js
let length = 1;
textInputClient.getForward(length).then((text) => {
    console.info('Succeeded in getting forward, text: ' + text);
}).catch((err) => {
    console.error('Failed to getForward: ' + JSON.stringify(err));
});
```

### getBackward<sup>(deprecated)</sup>

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text after the cursor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getBackward](#getbackward9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained text. Otherwise, **err** is an error object.|

**Example**

```js
let length = 1;
textInputClient.getBackward(length, (err, text) => {
    if (err !== undefined) {
        console.error('Failed to getBackward: ' + JSON.stringify(err));
        return;
    }
    console.log('Succeeded in getting borward, text: ' + text);
});
```

### getBackward<sup>(deprecated)</sup>

getBackward(length:number): Promise&lt;string&gt;

Obtains the specific-length text after the cursor. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getBackward](#getbackward9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Promise used to return the specific-length text after the cursor.               |

**Example**

```js
let length = 1;
textInputClient.getBackward(length).then((text) => {
    console.info('Succeeded in getting backward: ' + JSON.stringify(text));
}).catch((err) => {
    console.error('Failed to getBackward: ' + JSON.stringify(err));
});
```

### deleteForward<sup>(deprecated)</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text before the cursor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [deleteForward](#deleteforward9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Example**

```js
let length = 1;
textInputClient.deleteForward(length, (err, result) => {
    if (err !== undefined) {
        console.error('Failed to deleteForward: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Succeeded in deleting forward. ');
    } else {
        console.error('Failed to deleteForward. ');
    }
});
```

### deleteForward<sup>(deprecated)</sup>

deleteForward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text before the cursor. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [deleteForward](#deleteforward9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length.|

**Return value** 

| Type                  | Description          |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the deletion is successful, and **false** means the opposite.|

**Example**

```js
let length = 1;
textInputClient.deleteForward(length).then((result) => {
    if (result) {
        console.info('Succeeded in deleting forward. ');
    } else {
        console.error('Failed to delete forward. ');
    }
}).catch((err) => {
    console.error('Failed to delete forward: ' + JSON.stringify(err));
});
```

### deleteBackward<sup>(deprecated)</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [deleteBackward](#deletebackward9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name  | Type                        | Mandatory| Description          |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | Yes  | Text length.    |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

  **Example**

```js
let length = 1;
textInputClient.deleteBackward(length, (err, result) => {
    if (err !== undefined) {
        console.error('Failed to delete backward: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Succeeded in deleting backward. ');
    } else {
        console.error('Failed to deleteBackward. ');
    }
});
```

### deleteBackward<sup>(deprecated)</sup>

deleteBackward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [deleteBackward](#deletebackward9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise used to return the result. The value **true** means that the deletion is successful, and **false** means the opposite.|

**Example**

```js
let length = 1;
textInputClient.deleteBackward(length).then((result) => {
    if (result) {
        console.info('Succeeded in deleting backward. ');
    } else {
        console.error('Failed to deleteBackward. ');
    }
}).catch((err) => {
    console.error('Failed to deleteBackward: ' + JSON.stringify(err));
});
```
### sendKeyFunction<sup>(deprecated)</sup>

sendKeyFunction(action: number, callback: AsyncCallback&lt;boolean&gt;): void

Sends the function key. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [sendKeyFunction](#sendkeyfunction9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Action of the function key.<br>**0**: invalid key.<br>**1**: confirm key (Enter key).|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

  **Example**

```js
let action = 1;
textInputClient.sendKeyFunction(action, (err, result) => {
    if (err !== undefined) {
        console.error('Failed to sendKeyFunction: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Succeeded in sending key function. ');
    } else {
        console.error('Failed to sendKeyFunction. ');
    }
});
```

### sendKeyFunction<sup>(deprecated)</sup>

sendKeyFunction(action: number): Promise&lt;boolean&gt;

Sends the function key. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [sendKeyFunction](#sendkeyfunction9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Action of the function key.<br>**0**: invalid key.<br>**1**: confirm key (Enter key).|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise used to return the result. The value **true** means that the setting is successful, and **false** means the opposite.|

**Example**

```js
let action = 1;
textInputClient.sendKeyFunction(action).then((result) => {
    if (result) {
        console.info('Succeeded in sending key function. ');
    } else {
        console.error('Failed to sendKeyFunction. ');
    }
}).catch((err) => {
    console.error('Failed to sendKeyFunction:' + JSON.stringify(err));
});
```

### insertText<sup>(deprecated)</sup>

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

Inserts text. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [insertText](#inserttext9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Text to insert.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Example**

```js
textInputClient.insertText('test', (err, result) => {
    if (err !== undefined) {
        console.error('Failed to insertText: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Succeeded in inserting text. ');
    } else {
        console.error('Failed to insertText. ');
    }
});
```

### insertText<sup>(deprecated)</sup>

insertText(text:string): Promise&lt;boolean&gt;

Inserts text. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [insertText](#inserttext9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Text to insert.|

**Return value** 

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise used to return the result. The value **true** means that the insertion is successful, and **false** means the opposite.|

**Example**

```js
textInputClient.insertText('test').then((result) => {
    if (result) {
        console.info('Succeeded in inserting text. ');
    } else {
        console.error('Failed to insertText. ');
    }
}).catch((err) => {
    console.error('Failed to insertText: ' + JSON.stringify(err));
});
```

### getEditorAttribute<sup>(deprecated)</sup>

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

Obtains the attribute of the edit box. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getEditorAttribute](#geteditorattribute9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name                        | Type                         | Mandatory                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[EditorAttribute](#editorattribute)&gt; | Yes|  Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the attribute of the edit box. Otherwise, **err** is an error object.|

**Example**

```js
textInputClient.getEditorAttribute((err, editorAttribute) => {
    if (err !== undefined) {
        console.error('Failed to getEditorAttribute: ' + JSON.stringify(err));
        return;
    }
    console.log('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
    console.log('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
});
```

### getEditorAttribute<sup>(deprecated)</sup>

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

Obtains the attribute of the edit box. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getEditorAttribute](#geteditorattribute9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#editorattribute)&gt; |  Promise used to return the attribute of the edit box.          |

**Example**

```js
textInputClient.getEditorAttribute().then((editorAttribute) => {
    console.info('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
    console.info('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
}).catch((err) => {
    console.error('Failed to getEditorAttribute: ' + JSON.stringify(err));
});
```
<!--no_check-->
