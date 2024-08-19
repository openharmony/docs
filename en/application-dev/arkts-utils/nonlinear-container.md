# Nonlinear Containers


Nonlinear containers, underpinned by hash tables or red-black trees, implement a data structure that enables quick search. There are several types of nonlinear containers: **HashMap**, **HashSet**, **TreeMap**, **TreeSet**, **LightWeightMap**, **LightWeightSet**, and **PlainArray**. The types of **key** and **value** in nonlinear containers must meet the ECMA standard.


## HashMap

[HashMap](../reference/apis-arkts/js-apis-hashmap.md) is used to store a set of associated key-value (KV) pairs. In a hash map, each key is unique and corresponds to a value.

**HashMap** uses generics. In a hash map, a key is located based on its hash code. The initial capacity of a hash map is 16, and it has capacity doubled in each dynamic expansion. The bottom layer of **HashMap** is implemented based on a hash table. It uses chaining to avoid collisions in hash tables.

**HashMap** is faster in accessing data than [TreeMap](../reference/apis-arkts/js-apis-treemap.md), because the former accesses the keys based on the hash codes, whereas the latter stores and accesses the keys in sorted order.

[HashSet](../reference/apis-arkts/js-apis-hashset.md) is implemented based on **HashMap**. The input parameter of **HashMap** consists of **key** and **value**. In **HashSet**, only the **value** object is processed.

You are advised to use **HashMap** when you need to quickly access, remove, and insert KV pairs.

**HashMap** provides the following Create, Read, Update, and Delete (CRUD) APIs.

| Operation | Description |
| -------- | ------ |
| Create | Use **set(key: K, value: V)** to add an element (a KV pair) to this container. |
| Read | Use **get(key: K)** to obtain the value of the specified key. |
| Read | Use **keys()** to return an iterator that contains all the keys in this container. |
| Read | Use **values()** to return an iterator that contains all the values in this container. |
| Read | Use **entries()** to return an iterator that contains all the elements in this container. |
| Read | Use **forEach(callbackFn: (value?: V, key?: K, map?: HashMap<K, V>) => void, thisArg?: Object)** to traverse the elements in this container. |
| Read | Use **\[Symbol.iterator]():IterableIterator&lt;[K,V]&gt;** for data access. |
| Update | Use **replace(key: K, newValue: V)** to change the value of the specified key. |
| Update | Use **forEach(callbackFn: (value?: V, key?: K, map?: HashMap<K, V>) => void, thisArg?: Object)** to modify an element in this container. |
| Delete | Use **remove(key: K)** to remove an element with the specified key. |
| Delete | Use **clear()** to clear this container. |


## HashSet

[HashSet](../reference/apis-arkts/js-apis-hashset.md) is used to store a set of values, each of which is unique in a hash set.

**HashSet** uses generics. In a hash set, a value is located based on its hash code. The initial capacity of a hash set is 16, and it has capacity doubled in each dynamic expansion. The type of **value** must comply with the ECMA standard. The bottom layer of **HashSet** is implemented based on a hash table. It uses chaining to avoid collisions in hash tables.

**HashSet** is implemented based on [HashMap](../reference/apis-arkts/js-apis-hashmap.md). In **HashSet**, only the **value** object is processed.

Unlike [TreeSet](../reference/apis-arkts/js-apis-treeset.md), which stores and accesses data in sorted order, **HashSet** stores data in a random order. This means that **HashSet** may use a different order when storing and accessing elements. Both of them allow only unique elements. However, null values are allowed in **HashSet**, but not in **TreeSet**, because null values may affect the order of elements in the container.

You are advised to use **HashSet** when you need a set that has only unique elements or need to deduplicate a set.

**HashSet** provides the following CRUD APIs.

