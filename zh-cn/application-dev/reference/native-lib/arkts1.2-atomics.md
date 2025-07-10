# Atomics (原子操作)
- Atomics用于解决多线程并发编程中的竞态条件问题，确保对共享数据的并发操作安全。
- Atomics的所有方法都是静态方法，数据通过第一个参数`typedArray`传递。
- `typedArray`指一类数组数据类型，具体请见下文表格。
- `typedArray`是基于`ArrayBuffer`构建的。

Atomics的各个方法不是每种`typedArray`都支持，各方法支持类型见下表：  

**类型支持表：**  
| function |Int8Array|Int16Array|Int32Array|Uint8Array|Uint16Array|Uint32Array|BigInt64Array|BigUint64Array|
|--|--|--|--|--|--|--|--|--|
|add|支持|支持|支持|支持|支持|支持|支持|支持|
|and|支持|支持|支持|支持|支持|支持|支持|支持|
|compareExchange|支持|支持|支持|支持|支持|支持|支持|支持|
|exchange|支持|支持|支持|支持|支持|支持|支持|支持|
|load|支持|支持|支持|支持|支持|支持|支持|支持|
|notify|不支持|不支持|支持|不支持|不支持|不支持|支持|不支持|
|or|支持|支持|支持|支持|支持|支持|支持|支持|
|store|支持|支持|支持|支持|支持|支持|支持|支持|
|sub|支持|支持|支持|支持|支持|支持|支持|支持|
|wait|不支持|不支持|支持|不支持|不支持|不支持|支持|不支持|
|waitAsync|不支持|不支持|支持|不支持|不支持|不支持|支持|不支持|
|xor|支持|支持|支持|支持|支持|支持|支持|支持|

为了方便在各方法中表示支持的类型，将类型分为以下别名：
- **smalltypedArray**: Int8Array | Int16Array | Int32Array | Uint8Array | Uint16Array | Uint32Array
- **bigtypedArray**: BigInt64Array | BigUint64Array

## add

static add(typedArray: smalltypedArray, index: number, value: number): number  

将typedArray[index]与value进行加法运算，结果写回typedArray[index]。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在修改typedArray[index]之前，不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | smalltypedArray                         | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。  |
| value     | number                            | 是   | 执行运算的操作数，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。        |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| number      | 返回typedArray[index]被修改之前的值，与smalltypedArray中的元素类型一致，可为负数，不可为浮点数。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例**  
```ts
let ab = new ArrayBuffer(1024)
let ta = new Uint8Array(ab)

let old = Atomics.add(ta, 0, 12)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //0
hilog.info(0x0000, "testTag", "res is:" + re) //12
```

## add

static add(typedArray: bigtypedArray, index: number, value: bigint): bigint  

将typedArray[index]与value进行加法运算，结果写回typedArray[index]。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | bigtypedArray                          | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。  |
| value     | bigint                            | 是   | 执行运算的操作数。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| bigint      | 返回typedArray[index]被修改之前的值。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例**  
```ts
let ab = new ArrayBuffer(1024)
let ta = new BigInt64Array(ab)

let old = Atomics.add(ta, 0, 12n)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //0
hilog.info(0x0000, "testTag", "res is:" + re) //12
```

## and

static and(typedArray: smalltypedArray, index: number, value: number): number  

将typedArray[index]与value进行按位与运算，结果写回typedArray[index]。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | smalltypedArray                        | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。    |
| value     | number                            | 是   | 执行运算的操作数，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| number      | 返回typedArray[index]被修改之前的值，与smalltypedArray中的元素类型一致，可为负数，不可为浮点数。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new Uint8Array(ab)
ta[0] = 3

