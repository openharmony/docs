# OpenHarmony IDL工具规格及使用说明书

## 1. IDL接口描述语言简介
在OpenHarmony中，当客户端和服务器进行IPC通信时，需要定义双方都认可的接口，以保障双方可以成功通信，OpenHarmony IDL（OpenHarmony Interface Definition Language）则是一种定义此类接口的工具。OpenHarmony IDL先把需要传递的对象分解成操作系统能够理解的基本类型，并根据开发者的需要封装跨边界的对象。

![IDL-interface-description](./figures/IDL-interface-description.png)

OpenHarmony  IDL接口描述语言主要用于：

- 声明系统服务对外提供的服务接口，根据接口声明在编译时生成跨进程调用（IPC）或跨设备调用（RPC）的代理（Proxy）和桩（Stub）的C/C++代码或JS/TS代码。

- 声明Ability对外提供的服务接口，根据接口声明在编译时生成跨进程调用（IPC）或跨设备调用（RPC）的代理（Proxy）和桩（Stub）的C/C++代码或JS/TS代码。

  **图2** IPC/RPC通信模型

![IPC-RPC-communication-model](./figures/IPC-RPC-communication-model.png)

使用OpenHarmony IDL接口描述语言声明接口具有以下优点：

- OpenHarmony IDL中是以接口的形式定义服务，可以专注于定义而隐藏实现细节。

- OpenHarmony IDL中定义的接口可以支持跨进程调用或跨设备调用。根据OpenHarmony IDL中的定义生成的信息或代码可以简化跨进程或跨设备调用接口的实现。

## 2. IDL接口描述语言构成

### 2.1 数据类型

#### 2.1.1 基础数据类型
| IDL基本数据类型 | C++基本数据类型 | TS基本数据类型 |
|   --------      |  --------      | --------    |
|void             | void           | void |
|boolean          | bool           | boolean |
|byte             | int8_t         | number |
|short            | int16_t        | number |
|int              | int32_t        | number |
|long             | int64_t        | number |
|float            | float          | number |
|double           | double         | number |
|String           | std::string    | string |

idl支持的基本数据类型及其映射到C++，TS上的数据类型的对应关系如上表所示。

#### 2.1.2 sequenceable数据类型
sequenceable数据类型是指使用“sequenceable”关键字声明的数据，表面该数据类型可以被序列化进行跨进程或跨设备传递。sequenceable在C++与TS中声明方式存在一定差异。

在C++中sequenceable数据类型的声明放在文件的头部，以“sequenceable includedir..namespace.typename”的形式声明。具体而言。声明可以有如下三个形式：

```
sequenceable includedir..namespace.typename
sequenceable includedir...typename
sequenceable namespace.typename
```
其中，includedir表示该数据类型头文件所在目录，includedir中以“.”作为分隔符。namespace表示该数据类型所在命名空间，namespace中同样以“.”作为分隔符。typename表示数据类型，数据类型中不能包含非英文字符类型的其他符号。includedir与namespace之间通过“..”分割，如果类型声明的表达式中不包含“..”,除去最后一个typename之外的字符都会被解析为命名空间。例如：
```
sequenceable a.b..C.D
```
上述声明在生成的的C++头文件中将被解析为如下代码：
```
#include  “a/b/d.h”
using C::D;
```
TS声明放在文件的头部，以 “sequenceable namespace.typename;”的形式声明。具体而言，声明可以有如下形式：

```
sequenceable idl.MySequenceable
```

其中，namespace是该类型所属的命名空间，typename是类型名。MySequenceable类型表示可以通过Parcel进行跨进程传递。Sequenceable数据类型并不在OpenHarmony IDL文件中定义，而是定义在.ts文件中。因此，OpenHarmony IDL工具将根据声明在生成的.ts代码文件中加入如下语句：

```
import MySequenceable from "./mysequenceable"
```

