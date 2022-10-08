# RPC

The **RPC** module implements communication between processes, including inter-process communication (IPC) on a single device and Remote Procedure Call (RPC) between processes on difference devices. IPC is implemented based on the Binder driver, and RPC is based on the DSoftBus driver.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import


```
import rpc from '@ohos.rpc';
```


## MessageParcel

Provides APIs for reading and writing data in specific format. During RPC, the sender can use the **write()** method provided **MessageParcel** to write data to a **MessageParcel** object in specific format. The receiver can use the **read()** method provided by **MessageParcel** to read data in specific format from a **MessageParcel** object. The data formats include basic data types and arrays, IPC objects, interface tokens, and custom sequenceable objects.


### create

create(): MessageParcel

Creates a **MessageParcel** object. This method is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | MessageParcel | **MessageParcel** object created.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  console.log("RpcClient: data is " + data);
  ```


### reclaim

reclaim(): void

Reclaims the **MessageParcel** object that is no longer used.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```
  let reply = rpc.MessageParcel.create();
  reply.reclaim();
  ```


### writeRemoteObject

writeRemoteObject(object: [IRemoteObject](#iremoteobject)): boolean

  Serializes a remote object and writes it to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | object | [IRemoteObject](#iremoteobject) | Yes| Remote object to serialize and write to the **MessageParcel** object.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
  }
  let data = rpc.MessageParcel.create();
  let testRemoteObject = new TestRemoteObject("testObject");
  data.writeRemoteObject(testRemoteObject);
  ```


### readRemoteObject

readRemoteObject(): IRemoteObject

Reads the remote object from this **MessageParcel** object. You can use this method to deserialize the **MessageParcel** object to generate an **IRemoteObject**. The remote objects are read in the order in which they are written to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | [IRemoteObject](#iremoteobject) | Remote object obtained.|

**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
  }
  let data = rpc.MessageParcel.create();
  let testRemoteObject = new TestRemoteObject("testObject");
  data.writeRemoteObject(testRemoteObject);
  let proxy = data.readRemoteObject();
  ```


### writeInterfaceToken

writeInterfaceToken(token: string): boolean

Writes an interface token to this **MessageParcel** object. The remote object can use this interface token to verify the communication.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | token | string | Yes| Interface token to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInterfaceToken("aaa");
  console.log("RpcServer: writeInterfaceToken is " + result);
  ```


### readInterfaceToken

readInterfaceToken(): string

Reads the interface token from this **MessageParcel** object. The interface token is read in the sequence in which it is written to the **MessageParcel** object. The local object can use it to verify the communication.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Interface token obtained.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Size of the **MessageParcel** object obtained, in bytes.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let size = data.getSize();
  console.log("RpcClient: size is " + size);
  ```


### getCapacity

getCapacity(): number

Obtains the capacity of this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | **MessageParcel** capacity obtained, in bytes.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.getCapacity();
  console.log("RpcClient: capacity is " + result);
  ```


### setSize

setSize(size: number): boolean

Sets the size of data contained in this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | size | number | Yes| Data size to set, in bytes.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let setSize = data.setSize(16);
  console.log("RpcClient: setSize is " + setSize);
  ```


### setCapacity

setCapacity(size: number): boolean

Sets the storage capacity of this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | size | number | Yes| Storage capacity to set, in bytes.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.setCapacity(100);
  console.log("RpcClient: setCapacity is " + result);
  ```


### getWritableBytes

getWritableBytes(): number

Obtains the writable capacity of this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | **MessageParcel** writable capacity obtained, in bytes.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | **MessageParcel** object readable capacity, in bytes.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Current read position of the **MessageParcel** object.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let readPos = data.getReadPosition();
  console.log("RpcClient: readPos is " + readPos);
  ```


### getWritePosition

getWritePosition(): number

Obtains the write position of this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Current write position of the **MessageParcel** object.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  data.writeInt(10);
  let bwPos = data.getWritePosition();
  console.log("RpcClient: bwPos is " + bwPos);
  ```


### rewindRead

rewindRead(pos: number): boolean

Moves the read pointer to the specified position.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pos | number | Yes| Position from which data is to read.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the read position changes; returns **false** otherwise.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | pos | number | Yes| Position from which data is to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the write position changes; returns **false** otherwise.|

**Example**

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

Writes a Byte value to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | val | number | Yes| Byte value to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeByte(2);
  console.log("RpcClient: writeByte is: " + result);
  ```


### readByte

readByte(): number

Reads the Byte value from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Byte value read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeByte(2);
  console.log("RpcClient: writeByte is: " + result);
  let ret = data.readByte();
  console.log("RpcClient: readByte is: " + ret);
  ```


### writeShort

writeShort(val: number): boolean

Writes a Short int value to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | val | number | Yes| Short int value to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShort(8);
  console.log("RpcClient: writeShort is: " + result);
  ```


### readShort

readShort(): number

Reads the Short int value from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Short int value read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShort(8);
  console.log("RpcClient: writeShort is: " + result);
  let ret = data.readShort();
  console.log("RpcClient: readShort is: " + ret);
  ```


### writeInt

writeInt(val: number): boolean

Writes an Int value to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | val | number | Yes| Int value to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInt(10);
  console.log("RpcClient: writeInt is " + result);
  ```


### readInt

readInt(): number

Reads the Int value from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Int value read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInt(10);
  console.log("RpcClient: writeInt is " + result);
  let ret = data.readInt();
  console.log("RpcClient: readInt is " + ret);
  ```


### writeLong

