# 线性容器LinkedList

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import LinkedList from '@ohos.linkedlist'  
```


## 权限

无


## LinkedList


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | 获取LinkedList&nbsp;的元素个数 |


### constructor

constructor(_head?: NodeObj<T>, _tail?: NodeObj<T>) 

constructor是LinkedList的构造函数。

- 参数：
  | 参数名 | 类型 | 可读 | 可写 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | _head | NodeObj<T> | 是 | 否 | 入参对象,节点对象,含有element,和next指向,和prev指向 |
  | _tail | NodeObj<T> | 是 | 否 | 入参对象,节点对象,含有element,和next指向,和prev指向 |

- 示例：
  ```
  let linkedlist = new LinkedList();
  ```


### add

add(element: T): boolean

在LinkedList尾部插入元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 添加进去的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 插入成功返回true,失败返回false |

- 示例:
  ```
  const linkedlist = new LinkedList;
  linkedlist.add("a");
  linkedlist.add(1);
  let b = [1,2,3];
  linkedlist.add(b);
  let c = {name:"lala",age:"13"};
  linkedlist.add(false)
  ```
### addFirst

addFirst(element: T): void

在LinkedList头部插入元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 添加进去的元素 |

- 示例:
  ```
  const linkedlist = new LinkedList;
  linkedlist.addFirst("a");
  linkedlist.addFirst(1);
  let b = [1,2,3];
  linkedlist.addFirst(b);
  let c = {name:"lala",age:"13"};
  linkedlist.addFirst(false)
  ```

### insert

insert(element: T, index: number): void

在长度范围内任意插入指定元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 被插入的元素 |
  | index | number | 是 | 被插入的元素 |

- 示例:
  ```
  let linkedlist = new LinkedList
  linkedlist.insert("A",0);
  linkedlist.insert(0,1);
  linkedlist.insert(true,2);

  ```

### has

has(element: T): boolean

判断此LinkedList中是否含有该指定元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 是否包含的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 是否包含指定元素 |

- 示例:
  ```
  const linkedlist = new LinkedList()
  linkedlist.has("Ahfbrgrbgnutfodgorrogorg");
  linkedlist.add("Ahfbrgrbgnutfodgorrogorg");
  linkedlist.has("Ahfbrgrbgnutfodgorrogorg");

  ```

### get

get(index: number): T  

根据下标获取LinkedList中的元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 要查找的下标 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 根据下标查找到的元素 |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(2);
  linkedlist.add(1);
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.get(2);

  ```
### getLastIndexOf

getLastIndexOf(element: T): number

查找指定元素最后一次出现的下标值,如果没有找到该元素返回-1

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 被查找的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回最后一次找到指定元素的下标,没有找到返回-1 |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(2);
  linkedlist.add(1);
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.getLastIndexOf(2);

  ```

### getIndexOf

getIndexOf(element: T): number

查找指定元素第一次出现的下标值,如果没有找到该元素返回-1

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 被查找的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回第一次找到指定元素的下标,没有找到返回-1 |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(2);
  linkedlist.add(1);
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.getIndexOf(2);

  ```
### removeByIndex

removeByIndex(index: number): T

根据下标删除元素并返回该删除元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 删除元素的下标 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回删除的元素 |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.removeByIndex(2);

  ```
### removeFirst

removeFirst(): T

删除并返回LinkedList的首元素

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回删除的元素 |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.removeFirst();

  ```
### removeLast

removeLst(): T

删除并返回LinkedList的尾元素

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回删除的元素 |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.removeLast();

  ```

### remove

remove(element: T): boolean

删除查找到的第一个指定的元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 指定删除的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 删除成功返回true,失败返回false |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  linkedlist.remove(2);

  ```
### removeFirstFound

removeFirstFound(element: T): boolean

删除第一次出现的指定元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 指定删除的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 删除成功返回true,失败返回false |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  linkedlist.removeFirstFound(4);

  ```
### removeLastFound

removeLastFound(element: T): boolean

删除最后一次出现的指定元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 指定删除的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 删除成功返回true,失败返回false |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  linkedlist.removeLastFound(4);

  ```
### clone
clone(): LinkedList<T> 

克隆一个与LinkedList一模一样的实例,并返回克隆后的实例,修改克隆后的实例并不会影响原实例

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | LinkedList<T> | 返回LinkedList对象实例 |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  linkedlist.clone();
 
  ```
### forEach
forEach(callbackfn: (value: T, index?: number, linkedlist?: LinkedList<T>) => void,
thisArg?: Object): void 

通过回调函数来遍历LinkedList实例对象上的元素以及元素对应的下标

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callbackfn | function | 是 | 回调函数。 |
  | thisArg | Object | 否 | callbackfn被调用时用作this值 |

- callbackfn的参数说明
  
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | value | T | 是 | 当前遍历到的元素。 |
  | index | number | 否 | 当前遍历到的下标值。 |
  | linkedlist | LinkedList<T> | 否 | 当前调用forEach方法的实例对象。 |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  linkedlist.forEach((value,index)=>{
    console.log(value,index)
  });

  ```
### clear
clear(): void

清除LinkedList中的所有元素,并把length置为0

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  linkedlist.clear();
 
  ```
### set
set(index: number, element: T): T
将此 LinkedList 中指定位置的元素替换为指定元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 查找的下标 |
  | element | T | 是 | 用来替换的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回T类型 |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  linkedlist.set(2,"b");
 
  ```
### convertToArray
convertToArray(): Array<T>

把当前LinkedList实例转换成数组,并返回转换后的数组

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Array<T> | 返回数组类型 |

- 示例:
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  linkedlist.convertToArray();

  ```

### getFirst

getFirst(): T
获取LinkedList实例中的第一个元素

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回T型 |


- 示例：
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  linkedlist.getFirst();
  ```
### getLast

getLast(): T 
获取LinkedList实例中的最后一个元素

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回T型 |


- 示例：
  ```
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  linkedlist.getLast();
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
  const linkedlist = new LinkedList();
  linkedlist.add(2);
  linkedlist.add(4);
  linkedlist.add(5);
  linkedlist.add(4);
  for (let item of linkedlist) { 
    console.log(item); 
  } 
  ```