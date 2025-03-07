# ArkData方舟数据管理变更说明

## cl.ArkData.1 ValueType增加类型

**访问级别**

公开接口。

**变更原因**

由于接口能力增强，ValueType需要增加类型。

**变更影响**

该变更为不兼容变更，ValueType增加类型，会导致getValue的返回值类型增加。当高低版本设备互通时，当高版本设备设置的数据类型为本次新增的类型时，由于低版本设备不支持新增的类型，会导致低版本设备上getValue失败。

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
type ValueType = number | string  | boolean | image.PixelMap | Want | ArrayBuffer | object | null | undefined
```

**适配指导**

getValue接口的使用可参考[getValue示例代码](../../../application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#getvalue12)。