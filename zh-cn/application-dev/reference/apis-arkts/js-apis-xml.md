# @ohos.xml (XML解析与生成)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong; @lijin1039-->
<!--Designer: @Malzahar; @lijin1039-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

本模块提供XML生成和解析的接口，支持多种方式的XML文本生成与解析，可帮助开发者高效处理结构化XML数据。

本模块提供了两种生成XML文件的方式:
* [XmlSerializer](#xmlserializer)：适用于已知XML文本大小的情况。需要开发者自行创建ArrayBuffer作为缓存区域，需确保缓存区域足以容纳生成的文本内容。
* [XmlDynamicSerializer<sup>20+</sup>](#xmldynamicserializer20)：适用于未知XML文本大小的情况。无需自行创建ArrayBuffer，程序动态扩容，但序列化结果字符串长度上限为100000。

本模块提供了两种解析XML文件的方式:
* [XmlPullParser](#xmlpullparser)：适用于对XML文本进行随机访问和灵活解析的场景。
* [XmlSAXParser<sup>24+</sup>](#xmlsaxparser24)：适用于流式解析XML文本的场景，当XML文本较大，其他解析方式会消耗较多内存，建议采用流式解析。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { xml } from '@kit.ArkTS';
```

## XmlSerializer

XmlSerializer接口用于生成XML文件。该接口基于预分配的ArrayBuffer缓存区域，通过顺序调用元素写入方法（如startElement、setAttributes、setText和endElement）将XML文本写入缓存。

### constructor

constructor(buffer: ArrayBuffer | DataView, encoding?: string)

构造并返回一个XmlSerializer对象，用于将XML信息写入指定的ArrayBuffer或DataView内存中。

> **说明：**
>
> buffer是开发者根据需要自定义大小的缓冲区，用于临时存储生成的XML文本。在使用过程中必须确保缓冲区足以容纳生成的文本内容。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                             |
| -------- | --------------------------------- | ---- | ------------------------------------------------ |
| buffer   | ArrayBuffer \| DataView | 是   | 用于接收写入XML信息的ArrayBuffer或DataView内存，需确保缓存区域足以容纳生成的文本内容。 |
| encoding | string                            | 否   | 编码格式，默认'utf-8'（目前仅支持'utf-8'）。               |

**示例：**

```ts
let arrayBuffer = new ArrayBuffer(2048);
let xmlSerializer = new xml.XmlSerializer(arrayBuffer, "utf-8");
```

### setAttributes

setAttributes(name: string, value: string): void

添加元素的属性和属性值。

> **说明：**
>
> 该接口必须在[startElement](#startelement)之后调用，用于为当前已开启的元素设置属性。在元素开始标记写入之前调用此接口将产生无效XML。
>
> 该接口对所添加数据不做标准XML校验处理，请确保所添加的数据符合标准XML规范。例如不允许添加数字开头的属性名称以及添加多个同名的属性名称。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| name   | string | 是   | XML元素的属性名称。   |
| value  | string | 是   | XML元素的属性值，与name参数指定的属性名对应。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("note");
thatSer.setAttributes("importance", "high");
thatSer.endElement();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <note importance="high"/>
```

### addEmptyElement

addEmptyElement(name: string): void

添加一个空元素。

> **说明：**
>
> 该接口对所添加数据不做标准XML校验处理，请确保所添加的数据符合标准XML规范。例如不允许添加数字开头的元素名称。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| name   | string | 是   | 元素的名称，取值原则：不允许以数字开头。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.addEmptyElement("d");
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <d/>
```

### setDeclaration

setDeclaration(): void

设置带有编码信息的文件声明，调用后将在XML文本中生成`<?xml version="1.0" encoding="utf-8"?>`格式的声明。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
import { util } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setDeclaration();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result);
// <?xml version="1.0" encoding="utf-8"?>
```

### startElement

startElement(name: string): void

根据给定名称添加元素开始标记。

> **说明：**
>
>- 调用该接口后须调用[endElement](#endelement)写入元素结束标记，以确保节点正确闭合。
>
>- 该接口对所添加数据不做标准XML校验处理，请确保所添加的数据符合标准XML规范。例如不允许添加数字开头的元素名称。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| name   | string | 是   | 当前元素的元素名。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("note");
thatSer.setText("Happy");
thatSer.endElement();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result);
// <note>Happy</note>
```

### endElement

endElement(): void

添加元素结束标记。

> **说明：**
>
> 调用该接口前必须先调用[startElement](#startelement)接口写入元素开始标记。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
import { util } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("note");
thatSer.setText("Happy");
thatSer.endElement();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result);
// <note>Happy</note>
```

### setNamespace

setNamespace(prefix: string, namespace: string): void

添加当前元素标记的命名空间，适用于需要在同一XML文档中区分来自不同词汇表或模式的元素的场景，如混合使用多个XML标准的文档。

> **说明：**
>
> 该接口应在[startElement](#startelement)之前调用，为即将开启的元素设置命名空间前缀。调用顺序：先调用setNamespace设置命名空间，再调用startElement开启元素。
>
> 该接口对所添加数据不做标准XML校验处理，请确保所添加的数据符合标准XML规范。例如禁止添加数字开头的前缀以及为同一个元素设置多个命名空间。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                           |
| --------- | ------ | ---- | ------------------------------ |
| prefix    | string | 是   | 当前元素及其子元素的前缀。     |
| namespace | string | 是   | 当前元素及其子元素的命名空间。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");
thatSer.startElement("note");
thatSer.endElement();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result);
// <h:note xmlns:h="http://www.w3.org/TR/html4/"/>
```

### setComment

setComment(text: string): void

添加注释内容，所生成的注释结构为：`<!--` + 注释内容 + `-->`。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| text   | string | 是   | 当前元素的注释内容。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setComment("Hello, World!");
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <!--Hello, World!-->
```

### setCDATA

setCDATA(text: string): void

提供在CDATA标签中添加数据的能力，适用于XML内容中包含特殊字符（如<、&等）需要原样保留而不被XML解析器处理的场景。所生成的CDATA标签结构为：`<![CDATA[` + 所添加的数据 + `]]>`。

> **说明：**
>
> 该接口对所添加数据不做标准XML校验处理，请确保所添加的数据符合标准XML规范。例如不允许在CDATA标签中添加包含"\]\]\>"字符串的数据。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明              |
| ------ | ------ | ---- | ----------------- |
| text   | string | 是   | CDATA标签中的数据内容。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setCDATA('root SYSTEM')
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <![CDATA[root SYSTEM]]>
```

### setText

setText(text: string): void

添加标签值，标签值将作为当前元素的文本内容，写入元素的开始标记与结束标记之间。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| text   | string | 是   | XML元素的标签文本内容。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("note");
thatSer.setAttributes("importance", "high");
thatSer.setText("Happy");
thatSer.endElement();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <note importance="high">Happy</note>
```

### setDocType

setDocType(text: string): void

添加文档类型，调用后将在XML文本中生成`<!DOCTYPE ...>`格式的文档类型声明。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                |
| ------ | ------ | ---- | ------------------- |
| text   | string | 是   | 文档类型声明的内容。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setDocType('root SYSTEM "http://www.test.org/test.dtd"');
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <!DOCTYPE root SYSTEM "http://www.test.org/test.dtd">
```

## XmlDynamicSerializer<sup>20+</sup>

XmlDynamicSerializer类用于动态生成XML字符串。当无法确定XML内容长度时，推荐使用该类。

> **说明：**
>
> 使用该类构造的对象无需自行创建ArrayBuffer，程序动态扩容，可以不断添加XML元素，最终序列化结果字符串长度上限为100000。

### constructor<sup>20+</sup>

constructor(encoding?: string)

构造并返回一个XmlDynamicSerializer对象，该对象支持动态扩容生成XML字符串，无需预先指定缓存大小。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                             |
| -------- | --------------------------------- | ---- | ------------------------------------------------ |
| encoding | string                            | 否   | 编码格式，默认'utf-8'（目前仅支持'utf-8'）。          |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200066 | Incorrect encoding format, only support utf-8. |

**示例：**

```ts
let serializer = new xml.XmlDynamicSerializer('utf-8');
```

### getOutput<sup>20+</sup>

getOutput(): ArrayBuffer

返回XML字符串的ArrayBuffer。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| ArrayBuffer | 用于接收写入XML信息的ArrayBuffer内存。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.startElement("note");
serializer.setText("Happy");
serializer.endElement();
let arr = serializer.getOutput();
let uint8 = new Uint8Array(arr);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <note>Happy</note>
```

### setAttributes<sup>20+</sup>

setAttributes(name: string, value: string): void

写入元素的属性和属性值。

> **说明：**
>
> 该接口必须在[startElement<sup>20+</sup>](#startelement20)之后调用，用于为当前已开启的元素设置属性。
>
> 该接口对所添加数据不做标准XML校验处理，请确保所添加的数据符合标准XML规范。例如不允许添加数字开头的属性名称以及添加多个同名的属性名称。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| name   | string | 是   | 属性名。所组成的XML长度不能超过100000，不可为空字符。|
| value  | string | 是   | 属性值。所组成的XML长度不能超过100000字符。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200062 | The cumulative length of xml has exceeded the upper limit 100000. |
| 10200063 | Illegal position for xml. |
| 10200064 | Cannot be an empty string. |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.startElement("note");
serializer.setAttributes("importance", "high");
serializer.endElement();
let arrayBuffer = serializer.getOutput();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <note importance="high"/>
```

### addEmptyElement<sup>20+</sup>

addEmptyElement(name: string): void

写入一个空元素。

> **说明：**
>
> 该接口对所添加数据不做标准XML校验处理，请确保所添加的数据符合标准XML规范。例如不允许添加数字开头的元素名称。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| name   | string | 是   | 该空元素的元素名，所组成的XML长度不能超过100000。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200062 | The cumulative length of xml has exceeded the upper limit 100000. |
| 10200064 | Cannot be an empty string. |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.addEmptyElement("d");
let arrayBuffer = serializer.getOutput();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <d/>
```

### setDeclaration<sup>20+</sup>

setDeclaration(): void

编写带有编码的文件声明，调用后将在XML文本中生成`<?xml version="1.0" encoding="utf-8"?>`格式的声明。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200062 | The cumulative length of xml has exceeded the upper limit 100000. |
| 10200063 | Illegal position for xml. |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.setDeclaration();
let arrayBuffer = serializer.getOutput();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <?xml version="1.0" encoding="utf-8"?>
```

### startElement<sup>20+</sup>

startElement(name: string): void

写入元素开始标记。

> **说明：**
>
>- 调用该接口后须调用[endElement<sup>20+</sup>](#endelement20)写入元素结束标记，以确保节点正确闭合。
>
>- 该接口对所添加数据不做标准XML校验处理，请确保所添加的数据符合标准XML规范。例如不允许添加数字开头的元素名称。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| name   | string | 是   | 当前元素的元素名。所组成的XML长度不能超过100000，不可为空字符。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200062 | The cumulative length of xml has exceeded the upper limit 100000. |
| 10200064 | Cannot be an empty string. |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.startElement("note");
serializer.setText("Happy");
serializer.endElement();
let arrayBuffer = serializer.getOutput();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <note>Happy</note>
```

### endElement<sup>20+</sup>

endElement(): void

写入元素结束标记。

> **说明：**
>
> 调用该接口前必须先调用[startElement<sup>20+</sup>](#startelement20)接口写入元素开始标记。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200062 | The cumulative length of xml has exceeded the upper limit 100000. |
| 10200065 | There is no match between the startElement and the endElement. |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.startElement("note");
serializer.setText("Happy");
serializer.endElement();
let arrayBuffer = serializer.getOutput();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <note>Happy</note>
```

### setNamespace<sup>20+</sup>

setNamespace(prefix: string, namespace: string): void

写入当前元素标记的命名空间。

> **说明：**
>
> 该接口应在[startElement<sup>20+</sup>](#startelement20)之前调用，为即将开启的元素设置命名空间前缀。调用顺序：先调用setNamespace设置命名空间，再调用startElement开启元素。
>
> 该接口对所添加数据不做标准XML校验处理，请确保所添加的数据符合标准XML规范。例如不允许添加数字开头的前缀以及为同一个元素设置多个命名空间。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                           |
| --------- | ------ | ---- | ------------------------------ |
| prefix    | string | 是   | 当前元素及其子元素的前缀。所组成的XML长度不能超过100000，不可为空字符串。 |
| namespace | string | 是   | 当前元素及其子元素的命名空间。所组成的XML长度不能超过100000，不可为空字符串。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200062 | The cumulative length of xml has exceeded the upper limit 100000. |
| 10200064 | Cannot be an empty string. |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.setNamespace("h", "http://www.w3.org/TR/html4/");
serializer.startElement("note");
serializer.endElement();
let arrayBuffer = serializer.getOutput();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <h:note xmlns:h="http://www.w3.org/TR/html4/"/>
```

### setComment<sup>20+</sup>

setComment(text: string): void

写入注释内容，所生成的注释结构为：`<!--` + 注释内容 + `-->`。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| text   | string | 是   | 当前元素的注释内容。所组成的XML长度不能超过100000，不可为空字符。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200062 | The cumulative length of xml has exceeded the upper limit 100000. |
| 10200064 | Cannot be an empty string. |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.setComment("Hello, World!");
let arrayBuffer = serializer.getOutput();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <!--Hello, World!-->
```

### setCdata<sup>20+</sup>

setCdata(text: string): void

提供在CDATA标签中添加数据的能力，所生成的CDATA标签结构为：`<![CDATA[` + 所添加的数据 + `]]>`。

> **说明：**
>
> 该接口对所添加数据不做标准XML校验处理，请确保所添加的数据符合标准XML规范。例如不允许在CDATA标签中添加包含"\]\]\>"字符串的数据。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明              |
| ------ | ------ | ---- | ----------------- |
| text   | string | 是   | CDATA标签中的数据内容。所组成的XML长度不能超过100000。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200062 | The cumulative length of xml has exceeded the upper limit 100000. |
| 10200064 | Cannot be an empty string. |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.setCdata('root SYSTEM')
let arrayBuffer = serializer.getOutput();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <![CDATA[root SYSTEM]]>
```

### setText<sup>20+</sup>

setText(text: string): void

写入标签值。

> **说明：**
>
> 该接口必须在[startElement<sup>20+</sup>](#startelement20)之后、[endElement<sup>20+</sup>](#endelement20)之前调用，用于设置当前元素的文本内容。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| text   | string | 是   | 标签值。所组成的XML长度不能超过100000，不可为空字符。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200062 | The cumulative length of xml has exceeded the upper limit 100000. |
| 10200064 | Cannot be an empty string. |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.startElement("note");
serializer.setAttributes("importance", "high");
serializer.setText("Happy");
serializer.endElement();
let arrayBuffer = serializer.getOutput();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <note importance="high">Happy</note>
```

### setDocType<sup>20+</sup>

setDocType(text: string): void

写入文档类型。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                |
| ------ | ------ | ---- | ------------------- |
| text   | string | 是   | 文档类型声明的内容。所组成的XML长度不能超过100000。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200062 | The cumulative length of xml has exceeded the upper limit 100000. |
| 10200064 | Cannot be an empty string. |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let serializer = new xml.XmlDynamicSerializer('utf-8');
serializer.setDocType('root SYSTEM "http://www.test.org/test.dtd"');
let arrayBuffer = serializer.getOutput();
let uint8 = new Uint8Array(arrayBuffer);
let result = util.TextDecoder.create().decodeToString(uint8);
console.info(result); // <!DOCTYPE root SYSTEM "http://www.test.org/test.dtd">
```

## XmlPullParser

XmlPullParser接口用于解析现有的XML文件，适用于对XML文本进行随机访问和灵活解析的场景。

### constructor

constructor(buffer: ArrayBuffer | DataView, encoding?: string)

构造并返回一个XmlPullParser对象。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                       |
| -------- | --------------------------------- | ---- | ------------------------------------------ |
| buffer   | ArrayBuffer \| DataView | 是   | 用于解析的XML文本数据所在的ArrayBuffer或DataView内存。 |
| encoding | string                            | 否   | 编码格式，默认'utf-8'（目前仅支持'utf-8'）。         |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml = '<title>Happy</title>'
let textEncoder = new util.TextEncoder();
let uint8Array = textEncoder.encodeInto(strXml);
let xmlParser = new xml.XmlPullParser(uint8Array.buffer as object as ArrayBuffer, 'UTF-8');
```

### parseXml<sup>14+</sup>

parseXml(option: ParseOptions): void

解析XML，调用后将根据ParseOptions中配置的回调函数触发相应的解析事件，通过回调函数传递标签、属性、文本等解析信息。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                          | 必填 | 说明          |
| ------ | ----------------------------- | ---- | ------------- |
| option | [ParseOptions](#parseoptions) | 是   | XML解析选项。 |

**示例：**
具体使用场景可参照[解析XML标签和标签值](../../arkts-utils/xml-parsing.md#解析xml标签和标签值)和[解析XML属性和属性值](../../arkts-utils/xml-parsing.md#解析xml属性和属性值)。

```ts
import { xml, util } from '@kit.ArkTS';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title><![CDATA[测试\n测试]]></title>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let uint8 = textEncoder.encodeInto(strXml);

function onParseEvent(key: xml.EventType, value: xml.ParseInfo) {
  if (key == xml.EventType.CDSECT) {
    console.info(JSON.stringify(value.getText()));
  }
  return true;
}
let options: xml.ParseOptions = {supportDoctype: true, ignoreNameSpace: true, tokenValueCallbackFunction: onParseEvent}
let pullParser = new xml.XmlPullParser(uint8.buffer as object as ArrayBuffer);
pullParser.parseXml(options);
// "测试\n测试"
```

### parse<sup>(deprecated)</sup>

parse(option: ParseOptions): void

该接口用于根据指定的解析选项解析XML文本。

> **说明：**
>
> 从API version 8开始支持，从API version 14开始废弃，建议使用[parseXml<sup>14+</sup>](#parsexml14)替代。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                          | 必填 | 说明                             |
| ------ | ----------------------------- | ---- | -------------------------------- |
| option | [ParseOptions](#parseoptions) | 是   | XML解析选项。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
  '<note importance="high" logged="true">' +
    '<company>John &amp; Hans</company>' +
    '<title>Happy</title>' +
  '</note>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer, 'UTF-8');
let parseResult = '';
function func(name: string, value: string) {
  parseResult = name + value;
  console.info(parseResult);
  return true;
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tagValueCallbackFunction:func}
that.parse(options);
// note
// company
// John & Hans
// company
// title
// Happy
// title
// note
```

## AttributeWithTagCb<sup>20+</sup>

type AttributeWithTagCb = (tagName: string, key: string, value: string) => boolean

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   |  类型  | 必填 |  说明   |
| ------- | -------| ---- | ------ |
| tagName | string | 是   | 标签名称。|
| key     | string | 是   | 属性名称。|
| value   | string | 是   | 属性的值。|

**返回值：**

| 类型    | 说明                                                                       |
| ------- | ------------------------------------------------------------------------- |
| boolean | 是否继续解析标签名称、属性名称及属性的值。true表示继续解析，false表示停止解析。 |

## ParseOptions

XML解析选项，用于配置XmlPullParser的解析行为。开发者可通过supportDoctype和ignoreNameSpace控制解析范围，通过注册回调函数（tagValueCallbackFunction、attributeValueCallbackFunction、tokenValueCallbackFunction等）接收不同类型的解析事件。


**系统能力：** SystemCapability.Utils.Lang


| 名称                           | 类型                                                         | 只读 | 可选 | 说明                                    |
| ------------------------------ | ------------------------------------------------------------ | ---- | ---- | --------------------------------------- |
| supportDoctype                 | boolean                                                      | 否   | 是   | 是否解析文档类型，false表示不解析文档类型，true表示解析文档类型，默认值为false。  <br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。|
| ignoreNameSpace                | boolean                                                      | 否   | 是   | 是否忽略命名空间，忽略命名空间后，将不会对其进行解析。true表示忽略命名空间，false表示不忽略命名空间，默认值为false。 <br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。|
| tagValueCallbackFunction       | (name: string, value: string) =&gt; boolean | 否   | 是   | 解析开始标签、标签值和结束标签，返回true表示继续解析，返回false表示停止解析，默认值为undefined，表示不解析。 <br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。|
| attributeValueCallbackFunction | (name: string, value: string) =&gt; boolean | 否   | 是   | 解析属性和属性值，返回true表示继续解析，返回false表示停止解析，默认值为undefined，表示不解析。 <br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。|
| tokenValueCallbackFunction     | (eventType: [EventType](#eventtype), value: [ParseInfo](#parseinfo)) =&gt; boolean | 否   | 是   | 解析元素事件类型([EventType](#eventtype))和[ParseInfo](#parseinfo)属性，默认值为undefined，表示不解析。 <br/>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。|
| attributeWithTagCallbackFunction<sup>20+</sup> | [AttributeWithTagCb](#attributewithtagcb20) | 否 | 是   | 解析标签名称、属性名称及属性的值，默认值为为undefined，表示不执行解析。 <br/>**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。|

## ParseInfo

当前XML解析信息。


### getColumnNumber

getColumnNumber(): number

获取当前列号，从1开始计数。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 当前元素的列号（从1开始），用于定位XML解析位置。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml = '<?xml version="1.0" encoding="utf-8"?><note>Happy</note>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getColumnNumber() + ' ';
  return true; // 决定是否继续解析，用于继续或终止解析。
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parseXml(options);
console.info(str);
// key:0 value:1 key:2 value:45 key:4 value:50 key:3 value:57 key:1 value:57
```

### getDepth

getDepth(): number

获取元素的当前深度。

> **说明：**
>
> 标签内的空白事件深度与标签的深度保持一致。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 元素的嵌套深度（从0开始），用于判断XML层级结构。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
  '<note importance="high">' +
    '<title>Happy</title>' +
  '</note>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getDepth() + ' ';
  return true; // 决定是否继续解析，用于继续或终止解析。
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parseXml(options);
console.info(str);
// key:0 value:0 key:2 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:3 value:1 key:1 value:0
```

### getLineNumber

getLineNumber(): number

获取当前行号，从1开始。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 当前元素的行号（从1开始），用于定位XML解析位置。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml = '<?xml version="1.0" encoding="utf-8"?><note>Work</note>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getLineNumber() + ' ';
  return true; // 决定是否继续解析，用于继续或终止解析。
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parseXml(options);
console.info(str);
// key:0 value:1 key:2 value:1 key:4 value:1 key:3 value:1 key:1 value:1
```

### getName

getName(): string

获取当前元素名称。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| string | 当前元素的名称（不包含命名空间前缀），用于标识XML元素。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml = '<?xml version="1.0" encoding="utf-8"?><note>Happy</note>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getName() + ' ';
  return true; // 决定是否继续解析，用于继续或终止解析。
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parseXml(options);
console.info(str);
// key:0 value: key:2 value:note key:4 value: key:3 value:note key:1 value:
```
### getNamespace

getNamespace(): string

获取当前元素的命名空间。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 返回当前元素的命名空间。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
  '<note xmlns:h="http://www.w3.org">' +
    '<h:title>Happy</h:title>' +
  '</note>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getNamespace() + ' ';
  return true; // 决定是否继续解析，用于继续或终止解析。
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:false, tokenValueCallbackFunction:func}
that.parseXml(options);
console.info(str);
// key:0 value: key:2 value: key:2 value:http://www.w3.org key:4 value: key:3 value:http://www.w3.org key:3 value: key:1 value:
```
### getPrefix

getPrefix(): string

获取当前元素的命名空间前缀。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| string | 返回当前元素的命名空间前缀，如果元素没有命名空间前缀则返回空字符串。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
  '<note xmlns:h="http://www.w3.org/TR/html4">' +
    '<h:title>Happy</h:title>' +
  '</note>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getPrefix() + ' ';
  return true; // 决定是否继续解析，用于继续或终止解析。
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:false, tokenValueCallbackFunction:func}
that.parseXml(options);
console.info(str);
// key:0 value: key:2 value: key:2 value:h key:4 value: key:3 value:h key:3 value: key:1 value:
```

### getText

getText(): string

获取当前事件的文本内容。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 当前事件的文本内容（如标签值、注释等），用于获取解析的XML数据。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml = '<?xml version="1.0" encoding="utf-8"?><note>Happy</note>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getText() + ' ';
  return true; // 决定是否继续解析，用于继续或终止解析。
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parseXml(options);
console.info(str);
// key:0 value: key:2 value: key:4 value:Happy key:3 value: key:1 value:
```
### isEmptyElementTag

isEmptyElementTag(): boolean

判断当前元素是否为空元素。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                         |
| ------- | ---------------------------- |
| boolean | 返回true，表示当前元素为空元素。返回false，表示当前元素为非空元素。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
  '<note importance="high" logged="true">' +
    '<title/>' +
  '</note>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.isEmptyElementTag() + ' ';
  return true; // 决定是否继续解析，用于继续或终止解析。
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parseXml(options);
console.info(str);
// key:0 value:false key:2 value:false key:2 value:true key:3 value:false key:3 value:false key:1 value:false
```
### isWhitespace

isWhitespace(): boolean

判断当前事件是否只包含空格字符。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | 返回true，表示当前文本事件仅包含空格字符。返回false，表示当前文本事件包含非空格字符。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
  '<note importance="high" logged="true">' +
    '<title> </title>' +
  '</note>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.isWhitespace() + ' ';
  return true; // 决定是否继续解析，用于继续或终止解析。
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parseXml(options);
console.info(str);
// key:0 value:true key:2 value:false key:2 value:true key:10 value:true key:3 value:true key:3 value:true key:1 value:true
```
### getAttributeCount

getAttributeCount(): number

获取当前开始标记的属性数量。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**
| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 当前开始标记的属性数量，用于遍历和处理XML属性。 |

**示例：**

```ts
import { util } from '@kit.ArkTS';

let strXml = '<?xml version="1.0" encoding="utf-8"?><note importance="high" logged="true"/>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getAttributeCount() + ' ';
  return true; // 决定是否继续解析，用于继续或终止解析。
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parseXml(options);
console.info(str);
// key:0 value:0 key:2 value:2 key:3 value:2 key:1 value:0
```

## EventType

事件类型枚举，定义了XmlPullParser在解析XML过程中可能触发的各类事件。解析时事件按START_DOCUMENT→START_TAG→TEXT/CDSECT→END_TAG→END_DOCUMENT等顺序依次触发，开发者可通过tokenValueCallbackFunction回调接收对应事件。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称             | 值   | 说明                  |
| ---------------- | ---- | --------------------- |
| START_DOCUMENT   | 0    | 启动文件事件。        |
| END_DOCUMENT     | 1    | 结束文件事件。        |
| START_TAG        | 2    | 启动标签事件。        |
| END_TAG          | 3    | 结束标签事件。        |
| TEXT             | 4    | 文本事件。            |
| CDSECT           | 5    | CDATA事件。           |
| COMMENT          | 6    | XML注释事件。         |
| DOCDECL          | 7    | XML文档类型声明事件。 |
| INSTRUCTION      | 8    | XML处理指令声明事件。 |
| ENTITY_REFERENCE | 9    | 实体引用事件。        |
| WHITESPACE       | 10   | 空白事件。            |

## XmlSAXParser<sup>24+</sup>

XmlSAXParser类用于以流式方式解析XML文本。适用于需要边读取边处理的场景，支持从[stream.Readable](js-apis-stream.md#readable) 流中读取XML数据并进行解析。

> **说明：**
>
> - 本接口采用流式解析的方式，理论上可以解析任意大小的XML文本。但考虑到实际性能表现，建议单次解析的数据大小不超过300MB，以避免解析时间过长影响使用体验。

### constructor<sup>24+</sup>

constructor(inputStream: stream.Readable, encoding?: string)

构造并返回一个XmlSAXParser对象，用于以SAX方式从可读流中流式解析XML文本。

> **说明：**
>
> - `inputStream`参数必须传入继承自[Readable](js-apis-stream.md#readable)且实现[doRead](js-apis-stream.md#doread)的类。可以传入其他模块中满足该条件的类，如[ReadStream](../apis-core-file-kit/js-apis-file-fs.md#readstream12)。


**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名       | 类型             | 必填 | 说明                                             |
| ------------ | ---------------- | ---- | ------------------------------------------------ |
| inputStream  | [stream.Readable](js-apis-stream.md#readable)  | 是   | 用于读取XML数据的可读流实例。                    |
| encoding     | string           | 否   | 编码格式，默认为'utf-8'（目前仅支持'utf-8'）。     |

**示例：**

```ts
import { xml, stream } from '@kit.ArkTS';

class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
  }
}

let readableStream = new TestReadable();
let saxParser = new xml.XmlSAXParser(readableStream, 'utf-8');
```

### parse<sup>24+</sup>

parse(xmlSAXHandler: XmlSAXHandler): void

使用SAX（Simple API for XML）方式解析XML数据。

> **说明：**
>
> - 在调用parse函数后，用户可以通过控制流的方式来控制解析进度。任意数据块被推入后，解析器会解析相应的进度。具体流控制方式详见[@ohos.util.stream (数据流基类stream)](js-apis-stream.md)。
> - 可以配合自动控制数据的流使用，如[ReadStream](../apis-core-file-kit/js-apis-file-fs.md#readstream12)，此时用户不再需要手动控制数据。
> - parse接口注册了流的on监听器，会自动读取流中的数据。不建议再对流的监听器进行操作或者读取数据，以免发生冲突导致接口能力失效。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名         | 类型                               | 必填 | 说明                    |
| -------------- | ---------------------------------- | ---- | ----------------------- |
| xmlSAXHandler  | [XmlSAXHandler](#xmlsaxhandler24)  | 是   | SAX处理器对象。         |

**示例：**

```ts
import { xml, stream } from '@kit.ArkTS';

class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
  }
}

let readableStream = new TestReadable();
let saxParser = new xml.XmlSAXParser(readableStream);

let handler: xml.XmlSAXHandler = {
  startDocument: () => {
  },
  endDocument: () => {
  },
  startElement: (elementName: string, namespaceURI: string | undefined, qName: string | undefined,
    attributes: Map<string, string>) => {
  },
  endElement: (elementName: string, namespaceURI: string | undefined, qName: string | undefined) => {
  },
  characters: (content: string) => {
  }
};

saxParser.parse(handler);
```

## XmlSAXHandler<sup>24+</sup>

XmlSAXHandler定义了SAX解析XML文本时的回调方法。开发者需要实现这些回调方法来处理XML文本的不同部分。这些回调方法会在XML解析过程的对应时机触发。startDocument会在开始解析文档时触发，endDocument会在结束文档解析时触发，startElement会在开始解析元素时触发，endElement会在结束解析元素时触发，characters则会在解析元素间文本内容时触发。

### startDocument<sup>24+</sup>

startDocument(): void

当解析器在XML文本开始解析时触发的回调函数。该回调函数需要开发者自行实现。具体使用示例可见[characters<sup>24+</sup>](#characters24)。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

### endDocument<sup>24+</sup>

endDocument(): void

当解析器在XML文本结束解析时触发的回调函数。该回调函数需要开发者自行实现。具体使用示例可见[characters<sup>24+</sup>](#characters24)。

> **说明：**
>
> 当可读流结束时触发此回调。在stream中调用push()，传入null值，从而触发该回调。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

### startElement<sup>24+</sup>

startElement(elementName: string, namespaceURI: string | undefined, qName: string | undefined, attributes: Map<string, string>): void

当解析器遇到XML元素的开始标签时触发的回调函数。该回调函数需要开发者自行实现。具体使用示例可见[characters<sup>24+</sup>](#characters24)。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名        | 类型                      | 必填 | 说明                                   |
| ------------- | ------------------------- | ---- | -------------------------------------- |
| elementName   | string                    | 是   | 解析器回传的元素名称（不包含命名空间前缀）。例如，对于`<ns2:child>`，elementName为"child"。 |
| namespaceURI  | string \| undefined       | 是   | 解析器回传的命名空间URI。例如，对于`xmlns:ns2="http://example.com/ns2"`，namespaceURI为`"http://example.com/ns2"`。如果元素没有命名空间则为undefined。 |
| qName        | string \| undefined       | 是   | 解析器回传的元素限定名（包含命名空间前缀）。例如，对于`<ns2:child>`，qName为"ns2:child"。如果元素没有命名空间则qName为undefined。 |
| attributes    | Map<string, string>       | 是   | 解析器回传的元素的属性映射表，键为属性名（可能包含命名空间前缀，如"ns2:attrA"），值为属性值。 |

### endElement<sup>24+</sup>

endElement(elementName: string, namespaceURI: string | undefined, qName: string | undefined): void

当解析器遇到XML元素的结束标签时触发的回调函数。该回调函数需要开发者自行实现。具体使用示例可见[characters<sup>24+</sup>](#characters24)。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名        | 类型                      | 必填 | 说明                                   |
| ------------- | ------------------------- | ---- | -------------------------------------- |
| elementName   | string                    | 是   | 解析器回传的元素名称（不包含命名空间前缀）。例如，对于`<ns2:child>`，elementName为"child"。 |
| namespaceURI  | string \| undefined       | 是   | 解析器回传的命名空间URI。例如，对于`xmlns:ns2="http://example.com/ns2"`，namespaceURI为`"http://example.com/ns2"`。如果元素没有命名空间则为undefined。 |
| qName        | string \| undefined       | 是   | 解析器回传的元素限定名（包含命名空间前缀）。例如，对于`<ns2:child>`，qName为"ns2:child"。如果元素没有命名空间则qName为undefined。 |

### characters<sup>24+</sup>

characters(content: string): void

当解析器在XML元素内部遇到文本内容时调用的回调函数。该回调函数需要开发者自行实现。

**原子化服务API**：从API version 24开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型   | 必填 | 说明             |
| -------- | ------ | ---- | ---------------- |
| content  | string | 是   | 解析器回传元素中的文本内容。       |

**示例：**

```ts
import { xml, stream } from '@kit.ArkTS';

class TestReadable extends stream.Readable {
  constructor() {
    super();
  }

  doRead(size: number) {
  }
}

const saxHandler: xml.XmlSAXHandler = {
  startDocument() {
    console.info("startDocument");
  },
  endDocument() {
    console.info("endDocument");
  },
  startElement(elementName: string, namespaceURI: string | undefined, qName: string | undefined,
    attributes: Map<string, string>) {
    console.info("startElement elementName:", elementName);
    console.info("startElement namespaceURI:", namespaceURI);
    console.info("startElement qName:", qName);
    if (attributes) {
      attributes.forEach((value, key) => {
        console.info("startElement attribute:", key, "=", value);
      });
    }
  },
  endElement(elementName: string, namespaceURI: string | undefined, qName: string | undefined) {
    console.info("endElement elementName:", elementName);
  },
  characters(content: string) {
    console.info("characters:", content);
  }
};

let readableStream = new TestReadable();
let saxParser = new xml.XmlSAXParser(readableStream);
saxParser.parse(saxHandler);

let testData = '<?xml version="1.0" encoding="UTF-8"?>\n' +
  '<root xmlns:ns1="http://example.com/ns1">\n' +
  '  <ns1:child ns1:attr1="value1" attr2="value2">Text content</ns1:child>\n' +
  '</root>';

readableStream.push(testData);
readableStream.push(null);
// 输出示例：
// startDocument
// startElement elementName: root
// startElement namespaceURI: undefined
// startElement qName: undefined
// characters: 
// 
// startElement elementName: child
// startElement namespaceURI: http://example.com/ns1
// startElement qName: ns1:child
// startElement attribute: attr2 = value2
// startElement attribute: ns1:attr1 = value1
// characters: Text content
// endElement elementName: child
// characters: 
// endElement elementName: root
// endDocument
```