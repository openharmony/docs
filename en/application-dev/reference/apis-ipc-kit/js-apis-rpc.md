# @ohos.rpc (RPC)

The **RPC** module implements communication between processes, including inter-process communication (IPC) on a single device and remote procedure call (RPC) between processes on difference devices. IPC is implemented based on the Binder driver, and RPC is based on the DSoftBus driver.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This module supports return of error codes since API version 9.

## Modules to Import

```
import { rpc } from '@kit.IPCKit';
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


## TypeCode<sup>12+</sup>

Since API version 12, [writeArrayBuffer](#writearraybuffer12) and [readArrayBuffer](#readarraybuffer12) are added to pass ArrayBuffer data. The specific TypedArray type is determined by **TypeCode** defined as follows:

**System capability**: SystemCapability.Communication.IPC.Core

| Name                        | Value    | Description                                         |
| ---------------------------- | ------ | --------------------------------------------  |
| INT8_ARRAY                   | 0      | The TypedArray type is **INT8_ARRAY**.                 |
| UINT8_ARRAY                  | 1      | The TypedArray type is **UINT8_ARRAY**.                |
| INT16_ARRAY                  | 2      | The TypedArray type is **INT16_ARRAY**.                |
| UINT16_ARRAY                 | 3      | The TypedArray type is **UINT16_ARRAY**.               |
| INT32_ARRAY                  | 4      | The TypedArray type is **INT32_ARRAY**.                |
| UINT32_ARRAY                 | 5      | The TypedArray type is **UINT32_ARRAY**.               |
| FLOAT32_ARRAY                | 6      | The TypedArray type is **FLOAT32_ARRAY**.              |
| FLOAT64_ARRAY                | 7      | The TypedArray type is **FLOAT64_ARRAY**.              |
| BIGINT64_ARRAY               | 8      | The TypedArray type is **BIGINT64_ARRAY**.             |
| BIGUINT64_ARRAY              | 9      | The TypedArray type is **BIGUINT64_ARRAY**.            |


## MessageSequence<sup>9+</sup>

Provides APIs for reading and writing data in specific format. During RPC or IPC, the sender can use the **write()** method provided by **MessageSequence** to write data in specific format to a **MessageSequence** object. The receiver can use the **read()** method provided by **MessageSequence** to read data in specific format from a **MessageSequence** object. The data formats include basic data types and arrays, IPC objects, interface tokens, and custom sequenceable objects.

### create

static create(): MessageSequence

Creates a **MessageSequence** object. This API is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| [MessageSequence](#messagesequence9) | **MessageSequence** object created.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageSequence.create();
  hilog.info(0x0000, 'testTag', 'RpcClient: data is ' + data);
  ```

### reclaim

reclaim(): void

Reclaims the **MessageSequence** object that is no longer used.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```ts
  let reply = rpc.MessageSequence.create();
  reply.reclaim();
  ```

### writeRemoteObject

writeRemoteObject(object: IRemoteObject): void

Serializes a remote object and writes it to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type                           | Mandatory| Description                                     |
| ------ | ------------------------------- | ---- | ----------------------------------------- |
| object | [IRemoteObject](#iremoteobject) | Yes  | Remote object to serialize and write to the **MessageSequence** object.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900008  | The proxy or remote object is invalid. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
  }
  let data = rpc.MessageSequence.create();
  let testRemoteObject = new TestRemoteObject("testObject");
  try {
    data.writeRemoteObject(testRemoteObject);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc write remote object fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc write remote object fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900008  | The proxy or remote object is invalid. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
  }
  let data = rpc.MessageSequence.create();
  let testRemoteObject = new TestRemoteObject("testObject");
  try {
    data.writeRemoteObject(testRemoteObject);
    let proxy = data.readRemoteObject();
    hilog.info(0x0000, 'testTag', 'RpcClient: readRemoteObject is ' + proxy);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc write remote object fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc write remote object fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes:<br> 1.The number of parameters is incorrect;<br> 2.The parameter type does not match;<br> 3.The string length exceeds 40960 bytes;<br> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeInterfaceToken("aaa");
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write interface fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write interface fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

class Stub extends rpc.RemoteObject {
  onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
    try {
      let interfaceToken = data.readInterfaceToken();
      hilog.info(0x0000, 'testTag', 'RpcServer: interfaceToken is ' + interfaceToken);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'RpcServer: read interfaceToken failed, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'RpcServer: read interfaceToken failed, errorMessage ' + e.message);
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
| number | Size of the **MessageSequence** instance obtained, in bytes.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageSequence.create();
  let size = data.getSize();
  hilog.info(0x0000, 'testTag', 'RpcClient: size is ' + size);
  ```

### getCapacity

getCapacity(): number

Obtains the capacity of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description |
| ------ | ----- |
| number | Capacity of the obtained **MessageSequence** object, in bytes.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageSequence.create();
  let result = data.getCapacity();
  hilog.info(0x0000, 'testTag', 'RpcClient: capacity is ' + result);
  ```

### setSize

setSize(size: number): void

Sets the size of the data contained in this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description  |
| ------ | ------ | ---- | ------ |
| size   | number | Yes  | Data size to set, in bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  data.writeString('Hello World');
  try {
    data.setSize(16);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc set size of MessageSequence fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc set size of MessageSequence fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900011  | Memory allocation failed |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.setCapacity(100);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc memory alloc fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc memory alloc fail, errorMessage ' + e.message);
  }
  ```

### getWritableBytes

getWritableBytes(): number

Obtains the writable capacity (in bytes) of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description  |
| ------ | ------ |
| number | Writable capacity of the **MessageSequence** instance, in bytes.|

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

class Stub extends rpc.RemoteObject {
  onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
    let getWritableBytes = data.getWritableBytes();
    hilog.info(0x0000, 'testTag', 'RpcServer: getWritableBytes is ' + getWritableBytes);
    return true;
  }
}
```

### getReadableBytes

getReadableBytes(): number

Obtains the readable capacity of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description   |
| ------ | ------- |
| number | Readable capacity of the **MessageSequence** instance, in bytes.|

**Example**

```ts
import { hilog } from '@kit.PerformanceAnalysisKit';

class Stub extends rpc.RemoteObject {
  onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
    let result = data.getReadableBytes();
    hilog.info(0x0000, 'testTag', 'RpcServer: getReadableBytes is ' + result);
    return true;
  }
}
```

### getReadPosition

getReadPosition(): number

Obtains the read position of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description  |
| ------ | ------ |
| number | Read position obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageSequence.create();
  let readPos = data.getReadPosition();
  hilog.info(0x0000, 'testTag', 'RpcClient: readPos is ' + readPos);
  ```

### getWritePosition

getWritePosition(): number

Obtains the write position of this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description |
| ------ | ----- |
| number | Write position obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageSequence.create();
  data.writeInt(10);
  let bwPos = data.getWritePosition();
  hilog.info(0x0000, 'testTag', 'RpcClient: bwPos is ' + bwPos);
  ```

### rewindRead

rewindRead(pos: number): void

Moves the read pointer to the specified position.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| pos    | number | Yes  | Position from which data is to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  data.writeInt(12);
  data.writeString("sequence");
  let number = data.readInt();
  hilog.info(0x0000, 'testTag', 'RpcClient: number is ' + number);
  try {
    data.rewindRead(0);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc rewind read data fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc rewind read data fail, errorMessage ' + e.message);
  }
  let number2 = data.readInt();
  hilog.info(0x0000, 'testTag', 'RpcClient: rewindRead is ' + number2);
  ```

### rewindWrite

rewindWrite(pos: number): void

Moves the write pointer to the specified position.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ------ | ---- | ----- |
| pos    | number | Yes  | Position from which data is to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  data.writeInt(4);
  try {
    data.rewindWrite(0);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc rewindWrite fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc rewindWrite fail, errorMessage ' + e.message);
  }
  data.writeInt(5);
  let number = data.readInt();
  hilog.info(0x0000, 'testTag', 'RpcClient: rewindWrite is: ' + number);
  ```

### writeByte

writeByte(val: number): void

Writes a byte value to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ------ | ---- | ----- |
| val    | number | Yes  | Byte value to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------  |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeByte(2);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write byte fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write byte fail, errorMessage ' + e.message);
  }
  ```

### readByte

readByte(): number

Reads the byte value from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description |
| ------ | ----- |
| number | Byte value read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| ------- | --------  |
| 1900010 | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeByte(2);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write byte fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write byte fail, errorMessage ' + e.message);
  }
  try {
    let ret = data.readByte();
    hilog.info(0x0000, 'testTag', 'RpcClient: readByte is: ' +  ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read byte fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read byte fail, errorMessage ' + e.message);
  }
  ```

### writeShort

writeShort(val: number): void

Writes a short integer to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description|
| ------ | ------ | ---  | ---  |
| val    | number | Yes  | Short integer to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeShort(8);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write short fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write short fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeShort(8);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write short fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write short fail, errorMessage ' + e.message);
  }
  try {
    let ret = data.readShort();
    hilog.info(0x0000, 'testTag', 'RpcClient: readByte is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read short fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read short fail, errorMessage ' + e.message);
  }
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeInt(10);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write int fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write int fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeInt(10);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write int fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write int fail, errorMessage ' + e.message);
  }
  try {
    let ret = data.readInt();
    hilog.info(0x0000, 'testTag', 'RpcClient: readInt is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read int fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read int fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeLong(10000);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write long fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write long fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeLong(10000);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write long fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write long fail, errorMessage ' + e.message);
  }
  try {
    let ret = data.readLong();
    hilog.info(0x0000, 'testTag', 'RpcClient: readLong is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read long fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read long fail, errorMessage ' + e.message);
  }
  ```

### writeFloat

writeFloat(val: number): void

Writes a floating-point number to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description |
| ------ | ------ | ---- | ----- |
| val    | number | Yes  | Floating-point number to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeFloat(1.2);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write float fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write float fail, errorMessage ' + e.message);
  }
  ```

### readFloat

readFloat(): number

Reads the floating-point number from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description        |
| ------ | ------------ |
| number | Floating-point number read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeFloat(1.2);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write float fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write float fail, errorMessage ' + e.message);
  }
  try {
    let ret = data.readFloat();
    hilog.info(0x0000, 'testTag', 'RpcClient: readFloat is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read float fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read float fail, errorMessage ' + e.message);
  }
  ```

### writeDouble

writeDouble(val: number): void

Writes a double-precision floating-point number to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| val    | number | Yes  | Double-precision floating-point number to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeDouble(10.2);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write double fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write double fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeDouble(10.2);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write double fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write double fail, errorMessage ' + e.message);
  }
  try {
    let ret = data.readDouble();
    hilog.info(0x0000, 'testTag', 'RpcClient: readDouble is ' +  ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read double fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read double fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeBoolean(false);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write boolean fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write boolean fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeBoolean(false);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write boolean fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write boolean fail, errorMessage ' + e.message);
  }
  try {
    let ret = data.readBoolean();
    hilog.info(0x0000, 'testTag', 'RpcClient: readBoolean is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read boolean fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read boolean fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeChar(97);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write char fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write char fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeChar(97);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write char fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write char fail, errorMessage ' + e.message);
  }
  try {
    let ret = data.readChar();
    hilog.info(0x0000, 'testTag', 'RpcClient: readChar is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read char fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read char fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The string length exceeds 40960 bytes; <br> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeString('abc');
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write string fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write string fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeString('abc');
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write string fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write string fail, errorMessage ' + e.message);
  }
  try {
    let ret = data.readString();
    hilog.info(0x0000, 'testTag', 'RpcClient: readString is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read string fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read string fail, errorMessage ' + e.message);
  }
  ```

### writeParcelable

writeParcelable(val: Parcelable): void

Writes a **Parcelable** object to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | --------- | ---- | ------ |
| val    | [Parcelable](#parcelable9) | Yes  | **Parcelable** object to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyParcelable implements rpc.Parcelable {
    num: number = 0;
    str: string = '';
    constructor( num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageSequence: rpc.MessageSequence): boolean {
      messageSequence.writeInt(this.num);
      messageSequence.writeString(this.str);
      return true;
    }
    unmarshalling(messageSequence: rpc.MessageSequence): boolean {
      this.num = messageSequence.readInt();
      this.str = messageSequence.readString();
      return true;
    }
  }
  let parcelable = new MyParcelable(1, "aaa");
  let data = rpc.MessageSequence.create();
  try {
    data.writeParcelable(parcelable);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write parcelable fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write parcelable fail, errorMessage ' + e.message);
  }
  ```

### readParcelable

readParcelable(dataIn: Parcelable): void

Reads a **Parcelable** object from this **MessageSequence** object to the specified object (**dataIn**).

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type                      | Mandatory| Description                                     |
| ------ | -------------------------- | ---- | ----------------------------------------- |
| dataIn | [Parcelable](#parcelable9) | Yes  | **Parcelable** object to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect. |
| 1900010  | Failed to read data from the message sequence. |
| 1900012  | Failed to call the JS callback function. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyParcelable implements rpc.Parcelable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageSequence: rpc.MessageSequence): boolean {
      messageSequence.writeInt(this.num);
      messageSequence.writeString(this.str);
      return true;
    }
    unmarshalling(messageSequence: rpc.MessageSequence): boolean {
      this.num = messageSequence.readInt();
      this.str = messageSequence.readString();
      return true;
    }
  }
  let parcelable = new MyParcelable(1, "aaa");
  let data = rpc.MessageSequence.create();
  data.writeParcelable(parcelable);
  let ret = new MyParcelable(0, "");
  try {
    data.readParcelable(ret);
  }catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read parcelable fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read parcelable fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The element does not exist in the array. <br> 5.The type of the element in the array is incorrect. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  try {
    data.writeByteArray(ByteArrayVar);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  try {
    data.writeByteArray(ByteArrayVar);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorMessage ' + e.message);
  }
  try {
    let array: Array<number> = new Array(5);
    data.readByteArray(array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read byteArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read byteArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | check param failed |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  let byteArrayVar = [1, 2, 3, 4, 5];
  try {
    data.writeByteArray(byteArrayVar);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorMessage ' + e.message);
  }
  try {
    let array = data.readByteArray();
    hilog.info(0x0000, 'testTag', 'RpcClient: readByteArray is ' +  array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read byteArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read byteArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The element does not exist in the array; <br> 5.The type of the element in the array is incorrect. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeShortArray([11, 12, 13]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeShortArray([11, 12, 13]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorMessage ' + e.message);
  }
  try {
    let array: Array<number> = new Array(3);
    data.readShortArray(array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read shortArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read shortArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeShortArray([11, 12, 13]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorMessage ' + e.message);
  }
  try {
    let array = data.readShortArray();
    hilog.info(0x0000, 'testTag', 'RpcClient: readShortArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read shortArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read shortArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The element does not exist in the array; <br> 5.The type of the element in the array is incorrect. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeIntArray([100, 111, 112]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeIntArray([100, 111, 112]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorMessage ' + e.message);
  }
  let array: Array<number> = new Array(3);
  try {
    data.readIntArray(array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read intArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read intArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeIntArray([100, 111, 112]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorMessage ' + e.message);
  }
  try {
    let array = data.readIntArray();
    hilog.info(0x0000, 'testTag', 'RpcClient: readIntArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read intArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read intArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The element does not exist in the array; <br> 5.The type of the element in the array is incorrect. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeLongArray([1111, 1112, 1113]);
  }catch (error){
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeLongArray([1111, 1112, 1113]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorMessage ' + e.message);
  }
  let array: Array<number> = new Array(3);
  try {
    data.readLongArray(array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read longArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read longArray fail, errorMessage ' + e.message);
  }
  ```

