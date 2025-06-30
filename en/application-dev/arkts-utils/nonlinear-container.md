# Nonlinear Containers


Nonlinear containers, underpinned by hash tables or red-black trees, implement a data structure that enables quick lookup operations. There are several types of nonlinear containers: HashMap, HashSet, TreeMap, TreeSet, LightWeightMap, LightWeightSet, and PlainArray. The types of **key** and **value** in nonlinear containers comply with the ECMA standard.

## Comparison of Nonlinear Container Types

| Type| Characteristics and Recommended Use Cases|
| --------- | ------- |
| HashMap | Stores a collection of key-value (KV) pairs with unique keys. It uses the hash code of the key to determine the storage location, offering fast access but no custom sorting. It is recommended for scenarios requiring quick storage, retrieval, and removal of KV pairs.|
| HashSet | Stores a collection of unique values. It uses the hash code of the value to determine the storage location. It allows null values but does not support custom sorting. It is useful for creating non-redundant collections or removing duplicates.|
| TreeMap | Stores a collection of KV pairs with unique keys. It allows users to customize sorting methods. It is suitable for scenarios requiring ordered storage of KV pairs.|
| TreeSet | Stores a collection of unique values. It allows users to customize sorting methods but does not recommend storing null values. It is suitable for scenarios requiring ordered storage of collections.|
| LightWeightMap | Stores a collection of KV pairs with unique keys. It uses a more lightweight structure, occupying less memory. It is recommended for scenarios with limited memory and the need to store KV pairs.|
| LightWeightSet |  Stores a collection of unique values. It uses a more lightweight structure, occupying less memory. It is useful for creating non-redundant collections or removing duplicates.|
| PlainArray | Stores a collection of KV pairs with unique keys, where keys are of the number type. It uses a lightweight structure and a binary search algorithm for key lookup. It is suitable for storing KV pairs with number-type keys.|

## HashMap

[HashMap](../reference/apis-arkts/js-apis-hashmap.md) is used to store a collection of KV pairs with unique keys. Each key corresponds to a value.

Defined by generics, HashMap uses the hash code of the key to determine the storage location, enabling quick access to KV pairs. The initial capacity is 16, and it supports dynamic resizing, doubling its size each time. HashMap is implemented using a hash table with a chain address conflict resolution strategy.

HashMap is faster in accessing data than [TreeMap](../reference/apis-arkts/js-apis-treemap.md), because the former accesses the keys based on the hash codes, whereas the latter stores and accesses the keys in sorted order.

[HashSet](../reference/apis-arkts/js-apis-hashset.md) is implemented based on HashMap. HashMap takes **key** and **value** as input parameters. In HashSet, only the **value** object is processed.

You are advised to use HashMap when you need to quickly access, remove, and insert KV pairs.

Common APIs for adding, removing, modifying, and accessing elements in HashMap are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| set(key: K, value: V) | Adds a KV pair.|
| Accessing elements| get(key: K) | Obtains the value corresponding to the specified key.|
| Accessing elements| keys() | Returns an iterator that contains all the keys in the map.|
| Accessing elements| values() | Returns an iterator that contains all the values in the map.|
| Accessing elements| entries() | Returns an iterator that contains all the KV pairs in the map.|
| Accessing elements| forEach(callbackFn: (value?: V, key?: K, map?: HashMap<K, V>) => void, thisArg?: Object) | Iterates over all elements in the map.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;[K,V]&gt; | Creates an iterator for data access.|
| Modifying elements| replace(key: K, newValue: V) | Modifies the value corresponding to the specified key.|
| Modifying elements| forEach(callbackFn: (value?: V, key?: K, map?: HashMap<K, V>) => void, thisArg?: Object) | Modifies all elements in the map through iteration.|
| Removing elements| remove(key: K) | Removes the KV pair matching the specified key from the map.|
| Removing elements| clear() | Clears the entire map.|

## HashSet

[HashSet](../reference/apis-arkts/js-apis-hashset.md) is used to store a collection of unique values.

Defined by generics, HashSet uses the hash code of the value to determine the storage location, enabling quick access to the value. The initial capacity is 16, and it supports dynamic resizing, doubling its size each time. The type of **value** must comply with the ECMA standard. HashSet is implemented based on [HashMap](../reference/apis-arkts/js-apis-hashmap.md) and processes only the **value** object. The underlying data structure is consistent with HashMap.

