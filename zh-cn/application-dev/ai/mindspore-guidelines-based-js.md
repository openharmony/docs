# 使用MindSpore Lite JS API开发AI应用

## 使用场景

开发者可以使用MindSpore Lite提供的JS API，在UI代码中直接集成MindSpore Lite能力，快速部署AI算法，进行AI模型推理。

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

## 推理代码开发

假设开发者已准备好`.ms`格式模型。模型推理流程包括读取、编译、推理和释放，具体开发过程及细节如下：

1. 创建上下文，设置线程数、设备类型等参数。
2. 加载模型。本文从路径读入模型。
3. 加载数据。模型执行之前需要先获取输入，再向输入的张量中填充数据。
4. 执行推理并读取输出。使用predict接口进行模型推理。

```ts
// 构造单例对象
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
// 1.创建上下文
let context: mindSporeLite.Context = {};
context.target = ['cpu'];
context.cpu = {}
context.cpu.threadNum = 1;
context.cpu.threadAffinityMode = 0;
context.cpu.precisionMode = 'enforce_fp32';

// 2.加载模型
let modelFile = '/data/storage/el2/base/haps/entry/files/mnet.caffemodel.ms';
let msLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFile(modelFile, context);

// 3.设置输入数据
let modelInputs : mindSporeLite.MSTensor[] = msLiteModel.getInputs();
if (inputBuffer != null) {
  modelInputs[0].setData(inputBuffer as ArrayBuffer);
}

// 4.执行推理并打印输出
console.log('=========MSLITE predict start=====')
msLiteModel.predict(modelInputs).then((modelOutputs : mindSporeLite.MSTensor[]) => {
  let output0 = new Float32Array(modelOutputs[0].getData());
  for (let i = 0; i < output0.length; i++) {
    console.log(output0[i].toString());
  }
  })
console.log('=========MSLITE predict success=====')
```

## 调测验证

1. 在DevEco Studio 中连接设备，点击Run entry，编译自己的hap，有如下显示：

   ```shell
   Launching com.example.myapptfjs
   $ hdc uninstall com.example.myapptfjs
   $ hdc install -r "path/to/xxx.hap"
   $ hdc shell aa start -a EntryAbility -b com.example.myapptfjs
   ```

2. 使用hdc连接设备，并将mnet.caffemodel.ms推送到设备中的沙盒目录。mnet_caffemodel_nhwc.bin在本地项目中的rawfile目录下。

   ```shell
   hdc -t your_device_id file send .\mnet.caffemodel.ms /data/app/el2/100/base/com.example.myapptfjs/haps/entry/files/
   ```
3. 在设备屏幕点击Test_MSLiteModel_predict触发用例，在HiLog打印结果中得到如下结果：

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
