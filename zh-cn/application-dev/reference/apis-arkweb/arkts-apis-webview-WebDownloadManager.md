# Class (WebDownloadManager)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

WebDownloadManager是ArkWeb框架下Web组件下载任务的静态管理类，负责管理所有通过Web组件触发的文件下载流程。开发者可以通过该类设置下载委托以接收下载进度回调，以及恢复失败的下载任务。该类的所有方法均为静态方法，在整个应用范围内全局生效。

WebDownloadManager与[WebDownloadDelegate](./arkts-apis-webview-WebDownloadDelegate.md)、[WebDownloadItem](./arkts-apis-webview-WebDownloadItem.md)配合使用：WebDownloadManager负责下载任务的生命周期管理和委托设置，WebDownloadDelegate负责向应用层报告下载进度和状态变更事件，WebDownloadItem代表单个下载任务实体，支持暂停、恢复、取消等操作。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 11开始支持。
>
> - 示例效果请以真机运行为准。

## 导入模块

```ts
import { webview } from '@kit.ArkWeb';
```

## setDownloadDelegate<sup>11+</sup>

static setDownloadDelegate(delegate: WebDownloadDelegate): void

设置接收从WebDownloadManager触发的下载进度的委托。

> **说明：**
>
> - 在调用本接口前，若尚未创建Web组件且未执行[initializeWebEngine](./arkts-apis-webview-WebviewController.md#initializewebengine)方法，必须先调用该方法完成Web内核初始化，否则接口调用无效。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| delegate      | [WebDownloadDelegate](./arkts-apis-webview-WebDownloadDelegate.md)  | 是   | 用来接收下载进度的委托。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.info('will start a download.');
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start('/data/storage/el2/base/cache/web/' + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.info('download update percent complete: ' + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.error('download failed guid: ' + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.info('download finish guid: ' + webDownloadItem.getGuid());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## resumeDownload<sup>11+</sup>

static resumeDownload(webDownloadItem: WebDownloadItem): void

恢复一个失败的下载任务，需通过[WebDownloadItem.deserialize](./arkts-apis-webview-WebDownloadItem.md#deserialize11)方法获取反序列化后的对象，仅适用于之前失败的下载任务。

> **说明：**
>
>- 在调用本接口前，若尚未创建Web组件且未执行initializeWebEngine方法完成Web内核初始化，必须先调用initializeWebEngine方法进行初始化，否则接口调用无效。
>- 必须先调用[setDownloadDelegate](#setdownloaddelegate11)设置下载委托，否则会抛出错误码17100018。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型    |  必填  | 说明                                            |
| ---------------| ------- | ---- | ------------- |
| webDownloadItem | [WebDownloadItem](./arkts-apis-webview-WebDownloadItem.md) | 是 | 从序列化数据恢复的下载任务。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 17100018 | No WebDownloadDelegate has been set yet. |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
  download: webview.WebDownloadItem = new webview.WebDownloadItem();
  failedData: Uint8Array = new Uint8Array();

  build() {
    Column() {
      Button('setDownloadDelegate')
        .onClick(() => {
          try {
            this.delegate.onBeforeDownload((webDownloadItem: webview.WebDownloadItem) => {
              console.info('will start a download.');
              // 传入一个下载路径，并开始下载。
              webDownloadItem.start('/data/storage/el2/base/cache/web/' + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.info('download update percent complete: ' + webDownloadItem.getPercentComplete());
              this.download = webDownloadItem;
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.error('download failed guid: ' + webDownloadItem.getGuid());
              // 序列化失败的下载到一个字节数组。
              this.failedData = webDownloadItem.serialize();
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.info('download finish guid: ' + webDownloadItem.getGuid());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resumeDownload')
        .onClick(() => {
          try {
            webview.WebDownloadManager.resumeDownload(webview.WebDownloadItem.deserialize(this.failedData));
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('cancel')
        .onClick(() => {
          try {
            this.download.cancel();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('pause')
        .onClick(() => {
          try {
            this.download.pause();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Button('resume')
        .onClick(() => {
          try {
            this.download.resume();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```