# 组件内容填充方式

用于决定在组件的宽高动画过程中，如何将动画最终的组件内容绘制在组件上。

>  **说明：**
>
>  从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## renderFit

renderFit(fitMode: RenderFit)

设置宽高动画过程中的组件内容填充方式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                            | 必填 | 说明                                                         |
| ------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| fitMode | [RenderFit](#renderfit枚举说明) | 是   | 设置宽高动画过程中的组件内容填充方式。<br/>当不设置renderFit属性时，取默认值RenderFit.TOP_LEFT。 |

>  **说明：**
>
>  对于TEXTURE和SURFACE类型的[XComponent](./ts-basic-components-xcomponent.md)组件，当不设置renderFit属性时，取默认值为RenderFit.RESIZE_FILL。

## RenderFit枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

| 名称                          | 描述                                       | 示意图                                      |
| --------------------------- | ---------------------------------------- | ---------------------------------------- |
| CENTER                      | 保持动画终态的内容大小，并且内容始终与组件保持中心对齐。             | ![renderfit_center](figures/renderfit_center.png) |
| TOP                         | 保持动画终态的内容大小，并且内容始终与组件保持顶部中心对齐。           | ![renderfit_top](figures/renderfit_top.png) |
| BOTTOM                      | 保持动画终态的内容大小，并且内容始终与组件保持底部中心对齐。           | ![renderfit_bottom](figures/renderfit_bottom.png) |
| LEFT                        | 保持动画终态的内容大小，并且内容始终与组件保持左侧对齐。             | ![renderfit_left](figures/renderfit_left.png) |
| RIGHT                       | 保持动画终态的内容大小，并且内容始终与组件保持右侧对齐。             | ![renderfit_right](figures/renderfit_right.png) |
| TOP_LEFT                    | 保持动画终态的内容大小，并且内容始终与组件保持左上角对齐。            | ![renderfit_top_left](figures/renderfit_top_left.png) |
| TOP_RIGHT                   | 保持动画终态的内容大小，并且内容始终与组件保持右上角对齐。            | ![renderfit_top_right](figures/renderfit_top_right.png) |
| BOTTOM_LEFT                 | 保持动画终态的内容大小，并且内容始终与组件保持左下角对齐。            | ![renderfit_bottom_left](figures/renderfit_bottom_left.png) |
| BOTTOM_RIGHT                | 保持动画终态的内容大小，并且内容始终与组件保持右下角对齐。            | ![renderfit_bottom_right](figures/renderfit_bottom_right.png) |
| RESIZE_FILL                 | 不考虑动画终态内容的宽高比，并且内容始终缩放到组件的大小。            | ![renderfit_resize_fill](figures/renderfit_resize_fill.png) |
| RESIZE_CONTAIN              | 保持动画终态内容的宽高比进行缩小或放大，使内容完整显示在组件内，且与组件保持中心对齐。 | ![renderfit_resize_contain](figures/renderfit_resize_contain.png) |
| RESIZE_CONTAIN_TOP_LEFT     | 保持动画终态内容的宽高比进行缩小或放大，使内容完整显示在组件内。当组件宽方向有剩余时，内容与组件保持左侧对齐，当组件高方向有剩余时，内容与组件保持顶部对齐。 | ![renderfit_resize_contain_top_left](figures/renderfit_resize_contain_top_left.png) |
| RESIZE_CONTAIN_BOTTOM_RIGHT | 保持动画终态内容的宽高比进行缩小或放大，使内容完整显示在组件内。当组件宽方向有剩余时，内容与组件保持右侧对齐，当组件高方向有剩余时，内容与组件保持底部对齐。 | ![renderfit_resize_contain_bottom_right](figures/renderfit_resize_contain_bottom_right.png) |
| RESIZE_COVER                | 保持动画终态内容的宽高比进行缩小或放大，使内容两边都大于或等于组件两边，且与组件保持中心对齐，显示内容的中间部分。 | ![renderfit_resize_cover](figures/renderfit_resize_cover.png) |
| RESIZE_COVER_TOP_LEFT       | 保持动画终态内容的宽高比进行缩小或放大，使内容的两边都恰好大于或等于组件两边。当内容宽方向有剩余时，内容与组件保持左侧对齐，显示内容的左侧部分。当内容高方向有剩余时，内容与组件保持顶部对齐，显示内容的顶侧部分。 | ![renderfit_resize_cover_top_left](figures/renderfit_resize_cover_top_left.png) |
| RESIZE_COVER_BOTTOM_RIGHT   | 保持动画终态内容的宽高比进行缩小或放大，使内容的两边都恰好大于或等于组件两边。当内容宽方向有剩余时，内容与组件保持右侧对齐，显示内容的右侧部分。当内容高方向有剩余时，内容与组件保持底部对齐，显示内容的底侧部分。 | ![renderfit_resize_cover_bottom_right](figures/renderfit_resize_cover_bottom_right.png) |

> **说明：**
>
> - 示意图中，蓝色区域表示内容，橙黄色区域表示节点大小。
> - 不同的内容填充方式在宽高动画过程中效果不一致，开发者需要选择合适的内容填充方式以实现需要的动画效果。

## 示例

```ts
// xxx.ets
@Entry
@Component
struct RenderFitExample {
  @State width1: number = 100;
  @State height1: number = 30;
  flag: boolean = true;
  build() {
    Column() {
      Text("Hello")
        .width(this.width1)
        .height(this.height1)
        .borderWidth(1)
        .textAlign(TextAlign.Start)
        .renderFit(RenderFit.LEFT) // 设置LEFT的renderFit，动画过程中，动画的终态内容与组件保持左对齐
        .margin(20)

      Text("Hello")
        .width(this.width1)
        .height(this.height1)
        .textAlign(TextAlign.Center)
        .borderWidth(1)
        .renderFit(RenderFit.CENTER) // 设置CENTER的renderFit，动画过程中，动画的终态内容与组件保持中心对齐
        .margin(20)

      Button("animate")
        .onClick(() => {
          animateTo({ curve: Curve.Ease }, () => {
            if (this.flag) {
              this.width1 = 150;
              this.height1 = 50;
            } else {
              this.width1 = 100;
              this.height1 = 30;
            }
            this.flag = !this.flag;
          })
        })
    }.width("100%").height("100%").alignItems(HorizontalAlign.Center)
  }
}
```

![renderfit](figures/renderfit.gif)
