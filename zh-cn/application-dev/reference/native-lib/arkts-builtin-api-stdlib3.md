# StdLib3

## 变更梗概
- [PropertyDescriptor](#propertydescriptor)
- [Reflect](#reflect)
- [RegExpExecArray](#regexpexecarray)
- [RegExpMatchArray](#regexpmatcharray)
- [TypedPropertyDescriptor](#typedpropertydescriptor)
- [TemplateStringsArray](#templatestringsarray)

## PropertyDescriptor

### 变更梗概
- [configurable属性移除](#configurable属性移除)
- [enumerable属性移除](#enumerable属性移除)
- [value属性移除](#value属性移除)
- [writable属性移除](#writable属性移除)
- [get方法移除](#get方法移除)
- [set方法移除](#set方法移除)

### 变更详情

#### configurable属性移除
**ArkTS1.1版本签名：**  
  `configurable?: boolean`

**示例：**  
ArkTs1.1 限制使用标准库, 会有告警提示
  ```typescript
  Object.defineProperty(obj, "prop", { configurable: true }); // Usage of standard library is restricetd (arkts-limited-stdlib) <ArkTsCheck>
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  建议通过调整或创建新的类来达成效果。

#### enumerable属性移除
**ArkTS1.1版本签名：**  
  `enumerable?: boolean`

**示例：**  
ArkTs1.1 限制使用标准库, 会有告警提示
  ```typescript
  Object.defineProperty(obj, "prop", { enumerable: false }); // Usage of standard library is restricetd (arkts-limited-stdlib) <ArkTsCheck>
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  建议通过调整或创建新的类来达成效果。

#### value属性移除
**ArkTS1.1版本签名：**  
  `value?: any`

**示例：**  
ArkTs1.1 限制使用标准库, 会有告警提示
  ```typescript
  Object.defineProperty(obj, "prop", { value: 1 }); // Usage of standard library is restricetd (arkts-limited-stdlib) <ArkTsCheck>
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  建议通过调整或创建新的类来达成效果。

#### writable属性移除
**ArkTS1.1版本签名：**  
  `writable?: boolean`

**示例：**  
ArkTs1.1 限制使用标准库, 会有告警提示
  ```typescript
  Object.defineProperty(obj, "prop", { writable: false }); // Usage of standard library is restricetd (arkts-limited-stdlib) <ArkTsCheck>
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  建议通过调整或创建新的类来达成效果。

#### get方法移除
**ArkTS1.1版本签名：**  
  `get?(): any`

**示例：**  
ArkTs1.1 限制使用标准库, 会有告警提示
  ```typescript
  Object.defineProperty(obj, "prop", { 
    get() { return this._value; }
  }); // Usage of standard library is restricetd (arkts-limited-stdlib) <ArkTsCheck>
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  建议通过调整或创建新的类来达成效果。

#### set方法移除
**ArkTS1.1版本签名：**  
  `set?(v: any): void`

**示例：**  
ArkTs1.1 限制使用标准库, 会有告警提示
  ```typescript
  Object.defineProperty(obj, "prop", {
    set(v) { this._value = v; }
  }); // Usage of standard library is restricetd (arkts-limited-stdlib) <ArkTsCheck>
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  建议通过调整或创建新的类来达成效果。

## RegExpExecArray

### 变更梗概
- [RegExpExecArray-groups类型变更](#regexpexecarray-groups类型变更)

### 变更详情

#### RegExpExecArray-groups类型变更
**ArkTS1.1版本签名：**  
  `groups?: { [key: string]: string }`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | { [key: string]: string } | 匹配结果的集合。 |

**示例：**  
  ```typescript
  const text = '2025-01-01';
  const regex = /(?<year>\d{4})-(?<month>\d{2})-(?<day>\d{2})/;
  const match = regex.exec(text);
  console.info(match!.groups!.year)
  ```

**ArkTS1.2版本签名：**  
  `groups?: Record<string, string>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Record\<string, string\> | 命名捕获组。 |

**示例：**  
  ```typescript
  const text = '2025-01-01';
  const regex = new RegExp(`(?<year>....)-(?<month>..)-(?<day>..)`);
  const match = regex.exec(text);
  console.info(match!.groups)
  ```

**适配建议：** 
  使用字符串索引访问捕获组。

## RegExpMatchArray

### 变更梗概
- [RegExpMatchArray-groups类型变更](#regexpmatcharray-groups类型变更)

### 变更详情

#### RegExpMatchArray-groups类型变更
**ArkTS1.1版本签名：**  
  `groups?: { [key: string]: string }`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | { [key: string]: string } | 匹配结果的集合。 |

**示例：**  
  ```typescript
  const text = '2025-01-01';
  const regex = /(?<year>\d{4})-(?<month>\d{2})-(?<day>\d{2})/;
  const match = text.match(regex);
  console.info(match!.groups!.year);
  ```

**ArkTS1.2版本签名：**  
  `groups?: Record<string, string>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Record\<string, string\> | 命名捕获组。 |

**示例：**  
  ```typescript
  const text = '2025-01-01';
  const regex = new RegExp(`(?<year>....)-(?<month>..)-(?<day>..)`);
  const match = text.match(regex);
  console.info(match!.groups);
  ```

**适配建议：** 
  通过字符串键访问捕获组。

## TypedPropertyDescriptor

### 变更梗概
- [TypedPropertyDescriptor-configurable属性变更](#typedpropertydescriptor-configurable属性变更)
- [TypedPropertyDescriptor-enumerable属性变更](#typedpropertydescriptor-enumerable属性变更)
- [TypedPropertyDescriptor-get方法变更](#typedpropertydescriptor-get方法变更)
- [TypedPropertyDescriptor-set方法变更](#typedpropertydescriptor-set方法变更)
- [TypedPropertyDescriptor-value属性变更](#typedpropertydescriptor-value属性变更)
- [TypedPropertyDescriptor-writable属性变更](#typedpropertydescriptor-writable属性变更)

### 变更详情

#### TypedPropertyDescriptor-configurable属性变更
**ArkTS1.1版本签名：**  
  `configurable?: boolean`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否可配置，true表示是可配置，false表示不可配置。 |

**示例：**  
  ```typescript
  let desc: TypedPropertyDescriptor<number> = {
    configurable: false
  };
  ```

**ArkTS1.2版本签名：**  
  不支持。
 
**适配建议：** 
  静态语言不支持修改属性，因此建议通过调整或创建新的类来达成效果。

#### TypedPropertyDescriptor-enumerable属性变更
**ArkTS1.1版本签名：**  
  `enumerable?: boolean`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否可枚举，true表示是，false表示不可枚举。 |

**示例：**  
  ```typescript
  let desc: TypedPropertyDescriptor<number> = {
    enumerable: true
  };
  ```

**ArkTS1.2版本签名：**  
  不支持。
 
**适配建议：** 
  静态语言不支持修改属性，因此建议通过调整或创建新的类来达成效果。

#### TypedPropertyDescriptor-get方法变更
**ArkTS1.1版本签名：**  
  `get?: () => T`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 属性值。 |

**示例：**  
  ```typescript
  let desc: TypedPropertyDescriptor<number> = {
    get(): number { return this.value; }
  };
  ```

**ArkTS1.2版本签名：**  
  不支持。
 
**适配建议：** 
  静态语言不支持修改属性，因此建议通过调整或创建新的类来达成效果。

#### TypedPropertyDescriptor-set方法变更
**ArkTS1.1版本签名：**  
  `set?: (value: T) => void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 要设置的值。 |

**示例：**  
  ```typescript
  let desc: TypedPropertyDescriptor<number> = {
    set(v: number) { this.value = v; }
  };
  ```

**ArkTS1.2版本签名：**  
  不支持。
 
**适配建议：** 
  静态语言不支持修改属性，因此建议通过调整或创建新的类来达成效果。

#### TypedPropertyDescriptor-value属性变更
**ArkTS1.1版本签名：**  
  `value?: T`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 属性值 |

**示例：**  
  ```typescript
  let desc: TypedPropertyDescriptor<number> = {
    value: 1
  };
  ```

**ArkTS1.2版本签名：**  
  不支持。
 
**适配建议：** 
  静态语言不支持修改属性，因此建议通过调整或创建新的类来达成效果。

#### TypedPropertyDescriptor-writable属性变更
**ArkTS1.1版本签名：**  
  `writable?: boolean`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否可写，true表示是，false表示不可写。 |

**示例：**  
  ```typescript
  let desc: TypedPropertyDescriptor<number> = {
    writable: true
  };
  ```

**ArkTS1.2版本签名：**  
  不支持。
 
**适配建议：** 
  静态语言不支持修改属性，因此建议通过调整或创建新的类来达成效果。

## Reflect

### 变更梗概
- [Reflect-get方法变更](#reflect-get方法变更)
- [Reflect-has方法变更](#reflect-has方法变更)
- [Reflect-ownKeys方法变更](#reflect-ownkeys方法变更)
- [Reflect-set方法变更](#reflect-set方法变更)
- [Reflect-方法新增](#reflect-方法新增)

### 变更详情

#### Reflect-get方法变更
**ArkTS1.1版本签名：**  
  `function get<T extends object, P extends PropertyKey>(target: T, propertyKey: P, receiver?: unknown): P extends keyof T ? T[P] : any`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | target | T | 是 | 目标对象。 |
  | propertyKey | P | 是 | 属性键。 |
  | receiver | unknown | 否 | 接收器对象，默认值为undefined。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | P extends keyof T ? T[P] : any | 返回属性值。 |

**示例：**
  ```typescript
  class C {
    a: number = 1;
    get x() { return this.a; }
  }
  const instance = new C();
  Reflect.get<C, string>(instance, "x", instance); // 1
  ```

**ArkTS1.2版本签名：**  
  `function get(target: object, propertyKey: string): NullishType`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | target | object | 是 | 目标对象。 |
  | propertyKey | string | 是 | 属性键。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | NullishType | 返回属性值、null或undefined。 |

**示例：**
  ```typescript
  class C {
      a: number = 1;
  }
  let a = new C()
  Reflect.get(a, "a") // 1
  ```
 
**适配建议：** 
  不使用泛型参数，属性名只能是字符串，不支持receiver参数。

#### Reflect-has方法变更
**ArkTS1.1版本签名：**  
  `function has(target: object, propertyKey: PropertyKey): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | target | object | 是 | 目标对象。 |
  | propertyKey | PropertyKey | 是 | 属性键。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示是否包含属性，true表示是，false表示不包含属性。 |

**示例：**
  ```typescript
  let a = [1,2,3];
  Reflect.has(a, 0);
  ```

**ArkTS1.2版本签名：**  
  `function has(target: object, propertyKey: string): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | target | object | 是 | 目标对象。 |
  | propertyKey | string | 是 | 属性键。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示是否包含属性，true表示是，false表示不包含属性。 |

**示例：**
  ```typescript
  class C{
      a: number=1;
  }
  let a = new C()
  Reflect.has(a, "a")
  ```
 
**适配建议：** 
  只使用字符串作为属性名。

#### Reflect-ownKeys方法变更
**ArkTS1.1版本签名：**  
  `function ownKeys(target: object): (string | symbol)[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | target | object | 是 | 目标对象。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | (string \| symbol)[] | 属性键数组。 |

**示例：**
  ```typescript
  let a = [1,2,3];
  Reflect.ownKeys(a);
  ```

**ArkTS1.2版本签名：**  
  `function ownKeys(target: object): string[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | target | object | 是 | 目标对象。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | string[] | 属性键数组。 |

**示例：**
  ```typescript
  class C{
      a: number=1;
  }
  let a = new C();
  console.info(Reflect.ownKeys(a));
  ```
 
**适配建议：** 
  只使用字符串作为属性名。

#### Reflect-set方法变更
**ArkTS1.1版本签名：**  
  `function set<T extends object, P extends PropertyKey>(target: T, propertyKey: P, value: P extends keyof T ? T[P] : any, receiver?: any): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | target | T | 是 | 目标对象。 |
  | propertyKey | P | 是 | 属性键。 |
  | value | P extends keyof T ? T[P] : any | 是 | 属性值。 |
  | receiver | any | 否 | 接收器对象，默认值为undefined。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示设置是否成功，true表示成功，false表示不成功。 |

**示例：**
  ```typescript
  let a = [1,2,3];
  Reflect.set<Array<number>, number>(a, 0, 2);
  ```

**ArkTS1.2版本签名：**  
  `function set(target: object, propertyKey: string, value: object): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | target | object | 是 | 目标对象。 |
  | propertyKey | string | 是 | 属性键。 |
  | value | object | 是 | 属性值。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示设置是否成功，true表示成功，false表示不成功。 |

**示例：**
  ```typescript
  class C {
      a: number=1;
  }
  let a = new C()
  Reflect.set(a, "a", Number(2))
  console.info(a.a)
  ```
 
**适配建议：** 
  不使用泛型参数，属性名只能是字符串，值必须是对象类型。

#### Reflect-方法新增

**ArkTS1.2版本签名：**
  `function isLiteralInitializedInterface(target: Object): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  |--------|------|------|------|
  | target | Object | 是 | 目标对象。 |

**返回值：**
  | 类型 | 说明 |
  |------|------|
  | boolean | 表示对象是否由Interface创建出来的ObjectLiteral，true表示是，false表示不是。 |

**示例：**
  ```typescript
  interface TestIface {
    str: string
    num: number
    bl: boolean
  }

  let tif: TestIface = { str: "strstr", num: 42, bl: false}
  let res: boolean = Reflect.isLiteralInitializedInterface(tif);
  console.log(res); // True
  ```

## TemplateStringsArray

### 变更梗概
- [TemplateStringsArray-raw属性变更](#templatestringsarray-raw属性变更)

### 变更详情

#### TemplateStringsArray-raw属性变更
**ArkTS1.1版本签名：**  
  `readonly raw: readonly string[]`

- 类型说明：
  | 属性名 | 类型 | 说明 |
  |--------|------|------|
  | raw | readonly string[] | 原始字符串数组。 |

**示例：**
  ```typescript
  function f(a: TemplateStringsArray) {
    a.raw;
  }
  f`Hello`;
  ```

**ArkTS1.2版本签名：**  
  N/A
 
**适配建议：** 
  不使用模板字符串标签函数。

