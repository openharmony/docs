# Nonlinear Containers


Nonlinear containers, underpinned by hash tables or red-black trees, implement a data structure that enables quick search. There are several types of nonlinear containers: **HashMap**, **HashSet**, **TreeMap**, **TreeSet**, **LightWeightMap**, **LightWeightSet**, and **PlainArray**. The types of **key** and **value** in nonlinear containers must meet the ECMA standard.

## Comparison of Non-linear Container Types

| Class| Characteristics and Recommended Application Scenarios|
| --------- | ------- |
| HashMap | Stores a set of key-value pairs that have association relationships. The key in the storage element is unique, and the storage location is determined based on the hash value of the key. The access speed is fast, but the sorting cannot be customized. Recommended for quick access, insertion, and deletion of key-value pair data.|
| HashSet | A set of values. Each value in a storage element is unique. The storage location is determined based on the hash of the value. Null values can be added, but the sorting cannot be customized. It can be used when a non-repeated collection is required or a collection needs to be deduplicated.|
| TreeMap | Stores a set of key-value pairs that have association relationships. The key in the storage element is unique. You can customize the sorting method. Generally, this mode can be used in scenarios where key-value pairs need to be stored in sequence.|
| TreeSet | A set of values. The values in the storage element are unique. You can customize the sorting method, but you are not advised to put null values. Generally, this method can be used in scenarios where collections need to be stored in sequence.|
| LightWeightMap | Stores a set of key-value pairs that have association relationships. The key in the storage element is unique. The bottom layer uses a more lightweight structure and occupies less space. This mode is recommended when key-value pair data needs to be accessed and the memory is insufficient.|
| LightWeightSet |  Stores a set of values. The values in the storage element are unique. The bottom layer uses a more lightweight structure and occupies less space. This method is recommended when you need a unique set or a set to be deduplicated.|
| PlainArray | Stores a set of key-value pairs that have association relationships. The key in the storage element is unique. The bottom layer uses a more lightweight structure like LightWeightMap, and the key is of the number type. You are advised to use PlainArray when you need to store KV pairs whose keys are of the number type.|

## HashMap

[HashMap](../reference/apis-arkts/js-apis-hashmap.md) is used to store a set of associated key-value (KV) pairs. In a hash map, each key is unique and corresponds to a value.

**HashMap** uses generics. In a hash map, a key is located based on its hash code. The initial capacity of a hash map is 16, and it has capacity doubled in each dynamic expansion. The bottom layer of **HashMap** is implemented based on a hash table. It uses chaining to avoid collisions in hash tables.

**HashMap** is faster in accessing data than [TreeMap](../reference/apis-arkts/js-apis-treemap.md), because the former accesses the keys based on the hash codes, whereas the latter stores and accesses the keys in sorted order.

[HashSet](../reference/apis-arkts/js-apis-hashset.md) is implemented based on **HashMap**. The input parameter of **HashMap** consists of **key** and **value**. In **HashSet**, only the **value** object is processed.

You are advised to use **HashMap** when you need to quickly access, remove, and insert KV pairs.

**HashMap** provides the following Create, Read, Update, and Delete (CRUD) APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| set(key: K, value: V) | Adds a key-value pair.|
| Read| get(key: K) | Value corresponding to the target key.|
| Read| keys() | Use **keys()** to return an iterator that contains all the keys in this container.|
| Read| values() | Use **values()** to return an iterator that contains all the values in this container.|
| Read| entries() | Use **entries()** to return an iterator that contains all the elements in this container.|
| Read| forEach(callbackFn: (value?: V, key?: K, map?: HashMap<K, V>) => void, thisArg?: Object) | Traverses the elements of the entire map.|
| Read| \[Symbol.iterator]():IterableIterator&lt;[K,V]&gt; | Creates an iterator for data access.|
| Update| replace(key: K, newValue: V) | Value corresponding to the target key.|
| Update| forEach(callbackFn: (value?: V, key?: K, map?: HashMap<K, V>) => void, thisArg?: Object) | Modify the elements of the entire map through traversal.|
| Delete| remove(key: K) | Deletes the matched key-value pair from the map.|
| Delete| clear() | Clears the entire map.|

## HashSet

[HashSet](../reference/apis-arkts/js-apis-hashset.md) is used to store a set of values, each of which is unique in a hash set.

