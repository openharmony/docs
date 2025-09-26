# Loading a Module Using Node-API
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

You can use **napi_load_module_with_info** to load a module. After the module is loaded, you can use **napi_get_property** to obtain the variables of the module or use **napi_get_named_property** to obtain the functions of the module. The **napi_load_module_with_info** API can be used in a [new ArkTS runtime environment](use-napi-ark-runtime.md) created by the **napi_create_ark_runtime** API.

## Function Description

```cpp
napi_status napi_load_module_with_info(napi_env env, const char* path, const char* module_info, napi_value* result);
```

| Parameter           | Description         |
| :------------- | :----------------------------- |
| env            | Current VM environment.      |
| path          | Path of the file or name of the module to load.         |
| module_info   | Path composed of **bundleName** and **moduleName**.      |
| result         | Module loaded.         |

> **NOTE**
>
> 1. **bundleName** indicates the project name configured in **AppScope/app.json5**.
> 2. **moduleName** must be set to the module name configured in the **module.json5** file in the HAP to which the module belongs.

## Scenarios Supported by napi_load_module_with_info

| Scenario           | Description          | Description                        |
| :------------- | :----------------------------- | :--------------------------- |
| Local project module  | Load the module file.      | The file path must start with **moduleName**.            |
| Local project module  | Load the HAR module name.          | -                            |
| Remote package        | Load the remote HAR module name.       | -                            |
| Remote package        | Load the ohpm package name.           | -                            |
| API        |    Load **@ohos.** or **@system.**.         | -                            |
| Native library  | Load **libNativeLibrary.so**.| -                            |

> **NOTE**
>
> 1. The module name to be loaded is the entry file, generally **index.ets/ts**, of the module.
> 2. To load a HAR to another HAR, ensure that **module_info** is correct. The value of **moduleName** must be that of the HAP or HSP.
> 3. If a third-party package is directly or indirectly used in a HAP/HSP and the third-party package has loaded another module, for example, module A, using **napi_load_module_with_info**, you must add module A in the dependencies of the HAP/HSP.

## Exception Scenarios
1. When no file is found in the package or the **build-profile.json5** configuration is incorrect during module loading, the error code **napi_generic_failure** is returned and an error log is printed.
![napi_load_module_with_info](figures/napi_load_module_with_info.png)
2. The module loading fails due to unexpected behavior on the system side, and **cppcrash** is thrown.

## How to Use

- **Loading a module file**

Load a module from a file, as shown in the following ArkTS code.

```javascript
//./src/main/ets/Test.ets
let value = 123;
function test() {
  console.info("Hello OpenHarmony");
}
export {value, test};
```

1. Configure the **build-profile.json5** file of the current module as follows:

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

2. Call **napi_load_module_with_info** to load the **Test.ets** file, call the **test()** function, and obtain the variable values.

    > **NOTE**
    >
    > When a module file is loaded with **useNormalizedOHMUrl** enabled (the **useNormalizedOHMUrl** field of **strictMode** in the application's **build-profile.json5** file in the same directory as **entry** in the project is set to **true**):
    >
    > 1. **bundleName** does not affect the loading logic. The corresponding HAP in the process is intelligently indexed based on the module name. For example, the module can be successfully loaded if **bundleName** is set to **com.example.application1** while the actual bundle name of the project is **com.example.application**.
    > 2. The file path must start with **packageName**, which is the value of **name** in the **oh-package.json5** file of the module.


    ~~~c++
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module_with_info to load the module from the Test.ets file.
        napi_status status = napi_load_module_with_info(env, "entry/src/main/ets/Test", "com.example.application/entry", &result);
        if (status != napi_ok) {
            return nullptr;
        }

        napi_value testFn;
        // 2. Call napi_get_named_property to obtain the test function.
        napi_get_named_property(env, result, "test", &testFn);
        // 3. Call napi_call_function to invoke the test function.
        napi_call_function(env, result, testFn, 0, nullptr, nullptr);

        napi_value value;
        napi_value key;
        std::string keyStr = "value";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 4. Call napi_get_property to obtain a variable value.
        napi_get_property(env, result, key, &value);
        return result;
    }
    ~~~

- **Loading a source code HAR module**

The **Index.ets** file in the HAR is as follows:

```javascript
//library Index.ets
let value = 123;
function test() {
    console.info("Hello OpenHarmony");
}
export {value, test};
```

1. Configure **dependencies** in the **oh-package.json5** file.

    ```json
    {
        "dependencies": {
            "library": "file:../library"
        }
    }
    ```

2. Configure **build-profile.json5** for the module that uses **library**.

    ```json
    {
        "buildOption" : {
            "arkOptions" : {
                "runtimeOnly" : {
                    "packages": [
                        "library"
                    ]
                }
            }
        }
    }
    ```

