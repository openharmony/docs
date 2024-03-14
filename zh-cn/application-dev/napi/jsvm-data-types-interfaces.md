# JSVM-API支持的数据类型和接口

## JSVM-API的数据类型

### JSVM_Status

是一个枚举数据类型，表示JSVM-API接口返回的状态信息。

每当调用一个JSVM-API函数，都会返回该值，表示操作成功与否的相关信息。

```c++
typedef enum {
    JSVM_OK,
    JSVM_INVALID_ARG,
    JSVM_OBJECT_EXPECTED,
    JSVM_STRING_EXPECTED,
    JSVM_NAME_EXPECTED,
    JSVM_FUNCTION_EXPECTED,
    JSVM_NUMBER_EXPECTED,
    JSVM_BOOL_EXPECTED,
    JSVM_ARRAY_EXPECTED,
    JSVM_GENERIC_FAILURE,
    JSVM_PENDING_EXCEPTION,
    JSVM_CENCELLED,
    JSVM_ESCAPE_CALLED_TWICE,
    JSVM_HANDLE_SCOPE_MISMATCH,
    JSVM_CALLBACK_SCOPE_MISMATCH,
    JSVM_QUEUE_FULL,
    JSVM_CLOSING,
    JSVM_BIGINT_EXPECTED,
    JSVM_DATA_EXPECTED,
    JSVM_CALLBACK_SCOPE_MISMATCH,
    JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED,
    JSVM_WOULD_DEADLOCK,  /* unused */
    JSVM_NO_EXTERNAL_BUFFERS_ALLOWED,
    JSVM_CANNOT_RUN_JS
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

在C++代码中，表示一个JavaScript值。

### JSVM_Env

- 用于表示JSVM-API执行时的上下文，Native侧函数入参，并传递给函数中的JSVM-API接口。

- 退出Native侧插件时，JSVM_Env将变为无效。关于此事件的通知通过传递给OH_JSVM_SetInstanceData的回调函数进行传递。

- 禁止缓存JSVM_Env，禁止在不同Worker中传递JSVM_Env。

### JSVM_ValueType

描述JSVM_Value的类型。这通常对应于ECMAScript语言规范第6.1节中描述的类型。除了该部分中的类型外，JSVM_ValueType还可以用外部数据表示函数和对象。

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

这表示TypedArray的基本二进制标量数据类型。此枚举的元素对应于ECMAScript语言规范的第22.2节。

```c++
typedef enum {
    JSVM_INT8_ARRAY,
    JSVM_UINT8_ARRAY,
    JSVM_UINT8_CLAMPED_ARRAY,
    JSVM_INT16_ARRAY,
    JAVM_UINT16_ARRAY,
    JSVM_INT32_ARRAY,
    JSVM_UINT32_ARRAY,
    JSVM_FLOAT32_ARRAY,
    JSVM_FLOAT64_ARRAY,
    JSVM_BIGINT64_ARRAY,
    JSVM_BIGUINT64_ARRAY,
} JSVM_TypedarrayType;
```

### 内存管理类型

JSVM-API包含以下内存管理类型：

**JSVM_HandleScope**

JSVM_HandleScope数据类型是用来管理JavaScript对象的生命周期的。由OH_JSVM_OpenHandleScope接口创建，由OH_JSVM_CloseHandleScope接口关闭。它允许JavaScript对象在一定范围内保持活动状态，以便在JavaScript代码中使用。在创建JSVM_HandleScope时，所有在该范围内创建的JavaScript对象都会保持活动状态，直到结束。这样可以避免在JavaScript代码中使用已经被释放的对象，从而提高代码的可靠性和性能。

**JSVM_EscapableHandleScope**

- 由OH_JSVM_OpenEscapableHandleScope接口创建，由OH_JSVM_CloseEscapableHandleScope接口关闭。

- 表示一种特殊类型的句柄范围，用于将在escapable_handle_scope范围内创建的值返回给父scope。

- 用于OH_JSVM_EscapeHandle接口，将escape_handle_scope提升到JavaScript对象，以便在外部作用域使用。

**JSVM_Ref**

这是指向JSVM_Value的指针。这允许用户管理JavaScript值的生存期，包括明确定义它们的最小生存期。

**JSVM_TypeTag**

该结构体定义了一个包含两个无符号64位整数的类型标签，用于标识一个JSVM-API值的类型信息。

```c++
typedef struct {
    uint64_t lower;
    uint64_t upper;
} JSVM_TypeTag;
```

- 存储了两个无符号64位整数的128位值，用它来标记JavaScript对象，确保它们属于某种类型。

- 比OH_JSVM_Instanceof更强的类型检查，如果对象的原型被操纵，OH_JSVM_Instanceof可能会报告误报。

- type_tag与OH_JSVM_Wrap结合非常有用，因为它确保从包装对象检索的指针可以安全地转换为与先前应用于JavaScript对象的类型标记相对应的Native类型。

### 回调类型

JSVM-API包含以下回调类型：

**JSVM_CallbackInfo**

Native侧获取JS侧参数信息，传递给OH_JSVM_GetCbInfo，用于获取JS侧入参信息。

**JSVM_CallbackStruct**

用户提供的Native函数的回调函数指针和数据，这些函数将通过JSVM-API暴露给JavaScript。

```c++
typedef struct {
  JSVM_Value(*callback)(JSVM_Env env, JSVM_CallbackInfo info);
  void* data;
} JSVM_CallbackStruct;
```

**JSVM_Callback**

表示用户定义的Native函数，暴露给JavaScript，即JS侧调用的接口；除非在对象生命周期管理中有特殊要求，一般不在此callback中创建handle或者callback scope。

基本用法如下:

```c++
typedef JSVM_CallbackStruct* JSVM_Callback;
```

**JSVM_Finalize**

函数指针，用于传入OH_JSVM_SetInstanceData、OH_JSVM_CreateExternal、OH_JSVM_Wrap等接口。JSVM_Finalize在对象被回收时会被调用，可用于在JavaScript对象被垃圾回收时释放本机实例。

JSVM_Finalize可以用于确定何时回收具有外部数据的对象。
写法如下：

```c++
typedef void (JSVM_Finalize)(JSVM_Env env, void finalizeData, void* finalizeHint);
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

