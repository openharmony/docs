# @ohos.accessibility.config (System Accessibility Configuration)

The **accessibility.config** module provides APIs for configuring system accessibility features, including accessibility extension, high-contrast text, mouse buttons, and captions.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import config from '@ohos.accessibility.config';
```

## Attributes

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name                                | Type                                                                                        | Readable| Writable| Description                                                       |
|------------------------------------|--------------------------------------------------------------------------------------------| -------- | -------- |-----------------------------------------------------------|
| highContrastText                   | [Config](#config)\<boolean>                                                                | Yes| Yes| Whether to enable high-contrast text.                                          |
| invertColor                        | [Config](#config)\<boolean>                                                                | Yes| Yes| Whether to enable color inversion.                                            |
| daltonizationState<sup>11+</sup>   | [Config](#config)\<boolean>                                                                | Yes| Yes| Whether to enable daltonization. It must be used with **daltonizationColorFilter**.               |
| daltonizationColorFilter           | [Config](#config)&lt;[DaltonizationColorFilter](#daltonizationcolorfilter)&gt;             | Yes| Yes| Configuration of the daltonization filter.                                              |
| contentTimeout                     | [Config](#config)\<number>                                                                 | Yes| Yes| Recommended duration for content display. The value ranges from 0 to 5000, in milliseconds.                            |
| animationOff                       | [Config](#config)\<boolean>                                                                | Yes| Yes| Whether to disable animation.                                            |
| brightnessDiscount                 | [Config](#config)\<number>                                                                 | Yes| Yes| Brightness discount. The value ranges from 0 to 1.0.                                     |
| mouseKey                           | [Config](#config)\<boolean>                                                                | Yes| Yes| Whether to enable the mouse button feature.                                             |
| mouseAutoClick                     | [Config](#config)\<number>                                                                 | Yes| Yes| Interval for automatic mouse clicks. The value ranges from 0 to 5000, in milliseconds.                          |
| shortkey                           | [Config](#config)\<boolean>                                                                | Yes| Yes| Whether to enable the accessibility extension shortcut key.                                         |
| shortkeyTarget                     | [Config](#config)\<string>                                                                 | Yes| Yes| Target application for the accessibility extension shortcut key. The value format is 'bundleName/abilityName'.  |
| captions                           | [Config](#config)\<boolean>                                                                | Yes| Yes| Whether to enable captions.                                            |
| captionsStyle                      | [Config](#config)\<[accessibility.CaptionsStyle](js-apis-accessibility.md#captionsstyle8)> | Yes| Yes| Captions style.                                               |
| audioMono<sup>10+</sup>            | [Config](#config)\<boolean>                                                                | Yes| Yes| Whether to enable mono audio.                                              |
| audioBalance<sup>10+</sup>         | [Config](#config)\<number>                                                                 | Yes| Yes| Audio balance for the left and right audio channels. The value ranges from -1.0 to +1.0.                               |
| shortkeyMultiTargets<sup>11+</sup> | [Config](#config)&lt;Array\<string>&gt;                                                    | Yes| Yes| List of target applications for the accessibility shortcut keys. The value format is ['bundleName/abilityName'].|
| clickResponseTime<sup>11+</sup>    | [Config](#config)&lt;[ClickResponseTime](#clickresponsetime11)&gt;                         | Yes| Yes| Length of time required for a click.                                            |
| ignoreRepeatClick<sup>11+</sup>    | [Config](#config)\<boolean>                                                                | Yes| Yes| Whether to ignore repeated clicks. This parameter must be used together with **repeatClickInterval**.                  |
| repeatClickInterval<sup>11+</sup>  | [Config](#config)&lt;[RepeatClickInterval](#repeatclickinterval11)&gt;                     | Yes| Yes| Interval between repeated clicks.                                            |

For a Boolean return value, **True** means that the feature is enabled, and **False** means the opposite.

## enableAbility

enableAbility(name: string, capability: Array&lt;accessibility.Capability&gt;): Promise&lt;void&gt;;

**Required permissions**: ohos.permission.WRITE_ACCESSIBILITY_CONFIG

Enables an accessibility extension ability. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the accessibility extension ability. The format is 'bundleName/abilityName'.|
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | Yes| Capability of the accessibility extension ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 9300001 | Invalid bundle name or ability name.  |
| 9300002 | Target ability already enabled. |

**Example**

```ts
import accessibility from '@ohos.accessibility';
import config from '@ohos.accessibility.config';
import { BusinessError } from '@ohos.base';

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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the accessibility extension ability. The format is 'bundleName/abilityName'.|
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | Yes| Capability of the accessibility extension ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 9300001 | Invalid bundle name or ability name.  |
| 9300002 | Target ability already enabled. |

