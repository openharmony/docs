# 编辑图片

## 场景说明
图片编辑是在应用中经常用到的功能，比如相机拍完照片后可以对照片进行编辑；截图后可以对截图进行编辑；可以对图库中的图片进行编辑等。本例即为大家介绍如何获取图片的pixelMap数据，并通过pixelMap对图片进行常见的编辑操作。

## 效果呈现
本例最终效果如下：

![image-edit](figures/image-edit.gif)

## 运行环境
本例基于以下环境开发，开发者也可以基于其他适配的版本进行开发：

- IDE: DevEco Studio 3.1 Release
- SDK: Ohos_sdk_public 3.2.12.5(API Version 9 Release)

## 实现思路
本例中展示的是对资源文件中的图片进行编辑，编辑操作主要分为以下三步：
1. 对图片解码，获取到pixelMap：先通过上下文context获取到资源管理器resourceManager，然后通过资源管理器获取到图片数据，然后获取图片的ArrayBuffer，最后通过ArrayBuffer创建imageSource，获取到pixelMap，完成图片解码。
2. 编辑pixelMap：获取到pixelMap后就可以针对pixelMap进行裁剪、缩放、偏移、旋转、翻转、调节透明度等操作。
3. 将编辑好的pixelMap渲染显示出来：完成对pixelMap的编辑后，可以通过Image组件将编辑后的pixelMap渲染显示出来。

## 开发步骤
由于本例重点讲解图片编辑，所以开发步骤会着重讲解相关实现，不相关的内容不做介绍，全量代码可参考完整代码章节。
1. 对图片进行解码。

    先通过上下文context获取到资源管理器resourceManager，然后通过资源管理器获取到图片数据，然后获取图片的ArrayBuffer，最后通过ArrayBuffer创建imageSource，获取到pixelMap，完成图片解码。
    具体代码如下：
    ```ts
    async get_pixelmap(){
      // 获取resourceManager资源管理
      const context = getContext(this)
      const resourceMgr = context.resourceManager
      // 获取rawfile文件夹下httpimage.PNG的ArrayBuffer
      const fileData = await resourceMgr.getMediaContent($r('app.media.httpimage'))
      const buffer = fileData.buffer
      // 创建imageSource
      const imageSource = image.createImageSource(buffer)
      // 创建PixelMap
      const pixelMap = await imageSource.createPixelMap()
      return pixelMap
    }
    ```
2. 编辑pixelMap。

    分别通过以下方法对pixelMap进行裁剪、缩放、偏移、旋转、翻转、调节透明度等操作：crop、scale、translate、rotate、flip、opacity。
    具体代码如下：
    ```ts
    // 对pixelMap进行裁剪
    async crop_image(){
      let pixelMap = await this.get_pixelmap()
      pixelMap.crop({x:0,y:0,size:{height:300,width:300}})
      this.imagePixelMap = pixelMap
    }
    // 对pixelMap进行缩放
    async scale_image(){
      let pixelMap = await this.get_pixelmap()
      pixelMap.scale(0.5,0.5)
      this.imagePixelMap = pixelMap
    }
    // 对pixelMap进行偏移
    async translate_image(){
      let pixelMap = await this.get_pixelmap()
      pixelMap.translate(100,100);
      this.imagePixelMap = pixelMap
    }
    // 对pixelMap进行旋转
    async rotate_image(){
      let pixelMap = await this.get_pixelmap()
      pixelMap.rotate(90);
      this.imagePixelMap = pixelMap
    }
    // 对pixelMap进行翻转
    async flip_image(){
      let pixelMap = await this.get_pixelmap()
      pixelMap.flip(false, true);
      this.imagePixelMap = pixelMap
    }
    // 对pixelMap进行透明度调整
    async opacity_image(){
      let pixelMap = await this.get_pixelmap()
      pixelMap.opacity(0.5);
      this.imagePixelMap = pixelMap
    }
    ```
