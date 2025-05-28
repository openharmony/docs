# 使用Node-API接口进行模块加载

Node-API中的napi_load_module_with_info接口的功能是进行模块的加载，当模块加载出来之后，可以使用函数napi_get_property获取模块导出的变量，也可以使用napi_get_named_property获取模块导出的函数，该函数可以在[新创建的ArkTS基础运行时环境](use-napi-ark-runtime.md)中使用，即napi_create_ark_runtime接口创建的运行时环境。

## 函数说明

```cpp
napi_status napi_load_module_with_info(napi_env env, const char* path, const char* module_info, napi_value* result);
```

| 参数            | 说明          |
| :------------- | :----------------------------- |
| env            | 当前的虚拟机环境       |
| path          | 加载的文件路径或者模块名          |
| module_info   | bundleName/moduleName的路径拼接       |
| result         | 加载的模块          |

> **注意**
>
> 1. bundleName表示AppScope/app.json5中配置的工程名；
> 2. moduleName指的是待加载模块所在的HAP下module.json5中配置的名字；

## napi_load_module_with_info支持的场景

| 场景            | 详细分类           | 说明                         |
| :------------- | :----------------------------- | :--------------------------- |
| 本地工程模块   | 加载模块内文件路径       | 要求路径以moduleName开头             |
| 本地工程模块   | 加载HAR模块名           | -                            |
| 远程包         | 加载远程HAR模块名        | -                            |
| 远程包         | 加载ohpm包名            | -                            |
| API        |    加载@ohos.*或 @system.*          | -                            |
| 模块Native库   | 加载libNativeLibrary.so | -                            |

> **注意**
>
> 1. 加载一个模块名，实际的行为是加载该模块的入口文件，一般为index.ets/ts。
> 2. 如果在HAR中加载另外一个HAR，需要确保module_info的配置正确，尤其注意moduleName应为HAP的moduleName或者HSP的moduleName。
> 3. 如果在HAP/HSP中直接或间接使用了三方包，该三方包中使用napi_load_module_with_info接口加载其他模块A，则需要在HAP/HSP中也添加A的依赖。

## 异常场景
1. 例如当hsp的moduleName错误时，会导致加载hsp失败，返回错误码`napi_generic_failure`。
2. 在模块加载过程中，若出现链接关系错误或包内未找到对应文件等问题，该API将抛出referenceError异常，并返回错误码`napi_pending_exception`。
3. 系统侧发生非预期行为导致加载模块无法正常执行，将抛出cppcrash。

## 使用示例

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

1. 当前模块的build-profile.json5文件中需进行以下配置：

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

2. 使用napi_load_module_with_info加载Test文件，调用函数test以及获取变量value。

    > **注意**
    >
    > 开启useNormalizedOHMUrl后（即将工程目录中与entry同级别的应用级build-profile.json5文件中strictMode属性的useNormalizedOHMUrl字段配置为true），加载模块内文件路径时：
    >
    > 1. bundleName不会影响最终加载逻辑，会智能通过module名索引进程内对应的hap，例如：工程的bundleName为com.example.application，实际入参时填写为 com.example.application1，模块也能正常加载。
    > 2. 路径需要以packageName开头，packageName指的是模块的oh-package.json5中配置的name字段。


    ~~~c++
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module_with_info加载Test文件中的模块
        napi_status status = napi_load_module_with_info(env, "entry/src/main/ets/Test", "com.example.application/entry", &result);
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
    ~~~

- **加载源码HAR模块**

HAR包Index.ets文件如下：

```javascript
//library Index.ets
let value = 123;
function test() {
    console.log("Hello OpenHarmony");
}
export {value, test};
```

1. 在oh-package.json5文件中配置dependencies项：

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

3. 使用napi_load_module_with_info加载library，调用函数test以及获取变量value：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module_with_info加载library
        napi_status status = napi_load_module_with_info(env, "library", "com.example.application/entry", &result);
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

- **加载源码HSP模块**

HSP包Index.ets文件如下：

```javascript
//hsp Index.ets
let value = 123;
function test() {
    console.log("Hello World");
}
export {value, test};
```

