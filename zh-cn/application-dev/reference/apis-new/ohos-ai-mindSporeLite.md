# @ohos.ai.mindSporeLite    
MindSpore Lite是一款AI引擎，它提供了面向不同硬件设备AI模型推理的功能，目前已经在图像分类、目标识别、人脸识别、文字识别等应用中广泛使用。  
本模块介绍了MindSpore Lite推理引擎支持模型推理的相关能力。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import mindSporeLite from '@ohos.ai.mindSporeLite'    
```  
    
## loadModelFromFile    
从完整路径加载输入模型用于推理。使用callback异步回调。  
 **调用形式：**     
    
- loadModelFromFile(     model: string,     context?: Context): Promise\<Model>    
起始版本： 10    
- loadModelFromFile(     model: string, callback: Callback\<Model>): void    
起始版本： 10    
- loadModelFromFile(     model: string,     context: Context, callback: Callback\<Model>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| model | string | true | 模型的完整输入路径。  |  
| context | Context | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回模型对象。 |  
| Promise<Model> |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
let model_file : string = '/path/to/xxx.ms';  
mindSporeLite.loadModelFromFile(model_file, (result : mindSporeLite.Model) => {  
  let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();  
  console.log(modelInputs[0].name);  
})    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
let model_file = '/path/to/xxx.ms';  
mindSporeLite.loadModelFromFile(model_file).then((result : mindSporeLite.Model) => {  
  let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();  
  console.log(modelInputs[0].name);  
})    
```    
  
    
## loadModelFromBuffer    
从内存加载输入模型用于推理。使用callback异步回调。  
 **调用形式：**     
    