### readLongArray

readLongArray(): number[]

Reads the long integer array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type    | Description            |
| -------- | ---------------- |
| number[] | Long array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeLongArray([1111, 1112, 1113]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorMessage ' + e.message);
  }
  try {
    let array = data.readLongArray();
    hilog.info(0x0000, 'testTag', 'RpcClient: readLongArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read longArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read longArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The element does not exist in the array; <br> 5.The type of the element in the array is incorrect. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeFloatArray([1.2, 1.3, 1.4]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeFloatArray([1.2, 1.3, 1.4]);
  }catch (error){
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorMessage ' + e.message);
  }
  let array: Array<number> = new Array(3);
  try {
    data.readFloatArray(array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read floatArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read floatArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeFloatArray([1.2, 1.3, 1.4]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorMessage ' + e.message);
  }
  try {
    let array = data.readFloatArray();
    hilog.info(0x0000, 'testTag', 'RpcClient: readFloatArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read floatArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read floatArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The element does not exist in the array; <br> 5.The type of the element in the array is incorrect. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeDoubleArray([11.1, 12.2, 13.3]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeDoubleArray([11.1, 12.2, 13.3]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorMessage ' + e.message);
  }
  let array: Array<number> = new Array(3);
  try {
    data.readDoubleArray(array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read doubleArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read doubleArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeDoubleArray([11.1, 12.2, 13.3]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorMessage ' + e.message);
  }
  try {
    let array = data.readDoubleArray();
    hilog.info(0x0000, 'testTag', 'RpcClient: readDoubleArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read doubleArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read doubleArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The element does not exist in the array. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeBooleanArray([false, true, false]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeBooleanArray([false, true, false]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorMessage ' + e.message);
  }
  let array: Array<boolean> = new Array(3);
  try {
    data.readBooleanArray(array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read booleanArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read booleanArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeBooleanArray([false, true, false]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorMessage ' + e.message);
  }
  try {
    let array = data.readBooleanArray();
    hilog.info(0x0000, 'testTag', 'RpcClient: readBooleanArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read booleanArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read booleanArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The element does not exist in the array. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeCharArray([97, 98, 88]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeCharArray([97, 98, 88]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorMessage ' + e.message);
  }
  let array: Array<number> = new Array(3);
  try {
    data.readCharArray(array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read charArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read charArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeCharArray([97, 98, 88]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorMessage ' + e.message);
  }
  try {
    let array = data.readCharArray();
    hilog.info(0x0000, 'testTag', 'RpcClient: readCharArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read charArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read charArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The string length exceeds 40960 bytes; <br> 5.The number of bytes copied to the buffer is different from the length of the obtained string. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeStringArray(["abc", "def"]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeStringArray(["abc", "def"]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorMessage ' + e.message);
  }
  let array: Array<string> = new Array(2);
  try {
    data.readStringArray(array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read stringArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read stringArray fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let data = rpc.MessageSequence.create();
  try {
    data.writeStringArray(["abc", "def"]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorMessage ' + e.message);
  }
  try {
    let array = data.readStringArray();
    hilog.info(0x0000, 'testTag', 'RpcClient: readStringArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read stringArray fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read stringArray fail, errorMessage ' + e.message);
  }
  ```

### writeNoException

writeNoException(): void

Writes information to this **MessageSequence** object indicating that no exception occurred.

**System capability**: SystemCapability.Communication.IPC.Core

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      if (code === 1) {
        hilog.info(0x0000, 'testTag', 'RpcServer: onRemoteMessageRequest called');
        try {
          reply.writeNoException();
        } catch (error) {
          let e: BusinessError = error as BusinessError;
          hilog.error(0x0000, 'testTag', 'rpc write no exception fail, errorCode ' + e.code);
          hilog.error(0x0000, 'testTag', 'rpc write no exception fail, errorMessage ' + e.message);
        }
        return true;
      } else {
        hilog.error(0x0000, 'testTag', 'RpcServer: unknown code: ' + code);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **sendMessageRequest()** of the proxy object is called to send a message.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let option = new rpc.MessageOption();
  let data = rpc.MessageSequence.create();
  let reply = rpc.MessageSequence.create();
  data.writeNoException();
  data.writeInt(6);
  if (proxy != undefined) {
    proxy.sendMessageRequest(1, data, reply, option)
      .then((result: rpc.RequestResult) => {
        if (result.errCode === 0) {
          hilog.info(0x0000, 'testTag', 'sendMessageRequest got result');
          try {
            result.reply.readException();
          } catch (error) {
            let e: BusinessError = error as BusinessError;
            hilog.error(0x0000, 'testTag', 'rpc read exception fail, errorCode ' + e.code);
            hilog.error(0x0000, 'testTag', 'rpc read exception fail, errorMessage ' + e.message);
          }
          let num = result.reply.readInt();
          hilog.info(0x0000, 'testTag', 'RPCTest: reply num: ' + num);
        } else {
          hilog.error(0x0000, 'testTag', 'RPCTest: sendMessageRequest failed, errCode: ' + result.errCode);
        }
      }).catch((e: Error) => {
        hilog.error(0x0000, 'testTag', 'RPCTest: sendMessageRequest got exception: ' + e.message);
      }).finally (() => {
        hilog.info(0x0000, 'testTag', 'RPCTest: sendMessageRequest ends, reclaim parcel');
        data.reclaim();
        reply.reclaim();
      });
  }
  ```

### writeParcelableArray

writeParcelableArray(parcelableArray: Parcelable[]): void

Writes a **Parcelable** array to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name         | Type        | Mandatory| Description                      |
| --------------- | ------------ | ---- | -------------------------- |
| parcelableArray | [Parcelable](#parcelable9)[] | Yes  | **Parcelable** array to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The element does not exist in the array. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyParcelable implements rpc.Parcelable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageSequence: rpc.MessageSequence): boolean {
      messageSequence.writeInt(this.num);
      messageSequence.writeString(this.str);
      return true;
    }
    unmarshalling(messageSequence: rpc.MessageSequence): boolean {
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
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write parcelable array fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write parcelable array fail, errorMessage ' + e.message);
  }
  ```

### readParcelableArray

readParcelableArray(parcelableArray: Parcelable[]): void

Reads a **Parcelable** array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name         | Type        | Mandatory| Description                      |
| --------------- | ------------ | ---- | -------------------------- |
| parcelableArray | [Parcelable](#parcelable9)[] | Yes  | **Parcelable** array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The length of the array passed when reading is not equal to the length passed when writing to the array; <br> 5.The element does not exist in the array. |
| 1900010  | Failed to read data from the message sequence. |
| 1900012  | Failed to call the JS callback function. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyParcelable implements rpc.Parcelable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageSequence: rpc.MessageSequence): boolean {
      messageSequence.writeInt(this.num);
      messageSequence.writeString(this.str);
      return true;
    }
    unmarshalling(messageSequence: rpc.MessageSequence): boolean {
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
  data.writeParcelableArray(a);
  let b = [new MyParcelable(0, ""), new MyParcelable(0, ""), new MyParcelable(0, "")];
  try {
    data.readParcelableArray(b);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read parcelable array fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read parcelable array fail, errorMessage ' + e.message);
  }
  ```

### writeRemoteObjectArray

writeRemoteObjectArray(objectArray: IRemoteObject[]): void

Writes an array of **IRemoteObject** objects to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name     | Type           | Mandatory| Description                                          |
| ----------- | --------------- | ---- | ---------------------------------------------- |
| objectArray | [IRemoteObject](#iremoteobject)[] | Yes  | Array of **IRemoteObject** objects to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The element does not exist in the array; <br> 5.The obtained remoteObject is null. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
      this.modifyLocalInterface(this, descriptor);
    }

    asObject(): rpc.IRemoteObject {
      return this;
    }
  }
  let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
  let data = rpc.MessageSequence.create();
  try {
    data.writeRemoteObjectArray(a);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write remote object array fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write remote object array fail, errorMessage ' + e.message);
  }
  ```

### readRemoteObjectArray

readRemoteObjectArray(objects: IRemoteObject[]): void

Reads an array of **IRemoteObject** objects from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type           | Mandatory| Description                                          |
| ------- | --------------- | ---- | ---------------------------------------------- |
| objects | [IRemoteObject](#iremoteobject)[] | Yes  | **IRemoteObject** array to read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The length of the array passed when reading is not equal to the length passed when writing to the array. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
  let b: Array<rpc.IRemoteObject> = new Array(3);
  try {
    data.readRemoteObjectArray(b);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read remote object array fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read remote object array fail, errorMessage ' + e.message);
  }
  ```

### readRemoteObjectArray

readRemoteObjectArray(): IRemoteObject[]

Reads the **IRemoteObject** object array from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type           | Description                       |
| --------------- | --------------------------- |
| [IRemoteObject](#iremoteobject)[] | **IRemoteObject** object array read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
    hilog.info(0x0000, 'testTag', 'RpcClient: readRemoteObjectArray is ' + b);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read remote object array fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read remote object array fail, errorMessage ' + e.message);
  }
  ```

### closeFileDescriptor

static closeFileDescriptor(fd: number): void

Closes a file descriptor. This API is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| fd     | number | Yes  | File descriptor to close.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |

**Example**

  ```ts
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = "path/to/file";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  try {
    rpc.MessageSequence.closeFileDescriptor(file.fd);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc close file descriptor fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc close file descriptor fail, errorMessage ' + e.message);
  }
  ```

### dupFileDescriptor

static dupFileDescriptor(fd: number): number

Duplicates a file descriptor. This API is a static method.

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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900013  | Failed to call dup. |

**Example**

  ```ts
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let filePath = "path/to/file";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  try {
    rpc.MessageSequence.dupFileDescriptor(file.fd);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc dup file descriptor fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc dup file descriptor fail, errorMessage ' + e.message);
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

  ```ts
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let sequence = new rpc.MessageSequence();
  let filePath = "path/to/file";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  try {
    sequence.writeFileDescriptor(file.fd);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorMessage ' + e.message);
  }
  try {
    let containFD = sequence.containFileDescriptors();
    hilog.info(0x0000, 'testTag', 'RpcTest: sequence after write fd containFd result is ' + containFD);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc contain file descriptor fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc contain file descriptor fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let sequence = new rpc.MessageSequence();
  let filePath = "path/to/file";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  try {
    sequence.writeFileDescriptor(file.fd);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorMessage ' + e.message);
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

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let sequence = new rpc.MessageSequence();
  let filePath = "path/to/file";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  try {
    sequence.writeFileDescriptor(file.fd);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorMessage ' + e.message);
  }
  try {
    let readFD = sequence.readFileDescriptor();
    hilog.info(0x0000, 'testTag', 'RpcClient: readFileDescriptor is ' + readFD);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read file descriptor fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read file descriptor fail, errorMessage ' + e.message);
  }
  ```

### writeAshmem

writeAshmem(ashmem: Ashmem): void

Writes an anonymous shared object to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description                                 |
| ------ | ------ | ---- | ------------------------------------- |
| ashmem | [Ashmem](#ashmem8) | Yes  | Anonymous shared object to write.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | ------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter is not an instance of the Ashmem object. |
| 1900003  | Failed to write data to the shared memory. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let sequence = new rpc.MessageSequence();
  let ashmem: rpc.Ashmem | undefined = undefined;
  try {
    ashmem = rpc.Ashmem.create("ashmem", 1024);
    try {
      sequence.writeAshmem(ashmem);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'rpc write ashmem fail, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'rpc write ashmem fail, errorMessage ' + e.message);
    }
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc create ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc create ashmem fail, errorMessage ' + e.message);
  }
  ```

### readAshmem

readAshmem(): Ashmem

Reads the anonymous shared object from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| [Ashmem](#ashmem8) | Anonymous share object obtained.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | check param failed |
| 1900004  | Failed to read data from the shared memory. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let sequence = new rpc.MessageSequence();
  let ashmem: rpc.Ashmem | undefined = undefined;
  try {
    ashmem = rpc.Ashmem.create("ashmem", 1024);
    try {
      sequence.writeAshmem(ashmem);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'rpc write ashmem fail, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'rpc write ashmem fail, errorMessage ' + e.message);
    }
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc create ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc create ashmem fail, errorMessage ' + e.message);
  }
  try {
    sequence.readAshmem();
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read ashmem fail, errorMessage ' + e.message);
  }
  ```

### getRawDataCapacity

getRawDataCapacity(): number

Obtains the maximum amount of raw data that can be held by this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Maximum amount of raw data that **MessageSequence** can hold, that is, 128 MB.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sequence = new rpc.MessageSequence();
  let result = sequence.getRawDataCapacity();
  hilog.info(0x0000, 'testTag', 'RpcTest: sequence get RawDataCapacity result is ' + result);
  ```

### writeRawData<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 11. Use [writeRawDataBuffer](#writerawdatabuffer11) instead.

writeRawData(rawData: number[], size: number): void

Writes raw data to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type    | Mandatory| Description                              |
| ------- | -------- | ---- | ---------------------------------- |
| rawData | number[] | Yes  | Raw data to write.                |
| size    | number   | Yes  | Size of the raw data, in bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The transferred size cannot be obtained; <br> 5.The transferred size is less than or equal to 0;<br> 6.The element does not exist in the array; <br> 7.Failed to obtain typedArray information; <br> 8.The array is not of type int32; <br> 9.The length of typedarray is smaller than the size of the original data sent. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let sequence = new rpc.MessageSequence();
  let arr = [1, 2, 3, 4, 5];
  try {
    sequence.writeRawData(arr, arr.length);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorMessage ' + e.message);
  }
  ```

### writeRawDataBuffer<sup>11+</sup>

writeRawDataBuffer(rawData: ArrayBuffer, size: number): void

Writes raw data to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type    | Mandatory| Description                              |
| ------- | -------- | ---- | ---------------------------------- |
| rawData | ArrayBuffer | Yes  | Raw data to write.                |
| size    | number   | Yes  | Size of the raw data, in bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.Failed to obtain arrayBuffer information; <br> 4.The transferred size cannot be obtained; <br> 5.The transferred size is less than or equal to 0; <br> 6.The transferred size is greater than the byte length of ArrayBuffer. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let buffer = new ArrayBuffer(64 * 1024);
  let int32View = new Int32Array(buffer);
  for (let i = 0; i < int32View.length; i++) {
    int32View[i] = i * 2 + 1;
  }
  let size = buffer.byteLength;
  let sequence = new rpc.MessageSequence();
  try {
    sequence.writeRawDataBuffer(buffer, size);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorMessage ' + e.message);
  }
  ```

### readRawData<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 11. Use [readRawDataBuffer](#readrawdatabuffer11) instead.

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
| number[] | Raw data obtained, in bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let sequence = new rpc.MessageSequence();
  let arr = [1, 2, 3, 4, 5];
  try {
    sequence.writeRawData(arr, arr.length);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorMessage ' + e.message);
  }
  try {
    let result = sequence.readRawData(5);
    hilog.info(0x0000, 'testTag', 'RpcTest: sequence read raw data result is ' + result);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read rawdata fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read rawdata fail, errorMessage ' + e.message);
  }
  ```

### readRawDataBuffer<sup>11+</sup>

readRawDataBuffer(size: number): ArrayBuffer

Reads raw data from this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| size   | number | Yes  | Size of the raw data to read.|

**Return value**

| Type    | Description                          |
| -------- | ------------------------------ |
| ArrayBuffer | Raw data obtained, in bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let buffer = new ArrayBuffer(64 * 1024);
  let int32View = new Int32Array(buffer);
  for (let i = 0; i < int32View.length; i++) {
    int32View[i] = i * 2 + 1;
  }
  let size = buffer.byteLength;
  let sequence = new rpc.MessageSequence();
  try {
    sequence.writeRawDataBuffer(buffer, size);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorMessage ' + e.message);
  }
  try {
    let result = sequence.readRawDataBuffer(size);
    let readInt32View = new Int32Array(result);
    hilog.info(0x0000, 'testTag', 'RpcTest: sequence read raw data result is ' + readInt32View);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read rawdata fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read rawdata fail, errorMessage ' + e.message);
  }
  ```

### writeArrayBuffer<sup>12+</sup>

writeArrayBuffer(buf: ArrayBuffer, typeCode: TypeCode): void

Writes data of the ArrayBuffer type to this **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type                     | Mandatory| Description                       |
| --------- | ------------------------- | ---- | --------------------------- |
| buf       | ArrayBuffer               | Yes  | Data to write.  |
| typeCode  | [TypeCode](#typecode12)   | Yes  | TypedArray type of the ArrayBuffer data.<br>The underlying write mode is determined based on the enum value of **TypeCode** passed by the service.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The parameter is an empty array; <br> 2.The number of parameters is incorrect; <br> 3.The parameter type does not match; <br> 4.The obtained value of typeCode is incorrect; <br> 5.Failed to obtain arrayBuffer information. |
| 1900009  | Failed to write data to the message sequence. |

**Example**

  ```ts
  // In this example, the value of TypeCode is Int16Array.
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const data = rpc.MessageSequence.create();

  let buffer = new ArrayBuffer(10);
  let int16View = new Int16Array(buffer);
  for (let i = 0; i < int16View.length; i++) {
    int16View[i] = i * 2 + 1;
  }

  try {
    data.writeArrayBuffer(buffer, rpc.TypeCode.INT16_ARRAY);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write ArrayBuffe fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write ArrayBuffe fail, errorMessage ' + e.message);
  }
  ```

### readArrayBuffer<sup>12+</sup>

readArrayBuffer(typeCode: TypeCode): ArrayBuffer

Reads data of the ArrayBuffer type from this **MessageSequence**.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                  |
| -------- | ----------------------- | ---- | ------------------------|
| typeCode | [TypeCode](#typecode12) | Yes  | TypedArray type of the ArrayBuffer data.<br>The underlying read mode is determined based on the enum value of **TypeCode** passed by the service. |

**Return value**

| Type    | Description                                        |
| -------- | -------------------------------------------- |
| ArrayBuffer | Data of the ArrayBuffer type read, in bytes.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The obtained value of typeCode is incorrect; |
| 1900010  | Failed to read data from the message sequence. |

**Example**

  ```ts
  // In this example, the value of TypeCode is Int16Array.
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const data = rpc.MessageSequence.create();

  let buffer = new ArrayBuffer(10);
  let int16View = new Int16Array(buffer);
  for (let i = 0; i < int16View.length; i++) {
    int16View[i] = i * 2 + 1;
  }

  try {
    data.writeArrayBuffer(buffer, rpc.TypeCode.INT16_ARRAY);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write ArrayBuffe fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write ArrayBuffe fail, errorMessage ' + e.message);
  }
  try {
    let result = data.readArrayBuffer(rpc.TypeCode.INT16_ARRAY);
    let readInt16View = new Int16Array(result);
    hilog.info(0x0000, 'testTag', 'RpcTest: read ArrayBuffer result is ' + readInt16View);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc read ArrayBuffer fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc read ArrayBuffer fail, errorMessage ' + e.message);
  }
  ```

## MessageParcel<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [MessageSequence](#messagesequence9) instead.

Provides APIs for reading and writing data in specific format. During RPC, the sender can use the **write()** method provided by **MessageParcel** to write data in specific format to a **MessageParcel** object. The receiver can use the **read()** method provided by **MessageParcel** to read data in specific format from a **MessageParcel** object. The data formats include basic data types and arrays, IPC objects, interface tokens, and custom sequenceable objects.

### create

static create(): MessageParcel

Creates a **MessageParcel** object. This method is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type         | Description                         |
| ------------- | ----------------------------- |
| [MessageParcel](#messageparceldeprecated) | **MessageParcel** object created.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  hilog.info(0x0000, 'testTag', 'RpcClient: data is ' + data);
  ```

### reclaim

reclaim(): void

Reclaims the **MessageParcel** object that is no longer used.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```ts
  let reply = rpc.MessageParcel.create();
  reply.reclaim();
  ```

### writeRemoteObject

writeRemoteObject(object: IRemoteObject): boolean

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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
  hilog.info(0x0000, 'testTag', 'readRemoteObject is ' + proxy);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeInterfaceToken("aaa");
  hilog.info(0x0000, 'testTag', 'RpcServer: writeInterfaceToken is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      let interfaceToken = data.readInterfaceToken();
      hilog.info(0x0000, 'testTag', 'RpcServer: interfaceToken is ' + interfaceToken);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let size = data.getSize();
  hilog.info(0x0000, 'testTag', 'RpcClient: size is ' + size);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.getCapacity();
  hilog.info(0x0000, 'testTag', 'RpcClient: capacity is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let setSize = data.setSize(16);
  hilog.info(0x0000, 'testTag', 'RpcClient: setSize is ' + setSize);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.setCapacity(100);
  hilog.info(0x0000, 'testTag', 'RpcClient: setCapacity is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      let getWritableBytes = data.getWritableBytes();
      hilog.info(0x0000, 'testTag', 'RpcServer: getWritableBytes is ' + getWritableBytes);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      let result = data.getReadableBytes();
      hilog.info(0x0000, 'testTag', 'RpcServer: getReadableBytes is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let readPos = data.getReadPosition();
  hilog.info(0x0000, 'testTag', 'RpcClient: readPos is ' + readPos);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  data.writeInt(10);
  let bwPos = data.getWritePosition();
  hilog.info(0x0000, 'testTag', 'RpcClient: bwPos is ' + bwPos);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  data.writeInt(12);
  data.writeString("parcel");
  let number = data.readInt();
  hilog.info(0x0000, 'testTag', 'RpcClient: number is ' + number);
  data.rewindRead(0);
  let number2 = data.readInt();
  hilog.info(0x0000, 'testTag', 'RpcClient: rewindRead is ' + number2);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  data.writeInt(4);
  data.rewindWrite(0);
  data.writeInt(5);
  let number = data.readInt();
  hilog.info(0x0000, 'testTag', 'RpcClient: rewindWrite is ' + number);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeByte(2);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeByte is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeByte(2);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeByte is ' + result);
  let ret = data.readByte();
  hilog.info(0x0000, 'testTag', 'RpcClient: readByte is ' + ret);
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
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeShort(8);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeShort is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeShort(8);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeShort is ' + result);
  let ret = data.readShort();
  hilog.info(0x0000, 'testTag', 'RpcClient: readShort is ' + ret);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeInt(10);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeInt is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeInt(10);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeInt is ' + result);
  let ret = data.readInt();
  hilog.info(0x0000, 'testTag', 'RpcClient: readInt is ' + ret);
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
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeLong(10000);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeLong is ' + result);
  ```

### readLong

readLong(): number

Reads the Long int value from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description          |
| ------ | -------------- |
| number | Long integer read.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeLong(10000);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeLong is ' + result);
  let ret = data.readLong();
  hilog.info(0x0000, 'testTag', 'RpcClient: readLong is ' + ret);
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
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeFloat(1.2);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeFloat is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeFloat(1.2);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeFloat is ' + result);
  let ret = data.readFloat();
  hilog.info(0x0000, 'testTag', 'RpcClient: readFloat is ' + ret);
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
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeDouble(10.2);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeDouble is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeDouble(10.2);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeDouble is ' + result);
  let ret = data.readDouble();
  hilog.info(0x0000, 'testTag', 'RpcClient: readDouble is ' + ret);
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
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeBoolean(false);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeBoolean is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeBoolean(false);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeBoolean is ' + result);
  let ret = data.readBoolean();
  hilog.info(0x0000, 'testTag', 'RpcClient: readBoolean is ' + ret);
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
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeChar(97);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeChar is ' + result);
  ```

### readChar

readChar(): number

Reads the single character value from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| number | Single character value read.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeChar(97);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeChar is ' + result);
  let ret = data.readChar();
  hilog.info(0x0000, 'testTag', 'RpcClient: readChar is ' + ret);
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
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeString('abc');
  hilog.info(0x0000, 'testTag', 'RpcClient: writeString is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeString('abc');
  hilog.info(0x0000, 'testTag', 'RpcClient: writeString is ' + result);
  let ret = data.readString();
  hilog.info(0x0000, 'testTag', 'RpcClient: readString is ' + ret);
  ```

### writeSequenceable

writeSequenceable(val: Sequenceable): boolean

Writes a sequenceable object to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type                         | Mandatory| Description                |
| ------ | ----------------------------- | ---- | -------------------- |
| val    | [Sequenceable](#sequenceabledeprecated) | Yes  | Sequenceable object to write.|

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MySequenceable implements rpc.Sequenceable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageParcel: rpc.MessageParcel): boolean {
      messageParcel.writeInt(this.num);
      messageParcel.writeString(this.str);
      return true;
    }
    unmarshalling(messageParcel: rpc.MessageParcel): boolean {
      this.num = messageParcel.readInt();
      this.str = messageParcel.readString();
      return true;
    }
  }
  let sequenceable = new MySequenceable(1, "aaa");
  let data = rpc.MessageParcel.create();
  let result = data.writeSequenceable(sequenceable);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeSequenceable is ' + result);
  ```

### readSequenceable

readSequenceable(dataIn: Sequenceable): boolean

Reads member variables from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type                         | Mandatory   | Description                                          |
| ------ | ----------------------------- | ------- | ---------------------------------------------- |
| dataIn | [Sequenceable](#sequenceabledeprecated) | Yes  | Object that reads member variables from the **MessageParcel** object.|

**Return value**

| Type   | Description                                    |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MySequenceable implements rpc.Sequenceable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageParcel: rpc.MessageParcel): boolean {
      messageParcel.writeInt(this.num);
      messageParcel.writeString(this.str);
      return true;
    }
    unmarshalling(messageParcel: rpc.MessageParcel): boolean {
      this.num = messageParcel.readInt();
      this.str = messageParcel.readString();
      return true;
    }
  }
  let sequenceable = new MySequenceable(1, "aaa");
  let data = rpc.MessageParcel.create();
  let result = data.writeSequenceable(sequenceable);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeSequenceable is ' + result);
  let ret = new MySequenceable(0, "");
  let result2 = data.readSequenceable(ret);
  hilog.info(0x0000, 'testTag', 'RpcClient: readSequenceable is ' + result2);
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

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let result = data.writeByteArray(ByteArrayVar);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeByteArray is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let result = data.writeByteArray(ByteArrayVar);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeByteArray is ' + result);
  let array: Array<number> = new Array(5);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let result = data.writeByteArray(ByteArrayVar);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeByteArray is ' + result);
  let array = data.readByteArray();
  hilog.info(0x0000, 'testTag', 'RpcClient: readByteArray is ' + array);
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

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeShortArray is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeShortArray is ' + result);
  let array: Array<number> = new Array(3);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeShortArray is ' + result);
  let array = data.readShortArray();
  hilog.info(0x0000, 'testTag', 'RpcClient: readShortArray is ' + array);
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

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeIntArray is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeIntArray is ' + result);
  let array: Array<number> = new Array(3);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeIntArray is ' + result);
  let array = data.readIntArray();
  hilog.info(0x0000, 'testTag', 'RpcClient: readIntArray is ' + array);
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
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeLongArray is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeLongArray is ' + result);
  let array: Array<number> = new Array(3);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeLongArray is ' + result);
  let array = data.readLongArray();
  hilog.info(0x0000, 'testTag', 'RpcClient: readLongArray is ' + array);
  ```

### writeFloatArray

writeFloatArray(floatArray: number[]): boolean

Writes a FloatArray to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type| Mandatory| Description |
| ---------- | -------- | ---- | --- |
| floatArray | number[] | Yes  | Floating-point array to write. The system processes Float data as that of the Double type. Therefore, the total number of bytes occupied by a FloatArray must be calculated as the Double type.|

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeFloatArray is ' + result);
  ```

### readFloatArray

readFloatArray(dataIn: number[]): void

Reads a FloatArray from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type    | Mandatory| Description  |
| ------ | -------- | ---- | ------ |
| dataIn | number[] | Yes  | Floating-point array to read. The system processes Float data as that of the Double type. Therefore, the total number of bytes occupied by a FloatArray must be calculated as the Double type.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeFloatArray is ' + result);
  let array: Array<number> = new Array(3);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeFloatArray is ' + result);
  let array = data.readFloatArray();
  hilog.info(0x0000, 'testTag', 'RpcClient: readFloatArray is ' + array);
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

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeDoubleArray is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeDoubleArray is ' + result);
  let array: Array<number> = new Array(3);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeDoubleArray is ' + result);
  let array = data.readDoubleArray();
  hilog.info(0x0000, 'testTag', 'RpcClient: readDoubleArray is ' + array);
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

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeBooleanArray is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeBooleanArray is ' + result);
  let array: Array<boolean> = new Array(3);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeBooleanArray is ' + result);
  let array = data.readBooleanArray();
  hilog.info(0x0000, 'testTag', 'RpcClient: readBooleanArray is ' + array);
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

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 88]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeCharArray is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 99]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeCharArray is ' + result);
  let array: Array<number> = new Array(3);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 99]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeCharArray is ' + result);
  let array = data.readCharArray();
  hilog.info(0x0000, 'testTag', 'RpcClient: readCharArray is ' + array);
  ```

### writeStringArray

writeStringArray(stringArray: string[]): boolean

Writes a string array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name     | Type    | Mandatory| Description            |
| ----------- | -------- | ---- | ---------------- |
| stringArray | string[] | Yes  | String array to write. The length of a single element in the array must be less than 40960 bytes.|

**Return value**

| Type   | Description|
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeStringArray is ' + result);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeStringArray is ' + result);
  let array: Array<string> = new Array(2);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeStringArray is ' + result);
  let array = data.readStringArray();
  hilog.info(0x0000, 'testTag', 'RpcClient: readStringArray is ' + array);
  ```

### writeNoException<sup>8+</sup>

writeNoException(): void

Writes information to this **MessageParcel** object indicating that no exception occurred.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      if (code === 1) {
        hilog.info(0x0000, 'testTag', 'RpcServer: onRemoteRequest called');
        reply.writeNoException();
        return true;
      } else {
        hilog.error(0x0000, 'testTag', 'RpcServer: unknown code: ' + code);
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

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **sendRequest()** of the proxy object is called to send a message.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeNoException();
  data.writeString('hello');
  if (proxy != undefined) {
    let a = proxy.sendRequest(1, data, reply, option) as Object;
    let b = a as Promise<rpc.SendRequestResult>;
    b.then((result: rpc.SendRequestResult) => {
      if (result.errCode === 0) {
        hilog.info(0x0000, 'testTag', 'sendRequest got result');
        result.reply.readException();
        let msg = result.reply.readString();
        hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
      } else {
        hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest failed, errCode: ' + result.errCode);
      }
    }).catch((e: Error) => {
      hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest got exception: ' + e.message);
    }).finally (() => {
      hilog.info(0x0000, 'testTag', 'RPCTest: sendRequest ends, reclaim parcel');
      data.reclaim();
      reply.reclaim();
    });
  }
  ```

### writeSequenceableArray

writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean

Writes a sequenceable array to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name           | Type                                     | Mandatory| Description                      |
| ----------------- | ----------------------------------------- | ---- | -------------------------- |
| sequenceableArray | [Sequenceable](#sequenceabledeprecated)[] | Yes  | Sequenceable array to write.|

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MySequenceable implements rpc.Sequenceable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageParcel: rpc.MessageParcel): boolean {
      messageParcel.writeInt(this.num);
      messageParcel.writeString(this.str);
      return true;
    }
    unmarshalling(messageParcel: rpc.MessageParcel): boolean {
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
  hilog.info(0x0000, 'testTag', 'RpcClient: writeSequenceableArray is ' + result);
  ```

### readSequenceableArray<sup>8+</sup>

readSequenceableArray(sequenceableArray: Sequenceable[]): void

Reads a sequenceable array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name           | Type                                     | Mandatory| Description                      |
| ----------------- | ----------------------------------------- | ---- | -------------------------- |
| sequenceableArray | [Sequenceable](#sequenceabledeprecated)[] | Yes  | Sequenceable array to read.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MySequenceable implements rpc.Sequenceable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageParcel: rpc.MessageParcel): boolean {
      messageParcel.writeInt(this.num);
      messageParcel.writeString(this.str);
      return true;
    }
    unmarshalling(messageParcel: rpc.MessageParcel): boolean {
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
  hilog.info(0x0000, 'testTag', 'RpcClient: writeSequenceableArray is ' + result);
  let b = [new MySequenceable(0, ""), new MySequenceable(0, ""), new MySequenceable(0, "")];
  data.readSequenceableArray(b);
  ```

### writeRemoteObjectArray<sup>8+</sup>

writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean

Writes an array of **IRemoteObject** objects to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name     | Type           | Mandatory| Description |
| ----------- | --------------- | ---- | ----- |
| objectArray | [IRemoteObject](#iremoteobject)[] | Yes  | Array of **IRemoteObject** objects to write.|

**Return value**

| Type   | Description                                                                                                                |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
  hilog.info(0x0000, 'testTag', 'RpcClient: writeRemoteObjectArray is ' + result);
  ```

### readRemoteObjectArray<sup>8+</sup>

readRemoteObjectArray(objects: IRemoteObject[]): void

Reads an **IRemoteObject** array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type           | Mandatory| Description     |
| ------- | --------------- | ---- | --------- |
| objects | [IRemoteObject](#iremoteobject)[] | Yes  | **IRemoteObject** array to read.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
  data.writeRemoteObjectArray(a);
  let b: Array<rpc.IRemoteObject> = new Array(3);
  data.readRemoteObjectArray(b);
  ```

### readRemoteObjectArray<sup>8+</sup>

readRemoteObjectArray(): IRemoteObject[]

Reads the **IRemoteObject** array from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type           | Description                       |
| --------------- | --------------------------- |
| [IRemoteObject](#iremoteobject)[] | **IRemoteObject** object array obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
  hilog.info(0x0000, 'testTag', 'RpcClient: readRemoteObjectArray is ' + result);
  let b = data.readRemoteObjectArray();
  hilog.info(0x0000, 'testTag', 'RpcClient: readRemoteObjectArray is ' + b);
  ```

### closeFileDescriptor<sup>8+</sup>

static closeFileDescriptor(fd: number): void

Closes a file descriptor. This API is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| fd     | number | Yes  | File descriptor to close.|

**Example**

  ```ts
  import { fileIo } from '@kit.CoreFileKit';

  let filePath = "path/to/file";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  rpc.MessageParcel.closeFileDescriptor(file.fd);
  ```

### dupFileDescriptor<sup>8+</sup>

static dupFileDescriptor(fd: number) :number

Duplicates a file descriptor. This API is a static method.

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

  ```ts
  import { fileIo } from '@kit.CoreFileKit';

  let filePath = "path/to/file";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  rpc.MessageParcel.dupFileDescriptor(file.fd);
  ```

### containFileDescriptors<sup>8+</sup>

containFileDescriptors(): boolean

Checks whether this **MessageParcel** object contains file descriptors.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean |Returns **true** if the **MessageParcel** object contains file descriptors; returns **false** otherwise.|

**Example**

  ```ts
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let parcel = new rpc.MessageParcel();
  let filePath = "path/to/file";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let writeResult = parcel.writeFileDescriptor(file.fd);
  hilog.info(0x0000, 'testTag', 'RpcTest: parcel writeFd result is ' + writeResult);
  let containFD = parcel.containFileDescriptors();
  hilog.info(0x0000, 'testTag', 'RpcTest: parcel after write fd containFd result is ' + containFD);
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

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let parcel = new rpc.MessageParcel();
  let filePath = "path/to/file";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  let writeResult = parcel.writeFileDescriptor(file.fd);
  hilog.info(0x0000, 'testTag', 'RpcTest: parcel writeFd result is ' + writeResult);
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

  ```ts
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let parcel = new rpc.MessageParcel();
  let filePath = "path/to/file";
  let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  parcel.writeFileDescriptor(file.fd);
  let readFD = parcel.readFileDescriptor();
  hilog.info(0x0000, 'testTag', 'RpcTest: parcel read fd is ' + readFD);
  ```

### writeAshmem<sup>8+</sup>

writeAshmem(ashmem: Ashmem): boolean

Writes an anonymous shared object to this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description                               |
| ------ | ------ | ---- | ----------------------------------- |
| ashmem | [Ashmem](#ashmem8) | Yes  | Anonymous shared object to write.|

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let parcel = new rpc.MessageParcel();
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);
  let isWriteSuccess = parcel.writeAshmem(ashmem);
  hilog.info(0x0000, 'testTag', 'RpcTest: write ashmem to result is ' + isWriteSuccess);
  ```

### readAshmem<sup>8+</sup>

readAshmem(): Ashmem

Reads the anonymous shared object from this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| [Ashmem](#ashmem8) | Anonymous share object obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let parcel = new rpc.MessageParcel();
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);
  let isWriteSuccess = parcel.writeAshmem(ashmem);
  hilog.info(0x0000, 'testTag', 'RpcTest: write ashmem to result is ' + isWriteSuccess);
  let readAshmem = parcel.readAshmem();
  hilog.info(0x0000, 'testTag', 'RpcTest: read ashmem to result is ' + readAshmem);
  ```

### getRawDataCapacity<sup>8+</sup>

getRawDataCapacity(): number

Obtains the maximum amount of raw data that can be held by this **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description                                                      |
| ------ | ---------------------------------------------------------- |
| number | Maximum amount of raw data that **MessageParcel** can hold, that is, 128 MB.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let parcel = new rpc.MessageParcel();
  let result = parcel.getRawDataCapacity();
  hilog.info(0x0000, 'testTag', 'RpcTest: parcel get RawDataCapacity result is ' + result);
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

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let parcel = new rpc.MessageParcel();
  let arr = [1, 2, 3, 4, 5];
  let isWriteSuccess = parcel.writeRawData(arr, arr.length);
  hilog.info(0x0000, 'testTag', 'RpcTest: parcel write raw data result is ' + isWriteSuccess);
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let parcel = new rpc.MessageParcel();
  let arr = [1, 2, 3, 4, 5];
  let isWriteSuccess = parcel.writeRawData(arr, arr.length);
  hilog.info(0x0000, 'testTag', 'RpcTest: parcel write raw data result is ' + isWriteSuccess);
  let result = parcel.readRawData(5);
  hilog.info(0x0000, 'testTag', 'RpcTest: parcel read raw data result is ' + result);
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
| dataOut |[MessageSequence](#messagesequence9)| Yes  | **MessageSequence** object to which the **Parcelable** object is to be marshaled.|

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyParcelable implements rpc.Parcelable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageSequence: rpc.MessageSequence): boolean {
      messageSequence.writeInt(this.num);
      messageSequence.writeString(this.str);
      return true;
    }
    unmarshalling(messageSequence: rpc.MessageSequence): boolean {
      this.num = messageSequence.readInt();
      this.str = messageSequence.readString();
      hilog.info(0x0000, 'testTag', 'RpcClient: readInt is ' + this.num + ' readString is ' + this.str);
      return true;
    }
  }
  let parcelable = new MyParcelable(1, "aaa");
  let data = rpc.MessageSequence.create();
  data.writeParcelable(parcelable);
  let ret = new MyParcelable(0, "");
  data.readParcelable(ret);
  ```

### unmarshalling

unmarshalling(dataIn: MessageSequence): boolean

Unmarshals this **Parcelable** object from a **MessageSequence** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type           | Mandatory| Description                                           |
| ------ | --------------- | ---- | ----------------------------------------------- |
| dataIn | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object from which the **Parcelable** object is to be unmarshaled.|

**Return value**

| Type   | Description                                    |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyParcelable implements rpc.Parcelable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageSequence: rpc.MessageSequence): boolean {
      messageSequence.writeInt(this.num);
      messageSequence.writeString(this.str);
      return true;
    }
    unmarshalling(messageSequence: rpc.MessageSequence): boolean {
      this.num = messageSequence.readInt();
      this.str = messageSequence.readString();
      hilog.info(0x0000, 'testTag', 'RpcClient: readInt is ' + this.num + ' readString is ' + this.str);
      return true;
    }
  }
  let parcelable = new MyParcelable(1, "aaa");
  let data = rpc.MessageSequence.create();
  data.writeParcelable(parcelable);
  let ret = new MyParcelable(0, "");
  data.readParcelable(ret);
  ```

## Sequenceable<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [Parcelable](#parcelable9) instead.

Writes objects of classes to a **MessageParcel** and reads them from the **MessageParcel** during IPC.

### marshalling

marshalling(dataOut: MessageParcel): boolean

Marshals the sequenceable object into a **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type                                     | Mandatory| Description                                     |
| ------- | ----------------------------------------- | ---- | ----------------------------------------- |
| dataOut | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object to which the sequenceable object is to be marshaled.|

**Return value**

| Type   | Description                             |
| ------- | --------------------------------  |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MySequenceable implements rpc.Sequenceable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageParcel: rpc.MessageParcel): boolean {
      messageParcel.writeInt(this.num);
      messageParcel.writeString(this.str);
      return true;
    }
    unmarshalling(messageParcel: rpc.MessageParcel): boolean {
      this.num = messageParcel.readInt();
      this.str = messageParcel.readString();
      return true;
    }
  }
  let sequenceable = new MySequenceable(1, "aaa");
  let data = rpc.MessageParcel.create();
  let result = data.writeSequenceable(sequenceable);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeSequenceable is ' + result);
  let ret = new MySequenceable(0, "");
  let result2 = data.readSequenceable(ret);
  hilog.info(0x0000, 'testTag', 'RpcClient: readSequenceable is ' + result2);
  ```

### unmarshalling

unmarshalling(dataIn: MessageParcel): boolean

Unmarshals this sequenceable object from a **MessageParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type                                     | Mandatory| Description                                         |
| ------ | ----------------------------------------- | ---- | --------------------------------------------- |
| dataIn | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object in which the sequenceable object is to be unmarshaled.|

**Return value**

| Type   | Description                                    |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MySequenceable implements rpc.Sequenceable {
    num: number = 0;
    str: string = '';
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    }
    marshalling(messageParcel: rpc.MessageParcel): boolean {
      messageParcel.writeInt(this.num);
      messageParcel.writeString(this.str);
      return true;
    }
    unmarshalling(messageParcel: rpc.MessageParcel): boolean {
      this.num = messageParcel.readInt();
      this.str = messageParcel.readString();
      return true;
    }
  }
  let sequenceable = new MySequenceable(1, "aaa");
  let data = rpc.MessageParcel.create();
  let result = data.writeSequenceable(sequenceable);
  hilog.info(0x0000, 'testTag', 'RpcClient: writeSequenceable is ' + result);
  let ret = new MySequenceable(0, "");
  let result2 = data.readSequenceable(ret);
  hilog.info(0x0000, 'testTag', 'RpcClient: readSequenceable is ' + result2);
  ```

## IRemoteBroker

Represents the holder of a remote proxy object.

### asObject

asObject(): IRemoteObject

Obtains a proxy or remote object. This API must be implemented by its derived classes.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type | Description |
| ----- | ----- |
| [IRemoteObject](#iremoteobject) | Returns the **RemoteObject** if it is the caller; returns the [IRemoteObject](#iremoteobject), the holder of this **RemoteProxy** object, if the caller is a [RemoteProxy](#remoteproxy) object.|

**Example**

  ```ts
  class TestAbility extends rpc.RemoteObject {
    asObject() {
      return this;
    }
  }
  let remoteObject = new TestAbility("testObject").asObject();
  ```

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want  = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **asObject()** of the proxy object is called to obtain the proxy or remote object.

  ```ts
  class TestProxy {
    remote: rpc.IRemoteObject;
    constructor(remote: rpc.IRemoteObject) {
      this.remote = remote;
    }
    asObject() {
      return this.remote;
    }
  }
  if (proxy != undefined) {
    let iRemoteObject = new TestProxy(proxy).asObject();
  }
  ```

## DeathRecipient

Subscribes to death notifications of a remote object. When the remote object is dead, the local end will receive a notification and **[onRemoteDied](#onremotedied)** will be called. A remote object is dead when the process holding the object is terminated or the device of the remote object is shut down or restarted. If the local and remote objects belong to different devices, the remote object is dead when the device holding the remote object is detached from the network. 

### onRemoteDied

onRemoteDied(): void

Called to perform subsequent operations when a death notification of the remote object is received.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  ```

## RequestResult<sup>9+</sup>

Defines the response to the request.

**System capability**: SystemCapability.Communication.IPC.Core

| Name   | Type           | Readable| Writable| Description                                 |
| ------- | --------------- | ---- | ---- |-------------------------------------- |
| errCode | number          | Yes  | No  | Error code.                             |
| code    | number          | Yes  | No  | Message code.                           |
| data    | [MessageSequence](#messagesequence9) | Yes  | No  | **MessageSequence** object sent to the remote process.|
| reply   | [MessageSequence](#messagesequence9) | Yes  | No  | **MessageSequence** object returned by the remote process.  |

## SendRequestResult<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [RequestResult](#requestresult9) instead.

Defines the response to the request.

**System capability**: SystemCapability.Communication.IPC.Core

| Name   | Type         | Readable| Writable| Description                               |
| ------- | ------------- | ---- | ---- | ----------------------------------- |
| errCode | number        | Yes  | No  | Error code.                           |
| code    | number        | Yes  | No  | Message code.                         |
| data    | [MessageParcel](#messageparceldeprecated) | Yes  | No  | **MessageParcel** object sent to the remote process.|
| reply   | [MessageParcel](#messageparceldeprecated) | Yes  | No  | **MessageParcel** object returned by the remote process.  |

## IRemoteObject

Provides methods to query of obtain interface descriptors, add or delete death notifications, dump object status to specific files, and send messages.

### getLocalInterface<sup>9+</sup>

getLocalInterface(descriptor: string): IRemoteBroker

Obtains the string of the interface descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name    | Type  | Mandatory| Description                |
| ---------- | ------ | ---- | -------------------- |
| descriptor | string | Yes  | Interface descriptor.|

**Return value**

| Type         | Description                                         |
| ------------- | --------------------------------------------- |
| [IRemoteBroker](#iremotebroker) | **IRemoteBroker** object bound to the specified interface token.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The string length exceeds 40960 bytes; <br> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |

### queryLocalInterface<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [getLocalInterface](#getlocalinterface9) instead.

queryLocalInterface(descriptor: string): IRemoteBroker

Queries the string of the interface descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name    | Type  | Mandatory| Description                |
| ---------- | ------ | ---- | -------------------- |
| descriptor | string | Yes  | Interface descriptor.|

**Return value**

| Type         | Description                                         |
| ------------- | --------------------------------------------- |
| [IRemoteBroker](#iremotebroker) | **IRemoteBroker** object bound to the specified interface token.|

### sendRequest<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 8. Use [sendMessageRequest](#sendmessagerequest9) instead.

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a promise will be fulfilled immediately and the reply message does not contain any content. If synchronous mode is set in **options**, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type                                     | Mandatory| Description                                                                                  |
| ------- | ----------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| code    | number                                    | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
| reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
| options | [MessageOption](#messageoption)           | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the message is sent successfully; returns **false** otherwise.|

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise&lt;RequestResult&gt;

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a promise will be fulfilled immediately and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a promise will be fulfilled when the response to **sendMessageRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type                                | Mandatory| Description                                                                                  |
| ------- | ------------------------------------ | ---- | -------------------------------------------------------------------------------------- |
| code    | number                               | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data    | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
| reply   | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that receives the response.                                                   |
| options | [MessageOption](#messageoption)      | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

| Type                        | Description                                     |
| ---------------------------- | ----------------------------------------- |
| Promise&lt;[RequestResult](#requestresult9)&gt; | Promise used to return the **requestResult** object.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.Failed to obtain the passed object instance. |

### sendRequest<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [sendMessageRequest](#sendmessagerequest9) instead.

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a promise will be fulfilled immediately and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type                                     | Mandatory| Description                                                                                  |
| ------- | ----------------------------------------  | ---- | -------------------------------------------------------------------------------------- |
| code    | number                                    | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
| reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
| options | [MessageOption](#messageoption)           | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

| Type                                                        | Description                                         |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | Promise used to return a **sendRequestResult** instance.|

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback&lt;RequestResult&gt;): void

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a callback will be called immediately, and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a callback will be invoked when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                                                  |
| -------- | ------------------------------------ | ---- | -------------------------------------------------------------------------------------- |
| code     | number                               | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data     | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
| reply    | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that receives the response.                                                   |
| options  | [MessageOption](#messageoption)      | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |
| callback | AsyncCallback&lt;[RequestResult](#requestresult9)&gt;   | Yes  | Callback for receiving the sending result.                                                                  |

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.Failed to obtain the passed object instance. |

### sendRequest<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [sendMessageRequest](#sendmessagerequest9-1) instead.

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a callback will be called immediately, and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a callback will be invoked when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| code     | number                                                       | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data     | [MessageParcel](#messageparceldeprecated)                    | Yes  | **MessageParcel** object holding the data to send.                   |
| reply    | [MessageParcel](#messageparceldeprecated)                    | Yes  | **MessageParcel** object that receives the response.                           |
| options  | [MessageOption](#messageoption)                              | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                        |
| callback | AsyncCallback&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | Yes  | Callback for receiving the sending result.                                        |

### registerDeathRecipient<sup>9+</sup>

registerDeathRecipient(recipient: DeathRecipient, flags: number): void

Registers a callback for receiving death notifications of the remote object. This callback will be called if the remote object process matching the **RemoteProxy** object is killed.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type                             | Mandatory| Description          |
| --------- | --------------------------------- | ---- | -------------- |
| recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to register.|
| flags     | number                            | Yes  | Flag of the death notification.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The callback used to receive remote object death notifications is empty. |
| 1900008  | The proxy or remote object is invalid. |

### addDeathrecipient<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [registerDeathRecipient](#registerdeathrecipient9) instead.

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Adds a callback for receiving death notifications of the remote object. This method is called if the remote object process matching the **RemoteProxy** object is killed.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type                             | Mandatory| Description          |
| --------- | --------------------------------- | ---- | -------------- |
| recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to add.|
| flags     | number                            | Yes  | Flag of the death notification.|

**Return value**

| Type   | Description                                    |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the callback is added successfully; returns **false** otherwise.|

### unregisterDeathRecipient<sup>9+</sup>

unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void

Unregisters the callback used to receive death notifications of the remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type                             | Mandatory| Description          |
| --------- | --------------------------------- | ---- | -------------- |
| recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to unregister.|
| flags     | number                            | Yes  | Flag of the death notification.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The callback used to receive remote object death notifications is empty. |
| 1900008  | The proxy or remote object is invalid. |

### removeDeathRecipient<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [unregisterDeathRecipient](#unregisterdeathrecipient9) instead.

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Removes the callback used to receive death notifications of the remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type                             | Mandatory| Description          |
| --------- | --------------------------------- | ---- | -------------- |
| recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to remove.|
| flags     | number                            | Yes  | Flag of the death notification.|

**Return value**

| Type   | Description                                    |
| ------- | -----------------------------------------|
| boolean | Returns **true** if the callback is removed; returns **false** otherwise.|

### getDescriptor<sup>9+</sup>

getDescriptor(): string

Obtains the interface descriptor (which is a string) of this object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| string | Interface descriptor obtained.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900008  | The proxy or remote object is invalid. |

### getInterfaceDescriptor<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [getDescriptor](#getdescriptor9) instead.

getInterfaceDescriptor(): string

Obtains the interface descriptor (which is a string) of this object.

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

| Type   | Description                              |
| ------- | ---------------------------------- |
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

>**NOTE**<br>This API is deprecated since API version 8. Use [sendMessageRequest](#sendmessagerequest9-2) instead.

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a promise will be fulfilled immediately and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type                                     | Mandatory| Description                                                                                  |
| ------- | ----------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| code    | number                                    | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
| reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
| options | [MessageOption](#messageoption)           | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

| Type   | Description                            |
| ------- | ---------------------------------|
| boolean | Returns **true** if the message is sent successfully; returns **false** otherwise.|

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
     onConnect: (elementName, remoteProxy) => {
        hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
        proxy = remoteProxy;
     },
     onDisconnect: (elementName) => {
        hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
     },
     onFailed: () => {
        hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
     }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **sendRequest()** of the proxy object is called to send a message.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  if (proxy != undefined) {
    let ret: boolean = proxy.sendRequest(1, data, reply, option);
    if (ret) {
      hilog.info(0x0000, 'testTag', 'sendRequest got result');
      let msg = reply.readString();
      hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
    } else {
      hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest failed');
    }
    hilog.info(0x0000, 'testTag', 'RPCTest: sendRequest ends, reclaim parcel');
    data.reclaim();
    reply.reclaim();
  }
  ```

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise&lt;RequestResult&gt;

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a promise will be fulfilled immediately and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a promise will be fulfilled when the response to **sendMessageRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type                                | Mandatory| Description                                                                                  |
| ------- | ------------------------------------ | ---- | -------------------------------------------------------------------------------------- |
| code    | number                               | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data    | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
| reply   | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that receives the response.                                                   |
| options | [MessageOption](#messageoption)      | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

| Type                        | Description                                     |
| ---------------------------- | ----------------------------------------- |
| Promise&lt;[RequestResult](#requestresult9)&gt; | Promise used to return a **requestResult** instance.|


**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.Failed to obtain the passed object instance. |

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **sendMessageRequest()** of the proxy object is called to send a message.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let option = new rpc.MessageOption();
  let data = rpc.MessageSequence.create();
  let reply = rpc.MessageSequence.create();
  data.writeInt(1);
  data.writeString("hello");
  if (proxy != undefined) {
    proxy.sendMessageRequest(1, data, reply, option)
    .then((result: rpc.RequestResult) => {
      if (result.errCode === 0) {
        hilog.info(0x0000, 'testTag', 'sendMessageRequest got result');
        let num = result.reply.readInt();
        let msg = result.reply.readString();
        hilog.info(0x0000, 'testTag', 'RPCTest: reply num: ' + num);
        hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
      } else {
        hilog.error(0x0000, 'testTag', 'RPCTest: sendMessageRequest failed, errCode: ' + result.errCode);
      }
    }).catch((e: Error) => {
      hilog.error(0x0000, 'testTag', 'RPCTest: sendMessageRequest failed, message: ' + e.message);
    }).finally (() => {
      hilog.info(0x0000, 'testTag', 'RPCTest: sendMessageRequest ends, reclaim parcel');
      data.reclaim();
      reply.reclaim();
    });
  }
  ```

### sendRequest<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [sendMessageRequest](#sendmessagerequest9-2) instead.

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a promise will be fulfilled immediately and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type                                     | Mandatory| Description                                                                                  |
| ------- | ----------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| code    | number                                    | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
| reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
| options | [MessageOption](#messageoption)           | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

| Type                                                        | Description                                         |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | Promise used to return a **sendRequestResult** instance.|

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **sendRequest()** of the proxy object is called to send a message.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  if (proxy != undefined) {
    let a = proxy.sendRequest(1, data, reply, option) as Object;
    let b = a as Promise<rpc.SendRequestResult>;
    b.then((result: rpc.SendRequestResult) => {
      if (result.errCode === 0) {
        hilog.info(0x0000, 'testTag', 'sendRequest got result');
        let num = result.reply.readInt();
        let msg = result.reply.readString();
        hilog.info(0x0000, 'testTag', 'RPCTest: reply num: ' + num);
        hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
      } else {
        hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest failed, errCode: ' + result.errCode);
      }
    }).catch((e: Error) => {
      hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest failed, message: ' + e.message);
    }).finally (() => {
      hilog.info(0x0000, 'testTag', 'RPCTest: sendRequest ends, reclaim parcel');
      data.reclaim();
      reply.reclaim();
    });
  }
  ```

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback&lt;RequestResult&gt;): void

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a callback will be called immediately, and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a callback will be invoked at certain time after the response to **RequestResult** is returned, and the reply contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                                                  |
| -------- | ------------------------------------ | ---- | -------------------------------------------------------------------------------------- |
| code     | number                               | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data     | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
| reply    | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that receives the response.                                                   |
| options  | [MessageOption](#messageoption)      | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |
| callback | AsyncCallback&lt;[RequestResult](#requestresult9)&gt;   | Yes  | Callback for receiving the sending result.                                                                  |


**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.Failed to obtain the passed object instance. |

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };
  function sendMessageRequestCallback(err: BusinessError, result: rpc.RequestResult) {
    if (result.errCode === 0) {
      hilog.info(0x0000, 'testTag', 'sendMessageRequest got result');
      let num = result.reply.readInt();
      let msg = result.reply.readString();
      hilog.info(0x0000, 'testTag', 'RPCTest: reply num: ' + num);
      hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
    } else {
      hilog.error(0x0000, 'testTag', 'RPCTest: sendMessageRequest failed, errCode: ' + result.errCode);
    }
    hilog.info(0x0000, 'testTag', 'RPCTest: sendMessageRequest ends, reclaim parcel');
    result.data.reclaim();
    result.reply.reclaim();
}

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **sendMessageRequest()** of the proxy object is called to send a message.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let option = new rpc.MessageOption();
  let data = rpc.MessageSequence.create();
  let reply = rpc.MessageSequence.create();
  data.writeInt(1);
  data.writeString("hello");
  if (proxy != undefined) {
    try {
      proxy.sendMessageRequest(1, data, reply, option, sendMessageRequestCallback);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'rpc sendMessageRequest fail, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'rpc sendMessageRequest fail, errorMessage ' + e.message);
    }
  }
  ```

### sendRequest<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [sendMessageRequest](#sendmessagerequest9-3) instead.

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a callback will be called immediately, and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a callback will be invoked when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| code     | number                                                       | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data     | [MessageParcel](#messageparceldeprecated)                    | Yes  | **MessageParcel** object holding the data to send.                   |
| reply    | [MessageParcel](#messageparceldeprecated)                    | Yes  | **MessageParcel** object that receives the response.                           |
| options  | [MessageOption](#messageoption)                              | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                        |
| callback | AsyncCallback&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | Yes  | Callback for receiving the sending result.                                        |

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
      bundleName: "com.ohos.server",
      abilityName: "com.ohos.server.EntryAbility",
  };
  function sendRequestCallback(err: BusinessError, result: rpc.SendRequestResult) {
    if (result.errCode === 0) {
      hilog.info(0x0000, 'testTag', 'sendRequest got result');
      let num = result.reply.readInt();
      let msg = result.reply.readString();
      hilog.info(0x0000, 'testTag', 'RPCTest: reply num: ' + num);
      hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
    } else {
      hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest failed, errCode: ' + result.errCode);
    }
    hilog.info(0x0000, 'testTag', 'RPCTest: sendRequest ends, reclaim parcel');
    result.data.reclaim();
    result.reply.reclaim();
}

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **sendRequest()** of the proxy object is called to send a message.

  ```ts
  let option = new rpc.MessageOption();
  let data = rpc.MessageParcel.create();
  let reply = rpc.MessageParcel.create();
  data.writeInt(1);
  data.writeString("hello");
  if (proxy != undefined) {
    proxy.sendRequest(1, data, reply, option, sendRequestCallback);
  }
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

| Type                           | Description                                      |
| ------------------------------- | ------------------------------------------ |
| [IRemoteBroker](#iremotebroker) | Returns **Null** by default, which indicates a proxy interface.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | check param failed |
| 1900006  | Operation allowed only for the remote object. |

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **getLocalInterface()** of the proxy object is called to obtain the interface descriptor.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  if (proxy != undefined) {
    try {
      let broker: rpc.IRemoteBroker = proxy.getLocalInterface("testObject");
      hilog.info(0x0000, 'testTag', 'RpcClient: getLocalInterface is ' + broker);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorMessage ' + e.message);
    }
  }
  ```

### queryLocalInterface<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [getLocalInterface](#getlocalinterface9-1) instead.

queryLocalInterface(interface: string): IRemoteBroker

Obtains the **LocalInterface** object of an interface token.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type  | Mandatory| Description                  |
| --------- | ------ | ---- | ---------------------- |
| interface | string | Yes  | Interface descriptor.|

**Return value**

| Type                           | Description                                      |
| ------------------------------- | ------------------------------------------ |
| [IRemoteBroker](#iremotebroker) | Returns **Null** by default, which indicates a proxy interface.|

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **queryLocalInterface()** of the proxy object is called to obtain the interface descriptor.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  if (proxy != undefined) {
    let broker: rpc.IRemoteBroker = proxy.queryLocalInterface("testObject");
    hilog.info(0x0000, 'testTag', 'RpcClient: queryLocalInterface is ' + broker);
  }
  ```

### registerDeathRecipient<sup>9+</sup>

registerDeathRecipient(recipient: DeathRecipient, flags: number): void

Registers a callback for receiving death notifications of the remote object. This callback will be called if the remote object process matching the **RemoteProxy** object is killed.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type                             | Mandatory| Description          |
| --------- | --------------------------------- | ---- | -------------- |
| recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to register.|
| flags     | number                            | Yes  | Flag of the death notification.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The callback used to receive remote object death notifications is empty. |
| 1900008  | The proxy or remote object is invalid. |

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **registerDeathRecipient()** of the proxy object is called to register a callback for receiving the death notification of the remote object.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  let deathRecipient = new MyDeathRecipient();
  if (proxy != undefined) {
    try {
      proxy.registerDeathRecipient(deathRecipient, 0);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'proxy register deathRecipient fail, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'proxy register deathRecipient fail, errorMessage ' + e.message);
    }
  }
  ```

### addDeathRecipient<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [registerDeathRecipient](#registerdeathrecipient9-1) instead.

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Adds a callback for receiving the death notifications of the remote object, including the death notifications of the remote proxy.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type                             | Mandatory| Description                             |
| --------- | --------------------------------- | ---- | --------------------------------- |
| recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to add.         |
| flags     | number                            | Yes  | Flag of the death notification. This parameter is reserved. It is set to **0**.|

**Return value**

| Type   | Description                                    |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the callback is added successfully; returns **false** otherwise.|

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **addDeathRecipient()** of the proxy object is called to add a callback for receiving the death notification of the remove object.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  let deathRecipient = new MyDeathRecipient();
  if (proxy != undefined) {
    proxy.addDeathRecipient(deathRecipient, 0);
  }
  ```

### unregisterDeathRecipient<sup>9+</sup>

unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void

Unregisters the callback used to receive death notifications of the remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type                             | Mandatory| Description          |
| --------- | --------------------------------- | ---- | -------------- |
| recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to unregister.|
| flags     | number                            | Yes  | Flag of the death notification.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The callback used to receive remote object death notifications is empty. |
| 1900008  | The proxy or remote object is invalid. |

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **unregisterDeathRecipient()** of the proxy object is called to unregister the callback for receiving the death notification of the remote object.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  let deathRecipient = new MyDeathRecipient();
  if (proxy != undefined) {
    try {
      proxy.registerDeathRecipient(deathRecipient, 0);
      proxy.unregisterDeathRecipient(deathRecipient, 0);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'proxy unregister deathRecipient fail, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'proxy unregister deathRecipient fail, errorMessage ' + e.message);
    }
  }
  ```

### removeDeathRecipient<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [unregisterDeathRecipient](#unregisterdeathrecipient9-1) instead.

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

Removes the callback used to receive death notifications of the remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type                             | Mandatory| Description                             |
| --------- | --------------------------------- | ---- | --------------------------------- |
| recipient | [DeathRecipient](#deathrecipient) | Yes  | Callback to remove.               |
| flags     | number                            | Yes  | Flag of the death notification. This parameter is reserved. It is set to **0**.|

**Return value**

| Type   | Description                                    |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if the callback is removed; returns **false** otherwise.|

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **removeDeathRecipient()** of the proxy object is called to remove the callback used to receive the death notification of the remote object.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  let deathRecipient = new MyDeathRecipient();
  if (proxy != undefined) {
    proxy.addDeathRecipient(deathRecipient, 0);
    proxy.removeDeathRecipient(deathRecipient, 0);
  }
  ```

### getDescriptor<sup>9+</sup>

getDescriptor(): string

Obtains the interface descriptor (which is a string) of this object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| string | Interface descriptor obtained.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900007  | communication failed.              |
| 1900008  | The proxy or remote object is invalid. |

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```
The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **getDescriptor()** of the proxy object is called to obtain the interface descriptor of the object.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  if (proxy != undefined) {
    try {
      let descriptor: string = proxy.getDescriptor();
      hilog.info(0x0000, 'testTag', 'RpcClient: descriptor is ' + descriptor);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'rpc get interface descriptor fail, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'rpc get interface descriptor fail, errorMessage ' + e.message);
    }
  }
  ```

### getInterfaceDescriptor<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [getDescriptor](#getdescriptor9-1) instead.

getInterfaceDescriptor(): string

Obtains the interface descriptor of this proxy object.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| string | Interface descriptor obtained.|

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **getInterfaceDescriptor()** of the proxy object is called to obtain the interface descriptor of the current proxy object.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  if (proxy != undefined) {
    let descriptor: string = proxy.getInterfaceDescriptor();
    hilog.info(0x0000, 'testTag', 'RpcClient: descriptor is ' + descriptor);
  }
  ```

### isObjectDead

isObjectDead(): boolean

Checks whether the **RemoteObject** is dead.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Returns **true** if **RemoteObject** is dead; returns **false** otherwise.|

**Example**

  ```ts
  // If the FA model is used, import featureAbility from @kit.AbilityKit.
  // import { featureAbility } from '@kit.AbilityKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // Use this method to connect to the ability for the FA model.
  // FA.connectAbility(want,connect);

  // Save the connection ID, which will be used for the subsequent service disconnection.
  let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
  // Save the connection ID, which will be used for the subsequent service disconnection.
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

The proxy object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. Then, **isObjectDead()** of the proxy object is called to check whether this object is dead.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  if (proxy != undefined) {
    let isDead: boolean = proxy.isObjectDead();
    hilog.info(0x0000, 'testTag', 'RpcClient: isObjectDead is ' + isDead);
  }
  ```

## MessageOption

Defines the options used to construct the **MessageOption** object.

**System capability**: SystemCapability.Communication.IPC.Core

| Name         | Value       | Description                                                       |
| ------------- | --------- | ----------------------------------------------------------- |
| TF_SYNC       | 0 (0x00)  | Synchronous call.                                             |
| TF_ASYNC      | 1 (0x01)  | Asynchronous call.                                             |
| TF_ACCEPT_FDS | 16 (0x10) | Indication to **sendMessageRequest<sup>9+</sup>** for returning the file descriptor.|
| TF_WAIT_TIME  | 8 (0x8)   | RPC wait time, in seconds. This parameter cannot be used in IPC.                                    |

### constructor<sup>9+</sup>

constructor(async?: boolean)

A constructor used to create a **MessageOption** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| async  | boolean | No  | Whether to execute the call asynchronously. The value **true** means to execute the call asynchronously; the value **false** means to execute the call synchronously. The default value is **synchronous**.|

**Example**

  ```ts
  class TestRemoteObject extends rpc.MessageOption {
    constructor(async: boolean) {
      super(async);
    }
  }
  ```

### constructor

constructor(syncFlags?: number, waitTime?: number)

A constructor used to create a **MessageOption** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name   | Type  | Mandatory| Description                                         |
| --------- | ------ | ---- | --------------------------------------------- |
| syncFlags | number | No  | Call flag, which can be synchronous or asynchronous. The default value is **synchronous**.       |
| waitTime  | number | No  | Maximum wait time for an RPC call. The default value is **TF_WAIT_TIME**.|

**Example**

  ```ts
  class TestRemoteObject extends rpc.MessageOption {
    constructor(syncFlags?: number,waitTime?: number) {
      super(syncFlags,waitTime);
    }
  }
  ```
### isAsync<sup>9+</sup>

isAsync(): boolean

Checks whether **SendMessageRequest** is called synchronously or asynchronously.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type   | Description                                    |
| ------- | ---------------------------------------- |
| boolean | Returns **true** if **SendMessageRequest** is called asynchronously; returns **false** if it is called synchronously.|

**Example**

  ```ts
  let option = new rpc.MessageOption();
  option.isAsync();
  ```

### setAsync<sup>9+</sup>

setAsync(async: boolean): void

Sets the calling flag in **SendMessageRequest**.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type   | Mandatory| Description                                             |
| ------ | ------- | ---- | ------------------------------------------------- |
| async  | boolean | Yes  | Whether to execute the call asynchronously. The value **true** means to execute the call asynchronously; the value **false** means to execute the call synchronously.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let option = new rpc.MessageOption();
  option.setAsync(true);
  hilog.info(0x0000, 'testTag', 'Set asynchronization flag');
  ```

### getFlags

getFlags(): number

Obtains the call flag, which can be synchronous or asynchronous.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| number | Call mode obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let option = new rpc.MessageOption();
    hilog.info(0x0000, 'testTag', 'create object successfully');
    let flog = option.getFlags();
    hilog.info(0x0000, 'testTag', 'run getFlags success, flog is ' + flog);
    option.setFlags(1)
    hilog.info(0x0000, 'testTag', 'run setFlags success');
    let flog2 = option.getFlags();
    hilog.info(0x0000, 'testTag', 'run getFlags success, flog2 is ' + flog2);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### setFlags

setFlags(flags: number): void

Sets the call flag, which can be synchronous or asynchronous.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| flags  | number | Yes  | Call flag to set.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let option = new rpc.MessageOption();
    option.setFlags(1)
    hilog.info(0x0000, 'testTag', 'run setFlags success');
    let flog = option.getFlags();
    hilog.info(0x0000, 'testTag', 'run getFlags success, flog is ' + flog);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getWaitTime

getWaitTime(): number

Obtains the maximum wait time for this RPC call.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description             |
| ------ | ----------------- |
| number | Maximum wait time obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let option = new rpc.MessageOption();
    let time = option.getWaitTime();
    hilog.info(0x0000, 'testTag', 'run getWaitTime success, time is ' + time);
    option.setWaitTime(16);
    let time2 = option.getWaitTime();
    hilog.info(0x0000, 'testTag', 'run getWaitTime success, time is ' + time2);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### setWaitTime

setWaitTime(waitTime: number): void

Sets the maximum wait time for this RPC call.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name  | Type  | Mandatory| Description                 |
| -------- | ------ | ---- | --------------------- |
| waitTime | number | Yes  | Maximum wait time to set. The upper limit is 3000 seconds.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let option = new rpc.MessageOption();
    option.setWaitTime(16);
    let time = option.getWaitTime();
    hilog.info(0x0000, 'testTag', 'run getWaitTime success, time is ' + time);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

## IPCSkeleton

Obtains IPC context information, including the UID and PID, local and remote device IDs, and whether the method is invoked on the same device.

### getContextObject

static getContextObject(): IRemoteObject

Obtains the system capability manager. This API is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type                           | Description                |
| ------------------------------- | -------------------- |
| [IRemoteObject](#iremoteobject) | System capability manager obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let samgr = rpc.IPCSkeleton.getContextObject();
  hilog.info(0x0000, 'testTag', 'RpcServer: getContextObject result: ' + samgr);
  ```

### getCallingPid

static getCallingPid(): number

Obtains the PID of the caller. This API is a static method, which is invoked by the **RemoteObject** object in the **onRemoteRequest** method. If this method is not invoked in the IPC context (**onRemoteRequest**), the PID of the process will be returned.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description             |
| ------ | ----------------- |
| number | PID of the caller.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      let callerPid = rpc.IPCSkeleton.getCallingPid();
      hilog.info(0x0000, 'testTag', 'RpcServer: getCallingPid result: ' + callerPid);
      return true;
    }
 }
  ```

### getCallingUid

static getCallingUid(): number

Obtains the UID of the caller. This API is a static method, which is invoked by the **RemoteObject** object in the **onRemoteRequest** method. If this method is not invoked in the IPC context (**onRemoteRequest**), the UID of the process will be returned.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description             |
| ------ | ----------------- |
| number | UID of the caller.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      let callerUid = rpc.IPCSkeleton.getCallingUid();
      hilog.info(0x0000, 'testTag', 'RpcServer: getCallingUid result: ' + callerUid);
      return true;
    }
  }
  ```

### getCallingTokenId<sup>8+</sup>

static getCallingTokenId(): number

Obtains the caller's token ID, which is used to verify the caller identity.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description                 |
| ------ | --------------------- |
| number | Token ID of the caller obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();
      hilog.info(0x0000, 'testTag', 'RpcServer: getCallingTokenId result: ' + callerTokenId);
      return true;
    }
  }
  ```

### getCallingDeviceID

static getCallingDeviceID(): string

Obtains the ID of the device hosting the caller's process. This API is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| string | Device ID obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      let callerDeviceID = rpc.IPCSkeleton.getCallingDeviceID();
      hilog.info(0x0000, 'testTag', 'RpcServer: callerDeviceID is ' + callerDeviceID);
      return true;
    }
  }
  ```

### getLocalDeviceID

static getLocalDeviceID(): string

Obtains the local device ID. This API is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| string | Local device ID obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      let localDeviceID = rpc.IPCSkeleton.getLocalDeviceID();
      hilog.info(0x0000, 'testTag', 'RpcServer: localDeviceID is ' + localDeviceID);
      return true;
    }
  }
  ```

### isLocalCalling

static isLocalCalling(): boolean

Checks whether the peer process is a process of the local device. This API is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type   | Description                                              |
| ------- | -------------------------------------------------- |
| boolean | Returns **true** if the local and peer processes are on the same device; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      let isLocalCalling = rpc.IPCSkeleton.isLocalCalling();
      hilog.info(0x0000, 'testTag', 'RpcServer: isLocalCalling is ' + isLocalCalling);
      return true;
    }
  }
  ```

### flushCmdBuffer<sup>9+</sup>

static flushCmdBuffer(object: IRemoteObject): void

Flushes all suspended commands from the specified **RemoteProxy** to the corresponding **RemoteObject**. This API is a static method. You are advised to call this API before performing any sensitive operation.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type                           | Mandatory| Description               |
| ------ | ------------------------------- | ---- | ------------------- |
| object | [IRemoteObject](#iremoteobject) | Yes  | **RemoteProxy** specified. |

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
  }
  let remoteObject = new TestRemoteObject("aaa");
  try {
    rpc.IPCSkeleton.flushCmdBuffer(remoteObject);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'proxy flushCmdBuffer fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'proxy flushCmdBuffer fail, errorMessage ' + e.message);
  }
  ```

### flushCommands<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [flushCmdBuffer](#flushcmdbuffer9) instead.

static flushCommands(object: IRemoteObject): number

Flushes all suspended commands from the specified **RemoteProxy** to the corresponding **RemoteObject**. This API is a static method. You are advised to call this API before performing any sensitive operation.

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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
  hilog.info(0x0000, 'testTag', 'RpcServer: flushCommands result: ' + ret);
  ```

### resetCallingIdentity

static resetCallingIdentity(): string

Resets the UID and PID of the remote user to those of the local user. This API is a static method and is used in scenarios such as identity authentication.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| string | String containing the UID and PID of the remote user.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      let callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();
      hilog.info(0x0000, 'testTag', 'RpcServer: callingIdentity is ' + callingIdentity);
      return true;
    }
  }
  ```

### restoreCallingIdentity<sup>9+</sup>

static restoreCallingIdentity(identity: string): void

Restores the UID and PID of the remote user. This API is a static method. It is usually called after **resetCallingIdentity**, and the UID and PID of the remote user returned by **resetCallingIdentity** are required.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name  | Type  | Mandatory| Description                                                              |
| -------- | ------ | ---- | ------------------------------------------------------------------ |
| identity | string | Yes  | String containing the remote user's UID and PID, which are returned by **resetCallingIdentity**.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The string length exceeds 40960 bytes; <br> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      let callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();
      hilog.info(0x0000, 'testTag', 'RpcServer: callingIdentity is ' + callingIdentity);
      rpc.IPCSkeleton.restoreCallingIdentity(callingIdentity);
      return true;
    }
  }
  ```

### setCallingIdentity<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [restoreCallingIdentity](#restorecallingidentity9) instead.

static setCallingIdentity(identity: string): boolean

Sets the UID and PID of the remote user. This API is a static method. It is usually called after **resetCallingIdentity**, and the UID and PID of the remote user returned by **resetCallingIdentity** are required.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name  | Type  | Mandatory| Description                                                              |
| -------- | ------ | ---- | ------------------------------------------------------------------ |
| identity | string | Yes  | String containing the remote user's UID and PID, which are returned by **resetCallingIdentity**.|

**Return value**

| Type   | Description                            |
| ------- | ---------------------------------|
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      let callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();
      hilog.info(0x0000, 'testTag', 'RpcServer: callingIdentity is ' + callingIdentity);
      let ret = rpc.IPCSkeleton.setCallingIdentity(callingIdentity);
      hilog.info(0x0000, 'testTag', 'RpcServer: setCallingIdentity is ' + ret);
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

>**NOTE**<br>This API is deprecated since API version 8. Use [sendMessageRequest](#sendmessagerequest9-4) instead.

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a promise will be fulfilled immediately and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type                                     | Mandatory| Description                                                                                  |
| ------- | ----------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| code    | number                                    | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
| reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
| options | [MessageOption](#messageoption)           | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the message is sent successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
    hilog.info(0x0000, 'testTag', 'sendRequest got result');
    let msg = reply.readString();
    hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
  } else {
    hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest failed');
  }
  hilog.info(0x0000, 'testTag', 'RPCTest: sendRequest ends, reclaim parcel');
  data.reclaim();
  reply.reclaim();
  ```

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise&lt;RequestResult&gt;

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a promise will be fulfilled immediately and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a promise will be fulfilled when the response to **sendMessageRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type                                | Mandatory| Description                                                                                  |
| ------- | ------------------------------------ | ---- | -------------------------------------------------------------------------------------- |
| code    | number                               | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data    | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object holding the data to send.                                           |
| reply   | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that receives the response.                                                   |
| options | [MessageOption](#messageoption)      | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

| Type                                           | Description                                     |
| ----------------------------------------------- | ----------------------------------------- |
| Promise&lt;[RequestResult](#requestresult9)&gt; | Promise used to return a **RequestResult** instance.|


**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.Failed to obtain the passed object instance. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
    .then((result: rpc.RequestResult) => {
      if (result.errCode === 0) {
        hilog.info(0x0000, 'testTag', 'sendMessageRequest got result');
        let num = result.reply.readInt();
        let msg = result.reply.readString();
        hilog.info(0x0000, 'testTag', 'RPCTest: reply num: ' + num);
        hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
      } else {
        hilog.error(0x0000, 'testTag', 'RPCTest: sendMessageRequest failed, errCode: ' + result.errCode);
      }
    }).catch((e: Error) => {
      hilog.error(0x0000, 'testTag', 'RPCTest: sendMessageRequest failed, message: ' + e.message);
    }).finally (() => {
      hilog.info(0x0000, 'testTag', 'RPCTest: sendMessageRequest ends, reclaim parcel');
      data.reclaim();
      reply.reclaim();
    });
  ```

### sendRequest<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [sendMessageRequest](#sendmessagerequest9-4) instead.

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a promise will be fulfilled immediately and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a promise will be fulfilled when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type                                     | Mandatory| Description                                                                                  |
| ------- | ----------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| code    | number                                    | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data    | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object holding the data to send.                                             |
| reply   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that receives the response.                                                     |
| options | [MessageOption](#messageoption)           | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                                                  |

**Return value**

| Type                                                        | Description                                         |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | Promise used to return a **sendRequestResult** instance.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
  let a = testRemoteObject.sendRequest(1, data, reply, option) as Object;
  let b = a as Promise<rpc.SendRequestResult>;
  b.then((result: rpc.SendRequestResult) => {
    if (result.errCode === 0) {
      hilog.info(0x0000, 'testTag', 'sendRequest got result');
      let num = result.reply.readInt();
      let msg = result.reply.readString();
      hilog.info(0x0000, 'testTag', 'RPCTest: reply num: ' + num);
      hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
    } else {
      hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest failed, errCode: ' + result.errCode);
    }
  }).catch((e: Error) => {
    hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest failed, message: ' + e.message);
  }).finally (() => {
    hilog.info(0x0000, 'testTag', 'RPCTest: sendRequest ends, reclaim parcel');
    data.reclaim();
    reply.reclaim();
  });
  ```

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback&lt;RequestResult&gt;): void

Sends a **MessageSequence** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a callback will be called immediately, and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a callback will be invoked when the response to **sendMessageRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name       | Type                                                 | Mandatory| Description                                                        |
| ------------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| code          | number                                                | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data          | [MessageSequence](#messagesequence9)                  | Yes  | **MessageSequence** object holding the data to send.                 |
| reply         | [MessageSequence](#messagesequence9)                  | Yes  | **MessageSequence** object that receives the response.                         |
| options       | [MessageOption](#messageoption)                       | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                        |
| callback      | AsyncCallback&lt;[RequestResult](#requestresult9)&gt; | Yes  | Callback for receiving the sending result.                                        |


**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.Failed to obtain the passed object instance. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
  }
  function sendRequestCallback(err: BusinessError, result: rpc.RequestResult) {
    if (result.errCode === 0) {
      hilog.info(0x0000, 'testTag', 'sendRequest got result');
      let num = result.reply.readInt();
      let msg = result.reply.readString();
      hilog.info(0x0000, 'testTag', 'RPCTest: reply num: ' + num);
      hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
    } else {
      hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest failed, errCode: ' + result.errCode);
    }
    hilog.info(0x0000, 'testTag', 'RPCTest: sendRequest ends, reclaim parcel');
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

### sendRequest<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [sendMessageRequest](#sendmessagerequest9-5) instead.

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

Sends a **MessageParcel** message to the remote process in synchronous or asynchronous mode. If asynchronous mode is set in **options**, a callback will be called immediately, and the reply message is empty. The specific reply needs to be obtained from the callback on the service side. If synchronous mode is set in **options**, a callback will be invoked when the response to **sendRequest** is returned, and the reply message contains the returned information.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                                        |
| ------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| code          | number                                                       | Yes  | Message code (1-16777215) called by the request, which is determined by the communication parties. If the method is generated by an IDL tool, the message code is automatically generated by the IDL tool.|
| data          | [MessageParcel](#messageparceldeprecated)                    | Yes  | **MessageParcel** object holding the data to send.                   |
| reply         | [MessageParcel](#messageparceldeprecated)                    | Yes  | **MessageParcel** object that receives the response.                           |
| options       | [MessageOption](#messageoption)                              | Yes  | Request sending mode, which can be synchronous (default) or asynchronous.                        |
| callback      | AsyncCallback&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | Yes  | Callback for receiving the sending result.                                        |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
  function sendRequestCallback(err: BusinessError, result: rpc.SendRequestResult) {
    if (result.errCode === 0) {
      hilog.info(0x0000, 'testTag', 'sendRequest got result');
      let num = result.reply.readInt();
      let msg = result.reply.readString();
      hilog.info(0x0000, 'testTag', 'RPCTest: reply num: ' + num);
      hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);
    } else {
      hilog.error(0x0000, 'testTag', 'RPCTest: sendRequest failed, errCode: ' + result.errCode);
    }
    hilog.info(0x0000, 'testTag', 'RPCTest: sendRequest ends, reclaim parcel');
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

### onRemoteMessageRequest<sup>9+</sup>

onRemoteMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): boolean | Promise\<boolean>

> **NOTE**
>
>* You are advised to overload **onRemoteMessageRequest** preferentially, which implements synchronous and asynchronous message processing.
>* If both **onRemoteRequest()** and **onRemoteMessageRequest()** are overloaded, only the onRemoteMessageRequest() takes effect.

Called to return a response to **sendMessageRequest()**. The server processes the request synchronously or asynchronously and returns the result in this API.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type                                | Mandatory| Description                                     |
| ------ | ------------------------------------ | ---- | ----------------------------------------- |
| code   | number                               | Yes  | Service request code sent by the remote end.                   |
| data   | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object that holds the parameters called by the client.|
| reply  | [MessageSequence](#messagesequence9) | Yes  | **MessageSequence** object to which the result is written.          |
| options | [MessageOption](#messageoption)      | Yes  | Whether the operation is synchronous or asynchronous.                 |

**Return value**

| Type             | Description                                                                                           |
| ----------------- | ----------------------------------------------------------------------------------------------- |
| boolean           | Returns a Boolean value if the request is processed synchronously in **onRemoteMessageRequest**. The value **true** means the operation is successful; the value **false** means the opposite.|
| Promise\<boolean> | Returns a promise object if the request is processed asynchronously in **onRemoteMessageRequest**.                                |

**Example**: Overload **onRemoteMessageRequest** to process requests synchronously.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }

    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      if (code === 1) {
        hilog.info(0x0000, 'testTag', 'RpcServer: sync onRemoteMessageRequest is called');
        return true;
      } else {
        hilog.error(0x0000, 'testTag', 'RpcServer: unknown code: ' + code);
        return false;
      }
    }
  }
  ```

  **Example**: Overload **onRemoteMessageRequest** to process requests asynchronously.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }

    async onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): Promise<boolean> {
      if (code === 1) {
        hilog.info(0x0000, 'testTag', 'RpcServer: async onRemoteMessageRequest is called');
      } else {
        hilog.error(0x0000, 'testTag', 'RpcServer: unknown code: ' + code);
        return false;
      }
      await new Promise((resolve: (data: rpc.RequestResult) => void) => {
        setTimeout(resolve, 100);
      })
      return true;
    }
  }
  ```

**Example**: Overload **onRemoteMessageRequest** and **onRemoteRequest** to process requests synchronously.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }

    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
       if (code === 1) {
          hilog.info(0x0000, 'testTag', 'RpcServer: sync onRemoteMessageRequest is called');
          return true;
       } else {
          hilog.error(0x0000, 'testTag', 'RpcServer: unknown code: ' + code);
          return false;
       }
    }
      // Only onRemoteMessageRequest is executed.
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      if (code === 1) {
        hilog.info(0x0000, 'testTag', 'RpcServer: async onRemoteMessageRequest is called');
      } else {
        hilog.error(0x0000, 'testTag', 'RpcServer: unknown code: ' + code);
        return false;
      }
      return true;
    }
  }
  ```

  **Example**: Overload **onRemoteMessageRequest** and **onRemoteRequest** to process requests asynchronously.

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }

    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      if (code === 1) {
        hilog.info(0x0000, 'testTag', 'RpcServer: sync onRemoteRequest is called');
        return true;
      } else {
        hilog.error(0x0000, 'testTag', 'RpcServer: unknown code: ' + code);
        return false;
      }
    }
    // Only onRemoteMessageRequest is executed.
    async onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): Promise<boolean> {
      if (code === 1) {
        hilog.info(0x0000, 'testTag', 'RpcServer: async onRemoteMessageRequest is called');
      } else {
        hilog.error(0x0000, 'testTag', 'RpcServer: unknown code: ' + code);
        return false;
      }
      await new Promise((resolve: (data: rpc.RequestResult) => void) => {
        setTimeout(resolve, 100);
      })
      return true;
    }
  }
  ```

### onRemoteRequest<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [onRemoteMessageRequest](#onremotemessagerequest9) instead.

onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

Called to return a response to **sendRequest()**. The server processes the request and returns a response in this function.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type                                     | Mandatory| Description                                   |
| ------ | ----------------------------------------- | ---- | --------------------------------------- |
| code   | number                                    | Yes  | Service request code sent by the remote end.                 |
| data   | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object that holds the parameters called by the client.|
| reply  | [MessageParcel](#messageparceldeprecated) | Yes  | **MessageParcel** object carrying the result.          |
| options | [MessageOption](#messageoption)           | Yes  | Whether the operation is synchronous or asynchronous.               |

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      if (code === 1) {
        hilog.info(0x0000, 'testTag', 'RpcServer: onRemoteRequest called');
        return true;
      } else {
        hilog.error(0x0000, 'testTag', 'RpcServer: unknown code: ' + code);
        return false;
      }
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  hilog.info(0x0000, 'testTag', 'RpcServer: getCallingUid: ' + testRemoteObject.getCallingUid());
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  hilog.info(0x0000, 'testTag', 'RpcServer: getCallingPid: ' + testRemoteObject.getCallingPid());
  ```

### getLocalInterface<sup>9+</sup>

getLocalInterface(descriptor: string): IRemoteBroker

Obtains the string of the interface descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name    | Type  | Mandatory| Description                |
| ---------- | ------ | ---- | -------------------- |
| descriptor | string | Yes  | Interface descriptor.|

**Return value**

| Type         | Description                                         |
| ------------- | --------------------------------------------- |
| IRemoteBroker | **IRemoteBroker** object bound to the specified interface token.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The string length exceeds 40960 bytes; <br> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
      this.modifyLocalInterface(this, descriptor);
    }
    registerDeathRecipient(recipient: MyDeathRecipient, flags: number) {
      // Implement the method logic based on service requirements.
    }
    unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number) {
      // Implement the method logic based on service requirements.
    }
    isObjectDead(): boolean {
      return false;
    }
    asObject(): rpc.IRemoteObject {
      return this;
    }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  try {
    testRemoteObject.getLocalInterface("testObject");
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorMessage ' + e.message);
  }
  ```

### queryLocalInterface<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [getLocalInterface](#getlocalinterface9-2) instead.

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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
  testRemoteObject.queryLocalInterface("testObject");
  ```

### getDescriptor<sup>9+</sup>

getDescriptor(): string

Obtains the interface descriptor of this object. The interface descriptor is a string.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| string | Interface descriptor obtained.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900008  | The proxy or remote object is invalid. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    registerDeathRecipient(recipient: MyDeathRecipient, flags: number) {
      // Implement the method logic based on service requirements.
    }
    unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number) {
      // Implement the method logic based on service requirements.
    }
    isObjectDead(): boolean {
      return false;
    }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  try {
    let descriptor = testRemoteObject.getDescriptor();
    hilog.info(0x0000, 'testTag', 'RpcServer: descriptor is ' + descriptor);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorMessage ' + e.message);
  }
  ```

### getInterfaceDescriptor<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [getDescriptor](#getdescriptor9-2) instead.

getInterfaceDescriptor(): string

Obtains the interface descriptor.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type  | Description            |
| ------ | ---------------- |
| string | Interface descriptor obtained.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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
  hilog.info(0x0000, 'testTag', 'RpcServer: descriptor is: ' + descriptor);
  ```

### modifyLocalInterface<sup>9+</sup>

modifyLocalInterface(localInterface: IRemoteBroker, descriptor: string): void

Binds an interface descriptor to an **IRemoteBroker** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name        | Type                           | Mandatory| Description                                 |
| -------------- | ------------------------------- | ---- | ------------------------------------- |
| localInterface | [IRemoteBroker](#iremotebroker) | Yes  | **IRemoteBroker** object.  |
| descriptor     | string                          | Yes  | Interface descriptor.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The string length exceeds 40960 bytes; <br> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
      try {
        this.modifyLocalInterface(this, descriptor);
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        hilog.error(0x0000, 'testTag', ' rpc attach local interface fail, errorCode ' + e.code);
        hilog.error(0x0000, 'testTag', ' rpc attach local interface fail, errorMessage ' + e.message);
      }
    }
    registerDeathRecipient(recipient: MyDeathRecipient, flags: number) {
      // Implement the method logic based on service requirements.
    }
    unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number) {
      // Implement the method logic based on service requirements.
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

### attachLocalInterface<sup>(deprecated)</sup>

>**NOTE**<br>This API is deprecated since API version 9. Use [modifyLocalInterface](#modifylocalinterface9) instead.

attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void

Binds an interface descriptor to an **IRemoteBroker** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name        | Type                           | Mandatory| Description                                 |
| -------------- | ------------------------------- | ---- | ------------------------------------- |
| localInterface | [IRemoteBroker](#iremotebroker) | Yes  | **IRemoteBroker** object.  |
| descriptor     | string                          | Yes  | Interface descriptor.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
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

**System capability**: SystemCapability.Communication.IPC.Core

The table below describes the protection types of the mapped memory.

| Name      | Value | Description              |
| ---------- | --- | ------------------ |
| PROT_EXEC  | 4   | The mapped memory is executable.  |
| PROT_NONE  | 0   | The mapped memory is inaccessible.|
| PROT_READ  | 1   | The mapped memory is readable.    |
| PROT_WRITE | 2   | The mapped memory is writeable.    |

### create<sup>9+</sup>

static create(name: string, size: number): Ashmem

Creates an **Ashmem** object with the specified name and size. This API is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description                        |
| ------ | ------ | ---- | ---------------------------- |
| name   | string | Yes  | Name of the **Ashmem** object to create.  |
| size   | number | Yes  | Size (in bytes) of the **Ashmem** object to create.|

**Return value**

| Type              | Description                                          |
| ------------------ | ---------------------------------------------- |
| [Ashmem](#ashmem8) | Returns the **Ashmem** object if it is created successfully; returns null otherwise.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The Ashmem name passed is empty; <br> 4.The Ashmem size passed is less than or equal to 0. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let ashmem: rpc.Ashmem | undefined = undefined;
  try {
    ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let size = ashmem.getAshmemSize();
    hilog.info(0x0000, 'testTag', 'RpcTest: get ashemm by create: ' + ashmem + ' size is ' + size);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc creat ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc creat ashmem  fail, errorMessage ' + e.message);
  }
  ```

### createAshmem<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [create](#create9) instead.

static createAshmem(name: string, size: number): Ashmem

Creates an **Ashmem** object with the specified name and size. This API is a static method.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type  | Mandatory| Description                        |
| ------ | ------ | ---- | ---------------------------- |
| name   | string | Yes  | Name of the **Ashmem** object to create.  |
| size   | number | Yes  | Size (in bytes) of the **Ashmem** object to create.|

**Return value**

| Type              | Description                                          |
| ------------------ | ---------------------------------------------- |
| [Ashmem](#ashmem8) | Returns the **Ashmem** object if it is created successfully; returns null otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  hilog.info(0x0000, 'testTag', 'RpcTest: get ashemm by createAshmem: ' + ashmem + ' size is ' + size);
  ```

### create<sup>9+</sup>

static create(ashmem: Ashmem): Ashmem

Creates an **Ashmem** object by copying the file descriptor of an existing **Ashmem** object. The two **Ashmem** objects point to the same shared memory region.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type              | Mandatory| Description                |
| ------ | ------------------ | ---- | -------------------- |
| ashmem | [Ashmem](#ashmem8) | Yes  | Existing **Ashmem** object.|

**Return value**

| Type              | Description                  |
| ------------------ | ---------------------- |
| [Ashmem](#ashmem8) | **Ashmem** object created.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The passed parameter is not an Ahmem object; <br> 3.The ashmem instance for obtaining packaging is empty. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let ashmem2 = rpc.Ashmem.create(ashmem);
    let size = ashmem2.getAshmemSize();
    hilog.info(0x0000, 'testTag', 'RpcTest: get ashemm by create: ' + ashmem2 + ' size is ' + size);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc creat ashmem from existing fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc creat ashmem from existing fail, errorMessage ' + e.message);
  }
  ```

### createAshmemFromExisting<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [create](#create9-1) instead.

static createAshmemFromExisting(ashmem: Ashmem): Ashmem

Creates an **Ashmem** object by copying the file descriptor of an existing **Ashmem** object. The two **Ashmem** objects point to the same shared memory region.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type              | Mandatory| Description                |
| ------ | ------------------ | ---- | -------------------- |
| ashmem | [Ashmem](#ashmem8) | Yes  | Existing **Ashmem** object.|

**Return value**

| Type              | Description                  |
| ------------------ | ---------------------- |
| [Ashmem](#ashmem8) | **Ashmem** object created.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  let ashmem2 = rpc.Ashmem.createAshmemFromExisting(ashmem);
  let size = ashmem2.getAshmemSize();
  hilog.info(0x0000, 'testTag', 'RpcTest: get ashemm by createAshmemFromExisting: ' + ashmem2 + ' size is ' + size);
  ```

### closeAshmem<sup>8+</sup>

closeAshmem(): void

Closes this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```ts
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.closeAshmem();
  ```

### unmapAshmem<sup>8+</sup>

unmapAshmem(): void

Deletes the mappings for the specified address range of this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Example**

  ```ts
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

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  hilog.info(0x0000, 'testTag', 'RpcTest: get ashmem is ' + ashmem + ' size is ' + size);
  ```

### mapTypedAshmem<sup>9+</sup>

mapTypedAshmem(mapType: number): void

Creates the shared file mapping on the virtual address space of this process. The size of the mapping region is specified by this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type  | Mandatory| Description                          |
| ------- | ------ | ---- | ------------------------------ |
| mapType | number | Yes  | Protection level of the memory region to which the shared file is mapped.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect;  <br> 2.The parameter type does not match; <br> 3.The passed mapType exceeds the maximum protection level. |
| 1900001  | Failed to call mmap. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  try {
    ashmem.mapTypedAshmem(ashmem.PROT_READ | ashmem.PROT_WRITE);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc map ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc map ashmem fail, errorMessage ' + e.message);
  }
  ```

### mapAshmem<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [mapTypedAshmem](#maptypedashmem9) instead.

mapAshmem(mapType: number): boolean

Creates the shared file mapping on the virtual address space of this process. The size of the mapping region is specified by this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name | Type  | Mandatory| Description                          |
| ------- | ------ | ---- | ------------------------------ |
| mapType | number | Yes  | Protection level of the memory region to which the shared file is mapped.|

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the mapping is created; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  let mapReadAndWrite = ashmem.mapAshmem(ashmem.PROT_READ | ashmem.PROT_WRITE);
  hilog.info(0x0000, 'testTag', 'RpcTest: map ashmem result is ' + mapReadAndWrite);
  ```

### mapReadWriteAshmem<sup>9+</sup>

mapReadWriteAshmem(): void

Maps the shared file to the readable and writable virtual address space of the process.

**System capability**: SystemCapability.Communication.IPC.Core

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900001  | Failed to call mmap. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  try {
    ashmem.mapReadWriteAshmem();
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc map read and write ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc map read and write ashmem fail, errorMessage ' + e.message);
  }
  ```

### mapReadAndWriteAshmem<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [mapReadWriteAshmem](#mapreadwriteashmem9) instead.

mapReadAndWriteAshmem(): boolean

Maps the shared file to the readable and writable virtual address space of the process.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the mapping is created; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadAndWriteAshmem();
  hilog.info(0x0000, 'testTag', 'RpcTest: map ashmem result is ' + mapResult);
  ```

### mapReadonlyAshmem<sup>9+</sup>

mapReadonlyAshmem(): void

Maps the shared file to the read-only virtual address space of the process.

**System capability**: SystemCapability.Communication.IPC.Core

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 1900001  | Failed to call mmap. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  try {
    ashmem.mapReadonlyAshmem();
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc map read and write ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc map read and write ashmem fail, errorMessage ' + e.message);
  }
  ```

### mapReadOnlyAshmem<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [mapReadonlyAshmem](#mapreadonlyashmem9) instead.

mapReadOnlyAshmem(): boolean

Maps the shared file to the read-only virtual address space of the process.

**System capability**: SystemCapability.Communication.IPC.Core

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the mapping is created; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadOnlyAshmem();
  hilog.info(0x0000, 'testTag', 'RpcTest: Ashmem mapReadOnlyAshmem result is ' + mapResult);
  ```

### setProtectionType<sup>9+</sup>

setProtectionType(protectionType: number): void

Sets the protection level of the memory region to which the shared file is mapped.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name        | Type  | Mandatory| Description              |
| -------------- | ------ | ---- | ------------------ |
| protectionType | number | Yes  | Protection type to set.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900002  | Failed to call ioctl. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  try {
    ashmem.setProtection(ashmem.PROT_READ);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc set protection type fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc set protection type fail, errorMessage ' + e.message);
  }
  ```

### setProtection<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [setProtectionType](#setprotectiontype9) instead.

setProtection(protectionType: number): boolean

Sets the protection level of the memory region to which the shared file is mapped.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name        | Type  | Mandatory| Description              |
| -------------- | ------ | ---- | ------------------ |
| protectionType | number | Yes  | Protection type to set.|

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  let result = ashmem.setProtection(ashmem.PROT_READ);
  hilog.info(0x0000, 'testTag', 'RpcTest: Ashmem setProtection result is ' + result);
  ```

### writeDataToAshmem<sup>11+</sup>

writeDataToAshmem(buf: ArrayBuffer, size: number, offset: number): void

Writes data to the shared file associated with this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type    | Mandatory| Description                                              |
| ------ | -------- | ---- | -------------------------------------------------- |
| buf    | ArrayBuffer | Yes  | Data to write.                            |
| size   | number   | Yes  | Size of the data to write.                                |
| offset | number   | Yes  | Start position of the data to write in the memory region associated with this **Ashmem** object.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.Failed to obtain arrayBuffer information. |
| 1900003  | Failed to write data to the shared memory. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let buffer = new ArrayBuffer(1024);
  let int32View = new Int32Array(buffer);
  for (let i = 0; i < int32View.length; i++) {
    int32View[i] = i * 2 + 1;
  }
  let size = buffer.byteLength;
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.mapReadWriteAshmem();
  try {
    ashmem.writeDataToAshmem(buffer, size, 0);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc write to ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc write to ashmem fail, errorMessage ' + e.message);
  }
  ```

### writeAshmem<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 9 and deprecated since API version 11. Use [writeDataToAshmem](#writedatatoashmem11) instead.

writeAshmem(buf: number[], size: number, offset: number): void

Writes data to the shared file associated with this **Ashmem** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Parameters**

| Name| Type    | Mandatory| Description                                              |
| ------ | -------- | ---- | -------------------------------------------------- |
| buf    | number[] | Yes  | Data to write.                            |
| size   | number   | Yes  | Size of the data to write.                                |
| offset | number   | Yes  | Start position of the data to write in the memory region associated with this **Ashmem** object.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match; <br> 3.The element does not exist in the array. |
| 1900003  | Failed to write data to the shared memory. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.mapReadWriteAshmem();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  try {
    ashmem.writeAshmem(ByteArrayVar, 5, 0);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc write to ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc write to ashmem fail, errorMessage ' + e.message);
  }
  ```

### writeToAshmem<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [writeDataToAshmem](#writedatatoashmem11) instead.

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

| Type   | Description                                                                         |
| ------- | ----------------------------------------------------------------------------- |
| boolean | Returns **true** if the data is written successfully; returns **false** otherwise.|

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadAndWriteAshmem();
  hilog.info(0x0000, 'testTag', 'RpcTest map ashmem result is ' + mapResult);
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);
  hilog.info(0x0000, 'testTag', 'RpcTest: write to Ashmem result is ' + writeResult);
  ```

### readDataFromAshmem<sup>11+</sup>

readDataFromAshmem(size: number, offset: number): ArrayBuffer

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
| ArrayBuffer | Data read.|

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900004  | Failed to read data from the shared memory. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let buffer = new ArrayBuffer(1024);
  let int32View = new Int32Array(buffer);
  for (let i = 0; i < int32View.length; i++) {
    int32View[i] = i * 2 + 1;
  }
  let size = buffer.byteLength;
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.mapReadWriteAshmem();
  try {
    ashmem.writeDataToAshmem(buffer, size, 0);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc write to ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc write to ashmem fail, errorMessage ' + e.message);
  }
  try {
    let readResult = ashmem.readDataFromAshmem(size, 0);
    let readInt32View = new Int32Array(readResult);
    hilog.info(0x0000, 'testTag', 'RpcTest: read from Ashmem result is ' + readInt32View);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc read from ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc read from ashmem fail, errorMessage ' + e.message);
  }
  ```

### readAshmem<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 9 and deprecated since API version 11. Use [readDataFromAshmem](#readdatafromashmem11) instead.

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

**Error codes**

For details about the error codes, see [RPC Error Codes](errorcode-rpc.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: <br> 1.The number of parameters is incorrect; <br> 2.The parameter type does not match. |
| 1900004  | Failed to read data from the shared memory. |

**Example**

  ```ts
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.mapReadWriteAshmem();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  ashmem.writeAshmem(ByteArrayVar, 5, 0);
  try {
    let readResult = ashmem.readAshmem(5, 0);
    hilog.info(0x0000, 'testTag', 'RpcTest: read from Ashmem result is ' + readResult);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc read from ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc read from ashmem fail, errorMessage ' + e.message);
  }
  ```

### readFromAshmem<sup>(deprecated)</sup>

>**NOTE**<br>This API is supported since API version 8 and deprecated since API version 9. Use [readDataFromAshmem](#readdatafromashmem11) instead.

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

 ``` ts
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadAndWriteAshmem();
  hilog.info(0x0000, 'testTag', 'RpcTest map ashmem result is ' + mapResult);
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);
  hilog.info(0x0000, 'testTag', 'RpcTest: write to Ashmem result is ' + writeResult);
  let readResult = ashmem.readFromAshmem(5, 0);
  hilog.info(0x0000, 'testTag', 'RpcTest: read to Ashmem result is ' + readResult);
 ```
