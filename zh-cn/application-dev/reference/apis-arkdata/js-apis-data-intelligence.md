# @ohos.data.intelligence (智慧数据平台)

智慧数据平台（ArkData Intelligence Platform，AIP）提供端侧的数据智慧化能力，完成数据和AI智能在端侧闭环。作为端侧智慧化能力底座，将构建以下能力：
- 多模态嵌入模型：使用嵌入模型（Embedding Model）对多模态数据生成向量表征，将文本、图片等数据映射到同一向量空间，支撑基于语义的多模态知识检索。
- 多模态数据存储：支持端侧向量、倒排索引等多模态数据存储，避免将原始数据发送到服务器进行处理，减少了数据泄露的风险。
- 知识检索：逐步构建语义索引、知识图谱、召回、重排等能力，支持用户知识的语义化检索。
- 知识生成与整理：基于用户文档、消息、电子邮件、照片、视频、日历事件、屏幕上下文等数据，支持高效数据整理与知识生成，实现数据到知识的转换。

> **说明：**
>
> 本模块首批接口从API version 15开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 考虑到数据向量化处理的计算量和资源占用较大，当前仅支持在2in1设备上使用。


## 导入模块

```ts
import { intelligence } from '@kit.ArkData';
```

## intelligence.getTextEmbeddingModel

getTextEmbeddingModel(config: ModelConfig): Promise&lt;TextEmbedding&gt;