场景示例:
创建及销毁JavaScript引擎实例，包含创建及销毁JS执行上下文环境

```c++
static JSVM_Value test(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 2;
    JSVM_Value args[2];
    JSVM_CALL(env, OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

    bool isStrictEquals = false;
    OH_JSVM_StrictEquals(env, args[0], args[1], &isStrictEquals);
    return nullptr;
}

OH_JSVM_Init(nullptr);

JSVM_CreateVMOptions options;
memset(&options, 0, sizeof(options));

JSVM_VM vm;
OH_JSVM_CreateVM(&options, &vm);

JSVM_VM_Scope vmScope;
OH_JSVM_OpenVMScope(vm, &vmScope);

JSVM_Env env;
JSVM_CallbackStruct param[1];
param[0].data = nullptr;
param[0].callback = test;
JSVM_PropertyDescriptor descriptor[] = {
    {"test", NULL, &param[0], NULL, NULL, NULL, JSVM_DEFAULT},
};
OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
JSVM_EnvScope envScope;
OH_JSVM_OpenEnvScope(env, &envScope);

JSVM_HandleScope handleScope;
OH_JSVM_OpenHandleScope(env, &handleScope);

// 业务代码
... ...

OH_JSVM_CloseHandleScope(env, handleScope);

OH_JSVM_CloseEnvScope(env, envScope);
OH_JSVM_DestroyEnv(env);

OH_JSVM_CloseVMScope(vm, vmScope);
OH_JSVM_DestroyVM(vm);
```

### 使用 JSVM-API 接口编译及执行 JS 代码

#### 场景介绍

编译及执行JS代码。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
| OH_JSVM_CompileScript| 编译JavaScript代码并返回绑定到当前环境的编译脚本 |
| OH_JSVM_CreateCodeCache| 为编译脚本创建code cache|
| OH_JSVM_RunScript| 执行编译脚本 |

场景示例：
编译及执行JS代码

