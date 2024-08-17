# Downloading Files

## Listening for Downloads Initiated from Pages

Call [setDownloadDelegate()](../reference/apis-arkweb/js-apis-webview.md#setdownloaddelegate11) to register a **DownloadDelegate** object with the **\<Web>** component to listen for downloads initiated from pages. While the **\<Web>** component downloads resources as requested, it notifies the application of the download progress through the **DownloadDelegate** object.

In the following example, the **index.html** and **download.html** files are added to the **rawfile** folder of the application. After the application is started, a **\<Web>** component is created and the **index.html** file is loaded. After **setDownloadDelegate** is clicked, a **DownloadDelegate** object is registered with the **\<Web>** component. This **DownloadDelegate** object listens for any downloads initiated by clicking the download button on the page.

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
<a href='data:text/html,%3Ch1%3EHello%2C%20World%21%3C%2Fh1%3E' download='download.html'>Download</a>
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
For a download initiated by it, the **\<Web>** component works out the referrer based on the currently displayed URL and its own default referrer policy.

  In the following example, clicking **setDownloadDelegate** registers a listener class with the **\<Web>** component, and clicking **startDownload** initiates a download task.
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
