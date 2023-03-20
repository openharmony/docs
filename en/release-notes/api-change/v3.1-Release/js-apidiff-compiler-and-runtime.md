# JS API Changes of the Compiler and Runtime Subsystem

The table below lists the APIs changes of the compiler and runtime subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.xml | XmlPullParser | parse(option: ParseOptions): void; | Added|
| ohos.xml | XmlPullParser | constructor(buffer: ArrayBuffer \| DataView, encoding?: string); | Added|
| ohos.xml | ParseOptions | tokenValueCallbackFunction?: (eventType: EventType, value: ParseInfo) => boolean; | Added|
| ohos.xml | ParseOptions | attributeValueCallbackFunction?: (name: string, value: string) => boolean; | Added|
| ohos.xml | ParseOptions | tagValueCallbackFunction?: (name: string, value: string) => boolean; | Added|
| ohos.xml | ParseOptions | ignoreNameSpace?: boolean; | Added|
| ohos.xml | ParseOptions | supportDoctype?: boolean; | Added|
| ohos.xml | ParseInfo | getAttributeCount(): number; | Added|
| ohos.xml | ParseInfo | isWhitespace(): boolean; | Added|
| ohos.xml | ParseInfo | isEmptyElementTag(): boolean; | Added|
| ohos.xml | ParseInfo | getText(): string; | Added|
| ohos.xml | ParseInfo | getPrefix(): string; | Added|
| ohos.xml | ParseInfo | getNamespace(): string; | Added|
| ohos.xml | ParseInfo | getName(): string; | Added|
| ohos.xml | ParseInfo | getLineNumber(): number; | Added|
| ohos.xml | ParseInfo | getDepth(): number; | Added|
| ohos.xml | ParseInfo | getColumnNumber(): number; | Added|
| ohos.xml | EventType | WHITESPACE | Added|
| ohos.xml | EventType | ENTITY_REFERENCE | Added|
| ohos.xml | EventType | INSTRUCTION | Added|
| ohos.xml | EventType | DOCDECL | Added|
| ohos.xml | EventType | COMMENT | Added|
| ohos.xml | EventType | CDSECT | Added|
| ohos.xml | EventType | TEXT | Added|
| ohos.xml | EventType | END_TAG | Added|
| ohos.xml | EventType | START_TAG | Added|
| ohos.xml | EventType | END_DOCUMENT | Added|
| ohos.xml | EventType | START_DOCUMENT | Added|
| ohos.xml | XmlSerializer | setDocType(text: string): void; | Added|
| ohos.xml | XmlSerializer | setText(text: string): void; | Added|
| ohos.xml | XmlSerializer | setCDATA(text: string): void; | Added|
| ohos.xml | XmlSerializer | setComment(text: string): void; | Added|
| ohos.xml | XmlSerializer | setNamespace(prefix: string, namespace: string): void; | Added|
| ohos.xml | XmlSerializer | endElement(): void; | Added|
| ohos.xml | XmlSerializer | startElement(name: string): void; | Added|
| ohos.xml | XmlSerializer | setDeclaration(): void; | Added|
| ohos.xml | XmlSerializer | addEmptyElement(name: string): void; | Added|
| ohos.xml | XmlSerializer | setAttributes(name: string, value: string): void; | Added|
| ohos.xml | XmlSerializer | constructor(buffer: ArrayBuffer \| DataView, encoding?: string); | Added|
| ohos.util.Vector | Vector | \[Symbol.iterator](): IterableIterator\<T>; | Added|
| ohos.util.Vector | Vector | copyToArray(array: Array\<T>): void; | Added|
| ohos.util.Vector | Vector | trimToCurrentLength(): void; | Added|
| ohos.util.Vector | Vector | toString(): string; | Added|
| ohos.util.Vector | Vector | increaseCapacityTo(newCapacity: number): void; | Added|
| ohos.util.Vector | Vector | isEmpty(): boolean; | Added|
| ohos.util.Vector | Vector | convertToArray(): Array\<T>; | Added|
| ohos.util.Vector | Vector | getCapacity(): number; | Added|
| ohos.util.Vector | Vector | setLength(newSize: number): void; | Added|
| ohos.util.Vector | Vector | clone(): Vector\<T>; | Added|
| ohos.util.Vector | Vector | clear(): void; | Added|
| ohos.util.Vector | Vector | subVector(fromIndex: number, toIndex: number): Vector\<T>; | Added|
| ohos.util.Vector | Vector | sort(comparator?: (firstValue: T, secondValue: T) => number): void; | Added|
| ohos.util.Vector | Vector | forEach(callbackfn: (value: T, index?: number, vector?: Vector\<T>) => void, thisArg?: Object): void; | Added|
| ohos.util.Vector | Vector | replaceAllElements(callbackfn: (value: T, index?: number, vector?: Vector\<T>) => T, thisArg?: Object): void; | Added|
| ohos.util.Vector | Vector | removeByRange(fromIndex: number, toIndex: number): void; | Added|
| ohos.util.Vector | Vector | getIndexFrom(element: T, index: number): number; | Added|
| ohos.util.Vector | Vector | getLastIndexFrom(element: T, index: number): number; | Added|
| ohos.util.Vector | Vector | getLastIndexOf(element: T): number; | Added|
| ohos.util.Vector | Vector | set(index: number, element: T): T; | Added|
| ohos.util.Vector | Vector | remove(element: T): boolean; | Added|
| ohos.util.Vector | Vector | removeByIndex(index: number): T; | Added|
| ohos.util.Vector | Vector | getLastElement(): T; | Added|
| ohos.util.Vector | Vector | getFirstElement(): T; | Added|
| ohos.util.Vector | Vector | getIndexOf(element: T): number; | Added|
| ohos.util.Vector | Vector | get(index: number): T; | Added|
| ohos.util.Vector | Vector | has(element: T): boolean; | Added|
| ohos.util.Vector | Vector | insert(element: T, index: number): void; | Added|
| ohos.util.Vector | Vector | add(element: T): boolean; | Added|
| ohos.util.Vector | Vector | length: number; | Added|
| ohos.util.Vector | Vector | constructor(); | Added|
| ohos.util.TreeSet | TreeSet | \[Symbol.iterator](): IterableIterator\<T>; | Added|
| ohos.util.TreeSet | TreeSet | entries(): IterableIterator\<[T, T]>; | Added|
| ohos.util.TreeSet | TreeSet | values(): IterableIterator\<T>; | Added|
| ohos.util.TreeSet | TreeSet | forEach(callbackfn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object): void; | Added|
| ohos.util.TreeSet | TreeSet | popLast(): T; | Added|
| ohos.util.TreeSet | TreeSet | popFirst(): T; | Added|
| ohos.util.TreeSet | TreeSet | getHigherValue(key: T): T; | Added|
| ohos.util.TreeSet | TreeSet | getLowerValue(key: T): T; | Added|
| ohos.util.TreeSet | TreeSet | getLastValue(): T; | Added|
| ohos.util.TreeSet | TreeSet | getFirstValue(): T; | Added|
| ohos.util.TreeSet | TreeSet | clear(): void; | Added|
| ohos.util.TreeSet | TreeSet | remove(value: T): boolean; | Added|
| ohos.util.TreeSet | TreeSet | add(value: T): boolean; | Added|
| ohos.util.TreeSet | TreeSet | has(value: T): boolean; | Added|
| ohos.util.TreeSet | TreeSet | isEmpty(): boolean; | Added|
| ohos.util.TreeSet | TreeSet | length: number; | Added|
| ohos.util.TreeSet | TreeSet | constructor(comparator?: (firstValue: T, secondValue: T) => boolean) | Added|
| ohos.util.TreeMap | TreeMap | \[Symbol.iterator](): IterableIterator\<[K, V]>; | Added|
| ohos.util.TreeMap | TreeMap | entries(): IterableIterator\<[K, V]>; | Added|
| ohos.util.TreeMap | TreeMap | forEach(callbackfn: (value?: V, key?: K, map?: TreeMap\<K, V>) => void, thisArg?: Object): void; | Added|
| ohos.util.TreeMap | TreeMap | replace(key: K, newValue: V): boolean; | Added|
| ohos.util.TreeMap | TreeMap | values(): IterableIterator\<V>; | Added|
| ohos.util.TreeMap | TreeMap | keys(): IterableIterator\<K>; | Added|
| ohos.util.TreeMap | TreeMap | getHigherKey(key: K): K; | Added|
| ohos.util.TreeMap | TreeMap | getLowerKey(key: K): K; | Added|
| ohos.util.TreeMap | TreeMap | clear(): void; | Added|
| ohos.util.TreeMap | TreeMap | remove(key: K): V; | Added|
| ohos.util.TreeMap | TreeMap | set(key: K, value: V): Object; | Added|
| ohos.util.TreeMap | TreeMap | setAll(map: TreeMap\<K, V>): void; | Added|
| ohos.util.TreeMap | TreeMap | getLastKey(): K; | Added|
| ohos.util.TreeMap | TreeMap | getFirstKey(): K; | Added|
| ohos.util.TreeMap | TreeMap | get(key: K): V; | Added|
| ohos.util.TreeMap | TreeMap | hasValue(value: V): boolean; | Added|
| ohos.util.TreeMap | TreeMap | hasKey(key: K): boolean; | Added|
| ohos.util.TreeMap | TreeMap | isEmpty(): boolean; | Added|
| ohos.util.TreeMap | TreeMap | length: number; | Added|
| ohos.util.TreeMap | TreeMap | constructor(comparator?: (firstValue: K, secondValue: K) => boolean); | Added|
| ohos.util.Stack | Stack | \[Symbol.iterator](): IterableIterator\<T>; | Added|
| ohos.util.Stack | Stack | forEach(callbackfn: (value: T, index?: number, stack?: Stack\<T>) => void, thisArg?: Object): void; | Added|
| ohos.util.Stack | Stack | locate(element: T): number; | Added|
| ohos.util.Stack | Stack | push(item: T): T; | Added|
| ohos.util.Stack | Stack | pop(): T; | Added|
| ohos.util.Stack | Stack | peek(): T; | Added|
| ohos.util.Stack | Stack | isEmpty(): boolean; | Added|
| ohos.util.Stack | Stack | length: number; | Added|
| ohos.util.Stack | Stack | constructor(); | Added|
| ohos.util.Queue | Queue | \[Symbol.iterator](): IterableIterator\<T>; | Added|
| ohos.util.Queue | Queue | forEach(callbackfn: (value: T, index?: number, Queue?: Queue\<T>) => void, thisArg?: Object): void; | Added|
| ohos.util.Queue | Queue | pop(): T; | Added|
| ohos.util.Queue | Queue | getFirst(): T; | Added|
| ohos.util.Queue | Queue | add(element: T): boolean; | Added|
| ohos.util.Queue | Queue | length: number; | Added|
| ohos.util.Queue | Queue | constructor(); | Added|
| ohos.util.PlainArray | PlainArray | \[Symbol.iterator](): IterableIterator\<[number, T]>; | Added|
| ohos.util.PlainArray | PlainArray | forEach(callbackfn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void,  thisArg?: Object): void; | Added|
| ohos.util.PlainArray | PlainArray | getValueAt(index: number): T; | Added|
| ohos.util.PlainArray | PlainArray | toString(): String; | Added|
| ohos.util.PlainArray | PlainArray | setValueAt(index: number, value: T): void; | Added|
| ohos.util.PlainArray | PlainArray | removeRangeFrom(index: number, size: number): number; | Added|
| ohos.util.PlainArray | PlainArray | removeAt(index: number): T; | Added|
| ohos.util.PlainArray | PlainArray | remove(key: number): T; | Added|
| ohos.util.PlainArray | PlainArray | getKeyAt(index: number): number; | Added|
| ohos.util.PlainArray | PlainArray | isEmpty(): boolean; | Added|
| ohos.util.PlainArray | PlainArray | getIndexOfValue(value: T): number; | Added|
| ohos.util.PlainArray | PlainArray | getIndexOfKey(key: number): number; | Added|
| ohos.util.PlainArray | PlainArray | get(key: number): T; | Added|
| ohos.util.PlainArray | PlainArray | has(key: number): boolean; | Added|
| ohos.util.PlainArray | PlainArray | clone(): PlainArray\<T>; | Added|
| ohos.util.PlainArray | PlainArray | clear(): void; | Added|
| ohos.util.PlainArray | PlainArray | add(key: number, value: T): void; | Added|
| ohos.util.PlainArray | PlainArray | length: number; | Added|
| ohos.util.PlainArray | PlainArray | constructor(); | Added|
| ohos.util.List | List | \[Symbol.iterator](): IterableIterator\<T>; | Added|
| ohos.util.List | List | isEmpty(): boolean; | Added|
| ohos.util.List | List | convertToArray(): Array\<T>; | Added|
| ohos.util.List | List | replaceAllElements(callbackfn: (value: T, index?: number, list?: List\<T>) => T, thisArg?: Object): void; | Added|
| ohos.util.List | List | getSubList(fromIndex: number, toIndex: number): List\<T>; | Added|
| ohos.util.List | List | clear(): void; | Added|
| ohos.util.List | List | sort(comparator: (firstValue: T, secondValue: T) => number): void; | Added|
| ohos.util.List | List | forEach(callbackfn: (value: T, index?: number, List?: List\<T>) => void, thisArg?: Object): void; | Added|
| ohos.util.List | List | equal(obj: Object): boolean; | Added|
| ohos.util.List | List | set(index: number, element: T): T; | Added|
| ohos.util.List | List | getLast(): T; | Added|
| ohos.util.List | List | getFirst(): T; | Added|
| ohos.util.List | List | getLastIndexOf(element: T): number; | Added|
| ohos.util.List | List | remove(element: T): boolean; | Added|
| ohos.util.List | List | removeByIndex(index: number): T; | Added|
| ohos.util.List | List | getIndexOf(element: T): number; | Added|
| ohos.util.List | List | has(element: T): boolean; | Added|
| ohos.util.List | List | get(index: number): T; | Added|
| ohos.util.List | List | insert(element: T, index: number): void; | Added|
| ohos.util.List | List | add(element: T): boolean; | Added|
| ohos.util.List | List | length: number; | Added|
| ohos.util.List | List | constructor(); | Added|
| ohos.util.LinkedList | LinkedList | \[Symbol.iterator](): IterableIterator\<T>; | Added|
| ohos.util.LinkedList | LinkedList | convertToArray(): Array\<T>; | Added|
| ohos.util.LinkedList | LinkedList | clone(): LinkedList\<T>; | Added|
| ohos.util.LinkedList | LinkedList | clear(): void; | Added|
| ohos.util.LinkedList | LinkedList | forEach(callbackfn: (value: T, index?: number, LinkedList?: LinkedList\<T>) => void, thisArg?: Object): void; | Added|
| ohos.util.LinkedList | LinkedList | set(index: number, element: T): T; | Added|
| ohos.util.LinkedList | LinkedList | getLast(): T; | Added|
| ohos.util.LinkedList | LinkedList | getFirst(): T; | Added|
| ohos.util.LinkedList | LinkedList | getLastIndexOf(element: T): number; | Added|
| ohos.util.LinkedList | LinkedList | removeLastFound(element: T): boolean; | Added|
| ohos.util.LinkedList | LinkedList | removeFirstFound(element: T): boolean; | Added|
| ohos.util.LinkedList | LinkedList | remove(element: T): boolean; | Added|
| ohos.util.LinkedList | LinkedList | removeByIndex(index: number): T; | Added|
| ohos.util.LinkedList | LinkedList | getIndexOf(element: T): number; | Added|
| ohos.util.LinkedList | LinkedList | has(element: T): boolean; | Added|
| ohos.util.LinkedList | LinkedList | removeLast(): T; | Added|
| ohos.util.LinkedList | LinkedList | removeFirst(): T; | Added|
| ohos.util.LinkedList | LinkedList | addFirst(element: T): void; | Added|
| ohos.util.LinkedList | LinkedList | get(index: number): T; | Added|
| ohos.util.LinkedList | LinkedList | insert(index: number, element: T): void; | Added|
| ohos.util.LinkedList | LinkedList | add(element: T): boolean; | Added|
| ohos.util.LinkedList | LinkedList | length: number; | Added|
| ohos.util.LinkedList | LinkedList | constructor(); | Added|
| ohos.util.LightWeightSet | LightWeightSet | isEmpty(): boolean; | Added|
| ohos.util.LightWeightSet | LightWeightSet | entries(): IterableIterator\<[T, T]>; | Added|
| ohos.util.LightWeightSet | LightWeightSet | values(): IterableIterator\<T>; | Added|
| ohos.util.LightWeightSet | LightWeightSet | getValueAt(index: number): T; | Added|
| ohos.util.LightWeightSet | LightWeightSet | toArray(): Array\<T>; | Added|
| ohos.util.LightWeightSet | LightWeightSet | toString(): String; | Added|
| ohos.util.LightWeightSet | LightWeightSet | \[Symbol.iterator](): IterableIterator\<T>; | Added|
| ohos.util.LightWeightSet | LightWeightSet | forEach(callbackfn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object): void; | Added|
| ohos.util.LightWeightSet | LightWeightSet | clear(): void; | Added|
| ohos.util.LightWeightSet | LightWeightSet | removeAt(index: number): boolean; | Added|
| ohos.util.LightWeightSet | LightWeightSet | remove(key: T): T; | Added|
| ohos.util.LightWeightSet | LightWeightSet | getIndexOf(key: T): number; | Added|
| ohos.util.LightWeightSet | LightWeightSet | increaseCapacityTo(minimumCapacity: number): void; | Added|
| ohos.util.LightWeightSet | LightWeightSet | equal(obj: Object): boolean; | Added|
| ohos.util.LightWeightSet | LightWeightSet | has(key: T): boolean; | Added|
| ohos.util.LightWeightSet | LightWeightSet | hasAll(set: LightWeightSet\<T>): boolean; | Added|
| ohos.util.LightWeightSet | LightWeightSet | addAll(set: LightWeightSet\<T>): boolean; | Added|
| ohos.util.LightWeightSet | LightWeightSet | add(obj: T): boolean; | Added|
| ohos.util.LightWeightSet | LightWeightSet | length: number; | Added|
| ohos.util.LightWeightSet | LightWeightSet | constructor(); | Added|
| ohos.util.LightWeightMap | LightWeightMap | values(): IterableIterator\<V>; | Added|
| ohos.util.LightWeightMap | LightWeightMap | getValueAt(index: number): V; | Added|
| ohos.util.LightWeightMap | LightWeightMap | toString(): String; | Added|
| ohos.util.LightWeightMap | LightWeightMap | \[Symbol.iterator](): IterableIterator\<[K, V]>; | Added|
| ohos.util.LightWeightMap | LightWeightMap | forEach(callbackfn: (value?: V, key?: K, map?: LightWeightMap\<K, V>) => void, thisArg?: Object): void; | Added|
| ohos.util.LightWeightMap | LightWeightMap | setValueAt(index: number, newValue: V): boolean; | Added|
| ohos.util.LightWeightMap | LightWeightMap | clear(): void; | Added|
| ohos.util.LightWeightMap | LightWeightMap | removeAt(index: number): boolean; | Added|
| ohos.util.LightWeightMap | LightWeightMap | remove(key: K): V; | Added|
| ohos.util.LightWeightMap | LightWeightMap | set(key: K, value: V): Object; | Added|
| ohos.util.LightWeightMap | LightWeightMap | setAll(map: LightWeightMap\<K, V>): void; | Added|
| ohos.util.LightWeightMap | LightWeightMap | keys(): IterableIterator\<K>; | Added|
| ohos.util.LightWeightMap | LightWeightMap | getKeyAt(index: number): K; | Added|
| ohos.util.LightWeightMap | LightWeightMap | isEmpty(): boolean; | Added|
| ohos.util.LightWeightMap | LightWeightMap | getIndexOfValue(value: V): number; | Added|
| ohos.util.LightWeightMap | LightWeightMap | getIndexOfKey(key: K): number; | Added|
| ohos.util.LightWeightMap | LightWeightMap | get(key: K): V; | Added|
| ohos.util.LightWeightMap | LightWeightMap | entries(): IterableIterator\<[K, V]>; | Added|
| ohos.util.LightWeightMap | LightWeightMap | increaseCapacityTo(minimumCapacity: number): void; | Added|
| ohos.util.LightWeightMap | LightWeightMap | hasValue(value: V): boolean; | Added|
| ohos.util.LightWeightMap | LightWeightMap | hasKey(key: K): boolean; | Added|
| ohos.util.LightWeightMap | LightWeightMap | hasAll(map: LightWeightMap\<K, V>): boolean; | Added|
| ohos.util.LightWeightMap | LightWeightMap | length: number; | Added|
| ohos.util.LightWeightMap | LightWeightMap | constructor(); | Added|
| ohos.util.HashSet | HashSet | \[Symbol.iterator](): IterableIterator\<T>; | Added|
| ohos.util.HashSet | HashSet | entries(): IterableIterator\<[T, T]>; | Added|
| ohos.util.HashSet | HashSet | values(): IterableIterator\<T>; | Added|
| ohos.util.HashSet | HashSet | forEach(callbackfn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object): void; | Added|
| ohos.util.HashSet | HashSet | clear(): void; | Added|
| ohos.util.HashSet | HashSet | remove(value: T): boolean; | Added|
| ohos.util.HashSet | HashSet | add(value: T): boolean; | Added|
| ohos.util.HashSet | HashSet | has(value: T): boolean; | Added|
| ohos.util.HashSet | HashSet | isEmpty(): boolean; | Added|
| ohos.util.HashSet | HashSet | length: number; | Added|
| ohos.util.HashSet | HashSet | constructor(); | Added|
| ohos.util.HashMap | HashMap | \[Symbol.iterator](): IterableIterator\<[K, V]>; | Added|
| ohos.util.HashMap | HashMap | entries(): IterableIterator\<[K, V]>; | Added|
| ohos.util.HashMap | HashMap | forEach(callbackfn: (value?: V, key?: K, map?: HashMap\<K, V>) => void, thisArg?: Object): void; | Added|
| ohos.util.HashMap | HashMap | replace(key: K, newValue: V): boolean; | Added|
| ohos.util.HashMap | HashMap | values(): IterableIterator\<V>; | Added|
| ohos.util.HashMap | HashMap | keys(): IterableIterator\<K>; | Added|
| ohos.util.HashMap | HashMap | clear(): void; | Added|
| ohos.util.HashMap | HashMap | remove(key: K): V; | Added|
| ohos.util.HashMap | HashMap | set(key: K, value: V): Object; | Added|
| ohos.util.HashMap | HashMap | setAll(map: HashMap\<K, V>): void; | Added|
| ohos.util.HashMap | HashMap | get(key: K): V; | Added|
| ohos.util.HashMap | HashMap | hasValue(value: V): boolean; | Added|
| ohos.util.HashMap | HashMap | hasKey(key: K): boolean; | Added|
| ohos.util.HashMap | HashMap | isEmpty(): boolean; | Added|
| ohos.util.HashMap | HashMap | length: number; | Added|
| ohos.util.HashMap | HashMap | constructor(); | Added|
| ohos.util.Deque | Deque | \[Symbol.iterator](): IterableIterator\<T>; | Added|
| ohos.util.Deque | Deque | forEach(callbackfn: (value: T, index?: number, deque?: Deque\<T>) => void, thisArg?: Object): void; | Added|
| ohos.util.Deque | Deque | popLast(): T; | Added|
| ohos.util.Deque | Deque | popFirst(): T; | Added|
| ohos.util.Deque | Deque | getLast(): T; | Added|
| ohos.util.Deque | Deque | getFirst(): T; | Added|
| ohos.util.Deque | Deque | has(element: T): boolean; | Added|
| ohos.util.Deque | Deque | insertEnd(element: T): void; | Added|
| ohos.util.Deque | Deque | insertFront(element: T): void; | Added|
| ohos.util.Deque | Deque | length: number; | Added|
| ohos.util.Deque | Deque | constructor(); | Added|
| ohos.util | types | isWeakSet(value: Object): boolean; | Added|
| ohos.util | types | isWeakMap(value: Object): boolean; | Added|
| ohos.util | types | isUint32Array(value: Object): boolean; | Added|
| ohos.util | types | isUint16Array(value: Object): boolean; | Added|
| ohos.util | types | isUint8ClampedArray(value: Object): boolean; | Added|
| ohos.util | types | isUint8Array(value: Object): boolean; | Added|
| ohos.util | types | isTypedArray(value: Object): boolean; | Added|
| ohos.util | types | isSymbolObject(value: Object): boolean; | Added|
| ohos.util | types | isStringObject(value: Object): boolean; | Added|
| ohos.util | types | isSharedArrayBuffer(value: Object): boolean; | Added|
| ohos.util | types | isSetIterator(value: Object): boolean; | Added|
| ohos.util | types | isSet(value: Object): boolean; | Added|
| ohos.util | types | isRegExp(value: Object): boolean; | Added|
| ohos.util | types | isProxy(value: Object): boolean; | Added|
| ohos.util | types | isPromise(value: Object): boolean; | Added|
| ohos.util | types | isNumberObject(value: Object): boolean; | Added|
| ohos.util | types | isNativeError(value: Object): boolean; | Added|
| ohos.util | types | isModuleNamespaceObject(value: Object): boolean; | Added|
| ohos.util | types | isMapIterator(value: Object): boolean; | Added|
| ohos.util | types | isMap(value: Object): boolean; | Added|
| ohos.util | types | isInt32Array(value: Object): boolean; | Added|
| ohos.util | types | isInt16Array(value: Object): boolean; | Added|
| ohos.util | types | isInt8Array(value: Object): boolean; | Added|
| ohos.util | types | isGeneratorObject(value: Object): boolean; | Added|
| ohos.util | types | isGeneratorFunction(value: Object): boolean; | Added|
| ohos.util | types | isFloat64Array(value: Object): boolean; | Added|
| ohos.util | types | isFloat32Array(value: Object): boolean; | Added|
| ohos.util | types | isExternal(value: Object): boolean; | Added|
| ohos.util | types | isDate(value: Object): boolean; | Added|
| ohos.util | types | isDataView(value: Object): boolean; | Added|
| ohos.util | types | isBoxedPrimitive(value: Object): boolean; | Added|
| ohos.util | types | isBooleanObject(value: Object): boolean; | Added|
| ohos.util | types | isBigUint64Array(value: Object): boolean; | Added|
| ohos.util | types | isBigInt64Array(value: Object): boolean; | Added|
| ohos.util | types | isAsyncFunction(value: Object): boolean; | Added|
| ohos.util | types | isArrayBuffer(value: Object): boolean; | Added|
| ohos.util | types | isArgumentsObject(value: Object): boolean; | Added|
| ohos.util | types | isArrayBufferView(value: Object): boolean; | Added|
| ohos.util | types | isAnyArrayBuffer(value: Object): boolean; | Added|
| ohos.util | types | constructor(); | Added|
| ohos.util | Base64 | decodeSync(src: Uint8Array \| string): Uint8Array; | Added|
| ohos.util | Base64 | encodeToStringSync(src: Uint8Array): string; | Added|
| ohos.util | Base64 | encodeSync(src: Uint8Array): Uint8Array; | Added|
| ohos.util | LruBuffer | getCapacity(): number; | Added|
| ohos.util | LruBuffer | length:number | Added|
| ohos.util | RationalNumber | valueOf(): number; | Added|
| ohos.util.ArrayList | ArrayList | \[Symbol.iterator](): IterableIterator\<T>; | Added|
| ohos.util.ArrayList | ArrayList | trimToCurrentLength(): void; | Added|
| ohos.util.ArrayList | ArrayList | increaseCapacityTo(newCapacity: number): void; | Added|
| ohos.util.ArrayList | ArrayList | isEmpty(): boolean; | Added|
| ohos.util.ArrayList | ArrayList | convertToArray(): Array\<T>; | Added|
| ohos.util.ArrayList | ArrayList | getCapacity(): number; | Added|
| ohos.util.ArrayList | ArrayList | clone(): ArrayList\<T>; | Added|
| ohos.util.ArrayList | ArrayList | clear(): void; | Added|
| ohos.util.ArrayList | ArrayList | subArrayList(fromIndex: number, toIndex: number): ArrayList\<T>; | Added|
| ohos.util.ArrayList | ArrayList | sort(comparator?: (firstValue: T, secondValue: T) => number): void; | Added|
| ohos.util.ArrayList | ArrayList | forEach(callbackfn: (value: T, index?: number, arrlist?: ArrayList\<T>) => void, thisArg?: Object): void; | Added|
| ohos.util.ArrayList | ArrayList | replaceAllElements(callbackfn: (value: T, index?: number, arrlist?: ArrayList\<T>) => T, thisArg?: Object): void; | Added|
| ohos.util.ArrayList | ArrayList | removeByRange(fromIndex: number, toIndex: number): void; | Added|
| ohos.util.ArrayList | ArrayList | getLastIndexOf(element: T): number; | Added|
| ohos.util.ArrayList | ArrayList | remove(element: T): boolean; | Added|
| ohos.util.ArrayList | ArrayList | removeByIndex(index: number): T; | Added|
| ohos.util.ArrayList | ArrayList | getIndexOf(element: T): number; | Added|
| ohos.util.ArrayList | ArrayList | has(element: T): boolean; | Added|
| ohos.util.ArrayList | ArrayList | insert(element: T, index: number): void; | Added|
| ohos.util.ArrayList | ArrayList | add(element: T): boolean; | Added|
| ohos.util.ArrayList | ArrayList | length: number; | Added|
| ohos.util.ArrayList | ArrayList | constructor(); | Added|
| ohos.uri | URI | ssp: string; | Added|
| ohos.uri | URI | authority: string; | Added|
| ohos.uri | URI | fragment: string; | Added|
| ohos.uri | URI | query: string; | Added|
| ohos.uri | URI | path: string; | Added|
| ohos.uri | URI | port: string; | Added|
| ohos.uri | URI | host: string; | Added|
| ohos.uri | URI | userInfo: string; | Added|
| ohos.uri | URI | scheme: string; | Added|
| ohos.uri | URI | normalize(): URI; | Added|
| ohos.uri | URI | checkIsAbsolute(): boolean; | Added|
| ohos.uri | URI | equals(other: URI): boolean; | Added|
| ohos.uri | URI | toString(): string | Added|
| ohos.uri | URI | constructor(uri: string); | Added|
| ohos.convertxml | ConvertXML | convert(xml: string, options?: ConvertOptions) : Object; | Added|
| ohos.convertxml | ConvertOptions | elementsKey: string; | Added|
| ohos.convertxml | ConvertOptions | nameKey: string; | Added|
| ohos.convertxml | ConvertOptions | typeKey: string; | Added|
| ohos.convertxml | ConvertOptions | parentKey: string; | Added|
| ohos.convertxml | ConvertOptions | commentKey: string; | Added|
| ohos.convertxml | ConvertOptions | doctypeKey: string; | Added|
| ohos.convertxml | ConvertOptions | cdataKey: string; | Added|
| ohos.convertxml | ConvertOptions | textKey: string; | Added|
| ohos.convertxml | ConvertOptions | attributesKey: string; | Added|
| ohos.convertxml | ConvertOptions | instructionKey: string; | Added|
| ohos.convertxml | ConvertOptions | declarationKey: string; | Added|
| ohos.convertxml | ConvertOptions | ignoreText?: boolean; | Added|
| ohos.convertxml | ConvertOptions | ignoreDoctype?: boolean; | Added|
| ohos.convertxml | ConvertOptions | ignoreCDATA?: boolean; | Added|
| ohos.convertxml | ConvertOptions | ignoreComment?: boolean; | Added|
| ohos.convertxml | ConvertOptions | ignoreAttributes?: boolean; | Added|
| ohos.convertxml | ConvertOptions | ignoreInstruction?: boolean; | Added|
| ohos.convertxml | ConvertOptions | ignoreDeclaration?: boolean; | Added|
| ohos.convertxml | ConvertOptions | trim: boolean; | Added|