writeLong(val: number): boolean

Writes a Long int value to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | val | number | Yes| Long int value to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLong(10000);
  console.log("RpcClient: writeLong is " + result);
  ```


### readLong

readLong(): number

Reads the Long int value from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Long int value read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLong(10000);
  console.log("RpcClient: writeLong is " + result);
  let ret = data.readLong();
  console.log("RpcClient: readLong is " + ret);
  ```


### writeFloat

writeFloat(val: number): boolean

Writes a Float value to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | val | number | Yes| Float value to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloat(1.2);
  console.log("RpcClient: writeFloat is " + result);
  ```


### readFloat

readFloat(): number

Reads the Float value from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Float value read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloat(1.2);
  console.log("RpcClient: writeFloat is " + result);
  let ret = data.readFloat();
  console.log("RpcClient: readFloat is " + ret);
  ```


### writeDouble

writeDouble(val: number): boolean

Writes a Double value to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | val | number | Yes| Double value to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDouble(10.2);
  console.log("RpcClient: writeDouble is " + result);
  ```


### readDouble

readDouble(): number

Reads the Double value from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Double value read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDouble(10.2);
  console.log("RpcClient: writeDouble is " + result);
  let ret = data.readDouble();
  console.log("RpcClient: readDouble is " + ret);
  ```


### writeBoolean

writeBoolean(val: boolean): boolean

Writes a Boolean value to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | val | boolean | Yes| Boolean value to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBoolean(false);
  console.log("RpcClient: writeBoolean is " + result);
  ```


### readBoolean

readBoolean(): boolean

Reads the Boolean value from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Boolean value read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBoolean(false);
  console.log("RpcClient: writeBoolean is " + result);
  let ret = data.readBoolean();
  console.log("RpcClient: readBoolean is " + ret);
  ```


### writeChar

writeChar(val: number): boolean

Writes a Char value to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | val | number | Yes| Char value to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeChar(97);
  console.log("RpcClient: writeChar is " + result);
  ```


### readChar

readChar(): number

Reads the Char value from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Char value read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeChar(97);
  console.log("RpcClient: writeChar is " + result);
  let ret = data.readChar();
  console.log("RpcClient: readChar is " + ret);
  ```


### writeString

writeString(val: string): boolean

Writes a string to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | val | string | Yes| String to write. The length of the string must be less than 40960 bytes.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeString('abc');
  console.log("RpcClient: writeString  is " + result);
  ```


### readString

readString(): string

Reads a string from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | String read.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | val | [Sequenceable](#sequenceable) | Yes| Sequenceable object to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  class MySequenceable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
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

Reads member variables from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | [Sequenceable](#sequenceable) | Yes| Object that reads member variables from the **MessageParcel** object.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  class MySequenceable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
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

Writes a byte array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | byteArray | number[] | Yes| Byte array to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let result = data.writeByteArray(ByteArrayVar);
  console.log("RpcClient: writeByteArray is " + result);
  ```


### readByteArray

readByteArray(dataIn: number[]) : void

Reads a byte array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes| Byte array to read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let result = data.writeByteArray(ByteArrayVar);
  console.log("RpcClient: writeByteArray is " + result);
  let array = new Array(5);
  data.readByteArray(array);
  ```


### readByteArray

readByteArray(): number[]

Reads the byte array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number[] | Byte array read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let result = data.writeByteArray(ByteArrayVar);
  console.log("RpcClient: writeByteArray is " + result);
  let array = data.readByteArray();
  console.log("RpcClient: readByteArray is " + array);
  ```


### writeShortArray

writeShortArray(shortArray: number[]): boolean

Writes a short array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | shortArray | number[] | Yes| Short array to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  ```


### readShortArray

readShortArray(dataIn: number[]) : void

Reads a short array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes| Short array to read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  let array = new Array(3);
  data.readShortArray(array);
  ```


### readShortArray

readShortArray(): number[]

Reads the short array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number[] | Short array read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  let array = data.readShortArray();
  console.log("RpcClient: readShortArray is " + array);
  ```


### writeIntArray

writeIntArray(intArray: number[]): boolean

Writes an integer array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | intArray | number[] | Yes| Integer array to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  ```


### readIntArray

readIntArray(dataIn: number[]) : void

Reads an integer array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes| Integer array to read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  let array = new Array(3);
  data.readIntArray(array);
  ```


### readIntArray

readIntArray(): number[]

Reads the integer array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number[] | Integer array read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  let array = data.readIntArray();
  console.log("RpcClient: readIntArray is " + array);
  ```


### writeLongArray

writeLongArray(longArray: number[]): boolean

Writes a long array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | longArray | number[] | Yes| Long array to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  ```


### readLongArray

readLongArray(dataIn: number[]) : void

Reads a long array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes| Long array to read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  let array = new Array(3);
  data.readLongArray(array);
  ```


### readLongArray

readLongArray(): number[]

Reads the long array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number[] | Long array read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  let array = data.readLongArray();
  console.log("RpcClient: readLongArray is " + array);
  ```


### writeFloatArray

writeFloatArray(floatArray: number[]): boolean

Writes a FloatArray to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | floatArray | number[] | Yes| FloatArray to write. The system processes Float data as that of the Double type. Therefore, the total number of bytes occupied by a FloatArray must be calculated as the Double type.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  ```


### readFloatArray

readFloatArray(dataIn: number[]) : void

Reads a FloatArray from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes| FloatArray to read. The system processes Float data as that of the Double type. Therefore, the total number of bytes occupied by a FloatArray must be calculated as the Double type.|