```c++
char* sourcecodestr = "let length = 5; let arr = new Array(length); arr[4] = 123;";
JSVM_Value sourcecodevalue;
OH_JSVM_CreateStringUtf8(env, sourcecodestr.c_str(), sourcecodestr.size(), &sourcecodevalue);

JSVM_Script script;
OH_JSVM_CompileScript(env, sourcecodevalue, nullptr, 0, true, 0, &script);
JSVM_Value result;
OH_JSVM_RunScript(env, script, &result);
int32_t runScriptResult;
OH_JSVM_GetValueInt32(env, result, &runScriptResult); // runScriptResult: 123
```

### 异常处理

#### 场景介绍

获取、抛出、清理JS异常

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
以TypeError为例。创建，判断，并抛出JS TypeError

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
if (status != JSVM_OK)
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

### 对象生命周期管理。

在进行JSVM-API调用时，底层VM的堆中对象的句柄可以作为JSVM_Values返回。这些句柄必须保持对象处于“活动”状态，直到本机代码不再需要它们为止，否则可能会在本机代码使用完对象之前收集这些对象。当对象句柄被返回时，它们与一个“scope”相关联。默认作用域的寿命与本机方法调用的寿命相关联。结果是，默认情况下，句柄保持有效，并且与这些句柄关联的对象将在本机方法调用的生命周期内保持活动状态。然而，在许多情况下，句柄必须在比本机方法更短或更长的寿命内保持有效。下面的部分介绍了JSVM-API函数，这些函数可用于从默认值更改句柄的使用寿命。

#### 对象生命周期管理接口说明
| 接口 | 功能说明 |
| -------- | -------- |
| OH_JSVM_OpenHandleScope| 打开一个新的scope，在关闭该scope之前创建的对象在scope范围内不会被GC回收 |
| OH_JSVM_CloseHandleScope| 关闭一个scope，在此scope范围内创建的对象在关闭scope后可以被GC回收|
| OH_JSVM_OpenEscapableHandleScope| 打开一个新的scope逃逸handle scope，在关闭该scope之前创建的对象与父作用域有相同的生命周期 |
| OH_JSVM_CloseEscapableHandleScope| 关闭一个scope，在此scope范围外创建的对象不受父作用域保护 |
| OH_JSVM_EscapeHandle| 将 JavaScript 对象的句柄提升到外部作用域，确保在外部作用域中可以持续地使用该对象 |
| OH_JSVM_CreateReference| 以指定的引用计数为JavaScript对象创建一个新的引用，该引用将指向传入的对象，引用允许在不同的上下文中使用和共享对象，并且可以有效地跟踪对象的生命周期 |
| OH_JSVM_DeleteReference| 释放由 OH_JSVM_CreateReference 创建的引用，确保对象在不再被使用时能够被正确地释放和回收，避免内存泄漏 |
| OH_JSVM_ReferenceRef| 增加由OH_JSVM_CreateReference 创建的引用的引用计数，以确保对象在有引用时不会被提前释放 |
| OH_JSVM_ReferenceUnref| 减少由OH_JSVM_CreateReference 创建的引用的引用计数，以确保没有任何引用指向该对象时能正确地释放和回收 |
| OH_JSVM_GetReferenceValue| 返回由 OH_JSVM_CreateReference 创建的引用的对象 |

场景示例：
通过handlescope保护在scope范围内创建的对象在该范围内不被回收

```c++
JSVM_HandleScope scope;
OH_JSVM_OpenHandleScope(env, &scope);
JSVM_Value obj = nullptr;
OH_JSVM_CreateObject(env, &obj);
OH_JSVM_CloseHandleScope(env, scope);
```  

通过escapable handlescope保护在scope范围内创建的对象在父作用域范围内不被回收

