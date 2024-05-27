# @ohos.ai.mindSporeLite (推理能力)

MindSpore Lite是一款AI引擎，它提供了面向不同硬件设备AI模型推理的功能，目前已经在图像分类、目标识别、人脸识别、文字识别等应用中广泛使用。
本模块介绍了MindSpore Lite推理引擎支持模型推理的相关能力。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。示例代码使用模型均为MindSpore端侧模型。
> 
> 本模块接口仅可在Stage模型下使用。

## 导入模块
```ts
import { mindSporeLite } from '@kit.MindSporeLiteKit';
```

## TrainCfg

定义训练环境的配置信息。

### 属性

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                            | 类型                                    | 必填 | 说明                 |
| ------------------------------- | --------------------------------------- | ---- | -------------------- |
| lossName<sup>12+</sup>          | string[]                                | 是   | 损失函数的名称列表。 |
| optimizationLevel<sup>12+</sup> | [OptimizationLevel](#optimizationlevel) | 否   | 训练配置的优化等级。 |

### OptimizationLevel

训练配置的优化等级。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称               | 值   | 说明                                                       |
| ------------------ | ---- | ---------------------------------------------------------- |
| O0<sup>12+</sup>   | 0    | 无优化等级。                                               |
| O2<sup>12+</sup>   | 2    | 将网络转换为float16, 保持批量归一化层和损失函数为float32。 |
| O3<sup>12+</sup>   | 3    | 将网络转换为float16, 包括批量归一化层。                    |
| AUTO<sup>12+</sup> | 4    | 根据设备选择优化等级。                                     |

## Extension

定义NNRT设备的扩展信息。

### 属性

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                | 类型        | 必填 | 说明             |
| ------------------- | ----------- | ---- | ---------------- |
| name<sup>12+</sup>  | string      | 是   | 扩展名称。       |
| value<sup>12+</sup> | ArrayBuffer | 否   | 包含扩展的内存。 |

## Context

定义运行环境的配置信息。

### 属性

**系统能力：** SystemCapability.AI.MindSporeLite


| 名称   | 类型                      | 可读 | 可写 | 说明                                                         |
| ------ | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| target | string[]                  | 是   | 是   | 配置目标后端。可选'cpu'，'nnrt'，默认'cpu'。                 |
| cpu    | [CpuDevice](#cpudevice)   | 是   | 是   | CPU后端设备选项。只有当target包含'cpu'时，才能设置此属性。默认值为CpuDevice各属性默认值。 |
| nnrt   | [NNRTDevice](#nnrtdevice) | 是   | 是   | NNRT后端设备选项。只有当target包含'nnrt'时，才能设置此属性，当前属性为空。 |

**示例：** 

```ts
let context: mindSporeLite.Context = {};
context.target = ['cpu','nnrt'];
```

## CpuDevice

CPU后端设备选项。

### 属性

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                   | 类型                                      | 可读 | 可写 | 说明                                                         |
| ---------------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| threadNum              | number                                    | 是   | 是   | 设置运行时的线程数，默认值：2。                              |
| threadAffinityMode     | [ThreadAffinityMode](#threadaffinitymode) | 是   | 是   | 设置运行时的CPU绑核策略模式，默认值为不绑核：mindSporeLite.ThreadAffinityMode.NO_AFFINITIES。 |
| threadAffinityCoreList | number[]                                  | 是   | 是   | 设置运行时的CPU绑核列表，设置绑核策略模式后使能，当绑核策略模式为mindSporeLite.ThreadAffinityMode.NO_AFFINITIES时，绑核列表为空。列表中的数字代表核的序号。默认值：[]。 |
| precisionMode          | string                                    | 是   | 是   | 设置是否使能**Float16推理模式**，设置为'preferred_fp16'代表使能半精度推理，其余设置情况均为不支持，默认设置'enforce_fp32'表示不使能半精度推理。 |

**Float16推理模式**：  Float16又称半精度，它使用16比特表示一个数。Float16推理模式表示推理的时候用半精度进行推理。 

**示例：** 

```ts
let context: mindSporeLite.Context = {};
context.cpu = {};
context.target = ['cpu'];
context.cpu.threadNum = 2;
context.cpu.threadAffinityMode = 0;
context.cpu.precisionMode = 'preferred_fp16';
context.cpu.threadAffinityCoreList = [0, 1, 2];
```

## NNRTDevice

Neural Network Runtime表示神经网络运行时，简称NNRt。作为中间桥梁，连通上层 AI 推理框架和底层加速芯片，实现 AI 模型的跨芯片推理计算。MindSpore Lite 可配置NNRt后端。当前暂未支持。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                          | 类型                                | 必填 | 说明                     |
| ----------------------------- | ----------------------------------- | ---- | ------------------------ |
| deviceID<sup>12+</sup>        | bigint                              | 是   | NNRT设备ID。             |
| performanceMode<sup>12+</sup> | [PerformanceMode](#performancemode) | 否   | NNRT设备的工作性能模式。 |
| priority<sup>12+</sup>        | [Priority](#priority)               | 否   | NNRT推理任务优先级。     |
| extensions<sup>12+</sup>      | Extension[]                         | 否   | NNRT设备的扩展配置。     |



## ThreadAffinityMode

设置运行时的CPU绑核策略模式，有效值为0-2，0为默认不绑核，1为绑大核，2为绑中核。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称               | 值   | 说明         |
| ------------------ | ---- | ------------ |
| NO_AFFINITIES      | 0    | 不绑核。     |
| BIG_CORES_FIRST    | 1    | 绑大核优先。 |
| LITTLE_CORES_FIRST | 2    | 绑中核优先。 |

## PerformanceMode

NNRT设备的工作性能模式。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                              | 值   | 说明                |
| --------------------------------- | ---- | ------------------- |
| PERFORMANCE_NONE<sup>12+</sup>    | 0    | 无特殊设置。        |
| PERFORMANCE_LOW<sup>12+</sup>     | 1    | 低功耗模式。        |
| PERFORMANCE_MEDIUM<sup>12+</sup>  | 2    | 功耗-性能均衡模式。 |
| PERFORMANCE_HIGH<sup>12+</sup>    | 3    | 高性能模式。        |
| PERFORMANCE_EXTREME<sup>12+</sup> | 4    | 极致性能模式。      |

## Priority

NNRT推理任务优先级。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                          | 值   | 说明           |
| ----------------------------- | ---- | -------------- |
| PRIORITY_NONE<sup>12+</sup>   | 0    | 无优先级偏好。 |
| PRIORITY_LOW<sup>12+</sup>    | 1    | 低优先级任务。 |
| PRIORITY_MEDIUM<sup>12+</sup> | 2    | 中优先级任务。 |
| PRIORITY_HIGH<sup>12+</sup>   | 3    | 高优先级。     |



## NNRTDeviceDescription

NNRT设备信息描述，包含设备ID，设备名称等信息。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                     | 类型                              | 必填 | 说明                     |
| ------------------------ | --------------------------------- | ---- | ------------------------ |
| deviceID<sup>12+</sup>   | bigint                            | 是   | NNRT设备ID。             |
| deviceType<sup>12+</sup> | [NNRTDeviceType](#nnrtdevicetype) | 否   | NNRT设备的工作性能模式。 |
| deviceName<sup>12+</sup> | string                            | 否   | NNRT设备名称。           |

## NNRTDeviceType

NNRT设备类型。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                                 | 值   | 说明                                |
| ------------------------------------ | ---- | ----------------------------------- |
| NNRTDEVICE_OTHERS<sup>12+</sup>      | 0    | 设备类型不属于以下3种，则属于其它。 |
| NNRTDEVICE_CPU<sup>12+</sup>         | 1    | CPU设备。                           |
| NNRTDEVICE_GPU<sup>12+</sup>         | 2    | GPU设备。                           |
| NNRTDEVICE_ACCELERATOR<sup>12+</sup> | 3    | 特定的加速设备。                    |



## mindSporeLite.loadModelFromFile

loadModelFromFile(model: string, callback: Callback&lt;Model&gt;): void

从完整路径加载输入模型用于推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| model    | string                    | 是   | 模型的完整输入路径。     |
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。 |

**示例：** 

```ts
let model_file : string = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file, (result : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromFile

loadModelFromFile(model: string, context: Context, callback: Callback&lt;Model&gt;): void

从完整路径加载输入模型用于推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | string                              | 是   | 模型的完整输入路径。   |
| context | [Context](#context) | 是 | 运行环境的配置信息。 |
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。 |

**示例：** 

```ts
let context: mindSporeLite.Context = {};
context.target = ['cpu'];
let model_file : string = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file, context, (result : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromFile

loadModelFromFile(model: string, context?: Context): Promise&lt;Model&gt;

从完整路径加载输入模型用于推理。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名  | 类型                | 必填 | 说明                 |
| ------- | ------------------- | ---- | -------------------- |
| model   | string              | 是   | 模型的完整输入路径。 |
| context | [Context](#context) | 否   | 运行环境的配置信息。 |

**返回值：**

| 类型                      | 说明                         |
| ------------------------- | ---------------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

**示例：** 

```ts
let model_file = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file).then((result : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromBuffer

loadModelFromBuffer(model: ArrayBuffer, callback: Callback&lt;Model&gt;): void

从内存加载输入模型用于推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| model    | ArrayBuffer               | 是   | 包含模型的内存。         |
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。 |

**示例：** 

```ts
import { mindSporeLite } from '@kit.MindSporeLiteKit';
import { common } from '@kit.AbilityKit';

let modelName = '/path/to/xxx.ms';
getContext(this).resourceManager.getRawFileContent(modelName).then((buffer : Uint8Array) => {
  let modelBuffer = buffer.buffer;
  mindSporeLite.loadModelFromBuffer(modelBuffer, (result : mindSporeLite.Model) => {
    let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();
    console.log(modelInputs[0].name);
  })
})
```
## mindSporeLite.loadModelFromBuffer

loadModelFromBuffer(model: ArrayBuffer, context: Context, callback: Callback&lt;Model&gt;): void

从内存加载输入模型用于推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | ArrayBuffer                   | 是   | 包含模型的内存。 |
| context | [Context](#context) | 是  | 运行环境的配置信息。 |
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。 |

**示例：** 

```ts
import { resourceManager } from '@kit.LocalizationKit';
import { GlobalContext } from '../GlobalContext';
import { mindSporeLite } from '@kit.MindSporeLiteKit';
import { common } from '@kit.AbilityKit';
let modelName = '/path/to/xxx.ms';
export class Test {
  value:number = 0;
  foo(): void {
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let globalContext= GlobalContext.getContext().getObject("value") as common.UIAbilityContext;

globalContext.resourceManager.getRawFileContent(modelName).then((buffer : Uint8Array) => {
  let modelBuffer = buffer.buffer;
  let context: mindSporeLite.Context = {};
  context.target = ['cpu'];
  mindSporeLite.loadModelFromBuffer(modelBuffer, context, (result : mindSporeLite.Model) => {
    let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();
    console.log(modelInputs[0].name);
  })
})
```
## mindSporeLite.loadModelFromBuffer

loadModelFromBuffer(model: ArrayBuffer, context?: Context): Promise&lt;Model&gt;

从内存加载输入模型用于推理。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名  | 类型                | 必填 | 说明                 |
| ------- | ------------------- | ---- | -------------------- |
| model   | ArrayBuffer         | 是   | 包含模型的内存。     |
| context | [Context](#context) | 否   | 运行环境的配置信息。 |

**返回值：**

| 类型                            | 说明                         |
| ------------------------------- | ---------------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

**示例：** 

```ts
import { resourceManager } from '@kit.LocalizationKit';
import { GlobalContext } from '../GlobalContext';
import { mindSporeLite } from '@kit.MindSporeLiteKit';
import { common } from '@kit.AbilityKit';
let modelName = '/path/to/xxx.ms';
export class Test {
  value:number = 0;
  foo(): void {
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let globalContext = GlobalContext.getContext().getObject("value") as common.UIAbilityContext;

globalContext.resourceManager.getRawFileContent(modelName).then((buffer : Uint8Array) => {
  let modelBuffer = buffer.buffer;
  mindSporeLite.loadModelFromBuffer(modelBuffer).then((result : mindSporeLite.Model) => {
    let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();
    console.log(modelInputs[0].name);
  })
})
```
## mindSporeLite.loadModelFromFd

loadModelFromFd(model: number, callback: Callback&lt;Model&gt;): void

从文件描述符加载输入模型用于推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | number                         | 是   | 模型的文件描述符。 |
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。 |

**示例：** 

```ts
import { fileIo } from '@kit.CoreFileKit';
let model_file = '/path/to/xxx.ms';
let file = fileIo.openSync(model_file, fileIo.OpenMode.READ_ONLY);
mindSporeLite.loadModelFromFd(file.fd, (result : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromFd

loadModelFromFd(model: number, context: Context, callback: Callback&lt;Model&gt;): void

从文件描述符加载输入模型用于推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | number                   | 是   | 模型的文件描述符。 |
| context | [Context](#context) | 是  | 运行环境的配置信息。 |
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。 |

**示例：** 

```ts
import { fileIo } from '@kit.CoreFileKit';
let model_file = '/path/to/xxx.ms';
let context : mindSporeLite.Context = {};
context.target = ['cpu'];
let file = fileIo.openSync(model_file, fileIo.OpenMode.READ_ONLY);
mindSporeLite.loadModelFromFd(file.fd, context, (result : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromFd

loadModelFromFd(model: number, context?: Context): Promise&lt;Model&gt;

从文件描述符加载输入模型用于推理。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名  | 类型                | 必填 | 说明                 |
| ------- | ------------------- | ---- | -------------------- |
| model   | number              | 是   | 模型的文件描述符。   |
| context | [Context](#context) | 否   | 运行环境的配置信息。 |

**返回值：**

| 类型                      | 说明                         |
| ------------------------- | ---------------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

**示例：** 

```ts
import { fileIo } from '@kit.CoreFileKit';
let model_file = '/path/to/xxx.ms';
let file = fileIo.openSync(model_file, fileIo.OpenMode.READ_ONLY);
let mindSporeLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFd(file.fd);
let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
console.log(modelInputs[0].name);
```

## mindSporeLite.loadTrainModelFromFile<sup>12+</sup>

loadTrainModelFromFile(model: string, trainCfg?: TrainCfg, context?: Context): Promise&lt;Model&gt;

根据路径读取加载训练模型文件。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                | 必填 | 说明                 |
| -------- | ------------------- | ---- | -------------------- |
| model    | string              | 是   | 模型的完整输入路径。 |
| trainCfg | TrainCfg            | 否   | 模型训练配置。       |
| context  | [Context](#context) | 否   | 运行环境的配置信息。 |

**返回值：**

| 类型                       | 说明                   |
| ------------------------ | -------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |



## mindSporeLite.loadTrainModelFromBuffer<sup>12+</sup>

loadTrainModelFromBuffer(model: ArrayBuffer, trainCfg?: TrainCfg, context?: Context): Promise&lt;Model&gt;

从内存加载训练模型文件。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                | 必填 | 说明                 |
| -------- | ------------------- | ---- | -------------------- |
| model    | ArrayBuffer         | 是   | 包含训练模型的内存。 |
| trainCfg | TrainCfg            | 否   | 模型训练配置。       |
| context  | [Context](#context) | 否   | 运行环境的配置信息。 |

**返回值：**

| 类型                       | 说明                   |
| ------------------------ | -------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |



## mindSporeLite.loadTrainModelFromFd<sup>12+</sup>

loadTrainModelFromFd(model: number, trainCfg?: TrainCfg, context?: Context): Promise&lt;Model&gt;

从文件描述符加载训练模型文件。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                | 必填 | 说明                   |
| -------- | ------------------- | ---- | ---------------------- |
| model    | number              | 是   | 训练模型的文件描述符。 |
| trainCfg | TrainCfg            | 否   | 模型训练配置。         |
| context  | [Context](#context) | 否   | 运行环境的配置信息。   |

**返回值：**

| 类型                     | 说明                         |
| ------------------------ | ---------------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

## mindSporeLite.getAllNNRTDeviceDescriptions<sup>12+</sup>

getAllNNRTDeviceDescriptions() : NNRTDeviceDescription[]

获取NNRT中的所有设备描述。

**系统能力：** SystemCapability.AI.MindSporeLite

**返回值：**

| 类型                    | 说明                   |
| ----------------------- | ---------------------- |
| NNRTDeviceDescription[] | NNRT设备描述信息数组。 |



## Model

模型实例。描述Model对象的属性和方法。

下例API示例中都需先使用[loadModelFromFile()](#mindsporeliteloadmodelfromfile)、[loadModelFromBuffer()](#mindsporeliteloadmodelfrombuffer)、[loadModelFromFd()](#mindsporeliteloadmodelfromfd)中的任一方法获取到Model实例，再通过此实例调用对应方法。

### learningRate<sup>12+</sup>

learningRate: number

训练模型的学习率。

**系统能力：** SystemCapability.AI.MindSporeLite

**返回值：**

| 类型     | 说明     |
| ------ | ------ |
| number | 返回学习率。 |

### trainMode<sup>12+</sup>

trainMode: boolean

模型的运行模式。

**系统能力：** SystemCapability.AI.MindSporeLite

**返回值：**

| 类型      | 说明         |
| ------- | ---------- |
| boolean | 返回是否是训练模式。 |

### getInputs

getInputs(): MSTensor[]

获取模型的输入用于推理。

**系统能力：**  SystemCapability.AI.MindSporeLite

**返回值：**

| 类型                    | 说明               |
| ----------------------- | ------------------ |
| [MSTensor](#mstensor)[] | 返回MSTensor对象。 |

**示例：** 

```ts
let model_file = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file).then((result : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();
  console.log(modelInputs[0].name);
})
```
### predict

predict(inputs: MSTensor[], callback: Callback&lt;MSTensor[]&gt;): void

执行推理模型。使用callback异步回调。需要确保调用时模型对象不被资源回收。

**系统能力：**  SystemCapability.AI.MindSporeLite

**参数：**

| 参数名 | 类型                    | 必填 | 说明                       |
| ------ | ----------------------- | ---- | -------------------------- |
| inputs | [MSTensor](#mstensor)[] | 是   | 模型的输入列表。MSTensor对象。 |
| callback | Callback<[MSTensor](#mstensor)[]> | 是   | 回调函数。返回MSTensor对象。 |

**示例：** 

```ts
import { resourceManager } from '@kit.LocalizationKit';
import { GlobalContext } from '../GlobalContext';
import { mindSporeLite } from '@kit.MindSporeLiteKit';
import { common } from '@kit.AbilityKit';
export class Test {
  value:number = 0;
  foo(): void {
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let globalContext = GlobalContext.getContext().getObject("value") as common.UIAbilityContext;

let inputName = 'input_data.bin';
globalContext.resourceManager.getRawFileContent(inputName).then(async (buffer : Uint8Array) => {
  let modelBuffer = buffer.buffer;
  let model_file : string = '/path/to/xxx.ms';
  let mindSporeLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFile(model_file);
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();

  modelInputs[0].setData(modelBuffer);
  mindSporeLiteModel.predict(modelInputs, (result : mindSporeLite.MSTensor[]) => {
    let output = new Float32Array(result[0].getData());
    for (let i = 0; i < output.length; i++) {
      console.log(output[i].toString());
    }
  })
})
```
### predict

predict(inputs: MSTensor[]): Promise&lt;MSTensor[]&gt;

执行推理模型，返回推理结果。使用Promise异步回调。需要确保调用时模型对象不被资源回收。

**系统能力：**  SystemCapability.AI.MindSporeLite

**参数：**

| 参数名 | 类型                    | 必填 | 说明                           |
| ------ | ----------------------- | ---- | ------------------------------ |
| inputs | [MSTensor](#mstensor)[] | 是   | 模型的输入列表。MSTensor对象。 |

**返回值：**

| 类型                    | 说明                   |
| ----------------------- | ---------------------- |
| Promise<[MSTensor](#mstensor)[]> | Promise对象。返回MSTensor对象列表。 |

**示例：** 

```ts
import { resourceManager } from '@kit.LocalizationKit';
import { GlobalContext } from '../GlobalContext';
import { mindSporeLite } from '@kit.MindSporeLiteKit';
import { common } from '@kit.AbilityKit';
export class Test {
    value:number = 0;
    foo(): void {
    GlobalContext.getContext().setObject("value", this.value);
}
}
let globalContext = GlobalContext.getContext().getObject("value") as common.UIAbilityContext;;
let inputName = 'input_data.bin';
globalContext.resourceManager.getRawFileContent(inputName).then(async (buffer : Uint8Array) => {
  let modelBuffer = buffer.buffer;
  let model_file = '/path/to/xxx.ms';
  let mindSporeLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFile(model_file);
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  modelInputs[0].setData(modelBuffer);
  mindSporeLiteModel.predict(modelInputs).then((result : mindSporeLite.MSTensor[]) => {
    let output = new Float32Array(result[0].getData());
    for (let i = 0; i < output.length; i++) {
      console.log(output[i].toString());
    }
  })
})
```

### resize

resize(inputs: MSTensor[], dims: Array&lt;Array&lt;number&gt;&gt;): boolean

重新设置张量大小。

**系统能力：**  SystemCapability.AI.MindSporeLite

**参数：**

| 参数名 | 类型                  | 必填 | 说明                          |
| ------ | --------------------- | ---- | ----------------------------- |
| inputs | [MSTensor](#mstensor)[]            | 是   | 模型的输入列表。  |
| dims   | Array&lt;Array&lt;number&gt;&gt; | 是   | 需要修改的目标张量大小。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回是否设置成功的结果。true表示重新设置张量大小成功；false表示重新设置张量大小失败。 |

**示例：** 

```ts
let model_file = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file).then((mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  let new_dim = new Array([1,32,32,1]);
  mindSporeLiteModel.resize(modelInputs, new_dim);
})
```

### runStep<sup>12+</sup>

runStep(inputs: MSTensor[]): boolean

获取是否逐步训练模型。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名    | 类型                      | 必填  | 说明       |
| ------ | ----------------------- | --- | -------- |
| inputs | [MSTensor](#mstensor)[] | 是   | 模型的输入列表。 |

**返回值：**

| 类型      | 说明          |
| ------- | ----------- |
| boolean | 返回是否逐步训练模型。 |

### getWeights<sup>12+</sup>

getWeights(): MSTensor[]

获取模型的所有权重。

**系统能力：** SystemCapability.AI.MindSporeLite

**返回值：**

| 类型                      | 说明         |
| ----------------------- | ---------- |
| [MSTensor](#mstensor)[] | 返回模型的权重张量。 |

### updateWeights<sup>12+</sup>

updateWeights(weights: MSTensor[]): boolean

更新模型的权重。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名     | 类型                      | 必填  | 说明       |
| ------- | ----------------------- | --- | -------- |
| weights | [MSTensor](#mstensor)[] | 是   | 模型的输入列表。 |

**返回值：**

| 类型      | 说明            |
| ------- | ------------- |
| boolean | 返回是否更新权重操作成功。 |

### setupVirtualBatch<sup>12+</sup>

setupVirtualBatch(virtualBatchMultiplier: number, lr: number, momentum: number): boolean

使用虚拟批次设置训练。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名                 | 类型   | 必填 | 说明                                       |
| ---------------------- | ------ | ---- | ------------------------------------------ |
| virtualBatchMultiplier | number | 是   | 虚拟批量乘法器，小于1的任意数字禁用。      |
| lr                     | number | 是   | 用于虚拟批处理的学习率，-1用于内部配置     |
| momentum               | number | 是   | 用于虚拟批处理的批范数动量，-1用于内部配置 |

**返回值：**

| 类型      | 说明        |
| ------- | --------- |
| boolean | 返回是否操作成功。 |

### exportModel<sup>12+</sup>

exportModel(modelFile: string, quantizationType?: QuantizationType, exportInferenceOnly?: boolean, outputTensorName?: string[]): boolean

导出训练模型。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名              | 类型                                  | 必填 | 说明                                             |
| ------------------- | ------------------------------------- | ---- | ------------------------------------------------ |
| modelFile           | string                                | 是   | 模型文件路径。                                   |
| quantizationType    | [QuantizationType](#quantizationtype) | 否   | 量化类型，默认为NO_quant。                       |
| exportInferenceOnly | boolean                               | 否   | 是否导出仅推理模型，默认为true。                 |
| outputTensorName    | string[]                              | 否   | 设置导出模型的输出Tensor，默认为空表示全量导出。 |

**返回值：**

| 类型      | 说明        |
| ------- | --------- |
| boolean | 返回是否操作成功。 |

### QuantizationType

量化类型信息，有效值为0-2。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                       | 值   | 说明       |
| -------------------------- | ---- | ---------- |
| NO_QUANT<sup>12+</sup>     | 0    | 不做量化。 |
| WEIGHT_QUANT<sup>12+</sup> | 1    | 权重量化。 |
| FULL_QUANT<sup>12+</sup>   | 2    | 全量化。   |

### exportWeightsCollaborateWithMicro<sup>12+</sup>

exportWeightsCollaborateWithMicro(weightFile: string, isInference?: boolean, enableFp16?: boolean, changeableWeightsName?: string[]): boolean;

导出模型权重，只能用于micro推理，仅用于端侧训练。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名                | 类型     | 必填 | 说明                                                     |
| --------------------- | -------- | ---- | -------------------------------------------------------- |
| weightFile            | string   | 是   | 权重文件路径。                                           |
| isInference           | boolean  | 否   | 是否从推理模型中导出权重，目前只支持`true`，默认为true。 |
| enableFp16            | boolean  | 否   | 是否以float16格式保存，默认为false。                     |
| changeableWeightsName | string[] | 否   | 可变权重名称。                                           |

**返回值：**

| 类型      | 说明        |
| ------- | --------- |
| boolean | 返回是否操作成功。 |

## MSTensor

模型张量实例。描述MSTensor对象的属性和方法。它与数组和矩阵非常相似，是MindSpore Lite网络运算中的基本数据结构。

下例API示例中都需先使用[getInputs()](#getinputs)获取到MSTensor实例，再通过此实例调用对应方法。

### 属性

**系统能力：**  SystemCapability.AI.MindSporeLite

| 名称       | 类型                  | 可读 | 可写 | 说明                                                 |
| ---------- | --------------------- | ---- | ---- | ---------------------------------------------------- |
| name       | string                | 是   | 是   | 张量的名称。默认为null                               |
| shape      | number[]              | 是   | 是   | 张量的维度数组。默认为0。                            |
| elementNum | number                | 是   | 是   | 张量的维度数组的长度。默认为0。                      |
| dataSize   | number                | 是   | 是   | 张量的数据的长度。默认为0。                          |
| dtype      | [DataType](#datatype) | 是   | 是   | 张量的数据类型。默认值为0，代表TYPE_UNKNOWN。        |
| format     | [Format](#format)     | 是   | 是   | 张量的数据排布方式。默认值为-1，代表DEFAULT_FORMAT。 |

**示例：** 

```ts
let model_file = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file).then((mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  console.log(modelInputs[0].name);
  console.log(modelInputs[0].shape.toString());
  console.log(modelInputs[0].elementNum.toString());
  console.log(modelInputs[0].dtype.toString());
  console.log(modelInputs[0].format.toString());
  console.log(modelInputs[0].dataSize.toString());
})
```

### getData

getData(): ArrayBuffer

获取张量的数据。

**系统能力：** SystemCapability.AI.MindSporeLite

**返回值：**

| 类型        | 说明                 |
| ----------- | -------------------- |
| ArrayBuffer | 返回张量的数据指针。 |

**示例：** 

```ts
import { resourceManager } from '@kit.LocalizationKit';
import { GlobalContext } from '../GlobalContext';
import { mindSporeLite } from '@kit.MindSporeLiteKit';
import { common } from '@kit.AbilityKit';
export class Test {
  value:number = 0;
  foo(): void {
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let globalContext = GlobalContext.getContext().getObject("value") as common.UIAbilityContext;
let inputName = 'input_data.bin';
globalContext.resourceManager.getRawFileContent(inputName).then(async (buffer : Uint8Array) => {
  let inputBuffer = buffer.buffer;
  let model_file = '/path/to/xxx.ms';
  let mindSporeLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFile(model_file);
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  modelInputs[0].setData(inputBuffer);
  mindSporeLiteModel.predict(modelInputs).then((result : mindSporeLite.MSTensor[]) => {
    let output = new Float32Array(result[0].getData());
    for (let i = 0; i < output.length; i++) {
      console.log(output[i].toString());
    }
  })
})
```

### setData

setData(inputArray: ArrayBuffer): void

设置张量的数据。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名     | 类型        | 必填 | 说明                   |
| ---------- | ----------- | ---- | ---------------------- |
| inputArray | ArrayBuffer | 是   | 张量的输入数据缓冲区。 |

**示例：** 

```ts
import { resourceManager } from '@kit.LocalizationKit';
import { GlobalContext } from '../GlobalContext';
import { mindSporeLite } from '@kit.MindSporeLiteKit';
import { common } from '@kit.AbilityKit';
export class Test {
  value:number = 0;
  foo(): void {
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let globalContext = GlobalContext.getContext().getObject("value") as common.UIAbilityContext;
let inputName = 'input_data.bin';
globalContext.resourceManager.getRawFileContent(inputName).then(async (buffer : Uint8Array) => {
  let inputBuffer = buffer.buffer;
  let model_file = '/path/to/xxx.ms';
  let mindSporeLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFile(model_file);
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  modelInputs[0].setData(inputBuffer);
})
```

## DataType

张量的数据类型。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                | 值   | 说明                |
| ------------------- | ---- | ------------------- |
| TYPE_UNKNOWN        | 0    | 未知类型。          |
| NUMBER_TYPE_INT8    | 32   | 保持Int8的类型。    |
| NUMBER_TYPE_INT16   | 33   | 保持Int16的类型。   |
| NUMBER_TYPE_INT32   | 34   | 保持Int32的类型。   |
| NUMBER_TYPE_INT64   | 35   | 保持Int64的类型。   |
| NUMBER_TYPE_UINT8   | 37   | 保持UInt8的类型。   |
| NUMBER_TYPE_UINT16  | 38   | 保持UInt16的类型。  |
| NUMBER_TYPE_UINT32  | 39   | 保持UInt32的类型。  |
| NUMBER_TYPE_UINT64  | 40   | 保持UInt64的类型。  |
| NUMBER_TYPE_FLOAT16 | 42   | 保持Float16的类型。 |
| NUMBER_TYPE_FLOAT32 | 43   | 保持Float32的类型。 |
| NUMBER_TYPE_FLOAT64 | 44   | 保持Float64的类型。 |

## Format

张量的数据排布方式。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称           | 值   | 说明                  |
| -------------- | ---- | --------------------- |
| DEFAULT_FORMAT | -1   | 未知数据排布方式。    |
| NCHW           | 0    | 数据排布方式为NCHW。  |
| NHWC           | 1    | 数据排布方式为NHWC。  |
| NHWC4          | 2    | 数据排布方式为NHWC4。 |
| HWKC           | 3    | 数据排布方式为HWKC。  |
| HWCK           | 4    | 数据排布方式为HWCK。  |
| KCHW           | 5    | 数据排布方式为KCHW。  |
