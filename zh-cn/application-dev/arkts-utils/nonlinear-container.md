# 非线性容器
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->


非线性容器实现能快速查找的数据结构，其底层通过hash或者红黑树实现，包括HashMap、HashSet、TreeMap、TreeSet、LightWeightMap、LightWeightSet、PlainArray七种。非线性容器中的key及value的类型均满足ECMA标准。

## 各非线性容器类型特征对比

| 类名 | 特征及建议使用场景 |
| --------- | ------- |
| HashMap | 存储具有关联关系的键值对集合。键唯一，依据键的hash值确定存储位置。访问速度快，但不能自定义排序。推荐用于需要快速存取、插入删除键值对数据时使用。 |
| HashSet | 存储一系列值的集合。值唯一，依据值的hash确定存储位置。允许放入null值，但不能自定义排序。适用于不重复的集合或去重某个集合。 |
| TreeMap | 存储具有关联关系的键值对集合。键唯一，允许用户自定义排序方法。适用于按序存储键值对的场景。 |
| TreeSet | 存储一系列值的集合。值唯一，允许用户自定义排序方法，但不建议放入null值。适用于按序存储集合的场景。 |
| LightWeightMap | 存储具有关联关系的键值对集合。键唯一，底层采用轻量级结构，空间占用小。推荐用于存取键值对数据且内存不充足时。 |
| LightWeightSet | 存储一系列值的集合。值唯一，底层采用轻量级结构，空间占用小。适用于不重复的集合或去重某个集合。 |
| PlainArray | 存储具有关联关系的键值对集合。键唯一，底层与LightWeightMap一样采用轻量级结构，键固定为number类型。适用于存储键为number类型键值对的场景。 |

## HashMap

[HashMap](../reference/apis-arkts/js-apis-hashmap.md)可用来存储具有关联关系的key-value键值对集合，存储元素中key是唯一的，每个key会对应一个value值。

HashMap通过泛型定义，利用键的哈希值确定存储位置，实现快速查找。初始容量为16，支持动态扩容，每次扩容为原容量的两倍。底层基于哈希表实现，冲突处理采用链地址法。

HashMap和[TreeMap](../reference/apis-arkts/js-apis-treemap.md)相比，HashMap依据键的hashCode存取数据，访问速度较快。TreeMap则按顺序存取，效率较低。

[HashSet](../reference/apis-arkts/js-apis-hashset.md)基于HashMap实现。HashMap的输入参数由key、value两个值组成。在HashSet中，只处理value对象。

需要快速存取、删除以及插入键值对数据时，推荐使用HashMap。

HashMap支持增、删、改、查操作，常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | set(key: K, value: V) | 增加一个键值对。 |
| 访问元素 | get(key: K) | 获取key对应的value值。 |
| 访问元素 | keys() | 返回一个迭代器对象，包含map中的所有key值。 |
| 访问元素 | values() | 返回一个迭代器对象，包含map中的所有value值。 |
| 访问元素 | entries() | 返回一个迭代器对象，包含map中的所有键值对。 |
| 访问元素 | forEach(callbackFn: (value?: V, key?: K, map?: HashMap<K, V>) => void, thisArg?: Object) | 遍历访问整个map的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;[K,V]&gt; | 创建迭代器以访问数据。 |
| 修改元素 | replace(key: K, newValue: V) | 修改指定key对应的value值。 |
| 修改元素 | forEach(callbackFn: (value?: V, key?: K, map?: HashMap<K, V>) => void, thisArg?: Object) | 遍历并修改整个map的元素。 |
| 删除元素 | remove(key: K) | 删除map中匹配到的键值对。 |
| 删除元素 | clear() | 清空整个map。 |

## HashSet

[HashSet](../reference/apis-arkts/js-apis-hashset.md)可用来存储一系列值的集合，存储元素中value是唯一的。

HashSet基于泛型定义，集合中通过value的hash值确定存储位置，从而快速找到该值。初始容量为16，支持动态扩容，每次扩容为原始容量的2倍。value的类型需满足ECMA标准。HashSet基于[HashMap](../reference/apis-arkts/js-apis-hashmap.md)实现，只处理value对象，底层数据结构与HashMap一致。

