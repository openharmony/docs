# Uploading Files

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=f0524ade16836279b29e1c928b6b7514bb1a1dfd translatedAt=2026-08-14T03:46:08.894Z pushedAt=2026-08-14T08:26:13.828Z -->

The **Web** component supports file upload from the frontend page. You can use the [onShowFileSelector()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9) API to handle the file upload request from the frontend page. If you do not handle it, ArkWeb provides a default behavior to process the file upload request from the frontend page. You can also customize the Picker to be invoked based on the obtained frontend data.

## Starting File Manager Using onShowFileSelector

In the following example, when a user clicks the **Upload** button on the frontend page, the application receives a file upload request through [onShowFileSelector()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9), which carries the path of the local file to be uploaded.

- Application code:

<!-- @[web_file_upload](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ManageWebPageFileIO/entry/src/main/ets/pages/UploadFiles.ets) -->

``` TypeScript
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
          console.info('MyFileUploader onShowFileSelector invoked');
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

- Code of the **local.html** page:

  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width" />
      <title>Document</title>
  </head>

  <body>
  <!-- Click the Upload button -->
  <input type="file"><br>
  </body>
  </html>
  ```

![web-app-document](./figures/web-app-document.gif)

## Starting Gallery Using onShowFileSelector

In the following example, when a user clicks the **Upload** button on the frontend page, the application receives a file upload request through [onShowFileSelector()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9), which carries the path of the local image to be uploaded.

- Application code:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { photoAccessHelper } from '@kit.MediaLibraryKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    async selectFile(result: FileSelectorResult): Promise<void> {
      let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
      let photoPicker = new photoAccessHelper.PhotoViewPicker();
      // Set the mime file type to IMAGE_VIDEO.
      photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_VIDEO_TYPE;
      // Set the maximum number of media files that can be selected.
      photoSelectOptions.maxSelectNumber = 5;
      let chooseFile: photoAccessHelper.PhotoSelectResult = await photoPicker.select(photoSelectOptions);
      // Obtain the list of selected files.
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

- Code of the **local.html** page:

  ```html
  <!DOCTYPE html>
  <html>
  <head>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width" />
      <title>Document</title>
  </head>

  <body>
  <!-- Click the Upload button -->
  <input type="file"><br>
  </body>
  </html>
  ```

![web-app-photo](./figures/web-app-photo.gif)

## Starting Camera Using onShowFileSelector

The **Web** component supports invoking the camera to take photos immediately when the frontend page uploads image files. You can use the [onShowFileSelector()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9) API to handle the file upload request from the frontend page and invoke the camera on your own. If you do not handle it, ArkWeb provides a default behavior to process the request from the frontend page to invoke the camera.

In this example, the application listens for the [onShowFileSelector](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9) event and returns `true` to intercept the default ArkWeb dialog, and then calls the system CameraPicker to invoke the camera. The application can obtain AcceptType to perform finer filtering on different types of target files.

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
            //You can use event.fileSelector.getAcceptType() and event.fileSelector.isCapture() to determine the file type and filter files to start different file selectors.
            openCamera((result) => {
                if (event) {
                console.info('Title is ' + event.fileSelector.getTitle());
                console.info('Mode is ' + event.fileSelector.getMode());
                console.info('Accept types are ' + event.fileSelector.getAcceptType());
                console.info('Capture is ' + event.fileSelector.isCapture());
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

HTML page code:

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
                    // Convert the image file into a Base64 string.
                    img.src = fileReader.result;
                    img.style.display = "block";
                },
                false
            );
            if (event.target.files && event.target.files[0]) {
              fileReader.readAsDataURL(event.target.files[0]);
            } else {
              console.error("File not exist.");
            }            
        }
    </script>
