# ArkTS Collections与原生API方法的行为差异对比

ArkTS提供了Sendable数据相关的[容器集](../reference/apis-arkts/js-apis-arkts-collections.md)，接口行为与原生API存在部分差异，具体可见下文对比。

## Array

支持原生容器Array通过[collections.Array.from](../reference/apis-arkts/js-apis-arkts-collections.md#from)方法转换为ArkTS Array容器；支持通过原生容器Array的from方法将ArkTS Array容器转换为原生容器Array。

| 原生API方法 | ArkTS容器集方法 | 是否有行为差异 | 在ArkTS容器中的差异表现 |
| --------------------------------- | ---- | ---- | ----------------- |
| length: number |  readonly length: number  | 是 | 为了防止undefined扩散，不允许设置length。 |
| new(arrayLength ?: number): any[] |  static create(arrayLength: number, initialValue: T): Array  | 是 | 为了防止undefined扩散，构造函数中必须提供一个初始值的构造函数。 |
| new \<T>(arrayLength: number): T[] |  constructor()  | 否 | / |
| new \<T>(...items: T[]): T[] |  constructor(first: T, ...left: T[])  | 是 | 为了防止undefined扩散，构造函数中必须提供一个初始值的构造函数，继承场景下，无法调用该函数进行对象构造。 |
| from\<T>(arrayLike: ArrayLike\<T>): T[] |  static from\<T>(arrayLike: ArrayLike\<T>): Array\<T>  | 否 | / |
| pop(): T \| undefined |  pop(): T \| undefined  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| push(...items: T[]): number |  push(...items: T[]): number  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| concat(...items: ConcatArray\<T>[]): T[] |  concat(...items: ConcatArray\<T>[]): Array\<T>  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| concat(...items: (T \| ConcatArray\<T>)[]): T[] |  concat(...items: ConcatArray\<T>[]): Array\<T>  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| join(separator?: string): string |  join(separator?: string): string  | 否 | / |
| shift(): T \| undefined |  shift(): T \| undefined  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| slice(start?: number, end?: number): T[] |  slice(start?: number, end?: number): Array\<T>  | 否 | / |
| sort(compareFn?: (a: T, b: T) => number): this |  sort(compareFn?: (a: T, b: T) => number): Array\<T>  | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。<br/>2. 继承场景下，无法获得实际类型的返回值。 |
| unshift(...items: T[]): number |  unshift(...items: T[]): number  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| indexOf(searchElement: T, fromIndex?: number): number |  indexOf(searchElement: T, fromIndex?: number): number  | 否 | / |
| forEach(callbackfn: (value: T, index: number, array: T[]) => void, thisArg?: any): void |  forEach(callbackFn: (value: T, index: number, array: Array\<T>) => void): void  | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| map\<U>(callbackfn: (value: T, index: number, array: T[]) => U, thisArg?: any): U[] |  map\<U>(callbackFn: (value: T, index: number, array: Array\<T>) => U): Array\<U>  | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| filter(predicate: (value: T, index: number, array: T[]) => unknown, thisArg?: any): T[] |  filter(predicate: (value: T, index: number, array: Array\<T>) => boolean): Array\<T>  | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| reduce(callbackfn: (previousValue: T, currentValue: T, currentIndex: number, array: T[]) => T): T |  reduce(callbackFn: (previousValue: T, currentValue: T, currentIndex: number, array: Array\<T>) => T): T  | 否 | / |
| reduce\<U>(callbackfn: (previousValue: U, currentValue: T, currentIndex: number, array: T[]) => U, initialValue: U): U |  reduce\<U>(callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array\<T>) => U, initialValue: U): U | 否 | / |
| [n: number]: T |  [index: number]: T  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。 |
| findIndex(predicate: (value: T, index: number, obj: T[]) => unknown, thisArg?: any): number |  findIndex(predicate: (value: T, index: number, obj: Array\<T>) => boolean): number  | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| fill(value: T, start?: number, end?: number): this |  fill(value: T, start?: number, end?: number): Array\<T>  | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作，否则会抛出异常。<br/>2. 继承场景下，无法获得实际类型的返回值。 |
| entries(): IterableIterator\<[number, T]> | entries(): IterableIterator\<[number, T]>  | 否 | / |
| keys(): IterableIterator\<number> | keys(): IterableIterator\<number>  | 否 | / |
| values(): IterableIterator\<T> | values(): IterableIterator\<T>  | 否 | / |
| includes(searchElement: T, fromIndex?: number): boolean | includes(searchElement: T, fromIndex?: number): boolean  | 否 | / |
| at(index: number): T \| undefined | at(index: number): T \| undefined  | 否 | / |

