# JSVM


## Overview

Provides standard JavaScript engine capabilities.

Function: The standard JS engine is a JavaScript code execution engine that strictly complies with the ECMAScript specification. It supports the standard library defined in the ECMAScript specification and provides comprehensive native APIs of C++ interaction JS. It uses the Just-In-Time (JIT) compiler to accelerate code execution and provide secure and efficient JS execution capabilities for applications. The capabilities of the standard JS engine are provided through a stable set of application binary interfaces (ABIs), that is, JSVM-API. JSVM-API can be dynamically linked to JS engine libraries of different versions to shield API differences between engines. JSVM-API provides capabilities such as engine lifecycle management, JS context management, JS code execution, JS/C++ interoperability, execution environment snapshot, and code cache.

Platform: ARM64.

Usage: Link **libjsvm.so** in the SDK and include the **ark_runtime/jsvm.h** header file in the C++ code.

The APIs are used to provide independent, standard, and complete JavaScript engine capabilities, including managing the engine lifecycle, compiling and running JS code, implementing JS/C++ cross-language invoking, and taking snapshots.

**Since**: 11


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [jsvm.h](jsvm_8h.md) | Provides JSVM-API API definitions.| 
| [jsvm_types.h](jsvm__types_8h.md) | Provides JSVM-API type definitions.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[JSVM_CallbackStruct](_j_s_v_m___callback_struct.md) | Pointer to and data of the native callbacks provided by the user. These functions are exposed to JavaScript via JSVM-API.| 
| struct&nbsp;&nbsp;[JSVM_HeapStatistics](_j_s_v_m___heap_statistics.md) | Heap statistics struct, which is used to store statistics about JavaScript heap memory usage.| 
| struct&nbsp;&nbsp;[JSVM_InitOptions](_j_s_v_m___init_options.md) | Options for initializing a JavaScript VM.| 
| struct&nbsp;&nbsp;[JSVM_CreateVMOptions](_j_s_v_m___create_v_m_options.md) | Options for creating a JavaScript VM.| 
| struct&nbsp;&nbsp;[JSVM_VMInfo](_j_s_v_m___v_m_info.md) | JavaScript VM information.| 
| struct&nbsp;&nbsp;[JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) | Property descriptor.| 
| struct&nbsp;&nbsp;[JSVM_ExtendedErrorInfo](_j_s_v_m___extended_error_info.md) | Extended error information.| 
| struct&nbsp;&nbsp;[JSVM_TypeTag](_j_s_v_m___type_tag.md) | Type tag, stored as a 128-bit value of two unsigned 64-bit integers. This tag can be used as a UUID, so that JavaScript objects can be tagged, to ensure that their types remain unchanged.| 
| struct&nbsp;&nbsp;[JSVM_PropertyHandlerConfigurationStruct](_j_s_v_m___property_handler_configuration_struct.md) | Struct for triggering the corresponding callback when the getter, setter, deleter, or enumerator of an object is executed.| 
| struct&nbsp;&nbsp;[JSVM_ScriptOrigin](_j_s_v_m___script_origin.md) | Source code information. | 


### Macros

