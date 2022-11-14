# System Accessibility Configuration

The **config** module allows you to configure system accessibility features, including accessibility extension, high-contrast text, mouse buttons, and captions.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```typescript
import config from "@ohos.accessibility.config";
```

## Attributes

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| highContrastText | [Config](#config)\<boolean>| Yes| Yes| Whether to enable high-contrast text.|
| invertColor | [Config](#config)\<boolean>| Yes| Yes| Whether to enable color inversion.|
| daltonizationColorFilter | [Config](#config)\<[DaltonizationColorFilter](#daltonizationcolorfilter)>| Yes| Yes| Daltonization filter. |
| contentTimeout | [Config](#config)\<number>| Yes| Yes| Recommended duration for content display. The value ranges from 0 to 5000, in milliseconds.|
| animationOff | [Config](#config)\<boolean>| Yes| Yes| Whether to enable animation.|
| brightnessDiscount | [Config](#config)\<number>| Yes| Yes| Brightness discount. The value ranges from 0 to 1.0.|
| mouseKey | [Config](#config)\<boolean>| Yes| Yes| Whether to enable the mouse button feature.|
| mouseAutoClick | [Config](#config)\<number>| Yes| Yes| Interval for the automatic mouse clicks. The value ranges from 0 to 5000, in milliseconds.|
| shortkey | [Config](#config)\<boolean>| Yes| Yes| Whether to enable the accessibility extension shortcut key.|
| shortkeyTarget | [Config](#config)\<string>| Yes| Yes| Target application for the accessibility extension shortcut key. The value format is bundleName/abilityName.|
| captions | [Config](#config)\<boolean>| Yes| Yes| Whether to enable captions.|
| captionsStyle | [Config](#config)\<[accessibility.CaptionsStyle](./js-apis-accessibility.md#captionsstyle8)>| Yes| Yes| Captions style.|

## enableAbility

enableAbility(name: string, capability: Array&lt;[accessibility.Capability](./js-apis-accessibility.md#capability)&gt;): Promise&lt;void&gt;;

Enables an accessibility extension ability. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the accessibility extension ability. The format is bundleName/abilityName.|
| capability | Array&lt;[accessibility.Capability](./js-apis-accessibility.md#capability)&gt;) | Yes| Capability of the accessibility extension ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the execution result.|

**Example**

  ```typescript
  config.enableAbility("com.ohos.example/axExtension", ['retrieve'])
      .then(() => {
        console.info('enable succeed');
      }).catch((error) => {
        console.error('enable failed');
      });
  ```

## enableAbility

enableAbility(name: string, capability: Array&lt;[accessibility.Capability](./js-apis-accessibility.md#capability)&gt;, callback: AsyncCallback&lt;void&gt;): void;

Enables an accessibility extension ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the accessibility extension ability. The format is bundleName/abilityName.|
| capability | Array&lt;[accessibility.Capability](./js-apis-accessibility.md#capability)&gt; | Yes| Capability of the accessibility extension ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

**Example**

  ```typescript
  config.enableAbility("com.ohos.example/axExtension", ['retrieve'], (err, data) => {
      if (err) {
          console.error('enable failed');
          return;
      }
      console.info('enable succeed');
    })
  ```

## disableAbility

disableAbility(name: string): Promise&lt;void&gt;;

Disables an accessibility extension ability. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the accessibility extension ability. The format is bundleName/abilityName.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the execution result.|

**Example**

  ```typescript
  config.disableAbility("com.ohos.example/axExtension")
      .then(() => {
        console.info('disable succeed');
      }).catch((error) => {
        console.error('disable failed');
      });
  ```

## disableAbility

disableAbility(name: string, callback: AsyncCallback&lt;void&gt;): void;

Disables an accessibility extension ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the accessibility extension ability. The format is bundleName/abilityName.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

**Example**

  ```typescript
  config.disableAbility("com.ohos.example/axExtension", (err, data) => {
      if (err) {
          console.error('disable failed');
          return;
      }
      console.info('disable succeed');
    })
  ```

## on('enableAbilityListsStateChanged')

on(type: 'enableAbilityListsStateChanged', callback: Callback&lt;void&gt;): void;

Adds a listener for changes in the list of enabled accessibility extension abilities.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Listening type. The value is fixed at **'enableAbilityListsStateChanged'**, indicating the changes in the list of enabled accessibility extension abilities. |
| callback | Callback&lt;void&gt; | Yes| Callback invoked when the list of enabled accessibility extension abilities changes.|

**Example**

  ```typescript
  config.on('enableAbilityListsStateChanged',() => {
      console.info('ax extension ability enable list changed');
  });
  ```

## off('enableAbilityListsStateChanged')

off(type: 'enableAbilityListsStateChanged', callback?: Callback&lt;void&gt;): void;

Cancels the listener for changes in the list of enabled accessibility extension abilities.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type |  string | No| Listening type. The value is fixed at **'enableAbilityListsStateChanged'**, indicating the changes in the list of enabled accessibility extension abilities. |
| callback | Callback&lt;void&gt; | No| Callback invoked when the list of enabled accessibility extension abilities changes.|

**Example**

  ```typescript
  config.off('enableAbilityListsStateChanged');
  ```

## Config

Implements configuration, acquisition, and listening for attributes.

### set

set(value: T): Promise&lt;void&gt;;

Sets this attribute. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Attribute value to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the execution result.|

**Example**

  ```typescript
  config.highContrastText.set(true)
      .then(() => {
        console.info('highContrastText set succeed');
      }).catch((error) => {
        console.error('highContrastText set failed');
      });
  ```

### set

set(value: T, callback: AsyncCallback&lt;void&gt;): void;

Sets this attribute. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | T | Yes| Attribute value to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the execution result.|

**Example**

  ```typescript
  config.highContrastText.set(true, (err, data) => {
      if (err) {
          console.error('highContrastText set failed');
          return;
      }
      console.info('highContrastText set succeed');
    })
  ```

### get

get(): Promise&lt;T&gt;;

Obtains the value of this attribute. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;T&gt; | Promise used to return the attribute value.|

**Example**

  ```typescript
  config.highContrastText.get()
      .then((value) => {
        console.info('highContrastText get succeed');
      }).catch((error) => {
        console.error('highContrastText get failed');
      });
  ```

### get

get(callback: AsyncCallback&lt;T&gt;): void;

Obtains the value of this attribute. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the attribute value.|

**Example**

  ```typescript
  config.highContrastText.get((err, data) => {
      if (err) {
          console.error('highContrastText get failed');
          return;
      }
      console.info('highContrastText get succeed');
    })
  ```

### on

on(callback: Callback&lt;T&gt;): void;

Adds a listener for attribute changes.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | Yes| Callback invoked when the attribute changes.|

**Example**

  ```typescript
  config.highContrastText.on(() => {
      console.info('highContrastText changed');
  });
  ```

### off

off(callback?: Callback&lt;T&gt;): void;

Cancels the listener for attribute changes.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | No| Callback invoked when the attribute changes.|

**Example**

  ```typescript
  config.highContrastText.off();
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