需要注意的是，IDL并不负责该类型的代码实现，仅仅按照指定的形式引入该头文件或import指定模块，并使用该类型，因此开发者需要自行保证引入目录、命名空间及类型的正确性。

#### 2.1.3 接口类型
接口类型是指OpenHarmony IDL文件中定义的接口。对于当前IDL文件中定义的接口，可以直接使用它作为方法参数类型或返回值类型。而在其它OpenHarmony IDL文件中定义的接口，则需要在文件的头部进行前置声明。

C++中声明的形式与sequenceable类型相似，具体而言可以有如下形式：

```
interface includedir..namespace.typename
```

TS中声明的形式，具体而言可以有如下形式：

```
interface namespace.interfacename
```

其中，namespace是该接口所属的命名空间，interfacename是接口名。例如：“interface OHOS.IIdlTestObserver;”声明了在其他OpenHarmony IDL文件定义的IIdlTestObserver接口，该接口可以作为当前定义中方法的参数类型或返回值类型使用。OpenHarmony IDL工具将根据该声明在生成的TS代码文件中加入如下语句：

```
import IIdlTestObserver from "./i_idl_test_observer"
```

#### 2.1.4 数组类型
数组类型使用“T[]”表示，其中T可以是基本数据类型、sequenceable数据类型、interface类型和数据类型。该类型在C++生成代码中将被生成为std::vector&lt;T&gt;类型。
OpenHarmony IDL数组数据类型与TS数据类型、C++数据类型的对应关系如下表所示：

|OpenHarmony IDL数据类型  | C++数据类型       | TS数据类型     |
|   --------             |  --------        |  --------        |
|T[]                     | std::vector&lt;T&gt;   | T[] |

#### 2.1.5 容器类型
IDL支持两种容器类型，即List和Map。其中List类型容器的用法为List&lt;T&gt;;Map容器的用法为Map<KT,VT>,其中T、KT、VT为基本数据类型、sequenceable类型、interface类型、数组类型或容器类型。

List类型在C++代码中被映射为std::list,Map容器被映射为std::map。

List类型在TS代码中不支持,Map容器被映射为Map。

OpenHarmony IDL容器数据类型与Ts数据类型、C++数据类型的对应关系如下表所示：

|OpenHarmony IDL数据类型  | C++数据类型       | TS数据类型     |
|   --------             |  --------        |  --------        |
|List&lt;T&gt;                 | std::list        | 不支持 |
|Map<KT,VT>              | std::map         | Map |


### 2.2 IDL文件编写规范
一个idl文件只能定义一个interface类型，且该interface名称必须和文件名相同。idl文件的接口定义使用BNF范式描述，其基本定义的形式如下：
```
[<*interface_attr_declaration*>]interface<*interface_name_with_namespace*>{<*method_declaration*>}
```
其中，<*interface_attr_declaration*>表示接口属性声明。当前仅支持“oneway”属性表示该接口中的接口都是单向方法，即调用方法后不用等待该方法执行即可返回。这个属性为可选项，如果未声明该属性，则默认为同步调用方法。接口名需要包含完整的接口头文件目录及命名空间，且必须包含方法声明，不允许出现空接口。
接口内的方法声明形式为：
```
/[<*method_attr_declaration*>]<*result_type*><*method_declaration*>
```
其中，<*method_attr_declaration*>表示接口属性说明。当前仅支持“oneway”属性表示该方法为单向方法，即调用方法后不在等待该方法执行即可返回。这个属性为可选项，如果未声明该属性，则默认为同步调用方法。<*result_type*>为返回值类型，<*method_declaration*>是方法名和各个参数声明。
参数声明的形式为：
```
[<**formal_param_attr*>]<*type*><*identifier*>
```
其中<*formal_param_attr*>的值为“in”，“out”，“inout”,分别表示该参数是输入参数，输出参数或输入输出参数。需要注意的是，如果一个方法被声明为oneway，则该方法不允许有输出类型的参数（及输入输出类型）和返回值。

