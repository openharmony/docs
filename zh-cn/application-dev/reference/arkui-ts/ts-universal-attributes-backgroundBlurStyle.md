# 组件背景模糊

为当前组件添加背景模糊效果。

>  **说明：**
> 
>  从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  此接口为系统接口。

## 属性

| 名称                  | 参数类型                     | 描述                     |
| -------------------- | ----------------------- | ------------------------ |
| backgroundBlurStyle  | [BlurStyle](#blurstyle) | 为当前组件提供一种在背景和内容之间的模糊能力，入参为模糊材质。|

## BlurStyle

  | 名称       | 描述      |
  | ------- | ---------- |
  | Thin    | 轻薄材质。     |
  | Regular | 普通厚度材质。  |
  | Thick   | 厚材质。       |

## 示例

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
![zh-cn_image_background_blur_style](figures/zh-cn_image_background_blur_style.png)