## ArrayBuffer

| 原生API方法 | ArkTS容器集方法 | 是否有行为差异 | 在ArkTS容器中的差异表现 |
| --------------------------------- | ---- | ---- | ----------------- |
| readonly byteLength: number | readonly byteLength: number  | 否 | / |
| slice(begin: number, end?: number): ArrayBuffer | slice(begin: number, end?: number): ArrayBuffer  | 否 | / |
| new(byteLength: number): ArrayBuffer | constructor(byteLength: number)  | 否 | / |

## TypedArray（以Int8Array为例）

支持原生容器TypedArray通过[collections.TypedArray.from](../reference/apis-arkts/js-apis-arkts-collections.md#from-1)方法转换为ArkTS TypedArray容器；支持通过原生容器TypedArray的from方法将ArkTS TypedArray容器转换为原生容器TypedArray。

| 原生API方法 | ArkTS容器集方法 | 是否有行为差异 | 在ArkTS容器中的差异表现 |
| --------------------------------- | ---- | ---- | ----------------- |
| readonly buffer: ArrayBufferLike | readonly buffer: ArrayBuffer | 否 | / |
| readonly byteLength: number | readonly byteLength: number  | 否 | / |
| readonly byteOffset: number | readonly byteOffset: number | 否 | / |
| readonly length: number | readonly length: number | 否 | / |
| readonly BYTES_PER_ELEMENT: number | static readonly BYTES_PER_ELEMENT: number | 否 | / |
| copyWithin(target: number, start: number, end?: number): this | copyWithin(target: number, start: number, end?: number): Int8Array | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| every(predicate: (value: number, index: number, array: Int8Array) => unknown, thisArg?: any): boolean | every(predicate: TypedArrayPredicateFn\<number, Int8Array>): boolean | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| fill(value: number, start?: number, end?: number): this | fill(value: number, start?: number, end?: number): Int8Array | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| filter(predicate: (value: number, index: number, array: Int8Array) => any, thisArg?: any): Int8Array | filter(predicate: TypedArrayPredicateFn\<number, Int8Array>): Int8Array | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| find(predicate: (value: number, index: number, obj: Int8Array) => boolean, thisArg?: any): number \| undefined | find(predicate: TypedArrayPredicateFn\<number, Int8Array>): number \| undefined | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| findIndex(predicate: (value: number, index: number, obj: Int8Array) => boolean, thisArg?: any): number | findIndex(predicate: TypedArrayPredicateFn\<number, Int8Array>): number | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| forEach(callbackfn: (value: number, index: number, array: Int8Array) => void, thisArg?: any): void | forEach(callbackFn: (value: number, index: number, array: Int8Array) => void): void | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| indexOf(searchElement: number, fromIndex?: number): number | indexOf(searchElement: number, fromIndex?: number): number | 否 | / |
| join(separator?: string): string | join(separator?: string): string | 否 | / |
| map(callbackfn: (value: number, index: number, array: Int8Array) => number, thisArg?: any): Int8Array | map(callbackFn: TypedArrayForEachCallback\<number, Int8Array>): Int8Array | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| reduce(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) => number): number | reduce(callbackFn: TypedArrayReduceCallback\<number, number, Int8Array>): number | 否 | / |
| reduce(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) => number, initialValue: number): number | reduce(callbackFn: TypedArrayReduceCallback\<number, number, Int8Array>, initialValue: number): number | 否 | / |
| reduce\<U>(callbackfn: (previousValue: U, currentValue: number, currentIndex: number, array: Int8Array) => U, initialValue: U): U | reduce\<U>(callbackFn: TypedArrayReduceCallback\<U, number, Int8Array>, initialValue: U): U | 否 | / |
| reverse(): Int8Array | reverse(): Int8Array | 否 | / |
| set(array: ArrayLike\<number>, offset?: number): void | set(array: ArrayLike\<number>, offset?: number): void | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| slice(start?: number, end?: number): Int8Array | slice(start?: number, end?: number): Int8Array | 否 | / |
| some(predicate: (value: number, index: number, array: Int8Array) => unknown, thisArg?: any): boolean | some(predicate: TypedArrayPredicateFn\<number, Int8Array>): boolean | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| sort(compareFn?: (a: number, b: number) => number): this | sort(compareFn?: TypedArrayCompareFn\<number>): Int8Array | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. 继承场景下，无法获得实际类型的返回值。 |
| subarray(begin?: number, end?: number): Int8Array | subarray(begin?: number, end?: number): Int8Array | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| [index: number]: number | [index: number]: number | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| entries(): IterableIterator\<[number, number]> | entries(): IterableIterator\<[number, number]> | 否 | / |
| keys(): IterableIterator\<number> | keys(): IterableIterator\<number> | 否 | / |
| values(): IterableIterator\<number> | values(): IterableIterator\<number> | 否 | / |
| includes(searchElement: number, fromIndex?: number): boolean | includes(searchElement: number, fromIndex?: number): boolean | 否 | / |
| at(index: number): number \| undefined | at(index: number): number \| undefined | 否 | / |
| new(length: number): Int8Array | constructor(length: number) | 否 | / |
| new(array: ArrayLike\<number> \| ArrayBufferLike): Int8Array | constructor(array: ArrayLike\<number> \| ArrayBuffer) | 否 | / |
| new(buffer: ArrayBufferLike, byteOffset?: number, length?: number): Int8Array | constructor(buffer: ArrayBuffer, byteOffset?: number, length?: number) | 否 | / |
| from(arrayLike: ArrayLike\<number>): Int8Array | static from(arrayLike: ArrayLike\<number>): Int8Array | 否 | / |
| from\<T>(arrayLike: ArrayLike\<T>, mapfn: (v: T, k: number) => number, thisArg?: any): Int8Array | static from\<T>(arrayLike: ArrayLike\<T>, mapFn: TypedArrayFromMapFn\<T, number>): Int8Array | 是 | ArkTS不支持this，因此不支持thisArg参数。 |
| from(arrayLike: Iterable\<number>, mapfn?: (v: number, k: number) => number, thisArg?: any): Int8Array | static from(arrayLike: Iterable\<number>, mapFn?: TypedArrayFromMapFn\<number, number>): Int8Array | 是 | ArkTS不支持this，因此不支持thisArg参数。 |

