# Accessibility Event

When accessibility mode is enabled, your application may need to handle or intercept accessibility events.

>**NOTE**
>
>  - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - Currently, accessibility events can be triggered only when accessibility mode is enabled.

## onAccessibilityFocus

onAccessibilityFocus(callback: AccessibilityFocusCallback): T

Triggered when the accessibility component gains or loses focus. Callback triggered when the component gains or loses focus.

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| callback | [AccessibilityFocusCallback](ts-universal-accessibility-event.md#AccessibilityFocusCallback) | Yes  | Callback that notifies the registered component of focus and blur events.|

**Return value**

| Type   | Description             |
| ------ | ---------------- |
| T | Current component.|

## AccessibilityFocusCallback

type AccessibilityFocusCallback = (isFocus: boolean) => void

Defines the callback type used in **onAccessibilityFocus**.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type   | Mandatory| Description             |
| ------ | ------ | ---- | ---------------- |
| isFocus | boolean | Yes| Whether the component has gained or lost focus.<br>**true**: The component has gained focus.<br>**false**: The component has lost focus.|

## onAccessibilityActionIntercept

onAccessibilityActionIntercept(callback: AccessibilityActionInterceptCallback): T

Registers a callback to be invoked before an accessibility event is triggered in accessibility mode. The application that registers this callback can decide whether to intercept the accessibility event based on the provided action type.

**Widget capability**: This API can be used in ArkTS widgets since API version 20.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| callback | [AccessibilityActionInterceptCallback](ts-universal-accessibility-event.md#accessibilityactioninterceptcallback) | Yes  | Callback to be invoked before an accessibility event is triggered. The application that registers this callback can decide whether to intercept the accessibility event.|

**Return value**

| Type   | Description             |
| ------ | ---------------- |
| T | Current component.|

## AccessibilityActionInterceptCallback

type AccessibilityActionInterceptCallback = (action: AccessibilityAction) => AccessibilityActionInterceptResult

Defines the callback type used in **onAccessibilityActionIntercept** to handle accessibility event interception.

**Widget capability**: This API can be used in ArkTS widgets since API version 20.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type   | Mandatory| Description             |
| ------ | ------ | ---- | ---------------- |
| action | [AccessibilityAction](ts-universal-accessibility-event.md#accessibilityaction) | Yes| Type of accessibility action being triggered.|

**Return value**

| Type   | Description             |
| ------ | ---------------- |
| [AccessibilityActionInterceptResult](ts-universal-accessibility-event.md#accessibilityactioninterceptresult) | Result indicating whether to intercept the accessibility event.|

## AccessibilityAction

Enumerates the types of accessibility actions that components can trigger.

**Widget capability**: This API can be used in ArkTS widgets since API version 20.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value | Description            |
| ---- | ---- | ------------------ |
| UNDEFINED_ACTION | 0 | Undefined accessibility action.|
| ACCESSIBILITY_CLICK | 1 | Accessibility click action.|

## AccessibilityActionInterceptResult

Enumerates the results of the accessibility event interception in **AccessibilityActionInterceptCallback**.

**Widget capability**: This API can be used in ArkTS widgets since API version 20.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Value | Description            |
| ---- | ---- | ------------------ |
| ACTION_INTERCEPT | 0 | Intercepts the accessibility event for the current component.|
| ACTION_CONTINUE | 1 | Allows the accessibility event to proceed with normal processing for the current component.|
| ACTION_RISE | 2 | Initiates event bubbling to the ancestor component that has registered **onAccessibilityActionIntercept** and uses the result from the ancestor component to determine the current component's interception result. If the ancestor component returns **ACTION_RISE**, event bubbling continues.|

## Example

The example demonstrates how to use the **onAccessibilityActionIntercept** event to intercept a click event on a **Toggle** component in accessibility mode before the click event is processed.

```ts
// xxx.ets
@Entry
@Component
struct SwitchBootcamp {
  @State private isOn: boolean = false;
  isPolygon(event: TouchEvent) {
    return true;
  }

  build() {
    NavDestination() {
      Column() {
        Text('onTouchIntercept')
        Row() {
          Text('Label message')
          Blank()
          Toggle({ type: ToggleType.Switch, isOn: $$this.isOn })
            .onAccessibilityActionIntercept((action : AccessibilityAction) => {
              if (action === AccessibilityAction.ACCESSIBILITY_CLICK) {
                this.getUIContext().showAlertDialog({
                  title: 'Title',
                  message: 'Message content',
                  primaryButton: {
                    value: 'OK',
                    action: () => {
                      this.isOn = !this.isOn;
                    }
                  },
                  secondaryButton: {
                    value: 'Cancel',
                    action: () => {
                    }
                  }
                })
                return AccessibilityActionInterceptResult.ACTION_INTERCEPT;
              } else {
                return AccessibilityActionInterceptResult.ACTION_CONTINUE;
              }
            })
        }.width('100%')
      }
      .padding(24)
      .width('100%')
    }
  }
}
```
