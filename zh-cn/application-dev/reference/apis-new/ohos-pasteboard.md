# @ohos.pasteboard    
本模块主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。系统剪贴板支持对文本、HTML、URI、Want、PixelMap等内容的操作。  
> **说明**   
>本模块首批接口从API version -1开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import pasteboard from '@ohos.pasteboard'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| MAX_RECORD_NUM<sup>(7+)</sup> | number |  | API version 10之前，此常量值为512，表示单个PasteData中所能包含的最大条目数为512。当剪贴板内容中添加的条目达到数量上限512后，后续的添加操作无效。<br>从API version 10开始，不再限制单个PasteData中所能包含的最大条目数。 |  
| MIMETYPE_TEXT_HTML<sup>(7+)</sup> | string |  | HTML内容的MIME类型定义。    |  
| MIMETYPE_TEXT_WANT<sup>(7+)</sup> | string |  | Want内容的MIME类型定义。 |  
| MIMETYPE_TEXT_PLAIN<sup>(7+)</sup> | string |  | 纯文本内容的MIME类型定义。   |  
| MIMETYPE_TEXT_URI<sup>(7+)</sup> | string |  | URI内容的MIME类型定义。 |  
| MIMETYPE_PIXELMAP<sup>(9+)</sup> | string |  | PixelMap内容的MIME类型定义。 |  
    
## ValueType<sup>(9+)</sup>    
用于表示允许的数据字段类型。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
    
