# 非线性容器HashSet

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import hashset from '@ohos.hashset'  
```


## 权限

无

## HashSet


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | HashSet&nbsp;的元素个数 |


### constructor

constructor()

constructor是HashSet的构造函数。

- 参数：
  | 参数名 | 类型 | 可读 | 可写 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | 无 | 无 | 是 | 否 | 无 |

- 示例：
  ```
  let hashset = new HashSet();
  ```


### isEmpty

isEmpty(): boolean 

判断该HashSet是否为空

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 为空返回true, 不为空返回false |

- 示例:
  ```
  const hashset = new HashSet();
  hashset.isEmpty();
  ```


### has

has(value: T): boolean

判断此HashSett中是否含有该指定key

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 是否包含的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否包含指定元素 |

- 示例:
  ```
  let hashset = new HashSet();
  hashset.has("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  hashset.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  hashset.has("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  ```


### add

add(value: T): boolean;

向HashSet中添加数据

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 添加成员数据。 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 返回是否有成功增加元素 |

- 示例:
  ```
  let hashset = new HashSet();
  hashset.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  ```


### remove

remove(value: T): boolean;

删除指定的元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 指定删除的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 返回是否成功删除指定元素 |

- 示例:
  ```
  let hashset = new HashSet();
  hashset.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  hashset.add("sdfs");
  hashset.remove("sdfs");
  ```


### clear

clear(): void

清除HashSet中的所有元素,并把length置为0

- 示例:
  ```
  let hashset = new HashSet();
  hashset.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  hashset.add("sdfs");
  hashset.clear();
  ```


### values

values(): IterableIterator<T>

返回包含此映射中包含的键的新迭代器对象

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;[T,&nbsp;boolean]&gt; | 返回一个迭代器。 |

- 示例:
  ```
  let hashset = new HashSet();
  hashset.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  hashset.add("sdfs");
  let itor = hashset.values();
  while(itor.next() != undefined) {
    let temp = itor.next();
    console.log(temp);
  } 
  ```


### forEach

forEach(callbackfn: (value: T, key?: T, hashset?: HashSet<T>) => void, thisArg?: Object): void 

通过回调函数来遍历实例对象上的元素以及元素对应的下标

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 回调函数。 |
  | thisArg | Object | 否 | callbackfn被调用时用作this值 |

- callbackfn的参数说明
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前遍历到的元素键值对的值。 |
  | key | T | 否 | 当前遍历到的元素键值对的值（和value相同）。 |
  | hashset | HashSet<T> | 否 | 当前调用forEach方法的实例对象。 |


- 示例:
  ```
  let hashset = new HashSet();
  hashset.add("sdfs");
  hashset.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  hashset.forEach((value, key)=>{
    console.log(value, key)
  });
  ```


### entries
entries(): IterableIterator<[T, T]>

返回包含此映射中包含的键的新迭代器对象

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;[[T, T],&nbsp;boolean]&gt; | 返回一个迭代器。 |

- 示例:
  ```
  let hashset = new HashSet();
  hashset.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  hashset.add("sdfs");
  let itor = hashset.entries();
  while(itor.next() != undefined) {
    let temp = itor.next();
    console.log(temp.key);
    console.log(temp.value);
  }
  ```


### [Symbol.iterator]

[Symbol.iterator](): IterableIterator<T>

返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;[T,&nbsp;boolean]&gt; | 返回一个迭代器。 |

- 示例：
  ```
  let hashset = new HashSet();
  hashset.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  hashset.add("sdfs");
  for (let item of hashset) { 
    console.log("value: " + item);
  } 
  ```