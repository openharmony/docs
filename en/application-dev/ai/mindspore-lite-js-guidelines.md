# Using MindSpore Lite for Model Inference (JS)

## Scenarios

MindSpore Lite is an AI engine that implements AI model inference for different hardware devices. It has been used in a wide range of fields, such as image classification, target recognition, facial recognition, and character recognition.

This document describes the general development process for implementing MindSpore Lite model inference. For details about how to use native APIs to implement model inference, see [Using MindSpore Lite for Model Inference](../napi/mindspore-lite-guidelines.md).

## Basic Concepts

Before getting started, you need to understand the following basic concepts:

**Tensor**: a special data structure that is similar to arrays and matrices. It is basic data structure used in MindSpore Lite network operations.

**Float16 inference mode**: a mode that uses half-precision inference. Float16 uses 16 bits to represent a number and therefore it is also called half-precision.

## Available APIs
APIs involved in MindSpore Lite model inference are categorized into context APIs, model APIs, and tensor APIs. For more APIs, see [@ohos.ai.mindSporeLite](../reference/apis/js-apis-mindSporeLite.md).

| API       | Description       |
| ------------------ | ----------------- |
|loadModelFromFile(model: string, options: Context): Promise&lt;Model&gt;|Loads a model from a file.|
|getInputs(): MSTensor[]|Obtains the model input.|
|predict(inputs: MSTensor[]): Promise&lt;MSTensor&gt;|Performs model inference.|
| getData(): ArrayBuffer                 | Obtains tensor data.|
| setData(inputArray: ArrayBuffer): void | Sets the tensor data.|

## How to Develop

The development process consists of the following main steps:

1. Prepare the required model. You can download the required model directly or obtain the model by using the model conversion tool. The required data is read from the `bin` file.

   - If the downloaded model is in the `.ms` format, you can use it directly for inference. This document uses `mnet.caffemodel.ms` as an example.
   - If the downloaded model uses a third-party framework, such as TensorFlow, TensorFlow Lite, Caffe, or ONNX, you can use the [model conversion tool](https://www.mindspore.cn/lite/docs/en/r2.0/use/downloads.html#1-8-1) to convert it to the `.ms` format.
2. Create a context, and set parameters such as the number of runtime threads and device type.
3. Load the model. In this example, the model is read from the file.
4. Load data. Before executing a model, you need to obtain the model input and then fill data in the input tensor.
5. Perform inference and print the output. Call the **predict** API to perform model inference.
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
         // 1. Prepare for a model.
         let syscontext = globalThis.context;
         syscontext.resourceManager.getRawFileContent(this.inputName).then((buffer) => {
           this.inputBuffer = buffer;
           console.log('=========input bin byte length: ' + this.inputBuffer.byteLength)
         }).catch(error => {
           console.error('Failed to get buffer, error code: ${error.code},message:${error.message}.');
         })
         // 2. Create a context.
         let context: mindSporeLite.Context = {};
         context.target = ['cpu'];
         context.cpu = {}
         context.cpu.threadNum = 1;
         context.cpu.threadAffinityMode = 0;
         context.cpu.precisionMode = 'enforce_fp32';
         // 3. Load the model.
         let modelFile = '/data/storage/el2/base/haps/entry/files/mnet.caffemodel.ms';
         let msLiteModel = await mindSporeLite.loadModelFromFile(modelFile, context);
         // 4. Load data.
         const modelInputs = msLiteModel.getInputs();
         modelInputs[0].setData(this.inputBuffer.buffer);
         // 5. Perform inference and print the output.
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

## Debugging and Verification

1. Connect to the rk3568 development board on DevEco Studio, click **Run entry**, and compile your own HAP. The following information is displayed:

   ```shell
   Launching com.example.myapptfjs
   $ hdc uninstall com.example.myapptfjs
   $ hdc install -r "D:\TVOS\JSAPI\MyAppTfjs\entry\build\default\outputs\default\entry-default-signed.hap"
   $ hdc shell aa start -a EntryAbility -b com.example.myapptfjs
   ```

2. Use the hdc tool to connect to the rk3568 development board and push `mnet.caffemodel.ms` to the sandbox directory on the device. `mnet\_caffemodel\_nhwc.bin` is stored in the `rawfile` directory of the local project.

   ```shell
   hdc -t 7001005458323933328a00bcdf423800 file send .\mnet.caffemodel.ms /data/app/el2/100/base/com.example.myapptfjs/haps/entry/files/
   ```
3. Click **Test\_MSLiteModel\_predict** on the screen of the rk3568 development board to run the test case. The following information is displayed in the HiLog printing result:

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
