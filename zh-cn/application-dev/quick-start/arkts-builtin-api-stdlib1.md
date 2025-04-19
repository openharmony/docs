# StdLib1

## 变更梗概
- [Map](#map)
- [Set](#set)
- [String](#string)
- [Symbol](#symbol)
- [Object](#object)
- [Number](#number)

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
- [raw方法变更](#raw方法变更)
- [string-构造函数变更为invoke方法](#string-构造函数变更为invoke方法)

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
  let str = "hello";
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

#### raw方法变更
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
  N/A

**适配建议：** 
  使用普通字符串替代。

#### string-构造函数变更为invoke方法
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
- [getOwnPropertyNames方法变更](#getownpropertynames方法变更)
- [Object-构造函数变更](#object-构造函数变更)
- [Object-valueOf变更](#object-valueof变更)
- [ObjectConstructor无参调用变更](#objectconstructor无参调用变更)
- [ObjectConstructor带参调用变更](#objectconstructor带参调用变更)

### 变更详情

#### getOwnPropertyNames方法变更
- ArkTS1.1 版本签名：  
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

- ArkTS1.2 版本签名:  
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
  N/A

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
  N/A

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
  N/A
 
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
