# @ohos.rpc (RPC通信)
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->

本模块提供进程间通信能力，包括设备内的进程间通信（IPC）和设备间的进程间通信（RPC），前者基于Binder驱动，后者基于软总线驱动。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块从API version 9开始支持异常返回功能。

## 导入模块

```
import { rpc } from '@kit.IPCKit';
```

## ErrorCode<sup>9+</sup>

从API version 9起，IPC支持异常返回功能。错误码对应数值及含义如下。

**系统能力**：SystemCapability.Communication.IPC.Core

  | 名称                                  | 值      | 说明                                          |
  | ------------------------------------- | ------- | --------------------------------------------- |
  | CHECK_PARAM_ERROR                     | 401     | 检查参数失败。                                |
  | OS_MMAP_ERROR                         | 1900001 | 执行系统调用mmap失败。                        |
  | OS_IOCTL_ERROR                        | 1900002 | 在共享内存文件描述符上执行系统调用ioctl失败。 |
  | WRITE_TO_ASHMEM_ERROR                 | 1900003 | 向共享内存写数据失败。                        |
  | READ_FROM_ASHMEM_ERROR                | 1900004 | 从共享内存读数据失败。                        |
  | ONLY_PROXY_OBJECT_PERMITTED_ERROR     | 1900005 | 只有proxy对象允许该操作。                     |
  | ONLY_REMOTE_OBJECT_PERMITTED_ERROR    | 1900006 | 只有remote对象允许该操作。                    |
  | COMMUNICATION_ERROR                   | 1900007 | 和远端对象进行进程间通信失败。                |
  | PROXY_OR_REMOTE_OBJECT_INVALID_ERROR  | 1900008 | 非法的代理对象或者远端对象。                  |
  | WRITE_DATA_TO_MESSAGE_SEQUENCE_ERROR  | 1900009 | 向MessageSequence写数据失败。                 |
  | READ_DATA_FROM_MESSAGE_SEQUENCE_ERROR | 1900010 | 读取MessageSequence数据失败。                 |
  | PARCEL_MEMORY_ALLOC_ERROR             | 1900011 | 序列化过程中内存分配失败。                    |
  | CALL_JS_METHOD_ERROR                  | 1900012 | 执行JS回调方法失败。                          |
  | OS_DUP_ERROR                          | 1900013 | 执行系统调用dup失败。                         |


## TypeCode<sup>12+</sup>

