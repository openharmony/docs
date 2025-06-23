# @ohos.inputMethod (Input Method Framework) (System API)

The **inputMethod** module is oriented to common foreground applications (system applications such as Notes, Messaging, and Settings). It provides input method control and management capabilities, including displaying or hiding the soft keyboard, switching between input methods, and obtaining the list of all input methods.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { inputMethod } from '@kit.IMEKit';
```

## inputMethod.switchInputMethod<sup>11+</sup>
switchInputMethod(bundleName: string, subtypeId?: string): Promise&lt;void&gt;

Switches to another input method. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  |bundleName |  string| Yes| Bundle name of the target input method.|
  |subtypeId |  string| No| Input method subtype.|

**Return value**

  | Type          | Description                    |
  | -------------- | ----------------------- |
  | Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201      | permissions check fails.  |
| 202      | not system application.  |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.           |
| 12800005 | configuration persistence error.        |
| 12800008 | input method manager service error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentIme = inputMethod.getCurrentInputMethod();
try {
  inputMethod.switchInputMethod(currentIme.name).then(() => {
    console.info('Succeeded in switching inputmethod.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
  })
} catch (err) {
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
}
let currentImeSubType = inputMethod.getCurrentInputMethodSubtype();
try {
  inputMethod.switchInputMethod(currentIme.name, currentImeSubType.id).then(() => {
    console.info('Succeeded in switching inputmethod.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
  })
} catch (err) {
  console.error(`Failed to switchInputMethod: ${JSON.stringify(err)}`);
}
```

## InputMethodSetting<sup>8+</sup>

