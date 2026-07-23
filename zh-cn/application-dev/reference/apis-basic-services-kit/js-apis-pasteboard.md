# @ohos.pasteboard (剪贴板)
<!--Kit: Basic Services Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @yangxiaodong41-->
<!--Designer: @guo867-->
<!--Tester: @maxiaorong-->
<!--Adviser: @fang-jinxu-->

本模块提供管理系统剪贴板的能力，支持系统复制、粘贴功能。系统剪贴板支持对文本、HTML、URI、Want、PixelMap等内容的操作。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 概述

本模块提供系统剪贴板管理能力。

## 导入模块

```ts
import { pasteboard } from '@kit.BasicServicesKit';
```

## 常量

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称 | 类型 | 值 | 说明           |
| ---- | ---- |-----|-------------|
| MAX_RECORD_NUM<sup>7+</sup> | number | - | API version 10之前，此常量值为512，表示单个PasteData中所能包含的最大条目数为512。当剪贴板内容中添加的条目达到数量上限512后，后续的添加操作无效。<br>从API version 10开始，不再限制单个PasteData中所能包含的最大条目数。 |
| MIMETYPE_TEXT_HTML<sup>7+</sup> | string | 'text/html'  | HTML内容的MIME类型定义。 |
| MIMETYPE_TEXT_WANT<sup>7+</sup> | string | 'text/want'  | Want内容的MIME类型定义。 |
| MIMETYPE_TEXT_PLAIN<sup>7+</sup> | string | 'text/plain' | 纯文本内容的MIME类型定义。 |
| MIMETYPE_TEXT_URI<sup>7+</sup> | string | 'text/uri'   | URI内容的MIME类型定义。 |
| MIMETYPE_PIXELMAP<sup>9+</sup> | string | 'pixelMap'   | PixelMap内容的MIME类型定义。 |

## ValueType<sup>9+</sup>

type ValueType = string | image.PixelMap | Want | ArrayBuffer

用于表示允许的数据字段类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 类型 | 说明 |
| -------- | -------- |
| string | 表示string的类型。 |
| image.PixelMap | 表示[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)的类型。 |
| Want | 表示[Want](../apis-ability-kit/js-apis-app-ability-want.md)的类型。 |
| ArrayBuffer | 表示ArrayBuffer的类型。 |

## pasteboard.createData<sup>9+</sup>

createData(mimeType: string, value: ValueType): PasteData

构建一个指定类型的剪贴板内容对象，根据传入的MIME类型和数据内容创建PasteData实例。 调用此方法后，系统将验证MIME类型有效性，封装数据内容，并返回可用于后续剪贴板操作的PasteData对象。参数mimeType长度不能超过1024字节，value类型需与mimeType匹配。

**使用场景：** 当需要将单一类型的数据（如纯文本、HTML、图片等）放入剪贴板时使用此方法。