**Example**

```ts
import accessibility from '@ohos.accessibility';
import config from '@ohos.accessibility.config';
import { BusinessError } from '@ohos.base';

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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the accessibility extension ability. The format is 'bundleName/abilityName'.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 9300001 | Invalid bundle name or ability name.  |

**Example**

```ts
import accessibility from '@ohos.accessibility';
import config from '@ohos.accessibility.config';
import { BusinessError } from '@ohos.base';

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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the accessibility extension ability. The format is 'bundleName/abilityName'.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](../errorcodes/errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 9300001 | Invalid bundle name or ability name.  |

**Example**

```ts
import accessibility from '@ohos.accessibility';
import config from '@ohos.accessibility.config';
import { BusinessError } from '@ohos.base';

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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type. The value is fixed at **'enabledAccessibilityExtensionListChange'**, indicating listening for changes in the list of enabled accessibility extension abilities.|
| callback | Callback&lt;void&gt; | Yes| Callback invoked when the list of enabled accessibility extension abilities changes.|

**Example**

```ts
import config from '@ohos.accessibility.config';

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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type |  string | Yes| Listening type. The value is fixed at **'enabledAccessibilityExtensionListChange'**, indicating listening for changes in the list of enabled accessibility extension abilities.|
| callback | Callback&lt;void&gt; | No| Callback for the event. The value must be the same as the value of **callback** in **on('enabledAccessibilityExtensionListChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
import config from '@ohos.accessibility.config';

config.off('enabledAccessibilityExtensionListChange', () => {
  console.info('Unsubscribe enabled accessibility extension list change state success');
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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Attribute value to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import config from '@ohos.accessibility.config';
import { BusinessError } from '@ohos.base';

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

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Attribute value to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

```ts
import config from '@ohos.accessibility.config';
import { BusinessError } from '@ohos.base';

let value: boolean = true;

config.highContrastText.set(value, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to set highContrastText. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in setting highContrastText. Value: ${value}`);
});
```

### get

get(): Promise&lt;T&gt;;

Obtains the attribute value. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;T&gt; | Promise used to return the value obtained.|

**Example**

```ts
import config from '@ohos.accessibility.config';
import { BusinessError } from '@ohos.base';

config.highContrastText.get().then((data: boolean) => {
  console.info(`Succeeded in getting highContrastText. Data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get highContrastText. Code: ${err.code}, message: ${err.message}`);
});
```

### get

get(callback: AsyncCallback&lt;T&gt;): void;

Obtains the attribute value. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;T&gt; | Yes| Callback used to return the attribute value.|

**Example**

```ts
import config from '@ohos.accessibility.config';
import { BusinessError } from '@ohos.base';

config.highContrastText.get((err: BusinessError, data: boolean) => {
  if (err) {
    console.error(`Failed to get highContrastText. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting highContrastText. Data: ${data}`);
});
```

### on

on(callback: Callback&lt;T&gt;): void;

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

Adds a listener for attribute changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | Yes| Callback invoked when the attribute changes.|

**Example**

```ts
import config from '@ohos.accessibility.config';

config.highContrastText.on((data: boolean) => {
  console.info(`Succeeded in subscribing to highContrastText. Result: ${JSON.stringify(data)}`);
});
```

### off

off(callback?: Callback&lt;T&gt;): void;

**Required permissions**: ohos.permission.READ_ACCESSIBILITY_CONFIG

Cancels the listener for attribute changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | No| Callback for the event. The value must be the same as the value of **callback** in **on()**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
import config from '@ohos.accessibility.config';

config.highContrastText.off((data: boolean) => {
  console.info(`Succeeded in unsubscribing from highContrastText. Result: ${JSON.stringify(data)}`);
});
```

## DaltonizationColorFilter

Enumerates the daltonization filters. 
When daltonization is enabled (with [daltonizationState](#attributes) set to **true**), the filter set for users with disabilities is used; otherwise, the filter for normal uses is used.<sup>11+</sup>

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
**RepeatClickInterval** takes effect only when repeated clicks are ignored ([ignoreRepeatClick](#attributes) set to **true**).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name      | Description   |
|----------|-------|
| Shortest | Shortest.|
| Short    | Short. |
| Medium   | Medium. |
| Long     | Long. |
| Longest  | Longest.|
