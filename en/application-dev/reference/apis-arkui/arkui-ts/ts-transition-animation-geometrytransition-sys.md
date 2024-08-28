# Implicit Shared Element Transition (geometryTransition) (System API)

**GeometryTransition** is used to create a smooth, seamless transition between views. By specifying the frame and position of the in and out components through **GeometryTransition**, you can create a spatial linkage between the transition effects (such as opacity and scale) defined through the **transition** mechanism. In this way, you can guide the visual focus from the previous view (out component) to the new view (in component).

> **NOTE**
>
> This feature is supported since API version 7 and effective since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> For the settings to take effect, [geometryTransition](ts-transition-animation-geometrytransition.md) must be used together with [animateTo](ts-explicit-animation.md). The animation duration and curve follow the settings in [animateTo](ts-explicit-animation.md). [animation](ts-animatorproperty.md) is not supported.
>
> This topic describes only the system APIs provided by the module. For details about its public APIs, see [Implicit Shared Element Transition (geometryTransition)](ts-transition-animation-geometrytransition.md).

## GeometryTransitionOptions<sup>11+<sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name| Type| Mandatory| Description                                                                 |
| ------ | -------- | ---- | ------------------------------------------------------------------------- |
| hierarchyStrategy<sup>12+<sup> | [TransitionHierarchyStrategy](#transitionhierarchystrategy12)  | No  | <br>Strategy for the hierarchical position movement of in/out components in the component tree during the shared element transition process.<br>Default value: **TransitionHierarchyStrategy.ADAPTIVE**<br><br>The setting significantly affects the front-to-back overlap relationship of the in/out components in comparison to other components. Exercise caution with it under normal conditions.<br>You are advised to adjust this setting only when there is an error in the component overlap relationship observed during the shared element transition process.<br>**System API**: This is a system API.|

## TransitionHierarchyStrategy<sup>12+<sup>
Enumerates the strategies for the hierarchical position movement of in/out components in the component tree during the shared element transition process.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Atomic service API**: This API can be used in atomic services since API version 12.

**System API**: This is a system API.

| Name  | Value| Description|
| ------ | - | ---- |
| NONE  | 0 | The in/out components maintain their original hierarchical positions and are affected by the scale and position of their parent components.|
| ADAPTIVE | 1 | Relatively lower-level in/out components are promoted to a higher position in the component tree relative to the higher-level in/out components.<br>This mode also causes the promoted components to be decoupled from their parent components, not affected by the scale and position of their parent components.<br>For example, if the in component is at a higher hierarchy level than the out component, in this mode the out component will be decoupled from its own parent component during the animation process and promoted to the hierarchical position of the in component, while the in component's hierarchical position remains unchanged.|

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
          .geometryTransition("picture", {hierarchyStrategy: TransitionHierarchyStrategy.ADAPTIVE})
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
        .geometryTransition("picture", {hierarchyStrategy: TransitionHierarchyStrategy.ADAPTIVE})
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