HashSet和[TreeSet](../reference/apis-arkts/js-apis-treeset.md)相比，HashSet中的数据无序存放，不支持用户指定排序方式，而TreeSet中的数据有序存放，支持用户通过排序函数对元素进行排序。它们集合中的元素都不允许重复，HashSet允许放入null值，但TreeSet不建议存放null值，可能会对排序结果产生影响。

可以利用HashSet的不重复特性，在需要去重或确保集合元素唯一性时使用。

HashSet支持增、删、改、查操作，常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(value: T) | 增加一个值。 |
| 访问元素 | values() | 返回一个迭代器对象，包含set中的所有value。 |
| 访问元素 | entries() | 返回一个迭代器对象，包含类似键值对的数组，键值都是value。 |
| 访问元素 | forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object) | 遍历访问整个set的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object) | 通过遍历修改整个set的元素。 |
| 删除元素 | remove(value: T) | 删除指定的元素。 |
| 删除元素 | clear() | 清空整个set。 |

## TreeMap

[TreeMap](../reference/apis-arkts/js-apis-treemap.md)用于存储具有关联关系的key-value键值对集合，存储元素中key是唯一的，每个key对应一个value值。

TreeMap的key按照泛型定义有序存储，基于红黑树实现，支持快速插入和删除，key的类型需满足ECMA标准。

TreeMap和[HashMap](../reference/apis-arkts/js-apis-hashmap.md)相比，HashMap依据键的hashCode存取数据，访问速度较快。而TreeMap是有序存取，效率较低。

一般需要存储有序键值对的场景，可以使用TreeMap。

TreeMap支持增、删、改、查操作，常用 API 如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | set(key: K, value: V) | 增加一个键值对。 |
| 访问元素 | get(key: K) | 获取key对应的value值。 |
| 访问元素 | getFirstKey() | 获取map中排在首位的key值。 |
| 访问元素 | getLastKey() | 获取map中排在末位的key值。 |
| 访问元素 | keys() | 返回一个迭代器对象，包含map中的所有key值。 |
| 访问元素 | values() | 返回一个迭代器对象，包含map中的所有value值。 |
| 访问元素 | entries() | 返回一个迭代器对象，包含map中的所有键值对。 |
| 访问元素 | forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object) | 遍历访问整个map的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;[K,V]&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | replace(key: K, newValue: V) | 修改指定key对应的value值。 |
| 修改元素 | forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object) | 通过遍历修改整个map的元素。 |
| 删除元素 | remove(key: K) | 删除map中匹配到的键值对。 |
| 删除元素 | clear() | 清空整个map。 |

## TreeSet

[TreeSet](../reference/apis-arkts/js-apis-treeset.md)可用来存储一系列值的集合，存储元素中value是唯一的。

TreeSet根据泛型定义有序存储值，底层实现基于红黑树，支持快速插入和删除。value的类型符合ECMA标准。

TreeSet基于[TreeMap](../reference/apis-arkts/js-apis-treemap.md)实现，仅处理value对象，用于存储值的集合，元素中value唯一，并支持按用户定义的排序函数排序。用于存储值的集合，元素中value唯一，并支持按用户定义的排序函数排序。

TreeSet和[HashSet](../reference/apis-arkts/js-apis-hashset.md)相比，HashSet无序存放数据，TreeSet有序存放数据。两者元素均不允许重复，HashSet允许null值，但TreeSet不建议存放null值，可能影响排序。

在需要存储有序集合的场景中，可以使用TreeSet。

TreeSet支持增、删、改、查操作，常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(value: T) | 增加一个值。 |
| 访问元素 | values() | 返回一个迭代器对象，包含set中的所有value值。 |
| 访问元素 | entries() | 返回一个迭代器对象，包含类似键值对的数组，键值都是value。 |
| 访问元素 | getFirstValue() | 获取set中排在首位的value值。 |
| 访问元素 | getLastValue() | 获取set中排在末位的value值。 |
| 访问元素 | forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object) | 遍历访问整个set的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object) | 通过遍历修改整个set的元素。 |
| 删除元素 | remove(value: T) | 删除指定的元素。 |
| 删除元素 | clear() | 清空整个set。 |

## LightWeightMap

