# @ohos.accessibility (Accessibility)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

The **Accessibility** module implements the accessibility features, including obtaining the accessibility application list, accessibility application enabling state, and captions configuration.

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

### Properties

| Name                            | Type                                      | Read-Only  | Optional  | Description              |
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
| 'cut'                     | Cutting.  |
| 'copy'                    | Copying.  |
| 'paste'                   | Pasting.  |
| 'select'                  | Selecting.  |
| 'setText'                 | Setting text. You need to set the **setText** parameter.|
| 'delete'                  | Delete. Not supported yet.  |
| 'setSelection'            | Selecting. You need to set the **selectTextBegin**, **selectTextEnd** and **selectTextInForWard** parameters.  |
| 'common'            | Common actions used in auto-focusing and auto-broadcasting.  |
| 'home'                | Returning to the home screen.  |
| 'back'                | Returning to the previous screen.  |
| 'recentTask'          | Opening a recent task.  |
| 'notificationCenter'      | Opening the notification bar.  |
| 'controlCenter'       | Opening the control center.  |
| 'setCursorPosition'     | Setting cursor location. You need to set the **offset** parameter.  |

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

| Type                 | Description               |
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

| Name             | Type                                   | Read-Only  | Optional  | Description         |
| --------------- | ---------------------------------------- | ---- | ---- | ----------- |
| fontFamily      | [CaptionsFontFamily](#captionsfontfamily8) | No   | No   | Font family of captions.    |
| fontScale       | number                                   | No   | No   | Font scale factor of captions, in percentage. The value ranges from 1 to 200.|
| fontColor       | number \| string                         | No   | No   | Font color of captions.<br>**number**: HEX format, used to represent colors defined in either the RGB or ARGB color models.<br>**string**: #rrggbb, #rrggbbaa, #rgb, or #rgba format.<br>Example: opaque red; number: 0xffff0000; string: '#ff0000', '#ff0000ff', '#f00', or '#f00f'|
| fontEdgeType    | [CaptionsFontEdgeType](#captionsfontedgetype8) | No   | No   | Font edge type of captions.  |
| backgroundColor | number \| string                         | No   | No   | Background color of captions.<br>**number**: HEX format, used to represent colors defined in either the RGB or ARGB color models.<br>**string**: #rrggbb, #rrggbbaa, #rgb, or #rgba format.<br>Example: opaque red; number: 0xffff0000; string: '#ff0000', '#ff0000ff', '#f00', or '#f00f'  |
| windowColor     | number \| string                         | No   | No   | Window color of captions.<br>**number**: HEX format, used to represent colors defined in either the RGB or ARGB color models.<br>**string**: #rrggbb, #rrggbbaa, #rgb, or #rgba format.<br>Example: opaque red; number: 0xffff0000; string: '#ff0000', '#ff0000ff', '#f00', or '#f00f'  |

## CaptionsManager<sup>8+</sup>

Implements configuration management for captions. Before calling any API of **CaptionsManager**, you must use the [accessibility.getCaptionsManager()](#accessibilitygetcaptionsmanagerdeprecated) API to obtain a **CaptionsManager** instance.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

### Properties

| Name     | Type                              | Read-Only  | Optional  | Description         |
| ------- | -------------------------------- | ---- | ---- | ----------- |
| enabled | boolean                          | No   | No   | Whether to enable captions configuration. The value **true** indicates that the caption configuration is enabled, and **false** indicates the opposite.|
| style   | [CaptionsStyle](#captionsstyle8) | No   | No   | Style of captions.    |

### on('enableChange')<sup>(deprecated)</sup>

on(type: 'enableChange', callback: Callback&lt;boolean&gt;): void;

Subscribes to the enabling state changes of captions configuration. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12. Related features are no longer available in the system.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name     | Type                     | Mandatory  | Description                                     |
| -------- | ----------------------- | ---- | --------------------------------------- |
| type     | string                  | Yes   | Event type, which is set to **'enableChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes   | Callback invoked when the enabled status of captions configuration changes.             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

@Entry
@Component
struct Index {
  callback: (data: boolean) => void = this.eventCallback;
  eventCallback(data: boolean): void {
    console.info(`subscribe caption manager enable state change, result: ${JSON.stringify(data)}`);
  }

  aboutToAppear(): void {
    let captionsManager = accessibility.getCaptionsManager();
    captionsManager.on('enableChange', this.callback);
  }

  build() {
    Column() {
    }
  }
}
```

### on('styleChange')<sup>(deprecated)</sup>

on(type: 'styleChange', callback: Callback&lt;CaptionsStyle&gt;): void;

Subscribes to captions style changes. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12. Related features are no longer available in the system.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                |
| -------- | ---------------------------------------- | ---- | ---------------------------------- |
| type     | string                                   | Yes   | Event type, which is set to **'styleChange'** in this API.|
| callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | Yes   | Callback invoked when the style of captions changes.           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

@Entry
@Component
struct Index {
  callback: (data: accessibility.CaptionsStyle) => void = this.eventCallback;
  eventCallback(data: accessibility.CaptionsStyle): void {
    console.info(`subscribe caption manager style state change, result: ${JSON.stringify(data)}`);
  }

  aboutToAppear(): void {
    let captionsManager = accessibility.getCaptionsManager();
    captionsManager.on('styleChange', this.callback);
  }

  build() {
    Column() {
    }
  }
}
```

### off('enableChange')<sup>(deprecated)</sup>

off(type: 'enableChange', callback?: Callback&lt;boolean&gt;): void;

Unsubscribes from the enabling state changes of captions configuration. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12. Related features are no longer available in the system.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Event type, which is set to **'enableChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No  | Callback used to unregister. The value must be the same as the value of **callback** in **on('enableChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

@Entry
@Component
struct Index {
  callback: (data: boolean) => void = this.eventCallback;
  eventCallback(data: boolean): void {
    console.info(`subscribe caption manager enable state change, result: ${JSON.stringify(data)}`);
  }

  aboutToAppear(): void {
    let captionsManager = accessibility.getCaptionsManager();
    captionsManager.on('enableChange', this.callback);
  }

  aboutToDisappear(): void {
    let captionsManager = accessibility.getCaptionsManager();
    captionsManager.off('enableChange', this.callback);
  }

  build() {
    Column() {
    }
  }
}
```

### off('styleChange')<sup>(deprecated)</sup>

off(type: 'styleChange', callback?: Callback&lt;CaptionsStyle&gt;): void;

Unsubscribes from the captions style changes. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 12. Related features are no longer available in the system.

**System capability**: SystemCapability.BarrierFree.Accessibility.Hearing

**Parameters**

| Name  | Type                                            | Mandatory| Description                                                        |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                           | Yes  | Event type, which is set to **'styleChange'** in this API. |
| callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | No  | Callback used to unregister. The value must be the same as the value of **callback** in **on('styleChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

@Entry
@Component
struct Index {
  callback: (data: accessibility.CaptionsStyle) => void = this.eventCallback;
  eventCallback(data: accessibility.CaptionsStyle): void {
    console.info(`subscribe caption manager style state change, result: ${JSON.stringify(data)}`);
  }

  aboutToAppear(): void {
    let captionsManager = accessibility.getCaptionsManager();
    captionsManager.on('styleChange', this.callback);
  }

  aboutToDisappear(): void {
    let captionsManager = accessibility.getCaptionsManager();
    captionsManager.off('styleChange', this.callback);
  }

  build() {
    Column() {
    }
  }
}
```

## EventInfo

Describes a GUI change event.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

### Properties

| Name            | Type                                  | Read-Only| Optional| Description           |
| ---------------- | ------------------------------------- |----- |------|-----------------------|
| type             | [EventType](#eventtype)               | No  | No  | Accessibility event type (mandatory).        |
| windowUpdateType | [WindowUpdateType](#windowupdatetype) | No  | Yes  | Window update type.              |
| bundleName       | string                                | No  | No  | Name of the target application (mandatory).          |
| componentType    | string                                | No  | Yes  | Component type, for example, **Button** for the button component and **Image** for the image component.      |
| pageId           | number                                | No  | Yes  | ID of the page where the event occurs. The default value is **0**.           |
| description      | string                                | No  | Yes  | Event description. Set this parameter as required.       |
| triggerAction    | [Action](#action)                     | No  | No  | Action that triggers the event (mandatory).   |
| textMoveUnit     | [TextMoveUnit](#textmoveunit)         | No  | Yes  | Text move granularity.     |
| contents         | Array&lt;string&gt;                   | No  | Yes  | Content list. Set this parameter as required.                |
| lastContent      | string                                | No  | Yes  | Latest content. Set this parameter as required.                |
| beginIndex       | number                                | No  | Yes  | Start index. The default value is **0**.|
| currentIndex     | number                                | No  | Yes  | Current index. The default value is **0**.     |
| endIndex         | number                                | No  | Yes  | End index. The default value is **0**.|
| itemCount        | number                                | No  | Yes  | Total number of items. The default value is **0**.       |
| elementId<sup>12+</sup>        | number                  | No  | Yes  | Element ID of the component. The default value is **0**.       |
| textAnnouncedForAccessibility<sup>12+</sup>     | string     | No  | Yes  | Content for auto-broadcasting. Set the broadcast content based on the actual scenario. No special restrictions.|
| textResourceAnnouncedForAccessibility<sup>18+</sup>      | Resource   | No  | Yes  | Content for auto-broadcasting. The value is a string of the **Resource** type. |
| customId<sup>12+</sup>        | string                                | No  | Yes  | Component ID for auto-focusing.       |

### constructor

constructor(jsonObject: Object)

Implements a constructor.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name       | Type    | Mandatory  | Description                  |
| ---------- | ------ | ---- | -------------------- |
| jsonObject | Object | Yes   | JSON object that contains the **type**, **bundleName**, and **triggerAction** fields.|

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
| type | [EventType](#eventtype)          | Yes| Accessibility event types.     |
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
'announceForAccessibility' | 'requestFocusForAccessibilityNotInterrupt' |
'announceForAccessibilityNotInterrupt' | 'scrolling'

Enumerates accessibility event types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Type                     | Description                    |
| ----------------------- |------------------------|
| 'accessibilityFocus'      | Event indicating that the accessibility focus is obtained.         |
| 'accessibilityFocusClear' | Event indicating that the accessibility focus is cleared.         |
| 'click'                   | Event of clicking a component.            |
| 'longClick'               | Event indicating that the component is long pressed.            |
| 'select'                  | Event of selecting a component.   |
| 'hoverEnter'              | Event indicating that the hover enters a component. |
| 'hoverExit'               | Event indicating that the hover exits a component. |
| 'focus'                   | Event indicating that the component obtains the focus. Not supported currently. |
| 'textUpdate'              | Event indicating that the component text has been updated.|
| 'textSelectionUpdate'     | Event indicating that the selected text has been updated. Not supported currently.|
| 'scroll'                  | Event of the scroll view.   |
| 'requestFocusForAccessibility'     | Event of the auto-focusing.|
| 'announceForAccessibility'         | Event of the auto-broadcasting.|
| 'requestFocusForAccessibilityNotInterrupt'     | Event of the auto-focusing without interruption.<br>This event is supported since API version 18.|
| 'announceForAccessibilityNotInterrupt'         | Event of the auto-broadcasting without interruption.<br>This event is supported since API version 18.|
| 'scrolling'                  | Event indicating that an item is scrolled out of the screen in the scrolling view.<br>This event is supported since API version 18.|

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Parameter example**
| Accessibility Application Type/State     | enable       | disable |install|
| ------- | -------- |----|----|
| **audible**  | Queries enabled accessibility applications with audible feedback.|Queries disabled accessibility applications with audible feedback.|Queries installed accessibility applications with audible feedback.|
|**generic**| Queries enabled accessibility applications with generic feedback.|Queries disabled accessibility applications with generic feedback.|Queries installed accessibility applications with generic feedback.|
|**haptic**| Queries enabled accessibility applications with haptic feedback.|Queries disabled accessibility applications with haptic feedback.|Queries installed accessibility applications with haptic feedback.|
|**spoken**| Queries enabled accessibility applications with spoken feedback.|Queries disabled accessibility applications with spoken feedback.|Queries installed accessibility applications with spoken feedback.|
|**visual**| Queries enabled accessibility applications with visual feedback.|Queries disabled accessibility applications with visual feedback.|Queries installed accessibility applications with visual feedback.|
|**all**| Queries all enabled accessibility applications.|Queries all disabled accessibility applications.|Queries all installed accessibility applications.|

**Example of querying all installed accessibility applications**:
```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityType: accessibility.AbilityType = 'all'; // Set the accessibility application type to 'all'.
let abilityState: accessibility.AbilityState = 'install'; // Set the accessibility application state to 'install'.

accessibility.getAccessibilityExtensionList(abilityType, abilityState).then((data: accessibility.AccessibilityAbilityInfo[]) => {
  console.info(`Succeeded in get accessibility extension list, ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get accessibility extension list, Code is ${err.code}, message is ${err.message}`);
});

// For example, install an accessibility application whose bundle name is com.example.myaccessibilityapp in the system.
// The log output is as follows:
// [{"id":"com.example.myaccessibilityapp/AccessibilityExtAbility","name":"AccessibilityExtAbility",
// "bundleName":"com.example.myaccessibilityapp","abilityTypes":[],
// "capabilities":["retrieve","gesture"],"description":"$string:MainAbility_desc",
// "eventTypes":["click","longClick","select","focus","textUpdate","hoverEnter","hoverExit","scroll",
// "textSelectionUpdate","accessibilityFocus","accessibilityFocusClear","requestFocusForAccessibility",
// "announceForAccessibility","announceForAccessibilityNotInterrupt",
// "requestFocusForAccessibilityNotInterrupt","scrolling"],"targetBundleNames":[],"needHide":false}}]
```

**Example of querying all enabled accessibility applications with voice feedback**:
```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityType: accessibility.AbilityType = 'spoken'; // Set the accessibility application type to 'spoken'.
let abilityState: accessibility.AbilityState = 'enable'; // Set the accessibility application state to 'enable'.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Parameter example**
| Accessibility Application Type/State     | enable       | disable |install|
| ------- | -------- |----|----|
| **audible**  | Queries enabled accessibility applications with audible feedback.|Queries disabled accessibility applications with audible feedback.|Queries installed accessibility applications with audible feedback.|
|**generic**| Queries enabled accessibility applications with generic feedback.|Queries disabled accessibility applications with generic feedback.|Queries installed accessibility applications with generic feedback.|
|**haptic**| Queries enabled accessibility applications with haptic feedback.|Queries disabled accessibility applications with haptic feedback.|Queries installed accessibility applications with haptic feedback.|
|**spoken**| Queries enabled accessibility applications with spoken feedback.|Queries disabled accessibility applications with spoken feedback.|Queries installed accessibility applications with spoken feedback.|
|**visual**| Queries enabled accessibility applications with visual feedback.|Queries disabled accessibility applications with visual feedback.|Queries installed accessibility applications with visual feedback.|
|**all**| Queries all enabled accessibility applications.|Queries all disabled accessibility applications.|Queries all installed accessibility applications.|

**Example of querying all installed accessibility applications**:

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityType: accessibility.AbilityType = 'all'; // Set the accessibility application type to 'all'.
let abilityState: accessibility.AbilityState = 'install'; // Set the accessibility application state to 'install'.

accessibility.getAccessibilityExtensionList(abilityType, abilityState,(err: BusinessError, data: accessibility.AccessibilityAbilityInfo[]) => {
  if (err) {
    console.error(`failed to get accessibility extension list, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get accessibility extension list, ${JSON.stringify(data)}`);
});

// For example, install an accessibility application whose bundle name is com.example.myaccessibilityapp in the system.
// The log output is as follows:
// [{"id":"com.example.myaccessibilityapp/AccessibilityExtAbility","name":"AccessibilityExtAbility",
// "bundleName":"com.example.myaccessibilityapp","abilityTypes":[],
// "capabilities":["retrieve","gesture"],"description":"$string:MainAbility_desc",
// "eventTypes":["click","longClick","select","focus","textUpdate","hoverEnter","hoverExit","scroll",
// "textSelectionUpdate","accessibilityFocus","accessibilityFocusClear","requestFocusForAccessibility",
// "announceForAccessibility","announceForAccessibilityNotInterrupt",
// "requestFocusForAccessibilityNotInterrupt","scrolling"],"targetBundleNames":[],"needHide":false}}]
```

**Example of querying all enabled accessibility applications with voice feedback**:

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityType: accessibility.AbilityType = 'spoken'; // Set the accessibility application type to 'spoken'.
let abilityState: accessibility.AbilityState = 'enable'; // Set the accessibility application state to 'enable'.

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

Query the list of accessibility applications in the current system, which can be queried by criteria.

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

**Parameter example**
| Accessibility Application Type/State     | enable       | disable |install|
| ------- | -------- |----|----|
| **audible**  | Queries enabled accessibility applications with audible feedback.|Queries disabled accessibility applications with audible feedback.|Queries installed accessibility applications with audible feedback.|
|**generic**| Queries enabled accessibility applications with generic feedback.|Queries disabled accessibility applications with generic feedback.|Queries installed accessibility applications with generic feedback.|
|**haptic**| Queries enabled accessibility applications with haptic feedback.|Queries disabled accessibility applications with haptic feedback.|Queries installed accessibility applications with haptic feedback.|
|**spoken**| Queries enabled accessibility applications with spoken feedback.|Queries disabled accessibility applications with spoken feedback.|Queries installed accessibility applications with spoken feedback.|
|**visual**| Queries enabled accessibility applications with visual feedback.|Queries disabled accessibility applications with visual feedback.|Queries installed accessibility applications with visual feedback.|
|**all**| Queries all enabled accessibility applications.|Queries all disabled accessibility applications.|Queries all installed accessibility applications.|

**Example of querying all installed accessibility applications**:

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityType: accessibility.AbilityType = 'all'; // Set the accessibility application type to 'all'.
let abilityState: accessibility.AbilityState = 'install'; // Set the accessibility application state to 'install'.
let data: accessibility.AccessibilityAbilityInfo[];

try {
  data = accessibility.getAccessibilityExtensionListSync(abilityType, abilityState);
  console.info(`Succeeded in get accessibility extension list, ${JSON.stringify(data)}`);
} catch (error) {
  let err = error as BusinessError;
  console.error(`error code: ${err.code}`);
}

// For example, install an accessibility application whose bundle name is com.example.myaccessibilityapp in the system.
// The log output is as follows:
// [{"id":"com.example.myaccessibilityapp/AccessibilityExtAbility","name":"AccessibilityExtAbility",
// "bundleName":"com.example.myaccessibilityapp","abilityTypes":[],
// "capabilities":["retrieve","gesture"],"description":"$string:MainAbility_desc",
// "eventTypes":["click","longClick","select","focus","textUpdate","hoverEnter","hoverExit","scroll",
// "textSelectionUpdate","accessibilityFocus","accessibilityFocusClear","requestFocusForAccessibility",
// "announceForAccessibility","announceForAccessibilityNotInterrupt",
// "requestFocusForAccessibilityNotInterrupt","scrolling"],"targetBundleNames":[],"needHide":false}}]
```

**Example of querying all enabled accessibility applications with voice feedback**:

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let abilityType: accessibility.AbilityType = 'spoken'; // Set the accessibility application type to 'spoken'.
let abilityState: accessibility.AbilityState = 'enable'; // Set the accessibility application state to 'enable'.
let data: accessibility.AccessibilityAbilityInfo[];

try {
  data = accessibility.getAccessibilityExtensionListSync(abilityType, abilityState);
  console.info(`Succeeded in get accessibility extension list, ${JSON.stringify(data)}`);
} catch (error) {
  let err = error as BusinessError;
  console.error(`error code: ${err.code}`);
}
```

<!--RP1-->
<!--RP1End-->

## accessibility.getCaptionsManager<sup>(deprecated)</sup>

getCaptionsManager(): CaptionsManager

Obtains a **CaptionsManager** instance.

> **NOTE**
>
> This API is deprecated since API version 12. Related features are no longer available in the system.

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

Subscribes to the enabling state changes of the accessibility application. This API uses an asynchronous callback to return the result. To obtain information about accessibility applications in the system, use [accessibility.getAccessibilityExtensionListSync](#accessibilitygetaccessibilityextensionlistsync12).

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Event type, which is set to **'accessibilityStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes  | Callback invoked when the enabled status of accessibility application changes. The returned result indicates the global enabled status of the accessibility application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

// When one or more accessibility applications have been installed in the system:
// 1. After the first application is enabled, the callback returns true.
// 2. If one or more applications have been enabled and the last enabled one is disabled, the callback returns false.
accessibility.on('accessibilityStateChange', (data: boolean) => {
  console.info(`subscribe accessibility state change, result: ${JSON.stringify(data)}`);
});
```

<!--RP2-->
<!--RP2End-->

## accessibility.on('touchGuideStateChange')

on(type: 'touchGuideStateChange', callback: Callback&lt;boolean&gt;): void

Subscribes to the enabling state changes of the touch guide mode. This API uses an asynchronous callback to return the result. To obtain information about accessibility applications in the system, use [accessibility.getAccessibilityExtensionListSync](#accessibilitygetaccessibilityextensionlistsync12).

**System capability**: SystemCapability.BarrierFree.Accessibility.Vision

**Parameters**

| Name     | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Event type, which is set to **'touchGuideStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes   | Callback invoked when the enabling state of touch guide mode changes.          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

// When one or more accessibility applications with touch guide mode (**touchGuide** is set in **Capability**) have been installed in the system:
// 1. After the first application is enabled, the callback returns true.
// 2. If one or more applications have been enabled and the last enabled one is disabled, the callback returns false.
accessibility.on('touchGuideStateChange', (data: boolean) => {
  console.info(`subscribe touch guide state change, result: ${JSON.stringify(data)}`);
});
```

## accessibility.on('screenReaderStateChange')<sup>18+</sup>

on(type: 'screenReaderStateChange', callback: Callback&lt;boolean&gt;): void

Subscribes to the enabling state changes of the screen reader. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Event type, which is set to **'screenReaderStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | Yes   | Callback invoked when the enabling state of screen reader changes.          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

accessibility.on('screenReaderStateChange', (data: boolean) => {
  console.info(`subscribe screen reader state change, result: ${JSON.stringify(data)}`);
});
```

## accessibility.on('touchModeChange')<sup>20+</sup>

on(type: 'touchModeChange', callback: Callback&lt;string&gt;): void

Subscribers to the single- or double-touch event changes in touch guide mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                     | Mandatory  | Description                                      |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| type     | string                  | Yes   | Event type, which is set to **'touchModeChange'** in this API.|
| callback | Callback&lt;string&gt; | Yes   | Callback to be invoked when the single- or double-touch event changes.          |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

@Entry
@Component
struct Index {
  callback: (mode: string) => void = this.eventCallback;
  eventCallback(mode: string): void {
    console.info(`current touch mode: ${JSON.stringify(mode)}`);
  }

  aboutToAppear(): void {
    accessibility.on('touchModeChange', this.callback);
  }

  build() {
    Column() {
    }
  }
}
```

## accessibility.off('accessibilityStateChange')

off(type: 'accessibilityStateChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from the enabling state changes of the accessibility application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Event type, which is set to **'accessibilityStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No  | Callback used to unregister. The value must be the same as the value of **callback** in **accessibility.on('accessibilityStateChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

accessibility.off('accessibilityStateChange', (data: boolean) => {
  console.info(`Unsubscribe accessibility state change, result: ${JSON.stringify(data)}`);
});
```

## accessibility.off('touchGuideStateChange')

off(type: 'touchGuideStateChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from the enabling state changes of the touch guide mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Event type, which is set to **'touchGuideStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No  | Callback used to unregister. The value must be the same as the value of **callback** in **accessibility.on('touchGuideStateChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

accessibility.off('touchGuideStateChange', (data: boolean) => {
  console.info(`Unsubscribe touch guide state change, result: ${JSON.stringify(data)}`);
});
```

## accessibility.off('screenReaderStateChange')<sup>18+</sup>

off(type: 'screenReaderStateChange', callback?: Callback&lt;boolean&gt;): void

Unsubscribes from the enabling state changes of the screen reader. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Event type, which is set to **'screenReaderStateChange'** in this API.|
| callback | Callback&lt;boolean&gt; | No  | Callback used to unregister. The value must be the same as the value of **callback** in **accessibility.on('screenReaderStateChange')**. If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

accessibility.off('screenReaderStateChange', (data: boolean) => {
  console.info(`Unsubscribe screen reader state change, result: ${JSON.stringify(data)}`);
});
```

## accessibility.off('touchModeChange')<sup>20+</sup>

off(type: 'touchModeChange', callback?: Callback&lt;string&gt;): void

Unsubscribes from the single- or double-touch event changes in touch guide mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| type     | string                  | Yes  | Event type, which is set to **'touchModeChange'** in this API.|
| callback | Callback&lt;string&gt; | No  | Callback used to unregister. The callback must be the same as that of [accessibility.on('touchModeChange')](#accessibilityontouchmodechange20). If this parameter is not specified, listening will be disabled for all callbacks corresponding to the specified type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

@Entry
@Component
struct Index {
  callback: (mode: string) => void = this.eventCallback;
  eventCallback(mode: string): void {
    console.info(`current touch mode: ${JSON.stringify(mode)}`);
  }

  aboutToAppear(): void {
    accessibility.on('touchModeChange', this.callback);
  }

  aboutToDisappear(): void {
    accessibility.off('touchModeChange', this.callback);
  }

  build() {
    Column() {
    }
  }
}
```

## accessibility.isOpenAccessibility<sup>(deprecated)</sup>

isOpenAccessibility(): Promise&lt;boolean&gt;

Checks whether this accessibility application is enabled. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 10.
>
> You are advised to use [accessibility.isOpenAccessibilitySync](#accessibilityisopenaccessibilitysync10) instead.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type                    | Description                                      |
| ---------------------- | ---------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. Returns **true** if this accessibility application is enabled; returns **false** otherwise.|

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

Checks whether an accessibility application is enabled. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 10.
>
> You are advised to use [accessibility.isOpenAccessibilitySync](#accessibilityisopenaccessibilitysync10) instead.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description                                 |
| -------- | ---------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. Returns **true** if the accessibility application is enabled; returns **false** otherwise.|

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

Checks whether any accessibility application has been enabled in the system. To obtain information about accessibility applications in the system, use [accessibility.getAccessibilityExtensionListSync](#accessibilitygetaccessibilityextensionlistsync12).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**
<!--RP3-->
| Type       | Description                                 |
| ----------- | ------------------------------------- |
| boolean | Whether any accessibility application has been enabled in the system. Returns **true** if one or more accessibility applications are enabled; returns **false** otherwise.|
<!--RP3End-->

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 1. If no accessibility application is enabled, the system returns false.
// 2. If any accessibility application is enabled, the system returns true.
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
| boolean | Whether the touch guide mode is enabled. Returns **true** if the touch guide mode is enabled; returns **false** otherwise.|

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

let status: boolean = accessibility.isOpenTouchGuideSync();
```

## accessibility.isScreenReaderOpenSync<sup>18+</sup>

isScreenReaderOpenSync(): boolean

Checks whether the screen reader mode is enabled.

**System capability**: SystemCapability.BarrierFree.Accessibility.Vision

**Return value**

| Type   | Description                                 |
| ------- | ------------------------------------- |
| boolean | Whether the screen reader is enabled. Returns **true** if the screen reader is enabled; returns **false** otherwise.|

**Example**

```ts
import { accessibility } from '@kit.AccessibilityKit';

let status: boolean = accessibility.isScreenReaderOpenSync();
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401  |Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
      Button('Component to be focused').id('click')
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

**Example of resource-supported auto-broadcasting<sup>18+</sup>:**

```ts
import { accessibility } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let eventInfo: accessibility.EventInfo = ({
  type: 'announceForAccessibility',
  bundleName: 'com.example.MyApplication',
  triggerAction: 'common',
  textResourceAnnouncedForAccessibility: $r('app.string.ResourceName'),
});

accessibility.sendAccessibilityEvent(eventInfo, (err: BusinessError) => {
  if (err) {
    console.error(`failed to send event, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in send event, eventInfo is ${eventInfo}`);
});
```

## accessibility.getTouchModeSync<sup>20+</sup>

getTouchModeSync(): string

Queries the single- or double-touch mode.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Return value**

| Type       | Description                                 |
| ----------- | ------------------------------------- |
| string | Touch mode.<br>- **singleTouchMode**: single-touch mode.<br>- **doubleTouchMode**: double-touch mode.<br>- **none**: The touch mode is disabled.|

```ts
import { accessibility } from '@kit.AccessibilityKit';

@Entry
@Component
struct Index {
  aboutToAppear(): void {
    let touchMode: string = accessibility.getTouchModeSync();
    console.info(`current touch mode: ${JSON.stringify(touchMode)}`);
  }

  build() {
    Column() {
    }
  }
}
```
