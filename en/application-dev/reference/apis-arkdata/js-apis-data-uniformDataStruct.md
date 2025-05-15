# @ohos.data.uniformDataStruct (Uniform Data Structs)

As a part of the Unified Data Management Framework (UDMF), the **uniformDataStruct** module provides data structs corresponding to certain [UniformDataTypes](js-apis-data-uniformTypeDescriptor.md#uniformdatatype) for service scenarios of many-to-many data sharing across applications. It helps simplify data interaction and reduce the data type adaptation workload.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { uniformDataStruct } from '@kit.ArkData';
```

## PlainText

Represents data of the plain text type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name       | Type  | Read-Only| Optional| Description                   |
| ----------- | ------ | ---- | ---- |-----------------------|
| uniformDataType | 'general.plain-text'| Yes  | No  | Uniform data type, which has a fixed value of **general.plain-text**. For details, see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype).               |
| textContent | string | No  | No  | Plaintext content.               |
| abstract    | string | No  | Yes  | Text abstract. It is an empty string by default.|
| details | Record<string, string> | No  | Yes| Object of the dictionary type used to describe the attributes of the text content. Both the key and value of the object are of the string type. For example, the following is a **details** object used to describe the properties of a file:<br>{<br>"title":"Title of the file",<br>"content":"Content of the file"<br>}<br> By default, it is an empty dictionary object.|

**Example**

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
let plainTextDetails : Record<string, string> = {
  'attr1': 'value1',
  'attr2': 'value2'
}
let plainText : uniformDataStruct.PlainText = {
  uniformDataType: 'general.plain-text',
  textContent : 'This is plainText textContent example',
  abstract : 'this is abstract',
  details : plainTextDetails
}
console.info('plainText.uniformDataType: ' + plainText.uniformDataType);
if(plainText.details != undefined){
  let plainTextDetailsObj : Record<string, string> = plainText.details;
  for(let kv of Object.entries(plainTextDetailsObj)) {
    console.info('plainText.details.attr: ' + kv[0] + ', value:' + kv[1]);
  }
}
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainText);
```

## Hyperlink

Represents data of the hyperlink type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name       | Type  | Read-Only| Optional| Description          |
| ----------- | ------ | ---- | ---- |-------------- |
| uniformDataType | 'general.hyperlink'| Yes  | No  | Uniform data type, which has a fixed value of **general.hyperlink**. For details, see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype). |
| url         | string | No  | No  | URL.      |
| description | string | No  | Yes  | Description of the linked content. This parameter is optional. By default, it is an empty string.|
| details | Record<string, string> | No  | Yes | Object of the dictionary type used to describe the attributes of the hyperlink. Both the key and value of the object are of the string type. For example, the following is a **details** object used to describe the properties of a file:<br>{<br>"title":"Title of the hyperlink",<br>"content":"Content"<br>}<br> By default, it is an empty dictionary object. |

**Example**

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
let hyperlinkDetails : Record<string, string> = {
  'attr1': 'value1',
  'attr2': 'value2'
}
let hyperlink : uniformDataStruct.Hyperlink = {
  uniformDataType:'general.hyperlink',
  url : 'www.XXX.com',
  description : 'This is the description of this hyperlink',
  details : hyperlinkDetails
}
console.info('hyperlink.uniformDataType: ' + hyperlink.uniformDataType);
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.HYPERLINK, hyperlink);
```

## HTML

Represents data of the HTML type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name     | Type  | Read-Only| Optional | Description |
| ------------ | ------ | ---- | ---- |-----------------------|
| uniformDataType | 'general.html'| Yes  | No  | Uniform data type, which has a fixed value of **general.html**. For details, see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype). |
| htmlContent  | string | No  | No  | Content in HTML format. |
| plainContent | string  | No  | Yes | Plaintext without HTML tags. This parameter is optional. By default, it is an empty string. |
| details | Record<string, string> | No  | Yes  | Object of the dictionary type used to describe the attributes of the HTML content. Both the key and value of the object are of the string type. For example, the following is a **details** object used to describe the properties of a file:<br>{<br>"title":"Title of the HTML content",<br>"content":"Content"<br>}<br> By default, it is an empty dictionary object. |

**Example**

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
let htmlObjDetails : Record<string, string> = {
  'attr1': 'value1',
  'attr2': 'value2'
}
let htmlObj : uniformDataStruct.HTML = {
  uniformDataType :'general.html',
  htmlContent: '<div><p>Title</p></div>',
  plainContent : 'this is plainContent',
  details : htmlObjDetails
}
console.info('htmlObj.uniformDataType: ' + htmlObj.uniformDataType);
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.HTML, htmlObj);
```