| Operation | Description |
| -------- | ------ |
| Create | Use **add(value: T)** to add a value to this container. |
| Read | Use **values()** to return an iterator that contains all the values in this container. |
| Read | Use **entries()** to return an iterator that contains all the elements in this container. |
| Read | Use **forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object)** to traverse the elements in this container. |
| Read | Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access. |
| Update | Use **forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object)** to change a value in this container. |
| Delete | Use **remove(value: T)** to remove a value. |
| Delete | Use **clear()** to clear this container. |


## TreeMap

[TreeMap](../reference/apis-arkts/js-apis-treemap.md) is used to store a set of associated KV pairs. In a tree map, each key is unique and corresponds to a value.

**TreeMap** uses generics, and the keys in a tree map are ordered. The bottom layer of **TreeMap** is a binary tree, which supports quick search of KV pairs through the children (left child and right child) of the tree. The type of **key** must comply with the ECMA standard. Keys in a tree map are stored in order. The bottom layer of **TreeMap** is implemented based on the red-black tree and supports quick insertion and removal.

[HashMap](../reference/apis-arkts/js-apis-hashmap.md) is faster in accessing data than **TreeMap**, because the former accesses the keys based on the hash codes, whereas the latter stores and accesses the keys in sorted order.

You are advised to use **TreeMap** when you need to store KV pairs in sorted order.

**TreeMap** provides the following CRUD APIs.

| Operation | Description |
| ------- | ------ |
| Create | Use **set(key: K, value: V)** to add an element (a KV pair) to this container. |
| Read | Use **get(key: K)** to obtain the value of the specified key. |
| Read | Use **getFirstKey()** to obtain the first key in this container. |
| Read | Use **getLastKey()** to obtain the last key in this container. |
| Read | Use **keys()** to return an iterator that contains all the keys in this container. |
| Read | Use **values()** to return an iterator that contains all the values in this container. |
| Read | Use **entries()** to return an iterator that contains all the elements in this container. |
| Read | Use **forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object)** to traverse the elements in this container. |
| Read | Use **\[Symbol.iterator]():IterableIterator\<[K,V]>** for data access. |
| Update | Use **replace(key: K, newValue: V)** to change the value of the specified key. |
| Update | Use **forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object)** to modify an element in this container. |
| Delete | Use **remove(key: K)** to remove an element with the specified key. |
| Delete | Use **clear()** to clear this container. |


## TreeSet

[TreeSet](../reference/apis-arkts/js-apis-treeset.md) is used to store a set of values, each of which is unique in a tree set.

**TreeSet** uses generics, and the values in a tree set are ordered. The bottom layer of **TreeSet** is a binary tree, which supports quick search of a value through the children (left child and right child) of the tree. The type of **value** must meet the ECMA standard. Values in a tree set are stored in order. The bottom layer of **TreeSet** is implemented based on the red-black tree and supports quick insertion and removal.

**TreeSet** is implemented based on [TreeMap](../reference/apis-arkts/js-apis-treemap.md). In **TreeSet**, only **value** objects are processed. **TreeSet** can be used to store values, each of which must be unique.

[HashSet](../reference/apis-arkts/js-apis-hashset.md) stores data in a random order, whereas **TreeSet** stores data in sorted order. Both of them allow only unique elements. However, null values are allowed in **HashSet**, but not in **TreeSet**, because null values may affect the order of elements in the container.

You are advised to use **TreeSet** when you need to store data in sorted order.

**TreeSet** provides the following CRUD APIs.

| Operation | Description |
| -------- | ------ |
| Create | Use **add(value: T)** to add a value to this container. |
| Read | Use **values()** to return an iterator that contains all the values in this container. |
| Read | Use **entries()** to return an iterator that contains all the elements in this container. |
| Read | Use **getFirstValue()** to obtain the first value in this container. |
| Read | Use **getLastValue()** to obtain the last value in this container. |
| Read | Use **forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object)** to traverse the elements in this container. |
| Read | Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access. |
| Update | Use **forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object)** to change a value in this container. |
| Delete | Use **remove(value: T)** to remove a value. |
| Delete | Use **clear()** to clear this container. |


## LightWeightMap

