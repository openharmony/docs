# Arkts子系统变更说明

## cl.arkts.1 xml.XmlPullParser.parse接口行为变更

**访问级别**

公开接口

**变更原因**

parse接口解析xml时，会把实体引用事件识别为文本事件，用户在tokenValueCallbackFunction中指定的回调函数无法得到实体引用事件的解析结果，解析内容会被整合在文本事件中，不符合设计预期，需要修改。

**变更影响**

不兼容变更，影响parse接口解析带实体引用事件的xml的解析结果，修改在API12及更高版本中适用。不带实体引用事件的xml解析不受影响。

以下面的例子说明变更前后差异，strXml存放待解析的xml，func为开发者自行准备的tokenValueCallbackFunction型回调函数，parse接口解析后得到的每个事件都会触发一次回调，并传入事件类型和对应的xml解析结果。
```
let strXml = '<?xml version="1.0" encoding="utf-8"?>\n' +
                '<note>&amp;happy&amp;</note>';    // 此处第一个实体引用“&amp;”属于实体引用事件，而第二个实体引用“&amp;”由于紧随文本“happy”，“happy&amp;”作为整体属于文本事件。
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer, 'UTF-8');
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo){
  str += 'key:' + key +' value:' + value.getText() + '  ';
  return true;
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
```

**变更前**

- 所有版本解析结果不包含实体引用事件。

```
&amp;happy&amp;解析结果为：
key为4（文本事件），value为&happy&
```


**变更后**

- API12及更高版本解析结果包含实体引用事件，其他情况和变更前一致。

```
&amp;happy&amp;解析结果为2个：
key为9（实体引用事件），value为&
key为4（文本事件），value为happy&
```


**起始API Level**

8

**变更发生版本**

从OpenHarmony SDK 5.0.0.38 版本开始，仅在API12及更高版本适用此修改。

**变更的接口/组件**

xml.XmlPullParser.parse

**适配指导**

一、实体引用事件说明
目前仅支持在XML中5个预定义的实体引用对应的实体引用事件：
```
&lt;    <  less than
&gt;    >  greater than
&amp;   &  ampersand
&apos;  '  apostrophe
&quot;  "  quotation mark
```
另外，实体引用前存在文本时会被一起视为文本事件，如：
```
<note>happy&lt;&gt;</note> 依次为：启动标签事件；文本事件；结束标签事件。
<note>&lt;&gt;happy</note> 依次为：启动标签事件；实体引用事件；实体引用事件；文本事件；结束标签事件。
```

二、开发者如果需要使用实体引用事件，需要至少使用API12，并在xml中严格遵从实体引用事件的格式，不在实体引用前加普通文本形成文本事件

三、开发者如果不需要使用实体引用事件，在xml中实体引用前面加普通文本形成文本事件就行，或者自行适配回调函数。

文档可参考如下：

https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkts/js-apis-xml.md#parse