let old = Atomics.and(ta, 0, 2)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //3
hilog.info(0x0000, "testTag", "res is:" + re) //2
```
## and

static and(typedArray: bigtypedArray, index: number, value: bigint): bigint  

将typedArray[index]与value进行按位与运算，结果写回typedArray[index]。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | bigtypedArray                          | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。    |
| value     | bigint                            | 是   | 执行运算的操作数。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| bigint      | 返回typedArray[index]被修改之前的值。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024);
let ta = new BigInt64Array(ab);
ta[0] = 3n

let old = Atomics.and(ta, 0, 2n)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //3
hilog.info(0x0000, "testTag", "res is:" + re) //2
```

## compareExchange

static compareExchange(typedArray: smalltypedArray, index: number, expectedValue: number, replacementValue: number): number  

如果typedArray[index]等于expectedValue，将typedArray[index]赋值为replacementValue，如果不相等则不做任何处理。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                          | 必填 | 说明                   |
| -------- | -------------------------------------------- | ---- | ---------------------- |
| typedArray | smalltypedArray                              | 是   | 要操作的数组。    |
| index     | number                                         | 是   | typedArray的索引。     |
| expectedValue     | number             | 是   | 用于检查与typedArray[index]是否相等的值，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。     |
| replacementValue     | number          | 是   | typedArray[index]要被替换的值，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| number       | 返回typedArray[index]被修改之前的值，与smalltypedArray中的元素类型一致，可为负数，不可为浮点数。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new Uint8Array(ab)
ta[0] = 7

let old = Atomics.compareExchange(ta, 0, 7, 12)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //7
hilog.info(0x0000, "testTag", "res is:" + re) //12
```
## compareExchange

static compareExchange(typedArray: bigtypedArray, index: number, expectedValue: bigint, replacementValue: bigint): bigint  

如果typedArray[index]等于expectedValue，将typedArray[index]赋值为replacementValue，如果不相等则不做任何处理。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                          | 必填 | 说明                   |
| -------- | -------------------------------------------- | ---- | ---------------------- |
| typedArray | bigtypedArray                                    | 是   | 要操作的数组。    |
| index     | number                                         | 是   | typedArray的索引。     |
| expectedValue     | bigint                              | 是   | 用于检查与typedArray[index]是否相等的值。     |
| replacementValue     | bigint                           | 是   | typedArray[index]要被替换的值。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| bigint      | 返回typedArray[index]被修改之前的值。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new BigInt64Array(ab)
ta[0] = 7n

let old = Atomics.compareExchange(ta, 0, 7n, 12n)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //7
hilog.info(0x0000, "testTag", "res is:" + re) //12
```

## exchange

static exchange(typedArray: smalltypedArray, index: number, value: number): number  

将typedArray[index]赋值为value。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | smalltypedArray                         | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。     |
| value     | number         | 是   | typedArray[index]要被修改为的值，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。     |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| number      | 返回typedArray[index]被修改前的值，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new Uint8Array(ab)

let old = Atomics.exchange(ta, 0, 12)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //0
hilog.info(0x0000, "testTag", "res is:" + re) //12
```
## exchange

static exchange(typedArray: bigtypedArray, index: number, value: bigint): bigint  

将typedArray[index]赋值为value。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | bigtypedArray                         | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。     |
| value     | bigint         | 是   | typedArray[index]要被修改为的值。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| bigint       | 返回typedArray[index]被修改前的值。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new BigInt64Array(ab)

let old = Atomics.exchange(ta, 0, 12n)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //0
hilog.info(0x0000, "testTag", "res is:" + re) //12
```

## isLockFree

static isLockFree(byteSize: int): boolean

Atomics的方法对数据字节大小有要求，只有符合字节大小要求的才能使用Atomics的方法。  
此方法判断byteSize字节的大小是否适用于Atomics的方法。

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| byteSize | int                                 | 是   | 要判断是否可使用Atomics方法的字节大小。     |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| boolean      | 返回一个布尔值，表示是否可使用Atomics方法，true代表可以使用，false代表不可以使用。   |

