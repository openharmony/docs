# @ohos.util.json (JSON解析与生成)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @Malzahar-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

本模块提供了将JSON文本转换为JSON对象或值，以及将对象转换为JSON文本等功能。模块基于标准JSON规范实现解析与序列化，通过Transformer机制支持自定义转换，通过BigIntMode策略解决BigInt兼容问题，并提供has/remove操作便于对解析结果进行属性查询与删除。

>**说明：**
>
>本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { JSON } from '@kit.ArkTS';
```

## Transformer

type Transformer = (this: Object, key: string, value: Object) => Object | undefined | null

用于转换结果的函数类型。<br>
作为[JSON.parse](#jsonparse)函数的参数时，解析结果中的每个键值对按深度优先顺序（从最内层节点开始，逐层向外）依次调用此函数，this指向当前键值对所属的对象，返回值替换原始值，若返回undefined则该属性将被删除。<br>
作为[JSON.stringify](#jsonstringify-1)函数的参数时，序列化引擎会按从外到内的顺序对每个属性调用该函数处理，this指向当前属性所属的对象，返回值作为序列化结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| this   | Object | 是 | 正在解析或序列化的键值对所属的对象。 |
| key  | string | 是 | 当前正在处理的对象成员的属性名，用于在转换函数中识别所解析或序列化的键。 |
| value  | Object | 是 | 正在解析或序列化的键值对的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Object \| undefined \| null | 返回转换处理后的属性值；返回undefined时，该属性在结果中被移除；返回null时，该属性值设为null。|

## BigIntMode

定义处理BigInt的模式。由于JSON规范不支持BigInt类型，且Number精度范围为-(2^53-1)到(2^53-1)，本模块提供三种模式以适配不同场景的整数精度需求。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 值 | 说明            |
| ------ | ------ | --------------- |
| DEFAULT   | 0 | 不支持BigInt，超大整数可能丢失精度。适用于不需要处理超大整数的常规JSON解析场景。|
| PARSE_AS_BIGINT   | 1 | 当整数小于-(2^53-1)或大于(2^53-1)时，解析为BigInt，普通整数仍按number处理。适用于JSON中可能包含超出安全整数范围的大整数、但普通整数不需要BigInt的场景。|
| ALWAYS_PARSE_AS_BIGINT   | 2 | 所有整数都解析为BigInt。适用于需要所有整数都以BigInt形式保留精度的场景，如高精度数值计算。|

## ParseOptions

解析的选项，可定义处理BigInt的模式。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明            |
| ------ | ------ | ---- | ---- | --------------- |
| bigIntMode   | [BigIntMode](#bigintmode) | 否 | 否 | 定义处理BigInt的模式。|

## JSON.parse

parse(text: string, reviver?: Transformer, options?: ParseOptions): Object | null

解析JSON字符串生成ArkTS对象或null。解析过程中，每个键值对按从最内层到最外层的顺序依次经过reviver函数处理，返回值替换原始值；当传入ParseOptions指定BigIntMode时，符合条件的整数将被解析为BigInt；当入参字符串为'null'时返回null。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| text   | string | 是 | 有效的JSON字符串，需符合JSON语法规范。 |
| reviver  | [Transformer](#transformer) | 否 | 转换函数，用于修改解析生成的原始值；当需要对解析结果进行自定义转换时使用。默认值是undefined。 |
| options   | [ParseOptions](#parseoptions) | 否 | 解析的配置选项，用于控制解析生成的类型。默认值是undefined。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Object \| null | 当传入的字符串为'null'时，返回null。 |

**示例：**

```ts
import { JSON } from '@kit.ArkTS';

function reviverFunc(key: string, value: Object): Object | undefined | null {
  if (key === "age" && typeof value === 'number') {
    return value + 1;
  }
  return value;
}

const jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let parsedObj = JSON.parse(jsonText);
console.info((parsedObj as object)?.["name"]);
// 打印结果：John

const jsonTextStr = '{"name": "John", "age": 30}';
let objRst = JSON.parse(jsonTextStr, reviverFunc);
console.info((objRst as object)?.["age"]);
// 打印结果：31

const numberText = '{"number": 10, "largeNumber": 112233445566778899}';
let options: JSON.ParseOptions = { bigIntMode: JSON.BigIntMode.PARSE_AS_BIGINT };
let numberObj = JSON.parse(numberText, null, options) as Object;

console.info(typeof (numberObj as object)?.["number"]);
// 打印结果：number
console.info((numberObj as object)?.["number"]);
// 打印结果：10

