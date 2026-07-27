# Application Data Vectorization (ArkTS)

<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @my-2024; @cuile44; @pancodax-->
<!--Designer: @fysun17; @AnruiWang; @xd_94-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=b464bd8a2d25d9f977204373ed9c12c6bc63984e translatedAt=2026-07-27T08:15:21.461Z pushedAt=2026-07-27T08:30:36.500Z -->

## When to Use

In the pivotal shift from digital transformation to AI advancement, creating intelligent services is essential for boosting product competitiveness.

Currently, ArkData Intelligence Platform (AIP) provides application data vectorization, which leverages embedding models to convert multi-modal data such as unstructured text and images into semantic vectors.

Since API version 15, application data vectorization is supported.

## Basic Concepts

To get started, it is helpful to understand the following concepts:

### Vectorization

The process of vectorization uses embedding models to convert high-dimensional unstructured data (such as text and images) into low-dimensional continuous vector representations. This approach captures the semantic relationships with the data, translating abstract information into a format that can be analyzed and processed by computers. Embedding technology is widely used in fields such as natural language processing (semantic search), image recognition (feature extraction), and recommendation systems (user/item representation).

### Multi-Modal Embedding Model

Embedding models are used to implement application data vectorization. The system supports multimodal embedding models, which can map different data modalities, such as text and images, into a unified vector space. These models support both single-modal semantic representation (text-to-text and image-to-image retrieval) and cross-modal capabilities (text-to-image and image-to-text retrieval).

### Text Segmentation

To address length limitations when textual data is vectorized, you can use the APIs provided by the ArkData Intelligence Platform (AIP) to split the input text into smaller sections. This approach ensures efficient and effective data vectorization.

## Implementation Mechanism

By leveraging the AIP, you can implement intelligent data construction, converting application data into computable vectors. All these capabilities operate within the application processes, ensuring that data always remains in the application environment. This ensures data security and safeguards user privacy.

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
| loadModel(): Promise&lt;void&gt; | Loads the text embedding model.| 
| splitText(text: string, config: SplitConfig): Promise&lt;Array&lt;string&gt;&gt; | Obtains text chunks.| 
| getEmbedding(text: string): Promise&lt;Array&lt;number&gt;&gt; | Obtains the embedding vector of the given text.| 
| getEmbedding(batchTexts: Array&lt;string&gt;): Promise&lt;Array&lt;Array&lt;number&gt;&gt;&gt; | Obtains the embedding vector of a given batch of texts.|
| releaseModel(): Promise&lt;void&gt; | Releases the text embedding model.| 
| getImageEmbeddingModel(config: ModelConfig): Promise&lt;ImageEmbedding&gt; | Obtains an image embedding model.| 
| loadModel(): Promise&lt;void&gt; | Loads the image embedding model.| 
| getEmbedding(image: Image): Promise&lt;Array&lt;number&gt;&gt; | Obtains the embedding vector of the given image.| 
| releaseModel(): Promise&lt;void&gt; | Releases the image embedding model.| 

## How to Develop Text Vectorization

