# 如何转换图片格式

## 场景说明
当我们获取到图片或者视频的缩略图后，返回的是pixelMap，此时有开发者会有疑问如何将pixelMap转换成jpeg等其他格式的图片，其实使用image类中的packing方法就可以将pixelMap重新打包成新的格式（当前只支持jpeg，webp格式），再使用文件管理就可以将图片存入到应用的沙箱路径。本例即为大家介绍如何完成图片格式转换。

## 运行环境
本例基于以下环境开发，开发者也可以基于其他适配的版本进行开发：

- IDE: DevEco Studio 4.0 Beta1
- SDK: Ohos_sdk_public 4.0.7.5 (API Version 10 Beta1)

## 效果呈现
本例最终实现效果为：将工程资源文件中png格式的图片转换为jpg格式，并保存在设备中。由于本例不涉及UI讲解，所以不在此提供UI效果。

## 实现思路
本例中完成图片格式转换包含三个关键步骤，相关步骤及实现方案如下：
- 获取到要转换图片的PixelMap数据：使用image的createPixelMap方法获取到图片的PixelMap数据。
- 将图片的PixelMap重新打包转换为其他格式：使用packing方法进行打包，打包时可以设置格式、压缩质量等。
- 将重新打包好的图片保存到应用目录：使用图库选择器photoViewPicker的相关功能以及file读写操作完成图片的保存。

## 开发步骤
由于本例重点讲解图片格式的转换，所以开发步骤会着重讲解相关实现，不相关的内容不做介绍，全量代码可参考完整代码章节。
1. 获取要转换图片的PixelMap数据。

    先通过上下文context获取到资源管理器resourceManager，然后通过资源管理器获取到图片数据，然后获取图片的ArrayBuffer，最后通过ArrayBuffer创建imageSource，获取到pixelMap，完成图片解码。

    具体代码如下：
    ```ts
    import common from '@ohos.app.ability.common';

    @Entry
    @Component
    struct Index {
      ...
      context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext
      ...

      async getPixelMap(){
        // 获取resourceManager资源管理
        const resourceMgr = this.context.resourceManager
        // 获取rawfile文件夹下imagetransfer.PNG的ArrayBuffer
        const fileData = await resourceMgr.getMediaContent($r('app.media.imagetransfer'))
        const buffer = fileData.buffer
        // 创建imageSource
        const imageSource = image.createImageSource(buffer)
        // 获取PixelMap
        const pixelMap = await imageSource.createPixelMap()
        return pixelMap
      }
      ...
    }
    ```
2. 将图片的PixelMap重新打包转换为其他格式。

    先通过createImagePacker构建ImagePacker实例，再通过该实例调用packing方法进行打包，打包时传入获取到的PixelMap数据及重新打包的图片格式等相关配置信息。
    具体代码如下：
    ```ts
    ...
    @State src:PixelMap = undefined
    ...
    // 页面加载前将获取到的图片PixelMap数据赋值给状态变量src
    async aboutToAppear() {
      this.src = await this.getPixelMap()
    }
    ...
    // 创建ImagePacker实例
    let imagePackerApi = image.createImagePacker();
    let options = {
      // 设置重新打包的图片格式
      format: 'image/jpeg',
      quality: 98
    };
    // 打包时传入图片的PixelMap：src和图片打包选项：option，异步获取打包后的数据data
    imagePackerApi.packing(this.src, options).then((data) => {
      console.log('Succeeded in packing the image.');
      }).catch(error => {
      console.log('Failed to pack the image..');
      ....
    })
    ```
