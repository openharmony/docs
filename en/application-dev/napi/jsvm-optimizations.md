# JSVM Tuning Practices
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

## JSVM Call Invocation

The process of executing JavaScript (JS) code on a JavaScript virtual machine (JSVM) can be divided into the following layers:

- Native: logic layer for the application to run JS code. In this layer, the APIs provided by the JSVM are used to compile and run JS code and create a code cache.
- JSVM-API: intermediate layer between C/C++ and V8 JS engine. This layer ensures compatibility with JS engines of different versions and provides standardized practices of JS engines.
- JSVM: JS engine layer, in which JS code is compiled and executed.

When the JSVM is used, unnecessary overhead may be generated due to various reasons, which slows down the startup speed. You can analyze the problem from the following three aspects:

## Accelerating Startup

For the applications that use JSVM, optimization can be made in the cold startup and hot startup.
In the cold startup, generally, the initial startup, there is no profile or cache that can be used for optimization.
In the hot startup, the code cache can be used for optimization.

### Reducing Overheads of the JSVM Layer

The overhead of the engine layer is largely caused by compilation. By properly adjusting the input options when the JSVM-API is called, you can reduce the compilation overhead of the JS engine on the main thread.
In the following example, the **eagerCompile** parameter specifies the compilation behavior. You can enable this option in the startup scenarios to optimize the compilation effect.

```cpp
/**
 * ...
 * @param eagerCompile: Whether to compile the script eagerly.
 * ...
 */
JSVM_EXTERN JSVM_Status OH_JSVM_CompileScript(JSVM_Env env,
                                              JSVM_Value script,
                                              const uint8_t* cachedData,
                                              size_t cacheDataLength,
                                              bool eagerCompile, // Set it to true to enable full compilation.
                                              bool* cacheRejected,
                                              JSVM_Script* result);
```

Using a code cache also helps speed up compilation. For details, see [Accelerating Compilation Using a Code Cache](use-jsvm-about-code-cache.md).

Hot Startup: Creating a Code Cache with Adequate Code 

To speed up hot startup, create a code cache with adequate code to reduce the compilation overhead. The code coverage of the created code cache determines the optimization effect of the hot startup.

There is a simple policy to generate sufficient code cache: Enable the `eager compile` option in the compilation before the code cache is generated. In this way, V8 performs full compilation during compilation to ensure that the generated code cache is full.

This method increases the compilation time overhead and may affect the cold start time. The cold start optimization method of the native layer will be discussed in detail later.

Cold Startup: Disabling eagerCompile

Enabling **eagerCompile** increases the compilation time for cold startup. To reduce the compilation time, you can use V8 lazy compile, which delays the compilation of JS code until it is executed.

Therefore, during cold start, you can disable the `eager compile` option to avoid blocking the main thread and obtain sufficient cold start optimization effect.

### Reducing Time Overheads in the Native Layer
Reducing the Code Cache Impact in Cold Startup

It seems contradictory since you are advised to enable **eagerCompile** for higher hot startup performance and to disable **eagerCompile** for higher cold startup performance. To avoid the trade-off between cold startup and hot startup performance, let's focus on the code cache itself.

First, pre-compilation needs to be performed to generate the code cache. Second, generating the code cache itself also causes overheads.

At the native layer, to solve the conflict between cold start and code cache generation, you can start another thread to generate the code cache. In this way, the impact of code cache generation on cold start can be avoided.

There are two methods for reference. (The following pseudocode is used only to display the logic process and does not involve actual API invoking.)

- Start another thread to complete the code compilation and create a code cache. In this way, you can enable **eagerCompile** for code cache creation and disable it for cold startup. This approach decouples the code cache creation and the application running, and you do not need to consider the time when the code cache is created. However, the peak resource usage during the application running may increase. The pseudocode of the process is as follows:

```
async_create_code_cache() {
  compile_with_eager_compile();
  create_code_cache();
  save_code_cache();
}

...

if (has_code_cache) {
  evaluate_script_with_code_cache();
} else {
  start_thread(async_create_code_cache());
  evaluate_script_without_code_cache();
}
```


