# ArkTS Subsystem Changelog

## cl.arkts.1 Behavior Changed for xml.XmlPullParser.parse in Parsing Entity Reference Events

**Access Level**

Public API

**Reason for Change**

When parsing an XML file, the **parse** interface identifies an entity reference event as a text event, and the parsed content is integrated into the text event. Consequently, the callback function specified in **tokenValueCallbackFunction** cannot obtain the parsing result of the entity reference event.

**Change Impact**

This change is a non-compatible change.

Before change: The XML information of an entity reference event is parsed into a text event. You cannot perform operations on the entity reference event in the callback function or determine whether the entity reference event exists based on the XML parsing result.

After change: In API version 12 or version, the XML information of an entity reference event is parsed as an entity reference event. You can perform operations on the entity reference event in the callback function or determine whether the entity reference event exists based on the XML parsing result.

**Start API Level**

API version 12

**Change Since**

OpenHarmony SDK 5.0.0.38

**Key API/Component Changes**

xml.XmlPullParser.parse

**Adaptation Guide**

If the XML file does not involve entity reference events, no adaptation is required.

If the XML file involves entity reference events, refer to the following example to learn the differences before and after the change. In the code snippet below, **strXml** stores the XML file to be parsed, and **func** is the callback function **tokenValueCallbackFunction**. Each event obtained upon a **parse** call triggers a callback, and the event type and XML parsing result are included in the callback.
```
let strXml = '<?xml version="1.0" encoding="utf-8"?>\n' +
                '<note>&amp;happy&amp;</note>';    // The first entity reference "&amp;" is an entity reference event, and the second entity reference "&amp;", together with its following "happy", is treated as a text event.
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
Before change:
```
The parsing result of &amp;happy&amp; is as follows:
key: 4 (text event); value: &happy&
```
After change:
```
The parsing results of &amp;happy&amp; are as follows:
key: 9 (entity reference event): value: &
key: 4 (text event); value: happy&
```

To use an entity reference event, use API version 12 or later and strictly comply with the entity reference event format in the XML file. Do not add regular text before the entity reference to form a text event.

If you do not need to use entity reference events, add regular text before the entity reference in the XML file to form a text event or write the callback function.

Entity reference events:

Currently, only the following entity reference events corresponding to the five predefined entities in the XML file are supported:

```
&lt;    <  less than
&gt;    >  greater than
&amp;   &  ampersand
&apos;  '  apostrophe
&quot;  "  quotation mark
```
In addition, if regular text exists before an entity reference, they are treated as a text event as a whole. 

Example:

```
<note>happy&lt;&gt;</note>: start tag event, text event, and end tag event in sequence.
<note>&lt;&gt;happy</note>: start tag event, entity reference event, entity reference event, text event, and end tag event in sequence.
```