1. Import the **intelligence** module.

   <!-- @[import_the_aip_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   import { intelligence } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain a text embedding model.

   Use the **getTextEmbeddingModel** method to obtain a text embedding model. The sample code is as follows:

   <!-- @[aip_getTextEmbeddingModel_operating_parameter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   let textConfig: intelligence.ModelConfig = {
     version: intelligence.ModelVersion.BASIC_MODEL,
     isNpuAvailable: false,
     cachePath: "/data"
   }
   let textEmbedding: intelligence.TextEmbedding;
   let modelInfo:  intelligence.CloudModelInfo;
   ```

   <!-- @[aip_getTextEmbeddingModel_operating](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   intelligence.getTextEmbeddingModel(textConfig)
     .then((data: intelligence.TextEmbedding) => {
       console.info('Succeeded in getting TextModel');
       textEmbedding = data;
       // ...
     })
     .catch((err: BusinessError) => {
       console.error('Failed to get TextModel and code is ' + err.code);
       // ...
     })
   ```

3. Load the text embedding model.

   Use the **loadModel** method to load the text embedding model. The sample code is as follows:

   <!-- @[aip_loadTextModel_operating](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   textEmbedding.loadModel()
     .then(() => {
       console.info('Succeeded in loading Model');
       // ...
     })
     .catch((err: BusinessError) => {
       console.error('Failed to load Model and code is ' + err.code);
       // ...
     })
   ```

4. Split text. If the data length exceeds the limit, call **splitText()** to split the data into smaller text blocks and then vectorize them.

    The sample code is as follows:

   <!-- @[aip_splitText_operating](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   let splitConfig:intelligence.SplitConfig = {
     size: 10,
     overlapRatio: 0.1
   }
   let splitText = 'text';
   
   intelligence.splitText(splitText, splitConfig)
     .then((data: Array<string>) => {
       console.info('Succeeded in splitting Text');
       // ...
     })
     .catch((err: BusinessError) => {
       console.error('Failed to split Text and code is ' + err.code);
       // ...
     })
   ```

5. Obtain the embedding vector of the given text. The given text can be a single piece of text or a collection of multiple text entries.

    The sample code is as follows:

   <!-- @[aip_getTextEmbedding_operating](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   let text = 'text';
   textEmbedding.getEmbedding(text)
     .then((data: Array<number>) => {
       console.info('Succeeded in getting Embedding');
       // ...
     })
     .catch((err: BusinessError) => {
       console.error('Failed to get Embedding and code is ' + err.code);
       // ...
     })
   
   let batchTexts = ['text1','text2'];
   textEmbedding.getEmbedding(batchTexts)
     .then((data: Array<Array<number>>) => {
       console.info('Succeeded in getting Embedding');
       // ...
     })
     .catch((err: BusinessError) => {
       console.error('Failed to get Embedding and code is ' + err.code);
       // ...
     })
   ```

6. Release the text embedding model.

   Use the **releaseModel** method to release the text embedding model. The sample code is as follows:

   <!-- @[aip_releaseTextModel_operating](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   textEmbedding.releaseModel()
     .then(() => {
       console.info('Succeeded in releasing Model');
       // ...
     })
     .catch((err: BusinessError) => {
       console.error('Failed to release Model and code is ' + err.code);
       // ...
     })
   ```

## How to Develop Image Vectorization

1. Import the required module.

   <!-- @[import_the_aip_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   import { intelligence } from '@kit.ArkData';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain an image embedding model.

   Use the **getImageEmbeddingModel** method to obtain an image embedding model. The sample code is as follows:

   <!-- @[aip_getImageEmbeddingModel_operating_parameter](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   let imageConfig: intelligence.ModelConfig = {
     version: intelligence.ModelVersion.BASIC_MODEL,
     isNpuAvailable: false,
     cachePath: "/data"
   }
   let imageEmbedding: intelligence.ImageEmbedding;
   ```

   <!-- @[aip_getImageEmbeddingModel_operating](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   intelligence.getImageEmbeddingModel(imageConfig)
     .then((data: intelligence.ImageEmbedding) => {
       console.info('Succeeded in getting ImageModel');
       imageEmbedding = data;
       // ...
     })
     .catch((err: BusinessError) => {
       console.error('Failed to get ImageModel and code is ' + err.code);
       // ...
     })
   ```

3. Load the image embedding model.

   Use the **loadModel** method to load the image embedding model. The sample code is as follows:

    <!-- @[aip_loadImageModel_operating](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

    ``` TypeScript
    imageEmbedding.loadModel()
      .then(() => {
        console.info('Succeeded in loading Model');
        // ...
      })
      .catch((err: BusinessError) => {
        console.error('Failed to load Model and code is ' + err.code);
        // ...
      })
    ```

4. Obtain the embedding vector of the given image.

   Use the **getEmbedding** method to obtain the embedding vector of the given image. The sample code is as follows:

    <!-- @[aip_getImageEmbedding_operating](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

    ``` TypeScript
    let image = 'file://<packageName>/data/storage/el2/base/haps/entry/files/xxx.jpg';
    imageEmbedding.getEmbedding(image)
      .then((data: Array<number>) => {
        console.info('Succeeded in getting Embedding');
        // ...
      })
      .catch((err: BusinessError) => {
        console.error('Failed to get Embedding and code is ' + err.code);
        // ...
      })
    ```

5. Release the image embedding model.

   Use the **releaseModel** method to release the image embedding model. The sample code is as follows:

   <!-- @[aip_releaseImageModel_operating](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkData/Aip/entry/src/main/ets/pages/Index.ets) --> 

   ``` TypeScript
   imageEmbedding.releaseModel()
     .then(() => {
       console.info('Succeeded in releasing Model');
       // ...
     })
     .catch((err: BusinessError) => {
       console.error('Failed to release Model and code is ' + err.code);
       // ...
     })
   ```