## OpenHarmonyAppItem

Represents data of the home screen icon type defined by the system.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name       | Type  | Read-Only| Optional| Description             |
| ----------- | ------ | ---- | ---- |-----------------|
| uniformDataType | 'openharmony.app-item'| Yes  | No  | Uniform data type, which has a fixed value of **openharmony.app-item**. For details, see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype). |
| appId       | string | No  | No  | ID of the application, for which the icon is used.     |
| appName     | string | No  | No  | Name of the application, for which the icon is used.      |
| appIconId   | string | No  | No  | Image ID of the icon.       |
| appLabelId  | string | No  | No  | Label ID corresponding to the icon name.   |
| bundleName  | string | No  | No  | Bundle name corresponding to the icon.|
| abilityName | string | No  | No  | Application ability name corresponding to the icon.|
| details | Record<string, number \| string \| Uint8Array> | No  | Yes  | Object of the dictionary type used to describe the icon. The key is of the string type, and the value can be a number, a string, or a Uint8Array. By default, it is an empty dictionary object. |


**Example**

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
let appItemDetails : Record<string, number | string | Uint8Array> = {
  'appItemKey1': 123,
  'appItemKey2': 'appItemValue',
  'appItemKey3': u8Array
}
let appItem : uniformDataStruct.OpenHarmonyAppItem = {
  uniformDataType:'openharmony.app-item',
  appId : 'MyAppId',
  appName : 'MyAppName',
  appIconId : 'MyAppIconId',
  appLabelId : 'MyAppLabelId',
  bundleName : 'MyBundleName',
  abilityName : 'MyAbilityName',
  details : appItemDetails
}
console.info('appItem.uniformDataType: ' + appItem.uniformDataType);
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.OPENHARMONY_APP_ITEM, appItem);
```

## ContentForm<sup>14+</sup>

Represents data of the content widget type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name        | Type  | Read-Only| Optional| Description                                                                                                                            |
|------------| ------ | ---- |----|--------------------------------------------------------------------------------------------------------------------------------|
| uniformDataType | 'general.content-form'| Yes  | No | Uniform data type, which has a fixed value of **general.content-form**. |
| title      | string | No  | No | Title of the content widget.|
| thumbData  | Uint8Array | No  | Yes | Image data in the content widget.|
| description| string | No  | Yes | Description of the content widget.|
| appIcon    | Uint8Array | No  | Yes | Application icon data in the content widget.|
| appName    | string | No  | Yes | Application name in the content widget.|
| linkUri    | string | No  | Yes | Hyperlink in the content widget.|

**Example**

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
let thumbDataU8Array = new Uint8Array([1, 2, 3, 4, 5]);
let appIconU8Array = new Uint8Array([6, 7, 8, 9, 10]);
let contentForm : uniformDataStruct.ContentForm = {
  uniformDataType : 'general.content-form',
  title : 'MyTitle',
  thumbData : thumbDataU8Array,
  description : 'MyDescription',
  appName : 'MyAppName',
  linkUri : 'MyLinkUri',
  appIcon : appIconU8Array
}
console.info('contentForm.uniformDataType: ' + contentForm.uniformDataType);
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.CONTENT_FORM, contentForm);
```

## Form<sup>15+</sup>

