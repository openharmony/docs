# LoadingProgress

The **\<LoadingProgress>** component is used to create a loading animation.

>  **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

LoadingProgress()

Creates a **\<LoadingProgress>** component.

## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| color | [ResourceColor](ts-types.md#resourcecolor) | Foreground color of the **\<LoadingProgress>** component.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct LoadingProgressExample {
  build() {
    Column({ space: 5 }) {
      Text('Orbital LoadingProgress ').fontSize(9).fontColor(0xCCCCCC).width('90%')
      LoadingProgress()
        .color(Color.Blue)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_000000111864201](figures/en-us_image_000000111864201.gif)
