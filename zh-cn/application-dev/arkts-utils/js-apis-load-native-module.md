# 同步方式动态加载native模块

loadNativeModule接口用于以同步方式动态加载native模块。其主要目的是在需要某个native模块时才进行加载，从而避免在应用启动时加载不必要的模块。但是使用该接口时会产生加载so耗时，需要开发者自行评估是否会对功能产生影响。

## 函数说明

```js
loadNativeModule(moduleName: string): Object;
```

| 参数            | 说明          |
| :------------- | :----------------------------- |
| moduleName            | 加载的模块名。       |

> **说明**
> loadNativeModule加载的模块名是指依赖方oh-package.json5文件的dependencies中的名字。
>
> loadNativeModule必须在UI主线程中调用。
>
> 该接口在加载常量字符串或变量表达式作为参数时，需要配置依赖。

## loadNativeModule支持的场景

| 场景            | 示例           | 
| :------------- | :----------------------------- | 
| 系统库模块        | 加载@ohos.或@system.        | 
| 应用内native模块	| 加载libNativeLibrary.so |

## 使用示例

- **HAP加载系统库模块**

```js
let hilog: ESObject = loadNativeModule("@ohos.hilog");
hilog.info(0, "testTag", "loadNativeModule ohos.hilog success");
```

- **HAP加载Native库**

libentry.so的index.d.ts文件如下：

```javascript
//index.d.ts
export const add: (a: number, b: number) => number;
```

1.加载本地so库时，需要在oh-package.json5文件中配置dependencies项。

```json
{
    "dependencies": {
        "libentry.so": "file:../src/main/cpp/types/libentry"
    }
}
```

2.在build-profile.json5中进行配置。

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

3.使用loadNativeModule加载libentry.so，并调用add函数。

```js
let module: ESObject = loadNativeModule("libentry.so");
let sum: number = module.add(1, 2);
```
