# @ohos.rpc

The **RPC** module implements communication between processes, including inter-process communication (IPC) on a single device and remote procedure call (RPC) between processes on difference devices. IPC is implemented based on the Binder driver, and RPC is based on the DSoftBus driver.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This module supports return of error codes since API version 9.


## Modules to Import

```
import rpc from '@ohos.rpc';
```


## ErrorCode<sup>9+</sup>

The APIs of this module return exceptions since API version 9. The following table lists the error codes.

**System capability**: SystemCapability.Communication.IPC.Core

  | Name                                 | Value     | Description                                         |
  | ------------------------------------- | ------- | --------------------------------------------- |
  | CHECK_PARAM_ERROR                     | 401     | Parameter check failed.                               |
  | OS_MMAP_ERROR                         | 1900001 | Failed to call mmap.                       |
  | OS_IOCTL_ERROR                        | 1900002 | Failed to call **ioctl** with the shared memory file descriptor.|
  | WRITE_TO_ASHMEM_ERROR                 | 1900003 | Failed to write data to the shared memory.                       |
  | READ_FROM_ASHMEM_ERROR                | 1900004 | Failed to read data from the shared memory.                       |
  | ONLY_PROXY_OBJECT_PERMITTED_ERROR     | 1900005 | This operation is allowed only on the proxy object.                    |
  | ONLY_REMOTE_OBJECT_PERMITTED_ERROR    | 1900006 | This operation is allowed only on the remote object.                   |
  | COMMUNICATION_ERROR                   | 1900007 | Failed to communicate with the remote object over IPC.               |
  | PROXY_OR_REMOTE_OBJECT_INVALID_ERROR  | 1900008 | Invalid proxy or remote object.                 |
  | WRITE_DATA_TO_MESSAGE_SEQUENCE_ERROR  | 1900009 | Failed to write data to MessageSequence.                |
  | READ_DATA_FROM_MESSAGE_SEQUENCE_ERROR | 1900010 | Failed to read data from MessageSequence.                |
  | PARCEL_MEMORY_ALLOC_ERROR             | 1900011 | Failed to allocate memory during serialization.                   |
  | CALL_JS_METHOD_ERROR                  | 1900012 | Failed to invoke the JS callback.                         |
  | OS_DUP_ERROR                          | 1900013 | Failed to call dup.                        |


## MessageSequence<sup>9+</sup>

  Provides APIs for reading and writing data in specific format. During RPC, the sender can use the **write()** method provided by **MessageSequence** to write data in specific format to a **MessageSequence** object. The receiver can use the **read()** method provided by **MessageSequence** to read data in specific format from a **MessageSequence** object. The data formats include basic data types and arrays, IPC objects, interface tokens, and custom sequenceable objects.

### create

  create(): MessageSequence

  Creates a **MessageSequence** object. This API is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type           | Description                           |
  | --------------- | ------------------------------- |
  | MessageSequence | **MessageSequence** object created.|

**Example**

  ```
  let data = rpc.MessageSequence.create();
  console.log("RpcClient: data is " + data);
  ```

### reclaim

reclaim(): void

Reclaims the **MessageSequence** object that is no longer used.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```
  let reply = rpc.MessageSequence.create();
  reply.reclaim();
  ```

### writeRemoteObject

writeRemoteObject(object: [IRemoteObject](#iremoteobject)): void

Serializes a remote object and writes it to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type                           | Mandatory| Description                                     |
  | ------ | ------------------------------- | ---- | ----------------------------------------- |
  | object | [IRemoteObject](#iremoteobject) | Yes  | Remote object to serialize and write to the **MessageSequence** object.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------- |
  | 1900008 | proxy or remote object is invalid |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let data = rpc.MessageSequence.create();
  let testRemoteObject = new TestRemoteObject("testObject");
  try {
      data.writeRemoteObject(testRemoteObject);
  } catch(error) {
      console.info("Rpc write remote object fail, errorCode " + error.code);
      console.info("Rpc write remote object fail, errorMessage " + error.message);
  }
  ```

### readRemoteObject

readRemoteObject(): IRemoteObject

Reads the remote object from **MessageSequence**. You can use this API to deserialize the **MessageSequence** object to generate an **IRemoteObject**. The remote object is read in the order in which it is written to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type                           | Description              |
  | ------------------------------- | ------------------ |
  | [IRemoteObject](#iremoteobject) | Remote object obtained.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let data = rpc.MessageSequence.create();
  let testRemoteObject = new TestRemoteObject("testObject");
  try {
      data.writeRemoteObject(testRemoteObject);
      let proxy = data.readRemoteObject();
  } catch(error) {
      console.info("Rpc write remote object fail, errorCode " + error.code);
      console.info("Rpc write remote object fail, errorMessage " + error.message);
  }
  ```

### writeInterfaceToken

writeInterfaceToken(token: string): void

Writes an interface token to this **MessageSequence** object. The remote object can use this interface token to verify the communication.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description              |
  | ------ | ------ | ---- | ------------------ |
  | token  | string | Yes  | Interface token to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeInterfaceToken("aaa");
  } catch(error) {
      console.info("rpc write interface fail, errorCode " + error.code);
      console.info("rpc write interface fail, errorMessage " + error.message);
  }
  ```

### readInterfaceToken

readInterfaceToken(): string

Reads the interface token from this **MessageSequence** object. The interface token is read in the sequence in which it is written to the **MessageSequence** object. The local object can use it to verify the communication.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description                    |
  | ------ | ------------------------ |
  | string | Interface token obtained.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ----- |
  | 1900010 | read data from message sequence failed |


**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          try {
              let interfaceToken = data.readInterfaceToken();
              console.log("RpcServer: interfaceToken is " + interfaceToken);
          } catch(error) {
              console.info("RpcServer: read interfaceToken failed, errorCode " + error.code);
              console.info("RpcServer: read interfaceToken failed, errorMessage " + error.message);
          }
          return true;
      }
  }
  ```

### getSize

getSize(): number

Obtains the data size of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description                                           |
  | ------ | ----------------------------------------------- |
  | number | Size of the **MessageSequence** object obtained, in bytes.|

**Example**

  ```
  let data = rpc.MessageSequence.create();
  let size = data.getSize();
  console.log("RpcClient: size is " + size);
  ```

### getCapacity

getCapacity(): number

Obtains the capacity of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description|
  | ------ | ----- |
  | number | **MessageSequence** capacity obtained, in bytes.|

**Example**

  ```
  let data = rpc.MessageSequence.create();
  let result = data.getCapacity();
  console.log("RpcClient: capacity is " + result);
  ```

### setSize

setSize(size: number): void

Sets the size of data contained in this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description|
  | ------ | ------ | ---- | ------ |
  | size | number | Yes| Data size to set, in bytes.|

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.setSize(16);
      console.log("RpcClient: setSize is " + data.getSize());
  } catch(error) {
      console.info("rpc set size of MessageSequence fail, errorCode " + error.code);
      console.info("rpc set size of MessageSequence fail, errorMessage " + error.message);
  }
  ```

### setCapacity

setCapacity(size: number): void

Sets the storage capacity of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                                         |
  | ------ | ------ | ---- | --------------------------------------------- |
  | size   | number | Yes  | Storage capacity of the **MessageSequence** object to set, in bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------ |
  | 1900011 | parcel memory alloc failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.setCapacity(100);
      console.log("RpcClient: setCapacity is " + data.getCapacity());
  } catch(error) {
      console.info("rpc memory alloc fail, errorCode " + error.code);
      console.info("rpc memory alloc fail, errorMessage " + error.message);
  }
  ```

### getWritableBytes

getWritableBytes(): number

Obtains the writable capacity of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | ------ | ------ |
  | number | **MessageSequence** writable capacity obtained, in bytes.|

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

Obtains the readable capacity of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | ------ | ------- |
  | number | **MessageSequence** readable capacity obtained, in bytes.|

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

Obtains the read position of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | ------ | ------ |
  | number | Read position obtained.|

**Example**

  ```
  let data = rpc.MessageSequence.create();
  let readPos = data.getReadPosition();
  console.log("RpcClient: readPos is " + readPos);
  ```

### getWritePosition

getWritePosition(): number

Obtains the write position of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type| Description|
  | ------ | ----- |
  | number | Write position obtained.|

**Example**

  ```
  let data = rpc.MessageSequence.create();
  data.writeInt(10);
  let bwPos = data.getWritePosition();
  console.log("RpcClient: bwPos is " + bwPos);
  ```

### rewindRead

rewindRead(pos: number): void

Moves the read pointer to the specified position.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ------- |
  | pos    | number | Yes  | Position from which data is to read.|

**Example**

  ```
  let data = rpc.MessageSequence.create();
  data.writeInt(12);
  data.writeString("sequence");
  let number = data.readInt();
  console.log("RpcClient: number is " + number);
  try {
      data.rewindRead(0);
  } catch(error) {
      console.info("rpc rewind read data fail, errorCode " + error.code);
      console.info("rpc rewind read data fail, errorMessage " + error.message);
  }
  let number2 = data.readInt();
  console.log("RpcClient: rewindRead is " + number2);
  ```

### rewindWrite

rewindWrite(pos: number): void

Moves the write pointer to the specified position.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ----- |
  | pos    | number | Yes  | Position from which data is to write.|

**Example**

  ```
  let data = rpc.MessageSequence.create();
  data.writeInt(4);
  try {
      data.rewindWrite(0);
  } catch(error) {
      console.info("rpc rewind read data fail, errorCode " + error.code);
      console.info("rpc rewind read data fail, errorMessage " + error.message);
  }
  data.writeInt(5);
  let number = data.readInt();
  console.log("RpcClient: rewindWrite is: " + number);
  ```

### writeByte

writeByte(val: number): void

Writes a byte value to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description|
  | ----- | ------ | ---- | ----- |
  | val | number | Yes| Byte value to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeByte(2);
  } catch(error) {
    console.info("rpc write byte fail, errorCode " + error.code);
    console.info("rpc write byte fail, errorMessage" + error.message);
  }
  ```

### readByte

readByte(): number

Reads the byte value from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description|
  | ------ | ----- |
  | number | Byte value read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | --------  |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeByte(2);
  } catch(error) {
    console.info("rpc write byte fail, errorCode " + error.code);
    console.info("rpc write byte fail, errorMessage" + error.message);
  }
  try {
      let ret = data.readByte();
      console.log("RpcClient: readByte is: " + ret);
  } catch(error) {
    console.info("rpc write byte fail, errorCode " + error.code);
    console.info("rpc write byte fail, errorMessage" + error.message);
  }
  ```

### writeShort

writeShort(val: number): void

Writes a short integer to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description|
  | ------ | ------ | --- | --- |
  | val | number | Yes| Short integer to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------ |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeShort(8);
  } catch(error) {
      console.info("rpc write short fail, errorCode " + error.code);
      console.info("rpc write short fail, errorMessage" + error.message);
  }
  ```

### readShort

readShort(): number

Reads the short integer from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description          |
  | ------ | -------------- |
  | number | Short integer read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeShort(8);
  } catch(error) {
      console.info("rpc write short fail, errorCode " + error.code);
      console.info("rpc write short fail, errorMessage" + error.message);
  }
  try {
      let ret = data.readShort(8);
  } catch(error) {
      console.info("rpc read short fail, errorCode " + error.code);
      console.info("rpc read short fail, errorMessage" + error.message);
  }
  console.log("RpcClient: readByte is: " + ret);
  ```

### writeInt

writeInt(val: number): void

Writes an integer to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description            |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | Yes  | Integer to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeInt(10);
  } catch(error) {
      console.info("rpc write int fail, errorCode " + error.code);
      console.info("rpc write int fail, errorMessage" + error.message);
  }
  ```

### readInt

readInt(): number

Reads the integer from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description        |
  | ------ | ------------ |
  | number | Integer read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeInt(10);
  } catch(error) {
      console.info("rpc write int fail, errorCode " + error.code);
      console.info("rpc write int fail, errorMessage" + error.message);
  }
  try {
      let ret = data.readInt();
      console.log("RpcClient: readInt is " + ret);
  } catch(error) {
      console.info("rpc read int fail, errorCode " + error.code);
      console.info("rpc read int fail, errorMessage" + error.message);
  }
  ```

### writeLong

writeLong(val: number): void

Writes a long integer to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description            |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | Yes  | Long integer to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeLong(10000);
  } catch(error) {
      console.info("rpc write long fail, errorCode " + error.code);
      console.info("rpc write long fail, errorMessage" + error.message);
  }
  ```

### readLong

readLong(): number

Reads the long integer from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description          |
  | ------ | -------------- |
  | number | Long integer read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeLong(10000);
  } catch(error) {
      console.info("rpc write long fail, errorCode " + error.code);
      console.info("rpc write long fail, errorMessage" + error.message);
  }
  try {
      let ret = data.readLong();
      console.log("RpcClient: readLong is " + ret);
  } catch(error) {
      console.info("rpc read long fail, errorCode " + error.code);
      console.info("rpc read long fail, errorMessage" + error.message);
  }
  ```

### writeFloat

writeFloat(val: number): void

Writes a floating-point number to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | ----- | ---- | ---- | ----- |
  | val | number | Yes| Floating-point number to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeFloat(1.2);
  } catch(error) {
      console.info("rpc write float fail, errorCode " + error.code);
      console.info("rpc write float fail, errorMessage" + error.message);
  }
  ```

### readFloat

readFloat(): number

Reads the floating-pointer number from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description        |
  | ------ | ------------ |
  | number | Floating-point number read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeFloat(1.2);
  } catch(error) {
      console.info("rpc write float fail, errorCode " + error.code);
      console.info("rpc write float fail, errorMessage" + error.message);
  }
  try {
      let ret = data.readFloat();
      console.log("RpcClient: readFloat is " + ret);
  } catch(error) {
      console.info("rpc read float fail, errorCode " + error.code);
      console.info("rpc read float fail, errorMessage" + error.message);
  }
  ```