3. 通过Image组件将编辑后的pixelMap渲染显示出来。

    第2步中将编辑好的pixelMap传递给状态变量imagePixelMap，本步中直接将imagePixelMap传入Image组件进行渲染显示。
    具体代码如下：
    ```ts
    if(!this.edit){
      Row(){
        Image($r('app.media.httpimage')).objectFit(ImageFit.None)
      }.width('100%').height('50%').backgroundColor('#F0F0F0')
    }else{
      Row(){
        // 将编辑好的pixelMap传递给状态变量imagePixelMap后，通过Image组件进行渲染
        Image(this.imagePixelMap).objectFit(ImageFit.None)
      }.width('100%').height('50%').backgroundColor('#F0F0F0')
    }
    ```

## 完整代码
本例完整代码如下：
```ts
import image from '@ohos.multimedia.image';

@Entry
@Component
struct ImageEdit{
  @State imagePixelMap:PixelMap = undefined
  @State edit:boolean = false

  @Builder buttonModel($$:{textContent,action}){
    Button($$.textContent)
      .fontSize(14)
      .height(30)
      .width(60)
      .borderRadius(10)
      .backgroundColor('#E8A027')
      .onClick(()=>{
        $$.action
        this.edit = true
      })
  }

  async get_pixelmap(){
    // 获取resourceManager资源管理
    const context = getContext(this)
    const resourceMgr = context.resourceManager
    // 获取rawfile文件夹下httpimage.PNG的ArrayBuffer
    const fileData = await resourceMgr.getMediaContent($r('app.media.httpimage'))
    const buffer = fileData.buffer
    // 创建imageSource
    const imageSource = image.createImageSource(buffer)
    // 创建PixelMap
    const pixelMap = await imageSource.createPixelMap()
    return pixelMap
  }

  // 对pixelMap进行裁剪
  async crop_image(){
    let pixelMap = await this.get_pixelmap()
    pixelMap.crop({x:0,y:0,size:{height:300,width:300}})
    this.imagePixelMap = pixelMap
  }

  // 对pixelMap进行缩放
  async scale_image(){
    let pixelMap = await this.get_pixelmap()
    pixelMap.scale(0.5,0.5)
    this.imagePixelMap = pixelMap
  }

  // 对pixelMap进行偏移
  async translate_image(){
    let pixelMap = await this.get_pixelmap()
    pixelMap.translate(100,100);
    this.imagePixelMap = pixelMap
  }

  // 对pixelMap进行旋转
  async rotate_image(){
    let pixelMap = await this.get_pixelmap()
    pixelMap.rotate(90);
    this.imagePixelMap = pixelMap
  }

  // 对pixelMap进行翻转
  async flip_image(){
    let pixelMap = await this.get_pixelmap()
    pixelMap.flip(false, true);
    this.imagePixelMap = pixelMap
  }

  // 对pixelMap进行透明度调整
  async opacity_image(){
    let pixelMap = await this.get_pixelmap()
    pixelMap.opacity(0.5);
    this.imagePixelMap = pixelMap
  }

  build(){
    Column(){
      if(!this.edit){
        Row(){
          Image($r('app.media.httpimage')).objectFit(ImageFit.None)
        }.width('100%').height('50%').backgroundColor('#F0F0F0')
      }else{
        Row(){
          // 将编辑好的pixelMap传递给状态变量imagePixelMap后，通过Image组件进行渲染
          Image(this.imagePixelMap).objectFit(ImageFit.None)
        }.width('100%').height('50%').backgroundColor('#F0F0F0')
      }

      Flex({wrap:FlexWrap.Wrap,justifyContent:FlexAlign.SpaceEvenly}){
        this.buttonModel({textContent:'裁剪',action:this.crop_image()})
        this.buttonModel({textContent:'缩放',action:this.scale_image()})
        this.buttonModel({textContent:'偏移',action:this.translate_image()})
        this.buttonModel({textContent:'旋转',action:this.rotate_image()})
        this.buttonModel({textContent:'翻转',action:this.flip_image()})
        this.buttonModel({textContent:'透明度',action:this.opacity_image()})
        Button('还原')
          .fontSize(14)
          .height(30)
          .width(60)
          .borderRadius(10)
          .margin({top:20})
          .backgroundColor('#A4AE77')
          .onClick(()=>{
            this.edit = false
          })
      }
      .margin({top:100})
      .height('100%')
      .width('100%')
    }
    .height('100%')
    .width('100%')
  }
}
```
## 参考
- [图片解码](../application-dev/media/image-decoding.md)
- [图片变换](../application-dev/media/image-transformation.md)
- [Image组件](../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-image.md)
