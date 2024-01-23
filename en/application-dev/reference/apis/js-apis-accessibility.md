# @ohos.accessibility (Accessibility)

The **Accessibility** module implements the accessibility functions, including obtaining the accessibility application list, accessibility application enabled status, and captions configuration.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import accessibility from '@ohos.accessibility';
```

## AbilityState

Enumerates the states of an accessibility application.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name     | Description      |
| ------- | -------- |
| enable  | The accessibility application is enabled.|
| disable | The accessibility application is disabled.|
| install | The accessibility application has been installed.|

## AbilityType

Enumerates the types of accessibility applications.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name              | Description       |
| ---------------- | --------- |
| audible          | The accessibility application provides audible feedback.|
| generic          | The accessibility application provides generic feedback.|
| haptic           | The accessibility application provides haptic feedback.|
| spoken           | The accessibility application provides spoken feedback.|
| visual           | The accessibility application provides visual feedback.|
| all<sup>9+</sup> | All the preceding types.|

## AccessibilityAbilityInfo

Provides information about an accessibility application.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Attributes

| Name                            | Type                                      | Readable  | Writable  | Description              |
| ------------------------------ | ---------------------------------------- | ---- | ---- | ---------------- |
| id                             | string                                   | Yes   | No   | Ability ID.|
| name                           | string                                   | Yes   | No   | Ability name.      |
| bundleName                     | string                                   | Yes   | No   | Bundle name.       |
| targetBundleNames<sup>9+</sup> | Array&lt;string&gt;                      | Yes   | No   | Name of the target bundle.  |
| abilityTypes                   | Array&lt;[AbilityType](#abilitytype)&gt; | Yes   | No   | Accessibility application type.         |
| capabilities                   | Array&lt;[Capability](#capability)&gt;   | Yes   | No   | Capabilities list of the accessibility application.       |
| description                    | string                                   | Yes   | No   | Description of the accessibility application.         |
| eventTypes                     | Array&lt;[EventType](#eventtype)&gt;     | Yes   | No   | List of events that the accessibility application focuses on. |

## Action

Describes the target action supported by an accessibility application.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name                     | Description                |
| ----------------------- |--------------------|
| click                   | Clicking.           |
| longClick               | Long pressing.           |
| scrollForward           | Scrolling forward. Not supported yet.|
| scrollBackward          | Scrolling backward. Not supported yet.|
| focus                   | Obtaining the focus. Not supported yet.|
| clearFocus              | Clearing focus. Not supported yet.|
| clearSelection          | Clearing selection. Not supported yet.|
| accessibilityFocus      | Obtaining the accessibility focus.      |
| clearAccessibilityFocus | Clearing the accessibility focus.      |
| cut                     | Cut. Not supported yet.  |
| copy                    | Copy. Not supported yet.  |
| paste                   | Paste. Not supported yet.  |
| select                  | Select. Not supported yet.  |
| setText                 | Setting the text. Not supported yet.|
| delete                  | Delete. Not supported yet.  |
| setSelection            | Setting the selection. Not supported yet.  |

## Capability

Enumerates the capabilities of an accessibility application.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name              | Description                   |
| ---------------- |-----------------------|
| retrieve         | Capability to retrieve the window content.         |
| touchGuide       | Capability of touch guide mode.         |
| keyEventObserver | Capability to filter key events.         |
| zoom             | Capability to control the display zoom level. Not supported yet.|
| gesture          | Capability to perform gesture actions.         |

## CaptionsFontEdgeType<sup>8+</sup>

Enumerates the font edge types of captions.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

| Name        | Description   |
| ---------- | ----- |
| none       | No effect. |
| raised     | Raised effect.|
| depressed  | Depressed effect.|
| uniform    | Uniform effect.|
| dropShadow | Drop shadow effect.|

## CaptionsFontFamily<sup>8+</sup>

Enumerates the font families of captions.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

| Name                 | Description               |
| ------------------- | ----------------- |
| default             | Default font family.            |
| monospacedSerif     | Monospaced Serif fonts, which use the same width for each character.     |
| serif               | Serif fonts.        |
| monospacedSansSerif | Monospaced Sans Serif fonts, which use the same width for each character.|
| sansSerif           | Sans Serif fonts.   |
| casual              | Casual fonts.           |
| cursive             | Cursive fonts.            |
| smallCapitals       | Small caps fonts.        |

## CaptionsStyle<sup>8+</sup>

Describes the style of captions.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

| Name             | Type                                      | Readable  | Writable  | Description         |
| --------------- | ---------------------------------------- | ---- | ---- | ----------- |
| fontFamily      | [CaptionsFontFamily](#captionsfontfamily8) | Yes   | No   | Font family of captions.    |
| fontScale       | number                                   | Yes   | No   | Font scale factor of captions, in percentage. The value ranges from 1 to 200.|
| fontColor       | number \| string                         | Yes   | No   | Font color of captions. For example, red corresponds to #FF0000.  |
| fontEdgeType    | [CaptionsFontEdgeType](#captionsfontedgetype8) | Yes   | No   | Font edge type of captions.  |
| backgroundColor | number \| string                         | Yes   | No   | Background color of captions. For example, red corresponds to #FF0000.  |
| windowColor     | number \| string                         | Yes   | No   | Window color of captions. For example, red corresponds to #FF0000.  |

## CaptionsManager<sup>8+</sup>

Implements configuration management for captions. Before calling any API of **CaptionsManager**, you must use the [accessibility.getCaptionsManager()](#accessibilitygetcaptionsmanager8) API to obtain a **CaptionsManager** instance.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

### Attributes

| Name     | Type                              | Readable  | Writable  | Description         |
| ------- | -------------------------------- | ---- | ---- | ----------- |
| enabled | boolean                          | Yes   | No   | Whether to enable captions configuration.|
| style   | [CaptionsStyle](#captionsstyle8) | Yes   | No   | Style of captions.    |

For a boolean return value, **True** means that the feature is enabled, and **False** means the opposite.

### on('enableChange')

on(type: 'enableChange', callback: Callback&lt;boolean&gt;): void;

Enables listening for the enabled status changes of captions configuration. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name     | Type                     | Mandatory  | Description                                     |
| -------- | ----------------------- | ---- | --------------------------------------- |
| type     | string                  | Yes   | Listening type, which is set to **'enableChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes   | Callback invoked when the enabled status of captions configuration changes.             |

**Example**

```ts
import accessibility from '@ohos.accessibility';

