# AccessibilityExtensionContext

The **AccessibilityExtensionContext** module, inherited from **ExtensionContext**, provides context for **Accessibility Extension** abilities.

You can use the APIs of this module to configure the concerned information, obtain root information, and inject gestures.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Usage

Before using the **AccessibilityExtensionContext** module, you must define a child class that inherits from **AccessibilityExtensionAbility**.

```js
import AccessibilityExtensionAbility from '@ohos.application.AccessibilityExtensionAbility'
class MainAbility extends AccessibilityExtensionAbility {
    onConnect(): void {
        console.log("AxExtensionAbility onConnect");
        let axContext = this.context;
    }
}
```

## FocusDirection

Enumerates the focus directions.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name      | Description     |
| -------- | ------- |
| up       | Search for the next focusable item above the current item in focus.|
| down     | Search for the next focusable item below the current item in focus.|
| left     | Search for the next focusable item on the left of the current item in focus.|
| right    | Search for the next focusable item on the right the current item in focus.|
| forward  | Search for the next focusable item before the current item in focus.|
| backward | Search for the next focusable item after the current item in focus.|

## FocusType

Enumerates of the focus types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name           | Description         |
| ------------- | ----------- |
| accessibility | Accessibility focus.|
| normal        | Normal focus. |

## Rect

Defines a rectangle.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name    | Type  | Readable  | Writable  | Description       |
| ------ | ------ | ---- | ---- | --------- |
| left   | number | Yes   | No   | Left boundary of the rectangle.|
| top    | number | Yes   | No   | Top boundary of the rectangle.|
| width  | number | Yes   | No   | Width of the rectangle. |
| height | number | Yes   | No   | Height of the rectangle. |

## WindowType

Enumerates the window types.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

| Name         | Description       |
| ----------- | --------- |
| application | Application window.|
| system      | System window.|

## AccessibilityExtensionContext.setEventTypeFilter

setEventTypeFilter(type: Array<accessibility.EventType>): Promise\<boolean>;

Sets the concerned event type.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name | Type                                    | Mandatory  | Description      |
| ---- | ---------------------------------------- | ---- | -------- |
| type | Array&lt;[EventType](js-apis-accessibility.md#EventType)&gt; | Yes   | Event type.|

**Return value**

| Type                    | Description                   |
| ---------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```ts
this.context.setEventTypeFilter(['click', 'longClick']);
```

## AccessibilityExtensionContext.setTargetBundleName

setTargetBundleName(targetNames: Array\<string>): Promise\<boolean>;

Sets the concerned target bundle.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type               | Mandatory  | Description      |
| ----------- | ------------------- | ---- | -------- |
| targetNames | Array&lt;string&gt; | Yes   | Name of the target bundle.|

**Return value**

| Type                    | Description                   |
| ---------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```ts
this.context.setTargetBundleName(['com.ohos.mms']);
```

## AccessibilityExtensionContext.getFocusElement

getFocusElement(isAccessibilityFocus?: boolean): Promise\<AccessibilityElement>;

Obtains the focus element.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name                 | Type   | Mandatory  | Description                 |
| -------------------- | ------- | ---- | ------------------- |
| isAccessibilityFocus | boolean | No   | Whether the obtained focus element is an accessibility focus. The default value is false.|

**Return value**

| Type                                 | Description                    |
| ----------------------------------- | ---------------------- |
| Promise&lt;AccessibilityElement&gt; | Promise used to return the current focus element.|

**Example**

```ts
this.context.getFocusElement().then(focusElement => {
    console.log("AxExtensionAbility getFocusElement success");
})
```

## AccessibilityExtensionContext.getWindowRootElement

getWindowRootElement(windowId?: number): Promise\<AccessibilityElement>;

Obtains the root element of a window.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name     | Type  | Mandatory  | Description                         |
| -------- | ------ | ---- | --------------------------- |
| windowId | number | No   | Window for which you want to obtain the root element. If this parameter is not specified, it indicates the current active window.|

**Return value**

| Type                                 | Description                     |
| ----------------------------------- | ----------------------- |
| Promise&lt;AccessibilityElement&gt; | Promise used to return the root element.|

**Example**

```ts
this.context.getWindowRootElement().then(rootElement => {
    console.log("AxExtensionAbility getWindowRootElement success");
})
```

## AccessibilityExtensionContext.getWindows

getWindows(displayId?: number): Promise<Array\<AccessibilityElement>>;

Obtains the list of windows visible to users.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name      | Type  | Mandatory  | Description                       |
| --------- | ------ | ---- | ------------------------- |
| displayId | number | No   | Screen from which the window information is obtained. If this parameter is not specified, it indicates the default home screen.|

**Return value**

| Type                                      | Description                      |
| ---------------------------------------- | ------------------------ |
| Promise&lt;Array&lt;AccessibilityElement&gt;&gt; | Promise used to return the window list. |

**Example**

```ts
this.context.getWindows().then(windows => {
    console.log("AxExtensionAbility getWindows success");
})
```

## AccessibilityExtensionContext.injectGesture

injectGesture(gesturePath: GesturePath, listener: Callback\<boolean>): Promise\<boolean

Injects a gesture.

**System capability**: SystemCapability.BarrierFree.Accessibility.Core

**Parameters**

| Name        | Type                                    | Mandatory  | Description            |
| ----------- | ---------------------------------------- | ---- | -------------- |
| gesturePath | [GesturePath](js-apis-application-AccessibilityExtensionAbility.md#GesturePath) | Yes   | Path of the gesture to inject.    |
| listener    | Callback&lt;boolean&gt;                  | Yes   | Callback used to return the result.|

**Return value**

| Type                    | Description                    |
| ---------------------- | ---------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

```ts
let gesturePath = new GesturePath(100);
for (let i = 0; i < 10; i++) {
    let gesturePoint = new GesturePosition(100, i * 200);
    gesturePath.positions.push(gesturePoint);
}
this.context.gestureInject(gesturePath, (result) => {
    console.info('gestureInject result: ' + result);
})
```