从API version 12起，IPC新增[writeArrayBuffer](#writearraybuffer12)和[readArrayBuffer](#readarraybuffer12)方法传递ArrayBuffer数据，传递数据时通过具体类型值来分辨业务是以哪一种TypedArray去进行数据的读写。类型码对应数值及含义如下。

**系统能力**：SystemCapability.Communication.IPC.Core

  | 名称                         | 值     | 说明                                          |
  | ---------------------------- | ------ | --------------------------------------------  |
  | INT8_ARRAY                   | 0      | TypedArray类型为INT8_ARRAY。                  |
  | UINT8_ARRAY                  | 1      | TypedArray类型为UINT8_ARRAY。                 |
  | INT16_ARRAY                  | 2      | TypedArray类型为INT16_ARRAY。                 |
  | UINT16_ARRAY                 | 3      | TypedArray类型为UINT16_ARRAY。                |
  | INT32_ARRAY                  | 4      | TypedArray类型为INT32_ARRAY。                 |
  | UINT32_ARRAY                 | 5      | TypedArray类型为UINT32_ARRAY。                |
  | FLOAT32_ARRAY                | 6      | TypedArray类型为FLOAT32_ARRAY。               |
  | FLOAT64_ARRAY                | 7      | TypedArray类型为FLOAT64_ARRAY。               |
  | BIGINT64_ARRAY               | 8      | TypedArray类型为BIGINT64_ARRAY。              |
  | BIGUINT64_ARRAY              | 9      | TypedArray类型为BIGUINT64_ARRAY。             |


## MessageSequence<sup>9+</sup>

  在RPC或IPC过程中，发送方可以使用MessageSequence提供的写方法，将待发送的数据以特定格式写入该对象。接收方可以使用MessageSequence提供的读方法从该对象中读取特定格式的数据。数据格式包括：基础类型及数组、IPC对象、接口描述符和自定义序列化对象。

### create<sup>9+</sup>

  static create(): MessageSequence

  静态方法，创建MessageSequence对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| [MessageSequence](#messagesequence9) | 返回创建的MessageSequence对象。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    hilog.info(0x0000, 'testTag', 'data is ' + data);

    // 当MessageSequence对象不再使用，由业务主动调用reclaim方法去释放资源。
    data.reclaim();
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### reclaim<sup>9+</sup>

reclaim(): void

释放不再使用的MessageSequence对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let reply = rpc.MessageSequence.create();
    reply.reclaim();
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeRemoteObject<sup>9+</sup>

writeRemoteObject(object: IRemoteObject): void

序列化远程对象并将其写入[MessageSequence](#messagesequence9)对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                            | 必填 | 说明                                      |
  | ------ | ------------------------------- | ---- | ----------------------------------------- |
  | object | [IRemoteObject](#iremoteobject) | 是   | 要序列化并写入MessageSequence的远程对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900008  | The proxy or remote object is invalid. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }

  try {
    let data = rpc.MessageSequence.create();
    let testRemoteObject = new TestRemoteObject("testObject");
    data.writeRemoteObject(testRemoteObject);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readRemoteObject<sup>9+</sup>

readRemoteObject(): IRemoteObject

从MessageSequence读取远程对象。此方法用于反序列化MessageSequence对象以生成IRemoteObject。远程对象按写入MessageSequence的顺序读取。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型                            | 说明               |
  | ------------------------------- | ------------------ |
  | [IRemoteObject](#iremoteobject) | 读取到的远程对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900008  | The proxy or remote object is invalid. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }

  try {
    let data = rpc.MessageSequence.create();
    let testRemoteObject = new TestRemoteObject("testObject");
    data.writeRemoteObject(testRemoteObject);
    let proxy = data.readRemoteObject();
    hilog.info(0x0000, 'testTag', 'readRemoteObject is ' + proxy);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeInterfaceToken<sup>9+</sup>

writeInterfaceToken(token: string): void

将接口描述符写入MessageSequence对象，远端对象可使用该信息校验本次通信。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明               |
  | ------ | ------ | ---- | ------------------ |
  | token  | string | 是   | 字符串类型描述符，其长度应小于40960字节。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes:<br/> 1.The number of parameters is incorrect;<br/> 2.The parameter type does not match;<br/> 3.The string length exceeds 40960 bytes;<br/> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeInterfaceToken("aaa");
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readInterfaceToken<sup>9+</sup>

readInterfaceToken(): string

从MessageSequence对象中读取接口描述符，接口描述符按写入MessageSequence的顺序读取，本地对象可使用该信息检验本次通信。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                     |
  | ------ | ------------------------ |
  | string | 返回读取到的接口描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeInterfaceToken("aaa");
    let interfaceToken = data.readInterfaceToken();
    hilog.info(0x0000, 'testTag', 'RpcServer: interfaceToken is ' + interfaceToken);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
```

### getSize<sup>9+</sup>

getSize(): number

获取当前创建的MessageSequence对象的数据大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                            |
  | ------ | ----------------------------------------------- |
  | number | 获取的MessageSequence实例的数据大小。以字节为单位。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    let size = data.getSize();
    hilog.info(0x0000, 'testTag', 'size is ' + size);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### getCapacity<sup>9+</sup>

getCapacity(): number

获取当前MessageSequence对象的容量大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明  |
  | ------ | ----- |
  | number | 获取的MessageSequence实例的容量大小。以字节为单位。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    let result = data.getCapacity();
    hilog.info(0x0000, 'testTag', 'capacity is ' + result);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### setSize<sup>9+</sup>

setSize(size: number): void

设置MessageSequence对象中包含的数据大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明   |
  | ------ | ------ | ---- | ------ |
  | size   | number | 是   | MessageSequence实例的数据大小。以字节为单位。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeString('Hello World');
    data.setSize(16);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### setCapacity<sup>9+</sup>

setCapacity(size: number): void

设置MessageSequence对象的存储容量。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                          |
  | ------ | ------ | ---- | --------------------------------------------- |
  | size   | number | 是   | MessageSequence实例的存储容量。以字节为单位。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |
  | 1900011  | Memory allocation failed. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.setCapacity(100);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### getWritableBytes<sup>9+</sup>

getWritableBytes(): number

获取MessageSequence的可写字节空间大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明   |
  | ------ | ------ |
  | number | 获取到的MessageSequence实例的可写字节空间。以字节为单位。 |

**示例：**

```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.setCapacity(100);
    let getWritableBytes = data.getWritableBytes();
    hilog.info(0x0000, 'testTag', 'RpcServer: getWritableBytes is ' + getWritableBytes);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
```

### getReadableBytes<sup>9+</sup>

getReadableBytes(): number

获取MessageSequence的可读字节空间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明    |
  | ------ | ------- |
  | number | 获取到的MessageSequence实例的可读字节空间。以字节为单位。 |

**示例：**

```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeString("hello world");
    let result = data.getReadableBytes();
    hilog.info(0x0000, 'testTag', 'RpcServer: getReadableBytes is ' + result);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
```

### getReadPosition<sup>9+</sup>

getReadPosition(): number

获取MessageSequence的读位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明   |
  | ------ | ------ |
  | number | 返回MessageSequence实例中的当前读取位置。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeString("hello world");
    let readPos = data.getReadPosition();
    hilog.info(0x0000, 'testTag', 'readPos is ' + readPos);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### getWritePosition<sup>9+</sup>

getWritePosition(): number

获取MessageSequence的写位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明  |
  | ------ | ----- |
  | number | 返回MessageSequence实例中的当前写入位置。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeInt(10);
    let bwPos = data.getWritePosition();
    hilog.info(0x0000, 'testTag', 'bwPos is ' + bwPos);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### rewindRead<sup>9+</sup>

rewindRead(pos: number): void

重新偏移读取位置到指定的位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明    |
  | ------ | ------ | ---- | ------- |
  | pos    | number | 是   | 开始读取数据的目标位置。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900010 | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeInt(12);
    data.writeString("sequence");
    let number = data.readInt();
    hilog.info(0x0000, 'testTag', 'number is ' + number);
    data.rewindRead(0);
    let number2 = data.readInt();
    hilog.info(0x0000, 'testTag', 'rewindRead is ' + number2);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### rewindWrite<sup>9+</sup>

rewindWrite(pos: number): void

重新偏移写位置到指定的位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明  |
  | ------ | ------ | ---- | ----- |
  | pos    | number | 是   | 开始写入数据的目标位置。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeInt(4);
    data.rewindWrite(0);
    data.writeInt(5);
    let number = data.readInt();
    hilog.info(0x0000, 'testTag', 'rewindWrite is: ' + number);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeByte<sup>9+</sup>

writeByte(val: number): void

将字节值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明  |
  | ------ | ------ | ---- | ----- |
  | val    | number | 是   | 要写入的字节值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------  |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeByte(2);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readByte<sup>9+</sup>

readByte(): number

从MessageSequence实例读取字节值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明  |
  | ------ | ----- |
  | number | 返回字节值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | --------  |
  | 1900010 | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeByte(2);
    let ret = data.readByte();
    hilog.info(0x0000, 'testTag', 'readByte is: ' +  ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeShort<sup>9+</sup>

writeShort(val: number): void

将短整数值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明 |
  | ------ | ------ | ---  | ---  |
  | val    | number | 是   | 要写入的短整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeShort(8);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readShort<sup>9+</sup>

readShort(): number

从MessageSequence实例读取短整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | number | 返回短整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeShort(8);
    let ret = data.readShort();
    hilog.info(0x0000, 'testTag', 'readShort is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeInt<sup>9+</sup>

writeInt(val: number): void

将整数值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeInt(10);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readInt<sup>9+</sup>

readInt(): number

从MessageSequence实例读取整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明         |
  | ------ | ------------ |
  | number | 返回整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeInt(10);
    let ret = data.readInt();
    hilog.info(0x0000, 'testTag', 'readInt is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeLong<sup>9+</sup>

writeLong(val: number): void

将长整数值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的长整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeLong(10000);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readLong<sup>9+</sup>

readLong(): number

从MessageSequence实例中读取长整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | number | 返回长整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeLong(10000);
    let ret = data.readLong();
    hilog.info(0x0000, 'testTag', 'readLong is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeFloat<sup>9+</sup>

writeFloat(val: number): void

将双精度浮点值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明  |
  | ------ | ------ | ---- | ----- |
  | val    | number | 是   | 要写入的双精度浮点值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeFloat(1.2);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readFloat<sup>9+</sup>

readFloat(): number

从MessageSequence实例中读取双精度浮点值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明         |
  | ------ | ------------ |
  | number | 返回双精度浮点值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeFloat(1.2);
    let ret = data.readFloat();
    hilog.info(0x0000, 'testTag', 'readFloat is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeDouble<sup>9+</sup>

writeDouble(val: number): void

将双精度浮点值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                   |
  | ------ | ------ | ---- | ---------------------- |
  | val    | number | 是   | 要写入的双精度浮点值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeDouble(10.2);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readDouble<sup>9+</sup>

readDouble(): number

从MessageSequence实例读取双精度浮点值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明               |
  | ------ | ------------------ |
  | number | 返回双精度浮点值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeDouble(10.2);
    let ret = data.readDouble();
    hilog.info(0x0000, 'testTag', 'readDouble is ' +  ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeBoolean<sup>9+</sup>

writeBoolean(val: boolean): void

将布尔值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型    | 必填 | 说明             |
  | ------ | ------- | ---- | ---------------- |
  | val    | boolean | 是   | 要写入的布尔值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeBoolean(false);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readBoolean<sup>9+</sup>

readBoolean(): boolean

从MessageSequence实例读取布尔值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                 |
  | ------- | -------------------- |
  | boolean | 返回读取到的布尔值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeBoolean(false);
    let ret = data.readBoolean();
    hilog.info(0x0000, 'testTag', 'readBoolean is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeChar<sup>9+</sup>

writeChar(val: number): void

将单个字符值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                 |
  | ------ | ------ | ---- | -------------------- |
  | val    | number | 是   | 要写入的单个字符值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeChar(97);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readChar<sup>9+</sup>

readChar(): number

从MessageSequence实例中读取单个字符值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明 |
  | ------ | ---- |
  | number | 返回单个字符值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeChar(97);
    let ret = data.readChar();
    hilog.info(0x0000, 'testTag', 'readChar is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeString<sup>9+</sup>

writeString(val: string): void

将字符串值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                      |
  | ------ | ------ | ---- | ----------------------------------------- |
  | val    | string | 是   | 要写入的字符串值，其长度应小于40960字节。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The string length exceeds 40960 bytes; <br/> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeString('abc');
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readString<sup>9+</sup>

readString(): string

从MessageSequence实例读取字符串值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | string | 返回字符串值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeString('abc');
    let ret = data.readString();
    hilog.info(0x0000, 'testTag', 'readString is ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeParcelable<sup>9+</sup>

writeParcelable(val: Parcelable): void

将自定义序列化对象写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | --------- | ---- | ------ |
| val    | [Parcelable](#parcelable9) | 是   | 要写入的可序列对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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

  try {
    let parcelable = new MyParcelable(1, "aaa");
    let data = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readParcelable<sup>9+</sup>

readParcelable(dataIn: Parcelable): void

从MessageSequence实例中读取成员变量到指定的对象（dataIn）。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名 | 类型                       | 必填 | 说明                                      |
| ------ | -------------------------- | ---- | ----------------------------------------- |
| dataIn | [Parcelable](#parcelable9) | 是   | 需要从MessageSequence读取成员变量的对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect. |
  | 1900010  | Failed to read data from the message sequence. |
  | 1900012  | Failed to call the JS callback function. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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

  try {
    let parcelable = new MyParcelable(1, "aaa");
    let data = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);
    let ret = new MyParcelable(0, "");
    data.readParcelable(ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeByteArray<sup>9+</sup>

writeByteArray(byteArray: number[]): void

将字节数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明               |
  | --------- | -------- | ---- | ------------------ |
  | byteArray | number[] | 是   | 要写入的字节数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The element does not exist in the array. <br/> 5.The type of the element in the array is incorrect. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    let ByteArrayVar = [1, 2, 3, 4, 5];
    data.writeByteArray(ByteArrayVar);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readByteArray<sup>9+</sup>

readByteArray(dataIn: number[]): void

从MessageSequence实例读取字节数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明               |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | 是   | 要读取的字节数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    let ByteArrayVar = [1, 2, 3, 4, 5];
    data.writeByteArray(ByteArrayVar);
    let array: Array<number> = new Array(5);
    data.readByteArray(array);
    hilog.info(0x0000, 'testTag', 'readByteArray is  ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readByteArray<sup>9+</sup>

readByteArray(): number[]

从MessageSequence实例中读取字节数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回字节数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    let ByteArrayVar = [1, 2, 3, 4, 5];
    data.writeByteArray(ByteArrayVar);
    let array = data.readByteArray();
    hilog.info(0x0000, 'testTag', 'readByteArray is  ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeShortArray<sup>9+</sup>

writeShortArray(shortArray: number[]): void

将短整数数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型     | 必填 | 说明                 |
  | ---------- | -------- | ---- | -------------------- |
  | shortArray | number[] | 是   | 要写入的短整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The element does not exist in the array; <br/> 5.The type of the element in the array is incorrect. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeShortArray([11, 12, 13]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readShortArray<sup>9+</sup>

readShortArray(dataIn: number[]): void

从MessageSequence实例中读取短整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | 是   | 要读取的短整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeShortArray([11, 12, 13]);
    let array: Array<number> = new Array(3);
    data.readShortArray(array);
    hilog.info(0x0000, 'testTag', 'readShortArray is  ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readShortArray<sup>9+</sup>

readShortArray(): number[]

从MessageSequence实例中读取短整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | number[] | 返回短整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeShortArray([11, 12, 13]);
    let array = data.readShortArray();
    hilog.info(0x0000, 'testTag', 'readShortArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeIntArray<sup>9+</sup>

writeIntArray(intArray: number[]): void

将整数数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型     | 必填 | 说明               |
  | -------- | -------- | ---- | ------------------ |
  | intArray | number[] | 是   | 要写入的整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The element does not exist in the array; <br/> 5.The type of the element in the array is incorrect. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeIntArray([100, 111, 112]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readIntArray<sup>9+</sup>

readIntArray(dataIn: number[]): void

从MessageSequence实例中读取整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明               |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | 是   | 要读取的整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeIntArray([100, 111, 112]);
    let array: Array<number> = new Array(3);
    data.readIntArray(array);
    hilog.info(0x0000, 'testTag', 'readIntArray is  ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readIntArray<sup>9+</sup>

readIntArray(): number[]

从MessageSequence实例中读取整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeIntArray([100, 111, 112]);
    let array = data.readIntArray();
    hilog.info(0x0000, 'testTag', 'readIntArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeLongArray<sup>9+</sup>

writeLongArray(longArray: number[]): void

将长整数数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明                 |
  | --------- | -------- | ---- | -------------------- |
  | longArray | number[] | 是   | 要写入的长整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The element does not exist in the array; <br/> 5.The type of the element in the array is incorrect. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeLongArray([1111, 1112, 1113]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readLongArray<sup>9+</sup>

readLongArray(dataIn: number[]): void

从MessageSequence实例读取的长整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | 是   | 要读取的长整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeLongArray([1111, 1112, 1113]);
    let array: Array<number> = new Array(3);
    data.readLongArray(array);
    hilog.info(0x0000, 'testTag', 'readLongArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readLongArray<sup>9+</sup>

readLongArray(): number[]

从MessageSequence实例中读取所有的长整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | number[] | 返回长整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeLongArray([1111, 1112, 1113]);
    let array = data.readLongArray();
    hilog.info(0x0000, 'testTag', 'readLongArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeFloatArray<sup>9+</sup>

writeFloatArray(floatArray: number[]): void

将双精度浮点数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型     | 必填 | 说明                                                                                                                    |
  | ---------- | -------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
  | floatArray | number[] | 是   | 要写入的双精度浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The element does not exist in the array; <br/> 5.The type of the element in the array is incorrect. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeFloatArray([1.2, 1.3, 1.4]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readFloatArray<sup>9+</sup>

readFloatArray(dataIn: number[]): void

从MessageSequence实例中读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                                                                                                                    |
  | ------ | -------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
  | dataIn | number[] | 是   | 要读取的双精度浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeFloatArray([1.2, 1.3, 1.4]);
    let array: Array<number> = new Array(3);
    data.readFloatArray(array);
    hilog.info(0x0000, 'testTag', 'readFloatArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readFloatArray<sup>9+</sup>

readFloatArray(): number[]

从MessageSequence实例中读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回双精度浮点数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeFloatArray([1.2, 1.3, 1.4]);
    let array = data.readFloatArray();
    hilog.info(0x0000, 'testTag', 'readFloatArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeDoubleArray<sup>9+</sup>

writeDoubleArray(doubleArray: number[]): void

将双精度浮点数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型     | 必填 | 说明                     |
  | ----------- | -------- | ---- | ------------------------ |
  | doubleArray | number[] | 是   | 要写入的双精度浮点数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The element does not exist in the array; <br/> 5.The type of the element in the array is incorrect. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeDoubleArray([11.1, 12.2, 13.3]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readDoubleArray<sup>9+</sup>

readDoubleArray(dataIn: number[]): void

从MessageSequence实例中读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                     |
  | ------ | -------- | ---- | ------------------------ |
  | dataIn | number[] | 是   | 要读取的双精度浮点数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeDoubleArray([11.1, 12.2, 13.3]);
    let array: Array<number> = new Array(3);
    data.readDoubleArray(array);
    hilog.info(0x0000, 'testTag', 'readDoubleArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readDoubleArray<sup>9+</sup>

readDoubleArray(): number[]

从MessageSequence实例读取所有双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明                 |
  | -------- | -------------------- |
  | number[] | 返回双精度浮点数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeDoubleArray([11.1, 12.2, 13.3]);
    let array = data.readDoubleArray();
    hilog.info(0x0000, 'testTag', 'readDoubleArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeBooleanArray<sup>9+</sup>

writeBooleanArray(booleanArray: boolean[]): void

将布尔数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名       | 类型      | 必填 | 说明               |
  | ------------ | --------- | ---- | ------------------ |
  | booleanArray | boolean[] | 是   | 要写入的布尔数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The element does not exist in the array. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeBooleanArray([false, true, false]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readBooleanArray<sup>9+</sup>

readBooleanArray(dataIn: boolean[]): void

从MessageSequence实例中读取布尔数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型      | 必填 | 说明               |
  | ------ | --------- | ---- | ------------------ |
  | dataIn | boolean[] | 是   | 要读取的布尔数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeBooleanArray([false, true, false]);
    let array: Array<boolean> = new Array(3);
    data.readBooleanArray(array);
    hilog.info(0x0000, 'testTag', 'readBooleanArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readBooleanArray<sup>9+</sup>

readBooleanArray(): boolean[]

从MessageSequence实例中读取所有布尔数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型      | 说明           |
  | --------- | -------------- |
  | boolean[] | 返回布尔数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeBooleanArray([false, true, false]);
    let array = data.readBooleanArray();
    hilog.info(0x0000, 'testTag', 'readBooleanArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeCharArray<sup>9+</sup>

writeCharArray(charArray: number[]): void

将单个字符数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明                   |
  | --------- | -------- | ---- | ---------------------- |
  | charArray | number[] | 是   | 要写入的单个字符数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The element does not exist in the array. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeCharArray([97, 98, 88]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readCharArray<sup>9+</sup>

readCharArray(dataIn: number[]): void

从MessageSequence实例中读取单个字符数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                   |
  | ------ | -------- | ---- | ---------------------- |
  | dataIn | number[] | 是   | 要读取的单个字符数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeCharArray([97, 98, 88]);
    let array: Array<number> = new Array(3);
    data.readCharArray(array);
    hilog.info(0x0000, 'testTag', 'readCharArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readCharArray<sup>9+</sup>

readCharArray(): number[]

从MessageSequence实例读取单个字符数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明               |
  | -------- | ------------------ |
  | number[] | 返回单个字符数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeCharArray([97, 98, 88]);
    let array = data.readCharArray();
    hilog.info(0x0000, 'testTag', 'readCharArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeStringArray<sup>9+</sup>

writeStringArray(stringArray: string[]): void

将字符串数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型     | 必填 | 说明                                                    |
  | ----------- | -------- | ---- | ------------------------------------------------------- |
  | stringArray | string[] | 是   | 要写入的字符串数组，数组单个元素的长度应小于40960字节。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The string length exceeds 40960 bytes; <br/> 5.The number of bytes copied to the buffer is different from the length of the obtained string. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeStringArray(["abc", "def"]);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readStringArray<sup>9+</sup>

readStringArray(dataIn: string[]): void

从MessageSequence实例读取字符串数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | string[] | 是   | 要读取的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeStringArray(["abc", "def"]);
    let array: Array<string> = new Array(2);
    data.readStringArray(array);
    hilog.info(0x0000, 'testTag', 'readStringArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readStringArray<sup>9+</sup>

readStringArray(): string[]

从MessageSequence实例读取字符串数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | string[] | 返回字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    data.writeStringArray(["abc", "def"]);
    let array = data.readStringArray();
    hilog.info(0x0000, 'testTag', 'readStringArray is ' + array);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeNoException<sup>9+</sup>

writeNoException(): void

向MessageSequence写入“指示未发生异常”的信息。

**系统能力**：SystemCapability.Communication.IPC.Core

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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

### readException<sup>9+</sup>

readException(): void

从MessageSequence中读取异常。

**系统能力**：SystemCapability.Communication.IPC.Core

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的sendMessageRequest接口方法发送消息

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  try {
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
            result.reply.readException();
            let num = result.reply.readInt();
            hilog.info(0x0000, 'testTag', 'reply num: ' + num);
          } else {
            hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode: ' + result.errCode);
          }
        }).catch((e: Error) => {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest got exception: ' + e);
        }).finally (() => {
          hilog.info(0x0000, 'testTag', 'sendMessageRequest ends, reclaim parcel');
          data.reclaim();
          reply.reclaim();
        });
    }
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeParcelableArray<sup>9+</sup>

writeParcelableArray(parcelableArray: Parcelable[]): void

将可序列化对象数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名          | 类型         | 必填 | 说明                       |
| --------------- | ------------ | ---- | -------------------------- |
| parcelableArray | [Parcelable](#parcelable9)[] | 是   | 要写入的可序列化对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The element does not exist in the array. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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

  try {
    let parcelable = new MyParcelable(1, "aaa");
    let parcelable2 = new MyParcelable(2, "bbb");
    let parcelable3 = new MyParcelable(3, "ccc");
    let a = [parcelable, parcelable2, parcelable3];
    let data = rpc.MessageSequence.create();
    data.writeParcelableArray(a);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write parcelable array fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write parcelable array fail, errorMessage ' + e.message);
  }
  ```

### readParcelableArray<sup>9+</sup>

readParcelableArray(parcelableArray: Parcelable[]): void

从MessageSequence实例读取可序列化对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名          | 类型         | 必填 | 说明                       |
| --------------- | ------------ | ---- | -------------------------- |
| parcelableArray | [Parcelable](#parcelable9)[] | 是   | 要读取的可序列化对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The length of the array passed when reading is not equal to the length passed when writing to the array; <br/> 5.The element does not exist in the array. |
  | 1900010  | Failed to read data from the message sequence. |
  | 1900012  | Failed to call the JS callback function. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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

  try {
    let parcelable = new MyParcelable(1, "aaa");
    let parcelable2 = new MyParcelable(2, "bbb");
    let parcelable3 = new MyParcelable(3, "ccc");
    let a = [parcelable, parcelable2, parcelable3];
    let data = rpc.MessageSequence.create();
    data.writeParcelableArray(a);
    let b = [new MyParcelable(0, ""), new MyParcelable(0, ""), new MyParcelable(0, "")];
    data.readParcelableArray(b);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'rpc write parcelable array fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'rpc write parcelable array fail, errorMessage ' + e.message);
  }
  ```

### writeRemoteObjectArray<sup>9+</sup>

writeRemoteObjectArray(objectArray: IRemoteObject[]): void

将IRemoteObject对象数组写入MessageSequence。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名      | 类型            | 必填 | 说明                                           |
| ----------- | --------------- | ---- | ---------------------------------------------- |
| objectArray | [IRemoteObject](#iremoteobject)[] | 是   | 要写入MessageSequence的IRemoteObject对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The element does not exist in the array; <br/> 5.The obtained remoteObject is null. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }

  try {
    let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
    let data = rpc.MessageSequence.create();
    data.writeRemoteObjectArray(a);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readRemoteObjectArray<sup>9+</sup>

readRemoteObjectArray(objects: IRemoteObject[]): void

从MessageSequence读取IRemoteObject对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名  | 类型            | 必填 | 说明                                           |
| ------- | --------------- | ---- | ---------------------------------------------- |
| objects | [IRemoteObject](#iremoteobject)[] | 是   | 从MessageSequence读取的IRemoteObject对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The length of the array passed when reading is not equal to the length passed when writing to the array. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }

  try {
    let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
    let data = rpc.MessageSequence.create();
    data.writeRemoteObjectArray(a);
    let b: Array<rpc.IRemoteObject> = new Array(3);
    data.readRemoteObjectArray(b);
    hilog.info(0x0000, 'testTag', 'readRemoteObjectArray is ' + b);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readRemoteObjectArray<sup>9+</sup>

readRemoteObjectArray(): IRemoteObject[]

从MessageSequence读取IRemoteObject对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

| 类型            | 说明                        |
| --------------- | --------------------------- |
| [IRemoteObject](#iremoteobject)[] | 返回IRemoteObject对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }

  try {
    let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
    let data = rpc.MessageSequence.create();
    let b = data.readRemoteObjectArray();
    hilog.info(0x0000, 'testTag', 'readRemoteObjectArray is ' + b);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### closeFileDescriptor<sup>9+</sup>

static closeFileDescriptor(fd: number): void

静态方法，关闭给定的文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                 |
  | ------ | ------ | ---- | -------------------- |
  | fd     | number | 是   | 要关闭的文件描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let filePath = "path/to/file"; 
    let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    rpc.MessageSequence.closeFileDescriptor(file.fd);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### dupFileDescriptor<sup>9+</sup>

static dupFileDescriptor(fd: number): number

静态方法，复制给定的文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                     |
  | ------ | ------ | ---- | ------------------------ |
  | fd     | number | 是   | 表示已存在的文件描述符。 |

**返回值：**

  | 类型   | 说明                 |
  | ------ | -------------------- |
  | number | 返回新的文件描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900013  | Failed to call dup. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let filePath = "path/to/file"; 
    let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    rpc.MessageSequence.dupFileDescriptor(file.fd);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### containFileDescriptors<sup>9+</sup>

containFileDescriptors(): boolean

检查此MessageSequence对象是否包含文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                                                 |
  | ------- | -------------------------------------------------------------------- |
  | boolean | true：包含文件描述符，false：不包含文件描述符。|

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let sequence = rpc.MessageSequence.create();
    let filePath = "path/to/file";
    let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    let containFD = sequence.containFileDescriptors();
    hilog.info(0x0000, 'testTag', 'sequence after write fd containFd result is ' + containFD);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeFileDescriptor<sup>9+</sup>

writeFileDescriptor(fd: number): void

写入文件描述符到MessageSequence。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明         |
  | ------ | ------ | ---- | ------------ |
  | fd     | number | 是   | 文件描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let sequence = rpc.MessageSequence.create();
    let filePath = "path/to/file";
    let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    sequence.writeFileDescriptor(file.fd);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readFileDescriptor<sup>9+</sup>

readFileDescriptor(): number

从MessageSequence中读取文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | number | 返回文件描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let sequence = rpc.MessageSequence.create();
    let filePath = "path/to/file";
    let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    sequence.writeFileDescriptor(file.fd);
    let readFD = sequence.readFileDescriptor();
    hilog.info(0x0000, 'testTag', 'readFileDescriptor is ' + readFD);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeAshmem<sup>9+</sup>

writeAshmem(ashmem: Ashmem): void

将指定的匿名共享对象写入此MessageSequence。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                  |
| ------ | ------ | ---- | ------------------------------------- |
| ashmem | [Ashmem](#ashmem8) | 是   | 要写入MessageSequence的匿名共享对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter is not an instance of the Ashmem object. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let sequence = rpc.MessageSequence.create();
    let ashmem = rpc.Ashmem.create("ashmem", 1024);
    // ashmem里写入数据
    let buffer = new ArrayBuffer(1024);
    let int32View = new Int32Array(buffer);
    for (let i = 0; i < int32View.length; i++) {
      int32View[i] = i * 2 + 1;
    }
    let size = buffer.byteLength;
    ashmem.mapReadWriteAshmem();
    ashmem.writeDataToAshmem(buffer, size, 0);
    // 将ashmem对象写入messageSequence对象中
    sequence.writeAshmem(ashmem);
    // 将传递的数据大小写入messageSequence对象中
    sequence.writeInt(size);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readAshmem<sup>9+</sup>

readAshmem(): Ashmem

从MessageSequence读取匿名共享对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| [Ashmem](#ashmem8) | 返回匿名共享对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let sequence = rpc.MessageSequence.create();
    let ashmem = rpc.Ashmem.create("ashmem", 1024);
    // ashmem里写入数据
    let buffer = new ArrayBuffer(1024);
    let int32View = new Int32Array(buffer);
    for (let i = 0; i < int32View.length; i++) {
      int32View[i] = i * 2 + 1;
    }
    let size = buffer.byteLength;
    ashmem.mapReadWriteAshmem();
    ashmem.writeDataToAshmem(buffer, size, 0);
    // 将传递的数据大小写入messageSequence对象中
    sequence.writeInt(size);
    // 将ashmem对象写入messageSequence对象中
    sequence.writeAshmem(ashmem);

    // 读取传递的数据大小
    let dataSize = sequence.readInt();
    // 从messageSequence对象中读取ashmem对象
    let ashmem1 = sequence.readAshmem();
    // 从ashmem对象中读取数据
    ashmem1.mapReadWriteAshmem();
    let readResult = ashmem1.readDataFromAshmem(dataSize, 0);
    let readInt32View = new Int32Array(readResult);
    hilog.info(0x0000, 'testTag', 'read from Ashmem result is ' + readInt32View);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### getRawDataCapacity<sup>9+</sup>

getRawDataCapacity(): number

获取MessageSequence可以容纳的最大原始数据量。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                                         |
  | ------ | ------------------------------------------------------------ |
  | number | 返回MessageSequence可以容纳的最大原始数据量，即128MB。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let sequence = rpc.MessageSequence.create();
    let result = sequence.getRawDataCapacity();
    hilog.info(0x0000, 'testTag', 'sequence get RawDataCapacity result is ' + result);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeRawData<sup>(deprecated)</sup>

writeRawData(rawData: number[], size: number): void

将原始数据写入MessageSequence对象。

> **说明：**
>
> 从API version 11 开始废弃，建议使用[writeRawDataBuffer](#writerawdatabuffer11)替代。
>
> 该接口是一次性接口，不允许在一次parcel通信中多次调用该接口。
> 该接口在传输数据时，当数据量较大时（超过32KB），会使用共享内存传输数据，此时需注意selinux配置。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型     | 必填 | 说明                               |
  | ------- | -------- | ---- | ---------------------------------- |
  | rawData | number[] | 是   | 要写入的原始数据，大小不能超过128MB。 |
  | size    | number   | 是   | 发送的原始数据大小，以字节为单位。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The transferred size cannot be obtained; <br/> 5.The transferred size is less than or equal to 0;<br/> 6.The element does not exist in the array; <br/> 7.Failed to obtain typedArray information; <br/> 8.The array is not of type int32; <br/> 9.The length of typedarray is smaller than the size of the original data sent. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let sequence = rpc.MessageSequence.create();
    let arr = [1, 2, 3, 4, 5];
    sequence.writeRawData(arr, arr.length);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeRawDataBuffer<sup>11+</sup>

writeRawDataBuffer(rawData: ArrayBuffer, size: number): void

将原始数据写入MessageSequence对象。

> **说明：**
>
> 该接口是一次性接口，不允许在一次parcel通信中多次调用该接口。
> 该接口在传输数据时，当数据量较大时（超过32KB），会使用共享内存传输数据，此时需注意selinux配置。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型        | 必填 | 说明                                 |
  | ------- | ----------- | ---- | ------------------------------------ |
  | rawData | ArrayBuffer | 是   | 要写入的原始数据，大小不能超过128MB。 |
  | size    | number      | 是   | 发送的原始数据大小，以字节为单位。    |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.Failed to obtain arrayBuffer information; <br/> 4.The transferred size cannot be obtained; <br/> 5.The transferred size is less than or equal to 0; <br/> 6.The transferred size is greater than the byte length of ArrayBuffer. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let buffer = new ArrayBuffer(64 * 1024);
    let int32View = new Int32Array(buffer);
    for (let i = 0; i < int32View.length; i++) {
      int32View[i] = i * 2 + 1;
    }
    let size = buffer.byteLength;
    let sequence = rpc.MessageSequence.create();
    sequence.writeRawDataBuffer(buffer, size);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readRawData<sup>(deprecated)</sup>

readRawData(size: number): number[]

从MessageSequence读取原始数据。

> **说明：**
>
> 从API version 11 开始废弃，建议使用[readRawDataBuffer](#readrawdatabuffer11)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                     |
  | ------ | ------ | ---- | ------------------------ |
  | size   | number | 是   | 要读取的原始数据的大小。 |

**返回值：**

  | 类型     | 说明                           |
  | -------- | ------------------------------ |
  | number[] | 返回原始数据（以字节为单位）。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let sequence = rpc.MessageSequence.create();
    let arr = [1, 2, 3, 4, 5];
    sequence.writeRawData(arr, arr.length);
    let size = arr.length;
    let result = sequence.readRawData(size);
    hilog.info(0x0000, 'testTag', 'sequence read raw data result is ' + result);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readRawDataBuffer<sup>11+</sup>

readRawDataBuffer(size: number): ArrayBuffer

从MessageSequence读取原始数据。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                     |
  | ------ | ------ | ---- | ------------------------ |
  | size   | number | 是   | 要读取的原始数据的大小。 |

**返回值：**

  | 类型     | 说明                           |
  | -------- | ------------------------------ |
  | ArrayBuffer | 返回原始数据（以字节为单位）。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let buffer = new ArrayBuffer(64 * 1024);
    let int32View = new Int32Array(buffer);
    for (let i = 0; i < int32View.length; i++) {
      int32View[i] = i * 2 + 1;
    }
    let size = buffer.byteLength;
    let sequence = rpc.MessageSequence.create();
    sequence.writeRawDataBuffer(buffer, size);
    let result = sequence.readRawDataBuffer(size);
    let readInt32View = new Int32Array(result);
    hilog.info(0x0000, 'testTag', 'sequence read raw data result is ' + readInt32View);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeArrayBuffer<sup>12+</sup>

writeArrayBuffer(buf: ArrayBuffer, typeCode: TypeCode): void

将ArrayBuffer类型数据写入MessageSequence对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                      | 必填 | 说明                        |
  | --------- | ------------------------- | ---- | --------------------------- |
  | buf       | ArrayBuffer               | 是   | 要写入的ArrayBuffer数据。   |
  | typeCode  | [TypeCode](#typecode12)   | 是   | ArrayBuffer数据具体是以哪一种TypedArray来访问和操作(会根据业务传递的类型枚举值去决定底层的写入方式，需要业务正确传递枚举值。) |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The parameter is an empty array; <br/> 2.The number of parameters is incorrect; <br/> 3.The parameter type does not match; <br/> 4.The obtained value of typeCode is incorrect; <br/> 5.Failed to obtain arrayBuffer information. |
  | 1900009  | Failed to write data to the message sequence. |

**示例：**

  ```ts
  // TypeCode 类型枚举较多，示例代码以Int16Array为例
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    let buffer = new ArrayBuffer(10);
    let int16View = new Int16Array(buffer);
    for (let i = 0; i < int16View.length; i++) {
      int16View[i] = i * 2 + 1;
    }
    data.writeArrayBuffer(buffer, rpc.TypeCode.INT16_ARRAY);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readArrayBuffer<sup>12+</sup>

readArrayBuffer(typeCode: TypeCode): ArrayBuffer

从MessageSequence读取ArrayBuffer类型数据。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型                     | 必填 | 说明                   |
  | -------- | ----------------------- | ---- | ------------------------|
  | typeCode | [TypeCode](#typecode12) | 是   | ArrayBuffer数据具体是以哪一种TypedArray来访问和操作(会根据业务传递的类型枚举值去决定底层的读取方式，需要业务正确传递枚举值，读写枚举值不匹配会导致数据异常。)  |

**返回值：**

  | 类型     | 说明                                         |
  | -------- | -------------------------------------------- |
  | ArrayBuffer | 返回ArrayBuffer类型数据（以字节为单位）。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The obtained value of typeCode is incorrect; |
  | 1900010  | Failed to read data from the message sequence. |

**示例：**

  ```ts
  // TypeCode 类型枚举较多，示例代码以Int16Array为例
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let data = rpc.MessageSequence.create();
    let buffer = new ArrayBuffer(10);
    let int16View = new Int16Array(buffer);
    for (let i = 0; i < int16View.length; i++) {
      int16View[i] = i * 2 + 1;
    }
    data.writeArrayBuffer(buffer, rpc.TypeCode.INT16_ARRAY);
    let result = data.readArrayBuffer(rpc.TypeCode.INT16_ARRAY);
    let readInt16View = new Int16Array(result);
    hilog.info(0x0000, 'testTag', 'read ArrayBuffer result is ' + readInt16View);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

## MessageParcel<sup>(deprecated)</sup>

在RPC过程中，发送方可以使用MessageParcel提供的写方法，将待发送的数据以特定格式写入该对象。接收方可以使用MessageParcel提供的读方法从该对象中读取特定格式的数据。数据格式包括：基础类型及数组、IPC对象、接口描述符和自定义序列化对象。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[MessageSequence](#messagesequence9)替代。

### create

static create(): MessageParcel

静态方法，创建MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型          | 说明                          |
  | ------------- | ----------------------------- |
  | [MessageParcel](#messageparceldeprecated) | 返回创建的MessageParcel对象。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    hilog.info(0x0000, 'testTag', 'data is ' + data);

    // 当MessageParcel对象不再使用，由业务主动调用reclaim方法去释放资源。
    data.reclaim();
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### reclaim

reclaim(): void

释放不再使用的MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let reply = rpc.MessageParcel.create();
    reply.reclaim();
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeRemoteObject

writeRemoteObject(object: IRemoteObject): boolean

序列化远程对象并将其写入MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                            | 必填 | 说明                                    |
  | ------ | ------------------------------- | ---- | --------------------------------------- |
  | object | [IRemoteObject](#iremoteobject) | 是   | 要序列化并写入MessageParcel的远程对象。 |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：操作成功，false：操作失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }

  try {
    let data = rpc.MessageParcel.create();
    let testRemoteObject = new TestRemoteObject("testObject");
    data.writeRemoteObject(testRemoteObject);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readRemoteObject

readRemoteObject(): IRemoteObject

从MessageParcel读取远程对象。此方法用于反序列化MessageParcel对象以生成IRemoteObject。远程对象按写入MessageParcel的顺序读取。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型                            | 说明               |
  | ------------------------------- | ------------------ |
  | [IRemoteObject](#iremoteobject) | 读取到的远程对象。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }

  try {
    let data = rpc.MessageParcel.create();
    let testRemoteObject = new TestRemoteObject("testObject");
    data.writeRemoteObject(testRemoteObject);
    let proxy = data.readRemoteObject();
    hilog.info(0x0000, 'testTag', 'readRemoteObject is ' + proxy);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeInterfaceToken

writeInterfaceToken(token: string): boolean

将接口描述符写入MessageParcel对象，远端对象可使用该信息校验本次通信。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明               |
  | ------ | ------ | ---- | ------------------ |
  | token  | string | 是   | 字符串类型描述符，其长度应小于40960字节。 |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：操作成功，false：操作失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeInterfaceToken("aaa");
    hilog.info(0x0000, 'testTag', 'RpcServer: writeInterfaceToken is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readInterfaceToken

readInterfaceToken(): string

从MessageParcel中读取接口描述符，接口描述符按写入MessageParcel的顺序读取，本地对象可使用该信息检验本次通信。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                     |
  | ------ | ------------------------ |
  | string | 返回读取到的接口描述符。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeInterfaceToken("aaa");
    let interfaceToken = data.readInterfaceToken();
    hilog.info(0x0000, 'testTag', 'RpcServer: interfaceToken is ' + interfaceToken);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getSize

getSize(): number

获取当前MessageParcel的数据大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                          |
  | ------ | --------------------------------------------- |
  | number | 获取的MessageParcel的数据大小。以字节为单位。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    data.writeInt(1);
    let size = data.getSize();
    hilog.info(0x0000, 'testTag', 'size is ' + size);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getCapacity

getCapacity(): number

获取当前MessageParcel的容量。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                          |
  | ------ | --------------------------------------------- |
  | number | 获取的MessageParcel的容量大小。以字节为单位。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let data = rpc.MessageParcel.create();
    let result = data.getCapacity();
    hilog.info(0x0000, 'testTag', 'capacity is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### setSize

setSize(size: number): boolean

设置MessageParcel实例中包含的数据大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                        |
  | ------ | ------ | ---- | ------------------------------------------- |
  | size   | number | 是   | MessageParcel实例的数据大小。以字节为单位。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：设置成功，false：设置失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let setSize = data.setSize(16);
    hilog.info(0x0000, 'testTag', 'setSize is ' + setSize);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### setCapacity

setCapacity(size: number): boolean

设置MessageParcel实例的存储容量。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                        |
  | ------ | ------ | ---- | ------------------------------------------- |
  | size   | number | 是   | MessageParcel实例的存储容量。以字节为单位。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：设置成功，false：设置失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.setCapacity(100);
    hilog.info(0x0000, 'testTag', 'setCapacity is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getWritableBytes

getWritableBytes(): number

获取MessageParcel的可写字节空间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                                |
  | ------ | --------------------------------------------------- |
  | number | 获取到的MessageParcel的可写字节空间。以字节为单位。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    data.writeInt(1);
    let getWritableBytes = data.getWritableBytes();
    hilog.info(0x0000, 'testTag', 'RpcServer: getWritableBytes is ' + getWritableBytes);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getReadableBytes

getReadableBytes(): number

获取MessageParcel的可读字节空间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                                |
  | ------ | --------------------------------------------------- |
  | number | 获取到的MessageParcel的可读字节空间。以字节为单位。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    data.writeInt(1);
    let result = data.getReadableBytes();
    hilog.info(0x0000, 'testTag', 'RpcServer: getReadableBytes is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getReadPosition

getReadPosition(): number

获取MessageParcel的读位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                    |
  | ------ | --------------------------------------- |
  | number | 返回MessageParcel实例中的当前读取位置。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let readPos = data.getReadPosition();
    hilog.info(0x0000, 'testTag', 'readPos is ' + readPos);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getWritePosition

getWritePosition(): number

获取MessageParcel的写位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                    |
  | ------ | --------------------------------------- |
  | number | 返回MessageParcel实例中的当前写入位置。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    data.writeInt(10);
    let bwPos = data.getWritePosition();
    hilog.info(0x0000, 'testTag', 'bwPos is ' + bwPos);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### rewindRead

rewindRead(pos: number): boolean

重新偏移读取位置到指定的位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                     |
  | ------ | ------ | ---- | ------------------------ |
  | pos    | number | 是   | 开始读取数据的目标位置。 |

**返回值：**

  | 类型    | 说明                                              |
  | ------- | ------------------------------------------------- |
  | boolean | true：读取位置发生更改，false：读取位置未发生更改。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    data.writeInt(12);
    data.writeString("parcel");
    let number = data.readInt();
    hilog.info(0x0000, 'testTag', 'number is ' + number);
    data.rewindRead(0);
    let number2 = data.readInt();
    hilog.info(0x0000, 'testTag', 'rewindRead is ' + number2);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### rewindWrite

rewindWrite(pos: number): boolean

重新偏移写位置到指定的位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                     |
  | ------ | ------ | ---- | ------------------------ |
  | pos    | number | 是   | 开始写入数据的目标位置。 |

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean | true：写入位置发生更改，false：写入位置未发生更改。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    data.writeInt(4);
    data.rewindWrite(0);
    data.writeInt(5);
    let number = data.readInt();
    hilog.info(0x0000, 'testTag', 'rewindWrite is ' + number);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeByte

writeByte(val: number): boolean

将字节值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的字节值。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |
  | boolean | true：写入成功，false：写入失败。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeByte(2);
    hilog.info(0x0000, 'testTag', 'writeByte is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readByte

readByte(): number

从MessageParcel实例读取字节值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明         |
  | ------ | ------------ |
  | number | 返回字节值。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeByte(2);
    hilog.info(0x0000, 'testTag', 'writeByte is ' + result);
    let ret = data.readByte();
    hilog.info(0x0000, 'testTag', 'readByte is ' + ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeShort

writeShort(val: number): boolean

将短整数值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明               |
  | ------ | ------ | ---- | ------------------ |
  | val    | number | 是   | 要写入的短整数值。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeShort(8);
    hilog.info(0x0000, 'testTag', 'writeShort is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readShort

readShort(): number

从MessageParcel实例读取短整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | number | 返回短整数值。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeShort(8);
    hilog.info(0x0000, 'testTag', 'writeShort is ' + result);
    let ret = data.readShort();
    hilog.info(0x0000, 'testTag', 'readShort is ' + ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeInt

writeInt(val: number): boolean

将整数值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的整数值。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |   
  | boolean | true：写入成功，false：写入失败。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeInt(10);
    hilog.info(0x0000, 'testTag', 'writeInt is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readInt

readInt(): number

从MessageParcel实例读取整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明         |
  | ------ | ------------ |
  | number | 返回整数值。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeInt(10);
    hilog.info(0x0000, 'testTag', 'writeInt is ' + result);
    let ret = data.readInt();
    hilog.info(0x0000, 'testTag', 'readInt is ' + ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeLong

writeLong(val: number): boolean

将长整数值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的长整数值 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeLong(10000);
    hilog.info(0x0000, 'testTag', 'writeLong is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readLong

readLong(): number

从MessageParcel实例中读取长整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | number | 返回长整数值。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeLong(10000);
    hilog.info(0x0000, 'testTag', 'writeLong is ' + result);
    let ret = data.readLong();
    hilog.info(0x0000, 'testTag', 'readLong is ' + ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeFloat

writeFloat(val: number): boolean

将双精度浮点值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的双精度浮点值。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeFloat(1.2);
    hilog.info(0x0000, 'testTag', 'writeFloat is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readFloat

readFloat(): number

从MessageParcel实例中读取双精度浮点值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明         |
  | ------ | ------------ |
  | number | 返回双精度浮点值。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeFloat(1.2);
    hilog.info(0x0000, 'testTag', 'writeFloat is ' + result);
    let ret = data.readFloat();
    hilog.info(0x0000, 'testTag', 'readFloat is ' + ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeDouble

writeDouble(val: number): boolean

将双精度浮点值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                   |
  | ------ | ------ | ---- | ---------------------- |
  | val    | number | 是   | 要写入的双精度浮点值。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeDouble(10.2);
    hilog.info(0x0000, 'testTag', 'writeDouble is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readDouble

readDouble(): number

从MessageParcel实例读取双精度浮点值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明               |
  | ------ | ------------------ |
  | number | 返回双精度浮点值。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeDouble(10.2);
    hilog.info(0x0000, 'testTag', 'writeDouble is ' + result);
    let ret = data.readDouble();
    hilog.info(0x0000, 'testTag', 'readDouble is ' + ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeBoolean

writeBoolean(val: boolean): boolean

将布尔值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型    | 必填 | 说明             |
  | ------ | ------- | ---- | ---------------- |
  | val    | boolean | 是   | 要写入的布尔值。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeBoolean(false);
    hilog.info(0x0000, 'testTag', 'writeBoolean is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readBoolean

readBoolean(): boolean

从MessageParcel实例读取布尔值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                 |
  | ------- | -------------------- |
  | boolean | 返回读取到的布尔值。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeBoolean(false);
    hilog.info(0x0000, 'testTag', 'writeBoolean is ' + result);
    let ret = data.readBoolean();
    hilog.info(0x0000, 'testTag', 'readBoolean is ' + ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeChar

writeChar(val: number): boolean

将单个字符值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                 |
  | ------ | ------ | ---- | -------------------- |
  | val    | number | 是   | 要写入的单个字符值。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeChar(97);
    hilog.info(0x0000, 'testTag', 'writeChar is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readChar

readChar(): number

从MessageParcel实例中读取单个字符值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | number | 返回单个字符值。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeChar(97);
    hilog.info(0x0000, 'testTag', 'writeChar is ' + result);
    let ret = data.readChar();
    hilog.info(0x0000, 'testTag', 'readChar is ' + ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeString

writeString(val: string): boolean

将字符串值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                      |
  | ------ | ------ | ---- | ----------------------------------------- |
  | val    | string | 是   | 要写入的字符串值，其长度应小于40960字节。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeString('abc');
    hilog.info(0x0000, 'testTag', 'writeString is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readString

readString(): string

从MessageParcel实例读取字符串值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | string | 返回字符串值。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeString('abc');
    hilog.info(0x0000, 'testTag', 'writeString is ' + result);
    let ret = data.readString();
    hilog.info(0x0000, 'testTag', 'readString is ' + ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeSequenceable

writeSequenceable(val: Sequenceable): boolean

将自定义序列化对象写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                          | 必填 | 说明                 |
  | ------ | ----------------------------- | ---- | -------------------- |
  | val    | [Sequenceable](#sequenceabledeprecated) | 是   | 要写入的可序列对象。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
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

  try {
    let sequenceable = new MySequenceable(1, "aaa");
    let data = rpc.MessageParcel.create();
    let result = data.writeSequenceable(sequenceable);
    hilog.info(0x0000, 'testTag', 'writeSequenceable is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readSequenceable

readSequenceable(dataIn: Sequenceable): boolean

从MessageParcel实例中读取成员变量到指定的对象（dataIn）。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                          | 必填    | 说明                                           |
  | ------ | ----------------------------- | ------- | ---------------------------------------------- |
  | dataIn | [Sequenceable](#sequenceabledeprecated) | 是   | 需要从MessageParcel读取成员变量的对象。 |

**返回值：**

  | 类型    | 说明                                     |
  | ------- | ---------------------------------------- |
  | boolean | true：反序列化成功，false：反序列化失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
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

  try {
    let sequenceable = new MySequenceable(1, "aaa");
    let data = rpc.MessageParcel.create();
    let result = data.writeSequenceable(sequenceable);
    hilog.info(0x0000, 'testTag', 'writeSequenceable is ' + result);
    let ret = new MySequenceable(0, "");
    let result2 = data.readSequenceable(ret);
    hilog.info(0x0000, 'testTag', 'readSequenceable is ' + result2);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeByteArray

writeByteArray(byteArray: number[]): boolean

将字节数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明               |
  | --------- | -------- | ---- | ------------------ |
  | byteArray | number[] | 是   | 要写入的字节数组。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let ByteArrayVar = [1, 2, 3, 4, 5];
    let result = data.writeByteArray(ByteArrayVar);
    hilog.info(0x0000, 'testTag', 'writeByteArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readByteArray

readByteArray(dataIn: number[]): void

从MessageParcel实例读取字节数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明               |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | 是   | 要读取的字节数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let ByteArrayVar = [1, 2, 3, 4, 5];
    let result = data.writeByteArray(ByteArrayVar);
    let array: Array<number> = new Array(5);
    data.readByteArray(array);
    hilog.info(0x0000, 'testTag', 'readByteArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readByteArray

readByteArray(): number[]

从MessageParcel实例中读取字节数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回字节数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let ByteArrayVar = [1, 2, 3, 4, 5];
    let result = data.writeByteArray(ByteArrayVar);
    hilog.info(0x0000, 'testTag', 'writeByteArray is ' + result);
    let array = data.readByteArray();
    hilog.info(0x0000, 'testTag', 'readByteArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeShortArray

writeShortArray(shortArray: number[]): boolean

将短整数数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型     | 必填 | 说明                 |
  | ---------- | -------- | ---- | -------------------- |
  | shortArray | number[] | 是   | 要写入的短整数数组。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeShortArray([11, 12, 13]);
    hilog.info(0x0000, 'testTag', 'writeShortArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readShortArray

readShortArray(dataIn: number[]): void

从MessageParcel实例中读取短整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | 是   | 要读取的短整数数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeShortArray([11, 12, 13]);
    hilog.info(0x0000, 'testTag', 'writeShortArray is ' + result);
    let array: Array<number> = new Array(3);
    data.readShortArray(array);
    hilog.info(0x0000, 'testTag', 'readShortArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readShortArray

readShortArray(): number[]

从MessageParcel实例中读取短整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | number[] | 返回短整数数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeShortArray([11, 12, 13]);
    hilog.info(0x0000, 'testTag', 'writeShortArray is ' + result);
    let array = data.readShortArray();
    hilog.info(0x0000, 'testTag', 'readShortArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeIntArray

writeIntArray(intArray: number[]): boolean

将整数数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型     | 必填 | 说明               |
  | -------- | -------- | ---- | ------------------ |
  | intArray | number[] | 是   | 要写入的整数数组。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeIntArray([100, 111, 112]);
    hilog.info(0x0000, 'testTag', 'writeIntArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readIntArray

readIntArray(dataIn: number[]): void

从MessageParcel实例中读取整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明               |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | 是   | 要读取的整数数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeIntArray([100, 111, 112]);
    hilog.info(0x0000, 'testTag', 'writeIntArray is ' + result);
    let array: Array<number> = new Array(3);
    data.readIntArray(array);
    hilog.info(0x0000, 'testTag', 'readIntArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readIntArray

readIntArray(): number[]

从MessageParcel实例中读取整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回整数数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeIntArray([100, 111, 112]);
    hilog.info(0x0000, 'testTag', 'writeIntArray is ' + result);
    let array = data.readIntArray();
    hilog.info(0x0000, 'testTag', 'readIntArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeLongArray

writeLongArray(longArray: number[]): boolean

将长整数数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明                 |
  | --------- | -------- | ---- | -------------------- |
  | longArray | number[] | 是   | 要写入的长整数数组。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeLongArray([1111, 1112, 1113]);
    hilog.info(0x0000, 'testTag', 'writeLongArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readLongArray

readLongArray(dataIn: number[]): void

从MessageParcel实例读取长整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | 是   | 要读取的长整数数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeLongArray([1111, 1112, 1113]);
    hilog.info(0x0000, 'testTag', 'writeLongArray is ' + result);
    let array: Array<number> = new Array(3);
    data.readLongArray(array);
    hilog.info(0x0000, 'testTag', 'readLongArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readLongArray

readLongArray(): number[]

从MessageParcel实例中读取长整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

 | 类型     | 说明             |
 | -------- | ---------------- |
 | number[] | 返回长整数数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeLongArray([1111, 1112, 1113]);
    hilog.info(0x0000, 'testTag', 'writeLongArray is ' + result);
    let array = data.readLongArray();
    hilog.info(0x0000, 'testTag', 'readLongArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeFloatArray

writeFloatArray(floatArray: number[]): boolean

将双精度浮点数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明  |
  | ---------- | -------- | ---- | --- |
  | floatArray | number[] | 是   | 要写入的双精度浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeFloatArray([1.2, 1.3, 1.4]);
    hilog.info(0x0000, 'testTag', 'writeFloatArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readFloatArray

readFloatArray(dataIn: number[]): void

从MessageParcel实例中读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明   |
  | ------ | -------- | ---- | ------ |
  | dataIn | number[] | 是   | 要读取的双精度浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeFloatArray([1.2, 1.3, 1.4]);
    hilog.info(0x0000, 'testTag', 'writeFloatArray is ' + result);
    let array: Array<number> = new Array(3);
    data.readFloatArray(array);
    hilog.info(0x0000, 'testTag', 'readFloatArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readFloatArray

readFloatArray(): number[]

从MessageParcel实例中读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回双精度浮点数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeFloatArray([1.2, 1.3, 1.4]);
    hilog.info(0x0000, 'testTag', 'writeFloatArray is ' + result);
    let array = data.readFloatArray();
    hilog.info(0x0000, 'testTag', 'readFloatArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeDoubleArray

writeDoubleArray(doubleArray: number[]): boolean

将双精度浮点数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型     | 必填 | 说明                     |
  | ----------- | -------- | ---- | ------------------------ |
  | doubleArray | number[] | 是   | 要写入的双精度浮点数组。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
    hilog.info(0x0000, 'testTag', 'writeDoubleArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readDoubleArray

readDoubleArray(dataIn: number[]): void

从MessageParcel实例中读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                     |
  | ------ | -------- | ---- | ------------------------ |
  | dataIn | number[] | 是   | 要读取的双精度浮点数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
    hilog.info(0x0000, 'testTag', 'writeDoubleArray is ' + result);
    let array: Array<number> = new Array(3);
    data.readDoubleArray(array);
    hilog.info(0x0000, 'testTag', 'readDoubleArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readDoubleArray

readDoubleArray(): number[]

从MessageParcel实例读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明                 |
  | -------- | -------------------- |
  | number[] | 返回双精度浮点数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
    hilog.info(0x0000, 'testTag', 'writeDoubleArray is ' + result);
    let array = data.readDoubleArray();
    hilog.info(0x0000, 'testTag', 'readDoubleArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeBooleanArray

writeBooleanArray(booleanArray: boolean[]): boolean

将布尔数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名       | 类型      | 必填 | 说明               |
  | ------------ | --------- | ---- | ------------------ |
  | booleanArray | boolean[] | 是   | 要写入的布尔数组。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeBooleanArray([false, true, false]);
    hilog.info(0x0000, 'testTag', 'writeBooleanArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readBooleanArray

readBooleanArray(dataIn: boolean[]): void

从MessageParcel实例中读取布尔数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型      | 必填 | 说明               |
  | ------ | --------- | ---- | ------------------ |
  | dataIn | boolean[] | 是   | 要读取的布尔数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeBooleanArray([false, true, false]);
    hilog.info(0x0000, 'testTag', 'writeBooleanArray is ' + result);
    let array: Array<boolean> = new Array(3);
    data.readBooleanArray(array);
    hilog.info(0x0000, 'testTag', 'readBooleanArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readBooleanArray

readBooleanArray(): boolean[]

从MessageParcel实例中读取布尔数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型      | 说明           |
  | --------- | -------------- |
  | boolean[] | 返回布尔数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeBooleanArray([false, true, false]);
    hilog.info(0x0000, 'testTag', 'writeBooleanArray is ' + result);
    let array = data.readBooleanArray();
    hilog.info(0x0000, 'testTag', 'readBooleanArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeCharArray

writeCharArray(charArray: number[]): boolean

将单个字符数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明                   |
  | --------- | -------- | ---- | ---------------------- |
  | charArray | number[] | 是   | 要写入的单个字符数组。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeCharArray([97, 98, 88]);
    hilog.info(0x0000, 'testTag', 'writeCharArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readCharArray

readCharArray(dataIn: number[]): void

从MessageParcel实例中读取单个字符数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                   |
  | ------ | -------- | ---- | ---------------------- |
  | dataIn | number[] | 是   | 要读取的单个字符数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeCharArray([97, 98, 99]);
    hilog.info(0x0000, 'testTag', 'writeCharArray is ' + result);
    let array: Array<number> = new Array(3);
    data.readCharArray(array);
    hilog.info(0x0000, 'testTag', 'writeCharArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readCharArray

readCharArray(): number[]

从MessageParcel实例读取单个字符数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明               |
  | -------- | ------------------ |
  | number[] | 返回单个字符数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeCharArray([97, 98, 99]);
    hilog.info(0x0000, 'testTag', 'writeCharArray is ' + result);
    let array = data.readCharArray();
    hilog.info(0x0000, 'testTag', 'readCharArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeStringArray

writeStringArray(stringArray: string[]): boolean

将字符串数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型     | 必填 | 说明             |
  | ----------- | -------- | ---- | ---------------- |
  | stringArray | string[] | 是   | 要写入的字符串数组，数组单个元素的长度应小于40960字节。 |

**返回值：**

  | 类型    | 说明 |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeStringArray(["abc", "def"]);
    hilog.info(0x0000, 'testTag', 'writeStringArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readStringArray

readStringArray(dataIn: string[]): void

从MessageParcel实例读取字符串数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | string[] | 是   | 要读取的字符串数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeStringArray(["abc", "def"]);
    hilog.info(0x0000, 'testTag', 'writeStringArray is ' + result);
    let array: Array<string> = new Array(2);
    data.readStringArray(array);
    hilog.info(0x0000, 'testTag', 'readStringArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readStringArray

readStringArray(): string[]

从MessageParcel实例读取字符串数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | string[] | 返回字符串数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let data = rpc.MessageParcel.create();
    let result = data.writeStringArray(["abc", "def"]);
    hilog.info(0x0000, 'testTag', 'writeStringArray is ' + result);
    let array = data.readStringArray();
    hilog.info(0x0000, 'testTag', 'readStringArray is ' + array);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeNoException<sup>8+</sup>

writeNoException(): void

向MessageParcel写入“指示未发生异常”的信息。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
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

从MessageParcel中读取异常。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的sendRequest接口方法发送消息
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try { 
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
          hilog.info(0x0000, 'testTag', 'reply msg: ' + msg);
        } else {
          hilog.error(0x0000, 'testTag', 'sendRequest failed, errCode: ' + result.errCode);
        }
      }).catch((e: Error) => {
        hilog.error(0x0000, 'testTag', 'sendRequest got exception: ' + e);
      }).finally (() => {
        hilog.info(0x0000, 'testTag', 'sendRequest ends, reclaim parcel');
        data.reclaim();
        reply.reclaim();
      });
    }
  } catch (error) { 
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeSequenceableArray

writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean

将可序列化对象数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名            | 类型                                      | 必填 | 说明                       |
| ----------------- | ----------------------------------------- | ---- | -------------------------- |
| sequenceableArray | [Sequenceable](#sequenceabledeprecated)[] | 是   | 要写入的可序列化对象数组。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
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

  try {
    let sequenceable = new MySequenceable(1, "aaa");
    let sequenceable2 = new MySequenceable(2, "bbb");
    let sequenceable3 = new MySequenceable(3, "ccc");
    let a = [sequenceable, sequenceable2, sequenceable3];
    let data = rpc.MessageParcel.create();
    let result = data.writeSequenceableArray(a);
    hilog.info(0x0000, 'testTag', 'writeSequenceableArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readSequenceableArray<sup>8+</sup>

readSequenceableArray(sequenceableArray: Sequenceable[]): void

从MessageParcel实例读取可序列化对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名            | 类型                                      | 必填 | 说明                       |
| ----------------- | ----------------------------------------- | ---- | -------------------------- |
| sequenceableArray | [Sequenceable](#sequenceabledeprecated)[] | 是   | 要读取的可序列化对象数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
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

  try {
    let sequenceable = new MySequenceable(1, "aaa");
    let sequenceable2 = new MySequenceable(2, "bbb");
    let sequenceable3 = new MySequenceable(3, "ccc");
    let a = [sequenceable, sequenceable2, sequenceable3];
    let data = rpc.MessageParcel.create();
    let result = data.writeSequenceableArray(a);
    hilog.info(0x0000, 'testTag', 'writeSequenceableArray is ' + result);
    let b = [new MySequenceable(0, ""), new MySequenceable(0, ""), new MySequenceable(0, "")];
    data.readSequenceableArray(b);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeRemoteObjectArray<sup>8+</sup>

writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean

将IRemoteObject对象数组写入MessageParcel。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型            | 必填 | 说明  |
  | ----------- | --------------- | ---- | ----- |
  | objectArray | [IRemoteObject](#iremoteobject)[] | 是   | 要写入MessageParcel的IRemoteObject对象数组。 |

**返回值：**

  | 类型    | 说明                                                                                                                 |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      // 具体处理由业务决定
      return true;
    }
  }

  try {
    let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
    let data = rpc.MessageParcel.create();
    let result = data.writeRemoteObjectArray(a);
    hilog.info(0x0000, 'testTag', 'writeRemoteObjectArray is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readRemoteObjectArray<sup>8+</sup>

readRemoteObjectArray(objects: IRemoteObject[]): void

从MessageParcel读取IRemoteObject对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型            | 必填 | 说明      |
  | ------- | --------------- | ---- | --------- |
  | objects | [IRemoteObject](#iremoteobject)[] | 是   | 从MessageParcel读取的IRemoteObject对象数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      // 具体处理由业务决定
      return true;
    }
  }

  try {
    let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
    let data = rpc.MessageParcel.create();
    data.writeRemoteObjectArray(a);
    let b: Array<rpc.IRemoteObject> = new Array(3);
    data.readRemoteObjectArray(b);
    hilog.info(0x0000, 'testTag', 'readRemoteObjectArray is ' + b);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readRemoteObjectArray<sup>8+</sup>

readRemoteObjectArray(): IRemoteObject[]

从MessageParcel读取IRemoteObject对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型            | 说明                        |
  | --------------- | --------------------------- |
  | [IRemoteObject](#iremoteobject)[] | 返回IRemoteObject对象数组。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      // 具体处理由业务决定
      return true;
    }
  }

  try {
    let a = [new TestRemoteObject("testObject1"), new TestRemoteObject("testObject2"), new TestRemoteObject("testObject3")];
    let data = rpc.MessageParcel.create();
    let result = data.writeRemoteObjectArray(a);
    hilog.info(0x0000, 'testTag', 'readRemoteObjectArray is ' + result);
    let b = data.readRemoteObjectArray();
    hilog.info(0x0000, 'testTag', 'readRemoteObjectArray is ' + b);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### closeFileDescriptor<sup>8+</sup>

static closeFileDescriptor(fd: number): void

静态方法，关闭给定的文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                 |
  | ------ | ------ | ---- | -------------------- |
  | fd     | number | 是   | 要关闭的文件描述符。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let filePath = "path/to/file";
    let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    rpc.MessageParcel.closeFileDescriptor(file.fd);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### dupFileDescriptor<sup>8+</sup>

static dupFileDescriptor(fd: number) :number

静态方法，复制给定的文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                     |
  | ------ | ------ | ---- | ------------------------ |
  | fd     | number | 是   | 表示已存在的文件描述符。 |

**返回值：**

  | 类型   | 说明                 |
  | ------ | -------------------- |
  | number | 返回新的文件描述符。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let filePath = "path/to/file";
    let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    rpc.MessageParcel.dupFileDescriptor(file.fd);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### containFileDescriptors<sup>8+</sup>

containFileDescriptors(): boolean

检查此MessageParcel对象是否包含文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean |true：包含文件描述符，false：未包含文件描述符。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let parcel = new rpc.MessageParcel();
    let filePath = "path/to/file";
    let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    let writeResult = parcel.writeFileDescriptor(file.fd);
    hilog.info(0x0000, 'testTag', 'parcel writeFd result is ' + writeResult);
    let containFD = parcel.containFileDescriptors();
    hilog.info(0x0000, 'testTag', 'parcel after write fd containFd result is ' + containFD);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeFileDescriptor<sup>8+</sup>

writeFileDescriptor(fd: number): boolean

写入文件描述符到MessageParcel。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明         |
  | ------ | ------ | ---- | ------------ |
  | fd     | number | 是   | 文件描述符。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：操作成功，false：操作失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let parcel = new rpc.MessageParcel();
    let filePath = "path/to/file";
    let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    let writeResult = parcel.writeFileDescriptor(file.fd);
    hilog.info(0x0000, 'testTag', 'parcel writeFd result is ' + writeResult);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readFileDescriptor<sup>8+</sup>

readFileDescriptor(): number

从MessageParcel中读取文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | number | 返回文件描述符。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { fileIo } from '@kit.CoreFileKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let parcel = new rpc.MessageParcel();
    let filePath = "path/to/file";
    let file = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    parcel.writeFileDescriptor(file.fd);
    let readFD = parcel.readFileDescriptor();
    hilog.info(0x0000, 'testTag', 'parcel read fd is ' + readFD);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeAshmem<sup>8+</sup>

writeAshmem(ashmem: Ashmem): boolean

将指定的匿名共享对象写入此MessageParcel。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                |
| ------ | ------ | ---- | ----------------------------------- |
| ashmem | [Ashmem](#ashmem8) | 是   | 要写入MessageParcel的匿名共享对象。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let parcel = new rpc.MessageParcel();
    let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);
    let isWriteSuccess = parcel.writeAshmem(ashmem);
    hilog.info(0x0000, 'testTag', 'write ashmem to result is ' + isWriteSuccess);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readAshmem<sup>8+</sup>

readAshmem(): Ashmem

从MessageParcel读取匿名共享对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| [Ashmem](#ashmem8) | 返回匿名共享对象。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let parcel = new rpc.MessageParcel();
    let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);
    let isWriteSuccess = parcel.writeAshmem(ashmem);
    hilog.info(0x0000, 'testTag', 'write ashmem to result is ' + isWriteSuccess);
    let readAshmem = parcel.readAshmem();
    hilog.info(0x0000, 'testTag', 'read ashmem to result is ' + readAshmem);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getRawDataCapacity<sup>8+</sup>

getRawDataCapacity(): number

获取MessageParcel可以容纳的最大原始数据量。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                                       |
  | ------ | ---------------------------------------------------------- |
  | number | 返回MessageParcel可以容纳的最大原始数据量，即128MB。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let parcel = new rpc.MessageParcel();
    let result = parcel.getRawDataCapacity();
    hilog.info(0x0000, 'testTag', 'parcel get RawDataCapacity result is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeRawData<sup>8+</sup>

writeRawData(rawData: number[], size: number): boolean

将原始数据写入MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型     | 必填 | 说明                               |
  | ------- | -------- | ---- | ---------------------------------- |
  | rawData | number[] | 是   | 要写入的原始数据，大小不能超过128MB。|
  | size    | number   | 是   | 发送的原始数据大小，以字节为单位。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let parcel = new rpc.MessageParcel();
    let arr = [1, 2, 3, 4, 5];
    let isWriteSuccess = parcel.writeRawData(arr, arr.length);
    hilog.info(0x0000, 'testTag', 'parcel write raw data result is ' + isWriteSuccess);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### readRawData<sup>8+</sup>

readRawData(size: number): number[]

从MessageParcel读取原始数据。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                     |
  | ------ | ------ | ---- | ------------------------ |
  | size   | number | 是   | 要读取的原始数据的大小。 |

**返回值：**

  | 类型     | 说明                           |
  | -------- | ------------------------------ |
  | number[] | 返回原始数据（以字节为单位）。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let parcel = new rpc.MessageParcel();
    let arr = [1, 2, 3, 4, 5];
    let isWriteSuccess = parcel.writeRawData(arr, arr.length);
    hilog.info(0x0000, 'testTag', 'parcel write raw data result is ' + isWriteSuccess);
    let result = parcel.readRawData(5);
    hilog.info(0x0000, 'testTag', 'parcel read raw data result is ' + result);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

## Parcelable<sup>9+</sup>

在进程间通信（IPC）期间，将类的对象写入MessageSequence并从MessageSequence中恢复它们。

### marshalling<sup>9+</sup>

marshalling(dataOut: MessageSequence): boolean

将此可序列对象封送到MessageSequence中。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名  | 类型            | 必填 | 说明                                        |
| ------- | --------------- | ---- | ------------------------------------------- |
| dataOut |[MessageSequence](#messagesequence9)| 是   | 可序列对象将被封送到的MessageSequence对象。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：封送成功，false：封送失败。|

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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
      hilog.info(0x0000, 'testTag', 'readInt is ' + this.num + ' readString is ' + this.str);
      return true;
    }
  }

  try {
    let parcelable = new MyParcelable(1, "aaa");
    let data = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);
    let ret = new MyParcelable(0, "");
    data.readParcelable(ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### unmarshalling<sup>9+</sup>

unmarshalling(dataIn: MessageSequence): boolean

从MessageSequence中解封此可序列对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名 | 类型            | 必填 | 说明                                            |
| ------ | --------------- | ---- | ----------------------------------------------- |
| dataIn | [MessageSequence](#messagesequence9) | 是   | 已将可序列对象封送到其中的MessageSequence对象。 |

**返回值：**

  | 类型    | 说明                                     |
  | ------- | ---------------------------------------- |
  | boolean | true：反序列化成功，false：反序列化失败。|

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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
      hilog.info(0x0000, 'testTag', 'readInt is ' + this.num + ' readString is ' + this.str);
      return true;
    }
  }

  try {
    let parcelable = new MyParcelable(1, "aaa");
    let data = rpc.MessageSequence.create();
    data.writeParcelable(parcelable);
    let ret = new MyParcelable(0, "");
    data.readParcelable(ret);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

## Sequenceable<sup>(deprecated)</sup>

在进程间通信（IPC）期间，将类的对象写入MessageParcel并从MessageParcel中恢复它们。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[Parcelable](#parcelable9)替代。

### marshalling

marshalling(dataOut: MessageParcel): boolean

将此可序列对象封送到MessageParcel中。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                                      | 必填 | 说明                                      |
  | ------- | ----------------------------------------- | ---- | ----------------------------------------- |
  | dataOut | [MessageParcel](#messageparceldeprecated) | 是   | 可序列对象将被封送到的MessageParcel对象。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------  |
  | boolean | true：封送成功，false：封送失败。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
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

  try {
    let sequenceable = new MySequenceable(1, "aaa");
    let data = rpc.MessageParcel.create();
    let result = data.writeSequenceable(sequenceable);
    hilog.info(0x0000, 'testTag', 'writeSequenceable is ' + result);
    let ret = new MySequenceable(0, "");
    let result2 = data.readSequenceable(ret);
    hilog.info(0x0000, 'testTag', 'readSequenceable is ' + result2);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### unmarshalling

unmarshalling(dataIn: MessageParcel): boolean

从MessageParcel中解封此可序列对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                                      | 必填 | 说明                                          |
  | ------ | ----------------------------------------- | ---- | --------------------------------------------- |
  | dataIn | [MessageParcel](#messageparceldeprecated) | 是   | 已将可序列对象封送到其中的MessageParcel对象。 |

**返回值：**

  | 类型    | 说明                                     |
  | ------- | ---------------------------------------- |
  | boolean | true：反序列化成功，false：反序列化失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
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

  try {
    let sequenceable = new MySequenceable(1, "aaa");
    let data = rpc.MessageParcel.create();
    let result = data.writeSequenceable(sequenceable);
    hilog.info(0x0000, 'testTag', 'writeSequenceable is ' + result);
    let ret = new MySequenceable(0, "");
    let result2 = data.readSequenceable(ret);
    hilog.info(0x0000, 'testTag', 'readSequenceable is ' + result2);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

## IRemoteBroker

远端对象的代理持有者。用于获取代理对象。

### asObject

asObject(): IRemoteObject

需派生类实现，获取代理或远端对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型  | 说明  |
  | ----- | ----- |
  | [IRemoteObject](#iremoteobject) | 如果调用者是RemoteObject对象，则直接返回本身；如果调用者是[RemoteProxy](#remoteproxy)对象，则返回它的持有者[IRemoteObject](#iremoteobject)。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';

  class TestAbility extends rpc.RemoteObject {
    asObject() {
      return this;
    }
  }
  let remoteObject = new TestAbility("testObject").asObject();
  ```

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want  = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的asObject接口方法获取代理或远端对象

  ```ts
  import { rpc } from '@kit.IPCKit';

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

用于订阅远端对象的死亡通知。当被订阅该通知的远端对象死亡时，本端可收到消息，调用[onRemoteDied](#onremotedied)接口。远端对象死亡可以为远端对象所在进程死亡，远端对象所在设备关机或重启，当远端对象与本端对象属于不同设备时，也可为远端对象离开组网时。

### onRemoteDied

onRemoteDied(): void

在成功添加死亡通知订阅后，当远端对象死亡时，将自动调用本方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  ```

## RequestResult<sup>9+</sup>

发送请求的响应结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

| 名称    | 类型            | 只读 | 可选 | 说明                                  |
| ------- | --------------- | ---- | ---- |-------------------------------------- |
| errCode | number          | 否   | 否   | 错误码。                              |
| code    | number          | 否   | 否   | 消息代码。                            |
| data    | [MessageSequence](#messagesequence9) | 否   | 否   | 发送给对端进程的MessageSequence对象。 |
| reply   | [MessageSequence](#messagesequence9) | 否   | 否   | 对端进程返回的MessageSequence对象。   |

## SendRequestResult<sup>(deprecated)</sup>

发送请求的响应结果。

> **说明：**
>
> 从API version 8 开始支持，API version 9 开始废弃，建议使用[RequestResult](#requestresult9)替代。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

  | 名称    | 类型          | 只读 | 可选 | 说明                                |
  | ------- | ------------- | ---- | ---- | ----------------------------------- |
  | errCode | number        | 否   | 否   | 错误码。                            |
  | code    | number        | 否   | 否   | 消息代码。                          |
  | data    | [MessageParcel](#messageparceldeprecated) | 否   | 否   | 发送给对端进程的MessageParcel对象。 |
  | reply   | [MessageParcel](#messageparceldeprecated) | 否   | 否   | 对端进程返回的MessageParcel对象。   |

## IRemoteObject

该接口可用于查询或获取接口描述符、添加或删除死亡通知、转储对象状态到特定文件、发送消息。

### getLocalInterface<sup>9+</sup>

getLocalInterface(descriptor: string): IRemoteBroker

查询接口描述符的字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型   | 必填 | 说明                 |
  | ---------- | ------ | ---- | -------------------- |
  | descriptor | string | 是   | 接口描述符的字符串。 |

**返回值：**

| 类型          | 说明                                          |
| ------------- | --------------------------------------------- |
| [IRemoteBroker](#iremotebroker) | 返回绑定到指定接口描述符的IRemoteBroker对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The string length exceeds 40960 bytes; <br/> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |

### queryLocalInterface<sup>(deprecated)</sup>

queryLocalInterface(descriptor: string): IRemoteBroker

查询接口描述符的字符串。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[getLocalInterface](#getlocalinterface9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型   | 必填 | 说明                 |
  | ---------- | ------ | ---- | -------------------- |
  | descriptor | string | 是   | 接口描述符的字符串。 |

**返回值：**

| 类型          | 说明                                          |
| ------------- | --------------------------------------------- |
| [IRemoteBroker](#iremotebroker) | 返回绑定到指定接口描述符的IRemoteBroker对象。 |

### sendRequest<sup>(deprecated)</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

> **说明：**
>
> 从API version 9开始废弃，建议使用[sendMessageRequest](#sendmessagerequest9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                                      | 必填 | 说明                                                                                   |
  | ------- | ----------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                                    | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption)           | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：发送成功，false：发送失败。|

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise&lt;RequestResult&gt;

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendMessageRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                                 | 必填 | 说明                                                                                   |
  | ------- | ------------------------------------ | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                               | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的MessageSequence对象。                                            |
  | reply   | [MessageSequence](#messagesequence9) | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options | [MessageOption](#messageoption)      | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型                         | 说明                                      |
  | ---------------------------- | ----------------------------------------- |
  | Promise&lt;[RequestResult](#requestresult9)&gt; | 返回一个期约，兑现值是requestResult实例。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.Failed to obtain the passed object instance. |

### sendRequest<sup>(deprecated)</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[sendMessageRequest](#sendmessagerequest9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                                      | 必填 | 说明                                                                                   |
  | ------- | ----------------------------------------  | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                                    | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption)           | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | 返回一个期约，兑现值是sendRequestResult实例。 |

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback&lt;RequestResult&gt;): void

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型                                 | 必填 | 说明                                                                                   |
  | -------- | ------------------------------------ | ---- | -------------------------------------------------------------------------------------- |
  | code     | number                               | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data     | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的MessageSequence对象。                                            |
  | reply    | [MessageSequence](#messagesequence9) | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options  | [MessageOption](#messageoption)      | 是   | 本次请求的同异步模式，默认同步调用。                                                   |
  | callback | AsyncCallback&lt;[RequestResult](#requestresult9)&gt;   | 是   | 接收发送结果的回调。                                                                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.Failed to obtain the passed object instance. |

### sendRequest<sup>(deprecated)</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[sendMessageRequest](#sendmessagerequest9-1)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| code     | number                                                       | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
| data     | [MessageParcel](#messageparceldeprecated)                    | 是   | 保存待发送数据的MessageParcel对象。                    |
| reply    | [MessageParcel](#messageparceldeprecated)                    | 是   | 接收应答数据的MessageParcel对象。                            |
| options  | [MessageOption](#messageoption)                              | 是   | 本次请求的同异步模式，默认同步调用。                         |
| callback | AsyncCallback&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | 是   | 接收发送结果的回调。                                         |

### registerDeathRecipient<sup>9+</sup>

registerDeathRecipient(recipient: DeathRecipient, flags: number): void

注册用于接收远程对象死亡通知的回调。如果与RemoteProxy对象匹配的远程对象进程死亡，则调用此方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注册的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The callback used to receive remote object death notifications is empty. |
  | 1900005  | Operation allowed only for the proxy object. |
  | 1900008  | The proxy or remote object is invalid. |

### addDeathRecipient<sup>(deprecated)</sup>

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

注册用于接收远程对象死亡通知的回调。如果与RemoteProxy对象匹配的远程对象进程死亡，则调用此方法。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[registerDeathRecipient](#registerdeathrecipient9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注册的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**返回值：**

  | 类型    | 说明                                     |
  | ------- | ---------------------------------------- |
  | boolean | true：回调注册成功，false：回调注册失败。|

### unregisterDeathRecipient<sup>9+</sup>

unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void

注销用于接收远程对象死亡通知的回调。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注销的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The callback used to receive remote object death notifications is empty. |
  | 1900005  | Operation allowed only for the proxy object. |
  | 1900008  | The proxy or remote object is invalid. |

### removeDeathRecipient<sup>(deprecated)</sup>

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

注销用于接收远程对象死亡通知的回调。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[unregisterDeathRecipient](#unregisterdeathrecipient9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注销的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**返回值：**

  | 类型    | 说明                                     |
  | ------- | -----------------------------------------|
  | boolean | true：回调注销成功，false：回调注销失败。|

### getDescriptor<sup>9+</sup>

getDescriptor(): string

获取对象的接口描述符，接口描述符为字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | string | 返回接口描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900008  | The proxy or remote object is invalid. |

### getInterfaceDescriptor<sup>(deprecated)</sup>

getInterfaceDescriptor(): string

获取对象的接口描述符，接口描述符为字符串。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[getDescriptor](#getdescriptor9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | string | 返回接口描述符。 |

### isObjectDead

isObjectDead(): boolean

检查当前对象是否死亡。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                               |
  | ------- | ---------------------------------- |
  | boolean | true：对象死亡，false：对象未死亡。|

## RemoteProxy

实现IRemoteObject代理对象。

### 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

  | 名称                  | 类型   | 只读  | 可选 | 说明                                     |
  | --------------------- | -------| ------|------|------------------------------------------ |
  | PING_TRANSACTION      | number | 是    | 否   | 内部指令码，用于测试IPC服务是否正常。     |
  | DUMP_TRANSACTION      | number | 是    | 否   | 内部指令码，获取IPC服务相关的状态信息。   |
  | INTERFACE_TRANSACTION | number | 是    | 否   | 内部指令码，获取对端接口描述符。          |
  | MIN_TRANSACTION_ID    | number | 是    | 否   | 最小有效指令码。                          |
  | MAX_TRANSACTION_ID    | number | 是    | 否   | 最大有效指令码。                          |


### sendRequest<sup>(deprecated)</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

> **说明：**
>
> 从API version 8 开始废弃，建议使用[sendMessageRequest](#sendmessagerequest9-2)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                                      | 必填 | 说明                                                                                   |
  | ------- | ----------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                                    | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption)           | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型    | 说明                             |
  | ------- | ---------------------------------|
  | boolean | true：发送成功，false：发送失败。|

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的sendRequest接口方法发送消息
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
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
        hilog.info(0x0000, 'testTag', 'reply msg: ' + msg);
      } else {
        hilog.error(0x0000, 'testTag', 'sendRequest failed');
      }
      hilog.info(0x0000, 'testTag', 'sendRequest ends, reclaim parcel');
      data.reclaim();
      reply.reclaim();
    }
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error: ' + error);
  }
  ```

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise&lt;RequestResult&gt;

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendMessageRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                                 | 必填 | 说明                                                                                   |
  | ------- | ------------------------------------ | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                               | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的MessageSequence对象。                                            |
  | reply   | [MessageSequence](#messagesequence9) | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options | [MessageOption](#messageoption)      | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型                         | 说明                                      |
  | ---------------------------- | ----------------------------------------- |
  | Promise&lt;[RequestResult](#requestresult9)&gt; | 返回一个期约，兑现值是requestResult实例。 |


**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.Failed to obtain the passed object instance. |

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的sendMessageRequest接口方法发送消息

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
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
          hilog.info(0x0000, 'testTag', 'reply num: ' + num);
          hilog.info(0x0000, 'testTag', 'reply msg: ' + msg);
        } else {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode: ' + result.errCode);
        }
      }).catch((e: Error) => {
        hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, error: ' + e);
      }).finally (() => {
        hilog.info(0x0000, 'testTag', 'sendMessageRequest ends, reclaim parcel');
        data.reclaim();
        reply.reclaim();
      });
    }
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, error: ' + error);
  }
  ```

### sendRequest<sup>(deprecated)</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[sendMessageRequest](#sendmessagerequest9-2)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                                      | 必填 | 说明                                                                                   |
  | ------- | ----------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                                    | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption)           | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | 返回一个期约，兑现值是sendRequestResult实例。 |

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的sendRequest接口方法发送消息
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
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
          hilog.info(0x0000, 'testTag', 'reply num: ' + num);
          hilog.info(0x0000, 'testTag', 'reply msg: ' + msg);
        } else {
          hilog.error(0x0000, 'testTag', 'sendRequest failed, errCode: ' + result.errCode);
        }
      }).catch((e: Error) => {
        hilog.error(0x0000, 'testTag', 'sendRequest failed, error: ' + e);
      }).finally (() => {
        hilog.info(0x0000, 'testTag', 'sendRequest ends, reclaim parcel');
        data.reclaim();
        reply.reclaim();
      });
    }
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'sendRequest failed, error: ' + error);
  }
  ```

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback&lt;RequestResult&gt;): void

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendMessageRequest返回后的某个时机执行回调，回复内容在RequestResult的reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型                                 | 必填 | 说明                                                                                   |
  | -------- | ------------------------------------ | ---- | -------------------------------------------------------------------------------------- |
  | code     | number                               | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data     | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的MessageSequence对象。                                            |
  | reply    | [MessageSequence](#messagesequence9) | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options  | [MessageOption](#messageoption)      | 是   | 本次请求的同异步模式，默认同步调用。                                                   |
  | callback | AsyncCallback&lt;[RequestResult](#requestresult9)&gt;   | 是   | 接收发送结果的回调。                                                                   |


**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.Failed to obtain the passed object instance. |

### sendRequest<sup>(deprecated)</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[sendMessageRequest](#sendmessagerequest9-3)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| code     | number                                                       | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
| data     | [MessageParcel](#messageparceldeprecated)                    | 是   | 保存待发送数据的MessageParcel对象。                    |
| reply    | [MessageParcel](#messageparceldeprecated)                    | 是   | 接收应答数据的MessageParcel对象。                            |
| options  | [MessageOption](#messageoption)                              | 是   | 本次请求的同异步模式，默认同步调用。                         |
| callback | AsyncCallback&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | 是   | 接收发送结果的回调。                                         |

### getLocalInterface<sup>9+</sup>

getLocalInterface(interface: string): IRemoteBroker

查询并获取当前接口描述符对应的本地接口对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型   | 必填 | 说明                   |
  | --------- | ------ | ---- | ---------------------- |
  | interface | string | 是   | 需要查询的接口描述符。 |

**返回值：**

| 类型                            | 说明                                       |
| ------------------------------- | ------------------------------------------ |
| [IRemoteBroker](#iremotebroker) | 默认返回Null，标识该接口是一个代理侧接口。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | check param failed |
  | 1900006  | Operation allowed only for the remote object. |

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的getLocalInterface接口方法查询接口对象
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  if (proxy != undefined) {
    try {
      let broker: rpc.IRemoteBroker = proxy.getLocalInterface("testObject");
      hilog.info(0x0000, 'testTag', 'getLocalInterface is ' + broker);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorMessage ' + e.message);
    }
  }
  ```

### queryLocalInterface<sup>(deprecated)</sup>

queryLocalInterface(interface: string): IRemoteBroker

查询并获取当前接口描述符对应的本地接口对象。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[getLocalInterface](#getlocalinterface9-1)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型   | 必填 | 说明                   |
  | --------- | ------ | ---- | ---------------------- |
  | interface | string | 是   | 需要查询的接口描述符。 |

**返回值：**

| 类型                            | 说明                                       |
| ------------------------------- | ------------------------------------------ |
| [IRemoteBroker](#iremotebroker) | 默认返回Null，标识该接口是一个代理侧接口。 |

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的queryLocalInterface接口获取接口对象
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  if (proxy != undefined) {
    let broker: rpc.IRemoteBroker = proxy.queryLocalInterface("testObject");
    hilog.info(0x0000, 'testTag', 'queryLocalInterface is ' + broker);
  }
  ```

### registerDeathRecipient<sup>9+</sup>

registerDeathRecipient(recipient: DeathRecipient, flags: number): void

注册用于接收远程对象死亡通知的回调。如果与RemoteProxy对象匹配的远程对象进程死亡，则调用此方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注册的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The callback used to receive remote object death notifications is empty. |
  | 1900008  | The proxy or remote object is invalid. |

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的registerDeathRecipient接口注册死亡回调

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  if (proxy != undefined) {
    try {
      let deathRecipient = new MyDeathRecipient();
      proxy.registerDeathRecipient(deathRecipient, 0);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'proxy register deathRecipient fail, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'proxy register deathRecipient fail, errorMessage ' + e.message);
    }
  }
  ```

### addDeathRecipient<sup>(deprecated)</sup>

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

注册用于接收远程对象死亡通知的回调，增加proxy对象上的死亡通知。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[registerDeathRecipient](#registerdeathrecipient9-1)类替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明                              |
  | --------- | --------------------------------- | ---- | --------------------------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 收件人表示要注册的回调。          |
  | flags     | number                            | 是   | 死亡通知标志。保留参数。设置为0。 |

**返回值：**

  | 类型    | 说明                                     |
  | ------- | ---------------------------------------- |
  | boolean | true：回调注册成功，false：回调注册失败。|

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的addDeathRecipient接口方法新增死亡回调
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  if (proxy != undefined) {
    let deathRecipient = new MyDeathRecipient();
    proxy.addDeathRecipient(deathRecipient, 0);
  }
  ```

### unregisterDeathRecipient<sup>9+</sup>

unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void

注销用于接收远程对象死亡通知的回调。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注销的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The callback used to receive remote object death notifications is empty. |
  | 1900008  | The proxy or remote object is invalid. |

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的unregisterDeathRecipient接口方法注销死亡回调

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  if (proxy != undefined) {
    try {
      let deathRecipient = new MyDeathRecipient();
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

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

注销用于接收远程对象死亡通知的回调。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[unregisterDeathRecipient](#unregisterdeathrecipient9-1)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明                              |
  | --------- | --------------------------------- | ---- | --------------------------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注销的死亡回调。                |
  | flags     | number                            | 是   | 死亡通知标志。保留参数。设置为0。 |

**返回值：**

  | 类型    | 说明                                     |
  | ------- | ---------------------------------------- |
  | boolean | true：回调注销成功，false：回调注销失败。|

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的removeDeathRecipient接口方法去注册死亡回调
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  if (proxy != undefined) {
    let deathRecipient = new MyDeathRecipient();
    proxy.addDeathRecipient(deathRecipient, 0);
    proxy.removeDeathRecipient(deathRecipient, 0);
  }
  ```

### getDescriptor<sup>9+</sup>

getDescriptor(): string

获取对象的接口描述符，接口描述符为字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | string | 返回接口描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900007  | communication failed.              |
  | 1900008  | The proxy or remote object is invalid. |

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```
  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的getDescriptor接口方法获取对象的接口描述符

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  if (proxy != undefined) {
    try {
      let descriptor: string = proxy.getDescriptor();
      hilog.info(0x0000, 'testTag', 'descriptor is ' + descriptor);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'rpc get interface descriptor fail, errorCode ' + e.code);
      hilog.error(0x0000, 'testTag', 'rpc get interface descriptor fail, errorMessage ' + e.message);
    }
  }
  ```

### getInterfaceDescriptor<sup>(deprecated)</sup>

getInterfaceDescriptor(): string

查询当前代理对象接口的描述符。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[getDescriptor](#getdescriptor9-1)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明               |
  | ------ | ------------------ |
  | string | 当前的接口描述符。 |

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的getInterfaceDescriptor接口方法查询当前代理对象接口的描述符
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  if (proxy != undefined) {
    let descriptor: string = proxy.getInterfaceDescriptor();
    hilog.info(0x0000, 'testTag', 'descriptor is ' + descriptor);
  }
  ```

### isObjectDead

isObjectDead(): boolean

指示对应的RemoteObject是否死亡。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                              |
  | ------- | ------------------------------------------------- |
  | boolean | true：对应的对象已经死亡，false：对应的对象未死亡。 |

**示例：**

>**说明：**
>
>在本文档的示例中，通过this.getUIContext().getHostContext()来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需要在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

  <!--code_no_check-->
  ```ts
  // FA模型需要从@kit.AbilityKit导入featureAbility
  // import { featureAbility } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { Want, common } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;
  let connect: common.ConnectOptions = {
    onConnect: (elementName, remoteProxy) => {
      hilog.info(0x0000, 'testTag', 'js onConnect called');
      proxy = remoteProxy;
    },
    onDisconnect: (elementName) => {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    },
    onFailed: () => {
      hilog.info(0x0000, 'testTag', 'onFailed');
    }
  };
  let want: Want = {
    bundleName: "com.ohos.server",
    abilityName: "com.ohos.server.EntryAbility",
  };

  // FA模型使用此方法连接服务
  // FA.connectAbility(want,connect);

  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
  // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
  let connectionId = context.connectServiceExtensionAbility(want, connect);
  ```

  上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的isObjectDead接口方法判断当前对象是否已经死亡

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  if (proxy != undefined) {
    let isDead: boolean = proxy.isObjectDead();
    hilog.info(0x0000, 'testTag', 'isObjectDead is ' + isDead);
  }
  ```

## MessageOption

公共消息选项，使用指定的标志类型，构造指定的MessageOption对象。

### 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

  | 名称          | 类型   | 只读  | 可选  | 说明                                                                      |
  | ------------- | ------ | ----- | ----- | ------------------------------------------------------------------------ |
  | TF_SYNC       | number | 是    | 否    | 同步调用标识。                                                            |
  | TF_ASYNC      | number | 是    | 否    | 异步调用标识。                                                            |
  | TF_ACCEPT_FDS | number | 是    | 否    | 指示sendMessageRequest<sup>9+</sup>接口可以传递文件描述符。               |
  | TF_WAIT_TIME  | number | 是    | 是    | RPC等待时间(单位/秒)，IPC场景下无效。默认等待为8秒（不建议修改等待时间）。 |

### constructor<sup>9+</sup>

constructor(async?: boolean)

MessageOption构造函数。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| async  | boolean | 否   | true：表示异步调用标志，false：表示同步调用标志。默认同步调用。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';

  class TestRemoteObject extends rpc.MessageOption {
    constructor(async: boolean) {
      super(async);
    }
  }
  ```

### constructor

constructor(syncFlags?: number, waitTime?: number)

MessageOption构造函数。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型   | 必填 | 说明                                          |
  | --------- | ------ | ---- | --------------------------------------------- |
  | syncFlags | number | 否   | 同步调用或异步调用标志，同步调用标志：0；异步调用标志：1。默认同步调用。        |
  | waitTime  | number | 否   | 调用rpc最长等待时间。默认TF_WAIT_TIME。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';

  class TestRemoteObject extends rpc.MessageOption {
    constructor(syncFlags?: number,waitTime?: number) {
      super(syncFlags,waitTime);
    }
  }
  ```
### isAsync<sup>9+</sup>

isAsync(): boolean

获取SendMessageRequest调用中确定同步或是异步的标志。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                     |
  | ------- | ---------------------------------------- |
  | boolean | true：异步调用成功，false：同步调用成功。|

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let option = new rpc.MessageOption();
    let result = option.isAsync();
  } catch (error) {
    hilog.info(0x0000, 'testTag', 'error ' + error);
  }
  ```

### setAsync<sup>9+</sup>

setAsync(async: boolean): void

设置SendMessageRequest调用中确定同步或是异步的标志。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                              |
| ------ | ------- | ---- | ------------------------------------------------- |
| async  | boolean | 是   | true：表示异步调用标志，false：表示同步调用标志。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let option = new rpc.MessageOption();
    option.setAsync(true);
  } catch (error) {
    hilog.info(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getFlags

getFlags(): number

获取同步调用或异步调用标志。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                 |
  | ------ | ------------------------------------ |
  | number | 调用成功返回同步调用或异步调用标志。同步调用标志：0，异步调用标志：1。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let option = new rpc.MessageOption();
    hilog.info(0x0000, 'testTag', 'create object successfully');
    let flag = option.getFlags();
    hilog.info(0x0000, 'testTag', 'run getFlags success, flag is ' + flag);
    option.setFlags(rpc.MessageOption.TF_ASYNC);
    hilog.info(0x0000, 'testTag', 'run setFlags success');
    let flag2 = option.getFlags();
    hilog.info(0x0000, 'testTag', 'run getFlags success, flag2 is ' + flag2);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### setFlags

setFlags(flags: number): void

设置同步调用或异步调用标志。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                     |
  | ------ | ------ | ---- | ------------------------ |
  | flags  | number | 是   | 同步调用或异步调用标志。同步调用标志：0；异步调用标志：1 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let option = new rpc.MessageOption();
    option.setFlags(rpc.MessageOption.TF_ASYNC);
    hilog.info(0x0000, 'testTag', 'run setFlags success');
    let flag = option.getFlags();
    hilog.info(0x0000, 'testTag', 'run getFlags success, flag is ' + flag);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getWaitTime

getWaitTime(): number

获取rpc调用的最长等待时间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明              |
  | ------ | ----------------- |
  | number | rpc最长等待时间。默认TF_WAIT_TIME。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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

设置rpc调用最长等待时间。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型   | 必填 | 说明                  |
  | -------- | ------ | ---- | --------------------- |
  | waitTime | number | 是   | rpc调用最长等待时间，上限为3000秒。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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

用于获取IPC上下文信息，包括获取UID和PID、获取本端和对端设备ID、检查接口调用是否在同一设备上。

### getContextObject

static getContextObject(): IRemoteObject

静态方法，获取系统能力的管理者。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型                            | 说明                 |
  | ------------------------------- | -------------------- |
  | [IRemoteObject](#iremoteobject) | 返回系统能力管理者。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let samgr = rpc.IPCSkeleton.getContextObject();
    hilog.info(0x0000, 'testTag', 'RpcServer: getContextObject result: ' + samgr);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### getCallingPid

static getCallingPid(): number

静态方法，获取调用者的PID。此方法由RemoteObject对象在onRemoteRequest方法中调用，不在IPC上下文环境（onRemoteRequest）中调用则返回本进程的PID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明              |
  | ------ | ----------------- |
  | number | 返回调用者的PID。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      try {
        let callerPid = rpc.IPCSkeleton.getCallingPid();
        hilog.info(0x0000, 'testTag', 'RpcServer: getCallingPid result: ' + callerPid);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'error ' + error);
      }
      return true;
    }
 }
  ```

### getCallingUid

static getCallingUid(): number

静态方法，获取调用者的UID。此方法由RemoteObject对象在onRemoteRequest方法中调用，不在IPC上下文环境（onRemoteRequest）中调用则返回本进程的UID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明              |
  | ------ | ----------------- |
  | number | 返回调用者的UID。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      try {
        let callerUid = rpc.IPCSkeleton.getCallingUid();
        hilog.info(0x0000, 'testTag', 'RpcServer: getCallingUid result: ' + callerUid);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'error ' + error);
      }
      return true;
    }
  }
  ```

### getCallingTokenId<sup>8+</sup>

static getCallingTokenId(): number

静态方法，获取调用者的TokenId，用于被调用方对调用方的身份校验。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

   | 类型   | 说明                  |
   | ------ | --------------------- |
   | number | 返回调用者的TokenId。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      try {
        let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();
        hilog.info(0x0000, 'testTag', 'RpcServer: getCallingTokenId result: ' + callerTokenId);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'error ' + error);
      }
      return true;
    }
  }
  ```

### getCallingDeviceID

static getCallingDeviceID(): string

静态方法，获取调用者进程所在的设备ID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                         |
  | ------ | ---------------------------- |
  | string | 返回调用者进程所在的设备ID。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      try {
        let callerDeviceID = rpc.IPCSkeleton.getCallingDeviceID();
        hilog.info(0x0000, 'testTag', 'RpcServer: callerDeviceID is ' + callerDeviceID);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'error ' + error);
      }
      return true;
    }
  }
  ```

### getLocalDeviceID

static getLocalDeviceID(): string

静态方法，获取本端设备ID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明               |
  | ------ | ------------------ |
  | string | 返回本地设备的ID。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      try {
        let localDeviceID = rpc.IPCSkeleton.getLocalDeviceID();
        hilog.info(0x0000, 'testTag', 'RpcServer: localDeviceID is ' + localDeviceID);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'error ' + error);
      }
      return true;
    }
  }
  ```

### isLocalCalling

static isLocalCalling(): boolean

静态方法，检查当前通信对端是否是本设备的进程。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                               |
  | ------- | -------------------------------------------------- |
  | boolean | true：调用在同一台设备，false：调用未在同一台设备。|

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      try {
        let isLocalCalling = rpc.IPCSkeleton.isLocalCalling();
        hilog.info(0x0000, 'testTag', 'RpcServer: isLocalCalling is ' + isLocalCalling);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'error ' + error);
      }
      return true;
    }
  }
  ```

### flushCmdBuffer<sup>9+</sup>

static flushCmdBuffer(object: IRemoteObject): void

静态方法，将所有挂起的命令从指定的RemoteProxy刷新到相应的RemoteObject。建议在任何时间执行敏感操作之前调用此方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                            | 必填 | 说明                |
  | ------ | ------------------------------- | ---- | ------------------- |
  | object | [IRemoteObject](#iremoteobject) | 是   | 指定的RemoteProxy。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }
  try {
    let remoteObject = new TestRemoteObject("aaa");
    rpc.IPCSkeleton.flushCmdBuffer(remoteObject);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'proxy flushCmdBuffer fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'proxy flushCmdBuffer fail, errorMessage ' + e.message);
  }
  ```

### flushCommands<sup>(deprecated)</sup>

static flushCommands(object: IRemoteObject): number

静态方法，将所有挂起的命令从指定的RemoteProxy刷新到相应的RemoteObject。建议在任何时间执行敏感操作之前调用此方法。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[flushCmdBuffer](#flushcmdbuffer9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                            | 必填 | 说明                |
  | ------ | ------------------------------- | ---- | ------------------- |
  | object | [IRemoteObject](#iremoteobject) | 是   | 指定的RemoteProxy。 |

**返回值：**

  | 类型   | 说明                                                                              |
  | ------ | --------------------------------------------------------------------------------- |
  | number | 如果操作成功，返回0；如果输入对象为空或RemoteObject，或者操作失败，返回错误代码。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }
  try {
    let remoteObject = new TestRemoteObject("aaa");
    let ret = rpc.IPCSkeleton.flushCommands(remoteObject);
    hilog.info(0x0000, 'testTag', 'RpcServer: flushCommands result: ' + ret);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'proxy flushCmdBuffer fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'proxy flushCmdBuffer fail, errorMessage ' + e.message);
  }
  ```

### resetCallingIdentity

static resetCallingIdentity(): string

静态方法，将远程用户的UID和PID替换为本地用户的UID和PID。它可以用于身份验证等场景。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                 |
  | ------ | ------------------------------------ |
  | string | 返回包含远程用户的UID和PID的字符串。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      try {
        let callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();
        hilog.info(0x0000, 'testTag', 'RpcServer: callingIdentity is ' + callingIdentity);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'error ' + error);
      }
      return true;
    }
  }
  ```

### restoreCallingIdentity<sup>9+</sup>

static restoreCallingIdentity(identity: string): void

静态方法，将UID和PID恢复为远程用户的UID和PID。它通常在使用resetCallingIdentity后调用，需要resetCallingIdentity返回的远程用户的UID和PID。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型   | 必填 | 说明                                                               |
  | -------- | ------ | ---- | ------------------------------------------------------------------ |
  | identity | string | 是   | 标识表示包含远程用户UID和PID的字符串，其长度应小于40960字节。由resetCallingIdentity返回。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The string length exceeds 40960 bytes; <br/> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      try {
        let callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();
        hilog.info(0x0000, 'testTag', 'RpcServer: callingIdentity is ' + callingIdentity);
        rpc.IPCSkeleton.restoreCallingIdentity(callingIdentity);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'error ' + error);
      }
      return true;
    }
  }
  ```

### setCallingIdentity<sup>(deprecated)</sup>

static setCallingIdentity(identity: string): boolean

静态方法，将UID和PID恢复为远程用户的UID和PID。它通常在使用resetCallingIdentity后调用，需要resetCallingIdentity返回的远程用户的UID和PID。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[restoreCallingIdentity](#restorecallingidentity9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型   | 必填 | 说明                                                               |
  | -------- | ------ | ---- | ------------------------------------------------------------------ |
  | identity | string | 是   | 标识表示包含远程用户UID和PID的字符串。由resetCallingIdentity返回。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | ---------------------------------|
  | boolean | true：设置成功，false：设置失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class Stub extends rpc.RemoteObject {
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      try {
        let callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();
        hilog.info(0x0000, 'testTag', 'RpcServer: callingIdentity is ' + callingIdentity);
        let ret = rpc.IPCSkeleton.setCallingIdentity(callingIdentity);
        hilog.info(0x0000, 'testTag', 'RpcServer: setCallingIdentity is ' + ret);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'error ' + error);
      }
      return true;
    }
  }
  ```

## RemoteObject

实现远程对象。服务提供者必须继承此类。

### constructor

constructor(descriptor: string)

RemoteObject构造函数。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型   | 必填 | 说明         |
  | ---------- | ------ | ---- | ------------ |
  | descriptor | string | 是   | 接口描述符，其长度应小于40960字节。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
  }
  ```
### sendRequest<sup>(deprecated)</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

> **说明：**
>
> 从API version 8 开始废弃，建议使用[sendMessageRequest](#sendmessagerequest9-4)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                                      | 必填 | 说明                                                                                   |
  | ------- | ----------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                                    | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption)           | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：发送成功，false：发送失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class testRemoteObject extends rpc.RemoteObject {
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }
  try {
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
      hilog.info(0x0000, 'testTag', 'reply msg: ' + msg);
    } else {
      hilog.error(0x0000, 'testTag', 'sendRequest failed');
    }
    hilog.info(0x0000, 'testTag', 'sendRequest ends, reclaim parcel');
    data.reclaim();
    reply.reclaim();
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise&lt;RequestResult&gt;

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendMessageRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                                 | 必填 | 说明                                                                                   |
  | ------- | ------------------------------------ | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                               | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的MessageSequence对象。                                            |
  | reply   | [MessageSequence](#messagesequence9) | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options | [MessageOption](#messageoption)      | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

| 类型                                            | 说明                                      |
| ----------------------------------------------- | ----------------------------------------- |
| Promise&lt;[RequestResult](#requestresult9)&gt; | 返回一个期约，兑现值是RequestResult实例。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.Failed to obtain the passed object instance. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }
  try {
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
          hilog.info(0x0000, 'testTag', 'reply num: ' + num);
          hilog.info(0x0000, 'testTag', 'reply msg: ' + msg);
        } else {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode: ' + result.errCode);
        }
      }).catch((e: Error) => {
        hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, error: ' + e);
      }).finally (() => {
        hilog.info(0x0000, 'testTag', 'sendMessageRequest ends, reclaim parcel');
        data.reclaim();
        reply.reclaim();
      });
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, error: ' + error);
  }
  ```

### sendRequest<sup>(deprecated)</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[sendMessageRequest](#sendmessagerequest9-4)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                                      | 必填 | 说明                                                                                   |
  | ------- | ----------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                                    | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption)           | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

| 类型                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| Promise&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | 返回一个期约，兑现值是sendRequestResult实例。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }
  try {
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
        hilog.info(0x0000, 'testTag', 'reply num: ' + num);
        hilog.info(0x0000, 'testTag', 'reply msg: ' + msg);
      } else {
        hilog.error(0x0000, 'testTag', 'sendRequest failed, errCode: ' + result.errCode);
      }
    }).catch((e: Error) => {
      hilog.error(0x0000, 'testTag', 'sendRequest failed, error: ' + e);
    }).finally (() => {
      hilog.info(0x0000, 'testTag', 'sendRequest ends, reclaim parcel');
      data.reclaim();
      reply.reclaim();
    });
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error: ' + error);
  }
  ```

### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback&lt;RequestResult&gt;): void

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendMessageRequest返回时收到回调，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名        | 类型                                                  | 必填 | 说明                                                         |
| ------------- | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| code          | number                                                | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
| data          | [MessageSequence](#messagesequence9)                  | 是   | 保存待发送数据的MessageSequence对象。                  |
| reply         | [MessageSequence](#messagesequence9)                  | 是   | 接收应答数据的MessageSequence对象。                          |
| options       | [MessageOption](#messageoption)                       | 是   | 本次请求的同异步模式，默认同步调用。                         |
| callback      | AsyncCallback&lt;[RequestResult](#requestresult9)&gt; | 是   | 接收发送结果的回调。                                         |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.Failed to obtain the passed object instance. |

### sendRequest<sup>(deprecated)</sup> 

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[sendMessageRequest](#sendmessagerequest9-5)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名        | 类型                                                         | 必填 | 说明                                                         |
| ------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| code          | number                                                       | 是   | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
| data          | [MessageParcel](#messageparceldeprecated)                    | 是   | 保存待发送数据的MessageParcel对象。                    |
| reply         | [MessageParcel](#messageparceldeprecated)                    | 是   | 接收应答数据的MessageParcel对象。                            |
| options       | [MessageOption](#messageoption)                              | 是   | 本次请求的同异步模式，默认同步调用。                         |
| callback      | AsyncCallback&lt;[SendRequestResult](#sendrequestresultdeprecated)&gt; | 是   | 接收发送结果的回调。                                         |

### onRemoteMessageRequest<sup>9+</sup>

onRemoteMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): boolean | Promise\<boolean>

> **说明：**
>
> 开发者应优先选择重载onRemoteMessageRequest方法，其中可以自由实现同步和异步的消息处理。
> 开发者同时重载onRemoteRequest和onRemoteMessageRequest方法时，仅onRemoteMessageRequest方法生效。

sendMessageRequest请求的响应处理函数，服务端在该函数里同步或异步地处理请求，回复结果。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                                 | 必填 | 说明                                      |
  | ------ | ------------------------------------ | ---- | ----------------------------------------- |
  | code   | number                               | 是   | 对端发送的服务请求码。                    |
  | data   | [MessageSequence](#messagesequence9) | 是   | 携带客户端调用参数的MessageSequence对象。 |
  | reply  | [MessageSequence](#messagesequence9) | 是   | 写入结果的MessageSequence对象。           |
  | options | [MessageOption](#messageoption)      | 是   | 指示操作是同步还是异步。                  |

**返回值：**

  | 类型              | 说明                                                                                            |
  | ----------------- | ----------------------------------------------------------------------------------------------- |
  | boolean \| Promise\<boolean>  | - 若在onRemoteMessageRequest中同步处理请求，则返回一个布尔值。返回true表示操作成功，返回false表示操作失败。</br>- 若在onRemoteMessageRequest中异步处理请求，则返回一个Promise对象。返回true表示操作成功，返回false表示操作失败。|

**重载onRemoteMessageRequest方法同步处理请求示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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

  **重载onRemoteMessageRequest方法异步处理请求示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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

**同时重载onRemoteMessageRequest和onRemoteRequest方法同步处理请求示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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
      // 同时调用仅会执行onRemoteMessageRequest
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

  **同时重载onRemoteMessageRequest和onRemoteRequest方法异步处理请求示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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
    // 同时调用仅会执行onRemoteMessageRequest
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

onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

sendRequest请求的响应处理函数，服务端在该函数里处理请求，回复结果。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[onRemoteMessageRequest](#onremotemessagerequest9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                                      | 必填 | 说明                                    |
  | ------ | ----------------------------------------- | ---- | --------------------------------------- |
  | code   | number                                    | 是   | 对端发送的服务请求码。                  |
  | data   | [MessageParcel](#messageparceldeprecated) | 是   | 携带客户端调用参数的MessageParcel对象。 |
  | reply  | [MessageParcel](#messageparceldeprecated) | 是   | 写入结果的MessageParcel对象。           |
  | options | [MessageOption](#messageoption)           | 是   | 指示操作是同步还是异步。                |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：操作成功，false：操作失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
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

获取通信对端的进程Uid。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
  | 类型   | 说明                    |
  | ------ | ----------------------- |
  | number | 返回通信对端的进程Uid。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }
  try {
    let testRemoteObject = new TestRemoteObject("testObject");
    hilog.info(0x0000, 'testTag', 'RpcServer: getCallingUid: ' + testRemoteObject.getCallingUid());
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error: ' + error);
  }
  ```

### getCallingPid

getCallingPid(): number

获取通信对端的进程Pid。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                    |
  | ------ | ----------------------- |
  | number | 返回通信对端的进程Pid。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }
  try {
    let testRemoteObject = new TestRemoteObject("testObject");
    hilog.info(0x0000, 'testTag', 'RpcServer: getCallingPid: ' + testRemoteObject.getCallingPid());
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error: ' + error);
  }
  ```

### getLocalInterface<sup>9+</sup>

getLocalInterface(descriptor: string): IRemoteBroker

查询接口描述符的字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型   | 必填 | 说明                 |
  | ---------- | ------ | ---- | -------------------- |
  | descriptor | string | 是   | 接口描述符的字符串，其长度应小于40960字节。 |

**返回值：**

  | 类型          | 说明                                          |
  | ------------- | --------------------------------------------- |
  | [IRemoteBroker](#iremotebroker) | 返回绑定到指定接口描述符的IRemoteBroker对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The string length exceeds 40960 bytes; <br/> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }
  try {
    let testRemoteObject = new TestRemoteObject("testObject");
    testRemoteObject.getLocalInterface("testObject");
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### queryLocalInterface<sup>(deprecated)</sup>

queryLocalInterface(descriptor: string): IRemoteBroker

查询并获取当前接口描述符对应的远端对象是否已经存在。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[getLocalInterface](#getlocalinterface9-2)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型   | 必填 | 说明                   |
  | ---------- | ------ | ---- | ---------------------- |
  | descriptor | string | 是   | 需要查询的接口描述符。 |

**返回值：**

  | 类型          | 说明                                                               |
  | ------------- | ------------------------------------------------------------------ |
  | [IRemoteBroker](#iremotebroker) | 如果接口描述符对应的远端对象存在，则返回该远端对象，否则返回Null。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }
  try {
    let testRemoteObject = new TestRemoteObject("testObject");
    testRemoteObject.queryLocalInterface("testObject");
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error: ' + error);
  }
  ```

