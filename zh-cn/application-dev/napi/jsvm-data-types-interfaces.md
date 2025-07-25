# JSVM-API 支持的数据类型和接口

## JSVM-API 的数据类型

### `JSVM_Status`

    这是一个枚举数据类型，用来表示 JSVM-API 接口返回的状态信息。

    每调用一次 JSVM-API 函数，都会返回一个值，用来表示操作成功与否的相关信息。

```c++
    typedef enum {
        JSVM_OK,                              /* 成功状态 */
        JSVM_INVALID_ARG,                     /* 无效的状态 */
        JSVM_OBJECT_EXPECTED,                 /* 期待传入对象类型 */
        JSVM_STRING_EXPECTED,                 /* 期待传入字符串类型 */
        JSVM_NAME_EXPECTED,                   /* 期待传入名字 */
        JSVM_FUNCTION_EXPECTED,               /* 期待传入函数类型 */
        JSVM_NUMBER_EXPECTED,                 /* 期待传入数字类型 */
        JSVM_BOOL_EXPECTED,                   /* 期待传入布尔类型 */
        JSVM_ARRAY_EXPECTED,                  /* 期待传入数组类型 */
        JSVM_GENERIC_FAILURE,                 /* 泛型失败状态 */
        JSVM_PENDING_EXCEPTION,               /* 挂起异常状态 */
        JSVM_CANCELLED,                       /* 取消状态 */
        JSVM_ESCAPE_CALLED_TWICE,             /* 转义调用了2次 */
        JSVM_HANDLE_SCOPE_MISMATCH,           /* 句柄作用域不匹配 */
        JSVM_CALLBACK_SCOPE_MISMATCH,         /* 回调作用域不匹配 */
        JSVM_QUEUE_FULL,                      /* 队列满 */
        JSVM_CLOSING,                         /* 关闭中 */
        JSVM_BIGINT_EXPECTED,                 /* 期望传入Bigint类型 */
        JSVM_DATE_EXPECTED,                   /* 期望传入日期类型 */
        JSVM_ARRAYBUFFER_EXPECTED,            /* 期望传入ArrayBuffer类型 */
        JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED, /* 可分离的数组缓冲区预期状态 */
        JSVM_WOULD_DEADLOCK,                  /* 将死锁状态 */
        JSVM_NO_EXTERNAL_BUFFERS_ALLOWED,     /* 不允许外部缓冲区 */
        JSVM_CANNOT_RUN_JS,                   /* 不能执行JS */
        JSVM_INVALID_TYPE,                    /* 非法类型 */
        JSVM_JIT_MODE_EXPECTED,                /* 期望在JIT模式下执行 */
    } JSVM_Status;
```

### JSVM_ExtendedErrorInfo

一个结构体，在调用函数不成功时存储了较为详细的错误信息。

```c++
typedef struct {
    const char* errorMessage;
    void* engineReserved;
    uint32_t engineErrorCode;
    JSVM_Status errorCode;
} JSVM_ExtendedErrorInfo;
```

### JSVM_Value

在C++代码中，表示JavaScript值。

### JSVM_Env

- 表示JSVM-API执行时的上下文，作为Native函数的参数传递给JSVM-API接口。

- 退出Native侧插件时，JSVM_Env将失效，该事件通过回调传递给OH_JSVM_SetInstanceData。

- 禁止缓存JSVM_Env，并禁止在不同Worker中传递JSVM_Env。

- 在不同线程间共享JSVM_Env时，要保证在线程切换时在前一个线程中关闭env scope并在新的线程中打开新的env scope，以保证threadlocal变量的线程隔离。

### JSVM_ValueType

JSVM_Value的类型。包含了ECMAScript语言规范中定义的类型，其中JSVM_EXTERNAL表示外部数据类型。

```c++
typedef enum {
    JSVM_UNDEFINED,
    JSVM_NULL,
    JSVM_BOOLEAN,
    JSVM_NUMBER,
    JSVM_STRING,
    JSVM_SYMBOL,
    JSVM_OBJECT,
    JSVM_FUNCTION,
    JSVM_EXTERNAL,
    JSVM_BIGINT,
} JSVM_ValueType;
```

### JSVM_TypedarrayType

TypedArray 的基本二进制标量数据类型。

```c++
typedef enum {
    JSVM_INT8_ARRAY,
    JSVM_UINT8_ARRAY,
    JSVM_UINT8_CLAMPED_ARRAY,
    JSVM_INT16_ARRAY,
    JSVM_UINT16_ARRAY,
    JSVM_INT32_ARRAY,
    JSVM_UINT32_ARRAY,
    JSVM_FLOAT32_ARRAY,
    JSVM_FLOAT64_ARRAY,
    JSVM_BIGINT64_ARRAY,
    JSVM_BIGUINT64_ARRAY,
} JSVM_TypedarrayType;
```

### JSVM_RegExpFlags

正则表达式标志位。

```c++
typedef enum {
    JSVM_REGEXP_NONE = 0,
    JSVM_REGEXP_GLOBAL = 1 << 0,
    JSVM_REGEXP_IGNORE_CASE = 1 << 1,
    JSVM_REGEXP_MULTILINE = 1 << 2,
    JSVM_REGEXP_STICKY = 1 << 3,
    JSVM_REGEXP_UNICODE = 1 << 4,
    JSVM_REGEXP_DOT_ALL = 1 << 5,
    JSVM_REGEXP_LINEAR = 1 << 6,
    JSVM_REGEXP_HAS_INDICES = 1 << 7,
    JSVM_REGEXP_UNICODE_SETS = 1 << 8,
} JSVM_RegExpFlags;
```

### 编译选项相关类型
#### JSVM_CompileOptions

配合 OH_JSVM_CompileScriptWithOptions 接口使用，是其参数中 options 数组的元素类型。

其中：
- id 代表这个编译选项的类型。
- content 代表编译选项的内容。

id 的值和 content 的类型需对应使用，具体对应关系请参见各选项类型的介绍。

```c
typedef struct {
    /** compile option id. */
    JSVM_CompileOptionId id;
    /** option content. */
    union {
      /** ptr type. */
      void *ptr;
      /** int type. */
      int num;
      /** bool type. */
      _Bool boolean;
    } content;
} JSVM_CompileOptions;
```

#### JSVM_CompileOptionId

JSVM_CompileOptions 中的 id 对应类型，每个值有对应的 content 类型。JSVM_COMPILE_ENABLE_SOURCE_MAP 的类型为 bool，当 JSVM_ScriptOrigin 中的 sourceMapUrl 不为空时生效。

```c
typedef enum {
    /** compile mode. */
    JSVM_COMPILE_MODE,
    /** code cache content. */
    JSVM_COMPILE_CODE_CACHE,
    /** script origin. */
    JSVM_COMPILE_SCRIPT_ORIGIN,
    /** compile profile content. */
    JSVM_COMPILE_COMPILE_PROFILE,
    /** switch for source map support. */
    JSVM_COMPILE_ENABLE_SOURCE_MAP,
} JSVM_CompileOptionId;
```

#### JSVM_CompileMode

当 id 为 JSVM_COMPILE_MODE 时，content 类型的每个值代表一种编译模式。

- JSVM_COMPILE_MODE_DEFAULT : 默认的编译选项。
- JSVM_COMPILE_MODE_CONSUME_CODE_CACHE : 消耗 codecache 进行编译。
- JSVM_COMPILE_MODE_EAGER_COMPILE : 进行全量编译，不再进行 lazy compile。
- JSVM_COMPILE_MODE_PRODUCE_COMPILE_PROFILE/JSVM_COMPILE_MODE_CONSUME_COMPILE_PROFILE : 当前暂无效果，请等待后续更新。

```c
typedef enum {
    /** default mode. */
    JSVM_COMPILE_MODE_DEFAULT,
    /** consume code cache. */
    JSVM_COMPILE_MODE_CONSUME_CODE_CACHE,
    /** apply eager compile. */
    JSVM_COMPILE_MODE_EAGER_COMPILE,
    /** preset for compile profile. */
    JSVM_COMPILE_MODE_PRODUCE_COMPILE_PROFILE,
    /** consume compile profile. */
    JSVM_COMPILE_MODE_CONSUME_COMPILE_PROFILE,
} JSVM_CompileMode;
```


#### JSVM_CodeCache

当 id 为 JSVM_COMPILE_CODE_CACHE 时，content 的类型为：

- cache : 指向 code cache 的指针。
- length : 代表 code cache 的大小。

```c
typedef struct {
    /** cache pointer. */
    uint8_t *cache;
    /** length. */
    size_t length;
} JSVM_CodeCache;
```

#### JSVM_ScriptOrigin

当 id 为 JSVM_COMPILE_SCRIPT_ORIGIN 时，content 存放待编译脚本的源码信息。

- sourceMapUrl : sourceMap 的路径，当前仅支持运行设备上的本地路径，可以为空。
- resourceName : 待编译的 js script 的名字。

```c
typedef struct {
    /** Sourcemap url. */
    const char* sourceMapUrl;
    /** Resource name. */
    const char* resourceName;
    /** Resource line offset. */
    size_t resourceLineOffset;
    /** Resource column offset. */
    size_t resourceColumnOffset;
} JSVM_ScriptOrigin;
```

### JSVM
### 内存管理类型

JSVM-API 包含以下内存管理类型：

**JSVM_HandleScope**

JSVM_HandleScope 数据类型用于管理 JavaScript 对象的生命周期。它确保在指定范围内创建的 JavaScript 对象保持活动状态，直到该范围结束。这样可以防止使用已释放的对象，提高代码的可靠性和性能。

**JSVM_EscapableHandleScope**

- 由 OH_JSVM_OpenEscapableHandleScope 接口创建，由 OH_JSVM_CloseEscapableHandleScope 接口关闭。

- 表示一种特殊类型的句柄范围，用于将在JSVM_EscapableHandleScope范围内创建的值返回给父scope。

- 用于 OH_JSVM_EscapeHandle 接口，将 JSVM_EscapableHandleScope 范围内的值提升为 JavaScript 对象，以便在外部作用域使用。

**JSVM_Ref**

指向JSVM_Value，允许开发者管理JavaScript值的生命周期。

**JSVM_TypeTag**

该结构体定义了一个包含两个无符号64位整数的类型标签，用于标识一个JSVM-API值的类型信息。

```c++
typedef struct {
    uint64_t lower;
    uint64_t upper;
} JSVM_TypeTag;
```

- 存储了两个无符号64位整数的128位值，用它来标识JavaScript对象，确保它们属于某种类型。

- 比OH_JSVM_Instanceof更强的类型检查，如果对象的原型被操纵，OH_JSVM_Instanceof可能会报告误报。

- JSVM_TypeTag 在与 OH_JSVM_Wrap 结合使用时最有用，因为它确保从包装对象检索的指针可以安全地转换为与先前应用于JavaScript对象的类型标签相对应的Native类型。

### 回调类型

JSVM-API包含以下回调类型：

**JSVM_CallbackStruct**

用户提供的 Native callback 的回调函数指针和数据，JSVM_CallbackStruct 将通过 JSVM-API 暴露给 JavaScript。例如，可以使用 OH_JSVM_CreateFunction 接口创建绑定到 Native callback 的 JS 函数，其中 Native callback 就是通过 JSVM_CallbackStruct 结构定义。除非在对象生命周期管理中有特殊要求，一般不在此 callback 中创建 handle 或者 callback scope。

```c++
typedef struct {
  JSVM_Value(*callback)(JSVM_Env env, JSVM_CallbackInfo info);
  void* data;
} JSVM_CallbackStruct;
```

**JSVM_Callback**

JSVM_CallbackStruct 指针类型的别名。

定义如下:

```c++
typedef JSVM_CallbackStruct* JSVM_Callback;
```

**JSVM_CallbackInfo**

用户定义的 Native callback，第一个参数类型是 JSVM_Env，第二个参数类型是 JSVM_CallbackInfo。JSVM_CallbackInfo 表示从 JS 侧调用到 Native 侧时携带的调用信息，如参数列表。在实现 Native callback 时，一般使用 OH_JSVM_GetCbInfo 接口从 JSVM_CallbackInfo 中获取调用信息。

**JSVM_Finalize**

函数指针，用于传入OH_JSVM_SetInstanceData、OH_JSVM_CreateExternal、OH_JSVM_Wrap等接口。JSVM_Finalize在对象被回收后会被调用，可用于在JavaScript对象被垃圾回收时释放Native对象。JSVM 不保证是否执行该回调函数，也不保证执行该回调函数的时机，**开发者不应依赖于该回调的执行时机**。

写法如下：

```c++
typedef void (*JSVM_Finalize)(JSVM_Env env, void* finalizeData, void* finalizeHint);
```

**JSVM_PropertyHandlerConfigurationStruct**

当执行对象的getter、setter、deleter和enumerator操作时，对应的回调将会触发。

