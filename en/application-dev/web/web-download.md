# Downloading Files

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=df43b8cd7284167bf41a7a5f049ab6572e368164 translatedAt=2026-08-14T03:45:16.043Z pushedAt=2026-08-14T08:05:27.403Z -->

To download files on the web page, you can use the following method to invoke the web APIs.

## Listening for Downloads Initiated from Pages

Call [setDownloadDelegate()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#setdownloaddelegate11) to register a **DownloadDelegate** object with the **Web** component to listen for downloads initiated from pages. While the **Web** component downloads resources as requested, it notifies the application of the download progress through the **DownloadDelegate** object.

In the following example, create index.html in the rawfile directory of the app. After the app starts, a Web component is created and loads index.html. Click the setDownloadDelegate button to register a DownloadDelegate with the Web component. When the download button on the page is tapped, a download task is triggered, and the download progress can be listened for in DownloadDelegate.

By default, the download path is in the web directory of the application sandbox and cannot be viewed by users. If users need to view it, change the download path to a directory with access permission, for example, the **Download** directory. For details, see [Initiating a Download Task](#initiating-a-download-task).

<!-- @[download_delegate](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ManageWebPageFileIO/entry/src/main/ets/pages/ListenForPageDown.ets) -->

``` TypeScript
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  @State myText: string = 'download';

  build() {
    Column() {
      Text(this.myText)
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.info('will start a download.');
              // Pass in a download path and start the download.
              // If the path is invalid, the file will be downloaded to the default directory at /data/storage/el2/base/cache/web/.
              webDownloadItem.start('/data/storage/el2/base/cache/web/' + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              // Unique ID of a download task.
              console.info('download update guid: ' + webDownloadItem.getGuid());
              // Download progress.
              console.info('download update percent complete: ' + webDownloadItem.getPercentComplete());
              // Current download speed.
              console.info('download update speed: ' + webDownloadItem.getCurrentSpeed());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.error('download failed guid: ' + webDownloadItem.getGuid());
              // Error code of a download task failure.
              console.error('download failed last error code: ' + webDownloadItem.getLastErrorCode());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.info('download finish guid: ' + webDownloadItem.getGuid());
              this.myText = 'download finish';
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(
              `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }
}
```

HTML file to be loaded:

```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<body>
<!-- Tapping the download button in the menu at the bottom right of the video triggers a download task. -->
<video controls="controls" width="800px" height="580px"
       src="http://vjs.zencdn.net/v/oceans.mp4"
       type="video/mp4">
