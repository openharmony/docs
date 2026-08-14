# @ohos.ai.mindSporeLite (端侧AI框架)

<!--Kit: MindSpore Lite Kit-->
<!--Subsystem: AI-->
<!--Owner: @zhuguodong8-->
<!--Designer: @zhuguodong8; @jjfeing-->
<!--Tester: @principal87-->
<!--Adviser: @ge-yafang-->

MindSpore Lite是一个轻量化、高性能的端侧AI引擎，提供了标准的模型推理和训练接口，内置通用硬件高性能算子库，支持Neural Network Runtime Kit使能AI专用芯片加速推理，助力打造全场景智能应用。

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

从完整路径加载输入模型，用于CPU推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                             |
| -------- | ------------------------- | ---- | ------------------------------------------------ |
| model    | string                    | 是   | 模型的完整输入路径。字符串长度限制跟随文件系统。 |
| callback | Callback<[Model](#model)> | 是   | 回调函数，用于返回模型对象。当检查到模型输入为空时，加载失败。                         |

**示例：** 

```ts
let modelFile: string = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile, (mindSporeLiteModel: mindSporeLite.Model) => {
  let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  if (modelInputs == null) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Result: null`);
  } else if (modelInputs.length === 0) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Input count: 0`);
  } else {
    console.info(`Succeeded in getting model inputs. Model file: ${modelFile}, Input name: ${modelInputs[0].name}`);
  }
})
```
## mindSporeLite.loadModelFromFile

loadModelFromFile(model: string, context: Context, callback: Callback&lt;Model&gt;): void

从完整路径加载输入模型用于推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | string                              | 是   | 模型的完整输入路径。字符串长度限制跟随文件系统。 |
| context | [Context](#context) | 是 | 运行环境的配置信息。 |
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。回调过程中若检查模型输入为空，回调失败。 |

**示例：** 

```ts
let context: mindSporeLite.Context = {};
context.target = ['cpu'];
let modelFile: string = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile, context, (mindSporeLiteModel: mindSporeLite.Model) => {
  let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  if (modelInputs == null) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Context: ${JSON.stringify(context)}, Result: null`);
  } else if (modelInputs.length === 0) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Context: ${JSON.stringify(context)}, Input count: 0`);
  } else {
    console.info(`Succeeded in getting model inputs. Model file: ${modelFile}, Input name: ${modelInputs[0].name}`);
  }
})
```
## mindSporeLite.loadModelFromFile

loadModelFromFile(model: string, context?: Context): Promise&lt;Model&gt;

从完整路径加载输入模型用于推理。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名  | 类型                | 必填 | 说明                                             |
| ------- | ------------------- | ---- | ------------------------------------------------ |
| model   | string              | 是   | 模型的完整输入路径。字符串长度限制跟随文件系统。 |
| context | [Context](#context) | 否   | 运行环境的配置信息。默认使用CpuDevice初始化。    |

**返回值：**

| 类型                      | 说明                         |
| ------------------------- | ---------------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

**示例：** 

```ts
let modelFile = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile).then((mindSporeLiteModel: mindSporeLite.Model) => {
  let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  if (modelInputs == null) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Result: null`);
  } else if (modelInputs.length === 0) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Input count: 0`);
  } else {
    console.info(`Succeeded in getting model inputs. Model file: ${modelFile}, Input name: ${modelInputs[0].name}`);
  }
}).catch((error: Error) => {
  console.error(`Failed to load model from file. Model file: ${modelFile}, Error: ${error.message}`);
});
```
## mindSporeLite.loadModelFromBuffer

loadModelFromBuffer(model: ArrayBuffer, callback: Callback&lt;Model&gt;): void

从内存加载输入模型，用于CPU推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                      | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ------------------------ |
| model    | ArrayBuffer               | 是   | 包含模型的内存。         |
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。回调过程中若检查模型输入为空，回调失败。 |

**示例：** 

```ts
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let modelFile = 'xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(modelFile)
  .then((buffer: Uint8Array) => {
    let modelBuffer = buffer.buffer;
    mindSporeLite.loadModelFromBuffer(modelBuffer, (mindSporeLiteModel: mindSporeLite.Model) => {
      let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
      if (modelInputs == null || modelInputs.length === 0) {
        console.error(`Failed to get model inputs from buffer. Model file: ${modelFile}, Buffer size: ${modelBuffer.byteLength}`);
      } else {
        console.info(`Succeeded in getting model inputs from buffer. Model file: ${modelFile}, Input name: ${modelInputs[0].name}`);
      }
    })
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read model file from resources. File name: ${modelFile}, Error code: ${error.code}, Error message: ${error.message}`);
  });
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
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。回调过程中若检查模型输入为空，回调失败。 |

**示例：** 