**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  let array = new Array(3);
  data.readFloatArray(array);
  ```


### readFloatArray

readFloatArray(): number[]

Reads the FloatArray from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number[] | FloatArray read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  let array = data.readFloatArray();
  console.log("RpcClient: readFloatArray is " + array);
  ```


### writeDoubleArray

writeDoubleArray(doubleArray: number[]): boolean

Writes a DoubleArray to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | doubleArray | number[] | Yes| DoubleArray to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  ```


### readDoubleArray

readDoubleArray(dataIn: number[]) : void

Reads a DoubleArray from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes| DoubleArray to read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  let array = new Array(3);
  data.readDoubleArray(array);
  ```


### readDoubleArray

readDoubleArray(): number[]

Reads the DoubleArray from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number[] | DoubleArray read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  let array = data.readDoubleArray();
  console.log("RpcClient: readDoubleArray is " + array);
  ```


### writeBooleanArray

writeBooleanArray(booleanArray: boolean[]): boolean

Writes a Boolean array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | booleanArray | boolean[] | Yes| Boolean array to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  ```


### readBooleanArray

readBooleanArray(dataIn: boolean[]) : void

Reads a Boolean array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | boolean[] | Yes| Boolean array to read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  let array = new Array(3);
  data.readBooleanArray(array);
  ```


### readBooleanArray

readBooleanArray(): boolean[]

Reads the Boolean array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean[] | Boolean array read.|


  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  let array = data.readBooleanArray();
  console.log("RpcClient: readBooleanArray is " + array);
  ```


### writeCharArray

writeCharArray(charArray: number[]): boolean

Writes a character array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | charArray | number[] | Yes| Character array to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 88]);
  console.log("RpcClient: writeCharArray is " + result);
  ```


### readCharArray

readCharArray(dataIn: number[]) : void

Reads a character array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | Yes| Character array to read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 99]);
  console.log("RpcClient: writeCharArray is " + result);
  let array = new Array(3);
  data.readCharArray(array);
  ```


### readCharArray

readCharArray(): number[]

Reads the character array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number[] | Character array read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 99]);
  console.log("RpcClient: writeCharArray is " + result);
  let array = data.readCharArray();
  console.log("RpcClient: readCharArray is " + array);
  ```


### writeStringArray

writeStringArray(stringArray: string[]): boolean

Writes a string array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | stringArray | string[] | Yes| String array to write. The length of a single element in the array must be less than 40960 bytes.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  console.log("RpcClient: writeStringArray is " + result);
  ```


### readStringArray

readStringArray(dataIn: string[]) : void

Reads a string array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | string[] | Yes| String array to read.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  console.log("RpcClient: writeStringArray is " + result);
  let array = new Array(2);
  data.readStringArray(array);
  ```


### readStringArray

readStringArray(): string[]

Reads the string array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string[] | String array read.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
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

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

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
      "bundleName": "com.ohos.server",
      "abilityName": "com.ohos.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  proxy.sendRequestAsync(1, data, reply, option)
      .then(function(errCode) {
          if (errCode === 0) {
              console.log("sendRequestAsync got result");
              reply.readException();
              let msg = reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendRequestAsync failed, errCode: " + errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendRequestAsync got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendRequestAsync ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```


### writeSequenceableArray

writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean

Writes a sequenceable array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | sequenceableArray | Sequenceable[] | Yes| Sequenceable array to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  class MySequenceable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
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

Reads a sequenceable array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | sequenceableArray | Sequenceable[] | Yes| Sequenceable array to read.|

**Example**

  ```
  class MySequenceable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
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

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | objectArray | IRemoteObject[] | Yes| Array of **IRemoteObject** objects to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** if the operation fails or if the **IRemoteObject** array is null.|

**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
          this.attachLocalInterface(this, descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
      asObject(): rpc.IRemoteObject {
          return this;
      }
  }
  let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
  let data = rpc.MessageParcel.create();
  let result = data.writeRemoteObjectArray(a);
  console.log("RpcClient: writeRemoteObjectArray is " + result);
  ```


### readRemoteObjectArray<sup>8+</sup>

readRemoteObjectArray(objects: IRemoteObject[]): void

Reads an **IRemoteObject** array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | objects | IRemoteObject[] | Yes| **IRemoteObject** array to read.|

