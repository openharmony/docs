# JSVM-API Data Types and APIs

## Data Types

### JSVM_Status

    Defines an enum for the execution statuses of a JSVM-API call.
    
    Each time a JSVM-API function is called, a value of **JSVM_Status** is returned to indicate the execution result.

```c++
    typedef enum {
        JSVM_OK,                              /* Successful. */
        JSVM_INVALID_ARG,                     /* Invalid parameters. */
        JSVM_OBJECT_EXPECTED,                 /* An object is expected. */
        JSVM_STRING_EXPECTED,                 /* A string is expected. */
        JSVM_NAME_EXPECTED,                   /* A name is expected. */
        JSVM_FUNCTION_EXPECTED,               /* A function is expected. */
        JSVM_NUMBER_EXPECTED,                 /* A number is expected. */
        JSVM_BOOL_EXPECTED,                   /* A Boolean value is expected. */
        JSVM_ARRAY_EXPECTED,                  /* An array is expected. */
        JSVM_GENERIC_FAILURE,                 /* Generic failure. */
        JSVM_PENDING_EXCEPTION,               /* Pending exception. */
        JSVM_CANCELLED,                       /* Canceled */
        JSVM_ESCAPE_CALLED_TWICE,             /* Escape is called twice. */
        JSVM_HANDLE_SCOPE_MISMATCH,           /* Handle scope does not match. */
        JSVM_CALLBACK_SCOPE_MISMATCH,         /* Callback scope does not match. */
        JSVM_QUEUE_FULL,                      /* The queue is full. */
        JSVM_CLOSING,                         /* Closing. */
        JSVM_BIGINT_EXPECTED,                 /* A Bigint value is expected. */
        JSVM_DATE_EXPECTED,                   /* A date is expected. */
        JSVM_ARRAYBUFFER_EXPECTED,            /* An ArrayBuffer is expected. */
        JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED, /* A detachable ArrayBuffer is expected. */
        JSVM_WOULD_DEADLOCK,                  /* About to deadlock. */
        JSVM_NO_EXTERNAL_BUFFERS_ALLOWED,     /* External buffers are not allowed. */
        JSVM_CANNOT_RUN_JS,                   /* JS cannot be executed. */
        JSVM_JIT_MODE_EXPECTD,                /* JIT mode is expected. */
    } JSVM_Status;
```

### JSVM_ExtendedErrorInfo

Defines a struct that represents detailed error information when a JSVM-API call fails.

```c++
typedef struct {
    const char* errorMessage;
    void* engineReserved;
    uint32_t engineErrorCode;
    JSVM_Status errorCode;
} JSVM_ExtendedErrorInfo;
```

### JSVM_Value

Defines a pointer to a JavaScript (JS) value.

### JSVM_Env

- Defines the context for the underlying JSVM-API implementation. It is passed to the JSVM-API interface in a native function as an input parameter.

- When the native addon exits, **JSVM_Env** becomes invalid and this event is passed to **OH_JSVM_SetInstanceData** via a callback.

- Avoid caching **JSVM_Env** or passing **JSVM_Env** between different worker threads.

- If **JSVM_Env** is shared between different threads, the **threadlocal** variable must be isolated across threads. For this purpose, close the env scope of the current thread before switching to another thread and open a new env scope in each thread switched to.

### JSVM_ValueType

Defines an enum for the **JSVM_Value** types. **JSVM_Value** includes the types defined in ECMAScript. **JSVM_EXTERNAL** indicates an external data type.

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

Defines an enum for data types of the **TypedArray** object.

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

Defines an enum for regular expression flags.

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

### Compilation Option Types
#### JSVM_CompileOptions

Defines a struct that represents the type of the elements in **options** of **OH_JSVM_CompileScriptWithOptions**.

The struct consists of the following parameters:
- **id**: identifies a compilation option.
- **content**: specifies a compilation option.

**id** and **content** together define a compilation option.

