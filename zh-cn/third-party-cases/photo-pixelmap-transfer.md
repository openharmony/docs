# 获取图库中的图片并显示在Image组件中

## 场景说明
拉起用户图库，选择图片并上传显示在应用界面中是比较常见的场景，比如上传用户头像、将图片上传社交平台、购物应用中上传图片评价等等。本文以上传用户头像为例介绍如何获取用户图库中的图片并显示在应用界面中。

## 效果呈现
本例最终效果图如下。

效果说明：点击头像处的相机，拉起用户图库，选择要上传的图片，点击上传，头像随即更新为上传后的图片。

![](./figures/photo-pixelmap-transfer.gif)


## 环境要求
本例基于以下环境开发，开发者也可以基于其他适配的版本进行开发：

- IDE: DevEco Studio 4.0 Release
- SDK: Ohos_sdk_public 4.0.10.13 (API Version 10 Release)

## 实现思路
本例的包含的关键操作及其实现方案如下：
- 拉起用户图库选择图片：使用图片类用户文件选择器PhotoViewPicker拉起用户图库并选择图片，与此同时获取到选中图片的uri。由于图库中图片属于系统资源，可被其他程序删除，修改，最终造成图库中uri路径失效，因此通常是将获取的图片资源推送至应用沙箱中指定路径或上传应用服务器中。本文采用选择图库图片后将图片拷贝至应用沙箱中指定路径中。
- 获取图片在应用沙箱中的uri后，可通过Image组件对图片进行显示，Image组件支持加载PixelMap、ResourceStr和DrawableDescriptor类型的数据源，支持png、jpg、bmp、svg和gif类型的图片格式。
- 对于用户头像应用场景下，部分应用可能需要支持对图片进行优化，编辑等（本例中不做详细介绍，具体操作请查阅官方文档中图片处理章节），因此本例中将获取的图片转换为PixelMap类型，用于Image组件展示。本例通过图片的uri获取到图片文件的fd（文件描述符），再使用createImageSource和createPixelMap方法将fd转换为pixelmap。


