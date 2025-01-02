# Arkts子系统变更说明

## cl.arkts.1 xml.XmlPullParser.parse接口解析实体引用事件的行为变更

**访问级别**

公开接口

**变更原因**

parse接口解析xml时，会把实体引用事件识别为文本事件，用户在tokenValueCallbackFunction中指定的回调函数无法得到实体引用事件的解析结果，解析内容会被整合在文本事件中，不符合设计预期，需要修改。

**变更影响**

该变更为不兼容变更。

变更前：实体引用事件的xml信息被解析为文本事件，用户无法在回调函数中针对实体引用事件进行操作，也无法仅通过xml解析结果判断实体引用事件是否存在。

变更后：在API12及更高版本中，实体引用事件的xml信息被解析为实体引用事件，用户可以在回调函数中针对实体引用事件进行操作，也能仅通过xml解析结果判断实体引用事件是否存在。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.38开始。

**变更的接口/组件**

xml.XmlPullParser.parse

**适配指导**

如果xml原本就不会涉及实体引用事件，则无需适配，没有影响。

如果xml涉及实体引用事件，以下面的例子说明变更前后差异，strXml存放待解析的xml，func为开发者自行准备的tokenValueCallbackFunction型回调函数，parse接口解析后得到的每个事件都会触发一次回调，并传入事件类型和对应的xml解析结果。
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
变更前
```
&amp;happy&amp;解析结果为：
key为4（文本事件），value为&happy&
```
变更后
```
&amp;happy&amp;解析结果为2个：
key为9（实体引用事件），value为&
key为4（文本事件），value为happy&
```

开发者如果需要使用实体引用事件，需要至少使用API12，并在xml中严格遵从实体引用事件的格式，不在实体引用前加普通文本形成文本事件。
开发者如果不需要使用实体引用事件，在xml中实体引用前面加普通文本形成文本事件就行，或者自行适配回调函数。

实体引用事件说明：
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