Compared with [TreeSet](../reference/apis-arkts/js-apis-treeset.md), which stores data in an ordered manner and allows users to define sorting functions, HashSet stores data in an unordered manner and does not support custom sorting. Neither allows duplicate elements, but HashSet permits null values, whereas TreeSet does not recommend storing null values as it may affect sorting results.

You are advised to use HashSet when you need to create non-redundant collections or remove duplicates.

Common APIs for adding, removing, modifying, and accessing elements in HashSet are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| add(value: T) | Adds a value.|
| Accessing elements| values() | Returns an iterator that contains all the values in the set.|
| Accessing elements| entries() | Returns an iterator object containing array-like KV pairs, where both keys and values are the same.|
| Accessing elements| forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object) | Iterates over all elements in the set.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Modifying elements| forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object) | Modifies all elements in the set through iteration.|
| Removing elements| remove(value: T) | Removes the matching value from the set.|
| Removing elements| clear() | Clears the entire set.|

## TreeMap

[TreeMap](../reference/apis-arkts/js-apis-treemap.md) is used to store a collection of KV pairs with unique keys. Each key corresponds to a value.

Defined by generics, TreeMap stores keys in an ordered manner. TreeMap is implemented using a red-black tree, enabling fast insertion and removal. The type of **key** complies with the ECMA standard.

Compared with [HashMap](../reference/apis-arkts/js-apis-hashmap.md), which provides faster access based on the key's hash code, TreeMap is ordered and thus less efficient.

You are advised to use TreeMap when you need to store KV pairs in sorted order.

Common APIs for adding, removing, modifying, and accessing elements in TreeMap are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| set(key: K, value: V) | Adds a KV pair.|
| Accessing elements| get(key: K) | Obtains the value corresponding to the specified key.|
| Accessing elements| getFirstKey() | Obtains the first key in the map.|
| Accessing elements| getLastKey() | Obtains the last key in the map.|
| Accessing elements| keys() | Returns an iterator that contains all the keys in the map.|
| Accessing elements| values() | Returns an iterator that contains all the values in the map.|
| Accessing elements| entries() | Returns an iterator that contains all the KV pairs in the map.|
| Accessing elements| forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object) | Iterates over all elements in the map.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;[K,V]&gt; | Creates an iterator for data access.|
| Modifying elements| replace(key: K, newValue: V) | Modifies the value corresponding to the specified key.|
| Modifying elements| forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object) | Modifies all elements in the map through iteration.|
| Removing elements| remove(key: K) | Removes the KV pair matching the specified key from the map.|
| Removing elements| clear() | Clears the entire map.|

## TreeSet

[TreeSet](../reference/apis-arkts/js-apis-treeset.md) is used to store a collection of unique values.

Defined by generics, TreeSet stores values in an ordered manner. TreeSet is implemented using a red-black tree, enabling fast insertion and removal. The type of **value** complies with the ECMA standard.

TreeSet is based on [TreeMap](../reference/apis-arkts/js-apis-treemap.md) and processes only the **value** object. It allows for ordered storage of a collection of values and can be sorted according to a custom sorting function.

Compared with [HashSet](../reference/apis-arkts/js-apis-hashset.md), which stores data in an unordered manner, TreeSet stores data in an ordered manner. Neither allows duplicate elements, but HashSet permits null values, whereas TreeSet does not recommend storing null values as it may affect sorting results.

You are advised to use TreeSet when you need to store data in sorted order.

Common APIs for adding, removing, modifying, and accessing elements in TreeSet are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| add(value: T) | Adds a value.|
| Accessing elements| values() | Returns an iterator that contains all the values in the set.|
| Accessing elements| entries() | Returns an iterator object containing array-like KV pairs, where both keys and values are the same.|
| Accessing elements| getFirstValue() | Obtains the first value in the set.|
| Accessing elements| getLastValue() | Obtains the last value in the set.|
| Accessing elements| forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object) | Iterates over all elements in the set.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Modifying elements| forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object) | Modifies all elements in the set through iteration.|
| Removing elements| remove(value: T) | Removes the matching value from the set.|
| Removing elements| clear() | Clears the entire set.|

## LightWeightMap

