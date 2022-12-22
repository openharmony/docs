# @ohos.accessibility.config

The System Accessibility Configuration module allows you to configure system accessibility features, including accessibility extension, high-contrast text, mouse buttons, and captions.

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

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| highContrastText | [Config](#config)\<boolean>| Yes| Yes| Whether to enable high-contrast text.|
| invertColor | [Config](#config)\<boolean>| Yes| Yes| Whether to enable color inversion.|
| daltonizationColorFilter | [Config](#config)&lt;[DaltonizationColorFilter](#daltonizationcolorfilter)&gt;| Yes| Yes| Configuration of the daltonization filter.|
| contentTimeout | [Config](#config)\<number>| Yes| Yes| Recommended duration for content display. The value ranges from 0 to 5000, in milliseconds.|
| animationOff | [Config](#config)\<boolean>| Yes| Yes| Whether to disable animation.|
| brightnessDiscount | [Config](#config)\<number>| Yes| Yes| Brightness discount. The value ranges from 0 to 1.0.|
| mouseKey | [Config](#config)\<boolean>| Yes| Yes| Whether to enable the mouse button feature.|
| mouseAutoClick | [Config](#config)\<number>| Yes| Yes| Interval for automatic mouse clicks. The value ranges from 0 to 5000, in milliseconds.|
| shortkey | [Config](#config)\<boolean>| Yes| Yes| Whether to enable the accessibility extension shortcut key.|
| shortkeyTarget | [Config](#config)\<string>| Yes| Yes| Target application for the accessibility extension shortcut key. The value format is 'bundleName/abilityName'.|
| captions | [Config](#config)\<boolean>| Yes| Yes| Whether to enable captions.|
| captionsStyle | [Config](#config)\<[accessibility.CaptionsStyle](js-apis-accessibility.md#captionsstyle8)>| Yes| Yes| Captions style.|

## enableAbility

enableAbility(name: string, capability: Array&lt;accessibility.Capability&gt;): Promise&lt;void&gt;;

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
let name = 'com.ohos.example/axExtension';
let capability : accessibility.Capability[] = ['retrieve'];
try {
    config.enableAbility(name, capability).then(() => {
      console.info('enable ability succeed');
    }).catch((err) => {
      console.error('failed to enable ability, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to enable ability, because ' + JSON.stringify(exception));
};
```

## enableAbility

enableAbility(name: string, capability: Array&lt;accessibility.Capability&gt;, callback: AsyncCallback&lt;void&gt;): void;

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
let name = 'com.ohos.example/axExtension';
let capability : accessibility.Capability[] = ['retrieve'];
try {
    config.enableAbility(name, capability, (err) => {
        if (err) {
            console.error('failed to enable ability, because ' + JSON.stringify(err));
            return;
        }
        console.info('enable ability succeed');
    });
} catch (exception) {
    console.error('failed to enable ability, because ' + JSON.stringify(exception));
};
```

## disableAbility

disableAbility(name: string): Promise&lt;void&gt;;

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
let name = 'com.ohos.example/axExtension';
try {
    config.disableAbility(name).then(() => {
      console.info('disable ability succeed');
    }).catch((err) => {
      console.error('failed to disable ability, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to disable ability, because ' + JSON.stringify(exception));
};
```

## disableAbility

disableAbility(name: string, callback: AsyncCallback&lt;void&gt;): void;

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
let name = 'com.ohos.example/axExtension';
try {
    config.disableAbility(name, (err, data) => {
        if (err) {
            console.error('failed to enable ability, because ' + JSON.stringify(err));
            return;
        }
        console.info('disable succeed');
    });
} catch (exception) {
    console.error('failed to enable ability, because ' + JSON.stringify(exception));
};
```

## on('enabledAccessibilityExtensionListChange')

on(type: 'enabledAccessibilityExtensionListChange', callback: Callback&lt;void&gt;): void;

Adds a listener for changes in the list of enabled accessibility extension abilities. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type. The value is fixed at **'enabledAccessibilityExtensionListChange'**, indicating listening for changes in the list of enabled accessibility extension abilities.|
| callback | Callback&lt;void&gt; | Yes| Callback invoked when the list of enabled accessibility extension abilities changes.|

**Example**

```ts
try {
    config.on('enabledAccessibilityExtensionListChange', () => {
        console.info('subscribe enabled accessibility extension list change state success');
    });
} catch (exception) {
    console.error('failed to subscribe enabled accessibility extension list change state, because ' +
    JSON.stringify(exception));
};
```

## off('enabledAccessibilityExtensionListChange')

off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback&lt;void&gt;): void;

Cancels the listener for changes in the list of enabled accessibility extension abilities. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type |  string | Yes| Listening type. The value is fixed at **'enabledAccessibilityExtensionListChange'**, indicating listening for changes in the list of enabled accessibility extension abilities.|
| callback | Callback&lt;void&gt; | No| Callback invoked when the list of enabled accessibility extension abilities changes.|

**Example**

```ts
try {
    config.off('enabledAccessibilityExtensionListChange', () => {
        console.info('Unsubscribe enabled accessibility extension list change state success');
    });
} catch (exception) {
    console.error('failed to Unsubscribe enabled accessibility extension list change state, because ' +
    JSON.stringify(exception));
};
```

## Config

Implements configuration, acquisition, and listening for attributes.

### set

set(value: T): Promise&lt;void&gt;;

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
let value = true;
try {
    config.highContrastText.set(value).then(() => {
        console.info('set highContrastText succeed');
    }).catch((err) => {
        console.error('failed to set highContrastText, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to set config, because ' + JSON.stringify(exception));
};
```

### set

set(value: T, callback: AsyncCallback&lt;void&gt;): void;

Sets the attribute value. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Attribute value to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

```ts
let value = true;
try {
    config.highContrastText.set(value, (err, data) => {
        if (err) {
            console.error('failed to set highContrastText, because ' + JSON.stringify(err));
            return;
        }
        console.info('set highContrastText succeed');
    });
} catch (exception) {
    console.error('failed to set config, because ' + JSON.stringify(exception));
};
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
let value;
config.highContrastText.get().then((data) => {
    value = data;
    console.info('get highContrastText success');
}).catch((err) => {
    console.error('failed to get highContrastText, because ' + JSON.stringify(err));
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
let value;
config.highContrastText.get((err, data) => {
    if (err) {
        console.error('failed to get highContrastText, because ' + JSON.stringify(err));
        return;
    }
    value = data;
    console.info('get highContrastText success');
});
```

### on

on(callback: Callback&lt;T&gt;): void;

Adds a listener for attribute changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | Yes| Callback invoked when the attribute changes.|

**Example**

```ts
try {
    config.highContrastText.on((data) => {
        console.info('subscribe highContrastText success, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed subscribe highContrastText, because ' + JSON.stringify(exception));
}
```

### off

off(callback?: Callback&lt;T&gt;): void;

Cancels the listener for attribute changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | No| Callback invoked when the list of enabled accessibility extension abilities changes.|

**Example**

```ts
config.highContrastText.off((data) => {
    console.info('Unsubscribe highContrastText success, result: ' + JSON.stringify(data));
});
```

## DaltonizationColorFilter

Enumerates the daltonization filters.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name| Description|
| -------- | -------- |
| Normal | Filter for normal users.|
| Protanomaly | Filter for protanomaly.|
| Deuteranomaly | Filter for deuteranomaly.|
| Tritanomaly  | Filter for tritanomaly.|