### writeDouble

writeDouble(val: number): void

Writes a double-precision floating-point number to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ------ |
  | val  number | Yes| Double-precision floating-point number to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeDouble(10.2);
  } catch(error) {
      console.info("rpc read float fail, errorCode " + error.code);
      console.info("rpc read float fail, errorMessage" + error.message);
  }
  ```

### readDouble

readDouble(): number

Reads the double-precision floating-point number from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description              |
  | ------ | ------------------ |
  | number | Double-precision floating-point number read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeDouble(10.2);
  } catch(error) {
      console.info("rpc write double fail, errorCode " + error.code);
      console.info("rpc write double fail, errorMessage" + error.message);
  }
  try {
      let ret = data.readDouble();
      console.log("RpcClient: readDouble is " + ret);
  } catch(error) {
      console.info("rpc read double fail, errorCode " + error.code);
      console.info("rpc read double fail, errorMessage" + error.message);
  }
  ```

### writeBoolean

writeBoolean(val: boolean): void

Writes a Boolean value to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type   | Mandatory| Description            |
  | ------ | ------- | ---- | ---------------- |
  | val    | boolean | Yes  | Boolean value to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeBoolean(false);
  } catch(error) {
      console.info("rpc write boolean fail, errorCode " + error.code);
      console.info("rpc write boolean fail, errorMessage" + error.message);
  }
  ```

### readBoolean

readBoolean(): boolean

Reads the Boolean value from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type   | Description                |
  | ------- | -------------------- |
  | boolean | Boolean value read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeBoolean(false);
  } catch(error) {
      console.info("rpc write boolean fail, errorCode " + error.code);
      console.info("rpc write boolean fail, errorMessage" + error.message);
  }
  try {
      let ret = data.readBoolean();
      console.log("RpcClient: readBoolean is " + ret);
  } catch(error) {
      console.info("rpc read boolean fail, errorCode " + error.code);
      console.info("rpc read boolean fail, errorMessage" + error.message);
  }
  ```

### writeChar

writeChar(val: number): void

Writes a character to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                |
  | ------ | ------ | ---- | -------------------- |
  | val    | number | Yes  | Single character to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeChar(97);
  } catch(error) {
      console.info("rpc write char fail, errorCode " + error.code);
      console.info("rpc write char fail, errorMessage" + error.message);
  }
  ```

### readChar

readChar(): number

Reads the character from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description|
  | ------ | ---- |
  | number | Character read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------ | --------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeChar(97);
  } catch(error) {
      console.info("rpc write char fail, errorCode " + error.code);
      console.info("rpc write char fail, errorMessage" + error.message);
  }
  try {
      let ret = data.readChar();
      console.log("RpcClient: readChar is " + ret);
  } catch(error) {
      console.info("rpc read char fail, errorCode " + error.code);
      console.info("rpc read char fail, errorMessage" + error.message);
  }
  ```

### writeString

writeString(val: string): void

Writes a string to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                                     |
  | ------ | ------ | ---- | ----------------------------------------- |
  | val    | string | Yes  | String to write. The length of the string must be less than 40960 bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeString('abc');
  } catch(error) {
      console.info("rpc write string fail, errorCode " + error.code);
      console.info("rpc write string fail, errorMessage" + error.message);
  }
  ```

### readString

readString(): string

Reads the string from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description          |
  | ------ | -------------- |
  | string | String read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeString('abc');
  } catch(error) {
      console.info("rpc write string fail, errorCode " + error.code);
      console.info("rpc write string fail, errorMessage" + error.message);
  }
  try {
      let ret = data.readString();
      console.log("RpcClient: readString is " + ret);
  } catch(error) {
      console.info("rpc read string fail, errorCode " + error.code);
      console.info("rpc read string fail, errorMessage" + error.message);
  }
  ```

### writeParcelable

writeParcelable(val: Parcelable): void

Writes a **Parcelable** object to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | --------- | ---- | ------ |
  | val    | Parcelable | Yes  | **Parcelable** object to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  class MySequenceable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
      }
      marshalling(messageSequence) {
          messageSequence.writeInt(this.num);
          messageSequence.writeString(this.str);
          return true;
      }
      unmarshalling(messageSequence) {
          this.num = messageSequence.readInt();
          this.str = messageSequence.readString();
          return true;
      }
  }
  let parcelable = new MySequenceable(1, "aaa");
  let data = rpc.MessageSequence.create();
  try {
      data.writeParcelable(parcelable);
  } catch(error) {
      console.info("rpc write parcelable fail, errorCode " + error.code);
      console.info("rpc write parcelable fail, errorMessage" + error.message);
  }
  ```

### readParcelable

readParcelable(dataIn: Parcelable): void

Reads a **Parcelable** object from this **MessageSequence** object to the specified object (**dataIn**).

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type                     | Mandatory| Description                                     |
  | ------ | ------------------------- | ---- | ----------------------------------------- |
  | dataIn | Parcelable | Yes  | **Parcelable** object to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------- |
  | 1900010 | read data from message sequence failed |
  | 1900012 | call js callback function failed |

**Example**

  ```
  class MySequenceable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
      }
      marshalling(messageSequence) {
          messageSequence.writeInt(this.num);
          messageSequence.writeString(this.str);
          return true;
      }
      unmarshalling(messageSequence) {
          this.num = messageSequence.readInt();
          this.str = messageSequence.readString();
          return true;
      }
  }
  let parcelable = new MySequenceable(1, "aaa");
  let data = rpc.MessageSequence.create();
  data.writeParcelable(parcelable);
  let ret = new MySequenceable(0, "");
  try {
      data.readParcelable(ret);
  }catch(error) {
      console.info("rpc read parcelable fail, errorCode " + error.code);
      console.info("rpc read parcelable fail, errorMessage" + error.message);
  }
  ```

### writeByteArray

writeByteArray(byteArray: number[]): void

Writes a byte array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type    | Mandatory| Description              |
  | --------- | -------- | ---- | ------------------ |
  | byteArray | number[] | Yes  | Byte array to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  try {
      data.writeByteArray(ByteArrayVar);
  } catch(error) {
      console.info("rpc write byteArray fail, errorCode " + error.code);
      console.info("rpc write byteArray fail, errorMessage" + error.message);
  }
  ```

### readByteArray

readByteArray(dataIn: number[]): void

Reads a byte array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description              |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | Yes  | Byte array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  try {
      data.writeByteArray(ByteArrayVar);
  } catch(error) {
      console.info("rpc write byteArray fail, errorCode " + error.code);
      console.info("rpc write byteArray fail, errorMessage" + error.message);
  }
  try {
      let array = new Array(5);
      data.readByteArray(array);
  } catch(error) {
      console.info("rpc write byteArray fail, errorCode " + error.code);
      console.info("rpc write byteArray fail, errorMessage" + error.message);
  }
  ```

### readByteArray

readByteArray(): number[]

Reads the byte array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type    | Description          |
  | -------- | -------------- |
  | number[] | Byte array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  let byteArrayVar = [1, 2, 3, 4, 5];
  try {
      data.writeByteArray(byteArrayVar);
  } catch(error) {
      console.info("rpc write byteArray fail, errorCode " + error.code);
      console.info("rpc write byteArray fail, errorMessage" + error.message);
  }
  try {
      let array = data.readByteArray();
      console.log("RpcClient: readByteArray is " + array);
  } catch(error) {
      console.info("rpc read byteArray fail, errorCode " + error.code);
      console.info("rpc read byteArray fail, errorMessage" + error.message);
  }
  ```

### writeShortArray

writeShortArray(shortArray: number[]): void

Writes a short array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name    | Type    | Mandatory| Description                |
  | ---------- | -------- | ---- | -------------------- |
  | shortArray | number[] | Yes  | Short array to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ----- | ----- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeShortArray([11, 12, 13]);
  } catch(error) {
      console.info("rpc read byteArray fail, errorCode " + error.code);
      console.info("rpc read byteArray fail, errorMessage" + error.message);
  }
  ```

### readShortArray

readShortArray(dataIn: number[]): void

Reads a short array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | Yes  | Short array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------ | ------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeShortArray([11, 12, 13]);
  } catch(error) {
      console.info("rpc write shortArray fail, errorCode " + error.code);
      console.info("rpc write shortArray fail, errorMessage" + error.message);
  }
  try {
      let array = new Array(3);
      data.readShortArray(array);
  } catch(error) {
      console.info("rpc read shortArray fail, errorCode " + error.code);
      console.info("rpc read shortArray fail, errorMessage" + error.message);
  }
  ```

### readShortArray

readShortArray(): number[]

Reads the short array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type    | Description            |
  | -------- | ---------------- |
  | number[] | Short array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeShortArray([11, 12, 13]);
  } catch(error) {
      console.info("rpc write shortArray fail, errorCode " + error.code);
      console.info("rpc write shortArray fail, errorMessage" + error.message);
  }
  try {
      let array = data.readShortArray();
      console.log("RpcClient: readShortArray is " + array);
  } catch(error) {
      console.info("rpc read shortArray fail, errorCode " + error.code);
      console.info("rpc read shortArray fail, errorMessage" + error.message);
  }
  ```

### writeIntArray

writeIntArray(intArray: number[]): void

Writes an integer array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name  | Type    | Mandatory| Description              |
  | -------- | -------- | ---- | ------------------ |
  | intArray | number[] | Yes  | Integer array to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ----- | --------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeIntArray([100, 111, 112]);
  } catch(error) {
      console.info("rpc write intArray fail, errorCode " + error.code);
      console.info("rpc write intArray fail, errorMessage" + error.message);
  }
  ```

### readIntArray

readIntArray(dataIn: number[]): void

Reads an integer array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description              |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | Yes  | Integer array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeIntArray([100, 111, 112]);
  } catch(error) {
      console.info("rpc write intArray fail, errorCode " + error.code);
      console.info("rpc write intArray fail, errorMessage" + error.message);
  }
  let array = new Array(3);
  try {
      data.readIntArray(array);
  } catch(error) {
      console.info("rpc read intArray fail, errorCode " + error.code);
      console.info("rpc read intArray fail, errorMessage" + error.message);
  }
  ```

### readIntArray

readIntArray(): number[]

Reads the integer array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type    | Description          |
  | -------- | -------------- |
  | number[] | Integer array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ----- | ------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeIntArray([100, 111, 112]);
  } catch(error) {
      console.info("rpc write intArray fail, errorCode " + error.code);
      console.info("rpc write intArray fail, errorMessage" + error.message);
  }
  try {
    let array = data.readIntArray();
    console.log("RpcClient: readIntArray is " + array);
  } catch(error) {
      console.info("rpc read intArray fail, errorCode " + error.code);
      console.info("rpc read intArray fail, errorMessage" + error.message);
  }
  ```

### writeLongArray

writeLongArray(longArray: number[]): void

Writes a long array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type    | Mandatory| Description                |
  | --------- | -------- | ---- | -------------------- |
  | longArray | number[] | Yes  | Long array to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------  | ----- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeLongArray([1111, 1112, 1113]);
  }catch(error){
      console.info("rpc write longArray fail, errorCode " + error.code);
      console.info("rpc write longArray fail, errorMessage" + error.message);
  }
  ```

### readLongArray

readLongArray(dataIn: number[]): void

Reads a long array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | Yes  | Long array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------ |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeLongArray([1111, 1112, 1113]);
  } catch(error) {
      console.info("rpc write longArray fail, errorCode " + error.code);
      console.info("rpc write longArray fail, errorMessage" + error.message);
  }
  let array = new Array(3);
  try {
      data.readLongArray(array);
  } catch(error) {
      console.info("rpc read longArray fail, errorCode " + error.code);
      console.info("rpc read longArray fail, errorMessage" + error.message);
  }
  ```

### readLongArray

readLongArray(): number[]

Reads the long array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type    | Description            |
  | -------- | ---------------- |
  | number[] | Long array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeLongArray([1111, 1112, 1113]);
  } catch(error) {
      console.info("rpc write longArray fail, errorCode " + error.code);
      console.info("rpc write longArray fail, errorMessage" + error.message);
  }
  try {
      let array = data.readLongArray();
      console.log("RpcClient: readLongArray is " + array);
  } catch(error) {
      console.info("rpc read longArray fail, errorCode " + error.code);
      console.info("rpc read longArray fail, errorMessage" + error.message);
  }
  ```

### writeFloatArray

writeFloatArray(floatArray: number[]): void

Writes a floating-point array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name    | Type    | Mandatory| Description                                                                                                                   |
  | ---------- | -------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
  | floatArray | number[] | Yes  | Floating-point array to write. The system processes Float data as that of the Double type. Therefore, the total number of bytes occupied by a FloatArray must be calculated as the Double type.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeFloatArray([1.2, 1.3, 1.4]);
  } catch(error) {
      console.info("rpc write floatArray fail, errorCode " + error.code);
      console.info("rpc write floatArray fail, errorMessage" + error.message);
  }
  ```

### readFloatArray

readFloatArray(dataIn: number[]): void

