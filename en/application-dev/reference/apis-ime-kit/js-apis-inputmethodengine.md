# @ohos.inputMethodEngine (Input Method Service)

<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=681375fe8e2ad6298fc081a819f69633a55a7ca2 translatedAt=2026-08-15T06:26:05.044Z pushedAt=2026-08-18T12:25:43.912Z -->

The **@ohos.inputMethodEngine** module is a server-side API module for input method apps (including system input methods and third-party input methods). It provides interaction capabilities between input method apps and the system input method framework.

This module contains server-side interfaces for input method apps, defining all open capabilities required while an input method app is running. The capabilities cover input method lifecycle management, creation and control of the soft keyboard panel, text editing operations (insertion, deletion, and selection), cursor control, physical keyboard event listening, secure mode management, and private data communication.

With this module, an input method app can:<br>- Subscribe to input method attach/detach events to perceive connection and disconnection with edit boxes.<br>- Create and manage soft keyboard panels (fixed mode, floating mode, and candidate mode) and status bar panels, and control panel visibility, size adjustment, position movement, immersive mode, and more.<br>- Use **InputClient** to perform operations on edit boxes, such as text insertion, text deletion, text selection, cursor movement, function key sending, and extended editing actions.<br>- Use **KeyboardDelegate** to listen for physical keyboard key events, cursor position changes, text selection region changes, text content changes, and edit box attribute changes.<br>- Manage security modes (basic mode and full access mode) and support privacy panel configuration.<br>- Exchange private data and custom messages with an edit box app.

This module is used during input method app development. It must be used within **InputMethodExtensionAbility**, and applies to scenarios such as system input method development, third-party input method development, and custom keyboard layout implementation.

> **NOTE**
>
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

The core open capabilities of this module are implemented by the following key interfaces and classes:

| Interface/Class | Description |
|---|---|
| InputMethodAbility | Input method capability object, which is a core entry for input method apps. Supports subscription to input method lifecycle events (attach/detach, keyboard showing/hiding, subtype switching, security mode changes, etc.), panel creation and destruction, and security mode query. The instance can be obtained via **getInputMethodAbility()**. |
| KeyboardDelegate | Keyboard delegate object. Supports listening for physical keyboard key events, cursor position changes, text selection region changes, text content changes, and edit box attribute changes. The instance can be obtained via **getKeyboardDelegate()**. |
| InputClient | Input client object. Provides capabilities to perform text operations on edit boxes, including inserting text, deleting text backward/forward, obtaining text before or after the cursor, moving the cursor, selecting text, sending function keys, and performing extended editing actions, setting preview text, transmitting private data, and exchanging custom messages. The instance can be obtained inside the callback for the subscribed **inputStart** event. |
| KeyboardController | Keyboard controller object. Provides capabilities such as hiding the keyboard and exiting the current input type. The instance can be obtained inside the callback for the subscribed **inputStart** event. |
| Panel | Input method panel object. Supports panel page content loading, size adjustment, position movement, panel showing/hiding, panel state switching, privacy mode configuration, immersive mode and effect configurations, preset panel rectangular area, and hot region update. The instance can be obtained via **createPanel()**. |
| MessageHandler | Custom communication object. Receives custom communication data sent by edit box apps and provides the termination notification callback. It is registered via **InputClient.recvMessage()**. |

The typical usage workflow within an input method app involves combined calls of multiple APIs. The core workflow is as follows:<br>1. Obtain an **InputMethodAbility** instance.<br>2. Subscribe to the **inputStart** event.<br>3. Obtain **KeyboardController** and **InputClient** within the callback<br>4. Create a panel.<br>5. Load panel page content.<br>6. Perform operations on the text of the edit box via **InputClient**<br>7. Control keyboard visibility via **KeyboardController**.

```javascript
// The following pseudocode illustrates the calling logic.

// 1. Obtain the input method ability object.
let inputMethodAbility = inputMethodEngine.getInputMethodAbility();

// 2. Obtain the keyboard delegate object to listen for physical keyboard and edit box change events.
let keyboardDelegate = inputMethodEngine.getKeyboardDelegate();
keyboardDelegate.on('keyDown', (event) => { return true; });
keyboardDelegate.on('cursorContextChange', (x, y, height) => {});
keyboardDelegate.on('selectionChange', (oldBegin, oldEnd, newBegin, newEnd) => {});

// 3. Subscribe to the input method attachment event to obtain **KeyboardController** and **InputClient**.
inputMethodAbility.on('inputStart', (kbController, inputClient) => {

  // 4. Create an input method panel.
  let panelInfo = { type: inputMethodEngine.PanelType.SOFT_KEYBOARD, flag: inputMethodEngine.PanelFlag.FLG_FIXED };
  let panel = inputMethodAbility.createPanel(context, panelInfo);

  // 5. Load panel page content.
  panel.setUiContent('pages/Index');

  // 6. Show the panel.
  panel.show();

  // 7. Perform operations on the edit box via **InputClient**.
  inputClient.insertText('Hello');
  inputClient.deleteForward(1);
  inputClient.moveCursor(inputMethodEngine.CURSOR_RIGHT);

  // 8. Hide the keyboard via **KeyboardController**.
  kbController.hide();
});

// 9. Subscribe to the input method detachment event.
inputMethodAbility.on('inputStop', () => {
  // Destroy the panel.
  inputMethodAbility.destroyPanel(panel);
});
```

## Modules to Import

```ts
import { inputMethodEngine } from '@kit.IMEKit';
```

## Constants

Provides the constant values of function keys, edit boxes, and cursors. These constants enable input method apps to identify attributes such as edit box types, Enter key functions, and cursor movement directions. Input method apps can adjust the keyboard layout and input behavior based on these constant values. For example, the app can switch between different keyboard layouts according to the edit box type (**PATTERN_TEXT**, **PATTERN_NUMBER**, etc.), and adjust the displayed text and icon of the Enter key according to the Enter key function (**ENTER_KEY_TYPE_SEARCH**, **ENTER_KEY_TYPE_SEND**, etc.).

The following constants are divided into three categories by function:

- Function key constants (**ENTER_KEY_TYPE** series): Define the function type of the Enter key on edit boxes. Input method apps can display corresponding key labels (such as "Search" or "Send") on the soft keyboard based on the function key type.

