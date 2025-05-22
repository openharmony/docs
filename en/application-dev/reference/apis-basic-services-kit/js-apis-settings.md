# @ohos.settings (Data Item Settings)

The **settings** module provides APIs for setting data items.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
>  - If no value is obtained for the accessed data item, it indicates that the current system app does not add the value of the data item to the database.

## Modules to Import

```js
import settings from '@ohos.settings';
```
## domainName

Provides the domain name.

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name                         | Type  | Readable| Writable| Description                                                        |
|-----------------------------| ------ | ---- | ---- | ------------------------------------------------------------ |
| DEVICE_SHARED<sup>11+</sup> | string | Yes  | Yes  | Shared device domain.                                         |
| USER_PROPERTY<sup>11+</sup> | string | Yes  | Yes  | User property domain.                                          |

## date

Provides data items for setting the time and date formats. (Not supported yet.)

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name               | Type  | Readable| Writable| Description                                                        |
| ------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| DATE_FORMAT         | string | Yes  | Yes  | Date format.<br>The value can be **mm/dd/yyyy**, **dd/mm/yyyy**, or **yyyy/mm/dd**, where **mm** indicates the month, **dd** indicates the day, and **yyyy** indicates the year.|
| TIME_FORMAT         | string | Yes  | Yes  | Time format. The options are as follows:<br>- **12**: 12-hour format.<br>- **24**: 24-hour format.|
| AUTO_GAIN_TIME      | string | Yes  | Yes  | Whether the date, time, and time zone are automatically obtained from the Network Identity and Time Zone (NITZ).<br>The value **true** means that the date, time, and time zone are automatically obtained from NITZ;<br>**false** means the opposite.|
| AUTO_GAIN_TIME_ZONE | string | Yes  | Yes  | Whether the time zone is automatically obtained from NITZ.<br>The value **true** means that the time zone is automatically obtained from NITZ;<br>**false** means the opposite.|

## display

Provides data items for setting the display effects. (Not supported yet.)

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name                         | Type  | Readable| Writable| Description                                                                                                         |
| ----------------------------- | ------ | ---- | ---- |-------------------------------------------------------------------------------------------------------------|
| FONT_SCALE                    | string | Yes  | Yes  | Scale factor of the font. The value is a floating point number. (In the current version, only fixed values can be queried.)                                                                           |
| SCREEN_BRIGHTNESS_STATUS      | string | Yes  | Yes  | Screen brightness, with the value ranging from 0 to 255.                                                                                          |
| AUTO_SCREEN_BRIGHTNESS        | string | Yes  | Yes  | Whether automatic screen brightness adjustment is enabled.<br>- **AUTO_SCREEN_BRIGHTNESS_MODE**: Automatic screen brightness adjustment is enabled.<br>- **MANUAL_SCREEN_BRIGHTNESS_MODE**: Automatic screen brightness adjustment is disabled.   |
| AUTO_SCREEN_BRIGHTNESS_MODE   | number | Yes  | Yes  | Value of **AUTO_SCREEN_BRIGHTNESS** when automatic screen brightness adjustment is enabled.                                                                       |
| MANUAL_SCREEN_BRIGHTNESS_MODE | number | Yes  | Yes  | Value of **AUTO_SCREEN_BRIGHTNESS** when automatic screen brightness adjustment is disabled.                                                                       |
| SCREEN_OFF_TIMEOUT            | string | Yes  | Yes  | Waiting time for the device to enter the sleep state when not in use (unit: ms).                                                                             |
| DEFAULT_SCREEN_ROTATION       | string | Yes  | Yes  | This attribute is invalid when screen auto-rotation is enabled; otherwise, the following options are available:<br>- **0**: The screen rotates by 0 degrees.<br>- **1**: The screen rotates by 90 degrees.<br>- **2**: The screen rotates by 180 degrees.<br>- **3**: The screen rotates by 270 degrees.|
| ANIMATOR_DURATION_SCALE       | string | Yes  | Yes  | Scale factor for the animation duration, which affects the start delay and duration of all such animations.<br>If the value is **0**, the animation ends immediately. The default value is **1**.                                                 |
| TRANSITION_ANIMATION_SCALE    | string | Yes  | Yes  | Scale factor for transition animations.<br>The value **0** indicates that the transition animations are disabled.                                                                               |
| WINDOW_ANIMATION_SCALE        | string | Yes  | Yes  | Scale factor for normal window animations.<br>The value **0** indicates that window animations are disabled.                                                                             |
| DISPLAY_INVERSION_STATUS      | string | Yes  | Yes  | Whether display color inversion is enabled.<br>- **1**: Display color inversion is enabled.<br>- **0**: Display color inversion is disabled.                                                       |

## general

