# jsonx

>**说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块仅适用于ArkTS1.2。

## 导入模块

```ts
import { jsonx } from "std/core";
```

## JsonType

JSON值类型的枚举，用于在运行时识别JsonElement的类型。

| 名称      | 值  | 说明 |
| ---- | ---- | ---- |
| JsonUndefined | 0 | 没有值，与null不同。 |
| JsonObject    | 1 | 一个Json对象。 |
| JsonArray     | 2 | 一个Json数组。 |
| JsonString    | 3 | 一个Json字符串。 |
| JsonNumber    | 4 | 一个Json数字。 |
| JsonTrue      | 5 | 一个Json值为true。 |
| JsonFalse     | 6 | 一个Json值为false。 |
| JsonNull      | 7 | 一个Json值为null。 |

## JsonError

JSON的基本错误类。当发生一般的JSON解析或操作错误时抛出。

### constructor

constructor(msg: string)

JsonError的构造函数。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| msg | string | 是 | 错误信息。 |

## JsonTypeError

尝试访问具有不兼容类型的JSON元素时抛出错误。

### constructor

constructor(msg: string)

JsonTypeError的构造函数。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| msg | string | 是 | 错误信息。 |

## JsonElement

可容纳任何有效JSON值的JSON元素。提供类型安全的JSON值访问接口，包含严格模式和宽松模式两种API。

- 严格模式：例如getString，会返回string值。

- 宽松模式：例如tryGetString，当可以找到时会返回string值，未找到则返回空字符串。

