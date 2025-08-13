# @ohos.inputMethod (Input Method Framework)
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @illybyy-->
<!--SE: @andeszhang-->
<!--TSE: @murphy1984-->

The **inputMethod** module is oriented to common foreground applications (third-party applications and system applications such as Notes, Messaging, and Settings). It provides input method control and management capabilities, including displaying or hiding the soft keyboard, switching between input methods, and obtaining the list of all input methods.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { inputMethod } from '@kit.IMEKit';
```

## Constant

Provides the constants.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Value| Description|
| -------- | -------- | -------- | -------- |
| MAX_TYPE_NUM<sup>8+</sup> | number | 128 | Maximum number of supported input methods.|

## InputMethodProperty<sup>8+</sup>

Describes the input method application attributes.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| name<sup>9+</sup>  | string | Yes| No| Mandatory. Name of the input method package.|
| id<sup>9+</sup>    | string | Yes| No| Mandatory. Unique identifier of an input method extension in an app. **id** and **name** form a globally unique identifier of the input method extension.|
| label<sup>9+</sup>    | string | Yes| Yes| Optional.<br>- When **InputMethodProperty** is used as the input parameter of an API for switching or querying, you do not need to set this field. You can use name and ID to uniquely specify an input method extension.<br>- When **InputMethodProperty** is used as the return value of an API for querying (for example, [getCurrentInputMethod](#inputmethodgetcurrentinputmethod9)), this field indicates the name of the input method extension displayed externally. Use the label configured for the InputmethodExtensionAbility. If no label is configured, the label of the application entry ability is automatically used. If no label is configured for the application entry ability, the label configured in **AppScope** is automatically used.|
| labelId<sup>10+</sup>    | number | Yes| Yes| Optional.<br>- When **InputMethodProperty** is used as the input parameter of an API for switching or querying, you do not need to set this field. You can use name and ID to uniquely specify an input method extension.<br>- When **InputMethodProperty** is used as the return value of an API for querying (for example, [getCurrentInputMethod](#inputmethodgetcurrentinputmethod9)), this field indicates the resource ID of the **label** field.|
| icon<sup>9+</sup>    | string | Yes| Yes| Optional.<br>- When **InputMethodProperty** is used as the input parameter of an API for switching or querying, you do not need to set this field. You can use name and ID to uniquely specify an input method extension.<br>- When **InputMethodProperty** is used as the return value of an API for querying (for example, [getCurrentInputMethod](#inputmethodgetcurrentinputmethod9)), this field indicates the input method icon data, which can be obtained through icon ID.|
| iconId<sup>9+</sup>    | number | Yes| Yes| Optional.<br>- When **InputMethodProperty** is used as the input parameter of an API for switching or querying, you do not need to set this field. You can use name and ID to uniquely specify an input method extension.<br>- When **InputMethodProperty** is used as the return value of an API for querying (for example, [getCurrentInputMethod](#inputmethodgetcurrentinputmethod9)), this field indicates the resource ID of the **icon** field.|
| enabledState<sup>20+</sup>    | [EnabledState](js-apis-inputmethod.md#enabledstate15) | Yes| Yes| Optional.<br>- When **InputMethodProperty** is used as the input parameter of an API for switching or querying, you do not need to set this field. You can use name and ID to uniquely specify an input method extension.<br>- When **InputMethodProperty** is used as the return value of an API for querying (for example, [getCurrentInputMethod](#inputmethodgetcurrentinputmethod9)), this field indicates whether the input method is enabled.|
| extra<sup>9+</sup>    | object | No| Yes| Extra information about the input method. This parameter is reserved and currently has no specific meaning.<br>- API version 10 and later: optional<br>- API version 9: mandatory|
| packageName<sup>(deprecated)</sup> | string | Yes| No| Name of the input method package. Mandatory.<br>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. You are advised to use **name** instead.|
| methodId<sup>(deprecated)</sup> | string | Yes| No| Unique ID of the input method. Mandatory.<br>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. You are advised to use **id** instead.|

## CapitalizeMode<sup>20+</sup>

Enumerates the modes of capitalizing the first letter of a text.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value| Description|
| -------- | -- | -------- |
| NONE | 0 | The first letter is not capitalized.|
| SENTENCES | 1 | The first letter of each sentence is capitalized.|
| WORDS | 2 | The first letter of each word is capitalized.|
| CHARACTERS | 3 | All letters are capitalized.|

## inputMethod.getController<sup>9+</sup>

getController(): InputMethodController

Obtains an [InputMethodController](#inputmethodcontroller) instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                           | Description                  |
| ----------------------------------------------- | ---------------------- |
| [InputMethodController](#inputmethodcontroller) | **InputMethodController** instance.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                    |
| -------- | ------------------------------ |
| 12800006 | input method controller error. Possible cause: create InputmethodController object failed. |

**Example**

```ts
let inputMethodController = inputMethod.getController();
```

## inputMethod.getDefaultInputMethod<sup>11+</sup>

getDefaultInputMethod(): InputMethodProperty

Obtains the default input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                        | Description                    |
| -------------------------------------------- | ------------------------ |
| [InputMethodProperty](#inputmethodproperty8) | Default input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
try {
  let defaultIme = inputMethod.getDefaultInputMethod();
} catch(err) {
  console.error(`Failed to getDefaultInputMethod: ${JSON.stringify(err)}`);
}
```

## inputMethod.getSystemInputMethodConfigAbility<sup>11+</sup>

getSystemInputMethodConfigAbility(): ElementName

Obtains the information about the input method configuration page ability.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                        | Description                    |
| -------------------------------------------- | ------------------------ |
| [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md) | Element name of the input method configuration page ability.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
try {
  let inputMethodConfig = inputMethod.getSystemInputMethodConfigAbility();
} catch(err) {
  console.error(`Failed to get getSystemInputMethodConfigAbility: ${JSON.stringify(err)}`);
}
```

## inputMethod.getSetting<sup>9+</sup>

getSetting(): InputMethodSetting

Obtains an [InputMethodSetting](#inputmethodsetting8) instance.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description                      |
| ----------------------------------------- | -------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | **InputMethodSetting** instance.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800007 |  input method setter error. Possible cause: create InputmethodSetting object failed. |

**Example**

```ts
let inputMethodSetting = inputMethod.getSetting();
```

## inputMethod.switchInputMethod<sup>9+</sup>

switchInputMethod(target: InputMethodProperty, callback: AsyncCallback&lt;boolean&gt;): void

Switches to another input method. This API uses an asynchronous callback to return the result.
> **NOTE**
>
>  - In API versions 9 and 10, this API can only be called by system applications granted the **ohos.permission.CONNECT_IME_ABILITY** permission.
>  - Since API version 11, this API can only be called by the current input method application.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| target | [InputMethodProperty](#inputmethodproperty8) | Yes| Target input method.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentIme = inputMethod.getCurrentInputMethod();
try{
  inputMethod.switchInputMethod(currentIme, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in switching inputmethod.');
    } else {
      console.error('Failed to switchInputMethod.');
    }
  });
} catch(err) {
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
}
```

> **NOTE**
>
> Since API version 11, the error code `201 permissions check fails` is removed.

## inputMethod.switchInputMethod<sup>9+</sup>
switchInputMethod(target: InputMethodProperty): Promise&lt;boolean&gt;