</body>
</html>
```

![web-app-camera](./figures/web-app-camera.gif)

## Processing File Upload Requests Using the Default ArkWeb Mode

The `accept` attribute is a string that defines the file types that the file `input` should accept. This string is a comma-separated list of unique file type specifiers. Because a given file type can be specified in multiple ways, it is useful to provide a complete set of type specifiers when you need files of a given format.

The `capture` attribute is a string that specifies which camera to use to obtain the data if the `accept` attribute indicates that the input is an image or video type. The value `user` indicates that the front camera and/or microphone should be used. The value `environment` indicates that the rear camera and/or microphone should be used. If this attribute is absent, the user agent is free to decide what to do. If the requested front mode is unavailable, the user agent may fall back to its preferred default mode.

When the Boolean type attribute `multiple` is specified, the file `input` allows users to select multiple files.

The sample page includes multiple file selectors, each with different **accept** and **capture** attributes. The impact of these attributes on the camera is as follows:

| accept                      | capture                     | Behavior of the File Selector                                    |
| --------------------------- | --------------------------- | -------------------------------------------------- |
| Only the image type             | **environment** or **user**| Starts the camera to take photos.                            |
| Only the image type              | Unspecified                     | Starts a dialog box. After the user chooses to take a photo, the camera is started to take a photo.      |
| Only the video type             | **environment** or **user**| Starts the camera to record videos.                            |
| videos only               | Unspecified                      | Starts a dialog box. After the user selects video recording, the camera video recording mode is invoked.       |
| Image and video types         | **environment** or **user**| Starts the camera to take photos and record videos.                    |
| Image and video types           | Unspecified                     | Starts a dialog box. After the user chooses to take a photo, the camera is started to take photos and record videos.|
| Unspecified       | **environment** or **user**| Starts the camera to take photos and record videos.                    |
| Unspecified         | Unspecified                     | Starts a dialog box. After the user chooses to take a photo, the camera is started to take photos and record videos.|
| Image and video types are excluded       | **environment** or **user**| Starts the file selection, but not the camera.                   |
| Image and video types are excluded         | Unspecified                     | Starts the file selection, but not the camera.                  |

> Currently, ArkWeb can identify the following file types:
>  - Image: tif, xbm, tiff, pjp, jfif, bmp, avif, apng, ico, webp, svg, gif, svgz, jpg, jpeg, png, pjpeg
>  - Video: mp4, mpg, mpeg, m4v, ogm, ogv, webm

>  **NOTE**
>
> By default, ArkWeb invokes only the rear camera. The value `'user'` is not processed as invoking the front camera. If needed, handle it separately on the application side through the [onShowFileSelector()](../reference/apis-arkweb/arkts-basic-components-web-events.md#onshowfileselector9) API.

HTML page code:

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>WebCamera</title>
</head>
<body>
    <input type="file" name="picture" id="picture" accept="image/*"><br>
    <img style="display: none;width:200px" id="img">
    <script>
        let picture = document.getElementById("picture");
        picture.addEventListener("change", preViewImg)

        function preViewImg(event) {
            let fileReader = new FileReader();
            let img = document.getElementById("img");
            fileReader.addEventListener(
                "load",
                () => {
                    // Convert the image file into a Base64 string.
                    img.src = fileReader.result;
                    img.style.display = "block";
                },
                false
            );
            if (event.target.files && event.target.files[0]) {
              fileReader.readAsDataURL(event.target.files[0]);
            } else {
              console.error("File not exist.");
            }    
        }
    </script>
</body>
</html>
```

