# @ohos.rpc (RPC通信)

本模块提供进程间通信能力，包括设备内的进程间通信（IPC）和设备间的进程间通信（RPC），前者基于Binder驱动，后者基于软总线驱动。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块从API version 9开始支持异常返回功能。

## 导入模块

```
import rpc from '@ohos.rpc';
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


## MessageSequence<sup>9+</sup>

  在RPC或IPC过程中，发送方可以使用MessageSequence提供的写方法，将待发送的数据以特定格式写入该对象。接收方可以使用MessageSequence提供的读方法从该对象中读取特定格式的数据。数据格式包括：基础类型及数组、IPC对象、接口描述符和自定义序列化对象。

### create

  static create(): MessageSequence

**描述**：

  静态方法，创建MessageSequence对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型            | 说明                            |
  | --------------- | ------------------------------- |
  | MessageSequence | 返回创建的MessageSequence对象。 |

**示例：**

  ```
  let data = rpc.MessageSequence.create();
  console.log("RpcClient: data is " + data);
  ```

### reclaim

reclaim(): void

**描述**：

释放不再使用的MessageSequence对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  let reply = rpc.MessageSequence.create();
  reply.reclaim();
  ```

### writeRemoteObject

writeRemoteObject(object: [IRemoteObject](#iremoteobject)): void

**描述**：

序列化远程对象并将其写入MessageSequence对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                            | 必填 | 说明                                      |
  | ------ | ------------------------------- | ---- | ----------------------------------------- |
  | object | [IRemoteObject](#iremoteobject) | 是   | 要序列化并写入MessageSequence的远程对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------- |
  | 1900008 | proxy or remote object is invalid |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence读取远程对象。此方法用于反序列化MessageSequence对象以生成IRemoteObject。远程对象按写入MessageSequence的顺序读取。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型                            | 说明               |
  | ------------------------------- | ------------------ |
  | [IRemoteObject](#iremoteobject) | 读取到的远程对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将接口描述符写入MessageSequence对象，远端对象可使用该信息校验本次通信。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明               |
  | ------ | ------ | ---- | ------------------ |
  | token  | string | 是   | 字符串类型描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence对象中读取接口描述符，接口描述符按写入MessageSequence的顺序读取，本地对象可使用该信息检验本次通信。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                     |
  | ------ | ------------------------ |
  | string | 返回读取到的接口描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ----- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

获取当前创建的MessageSequence对象的数据大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                            |
  | ------ | ----------------------------------------------- |
  | number | 获取的MessageSequence实例的数据大小。以字节为单位。 |

**示例：**

  ```
  let data = rpc.MessageSequence.create();
  let size = data.getSize();
  console.log("RpcClient: size is " + size);
  ```

### getCapacity

getCapacity(): number

**描述**：

获取当前MessageSequence对象的容量大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明 |
  | ------ | ----- |
  | number | 获取的MessageSequence实例的容量大小。以字节为单位。 |

**示例：**

  ```
  let data = rpc.MessageSequence.create();
  let result = data.getCapacity();
  console.log("RpcClient: capacity is " + result);
  ```

### setSize

setSize(size: number): void

**描述**：

设置MessageSequence对象中包含的数据大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明 |
  | ------ | ------ | ---- | ------ |
  | size   | number | 是   | MessageSequence实例的数据大小。以字节为单位。 |

**示例：**

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

**描述**：

设置MessageSequence对象的存储容量。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                          |
  | ------ | ------ | ---- | --------------------------------------------- |
  | size   | number | 是   | MessageSequence实例的存储容量。以字节为单位。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------ |
  | 1900011 | parcel memory alloc failed |

**示例：**

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

**描述**：

获取MessageSequence的可写字节空间大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型 | 说明 |
  | ------ | ------ |
  | number | 获取到的MessageSequence实例的可写字节空间。以字节为单位。 |

**示例：**

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

**描述**：

获取MessageSequence的可读字节空间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型 | 说明 |
  | ------ | ------- |
  | number | 获取到的MessageSequence实例的可读字节空间。以字节为单位。 |

**示例：**

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

**描述**：

获取MessageSequence的读位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型 | 说明 |
  | ------ | ------ |
  | number | 返回MessageSequence实例中的当前读取位置。 |

**示例：**

  ```
  let data = rpc.MessageSequence.create();
  let readPos = data.getReadPosition();
  console.log("RpcClient: readPos is " + readPos);
  ```

### getWritePosition

getWritePosition(): number

**描述**：

获取MessageSequence的写位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型 | 说明 |
  | ------ | ----- |
  | number | 返回MessageSequence实例中的当前写入位置。 |

**示例：**

  ```
  let data = rpc.MessageSequence.create();
  data.writeInt(10);
  let bwPos = data.getWritePosition();
  console.log("RpcClient: bwPos is " + bwPos);
  ```

### rewindRead

rewindRead(pos: number): void

**描述**：

重新偏移读取位置到指定的位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ---- | ------- |
  | pos    | number | 是   | 开始读取数据的目标位置。 |

**示例：**

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

**描述**：

重新偏移写位置到指定的位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ---- | ----- |
  | pos    | number | 是   | 开始写入数据的目标位置。 |

**示例：**

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

**描述**：

将字节值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明 |
  | ----- | ------ | ---- | ----- |
  | val | number | 是 | 要写入的字节值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取字节值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明 |
  | ------ | ----- |
  | number | 返回字节值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | --------  |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将短整数值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明 |
  | ------ | ------ | --- | --- |
  | val | number | 是 | 要写入的短整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------ |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取短整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | number | 返回短整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将整数值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明         |
  | ------ | ------------ |
  | number | 返回整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将长整数值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的长整数值 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取长整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | number | 返回长整数值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将浮点值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ----- | ---- | ---- | ----- |
  | val | number | 是 | 要写入的浮点值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取浮点值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明         |
  | ------ | ------------ |
  | number | 返回浮点值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将双精度浮点值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | ------ | ---- | ------ |
  | val  number | 是 | 要写入的双精度浮点值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取双精度浮点值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明               |
  | ------ | ------------------ |
  | number | 返回双精度浮点值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将布尔值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型    | 必填 | 说明             |
  | ------ | ------- | ---- | ---------------- |
  | val    | boolean | 是   | 要写入的布尔值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取布尔值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                 |
  | ------- | -------------------- |
  | boolean | 返回读取到的布尔值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将单个字符值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                 |
  | ------ | ------ | ---- | -------------------- |
  | val    | number | 是   | 要写入的单个字符值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取单个字符值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明 |
  | ------ | ---- |
  | number | 返回单个字符值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------ | --------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将字符串值写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                      |
  | ------ | ------ | ---- | ----------------------------------------- |
  | val    | string | 是   | 要写入的字符串值，其长度应小于40960字节。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取字符串值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | string | 返回字符串值。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将自定义序列化对象写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | --------- | ---- | ------ |
  | val    | Parcelable | 是   | 要写入的可序列对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取成员变量到指定的对象（dataIn）。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                      | 必填 | 说明                                      |
  | ------ | ------------------------- | ---- | ----------------------------------------- |
  | dataIn | Parcelable | 是   | 需要从MessageSequence读取成员变量的对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------- |
  | 1900010 | read data from message sequence failed |
  | 1900012 | call js callback function failed |

**示例：**

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

**描述**：

将字节数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明               |
  | --------- | -------- | ---- | ------------------ |
  | byteArray | number[] | 是   | 要写入的字节数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取字节数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明               |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | 是   | 要读取的字节数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取字节数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回字节数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将短整数数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型     | 必填 | 说明                 |
  | ---------- | -------- | ---- | -------------------- |
  | shortArray | number[] | 是   | 要写入的短整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ----- | ----- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取短整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | 是   | 要读取的短整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------ | ------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取短整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | number[] | 返回短整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将整数数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型     | 必填 | 说明               |
  | -------- | -------- | ---- | ------------------ |
  | intArray | number[] | 是   | 要写入的整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ----- | --------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明               |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | 是   | 要读取的整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ----- | ------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将长整数数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明                 |
  | --------- | -------- | ---- | -------------------- |
  | longArray | number[] | 是   | 要写入的长整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------  | ----- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取定长长整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | 是   | 要读取的长整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------ |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取所有的长整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | number[] | 返回长整数数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将浮点数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型     | 必填 | 说明                                                                                                                    |
  | ---------- | -------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
  | floatArray | number[] | 是   | 要写入的浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                                                                                                                    |
  | ------ | -------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
  | dataIn | number[] | 是   | 要读取的浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回浮点数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将双精度浮点数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型     | 必填 | 说明                     |
  | ----------- | -------- | ---- | ------------------------ |
  | doubleArray | number[] | 是   | 要写入的双精度浮点数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取定长双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                     |
  | ------ | -------- | ---- | ------------------------ |
  | dataIn | number[] | 是   | 要读取的双精度浮点数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取所有双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明                 |
  | -------- | -------------------- |
  | number[] | 返回双精度浮点数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将布尔数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名       | 类型      | 必填 | 说明               |
  | ------------ | --------- | ---- | ------------------ |
  | booleanArray | boolean[] | 是   | 要写入的布尔数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取定长布尔数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型      | 必填 | 说明               |
  | ------ | --------- | ---- | ------------------ |
  | dataIn | boolean[] | 是   | 要读取的布尔数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取所有布尔数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型      | 说明           |
  | --------- | -------------- |
  | boolean[] | 返回布尔数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将单个字符数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明                   |
  | --------- | -------- | ---- | ---------------------- |
  | charArray | number[] | 是   | 要写入的单个字符数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------ |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例中读取单个字符数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                   |
  | ------ | -------- | ---- | ---------------------- |
  | dataIn | number[] | 是   | 要读取的单个字符数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取单个字符数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明               |
  | -------- | ------------------ |
  | number[] | 返回单个字符数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将字符串数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型     | 必填 | 说明                                                    |
  | ----------- | -------- | ---- | ------------------------------------------------------- |
  | stringArray | string[] | 是   | 要写入的字符串数组，数组单个元素的长度应小于40960字节。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取字符串数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | string[] | 是   | 要读取的字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取字符串数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | string[] | 返回字符串数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

向MessageSequence写入“指示未发生异常”的信息。

**系统能力**：SystemCapability.Communication.IPC.Core

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence中读取异常。

**系统能力**：SystemCapability.Communication.IPC.Core

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将可序列化对象数组写入MessageSequence实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名          | 类型         | 必填 | 说明                       |
  | --------------- | ------------ | ---- | -------------------------- |
  | parcelableArray | Parcelable[] | 是   | 要写入的可序列化对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence实例读取可序列化对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名          | 类型         | 必填 | 说明                       |
  | --------------- | ------------ | ---- | -------------------------- |
  | parcelableArray | Parcelable[] | 是   | 要读取的可序列化对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |
  | 1900012 | call js callback function failed |

**示例：**

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

**描述**：

将IRemoteObject对象数组写入MessageSequence。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型            | 必填 | 说明                                           |
  | ----------- | --------------- | ---- | ---------------------------------------------- |
  | objectArray | IRemoteObject[] | 是   | 要写入MessageSequence的IRemoteObject对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------- |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence读取IRemoteObject对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型            | 必填 | 说明                                           |
  | ------- | --------------- | ---- | ---------------------------------------------- |
  | objects | IRemoteObject[] | 是   | 从MessageSequence读取的IRemoteObject对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

从MessageSequence读取IRemoteObject对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型            | 说明                        |
  | --------------- | --------------------------- |
  | IRemoteObject[] | 返回IRemoteObject对象数组。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

静态方法，关闭给定的文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                 |
  | ------ | ------ | ---- | -------------------- |
  | fd     | number | 是   | 要关闭的文件描述符。 |

**示例：**

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

**描述**：

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

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------- |
  | 1900013 | call os dup function failed |

**示例：**

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

**描述**：

检查此MessageSequence对象是否包含文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                                                 |
  | ------- | -------------------------------------------------------------------- |
  | boolean | true：包含文件描述符，false：不包含文件描述符。|

**示例：**


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

**描述**：

写入文件描述符到MessageSequence。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明         |
  | ------ | ------ | ---- | ------------ |
  | fd     | number | 是   | 文件描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------ |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence中读取文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | number | 返回文件描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

**描述**：

将指定的匿名共享对象写入此MessageSequence。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                  |
  | ------ | ------ | ---- | ------------------------------------- |
  | ashmem | Ashmem | 是   | 要写入MessageSequence的匿名共享对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------- |
  | 1900003 | write to ashmem failed |

**示例：**

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

**描述**：

从MessageSequence读取匿名共享对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明               |
  | ------ | ------------------ |
  | Ashmem | 返回匿名共享对象。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900004 | read from ashmem failed |

**示例：**

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

**描述**：

获取MessageSequence可以容纳的最大原始数据量。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                                         |
  | ------ | ------------------------------------------------------------ |
  | number | 返回MessageSequence可以容纳的最大原始数据量，即128&nbsp;Mb。 |

**示例：**

  ```
  let sequence = new rpc.MessageSequence();
  let result = sequence.getRawDataCapacity();
  console.log("RpcTest: sequence get RawDataCapacity result is : " + result);
  ```

### writeRawData

writeRawData(rawData: number[], size: number): void

**描述**：

将原始数据写入MessageSequence对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型     | 必填 | 说明                               |
  | ------- | -------- | ---- | ---------------------------------- |
  | rawData | number[] | 是   | 要写入的原始数据。                 |
  | size    | number   | 是   | 发送的原始数据大小，以字节为单位。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------ |
  | 1900009 | write data to message sequence failed |

**示例：**

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

**描述**：

从MessageSequence读取原始数据。

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

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900010 | read data from message sequence failed |

**示例：**

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

>从API version 9 开始不再维护，建议使用[MessageSequence](#messagesequence9)类替代。

在RPC过程中，发送方可以使用MessageParcel提供的写方法，将待发送的数据以特定格式写入该对象。接收方可以使用MessageParcel提供的读方法从该对象中读取特定格式的数据。数据格式包括：基础类型及数组、IPC对象、接口描述符和自定义序列化对象。

### create

static create(): MessageParcel

**描述**：

静态方法，创建MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型          | 说明                          |
  | ------------- | ----------------------------- |
  | MessageParcel | 返回创建的MessageParcel对象。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  console.log("RpcClient: data is " + data);
  ```

### reclaim

reclaim(): void

**描述**：

释放不再使用的MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  let reply = rpc.MessageParcel.create();
  reply.reclaim();
  ```

### writeRemoteObject

writeRemoteObject(object: [IRemoteObject](#iremoteobject)): boolean

**描述**：

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

**描述**：

从MessageParcel读取远程对象。此方法用于反序列化MessageParcel对象以生成IRemoteObject。远程对象按写入MessageParcel的顺序读取。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型                            | 说明               |
  | ------------------------------- | ------------------ |
  | [IRemoteObject](#iremoteobject) | 读取到的远程对象。 |

**示例：**

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

**描述**：

将接口描述符写入MessageParcel对象，远端对象可使用该信息校验本次通信。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明               |
  | ------ | ------ | ---- | ------------------ |
  | token  | string | 是   | 字符串类型描述符。 |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：操作成功，false：操作失败。|

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInterfaceToken("aaa");
  console.log("RpcServer: writeInterfaceToken is " + result);
  ```


### readInterfaceToken

readInterfaceToken(): string

**描述**：

从MessageParcel中读取接口描述符，接口描述符按写入MessageParcel的顺序读取，本地对象可使用该信息检验本次通信。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                     |
  | ------ | ------------------------ |
  | string | 返回读取到的接口描述符。 |

**示例：**

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

**描述**：

获取当前MessageParcel的数据大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                          |
  | ------ | --------------------------------------------- |
  | number | 获取的MessageParcel的数据大小。以字节为单位。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let size = data.getSize();
  console.log("RpcClient: size is " + size);
  ```

### getCapacity

getCapacity(): number

**描述**：

获取当前MessageParcel的容量。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                          |
  | ------ | --------------------------------------------- |
  | number | 获取的MessageParcel的容量大小。以字节为单位。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.getCapacity();
  console.log("RpcClient: capacity is " + result);
  ```

### setSize

setSize(size: number): boolean

**描述**：

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

  ```
  let data = rpc.MessageParcel.create();
  let setSize = data.setSize(16);
  console.log("RpcClient: setSize is " + setSize);
  ```

### setCapacity

setCapacity(size: number): boolean

**描述**：

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

  ```
  let data = rpc.MessageParcel.create();
  let result = data.setCapacity(100);
  console.log("RpcClient: setCapacity is " + result);
  ```

### getWritableBytes

getWritableBytes(): number

**描述**：

获取MessageParcel的可写字节空间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                                |
  | ------ | --------------------------------------------------- |
  | number | 获取到的MessageParcel的可写字节空间。以字节为单位。 |

**示例：**

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

**描述**：

获取MessageParcel的可读字节空间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                                |
  | ------ | --------------------------------------------------- |
  | number | 获取到的MessageParcel的可读字节空间。以字节为单位。 |

**示例：**

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

**描述**：

获取MessageParcel的读位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                    |
  | ------ | --------------------------------------- |
  | number | 返回MessageParcel实例中的当前读取位置。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let readPos = data.getReadPosition();
  console.log("RpcClient: readPos is " + readPos);
  ```

### getWritePosition

getWritePosition(): number

**描述**：

获取MessageParcel的写位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                    |
  | ------ | --------------------------------------- |
  | number | 返回MessageParcel实例中的当前写入位置。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  data.writeInt(10);
  let bwPos = data.getWritePosition();
  console.log("RpcClient: bwPos is " + bwPos);
  ```

### rewindRead

rewindRead(pos: number): boolean

**描述**：

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

**描述**：

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

**描述**：

将字节值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的字节值。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |
  | boolean | 写入返回成功，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeByte(2);
  console.log("RpcClient: writeByte is: " + result);
  ```

### readByte

readByte(): number

**描述**：

从MessageParcel实例读取字节值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明         |
  | ------ | ------------ |
  | number | 返回字节值。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeByte(2);
  console.log("RpcClient: writeByte is: " + result);
  let ret = data.readByte();
  console.log("RpcClient: readByte is: " + ret);
  ```

### writeShort

writeShort(val: number): boolean

**描述**：

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

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShort(8);
  console.log("RpcClient: writeShort is: " + result);
  ```

### readShort

readShort(): number

**描述**：

从MessageParcel实例读取短整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | number | 返回短整数值。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShort(8);
  console.log("RpcClient: writeShort is: " + result);
  let ret = data.readShort();
  console.log("RpcClient: readShort is: " + ret);
  ```

### writeInt

writeInt(val: number): boolean

**描述**：

将整数值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的整数值。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |
  | boolean | 写入返回成功，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInt(10);
  console.log("RpcClient: writeInt is " + result);
  ```

### readInt

readInt(): number

**描述**：

从MessageParcel实例读取整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明         |
  | ------ | ------------ |
  | number | 返回整数值。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInt(10);
  console.log("RpcClient: writeInt is " + result);
  let ret = data.readInt();
  console.log("RpcClient: readInt is " + ret);
  ```

### writeLong

writeLong(val: number): boolean

**描述**：

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

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLong(10000);
  console.log("RpcClient: writeLong is " + result);
  ```

### readLong

readLong(): number

**描述**：

从MessageParcel实例中读取长整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | number | 返回长整数值。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLong(10000);
  console.log("RpcClient: writeLong is " + result);
  let ret = data.readLong();
  console.log("RpcClient: readLong is " + ret);
  ```

### writeFloat

writeFloat(val: number): boolean

**描述**：

将浮点值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明             |
  | ------ | ------ | ---- | ---------------- |
  | val    | number | 是   | 要写入的浮点值。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloat(1.2);
  console.log("RpcClient: writeFloat is " + result);
  ```

### readFloat

readFloat(): number

**描述**：

从MessageParcel实例中读取浮点值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明         |
  | ------ | ------------ |
  | number | 返回浮点值。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloat(1.2);
  console.log("RpcClient: writeFloat is " + result);
  let ret = data.readFloat();
  console.log("RpcClient: readFloat is " + ret);
  ```

### writeDouble

writeDouble(val: number): boolean

**描述**：

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

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDouble(10.2);
  console.log("RpcClient: writeDouble is " + result);
  ```

### readDouble

readDouble(): number

**描述**：

从MessageParcel实例读取双精度浮点值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明               |
  | ------ | ------------------ |
  | number | 返回双精度浮点值。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDouble(10.2);
  console.log("RpcClient: writeDouble is " + result);
  let ret = data.readDouble();
  console.log("RpcClient: readDouble is " + ret);
  ```

### writeBoolean

writeBoolean(val: boolean): boolean

**描述**：

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

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBoolean(false);
  console.log("RpcClient: writeBoolean is " + result);
  ```

### readBoolean

readBoolean(): boolean

**描述**：

从MessageParcel实例读取布尔值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                 |
  | ------- | -------------------- |
  | boolean | 返回读取到的布尔值。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBoolean(false);
  console.log("RpcClient: writeBoolean is " + result);
  let ret = data.readBoolean();
  console.log("RpcClient: readBoolean is " + ret);
  ```

### writeChar

writeChar(val: number): boolean

**描述**：

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

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeChar(97);
  console.log("RpcClient: writeChar is " + result);
  ```

### readChar

readChar(): number

**描述**：

从MessageParcel实例中读取单个字符值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | number | 返回单个字符值。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeChar(97);
  console.log("RpcClient: writeChar is " + result);
  let ret = data.readChar();
  console.log("RpcClient: readChar is " + ret);
  ```

### writeString

writeString(val: string): boolean

**描述**：

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

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeString('abc');
  console.log("RpcClient: writeString  is " + result);
  ```

### readString

readString(): string

**描述**：

从MessageParcel实例读取字符串值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明           |
  | ------ | -------------- |
  | string | 返回字符串值。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeString('abc');
  console.log("RpcClient: writeString  is " + result);
  let ret = data.readString();
  console.log("RpcClient: readString is " + ret);
  ```

### writeSequenceable

writeSequenceable(val: Sequenceable): boolean

**描述**：

将自定义序列化对象写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                          | 必填 | 说明                 |
  | ------ | ----------------------------- | ---- | -------------------- |
  | val    | [Sequenceable](#sequenceable) | 是   | 要写入的可序列对象。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

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

**描述**：

从MessageParcel实例中读取成员变量到指定的对象（dataIn）。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                          | 必填 | 说明                                    |
  | ------ | ----------------------------- | ---- | --------------------------------------- |
  | dataIn | [Sequenceable](#sequenceabledeprecated) | 是   | 需要从MessageParcel读取成员变量的对象。 |

**返回值：**

  | 类型    | 说明                                        |
  | ------- | ------------------------------------------- |
  | boolean | true：反序列化成功，false：反序列化失败。|

**示例：**

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

**描述**：

将字节数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明               |
  | --------- | -------- | ---- | ------------------ |
  | byteArray | number[] | 是   | 要写入的字节数组。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let result = data.writeByteArray(ByteArrayVar);
  console.log("RpcClient: writeByteArray is " + result);
  ```

### readByteArray

readByteArray(dataIn: number[]): void

**描述**：

从MessageParcel实例读取字节数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明               |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | 是   | 要读取的字节数组。 |

**示例：**

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

**描述**：

从MessageParcel实例中读取字节数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回字节数组。 |

**示例：**

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

**描述**：

将短整数数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型     | 必填 | 说明                 |
  | ---------- | -------- | ---- | -------------------- |
  | shortArray | number[] | 是   | 要写入的短整数数组。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  ```

### readShortArray

readShortArray(dataIn: number[]): void

**描述**：

从MessageParcel实例中读取短整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | 是   | 要读取的短整数数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  let array = new Array(3);
  data.readShortArray(array);
  ```

### readShortArray

readShortArray(): number[]

**描述**：

从MessageParcel实例中读取短整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | number[] | 返回短整数数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  let array = data.readShortArray();
 console.log("RpcClient: readShortArray is " + array);
  ```

### writeIntArray

writeIntArray(intArray: number[]): boolean

**描述**：

将整数数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型     | 必填 | 说明               |
  | -------- | -------- | ---- | ------------------ |
  | intArray | number[] | 是   | 要写入的整数数组。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  ```

### readIntArray

readIntArray(dataIn: number[]): void

**描述**：

从MessageParcel实例中读取整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明               |
  | ------ | -------- | ---- | ------------------ |
  | dataIn | number[] | 是   | 要读取的整数数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  let array = new Array(3);
  data.readIntArray(array);
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

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  let array = data.readIntArray();
  console.log("RpcClient: readIntArray is " + array);
  ```

### writeLongArray

writeLongArray(longArray: number[]): boolean

**描述**：

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

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  ```

### readLongArray

readLongArray(dataIn: number[]): void

**描述**：

从MessageParcel实例读取长整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | number[] | 是   | 要读取的长整数数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  let array = new Array(3);
  data.readLongArray(array);
  ```

### readLongArray

readLongArray(): number[]

**描述**：

从MessageParcel实例中读取长整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

 | 类型     | 说明             |
 | -------- | ---------------- |
 | number[] | 返回长整数数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  let array = data.readLongArray();
  console.log("RpcClient: readLongArray is " + array);
  ```

### writeFloatArray

writeFloatArray(floatArray: number[]): boolean

**描述**：

将浮点数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ---------- | -------- | ---- | --- |
  | floatArray | number[] | 是   | 要写入的浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  ```

### readFloatArray

readFloatArray(dataIn: number[]): void

**描述**：

从MessageParcel实例中读取浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | ------ | -------- | ---- | ------ |
  | dataIn | number[] | 是   | 要读取的浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  let array = new Array(3);
  data.readFloatArray(array);
  ```

### readFloatArray

readFloatArray(): number[]

**描述**：

从MessageParcel实例中读取浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明           |
  | -------- | -------------- |
  | number[] | 返回浮点数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  let array = data.readFloatArray();
  console.log("RpcClient: readFloatArray is " + array);
  ```

### writeDoubleArray

writeDoubleArray(doubleArray: number[]): boolean

**描述**：

将双精度浮点数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型     | 必填 | 说明                     |
  | ----------- | -------- | ---- | ------------------------ |
  | doubleArray | number[] | 是   | 要写入的双精度浮点数组。 |

**返回值：**

  | 类型    | 说明                          |
  | ------- | ----------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  ```

### readDoubleArray

readDoubleArray(dataIn: number[]): void

**描述**：

从MessageParcel实例中读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                     |
  | ------ | -------- | ---- | ------------------------ |
  | dataIn | number[] | 是   | 要读取的双精度浮点数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  let array = new Array(3);
  data.readDoubleArray(array);
  ```

### readDoubleArray

readDoubleArray(): number[]

**描述**：

从MessageParcel实例读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明                 |
  | -------- | -------------------- |
  | number[] | 返回双精度浮点数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  let array = data.readDoubleArray();
  console.log("RpcClient: readDoubleArray is " + array);
  ```

### writeBooleanArray

writeBooleanArray(booleanArray: boolean[]): boolean

**描述**：

将布尔数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名       | 类型      | 必填 | 说明               |
  | ------------ | --------- | ---- | ------------------ |
  | booleanArray | boolean[] | 是   | 要写入的布尔数组。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  ```

### readBooleanArray

readBooleanArray(dataIn: boolean[]): void

**描述**：

从MessageParcel实例中读取布尔数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型      | 必填 | 说明               |
  | ------ | --------- | ---- | ------------------ |
  | dataIn | boolean[] | 是   | 要读取的布尔数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  let array = new Array(3);
  data.readBooleanArray(array);
  ```

### readBooleanArray

readBooleanArray(): boolean[]

**描述**：

从MessageParcel实例中读取布尔数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型      | 说明           |
  | --------- | -------------- |
  | boolean[] | 返回布尔数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  let array = data.readBooleanArray();
  console.log("RpcClient: readBooleanArray is " + array);
  ```

### writeCharArray

writeCharArray(charArray: number[]): boolean

**描述**：

将单个字符数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型     | 必填 | 说明                   |
  | --------- | -------- | ---- | ---------------------- |
  | charArray | number[] | 是   | 要写入的单个字符数组。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 88]);
  console.log("RpcClient: writeCharArray is " + result);
  ```

### readCharArray

readCharArray(dataIn: number[]): void

**描述**：

从MessageParcel实例中读取单个字符数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                   |
  | ------ | -------- | ---- | ---------------------- |
  | dataIn | number[] | 是   | 要读取的单个字符数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 99]);
  console.log("RpcClient: writeCharArray is " + result);
  let array = new Array(3);
  data.readCharArray(array);
  ```

### readCharArray

readCharArray(): number[]

**描述**：

从MessageParcel实例读取单个字符数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明               |
  | -------- | ------------------ |
  | number[] | 返回单个字符数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 99]);
  console.log("RpcClient: writeCharArray is " + result);
  let array = data.readCharArray();
  console.log("RpcClient: readCharArray is " + array);
  ```

### writeStringArray

writeStringArray(stringArray: string[]): boolean

**描述**：

将字符串数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型     | 必填 | 说明 |
  | ----------- | -------- | ---- | ---------------- |
  | stringArray | string[] | 是   | 要写入的字符串数组，数组单个元素的长度应小于40960字节。 |

**返回值：**

  | 类型    | 说明 |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  console.log("RpcClient: writeStringArray is " + result);
  ```

### readStringArray

readStringArray(dataIn: string[]): void

**描述**：

从MessageParcel实例读取字符串数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                 |
  | ------ | -------- | ---- | -------------------- |
  | dataIn | string[] | 是   | 要读取的字符串数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  console.log("RpcClient: writeStringArray is " + result);
  let array = new Array(2);
  data.readStringArray(array);
  ```

### readStringArray

readStringArray(): string[]

**描述**：

从MessageParcel实例读取字符串数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | string[] | 返回字符串数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  console.log("RpcClient: writeStringArray is " + result);
  let array = data.readStringArray();
  console.log("RpcClient: readStringArray is " + array);
  ```

### writeNoException<sup>8+</sup>

writeNoException(): void

**描述**：

向MessageParcel写入“指示未发生异常”的信息。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

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

**描述**：

从MessageParcel中读取异常。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

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

**描述**：

将可序列化对象数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名            | 类型           | 必填 | 说明                       |
  | ----------------- | -------------- | ---- | -------------------------- |
  | sequenceableArray | Sequenceable[] | 是   | 要写入的可序列化对象数组。 |

**返回值：**

  | 类型    | 说明                              |
  | ------- | --------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

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

**描述**：

从MessageParcel实例读取可序列化对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名            | 类型           | 必填 | 说明                       |
  | ----------------- | -------------- | ---- | -------------------------- |
  | sequenceableArray | Sequenceable[] | 是   | 要读取的可序列化对象数组。 |

**示例：**

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

**描述**：

将IRemoteObject对象数组写入MessageParcel。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名      | 类型            | 必填 | 说明 |
  | ----------- | --------------- | ---- | ----- |
  | objectArray | IRemoteObject[] | 是   | 要写入MessageParcel的IRemoteObject对象数组。 |

**返回值：**

  | 类型    | 说明                                                                                                                 |
  | ------- | -------------------------------------------------------------------------------------------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

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

**描述**：

从MessageParcel读取IRemoteObject对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型            | 必填 | 说明 |
  | ------- | --------------- | ---- | --------- |
  | objects | IRemoteObject[] | 是   | 从MessageParcel读取的IRemoteObject对象数组。 |

**示例：**

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

**描述**：

从MessageParcel读取IRemoteObject对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型 | 说明 |
  | --------------- | -------- |
  | IRemoteObject[] | 返回IRemoteObject对象数组。 |

**示例：**

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

**描述**：

静态方法，关闭给定的文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                 |
  | ------ | ------ | ---- | -------------------- |
  | fd     | number | 是   | 要关闭的文件描述符。 |

**示例：**

  ```
  import fileio from '@ohos.fileio';
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  rpc.MessageParcel.closeFileDescriptor(fd);
  ```

### dupFileDescriptor<sup>8+</sup>

static dupFileDescriptor(fd: number) :number

**描述**：

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

  ```
  import fileio from '@ohos.fileio';
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  let newFd = rpc.MessageParcel.dupFileDescriptor(fd);
  ```

### containFileDescriptors<sup>8+</sup>

containFileDescriptors(): boolean

**描述**：

检查此MessageParcel对象是否包含文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                                               |
  | ------- | ------------------------------------------------------------------ |
  | boolean |true：包含文件描述符，false：未包含文件描述符。|

**示例：**

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

**描述**：

写入文件描述符到MessageParcel。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明         |
  | ------ | ------ | ---- | ------------ |
  | fd     | number | 是   | 文件描述符。 |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：操作成功，false：操作失败。|

**示例：**

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

**描述**：

从MessageParcel中读取文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | number | 返回文件描述符。 |

**示例：**

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

**描述**：

将指定的匿名共享对象写入此MessageParcel。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                |
  | ------ | ------ | ---- | ----------------------------------- |
  | ashmem | Ashmem | 是   | 要写入MessageParcel的匿名共享对象。 |

**返回值：**

  | 类型    | 说明                                                                 |
  | ------- | -------------------------------------------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let parcel = new rpc.MessageParcel();
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);
  let isWriteSuccess = parcel.writeAshmem(ashmem);
  console.log("RpcTest: write ashmem to result is : " + isWriteSuccess);
  ```

### readAshmem<sup>8+</sup>

readAshmem(): Ashmem

**描述**：

从MessageParcel读取匿名共享对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明               |
  | ------ | ------------------ |
  | Ashmem | 返回匿名共享对象。 |

**示例：**

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

**描述**：

获取MessageParcel可以容纳的最大原始数据量。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                                       |
  | ------ | ---------------------------------------------------------- |
  | number | 返回MessageParcel可以容纳的最大原始数据量，即128&nbsp;Mb。 |

**示例：**

  ```
  let parcel = new rpc.MessageParcel();
  let result = parcel.getRawDataCapacity();
  console.log("RpcTest: parcel get RawDataCapacity result is : " + result);
  ```

### writeRawData<sup>8+</sup>

writeRawData(rawData: number[], size: number): boolean

**描述**：

将原始数据写入MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型     | 必填 | 说明                               |
  | ------- | -------- | ---- | ---------------------------------- |
  | rawData | number[] | 是   | 要写入的原始数据。                 |
  | size    | number   | 是   | 发送的原始数据大小，以字节为单位。 |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：写入成功，false：写入失败。|

**示例：**

  ```
  let parcel = new rpc.MessageParcel();
  let arr = [1, 2, 3, 4, 5];
  let isWriteSuccess = parcel.writeRawData(arr, arr.length);
  console.log("RpcTest: parcel write raw data result is : " + isWriteSuccess);
  ```

### readRawData<sup>8+</sup>

readRawData(size: number): number[]

**描述**：

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

  ```
  let parcel = new rpc.MessageParcel();
  let arr = [1, 2, 3, 4, 5];
  let isWriteSuccess = parcel.writeRawData(arr, arr.length);
  console.log("RpcTest: parcel write raw data result is : " + isWriteSuccess);
  let result = parcel.readRawData(5);
  console.log("RpcTest: parcel read raw data result is : " + result);
  ```

## Parcelable<sup>9+</sup>

在进程间通信（IPC）期间，将类的对象写入MessageSequence并从MessageSequence中恢复它们。

### marshalling

marshalling(dataOut: MessageSequence): boolean

**描述**：

将此可序列对象封送到MessageSequence中。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型            | 必填 | 说明                                        |
  | ------- | --------------- | ---- | ------------------------------------------- |
  | dataOut | MessageSequence | 是   | 可序列对象将被封送到的MessageSequence对象。 |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：封送成功，false：封送失败。
**示例：**

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

**描述**：

从MessageSequence中解封此可序列对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型            | 必填 | 说明                                            |
  | ------ | --------------- | ---- | ----------------------------------------------- |
  | dataIn | MessageSequence | 是   | 已将可序列对象封送到其中的MessageSequence对象。 |

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean | true：反序列化成功，false：反序列化失败。|

**示例：**

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

>从API version 9 开始不再维护，建议使用[Parcelable](#parcelable9)类替代。

在进程间通信（IPC）期间，将类的对象写入MessageParcel并从MessageParcel中恢复它们。

### marshalling

marshalling(dataOut: MessageParcel): boolean

**描述**：

将此可序列对象封送到MessageParcel中。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                            | 必填 | 说明                                      |
  | ------- | ------------------------------- | ---- | ----------------------------------------- |
  | dataOut | [MessageParcel](#messageparceldeprecated) | 是   | 可序列对象将被封送到的MessageParcel对象。 |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：封送成功，false：封送失败。
**示例：**

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

**描述**：

从MessageParcel中解封此可序列对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                            | 必填 | 说明                                          |
  | ------ | ------------------------------- | ---- | --------------------------------------------- |
  | dataIn | [MessageParcel](#messageparceldeprecated) | 是   | 已将可序列对象封送到其中的MessageParcel对象。 |

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean | true：反序列化成功，false：反序列化失败。|

**示例：**

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

远端对象的代理持有者。用于获取代理对象。

### asObject

asObject(): IRemoteObject

**描述**：

需派生类实现，获取代理或远端对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型  | 说明 |
  | ---- | ----- |
  | [IRemoteObject](#iremoteobject) | 如果调用者是RemoteObject对象，则直接返回本身；如果调用者是[RemoteProxy](#remoteproxy)对象，则返回它的持有者[IRemoteObject](#iremoteobject)。 |

**示例：**

  ```
  class TestAbility extends rpc.RemoteObject {
      asObject() {
          return this;
      }
  }
  let remoteObject = new TestAbility().asObject();
  ```

**示例：**

  ```
  import FA from "@ohos.ability.featureAbility";
  let proxy;
  let connect = {
      onConnect: function (elementName, remoteProxy) {
          console.log("RpcClient: js onConnect called.");
          proxy = remoteProxy;
      },
      onDisconnect: function (elementName) {
          console.log("RpcClient: onDisconnect");
      },
      onFailed: function () {
          console.log("RpcClient: onFailed");
      }
  };
  let want = {
      "bundleName": "com.ohos.server",
      "abilityName": "com.ohos.server.MainAbility",
  };
  FA.connectAbility(want, connect);

  class TestProxy {
      remote: rpc.RemoteObject;
      constructor(remote) {
          this.remote = remote;
      }
      asObject() {
          return this.remote;
      }
  }
  let iRemoteObject = new TestProxy(proxy).asObject();

  ```

## DeathRecipient

用于订阅远端对象的死亡通知。当被订阅该通知的远端对象死亡时，本端可收到消息，调用[onRemoteDied](#onremotedied)接口。远端对象死亡可以为远端对象所在进程死亡，远端对象所在设备关机或重启，当远端对象与本端对象属于不同设备时，也可为远端对象离开组网时。

### onRemoteDied

onRemoteDied(): void

**描述**：

在成功添加死亡通知订阅后，当远端对象死亡时，将自动调用本方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server died");
      }
  }
  ```

## RequestResult<sup>9+</sup>

发送请求的响应结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

  | 名称    | 类型            | 可读 | 可写 | 说明                                  |
  | ------- | --------------- | ---- | ---- |-------------------------------------- |
  | errCode | number          | 是   | 否   | 错误码。                              |
  | code    | number          | 是   | 否   | 消息代码。                            |
  | data    | MessageSequence | 是   | 否   | 发送给对端进程的MessageSequence对象。 |
  | reply   | MessageSequence | 是   | 否   | 对端进程返回的MessageSequence对象。   |

## SendRequestResult<sup>8+(deprecated)</sup>

>从API version 9 开始不再维护，建议使用[RequestResult](#requestresult9)类替代。

发送请求的响应结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

  | 名称    | 类型          | 可读 | 可写 | 说明                                |
  | ------- | ------------- | ---- | ---- | ----------------------------------- |
  | errCode | number        | 是   | 否   | 错误码。                            |
  | code    | number        | 是   | 否   | 消息代码。                          |
  | data    | MessageParcel | 是   | 否   | 发送给对端进程的MessageParcel对象。 |
  | reply   | MessageParcel | 是   | 否   | 对端进程返回的MessageParcel对象。   |

## IRemoteObject

该接口可用于查询或获取接口描述符、添加或删除死亡通知、转储对象状态到特定文件、发送消息。

### getLocalInterface<sup>9+</sup>

getLocalInterface(descriptor: string): IRemoteBroker

**描述**：

查询接口描述符的字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型   | 必填 | 说明                 |
  | ---------- | ------ | ---- | -------------------- |
  | descriptor | string | 是   | 接口描述符的字符串。 |

**返回值：**

  | 类型          | 说明                                          |
  | ------------- | --------------------------------------------- |
  | IRemoteBroker | 返回绑定到指定接口描述符的IRemoteBroker对象。 |

### queryLocalInterface<sup>(deprecated)</sup>

>从API version 9 开始不再维护，建议使用[getLocalInterface](#getlocalinterface9)类替代。

queryLocalInterface(descriptor: string): IRemoteBroker

**描述**：

查询接口描述符的字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型   | 必填 | 说明                 |
  | ---------- | ------ | ---- | -------------------- |
  | descriptor | string | 是   | 接口描述符的字符串。 |

**返回值：**

  | 类型          | 说明                                          |
  | ------------- | --------------------------------------------- |
  | IRemoteBroker | 返回绑定到指定接口描述符的IRemoteBroker对象。 |

### sendRequest<sup>(deprecated)</sup>

>从API version 9 开始不再维护，建议使用[sendMessageRequest](#sendmessagerequest9)类替代。

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

**描述**：

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型 | 必填 | 说明  |
  | ------- | ------------------------------- | ---- | ---- |
  | code    | number                          | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的&nbsp;MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption) | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean | true：发送成功，false：发送失败。|


### sendRequest<sup>8+(deprecated)</sup>

>从API version 9 开始不再维护，建议使用[sendMessageRequest](#sendmessagerequest9)类替代。

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                            | 必填 | 说明                                                                                   |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的&nbsp;MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption) | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型                             | 说明                                          |
  | -------------------------------- | --------------------------------------------- |
  | Promise&lt;SendRequestResult&gt; | 返回一个期约，兑现值是sendRequestResult实例。 |


### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption): Promise&lt;RequestResult&gt;

**描述**：

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendMessageRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                            | 必填 | 说明                                                                                   |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的&nbsp;MessageSequence对象。                                            |
  | reply   | [MessageSequence](#messagesequence9) | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options | [MessageOption](#messageoption) | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型                         | 说明                                      |
  | ---------------------------- | ----------------------------------------- |
  | Promise&lt;RequestResult&gt; | 返回一个期约，兑现值是requestResult实例。 |


### sendMessageRequest<sup>9+</sup>

sendMessageRequest(code: number, data: MessageSequence, reply: MessageSequence, options: MessageOption, callback: AsyncCallback&lt;RequestResult&gt;): void

**描述**：

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型                               | 必填 | 说明                                                                                   |
  | -------- | ---------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code     | number                             | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data     | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的&nbsp;MessageSequence对象。                                            |
  | reply    | [MessageSequence](#messagesequence9) | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options  | [MessageOption](#messageoption)    | 是   | 本次请求的同异步模式，默认同步调用。                                                   |
  | callback | AsyncCallback&lt;RequestResult&gt; | 是   | 接收发送结果的回调。                                                                   |

### sendRequest<sup>8+(deprecated)</sup>

>从API version 9 开始不再维护，建议使用[sendMessageRequest](#sendmessagerequest9)类替代。

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

**描述**：

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型                                   | 必填 | 说明                                                                                   |
  | -------- | -------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code     | number                                 | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data     | [MessageParcel](#messageparceldeprecated)        | 是   | 保存待发送数据的&nbsp;MessageParcel对象。                                              |
  | reply    | [MessageParcel](#messageparceldeprecated)        | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options  | [MessageOption](#messageoption)        | 是   | 本次请求的同异步模式，默认同步调用。                                                   |
  | callback | AsyncCallback&lt;SendRequestResult&gt; | 是   | 接收发送结果的回调。                                                                   |

### registerDeathRecipient<sup>9+</sup>

registerDeathRecipient(recipient: DeathRecipient, flags: number): void

**描述**：

注册用于接收远程对象死亡通知的回调。如果与RemoteProxy对象匹配的远程对象进程死亡，则调用此方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注册的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |

### addDeathrecipient<sup>(deprecated)</sup>

>从API version 9 开始不再维护，建议使用[registerDeathRecipient](#registerdeathrecipient9)类替代。

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

**描述**：

注册用于接收远程对象死亡通知的回调。如果与RemoteProxy对象匹配的远程对象进程死亡，则调用此方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注册的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean | true：回调注册成功，false：回调注册失败。|


### unregisterDeathRecipient<sup>9+</sup>

unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void

**描述**：

注销用于接收远程对象死亡通知的回调。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注销的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |

### removeDeathRecipient<sup>(deprecated)</sup>

>从API version 9 开始不再维护，建议使用[unregisterDeathRecipient](#unregisterdeathrecipient9)类替代。

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

**描述**：

注销用于接收远程对象死亡通知的回调。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注销的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean | true：回调注销成功，false：回调注销失败。|

### getDescriptor<sup>9+</sup>

getDescriptor(): string

**描述**：

获取对象的接口描述符，接口描述符为字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | string | 返回接口描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |


### getInterfaceDescriptor<sup>(deprecated)</sup>

>从API version 9 开始不再维护，建议使用[getDescriptor](#getdescriptor9)类替代。

getInterfaceDescriptor(): string

**描述**：

获取对象的接口描述符，接口描述符为字符串。

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

  | 类型    | 说明                                        |
  | ------- | ------------------------------------------- |
  | boolean | true：对象死亡，false：对象未死亡。|


## RemoteProxy

实现IRemoteObject代理对象。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

| 名称                  | 默认值                      | 说明                              |
| --------------------- | ----------------------- | --------------------------------- |
| PING_TRANSACTION      | 1599098439 (0x5f504e47) | 内部指令码，用于测试IPC服务正常。 |
| DUMP_TRANSACTION      | 1598311760 (0x5f444d50) | 内部指令码，获取Binder内部状态。  |
| INTERFACE_TRANSACTION | 1598968902 (0x5f4e5446) | 内部指令码，获取对端接口描述符。  |
| MIN_TRANSACTION_ID    | 1 (0x00000001)          | 最小有效指令码。                  |
| MAX_TRANSACTION_ID    | 16777215 (0x00FFFFFF)   | 最大有效指令码。                  |

### sendRequest<sup>(deprecated)</sup>

>从API version 9 开始不再维护，建议使用[sendMessageRequest](#sendmessagerequest9)类替代。

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

**描述**：

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                            | 必填 | 说明                                                                                   |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的&nbsp;MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption) | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean | true：发送成功，false：发送失败。|

**示例：**

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

**描述**：

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendMessageRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                            | 必填 | 说明                                                                                   |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的&nbsp;MessageSequence对象。                                            |
  | reply   | [MessageSequence](#messagesequence9)  | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options | [MessageOption](#messageoption) | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型                         | 说明                                      |
  | ---------------------------- | ----------------------------------------- |
  | Promise&lt;RequestResult&gt; | 返回一个期约，兑现值是requestResult实例。 |

**示例：**

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

>从API version 9 开始不再维护，建议使用[sendMessageRequest](#sendmessagerequest9)类替代。

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

**描述**：

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                            | 必填 | 说明                                                                                   |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的&nbsp;MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption) | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型                             | 说明                                          |
  | -------------------------------- | --------------------------------------------- |
  | Promise&lt;SendRequestResult&gt; | 返回一个期约，兑现值是sendRequestResult实例。 |

**示例：**

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

**描述**：

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容。如果为选项设置了同步模式，则将在sendMessageRequest返回后的某个时机执行回调，回复内容在RequestResult的reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型                               | 必填 | 说明                                                                                   |
  | -------- | ---------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code     | number                             | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data     | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的&nbsp;MessageSequence对象。                                            |
  | reply    | [MessageSequence](#messagesequence9) | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options  | [MessageOption](#messageoption)    | 是   | 本次请求的同异步模式，默认同步调用。                                                   |
  | callback | AsyncCallback&lt;RequestResult&gt; | 是   | 接收发送结果的回调。                                                                   |

**示例：**

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

>从API version 9 开始不再维护，建议使用[sendMessageRequest](#sendmessagerequest9)类替代。

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

**描述**：

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型                                   | 必填 | 说明                                                                                   |
  | -------- | -------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code     | number                                 | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data     | [MessageParcel](#messageparceldeprecated)        | 是   | 保存待发送数据的&nbsp;MessageParcel对象。                                              |
  | reply    | [MessageParcel](#messageparceldeprecated)        | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options  | [MessageOption](#messageoption)        | 是   | 本次请求的同异步模式，默认同步调用。                                                   |
  | callback | AsyncCallback&lt;SendRequestResult&gt; | 是   | 接收发送结果的回调。                                                                   |

**示例：**

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

**描述**：

查询并获取当前接口描述符对应的本地接口对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型   | 必填 | 说明                   |
  | --------- | ------ | ---- | ---------------------- |
  | interface | string | 是   | 需要查询的接口描述符。 |

**返回值：**

  | 类型          | 说明                                       |
  | ------------- | ------------------------------------------ |
  | IRemoteBroker | 默认返回Null，标识该接口是一个代理侧接口。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | --------  |
  | 1900006 | only remote object permitted |

**示例：**

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

>从API version 9 开始不再维护，建议使用[getLocalInterface](#getlocalinterface9)类替代。

queryLocalInterface(interface: string): IRemoteBroker

**描述**：

查询并获取当前接口描述符对应的本地接口对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型   | 必填 | 说明                   |
  | --------- | ------ | ---- | ---------------------- |
  | interface | string | 是   | 需要查询的接口描述符。 |

**返回值：**

  | 类型          | 说明                                       |
  | ------------- | ------------------------------------------ |
  | IRemoteBroker | 默认返回Null，标识该接口是一个代理侧接口。 |

**示例：**

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

**描述**：

注册用于接收远程对象死亡通知的回调。如果与RemoteProxy对象匹配的远程对象进程死亡，则调用此方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注册的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |

**示例：**

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

>从API version 9 开始不再维护，建议使用[registerDeathRecipient](#registerdeathrecipient9)类替代。

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

**描述**：

注册用于接收远程对象死亡通知的回调，增加proxy对象上的死亡通知。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明                              |
  | --------- | --------------------------------- | ---- | --------------------------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 收件人表示要注册的回调。          |
  | flags     | number                            | 是   | 死亡通知标志。保留参数。设置为0。 |

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean | true：回调注册成功，false：回调注册失败。|

**示例：**

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

**描述**：

注销用于接收远程对象死亡通知的回调。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明           |
  | --------- | --------------------------------- | ---- | -------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注销的回调。 |
  | flags     | number                            | 是   | 死亡通知标志。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |

**示例：**

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

>从API version 9 开始不再维护，建议使用[unregisterDeathRecipient](#unregisterdeathrecipient9)类替代。

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

**描述**：

注销用于接收远程对象死亡通知的回调。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型                              | 必填 | 说明                              |
  | --------- | --------------------------------- | ---- | --------------------------------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是   | 要注销的死亡回调。                |
  | flags     | number                            | 是   | 死亡通知标志。保留参数。设置为0。 |

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean | true：回调注销成功，false：回调注销失败。|

**示例：**

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

**描述**：

获取对象的接口描述符，接口描述符为字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | string | 返回接口描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------- |
  | 1900008 | proxy or remote object is invalid |
  | 1900007 | communication failed              |

**示例：**

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

>从API version 9 开始不再维护，建议使用[getDescriptor](#getdescriptor9)类替代。

getInterfaceDescriptor(): string

**描述**：

查询当前代理对象接口的描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明               |
  | ------ | ------------------ |
  | string | 当前的接口描述符。 |

**示例：**

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

**描述**：

指示对应的RemoteObject是否死亡。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                                      |
  | ------- | --------------------------------------------------------- |
  | boolean | true：对应的对象已经死亡，false：对应的对象未死亡|

**示例：**

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

公共消息选项（int标志，int等待时间），使用标志中指定的标志构造指定的MessageOption对象。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

  | 名称          | 默认值   | 说明                                                        |
  | ------------- | ---- | ----------------------------------------------------------- |
  | TF_SYNC       | 0    | 同步调用标识。                                                  |
  | TF_ASYNC      | 1    | 异步调用标识。                                                  |
  | TF_ACCEPT_FDS | 0x10 | 指示sendMessageRequest<sup>9+</sup>接口可以返回文件描述符。 |
  | TF_WAIT_TIME  | 8    | 默认等待时间(单位/秒)。                                          |


### constructor<sup>9+</sup>

constructor(async?: boolean);

**描述**：

MessageOption构造函数。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型   | 必填 | 说明                                   |
  | --------- | ------ | ---- | -------------------------------------- |
  | syncFlags | number | 否   | 同步调用或异步调用标志。默认同步调用。 |


**示例：**

  ```
  class TestRemoteObject extends rpc.MessageOption {
    constructor(async) {
        super(async);
    }
  }
  ```

### constructor

constructor(syncFlags?: number, waitTime?: number)

**描述**：

MessageOption构造函数。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名    | 类型   | 必填 | 说明                                          |
  | --------- | ------ | ---- | --------------------------------------------- |
  | syncFlags | number | 否   | 同步调用或异步调用标志。默认同步调用。        |
  | waitTime  | number | 否   | 调用rpc最长等待时间。默认&nbsp;TF_WAIT_TIME。 |

**示例：**

  ```
  class TestRemoteObject extends rpc.MessageOption {
    constructor(syncFlags,waitTime) {
        super(syncFlags,waitTime);
    }
  }
  ```
### isAsync<sup>9+</sup>

isAsync(): boolean;

**描述**：

获取SendMessageRequest调用中确定同步或是异步的标志。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                 |
  | ------- | ------------------------------------ |
  | boolean | true：同步调用成功，false：异步调用成功。 |

**示例：**

  ```
  let option = new rpc.MessageOption();
  let isAsync = option.isAsync();
  ```

### setAsync<sup>9+</sup>

setAsync(async: boolean): void;

**描述**：

设置SendMessageRequest调用中确定同步或是异步的标志。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  let option = new rpc.MessageOption();
  let setAsync = option.setAsync(true);
  console.log("Set synchronization flag");
  ```

### getFlags

getFlags(): number

**描述**：

获取同步调用或异步调用标志。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                 |
  | ------ | ------------------------------------ |
  | number | 调用成功返回同步调用或异步调用标志。 |

**示例：**

  ```
  try {
      let option = new rpc.MessageOption();
      console.info("create object successfully.");
      let flog = option.getFlags();
      console.info("run getFlags success, flog is " + flog);
      option.setFlags(1)
      console.info("run setFlags success");
      let flog2 = option.getFlags();
      console.info("run getFlags success, flog2 is " + flog2);
  } catch (error) {
      console.info("error " + error);
  }
  ```
  
### setFlags

setFlags(flags: number): void

**描述**：

设置同步调用或异步调用标志。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                     |
  | ------ | ------ | ---- | ------------------------ |
  | flags  | number | 是   | 同步调用或异步调用标志。 |

**示例：**

  ```
  try {
      let option = new rpc.MessageOption();
      option.setFlags(1)
      console.info("run setFlags success");
      let flog = option.getFlags();
      console.info("run getFlags success, flog is " + flog);
  } catch (error) {
      console.info("error " + error);
  }
  ```

### getWaitTime

getWaitTime(): number

获取rpc调用的最长等待时间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明              |
  | ------ | ----------------- |
  | number | rpc最长等待时间。 |

**示例：**

  ```
  try {
      let option = new rpc.MessageOption();
      let time = option.getWaitTime();
      console.info("run getWaitTime success");
      option.setWaitTime(16);
      let time2 = option.getWaitTime();
      console.info("run getWaitTime success, time is " + time);
  } catch (error) {
      console.info("error " + error);
  }
  ```

### setWaitTime

setWaitTime(waitTime: number): void

**描述**：

设置rpc调用最长等待时间。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型   | 必填 | 说明                  |
  | -------- | ------ | ---- | --------------------- |
  | waitTime | number | 是   | rpc调用最长等待时间。 |

**示例：**

  ```
  try {
      let option = new rpc.MessageOption();
      option.setWaitTime(16);
      let time = option.getWaitTime();
      console.info("run getWaitTime success, time is " + time);
  } catch (error) {
      console.info("error " + error);
  }
  ```

## IPCSkeleton

用于获取IPC上下文信息，包括获取UID和PID、获取本端和对端设备ID、检查接口调用是否在同一设备上。

### getContextObject

static getContextObject(): IRemoteObject

**描述**：

静态方法，获取系统能力的管理者。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型                            | 说明                 |
  | ------------------------------- | -------------------- |
  | [IRemoteObject](#iremoteobject) | 返回系统能力管理者。 |

**示例：**

  ```
  let samgr = rpc.IPCSkeleton.getContextObject();
  console.log("RpcServer: getContextObject result: " + samgr);
  ```

### getCallingPid

static getCallingPid(): number

**描述**：

静态方法，获取调用者的PID。此方法由RemoteObject对象在onRemoteRequest方法中调用，不在IPC上下文环境（onRemoteRequest）中调用则返回本进程的PID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明              |
  | ------ | ----------------- |
  | number | 返回调用者的PID。 |

**示例：**

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

**描述**：

静态方法，获取调用者的UID。此方法由RemoteObject对象在onRemoteRequest方法中调用，不在IPC上下文环境（onRemoteRequest）中调用则返回本进程的UID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明              |
  | ------ | ----------------- |
  | number | 返回调用者的UID。 |

**示例：**

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

**描述**：

静态方法，获取调用者的TokenId，用于被调用方对调用方的身份校验。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
 
   | 类型   | 说明                  |
   | ------ | --------------------- |
   | number | 返回调用者的TokenId。 |
  
**示例：**

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

**描述**：

静态方法，获取调用者进程所在的设备ID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                         |
  | ------ | ---------------------------- |
  | string | 返回调用者进程所在的设备ID。 |

**示例：**

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

**描述**：

静态方法，获取本端设备ID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明               |
  | ------ | ------------------ |
  | string | 返回本地设备的ID。 |

**示例：**

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

**描述**：

静态方法，检查当前通信对端是否是本设备的进程。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                                      |
  | ------- | --------------------------------------------------------- |
  | boolean | true：调用在同一台设备，false：调用未在同一台设备。|

**示例：**

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

**描述**：

静态方法，将所有挂起的命令从指定的RemoteProxy刷新到相应的RemoteObject。建议在执行任何时间敏感操作之前调用此方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                            | 必填 | 说明                |
  | ------ | ------------------------------- | ---- | ------------------- |
  | object | [IRemoteObject](#iremoteobject) | 是   | 指定的RemoteProxy。 |


**示例：**

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

>从API version 9 开始不再维护，建议使用[flushCmdBuffer](#flushcmdbuffer9)类替代。

static flushCommands(object: IRemoteObject): number

**描述**：

静态方法，将所有挂起的命令从指定的RemoteProxy刷新到相应的RemoteObject。建议在执行任何时间敏感操作之前调用此方法。

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

**描述**：

静态方法，将远程用户的UID和PID替换为本地用户的UID和PID。它可以用于身份验证等场景。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                                 |
  | ------ | ------------------------------------ |
  | string | 返回包含远程用户的UID和PID的字符串。 |

**示例：**

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

**描述**：

静态方法，将远程用户的UID和PID替换为本地用户的UID和PID。它可以用于身份验证等场景。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型   | 必填 | 说明                                                               |
  | -------- | ------ | ---- | ------------------------------------------------------------------ |
  | identity | string | 是   | 标识表示包含远程用户UID和PID的字符串。由resetCallingIdentity返回。 |

**示例：**

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

>从API version 9 开始不再维护，建议使用[restoreCallingIdentity](#restorecallingidentity9)类替代。

static setCallingIdentity(identity: string): boolean

**描述**：

静态方法，将UID和PID恢复为远程用户的UID和PID。它通常在使用resetCallingIdentity后调用，需要resetCallingIdentity返回的远程用户的UID和PID。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名   | 类型   | 必填 | 说明                                                               |
  | -------- | ------ | ---- | ------------------------------------------------------------------ |
  | identity | string | 是   | 标识表示包含远程用户UID和PID的字符串。由resetCallingIdentity返回。 |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：设置成功，false：设置失败。|

**示例：**

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

实现远程对象。服务提供者必须继承此类。

### constructor

constructor(descriptor: string)

**描述**：

RemoteObject构造函数。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型   | 必填 | 说明         |
  | ---------- | ------ | ---- | ------------ |
  | descriptor | string | 是   | 接口描述符。 |


### sendRequest<sup>(deprecated)</sup>

>从API version 9 开始不再维护，建议使用[sendMessageRequest](#sendmessagerequest9)类替代。

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                            | 必填 | 说明                                                                                   |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的&nbsp;MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption) | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型    | 说明                                          |
  | ------- | --------------------------------------------- |
  | boolean | true：发送成功，false：发送失败。|

**示例：**

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

>从API version 9 开始不再维护，建议使用[sendMessageRequest](#sendmessagerequest9)类替代。

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise&lt;SendRequestResult&gt;

**描述**：

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                            | 必填 | 说明                                                                                   |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageParcel](#messageparceldeprecated) | 是   | 保存待发送数据的&nbsp;MessageParcel对象。                                              |
  | reply   | [MessageParcel](#messageparceldeprecated) | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options | [MessageOption](#messageoption) | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型                             | 说明                                          |
  | -------------------------------- | --------------------------------------------- |
  | Promise&lt;SendRequestResult&gt; | 返回一个期约，兑现值是sendRequestResult实例。 |

**示例：**

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

**描述**：

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendMessageRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型                            | 必填 | 说明                                                                                   |
  | ------- | ------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code    | number                          | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data    | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的&nbsp;MessageSequence对象。                                            |
  | reply   | [MessageSequence](#messagesequence9) | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options | [MessageOption](#messageoption) | 是   | 本次请求的同异步模式，默认同步调用。                                                   |

**返回值：**

  | 类型                         | 说明                                          |
  | ---------------------------- | --------------------------------------------- |
  | Promise&lt;RequestResult&gt; | 返回一个期约，兑现值是sendRequestResult实例。 |

**示例：**

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

**描述**：

以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容。如果为选项设置了同步模式，则将在sendMessageRequest返回时收到回调，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名        | 类型                               | 必填 | 说明                                                                                   |
  | ------------- | ---------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code          | number                             | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data          | [MessageSequence](#messagesequence9) | 是   | 保存待发送数据的&nbsp;MessageSequence对象。                                            |
  | reply         | [MessageSequence](#messagesequence9) | 是   | 接收应答数据的MessageSequence对象。                                                    |
  | options       | [MessageOption](#messageoption)    | 是   | 本次请求的同异步模式，默认同步调用。                                                   |
  | AsyncCallback | AsyncCallback&lt;RequestResult&gt; | 是   | 接收发送结果的回调。                                                                   |

**示例：**

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

>从API version 9 开始不再维护，建议使用[sendMessageRequest](#sendmessagerequest9)类替代。

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

**描述**：

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名        | 类型                                   | 必填 | 说明                                                                                   |
  | ------------- | -------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
  | code          | number                                 | 是   | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data          | [MessageParcel](#messageparceldeprecated)        | 是   | 保存待发送数据的&nbsp;MessageParcel对象。                                              |
  | reply         | [MessageParcel](#messageparceldeprecated)        | 是   | 接收应答数据的MessageParcel对象。                                                      |
  | options       | [MessageOption](#messageoption)        | 是   | 本次请求的同异步模式，默认同步调用。                                                   |
  | AsyncCallback | AsyncCallback&lt;SendRequestResult&gt; | 是   | 接收发送结果的回调。                                                                   |

**示例：**

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

>从API version 9 开始不再维护，建议使用[onRemoteMessageRequest](#onremotemessagerequest9)类替代。

onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean

**描述**：

sendMessageRequest请求的响应处理函数，服务端在该函数里处理请求，回复结果。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                            | 必填 | 说明                                    |
  | ------ | ------------------------------- | ---- | --------------------------------------- |
  | code   | number                          | 是   | 对端发送的服务请求码。                  |
  | data   | [MessageParcel](#messageparceldeprecated) | 是   | 携带客户端调用参数的MessageParcel对象。 |
  | reply  | [MessageParcel](#messageparceldeprecated) | 是   | 写入结果的MessageParcel对象。           |
  | option | [MessageOption](#messageoption) | 是   | 指示操作是同步还是异步。                |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：操作成功，false：操作失败。|

**示例：**

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

> **说明：**
>
>* 开发者应优先选择重载onRemoteMessageRequest方法，其中可以自由实现同步和异步的消息处理。
>* 开发者同时重载onRemoteRequest和onRemoteMessageRequest方法时，仅onRemoteMessageRequest方法生效。

sendMessageRequest请求的响应处理函数，服务端在该函数里同步或异步地处理请求，回复结果。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型                            | 必填 | 说明                                      |
  | ------ | ------------------------------- | ---- | ----------------------------------------- |
  | code   | number                          | 是   | 对端发送的服务请求码。                    |
  | data   | [MessageSequence](#messagesequence9) | 是   | 携带客户端调用参数的MessageSequence对象。 |
  | reply  | [MessageSequence](#messagesequence9) | 是   | 写入结果的MessageSequence对象。           |
  | option | [MessageOption](#messageoption) | 是   | 指示操作是同步还是异步。                  |

**返回值：**

  | 类型              | 说明                                                                                           |
  | ----------------- | ---------------------------------------------------------------------------------------------- |
  | boolean           | 若在onRemoteMessageRequest中同步地处理请求，则返回一个布尔值：true：操作成功，false：操作失败。 |
  | Promise\<boolean> | 若在onRemoteMessageRequest中异步地处理请求，则返回一个Promise对象。                                 |

**重载onRemoteMessageRequest方法同步处理请求示例：**

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

  **重载onRemoteMessageRequest方法异步处理请求示例：**

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

**同时重载onRemoteMessageRequest和onRemoteRequest方法同步处理请求示例：**

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
      // 同时调用仅会执行onRemoteMessageRequest
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

  **同时重载onRemoteMessageRequest和onRemoteRequest方法异步处理请求示例：**

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
      // 同时调用仅会执行onRemoteMessageRequest
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

**描述**：

获取通信对端的进程Uid。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
  | 类型   | 说明                    |
  | ------ | ----------------------- |
  | number | 返回通信对端的进程Uid。 |

**示例：**

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

**描述**：

获取通信对端的进程Pid。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                    |
  | ------ | ----------------------- |
  | number | 返回通信对端的进程Pid。 |

**示例：**

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

**描述**：

查询接口描述符的字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型   | 必填 | 说明                 |
  | ---------- | ------ | ---- | -------------------- |
  | descriptor | string | 是   | 接口描述符的字符串。 |

**返回值：**

  | 类型          | 说明                                          |
  | ------------- | --------------------------------------------- |
  | IRemoteBroker | 返回绑定到指定接口描述符的IRemoteBroker对象。 |


**示例：**

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

>从API version 9 开始不再维护，建议使用[getLocalInterface](#getlocalinterface9)类替代。

queryLocalInterface(descriptor: string): IRemoteBroker

**描述**：

查询并获取当前接口描述符对应的远端对象是否已经存在。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名     | 类型   | 必填 | 说明                   |
  | ---------- | ------ | ---- | ---------------------- |
  | descriptor | string | 是   | 需要查询的接口描述符。 |

**返回值：**

  | 类型          | 说明                                                               |
  | ------------- | ------------------------------------------------------------------ |
  | IRemoteBroker | 如果接口描述符对应的远端对象存在，则返回该远端对象，否则返回Null。 |

**示例：**

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

**描述**：

获取对象的接口描述符。接口描述符为字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | string | 返回接口描述符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900008 | proxy or remote object is invalid |

**示例：**

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

>从API version 9 开始不再维护，建议使用[getDescriptor](#getdescriptor9)类替代。

getInterfaceDescriptor(): string

**描述**：

查询接口描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明             |
  | ------ | ---------------- |
  | string | 返回接口描述符。 |

**示例：**

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

**描述**：

此接口用于把接口描述符和IRemoteBroker对象绑定。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名         | 类型          | 必填 | 说明                                  |
  | -------------- | ------------- | ---- | ------------------------------------- |
  | localInterface | IRemoteBroker | 是   | 将与描述符绑定的IRemoteBroker对象。   |
  | descriptor     | string        | 是   | 用于与IRemoteBroker对象绑定的描述符。 |

**示例：**

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

>从API version 9 开始不再维护，建议使用[modifyLocalInterface](#modifylocalinterface9)类替代。

attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void

**描述**：

此接口用于把接口描述符和IRemoteBroker对象绑定。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名         | 类型          | 必填 | 说明                                  |
  | -------------- | ------------- | ---- | ------------------------------------- |
  | localInterface | IRemoteBroker | 是   | 将与描述符绑定的IRemoteBroker对象。   |
  | descriptor     | string        | 是   | 用于与IRemoteBroker对象绑定的描述符。 |

**示例：**

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

提供与匿名共享内存对象相关的方法，包括创建、关闭、映射和取消映射Ashmem、从Ashmem读取数据和写入数据、获取Ashmem大小、设置Ashmem保护。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

映射内存保护类型：

  | 名称       | 默认值  | 说明               |
  | ---------- | --- | ------------------ |
  | PROT_EXEC  | 4   | 映射的内存可执行   |
  | PROT_NONE  | 0   | 映射的内存不可访问 |
  | PROT_READ  | 1   | 映射的内存可读     |
  | PROT_WRITE | 2   | 映射的内存可写     |

### create<sup>9+</sup>

static create(name: string, size: number): Ashmem

**描述**：

静态方法，根据指定的名称和大小创建Ashmem对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                         |
  | ------ | ------ | ---- | ---------------------------- |
  | name   | string | 是   | 名称，用于查询Ashmem信息。   |
  | size   | number | 是   | Ashmem的大小，以字节为单位。 |

**返回值：**

  | 类型   | 说明                                           |
  | ------ | ---------------------------------------------- |
  | Ashmem | 返回创建的Ashmem对象；如果创建失败，返回null。 |

**示例：**

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

>从API version 9 开始不再维护，建议使用[create](#create9)类替代。

static createAshmem(name: string, size: number): Ashmem

**描述**：

静态方法，根据指定的名称和大小创建Ashmem对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                         |
  | ------ | ------ | ---- | ---------------------------- |
  | name   | string | 是   | 名称，用于查询Ashmem信息。   |
  | size   | number | 是   | Ashmem的大小，以字节为单位。 |

**返回值：**

  | 类型   | 说明                                           |
  | ------ | ---------------------------------------------- |
  | Ashmem | 返回创建的Ashmem对象；如果创建失败，返回null。 |

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashemm by createAshmem : " + ashmem + " size is : " + size);
  ```

### create<sup>9+</sup>

static create(ashmem: Ashmem): Ashmem

**描述**：

静态方法，通过复制现有Ashmem对象的文件描述符(fd)来创建Ashmem对象。两个Ashmem对象指向同一个共享内存区域。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                 |
  | ------ | ------ | ---- | -------------------- |
  | ashmem | Ashmem | 是   | 已存在的Ashmem对象。 |

**返回值：**

  | 类型   | 说明                   |
  | ------ | ---------------------- |
  | Ashmem | 返回创建的Ashmem对象。 |


**示例：**

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

>从API version 9 开始不再维护，建议使用[create](#create9)类替代。

static createAshmemFromExisting(ashmem: Ashmem): Ashmem

**描述**：

静态方法，通过复制现有Ashmem对象的文件描述符(fd)来创建Ashmem对象。两个Ashmem对象指向同一个共享内存区域。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                 |
  | ------ | ------ | ---- | -------------------- |
  | ashmem | Ashmem | 是   | 已存在的Ashmem对象。 |

**返回值：**

  | 类型   | 说明                   |
  | ------ | ---------------------- |
  | Ashmem | 返回创建的Ashmem对象。 |

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let ashmem2 = rpc.Ashmem.createAshmemFromExisting(ashmem);
  let size = ashmem2.getAshmemSize();
  console.log("RpcTest: get ashemm by createAshmemFromExisting : " + ashmem2 + " size is : " + size);
  ```

### closeAshmem<sup>8+</sup>

closeAshmem(): void

**描述**：

关闭这个Ashmem。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.closeAshmem();
  ```

### unmapAshmem<sup>8+</sup>

unmapAshmem(): void

**描述**：

删除该Ashmem对象的地址映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);
  ashmem.unmapAshmem();
  ```

### getAshmemSize<sup>8+</sup>

getAshmemSize(): number

**描述**：

获取Ashmem对象的内存大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型   | 说明                       |
  | ------ | -------------------------- |
  | number | 返回Ashmem对象的内存大小。 |

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashmem is " + ashmem + " size is : " + size);
  ```

### mapTypedAshmem<sup>9+</sup>

mapTypedAshmem(mapType: number): void

**描述**：

在此进程的虚拟地址空间上创建共享文件映射，映射区域大小由此Ashmem对象指定。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型   | 必填 | 说明                           |
  | ------- | ------ | ---- | ------------------------------ |
  | mapType | number | 是   | 指定映射的内存区域的保护等级。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | ------ |
  | 1900001     | call mmap function failed |

**示例：**

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

>从API version 9 开始不再维护，建议使用[mapTypedAshmem](#maptypedashmem9)类替代。

mapAshmem(mapType: number): boolean

**描述**：

在此进程的虚拟地址空间上创建共享文件映射，映射区域大小由此Ashmem对象指定。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名  | 类型   | 必填 | 说明                           |
  | ------- | ------ | ---- | ------------------------------ |
  | mapType | number | 是   | 指定映射的内存区域的保护等级。 |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：映射成功，false：映射失败。|

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapReadAndWrite = ashmem.mapAshmem(ashmem.PROT_READ | ashmem.PROT_WRITE);
  console.log("RpcTest: map ashmem result is  : " + mapReadAndWrite);
  ```

### mapReadWriteAshmem<sup>9+</sup>

mapReadWriteAshmem(): void

**描述**：

在此进程虚拟地址空间上创建可读写的共享文件映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900001 | call mmap function failed |

**示例：**

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

>从API version 9 开始不再维护，建议使用[mapReadWriteAshmem](#mapreadwriteashmem9)类替代。

mapReadAndWriteAshmem(): boolean

**描述**：

在此进程虚拟地址空间上创建可读写的共享文件映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：映射成功，false：映射失败。|

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadAndWriteAshmem();
  console.log("RpcTest: map ashmem result is  : " + mapResult);
  ```

### mapReadonlyAshmem<sup>9+</sup>

mapReadonlyAshmem(): void

**描述**：

在此进程虚拟地址空间上创建只读的共享文件映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900001 | call mmap function failed |

**示例：**

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

>从API version 9 开始不再维护，建议使用[mapReadonlyAshmem](#mapreadonlyashmem9)类替代。

mapReadOnlyAshmem(): boolean

**描述**：

在此进程虚拟地址空间上创建只读的共享文件映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：映射成功，false：映射失败。|

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadOnlyAshmem();
  console.log("RpcTest: Ashmem mapReadOnlyAshmem result is : " + mapResult);
  ```

### setProtectionType<sup>9+</sup>

setProtectionType(protectionType: number): void

**描述**：

设置映射内存区域的保护等级。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名         | 类型   | 必填 | 说明               |
  | -------------- | ------ | ---- | ------------------ |
  | protectionType | number | 是   | 要设置的保护类型。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | -------- | ------- |
  | 1900002 | call os ioctl function failed |

**示例：**

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

>从API version 9 开始不再维护，建议使用[setProtectionType](#setprotectiontype9)类替代。

setProtection(protectionType: number): boolean

**描述**：

设置映射内存区域的保护等级。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名         | 类型   | 必填 | 说明               |
  | -------------- | ------ | ---- | ------------------ |
  | protectionType | number | 是   | 要设置的保护类型。 |

**返回值：**

  | 类型    | 说明                                      |
  | ------- | ----------------------------------------- |
  | boolean | true：设置成功，false：设置失败。|

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let result = ashmem.setProtection(ashmem.PROT_READ);
  console.log("RpcTest: Ashmem setProtection result is : " + result);
  ```

### writeAshmem<sup>9+</sup>

writeAshmem(buf: number[], size: number, offset: number): void

**描述**：

将数据写入此Ashmem对象关联的共享文件。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                                               |
  | ------ | -------- | ---- | -------------------------------------------------- |
  | buf    | number[] | 是   | 写入Ashmem对象的数据。                             |
  | size   | number   | 是   | 要写入的数据大小。                                 |
  | offset | number   | 是   | 要写入的数据在此Ashmem对象关联的内存区间的起始位置 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID | 错误信息 |
  | ------- | -------- |
  | 1900003 | write to ashmem failed |

**示例：**

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

>从API version 9 开始不再维护，建议使用[writeAshmem](#writeashmem9)类替代。

writeToAshmem(buf: number[], size: number, offset: number): boolean

**描述**：

将数据写入此Ashmem对象关联的共享文件。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型     | 必填 | 说明                                               |
  | ------ | -------- | ---- | -------------------------------------------------- |
  | buf    | number[] | 是   | 写入Ashmem对象的数据。                             |
  | size   | number   | 是   | 要写入的数据大小。                                 |
  | offset | number   | 是   | 要写入的数据在此Ashmem对象关联的内存区间的起始位置 |

**返回值：**

  | 类型    | 说明                                                                                      |
  | ------- | ----------------------------------------------------------------------------------------- |
  | boolean | true：如果数据写入成功，false：在其他情况下，如数据写入越界或未获得写入权限。。 |

**示例：**

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

**描述**：

从此Ashmem对象关联的共享文件中读取数据。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                               |
  | ------ | ------ | ---- | -------------------------------------------------- |
  | size   | number | 是   | 要读取的数据的大小。                               |
  | offset | number | 是   | 要读取的数据在此Ashmem对象关联的内存区间的起始位置 |

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | number[] | 返回读取的数据。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.rpc错误码](../errorcodes/errorcode-rpc.md)

  | 错误码ID  | 错误信息 |
  | -------- | -------- |
  | 1900004 | read from ashmem failed |

**示例：**

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

>从API version 9 开始不再维护，建议使用[readAshmem](#readashmem9)类替代。

readFromAshmem(size: number, offset: number): number[]

**描述**：

从此Ashmem对象关联的共享文件中读取数据。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**

  | 参数名 | 类型   | 必填 | 说明                                               |
  | ------ | ------ | ---- | -------------------------------------------------- |
  | size   | number | 是   | 要读取的数据的大小。                               |
  | offset | number | 是   | 要读取的数据在此Ashmem对象关联的内存区间的起始位置 |

**返回值：**

  | 类型     | 说明             |
  | -------- | ---------------- |
  | number[] | 返回读取的数据。 |

**示例：**

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