```c++
typedef struct {
    JSVM_Value(JSVM_CDECL* genericNamedPropertyGetterCallback)(JSVM_Env env,
                                                               JSVM_Value name,
                                                               JSVM_Value thisArg,
                                                               JSVM_Value namedPropertyData);
    JSVM_Value(JSVM_CDECL* genericNamedPropertySetterCallback)(JSVM_Env env,
                                                               JSVM_Value name,
                                                               JSVM_Value property,
                                                               JSVM_Value thisArg,
                                                               JSVM_Value namedPropertyData);
    JSVM_Value(JSVM_CDECL* genericNamedPropertyDeleterCallback)(JSVM_Env env,
                                                                JSVM_Value name,
                                                                JSVM_Value thisArg,
                                                                JSVM_Value namedPropertyData);
    JSVM_Value(JSVM_CDECL* genericNamedPropertyEnumeratorCallback)(JSVM_Env env,
                                                                   JSVM_Value thisArg,
                                                                   JSVM_Value namedPropertyData);
    JSVM_Value(JSVM_CDECL* genericIndexedPropertyGetterCallback)(JSVM_Env env,
                                                                JSVM_Value index,
                                                                JSVM_Value thisArg,
                                                                JSVM_Value indexedPropertyData);
    JSVM_Value(JSVM_CDECL* genericIndexedPropertySetterCallback)(JSVM_Env env,
                                                                 JSVM_Value index,
                                                                 JSVM_Value property,
                                                                 JSVM_Value thisArg,
                                                                 JSVM_Value indexedPropertyData);
    JSVM_Value(JSVM_CDECL* genericIndexedPropertyDeleterCallback)(JSVM_Env env,
                                                                  JSVM_Value index,
                                                                  JSVM_Value thisArg,
                                                                  JSVM_Value indexedPropertyData);
    JSVM_Value(JSVM_CDECL* genericIndexedPropertyEnumeratorCallback)(JSVM_Env env,
                                                                     JSVM_Value thisArg,
                                                                     JSVM_Value indexedPropertyData);
    JSVM_Value namedPropertyData;
    JSVM_Value indexedPropertyData;
} JSVM_PropertyHandlerConfigurationStruct;
```

**JSVM_PropertyHandlerCfg**

包含属性监听回调的结构指针。

基本用法如下:

```c++
typedef JSVM_PropertyHandlerConfigurationStruct* JSVM_PropertyHandlerCfg;
```

## 支持的JSVM-API接口

标准JS引擎的能力通过JSVM-API提供。JSVM-API支持动态链接到不同版本的JS引擎库，从而为开发者屏蔽掉不同引擎接口的差异。JSVM-API提供引擎生命周期管理、JS context管理、JS代码执行、JS/C++互操作、执行环境快照、codecache等能力，具体可见下文。

### 使用 JSVM-API 接口创建引擎实例及 JS 执行上下文环境

#### 场景介绍

执行JS代码需要先创建JavaScript VM，创建JS执行的上下文环境。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
| OH_JSVM_Init| 初始化JavaScript引擎实例 |
| OH_JSVM_CreateVM| 创建JavaScript引擎实例|
| OH_JSVM_DestroyVM| 销毁JavaScript引擎实例 |
| OH_JSVM_OpenVMScope| 打开一个新的VM scope，引擎实例只能在scope范围内使用，可以保证引擎实例不被销毁 |
| OH_JSVM_CloseVMScope| 关闭VM scope |
| OH_JSVM_CreateEnv| 创建一个新的JS执行上下文环境，并注册指定的Native函数 |
| OH_JSVM_DestroyEnv| 销毁一个JS执行上下文环境 |
| OH_JSVM_OpenEnvScope| 打开一个新的Env scope，Env只能在scope范围内使用 |
| OH_JSVM_CloseEnvScope| 关闭Env scope |
| OH_JSVM_OpenHandleScope| 打开一个Handle scope，确保scope范围内的JSVM_Value不被GC回收 |
| OH_JSVM_CloseHandleScope| 关闭Handle scope |

##### JSVM_InitOptions 的使用描述

JSVM 提供了多种配置选项，允许开发者在执行 `OH_JSVM_Init` 时灵活配置其行为。可以通过 `OH_JSVM_GetVMInfo` 接口获取当前 JSVM 版本所对应的 V8 引擎版本。JSVM 中可支持的选项范围与对应的 V8 引擎版本可支持的选项范围保持一致。`OH_JSVM_GetVMInfo` 接口的使用参考[使用JSVM-API接口获取JSVM API的版本号](use-jsvm-about-version.md)。

**注意：** 建议开发者在没有特殊需求的情况下，仅使用 JSVM 内部的默认配置选项。

场景示例：
常规模式下初始化 VM 平台。
```c++
static void NormalInit(bool &vmInit) {
    if (!vmInit) {
        // JSVM only need init once
        JSVM_InitOptions initOptions;
        memset(&initOptions, 0, sizeof(initOptions));
        OH_JSVM_Init(&initOptions);
        vmInit = true;
    }
}
```

场景示例：
初始化低内存占用的 VM 平台。
```c++
static void LowMemoryInit(bool &vmInit) {
    if (!vmInit) {
        // JSVM only need init once
        JSVM_InitOptions initOptions;
        initOptions.argc = 4;
        const char* argv[4];
        argv[1] = "--incremental-marking-hard-trigger=40";
        argv[2] = "--min-semi-space-size=4";
        argv[3] = "--max-semi-space-size=1";
        initOptions.argv = const_cast<char**>(argv);
        OH_JSVM_Init(&initOptions);
        vmInit = true;
    }
}
```

场景示例：
初始化低GC触发频次的 VM 平台。
```c++
static void LowGCFrequencyInit(bool &vmInit) {
    if (!vmInit) {
        // JSVM only need init once
        JSVM_InitOptions initOptions;
        initOptions.argc = 4;
        const char* argv[4];
        argv[1] = "--incremental-marking-hard-trigger=80";
        argv[2] = "--min-semi-space-size=16";
        argv[3] = "--max-semi-space-size=16";
        initOptions.argv = const_cast<char**>(argv);
        OH_JSVM_Init(&initOptions);
        vmInit = true;
    }
}
```

执行结果：
使用以上三个接口可以分别初始化具备不同特性的 VM 平台。初始化之后，可以创建 VM 实例，并执行 JavaScript 脚本。其中，
调用 LowGCFrequencyInit 接口进行 VM 平台初始化执行 JavaScript 脚本，相比调用 NormalInit 接口所触发的 GC 频次更低。调用 LowMemoryInit 接口进行 VM 平台初始化执行 JavaScript 脚本，相比调用 NormalInit 接口所占用内存更少。

##### 创建 VM 实例

场景示例:
创建及销毁 JavaScript 引擎实例，包含创建及销毁 JS 执行上下文环境
```c++
bool VM_INIT = false;

static JSVM_Value ConsoleInfo(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1];
    char log[256] = "";
    size_t logLength = 0;
    OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL);

    OH_JSVM_GetValueStringUtf8(env, args[0], log, 255, &logLength);
    log[255] = 0;
    OH_LOG_INFO(LOG_APP, "JSVM API TEST: %{public}s", log);
    return nullptr;
}

static JSVM_Value Add(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 2;
    JSVM_Value args[2];
    OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL);
    double num1 = 0;
	double num2 = 0;
    env, OH_JSVM_GetValueDouble(env, args[0], &num1);
    OH_JSVM_GetValueDouble(env, args[1], &num2);
    JSVM_Value sum = nullptr;
    OH_JSVM_CreateDouble(env, num1 + num2, &sum);
    return sum;
}

static napi_value MyJSVMDemo([[maybe_unused]] napi_env _env, [[maybe_unused]] napi_callback_info _info) {
    std::thread t([]() {
        // 可以根据不同的业务需求初始化具备不同能力的 VM 平台：
        // 1. 初始化默认的 VM 平台：调用'NormalInit'接口。
        // 2. 初始化低内存占用的 VM 平台：调用'LowMemoryInit'接口。
        // 3. 初始化低 GC 触发频次的 VM 平台：调用'LowGCFrequencyInit'接口。
        NormalInit(VM_INIT);
        // create vm, and open vm scope
        JSVM_VM vm;
        JSVM_CreateVMOptions options;
        memset(&options, 0, sizeof(options));
        OH_JSVM_CreateVM(&options, &vm);

        JSVM_VMScope vmScope;
        OH_JSVM_OpenVMScope(vm, &vmScope);

        JSVM_CallbackStruct param[] = {
            {.data = nullptr, .callback = ConsoleInfo},
            {.data = nullptr, .callback = Add},
        };
        JSVM_PropertyDescriptor descriptor[] = {
            {"consoleinfo", NULL, &param[0], NULL, NULL, NULL, JSVM_DEFAULT},
            {"add", NULL, &param[1], NULL, NULL, NULL, JSVM_DEFAULT},
        };
        // create env, register native method, and open env scope
        JSVM_Env env;
        OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);

        JSVM_EnvScope envScope;
        OH_JSVM_OpenEnvScope(env, &envScope);

        // open handle scope
        JSVM_HandleScope handleScope;
        OH_JSVM_OpenHandleScope(env, &handleScope);

        std::string sourceCodeStr = "\
        {\
            let value = add(4.96, 5.28);\
            consoleinfo('Result is:' + value);\
        }";
        // compile js script
        JSVM_Value sourceCodeValue;
        OH_JSVM_CreateStringUtf8(env, sourceCodeStr.c_str(), sourceCodeStr.size(), &sourceCodeValue);
        JSVM_Script script;
        OH_JSVM_CompileScript(env, sourceCodeValue, nullptr, 0, true, nullptr, &script);
        JSVM_Value result;
        // run js script
        OH_JSVM_RunScript(env, script, &result);
        JSVM_ValueType type;
        OH_JSVM_Typeof(env, result, &type);
        OH_LOG_INFO(LOG_APP, "JSVM API TEST type: %{public}d", type);

        // exit vm and clean memory
        OH_JSVM_CloseHandleScope(env, handleScope);

        OH_JSVM_CloseEnvScope(env, envScope);
        OH_JSVM_DestroyEnv(env);

        OH_JSVM_CloseVMScope(vm, vmScope);
        OH_JSVM_DestroyVM(vm);
    });

    t.detach();

    return nullptr;
}
```

### 使用 JSVM-API 接口编译及执行 JS 代码

#### 场景介绍

编译及执行JS代码。

#### 接口说明
| 接口                              | 功能说明                                                                               |
| ------------------------------- | ---------------------------------------------------------------------------------- |
| OH_JSVM_CompileScript           | 编译JavaScript代码并返回绑定到当前环境的编译脚本                                                      |
| OH_JSVM_CompileScriptWithOrigin | 编译JavaScript代码并返回绑定到当前环境的编译脚本，同时传入包括 sourceMapUrl 和源文件名在内的源代码信息，用于处理 source map 信息 |
| OH_JSVM_CompileScriptWithOptions | 通用的编译接口，通过传入 option 数组完成前面的 compile 接口全部功能，同时支持后续选项扩展 |
| OH_JSVM_CreateCodeCache         | 为编译脚本创建code cache                                                                  |
| OH_JSVM_RunScript               | 执行编译脚本                                                                             |

场景示例：
编译及执行 JS 代码（创建 VM 实例，注册函数，执行 JS，销毁 VM 实例）

cpp 部分代码

