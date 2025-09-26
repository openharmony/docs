# @ohos.multimodalInput.inputConsumer (Global Shortcut Keys) (System API)

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

The **inputConsumer** module provides APIs for subscribing to and unsubscribing from global hotkeys. 

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.
>
> - The APIs provided by this module apply only to system shortcut keys, which are global shortcut keys defined by the system.


## Modules to Import

```js
import { inputConsumer } from '@kit.InputKit';
```

## inputConsumer.on

on(type: 'key', keyOptions: KeyOptions, callback: Callback&lt;KeyOptions&gt;): void

Enables listening for system hotkey change events. This API uses an asynchronous callback to return the system hotkey data when a system hotkey event that meets the specified condition occurs.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                                      |
| ---------- | -------------------------- | ---- | ---------------------------------------- |
| type       | string                     | Yes   | Event type. Currently, only **key** is supported.                      |
| keyOptions | [KeyOptions](#keyoptions)  | Yes   | Combination key options.                |
| callback   | Callback&lt;KeyOptions&gt; | Yes   | Callback used to return the combination key data when a combination key event that meets the specified condition occurs.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | Permission denied, non-system app called system api. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { inputConsumer } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let leftAltKey = 2045;
          let tabKey = 2049;
          let keyOptions: inputConsumer.KeyOptions = {
            preKeys: [ leftAltKey ],
            finalKey: tabKey,
            isFinalKeyDown: true,
            finalKeyDownDuration: 0
          };
          let callback = (keyOptions: inputConsumer.KeyOptions) => {
            console.info(`keyOptions: ${JSON.stringify(keyOptions)}`);
          }
          try {
            inputConsumer.on("key", keyOptions, callback);
          } catch (error) {
            console.error(`Subscribe failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```


## inputConsumer.off

off(type: 'key', keyOptions: KeyOptions, callback?: Callback&lt;KeyOptions&gt;): void

Disables listening for system hotkey change events.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                             |
| ---------- | -------------------------- | ---- | ------------------------------- |
| type       | string                     | Yes   | Event type. Currently, only **key** is supported.             |
| keyOptions | [KeyOptions](#keyoptions)  | Yes   | Combination key options.            |
| callback   | Callback&lt;KeyOptions&gt; | No   | Callback to unregister. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202  | Permission denied, non-system app called system api. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { inputConsumer } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let leftAltKey = 2045;
          let tabKey = 2049;
          // Disable listening for a single callback.
          let callback = (keyOptions: inputConsumer.KeyOptions) => {
            console.info(`keyOptions: ${JSON.stringify(keyOptions)}`);
          }
          let keyOption: inputConsumer.KeyOptions = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
          try {
            inputConsumer.on("key", keyOption, callback);
            inputConsumer.off("key", keyOption, callback);
            console.info(`Unsubscribe success`);
          } catch (error) {
            console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```
```js
import { inputConsumer } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let leftAltKey = 2045;
          let tabKey = 2049;
          // Disable listening for all callbacks.
          let callback = (keyOptions: inputConsumer.KeyOptions) => {
            console.info(`keyOptions: ${JSON.stringify(keyOptions)}`);
          }
          let keyOption: inputConsumer.KeyOptions = {preKeys: [leftAltKey], finalKey: tabKey, isFinalKeyDown: true, finalKeyDownDuration: 0};
          try {
            inputConsumer.on("key", keyOption, callback);
            inputConsumer.off("key", keyOption);
            console.info(`Unsubscribe success`);
          } catch (error) {
            console.error(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputConsumer.setShieldStatus<sup>11+</sup>

setShieldStatus(shieldMode: ShieldMode, isShield: boolean): void

Sets the system hotkey shield status.

**Required permissions**: ohos.permission.INPUT_CONTROL_DISPATCHING

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                                      |
| ---------- | -------------------------- | ---- | ---------------------------------------- |
| shieldMode       | [ShieldMode](js-apis-inputconsumer-sys.md#shieldmode11)                     | Yes   | System hotkey shield mode. Currently, only **FACTORY_MODE** is supported, which means to shield all system hotkeys.                      |
| isShield | boolean  | Yes   | Whether to enable shortcut key shielding. The value **true** means to enable shortcut key shielding, and the value **false** indicates the opposite.             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | SystemAPI permission error. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { inputConsumer } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          let FACTORY_MODE = 0;
          try {
            inputConsumer.setShieldStatus(FACTORY_MODE,true);
            console.info(`set shield status success`);
          } catch (error) {
            console.error(`set shield status failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## inputConsumer.getShieldStatus<sup>11+</sup>

getShieldStatus(shieldMode: ShieldMode): boolean

Obtains the system hotkey shield status.

**Required permissions**: ohos.permission.INPUT_CONTROL_DISPATCHING

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

**Parameters**

| Name        | Type                        | Mandatory  | Description                                      |
| ---------- | -------------------------- | ---- | ---------------------------------------- |
| shieldMode       | [ShieldMode](js-apis-inputconsumer-sys.md#shieldmode11)                    | Yes   | System hotkey shield mode. Currently, only **FACTORY_MODE** is supported, which means to shield all system hotkeys.                      |

**Return value**

| Type        |  Description                                      |
| ---------- |  ---------------------------------------- |
| boolean                    | Whether to enable shortcut key shielding. The value **true** means to enable shortcut key shielding, and the value **false** indicates the opposite.                      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201  | Permission denied. |
| 202  | SystemAPI permission error. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```js
import { inputConsumer } from '@kit.InputKit';

@Entry
@Component
struct Index {
  build() {
    RelativeContainer() {
      Text()
        .onClick(() => {
          try {
            let FACTORY_MODE = 0;
            let shieldstatusResult:Boolean =  inputConsumer.getShieldStatus(FACTORY_MODE);
            console.info(` get shield status result:${JSON.stringify(shieldstatusResult)}`);
          } catch (error) {
            console.error(`Failed to get shield status, error: ${JSON.stringify(error, [`code`, `message`])}`);
          }
        })
    }
  }
}
```

## KeyOptions

Represents combination key options.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

| Name       | Type  | Read-Only  | Optional  | Description     |
| --------- | ------ | ---- | ---- | ------- |
| preKeys    | Array\<number>   | No   | No| Preceding key set. The number of preceding keys ranges from 0 to 4. There is no requirement on the sequence of the keys.<br>For example, in the combination keys **Ctrl+Alt+A**, **Ctrl+Alt** are called preceding keys.|
| finalKey             | number  | No   |  No| Final key. This parameter is mandatory. A callback is triggered by the final key.<br>For example, in the combination keys **Ctrl+Alt+A**, **A** is called the final key.|
| isFinalKeyDown       | boolean | No   |  No| Whether the final key is pressed.<br>The value **true** indicates that the key is pressed, and the value **false** indicates the opposite.|
| finalKeyDownDuration | number  | No   |  No| Duration for holding down the key, in μs.<br>If the value of this field is **0**, a callback is triggered immediately.<br>If the value of this field is greater than **0** and **isFinalKeyDown** is **true**, a callback is triggered when the key keeps being pressed after the specified duration expires. If **isFinalKeyDown** is **false**, a callback is triggered when the key is released before the specified duration expires.  |
| isRepeat<sup>18+</sup> | boolean  | No     | Yes     | Whether to report repeated key events. The value **true** means to report repeated key events, and the value **false** means the opposite. The default value is **true**.|

## shieldMode<sup>11+</sup>

Enumerates system hotkey shield modes.

**System capability**: SystemCapability.MultimodalInput.Input.InputConsumer

| Name                       | Value| Description          |
| ------------------------------ | ----------- | ---------------- |
| UNSET_MODE | -1 | Unspecified mode, which means not to shield system hotkeys.|
| FACTORY_MODE | 0 | Factory mode, which means to shield all system hotkeys.|
| OOBE_MODE | 1 | OOBE mode, which means to shield all system hotkeys during OOBE. This function is not supported currently.|