```ts
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let modelFile = 'xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
let context: mindSporeLite.Context = {};
context.target = ['cpu'];

globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(modelFile)
  .then((buffer: Uint8Array) => {
    let modelBuffer = buffer.buffer;
    mindSporeLite.loadModelFromBuffer(modelBuffer, context, (mindSporeLiteModel: mindSporeLite.Model) => {
      let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
      if (modelInputs == null || modelInputs.length === 0) {
        console.error(`Failed to get model inputs from buffer. Model file: ${modelFile}, Context: ${JSON.stringify(context)}, Buffer size: ${modelBuffer.byteLength}`);
      } else {
        console.info(`Succeeded in getting model inputs from buffer. Model file: ${modelFile}, Input name: ${modelInputs[0].name}`);
      }
    })
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read model file from resources. File name: ${modelFile}, Error code: ${error.code}, Error message: ${error.message}`);
  });
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
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let modelFile = 'xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(modelFile)
  .then((buffer: Uint8Array) => {
    let modelBuffer = buffer.buffer;
    mindSporeLite.loadModelFromBuffer(modelBuffer).then((mindSporeLiteModel: mindSporeLite.Model) => {
      let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
      if (modelInputs == null || modelInputs.length === 0) {
        console.error(`Failed to get model inputs from buffer. Model file: ${modelFile}, Buffer size: ${modelBuffer.byteLength}`);
      } else {
        console.info(`Succeeded in getting model inputs from buffer. Model file: ${modelFile}, Input name: ${modelInputs[0].name}`);
      }
    }).catch((error: Error) => {
      console.error(`Failed to load model from buffer. Model file: ${modelFile}, Buffer size: ${modelBuffer.byteLength}, Error: ${error.message}`);
    });
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read model file from resources. File name: ${modelFile}, Error code: ${error.code}, Error message: ${error.message}`);
  });
```
## mindSporeLite.loadModelFromFd

loadModelFromFd(model: number, callback: Callback&lt;Model&gt;): void

从文件描述符加载输入模型，用于CPU推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | number                         | 是   | 模型的文件描述符。跟随文件系统返回fd值传入。 |
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。回调过程中若检查模型输入为空，回调失败。 |

**示例：** 

```ts
import { fileIo } from '@kit.CoreFileKit';

let modelFile = '/path/to/xxx.ms';
let file = fileIo.openSync(modelFile, fileIo.OpenMode.READ_ONLY);
mindSporeLite.loadModelFromFd(file.fd, (mindSporeLiteModel: mindSporeLite.Model) => {
  let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  if (modelInputs == null) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, File descriptor: ${file.fd}, Result: null`);
  } else if (modelInputs.length === 0) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, File descriptor: ${file.fd}, Input count: 0`);
  } else {
    console.info(`Succeeded in getting model inputs. Model file: ${modelFile}, Input name: ${modelInputs[0].name}`);
  }
})
```
## mindSporeLite.loadModelFromFd

loadModelFromFd(model: number, context: Context, callback: Callback&lt;Model&gt;): void

从文件描述符加载输入模型用于推理。使用callback异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                                | 必填 | 说明                   |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | number                   | 是   | 模型的文件描述符。跟随文件系统返回fd值传入。 |
| context | [Context](#context) | 是  | 运行环境的配置信息。 |
| callback | Callback<[Model](#model)> | 是   | 回调函数。返回模型对象。回调过程中若检查模型输入为空，回调失败。 |

**示例：** 

```ts
import { fileIo } from '@kit.CoreFileKit';

let modelFile = '/path/to/xxx.ms';
let context: mindSporeLite.Context = {};
context.target = ['cpu'];
let file = fileIo.openSync(modelFile, fileIo.OpenMode.READ_ONLY);
mindSporeLite.loadModelFromFd(file.fd, context, (mindSporeLiteModel: mindSporeLite.Model) => {
  let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  if (modelInputs == null) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, File descriptor: ${file.fd}, Context: ${JSON.stringify(context)}, Result: null`);
  } else if (modelInputs.length === 0) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, File descriptor: ${file.fd}, Context: ${JSON.stringify(context)}, Input count: 0`);
  } else {
    console.info(`Succeeded in getting model inputs. Model file: ${modelFile}, Input name: ${modelInputs[0].name}`);
  }
})
```
## mindSporeLite.loadModelFromFd

loadModelFromFd(model: number, context?: Context): Promise&lt;Model&gt;

