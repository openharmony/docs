# RPC通信


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```
import rpc from '@ohos.rpc';
```


## MessageParcel

该类提供读写基础类型及数组、IPC对象、接口描述符和自定义序列化对象的方法。


### create

create(): MessageParcel

静态方法，创建MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | MessageParcel | 返回创建的MessageParcel对象。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  console.log("RpcClient: data is " + data);
  ```


### reclaim

reclaim(): void

释放不再使用的MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  let reply = rpc.MessageParcel.create();
  reply.reclaim();
  ```


### writeRemoteObject

writeRemoteObject(object: [IRemoteObject](#iremoteobject)): boolean

  序列化远程对象并将其写入MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | object | [IRemoteObject](#iremoteobject) | 是 | 要序列化并写入MessageParcel的远程对象。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果操作成功，则返回true；否则返回false。 |

**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
      }
  }
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

从MessageParcel读取远程对象。此方法用于反序列化MessageParcel对象以生成IRemoteObject。远程对象按写入MessageParcel的顺序读取。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | [IRemoteObject](#iremoteobject) | 读取到的远程对象。 |

**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
      }
  }
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

将接口描述符写入MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | token | string | 是 | 字符串类型描述符。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果操作成功，则返回true；否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInterfaceToken("aaa");
  console.log("RpcServer: writeInterfaceToken is " + result);
  ```


### readInterfaceToken

readInterfaceToken(): string

从MessageParcel中读取接口描述符。接口描述符按写入MessageParcel的顺序读取。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | string | 返回读取到的接口描述符。 |

**示例：**

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

获取当前MessageParcel的数据大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 获取的MessageParcel的数据大小。以字节为单位。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let size = data.getSize();
  console.log("RpcClient: size is " + size);
  ```


### getCapacity

getCapacity(): number

获取当前MessageParcel的容量。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 获取的MessageParcel的容量大小。以字节为单位。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.getCapacity();
  console.log("RpcClient: capacity is " + result);
  ```


### setSize

setSize(size: number): boolean

设置MessageParcel实例中包含的数据大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | size | number | 是 | MessageParcel实例的数据大小。以字节为单位。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 设置成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let setSize = data.setSize(16);
  console.log("RpcClient: setSize is " + setSize);
  ```


### setCapacity

setCapacity(size: number): boolean

设置MessageParcel实例的存储容量。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | size | number | 是 | MessageParcel实例的存储容量。以字节为单位。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 设置成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.setCapacity(100);
  console.log("RpcClient: setCapacity is " + result);
  ```


### getWritableBytes

getWritableBytes(): number

获取MessageParcel的可写字节空间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 获取到的MessageParcel的可写字节空间。以字节为单位。 |

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

获取MessageParcel的可读字节空间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

获取MessageParcel的读位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回MessageParcel实例中的当前读取位置。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let readPos = data.getReadPosition();
  console.log("RpcClient: readPos is " + readPos);
  ```


### getWritePosition

getWritePosition(): number

获取MessageParcel的写位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

重新偏移读取位置到指定的位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | pos | number | 是 | 开始读取数据的目标位置。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果读取位置发生更改，则返回true；否则返回false。 |

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

重新偏移写位置到指定的位置。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | pos | number | 是 | 开始写入数据的目标位置。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果写入位置更改，则返回true；否则返回false。 |

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

将字节值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | val | number | 是 | 要写入的字节值。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入返回成功，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeByte(2);
  console.log("RpcClient: writeByte is: " + result);
  ```


### readByte

readByte(): number

从MessageParcel实例读取字节值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将短整数值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | val | number | 是 | 要写入的短整数值。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShort(8);
  console.log("RpcClient: writeShort is: " + result);
  ```


### readShort

readShort(): number

从MessageParcel实例读取短整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将整数值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | val | number | 是 | 要写入的整数值。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入返回成功，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeInt(10);
  console.log("RpcClient: writeInt is " + result);
  ```


### readInt

readInt(): number

从MessageParcel实例读取整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将长整数值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | val | number | 是 | 要写入的长整数值 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLong(10000);
  console.log("RpcClient: writeLong is " + result);
  ```


### readLong

readLong(): number

