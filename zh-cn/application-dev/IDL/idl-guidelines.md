# OpenHarmony IDL工具规格及使用说明书

## IDL接口描述语言简介
在OpenHarmony中，当客户端和服务器进行IPC通信时，需要定义双方都认可的接口，以保障双方可以成功通信，OpenHarmony IDL（OpenHarmony Interface Definition Language）则是一种定义此类接口的工具。OpenHarmony IDL先把需要传递的对象分解成操作系统能够理解的基本类型，并根据开发者的需要封装跨边界的对象。

  **图1** IDL接口描述

![IDL-interface-description](./figures/IDL-interface-description.png)

 **OpenHarmony IDL接口描述语言主要用于：** 

- 声明系统服务对外提供的服务接口，根据接口声明在编译时生成跨进程调用（IPC）或跨设备调用（RPC）的代理（Proxy）和桩（Stub）的C/C++代码或JS/TS代码。

- 声明Ability对外提供的服务接口，根据接口声明在编译时生成跨进程调用（IPC）或跨设备调用（RPC）的代理（Proxy）和桩（Stub）的C/C++代码或JS/TS代码。

**图2** IPC/RPC通信模型

![IPC-RPC-communication-model](./figures/IPC-RPC-communication-model.png)

 **使用OpenHarmony IDL接口描述语言声明接口具有以下优点：** 

- OpenHarmony IDL中是以接口的形式定义服务，可以专注于定义而隐藏实现细节。

- OpenHarmony IDL中定义的接口可以支持跨进程调用或跨设备调用。根据OpenHarmony IDL中的定义生成的信息或代码可以简化跨进程或跨设备调用接口的实现。

## IDL接口描述语言构成

### 数据类型

#### 基础数据类型
| IDL基本数据类型 | C++基本数据类型 | TS基本数据类型 |
|   --------    |  --------     | --------     |
|void           | void          | void         |
|boolean        | bool          | boolean      |
|byte           | int8_t        | number       |
|short          | int16_t       | number       |
|int            | int32_t       | number       |
|long           | int64_t       | number       |
|float          | float         | number       |
|double         | double        | number       |
|String         | std::string   | string       |

IDL支持的基本数据类型及其映射到C++、TS上的数据类型的对应关系如上表所示。

#### sequenceable数据类型
sequenceable数据类型是指使用“sequenceable”关键字声明的数据，表面该数据类型可以被序列化进行跨进程或跨设备传递。sequenceable在C++与TS中声明方式存在一定差异。

在C++中sequenceable数据类型的声明放在文件的头部，以“sequenceable includedir..namespace.typename”的形式声明。具体而言。声明可以有如下三个形式：

```cpp
sequenceable includedir..namespace.typename
sequenceable includedir...typename
sequenceable namespace.typename
```

其中，includedir表示该数据类型头文件所在目录，includedir中以“.”作为分隔符。namespace表示该数据类型所在命名空间，namespace中同样以“.”作为分隔符。typename表示数据类型，数据类型中不能包含非英文字符类型的其他符号。includedir与namespace之间通过“..”分割，如果类型声明的表达式中不包含“..”,除去最后一个typename之外的字符都会被解析为命名空间。例如：

```cpp
sequenceable a.b..C.D
```

 上述声明在生成的的C++头文件中将被解析为如下代码：

```cpp
#include  “a/b/d.h”
using C::D;
```

TS声明放在文件的头部，以 “sequenceable namespace.typename;”的形式声明。具体而言，声明可以有如下形式：

```ts
sequenceable idl.MySequenceable
```

其中，namespace是该类型所属的命名空间，typename是类型名。MySequenceable类型表示可以通过Parcel进行跨进程传递。sequenceable数据类型并不在OpenHarmony IDL文件中定义，而是定义在.ts文件中。因此，OpenHarmony IDL工具将根据声明在生成的.ts代码文件中加入如下语句：

```ts
import MySequenceable from "./my_sequenceable"
```

需要注意的是，IDL并不负责该类型的代码实现，仅仅按照指定的形式引入该头文件或import指定模块，并使用该类型，因此开发者需要自行保证引入目录、命名空间及类型的正确性。

