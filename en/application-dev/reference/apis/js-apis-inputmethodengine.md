# Input Method Engine

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import inputMethodEngine from '@ohos.inputmethodengine';
```

## inputMethodEngine

Defines constant values.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------------------- | -------- | ---- | ---- | ------------------- |
| ENTER_KEY_TYPE_UNSPECIFIED | number | Yes | No | No function is specified for the Enter key.|
| ENTER_KEY_TYPE_GO          | number | Yes | No | The Enter key takes the user to the target.|
| ENTER_KEY_TYPE_SEARCH      | number | Yes | No | The Enter key takes the user to the results of their searching.|
| ENTER_KEY_TYPE_SEND        | number | Yes | No | The Enter key sends the text to its target.|
| ENTER_KEY_TYPE_NEXT        | number | Yes | No | The Enter key takes the user to the next field.|
| ENTER_KEY_TYPE_DONE        | number | Yes | No | The Enter key takes the user to the next line.|
| ENTER_KEY_TYPE_PREVIOUS    | number | Yes | No | The Enter key takes the user to the previous field.|
| PATTERN_NULL               | number | Yes | No | Any type of edit box.|
| PATTERN_TEXT               | number | Yes | No | Text edit box.|
| PATTERN_NUMBER             | number | Yes | No | Number edit box.|
| PATTERN_PHONE              | number | Yes | No | Phone number edit box.|
| PATTERN_DATETIME           | number | Yes | No | Date edit box.|
| PATTERN_EMAIL              | number | Yes | No | Email edit box.|
| PATTERN_URI                | number | Yes | No | URI edit box.|
| PATTERN_PASSWORD           | number | Yes | No | Password edit box.|
| OPTION_ASCII               | number | Yes | No | ASCII values are allowed.|
| OPTION_NONE                | number | Yes | No | No input attribute is specified.|
| OPTION_AUTO_CAP_CHARACTERS | number | Yes | No | Characters are allowed.|
| OPTION_AUTO_CAP_SENTENCES  | number | Yes | No | Sentences are allowed.|
| OPTION_AUTO_WORDS          | number | Yes | No | Words are allowed.|
| OPTION_MULTI_LINE          | number | Yes | No | Multiple lines are allowed.|
| OPTION_NO_FULLSCREEN       | number | Yes | No | Half-screen style.|
| FLAG_SELECTING             | number | Yes | No | The edit box is being selected.|
| FLAG_SINGLE_LINE           | number | Yes | No | The edit box allows only single-line input.|
| DISPLAY_MODE_PART          | number | Yes | No | The edit box is displayed in half-screen mode.|
| DISPLAY_MODE_FULL          | number | Yes | No | The edit box is displayed in full screen.|

## inputMethodEngine.getInputMethodEngine

getInputMethodEngine(): InputMethodEngine

Obtains an **InputMethodEngine** instance.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Return value**

| Type                                   | Description        |
| --------------------------------------- | ------------ |
| [InputMethodEngine](#InputMethodEngine) | **InputMethodEngine** instance obtained.|

**Example**

```js
let InputMethodEngine = inputMethodEngine.getInputMethodEngine();
```

## inputMethodEngine.createKeyboardDelegate

createKeyboardDelegate(): KeyboardDelegate

Obtains a **KeyboardDelegate** instance.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Return value**

| Type                                 | Description            |
| ------------------------------------- | ---------------- |
| [KeyboardDelegate](#KeyboardDelegate) | **KeyboardDelegate** instance obtained.|

**Example**

```js
let KeyboardDelegate = inputMethodEngine.createKeyboardDelegate();
```

## InputMethodEngine

In the following API examples, you must first use [getInputMethodEngine](#getInputMethodEngine) to obtain an **InputMethodEngine** instance, and then call the APIs using the obtained instance.

### on('inputStart')

on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

Listens for the input method binding event. This API uses a callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | Yes  | Listening type.<br>Set it to **'inputStart'**, which indicates listening for the input method binding event.|
| callback | [KeyboardController](#KeyboardController), [TextInputClient](#TextInputClient) | Yes| Callback used to return the result.|

**Example**

```js
InputMethodEngine.on('inputStart', (kbController, textInputClient) => {
    KeyboardController = kbController;
    TextInputClient = textInputClient;
});
```

### off('inputStart')

off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

Cancels listening for the input method binding event.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | Yes  | Listening type.<br>Set it to **'inputStart'**, which indicates listening for the input method binding event.|
| callback | [KeyboardController](#KeyboardController), [TextInputClient](#TextInputClient) | No| Callback used to return the result.|

**Example**

```js
InputMethodEngine.off('inputStart');
```

### on('keyboardShow'|'keyboardHide')

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

Listens for an input method event.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** means to listen for displaying of the input method.<br>- The value **'keyboardHide'** means to listen for hiding of the input method.|
| callback | void   | No  | Callback used to return the result.                                                  |

**Example**

```js
InputMethodEngine.on('keyboardShow', (err) => {
    console.info('keyboardShow');
});
```

### off('keyboardShow'|'keyboardHide')

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

Cancels listening for an input method event.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** means to listen for displaying of the input method.<br>- The value **'keyboardHide'** means to listen for hiding of the input method.|
| callback | void   | No  | Callback used to return the result.                                                  |

**Example**

```js
InputMethodEngine.off('keyboardShow');
```

## KeyboardDelegate

In the following API examples, you must first use [createKeyboardDelegate](#createKeyboardDelegate) to obtain a **KeyboardDelegate** instance, and then call the APIs using the obtained instance.

### on('keyDown'|'keyUp')

on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void

Listens for a hard keyboard even. This API uses a callback to return the key information.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type   | string         | Yes  | Listening type.<br>- The value **'keyDown'** means to listen for pressing of a key.<br>- The value **'keyUp'** means to listen for releasing of a key.|
| callback | [KeyEvent](#KeyEvent) | Yes| Callback used to return the key information.|

**Example**

```js
KeyboardDelegate.on('keyDown', (event) => {
    console.info('keyDown');
});
```

### off('keyDown'|'keyUp')

off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void

Cancels listening for a hard keyboard even.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| type     | string                | Yes  | Listening type.<br>- The value **'keyDown'** means to listen for pressing of a key.<br>- The value **'keyUp'** means to listen for releasing of a key.|
| callback | [KeyEvent](#KeyEvent) | No  | Callback used to return the key information.                                          |

**Example**

```js
KeyboardDelegate.off('keyDown');
```

### on('cursorContextChange')

on(type: 'cursorContextChange', callback: (x: number, y:number, height:number) => void): void

Listens for cursor context changes. This API uses a callback to return the cursor information.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'cursorContextChange'**, which indicates listening for cursor context changes.|
| callback | number | Yes  | Callback used to return the cursor information.                                          |

**Example**

```js
KeyboardDelegate.on('cursorContextChange', (x, y, height) => {
    console.info('cursorContextChange');
});
```

### off('cursorContextChange')

off(type: 'cursorContextChange', callback?: (x: number, y:number, height:number) => void): void

Cancels listening for cursor context changes.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string       | Yes  | Listening type.<br>Set it to **'cursorContextChange'**, which indicates listening for cursor context changes.|
| callback | number | No| Callback used to return the cursor information.|

**Example**

```js
KeyboardDelegate.off('cursorContextChange');
```

### on('selectionChange')

on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

Listens for text selection changes. This API uses a callback to return the text selection information.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'selectionChange'**, which indicates listening for text selection changes.|
| callback | number | Yes  | Callback used to return the text selection information.                                      |

**Example**

```js
KeyboardDelegate.on('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
    console.info('selectionChange');
});
```

### off('selectionChange')

off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

Cancels listening for text selection changes.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Listening type.<br>Set it to **'selectionChange'**, which indicates listening for text selection changes.|
| callback | number | No| Callback used to return the text selection information.|

**Example**

```js
KeyboardDelegate.off('selectionChange');
```


### on('textChange')

on(type: 'textChange', callback: (text: string) => void): void

Listens for text changes. This API uses a callback to return the current text content.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Listening type.<br>Set it to **'textChange'**, which indicates listening for text changes.|
| callback | string | Yes| Callback used to return the current text content.|

**Example**

```js
KeyboardDelegate.on('textChange', (text) => {
    console.info('textChange');
});
```

### off('textChange')

off(type: 'textChange', callback?: (text: string) => void): void

Cancels listening for text changes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string                  | Yes  | Listening type.<br>Set it to **'textChange'**, which indicates listening for text changes.|
| callback | string | No| Callback used to return the current text content.|

**Example**

```js
KeyboardDelegate.off('textChange');
```

## KeyboardController

In the following API examples, you must first use [inputStart](#inputStart) to obtain a **KeyboardController** instance, and then call the APIs using the obtained instance.

### hideKeyboard

hideKeyboard(callback: AsyncCallback&lt;void&gt;): void

Hides the keyboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | No  | Callback used to return the result.|

**Example**

```js
KeyboardController.hideKeyboard(()=>{
});
```

### hideKeyboard

hideKeyboard(): Promise&lt;void&gt;

Hides the keyboard. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type            | Description    |
| ---------------- | -------- |
| Promise&lt;void> | Promise used to return the result.|

**Example**

```js
KeyboardController.hideKeyboard();
```

## TextInputClient

In the following API examples, you must first use [inputStart](#inputStart) to obtain a **TextInputClient** instance, and then call the APIs using the obtained instance.

### getForward

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text before the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;string&gt; | Yes| Text returned.|

**Example**

```js
TextInputClient.getForward(5,(text) =>{
    console.info("text = " + text);
});
```

### getForward

getForward(length:number): Promise&lt;string&gt;

Obtains the specific-length text before the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Text returned.               |

**Example**

```js
let text = TextInputClient.getForward(5);
console.info("text = " + text);
```

### getBackward

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text after the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;string&gt; | Yes| Text returned.|

**Example**

```js
TextInputClient.getBackward(5,(text)=>{
    console.info("text = " + text);
});
```

### getBackward

getBackward(length:number): Promise&lt;string&gt;

Obtains the specific-length text after the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Text returned.               |

**Example**

```js
let text = TextInputClient.getBackward(5);
console.info("text = " + text);
```

### deleteForward

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text before the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Returns whether the operation is successful.|

**Example**

```js
TextInputClient.deleteForward(5,(isSuccess)=>{
    console.info("isSuccess = " + isSuccess);
});
```

### deleteForward

deleteForward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text before the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value** 

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Returns whether the operation is successful.               |

**Example**

```js
let isSuccess = TextInputClient.deleteForward(5);
console.info("isSuccess = " + isSuccess);
```

### deleteBackward

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Returns whether the operation is successful.|

**Example**

```js
TextInputClient.deleteBackward(5, (isSuccess)=>{
    console.info("isSuccess = " + isSuccess);
});
```

### deleteBackward

deleteBackward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text after the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Returns whether the operation is successful.               |

**Example**

```js
let isSuccess = TextInputClient.deleteBackward(5);
console.info("isSuccess = " + isSuccess);
```

### sendKeyFunction

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

Sets the Enter key to send the text to its target. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Edit box attribute.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Returns whether the operation is successful.|

**Example**

```js
TextInputClient.sendKeyFunction(inputMethod.ENTER_KEY_TYPE_NEXT,(isSuccess)=>{
    console.info("isSuccess = " + isSuccess);
});
```

### sendKeyFunction

sendKeyFunction(action:number): Promise&lt;boolean&gt;

Sets the Enter key to send the text to its target. This API uses a promise to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Edit box attribute.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Returns whether the operation is successful.               |

**Example**

```js
let isSuccess = TextInputClient.sendKeyFunction(inputMethod.ENTER_KEY_TYPE_NEXT);
console.info("isSuccess = " + isSuccess);
```

### insertText

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

Inserts text. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Text to insert.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Returns whether the operation is successful.|

**Example**

```js
TextInputClient.insertText("test", (isSuccess)=>{
    console.info("isSuccess = " + isSuccess);
});
```

### insertText

insertText(text:string): Promise&lt;boolean&gt;

Inserts text. This API uses a promise to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Text to insert.|

**Return value**   

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Returns whether the operation is successful.               |

**Example**

```js
let isSuccess = TextInputClient.insertText("test");
console.info("isSuccess = " + isSuccess);
```

### getEditorAttribute

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

Obtains the attribute of the edit box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Parameters**

| Name                        | Type                         | Mandatory                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[EditorAttribute](#EditorAttribute)&gt; | Yes|  Attribute of the edit box.               |

**Example**

```js
TextInputClient.getEditorAttribute((EditorAttribute)=>{
});
```

### getEditorAttribute

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

Obtains the attribute of the edit box. This API uses a promise to return the result.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#EditorAttribute)&gt; |  Returns the attribute of the edit box.          |

**Example**

```js
let EditorAttribute = TextInputClient.getEditorAttribute();
```

## EditorAttribute

Describes the attribute of the edit box.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

| Name        | Type| Readable| Writable| Description              |
| ------------ | -------- | ---- | ---- | ------------------ |
| enterKeyType | number   | Yes  | No  | Function attribute of the edit box.|
| inputPattern | number   | Yes  | No  | Text attribute of the edit box.|

## KeyEvent

Describes the attribute of a key.

**System capability**: SystemCapability.Miscservices.InputMethodFramework

| Name     | Type| Readable| Writable| Description        |
| --------- | -------- | ---- | ---- | ------------ |
| keyCode   | number   | Yes  | No  | Key value.|
| keyAction | number   | Yes  | No  | Key status.|
