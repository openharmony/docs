# OpenHarmony IDL Specifications and User Guide

## IDL Overview
To ensure successful communications between the client and server, interfaces recognized by both parties must be defined. The OpenHarmony Interface Definition Language (IDL) is a tool for defining such interfaces. OpenHarmony IDL decomposes objects to be transferred into primitives that can be understood by the operating system and encapsulates cross-boundary objects based on developers' requirements.

  **Figure 1** IDL interface description

![IDL-interface-description](./figures/IDL-interface-description.png)

**IDL provides the following functions:**

- Declares interfaces provided by system services for external systems, and based on the interface declaration, generates C, C++, JS, or TS code for inter-process communication (IPC) or remote procedure call (RPC) proxies and stubs during compilation.

- Declares interfaces provided by abilities for external systems, and based on the interface declaration, generates C, C++, JS, or TS code for IPC or RPC proxies and stubs during compilation.

**Figure 2** IPC/RPC communication model

![IPC-RPC-communication-model](./figures/IPC-RPC-communication-model.png)

**IDL has the following advantages:**

- Services are defined in the form of interfaces in IDL. Therefore, you do not need to focus on implementation details.

- Interfaces defined by IDL can be used in IPC or RPC scenarios. The information or code generated based on the definitions in IDL simplifies IPC or RPC implementation.

## IDL File Structure

### Data Types

#### Primitive Type
| IDL Primitive Type| C++ Primitive Type| TS Primitive Type|
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

The preceding table lists the primitive types supported by IDL and the mappings to the C++ and TS primitive types.

#### sequenceable Type
The sequenceable type is declared using the keyword **sequenceable**. This type can be passed during IPC or RPC through **Parcel** objects. The declaration mode of the sequenceable type in C++ is different from that in TS.

In C++, the declaration is placed in the file header in the format of **sequenceable includedir..namespace.typename**.  It can be in any of the following forms:

```cpp
sequenceable includedir..namespace.typename
sequenceable includedir...typename
sequenceable namespace.typename
```

In the preceding information, **includedir** indicates the directory where the header file of the type is located, and the dot (.) is used as the separator. **namespace** indicates the namespace where the type is located, and the dot (.) is used as the separator. **typename** indicates the data type, which can contain only English characters. **includedir** and **namespace** are separated by two dots (..). If the declaration statement does not contain two dots, all characters except the last typename will be parsed as a namespace. Example:

```cpp
sequenceable a.b..C.D
```

The preceding statement is parsed into the following code in the C++ header file:

```cpp
#include  "a/b/d.h"
using C::D;
```

In TS, the declaration is placed in the file header in the format of **sequenceable namespace.typename;**. It can be in the following form:

```ts
sequenceable idl.MySequenceable
```

In the preceding information, **namespace** indicates the namespace to which the data type belongs, **typename** indicates the data type name, and **MySequenceable** indicates that data can be passed during IPC using **Parcel** objects. The sequenceable type is not defined in the IDL file, but in the .ts file. Therefore, IDL adds the following statement to the generated .ts file based on the declaration:

```ts
import MySequenceable from "./my_sequenceable"
```

Note that IDL does not implement code for this type. It only imports the header file in the specified format or imports the specified module and uses the type. Therefore, you must ensure that the imported directory, namespace, and type are correct.

#### Interface Type
The interface type refers to interfaces defined in IDL files. The interfaces defined in an IDL file can be directly used as the parameter type or return value type of a method declared in the file. If an IDL file attempts to use interfaces defined in other IDL files, forward declaration must be contained in the header of that IDL file.

The declaration form in C++ is similar to that of the sequenceable type. The declaration form is as follows:

```cpp
interface includedir..namespace.typename
```

In TS, the declaration form is as follows:

```ts
interface namespace.interfacename
```

In the preceding information, **namespace** indicates the namespace to which the interface belongs, and **interfacename** indicates the name of the interface. For example, **interface OHOS.IIdlTestObserver;** declares the **IIdlTestObserver** interface defined in another IDL file. This interface can be used as the parameter type or return value type of a method in the current file. IDL adds the following statement to the generated .ts file based on the statement:

```ts
import IIdlTestObserver from "./i_idl_test_observer"
```

#### Array Type
The array type is represented by T[], where **T** can be the primitive, sequenceable, interface, or array type. In C++, this type is generated as **std::vector&lt;T&gt;**.
The table below lists the mappings between the IDL array type and TS and C++ data types.

|IDL Data Type | C++ Data Type          | TS Data Type    |
|   -------              |  --------            |  --------    |
|T[]                     | std::vector&lt;T&gt; | T[]          |