## 3.开发步骤

### 3.1 C++开发步骤

#### 3.1.1 创建.idl文件

 开发者可以使用C++编程语言构建.idl文件。.idl示例如下： 

```
  interface OHOS.IIdlTestService {
      int TestIntTransaction([in] int data);
      void TestStringTransaction([in] String data);
  }
```

使用者通过执行命令 “./idl -gen-cpp -d dir -c dir/iTest.idl” （-d为输出目录）在执行环境的dir/iTest.idl/目录中生成接口文件、Stub文件、Proxy文件。生成的接口类文件名称和.idl文件名称保持一致，区别在于其使用.h和.cpp扩展名。例如，IIdlTestService. idl 生成的文件名是 i_idl_test_service.h、idl_test_service_proxy.h、idl_test_service_stub.h、idl_test_service_proxy.cpp、idl_test_service_stub.cpp。

#### 3.1.2 服务端公开接口

 OpenHarmony IDL工具生成的Stub类是接口类的抽象实现，并且会声明.idl文件中的所有方法。 

```
#ifndef OHOS_IDLTESTSERVICESTUB_H
#define OHOS_IDLTESTSERVICESTUB_H
#include <iremote_stub.h>
#include "iidl_test_service.h"

namespace OHOS {
class IdlTestServiceStub : public IRemoteStub<IIdlTestService> {
public:
    int OnRemoteRequest(
        /* [in] */ uint32_t code,
        /* [in] */ MessageParcel& data,
        /* [out] */ MessageParcel& reply,
        /* [in] */ MessageOption& option) override;

private:
    static constexpr int COMMAND_TEST_INT_TRANSACTION = MIN_TRANSACTION_ID + 0;
    static constexpr int COMMAND_TEST_STRING_TRANSACTION = MIN_TRANSACTION_ID + 1;
};
} // namespace OHOS
#endif // OHOS_IDLTESTSERVICESTUB_H
```

开发者需要继承.idl文件中定义的接口类并实现其中的方法。在本示例中，我们继承了IdlTestServiceStub接口类并实现了其中的TestIntTransaction和TestStringTransaction方法。具体的示例代码如下：

```
#include "idl_test_service_stub.h"

namespace OHOS {
int IdlTest ::OnRemoteRequest(
    /* [in] */ uint32_t code,
    /* [in] */ MessageParcel& data,
    /* [out] */ MessageParcel& reply,
    /* [in] */ MessageOption& option)
{
    if (data.ReadInterfaceToken() != GetDescriptor()) {
        return ERR_TRANSACTION_FAILED;
    }
    switch (code) {
        case COMMAND_TEST_INT_TRANSACTION: {
            int _data = data.ReadInt32();
            int result;
            ErrCode ec = TestIntTransaction(_data, result);
            reply.WriteInt32(ec);
            if (SUCCEEDED(ec)) {
                reply.WriteInt32(result);
            }
            return ERR_NONE;
        }
        case COMMAND_TEST_STRING_TRANSACTION: {
            std::string _data = Str16ToStr8(data.ReadString16());
            ErrCode ec = TestStringTransaction(_data);
            reply.WriteInt32(ec);
            return ERR_NONE;
        }
        default:
            return IPCObjectStub::OnRemoteRequest(code, data, reply, option);
    }

    return ERR_TRANSACTION_FAILED;
}
}
```

在服务实现接口后，需要向客户端公开该接口，以便客户端进程绑定。如果开发者的服务要公开该接口，请扩展Ability并实现onConnect()从而返回IRemoteObject，以便客户端能与服务进程交互。服务端向客户端公开IRemoteAbility接口的代码示例如下：

