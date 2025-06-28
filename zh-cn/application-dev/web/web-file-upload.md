# 使用Web组件上传文件

Web组件支持前端页面选择文件上传功能，应用开发者可以使用[onShowFileSelector()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9)接口来处理前端页面文件上传的请求，如果应用开发者不做任何处理，Web会提供默认行为来处理前端页面文件上传的请求。

## 使用onShowFileSelector拉起文件管理器

下面的示例中，当用户在前端页面点击文件上传按钮，应用侧在[onShowFileSelector()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9)接口中收到文件上传请求，在此接口中开发者将上传的本地文件路径设置给前端页面。


- 应用侧代码。
  
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { picker } from '@kit.CoreFileKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: $rawfile('local.html'), controller: this.controller })
          .onShowFileSelector((event) => {
            console.log('MyFileUploader onShowFileSelector invoked');
            const documentSelectOptions = new picker.DocumentSelectOptions();
            let uri: string | null = null;
            const documentViewPicker = new picker.DocumentViewPicker();
            documentViewPicker.select(documentSelectOptions).then((documentSelectResult) => {
              uri = documentSelectResult[0];
              console.info('documentViewPicker.select to file succeed and uri is:' + uri);
              if (event) {
                event.result.handleFileList([uri]);
              }
            }).catch((err: BusinessError) => {
              console.error(`Invoke documentViewPicker.select failed, code is ${err.code}, message is ${err.message}`);
            })
            return true;
          })
      }
    }
  }
  ```


- local.html页面代码。
  
  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8">
      <title>Document</title>
  </head>

  <body>
  <!-- 点击上传文件按钮 -->
  <input type="file" value="file"></br>
  <meta name="viewport" content="width=device-width" />
  </body>
  </html>
  ```
![web-app-document](./figures/web-app-document.gif)

## 使用onShowFileSelector拉起图库

下面的示例中，当用户在前端页面点击文件上传按钮，应用侧在[onShowFileSelector()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9)接口中收到文件上传请求，在此接口中开发者将上传的本地图片路径设置给前端页面。


- 应用侧代码。
  
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { picker } from '@kit.CoreFileKit';
  import { photoAccessHelper } from '@kit.MediaLibraryKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController()

    async selectFile(result: FileSelectorResult): Promise<void> {
      let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
      let photoPicker = new photoAccessHelper.PhotoViewPicker();
      // 过滤选择媒体文件类型为IMAGE
      photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
      // 设置最大选择数量
      photoSelectOptions.maxSelectNumber = 5;
      let chooseFile: photoAccessHelper.PhotoSelectResult = await photoPicker.select(photoSelectOptions);
      // 获取选择的文件列表
      result.handleFileList(chooseFile.photoUris);
    }

    build() {
      Column() {
        Web({ src: $rawfile('local.html'), controller: this.controller })
          .onShowFileSelector((event) => {
            if (event) {
              this.selectFile(event.result);
            }
            return true;
          })
      }
    }
  }
  ```


- local.html页面代码。
  
  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8">
      <title>Document</title>
  </head>

  <body>
  <!-- 点击上传文件按钮 -->
  <input type="file" value="file"></br>
  <meta name="viewport" content="width=device-width" />
  </body>
  </html>
  ```
![web-app-photo](./figures/web-app-photo.gif)

## 使用onShowFileSelector拉起相机

Web组件支持前端页面上传图片文件时调用相机即时拍照，应用开发者可以使用[onShowFileSelector()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9)接口来处理前端页面文件上传的请求并自行拉起相机，如果应用开发者不做任何处理，Web会提供默认行为来处理前端页面调用相机的请求。

此示例中，应用侧通过监听[onShowFileSelector](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9)事件并返回`true`拦截ArkWeb默认弹窗,并调用系统CameraPicker拉起相机。
应用可以通过获取AcceptType对不同类型的目标文件做更精细的筛选。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { camera, cameraPicker } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

async function openCamera(callback: Callback<string>, uiContext: UIContext) {
  let mContext = uiContext.getHostContext() as common.Context;
  try {
    let pickerProfile: cameraPicker.PickerProfile = {
      cameraPosition: camera.CameraPosition.CAMERA_POSITION_BACK
    };
    let pickerResult: cameraPicker.PickerResult = await cameraPicker.pick(mContext,
      [cameraPicker.PickerMediaType.PHOTO, cameraPicker.PickerMediaType.VIDEO], pickerProfile);
    callback(pickerResult.resultUri);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`the pick call failed. error code: ${err.code}`);
  }
}

