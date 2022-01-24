# 线性容器Stack

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import Stack from '@ohos.stack'  
```


## 权限

无


## Stack


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | 获取Stack&nbsp;的元素个数 |


### constructor

constructor()

constructor是Stack的构造函数。

- 参数：
  | 参数名 | 类型 | 可读 | 可写 | 说明 |
  | -------- | -------- | -------- | -------- | -------- |
  | 无 | 无 | 是 | 否 | 无 |

- 示例：
  ```
  let stack = new Stack();
  ```


### push

push(item: T): T

在栈顶插入元素,并返回该元素

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 添加进去的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回被添加进去的元素 |

- 示例:
  ```
  const stack = new Stack();
  stack.push("a");
  stack.push(1);
  let b = [1,2,3];
  stack.push(b);
  let c = {name:"lala",age:"13"};
  stack.push(false)
  ```

### pop

pop(): T

删除栈顶元素并返回该删除元素

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回删除的元素 |

- 示例:
  ```
  const stack = new Stack();
  stack.push(2);
  stack.push(4);
  stack.push(5);
  stack.push(2);
  stack.push(4);
  stack.pop();

  ```

### peek

peek(): T

获取并返回栈顶元素

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回栈顶元素 |

- 示例:
  ```
  const stack = new Stack();
  stack.push(2);
  stack.push(4);
  stack.push(5);
  stack.push(2);
  stack.peek();

  ```
### locate

locate(element: T): number 

获取指定元素第一次出现的下标,找到就返回下标值,没有找到就返回-1

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | element | T | 是 | 查找的元素 |

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | number | 找到就返回下标值,没有找到返回-1 |
- 示例:
  ```
  const stack = new Stack();
  stack.push(2);
  stack.push(4);
  stack.push(5);
  stack.push(2);
  stack.locate(2);

  ```

### forEach
forEach(callbackfn: (value: T, index?: number, stack?: Stack<T>) => void,
thisArg?: Object): void 

通过回调函数来遍历Stack实例对象上的元素以及元素对应的下标

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
  | stack | Stack<T> | 否 | 当前调用forEach方法的实例对象。 |


- 示例:
  ```
  const stack = new Stack();
  stack.push(2);
  stack.push(4);
  stack.push(5);
  stack.push(4);
  stack.forEach((value,index)=>{
   console.log(value,index)
  });

  ```
### isEmpty
isEmpty(): boolean 

判断该栈是否为空

- 返回值：
  | 类型 | 说明 |
  | -------- | -------- |
  | boolean | 为空返回true, 不为空返回false |

- 示例:
  ```
  const stack = new Stack();
  stack.push(2);
  stack.push(4);
  stack.push(5);
  stack.push(4);
  stack.isEmpty();

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
  const stack = new Stack();
  stack.push(2);
  stack.push(4);
  stack.push(5);
  stack.push(4);
  for (let item of stack) { 
    console.log(item); 
  }
  
  ```