获取文本嵌入模型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| config | [ModelConfig](#modelconfig) | 是   | 嵌入模型的配置信息。 |

**返回值：**

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;[TextEmbedding](#textembedding)&gt; | Promise对象，返回文本嵌入模型对象。 |

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

let textConfig:intelligence.ModelConfig = {
  version:intelligence.ModelVersion.BASIC_MODEL,
  isNpuAvailable:false,
  cachePath:"/data"
}
let textEmbedding:intelligence.TextEmbedding;

intelligence.getTextEmbeddingModel(textConfig)
  .then((data:intelligence.TextEmbedding) => {
    console.info("Succeeded in getting TextModel");
    textEmbedding = data;
  })
  .catch((err:BusinessError) => {
    console.error("Failed to get TextModel and code is " + err.code);
  })
```

## intelligence.getImageEmbeddingModel

getImageEmbeddingModel(config: ModelConfig): Promise&lt;ImageEmbedding&gt;

获取图像嵌入模型。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| config | [ModelConfig](#modelconfig) | 是   | 嵌入模型的配置信息。 |

**返回值：**

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;[ImageEmbedding](#imageembedding)&gt; | Promise对象，返回图像嵌入模型对象。 |

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

let imageConfig:intelligence.ModelConfig = {
    version:intelligence.ModelVersion.BASIC_MODEL,
    isNpuAvailable:false,
    cachePath:"/data"
}
let imageEmbedding:intelligence.ImageEmbedding;

intelligence.getImageEmbeddingModel(imageConfig)
  .then((data:intelligence.ImageEmbedding) => {
    console.info("Succeeded in getting ImageModel");
    imageEmbedding = data;
  })
  .catch((err:BusinessError) => {
    console.error("Failed to get ImageModel and code is " + err.code);
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
| config | [SplitConfig](#splitconfig) | 是   | 文本分块的配置信息。 |

**返回值：**

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回分块结果的数组对象。 |

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

let splitConfig:intelligence.SplitConfig = {
  size:10,
  overlapRatio:0.1
}
let splitText = 'text';

intelligence.splitText(splitText, splitConfig)
  .then((data:Array<string>) => {
    console.info("Succeeded in splitting Text");
  })
  .catch((err:BusinessError) => {
    console.error("Failed to split Text and code is " + err.code);
  })
```

## intelligence.getRetriever<sup>18+</sup>

getRetriever(config: RetrievalConfig): Promise&lt;Retriever&gt;

创建并获取检索器，进行多路检索召回。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| config | [RetrievalConfig](#retrievalconfig18) | 是   | 检索器的配置信息。 |

**返回值：**

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;[Retriever](#retriever18)&gt; | Promise对象，返回检索器对象。 |


**示例：**

```ts
import {intelligence} from '@kit.ArkData';
import relationalStore from '@ohos.data.relationalStore';
import { BusinessError } from '@ohos.base';

@Entry
@Component
struct Page {
    async retrieve() {
        let vectorDBConfig:intelligence.DbConfig = {
            name:"vector_store_test.db",
            securityLevel:relationalStore.SecurityLevel.S3
        }
        
        let invidxDBConfig:intelligence.DbConfig = {
            name:"invidx_store_test.db",
            securityLevel:relationalStore.SecurityLevel.S3
        }
        let context: Context | undefined = this.getUIContext().getHostContext();
        if (context == undefined) {
          console.info("getHostContext failed.");
          return;
        }
        let channelConfigVector:intelligence.ChannelConfig = {
            channelType:intelligence.ChannelType.VECTOR_DATABASE,
            context:context,
            dbConfig:vectorDBConfig
        }
        
        let channelConfigInvIdx:intelligence.ChannelConfig = {
            channelType:intelligence.ChannelType.INVERTED_INDEX_DATABASE,
            context:context,
            dbConfig:invidxDBConfig
        }
        
        let retrievalConfig:intelligence.RetrievalConfig = {
            channelConfigs:[channelConfigInvIdx, channelConfigVector]
        }
        
        let globalRetriever:intelligence.Retriever | undefined;
        // 获取检索器
        await intelligence.getRetriever(retrievalConfig)
        .then((retriever:intelligence.Retriever) => {
            globalRetriever = retriever;
            console.info("globalRetriever is success");
        })
        .catch((err:BusinessError) => {
            globalRetriever = undefined;
            console.error("Failed to get Retriever and code is " + err.code);
        })
    }

    build() {
    }
}

```


## ModelConfig

管理嵌入模型的配置信息。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| version    | [ModelVersion](#modelversion)           | 是   |模型的版本。 |
| isNpuAvailable | boolean                | 是   | 指示是否使用NPU加速向量化过程，true表示使用，false表示不使用。如果设备不支持NPU，调用加载模型会失败，并抛出错误码31300000。 |
| cachePath | string                | 否   | 如果使用NPU进行加速，则需要本地路径进行模型缓存。格式为/xxx/xxx/xxx，xxx为路径地址，例如"/data"。长度上限为512个字符。默认值为""。 |

## ModelVersion

模型版本枚举。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称       | 值                   | 说明                   |
| ---------- | ---------- | ---------------------- |
| BASIC_MODEL     | 0     | 基本嵌入模型版本。   |

## Image

type Image = string

图片的URI地址，对应为string类型。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型                         | 说明                  |
| ---------------------------- | --------------------- |
| string | 图片的URI地址。长度上限为512个字符。 |

## SplitConfig

管理文本分块的配置信息。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| size    |       number     | 是   |分块的最大大小，取值为非负整数。 |
| overlapRatio | number                | 是   | 相邻分块之间的重叠比率。范围为[0,1]，0表示重叠比率最低，1表示重叠比率最高。 |


## TextEmbedding

描述多模态嵌入模型的文本嵌入函数。

下列接口都需先使用[intelligence.getTextEmbeddingModel](#intelligencegettextembeddingmodel)获取到TextEmbedding实例，再通过此实例调用对应接口。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

### loadModel

loadModel(): Promise&lt;void&gt;

加载嵌入模型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值：**

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
    console.info("Succeeded in loading Model");
  })
  .catch((err:BusinessError) => {
    console.error("Failed to load Model and code is " + err.code);
  })
```

### releaseModel

releaseModel(): Promise&lt;void&gt;

释放嵌入模型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值：**

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
    console.info("Succeeded in releasing Model");
  })
  .catch((err:BusinessError) => {
    console.error("Failed to release Model and code is " + err.code);
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
| text | string | 是   | 嵌入模型的输入文本。长度上限为512个字符。 |

**返回值：**

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise对象，返回向量化结果的数组对象。 |

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
  .then((data:Array<number>) => {
    console.info("Succeeded in getting Embedding");
  })
  .catch((err:BusinessError) => {
    console.error("Failed to get Embedding and code is " + err.code);
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
| batchTexts | Array&lt;string&gt; | 是   | 嵌入模型的文本输入批次。单个文本长度上限为512个字符。 |

**返回值：**

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;Array&lt;number&gt;&gt;&gt; | Promise对象，返回向量化结果的数组对象。 |

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
  .then((data:Array<Array<number>>) => {
    console.info("Succeeded in getting Embedding");
  })
  .catch((err:BusinessError) => {
    console.error("Failed to get Embedding and code is " + err.code);
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

**返回值：**

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

imageEmbedding.loadModel()
  .then(() => {
    console.info("Succeeded in loading Model");
  })
  .catch((err:BusinessError) => {
    console.error("Failed to load Model and code is " + err.code);
  })
```

### releaseModel

releaseModel(): Promise&lt;void&gt;

释放嵌入模型，使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**返回值：**

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

imageEmbedding.releaseModel()
  .then(() => {
    console.info("Succeeded in releasing Model");
  })
  .catch((err:BusinessError) => {
    console.error("Failed to release Model and code is " + err.code);
  })
```

### getEmbedding

getEmbedding(image: Image): Promise&lt;Array&lt;number&gt;&gt;

获取给定图像的嵌入向量。

该接口需先调用[loadModel](#loadmodel)加载嵌入模型，加载成功后调用getEmbedding。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| image | [Image](#image) | 是   | 嵌入模型的输入图像类型的URI地址。 |

**返回值：**

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise对象，返回向量化结果的数组对象。 |

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

imageEmbedding.loadModel();
let image = 'file://<packageName>/data/storage/el2/base/haps/entry/files/xxx.jpg';
imageEmbedding.getEmbedding(image)
  .then((data:Array<number>) => {
    console.info("Succeeded in getting Embedding");
  })
  .catch((err:BusinessError) => {
    console.error("Failed to get Embedding and code is " + err.code);
  })
```


## RetrievalConfig<sup>18+</sup>

管理检索器的配置信息。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| channelConfigs    | Array&lt;[ChannelConfig](#channelconfig18)&gt;           | 是   | 不同检索回路的配置信息数组。 |



## ChannelConfig<sup>18+</sup>

管理每个检索回路的配置信息。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| channelType    | [ChannelType](#channeltype18)           | 是   | 当前检索回路的数据库类型。 |
| context    | Context           | 是   | 应用的上下文。 <br>FA模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。<br>Stage模型的应用Context定义见[Context](../apis-ability-kit/js-apis-inner-app-context.md)。 |
| dbConfig    | [DbConfig](#dbconfig18)           | 是   | 当前检索回路的数据库配置。 |


## ChannelType<sup>18+</sup>

数据库类型枚举。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 值    | 说明              |
| ---------- | ----------| --------------------- |
| VECTOR_DATABASE   | 0      | 向量数据库。           |
| INVERTED_INDEX_DATABASE    | 1      | 倒排数据库，基于RDB。         |

## DbConfig<sup>18+</sup>

type DbConfig = relationalStore.StoreConfig

数据库配置。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 类型               | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| [relationalStore.StoreConfig](js-apis-data-relationalStore.md#storeconfig)         | 数据库配置。 |
 
## Retriever<sup>18+</sup>

检索器，用于多路检索召回。

下列接口都需先使用[intelligence.getRetriever](#intelligencegetretriever18)获取到检索器实例，再通过此实例调用对应接口。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

### retrieveRdb<sup>18+</sup>

retrieveRdb(query: string, condition: RetrievalCondition): Promise&lt;RdbRecords&gt;

给定检索条件（包含查询词分词、召回条件），从一个关系型数据库检索召回满足条件的数据。使用Promise异步回调。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| query | string | 是   | 当前检索的查询词。 |
| condition | [RetrievalCondition](#retrievalcondition18) | 是   | 检索条件。 |

**返回值：**

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| Promise&lt;[RdbRecords](#rdbrecords18)&gt; | Promise对象，返回检索召回数据。 |

**错误码：**

以下错误码的详细介绍请参见[智慧数据平台错误码](errorcode-intelligence.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 31300001     | Database corrupted. |
| 31300002     | Already closed. |
| 31300003     | The database is busy. |
| 31300004     | SQLite: The database is out of memory. |
| 31300100     | SQLite: Generic error. |
| 31300101     | SQLite: Access permission denied. |
| 31300102     | SQLite: The database file is locked. |
| 31300103     | SQLite: Some kind of disk I/O error occurred. |
| 31300104     | SQLite: The WAL file size exceeds the default limit. |
| 31300105     | SQLite: Unable to open the database file. |
| 31301000     | Retrieval: An error occurred during the reacll phase. |
| 31301001     | Retrieval: An error occurred during the re-ranking phase. |
| 31301002     | Retrieval: The value of the numerical parameter is outside the constrained range. |
| 31301003     | Retrieval: There are invalid primary keys. |
| 31301004     | Retrieval: A re-ranking algorithm that does not support composite primary keys was used. |
| 31301005     | Retrieval: There are fields with empty strings. |
| 31301006     | Retrieval: The filter input is invalid. |
| 31301007     | Retrieval: There are invalid recall names in RecallCondition. |
| 31301008     | Retrieval: The vector similarity threshold in VectorQuery is higher than the tiered threshold in VectorRerankParameter. |
| 31301009     | Retrieval: RerankMethod parameters do not match the channel type. |
| 31301010     | Retrieval: There exists a parameter value that should not be empty but is actually empty |


**示例：**

```ts
import {intelligence} from '@kit.ArkData';
import relationalStore from '@ohos.data.relationalStore';
import { BusinessError } from '@ohos.base';

@Entry
@Component
struct Page {
    async retrieve() {
        let vectorDBConfig:intelligence.DbConfig = {
            name:"vector_store_test.db",
            securityLevel:relationalStore.SecurityLevel.S3
        }
        
        let invidxDBConfig:intelligence.DbConfig = {
            name:"invidx_store_test.db",
            securityLevel:relationalStore.SecurityLevel.S3
        }
        let context: Context | undefined = this.getUIContext().getHostContext();
        if (context == undefined) {
          console.info("getHostContext failed.");
          return;
        }
        let channelConfigVector:intelligence.ChannelConfig = {
            channelType:intelligence.ChannelType.VECTOR_DATABASE,
            context:context,
            dbConfig:vectorDBConfig
        }
        
        let channelConfigInvIdx:intelligence.ChannelConfig = {
            channelType:intelligence.ChannelType.INVERTED_INDEX_DATABASE,
            context:context,
            dbConfig:invidxDBConfig
        }
        
        let retrievalConfig:intelligence.RetrievalConfig = {
            channelConfigs:[channelConfigInvIdx, channelConfigVector]
        }
        
        let globalRetriever:intelligence.Retriever | undefined;
        await intelligence.getRetriever(retrievalConfig)
        .then((retriever:intelligence.Retriever) => {
            globalRetriever = retriever;
            console.info("globalRetriever is success");
        })
        .catch((err:BusinessError) => {
            globalRetriever = undefined;
            console.error("Failed to get Retriever and code is " + err.code);
        })
        let fieldWeight:Record<string, number> = {
            "filename":4.0
        }

        let fieldSlops:Record<string, number> = {
            "filename":5
        }

        let bm25Strategy:intelligence.Bm25Strategy = {
            bm25Weight:1.5,
            columnWeight:fieldWeight
        }

        let exactStrategy:intelligence.ExactMatchingStrategy = {
            exactMatchingWeight:1.2,
            columnWeight:fieldWeight
        }

        let outOfOrderStrategy:intelligence.ProximityStrategy = {
            proximityWeight:1.2,
            columnWeight:fieldWeight,
            columnSlops:fieldSlops
        }

        let invertedIndexStrategies:Array<intelligence.InvertedIndexStrategy> = [bm25Strategy, exactStrategy, outOfOrderStrategy]

        let filters:Array<intelligence.FilterInfo> = [
          {
            columns:["filename"],
            operator:intelligence.Operator.OP_NE,
            filterValue."'大模型时代'"
          }
        ]

        let recallConditionInvIdx:intelligence.InvertedIndexRecallCondition ={
            ftsTableName:"invidx_table",
            primaryKey:["fileid"],
            fromClause:"invidx_table",
            responseColumns:["filename", "keywords"],
            deepSize:500,
            invertedIndexStrategies:invertedIndexStrategies,
            recallName:"invIdxRecall",
            filters:filters
        }

        // 这里 floatArray 时输入的 query 的表征向量，根据实际情况需要修改
        let floatArray = new Float32Array(128).fill(0.1);
        let vectorQuery:intelligence.VectorQuery = {
            column:"filename",
            value:floatArray,
            similarityThreshold:0.2
        }

        let recallConditionVector:intelligence.VectorRecallCondition = {
            vectorQuery:vectorQuery,
            fromClause:"vector_table",
            primaryKey:["fileid"],
            responseColumns:["filename_text", "keywords_text"],
            recallName:"vectorRecall",
            deepSize:500
        }

        let vectorWeights:Record<string, number> = {
            "vectorRecall":0.4
        }

        let invidxWeights:Record<string, number> = {
            "vectorRecall":0.6
        }

        let numberInspector:Record<intelligence.RecallName, intelligence.ColumnName> = {
            "vectorRecall":"filename"
        }

        let vectorRerankParameter:intelligence.VectorRerankParameter = {
            vectorWeights:vectorWeights,
            thresholds:[0.4, 0.3],
            numberInspector:numberInspector
        }

        let invidxRerankParameter:intelligence.InvertedIndexRerankParameter = {
            invertedIndexWeights:invidxWeights,
        }

        let parameters:Record<intelligence.ChannelType, intelligence.RerankParameter> = {
            0:vectorRerankParameter,
            1:invidxRerankParameter
        }

        let rerankMethod:intelligence.RerankMethod = {
            rerankType:intelligence.RerankType.RRF,
            parameters:parameters,
            isSoftmaxNormalized:true
        }

        let retrievalCondition:intelligence.RetrievalCondition = {
            rerankMethod:rerankMethod,
            recallConditions:[recallConditionInvIdx, recallConditionVector],
            resultCount:5
        } 

        if (globalRetriever != undefined) {
            let query:string = "大模型";
            // 执行检索
            globalRetriever.retrieveRdb(query, retrievalCondition)
            .then((rdbdata:intelligence.RdbRecords) => {
                for (let i = 0; i < rdbdata.records.length; i++) {
                    let itemInfo = rdbdata.records[i];
                    console.info(`primaryKey is ${itemInfo.primaryKey}`);
                }
                console.info("retrieval success.");
            })
            .catch((err:BusinessError) => {
                console.error("Failure in retrieveRdb and code is " + err.code);
            })
        }
    }

    build() {
    }
}
```

## RetrievalCondition<sup>18+</sup>

检索条件。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| recallConditions    |   Array&lt;[RecallCondition](#recallcondition18)&gt;       | 是   | 召回的条件，数组中的每个元素对应一个召回操作。 |
| rerankMethod    |  [RerankMethod](#rerankmethod18)         | 否   | 重排方法。其参数rerankType默认值为RRF算法，参数parameters默认值遵循[RecallCondition](#recallcondition18)中相应检索回路的参数。 |
| resultCount    | number         | 否   | 重排后允许返回结果的最大数量。默认值为500。必须为正整数。 |


## Recallcondition<sup>18+</sup>

type RecallCondition = InvertedIndexRecallCondition | VectorRecallCondition

召回操作的条件。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 类型               | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| [InvertedIndexRecallCondition](#invertedindexrecallcondition18)         | 倒排召回条件。 |
| [VectorRecallCondition](#vectorrecallcondition18)         | 向量召回条件。 |


## InvertedIndexRecallCondition<sup>18+</sup>

倒排检索的召回条件。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| ftsTableName    | string         | 是   | 倒排检索所用的fts(Full-Text Search)数据表的名称，用于执行bm25函数输入。必须为存在的表名且不能为空字符串。 |
| fromClause   | string         | 是   | 查询目标索引名。不能为空字符串。<br>注：fromClause指定的表中包含filters中涉及的所有字段，接受两种输入：1. 和ftsTableName填一样的值，则倒排检索将仅局限在倒排表内进行检索；2. 提供完整select...join语句的方式，来连接fts表之外的元素表，作为倒排这一路的被检索表（注意，使用此模式时，该select语句中必须有rowid字段且必须定义为fts表的rowid，例如当ftsTableName为“files”时，存在一个元素表metadata需要参与filters过滤，则应如下定义fromClause："SELECT files.rowid as rowid, * FROM metadata JOIN files ON metadata.fileid = files.fileid"。）。 |
| primaryKey    | Array&lt;[ColumnName](#columnname18)&gt;         | 是   | 召回结果主键字段，会作为召回字段之一，作为多路召回文档聚合依据。一次查询中所有召回操作的主键字段数量必须相等且不能为空。 |
| responseColumns    | Array&lt;[ColumnName](#columnname18)&gt;         | 是   | 需要额外召回的字段集合。ColumnName不得为空 |
| invertedIndexStrategies    | Array&lt;[InvertedIndexStrategy](#invertedindexstrategy18)&gt;         | 否   | 召回策略列表，决定了倒排表应当如何打分。如果为空，则默认执行全表匹配。 |
| recallName    | [RecallName](#recallname18)         | 否   | 当前检索回路的名称，作为重排阶段识别依据。默认值为随机字符串，不能为空字符串。 |
| filters    | Array&lt;[FilterInfo](#filterinfo18)&gt;         | 否   | 附加的过滤条件。 |
| deepSize    | number         | 否   | 重排阶段包含当前召回过程的最大结果数。默认值500，必须为正整数。 |


## ColumnName<sup>18+</sup>

type ColumnName = string

数据表的列名，类型为字符串。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 类型               | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| string         | 数据表列名对应的类型，为字符串类型可取任意值。 |


## RecallName<sup>18+</sup>

type RecallName = string

召回回路名称，类型为字符串，用于给倒排和向量两路召回取名。例如出现两路向量召回时，给两路向量取名做区分。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 类型               | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| string         | 召回路径名称对应的类型，类型为字符串，可取任意值。 |


## FilterInfo<sup>18+</sup>

过滤器信息。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| columns     | Array&lt;[ColumnName](#columnname18)&gt;        | 是   | 被过滤的列名称。 |
| operator     | [Operator](#operator18)         | 否   | 过滤条件中的操作算子。operator和filterValue、operator和filterRange至少有一组同时设置，过滤功能才能生效。 |
| filterValue     | [FilterValue](#filtervalue18)         |否   | 过滤条件中的过滤值。 |
| filterRange     | [FilterRange](#filterrange18)         | 否   | 过滤条件中的过滤范围。 |


## FilterValue<sup>18+</sup>

type FilterValue =  number | string | bigint

过滤条件中的过滤值。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 类型               | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| number         | 值类型为数字，可取任意值。 |
| string         | 值类型为字符串，可取任意值。 |
| bigint         | 值类型为int64，可取任意值。 |


## FilterRange<sup>18+</sup>

过滤条件中的过滤值范围。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| max     | number         | 是   | 最大过滤值。 |
| min     | number         | 是   | 最小过滤值，取值需小于最大过滤值。 |

## Operator<sup>18+</sup>

过滤条件中的操作算子。column为数据库表中的字段名，filterValue为该字段的取值。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 操作     | 说明                                                         |
| ---------- | ------------------------------------------------------------ |
| OP_EQ = '='        | &lt;column&gt;等于&lt;filterValue&gt;。 |
| OP_NE = '!='        | &lt;column&gt;不等于&lt;filterValue&gt;。 |
| OP_LT = '<'        | &lt;column&gt;小于&lt;filterValue&gt;，其中&lt;filterValue&gt;为数值。 |
| OP_LE = '<='        | &lt;column&gt;小于等于&lt;filterValue&gt;，其中&lt;filterValue&gt;为数值。 |
| OP_GT = '>'        | &lt;column&gt;大于&lt;filterValue&gt;，其中&lt;filterValue&gt;为数值。 |
| OP_GE = '>='        | &lt;column&gt;大于等于&lt;filterValue&gt;，其中&lt;filterValue&gt;为数值。 |
| OP_IN = 'IN'        | &lt;column&gt; IN &lt;filterValue&gt;，其中&lt;filterValue&gt;为string且通过','组合。 |
| OP_NOT_IN = 'NOT_IN'        | &lt;column&gt; NOT IN &lt;filterValue&gt;，其中&lt;filterValue&gt;为string且通过','拼接。 |
| OP_BETWEEN = 'BETWEEN'        | &lt;column&gt; BETWEEN &lt;filterRange.min&gt; AND &lt;filterRange.max&gt;。 |
| OP_LIKE = 'LIKE'        | &lt;column&gt; LIKE &lt;filterValue&gt;，其中&lt;filterValue&gt;为string。 |
| OP_NOT_LIKE = 'NOT_LIKE'        | &lt;column&gt; NOT LIKE &lt;filterValue&gt;，其中&lt;filterValue&gt;为string。 |

## InvertedIndexStrategy<sup>18+</sup>

type InvertedIndexStrategy = Bm25Strategy | ExactMatchingStrategy | ProximityStrategy

倒排召回策略。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core


| 类型               | 说明                                                         |
| --------------------- | ------------------------------------------------------------ |
| [Bm25Strategy](#bm25strategy18)         | Bm25Strategy策略。 |
| [ExactMatchingStrategy](#exactmatchingstrategy18)         | ExactMatchingStrategy策略。 |
| [ProximityStrategy](#proximitystrategy18)         | ProximityStrategy策略。 |

## Bm25Strategy<sup>18+</sup>

倒排检索所用的bm25策略。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| bm25Weight     | number         | 是   | 策略的打分权重。必须为非负数。 |
| columnWeight     | Record&lt;[ColumnName](#columnname18), number&gt;         | 否   | bm25策略涉及字段，以及字段对应的权重。如果字段为空，则增加1个配置，字段名为ftsTableName，权重值为1.0。如果不为空，则字段名不为空字符串，权重值为非负数。 |


## ExactMatchingStrategy<sup>18+</sup>

倒排检索所用的精确场景匹配策略。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| exactMatchingWeight     | number         | 是   | 策略的打分权重。必须为非负数。 |
| columnWeight     | Record&lt;[ColumnName](#columnname18), number&gt;         | 否   | 策略涉及字段，以及字段对应的权重。如果为空，则增加1个配置，字段名为ftsTableName，权重值为1.0。如果不为空，则字段名不能为空字符串，权重值为非负数。  |

## ProximityStrategy<sup>18+</sup>

倒排检索所用的近似与乱序匹配策略。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| proximityWeight     | number         | 是   | 策略的打分权重。必须为非负数。 |
| columnWeight     | Record&lt;[ColumnName](#columnname18), number&gt;         | 否   | 策略涉及字段，以及字段对应的权重。如果为空，则增加1个配置，字段名为ftsTableName，权重值为1.0。如果不为空，则字段名不能为空字符串，权重值为非负数。  |
| columnSlops     | Record&lt;[ColumnName](#columnname18), number&gt;         | 否   | 每个字段使用的偏移量配置。默认值为和columnWeight相同的字段，值为10。字段不能为空，对应值必须为非负数。 |


## VectorRecallCondition<sup>18+</sup>

向量检索的召回条件。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| query    | [VectorQuery](#vectorquery18)         | 是   | 用于向量检索的查询词向量。 |
| fromClause    | string         | 是   |  查询目标索引名。不能为空字符串。<br>注：fromClause指定的表中包含filters中涉及的所有字段，接受两种输入：1. 和ftsTableName填一样的值，则倒排检索将仅局限在倒排表内进行检索；2. 提供完整select...join语句的方式，来连接fts表之外的元素表，作为倒排这一路的被检索表（注意，使用此模式时，该select语句中必须有rowid字段且必须定义为fts表的rowid，例如当ftsTableName为“files”时，存在一个元素表metadata需要参与filters过滤，则应如下定义fromClause："SELECT files.rowid as rowid, * FROM metadata JOIN files ON metadata.fileid = files.fileid"。）。 |
| primaryKey    | Array&lt;[ColumnName](#columnname18)&gt;         | 是   | 召回结果主键字段，会作为召回字段之一，作为多路召回文档聚合依据。一次查询中所有RecallCondition的主键字段数量必须相等且不能为空。 |
| responseColumns    | Array&lt;[ColumnName](#columnname18)&gt;      | 是   | 需要额外召回的字段集合。ColumnName不得为空。 |
| recallName    | [RecallName](#recallname18)         | 否   | 当前检索回路的名称，作为重排阶段识别依据。默认值为随机字符串，不能为空字符串。 |
| filters    | Array&lt;[FilterInfo](#filterinfo18)&gt;        | 否   | 额外的过滤条件。 |
| deepSize    | number       | 否   | 当前召回过程给重排阶段返回的最大结果数。默认值500，必须为正整数。 |


## VectorQuery<sup>18+</sup>

根据查询词生成的向量。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| column    | [ColumnName](#columnname18)         | 是   | 待匹配向量字段名。必须为指定的向量数据库中存在的向量类型字段。 |
| value    | Float32Array         | 是   | 向量列的向量值。 |
| similarityThreshold    | number         | 否   | 向量阈值，用于过滤不相似向量的阈值。默认值为1，取值范围最小值为0，最大值为[VectorRerankParameter](#vectorrerankparameter18)中有效thresholds的最小值。 |


## RerankMethod<sup>18+</sup>

重排策略的参数。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| rerankType    | [RerankType](#reranktype18)         | 是   | 重排算法，取值类型为枚举类[RerankType](#reranktype18)，可选项为RRF、FUSED_SCORE，分别指向rrf排序算法以及分数融合排序算法。默认值为RRF。 |
| parameters    | Record&lt;[ChannelType](#channeltype18), [RerankParameter](#rerankparameter18)&gt;         | 否   | 每个召回回路对应的重排参数。如果上述检索参数RetrievalCondition中的存在的channelType未在parameters中配置重排参数，则会自动填充该channelType对应的重排参数默认值。倒排的重排参数默认值参考[InvertedIndexRerankParameter](#invertedindexrerankparameter18)，向量的重排参数默认值参考[VectorRerankParameter](#vectorrerankparameter18)。   |
| isSoftmaxNormalized    | boolean         | 否   | FUSED_SCORE模式下，是否使用softmax函数归一化计算重排最终得分。默认为false。true表示使用softmax函数归一化计算重排最终得分，false表示不使用。 |


## RerankType<sup>18+</sup>

重排算法的类型。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 类型     | 值    | 说明                                                         |
| ---------- | ----------| ------------------------------------------------------------ |
| RRF        | 0      | Reciprocal Rank Fusion(RRF)方法。根据各路召回位置信息进行分档排序。适用场景：对结果多样性要求较高的场景，希望每路结果平等输出。 |
| FUSION_SCORE        | 1      | 基于得分的召回融合方法。根据各路相关性分数进行分档排序。适用场景：对相关性准确性要求高、召回分数可靠且注重结果的排序稳定性的场景。 |


## RerankParameter<sup>18+</sup>

type RerankParameter = InvertedIndexRerankParameter| VectorRerankParameter

重排算法的参数配置。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 类型                         | 说明                  |
| ---------------------------- | --------------------- |
| [InvertedIndexRerankParameter](#invertedindexrerankparameter18) | 重排参数为InvertedIndexRerankParameter。 |
| [VectorRerankParameter](#vectorrerankparameter18) | 重排参数为VectorRerankParameter。 |

## InvertedIndexRerankParameter<sup>18+</sup>

用于倒排索引的重排算法的参数。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| invertedIndexWeights    | Record&lt;[RecallName](#recallname18), number&gt;         | 是   | 每路召回的重排权重，体现各路召回在重排过程中的重要性。key为各路召回RecallCondition的recallName，value为对应那一路召回的权重。权重值必须为非负数。如果未定义某一路召回的权重，则默认值为1。 |



## VectorRerankParameter<sup>18+</sup>

用于向量数据的重排算法的参数。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| vectorWeights    | Record&lt;[RecallName](#recallname18), number&gt;         | 是   | 每路召回的重排权重，体现各路召回在重排过程中的重要性。key为各路召回RecallCondition的recallName，value为对应那一路召回的权重。权重值必须为非负数。如果未定义某一路召回的权重，则默认值为1。 |
| thresholds    | Array&lt;number&gt;         | 否   | 向量召回的分档阈值，用户应当从[0, 1]范围内给3个值，高、中、低档最低分，赋值对应cosine()相似度得分，越高越相关；如果是2个值，则分出高、中两档，剩下结果都是低档；如果是1个值，则除了高档剩下结果都是低档。当给出多于3个值，则使用从大到小排序后前3个数值，后面忽略。如果未定义，默认值为[0.6, 0.45, 0.4]。 |
| numberInspector    | Record&lt;[RecallName](#recallname18), [ColumnName](#columnname18)&gt;         | 否   | 向量召回数字匹配降档策略配置，如果查询中存在数字，但是对应目标字段中的数字和查询数字不匹配，则将该检索结果的相关性降低。key为对应向量召回条件中的recallName，value为对应模式匹配字段名。默认值为空。 |


## RdbRecords<sup>18+</sup>

检索结果。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| records    | Array&lt;[ItemInfo](#iteminfo18)&gt;         | 是   | 当前检索的查询词。 |


## ItemInfo<sup>18+</sup>

检索结果中每条数据的特定内容。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| primaryKey    | string         | 是   |检索结果的主键。 |
| columns    | Record&lt;string, [relationalStore.ValueType](js-apis-data-relationalStore.md#valuetype)&gt;          | 是   | 召回列及其内容。 |
| score    | number        | 是   | 检索重排后的最终得分，其反映了重排记录与查询词之间的相似度。score取值大于等于0。 |
| recallScores    | Record&lt;[ChannelType](#channeltype18), Record&lt;string, [RecallScore](#recallscore18)&gt;&gt;         | 是   | 每路召回的得分，其反映了每路召回对该结果的相关性评估。key为该路RecallCondition的scoreKey；如果这里没有体现RetrievalCondition中的某一路RecallCondition的scoreKey，则代表该路召回认为该结果相关性过低不予召回。 |
| features    | Record&lt;string, number&gt;         | 是   | 不同倒排策略的得分。目前支持的倒排策略及得分为：<br>-"exact_phase"：文档字段精确命中查询语句的得分。<br>-"out_of_order_phase"：文档字段命中近似乱序匹配策略的得分。<br>-"token_bm25"：文档字段bm25策略得分。<br>-"core_count"：文档单个匹配字段内核心词总数。 |
| similarityLevel    | [SimilarityLevel](#similaritylevel18)         | 是   | 结果的相关性分档，表示该结果属于高相关、中相关、或低相关档位，方便对结果进行进一步筛选并且过滤。<br>-仅显示高相关性时：准确率高，召回率较低。<br>-显示高相关、中相关和低相关性时：召回率高，准确率较低。 |

## RecallScore<sup>18+</sup>

召回过程的得分。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 类型              | 必填 | 说明                                                         |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| score    | number         | 是   | 召回得分。 |
| isReverseQuery    | boolean         | 是   | 表示得分是否来自反查过程。true表示来自反查过程，flase表示来自原始召回过程。 |

## SimilarityLevel<sup>18+</sup>

检索结果的相关性分档，表示该结果高相关、中相关、低相关，方便对结果进行进一步筛选并且过滤。

**系统能力：** SystemCapability.DistributedDataManager.DataIntelligence.Core

| 名称     | 值    | 说明                                                         |
| ---------- | ----------| ------------------------------------------------------------ |
| NONE        | 0      | 无相似度。 |
| LOW         | 1      | 低相似度。 |
| MEDIUM      | 2      | 中相似度。 |
| HIGH        | 3      | 高相似度。 |