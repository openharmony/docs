# Behavior Differences Between ArkTS Collections APIs and Native APIs

ArkTS provides [Collections](../reference/apis-arkts/js-apis-arkts-collections.md) related to sendable data. The behavior of the Collections APIs is different from that of native APIs, as described below.

## Array

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| --------------------------------- | ---- | ---- | ----------------- |
| length: number |  readonly length: number  | Yes| To prevent the spread of undefined, it is not allowed to set **length**.|
| new(arrayLength ?: number): any[] |  static create(arrayLength: number, initialValue: T): Array  | Yes| To prevent the spread of undefined, a constructor must be provided with an initial value.|
| new \<T>(arrayLength: number): T[] |  constructor()  | No| / |
| new \<T>(...items: T[]): T[] |  constructor(first: T, ...left: T[])  | Yes| To prevent the spread of undefined, a constructor must be provided with an initial value. In inheritance scenarios, this constructor cannot be called to construct an object.|
| from\<T>(arrayLike: ArrayLike\<T>): T[] |  static from\<T>(arrayLike: ArrayLike\<T>): Array\<T>  | No| / |
| pop(): T \| undefined |  pop(): T \| undefined  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| push(...items: T[]): number |  push(...items: T[]): number  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| concat(...items: ConcatArray\<T>[]): T[] |  concat(...items: ConcatArray\<T>[]): Array\<T>  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| concat(...items: (T \| ConcatArray\<T>)[]): T[] |  concat(...items: ConcatArray\<T>[]): Array\<T>  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| join(separator?: string): string |  join(separator?: string): string  | No| / |
| shift(): T \| undefined |  shift(): T \| undefined  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| slice(start?: number, end?: number): T[] |  slice(start?: number, end?: number): Array\<T>  | No| / |
| sort(compareFn?: (a: T, b: T) => number): this |  sort(compareFn?: (a: T, b: T) => number): Array\<T>  | Yes| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. In inheritance scenarios, the actual return value type cannot be obtained.|
| unshift(...items: T[]): number |  unshift(...items: T[]): number  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| indexOf(searchElement: T, fromIndex?: number): number |  indexOf(searchElement: T, fromIndex?: number): number  | No| / |
| forEach(callbackfn: (value: T, index: number, array: T[]) => void, thisArg?: any): void |  forEach(callbackFn: (value: T, index: number, array: Array\<T>) => void): void  | Yes| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| map\<U>(callbackfn: (value: T, index: number, array: T[]) => U, thisArg?: any): U[] |  map\<U>(callbackFn: (value: T, index: number, array: Array\<T>) => U): Array\<U>  | Yes| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| filter(predicate: (value: T, index: number, array: T[]) => unknown, thisArg?: any): T[] |  filter(predicate: (value: T, index: number, array: Array\<T>) => boolean): Array\<T>  | Yes| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| reduce(callbackfn: (previousValue: T, currentValue: T, currentIndex: number, array: T[]) => T): T |  reduce(callbackFn: (previousValue: T, currentValue: T, currentIndex: number, array: Array\<T>) => T): T  | No| / |
| reduce\<U>(callbackfn: (previousValue: U, currentValue: T, currentIndex: number, array: T[]) => U, initialValue: U): U |  reduce\<U>(callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array\<T>) => U, initialValue: U): U | No| / |
| [n: number]: T |  [index: number]: T  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| findIndex(predicate: (value: T, index: number, obj: T[]) => unknown, thisArg?: any): number |  findIndex(predicate: (value: T, index: number, obj: Array\<T>) => boolean): number  | Yes| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| fill(value: T, start?: number, end?: number): this |  fill(value: T, start?: number, end?: number): Array\<T>  | Yes| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. In inheritance scenarios, the actual return value type cannot be obtained.|
| entries(): IterableIterator\<[number, T]> | entries(): IterableIterator\<[number, T]>  | No| / |
| keys(): IterableIterator\<number> | keys(): IterableIterator\<number>  | No| / |
| values(): IterableIterator\<T> | values(): IterableIterator\<T>  | No| / |
| includes(searchElement: T, fromIndex?: number): boolean | includes(searchElement: T, fromIndex?: number): boolean  | No| / |
| at(index: number): T \| undefined | at(index: number): T \| undefined  | No| / |

