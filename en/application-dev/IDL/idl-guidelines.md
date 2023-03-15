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

### Obtaining IDL
On DevEco Studio, choose **Tools > SDK Manager** to view the local installation path of the OpenHarmony SDK. The following figure uses DevEco Studio 3.0.0.993 as an example.
![SDKpath](./figures/SDKpath.png)
![SDKpath](./figures/SDKpath2.png)

Go to the local installation path, choose **toolchains > 3.x.x.x** (the folder named after the version number), and check whether the executable file of IDL exists.

> **NOTE**: Use the SDK of the latest version. The use of an earlier version may cause errors in some statements.

If the executable file does not exist, download the SDK package from the mirror as instructed in the [Release Notes](../../release-notes). The following uses the [3.2 Beta3](../../release-notes/OpenHarmony-v3.2-beta3.md#acquiring-source-code-from-mirrors) as an example.

For details about how to replace the SDK package, see [Guide to Switching to Full SDK](../quick-start/full-sdk-switch-guide.md).

After obtaining the executable file, perform subsequent development steps based on your scenario.

### Development Using TS

#### Creating an IDL File

You can use TS to create IDL files.

 For example, create a file named **IIdlTestService.idl** with the following content: 

```cpp
  interface OHOS.IIdlTestService {
      int TestIntTransaction([in] int data);
      void TestStringTransaction([in] String data);
  }
```

Run the **idl -gen-ts -d *dir* -c dir/IIdlTestService.idl** command in the folder where the executable file is located.

-*dir* next to **d** is the target output folder. For example, if the target output folder is **IIdlTestServiceTs**, run the **idl -gen-ts -d IIdlTestServiceTs -c IIdlTestServiceTs/IIdlTestService.idl** command in the folder where the executable file is located. The interface file, stub file, and proxy file are generated in the *dir* directory (**IIdlTestServiceTs** directory in this example) in the execution environment.

> **NOTE**: The generated interface class file name must be the same as that of the .idl file. Otherwise, an error occurs during code generation.

For example, for an .idl file named **IIdlTestService.idl** and target output directory named **IIdlTestServiceTs**, the directory structure is similar to the following:

```
├── IIdlTestServiceTs  # IDL code output folder
│   ├── i_idl_test_service.ts  # File generated
│   ├── idl_test_service_proxy.ts  # File generated
│   ├── idl_test_service_stub.ts  # File generated
│   └── IIdlTestService.idl  # Constructed .idl file
└── idl.exe  # Executable file of IDL
```

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
    
    async onRemoteRequestEx(code: number, data, reply, option): Promise<boolean> {
        console.log("onRemoteRequestEx called, code = " + code);
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