### getDescriptor<sup>9+</sup>

getDescriptor(): string

获取对象的接口描述符。接口描述符为字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | string | 返回接口描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900008  | The proxy or remote object is invalid. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }
  try {
    let descriptor = testRemoteObject.getDescriptor();
    hilog.info(0x0000, 'testTag', 'RpcServer: descriptor is ' + descriptor);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### getInterfaceDescriptor<sup>(deprecated)</sup>

getInterfaceDescriptor(): string

查询接口描述符。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[getDescriptor](#getdescriptor9-2)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | string | 返回接口描述符。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  class TestRemoteObject extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
      // 根据业务实际逻辑，进行相应处理
      return true;
    }
  }

  try {
    let testRemoteObject = new TestRemoteObject("testObject");
    let descriptor = testRemoteObject.getInterfaceDescriptor();
    hilog.info(0x0000, 'testTag', 'RpcServer: descriptor is: ' + descriptor);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### modifyLocalInterface<sup>9+</sup>

modifyLocalInterface(localInterface: IRemoteBroker, descriptor: string): void

此接口用于把接口描述符和IRemoteBroker对象绑定。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名         | 类型                            | 必填 | 说明                                  |
| -------------- | ------------------------------- | ---- | ------------------------------------- |
| localInterface | [IRemoteBroker](#iremotebroker) | 是   | 将与描述符绑定的IRemoteBroker对象。   |
| descriptor     | string                          | 是   | 用于与IRemoteBroker对象绑定的描述符，其长度应小于40960字节。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The string length exceeds 40960 bytes; <br/> 4.The number of bytes copied to the buffer is different from the length of the obtained string. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
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
        hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
        hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
      }
    }
    registerDeathRecipient(recipient: MyDeathRecipient, flags: number) {
      // 方法逻辑需开发者根据业务需要实现
    }
    unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number) {
      // 方法逻辑需开发者根据业务需要实现
    }
  }
  let testRemoteObject = new TestRemoteObject("testObject");
  ```

### attachLocalInterface<sup>(deprecated)</sup>

attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void

此接口用于把接口描述符和IRemoteBroker对象绑定。

> **说明：**
>
> 从API version 9 开始废弃，建议使用[modifyLocalInterface](#modifylocalinterface9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名         | 类型                            | 必填 | 说明                                  |
| -------------- | ------------------------------- | ---- | ------------------------------------- |
| localInterface | [IRemoteBroker](#iremotebroker) | 是   | 将与描述符绑定的IRemoteBroker对象。   |
| descriptor     | string                          | 是   | 用于与IRemoteBroker对象绑定的描述符。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
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
      // 方法逻辑需开发者根据业务需要实现
      return true;
    }
    removeDeathRecipient(recipient: MyDeathRecipient, flags: number): boolean {
      // 方法逻辑需开发者根据业务需要实现
      return true;
    }

  }
  let testRemoteObject = new TestRemoteObject("testObject");
  ```

