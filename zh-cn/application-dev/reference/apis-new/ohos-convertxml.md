# @ohos.convertxml    
本模块提供转换xml文本为JavaScript对象的功能。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import xml from '@ohos.convertxml'    
```  
    
## ConvertOptions    
转换选项。    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| trim | boolean | false | true | 是否修剪位于文本前后的空白字符，默认false。<br/> |  
| trim<sup>(10+)</sup> | boolean | false | true | 是否修剪位于文本前后的空白字符，默认false。<br/> |  
| ignoreDeclaration | boolean | false | false | 是否忽略xml写入声明指示，默认false。<br/> |  
| ignoreDeclaration<sup>(10+)</sup> | boolean | false | false | 是否忽略xml写入声明指示，默认false。<br/> |  
| ignoreInstruction | boolean | false | false | 是否忽略xml的写入处理指令，默认false。<br/> |  
| ignoreInstruction<sup>(10+)</sup> | boolean | false | false | 是否忽略xml的写入处理指令，默认false。<br/> |  
| ignoreAttributes | boolean | false | false | 是否跨多行打印属性并缩进属性，默认false。<br/> |  
| ignoreAttributes<sup>(10+)</sup> | boolean | false | false | 是否跨多行打印属性并缩进属性，默认false。<br/> |  
| ignoreComment | boolean | false | false | 是否忽略元素的注释信息，默认false。<br/> |  
| ignoreComment<sup>(10+)</sup> | boolean | false | false | 是否忽略元素的注释信息，默认false。<br/> |  
| ignoreCDATA | boolean | false | false | 是否忽略元素的CDATA信息，默认false。<br/> |  
| ignoreCDATA<sup>(10+)</sup> | boolean | false | false | 是否忽略元素的CDATA信息，默认false。<br/> |  
| ignoreDoctype | boolean | false | false | 是否忽略元素的Doctype信息，默认false。<br/> |  
| ignoreDoctype<sup>(10+)</sup> | boolean | false | false | 是否忽略元素的Doctype信息，默认false。<br/> |  
| ignoreText | boolean | false | false | 是否忽略元素的文本信息，默认false。<br/> |  
| ignoreText<sup>(10+)</sup> | boolean | false | false | 是否忽略元素的文本信息，默认false。<br/> |  
| declarationKey | string | false | true | 用于输出对象中declaration的属性键的名称，默认_declaration。<br/> |  
| declarationKey<sup>(10+)</sup> | string | false | true | 用于输出对象中declaration的属性键的名称，默认_declaration。<br/> |  
| instructionKey | string | false | true | 用于输出对象中instruction的属性键的名称，默认_instruction。<br/> |  
| instructionKey<sup>(10+)</sup> | string | false | true | 用于输出对象中instruction的属性键的名称，默认_instruction。<br/> |  
| attributesKey | string | false | true | 用于输出对象中attributes的属性键的名称，默认_attributes。<br/> |  
| attributesKey<sup>(10+)</sup> | string | false | true | 用于输出对象中attributes的属性键的名称，默认_attributes。<br/> |  
| textKey | string | false | true | 用于输出对象中text的属性键的名称，默认_text。<br/> |  
| textKey<sup>(10+)</sup> | string | false | true | 用于输出对象中text的属性键的名称，默认_text。<br/> |  
| cdataKey | string | false | true | 用于输出对象中cdata的属性键的名称，默认_cdata。<br/> |  
| cdataKey<sup>(10+)</sup> | string | false | true | 用于输出对象中cdata的属性键的名称，默认_cdata。<br/> |  
| doctypeKey | string | false | true | 用于输出对象中doctype的属性键的名称，默认_doctype。<br/> |  
| doctypeKey<sup>(10+)</sup> | string | false | true | 用于输出对象中doctype的属性键的名称，默认_doctype。<br/> |  
| commentKey | string | false | true | 用于输出对象中comment的属性键的名称，默认_comment。<br/> |  
| commentKey<sup>(10+)</sup> | string | false | true | 用于输出对象中comment的属性键的名称，默认_comment。<br/> |  
| parentKey | string | false | true | 用于输出对象中parent的属性键的名称，默认_parent。<br/> |  
| parentKey<sup>(10+)</sup> | string | false | true | 用于输出对象中parent的属性键的名称，默认_parent。<br/> |  
| typeKey | string | false | true | 用于输出对象中type的属性键的名称，默认_type。<br/> |  
| typeKey<sup>(10+)</sup> | string | false | true | 用于输出对象中type的属性键的名称，默认_type。<br/> |  
| nameKey | string | false | true | 用于输出对象中name的属性键的名称，默认_name。<br/> |  
| nameKey<sup>(10+)</sup> | string | false | true | 用于输出对象中name的属性键的名称，默认_name。<br/> |  
| elementsKey | string | false | true |  |  
| elementsKey<sup>(10+)</sup> | string | false | true | 用于输出对象中elements的属性键的名称，默认_elements。<br/> |  
    
## ConvertXML  
 **系统能力:**  SystemCapability.Utils.Lang    
### convert<sup>(deprecated)</sup>    
转换xml文本为JavaScript对象。  
 **调用形式：**     
- convert(xml: string, options?: ConvertOptions): Object  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.convertxml.ConvertXML.convertToJSObject。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| xml<sup>(deprecated)</sup> | string | true | 传入的xml文本。<br/> |  
| options<sup>(deprecated)</sup> | ConvertOptions | false | 转换选项 , 默认值是ConvertOptions对象 , 由其中各个属性的默认值组成。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Object | 处理后返回的JavaScript对象。 |  
    
 **示例代码：**   
```ts    
let xml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let conv = new convertxml.ConvertXML();let options: convertxml.ConvertOptions = {trim : false, declarationKey:"_declaration",  instructionKey : "_instruction", attributesKey : "_attributes",  textKey : "_text", cdataKey:"_cdata", doctypeKey : "_doctype",  commentKey : "_comment", parentKey : "_parent", typeKey : "_type",  nameKey : "_name", elementsKey : "_elements"}let result = JSON.stringify(conv.convert(xml, options));console.log(result);// 输出(宽泛型)// {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note","_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Play"}]}]}]}  
    
