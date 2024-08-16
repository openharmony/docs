# ArkTS Subsystem Changelog

## cl.arkts.1 Behavior of convertToJSObject of the convertXml Module Changed in Scenarios with Consecutive CDATA Tags

**Access Level**

Public API

**Reason for Change**

In specific scenarios, data with consecutive CDATA tags is incorrectly parsed into the same element.

**Change Impact**

The bug is fixed so that data with consecutive CDATA tags is parsed into different elements.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.19

**Key API/Component Changes**

convertToJSObject(xml: string, options?: ConvertOptions): Object;

**Adaptation Guide**

```ts
let xml = '<?xml version="1.0" encoding="utf-8"?><![CDATA[ \t data\n]]><![CDATA[< > " and & \t ]]>';
let conv = new convertxml.ConvertXML();
let options = {trim : false, declarationKey:"_declaration",
               instructionKey : "_instruction", attributesKey : "_attributes",
               textKey : "_text", cdataKey:"_cdata", doctypeKey : "_doctype",
               commentKey : "_comment", parentKey : "_parent", typeKey : "_type",
               nameKey : "_name", elementsKey : "_elements"}
let result: ESObject = conv.convertToJSObject(xml, options);

// Before change:
//let cdata = result._elements[0]._cdata; // cdata is' \\t data\\n< > \" and & \\t'.

// After change:
let cdata1 = result._elements[0]._cdata; // cdata1 is '\\t data\\n'
let cdata2 = result._elements[1]._cdata; // cdata2 is '< > \" and & \\t'.
```

Data with consecutive CDATA tags is parsed into different elements.

You need to make adaptation to the obtained **_cdata** when both of the following conditions are met:
1. **convertToJSObject** is used to parse XML data.
2. Two consecutive CDATA tags exist in the XML data, and there is no space or line feed character between the two CDATA tags.