```c++
static void func2(JSVM_Value *result)
{
    JSVM_EscapableHandleScope scope;
    JSVM_Env env;
    OH_JSVM_OpenEscapableHandleScope(env, &scope);
    OH_JSVM_CreateObject(env, result);
    OH_JSVM_CloseEscapableHandleScope(env, scope);
}

static void func1()
{
    JSVM_Value obj = nullptr;
    func2(&obj);
}
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

### 创建JS对象类型和基本类型

#### 场景介绍

创建JS对象类型和基本类型

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_CreateArray | 创建一个新的 JavaScript 数组对象 |
|OH_JSVM_CreateArrayWithLength | 创建一个指定长度的 JavaScript 数组对象 |
|OH_JSVM_CreateArraybuffer | 创建一个指定大小的 ArrayBuffer 对象 |
|OH_JSVM_CreateDate | 创建了一个表示给定毫秒数的 Date 对象 |
|OH_JSVM_CreateExternal | 创建一个包装了外部指针的 JavaScript 对象 |
|OH_JSVM_CreateExternalArraybuffer | 创建一个包装了外部 Arraybuffer 的 JavaScript 对象 |
|OH_JSVM_CreateObject | 创建一个默认的JavaScript Object对象 |
|OH_JSVM_CreateSymbol | 根据给定的描述符创建一个 Symbol 对象 |
|OH_JSVM_SymbolFor | 在全局注册表中搜索具有给定描述的现有Symbol,如果该Symbol已经存在，它将被返回，否则将在注册表中创建一个新Symbol |
|OH_JSVM_CreateTypedarray | 在现有的 ArrayBuffer 上创建一个 JavaScript TypedArray 对象,TypedArray 对象在底层数据缓冲区上提供类似数组的视图，其中每个元素都具有相同的底层二进制标量数据类型 |
|OH_JSVM_CreateDataview | 在现有的 ArrayBuffer 上创建一个 JavaScript DataView 对象。DataView 对象在底层数据缓冲区上提供类似数组的视图 |
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

场景示例:
创建指定长度的数组

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

创建typedarray，以Int32Array为例：

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

创建number和string:

```c++
const char *testStringStr = "test";
JSVM_Value testString = nullptr;
OH_JSVM_CreateStringUtf8(env, testStringStr, strlen(testStringStr), &testString);

JSVM_Value testNumber1 = nullptr;
JSVM_Value testNumber2 = nullptr;
OH_JSVM_CreateDouble(env, 10.1, &testNumber1);
OH_JSVM_CreateInt32(env, 10, &testNumber2);
```

### 从JS类型获取C类型&获取JS类型信息

#### 场景介绍

从JS类型获取C类型&获取JS类型信息

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
创建64位的BigInt，并获取64位int值。

```c++
int64_t testValue = INT64_MAX;
JSVM_Value result = nullptr;
OH_JSVM_CreateBigintInt64(env, testValue, &result);
int64_t resultValue = 0;
bool flag = false;
OH_JSVM_GetValueBigintInt64(env, result, &resultValue, &flag);
```

创建一个Int32Array，并获取其长度，byteoffset等信息。

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

创建utf8类型的String，并获取C字符串。

```c++
const char *testStringStr = "testString";
JSVM_Value testString = nullptr;
OH_JSVM_CreateStringUtf8(env, testStringStr, strlen(testStringStr), &testString);

char buffer[128];
size_t bufferSize = 128;
size_t copied;

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
|OH_JSVM_Typeof | 返回 JavaScript 对象的类型 |
|OH_JSVM_Instanceof | 判断一个对象是否是某个构造函数的实例 |
|OH_JSVM_IsArray | 判断一个 JavaScript 对象是否为 Array 类型对象|
|OH_JSVM_IsArraybuffer | 判断一个 JavaScript 对象是否为 Arraybuffer 类型对象 |
|OH_JSVM_IsDate | 判断一个 JavaScript 对象是否为 Date 类型对象 |
|OH_JSVM_IsTypedarray | 判断一个 JavaScript 对象是否为 Typedarray 类型对象 |
|OH_JSVM_IsDataview | 判断一个 JavaScript 对象是否为 Dataview 类型对象 |
|OH_JSVM_StrictEquals | 判断两个 JSVM_Value 对象是否相等 |
|OH_JSVM_DetachArraybuffer | 调用 ArrayBuffer 对象的Detach操作 |
|OH_JSVM_IsDetachedArraybuffer | 检查给定的 ArrayBuffer 是否已被分离(detached) |

场景示例:
判断JS值是否为数组类型

