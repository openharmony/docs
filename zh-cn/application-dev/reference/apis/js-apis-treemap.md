# 非线性容器TreeMap  

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import {TreeMap} from '@ohos.util.TreeMap'  
```


## 权限

无

## TreeMap


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | TreeMap的元素个数 |


### constructor

constructor(comparator?:(firstValue: K, secondValue: K) => boolean);

TreeMap的构造函数。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | comparator | function | 否 | 用户自定义的比较函数 |

- 示例：
  ```
  let treeMap = new TreeMap();
  ```


### isEmpty

isEmpty(): boolean;

判断该容器是否为空。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 为空返回true, 不为空返回false |

- 示例:
  ```
  const treeMap = new TreeMap();
  treeMap.isEmpty();
  ```


### hasKey

hasKey(key: K): boolean;

判断此容器中是否含有该指定key。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 指定元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否包含指定元素 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  ```


### hasValue

hasValue(value: V): boolean;

判断此容器中是否含有该指定value。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | V | 是 | 指定元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否包含指定元素 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.hasValue(123);
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.hasValue(123);
  ```


### get

get(key: K): V;

获取指定key所对应的value。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 查找的指定key |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | V | 返回key映射的value值 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  treeMap.get("sdfs");
  ```


### getFirstKey

getFirstKey(): K;

获取容器中排序第一的数据。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | K | 返回排序第一的数据 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  let result = treeMap.getFirstKey();
  ```


### getLastKey

getLastKey(): K;

获取容器中排序最后的数据。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | K | 返回排序最后的数据 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  let result = treeMap.getLastKey();
  ```


### setAll

setAll(map: TreeMap<K, V>): void;

将一个treemap中的所有元素组添加到另一个treemap中。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | map | TreeMap<K, V> | 是 | 被添加元素的treemap |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  let map = new TreeMap();
  treeMap.setAll(map);
  ```


### set
set(key: K, value: V): Object;

向treemap中添加一组数据。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 添加成员数据的键名 |
  | value | V | 是 | 添加成员数据的值 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Object | 返回添加后的hashmap |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  ```


### remove

remove(key: K): V;

删除指定的元素。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 依据key指定删除的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | V | 返回删除元素的值 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  treeMap.remove("sdfs");
  ```


### getLowerByKey

getLowerByKey(key: K): K;

获取容器中比传入key排序靠前一位的key。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 对比的key值 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | K | 返回排序中key前一位的数据 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  treeMap.set("zdfgsd", 356);
  let result = treeMap.getLowerByKey("sdfs");
  ```


### getHigherByKey

getHigherByKey(key: K): K;

获取容器中比传入key排序靠后一位的key。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 对比的key值 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | K | 返回排序中key后一位的数据 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  treeMap.set("zdfgsd", 356);
  let result = treeMap.getHigherByKey("sdfs");
  ```


### replace
replace(key: K, value: V): boolean;

对TreeMap中一组数据进行更新（替换）。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 依据key指定替换的元素 |
  | value | V | 是 | 添加成员数据的值 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否成功对已有数据进行替换 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("sdfs", 123);
  treeMap.replace("sdfs", 357);
  ```


### clear

clear(): void;

清除TreeMap中的所有元素,并把length置为0。

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  treeMap.clear();
  ```


### keys

keys(): IterableIterator&lt;K&gt;;

返回包含此映射中包含的键的新迭代器对象。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;K&gt; | 返回一个迭代器 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  let iter = treeMap.keys();
  let temp = iter.next().value;
  while(temp != undefined) {
    console.log(temp);
    temp = iter.next().value;
  } 
  ```


### values

values(): IterableIterator&lt;V&gt;;

返回包含此映射中包含的键的新迭代器对象。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;V&gt; | 返回一个迭代器 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  let iter = treeMap.values();
  let temp = iter.next().value;
  while(temp != undefined) {
    console.log(temp);
    temp = iter.next().value;
  }
  ```


### forEach

forEach(callbackfn: (value: V, key?: K, treeMap?: TreeMap<K, V>) => void, thisArg?: Object): void;

通过回调函数来遍历实例对象上的元素以及元素对应的下标。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 回调函数 |
  | thisArg | Object | 否 | callbackfn被调用时用作this值 |

- callbackfn的参数说明
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | V | 是 | 当前遍历到的元素键值对的值 |
  | key | K | 是 | 当前遍历到的元素键值对的键 |
  | treeMap | TreeMap<K, V> | 否 | 当前调用forEach方法的实例对象 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("sdfs", 123);
  treeMap.set("dfsghsf", 357);
  treeMap.forEach((value, key) => {
    console.log(value, key);
  });
  ```


### entries

entries(): IterableIterator<[K, V]>;

返回包含此映射中包含的键的新迭代器对象。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator<[K, V]> | 返回一个迭代器 |

- 示例:
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  let iter = treeMap.entries();
  let temp = iter.next().value;
  while(temp != undefined) {
    console.log(temp[0]);
    console.log(temp[1]);
    temp = iter.next().value;
  }
  ```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;;


返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator<[K, V]> | 返回一个迭代器 |

- 示例：
  ```
  let treeMap = new TreeMap();
  treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  treeMap.set("sdfs", 356);
  
  // 使用方法一：
  for (let item of treeMap) { 
    console.log("key: " + item[0]);
    console.log("value: " + item[1]);
  }

  // 使用方法二：
  let iter = treeMap[Symbol.iterator]();
  let temp = iter.next().value;
  while(temp != undefined) {
    console.log(temp[0]);
    console.log(temp[1]);
    temp = iter.next().value;
  }
  ```