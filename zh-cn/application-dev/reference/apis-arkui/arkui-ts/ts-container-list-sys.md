# List (系统接口)

列表包含一系列相同宽度的列表项。适合连续、多行呈现同类数据，例如图片和文本。

> **说明：**
>
> - 该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[List](ts-container-list.md)。

## 属性

### chainAnimationOptions<sup>10+</sup>

chainAnimationOptions(value: ChainAnimationOptions)

设置链式联动动效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 名称    | 参数类型                                     | 描述                           |
| ------ | ---------------------------------------- | ---------------------------------- |
| value  | [ChainAnimationOptions](#chainanimationoptions10对象说明) | 链式联动动效参数。|

## ChainEdgeEffect<sup>10+</sup>枚举说明

设置链式动效边缘效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      |  枚举值  | 描述                                       |
| ------- | ------ | ---------------------------------------- |
| DEFAULT | 0 | 默认效果，列表滚动到边缘以后继续拖动，拖拽方向上的列表项间距缩小，<br/>拖拽反方向上的列表项间距扩大。 |
| STRETCH | 1 | 列表滚动到边缘以后继续拖动，所有列表项间距扩大。                 |

## chainAnimationOptions<sup>10+</sup>对象说明

链式联动动效属性集合，用于设置List最大间距、最小间距、动效强度、传导系数和边缘效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型                                       | 必填   | 说明                                       |
| ------------ | ---------------------------------------- | ---- | ---------------------------------------- |
| minSpace     | [Length](ts-types.md#length)             | 是    | 设置链式联动动效最小间距。                            |
| maxSpace     | [Length](ts-types.md#length)             | 是    | 设置链式联动动效最大间距。                            |
| conductivity | number                                   | 否    | 设置链式联动动效传导系数。取值范围[0,1]，数值越大，动效传导范围越远。<br/>默认为0.7。 |
| intensity    | number                                   | 否    | 设置链式联动动效效果强度。取值范围[0,1]，数值越大，动效效果越明显。<br/>默认为0.3。 |
| edgeEffect   | [ChainEdgeEffect](#chainedgeeffect10枚举说明) | 否    | 设置链式联动动效边缘效果。<br/>默认为ChainEdgeEffect.DEFAULT。 |
| stiffness    | number                                   | 否    | 设置链式联动动效效果刚度。<br/>默认为228。 |
| damping      | number                                   | 否    | 设置链式联动动效效果阻尼。<br/>默认为30。 |