```
#include "idl_test_service_proxy.h"

namespace OHOS {
ErrCode IdlTestServiceProxy::TestIntTransaction(
    /* [in] */ int _data,
    /* [out] */ int& result)
{
    MessageParcel data;
    MessageParcel reply;
    MessageOption option(MessageOption::TF_SYNC);

    if (!data.WriteInterfaceToken(GetDescriptor())) {
        return ERR_INVALID_VALUE;
    }

    data.WriteInt32(_data);

    if (Remote() == nullptr) {
        return ERR_INVALID_VALUE;
    }
    int32_t st = Remote()->SendRequest(COMMAND_TEST_INT_TRANSACTION, data, reply, option);
    if (st != ERR_NONE) {
        return st;
    }

    ErrCode ec = reply.ReadInt32();
    if (FAILED(ec)) {
        return ec;
    }

    result = reply.ReadInt32();
    return ERR_OK;
}

ErrCode IdlTestServiceProxy::TestStringTransaction(
    /* [in] */ const std::string& _data)
{
    MessageParcel data;
    MessageParcel reply;
    MessageOption option(MessageOption::TF_SYNC);

    if (!data.WriteInterfaceToken(GetDescriptor())) {
        return ERR_INVALID_VALUE;
    }

    data.WriteString16(Str8ToStr16(_data));

    if (Remote() == nullptr) {
        return ERR_INVALID_VALUE;
    }
    int32_t st = Remote()->SendRequest(COMMAND_TEST_STRING_TRANSACTION, data, reply, option);
    if (st != ERR_NONE) {
        return st;
    }

    ErrCode ec = reply.ReadInt32();
    if (FAILED(ec)) {
        return ec;
    }

    return ERR_OK;
}
} 
```

#### 3.1.3 客户端调用IPC方法

 客户端调用connectAbility()以连接服务时，客户端的onAbilityConnectDone()回调会接收服务的onConnect()方法返回的IRemoteObject实例。由于客户端和服务在不同应用内，所以客户端应用的src/目录内必须包含.idl文件(SDK工具会自动生成Proxy代理类)的副本。当客户端onAbilityConnectDone()回调中收到IRemoteObject，调用RemoteAbilityStub.asInterface(IRemoteObject)，以将返回的参数转换为IRemoteAbility类型，示例代码如下： 

```
#ifndef OHOS_IDLTESTSERVICEPROXY_H
#define OHOS_IDLTESTSERVICEPROXY_H
#include <iremote_proxy.h>
#include "iidl_test_service.h"

namespace OHOS {
class IdlTestServiceProxy : public IRemoteProxy<IIdlTestService> {
public:
    explicit IdlTestServiceProxy(
        /* [in] */ const sptr<IRemoteObject>& remote)
        : IRemoteProxy<IIdlTestService>(remote)
    {}

    virtual ~IdlTestServiceProxy()
    {}

    ErrCode TestIntTransaction(
        /* [in] */ int _data,
        /* [out] */ int& result) override;

    ErrCode TestStringTransaction(
        /* [in] */ const std::string& _data) override;

private:
    static constexpr int COMMAND_TEST_INT_TRANSACTION = MIN_TRANSACTION_ID + 0;
    static constexpr int COMMAND_TEST_STRING_TRANSACTION = MIN_TRANSACTION_ID + 1;

    static inline BrokerDelegator<IdlTestServiceProxy> delegator_;
};
} // namespace OHOS
#endif 
```

如果要断开连接，请调用Ability.disconnectAbility()。



### 3.2 TS开发步骤

#### 3.2.1 创建.idl文件

 开发者可以使用TS编程语言构建.idl文件。.idl示例如下： 

```
  interface OHOS.IIdlTestService {
      int TestIntTransaction([in] int data);
      void TestStringTransaction([in] String data);
  }
```

使用者通过执行命令 “./idl -c IIdlTestService.idl -gen-ts -d /data/ts/” （-d为输出目录）在执行环境的/data/ts/目录中生成接口文件、Stub文件、Proxy文件。生成的接口类文件名称和.idl文件名称保持一致，区别在于其使用.ts扩展名。例如，IIdlTestService.idl 生成的文件名是 i_idl_test_service.ts、idl_test_service_proxy.ts、idl_test_service_stub.ts。

