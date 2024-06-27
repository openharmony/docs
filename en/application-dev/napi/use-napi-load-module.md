# Loading a Module in the Main Thread Using Node-API

## **Scenario**

You can use **napi_load_module** to load a module in the main thread. After the module is loaded, you can use **napi_get_property** to obtain the variables exported by the module or use **napi_get_named_property** to obtain the functions exported by the module. Currently, you can use **napi_load_module** to load the following modules:

- System modules, for example, @ohos.hilog
- Modules defined in the files under the **ets** directory

## Function Description

```cpp
napi_status napi_load_module(napi_env env,
                             const char* path,
                             napi_value* result);
```

| Parameter           | Description         |
| :------------- | :----------------------------- |
| env            | Current VM environment.      |
| path          | Path of the file or name of the module to load.         |
| result         | Module loaded.         |

## Constraints

- Do not use this AP in non-main threads.
- Do not use this API in the **Init()** function.
- Do not load a file in the callback function of a thread-safe function.

You are advised to use [napi_load_module_with_info](use-napi-load-module-with-info.md) to load modules. This API supports more scenarios.

## Loading a System Module

Use **napi_load_module** to load the system module @ohos.hilog and call the **info** function.

```cpp
static napi_value loadModule(napi_env env, napi_callback_info info) {
    // 1. Call napi_load_module to load the @ohos.hilog module.
    napi_value result;
    napi_status status = napi_load_module(env, "@ohos.hilog", &result);
    
    // 2. Call napi_get_named_property to obtain the info function.
    napi_value infoFn;
    napi_get_named_property(env, result, "info", &infoFn);
    
    napi_value tag;
    std::string formatStr = "test";
    napi_create_string_utf8(env, formatStr.c_str(), formatStr.size(), &tag);
    
    napi_value outputString;
    std::string str = "Hello OpenHarmony";
    napi_create_string_utf8(env, str.c_str(), str.size(), &outputString);
    
    napi_value flag;
    napi_create_int32(env, 0, &flag);

    napi_value args[3] = {flag, tag, outputString};
    //3. Use napi_call_function to call the info function.
    napi_call_function(env, result, infoFn, 3, args, nullptr);
    return result;
}
```

## Loading a Module from an ArkTS File

Load a module from a file as shown in the following ArkTS code.

```javascript
//./src/main/ets/Test.ets
let value = 123;
function test() {
  console.log("Hello OpenHarmony");
}
export {value, test};
```

1. Add the following to the **build-profile.json5** file of the project.

```json
{
    "buildOption" : {
        "arkOptions" : {
            "runtimeOnly" : {
                "sources": [
                    "./src/main/ets/Test.ets"
                ]
            }
        }
    }
}
```

2. Use **napi_load_module** to load the **Test.ets** file, call the **test()** function, and obtain the variable values.

```cpp
static napi_value loadModule(napi_env env, napi_callback_info info) {
    napi_value result;
    // 1. Call napi_load_module to load the module from the Test.ets file.
    napi_status status = napi_load_module(env, "ets/Test", &result);

    napi_value testFn;
    // 2. Call napi_get_named_property to obtain the test function.
    napi_get_named_property(env, result, "test", &testFn);
    // 3. Call napi_call_function to call the test function.
    napi_call_function(env, result, testFn, 0, nullptr, nullptr);

    napi_value value;
    napi_value key;
    std::string keyStr = "value";
    napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
    // 4. Call napi_get_property to obtain a variable value.
    napi_get_property(env, result, key, &value);
    return result;
}
```
