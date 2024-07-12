# Foreground Effect

You can apply different visual effects to foreground subjects.

>  **NOTE**
>
>  This feature is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.

## foregroundEffect

foregroundEffect(options: ForegroundEffectOptions)

Sets the foreground effect of the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                |
| ------ | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| options | [ForegroundEffectOptions](ts-appendix-enums.md#foregroundeffectoptions12) | Yes  | Foreground effect settings, including the blur radius.|

## Example

This example shows the usage of **foregroundEffect**.

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Row() {
      Image($r('app.media.icon'))
          .width(100)
          .height(100)
          .foregroundEffect({ radius: 20 })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}
```

Below is how the component looks with the foreground effect applied.
**radius** indicates the blur radius. A larger value creates a more blurred effect.

![foregroundColor_circle](figures/foregroundEffect.jpg)