#### 3.2.2 服务端公开接口

 OpenHarmony IDL工具生成的Stub类是接口类的抽象实现，并且会声明.idl文件中的所有方法。 

```
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

```
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

```
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
            console.log("ServiceAbility error:" + err)
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

#### 3.2.3 客户端调用IPC方法

客户端调用connectAbility()以连接服务时，客户端的onAbilityConnectDone()回调会接收服务的onConnect()方法返回的IRemoteObject实例。由于客户端和服务在不同应用内，所以客户端应用的目录内必须包含.idl文件(SDK工具会自动生成Proxy代理类)的副本。当客户端onAbilityConnectDone()回调中收到IRemoteObject，使用IRemoteObject创建IdlTestServiceProxy类的实例对象testProxy，然后调用相关IPC方法。示例代码如下： 

```
import IdlTestServiceProxy from './idl_test_service_proxy'
import featureAbility from '@ohos.ability.featureAbility';

function callbackTestIntTransaction(result: number, ret: number): void {
  if (result == 0 && ret == 124) {
    console.log("case 1 success ");
  }
}

function callbackTestStringTransaction(result: number): void {
  if (result == 0) {
    console.log("case 2 success ");
  }
}

var onAbilityConnectDone = {
  onConnect:function (elementName, proxy) {
    let testProxy = new IdlTestServiceProxy(proxy);
    testProxy.testIntTransaction(123, callbackTestIntTransaction);
    testProxy.testStringTransaction('hello', callbackTestStringTransaction);
  },
  onDisconnect:function (elementName) {
    console.log("onDisconnectService onDisconnect");
  },
  onFailed:function (code) {
    console.log("onDisconnectService onFailed");
  }
};

function connectAbility: void {
    let want = {
    	"bundleName":"com.example.myapplicationidl",
    	"abilityName": "com.example.myapplicationidl.ServiceAbility"
    };
    let connectionId = -1;
    connectionId = featureAbility.connectAbility(want, onAbilityConnectDone);
}


```

#### 3.2.4 IPC传递Sequenceable对象

开发者可以通过 IPC 接口，将某个类从一个进程发送至另一个进程。但是，必须确保 IPC 通道的另一端可使用该类的代码，并且该类必须支持marshalling和unmarshalling方法。OpenHarmony 需要通过该marshalling和unmarshalling方法将对象序列化和反序列化成各进程能识别的对象。

如需创建支持Sequenceable 类型数据，开发者必须执行以下操作：

1. 实现marshalling方法，它会获取对象的当前状态并将其序列化后写入Parcel。
2. 实现unmarshalling方法，它会从Parcel中反序列化出对象。

MySequenceable类的代码示例如下：

```
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



## 4. C++与TS互通开发步骤

### 4.1 TS Proxy与C++ Stub开发步骤

#### 4.1.1 C++端提供服务对象

1. 如上所述C++开发步骤，开发者使用C++编程语言构建.idl文件，通过命令生成接口、Stub文件、Proxy文件。

2. 开发者创建服务对象，并继承C++ Stub文件中定义的接口类并实现其中的方法，例如：

   ```
   class IdlTestServiceImpl : public IdlTestServiceStub {
   public:
       IdlTestServiceImpl() = default;
       virtual ~IdlTestServiceImpl() = default;
   
       ErrCode TestIntTransaction(int _data, int& result) override
       {
       	result = 256;
       	return ERR_OK;
       }
   
       ErrCode TestStringTransaction(const std::string& _data) override
       {
       	return ERR_OK;
       }
   };
   ```

#### 4.1.2 C++端提供napi接口

C++需要通过napi的方式，把C++服务对象提供给TS端，例如：C++端提供一个GetNativeObject方法，方法里创建IdlTestServiceImpl实例，通过NAPI_ohos_rpc_CreateJsRemoteObject方法，创建出一个JS远程对象供TS应用使用，如下：