**示例：**
```ts
hilog.info(0x0000, "testTag", "res is:" + Atomics.isLockFree(1)) //true
hilog.info(0x0000, "testTag", "res is:" + Atomics.isLockFree(2)) //true
hilog.info(0x0000, "testTag", "res is:" + Atomics.isLockFree(3)) //false
hilog.info(0x0000, "testTag", "res is:" + Atomics.isLockFree(4)) //true
hilog.info(0x0000, "testTag", "res is:" + Atomics.isLockFree(5)) //false
hilog.info(0x0000, "testTag", "res is:" + Atomics.isLockFree(6)) //false
hilog.info(0x0000, "testTag", "res is:" + Atomics.isLockFree(7)) //false
hilog.info(0x0000, "testTag", "res is:" + Atomics.isLockFree(8)) //true
```

## load

static load(typedArray: smalltypedArray, index: number): number  

返回typedArray[index]的值。  
此方法确保在typedArray[index]被加载之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | smalltypedArray                        | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。   |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| number      | 返回typedArray[index]的值，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024);
let ta = new Uint8Array(ab);

Atomics.add(ta, 0, 12);
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "res is:" + re) //12
```
## load

static load(typedArray: BigInt64Array, index: number): bigint  

返回typedArray[index]的值。  
此方法确保在typedArray[index]被加载之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | BigInt64Array                         | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。   |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| bigint       | 返回typedArray[index]的值。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new BigInt64Array(ab)

Atomics.add(ta, 0, 12n)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "res is:" + re) //12
```
## load

static load(typedArray: BigUint64Array, index: number): bigint  

返回typedArray[index]的值。  
此方法确保在typedArray[index]被加载之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | BigUint64Array                         | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。   |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| bigint       | 返回typedArray[index]的值。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new BigUint64Array(ab)

Atomics.add(ta, 0, 12n)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "res is:" + re) //12
```

## notify

static notify(typedArray: Int32Array | BigInt64Array, index: number, count?: number): int  

唤醒一些在等待typedArray[index]的Waiter。count可以指定唤醒Waiter的个数。  
调用Atomics.wait(typedArray, index, value)会在typedArray[index]处产生一个Waiter。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | Int32Array \| BigInt64Array             | 是   | 要操作的数组。     |
| index     | number                               | 是   |typedArray的索引，不能为负数。         |
| count     | number                          | 否   | 要唤醒的休眠Waiter的数量。不能为负数，默认为Infinity。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| int         | 返回被唤醒的Waiter数量。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Index out of bounds" | 访问typedArray越界。<br>可能原因：index超出typedArray的边界。<br>处理步骤：确保传入的index在typedArray的范围内。如果无法保证，建议捕获 RangeError 异常。 |

**示例：**  
```ts
function FuncWait(arr: BigInt64Array): void {
    let re = Atomics.wait(arr, 0, 0n, 3000)
    hilog.info(0x0000, "testTag", "Atomics result: " + re) //ok
}

function FuncNotify(arr: BigInt64Array): void {
    let re = Atomics.wait(arr, 0, 0n, 1000)
    hilog.info(0x0000, "testTag", "Atomics result: " + re) //timed-out

    Atomics.notify(arr, 0)
}

function testMain(): void {
    let buf = new ArrayBuffer(1024)
    let arr: BigInt64Array = new BigInt64Array(buf, 0)

    Atomics.store(arr, 0, 0n)
    let re = Atomics.wait(arr, 0, 1n)
    hilog.info(0x0000, "testTag", "Atomics result: " + re) //not-equal

    let p1 = launch<void, (arr: BigInt64Array) => void>(FuncWait, arr)
    FuncNotify(arr)
    p1.Await()
}
```

## or

static or(typedArray: smalltypedArray, index: number, value: number): number  

将typedArray[index]与value进行按位或运算，结果写回typedArray[index]。  
此方法返回修改前的typedArray[index]值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | smalltypedArray                         | 是   | 要操作的数组。     |
| index     | number                                | 是   | typedArray的索引。  |
| value     | number                             | 是   | 执行运算的操作数，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。   |

**返回值：** 
| 类型        | 说明                          |
| ----------- | ---------------------------  |
| number      | 返回typedArray[index]被修改之前的值，与smalltypedArray中的元素类型一致，可为负数，不可为浮点数。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new Uint8Array(ab)
ta[0] = 2

let old = Atomics.or(ta, 0, 1)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //2
hilog.info(0x0000, "testTag", "res is:" + re) //3
```
## or

