# 非线性容器LightWeightSet  

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import LightWeightSet from '@ohos.util.LightWeightSet'  
```


## 权限

无

## LightWeightSet


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | LightWeightSet的元素个数 |


### constructor

constructor();

LightWeightSet的构造函数。

- 示例：
  ```
  let lightWeightSet = new LightWeightSet();
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
  const lightWeightSet = new LightWeightSet();
  lightWeightSet.isEmpty();
  ```

### add

add(value: T): boolean;

向此容器中添加数据。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 添加的成员数据 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否成功添加元素 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  ```


### addAll

addAll(set: LightWeightSet&lt;T&gt;): boolean;

将另一个容器中的所有元素组添加到当前容器中。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | set | LightWeightSet&lt;T&gt; | 是 | 提供添加元素的lightweightmap |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  let set = new LightWeightSet();
  set.add("sfage");
  lightWeightSet.addAll(set);
  ```


### hasAll

hasAll(set: LightWeightSet&lt;T&gt;): boolean;

判断此容器中是否含有该指定set中的所有元素。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | set | LightWeightSet&lt;T&gt; | 是 | 比较对象 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否包含所有元素 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  let set = new LightWeightSet();
  set.add("sdfs");
  let result = lightWeightSet.hasAll(set);
  ```


### has

has(value: T): boolean;

判断此容器中是否含有该指定value。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 指定元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否包含指定元素 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.has(123);
  lightWeightSet.add(123);
  lightWeightSet.has(123);
  ```


### equal

equal(obj: Object): boolean;

判断此容器中是否含有该指定obj同类型。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | obj | Object | 是 | 比较对象 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否构成类型相同 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  let obj = {"Ahfbrgrbgnutfodgorrogorgrogofdfdf", "sdfs"};
  let result = lightWeightSet.equal(obj);
  ```


### ensureCapacityTo

ensureCapacityTo(minimumCapacity: number): void;

将当前容器扩容至可以容纳指定数量元素。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | minimumCapacity | number | 是 | 需要容纳数量 |


- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.ensureCapacityTo(10);
  ```


### getIndexOf

getIndexOf(key: T): number;

获取指定key所对应的下标。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | T | 是 | 查找的指定key |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 在lightweightset中指定数据的下标 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  lightWeightSet.getIndexOf("sdfs");
  ```


### remove

remove(key: T): T;

删除指定的元素。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | key | T | 是 | 依据key指定删除的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回删除元素的值 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  lightWeightSet.remove("sdfs");
  ```


### removeAt

removeAt(index: number): boolean;

删除指定下标的元素。

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
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  lightWeightSet.removeAt(1);
  ```


### getValueAt

getValueAt(index: number): T;

获取此容器中具体位置的元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 指定查询数据下标 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回指定位置中元素 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  lightWeightSet.getValueAt(1);
  ```


### clear

clear(): void;

清除容器中的所有元素,并把length置为0。

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  lightWeightSet.clear();
  ```


### toString

toString(): String;

获取包含容器中所有键和值的字符串。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | String | 返回一个字符串 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  lightWeightSet.toString();
  ```


### toArray

toArray(): Array&lt;T&gt;;

获取包含此容器中所有对象的数组。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Array&lt;T&gt; | 返回一个数组 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  lightWeightSet.toString();
  ```


### values

values(): IterableIterator&lt;T&gt;;

返回包含此映射中包含的键的新迭代器对象。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;T&gt; | 返回一个迭代器 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  let iter = lightWeightSet.values();
  let index = 0;
  while(index < lightWeightSet.length) {
    console.log(JSON.stringify(iter.next().value));
    index++;
  }
  ```


### forEach

forEach(callbackfn: (value: T, key?: T, lightWeightSet?: LightWeightSet&lt;T&gt;) => void, thisArg?: Object): void;

通过回调函数来遍历LightWeightSet实例对象上的元素以及元素对应的下标。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 回调函数 |
  | thisArg | Object | 否 | callbackfn被调用时用作this值 |

- callbackfn的参数说明
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前遍历到的元素 |
  | key | T | 否 | 当前遍历到的元素（和value相同） |
  | lightWeightSet | LightWeightSet&lt;T&gt; | 否 | 当前调用forEach方法的实例对象 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("sdfs");
  lightWeightSet.add("dfsghsf");
  lightWeightSet.forEach((value, key) => {
    console.log(value, key);
  });
  ```


### entries

entries(): IterableIterator<[T, T]>;

返回包含此映射中包含的键的新迭代器对象。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator<[T, T]> | 返回一个迭代器 |

- 示例:
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  let iter = lightWeightSet.entries();
  let index = 0;
  while(index < lightWeightSet.length) {
    console.log(JSON.stringify(iter.next().value));
    index++;
  }
  ```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;;

返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | IterableIterator&lt;T&gt; | 返回一个迭代器 |

- 示例：
  ```
  let lightWeightSet = new LightWeightSet();
  lightWeightSet.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  lightWeightSet.add("sdfs");
  
  // 使用方法一：
  for (let item of lightWeightSet) { 
    console.log("value: " + item);
  }

  // 使用方法二：
  let iter = lightWeightSet[Symbol.iterator]();
  let temp = iter.next().value;
  while(temp != undefined) {
    console.log(temp);
    temp = iter.next().value;
  }
  ```