从文件描述符加载输入模型用于推理。使用Promise异步函数。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名  | 类型                | 必填 | 说明                                          |
| ------- | ------------------- | ---- | --------------------------------------------- |
| model   | number              | 是   | 模型的文件描述符。跟随文件系统返回fd值传入。  |
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
  if (modelInputs == null) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, File descriptor: ${file.fd}, Result: null`);
  } else if (modelInputs.length === 0) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, File descriptor: ${file.fd}, Input count: 0`);
  } else {
    console.info(`Succeeded in getting model inputs. Model file: ${modelFile}, Input name: ${modelInputs[0].name}`);
  }
}).catch((error: Error) => {
  console.error(`Failed to load model from file descriptor. Model file: ${modelFile}, File descriptor: ${file.fd}, Error: ${error.message}`);
});
```

## mindSporeLite.loadTrainModelFromFile<sup>12+</sup>

loadTrainModelFromFile(model: string, trainCfg?: TrainCfg, context?: Context): Promise&lt;Model&gt;

根据路径加载训练模型文件。使用Promise异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                             |
| -------- | ----------------------- | ---- | ------------------------------------------------ |
| model    | string                  | 是   | 模型的完整输入路径。字符串长度限制跟随文件系统。 |
| trainCfg | [TrainCfg](#traincfg12) | 否   | 模型训练配置。默认值为TrainCfg各属性默认值。     |
| context  | [Context](#context)     | 否   | 运行环境的配置信息。默认使用CpuDevice初始化。    |

**返回值：**

| 类型                       | 说明                   |
| ------------------------ | -------------------- |
| Promise<[Model](#model)> | Promise对象。返回Model对象。 |

**示例：** 

```ts
let modelFile = '/path/to/xxx.ms';
mindSporeLite.loadTrainModelFromFile(modelFile).then((mindSporeLiteModel: mindSporeLite.Model) => {
  let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  if (modelInputs == null) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Result: null`);
  } else if (modelInputs.length === 0) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Input count: 0`);
  } else {
    console.info(`Succeeded in getting model inputs. Model file: ${modelFile}, Input name: ${modelInputs[0].name}`);
  }
}).catch((error: Error) => {
  console.error(`Failed to load train model from file. Model file: ${modelFile}, Error: ${error.message}`);
});
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
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let modelFile = 'xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(modelFile)
  .then((buffer: Uint8Array) => {
    let modelBuffer = buffer.buffer;
    mindSporeLite.loadTrainModelFromBuffer(modelBuffer).then((mindSporeLiteModel: mindSporeLite.Model) => {
      console.info(`Succeeded in loading train model. Train mode: ${mindSporeLiteModel.trainMode}`);
    }).catch((error: Error) => {
      console.error(`Failed to load train model from buffer. Model file: ${modelFile}, Buffer size: ${modelBuffer.byteLength}, Error: ${error.message}`);
    });
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read model file from resources. File name: ${modelFile}, Error code: ${error.code}, Error message: ${error.message}`);
  });
```

## mindSporeLite.loadTrainModelFromFd<sup>12+</sup>

loadTrainModelFromFd(model: number, trainCfg?: TrainCfg, context?: Context): Promise&lt;Model&gt;

从文件描述符加载训练模型文件。使用Promise异步回调。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                             |
| -------- | ----------------------- | ---- | ------------------------------------------------ |
| model    | number                  | 是   | 训练模型的文件描述符。跟随文件系统返回fd值传入。 |
| trainCfg | [TrainCfg](#traincfg12) | 否   | 模型训练配置。默认值为TrainCfg各属性默认值。     |
| context  | [Context](#context)     | 否   | 运行环境的配置信息。默认使用CpuDevice初始化。    |

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
  console.info(`Succeeded in loading train model. Train mode: ${mindSporeLiteModel.trainMode}`);
}).catch((error: Error) => {
  console.error(`Failed to load train model from file descriptor. Model file: ${modelFile}, File descriptor: ${file.fd}, Error: ${error.message}`);
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
try {
  let allDevices = mindSporeLite.getAllNNRTDeviceDescriptions();
  if (allDevices == null || allDevices.length === 0) {
    console.error('Failed to get NNRT device descriptions. Result: null or empty array');
  } else {
    console.info(`Succeeded in getting NNRT device descriptions. Device count: ${allDevices.length}`);
  }
} catch (error) {
  console.error(`Failed to get NNRT device descriptions. Error: ${error}`);
}
```

## Context

定义运行环境的配置信息。

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

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                   | 类型                                      | 只读 | 可选 | 说明                                                         |
| ---------------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| threadNum              | number                                    | 否   | 是   | 设置运行时的线程数，默认值：2。                              |
| threadAffinityMode     | [ThreadAffinityMode](#threadaffinitymode) | 否   | 是   | 设置运行时的CPU绑核策略模式，默认值为不绑核：mindSporeLite.ThreadAffinityMode.NO_AFFINITIES。 |
| threadAffinityCoreList | number[]                                  | 否   | 是   | 设置运行时的CPU绑核列表，设置绑核策略模式后使能，当绑核策略模式为mindSporeLite.ThreadAffinityMode.NO_AFFINITIES时，绑核列表为空。列表中的数字代表核的序号。默认值：[]。 |
| precisionMode          | string                                    | 否   | 是   | 设置是否使能**Float16推理模式**，设置为'preferred_fp16'代表使能半精度推理，其余设置值均不使能半精度推理，默认设置'enforce_fp32'表示不使能半精度推理。 |

**Float16推理模式**：  表示使用半精度（Float16）进行推理计算，相比全精度（Float32）可减少内存占用并提升推理速度。

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

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                | 类型        | 只读 | 可选 | 说明             |
| ------------------- | ----------- | ---- | ---- | ---------------- |
| name  | string      | 否   | 否   | 扩展名称。       |
| value | ArrayBuffer | 否   | 否   | 包含扩展的内存。 |

## NNRTDeviceDescription<sup>12+</sup>

NNRt设备信息描述，包含设备ID、设备名称等信息。

**系统能力：** SystemCapability.AI.MindSporeLite

### deviceID<sup>12+</sup>

deviceID() : bigint

获取NNRt设备ID。

**系统能力：**  SystemCapability.AI.MindSporeLite

**返回值：**

| 类型   | 说明         |
| ------ | ------------ |
| bigint | NNRt设备ID。 |

**示例：** 

```ts
let context: mindSporeLite.Context = {};
context.target = ["nnrt"];
context.nnrt = {};
let allDevices = mindSporeLite.getAllNNRTDeviceDescriptions();
if (allDevices == null || allDevices.length === 0) {
  console.error(`Failed to get NNRT device descriptions. Context: ${JSON.stringify(context)}, Result: null or empty`);
} else {
  console.info(`Succeeded in getting NNRT device descriptions. Device count: ${allDevices.length}`);
    for (let i: number = 0; i < allDevices.length; i++) {
      console.info(`Device ${i} ID: ${allDevices[i].deviceID().toString()}`);
    }
}
```

### deviceType<sup>12+</sup>

deviceType() : NNRTDeviceType

获取NNRt设备类型。

**系统能力：**  SystemCapability.AI.MindSporeLite

**返回值：**

| 类型                                | 说明           |
| ----------------------------------- | -------------- |
| [NNRTDeviceType](#nnrtdevicetype12) | NNRt设备类型。 |

**示例：** 

```ts
let context: mindSporeLite.Context = {};
context.target = ["nnrt"];
context.nnrt = {};
let allDevices = mindSporeLite.getAllNNRTDeviceDescriptions();
if (allDevices == null || allDevices.length === 0) {
  console.error(`Failed to get NNRT device descriptions. Context: ${JSON.stringify(context)}, Result: null or empty`);
} else {
  console.info(`Succeeded in getting NNRT device descriptions. Device count: ${allDevices.length}`);
  for (let i: number = 0; i < allDevices.length; i++) {
    console.info(`Device ${i} type: ${allDevices[i].deviceType().toString()}`);
  }
}
```

### deviceName<sup>12+</sup>

deviceName() : string

获取NNRt设备名称。

**系统能力：**  SystemCapability.AI.MindSporeLite

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| string | NNRt设备名称。 |

**示例：** 

```ts
let context: mindSporeLite.Context = {};
context.target = ["nnrt"];
context.nnrt = {};
let allDevices = mindSporeLite.getAllNNRTDeviceDescriptions();
if (allDevices == null || allDevices.length === 0) {
  console.error(`Failed to get NNRT device descriptions. Context: ${JSON.stringify(context)}, Result: null or empty`);
} else {
  console.info(`Succeeded in getting NNRT device descriptions. Device count: ${allDevices.length}`);
  for (let i: number = 0; i < allDevices.length; i++) {
    console.info(`Device ${i} name: ${allDevices[i].deviceName()}`);
  }
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

**系统能力：** SystemCapability.AI.MindSporeLite

| 名称                            | 类型                                      | 只读 | 可选 | 说明                                                         |
| ------------------------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| lossName         | string[]                                  | 否   | 是   |  损失函数的名称列表，用于端侧训练时标识模型中的损失函数节点。默认值为["loss_fct", "_loss_fn", "SigmoidCrossEntropy"]。 |
| optimizationLevel | [OptimizationLevel](#optimizationlevel12) | 否   | 是   | 端侧训练的网络优化等级。默认值为O0。                         |

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
| O2   | 2    | 将网络转换为Float16，保持批量归一化层和损失函数为Float32。 |
| O3   | 3    | 将网络转换为Float16，包括批量归一化层。                    |
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

下列API示例中都需先使用[loadModelFromFile()](#mindsporeliteloadmodelfromfile)、[loadModelFromBuffer()](#mindsporeliteloadmodelfrombuffer)、[loadModelFromFd()](#mindsporeliteloadmodelfromfd)中的任一方法获取到Model实例，再通过此实例调用对应方法。

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
| [MSTensor](#mstensor)[] | 返回MSTensor对象列表。 |

**示例：** 

```ts
let modelFile = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile).then((mindSporeLiteModel: mindSporeLite.Model) => {
  let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  if (modelInputs == null) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Result: null`);
  } else if (modelInputs.length === 0) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Input count: 0`);
  } else {
    console.info(`Succeeded in getting model inputs. Model file: ${modelFile}, Input name: ${modelInputs[0].name}, Total inputs: ${modelInputs.length}`);
  }
}).catch((error: Error) => {
  console.error(`Failed to load model. Model file: ${modelFile}, Error: ${error.message}`);
});
```
### predict

predict(inputs: MSTensor[], callback: Callback&lt;MSTensor[]&gt;): void

执行推理模型。使用callback异步回调。需要确保调用时模型对象不被资源回收。

**系统能力：**  SystemCapability.AI.MindSporeLite

**参数：**

| 参数名 | 类型                    | 必填 | 说明                       |
| ------ | ----------------------- | ---- | -------------------------- |
| inputs | [MSTensor](#mstensor)[] | 是   | 模型的输入列表。MSTensor对象。 |
| callback | Callback<[MSTensor](#mstensor)[]> | 是   | 回调函数。返回MSTensor对象列表。 |

**示例：** 

```ts
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

// 预处理后的模型输入数据文件名
let inputName = 'input_data.bin';
let modelFile: string = '/path/to/xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(inputName)
  .then(async (buffer: Uint8Array) => {
    let inputBuffer = buffer.buffer;
    console.info(`Succeeded in reading input data. File name: ${inputName}, Buffer size: ${inputBuffer.byteLength}`);
    
    let mindSporeLiteModel: mindSporeLite.Model = await mindSporeLite.loadModelFromFile(modelFile);
    console.info(`Succeeded in loading model. Model file: ${modelFile}`);
    
    let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
    if (modelInputs == null || modelInputs.length === 0) {
      console.error(`Failed to get model inputs. Model file: ${modelFile}, Input count: ${modelInputs ? modelInputs.length : 0}`);
      return;
    }

    modelInputs[0].setData(inputBuffer);
    console.info(`Succeeded in setting input data. Input tensor: ${modelInputs[0].name}`);
    
    mindSporeLiteModel.predict(modelInputs, (mindSporeLiteTensor: mindSporeLite.MSTensor[]) => {
      if (mindSporeLiteTensor == null || mindSporeLiteTensor.length === 0) {
        console.error(`Failed to get prediction output. Model file: ${modelFile}, Output count: ${mindSporeLiteTensor ? mindSporeLiteTensor.length : 0}`);
      } else {
        let output = new Float32Array(mindSporeLiteTensor[0].getData());
        console.info(`Succeeded in prediction. Output length: ${output.length}`);
        for (let i = 0; i < Math.min(5, output.length); i++) {
          console.info(`Output[${i}]: ${output[i].toString()}`);
        }
      }
    })
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read input data. File name: ${inputName}, Error code: ${error.code}, Error message: ${error.message}`);
  });
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
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

// 预处理后的模型输入数据文件名
let inputName = 'input_data.bin';
let modelFile = '/path/to/xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(inputName)
  .then(async (buffer: Uint8Array) => {
    let inputBuffer = buffer.buffer;
    console.info(`Succeeded in reading input data. File name: ${inputName}, Buffer size: ${inputBuffer.byteLength}`);
    
    let mindSporeLiteModel: mindSporeLite.Model = await mindSporeLite.loadModelFromFile(modelFile);
    console.info(`Succeeded in loading model. Model file: ${modelFile}`);
    
    let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
    if (modelInputs == null || modelInputs.length === 0) {
      console.error(`Failed to get model inputs. Model file: ${modelFile}, Input count: ${modelInputs ? modelInputs.length : 0}`);
      return;
    }
    
    modelInputs[0].setData(inputBuffer);
    console.info(`Succeeded in setting input data. Input tensor: ${modelInputs[0].name}`);
    
    mindSporeLiteModel.predict(modelInputs).then((mindSporeLiteTensor: mindSporeLite.MSTensor[]) => {
      if (mindSporeLiteTensor == null || mindSporeLiteTensor.length === 0) {
        console.error(`Failed to get prediction output. Model file: ${modelFile}, Output count: ${mindSporeLiteTensor ? mindSporeLiteTensor.length : 0}`);
      } else {
        let output = new Float32Array(mindSporeLiteTensor[0].getData());
        console.info(`Succeeded in prediction. Output length: ${output.length}`);
        for (let i = 0; i < Math.min(5, output.length); i++) {
          console.info(`Output[${i}]: ${output[i].toString()}`);
        }
      }
    }).catch((error: Error) => {
      console.error(`Failed to execute prediction. Model file: ${modelFile}, Error: ${error.message}`);
    });
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read input data. File name: ${inputName}, Error code: ${error.code}, Error message: ${error.message}`);
  });
```

### resize

resize(inputs: MSTensor[], dims: Array&lt;Array&lt;number&gt;&gt;): boolean

重新设置张量大小。 它允许在运行时动态修改模型输入形状，无需重新加载模型。常用于处理不同尺寸的图片、动态调整批次大小、或通过降低分辨率来加速推理。它只改变输入形状而保持模型权重不变，让一个模型支持多种输入配置，节省存储并提高灵活性。

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
mindSporeLite.loadModelFromFile(modelFile).then((mindSporeLiteModel: mindSporeLite.Model) => {
  let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  let originalShape = modelInputs[0].shape;
  console.info(`Original input shape: [${originalShape.join(', ')}]`);
  
  let newDim = [[1, 32, 32, 1]];
  let ret = mindSporeLiteModel.resize(modelInputs, newDim);
  
  if (ret === false) {
    console.error(`Failed to resize model inputs. Model file: ${modelFile}, Original shape: [${originalShape.join(', ')}], Target shape: [${newDim[0].join(', ')}]`);
  } else {
    console.info(`Succeeded in resizing model inputs. Model file: ${modelFile}, Original shape: [${originalShape.join(', ')}], New shape: [${modelInputs[0].shape.join(', ')}]`);
  }
}).catch((error: Error) => {
  console.error(`Failed to load model. Model file: ${modelFile}, Error: ${error.message}`);
});
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
  console.info(`Succeeded in setting train mode. Model file: ${modelFile}, Train mode: ${mindSporeLiteModel.trainMode}`);
  
  const modelInputs = mindSporeLiteModel.getInputs();
  if (modelInputs == null || modelInputs.length === 0) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}, Input count: ${modelInputs ? modelInputs.length : 0}`);
    return;
  }
  
  let ret = mindSporeLiteModel.runStep(modelInputs);
  if (ret === false) {
    console.error(`Failed to run training step. Model file: ${modelFile}, Input count: ${modelInputs.length}`);
  } else {
    console.info(`Succeeded in running training step. Model file: ${modelFile}`);
  }
}).catch((error: Error) => {
  console.error(`Failed to load train model. Model file: ${modelFile}, Error: ${error.message}`);
});
```

### getWeights<sup>12+</sup>

getWeights(): MSTensor[]

获取模型的所有权重，仅用于端侧训练。

**系统能力：** SystemCapability.AI.MindSporeLite

**返回值：**

| 类型                      | 说明         |
| ----------------------- | ---------- |
| [MSTensor](#mstensor)[] | 返回模型的权重张量列表。 |

**示例：** 

```ts
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let modelFile = 'xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(modelFile)
  .then((modelBuffer: Uint8Array) => {
    mindSporeLite.loadTrainModelFromBuffer(modelBuffer.buffer.slice(0))
      .then((mindSporeLiteModel: mindSporeLite.Model) => {
        mindSporeLiteModel.trainMode = true;
        console.info(`Succeeded in setting train mode. Model file: ${modelFile}`);
        
        const weights = mindSporeLiteModel.getWeights();
        if (weights == null || weights.length === 0) {
          console.error(`Failed to get model weights. Model file: ${modelFile}, Weights count: ${weights ? weights.length : 0}`);
        } else {
          console.info(`Succeeded in getting model weights. Model file: ${modelFile}, Weights count: ${weights.length}`);
          for (let i = 0; i < Math.min(3, weights.length); i++) {
            console.info(`Weight[${i}]: name=${weights[i].name}, shape=[${weights[i].shape.join(', ')}], dtype=${weights[i].dtype}, dataSize=${weights[i].dataSize}`);
          }
        }
      })
      .catch((error: Error) => {
        console.error(`Failed to load train model from buffer. Model file: ${modelFile}, Buffer size: ${modelBuffer.byteLength}, Error: ${error.message}`);
      });
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read model file from resources. File name: ${modelFile}, Error code: ${error.code}, Error message: ${error.message}`);
  });
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
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let modelFile = 'xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(modelFile)
  .then((modelBuffer: Uint8Array) => {
    mindSporeLite.loadTrainModelFromBuffer(modelBuffer.buffer.slice(0))
      .then((mindSporeLiteModel: mindSporeLite.Model) => {
        mindSporeLiteModel.trainMode = true;
        console.info(`Succeeded in setting train mode. Model file: ${modelFile}`);
        
        const weights = mindSporeLiteModel.getWeights();
        if (weights == null || weights.length === 0) {
          console.error(`Failed to get model weights. Model file: ${modelFile}, Weights count: ${weights ? weights.length : 0}`);
          return;
        }
        
        let ret = mindSporeLiteModel.updateWeights(weights);
        if (ret === false) {
          console.error(`Failed to update model weights. Model file: ${modelFile}, Weights count: ${weights.length}`);
        } else {
          console.info(`Succeeded in updating model weights. Model file: ${modelFile}, Weights count: ${weights.length}`);
        }
      })
      .catch((error: Error) => {
        console.error(`Failed to load train model from buffer. Model file: ${modelFile}, Buffer size: ${modelBuffer.byteLength}, Error: ${error.message}`);
      });
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read model file from resources. File name: ${modelFile}, Error code: ${error.code}, Error message: ${error.message}`);
  });
```

### setupVirtualBatch<sup>12+</sup>

setupVirtualBatch(virtualBatchMultiplier: number, lr: number, momentum: number): boolean

设置虚拟批次用于训练，仅用于端侧训练。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名                 | 类型   | 必填 | 说明                                                 |
| ---------------------- | ------ | ---- | ---------------------------------------------------- |
| virtualBatchMultiplier | number | 是   | 虚拟批次乘法器，只能为整数。取值小于1时：表示禁用虚拟batch；取值为1时：等同于禁用虚拟batch；取值大于1时：表示将一个大batch分割成N个小batch。 |
| lr                     | number | 是   | 学习率，控制每次参数更新时，沿着梯度方向移动的步长。取值为-1时，使用默认学习率；取值小于0且不为-1时，表示无效值，会导致设置失败；取值为0时，固定当前参数；取值大于0时，自定义学习率。 |
| momentum               | number | 是   | 动量，用于加速训练并减少梯度震荡。取值为-1时，表示使用系统默认的动量值，在不确定具体值时的选择；取值为0时，表示不使用动量优化，退化为纯梯度下降算法；取值在0.5~0.9时，能够在训练速度和稳定性之间取得较好的平衡；取值在0.9~0.99时，能够显著加速训练过程，适合凸优化问题；取值小于0且不为-1时，表示无效值，会导致虚拟批次设置失败。                                              |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回是否设置虚拟批次成功的结果。true表示设置虚拟批次成功，false表示设置虚拟批次失败。 |

**示例：** 

```ts
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let modelFile = 'xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(modelFile)
  .then((modelBuffer: Uint8Array) => {
    mindSporeLite.loadTrainModelFromBuffer(modelBuffer.buffer.slice(0))
      .then((mindSporeLiteModel: mindSporeLite.Model) => {
        mindSporeLiteModel.trainMode = true;
        console.info(`Succeeded in setting train mode. Model file: ${modelFile}`);
        
        let virtualBatchMultiplier = 2;
        let lr = -1;
        let momentum = -1;
        
        let ret = mindSporeLiteModel.setupVirtualBatch(virtualBatchMultiplier, lr, momentum);
        if (ret === false) {
          console.error(`Failed to setup virtual batch. Model file: ${modelFile}, Virtual batch multiplier: ${virtualBatchMultiplier}, Learning rate: ${lr}, Momentum: ${momentum}`);
        } else {
          console.info(`Succeeded in setting up virtual batch. Model file: ${modelFile}, Virtual batch multiplier: ${virtualBatchMultiplier}`);
        }
      })
      .catch((error: Error) => {
        console.error(`Failed to load train model from buffer. Model file: ${modelFile}, Buffer size: ${modelBuffer.byteLength}, Error: ${error.message}`);
      });
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read model file from resources. File name: ${modelFile}, Error code: ${error.code}, Error message: ${error.message}`);
  });
```

### exportModel<sup>12+</sup>

exportModel(modelFile: string, quantizationType?: QuantizationType, exportInferenceOnly?: boolean, outputTensorName?: string[]): boolean

导出训练模型，仅用于端侧训练。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名              | 类型                                    | 必填 | 说明                                                         |
| ------------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| modelFile           | string                                  | 是   | 导出模型的文件路径。字符串长度限制跟随文件系统。             |
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
let exportPath = newPath + "/new_model.ms";
mindSporeLite.loadTrainModelFromFile(modelFile).then((mindSporeLiteModel: mindSporeLite.Model) => {
  mindSporeLiteModel.trainMode = true;
  console.info(`Succeeded in setting train mode. Model file: ${modelFile}`);
  
  let ret = mindSporeLiteModel.exportModel(exportPath, mindSporeLite.QuantizationType.NO_QUANT, true);
  if (ret === false) {
    console.error(`Failed to export model. Source: ${modelFile}, Target: ${exportPath}, Quantization type: NO_QUANT, Inference only: true`);
  } else {
    console.info(`Succeeded in exporting model. Source: ${modelFile}, Target: ${exportPath}`);
  }
}).catch((error: Error) => {
  console.error(`Failed to load train model. Model file: ${modelFile}, Error: ${error.message}`);
});
```

### exportWeightsCollaborateWithMicro<sup>12+</sup>

exportWeightsCollaborateWithMicro(weightFile: string, isInference?: boolean, enableFp16?: boolean, changeableWeightsName?: string[]): boolean

导出供micro推理使用的模型权重，仅用于端侧训练。

**micro推理**：一种MindSpore Lite针对MCUs（MicroControllerUnits）硬件的超轻量AI部署方案。该方案在离线阶段直接将模型转换为轻量化代码，无需在设备端在线解析模型和编译图。

**系统能力：** SystemCapability.AI.MindSporeLite

**参数：**

| 参数名                | 类型     | 必填 | 说明                                                         |
| --------------------- | -------- | ---- | ------------------------------------------------------------ |
| weightFile            | string   | 是   | 权重文件路径。字符串长度限制跟随文件系统。                   |
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
  if (ret === false) {
    console.error(`Failed to export weights for micro. Model file: ${modelFile}, Target weight file: ${microWeight}`);
  } else {
    console.info(`Succeeded in exporting weights for micro. Model file: ${modelFile}, Target weight file: ${microWeight}`);
  }
}).catch((error: Error) => {
  console.error(`Failed to load train model. Model file: ${modelFile}, Error: ${error.message}`);
});
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
| elementNum | number                | 否   | 否   | 张量的元素总数。       |
| dataSize   | number                | 否   | 否   | 张量的数据的长度。     |
| dtype      | [DataType](#datatype) | 否   | 否   | 张量的数据类型。       |
| format     | [Format](#format)     | 否   | 否   | 张量的数据排布方式。   |

**示例：** 

```ts
let modelFile = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(modelFile).then((mindSporeLiteModel: mindSporeLite.Model) => {
  let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
  if (modelInputs == null || modelInputs.length === 0) {
    console.error(`Failed to get model inputs. Model file: ${modelFile}`);
    return;
  }
  
  let tensor = modelInputs[0];
  console.info(`Succeeded in getting model inputs. Input name: ${tensor.name}, Shape: [${tensor.shape.join(', ')}], Element num: ${tensor.elementNum}, Dtype: ${tensor.dtype}, Format: ${tensor.format}, Data size: ${tensor.dataSize}`);
}).catch((error: Error) => {
  console.error(`Failed to load model. Model file: ${modelFile}, Error: ${error.message}`);
});
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
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

// 预处理后的模型输入数据文件名
let inputName = 'input_data.bin';
let modelFile = '/path/to/xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(inputName)
  .then(async (buffer: Uint8Array) => {
    let inputBuffer = buffer.buffer;
    console.info(`Succeeded in reading input data. File name: ${inputName}, Buffer size: ${inputBuffer.byteLength}`);
    
    let mindSporeLiteModel: mindSporeLite.Model = await mindSporeLite.loadModelFromFile(modelFile);
    console.info(`Succeeded in loading model. Model file: ${modelFile}`);
    
    let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
    if (modelInputs == null || modelInputs.length === 0) {
      console.error(`Failed to get model inputs. Model file: ${modelFile}`);
      return;
    }
    
    modelInputs[0].setData(inputBuffer);
    console.info(`Succeeded in setting input data. Input tensor: ${modelInputs[0].name}`);
    
    mindSporeLiteModel.predict(modelInputs).then((mindSporeLiteTensor: mindSporeLite.MSTensor[]) => {
      if (mindSporeLiteTensor == null || mindSporeLiteTensor.length === 0) {
        console.error(`Failed to get prediction output. Model file: ${modelFile}`);
      } else {
        let output = new Float32Array(mindSporeLiteTensor[0].getData());
        console.info(`Succeeded in prediction. Output length: ${output.length}`);
        for (let i = 0; i < Math.min(5, output.length); i++) {
          console.info(`Output[${i}]: ${output[i].toString()}`);
        }
      }
    }).catch((error: Error) => {
      console.error(`Failed to execute prediction. Model file: ${modelFile}, Error: ${error.message}`);
    });
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read input data. File name: ${inputName}, Error code: ${error.code}, Error message: ${error.message}`);
  });
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
import { common } from '@kit.AbilityKit';
import { UIContext } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