```c++
JSVM_Value array = nullptr;
OH_JSVM_CreateArray(env, &array);
bool isArray = false;
OH_JSVM_IsArray(env, array, &isArray);
```

将int32类型转换为string类型

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

判断两个JS值类型是否相同

```c++
JSVM_Value value = nullptr;
JSVM_Value value1 = nullptr;
OH_JSVM_CreateArray(env, &value);

OH_JSVM_CreateInt32(env, 10, &value1);
bool isArray = true;
OH_JSVM_StrictEquals(env, value, value, &isArray);
```

### JS属性操作

#### 场景介绍

JS对象属性的增删获取和判断

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_GetPropertyNames | 获取给定对象的所有可枚举属性名称, 结果变量将存储一个包含所有可枚举属性名称的JavaScript数组 |
|OH_JSVM_GetAllPropertyNames | 获取给定对象的所有可用属性名称, 结果变量将存储一个包含所有可枚举属性名称的JavaScript数组 |
|OH_JSVM_SetProperty | 为给定对象设置一个属性 |
|OH_JSVM_GetProperty | 用给定的属性的名称，检索目标对象的属性 |
|OH_JSVM_HasProperty | 用给定的属性的名称，查询目标对象是否有此属性 |
|OH_JSVM_DeleteProperty | 用给定的属性的名称，删除目标对象属性 |
|OH_JSVM_HasOwnProperty | 检查目标对象是否具有指定的自有属性 |
|OH_JSVM_SetNamedProperty | 用给定的属性的名称为目标对象设置属性，此方法等效于使用从作为 utf8Name 传入的字符串创建的 JSVM_Value 调用 OH_JSVM_SetNamedProperty |
|OH_JSVM_GetNamedProperty | 用给定的属性的名称，检索目标对象的属性，此方法等效于使用从作为 utf8Name 传入的字符串创建的 JSVM_Value 调用 OH_JSVM_GetNamedProperty |
|OH_JSVM_HasNamedProperty | 用给定的属性的名称，查询目标对象是否有此属性，此方法等效于使用从作为 utf8Name 传入的字符串创建的 JSVM_Value 调用 OH_JSVM_HasNamedProperty |
|OH_JSVM_SetElement | 在给定对象的指定索引处，设置元素。 |
|OH_JSVM_GetElement | 获取给定对象指定索引处的元素。 |
|OH_JSVM_HasElement | 若给定对象的指定索引处拥有属性，获取该元素 |
|OH_JSVM_DeleteElement | 尝试删除给定对象的指定索引处的元素 |
|OH_JSVM_DefineProperties |  批量的向给定对象中定义属性 |
|OH_JSVM_ObjectFreeze | 冻结给定的对象,防止向其添加新属性，删除现有属性，防止更改现有属性的可枚举性、可配置性或可写性，并防止更改现有属性的值 |
|OH_JSVM_ObjectSeal | 密封给定的对象。这可以防止向其添加新属性，以及将所有现有属性标记为不可配置 |

场景示例:
JS对象属性的增删获取和判断

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
if (hasProperty)
{
    // 属性存在，做相应处理...
    // 删除属性
    OH_JSVM_DeleteProperty(env, myObject, key, &hasProperty);
}

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

场景示例:
创建JavaScript函数操作

```c++
JSVM_Value SayHello(JSVM_Env env, JSVM_CallbackInfo info)
{
    printf("Hello\n");
    JSVM_Value ret;
    OH_JSVM_CreateInt32(env, 2, &ret);
    return ret;
}

static JSVM_Value jsvmCreateFunction(JSVM_Env env, JSVM_CallbackInfo info)
{
    JSVM_CallbackStruct param;
    param.data = nullptr;
    param.callback = SayHello;

    JSVM_Value funcValue = nullptr;
    JSVM_Status status = OH_JSVM_CreateFunction(env, "func", JSVM_AUTO_LENGTH, &param, &funcValue);
    JSVM_Value value;
    OH_JSVM_CreateInt32(env, 1, &value);
    return funcValue;
}
```

在C/C++侧获取并调用JS方法

