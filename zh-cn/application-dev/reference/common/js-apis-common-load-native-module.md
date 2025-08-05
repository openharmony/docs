# loadNativeModule (同步动态加载系统库接口)

本模块提供了同步动态加载系统库接口的能力。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## loadNativeModule

loadNativeModule(moduleName: string): Object

`loadNativeModule`接口用于同步动态加载native模块，目的是按需加载所需要的模块。使用该接口会增加加载so文件的时间，开发者需评估其对功能的影响。

> **说明：**
>
> loadNativeModule加载的模块名指的是依赖方`oh-package.json5`文件的`dependencies`字段内的名称。
>
> loadNativeModule接口仅支持在UI主线程中加载native模块。
>
> 该接口在使用常量字符串或变量表达式作为参数时，都需要配置依赖。

**系统能力**：SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型     | 必填      | 说明  |
| ----- | -------- | ----  | ---------------- |
| moduleName | string | 是     | 加载的模块名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Object | native模块的默认导出。 |

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
| 应用内native模块	| 加载libNativeLibrary.so |

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

1.在加载本地so库时，配置模块级`oh-package.json5`文件的dependencies项。配置说明见[模块级oh-package.json5](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-oh-package-json5#zh-cn_topic_0000001792256137_oh-packagejson5-%E5%AD%97%E6%AE%B5%E8%AF%B4%E6%98%8E)。

```json
{
  "dependencies": {
    "libentry.so": "file:./src/main/cpp/types/libentry"
  }
}
```

2.在模块级`build-profile.json5`中进行配置。配置说明见[模块级build-profile.json5文件](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-hvigor-build-profile)。

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

3.使用`loadNativeModule`加载`libentry.so`，调用`add`函数。

```js
let module: ESObject = loadNativeModule("libentry.so");
let sum: number = module.add(1, 2);
```
