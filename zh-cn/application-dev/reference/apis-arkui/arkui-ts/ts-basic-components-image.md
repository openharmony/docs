# Image

Image为图片组件，常用于在应用中显示图片。Image支持加载[PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7)、[ResourceStr](ts-types.md#resourcestr)和[DrawableDescriptor](../js-apis-arkui-drawableDescriptor.md#drawabledescriptor)类型的数据源，支持png、jpg、jpeg、bmp、svg、webp和gif类型的图片格式。

> **说明：**
>
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 使用快捷组合键对Image组件复制时，Image组件必须处于[获焦状态](../../../ui/arkts-common-events-focus-event.md#设置组件是否获焦)。Image组件默认不获焦，需将[focusable](ts-universal-attributes-focus.md#focusable)属性设置为true，即可使用TAB键将焦点切换到组件上，再将[focusOnTouch](ts-universal-attributes-focus.md#focusontouch9)属性设置为true，即可实现点击获焦。
>
> 图片设置为svg图源时，当前支持的标签是svg、rect、circle、ellipse、path、line、polyline、polygon、feFlood、feBlend、feColorMatrix、feGaussianBlur、feComposite、filter、mask和use。

## 需要权限

使用网络图片时，需要申请权限ohos.permission.INTERNET。具体申请方式请参考[声明权限](../../../security/AccessToken/declare-permissions.md)。


## 子组件

无


## 接口

Image(src: PixelMap | ResourceStr | DrawableDescriptor)

通过图片数据源获取图片，用于后续渲染展示。

Image组件加载图片失败或图片尺寸为0时，图片组件大小自动为0，不跟随父组件的布局约束。

Image组件默认按照居中裁剪，例如组件宽高设置相同，原图长宽不等，此时按照中间区域进行裁剪。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：** 

| 参数名  | 参数类型                                     | 必填   | 参数描述                                     |
| ---- | ---------------------------------------- | ---- | ---------------------------------------- |
| src  | [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7)&nbsp;\|&nbsp;[ResourceStr](ts-types.md#resourcestr)\|&nbsp;[DrawableDescriptor](../js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | 是    | 图片的数据源，支持本地图片和网络图片，引用方式请参考[加载图片资源](../../../ui/arkts-graphics-display.md#加载图片资源)。<br>1. PixelMap格式为像素图，常用于图片编辑的场景。<br>2. ResourceStr包含Resource和string格式。<br>string格式可用于加载网络图片和本地图片，常用于加载网络图片。当使用相对路径引用本地图片时，例如Image("common/test.jpg")，不支持跨包/跨模块调用该Image组件，建议使用Resource格式来管理需全局使用的图片资源。<br>- 支持`Base64`字符串。格式`data:image/[png\|jpeg\|bmp\|webp];base64,[base64 data]`, 其中`[base64 data]`为`Base64`字符串数据。<br>- 支持file://路径前缀的字符串，[应用沙箱URI](../../apis-core-file-kit/js-apis-file-fileuri.md#constructor10)：file://\<bundleName>/\<sandboxPath>。用于读取本应用安装目录下files文件夹下的图片资源。需要保证目录包路径下的文件有可读权限。<br>Resource格式可以跨包/跨模块访问资源文件，是访问本地图片的推荐方式。<br/>3. 当传入资源id或name为普通图片时，生成DrawableDescriptor对象。<br>**说明：**<br/>- ArkTS卡片上支持gif图片格式动效，但仅在显示时播放一次。<br/>- ArkTS卡片上不支持http:/\/等网络相关路径前缀和file:/\/路径前缀的字符串。<br/>- ArkTS卡片上不支持&nbsp;[PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7)类型。 <br/>- 加载本地图片过程中，如果对图片进行修改或者替换，可能会引起应用崩溃。因此需要覆盖图片文件时，应该先删除该文件再重新创建一个同名文件。<br/>- 网络图片必须支持RFC 9113标准，否则会导致加载失败。<br/>- 如果下载的网络图片大于10MB或一次下载的网络图片数量较多，建议使用[HTTP](../../../network/http-request.md)工具提前预下载，提高图片加载性能，方便应用侧管理数据。<br/>- 如果SVG图片没有原生大小，需要给Image组件设置宽高，否则不显示。 |

## 属性

属性的详细使用指导请参考[添加属性](../../../ui/arkts-graphics-display.md#添加属性)。除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称                         | 参数类型                                                | 描述                                                         |
| ---------------------------- | ------------------------------------------------------- | ------------------------------------------------------------ |
| alt                          | string \| [Resource](ts-types.md#resource)          | 加载时显示的占位图，支持本地图片（png、jpg、bmp、svg和gif类型），不支持网络图片。<br>默认值：null<br>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| objectFit                    | [ImageFit](ts-appendix-enums.md#imagefit)               | 设置图片的填充效果。<br/>默认值：ImageFit.Cover<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| objectRepeat                 | [ImageRepeat](ts-appendix-enums.md#imagerepeat)         | 设置图片的重复样式。从中心点向两边重复，剩余空间不足放下一张图片时会截断。<br/>默认值：ImageRepeat.NoRepeat<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>svg类型图源不支持该属性。 |
| interpolation                | [ImageInterpolation](#imageinterpolation)               | 设置图片的插值效果，即缓解图片在缩放时的锯齿问题。<br/>默认值：ImageInterpolation.Low<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>svg类型图源不支持该属性。 |
| renderMode                   | [ImageRenderMode](#imagerendermode)                     | 设置图片的渲染模式为原色或黑白。<br/>默认值：ImageRenderMode.Original<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>svg类型图源不支持该属性。 |
| sourceSize                   | {<br/>width:&nbsp;number,<br/>height:&nbsp;number<br/>} | 设置图片解码尺寸，降低图片的分辨率，常用于需要让图片显示尺寸比组件尺寸更小的场景。和ImageFit.None配合使用时可在组件内显示小图。<br/>单位：vp<br>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：**<br/>仅在目标尺寸小于图源尺寸时生效。<br>svg类型图源不支持该属性。<br>PixelMap资源不支持该属性。 |
| matchTextDirection           | boolean                                                 | 设置图片是否跟随系统语言方向，在RTL语言环境下显示镜像翻转显示效果。<br/>默认值：false<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| fitOriginalSize              | boolean                                                 | 图片组件尺寸未设置时，其显示尺寸是否跟随图源尺寸。<br/>默认值：false<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| fillColor                    | [ResourceColor](ts-types.md#resourcecolor)              | 设置填充颜色，设置后填充颜色会覆盖在图片上。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br>**说明：** <br>仅对svg图源生效，设置后会替换svg图片的填充颜色。如需对png图片进行修改颜色，可以使用[colorFilter](#colorfilter9)。 |
| autoResize                   | boolean                                                 | 设置图片解码过程中是否对图源自动缩放。设置为true时，组件会根据显示区域的尺寸决定用于绘制的图源尺寸，有利于减少内存占用。如原图大小为1920x1080，而显示区域大小为200x200，则图片会降采样解码到200x200的尺寸，大幅度节省图片占用的内存。<br/>默认值：false<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 <br>**说明：** <br>降采样解码时图片的部分信息丢失，因此可能会导致图片质量的下降（如：出现锯齿），这时可以选择把autoResize设为false，按原图尺寸解码，提升显示效果，但会增加内存占用。<br>原图尺寸和显示尺寸不匹配时，图片都会出现些许的失真、模糊。最佳清晰度配置建议：<br>图片缩小显示时：.autoResize(false) + .interpolation(.Medium)<br>图片放大显示时：.interpolation(.High) |
| syncLoad<sup>8+</sup>        | boolean                                                 | 设置是否同步加载图片，默认是异步加载。同步加载时阻塞UI线程，不会显示占位图。<br/>默认值：false<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br>**说明：**<br>建议加载尺寸较小的本地图片时将syncLoad设为true，因为耗时较短，在主线程上执行即可。 |
| copyOption<sup>9+</sup>      | [CopyOptions](ts-appendix-enums.md#copyoptions9)        | 设置图片是否可复制。<br>当copyOption设置为非CopyOptions.None时，支持使用长按、鼠标右击、快捷组合键'CTRL+C'等方式进行复制。<br>默认值：CopyOptions.None<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br>**说明：**<br>svg图片不支持复制。 |
| colorFilter<sup>9+</sup>     | [ColorFilter](ts-types.md#colorfilter9)                 | 给图像设置颜色滤镜效果，入参为一个的4x5的RGBA转换矩阵。<br/>矩阵第一行表示R（红色）的向量值，第二行表示G（绿色）的向量值，第三行表示B（蓝色）的向量值，第四行表示A（透明度）的向量值，4行分别代表不同的RGBA的向量值。<br>当矩阵对角线值为1，其余值为0时，保持图片原有色彩。<br> **计算规则：**<br>如果输入的滤镜矩阵为：<br>![image-matrix-1](figures/image-matrix-1.jpg)<br>像素点为[R, G, B, A]<br>则过滤后的颜色为 [R’, G’, B’, A’]<br>![image-matrix-2](figures/image-matrix-2.jpg)<br>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>svg类型图源不支持该属性。 |
| draggable<sup>9+</sup>       | boolean                                                 | 组件默认拖拽效果，设置为true时，组件可拖拽。<br />API version 9及之前，默认值为false。API version 10及之后，默认值为true。 |
| enableAnalyzer<sup>11+</sup> | boolean                                                 | 设置组件支持AI分析，设置为true时，组件可进行AI分析。<br>不能和[overlay](ts-universal-attributes-overlay.md)属性同时使用，两者同时设置时overlay中CustomBuilder属性将失效。<br/>默认值：false<br>**说明：**<br/> 该特性依赖设备能力。 <br/> 分析图像要求是静态非矢量图，即svg、gif等图像类型不支持分析，支持传入[PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7)进行分析，目前仅支持[RGBA_8888](../../apis-image-kit/js-apis-image.md#pixelmapformat7)类型，使用方式见[示例](#使用pixelmap开启图像分析)。 <br/> alt占位图不支持分析，objectRepeat属性仅在ImageRepeat.NoRepeat下支持分析，隐私遮罩属性[obscured](ts-universal-attributes-obscured.md)打开时不支持分析。<br/> 基于完整原始图像进行分析，设置clip、margin、borderRadius、position和objectFit属性导致图像显示不完整，或使用renderMode设置蒙层，仍基于完整原始图像进行分析。<br/> copyOption属性不影响AI分析功能。 |
| resizable<sup>11+</sup>      | [ResizableOptions](#resizableoptions11)                 | 设置图像拉伸时可调整大小的图像选项。<br> **说明：**<br /> 1. 拉伸对拖拽缩略图以及占位图有效。<br>2. 设置合法的 [ResizableOptions](#resizableoptions11) 时，objectRepeat 属性设置不生效。<br>3. 当设置 top +bottom 大于原图的高或者 left + right 大于原图的宽时 [ResizableOptions](#resizableoptions11) 属性设置不生效。<br/> |

## ImageInterpolation

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称     | 描述                         |
| ------ | -------------------------- |
| None   | 最近邻插值。                   |
| High   | Cubic插值，插值质量最高，可能会影响图片渲染的速度。 |
| Medium | MipMap插值。                     |
| Low    | 双线性插值。                     |

## ImageRenderMode

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称       | 描述      |
| -------- | ------- |
| Original | 原色渲染模式。 |
| Template | 黑白渲染模式。 |

## ResizableOptions<sup>11+</sup>

图像拉伸时可调整大小的图像选项。

| 参数名   | 类型                                    | 说明                                       |
| ----- | ------------------------------------- | ---------------------------------------- |
| slice | [EdgeWidths](#edgewidths参数说明) | 边框宽度类型，用于描述组件边框不同方向的宽度。<br>**说明：**<br>只有当bottom和right同时大于0时，该属性生效。 |

## EdgeWidths参数说明

| 名称 | 类型 | 必填 | 说明 |
| --------- |-----------|-----------|-----------|
|  top    |  number  |  否  | 图片顶部拉伸时保持不变距离。<br>默认值：0<br>单位：vp |
|  right  |  number  |  否  | 图片右部拉伸时保持不变距离。<br>默认值：0<br>单位：vp |
|  bottom |  number  |  否  | 图片底部拉伸时保持不变距离。<br>默认值：0<br>单位：vp |
|  left   |  number  |  否  | 图片左部拉伸时保持不变距离。<br>默认值：0<br>单位：vp |

![edgewidths](figures/edgewidths.png)

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

### onComplete

onComplete(callback: (event?: { width: number, height: number, componentWidth: number, componentHeight: number, loadingStatus: number,contentWidth: number, contentHeight: number, contentOffsetX: number, contentOffsetY: number}) =&gt; void) }) =&gt; void)

图片数据加载成功和解码成功时均触发该回调，返回成功加载的图片尺寸。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名                          | 类型     | 说明                                       |
| ---------------------------- | ------ | ---------------------------------------- |
| width                        | number | 图片的宽。<br/>单位：像素                          |
| height                       | number | 图片的高。<br/>单位：像素                          |
| componentWidth               | number | 组件的宽。<br/>单位：像素                          |
| componentHeight              | number | 组件的高。<br/>单位：像素                          |
| loadingStatus                | number | 图片加载成功的状态值。<br/>**说明：**<br/>返回的状态值为0时，表示图片数据加载成功。返回的状态值为1时，表示图片解码成功。 |
| contentWidth<sup>10+</sup>   | number | 图片实际绘制的宽度。<br/>单位：像素<br>**说明：**<br/>仅在loadingStatus返回1时有效。 |
| contentHeight<sup>10+</sup>  | number | 图片实际绘制的高度。<br/>单位：像素<br/>**说明：**<br/>仅在loadingStatus返回1时有效。 |
| contentOffsetX<sup>10+</sup> | number | 实际绘制内容相对于组件自身的x轴偏移。<br/>单位：像素<br/>**说明：**<br/>仅在loadingStatus返回1时有效。 |
| contentOffsetY<sup>10+</sup> | number | 实际绘制内容相对于组件自身的y轴偏移。<br/>单位：像素<br/>**说明：**<br/>仅在loadingStatus返回1时有效。 |


### onError<sup>9+</sup>

onError(callback: [ImageErrorCallback](#imageerrorcallback9))

图片加载异常时触发该回调。

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名      | 类型                                       | 说明            |
| -------- | ---------------------------------------- | ------------- |
| callback | [ImageErrorCallback](#imageerrorcallback9) | 图片加载异常时触发的回调。 |

### onFinish

onFinish(event: () =&gt; void)

当加载的源文件为带动效的svg格式图片时，svg动效播放完成时会触发这个回调。如果动效为无限循环动效，则不会触发这个回调。

仅支持svg格式的图片。

从API version 9开始，该接口支持在ArkTS卡片中使用。

## ImageErrorCallback<sup>9+</sup>

type ImageErrorCallback = (error: [ImageError](#imageerror9)) => void

图片加载异常时触发的回调。

| 参数名   | 类型                         | 说明                |
| ----- | -------------------------- | ----------------- |
| error | [ImageError](#imageerror9) | 图片加载异常时触发回调的返回对象。 |

## ImageError<sup>9+</sup>

图片加载异常时触发回调的返回对象。

| 参数名             | 类型     | 说明              |
| --------------- | ------ | --------------- |
| componentWidth  | number | 组件的宽。<br/>单位：像素 |
| componentHeight | number | 组件的高。<br/>单位：像素 |
| message         | string | 报错信息。           |

## 示例

### 示例1

加载基本类型图片

```ts
@Entry
@Component
struct ImageExample1 {
  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Row() {
          // 加载png格式图片
          Image($r('app.media.ic_camera_master_ai_leaf'))
            .width(110).height(110).margin(15)
            .overlay('png', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          // 加载gif格式图片
          Image($r('app.media.loading'))
            .width(110).height(110).margin(15)
            .overlay('gif', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
        Row() {
          // 加载svg格式图片
          Image($r('app.media.ic_camera_master_ai_clouded'))
            .width(110).height(110).margin(15)
            .overlay('svg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          // 加载jpg格式图片
          Image($r('app.media.ic_public_favor_filled'))
            .width(110).height(110).margin(15)
            .overlay('jpg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }
}
```

![zh-cn_image_0000001592882500](figures/zh-cn_image_0000001592882500.gif)

### 示例2

加载网络图片时，默认网络超时是5分钟，建议使用alt配置加载时的占位图。如果需要更灵活的网络配置，可以使用[HTTP](../../../network/http-request.md)工具包发送网络请求，接着将返回的数据解码为Image组件中的`PixelMap`，图片开发可参考[图片处理](../../../media/image/image-overview.md)。

使用网络图片时，需要申请权限ohos.permission.INTERNET。具体申请方式请参考[声明权限](../../../security/AccessToken/declare-permissions.md)。

```ts
@Entry
@Component
struct ImageExample2 {
  build() {
    Column({ space: 10 }) {
      Image("https://www.example.com/xxx.png")// 直接加载网络地址，请填写一个具体的网络图片地址
        .alt($r('app.media.icon'))// 使用alt，在网络图片加载成功前使用占位图
        .width(100)
        .height(100)
    }
  }
}
```


### 示例3

为图片添加事件

```ts
@Entry
@Component
struct ImageExample3 {
  private imageOne: Resource = $r('app.media.earth');
  private imageTwo: Resource = $r('app.media.star');
  private imageThree: Resource = $r('app.media.moveStar');
  @State src: Resource = this.imageOne
  @State src2: Resource = this.imageThree
  build(){
    Column(){
      // 为图片添加点击事件，点击完成后加载特定图片
      Image(this.src)
        .width(100)
        .height(100)
        .onClick(() => {
          this.src = this.imageTwo
        })

      // 当加载图片为SVG格式时
      Image(this.src2)
        .width(100)
        .height(100)
        .onClick(() => {
          // SVG动效播放完成时加载另一张图片
          this.src2 = this.imageOne
        })
    }.width('100%').height('100%')
  }
}
```

![zh-cn_image_0000001607845173](figures/zh-cn_image_0000001607845173.gif)

### 示例4

使用PixelMap开启图像分析

```ts
import image from '@ohos.multimedia.image'
@Entry
@Component
struct ImageExample4 {
  @State imagePixelMap: image.PixelMap | undefined = undefined

  async aboutToAppear() {
    this.imagePixelMap = await this.getPixmapFromMedia($r('app.media.app_icon'))
  }

  build() {
    Column() {
      Image(this.imagePixelMap)
        .enableAnalyzer(true)
        .width(200)
        .height(200)
    }
  }
  private async getPixmapFromMedia(resource: Resource) {
    let unit8Array = await getContext(this)?.resourceManager?.getMediaContent({
      bundleName: resource.bundleName,
      moduleName: resource.moduleName,
      id: resource.id
    })
    let imageSource = image.createImageSource(unit8Array.buffer.slice(0, unit8Array.buffer.byteLength))
    let createPixelMap: image.PixelMap = await imageSource.createPixelMap({
      desiredPixelFormat: image.PixelMapFormat.RGBA_8888
    })
    await imageSource.release()
    return createPixelMap
  }
}
```

### 示例5

调整不同方向对图片进行拉伸

```ts
@Entry
@Component
struct Index {
  @State top: number = 40
  @State bottom: number = 5
  @State left: number = 40
  @State right: number = 10

  build() {
    Column({ space: 5 }) {
      // 原图效果
      Image($r("app.media.sky"))
        .width(200).height(200)
        .border({ width: 2, color: Color.Pink })
        .objectFit(ImageFit.Contain)

      // 图像拉伸效果，设置resizable属性，对图片不同方向进行拉伸
      Image($r("app.media.sky"))
        .resizable({
          slice: {
            left: this.left,
            right: this.right,
            top: this.top,
            bottom: this.bottom
          }
        })
        .width(200)
        .height(200)
        .border({ width: 2, color: Color.Pink })
        .objectFit(ImageFit.Contain)

      Row() {
        Button("add top to " + this.top).fontSize(10)
          .onClick(() => {
            this.top += 2
          })
        Button("add bottom to " + this.bottom).fontSize(10)
          .onClick(() => {
            this.bottom += 2
          })
      }

      Row() {
        Button("add left to " + this.left).fontSize(10)
          .onClick(() => {
            this.left += 2
          })
        Button("add right to " + this.right).fontSize(10)
          .onClick(() => {
            this.right += 2
          })
      }

    }
    .justifyContent(FlexAlign.Start).width('100%').height('100%')
  }
}
```

![imageResizable](figures/imageResizable.gif)