```c++
static JSVM_Value callFunction(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 1;
    JSVM_Value args[1];
    OH_JSVM_GetCbInfo(env, info, &argc, args, nullptr, nullptr);

    JSVM_ValueType valuetype;
    OH_JSVM_Typeof(env, args[0], &valuetype);
    JSVM_Value ret;
    OH_JSVM_CallFunction(env, nullptr, args[0], 0, nullptr, &ret);
    return ret;
}
```

### 对象绑定操作

#### 场景介绍

对象绑定操作。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_DefineClass| 用于在JavaScript中定义一个类，并与对应的C类进行封装和交互。它提供了创建类的构造函数、定义属性和方法的能力，以及在C和JavaScript之间进行数据交互的支持 |
|OH_JSVM_Wrap| 在 JavaScript 对象中封装原生实例。稍后可以使用 OH_JSVM_Unwrap() 检索原生实例 |
|OH_JSVM_Unwrap | 使用 OH_JSVM_Wrap() 检索先前封装在 JavaScript 对象中的原生实例 |
|OH_JSVM_RemoveWrap | 检索先前封装在 JavaScript 对象中的原生实例并移除封装 |
|OH_JSVM_TypeTagObject | 将 type_tag 指针的值与 JavaScript 对象或外部对象相关联 |
|OH_JSVM_CheckObjectTypeTag | 检查给定的类型标签是否与对象上的类型标签匹配 |
|OH_JSVM_AddFinalizer | 为对象添加 JSVM_Finalize 回调，以便在 JavaScript 对象被垃圾回收时调用来释放原生对象 |
|OH_JSVM_PostFinalizer | 安排在事件循环中异步调用 JSVM_Finalize 回调 |

场景示例：
对象绑定操作

```c++
static JSVM_Value assertEqual(JSVM_Env env, JSVM_CallbackInfo info)
{
    size_t argc = 2;
    JSVM_Value args[2];
    JSVM_CALL(env, OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

    bool isStrictEquals = false;
    OH_JSVM_StrictEquals(env, args[0], args[1], &isStrictEquals);
    return nullptr;
}

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
```

### 版本管理

#### 场景介绍

获取当前版本信息。

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_GetVersion| 返回JSVM运行时支持的最高JSVM API版本 |
|OH_JSVM_GetVMInfo| 返回虚拟机的信息 |

场景示例：
获取当前版本信息

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
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_AdjustExternalMemory| 通知虚拟机系统内存不足并有选择地触发垃圾回收 |
|OH_JSVM_MemoryPressureNotification| 创建一个延迟对象和一个JavaScript promise |

场景示例：
内存管理

```c++
int64_t change = 1024 * 1024; // 分配1MB的内存
int64_t result;
OH_JSVM_AdjustExternalMemory(env, change, &result);
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
Promise相关操作

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
解析JSON操作

```c++
std::string sourcecodestr = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}" ;
JSVM_Value jsonString;
OH_JSVM_CreateStringUtf8(env, sourcecodestr.c_str(), sourcecodestr.size(), &jsonString)
JSVM_Value result;
OH_JSVM_JsonParse(env, jsonString, &result);
```

### 创建虚拟机的启动快照

#### 场景介绍

创建虚拟机的启动快照

#### 接口说明
| 接口 | 功能说明 |
| -------- | -------- |
|OH_JSVM_CreateSnapshot| 用于创建虚拟机的启动快照 |

场景示例：
创建虚拟机的启动快照

```c++
JSVM_VM vm;
JSVM_CreateVMOptions options;
memset(&options, 0, sizeof(options));
OH_JSVM_CreateVM(&options, &vm);
JSVM_Env env;
JSVM_CallbackStruct param[1];
param[0].data = nullptr;
param[0].callback = assertEqual;
JSVM_PropertyDescriptor descriptor[] = {
    {"test", nullptr, &param[0], nullptr, nullptr, nullptr, JSVM_DEFAULT},
};
OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env);
const char *blob_data = nullptr;
size_t blob_size = 0;
JSVM_Env envs[1] = {env};
OH_JSVM_CreateSnapshot(vm, 1, envs, &blob_data, &blob_size);
```