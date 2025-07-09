# StdLib1

## 变更梗概
- [Map](#map)
- [WeakMap](#weakmap)
- [Set](#set)
- [String](#string)
- [Symbol](#symbol)
- [Object](#object)
- [Number](#number)
- [JSON](#json)
- [ALL](#all)
- [Date](#date)

## Map
### 变更梗概
- [Map-Symbol.iterator变更](#map-symboliterator变更)
- [Map-forEach方法签名变更](#map-foreach方法签名变更)

### 变更详情

#### Map-Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<[K, V]>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<[K, V]\> | Map的迭代器。 |

**示例：**  
  ```typescript
  let m: Map<string, string> = new Map<string, string>();
  let iter = Reflect.get(m, Symbol.iterator);
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<[K, V]>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<[K, V]\> | Map的迭代器。 |

**示例：**  
  ```typescript
  const m: Map<string, string> = new Map<string, string>();
  let iter = m.$_iterator();
  ```

**适配建议：** 
  建议仅使用for...of访问迭代器。


#### Map-forEach方法签名变更
**ArkTS1.1版本签名：**  
  `forEach(callbackfn: (value: V, key: K, map: Map<K, V>) => void, thisArg?: any): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 遍历函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认值为undefined。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | V | 是 | 当前遍历的键值对中的值。 |
  | key | K | 是 | 当前遍历的键值对中的键。 |
  | map | Map\<K, V\> | 是 | 调用的原始数组。 |


**示例：**  
  ```typescript
  const m: Map<string, string> = new Map<string, string>();
  class Ctx {
    log(key: string, value: string) {
      console.info(key, value);
    }
  }
  m.forEach((value: string, key: string, map: Map<string, string>) => {
    this.log(key, value); // this无法在独立函数中使用
  }, new Ctx());
  ```

**ArkTS1.2版本签名：**  
  `forEach(callbackfn: (value: V, key: K, map: Map<K, V>) => void): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 遍历函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | V | 是 | 当前遍历的键值对中的值。 |
  | key | K | 是 | 当前遍历的键值对中的键。 |
  | map | Map\<K, V\> | 是 | 调用的原始Map。 |


**示例：**  
  ```typescript
  const m: Map<string, string> = new Map<string, string>();
  m.forEach((value: string, key: string, map: Map<string, string>) => {
    console.info("value=", value, "key=", key);
  });
  ```

**适配建议：** 
  使用闭包替代thisArg参数。

## WeakMap
- 参数类型any变更为Object | null | undefined。
#### WeakMap构造签名变更
**ArkTS1.1版本签名：**  
  `constructor<K extends object = object, V = any>(entries?: readonly [K, V][] | null): WeakMap<K, V>`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | K | K extends object = object | 否 | 类型K必须继承自object类型，如果没有默认为object类型。|
  | V | any | 否 | 自定义泛型，默认为any类型。|
  | entries | readonly [K, V][] \| null | 否 | 由[K, V]元组组成的只读数组或者null，默认值为undefined。|

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | WeakMap\<K, V> | 一个键类型是K、值类型是V的WeakMap实例。 |

**示例：**
```typescript
  interface PrivateData {
      secret: string;
  }

  const privateData = new WeakMap<object, PrivateData>();

  class MyClass {
      constructor(secret: string) {
          privateData.set(this, { secret });
      }

      getSecret(): string {
          const data = privateData.get(this);
          return data ? data.secret : "no secret";
      }
  }
  const instance = new MyClass("my secret");
  console.log(instance.getSecret()); // "my secret"
```
**ArkTS1.2版本签名：**  
  `constructor<K extends object = object, V = Object | null | undefined>(entries?: readonly [K, V][] | null): WeakMap<K, V>`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | K | K extends object = object | 否 | 类型K必须继承自object类型，如果没有默认为object类型。|
  | V | Object \| null \| undefined | 否 | 自定义泛型，默认为联合类型。|
  | entries | readonly [K, V][] \| null | 否 | 由[K, V]元组组成的只读数组或者null，默认值为undefined。|

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | WeakMap\<K, V> | 一个键类型是K、值类型是V的WeakMap实例。 |

**示例：**
```typescript
  interface PrivateData {
      secret: string;
  }

  const privateData = new WeakMap<object, PrivateData>();

  class MyClass {
      constructor(secret: string) {
          privateData.set(this, { secret });
      }

      getSecret(): string {
          const data = privateData.get(this);
          return data ? data.secret : "no secret";
      }
  }
  const instance = new MyClass("my secret");
  console.log(instance.getSecret()); // "my secret"
```

**适配建议：** 
  ArkTS1.2相比ArkTS1.1接口签名有变更，但对开发者接口行为无变更。

## Set

### 变更梗概
- [Set-Symbol.iterator变更](#set-symboliterator变更)
- [Set-forEach方法签名变更](#set-foreach方法签名变更)

### 变更详情

#### Set-Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<T\> | Set的迭代器。 |

**示例：**  
  ```typescript
  let set = new Set<string>();
  Reflect.get(set, Symbol.iterator);
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<T\> | Set的迭代器。 |

**示例：**  
  ```typescript
  let set = new Set<string>();
  set.$_iterator();
  ```

**适配建议：** 
  使用for...of进行迭代。

#### Set-forEach方法签名变更
**ArkTS1.1版本签名：**  
  `forEach(callbackfn: (value: T, value2: T, set: Set<T>) => void, thisArg?: any): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 遍历函数。 |
  | thisArg | any | 否 | 执行上下文，默认值为undefined。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前遍历的键值对中的值。 |
  | value2 | T | 是 | 与value相同。 |
  | set | Set\<T\> | 是 | 调用的原始Set。 |

**示例：**  
  ```typescript
  class Counter {
    count(v: string) { this.total++; }
    total = 0;
  }
  let set = new Set(["a"]);
  set.forEach(new Counter().count, {total: 10});
  ```

**ArkTS1.2版本签名：**  
  `forEach(callbackfn: (value: T, value2: T, set: Set<T>) => void): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 遍历函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前遍历的键值对中的值。 |
  | value2 | T | 是 | 与value相同。 |
  | set | Set\<T\> | 是 | 调用的原始Set。 |

**示例：**  
  ```typescript
  let set = new Set<string>(["a"]);
  let total = 0;
  set.forEach(() => {total++});
  ```

**适配建议：** 
  通过外部变量维护状态。

## String

### 变更梗概
- [String-Symbol.iterator变更](#string-symboliterator变更)
- [String-raw方法变更](#string-raw方法变更)
- [String-replace方法变更](#string-replace方法变更)
- [String-replaceAll方法变更](#string-replaceall方法变更)
- [String-构造函数变更为invoke方法](#string-构造函数变更为invoke方法)

### 变更详情

#### String-Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<string>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<string\> | 字符串迭代器。 |

**示例：**  
  ```typescript
  let str = new String("hello");
  Reflect.get(str, Symbol.iterator);
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<string>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<string\> | 字符串迭代器。 |

**示例：**  
  ```typescript
  let str = "hello";
  str.$_iterator();
  ```

**适配建议：** 
  使用for...of遍历字符串。

#### String-raw方法变更
**ArkTS1.1版本签名：**  
  `static raw(template: { raw: readonly string[] | ArrayLike<string>}, ...substitutions: any[]): string`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | template | { raw: readonly string[] \| ArrayLike\<string\> } | 是 | 模板对象。 |
  | substitutions | any[] | 否 | 替换值，默认值为null。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | string | 原始字符串。 |

**示例：**
  ```typescript
  let a = String.raw`a\nb\nc`;
  ```

**ArkTS1.2版本签名：**  
  ArkTs1.2 没有String.raw

**适配建议：** 
  使用普通字符串替代。

#### String-replace方法变更
- 参数类型any变更为Object。

**ArkTS1.1版本签名：**  
  `replace(searchValue: string | RegExp, replacer: (substring: string, ...args: any[]) => string): string`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | searchValue | string \| RegExp | 是 | 可以是字符串或者一个带有Symbol.replace方法的对象，如正则表达式。 |
  | replacer | (substring: string, ...args: any[]) => string | 是 | 一个函数，将为每个匹配调用该函数，并将其返回值用作替换文本。 |

replacer函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | substring | string | 是 | 匹配到的子字符串。 |
  | ...args | any[] | 是 | 如果searchValue是字符串，参数是第一个匹配项；如果searchValue是正则表达式且有捕获组，参数会是捕获组的内容。 |

replacer返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 用于替换的字符串。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 一个新的字符串。 |

**示例：**
```typescript**示例：**
```typescript
const str = "apple, orange, apple, banana";
const result = str.replaceAll("apple", "kiwi");

console.log(result); // "kiwi, orange, kiwi, banana"
```
const str = "apple, orange, apple, banana";
const result1 = str.replace("apple", "kiwi");
console.log(result1); // "kiwi, orange, apple, banana"

const result2 = str.replace(/apple/g, "kiwi");
console.log(result2); // "kiwi, orange, kiwi, banana"
```

**ArkTS1.2版本签名：**  
  `replace(searchValue: StringOrRegExp, replacer: (substr: String, args: Object[]) => String): String`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | searchValue | StringOrRegExp | 是 | 联合类型(string \| RegExp)，可以是字符串或者一个带有Symbol.replace方法的对象，如正则表达式。 |
  | replacer | (substr: String, args: Object[]) => String | 是 | 一个函数，将为每个匹配调用该函数，并将其返回值用作替换文本。 |

replacer函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | substr | String | 是 | 匹配到的子字符串。 |
  | args | Object[] | 是 | 如果searchValue是字符串，参数是第一个匹配项；如果searchValue是正则表达式且有捕获组，参数会是捕获组的内容。 |

replacer返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | String | 用于替换的字符串。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | String | 一个新的字符串。 |

**示例：**
```typescript
const str = "apple, orange, apple, banana";
const result1 = str.replace("apple", "kiwi");
console.log(result1); // "kiwi, orange, apple, banana"

const reg = new RegExp("apple","g")
const result2 = str.replace(reg, "kiwi");
console.log(result2); // "kiwi, orange, kiwi, banana"
```

**适配建议：** 
  ArkTS1.2相比ArkTS1.1接口签名有变更，但对开发者接口行为无变更。

#### String-replaceAll方法变更
- 参数类型any变更为Object。

**ArkTS1.1版本签名：**  
  `replaceAll(searchValue: string | RegExp, replacer: (substring: string, ...args: any[]) => string): string`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | searchValue | string \| RegExp | 是 | 可以是字符串或者一个带有Symbol.replace方法的对象，如正则表达式。 |
  | replacer | (substring: string, ...args: any[]) => string | 是 | 一个函数，将为每个匹配调用该函数，并将其返回值用作替换文本。 |

replacer函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | substring | string | 是 | 匹配到的子字符串。 |
  | ...args | any[] | 是 | 如果searchValue是字符串，参数是第一个匹配项；如果searchValue是正则表达式且有捕获组，参数会是捕获组的内容。 |

replacer返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 用于替换的字符串。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 一个新的字符串。 |

**示例：**
```typescript
const str = "apple, orange, apple, banana";
const result = str.replaceAll("apple", "kiwi");

console.log(result); // "kiwi, orange, kiwi, banana"
```
**ArkTS1.2版本签名：**  
  `replaceAll(searchValue: StringOrRegExp, replacer: (substr: String, args: Object[]) => String): String`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | searchValue | StringOrRegExp | 是 | 联合类型(String \| RegExp)，可以是字符串或者一个带有Symbol.replace方法的对象，如正则表达式。 |
  | replacer | (substr: String, args: Object[]) => String | 是 | 一个函数，将为每个匹配调用该函数，并将其返回值用作替换文本。其中substring为匹配到的字符串，args为参数数组，取决于searchValue是否是正则表达式，以及正则是否包含捕获组。 |

replacer函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | substr | String | 是 | 匹配到的子字符串。 |
  | args | Object[] | 是 | 如果searchValue是字符串，参数是第一个匹配项；如果searchValue是正则表达式且有捕获组，参数会是捕获组的内容。 |

replacer返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | String | 用于替换的字符串。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | String | 一个新的字符串。 |

**示例：**
```typescript
const str = "apple, orange, apple, banana";
const result = str.replaceAll("apple", "kiwi");

console.log(result); // "kiwi, orange, kiwi, banana"
```

**适配建议：** 
  ArkTS1.2相比ArkTS1.1接口签名有变更，但对开发者接口行为无变更。

#### String-构造函数变更为invoke方法
**ArkTS1.1版本签名：**  
  `(value?: any): string`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | any | 否 | 任意类型值，默认值为空。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 字符串表示。 |

**示例：**  
  ```typescript
  function create(ctor: StringConstructor) {
    return ctor({});
  }
  ```

**ArkTS1.2版本签名：**  
  `static String.invoke(value?: Object | undefined | null): String`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | Object \| undefined \| null | 否 | 限定类型值，默认值为空。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | String | 字符串对象。 |

**示例：**  
  ```typescript
  String({}); // 需确保参数符合类型
  ```

**适配建议：** 
  不要使用Constructor类型，使用invoke或new的方式直接创建对象。

## Symbol

### 变更梗概
- [iterator符号属性移除](#iterator符号属性移除)

### 变更详情

#### iterator符号属性移除
**ArkTS1.1版本签名：**  
  `static readonly iterator: unique symbol`

**示例：**  
  ```typescript
  let a = Symbol.iterator;
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  使用字符串属性$_iterator访问迭代器。

## Object

### 变更梗概
- [Object-getOwnPropertyNames方法变更](#object-getownpropertynames方法变更)
- [Object-构造函数变更](#object-构造函数变更)
- [Object-entries变更](#object-entries变更)
- [Object-values变更](#object-values变更)
- [Object-valueOf变更](#object-valueof变更)
- [ObjectConstructor无参调用变更](#objectconstructor无参调用变更)
- [ObjectConstructor带参调用变更](#objectconstructor带参调用变更)

### 变更详情

#### Object-getOwnPropertyNames方法变更
**ArkTS1.1版本签名：**  
  `static getOwnPropertyNames(o: any): string[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `o` | `any` | 是 | 要获取属性名的对象。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `string[]` | 对象的属性名数组。 |

**示例：**  
  ```typescript
  class C {
    a: number = 1;
    b: number = 2;
  }
  const a = new C();
  Object.getOwnPropertyNames(a);
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  使用`Object.keys`代替。

#### Object-构造函数变更
**ArkTS1.1版本签名：**  
  `constructor(value?: any): Object`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | any | 否 | 任意类型的值，默认值为空。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Object | 对象实例。 |

**示例：**  
  ```typescript
  let obj = new Object({});
  ```

**ArkTS1.2版本签名：**  
  `constructor(): Object`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Object | 空对象实例。 |

**示例：**  
  ```typescript
  let obj = new Object();
  ```
 
**适配建议：** 
  使用具体类型替代泛型Object。

#### Object-entries变更
- 返回值any类型改为Object | null | undefined联合类型。

**ArkTS1.1版本签名：**  
  `static entries(o: {}): [string, any][]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | o | {} | 是 | 对象。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | [string, any][] | 一个由给定对象可枚举字符串键的键值对组成的数组，其中每个键值对都是一个包含两个元素的数组。 |

**示例：**  
  ```typescript
  interface obj {
    a: string,
    b: number,
  };
  const object1: obj = {
    a: "somestring",
    b: 42,
  };
  console.info(Object.entries(object1)[0][1]);
  ```

**ArkTS1.2版本签名：**  
  `static entries(o: Object): NullishEntryType[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | o | Obejct | 是 | 对象。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | NullishEntryType | 联合类型([string, Object \| null \| undefined] \| null \| undefined)。 |

**示例：**  
  ```typescript
  interface obj {
    a: string,
    b: number,
  };
  const object1 : obj= {
    a: "somestring",
    b : 42,
  };
  console.info(Object.entries(object1)[0]?.[1]);
  ```

**适配建议：** 
  返回值类型由any改为联合类型NullishEntryType，使用时需判断。

#### Object-values变更
- 返回值any类型改为Object | null | undefined。

**ArkTS1.1版本签名：**  
  `static values(o: {}): any[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | o | {} | 是 | 对象。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | any[] | 新数组。 |

**示例：**  
  ```typescript
  interface obj {
    a: string,
  };
  const object1: obj = {
    a: "somestring",
  };
  console.info(Object.values(object1)[0].toUpperCase());
  ```

**ArkTS1.2版本签名：**  
  `static values(o: Object): (Object | null | undefined)[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | o | Object | 是 | 对象。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | (Object \| null \| undefined)[] | 新数组。 |

**示例：**  
  ```typescript
  interface obj {
    a: string,
  }
  const object1: obj = {
    a: "somestring",
  }
  let value1 = Object.values(object1);
  let value2 = value1[0] as string;
  console.info("values :" + value2.toUpperCase());
  ```

**适配建议：** 
  ArkTS1.2版本any类型变为(Object | null | undefined)，使用需指定类型。

#### Object-valueOf变更
**ArkTS1.1版本签名：**  
  `valueOf(): Object`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Object | 对象本身。 |

**示例：**  
  ```typescript
  let obj = new Object();
  obj.valueOf();
  ```

**ArkTS1.2版本签名：**  
  ArkTs1.2 没有valueOf()接口

**适配建议：** 
  直接使用对象本身，不需要调用valueOf。

#### ObjectConstructor无参调用变更
**ArkTS1.1版本签名：**  
  `(): any`

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | any | 返回空对象。 |

**示例：**
  ```typescript
  let a: Object = Object();
  ```

**ArkTS1.2版本签名：**  
  ArkTs1.2 不支持泛型Object

**适配建议：** 
  使用具体类型替代泛型Object。


#### ObjectConstructor带参调用变更
**ArkTS1.1版本签名：**  
  `(value: any): any`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | value | any | 否 | 任意类型值，默认值为空。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | any | 返回包装后的对象。 |

**示例：**
  ```typescript
  let a: Object = Object({});
  ```

**ArkTS1.2版本签名：**  
  ArkTs1.2 不支持泛型Object
 
**适配建议：** 
  使用具体类型替代泛型Object。

## Number

### 变更梗概
- [Number-构造函数变更](#number-构造函数变更)
- [Number-isFinite方法变更](#number-isfinite方法变更)
- [Number-isInteger方法变更](#number-isinteger方法变更) 
- [Number-isNaN方法变更](#number-isnan方法变更)
- [Number-isSafeInteger方法变更](#number-issafeinteger方法变更)
- [Number-调用签名变更为invoke方法](#number-调用签名变更为invoke方法)

### 变更详情

#### Number-构造函数变更
**ArkTS1.1版本签名：**  
  `constructor(value?: any): Number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | value | any | 否 | 任意类型值，默认值为0。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | Number | 数字包装对象。 |

**示例：**  
  ```typescript
  let num = new Number(true);
  ```

**ArkTS1.2版本签名：**  
  `constructor(value?: String|Number|BigInt): Number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | value | String \| Number \| BigInt | 否 | 可转换为数字的值，默认值为0。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | Number | 数字包装对象。 |

**示例：**  
  ```typescript
  let num = new Number(10);
  ```
 
**适配建议：** 
  仅使用String、Number或BigInt类型创建Number对象。

#### Number-isFinite方法变更
**ArkTS1.1版本签名：**  
  `static isFinite(number: unknown): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | number | unknown | 是 | 待检测的值。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示是否为有限数，true表示是有限数，false表示不是有限数。 |

**示例：**  
  ```typescript
  Number.isFinite(true);
  ```

**ArkTS1.2版本签名：**  
  `static isFinite(n: number): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | n | number | 是 | 待检测的数字 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示是否为有限数，true表示是有限数，false表示不是有限数。 |

**示例：**  
  ```typescript
  Number.isFinite(1);
  ```
 
**适配建议：** 
  只对数字类型使用isFinite检查。

#### Number-isInteger方法变更
**ArkTS1.1版本签名：**  
  `static isInteger(number: unknown): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | number | unknown | 是 | 待检测的值。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示是否为整数，true表示是整数，false表示不是整数。 |

**示例：**  
  ```typescript
  Number.isInteger(true);
  ```

**ArkTS1.2版本签名：**  
  `static isInteger(n: number): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | n | number | 是 | 待检测的数字。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示是否为整数，true表示是整数，false表示不是整数。 |

**示例：**  
  ```typescript
  Number.isInteger(1);
  ```
 
**适配建议：** 
  只对数字类型使用isInteger检查。

#### Number-isNaN方法变更
**ArkTS1.1版本签名：**  
  `static isNaN(number: unknown): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | number | unknown | 是 | 待检测的值。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示是否为NaN，true表示是，false表示不是NaN。 |

**示例：**  
  ```typescript
  Number.isNaN(true);
  ```

**ArkTS1.2版本签名：**  
  `static isNaN(number: number): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | number | number | 是 | 待检测的数字。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示是否为NaN，true表示是，false表示不是NaN。 |

**示例：**  
  ```typescript
  Number.isNaN(1);
  ```
 
**适配建议：** 
  只对数字类型使用isNaN检查。

#### Number-isSafeInteger方法变更
**ArkTS1.1版本签名：**  
  `static isSafeInteger(number: unknown): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | number | unknown | 是 | 待检测的值。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示是否为安全整数，true表示是，false表示不是安全整数。 |

**示例：**  
  ```typescript
  Number.isSafeInteger(true);
  ```

**ArkTS1.2版本签名：**  
  `static isSafeInteger(n: number): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | n | number | 是 | 待检测的数字。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示是否为安全整数，true表示是安全整数，false表示不是安全整数。 |

**示例：**  
  ```typescript
  Number.isSafeInteger(1);
  ```
 
**适配建议：** 
  只对数字类型使用isSafeInteger检查。

#### Number-调用签名变更为invoke方法
**ArkTS1.1版本签名：**  
  `(value?: any): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | any | 否 | 任意类型值，默认值为0。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 转换后的数字。 |

**示例：**  
  ```typescript
  console.info(Number(undefined));
  ```

**ArkTS1.2版本签名：**  
  `static Number.invoke(value?: String|Number|BigInt): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | String \| Number \| BigInt | 否 | 限定类型的值，默认值为0。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 转换后的数字。 |

**示例：**  
  ```typescript
  console.info(Number(0)); //0
  ```

**适配建议：** 
  仅使用String/Number/BigInt类型作为参数。

## JSON
### 变更梗概
- [JSON-parse签名变更](#json-parse签名变更)
- [JSON-stringify签名变更](#json-stringify签名变更)

## JSON-parse签名变更
### 变更梗概
- [JSON-parse未传入可选参数reviver](#json-parse未传入可选参数reviver)
- [JSON-parse传入可选参数reviver](#json-parse传入可选参数reviver)

### 变更详情

#### JSON-parse未传入可选参数reviver
**ArkTS1.1版本签名：**  
  `parse(text: string, reviver?: (this: any, key: string, value: any) => any, options?: ParseOptions): Object|null`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | text | string | 是 | JSON字符串。 |
  | reviver | (this: any, key: string, value: any) => any | 否 | reviver函数用以在返回之前对所得到的对象执行变换。 |
  | options | ParseOptions | 否 | 解析的配置，传入该参数，可以用来控制解析生成的类型。默认是undefined。 |

reviver函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | this | any | 是 | reviver函数执行时的上下文对象。 |
  | key | string | 是 | 正在处理的this对象属性的键名。 |
  | value | any | 是 | 当前键对应的值。 |

reviver函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | any | 如果返回undefined，该对象属性会从结果中删除；如果返回非undefined，该返回值会替换原始解析值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Object \| null | 反序列化后的对象。 |

**示例：**  
  ```typescript
  class C {
    a:number = 1;
    b:number = 2;
  }
  const c = new C();
  let json: C = JSON.parse("{\"a\":1, \"b\":2}") as C;
  ```

**ArkTS1.2版本签名：**  
  `parse<T>(text: String, type: Type): T | null | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | text | String | 是 | JSON字符串。 |
  | type | Type | 是 | 要转换JSON字符串的类型。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T \| null \| undefined | 反序列化后的对象。 |

**示例：**  
  ```typescript
  class C {
    a:number = 1;
    b:number = 2;
  }
  const c = new C();
  let json = JSON.parse<C>("{\"a\":1, \"b\":2}", Type.of(c));
  console.info(json);
  ```

**适配建议：** 
  需要提供泛型T和入参type。

#### JSON-parse传入可选参数reviver
**ArkTS1.1版本签名：**  
  `parse(text: string, reviver?: (this: any, key: string, value: any) => any, options?: ParseOptions): Object|null`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | text | string | 是 | JSON字符串。 |
  | reviver | (this: any, key: string, value: any) => any | 否 | reviver函数用以在返回之前对所得到的对象执行变换。默认值为无。 |
  | options | ParseOptions | 否 | 解析的配置，传入该参数，可以用来控制解析生成的类型。默认是undefined。 |

reviver函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | this | any | 是 | reviver函数执行时的上下文对象。 |
  | key | string | 是 | 正在处理的this对象属性的键名。 |
  | value | any | 是 | 当前键对应的值。 |

reviver函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | any | 如果返回undefined，该对象属性会从结果中删除；如果返回非undefined，该返回值会替换原始解析值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Object \| null | 反序列化后的对象。 |

**示例：**  
  ```typescript
  class C {
    a: number = 2;
  }
  
  const c = new C();
  let json: C = JSON.parse('{"a": 2}', (k: string, v: number) => {
    if (k === "") {
      return v;
    }
    return v * 2;
  })
  console.info(JSON.stringify(json));
  ```

**ArkTS1.2版本签名：**  
  `parse<T>(text: string, reviver: ((key: string, value: (Object | null | undefined)) => (Object | null | undefined)) | undefined, type: Type, bigIntMode?: int): T | null | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | text | string | 是 | JSON字符串。 |
  | reviver | ((key: string, value: (Object \| null \| undefined)) => (Object \| null \| undefined)) \| undefined | 否 | reviver函数用以在返回之前对所得到的对象执行变换。默认值为无。 |
  | type | Type | 是 | 要转换JSON字符串的类型。 |
  | bigIntMode | int | 否 | 是否包含bigint（任意精度的大整数），选择开启。默认值为无。 |

reviver函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 正在处理的this对象属性的键名。 |
  | value | Object \| null \| undefined | 是 | 当前键对应的值。 |

reviver函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | Object \| null \| undefined | 如果返回undefined，该对象属性会从结果中删除；如果返回非undefined，该返回值会替换原始解析值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T \| null \| undefined | 反序列化后的对象。 |

**示例：**  
  ```typescript
  class C {
  a: number = 2;
  }
  
  const c = new C();
  let json: C|undefined|null = JSON.parse<C>('{"a": 2}', (k: string, v: Object|null|undefined ) => {
    if (k === "") {
      return v;
    }
    return (v as number) * 2;
  }, Type.of(c))
  
  console.info(JSON.stringify(json));
  ```

**适配建议：** 
  ArkTS1.1的JSON.parse返回一个any对象，该any对象可以为任何值，但ArkTS1.2无法生成一个any对象，并向里面动态添加属性。

## JSON-stringify签名变更
### 变更梗概
- [JSON-stringify入参为replacer数组any类型变更](#json-stringify入参为replacer数组any类型变更)
- [JSON-stringify入参为replacer函数any类型变更](#json-stringify入参为replacer函数any类型变更)

### 变更详情

#### JSON-stringify入参为replacer数组any类型变更
- 参数类型any变更为Object | null | undefined。

**ArkTS1.1版本签名：**  
  `stringify(value: any, replacer?: (number | string)[] | null, space?: string | number): string`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | any | 是 | 任意类型。 |
  | replacer | (number \| string)[] \| null | 否 | 只有包含在这个数组中的属性名才会被序列化到最终的JSON字符串中。默认值为无。 |
  | space | string \| number | 否 | 指定缩进用的空白字符串。默认值为无。 |


**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string | JSON字符串。 |

**ArkTS1.2版本签名：**  
  `stringify(obj: Object | null | undefined, replacer: Array<string | number>, space?: string | number): string`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | obj | Object \| null \| undefined | 是 | 联合类型。 |
  | replacer | Array\<string \| number\> | 是 | 只有包含在此数组中的属性名才会被序列化到最终的JSON字符串中。 |
  | space | string \| number | 否 | 指定缩进用的空白字符串。默认值为无。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string | JSON字符串。 |

**适配建议：** 
  ArkTS1.2相比ArkTS1.1接口签名有变更，但对开发者接口行为无变更。

#### JSON-stringify入参为replacer函数any类型变更
**ArkTS1.1版本签名：**  
  `stringify(value: any, replacer?: (this: any, key: string, value: any) => any, space?: string | number): string`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | any | 是 | 任意类型。 |
  | replacer | (this: any, key: string, value: any) => any | 否 | 在序列化过程中，被序列化的值的每个属性都会经过该函数的转换和处理。默认值为无。 |
  | space | string \| number | 否 | 指定缩进用的空白字符串。默认值为无。 |

replacer函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | this | any | 是 | replacer函数执行时的上下文对象。 |
  | key | string | 是 | 正在处理的this对象属性的键名。 |
  | value | any | 是 | 当前键对应的值。 |

replacer函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | any | 如果返回undefined，该对象属性会从结果中删除；如果返回非undefined，按返回值序列化。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string | JSON字符串。 |

**示例：**  
  ```typescript
  class A {
  username: string = "zzz"

  aaa(): void {
    this.username = "www"
  }
  }
  
  interface useritf {
    name: string,
    password: string,
    lastLogin: A
  }
  
  const user: useritf = {
    name: "李四",
    password: "secret123", // 无需序列化密码
    lastLogin: new A()
  };
  
  const filteredJson = JSON.stringify(user, (key: string, value: Object) => {
    if (key === "password") {
      return undefined;
    } // 移除密码字段
    if (key === "lastLogin") {
      (value as A).aaa()
      return value;
    } // 修改username
    return value;
  });

  console.info(filteredJson);
  ```

**ArkTS1.2版本签名：**  
  `stringify(obj: Object | null | undefined, replacer: ((key: string, value: Object | null | undefined) => Object | null | undefined) | undefined | null, space?: string | number): string`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | obj | Object \| null \| undefined | 是 | 要序列化的值。 |
  | replacer | ((key: string, value: Object \| null \|undefined) => Object \| null \| undefined) \| undefined \| null | 是 | 在序列化过程中，被序列化的值的每个属性都会经过该函数的转换和处理。 |
  | space | string \| number | 否 | 指定缩进用的空白字符串。默认值为无。 |

replacer函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | string | 是 | 正在处理的当前上下午对象属性的键名。 |
  | value | Object \| null \| undefined | 是 | 当前键对应的值。 |

replacer函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | Object \| null \| undefined | 如果返回undefined，该对象属性会从结果中删除；如果返回非undefined，按返回值序列化。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string | JSON字符串。 |

**示例：**  
  ```typescript
  class A {
  username: string = "zzz"

  aaa():void {
    this.username = "www"
  }
  }
  
  interface useritf {
    name: string,
    password: string,
    lastLogin: A
  }
  
  const user: useritf = {
    name: "李四",
    password: "secret123", // 无需序列化密码
    lastLogin: new A()
  };
  
  const filteredJson = JSON.stringify(user, (key: string, value: Object|null|undefined) => {
    if (key === "password") {
      return undefined;
    } // 移除密码字段
    if (key === "lastLogin") {
      (value as A).aaa()
      return value;
    } // 修改username
    return value;
  });
  
  console.info(filteredJson);
  ```

**适配建议：** 
  ArkTS1.2相比较于ArkTS1.1，类型any转为Object|null|undefined，在使用时需要先判断。

## ALL
### 变更详情

#### ArkTS1.2部分builtin class标注final，无法被继承使用。
**ArkTS1.1版本签名：**  
  `class xxx`

**示例：**  
  ```typescript
  class MyIntArray extends Int8Array {
  constructor(length: number) {
    super(length);
  }
  }
  
  try {
    const myArray = new MyIntArray(3);
  
    console.info('length = ' + myArray.length);
  } catch (error) {
    console.error('错误:', error);
  }
  ```

**ArkTS1.2版本签名：**  
  `final class xxx`

**示例：**  
  ```typescript
  class MyIntArray extends Int8Array { // 报错：TypeError: Cannot inherit with 'final' modifier. 
  constructor(length: number) {
    super(length);
  }
  }
  
  try {
    const myArray = new MyIntArray(3);
  
    console.info('length = ' + myArray.length);
  } catch (error) {
    console.error('错误:', error);
  }
  ```

## Date
### 变更详情

#### Date-toJSON方法变更
**ArkTS1.1版本签名：**  
  `toJSON(key?: any): string`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | any | 否 | 表示当前序列化对象属性名。默认值为无。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string | Date对象的字符串形式。 |

**示例：**  
  ```typescript
  const event = new Date("August 19, 1975 23:15:30 UTC");
  const jsonDate = event.toJSON();
  console.info("length :" + jsonDate.length);
  ```

**ArkTS1.2版本签名：**  
  `toJSON(): string|null`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string \| null | Date对象的字符串形式，可以为null。 |

**示例：**  
  ```typescript
  const event = new Date("August 19, 1975 23:15:30 UTC");
  const jsonDate = event.toJSON();
  console.info(jsonDate?.length);
  ```

**适配建议：** 
  toJSON接口变更，当date构造入参为空字符串时，toJSON返回null，返回值后续调用方法或属性时需要使用判空或使用?.访问。