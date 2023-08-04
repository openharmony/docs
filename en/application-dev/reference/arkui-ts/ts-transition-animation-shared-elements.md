# Shared Element Transition

A shared element transition is a transition animation applied to a component that is present on two pages. This component is called the shared element and can be set in the **sharedTransition** attribute.

> **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Attributes


| Name            | Parameter                                                        | Description                                                    |
| ---------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| sharedTransition | id: string,<br>{<br> duration?: number,<br> curve?: [Curve](ts-appendix-enums.md#curve) \| string \| [ICurve](../apis/js-apis-curve.md#icurve)<sup>10+</sup>,<br> delay?: number,<br> motionPath?: <br>{<br> path: string,<br> form?: number,<br> to?: number,<br> rotatable?: boolean<br>},<br>zIndex?: number,<br>type?: [SharedTransitionEffectType](ts-appendix-enums.md#sharedtransitioneffecttype)<br>} | Transition of the shared element. If the same **id** value is configured for a component on the two pages, this component is considered as a shared element of the pages. If the **id** value is an empty string, no transition will be applied to the component.<br>- **id**: component ID.<br>- **duration**: animation duration.<br>Default value: **1000**<br>Unit: ms<br>Value range: [0, +∞)<br>The value **0** indicates that no animation is applied. A value less than 0 evaluates to the default value **1000**.<br>- **curve**: animation curve. The default curve is **Curve.Linear**.<br>- **delay**: animation delay.<br>Default value: **0**<br>Unit: ms<br>Value range: [0, +∞)<br>A value less than 0 evaluates to the value **0**.<br>- **motionPath**: motion path information. For details, see [Motion Path Animation](ts-motion-path-animation.md).<br>- **path**: path.<br>- **from**: start value.<br>- **to**: end value.<br>- **rotatable**: whether to rotate.<br>- **zIndex**: z-axis.<br>- **type**: animation type.|


## Example

This example implements the custom transition of a shared image during redirection from one page to another, which is triggered by a click on the image.

```ts
// xxx.ets
@Entry
@Component
struct SharedTransitionExample {
  @State active: boolean = false

  build() {
    Column() {
      Navigator({ target: 'pages/PageB', type: NavigationType.Push }) {
        Image($r('app.media.ic_health_heart')).width(50).height(50)
          .sharedTransition('sharedImage', { duration: 800, curve: Curve.Linear, delay: 100 })
      }.padding({ left: 20, top: 20 })
      .onClick(() => {
        this.active = true
      })
    }
  }
}
```

```ts
// PageB.ets
@Entry
@Component
struct pageBExample {
  build() {
    Stack() {
      Image($r('app.media.ic_health_heart')).width(150).height(150)
        .sharedTransition('sharedImage', { duration: 800, curve: Curve.Linear, delay: 100 })
    }.width('100%').height('100%')
  }
}
```

![shared](figures/shared.gif)
