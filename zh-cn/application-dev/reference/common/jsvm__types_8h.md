# jsvm_types.h


## 概述

提供JSVM-API类型定义。

通过API接口为开发者提供独立、标准、完整的JavaScript引擎能力， 包括管理引擎生命周期、编译运行JS代码、实现JS/C++跨语言调用、拍摄快照等。

**库：** libjsvm.so

**系统能力：** SystemCapability.ArkCompiler.JSVM

**起始版本：** 11

**相关模块：**[JSVM](_j_s_v_m.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[JSVM_CallbackStruct](_j_s_v_m___callback_struct.md) | 用户提供的native回调函数的指针和数据，这些函数通过JSVM-API接口暴露给JavaScript。  | 
| struct&nbsp;&nbsp;[JSVM_HeapStatistics](_j_s_v_m___heap_statistics.md) | Heapstatisics结构体，用于保存有关JavaScript堆内存使用情况的统计信息。  | 
| struct&nbsp;&nbsp;[JSVM_InitOptions](_j_s_v_m___init_options.md) | 初始化选项，用于初始化JavaScript虚拟机。  | 
| struct&nbsp;&nbsp;[JSVM_CreateVMOptions](_j_s_v_m___create_v_m_options.md) | 创建JavaScript虚拟机的选项。  | 
| struct&nbsp;&nbsp;[JSVM_VMInfo](_j_s_v_m___v_m_info.md) | JavaScript虚拟机信息。  | 
| struct&nbsp;&nbsp;[JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) | 属性描述符。  | 
| struct&nbsp;&nbsp;[JSVM_ExtendedErrorInfo](_j_s_v_m___extended_error_info.md) | 扩展的异常信息。  | 
| struct&nbsp;&nbsp;[JSVM_TypeTag](_j_s_v_m___type_tag.md) | 类型标记，存储为两个无符号64位整数的128位值。 作为一个UUID，通过它，JavaScript对象可以是"tagged"， 以确保它们的类型保持不变。  | 
| struct&nbsp;&nbsp;[JSVM_PropertyHandlerConfigurationStruct](_j_s_v_m___property_handler_configuration_struct.md) | 当执行对象的getter、setter、deleter和enumerator操作时，该结构体中对应的函数回调将会触发。  | 
| struct&nbsp;&nbsp;[JSVM_ScriptOrigin](_j_s_v_m___script_origin.md) | Source code information。  |
| struct&nbsp;&nbsp;[JSVM_PropertyHandler](_j_s_v_m___property_handler.md) | 包含将class作为函数进行调用时所触发的回调函数的函数指针和访问实例对象属性时触发的回调函数的函数指针集。  |
| struct&nbsp;&nbsp;[JSVM_DefineClassOptions](_j_s_v_m___define_class_options.md) | 定义Class的选项。  |


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
|  typedef uint16_t **char16_t** |  | 
| typedef struct JSVM_VM__ \* [JSVM_VM](_j_s_v_m.md#jsvm_vm) | 表示JavaScript虚拟机实例。  | 
| typedef struct JSVM_VMScope__ \* [JSVM_VMScope](_j_s_v_m.md#jsvm_vmscope) | 表示JavaScript虚拟机作用域。  | 
| typedef struct JSVM_EnvScope__ \* [JSVM_EnvScope](_j_s_v_m.md#jsvm_envscope) | 表示用于控制附加到当前虚拟机实例的环境。只有当线程通过 OH_JSVM_OpenEnvScope进入该环境的JSVM_EnvScope后，该环境才 对线程的虚拟机实例可用。  | 
| typedef struct JSVM_Script__ \* [JSVM_Script](_j_s_v_m.md#jsvm_script) | 表示一段JavaScript代码。  | 
| typedef struct JSVM_Env__ \* [JSVM_Env](_j_s_v_m.md#jsvm_env) | 表示虚拟机特定状态的上下文环境，需要在调用native函数时作为参数传递， 并且传递给后续任何的JSVM-API嵌套调用。  | 
| typedef struct JSVM_CpuProfiler__ \* [JSVM_CpuProfiler](_j_s_v_m.md#jsvm_cpuprofiler) | 表示一个JavaScript CPU时间性能分析器。  | 
| typedef struct JSVM_Value__ \* [JSVM_Value](_j_s_v_m.md#jsvm_value) | 表示JavaScript值。  | 
| typedef struct JSVM_Data__ \* [JSVM_Data](_j_s_v_m.md#jsvm_data) | 表示一个 JavaScript Data。  |
| typedef struct JSVM_Ref__ \* [JSVM_Ref](_j_s_v_m.md#jsvm_ref) | 表示JavaScript值的引用。  | 
| typedef struct JSVM_HandleScope__ \* [JSVM_HandleScope](_j_s_v_m.md#jsvm_handlescope) | 表示JavaScript值的作用域，用于控制和修改在特定范围内创建的对象的生命周期。 通常，JSVM-API值是在JSVM_HandleScope的上下文中创建的。当从JavaScript调用native方法时， 将存在默认JSVM_HandleScope。如果用户没有显式创建新的JSVM_HandleScope，将在默认 JSVM_HandleScope中创建JSVM-API值。对于native方法执行之外的任何代码调用（例如，在libuv回调调用期间）， 模块需要在调用任何可能导致创建JavaScript值的函数之前创建一个作用域。JSVM_HandleScope是使用 OH_JSVM_OpenHandleScope创建的，并使用OH_JSVM_CloseHandleScope销毁的。 关闭作用域代表向GC指示在JSVM_HandleScope作用域的生命周期内创建的所有JSVM_Value将不再从当前堆的栈帧中引用。  | 
| typedef struct JSVM_EscapableHandleScope__ \* [JSVM_EscapableHandleScope](_j_s_v_m.md#jsvm_escapablehandlescope) | 表示一种特殊类型的handle scope，用于将在特定handle scope内创建的值返回到父作用域。  | 
| typedef struct JSVM_CallbackInfo__ \* [JSVM_CallbackInfo](_j_s_v_m.md#jsvm_callbackinfo) | 表示传递给回调函数的不透明数据类型。可用于获取调用该函数的上下文的附加信息。  | 
| typedef struct JSVM_Deferred__ \* [JSVM_Deferred](_j_s_v_m.md#jsvm_deferred) | 表示Promise延迟对象。  | 
| typedef [JSVM_CallbackStruct](_j_s_v_m___callback_struct.md) \* [JSVM_Callback](_j_s_v_m.md#jsvm_callback) | 用户提供的native函数的函数指针类型，这些函数通过JSVM-API接口暴露给JavaScript。  | 
| typedef void(JSVM_CDECL \* [JSVM_Finalize](_j_s_v_m.md#jsvm_finalize)) ([JSVM_Env](_j_s_v_m.md#jsvm_env) env, void \*finalizeData, void \*finalizeHint) | 函数指针类型，当native类型对象或数据与JS对象被关联时，传入该指针。该函数将会 在关联的JS对象被GC回收时被调用，用以执行native的清理动作。  | 
| typedef bool(JSVM_CDECL \* [JSVM_OutputStream](_j_s_v_m.md#jsvm_outputstream)) (const char \*data, int size, void \*streamData) | ASCII输出流回调的函数指针类型。参数data是指输出的数据指针。参数size是指输出的数据大小。 空数据指针指示流的结尾。参数streamData是指与回调一起传递给API函数的指针，该API函数向输出流生成数据。回 调返回true表示流可以继续接受数据。否则，它将中止流。  | 
| typedef [JSVM_PropertyHandlerConfigurationStruct](_j_s_v_m___property_handler_configuration_struct.md) \* [JSVM_PropertyHandlerCfg](_j_s_v_m.md#jsvm_propertyhandlercfg) | 包含属性监听回调的结构的指针类型。  | 
| typedef void(JSVM_CDECL \* [JSVM_HandlerForGC](_j_s_v_m.md#jsvm_handlerforgc)([JSVM_VM](_j_s_v_m.md#jsvm_vm) vm, [JSVM_GCType](_j_s_v_m.md#jsvm_gctype) gcType, [JSVM_GCCallbackFlags](_j_s_v_m.md#jsvm_gccallbackflags) flags, void\* data)) |GC回调的函数指针类型。  |
| typedef void(JSVM_CDECL \* [JSVM_HandlerForOOMError](_j_s_v_m.md#jsvm_handlerforoomerror)(const char\* location, const char\* detail, bool isHeapOOM)) | OOM-Error回调的函数指针类型。  |
| typedef void(JSVM_CDECL \* [JSVM_HandlerForFatalError](_j_s_v_m.md#jsvm_handlerforfatalerror)(const char\* location, <br/>const char\* message)) | Fatal-Error回调的函数指针类型。  |
| typedef void(JSVM_CDECL \* [JSVM_HandlerForPromiseReject](_j_s_v_m.md#jsvm_handlerforpromisereject)([JSVM_Env](_j_s_v_m.md#jsvm_env) env, [JSVM_PromiseRejectEvent](_j_s_v_m.md#jsvm_promiserejectevent) rejectEvent, [JSVM_Value](_j_s_v_m.md#jsvm_value) rejectInfo)) | Promise-Reject回调的函数指针类型。  |


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [JSVM_PropertyAttributes](_j_s_v_m.md#jsvm_propertyattributes) {<br/>[JSVM_DEFAULT](_j_s_v_m.md) = 0, [JSVM_WRITABLE](_j_s_v_m.md) = 1 &lt;&lt; 0, [JSVM_ENUMERABLE](_j_s_v_m.md) = 1 &lt;&lt; 1, [JSVM_CONFIGURABLE](_j_s_v_m.md) = 1 &lt;&lt; 2,<br/>[JSVM_STATIC](_j_s_v_m.md) = 1 &lt;&lt; 10, [JSVM_DEFAULT_METHOD](_j_s_v_m.md) = JSVM_WRITABLE \| JSVM_CONFIGURABLE, [JSVM_DEFAULT_JSPROPERTY](_j_s_v_m.md) = JSVM_WRITABLE \| JSVM_ENUMERABLE \| JSVM_CONFIGURABLE<br/>} | 用于控制JavaScript对象属性的行为。  | 
| [JSVM_ValueType](_j_s_v_m.md#jsvm_valuetype) {<br/>[JSVM_UNDEFINED](_j_s_v_m.md), [JSVM_NULL](_j_s_v_m.md), [JSVM_BOOLEAN](_j_s_v_m.md), [JSVM_NUMBER](_j_s_v_m.md),<br/>[JSVM_STRING](_j_s_v_m.md), [JSVM_SYMBOL](_j_s_v_m.md), [JSVM_OBJECT](_j_s_v_m.md), [JSVM_FUNCTION](_j_s_v_m.md),<br/>[JSVM_EXTERNAL](_j_s_v_m.md), [JSVM_BIGINT](_j_s_v_m.md)<br/>} | 描述JSVM_Value的类型。  | 
| [JSVM_TypedarrayType](_j_s_v_m.md#jsvm_typedarraytype) {<br/>[JSVM_INT8_ARRAY](_j_s_v_m.md), [JSVM_UINT8_ARRAY](_j_s_v_m.md), [JSVM_UINT8_CLAMPED_ARRAY](_j_s_v_m.md), [JSVM_INT16_ARRAY](_j_s_v_m.md),<br/>[JSVM_UINT16_ARRAY](_j_s_v_m.md), [JSVM_INT32_ARRAY](_j_s_v_m.md), [JSVM_UINT32_ARRAY](_j_s_v_m.md), [JSVM_FLOAT32_ARRAY](_j_s_v_m.md),<br/>[JSVM_FLOAT64_ARRAY](_j_s_v_m.md), [JSVM_BIGINT64_ARRAY](_j_s_v_m.md), [JSVM_BIGUINT64_ARRAY](_j_s_v_m.md)<br/>} | 描述TypedArray的类型。  | 
| [JSVM_Status](_j_s_v_m.md#jsvm_status) {<br/>[JSVM_OK](_j_s_v_m.md), [JSVM_INVALID_ARG](_j_s_v_m.md), [JSVM_OBJECT_EXPECTED](_j_s_v_m.md), [JSVM_STRING_EXPECTED](_j_s_v_m.md),<br/>[JSVM_NAME_EXPECTED](_j_s_v_m.md), [JSVM_FUNCTION_EXPECTED](_j_s_v_m.md), [JSVM_NUMBER_EXPECTED](_j_s_v_m.md), [JSVM_BOOLEAN_EXPECTED](_j_s_v_m.md),<br/>[JSVM_ARRAY_EXPECTED](_j_s_v_m.md), [JSVM_GENERIC_FAILURE](_j_s_v_m.md), [JSVM_PENDING_EXCEPTION](_j_s_v_m.md), [JSVM_CANCELLED](_j_s_v_m.md),<br/>[JSVM_ESCAPE_CALLED_TWICE](_j_s_v_m.md), [JSVM_HANDLE_SCOPE_MISMATCH](_j_s_v_m.md), [JSVM_CALLBACK_SCOPE_MISMATCH](_j_s_v_m.md), [JSVM_QUEUE_FULL](_j_s_v_m.md),<br/>[JSVM_CLOSING](_j_s_v_m.md), [JSVM_BIGINT_EXPECTED](_j_s_v_m.md), [JSVM_DATE_EXPECTED](_j_s_v_m.md), [JSVM_ARRAYBUFFER_EXPECTED](_j_s_v_m.md),<br/>[JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED](_j_s_v_m.md), [JSVM_WOULD_DEADLOCK](_j_s_v_m.md), [JSVM_NO_EXTERNAL_BUFFERS_ALLOWED](_j_s_v_m.md), [JSVM_CANNOT_RUN_JS](_j_s_v_m.md), [JSVM_INVALID_TYPE](_j_s_v_m.md)<br/>} | 表示JSVM-API调用成功或失败的完整状态码。  | 
| [JSVM_KeyCollectionMode](_j_s_v_m.md#jsvm_keycollectionmode) { [JSVM_KEY_INCLUDE_PROTOTYPES](_j_s_v_m.md), [JSVM_KEY_OWN_ONLY](_j_s_v_m.md) } | 限制查找属性的范围。  | 
| [JSVM_KeyFilter](_j_s_v_m.md#jsvm_keyfilter) {<br/>[JSVM_KEY_ALL_PROPERTIES](_j_s_v_m.md) = 0, [JSVM_KEY_WRITABLE](_j_s_v_m.md) = 1, [JSVM_KEY_ENUMERABLE](_j_s_v_m.md) = 1 &lt;&lt; 1, [JSVM_KEY_CONFIGURABLE](_j_s_v_m.md) = 1 &lt;&lt; 2,<br/>[JSVM_KEY_SKIP_STRINGS](_j_s_v_m.md) = 1 &lt;&lt; 3, [JSVM_KEY_SKIP_SYMBOLS](_j_s_v_m.md) = 1 &lt;&lt; 4<br/>} | 属性过滤器，可以通过使用or来构造一个复合过滤器。  | 
| [JSVM_KeyConversion](_j_s_v_m.md#jsvm_keyconversion) { [JSVM_KEY_KEEP_NUMBERS](_j_s_v_m.md), [JSVM_KEY_NUMBERS_TO_STRINGS](_j_s_v_m.md) } | 键转换选项。  | 
| [JSVM_MemoryPressureLevel](_j_s_v_m.md#jsvm_memorypressurelevel) { [JSVM_MEMORY_PRESSURE_LEVEL_NONE](_j_s_v_m.md), [JSVM_MEMORY_PRESSURE_LEVEL_MODERATE](_j_s_v_m.md), [JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL](_j_s_v_m.md) } | 内存压力水平。  | 
| [JSVM_RegExpFlags](_j_s_v_m.md#jsvm_regexpflags) {<br/>[JSVM_REGEXP_NONE](_j_s_v_m.md) = 0, [JSVM_REGEXP_GLOBAL](_j_s_v_m.md) = 1 &lt;&lt; 0, [JSVM_REGEXP_IGNORE_CASE](_j_s_v_m.md) = 1 &lt;&lt; 1, [JSVM_REGEXP_MULTILINE](_j_s_v_m.md) = 1 &lt;&lt; 2,<br/>[JSVM_REGEXP_STICKY](_j_s_v_m.md) = 1 &lt;&lt; 3, [JSVM_REGEXP_UNICODE](_j_s_v_m.md) = 1 &lt;&lt; 4, [JSVM_REGEXP_DOT_ALL](_j_s_v_m.md) = 1 &lt;&lt; 5, [JSVM_REGEXP_LINEAR](_j_s_v_m.md) = 1 &lt;&lt; 6,<br/>[JSVM_REGEXP_HAS_INDICES](_j_s_v_m.md) = 1 &lt;&lt; 7, [JSVM_REGEXP_UNICODE_SETS](_j_s_v_m.md) = 1 &lt;&lt; 8<br/>} | 正则表达式标志位。它们可以用来启用一组标志。  | 
| [JSVM_InitializedFlag](_j_s_v_m.md#jsvm_initializedflag) { [JSVM_ZERO_INITIALIZED](_j_s_v_m.md), [JSVM_UNINITIALIZED](_j_s_v_m.md) } | 初始化方式的标志位  | 
| [JSVM_WasmOptLevel](_j_s_v_m.md#jsvm_wasmoptlevel) { [JSVM_WASM_OPT_BASELINE](_j_s_v_m.md) = 10, [JSVM_WASM_OPT_HIGH](_j_s_v_m.md) = 20 } | WebAssembly 函数优化等级  | 
| [JSVM_CacheType](_j_s_v_m.md#jsvm_cachetype) { [JSVM_CACHE_TYPE_JS](_j_s_v_m.md), [JSVM_CACHE_TYPE_WASM](_j_s_v_m.md) } | 缓存类型。  | 
| [JSVM_MicrotaskPolicy](_j_s_v_m.md#jsvm_microtaskpolicy) { [JSVM_MICROTASK_EXPLICIT](_j_s_v_m.md) = 0, [JSVM_MICROTASK_AUTO](_j_s_v_m.md) } | JSVM 微任务执行策略。  |
| [JSVM_TraceCategory](_j_s_v_m.md#jsvm_tracecategory) { [JSVM_TRACE_VM](_j_s_v_m.md), [JSVM_TRACE_COMPILE](_j_s_v_m.md), [JSVM_TRACE_EXECUTE](_j_s_v_m.md), [JSVM_TRACE_RUNTIME](_j_s_v_m.md), [JSVM_TRACE_STACK_TRACE](_j_s_v_m.md), [JSVM_TRACE_WASM](_j_s_v_m.md), [JSVM_TRACE_WASM_DETAILED](_j_s_v_m.md) } | JSVM 内部 Trace 事件的类别。  |
| [JSVM_CBTriggerTimeForGC](_j_s_v_m.md#jsvm_cbtriggertimeforgc) { [JSVM_CB_TRIGGER_BEFORE_GC](_j_s_v_m.md), [JSVM_CB_TRIGGER_AFTER_GC](_j_s_v_m.md) } | 触发回调函数的时机。  |

| [JSVM_GCType](_j_s_v_m.md#jsvm_gctype) { [JSVM_GC_TYPE_SCAVENGE](_j_s_v_m.md) = 1 &lt;&lt; 0, [JSVM_GC_TYPE_MINOR_MARK_COMPACT](_j_s_v_m.md) = 1 &lt;&lt; 1, [JSVM_GC_TYPE_MARK_SWEEP_COMPACT](_j_s_v_m.md) = 1 &lt;&lt; 2, [JSVM_GC_TYPE_INCREMENTAL_MARKING](_j_s_v_m.md) = 1 &lt;&lt; 3, [JSVM_GC_TYPE_PROCESS_WEAK_CALLBACKS](_j_s_v_m.md) = 1 &lt;&lt; 4, [JSVM_GC_TYPE_ALL ](_j_s_v_m.md) = JSVM_GC_TYPE_SCAVENGE \| JSVM_GC_TYPE_MINOR_MARK_COMPACT \| JSVM_GC_TYPE_MARK_SWEEP_COMPACT \| JSVM_GC_TYPE_INCREMENTAL_MARKING \| JSVM_GC_TYPE_PROCESS_WEAK_CALLBACKS } | GC类型。  |

| [JSVM_GCCallbackFlags](_j_s_v_m.md#jsvm_gccallbackflags) { [JSVM_NO_GC_CALLBACK_FLAGS](_j_s_v_m.md), [JSVM_GC_CALLBACK_CONSTRUCT_RETAINED_OBJECT_INFOS](_j_s_v_m.md), [JSVM_GC_CALLBACK_FORCED](_j_s_v_m.md), [JSVM_GC_CALLBACK_SYNCHRONOUS_PHANTOM_CALLBACK_PROCESSING](_j_s_v_m.md), [JSVM_GC_CALLBACK_COLLECT_ALL_AVAILABLE_GARBAGE](_j_s_v_m.md), [JSVM_GC_CALLBACK_COLLECT_ALL_EXTERNAL_MEMORY](_j_s_v_m.md), [JSVM_GC_CALLBACK_SCHEDULE_IDLE_GARBAGE_COLLECTION](_j_s_v_m.md) } | GC回调函数标记。  |
| [JSVM_PromiseRejectEvent](_j_s_v_m.md#jsvm_promiserejectevent) { [JSVM_PROMISE_REJECT_OTHER_REASONS](_j_s_v_m.md) = 0, [JSVM_PROMISE_REJECT_WITH_NO_HANDLER](_j_s_v_m.md) = 1, [JSVM_PROMISE_HANDLER_ADDED_AFTER_REJECT](_j_s_v_m.md) = 2, [JSVM_PROMISE_REJECT_AFTER_RESOLVED](_j_s_v_m.md) = 3, [JSVM_PROMISE_RESOLVE_AFTER_RESOLVED](_j_s_v_m.md) = 4 } | promise-reject事件。  |
| [JSVM_MessageErrorLevel](_j_s_v_m.md#jsvm_messageerrorlevel) { [JSVM_MESSAGE_LOG](_j_s_v_m.md) = (1 &lt;&lt; 0), [JSVM_MESSAGE_DEBUG](_j_s_v_m.md) = (1 &lt;&lt; 1), [JSVM_MESSAGE_INFO](_j_s_v_m.md) = (1 &lt;&lt; 2), [JSVM_MESSAGE_ERROR](_j_s_v_m.md) = (1 &lt;&lt; 3), [JSVM_MESSAGE_WARNING](_j_s_v_m.md) = (1 &lt;&lt; 4), [JSVM_MESSAGE_ALL ](_j_s_v_m.md) = JSVM_MESSAGE_LOG \| JSVM_MESSAGE_DEBUG \| JSVM_MESSAGE_INFO \| JSVM_MESSAGE_ERROR \| JSVM_MESSAGE_WARNING }  | message的报错级别。  |
| [JSVM_DefineClassOptionsId](_j_s_v_m.md#jsvm_defineclassoptionsid) { [JSVM_DEFINE_CLASS_NORMAL](_j_s_v_m.md), [JSVM_DEFINE_CLASS_WITH_COUNT](_j_s_v_m.md), [JSVM_DEFINE_CLASS_WITH_PROPERTY_HANDLER](_j_s_v_m.md) }  | 定义Class的选项ID。  |