| Name| Description| 
| -------- | -------- |
| **JSVM_VERSION_EXPERIMENTAL**&nbsp;&nbsp;&nbsp;2147483647 |  | 
| **JSVM_VERSION**&nbsp;&nbsp;&nbsp;8 |  | 
| **JSVM_EXTERN**&nbsp;&nbsp;&nbsp;__attribute__((visibility("default"))) |  | 
| [JSVM_AUTO_LENGTH](#jsvm_auto_length)&nbsp;&nbsp;&nbsp;SIZE_MAX | Automatic length.| 
| **EXTERN_C_START** |  | 
| **EXTERN_C_END** |  | 
| **JSVM_CDECL** |  | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef uint16_t **char16_t** |  | 
| typedef struct JSVM_VM__ \* [JSVM_VM](#jsvm_vm) | JavaScript VM instance.| 
| typedef struct JSVM_VMScope__ \* [JSVM_VMScope](#jsvm_vmscope) | JavaScript VM scope.| 
| typedef struct JSVM_EnvScope__ \* [JSVM_EnvScope](#jsvm_envscope) | Environment scope of the current VM instance. The environment is available to the VM instance of the thread only after the thread enters JSVM_EnvScope of the environment through OH_JSVM_OpenEnvScope.| 
| typedef struct JSVM_Script__ \* [JSVM_Script](#jsvm_script) | JavaScript code.| 
| typedef struct JSVM_Env__ \* [JSVM_Env](#jsvm_env) | Context of a specific VM state. It needs to be passed as a parameter when the native function is called and passed to any subsequent JSVM-API nested invoking.| 
| typedef struct JSVM_CpuProfiler__ \* [JSVM_CpuProfiler](#jsvm_cpuprofiler) | JavaScript CPU profiler.| 
| typedef struct JSVM_Value__ \* [JSVM_Value](#jsvm_value) | JavaScript value.| 
| typedef struct JSVM_Ref__ \* [JSVM_Ref](#jsvm_ref) | Reference to the JavaScript value.| 
| typedef struct JSVM_HandleScope__ \* [JSVM_HandleScope](#jsvm_handlescope) | Scope of the JavaScript value. It is used to control and modify the lifecycle of an object created in a specific scope. Typically, the JSVM-API value is created in the context of JSVM_HandleScope. When the native method is called from JavaScript, the default JSVM_HandleScope exists. If the user does not explicitly create a new JSVM_HandleScope, the JSVM-API value is created in the default JSVM_HandleScope. For any code call other than native method execution (for example, libuv callback), the module needs to create a scope before calling any function that may cause JavaScript value creation. JSVM_HandleScope is created using OH_JSVM_OpenHandleScope and destroyed using OH_JSVM_CloseHandleScope. Closing the scope represents indicating to the GC that all JSVM_Values created during the lifecycle of JSVM_HandleScope will no longer be referenced from the stack frame of the current heap.| 
| typedef struct JSVM_EscapableHandleScope__ \* [JSVM_EscapableHandleScope](#jsvm_escapablehandlescope) | A special type of handle scope, which is used to return the value created in a specific handle scope to the parent scope.| 
| typedef struct JSVM_CallbackInfo__ \* [JSVM_CallbackInfo](#jsvm_callbackinfo) | An opaque data type passed to the callback. It can be used to obtain additional information about the context in which the function is called.| 
| typedef struct JSVM_Deferred__ \* [JSVM_Deferred](#jsvm_deferred) | Promise deferred object.| 
| typedef [JSVM_CallbackStruct](_j_s_v_m___callback_struct.md) \* [JSVM_Callback](#jsvm_callback) | Pointer types of the native functions provided by user. These functions are exposed to JavaScript via JSVM-API.| 
| typedef void(JSVM_CDECL \* [JSVM_Finalize](#jsvm_finalize)) ([JSVM_Env](#jsvm_env) env, void \*finalizeData, void \*finalizeHint) | Function pointer type. It is passed in when a native object or data is associated with a JavaScript object. This function is called when the associated JavaScript object is reclaimed by the GC to execute the native cleanup action.| 
| typedef bool(JSVM_CDECL \* [JSVM_OutputStream](#jsvm_outputstream)) (const char \*data, int size, void \*streamData) | Pointer to the callback of the ASCII output stream. **data** indicates the pointer to the output data. **size** indicates the size of the output data. **void** points to the end of the stream. **streamData** indicates the pointer passed to the API function together with the callback. The API function generates data to the output stream. If **true** is returned, the stream can continue to receive data. Otherwise, it aborts the stream.| 
| typedef [JSVM_PropertyHandlerConfigurationStruct](_j_s_v_m___property_handler_configuration_struct.md) \* [JSVM_PropertyHandlerCfg](#jsvm_propertyhandlercfg) | Pointer type of the struct that contains the property listening callback.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [JSVM_PropertyAttributes](#jsvm_propertyattributes) {<br>JSVM_DEFAULT = 0, JSVM_WRITABLE = 1 &lt;&lt; 0, JSVM_ENUMERABLE = 1 &lt;&lt; 1, JSVM_CONFIGURABLE = 1 &lt;&lt; 2,<br>JSVM_STATIC = 1 &lt;&lt; 10, JSVM_DEFAULT_METHOD = JSVM_WRITABLE \| JSVM_CONFIGURABLE, JSVM_DEFAULT_JSPROPERTY = JSVM_WRITABLE \| JSVM_ENUMERABLE \| JSVM_CONFIGURABLE<br>} | Control over the behavior of JavaScript object properties.| 
| [JSVM_ValueType](#jsvm_valuetype) {<br>JSVM_UNDEFINED, JSVM_NULL, JSVM_BOOLEAN, JSVM_NUMBER,<br>JSVM_STRING, JSVM_SYMBOL, JSVM_OBJECT, JSVM_FUNCTION,<br>JSVM_EXTERNAL, JSVM_BIGINT<br>} | JSVM_Value type.| 
| [JSVM_TypedarrayType](#jsvm_typedarraytype) {<br>JSVM_INT8_ARRAY, JSVM_UINT8_ARRAY, JSVM_UINT8_CLAMPED_ARRAY, JSVM_INT16_ARRAY,<br>JSVM_UINT16_ARRAY, JSVM_INT32_ARRAY, JSVM_UINT32_ARRAY, JSVM_FLOAT32_ARRAY,<br>JSVM_FLOAT64_ARRAY, JSVM_BIGINT64_ARRAY, JSVM_BIGUINT64_ARRAY<br>} | TypedArray type.| 
| [JSVM_Status](#jsvm_status) {<br>JSVM_OK, JSVM_INVALID_ARG, JSVM_OBJECT_EXPECTED, JSVM_STRING_EXPECTED,<br>JSVM_NAME_EXPECTED, JSVM_FUNCTION_EXPECTED, JSVM_NUMBER_EXPECTED, JSVM_BOOLEAN_EXPECTED,<br>JSVM_ARRAY_EXPECTED, JSVM_GENERIC_FAILURE, JSVM_PENDING_EXCEPTION, JSVM_CANCELLED,<br>JSVM_ESCAPE_CALLED_TWICE, JSVM_HANDLE_SCOPE_MISMATCH, JSVM_CALLBACK_SCOPE_MISMATCH, JSVM_QUEUE_FULL,<br>JSVM_CLOSING, JSVM_BIGINT_EXPECTED, JSVM_DATE_EXPECTED, JSVM_ARRAYBUFFER_EXPECTED,<br>JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED, JSVM_WOULD_DEADLOCK, JSVM_NO_EXTERNAL_BUFFERS_ALLOWED, JSVM_CANNOT_RUN_JS<br>} | Complete status code indicating whether the JSVM-API call is successful or fails.| 
| [JSVM_KeyCollectionMode](#jsvm_keycollectionmode) { JSVM_KEY_INCLUDE_PROTOTYPES, JSVM_KEY_OWN_ONLY } | Limited range of properties to be searched for.| 
| [JSVM_KeyFilter](#jsvm_keyfilter) {<br>JSVM_KEY_ALL_PROPERTIES = 0, JSVM_KEY_WRITABLE = 1, JSVM_KEY_ENUMERABLE = 1 &lt;&lt; 1, JSVM_KEY_CONFIGURABLE = 1 &lt;&lt; 2,<br>JSVM_KEY_SKIP_STRINGS = 1 &lt;&lt; 3, JSVM_KEY_SKIP_SYMBOLS = 1 &lt;&lt; 4<br>} | Property filter. You can use OR to construct a composite filter.| 
| [JSVM_KeyConversion](#jsvm_keyconversion) { JSVM_KEY_KEEP_NUMBERS, JSVM_KEY_NUMBERS_TO_STRINGS } | Key conversion options.| 
| [JSVM_MemoryPressureLevel](#jsvm_memorypressurelevel) { JSVM_MEMORY_PRESSURE_LEVEL_NONE, JSVM_MEMORY_PRESSURE_LEVEL_MODERATE, JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL } | Memory pressure level.| 
| [JSVM_RegExpFlags](#jsvm_regexpflags) {<br>JSVM_REGEXP_NONE = 0, JSVM_REGEXP_GLOBAL = 1 &lt;&lt; 0, JSVM_REGEXP_IGNORE_CASE = 1 &lt;&lt; 1, JSVM_REGEXP_MULTILINE = 1 &lt;&lt; 2,<br>JSVM_REGEXP_STICKY = 1 &lt;&lt; 3, JSVM_REGEXP_UNICODE = 1 &lt;&lt; 4, JSVM_REGEXP_DOT_ALL = 1 &lt;&lt; 5, JSVM_REGEXP_LINEAR = 1 &lt;&lt; 6,<br>JSVM_REGEXP_HAS_INDICES = 1 &lt;&lt; 7, JSVM_REGEXP_UNICODE_SETS = 1 &lt;&lt; 8<br>} | Regular expression flags. They can be used to enable a set of flags.| 
| [JSVM_InitializedFlag](#jsvm_initializedflag) { JSVM_ZERO_INITIALIZED, JSVM_UNINITIALIZED } | Initialization flag.| 
| [JSVM_WasmOptLevel](#jsvm_wasmoptlevel) { JSVM_WASM_OPT_BASELINE = 10, JSVM_WASM_OPT_HIGH = 20 } | WebAssembly function optimization level.| 
| [JSVM_CacheType](#jsvm_cachetype) { JSVM_CACHE_TYPE_JS, JSVM_CACHE_TYPE_WASM } | Cache type.| 


### Functions

| Name| Description| 
| -------- | -------- |
| EXTERN_C_START JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_Init](#oh_jsvm_init) (const [JSVM_InitOptions](_j_s_v_m___init_options.md) \*options) | Initializes a JavaScript VM.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateVM](#oh_jsvm_createvm) (const [JSVM_CreateVMOptions](_j_s_v_m___create_v_m_options.md) \*options, [JSVM_VM](#jsvm_vm) \*result) | Creates a VM instance.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_DestroyVM](#oh_jsvm_destroyvm) ([JSVM_VM](#jsvm_vm) vm) | Destroys a VM instance.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_OpenVMScope](#oh_jsvm_openvmscope) ([JSVM_VM](#jsvm_vm) vm, [JSVM_VMScope](#jsvm_vmscope) \*result) | Opens a new VM scope for a VM instance.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CloseVMScope](#oh_jsvm_closevmscope) ([JSVM_VM](#jsvm_vm) vm, [JSVM_VMScope](#jsvm_vmscope) scope) | Closes the VM scope of a VM instance.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateEnv](#oh_jsvm_createenv) ([JSVM_VM](#jsvm_vm) vm, size_t propertyCount, const [JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) \*properties, [JSVM_Env](#jsvm_env) \*result) | Creates a new environment based on the optional properties of the new context.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateEnvFromSnapshot](#oh_jsvm_createenvfromsnapshot) ([JSVM_VM](#jsvm_vm) vm, size_t index, [JSVM_Env](#jsvm_env) \*result) | Creates a new environment based on the startup snapshot of the VM.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_DestroyEnv](#oh_jsvm_destroyenv) ([JSVM_Env](#jsvm_env) env) | Destroys the environment.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_OpenEnvScope](#oh_jsvm_openenvscope) ([JSVM_Env](#jsvm_env) env, [JSVM_EnvScope](#jsvm_envscope) \*result) | Opens a new environment scope.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CloseEnvScope](#oh_jsvm_closeenvscope) ([JSVM_Env](#jsvm_env) env, [JSVM_EnvScope](#jsvm_envscope) scope) | Closes an environment scope.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetVM](#oh_jsvm_getvm) ([JSVM_Env](#jsvm_env) env, [JSVM_VM](#jsvm_vm) \*result) | Gets a VM instance.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CompileScript](#oh_jsvm_compilescript) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) script, const uint8_t \*cachedData, size_t cacheDataLength, bool eagerCompile, bool \*cacheRejected, [JSVM_Script](#jsvm_script) \*result) | Compiles a string of JavaScript code and returns the compiled script.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CompileScriptWithOrigin](#oh_jsvm_compilescriptwithorigin) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) script, const uint8_t \*cachedData, size_t cacheDataLength, bool eagerCompile, bool \*cacheRejected, [JSVM_ScriptOrigin](_j_s_v_m___script_origin.md) \*origin, [JSVM_Script](#jsvm_script) \*result) | Compiles a string of JavaScript code that contains source map information and returns the compiled script.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CompileScriptWithOptions](#oh_jsvm_compilescriptwithoptions) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) script, size_t optionCount, JSVM_CompileOptions options[], [JSVM_Value](#jsvm_value) \*result) | Compiles a string of JavaScript code and returns the compiled script.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateCodeCache](#oh_jsvm_createcodecache) ([JSVM_Env](#jsvm_env) env, [JSVM_Script](#jsvm_script) script, const uint8_t \*\*data, size_t \*length) | Creates a code cache for the compiled script.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_RunScript](#oh_jsvm_runscript) ([JSVM_Env](#jsvm_env) env, [JSVM_Script](#jsvm_script) script, [JSVM_Value](#jsvm_value) \*result) | Runs a string of JavaScript code and returns its result, including the following precautions: Unlike eval, this function does not allow the script to access the current lexical scope, and therefore does not allow the script to access the module scope. This means that pseudo-global variables such as **require** will be unavailable. The script can access the global scope. The functions and variable declarations in the script will be added to the global object. Variable declarations using **let** and **const** are globally visible, but are not added to the global object. The value of **this** is **global** in the script.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_SetInstanceData](#oh_jsvm_setinstancedata) ([JSVM_Env](#jsvm_env) env, void \*data, [JSVM_Finalize](#jsvm_finalize) finalizeCb, void \*finalizeHint) | Sets instance data so that it is associated with the currently running JSVM environment. You can use **OH_JSVM_GetInstanceData()** to get data later. Any existing data set by a previous call to **OH_JSVM_SetInstanceData()** will be overwritten. If **finalizeCb** was previously provided, it will not be called.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetInstanceData](#oh_jsvm_getinstancedata) ([JSVM_Env](#jsvm_env) env, void \*\*data) | Gets instance data that has been set by **OH_JSVM_SetInstanceData()**. If no associated data is set, this function is called successfully and **data** is set to **NULL**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetLastErrorInfo](#oh_jsvm_getlasterrorinfo) ([JSVM_Env](#jsvm_env) env, const [JSVM_ExtendedErrorInfo](_j_s_v_m___extended_error_info.md) \*\*result) | Gets the **JSVM_ExtendedErrorInfo** struct that contains information about the last error that occurred. The content of **JSVM_ExtendedErrorInfo** returned is valid only before the JSVM-API function is called for the same environment. This includes a call to **OH_JSVM_IsExceptionPending**, so you may often need to copy information for later use. The pointer returned in error_message points to a statically defined string, so if you copy it from the error_message field (which will be overwritten) before calling another JSVM-API function, you can safely use the pointer.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_Throw](#oh_jsvm_throw) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) error) | Throws the provided JavaScript value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ThrowError](#oh_jsvm_throwerror) ([JSVM_Env](#jsvm_env) env, const char \*code, const char \*msg) | Throws a JavaScript Error with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ThrowTypeError](#oh_jsvm_throwtypeerror) ([JSVM_Env](#jsvm_env) env, const char \*code, const char \*msg) | Throws a JavaScript TypeError with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ThrowRangeError](#oh_jsvm_throwrangeerror) ([JSVM_Env](#jsvm_env) env, const char \*code, const char \*msg) | Throws a JavaScript RangeError with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ThrowSyntaxError](#oh_jsvm_throwsyntaxerror) ([JSVM_Env](#jsvm_env) env, const char \*code, const char \*msg) | Throws a JavaScript SyntaxError with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsError](#oh_jsvm_iserror) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Checks whether the given JSVM_Value indicates an error.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateError](#oh_jsvm_createerror) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) code, [JSVM_Value](#jsvm_value) msg, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript Error with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateTypeError](#oh_jsvm_createtypeerror) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) code, [JSVM_Value](#jsvm_value) msg, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript TypeError with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateRangeError](#oh_jsvm_createrangeerror) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) code, [JSVM_Value](#jsvm_value) msg, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript RangeError with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateSyntaxError](#oh_jsvm_createsyntaxerror) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) code, [JSVM_Value](#jsvm_value) msg, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript SyntaxError with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetAndClearLastException](#oh_jsvm_getandclearlastexception) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Gets and clears the last exception. If pending occurs, a JavaScript exception is returned. Otherwise, **NULL** is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsExceptionPending](#oh_jsvm_isexceptionpending) ([JSVM_Env](#jsvm_env) env, bool \*result) | Checks whether the last exception is caused by pending. If yes, **true** is returned. Otherwise, **false** is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_OpenHandleScope](#oh_jsvm_openhandlescope) ([JSVM_Env](#jsvm_env) env, [JSVM_HandleScope](#jsvm_handlescope) \*result) | Opens a new scope.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CloseHandleScope](#oh_jsvm_closehandlescope) ([JSVM_Env](#jsvm_env) env, [JSVM_HandleScope](#jsvm_handlescope) scope) | Closes the scope. Scopes must be closed in the reverse order of opening scopes.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_OpenEscapableHandleScope](#oh_jsvm_openescapablehandlescope) ([JSVM_Env](#jsvm_env) env, [JSVM_EscapableHandleScope](#jsvm_escapablehandlescope) \*result) | Opens a new scope from which an object can be escalated to an external scope.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CloseEscapableHandleScope](#oh_jsvm_closeescapablehandlescope) ([JSVM_Env](#jsvm_env) env, [JSVM_EscapableHandleScope](#jsvm_escapablehandlescope) scope) | Closes the scope. Scopes must be closed in the reverse order of opening scopes. This JSVM_API can be called even if there is a suspended JavaScript exception.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_EscapeHandle](#oh_jsvm_escapehandle) ([JSVM_Env](#jsvm_env) env, [JSVM_EscapableHandleScope](#jsvm_escapablehandlescope) scope, [JSVM_Value](#jsvm_value) escapee, [JSVM_Value](#jsvm_value) \*result) | Escalates the handle to a JavaScript object so that it is valid through the lifecycle of the external scope. Each scope can be called only once. If it is called for multiple times, an error is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateReference](#oh_jsvm_createreference) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, uint32_t initialRefcount, [JSVM_Ref](#jsvm_ref) \*result) | Creates a new reference with the specified reference count for the passed-in value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_DeleteReference](#oh_jsvm_deletereference) ([JSVM_Env](#jsvm_env) env, [JSVM_Ref](#jsvm_ref) ref) | Deletes the passed-in reference.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ReferenceRef](#oh_jsvm_referenceref) ([JSVM_Env](#jsvm_env) env, [JSVM_Ref](#jsvm_ref) ref, uint32_t \*result) | Increases the reference count and returns the new reference count.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ReferenceUnref](#oh_jsvm_referenceunref) ([JSVM_Env](#jsvm_env) env, [JSVM_Ref](#jsvm_ref) ref, uint32_t \*result) | Decreases the reference count and returns the new reference count.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetReferenceValue](#oh_jsvm_getreferencevalue) ([JSVM_Env](#jsvm_env) env, [JSVM_Ref](#jsvm_ref) ref, [JSVM_Value](#jsvm_value) \*result) | Gets the JSVM_Value returned by the JSVM-API , indicating the JavaScript value associated with JSVM_Ref. Otherwise, the result is **NULL**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateArray](#oh_jsvm_createarray) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Returns the JSVM-API value corresponding to the JavaScript Array type.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateArrayWithLength](#oh_jsvm_createarraywithlength) ([JSVM_Env](#jsvm_env) env, size_t length, [JSVM_Value](#jsvm_value) \*result) | Returns the JSVM-API value corresponding to the JavaScript Array type. The length attribute of the array is set to the passed-in length parameter. However, there is no guarantee that the underlying buffer is pre-allocated by the VM when the array is created. This behavior is left to the underlying VM implementation.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateArraybuffer](#oh_jsvm_createarraybuffer) ([JSVM_Env](#jsvm_env) env, size_t byteLength, void \*\*data, [JSVM_Value](#jsvm_value) \*result) | Returns the JSVM-API value corresponding to the JavaScript ArrayBuffer type. ArrayBuffer is used to represent a fixed-length binary data buffer. It is usually used as the backup buffer of the TypedArray object. The allocated ArrayBuffer has an underlying byte buffer whose size is determined by the **length** argument. The underlying buffer can be returned to and operated by the caller. This buffer can only be written directly from the native code. To write data from JavaScript to this buffer, you need to create a TypedArray or DataView object.| 
| [JSVM_Status](#jsvm_status) JSVM_CDECL [OH_JSVM_AllocateArrayBufferBackingStoreData](#oh_jsvm_allocatearraybufferbackingstoredata) (size_t byteLength, [JSVM_InitializedFlag](#jsvm_initializedflag) initialized, void \*\*data) | Allocates the BackingStore memory for the array buffer.| 
| [JSVM_Status](#jsvm_status) JSVM_CDECL [OH_JSVM_FreeArrayBufferBackingStoreData](#oh_jsvm_freearraybufferbackingstoredata) (void \*data) | Frees the BackingStore memory allocated by **OH_JSVM_AllocateArrayBufferBackingStoreData**.| 
| [JSVM_Status](#jsvm_status) JSVM_CDECL [OH_JSVM_CreateArrayBufferFromBackingStoreData](#oh_jsvm_createarraybufferfrombackingstoredata) ([JSVM_Env](#jsvm_env) env, void \*data, size_t backingStoreSize, size_t offset, size_t arrayBufferSize, [JSVM_Value](#jsvm_value) \*result) | Creates an array buffer on the allocated BackingStore memory.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateDate](#oh_jsvm_createdate) ([JSVM_Env](#jsvm_env) env, double time, [JSVM_Value](#jsvm_value) \*result) | Allocates a JavaScript Date object. This API does not process leap seconds. This is because ECMAScript complies with the POSIX time specifications and ignores leap seconds.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateExternal](#oh_jsvm_createexternal) ([JSVM_Env](#jsvm_env) env, void \*data, [JSVM_Finalize](#jsvm_finalize) finalizeCb, void \*finalizeHint, [JSVM_Value](#jsvm_value) \*result) | Allocates a JavaScript value with external data. This is used to pass external data through JavaScript code. You can use **OH_JSVM_GetValueExternal** to retrieve the value from the native code. This API adds a **JSVM_Finalize** callback, which is called when the newly created JavaScript object is garbage collected. The created value is not an object, so it does not support additional attributes. It is considered as a unique value type: Calling **OH_JSVM_Typeof()** with an external value generates **JSVM_EXTERNAL**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateObject](#oh_jsvm_createobject) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Allocates a default JavaScript object. This function is equivalent to executing **new Object()** in JavaScript.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateSymbol](#oh_jsvm_createsymbol) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) description, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript symbol value from a UTF8-encoded C string.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_SymbolFor](#oh_jsvm_symbolfor) ([JSVM_Env](#jsvm_env) env, const char \*utf8description, size_t length, [JSVM_Value](#jsvm_value) \*result) | Searches the global registry for an existing symbol with the given description. If the symbol already exists, it is returned. Otherwise, a new symbol is created in the registry.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateTypedarray](#oh_jsvm_createtypedarray) ([JSVM_Env](#jsvm_env) env, [JSVM_TypedarrayType](#jsvm_typedarraytype) type, size_t length, [JSVM_Value](#jsvm_value) arraybuffer, size_t byteOffset, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript TypedArray object based on an existing ArrayBuffer object. The TypedArray object provides an array-like view on the underlying data buffer, where each element has the same underlying binary scalar data type. The requirement is as follows: (length\* Element size) + byteOffset ≤ Size of the passed-in array (in bytes). Otherwise, a RangeError is thrown.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateDataview](#oh_jsvm_createdataview) ([JSVM_Env](#jsvm_env) env, size_t length, [JSVM_Value](#jsvm_value) arraybuffer, size_t byteOffset, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript DataView object based on an existing ArrayBuffer object. The DataView object provides an array-like view on the underlying data buffer, where elements can have different sizes and types. The requirement is as follows: length in binary + byteOffset ≤ Size of the passed-in array (in bytes). Otherwise, a RangeError is thrown.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateInt32](#oh_jsvm_createint32) ([JSVM_Env](#jsvm_env) env, int32_t value, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript number object from a C int32_t object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateUint32](#oh_jsvm_createuint32) ([JSVM_Env](#jsvm_env) env, uint32_t value, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript number object from a C uint32_t object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateInt64](#oh_jsvm_createint64) ([JSVM_Env](#jsvm_env) env, int64_t value, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript number object from a C int64_t object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateDouble](#oh_jsvm_createdouble) ([JSVM_Env](#jsvm_env) env, double value, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript number object from a C double object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateBigintInt64](#oh_jsvm_createbigintint64) ([JSVM_Env](#jsvm_env) env, int64_t value, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript BigInt object from a C int64_t object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateBigintUint64](#oh_jsvm_createbigintuint64) ([JSVM_Env](#jsvm_env) env, uint64_t value, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript BigInt object from a C uint64_t object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateBigintWords](#oh_jsvm_createbigintwords) ([JSVM_Env](#jsvm_env) env, int signBit, size_t wordCount, const uint64_t \*words, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript BigInt value from a group of C uint64_t words.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateStringLatin1](#oh_jsvm_createstringlatin1) ([JSVM_Env](#jsvm_env) env, const char \*str, size_t length, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript string from a C string encoded using ISO-8859-1. Copies a native string.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateStringUtf16](#oh_jsvm_createstringutf16) ([JSVM_Env](#jsvm_env) env, const char16_t \*str, size_t length, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript string from a C string encoded using UTF16-LE. Copies a native string.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateStringUtf8](#oh_jsvm_createstringutf8) ([JSVM_Env](#jsvm_env) env, const char \*str, size_t length, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript string from a C string encoded using UTF8. Copies a native string.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetArrayLength](#oh_jsvm_getarraylength) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, uint32_t \*result) | Gets the length of an array.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetArraybufferInfo](#oh_jsvm_getarraybufferinfo) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) arraybuffer, void \*\*data, size_t \*byteLength) | Gets the underlying data buffer of the ArrayBuffer and its length.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetPrototype](#oh_jsvm_getprototype) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) \*result) | Gets the prototype of an object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetTypedarrayInfo](#oh_jsvm_gettypedarrayinfo) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) typedarray, [JSVM_TypedarrayType](#jsvm_typedarraytype) \*type, size_t \*length, void \*\*data, [JSVM_Value](#jsvm_value) \*arraybuffer, size_t \*byteOffset) | Gets the properties of a typed array. If any property is not required, its output parameter can be **NULL**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetDataviewInfo](#oh_jsvm_getdataviewinfo) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) dataview, size_t \*bytelength, void \*\*data, [JSVM_Value](#jsvm_value) \*arraybuffer, size_t \*byteOffset) | Gets the proprieties of a DataView. If any property is not required, its output parameter can be set to **NULL**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetDateValue](#oh_jsvm_getdatevalue) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, double \*result) | Gets the C double-precision primitive equivalent of a given JavaScript date. If this API is successfully called, **JSVM_OK** is returned. If a JSVM_Value of a non-JavaScript date type is passed in, **JSVM_DATA_EXPECTED** is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueBool](#oh_jsvm_getvaluebool) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Gets the C Boolean primitive equivalent of a given JavaScript Boolean.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueDouble](#oh_jsvm_getvaluedouble) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, double \*result) | Gets the C double-precision primitive equivalent of a given JavaScript number.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueBigintInt64](#oh_jsvm_getvaluebigintint64) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, int64_t \*result, bool \*lossless) | Gets the C int64_t primitive equivalent of a given JavaScript BigInt. If necessary, it truncates the value and sets **lossless** to **false**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueBigintUint64](#oh_jsvm_getvaluebigintuint64) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, uint64_t \*result, bool \*lossless) | Gets the C uint64_t primitive equivalent of a given JavaScript BigInt. If necessary, it truncates the value and sets **lossless** to **false**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueBigintWords](#oh_jsvm_getvaluebigintwords) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, int \*signBit, size_t \*wordCount, uint64_t \*words) | Gets the sign bit, 64-bit little-endian array, and number of elements in the array from a BigInt value. Both **signBit** and **words** can be set to **NULL**. In this case, only **wordCount** is obtained.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueExternal](#oh_jsvm_getvalueexternal) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, void \*\*result) | Gets the external data pointer previously passed to **OH_JSVM_CreateExternal()**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueInt32](#oh_jsvm_getvalueint32) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, int32_t \*result) | Gets the C int32 primitive equivalent of a given JavaScript number.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueInt64](#oh_jsvm_getvalueint64) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, int64_t \*result) | Gets the C int64 primitive equivalent of a given JavaScript number.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueStringLatin1](#oh_jsvm_getvaluestringlatin1) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, char \*buf, size_t bufsize, size_t \*result) | Gets an ISO-8859-1 encoded string corresponding to the passed-in value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueStringUtf8](#oh_jsvm_getvaluestringutf8) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, char \*buf, size_t bufsize, size_t \*result) | Gets a UTF8-encoded string corresponding to the passed-in value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueStringUtf16](#oh_jsvm_getvaluestringutf16) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, char16_t \*buf, size_t bufsize, size_t \*result) | Gets a UTF16-encoded string based on the passed-in value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetValueUint32](#oh_jsvm_getvalueuint32) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, uint32_t \*result) | Gets the C uint_32 primitive equivalent of a given JavaScript number.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetBoolean](#oh_jsvm_getboolean) ([JSVM_Env](#jsvm_env) env, bool value, [JSVM_Value](#jsvm_value) \*result) | Gets a JavaScript singleton object that is used to represent the given Boolean value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetGlobal](#oh_jsvm_getglobal) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Gets the global object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetNull](#oh_jsvm_getnull) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Gets the null object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetUndefined](#oh_jsvm_getundefined) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Gets the undefined object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CoerceToBool](#oh_jsvm_coercetobool) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_Value](#jsvm_value) \*result) | Implements the abstract operation ToBoolean().| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CoerceToNumber](#oh_jsvm_coercetonumber) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_Value](#jsvm_value) \*result) | Implements the abstract operation ToNumber(). If the passed-in value is an object, the function may run JavaScript code.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CoerceToObject](#oh_jsvm_coercetoobject) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_Value](#jsvm_value) \*result) | Implements the abstract operation ToObject().| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CoerceToString](#oh_jsvm_coercetostring) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_Value](#jsvm_value) \*result) | Implements the abstract operation ToString(). If the passed-in value is an object, the function may run JavaScript code.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_Typeof](#oh_jsvm_typeof) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_ValueType](#jsvm_valuetype) \*result) | Provides behavior similar to calling the typeof operator on a defined object. The difference is that this function supports the detection of external values; it detects null as a separate type, while ECMAScript typeof is used to detect objects. If the value type is invalid, an error is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_Instanceof](#oh_jsvm_instanceof) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) constructor, bool \*result) | Provides behavior similar to calling the instanceof operator on an object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsArray](#oh_jsvm_isarray) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Provides behavior similar to calling IsArray on an object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsArraybuffer](#oh_jsvm_isarraybuffer) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Checks whether the passed-in object is ArrayBuffer.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsDate](#oh_jsvm_isdate) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isDate) | Checks whether the passed-in object is a date.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsTypedarray](#oh_jsvm_istypedarray) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Checks whether the passed-in object is a typed array.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsDataview](#oh_jsvm_isdataview) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Checks whether the passed-in object is a DataView.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_StrictEquals](#oh_jsvm_strictequals) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) lhs, [JSVM_Value](#jsvm_value) rhs, bool \*result) | Provides behavior similar to calling the strict equality algorithm.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_Equals](#oh_jsvm_equals) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) lhs, [JSVM_Value](#jsvm_value) rhs, bool \*result) | Provides behavior similar to calling the loose equality algorithm. Regardless of the JavaScript value type, **true** is returned as long as the values are equal.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_DetachArraybuffer](#oh_jsvm_detacharraybuffer) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) arraybuffer) | Provides behavior similar to calling the ArrayBuffer detach operation.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsDetachedArraybuffer](#oh_jsvm_isdetachedarraybuffer) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Provides behavior similar to calling the ArrayBuffer IsDetachedBuffer operation.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetPropertyNames](#oh_jsvm_getpropertynames) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) \*result) | Gets the names of enumerable properties of an object as an array of characters. The properties of the object whose key is a symbol are not included.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetAllPropertyNames](#oh_jsvm_getallpropertynames) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_KeyCollectionMode](#jsvm_keycollectionmode) keyMode, [JSVM_KeyFilter](#jsvm_keyfilter) keyFilter, [JSVM_KeyConversion](#jsvm_keyconversion) keyConversion, [JSVM_Value](#jsvm_value) \*result) | Gets an array containing the names of the available properties of this object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_SetProperty](#oh_jsvm_setproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) key, [JSVM_Value](#jsvm_value) value) | Sets a property for the passed-in object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetProperty](#oh_jsvm_getproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) key, [JSVM_Value](#jsvm_value) \*result) | Gets the requested property from the passed-in object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_HasProperty](#oh_jsvm_hasproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) key, bool \*result) | Checks whether the passed-in object has the property with the specified name.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_DeleteProperty](#oh_jsvm_deleteproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) key, bool \*result) | Deletes the property of the key from the object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_HasOwnProperty](#oh_jsvm_hasownproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) key, bool \*result) | Checks whether the passed-in object has its own property. The key must be a string or symbol. Otherwise, an error is thrown. The JSVM-API does not perform any conversion between data types.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_SetNamedProperty](#oh_jsvm_setnamedproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, const char \*utf8name, [JSVM_Value](#jsvm_value) value) | This method is equivalent to calling **OH_JSVM_SetProperty**, where the JSVM_Value is created using the character string passed through **utf8Name**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetNamedProperty](#oh_jsvm_getnamedproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, const char \*utf8name, [JSVM_Value](#jsvm_value) \*result) | This method is equivalent to calling **OH_JSVM_GetProperty**, where the JSVM_Value is created using the character string passed through **utf8Name**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_HasNamedProperty](#oh_jsvm_hasnamedproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, const char \*utf8name, bool \*result) | This method is equivalent to calling **OH_JSVM_HasProperty**, where the JSVM_Value is created using the character string passed through **utf8Name**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_SetElement](#oh_jsvm_setelement) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, uint32_t index, [JSVM_Value](#jsvm_value) value) | Sets an element on the passed-in object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetElement](#oh_jsvm_getelement) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, uint32_t index, [JSVM_Value](#jsvm_value) \*result) | Gets the element at the requested index.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_HasElement](#oh_jsvm_haselement) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, uint32_t index, bool \*result) | Checks whether an object has an element at the specified index. If yes, the JSVM-API returns **true**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_DeleteElement](#oh_jsvm_deleteelement) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, uint32_t index, bool \*result) | Deletes the element at the specified index from an object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_DefineProperties](#oh_jsvm_defineproperties) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, size_t propertyCount, const [JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) \*properties) | Defines properties on a given object by using property descriptors. Through an array of property descriptors, this API sets the properties in the array in turn for the object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ObjectFreeze](#oh_jsvm_objectfreeze) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object) | Freezes the given object. This prevents additions or deletions of properties, enumerability, configurability, or writeability change of properties, or value change of properties. It also prevents prototype change of an object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ObjectSeal](#oh_jsvm_objectseal) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object) | Seals a specified object. This prevents additions of properties and marks existing properties non-configurable.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CallFunction](#oh_jsvm_callfunction) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) recv, [JSVM_Value](#jsvm_value) func, size_t argc, const [JSVM_Value](#jsvm_value) \*argv, [JSVM_Value](#jsvm_value) \*result) | Supports calling JavaScript function objects from native code, which is the main mechanism for JavaScript to call back from native code.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateFunction](#oh_jsvm_createfunction) ([JSVM_Env](#jsvm_env) env, const char \*utf8name, size_t length, [JSVM_Callback](#jsvm_callback) cb, [JSVM_Value](#jsvm_value) \*result) | Supports creating function objects in native code, which is the main mechanism for JavaScript to call native code. After this call, the newly created function is no longer automatically visible in the script. Instead, the setting property must be displayed on any object visible to JavaScript in order to access the function from the script.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetCbInfo](#oh_jsvm_getcbinfo) ([JSVM_Env](#jsvm_env) env, [JSVM_CallbackInfo](#jsvm_callbackinfo) cbinfo, size_t \*argc, [JSVM_Value](#jsvm_value) \*argv, [JSVM_Value](#jsvm_value) \*thisArg, void \*\*data) | Gets detailed information about the callback, such as the parameter from the given callback information and the **this** pointer.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetNewTarget](#oh_jsvm_getnewtarget) ([JSVM_Env](#jsvm_env) env, [JSVM_CallbackInfo](#jsvm_callbackinfo) cbinfo, [JSVM_Value](#jsvm_value) \*result) | Gets the new target called by the constructor. If the current callback is not a constructor call, the result is **NULL**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_NewInstance](#oh_jsvm_newinstance) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) constructor, size_t argc, const [JSVM_Value](#jsvm_value) \*argv, [JSVM_Value](#jsvm_value) \*result) | Instantiates a new JavaScript value by using the constructor represented by the given JSVM_Value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_DefineClass](#oh_jsvm_defineclass) ([JSVM_Env](#jsvm_env) env, const char \*utf8name, size_t length, [JSVM_Callback](#jsvm_callback) constructor, size_t propertyCount, const [JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) \*properties, [JSVM_Value](#jsvm_value) \*result) | Defines a JavaScript class.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_Wrap](#oh_jsvm_wrap) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsObject, void \*nativeObject, [JSVM_Finalize](#jsvm_finalize) finalizeCb, void \*finalizeHint, [JSVM_Ref](#jsvm_ref) \*result) | Wraps a native instance in the JavaScript object. The native instance can be obtained using **OH_JSVM_Unwrap()**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_Unwrap](#oh_jsvm_unwrap) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsObject, void \*\*result) | When the JavaScript code calls a method of a class or property accessor, the corresponding JSVM_Callback is called. If the callback is for an instance method or accessor, the **this** argument of the callback is the wrapper object. Then you can obtain the C++ instance as the call target by calling **OH_JSVM_Unwrap()** of the wrapper object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_RemoveWrap](#oh_jsvm_removewrap) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsObject, void \*\*result) | Removes the wrap of the native instance, which is previously wrapped in **js_object** by **OH_JSVM_Wrap()**. If the **finalize** callback is associated with wrap, it will not be called when the JavaScript object is garbage collected.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_TypeTagObject](#oh_jsvm_typetagobject) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, const [JSVM_TypeTag](_j_s_v_m___type_tag.md) \*typeTag) | Associates the value of the typeTag pointer with a JavaScript object or an external value. You can call **OH_JSVM_CheckObjectTypeTag()** to check the type of the tag attached to the object, to ensure that the object type is correct. If the object already has an associated type tag, **JSVM_INVALID_ARG** is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CheckObjectTypeTag](#oh_jsvm_checkobjecttypetag) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, const [JSVM_TypeTag](_j_s_v_m___type_tag.md) \*typeTag, bool \*result) | Compares the typeTag with the tag on a JavaScript object or external value. If they are the same tag, **result** is set to **true**. Otherwise, **result** is set to **false**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_AddFinalizer](#oh_jsvm_addfinalizer) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsObject, void \*finalizeData, [JSVM_Finalize](#jsvm_finalize) finalizeCb, void \*finalizeHint, [JSVM_Ref](#jsvm_ref) \*result) | Adds the **JSVM_Finalize** callback to a JavaScript object. This callback is called when the JavaScript object is garbage collected. **OH_JSVM_AddFinalizer** can be called multiple times on a single JavaScript object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetVersion](#oh_jsvm_getversion) ([JSVM_Env](#jsvm_env) env, uint32_t \*result) | Gets the latest JSVM-API version supported by the JSVM runtime. New JSVM-API APIs will be added to support more functions. With this API, the new functions of a certain JSVM version can be used, or callbacks are provided.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetVMInfo](#oh_jsvm_getvminfo) ([JSVM_VMInfo](_j_s_v_m___v_m_info.md) \*result) | Gets the VM information.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_AdjustExternalMemory](#oh_jsvm_adjustexternalmemory) ([JSVM_Env](#jsvm_env) env, int64_t changeInBytes, int64_t \*result) | Notifies the underlying VM of the size of externally allocated memory that remains active due to the JavaScript object. Registering externally allocated memory triggers global garbage collection more frequently than in other ways.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_MemoryPressureNotification](#oh_jsvm_memorypressurenotification) ([JSVM_Env](#jsvm_env) env, [JSVM_MemoryPressureLevel](#jsvm_memorypressurelevel) level) | Notifies the VM of insufficient system memory and selectively triggers garbage collection.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreatePromise](#oh_jsvm_createpromise) ([JSVM_Env](#jsvm_env) env, [JSVM_Deferred](#jsvm_deferred) \*deferred, [JSVM_Value](#jsvm_value) \*promise) | Creates a deferred object and a JavaScript promise.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ResolveDeferred](#oh_jsvm_resolvedeferred) ([JSVM_Env](#jsvm_env) env, [JSVM_Deferred](#jsvm_deferred) deferred, [JSVM_Value](#jsvm_value) resolution) | Resolves a JavaScript promise by using the associated deferred object. It can only be used to resolve the JavaScript promise of the corresponding available deferred object. This means that promise must be created using **OH_JSVM_CreatePromise()**, and the object returned from this call must be retained so that it can be passed to this API.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_RejectDeferred](#oh_jsvm_rejectdeferred) ([JSVM_Env](#jsvm_env) env, [JSVM_Deferred](#jsvm_deferred) deferred, [JSVM_Value](#jsvm_value) rejection) | Rejects a JavaScript promise by using the associated deferred object. It can only be used to reject the JavaScript promise of the corresponding available deferred object. This means that promise must be created using **OH_JSVM_CreatePromise()**, and the object returned from this call must be retained so that it can be passed to this API.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsPromise](#oh_jsvm_ispromise) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isPromise) | Checks whether a promise object is a native promise object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_JsonParse](#oh_jsvm_jsonparse) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsonString, [JSVM_Value](#jsvm_value) \*result) | Parses a JSON string and returns the parsed value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_JsonStringify](#oh_jsvm_jsonstringify) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsonObject, [JSVM_Value](#jsvm_value) \*result) | Converts an object into a JSON string and returns the converted string.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateSnapshot](#oh_jsvm_createsnapshot) ([JSVM_VM](#jsvm_vm) vm, size_t contextCount, const [JSVM_Env](#jsvm_env) \*contexts, const char \*\*blobData, size_t \*blobSize) | Creates a VM startup snapshot.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_GetHeapStatistics](#oh_jsvm_getheapstatistics) ([JSVM_VM](#jsvm_vm) vm, [JSVM_HeapStatistics](_j_s_v_m___heap_statistics.md) \*result) | Gets heap statistics of a VM.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_StartCpuProfiler](#oh_jsvm_startcpuprofiler) ([JSVM_VM](#jsvm_vm) vm, [JSVM_CpuProfiler](#jsvm_cpuprofiler) \*result) | Creates and starts a CPU profiler.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_StopCpuProfiler](#oh_jsvm_stopcpuprofiler) ([JSVM_VM](#jsvm_vm) vm, [JSVM_CpuProfiler](#jsvm_cpuprofiler) profiler, [JSVM_OutputStream](#jsvm_outputstream) stream, void \*streamData) | Stops the CPU profiler and outputs the result to a stream.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_TakeHeapSnapshot](#oh_jsvm_takeheapsnapshot) ([JSVM_VM](#jsvm_vm) vm, [JSVM_OutputStream](#jsvm_outputstream) stream, void \*streamData) | Takes a heap snapshot and outputs it to a stream.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_OpenInspector](#oh_jsvm_openinspector) ([JSVM_Env](#jsvm_env) env, const char \*host, uint16_t port) | Opens an inspector on the specified host and port for debugging JavaScript code.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CloseInspector](#oh_jsvm_closeinspector) ([JSVM_Env](#jsvm_env) env) | Closes all remaining inspector connections.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_WaitForDebugger](#oh_jsvm_waitfordebugger) ([JSVM_Env](#jsvm_env) env, bool breakNextLine) | Waits for the host to set up a socket connection with an inspector. After the connection is set up, the application continues to run. **Runtime.runIfWaitingForDebugger** is sent.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_DefineClassWithPropertyHandler](#oh_jsvm_defineclasswithpropertyhandler) ([JSVM_Env](#jsvm_env) env, const char \*utf8name, size_t length, [JSVM_Callback](#jsvm_callback) constructor, size_t propertyCount, const [JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) \*properties, [JSVM_PropertyHandlerCfg](#jsvm_propertyhandlercfg) propertyHandlerCfg, [JSVM_Callback](#jsvm_callback) callAsFunctionCallback, [JSVM_Value](#jsvm_value) \*result) | Defines a set of JavaScript class property operations including getter(), setter(), deleter(), and enumerator() with the given class name, constructor, properties, and callback handler, which are called as callbacks.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsUndefined](#oh_jsvm_isundefined) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isUndefined) | Checks whether the value passed in is **Undefined**. This API is equivalent to executing JavaScript code **value === undefined**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsNull](#oh_jsvm_isnull) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isNull) | Checks whether the value passed in is a **Null** object. This API is equivalent to executing JavaScript code **value === null**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsNullOrUndefined](#oh_jsvm_isnullorundefined) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isNullOrUndefined) | Checks whether the value passed in is **Null** or **Undefined**. This API is equivalent to executing JavaScript code **value == null**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsBoolean](#oh_jsvm_isboolean) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isBoolean) | Checks whether the value passed in is a Boolean value. This API is equivalent to executing JavaScript code **typeof value === 'boolean'**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsNumber](#oh_jsvm_isnumber) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isNumber) | Checks whether the value passed in is a number. This API is equivalent to executing JavaScript code **typeof value === 'number'**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsString](#oh_jsvm_isstring) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isString) | Checks whether the value passed in is a string. This API is equivalent to executing JavaScript code **typeof value === 'string'**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsSymbol](#oh_jsvm_issymbol) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isSymbol) | Checks whether the value passed in is a symbol. This API is equivalent to executing JavaScript code **typeof value === 'symbol'**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsFunction](#oh_jsvm_isfunction) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isFunction) | Checks whether the value passed in is a function. This API is equivalent to executing JavaScript code **typeof value === 'function'**.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsObject](#oh_jsvm_isobject) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isObject) | Checks whether the value passed in is an object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsBigInt](#oh_jsvm_isbigint) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isBigInt) | Checks whether the value passed in is a BigInt. This API is equivalent to executing JS code **typeof value === 'bigint'**.| 
| [JSVM_Status](#jsvm_status) JSVM_CDECL [OH_JSVM_CreateMap](#oh_jsvm_createmap) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Returns the JavaScript value corresponding to the JavaScript Map type.| 
| [JSVM_Status](#jsvm_status) JSVM_CDECL [OH_JSVM_IsMap](#oh_jsvm_ismap) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isMap) | Checks whether the value passed in is a map.| 
| [JSVM_Status](#jsvm_status) JSVM_CDECL [OH_JSVM_IsConstructor](#oh_jsvm_isconstructor) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isConstructor) | Checks whether the value passed in is a constructor.| 
| [JSVM_Status](#jsvm_status) JSVM_CDECL [OH_JSVM_CreateRegExp](#oh_jsvm_createregexp) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_RegExpFlags](#jsvm_regexpflags) flags, [JSVM_Value](#jsvm_value) \*result) | Returns the JavaScript value of the regular expression corresponding to the input. An exception may be thrown.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ObjectGetPrototypeOf](#oh_jsvm_objectgetprototypeof) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) \*result) | Gets the prototype of a JavaScript object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ObjectSetPrototypeOf](#oh_jsvm_objectsetprototypeof) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) prototype) | Sets the prototype of a JavaScript object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateSet](#oh_jsvm_createset) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript Set object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsSet](#oh_jsvm_isset) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isSet) | Checks whether the specified object is of the Set type.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CoerceToBigInt](#oh_jsvm_coercetobigint) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_Value](#jsvm_value) \*result) | Implements the abstract operation ToBigInt().| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsRegExp](#oh_jsvm_isregexp) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Checks whether the value passed in is a JavaScript RegExp object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateFunctionWithScript](#oh_jsvm_createfunctionwithscript) ([JSVM_Env](#jsvm_env) env, const char \*funcName, size_t length, size_t argc, const [JSVM_Value](#jsvm_value) \*argv, [JSVM_Value](#jsvm_value) script, [JSVM_Value](#jsvm_value) \*result) | Creates a function with the given JavaScript as the function body.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_PumpMessageLoop](#oh_jsvm_pumpmessageloop) ([JSVM_VM](#jsvm_vm) vm, bool \*result) | Starts the running of the task queue in the VM. The task queue can be executed through an external event loop.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_PerformMicrotaskCheckpoint](#oh_jsvm_performmicrotaskcheckpoint) ([JSVM_VM](#jsvm_vm) vm) | Checks whether there are micro tasks waiting in the queue. If yes, execute them.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_RetainScript](#oh_jsvm_retainscript) ([JSVM_Env](#jsvm_env) env, [JSVM_Script](#jsvm_script) script) | Retains a JSVM_Script and extends its lifecycle beyond the current scope.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ReleaseScript](#oh_jsvm_releasescript) ([JSVM_Env](#jsvm_env) env, [JSVM_Script](#jsvm_script) script) | Releases the script retained by **OH_JSVM_RetainScript**. The released script cannot be used again.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_OpenInspectorWithName](#oh_jsvm_openinspectorwithname) ([JSVM_Env](#jsvm_env) env, int pid, const char \*name) | Opens an inspector with the specified **name**, in order to open the UNIX domain port corresponding to the PID.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CompileWasmModule](#oh_jsvm_compilewasmmodule) ([JSVM_Env](#jsvm_env) env, const uint8_t \*wasmBytecode, size_t wasmBytecodeLength, const uint8_t \*cacheData, size_t cacheDataLength, bool \*cacheRejected, [JSVM_Value](#jsvm_value) \*wasmModule) | Compiles WebAssembly bytecode to get a WebAssembly module. If the WebAssembly cache is provided, it will be deserialized first.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CompileWasmFunction](#oh_jsvm_compilewasmfunction) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) wasmModule, uint32_t functionIndex, [JSVM_WasmOptLevel](#jsvm_wasmoptlevel) optLevel) | Compiles the function with the specified index in the WebAssembly module at a specified optimization level.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_IsWasmModuleObject](#oh_jsvm_iswasmmoduleobject) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Checks whether the given JSVM_Value is a WebAssembly module.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_CreateWasmCache](#oh_jsvm_createwasmcache) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) wasmModule, const uint8_t \*\*data, size_t \*length) | Creates a WebAssembly cache.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status) [OH_JSVM_ReleaseCache](#oh_jsvm_releasecache) ([JSVM_Env](#jsvm_env) env, const uint8_t \*cacheData, [JSVM_CacheType](#jsvm_cachetype) cacheType) | Releases the cache of a specified type.| 


## Macro Description


### JSVM_AUTO_LENGTH

```
#define JSVM_AUTO_LENGTH   SIZE_MAX
```

**Description**

Automatic length.

**Since**: 11


## Type Description


### JSVM_Callback

```
typedef JSVM_CallbackStruct* JSVM_Callback
```

**Description**

Pointer types of the native functions provided by user. These functions are exposed to JavaScript via JSVM-API.

**Since**: 11


### JSVM_CallbackInfo

```
typedef struct JSVM_CallbackInfo__* JSVM_CallbackInfo
```

**Description**

An opaque data type passed to the callback. It can be used to obtain additional information about the context in which the function is called.

**Since**: 11


### JSVM_CpuProfiler

```
typedef struct JSVM_CpuProfiler__* JSVM_CpuProfiler
```

**Description**

JavaScript CPU profiler.

**Since**: 12


### JSVM_Deferred

```
typedef struct JSVM_Deferred__* JSVM_Deferred
```

**Description**

Promise deferred object.

**Since**: 11


### JSVM_Env

```
typedef struct JSVM_Env__* JSVM_Env
```

**Description**

Context of a specific VM state. It needs to be passed as a parameter when the native function is called and passed to any subsequent JSVM-API nested invoking.

**Since**: 11


### JSVM_EnvScope

```
typedef struct JSVM_EnvScope__* JSVM_EnvScope
```

**Description**

Environment scope of the current VM instance. The environment is available to the VM instance of the thread only after the thread enters JSVM_EnvScope of the environment through OH_JSVM_OpenEnvScope.

**Since**: 11


### JSVM_EscapableHandleScope

```
typedef struct JSVM_EscapableHandleScope__* JSVM_EscapableHandleScope
```

**Description**

A special type of handle scope, which is used to return the value created in a specific handle scope to the parent scope.

**Since**: 11


### JSVM_Finalize

```
typedef void(JSVM_CDECL* JSVM_Finalize) (JSVM_Env env, void *finalizeData, void *finalizeHint)
```

**Description**

Function pointer type. It is passed in when a native object or data is associated with a JavaScript object. This function is called when the associated JavaScript object is reclaimed by the GC to execute the native cleanup action.

**Since**: 11


### JSVM_HandleScope

```
typedef struct JSVM_HandleScope__* JSVM_HandleScope
```

**Description**

Scope of the JavaScript value. It is used to control and modify the lifecycle of an object created in a specific scope. Typically, the JSVM-API value is created in the context of JSVM_HandleScope. When the native method is called from JavaScript, the default JSVM_HandleScope exists. If the user does not explicitly create a new JSVM_HandleScope, the JSVM-API value is created in the default JSVM_HandleScope. For any code call other than native method execution (for example, libuv callback), the module needs to create a scope before calling any function that may cause JavaScript value creation. JSVM_HandleScope is created using OH_JSVM_OpenHandleScope and destroyed using OH_JSVM_CloseHandleScope. Closing the scope represents indicating to the GC that all JSVM_Values created during the lifecycle of JSVM_HandleScope will no longer be referenced from the stack frame of the current heap.

**Since**: 11


### JSVM_OutputStream

```
typedef bool(JSVM_CDECL* JSVM_OutputStream) (const char *data, int size, void *streamData)
```

**Description**

Pointer to the callback of the ASCII output stream. **data** indicates the pointer to the output data. **size** indicates the size of the output data. **void** points to the end of the stream. **streamData** indicates the pointer passed to the API function together with the callback. The API function generates data to the output stream. If **true** is returned, the stream can continue to receive data. Otherwise, it aborts the stream.

**Since**: 12


### JSVM_PropertyHandlerCfg

```
typedef JSVM_PropertyHandlerConfigurationStruct* JSVM_PropertyHandlerCfg
```

**Description**

Pointer type of the struct that contains the property listening callback.

**Since**: 12


### JSVM_Ref

```
typedef struct JSVM_Ref__* JSVM_Ref
```

**Description**

Reference to the JavaScript value.

**Since**: 11


### JSVM_Script

```
typedef struct JSVM_Script__* JSVM_Script
```

**Description**

JavaScript code.

**Since**: 11


### JSVM_Value

```
typedef struct JSVM_Value__* JSVM_Value
```

**Description**

JavaScript value.

**Since**: 11


### JSVM_VM

```
typedef struct JSVM_VM__* JSVM_VM
```

**Description**

JavaScript VM instance.

**Since**: 11


### JSVM_VMScope

```
typedef struct JSVM_VMScope__* JSVM_VMScope
```

**Description**

JavaScript VM scope.

**Since**: 11


## Enum Description


### JSVM_CacheType

```
enum JSVM_CacheType
```

**Description**

Cache type.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| JSVM_CACHE_TYPE_JS | JavaScript cache, which is generated by **OH_JSVM_CreateCodeCache**.| 
| JSVM_CACHE_TYPE_WASM | WebAssembly cache, which is generated by **OH_JSVM_CreateWasmCache**.| 


### JSVM_InitializedFlag

```
enum JSVM_InitializedFlag
```

**Description**

Initialization flag.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| JSVM_ZERO_INITIALIZED | Initialized to 0.| 
| JSVM_UNINITIALIZED | No initialization.| 


### JSVM_KeyCollectionMode

```
enum JSVM_KeyCollectionMode
```

**Description**

Limited range of properties to be searched for.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_KEY_INCLUDE_PROTOTYPES | Includes properties on the prototype chain of the object.| 
| JSVM_KEY_OWN_ONLY | Includes only the object's own properties.| 


### JSVM_KeyConversion

```
enum JSVM_KeyConversion
```

**Description**

Key conversion options.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_KEY_KEEP_NUMBERS | Gets the numbers of integer indexes.| 
| JSVM_KEY_NUMBERS_TO_STRINGS | Converts integer indexes to strings.| 


### JSVM_KeyFilter

```
enum JSVM_KeyFilter
```

**Description**

Property filter. You can use OR to construct a composite filter.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_KEY_ALL_PROPERTIES | Key of all properties.| 
| JSVM_KEY_WRITABLE | Writable key.| 
| JSVM_KEY_ENUMERABLE | Enumerable key.| 
| JSVM_KEY_CONFIGURABLE | Configurable key.| 
| JSVM_KEY_SKIP_STRINGS | Key that skips strings.| 
| JSVM_KEY_SKIP_SYMBOLS | Key that skips symbols.| 


### JSVM_MemoryPressureLevel

```
enum JSVM_MemoryPressureLevel
```

**Description**

Memory pressure level.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_MEMORY_PRESSURE_LEVEL_NONE | No pressure.| 
| JSVM_MEMORY_PRESSURE_LEVEL_MODERATE | Moderate pressure.| 
| JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL | Critical pressure.| 


### JSVM_PropertyAttributes

```
enum JSVM_PropertyAttributes
```

**Description**

Control over the behavior of JavaScript object properties.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_DEFAULT | No explicit attribute set on the property.| 
| JSVM_WRITABLE | Writable property.| 
| JSVM_ENUMERABLE | Enumerable property.| 
| JSVM_CONFIGURABLE | Configurable property.| 
| JSVM_STATIC | Static property of the class, instead of the default instance property. Used only by **OH_JSVM_DefineClass**.| 
| JSVM_DEFAULT_METHOD | Configurable, writable, but not enumerable property, like a method in a JavaScript class.| 
| JSVM_DEFAULT_JSPROPERTY | Writable, enumerable, and configurable property, like a property set by value assignment in JavaScript.| 


### JSVM_RegExpFlags

```
enum JSVM_RegExpFlags
```

**Description**

Regular expression flags. They can be used to enable a set of flags.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| JSVM_REGEXP_NONE | None mode.| 
| JSVM_REGEXP_GLOBAL | Global mode.| 
| JSVM_REGEXP_IGNORE_CASE | Ignore Case mode.| 
| JSVM_REGEXP_MULTILINE | Multiline mode.| 
| JSVM_REGEXP_STICKY | Sticky mode.| 
| JSVM_REGEXP_UNICODE | Unicode mode.| 
| JSVM_REGEXP_DOT_ALL | dotAll mode.| 
| JSVM_REGEXP_LINEAR | Linear mode.| 
| JSVM_REGEXP_HAS_INDICES | Has Indices mode.| 
| JSVM_REGEXP_UNICODE_SETS | Unicode Sets mode.| 


### JSVM_Status

```
enum JSVM_Status
```

**Description**

Complete status code indicating whether the JSVM-API call is successful or fails.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_OK | Successful.| 
| JSVM_INVALID_ARG | Invalid.| 
| JSVM_OBJECT_EXPECTED | Object expected.| 
| JSVM_STRING_EXPECTED | String expected.| 
| JSVM_NAME_EXPECTED | Name expected.| 
| JSVM_FUNCTION_EXPECTED | Function expected.| 
| JSVM_NUMBER_EXPECTED | Number expected.| 
| JSVM_BOOLEAN_EXPECTED | Boolean expected.| 
| JSVM_ARRAY_EXPECTED | Array expected.| 
| JSVM_GENERIC_FAILURE | Generic failure.| 
| JSVM_PENDING_EXCEPTION | Pending exception.| 
| JSVM_CANCELLED | Canceled.| 
| JSVM_ESCAPE_CALLED_TWICE | Escape called twice.| 
| JSVM_HANDLE_SCOPE_MISMATCH | Handle scope mismatch.| 
| JSVM_CALLBACK_SCOPE_MISMATCH | Callback scope mismatch.| 
| JSVM_QUEUE_FULL | Full queue.| 
| JSVM_CLOSING | Closing.| 
| JSVM_BIGINT_EXPECTED | Bigint expected.| 
| JSVM_DATE_EXPECTED | Date expected.| 
| JSVM_ARRAYBUFFER_EXPECTED | ArrayBuffer expected.| 
| JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED | Detachable array buffer expected.| 
| JSVM_WOULD_DEADLOCK | Would be in deadlock.| 
| JSVM_NO_EXTERNAL_BUFFERS_ALLOWED | No external buffers allowed.| 
| JSVM_CANNOT_RUN_JS | Cannot run JavaSript.| 


### JSVM_TypedarrayType

```
enum JSVM_TypedarrayType
```

**Description**

TypedArray type.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_INT8_ARRAY | int8 type.| 
| JSVM_UINT8_ARRAY | uint8 type.| 
| JSVM_UINT8_CLAMPED_ARRAY | Fixed uint8 type.| 
| JSVM_INT16_ARRAY | int16 type.| 
| JSVM_UINT16_ARRAY | uint16 type.| 
| JSVM_INT32_ARRAY | int32 type.| 
| JSVM_UINT32_ARRAY | uint32 type.| 
| JSVM_FLOAT32_ARRAY | Float32 type.| 
| JSVM_FLOAT64_ARRAY | float64 type.| 
| JSVM_BIGINT64_ARRAY | bigint64 type.| 
| JSVM_BIGUINT64_ARRAY | biguint64 type.| 


### JSVM_ValueType

```
enum JSVM_ValueType
```

**Description**

JSVM_Value type.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_UNDEFINED | Unknown.| 
| JSVM_NULL | Null.| 
| JSVM_BOOLEAN | Boolean.| 
| JSVM_NUMBER | Number.| 
| JSVM_STRING | String.| 
| JSVM_SYMBOL | Symbol.| 
| JSVM_OBJECT | Object.| 
| JSVM_FUNCTION | Function.| 
| JSVM_EXTERNAL | External.| 
| JSVM_BIGINT | BigInt.| 


### JSVM_WasmOptLevel

```
enum JSVM_WasmOptLevel
```

**Description**

WebAssembly function optimization level.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| JSVM_WASM_OPT_BASELINE | Baseline optimization level.| 
| JSVM_WASM_OPT_HIGH | High optimization level.| 


## Function Description


### OH_JSVM_AddFinalizer()

```
JSVM_EXTERN JSVM_Status OH_JSVM_AddFinalizer (JSVM_Env env, JSVM_Value jsObject, void * finalizeData, JSVM_Finalize finalizeCb, void * finalizeHint, JSVM_Ref * result )
```

**Description**

Adds the **JSVM_Finalize** callback to a JavaScript object. This callback is called when the JavaScript object is garbage collected. **OH_JSVM_AddFinalizer** can be called multiple times on a single JavaScript object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| jsObject | JavaScript object associated with native data.| 
| finalizeData | Optional data to be passed to **finalizeCb**.| 
| finalizeCb | Native callback used to release native data when a JavaScript object is garbage collected. **JSVM_Finalize** provides more details.| 
| finalizeHint | Optional context hint passed to the **finalize** callback.| 
| result | Optional reference to a JavaScript object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_AdjustExternalMemory()

```
JSVM_EXTERN JSVM_Status OH_JSVM_AdjustExternalMemory (JSVM_Env env, int64_t changeInBytes, int64_t * result )
```

**Description**

Notifies the underlying VM of the size of externally allocated memory that remains active due to the JavaScript object. Registering externally allocated memory triggers global garbage collection more frequently than in other ways.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| changeInBytes | Change in the size of externally allocated memory that remains active due to the JavaScript object.| 
| result | Adjustment value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_AllocateArrayBufferBackingStoreData()

```
JSVM_Status JSVM_CDECL OH_JSVM_AllocateArrayBufferBackingStoreData (size_t byteLength, JSVM_InitializedFlag initialized, void ** data )
```

**Description**

Allocates the BackingStore memory for the array buffer.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| byteLength | Size of the BackingStore memory.| 
| initialized | Mode of initializing the BackingStore memory.| 
| data | Pointer to the address of allocated BackingStore memory.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates that **data** is a null pointer.

**JSVM_GENERIC_FAILURE** indicates memory allocation failure.


### OH_JSVM_CallFunction()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CallFunction (JSVM_Env env, JSVM_Value recv, JSVM_Value func, size_t argc, const JSVM_Value * argv, JSVM_Value * result )
```

**Description**

Supports calling JavaScript function objects from native code, which is the main mechanism for JavaScript to call back from native code.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| recv | Value of **this** passed to the callee.| 
| func | JavaScript function to be called.| 
| argc | Number of elements in the **argv** array.| 
| argv | JSVM_values array, representing the JavaScript values to be passed to the function as arguments.| 
| result | Returned JavaScript object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_PENDING_EXCEPTION** indicates that a JavaScript exception occurs during the execution.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_CheckObjectTypeTag()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CheckObjectTypeTag (JSVM_Env env, JSVM_Value value, const JSVM_TypeTag * typeTag, bool * result )
```

**Description**

Compares the typeTag with the tag on a JavaScript object or external value. If they are the same tag, **result** is set to **true**. Otherwise, **result** is set to **false**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript object or external value of the type tag to be checked.| 
| typeTag | Tag used to compare any tags found on an object.| 
| result | Indicating whether the specified type tag matches the type tag on the object. If the same type tag cannot be found on the object, **false** is returned.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_CloseEnvScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CloseEnvScope (JSVM_Env env, JSVM_EnvScope scope )
```

**Description**

Closes an environment scope.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Target environment in which the JSVM-API will be called.| 
| scope | Environment scope to be closed.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CloseEscapableHandleScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CloseEscapableHandleScope (JSVM_Env env, JSVM_EscapableHandleScope scope )
```

**Description**

Closes the scope. Scopes must be closed in the reverse order of opening scopes. This JSVM_API can be called even if there is a suspended JavaScript exception.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| scope | Scope to be closed.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_HANDLE_SCOPE_MISMATCH** indicates execution failure.


### OH_JSVM_CloseHandleScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CloseHandleScope (JSVM_Env env, JSVM_HandleScope scope )
```

**Description**

Closes the scope. Scopes must be closed in the reverse order of opening scopes.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| scope | Scope to be closed.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CloseInspector()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CloseInspector (JSVM_Env env)
```

**Description**

Closes all remaining inspector connections.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CloseVMScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CloseVMScope (JSVM_VM vm, JSVM_VMScope scope )
```

**Description**

Closes the VM scope of a VM instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | Target VM instance.| 
| scope | VM scope to be stopped.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CoerceToBigInt()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToBigInt (JSVM_Env env, JSVM_Value value, JSVM_Value * result )
```

**Description**

Implements the abstract operation ToBigInt().

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be forcibly converted.| 
| result | JavaScript value that is successfully converted to a BigInt type.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_BIGINT_EXPECTED** indicates that the passed-in JavaScript value is now not of the BitInt type.


### OH_JSVM_CoerceToBool()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToBool (JSVM_Env env, JSVM_Value value, JSVM_Value * result )
```

**Description**

Implements the abstract operation ToBoolean().

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be forcibly converted.| 
| result | Forced JavaScript Boolean.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CoerceToNumber()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToNumber (JSVM_Env env, JSVM_Value value, JSVM_Value * result )
```

**Description**

Implements the abstract operation ToNumber(). If the passed-in value is an object, the function may run JavaScript code.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be forcibly converted.| 
| result | Forced JavaScript number.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CoerceToObject()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToObject (JSVM_Env env, JSVM_Value value, JSVM_Value * result )
```

**Description**

Implements the abstract operation ToObject().

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be forcibly converted.| 
| result | Forced JavaScript object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CoerceToString()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToString (JSVM_Env env, JSVM_Value value, JSVM_Value * result )
```

**Description**

Implements the abstract operation ToString(). If the passed-in value is an object, the function may run JavaScript code.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be forcibly converted.| 
| result | Forced JavaScript string.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CompileScript()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CompileScript (JSVM_Env env, JSVM_Value script, const uint8_t * cachedData, size_t cacheDataLength, bool eagerCompile, bool * cacheRejected, JSVM_Script * result )
```

**Description**

Compiles a string of JavaScript code and returns the compiled script.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Target environment in which the JSVM-API will be called.| 
| script | JavaScript code that includes the script to be compiled.| 
| cachedData | Optional. Code cache data of the script.| 
| cacheDataLength | Length of the cachedData array.| 
| eagerCompile | Whether to compile the script immediately.| 
| cacheRejected | Whether the code cache is rejected by compilation.| 
| result | Compiled script.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_CompileScriptWithOptions()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CompileScriptWithOptions (JSVM_Env env, JSVM_Value script, size_t optionCount, JSVM_CompileOptions options[], JSVM_Value * result )
```

**Description**

Compiles a string of JavaScript code and returns the compiled script.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Target environment in which the JSVM-API will be called.| 
| script | JavaScript code that includes the script to be compiled.| 
| optionCount | Length of the passed-in option array.| 
| options | Option array, which stores all compilation options.| 
| result | Compiled script.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_CompileScriptWithOrigin()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CompileScriptWithOrigin (JSVM_Env env, JSVM_Value script, const uint8_t * cachedData, size_t cacheDataLength, bool eagerCompile, bool * cacheRejected, JSVM_ScriptOrigin * origin, JSVM_Script * result )
```

**Description**

Compiles a string of JavaScript code that contains source map information and returns the compiled script.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Target environment in which the JSVM-API will be called.| 
| script | JavaScript code that includes the script to be compiled.| 
| cachedData | Optional. Code cache data of the script.| 
| cacheDataLength | Length of the cachedData array.| 
| eagerCompile | Whether to compile the script immediately.| 
| cacheRejected | Whether the code cache is rejected by compilation.| 
| origin | Source code information, including the source map location and source code file name.| 
| result | Compiled script.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.

**JSVM_GENERIC_FAILURE** indicates execution failure.


### OH_JSVM_CompileWasmFunction()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CompileWasmFunction (JSVM_Env env, JSVM_Value wasmModule, uint32_t functionIndex, JSVM_WasmOptLevel optLevel )
```

**Description**

Compiles the function with the specified index in the WebAssembly module at a specified optimization level.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| wasmModule | WebAssembly module where the function to be compiled is located.| 
| functionIndex | Index of the function to be compiled. The index must be within the valid range.| 
| optLevel | Optimization level. Currently, only the high optimization level is supported.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates that the **env** or **wasmModule** argument is null, or **wasmModule** is not a real WebAssembly module.

**JSVM_GENERIC_FAILURE** indicates that the function index is out of range or the compilation fails.

**JSVM_PENDING_EXCEPTION** indicates that an exception occurs.


### OH_JSVM_CompileWasmModule()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CompileWasmModule (JSVM_Env env, const uint8_t * wasmBytecode, size_t wasmBytecodeLength, const uint8_t * cacheData, size_t cacheDataLength, bool * cacheRejected, JSVM_Value * wasmModule )
```

**Description**

Compiles WebAssembly bytecode to get a WebAssembly module. If the WebAssembly cache is provided, it will be deserialized first.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| wasmBytecode | WebAssembly bytecode.| 
| wasmBytecodeLength | Length of the WebAssembly bytecode, in bytes.| 
| cacheData | Optional WebAssembly cache.| 
| cacheDataLength | Optional WebAssembly cache length, in bytes.| 
| cacheRejected | Output parameter, indicating whether the provided WebAssembly cache is rejected by the engine.| 
| wasmModule | Output parameter, which indicates the generated WebAssembly module.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates that the **env** or **wasmBytecode** argument is null, or the data length argument passed in is invalid.

**JSVM_GENERIC_FAILURE** indicates that the compilation fails.

**JSVM_PENDING_EXCEPTION** indicates that an exception occurs.


### OH_JSVM_CreateArray()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateArray (JSVM_Env env, JSVM_Value * result )
```

**Description**

Returns the JSVM-API value corresponding to the JavaScript Array type.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | JSVM_Value of the JavaScript array.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateArraybuffer()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateArraybuffer (JSVM_Env env, size_t byteLength, void ** data, JSVM_Value * result )
```

**Description**

Returns the JSVM-API value corresponding to the JavaScript ArrayBuffer type. ArrayBuffer is used to represent a fixed-length binary data buffer. It is usually used as the backup buffer of the TypedArray object. The allocated ArrayBuffer has an underlying byte buffer whose size is determined by the **length** argument. The underlying buffer can be returned to and operated by the caller. This buffer can only be written directly from the native code. To write data from JavaScript to this buffer, you need to create a TypedArray or DataView object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| byteLength | Length of the array buffer to be created, in bytes.| 
| data | Pointer to the underlying byte buffer of the ArrayBuffer. **data** can be ignored by passing **NULL** to it.| 
| result | JSVM_Value of the JavaScript ArrayBuffer.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateArrayBufferFromBackingStoreData()

```
JSVM_Status JSVM_CDECL OH_JSVM_CreateArrayBufferFromBackingStoreData (JSVM_Env env, void * data, size_t backingStoreSize, size_t offset, size_t arrayBufferSize, JSVM_Value * result )
```

**Description**

Creates an array buffer on the allocated BackingStore memory.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| data | Allocated BackingStore memory.| 
| backingStoreSize | Size of the BackingStore memory.| 
| offset | Relative offset between the start position of the array buffer in the memory and the memory header, in bytes.| 
| arrayBufferSize | Size of the array buffer, in bytes.| 
| result | Pointer to the array buffer address| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates that one of the following exceptions is triggered:

1. offset + arrayBufferSize &gt; backingStoreSize

2. backingStoreSize or arrayBufferSize = 0

3. **data** or **result** is null.


### OH_JSVM_CreateArrayWithLength()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateArrayWithLength (JSVM_Env env, size_t length, JSVM_Value * result )
```

**Description**

Returns the JSVM-API value corresponding to the JavaScript Array type. The length attribute of the array is set to the passed-in length parameter. However, there is no guarantee that the underlying buffer is pre-allocated by the VM when the array is created. This behavior is left to the underlying VM implementation.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| length | Initial length of the array.| 
| result | JSVM_Value of the JavaScript array.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateBigintInt64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateBigintInt64 (JSVM_Env env, int64_t value, JSVM_Value * result )
```

**Description**

Creates a JavaScript BigInt object from a C int64_t object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | Integer value to be represented in JavaScript.| 
| result | JSVM_Value of the JavaScript BigInt type.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateBigintUint64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateBigintUint64 (JSVM_Env env, uint64_t value, JSVM_Value * result )
```

**Description**

Creates a JavaScript BigInt object from a C uint64_t object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | Unsigned integer value to be represented in JavaScript.| 
| result | JSVM_Value of the JavaScript BigInt type.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateBigintWords()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateBigintWords (JSVM_Env env, int signBit, size_t wordCount, const uint64_t * words, JSVM_Value * result )
```

**Description**

Creates a JavaScript BigInt value from a group of C uint64_t words.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| signBit | Whether the generated BigInt is positive or negative.| 
| wordCount | Length of the words array.| 
| words | uint64_t little-endian words array.| 
| result | JSVM_Value of the JavaScript BigInt type.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_CreateCodeCache()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateCodeCache (JSVM_Env env, JSVM_Script script, const uint8_t ** data, size_t * length )
```

**Description**

Creates a code cache for the compiled script.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Target environment in which the JSVM-API will be called.| 
| script | Target compilation script.| 
| data | Code cache data| 
| length | Length of the code cache data.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure.


### OH_JSVM_CreateDataview()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateDataview (JSVM_Env env, size_t length, JSVM_Value arraybuffer, size_t byteOffset, JSVM_Value * result )
```

**Description**

Creates a JavaScript DataView object based on an existing ArrayBuffer object. The DataView object provides an array-like view on the underlying data buffer, where elements can have different sizes and types. The requirement is as follows: length in binary + byteOffset ≤ Size of the passed-in array (in bytes). Otherwise, a RangeError is thrown.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| length | Number of elements in a DataView.| 
| arraybuffer | ArrayBuffer at the bottom layer of the DataView.| 
| byteOffset | Byte offset in the ArrayBuffer, indicating the start position of mapping a DataView.| 
| result | JSVM_Value of the JavaScript DataView object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateDate()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateDate (JSVM_Env env, double time, JSVM_Value * result )
```

**Description**

Allocates a JavaScript Date object. This API does not process leap seconds. This is because ECMAScript complies with the POSIX time specifications and ignores leap seconds.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| time | ECMAScript time since 00:00:00 UTC on January 1, 1970, in milliseconds.| 
| result | JSVM_Value of the JavaScript Date object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure.


### OH_JSVM_CreateDouble()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateDouble (JSVM_Env env, double value, JSVM_Value * result )
```

**Description**

Creates a JavaScript number object from a C double object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | Double-precision value to be represented in JavaScript.| 
| result | JSVM_Value of the JavaScript number type.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateEnv()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateEnv (JSVM_VM vm, size_t propertyCount, const JSVM_PropertyDescriptor * properties, JSVM_Env * result )
```

**Description**

Creates a new environment based on the optional properties of the new context.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | VM instance, in which the new environment will be created.| 
| propertyCount | Number of elements in the property array.| 
| properties | Array of property descriptors.| 
| result | New environment.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateEnvFromSnapshot()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateEnvFromSnapshot (JSVM_VM vm, size_t index, JSVM_Env * result )
```

**Description**

Creates a new environment based on the startup snapshot of the VM.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | VM instance, in which the new environment will be created.| 
| index | Index of the environment in the snapshot.| 
| result | New environment.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_CreateError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateError (JSVM_Env env, JSVM_Value code, JSVM_Value msg, JSVM_Value * result )
```

**Description**

Creates a JavaScript Error with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| code | (Optional) JSVM_Value, which is a string with the associated error code.| 
| msg | Message that references the JavaScript string as an error.| 
| result | Created error.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.


### OH_JSVM_CreateExternal()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateExternal (JSVM_Env env, void * data, JSVM_Finalize finalizeCb, void * finalizeHint, JSVM_Value * result )
```

**Description**

Allocates a JavaScript value with external data. This is used to pass external data through JavaScript code. You can use **OH_JSVM_GetValueExternal** to retrieve the value from the native code. This API adds a **JSVM_Finalize** callback, which is called when the newly created JavaScript object is garbage collected. The created value is not an object, so it does not support additional attributes. It is considered as a unique value type: Calling **OH_JSVM_Typeof()** with an external value generates **JSVM_EXTERNAL**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| data | Raw pointer to external data.| 
| finalizeCb | Optional callback called to collect external values. **JSVM_Finalize** provides more details.| 
| finalizeHint | Optional hint passed to the **finalize** callback during collection.| 
| result | JSVM_Value of an external value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateFunction()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateFunction (JSVM_Env env, const char * utf8name, size_t length, JSVM_Callback cb, JSVM_Value * result )
```

**Description**

Supports creating function objects in native code, which is the main mechanism for JavaScript to call native code. After this call, the newly created function is no longer automatically visible in the script. Instead, the setting property must be displayed on any object visible to JavaScript in order to access the function from the script.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| utf8Name | Optional name of the function encoded as UTF8. This is visible in JavaScript as the name property of the new function object.| 
| length | Length of **utf8name** (in bytes) or **JSVM_AUTO_LENGTH** (if null-terminated).| 
| cb | Native function that needs to be called when the function object is called. For details, see **JSVM_Callback**.| 
| result | JavaScript function object of the new function.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateFunctionWithScript()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateFunctionWithScript (JSVM_Env env, const char * funcName, size_t length, size_t argc, const JSVM_Value * argv, JSVM_Value script, JSVM_Value * result )
```

**Description**

Creates a function with the given JavaScript as the function body.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| funcName | A string containing the function name. If **NULL** is passed to it, an anonymous function is created.| 
| length | Length of **funcName** (in bytes) or **JSVM_AUTO_LENGTH** (if null-terminated).| 
| argc | Number of elements in the argv array.| 
| argv | JSVM_values array, representing the JavaScript values to be passed to the function as arguments.| 
| script | JavaScript string that is used as the function body.| 
| result | JSVM_Value of the JavaScript function object of the newly created function.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates that the passed-in JavaScript fails to be compiled.


### OH_JSVM_CreateInt32()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateInt32 (JSVM_Env env, int32_t value, JSVM_Value * result )
```

**Description**

Creates a JavaScript number object from a C int32_t object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | Integer value to be represented in JavaScript.| 
| result | JSVM_Value of the JavaScript number type.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateInt64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateInt64 (JSVM_Env env, int64_t value, JSVM_Value * result )
```

**Description**

Creates a JavaScript number object from a C int64_t object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | Integer value to be represented in JavaScript.| 
| result | JSVM_Value of the JavaScript number type.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateMap()

```
JSVM_Status JSVM_CDECL OH_JSVM_CreateMap (JSVM_Env env, JSVM_Value * result )
```

**Description**

Returns the JavaScript value corresponding to the JavaScript Map type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | JSVM_Value of the JavaScript map.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_CreateObject()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateObject (JSVM_Env env, JSVM_Value * result )
```

**Description**

Allocates a default JavaScript object. This function is equivalent to executing **new Object()** in JavaScript.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | JSVM_Value of the JavaScript object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreatePromise()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreatePromise (JSVM_Env env, JSVM_Deferred * deferred, JSVM_Value * promise )
```

**Description**

Creates a deferred object and a JavaScript promise.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| deferred | New deferred object, which can be passed to **OH_JSVM_ResolveDeferred()** or [OH_JSVM_RejectDeferred()](#oh_jsvm_rejectdeferred) to resolve **resp**. or reject the promise.| 
| promise | JavaScript promise associated with the deferred object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_CreateRangeError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateRangeError (JSVM_Env env, JSVM_Value code, JSVM_Value msg, JSVM_Value * result )
```

**Description**

Creates a JavaScript RangeError with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| code | (Optional) JSVM_Value, which is a string with the associated error code.| 
| msg | Message that references the JavaScript string as an error.| 
| result | Created error.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.


### OH_JSVM_CreateReference()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateReference (JSVM_Env env, JSVM_Value value, uint32_t initialRefcount, JSVM_Ref * result )
```

**Description**

Creates a new reference with the specified reference count for the passed-in value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value for which a reference is being created.| 
| initialRefcount | Initial reference count of a new reference.| 
| result | Points to a new reference.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateRegExp()

```
JSVM_Status JSVM_CDECL OH_JSVM_CreateRegExp (JSVM_Env env, JSVM_Value value, JSVM_RegExpFlags flags, JSVM_Value * result )
```

**Description**

Returns the JavaScript value of the regular expression corresponding to the input. An exception may be thrown.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript string to be converted to a regular expression.| 
| flags | Regular expression flags.| 
| result | JSVM_Value of JavaScript RegExp.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.

**JSVM_PENDING_EXCPTION** indicates that an exception is thrown during API running.


### OH_JSVM_CreateSet()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateSet (JSVM_Env env, JSVM_Value * result )
```

**Description**

Creates a JavaScript Set object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | Created JavaScript Set object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_CreateSnapshot()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateSnapshot (JSVM_VM vm, size_t contextCount, const JSVM_Env * contexts, const char ** blobData, size_t * blobSize )
```

**Description**

Creates a VM startup snapshot.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | Target environment in which the API will be called.| 
| contextCount | Number of contexts.| 
| contexts | Array of contexts to be added to the snapshot.| 
| blobData | Snapshot data.| 
| blobSize | Size of snapshot data.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_CreateStringLatin1()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateStringLatin1 (JSVM_Env env, const char * str, size_t length, JSVM_Value * result )
```

**Description**

Creates a JavaScript string from a C string encoded using ISO-8859-1. Copies a native string.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| str | Buffer of an ISO-8859-1-encoded string.| 
| length | Length of a string, in bytes. If it is null-terminated, the value is **JSVM_AUTO_LENGTH**.| 
| result | JSVM_Value of the JavaScript string.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateStringUtf16()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateStringUtf16 (JSVM_Env env, const char16_t * str, size_t length, JSVM_Value * result )
```

**Description**

Creates a JavaScript string from a C string encoded using UTF16-LE. Copies a native string.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| str | Buffer of a UTF16-LE-encoded string.| 
| length | Length of a string in 2-byte code. If it is null-terminated, the value is **JSVM_AUTO_LENGTH**.| 
| result | JSVM_Value of the JavaScript string.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateStringUtf8()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateStringUtf8 (JSVM_Env env, const char * str, size_t length, JSVM_Value * result )
```

**Description**

Creates a JavaScript string from a C string encoded using UTF8. Copies a native string.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| str | Buffer of a UTF8-encoded string.| 
| length | Length of a string, in bytes. If it is null-terminated, the value is **JSVM_AUTO_LENGTH**.| 
| result | JSVM_Value of the JavaScript string.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateSymbol()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateSymbol (JSVM_Env env, JSVM_Value description, JSVM_Value * result )
```

**Description**

Creates a JavaScript symbol value from a UTF8-encoded C string.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| description | Optional JSVM_Value, which refers to the JavaScript string to be set to the symbol description.| 
| result | JSVM_Value of the JavaScript symbol.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.


### OH_JSVM_CreateSyntaxError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateSyntaxError (JSVM_Env env, JSVM_Value code, JSVM_Value msg, JSVM_Value * result )
```

**Description**

Creates a JavaScript SyntaxError with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| code | (Optional) JSVM_Value, which is a string with the associated error code.| 
| msg | Message that references the JavaScript string as an error.| 
| result | Created error.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.

\*


### OH_JSVM_CreateTypedarray()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateTypedarray (JSVM_Env env, JSVM_TypedarrayType type, size_t length, JSVM_Value arraybuffer, size_t byteOffset, JSVM_Value * result )
```

**Description**

Creates a JavaScript TypedArray object based on an existing ArrayBuffer object. The TypedArray object provides an array-like view on the underlying data buffer, where each element has the same underlying binary scalar data type. The requirement is as follows: (length\* Element size) + byteOffset ≤ Size of the passed-in array (in bytes). Otherwise, a RangeError is thrown.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| type | Scalar data type of an element in TypedArray.| 
| length | Number of elements in TypedArray.| 
| arraybuffer | ArrayBuffer, which is the basis of TypedArray.| 
| byteOffset | Byte offset for the start position of mapping TypedArray in the ArrayBuffer.| 
| result | JSVM_Value of the JavaScript TypedArray.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_CreateTypeError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateTypeError (JSVM_Env env, JSVM_Value code, JSVM_Value msg, JSVM_Value * result )
```

**Description**

Creates a JavaScript TypeError with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| code | (Optional) JSVM_Value, which is a string with the associated error code.| 
| msg | Message that references the JavaScript string as an error.| 
| result | Created error.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.


### OH_JSVM_CreateUint32()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateUint32 (JSVM_Env env, uint32_t value, JSVM_Value * result )
```

**Description**

Creates a JavaScript number object from a C uint32_t object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | Unsigned integer value to be represented in JavaScript.| 
| result | JSVM_Value of the JavaScript number type.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_CreateVM()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateVM (const JSVM_CreateVMOptions * options, JSVM_VM * result )
```

**Description**

Creates a VM instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Options for creating a VM instance.| 
| result | New VM instance.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_CreateWasmCache()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateWasmCache (JSVM_Env env, JSVM_Value wasmModule, const uint8_t ** data, size_t * length )
```

**Description**

Creates a WebAssembly cache.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| wasmModule | Compiled WebAssembly module.| 
| data | Output parameter, indicating the generated WebAssembly cache.| 
| length | Output parameter, indicating the length of the generated WebAssembly cache, in bytes.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates a null pointer argument.

**JSVM_GENERIC_FAILURE** indicates cache generation failure.


### OH_JSVM_DefineClass()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DefineClass (JSVM_Env env, const char * utf8name, size_t length, JSVM_Callback constructor, size_t propertyCount, const JSVM_PropertyDescriptor * properties, JSVM_Value * result )
```

**Description**

Defines a JavaScript class.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| utf8name | Name of the JavaScript constructor. You are advised to use the C++ class name when wrapping a C++ class.| 
| length | Length of **utf8name** (in bytes) or **JSVM_AUTO_LENGTH** (if null-terminated).| 
| constructor | Callback used to create the constructor of a class. When a C++ class is wrapped, this method must comply with **JSVM_Callback**. It is a static member of the callback signature. C++ class constructors cannot be used. For details, see **JSVM_Callback**.| 
| propertyCount | Number of items in the properties array.| 
| properties | Attribute descriptor of a class, which is used to define the properties and methods of the class.| 
| result | JSVM_Value of the constructor of a class.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_DefineClassWithPropertyHandler()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DefineClassWithPropertyHandler (JSVM_Env env, const char * utf8name, size_t length, JSVM_Callback constructor, size_t propertyCount, const JSVM_PropertyDescriptor * properties, JSVM_PropertyHandlerCfg propertyHandlerCfg, JSVM_Callback callAsFunctionCallback, JSVM_Value * result )
```

**Description**

Defines a set of JavaScript class property operations including getter(), setter(), deleter(), and enumerator() with the given class name, constructor, properties, and callback handler, which are called as callbacks.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| utf8name | Name of the JavaScript class constructor.| 
| length | Length of **utf8name** (in bytes) or **JSVM_AUTO_LENGTH** (if null-terminated).| 
| constructor | Callback used to create the constructor of a class. This method must be of the **JSVM_Callback** type. The callback in the constructor must be a static member. C++ class constructors cannot be used. For details, see **JSVM_Callback**.| 
| propertyCount | Number of items in the properties array.| 
| properties | Properties, accessors, and methods of the property descriptor array class of static data and instance data. For details, see **JSVM_PropertyDescriptor**.| 
| propertyHandlerCfg | Callback triggered when an instance object property is accessed.| 
| callAsFunctionCallback | Callback triggered when an instance object is called as a function.| 
| result | JSVM_Value of the constructor of a JavaScript class.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_DefineProperties()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DefineProperties (JSVM_Env env, JSVM_Value object, size_t propertyCount, const JSVM_PropertyDescriptor * properties )
```

**Description**

Defines properties on a given object by using property descriptors. Through an array of property descriptors, this API sets the properties in the array in turn for the object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object whose properties are to be searched for.| 
| propertyCount | Number of elements in the properties array.| 
| properties | Array of property descriptors.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_DeleteElement()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DeleteElement (JSVM_Env env, JSVM_Value object, uint32_t index, bool * result )
```

**Description**

Deletes the element at the specified index from an object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object to be queried.| 
| index | Index of the property to be deleted.| 
| result | Whether an element is successfully deleted.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_DeleteProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DeleteProperty (JSVM_Env env, JSVM_Value object, JSVM_Value key, bool * result )
```

**Description**

Deletes the property of the key from the object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object to be queried.| 
| key | Name of the property to be deleted.| 
| result | Whether the property is successfully deleted. **result** can be ignored by passing **NULL** to it.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_DeleteReference()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DeleteReference (JSVM_Env env, JSVM_Ref ref )
```

**Description**

Deletes the passed-in reference.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| ref | JSVM_Ref to be deleted.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_DestroyEnv()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DestroyEnv (JSVM_Env env)
```

**Description**

Destroys the environment.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment to be destroyed.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_DestroyVM()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DestroyVM (JSVM_VM vm)
```

**Description**

Destroys a VM instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | VM instance to be destroyed.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_DetachArraybuffer()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DetachArraybuffer (JSVM_Env env, JSVM_Value arraybuffer )
```

**Description**

Provides behavior similar to calling the ArrayBuffer detach operation.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| arraybuffer | JavaScript ArrayBuffer to be detached.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED** indicates that the argument is not analyzable ArrayBuffer.


### OH_JSVM_Equals()

```
JSVM_EXTERN JSVM_Status OH_JSVM_Equals (JSVM_Env env, JSVM_Value lhs, JSVM_Value rhs, bool * result )
```

**Description**

Provides behavior similar to calling the loose equality algorithm. Regardless of the JavaScript value type, **true** is returned as long as the values are equal.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| lhs | JavaScript value to be checked.| 
| rhs | JavaScript value to be checked.| 
| result | Whether two JSVM_Value objects are equal.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_EscapeHandle()

```
JSVM_EXTERN JSVM_Status OH_JSVM_EscapeHandle (JSVM_Env env, JSVM_EscapableHandleScope scope, JSVM_Value escapee, JSVM_Value * result )
```

**Description**

Escalates the handle to a JavaScript object so that it is valid through the lifecycle of the external scope. Each scope can be called only once. If it is called for multiple times, an error is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| scope | Current scope.| 
| escapee | JavaScript object to be escalated.| 
| result | Handle to the escalated object in the external scope.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_ESCAPE_CALLED_TWICE** indicates that the scope object has been closed.


### OH_JSVM_FreeArrayBufferBackingStoreData()

```
JSVM_Status JSVM_CDECL OH_JSVM_FreeArrayBufferBackingStoreData (void * data)
```

**Description**

Frees the BackingStore memory allocated by **OH_JSVM_AllocateArrayBufferBackingStoreData**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| data | Allocated BackingStore memory.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates that **data** is a null pointer.


### OH_JSVM_GetAllPropertyNames()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetAllPropertyNames (JSVM_Env env, JSVM_Value object, JSVM_KeyCollectionMode keyMode, JSVM_KeyFilter keyFilter, JSVM_KeyConversion keyConversion, JSVM_Value * result )
```

**Description**

Gets an array containing the names of the available properties of this object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object from which the properties are retrieved.| 
| keyMode | Whether to retrieve the prototype properties.| 
| keyFilter | Properties to be retrieved (enumerated/readable/writable).| 
| keyConversion | Whether to convert a number property key to a string.| 
| result | An array of JavaScript values, which are the property names of an object. You can use **OH_JSVM_GetArrayLength** and **OH_JSVM_GetElement** to iterate the result.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_GetAndClearLastException()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetAndClearLastException (JSVM_Env env, JSVM_Value * result )
```

**Description**

Gets and clears the last exception. If pending occurs, a JavaScript exception is returned. Otherwise, **NULL** is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | An exception is returned if pending occurs. Otherwise, **NULL** is returned.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetArraybufferInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetArraybufferInfo (JSVM_Env env, JSVM_Value arraybuffer, void ** data, size_t * byteLength )
```

**Description**

Gets the underlying data buffer of the ArrayBuffer and its length.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| arraybuffer | ArrayBuffer to be queried.| 
| data | Underlying data buffer of the ArrayBuffer. If **byte_length** is **0**, the value may be **NULL** or any other pointer value.| 
| byteLength | Length of the underlying data buffer, in bytes.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_GetArrayLength()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetArrayLength (JSVM_Env env, JSVM_Value value, uint32_t * result )
```

**Description**

Gets the length of an array.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript array whose length is to be queried.| 
| result | uint32 indicates the array length.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_ARRAY_EXPECTED** indicates that the argument is not an array.


### OH_JSVM_GetBoolean()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetBoolean (JSVM_Env env, bool value, JSVM_Value * result )
```

**Description**

Gets a JavaScript singleton object that is used to represent the given Boolean value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | Boolean value to be retrieved.| 
| result | JavaScript Boolean singleton to be retrieved.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetCbInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetCbInfo (JSVM_Env env, JSVM_CallbackInfo cbinfo, size_t * argc, JSVM_Value * argv, JSVM_Value * thisArg, void ** data )
```

**Description**

Gets detailed information about the callback, such as the parameter from the given callback information and the **this** pointer.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| cbinfo | Callback information.| 
| argc | Used to specify the length of the provided **argv** array and receive the actual number of arguments. **argc** can be ignored by passing **NULL** to it.| 
| argv | C array of JSVM_Value, which is used to store copied arguments. If the number of arguments exceeds the provided number, only a requested number of arguments are copied. If fewer parameters are provided than declared, the rest of **argv** is filled with undefined JSVM_Values. **argv** can be ignored by passing **NULL** to it.| 
| thisArg | JavaScript **this** argument. **thisArg** can be ignored by passing **NULL** to it.| 
| data | Pointer to the callback data. **data** can be ignored by passing **NULL** to it.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetDataviewInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetDataviewInfo (JSVM_Env env, JSVM_Value dataview, size_t * bytelength, void ** data, JSVM_Value * arraybuffer, size_t * byteOffset )
```

**Description**

Gets the proprieties of a DataView. If any property is not required, its output parameter can be set to **NULL**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| dataview | DataView whose properties are to be queried.| 
| bytelength | Number of bytes in a DataView.| 
| data | Data buffer in a DataView. If **bytelength** is **0**, this value may be **NULL** or any other pointer value.| 
| arraybuffer | ArrayBuffer, which is the basis of DataView.| 
| byteOffset | Byte offset for the start position of mapping DataView in the data buffer.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_GetDateValue()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetDateValue (JSVM_Env env, JSVM_Value value, double * result )
```

**Description**

Gets the C double-precision primitive equivalent of a given JavaScript date. If this API is successfully called, **JSVM_OK** is returned. If a JSVM_Value of a non-JavaScript date type is passed in, **JSVM_DATA_EXPECTED** is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript date.| 
| result | Time value of the double type, expressed as the number of milliseconds since 00:00:00 UTC on January 1, 1970.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_DATE_EXPECTED** indicates that the argument is not a date.


### OH_JSVM_GetElement()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetElement (JSVM_Env env, JSVM_Value object, uint32_t index, JSVM_Value * result )
```

**Description**

Gets the element at the requested index.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object whose property is to be searched for.| 
| index | Index of the property to be obtained.| 
| result | Property value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_GetGlobal()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetGlobal (JSVM_Env env, JSVM_Value * result )
```

**Description**

Gets the global object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | JavaScript global object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetHeapStatistics()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetHeapStatistics (JSVM_VM vm, JSVM_HeapStatistics * result )
```

**Description**

Gets heap statistics of a VM.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | VM that returns heap statistics.| 
| result | Heap statistics.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetInstanceData()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetInstanceData (JSVM_Env env, void ** data )
```

**Description**

Gets instance data that has been set by **OH_JSVM_SetInstanceData()**. If no associated data is set, this function is called successfully and **data** is set to **NULL**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| data | Data that has been by **OH_JSVM_SetInstanceData()**, associated with the current JSVM environment.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetLastErrorInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetLastErrorInfo (JSVM_Env env, const JSVM_ExtendedErrorInfo ** result )
```

**Description**

Gets the **JSVM_ExtendedErrorInfo** struct that contains information about the last error that occurred. The content of **JSVM_ExtendedErrorInfo** returned is valid only before the JSVM-API function is called for the same environment. This includes a call to **OH_JSVM_IsExceptionPending**, so you may often need to copy information for later use. The pointer returned in error_message points to a statically defined string, so if you copy it from the error_message field (which will be overwritten) before calling another JSVM-API function, you can safely use the pointer.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | JSVM_ExtendedErrorInfo struct that contains more information about the error.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetNamedProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetNamedProperty (JSVM_Env env, JSVM_Value object, const char * utf8name, JSVM_Value * result )
```

**Description**

This method is equivalent to calling **OH_JSVM_GetProperty**, where the JSVM_Value is created using the character string passed through **utf8Name**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object from which the property is retrieved.| 
| utf8Name | Name of the property to be obtained.| 
| result | Property value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_GetNewTarget()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetNewTarget (JSVM_Env env, JSVM_CallbackInfo cbinfo, JSVM_Value * result )
```

**Description**

Gets the new target called by the constructor. If the current callback is not a constructor call, the result is **NULL**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| cbinfo | Callback information.| 
| result | New target called by the constructor.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetNull()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetNull (JSVM_Env env, JSVM_Value * result )
```

**Description**

Gets the null object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | JavaScript null object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetProperty (JSVM_Env env, JSVM_Value object, JSVM_Value key, JSVM_Value * result )
```

**Description**

Gets the requested property from the passed-in object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object from which the property is retrieved.| 
| key | Name of the property to be retrieved.| 
| result | Property value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_GetPropertyNames()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetPropertyNames (JSVM_Env env, JSVM_Value object, JSVM_Value * result )
```

**Description**

Gets the names of enumerable properties of an object as an array of characters. The properties of the object whose key is a symbol are not included.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object whose property is to be searched for.| 
| result | An array of JavaScript values, which are the property names of an object. You can use **OH_JSVM_GetArrayLength** and **OH_JSVM_GetElement** to iterate the result.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetPrototype()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetPrototype (JSVM_Env env, JSVM_Value object, JSVM_Value * result )
```

**Description**

Gets the prototype of an object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | JavaScript object whose prototype is to be returned. This will return the equivalent of **Object.getPrototypeOf** (different from the prototype property of the function).| 
| result | Prototype of a given object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetReferenceValue()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetReferenceValue (JSVM_Env env, JSVM_Ref ref, JSVM_Value * result )
```

**Description**

Gets the JSVM_Value returned by the JSVM-API , indicating the JavaScript value associated with JSVM_Ref. Otherwise, the result is **NULL**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| ref | JSVM_Ref for requesting the corresponding value.| 
| result | JSVM_Value referenced by JSVM_Ref.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetTypedarrayInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetTypedarrayInfo (JSVM_Env env, JSVM_Value typedarray, JSVM_TypedarrayType * type, size_t * length, void ** data, JSVM_Value * arraybuffer, size_t * byteOffset )
```

**Description**

Gets the properties of a typed array. If any property is not required, its output parameter can be **NULL**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| typedarray | TypedArray whose properties are to be queried.| 
| type | Scalar data type of an element in TypedArray.| 
| length | Number of elements in the TypedArray.| 
| data | The underlying data buffer of the TypedArray is adjusted by byte_offset so that it points to the first element in the TypedArray. If the array length is **0**, **data** may be NULL or any other pointer value.| 
| arraybuffer | ArrayBuffer under TypedArray.| 
| byteOffset | Byte offset of the first TypedArray element in the native array. **data** points to the first element in the array after its value has been adjusted. Therefore, the first byte of the native array is located at (data – byte_offset).| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_GetUndefined()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetUndefined (JSVM_Env env, JSVM_Value * result )
```

**Description**

Gets the undefined object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript undefined value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetValueBigintInt64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBigintInt64 (JSVM_Env env, JSVM_Value value, int64_t * result, bool * lossless )
```

**Description**

Gets the C int64_t primitive equivalent of a given JavaScript BigInt. If necessary, it truncates the value and sets **lossless** to **false**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript BigInt.| 
| result | C int64_t primitive equivalent of the given JavaScript BigInt.| 
| lossless | Whether the BigInt value has been losslessly converted.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_BIGINT_EXPECTED** indicates that the argument is not a BitInt.


### OH_JSVM_GetValueBigintUint64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBigintUint64 (JSVM_Env env, JSVM_Value value, uint64_t * result, bool * lossless )
```

**Description**

Gets the C uint64_t primitive equivalent of a given JavaScript BigInt. If necessary, it truncates the value and sets **lossless** to **false**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript BigInt.| 
| result | C uint64_t primitive equivalent of the given JavaScript BigInt.| 
| lossless | Whether the BigInt value has been losslessly converted.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_BIGINT_EXPECTED** indicates that the argument is not a BitInt.


### OH_JSVM_GetValueBigintWords()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBigintWords (JSVM_Env env, JSVM_Value value, int * signBit, size_t * wordCount, uint64_t * words )
```

**Description**

Gets the sign bit, 64-bit little-endian array, and number of elements in the array from a BigInt value. Both **signBit** and **words** can be set to **NULL**. In this case, only **wordCount** is obtained.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript BigInt.| 
| signBit | Whether JavaScript BigInt is a positive or negative integer.| 
| wordCount | Length of the words array. It will be set to the actual number of words required to store this BigInt.| 
| words | Pointer to the pre-allocated 64-bit words array.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_BIGINT_EXPECTED** indicates that the argument is not a BitInt.


### OH_JSVM_GetValueBool()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBool (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Gets the C Boolean primitive equivalent of a given JavaScript Boolean.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript Boolean.| 
| result | C Boolean primitive equivalent of a given JavaScript Boolean.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_BOOLEAN_EXPECTED** indicates that the argument is not a Boolean.


### OH_JSVM_GetValueDouble()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueDouble (JSVM_Env env, JSVM_Value value, double * result )
```

**Description**

Gets the C double-precision primitive equivalent of a given JavaScript number.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript number.| 
| result | C double-precision primitive equivalent of a given JavaScript number.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_NUMBER_EXPECTED** indicates that the argument is not a number.


### OH_JSVM_GetValueExternal()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueExternal (JSVM_Env env, JSVM_Value value, void ** result )
```

**Description**

Gets the external data pointer previously passed to **OH_JSVM_CreateExternal()**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript external value.| 
| result | Pointer to the data wrapped by the JavaScript external value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates that the argument is not an external JSVM_Value.


### OH_JSVM_GetValueInt32()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueInt32 (JSVM_Env env, JSVM_Value value, int32_t * result )
```

**Description**

Gets the C int32 primitive equivalent of a given JavaScript number.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript number.| 
| result | C int32 primitive equivalent of a given JavaScript number.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_NUMBER_EXPECTED** indicates that the argument is not a number.


### OH_JSVM_GetValueInt64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueInt64 (JSVM_Env env, JSVM_Value value, int64_t * result )
```

**Description**

Gets the C int64 primitive equivalent of a given JavaScript number.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript number.| 
| result | C int64 primitive equivalent of a given JavaScript number.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_NUMBER_EXPECTED** indicates that the argument is not a number.


### OH_JSVM_GetValueStringLatin1()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueStringLatin1 (JSVM_Env env, JSVM_Value value, char * buf, size_t bufsize, size_t * result )
```

**Description**

Gets an ISO-8859-1 encoded string corresponding to the passed-in value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript number.| 
| buf | Buffer to which an ISO-8859-1 encoded string is written. If **NULL** is passed, the length of the string (in bytes, excluding the null terminator) is returned in **result**.| 
| bufsize | Size of the destination buffer. If the size is insufficient, the returned string is truncated and terminated with null.| 
| result | Number of bytes copied to the buffer, excluding the null terminator.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.


### OH_JSVM_GetValueStringUtf16()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueStringUtf16 (JSVM_Env env, JSVM_Value value, char16_t * buf, size_t bufsize, size_t * result )
```

**Description**

Gets a UTF16-encoded string based on the passed-in value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript string.| 
| buf | Buffer to which a UTF16-LE-encoded string is written. If **NULL** is passed, the length of the string in 2-byte code is returned, excluding the null terminator.| 
| bufsize | Size of the destination buffer. If the size is insufficient, the returned string is truncated and terminated with null.| 
| result | Number of the 2-byte code units copied to the buffer, excluding the null terminator.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.


### OH_JSVM_GetValueStringUtf8()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueStringUtf8 (JSVM_Env env, JSVM_Value value, char * buf, size_t bufsize, size_t * result )
```

**Description**

Gets a UTF8-encoded string corresponding to the passed-in value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript string.| 
| buf | Buffer to which a UTF8-encoded string is written. If **NULL** is passed, the length of the string in bytes is returned in **result**, excluding the null terminator.| 
| bufsize | Size of the destination buffer. If the size is insufficient, the returned string is truncated and terminated with null.| 
| result | Number of bytes copied to the buffer, excluding the null terminator.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.


### OH_JSVM_GetValueUint32()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueUint32 (JSVM_Env env, JSVM_Value value, uint32_t * result )
```

**Description**

Gets the C uint_32 primitive equivalent of a given JavaScript number.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript number.| 
| result | C uint32_t primitive equivalent of a given JSVM_Value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_NUMBER_EXPECTED** indicates that the argument is not a number.


### OH_JSVM_GetVersion()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetVersion (JSVM_Env env, uint32_t * result )
```

**Description**

Gets the latest JSVM-API version supported by the JSVM runtime. New JSVM-API APIs will be added to support more functions. With this API, the new functions of a certain JSVM version can be used, or callbacks are provided.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | JSVM-API of the latest version.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetVM()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetVM (JSVM_Env env, JSVM_VM * result )
```

**Description**

Gets a VM instance.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Target environment in which the JSVM-API will be called.| 
| result | VM instance of the specified environment.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_GetVMInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetVMInfo (JSVM_VMInfo * result)
```

**Description**

Gets the VM information.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| result | VM information.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_HasElement()

```
JSVM_EXTERN JSVM_Status OH_JSVM_HasElement (JSVM_Env env, JSVM_Value object, uint32_t index, bool * result )
```

**Description**

Checks whether an object has an element at the specified index. If yes, the JSVM-API returns **true**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object to be queried.| 
| index | Index where there is an element.| 
| result | Whether the property exists on the object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_HasNamedProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_HasNamedProperty (JSVM_Env env, JSVM_Value object, const char * utf8name, bool * result )
```

**Description**

This method is equivalent to calling **OH_JSVM_HasProperty**, where the JSVM_Value is created using the character string passed through **utf8Name**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object to be queried.| 
| utf8Name | Name of the property to be checked.| 
| result | Whether the property exists on the object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_HasOwnProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_HasOwnProperty (JSVM_Env env, JSVM_Value object, JSVM_Value key, bool * result )
```

**Description**

Checks whether the passed-in object has its own property. The key must be a string or symbol. Otherwise, an error is thrown. The JSVM-API does not perform any conversion between data types.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object to be queried.| 
| key | Name of the object's own property to be checked.| 
| result | Whether an object has this own property.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_HasProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_HasProperty (JSVM_Env env, JSVM_Value object, JSVM_Value key, bool * result )
```

**Description**

Checks whether the passed-in object has the property with the specified name.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object to be queried.| 
| key | Name of the property to be checked.| 
| result | Whether the property exists on the object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_Init()

```
EXTERN_C_START JSVM_EXTERN JSVM_Status OH_JSVM_Init (const JSVM_InitOptions * options)
```

**Description**

Initializes a JavaScript VM.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Options for initializing the JavaScript VM.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_Instanceof()

```
JSVM_EXTERN JSVM_Status OH_JSVM_Instanceof (JSVM_Env env, JSVM_Value object, JSVM_Value constructor, bool * result )
```

**Description**

Provides behavior similar to calling the instanceof operator on an object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be checked.| 
| constructor | JavaScript function object of the constructor to be checked.| 
| result | **true** is returned if the object instanceof constructor is **true**.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_FUNCTION_EXPECTED** indicates that the argument is not a function.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_IsArray()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsArray (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Provides behavior similar to calling IsArray on an object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be checked.| 
| result | Whether the given object is an array.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_IsArraybuffer()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsArraybuffer (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Checks whether the passed-in object is ArrayBuffer.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be checked.| 
| result | Whether the specified object is ArrayBuffer.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_IsBigInt()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsBigInt (JSVM_Env env, JSVM_Value value, bool * isBigInt )
```

**Description**

Checks whether the value passed in is a BigInt. This API is equivalent to executing JS code **typeof value === 'bigint'**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isBigInt | Whether the given JSVM_Value is a BigInt.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success. This API does not trigger any exception.


### OH_JSVM_IsBoolean()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsBoolean (JSVM_Env env, JSVM_Value value, bool * isBoolean )
```

**Description**

Checks whether the value passed in is a Boolean value. This API is equivalent to executing JavaScript code **typeof value === 'boolean'**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isBoolean | Whether the given JSVM_Value is Boolean.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success. This API does not trigger any exception.


### OH_JSVM_IsConstructor()

```
JSVM_Status JSVM_CDECL OH_JSVM_IsConstructor (JSVM_Env env, JSVM_Value value, bool * isConstructor )
```

**Description**

Checks whether the value passed in is a constructor.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isConstructor | Whether the given value is a constructor.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_IsDataview()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsDataview (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Checks whether the passed-in object is a DataView.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be checked.| 
| result | Whether the given JSVM_Value is a DataView.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_IsDate()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsDate (JSVM_Env env, JSVM_Value value, bool * isDate )
```

**Description**

Checks whether the passed-in object is a date.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be checked.| 
| isDate | Whether the given JSVM_Value is a JavaScript Date object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_IsDetachedArraybuffer()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsDetachedArraybuffer (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Provides behavior similar to calling the ArrayBuffer IsDetachedBuffer operation.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript ArrayBuffer to be checked.| 
| result | Whether the ArrayBuffer is detached.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_IsError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsError (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Checks whether the given JSVM_Value indicates an error.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| result | If JSVM_Value indicates an error, **true** is returned. Otherwise, **false** is returned.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_IsExceptionPending()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsExceptionPending (JSVM_Env env, bool * result )
```

**Description**

Checks whether the last exception is caused by pending. If yes, **true** is returned. Otherwise, **false** is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | **true** is returned if pending occurs.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_IsFunction()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsFunction (JSVM_Env env, JSVM_Value value, bool * isFunction )
```

**Description**

Checks whether the value passed in is a function. This API is equivalent to executing JavaScript code **typeof value === 'function'**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isFunction | Whether the given JSVM_Value is a function.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success. This API does not trigger any exception.


### OH_JSVM_IsMap()

```
JSVM_Status JSVM_CDECL OH_JSVM_IsMap (JSVM_Env env, JSVM_Value value, bool * isMap )
```

**Description**

Checks whether the value passed in is a map.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isMap | Whether the given value is a map.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_IsNull()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsNull (JSVM_Env env, JSVM_Value value, bool * isNull )
```

**Description**

Checks whether the value passed in is a **Null** object. This API is equivalent to executing JavaScript code **value === null**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isNull | Whether the given JSVM_Value is **Null**.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success. This API does not trigger any exception.


### OH_JSVM_IsNullOrUndefined()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsNullOrUndefined (JSVM_Env env, JSVM_Value value, bool * isNullOrUndefined )
```

**Description**

Checks whether the value passed in is **Null** or **Undefined**. This API is equivalent to executing JavaScript code **value == null**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isNullOrUndefined | Whether the given JSVM_Value is **Null** or **Undefined**.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success. This API does not trigger any exception.


### OH_JSVM_IsNumber()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsNumber (JSVM_Env env, JSVM_Value value, bool * isNumber )
```

**Description**

Checks whether the value passed in is a number. This API is equivalent to executing JavaScript code **typeof value === 'number'**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isNumber | Whether the given JSVM_Value is a number.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success. This API does not trigger any exception.


### OH_JSVM_IsObject()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsObject (JSVM_Env env, JSVM_Value value, bool * isObject )
```

**Description**

Checks whether the value passed in is an object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isObject | Whether the given JSVM_Value is an object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success. This API does not trigger any exception.


### OH_JSVM_IsPromise()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsPromise (JSVM_Env env, JSVM_Value value, bool * isPromise )
```

**Description**

Checks whether a promise object is a native promise object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | Value to be checked.| 
| isPromise | Flag of a native promise object (that is, a promise object created by the underlying engine).| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_IsRegExp()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsRegExp (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Checks whether the value passed in is a JavaScript RegExp object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| result | Whether the given JSVM_Value is a JavaScript RegExp object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_IsSet()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsSet (JSVM_Env env, JSVM_Value value, bool * isSet )
```

**Description**

Checks whether the specified object is of the Set type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | Object to be checked.| 
| isSet | Whether the specified object is of the Set type.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_IsString()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsString (JSVM_Env env, JSVM_Value value, bool * isString )
```

**Description**

Checks whether the value passed in is a string. This API is equivalent to executing JavaScript code **typeof value === 'string'**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isString | Whether the given JSVM_Value is a string.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success. This API does not trigger any exception.


### OH_JSVM_IsSymbol()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsSymbol (JSVM_Env env, JSVM_Value value, bool * isSymbol )
```

**Description**

Checks whether the value passed in is a symbol. This API is equivalent to executing JavaScript code **typeof value === 'symbol'**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isSymbol | Whether the given JSVM_Value is a symbol.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success. This API does not trigger any exception.


### OH_JSVM_IsTypedarray()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsTypedarray (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Checks whether the passed-in object is a typed array.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be checked.| 
| result | Whether the given JSVM_Value is a TypedArray.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_IsUndefined()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsUndefined (JSVM_Env env, JSVM_Value value, bool * isUndefined )
```

**Description**

Checks whether the value passed in is **Undefined**. This API is equivalent to executing JavaScript code **value === undefined**.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| isUndefined | Whether the given JSVM_Value is **Undefined**.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success. This API does not trigger any exception.


### OH_JSVM_IsWasmModuleObject()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsWasmModuleObject (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Checks whether the given JSVM_Value is a WebAssembly module.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value to be checked.| 
| result | Output parameter, indicating whether the given value is a WebAssembly module.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates a null pointer argument.


### OH_JSVM_JsonParse()

```
JSVM_EXTERN JSVM_Status OH_JSVM_JsonParse (JSVM_Env env, JSVM_Value jsonString, JSVM_Value * result )
```

**Description**

Parses a JSON string and returns the parsed value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| jsonString | String to be parsed.| 
| result | Value obtained by parsing.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_STRING_EXPECTED** indicates that the argument is not a string.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_JsonStringify()

```
JSVM_EXTERN JSVM_Status OH_JSVM_JsonStringify (JSVM_Env env, JSVM_Value jsonObject, JSVM_Value * result )
```

**Description**

Converts an object into a JSON string and returns the converted string.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| jsonObject | Object to be stringified.| 
| result | String returned after successful conversion.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_MemoryPressureNotification()

```
JSVM_EXTERN JSVM_Status OH_JSVM_MemoryPressureNotification (JSVM_Env env, JSVM_MemoryPressureLevel level )
```

**Description**

Notifies the VM of insufficient system memory and selectively triggers garbage collection.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| level | Memory pressure level to be set for the current VM.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_NewInstance()

```
JSVM_EXTERN JSVM_Status OH_JSVM_NewInstance (JSVM_Env env, JSVM_Value constructor, size_t argc, const JSVM_Value * argv, JSVM_Value * result )
```

**Description**

Instantiates a new JavaScript value by using the constructor represented by the given JSVM_Value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| constructor | JavaScript function that will be called as a constructor.| 
| argc | Number of elements in the argv array.| 
| argv | JavaScript value array. **JSVM_Value** indicates the parameter of the constructor. If **argc** is 0, **argc** can be ignored by passing **NULL** to it.| 
| result | Returned JavaScript object, which is the constructed object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_PENDING_EXCEPTION** indicates that a JavaScript exception occurs during the execution.


### OH_JSVM_ObjectFreeze()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ObjectFreeze (JSVM_Env env, JSVM_Value object )
```

**Description**

Freezes the given object. This prevents additions or deletions of properties, enumerability, configurability, or writeability change of properties, or value change of properties. It also prevents prototype change of an object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object to be frozen.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_ObjectGetPrototypeOf()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ObjectGetPrototypeOf (JSVM_Env env, JSVM_Value object, JSVM_Value * result )
```

**Description**

Gets the prototype of a JavaScript object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | JavaScript object whose prototype is to be returned.| 
| result | Prototype of a given object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.

**JSVM_PENDING_EXCPTION** indicates that an exception is thrown during API running.


### OH_JSVM_ObjectSeal()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ObjectSeal (JSVM_Env env, JSVM_Value object )
```

**Description**

Seals a specified object. This prevents additions of properties and marks existing properties non-configurable.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object to be sealed.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_ObjectSetPrototypeOf()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ObjectSetPrototypeOf (JSVM_Env env, JSVM_Value object, JSVM_Value prototype )
```

**Description**

Sets the prototype of a JavaScript object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | JavaScript object whose prototype needs to be set.| 
| prototype | Object prototype.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.

**JSVM_GENERIC_FAILURE** indicates that the prototype fails to be set. This failure is triggered when the prototype is set cyclically.

**JSVM_PENDING_EXCPTION** indicates that an exception is thrown during API running.


### OH_JSVM_OpenEnvScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_OpenEnvScope (JSVM_Env env, JSVM_EnvScope * result )
```

**Description**

Opens a new environment scope.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Target environment in which the JSVM-API will be called.| 
| result | New environment scope.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_OpenEscapableHandleScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_OpenEscapableHandleScope (JSVM_Env env, JSVM_EscapableHandleScope * result )
```

**Description**

Opens a new scope from which an object can be escalated to an external scope.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | New scope.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_OpenHandleScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_OpenHandleScope (JSVM_Env env, JSVM_HandleScope * result )
```

**Description**

Opens a new scope.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| result | New scope.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_OpenInspector()

```
JSVM_EXTERN JSVM_Status OH_JSVM_OpenInspector (JSVM_Env env, const char * host, uint16_t port )
```

**Description**

Opens an inspector on the specified host and port for debugging JavaScript code.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| host | IP address of the host for listening on the inspector connection.| 
| port | Port for listening on the inspector connection.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_PENDING_EXCEPTION** indicates that a JavaScript exception occurs during the execution.


### OH_JSVM_OpenInspectorWithName()

```
JSVM_EXTERN JSVM_Status OH_JSVM_OpenInspectorWithName (JSVM_Env env, int pid, const char * name )
```

**Description**

Opens an inspector with the specified **name**, in order to open the UNIX domain port corresponding to the PID.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment in which the API is called.| 
| pid | Process ID for identifying the inspector connection.| 
| name | Name of an inspector. If nullptr is passed in, the default name is **jsvm**.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_PENDING_EXCEPTION** indicates that an exception occurs.


### OH_JSVM_OpenVMScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_OpenVMScope (JSVM_VM vm, JSVM_VMScope * result )
```

**Description**

Opens a new VM scope for a VM instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | Target VM instance.| 
| result | New VM scope.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_PerformMicrotaskCheckpoint()

```
JSVM_EXTERN JSVM_Status OH_JSVM_PerformMicrotaskCheckpoint (JSVM_VM vm)
```

**Description**

Checks whether there are micro tasks waiting in the queue. If yes, execute them.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | VM instance for which micro tasks are to be checked.| 

**Returns**

Result code of the JSVM function. **JSVM_OK** indicates execution success.


### OH_JSVM_PumpMessageLoop()

```
JSVM_EXTERN JSVM_Status OH_JSVM_PumpMessageLoop (JSVM_VM vm, bool * result )
```

**Description**

Starts the running of the task queue in the VM. The task queue can be executed through an external event loop.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | VM instance for starting a task queue.| 
| result | Whether the task queue is successfully started.| 

**Returns**

Result code of the JSVM function. **JSVM_OK** indicates execution success.


### OH_JSVM_ReferenceRef()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ReferenceRef (JSVM_Env env, JSVM_Ref ref, uint32_t * result )
```

**Description**

Increases the reference count and returns the new reference count.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| ref | Reference that is passed in. Its reference count will increase.| 
| result | New reference count.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_ReferenceUnref()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ReferenceUnref (JSVM_Env env, JSVM_Ref ref, uint32_t * result )
```

**Description**

Decreases the reference count and returns the new reference count.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| ref | JSVM_Ref that is passed in. Its reference count will decrease.| 
| result | New reference count.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure.


### OH_JSVM_RejectDeferred()

```
JSVM_EXTERN JSVM_Status OH_JSVM_RejectDeferred (JSVM_Env env, JSVM_Deferred deferred, JSVM_Value rejection )
```

**Description**

Rejects a JavaScript promise by using the associated deferred object. It can only be used to reject the JavaScript promise of the corresponding available deferred object. This means that promise must be created using **OH_JSVM_CreatePromise()**, and the object returned from this call must be retained so that it can be passed to this API.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| deferred | Deferred object whose associated promise is to be parsed.| 
| rejection | Value used to reject a promise.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_ReleaseCache()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ReleaseCache (JSVM_Env env, const uint8_t * cacheData, JSVM_CacheType cacheType )
```

**Description**

Releases the cache of a specified type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| cacheData | Cache data to be released. Repeated release is an undefined behavior.| 
| cacheType | Cache type. A generated cache can be released accordingly.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates a null pointer argument or an invalid cacheType argument.


### OH_JSVM_ReleaseScript()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ReleaseScript (JSVM_Env env, JSVM_Script script )
```

**Description**

Releases the script retained by **OH_JSVM_RetainScript**. The released script cannot be used again.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment in which the API is called.| 
| script | JavaScript string that includes the script to be released.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates that the script is empty or has not been saved.


### OH_JSVM_RemoveWrap()

```
JSVM_EXTERN JSVM_Status OH_JSVM_RemoveWrap (JSVM_Env env, JSVM_Value jsObject, void ** result )
```

**Description**

Removes the wrap of the native instance, which is previously wrapped in **js_object** by **OH_JSVM_Wrap()**. If the **finalize** callback is associated with wrap, it will not be called when the JavaScript object is garbage collected.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| jsObject | Object associated with the native instance.| 
| result | Pointer to the wrapped native instance.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_ResolveDeferred()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ResolveDeferred (JSVM_Env env, JSVM_Deferred deferred, JSVM_Value resolution )
```

**Description**

Resolves a JavaScript promise by using the associated deferred object. It can only be used to resolve the JavaScript promise of the corresponding available deferred object. This means that promise must be created using **OH_JSVM_CreatePromise()**, and the object returned from this call must be retained so that it can be passed to this API.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| deferred | Deferred object whose associated promise is to be parsed.| 
| resolution | Value used to resolve a promise.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_RetainScript()

```
JSVM_EXTERN JSVM_Status OH_JSVM_RetainScript (JSVM_Env env, JSVM_Script script )
```

**Description**

Retains a JSVM_Script and extends its lifecycle beyond the current scope.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment in which the API is called.| 
| script | JavaScript string that includes the script to be retained.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates that the script is empty or has been saved.


### OH_JSVM_RunScript()

```
JSVM_EXTERN JSVM_Status OH_JSVM_RunScript (JSVM_Env env, JSVM_Script script, JSVM_Value * result )
```

**Description**

Runs a string of JavaScript code and returns its result, including the following precautions: Unlike eval, this function does not allow the script to access the current lexical scope, and therefore does not allow the script to access the module scope. This means that pseudo-global variables such as **require** will be unavailable. The script can access the global scope. The functions and variable declarations in the script will be added to the global object. Variable declarations using **let** and **const** are globally visible, but are not added to the global object. The value of **this** is **global** in the script.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| script | JavaScript string that includes the script to be executed.| 
| result | Value generated after the script is executed.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure.


### OH_JSVM_SetElement()

```
JSVM_EXTERN JSVM_Status OH_JSVM_SetElement (JSVM_Env env, JSVM_Value object, uint32_t index, JSVM_Value value )
```

**Description**

Sets an element on the passed-in object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object whose property is to be set.| 
| index | Index of the property to be set.| 
| value | Property value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_SetInstanceData()

```
JSVM_EXTERN JSVM_Status OH_JSVM_SetInstanceData (JSVM_Env env, void * data, JSVM_Finalize finalizeCb, void * finalizeHint )
```

**Description**

Sets instance data so that it is associated with the currently running JSVM environment. You can use **OH_JSVM_GetInstanceData()** to get data later. Any existing data set by a previous call to **OH_JSVM_SetInstanceData()** will be overwritten. If **finalizeCb** was previously provided, it will not be called.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| data | Data bound for this instance.| 
| finalizeCb | Function for destroying the environment.| 
| finalizeHint | Optional hint passed to the **finalize** callback during collection.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_SetNamedProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_SetNamedProperty (JSVM_Env env, JSVM_Value object, const char * utf8name, JSVM_Value value )
```

**Description**

This method is equivalent to calling **OH_JSVM_SetProperty**, where the JSVM_Value is created using the character string passed through **utf8Name**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object whose property is to be set.| 
| utf8Name | Name of the property to be set.| 
| value | Property value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_SetProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_SetProperty (JSVM_Env env, JSVM_Value object, JSVM_Value key, JSVM_Value value )
```

**Description**

Sets a property for the passed-in object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| object | Object whose property is to be set.| 
| key | Name of the property to be set.| 
| value | Property value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_StartCpuProfiler()

```
JSVM_EXTERN JSVM_Status OH_JSVM_StartCpuProfiler (JSVM_VM vm, JSVM_CpuProfiler * result )
```

**Description**

Creates and starts a CPU profiler.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | VM for starting the CPU profiler.| 
| result | Pointer to the CPU profiler.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_StopCpuProfiler()

```
JSVM_EXTERN JSVM_Status OH_JSVM_StopCpuProfiler (JSVM_VM vm, JSVM_CpuProfiler profiler, JSVM_OutputStream stream, void * streamData )
```

**Description**

Stops the CPU profiler and outputs the result to a stream.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | VM for starting the CPU profiler.| 
| profiler | CPU profiler to be stopped.| 
| stream | Output stream callback.| 
| streamData | Optional data passed to the output stream callback. For example, it can be a file stream, which is used to write the sampled data passed in the output stream callback to a file.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_StrictEquals()

```
JSVM_EXTERN JSVM_Status OH_JSVM_StrictEquals (JSVM_Env env, JSVM_Value lhs, JSVM_Value rhs, bool * result )
```

**Description**

Provides behavior similar to calling the strict equality algorithm.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| lhs | JavaScript value to be checked.| 
| rhs | JavaScript value to be checked.| 
| result | Whether two JSVM_Value objects are equal.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_SymbolFor()

```
JSVM_EXTERN JSVM_Status OH_JSVM_SymbolFor (JSVM_Env env, const char * utf8description, size_t length, JSVM_Value * result )
```

**Description**

Searches the global registry for an existing symbol with the given description. If the symbol already exists, it is returned. Otherwise, a new symbol is created in the registry.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| utf8description | UTF-8 C string, indicating the text used as the symbol description.| 
| length | Length of the description string, in bytes. If it is null-terminated, the value is **JSVM_AUTO_LENGTH**.| 
| result | JSVM_Value of the JavaScript symbol.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_TakeHeapSnapshot()

```
JSVM_EXTERN JSVM_Status OH_JSVM_TakeHeapSnapshot (JSVM_VM vm, JSVM_OutputStream stream, void * streamData )
```

**Description**

Takes a heap snapshot and outputs it to a stream.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | VM whose heap snapshot is to be obtained.| 
| stream | Output stream callback.| 
| streamData | Optional data passed to the output stream callback. For example, it can be a file stream, which is used to write the sampled data passed in the output stream callback to a file.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_Throw()

```
JSVM_EXTERN JSVM_Status OH_JSVM_Throw (JSVM_Env env, JSVM_Value error )
```

**Description**

Throws the provided JavaScript value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| error | JavaScript error to be thrown.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_ThrowError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowError (JSVM_Env env, const char * code, const char * msg )
```

**Description**

Throws a JavaScript Error with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| code | Optional error code to be set on the error.| 
| msg | C string representing the text associated with the error.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_ThrowRangeError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowRangeError (JSVM_Env env, const char * code, const char * msg )
```

**Description**

Throws a JavaScript RangeError with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| code | Optional error code to be set on the error.| 
| msg | C string representing the text associated with the error.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_ThrowSyntaxError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowSyntaxError (JSVM_Env env, const char * code, const char * msg )
```

**Description**

Throws a JavaScript SyntaxError with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| code | Optional error code to be set on the error.| 
| msg | C string representing the text associated with the error.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_ThrowTypeError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowTypeError (JSVM_Env env, const char * code, const char * msg )
```

**Description**

Throws a JavaScript TypeError with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| code | Optional error code to be set on the error.| 
| msg | C string representing the text associated with the error.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.


### OH_JSVM_Typeof()

```
JSVM_EXTERN JSVM_Status OH_JSVM_Typeof (JSVM_Env env, JSVM_Value value, JSVM_ValueType * result )
```

**Description**

Provides behavior similar to calling the typeof operator on a defined object. The difference is that this function supports the detection of external values; it detects null as a separate type, while ECMAScript typeof is used to detect objects. If the value type is invalid, an error is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript value whose type is to be queried.| 
| result | Type of the JavaScript value.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_TypeTagObject()

```
JSVM_EXTERN JSVM_Status OH_JSVM_TypeTagObject (JSVM_Env env, JSVM_Value value, const JSVM_TypeTag * typeTag )
```

**Description**

Associates the value of the typeTag pointer with a JavaScript object or an external value. You can call **OH_JSVM_CheckObjectTypeTag()** to check the type of the tag attached to the object, to ensure that the object type is correct. If the object already has an associated type tag, **JSVM_INVALID_ARG** is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| value | JavaScript object or external value to be tagged.| 
| typeTag | Tag object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_Unwrap()

```
JSVM_EXTERN JSVM_Status OH_JSVM_Unwrap (JSVM_Env env, JSVM_Value jsObject, void ** result )
```

**Description**

When the JavaScript code calls a method of a class or property accessor, the corresponding JSVM_Callback is called. If the callback is for an instance method or accessor, the **this** argument of the callback is the wrapper object. Then you can obtain the C++ instance as the call target by calling **OH_JSVM_Unwrap()** of the wrapper object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| jsObject | Object associated with the native instance.| 
| result | Pointer to the wrapped native instance.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.


### OH_JSVM_WaitForDebugger()

```
JSVM_EXTERN JSVM_Status OH_JSVM_WaitForDebugger (JSVM_Env env, bool breakNextLine )
```

**Description**

Waits for the host to set up a socket connection with an inspector. After the connection is set up, the application continues to run. **Runtime.runIfWaitingForDebugger** is sent.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| breakNextLine | Whether to break in the next line of JavaScript code. If yes, the next line of JavaScript code will be broken. To continue the execution, use the debug button of the debugger to control the execution of the JavaScript code.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_GENERIC_FAILURE** indicates execution failure due to unknown reasons.


### OH_JSVM_Wrap()

```
JSVM_EXTERN JSVM_Status OH_JSVM_Wrap (JSVM_Env env, JSVM_Value jsObject, void * nativeObject, JSVM_Finalize finalizeCb, void * finalizeHint, JSVM_Ref * result )
```

**Description**

Wraps a native instance in the JavaScript object. The native instance can be obtained using **OH_JSVM_Unwrap()**.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for calling the JSVM-API.| 
| jsObject | JavaScript object that will wrap a native object.| 
| nativeObject | Native instance wrapped in a JavaScript object.| 
| finalizeCb | Optional native callback, which can be used to release the native instance when the JavaScript object is garbage collected.| 
| finalizeHint | Optional context hint passed to the **finalize** callback.| 
| result | Optional reference to the wrap object.| 

**Returns**

Status code JSVM_Status. **JSVM_OK** indicates execution success.

**JSVM_INVALID_ARG** indicates an invalid argument.
