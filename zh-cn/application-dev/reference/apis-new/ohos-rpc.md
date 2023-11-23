# @ohos.rpc    
本模块提供进程间通信能力，包括设备内的进程间通信（IPC）和设备间的进程间通信（RPC），前者基于Binder驱动，后者基于软总线驱动。  
> **说明**   
>本模块首批接口从API version -1开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import rpc from '@ohos.rpc'    
```  
    
## ErrorCode<sup>(9+)</sup>    
从API version 9起，IPC支持异常返回功能。错误码对应数值及含义如下。    
    
 **系统能力:**  SystemCapability.Communication.IPC.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CHECK_PARAM_ERROR | 401 | 检查参数失败。 |  
| OS_MMAP_ERROR | 1900001 | 执行系统调用mmap失败。 |  
| OS_IOCTL_ERROR | 1900002 | 在共享内存文件描述符上执行系统调用ioctl失败。 |  
| WRITE_TO_ASHMEM_ERROR | 1900003 | 向共享内存写数据失败。 |  
| READ_FROM_ASHMEM_ERROR | 1900004 | 从共享内存读数据失败。 |  
| ONLY_PROXY_OBJECT_PERMITTED_ERROR | 1900005 | 只有proxy对象允许该操作。 |  
| ONLY_REMOTE_OBJECT_PERMITTED_ERROR | 1900006 | 只有remote对象允许该操作。 |  
| COMMUNICATION_ERROR | 1900007 | 和远端对象进行进程间通信失败。 |  
| PROXY_OR_REMOTE_OBJECT_INVALID_ERROR | 1900008 | 非法的代理对象或者远端对象。 |  
| WRITE_DATA_TO_MESSAGE_SEQUENCE_ERROR | 1900009 | 向MessageSequence写数据失败。 |  
| READ_DATA_FROM_MESSAGE_SEQUENCE_ERROR | 1900010 | 读取MessageSequence数据失败。 |  
| PARCEL_MEMORY_ALLOC_ERROR | 1900011 | 序列化过程中内存分配失败。 |  
| CALL_JS_METHOD_ERROR | 1900012 | 执行JS回调方法失败。 |  
| OS_DUP_ERROR | 1900013 | 执行系统调用dup失败。 |  
    
## MessageParcel<sup>(deprecated)</sup>    
从API version 9 开始不再维护，建议使用[MessageSequence](#messagesequence9)类替代。在RPC过程中，发送方可以使用MessageParcel提供的写方法，将待发送的数据以特定格式写入该对象。接收方可以使用MessageParcel提供的读方法从该对象中读取特定格式的数据。数据格式包括：基础类型及数组、IPC对象、接口描述符和自定义序列化对象。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.rpc.MessageSequence替代。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### create<sup>(deprecated)</sup>    
静态方法，创建MessageParcel对象。  
 **调用形式：**     
- static create(): MessageParcel  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MessageParcel | 返回创建的MessageParcel对象。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  hilog.info(0x0000, 'testTag', 'RpcClient: data is ' + data);    
```    
  
    
### reclaim<sup>(deprecated)</sup>    
释放不再使用的MessageParcel对象。  
 **调用形式：**     
- reclaim(): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **示例代码：**   
```ts    
 let reply = rpc.MessageParcel.create();  reply.reclaim();    
```    
  
    
### writeRemoteObject<sup>(deprecated)</sup>    
序列化远程对象并将其写入MessageParcel对象。  
 **调用形式：**     
- writeRemoteObject(object: IRemoteObject): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| object<sup>(deprecated)</sup> | IRemoteObject | true | 要序列化并写入MessageParcel的远程对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：操作成功，false：操作失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### readRemoteObject<sup>(deprecated)</sup>    
从MessageParcel读取远程对象。此方法用于反序列化MessageParcel对象以生成IRemoteObject。远程对象按写入MessageParcel的顺序读取。  
 **调用形式：**     
- readRemoteObject(): IRemoteObject  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteObject | 读取到的远程对象。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### writeInterfaceToken<sup>(deprecated)</sup>    
将接口描述符写入MessageParcel对象，远端对象可使用该信息校验本次通信。  
 **调用形式：**     
