# 使用Web组件的下载能力

> **说明：**
>
>Web组件的下载功能要求应用通过调用WebDownloadItem.start来指定下载文件的保存路径。值得注意的是，WebDownloadItem.start并非启动下载，下载过程实际上在用户点击页面链接时即已开始。WebDownloadItem.start的作用是将已经下载到临时文件的部分移动到指定目标路径，后续未完成的下载的内容将直接保存到指定目标路径，临时目录位于`/data/storage/el2/base/cache/web/Temp/`。如果决定取消当前下载，应调用WebDownloadItem.cancel，此时临时文件将被删除。
>
>如果不希望在WebDownloadItem.start之前将文件下载到临时目录，可以通过WebDownloadItem.cancel中断下载，后续可通过[WebDownloadManager.resumeDownload](../reference/apis-arkweb/js-apis-webview.md#resumedownload11)恢复中断的下载。

## 监听页面触发的下载

通过[setDownloadDelegate()](../reference/apis-arkweb/js-apis-webview.md#setdownloaddelegate11)向Web组件注册一个DownloadDelegate来监听页面触发的下载任务。资源由Web组件来下载，Web组件会通过DownloadDelegate将下载的进度通知给应用。

下面的示例中，在应用的rawfile中创建index.html以及download.html。应用启动后会创建一个Web组件并加载index.html，点击setDownloadDelegate按钮向Web组件注册一个DownloadDelegate，点击页面里的下载按钮的时候会触发一个下载任务，在DownloadDelegate中可以监听到下载的进度。

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
              // 传入一个下载路径，并开始下载。
              // 如果传入一个不存在的路径，则会下载到默认/data/storage/el2/base/cache/web/目录。
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              // 下载任务的唯一标识。
              console.log("download update guid: " + webDownloadItem.getGuid());
              // 下载的进度。
              console.log("download update guid: " + webDownloadItem.getPercentComplete());
              // 当前的下载速度。
              console.log("download update speed: " + webDownloadItem.getCurrentSpeed())
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // 下载任务失败的错误码。
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
加载的html文件。
```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<body>
<a href='data:text/html,%3Ch1%3EHello%2C%20World%21%3C%2Fh1%3E' download='download.html'>下载</a>
</body>
</html>
```

待下载的html文件。
```html
<!-- download.html -->
<!DOCTYPE html>
<html>
<body>
<h1>download test</h1>
</body>
</html>
```

## 使用Web组件发起一个下载任务

使用[startDownload()](../reference/apis-arkweb/js-apis-webview.md#startdownload11)接口发起一个下载。
Web组件发起的下载会根据当前显示的url以及Web组件默认的Referrer Policy来计算referrer。

  在下面的示例中，先点击setDownloadDelegate按钮向Web注册一个监听类，然后点击startDownload主动发起了一个下载，
  该下载任务也会通过设置的DownloadDelegate来通知app下载的进度。

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
              // 传入一个下载路径，并开始下载。
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
            // 这里指定下载地址为 https://www.example.com/，Web组件会发起一个下载任务将该页面下载下来。
            // 开发者需要替换为自己想要下载的内容的地址。
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
