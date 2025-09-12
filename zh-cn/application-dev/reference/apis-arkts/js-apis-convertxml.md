# @ohos.convertxml (xml转换JavaScript)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->

本模块提供转换xml文本为JavaScript对象的功能。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { convertxml } from '@kit.ArkTS';
```

## ConvertXML

### fastConvertToJSObject<sup>14+</sup>

fastConvertToJSObject(xml: string, options?: ConvertOptions) : Object

转换xml文本为Object类型对象。

> **说明：**
>
> 该接口无法满足解析大数据量的XML文件，当单元素文本内容超过10M时，会打印异常信息并返回一个仅包含XML标签头的基础Object对象。
>
> 在Windows环境中，通常以回车符（CR）和换行符（LF）一对字符来表示换行。fastConvertToJSObject接口转换后的对象以换行符（LF）表示换行。

**原子化服务API**：从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型                              | 必填 | 说明            |
| ------- | --------------------------------- | ---- | --------------- |
| xml     | string                            | 是   | xml文本，若包含“&”字符，请使用实体引用“\&amp;”替换。|
| options | [ConvertOptions](#convertoptions) | 否   | 转换选项，默认值是ConvertOptions对象，由其中各个属性的默认值组成。|

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| Object | 转换后的JavaScript对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200002 | Invalid xml string. |

**示例：**

```ts
try {
  let xml =
    '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '   <title>Hello\r\nWorld</title>' +
    '   <todo><![CDATA[Work\r\n]]></todo>' +
    '</note>';
  let conv = new convertxml.ConvertXML();
  let options: convertxml.ConvertOptions = {
    trim: false, declarationKey: "_declaration",
    instructionKey: "_instruction", attributesKey: "_attributes",
    textKey: "_text", cdataKey: "_cdata", doctypeKey: "_doctype",
    commentKey: "_comment", parentKey: "_parent", typeKey: "_type",
    nameKey: "_name", elementsKey: "_elements"
  }
  let result = JSON.stringify(conv.fastConvertToJSObject(xml, options));
  console.info(result);
} catch (e) {
  console.error((e as Object).toString());
}
// 输出(宽泛型)
// {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note","_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_elements":[{"_type":"text","_text":"Hello\nWorld"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"cdata","_cdata":"Work\n"}]}]}]}
```

### convertToJSObject<sup>(deprecated)</sup>

convertToJSObject(xml: string, options?: ConvertOptions) : Object

转换xml文本为Object类型对象。

> **说明：**
>
> 从API version 9开始支持，从API version 14开始废弃，建议使用[fastConvertToJSObject<sup>14+</sup>](#fastconverttojsobject14)替代。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型                              | 必填 | 说明            |
| ------- | --------------------------------- | ---- | --------------- |
| xml     | string                            | 是   | 传入的xml文本，若包含“&”字符，请使用实体引用“\&amp;”替换。|
| options | [ConvertOptions](#convertoptions) | 否   | 转换选项，默认值是ConvertOptions对象，由其中各个属性的默认值组成。 |

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| Object | 处理后返回的JavaScript对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200002 | Invalid xml string. |

**示例：**

```ts
try {
  let xml =
    '<?xml version="1.0" encoding="utf-8"?>' +
      '<note importance="high" logged="true">' +
      '    <title>Happy</title>' +
      '    <todo>Work</todo>' +
      '    <todo>Play</todo>' +
      '</note>';
  let conv = new convertxml.ConvertXML();
  let options: convertxml.ConvertOptions = {
    trim: false, declarationKey: "_declaration",
    instructionKey: "_instruction", attributesKey: "_attributes",
    textKey: "_text", cdataKey: "_cdata", doctypeKey: "_doctype",
    commentKey: "_comment", parentKey: "_parent", typeKey: "_type",
    nameKey: "_name", elementsKey: "_elements"
  }
  let result = JSON.stringify(conv.convertToJSObject(xml, options));
  console.info(result);
} catch (e) {
  console.error((e as Object).toString());
}
// 输出(宽泛型)
// {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note","_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Play"}]}]}]}
```

### convert<sup>(deprecated)</sup>

convert(xml: string, options?: ConvertOptions) : Object

转换xml文本为JavaScript对象。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[fastConvertToJSObject<sup>14+</sup>](#fastconverttojsobject14)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型                              | 必填 | 说明            |
| ------- | --------------------------------- | ---- | --------------- |
| xml     | string                            | 是   | 传入的xml文本。 |
| options | [ConvertOptions](#convertoptions) | 否   | 转换选项，默认值是ConvertOptions对象，由其中各个属性的默认值组成。  |

**返回值：**

| 类型   | 说明                         |
| ------ | ---------------------------- |
| Object | 处理后返回的JavaScript对象。 |

**示例：**

```ts
let xml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let conv = new convertxml.ConvertXML();
let options: convertxml.ConvertOptions = {trim : false, declarationKey:"_declaration",
  instructionKey : "_instruction", attributesKey : "_attributes",
  textKey : "_text", cdataKey:"_cdata", doctypeKey : "_doctype",
  commentKey : "_comment", parentKey : "_parent", typeKey : "_type",
  nameKey : "_name", elementsKey : "_elements"}
