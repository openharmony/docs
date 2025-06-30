# 复用选项

reuse属性用于给\@ReusableV2装饰的自定义组件指定复用选项。

本文档仅为API参考说明。实际功能使用与限制见[@ReusableV2装饰器：组件复用](../../../ui/state-management/arkts-new-reusableV2.md)。

>  **说明：**
>
> 从API Version 18开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## reuse

reuse(options: ReuseOptions)

复用选项，用于设置V2自定义组件的复用选项。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                          | 必填 | 说明                                           |
| ------- | ----------------------------- | ---- | ---------------------------------------------- |
| options | [ReuseOptions](#reuseoptions) | 是   | 复用选项，用于配置复用相关信息，由开发者指定。 |

## ReuseOptions

复用选项信息。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### 属性

| 名称    | 类型                                | 必填 | 说明                                                         |
| ------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| reuseId | [ReuseIdCallback](#reuseidcallback) | 否   | 复用标识id，相同复用标识id的V2自定义组件会被互相复用。默认的复用标识id为自定义组件名。 |

## ReuseIdCallback

type ReuseIdCallback = () => string

获取复用标识id的回调方法。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 复用标识id，由开发者指定。<br>未指定或使用空字符串`''`作为复用标识id时，将默认使用自定义组件名。 |

## 示例

```ts
@Entry
@ComponentV2
struct Index {
  build() {
    Column() {
      ReusableV2Component()
        .reuse({reuseId: () => 'reuseComponent'}) // 使用'reuseComponent'作为reuseId
      ReusableV2Component()
        .reuse({reuseId: () => ''}) // 使用空字符串将默认使用组件名'ReusableV2Component'作为reuseId
      ReusableV2Component() // 未指定reuseId将默认使用组件名'ReusableV2Component'作为reuseId
    }
  }
}
@ReusableV2
@ComponentV2
struct ReusableV2Component {
  build() {
  }
}
```

