# Shared Container

## ArkTS Collections

ArkTS shared containers ([@arkts.collections (ArkTS Collections)](../reference/apis-arkts/js-apis-arkts-collections.md)) are designed for high-performance data transmission between concurrent instances. They offer similar functionality to the containers defined in the ECMAScript 262 specification but with some key differences, which are outlined in the [Behavior Differences Between Shared Container APIs and Native APIs](#behavior-differences-between-shared-container-apis-and-native-apis).

By default, ArkTS shared containers are passed by reference, allowing multiple concurrent instances to manipulate the same container instance. Pass-by-copy is also supported. In this mode, each concurrent instance holds an ArkTS container instance.

ArkTS shared containers are not thread-safe and employ a fail-fast mechanism to prevent concurrent structural modifications, which would otherwise trigger exceptions. When modifying container properties in a multithreaded scenario, you must use the [asynchronous lock](arkts-async-lock-introduction.md) mechanism to ensure safe access.

The ArkTS shared containers include the following types: [Array](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsarray), [Map](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsmap), [Set](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsset), [TypedArray](../reference/apis-arkts/js-apis-arkts-collections.md#collectionstypedarray) (Int8Array, Uint8Array, Int16Array, Uint16Array, Int32Array, Uint32Array, Uint8ClampedArray, and Float32Array), and [ArrayBuffer](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsarraybuffer). For details, see [@arkts.collections (ArkTS Collections)](../reference/apis-arkts/js-apis-arkts-collections.md).

The following is an example of using the collection:

```ts
import { ArkTSUtils, collections, taskpool } from '@kit.ArkTS';

@Concurrent
async function add(arr: collections.Array<number>, lock: ArkTSUtils.locks.AsyncLock) {
 await lock.lockAsync(() => {  // Without the asynchronous lock, the task will fail due to data race conflicts.
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
<!-- @[example_use](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ConcurrentThreadCommunication/InterThreadCommunicationObjects/SendableObject/SendableObjectRelated/entry/src/main/ets/managers/ArktsCollectionsIntroduction.ets) -->

## Behavior Differences Between Shared Container APIs and Native APIs

ArkTS provides shared containers for Sendable data, with some behavior differences when compared with native APIs. These differences are detailed below.

> **NOTE**
>
> ArkTS shared containers have different types from native ECMAScript 262 containers. Therefore, if the native **isArray()** method is used on a **collections.Array instance** object, **false** is returned.
>
> ArkTS shared containers are passed across threads by reference, which is more efficient than native containers. If you need to transfer large amounts of data across threads, you are advised to use ArkTS shared containers.

### Array

Native Array containers can be converted into ArkTS Array containers using the [collections.Array.from](../reference/apis-arkts/js-apis-arkts-collections.md#from) method, and ArkTS Array containers can be converted into native Array containers using the native **from** method.

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| -------- | -------- | -------- | -------- |
| length: number | readonly length: number | Yes| To prevent the spread of **undefined**, it is not allowed to set **length**.|
| new(arrayLength ?: number): any[] | static create(arrayLength: number, initialValue: T): Array | Yes| To prevent the spread of **undefined**, a constructor must be provided with an initial value.|
| new &lt;T&gt;(arrayLength: number): T[] | constructor() | No| / |
| new &lt;T&gt;(...items: T[]): T[] | constructor(first: T, ...left: T[]) | Yes| To prevent the spread of **undefined**, a constructor must be provided with an initial value. In inheritance scenarios, this constructor cannot be called to construct an object.|
| from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;): T[] | static from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;): Array&lt;T&gt; | No| / |
| from&lt;T, U&gt;(iterable: Iterable&lt;T&gt; \| ArrayLike&lt;T&gt;, mapfn: (v: T, k: number) => U, thisArg?: any): U[] | static from&lt;U, T&gt;(arrayLike: ArrayLike&lt;U&gt; \| Iterable&lt;U&gt;, mapFn: ArrayFromMapFn&lt;U, T&gt;): Array&lt;T&gt; | No| / |
| pop(): T \| undefined | pop(): T \| undefined | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| push(...items: T[]): number | push(...items: T[]): number | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| concat(...items: ConcatArray&lt;T&gt;[]): T[] | concat(...items: ConcatArray&lt;T&gt;[]): Array&lt;T&gt; | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| concat(...items: (T \| ConcatArray&lt;T&gt;)[]): T[] | concat(...items: ConcatArray&lt;T&gt;[]): Array&lt;T&gt; | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| join(separator?: string): string | join(separator?: string): string | No| / |
| shift(): T \| undefined | shift(): T \| undefined | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| slice(start?: number, end?: number): T[] | slice(start?: number, end?: number): Array&lt;T&gt; | No| / |
| sort(compareFn?: (a: T, b: T) =&gt; number): this | sort(compareFn?: (a: T, b: T) =&gt; number): Array&lt;T&gt; | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. In inheritance scenarios, the actual type of the return value cannot be obtained.|
| unshift(...items: T[]): number | unshift(...items: T[]): number | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| indexOf(searchElement: T, fromIndex?: number): number | indexOf(searchElement: T, fromIndex?: number): number | No| / |
| forEach(callbackfn: (value: T, index: number, array: T[]) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: T, index: number, array: Array&lt;T&gt;) =&gt; void): void | Yes| ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| map&lt;U&gt;(callbackfn: (value: T, index: number, array: T[]) =&gt; U, thisArg?: any): U[] | map&lt;U&gt;(callbackFn: (value: T, index: number, array: Array&lt;T&gt;) =&gt; U): Array&lt;U&gt; | Yes| ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| filter(predicate: (value: T, index: number, array: T[]) =&gt; unknown, thisArg?: any): T[] | filter(predicate: (value: T, index: number, array: Array&lt;T&gt;) =&gt; boolean): Array&lt;T&gt; | Yes| ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| reduce(callbackfn: (previousValue: T, currentValue: T, currentIndex: number, array: T[]) =&gt; T): T | reduce(callbackFn: (previousValue: T, currentValue: T, currentIndex: number, array: Array&lt;T&gt;) =&gt; T): T | No| / |
| reduce&lt;U&gt;(callbackfn: (previousValue: U, currentValue: T, currentIndex: number, array: T[]) =&gt; U, initialValue: U): U | reduce&lt;U&gt;(callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array&lt;T&gt;) =&gt; U, initialValue: U): U | No| / |
| [n: number]: T | [index: number]: T | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| findIndex(predicate: (value: T, index: number, obj: T[]) =&gt; unknown, thisArg?: any): number | findIndex(predicate: (value: T, index: number, obj: Array&lt;T&gt;) =&gt; boolean): number | Yes| ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| fill(value: T, start?: number, end?: number): this | fill(value: T, start?: number, end?: number): Array&lt;T&gt; | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. In inheritance scenarios, the actual type of the return value cannot be obtained.|
| entries(): IterableIterator&lt;[number, T]&gt; | entries(): IterableIterator&lt;[number, T]&gt; | No| / |
| keys(): IterableIterator&lt;number&gt; | keys(): IterableIterator&lt;number&gt; | No| / |
| values(): IterableIterator&lt;T&gt; | values(): IterableIterator&lt;T&gt; | No| / |
| includes(searchElement: T, fromIndex?: number): boolean | includes(searchElement: T, fromIndex?: number): boolean | No| / |
| at(index: number): T \| undefined | at(index: number): T \| undefined | No| / |
| isArray(arg: any): arg is any[] | static isArray(value: Object \| undefined \| null): boolean | Yes| Checks whether the array is an ArkTS array instance. If not, **false** is returned.|
| of&lt;T&gt;(...items: T[]): T[] | static of&lt;T&gt;(...items: T[]): Array&lt;T&gt; | No| / |
| copyWithin(target: number, start: number, end?: number): this | copyWithin(target: number, start: number, end?: number): Array&lt;T&gt; | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| lastIndexOf(searchElement: T, fromIndex?: number): number | lastIndexOf(searchElement: T, fromIndex?: number): number | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| some(predicate: (value: T, index: number, array: T[]) =&gt; unknown, thisArg?: any): boolean | some(predicate: ArrayPredicateFn&lt;T, Array&lt;T&gt;&gt;): boolean | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| reduceRight(callbackfn: (previousValue: T, currentValue: T, currentIndex: number, array: T[]) =&gt; T): T | reduceRight(callbackFn: ArrayReduceCallback&lt;T, T, Array&lt;T&gt;&gt;): T | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| reduceRight&lt;U&gt;(callbackfn: (previousValue: U, currentValue: T, currentIndex: number, array: T[]) =&gt; U, initialValue: U): U | reduceRight&lt;U = T&gt;(callbackFn: ArrayReduceCallback&lt;U, T, Array&lt;T&gt;&gt;, initialValue: U): U | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| reverse(): T[] | reverse(): Array&lt;T&gt; | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| toString(): string | toString(): string | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| find(predicate: (value: T, index: number, obj: T[]) =&gt; unknown, thisArg?: any): T \| undefined | find(predicate: (value: T, index: number, obj: Array&lt;T&gt;) =&gt; boolean): T \| undefined | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| splice(start: number, deleteCount: number, ...items: T[]): T[] | splice(start: number, deleteCount: number, ...items: T[]): Array&lt;T&gt; | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| every(predicate: (value: T, index: number, array: T[]) =&gt; unknown, thisArg?: any): boolean | every(predicate: ArrayPredicateFn&lt;T, Array&lt;T&gt;&gt;): boolean | Yes| ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| toLocaleString(): string | toLocaleString(): string | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|

### ArrayBuffer

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| -------- | -------- | -------- | -------- |
| readonly byteLength: number | readonly byteLength: number | No| / |
| slice(begin: number, end?: number): ArrayBuffer | slice(begin: number, end?: number): ArrayBuffer | No| / |
| new(byteLength: number): ArrayBuffer | constructor(byteLength: number) | No| / |

### TypedArray (Int8Array Used as an Example)

Native TypedArray containers can be converted into ArkTS TypedArray containers using the [collections.TypedArray.from](../reference/apis-arkts/js-apis-arkts-collections.md#from-1) method, and ArkTS TypedArray containers can be converted into native TypedArray containers using the native **from** method.

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| -------- | -------- | -------- | -------- |
| readonly buffer: ArrayBufferLike | readonly buffer: ArrayBuffer | No| / |
| readonly byteLength: number | readonly byteLength: number | No| / |
| readonly byteOffset: number | readonly byteOffset: number | No| / |
| readonly length: number | readonly length: number | No| / |
| readonly BYTES_PER_ELEMENT: number | static readonly BYTES_PER_ELEMENT: number | No| / |
| copyWithin(target: number, start: number, end?: number): this | copyWithin(target: number, start: number, end?: number): Int8Array | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| every(predicate: (value: number, index: number, array: Int8Array) =&gt; unknown, thisArg?: any): boolean | every(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): boolean | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| fill(value: number, start?: number, end?: number): this | fill(value: number, start?: number, end?: number): Int8Array | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| filter(predicate: (value: number, index: number, array: Int8Array) =&gt; any, thisArg?: any): Int8Array | filter(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): Int8Array | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| find(predicate: (value: number, index: number, obj: Int8Array) =&gt; boolean, thisArg?: any): number \| undefined | find(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): number \| undefined | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| findIndex(predicate: (value: number, index: number, obj: Int8Array) =&gt; boolean, thisArg?: any): number | findIndex(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): number | Yes| ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| forEach(callbackfn: (value: number, index: number, array: Int8Array) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: number, index: number, array: Int8Array) =&gt; void): void | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| indexOf(searchElement: number, fromIndex?: number): number | indexOf(searchElement: number, fromIndex?: number): number | No| / |
| join(separator?: string): string | join(separator?: string): string | No| / |
| map(callbackfn: (value: number, index: number, array: Int8Array) =&gt; number, thisArg?: any): Int8Array | map(callbackFn: TypedArrayForEachCallback&lt;number, Int8Array&gt;): Int8Array | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| reduce(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) =&gt; number): number | reduce(callbackFn: TypedArrayReduceCallback&lt;number, number, Int8Array&gt;): number | No| / |
| reduce(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) =&gt; number, initialValue: number): number | reduce(callbackFn: TypedArrayReduceCallback&lt;number, number, Int8Array&gt;, initialValue: number): number | No| / |
| reduce&lt;U&gt;(callbackfn: (previousValue: U, currentValue: number, currentIndex: number, array: Int8Array) =&gt; U, initialValue: U): U | reduce&lt;U&gt;(callbackFn: TypedArrayReduceCallback&lt;U, number, Int8Array&gt;, initialValue: U): U | No| / |
| reverse(): Int8Array | reverse(): Int8Array | No| / |
| set(array: ArrayLike&lt;number&gt;, offset?: number): void | set(array: ArrayLike&lt;number&gt;, offset?: number): void | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| slice(start?: number, end?: number): Int8Array | slice(start?: number, end?: number): Int8Array | No| / |
| some(predicate: (value: number, index: number, array: Int8Array) =&gt; unknown, thisArg?: any): boolean | some(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): boolean | Yes| ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| sort(compareFn?: (a: number, b: number) =&gt; number): this | sort(compareFn?: TypedArrayCompareFn&lt;number&gt;): Int8Array | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. In inheritance scenarios, the actual type of the return value cannot be obtained.|
| subarray(begin?: number, end?: number): Int8Array | subarray(begin?: number, end?: number): Int8Array | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| [index: number]: number | [index: number]: number | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| entries(): IterableIterator&lt;[number, number]&gt; | entries(): IterableIterator&lt;[number, number]&gt; | No| / |
| keys(): IterableIterator&lt;number&gt; | keys(): IterableIterator&lt;number&gt; | No| / |
| values(): IterableIterator&lt;number&gt; | values(): IterableIterator&lt;number&gt; | No| / |
| includes(searchElement: number, fromIndex?: number): boolean | includes(searchElement: number, fromIndex?: number): boolean | No| / |
| at(index: number): number \| undefined | at(index: number): number \| undefined | No| / |
| new(length: number): Int8Array | constructor(length: number) | No| / |
| new(array: ArrayLike&lt;number&gt; \| ArrayBufferLike): Int8Array | constructor(array: ArrayLike&lt;number&gt; \| ArrayBuffer) | No| / |
| new(buffer: ArrayBufferLike, byteOffset?: number, length?: number): Int8Array | constructor(buffer: ArrayBuffer, byteOffset?: number, length?: number) | No| / |
| from(arrayLike: ArrayLike&lt;number&gt;): Int8Array | static from(arrayLike: ArrayLike&lt;number&gt;): Int8Array | No| / |
| from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;, mapfn: (v: T, k: number) =&gt; number, thisArg?: any): Int8Array | static from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;, mapFn: TypedArrayFromMapFn&lt;T, number&gt;): Int8Array | Yes| ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| from(arrayLike: Iterable&lt;number&gt;, mapfn?: (v: number, k: number) =&gt; number, thisArg?: any): Int8Array | static from(arrayLike: Iterable&lt;number&gt;, mapFn?: TypedArrayFromMapFn&lt;number, number&gt;): Int8Array | Yes| ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| of(...items: number[]): Int8Array | static of(...items: number[]): Int8Array | No| / |
| toString(): string | toString(): string | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| toLocaleString(): string | toLocaleString(): string  | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| lastIndexOf(searchElement: number, fromIndex?: number): number | lastIndexOf(searchElement: number, fromIndex?: number): number | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| reduceRight(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) =&gt; number): number | reduceRight(callbackFn: TypedArrayReduceCallback&lt;number, number, Int8Array&gt;): number | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| reduceRight&lt;U&gt;(callbackfn: (previousValue: U, currentValue: number, currentIndex: number, array: Int8Array) =&gt; U, initialValue: U): U | reduceRight&lt;U = number&gt;(callbackFn: TypedArrayReduceCallback&lt;U, number, Int8Array&gt;, initialValue: U): U | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|

### Map

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| -------- | -------- | -------- | -------- |
| readonly size: number | readonly size: number | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| clear(): void | clear(): void | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| delete(key: K): boolean | delete(key: K): boolean | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| forEach(callbackfn: (value: V, key: K, map: Map&lt;K, V&gt;) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: V, key: K, map: Map&lt;K, V&gt;) =&gt; void): void | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| get(key: K): V \| undefined | get(key: K): V \| undefined | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| has(key: K): boolean | has(key: K): boolean | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| set(key: K, value: V): this | set(key: K, value: V): Map&lt;K, V&gt; | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| entries(): IterableIterator&lt;[K, V]&gt; | entries(): IterableIterator&lt;[K, V]&gt; | No| / |
| keys(): IterableIterator&lt;K&gt; | keys(): IterableIterator&lt;K&gt; | No| / |
| values(): IterableIterator&lt;V&gt; | values(): IterableIterator&lt;V&gt; | No| / |
| new &lt;K, V&gt;(entries?: readonly (readonly [K, V])[] \| null): Map&lt;K, V&gt; | constructor(entries?: readonly (readonly [K, V])[] \| null) | Yes| The passed-in values of **k** and **v** during construction cannot be non-Sendable data. Otherwise, an error is reported during compilation.|

### Set

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| -------- | -------- | -------- | -------- |
| readonly size: number | readonly size: number | Yes| Computed property names (arkts-sendable-compated-prop-name) cannot be used in Sendable classes and interfaces.|
| add(value: T): this | add(value: T): Set&lt;T&gt; | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| clear(): void | clear(): void | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| delete(value: T): boolean | delete(value: T): boolean | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| forEach(callbackfn: (value: T, value2: T, set: Set&lt;T&gt;) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: T, value2: T, set: Set&lt;T&gt;) =&gt; void): void | Yes| 1. It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, the **thisArg** parameter is not supported.|
| has(value: T): boolean | has(value: T): boolean | Yes| It is not allowed to add, delete, or modify elements during iteration or access. Otherwise, an exception is thrown.|
| entries(): IterableIterator&lt;[T, T]&gt; | entries(): IterableIterator&lt;[T, T]&gt; | No| / |
| keys(): IterableIterator&lt;T&gt; | keys(): IterableIterator&lt;T&gt; | No| / |
| values(): IterableIterator&lt;T&gt; | values(): IterableIterator&lt;T&gt; | Yes| Computed property names (arkts-sendable-compated-prop-name) cannot be used in Sendable classes and interfaces.|
| new &lt;T = any&gt;(values?: readonly T[] \| null): Set&lt;T&gt; | constructor(values?: readonly T[] \| null) | Yes| The data passed during construction must be of the Sendable type. Otherwise, a compilation error is reported.|
