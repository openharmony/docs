# @system.brightness (Screen Brightness)

The **brightness** module provides APIs for querying and adjusting the screen brightness and mode.

> **NOTE**
>
> - The APIs of this module are no longer maintained since API version 7.<!--Del--> You are advised to use APIs of [@ohos.brightness](js-apis-brightness-sys.md). <!--DelEnd-->The substitute APIs are available only for system applications.
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```js
import brightness, { BrightnessModeResponse, BrightnessResponse } from '@system.brightness';
```


## brightness.getValue

getValue(options?: GetBrightnessOptions): void

Obtains the current screen brightness.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [GetBrightnessOptions](#getbrightnessoptions) | No  | Options for obtaining the screen brightness. This parameter is optional and is left blank by default.|

**Example**

  ```js
  brightness.getValue({
      success: (data: BrightnessResponse) => {
        console.log('success get brightness value:' + data.value);
      },
      fail: (data: string, code: number) => {
        console.error('get brightness fail, code: ' + code + ', data: ' + data);
      }
  });
  ```


## brightness.setValue

setValue(options?: SetBrightnessOptions): void

Sets the screen brightness.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [SetBrightnessOptions](#setbrightnessoptions) | No  | Options for setting the screen brightness. This parameter is optional and is left blank by default.|

**Example**

  ```js
  brightness.setValue({
      value: 100,
      success: () => {
        console.log('handling set brightness success.');
      },
      fail: (data: string, code: number) => {
        console.error('handling set brightness value fail, code:' + code + ', data: ' + data);
      }
  });
  ```


## brightness.getMode

getMode(options?: GetBrightnessModeOptions): void

Obtains the screen brightness adjustment mode.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [GetBrightnessModeOptions](#getbrightnessmodeoptions) | No| Options for obtaining the screen brightness mode. This parameter is optional and is left blank by default.|

**Example**

  ```js
  brightness.getMode({
      success: (data: BrightnessModeResponse) => {
        console.log('success get mode:' + data.mode);
      },
      fail: (data: string, code: number) => {
        console.error('handling get mode fail, code:' + code + ', data: ' + data);
      }
  });
  ```


## brightness.setMode

setMode(options?: SetBrightnessModeOptions): void

Sets the screen brightness adjustment mode.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

**Parameters**
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [SetBrightnessModeOptions](#setbrightnessmodeoptions) | No  | Options for setting the screen brightness mode. This parameter is optional and is left blank by default.|

**Example**

  ```js
  brightness.setMode({
      mode: 1,
      success: () => {
        console.log('handling set mode success.');
      },
      fail: (data: string, code: number) => {
        console.error('handling set mode fail, code:' + code + ', data: ' + data);
      }
  });
  ```


## brightness.setKeepScreenOn

setKeepScreenOn(options?: SetKeepScreenOnOptions): void

>This API is no longer maintained since API version 7. You are advised to use [window.setWindowKeepScreenOn()](../apis-arkui/js-apis-window.md#setwindowkeepscreenon9).

Sets whether to always keep the screen on. Call this API in **onShow()**.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| options | [SetKeepScreenOnOptions](#setkeepscreenonoptions) | No| Options for setting the screen to be steady on. This parameter is optional and is left blank by default.|

**Example**

  ```js
  brightness.setKeepScreenOn({
      keepScreenOn: true,
      success: () => {
        console.log('handling set keep screen on success.');
      },
      fail: (data: string, code: number) => {
        console.error('handling set keep screen on fail, code:' + code + ', data: ' + data);
      }
  });
  ```
## GetBrightnessOptions

Options for obtaining the screen brightness.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

| Name    | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| success  | (data: [BrightnessResponse](#brightnessresponse)) => void | No  | Called when an API call is successful. **data** is a return value of the [BrightnessResponse](#brightnessresponse) type.|
| fail     | (data: string, code: number) => void                      | No  | Called when an API call has failed. **data** indicates the error information, and **code** indicates the error code.      |
| complete | () => void                                                | No  | Called when an API call is complete.                                    |

## SetBrightnessOptions

Options for setting the screen brightness.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

| Name    | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| value    | number                               | Yes  | Screen brightness. The value is an integer ranging from **1** to **255**.<br>- If the value is less than or equal to **0**, value **1** will be used.<br>- If the value is greater than **255**, value **255** will be used.<br>- If the value contains decimals, the integral part of the value will be used. For example, if value **8.1** is set, value **8** will be used.|
| success  | () => void                           | No  | Called when API call is successful.                                    |
| fail     | (data: string, code: number) => void | No  | Called when an API call has failed. **data** indicates the error information, and **code** indicates the error code.      |
| complete | () => void                           | No  | Called when an API call is complete.                                    |

## BrightnessResponse

Defines a response that returns the screen brightness.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| value | number | Yes| No| Screen brightness. The value ranges from **1** to **255**.|

## GetBrightnessModeOptions

Defines the options for obtaining the screen brightness mode.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

| Name    | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| success  | (data: [BrightnessModeResponse](#brightnessmoderesponse)) => void | No  | Called when an API call is successful. **data** is a return value of the [BrightnessModeResponse](#brightnessmoderesponse) type.|
| fail     | (data: string, code: number) => void                         | No  | Called when an API call has failed. **data** indicates the error information, and **code** indicates the error code.      |
| complete | () => void                                                   | No  | Called when an API call is complete.                                    |

## SetBrightnessModeOptions

Options for setting the screen brightness mode.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

| Name    | Type                                | Mandatory| Description                                                  |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------ |
| mode     | number                               | Yes  | The value **0** indicates the manual adjustment mode, and the value **1** indicates the automatic adjustment mode.|
| success  | () => void                           | No  | Called when API call is successful.                              |
| fail     | (data: string, code: number) => void | No  | Called when an API call has failed. **data** indicates the error information, and **code** indicates the error code.|
| complete | () => void                           | No  | Called when an API call is complete.                              |

## BrightnessModeResponse

Defines a response that returns the screen brightness mode.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| mode | number | Yes| No| The value **0** indicates the manual adjustment mode, and the value **1** indicates the automatic adjustment mode.|

## SetKeepScreenOnOptions

Options for setting the screen to be steady on.

**System capability**: SystemCapability.PowerManager.DisplayPowerManager.Lite

| Name        | Type                                | Mandatory| Description                                                  |
| ------------ | ------------------------------------ | ---- | ------------------------------------------------------ |
| keepScreenOn | boolean                              | Yes  | The value **true** means to keep the screen steady on, and the value **false** indicates the opposite.         |
| success      | () => void                           | No  | Called when API call is successful.                              |
| fail         | (data: string, code: number) => void | No  | Called when an API call has failed. **data** indicates the error information, and **code** indicates the error code.|
| complete     | () => void                           | No  | Called when an API call is complete.                              |
