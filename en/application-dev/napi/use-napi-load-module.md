# Loading a Module in the Main Thread Using Node-API

## **Scenario**

You can use **napi_load_module** to load a module in the main thread. After the module is loaded, you can use **napi_get_property** to obtain the variables of the module or use **napi_get_named_property** to obtain the functions of the module.

## Function Description

```cpp
napi_status napi_load_module(napi_env env, const char* path, napi_value* result);
```

| Parameter           | Description         |
| :------------- | :----------------------------- |
| env            | Current JSVM environment.      |
| path          | Pointer to the path of the file or name of the module to load.         |
| result         | Pointer to the module loaded.         |

## Constraints

- Do not use this API in non-main threads.
- Do not use this API in the **Init()** function.
- Do not load a file in the callback function of a thread-safe function.

You are advised to use [napi_load_module_with_info](use-napi-load-module-with-info.md) to load modules. This API supports more scenarios.

## Scenarios Supported by napi_load_module
| Scenario           | Scenario Description          | Remarks                        |
| :------------- | :----------------------------- | :--------------------------- |
| System module       |    Load **@ohos.** or **@system.**. | -                            |
| Local project module  | Load a module defined in a file under the **ets** directory.     | The file path must start with **ets**.            |
| Local project module  | Load a file path in a module.      | The file path must start with **moduleName**.            |
| Local project module  | Load the name of a HAR module.          | -                            |
| Local project module  | Load the name of an HSP module.          | -                            |
| Remote package        | Load the name of a remote HAR module.       | -                            |
| Remote package        | Load the ohpm package name.           | -                            |
| Native library of a module  | Load **libNativeLibrary.so**.| -                            |

- **Loading a System Module**

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        // 1. Call napi_load_module to load the @ohos.hilog module.
        napi_value result;
        napi_status status = napi_load_module(env, "@ohos.hilog", &result);
        if (status != napi_ok) {
            return nullptr;
        }

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
        // 3. Call napi_call_function to invoke the info function.
        napi_call_function(env, result, infoFn, 3, args, nullptr);
        return result;
    }
    ```

- **Loading a Module Defined in a File Under the ets Directory**

    For example, load a module from a file as shown in the following ArkTS code:

    ```javascript
    //./src/main/ets/Test.ets
    let value = 123;
    function test() {
      console.log("Hello OpenHarmony");
    }
    export {value, test};
    ```

1. Configure the **build-profile.json5** file of the project.

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

2. Call **napi_load_module** to load the module from the **Test.ets** file, call the **test()** function, and obtain the **value** variable.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module to load the module from the Test.ets file.
        napi_status status = napi_load_module(env, "ets/Test", &result);
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
        // 4. Call napi_get_property to obtain the value variable.
        napi_get_property(env, result, key, &value);
        return result;
    }
    ```
- **Loading a File Path in a Module**

    For example, load a module from a file as shown in the following ArkTS code:

    ```javascript
    //./src/main/ets/Test.ets
    let value = 123;
    function test() {
      console.log("Hello OpenHarmony");
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

2. Call **napi_load_module** to load the module from the **Test.ets** file, call the **test()** function, and obtain the **value** variable.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module to load the module from the Test.ets file.
        napi_status status = napi_load_module(env, "entry/src/main/ets/Test", &result);
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
    ```

- **Loading a HAR Module**

    For example, the **Index.ets** file in a HAR is as follows:

    ```javascript
    // Library Index.ets
    let value = 123;
    function test() {
      console.log("Hello OpenHarmony");
    }
    export {value, test};
    ```

1. Configure **dependencies** in the **oh-package.json5** file of the module.

    ```json
    {
      "dependencies": {
        "library": "file:../library"
      }
    }
    ```

2. Configure **build-profile.json5** for the module that uses the library.

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

