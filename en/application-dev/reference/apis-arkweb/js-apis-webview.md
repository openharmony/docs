# @ohos.web.webview (Webview)

The **Webview** module provides APIs for web control. It can work with the [Web](ts-basic-components-web.md) component, which is used to display web pages.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Required Permissions

**ohos.permission.INTERNET**, required for accessing online web pages. For details about how to apply for a permission, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

## Modules to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## webview.once

once(type: string, callback: Callback\<void\>): void

Registers a one-time callback for web events of the specified type. Currently, only **webInited** is supported. This callback is triggered when the Web engine initialization is complete.

When the first **Web** component is loaded in an application, the web engine is initialized. When other **Web** components are loaded in the same application, **once()** is not triggered. When the first **Web** component is loaded after the last **Web** component is destroyed in the application, the web engine will be initialized again.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type             | Mandatory| Description                 |
| ------- | ---------------- | ---- | -------------------- |
| type     | string          | Yes  | Web event type. The value can be **"webInited"**, indicating completion of web initialization.     |
| callback | Callback\<void\> | Yes  | Callback to register.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.   |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

webview.once("webInited", () => {
  console.log("configCookieSync");
  webview.WebCookieManager.configCookieSync("https://www.example.com", "a=b");
})

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## JsMessageExt<sup>10+</sup>

