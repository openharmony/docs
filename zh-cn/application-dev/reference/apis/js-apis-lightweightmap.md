# 非线性容器LightWeightMap 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import LightWeightMap from '@ohos.lightweightmap'  
```


## 权限

无

## LightWeightMap


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | LightWeightMap&nbsp;的元素个数 |


### constructor

constructor()

constructor是LightWeightMap的构造函数。

- 参数：
  | 参数名 | 类型 | 可读 | 可写 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | 无 | 无 | 是 | 否 | 无 |

- 示例：
  ```
  let lightweightmap = new LightWeightMap();
  ```


### isEmpty

isEmpty(): boolean 

判断该LightWeightMap是否为空

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 为空返回true, 不为空返回false |

- 示例:
  ```
  const lightweightmap = new LightWeightMap();
  lightweightmap.isEmpty();
  ```


### hasAll

hasAll(map: LightWeightMap<K, V>): boolean;

判断此LightWeightMap中是否含有该指定map中的所有元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | map | LightWeightMap<K, V> | 是 | 比较对象 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否包含所有元素 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  let map = new LightWeightMap();
  map.set("sdfs", 356);
  let result = lightweightmap.hasAll(map);
  ```


### hasKey

hasKey(key: K): boolean

判断此LightWeightMap中是否含有该指定key

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 是否包含的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否包含指定元素 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  ```


### hasValue

hasValue(value: V): boolean

判断此LightWeightMap中是否含有该指定value

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | V | 是 | 是否包含的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否包含指定元素 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.hasValue(123);
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.hasValue(123);
  ```


### increaseCapacityTo

increaseCapacityTo(minimumCapacity: number): void

将当前LightWeightMap扩容至可以容纳指定数量元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | minimumCapacity | number | 是 | 需要容纳数量 |


- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.increaseCapacityTo(10);
  ```


### get

get(key: K): V

获取指定key所对应的value

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
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  lightweightmap.get("sdfs");
  ```


### getIndexOfKey

getIndexOfKey(key: K): number

查找指定元素第一次出现的下标值,如果没有找到该元素返回-1

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 被查找的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回第一次找到指定元素的下标,没有找到返回-1 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  lightweightmap.getIndexOfKey("sdfs");
  ```


### getIndexOfValue

getIndexOfValue(value: V): number

查找指定元素第一次出现的下标值,如果没有找到该元素返回-1

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | V | 是 | 被查找的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回第一次找到指定元素的下标,没有找到返回-1 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  lightweightmap.getIndexOfValue(123);
  ```


### getKeyAt

getKeyAt(index: number): K

查找指定下标的元素键值对中key值，否则返回undefined

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 所查找的下标 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | K | 返回该下标对应的元素键值对中key值 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  lightweightmap.getKeyAt(1);
  ```


### setAll

setAll(map: LightWeightMap<K, V>): void

将一个LightWeightMap中的所有元素组添加到另一个lightweightmap中

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | map | LightWeightMap<K, V> | 是 | 被添加元素的lightweightmap |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  let map = new LightWeightMap();
  lightweightmap.setAll(map);
  ```


### set
set(key: K, value: V): Object;

向LightWeightMap中添加一组数据

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 添加成员数据的键名。 |
  | value | V | 是 | 添加成员数据的值。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Object | 返回添加后的hashmap |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  ```


### remove

remove(key: K): V;

删除指定的元素

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
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  lightweightmap.remove("sdfs");
  ```


### removeAt

removeAt(index: number): boolean;

删除指定下标的元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 指定想要删除元素下标 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 确认是否成功删除元素 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  lightweightmap.removeAt(1);
  ```


### setValueAt

setValueAt(index: number, newValue: V): boolean

向LightWeightMap中具体位置替换键值对中的值

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 指定替换数据下标 |
  | newValue | V | 是 | 替换键值对中的值 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否成功替换指定位置数据 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  lightweightmap.setValueAt(1, 3546);
  ```


### getValueAt

getValueAt(index: number): V

获取LightWeightMap中具体位置键值对中的值

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 指定查询数据下标 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | V | 返回指定位置中键值对的值 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  lightweightmap.getValueAt(1);
  ```


### clear

clear(): void

清除LightWeightMap中的所有元素,并把length置为0

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  lightweightmap.clear();
  ```


### keys

keys(): IterableIterator<K>

返回包含此映射中包含的键的新迭代器对象

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;[K,&nbsp;boolean]&gt; | 返回一个迭代器。 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  let itor = lightweightmap.keys();
  while(itor.next() != undefined) {
    let temp = itor.next();
    console.log(temp);
  }
  ```


### values

values(): IterableIterator<V>

返回包含此映射中包含的键的新迭代器对象

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;[V,&nbsp;boolean]&gt; | 返回一个迭代器。 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  let itor = lightweightmap.values();
  while(itor.next() != undefined) {
    let temp = itor.next();
    console.log(temp);
  } 
  ```


### forEach

forEach(callbackfn: (value: V, key?: K, lightweightmap?: LightWeightMap<K, V>) => void, thisArg?: Object): void 

通过回调函数来遍历实例对象上的元素以及元素对应的下标

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 回调函数。 |
  | thisArg | Object | 否 | callbackfn被调用时用作this值 |

- callbackfn的参数说明
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | V | 是 | 当前遍历到的元素键值对的值。 |
  | key | K | 是 | 当前遍历到的元素键值对的键。 |
  | lightweightmap | LightWeightMap<K, V> | 否 | 当前调用forEach方法的实例对象。 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("sdfs", 123);
  lightweightmap.set("dfsghsf", 357);
  lightweightmap.forEach((value, key)=>{
    console.log(value, key)
  });
  ```


### entries

entries(): IterableIterator<[K, V]>

返回包含此映射中包含的键的新迭代器对象

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;[[K, V],&nbsp;boolean]&gt; | 返回一个迭代器。 |

- 示例:
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  let itor = lightweightmap.entries();
  while(itor.next() != undefined) {
    let temp = itor.next();
    console.log(temp.key);
    console.log(temp.value);
  }
  ```


### [Symbol.iterator]

[Symbol.iterator](): IterableIterator<[K, V]>

返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;[[K, V],&nbsp;boolean]&gt; | 返回一个迭代器。 |

- 示例：
  ```
  let lightweightmap = new LightWeightMap();
  lightweightmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  lightweightmap.set("sdfs", 356);
  for (let item of lightweightmap) { 
    console.log("key: " + item.key);
    console.log("value: " + item.value);
  }
  ```