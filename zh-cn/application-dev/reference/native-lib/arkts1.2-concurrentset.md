# ConcurrentSet (并发集合)

ConcurrentSet\<T>是一个多线程并发安全的集合类，支持并发读取和写入，减少锁的竞争，实现高并发性能。它提供了对集合元素的高效操作，包括添加、删除、查找等，并且可以迭代操作内部存储的元素。该类基于[ConcurrentHashMap\<K, V>](./arkts1.2-concurrenthashmap.md)实现，确保了在多线程环境下的安全性。

> **说明：**
>
> ArkTS版本：该标准库接口仅适用于ArkTS1.2。

## 属性

| 名称 | 类型   | 只读 | 可选 | 说明               |
| :--- | :----- | :--- | :--- | :----------------- |
| size | number | 是   | 否   | 集合中元素的个数。 |

## constructor

constructor()

ConcurrentSet的构造函数，创建一个空的ConcurrentSet\<T>实例。

**示例：**

```typescript
let concurrentSet: ConcurrentSet<number> = new ConcurrentSet<number>();
```

## constructor

constructor(entries: ArrayLike\<T>)

ConcurrentSet的构造函数，传入一个实现了ArrayLike\<T>接口的数组对象entries，该构造函数创建一个新的ConcurrentSet\<T>实例，并将entries中的所有元素添加到新创建的集合中。

**参数：**

| 参数名  | 类型          | 必填 | 说明                                                |
| :------ | :------------ | :--- | :-------------------------------------------------- |
| entries | ArrayLike\<T> | 是   | 一个实现了ArrayLike\<T>的数组对象，用于初始化集合。 |

**示例：**

```typescript
let array = new Array<number>(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
let concurrentSet: ConcurrentSet<number> = new ConcurrentSet<number>(array);
```

## constructor

constructor(iterable: Iterable\<T>)

ConcurrentSet的构造函数，传入一个实现了Iterable\<T> 接口的可迭代对象iterable，该构造函数创建一个新的ConcurrentSet\<T>实例，并将iterable中的所有元素添加到新创建的集合中。

**参数：**

| 参数名   | 类型         | 必填 | 说明                                                      |
| :------- | :----------- | :--- | :-------------------------------------------------------- |
| iterable | Iterable\<T> | 是   | 一个实现了Iterable\<T> 接口的可迭代对象，用于初始化集合。 |

**示例：**

```typescript
let set = new Set<number>();
for (let i = 0; i < 10; i++) {
  set.add(i);
}
let iter: Iterable<number> = set.keys();
let concurrentSet: ConcurrentSet<number> = new ConcurrentSet<number>(iter);
```

## constructor

constructor(set: ReadonlySet\<T>)

ConcurrentSet的构造函数，传入一个了实现ReadonlySet\<T>接口的集合对象set，该构造函数创建一个新的ConcurrentSet\<T>实例，并将set中的所有元素添加到新创建的集合中。

**参数：**

| 参数名 | 类型            | 必填 | 说明                                                      |
| :----- | :-------------- | :--- | :-------------------------------------------------------- |
| set    | ReadonlySet\<T> | 是   | 一个实现了ReadonlySet\<T>接口的集合对象，用于初始化集合。 |

**示例：**

```typescript
let set = new Set<number>();
for (let i = 0; i < 10; i++) {
  set.add(i);
}
let concurrentSet: ConcurrentSet<number> = new ConcurrentSet<number>(set);
```

## add

add(val: T): this

