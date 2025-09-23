# 组件内容填充方式
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->

用于决定在组件的宽高动画过程中，如何将动画最终的组件内容绘制在组件上。

>  **说明：**
>
>  从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## renderFit

renderFit(fitMode: RenderFit): T

设置宽高动画过程中的组件内容填充方式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**参数：** 

| 参数名  | 类型                            | 必填 | 说明                                                         |
| ------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| fitMode | [RenderFit](ts-appendix-enums.md#renderfit10) | 是   | 设置宽高动画过程中的组件内容填充方式。<br/>当不设置renderFit属性时，取默认值RenderFit.TOP_LEFT。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

## renderFit<sup>18+</sup>

renderFit(fitMode: Optional\<RenderFit>): T

设置宽高动画过程中的组件内容填充方式。与[renderFit](#renderfit)相比，fitMode参数新增了对undefined类型的支持。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**参数：** 

| 参数名  | 类型                                       | 必填 | 说明                                                         |
| ------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| fitMode | Optional\<[RenderFit](ts-appendix-enums.md#renderfit10)> | 是   | 设置宽高动画过程中的组件内容填充方式。<br/>当fitMode的值为undefined时，取默认值。恢复为内容填充方式为RenderFit.TOP_LEFT的效果。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件。 |

>  **说明：**
>
>  对于TEXTURE和SURFACE类型的[XComponent](./ts-basic-components-xcomponent.md)组件，当不设置renderFit属性时，取默认值为RenderFit.RESIZE_FILL。
>
> 对于SURFACE类型的[XComponent](./ts-basic-components-xcomponent.md)组件，背景色设置为不透明的纯黑色，在API version 18之前，其renderFit通用属性仅支持设置为RenderFit.RESIZE_FILL；在API version 18及之后，支持所有的RenderFit枚举值。
>
>  对于使用[ArkUI NDK接口](../../../ui/ndk-access-the-arkts-page.md)创建的XComponent组件，不支持使用属性获取函数[getAttribute](../capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute)获取其renderFit属性值。

## 示例

该示例主要演示通过renderFit设置宽高动画过程中的组件内容不同填充方式。

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
        .renderFit(RenderFit.LEFT)// 设置LEFT的renderFit，动画过程中，动画的终态内容与组件保持左对齐
        .margin(20)

      Text("Hello")
        .width(this.width1)
        .height(this.height1)
        .textAlign(TextAlign.Center)
        .borderWidth(1)
        .renderFit(RenderFit.CENTER)// 设置CENTER的renderFit，动画过程中，动画的终态内容与组件保持中心对齐
        .margin(20)

      Button("animate")
        .onClick(() => {
          this.getUIContext()?.animateTo({ curve: Curve.Ease }, () => {
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
