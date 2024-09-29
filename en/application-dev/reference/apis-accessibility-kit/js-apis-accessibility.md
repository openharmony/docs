# @ohos.accessibility (Accessibility)

The **Accessibility** module implements the accessibility functions, including obtaining the accessibility application list, accessibility application enabled status, and captions configuration.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { accessibility } from '@kit.AccessibilityKit';
```

## AbilityState

type AbilityState = 'enable' | 'disable' | 'install'

Enumerates the states of an accessibility application.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type     | Description      |
| ------- | -------- |
| 'enable'  | The accessibility application is enabled.|
| 'disable'  | The accessibility application is disabled.|
| 'install'  | The accessibility application has been installed.|

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
| needHide<sup>12+</sup>                     | boolean     | Yes   | No   | Whether the auxiliary application is hidden in the list of installed extended services. The value **true** means the auxiliary application is hidden, and the value **false** means the opposite. |
| label<sup>12+</sup>                     | string     | Yes   | No   | Name of the application in the extended service list. |

## Action

type Action = 'accessibilityFocus' | 'clearAccessibilityFocus' | 'focus' | 'clearFocus' | 'clearSelection' |
  'click' | 'longClick' | 'cut' | 'copy' | 'paste' | 'select' | 'setText' | 'delete' |
  'scrollForward' | 'scrollBackward' | 'setSelection' | 'setCursorPosition' | 'home' |
  'back' | 'recentTask' | 'notificationCenter' | 'controlCenter' | 'common'

Target actions supported by the application. The target actions for which parameters need to be set have been specified in the description of the following table.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type                     | Description                |
| ----------------------- |--------------------|
| 'click'                   | Clicking.           |
| 'longClick'               | Long pressing.           |
| 'scrollForward'           | Scrolling forward.|
| 'scrollBackward'          | Scrolling backward.|
| 'focus'                   | Obtaining the focus.|
| 'clearFocus'              | Clearing focus.|
| 'clearSelection'          | Clearing selection. Not supported yet.|
| 'accessibilityFocus'      | Obtaining the accessibility focus.      |
| 'clearAccessibilityFocus'      | Clearing the accessibility focus.      |
| 'cut'                     | Cut.  |
| 'copy'                    | Copy.  |
| 'paste'                   | Paste.  |
| 'select'                  | Select.  |
| 'setCursorPosition'                 | Set text. You need to set the **setText** parameter.|
| 'delete'                  | Delete. Not supported yet.  |
| 'setSelection'            | Select. You need to set the **selectTextBegin**, **selectTextEnd** and **selectTextInForWard** parameters.  |
| 'common'            | Common actions used in auto-focusing and auto-broadcasting.  |
| 'home'                | Return to the home screen.  |
| 'back'                | Return to the previous screen.  |
| 'recentTask'          | Open a recent task.  |
| 'notificationCenter'      | Open the notification bar.  |
| 'controlCenter'       | Open the control center.  |
| 'setCursorPosition'     | Set cursor location. You need to set the **offset** parameter.  |

## Capability

type Capability = 'retrieve' | 'touchGuide' | 'keyEventObserver' | 'zoom' | 'gesture'

Enumerates the capabilities of an accessibility application.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type              | Description                   |
| ---------------- |-----------------------|
| 'retrieve'         | Capability to retrieve the window content.         |
| 'touchGuide'       | Capability of touch guide mode.         |
| 'keyEventObserver' | Capability to filter key events.         |
| 'zoom'             | Capability to control the display zoom level. Not supported currently.|
| 'gesture'          | Capability to perform gesture actions.         |

## CaptionsFontEdgeType<sup>8+</sup>

type CaptionsFontEdgeType = 'none' | 'raised' | 'depressed' | 'uniform' | 'dropShadow'

Enumerates the font edge types of captions.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

| Type        | Description   |
| ---------- | ----- |
| 'none'       | No effect. |
| 'raised'     | Raised effect.|
| 'depressed'  | Depressed effect.|
| 'uniform'    | Uniform effect.|
| 'dropShadow' | Drop shadow effect.|

## CaptionsFontFamily<sup>8+</sup>

type CaptionsFontFamily = 'default' | 'monospacedSerif' | 'serif' | 'monospacedSansSerif' |
  'sansSerif' | 'casual' | 'cursive' | 'smallCapitals'

Enumerates the font families of captions.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

| Name                 | Description               |
| ------------------- | ----------------- |
| 'default'             | Default font family.            |
| 'monospacedSerif'         | Monospaced Serif fonts, which use the same width for each character.     |
| 'serif'               | Serif fonts.        |
| 'monospacedSansSerif'        | Monospaced Sans Serif fonts, which use the same width for each character.|
| 'sansSerif'           | Sans Serif fonts.   |
| 'casual'              | Casual fonts.           |
| 'cursive'             | Cursive fonts.            |
| 'smallCapitals'       | Small caps fonts.        |

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

Implements configuration management for captions. Before calling any API of **CaptionsManager**, you must use the [accessibility.getCaptionsManager()](#accessibilitygetcaptionsmanagerdeprecated) API to obtain a **CaptionsManager** instance.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

### Attributes

| Name     | Type                              | Readable  | Writable  | Description         |
| ------- | -------------------------------- | ---- | ---- | ----------- |
| enabled | boolean                          | Yes   | No   | Whether to enable captions configuration.|
| style   | [CaptionsStyle](#captionsstyle8) | Yes   | No   | Style of captions.    |

For a boolean return value, **True** means that the feature is enabled, and **False** means the opposite.

### on('enableChange')<sup>(deprecated)</sup>

on(type: 'enableChange', callback: Callback&lt;boolean&gt;): void;

Enables listening for the enabled status changes of captions configuration. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name     | Type                     | Mandatory  | Description                                     |
| -------- | ----------------------- | ---- | --------------------------------------- |
| type     | string                  | Yes   | Listening type, which is set to **'enableChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes   | Callback invoked when the enabled status of captions configuration changes.             |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

let captionsManager = accessibility.getCaptionsManager();
captionsManager.on('enableChange', (data: boolean) => {
  console.info(`subscribe caption manager enable state change, result: ${JSON.stringify(data)}`);
})
```

