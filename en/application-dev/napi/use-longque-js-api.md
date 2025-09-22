# Longque-JS-API Usage Guide
Longque JS APIs are provided by Longque JS Engine and can be used to build stable and high-performance applications on the OpenHarmony platform. All APIs are under the `__Longque__` object. You can use **__Longque__.version** to obtain the API version for determining features.

**Note: The Longque JS API is in the experiment phase. Before using it, read this document to evaluate its stability and compatibility.**

## Available APIs
| Interface                      | Description                           |
|----------------------------|-------------------------------------|
|createDelegate         | Create an agency.|

## Attributes
| Name                      | Description                           |
|----------------------------|-------------------------------------|
|version         | Version of the Longque JS API.|
|SKIP_PROTOTYPE_CHAIN |Attribute filter of createDelegate, which indicates that only its own attributes are entrusted and the prototype chain is not considered.|
|SKIP_PREFIX_UNDERSCORE |Attribute filter of createDelegate, which filters out attributes whose names start with an underscore (_).|
|SKIP_PREFIX_DOLLAR |Attribute filter of createDelegate, which filters out the attributes whose names start with $.|
|SKIP_CONSTRUCTOR |Attribute filter of createDelegate, indicating that the'constructor' attribute is filtered out.|

## createDelegate interface
> Version in which the interface is introduced: 1

### Interface Description
| Interface | Name | Description|
| -- | -- | -- |
| createDelegate | Creating an agency| Creates an agency object for `underlyingObject`. The read and write operations on the attributes of the agency object are mapped to `underlyingObject`. Use `initObject` to specify the initial delegate object and use `propertyFilterFlags` to specify the attribute filter. By default, all enumerable string key properties in the `underlyingObject` and its prototype chain are mapped.

### Name
(1) `underlyingObject`: This parameter is mandatory. Underlying object to delegate. Parameter requirements:
- `underlyingObject` must be an object. Otherwise, the `TypeError` exception is thrown.
- If `underlyingObject` is a proxy object, the `TypeError` exception is thrown.
- If the `SKIP_PROTOTYPE_CHAIN` filter is not specified and a proxy object exists in the `underlyingObject` prototype chain, a `TypeError` exception is thrown.

(2) `initObject`: This parameter is optional. Initial delegate object. If undefined is passed, the initial object is not specified and is automatically created by the interface. Parameter requirements:
- `initObject` must be an object. Otherwise, the `TypeError` exception is thrown.
- If `initObject` is a proxy object, the `TypeError` exception is thrown.
- The agency object cannot be used as `initObject`. Otherwise, the `TypeError` exception is thrown.
- If the `initObject` is not extensible, a `TypeError` exception is thrown.
- If some attributes in `initObject` cannot be defined, the `TypeError` exception is thrown. In this case, only some attributes in `initObject` are defined successfully.

(3) `propertyFilterFlags`: This parameter is optional. Property filter. If undefined is passed, no filter is specified. Parameter requirements:
- The following lists the currently supported attribute filters (which may be extended in the future).
```sh
The __Longque__.SKIP_PROTOTYPE_CHAIN: delegates only the attributes of the underlyingObject and does not consider the prototype chain.
Filter out attributes whose names start with an underscore (_) in __Longque__.SKIP_PREFIX_UNDERSCORE:.
Filter out attributes whose names start with '$' in __Longque__.SKIP_PREFIX_DOLLAR:.
The **constructor** attribute is filtered out from ** __Longque__.SKIP_CONSTRUCTOR:**.
```
- The listed filters must be used. Otherwise, the API behavior is not defined, which may cause code compatibility issues.
- All filters are of the `number` type. You can use the | operator to specify multiple filters.
- If `propertyFilterFlags` is not of the `number` type, a `TypeError` exception is thrown.

### Return Value
The following information is returned only when the interface does not throw an exception:
- If no initial agency object is specified, the newly created agency object is returned.
- If an initial delegate object has been specified, the initial delegate object is returned.

### Important Notes
(1) The attribute sequence of the delegate object may be different from that of the for-in and Object.keys methods. Do not depend on the attribute sequence.

(2) The implementation of the delegate object is an internal mechanism of the engine. Do not rely on the returned results of calling APIs such as `Object.getOwnPropertyDescriptor`, `getOwnPropertyDescriptors`, and `Reflect.getOwnPropertyDescriptor` on the agency object.

### Sample Code