console.info(typeof (numberObj as object)?.["largeNumber"]);
// 打印结果：bigint
console.info((numberObj as object)?.["largeNumber"]);
// 打印结果：112233445566778899
```

## JSON.stringify

stringify(value: Object, replacer?: (number | string)[] | null, space?: string | number): string

该方法将一个ArkTS对象或数组转换为JSON字符串，支持线性容器的转换，不支持非线性容器（传入非线性容器时无法正确序列化）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | ArkTS对象或数组，支持线性容器的转换，不支持非线性容器。 |
| replacer | number[] \| string[] \| null | 否 | 用于筛选序列化属性。当参数为string[]时，只有包含在该数组中的对象属性名才会被序列化；当参数为number[]时，只有对应索引的数组元素才会被序列化；当参数为null或者未提供时，则对象所有的属性都会被序列化。默认值是undefined。|
| space | string \| number | 否 | 指定缩进用的空格或字符串，用于美化输出。当参数是数字时表示缩进空格数，取值需为非负整数；当参数是字符串时表示缩进字符；无参数则无缩进。默认值是空字符串。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 表示对象或数组经序列化处理后生成的JSON格式文本字符串。 |

**示例：**

```ts
import { JSON } from '@kit.ArkTS';

interface Person {
  name: string;
  age: number;
  city: string;
}

let person: Person = { name: "John", age: 30, city: "New York" };

let rstArrStr = JSON.stringify(person, ["name", "age"]);
console.info(rstArrStr);
// 打印结果：{"name":"John","age":30}

let rstStrSpace = JSON.stringify(person, ["name", "age"], '  ');
console.info(rstStrSpace);
/*
打印结果：
{
  "name": "John",
  "age": 30
}
 */

let rstStrStar = JSON.stringify(person, ["name", "age"], '  &&');
console.info(rstStrStar);
/*
打印结果：
{
  &&"name": "John",
  &&"age": 30
}
 */

let bigIntObj = BigInt(112233445566778899n);
console.info(JSON.stringify(bigIntObj));
// 打印结果：112233445566778899
```

## JSON.stringify

stringify(value: Object, replacer?: Transformer, space?: string | number): string

该方法将一个ArkTS对象或数组转换为JSON字符串，支持线性容器的转换，不支持非线性容器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | Object | 是 | ArkTS对象或数组，支持线性容器的转换，不支持非线性容器。 |
| replacer | [Transformer](#transformer) | 否 | 在序列化过程中，被序列化的值的每个属性都会经过该函数的转换和处理。当参数未提供时，则对象所有的属性都会被直接序列化，不经过转换处理。默认值是undefined。 |
| space | string \| number | 否 | 指定缩进用的空格或字符串，用于美化输出。当参数是数字时表示缩进空格数；当参数是字符串时表示缩进字符；无参数则无缩进。默认值是空字符串。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 表示对象或数组经序列化处理后生成的JSON格式文本字符串。|

**示例：**

```ts
import { JSON } from '@kit.ArkTS';

function replacer(key: string, value: Object): Object {
  if (typeof value === 'string') {
    return value.toUpperCase();
  }
  return value;
}

interface Person {
  name: string;
  age: number;
  city: string;
}
let inputObj = {"name": "John", "age": 30, "city": "ChongQing"} as Person;

console.info(JSON.stringify(inputObj, replacer));
// 打印结果：{"name":"JOHN","age":30,"city":"CHONGQING"}

console.info(JSON.stringify(inputObj, replacer, '  '));
/*
打印结果：
{
  "name": "JOHN",
  "age": 30,
  "city": "CHONGQING"
}
 */
```

## JSON.has

has(obj: object, property: string): boolean

检查ArkTS对象是否包含某种属性，可用于[JSON.parse](#jsonparse)解析JSON字符串之后。has接口仅支持最外层为字典形式（即大括号而非中括号包围）的合法JSON串，传入非字典形式的对象时无法正确判断属性是否存在。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | object | 是 | ArkTS对象，仅支持最外层为字典形式（即大括号而非中括号包围）的合法JSON串解析后的对象。 |
| property | string | 是 | 要检查的属性名称，用于指定需在ArkTS对象中查找是否存在的属性。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回ArkTS对象是否包含指定属性的结果。true表示对象包含指定属性；false表示对象不包含指定属性。 |

**示例：**

```ts
import { JSON } from '@kit.ArkTS';

const jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let inputObj = JSON.parse(jsonText);
let hasNameResult = JSON.has(inputObj, "name");
console.info("hasNameResult = " + hasNameResult);
// 打印结果：hasNameResult = true
```


## JSON.remove

remove(obj: object, property: string): void

从ArkTS对象中删除某种属性，可用于[JSON.parse](#jsonparse)解析JSON字符串之后，如清理敏感字段、移除冗余数据等场景。JSON.remove接口仅支持最外层为字典形式（即大括号而非中括号包围）的合法JSON串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | object | 是 | ArkTS对象，仅支持最外层为字典形式（即大括号而非中括号包围）的合法JSON串解析后的对象。 |
| property | string | 是 | 要删除的属性名称，用于指定需从ArkTS对象中移除的属性。 |

**示例：**

```ts
import { JSON } from '@kit.ArkTS';

const jsonText = '{"name": "John", "age": 30, "city": "ChongQing"}';
let inputObj = JSON.parse(jsonText);
JSON.remove(inputObj, "name");
let result = JSON.has(inputObj, "name");
console.info("result = " + result);
// 打印结果：result = false
```