Provides data items for setting the general information about the device. (Not supported yet.)

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name                            | Type  | Readable| Writable| Description                                                        |
| -------------------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| SETUP_WIZARD_FINISHED            | string | Yes  | Yes  | Whether the startup wizard is running.<br>- If the value is **0**, the startup wizard is not running.<br>- If the value is not **0**, the startup wizard is running.|
| END_BUTTON_ACTION                | string | Yes  | Yes  | Action after the call end button is pressed if the user is not in a call.<br>- **0**: Nothing happens.<br>- **1**: The home screen is displayed.<br>- **2**: The device enters sleep mode and the screen is locked.<br>- **3**: The home screen is displayed. If the focus is already on the home screen, the device will enter sleep mode.|
| ACCELEROMETER_ROTATION_STATUS    | string | Yes  | Yes  | Whether the accelerometer is used to change screen orientation, that is, whether to enable auto-rotation.<br>- **1**: The accelerometer is used.<br>- **0**: The accelerometer is not used.|
| DEVICE_PROVISION_STATUS          | string | Yes  | Yes  | Whether the device is preconfigured.<br>On a multi-user device with a single system user, the screen may be locked when the value is **true**. In addition, other features cannot be started on the system user unless they are marked to display on the lock screen.|
| HDC_STATUS                       | string | Yes  | Yes  | Whether the hard disk controller (HDC) on the USB device is enabled.<br>- **true**: HDC is enabled.<br>- **false**: HDC is disabled.|
| BOOT_COUNTING                    | string | Yes  | Yes  | Number of boot operations after the device is powered on.                                    |
| CONTACT_METADATA_SYNC_STATUS     | string | Yes  | Yes  | Whether contacts metadata synchronization is enabled.<br>- **true**: Contacts metadata synchronization is enabled.<br>- **false**: Contacts metadata synchronization is disabled.|
| DEVICE_NAME                      | string | Yes  | Yes  | Device name.                                                  |
| USB_STORAGE_STATUS               | string | Yes  | Yes  | Whether USB mass storage is enabled.<br>- **true**: USB mass storage is enabled.<br>- **false**: USB mass storage is disabled.|
| DEBUGGER_WAITING                 | string | Yes  | Yes  | Whether the device waits for the debugger when starting an application to debug.<br>- **1**: The device waits for the debugger.<br>- **0**: The device does not wait for the debugger. In this case, the application runs normally.|
| DEBUG_APP_PACKAGE                | string | Yes  | Yes  | Bundle name of the application to be debugged.                             |
| ACCESSIBILITY_STATUS             | string | Yes  | Yes  | Whether accessibility is enabled.<br>- **1**: Accessibility is enabled.<br>- **0**: Accessibility is disabled.|
| ACTIVATED_ACCESSIBILITY_SERVICES | string | Yes  | Yes  | List of activated accessibility features.                                    |
| GEOLOCATION_ORIGINS_ALLOWED      | string | Yes  | Yes  | Default geographic location that can be used by the browser. Multiple geographic locations are separated by spaces.      |
| SKIP_USE_HINTS                   | string | Yes  | Yes  | Whether the application should attempt to skip all introductory hints at the first startup. This feature is intended for temporary or experienced users.<br>- **1**: The application attempts to skip all introductory hints at the first startup.<br>- **0**: The application does not skip all introductory hints at the first startup.|
| TOUCH_EXPLORATION_STATUS         | string | Yes  | Yes  | Whether touch exploration is enabled.<br>- **1**: Touch exploration is enabled.<br>- **0**: Touch exploration is disabled.|

## input

Provides data items for setting input methods. (Not supported yet.)

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name                                | Type  | Readable| Writable| Description                                                        |
| ------------------------------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| DEFAULT_INPUT_METHOD                 | string | Yes  | Yes  | Default input method and its ID.                                          |
| ACTIVATED_INPUT_METHOD_SUB_MODE      | string | Yes  | Yes  | Type and ID of the default input method keyboard.                                  |
| ACTIVATED_INPUT_METHODS              | string | Yes  | Yes  | List of activated input methods.<br>The list is a string that contains the IDs and keyboard types of activated input methods.<br>The IDs are separated by colons (:), and keyboard types are separated by semicolons (;).<br>An example format is **ima0:keyboardType0;keyboardType1;ima1:ima2:keyboardTypes0,** where **ima** indicates the ID of an input method, and **keyboardType** indicates the keyboard type.|
| SELECTOR_VISIBILITY_FOR_INPUT_METHOD | string | Yes  | Yes  | Whether the input method selector is visible.<br>- **1**: The input method selector is visible.<br>- **0**: The input method selector is invisible.|
| AUTO_CAPS_TEXT_INPUT                 | string | Yes  | Yes  | Whether automatic capitalization is enabled for the text editor.<br>- **0**: Automatic capitalization is disabled.<br>- **1**: Automatic capitalization is enabled.|
| AUTO_PUNCTUATE_TEXT_INPUT            | string | Yes  | Yes  | Whether automatic punctuation is enabled for the text editor. Automatic punctuation enables the text editor to convert two spaces into a period (.) and a space.<br>- **0**: Automatic punctuation is disabled.<br>- **1**: Automatic punctuation is enabled.|
| AUTO_REPLACE_TEXT_INPUT              | string | Yes  | Yes  | Whether autocorrect is enabled for the text editor. Autocorrect enables the text editor to correct typos.<br>- **0**: Autocorrect is disabled.<br>- **1**: Autocorrect is enabled |
| SHOW_PASSWORD_TEXT_INPUT             | string | Yes  | Yes  | Whether password presentation is enabled in the text editor. Password presentation enables the text editor to show password characters when the user types them.<br>- **0**: Password presentation is disabled.<br>- **1**: Password presentation is enabled.|