```    
  
    
### convertToJSObject<sup>(9+)</sup>    
转换xml文本为JavaScript对象。  
 **调用形式：**     
- convertToJSObject(xml: string, options?: ConvertOptions): Object  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| xml | string | true | 传入的xml文本。 |  
| options | ConvertOptions | false | 转换选项 , 默认值是ConvertOptions对象 , 由其中各个属性的默认值组成。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Object | 处理后返回的JavaScript对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200002 | Invalid xml string. |  
    
 **示例代码：**   
```ts    
try {  
  let xml =  
    '<?xml version="1.0" encoding="utf-8"?>' +  
      '<note importance="high" logged="true">' +  
      '    <title>Happy</title>' +  
      '    <todo>Work</todo>' +  
      '    <todo>Play</todo>' +  
      '</note>';  
  let conv = new convertxml.ConvertXML()  
  let options: convertxml.ConvertOptions = {  
    trim: false, declarationKey: "_declaration",  
    instructionKey: "_instruction", attributesKey: "_attributes",  
    textKey: "_text", cdataKey: "_cdata", doctypeKey: "_doctype",  
    commentKey: "_comment", parentKey: "_parent", typeKey: "_type",  
    nameKey: "_name", elementsKey: "_elements"  
  }  
  let result = JSON.stringify(conv.convertToJSObject(xml, options));  
  console.log(result);  
} catch (e) {  
  console.log((e as Object).toString());  
}  
// 输出(宽泛型)  
// {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note","_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Play"}]}]}]}  
  
    
```    
  
