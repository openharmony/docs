# @ohos.data.intelligence (ArkData Intelligence Platform)

The ArkData Intelligence Platform (AIP) provides on-device data intelligence capabilities, enabling AI-powered data processing data on devices. To underpin AI-powered processing on devices, the AIP aims to build the following capabilities:
- Multimodal embedding model: leverages embedding models to generate vector representations for multimodal data, mapping text, images, and other data into a unified vector space for semantic-based multimodal knowledge retrieval.
- Multimodal data storage: supports on-device storage for vectors, inverted indexes, and other multimodal data, eliminating the need to send raw data to the server for processing. This reduces the risk of data leakage.
- Knowledge retrieval: enables semantic retrieval of user knowledge based on capabilities such as semantic indexing, knowledge graphs, recall, and re-ranking.
- Knowledge generation and collation: implements efficient data organization and knowledge generation based on user data such as user documents, messages, emails, photos, videos, calendar events, and screen context, enabling the transformation of data into knowledge.

> **NOTE**
>
> The initial APIs of this module are supported since API version 15. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> Considering the significant computing workload and resources of data vectorization processing, the APIs are only available to 2-in-1 device applications.


## Modules to Import

```ts
import { intelligence } from '@kit.ArkData';
```

## intelligence.getTextEmbeddingModel

getTextEmbeddingModel(config: ModelConfig): Promise&lt;TextEmbedding&gt;

Obtains a text embedding model. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name      | Type                                   | Mandatory| Description                              |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| config | [ModelConfig](#modelconfig) | Yes  | Configuration of the embedded model to obtain.|

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| Promise&lt;[TextEmbedding](#textembedding)&gt; | Promise used to return the text embedding model object.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [AIP Error Codes](errorcode-intelligence.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**Example**

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

Obtains an image embedding model. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name      | Type                                   | Mandatory| Description                              |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| config | [ModelConfig](#modelconfig) | Yes  | Configuration of the embedded model to obtain.|

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| Promise&lt;[ImageEmbedding](#imageembedding)&gt; | Promise used to return the image embedding model object.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [AIP Error Codes](errorcode-intelligence.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**Example**

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

Splits text.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name      | Type                                   | Mandatory| Description                              |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| text | string | Yes  | Text to split, which can be any value.|
| config | [SplitConfig](#splitconfig) | Yes  | Configuration for splitting the text.|

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the blocks of the text.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [AIP Error Codes](errorcode-intelligence.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**Example**

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

## ModelConfig

Represents the configuration an embedded model.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Name    | Type             | Mandatory| Description                                                        |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| version    | [ModelVersion](#modelversion)           | Yes  |Version of the model.|
| isNpuAvailable | boolean                | Yes  | Whether to use the NPU to accelerate the vectorization process. The value **true** means to use the NPU, and the value **false** means the opposite. If this parameter is set to **true** but the device does not support NPUs, loading an embedding model will trigger error 31300000.|
| cachePath | string                | No  | Local directory for model caching if the NPU is used. The value is in the /xxx/xxx/xxx format, for example, **/data**. The path cannot exceed 512 characters. <br>Default value: **""**|

## ModelVersion

Enumerates the model versions.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Name      | Value                  | Description                  |
| ---------- | ---------- | ---------------------- |
| BASIC_MODEL     | 0     | Basic embedding model version.  |

## Image

type Image = string

Represents the URI of an image, which is of the string type.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                        | Description                 |
| ---------------------------- | --------------------- |
| string | Image URI, which cannot exceed 512 characters.|

## SplitConfig

Represents the configuration for text splitting.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

| Name    | Type             | Mandatory| Description                                                        |
| ---------- | --------------------- | ---- | ------------------------------------------------------------ |
| size    |       number     | Yes  |Maximum size of a block. The value is a non-negative integer.|
| overlapRatio | number                | Yes  | Overlap ratio between adjacent blocks. <br>Value range: [0,1]<br>The value **0** indicates the lowest overlap ratio, and **1** indicates the highest overlap ratio.|


## TextEmbedding

Provides APIs for manipulating text embedding models.

Before calling any of the following APIs, you must obtain a **TextEmbedding** instance by using [intelligence.getTextEmbeddingModel](#intelligencegettextembeddingmodel).

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

### loadModel

loadModel(): Promise&lt;void&gt;

Loads this embedding model. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [AIP Error Codes](errorcode-intelligence.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**Example**

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

Releases this embedding model. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [AIP Error Codes](errorcode-intelligence.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**Example**

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

Obtains the embedding vector of the given text.

Before calling this API, ensure that an embedding model is successfully loaded by using [loadModel](#loadmodel).

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name      | Type                                   | Mandatory| Description                              |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| text | string | Yes  | Text for the embedding model. It cannot exceed 512 characters.|

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the vectorization result.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [AIP Error Codes](errorcode-intelligence.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**Example**

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

Obtains the embedding vector of a given batch of texts.

Before calling this API, ensure that an embedding model is successfully loaded by using [loadModel](#loadmodel).

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name      | Type                                   | Mandatory| Description                              |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| batchTexts | Array&lt;string&gt; | Yes  | Batch of texts, each of which cannot exceed 512 characters.|

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;Array&lt;number&gt;&gt;&gt; | Promise used to return the vectorization result.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [AIP Error Codes](errorcode-intelligence.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**Example**

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

Provides APIs for manipulating image embedding models.

Before calling any of the following APIs, you must obtain a **ImageEmbedding** instance by using [intelligence.getImageEmbeddingModel](#intelligencegetimageembeddingmodel).

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

### loadModel

loadModel(): Promise&lt;void&gt;

Loads this embedding model. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [AIP Error Codes](errorcode-intelligence.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**Example**

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

Releases this embedding model. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [AIP Error Codes](errorcode-intelligence.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**Example**

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

Obtains the embedding vector of the given image.

Before calling this API, ensure that an embedding model is successfully loaded by using [loadModel](#loadmodel).

**System capability**: SystemCapability.DistributedDataManager.DataIntelligence.Core

**Parameters**

| Name      | Type                                   | Mandatory| Description                              |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| image | [Image](#image) | Yes  | URI of the target image.|

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the vectorization result.|

**Error codes**

For details about the error codes, see [Common Error Codes](../errorcode-universal.md) and [AIP Error Codes](errorcode-intelligence.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801          | Capability not supported. |
| 31300000     | Inner error. |                                                                                                                                    |

**Example**

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