Reads a floating-point array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                                                                                                                   |
  | ------ | -------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
  | dataIn | number[] | Yes  | Floating-point array to read. The system processes Float data as that of the Double type. Therefore, the total number of bytes occupied by a FloatArray must be calculated as the Double type.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeFloatArray([1.2, 1.3, 1.4]);
  }catch(error){
      console.info("rpc write floatArray fail, errorCode " + error.code);
      console.info("rpc write floatArray fail, errorMessage" + error.message);
  }
  let array = new Array(3);
  try {
      data.readFloatArray(array);
  } catch(error) {
      console.info("rpc read floatArray fail, errorCode " + error.code);
      console.info("rpc read floatArray fail, errorMessage" + error.message);
  }
  ```

### readFloatArray

readFloatArray(): number[]

Reads the floating-point array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type    | Description          |
  | -------- | -------------- |
  | number[] | Floating-point array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeFloatArray([1.2, 1.3, 1.4]);
  } catch(error) {
      console.info("rpc write floatArray fail, errorCode " + error.code);
      console.info("rpc write floatArray fail, errorMessage" + error.message);
  }
  try {
      let array = data.readFloatArray();
      console.log("RpcClient: readFloatArray is " + array);
  } catch(error) {
      console.info("rpc read floatArray fail, errorCode " + error.code);
      console.info("rpc read floatArray fail, errorMessage" + error.message);
  }
  ```

### writeDoubleArray

writeDoubleArray(doubleArray: number[]): void

Writes a double-precision floating-point array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name     | Type    | Mandatory| Description                    |
  | ----------- | -------- | ---- | ------------------------ |
  | doubleArray | number[] | Yes  | Double-precision floating-point array to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeDoubleArray([11.1, 12.2, 13.3]);
  } catch(error) {
      console.info("rpc write doubleArray fail, errorCode " + error.code);
      console.info("rpc write doubleArray fail, errorMessage" + error.message);
  }
  ```

### readDoubleArray

readDoubleArray(dataIn: number[]): void

Reads a double-precision floating-point array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                    |
  | ------ | -------- | ---- | ------------------------ |
  | dataIn | number[] | Yes  | Double-precision floating-point array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeDoubleArray([11.1, 12.2, 13.3]);
  } catch(error) {
      console.info("rpc write doubleArray fail, errorCode " + error.code);
      console.info("rpc write doubleArray fail, errorMessage" + error.message);
  }
  let array = new Array(3);
  try {
      data.readDoubleArray(array);
  } catch(error) {
      console.info("rpc read doubleArray fail, errorCode " + error.code);
      console.info("rpc read doubleArray fail, errorMessage" + error.message);
  }
  ```

### readDoubleArray

readDoubleArray(): number[]

Reads the double-precision floating-point array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type    | Description                |
  | -------- | -------------------- |
  | number[] | Double-precision floating-point array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeDoubleArray([11.1, 12.2, 13.3]);
  } catch(error) {
      console.info("rpc write doubleArray fail, errorCode " + error.code);
      console.info("rpc write doubleArray fail, errorMessage" + error.message);
  }
  try {
      let array = data.readDoubleArray();
      console.log("RpcClient: readDoubleArray is " + array);
  } catch(error) {
      console.info("rpc read doubleArray fail, errorCode " + error.code);
      console.info("rpc read doubleArray fail, errorMessage" + error.message);
  }
  ```

### writeBooleanArray

writeBooleanArray(booleanArray: boolean[]): void

Writes a Boolean array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name      | Type     | Mandatory| Description              |
  | ------------ | --------- | ---- | ------------------ |
  | booleanArray | boolean[] | Yes  | Boolean array to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeBooleanArray([false, true, false]);
  } catch(error) {
      console.info("rpc write booleanArray fail, errorCode " + error.code);
      console.info("rpc write booleanArray fail, errorMessage" + error.message);
  }
  ```

### readBooleanArray

readBooleanArray(dataIn: boolean[]): void

Reads a Boolean array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type     | Mandatory| Description              |
  | ------ | --------- | ---- | ------------------ |
  | dataIn | boolean[] | Yes  | Boolean array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeBooleanArray([false, true, false]);
  } catch(error) {
      console.info("rpc write booleanArray fail, errorCode " + error.code);
      console.info("rpc write booleanArray fail, errorMessage" + error.message);
  }
  let array = new Array(3);
  try {
      data.readBooleanArray(array);
  } catch(error) {
      console.info("rpc read booleanArray fail, errorCode " + error.code);
      console.info("rpc read booleanArray fail, errorMessage" + error.message);
  }
  ```

### readBooleanArray

readBooleanArray(): boolean[]

Reads the Boolean array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type     | Description          |
  | --------- | -------------- |
  | boolean[] | Boolean array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeBooleanArray([false, true, false]);
  } catch(error) {
      console.info("rpc write booleanArray fail, errorCode " + error.code);
      console.info("rpc write booleanArray fail, errorMessage" + error.message);
  }
  try {
      let array = data.readBooleanArray();
      console.log("RpcClient: readBooleanArray is " + array);
  } catch(error) {
      console.info("rpc read booleanArray fail, errorCode " + error.code);
      console.info("rpc read booleanArray fail, errorMessage" + error.message);
  }
  ```

### writeCharArray

writeCharArray(charArray: number[]): void

Writes a character array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type    | Mandatory| Description                  |
  | --------- | -------- | ---- | ---------------------- |
  | charArray | number[] | Yes  | Character array to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------ |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeCharArray([97, 98, 88]);
  } catch(error) {
      console.info("rpc write charArray fail, errorCode " + error.code);
      console.info("rpc write charArray fail, errorMessage" + error.message);
  }
  ```

### readCharArray

readCharArray(dataIn: number[]): void

Reads a character array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                  |
  | ------ | -------- | ---- | ---------------------- |
  | dataIn | number[] | Yes  | Character array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeCharArray([97, 98, 88]);
  } catch(error) {
      console.info("rpc write charArray fail, errorCode " + error.code);
      console.info("rpc write charArray fail, errorMessage" + error.message);
  }
  let array = new Array(3);
  try {
      data.readCharArray(array);
  } catch(error) {
      console.info("rpc read charArray fail, errorCode " + error.code);
      console.info("rpc read charArray fail, errorMessage" + error.message);
  }
  ```

### readCharArray

readCharArray(): number[]

Reads the character array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type    | Description              |
  | -------- | ------------------ |
  | number[] | Character array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeCharArray([97, 98, 88]);
  } catch(error) {
      console.info("rpc write charArray fail, errorCode " + error.code);
      console.info("rpc write charArray fail, errorMessage" + error.message);
  }
  let array = new Array(3);
  try {
      let array = data.readCharArray();
      console.log("RpcClient: readCharArray is " + array);
  } catch(error) {
      console.info("rpc read charArray fail, errorCode " + error.code);
      console.info("rpc read charArray fail, errorMessage" + error.message);
  }
  ```

### writeStringArray

writeStringArray(stringArray: string[]): void

Writes a string array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name     | Type    | Mandatory| Description                                                   |
  | ----------- | -------- | ---- | ------------------------------------------------------- |
  | stringArray | string[] | Yes  | String array to write. The length of a single element in the array must be less than 40960 bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeStringArray(["abc", "def"]);
  } catch(error) {
      console.info("rpc write stringArray fail, errorCode " + error.code);
      console.info("rpc write stringArray fail, errorMessage" + error.message);
  }
  ```

### readStringArray

readStringArray(dataIn: string[]): void

Reads a string array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | string[] | Yes  | String array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeStringArray(["abc", "def"]);
  } catch(error) {
      console.info("rpc write stringArray fail, errorCode " + error.code);
      console.info("rpc write stringArray fail, errorMessage" + error.message);
  }
  let array = new Array(2);
  try {
      data.readStringArray(array);
  } catch(error) {
      console.info("rpc read stringArray fail, errorCode " + error.code);
      console.info("rpc read stringArray fail, errorMessage" + error.message);
  }
  ```

### readStringArray

readStringArray(): string[]

Reads the string array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type    | Description            |
  | -------- | ---------------- |
  | string[] | String array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let data = rpc.MessageSequence.create();
  try {
      data.writeStringArray(["abc", "def"]);
  } catch(error) {
      console.info("rpc write stringArray fail, errorCode " + error.code);
      console.info("rpc write stringArray fail, errorMessage" + error.message);
  }
  try {
      let array = data.readStringArray();
      console.log("RpcClient: readStringArray is " + array);
  } catch(error) {
      console.info("rpc read stringArray fail, errorCode " + error.code);
      console.info("rpc read stringArray fail, errorMessage" + error.message);
  }
  ```

### writeNoException

writeNoException(): void

Writes information to this **MessageSequence** object indicating that no exception occurred.

**System capability**: SystemCapability.Communication.IPC.Core

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }

      onRemoteRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: onRemoteRequest called");
              try {
                  reply.writeNoException();
              } catch(error) {
                  console.info("rpc write no exception fail, errorCode " + error.code);
                  console.info("rpc write no exception fail, errorMessage" + error.message);
              }
              return true;
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
      }
  }
  ```

### readException

readException(): void

Reads the exception information from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

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
  let data = rpc.MessageSequence.create();
  let reply = rpc.MessageSequence.create();
  data.writeInt(1);
  data.writeString("hello");
  proxy.sendMessageRequest(1, data, reply, option)
      .then(function(errCode) {
          if (errCode === 0) {
              console.log("sendMessageRequest got result");
              try {
                  reply.readException();
              } catch(error) {
                  console.info("rpc read exception fail, errorCode " + error.code);
                  console.info("rpc read no exception fail, errorMessage" + error.message);
              }
              let msg = reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendMessageRequest failed, errCode: " + errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendMessageRequest got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendMessageRequest ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```

### writeParcelableArray

writeParcelableArray(parcelableArray: Parcelable[]): void

Writes a **Parcelable** array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name         | Type        | Mandatory| Description                      |
  | --------------- | ------------ | ---- | -------------------------- |
  | parcelableArray | Parcelable[] | Yes  | **Parcelable** array to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  class MyParcelable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
      }
      marshalling(messageSequence) {
          messageSequence.writeInt(this.num);
          messageSequence.writeString(this.str);
          return true;
      }
      unmarshalling(messageSequence) {
          this.num = messageSequence.readInt();
          this.str = messageSequence.readString();
          return true;
      }
  }
  let parcelable = new MyParcelable(1, "aaa");
  let parcelable2 = new MyParcelable(2, "bbb");
  let parcelable3 = new MyParcelable(3, "ccc");
  let a = [parcelable, parcelable2, parcelable3];
  let data = rpc.MessageSequence.create();
  try {
      data.writeParcelableArray(a);
  } catch(error) {
      console.info("rpc write parcelable array fail, errorCode " + error.code);
      console.info("rpc write parcelable array fail, errorMessage" + error.message);
  }
  ```

### readParcelableArray

readParcelableArray(parcelableArray: Parcelable[]): void

Reads a **Parcelable** array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name         | Type        | Mandatory| Description                      |
  | --------------- | ------------ | ---- | -------------------------- |
  | parcelableArray | Parcelable[] | Yes  | **Parcelable** array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |
  | 1900012 | call js callback function failed |

**Example**

  ```
  class MyParcelable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
      }
      marshalling(messageSequence) {
          messageSequence.writeInt(this.num);
          messageSequence.writeString(this.str);
          return true;
      }
      unmarshalling(messageSequence) {
          this.num = messageSequence.readInt();
          this.str = messageSequence.readString();
          return true;
      }
  }
  let parcelable = new MyParcelable(1, "aaa");
  let parcelable2 = new MyParcelable(2, "bbb");
  let parcelable3 = new MyParcelable(3, "ccc");
  let a = [parcelable, parcelable2, parcelable3];
  let data = rpc.MessageSequence.create();
  let result = data.writeParcelableArray(a);
  console.log("RpcClient: writeParcelableArray is " + result);
  let b = [new MyParcelable(0, ""), new MyParcelable(0, ""), new MyParcelable(0, "")];
  try {
      data.readParcelableArray(b);
  } catch(error) {
      console.info("rpc read parcelable array fail, errorCode " + error.code);
      console.info("rpc read parcelable array fail, errorMessage" + error.message);
  }
  data.readParcelableArray(b);
  ```

### writeRemoteObjectArray

writeRemoteObjectArray(objectArray: IRemoteObject[]): void

Writes an array of **IRemoteObject** objects to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name     | Type           | Mandatory| Description                                          |
  | ----------- | --------------- | ---- | ---------------------------------------------- |
  | objectArray | IRemoteObject[] | Yes  | Array of **IRemoteObject** objects to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------- |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
          this.modifyLocalInterface(this, descriptor);
      }

      asObject(): rpc.IRemoteObject {
          return this;
      }
  }
  let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
  let data = rpc.MessageSequence.create();
  let result = data.writeRemoteObjectArray(a);
  try {
      data.writeRemoteObjectArray(a);
  } catch(error) {
      console.info("rpc write remote object array fail, errorCode " + error.code);
      console.info("rpc write remote object array fail, errorMessage" + error.message);
  }
  console.log("RpcClient: writeRemoteObjectArray is " + result);
  ```

### readRemoteObjectArray

readRemoteObjectArray(objects: IRemoteObject[]): void

Reads an array of **IRemoteObject** objects from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type           | Mandatory| Description                                          |
  | ------- | --------------- | ---- | ---------------------------------------------- |
  | objects | IRemoteObject[] | Yes  | **IRemoteObject** array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

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
          this.modifyLocalInterface(this, descriptor);
      }

      asObject(): rpc.IRemoteObject {
          return this;
      }
  }
  let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
  let data = rpc.MessageSequence.create();
  data.writeRemoteObjectArray(a);
  let b = new Array(3);
  try {
      data.readRemoteObjectArray(b);
  } catch(error) {
      console.info("rpc read remote object array fail, errorCode " + error.code);
      console.info("rpc read remote object array fail, errorMessage" + error.message);
  }
  data.readRemoteObjectArray(b);
  ```

### readRemoteObjectArray

readRemoteObjectArray(): IRemoteObject[]

Reads the **IRemoteObject** object array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type           | Description                       |
  | --------------- | --------------------------- |
  | IRemoteObject[] | **IRemoteObject** object array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
          this.modifyLocalInterface(this, descriptor);
      }
 
      asObject(): rpc.IRemoteObject {
          return this;
      }
  }
  let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
  let data = rpc.MessageSequence.create();
  data.writeRemoteObjectArray(a);
  try {
      let b = data.readRemoteObjectArray();
      console.log("RpcClient: readRemoteObjectArray is " + b);
  } catch(error) {
      console.info("rpc read remote object array fail, errorCode " + error.code);
      console.info("rpc read remote object array fail, errorMessage" + error.message);
  }
  ```


