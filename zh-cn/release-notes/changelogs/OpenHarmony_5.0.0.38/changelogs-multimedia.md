## cl.multimedia.1 AVMetadata.hdrType 只读属性补齐

**访问级别**

公开接口。

**变更原因**

补充标记hdrType字段为readonly属性，对齐JsDoc描述。

**变更影响**

该变更为非兼容性变更。
若对AVMetadata.hdrType进行过赋值的代码，会在编译时报错。之前的版本虽然赋值成功，但无法生效。建议删除赋值的代码。

**起始 API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.38开始。

**变更的接口/组件**

|            接口声明            |               变更前                 |            变更后             |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| hdrType | 可赋值，不生效 | readonly, 不可赋值 |

**适配指导**

开发者需将使用@ohos.multimedia.media.d.ts模块中对AVMetadata.hdrType赋值的代码行删除。