[LightWeightMap](../reference/apis-arkts/js-apis-lightweightmap.md) is used to store a set of associated KV pairs. In a lightweight map, each key is unique and corresponds to a value. **LightWeightMap** uses generics and a more lightweight structure. It uses the hash code to uniquely identify a key at the bottom layer. It uses linear probing to avoid collisions. In a lightweight map, a key is located by using the hash code and binary search algorithm. The hash code is stored in an array and mapped to a key and its value in another array. The type of **key** must comply with the ECMA standard.

The default initial capacity of a lightweight map is 8, and it has capacity doubled in each expansion.

Compared with [HashMap](../reference/apis-arkts/js-apis-hashmap.md), which can also store KV pairs, **LightWeightMap** occupies less memory.

You are advised to use **LightWeightMap** when you need to store and access **KV pairs**.

**LightWeightMap** provides the following CRUD APIs.

| Operation | Description |
| -------- | ------ |
| Create | Use **set(key: K, value: V)** to add an element (a KV pair) to this container. |
| Read | Use **get(key: K)** to obtain the value of the specified key. |
| Read | Use **getIndexOfKey(key: K)** to obtain the index of the specified key. |
| Read | Use **getIndexOfValue(value: V)** to obtain the index of the first occurrence of the specified value. |
| Read | Use **keys()** to return an iterator that contains all the keys in this container. |
| Read | Use **values()** to return an iterator that contains all the values in this container. |
| Read | Use **entries()** to return an iterator that contains all the elements in this container. |
| Read | Use **getKeyAt(index: number)** to obtain the key of an element at a given position (specified by **index**). |
| Read | Use **getValueAt(index: number)** to obtain the value of an element at a given position (specified by **index**). |
| Read | Use **forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object)** to traverse the elements in this container. |
| Read | Use **\[Symbol.iterator]():IterableIterator&lt;[K,V]&gt;** for data access. |
| Update | Use **setValueAt(index: number, newValue: V)** to change the value of an element at a given position (specified by **index**). |
| Update | Use **forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object)** to modify an element in this container. |
| Delete | Use **remove(key: K)** to remove an element with the specified key. |
| Delete | Use **removeAt(index: number)** to remove an element at a given position (specified by **index**). |
| Delete | Use **clear()** to clear this container. |


## LightWeightSet

[LightWeightSet](../reference/apis-arkts/js-apis-lightweightset.md) is used to store a set of values, each of which is unique in a lightweight set.

**LightWeightSet** uses generics and a lightweight structure. Its default initial capacity is 8, and it has capacity doubled in each expansion. In a lightweight set, a value is located by using the hash code and binary search algorithm. The hash code is stored in an array and mapped to a value in another array. The type of **value** must comply with the ECMA standard.

**LightWeightSet** uses the hash code to uniquely identify a value at the bottom layer. It uses linear probing to avoid collisions and adopts the binary search algorithm.

Compared with [HashSet](../reference/apis-arkts/js-apis-hashset.md), which can also store values, **LightWeightSet** occupies less memory.

You are advised to use **LightWeightSet** when you need a set that has only unique elements or need to deduplicate a set.

**LightWeightSet** provides the following CRUD APIs.

| Operation | Description |
| -------- | ------ |
| Create | Use **add(obj: T)** to add a value to this container. |
| Read | Use **getIndexOf(key: T)** to obtain the index of a key. |
| Read | Use **values()** to return an iterator that contains all the values in this container. |
| Read | Use **entries()** to return an iterator that contains all the elements in this container. |
| Read | Use **getValueAt(index: number)** to obtain the value of an element at a given position (specified by **index**). |
| Read | Use **forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object)** to traverse the elements in this container. |
| Read | Use **\[Symbol.iterator]():IterableIterator&lt;T&gt;** for data access. |
| Update | Use **forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object)** to change a value in this container. |
| Delete | Use **remove(key: K)** to remove an element with the specified key. |
| Delete | Use **removeAt(index: number)** to remove an element at a given position (specified by **index**). |
| Delete | Use **clear()** to clear this container. |


