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
| ----------------------- | ------------------ |
| click                   | Clicking.           |
| longClick               | Long pressing.           |
| scrollForward           | Scrolling forward. Not supported currently.|
| scrollBackward          | Scrolling backward. Not supported currently.|
| focus                   | Obtaining focus. Not supported currently.|
| clearFocus              | Clearing focus. Not supported currently.|
| clearSelection          | Clearing selection. Not supported currently.|
| accessibilityFocus      | Obtaining the accessibility focus.      |
| clearAccessibilityFocus | Clearing the accessibility focus.      |
| cut                     | Cut. Not supported currently.  |
| copy                    | Copy. Not supported currently.  |
| paste                   | Paste. Not supported currently.  |
| select                  | Select. Not supported currently.  |
| setText                 | Setting the text. Not supported currently.|
| delete                  | Delete. Not supported currently.  |
| setSelection            | Setting the selection. Not supported currently.  |

## Capability

Enumerates the capabilities of an accessibility application.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name              | Description                   |
| ---------------- | --------------------- |
| retrieve         | Capability to retrieve the window content.         |
| touchGuide       | Capability of touch guide mode.         |
| keyEventObserver | Capability to filter key events.         |
| zoom             | Capability to control the display zoom level. Not supported currently.|
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

### on('enableChange')

on(type: 'enableChange', callback: Callback&lt;boolean&gt;): void;

Enables listening for the enabled status changes of captions configuration. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name     | Type                     | Mandatory  | Description                                     |
| -------- | ----------------------- | ---- | --------------------------------------- |
| type     | string                  | Yes   | Type of the event to listen for, which is set to **'enableChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes   | Callback invoked when the enabled status of captions configuration changes.             |

**Example**

```ts
import accessibility from '@ohos.accessibility';

let captionsManager = accessibility.getCaptionsManager();
try {
    captionsManager.on('enableChange', (data: boolean) => {
        console.info('subscribe caption manager enable state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to subscribe caption manager enable state change, because ' + JSON.stringify(exception));
}
```

### on('styleChange')

on(type: 'styleChange', callback: Callback&lt;CaptionsStyle&gt;): void;

Enables listening for captions style changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| type     | string                                   | Yes   | Type of the event to listen for, which is set to **'styleChange'** in this API.|
| callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | Yes   | Callback invoked when the style of captions changes.           |

**Example**

```ts
import accessibility from '@ohos.accessibility';

let captionStyle: accessibility.CaptionsStyle;
let captionsManager = accessibility.getCaptionsManager();
try {
    captionsManager.on('styleChange', (data: accessibility.CaptionsStyle) => {
        captionStyle = data;
        console.info('subscribe caption manager style state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to subscribe caption manager style state change, because ' + JSON.stringify(exception));
}
```

### off('enableChange')

off(type: 'enableChange', callback?: Callback&lt;boolean&gt;): void;

Disables listening for the enabled status changes of captions configuration. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name     | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Type of the event to listen for, which is set to **'enableChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No   | Callback for the event.          |

**Example**

```ts
import accessibility from '@ohos.accessibility';

let captionsManager = accessibility.getCaptionsManager();
try {
    captionsManager.off('enableChange', (data: boolean) => {
        console.info('Unsubscribe caption manager enable state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to Unsubscribe caption manager enable state change, because ' + JSON.stringify(exception));
}
```

### off('styleChange')

off(type: 'styleChange', callback?: Callback&lt;CaptionsStyle&gt;): void;

Disables listening for captions style changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| type     | string                                   | Yes   | Type of the event to listen for, which is set to **'styleChange'** in this API.|
| callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | No   | Callback for the event.             |

**Example**

```ts
import accessibility from '@ohos.accessibility';

let captionStyle: accessibility.CaptionsStyle;
let captionsManager = accessibility.getCaptionsManager();
try {
    captionsManager.off('styleChange', (data: accessibility.CaptionsStyle) => {
        captionStyle = data;
        console.info('Unsubscribe caption manager style state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to Unsubscribe caption manager style state change, because ' + JSON.stringify(exception));
}
```

## EventInfo

Describes a GUI change event.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Attributes