从MessageParcel实例中读取长整数值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将浮点值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | val | number | 是 | 要写入的浮点值。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloat(1.2);
  console.log("RpcClient: writeFloat is " + result);
  ```


### readFloat

readFloat(): number

从MessageParcel实例中读取浮点值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将双精度浮点值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | val | number | 是 | 要写入的双精度浮点值。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDouble(10.2);
  console.log("RpcClient: writeDouble is " + result);
  ```


### readDouble

readDouble(): number

从MessageParcel实例读取双精度浮点值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将布尔值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | val | boolean | 是 | 要写入的布尔值。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBoolean(false);
  console.log("RpcClient: writeBoolean is " + result);
  ```


### readBoolean

readBoolean(): boolean

从MessageParcel实例读取布尔值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将单个字符值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | val | number | 是 | 要写入的单个字符值。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeChar(97);
  console.log("RpcClient: writeChar is " + result);
  ```


### readChar

readChar(): number

从MessageParcel实例中读取单个字符值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将字符串值写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | val | string | 是 | 要写入的字符串值。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeString('abc');
  console.log("RpcClient: writeString  is " + result);
  ```


### readString

readString(): string

从MessageParcel实例读取字符串值。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将自定义序列化对象写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | val | [Sequenceable](#sequenceable) | 是 | 要写入的可序列对象。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

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

readSequenceable(dataIn: Sequenceable) : boolean

从MessageParcel实例中读取成员变量到指定的对象（dataIn）。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | [Sequenceable](#sequenceable) | 是 | 需要从MessageParcel读取成员变量的对象。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果反序列成功，则返回true；否则返回false。 |

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

将字节数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | byteArray | number[] | 是 | 要写入的字节数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let ByteArrayVar = [1, 2, 3, 4, 5];
  let result = data.writeByteArray(ByteArrayVar);
  console.log("RpcClient: writeByteArray is " + result);
  ```


### readByteArray

readByteArray(dataIn: number[]) : void

从MessageParcel实例读取字节数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | 是 | 要读取的字节数组。 |

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

从MessageParcel实例中读取字节数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将短整数数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | shortArray | number[] | 是 | 要写入的短整数数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeShortArray([11, 12, 13]);
  console.log("RpcClient: writeShortArray is " + result);
  ```


### readShortArray

readShortArray(dataIn: number[]) : void

从MessageParcel实例中读取短整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | 是 | 要读取的短整数数组。 |

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

从MessageParcel实例中读取短整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将整数数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | intArray | number[] | 是 | 要写入的整数数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeIntArray([100, 111, 112]);
  console.log("RpcClient: writeIntArray is " + result);
  ```


### readIntArray

readIntArray(dataIn: number[]) : void

从MessageParcel实例中读取整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | 是 | 要读取的整数数组。 |

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
    | 类型 | 说明 |
  | -------- | -------- |
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

将长整数数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | longArray | number[] | 是 | 要写入的长整数数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeLongArray([1111, 1112, 1113]);
  console.log("RpcClient: writeLongArray is " + result);
  ```


### readLongArray

readLongArray(dataIn: number[]) : void

从MessageParcel实例读取长整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | 是 | 要读取的长整数数组。 |

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

从MessageParcel实例中读取长整数数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将浮点数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | floatArray | number[] | 是 | 要写入的浮点数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeFloatArray([1.2, 1.3, 1.4]);
  console.log("RpcClient: writeFloatArray is " + result);
  ```


### readFloatArray

readFloatArray(dataIn: number[]) : void

从MessageParcel实例中读取浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | 是 | 要读取的浮点数组。 |


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

从MessageParcel实例中读取浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将双精度浮点数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | doubleArray | number[] | 是 | 要写入的双精度浮点数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);
  console.log("RpcClient: writeDoubleArray is " + result);
  ```


### readDoubleArray

readDoubleArray(dataIn: number[]) : void

从MessageParcel实例中读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | 是 | 要读取的双精度浮点数组。 |

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

从MessageParcel实例读取双精度浮点数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将布尔数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | booleanArray | boolean[] | 是 | 要写入的布尔数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  ```


### readBooleanArray

readBooleanArray(dataIn: boolean[]) : void

从MessageParcel实例中读取布尔数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | boolean[] | 是 | 要读取的布尔数组。 |

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

从MessageParcel实例中读取布尔数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean[] | 返回布尔数组。 |


  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeBooleanArray([false, true, false]);
  console.log("RpcClient: writeBooleanArray is " + result);
  let array = data.readBooleanArray();
  console.log("RpcClient: readBooleanArray is " + array);
  ```


### writeCharArray

writeCharArray(charArray: number[]): boolean

将单个字符数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | charArray | number[] | 是 | 要写入的单个字符数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray([97, 98, 88]);
  console.log("RpcClient: writeCharArray is " + result);
  ```


