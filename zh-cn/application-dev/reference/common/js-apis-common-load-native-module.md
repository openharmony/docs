# loadNativeModule (同步动态加载系统库接口)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @yao_dashuai-->
<!--Designer: @yao_dashuai-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

本模块提供了同步动态加载系统库接口的能力。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## loadNativeModule

loadNativeModule(moduleName: string): Object

`loadNativeModule`接口用于同步动态加载native模块，目的是按需加载所需要的模块。

**系统能力**：SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型     | 必填      | 说明  |
| ----- | -------- | ----  | ---------------- |
| moduleName | string | 是     | 加载的模块名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Object | native模块的默认导出，需使用ArkTS的ESObject类型去接收。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](../apis-arkts/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | The parameter check failed.|
| 10200301 | Loading native module failed.|

**loadNativeModule支持的场景**

| 场景            | 示例           |
| :------------- | :----------------------------- |
| 系统库模块        | 加载@ohos.或@system.        |
| 应用内native模块  | 加载libNativeLibrary.so |

### 使用注意事项

- `loadNativeModule`仅支持在Stage模型的UI主线程中加载native模块。
- 使用该接口会增加so文件的加载时间，使用前需评估其对应用性能和功能的影响。
- 无论`moduleName`参数使用常量字符串还是变量表达式，都需要在依赖方模块级`oh-package.json5`文件的`dependencies`字段中配置依赖。`moduleName`的值为`dependencies`字段中声明的依赖名称。
- 加载应用内native模块时，还需要在依赖方模块级`build-profile.json5`文件的`buildOption.arkOptions.runtimeOnly.packages`字段中配置模块名称。该名称需与`oh-package.json5`文件中的依赖名称及`loadNativeModule`的入参保持一致。
- 接口声明的返回值类型为`Object`。调用时需使用`ESObject`类型的变量接收返回值，才能调用native模块导出的方法；使用`Object`类型接收返回值时，调用其中的方法可能会产生编译错误。

以加载`libentry.so`为例，需要完成以下配置。

1. 在模块级`oh-package.json5`文件中配置`dependencies`字段。配置说明见[模块级oh-package.json5](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-oh-package-json5#zh-cn_topic_0000001792256137_oh-packagejson5-%E5%AD%97%E6%AE%B5%E8%AF%B4%E6%98%8E)。

    ```json
    {
      "dependencies": {
        "libentry.so": "file:./src/main/cpp/types/libentry"
      }
    }
    ```

2. 在模块级`build-profile.json5`文件中配置`runtimeOnly.packages`字段。配置说明见[模块级build-profile.json5文件](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-profile)。

    ```json
    {
      "buildOption": {
        "arkOptions": {
          "runtimeOnly": {
            "packages": [
              "libentry.so"
            ]
          }
        }
      }
    }
    ```

**示例1**：HAP加载系统库模块

```js
let hilog: ESObject = loadNativeModule("@ohos.hilog");
hilog.info(0, "testTag", "loadNativeModule ohos.hilog success");
```

**示例2**：HAP加载Native库

libentry.so的index.d.ts文件内容如下：

```javascript
//index.d.ts
export const add: (a: number, b: number) => number;
```

完成[使用注意事项](#使用注意事项)中的依赖配置后，使用`loadNativeModule`加载`libentry.so`并调用`add`函数。

```js
let module: ESObject = loadNativeModule("libentry.so");
let sum: number = module.add(1, 2);
```
