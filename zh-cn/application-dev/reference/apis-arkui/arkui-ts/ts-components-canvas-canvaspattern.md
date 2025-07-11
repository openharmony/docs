# CanvasPattern

一个Object对象，使用[createPattern](ts-canvasrenderingcontext2d.md#createpattern)方法创建，通过指定图像和重复方式创建图片填充的模板。

>  **说明：**
>
>  从 API version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 方法

### setTransform

setTransform(transform?: Matrix2D): void

使用Matrix2D对象作为参数，对当前CanvasPattern进行矩阵变换。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型  | 必填 | 说明   |
| --------- | -------------- | ------ | ---------- |
| transform | [Matrix2D](ts-components-canvas-matrix2d.md) | 否  | 转换矩阵。<br>默认值：null |

## 示例

通过setTransform对当前CanvasPattern进行矩阵变换。

```ts
// xxx.ets
@Entry
@Component
struct CanvasPatternPage {
  private settings: RenderingContextSettings = new RenderingContextSettings(true);
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);
  private matrix: Matrix2D = new Matrix2D();
  private img: ImageBitmap = new ImageBitmap("common/pattern.jpg");
  private pattern: CanvasPattern | null = null;

  build() {
      Column() {
        Button("Click to set transform")
          .onClick(() => {
            this.matrix.scaleY = 1
            this.matrix.scaleX = 1
            this.matrix.translateX = 50
            this.matrix.translateY = 200
            if (this.pattern) {
              this.pattern.setTransform(this.matrix)
            }
            this.context.fillRect(0, 0, 480, 720)
          })
          .width("45%")
          .margin("5px")
        Canvas(this.context)
          .width('100%')
          .height('80%')
          .backgroundColor('#FFFFFF')
          .onReady(() => {
            this.pattern = this.context.createPattern(this.img, 'no-repeat')
            this.matrix.scaleY = 0.5
            this.matrix.scaleX = 0.5
            this.matrix.translateX = 50
            this.matrix.translateY = 50
            if (this.pattern) {
              this.context.fillStyle = this.pattern
              this.pattern.setTransform(this.matrix)
            }
            this.context.fillRect(0, 0, 480, 720)
          })
      }
      .width('100%')
      .height('100%')
  }
}
```

![CanvasPattern](./figures/canvas_pattern.gif)