### readCharArray

readCharArray(dataIn: number[]) : void

从MessageParcel实例中读取单个字符数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | number[] | 是 | 要读取的单个字符数组。 |

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

从MessageParcel实例读取单个字符数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number[] | 返回单个字符数组。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeCharArray(['a', 'b', 'c']);
  console.log("RpcClient: writeCharArray is " + result);
  let array = data.readCharArray();
  console.log("RpcClient: readCharArray is " + array);
  ```


### writeStringArray

writeStringArray(stringArray: string[]): boolean

将字符串数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | stringArray | string[] | 是 | 要写入的字符串数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

**示例：**

  ```
  let data = rpc.MessageParcel.create();
  let result = data.writeStringArray(["abc", "def"]);
  console.log("RpcClient: writeStringArray is " + result);
  ```


### readStringArray

readStringArray(dataIn: string[]) : void

从MessageParcel实例读取字符串数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | string[] | 是 | 要读取的字符串数组。 |

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

从MessageParcel实例读取字符串数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

向MessageParcel写入“指示未发生异常”的信息。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

将可序列化对象数组写入MessageParcel实例。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | sequenceableArray | Sequenceable[] | 是 | 要写入的可序列化对象数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 写入成功返回true，否则返回false。 |

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

从MessageParcel实例读取可序列化对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | sequenceableArray | Sequenceable[] | 是 | 要读取的可序列化对象数组。 |

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

将IRemoteObject对象数组写入MessageParcel。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | objectArray | IRemoteObject[] | 是 | 要写入MessageParcel的IRemoteObject对象数组。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果IRemoteObject对象数组成功写入MessageParcel，则返回true；如果对象为null或数组写入MessageParcel失败，则返回false。 |

**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

从MessageParcel读取IRemoteObject对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | objects | IRemoteObject[] | 是 | 从MessageParcel读取的IRemoteObject对象数组。 |

**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

从MessageParcel读取IRemoteObject对象数组。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | IRemoteObject[] | 返回IRemoteObject对象数组。 |

**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

关闭给定的文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 要关闭的文件描述符。 |

**示例：**

  ```
  import fileio from '@ohos.fileio';
  let filePath = "path/to/file";
  let fd = fileio.openSync(filePath, 0o2| 0o100, 0o666);
  rpc.MessageParcel.closeFileDescriptor(fd);
  ```


### dupFileDescriptor<sup>8+</sup>

static dupFileDescriptor(fd: number) :number

复制给定的文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 表示已存在的文件描述符。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

检查此MessageParcel对象是否包含文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果此MessageParcel对象包含文件描述符，则返回true；否则返回false。 |

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

写入文件描述符到MessageParcel。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fd | number | 是 | 文件描述符。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果操作成功，则返回true；否则返回false。 |

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

从MessageParcel中读取文件描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

将指定的匿名共享对象写入此MessageParcel。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ashmem | Ashmem | 是 | 要写入MessageParcel的匿名共享对象。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果匿名共享对象成功写入此MessageParcel，则返回true；否则返回false。 |

**示例：**

  ```
  let parcel = new rpc.MessageParcel();
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);
  let isWriteSuccess = parcel.writeAshmem(ashmem);
  console.log("RpcTest: write ashmem to result is : " + isWriteSuccess);
  ```


### readAshmem<sup>8+</sup>

readAshmem(): Ashmem

从MessageParcel读取匿名共享对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

获取MessageParcel可以容纳的最大原始数据量。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回MessageParcel可以容纳的最大原始数据量，即128&nbsp;Mb。 |

**示例：**

  ```
  let parcel = new rpc.MessageParcel();
  let result = parcel.getRawDataCapacity();
  console.log("RpcTest: parcel get RawDataCapacity result is : " + result);
  ```


### writeRawData<sup>8+</sup>

writeRawData(rawData: number[], size: number): boolean

将原始数据写入MessageParcel对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | rawData | number[] | 是 | 要写入的原始数据。 |
  | size | number | 是 | 发送的原始数据大小，以字节为单位。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果操作成功，则返回true；否则返回false。 |

**示例：**

  ```
  let parcel = new rpc.MessageParcel();
  let arr = [1, 2, 3, 4, 5];
  let isWriteSuccess = parcel.writeRawData(arr, arr.length);
  console.log("RpcTest: parcel write raw data result is : " + isWriteSuccess);
  ```


### readRawData<sup>8+</sup>

readRawData(size: number): number[]

从MessageParcel读取原始数据。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | size | number | 是 | 要读取的原始数据的大小。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

## Sequenceable

在进程间通信（IPC）期间，将类的对象写入MessageParcel并从MessageParcel中恢复它们。


### marshalling

marshalling(dataOut: MessageParcel): boolean

将此可序列对象封送到MessageParcel中。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataOut | [MessageParcel](#messageparcel) | 是 | 可序列对象将被封送到的MessageParcel对象。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果封送成功，则返回true；否则返回false。 |

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

unmarshalling(dataIn: MessageParcel) : boolean

从MessageParcel中解封此可序列对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | dataIn | [MessageParcel](#messageparcel) | 是 | 已将可序列对象封送到其中的MessageParcel对象。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果可序列化成功，则返回true；否则返回false。 |

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

需派生类实现，获取代理或远端对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | [IRemoteObject](#iremoteobject) | 如果调用者是[RemoteObject](#ashmem8)对象，则直接返回本身；如果调用者是[RemoteProxy](#remoteproxy)对象，则返回它的持有者[IRemoteObject](#iremoteobject)。 |

**示例：**

  ```
  class TestAbility extends rpc.RemoteObject {
      asObject() {
          return this;
      }
  }
  ```

**示例：**

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

用于订阅远端对象的死亡通知。当被订阅该通知的远端对象死亡时，本端可收到消息，调用[onRemoteDied](#onremotedied)接口。远端对象死亡可以为远端对象所在进程死亡，远端对象所在设备关机或重启，当远端对象与本端对象属于不同设备时，也可为远端对象离开组网时。


### onRemoteDied

onRemoteDied(): void

在成功添加死亡通知订阅后，当远端对象死亡时，将自动调用本方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
      }
  }
  ```