[LightWeightMap](../reference/apis-arkts/js-apis-lightweightmap.md) is used to store a collection of KV pairs with unique keys. Each key corresponds to a value. Defined by generics, LightWeightMap uses a more lightweight structure. The underlying structure uses hash codes to identify unique keys, with a conflict resolution strategy of linear probing. The lookup of keys relies on hash codes and binary search algorithms, storing hash codes in an array and mapping them to **key** and **value** values in other arrays. The type of **key** complies with the ECMA standard.

The default initial capacity is 8, and it supports dynamic resizing, doubling its size each time.

LightWeightMap and [HashMap](../reference/apis-arkts/js-apis-hashmap.md) are both used to store KV pairs, but LightWeightMap occupies less memory.

You are advised to use LightWeightMap when you need to store and access KV pairs.

Common APIs for adding, removing, modifying, and accessing elements in LightWeightMap are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| set(key: K, value: V) | Adds a KV pair.|
| Accessing elements| get(key: K) | Obtains the value corresponding to the specified key.|
| Accessing elements| getIndexOfKey(key: K) | Obtains the index of the specified key in the map.|
| Accessing elements| getIndexOfValue(value: V) | Obtains the index of the first occurrence of the specified value in the map.|
| Accessing elements| keys() | Returns an iterator that contains all the keys in the map.|
| Accessing elements| values() | Returns an iterator that contains all the values in the map.|
| Accessing elements| entries() | Returns an iterator that contains all the KV pairs in the map.|
| Accessing elements| getKeyAt(index: number) | Obtains the key at the specified index.|
| Accessing elements| getValueAt(index: number) | Obtains the value at the specified index.|
| Accessing elements| forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object) | Iterates over all elements in the map.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;[K,V]&gt; | Creates an iterator for data access.|
| Modifying elements| setValueAt(index: number, newValue: V) | Modifies the value at the specified index.|
| Modifying elements| forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object) | Modifies all elements in the map through iteration.|
| Removing elements| remove(key: K) | Removes the KV pair matching the specified key from the map.|
| Removing elements| removeAt(index: number) | Removes the KV pair at the specified index from the map.|
| Removing elements| clear() | Clears the entire map.|

## LightWeightSet

[LightWeightSet](../reference/apis-arkts/js-apis-lightweightset.md) is used to store a collection of unique values.

Defined by generics, LightWeightSet uses a more lightweight structure. The default initial capacity is 8, and it supports dynamic resizing, doubling its size each time. The lookup of values relies on hash codes and binary search algorithms, storing hash codes in an array and mapping them to values in other arrays. The type of **value** complies with the ECMA standard.

LightWeightSet identifies unique values based on hash at the underlying layer, with a conflict resolution strategy of linear probing and a lookup strategy based on binary search.

LightWeightSet and [HashSet](../reference/apis-arkts/js-apis-hashset.md) are both used to store unique values, but LightWeightSet occupies less memory.

You are advised to use LightWeightSet when you need a collection that contains unique elements or need to deduplicate a collection with limited memory.

Common APIs for adding, removing, modifying, and accessing elements in LightWeightSet are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| add(obj: T) | Adds a value.|
| Accessing elements| getIndexOf(key: T) | Obtains the index corresponding to the specified key.|
| Accessing elements| getValueAt(index: number) | Obtains the value at the specified index.|
| Accessing elements| values() | Returns an iterator that contains all the values in the set.|
| Accessing elements| entries() | Returns an iterator object containing array-like KV pairs, where both keys and values are the same.|
| Accessing elements| forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object) | Iterates over all elements in the set.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;T&gt; | Creates an iterator for data access.|
| Modifying elements| forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object) | Modifies all elements in the set through iteration.|
| Removing elements| remove(key: K) | Removes the KV pair matching the specified key from the set.|
| Removing elements| removeAt(index: number) | Removes the value at the specified index from the set.|
| Removing elements| clear() | Clears the entire set.|

## PlainArray

[PlainArray](../reference/apis-arkts/js-apis-plainarray.md) is used to store a collection of KV pairs with unique keys, where keys are of the number type. Each key corresponds to a value. Defined by generics, PlainArray uses a more lightweight structure, with key lookup relying on binary search algorithms and mapping to **value** values in other arrays.

The default initial capacity is 16, and it supports dynamic resizing, doubling its size each time.