#### 接口类型
 接口类型是指OpenHarmony IDL文件中定义的接口。对于当前IDL文件中定义的接口，可以直接使用它作为方法参数类型或返回值类型。而在其它OpenHarmony IDL文件中定义的接口，则需要在文件的头部进行前置声明。 

 C++中声明的形式与sequenceable类型相似，具体而言可以有如下形式： 

```cpp
interface includedir..namespace.typename
```

 TS中声明的形式，具体而言可以有如下形式： 

```ts
interface namespace.interfacename
```

其中，namespace是该接口所属的命名空间，interfacename是接口名。例如：“interface OHOS.IIdlTestObserver;”声明了在其他OpenHarmony IDL文件定义的IIdlTestObserver接口，该接口可以作为当前定义中方法的参数类型或返回值类型使用。OpenHarmony IDL工具将根据该声明在生成的TS代码文件中加入如下语句：

```ts
import IIdlTestObserver from "./i_idl_test_observer"
```

#### 数组类型
数组类型使用“T[]”表示，其中T可以是基本数据类型、sequenceable数据类型、interface类型和数组类型。该类型在C++生成代码中将被生成为std::vector&lt;T&gt;类型。
OpenHarmony IDL数组数据类型与TS数据类型、C++数据类型的对应关系如下表所示：

|OpenHarmony IDL数据类型  | C++数据类型           | TS数据类型     |
|   -------              |  --------            |  --------    |
|T[]                     | std::vector&lt;T&gt; | T[]          |

#### 容器类型
IDL支持两种容器类型，即List和Map。其中List类型容器的用法为List&lt;T&gt;;Map容器的用法为Map<KT,VT>,其中T、KT、VT为基本数据类型、sequenceable类型、interface类型、数组类型或容器类型。

List类型在C++代码中被映射为std::list,Map容器被映射为std::map。

List类型在TS代码中不支持,Map容器被映射为Map。

OpenHarmony IDL容器数据类型与Ts数据类型、C++数据类型的对应关系如下表所示：

|OpenHarmony IDL数据类型  | C++数据类型       | TS数据类型     |
|   --------             |  --------        |  -------     |
|List&lt;T&gt;           | std::list        | 不支持        |
|Map<KT,VT>              | std::map         | Map          |


### IDL文件编写规范
一个idl文件只能定义一个interface类型，且该interface名称必须和文件名相同。idl文件的接口定义使用BNF范式描述，其基本定义的形式如下：

```
[<*interface_attr_declaration*>]interface<*interface_name_with_namespace*>{<*method_declaration*>}
```

其中，<*interface_attr_declaration*>表示接口属性声明。当前仅支持“oneway”属性，表示该接口中的接口都是单向方法，即调用方法后不用等待该方法执行即可返回。这个属性为可选项，如果未声明该属性，则默认为同步调用方法。接口名需要包含完整的接口头文件目录及命名空间，且必须包含方法声明，不允许出现空接口。
接口内的方法声明形式为：

```
[<*method_attr_declaration*>]<*result_type*><*method_declaration*>
```

其中，<*method_attr_declaration*>表示接口属性说明。当前仅支持“oneway”属性，表示该方法为单向方法，即调用方法后不用等待该方法执行即可返回。这个属性为可选项，如果未声明该属性，则默认为同步调用方法。<*result_type*>为返回值类型，<*method_declaration*>是方法名和各个参数声明。
参数声明的形式为：

```
[<*formal_param_attr*>]<*type*><*identifier*>
```

其中<*formal_param_attr*>的值为“in”，“out”，“inout”,分别表示该参数是输入参数，输出参数或输入输出参数。需要注意的是，如果一个方法被声明为oneway，则该方法不允许有输出类型的参数（及输入输出类型）和返回值。

## 开发步骤

### IDL工具的获取
首先，打开DevEco Studio—>Tools—>SDK Manager，查看OpenHarmony SDK的本地安装路径，此处以DevEco Studio 3.0.0.993版本为例，查看方式如下图所示。
![SDKpath](./figures/SDKpath.png)
![SDKpath](./figures/SDKpath2.png)

