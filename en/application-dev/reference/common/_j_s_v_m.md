# JSVM


## Overview

Provides standard JavaScript engine capabilities.

Function overview: The standard JS engine is a JavaScript code execution engine that strictly complies with the Ecmascript specifications. Supports the standard library defined in the Ecmascript specification and provides complete native APIs of C++ interaction JS. Use jit to accelerate code execution and provide secure and efficient JS execution capabilities for applications. The capabilities of the standard JS engine are provided through a stable set of ABI, that is, JSVM-API. The JSVM-API can be dynamically linked to JS engine libraries of different versions to shield the differences between engine interfaces for developers. JSVM-API provides capabilities such as engine lifecycle management, JS context management, JS code execution, JS/C++ interoperability, execution environment snapshot, and codecache.
Platform: ARM64.
Usage: Link libjsvm.so in the SDK and include the ark_runtime/jsvm.h header file in the C++ code.

Provides developers with independent, standard, and complete JavaScript engine capabilities through APIs, including managing the engine lifecycle, compiling and running JavaScript code, implementing cross-language invoking of JavaScript and C++, and taking snapshots.

**Since**: 11


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [jsvm.h](jsvm_8h.md) | Provides the JSVM-API interface definition.| 
| [jsvm_types.h](jsvm__types_8h.md) | Provides JSVM-API type definitions.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[JSVM_CallbackStruct](_j_s_v_m___callback_struct.md) | Callback function pointers and data of native functions provided by users. These functions are exposed to JavaScript through the JSVM-API interface.| 
| struct&nbsp;&nbsp;[JSVM_InitOptions](_j_s_v_m___init_options.md) | Initialization option, which is used to initialize the JavaScript virtual machine.| 
| struct&nbsp;&nbsp;[JSVM_CreateVMOptions](_j_s_v_m___create_v_m_options.md) | Options for creating a JavaScript virtual machine.| 
| struct&nbsp;&nbsp;[JSVM_VMInfo](_j_s_v_m___v_m_info.md) | JavaScript VM information.| 
| struct&nbsp;&nbsp;[JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) | Attribute descriptor.| 
| struct&nbsp;&nbsp;[JSVM_ExtendedErrorInfo](_j_s_v_m___extended_error_info.md) | Extended exception information.| 
| struct&nbsp;&nbsp;[JSVM_TypeTag](_j_s_v_m___type_tag.md) | Type token, stored as a 128-bit value of two unsigned 64-bit integers. As a UUID, JavaScript objects can be "tagged" through it to ensure that their types remain unchanged.| 


### Macros