## Map

| 原生API方法 | ArkTS容器集方法 | 是否有行为差异 | 在ArkTS容器中的差异表现 |
| --------------------------------- | ---- | ---- | ----------------- |
| readonly size: number | readonly size: number  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| clear(): void | clear(): void  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| delete(key: K): boolean | delete(key: K): boolean  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| forEach(callbackfn: (value: V, key: K, map: Map\<K, V>) => void, thisArg?: any): void | forEach(callbackFn: (value: V, key: K, map: Map\<K, V>) => void): void  | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| get(key: K): V \| undefined | get(key: K): V \| undefined  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| has(key: K): boolean | has(key: K): boolean  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| set(key: K, value: V): this | set(key: K, value: V): Map\<K, V>  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| entries(): IterableIterator\<[K, V]> | entries(): IterableIterator\<[K, V]>  | 否 | / |
| keys(): IterableIterator\<K> | keys(): IterableIterator\<K>  | 否 | / |
| values(): IterableIterator\<V> | values(): IterableIterator\<V>  | 否 | / |
| new \<K, V>(entries?: readonly (readonly [K, V])[] \| null): Map\<K, V> | constructor(entries?: readonly (readonly [K, V])[] \| null)  | 是 | 构造时传入的k,v键值不能是非[Sendable数据](arkts-sendable.md)，否则编译会报错。 |

## Set

| 原生API方法 | ArkTS容器集方法 | 是否有行为差异 | 在ArkTS容器中的差异表现 |
| --------------------------------- | ---- | ---- | ----------------- |
| readonly size: number | readonly size: number  | 是 | Sendable类和接口中不允许使用计算属性名称(arkts-sendable-compated-prop-name)。 |
| add(value: T): this | add(value: T): Set\<T>  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| clear(): void | clear(): void  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| delete(value: T): boolean | delete(value: T): boolean  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| forEach(callbackfn: (value: T, value2: T, set: Set\<T>) => void, thisArg?: any): void | forEach(callbackFn: (value: T, value2: T, set: Set\<T>) => void): void  | 是 | 1. 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。<br/>2. ArkTS不支持this，因此不支持thisArg参数。 |
| has(value: T): boolean | has(value: T): boolean  | 是 | 不允许在遍历、访问过程中进行元素的增、删、改操作否则会抛出异常。 |
| entries(): IterableIterator\<[T, T]> | entries(): IterableIterator\<[T, T]>  | 否 | / |
| keys(): IterableIterator\<T> | keys(): IterableIterator\<T>  | 否 | / |
| values(): IterableIterator\<T> | values(): IterableIterator\<T>  | 是 | Sendable类和接口中不允许使用计算属性名称(arkts-sendable-compated-prop-name)。 |
| new \<T = any>(values?: readonly T[] \| null): Set\<T> | constructor(values?: readonly T[] \| null)  | 是 | 构造时传入数据不能是非[Sendable数据](arkts-sendable.md)，否则编译会报错。 |