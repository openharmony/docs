# BigInt64Array

## 变更梗概
- [Symbol.iterator变更](#symboliterator变更)
- [every方法变更](#every方法变更)
- [filter方法变更](#filter方法变更) 
- [find方法变更](#find方法变更)
- [findIndex方法变更](#findindex方法变更)
- [forEach方法变更](#foreach方法变更)
- [map方法变更](#map方法变更)
- [some方法变更](#some方法变更)
- [from静态方法变更](#from静态方法变更)

## 变更详情

### Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<bigint>`

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | `IterableIterator<bigint>` | BigInt64Array的迭代器。 |

**示例：**  
  ```typescript
  let a = new BigInt64Array(3);
  let iter = Reflect.get(a, Symbol.iterator);
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<bigint>`

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | `IterableIterator<bigint>` | BigInt64Array的迭代器。 |

**示例：**  
  ```typescript
  let a = new BigInt64Array(3);
  let iter = a.$_iterator();
  ```

- 适配建议：
  建议仅使用for...of访问迭代器，不要显示访问迭代器。

### every方法变更
**ArkTS1.1版本签名：**  
  `every(predicate: (value: bigint, index: number, array: BigInt64Array) => boolean, thisArg?: any): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | function | 是 | 用于测试每个元素的函数。 |
  | `thisArg` | `any` | 否 | 执行`predicate`时`this`指向的对象，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的bigint值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array对象。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否通过检查，true表示当前元素通过检查，false表示未通过。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `boolean` | 表示数组中的所有元素是否都满足`predicate`，`true`表示全部满足，`false`表示全部不满足。 |

**示例：**  
  ```typescript
  class C {
    comp(element: bigint, index: number, array: BigInt64Array): boolean {
      return element > this.base;
    }
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.every(new C(1n).comp, new C(2n));
  ```

**ArkTS1.2版本签名：**  
  `every(predicate: (value: bigint, index: number, array: BigInt64Array) => boolean): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的bigint值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array对象。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否通过检查，true表示当前元素通过检查，false表示未通过。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `boolean` | 表示数组中的所有元素是否都满足`predicate`，`true`表示全部满足，`false`表示全部不满足。 |

**示例：**  
  ```typescript
  class C {
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let o = new C(2n);
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.every((element: bigint, index: number, array: BigInt64Array) => {
      return element > o.base;
  });
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### filter方法变更
**ArkTS1.1版本签名：**  
  `filter(predicate: (value: bigint, index: number, array: BigInt64Array) => any, thisArg?: any): BigInt64Array`

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
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | any | 返回值会被隐式转换为boolean，决定当前元素是否会被过滤。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `BigInt64Array` | 包含所有满足`predicate`的元素的新数组。 |

**示例：**  
  ```typescript
  class C {
    comp(element: bigint, index: number, array: BigInt64Array): boolean {
      return element > this.base;
    }
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.filter(new C(1n).comp, new C(2n));
  ```

**ArkTS1.2版本签名：**  
  `filter(predicate: (value: bigint, index: number, array: BigInt64Array) => boolean): BigInt64Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否过滤当前元素，true表示保留当前元素，false表示过滤掉当前元素。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `BigInt64Array` | 包含所有满足`predicate`的元素的新数组。 |

**示例：**  
  ```typescript
  class C {
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let o = new C(2n);
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.filter((element: bigint, index: number, array: BigInt64Array) => {
      return element > o.base;
  });
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### find方法变更
**ArkTS1.1版本签名：**  
  `find(predicate: (value: bigint, index: number, array: BigInt64Array) => boolean, thisArg?: any): bigint | undefined`

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
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `bigint \| undefined` | 如果找到满足`predicate`的元素，则返回该元素，否则返回`undefined`。 |

**示例：**  
  ```typescript
  class C {
    comp(element: bigint, index: number, array: BigInt64Array): boolean {
      return element > this.base;
    }
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.find(new C(1n).comp, new C(2n));
  ```

**ArkTS1.2版本签名：**  
  `find(predicate: (value: bigint, index: number, array: BigInt64Array) => boolean): bigint | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `bigint | undefined` | 如果找到满足`predicate`的元素，则返回该元素，否则返回`undefined`。 |

**示例：**  
  ```typescript
  class C {
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let o = new C(2n);
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.find((element: bigint, index: number, array: BigInt64Array) => {
      return element > o.base;
  });
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### findIndex方法变更
**ArkTS1.1版本签名：**  
  `findIndex(predicate: (value: bigint, index: number, array: BigInt64Array) => boolean, thisArg?: any): number`

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
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

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
    comp(element: bigint, index: number, array: BigInt64Array): boolean {
      return element > this.base;
    }
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.findIndex(new C(1n).comp, new C(2n));
  ```

**ArkTS1.2版本签名：**  
  `findIndex(predicate: (value: bigint, index: number, array: BigInt64Array) => boolean): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `number` | 如果找到满足`predicate`的元素，则返回该元素的索引，否则返回 `-1`表示未找到满足的元素。 |

**示例：**  
  ```typescript
  class C {
    comp(element: bigint, index: number, array: BigInt64Array) :boolean{
      return element > this.base;
    }
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.findIndex(new C(1n).comp);
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### forEach方法变更
**ArkTS1.1版本签名：**  
  `forEach(callbackfn: (value: bigint, index: number, array: BigInt64Array) => void, thisArg?: any): void`

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
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

**示例：**  
  ```typescript
  class C {
    comp(element: bigint, index: number, array: BigInt64Array): boolean {
      return element > this.base;
    }
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.forEach(new C(1n).comp, new C(2n));
  ```

**ArkTS1.2版本签名：**  
  `forEach(callbackfn: (value: bigint, index: number, array: BigInt64Array) => void): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `callbackfn` | `function` | 是 | 为数组中的每个元素执行的函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

**示例：**  
  ```typescript
  class C {
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }

  function main() {
    let o = new C(2n);
    let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
    arr.forEach((element: bigint, index: number, array: BigInt64Array) => {
        console.info(element, index);
    });
  }
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### map方法变更
**ArkTS1.1版本签名：**  
  `map(callbackfn: (value: bigint, index: number, array: BigInt64Array) => bigint, thisArg?: any): BigInt64Array`

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
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | bigint | 当前函数计算后新得到的bigint值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `BigInt64Array` | 一个新的 BigInt64Array，包含`callbackfn`对每个元素的调用结果。 |

**示例：**  
  ```typescript
  class C {
    map(element: bigint, index: number, array: BigInt64Array): bigint {
      return this.base;
    }
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.map(new C(1n).map, new C(2n));
  ```

**ArkTS1.2版本签名：**  
  `map(callbackfn: (value: bigint, index: number, array: BigInt64Array) => bigint): BigInt64Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `callbackfn` | `function` | 是 | 为数组中的每个元素调用的函数，返回新数组中的元素。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | bigint | 当前函数计算后新得到的bigint值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `BigInt64Array` | 一个新的BigInt64Array，包含`callbackfn`对每个元素的调用结果。 |

**示例：**  
  ```typescript
  class C {
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let o = new C(2n);
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.map((element: bigint, index: number, array: BigInt64Array) => {
      return o.base;
  });
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### some方法变更
**ArkTS1.1版本签名：**  
  `some(predicate: (value: bigint, index: number, array: BigInt64Array) => boolean, thisArg?: any): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |
  | `thisArg` | `any` | 否 | 执行 `predicate` 时 `this` 指向的对象，默认值为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否满足`predicate`，`true`表示满足，`false`表示不满足。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `boolean` | 表示数组中至少有一个元素满足`predicate`，`true`表示有，`false`表示没有。 |

**示例：**  
  ```typescript
  class C {
    comp(element: bigint, index: number, array: BigInt64Array): boolean {
      return element > this.base;
    }
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.some(new C(1n).comp, new C(2n));
  ```

**ArkTS1.2版本签名：**  
  `some(predicate: (value: bigint, index: number, array: BigInt64Array) => boolean): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `predicate` | `function` | 是 | 用于测试每个元素的函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | bigint | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | BigInt64Array | 是 | 调用的原始BigInt64Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前元素是否满足`predicate`，`true`表示满足，`false`表示不满足。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `boolean` | 表示数组中至少有一个元素满足`predicate`，`true`表示有，`false`表示没有。 |

**示例：**  
  ```typescript
  class C {
    base: bigint;
    constructor(base: bigint) {
      this.base = base;
    }
  }
  let o = new C(2n);
  let arr: BigInt64Array = new BigInt64Array([1n, 2n, 3n]);
  let result = arr.some((element: bigint, index: number, array: BigInt64Array) => {
      return element > o.base;
  });
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### from静态方法变更
**ArkTS1.1版本签名：**  
  `static from<U>(arrayLike: ArrayLike<U>, mapfn: (v: U, k: number) => bigint, thisArg?: any): BigInt64Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `arrayLike` | `ArrayLike<U>` | 是 | 类似数组或可迭代的对象。 |
  | `mapfn` | `function` | 是 | 为`arrayLike`中的每个元素调用的函数，返回新数组中的元素。 |
  | `thisArg` | `any` | 否 | 执行`mapfn`时`this`指向的对象，默认值为undefined。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | U | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | bigint | 返回的一个bigint类型值，作为新BigInt64Array的元素 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `BigInt64Array` | 一个新的BigInt64Array，包含`mapfn`对`arrayLike`中每个元素的调用结果。 |

**示例：**  
  ```typescript
  class C {
    add(v: number, k: number): bigint {
      return BigInt(v + this.offset);
    }
    offset: number;
    constructor(offset: number) {
      this.offset = offset;
    }
  }

  const newArr = BigInt64Array.from<number>([1, 2, 3], new C(1).add, new C(2)); // [3,4,5]
  ```

**ArkTS1.2版本签名：**  
  `static from<U>(arrayLike: ArrayLike<U>, mapfn: (v: U, k: number) => bigint): BigInt64Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | `arrayLike` | `ArrayLike<U>` | 是 | 类似数组或可迭代的对象。 |
  | `mapfn` | `function` | 是 | 为`arrayLike`中的每个元素调用的函数，返回新数组中的元素。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | U | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | bigint | 返回的一个bigint类型值，作为新BigInt64Array的元素 |


**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | `BigInt64Array` | 一个新的BigInt64Array，包含`mapfn` 对`arrayLike`中每个元素的调用结果。 |

**示例：**  
  ```typescript
  class C {
    offset: number;
    constructor(offset: number) {
      this.offset = offset;
    }
  }

  function main() {
    const origArr: Array<number> = new Array<number>(1,2,3);
    let o = new C(2);
    const newArr: BigInt64Array = BigInt64Array.from<number>(origArr, (v: number, k: number) => {
        return new BigInt(v + o.offset);
    }); // [3,4,5]
    console.info(newArr);
  }
  ```

- 适配建议：
  删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。