| Name| Description| 
| -------- | -------- |
| [JSVM_AUTO_LENGTH](#jsvm_auto_length)&nbsp;&nbsp;&nbsp;SIZE_MAX | Automatic length.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct JSVM_VM__ \* [JSVM_VM](#jsvm_vm) | Indicates a JavaScript VM instance.| 
| typedef struct JSVM_VMScope__ \* [JSVM_VMScope](#jsvm_vmscope) | Indicates the scope of the JavaScript virtual machine.| 
| typedef struct JSVM_EnvScope__ \* [JSVM_EnvScope](#jsvm_envscope) | Represents the environment used to control the attachment to the current virtual machine instance. The environment is available to the virtual machine instance of the thread only after the thread enters the JSVM_EnvScope of the environment through OH_JSVM_OpenEnvScope.| 
| typedef struct JSVM_Script__ \* [JSVM_Script](#jsvm_script) | Indicates a piece of JavaScript code.| 
| typedef struct JSVM_Env__ \* [JSVM_Env](#jsvm_env) | Indicates the context environment of a specific VM state. It needs to be transferred as a parameter when the native function is called and transferred to any subsequent JSVM-API nested invoking.| 
| typedef struct JSVM_Value__ \* [JSVM_Value](#jsvm_value) | Indicates the JavaScript value.| 
| typedef struct JSVM_Ref__ \* [JSVM_Ref](#jsvm_ref) | Represents a reference to a JavaScript value.| 
| typedef struct JSVM_HandleScope__ \* [JSVM_HandleScope](#jsvm_handlescope) | Indicates the scope of a JavaScript value. It is used to control and modify the lifecycle of an object created in a specific scope. Typically, JSVM-API values are created in the context of JSVM_HandleScope. When the native method is called from JavaScript, the default JSVM_HandleScope exists. If the user does not explicitly create a new JSVM_HandleScope, the JSVM-API value is created in the default JSVM_HandleScope. For any code call other than native method execution (for example, during libuv callback calls), the module needs to create a scope before calling any function that may cause JavaScript value creation. JSVM_HandleScope is created using OH_JSVM_OpenHandleScope and destroyed using OH_JSVM_CloseHandleScope. Closing the scope represents indicating to the GC that all JSVM_Values created during the lifecycle of the JSVM_HandleScope scope will no longer be referenced from the stack frame of the current heap.| 
| typedef struct JSVM_EscapableHandleScope__ \* [JSVM_EscapableHandleScope](#jsvm_escapablehandlescope) | Indicates a special type of handle scope, which is used to return the value created in a specific handle scope to the parent scope.| 
| typedef struct JSVM_CallbackInfo__ \* [JSVM_CallbackInfo](#jsvm_callbackinfo) | Represents the opaque data type passed to the callback function. It can be used to obtain additional information about the context in which the function is called.| 
| typedef struct JSVM_Deferred__ \* [JSVM_Deferred](#jsvm_deferred) | Promise delay object.| 
| typedef [JSVM_CallbackStruct](_j_s_v_m___callback_struct.md) \* [JSVM_Callback](#jsvm_callback) | Function pointer type of native functions provided by users. These functions are exposed to JavaScript through the JSVM-API interface.| 
| typedef void(JSVM_CDECL \* [JSVM_Finalize](#jsvm_finalize)) ([JSVM_Env](#jsvm_env) env, void \*finalizeData, void \*finalizeHint) | Function pointer type. When a native object or data is associated with a JS object, this pointer is transferred. This function is called when the associated JS object is reclaimed by the GC to execute the native cleanup action.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [JSVM_PropertyAttributes](#jsvm_propertyattributes) {<br>JSVM_DEFAULT = 0, JSVM_WRITABLE = 1 &lt;&lt; 0, JSVM_ENUMERABLE = 1 &lt;&lt; 1, JSVM_CONFIGURABLE = 1 &lt;&lt; 2,<br>JSVM_STATIC = 1 &lt;&lt; 10, JSVM_DEFAULT_METHOD = JSVM_WRITABLE \| JSVM_CONFIGURABLE, JSVM_DEFAULT_JSPROPERTY = JSVM_WRITABLE \| JSVM_ENUMERABLE \| JSVM_CONFIGURABLE<br>} | Controls the behavior of JavaScript object attributes.| 
| [JSVM_ValueType](#jsvm_valuetype) {<br>JSVM_UNDEFINED, JSVM_NULL, JSVM_BOOLEAN, JSVM_NUMBER,<br>JSVM_STRING, JSVM_SYMBOL, JSVM_OBJECT, JSVM_FUNCTION,<br>JSVM_EXTERNAL, JSVM_BIGINT<br>} | Describes the JSVM_Value type.| 
| [JSVM_TypedarrayType](#jsvm_typedarraytype) {<br>JSVM_INT8_ARRAY, JSVM_UINT8_ARRAY, JSVM_UINT8_CLAMPED_ARRAY, JSVM_INT16_ARRAY,<br>JSVM_UINT16_ARRAY, JSVM_INT32_ARRAY, JSVM_UINT32_ARRAY, JSVM_FLOAT32_ARRAY,<br>JSVM_FLOAT64_ARRAY, JSVM_BIGINT64_ARRAY, JSVM_BIGUINT64_ARRAY<br>} | Type of a TypedArray.| 
| [JSVM_Status](#jsvm_status) {<br>JSVM_OK, JSVM_INVALID_ARG, JSVM_OBJECT_EXPECTED, JSVM_STRING_EXPECTED,<br>JSVM_NAME_EXPECTED, JSVM_FUNCTION_EXPECTED, JSVM_NUMBER_EXPECTED, JSVM_BOOLEAN_EXPECTED,<br>JSVM_ARRAY_EXPECTED, JSVM_GENERIC_FAILURE, JSVM_PENDING_EXCEPTION, JSVM_CANCELLED,<br>JSVM_ESCAPE_CALLED_TWICE, JSVM_HANDLE_SCOPE_MISMATCH, JSVM_CALLBACK_SCOPE_MISMATCH, JSVM_QUEUE_FULL,<br>JSVM_CLOSING, JSVM_BIGINT_EXPECTED, JSVM_DATE_EXPECTED, JSVM_ARRAYBUFFER_EXPECTED,<br>JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED, JSVM_WOULD_DEADLOCK, JSVM_NO_EXTERNAL_BUFFERS_ALLOWED, JSVM_CANNOT_RUN_JS<br>} | Complete status code indicating whether the JSVM-API invoking is successful or fails.| 
| [JSVM_KeyCollectionMode](#jsvm_keycollectionmode) { JSVM_KEY_INCLUDE_PROTOTYPES, JSVM_KEY_OWN_ONLY } | Limits the range of attributes to be searched for.| 
| [JSVM_KeyFilter](#jsvm_keyfilter) {<br>JSVM_KEY_ALL_PROPERTIES = 0, JSVM_KEY_WRITABLE = 1, JSVM_KEY_ENUMERABLE = 1 &lt;&lt; 1, JSVM_KEY_CONFIGURABLE = 1 &lt;&lt; 2,<br>JSVM_KEY_SKIP_STRINGS = 1 &lt;&lt; 3, JSVM_KEY_SKIP_SYMBOLS = 1 &lt;&lt; 4<br>} | Attribute filter. You can use or to construct a composite filter.| 
| [JSVM_KeyConversion](#jsvm_keyconversion) { JSVM_KEY_KEEP_NUMBERS, JSVM_KEY_NUMBERS_TO_STRINGS } | Key conversion option.| 
| [JSVM_MemoryPressureLevel](#jsvm_memorypressurelevel) { JSVM_MEMORY_PRESSURE_LEVEL_NONE, JSVM_MEMORY_PRESSURE_LEVEL_MODERATE, JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL } | Memory pressure level.| 


### Functions

| Name| Description| 
| -------- | -------- |
| EXTERN_C_START JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_Init](#oh_jsvm_init) (const [JSVM_InitOptions](_j_s_v_m___init_options.md) \*options) | Initialize a JavaScript virtual machine.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateVM](#oh_jsvm_createvm) (const [JSVM_CreateVMOptions](_j_s_v_m___create_v_m_options.md) \*options, [JSVM_VM](#jsvm_vm) \*result) | Create a VM instance.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_DestroyVM](#oh_jsvm_destroyvm) ([JSVM_VM](#jsvm_vm) vm) | Destroys a VM instance.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_OpenVMScope](#oh_jsvm_openvmscope) ([JSVM_VM](#jsvm_vm) vm, [JSVM_VMScope](#jsvm_vmscope) \*result) | Opens a new VM scope for a VM instance.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CloseVMScope](#oh_jsvm_closevmscope) ([JSVM_VM](#jsvm_vm) vm, [JSVM_VMScope](#jsvm_vmscope) scope) | Disable the VM scope of the VM instance.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateEnv](#oh_jsvm_createenv) ([JSVM_VM](#jsvm_vm) vm, size_t propertyCount, const [JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) \*properties, [JSVM_Env](#jsvm_env) \*result) | Creates a new environment based on the optional attributes of the new environment context.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateEnvFromSnapshot](#oh_jsvm_createenvfromsnapshot) ([JSVM_VM](#jsvm_vm) vm, size_t index, [JSVM_Env](#jsvm_env) \*result) | Creates a new environment based on the start snapshot of the VM.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_DestroyEnv](#oh_jsvm_destroyenv) ([JSVM_Env](#jsvm_env) env) | Destroy the environment.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_OpenEnvScope](#oh_jsvm_openenvscope) ([JSVM_Env](#jsvm_env) env, [JSVM_EnvScope](#jsvm_envscope) \*result) | Opens a new environment scope.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CloseEnvScope](#oh_jsvm_closeenvscope) ([JSVM_Env](#jsvm_env) env, [JSVM_EnvScope](#jsvm_envscope) scope) | Close the environment scope.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CompileScript](#oh_jsvm_compilescript) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) script, const uint8_t \*cachedData, size_t cacheDataLength, bool eagerCompile, bool \*cacheRejected, [JSVM_Script](#jsvm_script) \*result) | Compiles a string of JavaScript code and returns the compiled script.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateCodeCache](#oh_jsvm_createcodecache) ([JSVM_Env](#jsvm_env) env, [JSVM_Script](#jsvm_script) script, const uint8_t \*\*data, size_t \*length) | Create a code cache for the compiled script.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_RunScript](#oh_jsvm_runscript) ([JSVM_Env](#jsvm_env) env, [JSVM_Script](#jsvm_script) script, [JSVM_Value](#jsvm_value) \*result) | Executes a string of JavaScript code and returns its result, including the following precautions: Unlike eval, this function does not allow the script to access the current lexical scope, and therefore does not allow the script to access the module scope. This means that pseudo-global variables such as require will be unavailable. The script can access the global scope. The functions and var declarations in the script will be added to the global object. Variable declarations using let and const are globally visible, but are not added to global objects. The value of this is global in the script.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_SetInstanceData](#oh_jsvm_setinstancedata) ([JSVM_Env](#jsvm_env) env, void \*data, [JSVM_Finalize](#jsvm_finalize) finalizeCb, void \*finalizeHint) | Associates data with the currently running JSVM environment. You can use OH_JSVM_GetInstanceData() to retrieve data later. Any existing data associated with the currently running JSVM environment set by a previous call to OH_JSVM_SetInstanceData() will be overwritten. If finalizeCb was previously provided, it will not be called.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetInstanceData](#oh_jsvm_getinstancedata) ([JSVM_Env](#jsvm_env) env, void \*\*data) | Retrieves data associated with the currently running JSVM environment through OH_JSVM_SetInstanceData(). If no associated data is set, the function is called successfully and data is set to NULL.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetLastErrorInfo](#oh_jsvm_getlasterrorinfo) ([JSVM_Env](#jsvm_env) env, const [JSVM_ExtendedErrorInfo](_j_s_v_m___extended_error_info.md) \*\*result) | Retrieves the JSVM_ExtendedErrorInfo structure that contains information about the last error that occurred. The content of JSVM_ExtendedErrorInfo returned is valid only before the JSVM-API function is called for the same env. This includes calls to OH_JSVM_IsExceptionPending, so you may often need to copy information for later use. The pointer returned in error_message points to a statically defined string, so if you copy it from the error_message field (which will be overwritten) before calling another JSVM-API function, you can safely use the pointer.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_Throw](#oh_jsvm_throw) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) error) | Throws the provided JavaScript value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_ThrowError](#oh_jsvm_throwerror) ([JSVM_Env](#jsvm_env) env, const char \*code, const char \*msg) | A JavaScript Error with the provided text is thrown.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_ThrowTypeError](#oh_jsvm_throwtypeerror) ([JSVM_Env](#jsvm_env) env, const char \*code, const char \*msg) | A JavaScript TypeError with the provided text is thrown.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_ThrowRangeError](#oh_jsvm_throwrangeerror) ([JSVM_Env](#jsvm_env) env, const char \*code, const char \*msg) | A JavaScript RangeError with the provided text is thrown.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_ThrowSyntaxError](#oh_jsvm_throwsyntaxerror) ([JSVM_Env](#jsvm_env) env, const char \*code, const char \*msg) | A JavaScript SyntaxError with the provided text is thrown.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_IsError](#oh_jsvm_iserror) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Query JSVM_Value to check if it represents an error object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateError](#oh_jsvm_createerror) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) code, [JSVM_Value](#jsvm_value) msg, [JSVM_Value](#jsvm_value) \*result) | Returns a JavaScript Error with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateTypeError](#oh_jsvm_createtypeerror) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) code, [JSVM_Value](#jsvm_value) msg, [JSVM_Value](#jsvm_value) \*result) | Returns a JavaScript TypeError with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateRangeError](#oh_jsvm_createrangeerror) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) code, [JSVM_Value](#jsvm_value) msg, [JSVM_Value](#jsvm_value) \*result) | Returns a JavaScript RangeError with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateSyntaxError](#oh_jsvm_createsyntaxerror) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) code, [JSVM_Value](#jsvm_value) msg, [JSVM_Value](#jsvm_value) \*result) | Returns a JavaScript SyntaxError with the provided text.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetAndClearLastException](#oh_jsvm_getandclearlastexception) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Obtains and clears the last exception. If a suspension occurs, a JavaScript exception is returned. Otherwise, NULL is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_IsExceptionPending](#oh_jsvm_isexceptionpending) ([JSVM_Env](#jsvm_env) env, bool \*result) | Check whether the last exception is caused by suspension. If the error is caused by an exception, true is returned. Otherwise, false is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_OpenHandleScope](#oh_jsvm_openhandlescope) ([JSVM_Env](#jsvm_env) env, [JSVM_HandleScope](#jsvm_handlescope) \*result) | A new scope has been opened up.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CloseHandleScope](#oh_jsvm_closehandlescope) ([JSVM_Env](#jsvm_env) env, [JSVM_HandleScope](#jsvm_handlescope) scope) | Closes the incoming scope. Scopes must be closed in the reverse order of creating scopes.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_OpenEscapableHandleScope](#oh_jsvm_openescapablehandlescope) ([JSVM_Env](#jsvm_env) env, [JSVM_EscapableHandleScope](#jsvm_escapablehandlescope) \*result) | A new scope is opened from which an object can be promoted to an external scope.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CloseEscapableHandleScope](#oh_jsvm_closeescapablehandlescope) ([JSVM_Env](#jsvm_env) env, [JSVM_EscapableHandleScope](#jsvm_escapablehandlescope) scope) | Closes the incoming scope. Scopes must be closed in the reverse order of creating scopes. This JSVM_API can be called even if a suspended JavaScript exception exists.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_EscapeHandle](#oh_jsvm_escapehandle) ([JSVM_Env](#jsvm_env) env, [JSVM_EscapableHandleScope](#jsvm_escapablehandlescope) scope, [JSVM_Value](#jsvm_value) escapee, [JSVM_Value](#jsvm_value) \*result) | Raises the handle of a JavaScript object so that it is valid for the lifecycle of the external scope. Each scope can be called only once. If this API is called for multiple times, an error is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateReference](#oh_jsvm_createreference) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, uint32_t initialRefcount, [JSVM_Ref](#jsvm_ref) \*result) | Creates a new reference with the specified reference count for the value passed in.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_DeleteReference](#oh_jsvm_deletereference) ([JSVM_Env](#jsvm_env) env, [JSVM_Ref](#jsvm_ref) ref) | Delete the transferred reference.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_ReferenceRef](#oh_jsvm_referenceref) ([JSVM_Env](#jsvm_env) env, [JSVM_Ref](#jsvm_ref) ref, uint32_t \*result) | Increases the reference count of the incoming reference and returns the generated reference count.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_ReferenceUnref](#oh_jsvm_referenceunref) ([JSVM_Env](#jsvm_env) env, [JSVM_Ref](#jsvm_ref) ref, uint32_t \*result) | Decrements the reference count of the incoming reference and returns the generated reference count.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetReferenceValue](#oh_jsvm_getreferencevalue) ([JSVM_Env](#jsvm_env) env, [JSVM_Ref](#jsvm_ref) ref, [JSVM_Value](#jsvm_value) \*result) | If still valid, this JSVM-API returns JSVM_Value, representing the JavaScript value associated with JSVM_Ref. Otherwise, the result will be NULL.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateArray](#oh_jsvm_createarray) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Returns the JSVM-API value corresponding to the JavaScript Array type.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateArrayWithLength](#oh_jsvm_createarraywithlength) ([JSVM_Env](#jsvm_env) env, size_t length, [JSVM_Value](#jsvm_value) \*result) | Returns the JSVM-API value corresponding to the JavaScript Array type. The length attribute of the array is set to the input length parameter. However, there is no guarantee that the underlying buffer is pre-allocated by the VM when the array is created. This behavior is left to the underlying VM implementation.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateArraybuffer](#oh_jsvm_createarraybuffer) ([JSVM_Env](#jsvm_env) env, size_t byteLength, void \*\*data, [JSVM_Value](#jsvm_value) \*result) | The JSVM-API value corresponding to the JavaScript ArrayBuffer type is returned. ArrayBuffer is used to represent a fixed-length binary data buffer. It is usually used as a backup buffer for TypedArray objects. The allocated ArrayBuffer has an underlying byte buffer whose size is determined by the length parameter passed in. The underlying buffer can be returned to the caller, and the caller can directly operate the buffer. This buffer can only be written directly from native code. If you want to write data from JavaScript to the buffer, you need to create a TypedArray or DataView object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateDate](#oh_jsvm_createdate) ([JSVM_Env](#jsvm_env) env, double time, [JSVM_Value](#jsvm_value) \*result) | Allocates a JavaScript Date object. This API does not process leap seconds. This is because ECMAScript complies with the POSIX time specifications and ignores leap seconds.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateExternal](#oh_jsvm_createexternal) ([JSVM_Env](#jsvm_env) env, void \*data, [JSVM_Finalize](#jsvm_finalize) finalizeCb, void \*finalizeHint, [JSVM_Value](#jsvm_value) \*result) | Assigns a JavaScript value with external data. This is used to pass external data through JavaScript code. In the future, OH_JSVM_GetValueExternal can be used for retrieval by native code. A JSVM_Finalize callback is added to this API. This callback is called when the newly created JavaScript object is garbage collected. The created value is not an object, so additional attributes are not supported. It is considered a unique value type: calling OH_JSVM_Typeof() with an external value generates JSVM_EXTERNAL.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateObject](#oh_jsvm_createobject) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | Assigns a default JavaScript object. This function is equivalent to executing new Object() in JavaScript.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateSymbol](#oh_jsvm_createsymbol) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) description, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript symbol value from a UTF8-encoded C string.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_SymbolFor](#oh_jsvm_symbolfor) ([JSVM_Env](#jsvm_env) env, const char \*utf8description, size_t length, [JSVM_Value](#jsvm_value) \*result) | Searches the global registry for an existing symbol with a given description. If the symbol already exists, it is returned. Otherwise, a new symbol is created in the registry.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateTypedarray](#oh_jsvm_createtypedarray) ([JSVM_Env](#jsvm_env) env, [JSVM_TypedarrayType](#jsvm_typedarraytype) type, size_t length, [JSVM_Value](#jsvm_value) arraybuffer, size_t byteOffset, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript TypedArray object based on an existing ArrayBuffer object. The TypedArray object provides an array-like view on the underlying data buffer, where each element has the same underlying binary scalar data type. The sum of (length\*element size) and byteOffset must be less than or equal to the size (in bytes) of the input array. Otherwise, a range error (RangeError) is thrown.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateDataview](#oh_jsvm_createdataview) ([JSVM_Env](#jsvm_env) env, size_t length, [JSVM_Value](#jsvm_value) arraybuffer, size_t byteOffset, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript DataView object based on an existing ArrayBuffer object. The DataView object provides an array-like view on the underlying data buffer, where elements can have different sizes and types. The binary value of length plus byteOffset must be less than or equal to the size of the input array (in bytes). Otherwise, a range error (RangeError) is thrown.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateInt32](#oh_jsvm_createint32) ([JSVM_Env](#jsvm_env) env, int32_t value, [JSVM_Value](#jsvm_value) \*result) | Converts a value of the C int32_t type to a value of the JavaScript number type.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateUint32](#oh_jsvm_createuint32) ([JSVM_Env](#jsvm_env) env, uint32_t value, [JSVM_Value](#jsvm_value) \*result) | Converts a value of the C uint32_t type to the JavaScript number type.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateInt64](#oh_jsvm_createint64) ([JSVM_Env](#jsvm_env) env, int64_t value, [JSVM_Value](#jsvm_value) \*result) | Converts a value of the C int64_t type to a value of the JavaScript number type.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateDouble](#oh_jsvm_createdouble) ([JSVM_Env](#jsvm_env) env, double value, [JSVM_Value](#jsvm_value) \*result) | Converts a value of the C double type to a value of the JavaScript number type.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateBigintInt64](#oh_jsvm_createbigintint64) ([JSVM_Env](#jsvm_env) env, int64_t value, [JSVM_Value](#jsvm_value) \*result) | Converts a value of the C int64_t type to the JavaScript BigInt type.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateBigintUint64](#oh_jsvm_createbigintuint64) ([JSVM_Env](#jsvm_env) env, uint64_t value, [JSVM_Value](#jsvm_value) \*result) | Converts a value of the C uint64_t type to the JavaScript BigInt type.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateBigintWords](#oh_jsvm_createbigintwords) ([JSVM_Env](#jsvm_env) env, int signBit, size_t wordCount, const uint64_t \*words, [JSVM_Value](#jsvm_value) \*result) | Converts a set of unsigned 64-bit words to a single BigInt value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateStringLatin1](#oh_jsvm_createstringlatin1) ([JSVM_Env](#jsvm_env) env, const char \*str, size_t length, [JSVM_Value](#jsvm_value) \*result) | Converts a C string encoded using ISO-8859-1 to a JavaScript string value. Copies a native string.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateStringUtf16](#oh_jsvm_createstringutf16) ([JSVM_Env](#jsvm_env) env, const char16_t \*str, size_t length, [JSVM_Value](#jsvm_value) \*result) | Converts a C string encoded in UTF16-LE format to a JavaScript string value. Copies a native string.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateStringUtf8](#oh_jsvm_createstringutf8) ([JSVM_Env](#jsvm_env) env, const char \*str, size_t length, [JSVM_Value](#jsvm_value) \*result) | Creates a JavaScript string value from a UTF8-encoded C string. Copies a native string.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetArrayLength](#oh_jsvm_getarraylength) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, uint32_t \*result) | Returns the length of an array.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetArraybufferInfo](#oh_jsvm_getarraybufferinfo) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) arraybuffer, void \*\*data, size_t \*byteLength) | Retrieves the underlying data buffer of the ArrayBuffer and its length.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetPrototype](#oh_jsvm_getprototype) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) \*result) | Returns the prototype of an object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetTypedarrayInfo](#oh_jsvm_gettypedarrayinfo) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) typedarray, [JSVM_TypedarrayType](#jsvm_typedarraytype) \*type, size_t \*length, void \*\*data, [JSVM_Value](#jsvm_value) \*arraybuffer, size_t \*byteOffset) | Returns various properties of a typed array. If this attribute is not required, any output parameter can be NULL.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetDataviewInfo](#oh_jsvm_getdataviewinfo) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) dataview, size_t \*bytelength, void \*\*data, [JSVM_Value](#jsvm_value) \*arraybuffer, size_t \*byteOffset) | Returns various attributes of the DataView. If an attribute is not required, any output parameter can be set to NULL.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetDateValue](#oh_jsvm_getdatevalue) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, double \*result) | Returns the C double-precision base type for the time value of a given JavaScript Date. If the interface is called successfully, JSVM_OK is returned. If a JSVM_Value of the non-JavaScript Date type is transferred, JSVM_DATA_EXPECTED is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueBool](#oh_jsvm_getvaluebool) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Returns values such as the C Boolean base type of a given JavaScript Boolean.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueDouble](#oh_jsvm_getvaluedouble) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, double \*result) | Returns values such as the C double-precision base type of a given JavaScript number.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueBigintInt64](#oh_jsvm_getvaluebigintint64) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, int64_t \*result, bool \*lossless) | Returns values such as the C int64_t base type of a given JavaScript BigInt. If necessary, it truncates the value and sets lossless to false.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueBigintUint64](#oh_jsvm_getvaluebigintuint64) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, uint64_t \*result, bool \*lossless) | Returns values such as the C uint64_t base type of a given JavaScript BigInt. If necessary, it truncates the value and sets lossless to false.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueBigintWords](#oh_jsvm_getvaluebigintwords) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, int \*signBit, size_t \*wordCount, uint64_t \*words) | Converts a single BigInt value to a sign bit, a 64-bit little-endian array, and the number of elements in the array. Both signBit and words can be set to NULL. In this case, only wordCount is obtained.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueExternal](#oh_jsvm_getvalueexternal) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, void \*\*result) | Retrieves the external data pointer previously passed to OH_JSVM_CreateExternal().| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueInt32](#oh_jsvm_getvalueint32) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, int32_t \*result) | Returns values such as the C int32 base type of a given JavaScript number.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueInt64](#oh_jsvm_getvalueint64) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, int64_t \*result) | Returns values such as the C int64 base type of a given JavaScript number.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueStringLatin1](#oh_jsvm_getvaluestringlatin1) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, char \*buf, size_t bufsize, size_t \*result) | Returns the ISO-8859-1 encoded string corresponding to the input value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueStringUtf8](#oh_jsvm_getvaluestringutf8) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, char \*buf, size_t bufsize, size_t \*result) | Returns a UTF8 encoded string corresponding to the input value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueStringUtf16](#oh_jsvm_getvaluestringutf16) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, char16_t \*buf, size_t bufsize, size_t \*result) | Queries the UTF16-encoded string based on the input value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetValueUint32](#oh_jsvm_getvalueuint32) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, uint32_t \*result) | Returns values such as the C uint_32 base type of a given JavaScript number.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetBoolean](#oh_jsvm_getboolean) ([JSVM_Env](#jsvm_env) env, bool value, [JSVM_Value](#jsvm_value) \*result) | Returns a JavaScript singleton object used to represent a given Boolean value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetGlobal](#oh_jsvm_getglobal) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | The global object is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetNull](#oh_jsvm_getnull) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | The null object is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetUndefined](#oh_jsvm_getundefined) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) \*result) | The Undefined object is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CoerceToBool](#oh_jsvm_coercetobool) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_Value](#jsvm_value) \*result) | Implement the abstract operation ToBoolean().| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CoerceToNumber](#oh_jsvm_coercetonumber) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_Value](#jsvm_value) \*result) | Implement the abstract operation ToNumber(). If the input value is an object, the function may run JavaScript code.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CoerceToObject](#oh_jsvm_coercetoobject) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_Value](#jsvm_value) \*result) | Implement the abstract operation ToObject().| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CoerceToString](#oh_jsvm_coercetostring) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_Value](#jsvm_value) \*result) | Implement the abstract operation ToString(). If the input value is an object, the function may run JavaScript code.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_Typeof](#oh_jsvm_typeof) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, [JSVM_ValueType](#jsvm_valuetype) \*result) | Provides behavior similar to calling the typeof operator on a defined object. The difference is that this function supports the detection of external values; it detects null as a separate type, while ECMAScript typeof is used to detect objects. If the value type is invalid, an error is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_Instanceof](#oh_jsvm_instanceof) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) constructor, bool \*result) | Provides behavior similar to calling the instanceof operator on an object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_IsArray](#oh_jsvm_isarray) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Provides behavior similar to calling IsArray on an object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_IsArraybuffer](#oh_jsvm_isarraybuffer) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Check whether the input object is ArrayBuffer.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_IsDate](#oh_jsvm_isdate) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isDate) | Check whether the transferred object is a date.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_IsTypedarray](#oh_jsvm_istypedarray) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Ensure that the input object is a typed array.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_IsDataview](#oh_jsvm_isdataview) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Ensure that the input object is a DataView.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_StrictEquals](#oh_jsvm_strictequals) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) lhs, [JSVM_Value](#jsvm_value) rhs, bool \*result) | Provides behavior similar to invoking a strict equality algorithm.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_DetachArraybuffer](#oh_jsvm_detacharraybuffer) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) arraybuffer) | Provides behavior similar to calling the ArrayBuffer detach operation.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_IsDetachedArraybuffer](#oh_jsvm_isdetachedarraybuffer) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*result) | Provides behavior similar to calling ArrayBuffer IsDetachedBuffer.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetPropertyNames](#oh_jsvm_getpropertynames) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) \*result) | Returns the name of the enumerable property of an object as an array of characters. The attributes of the object whose key is a symbol are not included.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetAllPropertyNames](#oh_jsvm_getallpropertynames) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_KeyCollectionMode](#jsvm_keycollectionmode) keyMode, [JSVM_KeyFilter](#jsvm_keyfilter) keyFilter, [JSVM_KeyConversion](#jsvm_keyconversion) keyConversion, [JSVM_Value](#jsvm_value) \*result) | Returns an array containing the names of the available properties for this object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_SetProperty](#oh_jsvm_setproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) key, [JSVM_Value](#jsvm_value) value) | Sets an attribute for the input object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetProperty](#oh_jsvm_getproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) key, [JSVM_Value](#jsvm_value) \*result) | Obtains the attributes of the request from the input object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_HasProperty](#oh_jsvm_hasproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) key, bool \*result) | Checks if the passed Object has the property with the specified name.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_DeleteProperty](#oh_jsvm_deleteproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) key, bool \*result) | Attempt to delete the attribute of the key from the object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_HasOwnProperty](#oh_jsvm_hasownproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, [JSVM_Value](#jsvm_value) key, bool \*result) | Check whether the input object has its own named attribute. The key must be a string or symbol. Otherwise, an error is thrown. The JSVM-API does not perform any conversion between data types.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_SetNamedProperty](#oh_jsvm_setnamedproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, const char \*utf8name, [JSVM_Value](#jsvm_value) value) | This method is equivalent to invoking OH_JSVM_SetProperty. The string transferred through utf8Name is used to create JSVM_Value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetNamedProperty](#oh_jsvm_getnamedproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, const char \*utf8name, [JSVM_Value](#jsvm_value) \*result) | This method is equivalent to invoking OH_JSVM_GetProperty. The string transferred through utf8Name is used to create JSVM_Value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_HasNamedProperty](#oh_jsvm_hasnamedproperty) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, const char \*utf8name, bool \*result) | This method is equivalent to calling OH_JSVM_HasProperty with JSVM_Value created from the string passed as utf8Name.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_SetElement](#oh_jsvm_setelement) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, uint32_t index, [JSVM_Value](#jsvm_value) value) | Sets an element on the passed Object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetElement](#oh_jsvm_getelement) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, uint32_t index, [JSVM_Value](#jsvm_value) \*result) | Obtains the element at the request index.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_HasElement](#oh_jsvm_haselement) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, uint32_t index, bool \*result) | This JSVM-API returns true if the passed Object has an element at the specified index.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_DeleteElement](#oh_jsvm_deleteelement) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, uint32_t index, bool \*result) | Attempt to delete the element at the specified index from the object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_DefineProperties](#oh_jsvm_defineproperties) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object, size_t propertyCount, const [JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) \*properties) | This method allows you to efficiently define multiple attributes on a given object using attribute descriptors. Through an array of property descriptors, this API sets the properties in the array in turn for the object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_ObjectFreeze](#oh_jsvm_objectfreeze) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object) | Freezes a specified object. This prevents adding new attributes to it, deleting existing attributes, changing the enumerability, configurability, or writeability of existing attributes, or changing the value of an existing attribute. It also prevents changing the prototype of an object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_ObjectSeal](#oh_jsvm_objectseal) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) object) | Encapsulates a specified object. This prevents new attributes from being added to it and marks all existing attributes as unconfigurable.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CallFunction](#oh_jsvm_callfunction) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) recv, [JSVM_Value](#jsvm_value) func, size_t argc, const [JSVM_Value](#jsvm_value) \*argv, [JSVM_Value](#jsvm_value) \*result) | JavaScript function objects can be called from native code, which is the main mechanism for callback from native code to JavaScript.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateFunction](#oh_jsvm_createfunction) ([JSVM_Env](#jsvm_env) env, const char \*utf8name, size_t length, [JSVM_Callback](#jsvm_callback) cb, [JSVM_Value](#jsvm_value) \*result) | Function objects can be created in native code, which is the main mechanism for JavaScript to call native code. After this call, the newly created function is no longer automatically visible in the script. Instead, the setting property must be displayed on any object visible to JavaScript to access the function from the script.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetCbInfo](#oh_jsvm_getcbinfo) ([JSVM_Env](#jsvm_env) env, [JSVM_CallbackInfo](#jsvm_callbackinfo) cbinfo, size_t \*argc, [JSVM_Value](#jsvm_value) \*argv, [JSVM_Value](#jsvm_value) \*thisArg, void \*\*data) | This method is used in the callback function to retrieve details about the call, such as parameters from the given callback information and the **this** pointer.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetNewTarget](#oh_jsvm_getnewtarget) ([JSVM_Env](#jsvm_env) env, [JSVM_CallbackInfo](#jsvm_callbackinfo) cbinfo, [JSVM_Value](#jsvm_value) \*result) | Returns the new target called by the constructor function. If the current callback is not a constructor function call, the result is NULL.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_NewInstance](#oh_jsvm_newinstance) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) constructor, size_t argc, const [JSVM_Value](#jsvm_value) \*argv, [JSVM_Value](#jsvm_value) \*result) | Instantiates a new JavaScript value using the constructor represented by the given JSVM_Value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_DefineClass](#oh_jsvm_defineclass) ([JSVM_Env](#jsvm_env) env, const char \*utf8name, size_t length, [JSVM_Callback](#jsvm_callback) constructor, size_t propertyCount, const [JSVM_PropertyDescriptor](_j_s_v_m___property_descriptor.md) \*properties, [JSVM_Value](#jsvm_value) \*result) | Define a JavaScript class.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_Wrap](#oh_jsvm_wrap) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsObject, void \*nativeObject, [JSVM_Finalize](#jsvm_finalize) finalizeCb, void \*finalizeHint, [JSVM_Ref](#jsvm_ref) \*result) | Encapsulate the native instance in the JavaScript object. The native instance can be retrieved using OH_JSVM_Unwrap().| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_Unwrap](#oh_jsvm_unwrap) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsObject, void \*\*result) | When JavaScript code calls a method or property accessor of a class, the corresponding JSVM_Callback is called. If the callback is for an instance method or accessor, the **this** parameter of the callback is the wrapper object. Then, you can call OH_JSVM_Unwrap() of the wrapper object to obtain the C++ instance as the invoking target.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_RemoveWrap](#oh_jsvm_removewrap) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsObject, void \*\*result) | Use OH_JSVM_Wrap() to retrieve the native instance previously encapsulated in the JavaScript object js_object and remove the encapsulation. If the finalize callback is associated with encapsulation, it is no longer called when the JavaScript object is garbage collected.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_TypeTagObject](#oh_jsvm_typetagobject) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, const [JSVM_TypeTag](_j_s_v_m___type_tag.md) \*typeTag) | Associates the value of the typeTag pointer with a JavaScript object or an external value. You can call OH_JSVM_CheckObjectTypeTag() to determine the type of the tag attached to the object to ensure that the object type is correct. If the object already has an associated type tag, JSVM_INVALID_ARG is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CheckObjectTypeTag](#oh_jsvm_checkobjecttypetag) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, const [JSVM_TypeTag](_j_s_v_m___type_tag.md) \*typeTag, bool \*result) | Compares the type tag typeTag with the tag on the JavaScript object or external value. If the same tag is found, set result to true. Otherwise, set result to false.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_AddFinalizer](#oh_jsvm_addfinalizer) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsObject, void \*finalizeData, [JSVM_Finalize](#jsvm_finalize) finalizeCb, void \*finalizeHint, [JSVM_Ref](#jsvm_ref) \*result) | Add the JSVM_Finalize callback function for the JavaScript object. This callback function is called when the JavaScript object is garbage collected. OH_JSVM_AddFinalizer can be called multiple times on a single JavaScript object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetVersion](#oh_jsvm_getversion) ([JSVM_Env](#jsvm_env) env, uint32_t \*result) | Returns the highest JSVM-API version supported by the JSVM runtime. JSVM-API will be added in the future to support more functions. The purpose of introducing this API is as follows: In the JSVM version that supports a certain function, new functions can be used. In the JSVM version that does not support a certain function, callback behavior can be provided.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_GetVMInfo](#oh_jsvm_getvminfo) ([JSVM_VMInfo](_j_s_v_m___v_m_info.md) \*result) | The VM information is returned.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_AdjustExternalMemory](#oh_jsvm_adjustexternalmemory) ([JSVM_Env](#jsvm_env) env, int64_t changeInBytes, int64_t \*result) | This function notifies the underlying virtual machine of the externally allocated memory size that remains active due to the JavaScript object. Registering externally allocated memory will trigger global garbage collection more frequently than other ways.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_MemoryPressureNotification](#oh_jsvm_memorypressurenotification) ([JSVM_Env](#jsvm_env) env, [JSVM_MemoryPressureLevel](#jsvm_memorypressurelevel) level) | Notifies the VM that the system memory is insufficient and selectively triggers garbage collection.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreatePromise](#oh_jsvm_createpromise) ([JSVM_Env](#jsvm_env) env, [JSVM_Deferred](#jsvm_deferred) \*deferred, [JSVM_Value](#jsvm_value) \*promise) | Creates a delay object and a JavaScript promise.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_ResolveDeferred](#oh_jsvm_resolvedeferred) ([JSVM_Env](#jsvm_env) env, [JSVM_Deferred](#jsvm_deferred) deferred, [JSVM_Value](#jsvm_value) resolution) | Parses the JavaScript promise through the delay object associated with it. It can only be used to parse the JavaScript Promise of the corresponding available delay object. This means that Promise must be created using OH_JSVM_CreatePromise(), and the object returned from the call must be retained before it can be passed to this API.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_RejectDeferred](#oh_jsvm_rejectdeferred) ([JSVM_Env](#jsvm_env) env, [JSVM_Deferred](#jsvm_deferred) deferred, [JSVM_Value](#jsvm_value) rejection) | Rejects JavaScript Promise through the delayed object associated with it. It can only be used to reject JavaScript Promise of the corresponding available delay object. This means that Promise must be created using OH_JSVM_CreatePromise(), and the object returned from the call must be retained before it can be passed to this API.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_IsPromise](#oh_jsvm_ispromise) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) value, bool \*isPromise) | Queries whether the Promise object is a native Promise object.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_JsonParse](#oh_jsvm_jsonparse) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsonString, [JSVM_Value](#jsvm_value) \*result) | Parses the JSON string and returns the successfully parsed value.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_JsonStringify](#oh_jsvm_jsonstringify) ([JSVM_Env](#jsvm_env) env, [JSVM_Value](#jsvm_value) jsonObject, [JSVM_Value](#jsvm_value) \*result) | Converts an object to a string and returns the string that is successfully converted.| 
| JSVM_EXTERN [JSVM_Status](#jsvm_status)[OH_JSVM_CreateSnapshot](#oh_jsvm_createsnapshot) ([JSVM_VM](#jsvm_vm) vm, size_t contextCount, const [JSVM_Env](#jsvm_env) \*contexts, const char \*\*blobData, size_t \*blobSize) | This interface is used to create a startup snapshot for a VM.| 


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

Function pointer type of native functions provided by users. These functions are exposed to JavaScript through the JSVM-API interface.

**Since**: 11


### JSVM_CallbackInfo

```
typedef struct JSVM_CallbackInfo__* JSVM_CallbackInfo
```

**Description**

Represents the opaque data type passed to the callback function. It can be used to obtain additional information about the context in which the function is called.

**Since**: 11


### JSVM_Deferred

```
typedef struct JSVM_Deferred__* JSVM_Deferred
```

**Description**

Promise delay object.

**Since**: 11


### JSVM_Env

```
typedef struct JSVM_Env__* JSVM_Env
```

**Description**

Indicates the context environment of a specific VM state. It needs to be transferred as a parameter when the native function is called and transferred to any subsequent JSVM-API nested invoking.

**Since**: 11


### JSVM_EnvScope

```
typedef struct JSVM_EnvScope__* JSVM_EnvScope
```

**Description**

Represents the environment used to control the attachment to the current virtual machine instance. The environment is available to the virtual machine instance of the thread only after the thread enters the JSVM_EnvScope of the environment through OH_JSVM_OpenEnvScope.

**Since**: 11


### JSVM_EscapableHandleScope

```
typedef struct JSVM_EscapableHandleScope__* JSVM_EscapableHandleScope
```

**Description**

Indicates a special type of handle scope, which is used to return the value created in a specific handle scope to the parent scope.

**Since**: 11


### JSVM_Finalize

```
typedef void(JSVM_CDECL* JSVM_Finalize) (JSVM_Env env, void *finalizeData, void *finalizeHint)
```

**Description**

Function pointer type. When a native object or data is associated with a JS object, this pointer is transferred. This function is called when the associated JS object is reclaimed by the GC to execute the native cleanup action.

**Since**: 11


### JSVM_HandleScope

```
typedef struct JSVM_HandleScope__* JSVM_HandleScope
```

**Description**

Indicates the scope of a JavaScript value. It is used to control and modify the lifecycle of an object created in a specific scope. Typically, JSVM-API values are created in the context of JSVM_HandleScope. When the native method is called from JavaScript, the default JSVM_HandleScope exists. If the user does not explicitly create a new JSVM_HandleScope, the JSVM-API value is created in the default JSVM_HandleScope. For any code call other than native method execution (for example, during libuv callback calls), the module needs to create a scope before calling any function that may cause JavaScript value creation. JSVM_HandleScope is created using OH_JSVM_OpenHandleScope and destroyed using OH_JSVM_CloseHandleScope. Closing the scope represents indicating to the GC that all JSVM_Values created during the lifecycle of the JSVM_HandleScope scope will no longer be referenced from the stack frame of the current heap.

**Since**: 11


### JSVM_Ref

```
typedef struct JSVM_Ref__* JSVM_Ref
```

**Description**

Represents a reference to a JavaScript value.

**Since**: 11


### JSVM_Script

```
typedef struct JSVM_Script__* JSVM_Script
```

**Description**

Indicates a piece of JavaScript code.

**Since**: 11


### JSVM_Value

```
typedef struct JSVM_Value__* JSVM_Value
```

**Description**

Indicates the JavaScript value.

**Since**: 11


### JSVM_VM

```
typedef struct JSVM_VM__* JSVM_VM
```

**Description**

Indicates a JavaScript VM instance.

**Since**: 11


### JSVM_VMScope

```
typedef struct JSVM_VMScope__* JSVM_VMScope
```

**Description**

Indicates the scope of the JavaScript virtual machine.

**Since**: 11


## Enum Description


### JSVM_KeyCollectionMode

```
enum JSVM_KeyCollectionMode
```

**Description**

Limits the range of attributes to be searched for.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_KEY_INCLUDE_PROTOTYPES | It also contains attributes on the object prototype chain.| 
| JSVM_KEY_OWN_ONLY | Contains only the attributes of the object itself.| 


### JSVM_KeyConversion

```
enum JSVM_KeyConversion
```

**Description**

Key conversion option.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_KEY_KEEP_NUMBERS | The number of the integer index is returned.| 
| JSVM_KEY_NUMBERS_TO_STRINGS | Converts an integer index to a string.| 


### JSVM_KeyFilter

```
enum JSVM_KeyFilter
```

**Description**

Attribute filter. You can use or to construct a composite filter.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_KEY_ALL_PROPERTIES | Key of all attributes.| 
| JSVM_KEY_WRITABLE | Writable key.| 
| JSVM_KEY_ENUMERABLE | Enumerable key.| 
| JSVM_KEY_CONFIGURABLE | Configurable key.| 
| JSVM_KEY_SKIP_STRINGS | Excludes keys of the string type.| 
| JSVM_KEY_SKIP_SYMBOLS | Excludes keys of the symbol type.| 


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
| JSVM_MEMORY_PRESSURE_LEVEL_MODERATE | Medium pressure.| 
| JSVM_MEMORY_PRESSURE_LEVEL_CRITICAL | Critical pressure.| 


### JSVM_PropertyAttributes

```
enum JSVM_PropertyAttributes
```

**Description**

Controls the behavior of JavaScript object attributes.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_DEFAULT | The explicit attribute is not set on the attribute.| 
| JSVM_WRITABLE | This attribute is writable.| 
| JSVM_ENUMERABLE | This attribute is enumerable.| 
| JSVM_CONFIGURABLE | This attribute is configurable.| 
| JSVM_STATIC | This property will be defined as a static property of the class, not the default instance property. This is used only by OH_JSVM_DefineClass.| 
| JSVM_DEFAULT_METHOD | Like a method in a JS class, this property is configurable and writable, but innumerable.| 
| JSVM_DEFAULT_JSPROPERTY | Like properties set by assignment in JavaScript, properties are writable, enumerable, and configurable.| 


### JSVM_Status

```
enum JSVM_Status
```

**Description**

Complete status code indicating whether the JSVM-API invoking is successful or fails.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_OK | Indicates the success status.| 
| JSVM_INVALID_ARG | Invalid status.| 
| JSVM_OBJECT_EXPECTED | The object type is expected to be transferred.| 
| JSVM_STRING_EXPECTED | The string type is expected to be transferred.| 
| JSVM_NAME_EXPECTED | The name type is expected to be transferred.| 
| JSVM_FUNCTION_EXPECTED | The input function type is expected.| 
| JSVM_NUMBER_EXPECTED | The number type is expected to be transferred.| 
| JSVM_BOOLEAN_EXPECTED | The Boolean type is expected.| 
| JSVM_ARRAY_EXPECTED | The input array type is expected.| 
| JSVM_GENERIC_FAILURE | Generic failure status.| 
| JSVM_PENDING_EXCEPTION | Suspend the abnormal state.| 
| JSVM_CANCELLED | Indicates the cancellation status.| 
| JSVM_ESCAPE_CALLED_TWICE | The escape function is called twice.| 
| JSVM_HANDLE_SCOPE_MISMATCH | The handle scope does not match.| 
| JSVM_CALLBACK_SCOPE_MISMATCH | The callback scope does not match.| 
| JSVM_QUEUE_FULL | The queue is full.| 
| JSVM_CLOSING | Closing| 
| JSVM_BIGINT_EXPECTED | The Bigint type is expected to be transferred.| 
| JSVM_DATE_EXPECTED | The date type is expected to be transferred.| 
| JSVM_ARRAYBUFFER_EXPECTED | The ArrayBuffer type is expected to be transferred.| 
| JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED | Expected state of the separable array buffer.| 
| JSVM_WOULD_DEADLOCK | Deadlock state.| 
| JSVM_NO_EXTERNAL_BUFFERS_ALLOWED | External buffers are not allowed.| 
| JSVM_CANNOT_RUN_JS | The JS cannot be executed.| 


### JSVM_TypedarrayType

```
enum JSVM_TypedarrayType
```

**Description**

Type of a TypedArray.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_INT8_ARRAY | The value is of the int8 type.| 
| JSVM_UINT8_ARRAY | Indicates the uint8 type.| 
| JSVM_UINT8_CLAMPED_ARRAY | uint8: fixed type.| 
| JSVM_INT16_ARRAY | The value is of the int16 type.| 
| JSVM_UINT16_ARRAY | The value is of the uint16 type.| 
| JSVM_INT32_ARRAY | The value is of the int32 type.| 
| JSVM_UINT32_ARRAY | The value is of the uint32 type.| 
| JSVM_FLOAT32_ARRAY | The value is of the float32 type.| 
| JSVM_FLOAT64_ARRAY | The value is of the float64 type.| 
| JSVM_BIGINT64_ARRAY | The value is of the bigint64 type.| 
| JSVM_BIGUINT64_ARRAY | biguint64.| 


### JSVM_ValueType

```
enum JSVM_ValueType
```

**Description**

Describes the JSVM_Value type.

**Since**: 11

| Value| Description| 
| -------- | -------- |
| JSVM_UNDEFINED | Undefined type.| 
| JSVM_NULL | Null type.| 
| JSVM_BOOLEAN | Boolean.| 
| JSVM_NUMBER | Numeric field.| 
| JSVM_STRING | String type.| 
| JSVM_SYMBOL | Symbol type.| 
| JSVM_OBJECT | Object type.| 
| JSVM_FUNCTION | Function type.| 
| JSVM_EXTERNAL | External type.| 
| JSVM_BIGINT | The value is of the bigint type.| 


## Function Description


### OH_JSVM_AddFinalizer()

```
JSVM_EXTERN JSVM_Status OH_JSVM_AddFinalizer (JSVM_Env env, JSVM_Value jsObject, void * finalizeData, JSVM_Finalize finalizeCb, void * finalizeHint, JSVM_Ref * result )
```

**Description**

Add the JSVM_Finalize callback function for the JavaScript object. This callback function is called when the JavaScript object is garbage collected. OH_JSVM_AddFinalizer can be called multiple times on a single JavaScript object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| jsObject | JavaScript object associated with native data.| 
| finalizeData | Optional data to be transferred to finalizeCb.| 
| finalizeCb | When a JavaScript object is garbage collected, it is used to release the native callback of native data. JSVM_Finalize provides more details.| 
| finalizeHint | Optional context hint passed to the finalize callback.| 
| result | Optional reference to a JavaScript object.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_INVALID_ARG may be returned.


### OH_JSVM_AdjustExternalMemory()

```
JSVM_EXTERN JSVM_Status OH_JSVM_AdjustExternalMemory (JSVM_Env env, int64_t changeInBytes, int64_t * result )
```

**Description**

This function notifies the underlying virtual machine of the externally allocated memory size that remains active due to the JavaScript object. Registering externally allocated memory will trigger global garbage collection more frequently than other ways.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| changeInBytes | Changes in external allocated memory that remains active due to JavaScript objects.| 
| result | Indicates the adjustment value.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CallFunction()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CallFunction (JSVM_Env env, JSVM_Value recv, JSVM_Value func, size_t argc, const JSVM_Value * argv, JSVM_Value * result )
```

**Description**

JavaScript function objects can be called from native code, which is the main mechanism for callback from native code to JavaScript.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| recv | Value of this passed to the called function.| 
| func | Indicates the JavaScript function to be called.| 
| argc | Number of elements in the argv array.| 
| argv | JSVM_values array, representing the JavaScript value to be passed to the function as a parameter.| 
| result | Indicates the returned JavaScript object.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_PENDING_EXCEPTION or JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_CheckObjectTypeTag()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CheckObjectTypeTag (JSVM_Env env, JSVM_Value value, const JSVM_TypeTag * typeTag, bool * result )
```

**Description**

Compares the type tag typeTag with the tag on the JavaScript object or external value. If the same tag is found, set result to true. Otherwise, set result to false.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript object or external value of the type tag to be checked.| 
| typeTag | A label used to compare any labels found on an object.| 
| result | Indicates whether the specified type tag matches the type tag on the object. If the type tag cannot be found on the object, false is also returned.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_CloseEnvScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CloseEnvScope (JSVM_Env env, JSVM_EnvScope scope )
```

**Description**

Close the environment scope.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | target environment where the JSVM-API interface will be called.| 
| scope | Environment scope to be closed.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CloseEscapableHandleScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CloseEscapableHandleScope (JSVM_Env env, JSVM_EscapableHandleScope scope )
```

**Description**

Closes the incoming scope. Scopes must be closed in the reverse order of creating scopes. This JSVM_API can be called even if a suspended JavaScript exception exists.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| scope | Indicates the scope to be disabled.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_HANDLE_SCOPE_MISMATCH may be returned.


### OH_JSVM_CloseHandleScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CloseHandleScope (JSVM_Env env, JSVM_HandleScope scope )
```

**Description**

Closes the incoming scope. Scopes must be closed in the reverse order of creating scopes.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| scope | Indicates the scope to be disabled.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CloseVMScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CloseVMScope (JSVM_VM vm, JSVM_VMScope scope )
```

**Description**

Disable the VM scope of the VM instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | Target VM instance.| 
| scope | Specifies the scope of the VM to be shut down.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CoerceToBool()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToBool (JSVM_Env env, JSVM_Value value, JSVM_Value * result )
```

**Description**

Implement the abstract operation ToBoolean().

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value to be forcibly converted.| 
| result | Indicates the mandatory JavaScript Boolean.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CoerceToNumber()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToNumber (JSVM_Env env, JSVM_Value value, JSVM_Value * result )
```

**Description**

Implement the abstract operation ToNumber(). If the input value is an object, the function may run JavaScript code.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value to be forcibly converted.| 
| result | Indicates the mandatory JavaScript number.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CoerceToObject()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToObject (JSVM_Env env, JSVM_Value value, JSVM_Value * result )
```

**Description**

Implement the abstract operation ToObject().

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value to be forcibly converted.| 
| result | Indicates the mandatory JavaScript object.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CoerceToString()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CoerceToString (JSVM_Env env, JSVM_Value value, JSVM_Value * result )
```

**Description**

Implement the abstract operation ToString(). If the input value is an object, the function may run JavaScript code.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value to be forcibly converted.| 
| result | Indicates the mandatory JavaScript string.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


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
| env | target environment where the JSVM-API interface will be called.| 
| script | JavaScript code that contains the script to be compiled.| 
| cachedData | In this case, the parameter is optional. Code cache data of the script.| 
| cacheDataLength | Length of the cachedData array.| 
| eagerCompile | Indicates whether to compile the script immediately.| 
| cacheRejected | Indicates whether the code cache is rejected by compilation.| 
| result | Compiled script.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_STRING_EXPECTED or JSVM_GENERIC_FAILURE may be returned.


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
| env | Environment for invoking the JSVM-API.| 
| result | JSVM_Value representing the JavaScript Array.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateArraybuffer()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateArraybuffer (JSVM_Env env, size_t byteLength, void ** data, JSVM_Value * result )
```

**Description**

The JSVM-API value corresponding to the JavaScript ArrayBuffer type is returned. ArrayBuffer is used to represent a fixed-length binary data buffer. It is usually used as a backup buffer for TypedArray objects. The allocated ArrayBuffer has an underlying byte buffer whose size is determined by the length parameter passed in. The underlying buffer can be returned to the caller, and the caller can directly operate the buffer. This buffer can only be written directly from native code. If you want to write data from JavaScript to the buffer, you need to create a TypedArray or DataView object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| byteLength | The byte length of the array buffer to be created.| 
| data | Pointer to the underlying byte buffer of ArrayBuffer. data can be selectively ignored by passing NULL.| 
| result | JSVM_Value representing the JavaScript ArrayBuffer.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateArrayWithLength()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateArrayWithLength (JSVM_Env env, size_t length, JSVM_Value * result )
```

**Description**

Returns the JSVM-API value corresponding to the JavaScript Array type. The length attribute of the array is set to the input length parameter. However, there is no guarantee that the underlying buffer is pre-allocated by the VM when the array is created. This behavior is left to the underlying VM implementation.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| length | Initial length of an array.| 
| result | JSVM_Value representing the JavaScript Array.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateBigintInt64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateBigintInt64 (JSVM_Env env, int64_t value, JSVM_Value * result )
```

**Description**

Converts a value of the C int64_t type to the JavaScript BigInt type.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Integer value to be represented in JavaScript.| 
| result | JSVM_Value of the JavaScript BigInt type.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateBigintUint64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateBigintUint64 (JSVM_Env env, uint64_t value, JSVM_Value * result )
```

**Description**

Converts a value of the C uint64_t type to the JavaScript BigInt type.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Unsigned integer value to be represented in JavaScript.| 
| result | JSVM_Value representing the JavaScript BigInt type.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateBigintWords()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateBigintWords (JSVM_Env env, int signBit, size_t wordCount, const uint64_t * words, JSVM_Value * result )
```

**Description**

Converts a set of unsigned 64-bit words to a single BigInt value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| signBit | Determines whether the generated BigInt is positive or negative.| 
| wordCount | Length of the words array.| 
| words | uint64_t little-endian 64-bit word array.| 
| result | JSVM_Value representing the JavaScript BigInt type.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_INVALID_ARG or JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_CreateCodeCache()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateCodeCache (JSVM_Env env, JSVM_Script script, const uint8_t ** data, size_t * length )
```

**Description**

Create a code cache for the compiled script.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | target environment where the JSVM-API interface will be called.| 
| script | Target compilation script.| 
| data | Data cached in the code.| 
| length | Length of the code cache data.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_CreateDataview()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateDataview (JSVM_Env env, size_t length, JSVM_Value arraybuffer, size_t byteOffset, JSVM_Value * result )
```

**Description**

Creates a JavaScript DataView object based on an existing ArrayBuffer object. The DataView object provides an array-like view on the underlying data buffer, where elements can have different sizes and types. The binary value of length plus byteOffset must be less than or equal to the size of the input array (in bytes). Otherwise, a range error (RangeError) is thrown.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| length | Number of elements in the DataView.| 
| arraybuffer | ArrayBuffer at the bottom layer of DataView.| 
| byteOffset | Byte offset in ArrayBuffer, indicating the start position of the projected DataView.| 
| result | Represents the JSVM_Value of a JavaScript DataView object.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_PENDING_EXCEPTION may be returned.


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
| env | Environment for invoking the JSVM-API.| 
| time | ECMAScript time value (in milliseconds) since UTC on January 1, 1970.| 
| result | Represents the JSVM_Value of a JavaScript Date object.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_CreateDouble()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateDouble (JSVM_Env env, double value, JSVM_Value * result )
```

**Description**

Converts a value of the C double type to a value of the JavaScript number type.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Double-precision value to be represented in JavaScript.| 
| result | JSVM_Value representing the JavaScript number type.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateEnv()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateEnv (JSVM_VM vm, size_t propertyCount, const JSVM_PropertyDescriptor * properties, JSVM_Env * result )
```

**Description**

Creates a new environment based on the optional attributes of the new environment context.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | VM instance. The new environment will be created in this instance.| 
| propertyCount | Number of elements in the attribute array.| 
| properties | Array of attribute descriptors.| 
| result | Indicates the created environment.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateEnvFromSnapshot()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateEnvFromSnapshot (JSVM_VM vm, size_t index, JSVM_Env * result )
```

**Description**

Creates a new environment based on the start snapshot of the VM.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | VM instance. The new environment will be created in this instance.| 
| index | Index of the environment in the snapshot.| 
| result | Indicates the created environment.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_CreateError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateError (JSVM_Env env, JSVM_Value code, JSVM_Value msg, JSVM_Value * result )
```

**Description**

Returns a JavaScript Error with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| code | Optional JSVM_Value, a string with the error code associated with the error.| 
| msg | References a JavaScript string as an Error message.| 
| result | Indicates a creation error.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_STRING_EXPECTED may be returned.


### OH_JSVM_CreateExternal()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateExternal (JSVM_Env env, void * data, JSVM_Finalize finalizeCb, void * finalizeHint, JSVM_Value * result )
```

**Description**

Assigns a JavaScript value with external data. This is used to pass external data through JavaScript code. In the future, OH_JSVM_GetValueExternal can be used for retrieval by native code. A JSVM_Finalize callback is added to this API. This callback is called when the newly created JavaScript object is garbage collected. The created value is not an object, so additional attributes are not supported. It is considered a unique value type: calling OH_JSVM_Typeof() with an external value generates JSVM_EXTERNAL.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| data | Raw pointer to external data.| 
| finalizeCb | Optional callback called to collect external values. JSVM_Finalize provides more details.| 
| finalizeHint | Optional hints passed to the final callback during collection.| 
| result | JSVM_Value representing an external value.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateFunction()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateFunction (JSVM_Env env, const char * utf8name, size_t length, JSVM_Callback cb, JSVM_Value * result )
```

**Description**

Function objects can be created in native code, which is the main mechanism for JavaScript to call native code. After this call, the newly created function is no longer automatically visible in the script. Instead, the setting property must be displayed on any object visible to JavaScript to access the function from the script.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| utf8Name | Optional name of a function encoded in UTF8. This is visible in JavaScript as the name attribute of the new function object.| 
| length | Length of utf8name (in bytes) or JSVM_AUTO_LENGTH (if ending with null).| 
| cb | Native function that needs to be called when this function object is called. For details, see JSVM_Callback.| 
| result | Indicates the JavaScript function object of the newly created function.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateInt32()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateInt32 (JSVM_Env env, int32_t value, JSVM_Value * result )
```

**Description**

Converts a value of the C int32_t type to a value of the JavaScript number type.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Integer value to be represented in JavaScript.| 
| result | JSVM_Value of the JavaScript number type.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateInt64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateInt64 (JSVM_Env env, int64_t value, JSVM_Value * result )
```

**Description**

Converts a value of the C int64_t type to a value of the JavaScript number type.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Integer value to be represented in JavaScript.| 
| result | JSVM_Value representing the JavaScript number type.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateObject()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateObject (JSVM_Env env, JSVM_Value * result )
```

**Description**

Assigns a default JavaScript object. This function is equivalent to executing new Object() in JavaScript.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| result | Represents the JSVM_Value of a JavaScript object.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreatePromise()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreatePromise (JSVM_Env env, JSVM_Deferred * deferred, JSVM_Value * promise )
```

**Description**

Creates a delay object and a JavaScript promise.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| deferred | A newly created delay object that can be later passed to OH_JSVM_ResolveDeferred() or [OH_JSVM_RejectDeferred()](#oh_jsvm_rejectdeferred) to parse resp. or reject the relevant Promise.| 
| promise | JavaScript Promise associated with the delayed object.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_CreateRangeError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateRangeError (JSVM_Env env, JSVM_Value code, JSVM_Value msg, JSVM_Value * result )
```

**Description**

Returns a JavaScript RangeError with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| code | Optional JSVM_Value, a string with the error code associated with the error.| 
| msg | References a JavaScript string as an Error message.| 
| result | Indicates a creation error.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_STRING_EXPECTED may be returned.


### OH_JSVM_CreateReference()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateReference (JSVM_Env env, JSVM_Value value, uint32_t initialRefcount, JSVM_Ref * result )
```

**Description**

Creates a new reference with the specified reference count for the value passed in.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JSVM_Value for which a reference is being created.| 
| initialRefcount | Initial reference count of the new reference.| 
| result | Point to the new reference.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateSnapshot()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateSnapshot (JSVM_VM vm, size_t contextCount, const JSVM_Env * contexts, const char ** blobData, size_t * blobSize )
```

**Description**

Create a VM startup snapshot.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| vm | Specifies the target environment in which the API will be called.| 
| contextCount | Number of contexts.| 
| contexts | The array of contexts to add to the snapshot.| 
| blobData | Snapshot data.| 
| blobSize | Size of the snapshot data.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_CreateStringLatin1()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateStringLatin1 (JSVM_Env env, const char * str, size_t length, JSVM_Value * result )
```

**Description**

Converts a C string encoded using ISO-8859-1 to a JavaScript string value. Copies a native string.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| str | A character buffer representing an ISO-8859-1 encoded string.| 
| length | Length of a string, in bytes. JSVM_AUTO_LENGTH if it ends with null.| 
| result | JSVM_Value representing a JavaScript string.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateStringUtf16()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateStringUtf16 (JSVM_Env env, const char16_t * str, size_t length, JSVM_Value * result )
```

**Description**

Converts a C string encoded in UTF16-LE format to a JavaScript string value. Copies a native string.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| str | Represents a character buffer for UTF16-LE encoded strings.| 
| length | The length of the string represented in a two-byte code unit, or JSVM_AUTO_LENGTH if it terminates with null.| 
| result | JSVM_Value representing a JavaScript string.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateStringUtf8()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateStringUtf8 (JSVM_Env env, const char * str, size_t length, JSVM_Value * result )
```

**Description**

Creates a JavaScript string value from a UTF8-encoded C string. Copies a native string.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| str | Represents a character buffer for UTF8 encoded strings.| 
| length | Length of a string, in bytes. If the string ends with null, the value is JSVM_AUTO_LENGTH.| 
| result | JSVM_Value representing a JavaScript string.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


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
| env | Environment for invoking the JSVM-API.| 
| description | Optional JSVM_Value, which refers to the JavaScript string to be set to the symbol description.| 
| result | JSVM_Value representing a JavaScript symbol.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_STRING_EXPECTED may be returned.


### OH_JSVM_CreateSyntaxError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateSyntaxError (JSVM_Env env, JSVM_Value code, JSVM_Value msg, JSVM_Value * result )
```

**Description**

Returns a JavaScript SyntaxError with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| code | Optional JSVM_Value, a string with the error code associated with the error.| 
| msg | References a JavaScript string as an Error message.| 
| result | Indicates a creation error.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_STRING_EXPECTED may be returned.


### OH_JSVM_CreateTypedarray()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateTypedarray (JSVM_Env env, JSVM_TypedarrayType type, size_t length, JSVM_Value arraybuffer, size_t byteOffset, JSVM_Value * result )
```

**Description**

Creates a JavaScript TypedArray object based on an existing ArrayBuffer object. The TypedArray object provides an array-like view on the underlying data buffer, where each element has the same underlying binary scalar data type. The sum of (length\*element size) and byteOffset must be less than or equal to the size (in bytes) of the input array. Otherwise, a range error (RangeError) is thrown.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| type | Scalar data type of an element in TypedArray.| 
| length | Number of elements in TypedArray.| 
| arraybuffer | ArrayBuffer is the basis for typed arrays.| 
| byteOffset | Byte offset for starting projection of TypedArray in ArrayBuffer.| 
| result | JSVM_Value representing JavaScript TypedArray.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_INVALID_ARG may be returned.


### OH_JSVM_CreateTypeError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateTypeError (JSVM_Env env, JSVM_Value code, JSVM_Value msg, JSVM_Value * result )
```

**Description**

Returns a JavaScript TypeError with the provided text.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| code | Optional JSVM_Value, a string with the error code associated with the error.| 
| msg | References a JavaScript string as an Error message.| 
| result | Indicates a creation error.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_STRING_EXPECTED may be returned.


### OH_JSVM_CreateUint32()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateUint32 (JSVM_Env env, uint32_t value, JSVM_Value * result )
```

**Description**

Converts a value of the C uint32_t type to the JavaScript number type.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Unsigned integer value to be represented in JavaScript.| 
| result | JSVM_Value of the JavaScript number type.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_CreateVM()

```
JSVM_EXTERN JSVM_Status OH_JSVM_CreateVM (const JSVM_CreateVMOptions * options, JSVM_VM * result )
```

**Description**

Create a VM instance.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Specifies the option used to create a VM instance.| 
| result | New VM instance.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_INVALID_ARG may be returned.


### OH_JSVM_DefineClass()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DefineClass (JSVM_Env env, const char * utf8name, size_t length, JSVM_Callback constructor, size_t propertyCount, const JSVM_PropertyDescriptor * properties, JSVM_Value * result )
```

**Description**

Define a JavaScript class.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| utf8name | Name of the JavaScript constructor. You are advised to use the C++ class name when wrapping the C++ class.| 
| length | Length of utf8name (in bytes) or JSVM_AUTO_LENGTH (if ending with null).| 
| constructor | Callback function used to create the constructor of a class. When wrapping a C++ class, this method must comply with JSVM_Callback. Static member of the callback signature. C++ class constructors cannot be used. For details, see JSVM_Callback.| 
| propertyCount | Number of items in the properties array parameter.| 
| properties | Attribute descriptor of a class, which is used to define the attributes and methods of the class.| 
| result | JSVM_Value representing the constructor of the class.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_DefineProperties()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DefineProperties (JSVM_Env env, JSVM_Value object, size_t propertyCount, const JSVM_PropertyDescriptor * properties )
```

**Description**

This method allows you to efficiently define multiple attributes on a given object using attribute descriptors. Through an array of property descriptors, this API sets the properties in the array in turn for the object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object whose attributes are to be retrieved.| 
| propertyCount | Number of elements in the properties array.| 
| properties | Array of attribute descriptors.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_INVALID_ARG or JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_DeleteElement()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DeleteElement (JSVM_Env env, JSVM_Value object, uint32_t index, bool * result )
```

**Description**

Attempt to delete the element at the specified index from the object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object to be queried.| 
| index | Index of the attribute to be deleted.| 
| result | Indicates whether an element is successfully deleted.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_DeleteProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DeleteProperty (JSVM_Env env, JSVM_Value object, JSVM_Value key, bool * result )
```

**Description**

Attempt to delete the attribute of the key from the object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object to be queried.| 
| key | Name of the attribute to be deleted.| 
| result | Indicates whether an attribute is successfully deleted. The result can be selectively ignored by passing NULL.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_DeleteReference()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DeleteReference (JSVM_Env env, JSVM_Ref ref )
```

**Description**

Delete the transferred reference.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| ref | JSVM_Ref to be deleted.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_DestroyEnv()

```
JSVM_EXTERN JSVM_Status OH_JSVM_DestroyEnv (JSVM_Env env)
```

**Description**

Destroy the environment.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | environment to be destroyed.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


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
| vm | Specifies the VM instance to be destroyed.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


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
| env | Environment for invoking the JSVM-API.| 
| arraybuffer | JavaScript ArrayBuffer to be separated.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If an array buffer that cannot be disassembled is input, JSVM_DETACHABLE_ARRAYBUFFER_EXPECTED is returned.


### OH_JSVM_EscapeHandle()

```
JSVM_EXTERN JSVM_Status OH_JSVM_EscapeHandle (JSVM_Env env, JSVM_EscapableHandleScope scope, JSVM_Value escapee, JSVM_Value * result )
```

**Description**

Raises the handle of a JavaScript object so that it is valid for the lifecycle of the external scope. Each scope can be called only once. If this API is called for multiple times, an error is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| scope | Indicates the current scope.| 
| escapee | Indicates the JavaScript object to be promoted.| 
| result | Handle of the promoted object in the external scope.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_ESCAPE_CALLED_TWICE may be returned.


### OH_JSVM_GetAllPropertyNames()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetAllPropertyNames (JSVM_Env env, JSVM_Value object, JSVM_KeyCollectionMode keyMode, JSVM_KeyFilter keyFilter, JSVM_KeyConversion keyConversion, JSVM_Value * result )
```

**Description**

Returns an array containing the names of the available properties for this object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object from which the attribute is retrieved.| 
| keyMode | Indicates whether prototype attributes are also retrieved.| 
| keyFilter | Which attributes are to be retrieved (enumerated/readable/writable).| 
| keyConversion | Indicates whether to convert the numbered attribute key to a string.| 
| result | An array of JavaScript values that represent the attribute names of the object. You can use OH_JSVM_GetArrayLength and OH_JSVM_GetElement to iterate over the result.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_INVALID_ARG or JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_GetAndClearLastException()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetAndClearLastException (JSVM_Env env, JSVM_Value * result )
```

**Description**

Obtains and clears the last exception. If a suspension occurs, a JavaScript exception is returned. Otherwise, NULL is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| result | If a suspension occurs, an exception is returned. Otherwise, NULL is returned.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetArraybufferInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetArraybufferInfo (JSVM_Env env, JSVM_Value arraybuffer, void ** data, size_t * byteLength )
```

**Description**

Retrieves the underlying data buffer of the ArrayBuffer and its length.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| arraybuffer | Indicates the array buffer to be queried.| 
| data | Bottom-layer data buffer of ArrayBuffer. If byte_length is 0, the value may be NULL or any other pointer value.| 
| byteLength | Length of the underlying data buffer, in bytes.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_INVALID_ARG may be returned.


### OH_JSVM_GetArrayLength()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetArrayLength (JSVM_Env env, JSVM_Value value, uint32_t * result )
```

**Description**

Returns the length of an array.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript Array representing the length of the query.| 
| result | uint32 indicates the array length.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_ARRAY_EXPECTED may be returned.


### OH_JSVM_GetBoolean()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetBoolean (JSVM_Env env, bool value, JSVM_Value * result )
```

**Description**

Returns a JavaScript singleton object used to represent a given Boolean value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Boolean value to retrieve.| 
| result | Represents the JavaScript Boolean singleton to be retrieved.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetCbInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetCbInfo (JSVM_Env env, JSVM_CallbackInfo cbinfo, size_t * argc, JSVM_Value * argv, JSVM_Value * thisArg, void ** data )
```

**Description**

This method is used in the callback function to retrieve details about the call, such as parameters from the given callback information and the **this** pointer.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| cbinfo | Callback information transferred to the callback function.| 
| argc | Specifies the length of the supplied argv array and receives the actual number of arguments, which can be selectively ignored by passing NULL.| 
| argv | C array of JSVM_Value, which is used to store copied parameters. If the number of parameters exceeds the provided number, only the parameters of the requested number are copied. If fewer parameters are provided than declared, the rest of argv is populated by the JSVM_Value value representing undefined. You can ignore argv by passing NULL.| 
| thisArg | Receives the called JavaScript this parameter. ThisArg can be ignored by passing NULL.| 
| data | Pointer to the received callback data. data can be ignored by passing NULL.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetDataviewInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetDataviewInfo (JSVM_Env env, JSVM_Value dataview, size_t * bytelength, void ** data, JSVM_Value * arraybuffer, size_t * byteOffset )
```

**Description**

Returns various attributes of the DataView. If an attribute is not required, any output parameter can be set to NULL.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| dataview | Indicates the DataView whose attributes are to be queried.| 
| bytelength | Number of bytes in the DataView.| 
| data | Data buffer under DataView. If bytelength is 0, this may be NULL or any other pointer value.| 
| arraybuffer | ArrayBuffer is the basis of DataView.| 
| byteOffset | Byte offset in the data buffer that starts to project the DataView.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_INVALID_ARG may be returned.


### OH_JSVM_GetDateValue()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetDateValue (JSVM_Env env, JSVM_Value value, double * result )
```

**Description**

Returns the C double-precision base type for the time value of a given JavaScript Date. If the interface is called successfully, JSVM_OK is returned. If a JSVM_Value of the non-JavaScript Date type is transferred, JSVM_DATA_EXPECTED is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Indicates a JavaScript date.| 
| result | The time value as double is expressed as the number of milliseconds since midnight UTC on January 1, 1970.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_DATE_EXPECTED may be returned.


### OH_JSVM_GetElement()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetElement (JSVM_Env env, JSVM_Value object, uint32_t index, JSVM_Value * result )
```

**Description**

Obtains the element at the request index.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object whose attributes are to be retrieved.| 
| index | Index of the attribute to be obtained.| 
| result | Value of the attribute.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_GetGlobal()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetGlobal (JSVM_Env env, JSVM_Value * result )
```

**Description**

The global object is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| result | Represents a JavaScript global object.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetInstanceData()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetInstanceData (JSVM_Env env, void ** data )
```

**Description**

Retrieves data associated with the currently running JSVM environment through OH_JSVM_SetInstanceData(). If no associated data is set, the function is called successfully and data is set to NULL.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| data | Data items previously associated with the currently running JSVM environment by calling OH_JSVM_SetInstanceData().| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetLastErrorInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetLastErrorInfo (JSVM_Env env, const JSVM_ExtendedErrorInfo ** result )
```

**Description**

Retrieves the JSVM_ExtendedErrorInfo structure that contains information about the last error that occurred. The content of JSVM_ExtendedErrorInfo returned is valid only before the JSVM-API function is called for the same env. This includes calls to OH_JSVM_IsExceptionPending, so you may often need to copy information for later use. The pointer returned in error_message points to a statically defined string, so if you copy it from the error_message field (which will be overwritten) before calling another JSVM-API function, you can safely use the pointer.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| result | JSVM_ExtendedErrorInfo structure that contains more information about the error.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetNamedProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetNamedProperty (JSVM_Env env, JSVM_Value object, const char * utf8name, JSVM_Value * result )
```

**Description**

This method is equivalent to invoking OH_JSVM_GetProperty. The string transferred through utf8Name is used to create JSVM_Value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object from which the attribute is retrieved.| 
| utf8Name | Name of the attribute to be obtained.| 
| result | Value of the attribute.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_GetNewTarget()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetNewTarget (JSVM_Env env, JSVM_CallbackInfo cbinfo, JSVM_Value * result )
```

**Description**

Returns the new target called by the constructor function. If the current callback is not a constructor function call, the result is NULL.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| cbinfo | Callback information transferred to the callback function.| 
| result | Construct the new target called by the function.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetNull()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetNull (JSVM_Env env, JSVM_Value * result )
```

**Description**

The null object is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| result | Represents a JavaScript null object.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetProperty (JSVM_Env env, JSVM_Value object, JSVM_Value key, JSVM_Value * result )
```

**Description**

Obtains the attributes of the request from the input object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object from which the attribute is retrieved.| 
| key | The name of the attribute to retrieve.| 
| result | Value of the attribute.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_GetPropertyNames()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetPropertyNames (JSVM_Env env, JSVM_Value object, JSVM_Value * result )
```

**Description**

Returns the name of the enumerable property of an object as an array of characters. The attributes of the object whose key is a symbol are not included.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object whose attributes are to be retrieved.| 
| result | Represents an array of JavaScript values that represent the attribute names of the object. You can use OH_JSVM_GetArrayLength and OH_JSVM_GetElement to iterate over the result.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetPrototype()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetPrototype (JSVM_Env env, JSVM_Value object, JSVM_Value * result )
```

**Description**

Returns the prototype of an object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | JavaScript object whose prototype is to be returned. This returns the equal value of Object.getPrototypeOf (different from the prototype property of the function).| 
| result | Represents the prototype of a given object.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetReferenceValue()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetReferenceValue (JSVM_Env env, JSVM_Ref ref, JSVM_Value * result )
```

**Description**

If still valid, this JSVM-API returns JSVM_Value, representing the JavaScript value associated with JSVM_Ref. Otherwise, the result will be NULL.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| ref | JSVM_Ref of the corresponding value is requested.| 
| result | JSVM_Value referenced by JSVM_Ref.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetTypedarrayInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetTypedarrayInfo (JSVM_Env env, JSVM_Value typedarray, JSVM_TypedarrayType * type, size_t * length, void ** data, JSVM_Value * arraybuffer, size_t * byteOffset )
```

**Description**

Returns various properties of a typed array. If this attribute is not required, any output parameter can be NULL.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| typedarray | Indicates the TypedArray whose attributes are to be queried.| 
| type | Scalar data type of an element in TypedArray.| 
| length | Number of elements in TypedArray.| 
| data | The data buffer at the bottom layer of TypedArray is adjusted by the byte_offset value so that it points to the first element in TypedArray. If the length of the array is 0, this may be NULL or any other pointer value.| 
| arraybuffer | ArrayBuffer located under TypedArray.| 
| byteOffset | Byte offset in the underlying native array where the first element of the array is located. The value of the data parameter has been adjusted. Therefore, data points to the first element in the array. Therefore, the first byte of the native array will be located at data - byte_offset.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_INVALID_ARG may be returned.


### OH_JSVM_GetUndefined()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetUndefined (JSVM_Env env, JSVM_Value * result )
```

**Description**

The Undefined object is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Indicates the JavaScript undefined value.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetValueBigintInt64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBigintInt64 (JSVM_Env env, JSVM_Value value, int64_t * result, bool * lossless )
```

**Description**

Returns values such as the C int64_t base type of a given JavaScript BigInt. If necessary, it truncates the value and sets lossless to false.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Represents JavaScript BigInt.| 
| result | value such as the C int64_t base type of the given JavaScript BigInt.| 
| lossless | Indicates whether the BigInt value has been losslessly converted.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the input value is not BigInt, JSVM_BIGINT_EXPECTED is returned.


### OH_JSVM_GetValueBigintUint64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBigintUint64 (JSVM_Env env, JSVM_Value value, uint64_t * result, bool * lossless )
```

**Description**

Returns values such as the C uint64_t base type of a given JavaScript BigInt. If necessary, it truncates the value and sets lossless to false.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Represents JavaScript BigInt.| 
| result | Value such as the C uint64_t base type of the given JavaScript BigInt.| 
| lossless | Indicates whether the BigInt value has been losslessly converted.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the input value is not BigInt, JSVM_BIGINT_EXPECTED is returned.


### OH_JSVM_GetValueBigintWords()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBigintWords (JSVM_Env env, JSVM_Value value, int * signBit, size_t * wordCount, uint64_t * words )
```

**Description**

Converts a single BigInt value to a sign bit, a 64-bit little-endian array, and the number of elements in the array. Both signBit and words can be set to NULL. In this case, only wordCount is obtained.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Represents JavaScript BigInt.| 
| signBit | Indicates whether the JavaScript BigInt is a positive or negative integer.| 
| wordCount | The value must be initialized to the length of the words array. When returned, it is set to the actual number of words required to store this BigInt.| 
| words | Pointer to the pre-allocated 64-bit word array.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_BIGINT_EXPECTED may be returned.


### OH_JSVM_GetValueBool()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueBool (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Returns values such as the C Boolean base type of a given JavaScript Boolean.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Represents JavaScript Boolean.| 
| result | Value such as the C Boolean base type of a given JavaScript Boolean.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If a non-Boolean JSVM_Value is transferred, JSVM_BOOLEAN_EXPECTED is returned.


### OH_JSVM_GetValueDouble()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueDouble (JSVM_Env env, JSVM_Value value, double * result )
```

**Description**

Returns values such as the C double-precision base type of a given JavaScript number.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Indicates the JavaScript number.| 
| result | Value such as the C double-precision base type of a given JavaScript number.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If a non-numeric JSVM_Value is transferred, JSVM_NUMBER_EXPECTED is returned.


### OH_JSVM_GetValueExternal()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueExternal (JSVM_Env env, JSVM_Value value, void ** result )
```

**Description**

Retrieves the external data pointer previously passed to OH_JSVM_CreateExternal().

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Represents a JavaScript external value.| 
| result | Pointer to the data encapsulated by the JavaScript external value.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If a non-external JSVM_Value is transferred, JSVM_INVALID_ARG is returned.


### OH_JSVM_GetValueInt32()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueInt32 (JSVM_Env env, JSVM_Value value, int32_t * result )
```

**Description**

Returns values such as the C int32 base type of a given JavaScript number.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Indicates the JavaScript number.| 
| result | Value such as the C int32 base type of a given JavaScript number.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If a non-numeric JSVM_Value is transferred, JSVM_NUMBER_EXPECTED is returned.


### OH_JSVM_GetValueInt64()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueInt64 (JSVM_Env env, JSVM_Value value, int64_t * result )
```

**Description**

Returns values such as the C int64 base type of a given JavaScript number.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Indicates the JavaScript number.| 
| result | Value such as the C int64 base type of a given JavaScript number.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If a non-numeric JSVM_Value is transferred, JSVM_NUMBER_EXPECTED is returned.


### OH_JSVM_GetValueStringLatin1()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueStringLatin1 (JSVM_Env env, JSVM_Value value, char * buf, size_t bufsize, size_t * result )
```

**Description**

Returns the ISO-8859-1 encoded string corresponding to the input value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Indicates the JavaScript number.| 
| buf | Writes to the buffer of the ISO-8859-1 encoded string. If NULL is passed, the length of the string (in bytes, excluding the null terminator) is returned in the result.| 
| bufsize | Size of the destination buffer. When the size is insufficient, the returned string is truncated and ends with null.| 
| result | Number of bytes copied to the buffer, excluding null terminators.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If a non-string JSVM_Value is transferred, JSVM_STRING_EXPECTED is returned.


### OH_JSVM_GetValueStringUtf16()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueStringUtf16 (JSVM_Env env, JSVM_Value value, char16_t * buf, size_t bufsize, size_t * result )
```

**Description**

Queries the UTF16-encoded string based on the input value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Indicates a JavaScript string.| 
| buf | Buffer to which UTF16-LE encoded strings are written. If NULL is passed, the 2-byte code unit length of the string is returned, excluding the null terminator.| 
| bufsize | Size of the destination buffer. When this value is insufficient, the returned string is truncated and terminated with null.| 
| result | Number of 2-byte code units copied to the buffer, excluding null terminators.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If a non-string JSVM_Value is transferred, JSVM_STRING_EXPECTED is returned.


### OH_JSVM_GetValueStringUtf8()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueStringUtf8 (JSVM_Env env, JSVM_Value value, char * buf, size_t bufsize, size_t * result )
```

**Description**

Returns a UTF8 encoded string corresponding to the input value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Indicates a JavaScript string.| 
| buf | Writes a UTF8-encoded string to the buffer of the. If NULL is passed in, the string length in bytes is returned in the result, excluding the null terminator.| 
| bufsize | Size of the destination buffer. When this value is insufficient, the returned string is truncated and terminated with null.| 
| result | Number of bytes copied to the buffer, excluding the null terminator.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If a non-string JSVM_Value is transferred, JSVM_STRING_EXPECTED is returned.


### OH_JSVM_GetValueUint32()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetValueUint32 (JSVM_Env env, JSVM_Value value, uint32_t * result )
```

**Description**

Returns values such as the C uint_32 base type of a given JavaScript number.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Indicates the JavaScript number.| 
| result | Equivalents the given JSVM_Value to the C base type of uint32_t.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If a non-numeric JSVM_Value is transferred, JSVM_NUMBER_EXPECTED is returned.


### OH_JSVM_GetVersion()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetVersion (JSVM_Env env, uint32_t * result )
```

**Description**

Returns the highest JSVM-API version supported by the JSVM runtime. JSVM-API will be added in the future to support more functions. The purpose of introducing this API is as follows: In the JSVM version that supports a certain function, new functions can be used. In the JSVM version that does not support a certain function, callback behavior can be provided.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| result | Latest version of JSVM-API supported.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_GetVMInfo()

```
JSVM_EXTERN JSVM_Status OH_JSVM_GetVMInfo (JSVM_VMInfo * result)
```

**Description**

The VM information is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| result | VM information.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_HasElement()

```
JSVM_EXTERN JSVM_Status OH_JSVM_HasElement (JSVM_Env env, JSVM_Value object, uint32_t index, bool * result )
```

**Description**

This JSVM-API returns true if the passed Object has an element at the specified index.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object to be queried.| 
| index | Index position of the element to be determined.| 
| result | Indicates whether an attribute exists on an object.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_HasNamedProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_HasNamedProperty (JSVM_Env env, JSVM_Value object, const char * utf8name, bool * result )
```

**Description**

This method is equivalent to calling OH_JSVM_HasProperty with JSVM_Value created from the string passed as utf8Name.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object to be queried.| 
| utf8Name | Name of the attribute to be checked.| 
| result | Indicates whether an attribute exists on an object.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_HasOwnProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_HasOwnProperty (JSVM_Env env, JSVM_Value object, JSVM_Value key, bool * result )
```

**Description**

Check whether the input object has its own named attribute. The key must be a string or symbol. Otherwise, an error is thrown. The JSVM-API does not perform any conversion between data types.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object to be queried.| 
| key | Name of the self-owned attribute to be checked.| 
| result | Indicates whether an object has its own attribute.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_NAME_EXPECTED or JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_HasProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_HasProperty (JSVM_Env env, JSVM_Value object, JSVM_Value key, bool * result )
```

**Description**

Checks if the passed Object has the property with the specified name.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object to be queried.| 
| key | The name of the attribute whose existence is to be checked.| 
| result | Indicates whether an attribute exists on an object.| 

**Returns**

If the operation is successful, JSVM_OK is returned. JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_Init()

```
EXTERN_C_START JSVM_EXTERN JSVM_Status OH_JSVM_Init (const JSVM_InitOptions * options)
```

**Description**

Initialize a JavaScript virtual machine.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Options for initializing the JavaScript virtual machine.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


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
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value to be checked.| 
| constructor | JavaScript function object of the constructor to be checked| 
| result | If object instanceof constructor is true, set this parameter to a Boolean value of true.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_FUNCTION_EXPECTED or JSVM_GENERIC_FAILURE may be returned.


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
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value to be checked.| 
| result | Indicates whether the given object is an array.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_IsArraybuffer()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsArraybuffer (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Check whether the input object is ArrayBuffer.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value to be checked.| 
| result | Indicates whether the specified object is an ArrayBuffer.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_IsDataview()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsDataview (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Ensure that the input object is a DataView.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value to be checked.| 
| result | Indicates whether the given JSVM_Value represents a DataView.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_IsDate()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsDate (JSVM_Env env, JSVM_Value value, bool * isDate )
```

**Description**

Check whether the transferred object is a date.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value to be checked.| 
| isDate | Indicates whether the given JSVM_Value represents a JavaScript Date object.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_IsDetachedArraybuffer()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsDetachedArraybuffer (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Provides behavior similar to calling ArrayBuffer IsDetachedBuffer.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript ArrayBuffer to be checked.| 
| result | Indicates whether the ArrayBuffer is detached.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_IsError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsError (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Query JSVM_Value to check if it represents an error object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JSVM_Value to be checked.| 
| result | If JSVM_Value indicates an error, set this parameter to a Boolean value of true. Otherwise, set this parameter to false.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_IsExceptionPending()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsExceptionPending (JSVM_Env env, bool * result )
```

**Description**

Check whether the last exception is caused by suspension. If the error is caused by an exception, true is returned. Otherwise, false is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| result | If an exception is suspended, set this parameter to a Boolean value of true.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_IsPromise()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsPromise (JSVM_Env env, JSVM_Value value, bool * isPromise )
```

**Description**

Queries whether the Promise object is a native Promise object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | Value to be checked.| 
| isPromise | Indicates whether the object is a native Promise object (promise object created by the underlying engine).| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_IsTypedarray()

```
JSVM_EXTERN JSVM_Status OH_JSVM_IsTypedarray (JSVM_Env env, JSVM_Value value, bool * result )
```

**Description**

Ensure that the input object is a typed array.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value to be checked.| 
| result | Indicates whether the given JSVM_Value represents a TypedArray.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_JsonParse()

```
JSVM_EXTERN JSVM_Status OH_JSVM_JsonParse (JSVM_Env env, JSVM_Value jsonString, JSVM_Value * result )
```

**Description**

Parses the JSON string and returns the successfully parsed value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| jsonString | Character string to be parsed.| 
| result | Indicates the value that is successfully parsed.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_STRING_EXPECTED or JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_JsonStringify()

```
JSVM_EXTERN JSVM_Status OH_JSVM_JsonStringify (JSVM_Env env, JSVM_Value jsonObject, JSVM_Value * result )
```

**Description**

Converts an object to a string and returns the string that is successfully converted.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| jsonObject | Object to be stringed.| 
| result | Character string returned after successful conversion.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_MemoryPressureNotification()

```
JSVM_EXTERN JSVM_Status OH_JSVM_MemoryPressureNotification (JSVM_Env env, JSVM_MemoryPressureLevel level )
```

**Description**

Notifies the VM that the system memory is insufficient and selectively triggers garbage collection.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| level | Specifies the memory pressure level to be set for the current VM.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_NewInstance()

```
JSVM_EXTERN JSVM_Status OH_JSVM_NewInstance (JSVM_Env env, JSVM_Value constructor, size_t argc, const JSVM_Value * argv, JSVM_Value * result )
```

**Description**

Instantiates a new JavaScript value using the constructor represented by the given JSVM_Value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| constructor | Represents the JavaScript function that will be called as a constructor function.| 
| argc | Number of elements in the argv array.| 
| argv | JavaScript value array. JSVM_Value indicates the parameter of the constructor. If argc is zero, this parameter can be ignored by passing NULL.| 
| result | Indicates the returned JavaScript object, which is the constructed object in this example.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_PENDING_EXCEPTION may be returned.


### OH_JSVM_ObjectFreeze()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ObjectFreeze (JSVM_Env env, JSVM_Value object )
```

**Description**

Freezes a specified object. This prevents adding new attributes to it, deleting existing attributes, changing the enumerability, configurability, or writeability of existing attributes, or changing the value of an existing attribute. It also prevents changing the prototype of an object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object to be frozen.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_ObjectSeal()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ObjectSeal (JSVM_Env env, JSVM_Value object )
```

**Description**

Encapsulates a specified object. This prevents new attributes from being added to it and marks all existing attributes as unconfigurable.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object to be encapsulated.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


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
| env | target environment where the JSVM-API interface will be called.| 
| result | New environment scope.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_OpenEscapableHandleScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_OpenEscapableHandleScope (JSVM_Env env, JSVM_EscapableHandleScope * result )
```

**Description**

A new scope is opened from which an object can be promoted to an external scope.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| result | Indicates the new scope.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_OpenHandleScope()

```
JSVM_EXTERN JSVM_Status OH_JSVM_OpenHandleScope (JSVM_Env env, JSVM_HandleScope * result )
```

**Description**

A new scope has been opened up.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| result | Indicates the new scope.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


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
| result | Specifies the new VM scope.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_ReferenceRef()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ReferenceRef (JSVM_Env env, JSVM_Ref ref, uint32_t * result )
```

**Description**

Increases the reference count of the incoming reference and returns the generated reference count.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| ref | The reference count of an incoming reference increases.| 
| result | New reference count.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_ReferenceUnref()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ReferenceUnref (JSVM_Env env, JSVM_Ref ref, uint32_t * result )
```

**Description**

Decrements the reference count of the incoming reference and returns the generated reference count.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| ref | JSVM_Ref whose reference count will be reduced.| 
| result | New reference count.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_RejectDeferred()

```
JSVM_EXTERN JSVM_Status OH_JSVM_RejectDeferred (JSVM_Env env, JSVM_Deferred deferred, JSVM_Value rejection )
```

**Description**

Rejects JavaScript Promise through the delayed object associated with it. It can only be used to reject JavaScript Promise of the corresponding available delay object. This means that Promise must be created using OH_JSVM_CreatePromise(), and the object returned from the call must be retained before it can be passed to this API.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| deferred | Delay object whose associated promise is to be parsed.| 
| rejection | Value used to reject Promise.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_RemoveWrap()

```
JSVM_EXTERN JSVM_Status OH_JSVM_RemoveWrap (JSVM_Env env, JSVM_Value jsObject, void ** result )
```

**Description**

Use OH_JSVM_Wrap() to retrieve the native instance previously encapsulated in the JavaScript object js_object and remove the encapsulation. If the finalize callback is associated with encapsulation, it is no longer called when the JavaScript object is garbage collected.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| jsObject | Object associated with the native instance.| 
| result | Pointer to the encapsulated native instance.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_ResolveDeferred()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ResolveDeferred (JSVM_Env env, JSVM_Deferred deferred, JSVM_Value resolution )
```

**Description**

Parses the JavaScript promise through the delay object associated with it. It can only be used to parse the JavaScript Promise of the corresponding available delay object. This means that Promise must be created using OH_JSVM_CreatePromise(), and the object returned from the call must be retained before it can be passed to this API.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| deferred | Delay object whose associated promise is to be parsed.| 
| resolution | It is used to solve the value of Promise.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_RunScript()

```
JSVM_EXTERN JSVM_Status OH_JSVM_RunScript (JSVM_Env env, JSVM_Script script, JSVM_Value * result )
```

**Description**

Executes a string of JavaScript code and returns its result, including the following precautions: Unlike eval, this function does not allow the script to access the current lexical scope, and therefore does not allow the script to access the module scope. This means that pseudo-global variables such as require will be unavailable. The script can access the global scope. The functions and var declarations in the script will be added to the global object. Variable declarations using let and const are globally visible, but are not added to global objects. The value of this is global in the script.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| script | JavaScript string that contains the script to be executed.| 
| result | Value generated after the script is executed.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_SetElement()

```
JSVM_EXTERN JSVM_Status OH_JSVM_SetElement (JSVM_Env env, JSVM_Value object, uint32_t index, JSVM_Value value )
```

**Description**

Sets an element on the passed Object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object whose attributes are to be set.| 
| index | Index of the attribute to be set.| 
| value | Value of the attribute.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_SetInstanceData()

```
JSVM_EXTERN JSVM_Status OH_JSVM_SetInstanceData (JSVM_Env env, void * data, JSVM_Finalize finalizeCb, void * finalizeHint )
```

**Description**

Associates data with the currently running JSVM environment. You can use OH_JSVM_GetInstanceData() to retrieve data later. Any existing data associated with the currently running JSVM environment set by a previous call to OH_JSVM_SetInstanceData() will be overwritten. If finalizeCb was previously provided, it will not be called.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| data | Data items that can be used for the binding of this instance.| 
| finalizeCb | Function called when the environment is destroyed. This function receives data to release it.| 
| finalizeHint | Optional hints passed to the final callback during collection.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_SetNamedProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_SetNamedProperty (JSVM_Env env, JSVM_Value object, const char * utf8name, JSVM_Value value )
```

**Description**

This method is equivalent to invoking OH_JSVM_SetProperty. The string transferred through utf8Name is used to create JSVM_Value.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object whose properties are to be set.| 
| utf8Name | Name of the attribute to be set.| 
| value | Value of the attribute.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_SetProperty()

```
JSVM_EXTERN JSVM_Status OH_JSVM_SetProperty (JSVM_Env env, JSVM_Value object, JSVM_Value key, JSVM_Value value )
```

**Description**

Sets an attribute for the input object.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| object | Object whose attributes are to be set.| 
| key | Name of the attribute to be set.| 
| value | Value of the attribute.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE may be returned.


### OH_JSVM_StrictEquals()

```
JSVM_EXTERN JSVM_Status OH_JSVM_StrictEquals (JSVM_Env env, JSVM_Value lhs, JSVM_Value rhs, bool * result )
```

**Description**

Provides behavior similar to invoking a strict equality algorithm.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| lhs | JavaScript value to be checked.| 
| rhs | JavaScript value to be checked.| 
| result | Indicates whether two JSVM_Value objects are equal.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_SymbolFor()

```
JSVM_EXTERN JSVM_Status OH_JSVM_SymbolFor (JSVM_Env env, const char * utf8description, size_t length, JSVM_Value * result )
```

**Description**

Searches the global registry for an existing symbol with a given description. If the symbol already exists, it is returned. Otherwise, a new symbol is created in the registry.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| utf8description | A UTF-8 C string representing the text used as a symbol description.| 
| length | Length of a string, in bytes. If the string ends with null, the value is JSVM_AUTO_LENGTH.| 
| result | JSVM_Value representing a JavaScript symbol.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


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
| env | Environment for invoking the JSVM-API.| 
| error | JavaScript value to throw.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_ThrowError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowError (JSVM_Env env, const char * code, const char * msg )
```

**Description**

A JavaScript Error with the provided text is thrown.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| code | The optional error code to set on the error.| 
| msg | A C string representing the text associated with the error.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_ThrowRangeError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowRangeError (JSVM_Env env, const char * code, const char * msg )
```

**Description**

A JavaScript RangeError with the provided text is thrown.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| code | The optional error code to set on the error.| 
| msg | A C string representing the text associated with the error.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_ThrowSyntaxError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowSyntaxError (JSVM_Env env, const char * code, const char * msg )
```

**Description**

A JavaScript SyntaxError with the provided text is thrown.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| code | The optional error code to set on the error.| 
| msg | A C string representing the text associated with the error.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


### OH_JSVM_ThrowTypeError()

```
JSVM_EXTERN JSVM_Status OH_JSVM_ThrowTypeError (JSVM_Env env, const char * code, const char * msg )
```

**Description**

A JavaScript TypeError with the provided text is thrown.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| code | The optional error code to set on the error.| 
| msg | A C string representing the text associated with the error.| 

**Returns**

If the operation is successful, JSVM_OK is returned.


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
| env | Environment for invoking the JSVM-API.| 
| value | JavaScript value whose type is to be queried.| 
| result | Type of a JavaScript value.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_INVALID_ARG may be returned.


### OH_JSVM_TypeTagObject()

```
JSVM_EXTERN JSVM_Status OH_JSVM_TypeTagObject (JSVM_Env env, JSVM_Value value, const JSVM_TypeTag * typeTag )
```

**Description**

Associates the value of the typeTag pointer with a JavaScript object or an external value. You can call OH_JSVM_CheckObjectTypeTag() to determine the type of the tag attached to the object to ensure that the object type is correct. If the object already has an associated type tag, JSVM_INVALID_ARG is returned.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| value | The JavaScript object or external value to mark.| 
| typeTag | Label of the object to be marked.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the operation fails, JSVM_GENERIC_FAILURE or JSVM_INVALID_ARG may be returned.


### OH_JSVM_Unwrap()

```
JSVM_EXTERN JSVM_Status OH_JSVM_Unwrap (JSVM_Env env, JSVM_Value jsObject, void ** result )
```

**Description**

When JavaScript code calls a method or property accessor of a class, the corresponding JSVM_Callback is called. If the callback is for an instance method or accessor, the **this** parameter of the callback is the wrapper object. Then, you can call OH_JSVM_Unwrap() of the wrapper object to obtain the C++ instance as the invoking target.

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| jsObject | Object associated with the native instance.| 
| result | Pointer to the encapsulated native instance.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the input value of jsObject is not an object, JSVM_INVALID_ARG is returned.


### OH_JSVM_Wrap()

```
JSVM_EXTERN JSVM_Status OH_JSVM_Wrap (JSVM_Env env, JSVM_Value jsObject, void * nativeObject, JSVM_Finalize finalizeCb, void * finalizeHint, JSVM_Ref * result )
```

**Description**

Encapsulate the native instance in the JavaScript object. The native instance can be retrieved using OH_JSVM_Unwrap().

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Environment for invoking the JSVM-API.| 
| jsObject | JavaScript object that will become the native object wrapper.| 
| nativeObject | Native instance encapsulated in the JavaScript object.| 
| finalizeCb | Optional native callback, which can be used to release native instances when JavaScript objects are garbage collected.| 
| finalizeHint | Optional context hint passed to the completion callback.| 
| result | An optional reference to an encapsulated object.| 

**Returns**

If the operation is successful, JSVM_OK is returned. If the input value of jsObject is not an object, JSVM_INVALID_ARG is returned.
