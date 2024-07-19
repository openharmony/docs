# @ohos.accessibility.config (SystemAPI)

The **accessibility.config** module provides APIs for configuring system accessibility features, including accessibility extension, high-contrast text, mouse buttons, and captions.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { config } from '@kit.AccessibilityKit';
```

## Attributes

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name                                | Type                                                                                        | Readable | Writable | Description                                                       |
|------------------------------------|--------------------------------------------------------------------------------------------| -------- | -------- |-----------------------------------------------------------|
| highContrastText                   | [Config](#config)\<boolean>                                                                | M | Supported | Whether to enable high-contrast text.                                          |
| invertColor                        | [Config](#config)\<boolean>                                                                | M | M | Whether to enable color inversion.                                            |
| daltonizationState<sup>11+</sup>   | [Config](#config)\<boolean>                                                                | Supported | M | Indicates whether the color filter function is enabled. It must be used with **daltonizationColorFilter**.               |
| daltonizationColorFilter           | [Config](#config)&lt;[DaltonizationColorFilter](#daltonizationcolorfilter)&gt;             | M | Supported | Configuration of the daltonization filter.                                              |
| contentTimeout                     | [Config](#config)\<number>                                                                 | M | Supported | Recommended duration for content display. The value ranges from 0 to 5000, in milliseconds.                            |
| animationOff                       | [Config](#config)\<boolean>                                                                | Supported | M | Whether to disable animation.                                            |
| brightnessDiscount                 | [Config](#config)\<number>                                                                 | M | Supported | Brightness discount. The value ranges from 0 to 1.0.                                     |
| mouseKey                           | [Config](#config)\<boolean>                                                                | Supported | Supported | Whether to enable the mouse button feature.                                             |
| mouseAutoClick                     | [Config](#config)\<number>                                                                 | M | Supported | Interval for automatic mouse clicks. The value ranges from 0 to 5000, in milliseconds.                          |
| shortkey                           | [Config](#config)\<boolean>                                                                | Supported | Supported | Whether to enable the accessibility extension shortcut key.                                         |
| shortkeyTarget                     | [Config](#config)\<string>                                                                 | M | M | Target application for the accessibility extension shortcut key. The value format is 'bundleName/abilityName'.  |
| captions                           | [Config](#config)\<boolean>                                                                | M | M | Whether to enable captions.                                            |
| captionsStyle                      | [Config](#config)\<[accessibility.CaptionsStyle](js-apis-accessibility.md#captionsstyle8)> | M | Supported | Captions style.                                               |
| audioMono<sup>10+</sup>            | [Config](#config)\<boolean>                                                                | Supported | Supported | Indicates the configuration of the mono audio channel.                                              |
| audioBalance<sup>10+</sup>         | [Config](#config)\<number>                                                                 | M | M | Audio balance for the left and right audio channels. The value ranges from -1.0 to 1.0.                               |
| shortkeyMultiTargets<sup>11+</sup> | [Config](#config)&lt;Array\<string>&gt;                                                    | Supported | M | Indicates the list configuration of auxiliary extended shortcut keys. The value is the name of the auxiliary application. The format is ['bundleName/abilityName']. |
| clickResponseTime<sup>11+</sup>    | [Config](#config)&lt;[ClickResponseTime](#clickresponsetime11)&gt;                         | M | M | Indicates the configuration of the click duration function.                                            |
| ignoreRepeatClick<sup>11+</sup>    | [Config](#config)\<boolean>                                                                | M | M | Indicates whether the function of ignoring repeated clicks is enabled. This parameter is used together with repeatClickInterval.                  |
| repeatClickInterval<sup>11+</sup>  | [Config](#config)&lt;[RepeatClickInterval](#repeatclickinterval11)&gt;                     | M | Supported | Indicates that the repeated click function is ignored.                                            |

For a boolean return value, **True** means that the feature is enabled, and **False** means the opposite.
[]()
## enableAbility

enableAbility(name: string, capability: Array&lt;accessibility.Capability&gt;): Promise&lt;void&gt;;

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

Enables an accessibility extension ability. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type                                                                          | Mandatory | Description |
| -------- |------------------------------------------------------------------------------| -------- | -------- |
| name | string                                                                       | M | Name of an auxiliary application. The format is bundleName/abilityName. |
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | M | Capability attribute of an auxiliary application. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | that returns no value. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
| ------- | -------------------------------- |
| 201 | Permission denied.  |
| 202 | Not system App. |
| 401  | Input parameter error. 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
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

enableAbility(name: string, capability: Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt;, callback: AsyncCallback&lt;void&gt;): void;

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

Enables an accessibility extension ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type                                                                             | Mandatory | Usage |
| -------- |---------------------------------------------------------------------------------| -------- | -------- |
| name | string                                                                          | M | Name of an auxiliary application. The format is bundleName/abilityName. |
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | M | Capability attribute of an auxiliary application. |
| callback | AsyncCallback&lt;void&gt;                                                       | M | Callback used to return |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
| ------- | -------------------------------- |
| 201 | Permission denied.  |
| 202 | Not system App. |
| 401  | Input parameter error. 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
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

disableAbility(name: string): Promise&lt;void&gt;;

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

Disables an accessibility extension ability. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | Usage |
| -------- | -------- | -------- | -------- |
| name | string | M | Name of an auxiliary application. The format is bundleName/abilityName. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;void&gt; | that returns no value. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
| ------- | -------------------------------- |
| 201 | Permission denied.  |
| 202 | Not system App. |
| 401  | Input parameter error. 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
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

disableAbility(name: string, callback: AsyncCallback&lt;void&gt;): void;

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

Disables an accessibility extension ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | Usage |
| -------- | -------- | -------- | -------- |
| name | string | Supported | Name of an auxiliary application. The format is bundleName/abilityName. |
| callback | AsyncCallback&lt;void&gt; | Supported | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
| ------- | -------------------------------- |
| 201 | Permission denied.  |
| 202 | Not system App. |
| 401  | Input parameter error. 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
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

on(type: 'enabledAccessibilityExtensionListChange', callback: Callback&lt;void&gt;): void;

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

Adds a listener for changes in the list of enabled accessibility extension abilities. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | File |
| -------- | -------- | -------- | -------- |
| type | string | M | This parameter has a fixed value of enabledAccessibilityExtensionListChange, indicating that the list of enabled auxiliary extensions changes. |
| callback | Callback&lt;void&gt; | M | Callback function, which is used to notify when the list of enabled auxiliary extensions changes. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
| ------- | -------------------------------- |
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

off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback&lt;void&gt;): void;

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

Cancels the listener for changes in the list of enabled accessibility extension abilities. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | Usage |
| -------- | -------- | -------- | -------- |
| type |  string | M | This parameter has a fixed value of enabledAccessibilityExtensionListChange, indicating that the list of enabled auxiliary extensions changes. |
| callback | Callback&lt;void&gt; | No | Cancels the event response of a specified callback object. The value must be the same as the value of **callback** in **on('enabledAccessibilityExtensionListChange')**. By default, all registered events are deregistered. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
| ------- | -------------------------------- |
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

on(type: 'installedAccessibilityListChange', callback: Callback&lt;void&gt;): void;

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

Add a list change listener for installed auxiliary extensions and use callback for asynchronous callback.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | Usage |
| -------- | -------- | -------- | -------- |
| type | string | Supported | This parameter has a fixed value of installedAccessibilityListChange, indicating that the list of installed auxiliary extensions changes. |
| callback | Callback&lt;void&gt; | M | Callback function, which is used to notify when the list of installed auxiliary extensions changes. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
| ------- | -------------------------------- |
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

off(type: 'installedAccessibilityListChange', callback?: Callback&lt;void&gt;): void;

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

Cancel the list change listening of the installed auxiliary extension and use callback to perform asynchronous callback.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | Usage |
| -------- | -------- | -------- | -------- |
| type |  string | M | This parameter has a fixed value of installedAccessibilityListChange, indicating that the list of installed auxiliary extensions changes. |
| callback | Callback&lt;void&gt; | No | Cancels the event response of a specified callback object. The value must be the same as the value of callback in on(' installedAccessibilityListChange'). By default, all registered events are deregistered. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
| ------- | -------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';

config.off('installedAccessibilityListChange', () => {
  console.info('Unsubscribe installed accessibility extension list change state success');
});
```