```c++
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

// 依赖libjsvm.so
#include "ark_runtime/jsvm.h"

using namespace std;

static JSVM_Value Hello(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Value output;
    void* data = nullptr;
    OH_JSVM_GetCbInfo(env, info, nullptr, nullptr, nullptr, &data);
    OH_JSVM_CreateStringUtf8(env, (char*)data, strlen((char*)data), &output);
    return output;
}

static JSVM_CallbackStruct hello_cb = { Hello, (void*)"Hello" };

static string srcGlobal = R"JS(
const concat = (...args) => args.reduce((a, b) => a + b);
)JS";

static void RunScriptWithOption(JSVM_Env env, string& src,
								uint8_t** dataPtr = nullptr,
								size_t* lengthPtr = nullptr) {
    JSVM_HandleScope handleScope;
    OH_JSVM_OpenHandleScope(env, &handleScope);

    JSVM_Value jsSrc;
    OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsSrc);

    uint8_t* data = dataPtr ? *dataPtr : nullptr;
    auto compilMode = data ? JSVM_COMPILE_MODE_CONSUME_CODE_CACHE :  JSVM_COMPILE_MODE_DEFAULT;
    size_t length = lengthPtr ? *lengthPtr : 0;
    JSVM_Script script;
    // 编译js代码
	JSVM_ScriptOrigin origin {
	    // 以包名 helloworld 为例, 假如存在对应的 sourcemap, source map 的的路径可以是 /data/app/el2/100/base/com.example.helloworld/files/index.js.map
	    .sourceMapUrl = "/data/app/el2/100/base/com.example.helloworld/files/index.js.map",
	    // 源文件名字
	    .resourceName = "index.js",
	    // scirpt 在源文件中的起始行列号
	    .resourceLineOffset = 0,
	    .resourceColumnOffset = 0,
	};
	JSVM_CompileOptions option[3];
	option[0] = {
		.id = JSVM_COMPILE_MODE,
		.content = { .num = compilMode }
	};
	JSVM_CodeCache codeCache = {
		.cache = data,
		.length = length
	};
	option[1] = {
		.id = JSVM_COMPILE_CODE_CACHE,
		.content = { .ptr = &codeCache }
	};
	// JSVM_COMPILE_ENABLE_SOURCE_MAP 选项默认值为 false，若为 true 那么对应的 sourceMapUrl 必须不为空
	option[2] = {
		.id = JSVM_COMPILE_ENABLE_SOURCE_MAP,
		.content = { .boolean = true }
	};
	OH_JSVM_CompileScriptWithOptions(env, jsSrc, 3, option, &script);

    JSVM_Value result;
    // 执行js代码
    OH_JSVM_RunScript(env, script, &result);

    char resultStr[128];
    size_t size = 0;
    OH_JSVM_GetValueStringUtf8(env, result, resultStr, 128, &size);

    OH_JSVM_CloseHandleScope(env, handleScope);
}

static void RunScript(JSVM_Env env, string& src,
                       bool withOrigin = false,
                       uint8_t** dataPtr = nullptr,
                       size_t* lengthPtr = nullptr) {
    JSVM_HandleScope handleScope;
    OH_JSVM_OpenHandleScope(env, &handleScope);

    JSVM_Value jsSrc;
    OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsSrc);

    uint8_t* data = dataPtr ? *dataPtr : nullptr;
    size_t length = lengthPtr ? *lengthPtr : 0;
    bool cacheRejected = true;
    JSVM_Script script;
    // 编译js代码
    if (withOrigin) {
	    JSVM_ScriptOrigin origin {
	        // 以包名 helloworld 为例, 假如存在对应的 sourcemap, source map 的的路径可以是 /data/app/el2/100/base/com.example.helloworld/files/index.js.map
		    .sourceMapUrl = "/data/app/el2/100/base/com.example.helloworld/files/index.js.map",
		    // 源文件名字
		    .resourceName = "index.js",
		    // scirpt 在源文件中的起始行列号
		    .resourceLineOffset = 0,
		    .resourceColumnOffset = 0,
	    };
		OH_JSVM_CompileScriptWithOrigin(env, jsSrc, data, length, true, &cacheRejected, &origin, &script);
    } else {
	    OH_JSVM_CompileScript(env, jsSrc, data, length, true, &cacheRejected, &script);
    }
    printf("Code cache is %s\n", cacheRejected ? "rejected" : "used");

    JSVM_Value result;
    // 执行js代码
    OH_JSVM_RunScript(env, script, &result);

    char resultStr[128];
    size_t size = 0;
    OH_JSVM_GetValueStringUtf8(env, result, resultStr, 128, &size);

    OH_JSVM_CloseHandleScope(env, handleScope);
}

void RunWithOption(uint8_t** dataPtr, size_t* lengthPtr) {
    // 创建虚拟机实例
    JSVM_VM vm;
    OH_JSVM_CreateVM(nullptr, &vm);
    JSVM_VMScope vmScope;
    OH_JSVM_OpenVMScope(vm, &vmScope);

    JSVM_Env env;
    // 将native函数注册成js可调用的方法，hello_cb中记录该native方法的指针和参数等信息
    JSVM_PropertyDescriptor descriptors[] = {
        { "hello", NULL, &hello_cb, NULL, NULL, NULL, JSVM_DEFAULT }
    };
    OH_JSVM_CreateEnv(vm, 1, descriptors, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    // 执行js源码src，src中可以包含任何js语法。也可以调用已注册的native方法。
    auto src = srcGlobal + "concat(hello(), ', ', 'World', ' from RunWithOption!')";
    // 其中使用新增接口，可以覆盖原有 Compile 系列接口的功能且具有拓展性
    RunScriptWithOption(env, src, dataPtr, lengthPtr);

    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vmScope);
    OH_JSVM_DestroyVM(vm);

    bool result = true;
    OH_LOG_INFO(LOG_APP, "RunWithOption: success: %{public}d", result);
}

void RunWithOrigin(uint8_t **dataPtr, size_t *lengthPtr) {
    // 创建虚拟机实例
    JSVM_VM vm;
    JSVM_CreateVMOptions options;
    memset(&options, 0, sizeof(options));
    options.isForSnapshotting = true;
    OH_JSVM_CreateVM(&options, &vm);
    JSVM_VMScope vmScope;
    OH_JSVM_OpenVMScope(vm, &vmScope);

    // 从快照中创建env
    JSVM_Env env;
    // 将native函数注册成js可调用的方法，hello_cb中记录该native方法的指针和参数等信息
    JSVM_PropertyDescriptor descriptors[] = {
        { "hello", NULL, &hello_cb, NULL, NULL, NULL, JSVM_DEFAULT }
    };
    OH_JSVM_CreateEnv(vm, 1, descriptors, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    // 执行js脚本，因为快照记录的env中定义了hello()，所以无需重新定义。dataPtr中如果保存了编译后的js脚本，就能直接执行js脚本，避免从源码重复编译。
    string src = "concat(hello(), ', ', 'World', ' from RunWithOrigin!')";
    RunScript(env, src, true, dataPtr, lengthPtr);

    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vmScope);
    OH_JSVM_DestroyVM(vm);

    bool result = true;
    OH_LOG_INFO(LOG_APP, "RunWithOrigin: success: %{public}d", result);
}

static JSVM_Value RunDemo(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1] = {nullptr};
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);

    char* str = "WithOrigin";
    size_t len = strlen(str);
    JSVM_Value result = nullptr;
    OH_JSVM_CreateStringUtf8(env, str, len, &result);

    uint8_t* data = nullptr;
    size_t length = 0;
    bool equal = false;
    OH_JSVM_StrictEquals(env, args[0], result, &equal);
    const auto run = equal ? RunWithOrigin : RunWithOption;
    run(&data, &length);
    delete[] data;

    return nullptr;
}

// RunDemo注册回调
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = RunDemo},
};
static JSVM_CallbackStruct *method = param;
// RunDemo方法别名，供JS调用
static JSVM_PropertyDescriptor descriptor[] = {
    {"RunDemo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// 样例测试js
const char *srcCallNative = R"JS(RunDemo("WithOrigin"); RunDemo("WithOption"))JS";
```

预期输出结果
```ts
RunWithOption: success: 1
RunWithOrigin: success: 1
```

OH_JSVM_CreateCodeCache 接口用法可参考[使用 code cache 加速编译](use-jsvm-about-code-cache.md)。

### 使用 JSVM-API WebAssembly 接口编译 wasm module

#### 场景介绍

JSVM-API WebAssembly 接口提供了 WebAssembly 字节码编译、WebAssembly 函数优化、WebAssembly cache 序列化和反序列化的能力。
详见[使用 JSVM-API WebAssembly 接口](use-jsvm-about-wasm.md)。

#### 接口说明

| 接口                          | 功能说明                                                                                 |
| --------------------------- | ------------------------------------------------------------------------------------ |
| OH_JSVM_CompileWasmModule   | 将 wasm 字节码同步编译为 wasm module。如果提供了 cache 参数，先尝试将 cache 反序列为 wasm module，反序列化失败时再执行编译。 |
| OH_JSVM_CompileWasmFunction | 将 wasm module 中指定编号的函数编译为优化后的机器码，目前只使能了最高的优化等级，函数编号的合法性由接口调用者保证。                     |
| OH_JSVM_IsWasmModuleObject  | 判断传入的值是否是一个 wasm module。                                                             |
| OH_JSVM_CreateWasmCache     | 将 wasm module 中的机器码序列化为 wasm cache，如果 wasm module 不包含机器码，则会序列化失败。                    |
| OH_JSVM_ReleaseCache        | 释放由 JSVM 接口生成的 cache。传入的 cacheType 和 cacheData 必须匹配，否则会产生未定义行为。                      |

#### 场景示例

详见[使用 JSVM-API WebAssembly 接口](use-jsvm-about-wasm.md)。

### 异常处理

#### 场景介绍

获取、抛出、清理JS异常。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
| OH_JSVM_Throw| 抛出一个JS值 |
| OH_JSVM_ThrowTypeError| 抛出一个JS TypeError |
| OH_JSVM_ThrowRangeError| 抛出一个JS RangeError |
| OH_JSVM_IsError| 判断JS值是否为JS异常 |
| OH_JSVM_CreateError| 创建一个JS异常 |
| OH_JSVM_CreateTypeError| 创建一个JS TypeError并返回 |
| OH_JSVM_CreateRangeError| 创建一个JS RangeError并返回 |
| OH_JSVM_ThrowError| 抛出一个JS异常 |
| OH_JSVM_GetAndClearLastException| 清理并返回最后一个JS异常 |
| OH_JSVM_IsExceptionPending| 判断当前是否有异常 |
| OH_JSVM_GetLastErrorInfo| 获取最后一个异常的信息 |
| OH_JSVM_ThrowSyntaxError| 抛出一个JS SyntaxError |
| OH_JSVM_CreateSyntaxError| 创建一个JS SyntaxError并返回 |

场景示例：
以TypeError为例。创建、判断，并抛出JS TypeError。

```c++
JSVM_Value code = nullptr;
JSVM_Value message = nullptr;
OH_JSVM_CreateStringUtf8(env, "500", JSVM_AUTO_LENGTH, &code);
OH_JSVM_CreateStringUtf8(env, "type error 500", JSVM_AUTO_LENGTH, &message);
JSVM_Value error = nullptr;
OH_JSVM_CreateTypeError(env, code, message, &error);
bool isError = false;
OH_JSVM_IsError(env, error, &isError);
OH_JSVM_ThrowTypeError(env, nullptr, "type error1");
```

使用OH_JSVM_GetAndClearLastException后将异常信息以字符串形式打印

```c++
if (status != JSVM_OK) // 当执行失败出现异常时
{
    bool isPending = false;
    if (JSVM_OK == OH_JSVM_IsExceptionPending((env), &isPending) && isPending)
    {
        JSVM_Value error;
        if (JSVM_OK == OH_JSVM_GetAndClearLastException((env), &error))
        {
            // 获取异常堆栈
            JSVM_Value stack;
            OH_JSVM_GetNamedProperty((env), error, "stack", &stack);

            JSVM_Value message;
            OH_JSVM_GetNamedProperty((env), error, "message", &message);

            char stackstr[256];
            OH_JSVM_GetValueStringUtf8(env, stack, stackstr, 256, nullptr);
            OH_LOG_INFO(LOG_APP, "JSVM error stack: %{public}s", stackstr);

            char messagestr[256];
            OH_JSVM_GetValueStringUtf8(env, message, messagestr, 256, nullptr);
            OH_LOG_INFO(LOG_APP, "JSVM error message: %{public}s", messagestr);
        }
    }
}
```

### 对象生命周期管理

在调用JSVM-API接口时，底层VM堆中的对象可能会作为JSVM_Values返回句柄。这些句柄必须在Native方法销毁或主动释放掉前，使其关联的对象处于“活动”状态，防止被引擎回收掉。

当对象句柄被返回时，它们与一个“scope”相关联。默认作用域的生命周期与Native方法调用的生命周期相关联，这些句柄及关联的对象将在Native方法的生命周期内保持活动状态。

然而，在许多情况下，句柄必须保持有效的时间范围并不与Native方法的生命周期相同。下面将介绍可用于更改句柄的生命周期的JSVM-API方法。

#### 对象生命周期管理接口说明
| 接口 | 功能说明 |
| -------- | -------- |
| OH_JSVM_OpenHandleScope| 打开一个新的scope，在关闭该scope之前创建的对象在scope范围内不会被GC回收 |
| OH_JSVM_CloseHandleScope| 关闭一个scope，在此scope范围内创建的对象在关闭scope后可以被GC回收|
| OH_JSVM_OpenEscapableHandleScope| 打开一个新的scope逃逸handle scope，在关闭该scope之前创建的对象与父作用域有相同的生命周期 |
| OH_JSVM_CloseEscapableHandleScope| 关闭一个scope，在此scope范围外创建的对象不受父作用域保护 |
| OH_JSVM_EscapeHandle| 将 JavaScript 对象的句柄提升到外部作用域，确保在外部作用域中可以持续地使用该对象 |
| OH_JSVM_CreateReference| 以指定的引用计数为JavaScript对象创建一个新的引用，该引用将指向传入的对象，引用允许在不同的上下文中使用和共享对象，并且可以有效地监测对象的生命周期 |
| OH_JSVM_DeleteReference| 释放由 OH_JSVM_CreateReference 创建的引用，确保对象在不再被使用时能够被正确地释放和回收，避免内存泄漏 |
| OH_JSVM_ReferenceRef| 增加由OH_JSVM_CreateReference 创建的引用的引用计数，以确保对象在有引用时不会被提前释放 |
| OH_JSVM_ReferenceUnref| 减少由OH_JSVM_CreateReference 创建的引用的引用计数，以确保没有任何引用指向该对象时能正确地释放和回收 |
| OH_JSVM_GetReferenceValue| 返回由 OH_JSVM_CreateReference 创建的引用的对象 |
| OH_JSVM_RetainScript | 持久化保存一个 JSVM_Script, 使其能够跨过当前 scope 使用 |
| OH_JSVM_ReleaseScript | 释放持久化保存过的 JSVM_Script，释放之后 JSVM_Script 不再可用，应当置为空 |

场景示例：
通过handle scope保护在scope范围内创建的对象在该范围内不被回收。

```c++
JSVM_HandleScope scope;
OH_JSVM_OpenHandleScope(env, &scope);
JSVM_Value obj = nullptr;
OH_JSVM_CreateObject(env, &obj);
OH_JSVM_CloseHandleScope(env, scope);
```

通过escapable handle scope保护在scope范围内创建的对象在父作用域范围内不被回收

```c++
JSVM_EscapableHandleScope scope;
JSVM_CALL(env, OH_JSVM_OpenEscapableHandleScope(env, &scope));
JSVM_Value output = NULL;
JSVM_Value escapee = NULL;
JSVM_CALL(env, OH_JSVM_CreateObject(env, &output));
JSVM_CALL(env, OH_JSVM_EscapeHandle(env, scope, output, &escapee));
JSVM_CALL(env, OH_JSVM_CloseEscapableHandleScope(env, scope));
return escapee;
```

通过CreateReference创建对象引用和释放

```c++
JSVM_Value obj = nullptr;
OH_JSVM_CreateObject(env, &obj);
// 创建引用
JSVM_Ref reference;
OH_JSVM_CreateReference(env, obj, 1, &reference);

// 使用引用
JSVM_Value result;
OH_JSVM_GetReferenceValue(env, reference, &result);

// 释放引用
OH_JSVM_DeleteReference(env, reference);
```