### closeFileDescriptor<sup>9+</sup>

static closeFileDescriptor(fd: number): void

Closes a file descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                |
  | ------ | ------ | ---- | -------------------- |
  | fd     | number | Yes  | File descriptor to close.|

**Example**

  ```
  import fileio from '@ohos.fileio';
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  try {
      rpc.MessageSequence.closeFileDescriptor(fd);
  } catch(error) {
      console.info("rpc close file descriptor fail, errorCode " + error.code);
      console.info("rpc close file descriptor fail, errorMessage" + error.message);
  }
  ```

### dupFileDescriptor

static dupFileDescriptor(fd: number) :number

Duplicates a file descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                    |
  | ------ | ------ | ---- | ------------------------ |
  | fd     | number | Yes  | File descriptor to duplicate.|

**Return value**

  | Type  | Description                |
  | ------ | -------------------- |
  | number | New file descriptor.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------- |
  | 1900013 | call os dup function failed |

**Example**

  ```
  import fileio from '@ohos.fileio';
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  try {
      let newFd = rpc.MessageSequence.dupFileDescriptor(fd);
  } catch(error) {
      console.info("rpc dup file descriptor fail, errorCode " + error.code);
      console.info("rpc dup file descriptor fail, errorMessage" + error.message);
  }
  ```

### containFileDescriptors

containFileDescriptors(): boolean

Checks whether this **MessageSequence** object contains file descriptors.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type   | Description                                                                |
  | ------- | -------------------------------------------------------------------- |
  | boolean | Returns **true** if the **MessageSequence** object contains file descriptors; returns **false** otherwise.|

**Example**


  ```
  import fileio from '@ohos.fileio';
  let sequence = new rpc.MessageSequence();
  let filePath = "path/to/file";
  let r1 = sequence.containFileDescriptors();
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  try {
      sequence.writeFileDescriptor(fd);
  } catch(error) {
      console.info("rpc write file descriptor fail, errorCode " + error.code);
      console.info("rpc write file descriptor fail, errorMessage" + error.message);
  }
  try {
      let containFD = sequence.containFileDescriptors();
      console.log("RpcTest: sequence after write fd containFd result is : " + containFD);
  } catch(error) {
      console.info("rpc contain file descriptor fail, errorCode " + error.code);
      console.info("rpc contain file descriptor fail, errorMessage" + error.message);
  }
  ```

### writeFileDescriptor

writeFileDescriptor(fd: number): void

Writes a file descriptor to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description        |
  | ------ | ------ | ---- | ------------ |
  | fd     | number | Yes  | File descriptor to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------ |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  import fileio from '@ohos.fileio';
  let sequence = new rpc.MessageSequence();
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  try {
      sequence.writeFileDescriptor(fd);
  } catch(error) {
      console.info("rpc write file descriptor fail, errorCode " + error.code);
      console.info("rpc write file descriptor fail, errorMessage" + error.message);
  }
  ```


### readFileDescriptor

readFileDescriptor(): number

Reads the file descriptor from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description            |
  | ------ | ---------------- |
  | number | File descriptor read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  import fileio from '@ohos.fileio';
  let sequence = new rpc.MessageSequence();
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  try {
      sequence.writeFileDescriptor(fd);
  } catch(error) {
      console.info("rpc write file descriptor fail, errorCode " + error.code);
      console.info("rpc write file descriptor fail, errorMessage" + error.message);
  }
  try {
      let readFD = sequence.readFileDescriptor();
  } catch(error) {
      console.info("rpc read file descriptor fail, errorCode " + error.code);
      console.info("rpc read file descriptor fail, errorMessage" + error.message);
  }
  ```


### writeAshmem

writeAshmem(ashmem: Ashmem): void

Writes an anonymous shared object to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                                 |
  | ------ | ------ | ---- | ------------------------------------- |
  | ashmem | Ashmem | Yes  | Anonymous shared object to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------- |
  | 1900003 | write to ashmem failed |

**Example**

  ```
  let sequence = new rpc.MessageSequence();
  let ashmem;
  try {
      ashmem = rpc.Ashmem.create("ashmem", 1024);
  } catch(error) {
      console.info("rpc create ashmem fail, errorCode " + error.code);
      console.info("rpc creat ashmem fail, errorMessage" + error.message);
  }
  try {
      sequence.writeAshmem(ashmem);
  } catch(error) {
      console.info("rpc write ashmem fail, errorCode " + error.code);
      console.info("rpc write ashmem fail, errorMessage" + error.message);
  }
  ```


### readAshmem

readAshmem(): Ashmem

Reads the anonymous shared object from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description              |
  | ------ | ------------------ |
  | Ashmem | Anonymous share object read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900004 | read from ashmem failed |

**Example**

  ```
  let sequence = new rpc.MessageSequence();
  let ashmem;
  try {
      ashmem = rpc.Ashmem.create("ashmem", 1024);
  } catch(error) {
      console.info("rpc create ashmem fail, errorCode " + error.code);
      console.info("rpc creat ashmem fail, errorMessage" + error.message);
  }
  try {
      sequence.writeAshmem(ashmem);
  } catch(error) {
      console.info("rpc write ashmem fail, errorCode " + error.code);
      console.info("rpc write ashmem fail, errorMessage" + error.message);
  }
  try {
      let readAshmem = sequence.readAshmem();
      console.log("RpcTest: read ashmem to result is : " + readAshmem);
  } catch(error) {
      console.info("rpc read ashmem fail, errorCode " + error.code);
      console.info("rpc read ashmem fail, errorMessage" + error.message);
  }
  ```


### getRawDataCapacity

getRawDataCapacity(): number

Obtains the maximum amount of raw data that can be held by this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description                                                        |
  | ------ | ------------------------------------------------------------ |
  | number | 128 MB, which is the maximum amount of raw data that can be held by this **MessageSequence** object.|

**Example**

  ```
  let sequence = new rpc.MessageSequence();
  let result = sequence.getRawDataCapacity();
  console.log("RpcTest: sequence get RawDataCapacity result is : " + result);
  ```


### writeRawData

writeRawData(rawData: number[], size: number): void

Writes raw data to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type    | Mandatory| Description                              |
  | ------- | -------- | ---- | ---------------------------------- |
  | rawData | number[] | Yes  | Raw data to write.                |
  | size    | number   | Yes  | Size of the raw data, in bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------ |
  | 1900009 | write data to message sequence failed |

**Example**

  ```
  let sequence = new rpc.MessageSequence();
  let arr = [1, 2, 3, 4, 5];
  try {
      sequence.writeRawData(arr, arr.length);
  } catch(error) {
      console.info("rpc write rawdata fail, errorCode " + error.code);
      console.info("rpc write rawdata fail, errorMessage" + error.message);
  }
  ```


### readRawData

readRawData(size: number): number[]

Reads raw data from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                    |
  | ------ | ------ | ---- | ------------------------ |
  | size   | number | Yes  | Size of the raw data to read.|

**Return value**

  | Type    | Description                          |
  | -------- | ------------------------------ |
  | number[] | Raw data read, in bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**Example**

  ```
  let sequence = new rpc.MessageSequence();
  let arr = [1, 2, 3, 4, 5];
  try {
      sequence.writeRawData(arr, arr.length);
  } catch(error) {
      console.info("rpc write rawdata fail, errorCode " + error.code);
      console.info("rpc write rawdata fail, errorMessage" + error.message);
  }
  try {
      let result = sequence.readRawData(5);
      console.log("RpcTest: sequence read raw data result is : " + result);
  } catch(error) {
      console.info("rpc read rawdata fail, errorCode " + error.code);
      console.info("rpc read rawdata fail, errorMessage" + error.message);
  }
  ```

## MessageParcel<sup>(deprecated)</sup>

>This class is no longer maintained since API version 9. You are advised to use [MessageSequence](#messagesequence9).

Provides APIs for reading and writing data in specific format. During RPC, the sender can use the **write()** method provided by **MessageParcel** to write data in specific format to a **MessageParcel** object. The receiver can use the **read()** method provided by **MessageParcel** to read data in specific format from a **MessageParcel** object. The data formats include basic data types and arrays, IPC objects, interface tokens, and custom sequenceable objects.

### create

create(): MessageParcel

Creates a **MessageParcel** object. This method is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type         | Description                         |
  | ------------- | ----------------------------- |
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

  | Name| Type                           | Mandatory| Description                                   |
  | ------ | ------------------------------- | ---- | --------------------------------------- |
  | object | [IRemoteObject](#iremoteobject) | Yes  | Remote object to serialize and write to the **MessageParcel** object.|

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
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

  | Type                           | Description              |
  | ------------------------------- | ------------------ |
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

  | Name| Type  | Mandatory| Description              |
  | ------ | ------ | ---- | ------------------ |
  | token  | string | Yes  | Interface token to write.|

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
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

  | Type  | Description                    |
  | ------ | ------------------------ |
  | string | Interface token obtained.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
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

  | Type  | Description                                         |
  | ------ | --------------------------------------------- |
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

  | Type  | Description                                         |
  | ------ | --------------------------------------------- |
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

  | Name| Type  | Mandatory| Description                                       |
  | ------ | ------ | ---- | ------------------------------------------- |
  | size   | number | Yes  | Data size to set, in bytes.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
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

  | Name| Type  | Mandatory| Description                                       |
  | ------ | ------ | ---- | ------------------------------------------- |
  | size   | number | Yes  | Storage capacity to set, in bytes.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
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

  | Type  | Description                                               |
  | ------ | --------------------------------------------------- |
  | number | **MessageParcel** writable capacity obtained, in bytes.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
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

  | Type  | Description                                               |
  | ------ | --------------------------------------------------- |
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

  | Type  | Description                                   |
  | ------ | --------------------------------------- |
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

  | Type  | Description                                   |
  | ------ | --------------------------------------- |
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

  | Name| Type  | Mandatory| Description                    |
  | ------ | ------ | ---- | ------------------------ |
  | pos    | number | Yes  | Position from which data is to read.|

**Return value**

  | Type   | Description                                             |
  | ------- | ------------------------------------------------- |
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

  | Name| Type  | Mandatory| Description                    |
  | ------ | ------ | ---- | ------------------------ |
  | pos    | number | Yes  | Position from which data is to write.|

**Return value**

  | Type   | Description                                         |
  | ------- | --------------------------------------------- |
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

  | Name| Type  | Mandatory| Description            |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | Yes  | Byte value to write.|

**Return value**

  | Type   | Description                         |
  | ------- | ----------------------------- |
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

  | Type  | Description        |
  | ------ | ------------ |
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

  | Name| Type  | Mandatory| Description              |
  | ------ | ------ | ---- | ------------------ |
  | val    | number | Yes  | Short int value to write.|

**Return value**

  | Type   | Description                         |
  | ------- | ----------------------------- |
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

  | Type  | Description          |
  | ------ | -------------- |
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

  | Name| Type  | Mandatory| Description            |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | Yes  | Int value to write.|

**Return value**

  | Type   | Description                         |
  | ------- | ----------------------------- |
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

  | Type  | Description        |
  | ------ | ------------ |
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

  | Name| Type  | Mandatory| Description            |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | Yes  | Long int value to write.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
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

  | Type  | Description          |
  | ------ | -------------- |
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

  | Name| Type  | Mandatory| Description            |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | Yes  | Float value to write.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
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

  | Type  | Description        |
  | ------ | ------------ |
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

  | Name| Type  | Mandatory| Description                  |
  | ------ | ------ | ---- | ---------------------- |
  | val    | number | Yes  | Double value to write.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
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

  | Type  | Description              |
  | ------ | ------------------ |
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

  | Name| Type   | Mandatory| Description            |
  | ------ | ------- | ---- | ---------------- |
  | val    | boolean | Yes  | Boolean value to write.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
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

  | Type   | Description                |
  | ------- | -------------------- |
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

  | Name| Type  | Mandatory| Description                |
  | ------ | ------ | ---- | -------------------- |
  | val    | number | Yes  | Char value to write.|

**Return value**

  | Type   | Description                         |
  | ------- | ----------------------------- |
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

  | Type  | Description            |
  | ------ | ---------------- |
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

  | Name| Type  | Mandatory| Description                                     |
  | ------ | ------ | ---- | ----------------------------------------- |
  | val    | string | Yes  | String to write. The length of the string must be less than 40960 bytes.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeString('abc');
  console.log("RpcClient: writeString  is " + result);
  ```


### readString

readString(): string

Reads the string from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description          |
  | ------ | -------------- |
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

  | Name| Type                         | Mandatory| Description                |
  | ------ | ----------------------------- | ---- | -------------------- |
  | val    | [Sequenceable](#sequenceable) | Yes  | Sequenceable object to write.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
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

readSequenceable(dataIn: Sequenceable): boolean

Reads member variables from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type                         | Mandatory| Description                                   |
  | ------ | ----------------------------- | ---- | --------------------------------------- |
  | dataIn | [Sequenceable](#sequenceabledeprecated) | Yes  | Object that reads member variables from the **MessageParcel** object.|

**Return value**

  | Type   | Description                                       |
  | ------- | ------------------------------------------- |
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

  | Name   | Type    | Mandatory| Description              |
  | --------- | -------- | ---- | ------------------ |
  | byteArray | number[] | Yes  | Byte array to write.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let result = data.writeByteArray(ByteArrayVar);
  console.log("RpcClient: writeByteArray is " + result);
  ```


### readByteArray

readByteArray(dataIn: number[]): void

Reads a byte array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description              |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | Yes  | Byte array to read.|

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

  | Type    | Description          |
  | -------- | -------------- |
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

  | Name    | Type    | Mandatory| Description                |
  | ---------- | -------- | ---- | -------------------- |
  | shortArray | number[] | Yes  | Short array to write.|

**Return value**

  | Type   | Description                         |
  | ------- | ----------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  ```


### readShortArray

readShortArray(dataIn: number[]): void

Reads a short array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | Yes  | Short array to read.|

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

  | Type    | Description            |
  | -------- | ---------------- |
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

  | Name  | Type    | Mandatory| Description              |
  | -------- | -------- | ---- | ------------------ |
  | intArray | number[] | Yes  | Integer array to write.|

**Return value**

  | Type   | Description                         |
  | ------- | ----------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  ```


### readIntArray

readIntArray(dataIn: number[]): void

Reads an integer array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description              |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | Yes  | Integer array to read.|

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

  | Type    | Description          |
  | -------- | -------------- |
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

  | Name   | Type    | Mandatory| Description                |
  | --------- | -------- | ---- | -------------------- |
  | longArray | number[] | Yes  | Long array to write.|

**Return value**

  | Type   | Description                         |
  | ------- | ----------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  ```


### readLongArray

readLongArray(dataIn: number[]): void

Reads a long array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | Yes  | Long array to read.|

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

 | Type    | Description            |
 | -------- | ---------------- |
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
  | ---------- | -------- | ---- | --- |
  | floatArray | number[] | Yes  | Floating-point array to write. The system processes Float data as that of the Double type. Therefore, the total number of bytes occupied by a FloatArray must be calculated as the Double type.|

**Return value**

  | Type   | Description                         |
  | ------- | ----------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  ```


### readFloatArray

readFloatArray(dataIn: number[]): void

Reads a FloatArray from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | -------- | ---- | ------ |
  | dataIn | number[] | Yes  | Floating-point array to read. The system processes Float data as that of the Double type. Therefore, the total number of bytes occupied by a FloatArray must be calculated as the Double type.|

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

  | Type    | Description          |
  | -------- | -------------- |
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

  | Name     | Type    | Mandatory| Description                    |
  | ----------- | -------- | ---- | ------------------------ |
  | doubleArray | number[] | Yes  | DoubleArray to write.|

**Return value**

  | Type   | Description                         |
  | ------- | ----------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  ```


### readDoubleArray

readDoubleArray(dataIn: number[]): void

Reads a DoubleArray from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                    |
  | ------ | -------- | ---- | ------------------------ |
  | dataIn | number[] | Yes  | DoubleArray to read.|

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

  | Type    | Description                |
  | -------- | -------------------- |
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

  | Name      | Type     | Mandatory| Description              |
  | ------------ | --------- | ---- | ------------------ |
  | booleanArray | boolean[] | Yes  | Boolean array to write.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  ```


### readBooleanArray

readBooleanArray(dataIn: boolean[]): void

Reads a Boolean array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type     | Mandatory| Description              |
  | ------ | --------- | ---- | ------------------ |
  | dataIn | boolean[] | Yes  | Boolean array to read.|

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

  | Type     | Description          |
  | --------- | -------------- |
  | boolean[] | Boolean array read.|

**Example**

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

  | Name   | Type    | Mandatory| Description                  |
  | --------- | -------- | ---- | ---------------------- |
  | charArray | number[] | Yes  | Character array to write.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 88]);
  console.log("RpcClient: writeCharArray is " + result);
  ```


### readCharArray

readCharArray(dataIn: number[]): void

Reads a character array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                  |
  | ------ | -------- | ---- | ---------------------- |
  | dataIn | number[] | Yes  | Character array to read.|

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

  | Type    | Description              |
  | -------- | ------------------ |
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

  | Name     | Type    | Mandatory| Description|
  | ----------- | -------- | ---- | ---------------- |
  | stringArray | string[] | Yes  | String array to write. The length of a single element in the array must be less than 40960 bytes.|

**Return value**

  | Type   | Description|
  | ------- | --------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  console.log("RpcClient: writeStringArray is " + result);
  ```


