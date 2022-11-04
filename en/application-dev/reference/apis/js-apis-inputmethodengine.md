# Input Method Engine

The **inputMethodEngine** module streamlines the interaction between applications and input methods. By calling APIs of this module, applications can accept text input through the input methods, be bound to input method services, request the keyboard to display or hide, listen for the input method status, and much more.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import inputMethodEngine from '@ohos.inputmethodengine';
```

## inputMethodEngine

Provides the constants.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| ENTER_KEY_TYPE_UNSPECIFIED | number | Yes| No| No function is specified for the Enter key.|
| ENTER_KEY_TYPE_GO | number | Yes| No| The Enter key takes the user to the target.|
| ENTER_KEY_TYPE_SEARCH | number | Yes| No| The Enter key takes the user to the results of their searching.|
| ENTER_KEY_TYPE_SEND | number | Yes| No| The Enter key sends the text to its target.|
| ENTER_KEY_TYPE_NEXT | number | Yes| No| The Enter key takes the user to the next field.|
| ENTER_KEY_TYPE_DONE | number | Yes| No| The Enter key takes the user to the next line.|
| ENTER_KEY_TYPE_PREVIOUS | number | Yes| No| The Enter key takes the user to the previous field.|
| PATTERN_NULL | number | Yes| No| Any type of edit box.|
| PATTERN_TEXT | number | Yes| No| Text edit box.|
| PATTERN_NUMBER | number | Yes| No| Number edit box.|
| PATTERN_PHONE | number | Yes| No| Phone number edit box.|
| PATTERN_DATETIME | number | Yes| No| Date edit box.|
| PATTERN_EMAIL | number | Yes| No| Email edit box.|
| PATTERN_URI | number | Yes| No| URI edit box.|
| PATTERN_PASSWORD | number | Yes| No| Password edit box.|
| OPTION_ASCII | number | Yes| No| ASCII values are allowed.|
| OPTION_NONE | number | Yes| No| No input attribute is specified.|
| OPTION_AUTO_CAP_CHARACTERS | number | Yes| No| Characters are allowed.|
| OPTION_AUTO_CAP_SENTENCES | number | Yes| No| Sentences are allowed.|
| OPTION_AUTO_WORDS | number | Yes| No| Words are allowed.|
| OPTION_MULTI_LINE | number | Yes| No| Multiple lines are allowed.|
| OPTION_NO_FULLSCREEN | number | Yes| No| Half-screen style.|
| FLAG_SELECTING | number | Yes| No| The edit box is being selected.|
| FLAG_SINGLE_LINE | number | Yes| No| The edit box allows only single-line input.|
| DISPLAY_MODE_PART | number | Yes| No| The edit box is displayed in half-screen mode.|
| DISPLAY_MODE_FULL | number | Yes| No| The edit box is displayed in full screen.|
| CURSOR_UP<sup>9+</sup> | number | Yes| No| The caret moves upward.|
| CURSOR_DOWN<sup>9+</sup> | number | Yes| No| The caret moves downward.|
| CURSOR_LEFT<sup>9+</sup> | number | Yes| No| The caret moves leftward.|
| CURSOR_RIGHT<sup>9+</sup> | number | Yes| No| The caret moves rightward.|
| WINDOW_TYPE_INPUT_METHOD_FLOAT<sup>9+</sup> | number | Yes| No| The input method is displayed in a floating window.|

## inputMethodEngine.getInputMethodEngine<a name="getInputMethodEngine"></a>

getInputMethodEngine(): InputMethodEngine

Obtains an **InputMethodEngine** instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                   | Description        |
| --------------------------------------- | ------------ |
| [InputMethodEngine](#InputMethodEngine) | **InputMethodEngine** instance obtained.|

**Example**

  ```js
  var InputMethodEngine = inputMethodEngine.getInputMethodEngine();
  ```

## inputMethodEngine.createKeyboardDelegate<a name="createKeyboardDelegate"></a>

createKeyboardDelegate(): KeyboardDelegate

Obtains a **KeyboardDelegate** instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                 | Description            |
| ------------------------------------- | ---------------- |
| [KeyboardDelegate](#KeyboardDelegate) | **KeyboardDelegate** instance obtained.|

**Example**

  ```js
  var KeyboardDelegate = inputMethodEngine.createKeyboardDelegate();
  ```

## InputMethodEngine<a name="InputMethodEngine"></a>

In the following API examples, you must first use [getInputMethodEngine](#getInputMethodEngine) to obtain an **InputMethodEngine** instance, and then call the APIs using the obtained instance.

### on('inputStart')<a name="inputStart"></a>

on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

Listens for the input method binding event. This API uses a callback to return the result. This API requires two parameters, the first one being napi_string and the second one being napi_function. If either of these parameters is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

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

Cancels listening for the input method binding event. An exception is thrown in the following cases: (1) No parameter is passed; (2) Only one parameter is passed in, and it is not napi_string; (2) Two parameters are passed in, and the first parameter is not napi_string or the second parameter is not napi_function. If only one parameter is passed in, all listeners of the specified type will be canceled. If two parameters are passed in, the current listener of the specified type will be canceled.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | Yes  | Listening type.<br>Set it to **'inputStart'**, which indicates listening for the input method binding event.|
| callback | [KeyboardController](#KeyboardController), [TextInputClient](#TextInputClient) | No| Callback used to return the result.|



**Example**

  ```js
  InputMethodEngine.off('inputStart', (kbController, textInputClient) => {
      console.log('delete inputStart notification.');
  });
  ```

### on('inputStop')<sup>9+</sup>

on(type: 'inputStop', callback: () => void): void

Listens for the input method stop event. This API uses a callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'inputStop'**, which indicates listening for the input method stop event.|
| callback | void   | Yes  | Callback used to return the result.                                                  |

**Example**

  ```js
