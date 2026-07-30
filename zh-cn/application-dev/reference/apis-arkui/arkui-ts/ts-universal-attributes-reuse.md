# 复用选项

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

reuse属性用于给\@ReusableV2装饰的自定义组件指定复用选项。通过复用机制减少组件的重复创建与销毁开销，提升渲染性能，适用于列表滚动、页面滑动、频繁切换等场景。

本文档仅为API参考说明。实际功能使用与限制见[@ReusableV2装饰器：V2组件复用](../../../ui/state-management/arkts-new-reusableV2.md)。

>  **说明：**
>
> - 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## reuse

reuse(options: ReuseOptions): T

为\@ReusableV2装饰的V2自定义组件设置复用选项，相同复用标识ID的组件会被互相复用，提高复用匹配的精确度。

>  **说明：**
>
> 该接口不支持在[attributeModifier](ts-universal-attributes-attribute-modifier.md#attributemodifier)中调用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                          | 必填 | 说明                                           |
| ------- | ----------------------------- | ---- | ---------------------------------------------- |
| options | [ReuseOptions](#reuseoptions) | 是   | 复用选项，用于配置复用标识ID，由开发者指定。 |

**返回值：** 

| 类型                          | 说明                                           |
| ----------------------------|---------------------------------------------- |
|   T |   返回当前组件。 |

## ReuseOptions

复用选项，用于配置复用标识ID，相同复用标识ID的组件会被互相复用，提高复用匹配的精确度。

### 属性

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------- | ----------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| reuseId | [ReuseIdCallback](#reuseidcallback) | 否 | 是 | 复用标识ID，相同复用标识ID的V2自定义组件会被互相复用。默认的复用标识ID为自定义组件名。<br>在API版本26.0.0之前，当reuseId不是显式返回字符串字面量的回调方法时，实际的复用标识ID为该自定义组件的名称。例如，`Child().reuse({ reuseId: () => getReuseId() })`的实际复用标识ID为`"Child"`。<br>在API版本26.0.0及以后，支持将非显式返回字符串字面量形式的reuseId作为实际的复用标识ID。例如，`Child().reuse({ reuseId: () => getReuseId() })`的实际复用标识ID为`getReuseId()`的返回结果。 |

## ReuseIdCallback

type ReuseIdCallback = () => string

获取复用标识ID的回调方法。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 复用标识ID，由开发者指定。<br>未指定或使用空字符串`''`作为复用标识ID时，将默认使用自定义组件名。<br>在API版本26.0.0之前，当该回调不是显式返回字符串字面量时，实际复用标识ID将为自定义组件名，回调返回值不生效；在API版本26.0.0及以后，回调的实际返回结果将作为复用标识ID。 |

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
    Text('content')
  }
}
```
