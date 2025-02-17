# 应用数据向量化

## 场景介绍

应用数据向量化，是指嵌入模型将非结构化的文本、图像等多模态数据，转换成具有语义的向量。在智慧化检索、RAG（检索增强生成）等场景中，嵌入模型扮演桥梁的角色，将离散的图文数据映射到同一向量空间，支撑跨模态的数据检索。向量化的主要应用场景如下：

- 高效检索：通过向量的相似度计算，快速从向量数据库中召回与查询词最相关的文档片段。相比传统倒排索引，能识别语义隐含关联，提升召回内容的上下文适配性。
- 检索增强生成：检索增强生成（RAG）是解决LLM大模型生成幻觉问题的主流方案，向量知识库是RAG技术的关键。RAG可检索出知识库中的精准上下文（Top-K相关向量对应文本）并作为提示输入生成模型，从而显著减少生成幻觉。

## 基本概念

### 多模态嵌入模型
应用数据向量化，主要通过嵌入模型实现。当前支持多模态嵌入模型，能将文本和图像这两种不同数据模态转换到同一个向量空间，支持单模态（文搜文、图搜图）和跨模态（文搜图、图搜文）的语义表征能力。

### 文本分块
在进行数据向量化时，针对文本数据长度有限制，可通过AIP提供的分块接口，将输入文本按照指定的上限进行切分，从而高效实现数据向量化。

## 运作机制
应用数据向量化，是指将应用原数据进行向量化并进行存储的过程，向量化结果会存储在向量数据库中。

## 约束限制
- 模型推理单次可处理的文本长度上限为512个字符，支持中英文。
- 模型推理单次可处理的图像大小<20MB。

## 接口说明

以下是智慧数据向量化功能的相关接口，接口为异步接口。异步接口通过Promise方式返回。

| 接口名称 | 描述 | 
| -------- | -------- |
| getTextEmbeddingModel(config: ModelConfig): Promise&lt;TextEmbedding&gt; | 获取文本嵌入模型。 | 
| loadModel(): Promise&lt;void&gt; | 加载文本嵌入模型。 | 
| splitText(text: string, config: SplitConfig): Promise&lt;Array&lt;string&gt;&gt; | 获取文本的分块。 | 
| getEmbedding(text: string): Promise&lt;Array&lt;number&gt;&gt; | 获取给定文本的嵌入向量。 | 
| getEmbedding(batchTexts: Array&lt;string&gt;): Promise&lt;Array&lt;Array&lt;number&gt;&gt;&gt; | 获取给定批次文本的嵌入向量。 |
| releaseModel(): Promise&lt;void&gt; | 释放文本嵌入模型。 | 
| getImageEmbeddingModel(config: ModelConfig): Promise&lt;ImageEmbedding&gt; | 获取图像嵌入模型。 | 
| loadModel(): Promise&lt;void&gt; | 加载图像嵌入模型。 | 
| getEmbedding(image: Image): Promise&lt;Array&lt;number&gt;&gt; | 获取给定图像的嵌入向量。 | 
| releaseModel(): Promise&lt;void&gt; | 释放图像嵌入模型。 | 


## 开发步骤

1. 导入模块。

   ```ts
   import { intelligence } from '@kit.ArkData';
   ```

2. 获取文本嵌入模型。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';

   let textConfig:intelligence.ModelConfig = {
     version:1,
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

3. 加载文本嵌入模型。

   ```ts
   textEmbedding.loadModel()
     .then(() => {
       console.info("Succeeded in loading Model");
     })
     .catch((err:BusinessError) => {
       console.error("Failed to load Model and code is " + err.code);
     })
   ```

4. 获取文本的分块。当需要进行向量化的数据长度过长时，使用splitText()接口对其进行文本分块，然后再进行数据向量化。

   ```ts
   let splitConfig:intelligence.SplitConfig = {
     size:10,
     overlapRatio:0.1
   }
   let text = 'text';

   intelligence.splitText(text, splitConfig)
     .then((data:Array<string>) => {
       console.info("Succeeded in splitting Text");
     })
     .catch((err:BusinessError) => {
       console.error("Failed to split Text and code is " + err.code);
     })
   ```

5. 获取给定文本的嵌入向量。给定的文本数据可以为单个文本数据或者一个文本数据的集合。

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

6. 释放文本嵌入模型。

   ```ts
   textEmbedding.releaseModel()
     .then(() => {
       console.info("Succeeded in releasing Model");
     })
     .catch((err:BusinessError) => {
       console.error("Failed to release Model and code is " + err.code);
     })
   ```

7. 获取图像嵌入模型。

   ```ts
   let imageConfig:intelligence.ModelConfig = {
     version:1,
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

8. 加载图像嵌入模型。

   ```ts
   imageEmbedding.loadModel()
     .then(() => {
        console.info("Succeeded in loading Model");
     })
     .catch((err:BusinessError) => {
        console.error("Failed to load Model and code is " + err.code);
     })
   ```

9. 获取给定图像的嵌入向量。

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

10. 释放图像嵌入模型。

    ```ts
    imageEmbedding.releaseModel()
      .then(() => {
        console.info("Succeeded in releasing Model");
      })
      .catch((err:BusinessError) => {
        console.error("Failed to release Model and code is " + err.code);
      })
    ```
