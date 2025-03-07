# ArkTS子系统变更说明

## cl.arkts.1 convertXml模块convertToJSObject接口对于连续的CDATA标签解析行为变更

**访问级别**

公开接口

**变更原因**

特定场景下，对于连续的CDATA标签数据进行解析时，会将连续两个CDATA数据错误地解析到同一个element中。

**变更影响**

修复BUG，将连续的CDATA标签的数据解析到不同的element中。

**起始 API Level**

9

**变更发生版本**

OpenHarmony SDK 5.0.0.19

**变更的接口/组件**

convertToJSObject(xml: string, options?: ConvertOptions): Object;

**适配指导**

```ts
let xml = '<?xml version="1.0" encoding="utf-8"?><![CDATA[ \t data\n]]><![CDATA[< > " and & \t ]]>';
let conv = new convertxml.ConvertXML();
let options = {trim : false, declarationKey:"_declaration",
               instructionKey : "_instruction", attributesKey : "_attributes",
               textKey : "_text", cdataKey:"_cdata", doctypeKey : "_doctype",
               commentKey : "_comment", parentKey : "_parent", typeKey : "_type",
               nameKey : "_name", elementsKey : "_elements"}
let result: ESObject = conv.convertToJSObject(xml, options);

// 变更前：
//let cdata = result._elements[0]._cdata;   // cdata 为 ' \\t data\\n< > \" and & \\t '

// 变更后
let cdata1 = result._elements[0]._cdata;    // cdata1 为 '\\t data\\n'
let cdata2 = result._elements[1]._cdata;    // cdata2 为 '< > \" and & \\t '
```

该问题修复后的主要表现为：将连续的CDATA标签的数据解析到不同的element中。

同时满足以下两个特定场景，开发者需要适配修改获取的_cdata数据：
1. 使用convertToJSObject进行解析xml数据。
2. xml数据中存在连续两个CDATA标签，且两个CDATA标签间没有空格、换行等字符的情况。
