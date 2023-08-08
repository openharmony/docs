# XML解析


对于以XML作为载体传递的数据，实际使用中需要对相关的节点进行解析，一般包括[解析XML标签和标签值](#解析xml标签和标签值)、[解析XML属性和属性值](#解析xml属性和属性值)、[解析XML事件类型和元素深度](#解析xml事件类型和元素深度)三类场景。


XML模块提供XmlPullParser类对XML文件解析，输入为含有XML文本的ArrayBuffer或DataView，输出为解析得到的信息。


  **表1** XML解析选项

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| supportDoctype | boolean | 否 | 是否忽略文档类型。默认为false，表示对文档类型进行解析。 |
| ignoreNameSpace | boolean | 否 | 是否忽略命名空间。默认为false，表示对命名空间进行解析。 |
| tagValueCallbackFunction | (name: string, value: string) =&gt; boolean | 否 | 获取tagValue回调函数，打印标签及标签值。默认为null，表示不进行XML标签和标签值的解析。 |
| attributeValueCallbackFunction | (name: string, value: string) =&gt; boolean | 否 | 获取attributeValue回调函数， 打印属性及属性值。默认为null，表示不进行XML属性和属性值的解析。 |
| tokenValueCallbackFunction | (eventType: EventType, value: ParseInfo) =&gt; boolean | 否 | 获取tokenValue回调函数，打印标签事件类型及parseInfo对应属性。默认为null，表示不进行XML事件类型解析。 |


## 注意事项

- XML解析及转换需要确保传入的XML数据符合标准格式。

- XML解析目前不支持按指定节点解析对应的节点值。


## 解析XML标签和标签值

1. 引入模块。
   
   ```js
   import xml from '@ohos.xml';
   import util from '@ohos.util'; // 需要使用util模块函数对文件编码
   ```

2. 对XML文件编码后调用XmlPullParser。
   可以基于ArrayBuffer构造XmlPullParser对象， 也可以基于DataView构造XmlPullParser对象。

   
   ```js
   let strXml =
     '<?xml version="1.0" encoding="utf-8"?>' +
       '<note importance="high" logged="true">' +
       '<title>Play</title>' +
       '<lens>Work</lens>' +
       '</note>';
   let textEncoder = new util.TextEncoder();
   let arrBuffer = textEncoder.encodeInto(strXml); // 对数据编码，防止包含中文字符乱码
   // 1.基于ArrayBuffer构造XmlPullParser对象
   let that = new xml.XmlPullParser(arrBuffer.buffer, 'UTF-8');
   
   // 2.基于DataView构造XmlPullParser对象
   let dataView = new DataView(arrBuffer.buffer);
   let that = new xml.XmlPullParser(dataView, 'UTF-8');
   ```

3. 自定义回调函数，本例直接打印出标签及标签值。
   
   ```js
   let str = '';
   function func(name, value){
     str = name + value;
     console.info(str);
     return true; //true:继续解析 false:停止解析
   }
   ```

4. 设置解析选项，调用parse函数。
   
   ```js
   let options = {supportDoctype:true, ignoreNameSpace:true, tagValueCallbackFunction:func};
   that.parse(options);
   ```

   输出结果如下所示：

   
   ```js
   note
   title
   Play
   title
   lens
   Work
   lens
   note
   ```


## 解析XML属性和属性值

1. 引入模块。
   
   ```js
   import xml from '@ohos.xml';
   import util from '@ohos.util'; // 需要使用util模块函数对文件编码
   ```

2. 对XML文件编码后调用XmlPullParser。
   
   ```js
   let strXml =
     '<?xml version="1.0" encoding="utf-8"?>' +
       '<note importance="high" logged="true">' +
       '    <title>Play</title>' +
       '    <title>Happy</title>' +
       '    <lens>Work</lens>' +
       '</note>';
   let textEncoder = new util.TextEncoder();
   let arrBuffer = textEncoder.encodeInto(strXml); // 对数据编码，防止包含中文字符乱码
   let that = new xml.XmlPullParser(arrBuffer.buffer, 'UTF-8');
   ```

3. 自定义回调函数，本例直接打印出属性及属性值。
   
   ```js
   let str = '';
   function func(name, value){
     str += name + ' ' + value + ' ';
     return true; // true:继续解析 false:停止解析
   }
   ```

4. 设置解析选项，调用parse函数。
   
   ```js
   let options = {supportDoctype:true, ignoreNameSpace:true, attributeValueCallbackFunction:func};
   that.parse(options);
   console.info(str); // 一次打印出所有的属性及其值
   ```

   输出结果如下所示：

   
   ```js
   importance high logged true // note节点的属性及属性值
   ```


## 解析XML事件类型和元素深度

1. 引入模块。
   
   ```js
   import xml from '@ohos.xml';
   import util from '@ohos.util'; // 需要使用util模块函数对文件编码
   ```

2. 对XML文件编码后调用XmlPullParser。
   
   ```js
   let strXml =
     '<?xml version="1.0" encoding="utf-8"?>' +
     '<note importance="high" logged="true">' +
     '<title>Play</title>' +
     '</note>';
   let textEncoder = new util.TextEncoder();
   let arrBuffer = textEncoder.encodeInto(strXml); // 对数据编码，防止包含中文字符乱码
   let that = new xml.XmlPullParser(arrBuffer.buffer, 'UTF-8');
   ```

3. 自定义回调函数，本例直接打印元素事件类型及元素深度。
   
   ```js
   let str = '';
   function func(name, value){
     str = name + ' ' + value.getDepth(); // getDepth 获取元素的当前深度
     console.info(str)
     return true; //true:继续解析 false:停止解析
   }
   ```

4. 设置解析选项，调用parse函数。
   
   ```js
   let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func};
   that.parse(options);
   ```

   输出结果如下所示：

   
   ```js
   0 0 // 0：<?xml version="1.0" encoding="utf-8"?> 对应事件类型START_DOCUMENT值为0  0：起始深度为0
   2 1 // 2：<note importance="high" logged="true"> 对应事件类型START_TAG值为2       1：深度为1
   2 2 // 2：<title>对应事件类型START_TAG值为2                                       2：深度为2
   4 2 // 4：Play对应事件类型TEXT值为4                                               2：深度为2
   3 2 // 3：</title>对应事件类型END_TAG值为3                                        2：深度为2
   3 1 // 3：</note>对应事件类型END_TAG值为3                                         1：深度为1（与<note对应>）
   1 0 // 1：对应事件类型END_DOCUMENT值为1                                           0：深度为0
   ```


## 场景示例

此处以调用所有解析选项为例，提供解析XML标签、属性和事件类型的开发示例。


```js
import xml from '@ohos.xml';
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="UTF-8"?>' +
    '<book category="COOKING">' +
    '<title lang="en">Everyday</title>' +
    '<author>Giada</author>' +
    '</book>';
let textEncoder = new util.TextEncoder();
let arrBuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrBuffer.buffer, 'UTF-8');
let str = '';

function tagFunc(name, value) {
  str = name + value;
  console.info('tag-' + str);
  return true;
}

function attFunc(name, value) {
  str = name + ' ' + value;
  console.info('attri-' + str);
  return true;
}

function tokenFunc(name, value) {
  str = name + ' ' + value.getDepth();
  console.info('token-' + str);
  return true;
}

let options = {
  supportDocType: true,
  ignoreNameSpace: true,
  tagValueCallbackFunction: tagFunc,
  attributeValueCallbackFunction: attFunc,
  tokenValueCallbackFunction: tokenFunc
};
that.parse(options);

```

输出结果如下所示：


```js
tag-
token-0 0
tag-book
attri-category COOKING
token-2 1
tag-title
attri-lang en
token-2 2
tag-Everyday
token-4 2
tag-title
token-3 2
tag-author
token-2 2
tag-Giada
token-4 2
tag-author
token-3 2
tag-book
token-3 1
tag-
token-1 0
```