PlainArray and [LightWeightMap](../reference/apis-arkts/js-apis-lightweightmap.md) are both used to store KV pairs with a lightweight structure, but PlainArray's keys can only be of the number type.

You are advised to use PlainArray when you need to store KV pairs whose keys are of the number type.

Common APIs for adding, removing, modifying, and accessing elements in PlainArray are as follows:

| Operation| API| Description|
| --------- | ------- | ------- |
| Adding elements| add(key: number,value: T) | Adds a KV pair.|
| Accessing elements| get(key: number) | Obtains the value corresponding to the specified key.|
| Accessing elements| getIndexOfKey(key: number) | Obtains the index of the specified key in the PlainArray.|
| Accessing elements| getIndexOfValue(value: T) | Obtains the index of the first occurrence of the specified value in the PlainArray.|
| Accessing elements| getKeyAt(index: number) | Obtains the key at the specified index.|
| Accessing elements| getValueAt(index: number) | Obtains the value at the specified index.|
| Accessing elements| forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object) | Iterates over all elements in the PlainArray.|
| Accessing elements| \[Symbol.iterator]():IterableIterator&lt;[number, T]&gt; | Creates an iterator for data access.|
| Modifying elements| setValueAt(index:number, value: T) | Modifies the value at the specified index.|
| Modifying elements| forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object) | Modifies all elements in the PlainArray through iteration.|
| Removing elements| remove(key: number) | Removes the KV pair matching the specified key.|
| Removing elements| removeAt(index: number) | Removes the KV pair at the specified index.|
| Removing elements| removeRangeFrom(index: number, size: number) | Removes elements within the specified range in the PlainArray.|
| Removing elements| clear() | Clears the entire PlainArray.|

## Use of Nonlinear Containers

Here are usage examples for common nonlinear containers, including HashMap, TreeMap, LightWeightMap, and PlainArray, covering importing modules, adding elements, accessing elements, and modifying elements. The example code is as follows:


```ts
// HashMap
import { HashMap } from '@kit.ArkTS'; // Import the HashMap module.

let hashMap1: HashMap<string, number> = new HashMap();
hashMap1.set('a', 123); // Add an element with key 'a' and value 123.
let hashMap2: HashMap<number, number> = new HashMap();
hashMap2.set(4, 123); // Add an element with key 4 and value 123.
console.info(`result: ${hashMap2.hasKey(4)}`); // Check whether an element with key 4 exists. Output: result: true
console.info(`result: ${hashMap1.get('a')}`); // Access an element with key 'a'. Output: result: 123

// TreeMap
import { TreeMap } from '@kit.ArkTS'; // Import the TreeMap module.

let treeMap: TreeMap<string, number> = new TreeMap();
treeMap.set('a', 123); // Add an element with key 'a' and value 123.
treeMap.set('6', 356); // Add an element with key '6' and value 356.
console.info(`result: ${treeMap.get('a')}`); // Access an element with key 'a'. Output: result: 123
console.info(`result: ${treeMap.getFirstKey()}`); // Access the first element. Output: result: 6
console.info(`result: ${treeMap.getLastKey()}`); // Access the last element. Output: result: a

// LightWeightMap
import { LightWeightMap } from '@kit.ArkTS'; // Import the LightWeightMap module.

let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set('x', 123); // Add an element with key 'x' and value 123.
lightWeightMap.set('8', 356); // Add an element with key '8' and value 356.
console.info(`result: ${lightWeightMap.get('a')}`); // Access an element with key 'a'. Output: result: undefined
console.info(`result: ${lightWeightMap.get('x')}`); // Obtain the value of the element with key 'x'. Output: result: 123
console.info(`result: ${lightWeightMap.getIndexOfKey('8')}`); // Obtain the index of the element with key '8'. Output: result: 0

// PlainArray
import { PlainArray } from '@kit.ArkTS'; // Import the PlainArray module.

let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, 'sdd'); // Add an element with key 1 and value 'sdd'.
plainArray.add(2, 'sff'); // Add an element with key 2 and value 'sff'.
console.info(`result: ${plainArray.get(1)}`); // Obtain the value of the element with key 1. Output: result: sdd
console.info(`result: ${plainArray.getKeyAt(1)}`); // Obtain the key of the element at index 1. Output: result: 2
```
