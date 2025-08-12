# JSON扩展库
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--SE: @yuanyao14-->
<!--TSE: @kirl75; @zsw_zhushiwei-->

## 场景介绍

该库扩展了原生JSON功能，提供了额外的错误处理、循环引用检测、BigInt处理以及对不同输入类型的严格检查。代码中底层依赖于原生JSON.parse和JSON.stringify，但在此基础上加入了多种自定义逻辑并提供额外的has和remove接口，具体可见[@arkts.json](../reference/apis-arkts/js-apis-json.md)。

JSON扩展库主要适用于以下场景：

- 需要处理BigInt的JSON解析或序列化。

- 需要更严格的参数校验和错误处理。

- 需要在序列化对象时检测循环引用。

- 需要安全的对象操作（has/remove）。

该库适用于需要增强JSON功能的场景，特别是在处理BigInt和严格的参数校验时。

## JSON扩展说明

### parse

parse(text: string, reviver?: Transformer, options?: ParseOptions): Object | null

解析JSON字符串，支持BigInt模式。

**与原生的区别：**

| 特性	| 原生parse	 | 本库parse |
| -------- | -------- | -------- |
| BigInt支持	| 不支持（抛出TypeError） |支持（通过parseBigInt扩展）|
| 参数校验	| 弱校验 |强校验（抛出BusinessError） |
| 错误信息	| 原生错误（如SyntaxError） |	自定义BusinessError |
| reviver参数	| 支持 | 支持，但强制类型检查 |

### stringify

stringify(value: Object, replacer?: (number | string)[] | null, space?: string | number): string

将对象转换为JSON字符串，支持BigInt模式。

**与原生的区别：**

| 特性	| 原生stringify | 本库stringify |
| -------- | -------- | -------- |
| BigInt支持 | 不支持（抛出TypeError）| 支持（通过stringifyBigInt扩展） |
| 循环引用检测 | 抛出TypeError | 检测并抛出BusinessError |
| 参数校验 | 弱校验	| 强校验（replacer 必须是函数或数组） |
| 错误信息 | 原生错误	| 自定义BusinessError |

### has

has(obj: object, property: string): boolean

检查对象是否包含指定的属性，确保传入的值是一个对象，并且属性键是有效的字符串。

**与原生的区别：**

| 特性| 原生方式（obj.hasOwnProperty） | 本库has |
| -------- | -------- | -------- |
| 参数校验 | 无校验（可能误用） | 强制检查obj是普通对象，property是非空字符串 |
| 错误处理 | 可能静默失败 | 抛出BusinessError |

### remove

remove(obj: object, property: string): void

从对象中删除指定的属性。

| 特性 | 原生方式（delete obj.key） | 本库remove |
| -------- | -------- | -------- | 
| 参数校验 | 无校验（可能误删） | 强制检查obj是普通对象，property是非空字符串 |
| 错误处理 | 可能静默失败 | 抛出BusinessError |

### 总结

| 功能 | 原生JSON | 本库 |
| ----- | ----- | -----| 
| 严格参数校验 | 不支持 |	支持 |
| 循环引用检测 | 不支持 |	支持 |
| BigInt处理 | 不支持 |	支持 |
| 增强的错误处理（BusinessError） | 不支持 | 支持 |
| 额外方法（has/remove） | 不支持 | 支持 |

## 开发场景

### 解析包含嵌套引号的JSON字符串场景

JSON字符串中的嵌套引号会破坏其结构，将导致解析失败。

```ts
// 比如以下JSON字符串，由于嵌套引号导致结构破坏，执行JSON.parse将会抛异常。
// let jsonStr = `{"info": "{"name": "zhangsan", "age": 18}"}`;
```

以下提供两种方式解决该场景问题：

方式1：避免出现嵌套引号的操作。

```ts
import { JSON } from '@kit.ArkTS';

interface Info {
  name: string;
  age: number;
}

interface TestObj {
  info: Info;
}

interface TestStr {
  info: string;
}

/*
 * 将原始JSON字符串`{"info": "{"name": "zhangsan", "age": 18}"}`
 * 修改为`{"info": {"name": "zhangsan", "age": 18}}`。
 * */
let jsonStr = `{"info": {"name": "zhangsan", "age": 18}}`;
let obj1  = JSON.parse(jsonStr) as TestObj;
console.info(JSON.stringify(obj1));    //{"info":{"name":"zhangsan","age":18}}
// 获取JSON字符串中的name信息
console.info(obj1.info.name); // zhangsan
```