- Edit box constants (**PATTERN**/**OPTION**/**FLAG**/**DISPLAY_MODE** series): Define the input type, input attributes, status flags, and display modes of edit boxes. Input method apps adjust keyboard layouts and input policies accordingly.

- Cursor constants (**CURSOR** series): Define the cursor movement direction, used to specify the movement direction for [moveCursor](#movecursor9) and [moveCursorSync](#movecursorsync10).

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
| PATTERN_USER_NAME<sup>20+</sup> | number | 10 | User name edit box.<br/>**Model restriction:** This parameter can be used only in the stage model. |
| PATTERN_NEW_PASSWORD<sup>20+</sup> | number | 11 | New password edit box.<br/>**Model restriction:** This parameter can be used only in the stage model. |
| PATTERN_NUMBER_DECIMAL<sup>20+</sup> | number | 12 | Edit box for numbers with decimal points.<br/>**Model restriction:** This parameter can be used only in the stage model. |
| PATTERN_ONE_TIME_CODE<sup>20+</sup> | number | 13 | Verification code edit box.<br/>**Model restriction:** This parameter can be used only in the stage model. |
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
| CURSOR_UP<sup>9+</sup> | number | 1 | The cursor moves upward.|
| CURSOR_DOWN<sup>9+</sup> | number | 2 | The cursor moves downward.|
| CURSOR_LEFT<sup>9+</sup> | number | 3 | The cursor moves leftward.|
| CURSOR_RIGHT<sup>9+</sup> | number | 4 | The cursor moves rightward.|
| WINDOW_TYPE_INPUT_METHOD_FLOAT<sup>9+</sup> | number | 2105 | The input method is displayed in a floating window.|

## inputMethodEngine.getInputMethodAbility<sup>9+</sup>

getInputMethodAbility(): InputMethodAbility

Obtains an [InputMethodAbility](#inputmethodability) instance (input method capability object) for the input method app. This API can only be called by input method apps.<br>After this instance is obtained, the input method app can subscribe to soft keyboard show/hide request events, and create or destroy input method panels.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description              |
| ----------------------------------------- | ------------------ |
| [InputMethodAbility](#inputmethodability) | Input method app client.|

**Example**

```ts
// Obtain the input method app client instance.
let InputMethodAbility: inputMethodEngine.InputMethodAbility = inputMethodEngine.getInputMethodAbility();
```

## inputMethodEngine.getKeyboardDelegate<sup>9+</sup>

getKeyboardDelegate(): KeyboardDelegate

Obtains a [KeyboardDelegate](#keyboarddelegate) instance (keyboard delegate object) for the input method app.<br>After this instance is obtained, the input method app can subscribe to physical keyboard key events, text selection change events, and more.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                 | Description                    |
| ------------------------------------- | ------------------------ |
| [KeyboardDelegate](#keyboarddelegate) | Delegate for listening to client edit events.|

**Example**

```ts
// Obtain the delegate instance for listening to client edit events.
let KeyboardDelegate: inputMethodEngine.KeyboardDelegate = inputMethodEngine.getKeyboardDelegate();
```

## inputMethodEngine.getInputMethodEngine<sup>(deprecated)</sup>

getInputMethodEngine(): InputMethodEngine

Obtains an [InputMethodEngine](#inputmethodenginedeprecated) instance (input method engine) for the input method app.<br/>After this instance is obtained, the input method app can subscribe to soft keyboard show/hide request events and other events.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.getInputMethodAbility()](#inputmethodenginegetinputmethodability9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description              |
| ----------------------------------------- | ------------------ |
| [InputMethodEngine](#inputmethodenginedeprecated) | Input method app client.|

**Example**

```ts
// Obtain the input method app client instance (deprecated).
let InputMethodEngine: inputMethodEngine.InputMethodEngine = inputMethodEngine.getInputMethodEngine();
```

## inputMethodEngine.createKeyboardDelegate<sup>(deprecated)</sup>

createKeyboardDelegate(): KeyboardDelegate

Obtains a [KeyboardDelegate](#keyboarddelegate) instance for the input method app. After this instance is obtained, the input method app can subscribe to a physical keyboard event, text selection change event, and more.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.getKeyboardDelegate()](#inputmethodenginegetkeyboarddelegate9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                 | Description                    |
| ------------------------------------- | ------------------------ |
| [KeyboardDelegate](#keyboarddelegate) | Delegate for listening to client edit events.|

**Example**

```ts
let keyboardDelegate: inputMethodEngine.KeyboardDelegate = inputMethodEngine.createKeyboardDelegate();
```

## CommandDataType<sup>12+</sup>

type CommandDataType = number | string | boolean;

Defines the private data type, which varies depending on its function.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Type   | Description                |
| ------- | -------------------- |
| number  | Number.  |
| string  | String. |
| boolean | Boolean.|

## SizeChangeCallback<sup>15+</sup>

type SizeChangeCallback = (size: window.Size, keyboardArea?: KeyboardArea) => void

Callback triggered when the size of the input method panel changes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name      | Type                                                | Mandatory| Description                            |
| ------------ | ---------------------------------------------------- | ---- | -------------------------------- |
| size         | [window.Size](../apis-arkui/arkts-apis-window-i.md#size7) | Yes  | Panel size.                  |
| keyboardArea | [KeyboardArea](#keyboardarea15)                      | No   | Keyboard area within the current panel. Pass this parameter to obtain or listen for keyboard area changes. If omitted, the default value is **undefined**, and no keyboard area information will be returned. |

## InputMethodEngine<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 23. You are advised to use [InputMethodAbility](#inputmethodability) instead.

The following APIs must be called on an **InputMethodEngine** instance obtained through [getInputMethodEngine](js-apis-inputmethodengine.md#inputmethodenginegetinputmethodenginedeprecated).

### on('inputStart')<sup>(deprecated)</sup>

on(type: 'inputStart', callback: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

Enables listening for the input method binding event. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 23. You are advised to use [inputMethodEngine.InputMethodAbility.on](#oninputstart9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | Yes  | Event type, which is **'inputStart'**.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclientdeprecated)) => void | Yes| Callback used to return the **KeyboardController** and **TextInputClient** instances.|

**Example**

```ts
inputMethodEngine.getInputMethodEngine()
  .on('inputStart',
    (keyboardController: inputMethodEngine.KeyboardController, textInputClient: inputMethodEngine.TextInputClient) => {
      // Use kbController and textClient to perform related operations.
    });
```

### off('inputStart')<sup>(deprecated)</sup>

off(type: 'inputStart', callback?: (kbController: KeyboardController, textInputClient: TextInputClient) => void): void

Disables listening for the input method binding event.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 23. You are advised to use [inputMethodEngine.InputMethodAbility.off](#offinputstart9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type | string                                                       | Yes  | Event type, which is **'inputStart'**.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), textInputClient: [TextInputClient](#textinputclientdeprecated)) => void | No| Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
inputMethodEngine.getInputMethodEngine()
  .off('inputStart',
    (kbController: inputMethodEngine.KeyboardController, textClient: inputMethodEngine.TextInputClient) => {
      console.info('delete inputStart notification.');
    });
```

### on('keyboardShow'|'keyboardHide')<sup>(deprecated)</sup>

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

Enables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 23. You are advised to use [inputMethodEngine.InputMethodAbility.on](#onkeyboardshowkeyboardhide9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event.|
| callback | () => void   | Yes  | Callback used to return the result.                                                  |

**Example**

```ts
inputMethodEngine.getInputMethodEngine().on('keyboardShow', () => {
  console.info('inputMethodEngine keyboardShow.');
});
inputMethodEngine.getInputMethodEngine().on('keyboardHide', () => {
  console.info('inputMethodEngine keyboardHide.');
});
```

### off('keyboardShow'|'keyboardHide')<sup>(deprecated)</sup>

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

Disables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 23. You are advised to use [inputMethodEngine.InputMethodAbility.off](#offkeyboardshowkeyboardhide9) instead.

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

Represents the core capability object for input method apps. Provides capabilities including input method lifecycle management, panel creation and destruction, and event subscription. An input method app obtains this instance via [getInputMethodAbility](#inputmethodenginegetinputmethodability9).

Core capability overview:

- Lifecycle event subscription: Subscribe to the input method attach event using **on('inputStart')** to obtain [KeyboardController](#keyboardcontroller) and [InputClient](#inputclient9) instances, subscribe to the input method detach event using **on('inputStop')**, and subscribe to the soft keyboard show and hide events using **on('keyboardShow'|'keyboardHide')**.

- Panel management: Create an input method panel via [createPanel](#createpanel10) and destroy the panel via [destroyPanel](#destroypanel10). Calls to **createPanel** and **destroyPanel** must be paired to prevent resource leaks.

- Subtype and security mode: Subscribe to input method subtype change events using **on('setSubtype')** and security mode change events using **on('securityModeChange')**, and obtain the current security mode via [getSecurityMode](#getsecuritymode11).

- Private communication: Subscribe to app private data events using **on('privateCommand')** for private data exchange between the input method app and the attached app.

- Screen and window information: Subscribe to window change events using **on('setCallingWindow')**, screen ID change events using **on('callingDisplayDidChange')**, and text discard events using **on('discardTypingText')**.

Typical calling sequence:

1. The input method app calls **getInputMethodAbility()** in the **onCreate** lifecycle callback of [InputMethodExtensionAbility](js-apis-inputmethod-extension-ability.md) to obtain the instance.

2. Subscribe to the **on('inputStart')** event, and obtain **KeyboardController** and **InputClient** instances within the callback.

3. Call **createPanel()** inside the **on('inputStart')** callback to create a panel, and call **panel.setUiContent()** to load the keyboard page.

4. Subscribe to the **on('keyboardShow'|'keyboardHide')** event and call **panel.show()/panel.hide()** in the callback to show/hide the panel.

5. Call **destroyPanel()** in the **onDestroy** lifecycle callback of **InputMethodExtensionAbility** to release resources, and unsubscribe from all events.

In the following API examples, you must first use [getInputMethodAbility](#inputmethodenginegetinputmethodability9) to obtain an **InputMethodAbility** instance, and then call the APIs using the obtained instance.

### on('inputStart')<sup>9+</sup>

on(type: 'inputStart', callback: (kbController: KeyboardController, inputClient: InputClient) => void): void

Enables listening for the input method binding event. This API uses an asynchronous callback to return the result.

Usage scenarios: When an edit box gains focus and attaches to the input method, the input method app needs to obtain **KeyboardController** and **InputClient** instances for subsequent keyboard operations and text interactions.

Use effect: When an edit box attaches to the input method app, the callback is triggered and returns **KeyboardController** and **InputClient** instances. Within the callback, the input method app can create panels, load keyboard pages, register listeners for **KeyboardDelegate** events, and perform other operations.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                        | Yes  | Event type, which is **'inputStart'**.|
| callback | (kbController: [KeyboardController](#keyboardcontroller), inputClient: [InputClient](#inputclient9)) => void | Yes | Callback used to return the instances related to input method operations. **kbController** is the keyboard controller instance, used to control keyboard display/hiding; **inputClient** is the input client instance, used for text interaction with the edit box. |

**Example**

```ts
inputMethodEngine.getInputMethodAbility()
  .on('inputStart',
    (keyboardController: inputMethodEngine.KeyboardController, inputClient: inputMethodEngine.InputClient) => {
      // Use kbController and client to perform related operations.
    });
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

Usage scenarios: The input method app needs to perform cleanup operations (such as hiding the panel and releasing resources) when the edit box loses focus or the user switches the input method.

Use effect: The callback is triggered when the attachment between the edit box and the input method app terminates. The input method app shall hide the panel, unsubscribe from events, and release resources related to **InputClient** within the callback.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'inputStop'**.|
| callback | () => void | Yes | Callback function, with no return parameters. |

**Example**

```ts
inputMethodEngine.getInputMethodAbility().on('inputStop', () => {
  console.info('inputMethodAbility inputStop');
});
```

### off('inputStop')<sup>9+</sup>

off(type: 'inputStop', callback: () => void): void

Disables listening for the input method stop event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'inputStop'**.|
| callback | () => void | Yes | Callback used to unsubscribe from the keyboard show/hide event. Passing this parameter cancels the subscription for the specified callback. If no callback is provided, all callbacks corresponding to **type** will be unsubscribed. |

**Example**

```ts
inputMethodEngine.getInputMethodAbility().off('inputStop', () => {
  console.info('inputMethodAbility delete inputStop notification.');
});
```

### on('setCallingWindow')<sup>9+</sup>

on(type: 'setCallingWindow', callback: (wid: number) => void): void;

Enables listening for the window invocation setting event. This API uses an asynchronous callback to return the result.

Usage scenarios: The input method app needs to adjust the panel position or reposition the panel when the window of the attached app changes (for example, when the app switches windows or in multi-window scenarios).

Use effect: The callback is triggered when the calling window changes and returns the new window ID. The input method app can adjust the panel position based on this window ID.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'setCallingWindow'**.|
| callback | (wid: number) => void | Yes | Callback used to return the result. The parameter is the ID of the caller window. |

**Example**

```ts
inputMethodEngine.getInputMethodAbility().on('setCallingWindow', (windowId: number) => {
  console.info('inputMethodAbility setCallingWindow');
});
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
inputMethodEngine.getInputMethodAbility().off('setCallingWindow', (windowId: number) => {
  console.info('inputMethodAbility delete setCallingWindow notification.');
});
```

### on('keyboardShow'|'keyboardHide')<sup>9+</sup>

on(type: 'keyboardShow'|'keyboardHide', callback: () => void): void

Enables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

Usage scenarios: The input method app needs to perform corresponding UI updates (such as adjusting the panel layout and updating the candidate word region) when the soft keyboard is shown or hidden.

Use effect: When a request to show the soft keyboard is triggered, the **'keyboardShow'** callback is invoked, and the input method app shall call **panel.show()** to display the panel within the callback. When a request to hide the soft keyboard is triggered, the **'keyboardHide'** callback is invoked, and the input method app shall call **panel.hide()** to hide the panel within the callback.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type.<br>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event.|
| callback | () => void   | Yes  | Callback used to return the result.                                                  |

**Example**

```ts
inputMethodEngine.getInputMethodAbility().on('keyboardShow', () => {
  console.info('InputMethodAbility keyboardShow.');
});
inputMethodEngine.getInputMethodAbility().on('keyboardHide', () => {
  console.info('InputMethodAbility keyboardHide.');
});
```

### off('keyboardShow'|'keyboardHide')<sup>9+</sup>

off(type: 'keyboardShow'|'keyboardHide', callback?: () => void): void

Disables listening for a keyboard visibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes   | Event type.<br/>- The value **'keyboardShow'** indicates the keyboard display event.<br>- The value **'keyboardHide'** indicates the keyboard hiding event. |
| callback | () => void   | No   | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type. |

**Example**

```ts
inputMethodEngine.getInputMethodAbility().off('keyboardShow', () => {
  console.info('InputMethodAbility delete keyboardShow notification.');
});
inputMethodEngine.getInputMethodAbility().off('keyboardHide', () => {
  console.info('InputMethodAbility delete keyboardHide notification.');
});
```

### on('setSubtype')<sup>9+</sup>

on(type: 'setSubtype', callback: (inputMethodSubtype: InputMethodSubtype) => void): void

Enables listening for the input method subtype setting event. This API uses an asynchronous callback to return the result.

Usage scenarios: The input method app needs to switch to the corresponding keyboard layout or input logic when the subtype (such as language or input mode) changes.

Use effect: The callback is triggered when the input method subtype changes and returns information about the new input method subtype.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type| Mandatory | Description|
| -------- | --- | ---- | --- |
| type     | string | Yes  | Event type, which is **'setSubtype'**.|
| callback | (inputMethodSubtype: [InputMethodSubtype](js-apis-inputmethod-subtype.md)) => void | Yes | Callback used to return the input method subtype **InputMethodSubtype**. |

**Example**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';

inputMethodEngine.getInputMethodAbility().on('setSubtype', (inputMethodSubtype: InputMethodSubtype) => {
  console.info('InputMethodAbility setSubtype.');
});
```

### off('setSubtype')<sup>9+</sup>

off(type: 'setSubtype', callback?: (inputMethodSubtype: InputMethodSubtype) => void): void

Disables listening for the input method subtype setting event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type | Mandatory| Description  |
| ------- | ----- | ---- | ---- |
| type     | string | Yes  | Event type, which is **'setSubtype'**.|
| callback | (inputMethodSubtype: [InputMethodSubtype](js-apis-inputmethod-subtype.md)) => void | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type. |

**Example**

```ts
inputMethodEngine.getInputMethodAbility().off('setSubtype', () => {
  console.info('InputMethodAbility delete setSubtype notification.');
});
```

### on('securityModeChange')<sup>11+</sup>

on(type: 'securityModeChange', callback: Callback< SecurityMode>): void

Enables listening for the security mode changes of the input method. This API uses an asynchronous callback to return the result.

Use scenarios: The input method app needs to adjust keyboard behaviors when the security mode changes (for example, when the edit box switches to password input mode or privacy mode), such as disabling screenshots and switching to a secure keyboard layout.

Use effect: The callback is triggered when the security mode changes and returns the current security mode value.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                          |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| type     | string                                      | Yes  | Event type, which is **'securityModeChange'**.|
| callback | Callback\<[SecurityMode](#securitymode11)> | Yes  | Callback used to return the current security mode.      |

**Example**

```ts
inputMethodEngine.getInputMethodAbility()
  .on('securityModeChange', (securityMode: inputMethodEngine.SecurityMode) => {
    console.info(`InputMethodAbility securityModeChange, security is ${securityMode}`);
  });
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
let securityChangeCallback: (securityMode: inputMethodEngine.SecurityMode) => void =
  (securityMode: inputMethodEngine.SecurityMode) => {
    console.info(`InputMethodAbility securityModeChange, security is ${securityMode}`);
  };
let inputMethodAbility: inputMethodEngine.InputMethodAbility = inputMethodEngine.getInputMethodAbility();
inputMethodAbility.on('securityModeChange', securityChangeCallback);
inputMethodAbility.off('securityModeChange', securityChangeCallback);
```

### on('privateCommand')<sup>12+</sup>

on(type: 'privateCommand', callback: Callback<Record<string, CommandDataType>>): void;

Enables listening for the private data event of the input method. This API uses an asynchronous callback to return the result.

Usage scenarios: This API is used when private data (such as custom commands and configuration information) needs to be transmitted between an app and the input method. Only the system default input method app can subscribe to this event.

Use effect: The callback is triggered when the attached app sends private data to the input method, returning the private data record.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                         | Mandatory| Description                                      |
| -------- | --------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                        | Yes  | Event type, which is **'privateCommand'**.|
| callback | Callback<Record<string, [CommandDataType](#commanddatatype12)>> | Yes  | Callback used to return the private data sent to the input method app.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 12800010 | not the preconfigured default input method. |

**Example**

```ts
let privateCommandCallback: (record: Record<string, inputMethodEngine.CommandDataType>) => void =
  (record: Record<string, inputMethodEngine.CommandDataType>) => {
    for (const key in record) {
      console.info(`private command key: ${key}, value: ${record[key]}`);
    }
  }
inputMethodEngine.getInputMethodAbility().on('privateCommand', privateCommandCallback);
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
let privateCommandCallback: (record: Record<string, inputMethodEngine.CommandDataType>) => void =
  (record: Record<string, inputMethodEngine.CommandDataType>) => {
    for (const key in record) {
      console.info(`private command key: ${key}, value: ${record[key]}`);
    }
  }

inputMethodEngine.getInputMethodAbility().off('privateCommand', privateCommandCallback);
```

### on('callingDisplayDidChange')<sup>18+</sup>

on(type: 'callingDisplayDidChange', callback: Callback\<number>): void

Enables listening for changes of the screen ID of the window associated with the edit box. This API uses an asynchronous callback to return the result.

Usage scenarios: On multi-screen devices, when the edit box switches between different screens, the input method app needs to adjust the panel position and size based on the new screen ID.

Use effect: The callback is triggered when the screen ID where the edit box resides changes, returning the new screen ID.

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
inputMethodEngine.getInputMethodAbility().on('callingDisplayDidChange', (displayId: number) => {
  console.info(`display id: ${displayId}`);
});
inputMethodEngine.getInputMethodAbility().on('callingDisplayDidChange', callingDisplayDidChangeCallback);
```

### off('callingDisplayDidChange')<sup>18+</sup>

off(type: 'callingDisplayDidChange', callback?: Callback\<number>): void

Disables listening for changes of the screen ID of the window associated with the edit box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'callingDisplayDidChange'**.                  |
| callback | Callback\<number>  | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
inputMethodEngine.getInputMethodAbility().off('callingDisplayDidChange', (displayId: number) => {
  console.info('InputMethodAbility delete calling display notification.');
});
```

### on('discardTypingText')<sup>20+</sup>

on(type: 'discardTypingText', callback: Callback&lt;void&gt; ): void

Subscribes to the event in which the edit box app sends a request to discard candidate words to the input method. This API uses an asynchronous callback to return the result.

Usage scenarios: This API is used when the edit box app needs to notify the input method to discard the current candidate word list (such as when the user switches edit boxes or after form submission).

Use effect: The callback is triggered when the edit box app sends a request to discard candidate words. The input method app discards the candidate word list and pre-input text within the callback.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                         | Mandatory| Description                                      |
| -------- | --------------------------------------------- | ---- | ------------------------------------------ |
| type     | string                                        | Yes  | Event type, which is **'discardTypingText'**.<br>**'discardTypingText'** indicates subscribing to the event in which the edit box app sends a request to discard candidate words to the input method.|
| callback | Callback&lt;void&gt; | Yes | Callback used to return the result. |

**Example**

```ts
inputMethodEngine.getInputMethodAbility().on('discardTypingText', () => {
  console.info('InputMethodAbility discard the typing text.');
});
```

### off('discardTypingText')<sup>20+</sup>

off(type: 'discardTypingText', callback?: Callback&lt;void&gt; ): void

Unsubscribes from the event that the edit box app sends "clear candidate words" to the input method. This API uses an asynchronous callback to return the result.

Usage scenario: Used when the edit box app needs to notify the input method to clear the current candidate word list (for example, when the user switches input boxes or submits a form).

Effect after use: When the edit box app sends a request to clear candidate words, the callback is triggered, and the input method app should clear the candidate word list and pre-input text in the callback.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type, which is **'discardTypingText'**.<br> - **'discardTypingText'**: indicates unsubscribing from the event of discarding candidate words and sending the event to the input method.|
| callback | Callback&lt;void&gt;   | No   | Callback used to unsubscribe. If this parameter is not specified, this API unregisters all callbacks for the specified type. |

**Example**

```ts
inputMethodEngine.getInputMethodAbility().off('discardTypingText', () => {
  console.info('InputMethodAbility discard the typing text.');
});
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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 12800004 | not an input method application. |

**Example**

```ts
let security: inputMethodEngine.SecurityMode = inputMethodEngine.getInputMethodAbility().getSecurityMode();
console.error(`getSecurityMode, securityMode is : ${security}`);
```

### createPanel<sup>10+</sup>

createPanel(ctx: BaseContext, info: PanelInfo, callback: AsyncCallback\<Panel>): void

Creates an input method panel. This API can be called only by an input method app in the [InputMethodExtensionAbility](js-apis-inputmethod-extension-ability.md) class. This API uses an asynchronous callback to return the result.

Paired calls:

- After a panel is created via a call to **createPanel()**, [destroyPanel](#destroypanel10) must be called to destroy the panel and release resources after use.

- Failure to call **destroyPanel()** causes resource leaks and affects system resource usage.

- A single input method app can create only one soft keyboard panel and one status bar panel.

> **NOTE**
>
> A single input method app can create only one [soft keyboard panel](#paneltype10) and one [status bar panel](#paneltype10).<br>
> The input method panel does not support the creation of child windows. For example, you cannot [set an app child window](../../windowmanager/application-window-fa.md#setting-an-app-subwindow) by using **window.createWindow**, or create child window dialogs by using [bindContextMenu](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu8), [CustomDialog](../apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md), or other APIs. You are advised to use non-child-window alternatives, such as [dialogs](../apis-arkui/arkui-ts/ohos-arkui-advanced-Dialog.md), [bindMenu](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu), or setting **showInSubwindow** to **false**.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current context of the input method.|
| info    | [PanelInfo](#panelinfo10)   | Yes  | Information about the input method panel.|
| callback | AsyncCallback\<[Panel](#panel10)> | Yes  | Callback used to return the result. If the operation is successful, the created input method panel is returned. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800004   | not an input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethodEngine, InputMethodExtensionAbility } from '@kit.IMEKit';
import { Want } from '@kit.AbilityKit';

// Create the panel information. Set the panel type to soft keyboard and the state to fixed.
let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}

class InputMethodExt extends InputMethodExtensionAbility {
    onCreate(want: Want): void {
        console.info(`onCreate, want: ${want.abilityName}`);
        // context is the context object provided by the InputMethodExtensionAbility class and does not need to be obtained separately.
        if (this.context) {
            // Create the input method panel.
            inputMethodEngine.getInputMethodAbility()
            .createPanel(this.context, panelInfo, (err: BusinessError, panel: inputMethodEngine.Panel) => {
                if (err) {
                console.error(`Failed to createPanel. Code is ${err.code}, message is ${err.message}`);
                return;
              }
                console.info('Succeed in creating panel.');
            })
        }
    }
}
```

### createPanel<sup>10+</sup>

createPanel(ctx: BaseContext, info: PanelInfo): Promise&lt;Panel&gt;

Creates an input method panel. This API can be called only by an input method app in the [InputMethodExtensionAbility](js-apis-inputmethod-extension-ability.md) class. This API uses a promise to return the result.

> **NOTE**
>
> A single input method app can create only one [soft keyboard panel](#paneltype10) and one [status bar panel](#paneltype10).<br>
> The input method panel does not support the creation of child windows. For example, you cannot [set an app child window](../../windowmanager/application-window-fa.md#setting-an-app-subwindow) by using **window.createWindow**, or create child window dialogs by using [bindContextMenu](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu8), [CustomDialog](../apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md), or other APIs. You are advised to use non-child-window alternatives, such as [dialogs](../apis-arkui/arkui-ts/ohos-arkui-advanced-Dialog.md), [bindMenu](../apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu), or setting **showInSubwindow** to **false**.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| ctx     | [BaseContext](../apis-ability-kit/js-apis-inner-application-baseContext.md) | Yes  | Current context of the input method.|
| info    | [PanelInfo](#panelinfo10)   | Yes  | Information about the input method panel.|

**Return value**

| Type  | Description                                                                |
| ------- | ------------------------------------------------------------------ |
| Promise&lt;[Panel](#panel10)&gt; | Promise used to return the result. When the input method panel is created successfully, the input method panel object is returned. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID  | Error Message                      |
| ---------- | ----------------------------- |
| 401        | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800004   | not an input method application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethodEngine, InputMethodExtensionAbility } from '@kit.IMEKit';
import { Want } from '@kit.AbilityKit';

// Create the panel information. Set the panel type to soft keyboard and the state to fixed.
let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}

class InputMethodExt extends InputMethodExtensionAbility {
    onCreate(want: Want): void {
        console.info(`onCreate, want: ${want.abilityName}`);
        if (this.context) {
            inputMethodEngine.getInputMethodAbility().createPanel(this.context, panelInfo)
                .then((panel: inputMethodEngine.Panel) => {
                console.info('Succeed in creating panel.');
            }).catch((err: BusinessError) => {
                console.error(`Failed to create panel. Code is ${err.code}, message is ${err.message}`);
            })
        }
    }
}
```

### destroyPanel<sup>10+</sup>

destroyPanel(panel: Panel, callback: AsyncCallback&lt;void&gt; ): void

Destroys an input method panel. This API is called after the panel is created via [createPanel](#createpanel10). This API uses an asynchronous callback to return the result.

Paired calls:

- This API must be used together with [createPanel](#createpanel10) to destroy the input method panel created via **createPanel()**.

- The panel to be destroyed must be a successfully created panel object.

- Failure to destroy a panel properly may cause resource leaks. It is recommended that you call **destroyPanel()** in a timely manner to release resources after the panel is no longer in use.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ------- | ----------- | ---- | ------------------------ |
| panel     | [Panel](#panel10) | Yes  | Input method panel to destroy.|
| callback | AsyncCallback&lt;void&gt;  | Yes   | Callback used to return the result. If the input method panel is destroyed successfully, **err** is **undefined**; otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Create the panel information. Set the panel type to soft keyboard and the state to fixed.
let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}

let inputPanel: inputMethodEngine.Panel | undefined = undefined;
// context is the context object provided by the InputMethodExtensionAbility class and does not need to be obtained separately.
if (this.context) {
  inputMethodEngine.getInputMethodAbility()
    .createPanel(this.context, panelInfo, (err: BusinessError, panel: inputMethodEngine.Panel) => {
      if (err) {
        console.error(`Failed to create panel. Code is ${err.code}, message is ${err.message}`);
        return;
      }
      inputPanel = panel;
      console.info('Succeed in creating panel.');
    })
}

if (inputPanel) {
  inputMethodEngine.getInputMethodAbility().destroyPanel(inputPanel, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to destroy panel. Code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('Succeed in destroying panel.');
  })
}
```

### destroyPanel<sup>10+</sup>

destroyPanel(panel: Panel): Promise&lt;void&gt; 

Destroys the specified input method panel. This API uses a promise to return the result.

Paired calls:

- This API must be used together with [createPanel](#createpanel10) to destroy the input method panel created via **createPanel()**.

- The panel to be destroyed must be a successfully created panel object.

- Failure to destroy a panel properly may cause resource leaks. It is recommended that you call **destroyPanel()** in a timely manner to release resources after the panel is no longer in use.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                    |
| ---------| ----------- | ---- | ------------------------ |
| panel    | [Panel](#panel10)       | Yes  | Input method panel to destroy.     |

**Return value**

| Type   | Description                                                                |
| ------- | -------------------------------------------------------------------- |
| Promise&lt;void&gt;  | Promise that returns no result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Create the panel information. Set the panel type to soft keyboard and the state to fixed.
let panelInfo: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}

let inputPanel: inputMethodEngine.Panel | undefined = undefined;
// context is the context object provided by the InputMethodExtensionAbility class and does not need to be obtained separately.
if (this.context) {
  inputMethodEngine.getInputMethodAbility()
    .createPanel(this.context, panelInfo, (err: BusinessError, panel: inputMethodEngine.Panel) => {
      if (err) {
        console.error(`Failed to create panel. Code is ${err.code}, message is ${err.message}`);
        return;
      }
      inputPanel = panel;
      console.info('Succeed in creating panel.');
    })
}

if (inputPanel) {
  inputMethodEngine.getInputMethodAbility().destroyPanel(inputPanel).then(() => {
    console.info('Succeed in destroying panel.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to destroy panel. Code is ${err.code}, message is ${err.message}`);
  });
}
```

## KeyboardDelegate

Provides a delegate object for listening to keyboard events. It is used by the input method app to listen for physical keyboard key events and edit box text/cursor/selection change events. The input method app obtains this instance through [getKeyboardDelegate](#inputmethodenginegetkeyboarddelegate9). Core capabilities include:

- Physical keyboard key events: Subscribe to physical key press/release events through **on('keyDown'|'keyUp')**, and subscribe to more comprehensive key events (including modifier key information) through **on('keyEvent')**. The callback returns **true** to indicate that the key event is consumed, and **false** to indicate that it is not consumed.

- Cursor and selection change events: Subscribe to cursor position change events through **on('cursorContextChange')**, and subscribe to text selection change events through **on('selectionChange')**. The input method app can adjust the candidate word position or input strategy based on these events.

- Text change events: Subscribe to edit box text content change events through **on('textChange')**, based on which the input method app can update candidate words or input suggestions.

- Edit box attribute change event: Subscribe to the edit box attribute change event through **on('editorAttributeChanged')**, so that the input method app can dynamically adjust the keyboard layout based on edit box attribute changes.

Usage scenarios:

- When developing the physical keyboard shortcut handling feature, subscribe to the **on('keyDown'|'keyUp')** or **on('keyEvent')** event to intercept specific keys.

- When the input method behavior needs to be adjusted based on the real-time edit box state (cursor, selection, text, and attributes), subscribe to the corresponding **on** event.

In the following API examples, you must first use [getKeyboardDelegate](#inputmethodenginegetkeyboarddelegate9) to obtain a **KeyboardDelegate** instance, and then call the APIs using the obtained instance.

### on('keyDown'|'keyUp')

on(type: 'keyDown'|'keyUp', callback: (event: KeyEvent) => boolean): void

Enables listening for a physical keyboard event. This API uses an asynchronous callback to return the result.

Usage scenarios: Implement shortcut functions, intercept special keys, and handle function keys (such as Backspace and Enter), among others.

Use effect: The callback is triggered when a physical key is pressed or released, returning key information. If the key event is consumed by the event subscriber, the callback returns **true**; otherwise, it returns **false**. When **true** is returned, the key event will no longer be delivered to the edit box. When **false** is returned, the key event continues to be delivered to the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                           | Mandatory| Description                                                 |
| -------- | ------------------------------- | ---- |-----------------------------------------------------|
| type   | string         | Yes  | Event type.<br>- The value **'keyDown'** indicates the keydown event.<br>- The value **'keyUp'** indicates the keyup event.|
| callback | (event: [KeyEvent](#keyevent)) => boolean | Yes| Callback used to return the key information. If the event is consumed by the event subscriber, **true** is returned. Otherwise, **false** is returned.  |

**Example**

```ts
inputMethodEngine.getKeyboardDelegate().on('keyUp', (keyEvent: inputMethodEngine.KeyEvent) => {
  console.info(`inputMethodEngine keyCode.(keyUp): ${keyEvent.keyCode}`);
  console.info(`inputMethodEngine keyAction.(keyUp): ${keyEvent.keyAction}`);
  return true;
});
inputMethodEngine.getKeyboardDelegate().on('keyDown', (keyEvent: inputMethodEngine.KeyEvent) => {
  console.info(`inputMethodEngine keyCode.(keyDown): ${keyEvent.keyCode}`);
  console.info(`inputMethodEngine keyAction.(keyDown): ${keyEvent.keyAction}`);
  return true;
});
```

### off('keyDown'|'keyUp')

off(type: 'keyDown'|'keyUp', callback?: (event: KeyEvent) => boolean): void

Unsubscribes from key press and release events on the hard keyboard (that is, the physical keyboard).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type    | Mandatory | Description |
| -------- | ------- | ---- | ----- |
| type     | string  | Yes  | Event type.<br>- The value **'keyDown'** indicates the keydown event.<br>- The value **'keyUp'** indicates the keyup event.|
| callback | (event: [KeyEvent](#keyevent)) => boolean | No   | Callback used to unsubscribe from specific key events. Passing this parameter cancels the subscription for the specified callback. If this parameter is not specified, this API unregisters all callbacks for the specified type.  |

**Example**

```ts
inputMethodEngine.getKeyboardDelegate().off('keyUp', (keyEvent: inputMethodEngine.KeyEvent) => {
  console.info('delete keyUp notification.');
  return true;
});
inputMethodEngine.getKeyboardDelegate().off('keyDown', (keyEvent: inputMethodEngine.KeyEvent) => {
  console.info('delete keyDown notification.');
  return true;
});
```

### on('keyEvent')<sup>10+</sup>

on(type: 'keyEvent', callback: (event: InputKeyEvent) => boolean): void

Subscribes to hard keyboard (physical keyboard) events. This API uses an asynchronous callback to return the result. Compared with **on('keyDown'|'keyUp')**, **on('keyEvent')** provides more comprehensive key event information, including modifier key states for Ctrl/Shift/Alt and **unicodeChar** information. It applies to scenarios requiring processing of key combinations or access to detailed key event data.

Usage scenarios: Require handling key combinations (such as Ctrl+C and Shift+Enter) or obtaining more comprehensive key information (such as **unicodeChar** and **ctrlKey**).

Use effect: When a physical key event is triggered, the callback is invoked. If the key event is consumed by the event subscriber, the callback returns **true**; otherwise, it returns **false**.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'keyEvent'**.|
| callback | (event: [InputKeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent)) => boolean | Yes  | Callback used to return the result. The input parameter is the key event information and the return value is of the Boolean type.<br>- Input parameter: [InputKeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent).<br>- If the event is consumed by the event subscriber, **true** is returned. Otherwise, **false** is returned.|

**Example**

```ts
import type { KeyEvent } from '@kit.InputKit';

inputMethodEngine.getKeyboardDelegate().on('keyEvent', (keyEvent: KeyEvent) => {
  console.info(`inputMethodEngine keyEvent.action:${ keyEvent.action}`);
  console.info(`inputMethodEngine keyEvent.key.code: ${keyEvent.key.code}`);
  console.info(`inputMethodEngine keyEvent.ctrlKey: ${keyEvent.ctrlKey}`);
  console.info(`inputMethodEngine keyEvent.unicodeChar: ${keyEvent.unicodeChar}`);
  return true;
});
```

### off('keyEvent')<sup>10+</sup>

off(type: 'keyEvent', callback?: (event: InputKeyEvent) => boolean): void

Disables listening for a keyboard event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type, which is **'keyEvent'**.|
| callback | (event: [InputKeyEvent](../apis-input-kit/js-apis-keyevent.md#keyevent)) => boolean | No   | Callback used to unsubscribe from specific keyboard events. Passing this parameter cancels the subscription for the specified callback. If this parameter is not specified, this API unregisters all callbacks for the specified type. |

**Example**

```ts
import type { KeyEvent } from '@kit.InputKit';

inputMethodEngine.getKeyboardDelegate().off('keyEvent', (keyEvent: KeyEvent) => {
  console.info('This is a callback function which will be deregistered.');
  return true;
});
inputMethodEngine.getKeyboardDelegate().off('keyEvent');
```

### on('cursorContextChange')

on(type: 'cursorContextChange', callback: (x: number, y:number, height:number) => void): void

Enables listening for the cursor change event. This API uses an asynchronous callback to return the result.

Usage scenarios: Update the candidate word display position in real time, adjust the input method UI based on the cursor position, and implement a floating menu that follows the cursor, among others.

Use effect: This callback is triggered when the cursor position in the edit box changes, returning the x coordinate, y coordinate, and height of the cursor. The input method app can adjust the positioning of the candidate word window or panel accordingly.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type | Mandatory | Description |
| -------- | ---- | ---- | ----- |
| type     | string | Yes  | Event type, which is **'cursorContextChange'**.|
| callback | (x: number, y: number, height: number) => void | Yes | Callback used to return the cursor information.<br/>- **x**: x coordinate of the top of the cursor, in px. **y**: y coordinate of the top of the cursor, in px. **height**: height of the cursor, in px. |

**Example**

```ts
inputMethodEngine.getKeyboardDelegate().on('cursorContextChange', (x: number, y: number, height: number) => {
  console.info('inputMethodEngine cursorContextChange x:' + x);
  console.info('inputMethodEngine cursorContextChange y:' + y);
  console.info('inputMethodEngine cursorContextChange height:' + height);
});
```

### off('cursorContextChange')

off(type: 'cursorContextChange', callback?: (x: number, y: number, height: number) => void): void

Unsubscribes from cursor change events.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type | Mandatory | Description  |
| -------- | ---- | ---- | ------ |
| type     | string  | Yes  | Event type, which is **'cursorContextChange'**.|
| callback | (x: number, y:number, height:number) => void | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
inputMethodEngine.getKeyboardDelegate().off('cursorContextChange');
```

### on('selectionChange')

on(type: 'selectionChange', callback: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

Enables listening for the text selection change event. This API uses an asynchronous callback to return the result.

Usage scenarios: Listen for user text selection to provide quick actions such as cut, copy, and paste, display relevant suggestions based on selected text, implement text editing assistance features, and more.

Use effect: This callback is triggered when the text selection range in the edit field changes, returning the start and end indices of the selection range before and after the change.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type  | Mandatory| Description  |
| -------- | ----- | ---- | ---- |
| type     | string  | Yes  | Event type, which is **'selectionChange'**.|
| callback | (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void | Yes  | Callback used to return the text selection information.<br>- **oldBegin**: start of the selected text before the change.<br>- **oldEnd**: end of the selected text before the change.<br>- **newBegin**: start of the selected text after the change.<br>- **newEnd**: end of the selected text after the change.|

**Example**

```ts
inputMethodEngine.getKeyboardDelegate()
  .on('selectionChange', (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => {
    console.info('selectionChange oldBegin:' + oldBegin);
    console.info('selectionChange oldEnd:' + oldEnd);
    console.info('selectionChange newBegin:' + newBegin);
    console.info('selectionChange newEnd:' + newEnd);
  });
```

### off('selectionChange')

off(type: 'selectionChange', callback?: (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void): void

Unsubscribes from text selection change events.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type | Mandatory| Description    |
| -------- | ------- | ---- | ------- |
| type     | string  | Yes  | Event type, which is **'selectionChange'**.|
| callback | (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => void | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type.|

**Example**

```ts
inputMethodEngine.getKeyboardDelegate()
  .off('selectionChange', (oldBegin: number, oldEnd: number, newBegin: number, newEnd: number) => {
    console.info('delete selectionChange notification.');
  });
```

### on('textChange')

on(type: 'textChange', callback: (text: string) => void): void

Enables listening for the text change event. This API uses an asynchronous callback to return the result.

Usage scenarios: Update candidate words, provide intelligent input suggestions, and implement predictive input based on text changes, among others.

Use effect: This callback is triggered when the text content in the edit box changes, returning the complete text content of the current edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type, which is **'textChange'**.|
| callback | (text: string) => void | Yes  | Callback used to return the text content.|

**Example**

```ts
inputMethodEngine.getKeyboardDelegate().on('textChange', (text: string) => {
  console.info('inputMethodEngine textChange. text:' + text);
});
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
inputMethodEngine.getKeyboardDelegate().off('textChange', (text: string) => {
  console.info('delete textChange notification. text:' + text);
});
```

### on('editorAttributeChanged')<sup>10+</sup>

on(type: 'editorAttributeChanged', callback: (attr: EditorAttribute) => void): void

Enables listening for the edit box attribute change event. This API uses an asynchronous callback to return the result.

Usage scenarios: The input method app needs to dynamically adjust the keyboard layout in response to edit box attribute changes (for example, when the input type switches from text to numeric, or the Enter key type switches from "Search" to "Send").

Use effect: This callback is triggered when the edit box attributes change, returning updated edit box attribute information (including **inputPattern** and **enterKeyType**). The input method app can adjust the keyboard layout accordingly.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes   | Edit box attribute change event. The value is fixed at **'editorAttributeChanged'**. |
| callback | (attr: [EditorAttribute](#editorattribute)) => void | Yes  | Callback used to return the updated edit box attributes.|

**Example**

```ts
inputMethodEngine.getKeyboardDelegate()
  .on('editorAttributeChanged', (editorAttribute: inputMethodEngine.EditorAttribute) => {
    console.info(`Succeeded in receiving attribute of editor, inputPattern = ${editorAttribute.inputPattern}, enterKeyType = ${editorAttribute.enterKeyType}`);
  });
```

### off('editorAttributeChanged')<sup>10+</sup>

off(type: 'editorAttributeChanged', callback?: (attr: EditorAttribute) => void): void

Disables listening for the edit box attribute change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description                                                        |
| -------- | ------ | ---- | ------------------------------------------------------------ |
| type     | string | Yes   | Edit box attribute change event. The value is fixed at **'editorAttributeChanged'**. |
| callback | (attr: [EditorAttribute](#editorattribute)) => void | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified type by default.|

**Example**

```ts
inputMethodEngine.getKeyboardDelegate().off('editorAttributeChanged');
```

## Panel<sup>10+</sup>

Represents the input method panel object, offering capabilities including panel page loading, showing/hiding, size adjustment, position movement, and mode switching. A **Panel** instance is obtained through the [createPanel](#createpanel10) API of **InputMethodAbility**, and destroyed via a call to [destroyPanel](#destroypanel10) to release resources after use. **createPanel** and **destroyPanel** must be called in pairs.

Core capability overview:

- Page loading: Use [setUiContent](#setuicontent10) to load keyboard page content for the panel. It supports loading regular pages and pages associated with LocalStorage.

- Panel showing/hiding: Use [show](#show10) to show the panel and [hide](#hide10) to hide the panel. Panel visibility changes can also be monitored via **on('show')** or **on('hide')**.

- Size and position adjustment: Use [resize](#resize10) to adjust panel size, [moveTo](#moveto10) to reposition the panel, [startMoving](#startmoving15) to drag the panel, and [adjustPanelRect](#adjustpanelrect12)/[updatePanelRect](#updatepanelrect)/[updateRegion](#updateregion15) to adjust the panel region.

- Mode setting: Use [changeFlag](#changeflag10) to switch between fixed and floating panel states, [setPrivacyMode](#setprivacymode11) to set privacy mode, and [setImmersiveMode](#setimmersivemode15)/[getImmersiveMode](#getimmersivemode15) to set/obtain immersive mode.

- Event listening: Use **on('show')**, **on('hide')**, and **on('sizeChange')** to listen for panel state change events.

Panel lifecycle:

1. Create a **Panel** instance via [createPanel](#createpanel10) of **InputMethodAbility**, specifying the panel type and flags.

2. Call [setUiContent](#setuicontent10) to load keyboard page content.

3. Call [show](#show10) to display the panel for user interaction.

4. Call APIs such as **resize**, **moveTo**, and **changeFlag** to dynamically adjust the panel as required.

5. Call [destroyPanel](#destroypanel10) to destroy the panel after using the instance and release resources.

In the following API examples, you must first use [createPanel](#createpanel10) to obtain a **Panel** instance, and then call the APIs using the obtained instance.

### setUiContent<sup>10+</sup>

setUiContent(path: string, callback: AsyncCallback&lt;void&gt; ): void

Loads content from a page to this input method panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  | Path of the target page. It is recommended that the path length does not exceed 1,024 characters.|
| callback | AsyncCallback&lt;void&gt;  | Yes  | Callback used to return the result. If the panel page content is loaded successfully, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Set the input method panel content.
// The panel object is obtained via the createPanel API. For details, see the createPanel example.
panel.setUiContent('pages/page2/page2', (err: BusinessError) => {
  if (err) {
    console.error(`Failed to setUiContent. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the content.');
});
```

### setUiContent<sup>10+</sup>

setUiContent(path: string): Promise&lt;void&gt; 

Loads content from a page to this input method panel. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  | Path of the target page. It is recommended that the path length does not exceed 1,024 characters. |

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise&lt;void&gt;  | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.setUiContent('pages/page2/page2').then(() => {
  console.info('Succeeded in setting the content.');
}).catch((err: BusinessError) => {
  console.error(`Failed to setUiContent. Code is ${err.code}, message is ${err.message}`);
});
```

### setUiContent<sup>10+</sup>

setUiContent(path: string, storage: LocalStorage, callback: AsyncCallback&lt;void&gt; ): void

Loads content from a page associated with LocalStorage to this input method panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes | Path of the page associated with LocalStorage. It is recommended that the path length does not exceed 1,024 characters. |
| storage | [LocalStorage](../apis-arkui/arkui-ts/ts-state-management.md#localstorage9) | Yes | Storage unit that stores mutable and immutable state properties within the app scope. |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. If the panel page content is loaded successfully, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Create and initialize the LocalStorage object.
let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
panel.setUiContent('pages/page2/page2', storage, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to setUiContent. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting the content.');
});
```

### setUiContent<sup>10+</sup>

setUiContent(path: string, storage: LocalStorage): Promise&lt;void&gt; 

Loads content from a page associated with LocalStorage to this panel. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| path | string | Yes  | Path of the target page. It is recommended that the path length does not exceed 1,024 characters. |
| storage | [LocalStorage](../apis-arkui/arkui-ts/ts-state-management.md#localstorage9) | Yes  | Storage unit that stores mutable and immutable state properties within the app scope.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise&lt;void&gt;  | Promise used to return the result. No value is returned. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Create and initialize the LocalStorage object.
let storage: LocalStorage = new LocalStorage();
storage.setOrCreate('storageSimpleProp', 121);
panel.setUiContent('pages/page2/page2', storage).then(() => {
  console.info('Succeeded in setting the content.');
}).catch((err: BusinessError) => {
  console.error(`Failed to setUiContent. Code is ${err.code}, message is ${err.message}`);
});
```

### resize<sup>10+</sup>

resize(width: number, height: number, callback: AsyncCallback&lt;void&gt; ): void

Resizes this input method panel. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The panel width cannot exceed the screen width, and the panel height cannot be 0.7 times higher than the screen height.
>
> When the **PanelFlag** of a smartphone is **FLG_FLOATING** and the panel width is between 0 and 288 vp, the function buttons at the bottom of the panel will dynamically adjust their size according to the panel width. To ensure the optimal user experience, it is recommended that the panel width be no less than 90 vp.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| width | number | Yes | Width of the target panel, in px. The value must be an integer greater than or equal to 0 and must not exceed the screen width. If the value is out of range, error code 401 is returned. |
| height | number | Yes | Height of the target panel, in px. The value must be an integer greater than or equal to 0 and must not exceed 0.7 times the screen height. If the value is out of range, error code 401 is returned. |
| callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. If the panel size is changed successfully, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Change the input method panel size.
panel.resize(500, 1000, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to resize panel. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in changing the panel size.');
});
```

### resize<sup>10+</sup>

resize(width: number, height: number): Promise&lt;void&gt; 

Resizes this input method panel. This API uses a promise to return the result.

> **NOTE**
>
> The panel width cannot exceed the screen width, and the panel height cannot be 0.7 times higher than the screen height.
>
> When the **PanelFlag** of a smartphone is **FLG_FLOATING** and the panel width is between 0 and 288 vp, the function buttons at the bottom of the panel will dynamically adjust their size according to the panel width. To ensure the optimal user experience, it is recommended that the panel width be no less than 90 vp.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| width | number | Yes   | Width of the target panel, in px. The value must be an integer greater than or equal to 0 and must not exceed the screen width. If the value is out of range, error code 401 is returned.|
| height | number | Yes   | Height of the target panel, in px. The value must be an integer greater than or equal to 0 and must not exceed 0.7 times the screen height. If the value is out of range, error code 401 is returned.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise&lt;void&gt;  | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Change the input method panel size.
panel.resize(500, 1000).then(() => {
  console.info('Succeeded in changing the panel size.');
}).catch((err: BusinessError) => {
  console.error(`Failed to resize panel. Code is ${err.code}, message is ${err.message}`);
});
```

### moveTo<sup>10+</sup>

moveTo(x: number, y: number, callback: AsyncCallback&lt;void&gt; ): void

Moves this input method panel to the specified position. This API uses an asynchronous callback to return the result. This API does not work on panels in the [FLG_FIXED](#panelflag10) state.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| x | number | Yes | Distance to move along the horizontal axis, in px. This parameter must be an integer. A value greater than 0 indicates moving right; a value less than 0 indicates moving left. Error code 401 is returned if the value is outside the screen bounds.|
| y | number | Yes | Distance to move along the vertical axis, in px. This parameter must be an integer. A value greater than 0 indicates moving down; a value less than 0 indicates moving up. Error code 401 is returned if the value is outside the screen bounds.|
| callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. If the panel is moved successfully, **err** is **undefined**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Move the input method panel position.
panel.moveTo(300, 300, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to move panel. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in moving the panel.');
});
```

### moveTo<sup>10+</sup>

moveTo(x: number, y: number): Promise&lt;void&gt; 

Moves this input method panel to the specified position. This API uses a promise to return the result. This API does not work on panels in the [FLG_FIXED](#panelflag10) state.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| x | number | Yes  |Distance to move along the horizontal axis, in px. A positive value indicates moving rightwards. The value must be an integer.|
| y | number | Yes  |Distance to move along the vertical axis, in px. A positive value indicates moving downwards. The value must be an integer.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise&lt;void&gt;  | Promise used to return the result. No value is returned. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Move the input method panel position.
panel.moveTo(300, 300).then(() => {
  console.info('Succeeded in moving the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to move panel. Code is ${err.code}, message is ${err.message}`);
});
```

### startMoving<sup>15+</sup>

startMoving(): void

Sends a move command to the window to put the panel into a draggable state. It does not produce an actual movement effect; the panel moves only when the user drags it with the mouse.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 801 | capability not supported. [since 18] |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800013 | window manager service error. |
| 12800017 | invalid panel type or panel flag. |

**Example**

```ts
panel.startMoving();
```

### getDisplayId<sup>15+</sup>

getDisplayId(): Promise&lt;number&gt;

Obtains the display Id of the current window. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise&lt;number&gt;| Promise used to return the display Id of the window. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800013 | window manager service error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.getDisplayId().then((result: number) => {
  console.info('get displayId:' + result);
}).catch((err: BusinessError) => {
  console.error(`Failed to get displayId. Code is ${err.code}, message is ${err.message}`);
});
```

### show<sup>10+</sup>

show(callback: AsyncCallback&lt;void&gt; ): void

Shows this input method panel. This API uses an asynchronous callback to return the result. It can be called when the input method is bound to the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void&gt;  | Yes   | Callback used to return the result. If the panel is displayed successfully, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.show((err: BusinessError) => {
  if (err) {
    console.error(`Failed to show panel. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in showing the panel.');
});
```

### show<sup>10+</sup>

show(): Promise&lt;void&gt; 

Shows this input method panel. This API uses a promise to return the result. It can be called when the input method is bound to the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise&lt;void&gt;  | Promise object that returns no result. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.show().then(() => {
  console.info('Succeeded in showing the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show panel. Code is ${err.code}, message is ${err.message}`);
});
```

### hide<sup>10+</sup>

hide(callback: AsyncCallback&lt;void&gt; ): void

Hides this panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| callback | AsyncCallback&lt;void&gt;  | Yes   | Callback used to return the result. If the panel is hidden successfully, **err** is **undefined**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.hide((err: BusinessError) => {
  if (err) {
    console.error(`Failed to hide panel. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in hiding the panel.');
});
```

### hide<sup>10+</sup>

hide(): Promise&lt;void&gt; 

Hides this panel. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise&lt;void&gt;  | Promise object that returns no result. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.hide().then(() => {
  console.info('Succeeded in hiding the panel.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide panel. Code is ${err.code}, message is ${err.message}`);
});
```

### adjustPanelRect<sup>12+</sup>

adjustPanelRect(flag: PanelFlag, rect: PanelRect): void

Adjusts the panel rectangle. After the API is called, the adjust request is submitted to the input method framework, but the execution is not complete.

> **NOTE**
>
> This API applies only to panels of the **SOFT_KEYBOARD** type with the **FLG_FIXED** or **FLG_FLOATING** state.
>
> This is a synchronous API. A successful return only indicates that the system has received the configuration request, not that the configuration is complete. To detect exceptions during execution, use [updatePanelRect](#updatepanelrect) or [updatePanelRectSync](#updatepanelrectsync).
>
> On mobile devices, when **PanelFlag** is set to **FLG_FLOATING** and the panel width ranges from 0 to 288 vp, the function keys at the bottom of the panel are resized dynamically according to panel width. For optimal user experience, it is recommended that the panel width be no less than 90 vp.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| flag | [PanelFlag](#panelflag10) | Yes| Target panel state type. The value can be **FLG_FIXED** or **FLG_FLOATING**.|
| rect | [PanelRect](#panelrect12) | Yes | Target panel's x coordinate, y coordinate, width, and height in both landscape and portrait orientations. In fixed mode, the height cannot exceed 70% of the screen height, and the width cannot exceed the screen width. In floating mode, the height cannot exceed the screen height, and the width cannot exceed the screen width. Error code 401 is returned when the value is out of range. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800013 | window manager service error. |

**Example**

```ts
import { window } from '@kit.ArkUI';

// Define the rectangular area of the panel in landscape mode.
let landscapeRect: window.Rect = {
  left: 100,
  top: 100,
  width: 400,
  height: 400
};

// Define the rectangular area of the panel in portrait mode.
let portraitRect: window.Rect = {
  left: 200,
  top: 200,
  width: 300,
  height: 300
};

// Set the panel state to fixed.
let panelFlag: inputMethodEngine.PanelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
// Configure the rectangular areas of the panel for landscape and portrait orientations.
let panelRect: inputMethodEngine.PanelRect = {
  landscapeRect: landscapeRect,
  portraitRect: portraitRect
};
// Preset the landscape and portrait dimensions of the input method app panel.
panel.adjustPanelRect(panelFlag, panelRect);
```

### adjustPanelRect<sup>15+</sup>

adjustPanelRect(flag: PanelFlag, rect: EnhancedPanelRect): void

Presets the size, position, custom avoidance area, and hot zone of the input method app panel for landscape and portrait orientations.

> **NOTE**
>
> This applies only to panels of the **SOFT_KEYBOARD** type with the **FLG_FIXED** or **FLG_FLOATING** state. This API is compatible with the calling method of [adjustPanelRect](#adjustpanelrect12). If the input parameter **rect** contains only the **landscapeRect** and **portraitRect** properties, [adjustPanelRect](#adjustpanelrect12) is called by default.
>
> This is a synchronous API. A successful return only indicates that the system has received the configuration request, not that the configuration is complete. To detect exceptions during execution, use [updatePanelRect](#updatepanelrect-1) or [updatePanelRectSync](#updatepanelrectsync-1).
>
> On mobile devices, when **PanelFlag** is set to **FLG_FLOATING** and the panel width ranges from 0 to 288 vp, the function keys at the bottom of the panel are resized dynamically according to panel width. For optimal user experience, it is recommended that the panel width be no less than 90 vp.
>
> When the **com.ohos.sceneboard** process does not exist, the effective range of the input method hot zone remains consistent with the soft keyboard area.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type                                     | Mandatory| Description                                                      |
| ------ | ----------------------------------------- | ---- | ---------------------------------------------------------- |
| flag   | [PanelFlag](#panelflag10)                 | Yes  |  Target panel state type. The value can be **FLG_FIXED** or **FLG_FLOATING**.         |
| rect   | [EnhancedPanelRect](#enhancedpanelrect15) | Yes  | Position, size, avoidance area, and hot zone of the target panel for landscape and portrait orientations.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 12800013 | window manager service error.                                |
| 12800017 | invalid panel type or panel flag.                            |

**Example:**

```ts
import { window } from '@kit.ArkUI';

let landscapeRect1: window.Rect = {
  left: 300,
  top: 650,
  width: 2000,
  height: 500
};
let landscapeInputRegion: Array<window.Rect> = [landscapeRect1];

let portraitRect1: window.Rect = {
  left: 0,
  top: 1800,
  width: 1200,
  height: 800
}
let portraitInputRegion: Array<window.Rect> = [portraitRect1];
// Target panel state type.
let panelFlag: inputMethodEngine.PanelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
// The position, size, avoidance area, and hot zone of the target panel for landscape and portrait orientations.
let panelRect: inputMethodEngine.EnhancedPanelRect = {
  landscapeAvoidY: 650,
  landscapeInputRegion: landscapeInputRegion,
  portraitAvoidY: 1800,
  portraitInputRegion: portraitInputRegion,
  fullScreenMode: true
};
panel.adjustPanelRect(panelFlag, panelRect);
```

### updatePanelRect

updatePanelRect(flag: PanelFlag, rect: PanelRect): Promise&lt;void&gt; 

Presets the landscape and portrait dimensions of the input method app. This API uses a promise to return the result.

> **NOTE**
>
> This applies only to panels of the **SOFT_KEYBOARD** type with the **FLG_FIXED** or **FLG_FLOATING** state.
>
> This is an asynchronous API. A successful return only indicates that the system has received the configuration request, not that the configuration is complete.
>
> On mobile devices, when **PanelFlag** is set to **FLG_FLOATING** and the panel width ranges from 0 to 288 vp, the function keys at the bottom of the panel are resized dynamically according to panel width. For optimal user experience, it is recommended that the panel width be no less than 90 vp.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| flag | [PanelFlag](#panelflag10) | Yes  | Target panel state type. The value can be **FLG_FIXED** or **FLG_FLOATING**. |
| rect | [PanelRect](#panelrect12) | Yes  |  Target panel's x coordinate, y coordinate, width, and height in both landscape and portrait orientations. In fixed mode, the height cannot exceed 70% of the screen height, and the width cannot exceed the screen width. In floating mode, the height cannot exceed the screen height, and the width cannot exceed the screen width. Error code 401 is returned when the value is out of range.|

**Return value**

| Type   | Description               |
| ------- |------------------|
| Promise&lt;void&gt;  | Promise object that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| -------- | ------------------------------------------------------- |
| 12800013 | window manager service error. |

**Example**

```ts
import { window } from '@kit.ArkUI';

let landscapeRect: window.Rect = {
  left: 100,
  top: 100,
  width: 400,
  height: 400
};

let portraitRect: window.Rect = {
  left: 200,
  top: 200,
  width: 300,
  height: 300
};

// Target panel state type.
let panelFlag: inputMethodEngine.PanelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
// The x coordinate, y coordinate, width, and height of the target panel for landscape and portrait orientations.
let panelRect: inputMethodEngine.PanelRect = {
  landscapeRect: landscapeRect,
  portraitRect: portraitRect
};
panel.updatePanelRect(panelFlag, panelRect);
```

### updatePanelRect

updatePanelRect(flag: PanelFlag, rect: EnhancedPanelRect): Promise&lt;void&gt; 

Presets the size, position, custom avoidance area, and hot zone of the input method app panel for landscape and portrait orientations. This API uses a promise to return the result.

> **NOTE**
>
> This applies only to panels of the **SOFT_KEYBOARD** type with the **FLG_FIXED** or **FLG_FLOATING** state. This API is compatible with the calling method of [adjustPanelRect](#adjustpanelrect12). If the input parameter **rect** contains only the **landscapeRect** and **portraitRect** properties, [adjustPanelRect](#adjustpanelrect12) is called by default.
>
> This is an asynchronous API. A successful return only indicates that the system has received the configuration request, not that the configuration is complete.
>
> On mobile devices, when **PanelFlag** is set to **FLG_FLOATING** and the panel width ranges from 0 to 288 vp, the function keys at the bottom of the panel are resized dynamically according to panel width. For optimal user experience, it is recommended that the panel width be no less than 90 vp.
>
> When the **com.ohos.sceneboard** process does not exist, the effective range of the input method hot zone remains consistent with the soft keyboard area.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name | Type                                      | Mandatory | Description                                                        |
| ---- | ----------------------------------------- | --------- | ------------------------------------------------------------------ |
| flag | [PanelFlag](#panelflag10)                 | Yes       | Target panel state type. The value can be **FLG_FIXED** or **FLG_FLOATING**.   |
| rect | [EnhancedPanelRect](#enhancedpanelrect15) | Yes       | Position, size, avoidance area, and hot zone of the target panel for landscape and portrait orientations. |

**Return value**

| Type   | Description               |
| ------- |------------------|
| Promise&lt;void&gt;  | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 12800013 | window manager service error.                                |
| 12800017 | invalid panel type or panel flag.                            |

**Example**

```ts
import { window } from '@kit.ArkUI';

let landscapeRect1: window.Rect = {
  left: 300,
  top: 650,
  width: 2000,
  height: 500
};
let landscapeInputRegion: Array<window.Rect> = [landscapeRect1];

let portraitRect1: window.Rect = {
  left: 0,
  top: 1800,
  width: 1200,
  height: 800
}
let portraitInputRegion: Array<window.Rect> = [portraitRect1];
// Target panel state type.
let panelFlag: inputMethodEngine.PanelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
// The position, size, avoidance area, and hot zone of the target panel for landscape and portrait orientations.
let panelRect: inputMethodEngine.EnhancedPanelRect = {
  landscapeAvoidY: 650,
  landscapeInputRegion: landscapeInputRegion,
  portraitAvoidY: 1800,
  portraitInputRegion: portraitInputRegion,
  fullScreenMode: true
};
panel.updatePanelRect(panelFlag, panelRect);
```

### updatePanelRectSync

updatePanelRectSync(flag: PanelFlag, rect: PanelRect): void

Presets the landscape and portrait sizes of the input method app.
> **NOTE**
> 
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [updatePanelRect](#updatepanelrect) instead.
>
> This applies only to panels of the **SOFT_KEYBOARD** type with the **FLG_FIXED** or **FLG_FLOATING** state.
>
> This is a synchronous API. A successful return indicates that the system has received the configuration request and the configuration is complete.
>
> On mobile devices, when **PanelFlag** is set to **FLG_FLOATING** and the panel width ranges from 0 to 288 vp, the function keys at the bottom of the panel are resized dynamically according to panel width. For optimal user experience, it is recommended that the panel width be no less than 90 vp.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type                   | Mandatory | Description     |
| -------- | ---------------------- | ---- | -------- |
| flag | [PanelFlag](#panelflag10) | Yes | Target panel state type. The value can be **FLG_FIXED** or **FLG_FLOATING**. |
| rect | [PanelRect](#panelrect12) | Yes   | Target panel's x coordinate, y coordinate, width, and height in both landscape and portrait orientations. In fixed mode, the height cannot exceed 70% of the screen height, and the width cannot exceed the screen width. In floating mode, the height cannot exceed the screen height, and the width cannot exceed the screen width. Error code 401 is returned when the value is out of range.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| -------- | ------------------------------------------------------- |
| 12800013 | window manager service error. |

**Example**

```ts
import { window } from '@kit.ArkUI';

let landscapeRect: window.Rect = {
  left: 100,
  top: 100,
  width: 400,
  height: 400
};

let portraitRect: window.Rect = {
  left: 200,
  top: 200,
  width: 300,
  height: 300
};

// Target panel state type.
let panelFlag: inputMethodEngine.PanelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
// The x coordinate, y coordinate, width, and height of the target panel for landscape and portrait orientations.
let panelRect: inputMethodEngine.PanelRect = {
  landscapeRect: landscapeRect,
  portraitRect: portraitRect
};
panel.updatePanelRectSync(panelFlag, panelRect);
```

### updatePanelRectSync

updatePanelRectSync(flag: PanelFlag, rect: EnhancedPanelRect): void

Presets the size, position, custom avoidance area, and hot zone of the input method app panel for landscape and portrait orientations.
> **NOTE**
> 
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [updatePanelRect](#updatepanelrect) instead.
>
> This applies only to panels of the **SOFT_KEYBOARD** type with the **FLG_FIXED** or **FLG_FLOATING** state. This API is compatible with the calling method of [adjustPanelRect](#adjustpanelrect12). If the input parameter **rect** contains only the **landscapeRect** and **portraitRect** properties, [adjustPanelRect](#adjustpanelrect12) is called by default.
>
> This is a synchronous API. A successful return indicates that the system has received the configuration request and the configuration is complete.
>
> On mobile devices, when **PanelFlag** is set to **FLG_FLOATING** and the panel width ranges from 0 to 288 vp, the function keys at the bottom of the panel are resized dynamically according to panel width. For optimal user experience, it is recommended that the panel width be no less than 90 vp.
>
> When the **com.ohos.sceneboard** process does not exist, the effective range of the input method hot zone remains consistent with the soft keyboard area.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**System capability:** SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name | Type                                      | Mandatory | Description                                                       |
| ------ | ----------------------------------------- | ---- | ---------------------------------------------------------- |
| flag   | [PanelFlag](#panelflag10)                 | Yes   | Target panel state type. The value can be **FLG_FIXED** or **FLG_FLOATING**.          |
| rect   | [EnhancedPanelRect](#enhancedpanelrect15) | Yes   | Position, size, avoidance area, and hot zone of the target panel for landscape and portrait orientations. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message |
| -------- | ------------------------------------------------------------ |
| 12800013 | window manager service error.                                |
| 12800017 | invalid panel type or panel flag.                            |

**Example**

```ts
import { window } from '@kit.ArkUI';

let landscapeRect1: window.Rect = {
  left: 300,
  top: 650,
  width: 2000,
  height: 500
};
let landscapeInputRegion: Array<window.Rect> = [landscapeRect1];

let portraitRect1: window.Rect = {
  left: 0,
  top: 1800,
  width: 1200,
  height: 800
}
let portraitInputRegion: Array<window.Rect> = [portraitRect1];
// Target panel state type.
let panelFlag: inputMethodEngine.PanelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
// The position, size, avoidance area, and hot zone of the target panel for landscape and portrait orientations.
let panelRect: inputMethodEngine.EnhancedPanelRect = {
  landscapeAvoidY: 650,
  landscapeInputRegion: landscapeInputRegion,
  portraitAvoidY: 1800,
  portraitInputRegion: portraitInputRegion,
  fullScreenMode: true
};
panel.updatePanelRectSync(panelFlag, panelRect);
```

### updateRegion<sup>15+</sup>

updateRegion(inputRegion: Array&lt;window.Rect&gt;): void

Updates the hot zone on the input method panel in the current state.

> **NOTE**
>
> This applies only to panels of the **SOFT_KEYBOARD** type with the **FLG_FIXED** or **FLG_FLOATING** state.
>
> This is a synchronous API. A successful return only indicates that the system has received the request to update the hot zone, not that the hot zone update is complete.
>
> When the **com.ohos.sceneboard** process does not exist, the effective range of the input method hot zone remains consistent with the soft keyboard area.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name     | Type                                                        | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| inputRegion | Array&lt;[window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)&gt; | Yes  | Region for receiving input events.<br>- The array size is limited to [1, 4].<br>- The input hot zone is relative to the left vertex of the input method panel window.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 12800013 | window manager service error.                                |
| 12800017 | invalid panel type or panel flag.                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let inputRegion: Array<window.Rect> = [{
  left: 300,
  top: 650,
  width: 2000,
  height: 500
}];
panel.updateRegion(inputRegion);
```

### on('show')<sup>10+</sup>

on(type: 'show', callback: () => void): void

Listens for the display state of the current panel. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| type | string | Yes| Event type, which is **'show'**.|
| callback | () => void | Yes  | Callback used to return the result.|

**Example**

```ts
panel.on('show', () => {
  console.info('Panel is showing.');
});
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
panel.on('hide', () => {
  console.info('Panel is hiding.');
});
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

// Listen for panel size change events.
panel.on('sizeChange', (windowSize: window.Size) => {
  console.info(`panel size changed, width: ${windowSize.width}, height: ${windowSize.height}`);
});

// Listen for panel size change events (with keyboard area parameters).
panel.on('sizeChange', (windowSize: window.Size, keyboardArea: inputMethodEngine.KeyboardArea) => {
  console.info(`panel size changed, windowSize: ${windowSize.width}, ${windowSize.height}, ` +
    `keyboardArea: ${keyboardArea.top}, ${keyboardArea.bottom}, ${keyboardArea.left}, ${keyboardArea.right}`);
});
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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
panel.off('show');
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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
panel.off('hide');
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
| callback | [SizeChangeCallback](#sizechangecallback15) | No | Callback used to return the current soft keyboard panel size, including the width and height. If this parameter is not specified, this API unregisters all callbacks for the specified type. |

**Example**

```ts
import { window } from '@kit.ArkUI';

panel.off('sizeChange', (windowSize: window.Size) => {
  console.info(`panel size changed, width: ${windowSize.width}, height: ${windowSize.height}`);
});
```

### changeFlag<sup>10+</sup>

changeFlag(flag: PanelFlag): void

Changes the state type ([PanelFlag](#panelflag10)) of this input method panel. This API only works for [SOFT_KEYBOARD](#paneltype10) panels.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| flag | [PanelFlag](#panelflag10) | Yes| Type of the state of the target panel.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
let panelFlag: inputMethodEngine.PanelFlag = inputMethodEngine.PanelFlag.FLG_FIXED;
panel.changeFlag(panelFlag);
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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
let isPrivacyMode: boolean = true;
panel.setPrivacyMode(isPrivacyMode);
```

### setImmersiveMode<sup>15+</sup>

setImmersiveMode(mode: ImmersiveMode): void

Sets the immersive mode of the input method app. The mode can only be set to **NONE_IMMERSIVE**, **LIGHT_IMMERSIVE**, or **DARK_IMMERSIVE**.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| mode | [ImmersiveMode](#immersivemode15) | Yes  | Immersive mode.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.           |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800013  | window manager service error.                          |

**Example**

```ts
panel.setImmersiveMode(inputMethodEngine.ImmersiveMode.LIGHT_IMMERSIVE);
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
let mode: inputMethodEngine.ImmersiveMode = panel.getImmersiveMode();
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
let effect: inputMethodEngine.ImmersiveEffect = {
  gradientHeight: 100,
  gradientMode: inputMethodEngine.GradientMode.LINEAR_GRADIENT
}
panel.setImmersiveEffect(effect);
```

### setKeepScreenOn<sup>20+</sup>

setKeepScreenOn(isKeepScreenOn: boolean): Promise&lt;void&gt; 

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
| Promise&lt;void&gt;  | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 12800013 | window manager service error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

panel.setKeepScreenOn(true).then(() => {
  console.info(`setKeepScreenOn success.`);
}).catch((error: BusinessError) => {
  console.error(`setKeepScreenOn failed, code: ${error.code}, message: ${error.message}`);
})
```

### getSystemPanelCurrentInsets<sup>21+</sup>

getSystemPanelCurrentInsets(displayId: number): Promise&lt;SystemPanelInsets&gt;

Obtains the offset area of the soft keyboard relative to the system panel under the current state of the specified screen (for example, folded or unfolded) and the current state of the input method keyboard (for example, floating or fixed). This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| displayId | number | Yes  | Display ID of the screen where the input method keyboard is located. It can be obtained by calling [getDisplayId](#getdisplayid15).|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise&lt;[SystemPanelInsets](#systempanelinsets21)&gt;  | Promise used to return the result. The offset area between the input method keyboard and the system panel. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 12800013 | window manager service error. |
| 12800017 | invalid panel type or panel flag. Possible causes: 1. Current panel's type is not SOFT_KEYBOARD.  2. Panel's flag is not FLG_FIXED or FLG_FLOATING. |
| 12800022 | invalid displayId. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethodEngine } from '@kit.IMEKit';

let inputMethodAbility: inputMethodEngine.InputMethodAbility = inputMethodEngine.getInputMethodAbility();
let panelConfig: inputMethodEngine.PanelInfo = {
  type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
  flag: inputMethodEngine.PanelFlag.FLG_FIXED
}
// The following logic needs to be executed in InputMethodExtensionAbility. this.context is the context of InputMethodExtensionAbility.
// Create the input method panel.
inputMethodAbility.createPanel(this.context, panelConfig).then( (panel: inputMethodEngine.Panel) =>{
  panel.getDisplayId().then((displayId: number) => {
    panel.getSystemPanelCurrentInsets(displayId).then((insets: inputMethodEngine.SystemPanelInsets) => {
      console.info(`getSystemPanelCurrentInsets success, insets is { left: ${insets.left}, right: ${insets.right}, bottom: ${insets.bottom} }`);
    }).catch((error: BusinessError) => {
      console.error(`getSystemPanelCurrentInsets failed, code: ${error.code}, message: ${error.message}`);
    })
  });
})
```

### setSystemPanelButtonColor<sup>22+</sup>

setSystemPanelButtonColor(fillColor: string | undefined, backgroundColor: string | undefined): Promise&lt;void&gt;

Sets the color of the function buttons and their background color on the current panel. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                  | Mandatory| Description    |
| -------- | ---------------------- | ---- | -------- |
| fillColor | string\|undefined | Yes  | Color of the function buttons. The value can be [#01000000, #FFFFFFFF] or [#000000, #FFFFFF]. The value of the fully transparent alpha channel (**#00xxxxxx**) is not supported.|
| backgroundColor | string\|undefined | Yes  | Background color of the function buttons. The value can be [#01000000, #FFFFFFFF] or [#000000, #FFFFFF]. The value of the fully transparent alpha channel (#00xxxxxx) is not supported.|

**Return value**

| Type  | Description                            |
| ------- | ------------------------------ |
| Promise&lt;void&gt;  | Promise that returns no value.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Ensure that a panel instance exists. You can use inputMethodEngine.getInputMethodAbility().createPanel(...) to create a panel instance.
try {
  let fillColor = "#FFFF00";
  let backgroundColor = "#0000FF";
  panel.setSystemPanelButtonColor(fillColor, backgroundColor).then(() => {
    console.info(`setSystemPanelButtonColor success.`);
  }).catch((error: BusinessError) => {
    console.error(`setSystemPanelButtonColor failed, code: ${error.code}, message: ${error.message}`);
  })
} catch (err) {
  let error = err as BusinessError;
  console.error(`setSystemPanelButtonColor failed, code: ${error.code}, message: ${error.message}`);
}
```

## KeyboardController

You must first use [on('inputStart')](#oninputstart9) to obtain a **KeyboardController** instance, and then use this instance to call the following APIs.

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
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

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
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.hide().then(() => {
  console.info('Succeeded in hiding keyboard.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide. Code:${err.code}, message:${err.message}`);
});
```

### hideKeyboard<sup>(deprecated)</sup>

hideKeyboard(callback: AsyncCallback&lt;void&gt;): void

Hides the keyboard. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.KeyboardController.hide](#hide9) instead.

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
    console.error(`Failed to hideKeyboard. Code is ${err.code}, message is ${err.message}`);
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
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.KeyboardController.hide](#hide9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type            | Description                     |
| ---------------- | ------------------------- |
| Promise&lt;void&gt;| Promise that returns no value. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

keyboardController.hideKeyboard().then(() => {
  console.info('Succeeded in hiding keyboard.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hideKeyboard. Code is ${err.code}, message is ${err.message}`);
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
| Promise&lt;void&gt; | Promise that returns no value. |

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
  console.error(`Failed to exit current input type. Code:${err.code}, message:${err.message}`);
});
```

## SecurityMode<sup>11+</sup>

Describes the security mode.

**System capability:** SystemCapability.MiscServices.InputMethodFramework

| Name | Value  | Description                                        |
| ----- | ---- | -------------------------------------------- |
| BASIC | 0    | Basic access mode, where network access is restricted.|
| FULL  | 1    | Full access mode, where network access is not restricted.      |

## ExtendAction<sup>10+</sup>

Describes the type of the extended edit action on the text box.

**System capability:** SystemCapability.MiscServices.InputMethodFramework

| Name| Value|Description|
| -------- | -------- |-------- |
| SELECT_ALL  | 0 |Select all.|
| CUT  | 3 |Cut.|
| COPY  | 4 |Copy.|
| PASTE  | 5 |Paste.|

## Direction<sup>10+</sup>

Enumerates the directions of cursor movement of the input method.

**System capability:** SystemCapability.MiscServices.InputMethodFramework

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
inputMethodEngine.getInputMethodAbility()
  .on('inputStart',
    (keyboardController: inputMethodEngine.KeyboardController, inputClient: inputMethodEngine.InputClient) => {
      let messageHandler: inputMethodEngine.MessageHandler = {
        onTerminated(): void {
          console.info('OnTerminated.');
        },
        onMessage(msgId: string, msgParam?: ArrayBuffer): void {
          console.info(`recv message, msgId is ${msgId}, msgParam is ${JSON.stringify(msgParam)}`);
        }
      }
      inputClient.recvMessage(messageHandler);
    });
```

### onTerminated<sup>15+</sup>

onTerminated(): void

Listens for MessageHandler termination.

> **NOTE**
>
> When an app registers a new [MessageHandler](#messagehandler15) object, the [onTerminated](#onterminated15) callback of the penultimate registered [MessageHandler](#messagehandler15) object is triggered.
>
> When an app unregisters a [MessageHandler](#messagehandler15) object, the [onTerminated](#onterminated15) callback of the registered [MessageHandler](#messagehandler15) object is triggered.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Example**

```ts
inputMethodEngine.getInputMethodAbility()
  .on('inputStart',
    (keyboardController: inputMethodEngine.KeyboardController, inputClient: inputMethodEngine.InputClient) => {
      let messageHandler: inputMethodEngine.MessageHandler = {
        onTerminated(): void {
          console.info('OnTerminated.');
        },
        onMessage(msgId: string, msgParam?: ArrayBuffer): void {
          console.info(`recv message, msgId is ${msgId}, msgParam is ${JSON.stringify(msgParam)}`);
        }
      }
      client.recvMessage(messageHandler);
    });
```

## InputClient<sup>9+</sup>

Represents the input method client object for the edit box currently bound to the input method app. An **InputClient** instance is obtained through the [on('inputStart')](#getforward9) event callback of **InputMethodAbility**. Each binding event corresponds to one **InputClient** instance which the input method app uses to interact with the edit box for text operations.

Core capability overview:

- Text retrieval: Obtain the text before the cursor through [getForward](#getforward9) or [getForwardSync](#getforwardsync10), and the text after the cursor through [getBackward](#getbackward9) or [getBackwardSync](#getbackwardsync10), for analyzing the entered content and providing intelligent completion.

- Text editing: Insert text through [insertText](#inserttext9) or [insertTextSync](#inserttextsync10), delete text before the cursor through [deleteForward](#deleteforward9) or [deleteForwardSync](#deleteforwardsync10), and delete text after the cursor through [deleteBackward](#deletebackward9) or [deleteBackwardSync](#deletebackwardsync10).

- Function keys and cursor: Send function keys (such as the Enter key) through [sendKeyFunction](#sendkeyfunction9), and move the cursor through [moveCursor](#movecursor9) or [moveCursorSync](#movecursorsync10).

- Selection operations: Select text by range through [selectByRange](#selectbyrange10) or [selectByRangeSync](#selectbyrangesync10), and select text by direction through [selectByMovement](#selectbymovement10) or [selectByMovementSync](#selectbymovementsync10).

- Edit box attributes: Obtain edit box attribute information (input type, Enter key type, etc.) through [getEditorAttribute](#geteditorattribute9) or [getEditorAttributeSync](#geteditorattributesync10), and adjust the keyboard layout accordingly.

- Text preview: Set preview text through [setPreviewText](#setpreviewtext12) or [setPreviewTextSync](#setpreviewtextsync12), and end text preview through [finishTextPreview](#finishtextpreview12) or [finishTextPreviewSync](#finishtextpreviewsync12).

- Private communication: Send private commands to the app through [sendPrivateCommand](#sendprivatecommand12), and perform message communication through [sendMessage](#sendmessage15) or [recvMessage](#recvmessage15).

**NOTE**

- The **InputClient** instance is associated with the currently bound edit box. The instance may become invalid when the edit box loses focus or the input method unbinds.

- APIs suffixed with **Sync** are synchronous. They may block the main thread and impair UI interaction. Use them with caution.

You must first use [on('inputStart')](#oninputstart9) to obtain an **InputClient** instance, and then use this instance to call the following APIs.

### sendKeyFunction<sup>9+</sup>

sendKeyFunction(action:number, callback: AsyncCallback&lt;boolean&gt;): void

Sends the function key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Action of the function key.<br>- **0**: invalid key.<br>- **1**: confirm key (Enter key).|
| callback | AsyncCallback&lt;boolean&gt; | Yes | Callback used to return the result. If the function key is sent successfully, **err** is undefined and **data** is **true**; if the function key fails to be sent, **err** is undefined and **data** is **false**; otherwise, an error object is returned. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action: number = 1;

inputClient.sendKeyFunction(action, (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to sendKeyFunction. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  if (result) {
    console.info('Succeeded in sending key function.');
  } else {
    console.error('Failed to sendKeyFunction.');
  }
});
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
| Promise&lt;boolean&gt; | Promise object. If the promise is resolved with **true**, the function key is sent successfully. If the promise is resolved with **false**, sending the function key fails. If the promise is rejected, an error object is thrown, indicating an error occurred during execution. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action: number = 1;
inputClient.sendKeyFunction(action).then((result: boolean) => {
  if (result) {
    console.info('Succeeded in sending key function.');
  } else {
    console.error('Failed to sendKeyFunction.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to sendKeyFunction. Code is ${err.code}, message is ${err.message}`);
});
```

### getForward<sup>9+</sup>

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the fixed-length text before the cursor. This API uses an asynchronous callback to return the result.
Usage scenarios: Analyze the entered text to provide intelligent completion suggestions, check the text format, implement text prediction, and perform text semantic analysis, among others.
Use effect: When the operation is successful, the fixed-length text before the cursor is returned, based on which the input method app can update candidate words or input suggestions.

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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
inputClient.getForward(length, (err: BusinessError, text: string) => {
  if (err) {
    console.error(`Failed to getForward. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in getting forward, text: ' + text);
});
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

| ID | Error Message                    |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
inputClient.getForward(length).then((text: string) => {
  console.info('Succeeded in getting forward, text: ' + text);
}).catch((err: BusinessError) => {
  console.error(`Failed to getForward. Code is ${err.code}, message is ${err.message}`);
});
```

### getForwardSync<sup>10+</sup>

getForwardSync(length:number): string

Obtains the fixed-length text before the cursor.
> **NOTE**
> 
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [getForward](#getforward9-1).

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

| ID | Error Message                      |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
let length: number = 1;
let text: string = inputClient.getForwardSync(length);
console.info(`Succeeded in getting forward, text: ${text}`);
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

| ID | Error Message                    |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
inputClient.getBackward(length, (err: BusinessError, text: string) => {
  if (err) {
    console.error(`Failed to getBackward. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in getting backward, text: ' + text);
});
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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
inputClient.getBackward(length).then((text: string) => {
  console.info('Succeeded in getting backward, text: ' + text);
}).catch((err: BusinessError) => {
  console.error(`Failed to getBackward. Code is ${err.code}, message is ${err.message}`);
});
```

### getBackwardSync<sup>10+</sup>

getBackwardSync(length:number): string

Obtains the fixed-length text after the cursor.
> **NOTE**
> 
>  This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [getBackward](#getbackward9).

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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
let length: number = 1;
let text: string = inputClient.getBackwardSync(length);
console.info(`Succeeded in getting backward, text: ${text}`);
```

### deleteForward<sup>9+</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text before the cursor. This API uses an asynchronous callback to return the result.

Usage scenarios: Implement the Backspace key function, delete input character by character, delete incorrect input, and implement custom deletion logic, among others.

Use effect: When the operation is successful, the fixed-length text before the cursor in the edit box is deleted.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|
| callback | AsyncCallback&lt;boolean&gt; | Yes | Callback used to return the result. If the fixed-length text before the cursor is deleted successfully, **err** is undefined and **data** is **true**; if the deletion fails, **err** is undefined and **data** is **false**; otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
inputClient.deleteForward(length, (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to deleteForward. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  if (result) {
    console.info('Succeeded in deleting forward.');
  } else {
    console.error(`Failed to deleteForward.`);
  }
});
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
| Promise&lt;boolean&gt; | Promise used to return the result. If the promise is resolved with **true**, the fixed-length text before the cursor is deleted successfully. If the promise is resolved with **false**, the deletion fails. If the promise is rejected, an error object is thrown, indicating an error occurred during execution.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
inputClient.deleteForward(length).then((result: boolean) => {
  if (result) {
    console.info('Succeeded in deleting forward.');
  } else {
    console.error('Failed to delete Forward.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to deleteForward. Code is ${err.code}, message is ${err.message}`);
});
```

### deleteForwardSync<sup>10+</sup>

deleteForwardSync(length:number): void

Deletes the fixed-length text before the cursor.
> **NOTE**
> 
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [deleteForward](#deleteforward9).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length, which cannot be less than 0.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
let length: number = 1;
inputClient.deleteForwardSync(length);
```

### deleteBackward<sup>9+</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result.

Usage scenarios: Implement the Delete key function, delete characters after the cursor, quickly correct input, and implement custom deletion logic, among others.

Use effect: When the operation is successful, the fixed-length text after the cursor is deleted.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                        | Mandatory| Description          |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | Yes  | Text length, which cannot be less than 0.    |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
inputClient.deleteBackward(length, (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to deleteBackward. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  if (result) {
    console.info('Succeeded in deleting backward.');
  } else {
    console.error(`Failed to deleteBackward.`);
  }
});
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
| Promise&lt;boolean&gt; | Promise used to return the result. If the promise is resolved with **true**, the fixed-length text after the cursor is deleted successfully. If the promise is resolved with **false**, the deletion fails. If the promise is rejected, an error object is thrown, indicating an error occurred during execution. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
inputClient.deleteBackward(length).then((result: boolean) => {
  if (result) {
    console.info('Succeeded in deleting backward.');
  } else {
    console.error('Failed to deleteBackward.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to deleteBackward. Code is ${err.code}, message is ${err.message}`);
});
```

### deleteBackwardSync<sup>10+</sup>

deleteBackwardSync(length:number): void

Deletes the fixed-length text after the cursor.
> **NOTE**
> 
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [deleteBackward](#deletebackward9-1).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length, which cannot be less than 0. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
let length: number = 1;
inputClient.deleteBackwardSync(length);
```

### insertText<sup>9+</sup>

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

Inserts text. This API uses an asynchronous callback to return the result.

Usage scenarios: Insert candidate words, insert special symbols, implement text auto-completion, and quickly insert common phrases, among others.

Use effect: When the operation is successful, the text is inserted at the cursor position in the edit box.

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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';


inputClient.insertText('test', (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to insertText. Code is ${err.code}, message is ${err.message}`);
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
| Promise&lt;boolean&gt;  |  Promise used to return the result. If the promise is resolved with **true**, the text is inserted successfully. If the promise is resolved with **false**, the insertion fails. If the promise is rejected, an error object is thrown, indicating an error occurred during execution.  |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.insertText('test').then((result: boolean) => {
  if (result) {
    console.info('Succeeded in inserting text.');
  } else {
    console.error('Failed to insertText.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to insertText. Code is ${err.code}, message is ${err.message}`);
});
```

### insertTextSync<sup>10+</sup>

insertTextSync(text: string): void

Inserts text.
> **NOTE**
> 
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [insertText](#inserttext9-1) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| text   | string | Yes  | Text to insert.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800002 | input method engine error. Possible causes: 1.input method panel not created. 2.the input method application does not subscribe to related events. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
inputClient.insertTextSync('test');
```

### getEditorAttribute<sup>9+</sup>

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

Obtains the attribute of the edit box. This API uses an asynchronous callback to return the result.

Usage scenarios: Adjust the input method UI based on the edit box type, provide different input suggestions based on the edit box configuration, implement specific input logic, and adapt to different types of input boxes, among others.

Use effect: The edit box attribute information (including **inputPattern** and **enterKeyType**) is returned, based on which the input method app adjusts the keyboard layout.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name                        | Type                         | Mandatory                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[EditorAttribute](#editorattribute)&gt; | Yes |  Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the attribute of the edit box. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID | Error Message                |
| -------- | -------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getEditorAttribute((err: BusinessError, editorAttribute: inputMethodEngine.EditorAttribute) => {
  if (err) {
    console.error(`Failed to getEditorAttribute. Code is ${err.code}, message is ${err.message}`);
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
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getEditorAttribute().then((editorAttribute: inputMethodEngine.EditorAttribute) => {
  console.info(`editorAttribute.inputPattern:  ${editorAttribute.inputPattern}`);
  console.info(`editorAttribute.enterKeyType:  ${editorAttribute.enterKeyType}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to getEditorAttribute. Code is ${err.code}, message is ${err.message}`);
});
```

### getEditorAttributeSync<sup>10+</sup>

getEditorAttributeSync(): EditorAttribute

Obtains edit box attribute information.
> **NOTE**
>
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [getEditorAttribute](#geteditorattribute9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                               | Description          |
| ----------------------------------- | -------------- |
| [EditorAttribute](#editorattribute) | Attribute information.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
let editorAttribute: inputMethodEngine.EditorAttribute = inputClient.getEditorAttributeSync();
console.info(`editorAttribute.inputPattern:  ${editorAttribute.inputPattern}`);
console.info(`editorAttribute.enterKeyType:  ${editorAttribute.enterKeyType}`);
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number, callback: AsyncCallback&lt;void&gt;): void

Moves the cursor. This API uses an asynchronous callback to return the result.

Usage scenarios: Move the cursor to a specific position, move the cursor up, down, left, or right, quickly locate the cursor, implement custom cursor control, and more.

Use effect: When the operation is successful, the cursor in the edit box moves one step in the specified direction. For the value of **direction**, see [Constants](#constants), where **1** means up, **2** means down, **3** means left, and **4** means right.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type                     | Mandatory| Description          |
| --------- | ------------------------- | ---- | -------------- |
| direction | number                    | Yes  | Direction in which the cursor moves.<br>- **1**: upward.<br>- **2**: downward.<br>- **3**: leftward.<br>- **4**: rightward.<br>The value cannot be less than 0.|
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.   |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.moveCursor(inputMethodEngine.Direction.CURSOR_UP, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to moveCursor. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in moving cursor.');
});
```

### moveCursor<sup>9+</sup>

moveCursor(direction: number): Promise&lt;void&gt;

Moves the cursor. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type  | Mandatory| Description                                                        |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| direction | number | Yes  | Direction in which the cursor moves.<br>- **1**: upward.<br>- **2**: downward.<br>- **3**: leftward.<br>- **4**: rightward.<br>The value cannot be less than 0.|

**Return value** 

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.moveCursor(inputMethodEngine.Direction.CURSOR_UP).then(() => {
  console.info('Succeeded in moving cursor.');
}).catch((err: BusinessError) => {
  console.error(`Failed to moveCursor. Code is ${err.code}, message is ${err.message}`);
});
```

### moveCursorSync<sup>10+</sup>

moveCursorSync(direction: number): void

Moves the cursor.
> **NOTE**
>
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [moveCursor](#movecursor9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type  | Mandatory| Description                                                        |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| direction | number | Yes  | Direction in which the cursor moves.<br>- **1**: upward.<br>- **2**: downward.<br>- **3**: leftward.<br>- **4**: rightward.<br>The value cannot be less than 0.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                  |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
inputClient.moveCursorSync(inputMethodEngine.Direction.CURSOR_UP);
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

| ID | Error Message                  |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Set the replacement range of the preview text to the first character.
// Set the start and end positions of the selected text.
let range: inputMethodEngine.Range = { start: 0, end: 1 };
inputClient.selectByRange(range, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to selectByRange. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in selecting by range.');
});
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
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Set the replacement range of the preview text to the first character.
// Set the start and end positions of the selected text.
let range: inputMethodEngine.Range = { start: 0, end: 1 };
inputClient.selectByRange(range).then(() => {
  console.info('Succeeded in selecting by range.');
}).catch((err: BusinessError) => {
  console.error(`Failed to selectByRange. Code is ${err.code}, message is ${err.message}`);
});
```

### selectByRangeSync<sup>10+</sup>

selectByRangeSync(range: Range): void

Selects text based on the index range.
> **NOTE**
>
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [selectByRange](#selectbyrange10) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type             | Mandatory| Description            |
| ------ | ----------------- | ---- | ---------------- |
| range  | [Range](#range10) | Yes  | Range of the selected text.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
// Set the replacement range of the preview text to the first character.
// Set the start and end positions of the selected text.
let range: inputMethodEngine.Range = { start: 0, end: 1 };
inputClient.selectByRangeSync(range);
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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Set the cursor to move upward upon text selection.
let movement: inputMethodEngine.Movement = { direction: 1 };
inputClient.selectByMovement(movement, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to selectByMovement. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in selecting by movement.');
});
```

### selectByMovement<sup>10+</sup>

selectByMovement(movement: Movement): Promise&lt;void&gt;

Selects text based on the cursor movement direction. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| movement | [Movement](#movement10) | Yes  | Direction in which the cursor moves when the text is selected.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Set the cursor to move upward upon text selection.
let movement: inputMethodEngine.Movement = { direction: 1 };
inputClient.selectByMovement(movement).then(() => {
  console.info('Succeeded in selecting by movement.');
}).catch((err: BusinessError) => {
  console.error(`Failed to selectByMovement. Code is ${err.code}, message is ${err.message}`);
});
```

### selectByMovementSync<sup>10+</sup>

selectByMovementSync(movement: Movement): void

Selects text based on the cursor movement direction.
> **NOTE**
>
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [selectByMovement](#selectbymovement10-1) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                   | Mandatory| Description                  |
| -------- | ----------------------- | ---- | ---------------------- |
| movement | [Movement](#movement10) | Yes  | Direction in which the cursor moves when the text is selected.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                  |
| -------- | -------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |

**Example**

```ts
//  Set the cursor to move upward upon text selection.
let movement: inputMethodEngine.Movement = { direction: 1 };
inputClient.selectByMovementSync(movement);
```

### getTextIndexAtCursor<sup>10+</sup>

getTextIndexAtCursor(callback: AsyncCallback&lt;number&gt;): void

Obtains the index of the text where the cursor is located. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the text index is obtained successfully, **err** is **undefined** and **index** is the text index at the cursor position. Otherwise, **err** is an error object and **index** is **undefined**. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getTextIndexAtCursor((err: BusinessError, index: number) => {
  if (err) {
    console.error(`Failed to getTextIndexAtCursor. Code is ${err.code}, message is ${err.message}`);
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
| Promise&lt;number&gt; | Promise used to return the index of the text where the cursor is located. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID | Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getTextIndexAtCursor().then((index: number) => {
  console.info('Succeeded in getTextIndexAtCursor: ' + index);
}).catch((err: BusinessError) => {
  console.error(`Failed to getTextIndexAtCursor. Code is ${err.code}, message is ${err.message}`);
});
```

### getTextIndexAtCursorSync<sup>10+</sup>

getTextIndexAtCursorSync(): number

Obtains the text index at the cursor position.
> **NOTE**
>
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [getTextIndexAtCursor](#gettextindexatcursor10) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type  | Description                      |
| ------ | -------------------------- |
| number | Index of the text where the cursor is located.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
let index: number = inputClient.getTextIndexAtCursorSync();
console.info(`Succeeded in getTextIndexAtCursorSync, index: ${index}`);
```

### sendExtendAction<sup>10+</sup>

sendExtendAction(action: ExtendAction, callback: AsyncCallback&lt;void&gt;): void

Sends an extended edit action. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The input method applications call this API to send extended edit actions to the edit box. The edit box listens for the corresponding event using [on('handleExtendAction')](./js-apis-inputmethod.md#onhandleextendaction10) for further processing.
>
> When the edit box responds to the **PASTE** command of [ExtendAction](#extendaction10), the edit box application needs to apply for the [ohos.permission.READ_PASTEBOARD](../../security/AccessToken/restricted-permissions.md#ohospermissionread_pasteboard) permission.

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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.sendExtendAction(inputMethodEngine.ExtendAction.COPY, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to sendExtendAction. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in sending extend action.');
});
```

### sendExtendAction<sup>10+</sup>

sendExtendAction(action: ExtendAction): Promise&lt;void&gt;

Sends an extended edit action. This API uses a promise to return the result.

>**NOTE**
>
> The input method applications call this API to send extended edit actions to the edit box. The edit box listens for the corresponding event using [on('handleExtendAction')](./js-apis-inputmethod.md#onhandleextendaction10) for further processing.
>
> When the edit box responds to the **PASTE** command of [ExtendAction](#extendaction10), the edit box application needs to apply for the [ohos.permission.READ_PASTEBOARD](../../security/AccessToken/restricted-permissions.md#ohospermissionread_pasteboard) permission.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | [ExtendAction](#extendaction10) | Yes| Extended edit action to send.|

**Return value**

| Type                 | Description                                   |
| --------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800006 | input method controller error. Possible cause: create InputMethodController object failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.sendExtendAction(inputMethodEngine.ExtendAction.COPY).then(() => {
  console.info('Succeeded in sending extend action.');
}).catch((err: BusinessError) => {
  console.error(`Failed to sendExtendAction. Code is ${err.code}, message is ${err.message}`);
});
```

### sendPrivateCommand<sup>12+</sup>

sendPrivateCommand(commandData: Record&lt;string, CommandDataType&gt;): Promise&lt;void&gt;

Sends private data to the system component that needs to communicate with the input method application. This API uses a promise to return the result.

>**NOTE**
>
> - The private data channel allows communication between the system preset input method application and specific system components (such as a text box or a home screen application). It is usually used to implement custom input on a specific device.
> - The total size of the private data is 32 KB, and the maximum number of private data records is 5.
> - Private data is sent to the text box by default. To send it to a desktop application, add a data entry `{'sys_cmd':1}` to the private data.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name     | Type                           | Mandatory| Description      |
| ----------- | ------------------------------- | ---- | ---------- |
| commandData | Record<string, [CommandDataType](#commanddatatype12)> | Yes  | Private data to send.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                      |
| -------- | ---------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800010 | not the preconfigured default input method. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodEngine.getInputMethodAbility().on('inputStart', (kbController, textInputClient) => {
  let record: Record<string, inputMethodEngine.CommandDataType> = {
    "valueString1": "abcdefg",
    "valueString2": true,
    "valueString3": 500,
  }
  textInputClient.sendPrivateCommand(record).then(() => {
  }).catch((err: BusinessError) => {
    if (err) {
      console.error(`sendPrivateCommand catch error: ${err.code}, message: ${err.message}`);
    }
  });
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
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800012 | the input method panel does not exist. |
| 12800013 | window manager service error.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.getCallingWindowInfo().then((windowInfo: inputMethodEngine.WindowInfo) => {
  console.info(`windowInfo.rect: ${windowInfo.rect.left}, ${windowInfo.rect.top}, ${windowInfo.rect.width}, ${windowInfo.rect.height}`);
  console.info(`windowInfo.status: ${windowInfo.status}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to getCallingWindowInfo. Code is ${err.code}, message is ${err.message}`);
});
```

### setPreviewText<sup>12+</sup>

setPreviewText(text: string, range: Range): Promise&lt;void&gt;

Sets the preview text. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

<!--Table: auto; auto; 10%; 60%-->

| Name| Type             | Mandatory| Description                                                        |
| ------ | ----------------- | ---- | ------------------------------------------------------------ |
| text   | string            | Yes   | Preview text.                                           |
| range  | [Range](#setpreviewtext12) | Yes   | Range of the text to be replaced.<br/>- When the value is **{ start: -1, end: -1 }**, the input **text** replaces all content in the current preview region by default.<br/>- When **start** equals **end**, the input **text** is inserted at the cursor position corresponding to **start**.<br/>- When **start** does not equal **end**, the input **text** replaces text within the specified **range**.<br/>- For other combinations containing negative **start** or **end** values, the API returns a parameter error.<br/>- When the edit box already contains preview text, **range** must not exceed the bounds of the preview text region; otherwise, a parameter error is returned.<br/>- When the edit box has no preview text, **range** must not exceed the bounds of text within the edit box; otherwise, a parameter error is returned. |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800011 | text preview not supported.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Set the replacement range of the preview text to the first character.
// Set the start and end positions of the selected text.
let range: inputMethodEngine.Range = { start: 0, end: 1 };
inputClient.setPreviewText('test', range).then(() => {
  console.info('Succeeded in setting preview text.');
}).catch((err: BusinessError) => {
  console.error(`Failed to setPreviewText. Code is ${err.code}, message is ${err.message}`);
});
```

### setPreviewTextSync<sup>12+</sup>

setPreviewTextSync(text: string, range: Range): void

Sets the preview text.
> **NOTE**
>
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [setPreviewText](#setpreviewtext12) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

<!--Table: auto; auto; 10%; 60%-->

| Name | Type             | Mandatory| Description                                                        |
| ------ | ----------------- | ---- | ------------------------------------------------------------ |
| text   | string            | Yes   | Preview text.                                           |
| range  | [Range](#finishtextpreview12) | Yes   | Range of the text to be replaced.<br/>- When the value is **{ start: -1, end: -1 }**, the input **text** replaces all content in the current preview region by default.<br/>- When **start** equals **end**, the input **text** is inserted at the cursor position corresponding to **start**.<br/>- When **start** does not equal **end**, the input **text** replaces text within the specified **range**.<br/>- For other combinations containing negative **start** or **end** values, the API returns a parameter error.<br/>- When the edit box already contains preview text, **range** must not exceed the bounds of the preview text region; otherwise, a parameter error is returned.<br/>- When the edit box has no preview text, **range** must not exceed the bounds of text within the edit box; otherwise, a parameter error is returned. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800011 | text preview not supported.                               |

**Example**

```ts
// Set the replacement range of the preview text to the first character.
// Set the start and end positions of the selected text.
let range: inputMethodEngine.Range = { start: 0, end: 1 };
inputClient.setPreviewTextSync('test', range);
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
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID | Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800011 | text preview not supported. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputClient.finishTextPreview().then(() => {
  console.info('Succeeded in finishing text preview.');
}).catch((err: BusinessError) => {
  console.error(`Failed to finishTextPreview. Code is ${err.code}, message is ${err.message}`);
});
```

### finishTextPreviewSync<sup>12+</sup>

finishTextPreviewSync(): void

Ends the text preview.
> **NOTE**
>
> This synchronous API may block the main thread and affect UI interaction. Use it with caution. It is recommended that you use the corresponding asynchronous API [finishTextPreview](#finishtextpreview12) instead.
>
> If the current input box already contains preview text, calling this API commits the preview content to the screen.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
| 12800011 | text preview not supported. |

**Example**

```ts
inputClient.finishTextPreviewSync();
```

### sendMessage<sup>15+</sup>

sendMessage(msgId: string, msgParam?: ArrayBuffer): Promise&lt;void&gt;

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
| msgId    | string      | Yes   | Identifier of the custom data to be sent to the edit box app attached to the input method app. The maximum length is 256 bytes. If the length exceeds the limit, error code 401 is returned. |
| msgParam | ArrayBuffer | No   | Message body of the custom data to be sent to the edit box app attached to the input method app. The maximum size is 128 KB. If the size exceeds the limit, error code 401 is returned. |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Incorrect parameter length.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. 3.ipc failed due to the large amount of data transferred or other reasons. |
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
  console.error(`Failed to send message. Code is ${err.code}, message is ${err.message}`);
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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message        |
| -------- | ---------------- |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. |

**Example**

```ts
inputMethodEngine.getInputMethodAbility()
  .on('inputStart',
    (kbController: inputMethodEngine.KeyboardController, client: inputMethodEngine.InputClient) => {
      // Create a message handler to receive custom communication data sent by the edit box app.
      let messageHandler: inputMethodEngine.MessageHandler = {
        onTerminated(): void {
          console.info('OnTerminated.');
        },
        onMessage(msgId: string, msgParam?: ArrayBuffer): void {
          console.info('recv message.');
        }
      }
      // Register the message handler.
      client.recvMessage(messageHandler);
    });
```

### getAttachOptions<sup>19+</sup>

getAttachOptions(): AttachOptions

Obtains the additional options for binding an input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description        |
| ---- | ------------ |
| [AttachOptions](#attachoptions19) | Additional options for binding an input method.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                       |
| -------- | ---------------------------------------------- |
| 801 | Capability not supported. [since 19 - 19] |

> **NOTE**
>
> Error code `801 Capability not supported.` is removed since API version 20.

**Example**

```ts
let attachOptions: inputMethodEngine.AttachOptions = inputClient.getAttachOptions();
console.info(`Succeeded in getting AttachOptions, AttachOptions is ${attachOptions}`);
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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message                                       |
| -------- | ---------------------------------------------- |
| 801 | Capability not supported. [since 19 - 19]. |

> **NOTE**
>
> Error code `801 Capability not supported.` is removed since API version 20.

**Example**

```ts
// Create the callback for additional option changes.
let attachOptionsDidChangeCallback: (attachOptions: inputMethodEngine.AttachOptions) => void =
  (_attachOptions: inputMethodEngine.AttachOptions) => {
    console.info(`AttachOptionsDidChangeCallback1: attachOptionsDidChange event triggered`);
  };

// Subscribe to the additional option change event when the input method is attached.
inputClient.on('attachOptionsDidChange', attachOptionsDidChangeCallback);
console.info(`attachOptionsDidChangeCallback subscribed to attachOptionsDidChange`);
// Unsubscribe from the additional option change event when the input method is attached.
inputClient.off('attachOptionsDidChange', attachOptionsDidChangeCallback);
console.info(`attachOptionsDidChange unsubscribed from attachOptionsDidChange`);
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
let attachOptionsDidChangeCallback: (attachOptions: inputMethodEngine.AttachOptions) => void =
  (_attachOptions: inputMethodEngine.AttachOptions) => {
    console.info(`AttachOptionsDidChangeCallback1: attachOptionsDidChange event triggered`);
  };

inputClient.on('attachOptionsDidChange', attachOptionsDidChangeCallback);
console.info(`attachOptionsDidChangeCallback subscribed to attachOptionsDidChange`);
inputClient.off('attachOptionsDidChange', attachOptionsDidChangeCallback);
console.info(`attachOptionsDidChange unsubscribed from attachOptionsDidChange`);
```

## CapitalizeMode<sup>20+</sup>

Enumerates the modes of capitalizing the first letter of a text.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value| Description|
| -------- | -- | -------- |
| NONE | 0 | The first letter is not capitalized.|
| SENTENCES | 1 | The first letter of each sentence is capitalized.|
| WORDS | 2 | The first letter of each word is capitalized.|
| CHARACTERS | 3 | All letters are capitalized.|

## EditorAttribute

Represents the attributes of the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name        | Type| Read-Only| Optional| Description              |
| ------------ | -------- | ---- | ---- | ------------------ |
| enterKeyType | number   | Yes  | No  | Function attributes of the edit box. For details, see [function key definitions in constants](#constants).|
| inputPattern | number   | Yes  | No  | Text attributes of the edit box. For details, see [edit box definitions in constants](#immersivemode15).|
| isTextPreviewSupported<sup>12+</sup> | boolean | No| No| Whether text preview is supported.<br>- **true**: Supported.<br>- **false**: Unsupported.|
| bundleName<sup>14+</sup> | string | Yes| Yes| Name of the bundle to which the edit box belongs. The value may be **""**. Handle this scenario when using the attribute.|
| immersiveMode<sup>15+</sup> | [ImmersiveMode](#capitalizemode20) | Yes  | Yes  | Immersive mode of the input method.|
| windowId<sup>18+</sup> | number | Yes| Yes| ID of the window where the edit box is located.|
| displayId<sup>18+</sup> | number | Yes  | Yes  | Screen ID of the window corresponding to the edit box. If the window ID is not set, the screen ID of the focused window is used.|
| placeholder<sup>20+</sup> | string | Yes| Yes| Placeholder information set for the edit box.|
| abilityName<sup>20+</sup> | string | Yes| Yes| Ability name set for the edit box.|
| capitalizeMode<sup>20+</sup> | [CapitalizeMode](#gradientmode20) | Yes| Yes| Whether to capitalize the first letter in the edit box. If it is not set or is set to an invalid value, the first letter is not capitalized by default.|
| gradientMode<sup>20+</sup> | [GradientMode](#paneltype10) | Yes| Yes| Gradient mode. If this attribute is not specified or is set to an invalid value, the gradient mode is not used by default.|
| extraConfig<sup>22+</sup> | [InputMethodExtraConfig](./js-apis-inputmethod-extraconfig.md#inputmethodextraconfig) | Yes| Yes| Extra information about the input method.|
| consumeKeyEvents      | boolean   | Yes   | Yes   | Whether the edit box has the full capability to handle keys such as letters, characters, and function keys.<br/>- The value **true** indicates that it has this capability.<br/>- The value **false** indicates that it does not have this capability.<br/>**Since:** 26.0.0<br/>**Model restriction:** This parameter can be used only in the stage model. |

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

Indicates the position and size of the enhanced input method panel, including the custom avoidance area and hot zone.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name                | Type                                                        | Read-Only| Optional| Description                                                        |
| -------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| landscapeRect        | [window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)         | No  | Yes  | Size of the input method panel window in landscape mode.<br>- This attribute is mandatory when **fullScreenMode** is not set or is set to **false**.|
| portraitRect         | [window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)         | No  | Yes  | Size of the input method panel window in portrait mode.<br>- This attribute is mandatory when **fullScreenMode** is not set or is set to **false**.|
| landscapeAvoidY      | number                                                       | No   | Yes   | Distance from the avoidance line in the panel to the top of the panel in landscape mode, in px. The default value is **0**.<br/>- Other system components in the app avoid the IME panel area below the avoidance line.<br/>- When the panel is in the fixed state, the height from the avoidance line to the bottom of the screen cannot exceed 70% of the screen height. When the panel height is greater than 70% of the screen height, the default value **0** will fail this check. You need to set it manually so that the height from the avoidance line to the bottom of the screen does not exceed 70% of the screen height. |
| landscapeInputRegion | Array&lt;[window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)&gt; | No  | Yes  | Region where the panel receives input events in landscape mode.<br>- The array size is limited to [1, 4]. The default value is the panel size in landscape mode.<br>- The input hot zone is relative to the left vertex of the input method panel window.|
| portraitAvoidY       | number                                                       | No   | Yes   | Distance from the avoidance line in the panel to the top of the panel in portrait mode, in px. The default value is **0**.<br/>- Other system components in the app avoid the IME panel area below the avoidance line.<br/>- When the panel is in the fixed state, the height from the avoidance line to the bottom of the screen cannot exceed 70% of the screen height. When the panel height is greater than 70% of the screen height, the default value **0** will fail this check. You need to set it manually so that the height from the avoidance line to the bottom of the screen does not exceed 70% of the screen height. |
| portraitInputRegion  | Array&lt;[window.Rect](../apis-arkui/arkts-apis-window-i.md#rect7)&gt; | No  | Yes  | Region where the panel receives input events in portrait mode.<br>- The array size is limited to [1, 4]. The default value is the panel size in portrait mode.<br>- The input hot zone is relative to the left vertex of the input method panel window.|
| fullScreenMode       | boolean                                                      | No  | Yes  | Whether to enable the full-screen mode. The default value is **false**.<br>- If the value is **true**, **landscapeRect** and **portraitRect** are optional.<br>- If the value is **false**, **landscapeRect** and **portraitRect** are mandatory.|

## KeyboardArea<sup>15+</sup>

Represents the keyboard area on the panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name  | Type  | Read-Only | Optional | Description                                                        |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| top    | number | No | No  | Distance between the upper boundary of the keyboard area and the upper boundary of the panel area, in pixels. The value is an integer.|
| bottom | number | No  | No  | Distance between the lower boundary of the keyboard area and the lower boundary of the panel area, in pixels. The value is an integer.|
| left   | number | No  | No  | Distance between the left boundary of the keyboard area and the left boundary of the panel area, in pixels. The value is an integer.|
| right  | number | No  | No  | Distance between the right border of the keyboard area and the right border of the panel area, in pixels. The value is an integer.|

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
| gradientHeight   | number                      | No   | No   | Gradient height, which cannot exceed 15% of the screen height. Unit: px.|
| gradientMode | [GradientMode](#gradientmode20) | No  | No  | Gradient mode.|

## SystemPanelInsets<sup>21+</sup>

Defines the offset area between the input method soft keyboard and the system panel.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name  | Type  | Read-Only| Optional| Description                                                        |
| ------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| bottom | number | Yes  | No  | Distance between the bottom border of the keyboard area and the bottom border of the system panel area, in px. The value is an integer.|
| left   | number | Yes  | No  | Distance between the left border of the keyboard area and the left border of the system panel area, in px. The value is an integer.|
| right  | number | Yes  | No  | Distance between the right border of the keyboard area and the right border of the system panel area, in px. The value is an integer.|

## TextInputClient<sup>(deprecated)</sup>

In the following API examples, you must first use [on('inputStart')](#oninputstartdeprecated) to obtain a **TextInputClient** instance, and then call the APIs using the obtained instance.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [InputClient](#inputclient9) instead.

### getForward<sup>(deprecated)</sup>

getForward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text before the cursor. This API uses an asynchronous callback to return the result.

Usage scenarios: Analyze the entered text content to provide intelligent completion suggestions, check text format, implement text prediction, implement text semantic analysis, and more.

Use effect: When the operation is successful, the fixed-length text before the cursor is returned, based on which the input method app can update candidate words or input suggestions.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.getForward](#getforward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained text. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
textInputClient.getForward(length, (err: BusinessError, text: string) => {
  if (err) {
    console.error(`Failed to getForward. Code is ${err.code}, message is ${err.message}`);
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
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.getForward](#getforward9-1) instead.

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

let length: number = 1;
textInputClient.getForward(length).then((text: string) => {
  console.info('Succeeded in getting forward, text: ' + text);
}).catch((err: BusinessError) => {
  console.error(`Failed to getForward. Code is ${err.code}, message is ${err.message}`);
});
```

### getBackward<sup>(deprecated)</sup>

getBackward(length:number, callback: AsyncCallback&lt;string&gt;): void

Obtains the specific-length text after the cursor. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.getBackward](#getbackward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the obtained text. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
textInputClient.getBackward(length, (err: BusinessError, text: string) => {
  if (err) {
    console.error(`Failed to getBackward. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in getting backward, text: ' + text);
});
```

### getBackward<sup>(deprecated)</sup>

getBackward(length:number): Promise&lt;string&gt;

Obtains the specific-length text after the cursor. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.getBackward](#getbackward9) instead.

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

let length: number = 1;
textInputClient.getBackward(length).then((text: string) => {
  console.info(`'Succeeded in getting backward: ${text}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to getBackward. Code is ${err.code}, message is ${err.message}`);
});
```

### deleteForward<sup>(deprecated)</sup>

deleteForward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text before the cursor. This API uses an asynchronous callback to return the result.

Usage scenarios: Implement the Backspace key function, delete input character by character, delete incorrect input, and implement custom deletion logic, among others.

Use effect: When the operation is successful, the fixed-length text before the cursor is deleted.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.deleteForward](#deleteforward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| length | number | Yes| Text length, which cannot be less than 0.|
| callback | AsyncCallback&lt;boolean&gt; | Yes | Callback used to return the result. If the fixed-length text before the cursor is deleted successfully, **err** is **undefined** and **data** is **true**; if the deletion fails, **err** is **undefined** and **data** is **false**; otherwise, **err** is an error object. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
textInputClient.deleteForward(length, (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to deleteForward. Code is ${err.code}, message is ${err.message}`);
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
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.deleteBackward](#deletebackward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| length | number | Yes  | Text length, which cannot be less than 0.|

**Return value** 

| Type                  | Description          |
| ---------------------- | -------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If resolved, the value **true** indicates that the fixed-length text before the cursor is deleted successfully, and **false** indicates that the deletion fails. If rejected, an error object is thrown, indicating that an error occurs during execution. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
textInputClient.deleteForward(length).then((result: boolean) => {
  if (result) {
    console.info('Succeeded in deleting forward.');
  } else {
    console.error('Failed to delete forward.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to deleteForward. Code is ${err.code}, message is ${err.message}`);
});
```

### deleteBackward<sup>(deprecated)</sup>

deleteBackward(length:number, callback: AsyncCallback&lt;boolean&gt;): void

Deletes the fixed-length text after the cursor. This API uses an asynchronous callback to return the result.

Usage scenarios: Implement the Backspace key function, delete input character by character, delete incorrect input, and implement custom deletion logic, among others.

Use effect: When the operation is successful, the fixed-length text after the cursor is deleted.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.deleteBackward](#deletebackward9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                        | Mandatory| Description          |
| -------- | ---------------------------- | ---- | -------------- |
| length   | number                       | Yes  | Text length, which cannot be less than 0.     |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let length: number = 1;
textInputClient.deleteBackward(length, (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to deleteBackward. Code is ${err.code}, message is ${err.message}`);
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
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.deleteBackward](#deletebackward9) instead.

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

let length: number = 1;
textInputClient.deleteBackward(length).then((result: boolean) => {
  if (result) {
    console.info('Succeeded in deleting backward.');
  } else {
    console.error('Failed to deleteBackward.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to deleteBackward. Code is ${err.code}, message is ${err.message}`);
});
```

### sendKeyFunction<sup>(deprecated)</sup>

sendKeyFunction(action: number, callback: AsyncCallback&lt;boolean&gt;): void

Sends the function key. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.sendKeyFunction](#sendkeyfunction9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| action | number | Yes| Action of the function key.<br>- **0**: invalid key.<br>- **1**: confirm key (Enter key).|
| callback | AsyncCallback&lt;boolean&gt; | Yes | Callback used to return the result. If the function key is sent successfully, **err** is undefined and **data** is **true**; if the function key fails to be sent, **err** is undefined and **data** is **false**; otherwise, an error object is returned. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let action: number = 1;
textInputClient.sendKeyFunction(action, (err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to sendKeyFunction. Code is ${err.code}, message is ${err.message}`);
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
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.sendKeyFunction](#sendkeyfunction9) instead.

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

let action: number = 1;
textInputClient.sendKeyFunction(action).then((result: boolean) => {
  if (result) {
    console.info('Succeeded in sending key function.');
  } else {
    console.error('Failed to sendKeyFunction.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to sendKeyFunction:. Code is ${err.code}, message is ${err.message}`);
});
```

### insertText<sup>(deprecated)</sup>

insertText(text:string, callback: AsyncCallback&lt;boolean&gt;): void

Inserts text. This API uses an asynchronous callback to return the result.

Usage scenarios: Insert candidate words, insert special symbols, implement text auto-completion, and quickly insert common phrases, among others.

Use effect: When the operation is successful, the text is inserted at the cursor position in the edit box.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.insertText](#inserttext9) instead.

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
    console.error(`Failed to insertText. Code is ${err.code}, message is ${err.message}`);
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
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.insertText](#inserttext9) instead.

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
  console.error(`Failed to insertText. Code is ${err.code}, message is ${err.message}`);
});
```

### getEditorAttribute<sup>(deprecated)</sup>

getEditorAttribute(callback: AsyncCallback&lt;EditorAttribute&gt;): void

Obtains the attribute of the edit box. This API uses an asynchronous callback to return the result.

Usage scenarios: Adjust the input method UI based on the edit box type, provide different input suggestions based on the edit box configuration, implement specific input logic, and adapt to different types of input boxes, among others.

Use effect: The edit box attribute information (including **inputPattern** and **enterKeyType**) is returned, based on which the input method app adjusts the keyboard layout.

> **NOTE**
>
> Supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.getEditorAttribute](#geteditorattribute9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type  | Mandatory | Description  |
| -------- | ----- | ----- | ----- |
| callback | AsyncCallback&lt;[EditorAttribute](#editorattribute)&gt; | Yes|  Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the attribute of the edit box. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';


textInputClient.getEditorAttribute((err: BusinessError,
  editorAttribute: inputMethodEngine.EditorAttribute) => {
  if (err) {
    console.error(`Failed to getEditorAttribute. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`editorAttribute.inputPattern: ${editorAttribute.inputPattern}`);
  console.info(`editorAttribute.enterKeyType: ${editorAttribute.enterKeyType}`);
});
```

### getEditorAttribute<sup>(deprecated)</sup>

getEditorAttribute(): Promise&lt;EditorAttribute&gt;

Obtains the attribute of the edit box. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [inputMethodEngine.InputClient.getEditorAttribute](#geteditorattribute9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                           | Description                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| Promise&lt;[EditorAttribute](#editorattribute)&gt; |  Promise used to return the attribute of the edit box.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textInputClient.getEditorAttribute().then((editorAttribute: inputMethodEngine.EditorAttribute) => {
  console.info(`editorAttribute.inputPattern: ${editorAttribute.inputPattern}`);
  console.info(`editorAttribute.enterKeyType: ${editorAttribute.enterKeyType}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to getEditorAttribute. Code is ${err.code}, message is ${err.message}`);
});
```

<!--no_check-->