# 智慧数据向量化

## 场景介绍

当应用程序需要获取文本或图片向量化结果时，可以使用相关接口来进行文本或者图片的向量化结果获取

详细的接口介绍请参考[Intelligence接口](../../reference/apis-arkdata/js-apis-data-intelligence.md)。

## 运作机制
### 向量化/表征概念
以文本为示例，表征模型的向量召回过程，包括底库文本向量推理，在线用户查询推文本推理，以及查询文本向量和底库文本向量之间的相似度计算，最终根据相似度排序得到K个最相关的查询结果。

### 多模态表征模型
多模态统一表征模型关键技术包括多阶段语义表征训练技术、多任务联合建模技术、多模态表征增强技术三个部分。

首先进行多任务、多阶段的统一图文表征学习，使得模型同时具备单模态（文搜文、图搜图）和跨模态（文搜图、图搜文）的语义表征能力。其中，文搜图能力能够对标同等量级clip模型，文搜文能力能够对标同等量级Bert-based文本表征模型。

更进一步地，基于LLM数据生成更多的正样本和难负样本实施训练，进一步增强模型跨模态的细粒度检索能力和非对称表征能力。其中，细粒度语义对齐提升负样本难度，学习细粒度图像-语义信息，如“蒲公英”与“吹蒲公英”，非对称表征学习增强模型对于概括性描述-图片的表征能力。

模型推理性能方面，会通过模型侧和硬件侧两方面对嵌入模型的内存、功耗、时延展开相应的优化工作。模型侧基于模型量化、剪枝、蒸馏等轻量化技术，降低端侧模型的性能开销；硬件侧对NPU算子进行适配分析和优化，进一步对模型的性能消耗进行压缩。

## 约束限制
- 模型推理单次可处理的文本长度<512token，支持中英文
- 模型推理单次可处理的图像大小<20MB

## 接口说明

以下是智慧数据向量化功能的相关接口，接口为异步接口。异步接口通过Promise方式返回。

| 接口名称 | 描述 | 
| -------- | -------- |
| getTextEmbeddingModel(config: ModelConfig): Promise&lt;TextEmbedding&gt; | 获取文本嵌入模型。 | 
| loadModel(): Promise&lt;void&gt; | 加载嵌入模型。 | 
| releaseModel(): Promise&lt;void&gt;; | 释放嵌入模型。 | 
| getEmbedding(text: string): Promise&lt;Array&lt;number&gt;&gt; | 获取给定文本的嵌入向量。 | 
| getEmbedding(batchTexts: Array&lt;string&gt;): Promise&lt;Array&lt;Array&lt;number&gt;&gt;&gt; | 获取给定批次文本的嵌入向量。 |
| getImageEmbeddingModel(config: ModelConfig): Promise&lt;ImageEmbedding&gt; | 获取图像嵌入模型。 | 
| loadModel(): Promise&lt;void&gt; | 加载嵌入模型。 | 
| releaseModel(): Promise&lt;void&gt;; | 释放嵌入模型。 | 
| getEmbedding(image: Image): Promise&lt;Array&lt;number&gt;&gt; | 获取给定图像的嵌入向量。 | 
| splitText(text: string, config: SplitConfig): Promise&lt;Array&lt;string&gt;&gt; | 获取文本的分块。 | 


## 开发步骤

1. 导入模块。
     
   ```ts
   import { intelligence } from '@kit.ArkData';
   ```

2. 获取文本嵌入模型。
     
   ```ts

   let config = {
    version:1,
    isNpuAvailable:false,
    cachePath:"test"
   }

   intelligence.getTextEmbeddingModel(config)
      .then((data) => {
        console.info("get result success");
      })
      .catch((err) => {
        console.log("get result filed" + err.code);
      })
   ```

3. 加载嵌入模型。
     
   ```ts

   let config = {
    version:1,
    isNpuAvailable:false,
    cachePath:"test"
   }

   intelligence.getTextEmbeddingModel(config)
      .then((data) => {
        console.info("get result success");
        data.loadModel()
         .then(() => {
          console.info("load success");
         })
         .catch((err) => {
          console.log("load filed " + err.code);
         })
      })
      .catch((err) => {
        console.log("get result filed " + err.code);
      })
   ```