let result = JSON.stringify(conv.convert(xml, options));
console.info(result);
// 输出(宽泛型)
// {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note","_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Play"}]}]}]}
```

## ConvertOptions

转换选项。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称              | 类型 | 必填 | 说明                                                        |
| ----------------- | -------- | ---- | ----------------------------------------------------------- |
| trim              | boolean  | 是   | 是否修剪位于文本前后的空白字符，true表示xml文本前后的空白字符将会被修剪，false则表示空白字符会被保留。   |
| ignoreDeclaration | boolean  | 否   | 是否忽略xml写入声明指示，true表示忽略xml写入声明指示，false则相反，默认false。                        |
| ignoreInstruction | boolean  | 否   | 是否忽略xml的写入处理指令，true表示忽略xml的写入处理指令，false则相反，默认false。                      |
| ignoreAttributes  | boolean  | 否   | 是否忽略元素的属性信息，true表示忽略元素的属性信息，false则相反，默认false。                   |
| ignoreComment     | boolean  | 否   | 是否忽略元素的注释信息，true表示忽略元素的注释信息，false则相反，默认false。                         |
| ignoreCDATA       | boolean  | 否   | 是否忽略元素的CDATA信息，true表示忽略元素的CDATA信息，false则相反，默认false。                        |
| ignoreDoctype     | boolean  | 否   | 是否忽略元素的Doctype信息，true表示忽略元素的Doctype信息，false则相反，默认false。                      |
| ignoreText        | boolean  | 否   | 是否忽略元素的文本信息，true表示忽略元素的文本信息，false则相反，默认false。                         |
| declarationKey    | string   | 是   | 用于输出对象中declaration的属性键的名称。 |
| instructionKey    | string   | 是   | 用于输出对象中instruction的属性键的名称。 |
| attributesKey     | string   | 是   | 用于输出对象中attributes的属性键的名称。   |
| textKey           | string   | 是   | 用于输出对象中text的属性键的名称。               |
| cdataKey          | string   | 是   | 用于输出对象中cdata的属性键的名称             |
| doctypeKey        | string   | 是   | 用于输出对象中doctype的属性键的名称。         |
| commentKey        | string   | 是   | 用于输出对象中comment的属性键的名称。         |
| parentKey         | string   | 是   | 用于输出对象中parent的属性键的名称。           |
| typeKey           | string   | 是   | 用于输出对象中type的属性键的名称。               |
| nameKey           | string   | 是   | 用于输出对象中name的属性键的名称。               |
| elementsKey       | string   | 是   | 用于输出对象中elements的属性键的名称。       |