通过 RetainScript 持久化保存 JSVM_Script 并使用

```c++
JSVM_HandleScope scope;
OH_JSVM_OpenHandleScope(env, &scope);
JSVM_Script script;
JSVM_Value jsSrc;
std::string src(R"JS(
let a = 37;
a = a * 9;
)JS");
OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsSrc);
OH_JSVM_CompileScriptWithOptions(env, jsSrc, 0, nullptr, &script);
OH_JSVM_RetainScript(env, script);
OH_JSVM_CloseHandleScope(env, scope);

// 使用JSVM_Script
OH_JSVM_OpenHandleScope(env, &scope);
JSVM_Value result;
OH_JSVM_RunScript(env, script, &result);

// 释放JSVM_Script，并置空
OH_JSVM_ReleaseScript(env, script);
script = nullptr;
OH_JSVM_CloseHandleScope(env, scope);
```

### 创建JS对象类型和基本类型

#### 场景介绍

创建JS对象类型和基本类型。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_CreateArray | 创建一个新的 JavaScript 数组对象 |
|OH_JSVM_CreateArrayWithLength | 创建一个指定长度的 JavaScript 数组对象 |
|OH_JSVM_CreateArraybuffer | 创建一个指定大小的 ArrayBuffer 对象 |
|OH_JSVM_CreateDate | 创建了一个表示给定毫秒数的 Date 对象 |
|OH_JSVM_CreateExternal | 创建一个包装了外部指针的 JavaScript 对象 |
|OH_JSVM_CreateObject | 创建一个默认的JavaScript Object对象 |
|OH_JSVM_CreateSymbol | 根据给定的描述符创建一个 Symbol 对象 |
|OH_JSVM_SymbolFor | 在全局注册表中搜索具有给定描述的现有Symbol，如果该Symbol已经存在，它将被返回，否则将在注册表中创建一个新Symbol |
|OH_JSVM_CreateTypedarray | 在现有的 ArrayBuffer 上创建一个 JavaScript TypedArray 对象，TypedArray 对象在底层数据缓冲区上提供类似数组的视图，其中每个元素都具有相同的底层二进制标量数据类型 |
|OH_JSVM_CreateDataview | 在现有的 ArrayBuffer 上创建一个 JavaScript DataView 对象，DataView 对象在底层数据缓冲区上提供类似数组的视图 |
|OH_JSVM_CreateInt32 | 根据 Int32_t 类型对象创建 JavaScript number 对象 |
|OH_JSVM_CreateUint32 | 根据 Uint32_t 类型对象创建 JavaScript number 对象 |
|OH_JSVM_CreateInt64 | 根据 Int64_t 类型对象创建 JavaScript number 对象 |
|OH_JSVM_CreateDouble | 根据 Double 类型对象创建 JavaScript number 对象 |
|OH_JSVM_CreateBigintInt64 | 根据 Int64 类型对象创建 JavaScript Bigint 对象 |
|OH_JSVM_CreateBigintUint64 | 根据 Uint64 类型对象创建 JavaScript Bigint 对象 |
|OH_JSVM_CreateBigintWords | 根据给定的 Uint64_t 数组创建一个 JavaScript BigInt 对象 |
|OH_JSVM_CreateStringLatin1 | 根据 Latin-1 编码的字符串创建一个 JavaScript string 对象 |
|OH_JSVM_CreateStringUtf16 | 根据 Utf16 编码的字符串创建一个 JavaScript string 对象 |
|OH_JSVM_CreateStringUtf8 | 根据 Utf8 编码的字符串创建一个 JavaScript string 对象 |
|OH_JSVM_CreateMap | 创建一个新的 JavaScript Map对象 |
|OH_JSVM_CreateRegExp | 根据输入的字符串创建一个JavaScript 正则对象 |
|OH_JSVM_CreateSet | 创建一个新的 JavaScript Set对象 |

场景示例:
创建指定长度的JavaScript数组。

```c++
size_t arrayLength = 2;
JSVM_Value arr;

OH_JSVM_CreateArrayWithLength(env, arrayLength, &arr);
for (uint32_t i = 0; i < arrayLength; i++)
{
    JSVM_Value element;
    OH_JSVM_CreateUint32(env, i * 2, &element);
    OH_JSVM_SetElement(env, arr, i, element);
}
```

创建TypedArray，以Int32Array为例：

```c++
JSVM_Value arrayBuffer = nullptr;
void *arrayBufferPtr = nullptr;
size_t arrayBufferSize = 16;
size_t typedArrayLength = 4;
OH_JSVM_CreateArraybuffer(env, arrayBufferSize, &arrayBufferPtr, &arrayBuffer);

void *tmpArrayBufferPtr = nullptr;
size_t arrayBufferLength = 0;
OH_JSVM_GetArraybufferInfo(env, arrayBuffer, &tmpArrayBufferPtr, &arrayBufferLength);

JSVM_Value result;
OH_JSVM_CreateTypedarray(env, JSVM_TypedarrayType::JSVM_INT32_ARRAY, typedArrayLength, arrayBuffer, 0, &result);
return result;
```

创建number和string：

```c++
const char *testStringStr = "test";
JSVM_Value testString = nullptr;
OH_JSVM_CreateStringUtf8(env, testStringStr, strlen(testStringStr), &testString);

JSVM_Value testNumber1 = nullptr;
JSVM_Value testNumber2 = nullptr;
OH_JSVM_CreateDouble(env, 10.1, &testNumber1);
OH_JSVM_CreateInt32(env, 10, &testNumber2);
```

创建Map：

```c++
JSVM_Value value = nullptr;
OH_JSVM_CreateMap(env, &value);
```

创建RegExp：

```c++
JSVM_Value value = nullptr;
const char testStr[] = "ab+c";
OH_JSVM_CreateStringUtf8(env, testStr, strlen(testStr), &value);
JSVM_Value result = nullptr;
OH_JSVM_CreateRegExp(env, value, JSVM_RegExpFlags::JSVM_REGEXP_GLOBAL, &result);
```

创建Set：

```c++
JSVM_Value value;
OH_JSVM_CreateSet(env, &value);
```

### 从JS类型获取C类型&JS类型信息

#### 场景介绍

从JS类型获取C类型&JS类型信息。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_GetArrayLength | 返回 Array 对象的长度 |
|OH_JSVM_GetArraybufferInfo | 检索 ArrayBuffer 的底层数据缓冲区及其长度 |
|OH_JSVM_GetPrototype | 获取给定 JavaScript 对象的原型 |
|OH_JSVM_GetTypedarrayInfo | 获取 TypedArray（类型化数组）对象的信息 |
|OH_JSVM_GetDataviewInfo | 获取 Dataview 对象的信息 |
|OH_JSVM_GetDateValue | 获取给定 JavaScript Date 的时间值的 Double 基础类型值 |
|OH_JSVM_GetValueBool | 获取给定 JavaScript Boolean 的 C 布尔基础类型值 |
|OH_JSVM_GetValueDouble | 获取给定 JavaScript number 的 Double 基础类型值 |
|OH_JSVM_GetValueBigintInt64 | 获取给定 JavaScript BigInt 的 Int64_t 基础类型值 |
|OH_JSVM_GetValueBigintUint64 | 获取给定 JavaScript BigInt 的 Uint64_t 基础类型值 |
|OH_JSVM_GetValueBigintWords | 获取给定 JavaScript BigInt 对象的底层数据，即 BigInt 数据的字词表示 |
|OH_JSVM_GetValueExternal | 获取先前传递给 OH_JSVM_CreateExternal 的外部数据指针 |
|OH_JSVM_GetValueInt32 | 获取给定 JavaScript number 的 Int32 基础类型值 |
|OH_JSVM_GetValueInt64 | 获取给定 JavaScript number 的 Int64 基础类型值 |
|OH_JSVM_GetValueStringLatin1 | 获取给定 JavaScript string 对象的 Latin1 编码字符串 |
|OH_JSVM_GetValueStringUtf8 | 获取给定 JavaScript string 对象的 Utf8 编码字符串 |
|OH_JSVM_GetValueStringUtf16 | 获取给定 JavaScript string 对象的 Utf16 编码字符串 |
|OH_JSVM_GetValueUint32 | 获取给定 JavaScript number 的 Uint32 基础类型值 |
|OH_JSVM_GetBoolean | 返回用于表示给定布尔值的 JavaScript 单例对象 |
|OH_JSVM_GetGlobal | 返回当前环境中的全局 global 对象 |
|OH_JSVM_GetNull | 返回 JavaScript null 对象 |
|OH_JSVM_GetUndefined | 返回 JavaScript Undefined 对象 |

场景示例：
创建64位的 BigInt，并获取64位 Int 值。

```c++
int64_t testValue = INT64_MAX;
JSVM_Value result = nullptr;
OH_JSVM_CreateBigintInt64(env, testValue, &result);
int64_t resultValue = 0;
bool flag = false;
OH_JSVM_GetValueBigintInt64(env, result, &resultValue, &flag);
```

创建一个 Int32Array，并获取其长度、byteOffset 等信息。

```c++
JSVM_Value arrayBuffer = nullptr;
void *arrayBufferPtr = nullptr;
size_t arrayBufferSize = 16;
size_t typedArrayLength = 4;
OH_JSVM_CreateArraybuffer(env, arrayBufferSize, &arrayBufferPtr, &arrayBuffer);

bool isArrayBuffer = false;
OH_JSVM_IsArraybuffer(env, arrayBuffer, &isArrayBuffer);

JSVM_Value result;
OH_JSVM_CreateTypedarray(env, JSVM_TypedarrayType::JSVM_INT32_ARRAY, typedArrayLength, arrayBuffer, 0, &result);

bool isTypedArray = false;
OH_JSVM_IsTypedarray(env, result, &isTypedArray);


JSVM_TypedarrayType type;
size_t length = 0;
void *data = nullptr;
JSVM_Value retArrayBuffer;
size_t byteOffset = -1;
OH_JSVM_GetTypedarrayInfo(env, result, &type, &length, &data, &retArrayBuffer, &byteOffset);


bool retIsArrayBuffer = false;
OH_JSVM_IsArraybuffer(env, retArrayBuffer, &retIsArrayBuffer);
void *tmpArrayBufferPtr = nullptr;
size_t arrayBufferLength = 0;
OH_JSVM_GetArraybufferInfo(env, retArrayBuffer, &tmpArrayBufferPtr, &arrayBufferLength);
```

根据 UTF-8 编码的 C 字符串创建一个 JavaScript 字符串，以及获取给定 JavaScript 字符串的 UTF-8 编码 C 字符串。

```c++
const char *testStringStr = "testString";
JSVM_Value testString = nullptr;
OH_JSVM_CreateStringUtf8(env, testStringStr, strlen(testStringStr), &testString);

char buffer[128];
size_t bufferSize = 128;
size_t copied = 0; 

OH_JSVM_GetValueStringUtf8(env, testString, buffer, bufferSize, &copied);
```

### JS值操作和抽象操作

#### 场景介绍

JS值操作和抽象操作。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_CoerceToBool | 将目标值转换为 Boolean 类型对象|
|OH_JSVM_CoerceToNumber | 将目标值转换为 Number 类型对象 |
|OH_JSVM_CoerceToObject | 将目标值转换为 Object 类型对象 |
|OH_JSVM_CoerceToString | 将目标值转换为 String 类型对象 |
|OH_JSVM_CoerceToBigInt | 将目标值转换为 BigInt 类型对象 |
|OH_JSVM_Typeof | 返回 JavaScript 对象的类型 |
|OH_JSVM_Instanceof | 判断一个对象是否是某个构造函数的实例 |
|OH_JSVM_IsArray | 判断一个 JavaScript 对象是否为 Array 类型对象|
|OH_JSVM_IsArraybuffer | 判断一个 JavaScript 对象是否为 ArrayBuffer 类型对象 |
|OH_JSVM_IsDate | 判断一个 JavaScript 对象是否为 Date 类型对象 |
|OH_JSVM_IsTypedarray | 判断一个 JavaScript 对象是否为 TypedArray 类型对象 |
|OH_JSVM_IsDataview | 判断一个 JavaScript 对象是否为 DataView 类型对象 |
|OH_JSVM_IsUndefined | 此API检查传入的值是否为Undefined。这相当于JS中的`value === undefined`。 |
|OH_JSVM_IsNull | 此API检查传入的值是否为Null对象。这相当于JS中的`value === null`。 |
|OH_JSVM_IsNullOrUndefined | 此API检查传入的值是否为Null或Undefined。这相当于JS中的`value == null`。 |
|OH_JSVM_IsBoolean | 此API检查传入的值是否为Boolean。这相当于JS中的`typeof value === 'boolean'`。 |
|OH_JSVM_IsNumber | 此API检查传入的值是否为Number。这相当于JS中的`typeof value === 'number'`。 |
|OH_JSVM_IsString | 此API检查传入的值是否为String。这相当于JS中的`typeof value === 'string'`。 |
|OH_JSVM_IsSymbol | 此API检查传入的值是否为Symbol。这相当于JS中的`typeof value === 'symbol'`。 |
|OH_JSVM_IsFunction | 此API检查传入的值是否为Function。这相当于JS中的`typeof value === 'function'`。 |
|OH_JSVM_IsObject | 此API检查传入的值是否为Object。 |
|OH_JSVM_IsBigInt | 此API检查传入的值是否为BigInt。这相当于JS中的`typeof value === 'bigint'`。 |
|OH_JSVM_IsConstructor | 此API检查传入的值是否为构造函数。 |
|OH_JSVM_IsMap | 此API检查传入的值是否为Map。 |
|OH_JSVM_IsSet | 此API检查传入的值是否为Set。 |
|OH_JSVM_IsRegExp | 此API检查传入的值是否为RegExp。 |
|OH_JSVM_StrictEquals | 判断两个 JSVM_Value 对象是否严格相等 |
|OH_JSVM_Equals | 判断两个 JSVM_Value 对象是否宽松相等 |
|OH_JSVM_DetachArraybuffer | 调用 ArrayBuffer 对象的Detach操作 |
|OH_JSVM_IsDetachedArraybuffer | 检查给定的 ArrayBuffer 是否已被分离(detached) |