| Name              | Type                                   | Readable  | Writable  | Description                   |
| ---------------- | ------------------------------------- | ---- | ---- | --------------------- |
| type             | [EventType](#eventtype)               | Yes   | Yes   | Accessibility event type.             |
| windowUpdateType | [WindowUpdateType](#windowupdatetype) | Yes   | Yes   | Window update type.              |
| bundleName       | string                                | Yes   | Yes   | Target application name.               |
| componentType    | string                                | Yes   | Yes   | Type of the event source component, for example, button or chart.      |
| pageId           | number                                | Yes   | Yes   | Page ID of the event source.           |
| description      | string                                | Yes   | Yes   | Event description. Not supported currently.       |
| triggerAction    | [Action](#action)                     | Yes   | Yes   | Action that triggers the event.        |
| textMoveUnit     | [TextMoveUnit](#textmoveunit)         | Yes   | Yes   | Text movement unit. Not supported currently.     |
| contents         | Array&lt;string&gt;                   | Yes   | Yes   | Array of contents.                |
| lastContent      | string                                | Yes   | Yes   | Latest content.                |
| beginIndex       | number                                | Yes   | Yes   | Sequence number of the first item displayed on the page. Not supported currently.|
| currentIndex     | number                                | Yes   | Yes   | Sequence number of the current item. Not supported currently.     |
| endIndex         | number                                | Yes   | Yes   | Sequence number of the last item displayed on the page. Not supported currently.|
| itemCount        | number                                | Yes   | Yes   | Total number of items. Not supported currently.       |

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
    triggerAction: 'click'
  });
  ```

## EventType

Enumerates accessibility event types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name                     | Description                    |
| ----------------------- | ---------------------- |
| click                   | Event of clicking a component.            |
| longClick               | Event of long-pressing a component.            |
| select                  | Event of selecting a component. Not supported currently.   |
| focus                   | Event indicating that the component obtains the focus. Not supported currently. |
| textUpdate              | Event indicating that the component text has been updated. Not supported currently.|
| hoverEnter              | Event indicating that the hover enters a component. Not supported currently. |
| hoverExit               | Event indicating that the hover exits a component. Not supported currently. |
| scroll                  | Event of the scroll view. Not supported currently.   |
| textSelectionUpdate     | Event indicating that the selected text has been updated. Not supported currently.|
| accessibilityFocus      | Event indicating that the accessibility focus has been obtained.         |
| accessibilityFocusClear | Event indicating that the accessibility focus has been cleared.         |

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
> You are advised to use[getAccessibilityExtensionList()](#accessibilitygetaccessibilityextensionlist9).

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

let abilityType : accessibility.AbilityType = 'spoken';
let abilityState : accessibility.AbilityState = 'enable';
let abilityList: accessibility.AccessibilityAbilityInfo[];
try {
  accessibility.getAbilityLists(abilityType, abilityState)
    .then((data: accessibility.AccessibilityAbilityInfo[]) => {
      for (let item of data) {
        console.info(item.id);
        console.info(item.name);
        console.info(item.description);
        console.info(item.bundleName);
        abilityList.push(item);
      }
      console.info('get accessibility extension list success');
    })
    .catch((err: object) => {
      console.error('failed to get accessibility extension list because ' + JSON.stringify(err));
    });
} catch (exception) {
  console.error('failed to get accessibility extension list because ' + JSON.stringify(exception));
}
```

## accessibility.getAbilityLists<sup>(deprecated)</sup>

getAbilityLists(abilityType: AbilityType, stateType: AbilityState,callback: AsyncCallback&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;): void

Obtains the accessibility application list. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.
> You are advised to use [getAccessibilityExtensionList()](#accessibilitygetaccessibilityextensionlist9-1).

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

let abilityType : accessibility.AbilityType = 'spoken';
let abilityState : accessibility.AbilityState = 'enable';
let abilityList: accessibility.AccessibilityInfo[];
try {
    accessibility.getAbilityLists(abilityType, abilityState, 
    (err: BusinessError<void>, data: accessibility.AccessibilityAbilityInfo[]) => {
        if (err) {
            console.error('failed to get accessibility extension list because ' + JSON.stringify(err));
            return;
        }
        for (let item of data) {
            console.info(item.id);
            console.info(item.name);
            console.info(item.description);
            console.info(item.bundleName);
            abilityList.push(item);
        }
        console.info('get accessibility extension list success');
    })
} catch (exception) {
    console.error('failed to get accessibility extension list because ' + JSON.stringify(exception));
}
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

let abilityType : accessibility.AbilityType = 'spoken';
let abilityState : accessibility.AbilityState = 'enable';
let extensionList: accessibility.AccessibilityAbilityInfo[] = [];
try {
    accessibility.getAccessibilityExtensionList(abilityType, abilityState)
    .then((data: accessibility.AccessibilityAbilityInfo[]) => {
        for (let item of data) {
            console.info(item.id);
            console.info(item.name);
            console.info(item.description);
            console.info(item.bundleName);
            extensionList.push(item);
        }
        console.info('get accessibility extension list success');
    })
    .catch((err: object) => {
        console.error('failed to get accessibility extension list because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to get accessibility extension list because ' + JSON.stringify(exception));
}
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

let abilityType : accessibility.AbilityType = 'spoken';
let abilityState : accessibility.AbilityState = 'enable';
let extensionList: accessibility.AccessibilityAbilityInfo[] = [];
try {
    accessibility.getAccessibilityExtensionList(abilityType, abilityState, 
    (err: BusinessError<void>, data: accessibility.AccessibilityAbilityInfo[]) => {
        if (err) {
            console.error('failed to get accessibility extension list because ' + JSON.stringify(err));
            return;
        }
        for (let item of data) {
            console.info(item.id);
            console.info(item.name);
            console.info(item.description);
            console.info(item.bundleName);
            extensionList.push(item);
        }
        console.info('get accessibility extension list success');
    });
} catch (exception) {
    console.error('failed to get accessibility extension list because ' + JSON.stringify(exception));
}
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

| Name     | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Type of the event to listen for, which is set to **'accessibilityStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes   | Callback used to return the result.          |

**Example**

```ts
import accessibility from '@ohos.accessibility';

try {
    accessibility.on('accessibilityStateChange', (data: boolean) => {
        console.info('subscribe accessibility state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to subscribe accessibility state change, because ' + JSON.stringify(exception));
}
```

## accessibility.on('touchGuideStateChange')

on(type: 'touchGuideStateChange', callback: Callback&lt;boolean&gt;): void

Enables listening for the enabled status changes of the touch guide mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Vision

**Parameters**

| Name     | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Type of the event to listen for, which is set to **'touchGuideStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes   | Callback used to return the result.          |

**Example**

```ts
import accessibility from '@ohos.accessibility';

try {
    accessibility.on('touchGuideStateChange', (data: boolean) => {
        console.info('subscribe touch guide state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to subscribe touch guide state change, because ' + JSON.stringify(exception));
}
```

## accessibility.off('accessibilityStateChange')

off(type: 'accessibilityStateChange', callback?: Callback&lt;boolean&gt;): void

Disables listening for the enabled status changes of the accessibility application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Type of the event to listen for, which is set to **'accessibilityStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No   | Callback for the event.          |

**Example**

```ts
import accessibility from '@ohos.accessibility';

try {
    accessibility.off('accessibilityStateChange', (data: boolean) => {
        console.info('Unsubscribe accessibility state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to Unsubscribe accessibility state change, because ' + JSON.stringify(exception));
}
```

## accessibility.off('touchGuideStateChange')

off(type: 'touchGuideStateChange', callback?: Callback&lt;boolean&gt;): void

Disables listening for the enabled status changes of the touch guide mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Type of the event to listen for, which is set to **'touchGuideStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No   | Callback for the event.          |

**Example**

```ts
import accessibility from '@ohos.accessibility';

try {
    accessibility.off('touchGuideStateChange', (data: boolean) => {
        console.info('Unsubscribe touch guide state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to Unsubscribe touch guide state change, because ' + JSON.stringify(exception));
}
```

## accessibility.isOpenAccessibility

isOpenAccessibility(): Promise&lt;boolean&gt;

Checks whether accessibility is enabled. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. Returns **true** if accessibility is enabled; returns **false** otherwise.|

**Example**

```ts
import accessibility from '@ohos.accessibility';

accessibility.isOpenAccessibility().then((data: boolean) => {
    console.info('success data:isOpenAccessibility : ' + JSON.stringify(data))
}).catch((err: object) => {
    console.error('failed to  isOpenAccessibility because ' + JSON.stringify(err));
});
```

## accessibility.isOpenAccessibility

isOpenAccessibility(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether accessibility is enabled. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description                                 |
| -------- | ---------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. Returns **true** if accessibility is enabled; returns **false** otherwise.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

accessibility.isOpenAccessibility((err: BusinessError<void>, data: boolean) => {
    if (err) {
        console.error('failed to isOpenAccessibility because ' + JSON.stringify(err));
        return;
    }
    console.info('success data:isOpenAccessibility : ' + JSON.stringify(data))
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

try {
    let status: boolean = accessibility.isOpenAccessibilitySync();
} catch (exception) {
    console.error('failed to isOpenAccessibilitySync because ' + JSON.stringify(exception));
}
```

## accessibility.isOpenTouchGuide<sup>(deprecated)</sup>

isOpenTouchGuide(): Promise&lt;boolean&gt;

Checks whether touch guide mode is enabled. This API uses a promise to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Vision

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. Returns **true** if touch guide mode is enabled; returns **false** otherwise.|

**Example**

```ts
import accessibility from '@ohos.accessibility';

accessibility.isOpenTouchGuide().then((data: boolean) => {
    console.info('success data:isOpenTouchGuide : ' + JSON.stringify(data))
}).catch((err: object) => {
    console.error('failed to  isOpenTouchGuide because ' + JSON.stringify(err));
});
```

## accessibility.isOpenTouchGuide

isOpenTouchGuide(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether touch guide mode is enabled. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Vision

**Parameters**

| Name     | Type                          | Mandatory  | Description                                   |
| -------- | ---------------------------- | ---- | ------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. Returns **true** if touch guide mode is enabled; returns **false** otherwise.|

**Example**

```ts
import accessibility from '@ohos.accessibility';
import { BusinessError } from '@ohos.base';

accessibility.isOpenTouchGuide((err: BusinessError<void>, data: boolean) => {
    if (err) {
        console.error('failed to isOpenTouchGuide because ' + JSON.stringify(err));
        return;
    }
    console.info('success data:isOpenTouchGuide : ' + JSON.stringify(data))
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
import { BusinessError } from '@ohos.base';

try {
    let status: boolean = accessibility.isOpenTouchGuideSync();
} catch (exception) {
    console.error('failed to isOpenTouchGuideSync because ' + JSON.stringify(exception));
}
```

## accessibility.sendEvent<sup>(deprecated)</sup>

sendEvent(event: EventInfo): Promise&lt;void&gt;

Sends an accessibility event. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.
> You are advised to use **[sendAccessibilityEvent()](#accessibilitysendaccessibilityevent9)**.

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

let eventInfo: accessibility.EventInfo = ({
  type: 'click',
  bundleName: 'com.example.MyApplication',
  triggerAction: 'click'
});
accessibility.sendEvent(eventInfo).then(() => {
    console.info('send event success');
}).catch((err: object) => {
    console.error('failed to sendEvent because ' + JSON.stringify(err));
});
```

## accessibility.sendEvent<sup>(deprecated)</sup>

sendEvent(event: EventInfo, callback: AsyncCallback&lt;void&gt;): void

Sends an accessibility event. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9.
> You are advised to use **[sendAccessibilityEvent()](#accessibilitysendaccessibilityevent9-1)**.

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
  triggerAction: 'click'
});
accessibility.sendEvent(eventInfo, (err: BusinessError<void>) => {
    if (err) {
        console.error('failed to sendEvent because ' + JSON.stringify(err));
        return;
    }
    console.info('sendEvent success');
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

let eventInfo: accessibility.EventInfo = ({
  type: 'click',
  bundleName: 'com.example.MyApplication',
  triggerAction: 'click'
});
try {
    accessibility.sendAccessibilityEvent(eventInfo).then(() => {
        console.info('send event success');
    }).catch((err: object) => {
        console.error('failed to send event because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to send event because ' + JSON.stringify(exception));
}
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
  triggerAction: 'click'
});
try {
    accessibility.sendAccessibilityEvent(eventInfo, (err: BusinessError<void>) => {
        if (err) {
            console.error('failed to send event because ' + JSON.stringify(err));
            return;
        }
        console.info('send event success');
    });
} catch (exception) {
    console.error('failed to send event because ' + JSON.stringify(exception));
}
```