```c
typedef struct {
    /** Compilation option type. */
    JSVM_CompileOptionId id;
    /** Compilation option content. */
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

Defines an enum for **id** in **JSVM_CompileOptions**. Each **id** corresponds to a **content** value. The value **JSVM_COMPILE_ENABLE_SOURCE_MAP** corresponds to bool and is valid only when **sourceMapUrl** in **JSVM_ScriptOrigin** is not empty.

```c
typedef enum {
    /** Compilation mode. */
    JSVM_COMPILE_MODE,
    /** Code cache. */
    JSVM_COMPILE_CODE_CACHE,
    /** Script origin. */
    JSVM_COMPILE_SCRIPT_ORIGIN,
    /** Compilation profile. */
    JSVM_COMPILE_COMPILE_PROFILE,
    /** Switch for source map support. */
    JSVM_COMPILE_ENABLE_SOURCE_MAP,
} JSVM_CompileOptionId;
```

#### JSVM_CompileMode

Defines an enum for the compilation modes when **id** is **JSVM_COMPILE_MODE**.

- **JSVM_COMPILE_MODE_DEFAULT**: indicates the default compilation mode.
- **JSVM_COMPILE_MODE_CONSUME_CODE_CACHE**: indicates the compilation with the code cache.
- **JSVM_COMPILE_MODE_EAGER_COMPILE**: indicates full compilation.
- **JSVM_COMPILE_MODE_PRODUCE_COMPILE_PROFILE**/**JSVM_COMPILE_MODE_CONSUME_COMPILE_PROFILE**: reserved at present.

```c
typedef enum {
    /** Default mode. */
    JSVM_COMPILE_MODE_DEFAULT,
    /** Compilation by leveraging the code cache. */
    JSVM_COMPILE_MODE_CONSUME_CODE_CACHE,
    /** Full compilation. */
    JSVM_COMPILE_MODE_EAGER_COMPILE,
    /** Compilation with a preset compilation profile. */
    JSVM_COMPILE_MODE_PRODUCE_COMPILE_PROFILE,
    /** Compilation by using a compile profile. */
    JSVM_COMPILE_MODE_CONSUME_COMPILE_PROFILE,
} JSVM_CompileMode;
```


#### JSVM_CodeCache

Defines a struct that represents the code cache when **id** is **JSVM_COMPILE_CODE_CACHE**. The struct consists of the following:

- **cache**: pointer to the code cache to use.
- **length**: size of the code cache.

```c
typedef struct {
    /** cache pointer. */
    uint8_t *cache;
    /** length. */
    size_t length;
} JSVM_CodeCache;
```

#### JSVM_ScriptOrigin

Defines a struct that represents the source code of the script to compile when **id** is **JSVM_COMPILE_SCRIPT_ORIGIN**. The struct consists of the following:

- **sourceMapUrl**: path of the source map. Currently, only the local paths of the device are supported. This parameter can be left empty.
- **resourceName**: name of the JS script to be compiled.

```c
typedef struct {
    /** Source map URL. */
    const char* sourceMapUrl;
    /** Script to compile. */
    const char* resourceName;
    /** Line offset in the script. */
    size_t resourceLineOffset;
    /** Column offset in the script. */
    size_t resourceColumnOffset;
} JSVM_ScriptOrigin;
```

### JSVM
### Memory Management Types

JSVM-API provides the following memory management types:

**JSVM_HandleScope**

Data used to manage the lifecycle of JS objects. It allows JS objects to remain active within a certain range for use in JS code. When **JSVM_HandleScope** is created, all JS objects created in this range remain active until the end. This can prevent released objects from being used in JS code, which improves code reliability and performance.

**JSVM_EscapableHandleScope**

- It is created by **OH_JSVM_OpenEscapableHandleScope** and closed by **OH_JSVM_CloseEscapableHandleScope**.

- It is a special type of handle range used to return values created within the scope of **JSVM_EscapableHandleScope** to a parent scope.

- You can use **OH_JSVM_EscapeHandle** to promote **JSVM_EscapableHandleScope** to a JS object so that it is valid for the lifetime of the outer scope.

**JSVM_Ref**

Reference to **JSVM_Value**, which allows you to manage the lifecycle of JS values.

**JSVM_TypeTag**

Struct containing two unsigned 64-bit integers to identify the type of a JSVM-API value.

```c++
typedef struct {
    uint64_t lower;
    uint64_t upper;
} JSVM_TypeTag;
```

- It is a 128-bit value stored as two unsigned 64-bit integers. It is used to tag JS objects to ensure that they are of a certain type.

- This is a stronger check than **OH_JSVM_Instanceof** because **OH_JSVM_Instanceof** may report a false positive if the object's prototype is manipulated.

- The combination of **JSVM_TypeTag** and **OH_JSVM_Wrap** is useful because it ensures that the pointer retrieved from a wrapped object can be safely converted to the native type corresponding to the type tag that had been previously applied to the JS object.

### Callback Types

JSVM-API provides the following callback types:

**JSVM_CallbackStruct**

Callback function pointer and data for user-provided native callbacks, which are to be exposed to JS via JSVM-API. For example, you can use **OH_JSVM_CreateFunction** to create a JS function bound to a native callback defined by **JSVM_CallbackStruct**. Unless otherwise required in object lifecycle management, do not create a handle or callback scope in this callback.

```c++
typedef struct {
  JSVM_Value(*callback)(JSVM_Env env, JSVM_CallbackInfo info);
  void* data;
} JSVM_CallbackStruct;
```

**JSVM_Callback**

Alias of the **JSVM_CallbackStruct** pointer type.

It is defined as follows:

```c++
typedef JSVM_CallbackStruct* JSVM_Callback;
```

**JSVM_CallbackInfo**

User-defined native callback. The type of the first parameter is **JSVM_Env**, and that of the second parameter is **JSVM_CallbackInfo**. **JSVM_CallbackInfo** can be used to obtain additional information about the context in which the callback was invoked, for example, the parameter list. When a native callback is implemented, **OH_JSVM_GetCbInfo** is used to extract the invoking information from **JSVM_CallbackInfo**.

**JSVM_Finalize**

Function pointer, which is passed in APIs such as **OH_JSVM_SetInstanceData**, **OH_JSVM_CreateExternal**, and **OH_JSVM_Wrap**. **JSVM_Finalize** is called to release the native object when a JS object is garbage collected.

The format is as follows:

```c++
typedef void (*JSVM_Finalize)(JSVM_Env env, void* finalizeData, void* finalizeHint);
```

**JSVM_PropertyHandlerConfigurationStruct**

Callback to be invoked when the getter(), setter(), deleter(), or enumerator() of an object is executed.

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

Pointer to the struct that contains a callback for property listening.

The usage is as follows:

```c++
typedef JSVM_PropertyHandlerConfigurationStruct* JSVM_PropertyHandlerCfg;
```

## APIs

JSVM-API provides capabilities of the standard JS engine. JSVM-API can be dynamically linked to JS engine libraries of different versions to shield the differences between engine interfaces. JSVM-API provides capabilities, such as VM lifecycle management, JS context management, JS code execution, JS/C++ interaction, context snapshot management, and code caching. Read on the following for details.

### Creating a VM Instance and JS Context

#### When to Use

Before executing JS code, you need to create a avaScript virtual machine (JSVM) and JS context.

#### Available APIs
| API| Description|
| -------- | -------- |
| OH_JSVM_Init| Initializes a JS engine instance.|
| OH_JSVM_CreateVM| Creates a JSVM instance.|
| OH_JSVM_DestroyVM| Destroys a JSVM instance.|
| OH_JSVM_OpenVMScope| Opens a VM scope. The VM instance can be used only within the scope and will not be garbage-collected until the scope is closed.|
| OH_JSVM_CloseVMScope| Closes a VM scope.|
| OH_JSVM_CreateEnv| Creates a JS context and registers the specified native function.|
| OH_JSVM_DestroyEnv| Destroys a JS context.|
| OH_JSVM_OpenEnvScope| Opens a JS context scope. The context can be used only within the scope.|
| OH_JSVM_CloseEnvScope| Closes a JS context scope.|
| OH_JSVM_OpenHandleScope| Opens a handle scope. **JSVM_Value** within the scope will not be garbage-collected.|
| OH_JSVM_CloseHandleScope| Closes a handle scope.|

##### Using **JSVM_InitOptions**

JSVM provides multiple configuration options, allowing you to flexibly configure the behavior of **OH_JSVM_Init**. You can use the **OH_JSVM_GetVMInfo** API to obtain the V8 engine version corresponding to the current JSVM version. The options supported by the JSVM are the same as those supported by the corresponding V8 engine version. For details about how to use the **OH_JSVM_GetVMInfo** API, see [Obtaining the JSVM-API Version Using JSVM-API](use-jsvm-about-version.md).

**Note**: It is recommended that you use only the default configuration options in the JSVM.

Example:
Initialize a JSVM in normal mode.
```c++
static void NormalInit(bool &vmInit) {
    if (!vmInit) {
        // The JSVM only needs to be initialized once.
        JSVM_InitOptions initOptions;
        memset(&initOptions, 0, sizeof(initOptions));
        OH_JSVM_Init(&initOptions);
        vmInit = true;
    }
}
```

Example:
Initialize a JSVM with low memory usage.
```c++
static void LowMemoryInit(bool &vmInit) {
    if (!vmInit) {
        // The JSVM only needs to be initialized once.
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

Example:
Initialize a JSVM with a low GC triggering frequency.
```c++
static void LowGCFrequencyInit(bool &vmInit) {
    if (!vmInit) {
        // The JSVM only needs to be initialized once.
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

Execution result:
The preceding three interfaces can be used to initialize JSVMs with different capabilities. After initialization, a JSVM instance can be created to run JS scripts. Among the three interfaces:
Calling **LowGCFrequencyInit** allows for fewer GCs than calling **NormalInit**. Calling **LowMemoryInit** allows for less memory usage than calling **NormalInit**.

##### Creating a JSVM Instance

Example:
Create and destroy a JSVM instance (including the execution context).
```c++
bool VM_INIT = false;

static JSVM_Value ConsoleInfo(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1];
    char log[256] = "";
    size_t logLength;
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
    double num1, num2;
    env, OH_JSVM_GetValueDouble(env, args[0], &num1);
    OH_JSVM_GetValueDouble(env, args[1], &num2);
    JSVM_Value sum = nullptr;
    OH_JSVM_CreateDouble(env, num1 + num2, &sum);
    return sum;
}

static napi_value MyJSVMDemo([[maybe_unused]] napi_env _env, [[maybe_unused]] napi_callback_info _info) {
    std::thread t([]() {
        // Initialized a JSVM with the required capability based on service requirements.
        // 1. Call NormalInit to initialize the default JSVM.
        // 2. Call LowMemoryInit to initialize a JSVM with low memory usage.
        // 3. Call LowGCFrequencyInit to initialize a JSVM with a low GC triggering frequency.
        NormalInit(VM_INIT);
        // Create a VM instance and open the VM scope.
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
        // Create env, register a native method, and open an env scope.
        JSVM_Env env;
        OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);

        JSVM_EnvScope envScope;
        OH_JSVM_OpenEnvScope(env, &envScope);

        // Open a handle scope.
        JSVM_HandleScope handleScope;
        OH_JSVM_OpenHandleScope(env, &handleScope);

        std::string sourceCodeStr = "\
{\
let value = add(4.96, 5.28);\
consoleinfo('Result is:' + value);\
}\
";
        // Compile the JS script.
        JSVM_Value sourceCodeValue;
        OH_JSVM_CreateStringUtf8(env, sourceCodeStr.c_str(), sourceCodeStr.size(), &sourceCodeValue);
        JSVM_Script script;
        OH_JSVM_CompileScript(env, sourceCodeValue, nullptr, 0, true, nullptr, &script);
        JSVM_Value result;
        // Run the JS script.
        OH_JSVM_RunScript(env, script, &result);
        JSVM_ValueType type;
        OH_JSVM_Typeof(env, result, &type);
        OH_LOG_INFO(LOG_APP, "JSVM API TEST type: %{public}d", type);

        // Exit the VM and release the memory.
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

### Compiling and Running JS Code

#### When to Use

Compile and run JS code.

#### Available APIs
| API                             | Description                                                                              |
| ------------------------------- | ---------------------------------------------------------------------------------- |
| OH_JSVM_CompileScript           | Compiles JS code and returns the compiled script bound to the current environment.                                                     |
| OH_JSVM_CompileScriptWithOrigin | Compiles JS code and returns the compiled script bound to the current environment, with source code information including **sourceMapUrl** and source file name to process source map information.|
| OH_JSVM_CompileScriptWithOptions | Compiles a script with the specified options. You can pass the compilation options via the **option** array, which supports option extensions.|
| OH_JSVM_CreateCodeCache         | Creates a code cache for the compiled script.                                                                 |
| OH_JSVM_RunScript               | Runs a compile script.                                                                            |

Example:
Compile and run JS code (create a VM, register native functions, execute JS code, and destroy the VM).

CPP code:

```c++
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

// Add the dependency libjsvm.so.
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
    // Compile the JS code.
	JSVM_ScriptOrigin origin {
	    // In this example, the bundle name is helloworld, and the path of the source map is /data/app/el2/100/base/com.example.helloworld/files/index.js.map.
	    .sourceMapUrl = "/data/app/el2/100/base/com.example.helloworld/files/index.js.map",
	    // Name of the source file.
	    .resourceName = "index.js",
	    // Start row and column number of script in the source file
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
	// The default value of JSVM_COMPILE_ENABLE_SOURCE_MAP is false. If the value is true, sourceMapUrl cannot be empty.
	option[2] = {
		.id = JSVM_COMPILE_ENABLE_SOURCE_MAP,
		.content = { .boolean = true }
	};
	OH_JSVM_CompileScriptWithOptions(env, jsSrc, 3, option, &script);

    JSVM_Value result;
    // Run the JS code.
    OH_JSVM_RunScript(env, script, &result);

    char resultStr[128];
    size_t size;
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
    // Compile the JS code.
    if (withOrigin) {
	    JSVM_ScriptOrigin origin {
	        // In this example, the bundle name is helloworld, and the path of the source map is /data/app/el2/100/base/com.example.helloworld/files/index.js.map.
		    .sourceMapUrl = "/data/app/el2/100/base/com.example.helloworld/files/index.js.map",
		    // Name of the source file.
		    .resourceName = "index.js",
		    // Start row and column number of script in the source file
		    .resourceLineOffset = 0,
		    .resourceColumnOffset = 0,
	    };
		OH_JSVM_CompileScriptWithOrigin(env, jsSrc, data, length, true, &cacheRejected, &origin, &script);
    } else {
	    OH_JSVM_CompileScript(env, jsSrc, data, length, true, &cacheRejected, &script);
    }
    printf("Code cache is %s\n", cacheRejected ? "rejected" : "used");

    JSVM_Value result;
    // Run the JS code.
    OH_JSVM_RunScript(env, script, &result);

    char resultStr[128];
    size_t size;
    OH_JSVM_GetValueStringUtf8(env, result, resultStr, 128, &size);

    OH_JSVM_CloseHandleScope(env, handleScope);
}

void RunWithOption(uint8_t** dataPtr, size_t* lengthPtr) {
    // Create a VM instance.
    JSVM_VM vm;
    OH_JSVM_CreateVM(nullptr, &vm);
    JSVM_VMScope vmScope;
    OH_JSVM_OpenVMScope(vm, &vmScope);

    JSVM_Env env;
    // Register the native function as a method that can be called by a JS API. hello_cb holds the pointer and parameters of the native function.
    JSVM_PropertyDescriptor descriptors[] = {
        { "hello", NULL, &hello_cb, NULL, NULL, NULL, JSVM_DEFAULT }
    };
    OH_JSVM_CreateEnv(vm, 1, descriptors, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    // Execute the JS source code src, which can contain any JS syntax. The registered native function can also be invoked.
    auto src = srcGlobal + "concat(hello(), ', ', 'World', ' from RunWithOption!')";
    // Use RunScriptWithOption, which covers all the functionalities of the **Compile** APIs and provides extensions.
    RunScriptWithOption(env, src, dataPtr, lengthPtr);

    OH_JSVM_CloseEnvScope(env, envScope);
    OH_JSVM_DestroyEnv(env);
    OH_JSVM_CloseVMScope(vm, vmScope);
    OH_JSVM_DestroyVM(vm);

    bool result = true;
    OH_LOG_INFO(LOG_APP, "RunWithOption: success: %{public}d", result);
}

void RunWithOrigin(uint8_t **dataPtr, size_t *lengthPtr) {
    // Create a VM instance.
    JSVM_VM vm;
    JSVM_CreateVMOptions options;
    memset(&options, 0, sizeof(options));
    options.isForSnapshotting = true;
    OH_JSVM_CreateVM(&options, &vm);
    JSVM_VMScope vmScope;
    OH_JSVM_OpenVMScope(vm, &vmScope);

    // Create env from a snapshot.
    JSVM_Env env;
    // Register the native function as a method that can be called by a JS API. hello_cb holds the pointer and parameters of the native function.
    JSVM_PropertyDescriptor descriptors[] = {
        { "hello", NULL, &hello_cb, NULL, NULL, NULL, JSVM_DEFAULT }
    };
    OH_JSVM_CreateEnv(vm, 1, descriptors, &env);
    JSVM_EnvScope envScope;
    OH_JSVM_OpenEnvScope(env, &envScope);
    // Run the JS script. Because the snapshot contains hello() defined in env, you do not need to redefine hello(). If dataPtr contains the compiled JS script, the JS script can be directly executed, which avoids repeated compilation from the source code.
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

// Register the RunDemo callback.
static JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = RunDemo},
};
static JSVM_CallbackStruct *method = param;
// Alias for the RunDemo method to be called from JS.
static JSVM_PropertyDescriptor descriptor[] = {
    {"RunDemo", nullptr, method++, nullptr, nullptr, nullptr, JSVM_DEFAULT},
};

// Call C++ code from JS.
const char *srcCallNative = R"JS(RunDemo("WithOrigin"); RunDemo("WithOption"))JS";
```

Expected Result
```ts
RunWithOption: success: 1
RunWithOrigin: success: 1
```

For details about how to use the **OH_JSVM_CreateCodeCache** API, see [Accelerating Compilation Using a Code Cache](use-jsvm-about-code-cache.md).

### Compiling the Wasm Module

#### When to Use

JSVM-API provides APIs for compiling the WebAssembly (Wasm) bytecode, optimizing Wasm functions, and serializing and deserializing Wasm caches.
For details, see [Working with Wasm Using JSVM-API](use-jsvm-about-wasm.md).

#### Available APIs

| API                         | Description                                                                                |
| --------------------------- | ------------------------------------------------------------------------------------ |
| OH_JSVM_CompileWasmModule   | Compiles the Wasm bytecode into a Wasm module. If the **cache** parameter is passed in, the cache will be deserialized into a Wasm module first. The compilation is performed when the deserialization fails.|
| OH_JSVM_CompileWasmFunction | Compiles the function with the specified ID in a Wasm module into the optimized machine code. Currently, only the highest optimization level is enabled. The validity of the function ID is ensured by the caller.                    |
| OH_JSVM_IsWasmModuleObject  | Checks whether the input value is a Wasm module.                                                            |
| OH_JSVM_CreateWasmCache     | Serializes the machine code in a Wasm module into a Wasm cache. If the Wasm module does not contain machine code, the serialization will fail.                   |
| OH_JSVM_ReleaseCache        | Releases a Wasm cache instance created by JSVM-API. The **cacheType** and **cacheData** passed in must match. Otherwise, undefined behavior may occur.                     |

#### Example

For details, see [Working with Wasm Using JSVM-API](use-jsvm-about-wasm.md).

### Exception Handling

#### When to Use

Capture, throw, and clear JS exceptions as required.

#### Available APIs
| API| Description|
| -------- | -------- |
| OH_JSVM_Throw| Throws a JS value.|
| OH_JSVM_ThrowTypeError| Throws a JS type error.|
| OH_JSVM_ThrowRangeError| Throws a JS range error.|
| OH_JSVM_IsError| Checks whether a JS value indicates an error.|
| OH_JSVM_CreateError| Creates a JS error.|
| OH_JSVM_CreateTypeError| Creates a JS type error and returns it.|
| OH_JSVM_CreateRangeError| Creates a JS range error and returns it.|
| OH_JSVM_ThrowError| Throws a JS exception.|
| OH_JSVM_GetAndClearLastException| Obtains and clears the last JS exception.|
| OH_JSVM_IsExceptionPending| Checks whether an exception occurs.|
| OH_JSVM_GetLastErrorInfo| Obtains information about the last exception.|
| OH_JSVM_ThrowSyntaxError| Throws a JS syntax error.|
| OH_JSVM_CreateSyntaxError| Creates a JS syntax error and returns it.|

Example:
The following walks you through on how to create, judge, and throw a JS type error.

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

Call **OH_JSVM_GetAndClearLastException** to log the exception information as a string to the console.

```c++
if (status != JSVM_OK) // An exception occurs when the execution fails.
{
    bool isPending = false;
    if (JSVM_OK == OH_JSVM_IsExceptionPending((env), &isPending) && isPending)
    {
        JSVM_Value error;
        if (JSVM_OK == OH_JSVM_GetAndClearLastException((env), &error))
        {
            // Obtain the exception stack.
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

### Object Lifetime Management

When JSVM-API calls are made, handles to objects in the heap for the underlying VM may be returned as **JSVM_Value**s. These handles must hold the objects live until they are no longer required by the native code. Otherwise, the objects will be collected. 

 When an object handle is returned, it is associated with a scope. The lifecycle of the default scope is tied to the lifecycle of the native method call. By default, a handle remains valid and the object associated with it will be held live for the lifecycle of the native method call.

However, in many cases, you may need to adjust the lifecycle to be shorter or longer than that of the native method. The following describes the JSVM-API methods that can be used to change the lifecycle of a handle.

#### Available APIs
| API| Description|
| -------- | -------- |
| OH_JSVM_OpenHandleScope| Opens a handle scope. The object within the scope will not be garbage-collected until the handle scope is closed.|
| OH_JSVM_CloseHandleScope| Closes a handle scope. The object within the scope will be garbage-collected after the handle scope is closed.|
| OH_JSVM_OpenEscapableHandleScope| Opens an escapable handle scope. Before this scope is closed, the object created within the scope has the same lifecycle as its parent scope.|
| OH_JSVM_CloseEscapableHandleScope| Closes an escapable handle scope.|
| OH_JSVM_EscapeHandle| Promotes a handle to a JS object so that it is valid for the lifetime of the outer scope.|
| OH_JSVM_CreateReference| Creates a new reference with the specified reference count to the value passed in. The reference allows objects to be used and shared in different contexts and effectively monitors the lifecycle of the object.|
| OH_JSVM_DeleteReference| Release the reference created by **OH_JSVM_CreateReference**. This allows objects to be correctly released and reclaimed when they are no longer required, avoiding memory leaks.|
| OH_JSVM_ReferenceRef| Increments the reference count of the reference created by **OH_JSVM_CreateReference** so that the object referenced will not be released.|
| OH_JSVM_ReferenceUnref| Decrements the reference count of the reference created by **OH_JSVM_CreateReference** so that the object can be correctly released and reclaimed when it is not referenced.|
| OH_JSVM_GetReferenceValue| Obtains the object referenced by **OH_JSVM_CreateReference**.|
| OH_JSVM_RetainScript | Retains a **JSVM_Script** persistently so that it can be used out of the current scope.|
| OH_JSVM_ReleaseScript | Releases a **JSVM_Script** that is persistently retained. The released **JSVM_Script** will no longer be used and must be left empty.|

Example:
Use a handle scope to protect an object created within the scope from being reclaimed.

```c++
JSVM_HandleScope scope;
OH_JSVM_OpenHandleScope(env, &scope);
JSVM_Value obj = nullptr;
OH_JSVM_CreateObject(env, &obj);
OH_JSVM_CloseHandleScope(env, scope);
```

Use an escapable handle scope to protect an object from being reclaimed within its parent scope.

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

Reference a JS object and release the reference.

```c++
JSVM_Value obj = nullptr;
OH_JSVM_CreateObject(env, &obj);
// Create a reference.
JSVM_Ref reference;
OH_JSVM_CreateReference(env, obj, 1, &reference);

// Create a reference with a JS object.
JSVM_Value result;
OH_JSVM_GetReferenceValue(env, reference, &result);

// Release the reference.
OH_JSVM_DeleteReference(env, reference);
```

Use **RetainScript()** to persistently hold **JSVM_Script** and use it.

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

// Run a JSVM script.
OH_JSVM_OpenHandleScope(env, &scope);
JSVM_Value result;
OH_JSVM_RunScript(env, script, &result);

// Release a JSVM script and set it to null.
OH_JSVM_ReleaseScript(env, script);
script = nullptr;
OH_JSVM_CloseHandleScope(env, scope);
```

### Creating JS Object Types and Basic Types

#### When to Use

Create JS object types and basic types.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_CreateArray | Creates a JS array object.|
|OH_JSVM_CreateArrayWithLength | Creates a JS array object of the specified length.|
|OH_JSVM_CreateArraybuffer | Creates an **ArrayBuffer** object of the specified size.|
|OH_JSVM_CreateDate | Creates a date object representing the given number of milliseconds.|
|OH_JSVM_CreateExternal | Creates a JS object that wraps an external pointer.|
|OH_JSVM_CreateObject | Creates a default JS object.|
|OH_JSVM_CreateSymbol | Creates a symbol object based on the given descriptor.|
|OH_JSVM_SymbolFor | Searches for a symbol with the given key in a global (runtime-wide) symbol registry. If a match is found, the symbol will be returned. Otherwise, a symbol will be created in the registry.|
|OH_JSVM_CreateTypedarray | Creates a JS **TypedArray** object for an **ArrayBuffer**. The **TypedArray** object provides an array-like view over an underlying data buffer, where each element has the same underlying binary scalar data type.|
|OH_JSVM_CreateDataview | Creates a JS **DataView** object for an **ArrayBuffer**. The **DataView** object provides an array-like view of over an underlying data buffer.|
|OH_JSVM_CreateInt32 | Creates a JS number object from a C Int32_t object.|
|OH_JSVM_CreateUint32 | Creates a JS number object from a C Uint32_t object.|
|OH_JSVM_CreateInt64 | Creates a JS number object from a C Int64_t object.|
|OH_JSVM_CreateDouble | Creates a JS number object from a C Double object.|
|OH_JSVM_CreateBigintInt64 | Creates a JS BigInt object from a C Int64 object.|
|OH_JSVM_CreateBigintUint64 | Creates a JS BigInt object from a C Uint64 object.|
|OH_JSVM_CreateBigintWords | Creates a JS BigInt object from a C Uint64_t array.|
|OH_JSVM_CreateStringLatin1 | Creates a JS string object from an ISO-8859-1-encoded C string. ISO-8859-1 is also referred to as Latin-1.|
|OH_JSVM_CreateStringUtf16 | Creates a JS string object from a UTF16-encoded C string.|
|OH_JSVM_CreateStringUtf8 | Creates a JS string object from a UTF8-encoded C string.|
|OH_JSVM_CreateMap | Creates a JS **Map** object.|
|OH_JSVM_CreateRegExp | Creates a JS regular expression object based on the given string.|
|OH_JSVM_CreateSet | Creates a JS **Set** object.|

Example:
Create a JS array of the specified length.

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

Create a JS Int32Array.

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

Create JS numbers and strings.

```c++
const char *testStringStr = "test";
JSVM_Value testString = nullptr;
OH_JSVM_CreateStringUtf8(env, testStringStr, strlen(testStringStr), &testString);

JSVM_Value testNumber1 = nullptr;
JSVM_Value testNumber2 = nullptr;
OH_JSVM_CreateDouble(env, 10.1, &testNumber1);
OH_JSVM_CreateInt32(env, 10, &testNumber2);
```

Create a map.

```c++
JSVM_Value value = nullptr;
OH_JSVM_CreateMap(env, &value);
```

Create a regular expression.

```c++
JSVM_Value value = nullptr;
const char testStr[] = "ab+c";
OH_JSVM_CreateStringUtf8(env, testStr, strlen(testStr), &value);
JSVM_Value result = nullptr;
OH_JSVM_CreateRegExp(env, value, JSVM_RegExpFlags::JSVM_REGEXP_GLOBAL, &result);
```

Create a **set()** instance.

```c++
JSVM_Value value;
OH_JSVM_CreateSet(env, &value);
```

### Obtaining C Type and JS Type Information from JS Types

#### When to Use

Obtain C type and JS type information from JS types.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_GetArrayLength | Obtains the length of an array.|
|OH_JSVM_GetArraybufferInfo | Obtains the underlying data buffer of an **ArrayBuffer** and its length.|
|OH_JSVM_GetPrototype | Obtains the prototype of a JS object.|
|OH_JSVM_GetTypedarrayInfo | Obtains information about a **TypedArray** object.|
|OH_JSVM_GetDataviewInfo | Obtains information about a **DataView** object.|
|OH_JSVM_GetDateValue | Obtains the C double primitive of the time value for the given JS **Date** object.|
|OH_JSVM_GetValueBool | Obtains the C Boolean primitive equivalent of the given JS Boolean.|
|OH_JSVM_GetValueDouble | Obtains the C Double primitive equivalent of the given JS number.|
|OH_JSVM_GetValueBigintInt64 | Obtains the C Int64_t primitive equivalent of the given JS BigInt.|
|OH_JSVM_GetValueBigintUint64 | Obtains the C Uint64_t primitive equivalent of the given JS BigInt.|
|OH_JSVM_GetValueBigintWords | Obtains the underlying data of a given JS BigInt object, that is, the word representation of BigInt data.|
|OH_JSVM_GetValueExternal | Obtains the external data pointer previously passed to **OH_JSVM_CreateExternal**.|
|OH_JSVM_GetValueInt32 | Obtains the C Int32 primitive equivalent of the given JS number.|
|OH_JSVM_GetValueInt64 | Obtains the C Int64 primitive equivalent of the given JS number.|
|OH_JSVM_GetValueStringLatin1 | Obtains the ISO-8859-1-encoded string from the given JS string.|
|OH_JSVM_GetValueStringUtf8 | Obtains the UTF8-encoded string from the given JS string.|
|OH_JSVM_GetValueStringUtf16 | Obtains the UTF16-encoded string from the given JS string.|
|OH_JSVM_GetValueUint32 | Obtains the C primitive equivalent (a Uint32) of the given JS number.|
|OH_JSVM_GetBoolean | Obtains a JS singleton object that is used to represent the given Boolean value.|
|OH_JSVM_GetGlobal | Obtains the **global** object of the current environment.|
|OH_JSVM_GetNull | Obtains the JS **null** object.|
|OH_JSVM_GetUndefined | Obtains the JS **Undefined** object.|

Example:
Create a JS BigInt object from a C Int64 object and obtain the C Int64_t primitive equivalent.

```c++
int64_t testValue = INT64_MAX;
JSVM_Value result = nullptr;
OH_JSVM_CreateBigintInt64(env, testValue, &result);
int64_t resultValue = 0;
bool flag = false;
OH_JSVM_GetValueBigintInt64(env, result, &resultValue, &flag);
```

Create an Int32Array and obtain its information such as the length and byte offset.

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

Create a JavaScript string from a UTF-8-encoded C string, and obtain the UTF-8-encoded C string for the specified JavaScript string.

```c++
const char *testStringStr = "testString";
JSVM_Value testString = nullptr;
OH_JSVM_CreateStringUtf8(env, testStringStr, strlen(testStringStr), &testString);

char buffer[128];
size_t bufferSize = 128;
size_t copied;

OH_JSVM_GetValueStringUtf8(env, testString, buffer, bufferSize, &copied);
```

### Working with JS Values and Abstract Operations

#### When to Use

Perform abstract operations on JS values.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_CoerceToBool | Converts a JS value to an object of the Boolean type.|
|OH_JSVM_CoerceToNumber | Converts a JS value to an object of the number type.|
|OH_JSVM_CoerceToObject | Converts a JS value to an object of the object type.|
|OH_JSVM_CoerceToString | Converts a JS value to an object of the string type.|
|OH_JSVM_CoerceToBigInt | Converts a JS value to an object of the BigInt type.|
|OH_JSVM_Typeof | Returns the type of a JS object.|
|OH_JSVM_Instanceof | Checks whether an object is an instance of a constructor.|
|OH_JSVM_IsArray | Checks whether a JS object is an array.|
|OH_JSVM_IsArraybuffer | Checks whether a JS object is an array buffer.|
|OH_JSVM_IsDate | Checks whether a JS object is a **Date** object.|
|OH_JSVM_IsTypedarray | Checks whether a JS object is a **TypedArray** object.|
|OH_JSVM_IsDataview | Checks whether a JS object is a **DataView** object.|
|OH_JSVM_IsUndefined | Checks whether the value passed in is **Undefined**. This API is equivalent to executing JS code **value === undefined**.|
|OH_JSVM_IsNull | Checks whether the value passed in is a **Null** object. This API is equivalent to executing JS code **value === null**.|
|OH_JSVM_IsNullOrUndefined | Checks whether the value passed in is **Null** or **Undefined**. This API is equivalent to executing JS code **value == null**.|
|OH_JSVM_IsBoolean | Checks whether the value passed in is a Boolean value. This API is equivalent to executing JS code **typeof value ==='boolean'**.|
|OH_JSVM_IsNumber | Checks whether the value passed in is a number. This API is equivalent to executing JS code **typeof value === 'number'**.|
|OH_JSVM_IsString | Checks whether the value passed in is a string. This API is equivalent to executing JS code **typeof value === 'string'**.|
|OH_JSVM_IsSymbol | Checks whether the value passed in is a symbol. This API is equivalent to executing JS code **typeof value === 'symbol'**.|
|OH_JSVM_IsFunction | Checks whether the value passed in is a function. This API is equivalent to executing JS code **typeof value === 'function'**.|
|OH_JSVM_IsObject | Checks whether the value passed in is an object .|
|OH_JSVM_IsBigInt | Checks whether the value passed in is a BigInt. This API is equivalent to executing JS code **typeof value === 'bigint'**.|
|OH_JSVM_IsConstructor | Checks whether the value passed in is a constructor.|
|OH_JSVM_IsMap | Checks whether the value passed in is a map.|
|OH_JSVM_IsSet | Checks whether the value passed in is a **set()** instance.|
|OH_JSVM_IsRegExp | Checks whether the value passed in is a regular expression.|
|OH_JSVM_StrictEquals | Checks whether two **JSVM_Value** objects are strictly equal.|
|OH_JSVM_Equals | Checks whether two **JSVM_Value** objects are roughly equal.|
|OH_JSVM_DetachArraybuffer | Calls the **Detach()** operation of an **ArrayBuffer** object.|
|OH_JSVM_IsDetachedArraybuffer | Checks whether an **ArrayBuffer** object has been detached.|

Example:
Check whether a JS value is of the array type.

```c++
JSVM_Value array = nullptr;
OH_JSVM_CreateArray(env, &array);
bool isArray = false;
OH_JSVM_IsArray(env, array, &isArray);
```

Convert a JS int32 value to a string.

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

Convert a JS boolean value to a bigint.

```c++
JSVM_Value boolValue;
OH_JSVM_GetBoolean(env, false, &boolValue);
JSVM_Value bigIntValue;
OH_JSVM_CoerceToBigInt(env, boolValue, &bigIntValue);
```

Check whether two JS values are strictly equal as follows: Compare the operand types first. If the operand types are different, the values are different. If the operand types are the same, compare the two values. If the values are the same, **true** is returned.

```c++
JSVM_Value value = nullptr;
JSVM_Value value1 = nullptr;
OH_JSVM_CreateArray(env, &value);

OH_JSVM_CreateInt32(env, 10, &value1);
bool isArray = true;
OH_JSVM_StrictEquals(env, value, value, &isArray);
```

Check whether two JS values are roughly equal as follows: Compare the operand types first. If the operand types are different but can be converted to the same type, convert the operand types to the same type and check whether the values are strictly equal. If the values are the same, **true** is returned. **false** is returned in other cases.

```c++
JSVM_HandleScope handleScope;
OH_JSVM_OpenHandleScope(env, &handleScope);
const char testStr[] = "1";
JSVM_Value lhs = nullptr;
OH_JSVM_CreateStringUtf8(env, testStr, strlen(testStr), &lhs);
JSVM_Value rhs;
OH_JSVM_CreateInt32(env, 1, &rhs);
bool isEquals = false;
OH_JSVM_Equals(env, lhs, rhs, &isEquals); // The value of isEquals is true.
OH_JSVM_CloseHandleScope(env, handleScope);
```

Check whether the JS value is a constructor.

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
OH_JSVM_IsConstructor(env, value, &isConstructor); // The value of isConstructor is true.
```

Check whether the JS value is of the map type.

```c++
JSVM_Value value = nullptr;
OH_JSVM_CreateMap(env, &value);
bool isMap = false;
OH_JSVM_IsMap(env, value, &isMap); // The value of isMap is true.
```

Check whether the JS value is a **Set()** instance.

```c++
JSVM_Value value;
OH_JSVM_CreateSet(env, &value);
bool isSet = false;
OH_JSVM_IsSet(env, value, &isSet); // The value of isSet is true.
```

Check whether the JS value is a regular expression.

```c++
JSVM_Value value = nullptr;
const char testStr[] = "ab+c";
OH_JSVM_CreateStringUtf8(env, testStr, strlen(testStr), &value);
JSVM_Value result = nullptr;
OH_JSVM_CreateRegExp(env, value, JSVM_RegExpFlags::JSVM_REGEXP_GLOBAL, &result);
bool isRegExp = false;
OH_JSVM_IsRegExp(env, result, &isRegExp);
```

### Working with JS Properties

#### When to Use

Set, get, delete, and check properties of a JS object.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_GetPropertyNames | Obtains the names of all enumerable properties of a JS object as a JS array.|
|OH_JSVM_GetAllPropertyNames | Obtains the names of all available properties of a JS object as a JS array.|
|OH_JSVM_SetProperty | Sets a property for a JS object.|
|OH_JSVM_GetProperty | Obtains the requested property from a JS object.|
|OH_JSVM_HasProperty | Checks whether a JS object has the specified property.|
|OH_JSVM_DeleteProperty | Deletes a property from a JS object.|
|OH_JSVM_HasOwnProperty | Checks whether a JS object has the specified own property.|
|OH_JSVM_SetNamedProperty | Sets a property with the given property name for a JS object. This API is equivalent to calling **OH_JSVM_SetProperty** with a **JSVM_Value** created from the string passed in as **utf8Name**.|
|OH_JSVM_GetNamedProperty | Obtains the property from a JS object with the given property name. This API is equivalent to calling **OH_JSVM_GetProperty** with a **JSVM_Value** created from the string passed in as **utf8Name**.|
|OH_JSVM_HasNamedProperty | Checks whether a JS object has the specified property. This API is equivalent to calling **OH_JSVM_HasProperty** using a **JSVM_Value** created from the string passed in as **utf8Name**.|
|OH_JSVM_SetElement | Sets an element at the specified index for a JS object.|
|OH_JSVM_GetElement | Obtains the element at the specified index of a JS object.|
|OH_JSVM_HasElement | Checks whether a JS object has an element at the specified index.|
|OH_JSVM_DeleteElement | Deletes the element at the specified index from a JS object.|
|OH_JSVM_DefineProperties |  Defines multiple properties for a JS object.|
|OH_JSVM_ObjectFreeze | Freeze a JS object. Once a JS object is frozen, new properties cannot be added to it, existing properties cannot be removed, the enumerability, configurability, or writability of existing properties cannot be changed, and the values of existing properties cannot be changed.|
|OH_JSVM_ObjectSeal | Seals a JS object. Once a JS object is sealed, new properties cannot be added to it and all existing properties are marked as unconfigurable.|
|OH_JSVM_ObjectSetPrototypeOf | Sets a prototype for a given object.|
|OH_JSVM_ObjectGetPrototypeOf | Obtains the prototype of a JS object.|

Example:
Set, get, delete, and check properties of a JS object.

```c++
// Create an empty object.
JSVM_Value myObject = nullptr;
OH_JSVM_CreateObject(env, &myObject);

// Set properties.
const char *testNameStr = "John Doe";
JSVM_Value propValue = nullptr;
JSVM_Value key;
OH_JSVM_CreateStringUtf8(env, "name", JSVM_AUTO_LENGTH, &key);
OH_JSVM_CreateStringUtf8(env, testNameStr, strlen(testNameStr), &propValue);
OH_JSVM_SetProperty(env, myObject, key, propValue);

// Obtain properties.
JSVM_Value propResult = nullptr;
OH_JSVM_GetProperty(env, myObject, key, &propResult);

// Check whether a property exists.
bool hasProperty = false;
OH_JSVM_HasNamedProperty(env, myObject, "name", &hasProperty);
    // The property exists. Perform subsequent processing accordingly.
    if (hasProperty)
    {
        // Obtain all property names of the object.
        JSVM_Value propNames = nullptr;
        OH_JSVM_GetPropertyNames(env, myObject, &propNames);

        bool isArray = false;
        OH_JSVM_IsArray(env, propNames, &isArray);

        uint32_t arrayLength = 0;
        OH_JSVM_GetArrayLength(env, propNames, &arrayLength);
        // Traverse property elements.
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

// Delete a property.
OH_JSVM_DeleteProperty(env, myObject, key, &hasProperty);

// Set the object prototype.
JSVM_Value value;
OH_JSVM_CreateSet(env, &value);
OH_JSVM_ObjectSetPrototypeOf(env, myObject, value);

// Obtain the object prototype.
JSVM_Value proto;
OH_JSVM_ObjectGetPrototypeOf(env, myObject, &proto);
```

### Working with JS Functions

#### When to Use

Call back JS code into native code and call JS functions from native code.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_CallFunction | Calls a JS function from a C/C++ addon.|
|OH_JSVM_CreateFunction | Creates a JS function object in native code, which allows calling into the native code from JS.|
|OH_JSVM_GetCbInfo | Obtains detailed information about the call, such as the parameters and **this** pointer, from the given callback information.|
|OH_JSVM_GetNewTarget | Obtains the **new.target** of the constructor call.|
|OH_JSVM_NewInstance | Creates an instance based on the given constructor.|
|OH_JSVM_CreateFunctionWithScript | Creates a JS function object based on the given function body and parameter list.|

Example:
Create a JS function.

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

Obtain and call the JS function from C/C++.

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

Create a function.

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

### Wrapping Objects

#### When to Use

Wrap native classes and instances so that the class constructor and methods can be called from JS.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_DefineClass| Defines a JS class and associated functions within a C/C++ addon. It allows you to define a constructor, methods, and properties that can be accessed from JS.|
|OH_JSVM_Wrap| Wraps a native instance in a JS object. You can use **OH_JSVM_Unwrap()** to retrieve the native instance later.|
|OH_JSVM_Unwrap | Retrieves a native instance from a JS object.|
|OH_JSVM_RemoveWrap | Retrieves a native instance previously wrapped in a JS object and removes the wrapping.|
|OH_JSVM_TypeTagObject | Associates the value of the **type_tag** pointer with a JS object or an external object.|
|OH_JSVM_CheckObjectTypeTag | Checks whether a tag matches the tag type of an object. |
|OH_JSVM_AddFinalizer | Adds a **JSVM_Finalize** callback to a JS object. The callback will be invoked to release the native object when the JS object is garbage-collected. |
|OH_JSVM_DefineClassWithPropertyHandler | Defines a JS class with the given class name, constructor, property, and callback handler, and calls it as a function callback. The property operations include getter, setter, deleter, and enumerator.|
|OH_JSVM_DefineClassWithOptions | Defines a JS class with the given class name, constructor, properties, callback handler, and parent class. The **DefineClassOptions** parameter specifies whether to set a property proxy for the defined class, reserve the internal-field slot, and set a callback when the class is called as a function.|

Example:
Wrap a native object in a JS object.

```c++
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

Example:
Wrap a native object and register a listener for property access operations.

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
    // This callback is triggered by the getter of the object.
    char strValue[100];
    size_t size;
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
    // This callback is triggered by the setter of the object.
    char strValue[100];
    size_t size;
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
    // This callback is triggered by the deleter of the object.
    char strValue[100];
    size_t size;
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
    // This callback is triggered by the enumerator of an object.
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
    // This callback is triggered by the indexed getter.
    uint32_t value;
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
    // This callback is triggered by the indexed setter.
    uint32_t value;
    OH_JSVM_GetValueUint32(env, index, &value);
    char str[100];
    size_t size;
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
    // This callback is triggered by the indexed deleter.
    uint32_t value;
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
    // This callback is triggered by the indexed enumerator.
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

    // Initialize propertyCfg.
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

    // Register a property access listener in propertyCfg.
    OH_JSVM_DefineClassWithPropertyHandler(env, "TestWrapClass", NAPI_AUTO_LENGTH, &param1, 0, nullptr, &propertyCfg,
                                           &callbackStruct, &testWrapClass);
    JSVM_Value instanceValue = nullptr;
    OH_JSVM_NewInstance(env, testWrapClass, 0, nullptr, &instanceValue);
    const char testStr[] = "hello world";
    JSVM_Value setvalueName = nullptr;
    OH_JSVM_CreateStringUtf8(env, testStr, strlen(testStr), &setvalueName);

    // 1. Callbacks for properties.
    // Set properties.
    OH_JSVM_SetNamedProperty(env, instanceValue, "str11", setvalueName);
    OH_JSVM_SetNamedProperty(env, instanceValue, "str123", setvalueName);

    // Obtain a property.
    JSVM_Value valueName = nullptr;
    OH_JSVM_GetNamedProperty(env, instanceValue, "str11", &valueName);
    char str[100];
    size_t size;
    OH_JSVM_GetValueStringUtf8(env, valueName, str, 100, &size);

    // Obtain all property names.
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
        size_t size;
        OH_JSVM_GetValueStringUtf8(env, propertyName, str, 100, &size);
    }

    // Delete a property.
    bool result = false;
    propertyName = nullptr;
    char propertyChar[] = "str11";
    OH_JSVM_CreateStringUtf8(env, propertyChar, strlen(propertyChar), &propertyName);
    OH_JSVM_DeleteProperty(env, instanceValue, propertyName, &result);

    // 2. Callbacks for index properties.
    // Set properties.
    JSVM_Value jsIndex = nullptr;
    uint32_t index = 0;
    OH_JSVM_CreateUint32(env, index, &jsIndex);
    OH_JSVM_SetProperty(env, instanceValue, jsIndex, setvalueName);
    JSVM_Value jsIndex1 = nullptr;
    index = 1;
    OH_JSVM_CreateUint32(env, index, &jsIndex1);
    OH_JSVM_SetProperty(env, instanceValue, jsIndex1, setvalueName);

    // Obtain a property.
    JSVM_Value valueName1 = nullptr;
    OH_JSVM_GetProperty(env, instanceValue, jsIndex, &valueName1);
    char str1[100];
    size_t size1;
    OH_JSVM_GetValueStringUtf8(env, valueName1, str1, 100, &size1);

    // Obtain all property names.
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
        size_t size;
        OH_JSVM_GetValueStringUtf8(env, propertyName1, str, 100, &size);
    }

    // Delete a property.
    bool result1 = false;
    OH_JSVM_DeleteProperty(env, instanceValue, jsIndex, &result1);

    // 3. Callback of a function.
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
Scenario: Set a parent class and register a listener for property access operations.

For details, see [Working with Classes Using JSVM-API](use-jsvm-about-class.md).

### Version Management

#### When to Use

Obtain version information.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_GetVersion| Obtains the latest JSVM API version supported by the JSVM runtime.|
|OH_JSVM_GetVMInfo| Obtains the VM information.|

Example:
Obtain version information.

```c++
JSVM_VMInfo result;
OH_JSVM_GetVMInfo(&result);
uint32_t versionId = 0;
OH_JSVM_GetVersion(env, &versionId);
```

### Memory Management

#### When to Use

Perform memory management. 

#### Available APIs
| API                                         | Description                                                                                                  |
| ------------------------------------------- | ------------------------------------------------------------------------------------------------------ |
| OH_JSVM_AdjustExternalMemory                | Adjusts the amount of registered external memory used to give the JSVM an indication of the amount of externally allocated memory that is kept alive by JS objects. The JSVM then determines whether to perform global GC. Increasing the externally allocated memory will increase the probability of triggering global.|
| OH_JSVM_MemoryPressureNotification          | Notifies the VM of the memory pressure level and selectively triggers GC.                                                                            |
| OH_JSVM_AllocateArrayBufferBackingStoreData | Allocates memory for a backing store.|
| OH_JSVM_FreeArrayBufferBackingStoreData | Releases the backing store memory.|
| OH_JSVM_CreateArrayBufferFromBackingStoreData | Creates an array buffer based on the backing store memory allocated.|

> Using a backing store is a critical operation. You must ensure correct use of memory and exercise caution when using it. For details, see the following example.

Example:
Perform memory management. 

```c++
// Before and after calling OH_JSVM_AdjustExternalMemory, check the memory allocated externally from the perspective of the underlying VM.
int64_t result;
OH_JSVM_AdjustExternalMemory(env, 0, &result); // The externally allocated memory remains unchanged.
OH_LOG_INFO(LOG_APP, "Before AdjustExternalMemory: %{public}lld\n", result); // Obtain the memory value before the adjustment.
// Increase the memory usage and notify the VM of the change.
int64_t memoryIncrease = 1024 * 1024; // Increase the memory by 1 MB.
OH_JSVM_AdjustExternalMemory(env, memoryIncrease, &result);
OH_LOG_INFO(LOG_APP, "After AdjustExternalMemory: %{public}lld\n", result); // Obtain the memory value after the adjustment.
```
```c++
// Open a handle scope and apply for a large amount of memory within the scope to test the function.
// Check the memory status after the memory is allocated, after the scope is closed, and after OH_JSVM_MemoryPressureNotification is called.
JSVM_HandleScope tmpscope;
OH_JSVM_OpenHandleScope(env, &tmpscope);
for (int i = 0; i < 1000000; ++i) {
    JSVM_Value obj;
    OH_JSVM_CreateObject(env, &obj);
}
JSVM_HeapStatistics mem;
OH_JSVM_GetHeapStatistics(vm, &mem); // Obtain the heap statistics of the VM.
OH_LOG_INFO(LOG_APP, " %{public}zu\n", mem.usedHeapSize); // After the requested memory is allocated, the memory is of the maximum size.
OH_JSVM_CloseHandleScope (env, tmpscope); // Close the handle scope.

OH_JSVM_GetHeapStatistics(vm, &mem);
OH_LOG_INFO(LOG_APP, " %{public}zu\n", mem.usedHeapSize); // After the scope is closed, GC is not performed immediately.

// Notify the VM of the memory pressure level and selectively trigger GC.
OH_JSVM_MemoryPressureNotification(env, JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL); // The memory pressure is in the critical state.

OH_JSVM_GetHeapStatistics(vm, &mem);
OH_LOG_INFO(LOG_APP, " %{public}zu\n", mem.usedHeapSize); // After GC is triggered.
```

Example
``` c++
void *backingStore;
JSVM_Value arrayBuffer;

// Allocate memory of 100 bytes for a backing store.
OH_JSVM_AllocateArrayBufferBackingStoreData(100, JSVM_ZERO_INITIALIZED, &backingStore);

// In the allocated memory, create an ArrayBuffer of 20 bytes at 30 bytes away from the start address of the backing store.
OH_JSVM_CreateArrayBufferFromBackingStoreData(env, backingStore, 100, 30, 20, &arrayBuffer);

// Use the created ArrayBuffer in JS.
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

// Check the ArrayBuffer content.
uint8_t *array = static_cast<uint8_t*>(backingStore);
for (auto i = 0; i < 100; ++i) {
  if (array[i] != i % 25 % 256) {
    return false;
  }
}

// Release the ArrayBuffer. Before releasing the backing store, you must
// call OH_JSVM_DetachArraybuffer to release all ArrayBuffers created in the backing store.
// Otherwise, unpredictable memory problems may occur.
OH_JSVM_DetachArraybuffer(env, arrayBuffer);

// Release the memory allocated for the backing store.
OH_JSVM_FreeArrayBufferBackingStoreData(backingStore);
```
### Promises

#### When to Use

Perform operations related to promises.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_CreatePromise| Creates a **deferred** object and a JS promise.|
|OH_JSVM_ResolveDeferred| Resolves a JS promise by using the **deferred** object associated with it.|
|OH_JSVM_RejectDeferred| Rejects a JS promise by using the **deferred** object associated with it.|
|OH_JSVM_IsPromise| Checks whether a promise object is a native promise object.|

Example:
Perform operations related to promises.

```c++
JSVM_Deferred deferred;
JSVM_Value promise;
OH_JSVM_CreatePromise(env, &deferred, &promise);

// Perform an asynchronous operation.
int result = 42;
bool success = true;
if (success)
{
    // Resolve the promise and pass the result.
    JSVM_Value value;
    OH_JSVM_CreateInt32(env, result, &value);
    OH_JSVM_ResolveDeferred(env, deferred, value);
} else {
    // Reject the promise and pass the error information.
    JSVM_Value code = nullptr;
    JSVM_Value message = nullptr;
    OH_JSVM_CreateStringUtf8(env, "600", JSVM_AUTO_LENGTH, &code);
    OH_JSVM_CreateStringUtf8(env, "Async operation failed", JSVM_AUTO_LENGTH, &message);
    JSVM_Value error = nullptr;
    OH_JSVM_CreateError(env, code, message, &error);
    OH_JSVM_RejectDeferred(env, deferred, error);
}
```

### JSON Operations

#### When to Use

Perform JSON operations.

#### Available APIs

| API| Description|
| -------- | -------- |
|OH_JSVM_JsonParse| Parses a JSON string and returns the parsed value.|
|OH_JSVM_JsonStringify| Converts a JS object into a JSON string and returns the converted string.|

Example:
Parse JSON strings.

```c++
std::string sourcecodestr = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}" ;
JSVM_Value jsonString;
OH_JSVM_CreateStringUtf8(env, sourcecodestr.c_str(), sourcecodestr.size(), &jsonString)
JSVM_Value result;
OH_JSVM_JsonParse(env, jsonString, &result);
```

### Creating and Using a VM Startup Snapshot

#### When to Use

Create and use a VM startup snapshot.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_CreateSnapshot| Creates a VM startup snapshot.|
|OH_JSVM_CreateEnvFromSnapshot| Creates a JSVM environment from a startup snapshot.|

Example:

See [Working with VM Snapshots Using JSVM-API](use-jsvm-create-snapshot.md).

### Checking Input Parameters

#### When to Use

Check whether the input parameters are callable.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_IsCallable| Checks whether the input parameters are callable. |

Example:

Check whether input parameters are callable.

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
        // Create a VM instance and open the VM scope.
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
        // Create env, register a native method, and open an env scope.
        JSVM_Env env;
        OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
        JSVM_EnvScope envScope;
        OH_JSVM_OpenEnvScope(env, &envScope);
        // Open a handle scope.
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
        // Compile the JS script.
        JSVM_Value sourceCodeValue;
        OH_JSVM_CreateStringUtf8(env, sourceCodeStr.c_str(), sourceCodeStr.size(), &sourceCodeValue);
        JSVM_Script script;
        OH_JSVM_CompileScript(env, sourceCodeValue, nullptr, 0, true, nullptr, &script);
        JSVM_Value result;
        // Run the JS script.
        OH_JSVM_RunScript(env, script, &result);
        JSVM_ValueType type;
        OH_JSVM_Typeof(env, result, &type);
        OH_LOG_INFO(LOG_APP, "JSVM API TEST type: %{public}d", type);
        // Exit the VM and release the memory.
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

### Lock Operations

#### When to Use

Perform lock operations.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_IsLocked| Checks whether the current thread holds a lock of the specified environment.|
|OH_JSVM_AcquireLock| Obtains a lock.|
|OH_JSVM_ReleaseLock| Releases a lock.|

Example:
Obtain and release a lock.

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
        int32_t num1;
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
        int32_t num1;
        OH_JSVM_GetValueInt32(env, value, &num1);
        OH_LOG_INFO(LOG_APP, "JSVM:t2 num1 = %{public}d", num1);
        OH_JSVM_CloseHandleScope(env, handleScope);
    });
    t1.detach();
    t2.detach();
    return nullptr;
}
```

### Setting and Obtaining Data Associated with a JSVM Instance

#### When to Use

Use the **OH_JSVM_SetInstanceData()** function to set data to be associated with a JSVM instance.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_SetInstanceData| Sets data to be associated with a JSVM instance.|
|OH_JSVM_GetInstanceData| Obtains the data associated with a JSVM instance.|

Example:
Set and obtain the data associated with a JSVM instance.

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

// Initialize the VM and create a JSVM instance.
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

// Exit the VM and release the running environment.
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

// Clear and release the memory used by the instance.
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
    // Obtain the callback function parameters.
    napi_get_cb_info(env1, info, &argc, args , nullptr, nullptr);
    napi_valuetype valuetype0;
    napi_typeof(env1, args[0], &valuetype0);
    int32_t tmp = 0;
    napi_get_value_int32(env1, args[0], &tmp);
    instanceData->value = tmp;
    // Associate the obtained parameters with the current JSVM environment.
    OH_JSVM_SetInstanceData(env, instanceData, InstanceFinalizeCallback, nullptr);
    InstanceData *resData = nullptr;
    // Obtain the data associated with the JSVM instance.
    OH_JSVM_GetInstanceData(env, (void **)&resData);
    napi_value result;
    napi_create_uint32(env1, resData->value, &result);
    return result;
}
```

### Task Queue

#### When to Use

Start the running of a task queue in a JSVM and check whether there are micro tasks waiting in the queue. The task queue can be executed cyclically by external events.

#### Available APIs
| API| Description|
| -------- | -------- |
|OH_JSVM_PumpMessageLoop| Starts running a task queue.|
|OH_JSVM_PerformMicrotaskCheckpoint| Executes micro tasks in a task queue.|

Example:
See [Working with Task Queues Using JSVM-API](use-jsvm-execute_tasks.md).