#### Container Type
IDL supports two container types: List and Map. The List container is represented in the format of **List&lt;T&gt;**. The Map container is represented in the format of **Map<KT,VT>**, where **T**, **KT**, and **VT** can be of the primitive, sequenceable, interface, array, or container type.

In C++, the List container type is generated as **std::list**, and the Map container type is generated as **std::map**.

In TS, the List container type is not supported, and the Map container type is generated as **Map**.

The table below lists the mappings between the IDL container type and TS and C++ data types.

|IDL Data Type | C++ Data Type      | TS Data Type    |
|   --------             |  --------        |  -------     |
|List&lt;T&gt;           | std::list        | Not supported       |
|Map<KT,VT>              | std::map         | Map          |


### Specifications for Compiling IDL Files
Only one interface type can be defined in an IDL file, and the interface name must be the same as the file name. The interface definition of the IDL file is described in Backus-Naur form (BNF). The basic definition format is as follows:

```
[<*interface_attr_declaration*>]interface<*interface_name_with_namespace*>{<*method_declaration*>}
```

In the preceding information, <*interface_attr_declaration*> declares interface attributes. Currently, only the **oneway** attribute is supported, indicating that all methods in the interface are unidirectional. Such a method returns value without waiting for the execution to complete. This attribute is optional. If this attribute is not set, synchronous call is used. The interface name must contain the complete interface header file directory, namespace, and method declaration. Empty interfaces are not allowed.
The method declaration format in the interface is as follows:

```
[<*method_attr_declaration*>]<*result_type*><*method_declaration*>
```

In the preceding information, <*method_attr_declaration*> describes the interface attributes. Currently, only the **oneway** attribute is supported, indicating that the method is unidirectional. Such a method returns value without waiting for the execution to complete. This attribute is optional. If this attribute is not set, synchronous call is used. <*result_type*> indicates the type of the return value, and <*method_declaration*> indicates the method name and parameter declaration.
The parameter declaration format is as follows:

```
[<*formal_param_attr*>]<*type*><*identifier*>
```

The value of <*formal_param_attr*> can be **in**, **out**, or **inout**, indicating that the parameter is an input parameter, an output parameter, or both an input and an output parameter, respectively. A **oneway** method does not allow **output** or **inout** parameters or return values.

## How to Develop

### Development Using C++

#### Creating an IDL File

 You can use C++ to create IDL files. An example IDL file is as follows:

```cpp
  interface OHOS.IIdlTestService {
      int TestIntTransaction([in] int data);
      void TestStringTransaction([in] String data);
  }
```

You can run the **./idl -gen-cpp -d dir -c dir/iTest.idl** command (**-d** indicates the output directory) to generate the interface file, stub file, and proxy file in the **dir** directory in the execution environment. The names of the generated interface class files are the same as that of the IDL file, except that the file name extensions are **.h** and **.cpp**. For example, the files generated for **IIdlTestService.idl** are **i_idl_test_service.h**, **idl_test_service_proxy.h**, **idl_test_service_stub.h**, **idl_test_service_proxy.cpp**, and **idl_test_service_stub.cpp**.

#### Exposing Interfaces on the Server

The stub class generated by IDL is an abstract implementation of the interface class and declares all methods in the IDL file.

```cpp
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

You need to inherit the interface class defined in the IDL file and implement the methods in the class. In addition, you need to register the defined services with SAMGR during service initialization. In the following code snippet, **TestService** inherits the **IdlTestServiceStub** interface class and implements the **TestIntTransaction** and **TestStringTransaction** methods.  

```cpp
#ifndef OHOS_IPC_TEST_SERVICE_H
#define OHOS_IPC_TEST_SERVICE_H

#include "hilog/log.h"
#include "log_tags.h"
#include "idl_test_service_stub.h"

namespace OHOS {
class TestService : public IdlTestServiceStub {
public:
    TestService();
    ~TestService();
    static int Instantiate();
    ErrCode TestIntTransaction(int data, int &rep) override;
    ErrCode TestStringTransaction(const std::string& data) override;
private:
    static constexpr HiviewDFX::HiLogLabel LABEL = { LOG_CORE, LOG_ID_IPC, "TestService" };
};
} // namespace OHOS
#endif // OHOS_IPC_TEST_SERVICE_H
```

The sample code for registering a service is as follows:

```cpp
#include "test_service.h"

#include <string_ex.h>

#include "if_system_ability_manager.h"
#include "ipc_debug.h"
#include "ipc_skeleton.h"
#include "iservice_registry.h"
#include "system_ability_definition.h"

