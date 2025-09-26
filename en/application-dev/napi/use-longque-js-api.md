# Using Longque JS APIs
Provided by Longque JS Engine, Longque JS APIs are used to build stable and high-performance applications on OpenHarmony. They are under the **__Longque__** object. You can use **__Longque__.version** to obtain the API version for determining features.

Note: Longque JS APIs are in the experimental phase. Before using the APIs, read this topic to evaluate their stability and compatibility.

## Available APIs
| Name                      | Description                           |
|----------------------------|-------------------------------------|
|createDelegate         | Creates a delegate.|

## Properties
| Name                      | Description                           |
|----------------------------|-------------------------------------|
|version         | Version of the Longque JS API.|
|SKIP_PROTOTYPE_CHAIN |Property filter of **createDelegate**, which skips the prototype chain.|
|SKIP_PREFIX_UNDERSCORE |Property filter of **createDelegate**, which skips properties starting with an underscore (_).|
|SKIP_PREFIX_DOLLAR |Property filter of **createDelegate**, which skips properties starting with a dollar sign ($).|
|SKIP_CONSTRUCTOR |Property filter of **createDelegate**, which skips the **constructor** property.|

## createDelegate
> API introduction version: 1

### Description
| API | Usage | Description|
| -- | -- | -- |
| createDelegate | Delegate creation.| Creates a delegate object for **underlyingObject**. The read and write operations on the delegate object are mapped to **underlyingObject**. You can specify the initial delegate object through **initObject** and the property filter through **propertyFilterFlags**. By default, all enumerable string key properties in **underlyingObject** and its prototype chain are mapped.

### Parameters
(1) **underlyingObject**: Underlying object to delegate. This parameter is mandatory. Parameter requirements:
- **underlyingObject** must be an object. Otherwise, the **TypeError** exception is thrown.
- If **underlyingObject** is a delegate object, a **TypeError** exception is thrown.
- If the **SKIP_PROTOTYPE_CHAIN** filter is not specified and a delegate object exists in the **underlyingObject** prototype chain, a **TypeError** exception is thrown.

(2) **initObject**: Initial delegate object. This parameter is optional. If **undefined** is passed, the initial object is not specified and is automatically created by the API. Parameter requirements:
- **initObject** must be an object. Otherwise, a **TypeError** exception is thrown.
- If **initObject** is a delegate object, a **TypeError** exception is thrown.
- The delegate object cannot be used as **initObject**. Otherwise, a **TypeError** exception is thrown.
- If **initObject** is not extensible, a **TypeError** exception is thrown.
- If some properties of **initObject** cannot be defined, a **TypeError** exception is thrown. In this case, only some properties of **initObject** are successfully defined.

(3) **propertyFilterFlags**: Property filter. This parameter is optional. If **undefined** is passed, no filter is specified. Parameter requirements:
- The following lists the supported property filters (which may be extended in the future).
```sh
__Longque__.SKIP_PROTOTYPE_CHAIN: Delegates only the underlyingObject properties and skips the prototype chain.
__Longque__.SKIP_PREFIX_UNDERSCORE: Skips properties whose names start with underscores (_).
__Longque__.SKIP_PREFIX_DOLLAR: Skips properties whose names start with dollar signs ($).
__Longque__.SKIP_CONSTRUCTOR: Skips the constructor property.
```
- You must use any of the listed filters. Otherwise, the API behavior is not defined, which may cause code compatibility issues.
- All filters are of the **number** type. You can use the | operator to specify multiple filters.
- If **propertyFilterFlags** is not of the **number** type, a **TypeError** exception is thrown.

### Return Value
The API returns results correctly only if no exception is thrown.
- If no initial delegate object is specified, the newly created delegate object is returned.
- If the initial delegate object is specified, it is returned.

### Precautions
(1) The property sequence of the delegate object may be different from the result of the **for-in** or **Object.keys** method. Do not depend on the property sequence.

(2) The implementation of the delegate object is an internal mechanism of the engine. Do not depend on the return result of calling **Object.getOwnPropertyDescriptor**, **getOwnPropertyDescriptors** or **Reflect.getOwnPropertyDescriptor** on the delegate object.

### Sample Code

The following example shows how to use the Longque JS API in JSVM. If you are just starting out with JSVM-API, see [JSVM-API Development Process](use-jsvm-process.md). The following demonstrates only the C++ code involved in using the Longque JS API.

C++ code:
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