## PlainArray

[PlainArray](../reference/apis-arkts/js-apis-plainarray.md) is used to store a set of associated KV pairs. In a plain array, each key is unique, corresponds to a value, and is of the number type. **PlainArray** uses generics and a more lightweight structure. In a plain array, a key is located by using the binary search algorithm and is mapped to a value in another array.

The default initial capacity of a plain array is 16, and it has capacity doubled in each expansion.

Both **PlainArray** and [LightWeightMap](../reference/apis-arkts/js-apis-lightweightmap.md) are used to store KV pairs in the lightweight structure. However, the key type of **PlainArray** can only be **number**.

You are advised to use PlainArray when you need to store KV pairs whose keys are of the number type.

**PlainArray** provides the following CRUD APIs.

| Operation | Description |
| -------- | ------ |
| Create | Use **add(key: number,value: T)** to add an element (a KV pair) to this container. |
| Read | Use **get(key: number)** to obtain the value of the specified key. |
| Read | Use **getIndexOfKey(key: number)** to obtain the index of the specified key. |
| Read | Use **getIndexOfValue(value: T)** to obtain the index of the specified value. |
| Read | Use **getKeyAt(index: number)** to obtain the key of an element at a given position (specified by **index**). |
| Read | Use **getValueAt(index: number)** to obtain the value of an element at a given position (specified by **index**). |
| Read | Use **forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object)** to traverse the elements in this container. |
| Read | Use **\[Symbol.iterator]():IterableIterator&lt;[number, T]&gt;** for data access. |
| Update | Use **setValueAt(index:number, value: T)** to change the value of an element at a given position (specified by **index**). |
| Update | Use **forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object)** to modify an element in this container. |
| Delete | Use **remove(key: number)** to remove an element with the specified key. |
| Delete | Use **removeAt(index: number)** to remove an element at a given position (specified by **index**). |
| Delete | Use **removeRangeFrom(index: number, size: number)** to remove elements in a specified range. |
| Delete | Use **clear()** to clear this container. |


## Use of Nonlinear Containers

Refer to the code snippet below to add, access, and modify elements in **HashMap**, **TreeMap**, **LightWeightMap**, **Stack**, and **PlainArray**.


```ts
// HashMap
import { HashMap } from '@kit.ArkTS'; // Import the HashMap module.

let hashMap1: HashMap<string, number> = new HashMap();
hashMap1.set('a', 123);
let hashMap2: HashMap<number, number> = new HashMap();
hashMap2.set(4, 123); // Add an element.
console.info(`result: ${hashMap2.hasKey(4)}`); // Check whether an element is contained.
console.info(`result: ${hashMap1.get('a')}`); // Access an element.

// TreeMap
import { TreeMap } from '@kit.ArkTS'; // Import the TreeMap module.

let treeMap: TreeMap<string, number> = new TreeMap();
treeMap.set('a', 123);
treeMap.set('6', 356); // Add an element.
console.info(`result: ${treeMap.get('a')}`); // Access an element.
console.info(`result: ${treeMap.getFirstKey()}`); // Access the first element.
console.info(`result: ${treeMap.getLastKey()}`); // Access the last element.

// LightWeightMap
import { LightWeightMap } from '@kit.ArkTS'; // Import the LightWeightMap module.

let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set('x', 123);
lightWeightMap.set('8', 356); // Add an element.
console.info(`result: ${lightWeightMap.get('a')}`); // Access an element.
console.info(`result: ${lightWeightMap.get('x')}`); // Access an element.
console.info(`result: ${lightWeightMap.getIndexOfKey('8')}`); // Access an element.

// PlainArray
import { PlainArray } from '@kit.ArkTS'; // Import the PlainArray module.

let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, 'sdd');
plainArray.add(2,'sff'); // Add an element.
console.info(`result: ${plainArray.get(1)}`); // Access an element.
console.info(`result: ${plainArray.getKeyAt(1)}`); // Access an element.
```
