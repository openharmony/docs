# XML转换


将XML文本转换为JavaScript对象可以更轻松地处理和操作数据，并且更适合在JavaScript应用程序中使用。


语言基础类库提供ConvertXML类将XML文本转换为JavaScript对象，输入为待转换的XML字符串及转换选项，输出为转换后的JavaScript对象。具体转换选项可见[API参考@ohos.convertxml](../reference/apis-arkts/js-apis-convertxml.md)。


## 注意事项

XML解析及转换需要确保传入的XML数据符合标准格式。


## 开发步骤

此处以XML转为JavaScript对象后获取其标签值为例，说明转换效果。

1. 引入模块。

   ```ts
   import { convertxml } from '@kit.ArkTS';
   ```

2. 输入待转换的XML，设置转换选项，支持的转换选项及含义具体可见[ConvertOptions](../reference/apis-arkts/js-apis-convertxml.md#convertoptions)。

   > **说明：**
   >
   > 传入的XML文本中，若包含“&”字符，请使用实体引用“\&amp;”替换。

   ```ts
   let xml: string =
    '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
   let options: convertxml.ConvertOptions = {
     // trim: false 转换后是否删除文本前后的空格，否
     // declarationKey: "_declaration" 转换后文件声明使用_declaration来标识
     // instructionKey: "_instruction" 转换后指令使用_instruction标识
     // attributesKey: "_attributes" 转换后属性使用_attributes标识
     // textKey: "_text" 转换后标签值使用_text标识
     // cdataKey: "_cdata" 转换后未解析数据使用_cdata标识
     // docTypeKey: "_doctype" 转换后文档类型使用_doctype标识
     // commentKey: "_comment" 转换后注释使用_comment标识
     // parentKey: "_parent" 转换后父类使用_parent标识
     // typeKey: "_type" 转换后元素类型使用_type标识
     // nameKey: "_name" 转换后标签名称使用_name标识
     // elementsKey: "_elements" 转换后元素使用_elements标识
     trim: false,
     declarationKey: "_declaration",
     instructionKey: "_instruction",
     attributesKey: "_attributes",
     textKey: "_text",
     cdataKey: "_cdata",
     doctypeKey: "_doctype",
     commentKey: "_comment",
     parentKey: "_parent",
     typeKey: "_type",
     nameKey: "_name",
     elementsKey: "_elements"
   }
   ```

3. 调用转换函数，打印结果。

   ```ts
   let conv: convertxml.ConvertXML = new convertxml.ConvertXML();
   let result: object = conv.convertToJSObject(xml, options);
   let strRes: string = JSON.stringify(result); // 将js对象转换为json字符串，用于显式输出
   console.info(strRes);
   ```

   输出结果如下所示：

   ```json
   strRes:
   {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note",
    "_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title",
    "_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo",
    "_elements":[{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo",
    "_elements":[{"_type":"text","_text":"Play"}]}]}]}
   ```
