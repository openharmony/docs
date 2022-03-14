# RPC Communication


> ![icon-note.gif](public_sys-resources/icon-note.gif) **Note：**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import rpc from '@ohos.rpc';
```


## Required Permissions

None


## MessageParcel

Provides methods for reading and writing basic data types and arrays, inter-process communication (IPC) objects, interface tokens, and sequenceable objects.


### create

create(): MessageParcel

Creates a **MessageParcel** object. This method is a static method.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | MessageParcel | **MessageParcel**&nbsp;object&nbsp;created. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  console.log("RpcClient: data is " + data);
  ```


### reclaim

reclaim(): void

Reclaims the **MessageParcel** instance that is no longer used.


- Example
  
  ```
  let reply = rpc.MessageParcel.create();
  reply.reclaim();
  ```


### writeRemoteObject

writeRemoteObject(object: [IRemoteObject](#iremoteobject)): boolean

  Serializes a remote object and writes it to this **MessageParcel** object.
- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | object | [IRemoteObject](#iremoteobject) | Yes | Remote&nbsp;object&nbsp;to&nbsp;serialize&nbsp;and&nbsp;write&nbsp;to&nbsp;the&nbsp;**MessageParcel**&nbsp;object. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let data = rpc.MessageParcel.create();
  let testRemoteObject = new TestRemoteObject("testObject");
  data.writeRemoteObject(testRemoteObject);
  ```


### readRemoteObject

readRemoteObject(): IRemoteObject

Reads the remote object from this **MessageParcel** object. You can use this method to deserialize the **MessageParcel** object to generate an **IRemoteObject**. The remote objects are read in the order in which they are written to this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | [IRemoteObject](#iremoteobject) | Remote&nbsp;object&nbsp;obtained. | 

- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let data = rpc.MessageParcel.create();
  let testRemoteObject = new TestRemoteObject("testObject");
  data.writeRemoteObject(testRemoteObject);
  let proxy = data.readRemoteObject();
  ```


### writeInterfaceToken

writeInterfaceToken(token: string): boolean

Writes an interface token to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | token | string | Yes | Interface&nbsp;token&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInterfaceToken("aaa");
  console.log("RpcServer: writeInterfaceToken is " + result);
  ```


### readInterfaceToken

readInterfaceToken(): string

Reads the interface token from this **MessageParcel** object. The interface tokens are read in the order in which they are written into the **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | Interface&nbsp;token&nbsp;obtained. | 

- Example
  
  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let interfaceToken = data.readInterfaceToken();
          console.log("RpcServer: interfaceToken is " + interfaceToken);
          return true;
      }
  }
  ```


### getSize

getSize(): number

Obtains the data size of this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Data&nbsp;size&nbsp;obtained,&nbsp;in&nbsp;bytes. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let size = data.getSize();
  console.log("RpcClient: size is " + size);
  ```


### getCapacity

getCapacity(): number

Obtains the capacity of this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | **MessageParcel**&nbsp;capacity&nbsp;obtained,&nbsp;in&nbsp;bytes. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.getCapacity();
  console.log("RpcClient: capacity is " + result);
  ```


### setSize

setSize(size: number): boolean

Sets the size of data contained in this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | size | number | Yes | Data&nbsp;size&nbsp;to&nbsp;set,&nbsp;in&nbsp;bytes. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let setSize = data.setSize(16);
  console.log("RpcClient: setSize is " + setSize);
  ```


### setCapacity

setCapacity(size: number): boolean

Sets the storage capacity of this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | size | number | Yes | Storage&nbsp;capacity&nbsp;to&nbsp;set,&nbsp;in&nbsp;bytes. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.setCapacity(100);
  console.log("RpcClient: setCapacity is " + result);
  ```


### getWritableBytes

getWritableBytes(): number

Obtains the writable capacity of this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | **MessageParcel**&nbsp;writable&nbsp;capacity&nbsp;obtained,&nbsp;in&nbsp;bytes. | 

- Example
  
  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let getWritableBytes = data.getWritableBytes();
          console.log("RpcServer: getWritableBytes is " + getWritableBytes);
          return true;
      }
  }
  ```


### getReadableBytes

getReadableBytes(): number

Obtains the readable capacity of this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | **MessageParcel**&nbsp;readable&nbsp;capacity&nbsp;obtained,&nbsp;in&nbsp;bytes. | 

- Example
  
  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let result = data.getReadableBytes();
          console.log("RpcServer: getReadableBytes is " + result);
          return true;
      }
  }
  ```


### getReadPosition

getReadPosition(): number

Obtains the read position of this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Current&nbsp;read&nbsp;position&nbsp;of&nbsp;the&nbsp;**MessageParcel**&nbsp;object. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let readPos = data.getReadPosition();
  console.log("RpcClient: readPos is " + readPos);
  ```


### getWritePosition

getWritePosition(): number

Obtains the write position of this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Current&nbsp;write&nbsp;position&nbsp;of&nbsp;the&nbsp;**MessageParcel**&nbsp;object. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  data.writeInt(10);
  let bwPos = data.getWritePosition();
  console.log("RpcClient: bwPos is " + bwPos);
  ```


### rewindRead

rewindRead(pos: number): boolean

Moves the read pointer to the specified position.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | pos | number | Yes | Position&nbsp;from&nbsp;which&nbsp;data&nbsp;is&nbsp;to&nbsp;read. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;read&nbsp;position&nbsp;changes;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  data.writeInt(12);
  data.writeString("parcel");
  let number = data.readInt();
  console.log("RpcClient: number is " + number);
  data.rewindRead(0);
  let number2 = data.readInt();
  console.log("RpcClient: rewindRead is " + number2);
  ```


### rewindWrite

rewindWrite(pos: number): boolean

Moves the write pointer to the specified position.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | pos | number | Yes | Position&nbsp;from&nbsp;which&nbsp;data&nbsp;is&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;write&nbsp;position&nbsp;changes;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  data.writeInt(4);
  data.rewindWrite(0);
  data.writeInt(5);
  let number = data.readInt();
  console.log("RpcClient: rewindWrite is: " + number);
  ```


### writeByte

writeByte(val: number): boolean

Writes a **Byte** value to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | val | number | Yes | **Byte**&nbsp;value&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeByte(2);
  console.log("RpcClient: writeByte is: " + result);
  ```


### readByte

readByte(): number

Reads the **Byte** value from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | **Byte**&nbsp;value&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeByte(2);
  console.log("RpcClient: writeByte is: " + result);
  let ret = data.readByte();
  console.log("RpcClient: readByte is: " + ret);
  ```


### writeShort

writeShort(val: number): boolean

Writes a **Short int** value to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | val | number | Yes | **Short&nbsp;int**&nbsp;value&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShort(8);
  console.log("RpcClient: writeShort is: " + result);
  ```


### readShort

readShort(): number

Reads the **Short int** value from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | **Short&nbsp;int**&nbsp;value&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShort(8);
  console.log("RpcClient: writeShort is: " + result);
  let ret = data.readShort();
  console.log("RpcClient: readShort is: " + ret);
  ```


### writeInt

writeInt(val: number): boolean

Writes an **Int** value to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | val | number | Yes | **Int**&nbsp;value&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInt(10);
  console.log("RpcClient: writeInt is " + result);
  ```


### readInt

readInt(): number

Reads the **Int** value from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | **Int**&nbsp;value&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInt(10);
  console.log("RpcClient: writeInt is " + result);
  let ret = data.readInt();
  console.log("RpcClient: readInt is " + ret);
  ```


### writeLong

writeLong(val: number): boolean

Writes a **Long int** value to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | val | number | Yes | **Long&nbsp;int**&nbsp;value&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLong(10000);
  console.log("RpcClient: writeLong is " + result);
  ```


### readLong

readLong(): number

Reads the **Long int** value from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | **Long&nbsp;int**&nbsp;value&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLong(10000);
  console.log("RpcClient: writeLong is " + result);
  let ret = data.readlong();
  console.log("RpcClient: readLong is " + ret);
  ```


### writeFloat

writeFloat(val: number): boolean

Writes a **Float** value to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | val | number | Yes | **Float**&nbsp;value&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloat(1.2);
  console.log("RpcClient: writeFloat is " + result);
  ```


### readFloat

readFloat(): number

Reads the **Float** value from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | **Float**&nbsp;value&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloat(1.2);
  console.log("RpcClient: writeFloat is " + result);
  let ret = data.readFloat();
  console.log("RpcClient: readFloat is " + ret);
  ```


### writeDouble

writeDouble(val: number): boolean

Writes a **Double** value to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | val | number | Yes | **Double**&nbsp;value&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDouble(10.2);
  console.log("RpcClient: writeDouble is " + result);
  ```


### readDouble

readDouble(): number

Reads the **Double** value from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | **Double**&nbsp;value&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDouble(10.2);
  console.log("RpcClient: writeDouble is " + result);
  let ret = data.readDouble();
  console.log("RpcClient: readDouble is " + ret);
  ```


### writeBoolean

writeBoolean(val: boolean): boolean

Writes a **Boolean** value to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | val | boolean | Yes | **Boolean**&nbsp;value&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBoolean(false);
  console.log("RpcClient: writeBoolean is " + result);
  ```


### readBoolean

readBoolean(): boolean

Reads the **Boolean** value from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | **Boolean**&nbsp;value&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBoolean(false);
  console.log("RpcClient: writeBoolean is " + result);
  let ret = data.readBoolean();
  console.log("RpcClient: readBoolean is " + ret);
  ```


### writeChar

writeChar(val: number): boolean

Writes a **Char** value to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | val | number | Yes | **Char**&nbsp;value&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeChar('a');
  console.log("RpcClient: writeChar is " + result);
  ```


### readChar

readChar(): number

Reads the **Char** value from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | **Char**&nbsp;value&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeChar('a');
  console.log("RpcClient: writeChar is " + result);
  let ret = data.readChar();
  console.log("RpcClient: readChar is " + ret);
  ```


### writeString

writeString(val: string): boolean

Writes a **String** value to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | val | string | Yes | **String**&nbsp;value&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeString('abc');
  console.log("RpcClient: writeString  is " + result);
  ```


### readString

readString(): string

Reads the **String** value from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | **String**&nbsp;value&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeString('abc');
  console.log("RpcClient: writeString  is " + result);
  let ret = data.readString();
  console.log("RpcClient: readString is " + ret);
  ```


### writeSequenceable

writeSequenceable(val: Sequenceable): boolean

Writes a sequenceable object to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | val | [Sequenceable](#sequenceable) | Yes | Sequenceable&nbsp;object&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  class MySequenceable {
      constructor(num, string) {
          this.num = num;
          this.str = string;
      }
      marshalling(messageParcel) {
          messageParcel.writeInt(this.num);
          messageParcel.writeString(this.str);
          return true;
      }
      unmarshalling(messageParcel) {
          this.num = messageParcel.readInt();
          this.str = messageParcel.readString();
          return true;
      }
  }
  let sequenceable = new MySequenceable(1, "aaa");
  let data = rpc.MessageParcel.create();
  let result = data.writeSequenceable(sequenceable);
  console.log("RpcClient: writeSequenceable is " + result);
  ```


### readSequenceable

readSequenceable(dataIn: Sequenceable) : boolean

Reads member variables from the **MessageParcel** instance.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | [Sequenceable](#sequenceable) | Yes | Object&nbsp;that&nbsp;reads&nbsp;member&nbsp;variables&nbsp;from&nbsp;the&nbsp;**MessageParcel**&nbsp;instance. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  class MySequenceable {
      constructor(num, string) {
          this.num = num;
          this.str = string;
      }
      marshalling(messageParcel) {
          messageParcel.writeInt(this.num);
          messageParcel.writeString(this.str);
          return true;
      }
      unmarshalling(messageParcel) {
          this.num = messageParcel.readInt();
          this.str = messageParcel.readString();
          return true;
      }
  }
  let sequenceable = new MySequenceable(1, "aaa");
  let data = rpc.MessageParcel.create();
  let result = data.writeSequenceable(sequenceable);
  console.log("RpcClient: writeSequenceable is " + result);
  let ret = new MySequenceable(0, "");
  let result2 = data.readSequenceable(ret);
  console.log("RpcClient: writeSequenceable is " + result2);
  ```


### writeByteArray

writeByteArray(byteArray: number[]): boolean

Writes a **ByteArray** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | byteArray | number[] | Yes | **ByteArray**&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let ByteArrayVar = new Int8Array([1, 2, 3, 4, 5]);
  let result = data.writeByteArray(ByteArrayVar);
  console.log("RpcClient: writeByteArray is " + result);
  ```


### readByteArray

readByteArray(dataIn: number[]) : void

Reads the **ByteArray** from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes | **ByteArray**&nbsp;to&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let ByteArrayVar = new Int8Array([1, 2, 3, 4, 5]);
  let result = data.writeByteArray(ByteArrayVar);
  console.log("RpcClient: writeByteArray is " + result);
  let array = new Array(5);
  data.readByteArray(array);
  ```


### readByteArray

readByteArray(): number[]

Reads the **ByteArray** from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number[] | **ByteArray**&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let ByteArrayVar = new Int8Array([1, 2, 3, 4, 5]);
  let result = data.writeByteArray(ByteArrayVar);
  console.log("RpcClient: writeByteArray is " + result);
  let array = data.readByteArray();
  console.log("RpcClient: readByteArray is " + array);
  ```


### writeShortArray

writeShortArray(shortArray: number[]): boolean

Writes a **ShortArray** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | shortArray | number[] | Yes | **ShortArray**&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  ```


### readShortArray

readShortArray(dataIn: number[]) : void

Reads the **ShortArray** from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes | **ShortArray**&nbsp;to&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  let array = new Array(3);
  data.readShortArray(array);
  ```


### readShortArray

readShortArray(): number[]

Reads the **ShortArray** from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number[] | **ShortArray**&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  let array = data.readShortArray();
  console.log("RpcClient: readShortArray is " + array);
  ```


### writeIntArray

writeIntArray(intArray: number[]): boolean

Writes an **IntArray** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | intArray | number[] | Yes | **IntArray**&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  ```


### readIntArray

readIntArray(dataIn: number[]) : void

Reads the **IntArray** from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes | **IntArray**&nbsp;to&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  let array = new Array(3);
  data.readIntArray(array);
  ```


### readIntArray

readIntArray(): number[]

Reads the **IntArray** from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number[] | **IntArray**&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  let array = data.readIntArray();
  console.log("RpcClient: readIntArray is " + array);
  ```


### writeLongArray

writeLongArray(longArray: number[]): boolean

Writes a **LongArray** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | longArray | number[] | Yes | **LongArray**&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  ```


### readLongArray

readLongArray(dataIn: number[]) : void

Reads the **LongArray** from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes | **LongArray**&nbsp;to&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  let array = new Array(3);
  data.readLongArray(array);
  ```


### readLongArray

readLongArray(): number[]

Reads the **LongArray** from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number[] | **LongArray**&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  let array = data.readLongArray();
  console.log("RpcClient: readLongArray is " + array);
  ```


### writeFloatArray

writeFloatArray(floatArray: number[]): boolean

Writes a **FloatArray** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | floatArray | number[] | Yes | **FloatArray**&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  ```


### readFloatArray

readFloatArray(dataIn: number[]) : void

Reads the **FloatArray** from this **MessageParcel** object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes | **FloatArray**&nbsp;to&nbsp;read. | 


- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  let array = new Array(3);
  data.readFloatArray(array);
  ```


### readFloatArray

readFloatArray(): number[]

Reads the **FloatArray** from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number[] | **FloatArray**&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  let array = data.readFloatArray();
  console.log("RpcClient: readFloatArray is " + array);
  ```


### writeDoubleArray

writeDoubleArray(doubleArray: number[]): boolean

Writes a **DoubleArray** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | doubleArray | number[] | Yes | **DoubleArray**&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  ```


### readDoubleArray

readDoubleArray(dataIn: number[]) : void

Reads the **DoubleArray** from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes | **DoubleArray**&nbsp;to&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  let array = new Array(3);
  data.readDoubleArray(array);
  ```


### readDoubleArray

readDoubleArray(): number[]

Reads the **DoubleArray** from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number[] | **DoubleArray**&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  let array = data.readDoubleArray();
  console.log("RpcClient: readDoubleArray is " + array);
  ```


### writeBooleanArray

writeBooleanArray(booleanArray: boolean[]): boolean

Writes a **BooleanArray** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | booleanArray | boolean[] | Yes | **BooleanArray**&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  ```


### readBooleanArray

readBooleanArray(dataIn: boolean[]) : void

Reads the **BooleanArray** from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | boolean[] | Yes | **BooleanArray**&nbsp;to&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  let array = new Array(3);
  data.readBooleanArray(array);
  ```


### readBooleanArray

readBooleanArray(): boolean[]

Reads the **BooleanArray** from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean[] | **BooleanArray**&nbsp;read. | 

  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  let array = data.readBooleanArray();
  console.log("RpcClient: readBooleanArray is " + array);
  ```


### writeCharArray

writeCharArray(charArray: number[]): boolean

Writes a **CharArray** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | charArray | number[] | Yes | **CharArray**&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray(['a', 'b', 'c']);
  console.log("RpcClient: writeCharArray is " + result);
  ```


### readCharArray

readCharArray(dataIn: boolean[]) : void

Reads the **CharArray** from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | boolean[] | Yes | **CharArray**&nbsp;to&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray(['a', 'b', 'c']);
  console.log("RpcClient: writeCharArray is " + result);
  let array = new Array(3);
  data.readCharArray(array);
  ```


### readCharArray

readCharArray(): boolean[]

Reads the **CharArray** from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean[] | **CharArray**&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray(['a', 'b', 'c']);
  console.log("RpcClient: writeCharArray is " + result);
  let array = data.readCharArray();
  console.log("RpcClient: readCharArray is " + array);
  ```


### writeStringArray

writeStringArray(stringArray: string[]): boolean

Writes a **StringArray** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | stringArray | string[] | Yes | **StringArray**&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  console.log("RpcClient: writeStringArray is " + result);
  ```


### readStringArray

readStringArray(dataIn: string[]) : void

Reads the **StringArray** from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | string[] | Yes | **StringArray**&nbsp;to&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  console.log("RpcClient: writeStringArray is " + result);
  let array = new Array(2);
  data.readStringArray(array);
  ```


### readStringArray

readStringArray(): string[]

Reads the **StringArray** from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | string[] | **StringArray**&nbsp;read. | 

- Example
  
  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  console.log("RpcClient: writeStringArray is " + result);
  let array = data.readStringArray();
  console.log("RpcClient: readStringArray is " + array);
  ```


### writeNoException<sup>8+</sup>

writeNoException(): void

Writes information to this **MessageParcel** object indicating that no exception occurred.


- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      onRemoteRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: onRemoteRequest called");
              reply.writeNoException();
              return true;
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
      }
  }
  ```


### readException<sup>8+</sup>

readException(): void

Reads the exception information from this **MessageParcel** object.


- Example
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function(elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.huawei.server",
      "abilityName": "com.huawei.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  proxy.sendRequest(1, data, reply, option)
      .then(function(errCode) {
          if (errCode === 0) {
              console.log("sendRequest got result");
              reply.readException();
              let msg = reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendRequest failed, errCode: " + errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendRequest got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendRequest ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```


### writeSequenceableArray

writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean

Writes a **SequenceableArray** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | sequenceableArray | Sequenceable[] | Yes | **SequenceableArray**&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  class MySequenceable {
      constructor(num, string) {
          this.num = num;
          this.str = string;
      }
      marshalling(messageParcel) {
          messageParcel.writeInt(this.num);
          messageParcel.writeString(this.str);
          return true;
      }
      unmarshalling(messageParcel) {
          this.num = messageParcel.readInt();
          this.str = messageParcel.readString();
          return true;
      }
  }
  let sequenceable = new MySequenceable(1, "aaa");
  let sequenceable2 = new MySequenceable(2, "bbb");
  let sequenceable3 = new MySequenceable(3, "ccc");
  let a = [sequenceable, sequenceable2, sequenceable3];
  let data = rpc.MessageParcel.create();
  let result = data.writeSequenceableArray(a);
  console.log("RpcClient: writeSequenceableArray is " + result);
  ```


### readSequenceableArray<sup>8+</sup>

readSequenceableArray(sequenceableArray: Sequenceable[]): void

Reads the specified **SequenceableArray** from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | sequenceableArray | Sequenceable[] | Yes | **SequenceableArray**&nbsp;to&nbsp;read. | 

- Example
  
  ```
  class MySequenceable {
      constructor(num, string) {
          this.num = num;
          this.str = string;
      }
      marshalling(messageParcel) {
          messageParcel.writeInt(this.num);
          messageParcel.writeString(this.str);
          return true;
      }
      unmarshalling(messageParcel) {
          this.num = messageParcel.readInt();
          this.str = messageParcel.readString();
          return true;
      }
  }
  let sequenceable = new MySequenceable(1, "aaa");
  let sequenceable2 = new MySequenceable(2, "bbb");
  let sequenceable3 = new MySequenceable(3, "ccc");
  let a = [sequenceable, sequenceable2, sequenceable3];
  let data = rpc.MessageParcel.create();
  let result = data.writeSequenceableArray(a);
  console.log("RpcClient: writeSequenceableArray is " + result);
  let b = [new MySequenceable(0, ""), new MySequenceable(0, ""), new MySequenceable(0, "")];
  data.readSequenceableArray(b);
  ```


### writeRemoteObjectArray<sup>8+</sup>

writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean

Writes an array of **IRemoteObject** objects to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | objectArray | IRemoteObject[] | Yes | Array&nbsp;of&nbsp;**IRemoteObject**&nbsp;objects&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;**IRemoteObject**&nbsp;array&nbsp;is&nbsp;successfully&nbsp;written&nbsp;to&nbsp;the&nbsp;**MessageParcel**;&nbsp;returns&nbsp;**false**&nbsp;if&nbsp;the&nbsp;**IRemoteObject**&nbsp;array&nbsp;is&nbsp;null&nbsp;or&nbsp;fails&nbsp;to&nbsp;be&nbsp;written&nbsp;to&nbsp;the&nbsp;**MessageParcel**. | 

- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
          this.attachLocalInterface(this, descriptor);
      }
  }
  let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
  let data = rpc.MessageParcel.create();
  let result = data.writeRemoteObjectArray(a);
  console.log("RpcClient: writeRemoteObjectArray is " + result);
  ```


### readRemoteObjectArray<sup>8+</sup>

readRemoteObjectArray(objects: IRemoteObject[]): void

Reads the specified **IRemoteObject** array from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | objects | IRemoteObject[] | Yes | **IRemoteObject**&nbsp;array&nbsp;to&nbsp;read. | 

- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
          this.attachLocalInterface(this, descriptor);
      }
  }
  let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
  let data = rpc.MessageParcel.create();
  let result = data.writeRemoteObjectArray(a);
  let b = new Array(3);
  data.readRemoteObjectArray(b);
  ```


### readRemoteObjectArray<sup>8+</sup>

readRemoteObjectArray(): IRemoteObject[]

Reads **IRemoteObject** objects from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | IRemoteObject[] | An&nbsp;array&nbsp;of&nbsp;**IRemoteObject**&nbsp;objects&nbsp;obtained. | 

- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
          this.attachLocalInterface(this, descriptor);
      }
  }
  let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
  let data = rpc.MessageParcel.create();
  let result = data.writeRemoteObjectArray(a);
  console.log("RpcClient: readRemoteObjectArray is " + result);
  let b = data.readRemoteObjectArray();
  console.log("RpcClient: readRemoteObjectArray is " + b);
  ```


### closeFileDescriptor<sup>8+</sup>

static closeFileDescriptor(fd: number): void

Closes the specified file descriptor.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | fd | number | Yes | File&nbsp;descriptor&nbsp;to&nbsp;close. | 

- Example
  
  ```
  import fileio from '@ohos.fileio';
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  rpc.MessageParcel.closeFileDescriptor(fd);
  ```


### dupFileDescriptor<sup>8+</sup>

static dupFileDescriptor(fd: number) :number

Duplicates the specified file descriptor.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | fd | number | Yes | File&nbsp;descriptor&nbsp;to&nbsp;duplicate. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | New&nbsp;file&nbsp;descriptor. | 

- Example
  
  ```
  import fileio from '@ohos.fileio';
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  let newFd = rpc.MessageParcel.dupFileDescriptor(fd);
  ```


### containFileDescriptors<sup>8+</sup>

containFileDescriptors(): boolean

Checks whether this **MessageParcel** object contains a file descriptor.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;**MessageParcel**&nbsp;object&nbsp;contains&nbsp;a&nbsp;file&nbsp;descriptor;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  import fileio from '@ohos.fileio';
  let parcel = new rpc.MessageParcel();
  let filePath = "path/to/file";
  let r1 = parcel.containFileDescriptors();
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  let writeResult = parcel.writeFileDescriptor(fd);
  console.log("RpcTest: parcel writeFd result is : " + writeResult);
  let containFD = parcel.containFileDescriptors();
  console.log("RpcTest: parcel after write fd containFd result is : " + containFD);
  ```


### writeFileDescriptor<sup>8+</sup>

writeFileDescriptor(fd: number): boolean

Writes a file descriptor to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | fd | number | Yes | File&nbsp;descriptor&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  import fileio from '@ohos.fileio';
  let parcel = new rpc.MessageParcel();
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  let writeResult = parcel.writeFileDescriptor(fd);
  console.log("RpcTest: parcel writeFd result is : " + writeResult);
  ```


### readFileDescriptor<sup>8+</sup>

readFileDescriptor(): number

Reads a file descriptor from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | File&nbsp;descriptor&nbsp;obtained. | 

- Example
  
  ```
  import fileio from '@ohos.fileio';
  let parcel = new rpc.MessageParcel();
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  let writeResult = parcel.writeFileDescriptor(fd);
  let readFD = parcel.readFileDescriptor();
  console.log("RpcTest: parcel read fd is : " + readFD);
  ```


### writeAshmem<sup>8+</sup>

writeAshmem(ashmem: Ashmem): boolean

Writes an anonymous shared object to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | ashmem | Ashmem | Yes | Anonymous&nbsp;shared&nbsp;object&nbsp;to&nbsp;write. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let parcel = new rpc.MessageParcel();
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);
  let isWriteSuccess = parcel.writeAshmem(ashmem);
  console.log("RpcTest: write ashmem to result is : " + isWriteSuccess);
  ```


### readAshmem<sup>8+</sup>

readAshmem(): Ashmem

Reads the anonymous shared object from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | Ashmem | Anonymous&nbsp;share&nbsp;object&nbsp;obtained. | 

- Example
  
  ```
  let parcel = new rpc.MessageParcel();
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);
  let isWriteSuccess = parcel.writeAshmem(ashmem);
  console.log("RpcTest: write ashmem to result is : " + isWriteSuccess);
  let readAshmem = parcel.readAshmem();
  console.log("RpcTest: read ashmem to result is : " + readAshmem);
  ```


### getRawDataCapacity<sup>8+</sup>

getRawDataCapacity(): number

Obtains the maximum amount of raw data that can be held by this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | 128&nbsp;MB,&nbsp;which&nbsp;is&nbsp;the&nbsp;maximum&nbsp;amount&nbsp;of&nbsp;raw&nbsp;data&nbsp;that&nbsp;can&nbsp;be&nbsp;held&nbsp;by&nbsp;this&nbsp;**MessageParcel**&nbsp;object. | 

- Example
  
  ```
  let parcel = new rpc.MessageParcel();
  let result = parcel.getRawDataCapacity();
  console.log("RpcTest: parcel get RawDataCapacity result is : " + result);
  ```


### writeRawData<sup>8+</sup>

writeRawData(rawData: number[], size: number): boolean

Writes raw data to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | rawData | number[] | Yes | Raw&nbsp;data&nbsp;to&nbsp;write. | 
  | size | number | Yes | Size&nbsp;of&nbsp;the&nbsp;raw&nbsp;data,&nbsp;in&nbsp;bytes. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let parcel = new rpc.MessageParcel();
  let arr = new Int8Array([1, 2, 3, 4, 5]);
  let isWriteSuccess = parcel.writeRawData(arr, arr.length);
  console.log("RpcTest: parcel write raw data result is : " + isWriteSuccess);
  ```


### readRawData<sup>8+</sup>

readRawData(size: number): number[]

Reads raw data from this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | size | number | Yes | Size&nbsp;of&nbsp;the&nbsp;raw&nbsp;data&nbsp;to&nbsp;read. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number[] | Raw&nbsp;data&nbsp;obtained,&nbsp;in&nbsp;bytes. | 

- Example
  
  ```
  let parcel = new rpc.MessageParcel();
  let arr = new Int8Array([1, 2, 3, 4, 5]);
  let isWriteSuccess = parcel.writeRawData(arr, arr.length);
  console.log("RpcTest: parcel write raw data result is : " + isWriteSuccess);
  let result = parcel.readRawData(5);
  console.log("RpcTest: parcel read raw data result is : " + result);
  ```


### getDataVersion<sup>8+</sup>

getDataVersion(): number

Obtains the data format version from this **MessageParcel** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Data&nbsp;format&nbsp;version&nbsp;obtained. | 

- Example
  
  ```
  let parcel = new rpc.MessageParcel();
  let version = parcel.getDataVersion();
  console.log("RpcTest: parcel get data version is : " + version);
  ```


### updateDataVersion<sup>8+</sup>

updateDataVersion(proxy: IRemoteObject): void

Updates the data format version of the **IRemoteObject** to this **MessageParcel** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | proxy | IRemoteObject | Yes | Remote&nbsp;object&nbsp;that&nbsp;uses&nbsp;this&nbsp;**MessageParcel**&nbsp;object&nbsp;to&nbsp;send&nbsp;the&nbsp;request. | 

- Example
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function(elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.huawei.server",
      "abilityName": "com.huawei.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let parcel = new rpc.MessageParcel();
  parcel.updateDataVersion(proxy);
  ```


## Sequenceable

Writes objects of classes to a **MessageParcel** and reads them from the **MessageParcel** during inter-process communication (IPC).


### marshalling

marshalling(dataOut: MessageParcel): boolean

Marshals this sequenceable object into a **MessageParcel** object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataOut | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;to&nbsp;which&nbsp;the&nbsp;sequenceable&nbsp;object&nbsp;is&nbsp;to&nbsp;be&nbsp;marshaled. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  class MySequenceable {
      constructor(num, string) {
          this.num = num;
          this.str = string;
      }
      marshalling(messageParcel) {
          messageParcel.writeInt(this.num);
          messageParcel.writeString(this.str);
          return true;
      }
      unmarshalling(messageParcel) {
          this.num = messageParcel.readInt();
          this.str = messageParcel.readString();
          return true;
      }
  }
  let sequenceable = new MySequenceable(1, "aaa");
  let data = rpc.MessageParcel.create();
  let result = data.writeSequenceable(sequenceable);
  console.log("RpcClient: writeSequenceable is " + result);
  let ret = new MySequenceable(0, "");
  let result2 = data.readSequenceable(ret);
  console.log("RpcClient: readSequenceable is " + result2);
  ```


### unmarshalling

unmarshalling(dataIn: MessageParcel) : boolean

Unmarshals this sequenceable object from a **MessageParcel** object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataIn | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;in&nbsp;which&nbsp;the&nbsp;sequenceable&nbsp;object&nbsp;has&nbsp;been&nbsp;marshaled. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  class MySequenceable {
      constructor(num, string) {
          this.num = num;
          this.str = string;
      }
      marshalling(messageParcel) {
          messageParcel.writeInt(this.num);
          messageParcel.writeString(this.str);
          return true;
      }
      unmarshalling(messageParcel) {
          this.num = messageParcel.readInt();
          this.str = messageParcel.readString();
          return true;
      }
  }
  let sequenceable = new MySequenceable(1, "aaa");
  let data = rpc.MessageParcel.create();
  let result = data.writeSequenceable(sequenceable);
  console.log("RpcClient: writeSequenceable is " + result);
  let ret = new MySequenceable(0, "");
  let result2 = data.readSequenceable(ret);
  console.log("RpcClient: readSequenceable is " + result2);
  ```


## IRemoteBroker

Obtains a remote proxy object.


### asObject

asObject(): IRemoteObject

Obtains a proxy or remote object. This method must be implemented by its derived classes.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | [IRemoteObject](#iremoteobject) | Returns&nbsp;the&nbsp;[RemoteObject](#ashmem8)&nbsp;if&nbsp;the&nbsp;caller&nbsp;is&nbsp;a&nbsp;[RemoteObject](#ashmem8);&nbsp;returns&nbsp;the&nbsp;[IRemoteObject](#iremoteobject),&nbsp;that&nbsp;is,&nbsp;the&nbsp;holder&nbsp;of&nbsp;this&nbsp;**RemoteProxy**&nbsp;object,&nbsp;if&nbsp;the&nbsp;caller&nbsp;is&nbsp;a&nbsp;[RemoteProxy](#remoteproxy)&nbsp;object. | 

- Example
  
  ```
  class TestAbility extends rpc.RemoteObject {
      asObject() {
          return this;
      }
  }
  ```

- Example
  
  ```
  class TestProxy {
      constructor(remote) {
          this.remote = remote;
      }
      asObject() {
          return this.remote;
      }
  }
  ```


## DeathRecipient

Subscribes to death notifications of a remote object. When the remote object is dead, the local end will receive a notification and [onRemoteDied](#onremotedied) will be called. A remote object is dead when the process holding the object is terminated or the device of the remote object is shut down or restarted. If the local and remote objects belong to different devices, the remote object is dead when the device holding the remote object is detached from the network.


### onRemoteDied

onRemoteDied(): void

Called to perform subsequent operations when a death notification of the remote object is received.

- Example
  
  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
      }
  }
  ```


## SendRequestResult<sup>8+</sup>

Defines the response to the request.

  | Parameters | Value | Description | 
| -------- | -------- | -------- |
| errCode | number | Error&nbsp;code. | 
| code | number | Message&nbsp;code. | 
| data | MessageParcel | **MessageParcel**&nbsp;object&nbsp;sent&nbsp;to&nbsp;the&nbsp;peer&nbsp;process. | 
| reply | MessageParcel | **MessageParcel**&nbsp;object&nbsp;returned&nbsp;by&nbsp;the&nbsp;peer&nbsp;process. | 


## IRemoteObject

Provides methods to query or obtain interface descriptors, add or delete death notifications, dump object status to specific files, and send messages.


### queryLocalInterface

queryLocalInterface(descriptor: string): IRemoteBroker

Obtains the interface.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | descriptor | string | Yes | Interface&nbsp;descriptor. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | IRemoteBroker | **IRemoteBroker**&nbsp;object&nbsp;bound&nbsp;to&nbsp;the&nbsp;specified&nbsp;interface&nbsp;descriptor. | 


### sendRequest

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;number&gt;<sup>7</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;<sup>8+</sup>

Sends a **MessageParcel** message to the peer process in synchronous or asynchronous mode. If **options** indicates the asynchronous mode, a promise will be fulfilled immediately and the **reply** message does not contain any content. If **options** indicates the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | code | number | Yes | Message&nbsp;code&nbsp;called&nbsp;by&nbsp;the&nbsp;request,&nbsp;which&nbsp;is&nbsp;determined&nbsp;by&nbsp;the&nbsp;client&nbsp;and&nbsp;server.&nbsp;If&nbsp;the&nbsp;method&nbsp;is&nbsp;generated&nbsp;by&nbsp;an&nbsp;IDL&nbsp;tool,&nbsp;the&nbsp;message&nbsp;code&nbsp;is&nbsp;automatically&nbsp;generated&nbsp;by&nbsp;the&nbsp;IDL&nbsp;tool. | 
  | data | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;holding&nbsp;the&nbsp;data&nbsp;to&nbsp;send. | 
  | reply | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;that&nbsp;receives&nbsp;the&nbsp;response. | 
  | options | [MessageOption](#messageoption) | Yes | Request&nbsp;sending&nbsp;mode,&nbsp;which&nbsp;can&nbsp;be&nbsp;synchronous&nbsp;(default)&nbsp;or&nbsp;asynchronous. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Promise&lt;number&gt;<sup>7</sup><br/>Promise&lt;SendRequestResult&gt;<sup>8+</sup> | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;The&nbsp;value&nbsp;**0**&nbsp;will&nbsp;be&nbsp;returned&nbsp;if&nbsp;the&nbsp;request&nbsp;is&nbsp;sent&nbsp;successfully.&nbsp;Otherwise,&nbsp;an&nbsp;error&nbsp;code&nbsp;will&nbsp;be&nbsp;returned.&nbsp;<sup>7</sup><br/>Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;**sendRequestResult**&nbsp;instance.&nbsp;<sup>8+</sup> | 


### sendRequest<sup>8+</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the peer process in synchronous or asynchronous mode. If **options** indicates the asynchronous mode, a callback will be invoked immediately and the **reply** message does not contain any content. If **options** indicates the synchronous mode, a callback will be invoked when the response to **sendRequest** is returned, and the **reply** message contains the returned information.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | code | number | Yes | Message&nbsp;code&nbsp;called&nbsp;by&nbsp;the&nbsp;request,&nbsp;which&nbsp;is&nbsp;determined&nbsp;by&nbsp;the&nbsp;client&nbsp;and&nbsp;server.&nbsp;If&nbsp;the&nbsp;method&nbsp;is&nbsp;generated&nbsp;by&nbsp;an&nbsp;IDL&nbsp;tool,&nbsp;the&nbsp;message&nbsp;code&nbsp;is&nbsp;automatically&nbsp;generated&nbsp;by&nbsp;the&nbsp;IDL&nbsp;tool. | 
  | data | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;holding&nbsp;the&nbsp;data&nbsp;to&nbsp;send. | 
  | reply | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;that&nbsp;receives&nbsp;the&nbsp;response. | 
  | options | [MessageOption](#messageoption) | Yes | Request&nbsp;sending&nbsp;mode,&nbsp;which&nbsp;can&nbsp;be&nbsp;synchronous&nbsp;(default)&nbsp;or&nbsp;asynchronous. | 
  | callback | AsyncCallback&lt;SendRequestResult&gt; | Yes | Callback&nbsp;for&nbsp;receiving&nbsp;the&nbsp;sending&nbsp;result. | 


### addDeathrecipient

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Adds a callback for receiving death notifications of the remote object. This method is called if the remote object process matching the **RemoteProxy** object is killed.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes | Callback&nbsp;to&nbsp;add. | 
  | flags | number | Yes | Flag&nbsp;of&nbsp;the&nbsp;death&nbsp;notification. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;callback&nbsp;is&nbsp;added&nbsp;successfully;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 


### removeDeathRecipient

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Removes the callback used to receive death notifications of the remote object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes | Callback&nbsp;to&nbsp;remove. | 
  | flags | number | Yes | Flag&nbsp;of&nbsp;the&nbsp;death&nbsp;notification. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;callback&nbsp;is&nbsp;removed&nbsp;successfully;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 


### getInterfaceDescriptor

getInterfaceDescriptor(): string

Obtains the interface descriptor of the object. The interface descriptor is a string.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | Interface&nbsp;descriptor&nbsp;obtained. | 


### isObjectDead

isObjectDead(): boolean

Checks whether the current object is dead.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;object&nbsp;is&nbsp;dead;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 


## RemoteProxy

Provides methods to implement **IRemoteObject**.


### sendRequest

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;number&gt;<sup>7</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;<sup>8+</sup>

Sends a **MessageParcel** message to the peer process in synchronous or asynchronous mode. If **options** indicates the asynchronous mode, a promise will be fulfilled immediately and the **reply** message does not contain any content. If **options** indicates the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | code | number | Yes | Message&nbsp;code&nbsp;called&nbsp;by&nbsp;the&nbsp;request,&nbsp;which&nbsp;is&nbsp;determined&nbsp;by&nbsp;the&nbsp;client&nbsp;and&nbsp;server.&nbsp;If&nbsp;the&nbsp;method&nbsp;is&nbsp;generated&nbsp;by&nbsp;an&nbsp;IDL&nbsp;tool,&nbsp;the&nbsp;message&nbsp;code&nbsp;is&nbsp;automatically&nbsp;generated&nbsp;by&nbsp;the&nbsp;IDL&nbsp;tool. | 
  | data | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;holding&nbsp;the&nbsp;data&nbsp;to&nbsp;send. | 
  | reply | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;that&nbsp;receives&nbsp;the&nbsp;response. | 
  | options | [MessageOption](#messageoption) | Yes | Request&nbsp;sending&nbsp;mode,&nbsp;which&nbsp;can&nbsp;be&nbsp;synchronous&nbsp;(default)&nbsp;or&nbsp;asynchronous. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Promise&lt;number&gt;<sup>7</sup><br/>Promise&lt;SendRequestResult&gt;<sup>8+</sup> | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;The&nbsp;value&nbsp;**0**&nbsp;will&nbsp;be&nbsp;returned&nbsp;if&nbsp;the&nbsp;request&nbsp;is&nbsp;sent&nbsp;successfully.&nbsp;Otherwise,&nbsp;an&nbsp;error&nbsp;code&nbsp;will&nbsp;be&nbsp;returned.&nbsp;<sup>7</sup><br/>Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;**sendRequestResult**&nbsp;instance.&nbsp;<sup>8+</sup> | 

- Example<sup>7</sup>
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function(elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.huawei.server",
      "abilityName": "com.huawei.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  proxy.sendRequest(1, data, reply, option)
      .then(function(errCode) {
          if (errCode === 0) {
              console.log("sendRequest got result");
              let msg = reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendRequest failed, errCode: " + errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendRequest got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendRequest ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```

- Example<sup>8+</sup>
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function(elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.huawei.server",
      "abilityName": "com.huawei.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  proxy.sendRequest(1, data, reply, option)
      .then(function(result) {
          if (result.errCode === 0) {
              console.log("sendRequest got result");
              result.reply.readException();
              let msg = result.reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendRequest failed, errCode: " + result.errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendRequest got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendRequest ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```


### sendRequest<sup>8+</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the peer process in synchronous or asynchronous mode. If **options** indicates the asynchronous mode, a callback will be invoked immediately and the **reply** message does not contain any content. If **options** indicates the synchronous mode, a callback will be invoked when the response to **sendRequest** is returned, and the **reply** message contains the returned information.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | code | number | Yes | Message&nbsp;code&nbsp;called&nbsp;by&nbsp;the&nbsp;request,&nbsp;which&nbsp;is&nbsp;determined&nbsp;by&nbsp;the&nbsp;client&nbsp;and&nbsp;server.&nbsp;If&nbsp;the&nbsp;method&nbsp;is&nbsp;generated&nbsp;by&nbsp;an&nbsp;IDL&nbsp;tool,&nbsp;the&nbsp;message&nbsp;code&nbsp;is&nbsp;automatically&nbsp;generated&nbsp;by&nbsp;the&nbsp;IDL&nbsp;tool. | 
  | data | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;holding&nbsp;the&nbsp;data&nbsp;to&nbsp;send. | 
  | reply | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;that&nbsp;receives&nbsp;the&nbsp;response. | 
  | options | [MessageOption](#messageoption) | Yes | Request&nbsp;sending&nbsp;mode,&nbsp;which&nbsp;can&nbsp;be&nbsp;synchronous&nbsp;(default)&nbsp;or&nbsp;asynchronous. | 
  | callback | AsyncCallback&lt;SendRequestResult&gt; | Yes | Callback&nbsp;for&nbsp;receiving&nbsp;the&nbsp;sending&nbsp;result. | 

- Example
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function(elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.huawei.server",
      "abilityName": "com.huawei.server.MainAbility",
  };
  function sendRequestCallback(result) {
      if (result.errCode === 0) {
          console.log("sendRequest got result");
          result.reply.readException();
          let msg = result.reply.readString();
          console.log("RPCTest: reply msg: " + msg);
      } else {
          console.log("RPCTest: sendRequest failed, errCode: " + result.errCode);
      }
      console.log("RPCTest: sendRequest ends, reclaim parcel");
      result.data.reclaim();
      result.reply.reclaim();
  }
  FA.connectAbility(want, connect);
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  proxy.sendRequest(1, data, reply, option, sendRequestCallback);
  ```


### queryLocalInterface

queryLocalInterface(interface: string): IRemoteBroker

Obtains the **LocalInterface** object of an interface descriptor.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | interface | string | Yes | Interface&nbsp;descriptor. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | IRemoteBroker | Returns&nbsp;**Null**&nbsp;by&nbsp;default,&nbsp;which&nbsp;indicates&nbsp;a&nbsp;proxy&nbsp;interface. | 

- Example
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function (elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName":"com.huawei.server",
      "abilityName":"com.huawei.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let broker = proxy.queryLocalInterface("testObject");
  console.log("RpcClient: queryLocalInterface is " + broker);
  ```


### addDeathRecippient

addDeathRecipient(recipient : DeathRecipient, flags : number): boolean

Adds a callback for receiving the death notifications of the remote object, including the death notifications of the remote proxy.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes | Callback&nbsp;to&nbsp;add. | 
  | flags | number | Yes | Flag&nbsp;of&nbsp;the&nbsp;death&nbsp;notification.&nbsp;This&nbsp;parameter&nbsp;is&nbsp;reserved.&nbsp;It&nbsp;is&nbsp;set&nbsp;to&nbsp;**0**. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;callback&nbsp;is&nbsp;added&nbsp;successfully;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function(elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.huawei.server",
      "abilityName": "com.huawei.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
      }
  }
  let deathRecipient = new MyDeathRecipient();
  proxy.addDeathRecippient(deathRecipient, 0);
  ```


### removeDeathRecipient

removeDeathRecipient(recipient : DeathRecipient, flags : number): boolean

Removes the callback used to receive death notifications of the remote object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes | Callback&nbsp;to&nbsp;remove. | 
  | flags | number | Yes | Flag&nbsp;of&nbsp;the&nbsp;death&nbsp;notification.&nbsp;This&nbsp;parameter&nbsp;is&nbsp;reserved.&nbsp;It&nbsp;is&nbsp;set&nbsp;to&nbsp;**0**. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;callback&nbsp;is&nbsp;removed&nbsp;successfully;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function(elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.huawei.server",
      "abilityName": "com.huawei.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
      }
  }
  let deathRecipient = new MyDeathRecipient();
  proxy.addDeathRecippient(deathRecipient, 0);
  proxy.removeDeathRecipient(deathRecipient, 0);
  ```


### getInterfaceDescriptor

getInterfaceDescriptor(): string

Obtains the interface descriptor of this proxy object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | Interface&nbsp;descriptor&nbsp;obtained. | 

- Example
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function(elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.huawei.server",
      "abilityName": "com.huawei.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let descriptor = proxy.getInterfaceDescriptor();
  console.log("RpcClient: descriptor is " + descriptor);
  ```


### isObjectDead

isObjectDead(): boolean

Checks whether the **RemoteObject** is dead.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;**RemoteObject**&nbsp;is&nbsp;dead;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function(elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.huawei.server",
      "abilityName": "com.huawei.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let isDead = proxy.isObjectDead();
  console.log("RpcClient: isObjectDead is " + isDead);
  ```


### setDataVersion<sup>8+</sup>

setDataVersion(dataVersion: number): boolean

Sets the data format version to this **RemoteProxy** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | dataVersion | number | Yes | Data&nbsp;format&nbsp;version&nbsp;to&nbsp;set. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function(elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function(elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function() {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.huawei.server",
      "abilityName": "com.huawei.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let result = proxy.setDataVersion(1);
  console.log("RpcClient: set Data Version is " + result);
  ```


## MessageOption

Provides common message options (flag and wait time). The flag is used to construct the specified **MessageOption** object.


  | Parameters | Value | Description | 
| -------- | -------- | -------- |
| TF_SYNC | 0 | Synchronous&nbsp;call. | 
| TF_ASYNC | 1 | Asynchronous&nbsp;call. | 
| TF_ACCEPT_FDS | 0x10 | Indication&nbsp;to&nbsp;the&nbsp;[sendRequest](#sendrequest8)&nbsp;API&nbsp;for&nbsp;returning&nbsp;the&nbsp;file&nbsp;descriptor. | 
| TF_WAIT_TIME | 8 | Wait&nbsp;time,&nbsp;in&nbsp;seconds. | 


### constructor

constructor(syncFlags?: number, waitTime = TF_WAIT_TIME)

A constructor used to create a **MessageOption** instance.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | syncFlags | number | No | Specifies&nbsp;whether&nbsp;the&nbsp;**SendRequest**&nbsp;is&nbsp;called&nbsp;synchronously&nbsp;(default)&nbsp;or&nbsp;asynchronously. | 
  | waitTime | number | No | Maximum&nbsp;wait&nbsp;time&nbsp;for&nbsp;an&nbsp;RPC&nbsp;call.&nbsp;The&nbsp;default&nbsp;value&nbsp;is&nbsp;**TF_WAIT_TIME**. | 


### getFlags

getFlags(): number

Obtains the **SendRequest** call flag, which can be synchronous or asynchronous.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Whether&nbsp;the&nbsp;**SendRequest**&nbsp;is&nbsp;called&nbsp;synchronously&nbsp;or&nbsp;asynchronously. | 


### setFlags

setFlags(flags: number): void

Sets the **SendRequest** call flag, which can be synchronous or asynchronous.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | flags | number | Yes | Call&nbsp;flag,&nbsp;which&nbsp;can&nbsp;be&nbsp;synchronous&nbsp;or&nbsp;asynchronous. | 


### getWaitTime

getWaitTime(): number

Obtains the maximum wait time for this RPC call.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Maximum&nbsp;wait&nbsp;time&nbsp;obtained. | 


### setWaitTime

setWaitTime(waitTime: number): void

Sets the maximum wait time for this RPC call.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | waitTime | number | Yes | Maximum&nbsp;wait&nbsp;time&nbsp;to&nbsp;set. | 


## IPCSkeleton

Obtains IPC context information, including the UID and PID, local and peer device IDs, and whether the method is invoked on the same device.


### getContextObject

static getContextObject(): IRemoteObject

Obtains the system capability manager.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | [IRemoteObject](#iremoteobject) | System&nbsp;capability&nbsp;manager. | 

- Example
  
  ```
  let samgr = rpc.IPCSkeleton.getContextObject();
  console.log("RpcServer: getContextObject result: " + samgr);
  ```


### getCallingPid

static getCallingPid(): number

Obtains the PID of the caller. This method is invoked by the **RemoteObject** object in the **onRemoteRequest** method. If this method is not invoked in the IPC context (**onRemoteRequest**), the PID of the process will be returned.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | PID&nbsp;of&nbsp;the&nbsp;caller. | 

- Example
  
  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callerPid = rpc.IPCSkeleton.getCallingPid();
          console.log("RpcServer: getCallingPid result: " + callerPid);
          return true;
      }
  }
  ```


### getCallingUid

static getCallingUid(): number

Obtains the UID of the caller. This method is invoked by the **RemoteObject** object in the **onRemoteRequest** method. If this method is not invoked in the IPC context (**onRemoteRequest**), the UID of the process will be returned.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | UID&nbsp;of&nbsp;the&nbsp;caller. | 

- Example
  
  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callerUid = rpc.IPCSkeleton.getCallingUid();
          console.log("RpcServer: getCallingUid result: " + callerUid);
          return true;
      }
  }
  ```


### getCalligDeviceID

static getCallingDeviceID(): string

Obtains the ID of the device hosting the caller's process.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | Device&nbsp;ID&nbsp;obtained. | 

- Example
  
  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callerDeviceID = rpc.IPCSkeleton.getCalligDeviceID();
          console.log("RpcServer: callerDeviceID is: " + callerDeviceID);
          return true;
      }
  }
  ```


### getLocalDeviceID

static getLocalDeviceID(): string

Obtains the local device ID.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | Local&nbsp;device&nbsp;ID&nbsp;obtained. | 

- Example
  
  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let localDeviceID = rpc.IPCSkeleton.getLocalDeviceID();
          console.log("RpcServer: localDeviceID is: " + localDeviceID);
          return true;
      }
  }
  ```


### isLocalCalling

static isLocalCalling(): boolean

Checks whether the peer process is a process of the local device.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;local&nbsp;and&nbsp;peer&nbsp;processes&nbsp;are&nbsp;on&nbsp;the&nbsp;same&nbsp;device;&nbsp;returns&nbsp;false&nbsp;otherwise. | 

- Example
  
  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let isLocalCalling = rpc.IPCSkeleton.isLocalCalling();
          console.log("RpcServer: isLocalCalling is: " + isLocalCalling);
          return true;
      }
  }
  ```


### flushCommands

static flushCommands(object : IRemoteObject): number

Flushes all suspended commands from the specified **RemoteProxy** to the corresponding **RemoteObject**. It is recommended that this method be called before any time-sensitive operation is performed.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | object | [IRemoteObject](#iremoteobject) | Yes | **RemoteProxy**. | 


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Returns&nbsp;**0**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;an&nbsp;error&nbsp;code&nbsp;if&nbsp;the&nbsp;input&nbsp;object&nbsp;is&nbsp;null&nbsp;or&nbsp;a&nbsp;**RemoteObject**,&nbsp;or&nbsp;the&nbsp;operation&nbsp;fails. | 

- Example
  
  ```
  let remoteObject = new rpc.RemoteObject("aaa", 3);
  let ret = rpc.IPCSkeleton.flushCommands(remoteObject);
  console.log("RpcServer: flushCommands result: " + ret);
  ```


### resetCallingIdentity

static resetCallingIdentity(): string

Changes the UID and PID of the remote user to the UID and PID of the local user. This method is used in scenarios such as identity authentication.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | String&nbsp;containing&nbsp;the&nbsp;UID&nbsp;and&nbsp;PID&nbsp;of&nbsp;the&nbsp;remote&nbsp;user. | 

- Example
  
  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();
          console.log("RpcServer: callingIdentity is: " + callingIdentity);
          return true;
      }
  }
  ```


### setCallingIdentity

static setCallingIdentity(identity : string): boolean

Restores the UID and PID of the remote user. It is usually called when the UID and PID of the remote user are required. The UID and PID of the remote user are returned by **resetCallingIdentity**.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | identity | string | Yes | String&nbsp;containing&nbsp;the&nbsp;remote&nbsp;user&nbsp;UID&nbsp;and&nbsp;PID,&nbsp;which&nbsp;are&nbsp;returned&nbsp;by&nbsp;**resetCallingIdentity**. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callingIdentity = null;
          try {
              callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();
              console.log("RpcServer: callingIdentity is: " + callingIdentity);
          } finally {
              let ret = rpc.IPCSkeleton.setCallingIdentity("callingIdentity ");
              console.log("RpcServer: setCallingIdentity is: " + ret);
          }
          return true;
      }
  }
  ```


## RemoteObject

Provides methods to implement **RemoteObject**. The service provider must inherit from this class.


### constructor

constructor(descriptor: string)

A constructor used to create a **RemoteObject** instance.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | descriptor | string | Yes | Interface&nbsp;descriptor. | 


### sendRequest

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;number&gt;<sup>7</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;<sup>8+</sup>

Sends a **MessageParcel** message to the peer process in synchronous or asynchronous mode. If **options** indicates the asynchronous mode, a promise will be fulfilled immediately and the **reply** message does not contain any content. If **options** indicates the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | code | number | Yes | Message&nbsp;code&nbsp;called&nbsp;by&nbsp;the&nbsp;request,&nbsp;which&nbsp;is&nbsp;determined&nbsp;by&nbsp;the&nbsp;client&nbsp;and&nbsp;server.&nbsp;If&nbsp;the&nbsp;method&nbsp;is&nbsp;generated&nbsp;by&nbsp;an&nbsp;IDL&nbsp;tool,&nbsp;the&nbsp;message&nbsp;code&nbsp;is&nbsp;automatically&nbsp;generated&nbsp;by&nbsp;the&nbsp;IDL&nbsp;tool. | 
  | data | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;holding&nbsp;the&nbsp;data&nbsp;to&nbsp;send. | 
  | reply | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;that&nbsp;receives&nbsp;the&nbsp;response. | 
  | options | [MessageOption](#messageoption) | Yes | Request&nbsp;sending&nbsp;mode,&nbsp;which&nbsp;can&nbsp;be&nbsp;synchronous&nbsp;(default)&nbsp;or&nbsp;asynchronous. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Promise&lt;number&gt;<sup>7</sup><br/>Promise&lt;SendRequestResult&gt;<sup>8+</sup> | Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;result.&nbsp;The&nbsp;value&nbsp;**0**&nbsp;will&nbsp;be&nbsp;returned&nbsp;if&nbsp;the&nbsp;request&nbsp;is&nbsp;sent&nbsp;successfully.&nbsp;Otherwise,&nbsp;an&nbsp;error&nbsp;code&nbsp;will&nbsp;be&nbsp;returned.&nbsp;<sup>7</sup><br/>Promise&nbsp;used&nbsp;to&nbsp;return&nbsp;the&nbsp;**sendRequestResult**&nbsp;instance.&nbsp;<sup>8+</sup> | 


- Example<sup>7</sup>
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  testRemoteObject.sendRequest(1, data, reply, option)
      .then(function(errCode) {
          if (errCode === 0) {
              console.log("sendRequest got result");
              let msg = reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendRequest failed, errCode: " + errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendRequest got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendRequest ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```


- Example<sup>8+</sup>
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  testRemoteObject.sendRequest(1, data, reply, option)
      .then(function(result) {
          if (result.errCode === 0) {
              console.log("sendRequest got result");
              result.reply.readException();
              let msg = result.reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendRequest failed, errCode: " + result.errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendRequest got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendRequest ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```


### sendRequest<sup>8+</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the peer process in synchronous or asynchronous mode. If **options** indicates the asynchronous mode, a callback will be invoked immediately and the **reply** message does not contain any content. If **options** indicates the synchronous mode, a callback will be invoked when the response to **sendRequest** is returned, and the **reply** message contains the returned information.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | code | number | Yes | Message&nbsp;code&nbsp;called&nbsp;by&nbsp;the&nbsp;request,&nbsp;which&nbsp;is&nbsp;determined&nbsp;by&nbsp;the&nbsp;client&nbsp;and&nbsp;server.&nbsp;If&nbsp;the&nbsp;method&nbsp;is&nbsp;generated&nbsp;by&nbsp;an&nbsp;IDL&nbsp;tool,&nbsp;the&nbsp;message&nbsp;code&nbsp;is&nbsp;automatically&nbsp;generated&nbsp;by&nbsp;the&nbsp;IDL&nbsp;tool. | 
  | data | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;holding&nbsp;the&nbsp;data&nbsp;to&nbsp;send. | 
  | reply | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;that&nbsp;receives&nbsp;the&nbsp;response. | 
  | options | [MessageOption](#messageoption) | Yes | Request&nbsp;sending&nbsp;mode,&nbsp;which&nbsp;can&nbsp;be&nbsp;synchronous&nbsp;(default)&nbsp;or&nbsp;asynchronous. | 
  | AsyncCallback | AsyncCallback&lt;SendRequestResult&gt; | Yes | Callback&nbsp;for&nbsp;receiving&nbsp;the&nbsp;sending&nbsp;result. | 


- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  function sendRequestCallback(result) {
      if (result.errCode === 0) {
          console.log("sendRequest got result");
          result.reply.readException();
          let msg = result.reply.readString();
          console.log("RPCTest: reply msg: " + msg);
      } else {
          console.log("RPCTest: sendRequest failed, errCode: " + result.errCode);
      }
      console.log("RPCTest: sendRequest ends, reclaim parcel");
      result.data.reclaim();
      result.reply.reclaim();
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  testRemoteObject.sendRequest(1, data, reply, option, sendRequestCallback);
  ```


### onRemoteRequest

onRemoteRequest(code : number, data : MessageParcel, reply: MessageParcel, options : MessageOption): boolean

Provides a response to **sendRequest()**. The server processes the request and returns a response in this function.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | code | number | Yes | Service&nbsp;request&nbsp;code&nbsp;sent&nbsp;by&nbsp;the&nbsp;peer&nbsp;end. | 
  | data | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;that&nbsp;holds&nbsp;the&nbsp;parameters&nbsp;called&nbsp;by&nbsp;the&nbsp;client. | 
  | reply | [MessageParcel](#messageparcel) | Yes | **MessageParcel**&nbsp;object&nbsp;carrying&nbsp;the&nbsp;result. | 
  | option | [MessageOption](#messageoption) | Yes | Whether&nbsp;the&nbsp;operation&nbsp;is&nbsp;synchronous&nbsp;or&nbsp;asynchronous. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 


- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  
      onRemoteRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: onRemoteRequest called");
              return true;
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
      }
  }
  ```


### getCallingUid

getCallingUid(): number

Obtains the UID of the peer process.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | UID&nbsp;of&nbsp;the&nbsp;peer&nbsp;process&nbsp;obtained. | 


- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  console.log("RpcServer: getCallingUid: " + testRemoteObject.getCallingUid());
  ```


### getCallingPid

getCallingPid(): number

Obtains the PID of the peer process.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | PID&nbsp;of&nbsp;the&nbsp;peer&nbsp;process&nbsp;obtained. | 


- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  console.log("RpcServer: getCallingPid: " + testRemoteObject.getCallingPid());
  ```


### queryLocalInterface

queryLocalInterface(descriptor: descriptor): IRemoteBroker

Checks whether the remote object corresponding to the specified interface descriptor exists.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | descriptor | descriptor | Yes | Interface&nbsp;descriptor. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | IRemoteBroker | Returns&nbsp;the&nbsp;remote&nbsp;object&nbsp;if&nbsp;a&nbsp;match&nbsp;is&nbsp;found;&nbsp;returns&nbsp;**Null**&nbsp;otherwise. | 


- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  let broker = testRemoteObject.queryLocalInterface("testObject");
  ```


### getInterfaceDescriptor

getInterfaceDescriptor(): string

Obtains the interface descriptor.

- Return values
    | Type | Description | 
  | -------- | -------- |
  | string | Interface&nbsp;descriptor&nbsp;obtained. | 


- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  let descriptor = testRemoteObject.getInterfaceDescriptor();
  console.log("RpcServer: descriptor is: " + descriptor);
  ```


### attachLocalInterface

attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void

Binds an interface descriptor to an **IRemoteBroker** object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | localInterface | IRemoteBroker | Yes | **IRemoteBroker**&nbsp;object. | 
  | descriptor | string | Yes | Interface&nbsp;descriptor. | 


- Example
  
  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
          this.attachLocalInterface(this, descriptor);
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  ```


## Ashmem<sup>8+</sup>

Provides methods related to anonymous shared memory objects, including creating, closing, mapping, and unmapping an **Ashmem** object, reading data from and writing data to an **Ashmem** object, obtaining the **Ashmem** size, and setting **Ashmem** protection.

The following table describes the protection types of the mapped memory.

  | Name | Value | Description | 
| -------- | -------- | -------- |
| PROT_EXEC | 4 | The&nbsp;mapped&nbsp;memory&nbsp;is&nbsp;executable. | 
| PROT_NONE | 0 | The&nbsp;mapped&nbsp;memory&nbsp;is&nbsp;inaccessible. | 
| PROT_READ | 1 | The&nbsp;mapped&nbsp;memory&nbsp;is&nbsp;readable. | 
| PROT_WRITE | 2 | The&nbsp;mapped&nbsp;memory&nbsp;is&nbsp;writeable. | 


### createAshmem

static createAshmem(name: string, size: number): Ashmem

Creates an **Ashmem** object with the specified name and size.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | name | string | Yes | Name&nbsp;of&nbsp;the&nbsp;**Ashmem**&nbsp;object&nbsp;to&nbsp;create. | 
  | size | number | Yes | Size&nbsp;(in&nbsp;bytes)&nbsp;of&nbsp;the&nbsp;**Ashmem**&nbsp;object&nbsp;to&nbsp;create. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Ashmem | Returns&nbsp;the&nbsp;**Ashmem**&nbsp;object&nbsp;if&nbsp;it&nbsp;is&nbsp;created&nbsp;successfully;&nbsp;returns&nbsp;**null**&nbsp;otherwise. | 


- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashemm by createAshmem : " + ashmem + " size is : " + size);
  ```


### createAshmemFromExisting

static createAshmemFromExisting(ashmem: Ashmem): Ashmem

Creates an **Ashmem** object by copying the file descriptor (FD) of an existing **Ashmem** object. The two **Ashmem** objects point to the same shared memory region.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | ashmem | Ashmem | Yes | Existing&nbsp;**Ashmem**&nbsp;object. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | Ashmem | **Ashmem**&nbsp;object&nbsp;created. | 


- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let ashmem2 = rpc.Ashmem.createAshmemFromExisting(ashmem);
  let size = ashmem2.getAshmemSize();
  console.log("RpcTest: get ashemm by createAshmemFromExisting : " + ashmem2 + " size is : " + size);
  ```


### closeAshmem

closeAshmem(): void

Closes this **Ashmem** object.


- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  ashmem.closeAshmem();
  ```


### unmapAshmem

unmapAshmem(): void

Deletes the mappings for the specified address range of this **Ashmem** object.


- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  ashmem.unmapAshmem();
  ```


### getAshmemSize

getAshmemSize(): number

Obtains the memory size of this **Ashmem** object.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | number | Memory&nbsp;size&nbsp;obtained. | 

- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashmem is " + ashmem + " size is : " + size);
  ```


### mapAshmem

mapAshmem(mapType: number): boolean

Creates the shared file mapping on the virtual address space of this process. The size of the mapping region is specified by this **Ashmem** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | mapType | number | Yes | Protection&nbsp;level&nbsp;of&nbsp;the&nbsp;memory&nbsp;region&nbsp;to&nbsp;which&nbsp;the&nbsp;shared&nbsp;file&nbsp;is&nbsp;mapped. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapReadAndWrite = ashmem.mapAshmem(rpc.Ashmem.PROT_READ | rpc.Ashmem.PROT_WRITE);
  console.log("RpcTest: map ashmem result is  : " + mapReadAndWrite);
  ```


### mapReadAndWriteAshmem

mapReadAndWriteAshmem(): boolean

Maps the shared file to the readable and writable virtual address space of the process.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadAndWriteAshmem();
  console.log("RpcTest: map ashmem result is  : " + mapResult);
  ```


### mapReadOnlyAshmem

mapReadOnlyAshmem(): boolean

Maps the shared file to the read-only virtual address space of the process.


- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadOnlyAshmem();
  console.log("RpcTest: Ashmem mapReadOnlyAshmem result is : " + mapResult);
  ```


### setProtection

setProtection(protectionType: number): boolean

Sets the protection level of the memory region to which the shared file is mapped.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | protectionType | number | Yes | Protection&nbsp;type&nbsp;to&nbsp;set. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;if&nbsp;the&nbsp;operation&nbsp;is&nbsp;successful;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let result = ashmem.setProtection(rpc.Ashmem.PROT_READ);
  console.log("RpcTest: Ashmem setProtection result is : " + result);
  ```


### writeToAshmem

writeToAshmem(buf: number[], size: number, offset: number): boolean

Writes data to the shared file associated with this **Ashmem** object.


- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | buf | number[] | Yes | Data&nbsp;to&nbsp;write. | 
  | size | number | Yes | Size&nbsp;of&nbsp;the&nbsp;data&nbsp;to&nbsp;write. | 
  | offset | number | Yes | Start&nbsp;position&nbsp;of&nbsp;the&nbsp;data&nbsp;to&nbsp;write&nbsp;in&nbsp;the&nbsp;memory&nbsp;region&nbsp;associated&nbsp;with&nbsp;this&nbsp;**Ashmem**&nbsp;object. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | boolean | Returns&nbsp;**true**&nbsp;is&nbsp;the&nbsp;data&nbsp;is&nbsp;written&nbsp;successfully;&nbsp;returns&nbsp;**false**&nbsp;otherwise. | 

- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  var ByteArrayVar = new Int8Array([1, 2, 3, 4, 5]);
  let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);
  console.log("RpcTest: write to Ashmem result is  : " + writeResult);
  ```


### readFromAshmem

readFromAshmem(size: number, offset: number): number[]

Reads data from the shared file associated with this **Ashmem** object.

- Parameters
    | Name | Type | Mandatory | Description | 
  | -------- | -------- | -------- | -------- |
  | size | number | Yes | Size&nbsp;of&nbsp;the&nbsp;data&nbsp;to&nbsp;read. | 
  | offset | number | Yes | Start&nbsp;position&nbsp;of&nbsp;the&nbsp;data&nbsp;to&nbsp;read&nbsp;in&nbsp;the&nbsp;memory&nbsp;region&nbsp;associated&nbsp;with&nbsp;this&nbsp;**Ashmem**&nbsp;object. | 

- Return values
    | Type | Description | 
  | -------- | -------- |
  | number[] | Data&nbsp;read. | 


- Example
  
  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  var ByteArrayVar = new Int8Array([1, 2, 3, 4, 5]);
  let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);
  console.log("RpcTest: write to Ashmem result is  : " + writeResult);
  let readResult = ashmem.readFromAshmem(5, 0);
  console.log("RpcTest: read to Ashmem result is  : " + readResult);
  ```