## ArrayBuffer

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| --------------------------------- | ---- | ---- | ----------------- |
| readonly byteLength: number | readonly byteLength: number  | No| / |
| slice(begin: number, end?: number): ArrayBuffer | slice(begin: number, end?: number): ArrayBuffer  | No| / |
| new(byteLength: number): ArrayBuffer | constructor(byteLength: number)  | No| / |

## TypedArray (Int8Array Used as an Example)

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| --------------------------------- | ---- | ---- | ----------------- |
| readonly buffer: ArrayBufferLike | readonly buffer: ArrayBuffer | No| / |
| readonly byteLength: number | readonly byteLength: number  | No| / |
| readonly byteOffset: number | readonly byteOffset: number | No| / |
| readonly length: number | readonly length: number | No| / |
| readonly BYTES_PER_ELEMENT: number | static readonly BYTES_PER_ELEMENT: number | No| / |
| copyWithin(target: number, start: number, end?: number): this | copyWithin(target: number, start: number, end?: number): Int8Array | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| every(predicate: (value: number, index: number, array: Int8Array) => unknown, thisArg?: any): boolean | every(predicate: TypedArrayPredicateFn\<number, Int8Array>): boolean | Yes| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| fill(value: number, start?: number, end?: number): this | fill(value: number, start?: number, end?: number): Int8Array | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| filter(predicate: (value: number, index: number, array: Int8Array) => any, thisArg?: any): Int8Array | filter(predicate: TypedArrayPredicateFn\<number, Int8Array>): Int8Array | Yes| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| find(predicate: (value: number, index: number, obj: Int8Array) => boolean, thisArg?: any): number \| undefined | find(predicate: TypedArrayPredicateFn\<number, Int8Array>): number \| undefined | Yes| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| findIndex(predicate: (value: number, index: number, obj: Int8Array) => boolean, thisArg?: any): number | findIndex(predicate: TypedArrayPredicateFn\<number, Int8Array>): number | Yes| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| forEach(callbackfn: (value: number, index: number, array: Int8Array) => void, thisArg?: any): void | forEach(callbackFn: (value: number, index: number, array: Int8Array) => void): void | Yes| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| indexOf(searchElement: number, fromIndex?: number): number | indexOf(searchElement: number, fromIndex?: number): number | No| / |
| join(separator?: string): string | join(separator?: string): string | No| / |
| map(callbackfn: (value: number, index: number, array: Int8Array) => number, thisArg?: any): Int8Array | map(callbackFn: TypedArrayForEachCallback\<number, Int8Array>): Int8Array | Yes| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| reduce(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) => number): number | reduce(callbackFn: TypedArrayReduceCallback\<number, number, Int8Array>): number | No| / |
| reduce(callbackfn: (previousValue: number, currentValue: number, currentIndex: number, array: Int8Array) => number, initialValue: number): number | reduce(callbackFn: TypedArrayReduceCallback\<number, number, Int8Array>, initialValue: number): number | No| / |
| reduce\<U>(callbackfn: (previousValue: U, currentValue: number, currentIndex: number, array: Int8Array) => U, initialValue: U): U | reduce\<U>(callbackFn: TypedArrayReduceCallback\<U, number, Int8Array>, initialValue: U): U | No| / |
| reverse(): Int8Array | reverse(): Int8Array | No| / |
| set(array: ArrayLike\<number>, offset?: number): void | set(array: ArrayLike\<number>, offset?: number): void | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| slice(start?: number, end?: number): Int8Array | slice(start?: number, end?: number): Int8Array | No| / |
| some(predicate: (value: number, index: number, array: Int8Array) => unknown, thisArg?: any): boolean | some(predicate: TypedArrayPredicateFn\<number, Int8Array>): boolean | Yes| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| sort(compareFn?: (a: number, b: number) => number): this | sort(compareFn?: TypedArrayCompareFn\<number>): Int8Array | Yes| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. In inheritance scenarios, the actual return value type cannot be obtained.|
| subarray(begin?: number, end?: number): Int8Array | subarray(begin?: number, end?: number): Int8Array | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| [index: number]: number | [index: number]: number | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| entries(): IterableIterator\<[number, number]> | entries(): IterableIterator\<[number, number]> | No| / |
| keys(): IterableIterator\<number> | keys(): IterableIterator\<number> | No| / |
| values(): IterableIterator\<number> | values(): IterableIterator\<number> | No| / |
| includes(searchElement: number, fromIndex?: number): boolean | includes(searchElement: number, fromIndex?: number): boolean | No| / |
| at(index: number): number \| undefined | at(index: number): number \| undefined | No| / |
| new(length: number): Int8Array | constructor(length: number) | No| / |
| new(array: ArrayLike\<number> \| ArrayBufferLike): Int8Array | constructor(array: ArrayLike\<number> \| ArrayBuffer) | No| / |
| new(buffer: ArrayBufferLike, byteOffset?: number, length?: number): Int8Array | constructor(buffer: ArrayBuffer, byteOffset?: number, length?: number) | No| / |
| from(arrayLike: ArrayLike\<number>): Int8Array | static from(arrayLike: ArrayLike\<number>): Int8Array | No| / |
| from\<T>(arrayLike: ArrayLike\<T>, mapfn: (v: T, k: number) => number, thisArg?: any): Int8Array | static from\<T>(arrayLike: ArrayLike\<T>, mapFn: TypedArrayFromMapFn\<T, number>): Int8Array | Yes| ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| from(arrayLike: Iterable\<number>, mapfn?: (v: number, k: number) => number, thisArg?: any): Int8Array | static from(arrayLike: Iterable\<number>, mapFn?: TypedArrayFromMapFn\<number, number>): Int8Array | Yes| ArkTS does not support **this**. As a result, **thisArg** is not supported.|