## Ashmem<sup>8+</sup>

提供与匿名共享内存对象相关的方法，包括创建、关闭、映射和取消映射Ashmem、从Ashmem读取数据和写入数据、获取Ashmem大小、设置Ashmem保护。
共享内存只适用与本设备内跨进程通信。

### 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

  | 名称       | 类型   | 只读  | 可选  | 说明                                     |
  | ---------- | ------ | ----- | ----- |----------------------------------------- |
  | PROT_EXEC  | number | 是    | 否    | 映射内存保护类型，代表映射的内存可执行。  |
  | PROT_NONE  | number | 是    | 否    | 映射内存保护类型，代表映射的内存不可访问。|
  | PROT_READ  | number | 是    | 否    | 映射内存保护类型，代表映射的内存可读。    |
  | PROT_WRITE | number | 是    | 否    | 映射内存保护类型，代表映射的内存可写。    |

### create<sup>9+</sup>

static create(name: string, size: number): Ashmem

静态方法，根据指定的名称和大小创建Ashmem对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                         |
  | ------ | ------ | ---- | ---------------------------- |
  | name   | string | 是   | Ashmem名称，用于查询Ashmem信息，其长度不能为0。   |
  | size   | number | 是   | Ashmem的大小，其大小应大于0，以字节为单位。 |