Implements the **JsMessageExt** data object that is returned after script execution using the [runJavaScriptExt](./js-apis-webview-WebviewController.md#runjavascriptext10) API.

### getType<sup>10+</sup>

getType(): JsMessageType

Obtains the type of the data object. For details about the sample code, see [runJavaScriptExt](./js-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description                                                     |
| --------------| --------------------------------------------------------- |
| [JsMessageType](./js-apis-webview-e.md#jsmessagetype10) | Data type of the result returned after the [runJavaScriptExt](./js-apis-webview-WebviewController.md#runjavascriptext10) API is executed.|

### getString<sup>10+</sup>

getString(): string

Obtains string-type data of the data object. For details about the sample code, see [runJavaScriptExt](./js-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| string | Data of the string type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getNumber<sup>10+</sup>

getNumber(): number

Obtains number-type data of the data object. For details about the sample code, see [runJavaScriptExt](./js-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| number | Data of the number type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getBoolean<sup>10+</sup>

getBoolean(): boolean

Obtains Boolean-type data of the data object. For details about the sample code, see [runJavaScriptExt](./js-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| boolean | Data of the Boolean type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getArrayBuffer<sup>10+</sup>

getArrayBuffer(): ArrayBuffer

Obtains raw binary data of the data object. For details about the sample code, see [runJavaScriptExt](./js-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| ArrayBuffer | Raw binary data.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

### getArray<sup>10+</sup>

getArray(): Array\<string | number | boolean\>

Obtains array-type data of the data object. For details about the sample code, see [runJavaScriptExt](./js-apis-webview-WebviewController.md#runjavascriptext10).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type          | Description         |
| --------------| ------------- |
| Array\<string \| number \| boolean\> | Data of the array type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100014 | The type and value of the message do not match. |

## HistoryItem

Describes a historical page record.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type                                  | Read-Only| Optional| Description                        |
| ------------- | -------------------------------------- | ---- | ---- | ---------------------------- |
| icon          | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes  | No  | **PixelMap** object of the icon on the historical page.|
| historyUrl    | string                                 | No  | No  | URL of the historical page.       |
| historyRawUrl | string                                 | No  | No  | Original URL of the historical page.   |
| title         | string                                 | No  | No  | Title of the historical page.          |

## WebDownloadItem<sup>11+</sup>

 Implements a **WebDownloadItem** object. You can use this object to perform operations on the corresponding download task.

> **NOTE**
>
> During the download, the download process is notified to the user through **WebDownloadDelegate**. The user can operate the download task through the **WebDownloadItem** parameter.

### getGuid<sup>11+</sup>

getGuid(): string

Obtains the unique ID of this download task.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Unique ID of the download task.|

**Example**

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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getCurrentSpeed<sup>11+</sup>

getCurrentSpeed(): number

Obtains the download speed, in bytes per second.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Download speed, in bytes per second.|

**Example**

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
              console.log("download update current speed: " + webDownloadItem.getCurrentSpeed());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getPercentComplete<sup>11+</sup>

getPercentComplete(): number

Obtains the download progress. The value **100** indicates that the download is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Download progress. The value **100** indicates that the download is complete.|

**Example**

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
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getTotalBytes<sup>11+</sup>

getTotalBytes(): number

Obtains the total length of the file to be downloaded.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Total length of the file to be downloaded.|

**Example**

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
              console.log("download update total bytes: " + webDownloadItem.getTotalBytes());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getState<sup>11+</sup>

getState(): WebDownloadState

Obtains the download state.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| [WebDownloadState](./js-apis-webview-e.md#webdownloadstate11) | Download state.|

**Example**

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
              console.log("download update download state: " + webDownloadItem.getState());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getLastErrorCode<sup>11+</sup>

getLastErrorCode(): WebDownloadErrorCode

Obtains the download error code.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| [WebDownloadErrorCode](./js-apis-webview-e.md#webdownloaderrorcode11) | Error code returned when the download error occurs.|

**Example**

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
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              console.log("download error code: " + webDownloadItem.getLastErrorCode());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getMethod<sup>11+</sup>

getMethod(): string

Obtains the request mode of this download task.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Request mode of the download task.|

**Example**

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
              console.log("Download will start. Method:" + webDownloadItem.getMethod());
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getMimeType<sup>11+</sup>

getMimeType(): string

Obtains the MIME type of this download task (for example, a sound file may be marked as audio/ogg, and an image file may be image/png).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | MIME type (for example, audio/ogg for a sound file, and image/png for an image file).|

**Example**

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
              console.log("Download will start. MIME type:" + webDownloadItem.getMimeType());
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getUrl<sup>11+</sup>

getUrl(): string

Obtains the download request URL.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Download request URL.|

**Example**

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
              console.log("will start a download, url:" + webDownloadItem.getUrl());
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getSuggestedFileName<sup>11+</sup>

getSuggestedFileName(): string

Obtains the suggested file name for this download task.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Suggested file name.|

**Example**

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
              console.log("will start a download, suggest name:" + webDownloadItem.getSuggestedFileName());
              // Pass in a download path and start the download.
              webDownloadItem.start("/data/storage/el2/base/cache/web/" + webDownloadItem.getSuggestedFileName());
            })
            this.delegate.onDownloadUpdated((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getReceivedBytes<sup>11+</sup>

getReceivedBytes(): number

Obtains the number of received bytes.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Number of received bytes.|

**Example**

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
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
              console.log("download update received bytes: " + webDownloadItem.getReceivedBytes());
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### getFullPath<sup>11+</sup>

getFullPath(): string

Obtains the full path of the downloaded file on the disk.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | Full path of the downloaded file on the disk.|

**Example**

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
              console.log("download update percent complete: " + webDownloadItem.getPercentComplete());
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
            })
            this.delegate.onDownloadFinish((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download finish guid: " + webDownloadItem.getGuid());
              console.log("download finish full path: " + webDownloadItem.getFullPath());
            })
            this.controller.setDownloadDelegate(this.delegate);
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
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### serialize<sup>11+</sup>

serialize(): Uint8Array

Serializes the failed download to a byte array.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Uint8Array | Byte array into which the failed download is serialized.|

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
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
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
              this.failedData = webDownloadItem.serialize();
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
            this.controller.startDownload('https://www.example.com');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### deserialize<sup>11+</sup>

static deserialize(serializedData: Uint8Array): WebDownloadItem

Deserializes the serialized byte array into a **WebDownloadItem** object.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name             | Type   | Mandatory  |  Description|
| ------------------ | ------- | ---- | ------------- |
| serializedData | Uint8Array | Yes  | Byte array into which the download is serialized.|

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| [WebDownloadItem](#webdownloaditem11) | **WebDownloadItem** object.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Parameter verification failed.  |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
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
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
              this.failedData = webDownloadItem.serialize();
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
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### start<sup>11+</sup>

start(downloadPath: string): void

Starts a download to a specified directory.

> **NOTE**
>
>This API must be used in the **onBeforeDownload** callback of **WebDownloadDelegate**. If it is not called in the callback, the download task remains in the PENDING state and is downloaded to a temporary directory. After the target path is specified by **WebDownloadItem.start**, the temporary files are renamed to the target path and the unfinished files are directly downloaded to the target path. If you do not want to download the file to the temporary directory before invoking **WebDownloadItem.start**, you can call **WebDownloadItem.cancel** to cancel the current download task and then call **WebDownloadManager.resumeDownload** to resume the task.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type                  | Mandatory| Description                            |
| ------ | ---------------------- | ---- | ------------------------------|
| downloadPath   | string     | Yes | Path (including the file name) for downloading the file. The path length is the same as that in file management and can contain a maximum of 255 characters.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Incorrect parameter types. 2. Parameter verification failed.  |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  delegate: webview.WebDownloadDelegate = new webview.WebDownloadDelegate();
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
            })
            this.delegate.onDownloadFailed((webDownloadItem: webview.WebDownloadItem) => {
              console.log("download failed guid: " + webDownloadItem.getGuid());
              // Serialize the failed download to a byte array.
              this.failedData = webDownloadItem.serialize();
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
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### cancel<sup>11+</sup>

cancel(): void

Cancels a download task.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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
              // Serialize the failed download to a byte array.
              this.failedData = webDownloadItem.serialize();
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
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### pause<sup>11+</sup>

pause(): void

Pauses a download task.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100019 | The download task is not started yet. |

**Example**

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
              // Serialize the failed download to a byte array.
              this.failedData = webDownloadItem.serialize();
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
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

### resume<sup>11+</sup>

resume(): void

Resumes a download task.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID | Error Message                                                     |
| -------- | ------------------------------------------------------------ |
| 17100016 | The download task is not paused. |

**Example**

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
              // Serialize the failed download to a byte array.
              this.failedData = webDownloadItem.serialize();
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

## WebDownloadDelegate<sup>11+</sup>

 Implements a **WebDownloadDelegate** class. You can use the callbacks of this class to notify users of the download state.

### onBeforeDownload<sup>11+</sup>

onBeforeDownload(callback: Callback\<WebDownloadItem>): void

Invoked to notify users before the download starts. **WebDownloadItem.start("xxx")** must be called in this API, with a download path provided. Otherwise, the download remains in the PENDING state.

> **NOTE**
>
>The file of the download task in the PENDING state is saved to a temporary directory. After the target path is specified by invoking **WebDownloadItem.start**, the temporary file is renamed as the target file, and the unfinished part is directly downloaded to the target path. To avoid generating temporary files before invoking **WebDownloadItem.start**, you can call **WebDownloadItem.cancel** to cancel the current download task and then call **WebDownloadManager.resumeDownload** to resume it.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | Yes  | Callback for triggering a download.|

**Example**

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
              // Serialize the failed download to a byte array.
              this.failedData = webDownloadItem.serialize();
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

### onDownloadUpdated<sup>11+</sup>

onDownloadUpdated(callback: Callback\<WebDownloadItem>): void

Invoked when the download progress is updated.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | Yes  | Callback invoked when the downloaded progress is updated.|

**Example**

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
              // Serialize the failed download to a byte array.
              this.failedData = webDownloadItem.serialize();
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

### onDownloadFinish<sup>11+</sup>

onDownloadFinish(callback: Callback\<WebDownloadItem>): void

Invoked when the download is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | Yes  | Callback invoked when the download is complete.|

**Example**

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
              // Serialize the failed download to a byte array.
              this.failedData = webDownloadItem.serialize();
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

### onDownloadFailed<sup>11+</sup>

onDownloadFailed(callback: Callback\<WebDownloadItem>): void

Invoked when the download fails.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory| Description          |
| ------- | ------ | ---- | :------------- |
| callback | Callback\<[WebDownloadItem](#webdownloaditem11)> | Yes  | Callback invoked when the download fails.|

**Example**

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
              // Serialize the failed download to a byte array.
              this.failedData = webDownloadItem.serialize();
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

## WebDownloadManager<sup>11+</sup>

Implements a **WebDownloadManager** class. You can use the APIs of this class to resume failed download tasks.

### setDownloadDelegate<sup>11+</sup>

static setDownloadDelegate(delegate: WebDownloadDelegate): void

Sets the delegate used to receive download progress triggered from **WebDownloadManager**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| delegate      | [WebDownloadDelegate](#webdownloaddelegate11)  | Yes  | Delegate used to receive the download progress.|

**Example**

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
              // Serialize the failed download to a byte array.
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

### resumeDownload<sup>11+</sup>

static resumeDownload(webDownloadItem: WebDownloadItem): void

Resumes a failed download task.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| webDownloadItem      | [WebDownloadItem](#webdownloaditem11)  | Yes  | Download task to resume.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100018 | No WebDownloadDelegate has been set yet. |

**Example**

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
              // Serialize the failed download to a byte array.
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

## ProxyConfig<sup>15+</sup>

Implements a ProxyConfig class. You can use the APIs of this class to configure proxies.

### insertProxyRule<sup>15+</sup>

insertProxyRule(proxyRule: string, schemeFilter?: ProxySchemeFilter): void

Inserts a rule to specify a proxy for URLs matching **schemeFilter**. If **schemeFilter** is empty, all URLs use the specified proxy.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type    |  Mandatory | Description          |
| ---------------| ------- | ---- | ------------- |
| proxyRule      | string  | Yes  | The specified proxy.|
| schemeFilter   | [ProxySchemeFilter](./js-apis-webview-e.md#proxyschemefilter15)  | No  | Used to filter URLs to use the proxy.<br>Default value: **MATCH_ALL_SCHEMES**.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

### insertDirectRule<sup>15+</sup>

insertDirectRule(schemeFilter?: ProxySchemeFilter): void

Inserts a proxy rule to specify that URLs matching **schemeFilter** are directly connected to the server.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type    |  Mandatory | Description          |
| ---------------| ------- | ---- | ------------- |
| schemeFilter   | [ProxySchemeFilter](./js-apis-webview-e.md#proxyschemefilter15)  | No  | Used to filter URLs to be directly connected to the server.<br>Default value: **MATCH_ALL_SCHEMES**.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

### insertBypassRule<sup>15+</sup>

insertBypassRule(bypassRule: string): void

Inserts a bypass rule to specify the URLs that should bypass the proxy and directly connect to the server.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type    |  Mandatory | Description          |
| ---------------| ------- | ---- | ------------- |
| bypassRule     | string  | Yes  | Used to specify the URLs that should bypass the proxy.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

### bypassHostnamesWithoutPeriod<sup>15+</sup>

bypassHostnamesWithoutPeriod(): void

Specifies that domain names without a period should bypass the proxy and directly connect to the server.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

### clearImplicitRules<sup>15+</sup>

clearImplicitRules(): void

Overrides the default behavior and forces local host or local IP address to be sent through the proxy. (By default, if host names are local IP addresses or local host addresses, they bypass the proxy.)  

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

### enableReverseBypass<sup>15+</sup>

enableReverseBypass(reverse: boolean): void

Reverses the bypass rule.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type    |  Mandatory | Description          |
| ---------------| ------- | ---- | ------------- |
| reverse     | boolean  | Yes  | Whether to reverse the bypass rule. The default value is **false**, indicating the bypass rule set in [insertBypassRule](#insertbypassrule15) is not reversed. The value **true** indicates the opposite.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

### getBypassRules<sup>15+</sup>

getBypassRules(): Array\<string\>

Obtains the list of URLs that do not use the proxy.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Array\<string\> | List of URLs that do not use the proxy.|

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

### getProxyRules<sup>15+</sup>

getProxyRules(): Array\<ProxyRule\>

Obtains proxy rules.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Array\<[ProxyRule](#proxyrule15)\> | Proxy rule.|

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

### isReverseBypassEnabled<sup>15+</sup>

isReverseBypassEnabled(): boolean

Obtains the value of [enableReverseBypass](#enablereversebypass15). For details, see [enableReverseBypass](#enablereversebypass15).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Value of [enableReverseBypass](#enablereversebypass15). The default value is **false**, indicating the bypass rule set in [insertBypassRule](#insertbypassrule15) is not reversed. The value **true** indicates the opposite.|

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).


## ProxyRule<sup>15+</sup>

Indicates the proxy rule used in the [insertProxyRule](#insertproxyrule15).

### getSchemeFilter<sup>15+</sup>

getSchemeFilter(): ProxySchemeFilter

Obtains the **ProxySchemeFilter** information in the proxy rule.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| [ProxySchemeFilter](./js-apis-webview-e.md#proxyschemefilter15) | The **ProxySchemeFilter** information in the proxy rule.|

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

### getUrl<sup>15+</sup>

getUrl(): string

Obtains the URL specified in the proxy rule.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| string | The URL specified in the proxy rule.|

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

## OnProxyConfigChangeCallback<sup>15+</sup>

type OnProxyConfigChangeCallback = () => void

Called when the proxy is set successfully.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

## ProxyController<sup>15+</sup>

Implements a **ProxyController** object to set a proxy for an application.

### applyProxyOverride<sup>15+</sup>

static applyProxyOverride(proxyConfig: ProxyConfig, callback: OnProxyConfigChangeCallback): void

Set the proxy used by all webs in an application. URLs that match the bypass rule inserted through [insertBypassRule](#insertbypassrule15) do not use the proxy. Instead, their requests are directly sent to the source addresses specified by the URLs. The new proxy may not be used immediately after the network is connected. Before loading the page, wait for the listener to be triggered in the UI thread.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type    |  Mandatory | Description          |
| ---------------| ------- | ---- | ------------- |
| proxyConfig     | [ProxyConfig](#proxyconfig15)  | Yes  | Configuration of the proxy.|
| callback     | [OnProxyConfigChangeCallback](#onproxyconfigchangecallback15)   | Yes  | Callback used when the proxy is successfully set.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

For details, see [removeProxyOverride](#removeproxyoverride15).

### removeProxyOverride<sup>15+</sup>

static removeProxyOverride(callback: OnProxyConfigChangeCallback): void

Removes the proxy configuration. The new proxy may not be used immediately after the network is connected. Before loading the page, wait for the listener to be triggered in the UI thread.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type    |  Mandatory | Description          |
| ---------------| ------- | ---- | ------------- |
| callback     | [OnProxyConfigChangeCallback](#onproxyconfigchangecallback15)   | Yes  | Callback used when the proxy is successfully set.|

**Error codes**

For details about the following error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  proxyRules: webview.ProxyRule[] = [];

  build() {
    Row() {
      Column() {
        Button("applyProxyOverride").onClick(()=>{
          let proxyConfig:webview.ProxyConfig = new webview.ProxyConfig();
          // The first proxy configuration https://proxy.XXX.com is preferentially used.
          // When the proxy fails, insertDirectRule is used.
          try {
            proxyConfig.insertProxyRule("https://proxy.XXX.com", webview.ProxySchemeFilter.MATCH_ALL_SCHEMES);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
          try {
            proxyConfig.insertDirectRule(webview.ProxySchemeFilter.MATCH_HTTP);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
          try {
            proxyConfig.insertBypassRule("*.example.com");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
          proxyConfig.clearImplicitRules();
          proxyConfig.bypassHostnamesWithoutPeriod();
          try {
            proxyConfig.enableReverseBypass(true);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
          let bypassRules = proxyConfig.getBypassRules();
          for (let i = 0; i < bypassRules.length; i++) {
            console.log("bypassRules: " + bypassRules[i]);
          }
          this.proxyRules = proxyConfig.getProxyRules();
          for (let i = 0; i < this.proxyRules.length; i++) {
            console.log("SchemeFiletr: " + this.proxyRules[i].getSchemeFilter());
            console.log("Url: " + this.proxyRules[i].getUrl());
          }
          let isReverseBypassRule = proxyConfig.isReverseBypassEnabled();
          console.log("isReverseBypassRules: " + isReverseBypassRule);
          try {
            webview.ProxyController.applyProxyOverride(proxyConfig, () => {
              console.log("PROXYCONTROLLER proxy changed");
            });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        Button("loadUrl-https").onClick(()=>{
          this.controller.loadUrl("https://www.example.com")
        })
        Button("loadUrl-http").onClick(()=>{
          this.controller.loadUrl("http://www.example.com")
        })
        Button("removeProxyOverride").onClick(()=>{
          try {
          webview.ProxyController.removeProxyOverride(() => {
            console.log("PROXYCONTROLLER proxy changed");
          });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        Web({ src: 'www.example.com', controller: this.controller})
      }
      .width('100%')
    }
    .height('100%')
  }
}

```

## WebHttpBodyStream<sup>12+</sup>

Represents the body of the data being sent in POST and PUT requests. It accepts data of the BYTES, FILE, BLOB, and CHUNKED types. Note that other APIs in this class can be called only after [initialize](#initialize12) is called successfully.

### initialize<sup>12+</sup>

initialize(): Promise\<void\>

Initializes this **WebHttpBodyStream** instance.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100022 | Failed to initialize the HTTP body stream. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';
import { WebNetErrorList } from '@ohos.web.netErrorList'

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();
  htmlData: string = "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>";

  build() {
    Column() {
      Button('postUrl')
        .onClick(() => {
          try {
            let postData = buffer.from(this.htmlData);
            this.controller.postUrl('https://www.example.com', postData.buffer);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'https://www.example.com', controller: this.controller })
        .onControllerAttached(() => {
          try {
            this.schemeHandler.onRequestStart((request: webview.WebSchemeHandlerRequest, resourceHandler: webview.WebResourceHandler) => {
              console.log("[schemeHandler] onRequestStart");
              try {
                let stream = request.getHttpBodyStream();
                if (stream) {
                  stream.initialize().then(() => {
                    if (!stream) {
                      return;
                    }
                    console.log("[schemeHandler] onRequestStart postDataStream size:" + stream.getSize());
                    console.log("[schemeHandler] onRequestStart postDataStream position:" + stream.getPosition());
                    console.log("[schemeHandler] onRequestStart postDataStream isChunked:" + stream.isChunked());
                    console.log("[schemeHandler] onRequestStart postDataStream isEof:" + stream.isEof());
                    console.log("[schemeHandler] onRequestStart postDataStream isInMemory:" + stream.isInMemory());
                    stream.read(stream.getSize()).then((buffer) => {
                      if (!stream) {
                        return;
                      }
                      console.log("[schemeHandler] onRequestStart postDataStream readlength:" + buffer.byteLength);
                      console.log("[schemeHandler] onRequestStart postDataStream isEof:" + stream.isEof());
                      console.log("[schemeHandler] onRequestStart postDataStream position:" + stream.getPosition());
                    }).catch((error: BusinessError) => {
                      console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
                    })
                  }).catch((error: BusinessError) => {
                    console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
                  })
                } else {
                  console.log("[schemeHandler] onRequestStart has no http body stream");
                }
              } catch (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }

              return false;
            })

            this.schemeHandler.onRequestStop((request: webview.WebSchemeHandlerRequest) => {
              console.log("[schemeHandler] onRequestStop");
            });

            this.controller.setWebSchemeHandler('https', this.schemeHandler);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        .javaScriptAccess(true)
        .domStorageAccess(true)
    }
  }
}

```

### read<sup>12+</sup>

read(size: number): Promise\<ArrayBuffer\>

Reads data from this **WebHttpBodyStream** instance.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  size | number | Yes  | Number of bytes obtained from the **WebHttpBodyStream** instance.|

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Promise\<ArrayBuffer\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.    |

**Example**

For the complete sample code, see [initialize](#initialize12)).

### getSize<sup>12+</sup>

getSize(): number

Obtains the size of data in this **WebHttpBodyStream** instance. This API always returns zero when chunked transfer is used.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Size of data in the current **WebHttpBodyStream** instance.|

**Example**

For the complete sample code, see [initialize](#initialize12)).

### getPosition<sup>12+</sup>

getPosition(): number

Reads the current read position in this **WebHttpBodyStream** instance.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Current read position in the **WebHttpBodyStream** instance.|

**Example**

For the complete sample code, see [initialize](#initialize12)).

### isChunked<sup>12+</sup>

isChunked(): boolean

Checks whether this **WebHttpBodyStream** instance is transmitted by chunk.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Whether the **WebHttpBodyStream** instance is transmitted by chunk. The value **true** indicates that the **WebHttpBodyStream** instance is transmitted by chunk, and **false** indicates the opposite.|

**Example**

For the complete sample code, see [initialize](#initialize12)).

### isEof<sup>12+</sup>

isEof(): boolean

Checks whether all data in this **WebHttpBodyStream** instance has been read.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Whether all data in the **WebHttpBodyStream** instance has been read.<br>This API returns **true** if all data in the **httpBodyStream** instance is read. It returns **false** before the first read attempt is made for the **WebHttpBodyStream** instance that uses chunked transfer.|

**Example**

For the complete sample code, see [initialize](#initialize12)).

### isInMemory<sup>12+</sup>

isInMemory(): boolean

Checks whether the uploaded data in this **WebHttpBodyStream** instance is in memory.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Whether the uploaded data in the **WebHttpBodyStream** instance is stored in memory.<br>This API returns **true** if all the upload data in the **WebHttpBodyStream** instance is in memory and all read requests will be completed synchronously. It returns **false** if the data is chunked to transfer.|

**Example**

For the complete sample code, see [initialize](#initialize12)).

## WebSchemeHandlerRequest<sup>12+</sup>

Represents a request intercepted by the **WebSchemeHandler** object.

### getHeader<sup>12+</sup>

getHeader(): Array\<WebHeader\>

Obtains the information about the resource request header.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                        | Description        |
| -------------------------- | ---------- |
| Array\<[WebHeader](./js-apis-webview-i.md#webheader)\> | Information about the resource request header.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getRequestUrl<sup>12+</sup>

getRequestUrl(): string

Obtains the URL of the resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | URL of the resource request.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getRequestMethod<sup>12+</sup>

getRequestMethod(): string

Obtains the request method.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Request method.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getReferrer<sup>12+</sup>

getReferrer(): string

Obtains the referrer.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Obtained referrer.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### isMainFrame<sup>12+</sup>

isMainFrame(): boolean

Checks whether the resource request is for the main frame.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| boolean | Whether the resource request is for the main frame. If the resource request is for the main frame, **true** is returned. Otherwise, **false** is returned.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### hasGesture<sup>12+</sup>

hasGesture(): boolean

Checks whether the resource request is associated with a gesture (for example, a tap).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| boolean | Whether the resource request is associated with a gesture (for example, a tap). If the resource request is associated with a gesture, **true** is returned. Otherwise, **false** is returned.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getHttpBodyStream<sup>12+</sup>

getHttpBodyStream(): WebHttpBodyStream | null

Obtains the **WebHttpBodyStream** instance in this resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| [WebHttpBodyStream](#webhttpbodystream12) \| null | **WebHttpBodyStream** instance in the resource request. If there is no **WebHttpBodyStream** instance, **null** is returned.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getRequestResourceType<sup>12+</sup>

getRequestResourceType(): WebResourceType

Obtains the resource type of this resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| [WebResourceType](./js-apis-webview-e.md#webresourcetype12) | Resource type of the resource request.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

### getFrameUrl<sup>12+</sup>

getFrameUrl(): string

Obtains the URL of the frame that triggers this request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | URL of the frame that triggers the request.|

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

## WebSchemeHandlerResponse<sup>12+</sup>

Represents a request response. You can create a response for an intercepted request, fill in custom content, and return the response to the **Web** component.

### constructor<sup>12+</sup>

constructor()

Constructs a **Response** object.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { WebNetErrorList } from '@ohos.web.netErrorList';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();

  build() {
    Column() {
      Button('response').onClick(() => {
        let response = new webview.WebSchemeHandlerResponse();
        try {
          response.setUrl("http://www.example.com")
          response.setStatus(200)
          response.setStatusText("OK")
          response.setMimeType("text/html")
          response.setEncoding("utf-8")
          response.setHeaderByName("header1", "value1", false)
          response.setNetErrorCode(WebNetErrorList.NET_OK)
          console.log("[schemeHandler] getUrl:" + response.getUrl())
          console.log("[schemeHandler] getStatus:" + response.getStatus())
          console.log("[schemeHandler] getStatusText:" + response.getStatusText())
          console.log("[schemeHandler] getMimeType:" + response.getMimeType())
          console.log("[schemeHandler] getEncoding:" + response.getEncoding())
          console.log("[schemeHandler] getHeaderByValue:" + response.getHeaderByName("header1"))
          console.log("[schemeHandler] getNetErrorCode:" + response.getNetErrorCode())

        } catch (error) {
          console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
        }
      })
      Web({ src: 'https://www.example.com', controller: this.controller })
    }
  }
}

```

### setUrl<sup>12+</sup>

setUrl(url: string): void

Sets the redirection URL or the URL changed due to HSTS for this response. After the URL is set, a redirection to the new URL is triggered.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  url | string | Yes  | URL to be redirected to.|

**Example**

For details about the sample code, see [constructor](#constructor12).

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

### setNetErrorCode<sup>12+</sup>

setNetErrorCode(code: WebNetErrorList): void

Sets the network error code for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  code | [WebNetErrorList](js-apis-netErrorList.md#webneterrorlist) | Yes  | Network error code.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |

**Example**

For details about the sample code, see [constructor](#constructor12).

### setStatus<sup>12+</sup>

setStatus(code: number): void

Sets the HTTP status code for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  code | number | Yes  | HTTP status code.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types. |

**Example**

For details about the sample code, see [constructor](#constructor12).

### setStatusText<sup>12+</sup>

setStatusText(text: string): void

Sets the status text for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  text | string | Yes  | Status text.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**Example**

For details about the sample code, see [constructor](#constructor12).

### setMimeType<sup>12+</sup>

setMimeType(type: string): void

Sets the MIME type for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  type | string | Yes  | MIME type.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**Example**

For details about the sample code, see [constructor](#constructor12).

### setEncoding<sup>12+</sup>

setEncoding(encoding: string): void

Sets the character set for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  encoding | string | Yes  | Character set.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Incorrect parameter types.    |

**Example**

For details about the sample code, see [constructor](#constructor12).

### setHeaderByName<sup>12+</sup>

setHeaderByName(name: string, value: string, overwrite: boolean): void

Sets the header information for this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  name | string | Yes  | Name of the header.|
|  value | string | Yes  | Value of the header.|
|  overwrite | boolean | Yes  | Whether to override the existing header. The value **true** means to override the existing header, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.    |

**Example**

For details about the sample code, see [constructor](#constructor12).

### getUrl<sup>12+</sup>

getUrl(): string

Obtains the redirection URL or the URL changed due to HSTS.
NOTE: To obtain the URL for JavaScriptProxy communication API authentication, use [getLastJavascriptProxyCallingFrameUrl<sup>12+</sup>](./js-apis-webview-WebviewController.md#getlastjavascriptproxycallingframeurl12).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Redirection URL or the URL changed due to HSTS.|

**Example**

For details about the sample code, see [constructor](#constructor12).

### getNetErrorCode<sup>12+</sup>

getNetErrorCode(): WebNetErrorList

Obtains the network error code of the response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| [WebNetErrorList](js-apis-netErrorList.md#webneterrorlist) | Network error code of the response.|

**Example**

For details about the sample code, see [constructor](#constructor12).

### getStatus<sup>12+</sup>

getStatus(): number

Obtains the HTTP status code of the response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| number | HTTP status code of the response.|

**Example**

For details about the sample code, see [constructor](#constructor12).

### getStatusText<sup>12+</sup>

getStatusText(): string

Obtains the status text of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Status text.|

**Example**

For details about the sample code, see [constructor](#constructor12).

### getMimeType<sup>12+</sup>

getMimeType(): string

Obtains the MIME type of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | MIME type.|

**Example**

For details about the sample code, see [constructor](#constructor12).

### getEncoding<sup>12+</sup>

getEncoding(): string

Obtains the character set of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Character set.|

**Example**

For details about the sample code, see [constructor](#constructor12).

### getHeaderByName<sup>12+</sup>

getHeaderByName(name: string): string

Obtains the character set of this response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type            | Mandatory| Description                 |
| ------- | ---------------- | ---- | -------------------- |
| name     | string | Yes  | Name of the header.     |


**Return value**

| Type   | Description                                    |
| ------- | --------------------------------------- |
| string | Value of the header.|

**Example**

For details about the sample code, see [constructor](#constructor12).

## WebResourceHandler<sup>12+</sup>

Represents a **WebResourceHandler** object, which can return custom response headers and response bodies to the **Web** component.

### didReceiveResponse<sup>12+</sup>

didReceiveResponse(response: WebSchemeHandlerResponse): void

Sends a response header for this request.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| response      | [WebSchemeHandlerResponse](#webschemehandlerresponse12)  | Yes  | Response to send.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**Example**

See [OnRequestStart](#onrequeststart12).

### didReceiveResponseBody<sup>12+</sup>

didReceiveResponseBody(data: ArrayBuffer): void

Sends a response body for this request.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type   |  Mandatory | Description                                           |
| ---------------| ------- | ---- | ------------- |
| data      | ArrayBuffer  | Yes  | Response body.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified.    |
| 17100021 | The resource handler is invalid. |

**Example**

See [OnRequestStart](#onrequeststart12).

### didFinish<sup>12+</sup>

didFinish(): void

Notifies the **Web** component that this request is completed and that no more data is available. Before calling this API, you need to call [didReceiveResponse](#didreceiveresponse12) to send a response header for this request.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 17100021 | The resource handler is invalid. |

**Example**

See [OnRequestStart](#onrequeststart12).

### didFail<sup>12+</sup>

didFail(code: WebNetErrorList): void

Notifies the ArkWeb kernel that this request fails. Before calling this API, call [didReceiveResponse](#didreceiveresponse12) to send a response header to this request.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   |  Mandatory | Description                      |
| --------| ------- | ---- | ---------------------------|
|  code | [WebNetErrorList](js-apis-netErrorList.md#webneterrorlist) | Yes  | Network error code.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types. |
| 17100021 | The resource handler is invalid. |

**System capability**: SystemCapability.Web.Webview.Core

**Example**

See [OnRequestStart](#onrequeststart12).

## WebSchemeHandler<sup>12+</sup>

Represents a **WebSchemeHandler** object used to intercept requests for a specific scheme.

### onRequestStart<sup>12+</sup>

onRequestStart(callback: (request: WebSchemeHandlerRequest, handler: WebResourceHandler) => boolean): void

Called when a request starts. In this callback, you can determine whether to intercept the request. If **false** is returned, the request is not intercepted and the handler is invalid. If **true** is returned, the request is intercepted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback   | (request: [WebSchemeHandlerRequest](#webschemehandlerrequest12), handler: [WebResourceHandler](#webresourcehandler12)) => boolean | Yes| Callback invoked when a request for the specified scheme starts. **request** represents a request. **handler** provides the custom response header and response body for the **Web** component. The return value indicates whether the request is intercepted.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';
import { WebNetErrorList } from '@ohos.web.netErrorList';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  schemeHandler: webview.WebSchemeHandler = new webview.WebSchemeHandler();
  htmlData: string = "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>";

  build() {
    Column() {
      Web({ src: 'https://www.example.com', controller: this.controller })
        .onControllerAttached(() => {
          try {
            this.schemeHandler.onRequestStart((request: webview.WebSchemeHandlerRequest, resourceHandler: webview.WebResourceHandler) => {
              console.log("[schemeHandler] onRequestStart");
              try {
                console.log("[schemeHandler] onRequestStart url:" + request.getRequestUrl());
                console.log("[schemeHandler] onRequestStart method:" + request.getRequestMethod());
                console.log("[schemeHandler] onRequestStart referrer:" + request.getReferrer());
                console.log("[schemeHandler] onRequestStart isMainFrame:" + request.isMainFrame());
                console.log("[schemeHandler] onRequestStart hasGesture:" + request.hasGesture());
                console.log("[schemeHandler] onRequestStart header size:" + request.getHeader().length);
                console.log("[schemeHandler] onRequestStart resource type:" + request.getRequestResourceType());
                console.log("[schemeHandler] onRequestStart frame url:" + request.getFrameUrl());
                let header = request.getHeader();
                for (let i = 0; i < header.length; i++) {
                  console.log("[schemeHandler] onRequestStart header:" + header[i].headerKey + " " + header[i].headerValue);
                }
                let stream = request.getHttpBodyStream();
                if (stream) {
                  console.log("[schemeHandler] onRequestStart has http body stream");
                } else {
                  console.log("[schemeHandler] onRequestStart has no http body stream");
                }
              } catch (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }

              if (request.getRequestUrl().endsWith("example.com")) {
                return false;
              }

              let response = new webview.WebSchemeHandlerResponse();
              try {
                response.setNetErrorCode(WebNetErrorList.NET_OK);
                response.setStatus(200);
                response.setStatusText("OK");
                response.setMimeType("text/html");
                response.setEncoding("utf-8");
                response.setHeaderByName("header1", "value1", false);
              } catch (error) {
                console.error(`[schemeHandler] ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }

              // Before calling didFinish or didFail, call didReceiveResponse to send a response header to this request.
              let buf = buffer.from(this.htmlData)
              try {
                if (buf.length == 0) {
                  console.log("[schemeHandler] length 0");
                  resourceHandler.didReceiveResponse(response);
                  // If the value of buf.length is 0 in normal cases, call resourceHandler.didFinish(). Otherwise, call resourceHandler.didFail().
                  resourceHandler.didFail(WebNetErrorList.ERR_FAILED);
                } else {
                  console.log("[schemeHandler] length 1");
                  resourceHandler.didReceiveResponse(response);
                  resourceHandler.didReceiveResponseBody(buf.buffer);
                  resourceHandler.didFinish();
                }
              } catch (error) {
                console.error(`[schemeHandler] ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
              return true;
            })

            this.schemeHandler.onRequestStop((request: webview.WebSchemeHandlerRequest) => {
              console.log("[schemeHandler] onRequestStop");
            });

            this.controller.setWebSchemeHandler('https', this.schemeHandler);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        .javaScriptAccess(true)
        .domStorageAccess(true)
    }
  }
}
```
### onRequestStop<sup>12+</sup>

onRequestStop(callback: Callback\<WebSchemeHandlerRequest\>): void

Called when a request is complete, under the prerequisite that the request is indicated as intercepted in the **onRequestStart** callback. Specifically, this callback is invoked in the following cases:

1. The **WebResourceHandler** object calls **didFail** or **didFinish**.

2. The request is interrupted due to other reasons.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | Callback\<[WebSchemeHandlerRequest](#webschemehandlerrequest12)\> | Yes  | Callback invoked when the request is complete.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                             |
| -------- | ------------------------------------- |
| 401 | Invalid input parameter. |

**Example**

For the complete sample code, see [onRequestStart](#onrequeststart12).

## NativeMediaPlayerHandler<sup>12+<sup>

Represents a **NativeMediaPlayerHandler** object used as the parameter of the [CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12) callback.
The application uses this object to report the player status to the ArkWeb engine.

### handleStatusChanged<sup>12+<sup>

handleStatusChanged(status: PlaybackStatus): void

Called to notify the ArkWeb engine of the playback status of the player when the playback status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| status | [PlaybackStatus](./js-apis-webview-e.md#playbackstatus12) | Yes| Player status.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleVolumeChanged<sup>12+<sup>

handleVolumeChanged(volume: number): void

Called to notify the ArkWeb engine of the volume of the player when the volume changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| volume | number | Yes| Volume of the player.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleMutedChanged<sup>12+<sup>

handleMutedChanged(muted: boolean): void

Called to notify the ArkWeb engine of the muted status of the player when the muted status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| muted | boolean | Yes| Whether the player is muted.<br>The value **true** indicates that the player is muted, and **false** indicates the opposite.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handlePlaybackRateChanged<sup>12+<sup>

handlePlaybackRateChanged(playbackRate: number): void

Called to notify the ArkWeb engine of the playback rate of the player when the playback rate changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| playbackRate | number | Yes| Playback rate.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleDurationChanged<sup>12+<sup>

handleDurationChanged(duration: number): void

Called to notify the ArkWeb engine of the total duration of the media.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| duration | number | Yes| Total duration of the media.<br>Unit: second.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleTimeUpdate<sup>12+<sup>

handleTimeUpdate(currentPlayTime: number): void

Called to notify the ArkWeb engine of the playback progress when the playback progress changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| currentPlayTime | number | Yes| Current progress. Unit: second. |

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleBufferedEndTimeChanged<sup>12+<sup>

handleBufferedEndTimeChanged(bufferedEndTime: number): void

Called to notify the ArkWeb engine of the buffer time when the buffer time changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| bufferedEndTime | number | Yes| Duration of media data in the buffer.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleEnded<sup>12+<sup>

handleEnded(): void

Called to notify the ArkWeb engine that the media playback ends.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleNetworkStateChanged<sup>12+<sup>

handleNetworkStateChanged(state: NetworkState): void

Called to notify the ArkWeb engine of the network status of the player when the network status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| state | [NetworkState](./js-apis-webview-e.md#networkstate12) | Yes| Network status of the player.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleReadyStateChanged<sup>12+<sup>

handleReadyStateChanged(state: ReadyState): void

Called to notify the ArkWeb engine of the cache status of the player when the cache status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| state | [ReadyState](./js-apis-webview-e.md#readystate12) | Yes| Cache status of the player.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleFullscreenChanged<sup>12+<sup>

handleFullscreenChanged(fullscreen: boolean): void

Called to notify the ArkWeb engine of the full screen status of the player when the full screen status changes.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| fullscreen | boolean | Yes| Whether the player is in full screen.<br>The value **true** means that the player is in full screen, and **false** means the opposite.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleSeeking<sup>12+<sup>

handleSeeking(): void

Called to notify the ArkWeb engine that the player enters the seek state.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleSeekFinished<sup>12+<sup>

handleSeekFinished(): void

Called to notify the ArkWeb engine that the seek operation is complete.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleError<sup>12+<sup>

handleError(error: MediaError, errorMessage: string): void

Called to notify the ArkWeb engine that an error occurs with the player.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| error | [MediaError](./js-apis-webview-e.md#mediaerror12) | Yes| Error object type.|
| errorMessage | string | Yes| Error message.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### handleVideoSizeChanged<sup>12+<sup>

handleVideoSizeChanged(width: number, height: number): void

Called to notify the ArkWeb engine of the video size of the player.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| width  | number | Yes| Video width.|
| height | number | Yes| Video height.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## NativeMediaPlayerBridge<sup>12+<sup>

Implements a **NativeMediaPlayerBridge** object, which is the return value of the [CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12) callback.
It is an API class that acts as a bridge between the web media player and the ArkWeb kernel.
The ArkWeb engine uses an object of this interface class to control the player created by the application to take over web page media.

### updateRect<sup>12+<sup>

updateRect(x: number, y: number, width: number, height: number): void

Updates the surface position information.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| x | number | Yes| X coordinate of the surface relative to the web component.|
| y | number | Yes| Y coordinate of the surface relative to the web component.|
| width  | number | Yes| Width of the surface.|
| height | number | Yes| Height of the surface.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### play<sup>12+<sup>

play(): void

Plays this video.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### pause<sup>12+<sup>

pause(): void

Pauses playback.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### seek<sup>12+<sup>

seek(targetTime: number): void

Seeks to a specific time point in the media.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| targetTime | number | Yes| Target time point.<br>Unit: second.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### setVolume<sup>12+<sup>

setVolume(volume: number): void

Sets the playback volume.

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| volume | number | Yes| Volume of the player.<br>Value range: [0, 1.0]. The value **0** indicates mute, and the value **1.0** indicates the maximum volume.|

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### setMuted<sup>12+<sup>

setMuted(muted: boolean): void

Sets the muted status.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| muted | boolean | Yes| Whether to mute the player.<br>The value **true** means to mute the player, and **false** means the opposite.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### setPlaybackRate<sup>12+<sup>

setPlaybackRate(playbackRate: number): void

Sets the playback rate.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| playbackRate | number | Yes| Playback rate.<br>Value range: [0, 10.0]. The value **1** indicates the original speed of playback.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### release<sup>12+<sup>

release(): void

Releases this player.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### enterFullscreen<sup>12+<sup>

enterFullscreen(): void

Enables the player to enter full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### exitFullscreen<sup>12+<sup>

exitFullscreen(): void

Enables the player to exit full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### resumePlayer<sup>12+<sup>

resumePlayer?(): void

Resumes the player and its status information.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

### suspendPlayer<sup>12+<sup>

suspendPlayer?(type: SuspendType): void

Suspends the player and save its status information.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| type | [SuspendType](./js-apis-webview-e.md#suspendtype12) | Yes| Suspension type of the player.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## MediaSourceInfo<sup>12+<sup>

Provides the information about the media source.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| type | [SourceType](./js-apis-webview-e.md#sourcetype12) | Yes| Type of the media source.|
| source | string | Yes| Address of the media source.|
| format | string | Yes| Format of the media source, which may be empty. You need to determine the format by yourself.|

## NativeMediaPlayerSurfaceInfo<sup>12+<sup>

Provides the surface information used for same-layer rendering [when the application takes over the media playback functionality of the web page](./ts-basic-components-web-attributes.md#enablenativemediaplayer12).

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| id | string | Yes| Surface ID, which is the **psurfaceid** of the native image used for rendering at the same layer.<br>For details, see [NativeEmbedDataInfo](./ts-basic-components-web-i.md#nativeembeddatainfo11).|
| rect | [RectEvent](#rectevent12) | Yes| Position of the surface.|

## MediaInfo<sup>12+<sup>

Represents a **MediaInfo** object used as a parameter of the [CreateNativeMediaPlayerCallback](#createnativemediaplayercallback12) callback.
The object contains information about media on the web page. The application may create, based on the information, a player that takes over media playback of the web page .

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| embedID | string | Yes| ID of **\<video>** or **\<audio>** on the web page.|
| mediaType | [MediaType](./js-apis-webview-e.md#mediatype12) | Yes| Type of the media.|
| mediaSrcList | [MediaSourceInfo](#mediasourceinfo12)[] | Yes| Source of the media. There may be multiple sources. The application needs to select a supported source to play.|
| surfaceInfo | [NativeMediaPlayerSurfaceInfo](#nativemediaplayersurfaceinfo12) | Yes| Surface information used for same-layer rendering.|
| controlsShown | boolean | Yes| Whether the **controls** attribute exists in **\<video>** or **\<audio>**.<br>The value **true** means that the **controls** attribute exists in **\<video>** or **\<audio>**, and **false** means the opposite.|
| controlList | string[] | Yes| Value of the **controlslist** attribute in **\<video>** or **\<audio>**.|
| muted | boolean | Yes| Whether to mute the player.<br>The value **true** means to mute the player, and **false** means the opposite.|
| posterUrl | string | Yes| URL of a poster.|
| preload | [Preload](./js-apis-webview-e.md#preload12) | Yes| Whether preloading is required.|
| headers | Record\<string, string\> | Yes| HTTP headers that need to be included in the player's request for media resources.|
| attributes | Record\<string, string\> | Yes| Attributes in **\<video>** or **\<audio>**.|


## CreateNativeMediaPlayerCallback<sup>12+<sup>

type CreateNativeMediaPlayerCallback = (handler: NativeMediaPlayerHandler, mediaInfo: MediaInfo) => NativeMediaPlayerBridge

Represents a **CreateNativeMediaPlayerCallback** object used as a parameter of the [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12) callback.
This object is used to create a player to take over media playback of the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
|--------|------|------|------|
| handler | [NativeMediaPlayerHandler](#nativemediaplayerhandler12) | Yes| Object used to report the player status to the ArkWeb engine.|
| mediaInfo | [MediaInfo](#mediainfo12) | Yes| Information about the media on the web page.|

**Return value**

| Type| Description|
|------|------|
| [NativeMediaPlayerBridge](#nativemediaplayerbridge12) | Instance of the API class between the player that takes over web media and the ArkWeb kernel.<br>The application needs to implement the interface class.<br> Object used by the ArkWeb engine to control the player created by the application to take over web page media.<br>If the application returns **null**, the application does not take over the media playback, and the media will be played by the ArkWeb engine.|

**Example**

For details about the sample code, see [onCreateNativeMediaPlayer](./js-apis-webview-WebviewController.md#oncreatenativemediaplayer12).

## RectEvent<sup>12+<sup>

Defines a rectangle.

**System capability**: SystemCapability.Web.Webview.Core

| Name          | Type      | Read-Only| Optional| Description                        |
| -------------- | --------- | ---- | ---- | ---------------------------- |
| x  | number   | No  | No  | X-axis coordinate of the upper left corner of the rectangle.   |
| y  | number   | No  | No  | Y-axis coordinate of the upper left corner of the rectangle.   |
| width  | number   | No  | No  | Width of the rectangle.   |
| height  | number   | No  | No  | Height of the rectangle.   |

## BackForwardCacheSupportedFeatures<sup>12+<sup>

Adds a page that uses any of the following features to the back-forward cache. For details about the sample code, see [enableBackForwardCache](./js-apis-webview-WebviewController.md#enablebackforwardcache12).

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| nativeEmbed | boolean | Yes| Whether to add a page that uses same-layer rendering to the back-forward cache.<br>When the value is set to **true**, you need to maintain the lifecycle of system components created for the same-layer rendering elements to avoid resource leak.<br>The value **true** means to add a page that uses same-layer rendering to the back-forward cache, and **false** means the opposite.<br>The default value is **false**.|
| mediaTakeOver | boolean | Yes| Whether to add a page using media playback takeover to the back-forward cache.<br>When the value is set to **true**, you need to maintain the lifecycle of system components created for video elements to avoid resource leak.<br>The value **true** means to add a page using media playback takeover to the back-forward cache, and **false** means the opposite.<br>The default value is **false**.|

### constructor<sup>12+</sup>

constructor()

Constructs a **BackForwardCacheSupportedFeatures** instance.

**System capability**: SystemCapability.Web.Webview.Core

## BackForwardCacheOptions<sup>12+<sup>

Implements a **BackForwardCacheOptions** object to set back-forward cache options of the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name| Type| Mandatory| Description|
|------|------|------|------|
| size | number | Yes| The maximum number of pages that can be cached in a **Web** component.<br>The default value is **1**, and the maximum value is **50**.<br>If this parameter is set to **0** or a negative value, the back-forward cache is disabled.<br>The web reclaims the cache for memory pressure.|
| timeToLive | number | Yes| The time that a **Web** component allows a page to stay in the back-forward cache.<br>If this parameter is set to **0** or a negative value, the back-forward cache is disabled.<br>Default value: **600**<br>Unit: second.|

### constructor<sup>12+</sup>

constructor()

Constructs a **BackForwardCacheOptions** instance.

**System capability**: SystemCapability.Web.Webview.Core

## AdsBlockManager<sup>12+</sup>

Implements an **AdsBlockManager** instance to set custom ad blocking configurations in the **Web** components and disable the ad blocking feature for specific websites. Each application's **Web** components share an **AdsBlockManager** instance.

### setAdsBlockRules<sup>12+</sup>

static setAdsBlockRules(rulesFile: string, replace: boolean): void

Sets a custom ad blocking rule file that conforms to the universal EasyList syntax in the **Web** components.

> **NOTE**
>
> The ad blocking rules set by this API will be persistently stored after successful internal parsing; you do not need to set them again after the application is restarted.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| rulesFile | string | Yes  | Path to the rule file that conforms to the universal EasyList syntax. The application needs to have read permission for this file.|
| replace   | boolean | Yes  | Whether to replace the built-in default rules. The value **true** indicates that the built-in default rules will be forcibly replaced; **false** indicates that the custom rules will work alongside the built-in default rules.|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { picker, fileUri } from '@kit.CoreFileKit';

// This example demonstrates how to click a button to open an EasyList-compliant rule file through filepicker and set the file in the Web component.
@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Row() {
      Flex() {
        Button({ type: ButtonType.Capsule }) {
          Text("setAdsBlockRules")
        }
        .onClick(() => {
          try {
            let documentSelectionOptions: ESObject = new picker.DocumentSelectOptions();
            let documentPicker: ESObject = new picker.DocumentViewPicker();
            documentPicker.select(documentSelectionOptions).then((documentSelectResult: ESObject) => {
              if (documentSelectResult && documentSelectResult.length > 0) {
                let fileRealPath = new fileUri.FileUri(documentSelectResult[0]);
                console.info('DocumentViewPicker.select successfully, uri: ' + fileRealPath);
                webview.AdsBlockManager.setAdsBlockRules(fileRealPath.path, true);
              }
            })
          } catch (err) {
            console.error('DocumentViewPicker.select failed with err:' + err);
          }
        })
      }
    }
  }
}
```

### addAdsBlockDisallowedList<sup>12+</sup>

static addAdsBlockDisallowedList(domainSuffixes: Array\<string\>): void

Adds an array of domain names to the disallowed list of this **AdsBlockManager** object. When the ad blocking feature is enabled, ad blocking for these websites will be disabled.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted.
>
> The ad blocking feature matches website URLs based on the suffix. For example, if the disallowed list contains **'example.com'** or **'www.example.com'**, then ad blocking will be disabled for sites **https://www.example.com** and **https://m.example.com**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to add an array of domain names to the disallowed list.
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("addAdsBlockDisallowedList") }
          .onClick(() => {
            let arrDomainSuffixes = new Array<string>();
            arrDomainSuffixes.push('example.com');
            arrDomainSuffixes.push('abcdefg.cn');
            webview.AdsBlockManager.addAdsBlockDisallowedList(arrDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

### removeAdsBlockDisallowedList<sup>12+</sup>

static removeAdsBlockDisallowedList(domainSuffixes: Array\<string\>): void

Removes an array of domain names from the disallowed list of this **AdsBlockManager** object.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted. Removing an entry that does not exist does not trigger an exception.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to remove an array of domain names from the disallowed list.
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("removeAdsBlockDisallowedList") }
          .onClick(() => {
            let arrDomainSuffixes = new Array<string>();
            arrDomainSuffixes.push('example.com');
            arrDomainSuffixes.push('abcdefg.cn');
            webview.AdsBlockManager.removeAdsBlockDisallowedList(arrDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

### clearAdsBlockDisallowedList<sup>12+</sup>

static clearAdsBlockDisallowedList(): void

Clears the disallowed list of this **AdsBlockManager** object.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("clearAdsBlockDisallowedList") }
          .onClick(() => {
            webview.AdsBlockManager.clearAdsBlockDisallowedList();
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

### addAdsBlockAllowedList<sup>12+</sup>

static addAdsBlockAllowedList(domainSuffixes: Array\<string\>): void

Adds an array of domain names to the allowed list of this **AdsBlockManager** object. This API is typically used to re-enable ad blocking for certain websites that were previously added to the disallowed list.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted.
>
> The priority of the allowed list is higher than that of the disallowed list. For example, if the disallowed list includes **['example.com']**, all pages under the **example.com** domain will have their ad blocking disabled; to re-enable ad blocking for the subdomain **news.example.com**, you can use the **addAdsBlockAllowedList(['news.example.com'])** API.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to add an array of domain names to the disallowed list.
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("addAdsBlockAllowedList") }
          .onClick(() => {
            let arrDisallowDomainSuffixes = new Array<string>();
            arrDisallowDomainSuffixes.push('example.com');
            webview.AdsBlockManager.addAdsBlockDisallowedList(arrDisallowDomainSuffixes);

            let arrAllowedDomainSuffixes = new Array<string>();
            arrAllowedDomainSuffixes.push('news.example.com');
            webview.AdsBlockManager.addAdsBlockAllowedList(arrAllowedDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true)
        })
    }
  }
}
```

### removeAdsBlockAllowedList<sup>12+</sup>

static removeAdsBlockAllowedList(domainSuffixes: Array\<string\>): void

Removes an array of domain names from the allowed list of this **AdsBlockManager** object.

> **NOTE**
>
> The domain name set by this API is not persistent; they need to be set again after the application is restarted. Removing an entry that does not exist does not trigger an exception.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory| Description                              |
| ---------- | ------ | ---- | -------------------------------- |
| domainSuffixes | Array\<string\> | Yes  | Array of domain names, for example, ['example.com', 'abcd.efg.com'].|

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

// This example demonstrates how to click a button to remove an array of domain names from the disallowed list.
@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';

  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("removeAdsBlockAllowedList") }
          .onClick(() => {
            let arrDomainSuffixes = new Array<string>();
            arrDomainSuffixes.push('example.com');
            arrDomainSuffixes.push('abcdefg.cn');
            webview.AdsBlockManager.removeAdsBlockAllowedList(arrDomainSuffixes);
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
        .onControllerAttached(()=>{
          this.controller.enableAdsBlock(true);
        })
    }
  }
}
```

### clearAdsBlockAllowedList<sup>12+</sup>

static clearAdsBlockAllowedList(): void

Clears the allowed list of this **AdsBlockManager** object.

**System capability**: SystemCapability.Web.Webview.Core

**Error codes**

> **NOTE**
>
> Since API version 18, exception 801 will be thrown when this API is called on a device that does not support ad blocking.

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                 |
| -------- | ----------------------- |
|  801 | Capability not supported. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  main_url: string = 'https://www.example.com';
  text_input_controller: TextInputController = new TextInputController();
  controller: webview.WebviewController = new webview.WebviewController();
  @State input_text: string = 'https://www.example.com';


  build() {
    Column() {
      Row() {
        Flex() {
          TextInput({ text: this.input_text, placeholder: this.main_url, controller: this.text_input_controller})
            .id("input_url")
            .height(40)
            .margin(5)
            .borderColor(Color.Blue)
            .onChange((value: string) => {
              this.input_text = value;
            })

          Button({type: ButtonType.Capsule}) { Text("Go") }
          .onClick(() => {
            this.controller.loadUrl(this.input_text);
          })

          Button({type: ButtonType.Capsule}) { Text("clearAdsBlockAllowedList") }
          .onClick(() => {
            webview.AdsBlockManager.clearAdsBlockAllowedList();
          })
        }
      }
      Web({ src: this.main_url, controller: this.controller })
      .onControllerAttached(()=>{
        this.controller.enableAdsBlock(true);
      })
    }
  }
}
```

## PdfData<sup>14+</sup>

Represents the output data stream class of **createPdf()**.

> **NOTE**
>
> When a PDF file is generated on a web page, a data stream is returned, which is encapsulated by the **PdfData** class.

### pdfArrayBuffer<sup>14+</sup>

pdfArrayBuffer(): Uint8Array

Obtains the data stream generated by a web page. For details about the sample code, see [createPdf](./js-apis-webview-WebviewController.md#createpdf14).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type      | Description    |
| ---------- | -------- |
| Uint8Array | Data stream.|