3. Call **napi_load_module_with_info** to load **library**, call the **test** function, and obtain the variable values.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module_with_info to load library.
        napi_status status = napi_load_module_with_info(env, "library", "com.example.application/entry", &result);
        if (status != napi_ok) {
           return nullptr;
        }
    
        napi_value testFn;
        // 2. Call napi_get_named_property to obtain the test function.
        napi_get_named_property(env, result, "test", &testFn);
        // 3. Call napi_call_function to invoke the test function.
        status = napi_call_function(env, result, testFn, 0, nullptr, nullptr);
        if (status != napi_ok) {
           return nullptr;
        }
    
        napi_value value;
        napi_value key;
        std::string keyStr = "value";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 4. Call napi_get_property to obtain a variable value.
        status = napi_get_property(env, result, key, &value);
        if (status != napi_ok) {
           return nullptr;
        }
        return result;
    }
    ```

- **Loading a source code HSP module**

The **Index.ets** file in the HSP is as follows:

```javascript
//hsp Index.ets
let value = 123;
function test() {
    console.info("Hello World");
}
export {value, test};
```

1. Configure **dependencies** in the **oh-package.json5** file.

    ```json
    {
        "dependencies": {
            "hsp": "file:../hsp"
        }
    }
    ```

2. Configure **build-profile.json5** for the module that uses the HSP.

    ```json
    {
        "buildOption" : {
            "arkOptions" : {
                "runtimeOnly" : {
                    "packages": [
                        "hsp"
                    ]
                }
            }
        }
    }
    ```

3. Call **napi_load_module_with_info** to load the HSP, call the **test** function, and obtain the **value** variable.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module_with_info to load the HSP.
        napi_status status = napi_load_module_with_info(env, "hsp", "com.example.application/entry", &result);
        if (status != napi_ok) {
            return nullptr;
        }

        napi_value testFn;
        // 2. Call napi_get_named_property to obtain the test function.
        status = napi_get_named_property(env, result, "test", &testFn);
        if (status != napi_ok) {
            return nullptr;
        }
        // 3. Call napi_call_function to invoke the test function.
        status = napi_call_function(env, result, testFn, 0, nullptr, nullptr);
        if (status != napi_ok) {
            return nullptr;
        }

        napi_value value;
        napi_value key;
        std::string keyStr = "value";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 4. Call napi_get_property to obtain a variable value.
        status = napi_get_property(env, result, key, &value);
        if (status != napi_ok) {
            return nullptr;
        }
        return result;
    }
    ```

- **Loading a remote HAR module name**

1. Configure **dependencies** in the **oh-package.json5** file.

    ```json
    {
        "dependencies": {
            "@ohos/hypium": "1.0.16"
        }
    }
    ```

2. Configure **build-profile.json5** for the module that uses @ohos/hypium.

    ```json
    {
        "buildOption" : {
            "arkOptions" : {
                "runtimeOnly" : {
                    "packages": [
                        "@ohos/hypium"
                    ]
                }
            }
        }
    }
    ```

3. Call **napi_load_module_with_info** to load **@ohos/hypium** and obtain the **DEFAULT** variable.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module_with_info to load @ohos/hypium.
        napi_status status = napi_load_module_with_info(env, "@ohos/hypium", "com.example.application/entry", &result);
        if (status != napi_ok) {
           return nullptr;
        }
    
        napi_value key;
        std::string keyStr = "DEFAULT";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 2. Call napi_get_property to obtain the DEFAULT variable.
        napi_value defaultValue;
        napi_get_property(env, result, key, &defaultValue);
        return result;
    }
    ```

- **Loading an ohpm package name**

1. Configure **dependencies** in the **oh-package.json5** file.

    ```json
    {
        "dependencies": {
            "json5": "^2.2.3"
        }
    }
    ```

2. Configure **build-profile.json5** for the module that uses the .json5 file.

    ```json
    {
        "buildOption" : {
            "arkOptions" : {
                "runtimeOnly" : {
                    "packages": [
                        "json5"
                    ]
                }
            }
        }
    }
    ```

3. Call **napi_load_module_with_info** to load **json5** and call the **stringify** function.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module_with_info to load json5.
        napi_status status = napi_load_module_with_info(env, "json5", "com.example.application/entry", &result);
        if (status != napi_ok) {
           return nullptr;
        }
    
        napi_value key;
        std::string keyStr = "default";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 2. Call napi_get_property to obtain the default object.
        napi_value defaultValue;
        napi_get_property(env, result, key, &defaultValue);
    
        napi_value stringifyFn;
        // 3. Call napi_get_named_property to obtain the stringify function.
        napi_get_named_property(env, defaultValue, "stringify", &stringifyFn);
        // 4. Call napi_call_function to invoke the stringify function.
        napi_value argStr;
        std::string text = "call json5 stringify";
        napi_create_string_utf8(env, text.c_str(), text.size(), &argStr);
        napi_value args[1] = {argStr};
    
        napi_value returnValue;
        napi_call_function(env, defaultValue, stringifyFn, 1, args, &returnValue);
        return result;
    }
    ```