### 属性

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| jsonType | [JsonType](#jsontype) | 是 | 否 | 获取JsonElement的类型。 |
| jsonKey | string | 是 | 否 | 获取该JSON元素对应的键。 |

### constructor

constructor()

JsonElement的构造函数。

**示例：**

```ts
const elem = new jsonx.JsonElement();
```

### constructor

constructor(other: JsonElement)

JsonElement的构造函数。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| other | [JsonElement](#jsonelement) | 是 | 一个JsonElement对象。 |

**示例：**

```ts
const elem = new jsonx.JsonElement();
const newElem = new jsonx.JsonElement(elem);
```

### constructor

constructor(elements: Record\<string, JsonElement\>)

JsonElement的构造函数。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| elements | Record\<string, [JsonElement](#jsonelement)\> | 是 | 用于创建元素的键值结构。 |

**示例：**

```ts
const original = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
```

### $_get

$_get(index: int): JsonElement

通过下标获取数组中的JsonElement。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| index | int | 是 | 需要获取的下标。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回数组下标对应的JsonElement。 |

**示例：**

```ts
const arrayElem = new jsonx.JsonElement();
const items = [
    jsonx.JsonElement.createString("item1"),
    jsonx.JsonElement.createInteger(42),
    jsonx.JsonElement.createBoolean(true)
];
arrayElem.setArray(items);
const firstElement = arrayElem[0].asString();
console.info("firstElement = " + firstElement); // firstElement = item1
```

### createString

createString(value: string): JsonElement

创建一个代表string值的JsonElement对象。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| value | string | 是 | 要存储的字符串值。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement。 |

**示例：**

```ts
const stringElem = jsonx.JsonElement.createString("Hello, Factory!");
const result = stringElem.asString();
console.info("result = " + result); // result = Hello, Factory!
```

### createDouble

createDouble(value: double): JsonElement

创建一个代表double值的JsonElement对象。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| value | double | 是 | 要存储的double值。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement。 |

**示例：**

```ts
const doubleElem = jsonx.JsonElement.createDouble(3.14159);
const result = doubleElem.asDouble();
console.info("result = " + result); // result = 3.14159
```

### createInteger

createInteger(value: int): JsonElement

创建一个代表int值的JsonElement对象。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| value | int | 是 | 要存储的int值。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement。 |

**示例：**

```ts
const integerElem = jsonx.JsonElement.createInteger(42);
const result = integerElem.asInteger();
console.info("result = " + result); // result = 42
```

### createBoolean

createBoolean(value: boolean): JsonElement

创建一个代表boolean值的JsonElement对象。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| value | boolean | 是 | 要存储的boolean值。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement。 |

**示例：**

```ts
const trueElem = jsonx.JsonElement.createBoolean(true);
const result = trueElem.asBoolean();
console.info("result = " + result); // result = true
```

### createNull

createNull(): JsonElement

创建一个代表Null值的JsonElement对象。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement。 |

**示例：**

```ts
const nullElem = jsonx.JsonElement.createNull();
const result = nullElem.jsonType;
console.info("result = " + result); // result = 7
```

### createUndefined

createUndefined(): JsonElement

创建一个代表undefined值的JsonElement对象。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement。 |

**示例：**

```ts
const undefinedElem = jsonx.JsonElement.createUndefined();
const result = undefinedElem.jsonType;
console.info("result = " + result); // result = 0
```

### createArray

createArray(elements: Array\<JsonElement\>): JsonElement

创建一个代表Array\<JsonElement\>值的JsonElement对象。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| elements | Array\<[JsonElement](#jsonelement)\> | 是 | 要存储的Array值。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement。 |

**示例：**

```ts
const arrayElements = [
    jsonx.JsonElement.createString("item1"),
    jsonx.JsonElement.createInteger(42),
    jsonx.JsonElement.createBoolean(true)
];
const arrayElem = jsonx.JsonElement.createArray(arrayElements);
const result = arrayElem.asArray()[0].asString();
console.info("result = " + result); // result = item1
```

### createObject

createObject(map: Map\<string, JsonElement\>): JsonElement

创建一个代表键值对对象的JsonElement对象。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| map | Map\<string, [JsonElement](#jsonelement)\> | 是 | 需要存储的键值对对象。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement。 |

**示例：**

```ts
const map = new Map\<string, jsonx.JsonElement\>();
map.set("name", jsonx.JsonElement.createString("John Doe"));
map.set("age", jsonx.JsonElement.createInteger(30));

const objectElem = jsonx.JsonElement.createObject(map);
const result = objectElem.getString("name");
console.info("result = " + result); // result = John Doe
```

### $_get

$_get(key: string): JsonElement

根据key获取JsonElement。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement。 |

**示例：**

```ts
const original = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
original.setElement("name", jsonx.JsonElement.createString("John"));
original.setElement("age", jsonx.JsonElement.createInteger(30));
const result = original["name"].asString();
console.info("result = " + result); // result = John
```

### getElement

getElement(key: string): JsonElement

根据key获取JsonElement。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement。 |

**示例：**

```ts
const original = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
original.setElement("name", jsonx.JsonElement.createString("John"));
original.setElement("age", jsonx.JsonElement.createInteger(30));
const result = original.getElement("name").asString();
console.info("result = " + result); // result = John
```

### tryGetElement

tryGetElement(key: string): JsonElement | undefined

尝试根据key获取JsonElement。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) \| undefined | 返回一个JsonElement，如果没找到返回undefined。 |

**示例：**

```ts
const original = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
original.setElement("name", jsonx.JsonElement.createString("John"));
original.setElement("age", jsonx.JsonElement.createInteger(30));
const nameString = original.tryGetElement("name");
const result = nameString?.asString();
console.info("result = " + result); // result = John
```

### $_iterator

$_iterator(): IterableIterator\<[string, JsonElement]\>

返回对象属性的迭代器。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| IterableIterator\<[string, [JsonElement](#jsonelement)]\> | 对象属性的迭代器。 |

**示例：**

```ts
let propertyCount = 0;
const original = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
original.setElement("name", jsonx.JsonElement.createString("John"));
original.setElement("age", jsonx.JsonElement.createInteger(30));
let it = original.$_iterator();
while(true) {
    const v = it.next();
    if (v.done) {
        break;
    }
    const key = v.value![0];
    console.info("key = " + key);
    // key = name
    // key = age
    propertyCount++;
}
```

### getArray

getArray(key: string): Array\<JsonElement\>

通过key获取JsonElement数组。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| Array\<[JsonElement](#jsonelement)\> | 返回一个JsonElement类型的数组。 |

**示例：**

```ts
const userElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
const tagsArray = [
    jsonx.JsonElement.createString("developer"),
    jsonx.JsonElement.createString("javascript"),
    jsonx.JsonElement.createString("typescript")
];
userElem.setElement("tags", jsonx.JsonElement.createArray(tagsArray));
const tags = userElem.getArray("tags");
const result = tags[0].asString();
console.info("result = " + result); // result = developer
```

### tryGetArray

tryGetArray(key: string): Array\<JsonElement\>

尝试通过key获取JsonElement数组。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| Array\<[JsonElement](#jsonelement)\> | 返回一个JsonElement类型的数组。 |

**示例：**

```ts
const userElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
const tagsArray = [
    jsonx.JsonElement.createString("developer"),
    jsonx.JsonElement.createString("javascript"),
    jsonx.JsonElement.createString("typescript")
];
userElem.setElement("tags", jsonx.JsonElement.createArray(tagsArray));
const tags = userElem.tryGetArray("tags");
const result = tags[0]?.asString();
console.info("result = " + result); // result = developer
```

### removeElement

removeElement(key: string): boolean

通过key删除JsonElement。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| boolean | 返回是否删除成功，true表示删除成功，false表示删除失败。 |

**示例：**

```ts
const objectElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
objectElem.setElement("name", jsonx.JsonElement.createString("John Doe"));
objectElem.setElement("age", jsonx.JsonElement.createInteger(30));
objectElem.setElement("isActive", jsonx.JsonElement.createBoolean(true));
const result = objectElem.removeElement("age");
console.info("result = " + result); // result = true
```

### setElement

setElement(key: string, value: JsonElement)

通过key设置JsonElement。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要设置的key。 |
| value | [JsonElement](#jsonelement) | 是 | 要设置的JsonElement。 | 

**示例：**

```ts
const objectElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
objectElem.setElement("name", jsonx.JsonElement.createString("John Doe"));
objectElem.setElement("age", jsonx.JsonElement.createInteger(30));
objectElem.setElement("isActive", jsonx.JsonElement.createBoolean(true));
objectElem.setElement("age", jsonx.JsonElement.createInteger(31));
const result = objectElem.getInteger("age");
console.info("result = " + result); // result = 31
```

### getDouble

getDouble(key: string): double

通过key获取double值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| double | 返回找到的double值。 |

**示例：**

```ts
const objectElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
objectElem.setElement("name", jsonx.JsonElement.createString("John Doe"));
objectElem.setElement("age", jsonx.JsonElement.createInteger(30));
objectElem.setElement("isActive", jsonx.JsonElement.createBoolean(true));
objectElem.setElement("height", jsonx.JsonElement.createDouble(1.85));
const result = objectElem.getDouble("height");
console.info("result = " + result); // result = 1.85
```

### tryGetDouble

tryGetDouble(key: string, fallback?: double): double | undefined

尝试通过key获取double值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |
| fallback | double | 否 | 如果key没有找到时，返回该值。<br>默认值为undefined。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| double \| undefined | 返回找到的double值，如果没找到则返回undefined。 |

**示例：**

```ts
const objectElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
objectElem.setElement("name", jsonx.JsonElement.createString("John Doe"));
objectElem.setElement("age", jsonx.JsonElement.createInteger(30));
objectElem.setElement("isActive", jsonx.JsonElement.createBoolean(true));
objectElem.setElement("height", jsonx.JsonElement.createDouble(1.85));
const result = objectElem.tryGetDouble("height");
console.info("result = " + result); // result = 1.85
```

### getInteger

getInteger(key: string): int

通过key获取int值。
**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| int | 返回找到的int值。 |

**示例：**

```ts
const objectElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
objectElem.setElement("name", jsonx.JsonElement.createString("John Doe"));
objectElem.setElement("age", jsonx.JsonElement.createInteger(30));
objectElem.setElement("isActive", jsonx.JsonElement.createBoolean(true));
objectElem.setElement("height", jsonx.JsonElement.createDouble(1.85));
const result = objectElem.getInteger("age");
console.info("result = " + result); // result = 30
```

### tryGetInteger

tryGetInteger(key: string, fallback: int = 0): int

尝试通过key获取int值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |
| fallback | int | 否 | 如果key没找到时，返回的该值默认为0。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| int | 返回找到的int值。 |

**示例：**

```ts
const objectElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
objectElem.setElement("name", jsonx.JsonElement.createString("John Doe"));
objectElem.setElement("age", jsonx.JsonElement.createInteger(30));
objectElem.setElement("isActive", jsonx.JsonElement.createBoolean(true));
objectElem.setElement("height", jsonx.JsonElement.createDouble(1.85));
const result = objectElem.tryGetInteger("age");
console.info("result = " + result); // result = 30
```

### getString

getString(key: string): string

通过key获取string值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| string | 返回找到的string值。 |

**示例：**

```ts
const objectElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
objectElem.setElement("name", jsonx.JsonElement.createString("John Doe"));
objectElem.setElement("age", jsonx.JsonElement.createInteger(30));
objectElem.setElement("isActive", jsonx.JsonElement.createBoolean(true));
objectElem.setElement("height", jsonx.JsonElement.createDouble(1.85));
const result = objectElem.getString("name");
console.info("result = " + result); // result = John Doe
```

### tryGetString

tryGetString(key: string, fallback: string = ""): string

尝试通过key获取string值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |
| fallback | string | 否 | 如果key没有找到时，返回的该值默认为""。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| string | 找到的string值。 |

**示例：**

```ts
const objectElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
objectElem.setElement("name", jsonx.JsonElement.createString("John Doe"));
objectElem.setElement("age", jsonx.JsonElement.createInteger(30));
objectElem.setElement("isActive", jsonx.JsonElement.createBoolean(true));
objectElem.setElement("height", jsonx.JsonElement.createDouble(1.85));
const result = objectElem.tryGetString("name");
console.info("result = " + result); // result = John Doe
```

### getBoolean

getBoolean(key: string): boolean

通过key获取boolean值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| boolean | 找到的boolean值。 |

**示例：**

```ts
const objectElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
objectElem.setElement("name", jsonx.JsonElement.createString("John Doe"));
objectElem.setElement("age", jsonx.JsonElement.createInteger(30));
objectElem.setElement("isActive", jsonx.JsonElement.createBoolean(true));
objectElem.setElement("height", jsonx.JsonElement.createDouble(1.85));
const result = objectElem.getBoolean("isActive");
console.info("result = " + result); // result = true
```

### tryGetBoolean

tryGetBoolean(key: string, fallback: boolean = false): boolean

尝试通过key获取boolean值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| key | string | 是 | 要查找的key。 |
| fallback | boolean | 否 | 如果没找到key，返回该值默认为false。 |

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| boolean | 找到的boolean值。 |

**示例：**

```ts
const objectElem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
objectElem.setElement("name", jsonx.JsonElement.createString("John Doe"));
objectElem.setElement("age", jsonx.JsonElement.createInteger(30));
objectElem.setElement("isActive", jsonx.JsonElement.createBoolean(true));
objectElem.setElement("height", jsonx.JsonElement.createDouble(1.85));
const result = objectElem.tryGetBoolean("isActive");
console.info("result = " + result); // result = true
```

### asDouble

asDouble(): double

将JsonElement对象转换为double类型。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| double | 返回一个double值。 |

**示例：**

```ts
const doubleElem = jsonx.JsonElement.createDouble(3.14159);
const result = doubleElem.asDouble();
console.info("result = " + result); // result = 3.14159
```

### tryAsDouble

tryAsDouble(): double | undefined

尝试将JsonElement对象转换为double类型。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| double \| undefined | 返回一个double值，如果不能作为double值则返回undefined。 |

**示例：**

```ts
const stringElem = new jsonx.JsonElement();
stringElem.setString("Hello, world!");
const result = stringElem.tryAsBoolean();
console.info("result = " + result); // result = undefined
```

### asInteger

asInteger(): int

将JsonElement对象转换为int类型。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| int | 返回一个int值。 |

**示例：**

```ts
const integerElem = jsonx.JsonElement.createInteger(42);
const result = integerElem.asInteger();
console.info("result = " + result); // result = 42
```

### tryAsInteger

tryAsInteger(): int | undefined

尝试将JsonElement对象转换为int类型。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| int \| undefined | 返回一个int值，如果不能作为int值则返回undefined。 |

**示例：**

```ts
const stringElem = new jsonx.JsonElement();
stringElem.setString("Hello, world!");
const result = stringElem.tryAsInteger();
console.info("result = " + result); // result = undefined
```

### asString

asString(): string

将JsonElement对象转换为string类型。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| string | 返回一个string值。 |

**示例：**

```ts
const stringElem = jsonx.JsonElement.createString("Hello, Factory!");
const result = stringElem.asString();
console.info("result = " + result); // result = Hello, Factory!
```

### tryAsString

tryAsString(): string | undefined

尝试将JsonElement对象转换为string类型。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| string \| undefined | 返回一个string值，如果无法作为string值则返回undefined。 |

**示例：**

```ts
const stringElem = new jsonx.JsonElement();
stringElem.setString("Hello, world!");
const result = stringElem.tryAsString();
console.info("result = " + result); // result = Hello, world!
```

### asBoolean

asBoolean(): boolean

将JsonElement对象转换为boolean类型。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| boolean | 返回一个boolean值。 |

**示例：**

```ts
const trueElem = jsonx.JsonElement.createBoolean(true);
const result = trueElem.asBoolean();
console.info("result = " + result); // result = true
```

### tryAsBoolean

tryAsBoolean(): boolean | undefined

尝试将JsonElement对象转换为boolean类型。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| boolean \| undefined | 返回一个boolean值，如果无法作为boolean值则返回undefined。 |

**示例：**

```ts
const stringElem = new jsonx.JsonElement();
stringElem.setString("Hello, world!");
const result = stringElem.tryAsBoolean();
console.info("result = " + result); // result = undefined
```

### asArray

asArray(): Array\<JsonElement\>

将JsonElement对象转换为Array\<JsonElement\>类型。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| Array\<[JsonElement](#jsonelement)\> | 返回一个JsonElement类型的Array。 |

**示例：**

```ts
const arrayElements = [
    jsonx.JsonElement.createString("item1"),
    jsonx.JsonElement.createInteger(42),
    jsonx.JsonElement.createBoolean(true)
];
const arrayElem = jsonx.JsonElement.createArray(arrayElements);
const result = arrayElem.asArray()[0].asString();
console.info("result = " + result); // result = item1
```

### tryAsArray

tryAsArray(): Array\<JsonElement\> | undefined

尝试将JsonElement对象转换为Array\<JsonElement\>类型。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| Array\<[JsonElement](#jsonelement)\> \| undefined | 返回一个JsonElement类型的Array，如果无法作为Array则返回undefined。 |

**示例：**

```ts
const stringElem = new jsonx.JsonElement();
stringElem.setString("Hello, world!");
const result = stringElem.tryAsArray();
console.info("result = " + result); // result = undefined
```

### setDouble

setDouble(value: double): void

将当前JsonElement设置成double值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| value | double | 是 | 要设置的double值。 |

**示例：**

```ts
const elem = new jsonx.JsonElement();
elem.setDouble(3.14);
const result = elem.asDouble();
console.info("result = " + result); // result = 3.14
```

### setInteger

setInteger(value: int): void

将当前JsonElement设置成int值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| value | int | 是 | 要设置的int值。 |

**示例：**

```ts
const elem = new jsonx.JsonElement();
elem.setInteger(42);
const result = elem.asInteger();
console.info("result = " + result); // result = 42
```

### setString

setString(value: string): void

将当前JsonElement设置成string值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| value | string | 是 | 要设置的string值。 |

**示例：**

```ts
const elem = new jsonx.JsonElement();
elem.setString("Hello");
const result = elem.asString();
console.info("result = " + result); // result = Hello
```

### setBoolean

setBoolean(value: boolean): void

将当前JsonElement设置成boolean值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| value | boolean| 是 | 要设置的boolean值。 |

**示例：**

```ts
const elem = new jsonx.JsonElement();
elem.setBoolean(true);
const result = elem.asBoolean();
console.info("result = " + result); // result = true
```

### setArray

setArray(value: Array\<JsonElement\>): void

将当前JsonElement设置成Array值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| value | Array\<[JsonElement](#jsonelement)\> | 是 | 要设置的JsonElement类型的Array值。 |

**示例：**

```ts
const arrayElem = new jsonx.JsonElement();
const items = [
    jsonx.JsonElement.createString("item1"),
    jsonx.JsonElement.createInteger(42),
    jsonx.JsonElement.createBoolean(true)
];
arrayElem.setArray(items);

const arr = arrayElem.asArray();
console.info("length = " + arr.length); // length = 3
console.info("arr[0] = " + arr[0].asString()); // arr[0] = item1
console.info("arr[1] = " + arr[1].asInteger()); // arr[1] = 42
console.info("arr[2] = " + arr[2].asBoolean()); // arr[2] = true
```

### setNull

setNull(): void

将当前JsonElement设置成null。

**示例：**

```ts
const elem = new jsonx.JsonElement();
elem.setNull();
const result = elem.jsonType;
console.info("result = " + result); // result = 7
```

### setUndefined

setUndefined(): void

将当前JsonElement设置成undefined。

**示例：**

```ts
const elem = new jsonx.JsonElement();
elem.setUndefined();
const result = elem.jsonType;
console.info("result = " + result); // result = 0
```

## JsonElementSerializable

定义可从JSON反序列化的类型接口,实现该接口的类可从JsonElement进行转换。

### fromJson

fromJson(jsonElem: JsonElement)

从JsonElement反序列化对象。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ----- | ---- | ---- | ---- |
| jsonElem | [JsonElement](#jsonelement) | 是 | 要反序列化的源JsonElement。 |

**示例：**

```ts
class User implements jsonx.JsonElementSerializable {
    name: string = "";
    age: int = 0;

    fromJson(jsonElem: jsonx.JsonElement) {
        this.name = jsonElem.getElement("name").asString();
        this.age = jsonElem.getElement("age").asInteger();
    }
}

const original = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
original.setElement("name", jsonx.JsonElement.createString("John"));
original.setElement("age", jsonx.JsonElement.createInteger(30));
let user = new User();
user.fromJson(original);
console.info("name = " + user.name); // name = John
console.info("age = " + user.age); // age = 30
```

## JsonElementDeserializable

定义可序列化为JSON的类型接口，实现该接口的类可转换为JsonElement。

### toJson

toJson(): JsonElement

将对象序列化JsonElement。

**返回值：**

| 类型       | 说明               |
| ---------- | ------------------ |
| [JsonElement](#jsonelement) | 返回一个JsonElement类型。 |

**示例：**

```ts
class User implements jsonx.JsonElementDeserializable {
    name: string = "";
    age: int = 0;

    toJson(): jsonx.JsonElement {
        let elem = new jsonx.JsonElement({} as Record\<string, jsonx.JsonElement\>);
        elem.setElement("name", jsonx.JsonElement.createString(this.name));
        elem.setElement("age", jsonx.JsonElement.createInteger(this.age));
        return elem;
    }
}

let user = new User();
user.name = "John";
user.age = 30;
const elem = user.toJson();
console.info("age = " + elem.getElement("name").asString()); // age = 30
console.info("name = " + elem.getElement("age").asInteger()); // name = John
```