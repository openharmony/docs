# ReadOnly

## 变更梗概
- [ReadonlyArray](#readonlyarray)
- [ReadonlyMap](#readonlymap)
- [ReadonlySet](#readonlyset)

## ReadonlyArray

### 变更梗概
- [ReadonlyArray-Symbol.iterator变更](#readonlyarray-symboliterator变更)
- [ReadonlyArray-concat方法参数限制](#readonlyarray-concat方法参数限制)
- [ReadonlyArray-every方法签名变更](#readonlyarray-every方法签名变更)
- [ReadonlyArray-filter方法签名变更](#readonlyarray-filter方法签名变更)
- [ReadonlyArray-find方法签名变更](#readonlyarray-find方法签名变更)
- [ReadonlyArray-findIndex方法签名变更](#readonlyarray-findindex方法签名变更)
- [ReadonlyArray-flat方法移除](#readonlyarray-flat方法移除)
- [ReadonlyArray-flatMap方法移除](#readonlyarray-flatmap方法移除)
- [ReadonlyArray-forEach方法签名变更](#readonlyarray-foreach方法签名变更)
- [ReadonlyArray-map方法签名变更](#readonlyarray-map方法签名变更)
- [ReadonlyArray-some方法签名变更](#readonlyarray-some方法签名变更)

### 变更详情

#### ReadonlyArray-Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<T\> | 只读数组迭代器。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<string> = ["a"];
  Reflect.get(arr, Symbol.iterator);
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<T\> | 只读数组迭代器。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<string> = ["a"];
  arr.$_iterator();
  ```

**适配建议：** 
  使用for...of替代直接迭代器访问。


#### ReadonlyArray-concat方法参数限制
**ArkTS1.1版本签名：**  
  `concat(...items: (T | ConcatArray<T>)[]): T[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | items | (T \| ConcatArray\<T\>)[] | 是 | 待连接元素。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T[] | 新数组。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<number> = [1];
  arr.concat(2, [3]); // [1, 2, 3]
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  手动转换后连接：
  ```typescript
  let arr1: ReadonlyArray<number> = [1] as Array<number>;
  let temp = [2];
  arr1.concat(temp); // [1, 2] 先确保参数类型一致
  ```


#### ReadonlyArray-every方法签名变更
**ArkTS1.1版本签名：**  
  `every(predicate: (value: T, index: number, array: readonly T[]) => unknown, thisArg?: any): boolean`  
  `every<S extends T>(predicate: (value: T, index: number, array: readonly T[]) => value is S, thisArg?: any): this is readonly S[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行上下文，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | readonly T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | unknown | 返回值会被隐式转换为boolean，决定当前元素是否通过检查。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否所有元素都通过测试。true表示全部都通过，false表示全部都不通过。 |

**示例：**  
  ```typescript
  class C {
    test(v: number) { return v > this.limit; }
    limit = 1;
  }
  let arr: ReadonlyArray<number> = [2,3];
  arr.every(new C().test, {limit: 2}); // false
  ```

**ArkTS1.2版本签名：**  
  `every(predicate: (value: T, index: number, array: readonly T[]) => boolean): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | readonly T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否通过检查，true表示当前元素通过检查，false表示未通过。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否所有元素都通过测试。true表示全部都通过，false表示全部都不通过。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<number> = [2,3];
  let limit = 2;
  arr.every(v => v > limit); // false
  ```

**适配建议：** 
  使用闭包变量替代thisArg。


#### ReadonlyArray-filter方法签名变更
**ArkTS1.1版本签名：**  
  - `filter(predicate: (value: T, index: number, array: readonly T[]) => unknown, thisArg?: any): T[]`  
  - `filter<S extends T>(predicate: (value: T, index: number, array: readonly T[]) => value is S, thisArg?: any): S[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 过滤函数。 |
  | thisArg | any | 否 | 执行上下文，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | unknown | 返回值会被隐式转换为boolean，决定当前元素是会被过滤。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T[] | 过滤后的新数组。 |

**示例：**  
  ```typescript
  class Filter {
    criteria(v: number) { return v > this.min; }
    min = 2;
  }
  let arr: ReadonlyArray<number> = [1,2,3];
  arr.filter(new Filter().criteria, {min: 1}); // [2, 3]
  ```

**ArkTS1.2版本签名：**  
  `filter(predicate: (value: T, index: number, array: readonly T[]) => boolean): T[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 过滤函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | readonly T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否过滤当前元素，true表示保留当前元素，false表示过滤掉当前元素。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T[] | 过滤后的新数组。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<number> = [1,2,3] as Array<number>;
  let min = 1;
  arr.filter(v => v > min); // [2, 3]
  ```

**适配建议：** 
  通过外部变量传递上下文。


#### ReadonlyArray-find方法签名变更
**ArkTS1.1版本签名：**  
  `find(predicate: (value: T, index: number, obj: readonly T[]) => unknown, thisArg?: any): T | undefined`  
  `find<S extends T>(predicate: (this: void, value: T, index: number, obj: readonly T[]) => value is S, thisArg?: any): S | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行上下文，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | obj | readonly T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | unknown | 返回值会被隐式转换为boolean，判断当前是否找到匹配项。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T \| undefined | 找到的元素或undefined。 |

**示例：**  
  ```typescript
  class Matcher {
    check(v: number) { return v === this.target; }
    target = 2;
  }
  let arr: ReadonlyArray<number> = [1,2,3];
  arr.find(new Matcher().check, {target: 3}); // 3
  ```

**ArkTS1.2版本签名：**  
  `find(predicate: (value: T, index: number, obj: readonly T[]) => boolean): T | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | obj | readonly T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T \| undefined | 找到的元素或undefined。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<number> = [1,2,3] as Array<number>;
  let target = 3;
  arr.find(v => v === target); // 3
  ```

**适配建议：** 
  使用闭包捕获外部变量。


#### ReadonlyArray-findIndex方法签名变更
**ArkTS1.1版本签名：**  
  `findIndex(predicate: (value: T, index: number, obj: readonly T[]) => unknown, thisArg?: any): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行上下文，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | obj | readonly  T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 元素索引或-1表示未找到满足的元素。 |

**示例：**  
  ```typescript
  class Matcher {
    check(v: number) { return v > this.limit; }
    limit = 1;
  }
  let arr: ReadonlyArray<number> = [1,2,3];
  arr.findIndex(new Matcher().check, {limit: 2}); // 2
  ```

**ArkTS1.2版本签名：**  
  `findIndex(predicate: (value: T, index: number, obj: readonly T[]) => boolean): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | obj | readonly  T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 元素索引，-1表示未找到满足的元素。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<number> = [1,2,3] as Array<number>;
  let limit = 2;
  arr.findIndex(v => v > limit); // 2
  ```

**适配建议：** 
  通过外部变量传递条件参数。


#### ReadonlyArray-flat方法移除
**ArkTS1.1版本签名：**  
  `flat<A, D extends number = 1>(this: A, depth?: D): FlatArray<A, D>[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | depth | D | 否 | 展开深度，默认值为1。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | FlatArray\<A, D\>[] | 展开后的数组。 |

**示例：**  
  ```typescript
  type Nested = number | Nested[];
  let arr: ReadonlyArray<Nested> = [[1], 2, [3]];
  arr.flat(); // [1, 2, 3]
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  手动实现展开逻辑。
  ```typescript
  function flatten(arr: any[]): number[] {
    return arr.reduce((acc, val) => acc.concat(Array.isArray(val) ? flatten(val) : val), []);
  }
  ```


#### ReadonlyArray-flatMap方法移除
**ArkTS1.1版本签名：**  
  `flatMap<U, This = undefined>(callback: (this: This, value: T, index: number, array: T[]) => U | ReadonlyArray<U>, thisArg?: This): U[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | function | 是 | 映射函数。 |
  | thisArg | This | 否 | 执行上下文，默认值为undefined。 |

**callback函数参数说明：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | this | This | 是 | 由 thisArg 指定的上下文默认undefined。 |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | T[] | 是 | 调用的原始数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | U \| ReadonlyArray\<U> | 可返回单个值U或U类型的数组。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | U[] | 映射并展开后的数组。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<string> = ["a b", "c d"];
  arr.flatMap(s => s.split(" ")); // ["a", "b", "c", "d"]
  ```

**ArkTS1.2版本签名：**  
  不支持。

**适配建议：** 
  不使用flatMap。


#### ReadonlyArray-forEach方法签名变更
**ArkTS1.1版本签名：**  
  `forEach(callbackfn: (value: T, index: number, array: readonly T[]) => void, thisArg?: any): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 遍历函数。 |
  | thisArg | any | 否 | 执行上下文，默认值为undefined。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | readonly T[] | 是 | 调用的原始数组。 |

**示例：**  
  ```typescript
  class Logger {
    log(v: number) { console.info(v + this.offset); }
    offset = 10;
  }
  let arr: ReadonlyArray<number> = [1,2];
  arr.forEach(new Logger().log, {offset: 20}); // 21    22
  ```

**ArkTS1.2版本签名：**  
  `forEach(callbackfn: (value: T, index: number, array: readonly T[]) => void): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 遍历函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | readonly T[] | 是 | 调用的原始数组。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<number> = [1,2] as Array<number>;
  let offset = 20;
  arr.forEach(v => console.info(v + offset)); // 21    22
  ```

**适配建议：** 
  使用箭头函数捕获外部变量。


#### ReadonlyArray-map方法签名变更
**ArkTS1.1版本签名：**  
  `map<U>(callbackfn: (value: T, index: number, array: readonly T[]) => U, thisArg?: any): U[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 映射函数。 |
  | thisArg | any | 否 | 执行上下文，默认值为undefined。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | readonly T[] | 是 | 调用的原始数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | U | 映射后的值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | U[] | 映射后的新数组。 |

**示例：**  
  ```typescript
  class Transformer {
    transform(v: number) { return v * this.factor; }
    factor = 2;
  }
  let arr: ReadonlyArray<number> = [1,2];
  arr.map(new Transformer().transform, {factor: 3}); // [3, 6]
  ```

**ArkTS1.2版本签名：**  
  `map<U>(callbackfn: (value: T, index: number, array: readonly T[]) => U): U[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 映射函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | readonly T[] | 是 | 调用的原始数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | U | 映射后的值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | U[] | 映射后的新数组。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<number> = [1,2] as Array<number>;
  let factor = 3;
  arr.map(v => v * factor); // [3, 6]
  ```

**适配建议：** 
  通过闭包传递上下文参数。


#### ReadonlyArray-some方法签名变更
**ArkTS1.1版本签名：**  
  `some(predicate: (value: T, index: number, array: readonly T[]) => unknown, thisArg?: any): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行上下文，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | readonly T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | unknown | 返回值会被隐式转换为boolean，判断当前元素是否满足predicate。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否至少有一个元素通过测试。true表示至少有一个元素通过测试，false表示没有任何元素通过。 |

**示例：**  
  ```typescript
  class Checker {
    test(v: number) { return v > this.threshold; }
    threshold = 2;
  }
  let arr: ReadonlyArray<number> = [1,2,3];
  arr.some(new Checker().test, {threshold: 1}); // true
  ```

**ArkTS1.2版本签名：**  
  `some(predicate: (value: T, index: number, array: readonly T[]) => boolean): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | readonly T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否满足`predicate`，`true`表示满足，`false`表示不满足。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否至少有一个元素通过测试。true表示至少有一个元素通过测试，false表示没有任何元素通过。 |

**示例：**  
  ```typescript
  let arr: ReadonlyArray<number> = [1,2,3] as Array<number>;
  let threshold = 1;
  arr.some(v => v > threshold); // true
  ```

**适配建议：** 
  使用外部变量传递条件参数。

## ReadonlyMap

### 变更梗概
- [ReadonlyMap-Symbol.iterator变更](#readonlymap-symboliterator变更)
- [ReadonlyMap-forEach方法签名变更](#readonlymap-foreach方法签名变更)

### 变更详情
#### ReadonlyMap-Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<[K, V]>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<[K, V]\> | 只读Map的迭代器。 |

**示例：**  
  ```typescript
  let m: ReadonlyMap<string, string> = new Map<string, string>();
  let iter = Reflect.get(m, Symbol.iterator);
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<[K, V]>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<[K, V]\> | 只读Map的迭代器。 |

**示例：**  
  ```typescript
  const m: ReadonlyMap<string, string> = new Map<string, string>();
  let iter = m.$_iterator();
  ```

**适配建议：** 
  使用for...of替代直接迭代器访问。


#### ReadonlyMap-forEach方法签名变更
**ArkTS1.1版本签名：**  
  `forEach(callbackfn: (value: V, key: K, map: ReadonlyMap<K, V>) => void, thisArg?: any): void`

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
  | map | ReadonlyMap\<K, V\> | 是 | 调用的原始Map。 |

**示例：**  
  ```typescript
  const m: ReadonlyMap<string, string> = new Map<string, string>();
  m.forEach((value, key) => {}, new Ctx());
  ```

**ArkTS1.2版本签名：**  
  `forEach(callbackfn: (value: V, key: K, map: ReadonlyMap<K, V>) => void): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 遍历函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | V | 是 | 当前被遍历的数组元素的值。 |
  | key | K | 是 | 当前元素的索引。 |
  | map | ReadonlyMap\<K, V\> | 是 | 调用的原始Map。 |

**示例：**  
  ```typescript
  const m: ReadonlyMap<string, string> = new Map<string, string>();
  m.forEach((value, key) => console.info(key, value));
  ```

**适配建议：** 
  使用闭包替代thisArg参数。

## ReadonlySet

### 变更梗概
- [ReadonlySet-Symbol.iterator变更](#readonlyset-symboliterator变更)
- [ReadonlySet-forEach方法签名变更](#readonlyset-foreach方法签名变更)

### 变更详情

#### ReadonlySet-Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<T\> | 只读Set的迭代器。 |

**示例：**  
  ```typescript
  let set: ReadonlySet<string> = new Set(["a"]);
  Reflect.get(set, Symbol.iterator);
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<T\> | 只读Set的迭代器。 |

**示例：**  
  ```typescript
  let set: ReadonlySet<string> = new Set<string>(["a"]);
  set.$_iterator();
  ```

**适配建议：** 
  使用for...of替代直接迭代器访问。


#### ReadonlySet-forEach方法签名变更
**ArkTS1.1版本签名：**  
  `forEach(callbackfn: (value: T, value2: T, set: ReadonlySet<T>) => void, thisArg?: any): void`

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
  | set | ReadonlySet\<T\> | 是 | 调用的原始set。 |

**示例：**  
  ```typescript
  class Printer {
    print(v: string) { console.info(v + this.suffix); }
    suffix = "!";
  }
  let set: ReadonlySet<string> = new Set(["a"]);
  set.forEach(new Printer().print, {suffix: "?"});
  ```

**ArkTS1.2版本签名：**  
  `forEach(callbackfn: (value: T, value2: T, set: ReadonlySet<T>) => void): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 遍历函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | value2 | T | 是 | 当前元素的索引。 |
  | set | ReadonlySet\<T\> | 是 | 调用的原始set。 |

**示例：**  
  ```typescript
  let set: ReadonlySet<string> = new Set<string>(["a"]);
  let suffix = "?";
  set.forEach(v => console.info(v + suffix));
  ```

**适配建议：** 
  使用闭包捕获外部变量。