**返回值：**

| 类型               | 说明                                           |
| ------------------ | ---------------------------------------------- |
| [Ashmem](#ashmem8) | 返回创建的Ashmem对象；如果创建失败，返回null。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The Ashmem name passed is empty; <br/> 4.The Ashmem size passed is less than or equal to 0. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    hilog.info(0x0000, 'testTag', 'create ashmem: ' + ashmem);
    let size = ashmem.getAshmemSize();
    hilog.info(0x0000, 'testTag',  'size is ' + size);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### createAshmem<sup>(deprecated)</sup>

static createAshmem(name: string, size: number): Ashmem

静态方法，根据指定的名称和大小创建Ashmem对象。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[create](#create9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                         |
  | ------ | ------ | ---- | ---------------------------- |
  | name   | string | 是   | 名称，用于查询Ashmem信息。   |
  | size   | number | 是   | Ashmem的大小，以字节为单位。 |

**返回值：**

| 类型               | 说明                                           |
| ------------------ | ---------------------------------------------- |
| [Ashmem](#ashmem8) | 返回创建的Ashmem对象；如果创建失败，返回null。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
    hilog.info(0x0000, 'testTag', 'create ashmem: ' + ashmem);
    let size = ashmem.getAshmemSize();
    hilog.info(0x0000, 'testTag',  'size is ' + size);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }

  ```

### create<sup>9+</sup>

static create(ashmem: Ashmem): Ashmem

静态方法，通过复制现有Ashmem对象的文件描述符(fd)来创建Ashmem对象。两个Ashmem对象指向同一个共享内存区域。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名 | 类型               | 必填 | 说明                 |
| ------ | ------------------ | ---- | -------------------- |
| ashmem | [Ashmem](#ashmem8) | 是   | 已存在的Ashmem对象。 |

**返回值：**

| 类型               | 说明                   |
| ------------------ | ---------------------- |
| [Ashmem](#ashmem8) | 返回创建的Ashmem对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The passed parameter is not an Ahmem object; <br/> 3.The ashmem instance for obtaining packaging is empty. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let ashmem2 = rpc.Ashmem.create(ashmem);
    let size = ashmem2.getAshmemSize();
    hilog.info(0x0000, 'testTag', 'size is ' + size);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### createAshmemFromExisting<sup>(deprecated)</sup>

static createAshmemFromExisting(ashmem: Ashmem): Ashmem

静态方法，通过复制现有Ashmem对象的文件描述符(fd)来创建Ashmem对象。两个Ashmem对象指向同一个共享内存区域。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[create](#create9-1)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

| 参数名 | 类型               | 必填 | 说明                 |
| ------ | ------------------ | ---- | -------------------- |
| ashmem | [Ashmem](#ashmem8) | 是   | 已存在的Ashmem对象。 |

**返回值：**

| 类型               | 说明                   |
| ------------------ | ---------------------- |
| [Ashmem](#ashmem8) | 返回创建的Ashmem对象。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let ashmem2 = rpc.Ashmem.createAshmemFromExisting(ashmem);
    let size = ashmem2.getAshmemSize();
    hilog.info(0x0000, 'testTag', 'size is ' + size);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error is ' + error);
  }
  ```

### closeAshmem<sup>8+</sup>

closeAshmem(): void

关闭这个Ashmem。

> **说明：**
>
> 关闭Ashmem对象前需要先解除地址映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    ashmem.closeAshmem();
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error is ' + error);
  }
  ```

### unmapAshmem<sup>8+</sup>

unmapAshmem(): void

删除该Ashmem对象的地址映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    ashmem.unmapAshmem();
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error is ' + error);
  }
  ```

### getAshmemSize<sup>8+</sup>

getAshmemSize(): number

获取Ashmem对象的内存大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                       |
  | ------ | -------------------------- |
  | number | 返回Ashmem对象的内存大小。 |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let size = ashmem.getAshmemSize();
    hilog.info(0x0000, 'testTag', ' size is ' + size);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error is ' + error);
  }
  ```

### mapTypedAshmem<sup>9+</sup>

mapTypedAshmem(mapType: number): void

在此进程的虚拟地址空间上创建共享文件映射，映射区域大小由此Ashmem对象指定。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型   | 必填 | 说明                           |
  | ------- | ------ | ---- | ------------------------------ |
  | mapType | number | 是   | 指定映射的内存区域的保护等级。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect;  <br/> 2.The parameter type does not match; <br/> 3.The passed mapType exceeds the maximum protection level. |
  | 1900001  | Failed to call mmap. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    ashmem.mapTypedAshmem(rpc.Ashmem.PROT_READ | rpc.Ashmem.PROT_WRITE);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### mapAshmem<sup>(deprecated)</sup>

mapAshmem(mapType: number): boolean

在此进程的虚拟地址空间上创建共享文件映射，映射区域大小由此Ashmem对象指定。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[mapTypedAshmem](#maptypedashmem9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型   | 必填 | 说明                           |
  | ------- | ------ | ---- | ------------------------------ |
  | mapType | number | 是   | 指定映射的内存区域的保护等级。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：映射成功，false：映射失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let mapReadAndWrite = ashmem.mapAshmem(rpc.Ashmem.PROT_READ | rpc.Ashmem.PROT_WRITE);
    hilog.info(0x0000, 'testTag', 'map ashmem result is ' + mapReadAndWrite);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error is ' + error);
  }
  ```