| 取值范围 | 说明 |  
| --------| --------|  
| string | 表示string的类型。 |  
| image.PixelMap | 表示[image.PixelMap](js-apis-image.md#pixelmap7)的类型。 |  
| Want | 示[Want](js-apis-app-ability-want.md)的类型。 |  
| ArrayBuffer | 表示ArrayBuffer的类型。 |  
    
## createHtmlData<sup>(deprecated)</sup>    
构建一个HTML剪贴板内容对象。  
 **调用形式：**     
- createHtmlData(htmlText: string): PasteData  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#createData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| htmlText<sup>(deprecated)</sup> | string | true | HTML内容。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteData | 剪贴板内容对象。 |  
    
 **示例代码：**   
```ts    
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    \n" + "</body>\n" + "</html>";let pasteData: pasteboard.PasteData = pasteboard.createHtmlData(html);    
```    
  
    
## createWantData<sup>(deprecated)</sup>    
构建一个Want剪贴板内容对象。  
 **调用形式：**     
- createWantData(want: Want): PasteData  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#createData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want<sup>(deprecated)</sup> | Want | true |  Want内容。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteData | 剪贴板内容对象。 |  
    
 **示例代码：**   
```ts    
import Want from '@ohos.app.ability.Want';  
let object: Want = {    bundleName: "com.example.aafwk.test",    abilityName: "com.example.aafwk.test.TwoAbility"};let pasteData: pasteboard.PasteData = pasteboard.createWantData(object);    
```    
  
    
## createPlainTextData<sup>(deprecated)</sup>    
构建一个纯文本剪贴板内容对象。  
 **调用形式：**     
- createPlainTextData(text: string): PasteData  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#createData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text<sup>(deprecated)</sup> | string | true | 纯文本内容。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteData | 剪贴板内容对象。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');    
```    
  
    
## createUriData<sup>(deprecated)</sup>    
构建一个URI剪贴板内容对象。  
 **调用形式：**     
- createUriData(uri: string): PasteData  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#createData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true | URI内容。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteData | 剪贴板内容对象。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');    
```    
  
    
## createData<sup>(9+)</sup>    
构建一个自定义类型的剪贴板内容对象。  
 **调用形式：**     
- createData(mimeType: string, value: ValueType): PasteData  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mimeType | string | true | 剪贴板数据对应的MIME类型，可以是[常量](#常量)中已定义的类型，包括HTML类型，WANT类型，纯文本类型，URI类型，PIXELMAP类型；也可以是自定义的MIME类型，开发者可自定义此参数值。 |  
| value | ValueType | true | 自定义数据内容。       |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteData | 剪贴板内容对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
mimeType类型<span style="letter-spacing: 0px;">string</span>  
  
```ts    
let dataXml = new ArrayBuffer(256);  let pasteData: pasteboard.PasteData = pasteboard.createData('app/xml', dataXml);    
```    
  
    
 **示例代码2：**   
value类型<span style="letter-spacing: 0px;">ValueType</span>  
```ts    
let dataText = 'hello'; let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, dataText);    
```    
  
    
## createHtmlTextRecord<sup>(deprecated)</sup>    
创建一条HTML内容的条目。  
 **调用形式：**     
- createHtmlTextRecord(htmlText: string): PasteDataRecord  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#createRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| htmlText<sup>(deprecated)</sup> | string | true |  HTML内容。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteDataRecord | 一条新建的HTML内容条目。 |  
    
 **示例代码：**   
```ts    
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    \n" + "</body>\n" + "</html>";let record: pasteboard.PasteDataRecord = pasteboard.createHtmlTextRecord(html);    
```    
  
    
## createWantRecord<sup>(deprecated)</sup>    
创建一条Want内容条目。  
 **调用形式：**     
- createWantRecord(want: Want): PasteDataRecord  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#createRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want<sup>(deprecated)</sup> | Want | true | Want内容。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteDataRecord | 一条新建的Want内容条目。 |  
    
 **示例代码：**   
```ts    
import Want from '@ohos.app.ability.Want';  
let object: Want = {    bundleName: "com.example.aafwk.test",    abilityName: "com.example.aafwk.test.TwoAbility"};let record: pasteboard.PasteDataRecord = pasteboard.createWantRecord(object);    
```    
  
    
## createPlainTextRecord<sup>(deprecated)</sup>    
创建一条纯文本内容条目。  
 **调用形式：**     
- createPlainTextRecord(text: string): PasteDataRecord  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#createRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text<sup>(deprecated)</sup> | string | true | 纯文本内容。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteDataRecord | 一条新建的纯文本内容条目。 |  
    
 **示例代码：**   
```ts    
let record: pasteboard.PasteDataRecord = pasteboard.createPlainTextRecord('hello');    
```    
  
    
## createUriRecord<sup>(deprecated)</sup>    
创建一条URI内容的条目。  
 **调用形式：**     
- createUriRecord(uri: string): PasteDataRecord  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#createRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true | URI内容。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteDataRecord | 一条新建的URI内容条目。 |  
    
 **示例代码：**   
```ts    
let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');<i></i><span style="font-size: 14px; letter-spacing: 0px;"></span>    
```    
  
    
## createRecord<sup>(9+)</sup>    
创建一条自定义数据内容条目。  
 **调用形式：**     
- createRecord(mimeType: string, value: ValueType): PasteDataRecord  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mimeType | string | true | 剪贴板数据对应的MIME类型，可以是[常量](#常量)中已定义的类型，包括HTML类型，WANT类型，纯文本类型，URI类型，PIXELMAP类型；也可以是自定义的MIME类型，开发者可自定义此参数值。 |  
| value | ValueType | true |  自定义数据内容。     |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteDataRecord | 一条新建的自定义数据内容条目。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
mimeType类型string  
  
```ts    
let dataXml = new ArrayBuffer(256);let pasteDataRecord: pasteboard.PasteDataRecord = pasteboard.createRecord('app/xml', dataXml);    
```    
  
    
 **示例代码2：**   
value类型ValueType  
  
```ts    
let dataUri = 'dataability:///com.example.myapplication1/user.txt';let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, dataUri);    
```    
  
    
## getSystemPasteboard<sup>(6+)</sup>    
获取系统剪贴板对象  
 **调用形式：**     
- getSystemPasteboard(): SystemPasteboard  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| SystemPasteboard | 系统剪贴板对象。 |  
    
 **示例代码：**   
```ts    
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard()    
```    
  
    
## ShareOption<sup>(9+)</sup>    
可粘贴数据的范围类型枚举。    
    
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INAPP | 0 | 表示仅允许同应用内粘贴。 |  
| LOCALDEVICE | 1 | 表示允许在此设备中任何应用内粘贴。 |  
| CROSSDEVICE | 2 | 表示允许跨设备在任何应用内粘贴。 |  
    
## PasteDataProperty    
定义了剪贴板中所有内容条目的属性，包含时间戳、数据类型、粘贴范围以及一些附加数据等，  
该属性必须通过[setProperty](#setproperty9)方法，才能设置到剪贴板中。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| additions<sup>(7+)</sup> | [key: string]: object | false | true | 设置其他附加属性数据。不支持动态追加属性，只能通过重新赋值的方式修改附加值，具体见相关示例setProperty。  |  
| mimeTypes<sup>(7+)</sup> | Array<string> | true | true | 剪贴板内容条目的数据类型，非重复的类型列表。     |  
| tag<sup>(7+)</sup> | string | false | true | 用户自定义标签。  |  
| timestamp<sup>(7+)</sup> | number | true | true | 剪贴板数据的写入时间戳（单位：ms）。    |  
| localOnly<sup>(7+)</sup> | boolean | false | true | 配置剪贴板内容是否为“仅在本地”，默认值为false。其值会被shareOption属性覆盖，推荐使用shareOption属性。ShareOption.INAPP、ShareOption.LOCALDEVICE会将localOnly设置为true，ShareOption.CROSSDEVICE会将localOnly设置为false。<br/>- 配置为true时，表示内容仅在本地，不会在设备之间传递。<br/>- 配置为false时，表示内容将在设备间传递。 |  
| shareOption<sup>(9+)</sup> | ShareOption | false | true | 指示剪贴板数据可以粘贴到的范围，如果未设置或设置不正确，则默认值为CROSSDEVICE。  |  
    
## PasteDataRecord    
对于剪贴板中内容记录的抽象定义，称之为条目。剪贴板内容部分由一个或者多个条目构成，例如一条文本内容、一份HTML、一个URI或者一个Want。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
### 属性    
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| htmlText<sup>(7+)</sup> | string | false | true | HTML内容。 |  
| want<sup>(7+)</sup> | Want | false | true | Want内容。 |  
| mimeType<sup>(7+)</sup> | string | false | true | 数据类型。 |  
| plainText<sup>(7+)</sup> | string | false | true | 纯文本内容。 |  
| uri<sup>(7+)</sup> | string | false | true | URI内容。 |  
| pixelMap<sup>(9+)</sup> | image.PixelMap | false | true |  PixelMap内容。 |  
| data<sup>(9+)</sup> | object | false | true | 自定义数据内容。 |  
    
### convertToText<sup>(deprecated)</sup>    
将一个PasteData中的内容强制转换为文本内容，使用callback异步回调。  
 **调用形式：**     
- convertToText(callback: AsyncCallback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#convertToTextV9。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<string> | true | 回调函数，当转换成功，err为undefined，data为强制转换的文本内容；否则返回错误信息。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
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
将一个PasteData中的内容强制转换为文本内容，使用Promise异步回调。  
 **调用形式：**     
- convertToText(): Promise\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#convertToTextV9。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<string> | Promise对象，返回强制转换的文本内容。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');  
record.convertToText().then((data: string) => {  
    console.info(`Succeeded in converting to text. Data: ${data}`);  
}).catch((err: BusinessError) => {  
    console.error(`Failed to convert to text. Cause: ${err.message}`);  
});  
    
```    
  
    
### toPlainText<sup>(9+)</sup>    
将一个PasteData中的内容强制转换为文本内容。  
 **调用形式：**     
- toPlainText(): string  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 纯文本内容。 |  
    
 **示例代码：**   
```ts    
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');let data: string = record.toPlainText();console.info(`Succeeded in converting to text. Data: ${data}`);    
```    
  
    
## PasteData    
在调用PasteData的接口前，需要先通过[createData()](#pasteboardcreatedata9)或[getData()](#getdata9)获取一个PasteData对象。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
### addHtmlRecord<sup>(deprecated)</sup>    
向当前剪贴板内容中添加一条HTML内容条目，并将MIMETYPE_TEXT_HTML添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。  
 **调用形式：**     
- addHtmlRecord(htmlText: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#addRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| htmlText<sup>(deprecated)</sup> | string | true | HTML内容。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');let html: string = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    \n" + "</body>\n" + "</html>";pasteData.addHtmlRecord(html);    
```    
  
    
### addWantRecord<sup>(deprecated)</sup>    
向当前剪贴板内容中添加一条Want条目，并将MIMETYPE_TEXT_WANT添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。  
 **调用形式：**     
- addWantRecord(want: Want): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#addRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want<sup>(deprecated)</sup> | Want | true | Want对象内容。 |  
    
 **示例代码：**   
```ts    
import Want from '@ohos.app.ability.Want';  
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');let object: Want = {    bundleName: "com.example.aafwk.test",    abilityName: "com.example.aafwk.test.TwoAbility"};pasteData.addWantRecord(object);    
```    
  
    
### addRecord<sup>(7+)</sup>    
向当前剪贴板内容中添加一条条目，同时也会将条目类型添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。  
 **调用形式：**     
- addRecord(record: PasteDataRecord): void  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| record | PasteDataRecord | true | 待添加的条目。  |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');pasteData.addTextRecord('good');    
```    
  
    
### addTextRecord<sup>(deprecated)</sup>    
向当前剪贴板内容中添加一条纯文本条目，并将MIME_TEXT_PLAIN添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。  
。  
 **调用形式：**     
- addTextRecord(text: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#addRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text<sup>(deprecated)</sup> | string | true | 纯文本内容。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');pasteData.addTextRecord('good');    
```    
  
    
### addUriRecord<sup>(deprecated)</sup>    
向当前剪贴板内容中添加一条URI条目，并将MIMETYPE_TEXT_URI添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。  
。  
 **调用形式：**     
- addUriRecord(uri: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#addRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri<sup>(deprecated)</sup> | string | true |  URI内容。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');pasteData.addUriRecord('dataability:///com.example.myapplication1/user.txt');    
```    
  
    
### addRecord<sup>(9+)</sup>    
向当前剪贴板内容中添加一条自定义数据内容条目，同时也会将自定义数据类型添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。  
 **调用形式：**     
- addRecord(mimeType: string, value: ValueType): void  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mimeType | string | true | 自定义数据的MIME类型。 |  
| value | ValueType | true | 自定义数据内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12900002 | he number of record exceeds the maximum limit. |  
    
 **示例代码：**   
```null    
 let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');  let dataXml = new ArrayBuffer(256);  pasteData.addRecord('app/xml', dataXml    
```    
  
    
### addRecord<sup>(10+)</sup>    
  
  
 **调用形式：**     
- addRecord(mimeType: string, value: ValueType): void  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mimeType | string | true |  |  
| value | ValueType | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
### getMimeTypes<sup>(7+)</sup>    
获取剪贴板中[PasteDataProperty](#pastedataproperty7)的mimeTypes列表，当剪贴板内容为空时，返回列表为空。  
 **调用形式：**     
- getMimeTypes(): Array\<string>  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 剪贴板内容条目的数据类型，非重复的类型列表。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');let types: string[] = pasteData.getMimeTypes();    
```    
  
    
### getPrimaryHtml<sup>(7+)</sup>    
获取首个条目的HTML内容。  
 **调用形式：**     
- getPrimaryHtml(): string  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | HTML内容。 |  
    
 **示例代码：**   
```ts    
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    \n" + "</body>\n" + "</html>";let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_HTML, html);let htmlText: string = pasteData.getPrimaryHtml(    
```    
  
    
### getPrimaryWant<sup>(7+)</sup>    
获取首个条目的Want对象内容。  
 **调用形式：**     
- getPrimaryWant(): Want  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Want | Want对象内容。 |  
    
 **示例代码：**   
```ts    
import Want from '@ohos.app.ability.Want';  
let object: Want = {    bundleName: "com.example.aafwk.test",    abilityName: "com.example.aafwk.test.TwoAbility"};let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_WANT, object);let want: Want = pasteData.getPrimaryWant();    
```    
  
    
### getPrimaryMimeType<sup>(7+)</sup>    
获取剪贴板内容中首个条目的数据类型。  
 **调用形式：**     
- getPrimaryMimeType(): string  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 首个条目的数据类型。 |  
    
### getPrimaryText<sup>(6+)</sup>    
获取首个条目的纯文本内容  
 **调用形式：**     
- getPrimaryText(): string  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 纯文本内容。 |  
    
### getPrimaryUri<sup>(7+)</sup>    
获取首个条目的URI内容。  
 **调用形式：**     
- getPrimaryUri(): string  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | URI内容。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');let uri: string = pasteData.getPrimaryUri();    
```    
  
    
### getPrimaryPixelMap<sup>(9+)</sup>    
获取首个条目的PixelMap内容。  
 **调用形式：**     
- getPrimaryPixelMap(): image.PixelMap  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| image.PixelMap | PixelMap内容。 |  
    
 **示例代码：**   
```ts    
import image from '@ohos.multimedia.image';  
let buffer = new ArrayBuffer(128);let realSize: image.Size = { height: 3, width: 5 };let opt: image.InitializationOptions = {    size: realSize,    pixelFormat: 3,    editable: true,    alphaType: 1,    scaleMode: 1};image.createPixelMap(buffer, opt).then((pixelMap: image.PixelMap) => {    let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_PIXELMAP, pixelMap);    let PixelMap: image.PixelMap = pasteData.getPrimaryPixelMap();});    
```    
  
    
### getProperty<sup>(7+)</sup>    
获取剪贴板内容的属性描述对象。  
 **调用形式：**     
- getProperty(): PasteDataProperty  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteDataProperty | 属性描述对象。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');let property: pasteboard.PasteDataProperty = pasteData.getProperty();    
```    
  
    
### setProperty<sup>(9+)</sup>    
设置剪贴板内容的属性描述对象[PasteDataProperty](#pastedataproperty7)。  
 **调用形式：**     
- setProperty(property: PasteDataProperty): void  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| property | PasteDataProperty | true | 属性描述对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
type AdditionType = Record<string, Record<string, Object>>;  
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_HTML, 'application/xml');let prop: pasteboard.PasteDataProperty = pasteData.getProperty();prop.shareOption = pasteboard.ShareOption.INAPP;// 需要注意，不支持对addition进行追加属性的操作，只能通过重新赋值的方式达到追加属性的目的。prop.additions = { 'TestOne': { 'Test': 123 }, 'TestTwo': { 'Test': 'additions' } } as AdditionType;prop.tag = 'TestTag';pasteData.setProperty(prop);```[PasteDataProperty](#pastedataproperty7)的localOnly与shareOption属性互斥，最终结果以shareOption为准，shareOption会影响localOnly的值。```ts(async () => {    let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');    let prop: pasteboard.PasteDataProperty = pasteData.getProperty();    prop.shareOption = pasteboard.ShareOption.INAPP;    prop.localOnly = false;    pasteData.setProperty(prop);    let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
    await systemPasteboard.setData(pasteData).then(async () => {        console.info('Succeeded in setting PasteData.');        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();            prop.localOnly; // true        });    });  
    prop.shareOption = pasteboard.ShareOption.LOCALDEVICE;    prop.localOnly = false;    pasteData.setProperty(prop);  
    await systemPasteboard.setData(pasteData).then(async () => {        console.info('Succeeded in setting PasteData.');        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();            prop.localOnly; // true        });    });  
    prop.shareOption = pasteboard.ShareOption.CROSSDEVICE;    prop.localOnly = true;    pasteData.setProperty(prop);  
    await systemPasteboard.setData(pasteData).then(async () => {        console.info('Succeeded in setting PasteData.');        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();            prop.localOnly; // false        });    });})()    
```    
  
    
### getRecordAt<sup>(deprecated)</sup>    
获取剪贴板内容中指定下标的条目。  
 **调用形式：**     
- getRecordAt(index: number): PasteDataRecord  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#getRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | true | 指定条目的下标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteDataRecord | 指定下标的条目。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');let record: pasteboard.PasteDataRecord = pasteData.getRecordAt(0);    
```    
  
    
### getRecord<sup>(9+)</sup>    
获取剪贴板内容中指定下标的条目。  
 **调用形式：**     
- getRecord(index: number): PasteDataRecord  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定条目的下标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PasteDataRecord | 指定下标的条目。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12900001 | he index is out of the record. |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');let record: pasteboard.PasteDataRecord = pasteData.getRecord(0);    
```    
  
    
### getRecordCount<sup>(7+)</sup>    
获取剪贴板内容中条目的个数。  
 **调用形式：**     
- getRecordCount(): number  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 条目的个数。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');let count: number = pasteData.getRecordCount();    
```    
  
    
### getTag<sup>(7+)</sup>    
获取剪贴板内容中用户自定义的标签内容，如果没有设置用户自定义的标签内容将返回空。  
 **调用形式：**     
- getTag(): string  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回用户自定义的标签内容，如果没有设置用户自定义的标签内容，将返回空。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');let tag: string = pasteData.getTag();    
```    
  
    
### hasMimeType<sup>(deprecated)</sup>    
检查剪贴板内容中是否有指定的数据类型。  
 **调用形式：**     
- hasMimeType(mimeType: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#hasType。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mimeType<sup>(deprecated)</sup> | string | true | 待查询的数据类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 有指定的数据类型返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');let hasType: boolean = pasteData.hasMimeType(pasteboard.MIMETYPE_TEXT_PLAIN);    
```    
  
    
### hasType<sup>(9+)</sup>    
检查剪贴板内容中是否有指定的MIME数据类型  
 **调用形式：**     
- hasType(mimeType: string): boolean  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mimeType | string | true | 待查询的数据类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 有指定的数据类型返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');let hasType: boolean = pasteData.hasType(pasteboard.MIMETYPE_TEXT_PLAIN);    
```    
  
    
### removeRecordAt<sup>(deprecated)</sup>    
移除剪贴板内容中指定下标的条目。  
 **调用形式：**     
- removeRecordAt(index: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#removeRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | true | 指定的下标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功移除返回true，失败返回false。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');let isRemove: boolean = pasteData.removeRecordAt(0);    
```    
  
    
### removeRecord<sup>(9+)</sup>    
移除剪贴板内容中指定下标的条目。  
 **调用形式：**     
- removeRecord(index: number): void  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定的下标。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12900001 | The index is out of the record. |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');pasteData.removeRecord(0);    
```    
  
    
### replaceRecordAt<sup>(deprecated)</sup>    
替换剪贴板内容中指定下标的条目。  
 **调用形式：**     
- replaceRecordAt(index: number, record: PasteDataRecord): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#replaceRecord。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | true | 指定的下标。 |  
| record<sup>(deprecated)</sup> | PasteDataRecord | true | 替换后的条目。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功替换返回true，失败返回false。 |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');let isReplace: boolean = pasteData.replaceRecordAt(0, record);    
```    
  
    
### replaceRecord<sup>(9+)</sup>    
替换剪贴板内容中指定下标的条目。  
 **调用形式：**     
- replaceRecord(index: number, record: PasteDataRecord): void  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定的下标。 |  
| record | PasteDataRecord | true | 新条目的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12900001 | The index is out of the record. |  
    
 **示例代码：**   
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');pasteData.replaceRecord(0, record);    
```    
  
    
## SystemPasteboard    
系统剪贴板对象。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
### on('update')<sup>(7+)</sup>    
订阅系统剪贴板内容变化事件，当系统剪贴板中内容变化时触发用户程序的回调。  
 **调用形式：**     
    
- on(type: 'update', callback: () => void): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取值为'update'，表示系统剪贴板内容变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 剪贴板中内容变化时触发的用户程序的回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();let listener = () => {    console.info('The system pasteboard has changed.');};systemPasteboard.on('update', listener);    
```    
  
    
### off('update')<sup>(7+)</sup>    
取消订阅系统剪贴板内容变化事件。  
 **调用形式：**     
    
- off(type: 'update', callback?: () => void): void    
起始版本： 7  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 取值为'update'，表示系统剪贴板内容变化事件。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 剪贴板中内容变化时触发的用户程序的回调。如果此参数未填，表明清除本应用的所有监听回调，否则表示清除指定监听回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();let listener = () => {    console.info('The system pasteboard has changed.');};systemPasteboard.off('update', listener);    
```    
  
    
### clear<sup>(deprecated)</sup>    
清空系统剪贴板内容，使用callback异步回调。  
 **调用形式：**     
- clear(callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#clearData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当成功清空时，err为undefined；否则为错误对象。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();systemPasteboard.clear((err, data) => {    if (err) {        console.error(`Failed to clear the PasteData. Cause: ${err.message}`);        return;    }    console.info('Succeeded in clearing the PasteData.');});    
```    
  
    
### clear<sup>(deprecated)</sup>    
清空系统剪贴板内容，使用Promise异步回调。  
 **调用形式：**     
- clear(): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#clearData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import { BusinessError } from '@ohos.base';  
  
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
systemPasteboard.clear().then((data) => {  
    console.info('Succeeded in clearing the PasteData.');  
}).catch((err: BusinessError) => {  
    console.error(`Failed to clear the PasteData. Cause: ${err.message}`);  
});  
    
```    
  
    
### clearData<sup>(9+)</sup>    
清空系统剪贴板内容。  
 **调用形式：**     
    
- clearData(callback: AsyncCallback\<void>): void    
起始版本： 9    
- clearData(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当成功清空时，err为undefined；否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();systemPasteboard.clearData((err, data) => {    if (err) {        console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);        return;    }    console.info('Succeeded in clearing the pasteboard.');});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
systemPasteboard.clearData().then((data: void) => {  
    console.info('Succeeded in clearing the pasteboard.');  
}).catch((err: BusinessError) => {  
    console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);  
});  
    
```    
  
    
### getPasteData<sup>(deprecated)</sup>    
读取系统剪贴板内容，使用callback异步回调。  
 **调用形式：**     
- getPasteData(callback: AsyncCallback\<PasteData>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#getData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<PasteData> | true | 回调函数。当读取成功，err为undefined，data为返回的系统剪贴板数据；否则返回错误对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
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
读取系统剪贴板内容，使用Promise异步回调。  
 **调用形式：**     
- getPasteData(): Promise\<PasteData>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#getData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<PasteData> | Promise对象，返回系统剪贴板数据。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
systemPasteboard.getPasteData().then((pasteData: pasteboard.PasteData) => {  
    let text: string = pasteData.getPrimaryText();  
}).catch((err: BusinessError) => {  
    console.error('Failed to get PasteData. Cause: ' + err.message);  
});  
    
```    
  
    
### getData<sup>(9+)</sup>    
读取系统剪贴板内容  
 **调用形式：**     
    
- getData(callback: AsyncCallback\<PasteData>): void    
起始版本： 9    
- getData(): Promise\<PasteData>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当读取成功，err为undefined，data为返回的系统剪贴板数据；否则返回错误对象。 |  
| Promise<PasteData> | Promise对象，返回系统剪贴板数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12900003 | Another copy or paste is in progress. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {  
    if (err) {  
        console.error('Failed to get PasteData. Cause: ' + err.message);  
        return;  
    }  
    let text: string = pasteData.getPrimaryText();  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {  
    let text: string = pasteData.getPrimaryText();  
}).catch((err: BusinessError) => {  
    console.error('Failed to get PasteData. Cause: ' + err.message);  
});  
    
```    
  
    
### hasPasteData<sup>(deprecated)</sup>    
判断系统剪贴板中是否有内容，使用callback异步回调。  
 **调用形式：**     
- hasPasteData(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#hasData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
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
判断系统剪贴板中是否有内容，使用Promise异步回调。  
 **调用形式：**     
- hasPasteData(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#hasData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
systemPasteboard.hasPasteData().then((data: boolean) => {  
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);  
}).catch((err: BusinessError) => {  
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);  
});  
    
```    
  
    
### hasData<sup>(9+)</sup>    
判断系统剪贴板中是否有内容  
 **调用形式：**     
    
- hasData(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- hasData(): Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |  
| Promise<boolean> | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
systemPasteboard.hasData((err: BusinessError, data: boolean) => {  
    if (err) {  
        console.error(`Failed to check the PasteData. Cause: ${err.message}`);  
        return;  
    }  
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
systemPasteboard.hasData().then((data: boolean) => {  
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);  
}).catch((err: BusinessError) => {  
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);  
});  
    
```    
  
    
### setPasteData<sup>(deprecated)</sup>    
将数据写入系统剪贴板，使用callback异步回调。  
 **调用形式：**     
- setPasteData(data: PasteData, callback: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#setData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data<sup>(deprecated)</sup> | PasteData | true | PasteData对象。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | true | 回调函数。当写入成功，err为undefined，否则为错误对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();systemPasteboard.setPasteData(pasteData, (err, data) => {    if (err) {        console.error('Failed to set PasteData. Cause: ' + err.message);        return;    }    console.info('Succeeded in setting PasteData.');});    
```    
  
    
### setPasteData<sup>(deprecated)</sup>    
将数据写入系统剪贴板，使用Promise异步回调。  
 **调用形式：**     
- setPasteData(data: PasteData): Promise\<void>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.pasteboard.pasteboard#setData。  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data<sup>(deprecated)</sup> | PasteData | true | PasteData对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<void> | 无返回结果的Promise对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');  
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
systemPasteboard.setPasteData(pasteData).then((data: void) => {  
    console.info('Succeeded in setting PasteData.');  
}).catch((err: BusinessError) => {  
    console.error('Failed to set PasteData. Cause: ' + err.message);  
});  
    
```    
  
    
### setData<sup>(9+)</sup>    
将数据写入系统剪贴板  
 **调用形式：**     
    
- setData(data: PasteData, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setData(data: PasteData): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.MiscServices.Pasteboard    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | PasteData | true | asteData对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当写入成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 12900003 | Another copy or paste is in progress. |  
| 12900004 | Replication is prohibited. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();systemPasteboard.setData(pasteData, (err, data) => {    if (err) {        console.error('Failed to set PasteData. Cause: ' + err.message);        return;    }    console.info('Succeeded in setting PasteData.');});    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import { BusinessError } from '@ohos.base';  
  
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');  
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();  
systemPasteboard.setData(pasteData).then((data: void) => {  
    console.info('Succeeded in setting PasteData.');  
}).catch((err: BusinessError) => {  
    console.error('Failed to set PasteData. Cause: ' + err.message);  
});  
    
```    
  