## network

Provides data items for setting network information. (Not supported yet.)

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name                    | Type  | Readable| Writable| Description                                                        |
| ------------------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| DATA_ROAMING_STATUS      | string | Yes  | Yes  | Whether data roaming is enabled.<br>**true**: Data roaming is enabled.<br>**false**: Data roaming is disabled.|
| HTTP_PROXY_CFG           | string | Yes  | Yes  | Host name and port number of the global HTTP proxy. The host name and port number are separated by a colon (:).|
| NETWORK_PREFERENCE_USAGE | string | Yes  | Yes  | User preferences for the network to use.                                  |

## phone

Provides data items for setting the modes of answering incoming and outgoing calls. (Not supported yet.)

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name              | Type  | Readable| Writable| Description                                                        |
| ------------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| RTT_CALLING_STATUS | string | Yes  | Yes  | Whether the real-time text (RTT) feature is enabled. If this feature is enabled, incoming and outgoing calls are answered as RTT calls when supported by the device and carrier.<br> **1**: RTT is enabled.<br> **0**: RTT is disabled.|

## sound

Provides data items for setting the sound effects. (Not supported yet.)

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name                        | Type  | Readable| Writable| Description                                                        |
| ---------------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| VIBRATE_WHILE_RINGING        | string | Yes  | Yes  | Whether the device vibrates when it is ringing for an incoming call. This attribute is applicable to the phone and settings applications<br>and affects only the scenario where the device rings for an incoming call. It does not affect any other application or scenario.|
| DEFAULT_ALARM_ALERT          | string | Yes  | Yes  | Storage area of the system default alarms and alerts.                                    |
| DTMF_TONE_TYPE_WHILE_DIALING | string | Yes  | Yes  | Type of the dual tone multi-frequency (DTMF) tone played while dialing.<br>**0**: normal short tone.<br>**1**: long tone.|
| DTMF_TONE_WHILE_DIALING      | string | Yes  | Yes  | Whether the DTMF tone is played when dialing.<br>**1**: DTMF tone is played when dialing.<br>**0**: DTMF tone is not played when dialing.|
| AFFECTED_MODE_RINGER_STREAMS | string | Yes  | Yes  | Effect on audio streams determined by changes in the ringing mode and Do Not Disturb (DND) mode. If you want a specific audio stream to be affected by changes of the ringing mode and DDN mode, set the corresponding bit to **1**.|
| AFFECTED_MUTE_STREAMS        | string | Yes  | Yes  | Audio streams affected by the mute mode. If you want a specific audio stream to remain muted in mute mode, set the corresponding bit to **1**.|
| DEFAULT_NOTIFICATION_SOUND   | string | Yes  | Yes  | Storage area of the system default notification tone.                                  |
| DEFAULT_RINGTONE             | string | Yes  | Yes  | Storage area of the system default ringtone.                                    |
| SOUND_EFFECTS_STATUS         | string | Yes  | Yes  | Whether the sound feature is available.<br>**0**: The feature is not available.<br>**1**: The feature is available.  |
| VIBRATE_STATUS               | string | Yes  | Yes  | Whether the device vibrates for an event. This attribute is used inside the system.<br>**1**: The device vibrates for an event.<br>**0**: The device does not vibrate for an event.|
| HAPTIC_FEEDBACK_STATUS       | string | Yes  | Yes  | Whether haptic feedback is enabled.<br>**true**: Haptic feedback is enabled.<br>**false**: Haptic feedback is disabled.|

## TTS

Provides data items for setting text-to-speech (TTS) information. (Not supported yet.)

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name               | Type  | Readable| Writable| Description                                                        |
| ------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| DEFAULT_TTS_PITCH   | string | Yes  | Yes  | Default pitch of the TTS engine.<br>100 = 1x. If the value is set to **200**, the frequency is twice the normal sound frequency.|
| DEFAULT_TTS_RATE    | string | Yes  | Yes  | Default voice rate of the TTS engine.<br>100 = 1x.                        |
| DEFAULT_TTS_SYNTH   | string | Yes  | Yes  | Default TTS engine.                                               |
| ENABLED_TTS_PLUGINS | string | Yes  | Yes  | List of activated plug-in packages used for TTS. Multiple plug-in packages are separated by spaces.          |