@Entry
@Component
struct Index {
  webviewController: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: $rawfile("webCamera.html"), controller: this.webviewController })
        .onShowFileSelector((event) => {
            //开发者可以通过event.fileSelector.getAcceptType()和event.fileSelector.isCapture()判断文件类型，并有选择地做出筛选以拉起不同的文件选择器
            openCamera((result) => {
                if (event) {
                console.log('Title is ' + event.fileSelector.getTitle());
                console.log('Mode is ' + event.fileSelector.getMode());
                console.log('Accept types are ' + event.fileSelector.getAcceptType());
                console.log('Capture is ' + event.fileSelector.isCapture());
                event.result.handleFileList([result]);
                }
            }, this.getUIContext())
            return true;
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

html页面代码
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>WebCamera</title>
</head>
<body>
    <input type="file" name="photo" id="photo"><br>
    <img style="display: none;width:200px;" id="img">
    <script>
        let photo = document.getElementById("photo");
        photo.addEventListener("change", preViewImg)

        function preViewImg(event) {
            let fileReader = new FileReader();
            let img = document.getElementById("img");
            fileReader.addEventListener(
                "load",
                () => {
                    // 将图像文件转换为 Base64 字符串
                    img.src = fileReader.result;
                },
                false,
            );
            fileReader.readAsDataURL(event.target.files[0]);
            img.style.display = "block";
        }
    </script>
</body>
</html>
```
![web-app-camera](./figures/web-app-camera.gif)

## 使用ArkWeb默认的方式处理文件上传请求

`accept` 属性是一个字符串，它定义了文件 input 应该接受的文件类型。这个字符串是一个以逗号为分隔的唯一文件类型说明符列表。由于给定的文件类型可以用多种方式指定，因此当你需要给定格式的文件时，提供一组完整的类型指定符是非常有用的。

`capture` 属性是一个字符串，如果 `accept` 属性指出了 input 是图片或者视频类型，则它指定了使用哪个摄像头去获取这些数据。值 `user` 表示应该使用前置摄像头和（或）麦克风。值 `environment` 表示应该使用后置摄像头和（或）麦克风。如果缺少此属性，则用户代理可以自由决定做什么。如果请求的前置模式不可用，则用户代理可能退回到其首选的默认模式。

当指定布尔类型属性 `multiple` 时，文件 input 允许用户选择多个文件。

示例页面内有数个文件选择器，分别设置了不同的accept及capture属性，这两个属性对相机的影响如下：

| accept                      | capture                     | 文件选择器行为                                     |
| --------------------------- | --------------------------- | -------------------------------------------------- |
| 仅包含图片类型              | 设置为"environment"或"user" | 直接拉起相机拍照模式。                             |
| 仅包含图片类型               | 不设置                      | 先拉起弹窗，用户选择拍照后拉起相机拍照模式。       |
| 仅包含视频类型              | 设置为"environment"或"user" | 直接拉起相机录像模式。                             |
| 仅包含视频类型               | 不设置                      | 先拉起弹窗，用户选择拍照后拉起相机录像模式。       |
| 包含图片和视频类型          | 设置为"environment"或"user" | 直接拉起相机拍照模式，可录像。                     |
| 包含图片和视频类型            | 不设置                      | 先拉起弹窗，用户选择拍照后拉起相机拍照模式，可录像。 |
| 不设置图片或视频类型        | 设置为"environment"或"user" | 直接拉起相机拍照模式，可录像。                     |
| 不设置图片或视频类型          | 不设置                      | 先拉起弹窗，用户选择拍照后拉起相机拍照模式，可录像。 |
| 不包含图片或视频类型        | 设置为"environment"或"user" | 直接拉起文件选择，不可拉起相机。                    |
| 不包含图片或视频类型          | 不设置                      | 直接拉起文件选择，不可拉起相机。                   |

> 当前ArkWeb识别的文件类型有
>  - 图片：tif, xbm, tiff, pjp, jfif, bmp, avif, apng, ico, webp, svg, gif, svgz, jpg, jpeg, png, pjpeg
>  - 视频：mp4, mpg, mpeg, m4v, ogm, ogv, webm

>  **说明：** 
>
> ArkWeb默认仅拉起相机后置摄像头，值 `'user'`不会被处理成拉起前置摄像头。如有需要，请在应用侧通过[onShowFileSelector()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9)接口另行处理

html页面代码
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>WebCamera</title>
</head>
<body>
    <input type="file" name="photo" id="photo" accept="image/*" capture="environment"><br>
    <input type="file" name="photo2" id="photo2" capture="environment"><br>
    <input type="file" name="picture" id="picture" accept="image/*"><br>
    <input type="file" name="none" id="none"><br>
    <img style="display: none;width:200px" id="img">
    <script>
        let photo = document.getElementById("photo");
        let photo2 = document.getElementById("photo2");
        let picture = document.getElementById("picture");
        let none = document.getElementById("none");
        photo.addEventListener("change", preViewImg)
        photo2.addEventListener("change", preViewImg)
        picture.addEventListener("change", preViewImg)
        none.addEventListener("change", preViewImg)

        function preViewImg(event) {
            let fileReader = new FileReader();
            let img = document.getElementById("img");
            fileReader.addEventListener(
                "load",
                () => {
                    // 将图像文件转换为 Base64 字符串
                    img.src = fileReader.result;
                },
                false,
            );
            fileReader.readAsDataURL(event.target.files[0]);
            img.style.display = "block";
        }
    </script>
</body>
</html>
```

应用侧代码
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  webviewController: webview.WebviewController = new webview.WebviewController()

  build() {
    Column() {
      Web({ src: $rawfile("webCamera.html"), controller: this.webviewController })
    }
    .height('100%')
    .width('100%')
  }
}
```
![web-default-camera](./figures/web-default-camera.gif)

## 常见问题

### onShowFileSelector配合ArkWeb默认弹窗使用

用户点击文件上传按钮后，程序优先执行onShowFileSelector中的回调进行逻辑处理，应用开发者可以根据处理结果选择 `return false;` ，进而拉起ArkWeb默认弹窗，此时不推荐同时拉起应用侧各Picker。

### 回调中getAcceptType和getMimeTypes的区别

getAcceptType返回的是 `accept` 属性值全量转换为文件扩展名所组成的字符串数组，getMimeTypes返回的是 `accept` 属性值用逗号拆分后所组成的字符串数组。

如若 `accept` 属性值为 `video/mp4, .png` ，则getAcceptType返回  `.mp4, .m4v; .png` ，getMimeTypes返回 `video/mp4; .png` 。

### ArkWeb默认弹窗的说明

选项“图片”会拉起图库，根据 `accept` 属性值不同，用户可以选择上传图片或视频；选项“拍照”会拉起相机，根据 `accept` 属性值不同，用户可以选择拍照或录像；选项“文件”会拉起文管，用户可以上传任意内容。