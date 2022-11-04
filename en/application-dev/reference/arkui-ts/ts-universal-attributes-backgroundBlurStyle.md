# Background Blur

You can apply background blur effects to a component.

>  **NOTE**
> 
>The APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes

| Name                 | Type                    | Description                    |
| -------------------- | ----------------------- | ------------------------ |
| backgroundBlurStyle  | [BlurStyle](#blurstyle) | Style of the blur between the background and content for the current component. The input parameter indicates a blur material.|

## BlurStyle

| Name      | Description     |
| ------- | ---------- |
| Thin    | Thin material.    |
| Regular | Regular material. |
| Thick   | Thick material.      |

## Example

```ts
// xxx.ets
@Entry
@Component
struct Index {
  build() {
    Column() {
      Row() {
        Text("Thin Material")
      }
      .width(350)
      .height(300)
      .backgroundBlurStyle(BlurStyle.Thin)
      .position({ x: "15%", y: "30%" })
    }
    .height('100%')
    .width('100%')
    .backgroundImage($r('app.media.bg'))
    .backgroundImageSize(ImageSize.Cover)
  }
}
```
![en-us_image_background_blur_style](figures/en-us_image_background_blur_style.png)
