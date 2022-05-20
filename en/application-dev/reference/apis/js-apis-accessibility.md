# Accessibility

> **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```typescript
import accessibility from '@ohos.accessibility';
```

## AbilityState

Enumerates the states of an accessibility application.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

 | Name | Description |
 | -------- | -------- |
 | enable | The accessibility application is enabled. |
 | disable | The accessibility application is disabled. |
 | install | The accessibility application has been installed. |

## AbilityType

Enumerates the types of accessibility applications.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

 | Name | Description |
 | -------- | -------- |
 | audible | The accessibility application provides audible feedback. |
 | generic | The accessibility application provides generic feedback. |
 | haptic | The accessibility application provides haptic feedback. |
 | spoken | The accessibility application provides spoken feedback. |
 | visual | The accessibility application provides visual feedback. |

## AccessibilityAbilityInfo

Provides information about an accessibility application.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

### Attributes

 | Name | Type | Readable | Writable | Description |
 | -------- | -------- | -------- | -------- | -------- |
 | id | number | Yes | No | Ability ID. |
 | name | string | Yes | No | Ability name. |
 | bundleName | string | Yes | No | Bundle name. |
 | abilityTypes | Array&lt;[AbilityType](#abilitytype)&gt; | Yes | No | Accessibility application type. |
 | capabilities | Array&lt;[Capability](#capability)&gt; | Yes | No | Capabilities list of the accessibility application. |
 | description | string | Yes | No | Description of the accessibility application. |
 | eventTypes | Array&lt;[EventType](#eventtype)&gt; | Yes | No | List of events that the accessibility application focuses on. |

## Action

Describes the target action supported by an accessibility application.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

 | Name | Description |
 | -------- | -------- |
 | click | Clicking. |
 | longClick | Long pressing. |
 | scrollForward | Scrolling forward. |
 | scrollBackward | Scrolling backward. |
 | focus | Obtaining focus. |
 | clearFocus | Clearing focus. |
 | clearSelection | Clearing selection. |
 | accessibilityFocus | Obtaining the accessibility focus. |
 | clearAccessibilityFocus | Clearing the accessibility focus. |
 | cut | Cut. |
 | copy | Copy. |
 | paste | Paste. |
 | select | Select. |
 | setText | Setting the text. |
 | delete | Delete. |
 | setSelection | Setting the selection. |

## Capability

Enumerates the capabilities of an auxiliary application.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

 | Name | Description |
 | -------- | -------- |
 | retrieve | Capability to retrieve the window content. |
 | touchGuide | Capability of touch guide mode. |
 | keyEventObserver | Capability to filter key events. |
 | zoom | Capability to control the display zoom level. |
 | gesture | Capability to perform gesture actions. |

## CaptionsFontEdgeType<sup>8+</sup>

Enumerates the caption font edge type.

**System capability**: SystemCapability.Barrierfree.Accessibility.Hearing

 | Name | Description |
 | -------- | -------- |
 | none | No effect. |
 | raised | Raised effect. |
 | depressed | Depressed effect. |
 | uniform | Uniform effect. |
 | dropShadow | Drop shadow effect. |

## CaptionsFontFamily<sup>8+</sup>

Enumerates the caption font families.

**System capability**: SystemCapability.Barrierfree.Accessibility.Hearing

 | Name | Description |
 | -------- | -------- |
 | default | Default font family. |
 | monospacedSerif | Monospaced Serif fonts, which use the same width for each character. |
 | serif | Serif fonts. |
 | monospacedSansSerif | Monospaced Sans Serif fonts, which use the same width for each character. |
 | sansSerif | Sans Serif fonts. |
 | casual | Casual fonts. |
 | cursive | Cursive fonts. |
 | smallCapitals | Small caps fonts. |

## CaptionsStyle<sup>8+</sup>

Describes the caption style.

**System capability**: SystemCapability.Barrierfree.Accessibility.Hearing

 | Name | Type | Readable | Writable | Description |
 | -------- | -------- | -------- | -------- | -------- |
 | fontFamily | [CaptionsFontFamily](#captionsfontfamily8) | Yes | No | Font family of the captions. |
 | fontScale | number | Yes | No | Font scale of the captions. |
 | fontColor | number \ | string | Yes | No | Font color of the captions. |
 | fontEdgeType | [CaptionsFontEdgeType](#captionsfontedgetype8) | Yes | No | Font edge type of the captions. |
 | backgroundColor | number \ | string | Yes | No | Background color of the captions. |
 | windowColor | number \ | string | Yes | No | Window color of the captions. |

## CaptionsManager<sup>8+</sup>

Implements caption configuration management.

### Attributes

 | Name | Type | Readable | Writable | Description |
 | -------- | -------- | -------- | -------- | -------- |
 | enabled | boolean | Yes | No | Whether to enable caption configuration. |
 | style | [CaptionsStyle](#captionsstyle8) | Yes | No | Caption style. |

### Methods

In the following API examples, you must first use the [accessibility.getCaptionsManager()](#accessibilitygetcaptionsmanager8) method to obtain a **captionsManager** instance, and then call the methods using the obtained instance.

#### on('enableChange')

on(type: 'enableChange', callback: Callback&lt;boolean&gt;): void;

Enables listening for enable status changes of caption configuration.

**System capability**: SystemCapability.Barrierfree.Accessibility.Hearing

- **Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | type | string | Yes | Type of the event to listen for, which is set to **enableChange** in this API. |
 | callback | Callback&lt;boolean&gt; | Yes | Callback invoked when the enable status of caption configuration changes. |

- Example

  ```typescript
  captionsManager.on('enableChange',(data) => {
      console.info('success data:subscribeStateObserver : ' + JSON.stringify(data))
  })
  ```

#### on('styleChange')

on(type: 'styleChange', callback: Callback&lt;CaptionsStyle&gt;): void;

Enables listening for caption style changes.

**System capability**: SystemCapability.Barrierfree.Accessibility.Hearing

- **Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | type | string | Yes | Type of the event to listen for, which is set to **styleChange** in this API. |
 | callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | Yes | Callback invoked when the caption style changes. |

- Example

  ```typescript
  captionsManager.on('styleChange',(data) => {
      console.info('success data:subscribeStateObserver : ' + JSON.stringify(data))
  })
  ```
  
#### off('enableChange')

off(type: 'enableChange', callback?: Callback&lt;boolean&gt;): void;

Disables listening for enable status changes of caption configuration.

**System capability**: SystemCapability.Barrierfree.Accessibility.Hearing

- **Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | type | string | Yes | Type of the event to listen for, which is set to **enableChange** in this API. |
 | callback | Callback&lt;boolean&gt; | No | Callback invoked when the enable status of caption configuration changes. |

- Example

  ```typescript
  captionsManager.off('enableChange')
  ```

#### off('styleChange')

off(type: 'styleChange', callback?: Callback&lt;CaptionsStyle&gt;): void;

Disables listening for caption style changes.s is removed.

**System capability**: SystemCapability.Barrierfree.Accessibility.Hearing

- **Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | type | string | Yes | Type of the event to listen for, which is set to **styleChange** in this API. |
 | callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | No | Callback invoked when the caption style changes. |

- Example

  ```typescript
  captionsManager.off('styleChange')
  ```

## EventInfo

Describes a GUI change event.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

### Attributes

 | Name | Type | Readable | Writable | Description |
 | -------- | -------- | -------- | -------- | -------- |
 | type | [EventType](#eventtype) | Yes | Yes | Accessibility event type. |
 | windowUpdateType | [WindowUpdateType](#windowupdatetype) | Yes | Yes | Window update type. |
 | bundleName | string | Yes | Yes | Target application name. |
 | componentType | string | Yes | Yes | Type of the event source component, for example, button or chart. |
 | pageId | number | Yes | Yes | Page ID of the event source. |
 | description | string | Yes | Yes | Event description. |
 | triggerAction | [Action](#action) | Yes | Yes | Action that triggers the event. |
 | textMoveUnit | [TextMoveUnit](#textmoveunit) | Yes | Yes | Text movement unit. |
 | contents | Array&lt;string&gt; | Yes | Yes | Array of contents. |
 | lastContent | string | Yes | Yes | Latest content. |
 | beginIndex | number | Yes | Yes | Sequence number of the first item displayed on the page. |
 | currentIndex | number | Yes | Yes | Sequence number of the current item. |
 | endIndex | number | Yes | Yes | Sequence number of the last item displayed on the page. |
 | itemCount | number | Yes | Yes | Total number of items. |

## EventType

Enumerates accessibility event types.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

 | Name | Description |
 | -------- | -------- |
 | click | Event of clicking a component. |
 | longClick | Event of long-pressing a component. |
 | select | Event of selecting a component. |
 | focus | Event indicating that the component obtains the focus. |
 | textUpdate | Event indicating that the component text has been updated. |
 | hoverEnter | Event indicating that the hover enters a component. |
 | hoverExit | Event indicating that the hover exits a component. |
 | scroll | Event of the scroll view. |
 | textSelectionUpdate | Event indicating that the selected text has been updated. |
 | accessibilityFocus | Event indicating that the accessibility focus has been obtained. |
 | accessibilityFocusClear | Event indicating that the accessibility focus has been cleared. |

## TextMoveUnit

Enumerates the movement units for traversing the node text.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

 | Name | Description |
 | -------- | -------- |
 | char | The movement unit for traversing the node text is by character. |
 | word | The movement unit for traversing the node text is by word. |
 | line | The movement unit for traversing the node text is by line. |
 | page | The movement unit for traversing the node text is by page. |
 | paragraph | The movement unit for traversing the node text is by paragraph. |

## WindowUpdateType

Enumerates window update types.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

 | Name | Description |
 | -------- | -------- |
 | add | Window adding. |
 | remove | Window deletion. |
 | title | Window title change. |
 | bounds | Window boundary change. |
 | layer | Window layer change. |
 | active | Window activity change. |
 | focus | Window focus change. |
 | accessibilityFocus | Window accessibility focus change. |
 | parent | Parent window change. |
 | children | Child window change. |
 | pip | Picture-in-picture (PIP) mode change. |

## accessibility.getAbilityLists

getAbilityLists(abilityType: AbilityType, stateType: AbilityState): Promise&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;

Obtains the accessibility application list. This API uses a promise to return the result.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

- **Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | abilityType | [AbilityType](#abilitytype) | Yes | Accessibility application type. |
 | stateType | [AbilityState](#abilitystate) | Yes | Accessibility application status. |

- Return value

 | Type | Description |
 | -------- | -------- |
 | Promise&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | Promise used to return the accessibility application list. |

- Example

  ```typescript
  accessibility.getAbilityLists("spoken", "enable")
      .then((data) => {
          console.info('success data:getAbilityList1 : ' + JSON.stringify(data));
          for (let item of data) {
              console.info(item.id);
              console.info(item.name);
              console.info(item.description);
              console.info(item.abilityTypes);
              console.info(item.eventTypes);
              console.info(item.capabilities);
              console.info(item.packageName);
              console.info(item.filterBundleNames);
              console.info(item.bundleName);
          }
      }).catch((error) => {
          console.error('failed to  getAbilityList1 because ' + JSON.stringify(error));
      })
  ```

## accessibility.getAbilityLists

getAbilityLists(abilityType: AbilityType, stateType: AbilityState,callback: AsyncCallback&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;): void

Obtains the accessibility application list. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

- **Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | abilityType | [AbilityType](#abilitytype) | Yes | Accessibility application type. |
 | stateType | [AbilityState](#abilitystate) | Yes | Accessibility application status. |
 | callback | AsyncCallback&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | Yes | Callback used to return the accessibility application list. |

- Example

  ```typescript
  accessibility.getAbilityLists("visual", "enable", (err, data) => {
      if (err) {
          console.error('failed to getAbilityList2 because ' + JSON.stringify(err));
          return;
      }
      console.info('success data:getAbilityList2 : ' + JSON.stringify(data));
      for (let item of data) {
          console.info(item.id);
          console.info(item.name);
          console.info(item.description);
          console.info(item.abilityTypes);
          console.info(item.eventTypes);
          console.info(item.capabilities);
          console.info(item.packageName);
          console.info(item.filterBundleNames);
          console.info(item.bundleName);
      }
  })
  ```

## accessibility.getCaptionsManager<sup>8+</sup>

getCaptionsManager(): CaptionsManager

Obtains the accessibility caption configuration.

**System capability**: SystemCapability.Barrierfree.Accessibility.Hearing

- Return value

 | Type | Description |
 | -------- | -------- |
 | [CaptionsManager](#captionsmanager8) | Accessibility caption configuration. |

- Example

  ```typescript
  captionsManager = accessibility.getCaptionsManager()
  ```

## accessibility.on('accessibilityStateChange' | 'touchGuideStateChange')

on(type: 'accessibilityStateChange' | 'touchGuideStateChange', callback: Callback&lt;boolean&gt;): void

Enables listening for the accessibility application or touch guide mode status changes. 

- **Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | type | string | Yes | Type of the event to listen for.<br>-&nbsp;**accessibilityStateChange** means to listen for enable status changes of the accessibility application.<br>**System capability**: SystemCapability.Barrierfree.Accessibility.Core<br>-&nbsp;**touchGuideStateChange** means to listen for enable status changes of the touch guide mode.<br>**System capability**: SystemCapability.Barrierfree.Accessibility.Vision |
 | callback | Callback&lt;boolean&gt; | Yes | Callback invoked when the enable status changes. |

- Example

  ```typescript
  accessibility.on('accessibilityStateChange',(data) => { 
      console.info('success data:subscribeStateObserver : ' + JSON.stringify(data))
  })
  ```

## accessibility.off('accessibilityStateChange' | 'touchGuideStateChange')

off(type: 'accessibilityStateChange ' | 'touchGuideStateChange', callback?: Callback&lt;boolean&gt;): void

Disables listening for the accessibility application or touch guide mode status changes.

 

- **Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | type |  string | No | Type of the event to listen for.<br>-&nbsp;**accessibilityStateChange** means to listen for enable status changes of the accessibility application.<br>**System capability**: SystemCapability.Barrierfree.Accessibility.Core<br>-&nbsp;**touchGuideStateChange** means to listen for enable status changes of the touch guide mode.<br>**System capability**: SystemCapability.Barrierfree.Accessibility.Vision |
 | callback | Callback&lt;boolean&gt; | No | Callback invoked when the enable status changes. |

- Example

  ```typescript
  accessibility.off('accessibilityStateChange',(data) => {
      console.info('success data:unSubscribeStateObserver : ' + JSON.stringify(data))
  })
  ```

## accessibility.isOpenAccessibility

isOpenAccessibility(): Promise&lt;boolean&gt;

Checks whether accessibility is enabled. This API uses a promise to return the result.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

- Return value

 | Type | Description |
 | -------- | -------- |
 | Promise&lt;boolean&gt; | Returns **true** if accessibility is enabled; returns **false** otherwise. |

- Example

  ```typescript
  accessibility.isOpenAccessibility()
      .then((data) => {
          console.info('success data:isOpenAccessibility : ' + JSON.stringify(data))
      }).catch((error) => {
          console.error('failed to  isOpenAccessibility because ' + JSON.stringify(error));
      })
  ```

## accessibility.isOpenAccessibility

isOpenAccessibility(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether accessibility is enabled. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

- Parameters

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback used to return the result. Returns **true** if accessibility is enabled; returns **false** otherwise. |

- Example

  ```typescript
  accessibility.isOpenAccessibility((err, data) => {
      if (err) {
          console.error('failed to isOpenAccessibility because ' + JSON.stringify(err));
          return;
      }
      console.info('success data:isOpenAccessibility : ' + JSON.stringify(data))
  })
  ```

## accessibility.isOpenTouchGuide

isOpenTouchGuide(): Promise&lt;boolean&gt;

Checks whether touch guide mode is enabled. This API uses a promise to return the result.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

- Return value

 | Type | Description |
 | -------- | -------- |
 | Promise&lt;boolean&gt; | Returns **true** if touch guide mode is enabled; returns **false** otherwise. |

- Example

  ```typescript
  accessibility.isOpenTouchGuide()
      .then((data) => {
          console.info('success data:isOpenTouchGuide : ' + JSON.stringify(data))
      }).catch((error) => {
          console.error('failed to  isOpenTouchGuide because ' + JSON.stringify(error));
      })
  ```

## accessibility.isOpenTouchGuide

isOpenTouchGuide(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether touch guide mode is enabled. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

- Parameters

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | callback | AsyncCallback&lt;boolean&gt; | Yes | Callback used to return the result. Returns **true** if touch guide mode is enabled; returns **false** otherwise. |

- Example

  ```typescript
  accessibility.isOpenTouchGuide((err, data) => {
      if (err) {
          console.error('failed to isOpenTouchGuide because ' + JSON.stringify(err));
          return;
      }
      console.info('success data:isOpenTouchGuide : ' + JSON.stringify(data))
  })
  ```

## accessibility.sendEvent

sendEvent(event: EventInfo): Promise&lt;void&gt;

Sends an accessibility event. This API uses a promise to return the result.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

- **Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | event | [EventInfo](#eventinfo) | Yes | Accessibility event. |

- Return value

 | Type | Description |
 | -------- | -------- |
 | Promise&lt;void&gt; | Promise used to return the result. Returns data if the accessibility event is sent successfully; returns an error otherwise. |

- Example

  ```typescript
  accessibility.sendEvent(this.eventInfo)
      .then((data) => {
          console.info('success data:sendEvent : ' + JSON.stringify(data))
      }).catch((error) => {
          console.error('failed to  sendEvent because ' + JSON.stringify(error));
      })
  ```

## accessibility.sendEvent

sendEvent(event: EventInfo, callback: AsyncCallback&lt;void&gt;): void

Sends an accessibility event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Barrierfree.Accessibility.Core

- **Parameters**

 | Name | Type | Mandatory | Description |
 | -------- | -------- | -------- | -------- |
 | event | [EventInfo](#eventinfo) | Yes | Accessibility event. |
 | callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. Returns data if the accessibility event is sent successfully; returns an error otherwise. |

- Example

  ```typescript
  accessibility.sendEvent(this.eventInfo,(err, data) => {
      if (err) {
          console.error('failed to sendEvent because ' + JSON.stringify(err));
          return;
      }   
      console.info('success data:sendEvent : ' + JSON.stringify(data))
  })
  ```
