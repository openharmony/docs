# Class (WebHttpBodyStream)

Represents the body of the data being sent in POST and PUT requests. It accepts data of the BYTES, FILE, BLOB, and CHUNKED types. Note that other APIs in this class can be called only after [initialize](#initialize12) is called successfully.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this class are supported since API version 12.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Modules to Import

```ts
import { webview } from '@kit.ArkWeb';
```

## initialize<sup>12+</sup>

initialize(): Promise\<void\>

Initializes this **WebHttpBodyStream** instance.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| Error Code| Error Message                             |
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

## read<sup>12+</sup>

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

| Error Code| Error Message                             |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.    |

**Example**

For the complete sample code, see [initialize](#initialize12).

## getSize<sup>12+</sup>

getSize(): number

Obtains the size of data in this **WebHttpBodyStream** instance. This API always returns zero when chunked transfer is used.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Size of data in the current **WebHttpBodyStream** instance.|

**Example**

For the complete sample code, see [initialize](#initialize12).

## getPosition<sup>12+</sup>

getPosition(): number

Reads the current read position in this **WebHttpBodyStream** instance.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | Current read position in the **WebHttpBodyStream** instance.|

**Example**

For the complete sample code, see [initialize](#initialize12).

## isChunked<sup>12+</sup>

isChunked(): boolean

Checks whether this **WebHttpBodyStream** instance is transmitted by chunk.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Whether the **WebHttpBodyStream** instance is transmitted by chunk. The value **true** indicates that the **WebHttpBodyStream** instance is transmitted by chunk, and **false** indicates the opposite.|

**Example**

For the complete sample code, see [initialize](#initialize12).

## isEof<sup>12+</sup>

isEof(): boolean

Checks whether all data in this **WebHttpBodyStream** instance has been read.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Whether all data in the **WebHttpBodyStream** instance has been read.<br>This API returns **true** if all data in the **httpBodyStream** instance is read. It returns **false** before the first read attempt is made for the **WebHttpBodyStream** instance that uses chunked transfer.|

**Example**

For the complete sample code, see [initialize](#initialize12).

## isInMemory<sup>12+</sup>

isInMemory(): boolean

Checks whether the uploaded data in this **WebHttpBodyStream** instance is in memory.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| boolean | Whether the uploaded data in the **WebHttpBodyStream** instance is stored in memory.<br>This API returns **true** if all the upload data in the **WebHttpBodyStream** instance is in memory and all read requests will be completed synchronously. **false** is returned if the data is chunked.|

**Example**

For the complete sample code, see [initialize](#initialize12).