1. 在oh-package.json5文件中配置dependencies项：

    ```json
    {
        "dependencies": {
            "hsp": "file:../hsp"
        }
    }
    ```

2. 在使用hsp的模块中，对build-profile.json5进行配置：

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

3. 使用napi_load_module_with_info加载hsp，调用函数test以及获取变量value：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module_with_info加载hsp
        napi_status status = napi_load_module_with_info(env, "hsp", "com.example.application/entry", &result);
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

1. 在oh-package.json5文件中配置dependencies项：

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

3. 使用napi_load_module_with_info加载@ohos/hypium，获取DEFAULT变量：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module_with_info加载@ohos/hypium
        napi_status status = napi_load_module_with_info(env, "@ohos/hypium", "com.example.application/entry", &result);
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

1. 在oh-package.json5文件中配置dependencies项：

    ```json
    {
        "dependencies": {
            "json5": "^2.2.3"
        }
    }
    ```

2. 在使用json5的模块中，对build-profile.json5进行配置：

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

3. 用napi_load_module_with_info加载json5，调用函数stringify：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module_with_info加载json5
        napi_status status = napi_load_module_with_info(env, "json5", "com.example.application/entry", &result);
        if (status != napi_ok) {
           return nullptr;
        }
    
        napi_value key;
        std::string keyStr = "default";
        napi_create_string_utf8(env, keyStr.c_str(), keyStr.size(), &key);
        // 2. 使用napi_get_property获取default对象
        napi_value defaultValue;
        napi_get_property(env, result, key, &defaultValue);
    
        napi_value stringifyFn;
        // 3. 使用napi_get_named_property获取stringify函数
        napi_get_named_property(env, defaultValue, "stringify", &stringifyFn);
        // 4. 使用napi_call_function调用函数stringify
        napi_value argStr;
        std::string text = "call json5 stringify";
        napi_create_string_utf8(env, text.c_str(), text.size(), &argStr);
        napi_value args[1] = {argStr};
    
        napi_value returnValue;
        napi_call_function(env, defaultValue, stringifyFn, 1, args, &returnValue);
        return result;
    }
    ```

- **加载API模块**

```cpp
static napi_value loadModule(napi_env env, napi_callback_info info) {
    // 1. 使用napi_load_module_with_info加载模块@ohos.hilog
    napi_value result;
    napi_status status = napi_load_module_with_info(env, "@ohos.hilog", nullptr, &result);
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

- **加载Native库**

libentry.so的index.d.ts文件如下：

```javascript
//index.d.ts
export const add: (a: number, b: number) => number;
```

1. 在oh-package.json5文件中配置dependencies项：

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

3. 用napi_load_module_with_info加载libentry.so，调用函数add：

    ```cpp
    static constexpr int INT_NUM_2 = 2; // int类型数值2
    static constexpr int INT_NUM_3 = 3; // int类型数值3
    
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module_with_info加载libentry.so
        napi_status status = napi_load_module_with_info(env, "libentry.so", "com.example.application/entry", &result);
        if (status != napi_ok) {
            return nullptr;
        }
    
        napi_value addFn;
        // 2. 使用napi_get_named_property获取add函数
        napi_get_named_property(env, result, "add", &addFn);
    
        napi_value a;
        napi_value b;
        napi_create_int32(env, INT_NUM_2, &a);
        napi_create_int32(env, INT_NUM_3, &b);
        napi_value args[2] = {a, b};
        // 3. 使用napi_call_function调用函数add
        napi_value returnValue;
        napi_call_function(env, result, addFn, INT_NUM_2, args, &returnValue);
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

3. 在har1中使用napi_load_module_with_info加载har2，调用test函数并获取value变量：

    ```cpp
    static napi_value loadModule(napi_env env, napi_callback_info info) {
        napi_value result;
        // 1. 使用napi_load_module_with_info加载har2，注意这里的moduleName为模块所在HAP包的moduleName
        napi_status status = napi_load_module_with_info(env, "har2", "com.example.application/entry", &result);
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