**HashSet** uses generics. In a hash set, a value is located based on its hash code. The initial capacity of a hash set is 16, and it has capacity doubled in each dynamic expansion. The type of **value** must comply with the ECMA standard. HashSet is implemented based on [HashMap](../reference/apis-arkts/js-apis-hashmap.md) and processes only the value object. The bottom-layer data structure is the same as that of HashMap.

Compared with [TreeSet](../reference/apis-arkts/js-apis-treeset.md), data in HashSet is stored in an unordered manner, that is, users cannot specify the sorting mode. However, data in TreeSet is stored in an ordered manner, that is, elements can be sorted based on the sorting function specified by users. Both of them allow only unique elements. However, null values are allowed in **HashSet**, but not in **TreeSet**, because null values may affect the order of elements in the container.

You are advised to use **HashSet** when you need a set that has only unique elements or need to deduplicate a set.

**HashSet** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| add(value: T) | Adds a value.|
| Read| values() | Use **values()** to return an iterator that contains all the values in this container.|
| Read| entries() | Use **entries()** to return an iterator that contains all the elements in this container.|
| Read| forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object) | Traverses and accesses the elements of the entire set.|
| Read| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Update| forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object) | Modify the elements of the entire set through traversal.|
| Delete| remove(value: T) | Deletes the matched value from the set.|
| Delete| clear() | Clears the entire set.|

## TreeMap

[TreeMap](../reference/apis-arkts/js-apis-treemap.md) is used to store a set of associated KV pairs. In a tree map, each key is unique and corresponds to a value.

**TreeMap** uses generics, and the keys in a tree map are ordered. The bottom layer of **TreeMap** is a binary tree, which supports quick search of KV pairs through the children (left child and right child) of the tree. The type of **key** must comply with the ECMA standard. Keys in a tree map are stored in order. The bottom layer of **TreeMap** is implemented based on the red-black tree and supports quick insertion and removal.

[HashMap](../reference/apis-arkts/js-apis-hashmap.md) is faster in accessing data than **TreeMap**, because the former accesses the keys based on the hash codes, whereas the latter stores and accesses the keys in sorted order.

You are advised to use **TreeMap** when you need to store KV pairs in sorted order.

**TreeMap** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| set(key: K, value: V) | Adds a key-value pair.|
| Read| get(key: K) | Value corresponding to the target key.|
| Read| getFirstKey() | Use **getFirstKey()** to obtain the first key in this container.|
| Read| getLastKey() | Use **getLastKey()** to obtain the last key in this container.|
| Read| keys() | Use **keys()** to return an iterator that contains all the keys in this container.|
| Read| values() | Use **values()** to return an iterator that contains all the values in this container.|
| Read| entries() | Use **entries()** to return an iterator that contains all the elements in this container.|
| Read| forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object) | Traverses the elements of the entire map.|
| Read| \[Symbol.iterator]():IterableIterator&lt;[K,V]&gt; | Creates an iterator for data access.|
| Update| replace(key: K, newValue: V) | Value corresponding to the target key.|
| Update| forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object) | Modify the elements of the entire map through traversal.|
| Delete| remove(key: K) | Deletes the matched key-value pair from the map.|
| Delete| clear() | Clears the entire map.|

## TreeSet

[TreeSet](../reference/apis-arkts/js-apis-treeset.md) is used to store a set of values, each of which is unique in a tree set.

**TreeSet** uses generics, and the values in a tree set are ordered. The bottom layer of **TreeSet** is a binary tree, which supports quick search of a value through the children (left child and right child) of the tree. The type of **value** must meet the ECMA standard. Values in a tree set are stored in order. The bottom layer of **TreeSet** is implemented based on the red-black tree and supports quick insertion and removal.

**TreeSet** is implemented based on [TreeMap](../reference/apis-arkts/js-apis-treemap.md). In **TreeSet**, only **value** objects are processed. A TreeSet can be used to store a set of values. The value in an element is unique and can be sorted based on the sorting function specified by the user.

[HashSet](../reference/apis-arkts/js-apis-hashset.md) stores data in a random order, whereas **TreeSet** stores data in sorted order. Both of them allow only unique elements. However, null values are allowed in **HashSet**, but not in **TreeSet**, because null values may affect the order of elements in the container.

You are advised to use **TreeSet** when you need to store data in sorted order.