</video>
<a href='data:text/html,%3Ch1%3EHello%2C%20World%21%3C%2Fh1%3E' download='download.html'>Download the download.html</a>
</body>
</html>
```

## Initiating a Download Task

Call [startDownload()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#startdownload11) to initiate a download task.

For a download initiated by it, the **Web** component works out the referrer based on the currently displayed URL and its own default referrer policy.

In the following example, click setDownloadDelegate to register a listening class with the web, and then click startDownload to initiate a download task. The download task notifies the app of the download progress through DownloadDelegate.

<!-- @[init_download_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ManageWebPageFileIO/entry/src/main/ets/pages/InitiatingADownloadTask.ets) -->

``` TypeScript
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  @State myText: string = 'download';

  build() {
    Column() {
      Text(this.myText)
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.info('will start a download.');
              // Pass in a download path and start the download.
              // If the path is invalid, the file will be downloaded to the default directory at /data/storage/el2/base/cache/web/.
              webDownloadItem.start('/data/storage/el2/base/cache/web/' + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.info('download update guid: ' + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.error('download failed guid: ' + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.info('download finish guid: ' + webDownloadItem.getGuid());
              this.myText = 'download finish';
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(
              `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            // The specified download address here is https://www.example.com/. 
            // Replace it with the URL from which you want to download files.
            this.controller.startDownload('https://www.example.com/');
          } catch (error) {
            console.error(
              `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

Use [DocumentViewPicker()](../reference/apis-core-file-kit/js-apis-file-picker.md#documentviewpicker) to obtain the default download directory and set it as the download directory.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { picker, fileUri } from  '@kit.CoreFileKit';
@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.info("will start a download.");
              // Use DocumentViewPicker() to obtain the default download directory and set it as the download directory.
              getDownloadPathFromPicker().then((downloadPath) => {
                webDownloadItem.start(downloadPath + '/' + webDownloadItem.getSuggestedFileName());
              });

            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              // Unique ID of a download task.
              console.info("download update guid: " + webDownloadItem.getGuid());
              // Download progress.
              console.info("download update percent complete: " + webDownloadItem.getPercentComplete());
              // Current download speed.
              console.info("download update speed: " + webDownloadItem.getCurrentSpeed())
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.error("download failed guid: " + webDownloadItem.getGuid());
              // Error code of a download task failure.
              console.error("download failed last error code: " + webDownloadItem.getLastErrorCode());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.info("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
    }
  }

}
function getDownloadPathFromPicker(): Promise<string> {
  return new Promise<string>(resolve => {
    try {
      const documentSaveOptions = new picker.DocumentSaveOptions();
      documentSaveOptions.pickerMode = picker.DocumentPickerMode.DOWNLOAD
      const documentPicker = new picker.DocumentViewPicker();
      documentPicker.save(documentSaveOptions).then(async (documentSaveResult: Array<string>) => {
        if (documentSaveResult.length <= 0) {
          resolve('');
          return;
        }
        const uriString = documentSaveResult[0];
        if (!uriString) {
          resolve('');
          return;
        }
        const uri = new fileUri.FileUri(uriString);
        resolve(uri.path);
      }).catch((err: BusinessError) => {
        console.error(`ErrorCode: ${err.code},  Message: ${err.message}`);
        resolve('');
      });
    } catch (error) {
      resolve('');
    }
  })
}
```

> **NOTE**
>
>Call [WebDownloadItem.start](../reference/apis-arkweb/arkts-apis-webview-WebDownloadItem.md#start11) to specify the path for storing downloaded files.
>
>Note that **WebDownloadItem.start** does not start the download. The download process starts when the user clicks the page link. **WebDownloadItem.start** is used to move the content that has been downloaded to the temporary directory (**/data/storage/el2/base/cache/web/Temp/**) to the specified path, and directly save the remaining content to the specified path. Call[WebDownloadItem.cancel](../reference/apis-arkweb/arkts-apis-webview-WebDownloadItem.md#cancel11) to cancel the current download task. In this case, the temporary file is deleted.
>
>If you do not want to download the file to the temporary directory before **WebDownloadItem.start**, you can also use **WebDownloadItem.cancel** to interrupt the download. In addition, the interrupted download can be resumed using [WebDownloadManager.resumeDownload](../reference/apis-arkweb/arkts-apis-webview-WebDownloadManager.md#resumedownload11).

## Resuming Unfinished Download Tasks Due to Process Exit

When the **Web** component is started, you can resume the unfinished download task through the [resumeDownload()](../reference/apis-arkweb/arkts-apis-webview-WebDownloadManager.md#resumedownload11) API.

In the following example, the **record** button is used to save the current download task to a persistent file. After the application is restarted, the **recovery** button can be used to resume the persistent download task. If multiple download tasks need to be saved, the application can adjust the persistence time and mode as required.

<!-- @[recovery_download_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ManageWebPageFileIO/entry/src/main/ets/pages/ResumeDownload.ets) -->

``` TypeScript
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { DownloadUtil, fileName, filePath } from './downloadUtil'; // downloadUtil.ets is described below.

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  // Used to record failed download tasks.
  failedData: Uint8Array = new Uint8Array();

  aboutToAppear(): void {
    DownloadUtil.init(this.getUIContext());
  }

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.info('will start a download.');
              // Pass in a download path and start the download.
              // If the path is invalid, the file will be downloaded to the default directory at /data/storage/el2/base/cache/web/.
              webDownloadItem.start('/data/storage/el2/base/cache/web/' + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.info('download update percent complete: ' + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.error('download failed guid: ' + webDownloadItem.getGuid());
              // Serialize the failed download task to a byte array.
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.info('download finish guid: ' + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
            webview.WebDownloadManager.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(
              `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            // The specified download address here is https://www.example.com/. 
            // Replace it with the URL from which you want to download files.
            this.controller.startDownload('https://www.example.com/');
          } catch (error) {
            console.error(
              `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      // Serialize and save the current download task information for subsequent download task resumption.
      // This example shows the one-task download scenario. For multiple download tasks, extend the code as required.
      Button('record')
        .onClick(() => {
          try {
            // Save the downloaded data to a persistent file.
            DownloadUtil.saveDownloadInfo(DownloadUtil.uint8ArrayToStr(this.download.serialize()));
          } catch (error) {
            console.error(
              `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      // Resume the download task from the serialized download task information.
      // Ensure that the WebDownloadManager.setDownloadDelegate setting is complete when the button is triggered.
      Button('recovery')
        .onClick(() => {
          try {
            // The persistence file is available by default. You can set it as required.
            let webDownloadItem =
              webview.WebDownloadItem.deserialize(
                DownloadUtil.strToUint8Array(DownloadUtil.readFileSync(filePath, fileName)));
            webview.WebDownloadManager.resumeDownload(webDownloadItem);
          } catch (error) {
            console.error(
              `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

Download the task information persistence utility file.

<!-- @[task_info_persistence_util](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/ManageWebPageFileIO/entry/src/main/ets/pages/downloadUtil.ets) -->    

``` TypeScript
import { util } from '@kit.ArkTS';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

const helper = new util.Base64Helper();

export let filePath : string;
export const fileName = 'demoFile.txt';
export namespace  DownloadUtil {
  
  export function init(context: UIContext): void {
    filePath = context.getHostContext()!.filesDir;
  }

  export function uint8ArrayToStr(uint8Array: Uint8Array): string {
    return helper.encodeToStringSync(uint8Array);
  }

  export function strToUint8Array(str: string): Uint8Array {
    return helper.decodeSync(str);
  }

  export function saveDownloadInfo(downloadInfo: string): void {
    if (!fileExists(filePath)) {
      mkDirectorySync(filePath);
    }

    writeToFileSync(filePath, fileName, downloadInfo);
  }

  export function fileExists(filePath: string): boolean {
    try {
      return fileIo.accessSync(filePath);
    } catch (error) {
      return false;
    }
  }

  export function mkDirectorySync(directoryPath: string, recursion?: boolean): void {
    try {
      fileIo.mkdirSync(directoryPath, recursion ?? false);
    } catch (error) {
      console.error(`mk dir error. err message: ${error.message}, err code: ${error.code}`);
    }
  }

  export function writeToFileSync(dir: string, fileName: string, msg: string): void {
    let file: fileIo.File | null = null;
    try {
      file = fileIo.openSync(dir + '/' + fileName, fileIo.OpenMode.WRITE_ONLY | fileIo.OpenMode.CREATE);
      fileIo.writeSync(file.fd, msg);
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
    } finally {
      if (file) {
        fileIo.closeSync(file);
      }
    }
  }

  export function readFileSync(dir: string, fileName: string): string {
    try {
      return fileIo.readTextSync(dir + '/' + fileName);
    } catch (error) {
      console.error(`ErrorCode: ${(error as BusinessError).code}, Message: ${(error as BusinessError).message}`);
      return '';
    }
  }

}
```