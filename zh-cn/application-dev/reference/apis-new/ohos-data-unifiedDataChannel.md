# @ohos.data.unifiedDataChannel    
块为统一数据管理框架（Unified Data Management Framework,UDMF）的组成部分，针对多对多跨应用数据共享的不同业务场景提供了标准化的数据通路，提供了标准化的数据接入与读取接口。同时对文本、图片等数据类型提供了标准化定义，方便不同应用间进行数据交互，减少数据类型适配的工作量。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import unifiedDataChannel from '@ohos.data.unifiedDataChannel'    
```  
    
## UnifiedData    
表示UDMF统一数据对象，提供封装一组数据记录的方法。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### addRecord    
在当前统一数据对象中添加一条数据记录。  
 **调用形式：**     
- addRecord(record: UnifiedRecord): void  
  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| record | UnifiedRecord | true | 要添加到统一数据对象中的数据记录，该记录为UnifiedRecord子类对象。| |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
示例：  
```ts    
let text1 = new unifiedDataChannel.PlainText();  
text1.textContent = 'this is textContent of text1';  
let unifiedData = new unifiedDataChannel.UnifiedData(text1);  
  
let text2 = new unifiedDataChannel.PlainText();  
text2.textContent = 'this is textContent of text2';  
unifiedData.addRecord(text2);    
```    
  
    
### getRecords    
将当前统一数据对象中的所有数据记录取出。通过本接口取出的数据为UnifiedRecord类型，需通过[getType](#gettype)获取数据类型后转为子类再使用。  
 **调用形式：**     
- getRecords(): Array\<UnifiedRecord>  
  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<UnifiedRecord> | 当前统一数据对象内所添加的记录。 |  
    
 **示例代码：**   
示例：  
```ts    
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';  
  
let text = new unifiedDataChannel.PlainText();  
text.textContent = 'this is textContent of text';  
let unifiedData = new unifiedDataChannel.UnifiedData(text);  
  
let link = new unifiedDataChannel.Hyperlink();  
link.url = 'www.XXX.com';  
unifiedData.addRecord(link);  
  