[LightWeightMap](../reference/apis-arkts/js-apis-lightweightmap.md)用于存储具有唯一键的键值对集合，存储元素中key是唯一的，每个key会对应一个value值。LightWeightMap依据泛型定义，采用轻量级结构，底层通过hash实现唯一key，冲突策略为线性探测。集合中的key值的查找依赖于hash值以及二分查找算法，通过一个数组存储hash值，然后映射到其他数组中的key值以及value值，key的类型满足ECMA标准。

初始默认容量为8，每次扩容为原容量的2倍。

LightWeightMap和[HashMap](../reference/apis-arkts/js-apis-hashmap.md)都是用来存储具有关联关系的key-value键值对集合，但LightWeightMap占用内存更小。

当需要存储具有关联关系的key-value键值对集合时，推荐使用占用内存更小的LightWeightMap。

LightWeightMap支持增、删、改、查操作，常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | set(key: K, value: V) | 增加一个键值对。 |
| 访问元素 | get(key: K) | 获取key对应的value值。 |
| 访问元素 | getIndexOfKey(key: K) | 获取map中指定key的index。 |
| 访问元素 | getIndexOfValue(value: V) | 获取map中指定value出现的第一个的index。 |
| 访问元素 | keys() | 返回一个迭代器对象，包含map中的所有key值。 |
| 访问元素 | values() | 返回一个迭代器对象，包含map中的所有value值。 |
| 访问元素 | entries() | 返回一个迭代器对象，包含map中的所有键值对。 |
| 访问元素 | getKeyAt(index: number) | 获取指定index对应的key值。 |
| 访问元素 | getValueAt(index: number) | 获取指定index对应的value值。 |
| 访问元素 | forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object) | 遍历访问整个map的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;[K,V]&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | setValueAt(index: number, newValue: V) | 修改指定index对应的value值。 |
| 修改元素 | forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap<K, V>) => void, thisArg?: Object) | 通过遍历修改整个map的元素。 |
| 删除元素 | remove(key: K) | 删除map中指定key匹配到的键值对。 |
| 删除元素 | removeAt(index: number) | 删除map中指定index对应的键值对。 |
| 删除元素 | clear() | 清空整个map。 |

## LightWeightSet

[LightWeightSet](../reference/apis-arkts/js-apis-lightweightset.md)可用来存储一系列值的集合，存储元素中value是唯一的。

LightWeightSet依据泛型定义，采用更加轻量级的结构，初始默认容量为8，每次扩容为原始容量的2倍。集合中的value值的查找依赖于hash值以及二分查找算法，通过一个数组存储hash值，然后映射到其他数组中的value值，value的类型满足ECMA标准。

LightWeightSet底层通过hash表结构实现value的唯一性，冲突策略采用线性探测法，查找策略基于二分查找法。

LightWeightSet和[HashSet](../reference/apis-arkts/js-apis-hashset.md)都是用来存储键值的集合，但LightWeightSet的占用内存更小。

当需要存取某个集合或是对某个集合去重时，推荐使用占用内存更小的LightWeightSet。

LightWeightSet支持增、删、改、查操作。常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(obj: T) | 增加一个值。 |
| 访问元素 | getIndexOf(key: T) | 获取对应的index值。 |
| 访问元素 | getValueAt(index: number) | 获取指定index对应的value值。 |
| 访问元素 | values() | 返回一个迭代器对象，包含set中的所有value值。 |
| 访问元素 | entries() | 返回一个迭代器对象，包含类似键值对的数组，键值都是value。 |
| 访问元素 | forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object) | 遍历访问整个set的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;T&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object) | 通过遍历修改整个set的元素。 |
| 删除元素 | remove(key: K) | 删除指定的元素。 |
| 删除元素 | removeAt(index: number) | 删除set中指定index对应的值。 |
| 删除元素 | clear() | 清空整个set。 |

## PlainArray

[PlainArray](../reference/apis-arkts/js-apis-plainarray.md)可用来存储具有关联关系的键值对集合，存储元素中key是唯一的，并且对于PlainArray来说，其key的类型为number类型。每个key会对应一个value值，类型依据泛型的定义，PlainArray采用轻量级的结构，集合中的key值的查找依赖于二分查找算法，然后映射到其他数组中的value值。

初始默认容量为16，每次扩容为原始容量的2倍。

PlainArray和[LightWeightMap](../reference/apis-arkts/js-apis-lightweightmap.md)都用于存储键值对，且采用轻量级结构。不过，PlainArray的键值类型仅限于number。

