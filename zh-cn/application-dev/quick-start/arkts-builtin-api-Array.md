# Array

## 变更梗概
- [Symbol.iterator变更](#symboliterator变更)
- [concat方法参数变更](#concat方法参数变更)
- [every方法签名变更](#every方法签名变更)
- [filter方法签名变更](#filter方法签名变更)
- [find方法签名变更](#find方法签名变更)
- [findIndex方法签名变更](#findindex方法签名变更)
- [flat方法移除](#flat方法移除)
- [flatMap方法移除](#flatmap方法移除)
- [forEach方法签名变更](#foreach方法签名变更)
- [map方法签名变更](#map方法签名变更)
- [from方法签名变更](#from方法签名变更)
- [some方法签名变更](#some方法签名变更)
- [数组长度构造函数变更](#数组长度构造函数变更)

## 变更详情

### Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<T\> | 数组的迭代器对象。 |

**示例：**  
  ```typescript
  let a = new Array([1, 2, 3]);
  let iter = Reflect.get(a, Symbol.iterator);
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<T>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<T\> | 数组的迭代器对象。 |

**示例：**  
  ```typescript
  let a: Array<number> = new Array<number>(1, 2, 3);
  let iter: IterableIterator<number> = a.$_iterator();
  ```

- 适配建议：
  建议仅使用for...of访问迭代器，不要显示访问迭代器。

### concat方法参数变更
**ArkTS1.1版本签名：**  
  `concat(...items: (T | ConcatArray<T>)[]): T[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | items | (T \| ConcatArray\<T\>)[] | 是 | 要连接的项或数组。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T[] | 连接后的新数组。 |

**示例：**  
  ```typescript
  let arr1=new Array<number>();
  let arr2=new Array<number>();
  arr1.concat(1, arr2)
  ```

**ArkTS1.2版本签名：**  
  不支持。

- 适配建议：
  将单个成员改成数组再使用concat。
  ```typescript
  let arr1=new Array<number>();
  let arr2=new Array<number>();
  let arr3=new Array<number>();
  arr3.push(1);
  arr1.concat(arr3, arr2);
  ```

### every方法签名变更
**ArkTS1.1版本签名：**  
  - `every(predicate: (value: T, index: number, array: T[]) => unknown, thisArg?: any): boolean`  
  - `every<S extends T>(predicate: (value: T, index: number, array: T[]) => value is S, thisArg?: any): this is S[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认值为当前实例对象，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | unknown | 返回值会被隐式转换为boolean，决定当前元素是否通过检查。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否通过所有元素都测试，true表示全部通过，false表示全部不通过。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    compare(value: number, index: number, arr: Array<number>) {
        return value < this.base;
    }
  }
  
  let arr: Array<number> = new Array<number>(1, 2, 3);
  let a = new C(2);
  let b = new C(4);
  arr.every(a.compare, a); // false
  arr.every(a.compare, b); // true
  ```

**ArkTS1.2版本签名：**  
  `every(predicate: (value: T, index: number, array: Array<T>) => boolean): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | T[] | 是 | 调用的原始数组。 |

  predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否通过检查，true表示当前元素通过检查，false表示未通过。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否通过所有元素都测试，true表示全部通过，false表示全部不通过。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    callEvery(arr: Array<number>): boolean {
        return arr.every((value: number, index: number, arr: Array<number>)=>{return value < this.base});
    }
  }
  
  function main() {
    let arr: Array<number> = new Array<number>(1, 2, 3);
    let a = new C(2);
    let b = new C(4);
    a.callEvery(arr); // false
    b.callEvery(arr); // true
  }
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### filter方法签名变更
**ArkTS1.1版本签名：**  
  - `filter(predicate: (value: T, index: number, array: T[]) => unknown, thisArg?: any): T[]`  
  - `filter<S extends T>(predicate: (value: T, index: number, array: T[]) => value is S, thisArg?: any): S[]`  
  - `filter<S extends T>(predicate: (value: T, index: number, array: readonly T[]) => value is S, thisArg?: any): S[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认值为undefined。 |

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
  | T[] | 通过测试的元素组成的新数组。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    compare(value: number, index: number, arr: Array<number>) {
        return value < this.base;
    }
  }
  
  let arr: Array<number> = new Array<number>(1, 2, 3);
  let a = new C(2);
  let b = new C(3);
  arr.every(a.compare, a); // [1]
  arr.every(a.compare, b); // [1, 2]
  ```

**ArkTS1.2版本签名：**  
  `filter(fn: (v: T, i: number, self: Array<T>) => boolean): Array<T>`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fn | function | 是 | 测试函数。 |

fn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | T | 是 | 当前被遍历的数组元素的值。 |
  | i | number | 是 | 当前元素的索引。 |
  | self | Array\<T\> | 是 | 调用的原始数组。 |
  | boolean | 是 | 表示是否过滤当前元素，true表示保留当前元素，false表示过滤掉当前元素。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Array\<T\> | 通过测试的元素组成的新数组。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    call(arr: Array<number>): Array<number> {
        return arr.filter((value: number, index: number, arr: Array<number>)=>{return value < this.base});
    }
  }
  
  function main() {
    let arr: Array<number> = new Array<number>(1, 2, 3);
    let a = new C(2);
    let b = new C(3);
    a.call(arr); // [1]
    b.call(arr); // [1, 2]
  }
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### find方法签名变更
**ArkTS1.1版本签名：**  
  - `find(predicate: (value: T, index: number, obj: T[]) => unknown, thisArg?: any): T | undefined`  
  - `find<S extends T>(predicate: (this: void, value: T, index: number, obj: T[]) => value is S, thisArg?: any): S | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | unknown | 返回值会被隐式转换为boolean，判断当前是否找到匹配项。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T | undefined | 第一个通过测试的元素，未找到则返回undefined。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    compare(value: number, index: number, arr: Array<number>) {
      return value >= this.base
    }
  }
  
  let arr: Array<number> = new Array<number>(1, 2, 3);
  let a = new C(2);
  let b = new C(3);
  arr.find(a.compare, a); // 2
  arr.find(a.compare, b); // 3
  ```

**ArkTS1.2版本签名：**  
  `find(predicate: (value: T, index: number, arr: Array<T>) => boolean): T | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Array\<T\> | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T | undefined | 第一个通过测试的元素，未找到则返回undefined。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    call(arr: Array<number>) {
        return arr.find((value: number, index: number, arr: Array<number>)=>{return value >= this.base});
    }
  }
  
  function main() {
  let arr: Array<number> = new Array<number>(1, 2, 3);
    let a = new C(2)
    let b = new C(3)
    a.call(arr); // 2
    b.call(arr); // 3
    
    console.info(a.call(arr));
    console.info(b.call(arr));
  }
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### findIndex方法签名变更
**ArkTS1.1版本签名：**  
  `findIndex(predicate: (value: T, index: number, obj: T[]) => unknown, thisArg?: any): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | obj | T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 第一个通过测试元素的索引，未找到则返回-1表示未找到满足的元素。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    compare(value: number, index: number, arr: Array<number>) {
      return value >= this.base;
    }
  }
  
  let arr: Array<number> = new Array<number>(1, 2, 3);
  let a = new C(2);
  let b = new C(3);
  arr.findIndex(a.compare, a); // 1
  arr.findIndex(a.compare, b); // 2
  ```

**ArkTS1.2版本签名：**  
  `findIndex(predicate: (value: T, index: number, array: Array<T>) => boolean): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Array\<T> | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 第一个通过测试元素的索引，未找到则返回-1表示未找到满足的元素。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    call(arr: Array<number>): number {
        return arr.findIndex((value: number, index: number, arr: Array<number>)=>{return value >= this.base});
    }
  }
  
  function main() {
    let arr: Array<number> = new Array<number>(1, 2, 3);
    let a = new C(2);
    let b = new C(3);
    a.call(arr); // 1
    b.call(arr); // 2
  }
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### flat方法移除
**ArkTS1.1版本签名：**  
  `flat<A, D extends number = 1>(this: A,depth?: D): FlatArray<A, D>[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | depth | D | 否 | 指定要提取嵌套数组的结构深度，默认值为1。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | FlatArray\<A, D\>[] | 包含所有子数组元素的新数组。 |

**示例：**  
  ```typescript
  type T = number | T[];
  let arr:Array<T> = [[1, [2]], 3, [4, 5]];
  arr.flat(2); // [1, 2, 3, 4, 5]
  ```

**ArkTS1.2版本签名：**  
  不支持。

- 适配建议：
  不使用flat，对于有明确返回值类型的具体的场景自己实现算法。

### flatMap方法移除
**ArkTS1.1版本签名：**  
  `flatMap<U, This = undefined> (callback: (this: This, value: T, index: number, array: T[]) => U | ReadonlyArray<U>,thisArg?: This): U[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | function | 是 | 生成新数组元素的函数。 |
  | thisArg | This | 否 | 执行callback时使用的this值，默认值为undefined。 |

callback函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | this | This | 是 | 由 thisArg 指定的上下文默认undefined。 |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Array\<T> | 是 | 调用的原始数组。 |

callback函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | U\|ReadonlyArray\<U> | 可返回单个值U或U类型的数组。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | U[] | 新数组。 |

**示例：**  
  ```typescript
  let arr = [[1, 2], 3, [4, 5]]
  arr.flatMap(
      (value, index, array) =>{
          return value;
      }
  )
  ```

**ArkTS1.2版本签名：**  
  不支持。

- 适配建议：
  不使用flatMap。

### forEach方法签名变更
**ArkTS1.1版本签名：**  
  `forEach(callbackfn: (value: T, index: number, array: T[]) => void, thisArg?: any): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 为每个元素执行的函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认值为undefined。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | T[] | 是 | 调用的原始数组。 |


**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    foo(value: number, index: number, arr: Array<number>) {
        console.info(value + this.base)
    }
  }
  
  let arr: Array<number> = new Array<number>(1, 2, 3);
  let a = new C(2);
  let b = new C(3);
  arr.forEach(a.foo, a);
  arr.forEach(a.foo, b);
  ```

**ArkTS1.2版本签名：**  
  `forEach(callbackfn: (value: T, index: number, array: Array<T>) => void): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 为每个元素执行的函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Array\<T> | 是 | 调用的原始数组。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    call(arr: Array<number>) {
        return arr.forEach((value: number, index: number, arr: Array<number>)=>{console.info(value + this.base)});
    }
  }
  
  function main() {
    let arr: Array<number> = new Array<number>(1, 2, 3);
    let a = new C(2);
    let b = new C(3);
    a.call(arr);
    b.call(arr);
  }
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### map方法签名变更
**ArkTS1.1版本签名：**  
  `map<U>(callbackfn: (value: T, index: number, array: T[]) => U, thisArg?: any): U[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 生成新数组元素的函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认值为undefined。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | T[] | 是 | 调用的原始数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | U | 映射后的值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | U[] | 新数组。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    foo(value: number, index: number, arr: Array<number>) {
        return value + this.base;
    }
  }
  
  let arr: Array<number> = new Array<number>(1, 2, 3);
  let a = new C(2);
  let b = new C(3);
  arr.map(a.foo, a);
  arr.map(a.foo, b);
  ```

**ArkTS1.2版本签名：**  
  `map<U>(callbackfn: (value: T, index: number, arr: Array<T>) => U): U[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 生成新数组元素的函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Array\<T> | 是 | 调用的原始数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | U | 映射后的值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | U[] | 新数组。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    call(arr: Array<number>): Array<number> {
        return arr.map((value: number, index: number, arr: Array<number>)=>{return value + this.base})
    }
  }
  
  function main() {
    let arr: Array<number> = new Array<number>(1, 2, 3);
    let a = new C(2);
    let b = new C(3);
    a.call(arr);
    b.call(arr);
  }
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### from方法签名变更
**ArkTS1.1版本签名：**  
  `static from<T, U>(arrayLike: ArrayLike<T>, mapfn: (v: T, k: number) => U, thisArg?: any): U[]`
  `static from<T, U>(iterable: Iterable<T> | ArrayLike<T>, mapfn: (v: T, k: number) => U, thisArg?: any): U[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | arrayLike | ArrayLike\<T\> | 是 | 要转换为数组的对象。 |
  | mapfn | function | 是 | map函数。 |
  | thisArg | any | 否 | 执行mapfn时使用的this值，默认值为undefined。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | T | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | U | 返回的一个值，作为新Array的元素 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | U[] | 新数组。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    foo(value: number, index: number) {
        return value + this.base;
    }
  }
  
  let arr: Array<number> = new Array<number>(1, 2, 3);
  let a = new C(2);
  let b = new C(3);
  let arr2 = Array.from(arr, a.foo, a);
  let arr3 = Array.from(arr, a.foo, b);
  ```

**ArkTS1.2版本签名：**  
  `static from<T, U>(arrayLike: ArrayLike<T>, mapfn: (v: T, k: number) => U): U[]`
  `static from<T, U>(iterable: Iterable<T>, mapfn: (v: T, k: number) => U): U[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | arrayLike | ArrayLike\<T\> | 是 | 要转换为数组的对象。 |
  | mapfn | function | 是 | map函数。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | T | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | U | 返回的一个值，作为新Array的元素 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | U[] | 新数组。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    call(arr: Array<number>): Array<number> {
        return Array.from(arr, (value: number, index: number)=>{return value + this.base})
    }
  }
  
  function main() {
    let arr: Array<number> = new Array<number>(1, 2, 3);
    let a = new C(2);
    let b = new C(3);
    a.call(arr);
    b.call(arr);
  }
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### some方法签名变更
**ArkTS1.1版本签名：**  
  `some(predicate: (value: T, index: number, array: T[]) => unknown, thisArg?: any): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | unknown | 返回值会被隐式转换为boolean，判断当前元素是否满足predicate。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否通过所有元素都测试，true表示全部通过，false表示全部不通过。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    foo(value: number, index: number, arr: ReadonlyArray<number>) {
        return value > this.base;
    }
  }
  
  let arr: ReadonlyArray<number> = new Array<number>(1, 2, 3);
  let a = new C(2);
  let b = new C(3);
  arr.some(a.foo, a);
  arr.some(a.foo, b);
  ```

**ArkTS1.2版本签名：**  
  `some(predicate: (value: T, index: number, array: T[]) => boolean): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | T[] | 是 | 调用的原始数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否满足`predicate`，`true`表示满足，`false`表示不满足。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否通过所有元素都测试，true表示全部通过，false表示全部不通过。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    call(arr: ReadonlyArray<number>) {
        return arr.some(
            (value: number, index: number, arr: ReadonlyArray<number>)=>{return value > this.base}
        );
    }
  }
  let arr: ReadonlyArray<number> = new Array<number>(1, 2, 3);
  let a = new C(2);
  let b = new C(3);
  console.info(a.call(arr));
  console.info(b.call(arr));
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### 数组长度构造函数变更
**ArkTS1.1版本签名：**  
  `<T>(arrayLength?: number): T[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | arrayLength | number | 否 | 数组长度，默认值为0。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T[] | 新创建的数组。 |

**示例：**  
  ```typescript
  let a = Array<number>(10)
  function f(a:ArrayConstructor) {
      a(10);
  }
  ```

**ArkTS1.2版本签名：**  
  `static Array.invoke(arrayLength?: number): T[]`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | arrayLength | number | 否 | 数组长度，默认值为0。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | T[] | 新创建的数组。 |

**示例：**  
  ```typescript
  let a = Array<number>(10);
  function f() {
     Array<number>(10);
  }
  ```

- 适配建议：
  不要使用Constructor类型，使用invoke或new的方式直接创建对象。