## Map

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| --------------------------------- | ---- | ---- | ----------------- |
| readonly size: number | readonly size: number  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| clear(): void | clear(): void  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| delete(key: K): boolean | delete(key: K): boolean  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| forEach(callbackfn: (value: V, key: K, map: Map\<K, V>) => void, thisArg?: any): void | forEach(callbackFn: (value: V, key: K, map: Map\<K, V>) => void): void  | Yes| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| get(key: K): V \| undefined | get(key: K): V \| undefined  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| has(key: K): boolean | has(key: K): boolean  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| set(key: K, value: V): this | set(key: K, value: V): Map\<K, V>  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| entries(): IterableIterator\<[K, V]> | entries(): IterableIterator\<[K, V]>  | No| / |
| keys(): IterableIterator\<K> | keys(): IterableIterator\<K>  | No| / |
| values(): IterableIterator\<V> | values(): IterableIterator\<V>  | No| / |
| new \<K, V>(entries?: readonly (readonly [K, V])[] \| null): Map\<K, V> | constructor(entries?: readonly (readonly [K, V])[] \| null)  | Yes| The passed-in values of **k** and **v** during construction cannot be [non-sendable data](arkts-sendable.md). Otherwise, an error is reported during compilation.|

## Set

| Native API| ArkTS Collections API| Behavior Difference Exists| Different Behavior in ArkTS Collections|
| --------------------------------- | ---- | ---- | ----------------- |
| readonly size: number | readonly size: number  | Yes| The **arkts-sendable-compated-prop-name** cannot be used in the Sendable class and APIs.|
| add(value: T): this | add(value: T): Set\<T>  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| clear(): void | clear(): void  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| delete(value: T): boolean | delete(value: T): boolean  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| forEach(callbackfn: (value: T, value2: T, set: Set\<T>) => void, thisArg?: any): void | forEach(callbackFn: (value: T, value2: T, set: Set\<T>) => void): void  | Yes| 1. It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.<br>2. ArkTS does not support **this**. As a result, **thisArg** is not supported.|
| has(value: T): boolean | has(value: T): boolean  | Yes| It is not allowed to add, delete, or modify elements during traversal or access. Otherwise, an exception is thrown.|
| entries(): IterableIterator\<[T, T]> | entries(): IterableIterator\<[T, T]>  | No| / |
| keys(): IterableIterator\<T> | keys(): IterableIterator\<T>  | No| / |
| values(): IterableIterator\<T> | values(): IterableIterator\<T>  | Yes| The **arkts-sendable-compated-prop-name** cannot be used in the Sendable class and APIs.|
| new \<T = any>(values?: readonly T[] \| null): Set\<T> | constructor(values?: readonly T[] \| null)  | Yes| The passed-in values during construction cannot be [non-sendable data](arkts-sendable.md). Otherwise, an error is reported during compilation.|