namespace OHOS {
using namespace OHOS::HiviewDFX;

int TestService::Instantiate()
{
    ZLOGI(LABEL, "%{public}s call in", __func__);
    auto saMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    if (saMgr == nullptr) {
        ZLOGE(LABEL, "%{public}s:fail to get Registry", __func__);
        return -ENODEV;
    }

    sptr<IRemoteObject> newInstance = new TestService();
    int result = saMgr->AddSystemAbility(IPC_TEST_SERVICE, newInstance);
    ZLOGI(LABEL, "%{public}s: IPC_TEST_SERVICE result = %{public}d", __func__, result);
    return result;
}

TestService::TestService()
{
}

TestService::~TestService()
{
}

ErrCode TestService::TestIntTransaction(int data, int &rep)
{
    ZLOGE(LABEL, " TestService:read from client data = %{public}d", data);
    rep = data + data;
    return ERR_NONE;
}

ErrCode TestService::TestStringTransaction(const std::string &data)
{
    ZLOGE(LABEL, "TestService:read string from client data = %{public}s", data.c_str());
    return data.size();
}
} // namespace OHOS
```

#### Calling Methods from the Client for IPC

The C++ client obtains the service proxy defined in the system through SAMGR and then invokes the interface provided by the proxy. The sample code is as follows:

```cpp
#include "test_client.h"

#include "if_system_ability_manager.h"
#include "ipc_debug.h"
#include "ipc_skeleton.h"
#include "iservice_registry.h"
#include "system_ability_definition.h"

namespace OHOS {
int TestClient::ConnectService()
{
    auto saMgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    if (saMgr == nullptr) {
        ZLOGE(LABEL, "get registry fail");
        return -1;
    }

    sptr<IRemoteObject> object = saMgr->GetSystemAbility(IPC_TEST_SERVICE);
    if (object != nullptr) {
        ZLOGE(LABEL, "Got test Service object");
        testService_ = (new (std::nothrow) IdlTestServiceProxy(object));
    }

    if (testService_ == nullptr) {
        ZLOGE(LABEL, "Could not find Test Service!");
        return -1;
    }

    return 0;
}

void TestClient::StartIntTransaction()
{
    if (testService_ != nullptr) {
        ZLOGE(LABEL, "StartIntTransaction");
        [[maybe_unused]] int result = 0;
        testService_->TestIntTransaction(1234, result); // 1234 : test number
        ZLOGE(LABEL, "Rec result from server %{public}d.", result);
    }
}

void TestClient::StartStringTransaction()
{
    if (testService_ != nullptr) {
        ZLOGI(LABEL, "StartIntTransaction");
        testService_->TestStringTransaction("IDL Test");
    }
}
} // namespace OHOS
```

### Development Using TS

#### Creating an IDL File

 You can use TS to create IDL files. An example IDL file is as follows:

```ts
  interface OHOS.IIdlTestService {
      int TestIntTransaction([in] int data);
      void TestStringTransaction([in] String data);
  }
```

Run the **./idl -c IIdlTestService.idl -gen-ts -d /data/ts/** command (**-d** indicates the output directory) to generate the interface file, stub file, and proxy file in the **/data/ts** directory in the execution environment. The names of the generated interface class files are the same as that of the IDL file, except that the file name extension is **.ts**. For example, the files generated for the **IIdlTestService.idl** file are **i_idl_test_service.ts**, **idl_test_service_proxy.ts**, and **idl_test_service_stub.ts**.

#### Exposing Interfaces on the Server

The stub class generated by IDL is an abstract implementation of the interface class and declares all methods in the IDL file.

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

You need to inherit the interface class defined in the IDL file and implement the methods in the class. The following code snippet shows how to inherit the **IdlTestServiceStub** interface class and implement the **testIntTransaction** and **testStringTransaction** methods.  

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

After the service implements the interface, the interface needs to be exposed to the client for connection. If your service needs to expose this interface, extend **Ability** and implement **onConnect()** to return **IRemoteObject** so that the client can interact with the service process. The following code snippet shows how to expose the **IRemoteAbility** interface to the client:

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

#### Calling Methods from the Client for IPC

When the client calls **connectAbility()** to connect to a Service ability, the **onConnect** callback in **onAbilityConnectDone** of the client receives the **IRemoteObject** instance returned by the **onConnect()** method of the Service ability. The client and Service ability are in different applications. Therefore, the directory of the client application must contain a copy of the .idl file (the SDK automatically generates the proxy class). The **onConnect** callback then uses the **IRemoteObject** instance to create the **testProxy** instance of the **IdlTestServiceProxy** class and calls the related IPC method. The sample code is as follows:

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

#### Transferring a sequenceable Object During IPC

You can send a class from one process to another through IPC interfaces. However, you must ensure that the peer can use the code of this class and this class supports the **marshalling** and **unmarshalling** methods. OpenHarmony uses **marshalling** and **unmarshalling** to serialize and deserialize objects into objects that can be identified by each process.

**To create a class that supports the sequenceable type, perform the following operations:**

1. Implement the **marshalling** method, which obtains the current state of the object and serializes the object into a **Parcel** object.
2. Implement the **unmarshalling** method, which deserializes the object from a **Parcel** object.

The following is an example of the **MySequenceable** class code:

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

## How to Develop for Interworking Between C++ and TS

### TS Proxy and C++ Stub Development

#### C++ Service Object

1. Use C++ to construct an IDL file and run commands to generate interfaces, stub files, and proxy files.

2. Create a service object, inherit the interface class defined in the C++ stub file, and implement the methods in the class. An example is as follows:

   ```cpp
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

