# util系统JS API变更Changelog

OpenHarmony 3.2.10.7(Mr)版本相较于OpenHarmony 3.2.beta4版本，util子系统的API变更如下

## cl.util.1.randomUUID接口名变更
util子系统randomUUID函数名存在变更：

function randomUUID(entropyCache?: boolean): string 改为 function generateRandomUUID(entropyCache?: boolean): string 函数名由原来的randomUUID改为generateRandomUUID。

开发者需要根据以下说明对应用进行适配。

 **变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名      | 方法/属性/枚举/常量   | 变更类型 |
| :---------- | -------------------   | -------  |
| @ohos.util  | function randomUUID(entropyCache?: boolean): string        | 删除  |
| @ohos.util  | function generateRandomUUID(entropyCache?: boolean): string| 变更  | 

**适配指导**

应用中使用generateRandomUUID可参考下列代码

示例：

```ts
import util from '@ohos.util'
let uuid = util.generateRandomUUID(true);
console.log("RFC 4122 Version 4 UUID:" + uuid);
// 输出：
// RFC 4122 Version 4 UUID:88368f2a-d5db-47d8-a05f-534fab0a0045
```

## cl.util.2.randomBinaryUUID接口名变更
util子系统randomBinaryUUID函数名存在变更：

function randomBinaryUUID(entropyCache?: boolean): Uint8Array 改为 function generateRandomBinaryUUID(entropyCache?: boolean): Uint8Array 函数名由原来的randomBinaryUUID改为generateRandomBinaryUUID。

开发者需要根据以下说明对应用进行适配。

 **变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名      | 方法/属性/枚举/常量   | 变更类型 |
| :---------- | -------------------   | -------  |
| @ohos.util  | function randomBinaryUUID(entropyCache?: boolean): Uint8Array;       | 删除  |
| @ohos.util  | function generateRandomBinaryUUID(entropyCache?: boolean): Uint8Array| 变更  | 

**适配指导**

应用中使用generateRandomBinaryUUID可参考下列代码

示例：

```ts
import util from '@ohos.util'
let uuid = util.generateRandomBinaryUUID(true);
console.log(JSON.stringify(uuid));
// 输出：
// 138,188,43,243,62,254,70,119,130,20,235,222,199,164,140,150
```

## cl.util.3.LRUCache类contains接口参数类型变更
util子系统LRUCache类contains接口参数类型变更：

contains(key: object): boolean 改为 contains(key: K): boolean 参数类型由原来的object改为K。

开发者需要根据以下说明对应用进行适配。 

 **变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名     | 类名     | 方法/属性/枚举/常量              | 变更类型 |
| :--------  | ---------| -------------------------------- | -------- |
| @ohos.util | LRUCache |  contains(key: object): boolean  | 删除     |
| @ohos.util | LRUCache |  contains(key: K): boolean       | 变更     |

**适配指导**

应用中使用contains函数可参考下列代码

示例：

```ts
import util from '@ohos.util'
let pro = new util.LRUCache();
pro.put(2,10);
let obj = {1:"key"};
let result = pro.contains(obj);
```