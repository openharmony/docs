# 非线性容器HashMap

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import hashmap from '@ohos.hashmap'  
```


## 权限

无

## HashMap


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | HashMap&nbsp;的元素个数 |


### constructor

constructor()

constructor是HashMap的构造函数。

- 参数：
  | 参数名 | 类型 | 可读 | 可写 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | 无 | 无 | 是 | 否 | 无 |

- 示例：
  ```
  let hashmap = new HashMap();
  ```


### isEmpty

isEmpty(): boolean 

判断该HashMap是否为空

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 为空返回true, 不为空返回false |

- 示例:
  ```
  const hashmap = new HashMap();
  hashmap.isEmpty();
  ```


### hasKey

hasKey(key: K): boolean

判断此HashMap中是否含有该指定key

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
  let hashmap = new HashMap();
  hashmap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  hashmap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  ```


### hasValue

hasValue(value: V): boolean

判断此HashMap中是否含有该指定value

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
  let hashmap = new HashMap();
  hashmap.hasValue(123);
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  hashmap.hasValue(123);
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
  let hashmap = new HashMap();
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  hashmap.set("sdfs", 356);
  hashmap.get("sdfs");
  ```


### setAll

setAll(map: HashMap<K, V>): void

将一个HashMap中的所有元素组添加到另一个hashmap中

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | map | HashMap<K, V> | 是 | 被添加元素的hashmap |

- 示例:
  ```
  let hashmap = new HashMap();
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  hashmap.set("sdfs", 356);
  let newhashmap = new HashMap();
  hashmap.setAll(newhashmap);
  ```


### set

set(key: K, value: V): Object;

向HashMap中添加一组数据

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
  let hashmap = new HashMap();
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
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
  let hashmap = new HashMap();
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  hashmap.set("sdfs", 356);
  hashmap.remove("sdfs");
  ```


### clear

clear(): void

清除HashMap中的所有元素,并把length置为0

- 示例:
  ```
  let hashmap = new HashMap();
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  hashmap.set("sdfs", 356);
  hashmap.clear();
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
  let hashmap = new HashMap();
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  hashmap.set("sdfs", 356);
  let itor = hashmap.keys();
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
  | IterableIterator&lt;[K,&nbsp;boolean]&gt; | 返回一个迭代器。 |

- 示例:
  ```
  let hashmap = new HashMap();
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  hashmap.set("sdfs", 356);
  let itor = hashmap.values();
  while(itor.next() != undefined) {
    let temp = itor.next();
    console.log(temp);
  }
  ```


### replace

replace(key: K, value: V): boolean;

对HashMap中一组数据进行更新（替换）

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | K | 是 | 依据key指定替换的元素。 |
  | value | V | 是 | 添加成员数据的值。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否成功对已有数据进行替换 |

- 示例:
  ```
  let hashmap = new HashMap();
  hashmap.set("sdfs", 123);
  hashmap.replace("sdfs", 357);
  ```


### forEach

forEach(callbackfn: (value: V, key?: K, hashmap?: HashMap<K, V>) => void, thisArg?: Object): void 

通过回调函数来遍历HashMap实例对象上的元素以及元素对应的下标

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
  | hashmap | HashMap<K, V> | 否 | 当前调用forEach方法的实例对象。 |

- 示例:
  ```
  let hashmap = new HashMap();
  hashmap.set("sdfs", 123);
  hashmap.set("dfsghsf", 357);
  hashmap.forEach((value, key)=>{
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
  let hashmap = new HashMap();
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  hashmap.set("sdfs", 356);
  let itor = hashmap.entries();
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
  let hashmap = new HashMap();
  hashmap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
  hashmap.set("sdfs", 356);
  for (let item of hashmap) { 
    console.log("key: " + item.key);
    console.log("value: " + item.value);
  } 
  ```