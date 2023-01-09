# DSoftBus Subsystem ChangeLog

## IPC&RPC APIs support the exception handling mode and the selection of synchronous or asynchronous message sending by passing a Boolean value or a numeric value.
1. Some IPC&RPC APIs of DSoftBus use service logic return values to indicate the error information, which does not comply with the API error code specifications of OpenHarmony.
2. A Boolean value can be passed to specify the mode of sending information as asynchronous or synchronous.
#### Change Impacts

This version is compatible with earlier versions and no adaptation is required. Newly added APIs can be called to support the following changes:
1. Supports exception handling and return of error codes.
2. Supports selection of synchronous or asynchronous message sending by passing a Boolean value or by passing 0 or a non-0 number.

#### **Key API/Component Changes**

For adaptation to the unified API exception handling mode, related IPC&RPC APIs are deprecated, and corresponding new APIs and methods are added. The newly added APIs support unified error code handling specifications and function the same as the original APIs.
|  Class| Deprecated API | New Class | New API |
| ------------ | ------------ | ------------ | ------------ |
| MessageParcel | static create(): MessageParcel | MessageSequence  | static create(): MessageSequence |
| MessageParcel | reclaim(): void | MessageSequence | reclaim(): void |
| MessageParcel | writeRemoteObject(object: IRemoteObject): boolean| MessageSequence |writeRemoteObject(object: IRemoteObject): void|
| MessageParcel | readRemoteObject(): IRemoteObject | MessageSequence | readRemoteObject(): IRemoteObject |
|  MessageParcel | writeInterfaceToken(token: string): boolean | MessageSequence | writeInterfaceToken(token: string): void |
|  MessageParcel | readInterfaceToken(): string | MessageSequence | readInterfaceToken(): string |
|  MessageParcel | getSize(): number | MessageSequence | getSize(): number |
|  MessageParcel | getCapacity(): number | MessageSequence | getCapacity(): number|
|  MessageParcel | setSize(size: number): boolean | MessageSequence | setCapacity(size: number): void |
|  MessageParcel | getReadableBytes(): number | MessageSequence | getReadableBytes(): number |
|  MessageParcel | getReadPosition(): number | MessageSequence | getReadPosition(): number |
|  MessageParcel | getWritePosition(): number | MessageSequence | getWritePosition(): number |
|  MessageParcel | rewindRead(pos: number): boolean | MessageSequence | rewindRead(pos: number): void |
|  MessageParcel | rewindWrite(pos: number): boolean | MessageSequence  | rewindWrite(pos: number): void |
|  MessageParcel | writeNoException(): void | MessageSequence | writeNoException(): void |
|  MessageParcel | readException(): void | MessageSequence  | readException(): void |
|  MessageParcel | writeByte(val: number): boolean | MessageSequence  | writeByte(val: number): void |
|  MessageParcel | writeShort(val: number): boolean | MessageSequence | writeShort(val: number): void |
|  MessageParcel | writeInt(val: number): boolean | MessageSequence | writeInt(val: number): void |
|  MessageParcel | writeLong(val: number): boolean | MessageSequence | writeLong(val: number): void |
|  MessageParcel | writeFloat(val: number): boolean | MessageSequence | writeFloat(val: number): void |
|  MessageParcel | writeDouble(val: number): boolean | MessageSequence | writeDouble(val: number): void |
|  MessageParcel | writeBoolean(val: boolean): boolean | MessageSequence | writeBoolean(val: boolean): void |
|  MessageParcel | writeChar(val: number): boolean | MessageSequence | writeChar(val: number): void |
|  MessageParcel | writeString(val: string): boolean | MessageSequence | writeString(val: string): void |
|  MessageParcel | writeSequenceable(val: Sequenceable): boolean | MessageSequence | writeParcelable(val: Parcelable): void |
|  MessageParcel | writeByteArray(byteArray: number[]): boolean | MessageSequence | writeByteArray(byteArray: number[]): void |
|  MessageParcel | writeShortArray(shortArray: number[]): boolean | MessageSequence | writeShortArray(shortArray: number[]): void |
|  MessageParcel | writeIntArray(intArray: number[]): boolean | MessageSequence | writeIntArray(intArray: number[]): void |
|  MessageParcel | writeLongArray(longArray: number[]): boolean | MessageSequence | writeLongArray(longArray: number[]): void |
|  MessageParcel | writeFloatArray(floatArray: number[]): boolean | MessageSequence | writeFloatArray(floatArray: number[]): void |
|  MessageParcel | writeDoubleArray(doubleArray: number[]): boolean | MessageSequence | writeDoubleArray(doubleArray: number[]): void |
|  MessageParcel | writeBooleanArray(booleanArray: boolean[]): boolean | MessageSequence | writeBooleanArray(booleanArray: boolean[]): void |
|  MessageParcel | writeCharArray(charArray: number[]): boolean | MessageSequence | writeCharArray(charArray: number[]): void |
|  MessageParcel | writeStringArray(stringArray: string[]): boolean | MessageSequence  | writeStringArray(stringArray: string[]): void |
|  MessageParcel | writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean | MessageSequence  | writeParcelableArray(sequenceableArray: Parcelable[]): void |
|  MessageParcel | writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean | MessageSequence  | writeRemoteObjectArray(objectArray: IRemoteObject[]): void |
|  MessageParcel | readByte(): number | MessageSequence | readByte(): number |
|  MessageParcel | readShort(): number | MessageSequence | readShort(): number |
|  MessageParcel | readLong(): number | MessageSequence | readLong(): number |
|  MessageParcel | readFloat(): number | MessageSequence | readFloat(): number |
|  MessageParcel | readDouble(): number | MessageSequence | readDouble(): number |
|  MessageParcel | readBoolean(): boolean | MessageSequence | readBoolean(): boolean |
|  MessageParcel | readChar(): number | MessageSequence | readChar(): number |
|  MessageParcel | readString(): string | MessageSequence | readString(): string |
|  MessageParcel | readSequenceable(dataIn: Sequenceable) : boolean | MessageSequence | readSequenceable(dataIn: Parcelable) : void |
|  MessageParcel | readByteArray(dataIn: number[]) : void | MessageSequence | readByteArray(dataIn: number[]) : void |
|  MessageParcel | readByteArray(): number[] | MessageSequence | readByteArray(): number[] |
|  MessageParcel | readShortArray(dataIn: number[]) : void | MessageSequence | readShortArray(dataIn: number[]) : void |
|  MessageParcel | readShortArray(): number[] | MessageSequence | readShortArray(): number[] |
|  MessageParcel | readIntArray(dataIn: number[]) : void | MessageSequence | readIntArray(dataIn: number[]) : void |
|  MessageParcel | readIntArray() : number[] | MessageSequence | readIntArray() : number[] |
|  MessageParcel | readLongArray(dataIn: number[]) : void | MessageSequence | readLongArray(dataIn: number[]) : void |
|  MessageParcel | readLongArray(): number[] | MessageSequence | readLongArray(): number[] |
|  MessageParcel | readFloatArray(dataIn: number[]) : void | MessageSequence | readFloatArray(dataIn: number[]) : void |
|  MessageParcel | readFloatArray(): number[] | MessageSequence | readFloatArray(): number[] |
|  MessageParcel | readDoubleArray(dataIn: number[]) : void | MessageSequence | readDoubleArray(dataIn: number[]) : void |
|  MessageParcel | readDoubleArray(): number[] | MessageSequence | readDoubleArray(): number[] |
|  MessageParcel | readBooleanArray(dataIn: boolean[]) : void | MessageSequence | readBooleanArray(dataIn: boolean[]) : void |
|  MessageParcel | readBooleanArray(): boolean[] | MessageSequence | readBooleanArray(): boolean[] |
|  MessageParcel | readCharArray(dataIn: number[]) : void | MessageSequence | readCharArray(dataIn: number[]) : void |
|  MessageParcel | readCharArray(): number[] | MessageSequence | readCharArray(): number[] |
|  MessageParcel | readStringArray(dataIn: string[]) : void | MessageSequence | readStringArray(dataIn: string[]) : void |
|  MessageParcel | readStringArray(): string[] | MessageSequence | readStringArray(): string[] |
| MessageParcel | readSequenceableArray(sequenceableArray: Sequenceable[]): void | MessageSequence | readSequenceableArray(sequenceableArray: Parcelable[]): void |
| MessageParcel | readRemoteObjectArray(objects: IRemoteObject[]): void | MessageSequence | readRemoteObjectArray(objects: IRemoteObject[]): void |
| MessageParcel | readRemoteObjectArray(): IRemoteObject[] | MessageSequence | readRemoteObjectArray(): IRemoteObject[] |
| MessageParcel | static closeFileDescriptor(fd: number): void | MessageSequence | static closeFileDescriptor(fd: number): void |
| MessageParcel | static dupFileDescriptor(fd: number) :number | MessageSequence | static dupFileDescriptor(fd: number) :number |
| MessageParcel | containFileDescriptors(): boolean | MessageSequence | containFileDescriptors(): boolean |
| MessageParcel | writeFileDescriptor(fd: number): boolean | MessageSequence | writeFileDescriptor(fd: number): void |
| MessageParcel | readFileDescriptor(): number | MessageSequence | readFileDescriptor(): number |
| MessageParcel | writeAshmem(ashmem: Ashmem): boolean | MessageSequence | writeAshmem(ashmem: Ashmem): void |
| MessageParcel | readAshmem(): Ashmem | MessageSequence | readAshmem(): Ashmem |
| MessageParcel | writeRawData(rawData: number[], size: number): boolean | MessageSequence | writeRawData(rawData: number[], size: number): void |
| MessageParcel | readRawData(size: number): number[] | MessageSequence | readRawData(size: number): number[] |
| Sequenceable | marshalling(dataOut: MessageParcel): boolean | Parcelable | marshalling(dataOut: MessageSequence): boolean |
| Sequenceable | unmarshalling(dataIn: MessageParcel) : boolean | Parcelable | unmarshalling(dataIn: MessageSequence) : boolean |
| SendRequestResult | errCode: number | RequestResult | errCode: number |
| SendRequestResult | code: number | RequestResult | code: number |
| SendRequestResult | data: MessageParcel | RequestResult | data: MessageSequence |
| SendRequestResult | reply: MessageParcel | RequestResult | reply: MessageSequence |
| IRemoteObject | queryLocalInterface(descriptor: string): IRemoteBroker | NA | getLocalInterface(descriptor: string): IRemoteBroker |
| IRemoteObject | getInterfaceDescriptor(): string | NA | getDescriptor(): string |
| IRemoteObject | addDeathRecipient(recipient: DeathRecipient, flags: number): boolean | NA | registerDeathRecipient(recipient: DeathRecipient, flags: number): void |
| IRemoteObject | removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean | NA | unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void |
| IRemoteObject | NA | NA | sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise<RequestResult> |
| IRemoteObject | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback<SendRequestResult>): void | NA | sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption,callback: AsyncCallback<RequestResult>): void |
| MessageOption | NA | NA | isAsync(): boolean |
| MessageOption | NA | NA | setAsync(async: boolean): void |
| MessageOption | NA | NA | constructor(async?: boolean) |
| RemoteObject | queryLocalInterface(descriptor: string): IRemoteBroker | NA | getLocalInterface(descriptor: string): IRemoteBroker |
| RemoteObject | attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void  | NA | modifyLocalInterface(localInterface: IRemoteBroker, descriptor: string): void |
| RemoteObject | getInterfaceDescriptor(): string | NA | getDescriptor(): string |
| RemoteObject | onRemoteRequestEx(code : number, data : MessageParcel, reply: MessageParcel, options : MessageOption): boolean&nbsp;\|&nbsp;Promise<boolean> | NA | onRemoteMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): boolean&nbsp;\|&nbsp;Promise<boolean> |
| RemoteObject | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise<SendRequestResult> | NA | sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise<RequestResult> |
| RemoteObject | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback<SendRequestResult>): void | NA | sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback<RequestResult>): void |
| RemoteProxy | queryLocalInterface(interface: string): IRemoteBroker | NA | getLocalInterface(descriptor: string): IRemoteBroker |
| RemoteProxy | getInterfaceDescriptor(): string | NA | getDescriptor(): string |
| RemoteProxy | addDeathRecipient(recipient: DeathRecipient, flags: number): boolean | NA | registerDeathRecipient(recipient: DeathRecipient, flags: number): void |
| RemoteProxy | removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean | NA | unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void |
| RemoteProxy | NA | NA | sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise<RequestResult> |
| RemoteProxy | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback<SendRequestResult>): void | NA | sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback<RequestResult>): void |
| IPCSkeleton | static flushCommands(object: IRemoteObject): number | NA | static flushCmdBuffer(object: IRemoteObject): void |
| IPCSkeleton | static setCallingIdentity(identity: string): boolean | NA | static restoreCallingIdentity(identity: string): void |
| Ashmem | static createAshmem(name: string, size: number): Ashmem | NA | static create(name: string, size: number): Ashmem |
| Ashmem  | static createAshmemFromExisting(ashmem: Ashmem): Ashmem | NA | static create(ashmem: Ashmem): Ashmem |
| Ashmem  | mapAshmem(mapType: number): boolean | NA | mapTypedAshmem(mapType: number): void |
| Ashmem  | mapReadAndWriteAshmem(): boolean | NA | mapReadWriteAshmem(): void |
| Ashmem  | mapReadOnlyAshmem(): boolean | NA | mapReadonlyAshmem(): void |
| Ashmem  | setProtection(protectionType: number): boolean | NA | setProtectionType(protectionType: number): void |
| Ashmem  | writeToAshmem(buf: number[], size: number, offset: number): boolean | NA | writeAshmem(buf: number[], size: number, offset: number): void |
| Ashmem  | readFromAshmem(size: number, offset: number): number[] | NA | readAshmem(size: number, offset: number): number[] |

#### Adaptation Guide

The newly added APIs return error codes and corresponding error information by throwing exceptions. Take the **create** API in **MessageParcel** as an example. The sample code is as follows:
```js
import rpc from '@ohos.rpc'

try {
    var data = rpc.MessageParcel.create();
    data.reclaim();
} catch (error) {
    console.info("create meassageParcel failed, errorCode = " + error.errCode);
    console.info("create meassageParcel failed, errorMessage = " + error.errorMessage);
}
```
For details about sample code of more APIs, see [RPC API reference](../../../application-dev/reference/apis/js-apis-rpc.md).
