# 共享容器

## ArkTS容器集

ArkTS共享容器（[@arkts.collections (ArkTS容器集)](../reference/apis-arkts/js-apis-arkts-collections.md)）是一种在并发任务间共享传输的容器类，可以用于并发场景下的高性能数据传递。功能与Ecmascript262规范定义的容器类似，但仍然有部分差异，具体可见[共享容器与原生API方法的行为差异对比](#共享容器与原生api方法的行为差异对比)。

ArkTS共享容器在多个并发任务间传递时，默认采用引用传递，允许多个并发任务操作同一个容器实例。此外，还支持拷贝传递，即每个并发任务拥有一个独立的ArkTS容器实例。

ArkTS共享容器不是线程安全的，内部使用了fail-fast（快速失败）机制，即当检测到多个并发实例同时对容器进行结构性修改时，会触发异常。因此，在容器内修改属性的场景下，开发者需要使用ArkTS提供的[异步锁](arkts-async-lock-introduction.md)机制保证ArkTS容器的安全访问。

ArkTS共享容器包含如下几种：[Array](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsarray)、[Map](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsmap)、[Set](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsset)、[TypedArray](../reference/apis-arkts/js-apis-arkts-collections.md#collectionstypedarray)（Int8Array、Uint8Array、Int16Array、Uint16Array、Int32Array、Uint32Array、Uint8ClampedArray、Float32Array）、[ArrayBuffer](../reference/apis-arkts/js-apis-arkts-collections.md#collectionsarraybuffer)等，具体可见[@arkts.collections (ArkTS容器集)](../reference/apis-arkts/js-apis-arkts-collections.md)。

容器集使用示例如下：

```ts
import { ArkTSUtils, collections, taskpool } from '@kit.ArkTS';

@Concurrent
async function add(arr: collections.Array<number>, lock: ArkTSUtils.locks.AsyncLock) {
 await lock.lockAsync(() => {  // 如果不添加异步锁，任务会因为数据竞争冲突，导致抛异常失败
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

## 共享容器与原生API方法的行为差异对比

ArkTS提供了Sendable数据相关的共享容器集，接口行为与原生API存在部分差异，具体可见下文对比。

> **说明：**
>
> ArkTS共享容器的类型与Ecmascript262规范定义的原生容器的类型不同，因此使用原生容器Array的isArray()方法判断collections.Array实例对象会返回false。
>
> ArkTS共享容器跨线程传递采用引用传递方式，与原生容器相比效率更高，如果开发者需要跨线程传输的数据量很大，建议使用ArkTS共享容器。

### Array

支持原生容器Array通过[collections.Array.from](../reference/apis-arkts/js-apis-arkts-collections.md#from)方法转换为ArkTS Array容器；支持通过原生容器Array的from方法将ArkTS Array容器转换为原生容器Array。

| 原生API方法 | ArkTS容器集方法 | 是否有行为差异 | 在ArkTS容器中的差异表现 |
| -------- | -------- | -------- | -------- |
| length: number | readonly length: number | 是 | 为了防止undefined扩散，不允许设置length。 |
| new(arrayLength ?: number): any[] | static create(arrayLength: number, initialValue: T): Array | 是 | 为了防止undefined扩散，构造函数中必须提供一个初始值。 |
| new &lt;T&gt;(arrayLength: number): T[] | constructor() | 否 | / |
| new &lt;T&gt;(...items: T[]): T[] | constructor(first: T, ...left: T[]) | 是 | 为了防止undefined扩散，构造函数中必须提供一个初始值，继承场景下，无法调用该函数进行对象构造。 |
| from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;): T[] | static from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;): Array&lt;T&gt; | 否 | / |
| pop(): T \| undefined | pop(): T \| undefined | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| push(...items: T[]): number | push(...items: T[]): number | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| concat(...items: ConcatArray&lt;T&gt;[]): T[] | concat(...items: ConcatArray&lt;T&gt;[]): Array&lt;T&gt; | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| concat(...items: (T \| ConcatArray&lt;T&gt;)[]): T[] | concat(...items: ConcatArray&lt;T&gt;[]): Array&lt;T&gt; | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| join(separator?: string): string | join(separator?: string): string | 否 | / |
| shift(): T \| undefined | shift(): T \| undefined | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| slice(start?: number, end?: number): T[] | slice(start?: number, end?: number): Array&lt;T&gt; | 否 | / |
| sort(compareFn?: (a: T, b: T) =&gt; number): this | sort(compareFn?: (a: T, b: T) =&gt; number): Array&lt;T&gt; | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。<br/>2. 继承场景下，无法获得实际类型的返回值。 |
| unshift(...items: T[]): number | unshift(...items: T[]): number | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| indexOf(searchElement: T, fromIndex?: number): number | indexOf(searchElement: T, fromIndex?: number): number | 否 | / |
| forEach(callbackfn: (value: T, index: number, array: T[]) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: T, index: number, array: Array&lt;T&gt;) =&gt; void): void | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| map&lt;U&gt;(callbackfn: (value: T, index: number, array: T[]) =&gt; U, thisArg?: any): U[] | map&lt;U&gt;(callbackFn: (value: T, index: number, array: Array&lt;T&gt;) =&gt; U): Array&lt;U&gt; | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| filter(predicate: (value: T, index: number, array: T[]) =&gt; unknown, thisArg?: any): T[] | filter(predicate: (value: T, index: number, array: Array&lt;T&gt;) =&gt; boolean): Array&lt;T&gt; | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| reduce(callbackfn: (previousValue: T, currentValue: T, currentIndex: number, array: T[]) =&gt; T): T | reduce(callbackFn: (previousValue: T, currentValue: T, currentIndex: number, array: Array&lt;T&gt;) =&gt; T): T | 否 | / |
| reduce&lt;U&gt;(callbackfn: (previousValue: U, currentValue: T, currentIndex: number, array: T[]) =&gt; U, initialValue: U): U | reduce&lt;U&gt;(callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array&lt;T&gt;) =&gt; U, initialValue: U): U | 否 | / |
| [n: number]: T | [index: number]: T | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| findIndex(predicate: (value: T, index: number, obj: T[]) =&gt; unknown, thisArg?: any): number | findIndex(predicate: (value: T, index: number, obj: Array&lt;T&gt;) =&gt; boolean): number | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| fill(value: T, start?: number, end?: number): this | fill(value: T, start?: number, end?: number): Array&lt;T&gt; | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。<br/>2. 继承场景下，无法获得实际类型的返回值。 |
| entries(): IterableIterator&lt;[number, T]&gt; | entries(): IterableIterator&lt;[number, T]&gt; | 否 | / |
| keys(): IterableIterator&lt;number&gt; | keys(): IterableIterator&lt;number&gt; | 否 | / |
| values(): IterableIterator&lt;T&gt; | values(): IterableIterator&lt;T&gt; | 否 | / |
| includes(searchElement: T, fromIndex?: number): boolean | includes(searchElement: T, fromIndex?: number): boolean | 否 | / |
| at(index: number): T \| undefined | at(index: number): T \| undefined | 否 | / |

### ArrayBuffer

| 原生API方法 | ArkTS容器集方法 | 是否有行为差异 | 在ArkTS容器中的差异表现 |
| -------- | -------- | -------- | -------- |
| readonly byteLength: number | readonly byteLength: number | 否 | / |
| slice(begin: number, end?: number): ArrayBuffer | slice(begin: number, end?: number): ArrayBuffer | 否 | / |
| new(byteLength: number): ArrayBuffer | constructor(byteLength: number) | 否 | / |

### TypedArray（以Int8Array为例）

支持原生容器TypedArray通过[collections.TypedArray.from](../reference/apis-arkts/js-apis-arkts-collections.md#from-1)方法转换为ArkTS TypedArray容器；支持通过原生容器TypedArray的from方法将ArkTS TypedArray容器转换为原生容器TypedArray。

| 原生API方法 | ArkTS容器集方法 | 是否有行为差异 | 在ArkTS容器中的差异表现 |
| -------- | -------- | -------- | -------- |
| readonly buffer: ArrayBufferLike | readonly buffer: ArrayBuffer | 否 | / |
| readonly byteLength: number | readonly byteLength: number | 否 | / |
| readonly byteOffset: number | readonly byteOffset: number | 否 | / |
| readonly length: number | readonly length: number | 否 | / |
| readonly BYTES_PER_ELEMENT: number | static readonly BYTES_PER_ELEMENT: number | 否 | / |
| copyWithin(target: number, start: number, end?: number): this | copyWithin(target: number, start: number, end?: number): Int8Array | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| every(predicate: (value: number, index: number, array: Int8Array) =&gt; unknown, thisArg?: any): boolean | every(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): boolean | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| fill(value: number, start?: number, end?: number): this | fill(value: number, start?: number, end?: number): Int8Array | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| filter(predicate: (value: number, index: number, array: Int8Array) =&gt; any, thisArg?: any): Int8Array | filter(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): Int8Array | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| find(predicate: (value: number, index: number, obj: Int8Array) =&gt; boolean, thisArg?: any): number \| undefined | find(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): number \| undefined | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| findIndex(predicate: (value: number, index: number, obj: Int8Array) =&gt; boolean, thisArg?: any): number | findIndex(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): number | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| forEach(callbackfn: (value: number, index: number, array: Int8Array) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: number, index: number, array: Int8Array) =&gt; void): void | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| indexOf(searchElement: number, fromIndex?: number): number | indexOf(searchElement: number, fromIndex?: number): number | 否 | / |
| join(separator?: string): string | join(separator?: string): string | 否 | / |
| map(callbackfn: (value: number, index: number, array: Int8Array) =&gt; number, thisArg?: any): Int8Array | map(callbackFn: TypedArrayForEachCallback&lt;number, Int8Array&gt;): Int8Array | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| reduce(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) =&gt; number): number | reduce(callbackFn: TypedArrayReduceCallback&lt;number, number, Int8Array&gt;): number | 否 | / |
| reduce(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) =&gt; number, initialValue: number): number | reduce(callbackFn: TypedArrayReduceCallback&lt;number, number, Int8Array&gt;, initialValue: number): number | 否 | / |
| reduce&lt;U&gt;(callbackfn: (previousValue: U, currentValue: number, currentIndex: number, array: Int8Array) =&gt; U, initialValue: U): U | reduce&lt;U&gt;(callbackFn: TypedArrayReduceCallback&lt;U, number, Int8Array&gt;, initialValue: U): U | 否 | / |
| reverse(): Int8Array | reverse(): Int8Array | 否 | / |
| set(array: ArrayLike&lt;number&gt;, offset?: number): void | set(array: ArrayLike&lt;number&gt;, offset?: number): void | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| slice(start?: number, end?: number): Int8Array | slice(start?: number, end?: number): Int8Array | 否 | / |
| some(predicate: (value: number, index: number, array: Int8Array) =&gt; unknown, thisArg?: any): boolean | some(predicate: TypedArrayPredicateFn&lt;number, Int8Array&gt;): boolean | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| sort(compareFn?: (a: number, b: number) =&gt; number): this | sort(compareFn?: TypedArrayCompareFn&lt;number&gt;): Int8Array | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. 继承场景下，无法获得实际类型的返回值。 |
| subarray(begin?: number, end?: number): Int8Array | subarray(begin?: number, end?: number): Int8Array | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| [index: number]: number | [index: number]: number | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| entries(): IterableIterator&lt;[number, number]&gt; | entries(): IterableIterator&lt;[number, number]&gt; | 否 | / |
| keys(): IterableIterator&lt;number&gt; | keys(): IterableIterator&lt;number&gt; | 否 | / |
| values(): IterableIterator&lt;number&gt; | values(): IterableIterator&lt;number&gt; | 否 | / |
| includes(searchElement: number, fromIndex?: number): boolean | includes(searchElement: number, fromIndex?: number): boolean | 否 | / |
| at(index: number): number \| undefined | at(index: number): number \| undefined | 否 | / |
| new(length: number): Int8Array | constructor(length: number) | 否 | / |
| new(array: ArrayLike&lt;number&gt; \| ArrayBufferLike): Int8Array | constructor(array: ArrayLike&lt;number&gt; \| ArrayBuffer) | 否 | / |
| new(buffer: ArrayBufferLike, byteOffset?: number, length?: number): Int8Array | constructor(buffer: ArrayBuffer, byteOffset?: number, length?: number) | 否 | / |
| from(arrayLike: ArrayLike&lt;number&gt;): Int8Array | static from(arrayLike: ArrayLike&lt;number&gt;): Int8Array | 否 | / |
| from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;, mapfn: (v: T, k: number) =&gt; number, thisArg?: any): Int8Array | static from&lt;T&gt;(arrayLike: ArrayLike&lt;T&gt;, mapFn: TypedArrayFromMapFn&lt;T, number&gt;): Int8Array | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| from(arrayLike: Iterable&lt;number&gt;, mapfn?: (v: number, k: number) =&gt; number, thisArg?: any): Int8Array | static from(arrayLike: Iterable&lt;number&gt;, mapFn?: TypedArrayFromMapFn&lt;number, number&gt;): Int8Array | 是 | ArkTS不支持this，因此不支持thisArg参数。 |

### Map

| 原生API方法 | ArkTS容器集方法 | 是否有行为差异 | 在ArkTS容器中的差异表现 |
| -------- | -------- | -------- | -------- |
| readonly size: number | readonly size: number | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| clear(): void | clear(): void | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| delete(key: K): boolean | delete(key: K): boolean | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| forEach(callbackfn: (value: V, key: K, map: Map&lt;K, V&gt;) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: V, key: K, map: Map&lt;K, V&gt;) =&gt; void): void | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| get(key: K): V \| undefined | get(key: K): V \| undefined | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| has(key: K): boolean | has(key: K): boolean | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| set(key: K, value: V): this | set(key: K, value: V): Map&lt;K, V&gt; | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| entries(): IterableIterator&lt;[K, V]&gt; | entries(): IterableIterator&lt;[K, V]&gt; | 否 | / |
| keys(): IterableIterator&lt;K&gt; | keys(): IterableIterator&lt;K&gt; | 否 | / |
| values(): IterableIterator&lt;V&gt; | values(): IterableIterator&lt;V&gt; | 否 | / |
| new &lt;K, V&gt;(entries?: readonly (readonly [K, V])[] \| null): Map&lt;K, V&gt; | constructor(entries?: readonly (readonly [K, V])[] \| null) | 是 | 构造时传入的k,v键值不能是非Sendable数据，否则编译会报错。 |

### Set

| 原生API方法 | ArkTS容器集方法 | 是否有行为差异 | 在ArkTS容器中的差异表现 |
| -------- | -------- | -------- | -------- |
| readonly size: number | readonly size: number | 是 | Sendable类和接口中不允许使用计算属性名称(arkts-sendable-compated-prop-name)。 |
| add(value: T): this | add(value: T): Set&lt;T&gt; | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| clear(): void | clear(): void | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| delete(value: T): boolean | delete(value: T): boolean | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| forEach(callbackfn: (value: T, value2: T, set: Set&lt;T&gt;) =&gt; void, thisArg?: any): void | forEach(callbackFn: (value: T, value2: T, set: Set&lt;T&gt;) =&gt; void): void | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| has(value: T): boolean | has(value: T): boolean | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| entries(): IterableIterator&lt;[T, T]&gt; | entries(): IterableIterator&lt;[T, T]&gt; | 否 | / |
| keys(): IterableIterator&lt;T&gt; | keys(): IterableIterator&lt;T&gt; | 否 | / |
| values(): IterableIterator&lt;T&gt; | values(): IterableIterator&lt;T&gt; | 是 | Sendable类和接口中不允许使用计算属性名称(arkts-sendable-compated-prop-name)。 |
| new &lt;T = any&gt;(values?: readonly T[] \| null): Set&lt;T&gt; | constructor(values?: readonly T[] \| null) | 是 | 构造时传入的数据必须是Sendable类型，否则编译会报错。 |