3. 将重新打包好的图片保存到应用目录。

    使用图库选择器photoViewPicker保存文件，保存时可以在保存界面选择保存路径并设定文件名。此时保存的是空文件，然后再使用file将重新打包的图片数据写入保存的文件中，保存完成后我们便可以在保存路径下找到转换格式后的图片文件了。
    具体代码如下：
    ```ts
    ...
    // 打包时传入图片的pixelmap：src和图片打包选项：option，异步获取打包后的数据data
    imagePackerApi.packing(this.src, options).then((data) => {
      // 创建文件管理器保存选项实例
      let photoSaveOptions = new picker.PhotoSaveOptions();
      // 保存文件名（可选）
      photoSaveOptions.newFileNames = ["imageTransfer.jpg"];
      let photoViewPicker = new picker.PhotoViewPicker();

      // 保存时传入保存的文件名：photoSaveOptions
      photoViewPicker.save(photoSaveOptions)
        .then((photoSaveResult) => {
          setTimeout(() => {
            // 获取到保存文件的URI，后续进行文件读取等操作
            this.uri = photoSaveResult[0];

            fs.open(this.uri, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE).then((file) => {
              // 将图片打包数据data写入保存的文件
              fs.write(file.fd, data).then((number) => {
                console.info("foo imagetest: write data to file succeed and size is:" + number);
              }).catch((err) => {
                console.info("foo imagetest: write data to file failed with error:" + err);
              });
              // 完成文件写入后，关闭文件
              fs.close(file, (err) => {
                if (err) {
                  console.info("close file failed with error message: " + err.message + ", error code: " + err.code);
                } else {
                  console.info("close file success");
                }
              });
            }).catch((err) => {
              console.info("foo open file failed with error message: " + err.message + ", error code: " + err.code);
            });

          }, 200)

        })
        .catch((err) => {
          console.error('PhotoViewPicker.save failed with err: ' + err);
        })
    })
    ...
    ```
## 完整代码
本例完整代码如下：
```ts
import image from '@ohos.multimedia.image';
import fs from '@ohos.file.fs';
import common from '@ohos.app.ability.common';
import picker from '@ohos.file.picker';

@Entry
@Component
struct Index {
  @State src:PixelMap = undefined
  context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext
  private  uri = null
  // 页面加载前将获取到的图片PixelMap数据赋值给状态变量src
  async aboutToAppear() {
    this.src = await this.getPixelMap()
  }

  async getPixelMap(){
    // 获取resourceManager资源管理
    const resourceMgr = this.context.resourceManager
    // 获取rawfile文件夹下httpimage.PNG的ArrayBuffer
    const fileData = await resourceMgr.getMediaContent($r('app.media.contact6'))
    const buffer = fileData.buffer
    // 创建imageSource
    const imageSource = image.createImageSource(buffer)
    // 创建PixelMap
    const pixelMap = await imageSource.createPixelMap()
    return pixelMap
    console.log('pixelMap  ' + JSON.stringify(this.src.getPixelBytesNumber()))
  }

  build() {
    Row() {
      Column() {
        Button('转换图片格式：png->jpeg')
          .onClick(() => {
            // 创建ImagePacker实例
            let imagePackerApi = image.createImagePacker();
            // 设置重新打包的图片格式，及图片压缩质量
            let options = {
              format: 'image/jpeg',
              quality: 98
            };
            // 打包时传入图片的pixelmap：src和图片打包选项：option，异步获取打包后的数据data
            imagePackerApi.packing(this.src, options).then((data) => {
              // 创建文件管理器保存选项实例
              let photoSaveOptions = new picker.PhotoSaveOptions();
              // 保存文件名（可选）
              photoSaveOptions.newFileNames = ["imageTransfer.jpg"];
              let photoViewPicker = new picker.PhotoViewPicker();
              // 保存时传入保存的文件名：photoSaveOptions
              photoViewPicker.save(photoSaveOptions)
                .then((photoSaveResult) => {
                  console.log('foo start')
                  setTimeout(() => {
                    // 获取到图片的URI后进行文件读取等操作
                    this.uri = photoSaveResult[0];
                    fs.open(this.uri, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE).then((file) => {
                      // 将图片打包数据data写入保存的文件
                      fs.write(file.fd, data).then((number) => {
                        console.info("foo imagetest: write data to file succeed and size is:" + number);
                      }).catch((err) => {
                        console.info("foo imagetest: write data to file failed with error:" + err);
                      });
                      // 完成文件写入后，关闭文件
                      fs.close(file, (err) => {
                        if (err) {
                          console.info("close file failed with error message: " + err.message + ", error code: " + err.code);
                        } else {
                          console.info("close file success");
                        }
                      });
                    }).catch((err) => {
                      console.info("foo open file failed with error message: " + err.message + ", error code: " + err.code);
                    });
                  }, 200)
                })
                .catch((err) => {
                  console.error('PhotoViewPicker.save failed with err: ' + err);
                })
            })
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## 参考
- [@ohos.multimedia.image (图片处理)](../application-dev/reference/apis-image-kit/js-apis-image.md)
- [@ohos.file.fs (文件管理)](../application-dev/reference/apis-core-file-kit/js-apis-file-fs.md)
- [@ohos.file.picker (选择器)](../application-dev/reference/apis-core-file-kit/js-apis-file-picker.md)