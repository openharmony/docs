# Application Data Vectorization (ArkTS)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @my-2024; @cuile44; @pancodax-->
<!--Designer: @fysun17; @AnruiWang; @xd_94-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## When to Use

In the pivotal shift from digital transformation to AI advancement, creating intelligent services is essential for boosting product competitiveness.

Currently, ArkData Intelligence Platform (AIP) provides application data vectorization, which leverages embedding models to convert multi-modal data such as unstructured text and images into semantic vectors.

## Basic Concepts

To get started, it is helpful to understand the following concepts:

### Vectorization
The process of vectorization uses embedding models to convert high-dimensional unstructured data (such as text and images) into low-dimensional continuous vector representations. This approach captures the semantic relationships with the data, translating abstract information into a format that can be analyzed and processed by computers. Embedding technology is widely used in fields such as natural language processing (semantic search), image recognition (feature extraction), and recommendation systems (user/item representation).

### Multi-Modal Embedding Model
Embedding models are used to implement application data vectorization. The system supports multimodal embedding models, which can map different data modalities, such as text and images, into a unified vector space. These models support both single-modal semantic representation (text-to-text and image-to-image retrieval) and cross-modal capabilities (text-to-image and image-to-text retrieval).

### Text Segmentation
To address length limitations when textual data is vectorized, you can use the APIs provided by the ArkData Intelligence Platform (AIP) to split the input text into smaller sections. This approach ensures efficient and effective data vectorization.

## Implementation Mechanism

By leveraging the AIP, you can implement intelligent data construction. All these capabilities operate within the application processes, ensuring that data always remains in the application environment. This ensures data security and safeguards user privacy.

## Working Principles
Application data vectorization involves converting raw application data into vector formats and storing them in a vector database (store).

## Constraints
- Considering the significant computing workload and resources of data vectorization processing, the APIs are only available to 2-in-1 device applications.
- You can use NPUs to accelerate the inference process of embedding models. NPUs are recommended because pure CPU computation falls far behind in latency and energy efficiency.
- The model can process up to 512 characters of text per inference, supporting both Chinese and English.
- The model can handle images below 20 MB in size in a single inference.

## Available APIs

The following table lists the APIs related to application data vectorization. For more APIs and their usage, see [ArkData Intelligence Platform](../reference/apis-arkdata/js-apis-data-intelligence.md).

| API| Description|
| -------- | -------- |
| getTextEmbeddingModel(config: ModelConfig): Promise&lt;TextEmbedding&gt; | Obtains a text embedding model.|
| loadModel(): Promise&lt;void&gt; | Loads this text embedding model.|
| splitText(text: string, config: SplitConfig): Promise&lt;Array&lt;string&gt;&gt; | Splits text.|
| getEmbedding(text: string): Promise&lt;Array&lt;number&gt;&gt; | Obtains the embedding vector of the given text.|
| getEmbedding(batchTexts: Array&lt;string&gt;): Promise&lt;Array&lt;Array&lt;number&gt;&gt;&gt; | Obtains the embedding vector of a given batch of text.|
| releaseModel(): Promise&lt;void&gt; | Releases this text embedding model.|
| getImageEmbeddingModel(config: ModelConfig): Promise&lt;ImageEmbedding&gt; | Obtains an image embedding model.|
| loadModel(): Promise&lt;void&gt; | Loads this image embedding model.|
| getEmbedding(image: Image): Promise&lt;Array&lt;number&gt;&gt; | Obtains the embedding vector of the given image.|
| releaseModel(): Promise&lt;void&gt; | Releases this image embedding model.|

## How to Develop Text Vectorization

1. Import the **intelligence** module.

   ```ts
   import { intelligence } from '@kit.ArkData';
   ```

2. Obtain a text embedding model using the **getTextEmbeddingModel** method. The sample code is as follows:
   
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

3. Load this embedding model using the **loadModel** method. The sample code is as follows:
   
```ts
   textEmbedding.loadModel()
     .then(() => {
       console.info("Succeeded in loading Model");
     })
     .catch((err:BusinessError) => {
       console.error("Failed to load Model and code is " + err.code);
     })
```

4. Split text. If the data length exceeds the limit, call **splitText()** to split the data into smaller text blocks and then vectorize them.
   The sample code is as follows:

   ```ts
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

5. Obtain the embedding vector of the given text using the **getEmbedding** method. The given text can be a single piece of text or a collection of multiple text entries.
   The sample code is as follows:

   ```ts
   let text = 'text';
   textEmbedding.getEmbedding(text)
     .then((data:Array<number>) => {
       console.info("Succeeded in getting Embedding");
     })
     .catch((err:BusinessError) => {
       console.error("Failed to get Embedding and code is " + err.code);
     })
   ```

   ```ts
   let batchTexts = ['text1','text2'];
   textEmbedding.getEmbedding(batchTexts)
     .then((data:Array<Array<number>>) => {
       console.info("Succeeded in getting Embedding");
     })
     .catch((err:BusinessError) => {
       console.error("Failed to get Embedding and code is " + err.code);
     })
   ```

6. Release this text embedding model using the **releaseModel** method. The sample code is as follows:
   
```ts
   textEmbedding.releaseModel()
     .then(() => {
       console.info("Succeeded in releasing Model");
     })
     .catch((err:BusinessError) => {
       console.error("Failed to release Model and code is " + err.code);
     })
```

## How to Develop Image Vectorization

1. Import the **intelligence** module.

   ```ts
   import { intelligence } from '@kit.ArkData';
   ```

2. Obtain an image embedding model using the **getImageEmbeddingModel** method. The sample code is as follows:
   
```ts
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

3. Load this image embedding model using the **loadModel** method. The sample code is as follows:
   
```ts
   imageEmbedding.loadModel()
     .then(() => {
        console.info("Succeeded in loading Model");
     })
     .catch((err:BusinessError) => {
        console.error("Failed to load Model and code is " + err.code);
     })
```

4. Obtain the embedding vector of the given image using the **getEmbedding** method. The sample code is as follows:
   
 ```ts
    let image = "file://<packageName>/data/storage/el2/base/haps/entry/files/xxx.jpg";
    imageEmbedding.getEmbedding(image)
      .then((data:Array<number>) => {
        console.info("Succeeded in getting Embedding");
      })
      .catch((err:BusinessError) => {
        console.error("Failed to get Embedding and code is " + err.code);
      })
 ```

5. Release this image embedding model using the **releaseModel** method. The sample code is as follows:
   
 ```ts
    imageEmbedding.releaseModel()
      .then(() => {
        console.info("Succeeded in releasing Model");
      })
      .catch((err:BusinessError) => {
        console.error("Failed to release Model and code is " + err.code);
      })
 ```
