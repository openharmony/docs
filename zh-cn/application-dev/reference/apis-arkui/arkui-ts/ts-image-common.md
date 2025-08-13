# 图像类型定义
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyujie43-->
<!--SE: @weixin_52725220-->
<!--TSE: @xiong0104-->

>**说明：**
>
>本模块首批接口从API version 12开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。


## ImageAnalyzerConfig

图像AI分析配置项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                | 只读 | 可选 | 说明                   |
| ------ | ----------------- | ---- | -------------------- | -------------------- |
| types | [ImageAnalyzerType[]](#imageanalyzertype) | 否 | 否 | 图像AI分析类型。|

## ImageAnalyzerType

图像AI分析类型，未设置时默认开启主体识别和文字识别功能。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 值    | 说明           |
| -------- | ----- | -------- |
| SUBJECT | 0  | 主体识别功能。 |
| TEXT | -  | 文字识别功能。 |
| OBJECT_LOOKUP | -  | 对象查找功能。 |

## ImageAIOptions

图像AI分析选项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                | 只读 | 可选 | 说明                   |
| ------ | ----------------- | ---- | -------------------- | -------------------- |
| types | [ImageAnalyzerType[]](#imageanalyzertype) | 否 | 是 | 图像AI分析类型。 |
| aiController | [ImageAnalyzerController](#imageanalyzercontroller) | 否 | 是 | 图像AI分析控制器。 |

> **说明：**
>
> 该特性中的参数types优先级高于[ImageAnalyzerConfig](#imageanalyzerconfig)中的参数types，两者同时设置时以该特性设置的值为准。
>
> 该特性依赖设备能力，且需要和对应组件的enableAnalyzer接口（例如[Image组件](ts-basic-components-image.md#enableanalyzer11)）搭配使用。

## ImageAnalyzerController

图像分析控制器。可以将此对象绑定至支持的组件，通过控制器来调用支持的方法。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### constructor

constructor()

构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### getImageAnalyzerSupportTypes

getImageAnalyzerSupportTypes(): ImageAnalyzerType[]

获取对应组件支持的分析类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值:**

| 类型     | 说明                      |
| ------ | ----------------------- |
| [ImageAnalyzerType[]](#imageanalyzertype) | 对应组件支持的分析类型。 |