### mapReadWriteAshmem<sup>9+</sup>

mapReadWriteAshmem(): void

在此进程虚拟地址空间上创建可读写的共享文件映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900001  | Failed to call mmap. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    ashmem.mapReadWriteAshmem();
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### mapReadAndWriteAshmem<sup>(deprecated)</sup>

mapReadAndWriteAshmem(): boolean

在此进程虚拟地址空间上创建可读写的共享文件映射。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[mapReadWriteAshmem](#mapreadwriteashmem9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：映射成功，false：映射失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let mapResult = ashmem.mapReadAndWriteAshmem();
    hilog.info(0x0000, 'testTag', 'map ashmem result is ' + mapResult);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error is ' + error);
  }
  ```

### mapReadonlyAshmem<sup>9+</sup>

mapReadonlyAshmem(): void

在此进程虚拟地址空间上创建只读的共享文件映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 1900001  | Failed to call mmap. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    ashmem.mapReadonlyAshmem();
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### mapReadOnlyAshmem<sup>(deprecated)</sup>

mapReadOnlyAshmem(): boolean

在此进程虚拟地址空间上创建只读的共享文件映射。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[mapReadonlyAshmem](#mapreadonlyashmem9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：映射成功，false：映射失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let mapResult = ashmem.mapReadOnlyAshmem();
    hilog.info(0x0000, 'testTag', 'Ashmem mapReadOnlyAshmem result is ' + mapResult);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error is ' + error);
  }
  ```

