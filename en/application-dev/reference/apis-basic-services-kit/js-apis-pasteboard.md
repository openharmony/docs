# @ohos.pasteboard (Pasteboard)

The **Pasteboard** module provides the copy and paste support for the system pasteboard. You can use the APIs of this module to operate pasteboard content of the plain text, HTML, URI, Want, pixel map, and other types.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { pasteboard } from '@kit.BasicServicesKit';
```

## Constants

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Value           | Description                                                                                                                                       |
| -------- | -------- |--------------|-------------------------------------------------------------------------------------------------------------------------------------------|
| MAX_RECORD_NUM<sup>7+</sup> | number | -            | Maximum number of records in a **PasteData** object. In versions earlier than API version 10, the value is 512, indicating that no more records can be added once the number of records reaches 512.<br>Since API version 10, no limit is placed on the number of records in a **PasteData** object.|
| MIMETYPE_TEXT_HTML<sup>7+</sup> | string | 'text/html'  | MIME type of the HTML content.                                                                                                                         |
| MIMETYPE_TEXT_WANT<sup>7+</sup> | string | 'text/want'  | MIME type of the Want content.                                                                                                                         |
| MIMETYPE_TEXT_PLAIN<sup>7+</sup> | string | 'text/plain' | MIME type of the plain text content.                                                                                                                          |
| MIMETYPE_TEXT_URI<sup>7+</sup> | string | 'text/uri'   | MIME type of the URI content.                                                                                                                          |
| MIMETYPE_PIXELMAP<sup>9+</sup> | string | 'pixelMap'   | MIME type of the pixel map.                                                                                                                     |

## ValueType<sup>9+</sup>

type ValueType = string | image.PixelMap | Want | ArrayBuffer

Enumerates the value types.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Type| Description|
| -------- | -------- |
| string | The value is a string.|
| image.PixelMap | The value is of the [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) type.|
| Want | The value is of the [Want](../apis-ability-kit/js-apis-app-ability-want.md) type.|
| ArrayBuffer | The value is of the **ArrayBuffer** type.|

## pasteboard.createData<sup>9+</sup>

createData(mimeType: string, value: ValueType): PasteData

Creates a **PasteData** object of a custom type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description                                                                                                    |
| -------- | -------- | -------- |--------------------------------------------------------------------------------------------------------|
| mimeType | string | Yes| MIME type of custom data. The value can a predefined MIME type listed in [Constants](#constants), including HTML, WANT, plain text, URI, and pixel map, or a custom MIME type. The value of **mimeType** cannot exceed 1024 bytes.|
| value | [ValueType](#valuetype9) | Yes| Content of custom data.                                                                                              |

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) |  **PasteData** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example 1**

  ```ts
  let dataXml = new ArrayBuffer(256);
  let pasteData: pasteboard.PasteData = pasteboard.createData('app/xml', dataXml);
  ```

**Example 2**

  ```ts
 let dataText = 'hello';
 let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, dataText);
  ```

## pasteboard.createData<sup>14+</sup>

createData(data: Record&lt;string, ValueType&gt;): PasteData

Creates a **PasteData** object that contains multiple types of data.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type                                            | Mandatory| Description                                                                                                                                                                                                                                                                                         |
| -------- |------------------------------------------------| -------- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| data | Record&lt;string, [ValueType](#valuetype9)&gt; | Yes| The key of **Record** can be the MIME type corresponding to the pasteboard data, including HTML, WANT, plain text, URI, and PixelMap defined in [Constants](#constants). Alternatively, the key could be a custom MIME type, whose parameter, the length of **mimeType**, cannot exceed 1024 bytes.<br>The value of **Record** is the custom data corresponding to the MIME type specified in the key.<br>The first MIME type specified by the key-value in **Record** is used as the default MIME type of the first **PasteDataRecord** in the **PasteData** object. Data of non-default types can be read only by using the [getData](#getdata14) API.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) |  **PasteData** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example 1**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData({
    'text/plain': 'hello',
    'app/xml': new ArrayBuffer(256),
});
```

**Example 2**

```ts
let record: Record<string, pasteboard.ValueType> = {};
record[pasteboard.MIMETYPE_TEXT_PLAIN] = 'hello';
record[pasteboard.MIMETYPE_TEXT_URI] = 'dataability:///com.example.myapplication1/user.txt';
let pasteData: pasteboard.PasteData = pasteboard.createData(record);
```

## pasteboard.createRecord<sup>9+</sup>

createRecord(mimeType: string, value: ValueType):PasteDataRecord