Switches to another input method. This API uses a promise to return the result.
> **NOTE**
>
>  - In API versions 9 and 10, this API can only be called by system applications granted the **ohos.permission.CONNECT_IME_ABILITY** permission.
>  - Since API version 11, this API can only be called by the current input method application.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  |target |  [InputMethodProperty](#inputmethodproperty8)| Yes| Target input method.|

**Return value**

  | Type                                     | Description                        |
  | ----------------------------------------- | ---------------------------- |
  | Promise\<boolean> | Promise used to return the result. The value **true** means that the switching is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentIme = inputMethod.getCurrentInputMethod();
try {
  inputMethod.switchInputMethod(currentIme).then((result: boolean) => {
    if (result) {
      console.info('Succeeded in switching inputmethod.');
    } else {
      console.error('Failed to switchInputMethod.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
  })
} catch (err) {
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
}
```

> **NOTE**
>
> Since API version 11, the error code `201 permissions check fails` is removed.

## inputMethod.getCurrentInputMethod<sup>9+</sup>

getCurrentInputMethod(): InputMethodProperty

Obtains the current input method. This API returns the result synchronously.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                        | Description                    |
| -------------------------------------------- | ------------------------ |
| [InputMethodProperty](#inputmethodproperty8) | **InputmethodProperty** instance of the current input method.|

**Example**

```ts
let currentIme = inputMethod.getCurrentInputMethod();
```

## inputMethod.switchCurrentInputMethodSubtype<sup>9+</sup>

switchCurrentInputMethodSubtype(target: InputMethodSubtype, callback: AsyncCallback\<boolean>): void

Switches to another subtype of this input method. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>  - In API version 9, this API can only be called by system applications granted the **ohos.permission.CONNECT_IME_ABILITY** permission.
>  - In API version 10, this API can only be called by system applications and the current input method application, and the **ohos.permission.CONNECT_IME_ABILITY** permission is required.
>  - Since API version 11, this API can only be called by the current input method application.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| target |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| Yes| Target input method subtype.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let extra: Record<string, string> = {}
  inputMethod.switchCurrentInputMethodSubtype({
    id: "ServiceExtAbility",
    label: "",
    name: "com.example.kikakeyboard",
    mode: "upper",
    locale: "",
    language: "",
    icon: "",
    iconId: 0,
    extra: extra
  }, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in switching currentInputMethodSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodSubtype');
    }
  });
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

> **NOTE**
>
> Since API version 11, the error code `201 permissions check fails` is removed.

## inputMethod.switchCurrentInputMethodSubtype<sup>9+</sup>

switchCurrentInputMethodSubtype(target: InputMethodSubtype): Promise&lt;boolean&gt;

Switches to another subtype of this input method. This API uses a promise to return the result.

> **NOTE**
>
>  - In API version 9, this API can only be called by system applications granted the **ohos.permission.CONNECT_IME_ABILITY** permission.
>  - In API version 10, this API can only be called by system applications and the current input method application, and the **ohos.permission.CONNECT_IME_ABILITY** permission is required.
>  - Since API version 11, this API can only be called by the current input method application.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|target |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| Yes| Target input method subtype.|

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the switching is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let extra: Record<string, string> = {}
  inputMethod.switchCurrentInputMethodSubtype({
    id: "ServiceExtAbility",
    label: "",
    name: "com.example.kikakeyboard",
    mode: "upper",
    locale: "",
    language: "",
    icon: "",
    iconId: 0,
    extra: extra
  }).then((result: boolean) => {
    if (result) {
      console.info('Succeeded in switching currentInputMethodSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodSubtype.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

> **NOTE**
>
> Since API version 11, the error code `201 permissions check fails` is removed.

## inputMethod.getCurrentInputMethodSubtype<sup>9+</sup>

getCurrentInputMethodSubtype(): InputMethodSubtype

Obtains the current input method subtype.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                        | Description                    |
| -------------------------------------------- | ------------------------ |
| [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype) | Current input method subtype.|

**Example**

```ts
let currentImeSubType = inputMethod.getCurrentInputMethodSubtype();
```

## inputMethod.switchCurrentInputMethodAndSubtype<sup>9+</sup>

switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype, callback: AsyncCallback\<boolean>): void

Switches to a specified subtype of a specified input method. This API uses an asynchronous callback to return the result.

> **NOTE**
>
>  - In API versions 9 and 10, this API can only be called by system applications granted the **ohos.permission.CONNECT_IME_ABILITY** permission.
>  - Since API version 11, this API can only be called by the current input method application.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|inputMethodProperty |  [InputMethodProperty](#inputmethodproperty8)| Yes| Target input method.|
|inputMethodSubtype |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| Yes| Target input method subtype.|
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentIme = inputMethod.getCurrentInputMethod();
let imSubType = inputMethod.getCurrentInputMethodSubtype();
try {
  inputMethod.switchCurrentInputMethodAndSubtype(currentIme, imSubType, (err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in switching currentInputMethodAndSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodAndSubtype.');
    }
  });
} catch (err) {
  console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
}
```

> **NOTE**
>
> Since API version 11, the error code `201 permissions check fails` is removed.

## inputMethod.switchCurrentInputMethodAndSubtype<sup>9+</sup>

switchCurrentInputMethodAndSubtype(inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype): Promise&lt;boolean&gt;

Switches to a specified subtype of a specified input method. This API uses a promise to return the result.

> **NOTE**
>
>  - In API versions 9 and 10, this API can only be called by system applications granted the **ohos.permission.CONNECT_IME_ABILITY** permission.
>  - Since API version 11, this API can only be called by the current input method application.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|inputMethodProperty |  [InputMethodProperty](#inputmethodproperty8)| Yes| Target input method.|
|inputMethodSubtype |  [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)| Yes| Target input method subtype.|

**Return value**

| Type                                     | Description                        |
| ----------------------------------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the switching is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentIme = inputMethod.getCurrentInputMethod();
let imSubType = inputMethod.getCurrentInputMethodSubtype();
try {
  inputMethod.switchCurrentInputMethodAndSubtype(currentIme, imSubType).then((result: boolean) => {
    if (result) {
      console.info('Succeeded in switching currentInputMethodAndSubtype.');
    } else {
      console.error('Failed to switchCurrentInputMethodAndSubtype.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to switchCurrentInputMethodAndSubtype: ${JSON.stringify(err)}`);
}
```

> **NOTE**
>
> Since API version 11, the error code `201 permissions check fails` is removed.

## inputMethod.getInputMethodController<sup>(deprecated)</sup>

getInputMethodController(): InputMethodController

Obtains an [InputMethodController](#inputmethodcontroller) instance.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getController()](#inputmethodgetcontroller9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                           | Description                    |
| ----------------------------------------------- | ------------------------ |
| [InputMethodController](#inputmethodcontroller) | Current **InputMethodController** instance.|

**Example**

```ts
let inputMethodController = inputMethod.getInputMethodController();
```

## inputMethod.getInputMethodSetting<sup>(deprecated)</sup>

getInputMethodSetting(): InputMethodSetting

Obtains an [InputMethodSetting](#inputmethodsetting8) instance.

> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getSetting()](#inputmethodgetsetting9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                     | Description                      |
| ----------------------------------------- | -------------------------- |
| [InputMethodSetting](#inputmethodsetting8) | **InputMethodSetting** instance.|

**Example**

```ts
let inputMethodSetting = inputMethod.getInputMethodSetting();
```

## inputMethod.setSimpleKeyboardEnabled<sup>20+</sup>

setSimpleKeyboardEnabled(enable: boolean): void

Enables or disables the simple keyboard.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| enable | boolean | Yes| Whether to enable the simple keyboard. The value **true** means that the simple keyboard is enabled; the value **false** means the opposite.<br> The native edit box takes effect when it is focused next time, while the self-drawing component takes effect when the input method is attached by calling [attach](#attach10) next time.|

**Example**

```ts
  let enable = false;
  inputMethod.setSimpleKeyboardEnabled(enable);
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
| NUMBER_PASSWORD<sup>11+</sup> | 8 |Numeric password.|
| SCREEN_LOCK_PASSWORD<sup>20+</sup> | 9 |Lock screen password.|
| USER_NAME<sup>20+</sup> | 10 |Username.|
| NEW_PASSWORD<sup>20+</sup> | 11 |New password.|
| NUMBER_DECIMAL<sup>20+</sup> | 12 |Number with a decimal point.|
| ONE_TIME_CODE<sup>20+</sup> | 13 |Verification code.|

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
| NEWLINE<sup>12+</sup>  | 8 | Line break.|

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

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| enterKeyType<sup>10+</sup>  | [EnterKeyType](#enterkeytype10) | No| No| Function type represented by the Enter key of the input method.|

## InputAttribute<sup>10+</sup>

Describes the attributes of the edit box, including the text input type and Enter key function type.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| textInputType<sup>10+</sup>  | [TextInputType](#textinputtype10) | No| No| Enumerates the text input types.|
| enterKeyType<sup>10+</sup>  | [EnterKeyType](#enterkeytype10) | No| No| Function type represented by the Enter key.|
| placeholder<sup>20+</sup> | string | No| Yes| Placeholder information set for the edit box.<br>- When placeholder information is set for the edit box, the length cannot exceed 255 characters (a placeholder longer than 255 characters will be automatically truncated to 255 characters). It is used to prompt or guide users to enter temporary text or symbols. (For example, the placeholder prompts whether the input item is mandatory.)<br>- If no placeholder is set for the edit box, the value is an empty string by default.<br>- This field is provided for the input method application when [attach](#attach10) is called.|
| abilityName<sup>20+</sup> | string | No| Yes| Ability name set for the edit box.<br>- If the ability name is set for the edit box, the length cannot exceed 127 characters. (A name longer than 127 characters will be automatically truncated to 127 characters.)<br>- If the ability name is not set for the edit box, the value is an empty string by default.<br>- This field is provided for the input method application when [attach](#attach10) is called.|

## TextConfig<sup>10+</sup>

Describes the configuration of the edit box.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| inputAttribute<sup>10+</sup>  | [InputAttribute](#inputattribute10) | No| No| Edit box attribute.|
| cursorInfo<sup>10+</sup>  | [CursorInfo](#cursorinfo10) | No| Yes| Cursor information.|
| selection<sup>10+</sup>  | [Range](#range10) | No| Yes| Text selection range.|
| windowId<sup>10+</sup>  | number | No| Yes| ID of the window where the edit box is located.|
| newEditBox<sup>20+</sup> | boolean | No| Yes| Whether the edit box is new. The value **true** means the edit box is new; the value **false** means the opposite.|
| capitalizeMode<sup>20+</sup> | [CapitalizeMode](#capitalizemode20) | No| Yes| Whether to capitalize the first letter in the edit box. If it is not set or is set to an invalid value, the first letter is not capitalized by default.|

## CursorInfo<sup>10+</sup>

Represents the cursor information.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| left  | number | No| No| Left coordinate of the cursor.|
| top  | number | No| No| Top coordinate of the cursor.|
| width  | number | No| No| Width of the cursor.|
| height  | number | No| No| Height of the cursor.|

## Range<sup>10+</sup>

Describes the range of the selected text.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| start  | number | No| No| Index of the first selected character in the text box.|
| end  | number | No| No| Index of the last selected character in the text box.|

## Movement<sup>10+</sup>

Describes the direction in which the cursor moves when the text is selected.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| direction  | [Direction](#direction10) | No| No| Direction in which the cursor moves when the text is selected.|

## InputWindowInfo<sup>10+</sup>

Describes the window information of the input method keyboard.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| name  | string | No| No| Name of the input method keyboard window.|
| left  | number | No| No| Horizontal coordinate of the upper left corner of the input method keyboard window, in px.|
| top  | number | No| No| Vertical coordinate of the upper left corner of the input method keyboard window, in px.|
| width  | number | No| No| Width of the input method keyboard window, in px.|
| height  | number | No| No| Height of the input method keyboard window, in px.|

## EnabledState<sup>15+</sup>

Indicates whether the input method is enabled.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value|Description|
| -------- | -------- |-------- |
| DISABLED   | 0 |Disabled.|
| BASIC_MODE  | 1 |Basic mode.|
| FULL_EXPERIENCE_MODE  | 2 |Full experience mode.|

## RequestKeyboardReason<sup>15+</sup>

Describes the reason for keyboard request.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Value|Description|
| -------- | -------- |-------- |
| NONE   | 0 |The keyboard request is triggered for no reason.|
| MOUSE  | 1 |The keyboard request is triggered by a mouse operation.|
| TOUCH  | 2 |The keyboard request is triggered by a touch operation.|
| OTHER  | 20 |The keyboard request is triggered by other reasons.|

## MessageHandler<sup>15+</sup>

Represents a custom communication object.

> **NOTE**
>
> You can register this object to receive custom communication data sent by the input method application. When the custom communication data is received, the [onMessage](#onmessage15) callback in this object is triggered.
>
> This object is globally unique. After multiple registrations, only the last registered object is valid and retained, and the [onTerminated](#onterminated15) callback of the penultimate registered object is triggered.
>
> If this object is unregistered, its [onTerminated](#onterminated15) callback will be triggered.

### onMessage<sup>15+</sup>

onMessage(msgId: string, msgParam?: ArrayBuffer): void

Receives custom data sent by the input method application.

> **NOTE**
>
> This callback is triggered when the registered MeesageHandler receives custom communication data sent by the input method application.
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

let inputMethodController = inputMethod.getController();
try {
    let messageHandler: inputMethod.MessageHandler = {
        onTerminated(): void {
            console.info('OnTerminated.');
        },
        onMessage(msgId: string, msgParam?:ArrayBuffer): void {
            console.info('recv message.');
        }
    }
    inputMethodController.recvMessage(messageHandler);
} catch(err) {
  console.error(`Failed to recvMessage: ${JSON.stringify(err)}`);
}
```

### onTerminated<sup>15+</sup>

onTerminated(): void

Listens for MessageHandler termination.

> **NOTE**
>
> When an application registers a new MessageHandler object, the **OnTerminated** callback of the previous registered MessageHandler object is triggered.
>
> When an application unregisters a MessageHandler object, the **OnTerminated** callback of the current registered MessageHandler object is triggered.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodController = inputMethod.getController();
try {
    let messageHandler: inputMethod.MessageHandler = {
        onTerminated(): void {
            console.info('OnTerminated.');
        },
        onMessage(msgId: string, msgParam?:ArrayBuffer): void {
            console.info('recv message.');
        }
    }
    inputMethodController.recvMessage(messageHandler);
} catch(err) {
  console.error(`Failed to recvMessage: ${JSON.stringify(err)}`);
}
```

## SetPreviewTextCallback<sup>17+</sup>

type SetPreviewTextCallback = (text: string, range: Range) => void

Callback triggered when the input method framework needs to display the text preview.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name      | Type         | Mandatory| Description                         |
| ------- | ----------------- | ---- | ----------------------------- |
| text    | string            | Yes  | Text preview.                |
| range   | [Range](#range10) | Yes  | Describes the range of the selected text.|

## InputMethodController

In the following API examples, you must first use [getController](#inputmethodgetcontroller9) to obtain an **InputMethodController** instance, and then call the APIs using the obtained instance.

### attach<sup>10+</sup>

attach(showKeyboard: boolean, textConfig: TextConfig, callback: AsyncCallback&lt;void&gt;): void

Attaches a self-drawing component to the input method. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> An input method can use the following features only when it has a self-drawing component attached to it: showing or hiding the keyboard, updating the cursor information, changing the selection range of the edit box, saving the configuration information, and listening for and processing the information or commands sent by the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| showKeyboard | boolean | Yes| Whether to start the input method keyboard after the self-drawing component is attached to the input method.<br>- **true** means to start the input method keyboard.<br>- **false** means not to start the input method keyboard.|
| textConfig | [TextConfig](#textconfig10) | Yes| Configuration of the edit box.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let textConfig: inputMethod.TextConfig = {
    inputAttribute: {
      textInputType: 0,
      enterKeyType: 1
    }
  };
  inputMethodController.attach(true, textConfig, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to attach: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in attaching the inputMethod.');
  });
} catch(err) {
  console.error(`Failed to attach: ${JSON.stringify(err)}`);
}
```

### attach<sup>10+</sup>

attach(showKeyboard: boolean, textConfig: TextConfig): Promise&lt;void&gt;

Attaches a self-drawing component to the input method. This API uses a promise to return the result.

> **NOTE**
>
> An input method can use the following features only when it has a self-drawing component attached to it: showing or hiding the keyboard, updating the cursor information, changing the selection range of the edit box, saving the configuration information, and listening for and processing the information or commands sent by the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| showKeyboard | boolean | Yes| Whether to start the input method keyboard after the self-drawing component is attached to the input method.<br>- **true** means to start the input method keyboard.<br>- **false** means not to start the input method keyboard.|
| textConfig | [TextConfig](#textconfig10) | Yes| Configuration of the edit box.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let textConfig: inputMethod.TextConfig = {
    inputAttribute: {
      textInputType: 0,
      enterKeyType: 1
    }
  };
  inputMethodController.attach(true, textConfig).then(() => {
    console.info('Succeeded in attaching inputMethod.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to attach: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to attach: ${JSON.stringify(err)}`);
}
```

### attach<sup>15+</sup>

attach(showKeyboard: boolean, textConfig: TextConfig, requestKeyboardReason: RequestKeyboardReason): Promise&lt;void&gt;

Attaches a self-drawing component to the input method. This API uses a promise to return the result.

> **NOTE**
>
> An input method can use the following features only when it has a self-drawing component attached to it: showing or hiding the keyboard, updating the cursor information, changing the selection range of the edit box, saving the configuration information, and listening for and processing the information or commands sent by the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| showKeyboard | boolean | Yes| Whether to start the input method keyboard after the self-drawing component is attached to the input method.<br>- **true** means to start the input method keyboard.<br>- **false** means not to start the input method keyboard.|
| textConfig | [TextConfig](#textconfig10) | Yes| Configuration of the edit box.|
| requestKeyboardReason | [RequestKeyboardReason](#requestkeyboardreason15) | Yes| Reason for keyboard request.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let textConfig: inputMethod.TextConfig = {
    inputAttribute: {
      textInputType: 0,
      enterKeyType: 1
    }
  };

  let requestKeyboardReason: inputMethod.RequestKeyboardReason = inputMethod.RequestKeyboardReason.MOUSE;

  inputMethodController.attach(true, textConfig, requestKeyboardReason).then(() => {
    console.info('Succeeded in attaching inputMethod.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to attach: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to attach: ${JSON.stringify(err)}`);
}
```

### discardTypingText<sup>20+</sup>

discardTypingText(): Promise&lt;void&gt;

Discards the text that is being typed. This API uses a promise to return the result.

> **NOTE**
>
> This API can be called after the edit box is attached to an input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the result. Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800009 | input method client detached. |
| 12800015 | the other side does not accept the request. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { inputMethod } from '@kit.IMEKit';

inputMethod.getController().discardTypingText().then(() => {
  console.info('Succeeded discardTypingText.');
}).catch((err: BusinessError) => {
  console.error(`Failed to discardTypingText errCode:${err.code}, errMsg:${err.message}`);
});
```

### showTextInput<sup>10+</sup>

showTextInput(callback: AsyncCallback&lt;void&gt;): void

Enters the text editing mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> After the edit box is attached to an input method, this API can be called to start the soft keyboard and enter the text editing state.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.showTextInput((err: BusinessError) => {
  if (err) {
    console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in showing the inputMethod.');
});
```

### showTextInput<sup>10+</sup>

showTextInput(): Promise&lt;void&gt;

Enters the text editing mode. This API uses a promise to return the result.

> **NOTE**
>
> After the edit box is attached to an input method, this API can be called to start the soft keyboard and enter the text editing state.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.showTextInput().then(() => {
  console.info('Succeeded in showing text input.');
}).catch((err: BusinessError) => {
  console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);
});
```

### showTextInput<sup>15+</sup>

showTextInput(requestKeyboardReason: RequestKeyboardReason): Promise&lt;void&gt;

Enters the text editing mode. This API uses a promise to return the result.

> **NOTE**
>
> After the edit box is attached to an input method, this API can be called to start the soft keyboard and enter the text editing state.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| requestKeyboardReason | [RequestKeyboardReason](#requestkeyboardreason15) | Yes| Reason for keyboard request.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let requestKeyboardReason = inputMethod.RequestKeyboardReason.MOUSE;

inputMethodController.showTextInput(requestKeyboardReason).then(() => {
  console.info('Succeeded in showing text input.');
}).catch((err: BusinessError) => {
  console.error(`Failed to showTextInput: ${JSON.stringify(err)}`);
});
```

### hideTextInput<sup>10+</sup>

hideTextInput(callback: AsyncCallback&lt;void&gt;): void

Exits the text editing mode. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> If the soft keyboard is displayed when this API is called, it will be hidden.
>
> Calling this API does not detach the edit box from the input method. The edit box can call [showTextInput](#showtextinput10) again to reenter the text editing mode.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached.             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.hideTextInput((err: BusinessError) => {
  if (err) {
    console.error(`Failed to hideTextInput: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in hiding text input.');
});
```

### hideTextInput<sup>10+</sup>

hideTextInput(): Promise&lt;void&gt;

Exits the text editing mode. This API uses a promise to return the result.

> **NOTE**
>
> If the soft keyboard is displayed when this API is called, it will be hidden.
>
> Calling this API does not detach the edit box from the input method. The edit box can call [showTextInput](#showtextinput10) again to reenter the text editing mode.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.hideTextInput().then(() => {
  console.info('Succeeded in hiding inputMethod.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hideTextInput: ${JSON.stringify(err)}`);
})
```

### detach<sup>10+</sup>

detach(callback: AsyncCallback&lt;void&gt;): void

Detaches the self-drawing component from the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.detach((err: BusinessError) => {
  if (err) {
    console.error(`Failed to detach: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in detaching inputMethod.');
});
```

### detach<sup>10+</sup>

detach(): Promise&lt;void&gt;

Detaches the self-drawing component from the input method. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.detach().then(() => {
  console.info('Succeeded in detaching inputMethod.');
}).catch((err: BusinessError) => {
  console.error(`Failed to detach: ${JSON.stringify(err)}`);
});
```

### setCallingWindow<sup>10+</sup>

setCallingWindow(windowId: number, callback: AsyncCallback&lt;void&gt;): void

Sets the window to be avoided by the input method. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> After the window ID of the application bound to the input method is passed in the API, the input method window will not cover the window holding the application.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowId | number | Yes| Window ID of the application bound to the input method.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached.             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowId: number = 2000;
  inputMethodController.setCallingWindow(windowId, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in setting callingWindow.');
  });
} catch(err) {
  console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### setCallingWindow<sup>10+</sup>

setCallingWindow(windowId: number): Promise&lt;void&gt;

Sets the window to be avoided by the input method. This API uses a promise to return the result.

> **NOTE**
>
> After the window ID of the application bound to the input method is passed in the API, the input method window will not cover the window holding the application.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowId | number | Yes| Window ID of the application bound to the input method.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let windowId: number = 2000;
  inputMethodController.setCallingWindow(windowId).then(() => {
    console.info('Succeeded in setting callingWindow.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to setCallingWindow: ${JSON.stringify(err)}`);
}
```

### updateCursor<sup>10+</sup>

updateCursor(cursorInfo: CursorInfo, callback: AsyncCallback&lt;void&gt;): void

Updates the cursor information in this edit box. This API can be called to notify the input method of the cursor changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| cursorInfo | [CursorInfo](#cursorinfo10) | Yes| Cursor information.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached.             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let cursorInfo: inputMethod.CursorInfo = { left: 0, top: 0, width: 600, height: 800 };
  inputMethodController.updateCursor(cursorInfo, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in updating cursorInfo.');
  });
} catch(err) {
  console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
}
```

### updateCursor<sup>10+</sup>

updateCursor(cursorInfo: CursorInfo): Promise&lt;void&gt;

Updates the cursor information in this edit box. This API can be called to notify the input method of the cursor changes. This API uses a promise to return the result.

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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let cursorInfo: inputMethod.CursorInfo = { left: 0, top: 0, width: 600, height: 800 };
  inputMethodController.updateCursor(cursorInfo).then(() => {
    console.info('Succeeded in updating cursorInfo.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to updateCursor: ${JSON.stringify(err)}`);
}
```

### changeSelection<sup>10+</sup>

changeSelection(text: string, start: number, end: number, callback: AsyncCallback&lt;void&gt;): void

Updates the information about the selected text in this edit box, to notify the input method when the selected text content or text range changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| All input text.|
| start | number | Yes| Start position of the selected text.|
| end | number | Yes| End position of the selected text.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached.             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodController.changeSelection('text', 0, 5, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in changing selection.');
  });
} catch(err) {
  console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
}
```

### changeSelection<sup>10+</sup>

changeSelection(text: string, start: number, end: number): Promise&lt;void&gt;

Updates the information about the selected text in this edit box, to notify the input method when the selected text content or text range changes. This API uses a promise to return the result.

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

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodController.changeSelection('test', 0, 5).then(() => {
    console.info('Succeeded in changing selection.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to changeSelection: ${JSON.stringify(err)}`);
}
```

### updateAttribute<sup>10+</sup>

updateAttribute(attribute: InputAttribute, callback: AsyncCallback&lt;void&gt;): void

Updates the attribute information of this edit box. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| attribute | [InputAttribute](#inputattribute10) | Yes| Attribute information.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached.             |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let inputAttribute: inputMethod.InputAttribute = { textInputType: 0, enterKeyType: 1 };
  inputMethodController.updateAttribute(inputAttribute, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in updating attribute.');
  });
} catch(err) {
  console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
}
```

### updateAttribute<sup>10+</sup>

updateAttribute(attribute: InputAttribute): Promise&lt;void&gt;

Updates the attribute information of this edit box. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| attribute | [InputAttribute](#inputattribute10) | Yes|  Attribute information.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |
| 12800009 | input method client detached. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let inputAttribute: inputMethod.InputAttribute = { textInputType: 0, enterKeyType: 1 };
  inputMethodController.updateAttribute(inputAttribute).then(() => {
    console.info('Succeeded in updating attribute.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to updateAttribute: ${JSON.stringify(err)}`);
}
```

### stopInputSession<sup>9+</sup>

stopInputSession(callback: AsyncCallback&lt;boolean&gt;): void

Ends this input session. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API can be called only when the edit box is attached to the input method. That is, it can be called to end the input session only when the edit box is focused.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodController.stopInputSession((err: BusinessError, result: boolean) => {
    if (err) {
      console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
      return;
    }
    if (result) {
      console.info('Succeeded in stopping inputSession.');
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

> **NOTE**
>
> This API can be called only when the edit box is attached to the input method. That is, it can be called to end the input session only when the edit box is focused.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the operation is successful, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodController.stopInputSession().then((result: boolean) => {
    if (result) {
      console.info('Succeeded in stopping inputSession.');
    } else {
      console.error('Failed to stopInputSession.');
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to stopInputSession: ${JSON.stringify(err)}`);
}
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

Shows the soft keyboard. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API can be called only when the edit box is attached to the input method. That is, it can be called to show the soft keyboard only when the edit box is focused.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.showSoftKeyboard((err: BusinessError) => {
  if (!err) {
    console.info('Succeeded in showing softKeyboard.');
  } else {
    console.error(`Failed to show softKeyboard: ${JSON.stringify(err)}`);
  }
})
```

### showSoftKeyboard<sup>9+</sup>

showSoftKeyboard(): Promise&lt;void&gt;

Shows the soft keyboard. This API uses a promise to return the result.

> **NOTE**
>
> This API can be called only when the edit box is attached to the input method. That is, it can be called to show the soft keyboard only when the edit box is focused.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.showSoftKeyboard().then(() => {
  console.info('Succeeded in showing softKeyboard.');
}).catch((err: BusinessError) => {
  console.error(`Failed to show softKeyboard: ${JSON.stringify(err)}`);
});
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(callback: AsyncCallback&lt;void&gt;): void

Hides the soft keyboard. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API can be called only when the edit box is attached to the input method. That is, it can be called to hide the soft keyboard only when the edit box is focused.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.hideSoftKeyboard((err: BusinessError) => {
  if (!err) {
    console.info('Succeeded in hiding softKeyboard.');
  } else {
    console.error(`Failed to hide softKeyboard: ${JSON.stringify(err)}`);
  }
})
```

### hideSoftKeyboard<sup>9+</sup>

hideSoftKeyboard(): Promise&lt;void&gt;

Hides the soft keyboard. This API uses a promise to return the result.

> **NOTE**
>
> This API can be called only when the edit box is attached to the input method. That is, it can be called to hide the soft keyboard only when the edit box is focused.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY (for system applications only)

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 12800003 | input method client error. Possible causes: 1.the edit box is not focused. 2.no edit box is bound to current input method application. |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.hideSoftKeyboard().then(() => {
  console.info('Succeeded in hiding softKeyboard.');
}).catch((err: BusinessError) => {
  console.error(`Failed to hide softKeyboard: ${JSON.stringify(err)}`);
});
```

### sendMessage<sup>15+</sup>

sendMessage(msgId: string, msgParam?: ArrayBuffer): Promise<void&gt;

Sends the custom communication to the input method application. This API uses a promise to return the result.

> **NOTE**
>
> This API can be called only when the edit box is attached to the input method and enter the edit mode, and the input method application is in full experience mode.
>
> The maximum length of **msgId** is 256 B, and the maximum length of **msgParam** is 128 KB.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type       | Mandatory| Description                                      |
| -------- | ----------- | ---- | ------------------------------------------ |
| msgId    | string      | Yes  | Identifier of the custom data to be sent to the input method application.|
| msgParam | ArrayBuffer | No  | Message body of the custom data to be sent to the input method application.|

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
inputMethodController.sendMessage(msgId, msgParam).then(() => {
  console.info('Succeeded send message.');
}).catch((err: BusinessError) => {
  console.error(`Failed to send message: ${JSON.stringify(err)}`);
});
```

### recvMessage<sup>15+</sup>

recvMessage(msgHandler?: MessageHandler): void

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
| msgHandler | [MessageHandler](#messagehandler15) | No  | This object receives custom communication data from the input method application through [onMessage](#onmessage15) and receives a message for terminating the subscription to this object through [onTerminated](#onterminated15).<br>If no parameter is set, unregister [MessageHandler](#messagehandler15). Its [onTerminated](#onterminated15) callback will be triggered.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message        |
| -------- | ---------------- |
| 401      | parameter error. Possible causes: 1. Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
let messageHandler: inputMethod.MessageHandler = {
    onTerminated(): void {
        console.info('OnTerminated.');
    },
    onMessage(msgId: string, msgParam?:ArrayBuffer): void {
        console.info('recv message.');
    }
}
inputMethodController.recvMessage(messageHandler);
inputMethodController.recvMessage();
```

### stopInput<sup>(deprecated)</sup>

stopInput(callback: AsyncCallback&lt;boolean&gt;): void

Ends this input session. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API can be called only when the edit box is attached to the input method. That is, it can be called to end the input session only when the edit box is focused.
> 
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [stopInputSession()](#stopinputsession9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.stopInput((err: BusinessError, result: boolean) => {
  if (err) {
    console.error(`Failed to stopInput: ${JSON.stringify(err)}`);
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

Ends this input session. This API uses a promise to return the result.

> **NOTE**
> 
> This API can be called only when the edit box is attached to the input method. That is, it can be called to end the input session only when the edit box is focused.
> 
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [stopInputSession()](#stopinputsession9) instead.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the operation is successful, and **false** means the opposite.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodController.stopInput().then((result: boolean) => {
  if (result) {
    console.info('Succeeded in stopping input.');
  } else {
    console.error('Failed to stopInput.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to stopInput: ${JSON.stringify(err)}`);
})
```

### on('insertText')<sup>10+</sup>

on(type: 'insertText', callback: (text: string) => void): void

Enables listening for the text insertion event of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Listening type. The value is fixed at **'insertText'**.|
| callback | (text: string) => void | Yes  | Callback used to return the text to be inserted.<br>The application needs to operate the content in the edit box based on the text content returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**Example**

```ts
function callback1(text: string) {
  console.info('Succeeded in getting callback1 data: ' + JSON.stringify(text));
}

function callback2(text: string) {
  console.info('Succeeded in getting callback2 data: ' + JSON.stringify(text));
}

try {
  inputMethodController.on('insertText', callback1);
  inputMethodController.on('insertText', callback2);
  // Cancel only callback1 of insertText.
  inputMethodController.off('insertText', callback1);
  // Cancel all callbacks of insertText.
  inputMethodController.off('insertText');
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
| type     | string                 | Yes  | Listening type. The value is fixed at **'insertText'**.|
| callback | (text: string) => void | No  | Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
let onInsertTextCallback = (text: string) => {
    console.info(`Succeeded in subscribing insertText: ${text}`);
};
inputMethodController.off('insertText', onInsertTextCallback);
inputMethodController.off('insertText');
```

### on('deleteLeft')<sup>10+</sup>

on(type: 'deleteLeft', callback: (length: number) => void): void

Enables listening for the leftward delete event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | ----- | ---- | ----- |
| type     | string  | Yes  | Listening type. The value is fixed at **'deleteLeft'**.|
| callback | (length: number) => void | Yes  | Callback used to return the length of the text to be deleted leftward.<br>The application needs to operate the content in the edit box based on the length returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**Example**

```ts
try {
  inputMethodController.on('deleteLeft', (length: number) => {
    console.info(`Succeeded in subscribing deleteLeft, length: ${length}`);
  });
} catch(err) {
  console.error(`Failed to subscribe deleteLeft: ${JSON.stringify(err)}`);
}
```

### off('deleteLeft')<sup>10+</sup>

off(type: 'deleteLeft', callback?: (length: number) => void): void

Disables listening for the leftward delete event.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                    | Mandatory| Description                                                        |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                   | Yes  | Listening type. The value is fixed at **'deleteLeft'**.|
| callback | (length: number) => void | No  | Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
let onDeleteLeftCallback = (length: number) => {
    console.info(`Succeeded in subscribing deleteLeft, length: ${length}`);
};
inputMethodController.off('deleteLeft', onDeleteLeftCallback);
inputMethodController.off('deleteLeft');
```

### on('deleteRight')<sup>10+</sup>

on(type: 'deleteRight', callback: (length: number) => void): void

Enables listening for the rightward delete event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | ----- | ---- | ----- |
| type     | string  | Yes  | Listening type. The value is fixed at **'deleteRight'**.|
| callback | (length: number) => void | Yes  | Callback used to return the length of the text to be deleted rightward.<br>The application needs to operate the content in the edit box based on the length returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**Example**

```ts
try {
  inputMethodController.on('deleteRight', (length: number) => {
    console.info(`Succeeded in subscribing deleteRight, length: ${length}`);
  });
} catch(err) {
  console.error(`Failed to subscribe deleteRight: ${JSON.stringify(err)}`);
}
```

### off('deleteRight')<sup>10+</sup>

off(type: 'deleteRight', callback?: (length: number) => void): void

Disables listening for the rightward delete event.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                    | Mandatory| Description                                                        |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                   | Yes  | Listening type. The value is fixed at `deleteRight`.|
| callback | (length: number) => void | No  | Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
let onDeleteRightCallback = (length: number) => {
    console.info(`Succeeded in subscribing deleteRight, length: ${length}`);
};
inputMethodController.off('deleteRight', onDeleteRightCallback);
inputMethodController.off('deleteRight');
```

### on('sendKeyboardStatus')<sup>10+</sup>

on(type: 'sendKeyboardStatus', callback: (keyboardStatus: KeyboardStatus) => void): void

Enables listening for the soft keyboard status event of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type | Mandatory| Description   |
| -------- | ------ | ---- | ---- |
| type     | string  | Yes  | Listening type. The value is fixed at **'sendKeyboardStatus'**.|
| callback | (keyboardStatus: [KeyboardStatus](#keyboardstatus10)) => void | Yes  | Callback used to return the soft keyboard status.<br>The application needs to perform operations based on the soft keyboard state returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**Example**

```ts
try {
  inputMethodController.on('sendKeyboardStatus', (keyboardStatus: inputMethod.KeyboardStatus) => {
    console.info(`Succeeded in subscribing sendKeyboardStatus, keyboardStatus: ${keyboardStatus}`);
  });
} catch(err) {
  console.error(`Failed to subscribe sendKeyboardStatus: ${JSON.stringify(err)}`);
}
```

### off('sendKeyboardStatus')<sup>10+</sup>

off(type: 'sendKeyboardStatus', callback?: (keyboardStatus: KeyboardStatus) => void): void

Disables listening for the soft keyboard status event of the input method.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Listening type. The value is fixed at **'sendKeyboardStatus'**.|
| callback | (keyboardStatus: [KeyboardStatus](#keyboardstatus10)) => void | No  | Callback used for disable listening. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
let onSendKeyboardStatus = (keyboardStatus: inputMethod.KeyboardStatus) => {
    console.info(`Succeeded in subscribing sendKeyboardStatus, keyboardStatus: ${keyboardStatus}`);
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
| type     | string  | Yes  | Listening type. The value is fixed at **'sendFunctionKey'**.|
| callback | (functionKey: [FunctionKey](#functionkey10)) => void | Yes  | Callback used to return the function key information sent by the input method.<br>The application needs to perform operations based on the function key information returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**Example**

```ts
try {
  inputMethodController.on('sendFunctionKey', (functionKey: inputMethod.FunctionKey) => {
    console.info(`Succeeded in subscribing sendFunctionKey, functionKey.enterKeyType: ${functionKey.enterKeyType}`);
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
| type     | string                                               | Yes  | Listening type. The value is fixed at **'sendFunctionKey'**.|
| callback | (functionKey: [FunctionKey](#functionkey10)) => void | No  | Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
let onSendFunctionKey = (functionKey: inputMethod.FunctionKey) => {
    console.info(`Succeeded in subscribing sendFunctionKey, functionKey: ${functionKey.enterKeyType}`);
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
| type     | string | Yes  | Listening type. The value is fixed at **'moveCursor'**.|
| callback | (direction: [Direction](#direction10)) => void | Yes  | Callback used to return the cursor movement direction.<br>The application needs to change the cursor position based on the cursor movement direction returned in the callback. |

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                          |
| -------- | -------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**Example**

```ts
try {
  inputMethodController.on('moveCursor', (direction: inputMethod.Direction) => {
    console.info(`Succeeded in subscribing moveCursor, direction: ${direction}`);
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
| type   | string | Yes  | Listening type. The value is fixed at **'moveCursor'**.|
| callback | (direction: [Direction<sup>10+</sup>](#direction10)) => void | No| Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
let onMoveCursorCallback = (direction: inputMethod.Direction) => {
    console.info(`Succeeded in subscribing moveCursor, direction: ${direction}`);
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
| type     | string    | Yes  | Listening type. The value is fixed at **'handleExtendAction'**.|
| callback | (action: [ExtendAction](#extendaction10)) => void | Yes  | Callback used to return the extended action type.<br>The application needs to perform operations based on the extended action type returned in the callback.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**Example**

```ts
try {
  inputMethodController.on('handleExtendAction', (action: inputMethod.ExtendAction) => {
    console.info(`Succeeded in subscribing handleExtendAction, action: ${action}`);
  });
} catch(err) {
  console.error(`Failed to subscribe handleExtendAction: ${JSON.stringify(err)}`);
}
```

### off('handleExtendAction')<sup>10+</sup>

off(type: 'handleExtendAction', callback?: (action: ExtendAction) => void): void

Disables listening for the extended action handling event of the input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ------ | ---- | ------- |
| type   | string | Yes  | Listening type. The value is fixed at **'handleExtendAction'**.|
| callback | (action: [ExtendAction](#extendaction10)) => void | No| Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
try {
  let onHandleExtendActionCallback = (action: inputMethod.ExtendAction) => {
    console.info(`Succeeded in subscribing handleExtendAction, action: ${action}`);
  };
  inputMethodController.off('handleExtendAction', onHandleExtendActionCallback);
  inputMethodController.off('handleExtendAction');
} catch(err) {
  console.error(`Failed to subscribe handleExtendAction: ${JSON.stringify(err)}`);
}
```

### on('selectByRange')<sup>10+</sup>

on(type: 'selectByRange', callback: Callback&lt;Range&gt;): void

Enables listening for the select-by-range event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type    | Mandatory| Description    |
| -------- | ---- | ---- | ------- |
| type     | string  | Yes  | Listening type. The value is fixed at **'selectByRange'**.|
| callback | Callback&lt;[Range](#range10)&gt; | Yes  | Callback used to return the range of the text to be selected.<br>The application needs to select the text based on the range returned in the callback.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
try {
  inputMethodController.on('selectByRange', (range: inputMethod.Range) => {
    console.info(`Succeeded in subscribing selectByRange: start: ${range.start} , end: ${range.end}`);
  });
} catch(err) {
  console.error(`Failed to subscribe selectByRange: ${JSON.stringify(err)}`);
}
```

### off('selectByRange')<sup>10+</sup>

off(type: 'selectByRange', callback?:  Callback&lt;Range&gt;): void

Disables listening for the select-by-range event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                             | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                            | Yes  | Listening type. The value is fixed at **'selectByRange'**.|
| callback | Callback&lt;[Range](#range10)&gt; | No  | Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
try {
  let onSelectByRangeCallback = (range: inputMethod.Range) => {
    console.info(`Succeeded in subscribing selectByRange, start: ${range.start} , end: ${range.end}`);
  };
  inputMethodController.off('selectByRange', onSelectByRangeCallback);
  inputMethodController.off('selectByRange');
} catch(err) {
  console.error(`Failed to subscribe selectByRange: ${JSON.stringify(err)}`);
}
```

### on('selectByMovement')<sup>10+</sup>

on(type: 'selectByMovement', callback: Callback&lt;Movement&gt;): void

Enables listening for the select-by-cursor-movement event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description    |
| -------- | ----- | ---- | ------ |
| type     | string  | Yes  | Listening type. The value is fixed at **'selectByMovement'**.|
| callback | Callback&lt;[Movement](#movement10)&gt; | Yes  | Callback used to return the direction in which the cursor moves.<br>The application needs to select the text based on the direction returned in the callback.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
try {
  inputMethodController.on('selectByMovement', (movement: inputMethod.Movement) => {
    console.info('Succeeded in subscribing selectByMovement: direction: ' + movement.direction);
  });
} catch(err) {
  console.error(`Failed to subscribe selectByMovement: ${JSON.stringify(err)}`);
}
```

### off('selectByMovement')<sup>10+</sup>

off(type: 'selectByMovement', callback?: Callback&lt;Movement&gt;): void

Disables listening for the select-by-cursor-movement event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                               | Yes  | Listening type. The value is fixed at **'selectByMovement'**.|
| callback | Callback&lt;[Movement](#movement10)> | No  | Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
try {
  let onSelectByMovementCallback = (movement: inputMethod.Movement) => {
    console.info(`Succeeded in subscribing selectByMovement, movement.direction: ${movement.direction}`);
  };
  inputMethodController.off('selectByMovement', onSelectByMovementCallback);
  inputMethodController.off('selectByMovement');
} catch(err) {
  console.error(`Failed to unsubscribing selectByMovement: ${JSON.stringify(err)}`);
}
```

### on('getLeftTextOfCursor')<sup>10+</sup>

on(type: 'getLeftTextOfCursor', callback: (length: number) => string): void

Enables listening for the event of obtaining the length of text deleted leftward. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description    |
| -------- | ----- | ---- | ------ |
| type     | string  | Yes  | Listening type. The value is fixed at **'getLeftTextOfCursor'**.|
| callback | (length: number) => string | Yes  | Callback used to obtain the text of the specified length deleted leftward.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**Example**

```ts
try {
  inputMethodController.on('getLeftTextOfCursor', (length: number) => {
    console.info(`Succeeded in subscribing getLeftTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to unsubscribing getLeftTextOfCursor. err: ${JSON.stringify(err)}`);
}
```

### off('getLeftTextOfCursor')<sup>10+</sup>

off(type: 'getLeftTextOfCursor', callback?: (length: number) => string): void

Disables listening for the event of obtaining the length of text deleted leftward. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Listening type. The value is fixed at **'getLeftTextOfCursor'**.|
| callback | (length: number) => string | No | Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
try {
  let getLeftTextOfCursorCallback = (length: number) => {
    console.info(`Succeeded in unsubscribing getLeftTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  };
  inputMethodController.off('getLeftTextOfCursor', getLeftTextOfCursorCallback);
  inputMethodController.off('getLeftTextOfCursor');
} catch(err) {
  console.error(`Failed to unsubscribing getLeftTextOfCursor. err: ${JSON.stringify(err)}`);
}
```

### on('getRightTextOfCursor')<sup>10+</sup>

on(type: 'getRightTextOfCursor', callback: (length: number) => string): void

Enables listening for the event of obtaining the length of text deleted rightward. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description    |
| -------- | ----- | ---- | ------ |
| type     | string  | Yes  | Listening type. The value is fixed at **'getRightTextOfCursor'**.|
| callback | (length: number) => string | Yes  | Callback used to obtain the text of the specified length deleted rightward.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**Example**

```ts
try {
  inputMethodController.on('getRightTextOfCursor', (length: number) => {
    console.info(`Succeeded in subscribing getRightTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  });
} catch(err) {
  console.error(`Failed to subscribe getRightTextOfCursor. err: ${JSON.stringify(err)}`);
}
```

### off('getRightTextOfCursor')<sup>10+</sup>

off(type: 'getRightTextOfCursor', callback?: (length: number) => string): void

Disables listening for the event of obtaining the length of text deleted rightward. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Listening type. The value is fixed at **'getRightTextOfCursor'**.|
| callback | (length: number) => string | No |Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
try {
  let getRightTextOfCursorCallback = (length: number) => {
    console.info(`Succeeded in unsubscribing getRightTextOfCursor, length: ${length}`);
    let text:string = "";
    return text;
  };
  inputMethodController.off('getRightTextOfCursor', getRightTextOfCursorCallback);
  inputMethodController.off('getRightTextOfCursor');
} catch(err) {
  console.error(`Failed to unsubscribing getRightTextOfCursor. err: ${JSON.stringify(err)}`);
}
```

### on('getTextIndexAtCursor')<sup>10+</sup>

on(type: 'getTextIndexAtCursor', callback: () => number): void

Enables listening for the event of obtaining the index of text at the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description    |
| -------- | ----- | ---- | ------ |
| type     | string  | Yes  | Listening type. The value is fixed at **'getTextIndexAtCursor'**.|
| callback | () => number | Yes  | Callback used to obtain the index of text at the cursor.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800009 | input method client detached. |

**Example**

```ts
try {
  inputMethodController.on('getTextIndexAtCursor', () => {
    console.info(`Succeeded in subscribing getTextIndexAtCursor.`);
    let index:number = 0;
    return index;
  });
} catch(err) {
  console.error(`Failed to subscribe getTextIndexAtCursor. err: ${JSON.stringify(err)}`);
}
```

### off('getTextIndexAtCursor')<sup>10+</sup>

off(type: 'getTextIndexAtCursor', callback?: () => number): void

Disables listening for the event of obtaining the index of text at the cursor. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Listening type. The value is fixed at **'getTextIndexAtCursor'**.|
| callback | () => number | No | Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
try {
  let getTextIndexAtCursorCallback = () => {
    console.info(`Succeeded in unsubscribing getTextIndexAtCursor.`);
    let index:number = 0;
    return index;
  };
  inputMethodController.off('getTextIndexAtCursor', getTextIndexAtCursorCallback);
  inputMethodController.off('getTextIndexAtCursor');
} catch(err) {
  console.error(`Failed to unsubscribing getTextIndexAtCursor. err: ${JSON.stringify(err)}`);
}
```

### on('setPreviewText')<sup>17+</sup>

on(type: 'setPreviewText', callback: SetPreviewTextCallback): void

Subscribes to the event for text preview operations in an input method application. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> To use the text preview function, you need to subscribe to this event before calling [attach](#attach10) and subscribe to this event together with [on('finishTextPreview')](#onfinishtextpreview17).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description    |
| -------- | ----- | ---- | ------ |
| type     | string  | Yes  | Event type, which is **'setPreviewText'**.|
| callback | [SetPreviewTextCallback](#setpreviewtextcallback17) | Yes  | Callback used to return the result. It is used to receive and return the text preview.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
let setPreviewTextCallback1: inputMethod.SetPreviewTextCallback = (text: string, range: inputMethod.Range) => {
  console.info(`SetPreviewTextCallback1: Received text - ${text}, Received range - start: ${range.start}, end: ${range.end}`);
};

let setPreviewTextCallback2: inputMethod.SetPreviewTextCallback = (text: string, range: inputMethod.Range) => {
  console.info(`setPreviewTextCallback2: Received text - ${text}, Received range - start: ${range.start}, end: ${range.end}`);
};

try {
  inputMethodController.on('setPreviewText', setPreviewTextCallback1);
  console.info(`SetPreviewTextCallback1 subscribed to setPreviewText`);
  inputMethodController.on('setPreviewText', setPreviewTextCallback2);
  console.info(`SetPreviewTextCallback2 subscribed to setPreviewText`);
  // Cancel only the callback1 of setPreviewText.
  inputMethodController.off('setPreviewText', setPreviewTextCallback1);
  console.info(`SetPreviewTextCallback1 unsubscribed from setPreviewText`);
  // Cancel all callbacks of setPreviewText.
  inputMethodController.off('setPreviewText');
  console.info(`All callbacks unsubscribed from setPreviewText`);
} catch(err) {
  console.error(`Failed to operate on setPreviewText: ${JSON.stringify(err)}`);
}
```

### off('setPreviewText')<sup>17+</sup>

off(type: 'setPreviewText', callback?: SetPreviewTextCallback): void

Unsubscribes from the event for text preview operations in an input method application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'setPreviewText'**.|
| callback | [SetPreviewTextCallback](#setpreviewtextcallback17) | No | Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
let setPreviewTextCallback1: inputMethod.SetPreviewTextCallback = (text: string, range: inputMethod.Range) => {
  console.info(`SetPreviewTextCallback1: Received text - ${text}, Received range - start: ${range.start}, end: ${range.end}`);
};

let setPreviewTextCallback2: inputMethod.SetPreviewTextCallback = (text: string, range: inputMethod.Range) => {
  console.info(`setPreviewTextCallback2: Received text - ${text}, Received range - start: ${range.start}, end: ${range.end}`);
};

try {
  inputMethodController.on('setPreviewText', setPreviewTextCallback1);
  console.info(`SetPreviewTextCallback1 subscribed to setPreviewText`);
  inputMethodController.on('setPreviewText', setPreviewTextCallback2);
  console.info(`SetPreviewTextCallback2 subscribed to setPreviewText`);
  // Cancel only the callback1 of setPreviewText.
  inputMethodController.off('setPreviewText', setPreviewTextCallback1);
  console.info(`SetPreviewTextCallback1 unsubscribed from setPreviewText`);
  // Cancel all callbacks of setPreviewText.
  inputMethodController.off('setPreviewText');
  console.info(`All callbacks unsubscribed from setPreviewText`);
} catch(err) {
  console.error(`Failed to operate on setPreviewText: ${JSON.stringify(err)}`);
}
```

### on('finishTextPreview')<sup>17+</sup>

on(type: 'finishTextPreview', callback: Callback&lt;void&gt;): void

Subscribes to the event of finishing text preview. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> To use the text preview function, you need to subscribe to this event before calling [attach](#attach10) and subscribe to this event together with [on('setPreviewText')](#onsetpreviewtext17).

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type  | Mandatory| Description    |
| -------- | ----- | ---- | ------ |
| type     | string  | Yes  | Event type, which is **'finishTextPreview'**.|
| callback | Callback&lt;void&gt; | Yes  | Callback used to return the result. It is used to process the logic of finishing text preview. Return type: void|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |

**Example**

```ts
let finishTextPreviewCallback1 = () => {
  console.info(`FinishTextPreviewCallback1: finishTextPreview event triggered`);
};
let finishTextPreviewCallback2 = () => {
  console.info(`FinishTextPreviewCallback2: finishTextPreview event triggered`);
};

try {
  inputMethodController.on('finishTextPreview', finishTextPreviewCallback1);
  console.info(`FinishTextPreviewCallback1 subscribed to finishTextPreview`);
  inputMethodController.on('finishTextPreview', finishTextPreviewCallback2);
  console.info(`FinishTextPreviewCallback2 subscribed to finishTextPreview`);
  // Cancel only the callback1 of finishTextPreview.
  inputMethodController.off('finishTextPreview', finishTextPreviewCallback1);
  console.info(`FinishTextPreviewCallback1 unsubscribed from finishTextPreview`);
  // Cancel all callbacks of finishTextPreview.
  inputMethodController.off('finishTextPreview');
  console.info(`All callbacks unsubscribed from finishTextPreview`);
} catch(err) {
  console.error(`Failed to operate on finishTextPreview (subscribe/off): ${JSON.stringify(err)}`);
}
```

### off('finishTextPreview')<sup>17+</sup>

off(type: 'finishTextPreview', callback?: Callback&lt;void&gt;): void

Unsubscribes from the event of finishing text preview. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | Yes  | Event type, which is **'finishTextPreview'**.|
| callback | Callback&lt;void&gt; | No | Callback used for disable listening, which must be the same as that passed by the **on** API.<br>If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
let finishTextPreviewCallback1 = () => {
  console.info(`FinishTextPreviewCallback1: finishTextPreview event triggered`);
};
let finishTextPreviewCallback2 = () => {
  console.info(`FinishTextPreviewCallback2: finishTextPreview event triggered`);
};

try {
  inputMethodController.on('finishTextPreview', finishTextPreviewCallback1);
  console.info(`FinishTextPreviewCallback1 subscribed to finishTextPreview`);
  inputMethodController.on('finishTextPreview', finishTextPreviewCallback2);
  console.info(`FinishTextPreviewCallback2 subscribed to finishTextPreview`);
  // Cancel only the callback1 of finishTextPreview.
  inputMethodController.off('finishTextPreview', finishTextPreviewCallback1);
  console.info(`FinishTextPreviewCallback1 unsubscribed from finishTextPreview`);
  // Cancel all callbacks of finishTextPreview.
  inputMethodController.off('finishTextPreview');
  console.info(`All callbacks unsubscribed from finishTextPreview`);
} catch(err) {
  console.error(`Failed to operate on finishTextPreview (subscribe/off): ${JSON.stringify(err)}`);
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
| type     | string                        | Yes  | Listening type. The value is fixed at **'imeChange'**.|
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)) => void  | Yes| Callback used to return the input method attributes and subtype.|

**Example**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
try {
  inputMethodSetting.on('imeChange', (inputMethodProperty: inputMethod.InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => {
    console.info('Succeeded in subscribing imeChange: inputMethodProperty: ' + JSON.stringify(inputMethodProperty) + " , inputMethodSubtype: " + JSON.stringify(inputMethodSubtype));
  });
} catch(err) {
  console.error(`Failed to subscribing imeChange. Code: ${err.code}, Message: ${err.message}`);
}
```

### off('imeChange')<sup>9+</sup>

off(type: 'imeChange', callback?: (inputMethodProperty: InputMethodProperty, inputMethodSubtype: InputMethodSubtype) => void): void

Disables listening for the input method and subtype change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type   | Mandatory| Description         |
| -------- | --------- | ---- | --------------- |
| type     | string    | Yes  | Listening type. The value is fixed at **'imeChange'**.|
| callback | (inputMethodProperty: [InputMethodProperty](#inputmethodproperty8), inputMethodSubtype: [InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)) => void  | No| Callback used to return the input method attributes and subtype.|

**Example**

```ts
inputMethodSetting.off('imeChange');
```

### listInputMethodSubtype<sup>9+</sup>

listInputMethodSubtype(inputMethodProperty: InputMethodProperty, callback: AsyncCallback&lt;Array&lt;InputMethodSubtype&gt;&gt;): void

Obtains all subtypes of a specified input method. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                              | Mandatory| Description                  |
| -------- | -------------------------------------------------- | ---- | ---------------------- |
| inputMethodProperty | [InputMethodProperty](#inputmethodproperty8)| Yes| Input method.|
| callback | AsyncCallback&lt;Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>&gt; | Yes| Callback used to return all subtypes of the specified input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800001 | bundle manager error.                 |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodProperty: inputMethod.InputMethodProperty = {
  name: 'com.example.kikakeyboard',
  id: 'propertyId',
  packageName: 'com.example.kikakeyboard',
  methodId: 'propertyId',
}
let inputMethodSetting = inputMethod.getSetting();
try {
  inputMethodSetting.listInputMethodSubtype(inputMethodProperty, (err: BusinessError, data: Array<InputMethodSubtype>) => {
    if (err) {
      console.error(`Failed to listInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in listing inputMethodSubtype.');
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
| inputMethodProperty | [InputMethodProperty](#inputmethodproperty8)| Yes| Input method.|

**Return value**

| Type                                                       | Description                  |
| ----------------------------------------------------------- | ---------------------- |
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>> | Promise used to return all subtypes of the specified input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800001 | bundle manager error.                 |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodProperty: inputMethod.InputMethodProperty = {
  name: 'com.example.kikakeyboard',
  id: 'propertyId',
  packageName: 'com.example.kikakeyboard',
  methodId: 'propertyId',
}
let inputMethodSetting = inputMethod.getSetting();
try {
  inputMethodSetting.listInputMethodSubtype(inputMethodProperty).then((data: Array<InputMethodSubtype>) => {
    console.info('Succeeded in listing inputMethodSubtype.');
  }).catch((err: BusinessError) => {
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
| callback | AsyncCallback&lt;Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>&gt; | Yes  | Callback used to return all subtypes of the current input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | bundle manager error.                 |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodSetting = inputMethod.getSetting();
try {
  inputMethodSetting.listCurrentInputMethodSubtype((err: BusinessError, data: Array<InputMethodSubtype>) => {
    if (err) {
      console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in listing currentInputMethodSubtype.');
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
| Promise<Array<[InputMethodSubtype](./js-apis-inputmethod-subtype.md#inputmethodsubtype)>> | Promise used to return all subtypes of the current input method.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800001 | bundle manager error.                 |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { InputMethodSubtype } from '@kit.IMEKit';
import { BusinessError } from '@kit.BasicServicesKit';

let inputMethodSetting = inputMethod.getSetting();
try {
  inputMethodSetting.listCurrentInputMethodSubtype().then((data: Array<InputMethodSubtype>) => {
    console.info('Succeeded in listing currentInputMethodSubtype.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to listCurrentInputMethodSubtype: ${JSON.stringify(err)}`);
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean, callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

Obtains a list of activated or deactivated input methods. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> An activated input method refers to an input method that is enabled. The default input method is enabled by default. Other input methods can be enabled or disabled as needed.
> 
> The list of activated input methods includes the default input method and enabled input methods. The list of deactivated input methods includes all installed input methods except the enabled ones.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                               | Mandatory| Description                         |
| -------- | --------------------------------------------------- | ---- | ----------------------------- |
| enable   | boolean                                             | Yes  |Whether to return a list of activated input methods. The value **true** means to return a list of activated input methods, and **false** means to return a list of deactivated input methods.|
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; |  Yes | Callback used to return a list of activated or deactivated input methods.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800001 | bundle manager error.               |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodSetting.getInputMethods(true, (err: BusinessError, data: Array<inputMethod.InputMethodProperty>) => {
    if (err) {
      console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in getting inputMethods.');
  });
} catch (err) {
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
}
```

### getInputMethods<sup>9+</sup>

getInputMethods(enable: boolean): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

Obtains a list of activated or deactivated input methods. This API uses a promise to return the result.

> **NOTE**
> 
> An activated input method refers to an input method that is enabled. The default input method is enabled by default. Other input methods can be enabled or disabled as needed.
> 
> The list of activated input methods includes the default input method and enabled input methods. The list of deactivated input methods includes all installed input methods except the enabled ones.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type   | Mandatory| Description                   |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | Yes  |Whether to return a list of activated input methods. The value **true** means to return a list of activated input methods, and **false** means to return a list of deactivated input methods.|

**Return value**

| Type                                                        | Description                                      |
| ------------------------------------------------------------ | ------------------------------------------ |
| Promise\<Array\<[InputMethodProperty](#inputmethodproperty8)>> | Promise used to return a list of activated or deactivated input methods.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800001 | bundle manager error.               |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodSetting.getInputMethods(true).then((data: Array<inputMethod.InputMethodProperty>) => {
    console.info('Succeeded in getting inputMethods.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
  })
} catch(err) {
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
}
```

### getInputMethodsSync<sup>11+</sup>

getInputMethodsSync(enable: boolean): Array&lt;InputMethodProperty&gt;

Obtains a list of activated or deactivated input methods. This API returns the result synchronously.

> **NOTE**
>
> An activated input method refers to an input method that is enabled. The default input method is enabled by default. Other input methods can be enabled or disabled as needed.
>
> The list of activated input methods includes the default input method and enabled input methods. The list of deactivated input methods includes all installed input methods except the enabled ones.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type   | Mandatory| Description                   |
| ------ | ------- | ---- | ----------------------- |
| enable | boolean | Yes  |Whether to return a list of activated input methods. The value **true** means to return a list of activated input methods, and **false** means to return a list of deactivated input methods.|

**Return value**

| Type                                                | Description                         |
| ---------------------------------------------------- | ----------------------------- |
| Array\<[InputMethodProperty](#inputmethodproperty8)> | List of activated or deactivated input methods.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800001 | bundle manager error.                 |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
try {
  let imeProperty = inputMethodSetting.getInputMethodsSync(true);
} catch(err) {
  console.error(`Failed to getInputMethods: ${JSON.stringify(err)}`);
}
```

### getAllInputMethods<sup>11+</sup>

getAllInputMethods(callback: AsyncCallback&lt;Array&lt;InputMethodProperty&gt;&gt;): void

Obtains a list of all input methods. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type                                                        | Mandatory| Description                          |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------ |
| callback | AsyncCallback&lt;Array<[InputMethodProperty](#inputmethodproperty8)>&gt; | Yes  | Callback used to return a list of all input methods.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 12800001 | bundle manager error.               |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodSetting.getAllInputMethods((err: BusinessError, data: Array<inputMethod.InputMethodProperty>) => {
    if (err) {
      console.error(`Failed to getAllInputMethods: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in getting all inputMethods.');
  });
} catch (err) {
  console.error(`Failed to getAllInputMethods: ${JSON.stringify(err)}`);
}
```

### getAllInputMethods<sup>11+</sup>

getAllInputMethods(): Promise&lt;Array&lt;InputMethodProperty&gt;&gt;

Obtains a list of all input methods. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise\<Array\<[InputMethodProperty](#inputmethodproperty8)>> | Promise used to return a list of all input methods.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 12800001 | bundle manager error.              |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.getAllInputMethods().then((data: Array<inputMethod.InputMethodProperty>) => {
  console.info('Succeeded in getting all inputMethods.');
}).catch((err: BusinessError) => {
  console.error(`Failed to getAllInputMethods: ${JSON.stringify(err)}`);
})
```

### getAllInputMethodsSync<sup>11+</sup>

getAllInputMethodsSync(): Array&lt;InputMethodProperty&gt;

Obtains a list of all input methods. This API returns the result synchronously.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                                | Description              |
| ---------------------------------------------------- | ------------------ |
| Array\<[InputMethodProperty](#inputmethodproperty8)> | List of all input methods.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 12800001 | bundle manager error.              |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
try {
  let imeProperty = inputMethodSetting.getAllInputMethodsSync();
} catch(err) {
  console.error(`Failed to getAllInputMethodsSync: ${JSON.stringify(err)}`);
}
```

### showOptionalInputMethods<sup>(deprecated)</sup>

showOptionalInputMethods(callback: AsyncCallback&lt;boolean&gt;): void

Displays a dialog box for selecting an input method. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 18.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  inputMethodSetting.showOptionalInputMethods((err: BusinessError, data: boolean) => {
    if (err) {
      console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);
      return;
    }
    console.info('Succeeded in showing optionalInputMethods.');
  });
} catch (err) {
  console.error(`Failed to showOptionalInputMethods: ${JSON.stringify(err)}`);
}
```

### showOptionalInputMethods<sup>(deprecated)</sup>

showOptionalInputMethods(): Promise&lt;boolean&gt;

Displays a dialog box for selecting an input method. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 18.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.showOptionalInputMethods().then((data: boolean) => {
  console.info('Succeeded in showing optionalInputMethods.');
}).catch((err: BusinessError) => {
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.listInputMethod((err: BusinessError, data: Array<inputMethod.InputMethodProperty>) => {
  if (err) {
    console.error(`Failed to listInputMethod: ${JSON.stringify(err)}`);
    return;
  }
  console.info('Succeeded in listing inputMethod.');
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.listInputMethod().then((data: Array<inputMethod.InputMethodProperty>) => {
  console.info('Succeeded in listing inputMethod.');
}).catch((err: BusinessError) => {
  console.error(`Failed to listInputMethod: ${JSON.stringify(err)}`);
})
```

### displayOptionalInputMethod<sup>(deprecated)</sup>

displayOptionalInputMethod(callback: AsyncCallback&lt;void&gt;): void

Displays a dialog box for selecting an input method. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.displayOptionalInputMethod((err: BusinessError) => {
  if (err) {
    console.error(`Failed to displayOptionalInputMethod: ${JSON.stringify(err)}`);
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
> This API is supported since API version 8 and deprecated since API version 9.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.displayOptionalInputMethod().then(() => {
  console.info('Succeeded in displaying optionalInputMethod.');
}).catch((err: BusinessError) => {
  console.error(`Failed to displayOptionalInputMethod: ${JSON.stringify(err)}`);
})
```

### getInputMethodState<sup>15+</sup>

getInputMethodState(): Promise&lt;EnabledState&gt;

Obtains the input method state. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Return value**

| Type                                   | Description                                                        |
| --------------------------------------- | ------------------------------------------------------------ |
| Promise\<[EnabledState](#enabledstate15)> | Promise used to return the result. **EnabledState.DISABLED** indicates that the input method is disabled, **EnabledState.BASIC_MODE** indicates that the input method is in basic mode, and **EnabledState.FULL_EXPERIENCE_MODE** indicates that the input method is in full experience mode.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 12800004 | not an input method application.    |
| 12800008 | input method manager service error. Possible cause: a system error, such as null pointer, IPC exception. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

inputMethodSetting.getInputMethodState().then((status: inputMethod.EnabledState) => {
  console.info(`Succeeded in getInputMethodState, status: ${status}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to getInputMethodState: ${JSON.stringify(err)}`);
})
```
