# 线性容器ArrayList

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import ArrayList from '@ohos.arraylist'  
```


## 权限

无


## ArrayList


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | 获取ArrayList&nbsp;的元素个数 |


### constructor

constructor()

constructor是ArrayList的构造函数。

- 参数：
  | 参数名 | 类型 | 可读 | 可写 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | 无 | 无 | 是 | 否 | 无 |

- 示例：
  ```
  let arraylist = new ArrayList();
  ```


### add

add(element: T): boolean

在ArrayList尾部插入元素

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
  const arraylist = new ArrayList();
  arraylist.add("a");
  arraylist.add(1);
  let b = [1,2,3];
  arraylist.add(b);
  let c = {name:"lala",age:"13"};
  arraylist.add(false)
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
  let arraylist = new ArrayList()
  arraylist.insert("A",0);
  arraylist.insert(0,1);
  arraylist.insert(true,2);

  ```

### has

has(element: T): boolean

判断此ArrayList中是否含有该指定元素

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
  const arraylist = new ArrayList()
  arraylist.has("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  arraylist.add("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
  arraylist.has("Ahfbrgrbgnutfodgorrogorgrogofdfdf");

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
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(2);
  arraylist.add(1);
  arraylist.add(2);
  arraylist.add(4);
  arraylist.getIndexOf(2);

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
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(2);
  arraylist.add(1);
  arraylist.add(2);
  arraylist.add(4);
  arraylist.getLastIndexOf(2);

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
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(2);
  arraylist.add(4);
  arraylist.removeByIndex(2);

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
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.remove(2);

  ```
### removeByRange
removeByRange(fromIndex: number, toIndex: number): void

从一段范围删除元素,包前不包后.

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fromIndex | number | 是 | 起始下标 |
  | toIndex | number | 是 | 终止下标 |

- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.removeByRange(2,4);
  arraylist.removeByRange(4,3);
  arraylist.removeByRange(2,6);

  ```
### replaceAllElements
replaceAllElements(callbackfn: (value: T, index?: number, arraylist?: ArrayList<T>) => T,
thisArg?: Object): void

用户操作ArrayList中的元素,用操作后的元素替换原元素并返回操作后的元素

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
  | arraylist | ArrayList<T> | 否 | 当前调用replaceAllElements方法的实例对象。 |

- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.replaceAllElements((value,index)=>{
    return value = 2*value;
  });
  arraylist.replaceAllElements((value,index)=>{
    return value = value - 2;
  });

  ```
### forEach
forEach(callbackfn: (value: T, index?: number, arraylist?: ArrayList<T>) => void,
thisArg?: Object): void 

通过回调函数来遍历ArrayList实例对象上的元素以及元素对应的下标

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
  | arraylist | ArrayList<T> | 否 | 当前调用forEach方法的实例对象。 |


- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.forEach((value,index)=>{
    console.log(value,index)
  });

  ```
### sort
sort(comparator?: (firstValue: T, secondValue: T) => number): void
 
对ArrayList中的元素进行一个排序操作

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | comparator | function | 否 | 回调函数。 |

- comparator的参数说明
  
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | firstValue | T | 是 | 前一项元素 |
  | secondValue | T | 是 | 后一项元素 |
 

- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.sort(a,b=>a-b);
  arraylist.sort(a,b=>b-a);
  arraylist.sort()

  ```
### subArrayList
subArrayList(fromIndex: number, toIndex: number): ArrayList<T>

根据下标截取ArrayList中的一段元素,并返回这一段ArrayList实例,包前不包后
- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | fromIndex | number | 是 | 起始下标 |
  | toIndex | number | 是 | 终止下标 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | ArrayList<T> | 返回ArrayList对象实例 |

- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.subArrayList(2,4);
  arraylist.subArrayList(4,3);
  arraylist.subArrayList(2,6);
 
  ```

### clear
clear(): void

清除ArrayList中的所有元素,并把length置为0

- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.clear();
 
  ```
### clone
clone(): ArrayList<T> 

克隆一个与ArrayList一模一样的实例,并返回克隆后的实例,修改克隆后的实例并不会影响原实例

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | ArrayList<T> | 返回ArrayList对象实例 |

- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.clone();
 
  ```
### getCapacity
getCapacity(): number

获取当前实例的容量大小

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 返回arraylist的容量大小 |

- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.getCapacity();

  ```
### convertToArray
convertToArray(): Array<T>

把当前ArrayList实例转换成数组,并返回转换后的数组

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | Array<T> | 返回数组类型 |

- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.convertToArray();

  ```
### isEmpty
isEmpty(): boolean 

判断该ArrayList是否为空

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 为空返回true, 不为空返回false |

- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.isEmpty();

  ```
### increaseCapacityTo
increaseCapacityTo(newCapacity: number): void

如果该新容量大于活等于length,把容量改变为一个传入的新容量

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | newCapacity | number | 是 | 新容量 |


- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.increaseCapacityTo(2);
  arraylist.increaseCapacityTo(8);

  ```
### trimToCurrentLength
trimToCurrentLength(): void

把容量限制为当前的length大小

- 示例:
  ```
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  arraylist.trimToCurrentLength(2);

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
  const arraylist = new ArrayList();
  arraylist.add(2);
  arraylist.add(4);
  arraylist.add(5);
  arraylist.add(4);
  for (let item of arraylist) { 
    console.log(item); 
  } 
  ```