```
NativeValue* GetNativeObject(NativeEngine& engine, NativeCallbackInfo& info)
{
    sptr<IdlTestServiceImpl> impl = new IdlTestServiceImpl();
    napi_value napiRemoteObject = NAPI_ohos_rpc_CreateJsRemoteObject(reinterpret_cast<napi_env>(&engine), impl);
    NativeValue* nativeRemoteObject = reinterpret_cast<NativeValue*>(napiRemoteObject);
    return nativeRemoteObject;
}
```

#### 4.1.3 TS端提供Proxy对象

如上所述TS开发步骤，开发者使用TS编程语言构建.idl文件，通过命令生成接口、Stub文件、Proxy文件。Proxy文件例如：

```
idl_test_service_proxy.ts

import {testIntTransactionCallback} from "./i_idl_test_service";
import {testStringTransactionCallback} from "./i_idl_test_service";
import IIdlTestService from "./i_idl_test_service";
import rpc from "@ohos.rpc";

export default class IdlTestServiceProxy implements IIdlTestService {
    constructor(proxy) {
        this.proxy = proxy;
    }

    testIntTransaction(data: number, callback: testIntTransactionCallback): void
    {
        let _option = new rpc.MessageOption(rpc.MessageOption.TF_SYNC);
        let _data = new rpc.MessageParcel();
        let _reply = new rpc.MessageParcel();
        _data.writeInt(data);
        this.proxy.sendRequest(IdlTestServiceProxy.COMMAND_TEST_INT_TRANSACTION, _data, _reply, _option).then(function(result) {
            if (result.errCode === 0) {
                let _errCode = result.reply.readInt();
                if (_errCode != 0) {
                    let _returnValue = undefined;
                    callback(_errCode, _returnValue);
                    return;
                }
                let _returnValue = result.reply.readInt();
                callback(_errCode, _returnValue);
            } else {
                console.log("sendRequest failed, errCode: " + result.errCode);
            }
        })
    }

    testStringTransaction(data: string, callback: testStringTransactionCallback): void
    {
        let _option = new rpc.MessageOption(rpc.MessageOption.TF_SYNC);
        let _data = new rpc.MessageParcel();
        let _reply = new rpc.MessageParcel();
        _data.writeString(data);
        this.proxy.sendRequest(IdlTestServiceProxy.COMMAND_TEST_STRING_TRANSACTION, _data, _reply, _option).then(function(result) {
            if (result.errCode === 0) {
                let _errCode = result.reply.readInt();
                callback(_errCode);
            } else {
                console.log("sendRequest failed, errCode: " + result.errCode);
            }
        })
    }

    static readonly COMMAND_TEST_INT_TRANSACTION = 1;
    static readonly COMMAND_TEST_STRING_TRANSACTION = 2;
    private proxy
}
```

#### 4.1.4 TS与C++实现互通

1. TS应用调用napi接口获取C++服务的远程对象
2. 构建TS Proxy对象，并把C++服务的远程对象传递给它
3. 此时开发者通过TS Proxy对象调用.idl声明的方法，实现TS Proxy与C++ Stub的互通，示例如下：

```
import IdlTestServiceProxy from './idl_test_service_proxy'
import nativeMgr from 'nativeManager';

function testIntTransactionCallback(errCode: number, returnValue: number)
{
	console.log("errCode: " + errCode + "  returnValue: " + returnValue);
}

function testStringTransactionCallback(errCode: number)
{
	console.log("errCode: " + errCode);
}

function jsProxyTriggerCppStub()
{
	let nativeObj = nativeMgr.GetNativeObject();
  	let tsProxy = new IdlTestServiceProxy(nativeObj);	
  	// invoke testIntTransaction
  	tsProxy.testIntTransaction(10, testIntTransactionCallback);
  	
  	// invoke testStringTransaction
  	tsProxy.testStringTransaction("test", testIntTransactionCallback);
}
```