InputMethodEngine.getInputMethodEngine().on('inputStop', () => {
    console.log('inputMethodEngine inputStop');
});
  ```

### off('inputStop')<sup>9+</sup>

off(type: 'inputStop', callback: () => void): void

Cancels listening for the input method stop event. This API uses a callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'inputStop'**, which indicates listening for the input method stop event.|
| callback | void   | Yes  | Callback used to return the result.                                                  |

**Example**

  ```js
InputMethodEngine.getInputMethodEngine().off('inputStop', () => {
    console.log('inputMethodEngine delete inputStop notification.');
});
  ```

### on('setCallingWindow')<sup>9+</sup>

on(type: 'setCallingWindow', callback: (wid:number) => void): void

Listens for the window invocation setting event. This API uses a callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'setCallingWindow'**, which indicates listening for the window invocation setting event.|
| callback | number | Yes  | Window ID of the caller.                                           |

**Example**

  ```js
InputMethodEngine.getInputMethodEngine().on('setCallingWindow', (wid) => {
    console.log('inputMethodEngine setCallingWindow');
});
  ```

### off('setCallingWindow')<sup>9+</sup>

off(type: 'setCallingWindow', callback: (wid:number) => void): void

Cancels listening for the window invocation setting event. This API uses a callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'setCallingWindow'**, which indicates listening for the window invocation setting event.|
| callback | number | Yes  | Window ID of the caller.                                |

**Example**

  ```js
