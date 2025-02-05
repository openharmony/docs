# @ohos.data.intelligence (智慧数据平台)

智慧数据平台（ArkData Intelligence Platform，AIP）提供端侧的数据智慧化能力，完成数据和AI智能在端侧闭环。作为端侧智慧化能力底座，将构建以下能力：
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

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| version    | [ModelVersion](#modelversion)           | 是   |模型的版本。 |
| isNpuAvailable | boolean                | 是   | 指示是否使用 NPU，true表示使用，false表示不使用。 |
| cachePath | string                | 否   | 如果使用 NPU 进行加速，则需要本地路径进行模型缓存。格式为/xxx/xxx/xxx/，长度上限为512 tokens。 |

## ModelVersion

模型版本枚举。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称       | 值                   | 说明                   |
| ---------- | ---------- | ---------------------- |
| BASIC_MODEL     | 0     | 基本嵌入模型版本。   |

## Image

type Image = string;

表示string类型的数据。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 类型                         | 说明                  |
| ---------------------------- | --------------------- |
| string | 图像的类型的URI地址。长度上限为512 tokens。 |

## SplitConfig

管理文本块进程配置。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| size    |       number     | 是   |块的最大大小，可取任意值。 |
| overlapRatio | number                | 是   | 相邻块之间的重叠比率。范围为0-1。 |


## intelligence.getTextEmbeddingModel

getTextEmbeddingModel(config: ModelConfig): Promise&lt;TextEmbedding&gt;

获取文本嵌入模型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| config | [ModelConfig](#modelconfig) | 是   | 嵌入模型的配置。 |

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;[TextEmbedding](#textembedding)&gt; | 返回TextEmbedding对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let config:intelligence.ModelConfig = {
  version:1,
  isNpuAvailable:false,
  cachePath:"test"
}
let textEmbedding:intelligence.TextEmbedding;

intelligence.getTextEmbeddingModel(config)
  .then((data:intelligence.TextEmbedding) => {
    console.info("get result success");
    textEmbedding = data;
  })
  .catch((err:BusinessError) => {
    console.error("get result filed" + err.code);
  })
```

## TextEmbedding

描述多模态嵌入模型的文本嵌入函数。

下列接口都需先使用[intelligence.getTextEmbeddingModel](#intelligencegettextembeddingmodel)获取到TextEmbedding实例，再通过此实例调用对应接口。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

### loadModel

loadModel(): Promise&lt;void&gt;

加载嵌入模型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textEmbedding.loadModel()
  .then(() => {
    console.info("load success");
  })
  .catch((err:BusinessError) => {
    console.error("load filed " + err.code);
  })
```

### releaseModel

releaseModel(): Promise&lt;void&gt;

释放嵌入模型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

textEmbedding.releaseModel()
  .then(() => {
    console.info("release success");
  })
  .catch((err:BusinessError) => {
    console.error("release filed " + err.code);
  })
```

### getEmbedding

getEmbedding(text: string): Promise&lt;Array&lt;number&gt;&gt;

获取给定文本的嵌入向量。

该接口需先调用[loadModel](#loadmodel)加载嵌入模型，加载成功后调用getEmbedding。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| text | string | 是   | 嵌入模型的输入文本。长度上限为512 tokens。 |

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | 返回向量化结果的数组对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';


textEmbedding.loadModel();
let text = 'text';
textEmbedding.getEmbedding(text)
  .then((data:Array&lt;number&gt;) => {
    console.info("getEmbedding success");
  })
  .catch((err:BusinessError) => {
    console.error("getEmbedding filed " + err.code);
  })
```

### getEmbedding

getEmbedding(batchTexts: Array&lt;string&gt;): Promise&lt;Array&lt;Array&lt;number&gt;&gt;&gt;

获取给定批次文本的嵌入向量。

该接口需先调用[loadModel](#loadmodel)加载嵌入模型，加载成功后调用getEmbedding。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| batchTexts | Array&lt;string&gt; | 是   | 嵌入模型的文本输入批次。单个文本长度上限为512 tokens。 |

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;Array&lt;number&gt;&gt;&gt; | 返回向量化结果的数组对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';


textEmbedding.loadModel();
let batchTexts = ['text1','text2'];
textEmbedding.getEmbedding(batchTexts)
  .then((data:Array&lt;Array&lt;number&gt;&gt;) => {
    console.info("getEmbedding success");
  })
  .catch((err:BusinessError) => {
    console.error("getEmbedding filed " + err.code);
  })
```

## intelligence.getImageEmbeddingModel

getImageEmbeddingModel(config: ModelConfig): Promise&lt;ImageEmbedding&gt;

获取图像嵌入模型。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| config | [ModelConfig](#modelconfig) | 是   | 嵌入模型的配置。 |

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;[ImageEmbedding](#imageembedding)&gt; | 返回ImageEmbedding对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let config:intelligence.ModelConfig = {
    version:1,
    isNpuAvailable:false,
    cachePath:"image"
   }
let imageembedding:intelligence.ImageEmbedding;

intelligence.getImageEmbeddingModel(config)
  .then((data:intelligence.ImageEmbedding) => {
    console.info("get result success");
    imageembedding = data;
  })
  .catch((err:BusinessError) => {
    console.error("get result filed" + err.code);
  })
```

## ImageEmbedding

描述多模态嵌入模型的图像嵌入函数。

下列接口都需先使用[intelligence.getImageEmbeddingModel](#intelligencegetimageembeddingmodel)获取到ImageEmbedding实例，再通过此实例调用对应接口。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

### loadModel

loadModel(): Promise&lt;void&gt;

加载嵌入模型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageembedding.loadModel()
  .then(() => {
    console.info("load success");
  })
  .catch((err:BusinessError) => {
    console.error("load filed " + err.code);
  })
```

### releaseModel

releaseModel(): Promise&lt;void&gt;

释放嵌入模型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageembedding.releaseModel()
  .then(() => {
    console.info("release success");
  })
  .catch((err:BusinessError) => {
    console.error("release filed " + err.code);
  })
```

### getEmbedding

getEmbedding(image: Image): Promise&lt;Array&lt;number&gt;&gt;

获取给定图像的嵌入向量。

该接口需先调用[loadModel](#loadmodel)加载嵌入模型，加载成功后调用。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| image | [Image](#image) | 是   | 嵌入模型的输入图像类型的URI地址。 |

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | 返回向量化结果的数组对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

imageembedding.loadModel();
let image = 'image uri';
textEmbedding.getEmbedding(image)
  .then((data:Array&lt;number&gt;) => {
    console.info("getEmbedding success");
  })
  .catch((err:BusinessError) => {
    console.error("getEmbedding filed " + err.code);
  })
```

## intelligence.splitText

splitText(text: string, config: SplitConfig): Promise&lt;Array&lt;string&gt;&gt;

获取文本的分块。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| text | string | 是   | 用于分块的文本，可取任意值。 |
| config | [SplitConfig](#splitconfig) | 是   | 文本分块的配置。 |

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | 返回分块结果的数组对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let config:intelligence.SplitConfig = {
  size:10,
  overlapRatio:0.1
}

let text = 'text';

intelligence.splitText(text, config)
  .then((data:Array&lt;string&gt;) => {
    console.info("get result success");
  })
  .catch((err:BusinessError) => {
    console.log("get result filed" + err.code);
  })
```