Code on the application side:

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct Index {
  webviewController: webview.WebviewController = new webview.WebviewController();

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

## Custom Processing of File Requests Invoked by JS APIs

Since API version 23, the **getSuggestedName()**, **getDefaultPath()**, **getDescriptions()**, and **isAcceptAllOptionExcluded()** APIs are added to **FileSelectorParam** of **OnShowFileSelectorEvent**.

The new APIs enhance the file upload and save capabilities to align with W3C capabilities, so that users can obtain the data in the `option` parameter passed by the HTML frontend through methods such as `showSaveFilePicker`, `showOpenFilePicker`, and `showDirectoryPicker` (see the HTML file loaded below).

Since API version 23, the following members of **option** are added:

`suggestedName` corresponds to the [getSuggestedName](../reference/apis-arkweb/arkts-basic-components-web-FileSelectorParam.md#getsuggestedname23) API.

**description**: corresponds to the [getDescriptions](../reference/apis-arkweb/arkts-basic-components-web-FileSelectorParam.md#getdescriptions23) API.

**excludeAcceptAllOption**: corresponds to the [isAcceptAllOptionExcluded](../reference/apis-arkweb/arkts-basic-components-web-FileSelectorParam.md#isacceptalloptionexcluded23) API.

**startIn**: corresponds to the [getDefaultPath](../reference/apis-arkweb/arkts-basic-components-web-FileSelectorParam.md#getdefaultpath23) API.

**types**: corresponds to the [getAcceptableFileTypes](../reference/apis-arkweb/arkts-basic-components-web-FileSelectorParam.md#getacceptablefiletypes23) API.

Code of the **index.html** page:

```html
<!DOCTYPE html>
<html>
<head>
    <title>File saving test</title>
</head>
<body>
<button onclick="saveFile()">Save File</button>
<div id="result"></div>

<script>
    async function saveFile() {
        const options = {
            startIn: 'documents',
            suggestedName: 'example.txt',
            types: [
                {
                    description: 'Text file',
                    accept: {'text/plain': ['.txt','.text','.doc','.docx'],
                             'video/mp4': ['.mp4','.avi','.av1','.vp9']}
                },
                {
                    description: 'Video',
                    accept: {'video/mp4': ['.mp4','.avi','.av1','.vp9']}
                }
            ],
            excludeAcceptAllOption: true
        };

        try {
            const fileHandle = await window.showSaveFilePicker(options);
        } catch (error) {
            if (error.name !== 'AbortError') {
                document.getElementById('result').innerHTML =
                    'Error: ${error.message}`;
            }
        }
    }
</script>
</body>
</html>
```

Application code:

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { picker } from '@kit.CoreFileKit';
let defaultPublicPath = 'storage/Users/currentUser/';
let defaultBasePath = 'file://docs/';
let wellKnownDirectoryMap = new Map<string, string>([
    ['desktop', defaultPublicPath + 'desktop'],
    ['documents', defaultPublicPath + 'documents'],
    ['downloads', defaultPublicPath + 'download'],
    ['music', defaultPublicPath + 'music'],
    ['pictures', defaultPublicPath + 'images'],
    ['videos', defaultPublicPath + 'videos'],
]);

function getUri(path : string) {
  let publicDir = wellKnownDirectoryMap.get(path);
  if (publicDir !== undefined) {
    path = publicDir;
  }
  return defaultBasePath + path;
}

function getFileName(name : string) {
  let fileName = name;
  let lastDotIndex = name.lastIndexOf('.');
  if (lastDotIndex !== -1) {
    fileName = name.substring(0, lastDotIndex);
  }
  return fileName;
}

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .onShowFileSelector((event) => {
          console.info('onShowFileSelector Suggested Name is ' + event.fileSelector.getSuggestedName());
          console.info('onShowFileSelector Default Path is ' + event.fileSelector.getDefaultPath());
          console.info('onShowFileSelector Descriptions are ' + event.fileSelector.getDescriptions());
          console.info('onShowFileSelector AcceptAllOptionExcluded is ' + event.fileSelector.isAcceptAllOptionExcluded());
          const documentSaveOptions = new picker.DocumentSaveOptions();
          documentSaveOptions.newFileNames = new Array<string>();
          documentSaveOptions.newFileNames.push(getFileName(event.fileSelector.getSuggestedName()));
          documentSaveOptions.defaultFilePathUri = getUri(event.fileSelector.getDefaultPath());
          let accepts : Array<Array<AcceptableFileType>> = event.fileSelector.getAcceptableFileTypes();
          let descriptions : Array<string> = event.fileSelector.getDescriptions();
          documentSaveOptions.fileSuffixChoices = new Array<string>();
          let n = accepts.length;
          for (let i = 0; i < n; i++) {
            let m = accepts[i].length;
            let extList = Array<string>();
            for (let j = 0; j < m; j++) {
              extList.push(accepts[i][j].acceptableType.join(','));
            }
            let ext = extList.join(',');
            let desc = descriptions[i] + '(' + ext + ')' + '|';
            documentSaveOptions.fileSuffixChoices.push(desc + ext);
          }
          if (!event.fileSelector.isAcceptAllOptionExcluded()) {
            documentSaveOptions.fileSuffixChoices.push('All files(*.*)' + '|' + '*.*');
          }
          let uri: string | null = null;
          const documentViewPicker = new picker.DocumentViewPicker();
          documentViewPicker.save(documentSaveOptions).then((documentSelectResult) => {
            uri = documentSelectResult[0];
            console.info('documentViewPicker.save to file succeed and uri is:' + uri);
            if (event) {
              event.result.handleFileList([uri]);
            }
          }).catch((err: BusinessError) => {
            console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
          })
          return true;
        })
    }
  }
}
```

![web-custom-mode-file-picker.gif](./figures/web-custom-mode-file-picker.gif)

The sample uses `showSaveFilePicker()` in HTML together with the `documentViewPicker.save()` method in ArkTS as an example.

**NOTE**

1. The input parameter **option** of **showOpenFilePicker** and **showDirectoryPicker** in HTML has different members from that of **showSaveFilePicker**.

2. In ETS, when calling the [`documentViewPicker.select()`](../reference/apis-core-file-kit/js-apis-file-picker.md#select) method, pass parameters to the Picker with the [`picker.DocumentSelectOptions`](../reference/apis-core-file-kit/js-apis-file-picker.md#documentselectoptions) object instead of the [`picker.DocumentSaveOptions`](../reference/apis-core-file-kit/js-apis-file-picker.md#documentsaveoptions) object. For details, see [@ohos.file.picker (Picker)](../reference/apis-core-file-kit/js-apis-file-picker.md).

## FAQs

### How to use onShowFileSelector together with the default ArkWeb dialog box?

After the user taps the file upload button, the program first executes the callback in onShowFileSelector for logic processing. Based on the processing result, you can choose to return `false` to trigger the default ArkWeb dialog. In this case, avoid triggering other Pickers on the application side at the same time. If you choose to return `true`, the default ArkWeb dialog is intercepted and only the custom behavior is executed.

### What are the differences between getAcceptType and getMimeTypes in the callback?

getAcceptType returns a string array consisting of the file name extensions converted from the full `accept` attribute value. getMimeTypes returns a string array consisting of the `accept` attribute value split by commas.

If the value of the `accept` attribute is `video/mp4, .png`, getAcceptType returns `.mp4, .m4v; .png`, and getMimeTypes returns `video/mp4; .png`.

### What is the default ArkWeb dialog box used for?

The **Images** option invokes the gallery. Depending on the value of the `accept` attribute, users can select images or videos to upload. The **Camera** option invokes the camera. Depending on the value of the `accept` attribute, users can take photos or record videos. The **Files** option invokes the file manager, and users can upload any content.

### How to use handleFileList?

This function submits the selected file path to ArkWeb. The input parameters are of two types.

1. File protocol paths. Currently, only public paths prefixed with `file://media/` and `file://docs/` and application package name paths in the form of `file://<packageName>/` are supported. Other file protocol paths have no permission.

2. Sandbox directory. For details, see [Application Sandbox](../file-management/app-sandbox-directory.md).