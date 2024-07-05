# ArkData方舟数据管理变更说明

## cl.ArkData.1 ValueType增加类型

**访问级别**

公开接口。

**变更原因**

由于接口能力增强，ValueType需要增加类型。

**变更影响**

该变更为非兼容性变更，ValueType增加类型，导致getValue的返回值类型增加。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

变更之前，ValueType类型如下：
```
type ValueType = number | string | image.PixelMap | Want | ArrayBuffer
```

变更之后，ValueType类型如下：
```
type ValueType = number | string | image.PixelMap | Want | ArrayBuffer | boolean | object | undefined | null
```

**适配指导**

getValue接口使用的示例代码可参考[getValue](../../../application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#getvalue12)。