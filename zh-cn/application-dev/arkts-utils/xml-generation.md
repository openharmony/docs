# XML生成
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--SE: @yuanyao14-->
<!--TSE: @kirl75; @zsw_zhushiwei-->


XML可以作为数据交换格式，被各种系统和应用程序支持。例如Web服务，可以将结构化数据以XML格式进行传递。


XML还可以作为消息传递格式，用于分布式系统中不同节点的通信。


## 注意事项

- XML标签必须成对出现，生成开始标签就要生成结束标签。

- XML标签对大小写敏感，开始标签与结束标签大小写要一致。


## 开发步骤

XML模块提供`XmlSerializer`及`XmlDynamicSerializer`类来生成XML数据，使用`XmlSerializer`需传入固定长度的`ArrayBuffer`或`DataView`对象作为输出缓冲区，用于存储序列化后的XML数据。
`XmlDynamicSerializer`类动态扩容，程序根据实际生成的数据大小自动创建`ArrayBuffer`。

调用不同的方法写入不同的内容，如startElement(name: string)写入元素开始标记，setText(text: string)写入标签值。

XML模块的API接口可以参考[@ohos.xml](../reference/apis-arkts/js-apis-xml.md)的详细描述，按需求调用相应的函数可以生成一份完整的XML数据。

使用XmlSerializer生成XML示例如下：

1. 引入模块。

   ```ts
   import { xml, util } from '@kit.ArkTS';
   ```

2. 创建缓冲区，构造XmlSerializer对象。可以基于ArrayBuffer构造XmlSerializer对象，也可以基于DataView构造XmlSerializer对象。

   方式1：基于ArrayBuffer构造XmlSerializer对象

   ```ts
   let arrayBuffer: ArrayBuffer = new ArrayBuffer(2048); // 创建一个2048字节的缓冲区
   let serializer: xml.XmlSerializer = new xml.XmlSerializer(arrayBuffer); // 基于ArrayBuffer构造XmlSerializer对象
   ```

   方式2：基于DataView构造XmlSerializer对象

   ```ts
   let arrayBuffer: ArrayBuffer = new ArrayBuffer(2048); // 创建一个2048字节的缓冲区
   let dataView: DataView = new DataView(arrayBuffer); // 创建一个DataView
   let serializer: xml.XmlSerializer = new xml.XmlSerializer(dataView); // 基于DataView构造XmlSerializer对象
   ```

3. 调用XML元素生成函数。

   ```ts
   serializer.setDeclaration(); // 写入XML的声明
   serializer.startElement('bookstore'); // 写入元素开始标记
   serializer.startElement('book'); // 嵌套元素开始标记
   serializer.setAttributes('category', 'COOKING'); // 写入属性及其属性值
   serializer.startElement('title');
   serializer.setAttributes('lang', 'en');
   serializer.setText('Everyday'); // 写入标签值
   serializer.endElement(); // 写入结束标记
   serializer.startElement('author');
   serializer.setText('Giana');
   serializer.endElement();
   serializer.startElement('year');
   serializer.setText('2005');
   serializer.endElement();
   serializer.endElement();
   serializer.endElement();
   ```

4. 使用Uint8Array操作ArrayBuffer，并调用TextDecoder对Uint8Array解码后输出。

   ```ts
   let uint8Array: Uint8Array = new Uint8Array(arrayBuffer); // 使用Uint8Array读取arrayBuffer的数据
   let textDecoder: util.TextDecoder = util.TextDecoder.create(); // 调用util模块的TextDecoder类
   let result: string = textDecoder.decodeToString(uint8Array); // 对uint8Array解码
   console.info(result);
   ```

   输出结果如下：

   ```
   <?xml version="1.0" encoding="utf-8"?><bookstore>
     <book category="COOKING">
       <title lang="en">Everyday</title>
       <author>Giana</author>
       <year>2005</year>
     </book>
   </bookstore>
   ```

使用`XmlDynamicSerializer`生成XML示例如下：

1. 引入模块。

   ```ts
   import { xml, util } from '@kit.ArkTS';
   ```

2. 调用XML元素生成函数。

   ```ts
   let DySerializer = new xml.XmlDynamicSerializer('utf-8');
   DySerializer.setDeclaration(); // 写入XML的声明
   DySerializer.startElement('bookstore'); // 写入元素开始标记
   DySerializer.startElement('book'); // 嵌套元素开始标记
   DySerializer.setAttributes('category', 'COOKING'); // 写入属性及其属性值
   DySerializer.startElement('title');
   DySerializer.setAttributes('lang', 'en');
   DySerializer.setText('Everyday'); // 写入标签值
   DySerializer.endElement(); // 写入结束标记
   DySerializer.startElement('author');
   DySerializer.setText('Giana');
   DySerializer.endElement();
   DySerializer.startElement('year');
   DySerializer.setText('2005');
   DySerializer.endElement();
   DySerializer.endElement();
   DySerializer.endElement();
   let arrayBuffer = DySerializer.getOutput();
   ```

4. 使用Uint8Array操作ArrayBuffer，并调用TextDecoder对Uint8Array解码后输出。

   ```ts
   let uint8Array: Uint8Array = new Uint8Array(arrayBuffer);
   let result: string = util.TextDecoder.create().decodeToString(uint8Array);
   console.info(result);
   ```

   输出结果如下：

   ```
   <?xml version="1.0" encoding="utf-8"?>
   <bookstore>
     <book category="COOKING">
       <title lang="en">Everyday</title>
       <author>Giana</author>
       <year>2005</year>
     </book>
   </bookstore>
   ```