- writeInterfaceToken(token: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token<sup>(deprecated)</sup> | string | true | 字符串类型描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：操作成功，false：操作失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeInterfaceToken("aaa");  hilog.info(0x0000, 'testTag', 'RpcServer: writeInterfaceToken is ' + result);    
```    
  
    
### readInterfaceToken<sup>(deprecated)</sup>    
从MessageParcel中读取接口描述符，接口描述符按写入MessageParcel的顺序读取，本地对象可使用该信息检验本次通。  
 **调用形式：**     
- readInterfaceToken(): string  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回读取到的接口描述符。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {  
      let interfaceToken = data.readInterfaceToken();  
      hilog.info(0x0000, 'testTag', 'RpcServer: interfaceToken is ' + interfaceToken);  
      return true;  
    }  
  }  
    
```    
  
    
### getSize<sup>(deprecated)</sup>    
获取当前MessageParcel的数据大小。  
 **调用形式：**     
- getSize(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取的MessageParcel的数据大小。以字节为单位。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let size = data.getSize();  hilog.info(0x0000, 'testTag', 'RpcClient: size is ' + size);    
```    
  
    
### getCapacity<sup>(deprecated)</sup>    
获取当前MessageParcel的容量。  
 **调用形式：**     
- getCapacity(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取的MessageParcel的容量大小。以字节为单位。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.getCapacity();  hilog.info(0x0000, 'testTag', 'RpcClient: capacity is ' + result);    
```    
  
    
### setSize<sup>(deprecated)</sup>    
设置MessageParcel实例中包含的数据大小。  
 **调用形式：**     
- setSize(size: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size<sup>(deprecated)</sup> | number | true | MessageParcel实例的数据大小。以字节为单位。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：设置成功，false：设置失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.getCapacity();  hilog.info(0x0000, 'testTag', 'RpcClient: capacity is ' + result);    
```    
  
    
### setCapacity<sup>(deprecated)</sup>    
设置MessageParcel实例的存储容量。  
 **调用形式：**     
- setCapacity(size: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size<sup>(deprecated)</sup> | number | true | MessageParcel实例的存储容量。以字节为单位。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：设置成功，false：设置失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.setCapacity(100);  hilog.info(0x0000, 'testTag', 'RpcClient: setCapacity is ' + result);    
```    
  
    
### getWritableBytes<sup>(deprecated)</sup>    
获取MessageParcel的可写字节空间。  
 **调用形式：**     
- getWritableBytes(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取到的MessageParcel的可写字节空间。以字节为单位。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {  
      let getWritableBytes = data.getWritableBytes();  
      hilog.info(0x0000, 'testTag', 'RpcServer: getWritableBytes is ' + getWritableBytes);  
      return true;  
    }  
  }  
    
```    
  
    
### getReadableBytes<sup>(deprecated)</sup>    
获取MessageParcel的可读字节空间。  
 **调用形式：**     
- getReadableBytes(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取到的MessageParcel的可读字节空间。以字节为单位。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption): boolean {  
      let result = data.getReadableBytes();  
      hilog.info(0x0000, 'testTag', 'RpcServer: getReadableBytes is ' + result);  
      return true;  
    }  
  }  
    
```    
  
    
### getReadPosition<sup>(deprecated)</sup>    
获取MessageParcel的读位置。  
 **调用形式：**     
- getReadPosition(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回MessageParcel实例中的当前读取位置。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let readPos = data.getReadPosition();  hilog.info(0x0000, 'testTag', 'RpcClient: readPos is ' + readPos);    
```    
  
    
### getWritePosition<sup>(deprecated)</sup>    
获取MessageParcel的写位置。  
 **调用形式：**     
- getWritePosition(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回MessageParcel实例中的当前写入位置。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  data.writeInt(10);  let bwPos = data.getWritePosition();  hilog.info(0x0000, 'testTag', 'RpcClient: bwPos is ' + bwPos);    
```    
  
    
### rewindRead<sup>(deprecated)</sup>    
重新偏移读取位置到指定的位置。  
 **调用形式：**     
- rewindRead(pos: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pos<sup>(deprecated)</sup> | number | true | 开始读取数据的目标位置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：读取位置发生更改，false：读取位置未发生更改。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  data.writeInt(12);  data.writeString("parcel");  let number = data.readInt();  hilog.info(0x0000, 'testTag', 'RpcClient: number is ' + number);  data.rewindRead(0);  let number2 = data.readInt();  hilog.info(0x0000, 'testTag', 'RpcClient: rewindRead is ' + number2);    
```    
  
    
### rewindWrite<sup>(deprecated)</sup>    
重新偏移写位置到指定的位置。  
 **调用形式：**     
- rewindWrite(pos: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pos<sup>(deprecated)</sup> | number | true | 开始写入数据的目标位置。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入位置发生更改，false：写入位置未发生更改。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  data.writeInt(4);  data.rewindWrite(0);  data.writeInt(5);  let number = data.readInt();  hilog.info(0x0000, 'testTag', 'RpcClient: rewindWrite is ' + number);    
```    
  
    
### writeNoException<sup>(deprecated)</sup>    
向MessageParcel写入“指示未发生异常”的信息。  
 **调用形式：**     
- writeNoException(): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### readException<sup>(deprecated)</sup>    
从MessageParcel中读取异常。  
 **调用形式：**     
- readException(): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **示例代码：**   
 Stage模型的应用在获取服务前需要先获取context，具体方法可参考[获取context](#获取context)  
```ts    
import Want from '@ohos.app.ability.Want';  import common from '@ohos.app.ability.common';  import hilog from '@ohos.hilog';  
  let proxy: rpc.IRemoteObject | undefined = undefined;  let connect: common.ConnectOptions = {    onConnect: (elementName, remoteProxy) => {      hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');      proxy = remoteProxy;    },    onDisconnect: (elementName) => {      hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');    },    onFailed: () => {      hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');    }  };  let want: Want = {    bundleName: "com.ohos.server",    abilityName: "com.ohos.server.EntryAbility",  };    
```    
  
    
### writeByte<sup>(deprecated)</sup>    
<span style="letter-spacing: 0px;">将字节值写入MessageParcel实例。</span>。  
 **调用形式：**     
- writeByte(val: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val<sup>(deprecated)</sup> | number | true | 要写入的字节值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeByte(2);  hilog.info(0x0000, 'testTag', 'RpcClient: writeByte is ' + result);    
```    
  
    
### writeShort<sup>(deprecated)</sup>    
将短整数值写入MessageParcel实例。  
 **调用形式：**     
- writeShort(val: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val<sup>(deprecated)</sup> | number | true | 要写入的短整数值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeShort(8);  hilog.info(0x0000, 'testTag', 'RpcClient: writeShort is ' + result);    
```    
  
    
### writeInt<sup>(deprecated)</sup>    
将整数值写入MessageParcel实例。  
 **调用形式：**     
- writeInt(val: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val<sup>(deprecated)</sup> | number | true | 要写入的整数值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeInt(10);  hilog.info(0x0000, 'testTag', 'RpcClient: writeInt is ' + result);    
```    
  
    
### writeLong<sup>(deprecated)</sup>    
将长整数值写入MessageParcel实例。  
 **调用形式：**     
- writeLong(val: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val<sup>(deprecated)</sup> | number | true | 要写入的长整数值 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeLong(10000);  hilog.info(0x0000, 'testTag', 'RpcClient: writeLong is ' + result);    
```    
  
    
### writeFloat<sup>(deprecated)</sup>    
将浮点值写入MessageParcel实例。  
 **调用形式：**     
- writeFloat(val: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val<sup>(deprecated)</sup> | number | true | 要写入的浮点值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeFloat(1.2);  hilog.info(0x0000, 'testTag', 'RpcClient: writeFloat is ' + result);    
```    
  
    
### writeDouble<sup>(deprecated)</sup>    
将双精度浮点值写入MessageParcel实例。  
 **调用形式：**     
- writeDouble(val: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val<sup>(deprecated)</sup> | number | true | 要写入的双精度浮点值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeDouble(10.2);  hilog.info(0x0000, 'testTag', 'RpcClient: writeDouble is ' + result);    
```    
  
    
### writeBoolean<sup>(deprecated)</sup>    
将布尔值写入MessageParcel实例。  
 **调用形式：**     
- writeBoolean(val: boolean): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val<sup>(deprecated)</sup> | boolean | true | 要写入的布尔值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeBoolean(false);  hilog.info(0x0000, 'testTag', 'RpcClient: writeBoolean is ' + result);    
```    
  
    
### writeChar<sup>(deprecated)</sup>    
将单个字符值写入MessageParcel实例。  
 **调用形式：**     
- writeChar(val: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val<sup>(deprecated)</sup> | number | true | 要写入的单个字符值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeChar(97);  hilog.info(0x0000, 'testTag', 'RpcClient: writeChar is ' + result);    
```    
  
    
### writeString<sup>(deprecated)</sup>    
将字符串值写入MessageParcel实例。  
 **调用形式：**     
- writeString(val: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val<sup>(deprecated)</sup> | string | true | 要写入的字符串值，其长度应小于40960字节。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeString('abc');  hilog.info(0x0000, 'testTag', 'RpcClient: writeString is ' + result);    
```    
  
    
### writeSequenceable<sup>(deprecated)</sup>    
将自定义序列化对象写入MessageParcel实例。  
 **调用形式：**     
- writeSequenceable(val: Sequenceable): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val<sup>(deprecated)</sup> | Sequenceable | true | 要写入的可序列对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### writeByteArray<sup>(deprecated)</sup>    
将字节数组写入MessageParcel实例。  
 **调用形式：**     
- writeByteArray(byteArray: number[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| byteArray<sup>(deprecated)</sup> | number[] | true | 要写入的字节数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let ByteArrayVar = [1, 2, 3, 4, 5];  let result = data.writeByteArray(ByteArrayVar);  hilog.info(0x0000, 'testTag', 'RpcClient: writeByteArray is ' + result);    
```    
  
    
### writeShortArray<sup>(deprecated)</sup>    
将短整数数组写入MessageParcel实例。  
 **调用形式：**     
- writeShortArray(shortArray: number[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| shortArray<sup>(deprecated)</sup> | number[] | true | 要写入的短整数数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeShortArray([11, 12, 13]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeShortArray is ' + result);    
```    
  
    
### writeIntArray<sup>(deprecated)</sup>    
将整数数组写入MessageParcel实例。  
 **调用形式：**     
- writeIntArray(intArray: number[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| intArray<sup>(deprecated)</sup> | number[] | true | 要写入的整数数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeIntArray([100, 111, 112]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeIntArray is ' + result);    
```    
  
    
### writeLongArray<sup>(deprecated)</sup>    
将长整数数组写入MessageParcel实例。  
 **调用形式：**     
- writeLongArray(longArray: number[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| longArray<sup>(deprecated)</sup> | number[] | true | 要写入的长整数数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeLongArray([1111, 1112, 1113]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeLongArray is ' + result);    
```    
  
    
### writeFloatArray<sup>(deprecated)</sup>    
将浮点数组写入MessageParcel实例。  
 **调用形式：**     
- writeFloatArray(floatArray: number[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| floatArray<sup>(deprecated)</sup> | number[] | true | 要写入的浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeFloatArray([1.2, 1.3, 1.4]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeFloatArray is ' + result);    
```    
  
    
### writeDoubleArray<sup>(deprecated)</sup>    
将双精度浮点数组写入MessageParcel实例。  
 **调用形式：**     
- writeDoubleArray(doubleArray: number[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| doubleArray<sup>(deprecated)</sup> | number[] | true | 要写入的双精度浮点数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeDoubleArray is ' + result);    
```    
  
    
### writeBooleanArray<sup>(deprecated)</sup>    
将布尔数组写入MessageParcel实例。  
 **调用形式：**     
- writeBooleanArray(booleanArray: boolean[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| booleanArray<sup>(deprecated)</sup> | boolean[] | true | 要写入的布尔数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeBooleanArray([false, true, false]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeBooleanArray is ' + result);    
```    
  
    
### writeCharArray<sup>(deprecated)</sup>    
将单个字符数组写入MessageParcel实例。  
 **调用形式：**     
- writeCharArray(charArray: number[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| charArray<sup>(deprecated)</sup> | number[] | true | 要写入的单个字符数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeCharArray([97, 98, 88]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeCharArray is ' + result);    
```    
  
    
### writeStringArray<sup>(deprecated)</sup>    
将字符串数组写入MessageParcel实例。  
 **调用形式：**     
- writeStringArray(stringArray: string[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| stringArray<sup>(deprecated)</sup> | string[] | true |  | stringArray | string[] | 是   | 要写入的字符串数组，数组单个元素的长度应小于40960字节。 | |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeStringArray(["abc", "def"]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeStringArray is ' + result);    
```    
  
    
### writeSequenceableArray<sup>(deprecated)</sup>    
将可序列化对象数组写入MessageParcel实例。  
 **调用形式：**     
- writeSequenceableArray(sequenceableArray: Sequenceable[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sequenceableArray<sup>(deprecated)</sup> | Sequenceable[] | true | 要写入的可序列化对象数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### writeRemoteObjectArray<sup>(deprecated)</sup>    
将IRemoteObject对象数组写入MessageParcel。  
 **调用形式：**     
- writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| objectArray<sup>(deprecated)</sup> | IRemoteObject[] | true | 要写入MessageParcel的IRemoteObject对象数组。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### readByte<sup>(deprecated)</sup>    
从MessageSequence实例读取字节值。  
 **调用形式：**     
- readByte(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回字节值。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeByte(2);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write byte fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write byte fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readByte();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readByte is: ' +  ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read byte fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read byte fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readShort<sup>(deprecated)</sup>    
从MessageSequence实例读取短整数值。  
 **调用形式：**     
- readShort(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回短整数值。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeShort(8);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write short fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write short fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readShort();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readByte is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read short fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read short fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readInt<sup>(deprecated)</sup>    
从MessageSequence实例读取整数值。  
 **调用形式：**     
- readInt(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回整数值。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeInt(10);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write int fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write int fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readInt();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readInt is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read int fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read int fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readLong<sup>(deprecated)</sup>    
从MessageSequence实例中读取长整数值。  
 **调用形式：**     
- readLong(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回长整数值。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeLong(10000);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write long fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write long fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readLong();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readLong is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read long fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read long fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readFloat<sup>(deprecated)</sup>    
从MessageSequence实例中读取浮点值。  
 **调用形式：**     
- readFloat(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回浮点值。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeFloat(1.2);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write float fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write float fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readFloat();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readFloat is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read float fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read float fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readDouble<sup>(deprecated)</sup>    
从MessageSequence实例读取双精度浮点值。  
 **调用形式：**     
- readDouble(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回双精度浮点值。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeDouble(10.2);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write double fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write double fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readDouble();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readDouble is ' +  ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read double fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read double fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readBoolean<sup>(deprecated)</sup>    
从MessageSequence实例读取布尔值。  
 **调用形式：**     
- readBoolean(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回读取到的布尔值。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeBoolean(false);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write boolean fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write boolean fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readBoolean();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readBoolean is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read boolean fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read boolean fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readChar<sup>(deprecated)</sup>    
从MessageSequence实例中读取单个字符值。  
 **调用形式：**     
- readChar(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回单个字符值。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeChar(97);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write char fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write char fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readChar();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readChar is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read char fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read char fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readString<sup>(deprecated)</sup>    
从MessageSequence实例读取字符串值。  
 **调用形式：**     
- readString(): string  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回字符串值。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeString('abc');  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write string fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write string fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readString();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readString is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read string fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read string fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readSequenceable<sup>(deprecated)</sup>    
从MessageParcel实例中读取成员变量到指定的对象（dataIn）。  
 **调用形式：**     
- readSequenceable(dataIn: Sequenceable): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | Sequenceable | true | 需要从MessageParcel读取成员变量的对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：反序列化成功，false：反序列化失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### readByteArray<sup>(deprecated)</sup>    
从MessageParcel实例读取字节数组。  
 **调用形式：**     
- readByteArray(dataIn: number[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | number[] | true | 要读取的字节数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let ByteArrayVar = [1, 2, 3, 4, 5];  let result = data.writeByteArray(ByteArrayVar);  hilog.info(0x0000, 'testTag', 'RpcClient: writeByteArray is ' + result);  let array: Array<number> = new Array(5);  data.readByteArray(array);    
```    
  
    
### readByteArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取字节数组。  
 **调用形式：**     
- readByteArray(): number[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回字节数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let ByteArrayVar = [1, 2, 3, 4, 5];  let result = data.writeByteArray(ByteArrayVar);  hilog.info(0x0000, 'testTag', 'RpcClient: writeByteArray is ' + result);  let array = data.readByteArray();  hilog.info(0x0000, 'testTag', 'RpcClient: readByteArray is ' + array);    
```    
  
    
### readShortArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取短整数数组。  
 **调用形式：**     
- readShortArray(dataIn: number[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | number[] | true | 要读取的短整数数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeShortArray([11, 12, 13]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeShortArray is ' + result);  let array: Array<number> = new Array(3);  data.readShortArray(array);    
```    
  
    
### readShortArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取短整数数组。  
 **调用形式：**     
- readShortArray(): number[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回短整数数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeShortArray([11, 12, 13]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeShortArray is ' + result);  let array = data.readShortArray();  hilog.info(0x0000, 'testTag', 'RpcClient: readShortArray is ' + array);    
```    
  
    
### readIntArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取整数数组。  
 **调用形式：**     
- readIntArray(dataIn: number[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | number[] | true | 要读取的整数数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeIntArray([100, 111, 112]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeIntArray is ' + result);  let array: Array<number> = new Array(3);  data.readIntArray(array);    
```    
  
    
### readIntArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取整数数组。  
 **调用形式：**     
- readIntArray(): number[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回整数数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeIntArray([100, 111, 112]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeIntArray is ' + result);  let array = data.readIntArray();  hilog.info(0x0000, 'testTag', 'RpcClient: readIntArray is ' + array);    
```    
  
    
### readLongArray<sup>(deprecated)</sup>    
从MessageParcel实例读取长整数数组。  
 **调用形式：**     
- readLongArray(dataIn: number[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | number[] | true | 要读取的长整数数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeLongArray([1111, 1112, 1113]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeLongArray is ' + result);  let array: Array<number> = new Array(3);  data.readLongArray(array);    
```    
  
    
### readLongArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取长整数数组。  
 **调用形式：**     
- readLongArray(): number[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回长整数数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeLongArray([1111, 1112, 1113]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeLongArray is ' + result);  let array = data.readLongArray();  hilog.info(0x0000, 'testTag', 'RpcClient: readLongArray is ' + array);    
```    
  
    
### readFloatArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取浮点数组。  
 **调用形式：**     
- readFloatArray(dataIn: number[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | number[] | true | 要读取的浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |  
    
 **示例代码：**   
```ts    
<span style="letter-spacing: 0px;">import hilog from '@ohos.hilog';</span>  
  
  let data = rpc.MessageParcel.create();  let result = data.writeFloatArray([1.2, 1.3, 1.4]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeFloatArray is ' + result);  let array: Array<number> = new Array(3);  data.readFloatArray(array);    
```    
  
    
### readFloatArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取浮点数组。  
 **调用形式：**     
- readFloatArray(): number[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回浮点数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeFloatArray([1.2, 1.3, 1.4]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeFloatArray is ' + result);  let array = data.readFloatArray();  hilog.info(0x0000, 'testTag', 'RpcClient: readFloatArray is ' + array);    
```    
  
    
### readDoubleArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取双精度浮点数组。  
 **调用形式：**     
- readDoubleArray(dataIn: number[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | number[] | true | 要读取的双精度浮点数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeDoubleArray is ' + result);  let array: Array<number> = new Array(3);  data.readDoubleArray(array);    
```    
  
    
### readDoubleArray<sup>(deprecated)</sup>    
从MessageParcel实例读取双精度浮点数组。  
 **调用形式：**     
- readDoubleArray(): number[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回双精度浮点数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeDoubleArray([11.1, 12.2, 13.3]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeDoubleArray is ' + result);  let array = data.readDoubleArray();  hilog.info(0x0000, 'testTag', 'RpcClient: readDoubleArray is ' + array);    
```    
  
    
### readBooleanArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取布尔数组。  
 **调用形式：**     
- readBooleanArray(dataIn: boolean[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | boolean[] | true | 要读取的布尔数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeBooleanArray([false, true, false]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeBooleanArray is ' + result);  let array: Array<boolean> = new Array(3);  data.readBooleanArray(array);    
```    
  
    
### readBooleanArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取布尔数组。  
 **调用形式：**     
- readBooleanArray(): boolean[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean[] | 返回布尔数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeBooleanArray([false, true, false]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeBooleanArray is ' + result);  let array = data.readBooleanArray();  hilog.info(0x0000, 'testTag', 'RpcClient: readBooleanArray is ' + array);    
```    
  
    
### readCharArray<sup>(deprecated)</sup>    
从MessageParcel实例中读取单个字符数组。  
 **调用形式：**     
- readCharArray(dataIn: number[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | number[] | true | 要读取的单个字符数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeCharArray([97, 98, 99]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeCharArray is ' + result);  let array: Array<number> = new Array(3);  data.readCharArray(array);    
```    
  
    
### readCharArray<sup>(deprecated)</sup>    
从MessageParcel实例读取单个字符数组。  
 **调用形式：**     
- readCharArray(): number[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回单个字符数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeCharArray([97, 98, 99]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeCharArray is ' + result);  let array = data.readCharArray();  hilog.info(0x0000, 'testTag', 'RpcClient: readCharArray is ' + array);    
```    
  
    
### readStringArray<sup>(deprecated)</sup>    
从MessageParcel实例读取字符串数组。  
 **调用形式：**     
- readStringArray(dataIn: string[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | string[] | true | 要读取的字符串数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeStringArray(["abc", "def"]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeStringArray is ' + result);  let array: Array<string> = new Array(2);  data.readStringArray(array);    
```    
  
    
### readStringArray<sup>(deprecated)</sup>    
从MessageParcel实例读取字符串数组。  
 **调用形式：**     
- readStringArray(): string[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string[] | 返回字符串数组。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let data = rpc.MessageParcel.create();  let result = data.writeStringArray(["abc", "def"]);  hilog.info(0x0000, 'testTag', 'RpcClient: writeStringArray is ' + result);  let array = data.readStringArray();  hilog.info(0x0000, 'testTag', 'RpcClient: readStringArray is ' + array);    
```    
  
    
### readSequenceableArray<sup>(deprecated)</sup>    
从MessageParcel实例读取可序列化对象数组。  
 **调用形式：**     
- readSequenceableArray(sequenceableArray: Sequenceable[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| sequenceableArray<sup>(deprecated)</sup> | Sequenceable[] | true | 要读取的可序列化对象数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### readRemoteObjectArray<sup>(deprecated)</sup>    
从MessageParcel读取IRemoteObject对象数组。  
 **调用形式：**     
- readRemoteObjectArray(objects: IRemoteObject[]): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| objects<sup>(deprecated)</sup> | IRemoteObject[] | true | 从MessageParcel读取的IRemoteObject对象数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### readRemoteObjectArray<sup>(deprecated)</sup>    
从MessageParcel读取IRemoteObject对象数组。  
 **调用形式：**     
- readRemoteObjectArray(): IRemoteObject[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteObject[] | 返回IRemoteObject对象数组。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### closeFileDescriptor<sup>(deprecated)</sup>    
静态方法，关闭给定的文件描述符。  
 **调用形式：**     
- static closeFileDescriptor(fd: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 要关闭的文件描述符。 |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  
  let filePath = "path/to/file";  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  let parcel = new rpc.MessageParcel();     parcel.closeFileDescriptor(file.fd);    
```    
  
    
### dupFileDescriptor<sup>(deprecated)</sup>    
静态方法，复制给定的文件描述符。  
 **调用形式：**     
- static dupFileDescriptor(fd: number): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 表示已存在的文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number |  |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  
  let filePath = "path/to/file";  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  let parcel = new rpc.MessageParcel();  parcel.dupFileDescriptor(file.fd);    
```    
  
    
### containFileDescriptors<sup>(deprecated)</sup>    
检查此MessageParcel对象是否包含文件描述符。  
 **调用形式：**     
- containFileDescriptors(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：包含文件描述符，false：未包含文件描述符。 |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  import hilog from '@ohos.hilog';  
  let parcel = new rpc.MessageParcel();  let filePath = "path/to/file";  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  let writeResult = parcel.writeFileDescriptor(file.fd);  hilog.info(0x0000, 'testTag', 'RpcTest: parcel writeFd result is ' + writeResult);  let containFD = parcel.containFileDescriptors();  hilog.info(0x0000, 'testTag', 'RpcTest: parcel after write fd containFd result is ' + containFD);    
```    
  
    
### writeFileDescriptor<sup>(deprecated)</sup>    
写入文件描述符到MessageParcel。  
 **调用形式：**     
- writeFileDescriptor(fd: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd<sup>(deprecated)</sup> | number | true | 文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：操作成功，false：操作失败。 |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  import hilog from '@ohos.hilog';  
  let parcel = new rpc.MessageParcel();  let filePath = "path/to/file";  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  let writeResult = parcel.writeFileDescriptor(file.fd);  hilog.info(0x0000, 'testTag', 'RpcTest: parcel writeFd result is ' + writeResult);    
```    
  
    
### readFileDescriptor<sup>(deprecated)</sup>    
从MessageSequence中读取文件描述符。  
 **调用形式：**     
- readFileDescriptor(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回文件描述符。 |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  import hilog from '@ohos.hilog';  
  let parcel = new rpc.MessageParcel();  let filePath = "path/to/file";  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  parcel.writeFileDescriptor(file.fd);  let readFD = parcel.readFileDescriptor();  hilog.info(0x0000, 'testTag', 'RpcTest: parcel read fd is ' + readFD);    
```    
  
    
### writeAshmem<sup>(deprecated)</sup>    
将指定的匿名共享对象写入此MessageParcel。  
 **调用形式：**     
- writeAshmem(ashmem: Ashmem): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ashmem<sup>(deprecated)</sup> | Ashmem | true | 要写入MessageParcel的匿名共享对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let parcel = new rpc.MessageParcel();  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);  let isWriteSuccess = parcel.writeAshmem(ashmem);  hilog.info(0x0000, 'testTag', 'RpcTest: write ashmem to result is ' + isWriteSuccess);    
```    
  
    
### readAshmem<sup>(deprecated)</sup>    
从MessageParcel读取匿名共享对象。  
 **调用形式：**     
- readAshmem(): Ashmem  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Ashmem | 返回匿名共享对象。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let parcel = new rpc.MessageParcel();  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024);  let isWriteSuccess = parcel.writeAshmem(ashmem);  hilog.info(0x0000, 'testTag', 'RpcTest: write ashmem to result is ' + isWriteSuccess);  let readAshmem = parcel.readAshmem();  hilog.info(0x0000, 'testTag', 'RpcTest: read ashmem to result is ' + readAshmem);    
```    
  
    
### getRawDataCapacity<sup>(deprecated)</sup>    
获取MessageParcel可以容纳的最大原始数据量。  
 **调用形式：**     
- getRawDataCapacity(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回MessageParcel可以容纳的最大原始数据量，即128Mb。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let parcel = new rpc.MessageParcel();  let result = parcel.getRawDataCapacity();  hilog.info(0x0000, 'testTag', 'RpcTest: parcel get RawDataCapacity result is ' + result);    
```    
  
    
### writeRawData<sup>(deprecated)</sup>    
将原始数据写入MessageParcel对象。  
 **调用形式：**     
- writeRawData(rawData: number[], size: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rawData<sup>(deprecated)</sup> | number[] | true | 要写入的原始数据。 |  
| size<sup>(deprecated)</sup> | number | true | 发送的原始数据大小，以字节为单位。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：写入成功，false：写入失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let parcel = new rpc.MessageParcel();  let arr = [1, 2, 3, 4, 5];  let isWriteSuccess = parcel.writeRawData(arr, arr.length);  hilog.info(0x0000, 'testTag', 'RpcTest: parcel write raw data result is ' + isWriteSuccess);    
```    
  
    
### readRawData<sup>(deprecated)</sup>    
从MessageParcel读取原始数据。  
 **调用形式：**     
- readRawData(size: number): number[]  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size<sup>(deprecated)</sup> | number | true | 要读取的原始数据的大小。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回原始数据（以字节为单位）。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let parcel = new rpc.MessageParcel();  let arr = [1, 2, 3, 4, 5];  let isWriteSuccess = parcel.writeRawData(arr, arr.length);  hilog.info(0x0000, 'testTag', 'RpcTest: parcel write raw data result is ' + isWriteSuccess);  let result = parcel.readRawData(5);  hilog.info(0x0000, 'testTag', 'RpcTest: parcel read raw data result is ' + result);    
```    
  
    
## MessageSequence<sup>(9+)</sup>    
在RPC或IPC过程中，发送方可以使用MessageSequence提供的写方法，将待发送的数据以特定格式写入该对象。接收方可以使用MessageSequence提供的读方法从该对象中读取特定格式的数据。数据格式包括：基础类型及数组、IPC对象、接口描述符和自定义序列化对象。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### create<sup>(9+)</sup>    
静态方法，创建MessageSequence对象。  
 **调用形式：**     
- static create(): MessageSequence  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MessageSequence | 返回创建的MessageSequence对象。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageSequence.create();  hilog.info(0x0000, 'testTag', 'RpcClient: data is ' + data);    
```    
  
    
### reclaim<sup>(9+)</sup>    
释放不再使用的MessageSequence对象。  
 **调用形式：**     
- reclaim(): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **示例代码：**   
```ts    
let reply = rpc.MessageSequence.create();  reply.reclaim();    
```    
  
    
### writeRemoteObject<sup>(9+)</sup>    
序列化远程对象并将其写入MessageSequence对象。  
 **调用形式：**     
- writeRemoteObject(object: IRemoteObject): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| object | IRemoteObject | true | 要序列化并写入MessageSequence的远程对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900008 | proxy or remote object is invalid |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  class TestRemoteObject extends rpc.RemoteObject {  
    constructor(descriptor: string) {  
      super(descriptor);  
    }  
  }  
  let data = rpc.MessageSequence.create();  
  let testRemoteObject = new TestRemoteObject("testObject");  
  try {  
    data.writeRemoteObject(testRemoteObject);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc write remote object fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc write remote object fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readRemoteObject<sup>(9+)</sup>    
从MessageSequence读取远程对象。此方法用于反序列化MessageSequence对象以生成IRemoteObject。远程对象按写入MessageSequence的顺序读取。  
 **调用形式：**     
- readRemoteObject(): IRemoteObject  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteObject | 读取到的远程对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900008 | proxy or remote object is invalid |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc write remote object fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc write remote object fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeInterfaceToken<sup>(9+)</sup>    
将接口描述符写入MessageSequence对象，远端对象可使用该信息校验本次通信。  
 **调用形式：**     
- writeInterfaceToken(token: string): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| token | string | true | 字符串类型描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeInterfaceToken("aaa");  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write interface fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write interface fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readInterfaceToken<sup>(9+)</sup>    
从MessageSequence对象中读取接口描述符，接口描述符按写入MessageSequence的顺序读取，本地对象可使用该信息检验本次通信。  
 **调用形式：**     
- readInterfaceToken(): string  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回读取到的接口描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
import { BusinessError } from '@ohos.base';  
  
class Stub extends rpc.RemoteObject {  
  onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
    try {  
      let interfaceToken = data.readInterfaceToken();  
      hilog.info(0x0000, 'testTag', 'RpcServer: interfaceToken is ' + interfaceToken);  
    } catch(error) {  
      let e: BusinessError = error as BusinessError;  
      hilog.error(0x0000, 'testTag', 'RpcServer: read interfaceToken failed, errorCode ' + e.code);  
      hilog.error(0x0000, 'testTag', 'RpcServer: read interfaceToken failed, errorMessage ' + e.message);  
    }  
    return true;  
  }  
}  
    
```    
  
    
### getSize<sup>(9+)</sup>    
获取当前创建的MessageSequence对象的数据大小。  
 **调用形式：**     
- getSize(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取的MessageSequence实例的数据大小。以字节为单位。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageSequence.create();  let size = data.getSize();  hilog.info(0x0000, 'testTag', 'RpcClient: size is ' + size);    
```    
  
    
### getCapacity<sup>(9+)</sup>    
获取当前MessageSequence对象的容量大小。  
 **调用形式：**     
- getCapacity(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取的MessageSequence实例的容量大小。以字节为单位。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageSequence.create();  let result = data.getCapacity();  hilog.info(0x0000, 'testTag', 'RpcClient: capacity is ' + result);    
```    
  
    
### setSize<sup>(9+)</sup>    
设置MessageSequence对象中包含的数据大小。  
 **调用形式：**     
- setSize(size: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | number | true | MessageSequence实例的数据大小。以字节为单位。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.setSize(16);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc set size of MessageSequence fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc set size of MessageSequence fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### setCapacity<sup>(9+)</sup>    
设置MessageSequence对象的存储容量。  
 **调用形式：**     
- setCapacity(size: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | number | true | MessageSequence实例的存储容量。以字节为单位。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900011 | parcel memory alloc failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.setCapacity(100);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc memory alloc fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc memory alloc fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### getWritableBytes<sup>(9+)</sup>    
获取MessageSequence的可写字节空间大小。  
 **调用形式：**     
- getWritableBytes(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取到的MessageSequence实例的可写字节空间。以字节为单位。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
class Stub extends rpc.RemoteObject {  
  onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
    let getWritableBytes = data.getWritableBytes();  
    hilog.info(0x0000, 'testTag', 'RpcServer: getWritableBytes is ' + getWritableBytes);  
    return true;  
  }  
}  
    
```    
  
    
### getReadableBytes<sup>(9+)</sup>    
获取MessageSequence的可读字节空间。  
 **调用形式：**     
- getReadableBytes(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 获取到的MessageSequence实例的可读字节空间。以字节为单位。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
class Stub extends rpc.RemoteObject {  
  onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
    let result = data.getReadableBytes();  
    hilog.info(0x0000, 'testTag', 'RpcServer: getReadableBytes is ' + result);  
    return true;  
  }  
}  
    
```    
  
    
### getReadPosition<sup>(9+)</sup>    
获取MessageSequence的读位置。  
 **调用形式：**     
- getReadPosition(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回MessageSequence实例中的当前读取位置。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageSequence.create();  let readPos = data.getReadPosition();  hilog.info(0x0000, 'testTag', 'RpcClient: readPos is ' + readPos);    
```    
  
    
### getWritePosition<sup>(9+)</sup>    
获取MessageSequence的写位置。  
 **调用形式：**     
- getWritePosition(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回MessageSequence实例中的当前写入位置。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let data = rpc.MessageSequence.create();  data.writeInt(10);  let bwPos = data.getWritePosition();  hilog.info(0x0000, 'testTag', 'RpcClient: bwPos is ' + bwPos);    
```    
  
    
### rewindRead<sup>(9+)</sup>    
重新偏移读取位置到指定的位置。  
 **调用形式：**     
- rewindRead(pos: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pos | number | true | 开始读取数据的目标位置。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  data.writeInt(12);  
  data.writeString("sequence");  
  let number = data.readInt();  
  hilog.info(0x0000, 'testTag', 'RpcClient: number is ' + number);  
  try {  
    data.rewindRead(0);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc rewind read data fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc rewind read data fail, errorMessage ' + e.message);  
  }  
  let number2 = data.readInt();  
  hilog.info(0x0000, 'testTag', 'RpcClient: rewindRead is ' + number2);  
    
```    
  
    
### rewindWrite<sup>(9+)</sup>    
重新偏移写位置到指定的位置。  
 **调用形式：**     
- rewindWrite(pos: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| pos | number | true | 开始写入数据的目标位置。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  data.writeInt(4);  
  try {  
    data.rewindWrite(0);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc rewindWrite fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc rewindWrite fail, errorMessage ' + e.message);  
  }  
  data.writeInt(5);  
  let number = data.readInt();  
  hilog.info(0x0000, 'testTag', 'RpcClient: rewindWrite is: ' + number);  
    
```    
  
    
### writeNoException<sup>(9+)</sup>    
向MessageSequence写入“指示未发生异常”的信息。  
 **调用形式：**     
- writeNoException(): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900009 | write data to message sequence failed |  
    
### readException<sup>(9+)</sup>    
从MessageSequence中读取异常。  
 **调用形式：**     
- readException(): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
### writeByte<sup>(9+)</sup>    
<span style="letter-spacing: 0px;">将字节值写入MessageSequence实例。</span>  
 **调用形式：**     
- writeByte(val: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val | number | true | 要写入的字节值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeByte(2);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write byte fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write byte fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeShort<sup>(9+)</sup>    
将短整数值写入MessageSequence实例。  
 **调用形式：**     
- writeShort(val: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val | number | true | 要写入的短整数值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeShort(8);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write short fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write short fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeInt<sup>(9+)</sup>    
将整数值写入MessageSequence实例。  
 **调用形式：**     
- writeInt(val: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val | number | true | 要写入的整数值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeInt(10);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write int fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write int fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeLong<sup>(9+)</sup>    
将长整数值写入MessageSequence实例。  
 **调用形式：**     
- writeLong(val: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val | number | true | 要写入的长整数值 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeLong(10000);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write long fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write long fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeFloat<sup>(9+)</sup>    
将浮点值写入MessageSequence实例。  
 **调用形式：**     
- writeFloat(val: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val | number | true | 要写入的浮点值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeFloat(1.2);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write float fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write float fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeDouble<sup>(9+)</sup>    
将双精度浮点值写入MessageSequence实例。  
 **调用形式：**     
- writeDouble(val: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val | number | true | 要写入的双精度浮点值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeDouble(10.2);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write double fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write double fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeBoolean<sup>(9+)</sup>    
将布尔值写入MessageSequence实例。  
 **调用形式：**     
- writeBoolean(val: boolean): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val | boolean | true | 要写入的布尔值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeBoolean(false);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write boolean fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write boolean fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeChar<sup>(9+)</sup>    
将单个字符值写入MessageSequence实例。  
 **调用形式：**     
- writeChar(val: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val | number | true | 要写入的单个字符值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeChar(97);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write char fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write char fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeString<sup>(9+)</sup>    
将字符串值写入MessageSequence实例。  
 **调用形式：**     
- writeString(val: string): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val | string | true | 要写入的字符串值，其长度应小于40960字节。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeString('abc');  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write string fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write string fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeParcelable<sup>(9+)</sup>    
将自定义序列化对象写入MessageSequence实例。  
 **调用形式：**     
- writeParcelable(val: Parcelable): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| val | Parcelable | true | 要写入的可序列对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write parcelable fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write parcelable fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeByteArray<sup>(9+)</sup>    
将字节数组写入MessageSequence实例。  
 **调用形式：**     
- writeByteArray(byteArray: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| byteArray | number[] | true | 要写入的字节数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  let ByteArrayVar = [1, 2, 3, 4, 5];  
  try {  
    data.writeByteArray(ByteArrayVar);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeShortArray<sup>(9+)</sup>    
将短整数数组写入MessageSequence实例。  
 **调用形式：**     
- writeShortArray(shortArray: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| shortArray | number[] | true | 要写入的短整数数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeShortArray([11, 12, 13]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeIntArray<sup>(9+)</sup>    
将整数数组写入MessageSequence实例。  
 **调用形式：**     
- writeIntArray(intArray: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| intArray | number[] | true | 要写入的整数数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeIntArray([100, 111, 112]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeLongArray<sup>(9+)</sup>    
将长整数数组写入MessageSequence实例。  
 **调用形式：**     
- writeLongArray(longArray: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| longArray | number[] | true | 要写入的长整数数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeLongArray([1111, 1112, 1113]);  
  }catch(error){  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeFloatArray<sup>(9+)</sup>    
将浮点数组写入MessageSequence实例。  
 **调用形式：**     
- writeFloatArray(floatArray: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| floatArray | number[] | true | 要写入的浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeFloatArray([1.2, 1.3, 1.4]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeDoubleArray<sup>(9+)</sup>    
将双精度浮点数组写入MessageSequence实例。  
 **调用形式：**     
- writeDoubleArray(doubleArray: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| doubleArray | number[] | true | 要写入的双精度浮点数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeDoubleArray([11.1, 12.2, 13.3]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeBooleanArray<sup>(9+)</sup>    
将布尔数组写入MessageSequence实例。  
 **调用形式：**     
- writeBooleanArray(booleanArray: boolean[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| booleanArray | boolean[] | true | 要写入的布尔数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeBooleanArray([false, true, false]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeCharArray<sup>(9+)</sup>    
将单个字符数组写入MessageSequence实例。  
 **调用形式：**     
- writeCharArray(charArray: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| charArray | number[] | true | 要写入的单个字符数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeCharArray([97, 98, 88]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeStringArray<sup>(9+)</sup>    
将字符串数组写入MessageSequence实例。  
 **调用形式：**     
- writeStringArray(stringArray: string[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| stringArray | string[] | true | 要写入的字符串数组，数组单个元素的长度应小于40960字节。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeStringArray(["abc", "def"]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeParcelableArray<sup>(9+)</sup>    
将可序列化对象数组写入MessageSequence实例。  
 **调用形式：**     
- writeParcelableArray(parcelableArray: Parcelable[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parcelableArray | Parcelable[] | true | 要写入的可序列化对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write parcelable array fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write parcelable array fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeRemoteObjectArray<sup>(9+)</sup>    
将IRemoteObject对象数组写入MessageSequence。  
 **调用形式：**     
- writeRemoteObjectArray(objectArray: IRemoteObject[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| objectArray | IRemoteObject[] | true | 要写入MessageSequence的IRemoteObject对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
  } catch(error) {  
     let e: BusinessError = error as BusinessError;  
     hilog.error(0x0000, 'testTag', 'rpc write remote object array fail, errorCode ' + e.code);  
     hilog.error(0x0000, 'testTag', 'rpc write remote object array fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readByte<sup>(9+)</sup>    
从MessageSequence实例读取字节值。  
 **调用形式：**     
- readByte(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回字节值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeByte(2);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write byte fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write byte fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readByte();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readByte is: ' +  ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read byte fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read byte fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readShort<sup>(9+)</sup>    
从MessageSequence实例读取短整数值。  
 **调用形式：**     
- readShort(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回短整数值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeShort(8);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write short fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write short fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readShort();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readByte is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read short fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read short fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readInt<sup>(9+)</sup>    
从MessageSequence实例读取整数值。  
 **调用形式：**     
- readInt(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回整数值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeInt(10);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write int fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write int fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readInt();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readInt is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read int fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read int fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readLong<sup>(9+)</sup>    
从MessageSequence实例中读取长整数值。  
 **调用形式：**     
- readLong(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回长整数值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeLong(10000);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write long fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write long fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readLong();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readLong is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read long fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read long fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readFloat<sup>(9+)</sup>    
从MessageSequence实例中读取浮点值。  
 **调用形式：**     
- readFloat(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回浮点值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeFloat(1.2);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write float fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write float fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readFloat();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readFloat is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read float fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read float fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readDouble<sup>(9+)</sup>    
从MessageSequence实例读取双精度浮点值。  
 **调用形式：**     
- readDouble(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回双精度浮点值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeDouble(10.2);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write double fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write double fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readDouble();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readDouble is ' +  ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read double fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read double fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readBoolean<sup>(9+)</sup>    
从MessageSequence实例读取布尔值。  
 **调用形式：**     
- readBoolean(): boolean  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回读取到的布尔值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeBoolean(false);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write boolean fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write boolean fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readBoolean();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readBoolean is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read boolean fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read boolean fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readChar<sup>(9+)</sup>    
从MessageSequence实例中读取单个字符值。  
 **调用形式：**     
- readChar(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回单个字符值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeChar(97);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write char fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write char fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readChar();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readChar is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read char fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read char fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readString<sup>(9+)</sup>    
从MessageSequence实例读取字符串值。  
 **调用形式：**     
- readString(): string  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回字符串值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeString('abc');  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write string fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write string fail, errorMessage ' + e.message);  
  }  
  try {  
    let ret = data.readString();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readString is ' + ret);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read string fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read string fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readParcelable<sup>(9+)</sup>    
从MessageSequence实例中读取成员变量到指定的对象（dataIn）。  
 **调用形式：**     
- readParcelable(dataIn: Parcelable): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | Parcelable | true | 需要从MessageSequence读取成员变量的对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
| 1900012 | call js callback function failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
  }catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read parcelable fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read parcelable fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readByteArray<sup>(9+)</sup>    
从MessageSequence实例读取字节数组。  
 **调用形式：**     
- readByteArray(dataIn: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | number[] | true | 要读取的字节数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  let ByteArrayVar = [1, 2, 3, 4, 5];  
  try {  
    data.writeByteArray(ByteArrayVar);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array: Array<number> = new Array(5);  
    data.readByteArray(array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read byteArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read byteArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readByteArray<sup>(9+)</sup>    
从MessageSequence实例中读取字节数组。  
 **调用形式：**     
- readByteArray(): number[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回字节数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  let byteArrayVar = [1, 2, 3, 4, 5];  
  try {  
    data.writeByteArray(byteArrayVar);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write byteArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array = data.readByteArray();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readByteArray is ' +  array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read byteArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read byteArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readShortArray<sup>(9+)</sup>    
从MessageSequence实例中读取短整数数组。  
 **调用形式：**     
- readShortArray(dataIn: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | number[] | true | 要读取的短整数数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeShortArray([11, 12, 13]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array: Array<number> = new Array(3);  
    data.readShortArray(array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read shortArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read shortArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readShortArray<sup>(9+)</sup>    
从MessageSequence实例中读取短整数数组。  
 **调用形式：**     
- readShortArray(): number[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回短整数数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeShortArray([11, 12, 13]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write shortArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array = data.readShortArray();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readShortArray is ' + array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read shortArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read shortArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readIntArray<sup>(9+)</sup>    
从MessageSequence实例中读取整数数组。  
 **调用形式：**     
- readIntArray(dataIn: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | number[] | true | 要读取的整数数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeIntArray([100, 111, 112]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorMessage ' + e.message);  
  }  
  let array: Array<number> = new Array(3);  
  try {  
    data.readIntArray(array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read intArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read intArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readIntArray<sup>(9+)</sup>    
从MessageSequence实例中读取整数数组。  
 **调用形式：**     
- readIntArray(): number[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回整数数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeIntArray([100, 111, 112]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write intArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array = data.readIntArray();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readIntArray is ' + array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read intArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read intArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readLongArray<sup>(9+)</sup>    
从MessageSequence实例读取的长整数数组。  
 **调用形式：**     
- readLongArray(dataIn: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | number[] | true | 要读取的长整数数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeLongArray([1111, 1112, 1113]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorMessage ' + e.message);  
  }  
  let array: Array<number> = new Array(3);  
  try {  
    data.readLongArray(array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read longArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read longArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readLongArray<sup>(9+)</sup>    
从MessageSequence实例中读取所有的长整数数组。  
 **调用形式：**     
- readLongArray(): number[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回长整数数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeLongArray([1111, 1112, 1113]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write longArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array = data.readLongArray();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readLongArray is ' + array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read longArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read longArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readFloatArray<sup>(9+)</sup>    
从MessageSequence实例中读取浮点数组。  
 **调用形式：**     
- readFloatArray(dataIn: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | number[] | true | 要读取的浮点数组。由于系统内部对float类型的数据是按照double处理的，使用时对于数组所占的总字节数应按照double类型来计算。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeFloatArray([1.2, 1.3, 1.4]);  
  }catch(error){  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorMessage ' + e.message);  
  }  
  let array: Array<number> = new Array(3);  
  try {  
    data.readFloatArray(array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read floatArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read floatArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readFloatArray<sup>(9+)</sup>    
从MessageSequence实例中读取浮点数组。  
 **调用形式：**     
- readFloatArray(): number[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回浮点数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeFloatArray([1.2, 1.3, 1.4]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write floatArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array = data.readFloatArray();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readFloatArray is ' + array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read floatArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read floatArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readDoubleArray<sup>(9+)</sup>    
从MessageSequence实例中读取双精度浮点数组。  
 **调用形式：**     
- readDoubleArray(dataIn: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | number[] | true | 要读取的双精度浮点数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeDoubleArray([11.1, 12.2, 13.3]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorMessage ' + e.message);  
  }  
  let array: Array<number> = new Array(3);  
  try {  
    data.readDoubleArray(array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read doubleArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read doubleArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readDoubleArray<sup>(9+)</sup>    
从MessageSequence实例读取所有双精度浮点数组。  
 **调用形式：**     
- readDoubleArray(): number[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回双精度浮点数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeDoubleArray([11.1, 12.2, 13.3]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write doubleArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array = data.readDoubleArray();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readDoubleArray is ' + array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read doubleArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read doubleArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readBooleanArray<sup>(9+)</sup>    
从MessageSequence实例中读取布尔数组。  
 **调用形式：**     
- readBooleanArray(dataIn: boolean[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | boolean[] | true | 要读取的布尔数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeBooleanArray([false, true, false]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorMessage ' + e.message);  
  }  
  let array: Array<boolean> = new Array(3);  
  try {  
    data.readBooleanArray(array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read booleanArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read booleanArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readBooleanArray<sup>(9+)</sup>    
从MessageSequence实例中读取所有布尔数组。  
 **调用形式：**     
- readBooleanArray(): boolean[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean[] | 返回布尔数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeBooleanArray([false, true, false]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write booleanArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array = data.readBooleanArray();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readBooleanArray is ' + array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read booleanArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read booleanArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readCharArray<sup>(9+)</sup>    
从MessageSequence实例中读取单个字符数组。  
 **调用形式：**     
- readCharArray(dataIn: number[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | number[] | true | 要读取的单个字符数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeCharArray([97, 98, 88]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorMessage ' + e.message);  
  }  
  let array: Array<number> = new Array(3);  
  try {  
    data.readCharArray(array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read charArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read charArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readCharArray<sup>(9+)</sup>    
从MessageSequence实例读取单个字符数组。  
 **调用形式：**     
- readCharArray(): number[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回单个字符数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeCharArray([97, 98, 88]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write charArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array = data.readCharArray();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readCharArray is ' + array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read charArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read charArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readStringArray<sup>(9+)</sup>    
从MessageSequence实例读取字符串数组。  
 **调用形式：**     
- readStringArray(dataIn: string[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | string[] | true | 要读取的字符串数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeStringArray(["abc", "def"]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorMessage ' + e.message);  
  }  
  let array: Array<string> = new Array(2);  
  try {  
    data.readStringArray(array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read stringArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read stringArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readStringArray<sup>(9+)</sup>    
从MessageSequence实例读取字符串数组。  
 **调用形式：**     
- readStringArray(): string[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string[] | 返回字符串数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let data = rpc.MessageSequence.create();  
  try {  
    data.writeStringArray(["abc", "def"]);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write stringArray fail, errorMessage ' + e.message);  
  }  
  try {  
    let array = data.readStringArray();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readStringArray is ' + array);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read stringArray fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read stringArray fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readParcelableArray<sup>(9+)</sup>    
从MessageSequence实例读取可序列化对象数组。  
 **调用形式：**     
- readParcelableArray(parcelableArray: Parcelable[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| parcelableArray | Parcelable[] | true | 要读取的可序列化对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
| 1900012 | call js callback function failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read parcelable array fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read parcelable array fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readRemoteObjectArray<sup>(9+)</sup>    
从MessageSequence读取IRemoteObject对象数组。  
 **调用形式：**     
- readRemoteObjectArray(objects: IRemoteObject[]): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| objects | IRemoteObject[] | true | 从MessageSequence读取的IRemoteObject对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read remote object array fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read remote object array fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readRemoteObjectArray<sup>(9+)</sup>    
从MessageSequence读取IRemoteObject对象数组。  
 **调用形式：**     
- readRemoteObjectArray(): IRemoteObject[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteObject[] | 返回IRemoteObject对象数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 |  |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read remote object array fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read remote object array fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### closeFileDescriptor<sup>(9+)</sup>    
静态方法，关闭给定的文件描述符。  
 **调用形式：**     
- static closeFileDescriptor(fd: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 要关闭的文件描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  
  import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let filePath = "path/to/file";  
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
  try {  
    rpc.MessageSequence.closeFileDescriptor(file.fd);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc close file descriptor fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc close file descriptor fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### dupFileDescriptor<sup>(9+)</sup>    
静态方法，复制给定的文件描述符。  
 **调用形式：**     
- static dupFileDescriptor(fd: number): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 表示已存在的文件描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回新的文件描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900013 | call os dup function failed |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  
  import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let filePath = "path/to/file";  
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
  try {  
    rpc.MessageSequence.dupFileDescriptor(file.fd);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc dup file descriptor fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc dup file descriptor fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### containFileDescriptors<sup>(9+)</sup>    
检查此MessageSequence对象是否包含文件描述符。  
 **调用形式：**     
- containFileDescriptors(): boolean  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：包含文件描述符，false：不包含文件描述符。 |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  
  import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let sequence = new rpc.MessageSequence();  
  let filePath = "path/to/file";  
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
  try {  
    sequence.writeFileDescriptor(file.fd);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorMessage ' + e.message);  
  }  
  try {  
    let containFD = sequence.containFileDescriptors();  
    hilog.info(0x0000, 'testTag', 'RpcTest: sequence after write fd containFd result is ' + containFD);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc contain file descriptor fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc contain file descriptor fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeFileDescriptor<sup>(9+)</sup>    
写入文件描述符到MessageSequence。  
 **调用形式：**     
- writeFileDescriptor(fd: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fd | number | true | 文件描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  
  import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let sequence = new rpc.MessageSequence();  
  let filePath = "path/to/file";  
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
  try {  
    sequence.writeFileDescriptor(file.fd);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readFileDescriptor<sup>(9+)</sup>    
从MessageSequence中读取文件描述符。  
 **调用形式：**     
- readFileDescriptor(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回文件描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import fs from '@ohos.file.fs';  
  import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let sequence = new rpc.MessageSequence();  
  let filePath = "path/to/file";  
  let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
  try {  
    sequence.writeFileDescriptor(file.fd);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write file descriptor fail, errorMessage ' + e.message);  
  }  
  try {  
    let readFD = sequence.readFileDescriptor();  
    hilog.info(0x0000, 'testTag', 'RpcClient: readFileDescriptor is ' + readFD);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read file descriptor fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read file descriptor fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeAshmem<sup>(9+)</sup>    
将指定的匿名共享对象写入此MessageSequence。  
 **调用形式：**     
- writeAshmem(ashmem: Ashmem): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ashmem | Ashmem | true | 要写入MessageSequence的匿名共享对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900003 | write to ashmem failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let sequence = new rpc.MessageSequence();  
  let ashmem: rpc.Ashmem | undefined = undefined;  
  try {  
    ashmem = rpc.Ashmem.create("ashmem", 1024);  
    try {  
      sequence.writeAshmem(ashmem);  
    } catch(error) {  
      let e: BusinessError = error as BusinessError;  
      hilog.error(0x0000, 'testTag', 'rpc write ashmem fail, errorCode ' + e.code);  
      hilog.error(0x0000, 'testTag', 'rpc write ashmem fail, errorMessage ' + e.message);  
    }  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc create ashmem fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc create ashmem fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readAshmem<sup>(9+)</sup>    
从MessageSequence读取匿名共享对象。  
 **调用形式：**     
- readAshmem(): Ashmem  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Ashmem | 返回匿名共享对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900004 | read from ashmem failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let sequence = new rpc.MessageSequence();  
  let ashmem: rpc.Ashmem | undefined = undefined;  
  try {  
    ashmem = rpc.Ashmem.create("ashmem", 1024);  
    try {  
      sequence.writeAshmem(ashmem);  
    } catch(error) {  
      let e: BusinessError = error as BusinessError;  
      hilog.error(0x0000, 'testTag', 'rpc write ashmem fail, errorCode ' + e.code);  
      hilog.error(0x0000, 'testTag', 'rpc write ashmem fail, errorMessage ' + e.message);  
    }  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc create ashmem fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc create ashmem fail, errorMessage ' + e.message);  
  }  
  try {  
    sequence.readAshmem();  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read ashmem fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read ashmem fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### getRawDataCapacity<sup>(9+)</sup>    
获取MessageSequence可以容纳的最大原始数据量。  
 **调用形式：**     
- getRawDataCapacity(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回MessageSequence可以容纳的最大原始数据量，即128Mb。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let sequence = new rpc.MessageSequence();  let result = sequence.getRawDataCapacity();  hilog.info(0x0000, 'testTag', 'RpcTest: sequence get RawDataCapacity result is ' + result);    
```    
  
    
### writeRawData<sup>(9+)</sup>    
将原始数据写入MessageSequence对象。  
 **调用形式：**     
- writeRawData(rawData: number[], size: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rawData | number[] | true | 要写入的原始数据。 |  
| size | number | true | 发送的原始数据大小，以字节为单位。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900009 | write data to message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let sequence = new rpc.MessageSequence();  
  let arr = [1, 2, 3, 4, 5];  
  try {  
    sequence.writeRawData(arr, arr.length);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readRawData<sup>(9+)</sup>    
从MessageSequence读取原始数据。  
 **调用形式：**     
- readRawData(size: number): number[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | number | true | 要读取的原始数据的大小。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回原始数据（以字节为单位）。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900010 | read data from message sequence failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let sequence = new rpc.MessageSequence();  
  let arr = [1, 2, 3, 4, 5];  
  try {  
    sequence.writeRawData(arr, arr.length);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc write rawdata fail, errorMessage ' + e.message);  
  }  
  try {  
    let result = sequence.readRawData(5);  
    hilog.info(0x0000, 'testTag', 'RpcTest: sequence read raw data result is ' + result);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc read rawdata fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc read rawdata fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
## Sequenceable<sup>(deprecated)</sup>    
在进程间通信（IPC）期间，将类的对象写入MessageParcel并从MessageParcel中恢复它们。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.rpc.Parcelable替代。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### marshalling<sup>(deprecated)</sup>    
将此可序列对象封送到MessageParcel中。  
 **调用形式：**     
- marshalling(dataOut: MessageParcel): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataOut<sup>(deprecated)</sup> | MessageParcel | true | 可序列对象将被封送到的MessageParcel对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：封送成功，false：封送失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### unmarshalling<sup>(deprecated)</sup>    
从MessageParcel中解封此可序列对象。  
 **调用形式：**     
- unmarshalling(dataIn: MessageParcel): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn<sup>(deprecated)</sup> | MessageParcel | true | 已将可序列对象封送到其中的MessageParcel对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：反序列化成功，false：反序列化失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
## Parcelable<sup>(9+)</sup>    
在进程间通信（IPC）期间，将类的对象写入MessageSequence并从MessageSequence中恢复它们。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### marshalling<sup>(9+)</sup>    
将此可序列对象封送到MessageSequence中。  
 **调用形式：**     
- marshalling(dataOut: MessageSequence): boolean  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataOut | MessageSequence | true | 可序列对象将被封送到的MessageSequence对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：封送成功，false：封送失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  let result = data.writeParcelable(parcelable);  
  hilog.info(0x0000, 'testTag', 'RpcClient: writeParcelable is ' + result);  
  let ret = new MyParcelable(0, "");  
  let result2 = data.readParcelable(ret);  
  hilog.info(0x0000, 'testTag', 'RpcClient: readParcelable is ' + result2);  
    
```    
  
    
### unmarshalling<sup>(9+)</sup>    
从MessageSequence中解封此可序列对象。  
 **调用形式：**     
- unmarshalling(dataIn: MessageSequence): boolean  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| dataIn | MessageSequence | true | 已将可序列对象封送到其中的MessageSequence对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：反序列化成功，false：反序列化失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  let result = data.writeParcelable(parcelable);  
  hilog.info(0x0000, 'testTag', 'RpcClient: writeParcelable is ' + result);  
  let ret = new MyParcelable(0, "");  
  let result2 = data.readParcelable(ret);  
  hilog.info(0x0000, 'testTag', 'RpcClient: readParcelable is ' + result2);  
    
```    
  
    
## SendRequestResult<sup>(deprecated)</sup>    
发送请求的响应结果。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.rpc.RequestResult替代。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.IPC.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| errCode<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>错误码。 |  
| code<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>消息代码。 |  
| data<sup>(deprecated)</sup> | MessageParcel | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>发送给对端进程的MessageParcel对象。 |  
| reply<sup>(deprecated)</sup> | MessageParcel | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br>对端进程返回的MessageParcel对象。 |  
    
## RequestResult<sup>(9+)</sup>    
发送请求的响应结果。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.IPC.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| errCode<sup>(9+)</sup> | number | false | true | 错误码。 |  
| code<sup>(9+)</sup> | number | false | true | 消息代码。 |  
| data<sup>(9+)</sup> | MessageSequence | false | true | 发送给对端进程的MessageParcel对象。 |  
| reply<sup>(9+)</sup> | MessageSequence | false | true | 对端进程返回的MessageParcel对象。 |  
    
## IRemoteObject<sup>(7+)</sup>    
该接口可用于查询或获取接口描述符、添加或删除死亡通知、转储对象状态到特定文件、发送消息。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### queryLocalInterface<sup>(deprecated)</sup>    
查询接口描述符的字符串。  
 **调用形式：**     
- queryLocalInterface(descriptor: string): IRemoteBroker  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.IRemoteObject#getLocalInterface。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | string | true | 接口描述符的字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteBroker | 返回绑定到指定接口描述符的IRemoteBroker对象。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
      // 方法逻辑需开发者根据业务需要实现  
    }  
    unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number) {  
      // 方法逻辑需开发者根据业务需要实现  
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
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### getLocalInterface<sup>(9+)</sup>    
查询接口描述符的字符串。  
 **调用形式：**     
- getLocalInterface(descriptor: string): IRemoteBroker  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor | string | true | 接口描述符的字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteBroker | 返回绑定到指定接口描述符的IRemoteBroker对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
      // 方法逻辑需开发者根据业务需要实现  
    }  
    unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number) {  
      // 方法逻辑需开发者根据业务需要实现  
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
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### sendRequest<sup>(deprecated)</sup>    
以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。  
 **调用形式：**     
- sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data<sup>(deprecated)</sup> | MessageParcel | true | 保存待发送数据的MessageParcel对象。 |  
| reply<sup>(deprecated)</sup> | MessageParcel | true | 接收应答数据的MessageParcel对象。 |  
| options<sup>(deprecated)</sup> | MessageOption | true | 本次请求的同异步模式，默认同步调用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：发送成功，false：发送失败。 |  
    
### sendRequest<sup>(deprecated)</sup>    
以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。  
 **调用形式：**     
- sendRequest(      code: number,      data: MessageParcel,      reply: MessageParcel,      options: MessageOption    ): Promise\<SendRequestResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.IRemoteObject#sendMessageRequest。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data<sup>(deprecated)</sup> | MessageParcel | true | 保存待发送数据的MessageParcel对象。 |  
| reply<sup>(deprecated)</sup> | MessageParcel | true | 接收应答数据的MessageParcel对象。 |  
| options<sup>(deprecated)</sup> | MessageOption | true | 本次请求的同异步模式，默认同步调用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<SendRequestResult> | 返回一个期约，兑现值是sendRequestResult实例。 |  
    
### sendMessageRequest<sup>(9+)</sup>    
以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。  
 **调用形式：**     
    
- sendMessageRequest(      code: number,      data: MessageSequence,      reply: MessageSequence,      options: MessageOption    ): Promise\<RequestResult>    
起始版本： 9    
- sendMessageRequest(      code: number,      data: MessageSequence,      reply: MessageSequence,      options: MessageOption,      callback: AsyncCallback\<RequestResult>    ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data | MessageSequence | true | 保存待发送数据的MessageSequence对象。 |  
| reply | MessageSequence | true | 接收应答数据的MessageSequence对象。 |  
| options | MessageOption | true | 本次请求的同异步模式，默认同步调用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收发送结果的回调。 |  
| Promise<RequestResult> | 返回一个期约，兑现值是requestResult实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
### sendRequest<sup>(deprecated)</sup>    
以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。  
 **调用形式：**     
- sendRequest(      code: number,      data: MessageParcel,      reply: MessageParcel,      options: MessageOption,      callback: AsyncCallback\<SendRequestResult>    ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.IRemoteObject#sendMessageRequest。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data<sup>(deprecated)</sup> | MessageParcel | true | 保存待发送数据的MessageParcel对象 |  
| reply<sup>(deprecated)</sup> | MessageParcel | true | 接收应答数据的MessageParcel对象。 |  
| options<sup>(deprecated)</sup> | MessageOption | true | 本次请求的同异步模式，默认同步调用。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<SendRequestResult> | true | 接收发送结果的回调。 |  
    
### addDeathRecipient<sup>(deprecated)</sup>    
注册用于接收远程对象死亡通知的回调。如果与RemoteProxy对象匹配的远程对象进程死亡，则调用此方法。  
 **调用形式：**     
- addDeathRecipient(recipient: DeathRecipient, flags: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.IRemoteObject#registerDeathRecipient。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| recipient<sup>(deprecated)</sup> | DeathRecipient | true | 要注册的回调。 |  
| flags<sup>(deprecated)</sup> | number | true | 死亡通知标志。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：回调注册成功，false：回调注册失败。 |  
    
### registerDeathRecipient<sup>(9+)</sup>    
注册用于接收远程对象死亡通知的回调。如果与RemoteProxy对象匹配的远程对象进程死亡，则调用此方法。  
 **调用形式：**     
- registerDeathRecipient(recipient: DeathRecipient, flags: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| recipient | DeathRecipient | true | 要注册的回调。 |  
| flags | number | true | 死亡通知标志。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900008 | proxy or remote object is invalid |  
    
### removeDeathRecipient<sup>(deprecated)</sup>    
注销用于接收远程对象死亡通知的回调。  
 **调用形式：**     
- removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.IRemoteObject#unregisterDeathRecipient。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| recipient<sup>(deprecated)</sup> | DeathRecipient | true | 要注销的死亡回调。 |  
| flags<sup>(deprecated)</sup> | number | true | 死亡通知标志。保留参数。设置为0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：回调注销成功，false：回调注销失败。 |  
    
### unregisterDeathRecipient<sup>(9+)</sup>    
注销用于接收远程对象死亡通知的回调。  
 **调用形式：**     
- unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| recipient | DeathRecipient | true | 要注销的回调。 |  
| flags | number | true | 死亡通知标志。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900008 | proxy or remote object is invalid |  
    
### getInterfaceDescriptor<sup>(deprecated)</sup>    
查询当前代理对象接口的描述符。  
 **调用形式：**     
- getInterfaceDescriptor(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.IRemoteObject#getDescriptor。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 当前的接口描述符。 |  
    
### getDescriptor<sup>(9+)</sup>    
获取对象的接口描述符。接口描述符为字符串。  
 **调用形式：**     
- getDescriptor(): string  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回接口描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900008 | proxy or remote object is invalid |  
    
### isObjectDead<sup>(7+)</sup>    
检查当前对象是否死亡。  
 **调用形式：**     
- isObjectDead(): boolean  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：对象死亡，false：对象未死亡。 |  
    
## IRemoteBroker<sup>(7+)</sup>    
远端对象的代理持有者。用于获取代理对象。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### asObject<sup>(7+)</sup>    
需派生类实现，获取代理或远端对象。  
 **调用形式：**     
- asObject(): IRemoteObject  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteObject | 如果调用者是RemoteObject对象，则直接返回本身；如果调用者是[RemoteProxy](#remoteproxy)对象，则返回它的持有者[IRemoteObject](#iremoteobject)。 |  
    
 **示例代码：**   
```ts    
class TestAbility extends rpc.RemoteObject {  
    asObject() {  
      return this;  
    }  
  }  
  let remoteObject = new TestAbility("testObject").asObject();  
    
```    
  
    
## DeathRecipient<sup>(7+)</sup>    
用于订阅远端对象的死亡通知。当被订阅该通知的远端对象死亡时，本端可收到消息，调用[onRemoteDied](#onremotedied)接口。远端对象死亡可以为远端对象所在进程死亡，远端对象所在设备关机或重启，当远端对象与本端对象属于不同设备时，也可为远端对象离开组网时。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### onRemoteDied<sup>(7+)</sup>    
在成功添加死亡通知订阅后，当远端对象死亡时，将自动调用本方法。  
 **调用形式：**     
- onRemoteDied(): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class MyDeathRecipient implements rpc.DeathRecipient {  
    onRemoteDied() {  
      hilog.info(0x0000, 'testTag', 'server died');  
    }  
  }  
    
```    
  
    
## MessageOption<sup>(7+)</sup>    
公共消息选项（int标志，int等待时间），使用标志中指定的标志构造指定的MessageOption对象。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.IPC.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| TF_SYNC<sup>(7+)</sup> | number | false | true | 同步调用标识。 |  
| TF_ASYNC<sup>(7+)</sup> | number | false | true | 异步调用标识。 |  
| TF_ACCEPT_FDS<sup>(7+)</sup> | number | false | true | 指示sendMessageRequest<sup>9+</sup>接口可以返回文件描述符。 |  
| TF_WAIT_TIME<sup>(7+)</sup> | number | false | true | 默认等待时间(单位/秒)。 |  
    
### getFlags<sup>(7+)</sup>    
获取同步调用或异步调用标志。  
 **调用形式：**     
- getFlags(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 调用成功返回同步调用或异步调用标志。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### setFlags<sup>(7+)</sup>    
设置同步调用或异步调用标志。  
 **调用形式：**     
- setFlags(flags: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| flags | number | true | 同步调用或异步调用标志。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### isAsync<sup>(9+)</sup>    
获取SendMessageRequest调用中确定同步或是异步的标志。  
 **调用形式：**     
- isAsync(): boolean  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：异步调用成功，false：同步调用成功。 |  
    
 **示例代码：**   
```ts    
let option = new rpc.MessageOption();  option.isAsync();    
```    
  
    
### setAsync<sup>(9+)</sup>    
设置SendMessageRequest调用中确定同步或是异步的标志。  
 **调用形式：**     
- setAsync(async: boolean): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| async | boolean | true | true：表示异步调用标志，false：表示同步调用标志。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let option = new rpc.MessageOption();  option.setAsync(true);  hilog.info(0x0000, 'testTag', 'Set asynchronization flag');    
```    
  
    
### getWaitTime<sup>(7+)</sup>    
获取rpc调用的最长等待时间。  
 **调用形式：**     
- getWaitTime(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | rpc最长等待时间。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### setWaitTime<sup>(7+)</sup>    
设置rpc调用最长等待时间。  
 **调用形式：**     
- setWaitTime(waitTime: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| waitTime | number | true | rpc调用最长等待时间。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  try {  
    let option = new rpc.MessageOption();  
    option.setWaitTime(16);  
    let time = option.getWaitTime();  
    hilog.info(0x0000, 'testTag', 'run getWaitTime success, time is ' + time);  
  } catch (error) {  
    hilog.error(0x0000, 'testTag', 'error ' + error);  
  }  
    
```    
  
    
## RemoteObject<sup>(7+)</sup>    
实现远程对象。服务提供者必须继承此类。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### queryLocalInterface<sup>(deprecated)</sup>    
查询并获取当前接口描述符对应的远端对象是否已经存在。  
 **调用形式：**     
- queryLocalInterface(descriptor: string): IRemoteBroker  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteObject#getLocalInterface。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor<sup>(deprecated)</sup> | string | true | 需要查询的接口描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteBroker | 如果接口描述符对应的远端对象存在，则返回该远端对象，否则返回Null。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### getLocalInterface<sup>(9+)</sup>    
查询接口描述符的字符串。  
 **调用形式：**     
- getLocalInterface(descriptor: string): IRemoteBroker  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| descriptor | string | true | 接口描述符的字符串。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteBroker | 返回绑定到指定接口描述符的IRemoteBroker对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```null    
import hilog from '@ohos.hilog';  
import { BusinessError } from '@ohos.base';  
  
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
    // 方法逻辑需开发者根据业务需要实现  
  }  
  unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number) {  
    // 方法逻辑需开发者根据业务需要实现  
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
} catch(error) {  
  let e: BusinessError = error as BusinessError;  
  hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorCode ' + e.code);  
  hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorMessage ' + e.message);  
}  
    
```    
  
    
### getInterfaceDescriptor<sup>(deprecated)</sup>    
获取对象的接口描述符，接口描述符为字符串。  
 **调用形式：**     
- getInterfaceDescriptor(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteObject#getDescriptor。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回接口描述符。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### getDescriptor<sup>(9+)</sup>    
获取对象的接口描述符。接口描述符为字符串。  
 **调用形式：**     
- getDescriptor(): string  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回接口描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900008 | proxy or remote object is invalid |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
import { BusinessError } from '@ohos.base';  
  
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
    // 方法逻辑需开发者根据业务需要实现  
  }  
  unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number) {  
    // 方法逻辑需开发者根据业务需要实现  
  }  
  isObjectDead(): boolean {  
    return false;  
  }  
}  
let testRemoteObject = new TestRemoteObject("testObject");  
try {  
  let descriptor = testRemoteObject.getDescriptor();  
  hilog.info(0x0000, 'testTag', 'RpcServer: descriptor is ' + descriptor);  
} catch(error) {  
  let e: BusinessError = error as BusinessError;  
  hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorCode ' + e.code);  
  hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorMessage ' + e.message);  
}  
    
```    
  
    
### onRemoteMessageRequest<sup>(9+)</sup>    
sendMessageRequest请求的响应处理函数，服务端在该函数里同步或异步地处理请求，回复结果。  
 **调用形式：**     
    
- onRemoteMessageRequest(      code: number,      data: MessageSequence,      reply: MessageSequence,      options: MessageOption    ): boolean | Promise\<boolean>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code | number | true | 对端发送的服务请求码。 |  
| data | MessageSequence | true | 携带客户端调用参数的MessageSequence对象。 |  
| reply | MessageSequence | true | 写入结果的MessageSequence对象。 |  
| options | MessageOption | true | 指示操作是同步还是异步。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| boolean | Promise<boolean> | 若在onRemoteMessageRequest中同步地处理请求，则返回一个布尔值：true：操作成功，false：操作失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### onRemoteRequest<sup>(deprecated)</sup>    
sendRequest请求的响应处理函数，服务端在该函数里处理请求，回复结果。  
 **调用形式：**     
- onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteObject#onRemoteMessageRequest。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 对端发送的服务请求码。 |  
| data<sup>(deprecated)</sup> | MessageParcel | true | 携带客户端调用参数的MessageParcel对象。 |  
| reply<sup>(deprecated)</sup> | MessageParcel | true | 写入结果的MessageParcel对象。 |  
| options<sup>(deprecated)</sup> | MessageOption | true | 指示操作是同步还是异步。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：操作成功，false：操作失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### sendRequest<sup>(deprecated)</sup>    
以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。  
 **调用形式：**     
- sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data<sup>(deprecated)</sup> | MessageParcel | true | 保存待发送数据的MessageParcel对象。 |  
| reply<sup>(deprecated)</sup> | MessageParcel | true | 接收应答数据的MessageParcel对象。 |  
| options<sup>(deprecated)</sup> | MessageOption | true | 本次请求的同异步模式，默认同步调用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：发送成功，false：发送失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### sendRequest<sup>(deprecated)</sup>    
以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。  
 **调用形式：**     
- sendRequest(      code: number,      data: MessageParcel,      reply: MessageParcel,      options: MessageOption    ): Promise\<SendRequestResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteObject#sendMessageRequest。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data<sup>(deprecated)</sup> | MessageParcel | true | 保存待发送数据的MessageParcel对象。 |  
| reply<sup>(deprecated)</sup> | MessageParcel | true | 接收应答数据的MessageParcel对象。   |  
| options<sup>(deprecated)</sup> | MessageOption | true | 本次请求的同异步模式，默认同步调用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<SendRequestResult> | 返回一个期约，兑现值是sendRequestResult实例。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
    
```    
  
    
### sendMessageRequest<sup>(9+)</sup>    
以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendMessageRequest返回时收到回调，回复内容在reply报文里。  
 **调用形式：**     
    
- sendMessageRequest(      code: number,      data: MessageSequence,      reply: MessageSequence,      options: MessageOption    ): Promise\<RequestResult>    
起始版本： 9    
- sendMessageRequest(      code: number,      data: MessageSequence,      reply: MessageSequence,      options: MessageOption,      callback: AsyncCallback\<RequestResult>    ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data | MessageSequence | true | 保存待发送数据的MessageSequence对象。 |  
| reply | MessageSequence | true | 接收应答数据的MessageSequence对象。 |  
| options | MessageOption | true | 本次请求的同异步模式，默认同步调用。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收发送结果的回调。 |  
| Promise<RequestResult> | 返回一个期约，兑现值是requestResult实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import hilog from '@ohos.hilog';  
import { BusinessError } from '@ohos.base';  
  
class TestRemoteObject extends rpc.RemoteObject {  
  constructor(descriptor: string) {  
    super(descriptor);  
  }  
}  
function sendRequestCallback(err: BusinessError, result: rpc.RequestResult) {  
  if (result.errCode === 0) {  
    hilog.info(0x0000, 'testTag', 'sendRequest got result');  
    result.reply.readException();  
    let msg = result.reply.readString();  
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
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import hilog from '@ohos.hilog';  
  
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
      result.reply.readException();  
      let msg = result.reply.readString();  
      hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);  
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
    
```    
  
    
### sendRequest<sup>(deprecated)</sup>    
以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。  
 **调用形式：**     
- sendRequest(      code: number,      data: MessageParcel,      reply: MessageParcel,      options: MessageOption,      callback: AsyncCallback\<SendRequestResult>    ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteObject#sendMessageRequest。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data<sup>(deprecated)</sup> | MessageParcel | true | 保存待发送数据的MessageParcel对象。 |  
| reply<sup>(deprecated)</sup> | MessageParcel | true | 接收应答数据的MessageParcel对象。 |  
| options<sup>(deprecated)</sup> | MessageOption | true | 本次请求的同异步模式，默认同步调用。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<SendRequestResult> | true | 接收发送结果的回调。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
import { BusinessError } from '@ohos.base';  
  
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
    result.reply.readException();  
    let msg = result.reply.readString();  
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
  
    
### getCallingPid<sup>(7+)</sup>    
获取通信对端的进程Pid。  
 **调用形式：**     
- getCallingPid(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回通信对端的进程Pid。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
class TestRemoteObject extends rpc.RemoteObject {  
  constructor(descriptor: string) {  
    super(descriptor);  
  }  
}  
let testRemoteObject = new TestRemoteObject("testObject");  
hilog.info(0x0000, 'testTag', 'RpcServer: getCallingUid: ' + testRemoteObject.getCallingUid());  
    
```    
  
    
### getCallingUid<sup>(7+)</sup>    
获取通信对端的进程Uid。  
 **调用形式：**     
- getCallingUid(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回通信对端的进程Uid。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class TestRemoteObject extends rpc.RemoteObject {  
    constructor(descriptor: string) {  
      super(descriptor);  
    }  
  }  
  let testRemoteObject = new TestRemoteObject("testObject");  
  hilog.info(0x0000, 'testTag', 'RpcServer: getCallingUid: ' + testRemoteObject.getCallingUid());  
    
```    
  
    
### attachLocalInterface<sup>(deprecated)</sup>    
此接口用于把接口描述符和IRemoteBroker对象绑定。  
 **调用形式：**     
- attachLocalInterface(localInterface: IRemoteBroker, descriptor: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteObject#modifyLocalInterface。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localInterface<sup>(deprecated)</sup> | IRemoteBroker | true | 将与描述符绑定的IRemoteBroker对象。 |  
| descriptor<sup>(deprecated)</sup> | string | true | 用于与IRemoteBroker对象绑定的描述符。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
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
      } catch(error) {  
        let e: BusinessError = error as BusinessError;  
        hilog.error(0x0000, 'testTag', ' rpc attach local interface fail, errorCode ' + e.code);  
        hilog.error(0x0000, 'testTag', ' rpc attach local interface fail, errorMessage ' + e.message);  
      }  
    }  
    registerDeathRecipient(recipient: MyDeathRecipient, flags: number) {  
      // 方法逻辑需开发者根据业务需要实现  
    }  
    unregisterDeathRecipient(recipient: MyDeathRecipient, flags: number) {  
      // 方法逻辑需开发者根据业务需要实现  
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
  
    
### modifyLocalInterface<sup>(9+)</sup>    
此接口用于把接口描述符和IRemoteBroker对象绑定。  
 **调用形式：**     
- modifyLocalInterface(localInterface: IRemoteBroker, descriptor: string): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| localInterface | IRemoteBroker | true | 将与描述符绑定的IRemoteBroker对象。 |  
| descriptor | string | true | 用于与IRemoteBroker对象绑定的描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
## RemoteProxy<sup>(7+)</sup>    
实现IRemoteObject代理对象。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.IPC.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| PING_TRANSACTION<sup>(7+)</sup> | number | false | true | 内部指令码，用于测试IPC服务正常。 |  
| DUMP_TRANSACTION<sup>(7+)</sup> | number | false | true | 内部指令码，获取Binder内部状态。 |  
| INTERFACE_TRANSACTION<sup>(7+)</sup> | number | false | true | 内部指令码，获取对端接口描述符。 |  
| MIN_TRANSACTION_ID<sup>(7+)</sup> | number | false | true | 最小有效指令码。 |  
| MAX_TRANSACTION_ID<sup>(7+)</sup> | number | false | true | 最大有效指令码。 |  
    
### queryLocalInterface<sup>(deprecated)</sup>    
查询并获取当前接口描述符对应的本地接口对象。  
 **调用形式：**     
- queryLocalInterface(interface: string): IRemoteBroker  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteProxy#getLocalInterface。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| interface<sup>(deprecated)</sup> | string | true | 需要查询的接口描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteBroker | 默认返回Null，标识该接口是一个代理侧接口。 |  
    
 **示例代码：**   
)  
```ts    
import hilog from '@ohos.hilog';  
  
let broker: rpc.IRemoteBroker  = proxy.queryLocalInterface("testObject");  
hilog.info(0x0000, 'testTag', 'RpcClient: queryLocalInterface is ' + broker);    
```    
  
    
### getLocalInterface<sup>(9+)</sup>    
查询并获取当前接口描述符对应的本地接口对象。  
 **调用形式：**     
- getLocalInterface(interface: string): IRemoteBroker  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| interface | string | true | 需要查询的接口描述符。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteBroker | 默认返回Null，标识该接口是一个代理侧接口。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900006 | only remote object permitted |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
import { BusinessError } from '@ohos.base';  
  
try {  
  let broker: rpc.IRemoteBroker = proxy.getLocalInterface("testObject");  
  hilog.info(0x0000, 'testTag', 'RpcClient: getLocalInterface is ' + broker);  
} catch(error) {  
  let e: BusinessError = error as BusinessError;  
  hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorCode ' + e.code);  
  hilog.error(0x0000, 'testTag', 'rpc get local interface fail, errorMessage ' + e.message);  
}  
    
```    
  
    
### addDeathRecipient<sup>(deprecated)</sup>    
注册用于接收远程对象死亡通知的回调，增加proxy对象上的死亡通知。  
 **调用形式：**     
- addDeathRecipient(recipient: DeathRecipient, flags: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteProxy#registerDeathRecipient。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| recipient<sup>(deprecated)</sup> | DeathRecipient | true | 收件人表示要注册的回调。 |  
| flags<sup>(deprecated)</sup> | number | true | 死亡通知标志。保留参数。设置为0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：回调注册成功，false：回调注册失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
class MyDeathRecipient implements rpc.DeathRecipient {  
  onRemoteDied() {  
    hilog.info(0x0000, 'testTag', 'server died');  
  }  
}  
let deathRecipient = new MyDeathRecipient();  
proxy.addDeathRecipient(deathRecipient, 0);  
    
```    
  
    
### registerDeathRecipient<sup>(9+)</sup>    
注册用于接收远程对象死亡通知的回调。如果与RemoteProxy对象匹配的远程对象进程死亡，则调用此方法。  
 **调用形式：**     
- registerDeathRecipient(recipient: DeathRecipient, flags: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| recipient | DeathRecipient | true | 要注册的回调。 |  
| flags | number | true | 死亡通知标志。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900008 | proxy or remote object is invalid |  
    
 **示例代码：**   
```null    
import hilog from '@ohos.hilog';  
import { BusinessError } from '@ohos.base';  
  
class MyDeathRecipient implements rpc.DeathRecipient {  
  onRemoteDied() {  
    hilog.info(0x0000, 'testTag', 'server died');  
  }  
}  
let deathRecipient = new MyDeathRecipient();  
try {  
  proxy.registerDeathRecipient(deathRecipient, 0);  
} catch(error) {  
  let e: BusinessError = error as BusinessError;  
  hilog.error(0x0000, 'testTag', 'proxy register deathRecipient fail, errorCode ' + e.code);  
  hilog.error(0x0000, 'testTag', 'proxy register deathRecipient fail, errorMessage ' + e.message);  
}  
    
```    
  
    
### removeDeathRecipient<sup>(deprecated)</sup>    
注销用于接收远程对象死亡通知的回调。  
 **调用形式：**     
- removeDeathRecipient(recipient: DeathRecipient, flags: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteProxy#unregisterDeathRecipient。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| recipient<sup>(deprecated)</sup> | DeathRecipient | true | 要注销的死亡回调。 |  
| flags<sup>(deprecated)</sup> | number | true | 死亡通知标志。保留参数。设置为0。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：回调注销成功，false：回调注销失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
class MyDeathRecipient implements rpc.DeathRecipient {  
  onRemoteDied() {  
    hilog.info(0x0000, 'testTag', 'server died');  
  }  
}  
let deathRecipient = new MyDeathRecipient();  
proxy.addDeathRecipient(deathRecipient, 0);  
proxy.removeDeathRecipient(deathRecipient, 0);  
    
```    
  
    
### unregisterDeathRecipient<sup>(9+)</sup>    
注销用于接收远程对象死亡通知的回调。  
 **调用形式：**     
- unregisterDeathRecipient(recipient: DeathRecipient, flags: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| recipient | DeathRecipient | true | 要注销的回调。 |  
| flags | number | true | 死亡通知标志。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900008 | proxy or remote object is invalid |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
import { BusinessError } from '@ohos.base';  
  
class MyDeathRecipient implements rpc.DeathRecipient {  
  onRemoteDied() {  
    hilog.info(0x0000, 'testTag', 'server died');  
  }  
}  
let deathRecipient = new MyDeathRecipient();  
try {  
  proxy.registerDeathRecipient(deathRecipient, 0);  
  proxy.unregisterDeathRecipient(deathRecipient, 0);  
} catch(error) {  
  let e: BusinessError = error as BusinessError;  
  hilog.error(0x0000, 'testTag', 'proxy unregister deathRecipient fail, errorCode ' + e.code);  
  hilog.error(0x0000, 'testTag', 'proxy unregister deathRecipient fail, errorMessage ' + e.message);  
}  
    
```    
  
    
### getInterfaceDescriptor<sup>(deprecated)</sup>    
查询当前代理对象接口的描述符。  
 **调用形式：**     
- getInterfaceDescriptor(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteProxy#getDescriptor。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 当前的接口描述符。 |  
    
### getDescriptor<sup>(9+)</sup>    
获取对象的接口描述符，接口描述符为字符串。  
 **调用形式：**     
- getDescriptor(): string  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回接口描述符。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900007 | proxy or remote object is invalid |  
| 1900008 | communication failed |  
    
### sendRequest<sup>(deprecated)</sup>    
以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。  
 **调用形式：**     
- sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean  
  
 **废弃说明：** 从API version 8 开始废弃。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data<sup>(deprecated)</sup> | MessageParcel | true | 保存待发送数据的MessageParcel对象。 |  
| reply<sup>(deprecated)</sup> | MessageParcel | true | 接收应答数据的MessageParcel对象。  |  
| options<sup>(deprecated)</sup> | MessageOption | true | 本次请求的同异步模式，默认同步调用。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：发送成功，false：发送失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
let option = new rpc.MessageOption();  
let data = rpc.MessageParcel.create();  
let reply = rpc.MessageParcel.create();  
data.writeInt(1);  
data.writeString("hello");  
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
    
```    
  
    
### sendRequest<sup>(deprecated)</sup>    
以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendRequest返回时兑现，回复内容在reply报文里。  
 **调用形式：**     
- sendRequest(      code: number,      data: MessageParcel,      reply: MessageParcel,      options: MessageOption    ): Promise\<SendRequestResult>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteProxy#sendMessageRequest。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data<sup>(deprecated)</sup> | MessageParcel | true | 保存待发送数据的MessageParcel对象。 |  
| reply<sup>(deprecated)</sup> | MessageParcel | true | 接收应答数据的MessageParcel对象。 |  
| options<sup>(deprecated)</sup> | MessageOption | true | 本次请求的同异步模式，默认同步调用。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<SendRequestResult> | 返回一个期约，兑现值是sendRequestResult实例。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
let option = new rpc.MessageOption();  
let data = rpc.MessageParcel.create();  
let reply = rpc.MessageParcel.create();  
data.writeInt(1);  
data.writeString("hello");  
proxy.sendRequest(1, data, reply, option)  
  .then((result: rpc.SendRequestResult) => {  
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
    
```    
  
    
### sendMessageRequest<sup>(9+)</sup>    
以同步或异步方式向对端进程发送MessageSequence消息。如果为选项设置了异步模式，则期约立即兑现，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则期约将在sendMessageRequest返回时兑现，回复内容在reply报文里。  
 **调用形式：**     
    
- sendMessageRequest(      code: number,      data: MessageSequence,      reply: MessageSequence,      options: MessageOption    ): Promise\<RequestResult>    
起始版本： 9    
- sendMessageRequest(      code: number,      data: MessageSequence,      reply: MessageSequence,      options: MessageOption,      callback: AsyncCallback\<RequestResult>    ): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data | MessageSequence | true | 保存待发送数据的MessageSequence对象。 |  
| reply | MessageSequence | true | 接收应答数据的MessageSequence对象。 |  
| options | MessageOption | true | 本次请求的同异步模式，默认同步调用。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback |  |  
| Promise<RequestResult> | 返回一个期约，兑现值是requestResult实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```ts    
import hilog from '@ohos.hilog';  
import { BusinessError } from '@ohos.base';  
  
let option = new rpc.MessageOption();  
let data = rpc.MessageSequence.create();  
let reply = rpc.MessageSequence.create();  
data.writeInt(1);  
data.writeString("hello");  
try {  
  proxy.sendMessageRequest(1, data, reply, option, sendMessageRequestCallback);  
} catch(error) {  
  let e: BusinessError = error as BusinessError;  
  hilog.error(0x0000, 'testTag', 'rpc sendMessageRequest fail, errorCode ' + e.code);  
  hilog.error(0x0000, 'testTag', 'rpc sendMessageRequest fail, errorMessage ' + e.message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```ts    
import hilog from '@ohos.hilog';  
  
let option = new rpc.MessageOption();  
let data = rpc.MessageSequence.create();  
let reply = rpc.MessageSequence.create();  
data.writeInt(1);  
data.writeString("hello");  
proxy.sendMessageRequest(1, data, reply, option)  
  .then((result: rpc.RequestResult) => {  
    if (result.errCode === 0) {  
      hilog.info(0x0000, 'testTag', 'sendMessageRequest got result');  
      result.reply.readException();  
      let msg = result.reply.readString();  
      hilog.info(0x0000, 'testTag', 'RPCTest: reply msg: ' + msg);  
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
    
```    
  
    
### sendRequest<sup>(deprecated)</sup>    
以同步或异步方式向对端进程发送MessageParcel消息。如果为选项设置了异步模式，则立即收到回调，reply报文里没有内容，具体回复需要在业务侧的回调中获取。如果为选项设置了同步模式，则将在sendRequest返回时收到回调，回复内容在reply报文里。  
 **调用形式：**     
- sendRequest(      code: number,      data: MessageParcel,      reply: MessageParcel,      options: MessageOption,      callback: AsyncCallback\<SendRequestResult>    ): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.RemoteProxy#sendMessageRequest。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| code<sup>(deprecated)</sup> | number | true | 本次请求调用的消息码（1-16777215），由通信双方确定。如果接口由IDL工具生成，则消息代码由IDL自动生成。 |  
| data<sup>(deprecated)</sup> | MessageParcel | true | 保存待发送数据的MessageSequence对象。 |  
| reply<sup>(deprecated)</sup> | MessageParcel | true | 接收应答数据的MessageSequence对象。 |  
| options<sup>(deprecated)</sup> | MessageOption | true | 本次请求的同异步模式，默认同步调用。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<SendRequestResult> | true | 接收发送结果的回调。     |  
    
 **示例代码：**   
```ts    
let option = new rpc.MessageOption();  
let data = rpc.MessageParcel.create();  
let reply = rpc.MessageParcel.create();  
data.writeInt(1);  
data.writeString("hello");  
proxy.sendRequest(1, data, reply, option, sendRequestCallback);    
```    
  
    
### isObjectDead<sup>(7+)</sup>    
检查当前对象是否死亡。  
 **调用形式：**     
- isObjectDead(): boolean  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：对应的对象已经死亡，false：对应的对象未死亡 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
let isDead: boolean = proxy.isObjectDead();  
hilog.info(0x0000, 'testTag', 'RpcClient: isObjectDead is ' + isDead);    
```    
  
    
## IPCSkeleton<sup>(7+)</sup>    
用于获取IPC上下文信息，包括获取UID和PID、获取本端和对端设备ID、检查接口调用是否在同一设备上。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### getContextObject<sup>(7+)</sup>    
静态方法，获取系统能力的管理者。  
 **调用形式：**     
- static getContextObject(): IRemoteObject  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IRemoteObject | 返回系统能力管理者。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let samgr = rpc.IPCSkeleton.getContextObject();  hilog.info(0x0000, 'testTag', 'RpcServer: getContextObject result: ' + samgr);    
```    
  
    
### getCallingPid<sup>(7+)</sup>    
静态方法，获取调用者的PID。此方法由RemoteObject对象在onRemoteRequest方法中调用，不在IPC上下文环境（onRemoteRequest）中调用则返回本进程的PID。  
 **调用形式：**     
- static getCallingPid(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回调用者的PID。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
      let callerPid = rpc.IPCSkeleton.getCallingPid();  
      hilog.info(0x0000, 'testTag', 'RpcServer: getCallingPid result: ' + callerPid);  
      return true;  
    }  
 }  
    
```    
  
    
### getCallingUid<sup>(7+)</sup>    
静态方法，获取调用者的UID。此方法由RemoteObject对象在onRemoteRequest方法中调用，不在IPC上下文环境（onRemoteRequest）中调用则返回本进程的UID。  
 **调用形式：**     
- static getCallingUid(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回调用者的UID。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
      let callerUid = rpc.IPCSkeleton.getCallingUid();  
      hilog.info(0x0000, 'testTag', 'RpcServer: getCallingUid result: ' + callerUid);  
      return true;  
    }  
  }  
    
```    
  
    
### getCallingTokenId<sup>(8+)</sup>    
静态方法，获取调用者的TokenId，用于被调用方对调用方的身份校验。  
 **调用形式：**     
- static getCallingTokenId(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回调用者的TokenId。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
      let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();  
      hilog.info(0x0000, 'testTag', 'RpcServer: getCallingTokenId result: ' + callerTokenId);  
      return true;  
    }  
  }  
    
```    
  
    
### getCallingDeviceID<sup>(7+)</sup>    
静态方法，获取调用者进程所在的设备ID。  
 **调用形式：**     
- static getCallingDeviceID(): string  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回调用者进程所在的设备ID。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
      let callerDeviceID = rpc.IPCSkeleton.getCallingDeviceID();  
      hilog.info(0x0000, 'testTag', 'RpcServer: callerDeviceID is ' + callerDeviceID);  
      return true;  
    }  
  }  
    
```    
  
    
### getLocalDeviceID<sup>(7+)</sup>    
静态方法，获取本端设备ID。  
 **调用形式：**     
- static getLocalDeviceID(): string  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回本地设备的ID。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
      let localDeviceID = rpc.IPCSkeleton.getLocalDeviceID();  
      hilog.info(0x0000, 'testTag', 'RpcServer: localDeviceID is ' + localDeviceID);  
      return true;  
    }  
  }  
    
```    
  
    
### isLocalCalling<sup>(7+)</sup>    
静态方法，检查当前通信对端是否是本设备的进程。  
 **调用形式：**     
- static isLocalCalling(): boolean  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：调用在同一台设备，false：调用未在同一台设备。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
      let isLocalCalling = rpc.IPCSkeleton.isLocalCalling();  
      hilog.info(0x0000, 'testTag', 'RpcServer: isLocalCalling is ' + isLocalCalling);  
      return true;  
    }  
  }  
    
```    
  
    
### flushCommands<sup>(deprecated)</sup>    
静态方法，将所有挂起的命令从指定的RemoteProxy刷新到相应的RemoteObject。建议在任何时间执行敏感操作之前调用此方法。  
 **调用形式：**     
- static flushCommands(object: IRemoteObject): number  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.IPCSkeleton#flushCmdBuffer。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| object<sup>(deprecated)</sup> | IRemoteObject | true | 指定的RemoteProxy。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 如果操作成功，返回0；如果输入对象为空或RemoteObject，或者操作失败，返回错误代码。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
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
  
    
### flushCmdBuffer<sup>(9+)</sup>    
静态方法，将所有挂起的命令从指定的RemoteProxy刷新到相应的RemoteObject。建议在任何时间执行敏感操作之前调用此方法。  
 **调用形式：**     
- static flushCmdBuffer(object: IRemoteObject): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| object | IRemoteObject | true | 指定的RemoteProxy。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  class TestRemoteObject extends rpc.RemoteObject {  
    constructor(descriptor: string) {  
      super(descriptor);  
    }  
  }  
  let remoteObject = new TestRemoteObject("aaa");  
  try {  
    rpc.IPCSkeleton.flushCmdBuffer(remoteObject);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'proxy flushCmdBuffer fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'proxy flushCmdBuffer fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### resetCallingIdentity<sup>(7+)</sup>    
静态方法，将远程用户的UID和PID替换为本地用户的UID和PID。它可以用于身份验证等场景。  
 **调用形式：**     
- static resetCallingIdentity(): string  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回包含远程用户的UID和PID的字符串。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
      let callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();  
      hilog.info(0x0000, 'testTag', 'RpcServer: callingIdentity is ' + callingIdentity);  
      return true;  
    }  
  }  
    
```    
  
    
### setCallingIdentity<sup>(deprecated)</sup>    
静态方法，将UID和PID恢复为远程用户的UID和PID。它通常在使用resetCallingIdentity后调用，需要resetCallingIdentity返回的远程用户的UID和PID。  
 **调用形式：**     
- static setCallingIdentity(identity: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.IPCSkeleton#restoreCallingIdentity。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| identity<sup>(deprecated)</sup> | string | true | 标识表示包含远程用户UID和PID的字符串。由resetCallingIdentity返回。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：设置成功，false：设置失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
      let callingIdentity: rpc.IPCSkeleton | undefined = undefined;  
      try {  
        callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();  
        hilog.info(0x0000, 'testTag', 'RpcServer: callingIdentity is ' + callingIdentity);  
      } finally {  
        let ret = rpc.IPCSkeleton.setCallingIdentity("callingIdentity ");  
        hilog.info(0x0000, 'testTag', 'RpcServer: setCallingIdentity is ' + ret);  
      }  
      return true;  
    }  
  }  
    
```    
  
    
### restoreCallingIdentity<sup>(9+)</sup>    
静态方法，将UID和PID恢复为远程用户的UID和PID。它通常在使用resetCallingIdentity后调用，需要resetCallingIdentity返回的远程用户的UID和PID。  
 **调用形式：**     
- static restoreCallingIdentity(identity: string): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| identity | string | true | 标识表示包含远程用户UID和PID的字符串。由resetCallingIdentity返回。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  
  class Stub extends rpc.RemoteObject {  
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {  
      let callingIdentity: rpc.IPCSkeleton | undefined = undefined;  
      try {  
        callingIdentity = rpc.IPCSkeleton.resetCallingIdentity();  
        hilog.info(0x0000, 'testTag', 'RpcServer: callingIdentity is ' + callingIdentity);  
      } finally {  
        rpc.IPCSkeleton.restoreCallingIdentity(callingIdentity);  
      }  
      return true;  
    }  
  }  
    
```    
  
    
## Ashmem<sup>(8+)</sup>    
提供与匿名共享内存对象相关的方法，包括创建、关闭、映射和取消映射Ashmem、从Ashmem读取数据和写入数据、获取Ashmem大小、设置Ashmem保护。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
### 属性    
 **系统能力:**  SystemCapability.Communication.IPC.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| PROT_EXEC<sup>(8+)</sup> | number | false | true | 映射的内存可执行 |  
| PROT_NONE<sup>(8+)</sup> | number | false | true | 映射的内存不可访问 |  
| PROT_READ<sup>(8+)</sup> | number | false | true | 映射的内存可读 |  
| PROT_WRITE<sup>(8+)</sup> | number | false | true | 映射的内存可写 |  
    
### createAshmem<sup>(deprecated)</sup>    
静态方法，根据指定的名称和大小创建Ashmem对象。  
 **调用形式：**     
- static createAshmem(name: string, size: number): Ashmem  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.Ashmem#create。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 名称，用于查询Ashmem信息。 |  
| size<sup>(deprecated)</sup> | number | true | Ashmem的大小，以字节为单位。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Ashmem | 返回创建的Ashmem对象；如果创建失败，返回null。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let ashmem: rpc.Ashmem | undefined = undefined;  
  try {  
    ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  
    let size = ashmem.getAshmemSize();  
    hilog.info(0x0000, 'testTag', 'RpcTest: get ashemm by create: ' + ashmem + ' size is ' + size);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc creat ashmem fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc creat ashmem  fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### create<sup>(9+)</sup>    
静态方法，根据指定的名称和大小创建Ashmem对象。  
 **调用形式：**     
- static create(name: string, size: number): Ashmem  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 名称，用于查询Ashmem信息。 |  
| size | number | true | Ashmem的大小，以字节为单位。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Ashmem | 返回创建的Ashmem对象；如果创建失败，返回null。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  try {  
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  
    let ashmem2 = rpc.Ashmem.create(ashmem);  
    let size = ashmem2.getAshmemSize();  
    hilog.info(0x0000, 'testTag', 'RpcTest: get ashemm by create: ' + ashmem2 + ' size is ' + size);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc creat ashmem from existing fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc creat ashmem from existing fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### createAshmemFromExisting<sup>(deprecated)</sup>    
静态方法，通过复制现有Ashmem对象的文件描述符(fd)来创建Ashmem对象。两个Ashmem对象指向同一个共享内存区域。  
 **调用形式：**     
- static createAshmemFromExisting(ashmem: Ashmem): Ashmem  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.Ashmem#create。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ashmem<sup>(deprecated)</sup> | Ashmem | true | 已存在的Ashmem对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Ashmem | 返回创建的Ashmem对象。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);  let ashmem2 = rpc.Ashmem.createAshmemFromExisting(ashmem);  let size = ashmem2.getAshmemSize();  hilog.info(0x0000, 'testTag', 'RpcTest: get ashemm by createAshmemFromExisting: ' + ashmem2 + ' size is ' + size);    
```    
  
    
### create<sup>(9+)</sup>    
静态方法，通过复制现有Ashmem对象的文件描述符(fd)来创建Ashmem对象。两个Ashmem对象指向同一个共享内存区域。  
 **调用形式：**     
- static create(ashmem: Ashmem): Ashmem  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ashmem | Ashmem | true | 已存在的Ashmem对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Ashmem | 返回创建的Ashmem对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  try {  
    let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  
    let ashmem2 = rpc.Ashmem.create(ashmem);  
    let size = ashmem2.getAshmemSize();  
    hilog.info(0x0000, 'testTag', 'RpcTest: get ashemm by create: ' + ashmem2 + ' size is ' + size);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc creat ashmem from existing fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc creat ashmem from existing fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### closeAshmem<sup>(8+)</sup>    
关闭这个Ashmem。  
 **调用形式：**     
- closeAshmem(): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **示例代码：**   
```ts    
 let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  ashmem.closeAshmem();    
```    
  
    
### unmapAshmem<sup>(8+)</sup>    
删除该Ashmem对象的地址映射。  
 **调用形式：**     
- unmapAshmem(): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **示例代码：**   
```ts    
 let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  ashmem.unmapAshmem();    
```    
  
    
### getAshmemSize<sup>(8+)</sup>    
获取Ashmem对象的内存大小。  
 **调用形式：**     
- getAshmemSize(): number  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回Ashmem对象的内存大小。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);  let size = ashmem.getAshmemSize();  hilog.info(0x0000, 'testTag', 'RpcTest: get ashmem is ' + ashmem + ' size is ' + size);    
```    
  
    
### mapAshmem<sup>(deprecated)</sup>    
在此进程的虚拟地址空间上创建共享文件映射，映射区域大小由此Ashmem对象指定。  
 **调用形式：**     
- mapAshmem(mapType: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.Ashmem#mapTypedAshmem。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mapType<sup>(deprecated)</sup> | number | true | 指定映射的内存区域的保护等级。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：映射成功，false：映射失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  
  try {  
    ashmem.mapTypedAshmem(ashmem.PROT_READ | ashmem.PROT_WRITE);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc map ashmem fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc map ashmem fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### mapTypedAshmem<sup>(9+)</sup>    
在此进程的虚拟地址空间上创建共享文件映射，映射区域大小由此Ashmem对象指定。  
 **调用形式：**     
- mapTypedAshmem(mapType: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mapType | number | true | 指定映射的内存区域的保护等级。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900001 | call mmap function failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);  let mapReadAndWrite = ashmem.mapAshmem(ashmem.PROT_READ | ashmem.PROT_WRITE);  hilog.info(0x0000, 'testTag', 'RpcTest: map ashmem result is ' + mapReadAndWrite);    
```    
  
    
### mapReadAndWriteAshmem<sup>(deprecated)</sup>    
在此进程虚拟地址空间上创建可读写的共享文件映射。  
 **调用形式：**     
- mapReadAndWriteAshmem(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.Ashmem#mapReadWriteAshmem。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：映射成功，false：映射失败。 |  
    
 **示例代码：**   
```ts    
 import hilog from '@ohos.hilog';  
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);  let mapResult = ashmem.mapReadAndWriteAshmem();  hilog.info(0x0000, 'testTag', 'RpcTest: map ashmem result is ' + mapResult);    
```    
  
    
### mapReadWriteAshmem<sup>(9+)</sup>    
在此进程虚拟地址空间上创建可读写的共享文件映射。  
 **调用形式：**     
- mapReadWriteAshmem(): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900001 | call mmap function failed |  
    
 **示例代码：**   
```null    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  
  try {  
    ashmem.mapReadWriteAshmem();  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc map read and write ashmem fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc map read and write ashmem fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### mapReadOnlyAshmem<sup>(deprecated)</sup>    
在此进程虚拟地址空间上创建只读的共享文件映射。  
 **调用形式：**     
- mapReadOnlyAshmem(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.Ashmem#mapReadonlyAshmem。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：映射成功，false：映射失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);  let mapResult = ashmem.mapReadOnlyAshmem();  hilog.info(0x0000, 'testTag', 'RpcTest: Ashmem mapReadOnlyAshmem result is ' + mapResult);    
```    
  
    
### mapReadonlyAshmem<sup>(9+)</sup>    
在此进程虚拟地址空间上创建只读的共享文件映射。  
 **调用形式：**     
- mapReadonlyAshmem(): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1900001 | call mmap function failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  
  try {  
    ashmem.mapReadonlyAshmem();  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc map read and write ashmem fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc map read and write ashmem fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### setProtection<sup>(deprecated)</sup>    
设置映射内存区域的保护等级。  
 **调用形式：**     
- setProtection(protectionType: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.Ashmem#setProtectionType。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| protectionType<sup>(deprecated)</sup> | number | true | 要设置的保护类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：设置成功，false：设置失败。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);  let result = ashmem.setProtection(ashmem.PROT_READ);  hilog.info(0x0000, 'testTag', 'RpcTest: Ashmem setProtection result is ' + result);    
```    
  
    
### setProtectionType<sup>(9+)</sup>    
设置映射内存区域的保护等级。  
 **调用形式：**     
- setProtectionType(protectionType: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| protectionType | number | true | 要设置的保护类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900002 | call os ioctl function failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  
  try {  
    ashmem.setProtection(ashmem.PROT_READ);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc set protection type fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc set protection type fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### writeToAshmem<sup>(deprecated)</sup>    
将数据写入此Ashmem对象关联的共享文件。  
 **调用形式：**     
- writeToAshmem(buf: number[], size: number, offset: number): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.Ashmem#writeAshmem。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buf<sup>(deprecated)</sup> | number[] | true | 写入Ashmem对象的数据。 |  
| size<sup>(deprecated)</sup> | number | true | 要写入的数据大小。 |  
| offset<sup>(deprecated)</sup> | number | true | 要写入的数据在此Ashmem对象关联的内存区间的起始位置 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | true：如果数据写入成功，false：在其他情况下，如数据写入越界或未获得写入权限。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024);  let mapResult = ashmem.mapReadAndWriteAshmem();  hilog.info(0x0000, 'testTag', 'RpcTest map ashmem result is ' + mapResult);  let ByteArrayVar = [1, 2, 3, 4, 5];  let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0);  hilog.info(0x0000, 'testTag', 'RpcTest: write to Ashmem result is ' + writeResult);    
```    
  
    
### writeAshmem<sup>(9+)</sup>    
将数据写入此Ashmem对象关联的共享文件。  
 **调用形式：**     
- writeAshmem(buf: number[], size: number, offset: number): void  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| buf | number[] | true | 写入Ashmem对象的数据。 |  
| size | number | true | 要写入的数据大小。 |  
| offset | number | true | 要写入的数据在此Ashmem对象关联的内存区间的起始位置 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900003 | write to ashmem failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  
  ashmem.mapReadWriteAshmem();  
  let ByteArrayVar = [1, 2, 3, 4, 5];  
  try {  
    ashmem.writeAshmem(ByteArrayVar, 5, 0);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc write to ashmem fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc write to ashmem fail, errorMessage ' + e.message);  
  }  
    
```    
  
    
### readFromAshmem<sup>(deprecated)</sup>    
从此Ashmem对象关联的共享文件中读取数据。  
 **调用形式：**     
- readFromAshmem(size: number, offset: number): number[]  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.rpc.Ashmem#readAshmem。  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size<sup>(deprecated)</sup> | number | true | 要读取的数据的大小。 |  
| offset<sup>(deprecated)</sup> | number | true | 要读取的数据在此Ashmem对象关联的内存区间的起始位置 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回读取的数据。 |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
 let ashmem = rpc.Ashmem.createAshmem("ashmem", 1024*1024); let mapResult = ashmem.mapReadAndWriteAshmem(); hilog.info(0x0000, 'testTag', 'RpcTest map ashmem result is ' + mapResult); let ByteArrayVar = [1, 2, 3, 4, 5]; let writeResult = ashmem.writeToAshmem(ByteArrayVar, 5, 0); hilog.info(0x0000, 'testTag', 'RpcTest: write to Ashmem result is ' + writeResult); let readResult = ashmem.readFromAshmem(5, 0); hilog.info(0x0000, 'testTag', 'RpcTest: read to Ashmem result is ' + readResult););    
```    
  
    
### readAshmem<sup>(9+)</sup>    
从此Ashmem对象关联的共享文件中读取数据。  
 **调用形式：**     
- readAshmem(size: number, offset: number): number[]  
  
 **系统能力:**  SystemCapability.Communication.IPC.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| size | number | true | 要读取的数据的大小。 |  
| offset | number | true | 要读取的数据在此Ashmem对象关联的内存区间的起始位置 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | 返回读取的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1900004 | read from ashmem failed |  
    
 **示例代码：**   
```ts    
import hilog from '@ohos.hilog';  
  import { BusinessError } from '@ohos.base';  
  
  let ashmem = rpc.Ashmem.create("ashmem", 1024*1024);  
  ashmem.mapReadWriteAshmem();  
  let ByteArrayVar = [1, 2, 3, 4, 5];  
  ashmem.writeAshmem(ByteArrayVar, 5, 0);  
  try {  
    let readResult = ashmem.readAshmem(5, 0);  
    hilog.info(0x0000, 'testTag', 'RpcTest: read from Ashmem result is ' + readResult);  
  } catch(error) {  
    let e: BusinessError = error as BusinessError;  
    hilog.error(0x0000, 'testTag', 'Rpc read from ashmem fail, errorCode ' + e.code);  
    hilog.error(0x0000, 'testTag', 'Rpc read from ashmem fail, errorMessage ' + e.message);  
  }  
    
```    
  