InputMethodEngine.getInputMethodEngine().off('setCallingWindow', () => {
    console.log('inputMethodEngine delete setCallingWindow notification.');
});
  ```

### on('keyboardShow'|'keyboardHide')

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

Listens for an input method event. This API requires two parameters, the first one being napi_string and the second one being napi_function. If either of these parameters is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** means to listen for displaying of the keyboard.<br>- The value **'keyboardHide'** means to listen for hiding of the keyboard. |
| callback | void   | No  | Callback used to return the result.                                                  |

**Example**

  ```js
  InputMethodEngine.on('keyboardShow', () => {
      console.log('inputMethodEngine keyboardShow.');
  });
  InputMethodEngine.on('keyboardHide', () => {
      console.log('inputMethodEngine keyboardHide.');
  });
  ```

### off('keyboardShow'|'keyboardHide')

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

Cancels listening for an input method event. An exception is thrown in the following cases: (1) No parameter is passed; (2) Only one parameter is passed in, and it is not napi_string; (2) Two parameters are passed in, and the first parameter is not napi_string or the second parameter is not napi_function. If only one parameter is passed in, all listeners of the specified type will be canceled. If two parameters are passed in, the current listener of the specified type will be canceled.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>- The value **'keyboardShow'** means to listen for displaying of the keyboard.<br>- The value **'keyboardHide'** means to listen for hiding of the keyboard.|
| callback | void   | No  | Callback used to return the result.                                                  |

**Example**

  ```js
  InputMethodEngine.off('keyboardShow', () => {
      console.log('inputMethodEngine delete keyboardShow notification.');
  });
  InputMethodEngine.off('keyboardHide', () => {
      console.log('inputMethodEngine delete keyboardHide notification.');
  });
  ```


## KeyboardDelegate<a name="KeyboardDelegate"></a>

In the following API examples, you must first use [createKeyboardDelegate](#createKeyboardDelegate) to obtain a **KeyboardDelegate** instance, and then call the APIs using the obtained instance.

### on('keyDown'|'keyUp')

on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void

Listens for a hard keyboard even. This API uses a callback to return the key information. This API requires two parameters, the first one being napi_string and the second one being napi_function. If either of these parameters is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type   | string         | Yes  | Listening type.<br>- The value **'keyDown'** means to listen for pressing of a key.<br>- The value **'keyUp'** means to listen for releasing of a key.|
| callback | [KeyEvent](#KeyEvent) | Yes| Callback used to return the key information.|



**Example**

  ```js
  KeyboardDelegate.on('keyUp', (keyEvent) => {
      console.info('inputMethodEngine keyCode.(keyUp):' + JSON.stringify(keyEvent.keyCode));
      console.info('inputMethodEngine keyAction.(keyUp):' + JSON.stringify(keyEvent.keyAction));
      return true;
  });
  KeyboardDelegate.on('keyDown', (keyEvent) => {
      console.info('inputMethodEngine keyCode.(keyDown):' + JSON.stringify(keyEvent.keyCode));
      console.info('inputMethodEngine keyAction.(keyDown):' + JSON.stringify(keyEvent.keyAction));
      return true;
  });
  ```

### off('keyDown'|'keyUp')

off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void

Cancels listening for a hard keyboard even. An exception is thrown in the following cases: (1) No parameter is passed; (2) Only one parameter is passed in, and it is not napi_string; (2) Two parameters are passed in, and the first parameter is not napi_string or the second parameter is not napi_function. If only one parameter is passed in, all listeners of the specified type will be canceled. If two parameters are passed in, the current listener of the specified type will be canceled.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| type     | string                | Yes  | Listening type.<br>- The value **'keyDown'** means to listen for pressing of a key.<br>- The value **'keyUp'** means to listen for releasing of a key.|
| callback | [KeyEvent](#KeyEvent) | No  | Callback used to return the key information.                                          |

**Example**

  ```js
  KeyboardDelegate.off('keyUp', (keyEvent) => {
      console.log('delete keyUp notification.');
      return true;
  });
  KeyboardDelegate.off('keyDown', (keyEvent) => {
      console.log('delete keyDown notification.');
      return true;
  });
  ```

### on('cursorContextChange')

on(type: 'cursorContextChange', callback: (x: number, y:number, height:number) => void): void

Listens for cursor context changes. This API uses a callback to return the cursor information. This API requires two parameters, the first one being napi_string and the second one being napi_function. If either of these parameters is not passed in, an exception is thrown.

  **System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'cursorContextChange'**, which indicates listening for cursor context changes.|
| callback | number | Yes  | Callback used to return the cursor information.                                          |



  **Example**

```js
KeyboardDelegate.on('cursorContextChange', (x, y, height) => {
    console.log('inputMethodEngine cursorContextChange x:' + x);
    console.log('inputMethodEngine cursorContextChange y:' + y);
    console.log('inputMethodEngine cursorContextChange height:' + height);
});
```

### off('cursorContextChange')

off(type: 'cursorContextChange', callback?: (x: number, y:number, height:number) => void): void

Cancels listening for cursor context changes. An exception is thrown in the following cases: (1) No parameter is passed; (2) Only one parameter is passed in, and it is not napi_string; (2) Two parameters are passed in, and the first parameter is not napi_string or the second parameter is not napi_function. If only one parameter is passed in, all listeners of the specified type will be canceled. If two parameters are passed in, the current listener of the specified type will be canceled.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'cursorContextChange'**, which indicates listening for cursor context changes.|
| callback | number | No  | Callback used to return the cursor information.                                          |


  **Example**

```js
KeyboardDelegate.off('cursorContextChange', (x, y, height) => {
    console.log('delete cursorContextChange notification.');
});
```
### on('selectionChange')

on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

Listens for text selection changes. This API uses a callback to return the text selection information. This API requires two parameters, the first one being napi_string and the second one being napi_function. If either of these parameters is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'selectionChange'**, which indicates listening for text selection changes.|
| callback | number | Yes  | Callback used to return the text selection information.                                      |

  **Example**

```js
KeyboardDelegate.on('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
    console.log('inputMethodEngine beforeEach selectionChange oldBegin:' + oldBegin);
    console.log('inputMethodEngine beforeEach selectionChange oldEnd:' + oldEnd);
    console.log('inputMethodEngine beforeEach selectionChange newBegin:' + newBegin);
    console.log('inputMethodEngine beforeEach selectionChange newEnd:' + newEnd);
});
```

### off('selectionChange')

off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

Cancels listening for text selection changes. An exception is thrown in the following cases: (1) No parameter is passed; (2) Only one parameter is passed in, and it is not napi_string; (2) Two parameters are passed in, and the first parameter is not napi_string or the second parameter is not napi_function. If only one parameter is passed in, all listeners of the specified type will be canceled. If two parameters are passed in, the current listener of the specified type will be canceled.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'selectionChange'**, which indicates listening for text selection changes.|
| callback | number | No  | Callback used to return the text selection information.                                      |

  **Example**

```js
KeyboardDelegate.off('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {
  console.log('delete selectionChange notification.');
});
```


### on('textChange')

on(type: 'textChange', callback: (text: string) => void): void

Listens for text changes. This API uses a callback to return the current text content. This API requires two parameters, the first one being napi_string and the second one being napi_function. If either of these parameters is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'textChange'**, which indicates listening for text changes.|
| callback | string | Yes  | Callback used to return the current text content.                                      |

  **Example**

```js
KeyboardDelegate.on('textChange', (text) => {
    console.log('inputMethodEngine textChange. text:' + text);
});
```

### off('textChange')

off(type: 'textChange', callback?: (text: string) => void): void

Cancels listening for text changes. An exception is thrown in the following cases: (1) No parameter is passed; (2) Only one parameter is passed in, and it is not napi_string; (2) Two parameters are passed in, and the first parameter is not napi_string or the second parameter is not napi_function. If only one parameter is passed in, all listeners of the specified type will be canceled. If two parameters are passed in, the current listener of the specified type will be canceled.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Listening type.<br>Set it to **'textChange'**, which indicates listening for text changes.|
| callback | string | No  | Callback used to return the current text content.                                      |

  **Example**

```js
keyboardDelegate.off('textChange', (text) => {
    console.log('delete textChange notification. text:' + text);
});
```

## KeyboardController<a name="KeyboardController"></a>

In the following API examples, you must first use [inputStart](#inputStart) to obtain a **KeyboardController** instance, and then call the APIs using the obtained instance.

### hideKeyboard

hideKeyboard(callback: AsyncCallback&lt;void&gt;): void

Hides the keyboard. This API uses an asynchronous callback to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | No  | Callback used to return the result.|

**Example**


```js
KeyboardController.hideKeyboard((err) => {
    if (err === undefined) {
        console.error('hideKeyboard callback result---err: ' + err.msg);
        return;
    }
    console.log('hideKeyboard callback.');
});
```

### hideKeyboard

hideKeyboard(): Promise&lt;void&gt;

Hides the keyboard. This API uses a promise to return the result. If any parameter is passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type            | Description                     |
| ---------------- | ------------------------- |
| Promise&lt;void> | Promise that returns no value.|

**Example**

```js
async function InputMethodEngine() {
    await KeyboardController.hideKeyboard().then(() => {
        console.info('hideKeyboard promise.');
    }).catch((err) => {
        console.info('hideKeyboard promise err: ' + err.msg);
    });
}
```

## TextInputClient<a name="TextInputClient"></a>

In the following API examples, you must first use [inputStart](#inputStart) to obtain a **TextInputClient** instance, and then call the APIs using the obtained instance.

### getForward

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text before the cursor. This API uses an asynchronous callback to return the result. If the required two parameters are not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the text.|

**Example**

  ```js
  var length = 1;
  TextInputClient.getForward(length, (err, text) => {
      if (err === undefined) {
          console.error('getForward callback result---err: ' + err.msg);
          return;
      }
      console.log('getForward callback result---text: ' + text);
  });
  ```

### getForward

getForward(length:number): Promise&lt;string&gt;

Obtains the specific-length text before the cursor. This API uses a promise to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Promise used to return the text.               |

**Example**

  ```js
  async function InputMethodEngine() {
      var length = 1;
      await TextInputClient.getForward(length).then((text) => {
          console.info('getForward promise result---res: ' + text);
      }).catch((err) => {
          console.error('getForward promise err: ' + err.msg);
      });
  }
  ```

### getBackward

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text after the cursor. This API uses an asynchronous callback to return the result. If the required two parameters are not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the text.|

**Example**

  ```js
  var length = 1;
  TextInputClient.getBackward(length, (err, text) => {
      if (err === undefined) {
          console.error('getBackward callback result---err: ' + err.msg);
          return;
      }
      console.log('getBackward callback result---text: ' + text);
  });
  ```

### getBackward

getBackward(length:number): Promise&lt;string&gt;

Obtains the specific-length text after the cursor. This API uses a promise to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Promise used to return the text.               |

**Example**

  ```js
  async function InputMethodEngine() {
      var length = 1;
      await TextInputClient.getBackward(length).then((text) => {
          console.info('getBackward promise result---res: ' + text);
      }).catch((err) => {
          console.error('getBackward promise err: ' + err.msg);
      });
  }
  ```

### deleteForward

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text before the cursor. This API uses an asynchronous callback to return the result. If the required two parameters are not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result.|

**Example**

  ```js
  var length = 1;
  TextInputClient.deleteForward(length, (err, result) => {
      if (err === undefined) {
          console.error('deleteForward callback result---err: ' + err.msg);
          return;
      }
      if (result) {
          console.info('Success to deleteForward.(callback) ');
      } else {
          console.error('Failed to deleteForward.(callback) ');
      }
  });
  ```
### deleteForward

deleteForward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text before the cursor. This API uses a promise to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length.|

**Return value** 

| Type                  | Description          |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```js
async function InputMethodEngine() {
    var length = 1;
    await TextInputClient.deleteForward(length).then((result) => {
        if (result) {
            console.info('Success to deleteForward.(promise) ');
        } else {
            console.error('Failed to deleteForward.(promise) ');
        }
    }).catch((err) => {
        console.error('deleteForward promise err: ' + err.msg);
    });
}
```

### deleteBackward

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result. If the required two parameters are not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name  | Type                        | Mandatory| Description          |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | Yes  | Text length.    |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result.|

  **Example**

```js
var length = 1;
TextInputClient.deleteBackward(length, (err, result) => {
    if (err === undefined) {
        console.error('deleteBackward callback result---err: ' + err.msg);
        return;
    }
    if (result) {
        console.info('Success to deleteBackward.(callback) ');
    } else {
        console.error('Failed to deleteBackward.(callback) ');
    }
});
```

### deleteBackward

deleteBackward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result. If the required two parameters are not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise used to return the result.               |

**Example**

```js
async function InputMethodEngine() {
    var length = 1;
    await TextInputClient.deleteBackward(length).then((result) => {
        if (result) {
            console.info('Success to deleteBackward.(promise) ');
        } else {
            console.error('Failed to deleteBackward.(promise) ');
        }
    }).catch((err) => {
        console.error('deleteBackward promise err: ' + err.msg);
    });
}
```
### sendKeyFunction

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

Sets the Enter key to send the text to its target. This API uses an asynchronous callback to return the result. If the required two parameters are not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Edit box attribute.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result.|

  **Example**

```js
TextInputClient.sendKeyFunction(keyFunction, (err, result) => {
    if (err === undefined) {
        console.error('sendKeyFunction callback result---err: ' + err.msg);
        return;
    }
    if (result) {
        console.info('Success to sendKeyFunction.(callback) ');
    } else {
        console.error('Failed to sendKeyFunction.(callback) ');
    }
});
```

### sendKeyFunction

sendKeyFunction(action:number): Promise&lt;boolean&gt;

Sets the Enter key to send the text to its target. This API uses a promise to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Edit box attribute.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise used to return the result.               |

**Example**

  ```js
  async function InputMethodEngine() {
      await client.sendKeyFunction(keyFunction).then((result) => {
          if (result) {
              console.info('Success to sendKeyFunction.(promise) ');
          } else {
              console.error('Failed to sendKeyFunction.(promise) ');
          }
      }).catch((err) => {
          console.error('sendKeyFunction promise err:' + err.msg);
      });
  }
  ```

### insertText

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

Inserts text. This API uses an asynchronous callback to return the result. If the required two parameters are not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Text to insert.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result.|

**Example**

```js
TextInputClient.insertText('test', (err, result) => {
    if (err === undefined) {
        console.error('insertText callback result---err: ' + err.msg);
        return;
    }
    if (result) {
        console.info('Success to insertText.(callback) ');
    } else {
        console.error('Failed to insertText.(callback) ');
    }
});
```

### insertText

insertText(text:string): Promise&lt;boolean&gt;

Inserts text. This API uses a promise to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Text to insert.|

**Return value** 

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise used to return the result.               |

**Example**

  ```js
  async function InputMethodEngine() {
      await TextInputClient.insertText('test').then((result) => {
          if (result) {
              console.info('Success to insertText.(promise) ');
          } else {
              console.error('Failed to insertText.(promise) ');
          }
      }).catch((err) => {
          console.error('insertText promise err: ' + err.msg);
      });
  }
  ```

### getEditorAttribute

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

Obtains the attribute of the edit box. This API uses an asynchronous callback to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name                        | Type                         | Mandatory                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[EditorAttribute](#EditorAttribute)&gt; | Yes|  Attribute of the edit box.               |

**Example**

  ```js
  TextInputClient.getEditorAttribute((err, editorAttribute) => {
      if (err === undefined) {
          console.error('getEditorAttribute callback result---err: ' + err.msg);
          return;
      }
      console.log('editorAttribute.inputPattern(callback): ' + JSON.stringify(editorAttribute.inputPattern));
      console.log('editorAttribute.enterKeyType(callback): ' + JSON.stringify(editorAttribute.enterKeyType));
  });
  ```

### getEditorAttribute

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

Obtains the attribute of the edit box. This API uses a promise to return the result. If any parameter is passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#EditorAttribute)&gt; |  Promise used to return the attribute of the edit box.          |

**Example**

   ```js
   async function InputMethodEngine() {
       await TextInputClient.getEditorAttribute().then((editorAttribute) => {
           console.info('editorAttribute.inputPattern(promise): ' + JSON.stringify(editorAttribute.inputPattern));
           console.info('editorAttribute.enterKeyType(promise): ' + JSON.stringify(editorAttribute.enterKeyType));
       }).catch((err) => {
           console.error('getEditorAttribute promise err: ' + err.msg);
       });
   }
   ```

### moveCursor<sup>9+</sup>

moveCursor(direction: number, callback: AsyncCallback&lt;void&gt;): void

Moves the cursor. This API uses an asynchronous callback to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------- |
| direction | number                    | Yes  | Direction in which the cursor moves.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.    |

**Example**

```js
TextInputClient.moveCursor(inputMethodEngine.CURSOR_xxx, (err) => {
    if (err === undefined) {
        console.error('moveCursor callback result---err: ' + err.msg);
        return;
    }
});
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number): Promise&lt;void&gt;

Moves the cursor. This API uses a promise to return the result. If the required parameter is not passed in, an exception is thrown.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type  | Mandatory| Description          |
| --------- | ------ | ---- | -------------- |
| direction | number | Yes  | Direction in which the cursor moves.|

**Return value** 

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
async function InputMethodEngine() {
    await TextInputClient.moveCursor(inputMethodEngine.CURSOR_xxx).then(async (err) => {
        console.log('moveCursor success');
    }).catch((err) => {
        console.error('moveCursor success err: ' + err.msg);
    });
}
  ```

## EditorAttribute<a name="EditorAttribute"></a>

Describes the attribute of the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Type| Readable| Writable| Description              |
| ------------ | -------- | ---- | ---- | ------------------ |
| enterKeyType | number   | Yes  | No  | Function attribute of the edit box.|
| inputPattern | number   | Yes  | No  | Text attribute of the edit box.|

## KeyEvent<a name="KeyEvent"></a>

Describes the attribute of a key.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name     | Type| Readable| Writable| Description        |
| --------- | -------- | ---- | ---- | ------------ |
| keyCode   | number   | Yes  | No  | Key value.|
| keyAction | number   | Yes  | No  | Key status.|
