# @ohos.ai.mindSporeLite (端侧AI框架)

MindSpore Lite 是一个轻量化、高性能的端侧AI引擎，提供了标准的模型推理和训练接口，内置通用硬件高性能算子库，原生支持Neural Network Runtime Kit使能AI专用芯片加速推理，助力打造全场景智能应用。

本模块主要介绍MindSpore Lite AI引擎支持模型端侧推理/训练的相关能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。示例代码使用模型均为MindSpore端侧模型。
> 
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { mindSporeLite } from '@kit.MindSporeLiteKit';
```

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
let modelFile : string = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile, (mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  console.info(modelInputs[0].name);
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
let modelFile : string = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile, context, (mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  console.info(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromFile

loadModelFromFile(model: string, context?: Context): Promise&lt;Model&gt;

从完整路径加载输入模型用于推理。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名  | 类型                | 必填 | 说明                                          |
| ------- | ------------------- | ---- | --------------------------------------------- |
| model   | string              | 是   | 模型的完整输入路径。                          |
| context | [Context](#context) | 否   | 运行环境的配置信息。默认使用CpuDevice初始化。 |

**返回值：**

| 类型                      | 说明                         |
| ------------------------- | ---------------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

**示例：** 

```ts
let modelFile = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile).then((mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  console.info(modelInputs[0].name);
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

let modelFile = '/path/to/xxx.ms';
getContext(this).resourceManager.getRawFileContent(modelFile).then((buffer : Uint8Array) => {
  let modelBuffer = buffer.buffer;
  mindSporeLite.loadModelFromBuffer(modelBuffer, (mindSporeLiteModel : mindSporeLite.Model) => {
    let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
    console.info(modelInputs[0].name);
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
let modelFile = '/path/to/xxx.ms';
export class Test {
  value:number = 0;
  foo(): void {
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let globalContext= GlobalContext.getContext().getObject("value") as common.UIAbilityContext;

globalContext.resourceManager.getRawFileContent(modelFile).then((buffer : Uint8Array) => {
  let modelBuffer = buffer.buffer;
  let context: mindSporeLite.Context = {};
  context.target = ['cpu'];
  mindSporeLite.loadModelFromBuffer(modelBuffer, context, (mindSporeLiteModel : mindSporeLite.Model) => {
    let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
    console.info(modelInputs[0].name);
  })
})
```
## mindSporeLite.loadModelFromBuffer

loadModelFromBuffer(model: ArrayBuffer, context?: Context): Promise&lt;Model&gt;

从内存加载输入模型用于推理。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名  | 类型                | 必填 | 说明                                          |
| ------- | ------------------- | ---- | --------------------------------------------- |
| model   | ArrayBuffer         | 是   | 包含模型的内存。                              |
| context | [Context](#context) | 否   | 运行环境的配置信息。默认使用CpuDevice初始化。 |

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
let modelFile = '/path/to/xxx.ms';
export class Test {
  value:number = 0;
  foo(): void {
    GlobalContext.getContext().setObject("value", this.value);
  }
}
let globalContext = GlobalContext.getContext().getObject("value") as common.UIAbilityContext;

globalContext.resourceManager.getRawFileContent(modelFile).then((buffer : Uint8Array) => {
  let modelBuffer = buffer.buffer;
  mindSporeLite.loadModelFromBuffer(modelBuffer).then((mindSporeLiteModel : mindSporeLite.Model) => {
    let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
    console.info(modelInputs[0].name);
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
let modelFile = '/path/to/xxx.ms';
let file = fileIo.openSync(modelFile, fileIo.OpenMode.READ_ONLY);
mindSporeLite.loadModelFromFd(file.fd, (mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  console.info(modelInputs[0].name);
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
let modelFile = '/path/to/xxx.ms';
let context : mindSporeLite.Context = {};
context.target = ['cpu'];
let file = fileIo.openSync(modelFile, fileIo.OpenMode.READ_ONLY);
mindSporeLite.loadModelFromFd(file.fd, context, (mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  console.info(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromFd

loadModelFromFd(model: number, context?: Context): Promise&lt;Model&gt;

从文件描述符加载输入模型用于推理。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名  | 类型                | 必填 | 说明                                          |
| ------- | ------------------- | ---- | --------------------------------------------- |
| model   | number              | 是   | 模型的文件描述符。                            |
| context | [Context](#context) | 否   | 运行环境的配置信息。默认使用CpuDevice初始化。 |

**返回值：**

| 类型                      | 说明                         |
| ------------------------- | ---------------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

**示例：** 

```ts
import { fileIo } from '@kit.CoreFileKit';
let modelFile = '/path/to/xxx.ms';
let file = fileIo.openSync(modelFile, fileIo.OpenMode.READ_ONLY);
mindSporeLite.loadModelFromFd(file.fd).then((mindSporeLiteModel: mindSporeLite.Model) => {
  let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  console.info(modelInputs[0].name);
})
```

## mindSporeLite.loadTrainModelFromFile<sup>12+</sup>

loadTrainModelFromFile(model: string, trainCfg?: TrainCfg, context?: Context): Promise&lt;Model&gt;

根据路径加载训练模型文件。使用Promise异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                           |
| -------- | ----------------------- | ---- | ---------------------------------------------- |
| model    | string                  | 是   | 模型的完整输入路径。                           |
| trainCfg | [TrainCfg](#traincfg12) | 否   | 模型训练配置。默认值为TrainCfg各属性默认值。   |
| context  | [Context](#context)     | 否   | 运行环境的配置信息。默认使用CpuDevice初始化。 |

**返回值：**

| 类型                       | 说明                   |
| ------------------------ | -------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

**示例：** 

```ts
let modelFile = '/path/to/xxx.ms';
mindSporeLite.loadTrainModelFromFile(modelFile).then((mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  console.info(modelInputs[0].name);
})
```

## mindSporeLite.loadTrainModelFromBuffer<sup>12+</sup>

loadTrainModelFromBuffer(model: ArrayBuffer, trainCfg?: TrainCfg, context?: Context): Promise&lt;Model&gt;

从内存缓冲区加载训练模型。使用Promise异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                          |
| -------- | ----------------------- | ---- | --------------------------------------------- |
| model    | ArrayBuffer             | 是   | 包含训练模型的内存。                          |
| trainCfg | [TrainCfg](#traincfg12) | 否   | 模型训练配置。默认值为TrainCfg各属性默认值。  |
| context  | [Context](#context)     | 否   | 运行环境的配置信息。默认使用CpuDevice初始化。 |

**返回值：**

| 类型                       | 说明                   |
| ------------------------ | -------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

**示例：** 

```ts
import { resourceManager } from '@kit.LocalizationKit'
let modelFile = 'xxx.ms';
let resMgr: resourceManager.ResourceManager = getContext().getApplicationContext().resourceManager;
resMgr.getRawFileContent(modelFile).then(modelBuffer => {
  mindSporeLite.loadTrainModelFromBuffer(modelBuffer.buffer).then((mindSporeLiteModel: mindSporeLite.Model) => {
    console.info("MSLITE trainMode: ", mindSporeLiteModel.trainMode);
  })
})
```

## mindSporeLite.loadTrainModelFromFd<sup>12+</sup>

loadTrainModelFromFd(model: number, trainCfg?: TrainCfg, context?: Context): Promise&lt;Model&gt;

从文件描述符加载训练模型文件。使用Promise异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                          |
| -------- | ----------------------- | ---- | --------------------------------------------- |
| model    | number                  | 是   | 训练模型的文件描述符。                        |
| trainCfg | [TrainCfg](#traincfg12) | 否   | 模型训练配置。默认值为TrainCfg各属性默认值。  |
| context  | [Context](#context)     | 否   | 运行环境的配置信息。默认使用CpuDevice初始化。 |

**返回值：**

| 类型                     | 说明                         |
| ------------------------ | ---------------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

**示例：** 

```ts
import { fileIo } from '@kit.CoreFileKit';
let modelFile = '/path/to/xxx.ms';
let file = fileIo.openSync(modelFile, fileIo.OpenMode.READ_ONLY);
mindSporeLite.loadTrainModelFromFd(file.fd).then((mindSporeLiteModel: mindSporeLite.Model) => {
  console.info("MSLITE trainMode: ", mindSporeLiteModel.trainMode);
});
```

## mindSporeLite.getAllNNRTDeviceDescriptions<sup>12+</sup>

getAllNNRTDeviceDescriptions() : NNRTDeviceDescription[]

获取NNRt中的所有设备描述。

**系统能力：** SystemCapability.AI.MindSporeLite

**返回值：**

| 类型                                                | 说明                   |
| --------------------------------------------------- | ---------------------- |
| [NNRTDeviceDescription](#nnrtdevicedescription12)[] | NNRt设备描述信息数组。 |

**示例：** 

```ts
let allDevices = mindSporeLite.getAllNNRTDeviceDescriptions();
if (allDevices == null) {
  console.error('MS_LITE_LOG: getAllNNRTDeviceDescriptions is NULL.');
}
```

## Context

定义运行环境的配置信息。

### 属性

**系统能力：** SystemCapability.AI.MindSporeLite


| 名称   | 类型                      | 只读 | 可选 | 说明                                                         |
| ------ | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| target | string[]                  | 否   | 是   | 配置目标后端。可选'cpu'，'nnrt'，默认'cpu'。                 |
| cpu    | [CpuDevice](#cpudevice)   | 否   | 是   | CPU后端设备选项。只有当target包含'cpu'时，才能设置此属性。默认值为CpuDevice各属性默认值。 |
| nnrt   | [NNRTDevice](#nnrtdevice) | 否   | 是   | NNRt后端设备选项。只有当target包含'nnrt'时，才能设置此属性。默认值为NNRTDevice各属性默认值。 |

**示例：** 

```ts
let context: mindSporeLite.Context = {};
context.target = ['cpu','nnrt'];
```

## CpuDevice

CPU后端设备选项。

### 属性

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                   | 类型                                      | 只读 | 可选 | 说明                                                         |
| ---------------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| threadNum              | number                                    | 否   | 是   | 设置运行时的线程数，默认值：2。                              |
| threadAffinityMode     | [ThreadAffinityMode](#threadaffinitymode) | 否   | 是   | 设置运行时的CPU绑核策略模式，默认值为不绑核：mindSporeLite.ThreadAffinityMode.NO_AFFINITIES。 |
| threadAffinityCoreList | number[]                                  | 否   | 是   | 设置运行时的CPU绑核列表，设置绑核策略模式后使能，当绑核策略模式为mindSporeLite.ThreadAffinityMode.NO_AFFINITIES时，绑核列表为空。列表中的数字代表核的序号。默认值：[]。 |
| precisionMode          | string                                    | 否   | 是   | 设置是否使能**Float16推理模式**，设置为'preferred_fp16'代表使能半精度推理，其余设置情况均为不支持，默认设置'enforce_fp32'表示不使能半精度推理。 |

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

## ThreadAffinityMode

设置运行时的CPU绑核策略模式，有效值为0-2，0为默认不绑核，1为绑大核，2为绑中核。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称               | 值   | 说明         |
| ------------------ | ---- | ------------ |
| NO_AFFINITIES      | 0    | 不绑核。     |
| BIG_CORES_FIRST    | 1    | 绑大核优先。 |
| LITTLE_CORES_FIRST | 2    | 绑中核优先。 |

## NNRTDevice

Neural Network Runtime表示神经网络运行时，简称NNRt。作为中间桥梁，连通上层 AI 推理框架和底层加速芯片，实现 AI 模型的跨芯片推理计算。MindSpore Lite 可配置NNRt后端。

### 属性

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                          | 类型                                | 只读 | 可选 | 说明                     |
| ----------------------------- | ----------------------------------- | ---- | ------------------------ | ------------------------ |
| deviceID<sup>12+</sup>        | bigint                              | 否 | 是  | NNRt设备ID。默认值为0。     |
| performanceMode<sup>12+</sup> | [PerformanceMode](#performancemode12) | 否  | 是  | NNRt设备的工作性能模式。默认值为PERFORMANCE_NONE。 |
| priority<sup>12+</sup>        | [Priority](#priority12)               | 否  | 是  | NNRt推理任务优先级。默认值为PRIORITY_MEDIUM。 |
| extensions<sup>12+</sup>      | [Extension](#extension12)[]         | 否  | 是  | NNRt设备的扩展配置。默认为空。 |

## PerformanceMode<sup>12+</sup>

NNRt设备的工作性能模式枚举。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                | 值   | 说明                |
| ------------------- | ---- | ------------------- |
| PERFORMANCE_NONE    | 0    | 无特殊设置。        |
| PERFORMANCE_LOW     | 1    | 低功耗模式。        |
| PERFORMANCE_MEDIUM  | 2    | 功耗-性能均衡模式。 |
| PERFORMANCE_HIGH    | 3    | 高性能模式。        |
| PERFORMANCE_EXTREME | 4    | 极致性能模式。      |

## Priority<sup>12+</sup>

NNRt推理任务优先级枚举。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称            | 值   | 说明           |
| --------------- | ---- | -------------- |
| PRIORITY_NONE   | 0    | 无优先级偏好。 |
| PRIORITY_LOW    | 1    | 低优先级任务。 |
| PRIORITY_MEDIUM | 2    | 中优先级任务。 |
| PRIORITY_HIGH   | 3    | 高优先级任务。 |

## Extension<sup>12+</sup>

定义NNRt设备的扩展信息。

### 属性

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                | 类型        | 只读 | 可选 | 说明             |
| ------------------- | ----------- | ---- | ---- | ---------------- |
| name<sup>12+</sup>  | string      | 否   | 否   | 扩展名称。       |
| value<sup>12+</sup> | ArrayBuffer | 否   | 否   | 包含扩展的内存。 |

## NNRTDeviceDescription<sup>12+</sup>

NNRt设备信息描述，包含设备ID，设备名称等信息。

**系统能力：** SystemCapability.AI.MindSporeLite

### deviceID

deviceID() : bigint

获取NNRt设备ID。

**系统能力：**  SystemCapability.AI.MindSporeLite

**返回值：**

| 类型   | 说明         |
| ------ | ------------ |
| bigint | NNRt设备ID。 |

**示例：** 

```ts
let allDevices = mindSporeLite.getAllNNRTDeviceDescriptions();
if (allDevices == null) {
  console.error('getAllNNRTDeviceDescriptions is NULL.');
}
let context: mindSporeLite.Context = {};
context.target = ["nnrt"];
context.nnrt = {};
for (let i: number = 0; i < allDevices.length; i++) {
  console.info(allDevices[i].deviceID().toString());
}
```

### deviceType

deviceType() : NNRTDeviceType

获取NNRt设备类型。

**系统能力：**  SystemCapability.AI.MindSporeLite

**返回值：**

| 类型                                | 说明           |
| ----------------------------------- | -------------- |
| [NNRTDeviceType](#nnrtdevicetype12) | NNRt设备类型。 |

**示例：** 

```ts
let allDevices = mindSporeLite.getAllNNRTDeviceDescriptions();
if (allDevices == null) {
  console.error('getAllNNRTDeviceDescriptions is NULL.');
}
let context: mindSporeLite.Context = {};
context.target = ["nnrt"];
context.nnrt = {};
for (let i: number = 0; i < allDevices.length; i++) {
  console.info(allDevices[i].deviceType().toString());
}
```

### deviceName

deviceName() : string

获取NNRt设备名称。

**系统能力：**  SystemCapability.AI.MindSporeLite

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| string | NNRt设备名称。 |

**示例：** 

```ts
let allDevices = mindSporeLite.getAllNNRTDeviceDescriptions();
if (allDevices == null) {
  console.error('getAllNNRTDeviceDescriptions is NULL.');
}
let context: mindSporeLite.Context = {};
context.target = ["nnrt"];
context.nnrt = {};
for (let i: number = 0; i < allDevices.length; i++) {
  console.info(allDevices[i].deviceName().toString());
}
```

## NNRTDeviceType<sup>12+</sup>

NNRt设备类型枚举。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                   | 值   | 说明                                |
| ---------------------- | ---- | ----------------------------------- |
| NNRTDEVICE_OTHERS      | 0    | 设备类型不属于以下3种，则属于其它。 |
| NNRTDEVICE_CPU         | 1    | CPU设备。                           |
| NNRTDEVICE_GPU         | 2    | GPU设备。                           |
| NNRTDEVICE_ACCELERATOR | 3    | 特定的加速设备。                    |

## TrainCfg<sup>12+</sup>

端侧训练相关参数的配置文件。

### 属性

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                            | 类型                                      | 只读 | 可选 | 说明                                                         |
| ------------------------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| lossName<sup>12+</sup>          | string[]                                  | 否   | 是   | 损失函数的名称列表。默认值为["loss_fct", "_loss_fn", "SigmoidCrossEntropy"]。 |
| optimizationLevel<sup>12+</sup> | [OptimizationLevel](#optimizationlevel12) | 否   | 是   | 端侧训练的网络优化等级。默认值为O0。                         |

**示例：** 

```ts
let cfg: mindSporeLite.TrainCfg = {};
cfg.lossName = ["loss_fct", "_loss_fn", "SigmoidCrossEntropy"];
cfg.optimizationLevel = mindSporeLite.OptimizationLevel.O0;
```

## OptimizationLevel<sup>12+</sup>

端侧训练的网络优化等级枚举。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称 | 值   | 说明                                                       |
| ---- | ---- | ---------------------------------------------------------- |
| O0   | 0    | 无优化等级。                                               |
| O2   | 2    | 将网络转换为float16, 保持批量归一化层和损失函数为float32。 |
| O3   | 3    | 将网络转换为float16, 包括批量归一化层。                    |
| AUTO | 4    | 根据设备选择优化等级。                                     |


## QuantizationType<sup>12+</sup>

量化类型信息，有效值为0-2。

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称         | 值   | 说明       |
| ------------ | ---- | ---------- |
| NO_QUANT     | 0    | 不做量化。 |
| WEIGHT_QUANT | 1    | 权重量化。 |
| FULL_QUANT   | 2    | 全量化。   |

## Model

模型实例。描述Model对象的属性和方法。

下例API示例中都需先使用[loadModelFromFile()](#mindsporeliteloadmodelfromfile)、[loadModelFromBuffer()](#mindsporeliteloadmodelfrombuffer)、[loadModelFromFd()](#mindsporeliteloadmodelfromfd)中的任一方法获取到Model实例，再通过此实例调用对应方法。

### 属性

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                       | 类型    | 只读 | 可选 | 说明                                                         |
| -------------------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| learningRate<sup>12+</sup> | number  | 否   | 是   | 训练模型的学习率。默认值从加载的模型中读取。                 |
| trainMode<sup>12+</sup>    | boolean | 否   | 是   | 模型是否为训练模式。true表示训练模式，false表示非训练模式。如果是训练模型，trainMode默认是true；如果是推理模型，trainMode默认是false。 |

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
let modelFile = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile).then((mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  console.info(modelInputs[0].name);
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
  let modelFile : string = '/path/to/xxx.ms';
  let mindSporeLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFile(modelFile);
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();

  modelInputs[0].setData(modelBuffer);
  mindSporeLiteModel.predict(modelInputs, (mindSporeLiteTensor : mindSporeLite.MSTensor[]) => {
    let output = new Float32Array(mindSporeLiteTensor[0].getData());
    for (let i = 0; i < output.length; i++) {
      console.info(output[i].toString());
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
  let modelFile = '/path/to/xxx.ms';
  let mindSporeLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFile(modelFile);
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  modelInputs[0].setData(modelBuffer);
  mindSporeLiteModel.predict(modelInputs).then((mindSporeLiteTensor : mindSporeLite.MSTensor[]) => {
    let output = new Float32Array(mindSporeLiteTensor[0].getData());
    for (let i = 0; i < output.length; i++) {
      console.info(output[i].toString());
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
let modelFile = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile).then((mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  let new_dim = new Array([1,32,32,1]);
  mindSporeLiteModel.resize(modelInputs, new_dim);
})
```

### runStep<sup>12+</sup>

runStep(inputs: MSTensor[]): boolean

单步训练模型，仅用于端侧训练。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名    | 类型                      | 必填  | 说明       |
| ------ | ----------------------- | --- | -------- |
| inputs | [MSTensor](#mstensor)[] | 是   | 模型的输入列表。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回单步训练模型是否成功的结果。true表示单步训练模型成功，false表示单步训练模型失败。 |

**示例：** 

```ts
let modelFile = '/path/to/xxx.ms';
mindSporeLite.loadTrainModelFromFile(modelFile).then((mindSporeLiteModel: mindSporeLite.Model) => {
  mindSporeLiteModel.trainMode = true;
  const modelInputs = mindSporeLiteModel.getInputs();
  let ret = mindSporeLiteModel.runStep(modelInputs);
  if (ret == false) {
    console.error('MS_LITE_LOG: runStep failed.')
  }
})
```

### getWeights<sup>12+</sup>

getWeights(): MSTensor[]

获取模型的所有权重，仅用于端侧训练。

**系统能力：** SystemCapability.AI.MindSporeLite

**返回值：**

| 类型                      | 说明         |
| ----------------------- | ---------- |
| [MSTensor](#mstensor)[] | 返回模型的权重张量。 |

**示例：** 

```ts
import { resourceManager } from '@kit.LocalizationKit';

let resMgr: resourceManager.ResourceManager = getContext().getApplicationContext().resourceManager;
let modelFile = 'xxx.ms';
resMgr.getRawFileContent(modelFile).then((modelBuffer) => {
  mindSporeLite.loadTrainModelFromBuffer(modelBuffer.buffer.slice(0)).then((mindSporeLiteModel: mindSporeLite.Model) => {
    mindSporeLiteModel.trainMode = true;
    const weights = mindSporeLiteModel.getWeights();
    for (let i = 0; i < weights.length; i++) {
      let printStr = weights[i].name + ", ";
      printStr += weights[i].shape + ", ";
      printStr += weights[i].dtype + ", ";
      printStr += weights[i].dataSize + ", ";
      printStr += weights[i].getData();
      console.info("MS_LITE weights: ", printStr);
    }
  })
})
```

### updateWeights<sup>12+</sup>

updateWeights(weights: MSTensor[]): boolean

更新模型的权重，仅用于端侧训练。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名  | 类型                    | 必填 | 说明           |
| ------- | ----------------------- | ---- | -------------- |
| weights | [MSTensor](#mstensor)[] | 是   | 权重张量列表。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回是否更新权重成功的结果。true表示更新权重成功，false表示更新权重失败。 |

**示例：** 

```ts
import { resourceManager } from '@kit.LocalizationKit';

let resMgr: resourceManager.ResourceManager = getContext().getApplicationContext().resourceManager;
let modelFile = 'xxx.ms';
resMgr.getRawFileContent(modelFile).then((modelBuffer) => {
  mindSporeLite.loadTrainModelFromBuffer(modelBuffer.buffer.slice(0)).then((mindSporeLiteModel: mindSporeLite.Model) => {
    mindSporeLiteModel.trainMode = true;
    const weights = mindSporeLiteModel.getWeights();
    let ret = mindSporeLiteModel.updateWeights(weights);
    if (ret == false) {
      console.error('MS_LITE_LOG: updateWeights failed.')
    }
  })
})
```

### setupVirtualBatch<sup>12+</sup>

setupVirtualBatch(virtualBatchMultiplier: number, lr: number, momentum: number): boolean

设置虚拟批次用于训练，仅用于端侧训练。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名                 | 类型   | 必填 | 说明                                                 |
| ---------------------- | ------ | ---- | ---------------------------------------------------- |
| virtualBatchMultiplier | number | 是   | 虚拟批次乘法器，当设置值小于1时，表示禁用虚拟batch。 |
| lr                     | number | 是   | 学习率。                                             |
| momentum               | number | 是   | 动量。                                               |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回是否设置虚拟批次成功的结果。true表示设置虚拟批次成功，false表示设置虚拟批次失败。 |

**示例：** 

```ts
import { resourceManager } from '@kit.LocalizationKit';

let resMgr: resourceManager.ResourceManager = getContext().getApplicationContext().resourceManager;
let modelFile = 'xxx.ms';
resMgr.getRawFileContent(modelFile).then((modelBuffer) => {
  mindSporeLite.loadTrainModelFromBuffer(modelBuffer.buffer.slice(0)).then((mindSporeLiteModel: mindSporeLite.Model) => {
    mindSporeLiteModel.trainMode = true;
    let ret = mindSporeLiteModel.setupVirtualBatch(2,-1,-1);
    if (ret == false) {
      console.error('MS_LITE setupVirtualBatch failed.')
    }
  })
})
```

### exportModel<sup>12+</sup>

exportModel(modelFile: string, quantizationType?: QuantizationType, exportInferenceOnly?: boolean, outputTensorName?: string[]): boolean

导出训练模型，仅用于端侧训练。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名              | 类型                                    | 必填 | 说明                                                         |
| ------------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| modelFile           | string                                  | 是   | 导出模型的文件路径。                                         |
| quantizationType    | [QuantizationType](#quantizationtype12) | 否   | 量化类型，默认为NO_QUANT。                                   |
| exportInferenceOnly | boolean                                 | 否   | 是否只导出推理模型。true表示只导出推理模型，false表示导出训练和推理两个模型。默认为true。 |
| outputTensorName    | string[]                                | 否   | 设置导出模型的输出张量的名称。默认为空字符串数组，表示全量导出。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回是否导出训练模型成功的结果。true表示导出训练模型成功，false表示导出训练模型失败。 |

**示例：** 

```ts
let modelFile = '/path/to/xxx.ms';
let newPath = '/newpath/to';
mindSporeLite.loadTrainModelFromFile(modelFile).then((mindSporeLiteModel: mindSporeLite.Model) => {
  mindSporeLiteModel.trainMode = true;
  let ret = mindSporeLiteModel.exportModel(newPath + "/new_model.ms", mindSporeLite.QuantizationType.NO_QUANT, true);
  if (ret == false) {
    console.error('MS_LITE exportModel failed.')
  }
})
```


### exportWeightsCollaborateWithMicro<sup>12+</sup>

exportWeightsCollaborateWithMicro(weightFile: string, isInference?: boolean, enableFp16?: boolean, changeableWeightsName?: string[]): boolean;

导出供**micro推理**使用的模型权重，仅用于端侧训练。

**micro推理**：MindSpore Lite针对MCUs（MicroControllerUnits）部署硬件后端，提供了一种超轻量Micro AI部署解决方案，离线阶段直接将模型生成轻量化代码，不再需要在线解析模型和图编译。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名                | 类型     | 必填 | 说明                                                         |
| --------------------- | -------- | ---- | ------------------------------------------------------------ |
| weightFile            | string   | 是   | 权重文件路径。                                               |
| isInference           | boolean  | 否   | 是否从推理模型中导出权重。true表示从推理模型中导出权重，目前只支持true，默认为true。 |
| enableFp16            | boolean  | 否   | 浮点权重是否以float16格式保存。true表示以float16格式保存，false表示不以float16格式保存。默认为false。 |
| changeableWeightsName | string[] | 否   | 设置可变权重的名称。默认为空字符串数组。                     |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回是否导出供micro推理使用的模型权重成功的结果。true表示导出供micro推理使用的模型权重成功，false表示导出供micro推理使用的模型权重失败。 |

**示例：** 

```ts
let modelFile = '/path/to/xxx.ms';
let microWeight = '/path/to/xxx.bin';
mindSporeLite.loadTrainModelFromFile(modelFile).then((mindSporeLiteModel: mindSporeLite.Model) => {
  let ret = mindSporeLiteModel.exportWeightsCollaborateWithMicro(microWeight);
  if (ret == false) {
    console.error('MSLITE exportWeightsCollaborateWithMicro failed.')
  }
})
```

## MSTensor

模型张量实例。描述MSTensor对象的属性和方法。它与数组和矩阵非常相似，是MindSpore Lite网络运算中的基本数据结构。

下例API示例中都需先使用[getInputs()](#getinputs)获取到MSTensor实例，再通过此实例调用对应方法。

### 属性

**系统能力：**  SystemCapability.AI.MindSporeLite

| 名称       | 类型                  | 只读 | 可选 | 说明                   |
| ---------- | --------------------- | ---- | ---- | ---------------------- |
| name       | string                | 否   | 否   | 张量的名称。           |
| shape      | number[]              | 否   | 否   | 张量的维度数组。       |
| elementNum | number                | 否   | 否   | 张量的维度数组的长度。 |
| dataSize   | number                | 否   | 否   | 张量的数据的长度。     |
| dtype      | [DataType](#datatype) | 否   | 否   | 张量的数据类型。       |
| format     | [Format](#format)     | 否   | 否   | 张量的数据排布方式。   |

**示例：** 

```ts
let modelFile = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile).then((mindSporeLiteModel : mindSporeLite.Model) => {
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  console.info(modelInputs[0].name);
  console.info(modelInputs[0].shape.toString());
  console.info(modelInputs[0].elementNum.toString());
  console.info(modelInputs[0].dtype.toString());
  console.info(modelInputs[0].format.toString());
  console.info(modelInputs[0].dataSize.toString());
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
  let modelFile = '/path/to/xxx.ms';
  let mindSporeLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFile(modelFile);
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  modelInputs[0].setData(inputBuffer);
  mindSporeLiteModel.predict(modelInputs).then((mindSporeLiteTensor : mindSporeLite.MSTensor[]) => {
    let output = new Float32Array(mindSporeLiteTensor[0].getData());
    for (let i = 0; i < output.length; i++) {
      console.info(output[i].toString());
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
  let modelFile = '/path/to/xxx.ms';
  let mindSporeLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFile(modelFile);
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
