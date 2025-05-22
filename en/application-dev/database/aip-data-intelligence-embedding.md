# Application Data Vectorization

## When to Use

Application data vectorization leverages embedding models to convert multi-modal data such as unstructured text and images into semantic vectors. In scenarios like intelligent retrieval and Retrieval-Augmented Generation (RAG), embedding models act as a bridge, mapping discrete textual and visual data into a unified vector space for cross-modal data retrieval. Vectorization applies to the following scenarios:

- Efficient retrieval: enables rapid recall of document fragments that are most relevant to query terms from a vector database by calculating vector similarities. Compared with traditional inverted indexing, efficient retrieval can identify implicit semantic associations, enhancing the contextual relevance of retrieved content.
- RAG: a leading approach to addressing the hallucination problem in large language models (LLMs). A vector knowledge base plays a crucial role in RAG technology. By retrieving precise context from the knowledge base (Top-K relevant vectors corresponding to text) and using it as input prompts for the generation model, RAG significantly reduces the occurrence of hallucinations.

## Basic Concepts

### Multi-Modal Embedding Model
Embedding models are used to implement application data vectorization. The system supports multimodal embedding models, which can map different data modalities, such as text and images, into a unified vector space. These models support both single-modal semantic representation (text-to-text and image-to-image retrieval) and cross-modal capabilities (text-to-image and image-to-text retrieval).

### Text Segmentation
To address length limitations when textual data is vectorized, you can use the APIs provided by the ArkData Intelligence Platform (AIP) to split the input text into smaller sections. This approach ensures efficient and effective data vectorization.

## Working Principles
Application data vectorization involves converting raw application data into vector formats and storing them in a vector database (store).

## Constraints
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


## How to Develop

1. Import the **intelligence** module.

   ```ts
   import { intelligence } from '@kit.ArkData';
   ```

2. Obtain a text embedding model.

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

3. Load this embedding model.

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

5. Obtain the embedding vector of the given text. The given text can be a single piece of text or a collection of multiple text entries.

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

6. Release this text embedding model.

   ```ts
   textEmbedding.releaseModel()
     .then(() => {
       console.info("Succeeded in releasing Model");
     })
     .catch((err:BusinessError) => {
       console.error("Failed to release Model and code is " + err.code);
     })
   ```

7. Obtain an image embedding model.

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

8. Load this image embedding model.

   ```ts
   imageEmbedding.loadModel()
     .then(() => {
        console.info("Succeeded in loading Model");
     })
     .catch((err:BusinessError) => {
        console.error("Failed to load Model and code is " + err.code);
     })
   ```

9. Obtain the embedding vector of the given image.

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

10. Release this image embedding model.

    ```ts
    imageEmbedding.releaseModel()
      .then(() => {
        console.info("Succeeded in releasing Model");
      })
      .catch((err:BusinessError) => {
        console.error("Failed to release Model and code is " + err.code);
      })
    ```
