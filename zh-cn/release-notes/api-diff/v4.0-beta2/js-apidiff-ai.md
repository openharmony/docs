| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：mindSporeLite;<br>方法or属性：function loadModelFromFile(<br>    model: string,<br>    context?: Context): Promise\<Model>;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：mindSporeLite;<br>方法or属性：function loadModelFromFile(<br>    model: string, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：mindSporeLite;<br>方法or属性：function loadModelFromFile(<br>    model: string,<br>    context: Context, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：mindSporeLite;<br>方法or属性：function loadModelFromBuffer(<br>    model: ArrayBuffer,<br>    context?: Context): Promise\<Model>;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：mindSporeLite;<br>方法or属性：function loadModelFromBuffer(<br>    model: ArrayBuffer, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：mindSporeLite;<br>方法or属性：function loadModelFromBuffer(<br>    model: ArrayBuffer,<br>    context: Context, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：mindSporeLite;<br>方法or属性：function loadModelFromFd(<br>    model: number,<br>    context?: Context): Promise\<Model>;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：mindSporeLite;<br>方法or属性：function loadModelFromFd(<br>    model: number, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：mindSporeLite;<br>方法or属性：function loadModelFromFd(<br>    model: number,<br>    context: Context, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Model;<br>方法or属性：getInputs(): MSTensor[];|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Model;<br>方法or属性：predict(inputs: MSTensor[], callback: Callback\<MSTensor[]>): void;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Model;<br>方法or属性：predict(inputs: MSTensor[]): Promise\<MSTensor[]>;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Model;<br>方法or属性：resize(inputs: MSTensor[], dims: Array\<Array\<number>>): boolean;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Context;<br>方法or属性：target?: string[];|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Context;<br>方法or属性：cpu?: CpuDevice;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Context;<br>方法or属性：nnrt?: NNRTDevice;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：CpuDevice;<br>方法or属性：threadNum?: number;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：CpuDevice;<br>方法or属性：threadAffinityMode?: ThreadAffinityMode;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：CpuDevice;<br>方法or属性：threadAffinityCoreList?: number[];|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：CpuDevice;<br>方法or属性：precisionMode?: string;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：ThreadAffinityMode;<br>方法or属性：NO_AFFINITIES = 0|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：ThreadAffinityMode;<br>方法or属性：BIG_CORES_FIRST = 1|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：ThreadAffinityMode;<br>方法or属性：LITTLE_CORES_FIRST = 2|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：MSTensor;<br>方法or属性：name: string;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：MSTensor;<br>方法or属性：shape: number[];|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：MSTensor;<br>方法or属性：elementNum: number;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：MSTensor;<br>方法or属性：dataSize: number;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：MSTensor;<br>方法or属性：dtype: DataType;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：MSTensor;<br>方法or属性：format: Format;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：MSTensor;<br>方法or属性：getData(): ArrayBuffer;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：MSTensor;<br>方法or属性：setData(inputArray: ArrayBuffer): void;|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：TYPE_UNKNOWN = 0|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_INT8 = 32|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_INT16 = 33|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_INT32 = 34|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_INT64 = 35|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_UINT8 = 37|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_UINT16 = 38|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_UINT32 = 39|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_UINT64 = 40|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_FLOAT16 = 42|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_FLOAT32 = 43|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：DataType;<br>方法or属性：NUMBER_TYPE_FLOAT64 = 44|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Format;<br>方法or属性：DEFAULT_FORMAT = -1|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Format;<br>方法or属性：NCHW = 0|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Format;<br>方法or属性：NHWC = 1|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Format;<br>方法or属性：NHWC4 = 2|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Format;<br>方法or属性：HWKC = 3|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Format;<br>方法or属性：HWCK = 4|@ohos.ai.mindSporeLite.d.ts|
|新增|NA|类名：Format;<br>方法or属性：KCHW = 5|@ohos.ai.mindSporeLite.d.ts|