## wireless

Provides data items for setting wireless network information. (Not supported yet.)

### Attributes

**System capability**: SystemCapability.Applications.Settings.Core

| Name                             | Type  | Readable| Writable| Description                                                        |
| --------------------------------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| BLUETOOTH_DISCOVER_ABILITY_STATUS | string | Yes  | Yes  | Whether the device can be discovered or connected by other devices through Bluetooth.<br>**0**: The device cannot be discovered or connected.<br>**1**: The device can be connected but cannot be discovered.<br>**2**: The device can be discovered and connected.|
| BLUETOOTH_DISCOVER_TIMEOUT        | string | Yes  | Yes  | Duration for discovering a device through Bluetooth, in seconds.<br>After the duration expires, the device cannot be discovered through Bluetooth.|
| AIRPLANE_MODE_RADIOS              | string | Yes  | Yes  | List of radio signals to be disabled when airplane mode is enabled.<br>Multiple radio signals are separated by commas (,).<br>The list can include the following: **BLUETOOTH_RADIO**, **CELL_RADIO**, **NFC_RADIO**, and **WIFI_RADIO**.|
| BLUETOOTH_RADIO                   | string | Yes  | No  | A value of **AIRPLANE_MODE_RADIOS** to indicate that Bluetooth is disabled in airplane mode.|
| CELL_RADIO                        | string | Yes  | No  | A value of **AIRPLANE_MODE_RADIOS** to indicate that cellular radio is disabled in airplane mode.|
| NFC_RADIO                         | string | Yes  | No  | A value of **AIRPLANE_MODE_RADIOS** to indicate that NFC is disabled in airplane mode.|
| WIFI_RADIO                        | string | Yes  | No  | A value of **AIRPLANE_MODE_RADIOS** to indicate that Wi-Fi is disabled in airplane mode.|
| BLUETOOTH_STATUS                  | string | Yes  | Yes  | Whether Bluetooth is available.<br>- **true**: Bluetooth is available.<br>- **false**: Bluetooth is unavailable.|
| OWNER_LOCKDOWN_WIFI_CFG           | string | Yes  | Yes  | Whether the Wi-Fi configuration created by the application of the device owner should be locked down.<br>- **true**: The Wi-Fi configuration should be locked down.<br>- **false**: The Wi-Fi configuration should not be locked down.|
| WIFI_DHCP_MAX_RETRY_COUNT         | string | Yes  | Yes  | Maximum number of attempts to obtain an IP address from the DHCP server.                    |
| WIFI_TO_MOBILE_DATA_AWAKE_TIMEOUT | string | Yes  | Yes  | Maximum duration to hold a wake lock when waiting for the mobile data connection after the Wi-Fi connection is disconnected. |
| WIFI_STATUS                       | string | Yes  | Yes  | Whether Wi-Fi is available.<br>- **true**: Wi-Fi is available.<br>- **false**: Wi-Fi is unavailable.|
| WIFI_WATCHDOG_STATUS              | string | Yes  | Yes  | Whether Wi-Fi watchdog is available.<br>- **true**: Wi-Fi watchdog is available.<br>- **false**: Wi-Fi watchdog is unavailable.|


## settings.setValue<sup>10+</sup>

setValue(context: Context, name: string, value: string, callback: AsyncCallback\<boolean>): void

Sets the value for a data item. This API uses an asynchronous callback to return the result. 

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Required permissions**: ohos.permission.MANAGE_SETTINGS (available only to system applications)

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                 | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name     | string                  | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| value    | string                  | Yes  | Value of the data item. The value range varies by service.                              |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. Returns **true** if the operation is successful; returns **false** otherwise.              |

**Example**

```js
import settings from '@ohos.settings';

// Update the value of SCREEN_BRIGHTNESS_STATUS. (As this data item exists in the database, the setValue API will update its value.)
const context: Context =  getContext(this);
settings.setValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100', (status) => {
  console.log('Callback return whether value is set.');
});
```

## settings.setValue<sup>10+</sup>

setValue(context: Context, name: string, value: string): Promise\<boolean>

Sets the value for a data item. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Required permissions**: ohos.permission.MANAGE_SETTINGS (available only to system applications)

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name    | string  | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| value   | string  | Yes  | Value of the data item. The value range varies by service.                              |

**Return value**

| Type             | Description                                              |
| ----------------- | -------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
import settings from '@ohos.settings';

