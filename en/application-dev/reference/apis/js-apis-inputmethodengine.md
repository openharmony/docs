# Input Method Engine

The **inputMethodEngine** module streamlines the interaction between input methods and applications. By calling APIs of this module, applications can be bound to input method services to accept text input through the input methods, request the keyboard to display or hide, listen for the input method status, and much more.

> **NOTE**
>
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import inputMethodEngine from '@ohos.inputmethodengine';
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

Obtains an **InputMethodEngine** instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                   | Description        |
| --------------------------------------- | ------------ |
| [InputMethodAbility](#inputmethodability) | **InputMethodEngine** instance obtained.|

**Example**

```js
let InputMethodAbility = inputMethodEngine.getInputMethodAbility();
```

## inputMethodEngine.getKeyboardDelegate<sup>9+</sup>

getKeyboardDelegate(): KeyboardDelegate

Obtains a **KeyboardDelegate** instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                 | Description            |
| ------------------------------------- | ---------------- |
| [KeyboardDelegate](#keyboarddelegate) | **KeyboardDelegate** instance obtained.|

**Example**

```js
let KeyboardDelegate = inputMethodEngine.getKeyboardDelegate();
```

## inputMethodEngine.getInputMethodEngine<sup>(deprecated)</sup>

getInputMethodEngine(): InputMethodEngine

Obtains an **InputMethodEngine** instance.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getInputMethodAbility()](#inputmethodenginegetinputmethodability9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                   | Description        |
| --------------------------------------- | ------------ |
| [InputMethodEngine](#inputmethodengine-1) | **InputMethodEngine** instance obtained.|

**Example**

```js
let InputMethodEngine = inputMethodEngine.getInputMethodEngine();
```

## inputMethodEngine.createKeyboardDelegate<sup>(deprecated)</sup>

createKeyboardDelegate(): KeyboardDelegate

Obtains a **KeyboardDelegate** instance.

> **NOTE**
>
>This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getKeyboardDelegate()](#inputmethodenginegetkeyboarddelegate9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                 | Description            |
| ------------------------------------- | ---------------- |
| [KeyboardDelegate](#keyboarddelegate) | **KeyboardDelegate** instance obtained.|

**Example**

```js
let KeyboardDelegate = inputMethodEngine.createKeyboardDelegate();
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
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclient)) => void | Yes| Callback used to return the **KeyboardController** and **TextInputClient** instances.|

**Example**

```js
inputMethodEngine.getInputMethodEngine().on('inputStart', (kbController, textInputClient) => {
    KeyboardController = kbController;
    TextInputClient = textInputClient;
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
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclient)) => void | No| Callback used to return the **KeyboardController** and **TextInputClient** instances.|

**Example**

```js
inputMethodEngine.getInputMethodEngine().off('inputStart', (kbController, textInputClient) => {
    console.log('delete inputStart notification.');
});
```

### on('keyboardShow'|'keyboardHide')

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

Enables listening for a keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event. |
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

Disables listening for a keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event. |
| callback | () => void   | No  | Callback used to return the result.|

**Example**

```js
inputMethodEngine.getInputMethodEngine().off('keyboardShow', () => {
    console.log('inputMethodEngine delete keyboardShow notification.');
});
inputMethodEngine.getInputMethodEngine().off('keyboardHide', () => {
    console.log('inputMethodEngine delete keyboardHide notification.');
});
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
inputMethodEngine.getInputMethodAbility().on('inputStart', (kbController, inputClient) => {
    KeyboardController = kbController;
    InputClient = inputClient;
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
inputMethodEngine.getInputMethodAbility().off('inputStart', (kbController, inputClient) => {
    console.log('delete inputStart notification.');
});
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

Enables listening for an input method event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event. |
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

Disables listening for an input method event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>The value **'keyboardShow'** indicates the keyboard display event.<br>The value **'keyboardHide'** indicates the keyboard hiding event.|
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
| 12800003 | Input method client error. |

**Example**

```js
KeyboardController.hide((err) => {
    if (err === undefined) {
        console.error('hide err: ' + JSON.stringify(err));
        return;
    }
    console.log('hide success.');
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
| 12800003 | Input method client error. |

**Example**

```js
KeyboardController.hide().then(() => {
    console.info('hide success.');
}).catch((err) => {
    console.info('hide err: ' + JSON.stringify(err));
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
KeyboardController.hideKeyboard((err) => {
    if (err === undefined) {
        console.error('hideKeyboard err: ' + JSON.stringify(err));
        return;
    }
    console.log('hideKeyboard success.');
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
KeyboardController.hideKeyboard().then(() => {
    console.info('hideKeyboard success.');
}).catch((err) => {
    console.info('hideKeyboard err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error. |

 **Example**

```js
let action = 1;
try {
    InputClient.sendKeyFunction(action, (err, result) => {
        if (err) {
            console.error('sendKeyFunction err: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Success to sendKeyFunction. ');
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
| 12800003 | Input method client error. |

**Example**

```js
let action = 1;
try {
    InputClient.sendKeyFunction(action).then((result) => {
        if (result) {
            console.info('Success to sendKeyFunction. ');
        } else {
            console.error('Failed to sendKeyFunction. ');
        }
    }).catch((err) => {
        console.error('sendKeyFunction err:' + JSON.stringify(err));
    });
} catch (err) {
    console.error('sendKeyFunction err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error.     |
| 12800006 | Input method controller error. |

**Example**

```js
let length = 1;
try {
    InputClient.getForward(length, (err, text) => {
        if (err) {
            console.error('getForward err: ' + JSON.stringify(err));
            return;
        }
        console.log('getForward result: ' + text);
    });
} catch (err) {
    console.error('getForward err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error.     |
| 12800006 | Input method controller error. |

**Example**

```js
let length = 1;
try {
    InputClient.getForward(length).then((text) => {
        console.info('getForward resul: ' + text);
    }).catch((err) => {
        console.error('getForward err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('getForward err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error.     |
| 12800006 | Input method controller error. |

**Example**

```js
let length = 1;
try {
    InputClient.getBackward(length, (err, text) => {
        if (err) {
            console.error('getBackward result: ' + JSON.stringify(err));
            return;
        }
        console.log('getBackward result---text: ' + text);
    });
} catch (err) {
    console.error('getBackward result: ' + JSON.stringify(err));
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
| 12800003 | Input method client error.     |
| 12800006 | Input method controller error. |

**Example**

```js
let length = 1;
try {
    InputClient.getBackward(length).then((text) => {
        console.info('getBackward result: ' + text);
    }).catch((err) => {
        console.error('getBackward err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('getBackward err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error. |

**Example**

```js
let length = 1;
try {
    InputClient.deleteForward(length, (err, result) => {
        if (err) {
            console.error('deleteForward result: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Success to deleteForward. ');
        } else {
            console.error('Failed to deleteForward. ');
        }
    });
} catch (err) {
    console.error('deleteForward result: ' + JSON.stringify(err));
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
| 12800003 | Input method client error. |

**Example**

```js
let length = 1;
try {
    InputClient.deleteForward(length).then((result) => {
        if (result) {
            console.info('Success to deleteForward. ');
        } else {
            console.error('Failed to deleteForward. ');
        }
    }).catch((err) => {
        console.error('deleteForward err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('deleteForward err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error. |

**Example**

```js
let length = 1;
try {
    InputClient.deleteBackward(length, (err, result) => {
        if (err) {
            console.error('deleteBackward err: ' + JSON.stringify(err));
            return;
        }
        if (result) {
            console.info('Success to deleteBackward. ');
        } else {
            console.error('Failed to deleteBackward. ');
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
| 12800003 | Input method client error. |

**Example**

```js
let length = 1;
InputClient.deleteBackward(length).then((result) => {
    if (result) {
        console.info('Success to deleteBackward. ');
    } else {
        console.error('Failed to deleteBackward. ');
    }
}).catch((err) => {
    console.error('deleteBackward err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error. |

**Example**

```js
InputClient.insertText('test', (err, result) => {
    if (err) {
        console.error('insertText err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to insertText. ');
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
| 12800003 | Input method client error. |

**Example**

```js
try {
    InputClient.insertText('test').then((result) => {
        if (result) {
            console.info('Success to insertText. ');
        } else {
            console.error('Failed to insertText. ');
        }
    }).catch((err) => {
        console.error('insertText err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.error('insertText err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error. |

**Example**

```js
InputClient.getEditorAttribute((err, editorAttribute) => {
    if (err) {
        console.error('getEditorAttribute err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error. |

**Example**

```js
InputClient.getEditorAttribute().then((editorAttribute) => {
    console.info('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
    console.info('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
}).catch((err) => {
    console.error('getEditorAttribute err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error. |

**Example**

```js
try {
    InputClient.moveCursor(inputMethodEngine.CURSOR_xxx, (err) => {
        if (err) {
            console.error('moveCursor err: ' + JSON.stringify(err));
            return;
        }
        console.info('moveCursor success');
    });
} catch (err) {
    console.error('moveCursor err: ' + JSON.stringify(err));
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
| 12800003 | Input method client error. |

**Example**

```js
try {
    InputClient.moveCursor(inputMethodEngine.CURSOR_UP).then(() => {
        console.log('moveCursor success');
    }).catch((err) => {
        console.error('moveCursor success err: ' + JSON.stringify(err));
    });
} catch (err) {
    console.log('moveCursor err: ' + JSON.stringify(err));
}
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
TextInputClient.getForward(length, (err, text) => {
    if (err === undefined) {
        console.error('getForward err: ' + JSON.stringify(err));
        return;
    }
    console.log('getForward result---text: ' + text);
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
TextInputClient.getForward(length).then((text) => {
    console.info('getForward result: ' + JSON.stringify(text));
}).catch((err) => {
    console.error('getForward err: ' + JSON.stringify(err));
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
TextInputClient.getBackward(length, (err, text) => {
    if (err === undefined) {
        console.error('getBackward err: ' + JSON.stringify(err));
        return;
    }
    console.log('getBackward result---text: ' + text);
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
TextInputClient.getBackward(length).then((text) => {
    console.info('getBackward result: ' + JSON.stringify(text));
}).catch((err) => {
    console.error('getBackward err: ' + JSON.stringify(err));
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
TextInputClient.deleteForward(length, (err, result) => {
    if (err === undefined) {
        console.error('deleteForward err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to deleteForward. ');
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
TextInputClient.deleteForward(length).then((result) => {
    if (result) {
        console.info('Succeed in deleting forward. ');
    } else {
        console.error('Failed to delete forward. ');
    }
}).catch((err) => {
    console.error('Failed to delete forward err: ' + JSON.stringify(err));
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
TextInputClient.deleteBackward(length, (err, result) => {
    if (err === undefined) {
        console.error('deleteBackward err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to deleteBackward. ');
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
TextInputClient.deleteBackward(length).then((result) => {
    if (result) {
        console.info('Success to deleteBackward. ');
    } else {
        console.error('Failed to deleteBackward. ');
    }
}).catch((err) => {
    console.error('deleteBackward err: ' + JSON.stringify(err));
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
TextInputClient.sendKeyFunction(action, (err, result) => {
    if (err === undefined) {
        console.error('sendKeyFunction err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to sendKeyFunction. ');
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
TextInputClient.sendKeyFunction(action).then((result) => {
    if (result) {
        console.info('Success to sendKeyFunction. ');
    } else {
        console.error('Failed to sendKeyFunction. ');
    }
}).catch((err) => {
    console.error('sendKeyFunction err:' + JSON.stringify(err));
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
TextInputClient.insertText('test', (err, result) => {
    if (err === undefined) {
        console.error('insertText err: ' + JSON.stringify(err));
        return;
    }
    if (result) {
        console.info('Success to insertText. ');
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
TextInputClient.insertText('test').then((result) => {
    if (result) {
        console.info('Success to insertText. ');
    } else {
        console.error('Failed to insertText. ');
    }
}).catch((err) => {
    console.error('insertText err: ' + JSON.stringify(err));
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
TextInputClient.getEditorAttribute((err, editorAttribute) => {
    if (err === undefined) {
        console.error('getEditorAttribute err: ' + JSON.stringify(err));
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
TextInputClient.getEditorAttribute().then((editorAttribute) => {
    console.info('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
    console.info('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
}).catch((err) => {
    console.error('getEditorAttribute err: ' + JSON.stringify(err));
});
```