#### Native APIs in C++

C++ provides C++ service objects to TS in the format of native APIs. For example, C++ provides a **GetNativeObject** method, which is used to create an **IdlTestServiceImpl** instance. Using the **NAPI_ohos_rpc_CreateJsRemoteObject** method, you can create a JS remote object for the TS application.

```cpp
NativeValue* GetNativeObject(NativeEngine& engine, NativeCallbackInfo& info)
{
    sptr<IdlTestServiceImpl> impl = new IdlTestServiceImpl();
    napi_value napiRemoteObject = NAPI_ohos_rpc_CreateJsRemoteObject(reinterpret_cast<napi_env>(&engine), impl);
    NativeValue* nativeRemoteObject = reinterpret_cast<NativeValue*>(napiRemoteObject);
    return nativeRemoteObject;
}
```

#### TS Proxy Object

Use TS to construct an IDL file and run commands to generate interfaces, stub files, and proxy files. An example proxy file is as follows:

```ts
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
        let _option = new rpc.MessageOption();
        let _data = new rpc.MessageParcel();
        let _reply = new rpc.MessageParcel();
        _data.writeInt(data);
        this.proxy.sendRequest(IdlTestServiceProxy.COMMAND_TEST_INT_TRANSACTION, _data, _reply, _option).then(function(result) {
            if (result.errCode == 0) {
                let _errCode = result.reply.readInt();
                if (_errCode != 0) {
                    let _returnValue = undefined;
                    callback(_errCode, _returnValue);
                    return;
                }
                let _returnValue = result.reply.readInt();
                callback(_errCode, _returnValue);
            } else {
                console.log('sendRequest failed, errCode: ' + result.errCode);
            }
        })
    }

    testStringTransaction(data: string, callback: testStringTransactionCallback): void
    {
        let _option = new rpc.MessageOption();
        let _data = new rpc.MessageParcel();
        let _reply = new rpc.MessageParcel();
        _data.writeString(data);
        this.proxy.sendRequest(IdlTestServiceProxy.COMMAND_TEST_STRING_TRANSACTION, _data, _reply, _option).then(function(result) {
            if (result.errCode == 0) {
                let _errCode = result.reply.readInt();
                callback(_errCode);
            } else {
                console.log('sendRequest failed, errCode: ' + result.errCode);
            }
        })
    }

    static readonly COMMAND_TEST_INT_TRANSACTION = 1;
    static readonly COMMAND_TEST_STRING_TRANSACTION = 2;
    private proxy
}
```

#### Interworking Between TS and C++ Applications

1. The TS application invokes the native API to obtain the remote C++ service object.
2. Construct a TS proxy and transfers the remote C++ service object to it.
3. Use the TS proxy to call the method declared in the IDL file to implement the interworking between the TS proxy and C++ stub. The following is an example:

```ts
import IdlTestServiceProxy from './idl_test_service_proxy'
import nativeMgr from 'nativeManager';

function testIntTransactionCallback(errCode: number, returnValue: number)
{
	console.log('errCode: ' + errCode + '  returnValue: ' + returnValue);
}

function testStringTransactionCallback(errCode: number)
{
	console.log('errCode: ' + errCode);
}

function jsProxyTriggerCppStub()
{
	let nativeObj = nativeMgr.GetNativeObject();
  	let tsProxy = new IdlTestServiceProxy(nativeObj);	
  	// Call testIntTransaction.
  	tsProxy.testIntTransaction(10, testIntTransactionCallback);
  	
  	// Call testStringTransaction.
    tsProxy.testStringTransaction('test', testIntTransactionCallback);
}
```