场景示例:
判断JS值是否为Array类型

```c++
JSVM_Value array = nullptr;
OH_JSVM_CreateArray(env, &array);
bool isArray = false;
OH_JSVM_IsArray(env, array, &isArray);
```

将int32类型的目标值转换为string类型

```c++
int32_t num = 123;
JSVM_Value intValue;
OH_JSVM_CreateInt32(env, num, &intValue);
JSVM_Value stringValue;
OH_JSVM_CoerceToString(env, intValue, &stringValue);

char buffer[128];
size_t bufferSize = 128;
size_t copied = 0;

OH_JSVM_GetValueStringUtf8(env, stringValue, buffer, bufferSize, &copied);
// buffer:"123";
```

将boolean类型的目标值转换为bigint类型

```c++
JSVM_Value boolValue;
OH_JSVM_GetBoolean(env, false, &boolValue);
JSVM_Value bigIntValue;
OH_JSVM_CoerceToBigInt(env, boolValue, &bigIntValue);
```

判断两个JSVM_Value对象类型是否严格相同：先比较操作数类型，操作数类型不同就是不相等，操作数类型相同时，比较值是否相等，相等才返回true。

```c++
JSVM_Value value = nullptr;
JSVM_Value value1 = nullptr;
OH_JSVM_CreateArray(env, &value);

OH_JSVM_CreateInt32(env, 10, &value1);
bool isArray = true;
OH_JSVM_StrictEquals(env, value, value, &isArray);
```

判断两个JSVM_Value对象类型是否宽松相同：判断两个操作数的类型是否相同，若不相同，且可以转换为相同的数据类型，转换为相同的数据类型后，值做严格相等比较，其他的都返回false。

```c++
JSVM_HandleScope handleScope;
OH_JSVM_OpenHandleScope(env, &handleScope);
const char testStr[] = "1";
JSVM_Value lhs = nullptr;
OH_JSVM_CreateStringUtf8(env, testStr, strlen(testStr), &lhs);
JSVM_Value rhs;
OH_JSVM_CreateInt32(env, 1, &rhs);
bool isEquals = false;
OH_JSVM_Equals(env, lhs, rhs, &isEquals); // 这里isEquals的值是true
OH_JSVM_CloseHandleScope(env, handleScope);
```

判断传入的JS值是否为构造函数

```c++
JSVM_Value SayHello(JSVM_Env env, JSVM_CallbackInfo info)
{
    return nullptr;
}
JSVM_Value value = nullptr;
JSVM_CallbackStruct param;
param.data = nullptr;
param.callback = SayHello;
OH_JSVM_CreateFunction(env, "func", JSVM_AUTO_LENGTH, &param, &value);
bool isConstructor = false;
OH_JSVM_IsConstructor(env, value, &isConstructor); // 这里isConstructor的值是true
```

判断传入的JS值是否为Map类型

```c++
JSVM_Value value = nullptr;
OH_JSVM_CreateMap(env, &value);
bool isMap = false;
OH_JSVM_IsMap(env, value, &isMap); // 这里isMap的值是true
```

判断传入的JS值是否为Set类型

```c++
JSVM_Value value;
OH_JSVM_CreateSet(env, &value);
bool isSet = false;
OH_JSVM_IsSet(env, value, &isSet); // 这里isSet的值是true
```

判断JS值是否为RegExp类型

```c++
JSVM_Value value = nullptr;
const char testStr[] = "ab+c";
OH_JSVM_CreateStringUtf8(env, testStr, strlen(testStr), &value);
JSVM_Value result = nullptr;
OH_JSVM_CreateRegExp(env, value, JSVM_RegExpFlags::JSVM_REGEXP_GLOBAL, &result);
bool isRegExp = false;
OH_JSVM_IsRegExp(env, result, &isRegExp);
```

### JS属性操作

#### 场景介绍

JS对象属性的增加、删除、获取和判断。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_GetPropertyNames | 获取给定对象的所有可枚举属性名称, 结果变量将存储一个包含所有可枚举属性名称的JavaScript数组。 |
|OH_JSVM_GetAllPropertyNames | 获取给定对象的所有可用属性名称, 结果变量将存储一个包含所有可枚举属性名称的JavaScript数组。 |
|OH_JSVM_SetProperty | 为给定对象设置一个属性。 |
|OH_JSVM_GetProperty | 用给定的属性的名称，检索目标对象的属性。 |
|OH_JSVM_HasProperty | 用给定的属性的名称，查询目标对象是否有此属性。 |
|OH_JSVM_DeleteProperty | 用给定的属性的名称，删除目标对象属性。 |
|OH_JSVM_HasOwnProperty | 检查目标对象是否具有指定的自有属性。 |
|OH_JSVM_SetNamedProperty | 用给定的属性的名称为目标对象设置属性，此方法等效于使用从作为 utf8Name 传入的字符串创建的 JSVM_Value 调用 OH_JSVM_SetProperty。 |
|OH_JSVM_GetNamedProperty | 用给定的属性的名称，检索目标对象的属性，此方法等效于使用从作为 utf8Name 传入的字符串创建的 JSVM_Value 调用 OH_JSVM_GetProperty。 |
|OH_JSVM_HasNamedProperty | 用给定的属性的名称，查询目标对象是否有此属性，此方法等效于使用从作为 utf8Name 传入的字符串创建的 JSVM_Value 调用 OH_JSVM_HasProperty。 |
|OH_JSVM_SetElement | 在给定对象的指定索引处设置元素。 |
|OH_JSVM_GetElement | 获取给定对象指定索引处的元素。 |
|OH_JSVM_HasElement | 若给定对象的指定索引处拥有属性，获取该元素。 |
|OH_JSVM_DeleteElement | 尝试删除给定对象的指定索引处的元素。 |
|OH_JSVM_DefineProperties |  批量的向给定对象中定义属性。 |
|OH_JSVM_ObjectFreeze | 冻结给定的对象,防止向其添加新属性，删除现有属性，防止更改现有属性的可枚举性、可配置性或可写性，并防止更改现有属性的值。 |
|OH_JSVM_ObjectSeal | 密封给定的对象。这可以防止向其添加新属性，以及将所有现有属性标记为不可配置。 |
|OH_JSVM_ObjectSetPrototypeOf | 为给定对象设置一个原型。 |
|OH_JSVM_ObjectGetPrototypeOf | 获取给定JavaScript对象的原型。 |

场景示例:
JS对象属性的增加、删除、获取和判断。

```c++
// 创建一个空对象
JSVM_Value myObject = nullptr;
OH_JSVM_CreateObject(env, &myObject);

// 设置属性
const char *testNameStr = "John Doe";
JSVM_Value propValue = nullptr;
JSVM_Value key;
OH_JSVM_CreateStringUtf8(env, "name", JSVM_AUTO_LENGTH, &key);
OH_JSVM_CreateStringUtf8(env, testNameStr, strlen(testNameStr), &propValue);
OH_JSVM_SetProperty(env, myObject, key, propValue);

// 获取属性
JSVM_Value propResult = nullptr;
OH_JSVM_GetProperty(env, myObject, key, &propResult);

// 检查属性是否存在
bool hasProperty = false;
OH_JSVM_HasNamedProperty(env, myObject, "name", &hasProperty);
    // 属性存在，做相应处理...
    if (hasProperty)
    {
        // 获取对象的所有属性名
        JSVM_Value propNames = nullptr;
        OH_JSVM_GetPropertyNames(env, myObject, &propNames);

        bool isArray = false;
        OH_JSVM_IsArray(env, propNames, &isArray);

        uint32_t arrayLength = 0;
        OH_JSVM_GetArrayLength(env, propNames, &arrayLength);
        // 遍历属性元素
        for (uint32_t i = 0; i < arrayLength; i++)
        {
            bool hasElement = false;
            OH_JSVM_HasElement(env, propNames, i, &hasElement);

            JSVM_Value propName = nullptr;
            OH_JSVM_GetElement(env, propNames, i, &propName);

            bool hasProp = false;
            OH_JSVM_HasProperty(env, myObject, propName, &hasProp);

            JSVM_Value propValue = nullptr;
            OH_JSVM_GetProperty(env, myObject, propName, &propValue);
        }
    }

// 删除属性
OH_JSVM_DeleteProperty(env, myObject, key, &hasProperty);

// 设置对象原型
JSVM_Value value;
OH_JSVM_CreateSet(env, &value);
OH_JSVM_ObjectSetPrototypeOf(env, myObject, value);

// 获取对象原型
JSVM_Value proto;
OH_JSVM_ObjectGetPrototypeOf(env, myObject, &proto);
```

### JS函数操作

#### 场景介绍

JS函数操作。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_CallFunction | 在C/C++侧调用JS方法 |
|OH_JSVM_CreateFunction | 用于创建JavaScript函数,用于从JavaScript环境中调用C/C++代码中的函数 |
|OH_JSVM_GetCbInfo | 从给定的callback info中获取有关调用的详细信息，如参数和this指针 |
|OH_JSVM_GetNewTarget | 获取构造函数调用的new.target |
|OH_JSVM_NewInstance | 通过给定的构造函数，构建一个实例 |
|OH_JSVM_CreateFunctionWithScript | 根据传入的函数体和函数参数列表，创建一个新的 JavaScript Function对象 |

场景示例:
创建JavaScript函数操作。

```c++
JSVM_Value SayHello(JSVM_Env env, JSVM_CallbackInfo info)
{
    printf("Hello\n");
    JSVM_Value ret;
    OH_JSVM_CreateInt32(env, 2, &ret);
    return ret;
}

static JSVM_Value JsvmCreateFunction(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_CallbackStruct param;
    param.data = nullptr;
    param.callback = SayHello;

    JSVM_Value funcValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateFunction(env, "func", JSVM_AUTO_LENGTH, &param, &funcValue);
    return funcValue;
}
```

在C/C++侧调用JS方法。

```c++
static JSVM_Value CallFunction(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1];
    JSVM_CALL(env, OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

    JSVM_ASSERT(env, argc >= 1, "Wrong number of arguments");

    JSVM_ValueType valuetype;
    JSVM_CALL(env, OH_JSVM_Typeof(env, args[0], &valuetype));
    JSVM_ASSERT(env, valuetype == JSVM_ValueType::JSVM_FUNCTION, "Wrong type of argment. Expects a string.");

    JSVM_Value global;
    JSVM_CALL(env, OH_JSVM_GetGlobal(env, &global));

    JSVM_Value ret;
    JSVM_CALL(env, OH_JSVM_CallFunction(env, global, args[0], 0, nullptr, &ret));
    return ret;
}
```

创建JavaScript函数:

```c++
JSVM_Value script;
OH_JSVM_CreateStringUtf8(env, "return a + b;", JSVM_AUTO_LENGTH, &script);
JSVM_Value param1;
JSVM_Value param2;
OH_JSVM_CreateStringUtf8(env, "a", JSVM_AUTO_LENGTH, &param1);
OH_JSVM_CreateStringUtf8(env, "b", JSVM_AUTO_LENGTH, &param2);
JSVM_Value argus[] = {param1, param2};
JSVM_Value func;
OH_JSVM_CreateFunctionWithScript(env, "add", JSVM_AUTO_LENGTH, 2, argus, script, &func);
```

### 对象绑定操作

#### 场景介绍

对象绑定操作。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_DefineClass| 用于在JavaScript中定义一个类，并与对应的C类进行封装和交互。它提供了创建类的构造函数、定义属性和方法的能力，以及在C和JavaScript之间进行数据交互的支持。 |
|OH_JSVM_Wrap| 在 JavaScript 对象中封装原生实例。稍后可以使用 OH_JSVM_Unwrap() 检索原生实例。 |
|OH_JSVM_Unwrap | 使用 OH_JSVM_Wrap() 检索先前封装在 JavaScript 对象中的原生实例。 |
|OH_JSVM_RemoveWrap | 检索先前封装在 JavaScript 对象中的原生实例并移除封装。 |
|OH_JSVM_TypeTagObject | 将 type_tag 指针的值与 JavaScript 对象或外部对象相关联。 |
|OH_JSVM_CheckObjectTypeTag | 检查给定的类型标签是否与对象上的类型标签匹配。 |
|OH_JSVM_AddFinalizer | 为对象添加 JSVM_Finalize 回调，以便在 JavaScript 对象被垃圾回收时调用来释放原生对象。 |
|OH_JSVM_DefineClassWithPropertyHandler | 定义一个具有给定类名、构造函数、属性和回调处理程序的JavaScript类，并作为函数回调进行调用。属性操作包括getter、setter、deleter、enumerator等。 |
|OH_JSVM_DefineClassWithOptions | 定义一个具有给定类名、构造函数、属性和回调处理程序、父类的JavaScript类，并根据传入了DefineClassOptions来决定是否需要为所定义的Class设置属性代理、预留internal-field槽位、为class作为函数进行调用时设置函数回调。|

场景示例：
对象绑定操作。

