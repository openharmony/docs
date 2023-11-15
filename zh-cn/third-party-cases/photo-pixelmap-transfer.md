# 获取图库中的图片并显示在Image组件中

## 场景说明
拉起用户图库，选择图片并上传显示在应用界面中是比较常见的场景，比如上传用户头像、将图片上传朋友圈、购物应用中上传图片评价等等。本文以上传用户头像为例介绍如何获取用户图库中的图片并显示在应用界面中。

## 效果呈现
本例最终效果图如下：
![photo-pixelmap-transfer](figures/photo-pixelmap-transfer.gif)


## 环境要求
本例基于以下环境开发，开发者也可以基于其他适配的版本进行开发：

- IDE: DevEco Studio 4.0 Release
- SDK: Ohos_sdk_public 4.0.10.13 (API Version 10 Release)

## 实现思路
本例的包含的关键操作及其实现方案如下：
- 拉起用户图库选择图片：使用图片类用户文件选择器PhotoViewPicker拉起用户图库并选择图片，与此同时获取到选中图片的uri。
- 将选择的图片转换为pixelmap：由于Image组件不能直接通过uri显示图片内容，所以需要获取到图片的pixelmap。本例通过图片的uri获取到图片文件的fd（文件描述符），再使用createImageSource和createPixelMap方法将fd转换为pixelmap。
- 将图片显示在应用界面，完成头像更新：直接将获取到的pixelmap放到Image组件中完成图片显示。


## 开发步骤
本例详细开发步骤如下，开发步骤中仅展示相关步骤代码，全量代码请参考完整代码章节的内容。
1. 使用PhotoViewPicker拉起用户图库选择图片，并获取到图片的uri：
    ```ts
    // 定义一个函数用于点击头像时拉起用户图库
    pickProfile(): void{
      const photoSelectOptions = new picker.PhotoSelectOptions();
      // 设置选择的文件类型为图片类型
      photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
      // 一次只能选择一张图片
      photoSelectOptions.maxSelectNumber = 1;
      let uri = null;
      const photoViewPicker = new picker.PhotoViewPicker();
      // 拉起图库，获取选中图片的uri
      photoViewPicker.select(photoSelectOptions).then((photoSelectResult) => {
        // 获取选中图片的uri
        uri = photoSelectResult.photoUris[0];
        this.uri = uri
        console.info('photoViewPicker.select to file succeed and uris are:' + uri)
      }).catch((err) => {
        console.error(`Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
      })
    }
    ```
2. 使用获取到的uri将图片解码为pixelmap以便显示在Image组件中。
    ```ts
    // 定义获取图片pixelmap的函数
    getPixelMap(){
      // 通过uri打开图片文件，获取文件fd
      let file = fs.openSync(this.uri, fs.OpenMode.READ_ONLY);
      const imageSourceApi = image.createImageSource(file.fd);
      // 将图片解码为pixelmap
      imageSourceApi.createPixelMap().then(pixelmap => {
        // 用自定义变量profileImage接收pixelmap
        this.profileImage = pixelmap
        console.log('Succeeded in creating pixelmap object through image decoding parameters.');
      }).catch((err) => {
        console.log('Failed to create pixelmap object through image decoding parameters.');
      })
    }
    ```
3. 通过pixelmap将图片传入Image组件，完成头像上传更新。
    ```ts
    // 通过自定义变量profileImage将图片pixelmap传入Image组件
    Image(this.profileImage===null?this.profileSrc:this.profileImage)
      .width($r('app.float.mine_image_size3'))
      .height($r('app.float.mine_image_size3'))
      .objectFit(ImageFit.Cover)
      .markAnchor({ x: $r('app.float.mine_image_anchor'), y: $r('app.float.mine_image_anchor') })
      .position({ x: Const.MINE_IMAGE_X, y: Const.MINE_IMAGE_Y })
      .borderRadius(54)
    ```

## 完整代码
更新头像的完整代码如下：
```ts
// PhotoPixelmapTransfer.ets
import picker from '@ohos.file.picker';
import fs from '@ohos.file.fs';
import image from '@ohos.multimedia.image';

@Entry
@Component
export struct MinePage{
  @State profileSrc:Resource = $r('app.media.ic_profile_photo')
  @State profileImage:PixelMap = null
  private uri:string = ''
  @State flag:number = 0

  // 选择头像图片
  // 定义一个函数用于点击头像时拉起用户图库
  pickProfile(): void{
    const photoSelectOptions = new picker.PhotoSelectOptions();
    // 设置选择的文件类型为图片类型
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    // 一次只能选择一张图片
    photoSelectOptions.maxSelectNumber = 1;
    let uri = null;
    const photoViewPicker = new picker.PhotoViewPicker();
    // 拉起图库，获取选中图片的uri
    photoViewPicker.select(photoSelectOptions).then((photoSelectResult) => {
      // 获取选中图片的uri
      uri = photoSelectResult.photoUris[0];
      this.uri = uri
      this.flag = 1
      console.info('photoViewPicker.select to file succeed and uris are:' + uri)
    }).catch((err) => {
      console.error(`Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
    })
  }
  // 获取图片的pixelmap
  getPixelMap(){
    // 通过uri打开图片文件，获取文件fd
    let file = fs.openSync(this.uri, fs.OpenMode.READ_ONLY);
    const imageSourceApi = image.createImageSource(file.fd);
    // 将图片解码为pixelmap
    imageSourceApi.createPixelMap().then(pixelmap => {
      this.profileImage = pixelmap
      console.log('Succeeded in creating pixelmap object through image decoding parameters.');
    }).catch((err) => {
      console.log('Failed to create pixelmap object through image decoding parameters.');
    })
  }

  build(){
    Stack(){
      Image(this.profileImage===null?this.profileSrc:this.profileImage)
        .width(108)
        .height(108)
        .objectFit(ImageFit.Cover)
        .markAnchor({ x: 54, y: 54 })
        .position({ x: '50%', y: '45%' })
        .borderRadius(54)

      Image($r('app.media.add_profile'))
        .markAnchor({ x:35, y:35 })
        .position({ x: '50%', y: '45%'  })
        .width(68)
        .height(68)
        .opacity(0.1)
        .onClick(()=>{
          this.pickProfile()
        })
      
      if(this.flag === 1){
        Text('上传')
          .fontSize(10)
          .fontColor('#FFFFFF')
          .height(35)
          .width(35)
          .position({x:200,y:280})
          .borderRadius(17.5)
          .backgroundColor('#F07B7B')
          .textAlign(TextAlign.Center)
          .onClick(()=>{
            this.getPixelMap()
            this.flag = 0
          })
      }
    }
    .width('100%')
    .height('100%')
  }
}
```

## 参考
- [选择用户图片或视频类文件](../application-dev/file-management/select-user-file.md)
- [将图片解码为pixelmap](../application-dev/media/image-decoding.md)