// Update the value of SCREEN_BRIGHTNESS_STATUS. (As this data item exists in the database, the setValue API will update its value.)
const context: Context =  getContext(this);
settings.setValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100').then((status) => {
  console.log('Callback return whether value is set.');
});
```

## settings.setValue<sup>11+</sup>

setValue(context: Context, name: string, value: string, domainName: string): Promise\<boolean>

Sets the value for a data item. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Required permissions**: 
- ohos.permission.MANAGE_SETTINGS for writing the DEVICE_SHARED and USER_PROPERTY fields (available only to system applications);
- ohos.permission.MANAGE_SECURE_SETTINGS for writing the USER_SECURITY field (available only to system applications)

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                                                                                                                                                                 |
| -------- | ---------------------- | ---- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| context  | Context                | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).                                                                                                                                                               |
| name     | string                 | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items                                                                                                                                                                                                     |
| value    | string                 | Yes  | Value of the data item. The value range varies by service.                                                                                                                                                                                                                                                    |
|domainName| string                 | Yes  | Domain name to set.<br>- **domainName.DEVICE_SHARED**:<br>&nbsp;&nbsp;&nbsp;shared device domain<br>- **domainName.USER_PROPERTY**:<br>&nbsp;&nbsp;&nbsp;user property domain<br>- **domainName.USER_SECURITY**:<br>&nbsp;&nbsp;&nbsp;user security domain (for system applications only)|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the result. Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |

**Example**

```js
import settings from '@ohos.settings';

// Update the value of SCREEN_BRIGHTNESS_STATUS. (As this data item exists in the database, the setValue API will update its value.)
const context: Context =  getContext(this);
settings.setValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100', settings.domainName.DEVICE_SHARED).then((status) => {
  console.log(`callback:return whether value is set.`)
});
```

## settings.getValue<sup>10+</sup>

getValue(context: Context, name: string, callback: AsyncCallback\<string>): void

Obtains the value of a data item in the database. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name     | string                 | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| callback | AsyncCallback\<string> | Yes  | Callback used to return the value of the data item.                            |

**Example**

```js
import settings from '@ohos.settings';
const context: Context =  getContext(this);
settings.getValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS, (err, value) => {
  if (err) {
    console.error(`Failed to get the setting. ${err.message} `);
    return;
  }
  console.log(`callback:value -> ${value}`)
});
```

## settings.getValue<sup>10+</sup>

getValue(context: Context, name: string): Promise\<string>

Obtains the value of a data item in the database. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name    | string  | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the result. return the value of the data item.|

**Example**

```js
import settings from '@ohos.settings';
const context: Context =  getContext(this);
settings.getValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS).then((value) => {
  console.log(`promise:value -> ${value}`)
});
```

## settings.getValue<sup>11+</sup>

getValue(context: Context, name: string, domainName: string): Promise\<string>;

Obtains the value of a data item in the database. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Required permissions**:  
- ohos.permission.MANAGE_SECURE_SETTINGS for reading the USER_SECURITY field (available only to system applications)

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name     | string                 | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
|domainName| string                 | Yes  | Domain name to set.<br>- **domainName.DEVICE_SHARED**:<br>&nbsp;&nbsp;&nbsp;shared device domain<br>- **domainName.USER_PROPERTY**:<br>&nbsp;&nbsp;&nbsp;user property domain<br>- **domainName.USER_SECURITY**:<br>&nbsp;&nbsp;&nbsp;user security domain (for system applications only)|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the result. return the value of the data item.|

**Example**

```js
import settings from '@ohos.settings';

// Update the value of SCREEN_BRIGHTNESS_STATUS. (As this data item exists in the database, the getValue API will update its value.)
const context: Context =  getContext(this);
settings.getValue(context, settings.display.SCREEN_BRIGHTNESS_STATUS, settings.domainName.DEVICE_SHARED).then((value) => {
  console.log(`Promise:value -> ${value}`);
});
```

## settings.getValueSync<sup>10+</sup>

getValueSync(context: Context, name: string, defValue: string): string;

Obtains the value of a data item. Unlike **getValue**, this API returns the result synchronously.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| context  | Context | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name     | string  | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| defValue | string  | Yes  | Default value, which is returned when the value of a data item is not found in the database. Set this parameter as needed.|

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| string | Value of the data item.|

**Example**

```js
import settings from '@ohos.settings';

// Obtain the value of SCREEN_BRIGHTNESS_STATUS (this data item already exists in the database).
const context: Context =  getContext(this);
let value = settings.getValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '10');
```

## settings.getValueSync<sup>11+</sup>

getValueSync(context: Context, name: string, defValue: string, domainName: string): string;

Obtains the value of a data item. Unlike **getValue**, this API returns the result synchronously.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Required permissions**:  
- ohos.permission.MANAGE_SECURE_SETTINGS for reading the USER_SECURITY field (available only to system applications)

**Parameters**

| Name       | Type                  | Mandatory| Description                                                        |
|------------| ---------------------- | ---- | ------------------------------------------------------------ |
| context    | Context                | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name       | string                 | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| defValue   | string                 | Yes  | Value of the data item. The value range varies by service.                  |
| domainName | string                 | Yes  | Domain name to set.<br>- **domainName.DEVICE_SHARED**:<br>&nbsp;&nbsp;&nbsp;shared device domain<br>- **domainName.USER_PROPERTY**:<br>&nbsp;&nbsp;&nbsp;user property domain<br>- **domainName.USER_SECURITY**:<br>&nbsp;&nbsp;&nbsp;user security domain (for system applications only)|


**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| string           | Value of the data item.                      |

**Example**

```js
import settings from '@ohos.settings';