- loadModelFromBuffer(     model: ArrayBuffer,     context?: Context): Promise\<Model>    
起始版本： 10    
- loadModelFromBuffer(     model: ArrayBuffer, callback: Callback\<Model>): void    
起始版本： 10    
- loadModelFromBuffer(     model: ArrayBuffer,     context: Context, callback: Callback\<Model>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| model | ArrayBuffer | true | 包含模型的内存。 |  
| context | Context | false |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回模型对象。 |  
| Promise<Model> |  |  
    
 **示例代码：**   
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
import resourceManager from '@ohos.resourceManager'  
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
  
let modelName = '/path/to/xxx.ms';  
globalContext.resourceManager.getRawFileContent(modelName).then((buffer : Uint8Array) => {  
  let modelBuffer : ArrayBuffer = buffer.buffer;  
  mindSporeLite.loadModelFromBuffer(modelBuffer, (result : mindSporeLite.Model) => {  
    let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();  
    console.log(modelInputs[0].name);  
  })  
})  
    
```    
  
    
## loadModelFromFd    
从文件描述符加载输入模型用于推理。使用callback异步回调。  
 **调用形式：**     
    
- loadModelFromFd(     model: number,     context?: Context): Promise\<Model>    
起始版本： 10    
- loadModelFromFd(     model: number, callback: Callback\<Model>): void    
起始版本： 10    
- loadModelFromFd(     model: number,     context: Context, callback: Callback\<Model>): void    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| model | number | true | 模型的文件描述符。 |  
| context | Context | false | 运行环境的配置信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回模型对象。 |  
| Promise<Model> |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import fs from '@ohos.file.fs';  
let model_file = '/path/to/xxx.ms';  
let file = fs.openSync(model_file, fs.OpenMode.READ_ONLY);  
mindSporeLite.loadModelFromFd(file.fd, (result : mindSporeLite.Model) => {  
  let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();  
  console.log(modelInputs[0].name);  
})    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import fs from '@ohos.file.fs';  
let model_file = '/path/to/xxx.ms';  
let file = fs.openSync(model_file, fs.OpenMode.READ_ONLY);  
let mindSporeLiteModel : mindSporeLite.Model = await mindSporeLite.loadModelFromFd(file.fd);  
let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();  
console.log(modelInputs[0].name);    
```    
  
    
## Model    
模型实例。描述Model对象的属性和方法。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
### getInputs    
获取模型的输入用于推理。  
 **调用形式：**     
- getInputs(): MSTensor[]  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MSTensor[] | 返回MSTensor对象。 |  
    
 **示例代码：**   
```ts    
let model_file = '/path/to/xxx.ms';  
mindSporeLite.loadModelFromFile(model_file).then((result : mindSporeLite.Model) => {  
  let modelInputs : mindSporeLite.MSTensor[] = result.getInputs();  
  console.log(modelInputs[0].name);  
})    
```    
  
    
### predict    
执行推理模型。使用callback异步回调。需要确保调用时模型对象不被资源回收。  
 **调用形式：**     
    
- predict(inputs: MSTensor[], callback: Callback\<MSTensor[]>): void    
起始版本： 10    
- predict(inputs: MSTensor[]): Promise\<MSTensor[]>    
起始版本： 10  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inputs | MSTensor[] | true | 模型的输入列表。MSTensor对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回MSTensor对象。 |  
| Promise<MSTensor[]> |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import resourceManager from '@ohos.resourceManager'  
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
  
let inputName = 'input_data.bin';  
globalContext.resourceManager.getRawFileContent(inputName).then(async (buffer : Uint8Array) => {  
  let modelBuffer : ArrayBuffer = buffer.buffer;  
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
  
    
 **示例代码2：**   
示例（MSTensor）  
```ts    
import resourceManager from '@ohos.resourceManager'  
import { GlobalContext } from '../GlobalContext';  
import mindSporeLite from '@ohos.ai.mindSporeLite';  
import common from '@ohos.app.ability.common';  
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
重新设置张量大小。  
 **调用形式：**     
- resize(inputs: MSTensor[], dims: Array\<Array\<number>>): boolean  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inputs | MSTensor[] | true | 模型的输入列表。 |  
| dims | Array<Array<number>> | true | 需要修改的目标张量大小。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回是否设置成功的结果。true表示重新设置张量大小成功；false表示重新设置张量大小失败。 |  
    
 **示例代码：**   
```ts    
let model_file = '/path/to/xxx.ms';  
mindSporeLite.loadModelFromFile(model_file).then((mindSporeLiteModel : mindSporeLite.Model) => {  
  let modelInputs : mindSporeLite.MSTensor[] = mindSporeLiteModel.getInputs();  
  let new_dim = new Array([1,32,32,1]);  
  mindSporeLiteModel.resize(modelInputs, new_dim);  
})    
```    
  
    
## Context    
定义运行环境的配置信息。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| target | string[] | false | true |  配置目标后端。可选'cpu'，'nnrt'，默认'cpu'。 |  
| cpu | CpuDevice | false | true | CPU后端设备选项。只有当target包含'cpu'时，才能设置此属性。默认值为CpuDevice各属性默认值。  |  
| nnrt | NNRTDevice | false | true | NNRT后端设备选项。只有当target包含'nnrt'时，才能设置此属性，当前属性为空。  |  
    
## CpuDevice    
CPU后端设备选项。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| threadNum | number | false | true | 设置运行时的线程数，默认值：2。  |  
| threadAffinityMode | ThreadAffinityMode | false | true | 设置运行时的CPU绑核策略模式，默认值为不绑核：mindSporeLite.ThreadAffinityMode.NO_AFFINITIES。 |  
| threadAffinityCoreList | number[] | false | true | 设置运行时的CPU绑核列表，设置绑核策略模式后使能，当绑核策略模式为mindSporeLite.ThreadAffinityMode.NO_AFFINITIES时，绑核列表为空。列表中的数字代表核的序号。默认值：[]。 |  
| precisionMode | string | false | true | 设置是否使能**Float16推理模式**，设置为'preferred_fp16'代表使能半精度推理，其余设置情况均为不支持，默认设置'enforce_fp32'表示不使能半精度推理。 |  
    
## NNRTDevice    
Neural Network Runtime表示神经网络运行时，简称NNRt。作为中间桥梁，连通上层 AI 推理框架和底层加速芯片，实现 AI 模型的跨芯片推理计算。MindSpore Lite 可配置NNRt后端。当前暂未支持。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
## ThreadAffinityMode    
设置运行时的CPU绑核策略模式，有效值为0-2，0为默认不绑核，1为绑大核，2为绑中核。    
    
 **系统能力:**  SystemCapability.AI.MindSporeLite    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NO_AFFINITIES | 0 | 不绑核。 |  
| BIG_CORES_FIRST | 1 | 绑大核优先。 |  
| LITTLE_CORES_FIRST | 2 |  绑中核优先。 |  
    
## MSTensor    
模型张量实例。描述MSTensor对象的属性和方法。它与数组和矩阵非常相似，是MindSpore Lite网络运算中的基本数据结构。  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 张量的名称。默认为null |  
| shape | number[] | false | true | 张量的维度数组。默认为0。 |  
| elementNum | number | false | true | 张量的维度数组的长度。默认为0。 |  
| dataSize | number | false | true | 张量的数据的长度。默认为0。 |  
| dtype | DataType | false | true |  张量的数据类型。默认值为0，代表TYPE_UNKNOWN。  |  
| format | DataType | false | true | 张量的数据排布方式。默认值为-1，代表DEFAULT_FORMAT。 |  
    
### getData    
获取张量的数据。  
 **调用形式：**     
- getData(): ArrayBuffer  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ArrayBuffer | 返回张量的数据指针。 |  
    
 **示例代码：**   
```ts    
import resourceManager from '@ohos.resourceManager'  
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
设置张量的数据。  
 **调用形式：**     
- setData(inputArray: ArrayBuffer): void  
  
 **模型约束：** 此接口仅可在stage模型下使用。  
 **系统能力:**  SystemCapability.AI.MindSporeLite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| inputArray | ArrayBuffer | true | 张量的输入数据缓冲区。 |  
    
 **示例代码：**   
```ts    
import resourceManager from '@ohos.resourceManager'  
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
    
 **系统能力:**  SystemCapability.AI.MindSporeLite    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_UNKNOWN | 0 | 未知类型。 |  
| NUMBER_TYPE_INT8 | 32 | 保持Int8的类型。  |  
| NUMBER_TYPE_INT16 | 33 | 保持Int16的类型。 |  
| NUMBER_TYPE_INT32 | 34 | 保持Int32的类型。  |  
| NUMBER_TYPE_INT64 | 35 | 保持Int64的类型。 |  
| NUMBER_TYPE_UINT8 | 37 | 保持UInt8的类型。 |  
| NUMBER_TYPE_UINT16 | 38 | 保持UInt16的类型。 |  
| NUMBER_TYPE_UINT32 | 39 | 保持UInt32的类型。 |  
| NUMBER_TYPE_UINT64 | 40 | 保持UInt64的类型。  |  
| NUMBER_TYPE_FLOAT16 | 42 | 保持Float16的类型。 |  
| NUMBER_TYPE_FLOAT32 | 43 | 保持Float32的类型。 |  
| NUMBER_TYPE_FLOAT64 | 44 | 保持Float64的类型。  |  
    
## Format    
张量的数据排布方式。    
    
 **系统能力:**  SystemCapability.AI.MindSporeLite    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT_FORMAT | -1 | 未知数据排布方式。 |  
| NCHW | 0 | 数据排布方式为NCHW。  |  
| NHWC | 1 | 数据排布方式为NHWC。 |  
| NHWC4 | 2 | 数据排布方式为NHWC4。 |  
| HWKC | 3 | 数据排布方式为HWKC。 |  
| HWCK | 4 | 数据排布方式为HWCK。 |  
| KCHW | 5 | 数据排布方式为KCHW。 |  
    
 **示例代码：**   
```ts    
import mindSporeLite from '@ohos.ai.mindSporeLite';    
```    
  
