# LoadingProgress

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The **\<LoadingProgress>** component is used to display the loading progress.

## Required Permissions

None

## Child Components

None

## APIs

LoadingProgress()

Creates a **LoadingProgress** instance.

## Attributes

| Name  | Type  | Default Value | Description                              |
| ----- | ----- | ------------- | ---------------------------------------- |
| color | Color | -             | Foreground color of the loading progress bar. |

## Example

```
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

![zh-cn_image_0000001198839004](figures/loadingProgress.png)