```c++
static int aa = 0; 

static JSVM_Value AssertEqual(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 2;
    JSVM_Value args[2];
    JSVM_CALL(env, OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

    bool isStrictEquals = false;
    OH_JSVM_StrictEquals(env, args[0], args[1], &isStrictEquals);
    return nullptr;
}

static napi_value TestWrap(napi_env env1, napi_callback_info info)
{
    OH_LOG_ERROR(LOG_APP, "testWrap start");
    JSVM_InitOptions init_options;
    memset(&init_options, 0, sizeof(init_options));
    init_options.externalReferences = externals;
    if (aa == 0) {
        OH_JSVM_Init(&init_options);
        aa++;
    }
    JSVM_VM vm;
    JSVM_CreateVMOptions options;
    memset(&options, 0, sizeof(options));
    OH_JSVM_CreateVM(&options, &vm);
    JSVM_VMScope vm_scope;
    OH_JSVM_OpenVMScope(vm, &vm_scope);
    JSVM_Env env;
    JSVM_CallbackStruct param[1];
    param[0].data = nullptr;
    param[0].callback = AssertEqual;
    JSVM_PropertyDescriptor descriptor[] = {
        {"assertEqual", NULL, &param[0], NULL, NULL, NULL, JSVM_DEFAULT},
    };
    OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    JSVM_HandleScope handlescope;
    OH_JSVM_OpenHandleScope(env, &handlescope);
    JSVM_Value testClass = nullptr;
    JSVM_CallbackStruct param1;
    param1.data = nullptr;
    param1.callback = [](JSVM_Env env, JSVM_CallbackInfo info) -> JSVM_Value {
        JSVM_Value thisVar = nullptr;
        OH_JSVM_GetCbInfo(env, info, nullptr, nullptr, &thisVar, nullptr);

        return thisVar;
    };
    OH_JSVM_DefineClass(env, "TestClass", JSVM_AUTO_LENGTH, &param1, 0, nullptr, &testClass);

    JSVM_Value instanceValue = nullptr;
    OH_JSVM_NewInstance(env, testClass, 0, nullptr, &instanceValue);

    const char *testStr = "test";
    OH_JSVM_Wrap(
        env, instanceValue, (void *)testStr, [](JSVM_Env env, void *data, void *hint) {}, nullptr, nullptr);
    const char *tmpTestStr = nullptr;
    OH_JSVM_Unwrap(env, instanceValue, (void **)&tmpTestStr);
    const char *tmpTestStr1 = nullptr;
    OH_JSVM_RemoveWrap(env, instanceValue, (void **)&tmpTestStr1);
    OH_JSVM_Unwrap(env, instanceValue, (void **)&tmpTestStr1);
    OH_JSVM_CloseHandleScope(env, handlescope);
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vm_scope);
    OH_JSVM_DestroyVM(vm);
    OH_LOG_ERROR(LOG_APP, "testWrap pass");
    return nullptr;
}
```

场景示例：
对象绑定及监听拦截属性操作。

```c++
static int aa = 0;
static JSVM_Value hello(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Value output;
    void *data = nullptr;
    OH_JSVM_GetCbInfo(env, info, nullptr, nullptr, nullptr, &data);
    OH_JSVM_CreateStringUtf8(env, (char *)data, strlen((char *)data), &output);
    return output;
}

static JSVM_CallbackStruct hello_cb = {hello, (void *)"Hello"};
static intptr_t externals[] = {
    (intptr_t)&hello_cb,
    0,
};

static void test1() { OH_LOG_INFO(LOG_APP, "test1 called"); }

struct Test {
    void *ptr1;
    void *ptr2;
};

static JSVM_Value assertEqual(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 2;
    JSVM_Value args[2];
    JSVM_CALL(env, OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

    bool isStrictEquals = false;
    OH_JSVM_StrictEquals(env, args[0], args[1], &isStrictEquals);
    return nullptr;
}

static JSVM_Value GetPropertyCbInfo(JSVM_Env env, JSVM_Value name, JSVM_Value thisArg, JSVM_Value data) {
    // 该回调是由对象上的获取请求触发的
    char strValue[100];
    size_t size = 0;
    OH_JSVM_GetValueStringUtf8(env, name, strValue, 300, &size);
    JSVM_Value newResult = nullptr;
    char newStr[] = "new return value hahaha from name listening";
    OH_JSVM_CreateStringUtf8(env, newStr, strlen(newStr), &newResult);
    int signBit = 0;
    size_t wordCount = 2;
    uint64_t wordsOut[2] = {0ULL, 0ULL};
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, data, &signBit, &wordCount, wordsOut);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "GetPropertyCbInfo wordCount is %{public}zu", wordCount);
        auto test = reinterpret_cast<Test *>(wordsOut);
        typedef void (*callTest1)();
        callTest1 callTe = reinterpret_cast<callTest1>(test->ptr1);
        callTe();
    }
    return nullptr;
}

static JSVM_Value SetPropertyCbInfo(JSVM_Env env, JSVM_Value name, JSVM_Value property, JSVM_Value thisArg, JSVM_Value data) {
    // 该回调是由对象上的设置请求触发的
    char strValue[100];
    size_t size = 0;
    OH_JSVM_GetValueStringUtf8(env, name, strValue, 300, &size);
    JSVM_Value newResult = nullptr;
    char newStr[] = "new return value hahaha from name listening";
    OH_JSVM_CreateStringUtf8(env, newStr, strlen(newStr), &newResult);
    int signBit = 0;
    size_t wordCount = 2;
    uint64_t wordsOut[2] = {0ULL, 0ULL};
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, data, &signBit, &wordCount, wordsOut);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "SetPropertyCbInfo wordCount is %{public}zu", wordCount);
        auto test = reinterpret_cast<Test *>(wordsOut);
        typedef void (*callTest1)();
        callTest1 callTe = reinterpret_cast<callTest1>(test->ptr1);
        callTe();
    }
    return nullptr;
}

static JSVM_Value DeleterPropertyCbInfo(JSVM_Env env, JSVM_Value name, JSVM_Value thisArg, JSVM_Value data) {
    // 该回调是由对象上的删除请求触发的
    char strValue[100];
    size_t size = 0;
    OH_JSVM_GetValueStringUtf8(env, name, strValue, 300, &size);
    JSVM_Value newResult = nullptr;
    bool returnValue = false;
    OH_JSVM_GetBoolean(env, returnValue, &newResult);
    int signBit = 0;
    size_t wordCount = 2;
    uint64_t wordsOut[2] = {0ULL, 0ULL};
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, data, &signBit, &wordCount, wordsOut);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "DeleterPropertyCbInfo wordCount is %{public}zu", wordCount);
        auto test = reinterpret_cast<Test *>(wordsOut);
        typedef void (*callTest1)();
        callTest1 callTe = reinterpret_cast<callTest1>(test->ptr1);
        callTe();
    }
    return nullptr;
}

static JSVM_Value EnumeratorPropertyCbInfo(JSVM_Env env, JSVM_Value thisArg, JSVM_Value data) {
    // 该回调是由获取对象上的所有属性请求触发的
    JSVM_Value testArray = nullptr;
    OH_JSVM_CreateArrayWithLength(env, 2, &testArray);
    JSVM_Value name1 = nullptr;
    char newStr1[] = "hahaha";
    OH_JSVM_CreateStringUtf8(env, newStr1, strlen(newStr1), &name1);
    JSVM_Value name2 = nullptr;
    char newStr2[] = "heheheh";
    OH_JSVM_CreateStringUtf8(env, newStr2, strlen(newStr2), &name2);

    OH_JSVM_SetElement(env, testArray, 0, name1);
    OH_JSVM_SetElement(env, testArray, 1, name2);
    int signBit = 0;
    size_t wordCount = 2;
    uint64_t wordsOut[2] = {0ULL, 0ULL};
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, data, &signBit, &wordCount, wordsOut);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "EnumeratorPropertyCbInfo wordCount is %{public}zu", wordCount);
        auto test = reinterpret_cast<Test *>(wordsOut);
        typedef void (*callTest1)();
        callTest1 callTe = reinterpret_cast<callTest1>(test->ptr1);
        callTe();
    }
    return nullptr;
}

static JSVM_Value IndexedPropertyGet(JSVM_Env env, JSVM_Value index, JSVM_Value thisArg, JSVM_Value data) {
    // 该回调是由获取实例对象的索引属性触发的
    uint32_t value = 0;
    OH_JSVM_GetValueUint32(env, index, &value);

    JSVM_Value newResult = nullptr;
    char newStr[] = "new return value hahaha from index listening";
    OH_JSVM_CreateStringUtf8(env, newStr, strlen(newStr), &newResult);
    int signBit = 0;
    size_t wordCount = 2;
    uint64_t wordsOut[2] = {0ULL, 0ULL};
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, data, &signBit, &wordCount, wordsOut);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "IndexedPropertyGet wordCount is %{public}zu", wordCount);
        auto test = reinterpret_cast<Test *>(wordsOut);
        typedef void (*callTest1)();
        callTest1 callTe = reinterpret_cast<callTest1>(test->ptr1);
        callTe();
    }
    return nullptr;
}

static JSVM_Value IndexedPropertySet(JSVM_Env env, JSVM_Value index, JSVM_Value property, JSVM_Value thisArg, JSVM_Value data) {
    // 该回调是由设置实例对象的索引属性触发的
    uint32_t value = 0;
    OH_JSVM_GetValueUint32(env, index, &value);
    char str[100];
    size_t size = 0;
    OH_JSVM_GetValueStringUtf8(env, property, str, 100, &size);
    JSVM_Value newResult = nullptr;
    char newStr[] = "new return value hahaha from name listening";
    OH_JSVM_CreateStringUtf8(env, newStr, strlen(newStr), &newResult);
    int signBit = 0;
    size_t wordCount = 2;
    uint64_t wordsOut[2] = {0ULL, 0ULL};
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, data, &signBit, &wordCount, wordsOut);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "IndexedPropertySet wordCount is %{public}zu", wordCount);
        auto test = reinterpret_cast<Test *>(wordsOut);
        typedef void (*callTest1)();
        callTest1 callTe = reinterpret_cast<callTest1>(test->ptr1);
        callTe();
    }
    return nullptr;
}

static JSVM_Value IndexedPropertyDeleter(JSVM_Env env, JSVM_Value index, JSVM_Value thisArg, JSVM_Value data) {
    // 该回调是由删除实例对象的索引属性触发的
    uint32_t value = 0;
    OH_JSVM_GetValueUint32(env, index, &value);
    JSVM_Value newResult = nullptr;
    bool returnValue = false;
    OH_JSVM_GetBoolean(env, returnValue, &newResult);
    int signBit = 0;
    size_t wordCount = 2;
    uint64_t wordsOut[2] = {0ULL, 0ULL};
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, data, &signBit, &wordCount, wordsOut);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "IndexedPropertyDeleter wordCount is %{public}zu", wordCount);
        auto test = reinterpret_cast<Test *>(wordsOut);
        typedef void (*callTest1)();
        callTest1 callTe = reinterpret_cast<callTest1>(test->ptr1);
        callTe();
    }
    return nullptr;
}

static JSVM_Value IndexedPropertyEnumerator(JSVM_Env env, JSVM_Value thisArg, JSVM_Value data) {
    // 该回调是由获取对象上的所有索引属性请求触发的
    JSVM_Value testArray = nullptr;
    OH_JSVM_CreateArrayWithLength(env, 2, &testArray);
    JSVM_Value index1 = nullptr;
    OH_JSVM_CreateUint32(env, 1, &index1);
    JSVM_Value index2 = nullptr;
    OH_JSVM_CreateUint32(env, 2, &index2);
    OH_JSVM_SetElement(env, testArray, 0, index1);
    OH_JSVM_SetElement(env, testArray, 1, index2);
    int signBit = 0;
    size_t wordCount = 2;
    uint64_t wordsOut[2] = {0ULL, 0ULL};
    JSVM_Status status = OH_JSVM_GetValueBigintWords(env, data, &signBit, &wordCount, wordsOut);
    if (status == JSVM_OK) {
        OH_LOG_INFO(LOG_APP, "IndexedPropertyDeleter wordCount is %{public}zu", wordCount);
        auto test = reinterpret_cast<Test *>(wordsOut);
        typedef void (*callTest1)();
        callTest1 callTe = reinterpret_cast<callTest1>(test->ptr1);
        callTe();
    }
    return nullptr;
}

static napi_value TestDefineClassWithProperty(napi_env env1, napi_callback_info info) {
    OH_LOG_ERROR(LOG_APP, "TestDefineClassWithProperty start");
    JSVM_InitOptions init_options;
    memset(&init_options, 0, sizeof(init_options));
    init_options.externalReferences = externals;
    if (aa == 0) {
        OH_JSVM_Init(&init_options);
        aa++;
    }
    JSVM_VM vm;
    JSVM_CreateVMOptions options;
    memset(&options, 0, sizeof(options));
    OH_JSVM_CreateVM(&options, &vm);
    JSVM_VMScope vm_scope;
    OH_JSVM_OpenVMScope(vm, &vm_scope);
    JSVM_Env env;
    JSVM_CallbackStruct param[1];
    param[0].data = nullptr;
    param[0].callback = assertEqual;
    JSVM_PropertyDescriptor descriptor[] = {
        {"assertEqual", NULL, &param[0], NULL, NULL, NULL, JSVM_DEFAULT},
    };
    OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    JSVM_HandleScope handlescope;
    OH_JSVM_OpenHandleScope(env, &handlescope);


    JSVM_CallbackStruct param1;
    param1.callback = [](JSVM_Env env, JSVM_CallbackInfo info) -> JSVM_Value {
        JSVM_Value thisVar = nullptr;
        OH_JSVM_GetCbInfo(env, info, nullptr, nullptr, &thisVar, nullptr);
        return thisVar;
    };
    param1.data = nullptr;

    JSVM_Value res = nullptr;
    Test *test = new Test();
    test->ptr1 = (void *)test1;
    test->ptr2 = (void *)test1;
    OH_LOG_INFO(LOG_APP, "OH_JSVM_CreateBigintWords 111 word count %{public}d",
                sizeof(*test) / sizeof(uint64_t));
    JSVM_Status status = OH_JSVM_CreateBigintWords(env, 1, 2, reinterpret_cast<const uint64_t *>(test), &res);

    // 初始化propertyCfg
    JSVM_PropertyHandlerConfigurationStruct propertyCfg;
    propertyCfg.genericNamedPropertyGetterCallback = GetPropertyCbInfo;
    propertyCfg.genericNamedPropertySetterCallback = SetPropertyCbInfo;
    propertyCfg.genericNamedPropertyDeleterCallback = DeleterPropertyCbInfo;
    propertyCfg.genericNamedPropertyEnumeratorCallback = EnumeratorPropertyCbInfo;
    propertyCfg.genericIndexedPropertyGetterCallback = IndexedPropertyGet;
    propertyCfg.genericIndexedPropertySetterCallback = IndexedPropertySet;
    propertyCfg.genericIndexedPropertyDeleterCallback = IndexedPropertyDeleter;
    propertyCfg.genericIndexedPropertyEnumeratorCallback = IndexedPropertyEnumerator;
    propertyCfg.namedPropertyData = res;
    propertyCfg.indexedPropertyData = res;

    JSVM_CallbackStruct callbackStruct;
    callbackStruct.callback = [](JSVM_Env env, JSVM_CallbackInfo info) -> JSVM_Value {
        OH_LOG_INFO(LOG_APP, "call as a function called");
        JSVM_Value thisVar = nullptr;
        void *innerData;
        size_t argc = 1;
        JSVM_Value args[1];
        OH_JSVM_GetCbInfo(env, info, &argc, args, &thisVar, &innerData);
        OH_LOG_INFO(LOG_APP, "function call as function result is %{public}s", reinterpret_cast<char *>(innerData));
        uint32_t ret = 0;
        OH_JSVM_GetValueUint32(env, args[0], &ret);
        const char testStr[] = "hello world 111111";
        JSVM_Value setvalueName = nullptr;
        JSVM_CALL(env, OH_JSVM_CreateStringUtf8(env, testStr, strlen(testStr), &setvalueName));
        return setvalueName;
    };
    char data[100] = "1111 hello world";
    callbackStruct.data = data;
    JSVM_Value testWrapClass = nullptr;

    // 将属性的访问监听注册在propertyCfg中
    OH_JSVM_DefineClassWithPropertyHandler(env, "TestWrapClass", NAPI_AUTO_LENGTH, &param1, 0, nullptr, &propertyCfg,
                                           &callbackStruct, &testWrapClass);
    JSVM_Value instanceValue = nullptr;
    OH_JSVM_NewInstance(env, testWrapClass, 0, nullptr, &instanceValue);
    const char testStr[] = "hello world";
    JSVM_Value setvalueName = nullptr;
    OH_JSVM_CreateStringUtf8(env, testStr, strlen(testStr), &setvalueName);

    // 1. 名称属性回调
    // 设置属性
    OH_JSVM_SetNamedProperty(env, instanceValue, "str11", setvalueName);
    OH_JSVM_SetNamedProperty(env, instanceValue, "str123", setvalueName);

    // 获取属性
    JSVM_Value valueName = nullptr;
    OH_JSVM_GetNamedProperty(env, instanceValue, "str11", &valueName);
    char str[100];
    size_t size = 0;
    OH_JSVM_GetValueStringUtf8(env, valueName, str, 100, &size);

    // 获取所有属性的名称
    JSVM_Value allPropertyNames = nullptr;
    OH_JSVM_GetAllPropertyNames(env, instanceValue, JSVM_KEY_OWN_ONLY,
                                static_cast<JSVM_KeyFilter>(JSVM_KEY_ENUMERABLE | JSVM_KEY_SKIP_SYMBOLS),
                                JSVM_KEY_NUMBERS_TO_STRINGS, &allPropertyNames);
    uint32_t nameSize = 0;
    OH_JSVM_GetArrayLength(env, allPropertyNames, &nameSize);
    JSVM_Value propertyName = nullptr;
    for (uint32_t i = 0; i < nameSize; ++i) {
        OH_JSVM_GetElement(env, allPropertyNames, i, &propertyName);
        char str[100];
        size_t size = 0;
        OH_JSVM_GetValueStringUtf8(env, propertyName, str, 100, &size);
    }

    // 删除属性
    bool result = false;
    propertyName = nullptr;
    char propertyChar[] = "str11";
    OH_JSVM_CreateStringUtf8(env, propertyChar, strlen(propertyChar), &propertyName);
    OH_JSVM_DeleteProperty(env, instanceValue, propertyName, &result);

    // 2. 索引属性回调
    // 设置属性
    JSVM_Value jsIndex = nullptr;
    uint32_t index = 0;
    OH_JSVM_CreateUint32(env, index, &jsIndex);
    OH_JSVM_SetProperty(env, instanceValue, jsIndex, setvalueName);
    JSVM_Value jsIndex1 = nullptr;
    index = 1;
    OH_JSVM_CreateUint32(env, index, &jsIndex1);
    OH_JSVM_SetProperty(env, instanceValue, jsIndex1, setvalueName);

    // 获取属性
    JSVM_Value valueName1 = nullptr;
    OH_JSVM_GetProperty(env, instanceValue, jsIndex, &valueName1);
    char str1[100];
    size_t size1 = 0;
    OH_JSVM_GetValueStringUtf8(env, valueName1, str1, 100, &size1);

    // 获取所有属性的名称
    JSVM_Value allPropertyNames1 = nullptr;
    OH_JSVM_GetAllPropertyNames(env, instanceValue, JSVM_KEY_OWN_ONLY,
                                static_cast<JSVM_KeyFilter>(JSVM_KEY_ENUMERABLE | JSVM_KEY_SKIP_SYMBOLS),
                                JSVM_KEY_NUMBERS_TO_STRINGS, &allPropertyNames1);
    uint32_t nameSize1 = 0;
    OH_JSVM_GetArrayLength(env, allPropertyNames1, &nameSize);
    JSVM_Value propertyName1 = nullptr;
    for (uint32_t i = 0; i < nameSize1; ++i) {
        OH_JSVM_GetElement(env, allPropertyNames1, i, &propertyName1);
        char str[100];
        size_t size = 0;
        OH_JSVM_GetValueStringUtf8(env, propertyName1, str, 100, &size);
    }

    // 删除属性
    bool result1 = false;
    OH_JSVM_DeleteProperty(env, instanceValue, jsIndex, &result1);

    // 3. 作为函数的回调
    JSVM_Value gloablObj = nullptr;
    OH_JSVM_GetGlobal(env, &gloablObj);
    OH_JSVM_SetNamedProperty(env, gloablObj, "myTestInstance", instanceValue);
    OH_LOG_INFO(LOG_APP, "set property on global object");
    std::string innerSourcecodestr = R"(
    {
        let res = myTestInstance(12);
    })";
    JSVM_Value innerSourcecodevalue;
    OH_JSVM_CreateStringUtf8(env, innerSourcecodestr.c_str(), innerSourcecodestr.size(), &innerSourcecodevalue);
    JSVM_Script innerscript;
    OH_JSVM_CompileScript(env, innerSourcecodevalue, nullptr, 0, true, nullptr, &innerscript);
    JSVM_Value innerResult;
    OH_JSVM_RunScript(env, innerscript, &innerResult);

    OH_JSVM_CloseHandleScope(env, handlescope);
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vm_scope);
    OH_JSVM_DestroyVM(vm);
    OH_LOG_ERROR(LOG_APP, "TestDefineClassWithProperty pass");
    return nullptr;
}
```
场景示例：设置父类并通过DefineClassOptions设置监听拦截属性操作

