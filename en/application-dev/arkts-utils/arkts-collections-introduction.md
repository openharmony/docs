# Shared Container

## ArkTS Collections

The ArkTS shared container ([@arkts.collections (ArkTS Collections)](../reference/apis-arkts/js-apis-arkts-collections.md)) is a container class for shared transmission between concurrent tasks and can be used for high-performance data transmission in concurrent scenarios. The functions of the container are similar to those of the container defined in the Ecmascript262 specification, but there are still some differences. For details, see [Behavior Differences Between Shared Container APIs and Native APIs](#behavior-differences-between-shared-container-apis-and-native-apis).

When an ArkTS shared container is transferred between multiple concurrent tasks, the default behavior is reference transfer. Multiple concurrent tasks can operate the same container instance. Pass-by-copy is also supported. In this mode, each concurrent instance holds an ArkTS container instance.

ArkTS containers are not thread-safe. They adopt the fail-fast approach. An exception is thrown if multiple concurrent instances make structural changes to a container instance at the same time. Therefore, when modifying attributes in a container, you need to use the asynchronous lock (arkts-async-lock-introduction.md) mechanism provided by ArkTS to ensure secure access to the ArkTS container.

ArkTS shared containers include [Array](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsarray), [Map](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsmap), [Set](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsset), [TypedArray](../reference/apis-arkts/js-apis-arkts-collections.md#collectionstypedarray) (Int8Array, Uint8Array, Int16Array, Uint16Array, Int32Array, Uint32Array, Uint8ClampedArray and Float32Array), and [ArrayBuffer](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsarraybuffer). For details, see [@arkts.collections (ArkTS Collections)](../reference/apis-arkts/js-apis-arkts-collections.md).

The following is an example of using a container set:

```ts
import { ArkTSUtils, collections, taskpool } from '@kit.ArkTS';

@Concurrent
async function add(arr: collections.Array<number>, lock: ArkTSUtils.locks.AsyncLock) {
 await lock.lockAsync (() => { // If no asynchronous lock is added, the task will fail due to data contention conflicts.
   arr[0]++;
 })
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          let taskGroup = new taskpool.TaskGroup();
          let lock = new ArkTSUtils.locks.AsyncLock();
          let arr = collections.Array.create<number>(1, 0);
          let count = 1000;
          while (count--) {
            taskGroup.addTask(add, arr, lock);
          }
          taskpool.execute(taskGroup).then(() => {
            console.info(`Return success: ${arr[0]} === ${count}`);
          }).catch((e: Error) => {
            console.error("Return error.");
          })
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## Behavior Differences Between Shared Container APIs and Native APIs

ArkTS provides a shared container set related to Sendable data. The API behavior is different from that of the native API. For details, see the following comparison.

> **Note**
>
> The type of the ArkTS shared container is different from that of the native container defined in the Ecmascript262 specification. Therefore, when the isArray () method of the native container array is used to determine the collections.Array instance object, false is returned.

### Array

A native container array can be converted into an ArkTS array using the [collections.Array.from](../reference/apis-arkts/js-apis-arkts-collections.md#from) method. An ArkTS array can be converted into a native container array using the from method of the native container array.

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| -------- | -------- | -------- | -------- |
| length: number | readonly length: number | Supported| To prevent the spread of undefined, it is not allowed to set **length**.|
| new(arrayLength ?: number): any[] | static create(arrayLength: number, initialValue: T): Array | Supported| To prevent the spread of undefined, a constructor must be provided with an initial value.|
| new &lt;T&gt;(arrayLength: number): T[] | constructor() | No| / |
| new &lt;T&gt;(...items: T[]): T[] | constructor(first: T, ...left: T[]) | Supported| To prevent the spread of undefined, a constructor must be provided with an initial value. In inheritance scenarios, this constructor cannot be called to construct an object.|
| from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;): T[] | static from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;): Array&lt;T&gt; | No| / |
| pop(): T \| undefined | pop(): T \| undefined | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| push(...items: T[]): number | push(...items: T[]): number | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| concat(...items: ConcatArray&lt;T&gt;[]): T[] | concat(...items: ConcatArray&lt;T&gt;[]): Array&lt;T&gt; | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| concat(...items: (T \| ConcatArray&lt;T&gt;)[]): T[] | concat(...items: ConcatArray&lt;T&gt;[]): Array&lt;T&gt; | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| join(separator?: string): string | join(separator?: string): string | No| / |
| shift(): T \| undefined | shift(): T \| undefined | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| slice(start?: number, end?: number): T[] | slice(start?: number, end?: number): Array&lt;T&gt; | No| / |
| sort(compareFn?: (a: T, b: T) =&gt; number): this | sort(compareFn?: (a: T, b: T) =&gt; number): Array&lt;T&gt; | Supported| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. In inheritance scenarios, the actual return value type cannot be obtained.|
| unshift(...items: T[]): number | unshift(...items: T[]): number | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| indexOf(searchElement: T, fromIndex?: number): number | indexOf(searchElement: T, fromIndex?: number): number | No| / |
| forEach(callbackfn: (value: T, index: number, array: T[]) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: T, index: number, array: Array&lt;T&gt;) =&gt; void): void | Supported| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| map&lt;U&gt;(callbackfn: (value: T, index: number, array: T[]) =&gt; U, thisArg?: any): U[] | map&lt;U&gt;(callbackFn: (value: T, index: number, array: Array&lt;T&gt;) =&gt; U): Array&lt;U&gt; | Supported| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| filter(predicate: (value: T, index: number, array: T[]) =&gt; unknown, thisArg?: any): T[] | filter(predicate: (value: T, index: number, array: Array&lt;T&gt;) =&gt; boolean): Array&lt;T&gt; | Supported| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| reduce(callbackfn: (previousValue: T, currentValue: T, currentIndex: number, array: T[]) =&gt; T): T | reduce(callbackFn: (previousValue: T, currentValue: T, currentIndex: number, array: Array&lt;T&gt;) =&gt; T): T | No| / |
| reduce&lt;U&gt;(callbackfn: (previousValue: U, currentValue: T, currentIndex: number, array: T[]) =&gt; U, initialValue: U): U | reduce&lt;U&gt;(callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array&lt;T&gt;) =&gt; U, initialValue: U): U | No| / |
| [n: number]: T | [index: number]: T | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| findIndex(predicate: (value: T, index: number, obj: T[]) =&gt; unknown, thisArg?: any): number | findIndex(predicate: (value: T, index: number, obj: Array&lt;T&gt;) =&gt; boolean): number | Yes| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| fill(value: T, start?: number, end?: number): this | fill(value: T, start?: number, end?: number): Array&lt;T&gt; | Supported| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. In inheritance scenarios, the actual return value type cannot be obtained.|
| entries(): IterableIterator&lt;[number, T]&gt; | entries(): IterableIterator&lt;[number, T]&gt; | No| / |
| keys(): IterableIterator&lt;number&gt; | keys(): IterableIterator&lt;number&gt; | No| / |
| values(): IterableIterator&lt;T&gt; | values(): IterableIterator&lt;T&gt; | No| / |
| includes(searchElement: T, fromIndex?: number): boolean | includes(searchElement: T, fromIndex?: number): boolean | No| / |
| at(index: number): T \| undefined | at(index: number): T \| undefined | No| / |

### ArrayBuffer

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| -------- | -------- | -------- | -------- |
| readonly byteLength: number | readonly byteLength: number | No| / |
| slice(begin: number, end?: number): ArrayBuffer | slice(begin: number, end?: number): ArrayBuffer | No| / |
| new(byteLength: number): ArrayBuffer | constructor(byteLength: number) | No| / |

### TypedArray (Int8Array Used as an Example)

The native container TypedArray can be converted to the ArkTS TypedArray container using the [collections.TypedArray.from](../reference/apis-arkts/js-apis-arkts-collections.md#from-1) method. The ArkTS TypedArray container can be converted to the native container TypedArray using the from method of the native container TypedArray.

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| -------- | -------- | -------- | -------- |
| readonly buffer: ArrayBufferLike | readonly buffer: ArrayBuffer | No| / |
| readonly byteLength: number | readonly byteLength: number | No| / |
| readonly byteOffset: number | readonly byteOffset: number | No| / |
| readonly length: number | readonly length: number | No| / |
| readonly BYTES_PER_ELEMENT: number | static readonly BYTES_PER_ELEMENT: number | No| / |
| copyWithin(target: number, start: number, end?: number): this | copyWithin(target: number, start: number, end?: number): Int8Array | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| every(predicate: (value: number, index: number, array: Int8Array) =&gt; unknown, thisArg?: any): boolean | every(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): boolean | Supported| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| fill(value: number, start?: number, end?: number): this | fill(value: number, start?: number, end?: number): Int8Array | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| filter(predicate: (value: number, index: number, array: Int8Array) =&gt; any, thisArg?: any): Int8Array | filter(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): Int8Array | Supported| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| find(predicate: (value: number, index: number, obj: Int8Array) =&gt; boolean, thisArg?: any): number \| undefined | find(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): number \| undefined | Supported| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| findIndex(predicate: (value: number, index: number, obj: Int8Array) =&gt; boolean, thisArg?: any): number | findIndex(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): number | Supported| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| forEach(callbackfn: (value: number, index: number, array: Int8Array) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: number, index: number, array: Int8Array) =&gt; void): void | Supported| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| indexOf(searchElement: number, fromIndex?: number): number | indexOf(searchElement: number, fromIndex?: number): number | No| / |
| join(separator?: string): string | join(separator?: string): string | No| / |
| map(callbackfn: (value: number, index: number, array: Int8Array) =&gt; number, thisArg?: any): Int8Array | map(callbackFn: TypedArrayForEachCallback&lt;number, Int8Array&gt;): Int8Array | Supported| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| reduce(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) =&gt; number): number | reduce(callbackFn: TypedArrayReduceCallback&lt;number, number, Int8Array&gt;): number | No| / |
| reduce(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) =&gt; number, initialValue: number): number | reduce(callbackFn: TypedArrayReduceCallback&lt;number, number, Int8Array&gt;, initialValue: number): number | No| / |
| reduce&lt;U&gt;(callbackfn: (previousValue: U, currentValue: number, currentIndex: number, array: Int8Array) =&gt; U, initialValue: U): U | reduce&lt;U&gt;(callbackFn: TypedArrayReduceCallback&lt;U, number, Int8Array&gt;, initialValue: U): U | No| / |
| reverse(): Int8Array | reverse(): Int8Array | No| / |
| set(array: ArrayLike&lt;number&gt;, offset?: number): void | set(array: ArrayLike&lt;number&gt;, offset?: number): void | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| slice(start?: number, end?: number): Int8Array | slice(start?: number, end?: number): Int8Array | No| / |
| some(predicate: (value: number, index: number, array: Int8Array) =&gt; unknown, thisArg?: any): boolean | some(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): boolean | Supported| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| sort(compareFn?: (a: number, b: number) =&gt; number): this | sort(compareFn?: TypedArrayCompareFn&lt;number&gt;): Int8Array | Supported| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. In inheritance scenarios, the actual return value type cannot be obtained.|
| subarray(begin?: number, end?: number): Int8Array | subarray(begin?: number, end?: number): Int8Array | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| [index: number]: number | [index: number]: number | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| entries(): IterableIterator&lt;[number, number]&gt; | entries(): IterableIterator&lt;[number, number]&gt; | No| / |
| keys(): IterableIterator&lt;number&gt; | keys(): IterableIterator&lt;number&gt; | No| / |
| values(): IterableIterator&lt;number&gt; | values(): IterableIterator&lt;number&gt; | No| / |
| includes(searchElement: number, fromIndex?: number): boolean | includes(searchElement: number, fromIndex?: number): boolean | No| / |
| at(index: number): number \| undefined | at(index: number): number \| undefined | No| / |
| new(length: number): Int8Array | constructor(length: number) | No| / |
| new(array: ArrayLike&lt;number&gt; \| ArrayBufferLike): Int8Array | constructor(array: ArrayLike&lt;number&gt; \| ArrayBuffer) | No| / |
| new(buffer: ArrayBufferLike, byteOffset?: number, length?: number): Int8Array | constructor(buffer: ArrayBuffer, byteOffset?: number, length?: number) | No| / |
| from(arrayLike: ArrayLike&lt;number&gt;): Int8Array | static from(arrayLike: ArrayLike&lt;number&gt;): Int8Array | No| / |
| from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;, mapfn: (v: T, k: number) =&gt; number, thisArg?: any): Int8Array | static from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;, mapFn: TypedArrayFromMapFn&lt;T, number&gt;): Int8Array | Supported| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| from(arrayLike: Iterable&lt;number&gt;, mapfn?: (v: number, k: number) =&gt; number, thisArg?: any): Int8Array | static from(arrayLike: Iterable&lt;number&gt;, mapFn?: TypedArrayFromMapFn&lt;number, number&gt;): Int8Array | Supported| ArkTS does not support **this**. As a result, **thisArg** is not supported.|

### Map

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| -------- | -------- | -------- | -------- |
| readonly size: number | readonly size: number | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| clear(): void | clear(): void | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| delete(key: K): boolean | delete(key: K): boolean | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| forEach(callbackfn: (value: V, key: K, map: Map&lt;K, V&gt;) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: V, key: K, map: Map&lt;K, V&gt;) =&gt; void): void | Supported| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| get(key: K): V \| undefined | get(key: K): V \| undefined | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| has(key: K): boolean | has(key: K): boolean | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| set(key: K, value: V): this | set(key: K, value: V): Map&lt;K, V&gt; | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| entries(): IterableIterator&lt;[K, V]&gt; | entries(): IterableIterator&lt;[K, V]&gt; | No| / |
| keys(): IterableIterator&lt;K&gt; | keys(): IterableIterator&lt;K&gt; | No| / |
| values(): IterableIterator&lt;V&gt; | values(): IterableIterator&lt;V&gt; | No| / |
| new &lt;K, V&gt;(entries?: readonly (readonly [K, V])[] \| null): Map&lt;K, V&gt; | constructor(entries?: readonly (readonly [K, V])[] \| null) | Supported| The passed-in values of **k** and **v** during construction cannot be non-sendable data. Otherwise, an error is reported during compilation.|

### Set

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| -------- | -------- | -------- | -------- |
| readonly size: number | readonly size: number | Supported| The **arkts-sendable-compated-prop-name** cannot be used in the Sendable class and APIs.|
| add(value: T): this | add(value: T): Set&lt;T&gt; | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| clear(): void | clear(): void | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| delete(value: T): boolean | delete(value: T): boolean | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| forEach(callbackfn: (value: T, value2: T, set: Set&lt;T&gt;) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: T, value2: T, set: Set&lt;T&gt;) =&gt; void): void | Supported| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| has(value: T): boolean | has(value: T): boolean | Supported| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| entries(): IterableIterator&lt;[T, T]&gt; | entries(): IterableIterator&lt;[T, T]&gt; | No| / |
| keys(): IterableIterator&lt;T&gt; | keys(): IterableIterator&lt;T&gt; | No| / |
| values(): IterableIterator&lt;T&gt; | values(): IterableIterator&lt;T&gt; | Supported| The **arkts-sendable-compated-prop-name** cannot be used in the Sendable class and APIs.|
| new &lt;T = any&gt;(values?: readonly T[] \| null): Set&lt;T&gt; | constructor(values?: readonly T[] \| null) | Supported| The passed-in values during construction cannot be non-sendable data. Otherwise, an error is reported during compilation.|