### setProtectionType<sup>9+</sup>

setProtectionType(protectionType: number): void

设置映射内存区域的保护等级。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名         | 类型   | 必填 | 说明               |
  | -------------- | ------ | ---- | ------------------ |
  | protectionType | number | 是   | 要设置的保护类型。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900002  | Failed to call ioctl. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    ashmem.setProtectionType(rpc.Ashmem.PROT_READ);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc set protection type fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc set protection type fail, errorMessage ' + e.message);
  }
  ```

### setProtection<sup>(deprecated)</sup>

setProtection(protectionType: number): boolean

设置映射内存区域的保护等级。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[setProtectionType](#setprotectiontype9)替代。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名         | 类型   | 必填 | 说明               |
  | -------------- | ------ | ---- | ------------------ |
  | protectionType | number | 是   | 要设置的保护类型。 |

**返回值：**

  | 类型    | 说明                             |
  | ------- | -------------------------------- |
  | boolean | true：设置成功，false：设置失败。|

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let result = ashmem.setProtection(rpc.Ashmem.PROT_READ);
    hilog.info(0x0000, 'testTag', 'Ashmem setProtection result is ' + result);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'error ' + error);
  }
  ```

### writeDataToAshmem<sup>11+</sup>

writeDataToAshmem(buf: ArrayBuffer, size: number, offset: number): void