// Update the value of .SCREEN_BRIGHTNESS_STATUS (this data item already exists in the database).
const context: Context =  getContext(this);
let value = settings.getValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100',  settings.domainName.DEVICE_SHARED);
```

## settings.setValueSync<sup>10+</sup>

setValueSync(context: Context, name: string, value: string): boolean

Sets the value for a data item. Unlike **setValue**, this API returns the result synchronously.

- If the specified data item exists in the database, the **setValueSync** method updates the value of the data item.
- If the data item does not exist in the database, the **setValueSync** method inserts the data item into the database.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Required permissions**: ohos.permission.MANAGE_SETTINGS (available only to system applications)

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name    | string  | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| value   | string  | Yes  | Value of the data item. The value range varies by service.                      |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Result indicating whether the value is set successfully. Returns **true** if the value is set successfully; returns **false** otherwise.|

**Example**

```js
import settings from '@ohos.settings';

// Update the value of SCREEN_BRIGHTNESS_STATUS. (As this data item exists in the database, the setValueSync API will update its value.)
const context: Context =  getContext(this);
let ret = settings.setValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100');
```

## settings.setValueSync<sup>11+</sup>

setValueSync(context: Context, name: string, value: string, domainName: string): boolean

Sets the value for a data item. Unlike **setValue**, this API returns the result synchronously.

- If the specified data item exists in the database, the **setValueSync** method updates the value of the data item.
- If the data item does not exist in the database, the **setValueSync** method inserts the data item into the database.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Required permissions**: 
- ohos.permission.MANAGE_SETTINGS for writing the DEVICE_SHARED and USER_PROPERTY fields (available only to system applications); 
- ohos.permission.MANAGE_SECURE_SETTINGS for writing the USER_SECURITY field (available only to system applications)

**Parameters**

| Name    | Type                  | Mandatory| Description                                                        |
|---------| ---------------------- | ---- | ------------------------------------------------------------ |
| context | Context                | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name    | string                 | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| value   | string                 | Yes  | Value of the data item. The value range varies by service.                  |
| domainName | string                 | Yes  | Domain name to set.<br>- **domainName.DEVICE_SHARED**:<br>&nbsp;&nbsp;&nbsp;shared device domain<br>- **domainName.USER_PROPERTY**:<br>&nbsp;&nbsp;&nbsp;user property domain<br>- **domainName.USER_SECURITY**:<br>&nbsp;&nbsp;&nbsp;user security domain (for system applications only)|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| boolean          | Result indicating whether the value is set successfully. Returns **true** if the value is set successfully; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------- |
| 201 | Permission denied. |

**Example**

```js
import settings from '@ohos.settings';

// Update the value of SCREEN_BRIGHTNESS_STATUS. (As this data item exists in the database, the setValueSync API will update its value.)
const context: Context =  getContext(this);
let ret = settings.setValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '100', settings.domainName.DEVICE_SHARED);
```

## settings.registerKeyObserver<sup>11+</sup>

registerKeyObserver(context: Context, name: string, domainName: string, observer:AsyncCallback\<void>): boolean

Registers an observer in the specified context so that the specified data item can be observed in the specified domain name. When the data item value changes, the registered callback is called. Returns **true** if the registration is successful; returns **false** otherwise.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name     | string                 | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
|domainName| string                 | Yes  | Domain name to set.<br>- **domainName.DEVICE_SHARED**:<br>&nbsp;&nbsp;&nbsp;shared device domain<br>- **domainName.USER_PROPERTY**:<br>&nbsp;&nbsp;&nbsp;user property domain<br>- **domainName.USER_SECURITY**:<br>&nbsp;&nbsp;&nbsp;user security domain (for system applications only)|
|observer  |  AsyncCallback\<void>  | Yes  | Callback used to return the value of the data item.                  |

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| boolean | Result indicating whether the value is set successfully. Returns **true** if the value is set successfully; returns **false** otherwise.|

**Example**

```js
import settings from '@ohos.settings';

