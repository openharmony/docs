# Constructor

## 变更梗概
- [BigIntConstructor](#bigintconstructor)
- [BooleanConstructor](#booleanconstructor)
- [DateConstructor](#dateconstructor)
- [ErrorConstructor](#errorconstructor)
- [EvalErrorConstructor](#evalerrorconstructor)
- [RangeErrorConstructor](#rangeerrorconstructor)
- [SyntaxErrorConstructor](#syntaxerrorconstructor)
- [TypeErrorConstructor](#typeerrorconstructor)
- [URIErrorConstructor](#urierrorconstructor)
- [ReferenceErrorConstructor](#referenceerrorconstructor)
- [RegExpConstructor](#regexpconstructor)

## BigIntConstructor

### 变更梗概
- [BigIntConstructor-构造函数调用变更](#bigintconstructor-构造函数调用变更)

### 变更详情

#### BigIntConstructor-构造函数调用变更
**ArkTS1.1版本签名：**  
  `(value: bigint | boolean | number | string): bigint`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint \| boolean \| number \| string | 是 | 要转换的值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | bigint | 转换后的BigInt值。 |

**示例：**  
  ```typescript
  function createBigInt(ctor: BigIntConstructor) {
    return ctor(1);
  }
  function createBigIntDirect() {
    return BigInt(1);
  }
  ```

**ArkTS1.2版本签名：**  
  `static BigInt.invoke(value: bigint | boolean | number | string): bigint`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint \| boolean \| number \| string | 是 | 要转换的值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | bigint | 转换后的BigInt值。 |

**示例：**  
  ```typescript
  function creatBigInt() {
    return new BigInt(1)
  }
  
  function main() {
      console.info(creatBigInt());
  }
  ```

- 适配建议：
  不要使用Constructor类型，使用invoke或new的方式创建对象。

## BooleanConstructor

### 变更梗概
- [BooleanConstructor-构造函数签名变更](#booleanconstructor-构造函数签名变更)
- [BooleanConstructor-构造函数调用变更](#booleanconstructor-构造函数调用变更)

### 变更详情

#### BooleanConstructor-构造函数签名变更
- 参数类型any改为具体类型。

**ArkTS1.1版本签名：**  
  `constructor(value?: any): Boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | any | 否 | 要转换的值，默认值为undefined。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Boolean | 转换后的布尔值。 |

**ArkTS1.2版本签名：**  
  `constructor(value: Object | null | undefined = undefined): Boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | Object \| null \| undefined | 否 | 要转换的值，默认值为undefined。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Boolean | 转换后的布尔值。 |

- 适配建议：
  ArkTS1.2相比ArkTS1.1接口签名有变更，但对开发者接口行为无变更。

#### BooleanConstructor-构造函数调用变更
**ArkTS1.1版本签名：**  
  `<T>(value?: T): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 否 | 要转换的值，默认值为false。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 转换后的布尔值。 |

**示例：**  
  ```typescript
  function createBoolean(ctor: BooleanConstructor) {
    return ctor(true);
  }
  function createBooleanDirect() {
    return Boolean(true);
  }
  ```

**ArkTS1.2版本签名：**  
  `static Boolean.invoke<T>(value?: T): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 否 | 要转换的值，默认值为false。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 转换后的布尔值。 |

**示例：**  
  ```typescript
  function createBoolean() {
    return Boolean(true);
  }
  ```

- 适配建议：
  不要使用Constructor类型，使用invoke或new的方式创建对象。

## DateConstructor

### 变更梗概
- [DateConstructor-构造函数调用变更](#dateconstructor-构造函数调用变更)

### 变更详情

#### DateConstructor-构造函数调用变更
**ArkTS1.1版本签名：**  
  `(): string`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 日期字符串。 |

**示例：**  
  ```typescript
  function createDate(ctor: DateConstructor) {
    return ctor();
  }
  function createDateDirect() {
    return Date();
  }
  ```

**ArkTS1.2版本签名：**  
  `static Date.invoke(): string`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | string | 日期字符串。 |

**示例：**  
  ```typescript
  function createDate() {
    return Date();
  }
  ```

- 适配建议：
  不要使用Constructor类型，使用invoke或new的方式直接创建对象。

## ErrorConstructor

### 变更梗概
- [ErrorConstructor-构造函数调用变更](#errorconstructor-构造函数调用变更)

### 变更详情

#### ErrorConstructor-构造函数调用变更
**ArkTS1.1版本签名：**  
  `(message?: string): Error`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"Error"。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Error | 新创建的Error对象。 |

**示例：**  
  ```typescript
  function createError(ctor: ErrorConstructor) {
    return ctor("some error");
  }
  function createErrorDirect() {
    return Error("some error");
  }
  ```

**ArkTS1.2版本签名：**  
  `static invoke(message?: string): Error`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"Error"。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Error | 新创建的Error对象。 |

**示例：**  
  ```typescript
  function createError() {
    return Error("some error");
  }
  ```

- 适配建议：
  不要使用Constructor类型，使用invoke或new的方式直接创建对象。

## EvalErrorConstructor

### 变更梗概
- [EvalErrorConstructor-构造函数调用变更](#evalerrorconstructor-构造函数调用变更)

### 变更详情

#### EvalErrorConstructor-构造函数调用变更
**ArkTS1.1版本签名：**  
  `(message?: string): EvalError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"EvalError"。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | EvalError | 新创建的EvalError对象。 |

**示例：**  
  ```typescript
  function createError(ctor: EvalErrorConstructor) {
    return ctor("some error");
  }
  function createErrorDirect() {
    return EvalError("some error");
  }
  ```

**ArkTS1.2版本签名：**  
  `static invoke(message?: string): EvalError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"EvalError"。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | EvalError | 新创建的EvalError对象。 |

**示例：**  
  ```typescript
  function createError() {
    return EvalError("some error");
  }
  ```

- 适配建议：
  不要使用Constructor类型，使用invoke或new的方式直接创建对象。

## RangeErrorConstructor

### 变更梗概
- [RangeErrorConstructor-构造函数调用变更](#rangeerrorconstructor-构造函数调用变更)

### 变更详情

#### RangeErrorConstructor-构造函数调用变更
**ArkTS1.1版本签名：**  
  `(message?: string): RangeError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"RangeError"。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | RangeError | 创建的RangeError对象。 |

**示例：**  
  ```typescript
  function createError(ctor: RangeErrorConstructor) {
    return ctor("invalid range");
  }
  function createErrorDirect() {
    return RangeError("invalid range");
  }
  ```

**ArkTS1.2版本签名：**  
  `static RangeError.invoke(message?: string): RangeError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"RangeError"。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | RangeError | 创建的RangeError对象。 |

**示例：**  
  ```typescript
  RangeError("invalid range"); // 自动调用invoke
  ```

- 适配建议：
  直接调用而非通过Constructor类型。

## ReferenceErrorConstructor

### 变更梗概
- [ReferenceErrorConstructor-构造函数调用变更](#referenceerrorconstructor-构造函数调用变更)

### 变更详情

#### ReferenceErrorConstructor-构造函数调用变更
**ArkTS1.1版本签名：**  
  `(message?: string): ReferenceError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"ReferenceError"。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | ReferenceError | 创建的ReferenceError对象。 |

**示例：**  
  ```typescript
  function createError(ctor: ReferenceErrorConstructor) {
    return ctor("undefined variable");
  }
  function createErrorDirect() {
    return ReferenceError("undefined variable");
  }
  ```

**ArkTS1.2版本签名：**  
  `static ReferenceError.invoke(message?: string): ReferenceError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"ReferenceError"。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | ReferenceError | 创建的ReferenceError对象。 |

**示例：**  
  ```typescript
  ReferenceError("undefined variable");
  ```

- 适配建议：
  直接创建对应类型的对象，不直接使用constructor类。

## RegExpConstructor

### 变更梗概
- [RegExpConstructor-构造函数调用单参数变更](#regexpconstructor-构造函数调用单参数变更)
- [RegExpConstructor-构造函数调用双参数变更](#regexpconstructor-构造函数调用双参数变更)
- [RegExpConstructor-构造函数调用双参数标志可选变更](#regexpconstructor-构造函数调用双参数标志可选变更)

### 变更详情

#### RegExpConstructor-构造函数调用单参数变更
- ArkTS1.1 版本签名：  
  `(pattern: RegExp | string): RegExp`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `pattern` | `RegExp \| string` | 是 | 正则表达式模式或字符串形式的模式。 |
  
**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `RegExp` | 构造出的正则表达式对象。 |

**示例：**  
  ```typescript
  function createRegExp(ctor: RegExpConstructor) {
    return ctor("regexp");
  }
  function createRegExpDirect() {
    return RegExp("regexp");
  }
  ```

**ArkTS1.2版本签名：**  
  `static RegExp.invoke(pattern: RegExp | string): RegExp`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `pattern` | `RegExp \| string` | 是 | 正则表达式模式或字符串形式的模式。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `RegExp` | 构造出的正则表达式对象。 |

**示例：**  
  ```typescript
  function createDirect() {
    return RegExp("regexp");
  }
  ```

- 适配建议：
  直接创建对应类型的对象，不直接使用constructor类。


#### RegExpConstructor-构造函数调用双参数变更
- ArkTS1.1 版本签名：  
  `(pattern: RegExp | string, flags?: string): RegExp`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `pattern` | `RegExp \| string` | 是 | 正则表达式模式或字符串形式的模式。 |
  | `flags` | `string` | 否 | 正则表达式的标志，默认值为null。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `RegExp` | 构造出的正则表达式对象。 |

**示例：**  
  ```typescript
  function createRegExp(ctor: RegExpConstructor) {
    return ctor("regexp", "i");
  }
  function createRegExpDirect() {
    return RegExp("regexp", "i");
  }
  ```

**ArkTS1.2版本签名：**  
  `static RegExp.invoke(pattern: RegExp | string, flags?: string): RegExp`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `pattern` | `RegExp \| string` | 是 | 正则表达式模式或字符串形式的模式。 |
  | `flags` | `string` | 否 | 正则表达式的标志，默认值为null。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `RegExp` | 构造出的正则表达式对象。 |

**示例：**  
  ```typescript
  function createDirect() {
    return RegExp("regexp", "i");
  }
  ```

- 适配建议：
  直接创建对应类型的对象，不直接使用constructor类。


#### RegExpConstructor-构造函数调用双参数标志可选变更
- ArkTS1.1 版本签名：  
  `(pattern: string, flags?: string): RegExp`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `pattern` | `string` | 是 | 字符串形式的正则表达式模式。 |
  | `flags` | `string` | 否 | 正则表达式的标志，默认值为null。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `RegExp` | 构造出的正则表达式对象。 |

**示例：**  
  ```typescript
  function createRegExp(ctor: RegExpConstructor) {
    return ctor("regexp");
  }
  function createRegExpDirect() {
    return RegExp("regexp");
  }
  ```

**ArkTS1.2版本签名：**  
  `static RegExp.invoke(pattern: string, flags?: string): RegExp`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `pattern` | `string` | 是 | 字符串形式的正则表达式模式。 |
  | `flags` | `string` | 否 | 正则表达式的标志，默认值为null。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `RegExp` | 构造出的正则表达式对象。 |

**示例：**  
  ```typescript
  function createDirect() {
    return RegExp("regexp");
  }
  ```

- 适配建议：
  直接创建对应类型的对象，不直接使用constructor类。

## SyntaxErrorConstructor

### 变更梗概
- [SyntaxErrorConstructor-构造函数调用变更](#syntaxerrorconstructor-构造函数调用变更)

### 变更详情

#### SyntaxErrorConstructor-构造函数调用变更
**ArkTS1.1版本签名：**  
  `(message?: string): SyntaxError`

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"SyntaxError"。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | SyntaxError | 返回SyntaxError对象。 |

**示例：**  
  ```typescript
  function createError(ctor: SyntaxErrorConstructor) {
    return ctor("some error");
  }
  function createErrorDirect() {
    return SyntaxError("some error");
  }
  ```

**ArkTS1.2版本签名：**  
  `static SyntaxError.invoke(message?: string): SyntaxError`

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"SyntaxError"。 |

**返回值：**

  |  类型  | 说明 |
  | -------- | -------- |
  | SyntaxError | 返回SyntaxError对象。 |

**示例：**  
  ```typescript
  function createError() {
    return SyntaxError("some error");
  }
  ```
 
- 适配建议：
  不要使用Constructor类型，使用invoke或new的方式直接创建对象。

## TypeErrorConstructor

### 变更梗概
- [TypeErrorConstructor-构造函数调用变更](#typeerrorconstructor-构造函数调用变更)

### 变更详情

#### TypeErrorConstructor-构造函数调用变更
**ArkTS1.1版本签名：**  
  `(message?: string): TypeError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"TypeError"。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | TypeError | 返回TypeError对象。 |

**示例：**  
  ```typescript
  function createError(ctor: TypeErrorConstructor) {
    return ctor("some error");
  }
  function createErrorDirect() {
    return TypeError("some error");
  }
  ```

**ArkTS1.2版本签名：**  
  `static TypeError.invoke(message?: string): TypeError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"TypeError"。 |

**返回值：**
  |  类型  | 说明 |
  | -------- | -------- |
  | TypeError | 返回TypeError对象。 |

**示例：**  
  ```typescript
  function createError() {
    return TypeError("some error");
  }
  ```

- 适配建议：
  不要使用Constructor类型，使用invoke或new的方式直接创建对象。

## URIErrorConstructor

### 变更梗概
- [URIErrorConstructor-构造函数调用变更](#urierrorconstructor-构造函数调用变更)

### 变更详情

#### URIErrorConstructor-构造函数调用变更
**ArkTS1.1版本签名：**  
  `(message?: string): URIError`

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"URIError"。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | URIError | 返回URIError对象。 |

**示例：**  
  ```typescript
  function createError(ctor: URIErrorConstructor) {
    return ctor("some error");
  }
  function createErrorDirect() {
    return URIError("some error");
  }
  ```

**ArkTS1.2版本签名：**  
  `static URIError.invoke(message?: string): URIError`

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | message | string | 否 | 错误信息，默认值为"URIError"。 |

**返回值：**

  |  类型  | 说明 |
  | -------- | -------- |
  | URIError | 返回URIError对象。 |

**示例：**  
  ```typescript
  function createError() {
    return URIError("some error");
  }
  ```

- 适配建议：
  不要使用Constructor类型，使用invoke或new的方式直接创建对象。
