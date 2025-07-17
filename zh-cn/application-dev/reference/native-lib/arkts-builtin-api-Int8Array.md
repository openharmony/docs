# Int8Array

## 变更梗概
- [Symbol.iterator变更](#symboliterator变更)
- [every方法变更](#every方法变更) 
- [filter方法变更](#filter方法变更)
- [find方法变更](#find方法变更)
- [findIndex方法变更](#findindex方法变更)
- [forEach方法变更](#foreach方法变更)
- [map方法变更](#map方法变更)
- [some方法变更](#some方法变更)
- [from静态方法变更1](#from静态方法变更1)
- [from静态方法变更2](#from静态方法变更2)

## 变更详情

### Symbol.iterator变更
**ArkTS1.1版本签名：**  
  `[Symbol.iterator](): IterableIterator<number>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<number> | 返回数组的迭代器对象。 |

**示例：**  
  ```typescript
  let a = new Int8Array(3);
  let iter = Reflect.get(a, Symbol.iterator);
  ```

**ArkTS1.2版本签名：**  
  `$_iterator(): IterableIterator<number>`

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator\<number> | 返回数组的迭代器对象。 |

**示例：**  
  ```typescript
  let a = new Int8Array(3);
  let iter = a.$_iterator();
  ```

**适配建议：** 建议仅使用for...of访问迭代器，不要显示访问迭代器。

### every方法变更
**ArkTS1.1版本签名：**  
  `every(predicate: (value: number, index: number, array: Int8Array) => unknown, thisArg?: any): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的number值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Int8Array | 是 | 调用的原始Int8Array对象。 |

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
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    compare(value: number, index: number, arr: Int8Array) {
      return value < this.base
    }
  }
  
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(4);
  arr.every(a.compare, a);
  arr.every(a.compare, b);
  ```

**ArkTS1.2版本签名：**  
  `every(predicate: (value: number, index: number, array: Int8Array) => boolean): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的number值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Int8Array | 是 | 调用的原始Int8Array对象。 |

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
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    callEvery(arr: Int8Array) {
      return arr.every((value: number, index: number, arr: Int8Array)=>{return value < this.base})
    }
  }
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(4);
  a.callEvery(arr); // false
  b.callEvery(arr); // true
  ```

**适配建议：** 删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### filter方法变更
**ArkTS1.1版本签名：**  
  `filter(predicate: (value: number, index: number, array: Int8Array) => any, thisArg?: any): Int8Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Int8Array | 是 | 调用的原始Int8Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | any | 返回值会被隐式转换为boolean，决定当前元素是否会被过滤。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Int8Array | 通过测试的元素组成的新数组。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    compare(value: number, index: number, arr: Int8Array) {
      return value < this.base
    }
  }
  
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  arr.filter(a.compare, a);
  arr.filter(a.compare, b);
  ```

**ArkTS1.2版本签名：**  
  `filter(predicate: (value: number, index: number, array: Int8Array) => boolean): Int8Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Int8Array | 是 | 调用的原始Int8Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否过滤当前元素，true表示保留当前元素，false表示过滤掉当前元素。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Int8Array | 通过测试的元素组成的新数组。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    call(arr: Int8Array) {
      return arr.filter((value: number, index: number, arr: Int8Array)=>{return value < this.base})
    }
  }
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  a.call(arr); // [1]
  b.call(arr); // [1, 2]
  ```

**适配建议：** 删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### find方法变更
**ArkTS1.1版本签名：**  
  `find(predicate: (value: number, index: number, obj: Int8Array) => boolean, thisArg?: any): number | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | obj | Int8Array | 是 | 调用的原始Int8Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number \| undefined | 返回第一个符合条件的元素，否则返回undefined。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    compare(value: number, index: number, arr: Int8Array) {
      return value >= this.base
    }
  }
  
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  arr.find(a.compare, a);
  arr.find(a.compare, b);
  ```

**ArkTS1.2版本签名：**  
  `find(predicate: (value: number, index: number, obj: Int8Array) => boolean): number | undefined`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | obj | Int8Array | 是 | 调用的原始Int8Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number \| undefined | 返回第一个符合条件的元素，否则返回undefined。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    call(arr: Int8Array) {
      return arr.find((value: number, index: number, arr: Int8Array)=>{return value >= this.base})
    }
  }
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  a.call(arr); // 2
  b.call(arr); // 3
  ```

**适配建议：** 删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### findIndex方法变更
**ArkTS1.1版本签名：**  
  `findIndex(predicate: (value: number, index: number, obj: Int8Array) => boolean, thisArg?: any): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | obj | Int8Array | 是 | 调用的原始Int8Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回第一个符合条件的元素的索引，否则返回-1表示未找到满足的元素。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    compare(value: number, index: number, arr: Int8Array) {
      return value >= this.base
    }
  }
  
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  arr.findIndex(a.compare, a);
  arr.findIndex(a.compare, b);
  ```

**ArkTS1.2版本签名：**  
  `findIndex(predicate: (value: number, index: number, obj: Int8Array) => boolean): number`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | obj | Int8Array | 是 | 调用的原始Int8Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示当前是否找到匹配项，true表示找到，false表示没找到。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回第一个符合条件的元素的索引，否则返回-1表示未找到满足的元素。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    call(arr: Int8Array) {
      return arr.findIndex((value: number, index: number, arr: Int8Array)=>{return value >= this.base})
    }
  }
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  a.call(arr); // 1
  b.call(arr); // 2
  ```

**适配建议：** 删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### forEach方法变更
**ArkTS1.1版本签名：**  
  `forEach(callbackfn: (value: number, index: number, array: Int8Array) => void, thisArg?: any): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 遍历函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认为undefined。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Int8Array | 是 | 调用的原始Int8Array数组。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    foo(value: number, index: number, arr: Int8Array) {
      console.info((value + this.base).toString())
    }
  }
  
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  arr.forEach(a.foo, a);
  arr.forEach(a.foo, b);
  ```

**ArkTS1.2版本签名：**  
  `forEach(callbackfn: (value: number, index: number, array: Int8Array) => void): void`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 遍历函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Int8Array | 是 | 调用的原始Int8Array数组。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    call(arr: Int8Array) {
      return arr.forEach((value: number, index: number, arr: Int8Array)=>{console.info(value + this.base)})
    }
  }
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  a.call(arr);
  b.call(arr);
  ```

**适配建议：** 删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### map方法变更
**ArkTS1.1版本签名：**  
  `map(callbackfn: (value: number, index: number, array: Int8Array) => number, thisArg?: any): Int8Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 映射函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认为undefined。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Int8Array | 是 | 调用的原始Int8Array数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 当前函数计算后新得到的number值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Int8Array | 新数组，每个元素都是回调函数的返回值。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    foo(value: number, index: number, arr: Int8Array) {
      return value + this.base
    }
  }
  
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  arr.map(a.foo, a);
  arr.map(a.foo, b);
  ```

**ArkTS1.2版本签名：**  
  `map(callbackfn: (value: number, index: number, array: Int8Array) => number): Int8Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 映射函数。 |

callbackfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Int8Array | 是 | 调用的原始Int8Array数组。 |

callbackfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 当前函数计算后新得到的number值。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Int8Array | 新数组，每个元素都是回调函数的返回值。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    call(arr: Int8Array) {
      return arr.map((value: number, index: number, arr: Int8Array)=>{return value + this.base})
    }
  }
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  a.call(arr);
  b.call(arr);
  ```

**适配建议：** 删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### some方法变更
**ArkTS1.1版本签名：**  
  `some(predicate: (value: number, index: number, array: Int8Array) => unknown, thisArg?: any): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |
  | thisArg | any | 否 | 执行callback时使用的this值，默认为undefined。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Int8Array | 是 | 调用的原始Int8Array数组。 |

predicate函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | unknown | 返回值会被隐式转换为boolean，决定当前元素是都满足predicate满足。 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 表示是否至少有一个元素通过测试。true表示至少有一个元素通过测试，false表示没有任何元素通过。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    foo(value: number, index: number, arr: Int8Array) {
      return value > this.base
    }
  }
  
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  arr.some(a.foo, a);
  arr.some(a.foo, b);
  ```

**ArkTS1.2版本签名：**  
  `some(predicate: (value: number, index: number, array: Int8Array) => boolean): boolean`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | predicate | function | 是 | 测试函数。 |

predicate函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | number | 是 | 当前被遍历的数组元素的值。 |
  | index | number | 是 | 当前元素的索引。 |
  | array | Int8Array | 是 | 调用的原始Int8Array数组。 |

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
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    call(arr: Int8Array) {
      return arr.some((value: number, index: number, arr: Int8Array)=>{return value > this.base})
    }
  }
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  a.call(arr);
  b.call(arr);
  ```

**适配建议：** 删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

### from静态方法变更1
**ArkTS1.1版本签名：**  
  `static from(arrayLike: Iterable<number>, mapfn?: (v: number, k: number) => number, thisArg?: any): Int8Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | arrayLike | Iterable\<number> | 是 | 可迭代对象。 |
  | mapfn | function | 否 | 映射函数，默认为undefined。 |
  | thisArg | any | 否 | 执行mapfn时使用的this值，默认为undefined。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | number | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回的一个number类型值，作为新Int8Array的元素 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Int8Array | 新数组。 |

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
  
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  let arr2 = Int8Array.from(arr, a.foo, a);
  let arr3 = Int8Array.from(arr, a.foo, b);
  ```

**ArkTS1.2版本签名：**  
  `static from(arrayLike: Iterable<number>, mapfn?: (v: number, k: number) => number): Int8Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | arrayLike | Iterable\<number> | 是 | 可迭代对象。 |
  | mapfn | function | 否 | 映射函数，默认为undefined。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | number | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回的一个number类型值，作为新Int8Array的元素 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Int8Array | 新数组。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    call(arr: Int8Array) {
      return Array.from(arr, (value: number, index: number)=>{return value + this.base})
    }
  }
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  a.call(arr);
  b.call(arr);
  ```

**适配建议：** 删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。


### from静态方法变更2
**ArkTS1.1版本签名：**  
  `static from<T>(arrayLike: ArrayLike<T>, mapfn: (v: T, k: number) => number, thisArg?: any): Int8Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | arrayLike | ArrayLike\<T> | 是 | 类数组对象。 |
  | mapfn | function | 是 | 映射函数。 |
  | thisArg | any | 否 | 执行mapfn时使用的this值，默认为undefined。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | T | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回的一个number类型值，作为新Int8Array的元素 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Int8Array | 新数组。 |

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
  
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  let arr2 = Int8Array.from(arr, a.foo, a);
  let arr3 = Int8Array.from(arr, a.foo, b);
  ```

**ArkTS1.2版本签名：**  
  `static from<T>(arrayLike: ArrayLike<T>, mapfn: (v: T, k: number) => number): Int8Array`

**参数：**
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | arrayLike | ArrayLike\<T> | 是 | 类数组对象。 |
  | mapfn | function | 是 | 映射函数。 |

mapfn函数参数说明：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | v | T | 是 | 当前被遍历的数组元素的值。 |
  | k | number | 是 | 当前元素的索引。 |

mapfn函数返回值说明：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回的一个number类型值，作为新Int8Array的元素 |

**返回值：**
  | 类型 | 说明 |
  | -------- | -------- |
  | Int8Array | 新数组。 |

**示例：**
  ```typescript
  class C {
    base: number;
    constructor(base:number) {
      this.base = base;
    }
    call(arr:Int8Array) {
      return Array.from(arr, (value: number, index: number)=>{return value + this.base})
    }
  }
  let arr: Int8Array = new Int8Array([1, 2, 3]);
  let a = new C(2);
  let b = new C(3);
  a.call(arr);
  b.call(arr);
  ```

**适配建议：** 删除最后一个参数，不使用显式指定this的语义。若必须使用，可使用闭包。

