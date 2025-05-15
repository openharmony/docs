# ConcurrentHashMap (并发哈希表)

ConcurrentHashMap<[K, V]> 是一个多线程安全的哈希表，支持并发读取和写入，减少锁的竞争，实现高并发性能。提供了对容器元素的高效操作，包括添加、删除、查找等，并且可以迭代操作内部存储的元素。

> **说明：**
>
> ArkTS版本：该标准库接口仅适用于ArkTS1.2。

## 属性

| 名称 | 类型   | 只读 | 可选 | 说明                   |
| :--- | :----- | :--- | :--- | :--------------------- |
| size | number | 是   | 否   | 哈希表中键值对的个数。 |

## constructor

constructor()

ConcurrentHashMap的构造函数，创建一个空的ConcurrentHashMap<K, V>实例。

**示例：**

```typescript
let concurrentHashMap: ConcurrentHashMap<number, string> = new ConcurrentHashMap<number, string>();
```

## constructor

constructor(entries: ArrayLike<[K, V]>)

ConcurrentHashMap的构造函数，传入一个实现了ArrayLike<[K, V]>接口的数组对象entries，该构造函数创建一个新的ConcurrentHashMap<K, V>实例，并将entries中的所有元素添加到新创建的哈希表中。

**参数：**

| 参数名  | 类型              | 必填 | 说明                                                          |
| :------ | :---------------- | :--- | :------------------------------------------------------------ |
| entries | ArrayLike<[K, V]> | 是   | 一个实现了ArrayLike<[K, V]>接口的数组对象，用于初始化哈希表。 |

**示例：**

```typescript
let arrKeys: number[] = [0, 1, 2, 3, 4];
let arrValues: string[] = ["zero", "one", "two", "three", "four"];
let array = Array<[Double, String]>(5);
for (let i = 0; i < 5; i++) {
  let arrKV: [Double, String] = [arrKeys[i], arrValues[i]];
  array[i] = arrKV;
}
let concurrentHashMap: ConcurrentHashMap<Double, String> = new ConcurrentHashMap<Double, String>(array);
```

## constructor

constructor(iterable: Iterable<[K, V]>)

ConcurrentHashMap的构造函数，传入一个实现了Iterable<[K, V]>接口的可迭代对象iterable，该构造函数创建一个新的ConcurrentHashMap<K, V>实例，并将iterable中的所有元素添加到新创建的哈希表中。

**参数：**

| 参数名   | 类型             | 必填 | 说明                                                           |
| :------- | :--------------- | :--- | :------------------------------------------------------------- |
| iterable | Iterable<[K, V]> | 是   | 一个实现了Iterable<[K, V]>接口的可迭代对象，用于初始化哈希表。 |

**示例：**

```typescript
let arr: Array<[Double, string]> = [
  [1.0, "1.0"],
  [2.0, "2.0"],
  [3.0, "3.0"],
];
let map = new Map<Double, string>(arr);
let iterable = map.entries();
let concurrentHashMap: ConcurrentHashMap<Double, string> = new ConcurrentHashMap<Double, string>(iterable);
```

## constructor

constructor(map: ReadonlyMap<K, V>)

ConcurrentHashMap的构造函数，传入一个实现了ReadonlyMap<K, V>接口的映射对象map，该构造函数创建一个新的ConcurrentHashMap<K, V>实例，并将map中的所有元素添加到新创建的哈希表中。

**参数：**

| 参数名 | 类型              | 必填 | 说明                                                          |
| :----- | :---------------- | :--- | :------------------------------------------------------------ |
| map    | ReadonlyMap<K, V> | 是   | 一个实现了ReadonlyMap<K, V>接口的映射对象，用于初始化哈希表。 |

**示例：**

```typescript
let map: Map<number, string> = new Map<number, string>();
map.set(1, "1");
let concurrentHashMap: ConcurrentHashMap<number, string> = new ConcurrentHashMap<number, string>(map);
```

## set

set(key: K, val: V): this