let records = unifiedData.getRecords();  
for (let i = 0; i < records.length; i++) {  
  let record = records[i];  
  if (record.getType() == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {  
    let plainText = record as unifiedDataChannel.PlainText;  
    console.info(`textContent: ${plainText.textContent}`);  
  } else if (record.getType() == uniformTypeDescriptor.UniformDataType.HYPERLINK) {  
    let hyperlink = record as unifiedDataChannel.Hyperlink;  
    console.info(`linkUrl: ${hyperlink.url}`);  
  }  
}    
```    
  
    
## Summary    
描述某一统一数据对象的数据摘要，包括所含数据类型及大小，当前暂不支持。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| summary | { [key: string]: number } | false | true | 是一个字典类型对象，key表示数据类型（见[UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype)），value为统一数据对象中该类型记录大小总和（单位：Byte）。  |  
| totalSize | number | false | true | 统一数据对象内记录总大小（单位：Byte）。                                                                      |  
    
## UnifiedRecord    
对UDMF支持的数据内容的抽象定义，称为数据记录。一个统一数据对象内包含一条或多条数据记录，例如一条文本记录、一条图片记录、一条HTML记录等。  
  
UnifiedRecord是一个抽象父类，无法保存具体数据内容，应用在使用时，不能将其添加到统一数据对象中，而应该创建带有数据内容的具体子类，如Text、Image等。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### getType    
获取当前数据记录的类型。由于从统一数据对象中调用[getRecords](#getrecords)所取出的数据是UnifiedRecord对象，因此需要通过本接口查询此记录的具体类型，再将该UnifiedRecord对象转换为其子类，调用子类接口。  
 **调用形式：**     
- getType(): string  
  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 当前数据记录对应的具体数据类型，见[UniformDataType](js-apis-data-uniformTypeDescriptor.md#uniformdatatype)。 |  
    
 **示例代码：**   
示例：  
```ts    
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';  
  
let text = new unifiedDataChannel.PlainText();  
text.textContent = 'this is textContent of text';  
let unifiedData = new unifiedDataChannel.UnifiedData(text);  
  
let records = unifiedData.getRecords();  
if (records[0].getType() == uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {  
  let plainText = records[0] as unifiedDataChannel.PlainText;  
  console.info(`textContent: ${plainText.textContent}`);  
}    
```    
  
    
## Text    
文本类型数据，是[UnifiedRecord](#unifiedrecord)的子类，也是文本类型数据的基类，用于描述文本类数据，推荐开发者优先使用Text的子类描述数据，如[PlainText](#plaintext)、[Hyperlink](#hyperlink)、[HTML](#html)等具体子类。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| details | { [key: string]: string } | false | false | 是一个字典类型对象，key和value都是string类型，用于描述文本内容。例如，可生成一个details内容为<br />{<br />"title":"标题",<br />"content":"内容"<br />}<br />的数据对象，用于描述一篇文章。非必填字段，默认值为空字典对象。  |  
    
## PlainText    
纯文本类型数据，是[Text](#text)的子类，用于描述纯文本类数据。  
  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| textContent | string | false | true | 纯文本内容。                 |  
| abstract | string | false | false | 纯文本摘要，非必填字段，默认值为空字符串。  |  
    
## Hyperlink    
超链接类型数据，是[Text](#text)的子类，用于描述超链接类型数据。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| url | string | false | true | 链接url。        |  
| description | string | false | false | 链接内容描述，非必填字段，默认值为空字符串。  |  
    
## HTML    
HTML类型数据，是[Text](#text)的子类，用于描述超文本标记语言数据。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| htmlContent | string | false | true | html格式内容。              |  
| plainContent | string | false | false | 去除html标签后的纯文本内容，非必填字段，默认值为空字符串。  |  
    
## File    
File类型数据，是[UnifiedRecord](#unifiedrecord)的子类，也是文件类型数据的基类，用于描述文件类型数据，推荐开发者优先使用File的子类描述数据，如[Image](#image)、[Video](#video)、[Folder](#folder)等具体子类。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| details | { [key: string]: string } | false | false | 是一个字典类型对象，key和value都是string类型，用于描述文件相关信息。例如，可生成一个details内容为<br />{<br />"name":"文件名",<br />"type":"文件类型"<br />}<br />的数据对象，用于描述一个文件。非必填字段，默认值为空字典对象。  |  
| uri | string | false | true | 文件数据uri。                                                                                                                                              |  
    
## Image    
图片类型数据，是[File](#file)的子类，用于描述图片文件。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| imageUri | string | false | true | 图片数据uri。  |  
    
## Video    
视频类型数据，是[File](#file)的子类，用于描述视频文件。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| videoUri | string | false | true | 视频数据uri。  |  
    
## Audio    
音频类型数据，是[File](#file)的子类，用于描述音频文件。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| audioUri | string | false | true | 音频数据uri。  |  
    
## Folder    
文件夹类型数据，是[File](#file)的子类，用于描述文件夹。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| folderUri | string | false | true | 文件夹uri。  |  
    
## SystemDefinedRecord    
SystemDefinedRecord是[UnifiedRecord](#unifiedrecord)的子类，也是OpenHarmony系统特有数据类型的基类，用于描述仅在OpenHarmony系统范围内流通的特有数据类型，推荐开发者优先使用SystemDefinedRecord的子类描述数据，如[SystemDefinedForm](#systemdefinedform)、[SystemDefinedAppItem](#systemdefinedappitem)、[SystemDefinedPixelMap](#systemdefinedpixelmap)等具体子类。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| details | { [key: string]: number \| string \| Uint8Array } | false | false | 是一个字典类型对象，key是string类型，value可以写入number（数值类型）、string（字符串类型）、Uint8Array（二进制字节数组）类型数据。非必填字段，默认值为空字典对象。 |  
    
## SystemDefinedForm    
卡片类型数据，是[SystemDefinedRecord](#systemdefinedrecord)的子类。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| formId | number | false | true | 卡片id。           |  
| formName | string | false | true | 卡片名称。           |  
| bundleName | string | false | true | 卡片所属的bundle名。    |  
| abilityName | string | false | true | 卡片对应的ability名。  |  
| module | string | false | true | 卡片所属的module名。    |  
    
## SystemDefinedAppItem    
图标类型数据，是[SystemDefinedRecord](#systemdefinedrecord)的子类。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| appId | string | false | true | 图标对应的应用id。       |  
| appName | string | false | true | 图标对应的应用名。        |  
| appIconId | string | false | true | 图标的图片id。         |  
| appLabelId | string | false | true | 图标名称对应的标签id。     |  
| bundleName | string | false | true | 图标对应的应用bundle名。  |  
| abilityName | string | false | true | 图标对应的应用ability名。  |  
    
## SystemDefinedPixelMap    
与系统侧定义的[PixelMap](js-apis-image.md#pixelmap7)数据类型对应的图片数据类型，是[SystemDefinedRecord](#systemdefinedrecord)的子类，仅保存PixelMap的二进制数据。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| rawData | Uint8Array | false | true | PixelMap对象的二进制数据。  |  
    
## ApplicationDefinedRecord    
ApplicationDefinedRecord是[UnifiedRecord](#unifiedrecord)的子类，也是应用自定义数据类型的基类，用于描述仅在应用生态内部流通的自定义数据类型，应用可基于此类进行自定义数据类型的扩展。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| applicationDefinedType | string | false | true | 应用自定义类型标识符，必须以'ApplicationDefined'开头。  |  
| rawData | Uint8Array | false | true | 应用自定义数据类型的二进制数据。                       |  
    
## Intention    
UDMF已经支持的数据通路枚举类型。其主要用途是标识各种UDMF数据通路所面向的不同业务场景。    
    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DATA_HUB | DataHub | 公共数据通路。  |  
    
## Options    
UDMF提供的数据操作接口可选项，包含intention和key两个可选参数。无默认值，当对应接口不需要此参数时可不填，具体要求参照方法接口的参数说明。  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
### 属性    
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| intention | Intention | false | false | 表示数据操作相关的数据通路类型。  |  
| key | string | false | false | UDMF中数据对象的唯一标识符，可通过[insertData](#unifieddatachannelinsertdata)接口的返回值获取。<br>由udmf:/、intention、bundleName和groupId四部分组成，以'/'连接，比如：udmf://DataHub/com.ohos.test/0123456789。<br>其中udmf:/固定，DataHub为对应枚举的取值，com.ohos.test为包名，0123456789为随机生成的groupId。  |  
    
## insertData    
将数据写入UDMF的公共数据通路中，并生成数据的唯一标识符  
 **调用形式：**     
    
- insertData(options: Options, data: UnifiedData, callback: AsyncCallback\<string>): void    
起始版本： 10    
- insertData(options: Options, data: UnifiedData): Promise\<string>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | Options | true | 配置项参数，仅需要intention的值。         |  
| data | UnifiedData | true | 目标数据。     |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回写入UDMF的数据的唯一标识符key的值。 |  
| Promise<string> | Promise对象，返回写入UDMF的数据的唯一标识符key的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';  
import { BusinessError } from '@ohos.base';  
  
let plainText = new unifiedDataChannel.PlainText();  
plainText.textContent = 'hello world!';  
let unifiedData = new unifiedDataChannel.UnifiedData(plainText);  
  
let options: unifiedDataChannel.Options = {  
  intention: unifiedDataChannel.Intention.DATA_HUB  
}  
try {  
  unifiedDataChannel.insertData(options, unifiedData, (err, data) => {  
    if (err === undefined) {  
      console.info(`Succeeded in inserting data. key = ${data}`);  
    } else {  
      console.error(`Failed to insert data. code is ${err.code},message is ${err.message} `);  
    }  
  });  
  } catch (e) {  
    let error: BusinessError = e as BusinessError;  
    console.error(`Insert data throws an exception. code is ${error.code},message is ${error.message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';  
import { BusinessError } from '@ohos.base';  
  
let plainText = new unifiedDataChannel.PlainText();  
plainText.textContent = 'hello world!';  
let unifiedData = new unifiedDataChannel.UnifiedData(plainText);  
  
let options: unifiedDataChannel.Options = {  
  intention: unifiedDataChannel.Intention.DATA_HUB  
}  
try {  
  unifiedDataChannel.insertData(options, unifiedData).then((data) => {  
    console.info(`Succeeded in inserting data. key = ${data}`);  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to insert data. code is ${err.code},message is ${err.message} `);  
  });  
} catch (e) {  
  let error: BusinessError = e as BusinessError;  
  console.error(`Insert data throws an exception. code is ${error.code},message is ${error.message} `);  
}  
    
```    
  
    
## updateData    
更新已写入UDMF的公共数据通路的数据  
 **调用形式：**     
    
- updateData(options: Options, data: UnifiedData, callback: AsyncCallback\<void>): void    
起始版本： 10    
- updateData(options: Options, data: UnifiedData): Promise\<void>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | Options | true | 配置项参数，仅需要key的值。  |  
| data | UnifiedData | true | 目标数据。            |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当更新数据成功，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';  
import { BusinessError } from '@ohos.base';  
  
let plainText = new unifiedDataChannel.PlainText();  
plainText.textContent = 'hello world!';  
let unifiedData = new unifiedDataChannel.UnifiedData(plainText);  
  
let options: unifiedDataChannel.Options = {  
  key: 'udmf://DataHub/com.ohos.test/0123456789'  
};  
  
try {  
  unifiedDataChannel.updateData(options, unifiedData, (err) => {  
    if (err === undefined) {  
      console.info('Succeeded in updating data.');  
    } else {  
      console.error(`Failed to update data. code is ${err.code},message is ${err.message} `);  
    }  
  });  
} catch (e) {  
  let error: BusinessError = e as BusinessError;  
  console.error(`Update data throws an exception. code is ${error.code},message is ${error.message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';  
import { BusinessError } from '@ohos.base';  
  
let plainText = new unifiedDataChannel.PlainText();  
plainText.textContent = 'hello world!';  
let unifiedData = new unifiedDataChannel.UnifiedData(plainText);  
  
let options: unifiedDataChannel.Options = {  
  key: 'udmf://DataHub/com.ohos.test/0123456789'  
};  
  
try {  
  unifiedDataChannel.updateData(options, unifiedData).then(() => {  
    console.info('Succeeded in updating data.');  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to update data. code is ${err.code},message is ${err.message} `);  
  });  
} catch (e) {  
  let error: BusinessError = e as BusinessError;  
  console.error(`Update data throws an exception. code is ${error.code},message is ${error.message} `);  
}  
    
```    
  
    
## queryData    
查询UDMF公共数据通路的数据  
 **调用形式：**     
    
- queryData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void    
起始版本： 10    
- queryData(options: Options): Promise\<Array\<UnifiedData>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | Options | true | 配置项参数，key和intention均为可选，根据传入的参数做相应的校验以返回不同的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回查询到的所有数据。<br>如果options中填入的是key，则返回key对应的数据。<br>如果options中填入的是intention，则返回intention下所有数据。<br>如intention和key均填写了，取两者查询数据的交集，与options只填入key的获取结果一致；如没有交集报错。 |  
| Promise<Array<UnifiedData>> | Promise对象，返回查询到的所有数据。<br>如果options中填入的是key，则返回key对应的数据。<br>如果options中填入的是intention，则返回intention下所有数据。<br>如intention和key均填写了，取两者查询数据的交集，与options只填入key的获取结果一致；如没有交集报错。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';  
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';  
import { BusinessError } from '@ohos.base';  
  
let options: unifiedDataChannel.Options = {  
  intention: unifiedDataChannel.Intention.DATA_HUB  
};  
  
try {  
  unifiedDataChannel.queryData(options, (err, data) => {  
    if (err === undefined) {  
      console.info(`Succeeded in querying data. size = ${data.length}`);  
      for (let i = 0; i < data.length; i++) {  
        let records = data[i].getRecords();  
        for (let j = 0; j < records.length; j++) {  
          if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {  
            let text = records[j] as unifiedDataChannel.PlainText;  
            console.info(`${i + 1}.${text.textContent}`);  
          }  
        }  
      }  
    } else {  
      console.error(`Failed to query data. code is ${err.code},message is ${err.message} `);  
    }  
  });  
} catch (e) {  
  let error: BusinessError = e as BusinessError;  
  console.error(`Query data throws an exception. code is ${error.code},message is ${error.message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';  
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';  
import { BusinessError } from '@ohos.base';  
  
let options: unifiedDataChannel.Options = {  
  key: 'udmf://DataHub/com.ohos.test/0123456789'  
};  
  
try {  
  unifiedDataChannel.queryData(options).then((data) => {  
    console.info(`Succeeded in querying data. size = ${data.length}`);  
    for (let i = 0; i < data.length; i++) {  
      let records = data[i].getRecords();  
      for (let j = 0; j < records.length; j++) {  
        if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {  
          let text = records[j] as unifiedDataChannel.PlainText;  
          console.info(`${i + 1}.${text.textContent}`);  
        }  
      }  
    }  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to query data. code is ${err.code},message is ${err.message} `);  
  });  
} catch (e) {  
  let error: BusinessError = e as BusinessError;  
  console.error(`Query data throws an exception. code is ${error.code},message is ${error.message} `);  
}  
    
```    
  
    
## deleteData    
删除UDMF公共数据通路的数据，返回删除的数据集  
 **调用形式：**     
    
- deleteData(options: Options, callback: AsyncCallback\<Array\<UnifiedData>>): void    
起始版本： 10    
- deleteData(options: Options): Promise\<Array\<UnifiedData>>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.DistributedDataManager.UDMF.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | Options | true | 配置项参数，key和intention均为可选，根据传入的参数做相应的校验以返回不同的值。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回删除的所有数据。<br>如果options中填入的是key，则删除key对应的数据并返回该数据。<br>如果options中填入的是intention，则删除intention下所有数据并返回删除的数据。<br>如intention和key均填写了，取两者数据的交集进行删除，并返回删除的数据，与options只填入key的结果一致；如没有交集报错。 |  
| Promise<Array<UnifiedData>> | Promise对象，返回删除的所有数据。<br>如果options中填入的是key，则删除key对应的数据并返回该数据。<br>如果options中填入的是intention，则删除intention下所有数据并返回删除的数据。<br>如intention和key均填写了，取两者数据的交集进行删除，并返回删除的数据，与options只填入key的结果一致；如没有交集报错。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';  
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';  
import { BusinessError } from '@ohos.base';  
  
let options: unifiedDataChannel.Options = {  
  intention: unifiedDataChannel.Intention.DATA_HUB  
};  
  
try {  
  unifiedDataChannel.deleteData(options, (err, data) => {  
    if (err === undefined) {  
      console.info(`Succeeded in deleting data. size = ${data.length}`);  
      for (let i = 0; i < data.length; i++) {  
        let records = data[i].getRecords();  
        for (let j = 0; j < records.length; j++) {  
          if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {  
            let text = records[j] as unifiedDataChannel.PlainText;  
            console.info(`${i + 1}.${text.textContent}`);  
          }  
        }  
      }  
    } else {  
      console.error(`Failed to delete data. code is ${err.code},message is ${err.message} `);  
    }  
  });  
} catch (e) {  
  let error: BusinessError = e as BusinessError;  
  console.error(`Delete data throws an exception. code is ${error.code},message is ${error.message} `);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import unifiedDataChannel from '@ohos.data.unifiedDataChannel';  
import uniformTypeDescriptor from '@ohos.data.uniformTypeDescriptor';  
import { BusinessError } from '@ohos.base';  
  
let options: unifiedDataChannel.Options = {  
  key: 'udmf://DataHub/com.ohos.test/0123456789'  
};  
  
try {  
  unifiedDataChannel.deleteData(options).then((data) => {  
    console.info(`Succeeded in deleting data. size = ${data.length}`);  
    for (let i = 0; i < data.length; i++) {  
      let records = data[i].getRecords();  
      for (let j = 0; j < records.length; j++) {  
        if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {  
          let text = records[j] as unifiedDataChannel.PlainText;  
          console.info(`${i + 1}.${text.textContent}`);  
        }  
      }  
    }  
  }).catch((err: BusinessError) => {  
    console.error(`Failed to delete data. code is ${err.code},message is ${err.message} `);  
  });  
} catch (e) {  
  let error: BusinessError = e as BusinessError;  
  console.error(`Query data throws an exception. code is ${error.code},message is ${error.message} `);  
}  
    
```    
  
