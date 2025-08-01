# @ohos.inputMethodEngine (Input Method Service)

The **inputMethodEngine** module is oriented to input method applications (including system and third-party input method applications). With the APIs of this module, input method applications are able to create soft keyboard windows, insert or delete characters, select text, and listen for physical keyboard events.

> **NOTE**
>
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { inputMethodEngine } from '@kit.IMEKit';
```

## Constants

Provides the constant values of function keys, edit boxes, and the cursor.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Value| Description|
| -------- | -------- | -------- | -------- |
| ENTER_KEY_TYPE_UNSPECIFIED | number | 0 | No function is specified for the key.|
| ENTER_KEY_TYPE_GO | number | 2 | Key that executes a command or navigates to a specific location.|
| ENTER_KEY_TYPE_SEARCH | number | 3 | Key that initiates a search operation.|
| ENTER_KEY_TYPE_SEND | number | 4 | Key that sends the text to its target.|
| ENTER_KEY_TYPE_NEXT | number | 5 | Key that moves the focus to the next item in a sequence.|
| ENTER_KEY_TYPE_DONE | number | 6 | Key that indicates that a task or input is complete.|
| ENTER_KEY_TYPE_PREVIOUS | number | 7 | Key that moves the focus to the previous item in a sequence.|
| ENTER_KEY_TYPE_NEWLINE<sup>12+</sup> | number | 8 | Key that inserts a new line.|
| PATTERN_NULL | number | -1 | Any type of edit box.|
| PATTERN_TEXT | number | 0 | Text edit box.|
| PATTERN_NUMBER | number | 2 | Number edit box.|
| PATTERN_PHONE | number | 3 | Phone number edit box.|
| PATTERN_DATETIME | number | 4 | Date edit box.|
| PATTERN_EMAIL | number | 5 | Email edit box.|
| PATTERN_URI | number | 6 | URI edit box.|
| PATTERN_PASSWORD | number | 7 | Password edit box.|
| PATTERN_PASSWORD_NUMBER<sup>11+</sup> | number | 8 | Numeric password edit box.|
| PATTERN_PASSWORD_SCREEN_LOCK<sup>11+</sup> | number | 9 | Screen lock password edit box.|
| PATTERN_USER_NAME<sup>20+</sup> | number | 10 | User name edit box.|
| PATTERN_NEW_PASSWORD<sup>20+</sup> | number | 11 | New password edit box.|
| PATTERN_NUMBER_DECIMAL<sup>20+</sup> | number | 12 | Edit box for numbers with decimal points.|
| PATTERN_ONE_TIME_CODE<sup>20+</sup> | number | 13 | Verification code edit box.|
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

Obtains an [InputMethodAbility](#inputmethodability) instance for the input method. This API can be called only by an input method.<br>The input method can use the obtained instance to subscribe to a soft keyboard display/hide request event, create/destroy an input method panel, and the like.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description              |
| ----------------------------------------- | ------------------ |
| [InputMethodAbility](#inputmethodability) | **InputMethodAbility** instance.|

**Example**

```ts
let InputMethodAbility = inputMethodEngine.getInputMethodAbility();
```

## inputMethodEngine.getKeyboardDelegate<sup>9+</sup>

getKeyboardDelegate(): KeyboardDelegate

Obtains a [KeyboardDelegate](#keyboarddelegate) instance for the input method.<br>The input method can use the obtained instance to subscribe to a physical keyboard event, text selection change event, and more.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                 | Description                    |
| ------------------------------------- | ------------------------ |
| [KeyboardDelegate](#keyboarddelegate) | **KeyboardDelegate** instance.|

**Example**

```ts
let KeyboardDelegate = inputMethodEngine.getKeyboardDelegate();
```

## inputMethodEngine.getInputMethodEngine<sup>(deprecated)</sup>

getInputMethodEngine(): InputMethodEngine

Obtains an [InputMethodEngine](#inputmethodengine) instance for the input method.<br>The input method can use the obtained instance to subscribe to a soft keyboard display/hide request event.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getInputMethodAbility()](#inputmethodenginegetinputmethodability9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description              |
| ----------------------------------------- | ------------------ |
| [InputMethodEngine](#inputmethodengine) | **InputMethodAbility** instance.|

**Example**

```ts
let InputMethodEngine = inputMethodEngine.getInputMethodEngine();
```

## inputMethodEngine.createKeyboardDelegate<sup>(deprecated)</sup>

createKeyboardDelegate(): KeyboardDelegate

Obtains a [KeyboardDelegate](#keyboarddelegate) instance for the input method. The input method can use the obtained instance to subscribe to a physical keyboard event, text selection change event, and more.

> **NOTE**
>
>This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getKeyboardDelegate()](#inputmethodenginegetkeyboarddelegate9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                 | Description                    |
| ------------------------------------- | ------------------------ |
| [KeyboardDelegate](#keyboarddelegate) | **KeyboardDelegate** instance.|

**Example**

```ts
let keyboardDelegate = inputMethodEngine.createKeyboardDelegate();
```

## CommandDataType<sup>12+</sup>

type CommandDataType = number | string | boolean;

Defines the private data type, which varies depending on its function.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Type   | Description                |
| ------- | -------------------- |
| string  | String. |
| number  | Number.  |
| boolean | Boolean.|

## SizeChangeCallback<sup>15+</sup>

type SizeChangeCallback = (size: window.Size, keyboardArea?: KeyboardArea) => void

Callback triggered when the size of the input method panel changes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name      | Type                                                | Mandatory| Description                            |
| ------------ | ---------------------------------------------------- | ---- | -------------------------------- |
| size         | [window.Size](../apis-arkui/arkts-apis-window-i.md#size7) | Yes  | Panel size.                  |
| keyboardArea | [KeyboardArea](#keyboardarea15)                      | No  | Size of the keyboard area.|

## InputMethodEngine

In the following API examples, you must first use [getInputMethodEngine](#inputmethodenginegetinputmethodenginedeprecated) to obtain an **InputMethodEngine** instance, and then call the APIs using the obtained instance.

### on('inputStart')

on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

Enables listening for the input method binding event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | Yes  | Event type, which is **'inputStart'**.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclientdeprecated)) => void | Yes| Callback used to return the **KeyboardController** and **TextInputClient** instances.|

**Example**

```ts
try {
  inputMethodEngine.getInputMethodEngine()
    .on('inputStart', (kbController: inputMethodEngine.KeyboardController, textClient: inputMethodEngine.TextInputClient) => {
      let keyboardController = kbController;
      let textInputClient = textClient;
  });
} catch(err) {
  console.error(`Failed to inputStart: ${JSON.stringify(err)}`);
}
```

### off('inputStart')

off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

Disables listening for the input method binding event.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | Yes  | Event type, which is **'inputStart'**.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclientdeprecated)) => void | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
try {
  inputMethodEngine.getInputMethodEngine()
    .off('inputStart', (kbController: inputMethodEngine.KeyboardController, textClient: inputMethodEngine.TextInputClient) => {
      console.info('delete inputStart notification.');
  });
} catch(err) {
  console.error(`Failed to inputStart: ${JSON.stringify(err)}`);
}
```

### on('keyboardShow'|'keyboardHide')

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

Enables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event.|
| callback | () => void   | Yes  | Callback used to return the result.                                                  |

**Example**

```ts
try {
  inputMethodEngine.getInputMethodEngine().on('keyboardShow', () => {
    console.info('inputMethodEngine keyboardShow.');
  });
  inputMethodEngine.getInputMethodEngine().on('keyboardHide', () => {
    console.info('inputMethodEngine keyboardHide.');
  });
} catch(err) {
  console.error(`Failed to InputMethodEngine: ${JSON.stringify(err)}`);
}
```

### off('keyboardShow'|'keyboardHide')

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

Disables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event.|
| callback | () => void   | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
inputMethodEngine.getInputMethodEngine().off('keyboardShow');
inputMethodEngine.getInputMethodEngine().off('keyboardHide');
```

## InputMethodAbility

In the following API examples, you must first use [getInputMethodAbility](#inputmethodenginegetinputmethodability9) to obtain an **InputMethodAbility** instance, and then call the APIs using the obtained instance.

### on('inputStart')<sup>9+</sup>

on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void

Enables listening for the input method binding event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | Yes  | Event type, which is **'inputStart'**.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), inputClient: [InputClient](#inputclient9)) => void | Yes| Callback used to return instances related to input method operations.|

**Example**

```ts
try {
  inputMethodEngine.getInputMethodAbility()
    .on('inputStart', (kbController: inputMethodEngine.KeyboardController, client: inputMethodEngine.InputClient) => {
      let keyboardController = kbController;
      let inputClient = client;
  });
} catch(err) {
    console.error(`Failed to InputMethodAbility: ${JSON.stringify(err)}`);
}
```

### off('inputStart')<sup>9+</sup>

off(type: 'inputStart', callback?: (kbController: KeyboardController, inputClient: InputClient) => void): void

Disables listening for the input method binding event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | Yes  | Event type, which is **'inputStart'**.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), inputClient: [InputClient](#inputclient9)) => void | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
inputMethodEngine.getInputMethodAbility().off('inputStart');
```

### on('inputStop')<sup>9+</sup>

on(type: 'inputStop', callback: () => void): void

Enables listening for the input method unbinding event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'inputStop'**.|
| callback | () => void   | Yes  | Callback used to return the result.                       |

**Example**

```ts
try {
  inputMethodEngine.getInputMethodAbility().on('inputStop', () => {
    console.info('inputMethodAbility inputStop');
  });
} catch(err) {
    console.error(`Failed to inputStop: ${JSON.stringify(err)}`);
}
```

### off('inputStop')<sup>9+</sup>

off(type: 'inputStop', callback: () => void): void

Disables listening for the input method stop event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'inputStop'**.|
| callback | () => void   | Yes  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.       |

**Example**

```ts
try {
  inputMethodEngine.getInputMethodAbility().off('inputStop', () => {
    console.info('inputMethodAbility delete inputStop notification.');
  });
} catch(err) {
    console.error(`Failed to inputStop: ${JSON.stringify(err)}`);
}
```

### on('setCallingWindow')<sup>9+</sup>

on(type: 'setCallingWindow', callback: (wid: number) => void): void

Enables listening for the window invocation setting event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'setCallingWindow'**.|
| callback | (wid: number) => void | Yes  | Callback used to return the window ID of the caller.                    |

**Example**

```ts
try {
  inputMethodEngine.getInputMethodAbility().on('setCallingWindow', (wid: number) => {
    console.info('inputMethodAbility setCallingWindow');
  });
} catch(err) {
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### off('setCallingWindow')<sup>9+</sup>

off(type: 'setCallingWindow', callback: (wid:number) => void): void

Disables listening for the window invocation setting event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'setCallingWindow'**.|
| callback | (wid:number) => void | Yes  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
try {
  inputMethodEngine.getInputMethodAbility().off('setCallingWindow', (wid: number) => {
    console.info('inputMethodAbility delete setCallingWindow notification.');
  });
} catch(err) {
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### on('keyboardShow'|'keyboardHide')<sup>9+</sup>

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

Enables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event.|
| callback | () => void   | Yes  | Callback used to return the result.                                                  |

**Example**

```ts
try {
  inputMethodEngine.getInputMethodAbility().on('keyboardShow', () => {
    console.info('InputMethodAbility keyboardShow.');
  });
  inputMethodEngine.getInputMethodAbility().on('keyboardHide', () => {
    console.info('InputMethodAbility keyboardHide.');
  });
} catch(err) {
    console.error(`Failed to keyboard: ${JSON.stringify(err)}`);
}
```

### off('keyboardShow'|'keyboardHide')<sup>9+</sup>

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

Disables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event.|
| callback | () => void   | No  | Callback used to return the result.|

**Example**

```ts
try {
  inputMethodEngine.getInputMethodAbility().off('keyboardShow', () => {
    console.info('InputMethodAbility delete keyboardShow notification.');
  });
  inputMethodEngine.getInputMethodAbility().off('keyboardHide', () => {
    console.info('InputMethodAbility delete keyboardHide notification.');
  });
} catch(err) {
    console.error(`Failed to keyboard: ${JSON.stringify(err)}`);
}
```

### on('setSubtype')<sup>9+</sup>

on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void

Enables listening for the input method subtype setting event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type| Mandatory | Description|
| -------- | --- | ---- | --- |
| type     | string | Yes  | Event type, which is **'setSubtype'**.|
| callback | (inputMethodSubtype: [InputMethodSubtype](js-apis-inputmethod-subtype.md)) => void | Yes  | Callback used to return the input method subtype.                        |

**Example**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';

try {
  inputMethodEngine.getInputMethodAbility().on('setSubtype', (inputMethodSubtype: InputMethodSubtype) => {
    console.info('InputMethodAbility setSubtype.');
  });
} catch(err) {
    console.error(`Failed to setSubtype: ${JSON.stringify(err)}`);
}
```