具体示例参考[使用JSVM进行class相关开发](use-jsvm-about-class.md)。

### 版本管理

#### 场景介绍

获取当前版本信息。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_GetVersion| 返回JSVM运行时支持的最高JSVM API版本 |
|OH_JSVM_GetVMInfo| 返回虚拟机的信息 |

场景示例：
获取当前版本信息。

```c++
JSVM_VMInfo result;
OH_JSVM_GetVMInfo(&result);
uint32_t versionId = 0;
OH_JSVM_GetVersion(env, &versionId);
```

### 内存管理

#### 场景介绍

内存管理。

#### 接口说明
| 接口                                          | 功能说明                                                                                                   |
| ------------------------------------------- | ------------------------------------------------------------------------------------------------------ |
| OH_JSVM_AdjustExternalMemory                | 将因JavaScript对象而保持活跃的外部分配的内存大小及时通知给底层虚拟机，虚拟机后续触发GC时，就会综合内外内存状态来判断是否进行全局GC。即增大外部内存分配，则会增大触发全局GC的概率；反之减少。 |
| OH_JSVM_MemoryPressureNotification          | 通知虚拟机系统内存压力层级，并有选择地触发垃圾回收。                                                                             |
| OH_JSVM_AllocateArrayBufferBackingStoreData | 申请一块 BackingStore 内存。 |
| OH_JSVM_FreeArrayBufferBackingStoreData | 释放 BackingStore 内存。 |
| OH_JSVM_CreateArrayBufferFromBackingStoreData | 基于申请的 BackingStore 内存创建 array buffer。 |

> 使用 BackingStore 属于高危操作，使用者需确保内存使用正确。请参考下方正确示例，谨慎操作。

场景示例：
内存管理。

```c++
// 分别在调用OH_JSVM_AdjustExternalMemory前后来查看底层虚拟机视角下外部分配的内存大小
int64_t result = 0;
OH_JSVM_AdjustExternalMemory(env, 0, &result); // 假设外部分配内存的变化不变
OH_LOG_INFO(LOG_APP, "Before AdjustExternalMemory: %{public}lld\n", result); // 得到调整前的数值
// 调整外部分配的内存大小通知给底层虚拟机（此示例假设内存使用量增加）
int64_t memoryIncrease = 1024 * 1024; // 增加 1 MB
OH_JSVM_AdjustExternalMemory(env, memoryIncrease, &result);
OH_LOG_INFO(LOG_APP, "After AdjustExternalMemory: %{public}lld\n", result); // 得到调整后的数值
```
```c++
// 打开一个Handle scope，在scope范围内申请大量内存来测试函数功能；
// 分别在“完成申请后”、“关闭scope后”和“调用OH_JSVM_MemoryPressureNotification后”三个节点查看内存状态
JSVM_HandleScope tmpscope;
OH_JSVM_OpenHandleScope(env, &tmpscope);
for (int i = 0; i < 1000000; ++i) {
    JSVM_Value obj;
    OH_JSVM_CreateObject(env, &obj);
}
JSVM_HeapStatistics mem;
OH_JSVM_GetHeapStatistics(vm, &mem); // 获取虚拟机堆的统计数据
OH_LOG_INFO(LOG_APP, "%{public}zu\n", mem.usedHeapSize); // 申请完成后，内存处于最大状态
OH_JSVM_CloseHandleScope(env, tmpscope); // 关闭Handle scope

OH_JSVM_GetHeapStatistics(vm, &mem);
OH_LOG_INFO(LOG_APP, "%{public}zu\n", mem.usedHeapSize); // 关闭scope后，GC并没有立即回收

// 通知虚拟机系统内存压力层级，并有选择地触发垃圾回收
OH_JSVM_MemoryPressureNotification(env, JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL); // 假设内存压力处于临界状态

OH_JSVM_GetHeapStatistics(vm, &mem);
OH_LOG_INFO(LOG_APP, "%{public}zu\n", mem.usedHeapSize); // 触发垃圾回收后
```

BackingStore 正确使用示例
``` c++
void *backingStore;
JSVM_Value arrayBuffer;

// 申请一块大小为 100 字节的 BackingStore 内存
OH_JSVM_AllocateArrayBufferBackingStoreData(100, JSVM_ZERO_INITIALIZED, &backingStore);

// 在之前申请的 BackingStore 上创建一个 ArrayBuffer，位置为距离 BackingStore 起始地址加 30 字节处，大小为 20 字节
OH_JSVM_CreateArrayBufferFromBackingStoreData(env, backingStore, 100, 30, 20, &arrayBuffer);

// 在 JS 中使用创建的 ArrayBuffer
JSVM_Value js_global;
JSVM_Value name;
OH_JSVM_GetGlobal(jsvm_env, &js_global);
OH_JSVM_CreateStringUtf8(jsvm_env, "buffer", JSVM_AUTO_LENGTH, &name);
OH_JSVM_SetProperty(env, js_global, name, arrayBuffer);

JSVM_Script script;
JSVM_Value scriptString;
JSVM_Value result;
const char *src = R"JS(
function writeBuffer(data) {
  let view = new Uint8Array(data);
  // Write some values to the ArrayBuffer
  for (let i = 0; i < view.length; i++) {
    view[i] = i % 256;
  }
}
writeBuffer(buffer)
)JS";
OH_JSVM_CreateStringUtf8(env, src, JSVM_AUTO_LENGTH, &scriptString);
OH_JSVM_CompileScriptWithOptions(env, scriptString, 0, nullptr, &script);
OH_JSVM_RunScript(env, script, &result);

// 检查 ArrayBuffer 的内容
uint8_t *array = static_cast<uint8_t*>(backingStore);
for (auto i = 0; i < 100; ++i) {
  if (array[i] != i % 25 % 256) {
    return false;
  }
}

// 释放 array buffer. 注意对于这种方式创建的 ArrayBuffer, 在释放对应的 BackingStore 之前,
// 务必使用 OH_JSVM_DetachArraybuffer 将所有使用当前的 BackingStore 创建的 ArrayBuffer 释放
// 否则可能产生不可预测的内存问题，请谨慎使用
OH_JSVM_DetachArraybuffer(env, arrayBuffer);

// 释放申请的 backing store 内存
OH_JSVM_FreeArrayBufferBackingStoreData(backingStore);
```
### Promise操作