let captionsManager = accessibility.getCaptionsManager();
captionsManager.on('enableChange', (data: boolean) => {
  console.info(`subscribe caption manager enable state change, result: ${JSON.stringify(data)}`);
})
```

### on('styleChange')

on(type: 'styleChange', callback: Callback&lt;CaptionsStyle&gt;): void;

Enables listening for captions style changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| type     | string                                   | Yes   | Listening type, which is set to **'styleChange'** in this API.|
| callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | Yes   | Callback invoked when the style of captions changes.           |

**Example**

```ts
import accessibility from '@ohos.accessibility';

let captionsManager = accessibility.getCaptionsManager();

captionsManager.on('styleChange', (data: accessibility.CaptionsStyle) => {
  console.info(`subscribe caption manager style state change, result: ${JSON.stringify(data)}`);
});
```

### off('enableChange')

off(type: 'enableChange', callback?: Callback&lt;boolean&gt;): void;

Disables listening for the enabled status changes of captions configuration. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Listening type, which is set to **'enableChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No  | Callback used for disable listening. The value must be the same as the value of **callback** in **on('enableChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
import accessibility from '@ohos.accessibility';

let captionsManager = accessibility.getCaptionsManager();

captionsManager.off('enableChange', (data: boolean) => {
  console.info(`Unsubscribe caption manager enable state change, result: ${JSON.stringify(data)}`);
});
```

### off('styleChange')

off(type: 'styleChange', callback?: Callback&lt;CaptionsStyle&gt;): void;