const context: Context =  getContext(this);
settings.registerKeyObserver(context, settings.display.SCREEN_BRIGHTNESS_STATUS, settings.domainName.DEVICE_SHARED, (err, val) => {
  if (err) {
    console.error(`Failed to get the setting. ${err.message} `);
    return;
  }
  console.log(`callback:value -> ${JSON.stringify(val)}`)
  let value:string = settings.getValueSync(context, settings.display.SCREEN_BRIGHTNESS_STATUS, '10');
  console.log(`Promise:value -> ${value}`);
});
```

## settings.unregisterKeyObserver<sup>11+</sup>

unregisterKeyObserver(context: Context, name: string, domainName: string): boolean

Unregisters the observer under the specified domain name. This API returns the result synchronously.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Applications.Settings.Core

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| name     | string                 | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
|domainName| string                 | Yes  | Domain name to set.<br>- **domainName.DEVICE_SHARED**:<br>&nbsp;&nbsp;&nbsp;shared device domain<br>- **domainName.USER_PROPERTY**:<br>&nbsp;&nbsp;&nbsp;user property domain<br>- **domainName.USER_SECURITY**:<br>&nbsp;&nbsp;&nbsp;user security domain (for system applications only)|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| boolean | Whether the observer under the specified domain name is successfully unregistered. Returns **true** if the deregistration is successful; returns **false** otherwise.|

**Example**

```js
import settings from '@ohos.settings';

const context: Context =  getContext(this);
let ret = settings.unregisterKeyObserver(context, settings.display.SCREEN_BRIGHTNESS_STATUS,  settings.domainName.DEVICE_SHARED);
```

## settings.openNetworkManagerSettings<sup>18+</sup>

openNetworkManagerSettings(context: Context): Promise\<boolean>

Opens the network manager settings page. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                                                                                                                                                                 |
| -------- | ---------------------- | ---- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| context  | Context                | Yes  | Application context. Only UIAbilityContext and ExtensionContext are supported.<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).                                                                                                                                                               |

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the result. Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Settings Error Codes](./errorcode-settings.md).

| ID   | Error Message                   |
|----------|-------------------------|
| 14800000 | Parameter error.        |
| 14800010 | Original service error. |

**Example**

```js
import settings from '@ohos.settings';

// Redirect to the network manager settings page.
const context: Context =  getContext(this);
settings.openNetworkManagerSettings(context).then((status) => {
  console.log(`callback:return whether settings is open.`)
});
```

## settings.enableAirplaneMode

enableAirplaneMode(enable: boolean, callback: AsyncCallback\<void>): void

Enables or disables airplane mode. This API uses an asynchronous callback to return the result. (Not supported yet.)

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                           |
| -------- | -------------------- | ---- | ----------------------------------------------- |
| enable   | boolean              | Yes  | Whether airplane mode is enabled. **true** means that airplane mode is enabled, and **false** means the opposite.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.                                     |

**Example**

```js
let isEnabled :boolean = true;
settings.enableAirplaneMode(isEnabled, (err:Error) => {
    if (err) {
        console.log('Failed to enable AirplaneMode.');
        return;
    }
    console.log('Return true if enable.');
})
```

## settings.enableAirplaneMode

enableAirplaneMode(enable: boolean): Promise\<void>

Enables or disables airplane mode. This API uses a promise to return the result. (Not supported yet.)

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name| Type   | Mandatory| Description                                           |
| ------ | ------- | ---- | ----------------------------------------------- |
| enable | boolean | Yes  | Whether airplane mode is enabled. **true** means that airplane mode is enabled, and **false** means the opposite.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```js
let isEnabled :boolean = true;
settings.enableAirplaneMode(isEnabled).then(() => {
  console.log('Succeeded in enabling AirplaneMode.');
}).catch((err:Error) => {
  console.log(`Failed to enable AirplaneMode. Cause: ${err}`);
})
```

## settings.canShowFloating

canShowFloating(callback: AsyncCallback\<boolean>): void

Checks whether the application can be displayed in a floating window. This API uses an asynchronous callback to return the result. (Not supported yet.)

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result.<br>The value **true** means the application can be displayed in a floating window; **false** means the opposite.|

**Example**

```js
settings.canShowFloating((err:Error, status: boolean) => {
  if (err) {
    console.error(`Failed to Checks whether a specified application can show as float window ${err.message} `);
    return;
  }
  console.log('Checks whether a specified application can show as float window.');
});
```

## settings.canShowFloating

canShowFloating(): Promise\<boolean>

Checks whether the application can be displayed in a floating window. This API uses a promise to return the result. (Not supported yet.)

**System capability**: SystemCapability.Applications.Settings.Core

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result.<br>The value **true** means the application can be displayed in a floating window; **false** means the opposite.|

**Example**

```js
settings.canShowFloating().then((status:boolean) => {
    console.log('Checks whether a specified application can show as float window.');
});
```

## settings.getUriSync<sup>8+</sup>

getUriSync(name: string): string

Obtains the URI of a data item. (Not supported yet.)

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|

**Return value**

| Type  | Description         |
| ------ | ------------- |
| string | URI of the data item.|

**Example**

```js
// Obtain the URI of a data item.
let uriVar:string = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
```

## settings.getURI<sup>(deprecated)</sup>

getURI(name: string, callback: AsyncCallback\<object>): void

Obtains the URI of a data item. This API uses an asynchronous callback to return the result. (Not supported yet.)

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. No substitute API is provided.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| name     | string                 | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| callback | AsyncCallback\<object> | Yes  | Callback used to return the result. Obtains the URI of a data item.                                 |

**Example**

```js
settings.getURI(settings.display.SCREEN_BRIGHTNESS_STATUS, (uri:string) => {
    console.log(`callback:uri -> ${JSON.stringify(uri)}`)
})
```

## settings.getURI<sup>(deprecated)</sup>

getURI(name: string): Promise\<object>

Obtains the URI of a data item. This API uses a promise to return the result. (Not supported yet.)

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. No substitute API is provided.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|

**Return value**

| Type            | Description                                |
| ---------------- | ------------------------------------ |
| Promise\<object> | Promise used to return the result. return the URI of the data item.|

**Example**

```js
settings.getURI(settings.display.SCREEN_BRIGHTNESS_STATUS).then((uri:string) => {
    console.log(`promise:uri -> ${JSON.stringify(uri)}`)
})
```



## settings.getValue<sup>(deprecated)</sup>

getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void

Obtains the value of a data item in the database. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getValue()](#settingsgetvalue10) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name           | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | Yes  | **DataAbilityHelper** class.                                            |
| name              | string                                                       | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| callback          | AsyncCallback\<object>                                       | Yes  | Callback used to return the value of the data item.                            |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let uri:string = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
let helper = featureAbility.acquireDataAbilityHelper(uri);
settings.getValue(helper, settings.display.SCREEN_BRIGHTNESS_STATUS, (err:Error, value:string) => {
    if (err) {
        console.error(`Failed to get the setting. ${err.message} `);
        return;
    }
    console.log(`callback:value -> ${JSON.stringify(value)}`)
});
```