## SendRequestResult<sup>8+</sup>

发送请求的响应结果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

  | 参数 | 值 | 说明 |
| -------- | -------- | -------- |
| errCode | number | 错误码。 |
| code | number | 消息代码。 |
| data | MessageParcel | 发送给对端进程的MessageParcel对象。 |
| reply | MessageParcel | 对端进程返回的MessageParcel对象。 |


## IRemoteObject

该接口可用于查询或获取接口描述符、添加或删除死亡通知、转储对象状态到特定文件、发送消息。


### queryLocalInterface

queryLocalInterface(descriptor: string): IRemoteBroker

查询接口。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | descriptor | string | 是 | 接口描述符的字符串。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | IRemoteBroker | 返回绑定到指定接口描述符的IRemoteBroker对象。 |


### sendRequest<sup>(deprecated)</sup>

> **说明：**
> 从 API Version 8 开始废弃，建议使用[sendRequest<sup>8+</sup>](#sendrequest8)替代。

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): boolean

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data | [MessageParcel](#messageparcel) | 是 | 保存待发送数据的&nbsp;MessageParcel对象。 |
  | reply | [MessageParcel](#messageparcel) | 是 | 接收应答数据的MessageParcel对象。 |
  | options | [MessageOption](#messageoption) | 是 | 本次请求的同异步模式，默认同步调用。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 返回一个布尔值，true表示成功，false表示失败。|


### sendRequest<sup>8+</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data | [MessageParcel](#messageparcel) | 是 | 保存待发送数据的&nbsp;MessageParcel对象。 |
  | reply | [MessageParcel](#messageparcel) | 是 | 接收应答数据的MessageParcel对象。 |
  | options | [MessageOption](#messageoption) | 是 | 本次请求的同异步模式，默认同步调用。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;SendRequestResult&gt; | 返回一个期约，兑现值是sendRequestResult实例。|

### sendRequest<sup>8+</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data | [MessageParcel](#messageparcel) | 是 | 保存待发送数据的&nbsp;MessageParcel对象。 |
  | reply | [MessageParcel](#messageparcel) | 是 | 接收应答数据的MessageParcel对象。 |
  | options | [MessageOption](#messageoption) | 是 | 本次请求的同异步模式，默认同步调用。 |
  | callback | AsyncCallback&lt;SendRequestResult&gt; | 是 | 接收发送结果的回调。 |


### addDeathrecipient

addDeathRecipient(recipient: DeathRecipient, flags: number): boolean

注册用于接收远程对象死亡通知的回调。如果与RemoteProxy对象匹配的远程对象进程死亡，则调用此方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是 | 要注册的回调。 |
  | flags | number | 是 | 死亡通知标志。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果回调注册成功，则返回true；否则返回false。 |


### removeDeathRecipient

removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean

注销用于接收远程对象死亡通知的回调。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是 | 要注销的回调。 |
  | flags | number | 是 | 死亡通知标志。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果回调成功注销，则返回true；否则返回false。 |


### getInterfaceDescriptor

getInterfaceDescriptor(): string

获取对象的接口描述符。接口描述符为字符串。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | string | 返回接口描述符。 |


### isObjectDead

isObjectDead(): boolean

检查当前对象是否死亡。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果对象已死亡，则返回true；否则返回false。 |


## RemoteProxy

实现IRemoteObject代理对象。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

| 参数                  | 值                      | 说明                              |
| --------------------- | ----------------------- | --------------------------------- |
| PING_TRANSACTION      | 1599098439 (0x5f504e47) | 内部指令码，用于测试IPC服务正常。 |
| DUMP_TRANSACTION      | 1598311760 (0x5f444d50) | 内部指令码，获取Binder内部状态。 |
| INTERFACE_TRANSACTION | 1598968902 (0x5f4e5446) | 内部指令码，获取对端接口描述符。  |
| MIN_TRANSACTION_ID    | 1 (0x00000001)          | 最小有效指令码。                  |
| MAX_TRANSACTION_ID    | 16777215 (0x00FFFFFF)   | 最大有效指令码。                  |




### sendRequest<sup>(deprecated)</sup>

> **说明：**
> 从 API Version 8 开始废弃，建议使用[sendRequest<sup>8+</sup>](#sendrequest8-2)替代。

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): boolean

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data | [MessageParcel](#messageparcel) | 是 | 保存待发送数据的&nbsp;MessageParcel对象。 |
  | reply | [MessageParcel](#messageparcel) | 是 | 接收应答数据的MessageParcel对象。 |
  | options | [MessageOption](#messageoption) | 是 | 本次请求的同异步模式，默认同步调用。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 返回一个布尔值，true表示成功，false表示失败。|


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

### sendRequest<sup>8+</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data | [MessageParcel](#messageparcel) | 是 | 保存待发送数据的&nbsp;MessageParcel对象。 |
  | reply | [MessageParcel](#messageparcel) | 是 | 接收应答数据的MessageParcel对象。 |
  | options | [MessageOption](#messageoption) | 是 | 本次请求的同异步模式，默认同步调用。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;SendRequestResult&gt; | 返回一个期约，兑现值是sendRequestResult实例。|

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


### sendRequest<sup>8+</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data | [MessageParcel](#messageparcel) | 是 | 保存待发送数据的&nbsp;MessageParcel对象。 |
  | reply | [MessageParcel](#messageparcel) | 是 | 接收应答数据的MessageParcel对象。 |
  | options | [MessageOption](#messageoption) | 是 | 本次请求的同异步模式，默认同步调用。 |
  | callback | AsyncCallback&lt;SendRequestResult&gt; | 是 | 接收发送结果的回调。 |

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


### queryLocalInterface

queryLocalInterface(interface: string): IRemoteBroker

查询并获取当前接口描述符对应的本地接口对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | interface | string | 是 | 需要查询的接口描述符。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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


### addDeathRecippient

addDeathRecipient(recipient : DeathRecipient, flags : number): boolean

注册用于接收远程对象死亡通知的回调，增加proxy对象上的死亡通知。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是 | 收件人表示要注册的回调。 |
  | flags | number | 是 | 死亡通知标志。保留参数。设置为0。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果回调注册成功，则返回true；否则返回false。 |

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
          console.log("server is died");
      }
  }
  let deathRecipient = new MyDeathRecipient();
  proxy.addDeathRecippient(deathRecipient, 0);
  ```


### removeDeathRecipient

removeDeathRecipient(recipient : DeathRecipient, flags : number): boolean

注销用于接收远程对象死亡通知的回调。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | recipient | [DeathRecipient](#deathrecipient) | 是 | 要注销的死亡回调。 |
  | flags | number | 是 | 死亡通知标志。保留参数。设置为0。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果回调成功注销，则返回true；否则返回false。 |

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
          console.log("server is died");
      }
  }
  let deathRecipient = new MyDeathRecipient();
  proxy.addDeathRecippient(deathRecipient, 0);
  proxy.removeDeathRecipient(deathRecipient, 0);
  ```


### getInterfaceDescriptor

getInterfaceDescriptor(): string

查询当前代理对象接口的描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

指示对应的RemoteObject是否死亡。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果对应的RemoteObject已经死亡，返回true，否则返回false。 |

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

  | 参数 | 值 | 说明 |
| -------- | -------- | -------- |
| TF_SYNC | 0 | 同步调用。 |
| TF_ASYNC | 1 | 异步调用。 |
| TF_ACCEPT_FDS | 0x10 | 指示[sendRequest](#sendrequest8)接口可以返回文件描述符。 |
| TF_WAIT_TIME | 8 | 等待时间。单位秒。 |


### constructor

constructor(syncFlags?: number, waitTime = TF_WAIT_TIME)

MessageOption构造函数。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | syncFlags | number | 否 | 同步调用或异步调用标志。默认同步调用。 |
  | waitTime | number | 否 | 调用rpc最长等待时间。默认&nbsp;TF_WAIT_TIME。 |


### getFlags

getFlags(): number

获取同步调用或异步调用标志。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 调用成功返回同步调用或异步调用标志。 |


### setFlags

setFlags(flags: number): void

设置同步调用或异步调用标志。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | flags | number | 是 | 同步调用或异步调用标志。 |


### getWaitTime

getWaitTime(): number

获取rpc调用的最长等待时间。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | rpc最长等待时间。 |


### setWaitTime

setWaitTime(waitTime: number): void

设置rpc调用最长等待时间。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | waitTime | number | 是 | rpc调用最长等待时间。 |


## IPCSkeleton

用于获取IPC上下文信息，包括获取UID和PID、获取本端和对端设备ID、检查接口调用是否在同一设备上。


### getContextObject

static getContextObject(): IRemoteObject

获取系统能力的管理者。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | [IRemoteObject](#iremoteobject) | 返回系统能力管理者。 |

**示例：**

  ```
  let samgr = rpc.IPCSkeleton.getContextObject();
  console.log("RpcServer: getContextObject result: " + samgr);
  ```


### getCallingPid

static getCallingPid(): number

获取调用者的PID。此方法由RemoteObject对象在onRemoteRequest方法中调用，不在IPC上下文环境（onRemoteRequest）中调用则返回本进程的PID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回调用者的PID。 |

**示例：**

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

获取调用者的UID。此方法由RemoteObject对象在onRemoteRequest方法中调用，不在IPC上下文环境（onRemoteRequest）中调用则返回本进程的UID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回调用者的UID。 |

**示例：**

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

获取调用者的TokenId，用于被调用方对调用方的身份校验。

**系统能力**：SystemCapability.Communication.IPC.Core

* 返回值

    | 类型   | 说明                  |
  | ------ | --------------------- |
  | number | 返回调用者的TokenId。 |

* 示例

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

获取调用者进程所在的设备ID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | string | 返回调用者进程所在的设备ID。 |

**示例：**

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

获取本端设备ID。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | string | 返回本地设备的ID。 |

**示例：**

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

检查当前通信对端是否是本设备的进程。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果调用是在同一设备上进行的，则返回true，否则返回false。 |

**示例：**

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

将所有挂起的命令从指定的RemoteProxy刷新到相应的RemoteObject。建议在执行任何时间敏感操作之前调用此方法。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | object | [IRemoteObject](#iremoteobject) | 是 | 指定的RemoteProxy。 |


**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 如果操作成功，返回0；如果输入对象为空或RemoteObject，或者操作失败，返回错误代码。 |

**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

将远程用户的UID和PID替换为本地用户的UID和PID。它可以用于身份验证等场景。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | string | 返回包含远程用户的UID和PID的字符串。 |

**示例：**

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

将UID和PID恢复为远程用户的UID和PID。它通常在使用resetCallingIdentity后调用，需要resetCallingIdentity返回的远程用户的UID和PID。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | identity | string | 是 | 标识表示包含远程用户UID和PID的字符串。由resetCallingIdentity返回。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果操作成功，则返回true；否则返回false。 |

**示例：**

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

实现远程对象。服务提供者必须继承此类。


### constructor

constructor(descriptor: string)

RemoteObject构造函数。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | descriptor | string | 是 | 接口描述符。 |


### sendRequest<sup>(deprecated)</sup>

> **说明：**
> 从 API Version 8 开始废弃，建议使用[sendRequest<sup>8+</sup>](#sendrequest8-4)替代。

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): boolean

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data | [MessageParcel](#messageparcel) | 是 | 保存待发送数据的&nbsp;MessageParcel对象。 |
  | reply | [MessageParcel](#messageparcel) | 是 | 接收应答数据的MessageParcel对象。 |
  | options | [MessageOption](#messageoption) | 是 | 本次请求的同异步模式，默认同步调用。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 返回一个布尔值，true表示成功，false表示失败。|


**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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


### sendRequest<sup>8+</sup>

sendRequest(code : number, data : MessageParcel, reply : MessageParcel, options : MessageOption): Promise&lt;SendRequestResult&gt;

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data | [MessageParcel](#messageparcel) | 是 | 保存待发送数据的&nbsp;MessageParcel对象。 |
  | reply | [MessageParcel](#messageparcel) | 是 | 接收应答数据的MessageParcel对象。 |
  | options | [MessageOption](#messageoption) | 是 | 本次请求的同异步模式，默认同步调用。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;SendRequestResult&gt; | 返回一个期约，兑现值是sendRequestResult实例。|


**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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


### sendRequest<sup>8+</sup>

sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback&lt;SendRequestResult&gt;): void

以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 本次请求调用的消息码，由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |
  | data | [MessageParcel](#messageparcel) | 是 | 保存待发送数据的&nbsp;MessageParcel对象。 |
  | reply | [MessageParcel](#messageparcel) | 是 | 接收应答数据的MessageParcel对象。 |
  | options | [MessageOption](#messageoption) | 是 | 本次请求的同异步模式，默认同步调用。 |
  | AsyncCallback | AsyncCallback&lt;SendRequestResult&gt; | 是 | 接收发送结果的回调。 |


**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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


### onRemoteRequest

onRemoteRequest(code : number, data : MessageParcel, reply: MessageParcel, options : MessageOption): boolean

sendRequest请求的响应处理函数，服务端在该函数里处理请求，回复结果。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | code | number | 是 | 对端发送的服务请求码。 |
  | data | [MessageParcel](#messageparcel) | 是 | 携带客户端调用参数的MessageParcel对象。 |
  | reply | [MessageParcel](#messageparcel) | 是 | 写入结果的MessageParcel对象。 |
  | option | [MessageOption](#messageoption) | 是 | 指示操作是同步还是异步。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果操作成功，则返回true；否则返回false。 |


**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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


### getCallingUid

getCallingUid(): number

获取通信对端的进程Uid。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回通信对端的进程Uid。 |


**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

获取通信对端的进程Pid。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回通信对端的进程Pid。 |


**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

查询并获取当前接口描述符对应的远端对象是否已经存在。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | descriptor | string | 是 | 需要查询的接口描述符。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | IRemoteBroker | 如果接口描述符对应的远端对象存在，则返回该远端对象，否则返回Null。 |


**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

查询接口描述符。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | string | 返回接口描述符。 |


**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

此接口用于把接口描述符和IRemoteBroker对象绑定。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | localInterface | IRemoteBroker | 是 | 将与描述符绑定的IRemoteBroker对象。 |
  | descriptor | string | 是 | 用于与IRemoteBroker对象绑定的描述符。 |


**示例：**

  ```
  class MyDeathRecipient {
      onRemoteDied() {
          console.log("server is died");
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

映射内存保护类型：

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.IPC.Core。

  | 参数名 | 值 | 说明 |
| -------- | -------- | -------- |
| PROT_EXEC | 4 | 映射的内存可执行 |
| PROT_NONE | 0 | 映射的内存不可访问 |
| PROT_READ | 1 | 映射的内存可读 |
| PROT_WRITE | 2 | 映射的内存可写 |


### createAshmem<sup>8+</sup>

static createAshmem(name: string, size: number): Ashmem

根据指定的名称和大小创建Ashmem对象。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | name | string | 是 | 名称，用于查询Ashmem信息。 |
  | size | number | 是 | Ashmem的大小，以字节为单位。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | Ashmem | 返回创建的Ashmem对象；如果创建失败，返回null。 |


**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashemm by createAshmem : " + ashmem + " size is : " + size);
  ```


### createAshmemFromExisting<sup>8+</sup>

static createAshmemFromExisting(ashmem: Ashmem): Ashmem

通过复制现有Ashmem对象的文件描述符(fd)来创建Ashmem对象。两个Ashmem对象指向同一个共享内存区域。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | ashmem | Ashmem | 是 | 已存在的Ashmem对象。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
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

关闭这个Ashmem。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  ashmem.closeAshmem();
  ```


### unmapAshmem<sup>8+</sup>

unmapAshmem(): void

删除该Ashmem对象的地址映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  ashmem.unmapAshmem();
  ```


### getAshmemSize<sup>8+</sup>

getAshmemSize(): number

获取Ashmem对象的内存大小。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回Ashmem对象的内存大小。 |

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let size = ashmem.getAshmemSize();
  console.log("RpcTest: get ashmem is " + ashmem + " size is : " + size);
  ```


### mapAshmem<sup>8+</sup>

mapAshmem(mapType: number): boolean

在此进程的虚拟地址空间上创建共享文件映射，映射区域大小由此Ashmem对象指定。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | mapType | number | 是 | 指定映射的内存区域的保护等级。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果映射成功，则返回true；否则返回false。 |

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapReadAndWrite = ashmem.mapAshmem(ashmem.PROT_READ | ashmem.PROT_WRITE);
  console.log("RpcTest: map ashmem result is  : " + mapReadAndWrite);
  ```


### mapReadAndWriteAshmem<sup>8+</sup>

mapReadAndWriteAshmem(): boolean

在此进程虚拟地址空间上创建可读写的共享文件映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果映射成功，则返回true；否则返回false。 |

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadAndWriteAshmem();
  console.log("RpcTest: map ashmem result is  : " + mapResult);
  ```


### mapReadOnlyAshmem<sup>8+</sup>

mapReadOnlyAshmem(): boolean

在此进程虚拟地址空间上创建只读的共享文件映射。

**系统能力**：SystemCapability.Communication.IPC.Core

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果映射成功，则返回true；否则返回false。 |

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let mapResult = ashmem.mapReadOnlyAshmem();
  console.log("RpcTest: Ashmem mapReadOnlyAshmem result is : " + mapResult);
  ```


### setProtection<sup>8+</sup>

setProtection(protectionType: number): boolean

设置映射内存区域的保护等级。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | protectionType | number | 是 | 要设置的保护类型。 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果设置成功，则返回true；否则返回false。 |

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  let result = ashmem.setProtection(ashmem.PROT_READ);
  console.log("RpcTest: Ashmem setProtection result is : " + result);
  ```


### writeToAshmem<sup>8+</sup>

writeToAshmem(buf: number[], size: number, offset: number): boolean

将数据写入此Ashmem对象关联的共享文件。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | buf | number[] | 是 | 写入Ashmem对象的数据。 |
  | size | number | 是 | 要写入的数据大小。 |
  | offset | number | 是 | 要写入的数据在此Ashmem对象关联的内存区间的起始位置 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 如果数据写入成功，则返回true；在其他情况下，如数据写入越界或未获得写入权限，则返回false。 |

**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  var ByteArrayVar = [1, 2, 3, 4, 5];
  let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);
  console.log("RpcTest: write to Ashmem result is  : " + writeResult);
  ```


### readFromAshmem<sup>8+</sup>

readFromAshmem(size: number, offset: number): number[]

从此Ashmem对象关联的共享文件中读取数据。

**系统能力**：SystemCapability.Communication.IPC.Core

**参数：**
    | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | size | number | 是 | 要读取的数据的大小。 |
  | offset | number | 是 | 要读取的数据在此Ashmem对象关联的内存区间的起始位置 |

**返回值：**
    | 类型 | 说明 |
  | -------- | -------- |
  | number[] | 返回读取的数据。 |


**示例：**

  ```
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);
  var ByteArrayVar = [1, 2, 3, 4, 5];
  let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);
  console.log("RpcTest: write to Ashmem result is  : " + writeResult);
  let readResult = ashmem.readFromAshmem(5, 0);
  console.log("RpcTest: read to Ashmem result is  : " + readResult);
  ```
