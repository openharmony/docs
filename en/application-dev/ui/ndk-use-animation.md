# Using Animations


## Using Property Animations

The ArkUI development framework primarily offers property animations through NDK APIs to implement component transition effects for appearance and disappearance. Additionally, frame animation capabilities from the ArkTS side can be bridged through the Node-API to achieve animation effects on the native side.

> **NOTE**
>
> - Obtain **this.getUIContext()** from ArkTS and pass it to the native side.
> 
> - On the native side, obtain the context using the [OH_ArkUI_GetContextFromNapiValue](../reference/apis-arkui/native__node__napi_8h.md) API.
> 
> - Animation property changes must be written within the callback of **ArkUI_ContextCallback**.
> 
> - The properties to be animated must have been set before the animation is executed.

A global **animateTo** explicit animation API is provided to specify transition effects for state changes caused by closure code. Like property animations, layout changes such as width and height adjustments are animated directly to their final states.

