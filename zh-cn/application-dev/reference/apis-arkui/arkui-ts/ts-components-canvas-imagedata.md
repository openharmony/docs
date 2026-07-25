# ImageData
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

ImageData对象用于存储Canvas渲染的像素数据，支持对像素进行读取、修改和操作，适用于图像处理、像素级编辑、特效滤镜等场景。通过ImageData可以精确控制图像的每个像素点，实现自定义图像处理算法，为Canvas绘图提供灵活的像素级数据访问能力。

>  **说明：**
>
>  本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 创建ImageData时，宽高不超过16384px，面积不超过16000px*16000px。超过该面积限制时无法正常绘制；当创建面积超过536870911平方像素时，返回值的width和height均为0px，data为undefined。

## constructor

constructor(width: number, height: number, data?: Uint8ClampedArray)


创建宽为width，高为height，像素数据为data的ImageData，如果data未定义，则填充值全为0的一维数组。创建时宽高不超过16384px，最大面积不超过16000px*16000px，超过最大面积则无法正常绘制。当创建面积超过536870911平方像素时，返回值的width和height均为0px，data为undefined。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型  | 必填  | 说明 |
| ------ | ----- | ----- | ----- |
| width | number |是| 矩形区域宽度，单位为vp。宽高不超过16384px，最大面积不超过16000px*16000px，超过最大面积则无法正常绘制。当创建面积超过536870911平方像素时，返回对象的width和height为0，data为undefined。<br>异常值NaN、Infinity、负数和0按0处理。 |
| height | number |是| 矩形区域高度，单位为vp。宽高不超过16384px，最大面积不超过16000px*16000px，超过最大面积则无法正常绘制。当创建面积超过536870911平方像素时，返回对象的width和height为0，data为undefined。<br>异常值NaN、Infinity、负数和0按0处理。|
| data | [Uint8ClampedArray](../../apis-arkts/arkts-apis-arkts-collections-Uint8ClampedArray.md) |否| 一维数组，保存了RGBA格式的像素数据，每个像素占4字节，依次为R、G、B、A，数据值范围为0到255。数组长度必须为width × height × 4。当需要自定义ImageData的像素数据时传入此参数，如需要对图像进行像素级的处理或修改。传入异常值undefined时，data为undefined。<br>默认值：值全为0的一维数组 |

## constructor<sup>12+</sup>

constructor(width: number, height: number, data?: Uint8ClampedArray, unit?: LengthMetricsUnit)


创建宽为width，高为height，像素数据为data的ImageData，如果data未定义，则填充值全为0的一维数组，支持使用unit配置ImageData对象的单位模式。创建时宽高不超过16384px，最大面积不超过16000px*16000px，超过最大面积则无法正常绘制。当创建面积超过536870911平方像素时，返回值的width和height均为0px，data为undefined。异常值NaN、Infinity、负数和0按0处理。当需要使用vp单位实现响应式布局或适配不同屏幕密度时，可通过unit参数指定单位模式。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型  | 必填  | 说明 |
| ------ | ----- | ----- | ----- |
| width | number |是| 矩形区域宽度，单位由unit参数决定，默认单位为vp。宽高不超过16384px，最大面积不超过16000px*16000px，超过最大面积则无法正常绘制。当创建面积超过536870911平方像素时，返回对象的width和height为0，data为undefined。<br>异常值NaN、Infinity、负数和0按0处理。 |
| height | number |是| 矩形区域高度，单位由unit参数决定，默认单位为vp。宽高不超过16384px，最大面积不超过16000px*16000px，超过最大面积则无法正常绘制。当创建面积超过536870911平方像素时，返回对象的width和height为0，data为undefined。<br>异常值NaN、Infinity、负数和0按0处理。|
| data | [Uint8ClampedArray](../../apis-arkts/arkts-apis-arkts-collections-Uint8ClampedArray.md) |否| 一维数组，保存了RGBA格式的像素数据，每个像素占4字节，依次为R、G、B、A，数据值范围为0到255。当需要自定义ImageData的像素数据时传入此参数，如需要对图像进行像素级别的处理或修改。<br>传入异常值undefined时，data为undefined。<br>默认值：值全为0的一维数组。 |
| unit  | [LengthMetricsUnit](../js-apis-arkui-graphics.md#lengthmetricsunit12) | 否   |  用来配置ImageData对象的单位模式，配置后无法动态更改，配置方法同[CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md)。当需要使用vp单位实现响应式布局或适配不同屏幕密度时传入此参数。<br>异常值undefined、NaN和Infinity按默认值处理。<br>默认值：DEFAULT。 |

## 属性

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型   | 只读 | 可选 | 说明 |
| ------ | -------- | --------- | ---------- | ------------------------------ |
| width | number | 是 | 否 | 矩形区域实际像素宽度。<br>单位为px。 |
| height | number | 是 | 否 | 矩形区域实际像素高度。<br>单位为px。 |
| data | [Uint8ClampedArray](../../apis-arkts/arkts-apis-arkts-collections-Uint8ClampedArray.md) | 是 | 否 | 一维数组，保存了RGBA格式的像素数据，每个像素占4字节，依次为R、G、B、A，数据值范围为0到255。 |

>  **说明：**
>
>  可使用[px2vp](../arkts-apis-uicontext-uicontext.md#px2vp12)接口进行单位转换。

## 示例

使用drawImage绘制图像，通过getImageData接口获取ImageData对象，再使用putImageData接口将图像数据绘制到Canvas上。

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

  ![Yellow-lemon](figures/Yellow-lemon.png)