// 预处理后的模型输入数据文件名
let inputName = 'input_data.bin';
let modelFile = '/path/to/xxx.ms';
let globalContext = new UIContext().getHostContext() as common.UIAbilityContext;
globalContext.getApplicationContext()
  .resourceManager
  .getRawFileContent(inputName)
  .then(async (buffer: Uint8Array) => {
    let inputBuffer = buffer.buffer;
    console.info(`Succeeded in reading input data. File name: ${inputName}, Buffer size: ${inputBuffer.byteLength}`);
    
    let mindSporeLiteModel: mindSporeLite.Model = await mindSporeLite.loadModelFromFile(modelFile);
    console.info(`Succeeded in loading model. Model file: ${modelFile}`);
    
    let modelInputs: mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();
    if (modelInputs == null || modelInputs.length === 0) {
      console.error(`Failed to get model inputs. Model file: ${modelFile}`);
      return;
    }
    
    modelInputs[0].setData(inputBuffer);
    console.info(`Succeeded in setting input data. Input tensor: ${modelInputs[0].name}, Buffer size: ${inputBuffer.byteLength}`);
  })
  .catch((error: BusinessError) => {
    console.error(`Failed to read input data. File name: ${inputName}, Error code: ${error.code}, Error message: ${error.message}`);
  });
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