### off('setSubtype')<sup>9+</sup>

off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void

Disables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type | Mandatory| Description  |
| ------- | ----- | ---- | ---- |
| type     | string | Yes  | Event type, which is **'setSubtype'**.|
| callback | (inputMethodSubtype: [InputMethodSubtype](js-apis-inputmethod-subtype.md)) => void | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type. |

**Example**

```ts
try {
  inputMethodEngine.getInputMethodAbility().off('setSubtype', () => {
    console.info('InputMethodAbility delete setSubtype notification.');
  });
} catch(err) {
    console.error(`Failed to setSubtype: ${JSON.stringify(err)}`);
}
```

### on('securityModeChange')<sup>11+</sup>

on(type: 'securityModeChange', callback: Callback< SecurityMode>): void

Enables listening for the security mode changes of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                          |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | Yes  | Event type, which is **'securityModeChange'**.|
| callback | Callback\<[SecurityMode](#securitymode11)> | Yes  | Callback used to return the current security mode.      |

**Example**

```ts
try {
  inputMethodEngine.getInputMethodAbility().on('securityModeChange', (securityMode: inputMethodEngine.SecurityMode) => {
    console.info(`InputMethodAbility securityModeChange, security is ${securityMode}`);
  });
} catch(err) {
    console.error(`Failed to on securityModeChange: ${JSON.stringify(err)}`);
}
```

### off('securityModeChange')<sup>11+</sup>

off(type: 'securityModeChange', callback?: Callback< SecurityMode>): void

Disables listening for the security mode changes of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'securityModeChange'**.              |
| callback | Callback\<[SecurityMode](#securitymode11)> | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
let securityChangeCallback = (securityMode: inputMethodEngine.SecurityMode) => {
  console.info(`InputMethodAbility securityModeChange, security is ${securityMode}`);
};
let inputMethodAbility = inputMethodEngine.getInputMethodAbility();
inputMethodAbility.on('securityModeChange', securityChangeCallback);
try {
  inputMethodAbility.off('securityModeChange', securityChangeCallback);
} catch(err) {
  console.error(`Failed to off securityModeChange: ${JSON.stringify(err)}`);
}
```

### on('privateCommand')<sup>12+</sup>

on(type: 'privateCommand', callback: Callback<Record<string, CommandDataType>>): void;

Enables listening for the private data event of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                         | Mandatory| Description                                      |
| -------- | --------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                        | Yes  | Event type, which is **'privateCommand'**.|
| callback | Callback<Record<string, [CommandDataType](#commanddatatype12)>> | Yes  | Callback used to return the private data sent to the input method application.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 12800010 | not the preconfigured default input method. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethodEngine } from '@kit.IMEKit';

let privateCommandCallback = (record: Record<string, inputMethodEngine.CommandDataType>) => {
  for (let i = 0; i < record.length; i++) {
    console.info(`private command key: ${i}, value: ${record[i]}`);
  }
}
try {
  console.info(`regist private command `);
  inputMethodEngine.getInputMethodAbility().on('privateCommand', privateCommandCallback);
} catch (err) {
  let error = err as BusinessError;
  console.error(`regist private command error: ${error.code} ${error.message}`);
}
```

### off('privateCommand')<sup>12+</sup>

off(type: 'privateCommand', callback?: Callback<Record<string, CommandDataType>>): void

Disables listening for the private data event of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'privateCommand'**.                  |
| callback | Callback<Record<string, [CommandDataType](#commanddatatype12)>> | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 12800010 | not the preconfigured default input method. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethodEngine } from '@kit.IMEKit';

let privateCommandCallback = (record: Record<string, inputMethodEngine.CommandDataType>) => {
  for (let i = 0; i < record.length; i++) {
    console.info(`private command key: ${i}, value: ${record[i]}`);
  }
}
try {
  console.info(`regist private command `);
  inputMethodEngine.getInputMethodAbility().off('privateCommand', privateCommandCallback);
} catch (err) {
  let error = err as BusinessError;
  console.error(`regist private command error: ${error.code} ${error.message}`);
}
```

### on('callingDisplayDidChange')<sup>18+</sup>

on(type: 'callingDisplayDidChange', callback: Callback\<number>): void

Subscribes to the change of the ID of the screen where the window corresponding to the edit box is located. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                         | Mandatory| Description                                      |
| -------- | --------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                        | Yes  | Event type, which is **'callingDisplayDidChange'**.|
| callback |  Callback\<number> | Yes  | Callback used to return the screen ID of the window corresponding to the edit box.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 801 | capability not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethodEngine } from '@kit.IMEKit';

let callingDisplayDidChangeCallback = (num: number) => {
  console.info(`display id: ${num}`);
}
try {
  console.info(`regist calling display changed`);
  inputMethodEngine.getInputMethodAbility().on('callingDisplayDidChange', callingDisplayDidChangeCallback);
} catch (err) {
  let error = err as BusinessError;
  console.error(`regist calling display changed error: ${error.code} ${error.message}`);
}
```

### off('callingDisplayDidChange')<sup>18+</sup>

off(type: 'callingDisplayDidChange', callback?: Callback\<number>): void

Unsubscribes from the change of the ID of the screen where the window corresponding to the edit box is located. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'callingDisplayDidChange'**.                  |
| callback | Callback\<number>  | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethodEngine } from '@kit.IMEKit';

try {
  console.info(`unregist calling display changed `);
  inputMethodEngine.getInputMethodAbility().off('callingDisplayDidChange', (num: number) => {
    console.info('InputMethodAbility delete calling display  notification.');
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`unregist calling display changed error: ${error.code} ${error.message}`);
}
```

### on('discardTypingText')<sup>20+</sup>

on(type: 'discardTypingText', callback: Callback\<void>): void

Subscribes to the event of discarding candidate words and sends the event to the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                         | Mandatory| Description                                      |
| -------- | --------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                        | Yes  | Event type, which is **'discardTypingText'**.<br> - **'discardTypingText'**: indicates subscribing to the event of discarding candidate words and sending the event to the input method.|
| callback |  Callback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import inputMethodEngine from '@ohos.inputMethodEngine';

try {
  console.info(`discard the typing text`);
  inputMethodEngine.getInputMethodAbility().on('discardTypingText', ( ) => {
    console.info('InputMethodAbility discard the typing text.');
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`discard the typing text error: ${error.code} ${error.message}`);
}
```

### off('discardTypingText')<sup>20+</sup>

off(type: 'discardTypingText', callback?: Callback\<void>): void

Unsubscribes from the event of discarding candidate words and sends the event to the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'discardTypingText'**.<br> - **'discardTypingText'**: indicates unsubscribing from the event of discarding candidate words and sending the event to the input method.|
| callback | Callback\<void>  | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import inputMethodEngine from '@ohos.inputMethodEngine';

try {
  console.info(`discard the typing text`);
  inputMethodEngine.getInputMethodAbility().off('discardTypingText', ( ) => {
    console.info('InputMethodAbility discard the typing text.');
  });
} catch (err) {
  let error = err as BusinessError;
  console.error(`discard the typing text error: ${error.code} ${error.message}`);
}
```

### getSecurityMode<sup>11+</sup>

getSecurityMode(): SecurityMode

Obtains the current security mode of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                           | Description      |
| ------------------------------- | ---------- |
| [SecurityMode](#securitymode11) | Security mode.|

**Error codes**

| ID| Error Message                      |
| -------- | ------------------------------ |
| 12800004 | not an input method application. |

**Example**

```ts
try {
  let security = inputMethodEngine.getInputMethodAbility().getSecurityMode();
  console.error(`getSecurityMode, securityMode is : ${security}`);
} catch (err) {
  console.error(`Failed to getSecurityMode: ${JSON.stringify(err)}`);
}
```

### createPanel<sup>10+</sup>

createPanel(ctx: BaseContext, info: PanelInfo, callback: AsyncCallback\<Panel>): void

Creates an input method panel, which can be called only by input method applications. This API uses an asynchronous callback to return the result.<br>Only one [SOFT_KEYBOARD](#paneltype10) panel and one [STATUS_BAR](#paneltype10) panel can be created for a single input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current context of the input method.|
| info    | [PanelInfo](#panelinfo10)   | Yes  | Information about the input method application.|
| callback | AsyncCallback\<[Panel](#panel10)> | Yes  | Callback used to return the result. If the operation is successful, the created input method panel is returned. |

**Error codes**

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 401        | parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12800004   | not an input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}
try {
  inputMethodEngine.getInputMethodAbility()
    .createPanel(this.context, panelInfo, (err: BusinessError, panel: inputMethodEngine.Panel) => {
      if (err) {
        console.error(`Failed to createPanel: ${JSON.stringify(err)}`);
        return;
      }
      console.info('Succeed in creating panel.');
    })
} catch (err) {
  console.error(`Failed to createPanel: ${JSON.stringify(err)}`);
}
```

### createPanel<sup>10+</sup>

createPanel(ctx: BaseContext, info: PanelInfo): Promise\<Panel>

Creates an input method panel, which can be called only by input method applications. This API uses a promise to return the result.<br>Only one [SOFT_KEYBOARD](#paneltype10) panel and one [STATUS_BAR](#paneltype10) panel can be created for a single input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current context of the input method.|
| info    | [PanelInfo](#panelinfo10)   | Yes  | Information about the input method panel.|

**Return value**
| Type  | Description                                                                |
| ------- | ------------------------------------------------------------------ |
| Promise\<[Panel](#panel10)> | Promise used to return the result. If the operation is successful, the created input method panel is returned. |

**Error codes**

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 401        | parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 12800004   | not an input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}
inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo)
  .then((panel: inputMethodEngine.Panel) => {
    console.info('Succeed in creating panel.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to create panel: ${JSON.stringify(err)}`);
  })
```

### destroyPanel<sup>10+</sup>

destroyPanel(panel: Panel, callback: AsyncCallback\<void>): void

Destroys the specified input method panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| panel     | [Panel](#panel10) | Yes  | Input method panel to destroy.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}
let inputPanel: inputMethodEngine.Panel | undefined = undefined;
try {
  inputMethodEngine.getInputMethodAbility()
    .createPanel(this.context, panelInfo, (err: BusinessError, panel: inputMethodEngine.Panel) => {
      if (err) {
        console.error(`Failed to create panel: ${JSON.stringify(err)}`);
        return;
      }
      inputPanel = panel;
      console.info('Succeed in creating panel.');
    })
} catch (err) {
  console.error(`Failed to create panel: ${JSON.stringify(err)}`);
}
try {
  if (inputPanel) {
    inputMethodEngine.getInputMethodAbility().destroyPanel(inputPanel, (err: BusinessError) => {
      if (err !== undefined) {
        console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
        return;
      }
      console.info('Succeed in destroying panel.');
    })
  }
} catch (err) {
  console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
}
```

### destroyPanel<sup>10+</sup>

destroyPanel(panel: Panel): Promise\<void>

Destroys the specified input method panel. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ---------| ----------- | ---- | ------------------------ |
| panel    | [Panel](#panel10)       | Yes  | Input method panel to destroy.     |

**Return value**
| Type   | Description                                                                |
| ------- | -------------------------------------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}
let inputPanel: inputMethodEngine.Panel | undefined = undefined;
try {
  inputMethodEngine.getInputMethodAbility()
    .createPanel(this.context, panelInfo, (err: BusinessError, panel: inputMethodEngine.Panel) => {
      if (err) {
        console.error(`Failed to create panel: ${JSON.stringify(err)}`);
        return;
      }
      inputPanel = panel;
      console.info('Succeed in creating panel.');
    })
} catch (err) {
  console.error(`Failed to create panel: ${JSON.stringify(err)}`);
}

try {
  if (inputPanel) {
    inputMethodEngine.getInputMethodAbility().destroyPanel(inputPanel).then(() => {
      console.info('Succeed in destroying panel.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
    });
  }
} catch (err) {
  console.error(`Failed to destroy panel: ${JSON.stringify(err)}`);
}
```

## KeyboardDelegate

In the following API examples, you must first use [getKeyboardDelegate](#inputmethodenginegetkeyboarddelegate9) to obtain a **KeyboardDelegate** instance, and then call the APIs using the obtained instance.

### on('keyDown'|'keyUp')

on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void

Enables listening for a physical keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                 |
| -------- | ------------------------------- | ---- |-----------------------------------------------------|
| type   | string         | Yes  | Event type.<br>- The value **'keyDown'** indicates the keydown event.<br>- The value **'keyUp'** indicates the keyup event.|
| callback | (event: [KeyEvent](#keyevent)) => boolean | Yes| Callback used to return the key information. If the event is consumed by the event subscriber, **true** is returned. Otherwise, **false** is returned.  |

**Example**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().on('keyUp', (keyEvent: inputMethodEngine.KeyEvent) => {
    console.info(`inputMethodEngine keyCode.(keyDown): ${keyEvent.keyCode}`);
    console.info(`inputMethodEngine keyAction.(keyDown): ${keyEvent.keyAction}`);
    return true;
  });
  inputMethodEngine.getKeyboardDelegate().on('keyDown', (keyEvent: inputMethodEngine.KeyEvent) => {
    console.info(`inputMethodEngine keyCode.(keyDown): ${keyEvent.keyCode}`);
    console.info(`inputMethodEngine keyAction.(keyDown): ${keyEvent.keyAction}`);
    return true;
  });
} catch(err) {
    console.error(`Failed to KeyboardDelegate: ${JSON.stringify(err)}`);
}
```

### off('keyDown'|'keyUp')

off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void

Disables listening for a physical keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type    | Mandatory | Description |
| -------- | ------- | ---- | ----- |
| type     | string  | Yes  | Event type.<br>- The value **'keyDown'** indicates the keydown event.<br>- The value **'keyUp'** indicates the keyup event.|
| callback | (event: [KeyEvent](#keyevent)) => boolean | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.  |

**Example**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().off('keyUp', (keyEvent: inputMethodEngine.KeyEvent) => {
    console.info('delete keyUp notification.');
    return true;
  });
  inputMethodEngine.getKeyboardDelegate().off('keyDown', (keyEvent: inputMethodEngine.KeyEvent) => {
    console.info('delete keyDown notification.');
    return true;
  });
} catch(err) {
    console.error(`Failed to keyevent: ${JSON.stringify(err)}`);
}
```

### on('keyEvent')<sup>10+</sup>

on(type: 'keyEvent', callback: (event: InputKeyEvent) => boolean): void

Enables listening for a keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'keyEvent'**.|
| callback | (event: [InputKeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent)) => boolean | Yes  | Callback used to return the result. The input parameter is the key event information and the return value is of the Boolean type.<br>- Input parameter: [InputKeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent).<br>- If the event is consumed by the event subscriber, **true** is returned. Otherwise, **false** is returned.|

**Example**

```ts
import type { KeyEvent } from '@kit.InputKit';

try {
  inputMethodEngine.getKeyboardDelegate().on('keyEvent', (keyEvent: KeyEvent) => {
    console.info('inputMethodEngine keyEvent.action:' + JSON.stringify(keyEvent.action));
    console.info('inputMethodEngine keyEvent.key.code:' + JSON.stringify(keyEvent.key.code));
    console.info(`inputMethodEngine keyEvent.ctrlKey: ${keyEvent.ctrlKey}`);
    console.info(`inputMethodEngine keyEvent.unicodeChar: ${keyEvent.unicodeChar}`);
    return true;
  });
} catch(err) {
    console.error(`Failed to inputMethodEngine: ${JSON.stringify(err)}`);
}
```

### off('keyEvent')<sup>10+</sup>

off(type: 'keyEvent', callback?: (event: InputKeyEvent) => boolean): void

Disables listening for a keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'keyEvent'**.|
| callback | function | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
import type { KeyEvent } from '@kit.InputKit';

try {
  inputMethodEngine.getKeyboardDelegate().off('keyEvent', (keyEvent: KeyEvent) => {
    console.info('This is a callback function which will be deregistered.');
    return true;
  });
  inputMethodEngine.getKeyboardDelegate().off('keyEvent');
} catch(err) {
    console.error(`Failed to keyEvent: ${JSON.stringify(err)}`);
}
```

### on('cursorContextChange')

on(type: 'cursorContextChange', callback: (x: number, y:number, height:number) => void): void

Enables listening for the cursor change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type | Mandatory | Description |
| -------- | ---- | ---- | ----- |
| type     | string | Yes  | Event type, which is **'cursorContextChange'**.|
| callback | (x: number, y: number, height: number) => void | Yes  | Callback used to return the cursor information.<br>- **x**: x coordinate of the top of the cursor.<br>- **y**: y coordinate of the bottom of the cursor.<br>- **height**: height of the cursor.|

**Example**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().on('cursorContextChange', (x: number, y: number, height: number) => {
    console.info('inputMethodEngine cursorContextChange x:' + x);
    console.info('inputMethodEngine cursorContextChange y:' + y);
    console.info('inputMethodEngine cursorContextChange height:' + height);
  });
} catch(err) {
    console.error(`Failed to cursorContextChange: ${JSON.stringify(err)}`);
}
```

### off('cursorContextChange')

off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void

Disables listening for cursor context changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name   | Type | Mandatory | Description  |
| -------- | ---- | ---- | ------ |
| type     | string  | Yes  | Event type, which is **'cursorContextChange'**.|
| callback | (x: number, y:number, height:number) => void | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|


  **Example**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().off('cursorContextChange', (x: number, y: number, height: number) => {
    console.info('delete cursorContextChange notification.');
  });
} catch(err) {
    console.error(`Failed to cursorContextChange: ${JSON.stringify(err)}`);
}
```
### on('selectionChange')

on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

Enables listening for the text selection change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type  | Mandatory| Description  |
| -------- | ----- | ---- | ---- |
| type     | string  | Yes  | Event type, which is **'selectionChange'**.|
| callback | (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void | Yes  | Callback used to return the text selection information.<br>- **oldBegin**: start of the selected text before the change.<br>- **oldEnd**: end of the selected text before the change.<br>- **newBegin**: start of the selected text after the change.<br>- **newEnd**: end of the selected text after the change.|

**Example**

```ts
try {
  inputMethodEngine.getKeyboardDelegate()
    .on('selectionChange', (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => {
      console.info('inputMethodEngine beforeEach selectionChange oldBegin:' + oldBegin);
      console.info('inputMethodEngine beforeEach selectionChange oldEnd:' + oldEnd);
      console.info('inputMethodEngine beforeEach selectionChange newBegin:' + newBegin);
      console.info('inputMethodEngine beforeEach selectionChange newEnd:' + newEnd);
    });
} catch(err) {
    console.error(`Failed to selectionChange: ${JSON.stringify(err)}`);
}
```

### off('selectionChange')

off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

Disables listening for the text selection change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type | Mandatory| Description    |
| -------- | ------- | ---- | ------- |
| type     | string  | Yes  | Event type, which is **'selectionChange'**.|
| callback | (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
try {
  inputMethodEngine.getKeyboardDelegate()
    .off('selectionChange', (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number)  => {
      console.info('delete selectionChange notification.');
    });
} catch(err) {
    console.error(`Failed to selectionChange: ${JSON.stringify(err)}`);
}
```


### on('textChange')

on(type: 'textChange', callback: (text: string) => void): void

Enables listening for the text change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'textChange'**.|
| callback | (text: string) => void | Yes  | Callback used to return the text content.|

**Example**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().on('textChange', (text: string) => {
    console.info('inputMethodEngine textChange. text:' + text);
  });
} catch(err) {
    console.error(`Failed to textChange: ${JSON.stringify(err)}`);
}
```

### off('textChange')

off(type: 'textChange', callback?: (text: string) => void): void

Disables listening for the text change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'textChange'**.|
| callback | (text: string) => void | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().off('textChange', (text: string) => {
    console.info('delete textChange notification. text:' + text);
  });
} catch(err) {
    console.error(`Failed to textChange: ${JSON.stringify(err)}`);
}
```

### on('editorAttributeChanged')<sup>10+</sup>

on(type: 'editorAttributeChanged', callback: (attr: EditorAttribute) => void): void

Enables listening for the edit box attribute change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'editorAttributeChanged'**.|
| callback | (attr: [EditorAttribute](#editorattribute)) => void | Yes  | Callback used to return the changed edit box attribute.|

**Example**

```ts
try {
  inputMethodEngine.getKeyboardDelegate().on('editorAttributeChanged', (attr: inputMethodEngine.EditorAttribute) => {
    console.info(`Succeeded in receiving attribute of editor, inputPattern = ${attr.inputPattern}, enterKeyType = ${attr.enterKeyType}`);
  });
} catch(err) {
    console.error(`Failed to textChange: ${JSON.stringify(err)}`);
}
```

### off('editorAttributeChanged')<sup>10+</sup>

off(type: 'editorAttributeChanged', callback?: (attr: EditorAttribute) => void): void

Disables listening for the edit box attribute change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'editorAttributeChanged'**.|
| callback | (attr: [EditorAttribute](#editorattribute)) => void | No  | Callback used for unsubscription. If this parameter is not specified, this API unregisters all callbacks for the specified type by default.|

**Example**

```ts
inputMethodEngine.getKeyboardDelegate().off('editorAttributeChanged');
```

## Panel<sup>10+</sup>

In the following API examples, you must first use [createPanel](#createpanel10) to obtain a **Panel** instance, and then call the APIs using the obtained instance.

### setUiContent<sup>10+</sup>

setUiContent(path: string, callback: AsyncCallback\<void>): void

Loads content from a page to this input method panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  | Path of the page from which the content will be loaded.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.setUiContent('pages/page2/page2', (err: BusinessError) => {
    if (err) {
      console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in setting the content.');
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### setUiContent<sup>10+</sup>

setUiContent(path: string): Promise\<void>

Loads content from a page to this input method panel. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  |  Path of the page from which the content will be loaded.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.setUiContent('pages/page2/page2').then(() => {
    console.info('Succeeded in setting the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### setUiContent<sup>10+</sup>

setUiContent(path: string, storage: LocalStorage, callback: AsyncCallback\<void>): void

Loads content from a page linked to LocalStorage to this input method panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  | Path of the page linked to LocalStorage.|
| storage | [LocalStorage](../apis-arkui/arkui-ts/ts-state-management.md#localstorage9) | Yes  | Storage unit that provides storage for mutable and immutable state variables in the application.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storage = new LocalStorage();
storage.setOrCreate('storageSimpleProp',121);
try {
  panel.setUiContent('pages/page2/page2', storage, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in setting the content.');
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
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
| storage | [LocalStorage](../apis-arkui/arkui-ts/ts-state-management.md#localstorage9) | Yes  | Storage unit that provides storage for mutable and immutable state variables in the application.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storage = new LocalStorage();
storage.setOrCreate('storageSimpleProp',121);
try {
  panel.setUiContent('pages/page2/page2', storage).then(() => {
    console.info('Succeeded in setting the content.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to setUiContent: ${JSON.stringify(err)}`);
}
```

### resize<sup>10+</sup>

resize(width: number, height: number, callback: AsyncCallback\<void>): void

Resizes this input method panel. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The panel width cannot exceed the screen width, and the panel height cannot be 0.7 times higher than the screen height.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| width | number | Yes  | Target width of the panel, in px.|
| height | number | Yes  | Target height of the panel, in px.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.resize(500, 1000, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to resize panel: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in changing the panel size.');
  });
} catch (err) {
  console.error(`Failed to resize panel: ${JSON.stringify(err)}`);
}
```

### resize<sup>10+</sup>

resize(width: number, height: number): Promise\<void>

Resizes this input method panel. This API uses a promise to return the result.

> **NOTE**
>
> The panel width cannot exceed the screen width, and the panel height cannot be 0.7 times higher than the screen height.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| width | number | Yes  | Target width of the panel, in px.|
| height | number | Yes  | Target height of the panel, in px.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.resize(500, 1000).then(() => {
    console.info('Succeeded in changing the panel size.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to resize panel: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to resize panel: ${JSON.stringify(err)}`);
}
```

### moveTo<sup>10+</sup>

moveTo(x: number, y: number, callback: AsyncCallback\<void>): void

Moves this input method panel to the specified position. This API uses an asynchronous callback to return the result. This API does not work on panels in the [FLG_FIXED](#panelflag10) state.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| x | number | Yes  | Distance to move along the x-axis, in px. A positive value indicates moving rightwards.|
| y | number | Yes  | Distance to move along the y-axis, in px. A positive value indicates moving downwards.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.moveTo(300, 300, (err: BusinessError) =>{
    if (err) {
      console.error(`Failed to move panel: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in moving the panel.');
  });
} catch (err) {
    console.error(`Failed to move panel: ${JSON.stringify(err)}`);
}
```

### moveTo<sup>10+</sup>

moveTo(x: number, y: number): Promise\<void>

Moves this input method panel to the specified position. This API uses a promise to return the result. This API does not work on panels in the [FLG_FIXED](#panelflag10) state.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| x | number | Yes  |Distance to move along the x-axis, in px. A positive value indicates moving rightwards.|
| y | number | Yes  |Distance to move along the y-axis, in px. A positive value indicates moving downwards.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.moveTo(300, 300).then(() => {
    console.info('Succeeded in moving the panel.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to move panel: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to move panel: ${JSON.stringify(err)}`);
}
```

### startMoving<sup>15+</sup>

startMoving(): void

Sends a command to start moving the window. The window can be moved only when the mouse is clicked.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 801 | capability not supported. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800013 | window manager service error. |
| 12800017 | invalid panel type or panel flag. |

**Example**

```ts

try {
  panel.startMoving();
  console.info('Succeeded in moving the panel.');
} catch (err) {
  console.error(`Failed to move panel: ${JSON.stringify(err)}`);
}
```

### getDisplayId<sup>15+</sup>

getDisplayId(): Promise\<number>

Obtains the window ID. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
|Promise\<number>| Promise used to return the result. Returns the **displayId** of the window. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800013 | window manager service error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  panel.getDisplayId().then((result: number) => {
    console.info('get displayId:' + result);
  }).catch((err: BusinessError) => {
    console.error(`Failed to get displayId: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to get displayId: ${JSON.stringify(err)}`);
}
```

### show<sup>10+</sup>

show(callback: AsyncCallback\<void>): void

Shows this input method panel. This API uses an asynchronous callback to return the result. It can be called when the input method is bound to the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.show((err: BusinessError) => {
  if (err) {
    console.error(`Failed to show panel: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in showing the panel.');
});
```

### show<sup>10+</sup>

show(): Promise\<void>

Shows this input method panel. This API uses a promise to return the result. It can be called when the input method is bound to the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.show().then(() => {
  console.info('Succeeded in showing the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show panel: ${JSON.stringify(err)}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.hide((err: BusinessError) => {
  if (err) {
    console.error(`Failed to hide panel: ${JSON.stringify(err)}`);
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.hide().then(() => {
  console.info('Succeeded in hiding the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide panel: ${JSON.stringify(err)}`);
});
```

### adjustPanelRect<sup>12+</sup>

adjustPanelRect(flag: PanelFlag, rect: PanelRect): void

Adjusts the panel rectangle. After the API is called, the adjust request is submitted to the input method framework, but the execution is not complete.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| flag | [PanelFlag](#panelflag10) | Yes| Type of the state of the target panel. It can be **FLG_FIXED** or **FLG_FLOATING**.|
| rect | [PanelRect](#panelrect12) | Yes  | Landscape rectangle and portrait rectangle of the target panel. For the panel of the fixed state, the height cannot exceed 70% of the screen height, and the width cannot exceed the screen width. For the panel of the floating state, the height cannot exceed the screen height, and the width cannot exceed the screen width.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800013 | window manager service error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let panelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
  let panelRect:inputMethodEngine.PanelRect = {
    landscapeRect:{left:100, top:100, width:400, height:400},
    portraitRect:{left:200, top:200, width:300, height:300}
  };
  panel.adjustPanelRect(panelFlag, panelRect);
} catch(err) {
  console.error(`Failed to adjustPanelRect: ${JSON.stringify(err)}`);
}
```

### adjustPanelRect<sup>15+</sup>

adjustPanelRect(flag: PanelFlag, rect: EnhancedPanelRect): void

Adjusts the panel rectangle, and customizes the avoid area and touch area.

> **NOTE**
>
> This API applies only to the panels of the **SOFT_KEYBOARD** type in the **FLG_FIXED** or **FLG_FLOATING** state. This API is compatible with [adjustPanelRect](#adjustpanelrect12). If the input parameter **rect** contains only the **landscapeRect** and **portraitRect** attributes, [adjustPanelRect](#adjustpanelrect12) is called by default.
>
> This API returns the result synchronously. The return only indicates that the system receives the setting request, not that the setting is complete.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type                                     | Mandatory| Description                                                      |
| ------ | ----------------------------------------- | ---- | ---------------------------------------------------------- |
| flag   | [PanelFlag](#panelflag10)                 | Yes  | Type of the state of the target panel. It can be **FLG_FIXED** or **FLG_FLOATING**.         |
| rect   | [EnhancedPanelRect](#enhancedpanelrect15) | Yes  | The target panel rectangle, avoid area, and touch area.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 12800013 | window manager service error.                                |
| 12800017 | invalid panel type or panel flag.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let panelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
  let panelRect:inputMethodEngine.EnhancedPanelRect = {
    landscapeAvoidY: 650,
    landscapeInputRegion: [{left:300, top:650, width:2000, height:500}],
    portraitAvoidY: 1800,
    portraitInputRegion: [{left:0, top:1800, width:1200, height:800}],
    fullScreenMode: true
  };
  panel.adjustPanelRect(panelFlag, panelRect);
} catch(err) {
  console.error(`Failed to adjustPanelRect: ${JSON.stringify(err)}`);
}
```

### updatelnputRegion<sup>15+</sup>

updateRegion(inputRegion: Array&lt;window.Rect&gt;): void

Updates the hot zone on the input method panel in the current state.

> **NOTE**
>
> This API applies only to the panels of the **SOFT_KEYBOARD** type in the **FLG_FIXED** or **FLG_FLOATING** state.
>
> This API returns the result synchronously. The return only indicates that the system has received the request for updating the hot zone, not that the hot zone has been updated.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| inputRegion | Array&lt;[window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)&gt; | Yes  | Region for receiving input events.<br>- The array size is limited to [1, 4].<br>- The input hot zone is relative to the left vertex of the input method panel window.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 12800013 | window manager service error.                                |
| 12800017 | invalid panel type or panel flag.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

try {
  let inputRegion: Array<window.Rect> = [{left:300, top:650, width:2000, height:500}];
  panel.updateRegion(inputRegion);
} catch(err) {
  console.error(`Failed to updateRegion: ${JSON.stringify(err)}`);
}
```

### on('show')<sup>10+</sup>

on(type: 'show', callback: () => void): void

Enables listening for the show event of this panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| type | string | Yes| Event type, which is **'show'**.|
| callback | () => void | Yes  | Callback used to return the result.|

**Example**

```ts
try {
  panel.on('show', () => {
    console.info('Panel is showing.');
  });
} catch(err) {
    console.error(`Failed to show: ${JSON.stringify(err)}`);
}
```

### on('hide')<sup>10+</sup>

on(type: 'hide', callback: () => void): void

Enables listening for the hide event of this panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| type | string | Yes| Event type, which is **'hide'**.|
| callback | () => void | Yes  | Callback used to return the result.|

**Example**

```ts
try {
  panel.on('hide', () => {
    console.info('Panel is hiding.');
  });
} catch(err) {
    console.error(`Failed to hide: ${JSON.stringify(err)}`);
}
```

### on('sizeChange')<sup>12+</sup>

on(type: 'sizeChange', callback: SizeChangeCallback): void

Enables listening for the panel size change. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API applies only to the panels of the **SOFT_KEYBOARD** type in the **FLG_FIXED** or **FLG_FLOATING** state. When you call **adjustPanelRect** to adjust the panel size, the system calculates the final value based on certain rules (for example, whether the panel size exceeds the screen). This callback can be used to obtain the actual panel size to refresh the panel layout.
>
>-  This API is supported from API version 12 to 14. The callback function of this API contains only mandatory parameters of the [window.Size](../apis-arkui/arkts-apis-window-i.md#size7) type.
>-  Since API version 15, after the [adjustPanelRect](#adjustpanelrect15) API is called, an optional parameter of the [KeyboardArea](#keyboardarea15) type is added to the callback function of this API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                  |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'sizeChange'**.|
| callback | [SizeChangeCallback](#sizechangecallback15) | Yes  | Callback used to return the size of the soft keyboard panel, including the width and height.|

**Example**

```ts
import { window } from '@kit.ArkUI';
try {
  panel.on('sizeChange', (windowSize: window.Size) => {
    console.info(`panel size changed, width: ${windowSize.width}, height: ${windowSize.height}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sizeChange: ${JSON.stringify(err)}`);
}
try {
  panel.on('sizeChange', (windowSize: window.Size, keyboardArea: inputMethodEngine.KeyboardArea) => {
    console.info(`panel size changed, windowSize: ${JSON.stringify(windowSize)}, keyboardArea: ${JSON.stringify(keyboardArea)}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sizeChange: ${JSON.stringify(err)}`);
}
```

### off('show')<sup>10+</sup>

off(type: 'show', callback?: () => void): void

Disables listening for the show event of this panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| type | string | Yes| Event type, which is **'show'**.|
| callback | () => void | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
try {
  panel.off('show');
} catch(err) {
    console.error(`Failed to show: ${JSON.stringify(err)}`);
}
```

### off('hide')<sup>10+</sup>

off(type: 'hide', callback?: () => void): void

Disables listening for the hide event of this panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| type | string | Yes| Event type, which is **'hide'**.|
| callback | () => void | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
try {
  panel.off('hide');
} catch(err) {
    console.error(`Failed to hide: ${JSON.stringify(err)}`);
}
```

### off('sizeChange')<sup>12+</sup>

off(type: 'sizeChange', callback?: SizeChangeCallback): void

Disables listening for the panel size change. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API applies only to the panels of the **SOFT_KEYBOARD** type in the **FLG_FIXED** or **FLG_FLOATING** state. When you call **adjustPanelRect** to adjust the panel size, the system calculates the final value based on certain rules (for example, whether the panel size exceeds the screen). This callback can be used to obtain the actual panel size to refresh the panel layout.
>
>-  This API is supported from API version 12 to 14. The callback function of this API contains only mandatory parameters of the [window.Size](../apis-arkui/arkts-apis-window-i.md#size7) type.
>-  Since API version 15, after the [adjustPanelRect](#adjustpanelrect15) API is called, an optional parameter of the [KeyboardArea](#keyboardarea15) type is added to the callback function of this API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                    |
| -------- | ------------------------------------------- | ---- | -------------------------------------------------------- |
| type     | string                                      | Yes  | Event type, which is **'sizeChange'**.|
| callback | [SizeChangeCallback](#sizechangecallback15) | No  | Callback used to return the size of the soft keyboard panel, including the width and height.  |

**Example**

```ts
import { window } from '@kit.ArkUI';
try {
  panel.off('sizeChange', (windowSize: window.Size) => {
    console.info(`panel size changed, width: ${windowSize.width}, height: ${windowSize.height}`);
  });
} catch(err) {
    console.error(`Failed to subscribe sizeChange: ${JSON.stringify(err)}`);
}
```

### changeFlag<sup>10+</sup>

changeFlag(flag: PanelFlag): void

Changes the state type of this input method panel. This API only works for [SOFT_KEYBOARD](#paneltype10) panels.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| flag | [PanelFlag](#panelflag10) | Yes| Type of the state of the target panel.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
try {
  let panelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
  panel.changeFlag(panelFlag);
} catch(err) {
    console.error(`Failed to panelFlag: ${JSON.stringify(err)}`);
}
```

### setPrivacyMode<sup>11+</sup>

setPrivacyMode(isPrivacyMode: boolean): void

Sets the input method panel to privacy mode. In privacy mode, screenshot and screen recording are blocked.

**Required permissions**: ohos.permission.PRIVACY_WINDOW

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name       | Type   | Mandatory| Description              |
| ------------- | ------- | ---- | ------------------ |
| isPrivacyMode | boolean | Yes  | Whether to set the input method panel to privacy mode.<br>- **true**: privacy mode.<br>- **false**: non-privacy mode.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 201      | permissions check fails.  |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
try {
    let isPrivacyMode = true;
    panel.setPrivacyMode(isPrivacyMode);
} catch(err) {
    console.error(`Failed to set privacy mode: ${JSON.stringify(err)}`);
}
```

### setImmersiveMode<sup>15+</sup>

setImmersiveMode(mode: ImmersiveMode): void

Sets the immersive mode of the input method application. You can only set the immersion mode to **NONE_IMMERSIVE**, **LIGHT_IMMERSIVE**, or **DARK_IMMERSIVE**. **IMMERSIVE** cannot be set.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| mode | [ImmersiveMode](#immersivemode15) | Yes  | Immersive mode.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.           |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800013  | window manager service error.                          |

**Example**

```ts
try {
  panel.setImmersiveMode(inputMethodEngine.ImmersiveMode.LIGHT_IMMERSIVE);
} catch (err) {
  console.error(`Failed to setImmersiveMode: ${JSON.stringify(err)}`);
}
```

### getImmersiveMode<sup>15+</sup>

getImmersiveMode(): ImmersiveMode

Obtains the immersive mode of the input method application.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                           | Description      |
| ------------------------------- | ---------- |
| [ImmersiveMode](#immersivemode15) | Immersive mode.|

**Example**

```ts
try {
  let mode = panel.getImmersiveMode();
} catch (err) {
  console.error(`Failed to getImmersiveMode: ${JSON.stringify(err)}`);
}
```

### setImmersiveEffect<sup>20+</sup>

setImmersiveEffect(effect: ImmersiveEffect): void

Sets the immersive effect of the input method application.
- Gradient mode and fluid light mode can be used only when the [immersive mode](#setimmersivemode15) is enabled.
- The fluid light mode can be used only when the gradient mode is enabled.
- If the gradient mode is disabled, the gradient height must be 0 px.
- Only system applications can set the fluid light mode.
- The current API can be called only after any of the following APIs is called:
  - [adjustPanelRect](#adjustpanelrect12) (available since API version 12)
  - [adjustPanelRect](#adjustpanelrect15) (available since API version 15)
  - [resize](#resize10) (available since API version 10)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| effect | [ImmersiveEffect](#immersiveeffect20) | Yes  | Immersive effect.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 801  |capability not supported.                          |
| 12800002   |input method engine error. Possible causes:1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800013   |window manager service error.                          |
| 12800020   |invalid immersive effect. 1.The gradient mode and the fluid light mode can only be used when the immersive mode is enabled. 2.The fluid light mode can only be used when the gradient mode is enabled. 3.When the gradient mode is not enabled, the gradient height can only be 0. |
| 12800021   |this operation is allowed only after adjustPanelRect or resize is called. |

**Example**

```ts
try {
  let effect : inputMethodEngine.ImmersiveEffect = {
    gradientHeight: 100,
    gradientMode: inputMethodEngine.GradientMode.LINEAR_GRADIENT
  }
  panel.setImmersiveMode(effect);
} catch (err) {
  console.error(`Failed to setImmersiveMode: code:${err.code}, message:${err.message}`);
}
```

### setKeepScreenOn<sup>20+</sup>

setKeepScreenOn(isKeepScreenOn: boolean): Promise\<void>

Sets to keep the screen always on. This API uses a promise to return the result.

> **NOTE**
>
> - When the keyboard is displayed, the screen stays on. When the keyboard is hidden, the screen turns off.
> - You need to use this API properly. Set the attribute to **true** in necessary scenarios (for example, voice input) and reset this attribute to **false** after exiting necessary scenarios. In other scenarios, do not use this API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| isKeepScreenOn | boolean | Yes  | Whether to keep the screen always on. The value **true** means that the screen is always on; the value **false** means the opposite.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 12800013 | window manager service error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isKeepScreenOn = true;
  this.panel.setKeepScreenOn(isKeepScreenOn).then(() => {
    console.info(`setKeepScreenOn success.`);
  }).catch((error: BusinessError) => {
    console.error(`setKeepScreenOn failed, code: ${error.code}, message: ${error.message}`);
  })
} catch (err) {
  let error = err as BusinessError;
  console.error(`setKeepScreenOn failed, code: ${error.code}, message: ${error.message}`);
}
```

## KeyboardController

In the following API examples, you must first use [on('inputStart')](#oninputstart9) to obtain a **KeyboardController** instance, and then call the APIs using the obtained instance.

### hide<sup>9+</sup>

hide(callback: AsyncCallback&lt;void&gt;): void

Hides the keyboard. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.hide((err: BusinessError) => {
  if (err) {
    console.error(`Failed to hide. Code:${err.code}, message:${err.message}`);
    return;
  }
  console.info('Succeeded in hiding keyboard.');
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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.hide().then(() => {
  console.info('Succeeded in hiding keyboard.');
}).catch((err: BusinessError) => {
  let error = err as BusinessError;
  console.error(`Failed to hide. Code:${error.code}, message:${error.message}`);
});
```

### hideKeyboard<sup>(deprecated)</sup>

hideKeyboard(callback: AsyncCallback&lt;void&gt;): void

Hides the keyboard. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [hide](#hide9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.hideKeyboard((err: BusinessError) => {
  if (err) {
    console.error(`Failed to hideKeyboard: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in hiding keyboard.');
});
```

### hideKeyboard<sup>(deprecated)</sup>

hideKeyboard(): Promise&lt;void&gt;

Hides the keyboard. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [hide](#hide9-1) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type            | Description                     |
| ---------------- | ------------------------- |
| Promise&lt;void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.hideKeyboard().then(() => {
  console.info('Succeeded in hiding keyboard.');
}).catch((err: BusinessError) => {
  console.info(`Failed to hideKeyboard: ${JSON.stringify(err)}`);
});
```

### exitCurrentInputType<sup>11+</sup>

exitCurrentInputType(callback: AsyncCallback&lt;void&gt;): void

Exits this input type. This API can be called only by the preconfigured default input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800010 | not the preconfigured default input method. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.exitCurrentInputType((err: BusinessError) => {
  if (err) {
    console.error(`Failed to exit current input type. Code:${err.code}, message:${err.message}`);
    return;
  }
  console.info('Succeeded in exiting current input type.');
});
```

### exitCurrentInputType<sup>11+</sup>

exitCurrentInputType(): Promise&lt;void&gt;

Exits this input type. This API can be called only by the preconfigured default input method. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type            | Description                     |
| ---------------- | ------------------------- |
| Promise&lt;void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800010 | not the preconfigured default input method. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.exitCurrentInputType().then(() => {
  console.info('Succeeded in exiting current input type.');
}).catch((err: BusinessError) => {
  let error = err as BusinessError;
  console.error(`Failed to exit current input type. Code:${error.code}, message:${error.message}`);
});
```

## SecurityMode<sup>11+</sup>

Describes the security mode.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name | Value  | Description                                        |
| ----- | ---- | -------------------------------------------- |
| BASIC | 0    | Basic access mode, where network access is restricted.|
| FULL  | 1    | Full access mode, where network access is not restricted.      |

## ExtendAction<sup>10+</sup>

Describes the type of the extended edit action on the text box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value|Description|
| -------- | -------- |-------- |
| SELECT_ALL  | 0 |Select all.|
| CUT  | 3 |Cut.|
| COPY  | 4 |Copy.|
| PASTE  | 5 |Paste.|

## Direction<sup>10+</sup>

Enumerates the directions of cursor movement of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value|Description|
| -------- | -------- |-------- |
| CURSOR_UP  | 1 |Upward.|
| CURSOR_DOWN  | 2 |Downward.|
| CURSOR_LEFT  | 3 |Leftward.|
| CURSOR_RIGHT  | 4 |Rightward.|

## Range<sup>10+</sup>

Describes the range of the selected text.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| start  | number | No| No| Index of the first selected character in the text box.|
| end  | number | No| No| Index of the last selected character in the text box.|

## Movement<sup>10+</sup>

Describes the direction in which the cursor moves when the text is selected.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| direction  | [Direction](#direction10) | No| No| Direction in which the cursor moves when the text is selected.|

## MessageHandler<sup>15+</sup>

Represents a custom communication object.

> **NOTE**
>
> You can register this object to receive custom communication data sent by the edit box application attached to the input method application. When the custom communication data is received, the [onMessage](#onmessage15) callback in this object is triggered.
>
> This object is globally unique. After multiple registrations, only the last registered object is valid and retained, and the [onTerminated](#onterminated15) callback of the penultimate registered object is triggered.
>
> If this object is unregistered, its [onTerminated](#onterminated15) callback will be triggered.

### onMessage<sup>15+</sup>

onMessage(msgId: string, msgParam?: ArrayBuffer): void

Receives the custom data callback sent by the edit box application attached to the input method application.

> **NOTE**
>
> This callback is triggered when the registered [MessageHandler](#messagehandler15) receives custom communication data sent by the edit box application attached to the input method application.
>
> The **msgId** parameter is mandatory, and the **msgParam** parameter is optional. If only the custom **msgId** data is received, confirm it with the data sender.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                            |
| -------- | ----------- | ---- | -------------------------------- |
| msgId    | string      | Yes  | Identifier of the received custom communication data.|
| msgParam | ArrayBuffer | No  | Message body of the received custom communication data.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodEngine.getInputMethodAbility()
    .on('inputStart', (kbController: inputMethodEngine.KeyboardController, client: inputMethodEngine.InputClient) => {
      let keyboardController = kbController;
      let inputClient = client;
      try {
        let messageHandler: inputMethodEngine.MessageHandler = {
          onTerminated(): void {
            console.info('OnTerminated.');
          },
          onMessage(msgId: string, msgParam?:ArrayBuffer): void {
            console.info('recv message.');
          }
        }
        inputClient.recvMessage(messageHandler);
      } catch(err) {
        console.error(`Failed to recvMessage: ${JSON.stringify(err)}`);
      }
  });
} catch(err) {
    console.error(`Failed to InputMethodAbility: ${JSON.stringify(err)}`);
}
```

### onTerminated<sup>15+</sup>

onTerminated(): void

Listens for MessageHandler termination.

> **NOTE**
>
> When an application registers a new [MessageHandler](#messagehandler15) object, the [onTerminated](#onterminated15) callback of the penultimate registered [MessageHandler](#messagehandler15) object is triggered.
>
> When an application unregisters a new [MessageHandler](#messagehandler15) object, the [onTerminated](#onterminated15) callback of the registered [MessageHandler](#messagehandler15) object is triggered.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodEngine.getInputMethodAbility()
    .on('inputStart', (kbController: inputMethodEngine.KeyboardController, client: inputMethodEngine.InputClient) => {
      let keyboardController = kbController;
      let inputClient = client;
      try {
        let messageHandler: inputMethodEngine.MessageHandler = {
          onTerminated(): void {
            console.info('OnTerminated.');
          },
          onMessage(msgId: string, msgParam?:ArrayBuffer): void {
            console.info('recv message.');
          }
        }
        inputClient.recvMessage(messageHandler);
      } catch(err) {
        console.error(`Failed to recvMessage: ${JSON.stringify(err)}`);
      }
  });
} catch(err) {
    console.error(`Failed to InputMethodAbility: ${JSON.stringify(err)}`);
}
```

## InputClient<sup>9+</sup>

In the following API examples, you must first use [on('inputStart')](#oninputstart9) to obtain an **InputClient** instance, and then call the APIs using the obtained instance.

### sendKeyFunction<sup>9+</sup>

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

Sends the function key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

  **Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Action of the function key.<br>- **0**: invalid key.<br>- **1**: confirm key (Enter key).|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

 **Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action = 1;
try {
  inputClient.sendKeyFunction(action, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in sending key function.');
    } else {
      console.error('Failed to sendKeyFunction.');
    }
  });
} catch (err) {
  console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action = 1;
try {
  inputClient.sendKeyFunction(action).then((result: boolean) => {
    if (result) {
      console.info('Succeeded in sending key function.');
    } else {
      console.error('Failed to sendKeyFunction.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
}
```

### getForward<sup>9+</sup>

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text before the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained text. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                    |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.getForward(length, (err: BusinessError, text: string) => {
    if (err) {
      console.error(`Failed to getForward: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in getting forward, text: ' + text);
  });
} catch (err) {
  console.error(`Failed to getForward: ${JSON.stringify(err)}`);
}
```

### getForward<sup>9+</sup>

getForward(length:number): Promise&lt;string&gt;

Obtains the specific-length text before the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt;           |  Promise used to return the specific-length text before the cursor.                    |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                    |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.getForward(length).then((text: string) => {
    console.info('Succeeded in getting forward, text: ' + text);
  }).catch((err: BusinessError) => {
    console.error(`Failed to getForward: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to getForward: ${JSON.stringify(err)}`);
}
```

### getForwardSync<sup>10+</sup>

getForwardSync(length:number): string

Obtains the specific-length text before the cursor.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length, which cannot be less than 0.|

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| string | Specific-length text before the cursor.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
let length = 1;
try {
  let text: string = inputClient.getForwardSync(length);
  console.info(`Succeeded in getting forward, text: ${text}`);
} catch (err) {
  console.error(`Failed to getForwardSync: ${JSON.stringify(err)}`);
}
```

### getBackward<sup>9+</sup>

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text after the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained text. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                    |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.getBackward(length, (err: BusinessError, text: string) => {
    if (err) {
      console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in getting backward, text: ' + text);
  });
} catch (err) {
  console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
}
```

### getBackward<sup>9+</sup>

getBackward(length:number): Promise&lt;string&gt;

Obtains the specific-length text after the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt;           |  Promise used to return the specific-length text after the cursor.                    |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                    |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.getBackward(length).then((text: string) => {
    console.info('Succeeded in getting backward, text: ' + text);
  }).catch((err: BusinessError) => {
    console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
}
```

### getBackwardSync<sup>10+</sup>

getBackwardSync(length:number): string

Obtains the specific-length text after the cursor.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length, which cannot be less than 0.|

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| string | Specific-length text after the cursor.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
let length = 1;
try {
  let text: string = inputClient.getBackwardSync(length);
  console.info(`Succeeded in getting backward, text: ${text}`);
} catch (err) {
  console.error(`Failed to getBackwardSync: ${JSON.stringify(err)}`);
}
```

### deleteForward<sup>9+</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text before the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.deleteForward(length, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in deleting forward.');
    } else {
      console.error(`Failed to deleteForward.`);
    }
  });
} catch (err) {
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
}
```

### deleteForward<sup>9+</sup>

deleteForward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text before the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length, which cannot be less than 0.|

**Return value** 

| Type                  | Description          |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the deletion is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.deleteForward(length).then((result: boolean) => {
    if (result) {
      console.info('Succeeded in deleting forward.');
    } else {
      console.error('Failed to delete Forward.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
}
```

### deleteForwardSync<sup>10+</sup>

deleteForwardSync(length:number): void

Deletes the fixed-length text before the cursor.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length, which cannot be less than 0.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
let length = 1;
try {
  inputClient.deleteForwardSync(length);
  console.info('Succeeded in deleting forward.');
} catch (err) {
  console.error('deleteForwardSync err: ' + JSON.stringify(err));
}
```

### deleteBackward<sup>9+</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                        | Mandatory| Description          |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | Yes  | Text length, which cannot be less than 0.    |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
try {
  inputClient.deleteBackward(length, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in deleting backward.');
    } else {
      console.error(`Failed to deleteBackward.`);
    }
  });
} catch (err) {
  console.error('deleteBackward err: ' + JSON.stringify(err));
}
```

### deleteBackward<sup>9+</sup>

deleteBackward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text after the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.   |

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise used to return the result. The value **true** means that the deletion is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
inputClient.deleteBackward(length).then((result: boolean) => {
  if (result) {
    console.info('Succeeded in deleting backward.');
  } else {
    console.error('Failed to deleteBackward.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
});
```

### deleteBackwardSync<sup>10+</sup>

deleteBackwardSync(length:number): void

Deletes the fixed-length text after the cursor.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length, which cannot be less than 0. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
let length = 1;
try {
  inputClient.deleteBackwardSync(length);
  console.info('Succeeded in deleting backward.');
} catch (err) {
  console.error('deleteBackwardSync err: ' + JSON.stringify(err));
}
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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.insertText('test', (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to insertText: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.info('Succeeded in inserting text.');
  } else {
    console.error('Failed to insertText.');
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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.insertText('test').then((result: boolean) => {
    if (result) {
      console.info('Succeeded in inserting text.');
    } else {
      console.error('Failed to insertText.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to insertText: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to insertText: ${JSON.stringify(err)}`);
}
```

### insertTextSync<sup>10+</sup>

insertTextSync(text: string): void

Inserts text.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| text   | string | Yes  | Text to insert.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
try {
  inputClient.insertTextSync('test');
  console.info('Succeeded in inserting text.');
} catch (err) {
  console.error(`Failed to insertTextSync: ${JSON.stringify(err)}`);
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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getEditorAttribute((err: BusinessError, editorAttribute: inputMethodEngine.EditorAttribute) => {
  if (err) {
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
    return;
  }
  console.info(`editorAttribute.inputPattern:  ${editorAttribute.inputPattern}`);
  console.info(`editorAttribute.enterKeyType:  ${editorAttribute.enterKeyType}`);
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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.getEditorAttribute().then((editorAttribute: inputMethodEngine.EditorAttribute) => {
    console.info(`editorAttribute.inputPattern:  ${editorAttribute.inputPattern}`);
    console.info(`editorAttribute.enterKeyType:  ${editorAttribute.enterKeyType}`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
  });
} catch(err) {
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
}
```

### getEditorAttributeSync<sup>10+</sup>

getEditorAttributeSync(): EditorAttribute

Obtains the attribute of the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                               | Description          |
| ----------------------------------- | -------------- |
| [EditorAttribute](#editorattribute) | Attribute information.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
try {
  let editorAttribute: inputMethodEngine.EditorAttribute = inputClient.getEditorAttributeSync();
    console.info(`editorAttribute.inputPattern:  ${editorAttribute.inputPattern}`);
    console.info(`editorAttribute.enterKeyType:  ${editorAttribute.enterKeyType}`);
} catch (err) {
  console.error(`Failed to getEditorAttributeSync: ${JSON.stringify(err)}`);
}
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number, callback: AsyncCallback&lt;void&gt;): void

Moves the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------- |
| direction | number                    | Yes  | Direction in which the cursor moves.<br>- **1**: upward.<br>- **2**: downward.<br>- **3**: leftward.<br>- **4**: rightward. which cannot be less than 0.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.   |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.moveCursor(inputMethodEngine.Direction.CURSOR_UP, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in moving cursor.');
  });
} catch (err) {
  console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);
}
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number): Promise&lt;void&gt;

Moves the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type  | Mandatory| Description                                                        |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| direction | number | Yes  | Direction in which the cursor moves.<br>- **1**: upward.<br>- **2**: downward.<br>- **3**: leftward.<br>- **4**: rightward. which cannot be less than 0.|

**Return value** 

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.moveCursor(inputMethodEngine.Direction.CURSOR_UP).then(() => {
    console.info('Succeeded in moving cursor.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to moveCursor: ${JSON.stringify(err)}`);
}
```

### moveCursorSync<sup>10+</sup>

moveCursorSync(direction: number): void

Moves the cursor.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type  | Mandatory| Description                                                        |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| direction | number | Yes  | Direction in which the cursor moves.<br>- **1**: upward.<br>- **2**: downward.<br>- **3**: leftward.<br>- **4**: rightward. which cannot be less than 0.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
try {
  inputClient.moveCursorSync(inputMethodEngine.Direction.CURSOR_UP);
  console.info('Succeeded in moving cursor.');
} catch (err) {
  console.error(`Failed to moveCursorSync: ${JSON.stringify(err)}`);
}
```

### selectByRange<sup>10+</sup>

selectByRange(range: Range, callback: AsyncCallback&lt;void&gt;): void

Selects text based on the specified range. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| range    | [Range](#range10) | Yes  | Range of the selected text.                                            |
| callback | AsyncCallback&lt;void&gt;                                 | Yes  | Callback used to return the result. If the selection event is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let range: inputMethodEngine.Range = { start: 0, end: 1 };
  inputClient.selectByRange(range, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in selecting by range.');
  });
} catch (err) {
  console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);
}
```

### selectByRange<sup>10+</sup>

selectByRange(range: Range): Promise&lt;void&gt;

Selects text based on the specified range. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type                                                     | Mandatory| Description            |
| ------ | --------------------------------------------------------- | ---- | ---------------- |
| range  | [Range](#range10) | Yes  | Range of the selected text.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let range: inputMethodEngine.Range = { start: 0, end: 1 };
  inputClient.selectByRange(range).then(() => {
    console.info('Succeeded in selecting by range.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to selectByRange: ${JSON.stringify(err)}`);
}
```

### selectByRangeSync<sup>10+</sup>

selectByRangeSync(range: Range): void

Selects text based on the specified range.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type             | Mandatory| Description            |
| ------ | ----------------- | ---- | ---------------- |
| range  | [Range](#range10) | Yes  | Range of the selected text.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
try {
  let range: inputMethodEngine.Range = { start: 0, end: 1 };
  inputClient.selectByRangeSync(range);
  console.info('Succeeded in selecting by range.');
} catch (err) {
  console.error(`Failed to selectByRangeSync: ${JSON.stringify(err)}`);
}
```

### selectByMovement<sup>10+</sup>

selectByMovement(movement: Movement, callback: AsyncCallback&lt;void&gt;): void

Selects text based on the cursor movement direction. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type | Mandatory| Description  |
| -------- | ------ | ---- | ------ |
| movement | [Movement](#movement10)   | Yes  | Direction in which the cursor moves when the text is selected. |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the selection event is sent, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let movement: inputMethodEngine.Movement = { direction: 1 };
  inputClient.selectByMovement(movement, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in selecting by movement.');
  });
} catch (err) {
  console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
}
```

### selectByMovement<sup>10+</sup>

selectByMovement(movement: Movement): Promise&lt;void&gt;

Selects text based on the specified range. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| movement | [Movement](#movement10) | Yes  | Direction in which the cursor moves when the text is selected.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let movement: inputMethodEngine.Movement = { direction: 1 };
  inputClient.selectByMovement(movement).then(() => {
    console.info('Succeeded in selecting by movement.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
  });
} catch (err) {
  console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
}
```

### selectByMovementSync<sup>10+</sup>

selectByMovementSync(movement: Movement): void

Selects text based on the cursor movement direction.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                   | Mandatory| Description                  |
| -------- | ----------------------- | ---- | ---------------------- |
| movement | [Movement](#movement10) | Yes  | Direction in which the cursor moves when the text is selected.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |

**Example**

```ts
try {
  let movement: inputMethodEngine.Movement = { direction: 1 };  
  inputClient.selectByMovementSync(movement);
  console.info('Succeeded in selecting by movement.');
} catch (err) {
  console.error(`Failed to selectByMovement: ${JSON.stringify(err)}`);
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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getTextIndexAtCursor((err: BusinessError, index: number) => {
  if (err) {
    console.error(`Failed to getTextIndexAtCursor: ${JSON.stringify(err)}`);
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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getTextIndexAtCursor().then((index: number) => {
  console.info('Succeeded in getTextIndexAtCursor: ' + index);
}).catch((err: BusinessError) => {
  console.error(`Failed to getTextIndexAtCursor: ${JSON.stringify(err)}`);
});
```

### getTextIndexAtCursorSync<sup>10+</sup>

getTextIndexAtCursorSync(): number

Obtains the index of the text where the cursor is located.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | Index of the text where the cursor is located.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
try{
  let index: number = inputClient.getTextIndexAtCursorSync();
  console.info(`Succeeded in getTextIndexAtCursorSync, index: ${index}`);
} catch (err) {
  console.error(`Failed to getTextIndexAtCursorSync: ${JSON.stringify(err)}`);
}
```

### sendExtendAction<sup>10+</sup>

sendExtendAction(action: ExtendAction, callback: AsyncCallback&lt;void&gt;): void

Sends an extended edit action. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The input method calls this API to send an extended edit action to an edit box, which in turn listens for the corresponding event [on('handleExtendAction')](./js-apis-inputmethod.md#onhandleextendaction10) for further processing.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| action | [ExtendAction](#extendaction10) | Yes  | Extended edit action to send.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.sendExtendAction(inputMethodEngine.ExtendAction.COPY, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in sending extend action.');
  });
} catch(err) {
  console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);
}
```

### sendExtendAction<sup>10+</sup>

sendExtendAction(action: ExtendAction): Promise&lt;void&gt;

Sends an extended edit action. This API uses a promise to return the result.

>**NOTE**
>
> The input method calls this API to send an extended edit action to an edit box, which in turn listens for the corresponding event [on('handleExtendAction')](./js-apis-inputmethod.md#onhandleextendaction10) for further processing.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | [ExtendAction](#extendaction10) | Yes| Extended edit action to send.|

**Return value**

| Type                 | Description                                   |
| --------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.sendExtendAction(inputMethodEngine.ExtendAction.COPY).then(() => {
    console.info('Succeeded in sending extend action.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);
  });
} catch(err) {
  console.error(`Failed to sendExtendAction: ${JSON.stringify(err)}`);
}
```

### sendPrivateCommand<sup>12+</sup>

sendPrivateCommand(commandData: Record&lt;string, CommandDataType&gt;): Promise&lt;void&gt;

Sends private data to the system component that needs to communicate with the input method application.

>**NOTE**
>
> - The private data channel allows communication between the system preset input method application and specific system components (such as a text box or a home screen application). It is usually used to implement custom input on a specific device.
> - The total size of the private data is 32 KB, and the maximum number of private data records is 5.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name     | Type                           | Mandatory| Description      |
| ----------- | ------------------------------- | ---- | ---------- |
| commandData | Record<string, [CommandDataType](#commanddatatype12)> | Yes  | Private data to send.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800010 | not the preconfigured default input method. |

**Example**

```ts
import { inputMethodEngine } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodEngine.getInputMethodAbility().on('inputStart', (kbController, textInputClient) => {
  try {
    let record: Record<string, inputMethodEngine.CommandDataType> = {
      "valueString1": "abcdefg",
      "valueString2": true,
      "valueString3": 500,
    }
    textInputClient.sendPrivateCommand(record).then(() => {
    }).catch((err: BusinessError) => {
      if (err !== undefined) {
        let error = err as BusinessError;
        console.error(`sendPrivateCommand catch error: ${error.code} ${error.message}`);
      }
    });
  } catch (err) {
    let error = err as BusinessError;
    console.error(`sendPrivateCommand catch error: ${error.code} ${error.message}`);
  }
})
```

### getCallingWindowInfo<sup>12+</sup>

getCallingWindowInfo(): Promise&lt;WindowInfo&gt;

Obtains information about the application window, in which the input box that starts an input method is located. This API uses a promise to return the result.

>**NOTE**
>
>This API applies only to the input method applications that use [Panel](#panel10) as the soft keyboard window.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                      | Description                                                 |
| ------------------------------------------ | ----------------------------------------------------- |
| Promise&lt;[WindowInfo](#windowinfo12)&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                         |
| -------- | --------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800012 | the input method panel does not exist. |
| 12800013 | window manager service error.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.getCallingWindowInfo().then((windowInfo: inputMethodEngine.WindowInfo) => {
    console.info(`windowInfo.rect: ${JSON.stringify(windowInfo.rect)}`);
    console.info('windowInfo.status: ' + JSON.stringify(windowInfo.status));
  }).catch((err: BusinessError) => {
    console.error(`Failed to getCallingWindowInfo: ${JSON.stringify(err)}`);
  });
} catch(err) {
    console.error(`Failed to getCallingWindowInfo: ${JSON.stringify(err)}`);
}
```

### setPreviewText<sup>12+</sup>

setPreviewText(text: string, range: Range): Promise&lt;void&gt;

Sets the preview text. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type             | Mandatory| Description                                                        |
| ------ | ----------------- | ---- | ------------------------------------------------------------ |
| text   | string            | Yes  | Preview text to set.                                          |
| range  | [Range](#range10) | Yes  | Range of the preview text.<br>- If the value is { start: -1, end: -1 }, **text** replaces the entire text in the current preview area by default.<br>- If **start** is equal to **end**, **text** is inserted into the cursor position specified by **start**.<br>- If **start** is not equal to **end**, **text** replaces the text of the specified range.<br>- If the values of **start** and **end** are negative values, a parameter error is returned.<br>- If there is preview text in the text box, the value of **range** cannot exceed the range of the preview text. Otherwise, a parameter error is returned.<br>- If there is no preview text in the text box, the value of **range** cannot exceed the text range of the text box. Otherwise, a parameter error is returned.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800011 | text preview not supported.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let range: inputMethodEngine.Range = { start: 0, end: 1 };
  inputClient.setPreviewText('test', range).then(() => {
    console.info('Succeeded in setting preview text.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setPreviewText: ${JSON.stringify(err)}`);
  });
} catch(err) {
    console.error(`Failed to setPreviewText: ${JSON.stringify(err)}`);
}
```

### setPreviewTextSync<sup>12+</sup>

setPreviewTextSync(text: string, range: Range): void

Sets the preview text.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type             | Mandatory| Description                                                        |
| ------ | ----------------- | ---- | ------------------------------------------------------------ |
| text   | string            | Yes  | Preview text to set.                                          |
| range  | [Range](#range10) | Yes  | Range of the preview text.<br>- If the value is { start: -1, end: -1 }, **text** replaces the entire text in the current preview area by default.<br>- If **start** is equal to **end**, **text** is inserted into the cursor position specified by **start**.<br>- If **start** is not equal to **end**, **text** replaces the text of the specified range.<br>- If the values of **start** and **end** are negative values, a parameter error is returned.<br>- If there is preview text in the text box, the value of **range** cannot exceed the range of the preview text. Otherwise, a parameter error is returned.<br>- If there is no preview text in the text box, the value of **range** cannot exceed the text range of the text box. Otherwise, a parameter error is returned.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800011 | text preview not supported.                               |

**Example**

```ts
try {
  let range: inputMethodEngine.Range = { start: 0, end: 1 };
  inputClient.setPreviewTextSync('test', range);
  console.info('Succeeded in setting preview text with synchronized method.');
} catch (err) {
  console.error(`Failed to setPreviewTextSync: ${JSON.stringify(err)}`);
}
```

### finishTextPreview<sup>12+</sup>

finishTextPreview(): Promise&lt;void&gt;

Finishes the text preview. This API uses a promise to return the result.

>**NOTE**
>
>If there is preview text in the current text box, calling this API will display the preview text on the screen.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800011 | text preview not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputClient.finishTextPreview().then(() => {
    console.info('Succeeded in finishing text preview.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to finishTextPreview: ${JSON.stringify(err)}`);
  });
} catch(err) {
    console.error(`Failed to finishTextPreview: ${JSON.stringify(err)}`);
}
```

### finishTextPreviewSync<sup>12+</sup>

finishTextPreviewSync(): void

Finishes the text preview.

>**NOTE**
>
>If there is preview text in the current text box, calling this API will display the preview text on the screen.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800011 | text preview not supported. |

**Example**

```ts
try {
  inputClient.finishTextPreviewSync();
  console.info('Succeeded in finishing text preview with synchronized method.');
} catch (err) {
  console.error(`Failed to finishTextPreviewSync: ${JSON.stringify(err)}`);
}
```

### sendMessage<sup>15+</sup>

sendMessage(msgId: string, msgParam?: ArrayBuffer): Promise<void&gt;

Sends the custom communication to the edit box application attached to the input method application. This API uses a promise to return the result.

> **NOTE**
>
> This API can be called only when the edit box is attached to the input method and enter the edit mode, and the input method application is in full experience mode.
>
> The maximum length of **msgId** is 256 B, and the maximum length of **msgParam** is 128 KB.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                                                        |
| -------- | ----------- | ---- | ------------------------------------------------------------ |
| msgId    | string      | Yes  | Identifier of the custom data to be sent to the edit box application attached to the input method application.|
| msgParam | ArrayBuffer | No  | Message body of the custom data to be sent to the edit box application attached to the input method application.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Incorrect parameter types. 2. Incorrect parameter length.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800009 | input method client detached.               |
| 12800014 | the input method is in basic mode.          |
| 12800015 | the other side does not accept the request. |
| 12800016 | input method client is not editable.        |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let msgId: string = "testMsgId";
let msgParam: ArrayBuffer = new ArrayBuffer(128);
inputClient.sendMessage(msgId, msgParam).then(() => {
  console.info('Succeeded send message.');
}).catch((err: BusinessError) => {
  console.error(`Failed to send message: ${JSON.stringify(err)}`);
});
```

### recvMessage<sup>15+</sup>

recvMessage(msgHandler?: MessageHandler): void;

Registers or unregisters MessageHandler.

> **NOTE**
>
> The [MessageHandler](#messagehandler15) object is globally unique. After multiple registrations, only the last registered object is valid and retained, and the [onTerminated](#onterminated15) callback of the penultimate registered object is triggered.
>
> If no parameter is set, unregister [MessageHandler](#messagehandler15). Its [onTerminated](#onterminated15) callback will be triggered.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name    | Type                               | Mandatory| Description                                                        |
| ---------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| msgHandler | [MessageHandler](#messagehandler15) | No  | This object receives custom communication data from the edit box application attached to the input method application through [onMessage](#onmessage15) and receives a message for terminating the subscription to this object through [onTerminated](#onterminated15).<br>If no parameter is set, unregister [MessageHandler](#messagehandler15). Its [onTerminated](#onterminated15) callback will be triggered.|

**Return value**

| Type| Description        |
| ---- | ------------ |
| void | No value is returned.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message        |
| -------- | ---------------- |
| 401      | parameter error. Possible causes: 1. Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodEngine.getInputMethodAbility()
    .on('inputStart', (kbController: inputMethodEngine.KeyboardController, client: inputMethodEngine.InputClient) => {
      let keyboardController = kbController;
      let inputClient = client;
      try {
        let messageHandler: inputMethodEngine.MessageHandler = {
          onTerminated(): void {
            console.info('OnTerminated.');
          },
          onMessage(msgId: string, msgParam?:ArrayBuffer): void {
            console.info('recv message.');
          }
        }
        inputClient.recvMessage(messageHandler);
      } catch(err) {
        console.error(`Failed to recvMessage: ${JSON.stringify(err)}`);
      }
  });
} catch(err) {
    console.error(`Failed to InputMethodAbility: ${JSON.stringify(err)}`);
}
```

### getAttachOptions<sup>19+</sup>

getAttachOptions(): AttachOptions

Obtains the additional options for binding an input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description        |
| ---- | ------------ |
| [AttachOptions](#attachoptions19) | Additional options for binding an input method.|

> **NOTE**
>
> Error code `801 Capability not supported.` is removed since API version 20.

**Example**

```ts
try {
  let attachOptions = inputClient.getAttachOptions();
  console.info(`Succeeded in getting AttachOptions, AttachOptions is ${attachOptions}`);
} catch (err) {
  console.error(`Failed to get AttachOptions: ${JSON.stringify(err)}`);
}
```

### on('attachOptionsDidChange')<sup>19+</sup>

on(type: 'attachOptionsDidChange', callback: Callback\<AttachOptions>): void

Subscribes to the event indicating that the additional options for binding an input method are changed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                          |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | Yes  | Additional option change event when the input method is bound. The value is fixed to **'attachOptionsDidChange'**.|
| callback | Callback\<[AttachOptions](#attachoptions19)> | Yes  | Callback used to return the additional options for binding an input method.      |

> **NOTE**
>
> Error code `801 Capability not supported.` is removed since API version 20.

**Example**

```ts
let attachOptionsDidChangeCallback = (attachOptions: inputMethodEngine.AttachOptions) => {
  console.info(`AttachOptionsDidChangeCallback1: attachOptionsDidChange event triggered`);
};

try {
  inputClient.on('attachOptionsDidChange', attachOptionsDidChangeCallback);
  console.info(`attachOptionsDidChangeCallback subscribed to attachOptionsDidChange`);
  inputClient.off('attachOptionsDidChange', attachOptionsDidChangeCallback);
  console.info(`attachOptionsDidChange unsubscribed from attachOptionsDidChange`);
} catch(err) {
  console.error(`Failed to operate on attachOptionsDidChange (subscribe/off): ${JSON.stringify(err)}`);
}
```

### off('attachOptionsDidChange')<sup>19+</sup>

off(type: 'attachOptionsDidChange', callback?: Callback\<AttachOptions>): void

Unsubscribes from the event indicating that additional options for binding an input method are changed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes  | Additional option change event when the input method is bound. The value is fixed to **'attachOptionsDidChange'**.              |
| callback | Callback\<[AttachOptions](#attachoptions19)> | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type by default.|

**Example**

```ts
let attachOptionsDidChangeCallback = (attachOptions: inputMethodEngine.AttachOptions) => {
  console.info(`AttachOptionsDidChangeCallback1: attachOptionsDidChange event triggered`);
};

try {
  inputClient.on('attachOptionsDidChange', attachOptionsDidChangeCallback);
  console.info(`attachOptionsDidChangeCallback subscribed to attachOptionsDidChange`);
  inputClient.off('attachOptionsDidChange', attachOptionsDidChangeCallback);
  console.info(`attachOptionsDidChange unsubscribed from attachOptionsDidChange`);
} catch(err) {
  console.error(`Failed to operate on attachOptionsDidChange (subscribe/off): ${JSON.stringify(err)}`);
}
```

### CapitalizeMode<sup>20+</sup>

Enumerates the modes of capitalizing the first letter of a text.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value| Description|
| -------- | -- | -------- |
| NONE | 0 | The first letter is not capitalized.|
| SENTENCES | 1 | The first letter of each sentence is capitalized.|
| WORDS | 2 | The first letter of each word is capitalized.|
| CHARACTERS | 3 | All letters are capitalized.|

### EditorAttribute

Represents the attributes of the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Type| Read-Only| Optional| Description              |
| ------------ | -------- | ---- | ---- | ------------------ |
| enterKeyType | number   | Yes  | No  | Function attributes of the edit box. For details, see [function key definitions in constants](#constants).|
| inputPattern | number   | Yes  | No  | Text attribute of the edit box. For details, see [edit box definitions in constants](#constants).|
| isTextPreviewSupported<sup>12+</sup> | boolean | No| No| Whether text preview is supported.<br>- **true**: Supported.<br>- **false**: Unsupported.|
| bundleName<sup>14+</sup> | string | Yes| Yes| Name of the application package to which the edit box belongs. The value may be **""** When this attribute is used, the scenario where the value is **""** must be considered.|
| immersiveMode<sup>15+</sup> | [ImmersiveMode](#immersivemode15) | Yes  | Yes  | Immersive mode of the input method.|
| windowId<sup>18+</sup> | number | Yes| Yes| ID of the window where the edit box is located.|
| displayId<sup>18+</sup> | number | Yes  | Yes  | Screen ID of the window corresponding to the edit box. If window ID is not set, the screen ID of the focused window is used.|
| placeholder<sup>20+</sup> | string | Yes| Yes| Placeholder information set for the edit box.|
| abilityName<sup>20+</sup> | string | Yes| Yes| Ability name set for the edit box.|
| capitalizeMode<sup>20+</sup> | [CapitalizeMode](#capitalizemode20) | Yes| Yes| Whether to capitalize the first letter in the edit box. If it is not set or is set to an invalid value, the first letter is not capitalized by default.|
| gradientMode<sup>20+</sup> | [GradientMode](#gradientmode20) | Yes| Yes| Gradient mode. If this attribute is not specified or is set to an invalid value, the gradient mode is not used by default.|

## KeyEvent

Represents the attributes of a key.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name     | Type| Read-Only| Optional| Description        |
| --------- | -------- | ---- | ---- | ------------ |
| keyCode   | number   | Yes  | No  | Key value. For details, see [KeyCode](../apis-input-kit/js-apis-keycode.md#keycode).|
| keyAction | number   | Yes  | No  | Key event type.<br>- **2**: keydown event.<br>- **3**: keyup event.|

## PanelFlag<sup>10+</sup>

Enumerates the state types of the input method panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Value| Description              |
| ------------ | -- | ------------------ |
| FLG_FIXED  | 0 | Fixed state type.|
| FLG_FLOATING | 1 | Floating state type.|
| FLAG_CANDIDATE<sup>15+</sup> | 2 | Candidate state type.|

## PanelType<sup>10+</sup>

Enumerates the types of the input method panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Value| Description              |
| ------------ | -- | ------------------ |
| SOFT_KEYBOARD | 0 | Soft keyboard type.|
| STATUS_BAR   | 1 | Status bar type.|

## PanelInfo<sup>10+</sup>

Describes the attributes of the input method panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name     | Type| Read-Only| Optional| Description        |
| --------- | -------- | ---- | ---- | ------------ |
| type   	| [PanelType](#paneltype10)   | No  | No  | Type of the panel.|
| flag	    | [PanelFlag](#panelflag10)   | No  | Yes  | State type of the panel.|

## PanelRect<sup>12+</sup>

Represents the size of the input method panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Type| Read-Only| Optional| Description              |
| ------------ | -------- | ---- | ---- | ------------------ |
| landscapeRect | [window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)   | No  | No  | Size of the input method panel window in landscape mode.|
| portraitRect | [window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)   | No  | No  | Size of the input method panel window in portrait mode.|

## EnhancedPanelRect<sup>15+</sup>

Indicates the size of the enhanced input method panel, including the custom avoid area and touch area.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name                | Type                                                        | Read-Only| Optional| Description                                                        |
| -------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| landscapeRect        | [window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)         | No  | Yes  | Size of the input method panel window in landscape mode.<br>- This attribute is mandatory when **fullScreenMode** is not set or is set to **false**.|
| portraitRect         | [window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)         | No  | Yes  | Size of the input method panel window in portrait mode.<br>- This attribute is mandatory when **fullScreenMode** is not set or is set to **false**.|
| landscapeAvoidY      | number                                                       | No  | Yes  | Distance between the avoid line and the top of the panel in landscape mode. The default value is **0**.<br>- Other system components in the application avoid the input method panel area below the avoid line.<br>- When the panel is fixed, the distance between the avoid line and the bottom of the screen cannot exceed 70% of the screen height.|
| landscapeInputRegion | Array&lt;[window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)&gt; | No  | Yes  | Region where the panel receives input events in landscape mode.<br>- The array size is limited to [1, 4]. The default value is the panel size in landscape mode.<br>- The input hot zone is relative to the left vertex of the input method panel window.|
| portraitAvoidY       | number                                                       | No  | Yes  | Distance between the avoid line and the top of the panel in portrait mode. The default value is **0**.<br>- Other system components in the application avoid the input method panel area below the avoid line.<br>- When the panel is fixed, the distance between the avoid line and the bottom of the screen cannot exceed 70% of the screen height.|
| portraitInputRegion  | Array&lt;[window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)&gt; | No  | Yes  | Region where the panel receives input events in portrait mode.<br>- The array size is limited to [1, 4]. The default value is the panel size in portrait mode.<br>- The input hot zone is relative to the left vertex of the input method panel window.|
| fullScreenMode       | boolean                                                      | No  | Yes  | Indicates whether to enable the full-screen mode. The default value is **false**.<br>- If the value is **true**, **landscapeRect** and **portraitRect** are optional.<br>- If the value is **false**, **landscapeRect** and **portraitRect** are mandatory.|

## KeyboardArea<sup>15+</sup>

Represents the keyboard area on the panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name  | Type  | Read-Only| Optional| Description                                                        |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| top    | number | Yes  | No  | Distance between the upper boundary of the keyboard area and the upper boundary of the panel area, in pixels. The value is an integer.|
| bottom | number | Yes  | No  | Distance between the lower boundary of the keyboard area and the lower boundary of the panel area, in pixels. The value is an integer.|
| left   | number | Yes  | No  | Distance between the left boundary of the keyboard area and the left boundary of the panel area, in pixels. The value is an integer.|
| right  | number | Yes  | No  | Distance between the right border of the keyboard area and the right border of the panel area, in pixels. The value is an integer.|

## AttachOptions<sup>19+</sup>

Defines additional options for binding an input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name  | Type  | Read-Only| Optional| Description                                                        |
| ------ | ------ | ---- | ---- | ---------------------------------------------------------- |
| requestKeyboardReason    | [RequestKeyboardReason](#requestkeyboardreason19) | No  | Yes  | Reason for requesting the keyboard. This attribute is set by the edit box application. If this attribute is not set or is set to an invalid value, the keyboard will not be triggered by default.|
| isSimpleKeyboardEnabled<sup>20+</sup>    | boolean | No  | Yes  | Whether to enable the simple keyboard. This attribute is set by the edit box application. The value **true** means that the simple keyboard is enabled, and the value **false** means the opposite.<br> If this attribute is not set or is set to an invalid value, the simple keyboard is disabled by default.|

## WindowInfo<sup>12+</sup>

Represents window information.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name  | Type                                                        | Read-Only| Optional| Description          |
| ------ | ------------------------------------------------------------ | ---- | ---- | -------------- |
| rect   | [window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)         | No  | No  | Rectangular area of the window.|
| status | [window.WindowStatusType](../apis-arkui/arkts-apis-window-e.md#windowstatustype11) | No  | No  | Window status type.|

## ImmersiveMode<sup>15+</sup>

Enumerates the immersive modes of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Value| Description              |
| ------------ | -- | ------------------ |
| NONE_IMMERSIVE | 0 | The immersive mode is not used.|
| IMMERSIVE      | 1 | The immersive mode is used. Its style is determined by the input method application.|
| LIGHT_IMMERSIVE  | 2 | Immersive style in light mode.|
| DARK_IMMERSIVE   | 3 | Immersive style in dark mode.|

## RequestKeyboardReason<sup>19+</sup>

Enumerates the reasons for requesting keyboard input.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Value| Description              |
| ------------ | -- | ------------------ |
| NONE  | 0 | The keyboard request is triggered for no reason.|
| MOUSE | 1 | The keyboard request is triggered by a mouse operation.|
| TOUCH | 2 | The keyboard request is triggered by a touch operation.|
| OTHER | 20 | The keyboard request is triggered by other reasons.|

## GradientMode<sup>20+</sup>

Enumerates the gradient modes of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Value| Description              |
| ------------ | -- | ------------------ |
| NONE | 0 | The gradient mode is not used.|
| LINEAR_GRADIENT | 1 | Linear gradient.|

## ImmersiveEffect<sup>20+</sup>

Describes the immersive effect.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name  | Type                                 | Read-Only| Optional| Description          |
| ------ | ------------------------------------ | ---- | ---- | -------------- |
| gradientHeight   | number                      | No  | No  | Gradient height, which cannot exceed 15% of the screen height.|
| gradientMode | [GradientMode](#gradientmode20) | No  | No  | Gradient mode.|

## TextInputClient<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [InputClient](#inputclient9) instead.

In the following API examples, you must first use [on('inputStart')](#oninputstart) to obtain a **TextInputClient** instance, and then call the APIs using the obtained instance.

### getForward<sup>(deprecated)</sup>

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text before the cursor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getForward](#getforward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained text. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.getForward(length, (err: BusinessError, text: string) => {
  if (err) {
    console.error(`Failed to getForward: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in getting forward, text: ' + text);
});
```

### getForward<sup>(deprecated)</sup>

getForward(length:number): Promise&lt;string&gt;

Obtains the specific-length text before the cursor. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getForward](#getforward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Promise used to return the specific-length text before the cursor.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.getForward(length).then((text: string) => {
  console.info('Succeeded in getting forward, text: ' + text);
}).catch((err: BusinessError) => {
  console.error(`Failed to getForward: ${JSON.stringify(err)}`);
});
```

### getBackward<sup>(deprecated)</sup>

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text after the cursor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getBackward](#getbackward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained text. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.getBackward(length, (err: BusinessError, text: string) => {
  if (err) {
    console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in getting borward, text: ' + text);
});
```

### getBackward<sup>(deprecated)</sup>

getBackward(length:number): Promise&lt;string&gt;

Obtains the specific-length text after the cursor. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getBackward](#getbackward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;string&gt; |  Promise used to return the specific-length text after the cursor.               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.getBackward(length).then((text: string) => {
  console.info('Succeeded in getting backward: ' + JSON.stringify(text));
}).catch((err: BusinessError) => {
  console.error(`Failed to getBackward: ${JSON.stringify(err)}`);
});
```

### deleteForward<sup>(deprecated)</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text before the cursor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [deleteForward](#deleteforward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.deleteForward(length, (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.info('Succeeded in deleting forward.');
  } else {
    console.error('Failed to deleteForward.');
  }
});
```

### deleteForward<sup>(deprecated)</sup>

deleteForward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text before the cursor. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [deleteForward](#deleteforward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length, which cannot be less than 0.|

**Return value** 

| Type                  | Description          |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the deletion is successful, and **false** means the opposite.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.deleteForward(length).then((result: boolean) => {
  if (result) {
    console.info('Succeeded in deleting forward.');
  } else {
    console.error('Failed to delete forward.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to deleteForward: ${JSON.stringify(err)}`);
});
```

### deleteBackward<sup>(deprecated)</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [deleteBackward](#deletebackward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                        | Mandatory| Description          |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | Yes  | Text length, which cannot be less than 0.     |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.deleteBackward(length, (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.info('Succeeded in deleting backward.');
  } else {
    console.error('Failed to deleteBackward.');
  }
});
```

### deleteBackward<sup>(deprecated)</sup>

deleteBackward(length:number): Promise&lt;boolean&gt;

Deletes the fixed-length text after the cursor. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [deleteBackward](#deletebackward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0. |

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; |  Promise used to return the result. The value **true** means that the deletion is successful, and **false** means the opposite.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length = 1;
textInputClient.deleteBackward(length).then((result: boolean) => {
  if (result) {
    console.info('Succeeded in deleting backward.');
  } else {
    console.error('Failed to deleteBackward.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to deleteBackward: ${JSON.stringify(err)}`);
});
```
### sendKeyFunction<sup>(deprecated)</sup>

sendKeyFunction(action: number, callback: AsyncCallback&lt;boolean&gt;): void

Sends the function key. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [sendKeyFunction](#sendkeyfunction9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Action of the function key.<br>- **0**: invalid key.<br>- **1**: confirm key (Enter key).|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action = 1;
textInputClient.sendKeyFunction(action, (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.info('Succeeded in sending key function.');
  } else {
    console.error('Failed to sendKeyFunction.');
  }
});
```

### sendKeyFunction<sup>(deprecated)</sup>

sendKeyFunction(action: number): Promise&lt;boolean&gt;

Sends the function key. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [sendKeyFunction](#sendkeyfunction9) instead.

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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action = 1;
textInputClient.sendKeyFunction(action).then((result: boolean) => {
  if (result) {
    console.info('Succeeded in sending key function.');
  } else {
    console.error('Failed to sendKeyFunction.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to sendKeyFunction: ${JSON.stringify(err)}`);
});
```

### insertText<sup>(deprecated)</sup>

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

Inserts text. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [insertText](#inserttext9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Text to insert.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textInputClient.insertText('test', (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to insertText: ${JSON.stringify(err)}`);
    return;
  }
  if (result) {
    console.info('Succeeded in inserting text.');
  } else {
    console.error('Failed to insertText.');
  }
});
```

### insertText<sup>(deprecated)</sup>

insertText(text:string): Promise&lt;boolean&gt;

Inserts text. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [insertText](#inserttext9) instead.

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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textInputClient.insertText('test').then((result: boolean) => {
  if (result) {
    console.info('Succeeded in inserting text.');
  } else {
    console.error('Failed to insertText.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to insertText: ${JSON.stringify(err)}`);
});
```

### getEditorAttribute<sup>(deprecated)</sup>

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

Obtains the attribute of the edit box. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getEditorAttribute](#geteditorattribute9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type  | Mandatory | Description  |
| -------- | ----- | ----- | ----- |
| callback | AsyncCallback&lt;[EditorAttribute](#editorattribute)&gt; | Yes|  Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the attribute of the edit box. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textInputClient.getEditorAttribute((err: BusinessError, editorAttribute: inputMethodEngine.EditorAttribute) => {
  if (err) {
    console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
    return;
  }
  console.info(`editorAttribute.inputPattern: ${editorAttribute.inputPattern}`;
  console.info(`editorAttribute.enterKeyType: ${editorAttribute.enterKeyType}`);
});
```

### getEditorAttribute<sup>(deprecated)</sup>

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

Obtains the attribute of the edit box. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getEditorAttribute](#geteditorattribute9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#editorattribute)&gt; |  Promise used to return the attribute of the edit box.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textInputClient.getEditorAttribute().then((editorAttribute: inputMethodEngine.EditorAttribute) => {
  console.info('editorAttribute.inputPattern: ' + JSON.stringify(editorAttribute.inputPattern));
  console.info('editorAttribute.enterKeyType: ' + JSON.stringify(editorAttribute.enterKeyType));
}).catch((err: BusinessError) => {
  console.error(`Failed to getEditorAttribute: ${JSON.stringify(err)}`);
});
```
<!--no_check-->