**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
          this.attachLocalInterface(this, descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
      asObject(): rpc.IRemoteObject {
          return this;
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

Reads the **IRemoteObject** array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | IRemoteObject[] | **IRemoteObject** object array obtained.|

**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
          this.attachLocalInterface(this, descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
      asObject(): rpc.IRemoteObject {
          return this;
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

Closes a file descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | fd | number | Yes| File descriptor to close.|

**Example**

  ```
  import fileio from '@ohos.fileio';
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  rpc.MessageParcel.closeFileDescriptor(fd);
  ```


### dupFileDescriptor<sup>8+</sup>

static dupFileDescriptor(fd: number) :number

Duplicates a file descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | fd | number | Yes| File descriptor to duplicate.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | New file descriptor.|

**Example**

  ```
  import fileio from '@ohos.fileio';
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  let newFd = rpc.MessageParcel.dupFileDescriptor(fd);
  ```


### containFileDescriptors<sup>8+</sup>

containFileDescriptors(): boolean

Checks whether this **MessageParcel** object contains a file descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the **MessageParcel** object contains a file descriptor; returns **false** otherwise.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | fd | number | Yes| File descriptor to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

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

Reads the file descriptor from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | File descriptor read.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ashmem | Ashmem | Yes| Anonymous shared object to write.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let parcel = new rpc.MessageParcel();
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);
  let isWriteSuccess = parcel.writeAshmem(ashmem);
  console.log("RpcTest: write ashmem to result is : " + isWriteSuccess);
  ```


### readAshmem<sup>8+</sup>

readAshmem(): Ashmem

Reads the anonymous shared object from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Ashmem | Anonymous share object obtained.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | 128 MB, which is the maximum amount of raw data that can be held by this **MessageParcel** object.|

**Example**

  ```
  let parcel = new rpc.MessageParcel();
  let result = parcel.getRawDataCapacity();
  console.log("RpcTest: parcel get RawDataCapacity result is : " + result);
  ```


### writeRawData<sup>8+</sup>

writeRawData(rawData: number[], size: number): boolean

Writes raw data to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | rawData | number[] | Yes| Raw data to write.|
  | size | number | Yes| Size of the raw data, in bytes.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let parcel = new rpc.MessageParcel();
  let arr = [1, 2, 3, 4, 5];
  let isWriteSuccess = parcel.writeRawData(arr, arr.length);
  console.log("RpcTest: parcel write raw data result is : " + isWriteSuccess);
  ```


### readRawData<sup>8+</sup>

readRawData(size: number): number[]

Reads raw data from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | size | number | Yes| Size of the raw data to read.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number[] | Raw data obtained, in bytes.|

**Example**

  ```
  let parcel = new rpc.MessageParcel();
  let arr = [1, 2, 3, 4, 5];
  let isWriteSuccess = parcel.writeRawData(arr, arr.length);
  console.log("RpcTest: parcel write raw data result is : " + isWriteSuccess);
  let result = parcel.readRawData(5);
  console.log("RpcTest: parcel read raw data result is : " + result);
  ```

## Sequenceable

Writes objects of classes to a **MessageParcel** and reads them from the **MessageParcel** during IPC.


### marshalling

marshalling(dataOut: MessageParcel): boolean

Marshals the sequenceable object into a **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataOut | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object to which the sequenceable object is to be marshaled.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  class MySequenceable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
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

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | dataIn | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object in which the sequenceable object is to be unmarshaled.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  class MySequenceable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
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

Provides the holder of a remote proxy object.


### asObject

asObject(): IRemoteObject

Obtains a proxy or remote object. This API must be implemented by its derived classes.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | [IRemoteObject](#iremoteobject) | Returns the [RemoteObject](#ashmem8) if it is the caller; returns the [IRemoteObject](#iremoteobject), the holder of this **RemoteProxy** object, if the caller is a [RemoteProxy](#remoteproxy) object.|

**Example**

  ```
  class TestAbility extends rpc.RemoteObject {
      asObject() {
          return this;
      }
  }
  ```

**Example**

  ```
  class TestProxy {
      remote: rpc.RemoteObject;
      constructor(remote) {
          this.remote = remote;
      }
      asObject() {
          return this.remote;
      }
  }
  ```


## DeathRecipient

Subscribes to death notifications of a remote object. When the remote object is dead, the local end will receive a notification and **[onRemoteDied](#onremotedied)** will be called. A remote object is dead when the process holding the object is terminated or the device of the remote object is shut down or restarted. If the local and remote objects belong to different devices, the remote object is dead when the device holding the remote object is detached from the network. 


### onRemoteDied

onRemoteDied(): void

Called to perform subsequent operations when a death notification of the remote object is received.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  ```


## SendRequestResult<sup>8+</sup>

Defines the response to the request.

**System capability**: SystemCapability.Communication.IPC.Core

  | Parameter| Value| Description|
| -------- | -------- | -------- |
| errCode | number | Error Code|
| code | number | Message code.|
| data | MessageParcel | **MessageParcel** object sent to the remote process.|
| reply | MessageParcel | **MessageParcel** object returned by the remote process.|


## IRemoteObject

Provides methods to query of obtain interface descriptors, add or delete death notifications, dump object status to specific files, and send messages.


### queryLocalInterface

queryLocalInterface(descriptor: string): IRemoteBroker

Obtains the interface.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | descriptor | string | Yes| Interface descriptor.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | IRemoteBroker | **IRemoteBroker** object bound to the specified interface descriptor.|


### sendRequest<sup>(deprecated)</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): boolean

> **NOTE**<br/>
> This API is deprecated since API version 8. You are advised to use [sendRequestAsync<sup>9+</sup>](#sendrequestasync9).

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


### sendRequest<sup>8+(deprecated)</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;

> **NOTE**<br/>
> This API is deprecated since API version 9. You are advised to use [sendRequestAsync<sup>9+</sup>](#sendrequestasync9).

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;SendRequestResult&gt; | Promise used to return the **sendRequestResult** object.|

### sendRequestAsync<sup>9+</sup>

sendRequestAsync(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequestAsync** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;SendRequestResult&gt; | Promise used to return the **sendRequestResult** object.|

### sendRequest<sup>8+</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a callback will be invoked immediately and the reply message does not contain any content. If **options** is the synchronous mode, a callback will be invoked when the response to sendRequest is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|
  | callback | AsyncCallback&lt;SendRequestResult&gt; | Yes| Callback for receiving the sending result.|


### addDeathrecipient

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Adds a callback for receiving death notifications of the remote object. This method is called if the remote object process matching the **RemoteProxy** object is killed.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes| Callback to add.|
  | flags | number | Yes| Flag of the death notification.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the callback is added successfully; returns **false** otherwise.|


### removeDeathRecipient

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Removes the callback used to receive death notifications of the remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes| Callback to remove.|
  | flags | number | Yes| Flag of the death notification.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the callback is removed successfully; returns **false** otherwise.|


### getInterfaceDescriptor

getInterfaceDescriptor(): string

Obtains the interface descriptor of this object. The interface descriptor is a string.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Interface descriptor obtained.|


### isObjectDead

isObjectDead(): boolean

Checks whether this object is dead.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the object is dead; returns **false** otherwise.|


## RemoteProxy

Provides methods to implement **IRemoteObject**.

**System capability**: SystemCapability.Communication.IPC.Core

| Parameter                 | Value                     | Description                             |
| --------------------- | ----------------------- | --------------------------------- |
| PING_TRANSACTION      | 1599098439 (0x5f504e47) | Internal instruction code used to test whether the IPC service is normal.|
| DUMP_TRANSACTION      | 1598311760 (0x5f444d50) | Internal instruction code used to obtain the internal status of the binder.|
| INTERFACE_TRANSACTION | 1598968902 (0x5f4e5446) | Internal instruction code used to obtain the remote interface descriptor. |
| MIN_TRANSACTION_ID    | 1 (0x00000001)          | Minimum valid instruction code.                 |
| MAX_TRANSACTION_ID    | 16777215 (0x00FFFFFF)   | Maximum valid instruction code.                 |




### sendRequest<sup>(deprecated)</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): boolean

> **NOTE**<br/>
> This API is deprecated since API version 8. You are advised to use [sendRequestAsync<sup>9+</sup>](#sendrequestasync9-1).

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


**Example**

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
      "bundleName": "com.ohos.server",
      "abilityName": "com.ohos.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  let ret: boolean = proxy.sendRequest(1, data, reply, option);
  if (ret) {
      console.log("sendRequest got result");
      let msg = reply.readString();
      console.log("RPCTest: reply msg: " + msg);
  } else {
      console.log("RPCTest: sendRequest failed");
  }
  console.log("RPCTest: sendRequest ends, reclaim parcel");
  data.reclaim();
  reply.reclaim();
  ```

### sendRequest<sup>8+(deprecated)</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;

> **NOTE**<br/>
> This API is deprecated since API version 9. You are advised to use [sendRequestAsync<sup>9+</sup>](#sendrequestasync9-1).

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;SendRequestResult&gt; | Promise used to return the **sendRequestResult** object.|

**Example**

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
      "bundleName": "com.ohos.server",
      "abilityName": "com.ohos.server.MainAbility",
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

### sendRequestAsync<sup>9+</sup>

sendRequestAsync(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequestAsync** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;SendRequestResult&gt; | Promise used to return the **sendRequestResult** object.|

**Example**

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
      "bundleName": "com.ohos.server",
      "abilityName": "com.ohos.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  proxy.sendRequestAsync(1, data, reply, option)
      .then(function(result) {
          if (result.errCode === 0) {
              console.log("sendRequestAsync got result");
              result.reply.readException();
              let msg = result.reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendRequestAsync failed, errCode: " + result.errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendRequestAsync got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendRequestAsync ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```

### sendRequest<sup>8+</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a callback will be invoked immediately and the reply message does not contain any content. If **options** is the synchronous mode, a callback will be invoked when the response to sendRequest is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|
  | callback | AsyncCallback&lt;SendRequestResult&gt; | Yes| Callback for receiving the sending result.|

**Example**

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
      "bundleName": "com.ohos.server",
      "abilityName": "com.ohos.server.MainAbility",
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

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | interface | string | Yes| Interface descriptor.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | IRemoteBroker | Returns **Null** by default, which indicates a proxy interface.|

**Example**

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
      "bundleName":"com.ohos.server",
      "abilityName":"com.ohos.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let broker = proxy.queryLocalInterface("testObject");
  console.log("RpcClient: queryLocalInterface is " + broker);
  ```


### addDeathRecippient

addDeathRecipient(recipient : DeathRecipient, flags : number): boolean

Adds a callback for receiving the death notifications of the remote object, including the death notifications of the remote proxy.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes| Callback to add.|
  | flags | number | Yes| Flag of the death notification. This parameter is reserved. It is set to **0**.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the callback is added successfully; returns **false** otherwise.|

**Example**

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
      "bundleName": "com.ohos.server",
      "abilityName": "com.ohos.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  let deathRecipient = new MyDeathRecipient();
  proxy.addDeathRecippient(deathRecipient, 0);
  ```


### removeDeathRecipient

removeDeathRecipient(recipient : DeathRecipient, flags : number): boolean

Removes the callback used to receive death notifications of the remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes| Callback to remove.|
  | flags | number | Yes| Flag of the death notification. This parameter is reserved. It is set to **0**.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the callback is removed successfully; returns **false** otherwise.|

**Example**

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
      "bundleName": "com.ohos.server",
      "abilityName": "com.ohos.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  let deathRecipient = new MyDeathRecipient();
  proxy.addDeathRecippient(deathRecipient, 0);
  proxy.removeDeathRecipient(deathRecipient, 0);
  ```


### getInterfaceDescriptor

getInterfaceDescriptor(): string

Obtains the interface descriptor of this proxy object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Interface descriptor obtained.|

**Example**

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
      "bundleName": "com.ohos.server",
      "abilityName": "com.ohos.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let descriptor = proxy.getInterfaceDescriptor();
  console.log("RpcClient: descriptor is " + descriptor);
  ```


### isObjectDead

isObjectDead(): boolean

Checks whether the **RemoteObject** is dead.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the **RemoteObject** is dead; returns **false** otherwise.|

**Example**

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
      "bundleName": "com.ohos.server",
      "abilityName": "com.ohos.server.MainAbility",
  };
  FA.connectAbility(want, connect);
  let isDead = proxy.isObjectDead();
  console.log("RpcClient: isObjectDead is " + isDead);
  ```


## MessageOption

Provides common message options (flag and wait time). The flag is used to construct the specified **MessageOption** object.

**System capability**: SystemCapability.Communication.IPC.Core

  | Parameter| Value| Description|
| -------- | -------- | -------- |
| TF_SYNC | 0 | Synchronous call.|
| TF_ASYNC | 1 | Asynchronous call.|
| TF_ACCEPT_FDS | 0x10 | Indication to [sendRequestAsync](#sendrequestasync9) for returning the file descriptor.|
| TF_WAIT_TIME | 8 | Time to wait, in seconds.|


### constructor

constructor(syncFlags?: number, waitTime = TF_WAIT_TIME)

A constructor used to create a **MessageOption** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | syncFlags | number | No| Call flag, which can be synchronous or asynchronous. The default value is **synchronous**.|
  | waitTime | number | No| Maximum wait time for an RPC call. The default value is **TF_WAIT_TIME**.|


### getFlags

getFlags(): number

Obtains the call flag, which can be synchronous or asynchronous.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Call mode obtained.|


### setFlags

setFlags(flags: number): void

Sets the call flag, which can be synchronous or asynchronous.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | flags | number | Yes| Call flag to set.|


### getWaitTime

getWaitTime(): number

Obtains the maximum wait time for this RPC call.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Maximum wait time obtained.|


### setWaitTime

setWaitTime(waitTime: number): void

Sets the maximum wait time for this RPC call.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | waitTime | number | Yes| Maximum wait time to set.|


## IPCSkeleton

Obtains IPC context information, including the UID and PID, local and remote device IDs, and whether the method is invoked on the same device.


### getContextObject

static getContextObject(): IRemoteObject

Obtains the system capability manager.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | [IRemoteObject](#iremoteobject) | System capability manager obtained.|

**Example**

  ```
  let samgr = rpc.IPCSkeleton.getContextObject();
  console.log("RpcServer: getContextObject result: " + samgr);
  ```


### getCallingPid

static getCallingPid(): number

Obtains the PID of the caller. This method is invoked by the **RemoteObject** object in the **onRemoteRequest** method. If this method is not invoked in the IPC context (**onRemoteRequest**), the PID of the process will be returned.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | PID of the caller.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | UID of the caller.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callerUid = rpc.IPCSkeleton.getCallingUid();
          console.log("RpcServer: getCallingUid result: " + callerUid);
          return true;
      }
  }
  ```

### getCallingTokenId<sup>8+</sup>

static getCallingTokenId(): number;

Obtains the caller's token ID, which is used to verify the caller identity.

**System capability**: SystemCapability.Communication.IPC.Core

* Return value

    | Type  | Description                 |
  | ------ | --------------------- |
  | number | Token ID of the caller obtained.|

* Example

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();
          console.log("RpcServer: getCallingTokenId result: " + callerTokenId);
          return true;
      }
  }
  ```


### getCallingDeviceID

static getCallingDeviceID(): string

Obtains the ID of the device hosting the caller's process.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Device ID obtained.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callerDeviceID = rpc.IPCSkeleton.getCallingDeviceID();
          console.log("RpcServer: callerDeviceID is: " + callerDeviceID);
          return true;
      }
  }
  ```


### getLocalDeviceID

static getLocalDeviceID(): string

Obtains the local device ID.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Local device ID obtained.|

**Example**

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

Checks whether the remote process is a process of the local device.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the local and remote processes are on the same device; returns **false** otherwise.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | object | [IRemoteObject](#iremoteobject) | Yes| **RemoteProxy** specified. |


**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | Returns **0** if the operation is successful; returns an error code if the input object is null or a **RemoteObject**, or if the operation fails.|

**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
  }
  let remoteObject = new TestRemoteObject("aaa");
  let ret = rpc.IPCSkeleton.flushCommands(remoteObject);
  console.log("RpcServer: flushCommands result: " + ret);
  ```


### resetCallingIdentity

static resetCallingIdentity(): string

Changes the UID and PID of the remote user to the UID and PID of the local user. This method is used in scenarios such as identity authentication.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | String containing the UID and PID of the remote user.|

**Example**

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

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | identity | string | Yes| String containing the remote user UID and PID, which are returned by **resetCallingIdentity**.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

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

A constructor used to create a **RemoteObject** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | descriptor | string | Yes| Interface descriptor.|


### sendRequest<sup>(deprecated)</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): boolean

> **NOTE**<br/>
> This API is deprecated since API version 8. You are advised to use [sendRequestAsync<sup>9+</sup>](#sendrequestasync9-2).

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  let ret: boolean = testRemoteObject.sendRequest(1, data, reply, option);
  if (ret) {
      console.log("sendRequest got result");
      let msg = reply.readString();
      console.log("RPCTest: reply msg: " + msg);
  } else {
      console.log("RPCTest: sendRequest failed");
  }
  console.log("RPCTest: sendRequest ends, reclaim parcel");
  data.reclaim();
  reply.reclaim();
  ```


### sendRequest<sup>8+(deprecated)</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;

> **NOTE**<br/>
> This API is deprecated since API version 9. You are advised to use [sendRequestAsync<sup>9+</sup>](#sendrequestasync9-2).

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;SendRequestResult&gt; | Promise used to return the **sendRequestResult** object.|


**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
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

### sendRequestAsync<sup>9+</sup>

sendRequestAsync(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequestAsync** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;SendRequestResult&gt; | Promise used to return the **sendRequestResult** object.|

**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  testRemoteObject.sendRequestAsync(1, data, reply, option)
      .then(function(result) {
          if (result.errCode === 0) {
              console.log("sendRequestAsync got result");
              result.reply.readException();
              let msg = result.reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendRequestAsync failed, errCode: " + result.errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendRequestAsync got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendRequestAsync ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```

### sendRequest<sup>8+</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a callback will be invoked immediately and the reply message does not contain any content. If **options** is the synchronous mode, a callback will be invoked when the response to sendRequest is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object holding the data to send.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that receives the response.|
  | options | [MessageOption](#messageoption) | Yes| Request sending mode, which can be synchronous (default) or asynchronous.|
  | AsyncCallback | AsyncCallback&lt;SendRequestResult&gt; | Yes| Callback for receiving the sending result.|


**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
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


### onRemoteRequest<sup>8+(deprecated)</sup>


onRemoteRequest(code : number, data : MessageParcel, reply: MessageParcel, options : MessageOption): boolean

> **NOTE**<br/>
> This API is deprecated since API version 9. You are advised to use [onRemoteRequestEx<sup>9+</sup>](#onremoterequestex9).

Provides a response to **sendRequestAsync()**. The server processes the request and returns a response in this function.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Service request code sent by the remote end.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that holds the parameters called by the client.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object carrying the result.|
  | option | [MessageOption](#messageoption) | Yes| Whether the operation is synchronous or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


**Example**

  ```ets
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
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
### onRemoteRequestEx<sup>9+</sup>

onRemoteRequestEx(code : number, data : MessageParcel, reply: MessageParcel, options : MessageOption): boolean | Promise <boolean>

> **NOTE**<br/>
>- You are advised to overload **onRemoteRequestEx** preferentially, which implements synchronous and asynchronous message processing.
>- If both **onRemoteRequest** and **onRemoteRequestEx** are overloaded, only **onRemoteRequestEx** takes effect.

Provides a response to **sendRequestAsync()**. The server processes the request synchronously or asynchronously and returns the result in this API.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | code | number | Yes| Service request code sent by the remote end.|
  | data | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object that holds the parameters called by the client.|
  | reply | [MessageParcel](#messageparcel) | Yes| **MessageParcel** object carrying the result.|
  | option | [MessageOption](#messageoption) | Yes| Whether the operation is synchronous or asynchronous.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns a Boolean value if the request is processed synchronously in **onRemoteRequestEx**. If the operation is successful, **true** is returned. Otherwise, **false** is returned.|
  | Promise <boolean> | Returns a promise object if the request is processed asynchronously in **onRemoteRequestEx**.|


**Example**: Overload **onRemoteRequestEx** to process a request synchronously.

  ```ets
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
      onRemoteRequestEx(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: sync onRemoteRequestEx is called");
              return true;
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
      }
  }
  ```
  **Example**: Overload **onRemoteRequestEx** to process a request asynchronously.

  ```ets
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
      async onRemoteRequestEx(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: async onRemoteRequestEx is called");
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
          await new Promise((resolve) => {
            setTimeout(resolve, 100);
          })
          return true;
      }
  }
  ```
**Example**: Overload **onRemoteRequestEx** and **onRemoteRequest** to process requests synchronously.

  ```ets
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
      onRemoteRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: sync onRemoteRequestEx is called");
              return true;
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
      }
      // Only onRemoteRequestEx is executed when onRemoteRequestEx and onRemoteRequest are called.
      onRemoteRequestEx(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: async onRemoteRequestEx is called");
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
          
          return true;
      }
  }
  ```
  **Example**: Overload **onRemoteRequestEx** and **onRemoteRequest** to process requests asynchronously.

  ```ets
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
      onRemoteRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: sync onRemoteRequestEx is called");
              return true;
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
      }
      // Only onRemoteRequestEx is executed when onRemoteRequestEx and onRemoteRequest are called.
      async onRemoteRequestEx(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: async onRemoteRequestEx is called");
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
          await new Promise((resolve) => {
            setTimeout(resolve, 100);
          })
          return true;
      }
  }
  ```
### getCallingUid

getCallingUid(): number

Obtains the UID of the remote process.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | UID of the remote process obtained.|


**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  console.log("RpcServer: getCallingUid: " + testRemoteObject.getCallingUid());
  ```


### getCallingPid

getCallingPid(): number

Obtains the PID of the remote process.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | PID of the remote process obtained.|


**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  console.log("RpcServer: getCallingPid: " + testRemoteObject.getCallingPid());
  ```


### queryLocalInterface

queryLocalInterface(descriptor: string): IRemoteBroker

Checks whether the remote object corresponding to the specified interface descriptor exists.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | descriptor | string | Yes| Interface descriptor.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | IRemoteBroker | Returns the remote object if a match is found; returns **Null** otherwise.|


**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  let broker = testRemoteObject.queryLocalInterface("testObject");
  ```


### getInterfaceDescriptor

getInterfaceDescriptor(): string

Obtains the interface descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | string | Interface descriptor obtained.|


**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  let descriptor = testRemoteObject.getInterfaceDescriptor();
  console.log("RpcServer: descriptor is: " + descriptor);
  ```


### attachLocalInterface

attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void

Binds an interface descriptor to an **IRemoteBroker** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | localInterface | IRemoteBroker | Yes| **IRemoteBroker** object.|
  | descriptor | string | Yes| Interface descriptor.|


**Example**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
          this.attachLocalInterface(this, descriptor);
      }
      addDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
          return true;
      }
      isObjectDead(): boolean {
          return false;
      }
      asObject(): rpc.IRemoteObject {
          return this;
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  ```


## Ashmem<sup>8+</sup>

Provides methods related to anonymous shared memory objects, including creating, closing, mapping, and unmapping an **Ashmem** object, reading data from and writing data to an **Ashmem** object, obtaining the **Ashmem** size, and setting **Ashmem** protection.

The table below describes the protection types of the mapped memory.

**System capability**: SystemCapability.Communication.IPC.Core

  | Name| Value| Description|
| -------- | -------- | -------- |
| PROT_EXEC | 4 | The mapped memory is executable.|
| PROT_NONE | 0 | The mapped memory is inaccessible.|
| PROT_READ | 1 | The mapped memory is readable.|
| PROT_WRITE | 2 | The mapped memory is writeable.|


### createAshmem<sup>8+</sup>

static createAshmem(name: string, size: number): Ashmem

Creates an **Ashmem** object with the specified name and size.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | name | string | Yes| Name of the **Ashmem** object to create.|
  | size | number | Yes| Size (in bytes) of the **Ashmem** object to create.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Ashmem | Returns the **Ashmem** object if it is created successfully; returns null otherwise.|


**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashemm by createAshmem : " + ashmem + " size is : " + size);
  ```


### createAshmemFromExisting<sup>8+</sup>

static createAshmemFromExisting(ashmem: Ashmem): Ashmem

Creates an **Ashmem** object by copying the file descriptor (FD) of an existing Ashmem object. The two **Ashmem** objects point to the same shared memory region.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ashmem | Ashmem | Yes| Existing **Ashmem** object.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Ashmem | **Ashmem** object created.|


**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let ashmem2 = rpc.Ashmem.createAshmemFromExisting(ashmem);
  let size = ashmem2.getAshmemSize();
  console.log("RpcTest: get ashemm by createAshmemFromExisting : " + ashmem2 + " size is : " + size);
  ```


### closeAshmem<sup>8+</sup>

closeAshmem(): void

Closes this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  ashmem.closeAshmem();
  ```


### unmapAshmem<sup>8+</sup>

unmapAshmem(): void

Deletes the mappings for the specified address range of this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  ashmem.unmapAshmem();
  ```


### getAshmemSize<sup>8+</sup>

getAshmemSize(): number

Obtains the memory size of this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number | **Ashmem** size obtained.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashmem is " + ashmem + " size is : " + size);
  ```


### mapAshmem<sup>8+</sup>

mapAshmem(mapType: number): boolean

Creates the shared file mapping on the virtual address space of this process. The size of the mapping region is specified by this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | mapType | number | Yes| Protection level of the memory region to which the shared file is mapped.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapReadAndWrite = ashmem.mapAshmem(ashmem.PROT_READ | ashmem.PROT_WRITE);
  console.log("RpcTest: map ashmem result is  : " + mapReadAndWrite);
  ```


### mapReadAndWriteAshmem<sup>8+</sup>

mapReadAndWriteAshmem(): boolean

Maps the shared file to the readable and writable virtual address space of the process.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadAndWriteAshmem();
  console.log("RpcTest: map ashmem result is  : " + mapResult);
  ```


### mapReadOnlyAshmem<sup>8+</sup>

mapReadOnlyAshmem(): boolean

Maps the shared file to the read-only virtual address space of the process.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadOnlyAshmem();
  console.log("RpcTest: Ashmem mapReadOnlyAshmem result is : " + mapResult);
  ```


### setProtection<sup>8+</sup>

setProtection(protectionType: number): boolean

Sets the protection level of the memory region to which the shared file is mapped.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | protectionType | number | Yes| Protection type to set.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let result = ashmem.setProtection(ashmem.PROT_READ);
  console.log("RpcTest: Ashmem setProtection result is : " + result);
  ```


### writeToAshmem<sup>8+</sup>

writeToAshmem(buf: number[], size: number, offset: number): boolean

Writes data to the shared file associated with this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | buf | number[] | Yes| Data to write.|
  | size | number | Yes| Size of the data to write.|
  | offset | number | Yes| Start position of the data to write in the memory region associated with this **Ashmem** object.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** is the data is written successfully; returns **false** otherwise.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadAndWriteAshmem();
  console.info("RpcTest map ashmem result is " + mapResult);
  var ByteArrayVar = [1, 2, 3, 4, 5];
  let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);
  console.log("RpcTest: write to Ashmem result is  : " + writeResult);
  ```


### readFromAshmem<sup>8+</sup>

readFromAshmem(size: number, offset: number): number[]

Reads data from the shared file associated with this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | size | number | Yes| Size of the data to read.|
  | offset | number | Yes| Start position of the data to read in the memory region associated with this **Ashmem** object.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | number[] | Data read.|


**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadAndWriteAshmem();
  console.info("RpcTest map ashmem result is " + mapResult);
  var ByteArrayVar = [1, 2, 3, 4, 5];
  let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);
  console.log("RpcTest: write to Ashmem result is  : " + writeResult);
  let readResult = ashmem.readFromAshmem(5, 0);
  console.log("RpcTest: read to Ashmem result is  : " + readResult);
  ```
