# LoadingProgress

The **\<LoadingProgress>** component is used to create a loading animation.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

None


## APIs

LoadingProgress()

Creates a **LoadingProgress** instance.



## Attributes

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| color | [ResourceColor](../../ui/ts-types.md) | - | Foreground color of the loading progress bar.|



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