当需要存储键为number类型的键值对时，可以使用PlainArray。

PlainArray支持增、删、改、查操作。常用API如下：

| 操作 | 方法 | 描述 |
| --------- | ------- | ------- |
| 增加元素 | add(key: number,value: T) | 增加一个键值对。 |
| 访问元素 | get(key: number) | 获取key对应的value值。 |
| 访问元素 | getIndexOfKey(key: number) | 获取PlainArray中指定key的index。 |
| 访问元素 | getIndexOfValue(value: T) | 获取PlainArray中指定value出现的第一个的index。 |
| 访问元素 | getKeyAt(index: number) | 获取指定index对应的key值。 |
| 访问元素 | getValueAt(index: number) | 获取指定index对应的value值。 |
| 访问元素 | forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object) | 遍历访问整个PlainArray的元素。 |
| 访问元素 | \[Symbol.iterator]():IterableIterator&lt;[number, T]&gt; | 创建迭代器以进行数据访问。 |
| 修改元素 | setValueAt(index:number, value: T) | 修改指定index对应的value值。 |
| 修改元素 | forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object) | 通过遍历修改整个PlainArray的元素。 |
| 删除元素 | remove(key: number) | 删除PlainArray中指定key匹配到的键值对。 |
| 删除元素 | removeAt(index: number) | 删除PlainArray中指定index对应的键值对。 |
| 删除元素 | removeRangeFrom(index: number, size: number) | 删除PlainArray中指定范围内的元素。 |
| 删除元素 | clear() | 清空整个PlainArray。 |

## 非线性容器的使用

此处列举常用的非线性容器HashMap、TreeMap、LightWeightMap、PlainArray的使用示例，包括导入模块、增加元素、访问元素及修改等操作，示例代码如下所示：


```ts
// HashMap
import { HashMap } from '@kit.ArkTS'; // 导入HashMap模块

let hashMap1: HashMap<string, number> = new HashMap();
hashMap1.set('a', 123); // 增加一个键为'a'，值为123的元素
let hashMap2: HashMap<number, number> = new HashMap();
hashMap2.set(4, 123); // 增加一个键为4，值为123的元素
console.info(`result: ${hashMap2.hasKey(4)}`); // 判断是否含有键为4的元素。输出：result: true
console.info(`result: ${hashMap1.get('a')}`); // 访问键为'a'的元素。输出：result: 123

// TreeMap
import { TreeMap } from '@kit.ArkTS'; // 导入TreeMap模块

let treeMap: TreeMap<string, number> = new TreeMap();
treeMap.set('a', 123); // 增加一个键为'a'，值为123的元素
treeMap.set('6', 356); // 增加一个键为'6'，值为356的元素
console.info(`result: ${treeMap.get('a')}`); // 访问键为'a'的元素。输出：result: 123
console.info(`result: ${treeMap.getFirstKey()}`); // 访问首元素。输出：result: 6
console.info(`result: ${treeMap.getLastKey()}`); // 访问尾元素。输出：result: a

// LightWeightMap
import { LightWeightMap } from '@kit.ArkTS'; // 导入LightWeightMap模块

let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();
lightWeightMap.set('x', 123); // 增加一个键为'x'，值为123的元素
lightWeightMap.set('8', 356); // 增加一个键为'8'，值为356的元素
console.info(`result: ${lightWeightMap.get('a')}`); // 访问键为'a'的元素。输出：result: undefined
console.info(`result: ${lightWeightMap.get('x')}`); // 访问键为'x'的元素，获取其值。输出：result: 123
console.info(`result: ${lightWeightMap.getIndexOfKey('8')}`); // 访问键为'8'的元素，获取其索引。输出：result: 0

// PlainArray
import { PlainArray } from '@kit.ArkTS'; // 导入PlainArray模块

let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, 'sdd'); // 增加一个键为1，值为'sdd'的元素
plainArray.add(2, 'sff'); // 增加一个键为2，值为'sff'的元素
console.info(`result: ${plainArray.get(1)}`); // 访问键为1的元素，获取值。输出：result: sdd
console.info(`result: ${plainArray.getKeyAt(1)}`); // 访问索引为1的元素，获取键。输出：result: 2
```