In the following API examples, you must first use [getSetting](./js-apis-inputmethod.md#inputmethodgetsetting9) to obtain an **InputMethodSetting** instance, and then call the APIs using the obtained instance.

### on('imeShow')<sup>10+</sup>

on(type: 'imeShow', callback: (info: Array\<InputWindowInfo>) => void): void

Subscribes to the soft keyboard show event of the [input method panel](js-apis-inputmethodengine.md#panel10) in the fixed state. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | ---- | ---- | ---- |
| type     | string | Yes| Event type, which is **'imeShow'**.|
| callback | (info: Array<[InputWindowInfo](js-apis-inputmethod.md#inputwindowinfo10)>) => void | Yes| Callback used to return the soft keyboard information of the input method panel in the fixed state.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 202      | not system application.  |

**Example**

```ts
try {
  inputMethodSetting.on('imeShow', (info: Array<inputMethod.InputWindowInfo>) => {
    console.info('Succeeded in subscribing imeShow event.');
  });
} catch(err) {
  console.error(`Failed to unsubscribing imeShow. err: ${JSON.stringify(err)}`);
}
```

### on('imeHide')<sup>10+</sup>

on(type: 'imeHide', callback: (info: Array\<InputWindowInfo>) => void): void

Subscribes to the soft keyboard hide event of the [input method panel](js-apis-inputmethodengine.md#panel10) in the fixed state. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description|
| -------- | ---- | ---- | ---- |
| type     | string | Yes| Event type, which is **'imeHide'**.|
| callback | (info: Array<[InputWindowInfo](js-apis-inputmethod.md#inputwindowinfo10)>) => void | Yes| Callback used to return the soft keyboard information of the input method panel in the fixed state.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 202      | not system application.  |


**Example**

```ts
try {
  inputMethodSetting.on('imeHide', (info: Array<inputMethod.InputWindowInfo>) => {
    console.info('Succeeded in subscribing imeHide event.');
  });
} catch(err) {
  console.error(`Failed to unsubscribing imeHide. err: ${JSON.stringify(err)}`);
}
```

### off('imeShow')<sup>10+</sup>

off(type: 'imeShow', callback?: (info: Array\<InputWindowInfo>) => void): void

Unsubscribes from the soft keyboard show event of the [input method panel](js-apis-inputmethodengine.md#panel10) in the fixed state.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description  |
| -------- | ---- | ---- | ------ |
| type     | string | Yes| Event type, which is **'imeShow'**.|
| callback | (info: Array<[InputWindowInfo](js-apis-inputmethod.md#inputwindowinfo10)>) => void  | No| Callback to unregister.<br>If this parameter is not specified, this API unregisters all callbacks for the specified event type.|

**Example**

```ts
try {
  inputMethodSetting.off('imeShow');
} catch(err) {
  console.error(`Failed to unsubscribing imeShow. err: ${JSON.stringify(err)}`);
}
```

### off('imeHide')<sup>10+</sup>

off(type: 'imeHide', callback?: (info: Array\<InputWindowInfo>) => void): void

Unsubscribes from the soft keyboard hide event of the [input method panel](js-apis-inputmethodengine.md#panel10) in the fixed state.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name  | Type| Mandatory| Description  |
| -------- | ---- | ---- | ------ |
| type     | string | Yes| Event type, which is **'imeHide'**.|
| callback | (info: Array<[InputWindowInfo](js-apis-inputmethod.md#inputwindowinfo10)>) => void  | No| Callback to unregister.<br>If this parameter is not specified, this API unregisters all callbacks for the specified event type.|

**Example**

```ts
try {
  inputMethodSetting.off('imeHide');
} catch(err) {
  console.error(`Failed to unsubscribing imeHide. err: ${JSON.stringify(err)}`);
}
```

### isPanelShown<sup>11+</sup>

isPanelShown(panelInfo: PanelInfo): boolean

Checks whether the input method panel of a specified type is shown.

**System API**: This is a system API.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name   | Type                                                 | Mandatory| Description              |
| --------- | ----------------------------------------------------- | ---- | ------------------ |
| panelInfo | [PanelInfo](./js-apis-inputmethod-panel.md#panelinfo) | Yes  | Information about the input method panel.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Whether the input method panel is shown.<br>- The value **true** means that the input method panel is shown.<br>- The value **false** means that the input method panel is hidden.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | not system application.  |
| 401      | parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 12800008 | input method manager service error. |

**Example**

```ts
import { PanelInfo, PanelType, PanelFlag } from '@kit.IMEKit';

let info: PanelInfo = {
  type: PanelType.SOFT_KEYBOARD,
  flag: PanelFlag.FLAG_FIXED
}
try {
  let result = inputMethodSetting.isPanelShown(info);
  console.info('Succeeded in querying isPanelShown, result: ' + result);
} catch (err) {
  console.error(`Failed to query isPanelShown: ${JSON.stringify(err)}`);
}
```

### enableInputMethod<sup>20+</sup>

enableInputMethod(bundleName: string, extensionName: string, enabledState: EnabledState): Promise&lt;void&gt;

Enables or disables an input method. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CONNECT_IME_ABILITY

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**System API**: This is a system API.

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | bundleName |  string | Yes| Bundle name of the input method.|
  | extensionName |  string | Yes| Extension name of the input method.|
  | enabledState |  [EnabledState](js-apis-inputmethod.md#enabledstate15) | Yes| Whether the input method is enabled.|

**Return value**

  | Type          | Description                    |
  | -------------- | ----------------------- |
  | Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Input Method Framework Error Codes](errorcode-inputmethod-framework.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                            |
| -------- | -------------------------------------- |
| 201      | permissions check fails. |
| 202      | not system application. |
| 12800008 | input method manager service error. |
| 12800018 | the input method is not found. |
| 12800019 | current operation cannot be applied to the preconfigured default input method. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let currentIme = inputMethod.getCurrentInputMethod();
try {
  inputMethodSetting.enableInputMethod(currentIme.name, currentIme.id, inputMethod.EnabledState.BASIC_MODE).then(() => {
    console.info('Succeeded in enable inputmethod.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to enableInputMethod. Code: ${err.code}, message: ${err.message}`);
  })
} catch (err) {
  console.error(`Failed to enableInputMethod. Code: ${err.code}, message: ${err.message}`);
}
```
