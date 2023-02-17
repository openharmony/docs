# JS API Changes of the DSoftBus Subsystem

The table below lists the APIs changes of the DSoftBus subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.rpc | Ashmem | readFromAshmem(size: number, offset: number): number[]; | Added|
| ohos.rpc | Ashmem | writeToAshmem(buf: number[], size: number, offset: number): boolean; | Added|
| ohos.rpc | Ashmem | setProtection(protectionType: number): boolean; | Added|
| ohos.rpc | Ashmem | mapReadOnlyAshmem(): boolean; | Added|
| ohos.rpc | Ashmem | mapReadAndWriteAshmem(): boolean; | Added|
| ohos.rpc | Ashmem | mapAshmem(mapType: number): boolean; | Added|
| ohos.rpc | Ashmem | getAshmemSize(): number; | Added|
| ohos.rpc | Ashmem | unmapAshmem(): void; | Added|
| ohos.rpc | Ashmem | closeAshmem(): void; | Added|
| ohos.rpc | Ashmem | static createAshmemFromExisting(ashmem: Ashmem): Ashmem; | Added|
| ohos.rpc | Ashmem | static createAshmem(name: string, size: number): Ashmem; | Added|
| ohos.rpc | Ashmem | PROT_WRITE = 2; | Added|
| ohos.rpc | Ashmem | PROT_READ = 1; | Added|
| ohos.rpc | Ashmem | PROT_NONE = 0; | Added|
| ohos.rpc | Ashmem | PROT_EXEC = 4; | Added|
| ohos.rpc | IPCSkeleton | static getCallingTokenId(): number; | Added|
| ohos.rpc | SendRequestResult | reply: MessageParcel; | Added|
| ohos.rpc | SendRequestResult | data: MessageParcel; | Added|
| ohos.rpc | SendRequestResult | code: number; | Added|
| ohos.rpc | SendRequestResult | errCode: number; | Added|
| ohos.rpc | MessageParcel | readRawData(size: number): number[]; | Added|
| ohos.rpc | MessageParcel | writeRawData(rawData: number[], size: number): boolean; | Added|
| ohos.rpc | MessageParcel | getRawDataCapacity(): number; | Added|
| ohos.rpc | MessageParcel | readAshmem(): Ashmem; | Added|
| ohos.rpc | MessageParcel | writeAshmem(ashmem: Ashmem): boolean; | Added|
| ohos.rpc | MessageParcel | readFileDescriptor(): number; | Added|
| ohos.rpc | MessageParcel | writeFileDescriptor(fd: number): boolean; | Added|
| ohos.rpc | MessageParcel | containFileDescriptors(): boolean; | Added|
| ohos.rpc | MessageParcel | static dupFileDescriptor(fd: number) :number; | Added|
| ohos.rpc | MessageParcel | static closeFileDescriptor(fd: number): void; | Added|
| ohos.rpc | MessageParcel | readRemoteObjectArray(objects: IRemoteObject[]): void;<br>readRemoteObjectArray(): IRemoteObject[]; | Added|
| ohos.rpc | MessageParcel | readSequenceableArray(sequenceableArray: Sequenceable[]): void; | Added|
| ohos.rpc | MessageParcel | writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean; | Added|
| ohos.rpc | MessageParcel | readException(): void; | Added|
| ohos.rpc | MessageParcel | writeNoException(): void; | Added|
