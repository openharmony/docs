# @ohos.ai.mindSporeLite (Inference)

MindSpore Lite is an AI engine that implements AI model inference for different hardware devices. It has been used in a wide range of fields, such as image classification, target recognition, facial recognition, and character recognition.
The **mindSporeLite** module provides APIs for the MindSpore Lite inference engine to implement model inference.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version. Unless otherwise stated, the MindSpore model is used in the sample code.
>

## Modules to Import
```js
import mindSporeLite from '@ohos.ai.mindSporeLite';
```

## Context

Defines the configuration information of the running environment.

### Attributes

**System capability**: SystemCapability.AI.MindSporeLite


| Name  | Type                     | Readable| Writable| Description                                                        |
| ------ | ------------------------- | ---- | ---- | ------------------------------------------------------------ |
| target | string[]                  | Yes  | Yes  | Target backend. The value can be **cpu** or **nnrt**. The default value is **cpu**.                |
| cpu    | [CpuDevice](#cpudevice)   | Yes  | Yes  | CPU backend device option. Set this parameter set only when **target** is set to **cpu**. The default value is the combination of the default value of each **CpuDevice** option.|
| nnrt   | [NNRTDevice](#nnrtdevice) | Yes  | Yes  | NNRt backend device option. Set this parameter set only when **target** is set to **nnrt**. Currently, this parameter is empty.|

**Example**

```js
let context: mindSporeLite.Context = {};
context.target = ['cpu','nnrt'];
```

## CpuDevice

Defines the CPU backend device option.

### Attributes

**System capability**: SystemCapability.AI.MindSporeLite

| Name                  | Type                                     | Readable| Writable| Description                                                        |
| ---------------------- | ----------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| threadNum              | number                                    | Yes  | Yes  | Number of runtime threads. The default value is **2**.                             |
| threadAffinityMode     | [ThreadAffinityMode](#threadaffinitymode) | Yes  | Yes  | Affinity mode for binding runtime threads to CPU cores. The default value is **mindSporeLite.ThreadAffinityMode.NO_AFFINITIES**.|
| threadAffinityCoreList | number[]                                  | Yes  | Yes  | List of CPU cores bound to runtime threads. Set this parameter only when **threadAffinityMode** is set. If **threadAffinityMode** is set to **mindSporeLite.ThreadAffinityMode.NO_AFFINITIES**, this parameter is empty. The number in the list indicates the SN of the CPU core. The default value is **[]**.|
| precisionMode          | string                                    | Yes  | Yes  | Whether to enable the Float16 inference mode. The value **preferred_fp16** means to enable half-precision inference and the default value **enforce_fp32** means to disable half-precision inference. Other settings are not supported.|

**Float16 inference mode**: a mode that uses half-precision inference. Float16 uses 16 bits to represent a number and therefore it is also called half-precision.

**Example**

```js
let context: mindSporeLite.Context = {};
context.cpu = {};
context.target = ['cpu'];
context.cpu.threadAffinityMode = 0;
context.cpu.precisionMode = 'preferred_fp16';
context.cpu.threadAffinityCoreList = [0, 1, 2];
```

## NNRTDevice

Represents an NNRt device. Neural Network Runtime (NNRt) is a bridge that connects the upper-layer AI inference framework to the bottom-layer acceleration chip to implement cross-chip inference and computing of AI models. An NNRt backend can be configured for MindSpore Lite. Currently, this API is not supported.

**System capability**: SystemCapability.AI.MindSporeLite

## ThreadAffinityMode

Specifies the affinity mode for binding runtime threads to CPU cores.

**System capability**: SystemCapability.AI.MindSporeLite

| Name              | Value  | Description        |
| ------------------ | ---- | ------------ |
| NO_AFFINITIES      | 0    | No affinities.    |
| BIG_CORES_FIRST    | 1    | Big cores first.|
| LITTLE_CORES_FIRST | 2    | Medium cores first.|

## mindSporeLite.loadModelFromFile

loadModelFromFile(model: string, callback: Callback&lt;Model&gt;): void

Loads the input model from the full path for model inference. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name  | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| model    | string                    | Yes  | Complete path of the input model.    |
| callback | Callback<[Model](#model)> | Yes  | Callback used to return the result, which is a **Model** object.|

**Example**

```js
let model_file = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file, (result) => {
  const modelInputs = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromFile

loadModelFromFile(model: string, context: Context, callback: Callback&lt;Model&gt;): void

Loads the input model from the full path for model inference. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name  | Type                               | Mandatory| Description                  |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | string                              | Yes  | Complete path of the input model.  |
| context | [Context](#context) | Yes| Configuration information of the running environment.|
| callback | Callback<[Model](#model)> | Yes  | Callback used to return the result, which is a **Model** object.|

**Example**

```js
let context: mindSporeLite.Context = {};
context = {'target': ['cpu']};
let model_file = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file, context, (result) => {
  const modelInputs = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromFile

loadModelFromFile(model: string, context?: Context): Promise&lt;Model&gt;

Loads the input model from the full path for model inference. This API uses a promise to return the result.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name | Type               | Mandatory| Description                |
| ------- | ------------------- | ---- | -------------------- |
| model   | string              | Yes  | Complete path of the input model.|
| context | [Context](#context) | No  | Configuration information of the running environment.|

**Return value**

| Type                     | Description                        |
| ------------------------- | ---------------------------- |
| Promise<[Model](#model)> | Promise used to return the result, which is a **Model** object.|

**Example**

```js
let model_file = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file).then((result) => {
  const modelInputs = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromBuffer

loadModelFromBuffer(model: ArrayBuffer, callback: Callback&lt;Model&gt;): void

Loads the input model from the memory for inference. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name  | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| model    | ArrayBuffer               | Yes  | Memory that contains the input model.        |
| callback | Callback<[Model](#model)> | Yes  | Callback used to return the result, which is a **Model** object.|

**Example**

```js
import resourceManager from '@ohos.resourceManager'
let modelName = '/path/to/xxx.ms';
let syscontext = globalThis.context;
syscontext.resourceManager.getRawFileContent(modelName).then((buffer) => {
  let modelBuffer = buffer;
  mindSporeLite.loadModelFromBuffer(modelBuffer.buffer, (result) => {
  	const modelInputs = result.getInputs();
  	console.log(modelInputs[0].name);
  })
}).catch(error => {
  console.error('Failed to get buffer, error code: ${error.code},message:${error.message}.');
})
```
## mindSporeLite.loadModelFromBuffer

loadModelFromBuffer(model: ArrayBuffer, context: Context, callback: Callback&lt;Model&gt;): void

Loads the input model from the memory for inference. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name  | Type                               | Mandatory| Description                  |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | ArrayBuffer                   | Yes  | Memory that contains the input model.|
| context | [Context](#context) | Yes | Configuration information of the running environment.|
| callback | Callback<[Model](#model)> | Yes  | Callback used to return the result, which is a **Model** object.|

**Example**

```js
import resourceManager from '@ohos.resourceManager'
let modelName = '/path/to/xxx.ms';
let syscontext = globalThis.context;
syscontext.resourceManager.getRawFileContent(modelName).then((error,buffer) => {
  let modelBuffer = buffer;
  let context: mindSporeLite.Context = {};
  context = {'target': ['cpu']};
  mindSporeLite.loadModelFromBuffer(modelBuffer.buffer, context, (result) => {
    const modelInputs = result.getInputs();
    console.log(modelInputs[0].name);
  })  
}).catch(error => {
  console.error('Failed to get buffer, error code: ${error.code},message:${error.message}.');
})
```
## mindSporeLite.loadModelFromBuffer

loadModelFromBuffer(model: ArrayBuffer, context?: Context): Promise&lt;Model&gt;

Loads the input model from the memory for inference. This API uses a promise to return the result.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name | Type               | Mandatory| Description                |
| ------- | ------------------- | ---- | -------------------- |
| model   | ArrayBuffer         | Yes  | Memory that contains the input model.    |
| context | [Context](#context) | No  | Configuration information of the running environment.|

**Return value**

| Type                           | Description                        |
| ------------------------------- | ---------------------------- |
| Promise<[Model](#model)> | Promise used to return the result, which is a **Model** object.|

**Example**

```js
import resourceManager from '@ohos.resourceManager'
let modelName = '/path/to/xxx.ms';
let syscontext = globalThis.context;
syscontext.resourceManager.getRawFileContent(modelName).then((buffer) => {
  let modelBuffer = buffer;
  mindSporeLite.loadModelFromBuffer(modelBuffer.buffer).then((result) => {
    const modelInputs = result.getInputs();
    console.log(modelInputs[0].name);
  })  
}).catch(error => {
  console.error('Failed to get buffer, error code: ${error.code},message:${error.message}.');
})
```
## mindSporeLite.loadModelFromFd

loadModelFromFd(model: number, callback: Callback&lt;Model&gt;): void

Loads the input model based on the specified file descriptor for inference. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name  | Type                               | Mandatory| Description                  |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | number                         | Yes  | File descriptor of the input model.|
| callback | Callback<[Model](#model)> | Yes  | Callback used to return the result, which is a **Model** object.|

**Example**

```js
import fs from '@ohos.file.fs';
let model_file = '/path/to/xxx.ms';
let file = fs.openSync(model_file, fs.OpenMode.READ_ONLY);
mindSporeLite.loadModelFromFd(file.fd, (result) => {
  const modelInputs = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromFd

loadModelFromFd(model: number, context: Context, callback: Callback&lt;Model&gt;): void

Loads the input model based on the specified file descriptor for inference. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name  | Type                               | Mandatory| Description                  |
| -------- | ----------------------------------- | ---- | ---------------------- |
| model    | number                   | Yes  | File descriptor of the input model.|
| context | [Context](#context) | Yes | Configuration information of the running environment.|
| callback | Callback<[Model](#model)> | Yes  | Callback used to return the result, which is a **Model** object.|

**Example**

```js
import fs from '@ohos.file.fs';
let model_file = '/path/to/xxx.ms';
let context : mindSporeLite.Context = {};
context = {'target': ['cpu']};
let file = fs.openSync(model_file, fs.OpenMode.READ_ONLY);
mindSporeLite.loadModelFromFd(file.fd, context, (result) => {
  const modelInputs = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## mindSporeLite.loadModelFromFd

loadModelFromFd(model: number, context?: Context): Promise&lt; Model&gt;

Loads the input model based on the specified file descriptor for inference. This API uses a promise to return the result.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name | Type               | Mandatory| Description                |
| ------- | ------------------- | ---- | -------------------- |
| model   | number              | Yes  | File descriptor of the input model.  |
| context | [Context](#context) | No  | Configuration information of the running environment.|

**Return value**

| Type                     | Description                        |
| ------------------------- | ---------------------------- |
| Promise<[Model](#model)> | Promise used to return the result, which is a **Model** object.|

**Example**

```js
import fs from '@ohos.file.fs';
let model_file = '/path/to/xxx.ms';
let file = fs.openSync(model_file, fs.OpenMode.READ_ONLY);
let mindSporeLiteModel = await mindSporeLite.loadModelFromFd(file.fd);
mindSporeLite.loadModelFromFd(file.fd).then((result) => {
  const modelInputs = result.getInputs();
  console.log(modelInputs[0].name);
})
```
## Model

Represents a **Model** instance, with properties and APIs defined.

In the following sample code, you first need to use [loadModelFromFile()](#mindsporeliteloadmodelfromfile), [loadModelFromBuffer()](#mindsporeliteloadmodelfrombuffer), or [loadModelFromFd()](#mindsporeliteloadmodelfromfd) to obtain a **Model** instance before calling related APIs.

### getInputs

getInputs(): MSTensor[]

Obtains the model input for inference.

**System capability**: SystemCapability.AI.MindSporeLite

**Return value**

| Type                   | Description              |
| ----------------------- | ------------------ |
| [MSTensor](#mstensor)[] | **MSTensor** object.|

**Example**

```js
let model_file = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file).then((result) => {
  const modelInputs = result.getInputs();
  console.log(modelInputs[0].name);
})
```
### predict

predict(inputs: MSTensor[], callback: Callback&lt;MSTensor[]&gt;): void

Executes the inference model. This API uses an asynchronous callback to return the result. Ensure that the model object is not reclaimed when being invoked.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name| Type                   | Mandatory| Description                      |
| ------ | ----------------------- | ---- | -------------------------- |
| inputs | [MSTensor](#mstensor)[] | Yes  | Model input, which is an **MSTensor** object.|
| callback | Callback<[MSTensor](#mstensor)[]> | Yes  | Callback used to return the result, **MSTensor** object.|

**Example**

```js
import resourceManager from '@ohos.resourceManager'
let inputName = 'input_data.bin';
let syscontext = globalThis.context;
syscontext.resourceManager.getRawFileContent(inputName).then(async (buffer) => {
  let inputBuffer = buffer;
  let model_file = '/path/to/xxx.ms';
  let mindSporeLiteModel = await mindSporeLite.loadModelFromFile(model_file);
  const modelInputs = mindSporeLiteModel.getInputs();
  modelInputs[0].setData(inputBuffer.buffer);
  mindSporeLiteModel.predict(modelInputs, (result) => {
    let output = new Float32Array(result[0].getData());
    for (let i = 0; i < output.length; i++) {
      console.log(output[i].toString());
    }
  })
})
```
### predict

predict(inputs: MSTensor[]): Promise&lt;MSTensor[]&gt;

Executes the inference model. This API uses a promise to return the result. Ensure that the model object is not reclaimed when being invoked.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name| Type                   | Mandatory| Description                      |
| ------ | ----------------------- | ---- | -------------------------- |
| inputs | [MSTensor](#mstensor)[] | Yes  | Model input, which is an **MSTensor** object.|

**Return value**

| Type                   | Description              |
| ----------------------- | ------------------ |
| [MSTensor](#mstensor)[] | **MSTensor** object.|

**Example**

```js
import resourceManager from '@ohos.resourceManager'
let inputName = 'input_data.bin';
let syscontext = globalThis.context;
syscontext.resourceManager.getRawFileContent(inputName).then(async (buffer) => {
  let inputBuffer = buffer;
  let model_file = '/path/to/xxx.ms';
  let mindSporeLiteModel = await mindSporeLite.loadModelFromFile(model_file);
  const modelInputs = mindSporeLiteModel.getInputs();
  modelInputs[0].setData(inputBuffer.buffer);
  mindSporeLiteModel.predict(modelInputs).then((result) => {
    let output = new Float32Array(result[0].getData());
    for (let i = 0; i < output.length; i++) {
      console.log(output[i].toString());
    }
  })
})
```

### resize

resize(inputs: MSTensor[], dims: Array&lt;Array&lt;number&gt;&gt;): boolean

Resets the tensor size.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name| Type                 | Mandatory| Description                         |
| ------ | --------------------- | ---- | ----------------------------- |
| inputs | [MSTensor](#mstensor)[]            | Yes  | Model input, which is an **MSTensor** object.   |
| dims   | Array&lt;Array&lt;number&gt;&gt; | Yes  | Target tensor size.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Result indicating whether the setting is successful. The value **true** indicates that the tensor size is successfully reset, and the value **false** indicates the opposite.|

**Example**

```js
let model_file = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file).then((mindSporeLiteModel) => {
  const modelInputs = mindSporeLiteModel.getInputs();
  let new_dim = new Array([1,32,32,1]);
  mindSporeLiteModel.resize(modelInputs, new_dim);
})
```

## MSTensor

Represents an **MSTensor** instance, with properties and APIs defined. It is a special data structure similar to arrays and matrices. It is the basic data structure used in MindSpore Lite network operations.

In the following sample code, you first need to use [getInputs()](#getinputs) to obtain an **MSTensor** instance before calling related APIs.

### Attributes

**System capability**: SystemCapability.AI.MindSporeLite

| Name      | Type                 | Readable| Writable| Description                                                |
| ---------- | --------------------- | ---- | ---- | ---------------------------------------------------- |
| name       | string                | Yes  | Yes  | Tensor name. The default value is **null**.                              |
| shape      | number[]              | Yes  | Yes  | Tensor dimension array. The default value is **0**.                           |
| elementNum | number                | Yes  | Yes  | Length of the tensor dimension array. The default value is **0**.                     |
| dataSize   | number                | Yes  | Yes  | Length of tensor data. The default value is **0**.                         |
| dtype      | [DataType](#datatype) | Yes  | Yes  | Tensor data type. The default value is **0**, indicating **TYPE_UNKNOWN**.       |
| format     | [Format](#format)     | Yes  | Yes  | Tensor data format. The default value is **-1**, indicating **DEFAULT_FORMAT**.|

**Example**

```js
let model_file = '/path/to/xxx.ms';
mindSporeLite.loadModelFromFile(model_file).then((mindSporeLiteModel) => {
  const modelInputs = mindSporeLiteModel.getInputs();
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

Obtains tensor data.

**System capability**: SystemCapability.AI.MindSporeLite

**Return value**

| Type       | Description                |
| ----------- | -------------------- |
| ArrayBuffer | Pointer to the tensor data.|

**Example**

```js
import resourceManager from '@ohos.resourceManager'
let inputName = 'input_data.bin';
let syscontext = globalThis.context;
syscontext.resourceManager.getRawFileContent(inputName).then(async (buffer) => {
  let inputBuffer = buffer;
  let model_file = '/path/to/xxx.ms';
  let mindSporeLiteModel = await mindSporeLite.loadModelFromFile(model_file);
  const modelInputs = mindSporeLiteModel.getInputs();
  modelInputs[0].setData(inputBuffer.buffer);
  mindSporeLiteModel.predict(modelInputs).then((result) => {
    let output = new Float32Array(result[0].getData());
    for (let i = 0; i < output.length; i++) {
      console.log(output[i].toString());
    }
  })
})
```

### setData

setData(inputArray: ArrayBuffer): void

Sets the tensor data.

**System capability**: SystemCapability.AI.MindSporeLite

**Parameters**

| Name    | Type       | Mandatory| Description                  |
| ---------- | ----------- | ---- | ---------------------- |
| inputArray | ArrayBuffer | Yes  | Input data buffer of the tensor.|

**Example**

```js
import resourceManager from '@ohos.resourceManager'
let inputName = 'input_data.bin';
let syscontext = globalThis.context;
syscontext.resourceManager.getRawFileContent(inputName).then(async (buffer) => {
  let inputBuffer = buffer;
  let model_file = '/path/to/xxx.ms';
  let mindSporeLiteModel = await mindSporeLite.loadModelFromFile(model_file);
  const modelInputs = mindSporeLiteModel.getInputs();
  modelInputs[0].setData(inputBuffer.buffer);
})
```

## DataType

Tensor data type.

**System capability**: SystemCapability.AI.MindSporeLite

| Name               | Value  | Description               |
| ------------------- | ---- | ------------------- |
| TYPE_UNKNOWN        | 0    | Unknown type.         |
| NUMBER_TYPE_INT8    | 32   | Int8 type.   |
| NUMBER_TYPE_INT16   | 33   | Int16 type.  |
| NUMBER_TYPE_INT32   | 34   | Int32 type.  |
| NUMBER_TYPE_INT64   | 35   | Int64 type.  |
| NUMBER_TYPE_UINT8   | 37   | UInt8 type.  |
| NUMBER_TYPE_UINT16  | 38   | UInt16 type. |
| NUMBER_TYPE_UINT32  | 39   | UInt32 type. |
| NUMBER_TYPE_UINT64  | 40   | UInt64 type. |
| NUMBER_TYPE_FLOAT16 | 42   | Float16 type.|
| NUMBER_TYPE_FLOAT32 | 43   | Float32 type.|
| NUMBER_TYPE_FLOAT64 | 44   | Float64 type.|

## Format

Enumerates tensor data formats.

**System capability**: SystemCapability.AI.MindSporeLite

| Name          | Value  | Description                 |
| -------------- | ---- | --------------------- |
| DEFAULT_FORMAT | -1   | Unknown data format.   |
| NCHW           | 0    | NCHW format. |
| NHWC           | 1    | NHWC format. |
| NHWC4          | 2    | NHWC4 format.|
| HWKC           | 3    | HWKC format. |
| HWCK           | 4    | HWCK format. |
| KCHW           | 5    | KCHW format. |
