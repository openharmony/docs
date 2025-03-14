# 使用Node-API接口在主线程中进行模块加载

## 场景介绍

Node-API中的napi_load_module接口的功能是在主线程中进行模块的加载，当模块加载出来之后，可以使用函数napi_get_property获取模块导出的变量，也可以使用napi_get_named_property获取模块导出的函数。

## 函数说明

```cpp
napi_status napi_load_module(napi_env env,
                             const char* path,
                             napi_value* result);
```

| 参数            | 说明          |
| :------------- | :----------------------------- |
| env            | 当前的虚拟机环境       |
| path          | 加载的文件路径或者模块名          |
| result         | 加载的模块          |

## 使用限制

- 禁止在非主线程当中使用该接口。
- 禁止在Init函数中使用该接口。
- 禁止在线程安全函数的回调函数当中进行文件路径的加载。

建议使用[napi_load_module_with_info](use-napi-load-module-with-info.md)来进行模块加载，该接口支持了更多的场景。

## napi_load_module支持的场景
| 场景            | 详细分类           | 说明                         |
| :------------- | :----------------------------- | :--------------------------- |
| 系统模块        |    加载@ohos.*或 @system.*  | -                            |
| 本地工程模块   | 加载ets目录下文件中的模块      | 要求路径以ets开头             |
| 本地工程模块   | 加载模块内文件路径       | 要求路径以moduleName开头             |
| 本地工程模块   | 加载HAR模块名           | -                            |
| 本地工程模块   | 加载HSP模块名           | -                            |
| 远程包         | 加载远程HAR模块名        | -                            |
| 远程包         | 加载ohpm包名            | -                            |
| 模块Native库   | 加载libNativeLibrary.so | -                            |

- **加载系统模块**

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        // 1. 使用napi_load_module加载模块@ohos.hilog
        napi_value result;
        napi_status status = napi_load_module(env, "@ohos.hilog", &result);
        if (status != napi_ok) {
            return nullptr;
        }

        // 2. 使用napi_get_named_property获取info函数
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
        // 3. 使用napi_call_function调用info函数
        napi_call_function(env, result, infoFn, 3, args, nullptr);
        return result;
    }
    ```

- **加载ets目录下文件中的模块**

    当加载文件中的模块时，如以下ArkTS代码：

    ```javascript
    //./src/main/ets/Test.ets
    let value = 123;
    function test() {
    console.log("Hello OpenHarmony");
    }
    export {value, test};
    ```

1. 需要在工程的build-profile.json5文件中进行以下配置：

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

2. 使用napi_load_module加载Test文件，调用函数test以及获取变量value：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module加载Test文件中的模块
        napi_status status = napi_load_module(env, "ets/Test", &result);
        if (status != napi_ok) {
            return nullptr;
        }

        napi_value testFn;
        // 2. 使用napi_get_named_property获取test函数
        napi_get_named_property(env, result, "test", &testFn);
        // 3. 使用napi_call_function调用函数test
        napi_call_function(env, result, testFn, 0, nullptr, nullptr);

        napi_value value;
        napi_value key;
        std::string keyStr = "value";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 4. 使用napi_get_property获取变量value
        napi_get_property(env, result, key, &value);
        return result;
    }
    ```
- **加载模块内文件路径**

    当加载文件中的模块时，如以下ArkTS代码：

    ```javascript
    //./src/main/ets/Test.ets
    let value = 123;
    function test() {
    console.log("Hello OpenHarmony");
    }
    export {value, test};
    ```

1. 需要当前模块的build-profile.json5文件中进行以下配置：

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

2. 使用napi_load_module加载Test文件，调用函数test以及获取变量value：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module加载Test文件中的模块
        napi_status status = napi_load_module(env, "entry/src/main/ets/Test", &result);
        if (status != napi_ok) {
            return nullptr;
        }

        napi_value testFn;
        // 2. 使用napi_get_named_property获取test函数
        napi_get_named_property(env, result, "test", &testFn);
        // 3. 使用napi_call_function调用函数test
        napi_call_function(env, result, testFn, 0, nullptr, nullptr);

        napi_value value;
        napi_value key;
        std::string keyStr = "value";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 4. 使用napi_get_property获取变量value
        napi_get_property(env, result, key, &value);
        return result;
    }
    ```

- **加载HAR模块名**

    HAR包Index.ets文件如下：

    ```javascript
    //library Index.ets
    let value = 123;
    function test() {
    console.log("Hello OpenHarmony");
    }
    export {value, test};
    ```

1. 在当前模块下的oh-package.json5文件中配置dependencies项：

    ```json
    {
        "dependencies": {
            "library": "file:../library"
        }
    }
    ```

2. 在使用library的模块中，对build-profile.json5进行配置：

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

3. 用napi_load_module加载library，调用函数test以及获取变量value：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module加载library
        napi_status status = napi_load_module(env, "library", &result);
        if (status != napi_ok) {
            return nullptr;
        }

        napi_value testFn;
        // 2. 使用napi_get_named_property获取test函数
        napi_get_named_property(env, result, "test", &testFn);
        // 3. 使用napi_call_function调用函数test
        napi_call_function(env, result, testFn, 0, nullptr, nullptr);

        napi_value value;
        napi_value key;
        std::string keyStr = "value";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 4. 使用napi_get_property获取变量value
        napi_get_property(env, result, key, &value);
        return result;
    }
    ```

