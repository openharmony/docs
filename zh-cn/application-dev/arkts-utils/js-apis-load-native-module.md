# 同步方式动态加载native模块

loadNativeModule接口的功能是同步方式动态加载native模块。当需要使用某个模块时，再使用该接口进行加载，可以缩短冷起耗时。但是使用该接口时会产生加载so耗时，需要开发者自行评估是否会对功能产生影响。

## 函数说明

```js
loadNativeModule(moduleName: string): Object;
```

| 参数            | 说明          |
| :------------- | :----------------------------- |
| moduleName            | 加载的模块名       |

> **说明**
> moduleName指的是待加载模块所在的HAP下module.json5中配置的名字。
>
> loadNativeModule只局限于在UI主线程中进行模块加载。
>
> 该接口功能不论是加载常量字符串还是变量表达式入参，都需要配置依赖。

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

libentry.so的index.d.ts文件如下

```javascript
//index.d.ts
export const add: (a: number, b: number) => number;
```

1.在加载本地so库时，首先需要在oh-package.json5文件中配置dependencies项

```json
{
    "dependencies": {
        "libentry.so": "file:../src/main/cpp/types/libentry"
    }
}
```

2.其次，还需要在build-profile.json5中进行配置

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

3.用loadNativeModule加载libentry.so，调用函数add

```js
let module: ESObject = loadNativeModule("libentry.so");
let sum: number = module.add(1, 2);
```