### readStringArray

readStringArray(dataIn: string[]): void

Reads a string array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | string[] | Yes  | String array to read.|

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

  | Type    | Description            |
  | -------- | ---------------- |
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
  proxy.sendMessageRequest(1, data, reply, option)
      .then(function(errCode) {
          if (errCode === 0) {
              console.log("sendMessageRequest got result");
              reply.readException();
              let msg = reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendMessageRequest failed, errCode: " + errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendMessageRequest got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendMessageRequest ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```

### writeSequenceableArray

writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean

Writes a sequenceable array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name           | Type          | Mandatory| Description                      |
  | ----------------- | -------------- | ---- | -------------------------- |
  | sequenceableArray | Sequenceable[] | Yes  | Sequenceable array to write.|

**Return value**

  | Type   | Description                             |
  | ------- | --------------------------------- |
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

  | Name           | Type          | Mandatory| Description                      |
  | ----------------- | -------------- | ---- | -------------------------- |
  | sequenceableArray | Sequenceable[] | Yes  | Sequenceable array to read.|

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

  | Name     | Type           | Mandatory| Description|
  | ----------- | --------------- | ---- | ----- |
  | objectArray | IRemoteObject[] | Yes  | Array of **IRemoteObject** objects to write.|

**Return value**

  | Type   | Description                                                                                                                |
  | ------- | -------------------------------------------------------------------------------------------------------------------- |
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

  | Name | Type           | Mandatory| Description|
  | ------- | --------------- | ---- | --------- |
  | objects | IRemoteObject[] | Yes  | **IRemoteObject** array to read.|

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
  | --------------- | -------- |
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

  | Name| Type  | Mandatory| Description                |
  | ------ | ------ | ---- | -------------------- |
  | fd     | number | Yes  | File descriptor to close.|

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

  | Name| Type  | Mandatory| Description                    |
  | ------ | ------ | ---- | ------------------------ |
  | fd     | number | Yes  | File descriptor to duplicate.|

**Return value**

  | Type  | Description                |
  | ------ | -------------------- |
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

  | Type   | Description                                                              |
  | ------- | ------------------------------------------------------------------ |
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

  | Name| Type  | Mandatory| Description        |
  | ------ | ------ | ---- | ------------ |
  | fd     | number | Yes  | File descriptor to write.|

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
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

  | Type  | Description            |
  | ------ | ---------------- |
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

  | Name| Type  | Mandatory| Description                               |
  | ------ | ------ | ---- | ----------------------------------- |
  | ashmem | Ashmem | Yes  | Anonymous shared object to write.|

**Return value**

  | Type   | Description                                                                |
  | ------- | -------------------------------------------------------------------- |
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

  | Type  | Description              |
  | ------ | ------------------ |
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

  | Type  | Description                                                      |
  | ------ | ---------------------------------------------------------- |
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

  | Name | Type    | Mandatory| Description                              |
  | ------- | -------- | ---- | ---------------------------------- |
  | rawData | number[] | Yes  | Raw data to write.                |
  | size    | number   | Yes  | Size of the raw data, in bytes.|

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
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

  | Name| Type  | Mandatory| Description                    |
  | ------ | ------ | ---- | ------------------------ |
  | size   | number | Yes  | Size of the raw data to read.|

**Return value**

  | Type    | Description                          |
  | -------- | ------------------------------ |
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


## Parcelable<sup>9+</sup>

Writes an object to a **MessageSequence** and reads it from the **MessageSequence** during IPC.

### marshalling

marshalling(dataOut: MessageSequence): boolean

Marshals this **Parcelable** object into a **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type           | Mandatory| Description                                       |
  | ------- | --------------- | ---- | ------------------------------------------- |
  | dataOut | MessageSequence | Yes  | **MessageSequence** object to which the **Parcelable** object is to be marshaled.|

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  class MyParcelable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
      }
      marshalling(messageSequence) {
          messageSequence.writeInt(this.num);
          messageSequence.writeString(this.str);
          return true;
      }
      unmarshalling(messageSequence) {
          this.num = messageSequence.readInt();
          this.str = messageSequence.readString();
          return true;
      }
  }
  let parcelable = new MyParcelable(1, "aaa");
  let data = rpc.MessageSequence.create();
  let result = data.writeParcelable(parcelable);
  console.log("RpcClient: writeParcelable is " + result);
  let ret = new MyParcelable(0, "");
  let result2 = data.readParcelable(ret);
  console.log("RpcClient: readParcelable is " + result2);
  ```


### unmarshalling

unmarshalling(dataIn: MessageSequence): boolean

Unmarshals this **Parcelable** object from a **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type           | Mandatory| Description                                           |
  | ------ | --------------- | ---- | ----------------------------------------------- |
  | dataIn | MessageSequence | Yes  | **MessageSequence** object from which the **Parcelable** object is to be unmarshaled.|

**Return value**

  | Type   | Description                                         |
  | ------- | --------------------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  class MyParcelable {
      num: number;
      str: string;
      constructor(num, str) {
          this.num = num;
          this.str = str;
      }
      marshalling(messageSequence) {
          messageSequence.writeInt(this.num);
          messageSequence.writeString(this.str);
          return true;
      }
      unmarshalling(messageSequence) {
          this.num = messageSequence.readInt();
          this.str = messageSequence.readString();
          return true;
      }
  }
  let parcelable = new MyParcelable(1, "aaa");
  let data = rpc.MessageSequence.create();
  let result = data.writeParcelable(parcelable);
  console.log("RpcClient: writeParcelable is " + result);
  let ret = new MyParcelable(0, "");
  let result2 = data.readParcelable(ret);
  console.log("RpcClient: readParcelable is " + result2);
  ```


## Sequenceable<sup>(deprecated)</sup>

>This class is no longer maintained since API version 9. You are advised to use the [Parcelable](#parcelable9).

Writes objects of classes to a **MessageParcel** and reads them from the **MessageParcel** during IPC.

### marshalling

marshalling(dataOut: MessageParcel): boolean

Marshals the sequenceable object into a **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type                           | Mandatory| Description                                     |
  | ------- | ------------------------------- | ---- | ----------------------------------------- |
  | dataOut | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object to which the sequenceable object is to be marshaled.|

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
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

unmarshalling(dataIn: MessageParcel): boolean

Unmarshals this sequenceable object from a **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type                           | Mandatory| Description                                         |
  | ------ | ------------------------------- | ---- | --------------------------------------------- |
  | dataIn | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object in which the sequenceable object is to be unmarshaled.|

**Return value**

  | Type   | Description                                         |
  | ------- | --------------------------------------------- |
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

  | Type | Description|
  | ---- | ----- |
  | [IRemoteObject](#iremoteobject) | Returns the **RemoteObject** if it is the caller; returns the [IRemoteObject](#iremoteobject), the holder of this **RemoteProxy** object, if the caller is a [RemoteProxy](#remoteproxy) object.|

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

## RequestResult<sup>9+</sup>

Defines the response to the request.

**System capability**: SystemCapability.Communication.IPC.Core

  | Name   | Type           | Readable| Writable| Description                                 |
  | ------- | --------------- | ---- | ---- |-------------------------------------- |
  | errCode | number          | Yes  | No  | Error Code                             |
  | code    | number          | Yes  | No  | Message code.                           |
  | data    | MessageSequence | Yes  | No  | **MessageSequence** object sent to the remote process.|
  | reply   | MessageSequence | Yes  | No  | **MessageSequence** object returned by the remote process.  |

## SendRequestResult<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [RequestResult](#requestresult9).

Defines the response to the request.

**System capability**: SystemCapability.Communication.IPC.Core

  | Name   | Type         | Readable| Writable| Description                               |
  | ------- | ------------- | ---- | ---- | ----------------------------------- |
  | errCode | number        | Yes  | No  | Error Code                           |
  | code    | number        | Yes  | No  | Message code.                         |
  | data    | MessageParcel | Yes  | No  | **MessageParcel** object sent to the remote process.|
  | reply   | MessageParcel | Yes  | No  | **MessageParcel** object returned by the remote process.  |

## IRemoteObject

Provides methods to query of obtain interface descriptors, add or delete death notifications, dump object status to specific files, and send messages.

### getLocalInterface<sup>9+</sup>

getLocalInterface(descriptor: string): IRemoteBroker

Obtains the interface.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name    | Type  | Mandatory| Description                |
  | ---------- | ------ | ---- | -------------------- |
  | descriptor | string | Yes  | Interface descriptor.|

**Return value**

  | Type         | Description                                         |
  | ------------- | --------------------------------------------- |
  | IRemoteBroker | **IRemoteBroker** object bound to the specified interface token.|

### queryLocalInterface<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [getLocalInterface](#getlocalinterface9).

queryLocalInterface(descriptor: string): IRemoteBroker

Obtains the interface.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name    | Type  | Mandatory| Description                |
  | ---------- | ------ | ---- | -------------------- |
  | descriptor | string | Yes  | Interface descriptor.|

**Return value**

  | Type         | Description                                         |
  | ------------- | --------------------------------------------- |
  | IRemoteBroker | **IRemoteBroker** object bound to the specified interface token.|


### sendRequest<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [sendMessageRequest](#sendmessagerequest9).

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type| Mandatory| Description |
  | ------- | ------------------------------- | ---- | ---- |
  | code    | number                          | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
  | reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
  | options | [MessageOption](#messageoption) | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

  | Type   | Description                                         |
  | ------- | --------------------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|


### sendRequest<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [sendMessageRequest](#sendmessagerequest9).

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type                           | Mandatory| Description                                                                                  |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
  | reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
  | options | [MessageOption](#messageoption) | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

  | Type                            | Description                                         |
  | -------------------------------- | --------------------------------------------- |
  | Promise&lt;SendRequestResult&gt; | Promise used to return the **sendRequestResult** object.|


### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise&lt;RequestResult&gt;

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendMessageRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type                           | Mandatory| Description                                                                                  |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data    | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
  | reply   | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that receives the response.                                                   |
  | options | [MessageOption](#messageoption) | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

  | Type                        | Description                                     |
  | ---------------------------- | ----------------------------------------- |
  | Promise&lt;RequestResult&gt; | Promise used to return the **requestResult** object.|


### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback&lt;RequestResult&gt;): void

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a callback will be invoked immediately and the reply message does not contain any content. If **options** is the synchronous mode, a callback will be invoked when the response to sendRequest is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name  | Type                              | Mandatory| Description                                                                                  |
  | -------- | ---------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code     | number                             | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data     | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
  | reply    | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that receives the response.                                                   |
  | options  | [MessageOption](#messageoption)    | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |
  | callback | AsyncCallback&lt;RequestResult&gt; | Yes  | Callback for receiving the sending result.                                                                  |


### sendRequest<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [sendMessageRequest](#sendmessagerequest9).

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a callback will be invoked immediately and the reply message does not contain any content. If **options** is the synchronous mode, a callback will be invoked when the response to sendRequest is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name  | Type                                  | Mandatory| Description                                                                                  |
  | -------- | -------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code     | number                                 | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data     | [MessageParcel](#messageparceldeprecated)        | Yes  | **MessageParcel** object holding the data to send.                                             |
  | reply    | [MessageParcel](#messageparceldeprecated)        | Yes  | **MessageParcel** object that receives the response.                                                     |
  | options  | [MessageOption](#messageoption)        | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |
  | callback | AsyncCallback&lt;SendRequestResult&gt; | Yes  | Callback for receiving the sending result.                                                                  |


### registerDeathRecipient<sup>9+</sup>

registerDeathRecipient(recipient: DeathRecipient, flags: number): void

Adds a callback for receiving death notifications of the remote object. This method is called if the remote object process matching the **RemoteProxy** object is killed.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type                             | Mandatory| Description          |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to add.|
  | flags     | number                            | Yes  | Flag of the death notification.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |


### addDeathrecipient<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [registerDeathRecipient](#registerdeathrecipient9).

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Adds a callback for receiving death notifications of the remote object. This method is called if the remote object process matching the **RemoteProxy** object is killed.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type                             | Mandatory| Description          |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to add.|
  | flags     | number                            | Yes  | Flag of the death notification.|

**Return value**

  | Type   | Description                                         |
  | ------- | --------------------------------------------- |
  | boolean | Returns **true** if the callback is added successfully; returns **false** otherwise.|


### unregisterDeathRecipient<sup>9+</sup>

unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void

Removes the callback used to receive death notifications of the remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type                             | Mandatory| Description          |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to remove.|
  | flags     | number                            | Yes  | Flag of the death notification.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |


### removeDeathRecipient<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [unregisterDeathRecipient](#unregisterdeathrecipient9).

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Removes the callback used to receive death notifications of the remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type                             | Mandatory| Description          |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to remove.|
  | flags     | number                            | Yes  | Flag of the death notification.|

**Return value**

  | Type   | Description                                         |
  | ------- | --------------------------------------------- |
  | boolean | Returns **true** if the callback is removed successfully; returns **false** otherwise.|


### getDescriptor<sup>9+</sup>

getDescriptor(): string

Obtains the interface descriptor of this object. The interface descriptor is a string.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description            |
  | ------ | ---------------- |
  | string | Interface descriptor obtained.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |


### getInterfaceDescriptor<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [getDescriptor](#getdescriptor9).

getInterfaceDescriptor(): string

Obtains the interface descriptor of this object. The interface descriptor is a string.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description            |
  | ------ | ---------------- |
  | string | Interface descriptor obtained.|


### isObjectDead

isObjectDead(): boolean

Checks whether this object is dead.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type   | Description                                       |
  | ------- | ------------------------------------------- |
  | boolean | Returns **true** if the object is dead; returns **false** otherwise.|


## RemoteProxy

Provides APIs to implement **IRemoteObject**.

**System capability**: SystemCapability.Communication.IPC.Core

| Name                 | Value                     | Description                             |
| --------------------- | ----------------------- | --------------------------------- |
| PING_TRANSACTION      | 1599098439 (0x5f504e47) | Internal instruction code used to test whether the IPC service is normal.|
| DUMP_TRANSACTION      | 1598311760 (0x5f444d50) | Internal instruction code used to obtain the internal status of the binder. |
| INTERFACE_TRANSACTION | 1598968902 (0x5f4e5446) | Internal instruction code used to obtain the remote interface token. |
| MIN_TRANSACTION_ID    | 1 (0x00000001)          | Minimum valid instruction code.                 |
| MAX_TRANSACTION_ID    | 16777215 (0x00FFFFFF)   | Maximum valid instruction code.                 |


### sendRequest<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [sendMessageRequest](#sendmessagerequest9).

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type                           | Mandatory| Description                                                                                  |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
  | reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
  | options | [MessageOption](#messageoption) | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

  | Type   | Description                                         |
  | ------- | --------------------------------------------- |
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


### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise&lt;RequestResult&gt;

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendMessageRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type                           | Mandatory| Description                                                                                  |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data    | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
  | reply   | [MessageSequence](#messagesequence9)  | Yes  | **MessageSequence** object that receives the response.                                                   |
  | options | [MessageOption](#messageoption) | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

  | Type                        | Description                                     |
  | ---------------------------- | ----------------------------------------- |
  | Promise&lt;RequestResult&gt; | Promise used to return the **requestResult** object.|

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
  let data = rpc.MessageSequence.create();
  let reply = rpc.MessageSequence.create();
  data.writeInt(1);
  data.writeString("hello");
  proxy.sendMessageRequest(1, data, reply, option)
      .then(function(result) {
          if (result.errCode === 0) {
              console.log("sendMessageRequest got result");
              result.reply.readException();
              let msg = result.reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendMessageRequest failed, errCode: " + result.errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendMessageRequest got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendMessageRequest ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```


### sendRequest<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [sendMessageRequest](#sendmessagerequest9).

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type                           | Mandatory| Description                                                                                  |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
  | reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
  | options | [MessageOption](#messageoption) | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

  | Type                            | Description                                         |
  | -------------------------------- | --------------------------------------------- |
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

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback&lt;RequestResult&gt;): void

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a callback will be invoked immediately and the reply message does not contain any content. If **options** is the synchronous mode, a callback will be invoked at certain time after the response to **sendMessageRequest** is returned, and the reply contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name  | Type                              | Mandatory| Description                                                                                  |
  | -------- | ---------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code     | number                             | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data     | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
  | reply    | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that receives the response.                                                   |
  | options  | [MessageOption](#messageoption)    | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |
  | callback | AsyncCallback&lt;RequestResult&gt; | Yes  | Callback for receiving the sending result.                                                                  |


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
  let data = rpc.MessageSequence.create();
  let reply = rpc.MessageSequence.create();
  data.writeInt(1);
  data.writeString("hello");
  try {
      proxy.sendRequest(1, data, reply, option, sendRequestCallback);
  } catch(error) {
      console.info("rpc send sequence request fail, errorCode " + error.code);
      console.info("rpc send sequence request fail, errorMessage " + error.message);
  }
  ```


### sendRequest<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [sendMessageRequest](#sendmessagerequest9).

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a callback will be invoked immediately and the reply message does not contain any content. If **options** is the synchronous mode, a callback will be invoked when the response to sendRequest is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name  | Type                                  | Mandatory| Description                                                                                  |
  | -------- | -------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code     | number                                 | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data     | [MessageParcel](#messageparceldeprecated)        | Yes  | **MessageParcel** object holding the data to send.                                             |
  | reply    | [MessageParcel](#messageparceldeprecated)        | Yes  | **MessageParcel** object that receives the response.                                                     |
  | options  | [MessageOption](#messageoption)        | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |
  | callback | AsyncCallback&lt;SendRequestResult&gt; | Yes  | Callback for receiving the sending result.                                                                  |

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


### getLocalInterface<sup>9+</sup>

getLocalInterface(interface: string): IRemoteBroker

Obtains the **LocalInterface** object of an interface token.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type  | Mandatory| Description                  |
  | --------- | ------ | ---- | ---------------------- |
  | interface | string | Yes  | Interface descriptor.|

**Return value**

  | Type         | Description                                      |
  | ------------- | ------------------------------------------ |
  | IRemoteBroker | Returns **Null** by default, which indicates a proxy interface.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | --------  |
  | 1900006 | only remote object permitted |

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
  try {
      let broker = proxy.getLocalInterface("testObject");
      console.log("RpcClient: getLocalInterface is " + broker);
  } catch(error) {
      console.info("rpc get local interface fail, errorCode " + error.code);
      console.info("rpc get local interface fail, errorMessage " + error.message);
  }
  ```


### queryLocalInterface<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [getLocalInterface](#getlocalinterface9).

queryLocalInterface(interface: string): IRemoteBroker

Obtains the **LocalInterface** object of an interface token.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type  | Mandatory| Description                  |
  | --------- | ------ | ---- | ---------------------- |
  | interface | string | Yes  | Interface descriptor.|

**Return value**

  | Type         | Description                                      |
  | ------------- | ------------------------------------------ |
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


### registerDeathRecipient<sup>9+</sup>

registerDeathRecipient(recipient: DeathRecipient, flags: number): void

Adds a callback for receiving death notifications of the remote object. This method is called if the remote object process matching the **RemoteProxy** object is killed.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type                             | Mandatory| Description          |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to add.|
  | flags     | number                            | Yes  | Flag of the death notification.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |

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
  try {
      proxy.registerDeathRecippient(deathRecipient, 0);
  } catch(error) {
      console.info("proxy register deathRecipient fail, errorCode " + error.code);
      console.info("proxy register deathRecipient fail, errorMessage " + error.message);
  }
  ```


### addDeathRecippient<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [registerDeathRecipient](#registerdeathrecipient9).

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Adds a callback for receiving the death notifications of the remote object, including the death notifications of the remote proxy.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type                             | Mandatory| Description                             |
  | --------- | --------------------------------- | ---- | --------------------------------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to add.         |
  | flags     | number                            | Yes  | Flag of the death notification. This parameter is reserved. It is set to **0**.|

**Return value**

  | Type   | Description                                         |
  | ------- | --------------------------------------------- |
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

### unregisterDeathRecipient<sup>9+</sup>

unregisterDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Removes the callback used to receive death notifications of the remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type                             | Mandatory| Description          |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to remove.|
  | flags     | number                            | Yes  | Flag of the death notification.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |

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
  try {
      proxy.registerDeathRecippient(deathRecipient, 0);
      proxy.unregisterDeathRecippient(deathRecipient, 0);
  } catch(error) {
      console.info("proxy register deathRecipient fail, errorCode " + error.code);
      console.info("proxy register deathRecipient fail, errorMessage " + error.message);
  }
  ```


### removeDeathRecipient<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [unregisterDeathRecipient](#unregisterdeathrecipient9).

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Removes the callback used to receive death notifications of the remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type                             | Mandatory| Description                             |
  | --------- | --------------------------------- | ---- | --------------------------------- |
  | recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to remove.               |
  | flags     | number                            | Yes  | Flag of the death notification. This parameter is reserved. It is set to **0**.|

**Return value**

  | Type   | Description                                         |
  | ------- | --------------------------------------------- |
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


### getDescriptor<sup>9+</sup>

getDescriptor(): string

Obtains the interface descriptor of this object. The interface descriptor is a string.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description            |
  | ------ | ---------------- |
  | string | Interface descriptor obtained.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------- |
  | 1900008 | proxy or remote object is invalid |
  | 1900007 | communication failed              |

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
  try {
      let descriptor = proxy.getDescriptor();
      console.log("RpcClient: descriptor is " + descriptor);
  } catch(error) {
      console.info("rpc get interface descriptor fail, errorCode " + error.code);
      console.info("rpc get interface descriptor fail, errorMessage " + error.message);
  }
  ```


### getInterfaceDescriptor<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [getDescriptor](#getdescriptor9).

getInterfaceDescriptor(): string

Obtains the interface descriptor of this proxy object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description              |
  | ------ | ------------------ |
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

  | Type   | Description                                                     |
  | ------- | --------------------------------------------------------- |
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

Provides common message options (flag and wait time). Use the specified flag to construct the **MessageOption** object.

**System capability**: SystemCapability.Communication.IPC.Core

  | Name         | Value  | Description                                                       |
  | ------------- | ---- | ----------------------------------------------------------- |
  | TF_SYNC       | 0    | Synchronous call.                                                 |
  | TF_ASYNC      | 1    | Asynchronous call.                                                 |
  | TF_ACCEPT_FDS | 0x10 | Indication to **sendMessageRequest<sup>9+</sup>** for returning the file descriptor.|
  | TF_WAIT_TIME  | 8    | Default waiting time, in seconds.                                         |


### constructor<sup>9+</sup>

constructor(async?: boolean);

A constructor used to create a **MessageOption** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type  | Mandatory| Description                                  |
  | --------- | ------ | ---- | -------------------------------------- |
  | syncFlags | number | No  | Call flag, which can be synchronous or asynchronous. The default value is **synchronous**.|


### constructor

constructor(syncFlags?: number, waitTime?: number)

A constructor used to create a **MessageOption** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name   | Type  | Mandatory| Description                                         |
  | --------- | ------ | ---- | --------------------------------------------- |
  | syncFlags | number | No  | Call flag, which can be synchronous or asynchronous. The default value is **synchronous**.       |
  | waitTime  | number | No  | Maximum wait time for an RPC call. The default value is **TF_WAIT_TIME**.|


### isAsync<sup>9+</sup>

isAsync(): boolean;

Checks whether **SendMessageRequest** is called synchronously or asynchronously.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type   | Description                                |
  | ------- | ------------------------------------ |
  | boolean | Call mode obtained.|


### setAsync<sup>9+</sup>

setAsync(async: boolean): void;

Sets whether **SendMessageRequest** is called synchronously or asynchronously.

**System capability**: SystemCapability.Communication.IPC.Core


### getFlags

getFlags(): number

Obtains the call flag, which can be synchronous or asynchronous.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description                                |
  | ------ | ------------------------------------ |
  | number | Call mode obtained.|


### setFlags

setFlags(flags: number): void

Sets the call flag, which can be synchronous or asynchronous.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                    |
  | ------ | ------ | ---- | ------------------------ |
  | flags  | number | Yes  | Call flag to set.|


### getWaitTime

getWaitTime(): number

Obtains the maximum wait time for this RPC call.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description             |
  | ------ | ----------------- |
  | number | Maximum wait time obtained.|


### setWaitTime

setWaitTime(waitTime: number): void

Sets the maximum wait time for this RPC call.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name  | Type  | Mandatory| Description                 |
  | -------- | ------ | ---- | --------------------- |
  | waitTime | number | Yes  | Maximum wait time to set.|


## IPCSkeleton

Obtains IPC context information, including the UID and PID, local and remote device IDs, and whether the method is invoked on the same device.

### getContextObject

static getContextObject(): IRemoteObject

Obtains the system capability manager.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type                           | Description                |
  | ------------------------------- | -------------------- |
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

  | Type  | Description             |
  | ------ | ----------------- |
  | number | PID of the caller.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
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

  | Type  | Description             |
  | ------ | ----------------- |
  | number | UID of the caller.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
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


**Return value**
 
   | Type  | Description                 |
   | ------ | --------------------- |
   | number | Token ID of the caller obtained.|
  
**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
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

  | Type  | Description                        |
  | ------ | ---------------------------- |
  | string | Device ID obtained.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
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

  | Type  | Description              |
  | ------ | ------------------ |
  | string | Local device ID obtained.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
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

  | Type   | Description                                                     |
  | ------- | --------------------------------------------------------- |
  | boolean | Returns **true** if the local and remote processes are on the same device; returns **false** otherwise.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
          let isLocalCalling = rpc.IPCSkeleton.isLocalCalling();
          console.log("RpcServer: isLocalCalling is: " + isLocalCalling);
          return true;
      }
  }
  ```


### flushCmdBuffer<sup>9+</sup>

static flushCmdBuffer(object: IRemoteObject): void

Flushes all suspended commands from the specified **RemoteProxy** to the corresponding **RemoteObject**. It is recommended that this method be called before any time-sensitive operation is performed.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type                           | Mandatory| Description               |
  | ------ | ------------------------------- | ---- | ------------------- |
  | object | [IRemoteObject](#iremoteobject) | Yes  | **RemoteProxy** specified. |


**Example**

  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let remoteObject = new TestRemoteObject("aaa");
  try {
      rpc.IPCSkeleton.flushCmdBuffer(remoteObject);
  } catch(error) {
      console.info("proxy set calling identity fail, errorCode " + error.code);
      console.info("proxy set calling identity fail, errorMessage " + error.message);
  }
  ```


### flushCommands<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [flushCmdBuffer](#flushcmdbuffer9).

static flushCommands(object: IRemoteObject): number

Flushes all suspended commands from the specified **RemoteProxy** to the corresponding **RemoteObject**. It is recommended that this method be called before any time-sensitive operation is performed.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type                           | Mandatory| Description               |
  | ------ | ------------------------------- | ---- | ------------------- |
  | object | [IRemoteObject](#iremoteobject) | Yes  | **RemoteProxy** specified. |

**Return value**

  | Type  | Description                                                                             |
  | ------ | --------------------------------------------------------------------------------- |
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

  | Type  | Description                                |
  | ------ | ------------------------------------ |
  | string | String containing the UID and PID of the remote user.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
          let callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();
          console.log("RpcServer: callingIdentity is: " + callingIdentity);
          return true;
      }
  }
  ```


### restoreCallingIdentity<sup>9+</sup>

static restoreCallingIdentity(identity: string): void

Changes the UID and PID of the remote user to the UID and PID of the local user. This method is used in scenarios such as identity authentication.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name  | Type  | Mandatory| Description                                                              |
  | -------- | ------ | ---- | ------------------------------------------------------------------ |
  | identity | string | Yes  | String containing the remote user UID and PID, which are returned by **resetCallingIdentity**.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
          let callingIdentity = null;
          try {
              callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();
              console.log("RpcServer: callingIdentity is: " + callingIdentity);
          } finally {
              rpc.IPCSkeleton.restoreCallingIdentity("callingIdentity ");
          }
          return true;
      }
  }
  ```


### setCallingIdentity<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [restoreCallingIdentity](#restorecallingidentity9).

static setCallingIdentity(identity: string): boolean

Restores the UID and PID of the remote user. It is usually called when the UID and PID of the remote user are required. The UID and PID of the remote user are returned by **resetCallingIdentity**.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name  | Type  | Mandatory| Description                                                              |
  | -------- | ------ | ---- | ------------------------------------------------------------------ |
  | identity | string | Yes  | String containing the remote user UID and PID, which are returned by **resetCallingIdentity**.|

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  class Stub extends rpc.RemoteObject {
      onRemoteMessageRequest(code, data, reply, option) {
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

  | Name    | Type  | Mandatory| Description        |
  | ---------- | ------ | ---- | ------------ |
  | descriptor | string | Yes  | Interface descriptor.|


### sendRequest<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [sendMessageRequest](#sendmessagerequest9).

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type                           | Mandatory| Description                                                                                  |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
  | reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
  | options | [MessageOption](#messageoption) | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

  | Type   | Description                                         |
  | ------- | --------------------------------------------- |
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

>This API is no longer maintained since API version 9. You are advised to use [sendMessageRequest](#sendmessagerequest9).

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type                           | Mandatory| Description                                                                                  |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
  | reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
  | options | [MessageOption](#messageoption) | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

  | Type                            | Description                                         |
  | -------------------------------- | --------------------------------------------- |
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

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise&lt;RequestResult&gt;

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a promise will be fulfilled immediately and the reply message does not contain any content. If **options** is the synchronous mode, a promise will be fulfilled when the response to **sendMessageRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type                           | Mandatory| Description                                                                                  |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data    | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
  | reply   | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that receives the response.                                                   |
  | options | [MessageOption](#messageoption) | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

  | Type                        | Description                                         |
  | ---------------------------- | --------------------------------------------- |
  | Promise&lt;RequestResult&gt; | Promise used to return the **sendRequestResult** object.|

**Example**

  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  let option = new rpc.MessageOption();
  let data = rpc.MessageSequence.create();
  let reply = rpc.MessageSequence.create();
  data.writeInt(1);
  data.writeString("hello");
  testRemoteObject.sendMessageRequest(1, data, reply, option)
      .then(function(result) {
          if (result.errCode === 0) {
              console.log("sendMessageRequest got result");
              result.reply.readException();
              let msg = result.reply.readString();
              console.log("RPCTest: reply msg: " + msg);
          } else {
              console.log("RPCTest: sendMessageRequest failed, errCode: " + result.errCode);
          }
      }).catch(function(e) {
          console.log("RPCTest: sendMessageRequest got exception: " + e.message);
      }).finally (() => {
          console.log("RPCTest: sendMessageRequest ends, reclaim parcel");
          data.reclaim();
          reply.reclaim();
      });
  ```


### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback&lt;RequestResult&gt;): void

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a callback will be invoked immediately and the reply message does not contain any content. If **options** is the synchronous mode, a callback will be invoked when the response to **sendMessageRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name       | Type                              | Mandatory| Description                                                                                  |
  | ------------- | ---------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code          | number                             | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data          | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
  | reply         | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that receives the response.                                                   |
  | options       | [MessageOption](#messageoption)    | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |
  | AsyncCallback | AsyncCallback&lt;RequestResult&gt; | Yes  | Callback for receiving the sending result.                                                                  |

**Example**

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
  let data = rpc.MessageSequence.create();
  let reply = rpc.MessageSequence.create();
  data.writeInt(1);
  data.writeString("hello");
  testRemoteObject.sendMessageRequest(1, data, reply, option, sendRequestCallback);
  ```


### sendRequest<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [sendMessageRequest](#sendmessagerequest9).

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If **options** is the asynchronous mode, a callback will be invoked immediately and the reply message does not contain any content. If **options** is the synchronous mode, a callback will be invoked when the response to sendRequest is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name       | Type                                  | Mandatory| Description                                                                                  |
  | ------------- | -------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code          | number                                 | Yes  | Message code called by the request, which is determined by the client and server. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
  | data          | [MessageParcel](#messageparceldeprecated)        | Yes  | **MessageParcel** object holding the data to send.                                             |
  | reply         | [MessageParcel](#messageparceldeprecated)        | Yes  | **MessageParcel** object that receives the response.                                                     |
  | options       | [MessageOption](#messageoption)        | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |
  | AsyncCallback | AsyncCallback&lt;SendRequestResult&gt; | Yes  | Callback for receiving the sending result.                                                                  |

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

>This API is no longer maintained since API version 9. You are advised to use [onRemoteMessageRequest](#onremotemessagerequest9).

onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

Provides a response to **sendMessageRequest()**. The server processes the request and returns a response in this API.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type                           | Mandatory| Description                                   |
  | ------ | ------------------------------- | ---- | --------------------------------------- |
  | code   | number                          | Yes  | Service request code sent by the remote end.                 |
  | data   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that holds the parameters called by the client.|
  | reply  | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object carrying the result.          |
  | option | [MessageOption](#messageoption) | Yes  | Whether the operation is synchronous or asynchronous.               |

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
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

### onRemoteMessageRequest<sup>9+</sup>

onRemoteMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): boolean | Promise\<boolean>

> **NOTE**<br/>
>
>* You are advised to overload **onRemoteMessageRequest** preferentially, which implements synchronous and asynchronous message processing.
>* If both onRemoteRequest() and onRemoteMessageRequest() are overloaded, only the onRemoteMessageRequest() takes effect.

Provides a response to **sendMessageRequest()**. The server processes the request synchronously or asynchronously and returns the result in this API.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type                           | Mandatory| Description                                     |
  | ------ | ------------------------------- | ---- | ----------------------------------------- |
  | code   | number                          | Yes  | Service request code sent by the remote end.                   |
  | data   | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that holds the parameters called by the client.|
  | reply  | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object to which the result is written.          |
  | option | [MessageOption](#messageoption) | Yes  | Whether the operation is synchronous or asynchronous.                 |

**Return value**

  | Type             | Description                                                                                          |
  | ----------------- | ---------------------------------------------------------------------------------------------- |
  | boolean           | Returns a Boolean value if the request is processed synchronously in **onRemoteMessageRequest**. If the operation is successful, **true** is returned. Otherwise, **false** is returned.|
  | Promise\<boolean> | Returns a promise object if the request is processed asynchronously in **onRemoteMessageRequest**.                                |

**Example**: Overload **onRemoteMessageRequest** to process requests synchronously.

  ```ets
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }

      onRemoteMessageRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: sync onRemoteMessageRequest is called");
              return true;
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
      }
  }
  ```

  **Example**: Overload **onRemoteMessageRequest** to process requests asynchronously.

  ```ets
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }

      async onRemoteMessageRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: async onRemoteMessageRequest is called");
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

**Example**: Overload **onRemoteMessageRequest** and **onRemoteRequest** to process requests synchronously.

  ```ets
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }

      onRemoteRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: sync onRemoteMessageRequest is called");
              return true;
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
      }
      // Only onRemoteMessageRequest is executed.
      onRemoteMessageRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: async onRemoteMessageRequest is called");
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
         
          return true;
      }
  }
  ```

  **Example**: Overload **onRemoteMessageRequest** and **onRemoteRequest** to process requests asynchronously.

  ```ets
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }

      onRemoteRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: sync onRemoteRequest is called");
              return true;
          } else {
              console.log("RpcServer: unknown code: " + code);
              return false;
          }
      }
      // Only onRemoteMessageRequest is executed.
      async onRemoteMessageRequest(code, data, reply, option) {
          if (code === 1) {
              console.log("RpcServer: async onRemoteMessageRequest is called");
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
  | Type  | Description                   |
  | ------ | ----------------------- |
  | number | UID of the remote process obtained.|

**Example**

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

Obtains the PID of the remote process.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description                   |
  | ------ | ----------------------- |
  | number | PID of the remote process obtained.|

**Example**

  ```
  class TestRemoteObject extends rpc.RemoteObject {
      constructor(descriptor) {
          super(descriptor);
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  console.log("RpcServer: getCallingPid: " + testRemoteObject.getCallingPid());
  ```

### getLocalInterface<sup>9+</sup>

getLocalInterface(descriptor: string): IRemoteBroker

Obtains the interface.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name    | Type  | Mandatory| Description                |
  | ---------- | ------ | ---- | -------------------- |
  | descriptor | string | Yes  | Interface descriptor.|

**Return value**

  | Type         | Description                                         |
  | ------------- | --------------------------------------------- |
  | IRemoteBroker | **IRemoteBroker** object bound to the specified interface token.|


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
      registerDeathRecipient(recipient: MyDeathRecipient, flags: number);
      unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number);
      isObjectDead(): boolean {
          return false;
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  try {
      let broker = testRemoteObject.getLocalInterface("testObject");
  } catch(error) {
      console.info(rpc get local interface fail, errorCode " + error.code);
      console.info(rpc get local interface fail, errorMessage " + error.message);
  }
  ```


### queryLocalInterface<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [getLocalInterface](#getlocalinterface9).

queryLocalInterface(descriptor: string): IRemoteBroker

Checks whether the remote object corresponding to the specified interface token exists.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name    | Type  | Mandatory| Description                  |
  | ---------- | ------ | ---- | ---------------------- |
  | descriptor | string | Yes  | Interface descriptor.|

**Return value**

  | Type         | Description                                                              |
  | ------------- | ------------------------------------------------------------------ |
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


### getDescriptor<sup>9+</sup>

getDescriptor(): string

Obtains the interface descriptor of this object. The interface descriptor is a string.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description            |
  | ------ | ---------------- |
  | string | Interface descriptor obtained.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |

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
      addDeathRecipient(recipient: MyDeathRecipient, flags: number);
      unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number);
      isObjectDead(): boolean {
          return false;
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  try {
      let descriptor = testRemoteObject.getDescriptor();
  } catch(error) {
      console.info(rpc get local interface fail, errorCode " + error.code);
      console.info(rpc get local interface fail, errorMessage " + error.message);
  }
  console.log("RpcServer: descriptor is: " + descriptor);
  ```


### getInterfaceDescriptor<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [getDescriptor](#getdescriptor9).

getInterfaceDescriptor(): string

Obtains the interface descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description            |
  | ------ | ---------------- |
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


### modifyLocalInterface<sup>9+</sup>

modifyLocalInterface(localInterface: IRemoteBroker, descriptor: string): void

Binds an interface descriptor to an **IRemoteBroker** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name        | Type         | Mandatory| Description                                 |
  | -------------- | ------------- | ---- | ------------------------------------- |
  | localInterface | IRemoteBroker | Yes  | **IRemoteBroker** object.  |
  | descriptor     | string        | Yes  | Interface descriptor.|


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
          try {
              this.modifyLocalInterface(this, descriptor);
          } catch(error) {
              console.info(rpc attach local interface fail, errorCode " + error.code);
              console.info(rpc attach local interface fail, errorMessage " + error.message);
          }
      }
      registerDeathRecipient(recipient: MyDeathRecipient, flags: number);
      unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number);
      isObjectDead(): boolean {
          return false;
      }
      asObject(): rpc.IRemoteObject {
          return this;
      }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  ```

### attachLocalInterface<sup>(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [modifyLocalInterface](#modifylocalinterface9).

attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void

Binds an interface descriptor to an **IRemoteBroker** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name        | Type         | Mandatory| Description                                 |
  | -------------- | ------------- | ---- | ------------------------------------- |
  | localInterface | IRemoteBroker | Yes  | **IRemoteBroker** object.  |
  | descriptor     | string        | Yes  | Interface descriptor.|

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

  | Name      | Value | Description              |
  | ---------- | --- | ------------------ |
  | PROT_EXEC  | 4   | The mapped memory is executable.  |
  | PROT_NONE  | 0   | The mapped memory is inaccessible.|
  | PROT_READ  | 1   | The mapped memory is readable.    |
  | PROT_WRITE | 2   | The mapped memory is writeable.    |


### create<sup>9+</sup>

static create(name: string, size: number): Ashmem

Creates an **Ashmem** object with the specified name and size.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ------ | ------ | ---- | ---------------------------- |
  | name   | string | Yes  | Name of the **Ashmem** object to create.  |
  | size   | number | Yes  | Size (in bytes) of the **Ashmem** object to create.|

**Return value**

  | Type  | Description                                          |
  | ------ | ---------------------------------------------- |
  | Ashmem | Returns the **Ashmem** object if it is created successfully; returns null otherwise.|


**Example**

  ```
  let ashmem;
  try {
      ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  } catch(error) {
      console.info("Rpc creat ashmem fail, errorCode " + error.code);
      console.info("Rpc creat ashmem  fail, errorMessage " + error.message);
  }
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashemm by create : " + ashmem + " size is : " + size);
  ```


### createAshmem<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [create](#create9).

static createAshmem(name: string, size: number): Ashmem

Creates an **Ashmem** object with the specified name and size.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                        |
  | ------ | ------ | ---- | ---------------------------- |
  | name   | string | Yes  | Name of the **Ashmem** object to create.  |
  | size   | number | Yes  | Size (in bytes) of the **Ashmem** object to create.|

**Return value**

  | Type  | Description                                          |
  | ------ | ---------------------------------------------- |
  | Ashmem | Returns the **Ashmem** object if it is created successfully; returns null otherwise.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashemm by createAshmem : " + ashmem + " size is : " + size);
  ```


### create<sup>9+</sup>

static create(ashmem: Ashmem): Ashmem

Creates an **Ashmem** object by copying the file descriptor (FD) of an existing Ashmem object. The two **Ashmem** objects point to the same shared memory region.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                |
  | ------ | ------ | ---- | -------------------- |
  | ashmem | Ashmem | Yes  | Existing **Ashmem** object.|

**Return value**

  | Type  | Description                  |
  | ------ | ---------------------- |
  | Ashmem | **Ashmem** object created.|


**Example**

  ```
  let ashmem2;
  try {
      let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
      let ashmem2 = rpc.Ashmem.create(ashmem);
  } catch(error) {
      console.info("Rpc creat ashmem from existing fail, errorCode " + error.code);
      console.info("Rpc creat ashmem from existing  fail, errorMessage " + error.message);
  }
  let size = ashmem2.getAshmemSize();
  console.log("RpcTest: get ashemm by create : " + ashmem2 + " size is : " + size);
  ```


### createAshmemFromExisting<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [create](#create9).

static createAshmemFromExisting(ashmem: Ashmem): Ashmem

Creates an **Ashmem** object by copying the file descriptor (FD) of an existing Ashmem object. The two **Ashmem** objects point to the same shared memory region.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                |
  | ------ | ------ | ---- | -------------------- |
  | ashmem | Ashmem | Yes  | Existing **Ashmem** object.|

**Return value**

  | Type  | Description                  |
  | ------ | ---------------------- |
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
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.closeAshmem();
  ```


### unmapAshmem<sup>8+</sup>

unmapAshmem(): void

Deletes the mappings for the specified address range of this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.unmapAshmem();
  ```


### getAshmemSize<sup>8+</sup>

getAshmemSize(): number

Obtains the memory size of this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type  | Description                      |
  | ------ | -------------------------- |
  | number | **Ashmem** size obtained.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashmem is " + ashmem + " size is : " + size);
  ```


### mapTypedAshmem<sup>9+</sup>

mapTypedAshmem(mapType: number): void

Creates the shared file mapping on the virtual address space of this process. The size of the mapping region is specified by this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type  | Mandatory| Description                          |
  | ------- | ------ | ---- | ------------------------------ |
  | mapType | number | Yes  | Protection level of the memory region to which the shared file is mapped.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | ------ |
  | 1900001     | call mmap function failed |

**Example**

  ```
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  try {
      ashmem.mapTypedAshmem(ashmem.PROT_READ | ashmem.PROT_WRITE);
  } catch(error) {
      console.info("Rpc map ashmem fail, errorCode " + error.code);
      console.info("Rpc map ashmem fail, errorMessage " + error.message);
  }
  ```


### mapAshmem<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [mapTypedAshmem](#maptypedashmem9).

mapAshmem(mapType: number): boolean

Creates the shared file mapping on the virtual address space of this process. The size of the mapping region is specified by this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name | Type  | Mandatory| Description                          |
  | ------- | ------ | ---- | ------------------------------ |
  | mapType | number | Yes  | Protection level of the memory region to which the shared file is mapped.|

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapReadAndWrite = ashmem.mapAshmem(ashmem.PROT_READ | ashmem.PROT_WRITE);
  console.log("RpcTest: map ashmem result is  : " + mapReadAndWrite);
  ```


### mapReadWriteAshmem<sup>9+</sup>

mapReadWriteAshmem(): void

Maps the shared file to the readable and writable virtual address space of the process.

**System capability**: SystemCapability.Communication.IPC.Core

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900001 | call mmap function failed |

**Example**

  ```
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  try {
      ashmem.mapReadWriteAshmem();
  } catch(error) {
      console.info("Rpc map read and write ashmem fail, errorCode " + error.code);
      console.info("Rpc map read and write ashmem fail, errorMessage " + error.message);
  }
  ```


### mapReadAndWriteAshmem<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [mapReadWriteAshmem](#mapreadwriteashmem9).

mapReadAndWriteAshmem(): boolean

Maps the shared file to the readable and writable virtual address space of the process.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadAndWriteAshmem();
  console.log("RpcTest: map ashmem result is  : " + mapResult);
  ```


### mapReadonlyAshmem<sup>9+</sup>

mapReadonlyAshmem(): void

Maps the shared file to the read-only virtual address space of the process.

**System capability**: SystemCapability.Communication.IPC.Core

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900001 | call mmap function failed |

**Example**

  ```
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  try {
      ashmem.mapReadonlyAshmem();
  } catch(error) {
      console.info("Rpc map read and write ashmem fail, errorCode " + error.code);
      console.info("Rpc map read and write ashmem fail, errorMessage " + error.message);
  }
  ```


### mapReadOnlyAshmem<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [mapReadonlyAshmem](#mapreadonlyashmem9).

mapReadOnlyAshmem(): boolean

Maps the shared file to the read-only virtual address space of the process.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadOnlyAshmem();
  console.log("RpcTest: Ashmem mapReadOnlyAshmem result is : " + mapResult);
  ```


### setProtectionType<sup>9+</sup>

setProtectionType(protectionType: number): void

Sets the protection level of the memory region to which the shared file is mapped.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name        | Type  | Mandatory| Description              |
  | -------------- | ------ | ---- | ------------------ |
  | protectionType | number | Yes  | Protection type to set.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | -------- | ------- |
  | 1900002 | call os ioctl function failed |

**Example**

  ```
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  try {
      ashmem.setProtection(ashmem.PROT_READ);
  } catch(error) {
      console.info("Rpc set protection type fail, errorCode " + error.code);
      console.info("Rpc set protection type fail, errorMessage " + error.message);
  }
  ```


### setProtection<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [setProtectionType](#setprotectiontype9).

setProtection(protectionType: number): boolean

Sets the protection level of the memory region to which the shared file is mapped.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name        | Type  | Mandatory| Description              |
  | -------------- | ------ | ---- | ------------------ |
  | protectionType | number | Yes  | Protection type to set.|

**Return value**

  | Type   | Description                                     |
  | ------- | ----------------------------------------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let result = ashmem.setProtection(ashmem.PROT_READ);
  console.log("RpcTest: Ashmem setProtection result is : " + result);
  ```


### writeAshmem<sup>9+</sup>

writeAshmem(buf: number[], size: number, offset: number): void

Writes data to the shared file associated with this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                                              |
  | ------ | -------- | ---- | -------------------------------------------------- |
  | buf    | number[] | Yes  | Data to write.                            |
  | size   | number   | Yes  | Size of the data to write.                                |
  | offset | number   | Yes  | Start position of the data to write in the memory region associated with this **Ashmem** object.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID| Error Message|
  | ------- | -------- |
  | 1900003 | write to ashmem failed |

**Example**

  ```
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.mapReadWriteAshmem();
  var ByteArrayVar = [1, 2, 3, 4, 5];
  try {
      ashmem.writeAshmem(ByteArrayVar, 5, 0);
  } catch(error) {
      console.info("Rpc write to ashmem fail, errorCode " + error.code);
      console.info("Rpc write to ashmem fail, errorMessage " + error.message);
  }
  ```


### writeToAshmem<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [writeAshmem](#writeashmem9).

writeToAshmem(buf: number[], size: number, offset: number): boolean

Writes data to the shared file associated with this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type    | Mandatory| Description                                              |
  | ------ | -------- | ---- | -------------------------------------------------- |
  | buf    | number[] | Yes  | Data to write.                            |
  | size   | number   | Yes  | Size of the data to write.                                |
  | offset | number   | Yes  | Start position of the data to write in the memory region associated with this **Ashmem** object.|

**Return value**

  | Type   | Description                                                                                     |
  | ------- | ----------------------------------------------------------------------------------------- |
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


### readAshmem<sup>9+</sup>

readAshmem(size: number, offset: number): number[]

Reads data from the shared file associated with this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                                              |
  | ------ | ------ | ---- | -------------------------------------------------- |
  | size   | number | Yes  | Size of the data to read.                              |
  | offset | number | Yes  | Start position of the data to read in the memory region associated with this **Ashmem** object.|

**Return value**

  | Type    | Description            |
  | -------- | ---------------- |
  | number[] | Data read.|

**Error Code**

For details about the error codes, see [RPC Error Codes](../errorcodes/errorcode-rpc.md).

  | ID | Error Message|
  | -------- | -------- |
  | 1900004 | read from ashmem failed |

**Example**

  ```
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.mapReadWriteAshmem();
  var ByteArrayVar = [1, 2, 3, 4, 5];
  ashmem.writeAshmem(ByteArrayVar, 5, 0);
  try {
      let readResult = ashmem.readAshmem(5, 0);
      console.log("RpcTest: read from Ashmem result is  : " + readResult);
  } catch(error) {
      console.info("Rpc read from ashmem fail, errorCode " + error.code);
      console.info("Rpc read from ashmem fail, errorMessage " + error.message);
  }
  ```


### readFromAshmem<sup>8+(deprecated)</sup>

>This API is no longer maintained since API version 9. You are advised to use [readAshmem](#readashmem9).

readFromAshmem(size: number, offset: number): number[]

Reads data from the shared file associated with this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

  | Name| Type  | Mandatory| Description                                              |
  | ------ | ------ | ---- | -------------------------------------------------- |
  | size   | number | Yes  | Size of the data to read.                              |
  | offset | number | Yes  | Start position of the data to read in the memory region associated with this **Ashmem** object.|

**Return value**

  | Type    | Description            |
  | -------- | ---------------- |
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