向集合中添加一个元素，如果元素已经存在，则不会重复添加。返回this即调用该方法的[ConcurrentSet](#concurrentset-并发集合)对象，支持链式调用。

该方法多线程并发执行安全。

**参数：**

| 参数名 | 类型 | 必填 | 说明                     |
| :----- | :--- | :--- | :----------------------- |
| val    | T    | 是   | 需要添加到集合中的元素。 |

**返回值：**

| 类型 | 说明                                                           |
| :--- | :------------------------------------------------------------- |
| this | 返回调用该方法的[ConcurrentSet](#concurrentset-并发集合)对象。 |

**示例：**

```typescript
let arrValues = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];
let concurrentSet: ConcurrentSet<string> = new ConcurrentSet<string>();
for (let i = 0; i < 10; i++) {
  concurrentSet.add(arrValues[i]);
}
```

## has

has(val: T): boolean

检查集合中是否包含指定的元素。

该方法多线程并发执行安全。

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| :----- | :--- | :--- | :------------- |
| val    | T    | 是   | 要查找的元素。 |

**返回值：**

| 类型    | 说明                                            |
| :------ | :---------------------------------------------- |
| boolean | 当集合中包含该元素时，返回true，否则返回false。 |

**示例：**

```typescript
let concurrentSet: ConcurrentSet<int> = new ConcurrentSet<int>();
for (let i = 0; i < 10; i++) {
  concurrentSet.add(i);
}
let val = concurrentSet.has(1); // true
val = concurrentSet.has(-1); // false
```

## delete

delete(val: T): boolean

从集合中删除指定的元素。

该方法多线程并发执行安全。

**参数：**

| 参数名 | 类型 | 必填 | 说明           |
| :----- | :--- | :--- | :------------- |
| val    | T    | 是   | 要删除的元素。 |

**返回值：**

| 类型    | 说明                                            |
| :------ | :---------------------------------------------- |
| boolean | 元素存在并被成功删除，返回true，否则返回false。 |

**示例：**

```typescript
let concurrentSet: ConcurrentSet<number> = new ConcurrentSet<number>();
concurrentSet.add(0);
let res = concurrentSet.delete(0); // true
res = concurrentSet.delete(0); // false
```

## clear

clear(): void

清空集合中的所有元素。

该方法多线程并发执行安全。

**示例：**

```typescript
let arrValues = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];
let concurrentSet: ConcurrentSet<string> = new ConcurrentSet<string>();
let beforeClearSize = concurrentSet.size; //10
concurrentSet.clear();
let afterClearSize = concurrentSet.size; //0
```

## keys

keys(): IterableIterator\<T>

获取一个包含集合中所有元素的迭代器。

弱一致性，会返回当前所有元素的快照，不保证反映之后该集合中元素的变化。

**返回值：**

| 类型                 | 说明                             |
| :------------------- | :------------------------------- |
| IterableIterator\<T> | 返回包含集合中所有元素的迭代器。 |

**示例：**

```typescript
let concurrentSet: ConcurrentSet<int> = new ConcurrentSet<int>();
for (let i = 0; i < 5; i++) {
  concurrentSet.add(i);
}
let iter = concurrentSet.keys();
let v = iter.next();
while (!v.done) {
  const value = v.value;
  console.log("value: " + value);
  v = iter.next();
}
/*
value: 0
value: 1
value: 2
value: 3
value: 4
*/
```

## values

values(): IterableIterator\<T>

获取一个包含集合中所有元素的迭代器。与[keys](#keys)相同。

弱一致性，会返回当前所有元素的快照，不保证会反映之后该集合中元素的变化。

**返回值：**

| 类型                 | 说明                             |
| :------------------- | :------------------------------- |
| IterableIterator\<T> | 返回包含集合中所有元素的迭代器。 |

**示例：**

```typescript
let concurrentSet: ConcurrentSet<int> = new ConcurrentSet<int>();
for (let i = 0; i < 5; i++) {
  concurrentSet.add(i);
}
let iter = concurrentSet.values();
let v = iter.next();
while (!v.done) {
  const value = v.value;
  console.log("value: " + value);
  v = iter.next();
}
/*
value: 0
value: 1
value: 2
value: 3
value: 4
*/
```

## \$\_iterator

\$\_iterator(): IterableIterator\<T>

获取一个包含集合中所有元素的迭代器，与[keys](#keys)相同。

弱一致性，会返回当前所有元素的快照，不保证会反映之后该集合中元素的变化。

**返回值：**

| 类型                 | 说明                             |
| :------------------- | :------------------------------- |
| IterableIterator\<T> | 返回包含集合中所有元素的迭代器。 |

**示例：**

```typescript
let concurrentSet: ConcurrentSet<int> = new ConcurrentSet<int>();
for (let i = 0; i < 5; i++) {
  concurrentSet.add(i);
}
let iter = concurrentSet.$_iterator();
let v = iter.next();
while (!v.done) {
  const value = v.value;
  console.log("value: " + value);
  v = iter.next();
}
/*
value: 0
value: 1
value: 2
value: 3
value: 4
*/
```

## entries

entries(): IterableIterator\<[T, T]>

获取一个包含集合中所有元素的键值对迭代器。由于集合中的键和值相同，因此每个键值对都是[T, T]的形式。

弱一致性，会返回当前所有元素的键值对的快照，不保证会反映之后该集合中元素的变化。

**返回值：**

| 类型                      | 说明                                   |
| :------------------------ | :------------------------------------- |
| IterableIterator\<[T, T]> | 返回包含集合中所有元素键值对的迭代器。 |

**示例：**

```typescript
let concurrentSet: ConcurrentSet<int> = new ConcurrentSet<int>();
for (let i: int = 0; i < 5; i++) {
  concurrentSet.add(i);
}

let iter = concurrentSet.entries();
let v = iter.next();
while (!v.done) {
  const value = v.value;
  console.log("key: " + value![0] + "  value:" + value![1]);
  v = iter.next();
}
/*
key: 0  value:0
key: 1  value:1
key: 2  value:2
key: 3  value:3
key: 4  value:4
*/
```

## forEach

forEach(callbackfn: (value: T, value2: T, set: ConcurrentSet\<T>) => void): void

对集合中的每个元素执行指定的回调函数。回调函数可以接收当前迭代到的元素作为value1和value2，以及此集合实例。

该方法多线程并发执行安全。

**参数：**

| 参数名     | 类型     | 必填 | 说明       |
| :--------- | :------- | :--- | :--------- |
| callbackfn | function | 是   | 回调函数。 |

callbackfn的参数说明：

| 参数名 | 类型              | 必填 | 说明                                                     |
| :----- | :---------------- | :--- | :------------------------------------------------------- |
| value  | T                 | 否   | 集合当前遍历到的元素的值。                               |
| value2 | T                 | 否   | 集合当前遍历到的元素的值。                               |
| set    | ConcurrentSet\<T> | 否   | 调用该方法的[ConcurrentSet](#concurrentset-并发集合)对象 |

**示例：**

```typescript
let arrKeys = new Array<number>(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
let ConcurrentSet: ConcurrentSet<number> = new ConcurrentSet<number>(arrKeys);
let count = 0;
ConcurrentSet.forEach((k: number, v: number, set: ConcurrentSet<number>) => {
  if (k % 2 == 0) {
    count++;
  }
});
console.log(count); // 5
```

## toString

toString(): String

以字符串的形式输出该集合中的元素。

该方法多线程并发执行安全。

**返回值：**

| 类型   | 说明                             |
| :----- | :------------------------------- |
| String | 返回包含集合内所有元素的字符串。 |

```typescript
let array = new Array<number>(0.0, 1.0, 2.0, 3.0, 4.0);
let concurrentSet: ConcurrentSet<number> = new ConcurrentSet<number>(array);
let val = concurrentSet.toString(); // 'ConcurrentSet[0,1,2,3,4]'
```