static or(typedArray: bigtypedArray, index: number, value: bigint): bigint  

将typedArray[index]与value进行按位或运算，结果写回typedArray[index]。  
此方法返回修改前的typedArray[index]值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | bigtypedArray                         | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。  |
| value     | bigint       | 是   | 执行运算的操作数。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| bigint       | 返回typedArray[index]被修改之前的值。        |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new BigInt64Array(ab)
ta[0] = 2n

let old = Atomics.or(ta, 0, 1n)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //2
hilog.info(0x0000, "testTag", "res is:" + re) //3
```

## store

static store(typedArray: smalltypedArray, index: number, value: number): number  

将typedArray[index]赋值为value，并返回该值。

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | smalltypedArray                         | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。 |
| value     | number         | 是   | 执行运算的操作数，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。   |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| number       | 返回要存储的新值value，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。      |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new Uint8Array(ab)

let re = Atomics.store(ta, 0, 12)
hilog.info(0x0000, "testTag", "res is:" + re) //12
```
## store

static store(typedArray: bigtypedArray, index: number, value: bigint): bigint  

将typedArray[index]赋值为value，并返回该值。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | bigtypedArray                         | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。 |
| value     | bigint         | 是   | 执行运算的操作数。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| bigint       | 返回要存储的新值value，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。       |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new BigInt64Array(ab)

let re = Atomics.store(ta, 0, 12n)
hilog.info(0x0000, "testTag", "res is:" + re) //12
```

## sub

static sub(typedArray: smalltypedArray, index: number, value: number): number  

将typedArray[index]与value做减法，结果写回typedArray[index]。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | smalltypedArray                         | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。         |
| value     | number         | 是   | 执行运算的操作数，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。    |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| number       | 返回typedArray[index]被修改之前的值，与smalltypedArray中的元素类型一致，可为负数，不可为浮点数。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new Uint8Array(ab)
ta[0] = 48

let old = Atomics.sub(ta, 0, 12)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //48
hilog.info(0x0000, "testTag", "res is:" + re) //36
```
## sub

static sub(typedArray: bigtypedArray, index: number, value: bigint): bigint  

将typedArray[index]与value做减法，结果写回typedArray[index]。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | bigtypedArray                          | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。         |
| value     | bigint                            | 是   | typedArray[index]要减去的值。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| bigint       | 返回typedArray[index]被修改之前的值。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new BigInt64Array(ab)
ta[0] = 48n

let old = Atomics.sub(ta, 0, 12n)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //48
hilog.info(0x0000, "testTag", "res is:" + re) //36
```

## wait

static wait(typedArray: Int32Array, index: number, value: number, timeout?: number): string  

验证typedArray[index]是否等于value。如果不相等就直接返回"not-equal"。如果相等则进行等待状态。  
等待状态下如果收到notify，则结束等待并返回"ok"，如果设置了timeout超时时间，超过超时时间则不再等待并返回"time-out"，否则一直等待。    

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | Int32Array                         | 是   | 要操作的数组。     |
| index     | number                               | 是   |typedArray的索引，不能为负数。   |
| value     | number                           | 是   | typedArray[index]要比较相等性的数据。Int32类型取值范围         |
| timeout     | number                           | 否   | 超时时间，单位毫秒（ms），不可为负数。     |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| string      | 返回等待结果。<br>"not-equal"：typedArray[index]不等于value；"ok"：<br>等待期间收到另外一个协程notify；<br>"timed-out"：等待超过设置的timeout超时时间。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Index out of bounds" | 访问typedArray越界。<br>可能原因：index超出typedArray的边界。<br>处理步骤：确保传入的index在typedArray的范围内。如果无法保证，建议捕获 RangeError 异常。 |

**示例：**  
```ts
function FuncWait(arr: Int32Array): void {
    let re = Atomics.wait(arr, 0, 0, 3000)
    hilog.info(0x0000, "testTag", "Atomics result: " + re) //ok
}