## 开发步骤
本例详细开发步骤如下，开发步骤中仅展示相关步骤代码，全量代码请参考完整代码章节的内容。
1. 使用PhotoViewPicker拉起用户图库选择图片，并获取到图片的uri，然后将被选择图片拷贝到应用沙箱中的指定位置，获取沙箱中的uri。
    ```ts
    // 定义一个函数用于点击头像时拉起用户图库
    async pickProfile() {
      const photoSelectOptions = new picker.PhotoSelectOptions();
      // 设置选择的文件类型为图片类型
      photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
      // 一次只能选择一张图片
      photoSelectOptions.maxSelectNumber = 1;
      const photoViewPicker = new picker.PhotoViewPicker();
      // 拉起图库，获取选中图片的uri,并将选择图片拷贝至应用沙箱指定位置
      await photoViewPicker.select(photoSelectOptions)
        .then((photoSelectResult: picker.PhotoSelectResult) => {
          // 获取选中图片的uri
          let imageUri = photoSelectResult.photoUris[0];
          console.info('photoViewPicker.select to file succeed and uris are:' + imageUri);
          let context = getContext()
          //获取应用通用文件路径
          let filesDir = context.filesDir
          let fileName = "userProfileImage"
          //获取沙箱中文件路径
          let path = filesDir + "/" + fileName + "." + imageUri.split(".")[1]
          let file = fs.openSync(imageUri, fs.OpenMode.READ_ONLY)
          let file2 = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE)
          //完成图片拷贝
          fs.copyFileSync(file.fd, file2.fd)
          fs.closeSync(file.fd)
          fs.closeSync(file2.fd)
          //获取图片沙箱路径对应的uri
          this.uri = fileUri.getUriFromPath(path)
          //获取图片对应的PixelMap
          this.getPixelMap()
        })
        .catch((err: BusinessError) => {
          console.error('MinePage', `Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
        })
    }
    ```

    >![icon-danger.gif](../device-dev/public_sys-resources/icon-danger.gif) **注意：** 
    >
    >由于photoViewPicker.select返回的uri权限是只读权限，因此需要注意以下三点：
    >
    >1. 在使用fs.openSync方法时，mode只能选择OpenMode.READ_ONLY，获取的文件进对象只有读权限。
    >2. 使用fs.copyFileSync进行拷贝操作时，如果直接使用fs.copyFileSync(file.fd, path) 方式进行拷贝时，path处新图片权限与file权限一致，在本例中即为只有读权限。如果希望新图片有读写权限，建议采用本文方式进行处理。此外如果使用fs.copyFileSync接口有文件覆盖场景时，主要注意目标文件必须有写权限，不然会报13900012 Permission denied 错误。
    >3. 开发过程中，如果拷贝完成后，无法确定拷贝是否成功，可通过开发工具中的Terminal执行 hdc shell 进入工程机查看具体路径下的文件及权限

    

2. 使用获取到的uri将图片解码为pixelmap以便显示在Image组件中。
    ```ts
    // 定义获取图片pixelmap的函数
    getPixelMap(){
      // 通过uri打开图片文件，获取文件fd
      let file = fs.openSync(this.uri, fs.OpenMode.READ_WRITE);
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
    Image(this.profileImage)
      .alt($r('app.media.ic_user_portrait'))
      .width(108)
      .height(108)
      .objectFit(ImageFit.Cover)
      .borderRadius(54)
      .onClick(() => {
        this.pickProfile()
      })
    ```

## 完整代码
更新头像的完整代码如下：
```ts
// PhotoPixelmapTransfer.ets
import picker from '@ohos.file.picker';
import fs from '@ohos.file.fs';
import image from '@ohos.multimedia.image';
import { BusinessError } from '@ohos.base';
import fileUri from '@ohos.file.fileuri';

@Entry
@Component
export struct MinePage {
  @State profileSrc: Resource = $r('app.media.ic_user_portrait')
  @State profileImage: PixelMap = new Object() as PixelMap
  @State uri: string = ''
  @State flag: number = 0

  // 选择头像图片
  // 定义一个函数用于点击头像时拉起用户图库
  async pickProfile1() {
    const photoSelectOptions = new picker.PhotoSelectOptions();
    // 设置选择的文件类型为图片类型
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    // 一次只能选择一张图片
    photoSelectOptions.maxSelectNumber = 1;
    let uri = "";
    const photoViewPicker = new picker.PhotoViewPicker();
    // 拉起图库，获取选中图片的uri
    photoViewPicker.select(photoSelectOptions).then((photoSelectResult) => {
      // 获取选中图片的uri
      uri = photoSelectResult.photoUris[0];
      this.uri = uri
      this.flag = 1
      console.info('photoViewPicker.select to file succeed and uris are:' + uri)
    }).catch((err: BusinessError) => {
      console.error(`Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
    })
    this.getPixelMap()
  }

  // 定义一个函数用于点击头像时拉起用户图库
  async pickProfile() {
    const photoSelectOptions = new picker.PhotoSelectOptions();
    // 设置选择的文件类型为图片类型
    photoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
    // 一次只能选择一张图片
    photoSelectOptions.maxSelectNumber = 1;
    const photoViewPicker = new picker.PhotoViewPicker();
    // 拉起图库，获取选中图片的uri,并将选择图片拷贝至应用沙箱指定位置
    photoViewPicker.select(photoSelectOptions)
      .then((photoSelectResult: picker.PhotoSelectResult) => {
        // 获取选中图片的uri
        let imageUri = photoSelectResult.photoUris[0];
        console.info('photoViewPicker.select to file succeed and uris are:' + imageUri);
        let context = getContext()
        //获取应用通用文件路径
        let filesDir = context.filesDir
        let fileName = "userProfileImage"
        //获取沙箱中文件路径
        let path = filesDir + "/" + fileName + "." + imageUri.split(".")[1]
        let file = fs.openSync(imageUri, fs.OpenMode.READ_ONLY)
        let file2 = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE)
        //完成图片拷贝
        fs.copyFileSync(file.fd, file2.fd)
        fs.closeSync(file.fd)
        fs.closeSync(file2.fd)
        //获取图片沙箱路径对应的uri
        this.uri = fileUri.getUriFromPath(path)
        //获取图片对应的PixelMap
        this.getPixelMap()
      })
      .catch((err: BusinessError) => {
        console.error('MinePage', `Invoke photoViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
      })
  }

  // 获取图片的pixelmap
  getPixelMap(){
    // 通过uri打开图片文件，获取文件fd
    let file = fs.openSync(this.uri, fs.OpenMode.READ_WRITE);
    const imageSourceApi = image.createImageSource(file.fd);
    // 将图片解码为pixelmap
    imageSourceApi.createPixelMap().then(pixelmap => {
      this.profileImage = pixelmap
      console.log('Succeeded in creating pixelmap object through image decoding parameters.');
    }).catch((err:BusinessError) => {
      console.log('Failed to create pixelmap object through image decoding parameters.');
    })
  }

  build() {
    Column() {
      Image(this.profileImage)
        .alt($r('app.media.ic_user_portrait'))
        .width(108)
        .height(108)
        .objectFit(ImageFit.Cover)
        .borderRadius(54)
        .onClick(() => {
          this.pickProfile()
        })
      if (!this.uri) {
        Text('点击上传头像')
          .fontSize(24)
          .margin({ top: 10 })
      }
    }
    .alignItems(HorizontalAlign.Center)
    .justifyContent(FlexAlign.Center)
    .width('100%')
    .height('100%')
  }
}
```

## 参考
- [选择用户图片或视频类文件](../application-dev/file-management/select-user-file.md)
- [将图片解码为pixelmap](../application-dev/media/image-decoding.md)
- [@ohos.file.fs (文件管理)](../application-dev/reference/apis-core-file-kit/js-apis-file-fs.md)
- [Image](../application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-image.md)

