# Using MindSpore Lite JavaScript APIs to Develop AI Applications

## Scenarios

You can use the JavaScript APIs provided by MindSpore Lite to directly integrate MindSpore Lite capabilities into the UI code. This way, you can quickly deploy AI algorithms for AI model inference.

## Basic Concepts

Before getting started, you need to understand the following basic concepts:

**Tensor**: a special data structure that is similar to an array or matrix. It is the basic data structure used in MindSpore Lite network operations.

**Float16 inference mode**: a mode that uses half-precision inference. Float16 uses 16 bits to represent a number and therefore it is also called half-precision.

## Available APIs
APIs involved in MindSpore Lite model inference are categorized into context APIs, model APIs, and tensor APIs. For more APIs, see [@ohos.ai.mindSporeLite](../reference/apis/js-apis-mindSporeLite.md).

| API       | Description       |
| ------------------ | ----------------- |
|loadModelFromFile(model: string, options: Context): Promise&lt;Model&gt;|Loads a model from a file.|
|getInputs(): MSTensor[]|Obtains the model input.|
|predict(inputs: MSTensor[]): Promise&lt;MSTensor&gt;|Performs model inference.|
| getData(): ArrayBuffer                 | Obtains tensor data.|
| setData(inputArray: ArrayBuffer): void | Sets tensor data.|

## How to Develop

Assume that you have prepared a model in the **.ms** format. The key steps in model inference are model reading, model building, model inference, and memory release. The development procedure is described as follows:

1. Create a context, and set parameters such as the number of runtime threads and device type.
2. Load the model. In this example, the model is read from a file.
3. Load data. Before executing a model, you need to obtain the model input and then fill data in the input tensors.
4. Perform model inference by calling **predict**, and read the output.  

```ts
// Construct a singleton object.
export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }

}
```

```ts
import { GlobalContext } from '../GlobalContext';
import mindSporeLite from '@ohos.ai.mindSporeLite';
import common from '@ohos.app.ability.common';
export class Test {
  value:number = 0;
  foo(): void {
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let globalContext = GlobalContext.getContext().getObject("value") as common.UIAbilityContext;
let inputBuffer : ArrayBuffer | null = null;
let inputName: string = 'mnet_caffemodel_nhwc.bin';

globalContext.resourceManager.getRawFileContent(inputName).then((buffer : Uint8Array) => {
  inputBuffer = buffer.buffer;
  console.log('=========input bin byte length: ' + buffer.byteLength)
})
// 1. Create a context.
let context: mindSporeLite.Context = {};
context.target = ['cpu'];
context.cpu = {}
context.cpu.threadNum = 1;
context.cpu.threadAffinityMode = 0;
context.cpu.precisionMode = 'enforce_fp32';

// 2. Load the model.
let modelFile = '/data/storage/el2/base/haps/entry/files/mnet.caffemodel.ms';
let msLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFile(modelFile, context);

// 3. Set the input data.
let modelInputs : mindSporeLite.MSTensor[] = msLiteModel.getInputs();
if (inputBuffer != null) {
  modelInputs[0].setData(inputBuffer as ArrayBuffer);
}

// 4. Perform inference and print the output.
console.log('=========MSLITE predict start=====')
msLiteModel.predict(modelInputs).then((modelOutputs : mindSporeLite.MSTensor[]) => {
  let output0 = new Float32Array(modelOutputs[0].getData());
  for (let i = 0; i < output0.length; i++) {
    console.log(output0[i].toString());
  }
  })
console.log('=========MSLITE predict success=====')
```

## Debugging and Verification

1. On DevEco Studio, connect to the device, click **Run entry**, and build your own HAP. The following information is displayed:

   ```shell
   Launching com.example.myapptfjs
   $ hdc uninstall com.example.myapptfjs
   $ hdc install -r "path/to/xxx.hap"
   $ hdc shell aa start -a EntryAbility -b com.example.myapptfjs
   ```

2. Use hdc to connect to the device, and push **mnet.caffemodel.ms** to the sandbox directory on the device. **mnet\_caffemodel\_nhwc.bin** is stored in the **rawfile** directory of your project.

   ```shell
   hdc -t your_device_id file send .\mnet.caffemodel.ms /data/app/el2/100/base/com.example.myapptfjs/haps/entry/files/
   ```
3. Click **Test\_MSLiteModel\_predict** on the device screen to run the test case. The following information is displayed in the HiLog printing result:

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