Creates a **PasteDataRecord** object of the custom type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description               |
| -------- | -------- | -------- |-------------------|
| mimeType | string | Yes| MIME type of custom data. The value can a predefined MIME type listed in [Constants](#constants), including HTML, WANT, plain text, URI, and pixel map, or a custom MIME type. The value of **mimeType** cannot exceed 1024 bytes. |
| value | [ValueType](#valuetype9) | Yes| Content of custom data.         |

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the custom type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types;  3. Parameter verification failed. |

**Example 1**

  ```ts
let dataXml = new ArrayBuffer(256);
let pasteDataRecord: pasteboard.PasteDataRecord = pasteboard.createRecord('app/xml', dataXml);
  ```

**Example 2**

  ```ts
let dataUri = 'dataability:///com.example.myapplication1/user.txt';
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, dataUri);
  ```

## pasteboard.getSystemPasteboard

getSystemPasteboard(): SystemPasteboard

Obtains this **SystemPasteboard** object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [SystemPasteboard](#systempasteboard) | **SystemPasteboard** object.|

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
```

## ShareOption<sup>9+</sup>

Enumerates the pasteable ranges of pasteboard data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name                              | Value | Description                                                                                 |
| ---------------------------------- | --- | ------------------------------------------------------------------------------------- |
| INAPP                              | 0   | Only intra-application pasting is allowed.                                                             |
| LOCALDEVICE                        | 1   | Paste is allowed in any application on the local device.                                                   |
| CROSSDEVICE<sup>(deprecated)</sup> | 2   | Paste is allowed in any application across devices.<br>This API has been deprecated since API Version 12. No alternative API or method is available. You can choose **Settings** > **Multi-Device Collaboration** > **Cross-Device Clipboard Switch** to set whether to allow cross-device pasting.|

## pasteboard.createHtmlData<sup>(deprecated)</sup>

createHtmlData(htmlText: string): PasteData

Creates a **PasteData** object of the HTML type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| htmlText | string | Yes| HTML content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let pasteData: pasteboard.PasteData = pasteboard.createHtmlData(html);
```

## pasteboard.createWantData<sup>(deprecated)</sup>

createWantData(want: Want): PasteData

Creates a **PasteData** object of the Want type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let pasteData: pasteboard.PasteData = pasteboard.createWantData(object);
```

## pasteboard.createPlainTextData<sup>(deprecated)</sup>

createPlainTextData(text: string): PasteData

Creates a **PasteData** object of the plain text type.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Plain text.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
```

## pasteboard.createUriData<sup>(deprecated)</sup>

createUriData(uri: string): PasteData

Creates a **PasteData** object of the URI type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createData](#pasteboardcreatedata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteData](#pastedata) | **PasteData** object.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
```
## pasteboard.createHtmlTextRecord<sup>(deprecated)</sup>

createHtmlTextRecord(htmlText: string): PasteDataRecord

Creates a **PasteDataRecord** object of the HTML text type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| htmlText | string | Yes| HTML content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | **PasteDataRecord** object of the HTML text type.|

**Example**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record: pasteboard.PasteDataRecord = pasteboard.createHtmlTextRecord(html);
```

## pasteboard.createWantRecord<sup>(deprecated)</sup>

createWantRecord(want: Want): PasteDataRecord

Creates a **PasteDataRecord** object of the Want type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the Want type.|

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let record: pasteboard.PasteDataRecord = pasteboard.createWantRecord(object);
```

## pasteboard.createPlainTextRecord<sup>(deprecated)</sup>

createPlainTextRecord(text: string): PasteDataRecord

Creates a **PasteDataRecord** object of the plain text type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Plain text.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the plain text type.|

**Example**

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createPlainTextRecord('hello');
```

## pasteboard.createUriRecord<sup>(deprecated)</sup>

createUriRecord(uri: string): PasteDataRecord

Creates a **PasteDataRecord** object of the URI type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.createRecord](#pasteboardcreaterecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI content.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | New **PasteDataRecord** object of the URI type.|

**Example**

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
```


## PasteDataProperty<sup>7+</sup>

Defines the properties of all data records on the pasteboard, including the timestamp, data type, and additional data.
The defined properties can be applied to the pasteboard only with the [setProperty](#setproperty9) API.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Readable| Writable| Description                                                                                                                                                                                                                                      |
| -------- | -------- | -------- | -------- |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| additions<sup>7+</sup> | {[key:string]:object} | Yes| Yes| Additional data. It does not allow for dynamic adding of attributes. Attributes can be added only by re-assigning values. For details, see the example of **setProperty**.                                                                                                                                                                                                                             |
| mimeTypes<sup>7+</sup> | Array&lt;string&gt; | Yes| No| Non-repeating data types of the data records on the pasteboard.                                                                                                                                                                                                                  |
| tag<sup>7+</sup> | string | Yes| Yes| Custom tag.                                                                                                                                                                                                                                |
| timestamp<sup>7+</sup> | number | Yes| No| Timestamp when data is written to the pasteboard (unit: ms).                                                                                                                                                                                                                     |
| localOnly<sup>7+</sup> | boolean | Yes| Yes| Whether the pasteboard content is for local access only. The default value is **false**. The value will be overwritten by the value of the **shareOption** attribute. You are advised to use the **shareOption** attribute instead. **ShareOption.INAPP** and **ShareOption.LOCALDEVICE** set **localOnly** to **true**, and **ShareOption.CROSSDEVICE** sets **localOnly** to false.<br>- **true**: The pasteboard content is set for local access only.<br>- **false**: The pasteboard content can be shared between devices.|
| shareOption<sup>9+</sup> | [ShareOption](#shareoption9) | Yes| Yes| Where the pasteboard content can be pasted. If this attribute is set incorrectly or not set, the default value **CROSSDEVICE** is used.                                                                                                                                                                                           |

## FileConflictOptions<sup>15+</sup>

Defines options for file copy conflicts.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name     | Value  | Description                                                        |
| --------- | ---- | ------------------------------------------------------------ |
| OVERWRITE | 0    | Overwrites the file with the same name in the destination path.                                |
| SKIP      | 1    | Skips the file with the same name in the destination path. If **SKIP** is set, the copied data of the skipped file is not pasted to the application.|

## ProgressIndicator<sup>15+</sup>

Defines options for the progress indicator. You can choose whether to use the default progress indicator.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name   | Value  | Description                    |
| ------- | ---- | ------------------------ |
| NONE    | 0    | The default progress indicator is not used.|
| DEFAULT | 1    | The default progress indicator is used.  |

## ProgressInfo<sup>15+</sup>

Defines the progress information. This information is reported only when [ProgressIndicator](#progressindicator15) is set to **NONE**.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name    | Type  | Readable| Writable| Description                                                      |
| -------- | ------ | ---- | ---- | ---------------------------------------------------------- |
| progress | number | Yes  | No  | If the progress indicator provided by the system is not used, the system reports the progress percentage of the copy-and-paste task.|

## ProgressListener<sup>15+</sup>

type ProgressListener = (progress: ProgressInfo) => void

Defines a listener for progress data changes. If the default progress indicator is not used, you can set this API to obtain the paste progress.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name  | Type                           | Mandatory| Description                                                        |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| progress | [ProgressInfo](#progressinfo15) | Yes  | Defines the progress information. This information is reported only when [ProgressIndicator](#progressindicator15) is set to **NONE**.|

## ProgressSignal<sup>15+</sup>

Defines a function for canceling the paste task. This parameter is valid only when [ProgressIndicator](#progressindicator15) is set to **NONE**.

**System capability**: SystemCapability.MiscServices.Pasteboard

### cancel

cancel(): void

Cancels an ongoing copy-and-paste task.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Example**

```ts
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';
@Entry
@Component
struct PasteboardTest {
 build() {
   RelativeContainer() {
     Column() {
       Column() {
         Button("Copy txt")
           .onClick(async ()=>{
              let text = "test";
              let pasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, text);
              let systemPasteboard = pasteboard.getSystemPasteboard();
        	  await systemPasteboard.setData(pasteData);
              let signal = new pasteboard.ProgressSignal;
              let ProgressListener = (progress: pasteboard.ProgressInfo) => {
    		    console.log('progressListener success, progress:' + progress.progress);
                signal.cancel();
              }
              let params: pasteboard.GetDataParams = {
                destUri: '/data/storage/el2/base/haps/entry/files/dstFile.txt',
                fileConflictOptions: pasteboard.FileConflictOptions.OVERWRITE,
                progressIndicator: pasteboard.ProgressIndicator.DEFAULT,
                progressListener: ProgressListener
              };
              systemPasteboard.getDataWithProgress(params).then((pasteData: pasteboard.PasteData) => {
                console.error('getDataWithProgress succ');
              }).catch((err: BusinessError) => {
                console.error('Failed to get PasteData. Cause: ' + err.message);
              })   
          })
        }
      }
    }
  }
}
```

## GetDataParams<sup>15+</sup>

Obtains parameters when an application uses the file copy capability provided by the pasteboard, including the destination path, file conflict options, and progress indicator types.

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name               | Type                                         | Mandatory| Description                                                        |
| ------------------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| destUri             | string                                        | No  | Destination path for copying files. If file processing is not supported, this parameter is not required. If the application involves complex file processing policies or needs to distinguish file multipathing storage, you are advised not to set this parameter but let the application copies files by itself.|
| fileConflictOptions | [FileConflictOptions](#fileconflictoptions15) | No  | File conflict options for a copy-and-paste task. The default value is **OVERWRITE**.                 |
| progressIndicator   | [ProgressIndicator](#progressindicator15)     | Yes  | Progress indicator options. You can choose whether to use the default progress indicator.        |
| progressListener    | [ProgressListener](#progresslistener15)       | No  | Listener for progress data changes. If the default progress indicator is not used, you can set this parameter to obtain the paste progress.|
| progressSignal      | [ProgressSignal](#progresssignal15)           | No  | Function for canceling the paste task. This parameter is valid only when [ProgressIndicator](#progressindicator15) is set to **NONE**.|

## PasteDataRecord<sup>7+</sup>

Provides **PasteDataRecord** APIs. A **PasteDataRecord** is an abstract definition of the content on the pasteboard. The pasteboard content consists of one or more plain text, HTML, URI, or Want records.

### Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| htmlText<sup>7+</sup> | string | Yes| No| HTML content.|
| want<sup>7+</sup> | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| No| Want content.|
| mimeType<sup>7+</sup> | string | Yes| No| Data type.|
| plainText<sup>7+</sup> | string | Yes| No| Plain text.|
| uri<sup>7+</sup> | string | Yes| No| URI content.|
| pixelMap<sup>9+</sup> | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Yes| No| Pixel map.|
| data<sup>9+</sup> | {[mimeType:&nbsp;string]:&nbsp;ArrayBuffer} | Yes| No| Content of custom data.|

### toPlainText<sup>9+</sup>

toPlainText(): string

Forcibly converts HTML, plain, and URI content in a **PasteDataRecord** to the plain text.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Plain text.|

**Example**

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
let data: string = record.toPlainText();
console.info(`Succeeded in converting to text. Data: ${data}`);
```

### addEntry<sup>14+</sup>

addEntry(type: string, value: ValueType): void

Adds custom data of an extra type to **PasteDataRecord**. The MIME type added using this method is not the default type of **Record**. You can only use the [getData](#getdata14) API to read the corresponding data.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name  | Type| Mandatory| Description               |
|-------| -------- | -------- |-------------------|
| type  | string | Yes| MIME type of custom data. The value can a predefined MIME type listed in [Constants](#constants), including HTML, WANT, plain text, URI, and pixel map, or a custom MIME type. The value of **mimeType** cannot exceed 1024 bytes. |
| value | [ValueType](#valuetype9) | Yes| Content of custom data.         |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
record.addEntry(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
record.addEntry(pasteboard.MIMETYPE_TEXT_HTML, html);
```

### getValidTypes<sup>14+</sup>

getValidTypes(types: Array&lt;string&gt;): Array&lt;string&gt;

Obtains the intersection of the input MIME type and the MIME type of the pasteboard data.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name  | Type| Mandatory| Description            |
|-------| -------- | -------- |----------------|
| types | Array&lt;string&gt; | Yes| List of the MIME types.|

**Return value**

| Type| Description                                  |
| -------- |--------------------------------------|
| Array&lt;string&gt; | Intersection of the input MIME type and the MIME type of the pasteboard data obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
record.addEntry(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
record.addEntry(pasteboard.MIMETYPE_TEXT_HTML, html);
let types: string[] = record.getValidTypes([
    pasteboard.MIMETYPE_TEXT_PLAIN,
    pasteboard.MIMETYPE_TEXT_HTML,
    pasteboard.MIMETYPE_TEXT_URI,
    pasteboard.MIMETYPE_TEXT_WANT,
    pasteboard.MIMETYPE_PIXELMAP
]);
```

### getData<sup>14+</sup>

getData(type: string): Promise&lt;ValueType&gt;

Obtains custom data of the specified MIME type from **PasteDataRecord**.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name | Type    |Mandatory| Description      |
|------|--------|-------- |----------|
| type | string |Yes| MIME type.|

**Return value**

| Type                                     | Description                                                                                                                  |
|-----------------------------------------|----------------------------------------------------------------------------------------------------------------------|
| Promise&lt;[ValueType](#valuetype9)&gt; | Promise used to return the custom data of the specified MIME type.<br>If **PasteDataRecord** contains data of multiple MIME types, the non-**PasteDataRecord** data of the default MIME type can be obtained only through this API.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
record.addEntry(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
record.addEntry(pasteboard.MIMETYPE_TEXT_HTML, html);
record.getData(pasteboard.MIMETYPE_TEXT_PLAIN).then((value: pasteboard.ValueType) => {
    let textPlainContent = value as string;
    console.info('Success to get text/plain value. value is: ' + textPlainContent);
}).catch((err: BusinessError) => {
    console.error('Failed to get text/plain value. Cause: ' + err.message);
});
record.getData(pasteboard.MIMETYPE_TEXT_URI).then((value: pasteboard.ValueType) => {
    let uri = value as string;
    console.info('Success to get text/uri value. value is: ' + uri);
}).catch((err: BusinessError) => {
    console.error('Failed to get text/uri value. Cause: ' + err.message);
});
```

### convertToText<sup>(deprecated)</sup>

convertToText(callback: AsyncCallback&lt;string&gt;): void

Forcibly converts the content in a **PasteData** object to text. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [toPlainText](#toplaintext9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the text obtained from the conversion. Otherwise, **err** is error information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToText((err: BusinessError, data: string) => {
    if (err) {
        console.error(`Failed to convert to text. Cause: ${err.message}`);
        return;
    }
    console.info(`Succeeded in converting to text. Data: ${data}`);
});
```

### convertToText<sup>(deprecated)</sup>

convertToText(): Promise&lt;string&gt;

Forcibly converts the content in a **PasteData** object to text. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [toPlainText](#toplaintext9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the text obtained from the conversion.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToText().then((data: string) => {
    console.info(`Succeeded in converting to text. Data: ${data}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to convert to text. Cause: ${err.message}`);
});
```

## PasteData

Implements a **PasteData** object. Paste data contains one or more data records ([PasteDataRecord](#pastedatarecord7)) and property description objects ([PasteDataProperty](#pastedataproperty7)).

Before calling any API in **PasteData**, you must use **[createData()](#pasteboardcreatedata9)** or **[getData()](#getdata9)** to create a **PasteData** object.

**System capability**: SystemCapability.MiscServices.Pasteboard

### getPrimaryText

getPrimaryText(): string

Obtains the plain text of the primary record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Plain text.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let plainText: string = pasteData.getPrimaryText();
```

### getPrimaryHtml<sup>7+</sup>

getPrimaryHtml(): string

Obtains the HTML content of the primary record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | HTML content.|

**Example**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_HTML, html);
let htmlText: string = pasteData.getPrimaryHtml();
```

### getPrimaryWant<sup>7+</sup>

getPrimaryWant(): Want

Obtains the Want object of the primary record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Want object.|

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_WANT, object);
let want: Want = pasteData.getPrimaryWant();
```

### getPrimaryUri<sup>7+</sup>

getPrimaryUri(): string

Obtains the URI of the primary record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | URI content.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
let uri: string = pasteData.getPrimaryUri();
```

### getPrimaryPixelMap<sup>9+</sup>

getPrimaryPixelMap(): image.PixelMap

Obtains the pixel map of the primary record.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | Pixel map.|

**Example**

```ts
import { image } from '@kit.ImageKit';

let buffer = new ArrayBuffer(128);
let realSize: image.Size = { height: 3, width: 5 };
let opt: image.InitializationOptions = {
    size: realSize,
    pixelFormat: 3,
    editable: true,
    alphaType: 1,
    scaleMode: 1
};
image.createPixelMap(buffer, opt).then((pixelMap: image.PixelMap) => {
    let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_PIXELMAP, pixelMap);
    let PixelMap: image.PixelMap = pasteData.getPrimaryPixelMap();
});
```

### addRecord<sup>7+</sup>

addRecord(record: PasteDataRecord): void

Adds a data record to this pasteboard, and adds its type to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| record | [PasteDataRecord](#pastedatarecord7) | Yes| Record to add.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
let textRecord: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let html: string = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let htmlRecord: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_HTML, html);
pasteData.addRecord(textRecord);
pasteData.addRecord(htmlRecord);
```
### addRecord<sup>9+</sup>

addRecord(mimeType: string, value: ValueType): void

Adds a custom-type record to this pasteboard, and adds the custom type to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| MIME type of custom data. The length cannot exceed 1024 bytes.|
| value | [ValueType](#valuetype9) | Yes| Content of custom data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example**

  ```ts
  let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
  let dataXml = new ArrayBuffer(256);
  pasteData.addRecord('app/xml', dataXml);
  ```

### getMimeTypes<sup>7+</sup>

getMimeTypes(): Array&lt;string&gt;

Obtains a list of **mimeTypes** objects in [PasteDataProperty](#pastedataproperty7) from this pasteboard. If the pasteboard is empty, the returned list is also empty.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Array&lt;string&gt; | Non-repeating data types of the data records on the pasteboard.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let types: string[] = pasteData.getMimeTypes();
```

### getPrimaryMimeType<sup>7+</sup>

getPrimaryMimeType(): string

Obtains the data type of the primary record in this pasteboard.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Data type of the primary record.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let type: string = pasteData.getPrimaryMimeType();
```

### getProperty<sup>7+</sup>

getProperty(): PasteDataProperty

Obtains the property of the pasteboard data.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataProperty](#pastedataproperty7) | Property of the pasteboard data.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let property: pasteboard.PasteDataProperty = pasteData.getProperty();
```

### setProperty<sup>9+</sup>

setProperty(property: PasteDataProperty): void

Sets a [PasteDataProperty](#pastedataproperty7) object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| property | [PasteDataProperty](#pastedataproperty7) | Yes| Property of the pasteboard data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
type AdditionType = Record<string, Record<string, Object>>;

let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_HTML, 'application/xml');
let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
prop.shareOption = pasteboard.ShareOption.INAPP;
// Note that attributes cannot be added to additions. Attributes can be added only by re-assigning values.
prop.additions = { 'TestOne': { 'Test': 123 }, 'TestTwo': { 'Test': 'additions' } } as AdditionType;
prop.tag = 'TestTag';
pasteData.setProperty(prop);
```
The **localOnly** and **shareOption** attributes of [PasteDataProperty](#pastedataproperty7) are mutually exclusive. The **shareOption** attribute is prioritized, and its value affects the value of **localOnly**.
```ts
(async () => {
    let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
    let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
    prop.shareOption = pasteboard.ShareOption.INAPP;
    prop.localOnly = false;
    pasteData.setProperty(prop);
    let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();

    await systemPasteboard.setData(pasteData).then(async () => {
        console.info('Succeeded in setting PasteData.');
        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
            prop.localOnly; // true
        });
    });

    prop.shareOption = pasteboard.ShareOption.LOCALDEVICE;
    prop.localOnly = false;
    pasteData.setProperty(prop);

    await systemPasteboard.setData(pasteData).then(async () => {
        console.info('Succeeded in setting PasteData.');
        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
            prop.localOnly; // true
        });
    });

    prop.shareOption = pasteboard.ShareOption.CROSSDEVICE;
    prop.localOnly = true;
    pasteData.setProperty(prop);

    await systemPasteboard.setData(pasteData).then(async () => {
        console.info('Succeeded in setting PasteData.');
        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
            prop.localOnly; // false
        });
    });
})()
```

### getRecord<sup>9+</sup>

getRecord(index: number): PasteDataRecord

Obtains the record with a specific index from the pasteboard.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Index of the target record.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | Record with the specified index.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let record: pasteboard.PasteDataRecord = pasteData.getRecord(0);
```

### getRecordCount<sup>7+</sup>

getRecordCount(): number

Obtains the number of records in the pasteboard.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of records.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let count: number = pasteData.getRecordCount();
```

### getTag<sup>7+</sup>

getTag(): string

Obtains the custom tag from the pasteboard. If no custom tag is set, null is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| string | Custom tag. If no custom tag is set, null is returned.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let tag: string = pasteData.getTag();
```

### hasType<sup>9+</sup>

hasType(mimeType: string): boolean

Checks whether the pasteboard contains data of the specified type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| Type of the data to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified data type exists; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let hasType: boolean = pasteData.hasType(pasteboard.MIMETYPE_TEXT_PLAIN);
```

### removeRecord<sup>9+</sup>

removeRecord(index: number): void

Removes the record with a specific index from the pasteboard.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
pasteData.removeRecord(0);
```

### replaceRecord<sup>9+</sup>

replaceRecord(index: number, record: PasteDataRecord): void

Replaces the record with a specific index from the pasteboard.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index.|
| record | [PasteDataRecord](#pastedatarecord7) | Yes| New record.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
pasteData.replaceRecord(0, record);
```

### pasteStart<sup>12+</sup>

pasteStart(): void

Notifies the clipboard service to retain the cross-device channel before reading data from the clipboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    pasteData.pasteStart();
    console.log(`using data: ${pasteData.getPrimaryText()}`);
    pasteData.pasteComplete();
});
```

### pasteComplete<sup>12+</sup>

pasteComplete(): void

Notifies the clipboard service that the paste is complete.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    pasteData.pasteStart();
    console.log(`using data: ${pasteData.getPrimaryText()}`);
    pasteData.pasteComplete();
});
```

### addHtmlRecord<sup>(deprecated)</sup>

addHtmlRecord(htmlText: string): void

Adds an HTML record to this pasteboard, and adds **MIMETYPE_TEXT_HTML** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| htmlText | string | Yes| HTML content.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let html: string = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
pasteData.addHtmlRecord(html);
```

### addWantRecord<sup>(deprecated)</sup>

addWantRecord(want: Want): void

Adds a Want record to this pasteboard, and adds **MIMETYPE_TEXT_WANT** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want object.|

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
pasteData.addWantRecord(object);
```

### addTextRecord<sup>(deprecated)</sup>

addTextRecord(text: string): void

Adds a plain text record to this pasteboard, and adds **MIME_TEXT_PLAIN** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| text | string | Yes| Plain text.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
pasteData.addTextRecord('good');
```

### addUriRecord<sup>(deprecated)</sup>

addUriRecord(uri: string): void

Adds a URI record to this pasteboard, and adds **MIMETYPE_TEXT_URI** to **mimeTypes** in [PasteDataProperty](#pastedataproperty7). The parameters cannot be empty. Otherwise, the operation fails.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [addRecord](#addrecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| URI content.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
pasteData.addUriRecord('dataability:///com.example.myapplication1/user.txt');
```
### getRecordAt<sup>(deprecated)</sup>

getRecordAt(index: number): PasteDataRecord

Obtains the record with a specific index from the pasteboard.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getRecord](#getrecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Index of the target record.|

**Return value**

| Type| Description|
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | Record with the specified index.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let record: pasteboard.PasteDataRecord = pasteData.getRecordAt(0);
```

### hasMimeType<sup>(deprecated)</sup>

hasMimeType(mimeType: string): boolean

Checks whether the pasteboard contains data of the specified type.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [hasType](#hastype9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mimeType | string | Yes| Type of the data to query.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the specified data type exists; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let hasType: boolean = pasteData.hasMimeType(pasteboard.MIMETYPE_TEXT_PLAIN);
```
### removeRecordAt<sup>(deprecated)</sup>

removeRecordAt(index: number): boolean

Removes the record with a specific index from the pasteboard.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [removeRecord](#removerecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let isRemove: boolean = pasteData.removeRecordAt(0);
```
### replaceRecordAt<sup>(deprecated)</sup>

replaceRecordAt(index: number, record: PasteDataRecord): boolean

Replaces the record with a specific index from the pasteboard.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [replaceRecord](#replacerecord9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| index | number | Yes| Specified index.|
| record | [PasteDataRecord](#pastedatarecord7) | Yes| New record.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
let isReplace: boolean = pasteData.replaceRecordAt(0, record);
```

## SystemPasteboard

Provides **SystemPasteboard** APIs.

Before calling any **SystemPasteboard** API, you must obtain a **SystemPasteboard** object using [getSystemPasteboard](#pasteboardgetsystempasteboard).

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
```

### on('update')<sup>7+</sup>

on(type:  'update', callback: () =&gt;void ): void

Subscribes to the content change event of the system pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value **'update'** indicates changes in the pasteboard content.|
| callback | function | Yes| Callback invoked when the pasteboard content changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
let listener = () => {
    console.info('The system pasteboard has changed.');
};
systemPasteboard.on('update', listener);
```

### off('update')<sup>7+</sup>

off(type:  'update', callback?: () =&gt;void ): void

Unsubscribes from the system pasteboard content change event.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description                                                     |
| -------- | -------- | -------- |---------------------------------------------------------|
| type | string | Yes| Event type. The value **'update'** indicates changes in the pasteboard content.                             |
| callback | function | No| Callback invoked when the pasteboard content changes. If this parameter is not specified, listening will be disabled for all callbacks registered by the current application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
let listener = () => {
    console.info('The system pasteboard has changed.');
};
systemPasteboard.off('update', listener);
```

### clearData<sup>9+</sup>

clearData(callback: AsyncCallback&lt;void&gt;): void

Clears the system pasteboard. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clearData((err, data) => {
    if (err) {
        console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);
        return;
    }
    console.info('Succeeded in clearing the pasteboard.');
});
```

### clearData<sup>9+</sup>

clearData(): Promise&lt;void&gt;

Clears the system pasteboard. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clearData().then((data: void) => {
    console.info('Succeeded in clearing the pasteboard.');
}).catch((err: BusinessError) => {
    console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);
});
```

### setData<sup>9+</sup>

setData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

Writes a **PasteData** object to the pasteboard. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object.|
| callback | AsyncCallback&lt;void> | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 27787278 | Replication is prohibited. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setData(pasteData, (err, data) => {
    if (err) {
        console.error('Failed to set PasteData. Cause: ' + err.message);
        return;
    }
    console.info('Succeeded in setting PasteData.');
});
```

### setData<sup>9+</sup>

setData(data: PasteData): Promise&lt;void&gt;

Writes a **PasteData** object to the pasteboard. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 27787278 | Replication is prohibited. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setData(pasteData).then((data: void) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```

### getData<sup>9+</sup>

getData( callback: AsyncCallback&lt;PasteData&gt;): void

Obtains a **PasteData** object from the pasteboard. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_PASTEBOARD

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the system pasteboard data. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    let text: string = pasteData.getPrimaryText();
});
```

### getData<sup>9+</sup>

getData(): Promise&lt;PasteData&gt;

Obtains a **PasteData** object from the pasteboard. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_PASTEBOARD

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise used to return the system pasteboard data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    let text: string = pasteData.getPrimaryText();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### hasData<sup>9+</sup>

hasData(callback:  AsyncCallback&lt;boolean&gt;): void

Checks whether the system pasteboard contains data. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasData((err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`Failed to check the PasteData. Cause: ${err.message}`);
        return;
    }
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
});
```

### hasData<sup>9+</sup>

hasData(): Promise&lt;boolean&gt;

Checks whether the system pasteboard contains data. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasData().then((data: boolean) => {
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### clear<sup>(deprecated)</sup>

clear(callback: AsyncCallback&lt;void&gt;): void

Clears the system pasteboard. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.clearData](#cleardata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clear((err, data) => {
    if (err) {
        console.error(`Failed to clear the PasteData. Cause: ${err.message}`);
        return;
    }
    console.info('Succeeded in clearing the PasteData.');
});
```

### clear<sup>(deprecated)</sup>

clear(): Promise&lt;void&gt;

Clears the system pasteboard. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [pasteboard.clearData](#cleardata9-1).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clear().then((data) => {
    console.info('Succeeded in clearing the PasteData.');
}).catch((err: BusinessError) => {
    console.error(`Failed to clear the PasteData. Cause: ${err.message}`);
});
```

### getPasteData<sup>(deprecated)</sup>

getPasteData( callback: AsyncCallback&lt;PasteData&gt;): void

Obtains a **PasteData** object from the pasteboard. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getData](#getdata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the system pasteboard data. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    let text: string = pasteData.getPrimaryText();
});
```

### getPasteData<sup>(deprecated)</sup>

getPasteData(): Promise&lt;PasteData&gt;

Obtains a **PasteData** object from the pasteboard. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [getData](#getdata9-1).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise used to return the system pasteboard data.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData().then((pasteData: pasteboard.PasteData) => {
    let text: string = pasteData.getPrimaryText();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### hasPasteData<sup>(deprecated)</sup>

hasPasteData(callback:  AsyncCallback&lt;boolean&gt;): void

Checks whether the system pasteboard contains data. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [hasData](#hasdata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes| Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasPasteData((err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`Failed to check the PasteData. Cause: ${err.message}`);
        return;
    }
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
});
```

### hasPasteData<sup>(deprecated)</sup>

hasPasteData(): Promise&lt;boolean&gt;

Checks whether the system pasteboard contains data. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [hasData](#hasdata9-1).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;boolean&gt; | Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasPasteData().then((data: boolean) => {
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### setPasteData<sup>(deprecated)</sup>

setPasteData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

Writes a **PasteData** object to the pasteboard. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setData](#setdata9).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object.|
| callback | AsyncCallback&lt;void> | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData, (err, data) => {
    if (err) {
        console.error('Failed to set PasteData. Cause: ' + err.message);
        return;
    }
    console.info('Succeeded in setting PasteData.');
});
```
### setPasteData<sup>(deprecated)</sup>

setPasteData(data: PasteData): Promise&lt;void&gt;

Writes a **PasteData** object to the pasteboard. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 6 and deprecated since API version 9. You are advised to use [setData](#setdata9-1).

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | Yes| **PasteData** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData).then((data: void) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```
### isRemoteData<sup>11+</sup>

isRemoteData(): boolean

Checks whether the data in the pasteboard is from another device.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type   | Description                                 |
| ------- | ------------------------------------- |
| boolean | Returns **true** if the data in the pasteboard is from another device; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900005 | Request timed out. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.isRemoteData();
    console.info(`Succeeded in checking the RemoteData. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the RemoteData. Cause:' + err.message);
};
```

### getDataSource<sup>11+</sup>

getDataSource(): string

Obtains the data source.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type  | Description  |
| ------ | ------ |
| string | Data source.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900005 | Request timed out. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: string = systemPasteboard.getDataSource();
    console.info(`Succeeded in getting DataSource. Result: ${result}`);
} catch (err) { 
    console.error('Failed to get DataSource. Cause:' + err.message);
};
```

### hasDataType<sup>11+</sup>

hasDataType(mimeType: string): boolean

Checks whether the pasteboard contains data of the specified type.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name  | Type  | Mandatory| Description              |
| -------- | ------ | ---- | ------------------ |
| mimeType | string | Yes  | Data type.|

**Return value**

| Type   | Description                                       |
| ------- | ------------------------------------------- |
| boolean | Returns **true** if the pasteboard contains data of the specified type; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401 | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Request timed out. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.hasDataType(pasteboard.MIMETYPE_TEXT_PLAIN);
    console.info(`Succeeded in checking the DataType. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the DataType. Cause:' + err.message);
};
```

### clearDataSync<sup>11+</sup>

clearDataSync(): void

Clears the system pasteboard. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900005 | Request timed out. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.clearDataSync();
    console.info('Succeeded in clearing the pasteboard.');
} catch (err) {
    console.error('Failed to clear the pasteboard. Cause:' + err.message);
};
```

### getDataSync<sup>11+</sup>

getDataSync(): PasteData

Reads data in the system pasteboard. This API returns the result synchronously.

**Required permissions**: ohos.permission.READ_PASTEBOARD

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type                   | Description                |
| ----------------------- | -------------------- |
| [PasteData](#pastedata) | Data in the system pasteboard.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900005 | Request timed out. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: pasteboard.PasteData = systemPasteboard.getDataSync();
    console.info('Succeeded in getting PasteData.');
} catch (err) {
    console.error('Failed to get PasteData. Cause:' + err.message);
};   
```

### setDataSync<sup>11+</sup>

setDataSync(data: PasteData): void

Writes data to the system pasteboard. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type                   | Mandatory| Description            |
| ------ | ----------------------- | ---- | ---------------- |
| data   | [PasteData](#pastedata) | Yes  | Data to be written to the pasteboard.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Request timed out. |

**Example**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.setDataSync(pasteData);
    console.info('Succeeded in setting PasteData.');
} catch (err) {
    console.error('Failed to set PasteData. Cause:' + err.message);
};  
```

### hasDataSync<sup>11+</sup>

hasDataSync(): boolean

Checks whether the system pasteboard contains data. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type   | Description                                                                   |
| ------- | ----------------------------------------------------------------------- |
| boolean | Callback used to return the result. Returns **true** if the system pasteboard contains data; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 12900005 | Request timed out. |

**Example**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.hasDataSync();
    console.info(`Succeeded in checking the PasteData. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the PasteData. Cause:' + err.message);
};    
```

### getUnifiedData<sup>12+</sup>

getUnifiedData(): Promise&lt;unifiedDataChannel.UnifiedData&gt;

Obtains a **PasteData** object from the pasteboard. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_PASTEBOARD

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata)&gt; | Promise used to return the system pasteboard data.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 27787277 | Another copy or paste operation is in progress. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { unifiedDataChannel } from '@kit.ArkData';
import { uniformTypeDescriptor } from '@kit.ArkData';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getUnifiedData().then((data) => {
    let records: Array<unifiedDataChannel.UnifiedRecord> = data.getRecords();
    for (let j = 0; j < records.length; j++) {
        if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
            let text = records[j] as unifiedDataChannel.PlainText;
            console.info(`${j + 1}.${text.textContent}`);
        }
    }
}).catch((err: BusinessError) => {
    console.error('Failed to get UnifiedData. Cause: ' + err.message);
});
```

### getUnifiedDataSync<sup>12+</sup>

getUnifiedDataSync(): unifiedDataChannel.UnifiedData

Reads data in the system pasteboard. This API returns the result synchronously.

**Required permissions**: ohos.permission.READ_PASTEBOARD

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type                | Description                |
| -------------------- | -------------------- |
| [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | Data in the system pasteboard.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 12900005 | Request timed out. |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: unifiedDataChannel.UnifiedData = systemPasteboard.getUnifiedDataSync();
    console.info('Succeeded in getting UnifiedData.');
} catch (err) {
    console.error('Failed to get UnifiedData. Cause:' + err.message);
};   
```

### setUnifiedData<sup>12+</sup>

setUnifiedData(data: unifiedDataChannel.UnifiedData): Promise&lt;void&gt;

Writes a **PasteData** object to the pasteboard. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| data | [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | Yes| 	Data to be written to the pasteboard.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 27787277 | Another copy or paste operation is in progress. |
| 27787278 | Replication is prohibited. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { unifiedDataChannel } from '@kit.ArkData';

let plainTextData = new unifiedDataChannel.UnifiedData();
let plainText = new unifiedDataChannel.PlainText();
plainText.details = {
    Key: 'delayPlaintext',
    Value: 'delayPlaintext',
};
plainText.textContent = 'delayTextContent';
plainText.abstract = 'delayTextContent';
plainTextData.addRecord(plainText);

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setUnifiedData(plainTextData).then((data: void) => {
    console.info('Succeeded in setting UnifiedData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set UnifiedData. Cause: ' + err.message);
});
```

### setUnifiedDataSync<sup>12+</sup>

setUnifiedDataSync(data: unifiedDataChannel.UnifiedData): void

Writes data to the system pasteboard. This API returns the result synchronously.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type       | Mandatory| Description            |
| ------ | ----------- | ---- | ---------------- |
| data   | [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | Yes  | Data to be written to the pasteboard.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Request timed out. |

**Example**

```ts
import { unifiedDataChannel } from '@kit.ArkData';

let plainTextData = new unifiedDataChannel.UnifiedData();
let plainText = new unifiedDataChannel.PlainText();
plainText.details = {
    Key: 'delayPlaintext',
    Value: 'delayPlaintext',
};
plainText.textContent = 'delayTextContent';
plainText.abstract = 'delayTextContent';
plainTextData.addRecord(plainText);

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.setUnifiedDataSync(plainTextData);
    console.info('Succeeded in setting UnifiedData.');
} catch (err) {
    console.error('Failed to set UnifiedData. Cause:' + err.message);
};  
```

### setAppShareOptions<sup>14+</sup>

setAppShareOptions(shareOptions: ShareOption): void

Sets pasteable range of pasteboard data for applications.

**Required permissions**: ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| shareOptions | [ShareOption](js-apis-pasteboard.md#shareoption9) | Yes| Pasteable range. Only **pasteboard.ShareOption.INAPP** is allowed.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 12900006 | Settings already exist. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
  systemPasteboard.setAppShareOptions(pasteboard.ShareOption.INAPP);
  console.info('Set app share options success.');
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error(`Set app share options failed, errorCode: ${error.code}, errorMessage: ${error.message}.`);
}
```

### removeAppShareOptions<sup>14+</sup>

removeAppShareOptions(): void

Deletes the global pasteable range of the application.

**Required permissions**: ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

**System capability**: SystemCapability.MiscServices.Pasteboard

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
  systemPasteboard.removeAppShareOptions();
  console.info('Remove app share options success.');
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error(`Remove app share options failed, errorCode: ${error.code}, errorMessage: ${error.message}.`);
}
```

### Pattern<sup>13+</sup>
Describes the modes supported by the pasteboard.

**System capability**: SystemCapability.MiscServices.Pasteboard

| Name                              | Value | Description                                                                                 |
| ---------------------------------- | --- | ------------------------------------------------------------------------------------- |
| URL                              | 0   | URL.                                                             |
| NUMBER                        | 1   | Number.                                                   |
| EMAIL_ADDRESS | 2   | Email address.|

### detectPatterns<sup>13+</sup>

detectPatterns(patterns: Array&lt;Pattern&gt;): Promise&lt;Array&lt;Pattern&gt;&gt;

Detects patterns on the **local** pasteboard. This API uses a promise to return the result.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| patterns | [Array&lt;Pattern&gt;](#pattern13) | Yes| 	Pattern to be detected in the pasteboard.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;Pattern&gt;&gt; | Promise used to return the detected pattern.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |

**Example**

```ts
import { pasteboard } from '@kit.BasicServicesKit'

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
let patterns: Array<pasteboard.Pattern> = [pasteboard.Pattern.URL, pasteboard.Pattern.EMAIL_ADDRESS];

systemPasteboard.detectPatterns(patterns).then((data: Array<pasteboard.Pattern>) => {
    if (patterns.sort().join('')==data.sort().join('')) {
      console.info('All needed patterns detected, next get data');
      try {
        let result: pasteboard.PasteData = systemPasteboard.getDataSync();
        console.info('Succeeded in getting PasteData.');
      } catch (err) {
        console.error('Failed to get PasteData. Cause:' + err.message);
      };
    } else {
      console.info("Not all needed patterns detected, no need to get data.");
    }
});
```

### getMimeTypes<sup>14+</sup>

getMimeTypes(): Promise&lt;Array&lt;string&gt;&gt;

Obtains the MIME type from the pasteboard. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the read MIME type.|

**Example**

```ts
import { pasteboard, BusinessError } from '@kit.BasicServicesKit'

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getMimeTypes().then((data: Array<String>) => {
    console.info('Succeeded in getting mimeTypes. mimeTypes: ' + data.sort().join(','));
}).catch((err: BusinessError) => {
    console.error('Failed to get mimeTypes. Cause:' + err.message);
});
```

### getDataWithProgress<sup>15+</sup>

getDataWithProgress(params: GetDataParams): Promise&lt;PasteData&gt;

Obtains the pasteboard data and progress. This API uses a promise to return the result. Folders cannot be copied.

**Required permissions**: ohos.permission.READ_PASTEBOARD

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Parameters**

| Name| Type                             | Mandatory| Description                                                        |
| ------ | --------------------------------- | ---- | ------------------------------------------------------------ |
| params | [GetDataParams](#getdataparams15) | Yes  | Parameters required when an application uses the file copy capability provided by the pasteboard, including the destination path, file conflict option, and progress bar type.|

**Return value**

| Type                                  | Description                             |
| -------------------------------------- | --------------------------------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise used to return the system pasteboard data.|

**Error codes**

For details about the error codes, see [Pasteboard Error Codes](errorcode-pasteboard.md).

| Error Code ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error.                                             |
| 12900003 | Another copy or paste operation is in progress.              |
| 12900007 | Copy file failed.                                            |
| 12900008 | Failed to start progress.                                    |
| 12900009 | Progress exits abnormally.                                   |
| 12900010 | Get pasteData error.                                         |

**Example**

```ts
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';
@Entry
@Component
struct PasteboardTest {
 build() {
   RelativeContainer() {
     Column() {
       Column() {
         Button("Copy txt")
           .onClick(async ()=>{
              let text = "test";
              let pasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, text);
              let systemPasteboard = pasteboard.getSystemPasteboard();
        	  await systemPasteboard.setData(pasteData);
              let ProgressListener = (progress: pasteboard.ProgressInfo) => {
    		    console.log('progressListener success, progress:' + progress.progress);
              }
              let params: pasteboard.GetDataParams = {
                destUri: '/data/storage/el2/base/haps/entry/files/dstFile.txt',
                fileConflictOptions: pasteboard.FileConflictOptions.OVERWRITE,
                progressIndicator: pasteboard.ProgressIndicator.DEFAULT,
                progressListener: ProgressListener
              };
              systemPasteboard.getDataWithProgress(params).then((pasteData: pasteboard.PasteData) => {
                console.error('getDataWithProgress succ');
              }).catch((err: BusinessError) => {
                console.error('Failed to get PasteData. Cause: ' + err.message);
              })   
          })
        }
      }
    }
  }
}
```

### getChangeCount<sup>18+</sup>

getChangeCount(): number

Obtains the number of times that the pasteboard data changes.

Returns the result if this API is called successfully; otherwise, returns **0**.

Even though the pasteboard data expires, or the data becomes empty because of the called [clearDataSync](#cleardatasync11) API, the number of data changes remains.

When the system is restarted, or the pasteboard service is restarted due to an exception, the number of pasteboard data changes counts from 0. In addition, copying the same data repeatedly is considered to change the data for multiple times. Therefore, each time the data is copied, the number of data changes increases.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.MiscServices.Pasteboard

**Return value**

| Type| Description|
| -------- | -------- |
| number | Number of times that the pasteboard data changes.|

**Example**

```ts
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result : number = systemPasteboard.getChangeCount();
    console.info(`Succeeded in getting the ChangeCount. Result: ${result}`);
} catch (err) {
    console.error(`Failed to get the ChangeCount. Cause: ${err.message}`);
};
```
