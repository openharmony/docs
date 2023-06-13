# 使用MindSpore Lite引擎进行模型推理

## 场景介绍

MindSpore Lite是一款AI引擎，它提供了面向不同硬件设备AI模型推理的功能，目前已经在图像分类、目标识别、人脸识别、文字识别等应用中广泛使用。

本文介绍使用MindSpore Lite推理引擎实现模型推理的通用开发流程。对于使用Native接口实现模型推理，具体指导请见：[使用MindSpore Lite引擎进行模型推理 ](../napi/mindspore-lite-guidelines.md)。

## 基本概念

在进行开发前，请先了解以下概念。

**张量**：它与数组和矩阵非常相似，是MindSpore Lite网络运算中的基本数据结构。

**Float16推理模式**：  Float16又称半精度，它使用16比特表示一个数。Float16推理模式表示推理的时候用半精度进行推理。 

## 接口说明
这里给出MindSpore Lite推理的通用开发流程中涉及的一些接口，具体请见下列表格。更多接口及详细内容，请见[@ohos.ai.mindSporeLite (推理能力)](../reference/apis/js-apis-mindSporeLite.md)。

| 接口名        | 描述        |
| ------------------ | ----------------- |
|loadModelFromFile(model: string, options: Context): Promise&lt;Model&gt;|从路径加载模型。|
|getInputs(): MSTensor[]|获取模型的输入。|
|predict(inputs: MSTensor[]): Promise&lt;MSTensor&gt;|推理模型。|
| getData(): ArrayBuffer                 | 获取张量的数据。 |
| setData(inputArray: ArrayBuffer): void | 设置张量的数据。 |

## 开发步骤

主要流程包括模型的准备、读取、编译、推理和释放，具体开发过程及细节请见下文的开发步骤及示例。

1. 模型准备。需要的模型可以直接下载，也可以通过模型转换工具获得。需要的数据从bin文件读取。

   - 下载模型的格式若为`.ms`，则可以直接使用。本文以mnet.caffemodel.ms为例。
   - 如果是第三方框架的模型，比如 TensorFlow、TensorFlow Lite、Caffe、ONNX等，可以使用[模型转换工具](https://www.mindspore.cn/lite/docs/zh-CN/r2.0/use/downloads.html#1-8-1)转换为`.ms`格式的模型文件。
2. 创建上下文，设置线程数、设备类型等参数。
3. 加载模型。本文从路径读入模型。
4. 加载数据。模型执行之前需要先获取输入，再向输入的张量中填充数据。
5. 执行推理并打印输出。使用predict接口进行模型推理。
```js
@State inputName: string = 'mnet_caffemodel_nhwc.bin';
@State T_model_predict: string = 'Test_MSLiteModel_predict'
inputBuffer: any = null;
build() {
  Row() {
  Column() {
    Text(this.T_model_predict)
      .focusable(true)
      .fontSize(30)
      .fontWeight(FontWeight.Bold)
      .onClick(async () => {
         //1.模型准备
         let syscontext = globalThis.context;
         syscontext.resourceManager.getRawFileContent(this.inputName).then((buffer) => {
           this.inputBuffer = buffer;
           console.log('=========input bin byte length: ' + this.inputBuffer.byteLength)
         }).catch(error => {
           console.error('Failed to get buffer, error code: ${error.code},message:${error.message}.');
         })
         //2.创建上下文
         let context: mindSporeLite.Context = {};
         context.target = ['cpu'];
         context.cpu = {}
         context.cpu.threadNum = 1;
         context.cpu.threadAffinityMode = 0;
         context.cpu.precisionMode = 'enforce_fp32';
         //3.加载模型
         let modelFile = '/data/storage/el2/base/haps/entry/files/mnet.caffemodel.ms';
         let msLiteModel = await mindSporeLite.loadModelFromFile(modelFile, context);
         //4.加载数据
         const modelInputs = msLiteModel.getInputs();
         modelInputs[0].setData(this.inputBuffer.buffer);
         //5.执行推理并打印输出
         console.log('=========MSLITE predict start=====')
         msLiteModel.predict(modelInputs).then((modelOutputs) => {
           let output0 = new Float32Array(modelOutputs[0].getData());
           for (let i = 0; i < output0.length; i++) {
               console.log(output0[i].toString());
           }
         })
         console.log('=========MSLITE predict success=====')
       })
  }
  .width('100%')
  }
  .height('100%')
}
```

## 调测验证

1. 在DevEco Studio 中连接rk3568开发板，点击Run entry，编译自己的hap，有如下显示：

   ```shell
   Launching com.example.myapptfjs
   $ hdc uninstall com.example.myapptfjs
   $ hdc install -r "D:\TVOS\JSAPI\MyAppTfjs\entry\build\default\outputs\default\entry-default-signed.hap"
   $ hdc shell aa start -a EntryAbility -b com.example.myapptfjs
   ```

2. 使用hdc连接rk3568开发板，并将mnet.caffemodel.ms推送到设备中的沙盒目录。mnet_caffemodel_nhwc.bin在本地项目中的rawfile目录下。

   ```shell
   hdc -t 7001005458323933328a00bcdf423800 file send .\mnet.caffemodel.ms /data/app/el2/100/base/com.example.myapptfjs/haps/entry/files/
   ```
3. 在rk3568屏幕中点击Test_MSLiteModel_predict触发用例，在HiLog打印结果中得到如下结果：

   ```shell                                        
   08-27 23:25:50.278 31782-31782/? I C03d00/JSAPP: =========MSLITE predict start=====
   08-27 23:25:51.487 31782-31782/? I C03d00/JSAPP: 0.10046602040529252
   08-27 23:25:51.487 31782-31782/? I C03d00/JSAPP: 0.07535600662231445
   08-27 23:25:51.487 31782-31782/? I C03d00/JSAPP: 0.06326554715633392
   08-27 23:25:51.487 31782-31782/? I C03d00/JSAPP: 0.0015114173293113708
   08-27 23:25:51.487 31782-31782/? I C03d00/JSAPP: -0.026745859533548355
   08-27 23:25:51.487 31782-31782/? I C03d00/JSAPP: -0.055590517818927765
   08-27 23:25:51.487 31782-31782/? I C03d00/JSAPP: -0.05325715243816376
   08-27 23:25:51.487 31782-31782/? I C03d00/JSAPP: -0.04629542678594589
   ...
   08-27 23:25:52.881 31782-31782/? I C03d00/JSAPP: 0.23317644000053404
   08-27 23:25:52.881 31782-31782/? I C03d00/JSAPP: 0.17999525368213654
   08-27 23:25:50.372 31782-31782/? I C03d00/JSAPP: =========MSLITE predict success=====
   ```
