# Downloading Files

> **NOTE**
>
>To use the download function of the **Web** component, the application needs to invoke **WebDownloadItem.start** to specify the path for saving the downloaded file. Note that **WebDownloadItem.start** does not start the download. The download process starts when the user clicks the page link. **WebDownloadItem.start** is used to move the content that has been downloaded to the temporary directory (**/data/storage/el2/base/cache/web/Temp/**) to the specified path, and directly save the remaining content to the specified path. To cancel the current download, you can invoke **WebDownloadItem.cancel**. In this case, the temporary file is deleted.
>
>If you do not want to download the file to the temporary directory before **WebDownloadItem.start**, you can also use **WebDownloadItem.cancel** to interrupt the download. In addition, the interrupted download can be resumed by using [WebDownloadManager.resumeDownload](../reference/apis-arkweb/js-apis-webview.md#resumedownload11).

## Listening for Downloads Initiated from Pages

Call [setDownloadDelegate()](../reference/apis-arkweb/js-apis-webview.md#setdownloaddelegate11) to register a **DownloadDelegate** object with the **Web** component to listen for downloads initiated from pages. While the **Web** component downloads resources as requested, it notifies the application of the download progress through the **DownloadDelegate** object.

In the following example, the **index.html** and **download.html** files are added to the **rawfile** folder of the application. After the application is started, a **Web** component is created and the **index.html** file is loaded. After **setDownloadDelegate** is clicked, a **DownloadDelegate** object is registered with the **Web** component. This **DownloadDelegate** object listens for any downloads initiated by clicking the download button on the page.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

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
              console.log("will start a download.");
              // Pass in a download path and start the download.
              // If the path is invalid, the file will be downloaded to the default directory at /data/storage/el2/base/cache/web/.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              // Unique ID of a download task.
              console.log("download update guid: " + webDownloadItem.getGuid());
              // Download progress.
              console.log("download update guid: " + webDownloadItem.getPercentComplete());
              // Current download speed.
              console.log("download update speed: " + webDownloadItem.getCurrentSpeed())
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Error code of a download task failure.
              console.log("download failed guid: " + webDownloadItem.getLastErrorCode());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
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
```

HTML file to be loaded:
```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<body>
// Click the download button in the lower right corner of the video to trigger a download task.
<video controls="controls" width="800px" height="580px"
       src="http://vjs.zencdn.net/v/oceans.mp4"
       type="video/mp4">
</video>
<a href='data:text/html,%3Ch1%3EHello%2C%20World%21%3C%2Fh1%3E' download='download.html'>Download the download.html</a>
</body>
</html>
```

HTML file to be downloaded:
```html
<!-- download.html -->
<!DOCTYPE html>
<html>
<body>
<h1>download test</h1>
</body>
</html>
```

## Initiating a Download Task

Call [startDownload()](../reference/apis-arkweb/js-apis-webview.md#startdownload11) to initiate a download task.
For a download initiated by it, the **Web** component works out the referrer based on the currently displayed URL and its own default referrer policy.

  In the following example, clicking **setDownloadDelegate** registers a listener class with the **Web** component, and clicking **startDownload** initiates a download task.
  The application is notified of the download task progress through the configured **DownloadDelegate** object.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

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
              console.log("will start a download.");
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            // The specified download address here is https://www.example.com/. 
            // Replace it with the URL from which you want to download files.
            this.controller.startDownload('https://www.example.com/');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```


## Resuming Unfinished Download Tasks Due to Process Exit
When the **Web** component is started, you can resume the unfinished download task through the [resumeDownload()](../reference/apis-arkweb/js-apis-webview.md#resumedownload11) API.

In the following example, the **record** button is used to save the current download task to a persistent file. After the application is restarted, the **recovery** button can be used to resume the persistent download task. If multiple download tasks need to be saved, the application can adjust the persistence time and mode as required.
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { downloadUtil, fileName, filePath } from './downloadUtil'; // downloadUtil.ets is described below.

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  // Used to record failed download tasks.
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.log("will start a download.");
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download task to a byte array.
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
            })
            this.controller.setDownloadDelegate(this.delegate);
            webview.WebDownloadManager.setDownloadDelegate(this.delegate);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('startDownload')
        .onClick(() => {
          try {
            // The specified download address here is https://www.example.com/. 
            // Replace it with the URL from which you want to download files.
            this.controller.startDownload('https://www.example.com/');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      // Serialize and save the current download task information for subsequent download task resumption.
      // This example shows the one-task download scenario. For multiple download tasks, extend the code as required.
      Button('record')
        .onClick(() => {
          try {
            // Save the downloaded data to a persistent file.
            downloadUtil.saveDownloadInfo(downloadUtil.uint8ArrayToStr(this.download.serialize()));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      // Resume the download task from the serialized download task information.
      // Ensure that the WebDownloadManager.setDownloadDelegate setting is complete when the button is triggered.
      Button('recovery')
        .onClick(() => {
          try {
            // The persistence file is available by default. You can set it as required.
            let webDownloadItem =
              webview.WebDownloadItem.deserialize(downloadUtil.strToUint8Array(downloadUtil.readFileSync(filePath, fileName)));
            webview.WebDownloadManager.resumeDownload(webDownloadItem);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

Download the task information persistence utility file.
```ts
// downloadUtil.ets
import { util } from '@kit.ArkTS';
import fileStream from '@ohos.file.fs';

const helper = new util.Base64Helper();

export const filePath = getContext().filesDir;
export const fileName = 'demoFile.txt';
export namespace  downloadUtil {

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
      return fileStream.accessSync(filePath);
    } catch (error) {
      return false;
    }
  }

  export function mkDirectorySync(directoryPath: string, recursion?: boolean): void {
    try {
      fileStream.mkdirSync(directoryPath, recursion ?? false);
    } catch (error) {
      console.error(`mk dir error. err message: ${error.message}, err code: ${error.code}`);
    }
  }

  export function writeToFileSync(dir: string, fileName: string, msg: string): void {
    let file = fileStream.openSync(dir + '/' + fileName, fileStream.OpenMode.WRITE_ONLY | fileStream.OpenMode.CREATE);
    fileStream.writeSync(file.fd, msg);
  }

  export function readFileSync(dir: string, fileName: string): string {
    return fileStream.readTextSync(dir + '/' + fileName);
  }

}
```