向哈希表中添加或更新一个键值对，返回this即调用该方法的[ConcurrentHashMap](#concurrenthashmap-并发哈希表)对象，支持链式调用。

该方法多线程并发执行安全。

**参数：**

| 参数名 | 类型 | 必填 | 说明                  |
| :----- | :--- | :--- | :-------------------- |
| key    | K    | 是   | 待增添/更新元素的键。 |
| val    | V    | 是   | 待增添/更新元素的值。 |

**返回值：**

| 类型 | 说明                                                                     |
| :--- | :----------------------------------------------------------------------- |
| this | 返回调用该方法的[ConcurrentHashMap](#concurrenthashmap-并发哈希表)对象。 |

**示例：**

```typescript
let concurrentHashMap: ConcurrentHashMap<number, string> = new ConcurrentHashMap<number, string>();
let val = concurrentHashMap.set(1, "one").get(1); //"one"
```

## get

get(key: K): V \| undefined

获取指定key所映射的value，哈希表中不存在该键值对时则返回undefined。

该方法多线程并发执行安全。

**参数：**

| 参数名 | 类型 | 必填 | 说明                |
| :----- | :--- | :--- | :------------------ |
| key    | K    | 是   | 待查找的指定key值。 |

**返回值：**

| 类型           | 说明                                                  |
| :------------- | :---------------------------------------------------- |
| V \| undefined | 返回指定key所映射的value值；当不存在时返回undefined。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<number, string>();
concurrentHashMap.set(1, "one");
let val_0 = concurrentHashMap.get(1); // "one"
let val_1 = concurrentHashMap.get(2); // undefined
```

## replace

replace(key: K, newValue: V): boolean

对哈希表中一组键值对进行更新替换，若哈希表中没有key对应的键值对，替换失败，且不会增添键值对。替换成功时返回true，失败返回false。

该方法多线程并发执行安全。

**参数：**

| 参数名   | 类型 | 必填 | 说明                  |
| :------- | :--- | :--- | :-------------------- |
| key      | K    | 是   | 待替换元素指定key值。 |
| newValue | V    | 是   | 待替换的新值。        |

**返回值：**

| 类型    | 说明                                |
| :------ | :---------------------------------- |
| boolean | 替换成功时返回true，否则返回false。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<number, string>();
let val = concurrentHashMap.set(1, "one").get(1); //"one"
let flag_0 = concurrentHashMap.replace(1, "first"); // true
let flag_1 = concurrentHashMap.replace(2, "second"); // false
val = concurrentHashMap.get(1); // "first"
```

## has

has(key: K): boolean

判断此哈希表中是否含有键为key的元素。

该方法多线程并发执行安全。

**参数：**

| 参数名 | 类型 | 必填 | 说明                    |
| :----- | :--- | :--- | :---------------------- |
| key    | K    | 是   | 待查找元素的指定key值。 |

**返回值：**

| 类型    | 说明                                             |
| :------ | :----------------------------------------------- |
| boolean | 表中包含指定key的元素时返回true，否则返回false。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<number, string>();
concurrentHashMap.set(1, "one");
let flag_1 = concurrentHashMap.has(1); // true
let flag_2 = concurrentHashMap.has(2); // false
```

## remove

remove(key: K): V | undefined

删除指定key所对应的键值对，并返回其value值，如不存在匹配的键值对则直接返回undefined。

该方法多线程并发执行安全。

**参数：**

| 参数名 | 类型 | 必填 | 说明                    |
| :----- | :--- | :--- | :---------------------- |
| key    | K    | 是   | 待删除元素的指定key值。 |

**返回值：**

| 类型           | 说明                                                              |
| :------------- | :---------------------------------------------------------------- |
| V \| undefined | 返回被删除元素的value值，当key对应的键值对不存在则返回undefined。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<number, string>();
concurrentHashMap.set(1, "one");
let val_0 = concurrentHashMap.remove(1); // "one"
let val_1 = concurrentHashMap.remove(1); // undefined
```

## delete

delete(key:K): boolean

删除指定key所对应的键值对。如果哈希表中存在该键值对且被成功删除，则返回true；如果该键值对不存在或删除失败，则返回false。

该方法多线程并发执行安全。

**参数：**

| 参数名 | 类型 | 必填 | 说明                    |
| :----- | :--- | :--- | :---------------------- |
| key    | K    | 是   | 待删除元素的指定key值。 |

**返回值：**

| 类型    | 说明                                |
| :------ | :---------------------------------- |
| boolean | 删除成功时返回true，否则返回false。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<number, string>();
concurrentHashMap.set(1, "one");
let flag = concurrentHashMap.delete(1); // true
flag = concurrentHashMap.delete(1); // false
```

## isEmpty

isEmpty(): boolean

判断该哈希表是否为空（即元素数量为0）。

该方法多线程并发执行安全。

**返回值：**

| 类型    | 说明                                          |
| :------ | :-------------------------------------------- |
| boolean | 该哈希表为空时，返回true，不为空则返回false。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<number, string>();
let flag: boolean = concurrentHashMap.isEmpty(); // true
```

## clear

clear():void

清空该哈希表中所有元素。

该方法多线程并发执行安全。

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<number, string>();
concurrentHashMap.set(1, "one");
concurrentHashMap.set(2, "two");
concurrentHashMap.clear();
let size = concurrentHashMap.size; // 0
let isEmpty = concurrentHashMap.isEmpty();
```

## keys

keys(): IterableIterator\<K>

获取一个包含此哈希表中所有键值对的键的迭代器。

弱一致性，会返回当前哈希表所有元素的键的快照，不保证会反映之后该哈希表中元素的变化。

**返回值：**

| 类型                 | 说明                                       |
| :------------------- | :----------------------------------------- |
| IterableIterator\<K> | 返回包含此哈希表中所有键值对的键的迭代器。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<number, string>();
concurrentHashMap.set(0, "zero");
concurrentHashMap.set(1, "one");
concurrentHashMap.set(2, "two");
concurrentHashMap.set(3, "three");
concurrentHashMap.set(4, "four");

let iter = concurrentHashMap.keys();
let v = iter.next();
while (!v.done) {
  let val = v.value;
  console.log("key: " + val);
  v = iter.next();
}
/*
key: 0
key: 1
key: 2
key: 3
key: 4
*/
```

## values

values(): IterableIterator\<V>

获取一个包含此哈希表中所有键值对的值的迭代器。

弱一致性，会返回当前哈希表所有元素的值的快照，不保证会反映之后该哈希表中元素的变化。

**返回值：**

| 类型                 | 说明                                       |
| :------------------- | :----------------------------------------- |
| IterableIterator\<V> | 返回包含此哈希表中所有键值对的值的迭代器。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<number, string>();
concurrentHashMap.set(0, "zero");
concurrentHashMap.set(1, "one");
concurrentHashMap.set(2, "two");
concurrentHashMap.set(3, "three");
concurrentHashMap.set(4, "four");

let iter = concurrentHashMap.values();
let v = iter.next();
while (!v.done) {
  let value = v.value;
  console.log("value: " + value);
  v = iter.next();
}
/*
value: zero
value: one
value: two
value: three
value: four
*/
```

## entries

entries(): IterableIterator<[K, V]>

获取一个包含此哈希表中所有元素（键值对）的迭代器。

弱一致性，会返回当前所有元素的快照，不保证会反映之后该哈希表中元素的变化。

**返回值：**

| 类型                     | 说明                                 |
| :----------------------- | :----------------------------------- |
| IterableIterator<[K, V]> | 返回包含此哈希表中所有元素的迭代器。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<int, string>();
concurrentHashMap.set(0, "zero");
concurrentHashMap.set(1, "one");
concurrentHashMap.set(2, "two");
concurrentHashMap.set(3, "three");
concurrentHashMap.set(4, "four");

let iter = concurrentHashMap.entries();
let v = iter.next();
while (!v.done) {
  let value = v.value;
  console.log("key: " + value![0] + "  value: " + value![1]);
  v = iter.next();
}
/*
key: 0  value: zero
key: 1  value: one
key: 2  value: two
key: 3  value: three
key: 4  value: four
*/
```

## \$\_iterator()

\$\_iterator(): IterableIterator<[K, V]>

获取一个包含此哈希表中所有元素（键值对）的迭代器，与[entries](#entries)结果一致。

弱一致性，会返回当前所有元素的快照，不保证会反映之后该哈希表中元素的变化。

**返回值：**

| 类型                     | 说明                                 |
| :----------------------- | :----------------------------------- |
| IterableIterator<[K, V]> | 返回包含此哈希表中所有元素的迭代器。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<int, string>();
concurrentHashMap.set(0, "zero");
concurrentHashMap.set(1, "one");
concurrentHashMap.set(2, "two");
concurrentHashMap.set(3, "three");
concurrentHashMap.set(4, "four");

let iter = concurrentHashMap.$_iterator();
let v = iter.next();
while (!v.done) {
  let value = v.value;
  console.log("key: " + value![0] + "  value: " + value![1]);
  v = iter.next();
}
/*
key: 0  value: zero
key: 1  value: one
key: 2  value: two
key: 3  value: three
key: 4  value: four
*/
```

## forEach

forEach(callbackfn: (value: V, key: K, map: ConcurrentHashMap<K, V>) => void): void

对哈希表中的每个键值对执行指定的回调函数。回调函数可以接收当前迭代到的键值对的值、键，以及此哈希表实例。

该方法多线程并发执行安全。

**参数：**

| 参数名     | 类型     | 必填 | 说明       |
| :--------- | :------- | :--- | :--------- |
| callbackFn | function | 是   | 回调函数。 |

callbackfn的参数说明：

| 参数名 | 类型                    | 必填 | 说明                                                                 |
| :----- | :---------------------- | :--- | :------------------------------------------------------------------- |
| value  | V                       | 否   | 当前遍历到的键值对的值。                                             |
| key    | K                       | 否   | 当前遍历到的键值对的键。                                             |
| map    | ConcurrentHashMap<K, V> | 否   | 调用该方法的[ConcurrentHashMap](#concurrenthashmap-并发哈希表)对象。 |

**示例：**

```typescript
let concurrentHashMap: ConcurrentHashMap<number, string> = new ConcurrentHashMap<number, string>();
concurrentHashMap.set(1, "one");
concurrentHashMap.set(2, "two");

concurrentHashMap.forEach((value: string, key: number, map: ConcurrentHashMap<number, string>) => {
  console.log("value: " + value, "  key: " + key);
});
/*
value: one  key: 1
value: two  key: 2
*/
```

## toString

toString(): String

以字符串的形式输出哈希表中的元素。

该方法多线程并发执行安全。

**返回值：**

| 类型   | 说明                               |
| :----- | :--------------------------------- |
| String | 返回包含哈希表内所有元素的字符串。 |

**示例：**

```typescript
let concurrentHashMap = new ConcurrentHashMap<number, string>();
concurrentHashMap.set(1, "one");
concurrentHashMap.set(2, "two");
let str = concurrentHashMap.toString();
```