Represents data of the widget type defined by the system.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name        | Type  | Read-Only| Optional| Description                                                                                                                            |
|------------| ------ | ---- |----|--------------------------------------------------------------------------------------------------------------------------------|
| uniformDataType | 'openharmony.form'| Yes  | No | Uniform data type, which has a fixed value of **openharmony.form**. For details, see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype). |
| formId     | number | No  | No | Widget ID.|
| formName   | string | No  | No | Widget name.|
| bundleName | string | No  | No | Bundle to which the widget belongs.|
| abilityName| string | No  | No | Ability name corresponding to the widget.|
| module     | string | No  | No | Module to which the widget belongs.|
| details | Record<string, number \| string \| Uint8Array> | No  | Yes  | Object of the dictionary type used to describe the icon. The key is of the string type, and the value can be a number, a string, or a Uint8Array. By default, it is an empty dictionary object.|


**Example**

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
let formDetails : Record<string, number | string | Uint8Array> = {
  'formKey1': 123,
  'formKey2': 'formValue',
  'formKey3': u8Array
}
let form : uniformDataStruct.Form = {
  uniformDataType : 'openharmony.form',
  formId : 1,
  formName : 'formName',
  bundleName : 'com.xx.app',
  abilityName : 'abilityName',
  module : 'module',
  details : formDetails
}
console.info('form.uniformDataType: ' + form.uniformDataType);
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.OPENHARMONY_FORM, form);
```

## FileUri<sup>15+</sup>

Represents data of the file URI type.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name        | Type  | Read-Only| Optional| Description                                                                                                                            |
|------------| ------ | ---- |----|--------------------------------------------------------------------------------------------------------------------------------|
| uniformDataType | 'general.file-uri'| Yes  | No | Uniform data type, which has a fixed value of **general.file-uri**. For details, see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype). |
| oriUri     | string | No  | No | File URI.|
| fileType   | string | No  | No | File type.|
| details | Record<string, number \| string \| Uint8Array> | No  | Yes  | Object of the dictionary type used to describe the icon. The key is of the string type, and the value can be a number, a string, or a Uint8Array. By default, it is an empty dictionary object.|

**Example**

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
let fileUriDetails : Record<string, number | string | Uint8Array> = {
  'fileUriKey1': 123,
  'fileUriKey2': 'fileUriValue',
  'fileUriKey3': u8Array
}
let fileUri : uniformDataStruct.FileUri = {
  uniformDataType : 'general.file-uri',
  oriUri : 'www.xx.com',
  fileType : 'general.image',
  details : fileUriDetails
}
console.info('fileUri.uniformDataType: ' + fileUri.uniformDataType);
// You are advised to set type to uniformTypeDescriptor.UniformDataType.FILE_URI to use the uniform data struct of FileUri type to construct records.
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.FILE_URI, fileUri);
```

## PixelMap<sup>15+</sup>

Represents data of the pixel map type defined by the system.

**System capability**: SystemCapability.DistributedDataManager.UDMF.Core

| Name        | Type  | Read-Only| Optional| Description                                                                                                                            |
|------------| ------ | ---- |----|--------------------------------------------------------------------------------------------------------------------------------|
| uniformDataType | 'openharmony.pixel-map'| Yes  | No | Uniform data type, which has a fixed value of **openharmony.pixel-map**. For details, see [UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype). |
| pixelMap     | image.PixelMap | No  | No | Binary data of the pixel map.|
| details | Record<string, number \| string \| Uint8Array> | No  | Yes  | Object of the dictionary type used to describe the icon. The key is of the string type, and the value can be a number, a string, or a Uint8Array. By default, it is an empty dictionary object.|


**Example**

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

let u8Array = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
let arrayBuffer = new ArrayBuffer(4*200*200);
let opt : image.InitializationOptions = { editable: true, pixelFormat: 3, size: { height: 200, width: 200 }, alphaType: 3 };
let pixelMapDetails : Record<string, number | string | Uint8Array> = {
  'pixelMapKey1': 123,
  'pixelMapKey2': 'pixelMapValue',
  'pixelMapKey3': u8Array
}
let pixelMap : uniformDataStruct.PixelMap = {
  uniformDataType : 'openharmony.pixel-map',
  pixelMap : image.createPixelMapSync(arrayBuffer, opt),
  details : pixelMapDetails
}
console.info('pixelMap.uniformDataType: ' + pixelMap.uniformDataType);
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.OPENHARMONY_PIXEL_MAP, pixelMap);
```
