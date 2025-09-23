# @ohos.accessibility.config (SystemAPI)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

The **accessibility.config** module provides APIs for configuring system accessibility features, including accessibility extension, high-contrast text, mouse buttons, and captions.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { config } from '@kit.AccessibilityKit';
```

## Properties

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name                                | Type                                                                                    | Read-Only| Optional| Description                        |
|------------------------------------|--------------------------------------------------------------------------------------------| -------- | -------- |-----------------------------------------------------------|
| highContrastText                   | [Config](#config)\<boolean>                                                                | No| No| Whether to enable high-contrast text. The value **true** indicates that high-contrast text is enabled, and **false** indicates the opposite.<br>Default value: **false**                                          |
| invertColor                        | [Config](#config)\<boolean>                                                                | No| No| Whether to enable color inversion. The value **true** indicates that color inversion is enabled, and **false** indicates the opposite.<br>Default value: **false**                                            |
| daltonizationState<sup>11+</sup>   | [Config](#config)\<boolean>                                                                | No| No| Whether to enable daltonization. It must be used with **daltonizationColorFilter**. The value **true** indicates that daltonization is enabled, and **false** indicates the opposite.<br>Default value: **false**               |
| daltonizationColorFilter           | [Config](#config)&lt;[DaltonizationColorFilter](#daltonizationcolorfilter)&gt;             | No| No| Configuration of the daltonization filter.                                              |
| contentTimeout                     | [Config](#config)\<number>                                                                 | No| No| Recommended duration for content display. The value ranges from 0 to 5000, in milliseconds.<br> Default value: **0**                            |
| animationOff                       | [Config](#config)\<boolean>                                                                | No| No| Whether to disable animation. The value **true** indicates that animation is disabled, and **false** indicates the opposite.<br>Default value: **0**                                            |
| brightnessDiscount                 | [Config](#config)\<number>                                                                 | No| No| Brightness discount. The value ranges from 0 to 1.0.<br> Default value: **0.0**                                     |
| mouseKey                           | [Config](#config)\<boolean>                                                                | No| No| Whether to enable the mouse button. The value **true** indicates that the mouse button is enabled, and **false** indicates the opposite. <br>Default value: **0**                                             |
| mouseAutoClick                     | [Config](#config)\<number>                                                                 | No| No| Configuration of the automatic mouse click operation. The value ranges from 0 to 5000, in milliseconds. The value **0** indicates that the automatic mouse click is not triggered; other values indicate that the operation is triggered when the mouse pointer is hovered for a specified period of time.<br>Default value: **0**               |
| shortkey                           | [Config](#config)\<boolean>                                                                | No| No| Whether to enable the accessibility extension shortcut key. The value **true** indicates that the auxiliary extension shortcut key is enabled, and **false** indicates the opposite.<br>Default value: **false**                                         |
| shortkeyTarget                     | [Config](#config)\<string>                                                                 | No| No| Target application for the accessibility extension shortcut key. The value format is 'bundleName/abilityName'.  |
| captions                           | [Config](#config)\<boolean>                                                                | No| No| Whether to enable captions. The value **true** indicates that caption is enabled, and **false** indicates the opposite.<br>Default value: **false**                                            |
| captionsStyle                      | [Config](#config)\<[accessibility.CaptionsStyle](js-apis-accessibility.md#captionsstyle8)> | No| No| Captions style.                                               |
| audioMono<sup>10+</sup>            | [Config](#config)\<boolean>                                                                | No| No| Whether to enable mono audio. The value **true** indicates that mono audio is enabled, and **false** indicates the opposite.<br>Default value: **false**                                           |
| audioBalance<sup>10+</sup>         | [Config](#config)\<number>                                                                 | No| No| Audio balance for the left and right audio channels. The value ranges from -1.0 to 1.0.<br> Default value: **0.0**                               |
| shortkeyMultiTargets<sup>11+</sup> | [Config](#config)&lt;Array\<string>&gt;                                                    | No| No| List of target applications for the accessibility shortcut keys. The value format is ['bundleName/abilityName'].|
| clickResponseTime<sup>11+</sup>    | [Config](#config)&lt;[ClickResponseTime](#clickresponsetime11)&gt;                         | No| No| Length of time required for a click.                                            |
| ignoreRepeatClick<sup>11+</sup>    | [Config](#config)\<boolean>                                                                | No| No| Whether to ignore repeated clicks. This parameter must be used together with **repeatClickInterval**. The value **true** indicates that the feature of ignoring repeated clicks is enabled, and **false** indicates the opposite.<br>Default value: **false**                  |
| repeatClickInterval<sup>11+</sup>  | [Config](#config)&lt;[RepeatClickInterval](#repeatclickinterval11)&gt;                     | No| No| Interval between repeated clicks.                                            |

For a boolean return value, **True** means that the feature is enabled, and **False** means the opposite.
## enableAbility

enableAbility(name: string, capability: Array&lt;accessibility.Capability&gt;): Promise&lt;void&gt;

Enables an accessibility extension ability. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type                                                                          | Mandatory| Description|
| -------- |------------------------------------------------------------------------------| -------- | -------- |
| name | string                                                                       | Yes| Name of the accessibility extension ability. The format is 'bundleName/abilityName'.|
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | Yes| Capability of the accessibility extension ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void>| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300001 | Invalid bundle name or ability name.  |
| 9300002 | Target ability already enabled. |

**Example**

```ts
import { accessibility, config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';
let capability: accessibility.Capability[] = ['retrieve'];

config.enableAbility(name, capability).then(() => {
  console.info(`Succeeded  in enable ability, name is ${name}, capability is ${capability}`);
}).catch((err: BusinessError) => {
  console.error(`failed to enable ability, Code is ${err.code}, message is ${err.message}`);
});
```

## enableAbility

enableAbility(name: string, capability: Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt;, callback: AsyncCallback&lt;void&gt;): void

Enables an accessibility extension ability. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type                                                                             | Mandatory| Description|
| -------- |---------------------------------------------------------------------------------| -------- | -------- |
| name | string                                                                          | Yes| Name of the accessibility extension ability. The format is 'bundleName/abilityName'.|
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | Yes| Capability of the accessibility extension ability.|
| callback | AsyncCallback&lt;void&gt;                                                       | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300001 | Invalid bundle name or ability name.  |
| 9300002 | Target ability already enabled. |

**Example**

```ts
import { accessibility, config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';
let capability: accessibility.Capability[] = ['retrieve'];

config.enableAbility(name, capability, (err: BusinessError) => {
  if (err) {
    console.error(`failed to enable ability, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in enable ability, name is ${name}, capability is ${capability}`); 
});
```

## disableAbility

disableAbility(name: string): Promise&lt;void&gt;

Disables an accessibility extension ability. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the accessibility extension ability. The format is 'bundleName/abilityName'.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void>| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300001 | Invalid bundle name or ability name.  |

**Example**

```ts
import { accessibility, config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';

config.disableAbility(name).then(() => {
  console.info(`Succeeded in disable ability, name is ${name}`);
}).catch((err: BusinessError) => {
  console.error(`failed to disable ability, Code is ${err.code}, message is ${err.message}`);
})
```

## disableAbility

disableAbility(name: string, callback: AsyncCallback&lt;void&gt;): void

Disables an accessibility extension ability. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the accessibility extension ability. The format is 'bundleName/abilityName'.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300001 | Invalid bundle name or ability name.  |

**Example**

```ts
import { accessibility, config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';

config.disableAbility(name, (err: BusinessError) => {
  if (err) {
    console.error(`failed to enable ability, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in disable, name is ${name}`);
});
```

## on('enabledAccessibilityExtensionListChange')

on(type: 'enabledAccessibilityExtensionListChange', callback: Callback&lt;void&gt;): void

Adds a listener for changes in the list of enabled accessibility extension abilities. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type. The value is fixed at **'enabledAccessibilityExtensionListChange'**, indicating listening for changes in the list of enabled accessibility extension abilities.|
| callback | Callback&lt;void&gt; | Yes| Callback invoked when the list of enabled accessibility extension abilities changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';

config.on('enabledAccessibilityExtensionListChange', () => {
  console.info('subscribe enabled accessibility extension list change state success');
});
```

## off('enabledAccessibilityExtensionListChange')

off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback&lt;void&gt;): void

Cancels a listener for changes in the list of enabled accessibility extension abilities. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type |  string | Yes| Listening type. The value is fixed at **'enabledAccessibilityExtensionListChange'**, indicating listening for changes in the list of enabled accessibility extension abilities.|
| callback | Callback&lt;void&gt; | No| Callback for the event. The value must be the same as the value of **callback** in **on('enabledAccessibilityExtensionListChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';

config.off('enabledAccessibilityExtensionListChange', () => {
  console.info('Unsubscribe enabled accessibility extension list change state success');
});
```

## on('installedAccessibilityListChange')<sup>12+</sup>

on(type: 'installedAccessibilityListChange', callback: Callback&lt;void&gt;): void

Adds a listener for changes in the list of installed accessibility extension abilities. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type. The value is fixed at **'installedAccessibilityListChange'**, indicating listening for changes in the list of installed accessibility extension abilities.|
| callback | Callback&lt;void&gt; | Yes| Callback invoked when the list of installed accessibility extension abilities changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';

config.on('installedAccessibilityListChange', () => {
  console.info('subscribe installed accessibility extension list change state success');
});
```

## off('installedAccessibilityListChange')<sup>12+</sup>

off(type: 'installedAccessibilityListChange', callback?: Callback&lt;void&gt;): void

Cancels a listener for changes in the list of installed accessibility extension abilities. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type |  string | Yes| Listening type. The value is fixed at **'installedAccessibilityListChange'**, indicating listening for changes in the list of installed accessibility extension abilities.|
| callback | Callback&lt;void&gt; | No| Callback for the event. The value must be the same as the value of **callback** in **on('installedAccessibilityListChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';

config.off('installedAccessibilityListChange', () => {
  console.info('Unsubscribe installed accessibility extension list change state success');
});
```
## setMagnificationState<sup>20+</sup>

setMagnificationState(state: boolean): void

Sets the magnification state. Ensure that magnification is enabled before calling this API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| state |  boolean | Yes| Whether to trigger or disable the magnification feature.<br>- **true**: to trigger the magnification feature.<br>- **false**: to disable the magnification feature.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 9300007  | Trigger magnification failed. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';

try {
  config.setMagnificationState(true);
} catch (e) {
  console.error(`Set magnification failed,  error code: ${e?.code}, error msg: ${e?.message}`);
}
```

## Config

Implements configuration, acquisition, and listening for properties.

### set

set(value: T): Promise&lt;void&gt;

Sets the property value. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Property value to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void>| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let value: boolean = true;

config.highContrastText.set(value).then(() => {
  console.info(`Succeeded in set highContrastText value is ${value}`);
}).catch((err: BusinessError) => {
  console.error(`failed to set highContrastText, Code is ${err.code}, message is ${err.message}`);
});
```

### set

set(value: T, callback: AsyncCallback&lt;void&gt;): void

Sets the property value. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Property value to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let value: boolean = true;

config.highContrastText.set(value, (err: BusinessError) => {
  if (err) {
    console.error(`failed to set highContrastText, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in set highContrastText, value is ${value}`);
});
```

### get

get(): Promise&lt;T&gt;

Obtains the property value. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;T&gt; | Promise used to return the value obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

config.highContrastText.get().then((data: boolean) => {
  console.info(`Succeeded in get highContrastText, data is ${data}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get highContrastText, Code is ${err.code}, message is ${err.message}`);
});
```

### get

get(callback: AsyncCallback&lt;T&gt;): void

Obtains the property value. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;T&gt; | Yes| Callback used to return the property value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

config.highContrastText.get((err: BusinessError, data: boolean) => {
  if (err) {
    console.error(`failed to get highContrastText, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get highContrastText, data is ${data}`);
});
```

### on

on(callback: Callback&lt;T&gt;): void

Adds a listener for property changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | Yes| Callback invoked when the property changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';

config.highContrastText.on((data: boolean) => {
  console.info(`subscribe highContrastText success, result: ${JSON.stringify(data)}`);
});
```

### off

off(callback?: Callback&lt;T&gt;): void

Cancels the listener for property changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | No| Callback for the event. The value must be the same as the value of **callback** in **on()**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message|
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';

config.highContrastText.off((data: boolean) => {
  console.info(`Unsubscribe highContrastText success, result: ${JSON.stringify(data)}`);
});
```

## DaltonizationColorFilter

Enumerates the daltonization filters. 
**DaltonizationColorFilter** takes effect only when the daltonization filter is enabled ([daltonizationState](#properties) set to **true**).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name| Description|
| -------- | -------- |
| Normal | Filter for normal users.|
| Protanomaly | Filter for protanomaly.|
| Deuteranomaly | Filter for deuteranomaly.|
| Tritanomaly  | Filter for tritanomaly.|

## ClickResponseTime<sup>11+</sup>

Defines the length of time for a click. 

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name         | Description        |
|-------------|------------|
| Short       | Short (default). |
| Medium      | Medium.      |
| Long        | Long.      |

## RepeatClickInterval<sup>11+</sup>

Defines the interval between repeated clicks. 
**RepeatClickInterval** takes effect only when repeated clicks are ignored ([ignoreRepeatClick](#properties) set to **true**).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name      | Description   |
|----------|-------|
| Shortest | Shortest.|
| Short    | Short. |
| Medium   | Medium. |
| Long     | Long. |
| Longest  | Longest.|
