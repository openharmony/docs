# 同步方式动态加载Native模块
<!--Kit: ArkTS-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @shilei123-->
<!--Designer: @yao_dashuai-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

[loadNativeModule (同步动态加载系统库接口)](../reference/common/js-apis-common-load-native-module.md)用于同步动态加载Native模块，目的是按需加载所需要的模块。

## 函数说明

```js
loadNativeModule(moduleName: string): Object;
```

| 参数            | 说明          |
| :------------- | :----------------------------- |
| moduleName            | 加载的模块名。       |

## loadNativeModule支持的场景

| 场景            | 示例           | 
| :------------- | :----------------------------- | 
| 系统库模块        | 加载@ohos.或@system.        | 
| 应用内Native模块  | 加载libNativeLibrary.so |

## 使用注意事项

- `loadNativeModule`仅支持在Stage模型的UI主线程中加载native模块。
- 使用该接口会增加so文件的加载时间，使用前需评估其对应用性能和功能的影响。
- 无论`moduleName`参数使用常量字符串还是变量表达式，都需要在依赖方模块级`oh-package.json5`文件的`dependencies`字段中配置依赖。`moduleName`的值为`dependencies`字段中声明的依赖名称。
- 加载应用内native模块时，还需要在依赖方模块级`build-profile.json5`文件的`buildOption.arkOptions.runtimeOnly.packages`字段中配置模块名称。该名称需与`oh-package.json5`文件中的依赖名称及`loadNativeModule`的入参保持一致。
- 接口声明的返回值类型为`Object`。调用时需使用`ESObject`类型的变量接收返回值，才能调用native模块导出的方法；使用`Object`类型接收返回值时，调用其中的方法可能会产生编译错误。

以加载`libentry.so`为例，需要完成以下配置。

1. 在模块级`oh-package.json5`文件中配置`dependencies`字段。

    <!-- @[hap_load_native_dependence](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSRuntime/ArkTSModule/JsApisLoadNativeModule/entry/oh-package.json5) -->

    ``` JSON5
    "dependencies": {
      "libentry.so": "file:./src/main/cpp/types/libentry"
    },
    ```

2. 在模块级`build-profile.json5`文件中配置`runtimeOnly.packages`字段。

    <!-- @[hap_load_native_dependence_01](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSRuntime/ArkTSModule/JsApisLoadNativeModule/entry/build-profile.json5) -->

    ``` JSON5
    "buildOption": {
      "arkOptions": {
        "runtimeOnly": {
          "packages": [
            "libentry.so"
          ]
        }
      },
      // ...
    },
    ```

## 使用示例

**示例1**：HAP加载系统库模块

<!-- @[hap_load_system_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSRuntime/ArkTSModule/JsApisLoadNativeModule/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
// HAP加载系统库模块
let hilog: ESObject = loadNativeModule('@ohos.hilog');
hilog.info(0, 'testTag', 'loadNativeModule ohos.hilog success');
```

**示例2**：HAP加载Native库

libentry.so的index.d.ts文件如下：

<!-- @[hap_load_native](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSRuntime/ArkTSModule/JsApisLoadNativeModule/entry/src/main/cpp/types/libentry/index.d.ts) -->

``` TypeScript
export const add: (a: number, b: number) => number;
```

完成[使用注意事项](#使用注意事项)中的依赖配置后，使用`loadNativeModule`加载`libentry.so`并调用`add`函数。

<!-- @[load_native_module_libentry](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTSRuntime/ArkTSModule/JsApisLoadNativeModule/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
//HAP加载Native库
let module: ESObject = loadNativeModule('libentry.so');
let sum: number = module.add(1, 2);
```