#### 场景介绍

Promise相关操作。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_CreatePromise| 创建一个延迟对象和一个JavaScript promise |
|OH_JSVM_ResolveDeferred| 通过与之关联的延迟对象来解析JavaScript promise |
|OH_JSVM_RejectDeferred| 通过与之关联的延迟对象来拒绝JavaScript Promise |
|OH_JSVM_IsPromise| 查询Promise是否为原生Promise对象 |

场景示例：
Promise相关操作。

```c++
JSVM_Deferred deferred;
JSVM_Value promise;
OH_JSVM_CreatePromise(env, &deferred, &promise);

// 模拟异步操作
int result = 42;
bool success = true;
if (success)
{
    // 解析Promise，并传递结果
    JSVM_Value value;
    OH_JSVM_CreateInt32(env, result, &value);
    OH_JSVM_ResolveDeferred(env, deferred, value);
} else {
    // 拒绝Promise，并传递错误信息
    JSVM_Value code = nullptr;
    JSVM_Value message = nullptr;
    OH_JSVM_CreateStringUtf8(env, "600", JSVM_AUTO_LENGTH, &code);
    OH_JSVM_CreateStringUtf8(env, "Async operation failed", JSVM_AUTO_LENGTH, &message);
    JSVM_Value error = nullptr;
    OH_JSVM_CreateError(env, code, message, &error);
    OH_JSVM_RejectDeferred(env, deferred, error);
}
```

### JSON操作

#### 场景介绍

JSON操作。

#### 接口说明

| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_JsonParse| 解析JSON字符串，并返回成功解析的值 |
|OH_JSVM_JsonStringify| 将对象字符串化，并返回成功转换后的字符串 |

场景示例：
解析JSON操作。

```c++
std::string sourcecodestr = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}" ;
JSVM_Value jsonString;
OH_JSVM_CreateStringUtf8(env, sourcecodestr.c_str(), sourcecodestr.size(), &jsonString)
JSVM_Value result;
OH_JSVM_JsonParse(env, jsonString, &result);
```

### 创建和使用虚拟机的启动快照

#### 场景介绍

创建和使用虚拟机的启动快照。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_CreateSnapshot| 用于创建虚拟机的启动快照 |
|OH_JSVM_CreateEnvFromSnapshot| 基于启动快照创建jsvm环境 |

场景示例：
[创建和使用虚拟机的启动快照。](use-jsvm-create-snapshot.md)

### 检查传入的值是否可调用

#### 场景介绍

检查传入的值是否可调用。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_IsCallable| 检查传入的值是否可调用 |

场景示例：
检查传入的值是否可调用。

```c++
static JSVM_Value NapiIsCallable(JSVM_Env env, JSVM_CallbackInfo info) {
    JSVM_Value value, rst;
    size_t argc = 1;
    bool isCallable = false;
    JSVM_CALL(env, OH_JSVM_GetCbInfo(env, info, &argc, &value, NULL, NULL));
    JSVM_CALL(env, OH_JSVM_IsCallable(env, value, &isCallable));
    OH_JSVM_GetBoolean(env, isCallable, &rst);
    return rst;
}

static napi_value MyJSVMDemo([[maybe_unused]] napi_env _env, [[maybe_unused]] napi_callback_info _info) {
    std::thread t([]() {
        // create vm, and open vm scope
        JSVM_VM vm;
        JSVM_CreateVMOptions options;
        memset(&options, 0, sizeof(options));
        OH_JSVM_CreateVM(&options, &vm);
        JSVM_VMScope vmScope;
        OH_JSVM_OpenVMScope(vm, &vmScope);
        JSVM_CallbackStruct param[] = {
            {.data = nullptr, .callback = NapiIsCallable},
        };
        JSVM_PropertyDescriptor descriptor[] = {
            {"napiIsCallable", NULL, &param[0], NULL, NULL, NULL, JSVM_DEFAULT},
        };
        // create env, register native method, and open env scope
        JSVM_Env env;
        OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
        JSVM_EnvScope envScope;
        OH_JSVM_OpenEnvScope(env, &envScope);
        // open handle scope
        JSVM_HandleScope handleScope;
        OH_JSVM_OpenHandleScope(env, &handleScope);
        std::string sourceCodeStr = R"JS(
        function addNumbers(num1, num2)
        {
            var rst= num1 + num2;
            return rst;
        }
        let rst = napiIsCallable(addNumbers);
        )JS";
        // compile js script
        JSVM_Value sourceCodeValue;
        OH_JSVM_CreateStringUtf8(env, sourceCodeStr.c_str(), sourceCodeStr.size(), &sourceCodeValue);
        JSVM_Script script;
        OH_JSVM_CompileScript(env, sourceCodeValue, nullptr, 0, true, nullptr, &script);
        JSVM_Value result;
        // run js script
        OH_JSVM_RunScript(env, script, &result);
        JSVM_ValueType type;
        OH_JSVM_Typeof(env, result, &type);
        OH_LOG_INFO(LOG_APP, "JSVM API TEST type: %{public}d", type);
        // exit vm and clean memory
        OH_JSVM_CloseHandleScope(env, handleScope);
        OH_JSVM_CloseEnvScope(env, envScope);
        OH_JSVM_DestroyEnv(env);
        OH_JSVM_CloseVMScope(vm, vmScope);
        OH_JSVM_DestroyVM(vm);
    });
    t.detach();
    return nullptr;
}
```

### Lock操作

#### 场景介绍

Lock操作。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_IsLocked| 判断当前线程是否持有指定环境的锁 |
|OH_JSVM_AcquireLock| 获取指定环境的锁 |
|OH_JSVM_ReleaseLock| 释放指定环境的锁 |

场景示例：
加锁解锁操作。

```c++
class LockWrapper {
 public:
  LockWrapper(JSVM_Env env) : env(env) {
    OH_JSVM_IsLocked(env, &isLocked);
    if (!isLocked) {
      OH_JSVM_AcquireLock(env);
      OH_JSVM_GetVM(env, &vm);
      OH_JSVM_OpenVMScope(vm, &vmScope);
      OH_JSVM_OpenEnvScope(env, &envScope);
    }
  }

  ~LockWrapper() {
    if (!isLocked) {
      OH_JSVM_CloseEnvScope(env, envScope);
      OH_JSVM_CloseVMScope(vm, vmScope);
      OH_JSVM_ReleaseLock(env);
    }
  }

  LockWrapper(const LockWrapper&) = delete;
  LockWrapper& operator=(const LockWrapper&) = delete;
  LockWrapper(LockWrapper&&) = delete;
  void* operator new(size_t) = delete;
  void* operator new[](size_t) = delete;

 private:
  JSVM_Env env;
  JSVM_EnvScope envScope;
  JSVM_VMScope vmScope;
  JSVM_VM vm;
  bool isLocked;
};

static int aa = 0; 

static napi_value Add([[maybe_unused]] napi_env _env, [[maybe_unused]] napi_callback_info _info) {
    static JSVM_VM vm;
    static JSVM_Env env;
    if (aa == 0) {
        OH_JSVM_Init(nullptr);
        aa++;
        // create vm
        JSVM_CreateVMOptions options;
        memset(&options, 0, sizeof(options));
        OH_JSVM_CreateVM(&options, &vm);
        // create env
        OH_JSVM_CreateEnv(vm, 0, nullptr, &env);
    }

    std::thread t1([]() {
        LockWrapper lock(env);
        JSVM_HandleScope handleScope;
        OH_JSVM_OpenHandleScope(env, &handleScope);
        JSVM_Value value;
        JSVM_Status rst = OH_JSVM_CreateInt32(env, 32, &value); // 32: numerical value
        if (rst == JSVM_OK) {
            OH_LOG_INFO(LOG_APP, "JSVM:t1 OH_JSVM_CreateInt32 suc");
        } else {
            OH_LOG_ERROR(LOG_APP, "JSVM:t1 OH_JSVM_CreateInt32 fail");
        }
        int32_t num1 = 0;
        OH_JSVM_GetValueInt32(env, value, &num1);
        OH_LOG_INFO(LOG_APP, "JSVM:t1 num1 = %{public}d", num1);
        OH_JSVM_CloseHandleScope(env, handleScope);
    });
    std::thread t2([]() {
        LockWrapper lock(env);
        JSVM_HandleScope handleScope;
        OH_JSVM_OpenHandleScope(env, &handleScope);
        JSVM_Value value;
        JSVM_Status rst = OH_JSVM_CreateInt32(env, 32, &value); // 32: numerical value
        if (rst == JSVM_OK) {
            OH_LOG_INFO(LOG_APP, "JSVM:t2 OH_JSVM_CreateInt32 suc");
        } else {
            OH_LOG_ERROR(LOG_APP, "JSVM:t2 OH_JSVM_CreateInt32 fail");
        }
        int32_t num1 = 0;
        OH_JSVM_GetValueInt32(env, value, &num1);
        OH_LOG_INFO(LOG_APP, "JSVM:t2 num1 = %{public}d", num1);
        OH_JSVM_CloseHandleScope(env, handleScope);
    });
    t1.detach();
    t2.detach();
    return nullptr;
}
```

### 设置与获取和当前运行的JSVM环境相关联的数据

#### 场景介绍

使用OH_JSVM_SetInstanceData()函数，设置与当前运行的JSVM环境相关联的数据。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_SetInstanceData| 设置与当前运行的JSVM环境相关联的数据 |
|OH_JSVM_GetInstanceData| 获取与当前运行的JSVM环境相关联的数据 |

场景示例：
设置并获取与当前运行的JSVM环境相关联的数据。

```c++
JSVM_VM vm;
JSVM_CreateVMOptions options;
JSVM_VMScope vm_scope;
JSVM_Env env;
JSVM_EnvScope envScope;
JSVM_HandleScope handlescope;

static int aa = 0; 
struct InstanceData {
    int32_t value;
};

// 初始化虚拟机，创建JSVM运行环境
void init_JSVM_environment(){         
    JSVM_InitOptions init_options;
    memset(&init_options, 0, sizeof(init_options));
    if (aa == 0) {
        OH_JSVM_Init(&init_options);
        aa++;
    }
    memset(&options, 0, sizeof(options));
    OH_JSVM_CreateVM(&options, &vm);
    OH_JSVM_OpenVMScope(vm, &vm_scope);
    OH_JSVM_CreateEnv(vm, 0, nullptr, &env);
    OH_JSVM_OpenEnvScope(env, &envScope);
    OH_JSVM_OpenHandleScope(env, &handlescope);
}

// 退出虚拟机，释放对应的环境
napi_value close_JSVM_environment(napi_env env1, napi_callback_info info) 
{
    OH_JSVM_CloseHandleScope(env, handlescope);
    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vm_scope);
    OH_JSVM_DestroyVM(vm);
    napi_value result;
    char* s = "ok";
    napi_create_string_latin1(env1, s, strlen(s), &result);
    return result;
}

//清除和释放与实例相关联的内存资源
void InstanceFinalizeCallback(JSVM_Env env, void *finalizeData, void *finalizeHint)
{
    if (finalizeData) {
        InstanceData *data = reinterpret_cast<InstanceData *>(finalizeData);
        free(data);
        *(InstanceData **)finalizeData = nullptr;
    }
}

static napi_value GetInstanceData(napi_env env1, napi_callback_info info)
{
    InstanceData *instanceData = reinterpret_cast<InstanceData *>(malloc(sizeof(InstanceData)));
    if (instanceData == nullptr) {
        printf("Memory allocation failed!\n");
        return nullptr;
    }
    size_t argc = 1;
    napi_value args[1] = {nullptr};
    //用于获取回调函数参数
    napi_get_cb_info(env1, info, &argc, args , nullptr, nullptr);
    napi_valuetype valuetype0;
    napi_typeof(env1, args[0], &valuetype0);
    int32_t tmp = 0;
    napi_get_value_int32(env1, args[0], &tmp);
    instanceData->value = tmp;
    //将获得的参数与当前运行的JSVM环境关联起来
    OH_JSVM_SetInstanceData(env, instanceData, InstanceFinalizeCallback, nullptr);
    InstanceData *resData = nullptr;
    //获取与当前运行的JSVM环境相关联的数据
    OH_JSVM_GetInstanceData(env, (void **)&resData);
    napi_value result;
    napi_create_uint32(env1, resData->value, &result);
    return result;
}
```

### 任务队列

#### 场景介绍

在虚拟机内部启动任务队列的运行，检查队列中是否有待处理的微任务。任务队列可由外部事件循环执行。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_PumpMessageLoop| 启动任务队列的运行 |
|OH_JSVM_PerformMicrotaskCheckpoint| 执行任务队列里的微任务 |

场景示例：
[使用JSVM-API接口进行任务队列相关开发](use-jsvm-execute_tasks.md)