方式2：将JSON字符串中嵌套的引号进行双重转义，恢复JSON的正常结构。

```ts
import { JSON } from '@kit.ArkTS';

interface Info {
  name: string;
  age: number;
}

interface TestObj {
  info: Info;
}

interface TestStr {
  info: string;
}

/*
 * 将原始JSON字符串`{"info": "{"name": "zhangsan", "age": 18}"}`进行双重转义，
 * 修改为`{"info": "{\\"name\\": \\"zhangsan\\", \\"age\\": 18}"}`。
 * */
let jsonStr = `{"info": "{\\"name\\": \\"zhangsan\\", \\"age\\": 18}"}`;
let obj2 = JSON.parse(jsonStr) as TestStr;
console.info(JSON.stringify(obj2));    // {"info":"{\"name\": \"zhangsan\", \"age\": 18}"}
// 获取JSON字符串中的name信息
let obj3 = JSON.parse(obj2.info) as Info;
console.info(obj3.name); // zhangsan
```

### 解析包含大整数的JSON字符串场景

当JSON字符串中存在小于-(2^53-1)或大于(2^53-1)的整数时，解析后数据会出现精度丢失或不正确的情况。该解析场景需要指定BigIntMode，将大整数解析为BigInt。

```ts
import { JSON } from '@kit.ArkTS';

let numberText = '{"number": 10, "largeNumber": 112233445566778899}';

let numberObj1 = JSON.parse(numberText) as Object;
console.info((numberObj1 as object)?.["largeNumber"]);    // 112233445566778900

// 使用PARSE_AS_BIGINT的BigInt模式进行解析，避免出现大整数解析错误。
let options: JSON.ParseOptions = {
  bigIntMode: JSON.BigIntMode.PARSE_AS_BIGINT,
}

let numberObj2 = JSON.parse(numberText, null, options) as Object;

console.info(typeof (numberObj2 as object)?.["number"]);   // number
console.info((numberObj2 as object)?.["number"]);    // 10

console.info(typeof (numberObj2 as object)?.["largeNumber"]);    // bigint
console.info((numberObj2 as object)?.["largeNumber"]);    // 112233445566778899
```

### 序列化BigInt对象场景

为弥补原生JSON无法序列化BigInt对象的缺陷，本库提供以下两种JSON序列化方式：

方式1：不使用自定义转换函数，直接序列化BigInt对象。

```ts
import { JSON } from '@kit.ArkTS';

let bigIntObject = BigInt(112233445566778899n)

console.info(JSON.stringify(bigIntObject)); // 112233445566778899
```

方式2：使用自定义转换函数，需预处理BigInt对象进行序列化操作。

```ts
import { JSON } from '@kit.ArkTS';

let bigIntObject = BigInt(112233445566778899n)

// 错误序列化用法：自定义函数中直接返回BigInt对象
// JSON.stringify(bigIntObject, (key: string, value: Object): Object =>{ return value; });

// 正确序列化用法：自定义函数中将BigInt对象预处理为string对象
let result: string = JSON.stringify(bigIntObject, (key: string, value: Object): Object => {
  if (typeof value === 'bigint') {
    return value.toString();
  }
  return value;
});
console.info("result:", result); // result: "112233445566778899"
```

### 序列化浮点数number场景

在JSON序列化中，浮点数处理存在一个特殊行为：当小数部分为零时，为保持数值的简洁表示，序列化结果会自动省略小数部分。这可能导致精度信息丢失，影响需要精确表示浮点数的场景（如金融金额、科学计量）。以下示例提供解决该场景的方法：

```ts
import { JSON } from '@kit.ArkTS';

// 序列化小数部分不为零的浮点数，可以正常序列化。
let floatNumber1 = 10.12345;
console.info(JSON.stringify(floatNumber1)); // 10.12345

// 序列化小数部分为零的浮点数，为保持数值的简洁表示，会丢失小数部分的精度。
let floatNumber2 = 10.00;
console.info(JSON.stringify(floatNumber2)); // 10

// 以下是防止浮点数精度丢失的方法：
let result = JSON.stringify(floatNumber2, (key: string, value: Object): Object => {
  if (typeof value === 'number') {
    // 按照业务场景需要，定制所需的固定精度。
    return value.toFixed(2);
  }
  return value;
});
console.info(result); // "10.00"
```