## settings.getValue<sup>(deprecated)</sup>

getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>

Obtains the value of a data item in the database. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getValue()](#settingsgetvalue10-1) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name           | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | Yes  | **DataAbilityHelper** class.                                            |
| name              | string                                                       | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| Promise\<object> | Promise used to return the result. return the value of the data item.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

let uri:string = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
let helper = featureAbility.acquireDataAbilityHelper(uri);
settings.getValue(helper, settings.display.SCREEN_BRIGHTNESS_STATUS).then((value:string) => {
    console.log(`promise:value -> ${JSON.stringify(value)}`)
});
```

## settings.getValueSync<sup>(deprecated)</sup>

getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string

Obtains the value of a data item. Unlike **getValue**, this API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getValueSync()](#settingsgetvaluesync10) instead.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name           | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | Yes  | **DataAbilityHelper** class.                                            |
| name              | string                                                       | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| defValue          | string                                                       | Yes  | Default value, which is returned when the value of a data item is not found in the database. Set this parameter as needed.|

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| string | Value of the data item.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

// Obtain the value of SCREEN_BRIGHTNESS_STATUS (this data item already exists in the database).
let uri:string = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
let helper = featureAbility.acquireDataAbilityHelper(uri);
let value:string = settings.getValueSync(helper, settings.display.SCREEN_BRIGHTNESS_STATUS, '10');
```

## settings.setValueSync<sup>(deprecated)</sup>

setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean

Sets the value for a data item. Unlike **setValue**, this API returns the result synchronously.

- If the specified data item exists in the database, the **setValueSync** method updates the value of the data item.
- If the data item does not exist in the database, the **setValueSync** method inserts the data item into the database.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [setValueSync()](#settingssetvaluesync10) instead.

**Model restriction**: This API can be used only in the FA model.

**Required permissions**: ohos.permission.MANAGE_SETTINGS (available only to system applications)

**System capability**: SystemCapability.Applications.Settings.Core

**Parameters**

| Name           | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataAbilityHelper | [DataAbilityHelper](../apis-ability-kit/js-apis-inner-ability-dataAbilityHelper.md) | Yes  | **DataAbilityHelper** class.                                            |
| name              | string                                                       | Yes  | Name of the target data item. Data items can be classified as follows:<br>- Existing data items in the database<br>- Custom data items|
| value             | string                                                       | Yes  | Value of the data item. The value range varies by service.                      |

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Result indicating whether the value is set successfully. Returns **true** if the value is set successfully; returns **false** otherwise.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility';

// Update the value of SCREEN_BRIGHTNESS_STATUS. (As this data item exists in the database, the setValueSync API will update its value.)
let uri:string = settings.getUriSync(settings.display.SCREEN_BRIGHTNESS_STATUS);
let helper = featureAbility.acquireDataAbilityHelper(uri);
let ret:string = settings.setValueSync(helper, settings.display.SCREEN_BRIGHTNESS_STATUS, '100');
```