### on('styleChange')<sup>(deprecated)</sup>

on(type: 'styleChange', callback: Callback&lt;CaptionsStyle&gt;): void;

Enables listening for captions style changes. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| type     | string                                   | Yes   | Listening type, which is set to **'styleChange'** in this API.|
| callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | Yes   | Callback invoked when the style of captions changes.           |

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

let captionsManager = accessibility.getCaptionsManager();

captionsManager.on('styleChange', (data: accessibility.CaptionsStyle) => {
  console.info(`subscribe caption manager style state change, result: ${JSON.stringify(data)}`);
});
```

### off('enableChange')<sup>(deprecated)</sup>

off(type: 'enableChange', callback?: Callback&lt;boolean&gt;): void;

Disables listening for the enabled status changes of captions configuration. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Listening type, which is set to **'enableChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No  | Callback used for disable listening. The value must be the same as the value of **callback** in **on('enableChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

let captionsManager = accessibility.getCaptionsManager();

captionsManager.off('enableChange', (data: boolean) => {
  console.info(`Unsubscribe caption manager enable state change, result: ${JSON.stringify(data)}`);
});
```

### off('styleChange')<sup>(deprecated)</sup>

off(type: 'styleChange', callback?: Callback&lt;CaptionsStyle&gt;): void;