Disables listening for captions style changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name  | Type                                            | Mandatory| Description                                                        |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                           | Yes  | Listening type, which is set to **'styleChange'** in this API. |
| callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | No  | Callback used for disable listening. The value must be the same as the value of **callback** in **on('styleChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
import accessibility from '@ohos.accessibility';

let captionsManager = accessibility.getCaptionsManager();

captionsManager.off('styleChange', (data: accessibility.CaptionsStyle) => {
  console.info(`Unsubscribe caption manager style state change, result: ${JSON.stringify(data)}`);
});
```

## EventInfo

Describes a GUI change event.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Attributes

| Name              | Type                                   | Mandatory | Description                   |
| ---------------- | ------------------------------------- |-----|-----------------------|
| type             | [EventType](#eventtype)               | Yes  | Accessibility event type.        |
| windowUpdateType | [WindowUpdateType](#windowupdatetype) | No  | Window update type.              |
| bundleName       | string                                | Yes  | Name of the target application.          |
| componentType    | string                                | No  | Type of the event source component, for example, button or chart.      |
| pageId           | number                                | No  | Page ID of the event source.           |
| description      | string                                | No  | Event description. Not supported yet.       |
| triggerAction    | [Action](#action)                     | Yes  | Action that triggers the event.   |
| textMoveUnit     | [TextMoveUnit](#textmoveunit)         | No  | Text move granularity. Not supported yet.     |
| contents         | Array&lt;string&gt;                   | No  | Array of contents.                |
| lastContent      | string                                | No  | Latest content.                |
| beginIndex       | number                                | No  | Sequence number of the first item displayed on the page. Not supported yet.|
| currentIndex     | number                                | No  | Sequence number of the current item. Not supported yet.     |
| endIndex         | number                                | No  | Sequence number of the last item displayed on the page. Not supported yet.|
| itemCount        | number                                | No  | Total number of records. Not supported yet.       |

### constructor

constructor(jsonObject)

Implements a constructor.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name       | Type    | Mandatory  | Description                  |
| ---------- | ------ | ---- | -------------------- |
| jsonObject | string | Yes   | JSON string required for creating an object.|

**Example**

  ```ts
  import accessibility from '@ohos.accessibility';

  let eventInfo: accessibility.EventInfo = ({
    type: 'click',
    bundleName: 'com.example.MyApplication',
    triggerAction: 'click',
  });
  ```

### constructor<sup>11+</sup>

constructor(type: EventType, bundleName: string, triggerAction: Action)

Implements a constructor.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type               | Mandatory| Description           |
|------|-------------------|---|---------------|
| type | [EventType](#eventtype)          | Yes| Enumerates accessibility event types.     |
| bundleName | string | Yes| Target application name.       |
| triggerAction | [Action](#action) | Yes| Action that triggers the event.|

**Example**

  ```ts
  import accessibility from '@ohos.accessibility';

  let eventInfo = new accessibility.EventInfo('click', 'com.example.MyApplication', 'click');
  ```

## EventType

Enumerates accessibility event types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name                     | Description                    |
| ----------------------- |------------------------|
| accessibilityFocus      | Event indicating that the accessibility focus has been obtained.         |
| accessibilityFocusClear | Event indicating that the accessibility focus has been cleared.         |
| click                   | Event of clicking a component.            |
| longClick               | Event of long-pressing a component.            |
| select                  | Event of selecting a component. Not supported yet.   |
| hoverEnter              | Event indicating that the hover enters a component. Not supported yet. |
| hoverExit               | Event indicating that the hover exits a component. Not supported yet. |
| focus                   | Event indicating that the component obtains the focus. Not supported yet. |
| textUpdate              | Event indicating that the component text has been updated. Not supported yet.|
| textSelectionUpdate     | Event indicating that the selected text has been updated. Not supported yet.|
| scroll                  | Event of the scroll view. Not supported yet.   |


## TextMoveUnit

Enumerates the movement units for traversing the node text.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name       | Description             |
| --------- | --------------- |
| char      | The movement unit for traversing the node text is by character.|
| word      | The movement unit for traversing the node text is by word. |
| line      | The movement unit for traversing the node text is by line. |
| page      | The movement unit for traversing the node text is by page. |
| paragraph | The movement unit for traversing the node text is by paragraph.|

## WindowUpdateType

Enumerates window update types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name    | Description                |
| ------ | ------------------ |
| add    | Window adding.      |
| remove | Window deletion.   |
| bounds | Window boundary change.   |
| active | Window activity change.|
| focus  | Window focus change.  |

## accessibility.getAbilityLists<sup>(deprecated)</sup>

getAbilityLists(abilityType: AbilityType, stateType: AbilityState): Promise&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;

Obtains the accessibility application list. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.
> You are advised to use [accessibility.getAccessibilityExtensionList()](#accessibilitygetaccessibilityextensionlist9) instead.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                           | Mandatory  | Description      |
| ----------- | ----------------------------- | ---- | -------- |
| abilityType | [AbilityType](#abilitytype)   | Yes   | Accessibility application type.|
| stateType   | [AbilityState](#abilitystate) | Yes   | Accessibility application status.|

**Return value**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | Promise used to return the accessibility application list.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

let abilityType: accessibility.AbilityType = 'spoken';
let abilityState: accessibility.AbilityState = 'enable';

accessibility.getAbilityLists(abilityType, abilityState).then((data: accessibility.AccessibilityAbilityInfo[]) => {
  console.info(`Succeeded in get accessibility extension list, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get accessibility extension list because ${JSON.stringify(err)}`);
});
```

## accessibility.getAbilityLists<sup>(deprecated)</sup>

getAbilityLists(abilityType: AbilityType, stateType: AbilityState,callback: AsyncCallback&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;): void

Obtains the accessibility application list. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.
> You are advised to use [accessibility.getAccessibilityExtensionList()](#accessibilitygetaccessibilityextensionlist9-1) instead.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                      | Mandatory  | Description              |
| ----------- | ---------------------------------------- | ---- | ---------------- |
| abilityType | [AbilityType](#abilitytype)              | Yes   | Accessibility application type.        |
| stateType   | [AbilityState](#abilitystate)            | Yes   | Accessibility application status.        |
| callback    | AsyncCallback&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | Yes   | Callback used to return the accessibility application list.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

let abilityType: accessibility.AbilityType = 'spoken';
let abilityState: accessibility.AbilityState = 'enable';

accessibility.getAbilityLists(abilityType, abilityState, (err: BusinessError, data: accessibility.AccessibilityAbilityInfo[]) => {
  if (err) {
    console.error(`failed to get accessibility extension list because ${JSON.stringify(err)}`);
    return;
  }
  console.info(`Succeeded in get accessibility extension list, ${JSON.stringify(data)}`);
})
```

## accessibility.getAccessibilityExtensionList<sup>9+</sup>

getAccessibilityExtensionList(abilityType: AbilityType, stateType: AbilityState): Promise&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;

Obtains the accessibility application list. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                           | Mandatory  | Description      |
| ----------- | ----------------------------- | ---- | -------- |
| abilityType | [AbilityType](#abilitytype)   | Yes   | Accessibility application type.|
| stateType   | [AbilityState](#abilitystate) | Yes   | Accessibility application status.|

**Return value**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | Promise used to return the accessibility application list.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

let abilityType: accessibility.AbilityType = 'spoken';
let abilityState: accessibility.AbilityState = 'enable';

accessibility.getAccessibilityExtensionList(abilityType, abilityState).then((data: accessibility.AccessibilityAbilityInfo[]) => {
  console.info(`Succeeded in get accessibility extension list, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get accessibility extension list, Code is ${err.code}, message is ${err.message}`);
});
```

## accessibility.getAccessibilityExtensionList<sup>9+</sup>

getAccessibilityExtensionList(abilityType: AbilityType, stateType: AbilityState, callback: AsyncCallback&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;): void

Obtains the accessibility application list. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                      | Mandatory  | Description              |
| ----------- | ---------------------------------------- | ---- | ---------------- |
| abilityType | [AbilityType](#abilitytype)              | Yes   | Accessibility application type.        |
| stateType   | [AbilityState](#abilitystate)            | Yes   | Accessibility application status.        |
| callback    | AsyncCallback&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | Yes   | Callback used to return the accessibility application list.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

let abilityType: accessibility.AbilityType = 'spoken';
let abilityState: accessibility.AbilityState = 'enable';

accessibility.getAccessibilityExtensionList(abilityType, abilityState,(err: BusinessError, data: accessibility.AccessibilityAbilityInfo[]) => {
  if (err) {
    console.error(`failed to get accessibility extension list, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get accessibility extension list, ${JSON.stringify(data)}`);
});
```

## accessibility.getCaptionsManager<sup>8+</sup>

getCaptionsManager(): CaptionsManager

Obtains a **CaptionsManager** instance.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Return value**

| Type                                  | Description        |
| ------------------------------------ | ---------- |
| [CaptionsManager](#captionsmanager8) | Captions configuration.|

**Example**

```ts
import accessibility from '@ohos.accessibility';

let captionsManager = accessibility.getCaptionsManager();
```

## accessibility.on('accessibilityStateChange')

on(type: 'accessibilityStateChange', callback: Callback&lt;boolean&gt;): void

Enables listening for the enabled status changes of the accessibility application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Listening type, which is set to **'accessibilityStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes  | Callback used to return the result. The returned result indicates the global enabled status of the accessibility application.|

**Example**

```ts
import accessibility from '@ohos.accessibility';

accessibility.on('accessibilityStateChange', (data: boolean) => {
  console.info(`subscribe accessibility state change, result: ${JSON.stringify(data)}`);
});
```

## accessibility.on('touchGuideStateChange')

on(type: 'touchGuideStateChange', callback: Callback&lt;boolean&gt;): void

Enables listening for the enabled status changes of the touch guide mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Vision

**Parameters**

| Name     | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Listening type, which is set to **'touchGuideStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes   | Callback used to return the result.          |

**Example**

```ts
import accessibility from '@ohos.accessibility';

accessibility.on('touchGuideStateChange', (data: boolean) => {
  console.info(`subscribe touch guide state change, result: ${JSON.stringify(data)}`);
});
```

## accessibility.off('accessibilityStateChange')

off(type: 'accessibilityStateChange', callback?: Callback&lt;boolean&gt;): void

Disables listening for the enabled status changes of the accessibility application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Listening type, which is set to **'accessibilityStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No  | Callback used for disable listening. The value must be the same as the value of **callback** in **accessibility.on('accessibilityStateChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
import accessibility from '@ohos.accessibility';

accessibility.off('accessibilityStateChange', (data: boolean) => {
  console.info(`Unsubscribe accessibility state change, result: ${JSON.stringify(data)}`);
});
```

## accessibility.off('touchGuideStateChange')

off(type: 'touchGuideStateChange', callback?: Callback&lt;boolean&gt;): void

Disables listening for the enabled status changes of the touch guide mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Listening type, which is set to **'touchGuideStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No  | Callback used for disable listening. The value must be the same as the value of **callback** in **accessibility.on('touchGuideStateChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Example**

```ts
import accessibility from '@ohos.accessibility';

accessibility.off('touchGuideStateChange', (data: boolean) => {
  console.info(`Unsubscribe touch guide state change, result: ${JSON.stringify(data)}`);
});
```

## accessibility.isOpenAccessibility<sup>(deprecated)</sup>

isOpenAccessibility(): Promise&lt;boolean&gt;

Checks whether accessibility is enabled. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 10.
>
> You are advised to use [accessibility.isOpenAccessibilitySync](#accessibilityisopenaccessibilitysync10) instead.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. Returns **true** if accessibility is enabled; returns **false** otherwise.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

accessibility.isOpenAccessibility().then((data: boolean) => {
  console.info(`success data:isOpenAccessibility : ${JSON.stringify(data)}`)
}).catch((err: BusinessError) => {
  console.error(`failed to  isOpenAccessibility, Code is ${err.code}, message is ${err.message}`);
});
```

## accessibility.isOpenAccessibility<sup>(deprecated)</sup>

isOpenAccessibility(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether accessibility is enabled. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 10.
>
> You are advised to use [accessibility.isOpenAccessibilitySync](#accessibilityisopenaccessibilitysync10) instead.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description                                 |
| -------- | ---------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. Returns **true** if accessibility is enabled; returns **false** otherwise.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

accessibility.isOpenAccessibility((err: BusinessError, data: boolean) => {
  if (err) {
    console.error(`failed to isOpenAccessibility, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`success data:isOpenAccessibility : ${JSON.stringify(data)}`);
});
```

## accessibility.isOpenAccessibilitySync<sup>10+</sup>

isOpenAccessibilitySync(): boolean

Checks whether accessibility is enabled.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type       | Description                                 |
| ----------- | ------------------------------------- |
| boolean&gt; | Returns **true** if accessibility is enabled; returns **false** otherwise.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

let status: boolean = accessibility.isOpenAccessibilitySync();
```

## accessibility.isOpenTouchGuide<sup>(deprecated)</sup>

isOpenTouchGuide(): Promise&lt;boolean&gt;

Checks whether touch guide mode is enabled. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 10.
>
> You are advised to use [accessibility.isOpenTouchGuideSync](#accessibilityisopentouchguidesync10) instead.

**System capability**: SystemCapability.BarrierFree.Accessibility.Vision

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. Returns **true** if touch guide mode is enabled; returns **false** otherwise.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

accessibility.isOpenTouchGuide().then((data: boolean) => {
  console.info(`success data:isOpenTouchGuide : ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to  isOpenTouchGuide, Code is ${err.code}, message is ${err.message}`);
});
```

## accessibility.isOpenTouchGuide<sup>(deprecated)</sup>

isOpenTouchGuide(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether touch guide mode is enabled. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 10.
>
> You are advised to use [accessibility.isOpenTouchGuideSync](#accessibilityisopentouchguidesync10) instead.

**System capability**: SystemCapability.BarrierFree.Accessibility.Vision

**Parameters**

| Name     | Type                          | Mandatory  | Description                                   |
| -------- | ---------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. Returns **true** if touch guide mode is enabled; returns **false** otherwise.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

accessibility.isOpenTouchGuide((err: BusinessError, data: boolean) => {
  if (err) {
    console.error(`failed to isOpenTouchGuide, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`success data:isOpenTouchGuide : ${JSON.stringify(data)}`);
});
```

## accessibility.isOpenTouchGuideSync<sup>10+</sup>

isOpenTouchGuideSync(): boolean

Checks whether touch guide mode is enabled.

**System capability**: SystemCapability.BarrierFree.Accessibility.Vision

**Return value**

| Type   | Description                                 |
| ------- | ------------------------------------- |
| boolean | Returns **true** if touch guide mode is enabled; returns **false** otherwise.|

**Example**

```ts
import accessibility from '@ohos.accessibility';

let status: boolean = accessibility.isOpenTouchGuideSync();
```

## accessibility.sendEvent<sup>(deprecated)</sup>

sendEvent(event: EventInfo): Promise&lt;void&gt;

Sends an accessibility event. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.
> You are advised to use [accessibility.sendAccessibilityEvent()](#accessibilitysendaccessibilityevent9) instead.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                     | Mandatory  | Description      |
| ----- | ----------------------- | ---- | -------- |
| event | [EventInfo](#eventinfo) | Yes   | Accessibility event.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

let eventInfo: accessibility.EventInfo = ({
  type: 'click',
  bundleName: 'com.example.MyApplication',
  triggerAction: 'click',
});

accessibility.sendEvent(eventInfo).then(() => {
  console.info(`Succeeded in send event,eventInfo is ${eventInfo}`);
}).catch((err: BusinessError) => {
  console.error(`failed to sendEvent, Code is ${err.code}, message is ${err.message}`);
});
```

## accessibility.sendEvent<sup>(deprecated)</sup>

sendEvent(event: EventInfo, callback: AsyncCallback&lt;void&gt;): void

Sends an accessibility event. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.
> You are advised to use [accessibility.sendAccessibilityEvent()](#accessibilitysendaccessibilityevent9-1) instead.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| event    | [EventInfo](#eventinfo)   | Yes   | Accessibility event.                                 |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation fails, **err** that contains data is returned.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

let eventInfo: accessibility.EventInfo = ({
  type: 'click',
  bundleName: 'com.example.MyApplication',
  triggerAction: 'click',
});

accessibility.sendEvent(eventInfo, (err: BusinessError) => {
  if (err) {
    console.error(`failed to sendEvent, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in sendEvent, eventInfo is ${eventInfo}`);
});
```

## accessibility.sendAccessibilityEvent<sup>9+</sup>

sendAccessibilityEvent(event: EventInfo): Promise&lt;void&gt;

Sends an accessibility event. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                     | Mandatory  | Description      |
| ----- | ----------------------- | ---- | -------- |
| event | [EventInfo](#eventinfo) | Yes   | Accessibility event.|

**Return value**

| Type                 | Description              |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

let eventInfo: accessibility.EventInfo = ({
  type: 'click',
  bundleName: 'com.example.MyApplication',
  triggerAction: 'click',
});

accessibility.sendAccessibilityEvent(eventInfo).then(() => {
  console.info(`Succeeded in send event,eventInfo is ${eventInfo}`);
}).catch((err: BusinessError) => {
  console.error(`failed to send event , Code is ${err.code}, message is ${err.message}`);
});
```

## accessibility.sendAccessibilityEvent<sup>9+</sup>

sendAccessibilityEvent(event: EventInfo, callback: AsyncCallback&lt;void&gt;): void

Sends an accessibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| event    | [EventInfo](#eventinfo)   | Yes   | Accessibility event.                                 |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the operation fails, **err** that contains data is returned.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

let eventInfo: accessibility.EventInfo = ({
  type: 'click',
  bundleName: 'com.example.MyApplication',
  triggerAction: 'click',
});

accessibility.sendAccessibilityEvent(eventInfo, (err: BusinessError) => {
  if (err) {
    console.error(`failed to send event, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in send event, eventInfo is ${eventInfo}`);
});
```