This example shows how to use the Longque JS API in the JSVM. For details about the JSVM-API development process, see [Using JSVM-API to Implement Interactive Development Between JS and C/C++](use-jsvm-process.md). This document describes only the C++ code corresponding to the interface.

CPP code:
``` cpp
// JS code to be executed.
static const char *STR_TASK = R"JS(
  function createDelegateTest() {
    var myobj = {
      42: 0,
      x: 1,
      _y: 2,
      $z:3
    };

    var proto = {
      foo: 'foo'
    };
    Object.setPrototypeOf(myobj, proto);

    var d1 = __Longque__.createDelegate(myobj, undefined);
    consoleinfo(JSON.stringify(d1)); // {"42":0,"x":1,"_y":2,"$z":3,"foo":"foo"}

    const propertyFilterFlags = __Longque__.SKIP_PREFIX_UNDERSCORE | __Longque__.SKIP_PREFIX_DOLLAR;
    var d2 = __Longque__.createDelegate(myobj, undefined, propertyFilterFlags);
    consoleinfo(JSON.stringify(d2)); // {"42":0,"x":1,"foo":"foo"}

    d2[42] = 100;

    const newFilter = propertyFilterFlags | __Longque__.SKIP_PROTOTYPE_CHAIN;
    var d3 = __Longque__.createDelegate(myobj, undefined, newFilter);
    consoleinfo(JSON.stringify(d3)); // {"42":100,"x":1}
  }
  createDelegateTest();
)JS";

// Ensure normal printing of the JS code information.
static JSVM_Value ConsoleInfo(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1];
    char log[256] = "";
    size_t logLength = 0;
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

    OH_JSVM_GetValueStringUtf8(env, args[0], log, 255, &logLength);
    log[255] = 0;
    OH_LOG_INFO(LOG_APP, "JSVM API TEST: %{public}s", log);
    return nullptr;
}

// Register the consoleinfo callback.
JSVM_CallbackStruct param[] = {
    {.data = nullptr, .callback = ConsoleInfo},
};
JSVM_PropertyDescriptor descriptor[] = {
    {"consoleinfo", NULL, &param[0], NULL, NULL, NULL, JSVM_DEFAULT},
};

static int32_t TestJSVM() {
    JSVM_InitOptions init_options;
    memset(&init_options, 0, sizeof(init_options));
    if (g_aa == 0) {
        OH_JSVM_Init(&init_options);
        g_aa++;
    }
    // Create a JSVM instance and open the VM scope.
    JSVM_VM vm;
    JSVM_CreateVMOptions options;
    memset(&options, 0, sizeof(options));
    CHECK(OH_JSVM_CreateVM(&options, &vm));
    JSVM_VMScope vm_scope;
    CHECK(OH_JSVM_OpenVMScope(vm, &vm_scope));

    JSVM_Env env;
    CHECK(OH_JSVM_CreateEnv(vm, sizeof(descriptor) / sizeof(descriptor[0]), descriptor, &env));
    JSVM_EnvScope envScope;
    CHECK_RET(OH_JSVM_OpenEnvScope(env, &envScope));
    JSVM_HandleScope handlescope;
    CHECK_RET(OH_JSVM_OpenHandleScope(env, &handlescope));
    JSVM_Value sourcecodevalue;
    CHECK_RET(OH_JSVM_CreateStringUtf8(env, STR_TASK, strlen(STR_TASK), &sourcecodevalue));
    JSVM_Script script;
    CHECK_RET(OH_JSVM_CompileScript(env, sourcecodevalue, nullptr, 0, true, nullptr, &script));
    JSVM_Value result;
    CHECK_RET(OH_JSVM_RunScript(env, script, &result));

    // Close and destroy the environment and the VM.
    CHECK_RET(OH_JSVM_CloseHandleScope(env, handlescope));
    CHECK_RET(OH_JSVM_CloseEnvScope(env, envScope));
    CHECK(OH_JSVM_DestroyEnv(env));
    CHECK(OH_JSVM_CloseVMScope(vm, vm_scope));
    CHECK(OH_JSVM_DestroyVM(vm));
    return 0;
}
```

Expected output:
```
JSVM API TEST: {"42":0,"x":1,"_y":2,"$z":3,"foo":"foo"}
JSVM API TEST: {"42":0,"x":1,"foo":"foo"}
JSVM API TEST: {"42":100,"x":1}
```
