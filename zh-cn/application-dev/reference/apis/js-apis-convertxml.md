# xml转换JavaScript

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import convertxml from '@ohos.convertxml'
```


## 权限

无

## ConvertXML


### convert

convert(xml: string, options?: ConvertOptions) : Object

转化xml文本为JavaScript对象。


- 参数：

  | 参数名  | 类型                              | 必填 | 说明               |
  | ------- | --------------------------------- | ---- | ------------------ |
  | xml     | string                            | 是   | 传入的xml文本。    |
  | options | [ConvertOptions](#convertoptions) | 否   | 用户可进行的选项。 |

- 返回值：

  | 类型   | 说明                         |
  | ------ | ---------------------------- |
  | string | 处理后返回的JavaScript对象。 |

- 示例：

  ```
  var xml =
      '<?xml version="1.0" encoding="utf-8"?>' +
      '<note importance="high" logged="true">' +
      '    <title>Happy</title>' +
      '    <todo>Work</todo>' +
      '    <todo>Play</todo>' +
      '</note>';
  var conv= new convertxml.ConvertXML();
  var result1 = conv.convert(xml, {trim: false, ignoreDeclaration: false});
  console.log(result1)
  ```


## ConvertOptions

| 名称              | 参数类型 | 必填 | 说明                                                        |
| ----------------- | -------- | ---- | ----------------------------------------------------------- |
| trim              | boolean  | 否   | 是否修剪位于文本前后的空白字符，默认false。                 |
| ignoreDeclaration | boolean  | 否   | 是否忽略xml写入声明指示，默认false。                        |
| ignoreInstruction | boolean  | 否   | 是否忽略xml的写入处理指令，默认false。                      |
| ignoreAttributes  | boolean  | 否   | 是否跨多行打印属性并缩进属性，默认false。                   |
| ignoreComment     | boolean  | 否   | 是否忽略元素的注释信息，默认false。                         |
| ignoreCdata       | boolean  | 否   | 是否忽略元素的CData信息，默认false。                        |
| ignoreDoctype     | boolean  | 否   | 是否忽略元素的Doctype信息，默认false。                      |
| ignoreText        | boolean  | 否   | 是否忽略元素的文本信息，默认false。                         |
| declarationKey    | string   | 否   | 用于输出对象中declaration的属性键的名称，默认_declaration。 |
| instructionKey    | string   | 否   | 用于输出对象中instruction的属性键的名称，默认_instruction。 |
| attributesKey     | string   | 否   | 用于输出对象中attributes的属性键的名称，默认_attributes。   |
| textKey           | string   | 否   | 用于输出对象中text的属性键的名称，默认_text。               |
| cdataKey          | string   | 否   | 用于输出对象中cdata的属性键的名称，默认_cdata。             |
| doctypeKey        | string   | 否   | 用于输出对象中doctype的属性键的名称，默认_doctype。         |
| commentKey        | string   | 否   | 用于输出对象中comment的属性键的名称，默认_comment。         |
| parentKey         | string   | 否   | 用于输出对象中parent的属性键的名称，默认_parent。           |
| typeKey           | string   | 否   | 用于输出对象中type的属性键的名称，默认_type。               |
| nameKey           | string   | 否   | 用于输出对象中name的属性键的名称，默认_name。               |
| elementsKey       | string   | 否   | 用于输出对象中elements的属性键的名称，默认_elements。       |