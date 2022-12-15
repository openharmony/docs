# 分布式软总线子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，分布式软总线子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.rpc | Ashmem | readFromAshmem(size: number, offset: number): number[]; | 新增 |
| ohos.rpc | Ashmem | writeToAshmem(buf: number[], size: number, offset: number): boolean; | 新增 |
| ohos.rpc | Ashmem | setProtection(protectionType: number): boolean; | 新增 |
| ohos.rpc | Ashmem | mapReadOnlyAshmem(): boolean; | 新增 |
| ohos.rpc | Ashmem | mapReadAndWriteAshmem(): boolean; | 新增 |
| ohos.rpc | Ashmem | mapAshmem(mapType: number): boolean; | 新增 |
| ohos.rpc | Ashmem | getAshmemSize(): number; | 新增 |
| ohos.rpc | Ashmem | unmapAshmem(): void; | 新增 |
| ohos.rpc | Ashmem | closeAshmem(): void; | 新增 |
| ohos.rpc | Ashmem | static createAshmemFromExisting(ashmem: Ashmem): Ashmem; | 新增 |
| ohos.rpc | Ashmem | static createAshmem(name: string, size: number): Ashmem; | 新增 |
| ohos.rpc | Ashmem | PROT_WRITE = 2; | 新增 |
| ohos.rpc | Ashmem | PROT_READ = 1; | 新增 |
| ohos.rpc | Ashmem | PROT_NONE = 0; | 新增 |
| ohos.rpc | Ashmem | PROT_EXEC = 4; | 新增 |
| ohos.rpc | IPCSkeleton | static getCallingTokenId(): number; | 新增 |
| ohos.rpc | SendRequestResult | reply: MessageParcel; | 新增 |
| ohos.rpc | SendRequestResult | data: MessageParcel; | 新增 |
| ohos.rpc | SendRequestResult | code: number; | 新增 |
| ohos.rpc | SendRequestResult | errCode: number; | 新增 |
| ohos.rpc | MessageParcel | readRawData(size: number): number[]; | 新增 |
| ohos.rpc | MessageParcel | writeRawData(rawData: number[], size: number): boolean; | 新增 |
| ohos.rpc | MessageParcel | getRawDataCapacity(): number; | 新增 |
| ohos.rpc | MessageParcel | readAshmem(): Ashmem; | 新增 |
| ohos.rpc | MessageParcel | writeAshmem(ashmem: Ashmem): boolean; | 新增 |
| ohos.rpc | MessageParcel | readFileDescriptor(): number; | 新增 |
| ohos.rpc | MessageParcel | writeFileDescriptor(fd: number): boolean; | 新增 |
| ohos.rpc | MessageParcel | containFileDescriptors(): boolean; | 新增 |
| ohos.rpc | MessageParcel | static dupFileDescriptor(fd: number) :number; | 新增 |
| ohos.rpc | MessageParcel | static closeFileDescriptor(fd: number): void; | 新增 |
| ohos.rpc | MessageParcel | readRemoteObjectArray(objects: IRemoteObject[]): void;<br>readRemoteObjectArray(): IRemoteObject[]; | 新增 |
| ohos.rpc | MessageParcel | readSequenceableArray(sequenceableArray: Sequenceable[]): void; | 新增 |
| ohos.rpc | MessageParcel | writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean; | 新增 |
| ohos.rpc | MessageParcel | readException(): void; | 新增 |
| ohos.rpc | MessageParcel | writeNoException(): void; | 新增 |