将数据写入此Ashmem对象关联的共享文件。

> **说明：**
>
> 对Ashmem对象进行写操作时，需要先调用[mapReadWriteAshmem](#mapreadwriteashmem9)进行映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                                               |
  | ------ | -------- | ---- | -------------------------------------------------- |
  | buf    | ArrayBuffer | 是   | 写入Ashmem对象的数据。                             |
  | size   | number   | 是   | 要写入的数据大小。                                 |
  | offset | number   | 是   | 要写入的数据在此Ashmem对象关联的内存区间的起始位置。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.Failed to obtain arrayBuffer information. |
  | 1900003  | Failed to write data to the shared memory. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let buffer = new ArrayBuffer(1024);
    let int32View = new Int32Array(buffer);
    for (let i = 0; i < int32View.length; i++) {
      int32View[i] = i * 2 + 1;
    }
    let size = buffer.byteLength;
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    ashmem.mapReadWriteAshmem();
    ashmem.writeDataToAshmem(buffer, size, 0);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### writeAshmem<sup>(deprecated)</sup>

writeAshmem(buf: number[], size: number, offset: number): void

将数据写入此Ashmem对象关联的共享文件。

> **说明：**
>
> 从API version 9 开始支持，从API version 11 开始废弃，建议使用[writeDataToAshmem](#writedatatoashmem11)替代。
> 
> 对Ashmem对象进行写操作时，需要先调用[mapReadWriteAshmem](#mapreadwriteashmem9)进行映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                                               |
  | ------ | -------- | ---- | -------------------------------------------------- |
  | buf    | number[] | 是   | 写入Ashmem对象的数据。                             |
  | size   | number   | 是   | 要写入的数据大小。                                 |
  | offset | number   | 是   | 要写入的数据在此Ashmem对象关联的内存区间的起始位置。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match; <br/> 3.The element does not exist in the array. |
  | 1900003  | Failed to write data to the shared memory. |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    ashmem.mapReadWriteAshmem();
    let ByteArrayVar = [1, 2, 3, 4, 5];
    ashmem.writeAshmem(ByteArrayVar, 5, 0);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'Rpc write to ashmem fail, errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'Rpc write to ashmem fail, errorMessage ' + e.message);
  }
  ```

### writeToAshmem<sup>(deprecated)</sup>

writeToAshmem(buf: number[], size: number, offset: number): boolean

将数据写入此Ashmem对象关联的共享文件。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[writeDataToAshmem](#writedatatoashmem11)替代。
> 
> 对Ashmem对象进行写操作时，需要先调用[mapReadWriteAshmem](#mapreadwriteashmem9)进行映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                                               |
  | ------ | -------- | ---- | -------------------------------------------------- |
  | buf    | number[] | 是   | 写入Ashmem对象的数据。                             |
  | size   | number   | 是   | 要写入的数据大小。                                 |
  | offset | number   | 是   | 要写入的数据在此Ashmem对象关联的内存区间的起始位置。 |

**返回值：**

  | 类型    | 说明                                                                          |
  | ------- | ----------------------------------------------------------------------------- |
  | boolean | true：如果数据写入成功，false：在其他情况下，如数据写入越界或未获得写入权限。 |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let mapResult = ashmem.mapReadAndWriteAshmem();
    hilog.info(0x0000, 'testTag', 'RpcTest map ashmem result is ' + mapResult);
    let ByteArrayVar = [1, 2, 3, 4, 5];
    let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);
    hilog.info(0x0000, 'testTag', 'write to Ashmem result is ' + writeResult);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error is ' + error);
  }
  ```

### readDataFromAshmem<sup>11+</sup>

readDataFromAshmem(size: number, offset: number): ArrayBuffer

从此Ashmem对象关联的共享文件中读取数据。

> **说明：**
>
> 对Ashmem对象进行写操作时，需要先调用[mapReadWriteAshmem](#mapreadwriteashmem9)进行映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                               |
  | ------ | ------ | ---- | -------------------------------------------------- |
  | size   | number | 是   | 要读取的数据的大小。                               |
  | offset | number | 是   | 要读取的数据在此Ashmem对象关联的内存区间的起始位置。 |

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | ArrayBuffer | 返回读取的数据。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900004  | Failed to read data from the shared memory. |

**示例：**

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let buffer = new ArrayBuffer(1024);
    let int32View = new Int32Array(buffer);
    for (let i = 0; i < int32View.length; i++) {
      int32View[i] = i * 2 + 1;
    }
    let size = buffer.byteLength;
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    ashmem.mapReadWriteAshmem();
    ashmem.writeDataToAshmem(buffer, size, 0);
    let readResult = ashmem.readDataFromAshmem(size, 0);
    let readInt32View = new Int32Array(readResult);
    hilog.info(0x0000, 'testTag', 'read from Ashmem result is ' + readInt32View);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readAshmem<sup>(deprecated)</sup>

readAshmem(size: number, offset: number): number[]

从此Ashmem对象关联的共享文件中读取数据。

> **说明：**
>
> 从API version 9 开始支持，从API version 11 开始废弃，建议使用[readDataFromAshmem](#readdatafromashmem11)替代。
> 
> 对Ashmem对象进行写操作时，需要先调用[mapReadWriteAshmem](#mapreadwriteashmem9)进行映射。


**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                               |
  | ------ | ------ | ---- | -------------------------------------------------- |
  | size   | number | 是   | 要读取的数据的大小。                               |
  | offset | number | 是   | 要读取的数据在此Ashmem对象关联的内存区间的起始位置。 |

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | number[] | 返回读取的数据。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | -------- |
  | 401      | Parameter error. Possible causes: <br/> 1.The number of parameters is incorrect; <br/> 2.The parameter type does not match. |
  | 1900004  | Failed to read data from the shared memory. |

**示例：**
<!--deprecated_code_no_check-->
  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    ashmem.mapReadWriteAshmem();
    let ByteArrayVar = [1, 2, 3, 4, 5];
    ashmem.writeAshmem(ByteArrayVar, 5, 0);
    let readResult = ashmem.readAshmem(5, 0);
    hilog.info(0x0000, 'testTag', 'read from Ashmem result is ' + readResult);
  } catch (error) {
    let e: BusinessError = error as BusinessError;
    hilog.error(0x0000, 'testTag', 'errorCode ' + e.code);
    hilog.error(0x0000, 'testTag', 'errorMessage ' + e.message);
  }
  ```

### readFromAshmem<sup>(deprecated)</sup>

readFromAshmem(size: number, offset: number): number[]

从此Ashmem对象关联的共享文件中读取数据。

> **说明：**
>
> 从API version 8 开始支持，从API version 9 开始废弃，建议使用[readDataFromAshmem](#readdatafromashmem11)替代。
> 
> 对Ashmem对象进行写操作时，需要先调用[mapReadWriteAshmem](#mapreadwriteashmem9)进行映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                               |
  | ------ | ------ | ---- | -------------------------------------------------- |
  | size   | number | 是   | 要读取的数据的大小。                               |
  | offset | number | 是   | 要读取的数据在此Ashmem对象关联的内存区间的起始位置。 |

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | number[] | 返回读取的数据。 |

**示例：**
<!--deprecated_code_no_check-->
 ``` ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  try {
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
    let mapResult = ashmem.mapReadAndWriteAshmem();
    hilog.info(0x0000, 'testTag', 'RpcTest map ashmem result is ' + mapResult);
    let ByteArrayVar = [1, 2, 3, 4, 5];
    let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);
    hilog.info(0x0000, 'testTag', 'write to Ashmem result is ' + writeResult);
    let readResult = ashmem.readFromAshmem(5, 0);
    hilog.info(0x0000, 'testTag', 'read to Ashmem result is ' + readResult);
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'error is ' + error);
  }
 ```