- After all the paths are executed in the startup, start a new thread to create a code cache. In this way, you can create a cache with sufficient code without enabling **eagerCompile** while maintaining the hot startup performance. This approach will not increase the peak resource usage or affect the I/O. However, the time for generating the code cache is restricted. The pseudo-code of this process is as follows:

```
async_create_code_cache() {
  compile_with_out_eager_compile();
  create_code_cache();
  save_code_cache();
}

...

if (has_code_cache) {
  evaluate_script_with_code_cache();
} else {
  evaluate_script_without_code_cache();
}

...

if (script_run_completed) {
  start_thread(async_create_code_cache());
}
```


### Using Performant JSVM-API 

When the same effect can be achieved, using a more efficient JSVM-API is an effective performance optimization method. The following are some specific practice examples.

Using IsXXX Instead of TypeOf

To determine the native type of an object, it is inefficient to

use **OH_JSVM_TypeOf** to obtain the object type and check whether the object type is the same as a specific type.

Instead, you can use the **Is**XXX APIs. For details about the JSVM-API used in the following example, see [JSVM-API Data Types and APIs](./jsvm-data-types-interfaces.md). The following example only demonstrates the calling procedure.

- Example (not recommended):


```cpp
bool Test::IsFunction(JSVM_Env env, JSVM_Value jsvmValue) const {
    // type judgment
    JSVM_ValueType valueType;
    OH_JSVM_TypeOf(*env, jsvmValue, &valueType);
    return valueType == JSVM_FUNCTION;
}
```

- Example (recommended):


```cpp
bool Test::IsFunction(JSVM_Env env, JSVM_Value jsvmValue) const {
    // type judgment
    bool result = false;
    OH_JSVM_IsFunction(*env, jsvmValue, &result); // Check whether the object type is function.
    return result;
}
```

The following optimization decreases the code execution time by 150 ms, accounting for about 5% of the performance benefits of an applet.

Using OH_JSVM_CreateReference to Avoid Creating Redundant Objects

Generally, the procedure for creating a reference to an object is as follows:

Create an object -> Set a value of the object -> Create the reference to the object

If a value already exists, directly create a reference to the value.

For details about the JSVM-API used in the following example, see [JSVM-API Data Types and APIs](./jsvm-data-types-interfaces.md). The following example only demonstrates the calling procedure.


- Example (not recommended):

```cpp
// (1) Open a handle scope.
JSVM_HandleScope scope;
OH_JSVM_OpenHandleScope(*env, &scope);
// (2) Obtain JSVM_Value.
JSVM_Value jsvmValue;
OH_JSVM_GetNull(*env, &jsvmValue);
// (3) Create a Reference for JSVM_Value and save it.
JSVM_Value wrappingObject;
OH_JSVM_CreateObject(*env, &wrappingObject);
OH_JSVM_SetElement(*env, wrappingObject, 1, jsvmValue);
OH_JSVM_CreateReference(*env, wrappingObject, 1, &result->p_member->jsvmRef);
// (4) Close the handle scope.
OH_JSVM_CloseHandleScope(*env, scope);
```

- Example (recommended):

```cpp
// (1) Open a handle scope.
JSVM_HandleScope scope;
OH_JSVM_OpenHandleScope(*env, &scope);
// (2) Obtain JSVM_Value.
JSVM_Value jsvmValue;
OH_JSVM_GetNull(*env, &jsvmValue);
// (3) Create a Reference for JSVM_Value and save it.
OH_JSVM_CreateReference(*env, jsvmValue, 1, &result->p_member->jsvmRef); // Create a reference to an object of any type, making your code simpler and more performant.
// (4) Close the handle scope.
OH_JSVM_CloseHandleScope(*env, scope);
```

This optimization also helps reduce the number of API calls for another applet and decreases the code execution time by 100+ ms, accounting for about 3% of the performance benefits.
