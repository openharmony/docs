# Implicit Shared Element Transition (geometryTransition)

**geometryTransition** is used to create a smooth, seamless transition between views. By specifying the frame and position of the in and out components through **geometryTransition**, you can create a spatial linkage between the transition effects (such as opacity and scale) defined through the **transition** mechanism. In this way, you can guide the visual focus from the previous view (out component) to the new view (in component).

> **NOTE**
>
> This feature is supported since API version 7 and effective since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> For the settings to take effect, [geometryTransition](ts-transition-animation-geometrytransition.md) must be used together with [animateTo](ts-explicit-animation.md). The animation duration and curve follow the settings in [animateTo](ts-explicit-animation.md). [animation](ts-animatorproperty.md) is not supported.

## geometryTransition

geometryTransition(id: string)

Implements an implicit shared element transition.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name | Type                | Mandatory| Description                                                    |
| ------- | ------------------------ | ---- | ------------------------------------------------------------ |
| id      | string                   | Yes  | ID used to set up a binding relationship. Setting **id** to an empty string clears the binding relationship. The value can be changed to re-establish the binding relationship. One ID can be bound to only two components, which function as in and out components.|

## geometryTransition<sup>11+</sup>

geometryTransition(id: string, options?: GeometryTransitionOptions)

Implements an implicit shared element transition.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                | Mandatory| Description                                                    |
| ------- | ------------------------ | ---- | ------------------------------------------------------------ |
| id      | string                   | Yes  | ID used to set up a binding relationship. Setting **id** to an empty string clears the binding relationship. The value can be changed to re-establish the binding relationship. One ID can be bound to only two components, which function as in and out components.|
| options | [GeometryTransitionOptions](#geometrytransitionoptions11) | No  | Settings of the implicit shared element transition.                                  |

## GeometryTransitionOptions<sup>11+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description                                                    |
| ------ | -------- | ---- | ------------------------------------------------------------ |
| follow | boolean  | No  | Whether to apply the animation to components that are always in the component tree. It is effective only in the **if** syntax.<br>Default value: **false**|

## Example

```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State isShow: boolean = false

  build() {
    Stack({ alignContent: Alignment.Center }) {
      if (this.isShow) {
        Image($r('app.media.pic'))
          .autoResize(false)
          .clip(true)
          .width(300)
          .height(400)
          .offset({ y: 100 })
          .geometryTransition("picture", { follow: false })
          .transition(TransitionEffect.OPACITY)
      } else {
        // geometryTransition is bound to a container. Therefore, a relative layout must be configured for the child components of the container.
        // The multiple levels of containers here are used to demonstrate passing of relative layout constraints.
        Column() {
          Column() {
            Image($r('app.media.icon'))
              .width('100%').height('100%')
          }.width('100%').height('100%')
        }
        .width(80)
        .height(80)
        // geometryTransition synchronizes rounded corner settings, but only for the bound component, which is the container in this example.
        // In other words, rounded corner settings of the container are synchronized, and those of the child components are not.
        .borderRadius(20)
        .clip(true)
        .geometryTransition("picture")
        // transition ensures that the component is not destructed immediately when it exits. You can customize the transition effect.
        .transition(TransitionEffect.OPACITY)
      }
    }
    .onClick(() => {
      animateTo({ duration: 1000 }, () => {
        this.isShow = !this.isShow
      })
    })
  }
}
```

![geometrytransition](figures/geometrytransition.gif)
