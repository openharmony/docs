# @ohos.data.intelligence (智慧数据平台)

智慧数据平台（ArkData Intelligence Platform，AIP）提供端侧的数据智慧化能力，完成数据+AI智能在端侧闭环。作为端侧智慧化能力底座，将构建以下能力：
- 多模态嵌入模型：支持文字、图片多模态数据嵌入模型，由传统文本检索到多模态检索（PPT、图片、音频等）。
- 多模态数据存储：支持端侧向量、倒排索引等多模态数据存储，避免将原始数据发送到服务器进行处理，减少了数据泄露的风险。
- 知识检索：逐步构建语义索引、知识图谱、召回、重排等能力，支持用户知识的语义化检索。
- 知识生成与整理：基于用户文档、消息、电子邮件、照片、视频、日历事件、屏幕上下文等数据，支持高效数据整理与知识生成，实现数据到知识的转换。
- 能力开放：面向业务智慧化需求，结合数据与能力开放原则，从基础能力到知识库构建，逐步、逐层开放ArkData Intelligence Platform能力。

> **说明：**
>
> 本模块首批接口从API version 16开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { intelligence } from '@kit.ArkData';
```

## ModelConfig

管理嵌入模型的配置。


| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| version    | ModelVersion           | 是   |模型的版本。 |
| isNpuAvailable | boolean                | 是   | 指示是否使用 NPU。
| cachePath | string                | 否   | 如果使用 NPU 进行加速，则需要本地路径进行模型缓存。

## ModelVersion

模型版本枚举。


| 名称       | 说明                   |
| ---------- | ---------------------- |
| BASIC_MODEL     | 基本嵌入模型。   |

## TextEmbedding

描述多模态嵌入模型的文本嵌入函数。


| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| loadModel()    |       function     | 是   |加载嵌入模型。 |
| releaseModel() | function                | 是   | 释放嵌入模型。
| getEmbedding(text: string) | function                | 是   | 获取给定文本的嵌入向量。
| getEmbedding(batchTexts: Array&lt;string&gt;) | function                | 是   | 获取给定批次文本的嵌入向量。

## ImageEmbedding

描述多模态嵌入模型的图像嵌入功能。


| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| loadModel()    |       function     | 是   |加载嵌入模型。 |
| releaseModel() | function                | 是   | 释放嵌入模型。
| getEmbedding(image: Image) | function                | 是   | 获取给定图像的嵌入向量。

## Image

type Image = string;

表示string类型的数据。


| 类型                         | 说明                  |
| ---------------------------- | --------------------- |
| string; | 图像的类型的URI。 |

## SplitConfig

管理文本块进程配置。


| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| size    |       number     | 是   |块的最大大小。 |
| overlapRatio | number                | 是   | 相邻块之间的重叠比率。

## getTextEmbeddingModel

获取文本嵌入模型。


**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| config | [ModelConfig](#modelconfig) | 是   | 嵌入模型的配置 |

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| [TextEmbedding](#textembedding) | 多模态嵌入模型的文本嵌入函数 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |
| 801          | Capability not supported. |
| 31300000     | Inner error.                                                                                                                                    |

**示例：**

```ts
let textConfig = {
  version:1,
  isNpuAvailable:false,
  cachePath:"test"
}

AipService.getTextEmbeddingModel(textConfig)
  .then((data) => {
    console.info("get result success");
  })
  .catch((err) => {
    console.log("get result filed" + err.code);
  })

```

## getImageEmbeddingModel

获取图像嵌入模型。


**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| config | [ModelConfig](#modelconfig) | 是   | 嵌入模型的配置 |

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| [ImageEmbedding](#imageembedding) | 多模态嵌入模型的图像嵌入函数 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |
| 801          | Capability not supported. |
| 31300000     | Inner error.                                                                                                                                    |

**示例：**

```ts
let imageConfig = {
  version:1,
  isNpuAvailable:false,
  cachePath:"image"
}

AipService.getImageEmbeddingModel(imageConfig)
  .then((data) => {
    console.info("get result success");
  })
  .catch((err) => {
    console.log("get result filed" + err.code);
  })

```

## splitText

获取文本的分块。


**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| text | string | 是   | 用于分块的文本 |
| config | [SplitConfig](#splitconfig) | 是   | 文本分块的配置 |

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Array&lt;string&gt; | 返回结果的数组 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |
| 801          | Capability not supported. |
| 31300000     | Inner error.                                                                                                                                    |

**示例：**

```ts
let SplitConfig = {
  size:10,
  overlapRatio:0.1
}

let text = 'text';

AipService.splitText(text, SplitConfig)
  .then((data) => {
    console.info("get result success");
  })
  .catch((err) => {
    console.log("get result filed" + err.code);
  })

```