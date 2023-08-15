| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFile(<br>    model: string,<br>    context?: Context): Promise\<Model>;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFile(<br>    model: string, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFile(<br>    model: string,<br>    context: Context, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromBuffer(<br>    model: ArrayBuffer,<br>    context?: Context): Promise\<Model>;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromBuffer(<br>    model: ArrayBuffer, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromBuffer(<br>    model: ArrayBuffer,<br>    context: Context, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFd(<br>    model: number,<br>    context?: Context): Promise\<Model>;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFd(<br>    model: number, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: mindSporeLite;<br>Method or attribute name: function loadModelFromFd(<br>    model: number,<br>    context: Context, callback: Callback\<Model>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Model;<br>Method or attribute name: getInputs(): MSTensor[];|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Model;<br>Method or attribute name: predict(inputs: MSTensor[], callback: Callback\<MSTensor[]>): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Model;<br>Method or attribute name: predict(inputs: MSTensor[]): Promise\<MSTensor[]>;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Model;<br>Method or attribute name: resize(inputs: MSTensor[], dims: Array\<Array\<number>>): boolean;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Context;<br>Method or attribute name: target?: string[];|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Context;<br>Method or attribute name: cpu?: CpuDevice;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Context;<br>Method or attribute name: nnrt?: NNRTDevice;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: CpuDevice;<br>Method or attribute name: threadNum?: number;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: CpuDevice;<br>Method or attribute name: threadAffinityMode?: ThreadAffinityMode;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: CpuDevice;<br>Method or attribute name: threadAffinityCoreList?: number[];|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: CpuDevice;<br>Method or attribute name: precisionMode?: string;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: ThreadAffinityMode;<br>Method or attribute name: NO_AFFINITIES = 0|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: ThreadAffinityMode;<br>Method or attribute name: BIG_CORES_FIRST = 1|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: ThreadAffinityMode;<br>Method or attribute name: LITTLE_CORES_FIRST = 2|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: name: string;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: shape: number[];|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: elementNum: number;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: dataSize: number;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: dtype: DataType;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: format: Format;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: getData(): ArrayBuffer;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: MSTensor;<br>Method or attribute name: setData(inputArray: ArrayBuffer): void;|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: TYPE_UNKNOWN = 0|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_INT8 = 32|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_INT16 = 33|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_INT32 = 34|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_INT64 = 35|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_UINT8 = 37|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_UINT16 = 38|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_UINT32 = 39|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_UINT64 = 40|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_FLOAT16 = 42|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_FLOAT32 = 43|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: DataType;<br>Method or attribute name: NUMBER_TYPE_FLOAT64 = 44|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: DEFAULT_FORMAT = -1|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: NCHW = 0|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: NHWC = 1|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: NHWC4 = 2|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: HWKC = 3|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: HWCK = 4|@ohos.ai.mindSporeLite.d.ts|
|Added|NA|Class name: Format;<br>Method or attribute name: KCHW = 5|@ohos.ai.mindSporeLite.d.ts|
