# 使用Taihe实现ModularObjectExtensionAbility的IPC通信 (C/C++)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

从API版本26.0.0开始，通过[Taihe](ability-terminology.md#taihe)可自动生成ModularObjectExtensionAbility（相关C API定义见[modular_object_extension_ability.h](../reference/apis-ability-kit/capi-modular-object-extension-ability-h.md)）所需的Proxy/Stub代码及类型库文件，屏蔽IPC通信底层细节（如参数序列化/反序列化、消息码分发等），使开发者专注于接口设计与业务逻辑，大幅简化ModularObjectExtensionAbility的开发流程。

## 命令行使用

Taihe提供了核心编译器工具[taihec](ability-terminology.md#taihec)，用于解析`ohidl`文件并将其编译为目标语言代码。本章节介绍如何使用`taihec`生成ModularObjectExtensionAbility在IPC通信场景下所需的Proxy和Stub代码。请参考模块化对象模型概述 (C/C++)的[基本概念](modular-object-extension-overview.md#基本概念)，了解Proxy与Stub。

**taihec工具获取：**

taihec工具随SDK发布，位于DevEco Studio/sdk/default/openharmony/toolchains/taihe/bin目录下。

**命令基本格式：**

```bash
taihec [taihe_files ...] [options ...]
```

- `taihe_files`：一个或多个`ohidl`文件，主接口文件和公共类型文件需一并列出。
- `options`：用于指定代码生成的各种选项。

**命令行参数说明：**

| 参数 | 简写 |  必选/可选|说明 |
| --- | --- | --- | ---|
| `--output <path>` | `-O <path>` |  必选|指定生成的目标文件（.cpp/.h格式）存放目录。 |
| `--generate <backend>` | `-G <backend>` | 可选|指定代码生成后端。在ModularObjectExtensionAbility的IPC通信场景下，固定使用`modobj-ipc`。 |
| `--codegen <namespace>:<config>[=<value>]` | `-C <namespace>:<config>[=<value>]` | 可选|额外的代码生成配置项。ModularObjectExtensionAbility的IPC通信场景下仅支持`modobj:ipc-common=common.ohidl`，用于引入公共类型文件。 |

**执行代码生成示例：**

当主接口文件需要引用其他文件中的数据类型时，通过-C参数引入公共数据类型文件。带-C参数的生成命令会将公共数据类型单独生成到ExampleServiceIpcTypes.cpp和ExampleServiceIpcTypes.h文件中。
```bash
taihec -G modobj-ipc -O example/generated/IBasicTypes_ohidl_c -C modobj:ipc-common=example/ExampleServiceIpcTypes.ohidl example/IBasicTypes.ohidl
```
所有类型都定义在主接口文件中，无需引用其他文件。
```bash
taihec -G modobj-ipc -O example/generated example/Easy.ohidl
```

## ohidl文件编写规范

本节介绍`ohidl`文件中支持的数据类型、注解使用方式以及示例文件，帮助开发者编写`ohidl`文件。

### 数据类型与注解

**基础数据类型：**

| Taihe     | C++类型   | Parcel写入/读取规则                                         |
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

**复杂数据类型：**

| Taihe               | C++类型                     | Parcel写入/读取规则                                                         |
| :---                | :---                         | :---                                                                        |
| `String`            | `std::string`                | 转为`const char*`后`OH_IPCParcel_WriteString`/`OH_IPCParcel_ReadString`。 |
| `enum`              | `enum`                       | 按`int32_t`序列化。                                                          |
| `Vector<T>`         | `std::vector<T>`             | 先写size，再逐项序列化。                                                       |
| `@size(N) Array<T>` | `std::array<T, N>`           | 先写size，再逐项序列化。                                                       |
| `Set<T>`            | `std::set<T>`                | 先写size，再逐项序列化。                                                       |
| `Map<K,V>`          | `std::map<K, V>`             | 先写size，再顺序写入key/value。                                               |
| `struct`            | `struct&`                    | 调用生成的`Marshalling/Unmarshalling`。                                     |
| `interface`         | `interface&`                 | 写入`OHIPCRemoteStub`或`OHIPCRemoteProxy`，读取`OHIPCRemoteProxy`。         |

**注解与使用：**

| 注解                             | 作用范围   |说明                                    | 示例                               |                   
| :---                             | :---       | :---                                  | :---                               |                     
| `@main_service(version="x.y.z")` | interface     | 有且仅能声明一个主服务接口，生成的Stub作为[OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc](../reference/apis-ability-kit/capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_onconnectfunc)的返回值。  | @main_service(version="1.0.0")    |
| `@callback`                      | 方法       | 用于声明一个回调接口。服务端可持有此接口的实例来调用客户端，相关逻辑会在客户端的线程中执行。 | @callback interface ICallback {}  |
| `@oneway`                        | 方法       | 异步单向IPC调用，仅支持void类型返回值。       | @oneway Notify(...): void;        |
| `@!namespace("A","B")`           | ohidl文件   | 设置生成代码所在的命名空间，以及IPC接口描述符字符串前缀。 | @!namespace("OHOS","NativeApp")   |
| `@size(N)`                       | 参数       | 定长数组的大小，仅供Array类型参数使用。  | @size(4) Array\<i32\>; |

### 示例文件说明

编写ohidl文件时需要遵循以下约束与限制。

**ohidl文件的约束与限制：**
- 主接口文件定义服务核心接口，使用`@main_service`标记。
- 公共类型文件定义结构体、枚举，通过from...use...复用。
- `Map<K, V>`的键类型仅支持基础数据类型、`String`和`enum`。
- 严禁调换interface中已有方法的顺序，否则将导致IpcCode错位而破坏兼容性。
- 单次`modobj-ipc`生成范围内，所有`interface`、`struct`和`enum`名称必须全局唯一，不受命名空间限制。

**文件示例：**

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

## 开发步骤

1. 创建example文件夹，并新建Easy.ohidl文件。

   <!-- @[easy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ModularObjectExtensionAbilityIDL/exampleone/example/Easy.ohidl) -->
   
   ```ohipc
   @!namespace("OHOS", "IPC")
   
   @main_service(version = "1.0.0")
   interface ICalculator {
       Add(a: i32, b: i32): i32;
   }
   ```

2. 使用taihec命令生成代码。

   ``` bash
   ./taihec -G modobj-ipc -O ./example/generated ./example/Easy.ohidl
   ```

3. 生成的代码文件解析。

   | 文件名 | 说明 |
   | --- | --- |
   | `icalculator.h` | 接口定义头文件。 |
   | `calculator_proxy.h` | 客户端代理类声明。 |
   | `calculator_proxy.cpp` | 代理实现，负责参数序列化、发送IPC请求、解析返回值。 |
   | `calculator_stub.h` | 服务端Stub类声明。 |
   | `calculator_stub.cpp` | Stub实现，负责反序列化请求、调用业务实现、写回响应。 |
   | `calculator.typelib.json` | 类型库信息文件。 |

   - icalculator.h

     `GetDescriptor()`返回接口描述符字符串，`IpcCode`枚举为每个方法分配唯一命令码，从1001开始。

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

     `CalculatorProxy`继承`ICalculator`，并包含了远端代理对象`remoteProxy_`。

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

     创建`OHIPCParcel`请求包和响应包，写入接口描述符和序列化参数。

     调用`OH_IPCRemoteProxy_SendRequest()`发起同步IPC，并读取`reply`中的错误码与返回值。

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

     `CalculatorStub`继承`ICalculator`。

     `OnRemoteRequest`作为IPC调用入口，`OnRemoteRequestInner`根据`code`分发到具体`HandleXXX`方法。

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

     `OnRemoteRequestInner`方法中先校验接口描述符，再调用`HandleAdd`从`data`中读取参数，调用真实`Add`业务实现，并将`errCode`和结果写回`reply`。

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

     保存接口名称、描述符、方法名、IPCcode、参数与返回类型。

     用于运行时查询方法元数据和动态路由。

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
        除开发者自定义的接口外，还会自动生成`GetTypeLibInfo`、`GetVersion`、`GetTaiheVersion`等方法。

        | 方法              | 默认行为                                                                         | 常量                        |
        | :---              | :---                                                                            |:-----                       |
        | `GetTypeLibInfo`  | 返回类型库信息。                                               | COMMAND_GET_TYPE_LIB_INFO = 1 |
        | `GetVersion`      | 返回`@main_service`注解中 version 声明的版本号。                                  |COMMAND_GET_VERSION = 2      |
        | `GetTaiheVersion` | 返回Taihe编译器的版本，供系统调用，开发者无需关注。                                 |COMMAND_GET_TAIHE_VERSION = 3|

4. Proxy和Stub源码的使用。

   请参考[使用ModularObjectExtensionAbility实现模块化对象 (C/C++)](./modular-object-extension-development.md)。