4. 释放嵌入模型。
     
   ```ts

   let config = {
    version:1,
    isNpuAvailable:false,
    cachePath:"test"
   }

   intelligence.getTextEmbeddingModel(config)
      .then((data) => {
        console.info("get result success");
        data.loadModel();
        data.releaseModel()
         .then(() => {
          console.info("release success");
         })
         .catch((err) => {
          console.log("release filed " + err.code);
         })
      })
      .catch((err) => {
        console.log("get result filed " + err.code);
      })
   ```

5. 获取给定文本的嵌入向量。
     
   ```ts

   let config = {
    version:1,
    isNpuAvailable:false,
    cachePath:"test"
   }

   intelligence.getTextEmbeddingModel(config)
      .then((data) => {
        console.info("get result success");
        data.loadModel();
        let text = 'text';
        data.getEmbedding(text)
         .then(() => {
          console.info("getEmbedding success");
         })
         .catch((err) => {
          console.log("getEmbedding filed " + err.code);
         })
      })
      .catch((err) => {
        console.log("get result filed " + err.code);
      })
   ```

6. 获取给定批次文本的嵌入向量。
     
   ```ts

   let config = {
    version:1,
    isNpuAvailable:false,
    cachePath:"test"
   }

   intelligence.getTextEmbeddingModel(config)
      .then((data) => {
        console.info("get result success");
        data.loadModel();
        let batchTexts = ['text1','text2'];
        data.getEmbedding(batchTexts)
         .then(() => {
          console.info("getEmbedding success");
         })
         .catch((err) => {
          console.log("getEmbedding filed " + err.code);
         })
      })
      .catch((err) => {
        console.log("get result filed " + err.code);
      })
   ```

7. 获取图像嵌入模型。
     
   ```ts

   let config = {
    version:1,
    isNpuAvailable:false,
    cachePath:"image"
   }

   intelligence.getImageEmbeddingModel(config)
      .then((data) => {
        console.info("get result success");
      })
      .catch((err) => {
        console.log("get result filed" + err.code);
      })
   ```

8. 加载嵌入模型。
     
   ```ts

   let config = {
    version:1,
    isNpuAvailable:false,
    cachePath:"image"
   }

   intelligence.getImageEmbeddingModel(config)
      .then((data) => {
        console.info("get result success");
        data.loadModel()
         .then(() => {
          console.info("load success");
         })
         .catch((err) => {
          console.log("load filed " + err.code);
         })
      })
      .catch((err) => {
        console.log("get result filed " + err.code);
      })
   ```

9. 释放嵌入模型。
     
   ```ts

   let config = {
    version:1,
    isNpuAvailable:false,
    cachePath:"image"
   }

   intelligence.getImageEmbeddingModel(config)
      .then((data) => {
        console.info("get result success");
        data.loadModel();
        data.releaseModel()
         .then(() => {
          console.info("release success");
         })
         .catch((err) => {
          console.log("release filed " + err.code);
         })
      })
      .catch((err) => {
        console.log("get result filed " + err.code);
      })
   ```

10. 获取给定图像的嵌入向量。
     
   ```ts

   let config = {
    version:1,
    isNpuAvailable:false,
    cachePath:"image"
   }

   intelligence.getImageEmbeddingModel(config)
      .then((data) => {
        console.info("get result success");
        data.loadModel();
        let image = 'image uri';
        data.getEmbedding(image)
         .then(() => {
          console.info("getEmbedding success");
         })
         .catch((err) => {
          console.log("getEmbedding filed " + err.code);
         })
      })
      .catch((err) => {
        console.log("get result filed " + err.code);
      })
   ```

11. 获取文本的分块。
     
   ```ts

   let config = {
    size:10,
    overlapRatio:0.1
   }

   let text = 'text';

   intelligence.splitText(text, config)
      .then((data) => {
        console.info("get result success");
      })
      .catch((err) => {
        console.log("get result filed" + err.code);
      })
   ```