# StdLib2

## 变更梗概
- [__GLOBAL](#__global)
- [AggregateError](#aggregateerror)
- [ArrayBufferTypes](#arraybuffertypes)
- [IArguments](#iarguments)
- [Intl](#intl)
- [Iterable](#iterable)
- [Iterator](#iterator)
- [IterableIterator](#iterableiterator)

## __GLOBAL

### 变更梗概
- [ClassDecorator类型变更](#classdecorator类型变更)
- [MethodDecorator类型变更](#methoddecorator类型变更)
- [ParameterDecorator类型变更](#parameterdecorator类型变更)
- [PropertyDecorator类型变更](#propertydecorator类型变更)
- [PropertyKey类型变更](#propertykey类型变更)
- [FlatArray类型变更](#flatarray类型变更)

### 变更详情

#### ClassDecorator类型变更
**ArkTS1.1版本签名：**  
  `declare type ClassDecorator = <TFunction extends Function>(target: TFunction) => TFunction | void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | target | TFunction | 是 | 被装饰的类构造函数。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | TFunction \| void | 返回修改后的构造函数或void。 |

**示例：**  
  ```typescript
  let classDecorator: ClassDecorator = (target) => { return target };
  @classDecorator
  class A{}
  ```

**ArkTS1.2版本签名：**  
  不支持。
 
**适配建议：** 
  使用注解 (Annotation) 替代装饰器功能。

#### MethodDecorator类型变更
**ArkTS1.1版本签名：**  
  `declare type MethodDecorator = <T>(target: Object, propertyKey: string | symbol, descriptor: TypedPropertyDescriptor<T>) => TypedPropertyDescriptor<T> | void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | target | Object | 是 | 目标对象。 |
  | propertyKey | string \| symbol | 是 | 方法名。 |
  | descriptor | TypedPropertyDescriptor\<T\> | 是 | 属性描述符。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | TypedPropertyDescriptor\<T\> \| void | 返回修改后的描述符或void。 |

**示例：**  
  ```typescript
  let methodDecorator: MethodDecorator = (target, propertyKey, descriptor) => {
    console.info(JSON.stringify(descriptor));
  }
  class A{
    @methodDecorator
    method(){}
  }
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  使用注解(Annotation)替代装饰器功能。

#### ParameterDecorator类型变更
**ArkTS1.1版本签名：**  
  `declare type ParameterDecorator = (target: Object, propertyKey: string | symbol, parameterIndex: number) => void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | target | Object | 是 | 目标对象。 |
  | propertyKey | string \| symbol | 是 | 方法名。 |
  | parameterIndex | number | 是 | 参数索引。 |

**示例：**  
  ```typescript
  let paramDecorator: ParameterDecorator = (target, methodName, paramIdx) => {
    console.info(methodName as string);
  }
  class A{
    method(@paramDecorator param: string){}
  }
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  使用注解(Annotation)替代装饰器功能。

#### PropertyDecorator类型变更
**ArkTS1.1版本签名：**  
  `declare type PropertyDecorator = (target: Object, propertyKey: string | symbol) => void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | target | Object | 是 | 目标对象。 |
  | propertyKey | string \| symbol | 是 | 属性名。 |

**示例：**  
  ```typescript
  let propertyDecorator: PropertyDecorator = (target, propKey) => {
    console.info(propKey as string);
  }
  class A{
    @propertyDecorator
    prop = 1
  }
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  使用注解(Annotation)替代装饰器功能。

#### PropertyKey类型变更
**ArkTS1.1版本签名：**  
  `declare type PropertyKey = string | number | symbol`

**示例：**  
  ```typescript
  let a: PropertyKey = 1;
  ```

**ArkTS1.2版本签名：**  
  `type PropertyKey = string`

**示例：**  
  ```typescript
  let a: PropertyKey = "a";
  ```

**适配建议：** 
  仅使用字符串作为对象属性键。

#### FlatArray类型变更
**ArkTS1.1版本签名：**  
  `type FlatArray<Arr, Depth extends number> = {"done": Arr,"recur": Arr extends ReadonlyArray<infer InnerArr> ? FlatArray<InnerArr, [-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20][Depth]>: Arr}[Depth extends -1 ? "done" : "recur"]`

**示例：**  
  ```typescript
  const arr1 = [0, 1, 2, [3, 4]];
  let arr: FlatArray<number[], -1> = arr1.flat();
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  手动实现数组扁平化功能。

## AggregateError

### 变更梗概
- [AggregateError-构造函数参数类型变更](#aggregateerror-构造函数参数类型变更)
- [AggregateError-errors属性类型变更](#aggregateerror-errors属性类型变更)
- [AggregateError-Constructor变更](#aggregateerror-constructor变更)

### 变更详情

#### AggregateError-构造函数参数类型变更
**ArkTS1.1版本签名：**  
  `constructor(errors: Iterable<any>, message?: string, options?: ErrorOptions): AggregateError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | errors | Iterable\<any\> | 是 | 可迭代的错误集合。 |
  | message | string | 否 | 错误消息，默认值为"AggregateError"。 |
  | options | ErrorOptions | 否 | 错误选项，默认值为undefined。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | AggregateError | 新创建的AggregateError对象。 |

**示例：**  
  ```typescript
  let err: AggregateError = new AggregateError([1, 2])
  ```

**ArkTS1.2版本签名：**  
  `constructor(errors: Iterable<Error>, message?: string, options?: ErrorOptions): AggregateError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | errors | Iterable\<Error\> | 是 | 可迭代的错误集合(仅限Error类型)。 |
  | message | string | 否 | 错误消息，默认值为"AggregateError"。 |
  | options | ErrorOptions | 否 | 错误选项，默认值为undefined。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | AggregateError | 新创建的AggregateError对象。 |

**示例：**  
  ```typescript
  let err: AggregateError = new AggregateError([Error("first error"), Error("second error")])
  ```

**适配建议：** 
  仅允许使用Error类型作为迭代器返回值的可迭代对象作为AggregateError构造器第一个参数，不建议使用其他类型对象作为参数传入。

#### AggregateError-errors属性类型变更
**ArkTS1.1版本签名：**  
  `errors: any[]`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | any[] | 包含任意类型错误的数组。 |

**示例：**  
  ```typescript
  let err: AggregateError = new AggregateError([1， 2])
  let errors: Object[] = err.errors
  ```

**ArkTS1.2版本签名：**  
  `errors: Error[]`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Error[] | 仅包含Error类型错误的数组。 |

**示例：**  
  ```typescript
  let err: AggregateError = new AggregateError([Error('first error'), Error('second error')])
  let errors = err.errors
  ```

**适配建议：** 
  仅允许使用Error类型作为迭代器返回值的可迭代对象作为AggregateError构造器第一个参数，不建议使用其他类型对象作为参数传入。

#### AggregateError-Constructor变更
**ArkTS1.1版本签名：**  
  `(errors: Iterable<any>, message?: string, options?: ErrorOptions): AggregateError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `errors` | `Iterable<any>` | 是 | 可迭代的任意类型对象。 |
  | `message` | `string` | 否 | 错误消息，默认值为"AggregateError"。 |
  | `options` | `ErrorOptions` | 否 | 错误选项，默认值为undefined。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `AggregateError` | 聚合错误对象。 |

**示例：**  
  ```typescript
  function createAggregateError(ctor: AggregateErrorConstructor) {
    return ctor([Error("first error"), Error("second error")]);
  }
  function createAggregateErrorDirect() {
    return AggregateError([Error("first error"), Error("second error")]);
  }
  ```

**ArkTS1.2版本签名：**  
  `static AggregateError.invoke (errors: Iterable<Error>, message?: string, options?: ErrorOptions): AggregateError`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `errors` | `Iterable<Error>` | 是 | 可迭代的错误对象。 |
  | `message` | `string` | 否 | 错误消息，默认值为AggregateError。 |
  | `options` | `ErrorOptions` | 否 | 错误选项，默认值为undefined。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `AggregateError` | 聚合错误对象。 |

**示例：**  
  ```typescript
  function createAggregateError() {
    return AggregateError([Error("first error"), Error("second error")]);
  }
  ```

**适配建议：** 
  直接创建对应类型的对象，不直接使用constructor类。

## ArrayBufferTypes

### 变更梗概
- [ArrayBufferTypes类型移除](#arraybuffertypes类型移除)
- [SharedArrayBuffer类型移除](#sharedarraybuffer类型移除)

### 变更详情

#### ArrayBufferTypes类型移除
**ArkTS1.1版本签名：**  
  `ArrayBuffer: ArrayBuffer`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | ArrayBuffer | ArrayBuffer对象。 |

**示例：**  
  ```typescript
  let c:ArrayBufferTypes = {
    ArrayBuffer: new ArrayBuffer(10),
    SharedArrayBuffer: new SharedArrayBuffer(10)
  };
  c.ArrayBuffer;
  c.SharedArrayBuffer;
  ```

**ArkTS1.2版本签名：**  
  不支持

**适配建议：** 
  不使用ArrayBufferTypes，如果需要使用类似结构可以自定义类型。

#### SharedArrayBuffer类型移除
**ArkTS1.1版本签名：**  
  `SharedArrayBuffer: SharedArrayBuffer`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | SharedArrayBuffer | SharedArrayBuffer对象。 |

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  不使用ArrayBufferTypes，如果需要使用类似结构可以自定义类型。

## IArguments

### 变更梗概
- [IArguments类型移除](#iarguments类型移除)
- [IArguments-callee属性移除](#iarguments-callee属性移除)
- [IArguments-length属性移除](#iarguments-length属性移除)

### 变更详情

#### IArguments类型移除
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<any>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<any\> | arguments的迭代器。 |

**示例：**  
  ```typescript
  function f(a:number,b:string){
    Reflect.get(arguments, Symbol.iterator);
  }
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  ArkTS1.2不能使用arguments，因此不需要使用IArguments。

#### IArguments-callee属性移除
**ArkTS1.1版本签名：**  
  `callee: Function`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Function | 当前执行的函数。 |

**示例：**  
  ```typescript
  function f(a:number,b:string){
    arguments.callee;
  }
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  ArkTS1.2不能使用arguments，因此不需要使用callee。

#### IArguments-length属性移除
**ArkTS1.1版本签名：**  
  `length: number`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 参数个数。 |

**示例：**  
  ```typescript
  function f(a:number,b:string){
    console.info(arguments.length);
  }
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  ArkTS1.2不能使用arguments，因此不需要使用length属性。

## Intl

### 变更梗概
- [DateTimeFormat变更](#datetimeformat变更)
- [DateTimeFormatPartTypesRegistry变更](#datetimeformatparttypesregistry变更)
- [DisplayNames变更](#displaynames变更)
- [ListFormat访问变更](#listformat访问变更)
- [NumberFormat变更](#numberformat变更)

### 变更详情

#### DateTimeFormat变更
- ArkTS1.1 版本签名：  
  `readonly prototype: DateTimeFormat`

**示例：**  
  ```typescript
  Reflect.get(Intl.DateTimeFormat, "prototype")
  ```
**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  静态语言不支持去修改prototype，建议创建新的对象。

#### DateTimeFormatPartTypesRegistry变更
**ArkTS1.1版本签名：**  
  `interface DateTimeFormatPartTypesRegistry {
    day: any
    dayPeriod: any
    era: any
    hour: any
    literal: any
    minute: any
    month: any
    second: any
    timeZoneName: any
    weekday: any
    year: any
  }`

**示例：**  
  ```typescript
  let o: Intl.DateTimeFormatPartTypesRegistry = {
    day: undefined,
    dayPeriod: undefined,
    era: undefined,
    hour: undefined,
    literal: undefined,
    minute: undefined,
    month: undefined,
    second: undefined,
    timeZoneName: undefined,
    weekday: undefined,
    year: undefined,
    unknown: undefined,
    fractionalSecond: undefined
  }
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  不使用Intl.DateTimeFormatPartTypesRegistry。

#### DisplayNames变更
**ArkTS1.1版本签名：**  
  `prototype: DisplayNames`

**示例：**  
  ```typescript
  Reflect.get(Intl.DisplayNames, "prototype")
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  静态语言不支持去修改prototype，建议创建新的对象。

#### ListFormat访问变更
**ArkTS1.1版本签名：**  
  `prototype: ListFormat`

**示例：**  
  ```typescript
  Reflect.get(Intl.ListFormat, "prototype")
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  静态语言不支持去修改prototype，建议创建新的对象。

#### NumberFormat变更
**ArkTS1.1版本签名：**  
  `readonly prototype: NumberFormat`

**示例：**  
  ```typescript
  Reflect.get(Intl.NumberFormat, "prototype")
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  静态语言不支持去修改prototype，建议创建新的对象。

## Iterable

### 变更梗概
- [Iterable-Symbol.iterator变更](#iterable-symboliterator变更)

### 变更详情

#### Iterable-Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): Iterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Iterator\<T\> | 迭代器对象。 |

**示例：**  
  ```typescript
  function f<T>(a: Iterable<T>) {
    Reflect.get(a, Symbol.iterator);
  }
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): Iterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Iterator\<T\> | 迭代器对象。 |

**示例：**  
  ```typescript
  class C<T> implements Iterable<T> {
    $_iterator(): Iterator<T> {
      //....
    }
  }
  ```

**适配建议：** 
  建议仅使用for...of访问迭代器，不要显示访问迭代器。

## Iterator

### 变更梗概
- [Iterator-return方法变更](#iterator-return方法变更)
- [Iterator-throw方法变更](#iterator-throw方法变更)

### 变更详情

#### Iterator-return方法变更
**ArkTS1.1版本签名：**  
  `return?(value?: TReturn): IteratorResult<T, TReturn>`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | TReturn | 否 | 可选的返回值，默认值为undefined。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IteratorResult\<T, TReturn\> | 迭代结果对象。 |

**示例：**  
  ```typescript
  class C implements Iterator<number|undefined> {
    a: number = 0;
    b: number;
    constructor (b: number) {
      this.b = b;
    }
    next(): IteratorResult<number> {
      if (this.a >= this.b) {
        return {value: undefined, done: true};
      }
      this.a++;
      return {value: this.a, done: false};
    }
    return(): IteratorResult<number> {
      console.info("call return");
      this.a = 0;
      return {value: undefined, done: true};
    }
  }
  let a = new C(5);
  a.next();
  a.return();
  ```

**ArkTS1.2版本签名：**  
  N/A

**适配建议：** 
  不使用return方法。

#### Iterator-throw方法变更
**ArkTS1.1版本签名：**  
  `throw?(e?: any): IteratorResult<T, TReturn>`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | e | any | 否 | 可选的错误对象，默认值为undefined。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IteratorResult\<T, TReturn\> | 迭代结果对象。 |

**示例：**  
  ```typescript
  class C implements Iterator<number|undefined> {
    throw(e: Error): IteratorResult<number> {
      console.error("Error: " + e);
      return { value: undefined, done: true };
    }
  }
  let a = new C();
  a.throw(new Error("test"));
  ```

**ArkTS1.2版本签名：**  
  N/A
 
**适配建议：** 
  不使用throw方法。

## IterableIterator

### 变更梗概
- [IterableIterator-Symbol.iterator变更](#iterableiterator-symboliterator变更)

### 变更详情

#### IterableIterator-Symbol.iterator变更
- ArkTS1.1 版本签名：  
  `[Symbol.iterator](): IterableIterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `IterableIterator<T>` | 表示返回一个可迭代的迭代器对象。 |

**示例：**  
  ```typescript
  function f<T>(a: IterableIterator<T>) {
    Reflect.get(a, Symbol.iterator);
  }
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `IterableIterator<T>` | 表示返回一个可迭代的迭代器对象。 |

**示例：**  
  ```typescript
  class C<T> implements IterableIterator<T> {
    $_iterator(): IterableIterator<T> {
      //....
    }
    // ...
  }
  ```

**适配建议：** 
  建议仅使用`for...of`访问迭代器，不要显示访问迭代器。