**参数选取建议：** mimeType优先使用已定义的常量类型（如MIMETYPE_TEXT_PLAIN），若需要传递自定义格式数据，可使用自定义MIME类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                                                                     |
| -------- | -------- | -------- |--------------------------------------------------------------------------------------------------------|
| mimeType | string | 是 | 剪贴板数据对应的MIME类型。详情见下文说明。 |
| value | [ValueType](#valuetype9) | 是 | 自定义数据内容。建议根据实际场景选择合适的数据类型，使用过大的数据对象会影响应用复制粘贴性能和内存占用。对于ArrayBuffer类型，建议合理设置数据大小；对于PixelMap类型，建议及时释放不再使用的对象。 |

**mimeType参数详细说明**

- **支持的MIME类型**：可以是[常量](#常量)中已定义的类型，包括HTML类型、WANT类型、纯文本类型、URI类型、PIXELMAP类型。
- **自定义类型**：开发者可自定义MIME类型，自定义类型不能与常量中已定义的类型重复。
- **长度限制**：mimeType长度不能超过1024字节，超出范围时返回错误码401。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) |  剪贴板内容对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**示例1：**

  ```ts
  // 创建ArrayBuffer数据对象
  let dataXml = new ArrayBuffer(256);
  // 构建自定义MIME类型的剪贴板内容对象
  let pasteData: pasteboard.PasteData = pasteboard.createData('app/xml', dataXml);
  ```

**示例2：**

  ```ts
  // 定义纯文本内容
  let dataText = 'hello';
  // 构建纯文本类型的剪贴板内容对象
  let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, dataText);
  ```

## pasteboard.createData<sup>14+</sup>

createData(data: Record&lt;string, ValueType&gt;): PasteData

构建一个包含多个类型数据的剪贴板内容对象，支持一次创建多个MIME类型的数据条目。调用此方法后，系统将解析Record中的多个key-value对，创建多个PasteDataRecord条目，首个MIME类型作为默认类型。非默认类型数据需通过[getData](#getdata14)接口读取。

**使用场景：** 应用需要将多种不同类型的数据(如文本、URI、HTML等)同时复制到剪贴板时，可使用此接口一次性构建包含多个MIME类型数据的剪贴板内容对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明  |
| -------- |------------------------------------------------| -------- |-----------|
| data | [Record](../../quick-start/introduction-to-arkts.md#对象字面量)&lt;string, [ValueType](#valuetype9)&gt; | 是 | Record对象，key为MIME类型，value为对应数据。详情见下文说明。 |

**data参数详细说明**

- **Record的key**：剪贴板数据对应的MIME类型。
- **支持的MIME类型**：可以是[常量](#常量)中已定义的类型，包括HTML类型、WANT类型、纯文本类型、URI类型、PIXELMAP类型。
- **自定义类型**：开发者可自定义MIME类型。
- **长度限制**：mimeType长度不能超过1024字节，超出范围时返回错误码401。
- **Record的value**：key中指定MIME类型对应的数据。
- **默认MIME类型**：Record中的首个key-value指定的MIME类型，会作为剪贴板内容对象中首个PasteDataRecord的默认MIME类型。
- **非默认类型读取**：非默认类型的数据在粘贴时只能使用[getData](#getdata14)接口读取。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) |  剪贴板内容对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**示例1：**

```ts
// 构建包含多种MIME类型的剪贴板内容对象
let pasteData: pasteboard.PasteData = pasteboard.createData({
    'text/plain': 'hello',
    'app/xml': new ArrayBuffer(256),
});
```

**示例2：**

```ts
// 创建Record对象存储多种类型数据
let record: Record<string, pasteboard.ValueType> = {};
// 添加纯文本类型数据
record[pasteboard.MIMETYPE_TEXT_PLAIN] = 'hello';
// 添加URI类型数据
record[pasteboard.MIMETYPE_TEXT_URI] = 'dataability:///com.example.myapplication1/user.txt';
// 构建剪贴板内容对象
let pasteData: pasteboard.PasteData = pasteboard.createData(record);
```

## pasteboard.createRecord<sup>9+</sup>

createRecord(mimeType: string, value: ValueType): PasteDataRecord

创建一条指定类型的数据内容条目，将数据内容封装为PasteDataRecord对象。 调用此方法后，系统将根据MIME类型封装数据内容，返回可添加到PasteData中的条目对象。参数mimeType长度不能超过1024字节，value类型需与mimeType对应（如mimeType为MIMETYPE_TEXT_PLAIN，则value类型必须是string），参数不能为空。

**配合使用：**

- 创建的条目通常需要通过[addRecord](#addrecord7)方法添加到[PasteData](#pastedata)对象中才能生效。
- 典型使用流程：先通过[createData](#pasteboardcreatedata9)创建PasteData对象，再使用createRecord创建条目，最后通过addRecord添加条目。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明                |
| -------- | -------- | -------- |-------------------|
| mimeType | string | 是 | 剪贴板数据对应的MIME类型。详情见下文说明。  |
| value | [ValueType](#valuetype9) | 是 | 指定类型对应的数据内容。建议根据实际场景选择合适的数据类型，避免使用过大的数据对象以免影响剪贴板性能和内存占用。对于ArrayBuffer类型，建议合理设置数据大小；对于PixelMap类型，建议及时释放不再使用的对象。 |

**mimeType参数详细说明**

- **支持的MIME类型**：可以是[常量](#常量)中已定义的类型，包括HTML类型、WANT类型、纯文本类型、URI类型、PIXELMAP类型。
- **自定义类型**：开发者可自定义MIME类型。
- **长度限制**：mimeType长度不能超过1024字节，超出范围时返回错误码401。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的指定类型的数据内容条目。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types;  3. Parameter verification failed. |

**示例1：**

  ```ts
  // 创建ArrayBuffer数据对象
  let dataXml = new ArrayBuffer(256);
  // 创建自定义MIME类型的数据条目
  let pasteDataRecord: pasteboard.PasteDataRecord = pasteboard.createRecord('app/xml', dataXml);
  ```

**示例2：**

  ```ts
  // 创建纯文本剪贴板内容对象
  let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
  // 创建URI类型数据条目
  let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'file://com.example.myapplication1/data/storage/el2/base/files/file.txt');
  // 替换剪贴板中的第一条记录
  pasteData.replaceRecord(0, record);
  ```

## pasteboard.getSystemPasteboard

getSystemPasteboard(): SystemPasteboard

获取系统剪贴板对象，返回剪贴板服务的单例实例。调用此方法后，返回的系统剪贴板对象可用于访问剪贴板的读写、监听等功能。每次调用返回同一实例，调用前剪贴板系统服务需要正常运行。

**使用场景：** 在进行任何剪贴板读写操作前，都需要先调用此方法获取系统剪贴板对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [SystemPasteboard](#systempasteboard) | 系统剪贴板对象。 |

**示例：**

```ts
// 获取系统剪贴板对象 
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
```

## ShareOption<sup>9+</sup>

可粘贴数据的范围类型枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称                               | 值  | 说明                                                                                  |
| ---------------------------------- | --- | ------------------------------------------------------------------------------------- |
| INAPP                              | 0   | 表示仅允许同应用内粘贴。                                                              |
| LOCALDEVICE                        | 1   | 表示允许在任何应用内粘贴。<!--RP1--><!--RP1End-->  |
| CROSSDEVICE<sup>(deprecated)</sup> | 2   | 表示允许跨设备在任何应用内粘贴。<br/>从API version 12开始废弃，无替代接口和替代方法<!--RP2--><!--RP2End-->。 |

## pasteboard.createHtmlData<sup>(deprecated)</sup>

createHtmlData(htmlText: string): PasteData

构建一个HTML剪贴板内容对象。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[pasteboard.createData](#pasteboardcreatedata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| htmlText | string | 是 | HTML内容，需符合标准HTML格式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let pasteData: pasteboard.PasteData = pasteboard.createHtmlData(html);
```

## pasteboard.createWantData<sup>(deprecated)</sup>

createWantData(want: Want): PasteData

构建一个Want剪贴板内容对象。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[pasteboard.createData](#pasteboardcreatedata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | Want内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

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

构建一个纯文本剪贴板内容对象。
> **说明：**
>
> 从 API version 6 开始支持，从 API version 9 开始废弃，建议使用[pasteboard.createData](#pasteboardcreatedata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 纯文本内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
```

## pasteboard.createUriData<sup>(deprecated)</sup>

createUriData(uri: string): PasteData

构建一个URI剪贴板内容对象。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[pasteboard.createData](#pasteboardcreatedata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | URI内容，需符合标准URI格式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
```

## pasteboard.createHtmlTextRecord<sup>(deprecated)</sup>

createHtmlTextRecord(htmlText: string): PasteDataRecord

创建一条HTML内容的条目。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[pasteboard.createRecord](#pasteboardcreaterecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| htmlText | string | 是 | HTML内容，需符合标准HTML格式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的HTML内容条目。 |

**示例：**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record: pasteboard.PasteDataRecord = pasteboard.createHtmlTextRecord(html);
```

## pasteboard.createWantRecord<sup>(deprecated)</sup>

createWantRecord(want: Want): PasteDataRecord

创建一条Want内容条目。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[pasteboard.createRecord](#pasteboardcreaterecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | Want内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的Want内容条目。 |

**示例：**

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

创建一条纯文本内容条目。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[pasteboard.createRecord](#pasteboardcreaterecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 纯文本内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的纯文本内容条目。 |

**示例：**

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createPlainTextRecord('hello');
```

## pasteboard.createUriRecord<sup>(deprecated)</sup>

createUriRecord(uri: string): PasteDataRecord

创建一条URI内容的条目。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[pasteboard.createRecord](#pasteboardcreaterecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | URI内容，需符合标准URI格式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的URI内容条目。 |

**示例：**

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
```


## PasteDataProperty<sup>7+</sup>

定义剪贴板中所有内容条目的属性，包含时间戳、数据类型、粘贴范围以及一些附加数据等，该属性必须通过[setProperty](#setproperty9)方法，才能设置到剪贴板中。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------------------------------|
| additions | Record<string, object> | 否 | 否 | 设置其他附加属性数据。不支持动态追加属性，只能通过重新赋值的方式修改附加值，具体见相关示例setProperty， 默认为空。|
| mimeTypes | Array&lt;string&gt; | 是 | 否 | 剪贴板内容条目的数据类型，非重复的类型列表。 |
| tag | string | 否 | 否 | 用户自定义标签，默认为空。 |
| timestamp | number | 是 | 否 | 剪贴板数据的写入时间戳（单位：已开机时间的ns数）。 |
| localOnly | boolean | 否 | 否 | 配置剪贴板内容是否为“仅在本地”，true表示仅在本地有效，false表示允许跨设备传输。默认值为false。其值会被shareOption属性覆盖，推荐使用[ShareOption](#shareoption9)属性。 |
| shareOption<sup>9+</sup> | [ShareOption](#shareoption9) | 否 | 否 | 指示剪贴板数据可以粘贴到的范围，默认值为CROSSDEVICE。与localOnly属性互斥，设置shareOption会影响localOnly的实际值。 |

## FileConflictOptions<sup>15+</sup>

定义文件拷贝冲突时的选项。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称      | 值   | 说明                                                         |
| --------- | ---- | ------------------------------------------------------------ |
| OVERWRITE | 0    | 目标路径存在同文件名时覆盖。                                 |
| SKIP      | 1    | 目标路径存在同文件名时跳过，若设置SKIP，应用获取到的粘贴数据不包含跳过文件。 |

## ProgressIndicator<sup>15+</sup>

定义进度条指示选项，可选择是否采用系统默认进度显示。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称    | 值   | 说明                     |
| ------- | ---- | ------------------------ |
| NONE    | 0    | 不采用系统默认进度显示。 |
| DEFAULT | 1    | 采用系统默认进度显示。   |

## ProgressInfo<sup>15+</sup>

定义进度上报的数据结构，且仅当进度指示选项[ProgressIndicator](#progressindicator15)设置为NONE时才会上报此信息。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称     | 类型   | 只读 | 可选 | 说明                                                       |
| -------- | ------ | ---- | ---- | ---------------------------------------------------------- |
| progress | number | 否   | 否   | 不使用系统提供的进度条时，系统上报拷贝粘贴任务进度百分比，单位：%。 |

## ProgressListener<sup>15+</sup>

type ProgressListener = (progress: ProgressInfo) => void

定义进度数据变化的订阅函数，当选择不使用系统默认进度显示时，可设置该项获取粘贴过程的进度。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                         |
| -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| progress | [ProgressInfo](#progressinfo15) | 是   | 定义进度上报的数据结构，且仅当进度指示选项[ProgressIndicator](#progressindicator15)设置为NONE时才会上报此信息。 |

## ProgressSignal<sup>15+</sup>

定义进度取消的函数，在粘贴过程中可选择取消任务，且仅当进度指示选项[ProgressIndicator](#progressindicator15)设置为NONE时此参数才生效。

**系统能力：** SystemCapability.MiscServices.Pasteboard

### cancel<sup>15+</sup>

cancel(): void

取消正在进行的拷贝粘贴任务。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**示例：**

```ts
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';
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
              let progressListenerInfo = (progress: pasteboard.ProgressInfo) => {
                console.info('progressListener success, progress:' + progress.progress);
                signal.cancel();
              };
              let destPath: string = '/data/storage/el2/base/files/';
              let destUri : string = fileUri.getUriFromPath(destPath);
              let params: pasteboard.GetDataParams = {
                destUri: destUri,
                fileConflictOptions: pasteboard.FileConflictOptions.OVERWRITE,
                progressIndicator: pasteboard.ProgressIndicator.DEFAULT,
                progressListener: progressListenerInfo,
              };
              systemPasteboard.getDataWithProgress(params).then((pasteData: pasteboard.PasteData) => {
                console.info('getDataWithProgress success');
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

应用在使用剪贴板提供的文件拷贝能力的情况下需要的参数，包含目标路径、文件冲突选项、进度条类型等。调用本接口前，需确保无其他拷贝或粘贴操作正在进行。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称                | 类型                                          | 只读 | 可选 | 说明                                                         |
| ------------------- | -------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| destUri             | string                                        | 否 | 是 | 拷贝文件时目标路径，需符合URI格式规范。详情见下文说明。 |
| fileConflictOptions | [FileConflictOptions](#fileconflictoptions15) | 否 | 是 | 定义文件拷贝冲突时的选项。OVERWRITE（覆盖）适合需要确保目标路径使用最新文件内容的场景；SKIP（跳过）适合需要保留目标路径原有文件、避免意外覆盖的场景。默认为OVERWRITE。 |
| progressIndicator   | [ProgressIndicator](#progressindicator15)     | 否 | 否 | 定义进度条指示选项，可选择是否采用系统默认进度显示。设置为DEFAULT时采用系统默认进度显示；设置为NONE时需应用自行处理进度，此时progressListener和progressSignal参数才有效。 |
| progressListener    | [ProgressListener](#progresslistener15)       | 否 | 是 | 定义进度数据变化的订阅函数，用于获取粘贴过程的进度。仅当progressIndicator设置为NONE时此参数才生效，可设置该项自行处理进度显示；当progressIndicator设置为DEFAULT时此参数无效。默认为空（不监听进度）。 |
| progressSignal      | [ProgressSignal](#progresssignal15)           | 否 | 是 | 定义进度取消的函数。详情见下文说明。 |

**destUri参数详细说明**

- **基本用途：** 拷贝文件时目标路径。
- **使用场景：**
- 若不支持文件处理，则不需要设置此参数。
- 若应用涉及复杂文件处理策略或需要区分文件多路径存储，建议不设置此参数，由应用自行完成文件复制处理。
- **默认值：** 默认为空。

**progressSignal参数详细说明**

- **基本用途：** 定义进度取消的函数，在粘贴过程中可选择取消任务。
- **使用条件：** 仅当进度指示选项[ProgressIndicator](#progressindicator15)设置为NONE时此参数才生效。
- **默认值：** 默认为空。

## PasteDataRecord<sup>7+</sup>

对于剪贴板中内容记录的抽象定义，称之为条目。剪贴板内容部分由一个或者多个条目构成，例如一条文本内容、一份HTML、一个URI或者一个Want。

### 属性

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| htmlText| string | 是 | 否 | HTML内容，需符合标准HTML格式。 |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 否 | Want内容。 |
| mimeType | string | 是 | 否 | 默认数据类型。 |
| plainText | string | 是 | 否 | 纯文本内容。 |
| uri | string | 是 | 否 | URI内容，需符合标准URI格式。 |
| pixelMap<sup>9+</sup> | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 是 | 否 | PixelMap内容。 |
| data<sup>9+</sup> | Record<string, ArrayBuffer> | 是 | 否 | 自定义数据内容。 |

### toPlainText<sup>9+</sup>

toPlainText(): string

将一个PasteDataRecord中的html、plain、uri内容强制转换为文本内容。若PasteDataRecord包含其他数据类型（如PixelMap、Want等），转换结果为空字符串。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 纯文本内容。 |

**示例：**

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_HTML, '<html>hello</html>');
let text: string = record.toPlainText();
console.info(`Succeeded in converting to text. Text: ${text}`);
```

### addEntry<sup>14+</sup>

addEntry(type: string, value: ValueType): void

往一个PasteDataRecord中额外添加一种样式的自定义数据。此方式添加的MIME类型都不是Record的默认类型，粘贴时只能使用[getData](#getdata14)接口读取对应数据。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型 | 必填 | 说明                |
|-------| -------- | -------- |-------------------|
| type  | string | 是 | 剪贴板数据对应的MIME类型。详情见下文说明。  |
| value | [ValueType](#valuetype9) | 是 | 自定义数据内容。          |

**mimeType参数详细说明**

- **支持的MIME类型**：可以是[常量](#常量)中已定义的类型，包括HTML类型、WANT类型、纯文本类型、URI类型、PIXELMAP类型。
- **自定义类型**：开发者可自定义MIME类型。
- **长度限制**：mimeType长度不能超过1024字节，超出范围时返回错误码401。

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**示例：**

```ts
// 构建HTML内容字符串
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
// 创建URI类型数据条目
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
// 添加纯文本类型数据
record.addEntry(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
// 添加HTML类型数据
record.addEntry(pasteboard.MIMETYPE_TEXT_HTML, html);
```

### getValidTypes<sup>14+</sup>

getValidTypes(types: Array&lt;string&gt;): Array&lt;string&gt;

根据传入的MIME类型，返回传入的MIME类型和剪贴板中数据的MIME类型的交集。

**使用场景：** 在粘贴前，检查剪贴板数据是否包含应用支持的格式。例如，若应用仅支持纯文本和HTML格式，可调用此接口检查剪贴板数据是否包含这些格式，并根据返回结果决定是否执行粘贴操作。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型 | 必填 | 说明             |
|-------| -------- | -------- |----------------|
| types | Array&lt;string&gt; | 是 | MIME类型列表，设置后用于与剪贴板中数据的MIME类型进行交集匹配，返回匹配成功的类型列表。 |

**返回值：**

| 类型 | 说明                                   |
| -------- |--------------------------------------|
| Array&lt;string&gt; | 传入的MIME类型和剪贴板中数据的MIME类型的交集。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**示例：**

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

从PasteDataRecord中获取指定MIME类型的自定义数据，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名  | 类型     |必填 | 说明       |
|------|--------|-------- |----------|
| type | string | 是 | MIME类型，取值范围：长度不超过1024字节。超出范围时返回错误码401。 |

**返回值：**

| 类型                                      | 说明                                                                                                                   |
|-----------------------------------------|----------------------------------------------------------------------------------------------------------------------|
| Promise&lt;[ValueType](#valuetype9)&gt; | Promise对象，返回PasteDataRecord中指定MIME类型的自定义数据。<br/>PasteDataRecord中包含多个MIME类型数据时，非PasteDataRecord的默认MIME类型的数据只能通过本接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**示例：**

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

将一个PasteData中的内容强制转换为文本内容，使用callback异步回调。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[toPlainText](#toplaintext9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数，当转换成功，err为undefined，data为强制转换的文本内容；否则返回错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: Incorrect parameters types. |

**示例：**

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

将一个PasteData中的内容强制转换为文本内容，使用Promise异步回调。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[toPlainText](#toplaintext9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise对象，返回强制转换的文本内容。 |

**示例：**

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

剪贴板内容对象。剪贴板内容包含一个或者多个内容条目（[PasteDataRecord](#pastedatarecord7)）以及属性描述对象（[PasteDataProperty](#pastedataproperty7)）。

在调用PasteData的接口前，需要先通过[createData()](#pasteboardcreatedata9)或[getData()](#getdata9)获取一个PasteData对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

### getPrimaryText

getPrimaryText(): string

获取第一条纯文本内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 纯文本内容。剪贴板内容对象中没有纯文本内容时，默认返回为undefined。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 获取系统剪贴板对象
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// 异步读取剪贴板数据
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    // 获取剪贴板中的纯文本内容
    let text: string = pasteData.getPrimaryText();
}).catch((err: BusinessError) => {
    // 处理获取失败的情况
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### getPrimaryHtml<sup>7+</sup>

getPrimaryHtml(): string

获取第一条的HTML内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | HTML内容。剪贴板内容对象中没有HTML内容时，默认返回为undefined。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    let htmlText: string = pasteData.getPrimaryHtml();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### getPrimaryWant<sup>7+</sup>

getPrimaryWant(): Want

获取第一条的Want对象内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Want对象内容。剪贴板内容对象中没有Want内容时，默认返回为undefined。 |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    let want: Want = pasteData.getPrimaryWant();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### getPrimaryUri<sup>7+</sup>

getPrimaryUri(): string

获取第一条的URI内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | URI内容。剪贴板内容对象中没有URI内容时，默认返回为undefined。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    let uri: string = pasteData.getPrimaryUri();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### getPrimaryPixelMap<sup>9+</sup>

getPrimaryPixelMap(): image.PixelMap

获取第一条的PixelMap内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | PixelMap内容。剪贴板内容对象中没有PixelMap内容时，默认返回为undefined。 |

**示例：**

```ts
import { image } from '@kit.ImageKit';

// 创建图像数据缓冲区
let buffer = new ArrayBuffer(128);
// 定义图像尺寸
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

向当前剪贴板内容中添加一条条目，同时也会将条目类型添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加操作无效。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| record | [PasteDataRecord](#pastedatarecord7) | 是 | 待添加的条目，设置后会将该条目添加到剪贴板内容中，同时更新mimeTypes属性列表。 |

**示例：**

```ts
// 创建URI类型剪贴板内容对象
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
// 创建纯文本类型数据条目
let textRecord: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let html: string = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let htmlRecord: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_HTML, html);
pasteData.addRecord(textRecord);
pasteData.addRecord(htmlRecord);
```

### addRecord<sup>9+</sup>

addRecord(mimeType: string, value: ValueType): void

向当前剪贴板内容中添加一条数据内容条目，同时也会将数据类型添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

**使用场景：** 当剪贴板内容需要包含多种类型的数据（如同时包含纯文本和HTML）时，使用此方法向已有的PasteData对象添加额外的数据条目。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mimeType | string | 是 | 数据的MIME类型，取值范围：长度不超过1024字节。超出范围时返回错误码401。 |
| value | [ValueType](#valuetype9) | 是 | 数据内容，设置后更新剪贴板内容的属性信息，包括时间戳、数据类型、粘贴范围等。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 12900002 | The number of records exceeds the upper limit, <br>**适用版本：** 9 - 9 |

**示例：**

  ```ts
  let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
  // 创建ArrayBuffer数据
  let dataXml = new ArrayBuffer(256);
  pasteData.addRecord('app/xml', dataXml);
  ```

### getMimeTypes<sup>7+</sup>

getMimeTypes(): Array&lt;string&gt;

获取剪贴板中[PasteDataProperty](#pastedataproperty7)的mimeTypes列表，接口调用异常时返回undefined。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;string&gt; | 剪贴板内容条目的数据类型，非重复的类型列表。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let types: string[] = pasteData.getMimeTypes();
```

### getPrimaryMimeType<sup>7+</sup>

getPrimaryMimeType(): string

获取剪贴板内容中首个条目的数据类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 首个条目的数据类型。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let type: string = pasteData.getPrimaryMimeType();
```

### getProperty<sup>7+</sup>

getProperty(): PasteDataProperty

获取剪贴板内容的属性描述对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataProperty](#pastedataproperty7) | 属性描述对象。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let property: pasteboard.PasteDataProperty = pasteData.getProperty();
```

### setProperty<sup>9+</sup>

setProperty(property: PasteDataProperty): void

设置剪贴板内容的属性描述对象[PasteDataProperty](#pastedataproperty7)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| property | [PasteDataProperty](#pastedataproperty7) | 是 | 属性描述对象，设置后更新剪贴板内容的属性信息，包括时间戳、数据类型、粘贴范围等。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
// 定义附加属性的类型
type AdditionType = Record<string, Record<string, Object>>;

// 创建HTML类型剪贴板内容对象
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_HTML, 'application/xml');
// 获取剪贴板属性对象
let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
prop.shareOption = pasteboard.ShareOption.INAPP;
// 需要注意，不支持对addition进行追加属性的操作，只能通过重新赋值的方式达到追加属性的目的。
prop.additions = { 'TestOne': { 'Test': 123 }, 'TestTwo': { 'Test': 'additions' } } as AdditionType;
prop.tag = 'TestTag';
pasteData.setProperty(prop);
```
[PasteDataProperty](#pastedataproperty7)的localOnly与shareOption属性互斥，最终结果以shareOption为准，shareOption会影响localOnly的值。
```ts
(async () => {
    let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
    let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
    prop.shareOption = pasteboard.ShareOption.INAPP;
    prop.localOnly = false;
    pasteData.setProperty(prop);
    const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();

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
})
```

### getRecord<sup>9+</sup>

getRecord(index: number): PasteDataRecord

获取剪贴板内容中指定下标的条目。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定条目的下标。有效取值范围：[0, getRecordCount()-1]，超出范围会触发错误码12900001。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 指定下标的条目。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let record: pasteboard.PasteDataRecord = pasteData.getRecord(0);
```

### getRecordCount<sup>7+</sup>

getRecordCount(): number

获取剪贴板内容中条目的个数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 条目的个数。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let count: number = pasteData.getRecordCount();
```

### getTag<sup>7+</sup>

getTag(): string

获取剪贴板内容中用户自定义的标签内容，如果没有设置用户自定义的标签内容将返回空。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回用户自定义的标签内容，如果没有设置用户自定义的标签内容，将返回空。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let tag: string = pasteData.getTag();
```

### hasType<sup>9+</sup>

hasType(mimeType: string): boolean

检查剪贴板内容中是否有指定的MIME数据类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mimeType | string | 是 | 待查询的数据类型。可以是[常量](#常量)中已定义的类型，包括： - HTML类型 - WANT类型 - 纯文本类型 - URI类型 - PIXELMAP类型 也可以是自定义的MIME类型，长度不能超过1024字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 有指定的数据类型返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let hasType: boolean = pasteData.hasType(pasteboard.MIMETYPE_TEXT_PLAIN);
```

### removeRecord<sup>9+</sup>

removeRecord(index: number): void

移除剪贴板内容中指定下标的条目。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定的下标。有效取值范围：[0, getRecordCount()-1]，超出范围会触发错误码12900001。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
pasteData.removeRecord(0);
```

### replaceRecord<sup>9+</sup>

replaceRecord(index: number, record: PasteDataRecord): void

替换剪贴板内容中指定下标的条目。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定的下标。有效取值范围：[0, getRecordCount()-1]，超出范围会触发错误码12900001。 |
| record | [PasteDataRecord](#pastedatarecord7) | 是 | 被替换后的条目数据内容，设置后会替换指定下标位置的原始条目。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'file://com.example.myapplication1/data/storage/el2/base/files/file.txt');
pasteData.replaceRecord(0, record);
```

### pasteStart<sup>12+</sup>

pasteStart(): void

读取剪贴板数据前，通知剪贴板服务保留跨设备通道。访问剪贴板数据中的跨端文件数据前，通知剪贴板服务保留跨设备链路。跨设备链路用于连接远端设备并提供传输远端设备文件到本端设备的能力，如未调用此方法则跨设备链路将在30秒后自动断开。适用于跨设备粘贴场景。

**使用场景：** 当需要确保跨设备剪贴板数据通道保持连接，以便后续读取远端设备剪贴板数据时使用。

**配对调用：**

- 必须与[pasteComplete](#pastecomplete12)方法配对使用。
- 调用顺序：先调用pasteStart()通知保留通道，数据处理完成后必须调用pasteComplete()通知完成。
- 未调用pasteComplete()会导致跨设备通道未正确关闭，影响后续跨设备剪贴板操作。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    pasteData.pasteStart();
    console.info(`using data: ${pasteData.getPrimaryText()}`);
    pasteData.pasteComplete();
});
```

### pasteComplete<sup>12+</sup>

pasteComplete(): void

通知剪贴板服务数据使用已完成，可释放跨设备通道等资源。应在pasteStart之后、完成数据处理后调用，避免资源浪费。未调用可能导致跨设备通道长时间占用，影响后续跨设备粘贴操作。

**使用流程：**

1. getData()获取剪贴板数据
2. pasteStart()保留跨设备通道
3. 使用剪贴板数据
4. pasteComplete()释放通道

**系统能力：** SystemCapability.MiscServices.Pasteboard

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    pasteData.pasteStart();
    console.info(`using data: ${pasteData.getPrimaryText()}`);
    pasteData.pasteComplete();
});
```

### addHtmlRecord<sup>(deprecated)</sup>

addHtmlRecord(htmlText: string): void

向当前剪贴板内容中添加一条HTML内容条目，并将MIMETYPE_TEXT_HTML添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| htmlText | string | 是 | HTML内容，需符合标准HTML格式。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let html: string = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
pasteData.addHtmlRecord(html);
```

### addWantRecord<sup>(deprecated)</sup>

addWantRecord(want: Want): void

向当前剪贴板内容中添加一条Want条目，并将MIMETYPE_TEXT_WANT添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | Want对象内容。 |

**示例：**

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

向当前剪贴板内容中添加一条纯文本条目，并将MIMETYPE_TEXT_PLAIN添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 纯文本内容。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
pasteData.addTextRecord('good');
```

### addUriRecord<sup>(deprecated)</sup>

addUriRecord(uri: string): void

向当前剪贴板内容中添加一条URI条目，并将MIMETYPE_TEXT_URI添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | URI内容。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
pasteData.addUriRecord('dataability:///com.example.myapplication1/user.txt');
```

### getRecordAt<sup>(deprecated)</sup>

getRecordAt(index: number): PasteDataRecord

获取剪贴板内容中指定下标的条目。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[getRecord](#getrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定条目的下标。有效取值范围：[0, getRecordCount()-1]，超出范围返回错误码401。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 指定下标的条目。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let record: pasteboard.PasteDataRecord = pasteData.getRecordAt(0);
```

### hasMimeType<sup>(deprecated)</sup>

hasMimeType(mimeType: string): boolean

检查剪贴板内容中是否有指定的数据类型。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[hasType](#hastype9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mimeType | string | 是 | 待查询的数据类型。可以是[常量](#常量)中已定义的类型，包括： - HTML类型 - WANT类型 - 纯文本类型 - URI类型 - PIXELMAP类型 也可以是自定义的MIME类型，长度不能超过1024字节。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 有指定的数据类型返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let hasType: boolean = pasteData.hasMimeType(pasteboard.MIMETYPE_TEXT_PLAIN);
```

### removeRecordAt<sup>(deprecated)</sup>

removeRecordAt(index: number): boolean

移除剪贴板内容中指定下标的条目。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[removeRecord](#removerecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定的下标。有效取值范围：[0, getRecordCount()-1]，超出范围返回错误码401。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 移除指定下标的条目成功返回true，移除失败（如指定下标不存在或超出范围）返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let isRemove: boolean = pasteData.removeRecordAt(0);
```
### replaceRecordAt<sup>(deprecated)</sup>

replaceRecordAt(index: number, record: PasteDataRecord): boolean

替换剪贴板内容中指定下标的条目。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[replaceRecord](#replacerecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定的下标。有效取值范围：[0, getRecordCount()-1]，超出范围返回错误码401。 |
| record | [PasteDataRecord](#pastedatarecord7) | 是 | 替换后的条目。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 替换指定下标的条目成功返回true，替换失败（如指定下标不存在或超出范围、参数为空）返回false。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
let isReplace: boolean = pasteData.replaceRecordAt(0, record);
```

## SystemPasteboard

系统剪贴板对象。

在调用SystemPasteboard的接口前，需要先通过[getSystemPasteboard](#pasteboardgetsystempasteboard)获取系统剪贴板。

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
```

### on('update')<sup>7+</sup>

on(type: 'update', callback: () =&gt;void): void

订阅系统剪贴板内容变化事件，当系统剪贴板中内容变化时触发用户程序的回调。调用此方法后，系统将在剪贴板服务中注册监听器，剪贴板内容被写入、清空或修改时触发回调。可注册多个监听器，需在适当时机调用off取消监听以释放资源。

**使用场景：** 当应用需要实时响应剪贴板内容变化时使用，如自动检测剪贴板中的特定格式数据、实现智能粘贴建议等场景。

**配对调用：**

- 订阅后必须在不再需要监听时调用[off('update')](#offupdate7)取消订阅。
- 未取消订阅会导致回调函数持续监听剪贴板变化，可能造成内存泄漏或多次回调触发。
- 建议在组件/页面销毁时取消订阅。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取值为'update'，表示系统剪贴板内容变化事件，其他值无效。 |
| callback | function | 是 | 剪贴板中内容变化时触发的用户程序的回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
// 获取系统剪贴板对象
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// 定义剪贴板内容变化回调函数 
let listener = () => {
    console.info('The system pasteboard has changed.');
};
// 订阅剪贴板内容变化事件
systemPasteboard.on('update', listener);
```

### off('update')<sup>7+</sup>

off(type: 'update', callback?: () =&gt;void): void

取消订阅系统剪贴板内容变化事件。

**配对调用：**

- 与on('update')方法配合使用，取消订阅的是通过on('update')订阅的事件监听
- 必须在已订阅的情况下才能调用
- 如果callback参数未填，清除本应用的所有监听回调；否则清除指定监听回调

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                      |
| -------- | -------- | -------- |---------------------------------------------------------|
| type | string | 是 | 取值为'update'，表示系统剪贴板内容变化事件。                              |
| callback | function | 否 | 剪贴板中内容变化时触发的用户程序的回调。如果此参数未填，表明清除本应用的所有监听回调，否则表示清除指定监听回调。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
// 获取系统剪贴板对象
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// 定义剪贴板内容变化回调函数 
let listener = () => {
    console.info('The system pasteboard has changed.');
};
// 订阅剪贴板内容变化事件
systemPasteboard.off('update', listener);
```

### clearData<sup>9+</sup>

clearData(callback: AsyncCallback&lt;void&gt;): void

清空系统剪贴板内容，使用callback异步回调。调用此方法后，系统将删除剪贴板中的所有数据，触发已注册的'update'监听回调。清空成功后，剪贴板中将没有任何数据，hasData方法将返回false。

**使用场景：** 适用于需要异步清空剪贴板且不阻塞主线程的场景，如UI响应优先的交互流程。与同步接口[clearDataSync](#cleardatasync11)不同，此接口不会阻塞UI线程，更适合在UI交互中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当成功清空时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
// 获取系统剪贴板对象
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// 清空系统剪贴板内容
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

清空系统剪贴板内容，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clearData().then((data: void) => {
    console.info('Succeeded in clearing the pasteboard.');
}).catch((err: BusinessError) => {
    console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);
});
```

### setData<sup>9+</sup>

setData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

将数据写入系统剪贴板，使用callback异步回调。 调用此方法后，系统会将PasteData对象写入到系统剪贴板中。写入成功后，其他应用可以读取该剪贴板数据。写入的数据会替换剪贴板中已有的内容。

**约束说明：**

- 如果有其他拷贝或粘贴操作正在进行，会返回错误27787277。
- 如果复制被禁止，会返回错误27787278。
- PasteData对象不能为空。

**使用场景：** 适用于需要异步写入剪贴板内容的场景，如UI响应优先、避免阻塞主线程。与[setDataSync](#setdatasync11)相比，setData不会阻塞UI线程。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | 是 | PasteData对象，设置后会将该数据写入系统剪贴板，供应用读取和粘贴使用。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当写入成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 27787278 | Replication is prohibited. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
// 创建纯文本剪贴板内容对象
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');
// 获取系统剪贴板对象
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// 将数据写入系统剪贴板
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

将数据写入系统剪贴板，使用Promise异步回调。

**使用场景：** 适用于需要异步写入剪贴板且不阻塞主线程的场景，如UI响应优先的交互流程。与同步接口[setDataSync](#setdatasync11)不同，此接口不会阻塞UI线程，更适合在UI交互中调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | 是 | PasteData对象。调用本接口前，需确保无其他拷贝或粘贴操作正在进行。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 27787278 | Replication is prohibited. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 创建纯文本剪贴板内容对象
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');
// 获取系统剪贴板对象
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// 将数据写入系统剪贴板
systemPasteboard.setData(pasteData).then((data: void) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```

### getData<sup>9+</sup>

getData(callback: AsyncCallback&lt;PasteData&gt;): void

读取系统剪贴板内容，使用callback异步回调。将剪贴板数据封装为PasteData对象返回。 调用此方法后，系统将从剪贴板服务读取当前内容，通过callback返回PasteData对象。读取成功后，应用可以通过PasteData对象的方法获取具体的数据内容（如文本、HTML、URI等）。

**使用场景：** 适用于需要异步读取剪贴板内容的场景，如UI响应优先、避免阻塞主线程。与getDataSync相比，getData不会阻塞UI线程，适合处理大量数据或远端数据。

**需要权限：** ohos.permission.READ_PASTEBOARD，应用访问剪贴板内容需[申请访问剪贴板权限](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md)。[使用粘贴控件](../../security/AccessToken/pastebutton.md)访问剪贴板内容的应用，可以无需申请权限。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | 是 | 回调函数。当读取成功，err为undefined，data为返回的系统剪贴板数据；否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. <br>**适用版本：** 12+ |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 获取系统剪贴板对象
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// 读取系统剪贴板内容
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    // 获取剪贴板中的纯文本内容
    let text: string = pasteData.getPrimaryText();
});
```

### getData<sup>9+</sup>

getData(): Promise&lt;PasteData&gt;

读取系统剪贴板内容，将剪贴板数据封装为PasteData对象返回，使用Promise异步回调。适用于需要异步读取剪贴板内容的场景，如UI响应优先、避免阻塞主线程。

**使用场景：** 适用于应用需要使用标准化数据结构[UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata)读取剪贴板数据的场景。

**需要权限：** ohos.permission.READ_PASTEBOARD，应用访问剪贴板内容需[申请访问剪贴板权限](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md)。[使用粘贴控件](../../security/AccessToken/pastebutton.md)访问剪贴板内容的应用，可以无需申请权限。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise对象，返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 27787277 | Another copy or paste operation is in progress. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. <br>**适用版本：** 12+ |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 获取系统剪贴板对象
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// 读取系统剪贴板内容
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    // 获取剪贴板中的纯文本内容
    let text: string = pasteData.getPrimaryText();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### hasRemoteData<sup>24+</sup>

hasRemoteData(): boolean

判断剪贴板数据是否在远端设备上。由于数据跨端传输耗时较大，如果剪贴板数据在远端设备上，不建议在UI线程执行检查剪贴板数据中是否包含自定义数据类型，或读取剪贴板数据。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回指示剪贴板数据是否在远端设备上的结果。true表示剪贴板数据在远端设备上；false表示剪贴板数据不在远端设备上。默认为false。 |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();

let result: boolean = systemPasteboard.hasRemoteData();
console.info(`Succeeded in checking the remote data. Result: ${result}`);

```

### hasData<sup>9+</sup>

hasData(callback:  AsyncCallback&lt;boolean&gt;): void

判断系统剪贴板中是否有内容，使用callback异步回调。

**使用场景：** 适用于需要异步判断剪贴板是否有内容且不阻塞主线程的场景，如UI响应优先的交互流程。与同步接口[hasDataSync](#hasdatasync11)不同，此接口不会阻塞UI线程，更适合在UI交互中调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，用于接收剪贴板是否有内容的判断结果。返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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

判断系统剪贴板中是否有内容，使用Promise异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasData().then((data: boolean) => {
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### clear<sup>(deprecated)</sup>

clear(callback: AsyncCallback&lt;void&gt;): void

清空系统剪贴板内容，使用callback异步回调。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[pasteboard.clearData](#cleardata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当成功清空时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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

清空系统剪贴板内容，使用Promise异步回调。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[pasteboard.clearData](#cleardata9-1)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clear().then((data) => {
    console.info('Succeeded in clearing the PasteData.');
}).catch((err: BusinessError) => {
    console.error(`Failed to clear the PasteData. Cause: ${err.message}`);
});
```

### getPasteData<sup>(deprecated)</sup>

getPasteData(callback: AsyncCallback&lt;PasteData&gt;): void

读取系统剪贴板内容，使用callback异步回调。
> **说明：**
>
> 从 API version 6 开始支持，从 API version 9 开始废弃，建议使用[getData](#getdata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | 是 | 回调函数。当读取成功，err为undefined，data为返回的系统剪贴板数据；否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 获取系统剪贴板对象
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// 读取系统剪贴板内容
systemPasteboard.getPasteData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    // 获取剪贴板中的纯文本内容
    let text: string = pasteData.getPrimaryText();
});
```

### getPasteData<sup>(deprecated)</sup>

getPasteData(): Promise&lt;PasteData&gt;

读取系统剪贴板内容，使用Promise异步回调。
> **说明：**
>
> 从 API version 6 开始支持，从 API version 9 开始废弃，建议使用[getData](#getdata9-1)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise对象，返回系统剪贴板数据。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 获取系统剪贴板对象
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
// 读取系统剪贴板内容
systemPasteboard.getPasteData().then((pasteData: pasteboard.PasteData) => {
    // 获取剪贴板中的纯文本内容
    let text: string = pasteData.getPrimaryText();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### hasPasteData<sup>(deprecated)</sup>

hasPasteData(callback:  AsyncCallback&lt;boolean&gt;): void

判断系统剪贴板中是否有内容，使用callback异步回调。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[hasData](#hasdata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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

判断系统剪贴板中是否有内容，使用Promise异步回调。
> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[hasData](#hasdata9-1)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasPasteData().then((data: boolean) => {
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### setPasteData<sup>(deprecated)</sup>

setPasteData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

将数据写入系统剪贴板，使用callback异步回调。
> **说明：**
>
> 从 API version 6 开始支持，从 API version 9 开始废弃，建议使用[setData](#setdata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | 是 | PasteData对象。 |
| callback | AsyncCallback&lt;void> | 是 | 回调函数。当写入成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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

将数据写入系统剪贴板，使用Promise异步回调。
> **说明：**
>
> 从 API version 6 开始支持，从 API version 9 开始废弃，建议使用[setData](#setdata9-1)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | 是 | PasteData对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData).then((data: void) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```
### isRemoteData<sup>11+</sup>

isRemoteData(): boolean

判断剪贴板中的数据是否来自其他设备。由于数据跨端传输耗时较大，如果剪贴板数据在远端设备上，不建议在UI线程执行检查剪贴板数据中是否包含自定义数据类型，或读取剪贴板数据。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型    | 说明                                  |
| ------- | ------------------------------------- |
| boolean | 判断剪贴板中的数据是否来自其他设备。剪贴板数据来自其他设备返回true；剪贴板数据来自本设备返回false。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Excessive processing time for internal data. |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.isRemoteData();
    console.info(`Succeeded in checking the RemoteData. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the RemoteData. Cause: ' + err.message);
};
```

### getDataSource<sup>11+</sup>

getDataSource(): string

获取数据来源的应用名称。

**使用场景：** 当需要识别剪贴板数据的来源应用，用于识别剪贴板数据的来源应用，适用于安全审计、数据追踪或向用户提示数据来源等场景。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型   | 说明   |
| ------ | ------ |
| string | 数据来源的应用名称。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Excessive processing time for internal data. |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: string = systemPasteboard.getDataSource();
    console.info(`Succeeded in getting DataSource. Result: ${result}`);
} catch (err) { 
    console.error('Failed to get DataSource. Cause: ' + err.message);
};
```

### hasDataType<sup>11+</sup>

hasDataType(mimeType: string): boolean

检查剪贴板内容中是否有指定类型的数据。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ------------------ |
| mimeType | string | 是   | 数据类型，设置后用于检查剪贴板内容中是否存在该类型的特定数据。其长度不能超过1024字节，超出范围时返回错误码401。 |

**返回值：**

| 类型    | 说明                                        |
| ------- | ------------------------------------------- |
| boolean | 检查剪贴板内容中是否有指定类型的数据。剪贴板内容中有指定类型的数据返回true；剪贴板内容中没有指定类型的数据返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Excessive processing time for internal data. |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.hasDataType(pasteboard.MIMETYPE_TEXT_PLAIN);
    console.info(`Succeeded in checking the DataType. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the DataType. Cause: ' + err.message);
};
```

### clearDataSync<sup>11+</sup>

clearDataSync(): void

清空系统剪贴板内容，此接口为同步接口。

**使用场景：** 当需要在关键业务流程中同步清空剪贴板数据，或需要立即确认清空结果的场景。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Excessive processing time for internal data. |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.clearDataSync();
    console.info('Succeeded in clearing the pasteboard.');
} catch (err) {
    console.error('Failed to clear the pasteboard. Cause: ' + err.message);
};
```

### getDataSync<sup>11+</sup>

getDataSync(): PasteData

读取系统剪贴板内容，此接口为同步接口。

**使用场景：** 适用于应用需要在关键业务流程中同步获取剪贴板数据，或需要立即处理剪贴板内容的场景。

**开发建议：** 避免在UI线程调用此接口，以免阻塞界面；处理大量数据或远端数据时，建议使用异步接口getData。

**需要权限：** ohos.permission.READ_PASTEBOARD，应用访问剪贴板内容需[申请访问剪贴板权限](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md)。[使用粘贴控件](../../security/AccessToken/pastebutton.md)访问剪贴板内容的应用，可以无需申请权限。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                    | 说明                 |
| ----------------------- | -------------------- |
| [PasteData](#pastedata) | 返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Excessive processing time for internal data. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. <br>**适用版本：** 12+ |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: pasteboard.PasteData = systemPasteboard.getDataSync();
    console.info('Succeeded in getting PasteData.');
} catch (err) {
    console.error('Failed to get PasteData. Cause:' + err.message);
};   
```

### setDataSync<sup>11+</sup>

setDataSync(data: PasteData): void

将数据写入系统剪贴板，此接口为同步接口。

**使用场景：** 适用于应用需要在关键业务流程中同步完成剪贴板数据写入，或需要立即确认写入结果的场景。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型                    | 必填 | 说明             |
| ------ | ----------------------- | ---- | ---------------- |
| data   | [PasteData](#pastedata) | 是   | 需要写入剪贴板中的数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Excessive processing time for internal data. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.setDataSync(pasteData);
    console.info('Succeeded in setting PasteData.');
} catch (err) {
    console.error('Failed to set PasteData. Cause:' + err.message);
};  
```

### hasDataSync<sup>11+</sup>

hasDataSync(): boolean

判断系统剪贴板中是否有内容，此接口为同步接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型    | 说明                                                                    |
| ------- | ----------------------------------------------------------------------- |
| boolean | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Excessive processing time for internal data. |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.hasDataSync();
    console.info(`Succeeded in checking the PasteData. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the PasteData. Cause: ' + err.message);
};    
```

### getUnifiedData<sup>12+</sup>

getUnifiedData(): Promise&lt;unifiedDataChannel.UnifiedData&gt;

读取系统剪贴板内容，使用Promise异步回调。

**使用场景：** 适用于需要使用标准化数据结构[UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata)进行跨应用数据交换的场景。当应用需要与其他支持UnifiedData的应用进行数据共享，或需要处理复杂的多类型数据时，使用本接口。与[getData](#getdata14)相比，getUnifiedData提供了更标准化的数据格式。

**需要权限：** ohos.permission.READ_PASTEBOARD，应用访问剪贴板内容需[申请访问剪贴板权限](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md)。[使用粘贴控件](../../security/AccessToken/pastebutton.md)访问剪贴板内容的应用，可以无需申请权限。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata)&gt; | Promise对象，返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 27787277 | Another copy or paste operation is in progress. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { unifiedDataChannel, uniformDataStruct, uniformTypeDescriptor } from '@kit.ArkData';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getUnifiedData().then((data) => {
    let records: Array<unifiedDataChannel.UnifiedRecord> = data.getRecords();
    for (let j = 0; j < records.length; j++) {
        if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
            let text = records[j].getValue() as uniformDataStruct.PlainText;
            console.info(`${j + 1}.${text.textContent}`);
        }
    }
}).catch((err: BusinessError) => {
    console.error('Failed to get UnifiedData. Cause: ' + err.message);
});
```

### getUnifiedDataSync<sup>12+</sup>

getUnifiedDataSync(): unifiedDataChannel.UnifiedData

读取系统剪贴板内容，此接口为同步接口。

**使用场景：** 适用于需要同步使用标准化数据结构UnifiedData进行跨应用数据交换的场景。当应用需要在关键业务流程中立即获取剪贴板数据，且需要与其他支持UnifiedData的应用进行数据共享时使用。由于获取剪贴板中数据的时延受数据量大小与网络环境的影响，调用此接口可能耗时较长，建议开发者在非UI线程调用。

**需要权限：** ohos.permission.READ_PASTEBOARD，应用访问剪贴板内容需[申请访问剪贴板权限](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md)。[使用粘贴控件](../../security/AccessToken/pastebutton.md)访问剪贴板内容的应用，可以无需申请权限。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                 | 说明                 |
| -------------------- | -------------------- |
| [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | 返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 12900005 | Excessive processing time for internal data. |

**示例：**

```ts
import { unifiedDataChannel } from '@kit.ArkData';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: unifiedDataChannel.UnifiedData = systemPasteboard.getUnifiedDataSync();
    console.info('Succeeded in getting UnifiedData.');
} catch (err) {
    console.error('Failed to get UnifiedData. Cause:' + err.message);
};   
```

### setUnifiedData<sup>12+</sup>

setUnifiedData(data: unifiedDataChannel.UnifiedData): Promise&lt;void&gt;

将数据写入系统剪贴板，使用Promise异步回调。

**使用场景：** 适用于需要异步写入剪贴板且不阻塞主线程的场景，如UI响应优先的交互流程。与同步接口 [setUnifiedDataSync](#setunifieddatasync12)不同，此接口不会阻塞UI线程，更适合在UI交互中调用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | 是 | 需要写入剪贴板中的数据。调用本接口前，需确保无其他拷贝或粘贴操作正在进行。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 27787277 | Another copy or paste operation is in progress. |
| 27787278 | Replication is prohibited. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { unifiedDataChannel, uniformDataStruct, uniformTypeDescriptor } from '@kit.ArkData';

// 创建纯文本数据结构对象
let plainText : uniformDataStruct.PlainText = {
    uniformDataType: uniformTypeDescriptor.UniformDataType.PLAIN_TEXT,
    textContent : 'PLAINTEXT_CONTENT',
    abstract : 'PLAINTEXT_ABSTRACT',
}
// 创建统一数据记录对象
let record = new unifiedDataChannel.UnifiedRecord(uniformTypeDescriptor.UniformDataType.PLAIN_TEXT, plainText);
// 创建统一数据对象
let data = new unifiedDataChannel.UnifiedData();
// 添加数据记录到统一数据对象
data.addRecord(record);

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setUnifiedData(data).then((data: void) => {
    console.info('Succeeded in setting UnifiedData.');
}).catch((err: BusinessError) => {
    console.error('Failed to setUnifiedData. Cause: ' + err.message);
});
```

### setUnifiedDataSync<sup>12+</sup>

setUnifiedDataSync(data: unifiedDataChannel.UnifiedData): void

将数据写入系统剪贴板，此接口为同步接口。

**使用场景：** 适用于需要同步使用标准化数据结构UnifiedData进行跨应用数据交换的场景。当应用需要在关键业务流程中立即写入剪贴板数据，且需要与其他支持[UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata)的应用进行数据共享时使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型        | 必填 | 说明             |
| ------ | ----------- | ---- | ---------------- |
| data   | [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | 是   | 需要写入剪贴板中的数据内容。支持跨应用数据交换，其他应用可通过统一数据结构读取该内容。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Excessive processing time for internal data. |

**示例：**

```ts
import { unifiedDataChannel } from '@kit.ArkData';

// 创建统一数据对象
let plainTextData = new unifiedDataChannel.UnifiedData();
// 创建纯文本数据对象
let plainText = new unifiedDataChannel.PlainText();
// 设置纯文本的详细信息
plainText.details = {
    Key: 'delayPlaintext',
    Value: 'delayPlaintext',
};
// 设置文本内容
plainText.textContent = 'delayTextContent';
// 设置摘要内容
plainText.abstract = 'delayTextContent';
// 添加数据记录到统一数据对象
plainTextData.addRecord(plainText);

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.setUnifiedDataSync(plainTextData);
    console.info('Succeeded in setting UnifiedData.');
} catch (err) {
    console.error('Failed to set UnifiedData. Cause:' + err.message);
};
```

### setAppShareOptions<sup>14+</sup>

setAppShareOptions(shareOptions: ShareOption): void

应用设置本应用剪贴板数据的可粘贴范围。

**使用场景：** 适用于应用需要全局限制本应用产生的剪贴板数据的粘贴范围，如金融类应用需要保护用户敏感信息的场景。

**配对调用：**

- 与removeAppShareOptions()方法（删除应用全局的可粘贴的范围）配合使用。
- 需要删除已设置的分享范围时，调用removeAppShareOptions()。
- 在何处设置就在何处删除，确保分享范围设置和删除的一致性。

**需要权限：** ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| shareOptions | [ShareOption](#shareoption9) | 是 | 可粘贴的范围，参数只允许pasteboard.ShareOption.INAPP。传入其他值时返回错误码401。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 12900006 | Settings already exist. |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
  systemPasteboard.setAppShareOptions(pasteboard.ShareOption.INAPP);
  console.info('Set app share options success.');
} catch (error) {
  console.error(`Set app share options failed, errorCode: ${error.code}, errorMessage: ${error.message}.`);
}
```

### removeAppShareOptions<sup>14+</sup>

removeAppShareOptions(): void

删除应用全局的可粘贴的范围。

**使用场景：** 适用于应用需要取消之前设置的粘贴范围限制，恢复剪贴板数据默认粘贴范围的场景。

**配对调用：**

- 与setAppShareOptions()方法（应用设置本应用剪贴板数据的可粘贴范围）配合使用。
- 删除的是通过setAppShareOptions()设置的分享范围。
- 必须在已设置分享范围的情况下才能调用。

**需要权限：** ohos.permission.MANAGE_PASTEBOARD_APP_SHARE_OPTION

**系统能力：** SystemCapability.MiscServices.Pasteboard

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
  systemPasteboard.removeAppShareOptions();
  console.info('Remove app share options success.');
} catch (error) {
  console.error(`Remove app share options failed, errorCode: ${error.code}, errorMessage: ${error.message}.`);
}
```

### Pattern<sup>13+</sup>
剪贴板支持检测的模式类型。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称                               | 值  | 说明                                                                                  |
| ---------------------------------- | --- | ------------------------------------------------------------------------------------- |
| URL                              | 0   | URL类型。                                                              |
| NUMBER                        | 1   | 数字类型。                                                    |
| EMAIL_ADDRESS | 2   | 邮箱地址类型。 |
| HTTP_URL<sup>24+</sup> | 3   | HTTP web链接类型。</br> **模型约束**：此接口仅可在Stage模型下使用。 |
| FLIGHT_NUMBER<sup>24+</sup> | 4   | 航班号类型。</br> **模型约束**：此接口仅可在Stage模型下使用。 |

### detectPatterns<sup>13+</sup>

detectPatterns(patterns: Array&lt;Pattern&gt;): Promise&lt;Array&lt;Pattern&gt;&gt;

检测**本地**剪贴板中存在的[Pattern](#pattern13)模式，使用Promise异步回调。本地剪贴板指当前设备上的剪贴板数据，不包括跨设备传输的远端剪贴板数据。

**使用场景：** 适用于应用在粘贴数据前需要检测剪贴板内容是否包含特定类型的数据(如URL、邮箱、电话号码等)，以便进行相应处理或提供智能提示的场景。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| patterns | Array&lt;[Pattern](#pattern13)&gt; | 是 | 需要在剪贴板中检测的模式，用于检查剪贴板数据是否符合特定格式。可选值包括：URL(URL类型)、NUMBER(数字类型)、EMAIL_ADDRESS(邮箱地址类型)等。取值范围：数组元素数量不限，元素值只能为Pattern枚举值。传入无效值时返回错误码401。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[Pattern](#pattern13)&gt;&gt; | Promise对象，返回检测到的模式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |

**示例：**

```ts
import { pasteboard } from '@kit.BasicServicesKit'

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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

读取剪贴板中存在的MIME类型，使用Promise异步回调。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回读取到的MIME类型。 |

**示例：**

```ts
import { pasteboard, BusinessError } from '@kit.BasicServicesKit'

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getMimeTypes().then((data: Array<string>) => {
    console.info('Succeeded in getting mimeTypes. mimeTypes: ' + data.sort().join(','));
}).catch((err: BusinessError) => {
    console.error('Failed to get mimeTypes. Cause: ' + err.message);
});
```

### getDataWithProgress<sup>15+</sup>

getDataWithProgress(params: GetDataParams): Promise&lt;PasteData&gt;

获取剪贴板的内容和进度，使用Promise异步回调，不支持对文件夹的拷贝。对于大文件拷贝操作，建议设置进度监听以跟踪拷贝进度，避免在UI线程长时间等待；建议合理设置目标路径以确保有足够的存储空间。

**使用场景：** 适用于应用需要粘贴大文件时，需要显示拷贝进度或需要监听拷贝过程以便在必要时取消操作的场景。

**需要权限：** ohos.permission.READ_PASTEBOARD，应用访问剪贴板内容需[申请访问剪贴板权限](../../basic-services/pasteboard/get-pastedata-permission-guidelines.md)。[使用粘贴控件](../../security/AccessToken/pastebutton.md)访问剪贴板内容的应用，可以无需申请权限。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型                              | 必填 | 说明                                                         |
| ------ | --------------------------------- | ---- | ------------------------------------------------------------ |
| params | [GetDataParams](#getdataparams15) | 是   | 应用在使用剪贴板提供的文件拷贝能力的情况下需要的参数，包含目标路径、文件冲突选项、进度条类型等。 |

**返回值：**

| 类型                                   | 说明                              |
| -------------------------------------- | --------------------------------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise对象，返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error.                                             |
| 12900003 | Another copy or paste operation is in progress.              |
| 12900007 | Invalid destUri or file system error.                        |
| 12900008 | Failed to start progress.                                    |
| 12900009 | Progress exits abnormally.                                   |
| 12900010 | System error occurred during paste execution.                |

**示例：**

```ts
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';
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
              let progressListenerInfo = (progress: pasteboard.ProgressInfo) => {
                console.info('progressListener success, progress:' + progress.progress);
              };
              let destPath: string = '/data/storage/el2/base/files/';
              let destUri : string = fileUri.getUriFromPath(destPath);
              let params: pasteboard.GetDataParams = {
                destUri: destUri,
                fileConflictOptions: pasteboard.FileConflictOptions.OVERWRITE,
                progressIndicator: pasteboard.ProgressIndicator.DEFAULT,
                progressListener: progressListenerInfo,
              };
              systemPasteboard.getDataWithProgress(params).then((pasteData: pasteboard.PasteData) => {
                console.info('getDataWithProgress success');
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

获取剪贴板内容的变化次数。

执行成功时返回剪贴板内容的变化次数，否则返回0。

当剪贴板内容过期或调用[clearDataSync](#cleardatasync11)等接口导致剪贴板内容为空时，内容变化次数不会因此改变。

系统重启或剪贴板服务异常重启时，剪贴板内容变化次数重新从0开始计数。对同一内容连续多次复制会被记录为多次更改，每次复制均会导致内容变化次数增加。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回读取到的剪贴板内容变化次数。 |

**示例：**

```ts
import { BusinessError, pasteboard } from '@kit.BasicServicesKit';

const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result : number = systemPasteboard.getChangeCount();
    console.info(`Succeeded in getting the ChangeCount. Result: ${result}`);
} catch (err) {
    console.error(`Failed to get the ChangeCount. Cause: ${err.message}`);
};
```
### UpdateCallback<sup>22+</sup>

type UpdateCallback = () => void

表示剪贴板内容变更的回调

**系统能力：** SystemCapability.MiscServices.Pasteboard

### onRemoteUpdate<sup>22+</sup>

onRemoteUpdate(callback: UpdateCallback): void

订阅跨设备剪贴板内容变化事件，当远端设备系统剪贴板中内容变化时触发用户程序的回调。

**配对调用：** 

- 订阅后必须在不再需要监听时调用[offRemoteUpdate](#offremoteupdatecallback-updatecallback22)取消订阅。
- 未取消订阅会导致回调函数持续监听远端变化，造成内存泄漏。
- 建议在组件/页面销毁时取消订阅。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | [UpdateCallback](#updatecallback22) | 是 | 剪贴板中内容变化时触发的用户程序的回调，无参数。用于监听跨设备剪贴板内容更新事件，当远端设备剪贴板内容发生变化时触发此回调。 |

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
let listener = () => {
    console.info('The remote pasteboard has changed.');
};
systemPasteboard.onRemoteUpdate(listener);
```

### offRemoteUpdate(callback?: UpdateCallback)<sup>22+</sup>

offRemoteUpdate(callback?: UpdateCallback): void

取消订阅跨设备剪贴板内容变化事件。

**配对调用：**

- 与onRemoteUpdate()方法配合使用，取消订阅的是通过onRemoteUpdate()订阅的事件监听
- 必须在已订阅的情况下才能调用
- 如果callback参数未填，清除本应用的所有远端监听回调；否则清除指定远端监听回调

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                      |
| -------- | -------- | -------- |---------------------------------------------------------|
| callback | [UpdateCallback](#updatecallback22) | 否 | 远端设备剪贴板中内容变化时触发的用户程序的回调。如果此参数未填，表明清除本应用的所有远端监听回调，否则表示清除指定远端监听回调。|

**示例：**

```ts
const systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
let listener = () => {
    console.info('The remote pasteboard has changed.');
};
systemPasteboard.offRemoteUpdate(listener);
```