3. Call **napi_load_module** to load the library, call the **test** function, and obtain the **value** variable.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module to load the library.
        napi_status status = napi_load_module(env, "library", &result);
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
        // 4. Call napi_get_property to obtain the value variable.
        napi_get_property(env, result, key, &value);
        return result;
    }
    ```

- **Loading an HSP module**

    For example, the **Index.ets** file in an HSP is as follows:

    ```javascript
    // Shared library Index.ets
    let value = 123;
    function test() {
      console.log("Hello OpenHarmony");
    }
    export {value, test};
    ```

1. Configure **dependencies** in the **oh-package.json5** file of the module.

    ```json
    {
      "dependencies": {
        "sharedlibrary": "file:../sharedlibrary"
      }
    }
    ```

2. Configure **build-profile.json5** for the module that uses the library.

    ```json
    {
      "buildOption" : {
        "arkOptions" : {
          "runtimeOnly" : {
            "packages": [
              "sharedlibrary"
            ]
          }
        }
      }
    }
    ```

3. Call **napi_load_module** to load the shared library, call the **test** function, and obtain the **value** variable.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module to load the shared library.
        napi_status status = napi_load_module(env, "sharedlibrary", &result);
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
        // 4. Call napi_get_property to obtain the value variable.
        napi_get_property(env, result, key, &value);
        return result;
    }
    ```

- **Loading a Remote HAR Module**

1. Configure **dependencies** in the **oh-package.json5** file of the module.

    ```json
    {
      "dependencies": {
        "@ohos/hypium": "1.0.16"
      }
    }
    ```

2. Configure **build-profile.json5** for the module that uses **@ohos/hypium**.

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

3. Call **napi_load_module** to load **@ohos/hypium** and obtain the **DEFAULT** variable.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module to load @ohos/hypium.
        napi_status status = napi_load_module(env, "@ohos/hypium", &result);
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

- **Loading an ohpm Package**

1. Configure **dependencies** in the **oh-package.json5** file of the module.

    ```json
    {
      "dependencies": {
        "@ohos/axios": "2.2.4",
      }
    }
    ```

2. Configure **build-profile.json5** for the module that uses **@ohos/axios**.

    ```json
    {
      "buildOption" : {
        "arkOptions" : {
          "runtimeOnly" : {
            "packages": [
              "@ohos/axios"
            ]
          }
        }
      }
    }
    ```

3. Call **napi_load_module** to load **@ohos/axios** and obtain the **VERSION** variable.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module to load @ohos/axios.
        napi_status status = napi_load_module(env, "@ohos/axios", &result);
        if (status != napi_ok) {
            return nullptr;
        }
    
        napi_value key;
        std::string keyStr = "VERSION";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 2. Call napi_get_property to obtain the version.
        napi_value defaultValue;
        napi_get_property(env, result, key, &defaultValue);
        return result;
    }
    ```

- **Loading a Native Library**

    For example, the **index.d.ts** file of **libentry.so** is as follows:

    ```javascript
    //index.d.ts
    export const add: (a: number, b: number) => number;
    ```

1. Configure **dependencies** in the **oh-package.json5** file of the module.

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

3. Call **napi_load_module** to load **libentry.so** and call the **add** function.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module to load libentry.so.
        napi_status status = napi_load_module(env, "libentry.so", &result);
        if (status != napi_ok) {
            return nullptr;
        }
    
        napi_value addFn;
        // 2. Call napi_get_named_property to obtain the add() function.
        napi_get_named_property(env, result, "add", &addFn);
        
        napi_value a;
        napi_value b;
        napi_create_int32(env, 2, &a);
        napi_create_int32(env, 3, &b);
        napi_value args[2] = {a, b};
        // 3. Call napi_call_function to invoke the add() function.
        napi_value returnValue;
        napi_call_function(env, result, addFn, 2, args, &returnValue);
        return result;
    }
    ```

- **Loading Another HAR Module to a HAR**

    For example, load **har2** to **har1**. The **Index.ets** file of **har2** is as follows:

    ```javascript
    //har2 Index.ets
    let value = 123;
    function test() {
      console.log("Hello OpenHarmony");
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
3. Call **napi_load_module** to load **har2** to **har1**, call the **test** function, and obtain the **value** variable.

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. Call napi_load_module to load har2.
        napi_status status = napi_load_module(env, "har2", &result);
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
        // 4. Call napi_get_property to obtain the value variable.
        napi_get_property(env, result, key, &value);
        return result;
    }
    ```