function FuncNotify(arr: Int32Array): void {
    let re = Atomics.wait(arr, 0, 0, 1000)
    hilog.info(0x0000, "testTag", "Atomics result: " + re) //timed-out

    Atomics.notify(arr, 0)
}

function testMain(): void {
    let buf = new ArrayBuffer(1024)
    let arr: Int32Array = new Int32Array(buf, 0)

    Atomics.store(arr, 0, 0)
    let re = Atomics.wait(arr, 0, 1)
    hilog.info(0x0000, "testTag", "Atomics result: " + re) //not-equal

    let p1 = launch<void, (arr: Int32Array) => void>(FuncWait, arr)
    FuncNotify(arr)
    p1.Await()
}
```
## wait

static wait(typedArray: BigInt64Array, index: nubmer, value: bigint, timeout?: number): string  

验证typedArray[index]是否等于value。如果不相等就直接返回"not-equal"。如果相等则进行等待状态。  
等待状态下如果收到notify，则结束等待并返回"ok"，如果设置了timeout超时时间，超过超时时间则不再等待并返回"time-out"，否则一直等待。    

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | BigInt64Array                         | 是   | 要操作的数组。     |
| index     | number                               | 是   |typedArray的索引，不能为负数。   |
| value     | bigint                           | 是   | typedArray[index]要比较相等性的数据。         |
| timeout     | number                           | 否   | 超时时间，单位毫秒（ms），不可为负数。     |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| string      | 返回等待结果。<br>"not-equal"：typedArray[index]不等于value；"ok"：<br>等待期间收到另外一个协程notify；<br>"timed-out"：等待超过设置的timeout超时时间。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Index out of bounds" | 访问typedArray越界。<br>可能原因：index超出typedArray的边界。<br>处理步骤：确保传入的index在typedArray的范围内。如果无法保证，建议捕获 RangeError 异常。 |

**示例：**  
```ts
function FuncWait(arr: BigInt64Array): void {
    let re = Atomics.wait(arr, 0, 0n, 3000)
    hilog.info(0x0000, "testTag", "Atomics result: " + re) //ok
}

function FuncNotify(arr: BigInt64Array): void {
    let re = Atomics.wait(arr, 0, 0n, 1000)
    hilog.info(0x0000, "testTag", "Atomics result: " + re) //timed-out

    Atomics.notify(arr, 0)
}

