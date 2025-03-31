# 使用Web组件上传文件

## 使用onShowFileSelector处理文件上传请求

Web组件支持前端页面选择文件上传功能，应用开发者可以使用[onShowFileSelector()](../reference/apis-arkweb/ts-basic-components-web.md#onshowfileselector9)接口来处理前端页面文件上传的请求，如果应用开发者不做任何处理，Web会提供默认行为来处理前端页面文件上传的请求。


下面的示例中，当用户在前端页面点击文件上传按钮，应用侧在[onShowFileSelector()](../reference/apis-arkweb/ts-basic-components-web.md#onshowfileselector9)接口中收到文件上传请求，在此接口中开发者将上传的本地文件路径设置给前端页面。


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

## 使用Web组件实现拍照或录像

Web组件支持前端页面上传图片文件时调用相机即时拍照，应用开发者可以使用[onShowFileSelector()](../reference/apis-arkweb/ts-basic-components-web.md#onshowfileselector9)接口来处理前端页面文件上传的请求并自行拉起相机，如果应用开发者不做任何处理，Web会提供默认行为来处理前端页面调用相机的请求。

### 通过ArkWeb默认的方式拉起相机

示例页面内有数个文件选择器，分别设置了不同的accept及capture属性，这两个属性对相机的影响如下：

| accept                      | capture                     | 文件选择器行为                                     |
| --------------------------- | --------------------------- | -------------------------------------------------- |
| 仅包含图片类型              | 设置为"environment"或"user" | 直接拉起相机拍照模式                               |
|                             | 不设置                      | 先拉起弹窗，用户选择拍照后拉起相机拍照模式         |
| 仅包含视频类型              | 设置为"environment"或"user" | 直接拉起相机录像模式                               |
|                             | 不设置                      | 先拉起弹窗，用户选择拍照后拉起相机录像模式         |
| 包含图片和视频类型          | 设置为"environment"或"user" | 直接拉起相机拍照模式，可录像                       |
|                             | 不设置                      | 先拉起弹窗，用户选择拍照后拉起相机拍照模式，可录像 |
| 不设置/不包含图片或视频类型 | 设置为"environment"或"user" | 直接拉起相机拍照模式，可录像                       |
|                             | 不设置                      | 直接拉起文件选择，不可拉起相机                     |

> 当前ArkWeb识别的文件类型有
>  - 图片：tif, xbm, tiff, pjp, jfif, bmp, avif, apng, ico, webp, svg, gif, svgz, jpg, jpeg, png, pjpeg
>  - 视频：mp4, mpg, mpeg, m4v, ogm, ogv, webm

>  **注意：** ArkWeb默认仅拉起相机后置摄像头，`'user'`属性不会被处理成拉起前置摄像头。如有需要，请在应用侧通过[onShowFileSelector()](../reference/apis-arkweb/ts-basic-components-web.md#onshowfileselector9)接口另行处理

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

### 应用侧拦截系统弹窗并自行拉起相机

此示例中，应用侧通过监听[onShowFileSelector](../reference/apis-arkweb/ts-basic-components-web.md#onshowfileselector9)事件并返回`true`拦截ArkWeb默认弹窗,并调用系统CameraPicker拉起相机。
应用可以通过获取AcceptType对不同类型的目标文件做更精细的筛选。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { camera, cameraPicker } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let mContext = getContext(this) as common.Context;

async function openCamera(callback: Callback<string>) {
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
  webviewController: webview.WebviewController = new webview.WebviewController()

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
            })
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