## Config

Implements configuration, acquisition, and listening for attributes.

### set

set(value: T): Promise&lt;void&gt;;

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

Sets the attribute value. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | **Description** |
| -------- | -------- | -------- | -------- |
| value | T | Supported | Attribute value. |

**Return value**

| Type | Requirement |
| -------- | -------- |
| Promise&lt;void&gt; | that returns no value. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
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

set(value: T, callback: AsyncCallback&lt;void&gt;): void;

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

Sets the attribute value. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | **Description** |
| -------- | -------- | -------- | -------- |
| value | T | M | Attribute value. |
| callback | AsyncCallback&lt;void&gt; | M | Callback used to return the result. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
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

get(): Promise&lt;T&gt;;

Obtains the attribute value. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;T&gt; | Promise object, which returns the corresponding attribute value. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
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

get(callback: AsyncCallback&lt;T&gt;): void;

Obtains the attribute value. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | **Description** |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;T&gt; | Supported | Callback function, which returns the attribute value. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
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

on(callback: Callback&lt;T&gt;): void;

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

Adds a listener for attribute changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | **Description** |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | Supported | Callback function, which is used to notify users of attribute changes. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
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

off(callback?: Callback&lt;T&gt;): void;

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

Cancels the listener for attribute changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type | Mandatory/Optional | Description |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | No | Cancels the event response of a specified callback object. The value must be the same as the value of **callback** in **on()**. By default, all registered events are deregistered. |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| Error Code | Error Message |
| ------- | -------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
import { config } from '@kit.AccessibilityKit';

config.highContrastText.off((data: boolean) => {
  console.info(`Unsubscribe highContrastText success, result: ${JSON.stringify(data)}`);
});
```

## DaltonizationColorFilter

Corrected color filters for different amblyopia types. 
When daltonization is enabled (with [daltonizationState](#attributes) set to **true**), the filter set for users with disabilities is used; otherwise, the filter for normal uses is used.<sup>11+</sup>

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name | **Description** |
| -------- | -------- |
| Normal | Indicates the normal type. |
| Protanomaly | Indicates the red amblyopia type. |
| Deuteranomaly | Indicates the green amblyopia type. |
| Tritanomaly  | Indicates the blue amblyopia type. |

## ClickResponseTime<sup>11+</sup>

It is used for the click repetition time of different durations. 

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name         | Description        |
|-------------|------------|
| Short       | Indicates short (default). |
| Medium      | Medium.      |
| Long        | Long.      |

## RepeatClickInterval<sup>11+</sup>

Used to ignore repeated clicks at different intervals. 
When the function of ignoring repeated clicks is enabled ([ignoreRepeatClick](#attributes) is set to true), the configuration of ignoring repeated clicks (that is, the value of RepeatClickInterval) takes effect. When the function of ignoring repeated clicks is disabled ([ignoreRepeatClick] (#attribute) is set to false), the type is displayed as normal.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name      | Description   |
|----------|-------|
| Shortest | Indicates the shortest. |
| Short    | Short. |
| Medium   | Medium. |
| Long     | Long. |
| Longest  | Indicates the longest. |
