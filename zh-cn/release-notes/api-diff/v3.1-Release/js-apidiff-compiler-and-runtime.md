# 公共基础库子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，公共基础库子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.xml | XmlPullParser | parse(option: ParseOptions): void; | 新增 |
| ohos.xml | XmlPullParser | constructor(buffer: ArrayBuffer \| DataView, encoding?: string); | 新增 |
| ohos.xml | ParseOptions | tokenValueCallbackFunction?: (eventType: EventType, value: ParseInfo) => boolean; | 新增 |
| ohos.xml | ParseOptions | attributeValueCallbackFunction?: (name: string, value: string) => boolean; | 新增 |
| ohos.xml | ParseOptions | tagValueCallbackFunction?: (name: string, value: string) => boolean; | 新增 |
| ohos.xml | ParseOptions | ignoreNameSpace?: boolean; | 新增 |
| ohos.xml | ParseOptions | supportDoctype?: boolean; | 新增 |
| ohos.xml | ParseInfo | getAttributeCount(): number; | 新增 |
| ohos.xml | ParseInfo | isWhitespace(): boolean; | 新增 |
| ohos.xml | ParseInfo | isEmptyElementTag(): boolean; | 新增 |
| ohos.xml | ParseInfo | getText(): string; | 新增 |
| ohos.xml | ParseInfo | getPrefix(): string; | 新增 |
| ohos.xml | ParseInfo | getNamespace(): string; | 新增 |
| ohos.xml | ParseInfo | getName(): string; | 新增 |
| ohos.xml | ParseInfo | getLineNumber(): number; | 新增 |
| ohos.xml | ParseInfo | getDepth(): number; | 新增 |
| ohos.xml | ParseInfo | getColumnNumber(): number; | 新增 |
| ohos.xml | EventType | WHITESPACE | 新增 |
| ohos.xml | EventType | ENTITY_REFERENCE | 新增 |
| ohos.xml | EventType | INSTRUCTION | 新增 |
| ohos.xml | EventType | DOCDECL | 新增 |
| ohos.xml | EventType | COMMENT | 新增 |
| ohos.xml | EventType | CDSECT | 新增 |
| ohos.xml | EventType | TEXT | 新增 |
| ohos.xml | EventType | END_TAG | 新增 |
| ohos.xml | EventType | START_TAG | 新增 |
| ohos.xml | EventType | END_DOCUMENT | 新增 |
| ohos.xml | EventType | START_DOCUMENT | 新增 |
| ohos.xml | XmlSerializer | setDocType(text: string): void; | 新增 |
| ohos.xml | XmlSerializer | setText(text: string): void; | 新增 |
| ohos.xml | XmlSerializer | setCDATA(text: string): void; | 新增 |
| ohos.xml | XmlSerializer | setComment(text: string): void; | 新增 |
| ohos.xml | XmlSerializer | setNamespace(prefix: string, namespace: string): void; | 新增 |
| ohos.xml | XmlSerializer | endElement(): void; | 新增 |
| ohos.xml | XmlSerializer | startElement(name: string): void; | 新增 |
| ohos.xml | XmlSerializer | setDeclaration(): void; | 新增 |
| ohos.xml | XmlSerializer | addEmptyElement(name: string): void; | 新增 |
| ohos.xml | XmlSerializer | setAttributes(name: string, value: string): void; | 新增 |
| ohos.xml | XmlSerializer | constructor(buffer: ArrayBuffer \| DataView, encoding?: string); | 新增 |
| ohos.util.Vector | Vector | \[Symbol.iterator](): IterableIterator\<T>; | 新增 |
| ohos.util.Vector | Vector | copyToArray(array: Array\<T>): void; | 新增 |
| ohos.util.Vector | Vector | trimToCurrentLength(): void; | 新增 |
| ohos.util.Vector | Vector | toString(): string; | 新增 |
| ohos.util.Vector | Vector | increaseCapacityTo(newCapacity: number): void; | 新增 |
| ohos.util.Vector | Vector | isEmpty(): boolean; | 新增 |
| ohos.util.Vector | Vector | convertToArray(): Array\<T>; | 新增 |
| ohos.util.Vector | Vector | getCapacity(): number; | 新增 |
| ohos.util.Vector | Vector | setLength(newSize: number): void; | 新增 |
| ohos.util.Vector | Vector | clone(): Vector\<T>; | 新增 |
| ohos.util.Vector | Vector | clear(): void; | 新增 |
| ohos.util.Vector | Vector | subVector(fromIndex: number, toIndex: number): Vector\<T>; | 新增 |
| ohos.util.Vector | Vector | sort(comparator?: (firstValue: T, secondValue: T) => number): void; | 新增 |
| ohos.util.Vector | Vector | forEach(callbackfn: (value: T, index?: number, vector?: Vector\<T>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.Vector | Vector | replaceAllElements(callbackfn: (value: T, index?: number, vector?: Vector\<T>) => T, thisArg?: Object): void; | 新增 |
| ohos.util.Vector | Vector | removeByRange(fromIndex: number, toIndex: number): void; | 新增 |
| ohos.util.Vector | Vector | getIndexFrom(element: T, index: number): number; | 新增 |
| ohos.util.Vector | Vector | getLastIndexFrom(element: T, index: number): number; | 新增 |
| ohos.util.Vector | Vector | getLastIndexOf(element: T): number; | 新增 |
| ohos.util.Vector | Vector | set(index: number, element: T): T; | 新增 |
| ohos.util.Vector | Vector | remove(element: T): boolean; | 新增 |
| ohos.util.Vector | Vector | removeByIndex(index: number): T; | 新增 |
| ohos.util.Vector | Vector | getLastElement(): T; | 新增 |
| ohos.util.Vector | Vector | getFirstElement(): T; | 新增 |
| ohos.util.Vector | Vector | getIndexOf(element: T): number; | 新增 |
| ohos.util.Vector | Vector | get(index: number): T; | 新增 |
| ohos.util.Vector | Vector | has(element: T): boolean; | 新增 |
| ohos.util.Vector | Vector | insert(element: T, index: number): void; | 新增 |
| ohos.util.Vector | Vector | add(element: T): boolean; | 新增 |
| ohos.util.Vector | Vector | length: number; | 新增 |
| ohos.util.Vector | Vector | constructor(); | 新增 |
| ohos.util.TreeSet | TreeSet | \[Symbol.iterator](): IterableIterator\<T>; | 新增 |
| ohos.util.TreeSet | TreeSet | entries(): IterableIterator\<[T, T]>; | 新增 |
| ohos.util.TreeSet | TreeSet | values(): IterableIterator\<T>; | 新增 |
| ohos.util.TreeSet | TreeSet | forEach(callbackfn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.TreeSet | TreeSet | popLast(): T; | 新增 |
| ohos.util.TreeSet | TreeSet | popFirst(): T; | 新增 |
| ohos.util.TreeSet | TreeSet | getHigherValue(key: T): T; | 新增 |
| ohos.util.TreeSet | TreeSet | getLowerValue(key: T): T; | 新增 |
| ohos.util.TreeSet | TreeSet | getLastValue(): T; | 新增 |
| ohos.util.TreeSet | TreeSet | getFirstValue(): T; | 新增 |
| ohos.util.TreeSet | TreeSet | clear(): void; | 新增 |
| ohos.util.TreeSet | TreeSet | remove(value: T): boolean; | 新增 |
| ohos.util.TreeSet | TreeSet | add(value: T): boolean; | 新增 |
| ohos.util.TreeSet | TreeSet | has(value: T): boolean; | 新增 |
| ohos.util.TreeSet | TreeSet | isEmpty(): boolean; | 新增 |
| ohos.util.TreeSet | TreeSet | length: number; | 新增 |
| ohos.util.TreeSet | TreeSet | constructor(comparator?: (firstValue: T, secondValue: T) => boolean) | 新增 |
| ohos.util.TreeMap | TreeMap | \[Symbol.iterator](): IterableIterator\<[K, V]>; | 新增 |
| ohos.util.TreeMap | TreeMap | entries(): IterableIterator\<[K, V]>; | 新增 |
| ohos.util.TreeMap | TreeMap | forEach(callbackfn: (value?: V, key?: K, map?: TreeMap\<K, V>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.TreeMap | TreeMap | replace(key: K, newValue: V): boolean; | 新增 |
| ohos.util.TreeMap | TreeMap | values(): IterableIterator\<V>; | 新增 |
| ohos.util.TreeMap | TreeMap | keys(): IterableIterator\<K>; | 新增 |
| ohos.util.TreeMap | TreeMap | getHigherKey(key: K): K; | 新增 |
| ohos.util.TreeMap | TreeMap | getLowerKey(key: K): K; | 新增 |
| ohos.util.TreeMap | TreeMap | clear(): void; | 新增 |
| ohos.util.TreeMap | TreeMap | remove(key: K): V; | 新增 |
| ohos.util.TreeMap | TreeMap | set(key: K, value: V): Object; | 新增 |
| ohos.util.TreeMap | TreeMap | setAll(map: TreeMap\<K, V>): void; | 新增 |
| ohos.util.TreeMap | TreeMap | getLastKey(): K; | 新增 |
| ohos.util.TreeMap | TreeMap | getFirstKey(): K; | 新增 |
| ohos.util.TreeMap | TreeMap | get(key: K): V; | 新增 |
| ohos.util.TreeMap | TreeMap | hasValue(value: V): boolean; | 新增 |
| ohos.util.TreeMap | TreeMap | hasKey(key: K): boolean; | 新增 |
| ohos.util.TreeMap | TreeMap | isEmpty(): boolean; | 新增 |
| ohos.util.TreeMap | TreeMap | length: number; | 新增 |
| ohos.util.TreeMap | TreeMap | constructor(comparator?: (firstValue: K, secondValue: K) => boolean); | 新增 |
| ohos.util.Stack | Stack | \[Symbol.iterator](): IterableIterator\<T>; | 新增 |
| ohos.util.Stack | Stack | forEach(callbackfn: (value: T, index?: number, stack?: Stack\<T>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.Stack | Stack | locate(element: T): number; | 新增 |
| ohos.util.Stack | Stack | push(item: T): T; | 新增 |
| ohos.util.Stack | Stack | pop(): T; | 新增 |
| ohos.util.Stack | Stack | peek(): T; | 新增 |
| ohos.util.Stack | Stack | isEmpty(): boolean; | 新增 |
| ohos.util.Stack | Stack | length: number; | 新增 |
| ohos.util.Stack | Stack | constructor(); | 新增 |
| ohos.util.Queue | Queue | \[Symbol.iterator](): IterableIterator\<T>; | 新增 |
| ohos.util.Queue | Queue | forEach(callbackfn: (value: T, index?: number, Queue?: Queue\<T>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.Queue | Queue | pop(): T; | 新增 |
| ohos.util.Queue | Queue | getFirst(): T; | 新增 |
| ohos.util.Queue | Queue | add(element: T): boolean; | 新增 |
| ohos.util.Queue | Queue | length: number; | 新增 |
| ohos.util.Queue | Queue | constructor(); | 新增 |
| ohos.util.PlainArray | PlainArray | \[Symbol.iterator](): IterableIterator\<[number, T]>; | 新增 |
| ohos.util.PlainArray | PlainArray | forEach(callbackfn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void,  thisArg?: Object): void; | 新增 |
| ohos.util.PlainArray | PlainArray | getValueAt(index: number): T; | 新增 |
| ohos.util.PlainArray | PlainArray | toString(): String; | 新增 |
| ohos.util.PlainArray | PlainArray | setValueAt(index: number, value: T): void; | 新增 |
| ohos.util.PlainArray | PlainArray | removeRangeFrom(index: number, size: number): number; | 新增 |
| ohos.util.PlainArray | PlainArray | removeAt(index: number): T; | 新增 |
| ohos.util.PlainArray | PlainArray | remove(key: number): T; | 新增 |
| ohos.util.PlainArray | PlainArray | getKeyAt(index: number): number; | 新增 |
| ohos.util.PlainArray | PlainArray | isEmpty(): boolean; | 新增 |
| ohos.util.PlainArray | PlainArray | getIndexOfValue(value: T): number; | 新增 |
| ohos.util.PlainArray | PlainArray | getIndexOfKey(key: number): number; | 新增 |
| ohos.util.PlainArray | PlainArray | get(key: number): T; | 新增 |
| ohos.util.PlainArray | PlainArray | has(key: number): boolean; | 新增 |
| ohos.util.PlainArray | PlainArray | clone(): PlainArray\<T>; | 新增 |
| ohos.util.PlainArray | PlainArray | clear(): void; | 新增 |
| ohos.util.PlainArray | PlainArray | add(key: number, value: T): void; | 新增 |
| ohos.util.PlainArray | PlainArray | length: number; | 新增 |
| ohos.util.PlainArray | PlainArray | constructor(); | 新增 |
| ohos.util.List | List | \[Symbol.iterator](): IterableIterator\<T>; | 新增 |
| ohos.util.List | List | isEmpty(): boolean; | 新增 |
| ohos.util.List | List | convertToArray(): Array\<T>; | 新增 |
| ohos.util.List | List | replaceAllElements(callbackfn: (value: T, index?: number, list?: List\<T>) => T, thisArg?: Object): void; | 新增 |
| ohos.util.List | List | getSubList(fromIndex: number, toIndex: number): List\<T>; | 新增 |
| ohos.util.List | List | clear(): void; | 新增 |
| ohos.util.List | List | sort(comparator: (firstValue: T, secondValue: T) => number): void; | 新增 |
| ohos.util.List | List | forEach(callbackfn: (value: T, index?: number, List?: List\<T>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.List | List | equal(obj: Object): boolean; | 新增 |
| ohos.util.List | List | set(index: number, element: T): T; | 新增 |
| ohos.util.List | List | getLast(): T; | 新增 |
| ohos.util.List | List | getFirst(): T; | 新增 |
| ohos.util.List | List | getLastIndexOf(element: T): number; | 新增 |
| ohos.util.List | List | remove(element: T): boolean; | 新增 |
| ohos.util.List | List | removeByIndex(index: number): T; | 新增 |
| ohos.util.List | List | getIndexOf(element: T): number; | 新增 |
| ohos.util.List | List | has(element: T): boolean; | 新增 |
| ohos.util.List | List | get(index: number): T; | 新增 |
| ohos.util.List | List | insert(element: T, index: number): void; | 新增 |
| ohos.util.List | List | add(element: T): boolean; | 新增 |
| ohos.util.List | List | length: number; | 新增 |
| ohos.util.List | List | constructor(); | 新增 |
| ohos.util.LinkedList | LinkedList | \[Symbol.iterator](): IterableIterator\<T>; | 新增 |
| ohos.util.LinkedList | LinkedList | convertToArray(): Array\<T>; | 新增 |
| ohos.util.LinkedList | LinkedList | clone(): LinkedList\<T>; | 新增 |
| ohos.util.LinkedList | LinkedList | clear(): void; | 新增 |
| ohos.util.LinkedList | LinkedList | forEach(callbackfn: (value: T, index?: number, LinkedList?: LinkedList\<T>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.LinkedList | LinkedList | set(index: number, element: T): T; | 新增 |
| ohos.util.LinkedList | LinkedList | getLast(): T; | 新增 |
| ohos.util.LinkedList | LinkedList | getFirst(): T; | 新增 |
| ohos.util.LinkedList | LinkedList | getLastIndexOf(element: T): number; | 新增 |
| ohos.util.LinkedList | LinkedList | removeLastFound(element: T): boolean; | 新增 |
| ohos.util.LinkedList | LinkedList | removeFirstFound(element: T): boolean; | 新增 |
| ohos.util.LinkedList | LinkedList | remove(element: T): boolean; | 新增 |
| ohos.util.LinkedList | LinkedList | removeByIndex(index: number): T; | 新增 |
| ohos.util.LinkedList | LinkedList | getIndexOf(element: T): number; | 新增 |
| ohos.util.LinkedList | LinkedList | has(element: T): boolean; | 新增 |
| ohos.util.LinkedList | LinkedList | removeLast(): T; | 新增 |
| ohos.util.LinkedList | LinkedList | removeFirst(): T; | 新增 |
| ohos.util.LinkedList | LinkedList | addFirst(element: T): void; | 新增 |
| ohos.util.LinkedList | LinkedList | get(index: number): T; | 新增 |
| ohos.util.LinkedList | LinkedList | insert(index: number, element: T): void; | 新增 |
| ohos.util.LinkedList | LinkedList | add(element: T): boolean; | 新增 |
| ohos.util.LinkedList | LinkedList | length: number; | 新增 |
| ohos.util.LinkedList | LinkedList | constructor(); | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | isEmpty(): boolean; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | entries(): IterableIterator\<[T, T]>; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | values(): IterableIterator\<T>; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | getValueAt(index: number): T; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | toArray(): Array\<T>; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | toString(): String; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | \[Symbol.iterator](): IterableIterator\<T>; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | forEach(callbackfn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | clear(): void; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | removeAt(index: number): boolean; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | remove(key: T): T; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | getIndexOf(key: T): number; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | increaseCapacityTo(minimumCapacity: number): void; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | equal(obj: Object): boolean; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | has(key: T): boolean; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | hasAll(set: LightWeightSet\<T>): boolean; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | addAll(set: LightWeightSet\<T>): boolean; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | add(obj: T): boolean; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | length: number; | 新增 |
| ohos.util.LightWeightSet | LightWeightSet | constructor(); | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | values(): IterableIterator\<V>; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | getValueAt(index: number): V; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | toString(): String; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | \[Symbol.iterator](): IterableIterator\<[K, V]>; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | forEach(callbackfn: (value?: V, key?: K, map?: LightWeightMap\<K, V>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | setValueAt(index: number, newValue: V): boolean; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | clear(): void; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | removeAt(index: number): boolean; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | remove(key: K): V; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | set(key: K, value: V): Object; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | setAll(map: LightWeightMap\<K, V>): void; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | keys(): IterableIterator\<K>; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | getKeyAt(index: number): K; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | isEmpty(): boolean; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | getIndexOfValue(value: V): number; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | getIndexOfKey(key: K): number; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | get(key: K): V; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | entries(): IterableIterator\<[K, V]>; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | increaseCapacityTo(minimumCapacity: number): void; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | hasValue(value: V): boolean; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | hasKey(key: K): boolean; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | hasAll(map: LightWeightMap\<K, V>): boolean; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | length: number; | 新增 |
| ohos.util.LightWeightMap | LightWeightMap | constructor(); | 新增 |
| ohos.util.HashSet | HashSet | \[Symbol.iterator](): IterableIterator\<T>; | 新增 |
| ohos.util.HashSet | HashSet | entries(): IterableIterator\<[T, T]>; | 新增 |
| ohos.util.HashSet | HashSet | values(): IterableIterator\<T>; | 新增 |
| ohos.util.HashSet | HashSet | forEach(callbackfn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.HashSet | HashSet | clear(): void; | 新增 |
| ohos.util.HashSet | HashSet | remove(value: T): boolean; | 新增 |
| ohos.util.HashSet | HashSet | add(value: T): boolean; | 新增 |
| ohos.util.HashSet | HashSet | has(value: T): boolean; | 新增 |
| ohos.util.HashSet | HashSet | isEmpty(): boolean; | 新增 |
| ohos.util.HashSet | HashSet | length: number; | 新增 |
| ohos.util.HashSet | HashSet | constructor(); | 新增 |
| ohos.util.HashMap | HashMap | \[Symbol.iterator](): IterableIterator\<[K, V]>; | 新增 |
| ohos.util.HashMap | HashMap | entries(): IterableIterator\<[K, V]>; | 新增 |
| ohos.util.HashMap | HashMap | forEach(callbackfn: (value?: V, key?: K, map?: HashMap\<K, V>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.HashMap | HashMap | replace(key: K, newValue: V): boolean; | 新增 |
| ohos.util.HashMap | HashMap | values(): IterableIterator\<V>; | 新增 |
| ohos.util.HashMap | HashMap | keys(): IterableIterator\<K>; | 新增 |
| ohos.util.HashMap | HashMap | clear(): void; | 新增 |
| ohos.util.HashMap | HashMap | remove(key: K): V; | 新增 |
| ohos.util.HashMap | HashMap | set(key: K, value: V): Object; | 新增 |
| ohos.util.HashMap | HashMap | setAll(map: HashMap\<K, V>): void; | 新增 |
| ohos.util.HashMap | HashMap | get(key: K): V; | 新增 |
| ohos.util.HashMap | HashMap | hasValue(value: V): boolean; | 新增 |
| ohos.util.HashMap | HashMap | hasKey(key: K): boolean; | 新增 |
| ohos.util.HashMap | HashMap | isEmpty(): boolean; | 新增 |
| ohos.util.HashMap | HashMap | length: number; | 新增 |
| ohos.util.HashMap | HashMap | constructor(); | 新增 |
| ohos.util.Deque | Deque | \[Symbol.iterator](): IterableIterator\<T>; | 新增 |
| ohos.util.Deque | Deque | forEach(callbackfn: (value: T, index?: number, deque?: Deque\<T>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.Deque | Deque | popLast(): T; | 新增 |
| ohos.util.Deque | Deque | popFirst(): T; | 新增 |
| ohos.util.Deque | Deque | getLast(): T; | 新增 |
| ohos.util.Deque | Deque | getFirst(): T; | 新增 |
| ohos.util.Deque | Deque | has(element: T): boolean; | 新增 |
| ohos.util.Deque | Deque | insertEnd(element: T): void; | 新增 |
| ohos.util.Deque | Deque | insertFront(element: T): void; | 新增 |
| ohos.util.Deque | Deque | length: number; | 新增 |
| ohos.util.Deque | Deque | constructor(); | 新增 |
| ohos.util | types | isWeakSet(value: Object): boolean; | 新增 |
| ohos.util | types | isWeakMap(value: Object): boolean; | 新增 |
| ohos.util | types | isUint32Array(value: Object): boolean; | 新增 |
| ohos.util | types | isUint16Array(value: Object): boolean; | 新增 |
| ohos.util | types | isUint8ClampedArray(value: Object): boolean; | 新增 |
| ohos.util | types | isUint8Array(value: Object): boolean; | 新增 |
| ohos.util | types | isTypedArray(value: Object): boolean; | 新增 |
| ohos.util | types | isSymbolObject(value: Object): boolean; | 新增 |
| ohos.util | types | isStringObject(value: Object): boolean; | 新增 |
| ohos.util | types | isSharedArrayBuffer(value: Object): boolean; | 新增 |
| ohos.util | types | isSetIterator(value: Object): boolean; | 新增 |
| ohos.util | types | isSet(value: Object): boolean; | 新增 |
| ohos.util | types | isRegExp(value: Object): boolean; | 新增 |
| ohos.util | types | isProxy(value: Object): boolean; | 新增 |
| ohos.util | types | isPromise(value: Object): boolean; | 新增 |
| ohos.util | types | isNumberObject(value: Object): boolean; | 新增 |
| ohos.util | types | isNativeError(value: Object): boolean; | 新增 |
| ohos.util | types | isModuleNamespaceObject(value: Object): boolean; | 新增 |
| ohos.util | types | isMapIterator(value: Object): boolean; | 新增 |
| ohos.util | types | isMap(value: Object): boolean; | 新增 |
| ohos.util | types | isInt32Array(value: Object): boolean; | 新增 |
| ohos.util | types | isInt16Array(value: Object): boolean; | 新增 |
| ohos.util | types | isInt8Array(value: Object): boolean; | 新增 |
| ohos.util | types | isGeneratorObject(value: Object): boolean; | 新增 |
| ohos.util | types | isGeneratorFunction(value: Object): boolean; | 新增 |
| ohos.util | types | isFloat64Array(value: Object): boolean; | 新增 |
| ohos.util | types | isFloat32Array(value: Object): boolean; | 新增 |
| ohos.util | types | isExternal(value: Object): boolean; | 新增 |
| ohos.util | types | isDate(value: Object): boolean; | 新增 |
| ohos.util | types | isDataView(value: Object): boolean; | 新增 |
| ohos.util | types | isBoxedPrimitive(value: Object): boolean; | 新增 |
| ohos.util | types | isBooleanObject(value: Object): boolean; | 新增 |
| ohos.util | types | isBigUint64Array(value: Object): boolean; | 新增 |
| ohos.util | types | isBigInt64Array(value: Object): boolean; | 新增 |
| ohos.util | types | isAsyncFunction(value: Object): boolean; | 新增 |
| ohos.util | types | isArrayBuffer(value: Object): boolean; | 新增 |
| ohos.util | types | isArgumentsObject(value: Object): boolean; | 新增 |
| ohos.util | types | isArrayBufferView(value: Object): boolean; | 新增 |
| ohos.util | types | isAnyArrayBuffer(value: Object): boolean; | 新增 |
| ohos.util | types | constructor(); | 新增 |
| ohos.util | Base64 | decodeSync(src: Uint8Array \| string): Uint8Array; | 新增 |
| ohos.util | Base64 | encodeToStringSync(src: Uint8Array): string; | 新增 |
| ohos.util | Base64 | encodeSync(src: Uint8Array): Uint8Array; | 新增 |
| ohos.util | LruBuffer | getCapacity(): number; | 新增 |
| ohos.util | LruBuffer | length:number | 新增 |
| ohos.util | RationalNumber | valueOf(): number; | 新增 |
| ohos.util.ArrayList | ArrayList | \[Symbol.iterator](): IterableIterator\<T>; | 新增 |
| ohos.util.ArrayList | ArrayList | trimToCurrentLength(): void; | 新增 |
| ohos.util.ArrayList | ArrayList | increaseCapacityTo(newCapacity: number): void; | 新增 |
| ohos.util.ArrayList | ArrayList | isEmpty(): boolean; | 新增 |
| ohos.util.ArrayList | ArrayList | convertToArray(): Array\<T>; | 新增 |
| ohos.util.ArrayList | ArrayList | getCapacity(): number; | 新增 |
| ohos.util.ArrayList | ArrayList | clone(): ArrayList\<T>; | 新增 |
| ohos.util.ArrayList | ArrayList | clear(): void; | 新增 |
| ohos.util.ArrayList | ArrayList | subArrayList(fromIndex: number, toIndex: number): ArrayList\<T>; | 新增 |
| ohos.util.ArrayList | ArrayList | sort(comparator?: (firstValue: T, secondValue: T) => number): void; | 新增 |
| ohos.util.ArrayList | ArrayList | forEach(callbackfn: (value: T, index?: number, arrlist?: ArrayList\<T>) => void, thisArg?: Object): void; | 新增 |
| ohos.util.ArrayList | ArrayList | replaceAllElements(callbackfn: (value: T, index?: number, arrlist?: ArrayList\<T>) => T, thisArg?: Object): void; | 新增 |
| ohos.util.ArrayList | ArrayList | removeByRange(fromIndex: number, toIndex: number): void; | 新增 |
| ohos.util.ArrayList | ArrayList | getLastIndexOf(element: T): number; | 新增 |
| ohos.util.ArrayList | ArrayList | remove(element: T): boolean; | 新增 |
| ohos.util.ArrayList | ArrayList | removeByIndex(index: number): T; | 新增 |
| ohos.util.ArrayList | ArrayList | getIndexOf(element: T): number; | 新增 |
| ohos.util.ArrayList | ArrayList | has(element: T): boolean; | 新增 |
| ohos.util.ArrayList | ArrayList | insert(element: T, index: number): void; | 新增 |
| ohos.util.ArrayList | ArrayList | add(element: T): boolean; | 新增 |
| ohos.util.ArrayList | ArrayList | length: number; | 新增 |
| ohos.util.ArrayList | ArrayList | constructor(); | 新增 |
| ohos.uri | URI | ssp: string; | 新增 |
| ohos.uri | URI | authority: string; | 新增 |
| ohos.uri | URI | fragment: string; | 新增 |
| ohos.uri | URI | query: string; | 新增 |
| ohos.uri | URI | path: string; | 新增 |
| ohos.uri | URI | port: string; | 新增 |
| ohos.uri | URI | host: string; | 新增 |
| ohos.uri | URI | userInfo: string; | 新增 |
| ohos.uri | URI | scheme: string; | 新增 |
| ohos.uri | URI | normalize(): URI; | 新增 |
| ohos.uri | URI | checkIsAbsolute(): boolean; | 新增 |
| ohos.uri | URI | equals(other: URI): boolean; | 新增 |
| ohos.uri | URI | toString(): string | 新增 |
| ohos.uri | URI | constructor(uri: string); | 新增 |
| ohos.convertxml | ConvertXML | convert(xml: string, options?: ConvertOptions) : Object; | 新增 |
| ohos.convertxml | ConvertOptions | elementsKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | nameKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | typeKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | parentKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | commentKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | doctypeKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | cdataKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | textKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | attributesKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | instructionKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | declarationKey: string; | 新增 |
| ohos.convertxml | ConvertOptions | ignoreText?: boolean; | 新增 |
| ohos.convertxml | ConvertOptions | ignoreDoctype?: boolean; | 新增 |
| ohos.convertxml | ConvertOptions | ignoreCDATA?: boolean; | 新增 |
| ohos.convertxml | ConvertOptions | ignoreComment?: boolean; | 新增 |
| ohos.convertxml | ConvertOptions | ignoreAttributes?: boolean; | 新增 |
| ohos.convertxml | ConvertOptions | ignoreInstruction?: boolean; | 新增 |
| ohos.convertxml | ConvertOptions | ignoreDeclaration?: boolean; | 新增 |
| ohos.convertxml | ConvertOptions | trim: boolean; | 新增 |
