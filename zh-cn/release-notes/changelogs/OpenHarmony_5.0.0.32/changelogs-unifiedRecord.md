# UDMF统一数据对象变更说明

## cl.unifiedRecord.1 getValue返回值类型变更

**访问级别**

公开接口。

**变更原因**

由于接口能力增强，需要返回值变更。

**变更影响**

该变更为非兼容性变更，getValue的返回值类型ValueType增加boolean、object、undefined、null数据类型。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.32开始。

**变更的接口/组件**

变更之前，getValue接口的返回值类型ValueType如下：
```
type ValueType = number | string | image.PixelMap | Want | ArrayBuffer
```

变更之前，getValue接口的返回值类型ValueType如下：
```
type ValueType = number | string | image.PixelMap | Want | ArrayBuffer | boolean | object | undefined | null
```

**适配指导**

使用ValueType类型作为getValue接口的返回值。