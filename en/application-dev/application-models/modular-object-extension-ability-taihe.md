# Implementing IPC Communication for ModularObjectExtensionAbility with Taihe (C/C++)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=6b23d240ae1c164f2ceb5bb9d0bf454aa0b80361 translatedAt=2026-08-18T01:31:59.882Z pushedAt=2026-08-18T11:25:20.812Z -->

Starting from API version 26.0.0, [Taihe](ability-terminology.md#taihe) can automatically generate the Proxy/Stub code and type library files required by ModularObjectExtensionAbility (for the related C API definitions, see [modular_object_extension_ability.h](../reference/apis-ability-kit/capi-modular-object-extension-ability-h.md)), shielding the underlying details of IPC communication (such as parameter serialization/deserialization and message code dispatching). This allows developers to focus on interface design and business logic, greatly simplifying the development process of ModularObjectExtensionAbility.

## Command Line Usage

Taihe provides the core compiler tool [taihec](ability-terminology.md#taihec), which parses `ohidl` files and compiles them into target-language code. This section describes how to use `taihec` to generate the Proxy and Stub code required by ModularObjectExtensionAbility in IPC communication scenarios. For details about Proxy and Stub, see [Basic Concepts](modular-object-extension-overview.md#basic-concepts) in [Modular Object Model Overview (C/C++)](modular-object-extension-overview.md).

**Obtaining the taihec tool:**

The taihec tool is released with the SDK and is located in the DevEco Studio/sdk/default/openharmony/toolchains/taihe/bin directory.

**Basic command format:**

```bash
taihec [taihe_files ...] [options ...]
```

- `taihe_files`: one or more interface definition files `ohidl`. The main interface file and common type files must be listed together.

- `options`: specifies various options for code generation.

**Command-line parameter description:**

| Name | Short Form | Mandatory | Description |
| --- | --- | --- | ---|
| `--output <path>` | `-O <path>` | Required | Specifies the directory for storing the generated target files (.cpp/.h). |
| `--generate <backend>` | `-G <backend>` | Optional | Specifies the code generation backend. In the IPC communication scenario of ModularObjectExtensionAbility, `modobj-ipc` is always used. |
| `--codegen <namespace>:<config>[=<value>]` | `-C <namespace>:<config>[=<value>]` | Optional | Additional code generation configuration items. In the IPC communication scenario of ModularObjectExtensionAbility, only `modobj:ipc-common=common.ohidl` is supported, which is used to import common type files. |

**Code generation example:**

When the main interface file needs to reference data types from other files, use the -C parameter to include common type files (which define common data types such as structs and enums). A generation command with the -C parameter generates the common data types separately into the ExampleServiceIpcTypes.cpp and ExampleServiceIpcTypes.h files.

```bash
taihec -G modobj-ipc -O example/generated/IBasicTypes_ohidl_c -C modobj:ipc-common=example/ExampleServiceIpcTypes.ohidl example/IBasicTypes.ohidl
```

All types are defined in the main interface file, and no other files need to be referenced.

```bash
taihec -G modobj-ipc -O example/generated example/Easy.ohidl
```

## ohidl File Writing Specifications

This section describes the data types supported in the `ohidl` file, how to use annotations, and sample files, helping developers write `ohidl` files.

### Data Types and Annotations

**Basic Data Types:**

| Taihe     | C++ Type   | Parcel Write/Read Rules                                         |
| :-------  | :------    | :--------------------------------------------------------   |
| `bool`    | `bool`     | `OH_IPCParcel_WriteInt32`/`OH_IPCParcel_ReadInt32`      |
| `i8`      | `int8_t`   | `OH_IPCParcel_WriteInt8`/`OH_IPCParcel_ReadInt8`       |
| `i16`     | `int16_t`  | `OH_IPCParcel_WriteInt16`/`OH_IPCParcel_ReadInt16`      |
| `i32`     | `int32_t`  | `OH_IPCParcel_WriteInt32`/`OH_IPCParcel_ReadInt32`      |
| `i64`     | `int64_t`  | `OH_IPCParcel_WriteInt64`/`OH_IPCParcel_ReadInt64`      |
| `f32`     | `float`    | `OH_IPCParcel_WriteFloat`/`OH_IPCParcel_ReadFloat`      |
| `f64`     | `double`   | `OH_IPCParcel_WriteDouble`/`OH_IPCParcel_ReadDouble`     |
| `u8`      | `uint8_t`  | `OH_IPCParcel_WriteUint8_t`/`OH_IPCParcel_ReadUint8_t`    |
| `u16`     | `uint16_t` | `OH_IPCParcel_WriteUint16_t`/`OH_IPCParcel_ReadUint16_t`   |
| `u32`     | `uint32_t` | `OH_IPCParcel_WriteUint32_t`/`OH_IPCParcel_ReadUint32_t`   |
| `u64`     | `uint64_t` | `OH_IPCParcel_WriteUint64_t`/`OH_IPCParcel_ReadUint64_t`   |

**Complex Data Types:**

| Taihe               | C++ Type                     | Parcel Write/Read Rules                                                         |
| :---                | :---                         | :---                                                                        |
| `String`            | `std::string`                | Converted to `const char*` and then written/read with `OH_IPCParcel_WriteString`/`OH_IPCParcel_ReadString`. |
| `enum`              | `enum`                       | Serialized as `int32_t`.                                                          |
| `Vector<T>`         | `std::vector<T>`             | Write the size first, then serialize each item sequentially.                                                       |
| `@size(N) Array<T>` | `std::array<T, N>`           | Write the size first, then serialize each item sequentially.                                                       |
| `Set<T>`            | `std::set<T>`                | Write the size first, then serialize each item sequentially.                                                       |
| `Map<K,V>`          | `std::map<K, V>`             | Write the size first, then write key/value sequentially.                                               |
| `struct`            | `struct&`                    | Calls the generated `Marshalling/Unmarshalling`.                                     |
| `interface`         | `interface&`                 | Writes `OHIPCRemoteStub` or `OHIPCRemoteProxy`, and reads `OHIPCRemoteProxy`.         |

**Annotation and Usage:**

| Annotation                       | Scope      | Description                                    | Example                            |                   
| :---                             | :---       | :---                                           | :---                               |                     
| `@main_service(version="x.y.z")` | interface  | Only one main service interface can be declared. The generated Stub serves as the return value of [OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc](../reference/apis-ability-kit/capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_onconnectfunc). | @main_service(version="1.0.0")    |
| `@callback` | Method | Declares a callback interface. The server can hold an instance of this interface to call the client, and the related logic is executed in the client's thread. Typical usage scenarios: the client registers a listener with the server, and the server proactively notifies the client of events. For the complete development process, see the ITestEventCallback example in [Sample File Description](#sample-file-description). | @callback interface ICallback {} |
| `@oneway`                        | Method     | Asynchronous one-way IPC call. Only the void return type is supported. | @oneway Notify(...): void;        |
| `@!namespace("A","B")`           | ohidl file | Sets the namespace of the generated code and the prefix of the IPC interface descriptor string. | @!namespace("OHOS","NativeApp")   |
| `@size(N)`                       | Parameter  | Size of a fixed-length array. Used only for Array type parameters. | @size(4) Array\<i32\>; |

### Sample File Description

The following constraints and restrictions must be observed when writing ohidl files.

**Constraints on ohidl files:**

- The main interface file defines the core service interfaces and is marked with `@main_service`.

- The common types file defines structs and enums, which are reused through `from...use...`.

- The key type of `Map<K, V>` supports only basic data types, `String`, and `enum`.

- Do not change the order of existing methods in an interface; otherwise, the IpcCode will be misaligned and compatibility will be broken. When adding a new method, add it at the end of the interface and keep proper version management records to avoid breaking compatibility by mistake.

    **Interface Version Upgrade Rules:**

    - Adding methods: You can only add new methods at the end of the interface. Do not insert them before existing methods.

    - Deprecating methods: Keep the method declaration but mark it as deprecated. Do not delete it or move its position.

    - Parameter changes: It is recommended to add new methods instead of modifying the parameter signature of existing methods to ensure compatibility with older clients.

- Within a single `modobj-ipc` generation scope, all `interface`, `struct`, and `enum` names must be globally unique, regardless of namespace.

**Sample file:**

<!-- @[example](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionAbilityIDL/exampletwo/ITestInterface.ohidl) -->

```ohipc
@!namespace("OHOS", "IPC")

interface ICalculator {
    Add(a: i32, b: i32): i32;
}

struct OnProgressResult {
    summary: String;
}

@callback
interface ITestEventCallback {
    OnConnected(clientId: i32, welcome: String): void;
    OnProgress(taskId: i32): OnProgressResult;

    @oneway
    OnDisconnected(reason: String): void;
}

@main_service(version = "1.0.0")
interface ITestCallbackService {
    RegisterCallback(callback: ITestEventCallback): i32;
    GetPrimaryCalculator(userId: i32): ICalculator;
}
```

## How to Develop

1. Create the example folder and create the Easy.ohidl file.

   <!-- @[easy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionAbilityIDL/exampleone/example/Easy.ohidl) -->

   ```ohipc
   @!namespace("OHOS", "IPC")
   
   @main_service(version = "1.0.0")
   interface ICalculator {
       Add(a: i32, b: i32): i32;
   }
   ```

2. Use the taihec command to generate code.

   ``` bash
   ./taihec -G modobj-ipc -O ./example/generated ./example/Easy.ohidl
   ```

3. Analyze the generated code files.

   | File Name | Description |
   | --- | --- |
   | `icalculator.h` | Interface definition header file. |
   | `calculator_proxy.h` | Client proxy class declaration. |
   | `calculator_proxy.cpp` | Proxy implementation, which serializes parameters, sends IPC requests, and parses return values. |
   | `calculator_stub.h` | Server-side Stub class declaration. |
   | `calculator_stub.cpp` | Stub implementation, which deserializes requests, invokes the business implementation, and writes back responses. |
   | `calculator.typelib.json` | Type library information file. |

   - icalculator.h

     `GetDescriptor()` returns the interface descriptor string, and the `IpcCode` enum assigns a unique command code to each method, starting from 1001.

     <!-- @[ICalculator](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionAbilityIDL/exampleone/generated/icalculator.h) -->

        ``` C
        class ICalculator {
        public:
            virtual ~ICalculator() = default;
            static const char* GetDescriptor() { return "OHOS.IPC.ICalculator"; }
        
            virtual ErrCode WriteRemoteObject(OHIPCParcel* parcel) const = 0;
        
            enum class IpcCode : uint32_t {
                COMMAND_ADD = 1001,
                COMMAND_GET_TYPE_LIB_INFO = 1,
                COMMAND_GET_VERSION = 2,
                COMMAND_GET_TAIHE_VERSION = 3,
            };
        
            virtual ErrCode Add(int32_t a, int32_t b, int32_t& result) = 0;
            virtual ErrCode GetTypeLibInfo(int32_t fd) = 0;
            virtual ErrCode GetVersion(std::string& result) = 0;
            virtual ErrCode GetTaiheVersion(std::string& result) = 0;
        };
        ```

   - calculator_proxy.h

     `CalculatorProxy` inherits `ICalculator` and contains the remote proxy object `remoteProxy_`.

     <!-- @[CalculatorProxy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionAbilityIDL/exampleone/generated/calculator_proxy.h) -->

        ``` C
        class CalculatorProxy : public ICalculator {
        public:
            explicit CalculatorProxy(OHIPCRemoteProxy* remote) : remoteProxy_(remote) {}
            ~CalculatorProxy() override = default;
        // ...
            ErrCode WriteRemoteObject(OHIPCParcel* parcel) const override;
        
            ErrCode Add(int32_t a, int32_t b, int32_t& result) override;
        // ...
        private:
            OHIPCRemoteProxy* remoteProxy_ = nullptr;
        };
        ```

   - calculator_proxy.cpp

     Create the `OHIPCParcel` request and response packets, and write the interface descriptor and serialized parameters.

     Call `OH_IPCRemoteProxy_SendRequest()` to initiate synchronous IPC, and read the error code and return value from `reply`.

     <!-- @[CalculatorProxy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionAbilityIDL/exampleone/generated/calculator_proxy.cpp) -->

        ``` C++
        ErrCode CalculatorProxy::WriteRemoteObject(OHIPCParcel* parcel) const
        {
            if (parcel == nullptr || remoteProxy_ == nullptr) {
                return OH_IPC_CHECK_PARAM_ERROR;
            }
            if (OH_IPCParcel_WriteRemoteProxy(parcel, remoteProxy_) != OH_IPC_SUCCESS) {
                return OH_IPC_PARCEL_WRITE_ERROR;
            }
            return OH_IPC_SUCCESS;
        }
        
        ErrCode CalculatorProxy::Add(int32_t a, int32_t b, int32_t& result)
        {
        // ...
            std::unique_ptr<OHIPCParcel, ParcelDeleter> parcelData(OH_IPCParcel_Create());
            std::unique_ptr<OHIPCParcel, ParcelDeleter> parcelReply(OH_IPCParcel_Create());
        // ...
            if (OH_IPCParcel_WriteInterfaceToken(parcelData.get(),
                ICalculator::GetDescriptor()) != OH_IPC_SUCCESS) {
                return OH_IPC_PARCEL_WRITE_ERROR;
            }
        
            if (OH_IPCParcel_WriteInt32(parcelData.get(), a) != OH_IPC_SUCCESS) {
                return OH_IPC_PARCEL_WRITE_ERROR;
            }
            if (OH_IPCParcel_WriteInt32(parcelData.get(), b) != OH_IPC_SUCCESS) {
                return OH_IPC_PARCEL_WRITE_ERROR;
            }
        // ...
            int32_t errCode = OH_IPC_SUCCESS;
            if (OH_IPCParcel_ReadInt32(parcelReply.get(), &errCode) != OH_IPC_SUCCESS) {
                return OH_IPC_PARCEL_READ_ERROR;
            }
        
            int32_t resultValue = 0;
            if (OH_IPCParcel_ReadInt32(parcelReply.get(), &resultValue) != OH_IPC_SUCCESS) {
                return OH_IPC_PARCEL_READ_ERROR;
            }
            result = resultValue;
        
            return errCode;
        }
        ```

   - calculator_stub.h

     `CalculatorStub` inherits from `ICalculator`.

     `OnRemoteRequest` serves as the IPC call entry, and `OnRemoteRequestInner` dispatches to the specific `HandleXXX` method based on `code`.

     <!-- @[CalculatorStub](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionAbilityIDL/exampleone/generated/calculator_stub.h) -->

        ``` C
        class CalculatorStub : public ICalculator {
        public:
        // ...
            ErrCode WriteRemoteObject(OHIPCParcel* parcel) const override;
        
            static int32_t OnRemoteRequest(
                uint32_t code,
                const OHIPCParcel* data,
                OHIPCParcel* reply,
                void* userData);
        // ...
        private:
            int32_t OnRemoteRequestInner(uint32_t code, const OHIPCParcel* data, OHIPCParcel* reply);
            int32_t HandleAdd(const OHIPCParcel* data, OHIPCParcel* reply);
        // ...
        };
        ```

   - calculator_stub.cpp

    In the `OnRemoteRequestInner` method, first verify the interface descriptor, then call `HandleAdd` to read parameters from `data`, invoke the actual `Add` business implementation, and write `errCode` and the result back to `reply`.

     <!-- @[CalculatorStub](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionAbilityIDL/exampleone/generated/calculator_stub.cpp) -->

        ``` C++
        int32_t CalculatorStub::OnRemoteRequestInner(uint32_t code, const OHIPCParcel* data, OHIPCParcel* reply)
        {
        // ...
            if (OH_IPCParcel_ReadInterfaceToken(data, &remoteDescriptor,
                &remoteDescriptorLen, OhipcReadInterfaceTokenAllocator) != OH_IPC_SUCCESS) {
                return OH_IPC_CHECK_PARAM_ERROR;
            }
        // ...
            switch (static_cast<ICalculator::IpcCode>(code)) {
                case ICalculator::IpcCode::COMMAND_ADD:
                    return HandleAdd(data, reply);
        // ...
                default:
                    return OH_IPC_CHECK_PARAM_ERROR;
            }
        }
        
        int32_t CalculatorStub::HandleAdd(const OHIPCParcel* data, OHIPCParcel* reply)
        {
            int32_t aValue = 0;
            if (OH_IPCParcel_ReadInt32(data, &aValue) != OH_IPC_SUCCESS) {
                return OH_IPC_PARCEL_READ_ERROR;
            }
            int32_t a = aValue;
        // ...
            int32_t result = 0;
            ErrCode errCode = Add(a, b, result);
            if (OH_IPCParcel_WriteInt32(reply, errCode) != OH_IPC_SUCCESS) {
                return OH_IPC_PARCEL_WRITE_ERROR;
            }
        
            if (OH_IPCParcel_WriteInt32(reply, result) != OH_IPC_SUCCESS) {
                return OH_IPC_PARCEL_WRITE_ERROR;
            }
        
            return OH_IPC_SUCCESS;
        }
        ```

   - calculator.typelib.json

     The type library metadata file stores interface definition information (such as the interface name, descriptor, method name, IPC code, parameter and return types) for runtime querying of method information and dynamic route invocation. The content of this file is embedded into the generated Stub code at compile time, so developers do not need to manually load this JSON file or package it with the app. The following example is only for showing the internal structure of the file.

        ```json
        {
          "version": "1.0",
          "taihe_version": "1.0.0",
          "enums": [],
          "structs": [],
          "interfaces": [
            {
              "memberId": 1,
              "name": "ICalculator",
              "descriptor": "OHOS.IPC.ICalculator",
              "interface_type": 1,
              "methods": [
                {
                  "memberId": 4,
                  "name": "Add",
                  "code": 1001,
                  "oneway": false,
                  "return_type": {
                    "type": "i32"
                  },
                  "parameters": [
                    {
                      "memberId": 2,
                      "name": "a",
                      "type_info": {
                        "type": "i32"
                      }
                    },
                    {
                      "memberId": 3,
                      "name": "b",
                      "type_info": {
                        "type": "i32"
                      }
                    }
                  ]
                }
              ]
            }
          ]
        }
        ```

        In addition to the interface methods defined by developers in the ohidl file, Taihe also automatically generates methods such as GetTypeLibInfo, GetVersion, and GetTaiheVersion.

        | Method            | Default Behavior                                                               | Constant                    |
        | :---              | :---                                                                           |:-----                       |
        | `GetTypeLibInfo`  | Returns the type library information.                                          | COMMAND_GET_TYPE_LIB_INFO = 1 |
        | `GetVersion`      | Returns the version number declared by the `version` field in the `@main_service` annotation. |COMMAND_GET_VERSION = 2      |
        | `GetTaiheVersion` | Returns the version of the Taihe compiler, which is called by the system and does not require developer attention. |COMMAND_GET_TAIHE_VERSION = 3|

4. Using the Proxy and Stub source code.

   The generated Proxy and Stub code can be directly used for IPC communication. On the client side, create a CalculatorProxy instance and pass in an OHIPCRemoteProxy object to call remote methods. On the server side, inherit CalculatorStub and implement the business logic interface.

   For the detailed development process, see [Using ModularObjectExtensionAbility to Implement Modular Objects (C/C++)].
   <!--no_check-->