进入对应路径后，查看toolchains->3.x.x.x（对应版本号命名文件夹）下是否存在idl工具的可执行文件，若不存在，可对应版本前往[docs仓版本目录](https://gitee.com/openharmony/docs/tree/master/zh-cn/release-notes)下载SDK包，以[3.2Beta3版本](https://gitee.com/openharmony/docs/blob/master/zh-cn/release-notes/OpenHarmony-v3.2-beta3.md#%E4%BB%8E%E9%95%9C%E5%83%8F%E7%AB%99%E7%82%B9%E8%8E%B7%E5%8F%96)为例，可通过镜像站点获取。

关于如何替换DevEco Studio的SDK包具体操作，参考[full-SDK替换指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/quick-start/full-sdk-switch-guide.md#full-sdk%E6%9B%BF%E6%8D%A2%E6%8C%87%E5%8D%97)中的替换方法。

得到idl工具的可执行文件后，根据具体场景进行后续开发步骤。

### TS开发步骤

#### 创建.idl文件

 开发者可以使用TS编程语言构建.idl文件。

 例如，此处构建一个名为IIdlTestService.idl的文件，文件内具体内容如下：  

```cpp
  interface OHOS.IIdlTestService {
      int TestIntTransaction([in] int data);
      void TestStringTransaction([in] String data);
  }
```

在idl的可执行文件所在文件夹下执行命令 `idl -gen-ts -d dir -c dir/IIdlTestService.idl`。

-d后的dir为目标输出目录，以输出文件夹名为IIdlTestServiceTs为例，在idl可执行文件所在目录下执行`idl -gen-ts -d IIdlTestServiceTs -c IIdlTestServiceTs/IIdlTestService.idl`，将会在执行环境的dir目录（即IIdlTestServiceTs目录）中生成接口文件、Stub文件、Proxy文件。

> **注意**：生成的接口类文件名称和.idl文件名称保持一致，否则会生成代码时会出现错误。

以名为`IIdlTestService.idl`的.idl文件、目标输出文件夹为IIdlTestServiceTs为例，其目录结构应类似于:

```
├── IIdlTestServiceTs  # idl代码输出文件夹
│   ├── i_idl_test_service.ts  # 生成文件
│   ├── idl_test_service_proxy.ts  # 生成文件
│   ├── idl_test_service_stub.ts  # 生成文件
│   └── IIdlTestService.idl  # 构造的.idl文件
└── idl.exe  # idl的可执行文件
```

#### 服务端公开接口

OpenHarmony IDL工具生成的Stub类是接口类的抽象实现，并且会声明.idl文件中的所有方法。 

```ts
import {testIntTransactionCallback} from "./i_idl_test_service";
import {testStringTransactionCallback} from "./i_idl_test_service";
import IIdlTestService from "./i_idl_test_service";
import rpc from "@ohos.rpc";

export default class IdlTestServiceStub extends rpc.RemoteObject implements IIdlTestService {
    constructor(des: string) {
        super(des);
    }
    
    onRemoteRequest(code: number, data, reply, option): boolean {
        console.log("onRemoteRequest called, code = " + code);
        switch(code) {
            case IdlTestServiceStub.COMMAND_TEST_INT_TRANSACTION: {
                let _data = data.readInt();
                this.testIntTransaction(_data, (errCode, returnValue) => {
                    reply.writeInt(errCode);
                    if (errCode == 0) {
                        reply.writeInt(returnValue);
                    }
                });
                return true;
            }
            case IdlTestServiceStub.COMMAND_TEST_STRING_TRANSACTION: {
                let _data = data.readString();
                this.testStringTransaction(_data, (errCode) => {
                    reply.writeInt(errCode);
                });
                return true;
            }
            default: {
                console.log("invalid request code" + code);
                break;
            }
        }
        return false;
    }
    
    testIntTransaction(data: number, callback: testIntTransactionCallback): void{}
    testStringTransaction(data: string, callback: testStringTransactionCallback): void{}

    static readonly COMMAND_TEST_INT_TRANSACTION = 1;
    static readonly COMMAND_TEST_STRING_TRANSACTION = 2;
}
```

开发者需要继承.idl文件中定义的接口类并实现其中的方法。在本示例中，我们继承了IdlTestServiceStub接口类并实现了其中的testIntTransaction和testStringTransaction方法。具体的示例代码如下：

```ts
import {testIntTransactionCallback} from "./i_idl_test_service"
import {testStringTransactionCallback} from "./i_idl_test_service"
import IdlTestServiceStub from "./idl_test_service_stub"


class IdlTestImp extends IdlTestServiceStub {

    testIntTransaction(data: number, callback: testIntTransactionCallback): void
    {
        callback(0, data + 1);
    }
    testStringTransaction(data: string, callback: testStringTransactionCallback): void
    {
        callback(0);
    }
}
```

在服务实现接口后，需要向客户端公开该接口，以便客户端进程绑定。如果开发者的服务要公开该接口，请扩展Ability并实现onConnect()从而返回IRemoteObject，以便客户端能与服务进程交互。服务端向客户端公开IRemoteAbility接口的代码示例如下:

```ts
export default {
    onStart() {
        console.info('ServiceAbility onStart');
    },
    onStop() {
        console.info('ServiceAbility onStop');
    },
    onCommand(want, startId) {
        console.info('ServiceAbility onCommand');
    },
    onConnect(want) {
        console.info('ServiceAbility onConnect');
        try {
            console.log('ServiceAbility want:' + typeof(want));
            console.log('ServiceAbility want:' + JSON.stringify(want));
            console.log('ServiceAbility want name:' + want.bundleName)
        } catch(err) {
            console.log('ServiceAbility error:' + err)
        }
        console.info('ServiceAbility onConnect end');
        return new IdlTestImp('connect');
    },
    onDisconnect(want) {
        console.info('ServiceAbility onDisconnect');
        console.info('ServiceAbility want:' + JSON.stringify(want));
    }
};
```

#### 客户端调用IPC方法

客户端调用connectAbility()以连接服务时，客户端的onAbilityConnectDone中的onConnect回调会接收服务的onConnect()方法返回的IRemoteObject实例。由于客户端和服务在不同应用内，所以客户端应用的目录内必须包含.idl文件(SDK工具会自动生成Proxy代理类)的副本。客户端的onAbilityConnectDone中的onConnect回调会接收服务的onConnect()方法返回的IRemoteObject实例，使用IRemoteObject创建IdlTestServiceProxy类的实例对象testProxy，然后调用相关IPC方法。示例代码如下：

```ts
import IdlTestServiceProxy from './idl_test_service_proxy'
import featureAbility from '@ohos.ability.featureAbility';

function callbackTestIntTransaction(result: number, ret: number): void {
  if (result == 0 && ret == 124) {
    console.log('case 1 success');
  }
}

function callbackTestStringTransaction(result: number): void {
  if (result == 0) {
    console.log('case 2 success');
  }
}

var onAbilityConnectDone = {
  onConnect:function (elementName, proxy) {
    let testProxy = new IdlTestServiceProxy(proxy);
    testProxy.testIntTransaction(123, callbackTestIntTransaction);
    testProxy.testStringTransaction('hello', callbackTestStringTransaction);
  },
  onDisconnect:function (elementName) {
    console.log('onDisconnectService onDisconnect');
  },
  onFailed:function (code) {
    console.log('onDisconnectService onFailed');
  }
};

function connectAbility: void {
    let want = {
        bundleName: 'com.example.myapplicationidl',
        abilityName: 'com.example.myapplicationidl.ServiceAbility'
    };
    let connectionId = -1;
    connectionId = featureAbility.connectAbility(want, onAbilityConnectDone);
}


```

#### IPC传递sequenceable对象

开发者可以通过 IPC 接口，将某个类从一个进程发送至另一个进程。但是，必须确保 IPC 通道的另一端可使用该类的代码，并且该类必须支持marshalling和unmarshalling方法。OpenHarmony 需要通过该marshalling和unmarshalling方法将对象序列化和反序列化成各进程能识别的对象。

 **如需创建支持sequenceable 类型数据，开发者必须执行以下操作：** 

1. 实现marshalling方法，它会获取对象的当前状态并将其序列化后写入Parcel。
2. 实现unmarshalling方法，它会从Parcel中反序列化出对象。

MySequenceable类的代码示例如下：

```ts
import rpc from '@ohos.rpc';
export default class MySequenceable {
    constructor(num: number, str: string) {
        this.num = num;
        this.str = str;
    }
    getNum() : number {
        return this.num;
    }
    getString() : string {
        return this.str;
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
    private num;
    private str;
}
```