function testMain(): void {
    let buf = new ArrayBuffer(1024)
    let arr: BigInt64Array = new BigInt64Array(buf, 0)

    Atomics.store(arr, 0, 0n)
    let re = Atomics.wait(arr, 0, 1n)
    hilog.info(0x0000, "testTag", "Atomics result: " + re) //not-equal

    let p1 = launch<void, (arr: BigInt64Array) => void>(FuncWait, arr)
    FuncNotify(arr)
    p1.Await()
}
```

## waitAsync

async static waitAsync(typedArray: Int32Array | BigInt64Array, index: number, value: bigint, timeout?: number): Promise\<string>

等待共享内存的特定位置，与wait不同，不会阻塞调用者。  
等待结果可通过返回值获得。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | Int32Array \| BigInt64Array            | 是   | 要操作的数组。     |
| index     | number                               | 是   |typedArray的索引，不能为负数。   |
| value      | bigint                          | 是   | typedArray[index]要比较相等性的数据。     |
| timeout     | number                           | 否   | 超时时间，单位毫秒（ms），不可为负数。     |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| Promise\<string>   | 返回等待结果。<br>"not-equal"：typedArray[index]不等于value；<br>"ok"：等待期间收到另外一个协程notify；<br>"timed-out"：等待超过设置的timeout超时时间。 |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Index out of bounds" | 访问typedArray越界。<br>可能原因：index超出typedArray的边界。<br>处理步骤：确保传入的index在typedArray的范围内。如果无法保证，建议捕获 RangeError 异常。 |

**示例：**  
```ts
function FuncWaitAsync(arr: Int32Array): void {
    Atomics.store(arr, 0, 0)

    let re: Promise<string> = Atomics.waitAsync(arr,0, 1n)
    re.then((value: string): void => {
        hilog.info(0x0000, "testTag", value) // not-equal
    }, (err: Error): void => {
        hilog.info(0x0000, "testTag", "Test failed. The promise shouldn`t be rejected.")
    });

    let re2 = Atomics.waitAsync(arr, 0, 0n, 2000)
    re2.then((value: string): void => {
        hilog.info(0x0000, "testTag", value) // timed-out
    }, (err: Error): void => {
        hilog.info(0x0000, "testTag", "Test failed. The promise shouldn`t be rejected.")
    });

    let re3 = Atomics.waitAsync(arr, 0, 0n, 10000)
    re3.then((value: string): void => {
        hilog.info(0x0000, "testTag", value) // ok
    }, (err: Error): void => {
        hilog.info(0x0000, "testTag", "Test failed. The promise shouldn`t be rejected.")
    });
}

function FuncNotify(arr: Int32Array): void {
    setTimeout(() => {
        Atomics.notify(arr, 0)
    }, 5000);
}

function testMain(): void {
    let buf = new ArrayBuffer(1024);
    let arr: Int32Array = new Int32Array(buf, 0);
    FuncWaitAsync(arr)
    FuncNotify(arr)
}
```

## xor

static xor(typedArray: smalltypedArray, index: number, value: number): number  

将typedArray[index]与value进行按位异或运算，结果写回typedArray[index]。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | smalltypedArray                        | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。    |
| value     | number              | 是   | 执行运算的操作数，对应smalltypedArray中的元素类型，可为负数，不可为浮点数。 |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| number      | 返回typedArray[index]被修改之前的值，与smalltypedArray中的元素类型一致，可为负数，不可为浮点数。  |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new Uint8Array(ab)
ta[0] = 5

let old = Atomics.xor(ta, 0, 1)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //5
hilog.info(0x0000, "testTag", "res is:" + re) //4
```
## xor

static xor(typedArray: bigtypedArray, index: number, value: bigint): bigint  

将typedArray[index]与value进行按位异或运算，结果写回typedArray[index]。  
此方法返回typedArray[index]被修改之前的值。  
此方法确保在typedArray[index]被修改之前，typedArray[index]不会发生其他线程的读写操作。  

**参数：**
| 名称     | 类型                                    | 必填 | 说明                   |
| -------- | --------------------------------------- | ---- | ---------------------- |
| typedArray | bigtypedArray                          | 是   | 要操作的数组。     |
| index     | number                               | 是   | typedArray的索引。    |
| value     | bigint                            | 是   | 执行运算的操作数。         |

**返回值：** 
| 类型        | 说明                         |
| ----------- | --------------------------- |
| bigint       | 返回typedArray[index]被修改之前的值。   |

**错误信息**
| 错误信息        | 说明                         |
| ----------- | --------------------------- |
| "Unhandled array type!" | typedArray不在支持的类型范围内 |

**示例：**
```ts
let ab = new ArrayBuffer(1024)
let ta = new BigInt64Array(ab)
ta[0] = 5n

let old = Atomics.xor(ta, 0, 1n)
let re = Atomics.load(ta, 0)
hilog.info(0x0000, "testTag", "old is:" + old) //5
hilog.info(0x0000, "testTag", "res is:" + re) //4
```
