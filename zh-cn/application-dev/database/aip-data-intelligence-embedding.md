# 应用数据向量化 (ArkTS)

## 场景介绍

在数字化向智能化演进的关键阶段，构建智慧化服务已成为应用开发者提升产品竞争力的必然选择。

当前，系统提供ArkData智慧数据平台（Arkdata Intelligence Platform，AIP），提供端侧数据智慧化构建，使应用数据向量化，通过嵌入模型将非结构化的文本、图像等多模态数据，转换成具有语义的向量。

## 基本概念

在智慧化数据构建过程中，涉及以下基本概念，请先了解相关含义。

### 向量化
向量化主要是指通过嵌入模型将高维非结构化数据（如文字、图像）映射为低维连续向量的嵌入技术。嵌入技术通过模型捕捉数据之间的语义关系，将抽象概念转化为可计算的数学表示，使计算机能够理解非结构化数据。目前，嵌入技术广泛应用于自然语言处理（语义搜索）、图像识别（特征提取）、推荐系统（用户/物品表征）等领域。

### 多模态嵌入模型
应用数据向量化，主要通过嵌入模型实现。当前支持多模态嵌入模型，能将文本和图像这两种不同数据模态转换到同一个向量空间，支持单模态（文搜文、图搜图）和跨模态（文搜图、图搜文）的语义表征能力。

### 文本分块
数据向量化时，文本数据长度受限，可通过AIP分块接口切分文本，高效实现数据向量化。

## 实现机制

应用可借助智慧数据平台能力，实现智慧化数据的构建，将应用数据转化为可计算的向量，相关能力均运行在应用进程内，数据不出应用，保证隐私安全。

## 运作机制
应用数据向量化，将应用原数据向量化并存储在向量数据库中。

## 约束限制
- 考虑到数据向量化处理的计算量和资源占用较大，当前仅支持在2in1设备上使用。
- 嵌入模型的推理过程可使用NPU加速。与NPU计算相比，纯CPU的计算在时延和功耗上都有较大差距，建议采用NPU加速。
- 模型推理单次可处理的文本长度上限为512个字符，支持中英文。
- 模型推理单次可处理的图像大小小于20MB。

## 接口说明

以下是智慧数据向量化功能的相关接口。更多接口及使用方式请见[智慧数据平台](../reference/apis-arkdata/js-apis-data-intelligence.md)。

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

## 文本向量化开发步骤

1. 导入模块。

   ```ts
   import { intelligence } from '@kit.ArkData';
   ```

2. 获取文本嵌入模型。
   调用getTextEmbeddingModel方法，获取文本嵌入模型。示例代码如下所示：

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

3. 加载文本嵌入模型。
   调用loadModel方法，加载文本嵌入模型。示例代码如下所示：

   ```ts
   textEmbedding.loadModel()
     .then(() => {
       console.info("Succeeded in loading Model");
     })
     .catch((err:BusinessError) => {
       console.error("Failed to load Model and code is " + err.code);
     })
   ```

4. 获取文本的分块。当数据长度超过限定时，使用splitText()接口将其分块，然后再进行数据向量化。
   调用splitText方法，获取文本的分块结果。示例代码如下所示：

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

5. 获取给定文本的嵌入向量。给定的文本数据可以是单个文本或文本集合。
   调用getEmbedding方法，获取给定单个文本或文本集合的嵌入向量。示例代码如下所示：

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
   调用releaseModel方法，释放文本嵌入模型。示例代码如下所示：

   ```ts
   textEmbedding.releaseModel()
     .then(() => {
       console.info("Succeeded in releasing Model");
     })
     .catch((err:BusinessError) => {
       console.error("Failed to release Model and code is " + err.code);
     })
   ```

## 图像向量化开发步骤

1. 导入模块。

   ```ts
   import { intelligence } from '@kit.ArkData';
   ```

2. 获取图像嵌入模型。
   调用getTextEmbeddingModel方法，获取图像嵌入模型。示例代码如下所示：

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

3. 加载图像嵌入模型。
   调用loadModel方法，加载图像嵌入模型。示例代码如下所示：

   ```ts
   imageEmbedding.loadModel()
     .then(() => {
        console.info("Succeeded in loading Model");
     })
     .catch((err:BusinessError) => {
        console.error("Failed to load Model and code is " + err.code);
     })
   ```

4. 获取给定图像的嵌入向量。
   调用getEmbedding方法，获取给定图像的嵌入向量。示例代码如下所示：

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

5. 释放图像嵌入模型。
   调用releaseModel方法，释放图像嵌入模型。示例代码如下所示：

    ```ts
    imageEmbedding.releaseModel()
      .then(() => {
        console.info("Succeeded in releasing Model");
      })
      .catch((err:BusinessError) => {
        console.error("Failed to release Model and code is " + err.code);
      })
    ```