- **加载HSP模块名**

    HSP包Index.ets文件如下：

    ```javascript
    //sharedlibrary Index.ets
    let value = 123;
    function test() {
    console.log("Hello OpenHarmony");
    }
    export {value, test};
    ```

1. 在当前模块下的oh-package.json5文件中配置dependencies项：

    ```json
    {
        "dependencies": {
            "sharedlibrary": "file:../sharedlibrary"
        }
    }
    ```

2. 在使用library的模块中，对build-profile.json5进行配置：

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

3. 用napi_load_module加载sharedlibrary，调用函数test以及获取变量value：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module加载sharedlibrary
        napi_status status = napi_load_module(env, "sharedlibrary", &result);
        if (status != napi_ok) {
            return nullptr;
        }

        napi_value testFn;
        // 2. 使用napi_get_named_property获取test函数
        napi_get_named_property(env, result, "test", &testFn);
        // 3. 使用napi_call_function调用函数test
        napi_call_function(env, result, testFn, 0, nullptr, nullptr);

        napi_value value;
        napi_value key;
        std::string keyStr = "value";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 4. 使用napi_get_property获取变量value
        napi_get_property(env, result, key, &value);
        return result;
    }
    ```

- **加载远程HAR模块名**

1. 在当前模块下的oh-package.json5文件中配置dependencies项：

    ```json
    {
        "dependencies": {
            "@ohos/hypium": "1.0.16"
        }
    }
    ```

2. 在使用@ohos/hypium的模块中，对build-profile.json5进行配置：

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

3. 用napi_load_module加载@ohos/hypium，获取DEFAULT变量：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module加载@ohos/hypium
        napi_status status = napi_load_module(env, "@ohos/hypium", &result);
        if (status != napi_ok) {
            return nullptr;
        }

        napi_value key;
        std::string keyStr = "DEFAULT";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 2. 使用napi_get_property获取DEFAULT变量
        napi_value defaultValue;
        napi_get_property(env, result, key, &defaultValue);
        return result;
    }
    ```

- **加载ohpm包名**

1. 在当前模块下的oh-package.json5文件中配置dependencies项：

    ```json
    {
        "dependencies": {
            "@ohos/axios": "2.2.4",
        }
    }
    ```

2. 在使用@ohos/axios的模块中，对build-profile.json5进行配置：

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

3. 用napi_load_module加载@ohos/axios，获取VERSION变量：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module加载@ohos/axios
        napi_status status = napi_load_module(env, "@ohos/axios", &result);
        if (status != napi_ok) {
            return nullptr;
        }

        napi_value key;
        std::string keyStr = "VERSION";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 2. 使用napi_get_property获取VERSION
        napi_value defaultValue;
        napi_get_property(env, result, key, &defaultValue);
        return result;
    }
    ```

- **加载Native库**

    libentry.so的index.d.ts文件如下：

    ```javascript
    //index.d.ts
    export const add: (a: number, b: number) => number;
    ```

1. 在当前模块下的oh-package.json5文件中配置dependencies项：

    ```json
    {
        "dependencies": {
            "libentry.so": "file:../src/main/cpp/types/libentry"
        }
    }
    ```

2. 在使用libentry.so的模块中，对build-profile.json5进行配置：

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

3. 用napi_load_module加载libentry.so，调用函数add：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module加载libentry.so
        napi_status status = napi_load_module(env, "libentry.so", &result);
        if (status != napi_ok) {
            return nullptr;
        }

        napi_value addFn;
        // 2. 使用napi_get_named_property获取add函数
        napi_get_named_property(env, result, "add", &addFn);
        
        napi_value a;
        napi_value b;
        napi_create_int32(env, 2, &a);
        napi_create_int32(env, 3, &b);
        napi_value args[2] = {a, b};
        // 3. 使用napi_call_function调用函数add
        napi_value returnValue;
        napi_call_function(env, result, addFn, 2, args, &returnValue);
        return result;
    }
    ```

- **HAR加载HAR模块名**

    场景为har1加载har2，har2中的Index.ets文件如下：

    ```javascript
    //har2 Index.ets
    let value = 123;
    function test() {
    console.log("Hello OpenHarmony");
    }
    export {value, test};
    ```

1. 在har1中的oh-package.json5文件中配置dependencies项：

    ```json
    {
        "dependencies": {
            "har2": "file:../har2"
        }
    }
    ```

2. 在har1的build-profile.json5文件中进行配置：

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
3. 在har1中用napi_load_module加载har2，调用函数test以及获取变量value：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module加载har2
        napi_status status = napi_load_module(env, "har2", &result);
        if (status != napi_ok) {
            return nullptr;
        }
        
        napi_value testFn;
        // 2. 使用napi_get_named_property获取test函数
        napi_get_named_property(env, result, "test", &testFn);
        // 3. 使用napi_call_function调用函数test
        napi_call_function(env, result, testFn, 0, nullptr, nullptr);

        napi_value value;
        napi_value key;
        std::string keyStr = "value";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 4. 使用napi_get_property获取变量value
        napi_get_property(env, result, key, &value);
        return result;
    }
    ```