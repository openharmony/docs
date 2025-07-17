# Float32Array

## 变更梗概
- [Symbol.iterator变更](#symboliterator变更)
- [every变更](#every变更)
- [filter变更](#filter变更)
- [find变更](#find变更)
- [findIndex变更](#findindex变更)
- [forEach变更](#foreach变更)
- [map变更](#map变更)
- [some变更](#some变更)
- [from静态方法变更1](#from静态方法变更1)
- [from静态方法变更2](#from静态方法变更2)

## 变更详情

### Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<number>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `IterableIterator<number>` | Float32Array的迭代器。 |

**示例：**  
  ```typescript
  let a = new Float32Array(3);
  let iter = Reflect.get(a, Symbol.iterator);
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<number>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `IterableIterator<number>` | Float32Array的迭代器。 |

**示例：**  
  ```typescript
  let a = new Float32Array(3);
  let iter = a.$_iterator();
  ```

**适配建议：** 
  建议仅使用for...of访问迭代器，不要显示访问迭代器。


### every变更
**ArkTS1.1版本签名：**  
  `every(predicate: (value: number, index: number, array: Float32Array) => unknown, thisArg?: any): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |
  | `thisArg` | `any` | 否 | 执行`predicate`时`this`指向的对象，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的number值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array对象。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | unknown | 返回值会被隐式转换为boolean，决定当前元素是否通过检查。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `boolean` | 表示是否所有元素都通过测试。true表示全部都通过，false表示全部都不通过。 |

**示例：**  
  ```typescript
  class C {
    comp(element: number, index: number, array: Float32Array): boolean {
      return element > this.base;
    }
    base: number;
    constructor(base: number) {
      this.base = base;
    }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let result = arr.every(new C(1).comp, new C(2));
  ```

**ArkTS1.2版本签名：**  
  `every(predicate: (value: number, index: number, array: Float32Array) => boolean): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的number值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array对象。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否通过检查，true表示当前元素通过检查，false表示未通过。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `boolean` | 表示是否所有元素都通过测试。true表示全部都通过，false表示全部都不通过。 |

**示例：**  
  ```typescript
  class C {
      base: number;
      constructor(base:number) {
          this.base = base;
      }
      callEvery(arr: Float32Array) {
          return arr.every((value: number, index: number, arr: Float32Array)=>{return value < this.base})
      }
  }
  function main() {
    let arr: Float32Array = new Float32Array([1, 2, 3]);
    let a = new C(2)
    let b = new C(4)
    a.callEvery(arr) // false
    b.callEvery(arr) // true
  }
  ```

**适配建议：** 
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### filter变更
**ArkTS1.1版本签名：**  
  `filter(predicate: (value: number, index: number, array: Float32Array) => any, thisArg?: any): Float32Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |
  | `thisArg` | `any` | 否 | 执行 `predicate` 时 `this` 指向的对象，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | any | 是 | 返回值会被隐式转换为boolean，决定当前元素是否会被过滤。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `Float32Array` | 包含所有满足`predicate`的元素的新数组。 |

**示例：**  
  ```typescript
  class C {
    comp(element: number, index: number, array: Float32Array): boolean {
      return element > this.base;
    }
    base: number;
    constructor(base: number) {
      this.base = base;
    }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let result = arr.filter(new C(1).comp, new C(2));
  ```

**ArkTS1.2版本签名：**  
  `filter(predicate: (value: number, index: number, array: Float32Array) => boolean): Float32Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否过滤当前元素，true表示保留当前元素，false表示过滤掉当前元素。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `Float32Array` | 包含所有满足`predicate`的元素的新数组。 |

**示例：**  
  ```typescript
  class C {
      base: number;
      constructor(base:number) {
          this.base = base;
      }
      call(arr: Float32Array) {
          return arr.filter((value: number, index: number, arr: Float32Array)=>{return value < this.base})
      }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let a = new C(2)
  let b = new C(3)
  a.call(arr) // [1]
  b.call(arr) // [1, 2]
  ```

**适配建议：** 
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### find变更
**ArkTS1.1版本签名：**  
  `find(predicate: (value: number, index: number, obj: Float32Array) => boolean, thisArg?: any): number | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |
  | `thisArg` | `any` | 否 | 执行`predicate`时`this`指向的对象，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `number \| undefined` | 如果找到满足`predicate`的元素，则返回该元素，否则返回`undefined`。 |

**示例：**  
  ```typescript
  class C {
    comp(element: number, index: number, array: Float32Array): boolean {
      return element > this.base;
    }
    base: number;
    constructor(base: number) {
      this.base = base;
    }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let result = arr.find(new C(1).comp, new C(2));
  ```

**ArkTS1.2版本签名：**  
  `find(predicate: (value: number, index: number, obj: Float32Array) => boolean): number | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `number | undefined` | 如果找到满足`predicate`的元素，则返回该元素，否则返回`undefined`。 |

**示例：**  
  ```typescript
  class C {
      base: number;
      constructor(base:number) {
          this.base = base;
      }
      call(arr: Float32Array) {
          return arr.find((value: number, index: number, arr: Float32Array)=>{return value >= this.base})
      }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let a = new C(2)
  let b = new C(3)
  a.call(arr) // 2
  b.call(arr) // 3
  
  console.info(a.call(arr))
  console.info(b.call(arr))
  ```

**适配建议：** 
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### findIndex变更
**ArkTS1.1版本签名：**  
  `findIndex(predicate: (value: number, index: number, array: Float32Array) => boolean, thisArg?: any): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |
  | `thisArg` | `any` | 否 | 执行`predicate`时`this`指向的对象，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `number` | 如果找到满足`predicate`的元素，则返回该元素的索引，否则返回`-1`表示未找到满足的元素。 |

**示例：**  
  ```typescript
  class C {
    comp(element: number, index: number, array: Float32Array): boolean {
      return element > this.base;
    }
    base: number;
    constructor(base: number) {
      this.base = base;
    }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let result = arr.findIndex(new C(1).comp, new C(2));
  ```

**ArkTS1.2版本签名：**  
  `findIndex(predicate: (value: number, index: number, array: Float32Array) => boolean): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `number` | 如果找到满足`predicate`的元素，则返回该元素的索引，否则返回`-1`表示未找到满足的元素。 |

**示例：**  
  ```typescript
  class C {
      base: number;
      constructor(base:number) {
          this.base = base;
      }
      call(arr: Float32Array) {
          return arr.findIndex((value: number, index: number, arr: Float32Array)=>{return value >= this.base})
      }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let a = new C(2)
  let b = new C(3)
  a.call(arr) // 1
  b.call(arr) // 2
  ```

**适配建议：** 
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### forEach变更
**ArkTS1.1版本签名：**  
  `forEach(callbackfn: (value: number, index: number, array: Float32Array) => void, thisArg?: any): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `callbackfn` | `function` | 是 | 为数组中的每个元素执行的函数。 |
  | `thisArg` | `any` | 否 | 执行`callbackfn`时`this`指向的对象，默认值为undefined。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |


**示例：**  
  ```typescript
  class C {
    comp(element: number, index: number, array: Float32Array): boolean {
      return element > this.base;
    }
    base: number;
    constructor(base: number) {
      this.base = base;
    }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let result = arr.forEach(new C(1).comp, new C(2));
  ```

**ArkTS1.2版本签名：**  
  `forEach(callbackfn: (value: number, index: number, array: Float32Array) => void): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `callbackfn` | `function` | 是 | 为数组中的每个元素执行的函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

**示例：**  
  ```typescript
  class C {
      base: number;
      constructor(base:number) {
          this.base = base;
      }
      call(arr: Float32Array) {
          return arr.forEach((value: number, index: number, arr: Float32Array)=>{console.info(value + this.base)})
      }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let a = new C(2)
  let b = new C(3)
  a.call(arr)
  b.call(arr)
  ```

**适配建议：** 
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### map变更
**ArkTS1.1版本签名：**  
  `map(callbackfn: (value: number, index: number, array: Float32Array) => number, thisArg?: any): Float32Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `callbackfn` | `function` | 是 | 为数组中的每个元素调用的函数，返回新数组中的元素。 |
  | `thisArg` | `any` | 否 | 执行`callbackfn`时`this`指向的对象，默认值为undefined。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 当前函数计算后新得到的number值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `Float32Array` | 一个新的 Float32Array，包含`callbackfn`对每个元素的调用结果。 |

**示例：**  
  ```typescript
  class C {
    map(element: number, index: number, array: Float32Array): number {
      return this.base;
    }
    base: number;
    constructor(base: number) {
      this.base = base;
    }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let result = arr.map(new C(1).map, new C(2));
  ```

**ArkTS1.2版本签名：**  
  `map(callbackfn: (value: number, index: number, array: Float32Array) => number): Float32Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `callbackfn` | `function` | 是 | 为数组中的每个元素调用的函数，返回新数组中的元素。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 当前函数计算后新得到的number值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `Float32Array` | 一个新的Float32Array，包含`callbackfn`对每个元素的调用结果。 |

**示例：**  
  ```typescript
  class C {
      base: number;
      constructor(base:number) {
          this.base = base;
      }
      call(arr: Float32Array) {
          return arr.map((value: number, index: number, arr: Float32Array)=>{return value + this.base})
      }
  }
  function main() {
    let arr: Float32Array = new Float32Array([1, 2, 3]);
    let a = new C(2)
    let b = new C(3)
    a.call(arr)
    b.call(arr)
  }
  ```

**适配建议：** 
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### some变更
**ArkTS1.1版本签名：**  
  `some(predicate: (value: number, index: number, array: Float32Array) => unknown, thisArg?: any): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |
  | `thisArg` | `any` | 否 | 执行`predicate`时`this`指向的对象，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否满足`predicate`，`true`表示满足，`false`表示不满足。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `boolean` | 表示是否至少有一个元素通过测试。true表示至少有一个元素通过测试，false表示没有任何元素通过。 |

**示例：**  
  ```typescript
  class C {
    comp(element: number, index: number, array: Float32Array): boolean {
      return element > this.base;
    }
    base: number;
    constructor(base: number) {
      this.base = base;
    }
  }
  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let result = arr.some(new C(1).comp, new C(2));
  ```

**ArkTS1.2版本签名：**  
  `some(predicate: (value: number, index: number) => boolean): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Float32Array | 是 | 调用的原始Float32Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否满足`predicate`，`true`表示满足，`false`表示不满足。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `boolean` | 表示是否至少有一个元素通过测试。true表示至少有一个元素通过测试，false表示没有任何元素通过。 |

**示例：**  
  ```typescript
  class C {
      base: number;
      constructor(base:number) {
          this.base = base;
      }
      call(arr: Float32Array) {
          return arr.some((value: number, index: number, arr: Float32Array)=>{return value > this.base})
      }
  }
  function main() {
    let arr: Float32Array = new Float32Array([1, 2, 3]);
    let a = new C(2)
    let b = new C(3)
    a.call(arr)
    b.call(arr)
  }
  ```

**适配建议：** 
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### from静态方法变更1
**ArkTS1.1版本签名：**  
  `static from<T>(arrayLike: ArrayLike<T>, mapfn: (v: T, k: number) => number, thisArg?: any): Float32Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `arrayLike` | `ArrayLike<T>` | 是 | 类似数组或可迭代的对象。 |
  | `mapfn` | `function` | 是 | 为`arrayLike`中的每个元素调用的函数，返回新数组中的元素。 |
  | `thisArg` | `any` | 否 | 执行`mapfn`时`this`指向的对象，默认值为undefined。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | T | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回的一个number类型值，作为新Float32Array的元素 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `Float32Array` | 一个新的 Float32Array，包含`mapfn`对`arrayLike`中每个元素的调用结果。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    foo(value: number, index: number) {
      return value + this.base
    }
  }

  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  let arr2 = Float32Array.from(arr, a.foo, a)
  let arr3 = Float32Array.from(arr, a.foo, b)
  ```

**ArkTS1.2版本签名：**  
  `static from<T>(arrayLike: ArrayLike<T>, mapfn: (v: T, k: number) => number): Float32Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `arrayLike` | `ArrayLike<U>` | 是 | 类似数组或可迭代的对象。 |
  | `mapfn` | `function` | 是 | 为`arrayLike`中的每个元素调用的函数，返回新数组中的元素。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | T | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回的一个number类型值，作为新Float32Array的元素 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `Float32Array` | 一个新的 Float32Array，包含`mapfn`对`arrayLike`中每个元素的调用结果。 |

**示例：**  
  ```typescript
  class C {
      base: number;
      constructor(base:number) {
          this.base = base;
      }
      call(arr:Float32Array) {
          return Array.from(arr, (value: number, index: number)=>{return value + this.base})
      }
  }
  function main() {
    let arr: Float32Array = new Float32Array([1, 2, 3]);
    let a = new C(2)
    let b = new C(3)
    a.call(arr)
    b.call(arr)
  }
  ```

**适配建议：** 
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### from静态方法变更2
**ArkTS1.1版本签名：**  
  `static from(arrayLike: Iterable<number>, mapfn?: (v: number, k: number) => number, thisArg?: any): Float32Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `arrayLike` | `Iterable<number>` | 是 | 可迭代的数值集合 |
  | `mapfn` | `function` | 否 | 选映射函数，对每个元素进行转换处理，默认undefined。 |
  | `thisArg` | `any` | 否 | 执行`mapfn`时`this`指向的对象，默认undefined。|

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | number | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回的一个number类型值，作为新Float32Array的元素 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `Float32Array` | 从指定数据源创建的新的 64 位浮点型数组。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    foo(value: number, index: number) {
      return value + this.base
    }
  }

  let arr: Float32Array = new Float32Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  let arr2 = Float32Array.from(arr, a.foo, a)
  let arr3 = Float32Array.from(arr, a.foo, b)
  ```

**ArkTS1.2版本签名：**  
  `static from(arrayLike: Iterable<number>, mapfn?: (v: number, k: number) => number): Float32Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `arrayLike` | `Iterable<number>` | 是 | 可迭代的数值集合 |
  | `mapfn` | `function` | 否 | 选映射函数，对每个元素进行转换处理，默认undefined。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | number | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回的一个number类型值，作为新Float32Array的元素 |

**返回值：**
  |  类型  | 说明 |
  | -------- | -------- |
  | `Float32Array` | 从指定数据源创建的新的 64 位浮点型数组。 |

**示例：**  
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
        this.base = base;
    }
    call(arr: Float32Array) {
        return Array.from(arr, (value: number, index: number)=>{return value + this.base})
    }
  }
  function main() {
    let arr: Float32Array = new Float32Array([1, 2, 3]);
    let a = new C(2)
    let b = new C(3)
    a.call(arr)
    b.call(arr)
  }
  ```

**适配建议：** 
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。