**TreeSet** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| add(value: T) | Adds a value.|
| Read| values() | Use **values()** to return an iterator that contains all the values in this container.|
| Read| entries() | Use **entries()** to return an iterator that contains all the elements in this container.|
| Read| getFirstValue() | Use **getFirstValue()** to obtain the first value in this container.|
| Read| getLastValue() | Use **getLastValue()** to obtain the last value in this container.|
| Read| forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object) | Traverses and accesses the elements of the entire set.|
| Read| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Update| forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object) | Modify the elements of the entire set through traversal.|
| Delete| remove(value: T) | Deletes the matched value from the set.|
| Delete| clear() | Clears the entire set.|

## LightWeightMap

[LightWeightMap](../reference/apis-arkts/js-apis-lightweightmap.md) is used to store a set of associated KV pairs. In a lightweight map, each key is unique and corresponds to a value. **LightWeightMap** uses generics and a more lightweight structure. It uses the hash code to uniquely identify a key at the bottom layer. It uses linear probing to avoid collisions. In a lightweight map, a key is located by using the hash code and binary search algorithm. The hash code is stored in an array and mapped to a key and its value in another array. The type of **key** must comply with the ECMA standard.

The default initial capacity of a lightweight map is 8, and it has capacity doubled in each expansion.

Compared with [HashMap](../reference/apis-arkts/js-apis-hashmap.md), which can also store KV pairs, **LightWeightMap** occupies less memory.

You are advised to use **LightWeightMap** when you need to store and access **KV pairs**.

**LightWeightMap** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| set(key: K, value: V) | Adds a key-value pair.|
| Read| get(key: K) | Value corresponding to the target key.|
| Read| getIndexOfKey(key: K) | Obtains the index of a specified key in a map.|
| Read| getIndexOfValue(value: V) | Obtains the first index of a specified value in a map.|
| Read| keys() | Use **keys()** to return an iterator that contains all the keys in this container.|
| Read| values() | Use **values()** to return an iterator that contains all the values in this container.|
| Read| entries() | Use **entries()** to return an iterator that contains all the elements in this container.|
| Read| getKeyAt(index: number) | Pointer to the function used to obtain the cookie value of a specified URL.|
| Read| getValueAt(index: number) | Pointer to the function used to obtain the cookie value of a specified URL.|
| Read| forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object) | Traverses the elements of the entire map.|
| Read| \[Symbol.iterator]():IterableIterator&lt;[K,V]&gt; | Creates an iterator for data access.|
| Update| setValueAt(index: number, newValue: V) | Modifies the value of a specified index.|
| Update| forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object) | Modify the elements of the entire map through traversal.|
| Delete| remove(key: K) | Deletes the key-value pair that matches a specified key in a map.|
| Delete| removeAt(index: number) | Removes a key-value pair with the specified key.|
| Delete| clear() | Clears the entire map.|

## LightWeightSet

[LightWeightSet](../reference/apis-arkts/js-apis-lightweightset.md) is used to store a set of values, each of which is unique in a lightweight set.

**LightWeightSet** uses generics and a lightweight structure. Its default initial capacity is 8, and it has capacity doubled in each expansion. In a lightweight set, a value is located by using the hash code and binary search algorithm. The hash code is stored in an array and mapped to a value in another array. The type of **value** must comply with the ECMA standard.

**LightWeightSet** uses the hash code to uniquely identify a value at the bottom layer. It uses linear probing to avoid collisions and adopts the binary search algorithm.

Compared with [HashSet](../reference/apis-arkts/js-apis-hashset.md), which can also store values, **LightWeightSet** occupies less memory.

You are advised to use **LightWeightSet** when you need a set that has only unique elements or need to deduplicate a set.

**LightWeightSet** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| add(value: T) | Adds a value.|
| Read| getIndexOf(key: T) | Key of the value to obtain.|
| Read| getValueAt(index: number) | Pointer to the function used to obtain the cookie value of a specified URL.|
| Read| values() | Use **values()** to return an iterator that contains all the values in this container.|
| Read| entries() | Use **entries()** to return an iterator that contains all the elements in this container.|
| Read| forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object) | Traverses and accesses the elements of the entire set.|
| Read| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Update| forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object) | Modify the elements of the entire set through traversal.|
| Delete| remove(key: K) | Deletes the matched key-value pair from the set.|
| Delete| removeAt(index: number) | Deletes the value of a specified index from a set.|
| Delete| clear() | Clears the entire set.|

## PlainArray

[PlainArray](../reference/apis-arkts/js-apis-plainarray.md) is used to store a set of associated KV pairs. In a plain array, each key is unique, corresponds to a value, and is of the number type. **PlainArray** uses generics and a more lightweight structure. In a plain array, a key is located by using the binary search algorithm and is mapped to a value in another array.