Disables listening for captions style changes. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name  | Type                                            | Mandatory| Description                                                        |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                           | Yes  | Listening type, which is set to **'styleChange'** in this API. |
| callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | No  | Callback used for disable listening. The value must be the same as the value of **callback** in **on('styleChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

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
| description      | string                                | No  | Event description.       |
| triggerAction    | [Action](#action)                     | Yes  | Action that triggers the event.   |
| textMoveUnit     | [TextMoveUnit](#textmoveunit)         | No  | Text move granularity.     |
| contents         | Array&lt;string&gt;                   | No  | Array of contents.                |
| lastContent      | string                                | No  | Latest content.                |
| beginIndex       | number                                | No  | Sequence number of the first item displayed on the page.|
| currentIndex     | number                                | No  | Sequence number of the current item.     |
| endIndex         | number                                | No  | Sequence number of the last item displayed on the page.|
| itemCount        | number                                | No  | Total number of records.       |
| elementId<sup>12+</sup>        | number                                | No  | Element ID of the component.       |
| textAnnouncedForAccessibility<sup>12+</sup>        | string                                | No  | Content for auto-broadcasting.       |
| customId<sup>12+</sup>        | string                                | No  | Component ID for auto-focusing.       |

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
  import { accessibility } from '@kit.AccessibilityKit';

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
  import { accessibility } from '@kit.AccessibilityKit';

  let eventInfo = new accessibility.EventInfo('click', 'com.example.MyApplication', 'click');
  ```

## EventType

type EventType = 'accessibilityFocus' | 'accessibilityFocusClear' |
'click' | 'longClick' | 'focus' | 'select' | 'hoverEnter' | 'hoverExit' |
'textUpdate' | 'textSelectionUpdate' | 'scroll' | 'requestFocusForAccessibility' |
'announceForAccessibility'

Enumerates accessibility event types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type                     | Description                    |
| ----------------------- |------------------------|
| 'accessibilityFocus'      | Represents an event indicating that the accessibility focus is obtained.         |
| 'accessibilityFocusClear' | Represents an event indicating that the accessibility focus is cleared.         |
| 'click'                   | Event of clicking a component.            |
| 'longClick'               | Represents an event indicating that the component is long pressed.            |
| 'select'                  | Event of selecting a component.   |
| 'hoverEnter'              | Event indicating that the hover enters a component. |
| 'hoverExit'               | Event indicating that the hover exits a component. |
| 'focus'                   | Event indicating that the component obtains the focus. Not supported currently. |
| 'textUpdate'              | Event indicating that the component text has been updated.|
| 'textSelectionUpdate'     | Event indicating that the selected text has been updated. Not supported currently.|
| 'scroll'                  | Event of the scroll view.   |
| 'requestFocusForAccessibility'     | Event of the auto-focusing.|
| 'announceForAccessibility'         | Event of the auto-broadcasting.|


## TextMoveUnit

type TextMoveUnit = 'char' | 'word' | 'line' | 'page' | 'paragraph'

Enumerates the movement units for traversing the node text.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type       | Description             |
| --------- | --------------- |
| 'char'      | The movement unit for traversing the node text is by character.|
| 'word'      | The movement unit for traversing the node text is by word. |
| 'line'      | The movement unit for traversing the node text is by line. |
| 'page'      | The movement unit for traversing the node text is by page. |
| 'paragraph' | The movement unit for traversing the node text is by paragraph.|

## WindowUpdateType

type WindowUpdateType = 'add' | 'remove' | 'bounds' | 'active' | 'focus'

Enumerates window update types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type    | Description                |
| ------ | ------------------ |
| 'add'    | Window adding.      |
| 'remove' | Window deletion.   |
| 'bounds' | Window boundary change.   |
| 'active' | Window activity change.|
| 'focus'  | Window focus change.  |

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
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

## accessibility.getAccessibilityExtensionListSync<sup>12+</sup>

getAccessibilityExtensionListSync(abilityType: AbilityType, stateType: AbilityState): Array&lt;AccessibilityAbilityInfo&gt;

Obtains the API for synchronizing the accessibility application list.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                           | Mandatory  | Description      |
| ----------- | ----------------------------- | ---- | -------- |
| abilityType | [AbilityType](#abilitytype)   | Yes   | Accessibility application type.|
| stateType   | [AbilityState](#abilitystate) | Yes   | Accessibility application status.|

**Return value**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt; | Promise used to return the accessibility application list.|

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityType: accessibility.AbilityType = 'all';
let abilityState: accessibility.AbilityState = 'install';
let data: accessibility.AccessibilityAbilityInfo[];

try {
  data = accessibility.getAccessibilityExtensionListSync(abilityType, abilityState);
  console.info(`Succeeded in get accessibility extension list, ${JSON.stringify(data)}`);
} catch (error) {
  let err = error as BusinessError;
  console.error(`error code: ${err.code}`);
}
```

## accessibility.getCaptionsManager<sup>(deprecated)</sup>

getCaptionsManager(): CaptionsManager

Obtains a **CaptionsManager** instance.

> **NOTE**
>
> This API is deprecated since API version 12.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Return value**

| Type                                  | Description        |
| ------------------------------------ | ---------- |
| [CaptionsManager](#captionsmanager8) | Captions configuration.|

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

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
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type       | Description                                 |
| ----------- | ------------------------------------- |
| boolean | Returns **true** if accessibility is enabled; returns **false** otherwise.|

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BarrierFree.Accessibility.Vision

**Return value**

| Type   | Description                                 |
| ------- | ------------------------------------- |
| boolean | Returns **true** if accessibility is enabled; returns **false** otherwise.|

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

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
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Error codes**

For details about the error codes, see [Accessibility Error Codes](errorcode-accessibility.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Input parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Example of auto-focusing:**

```ts
@Entry
@Component
struct Index {

  build() {
    Column() {
      // Add the ID attribute to the component to be focused. The uniqueness of the ID is ensured by the user.
      Button ('Component to be focused').id ('click')
    }
  }
}
```
```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let eventInfo: accessibility.EventInfo = ({
  type: 'requestFocusForAccessibility',
  bundleName: 'com.example.MyApplication',
  triggerAction: 'common',
  customId: 'click' // ID of the component to be focused.
});

accessibility.sendAccessibilityEvent(eventInfo, (err: BusinessError) => {
  if (err) {
    console.error(`failed to send event, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in send event, eventInfo is ${eventInfo}`);
});
```
