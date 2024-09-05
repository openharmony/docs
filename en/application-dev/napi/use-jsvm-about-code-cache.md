# Accelerating Compilation Using a Code Cache

## Introduction to Code Cache

JSVM-API provides APIs for creating a code cache and using the code cache to store and manage compiled code to accelerate compilation. The process is as follows:

1. Use the **compile** APIs to obtain **JSVM_Script**.
2. Call **OH_JSVM_CreateCodeCache** with the passed-in **JSVM_Script** to create a code cache.
3. Save the created code cache. During the next compilation, pass the code cache as a parameter to the **compile** APIs.

The compilation using the code cache greatly reduces the compilation time because the serialized script in the code cache only needs to be deserialized, eliminating the need for parsing and compiling the code. In this way, the compilation process is simplified as a process for reading data.

## Example

The following pseudocode demonstrates a typical use case. During the second compilation, if the value of **cacheRejected** is not **true**, the code cache is successfully used and the compilation is greatly accelerated.

The following example provides only the APIs used in the process. For details about JSVM-API, see [JSVM](../reference/common/_j_s_v_m.md). 

```c++

JSVM_Env env;

...

using namespace std;
static string src = R"JS(
const concat = (...args) => args.reduce((a, b) => a + b);
throw new Error("exception triggered")
)JS";

// Set compilation parameters.
JSVM_Value jsSrc;
JSVM_Script script;
size_t length = 0;
const uint8_t* dataPtr = nullptr,
bool cacheRejected = false;

// Create a code cache.
{
	JSVM_HandleScope handleScope;
	OH_JSVM_OpenHandleScope(env, &handleScope);

	// Convert the source code string into a JS string.
	OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsSrc);

	// Compile the JS code.
	OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script);

	// Run the JS code.
	JSVM_Value result;
	OH_JSVM_RunScript(env, script, &result);

	if (dataPtr && lengthPtr && *dataPtr == nullptr) {
	    // Save the script compiled from the JS source code to the cache to prevent repeated compilation and improve performance.
	    OH_JSVM_CreateCodeCache(env, script, dataPtr, lengthPtr);
	}

	OH_JSVM_CloseHandleScope(env, handleScope);
}

// Use the code cache.
{
	JSVM_HandleScope handleScope;
	OH_JSVM_OpenHandleScope(env, &handleScope);

	// Convert the source code string into a JS string.
	OH_JSVM_CreateStringUtf8(env, src.c_str(), src.size(), &jsSrc);

	// Use the code cache to compile the JS code.
	OH_JSVM_CompileScript(env, jsSrc, dataPtr, length, true, &cacheRejected, &script);

	// Run the JS code.
	JSVM_Value result;
	OH_JSVM_RunScript(env, script, &result);

	OH_JSVM_CloseHandleScope(env, handleScope);
}
```

<!--no_check-->