The default initial capacity of a plain array is 16, and it has capacity doubled in each expansion.

Both **PlainArray** and [LightWeightMap](../reference/apis-arkts/js-apis-lightweightmap.md) are used to store KV pairs in the lightweight structure. However, the key type of **PlainArray** can only be **number**.

You are advised to use PlainArray when you need to store KV pairs whose keys are of the number type.

**PlainArray** provides the following CRUD APIs.

| Operation| API| Description|
| --------- | ------- | ------- |
| Create| add(key: number,value: T) | Adds a key-value pair.|
| Read| get(key: number) | Value corresponding to the target key.|
| Read| getIndexOfKey(key: number) | Obtains the index of a specified key in PlainArray.|
| Read| getIndexOfValue(value: T) | Obtains the first index of a specified value in a PlainArray.|
| Read| getKeyAt(index: number) | Pointer to the function used to obtain the cookie value of a specified URL.|
| Read| getValueAt(index: number) | Pointer to the function used to obtain the cookie value of a specified URL.|
| Read| forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object) | Traverses the elements of the entire PlainArray.|
| Read| \[Symbol.iterator]():IterableIterator&lt;[number, T]&gt; | Creates an iterator for data access.|
| Update| setValueAt(index:number, value: T) | Modifies the value of a specified index.|
| Update| forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object) | Modify the elements of the entire PlainArray through traversal.|
| Delete| remove(key: number) | Deletes the key-value pair that matches a specified key in PlainArray.|
| Delete| removeAt(index: number) | Removes a key-value pair with the specified key.|
| Delete| removeRangeFrom(index: number, size: number) | Deletes elements in a specified range from PlainArray.|
| Delete| clear() | Clears the entire PlainArray.|

## Use of Nonlinear Containers

Refer to the code snippet below to add, access, and modify elements in **HashMap**, **TreeMap**, **LightWeightMap**, **Stack**, and **PlainArray**.


```ts
// HashMap
import { HashMap } from '@kit.ArkTS'; // Import the HashMap module.

let hashMap1: HashMap<string, number> = new HashMap();
hashMap1.set ('a', 123); // Add an element whose key is'a' and value is 123.
let hashMap2: HashMap<number, number> = new HashMap();
hashMap2.set (4, 123); // Add an element whose key is 4 and value is 123.
console.info ('result: ${hashMap2.hasKey (4) }'); // Check whether an element whose key is 4 exists. Output: result: true
console.info ('result: ${hashMap1.get ('a') }'); // Element whose access key is'a'. Output: result: 123

// TreeMap
import { TreeMap } from '@kit.ArkTS'; // Import the TreeMap module.

let treeMap: TreeMap<string, number> = new TreeMap();
treeMap.set ('a', 123); // Add an element whose key is'a' and value is 123.
treeMap.set ('6', 356); // Add an element whose key is '6' and value is 356.
console.info ('result: ${treeMap.get ('a') }'); // Element whose access key is'a'. Output: result: 123
console.info ('result: ${treeMap.getFirstKey () }'); // Access the first element. Output: result: 6
console.info ('result: ${treeMap.getLastKey () }'); // Access the last element. Output: result: a

// LightWeightMap
import { LightWeightMap } from '@kit.ArkTS'; // Import the LightWeightMap module.

let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set ('x', 123); // Add an element whose key is'x' and value is 123.
lightWeightMap.set ('8', 356); // Add an element whose key is '8' and value is 356.
console.info ('result: ${lightWeightMap.get ('a') }'); // Element whose access key is'a'. Output: result: undefined
console.info ('result: ${lightWeightMap.get ('x') }'); // Obtain the value of the element whose access key is 'x'. Output: result: 123
console.info(`result: ${lightWeightMap.getIndexOfKey('8')}`); // accesses the element whose key is '8' and obtains its index. Output: result: 0

// PlainArray
import { PlainArray } from '@kit.ArkTS'; // Import the PlainArray module.

let plainArray: PlainArray<string> = new PlainArray();
plainArray.add (1,'sdd'); // Add an element whose key is 1 and value is'sdd'.
plainArray.add (2, 'sff'); // Add an element whose key is 2 and value is'sff'.
console.info ('result: ${plainArray.get (1) }'); // Access the element whose key is 1 to obtain the value. Output: result: sdd
console.info ('result: ${plainArray.getKeyAt (1) }'); // Access the element whose index is 1 to obtain the key. Output: result: 2
```
