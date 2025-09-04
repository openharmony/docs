# ImageData
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sd-wu-->
<!--Designer: @sunbees-->
<!--Tester: @liuli0427-->
<!--Adviser: @HelloCrease-->

ImageData对象可以存储canvas渲染的像素数据。

>  **说明：**
>
>  从 API version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## constructor

constructor(width: number, height: number, data?: Uint8ClampedArray)

创建ImageData时，宽高不超过16384px，最大面积不超过16000px*16000px，超过最大面积则无法正常绘制。当创建面积超过536870911px时，返回值的width和height均为0px，data为undefined。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型  | 必填  | 说明 |
| ------ | ----- | ----- | ----- |
| width | number |是| 矩形区域宽度，默认单位为vp。 |
| height | number |是| 矩形区域高度，默认单位为vp。|
| data | [Uint8ClampedArray](../../apis-arkts/arkts-apis-arkts-collections-Uint8ClampedArray.md) |否| 一维数组，保存了相应的颜色数据，数据值范围为0到255。<br/>默认值：值全为0的一维数组 |

## constructor<sup>12+<sup>

constructor(width: number, height: number, data?: Uint8ClampedArray, unit?: LengthMetricsUnit)

创建ImageData时，宽高不超过16384px，最大面积不超过16000px*16000px，超过最大面积则无法正常绘制。当创建面积超过536870911px时，返回值的width和height均为0px，data为undefined。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型  | 必填  | 说明 |
| ------ | ----- | ----- | ----- |
| width | number |是| 矩形区域宽度，默认单位为vp。 |
| height | number |是| 矩形区域高度，默认单位为vp。|
| data | [Uint8ClampedArray](../../apis-arkts/arkts-apis-arkts-collections-Uint8ClampedArray.md) |否| 一维数组，保存了相应的颜色数据，数据值范围为0到255。<br/>默认值：值全为0的一维数组 |
| unit  | [LengthMetricsUnit](../js-apis-arkui-graphics.md#lengthmetricsunit12) | 否   |  用来配置ImageData对象的单位模式，配置后无法动态更改，配置方法同[CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md)。<br>默认值：DEFAULT |

## 属性

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型   | 只读 | 可选 | 说明 |
| ------ | -------- | --------- | ---------- | ------------------------------ |
| width | number | 是 | 否 | 矩形区域实际像素宽度。<br>单位为px。 |
| height | number | 是 | 否 | 矩形区域实际像素高度。<br>单位为px。 |
| data | [Uint8ClampedArray](../../apis-arkts/arkts-apis-arkts-collections-Uint8ClampedArray.md) | 是 | 否 | 一维数组，保存了相应的颜色数据，数据值范围为0到255。 |

>  **说明：**
>
>  可使用[px2vp](ts-pixel-units.md#像素单位转换)接口进行单位转换。

## 示例

使用getImageData接口获得一个ImageData对象。

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Translate {
    private settings: RenderingContextSettings = new RenderingContextSettings(true);
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);
    // "common/images/1234.png"需要替换为开发者所需的图像资源文件
    private img: ImageBitmap = new ImageBitmap("common/images/1234.png");

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() => {
            this.context.drawImage(this.img, 0, 0, 130, 130)
            let imageData = this.context.getImageData(50, 50, 130, 130)
            this.context.putImageData(imageData, 150, 150)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![zh-cn_image_000000127777780](figures/zh-cn_image_000000127777780.png)