- **Loading an API module**

```cpp
static napi_value loadModule(napi_env env, napi_callback_info info) {
    // 1. Call napi_load_module_with_info to load the @ohos.hilog module.
    napi_value result;
    napi_status status = napi_load_module_with_info(env, "@ohos.hilog", nullptr, &result);
    if (status != napi_ok) {
        return nullptr;
    }

    // 2. Call napi_get_named_property to obtain the info function.
    napi_value infoFn;
    status = napi_get_named_property(env, result, "info", &infoFn);
    if (status != napi_ok) {
        return nullptr;
    }

    napi_value tag;
    std::string formatStr = "test";
    napi_create_string_utf8(env, formatStr.c_str(), formatStr.size(), &tag);

    napi_value outputString;
    std::string str = "Hello OpenHarmony";
    napi_create_string_utf8(env, str.c_str(), str.size(), &outputString);

    napi_value flag;
    napi_create_int32(env, 0, &flag);

    napi_value args[3] = {flag, tag, outputString};
    // 3. Call napi_call_function to invoke the info function.
    status = napi_call_function(env, result, infoFn, 3, args, nullptr);
    if (status != napi_ok) {
        return nullptr;
    }
    return result;
}
```

- **Loading a native library**

The **index.d.ts** file of **libentry.so** is as follows:

```javascript
// index.d.ts
export const add: (a: number, b: number) => number;
```

1. Configure **dependencies** in the **oh-package.json5** file.

    ```json
    {
        "dependencies": {
            "libentry.so": "file:../src/main/cpp/types/libentry"
        }
    }
    ```

2. Configure **build-profile.json5** for the module that uses **libentry.so**.

    ```json
    {
        "buildOption" : {
            "arkOptions" : {
                "runtimeOnly" : {
                    "packages": [
                        "libentry.so"
                    ]
                }
            }
        }
    }
    ```

3. Call **napi_load_module_with_info** to load **libentry.so** and call the **add** function.

    ```cpp
    static constexpr int INT_NUM_2 = 2; // Integer 2
    static constexpr int INT_NUM_3 = 3; // Integer 3
    
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module_with_info to load libentry.so.
        napi_status status = napi_load_module_with_info(env, "libentry.so", "com.example.application/entry", &result);
        if (status != napi_ok) {
            return nullptr;
        }
    
        napi_value addFn;
        // 2. Call napi_get_named_property to obtain the add function.
        napi_get_named_property(env, result, "add", &addFn);
    
        napi_value a;
        napi_value b;
        napi_create_int32(env, INT_NUM_2, &a);
        napi_create_int32(env, INT_NUM_3, &b);
        napi_value args[2] = {a, b};
        // 3. Call napi_call_function to invoke the add function.
        napi_value returnValue;
        napi_call_function(env, result, addFn, INT_NUM_2, args, &returnValue);
        return result;
    }
    ```

- **Loading another HAR module to a HAR**

For example, load **har2** to **har1**. The **Index.ets** file of **har2** is as follows:

```javascript
//har2 Index.ets
let value = 123;
function test() {
  console.info("Hello OpenHarmony");
}
export {value, test};
```

1. Configure **dependencies** in the **oh-package.json5** file of **har1**.

    ```json
    {
        "dependencies": {
            "har2": "file:../har2"
        }
    }
    ```

2. Configure the **build-profile.json5** file for **har1**.

    ```json
    {
        "buildOption" : {
            "arkOptions" : {
                "runtimeOnly" : {
                    "packages": [
                        "har2"
                    ]
                }
            }
        }
    }
    ```

3. Call **napi_load_module_with_info** to load **har2** to **har1**, call the **test** function, and obtain the variable **value**.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module_with_info to load har2. Note that moduleName is that of the HAP where the module is located.
        napi_status status = napi_load_module_with_info(env, "har2", "com.example.application/entry", &result);
        if (status != napi_ok) {
            return nullptr;
        }
    
        napi_value testFn;
        // 2. Call napi_get_named_property to obtain the test function.
        status = napi_get_named_property(env, result, "test", &testFn);
        if (status != napi_ok) {
            return nullptr;
        }
        // 3. Call napi_call_function to invoke the test function.
        status = napi_call_function(env, result, testFn, 0, nullptr, nullptr);
        if (status != napi_ok) {
            return nullptr;
        }
    
        napi_value value;
        napi_value key;
        std::string keyStr = "value";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 4. Call napi_get_property to obtain a variable value.
        status = napi_get_property(env, result, key, &value);
        if (status != napi_ok) {
            return nullptr;
        }
        return result;
    }
    ```
