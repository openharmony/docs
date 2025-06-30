# 声明式UI描述

ArkTS以声明方式组合和扩展组件来描述应用程序的UI，同时还提供了基本的属性、事件和子组件配置方法，帮助开发者实现应用交互逻辑。

## 创建组件

根据组件构造方法的不同，创建组件包含有参数和无参数两种方式。

>  **说明：**
>
>  创建组件不需要使用new关键字。

### 无参数

如果组件接口定义中不包含必选构造参数，则组件后面的“()”不需要配置任何内容。例如：Divider组件不包含构造参数。

```ts
Column() {
  Text('item 1')
  Divider()
  Text('item 2')
}
```

### 有参数

如果组件接口定义包含构造参数，则在组件后的“()”中配置相应参数。

- Image组件的必选参数src。

  ```ts
  Image('https://xyz/test.jpg')
  ```


- Text组件的非必选参数content。

  ```ts
  // string类型的参数
  Text('test')
  // $r形式引入应用资源，可应用于多语言场景
  Text($r('app.string.title_value'))
  // 无参数形式
  Text()
  ```

- 变量或表达式可以用于参数赋值，表达式结果类型必须符合参数要求。
    例如，设置变量或表达式来构造Image和Text组件的参数。

    ```ts
    Image(this.imagePath)
    Image('https://' + this.imageUrl)
    Text(`count: ${this.count}`)
    ```


## 配置属性

属性方法以“.”链式调用配置组件样式和其他属性，建议每个属性方法单独一行。

- 配置Text组件的字体大小。

  ```ts
  Text('test')
    .fontSize(12)
  ```

- 配置组件的多个属性。

  ```ts
  Image('test.jpg')
    .alt('error.jpg')    
    .width(100)    
    .height(100)
  ```

- 除了直接传递常量参数，还可以传递变量或表达式。

  ```ts
  Text('hello')
    .fontSize(this.size)
  Image('test.jpg')
    .width(this.count % 2 === 0 ? 100 : 200)    
    .height(this.offset + 100)
  ```

- 对于系统组件，ArkUI还为其属性预定义了一些枚举类型供开发者调用，枚举类型可以作为参数传递，但必须满足参数类型要求。
  例如，可以按以下方式配置Text组件的颜色和字体样式。

  ```ts
  Text('hello')
    .fontSize(20)
    .fontColor(Color.Red)
    .fontWeight(FontWeight.Bold)
  ```


## 配置事件

事件方法以“.”链式调用的方式配置系统组件支持的事件，建议每个事件方法单独写一行。

- 使用箭头函数配置组件的事件方法。

  ```ts
  Button('Click me')
    .onClick(() => {
      this.myText = 'ArkUI';
    })
  ```

- 使用箭头函数表达式配置组件的事件方法，要求使用“() => {...}”，以确保函数与组件绑定，同时符合ArkTS语法规范。

  ```ts
  Button('add counter')
    .onClick(() => {
      this.counter += 2;
    })
  ```

- 使用组件的成员函数配置组件的事件方法，需要bind this。ArkTS语法不建议使用成员函数配合bind this来配置组件的事件方法。

  ```ts
  myClickHandler(): void {
    this.counter += 2;
  }
  ...
  Button('add counter')
    .onClick(this.myClickHandler.bind(this))
  ```

- 使用声明的箭头函数时可以直接调用，不需要bind this。

  ```ts
  fn = () => {
    console.info(`counter: ${this.counter}`)
    this.counter++
  }
  ...
  Button('add counter')
    .onClick(this.fn)
  ```

> **说明：**
>
> 箭头函数内部的`this`是词法作用域，由上下文确定。匿名函数可能会出现`this`指向不明确的问题，因此在ArkTS中不允许使用。

## 配置子组件

如果组件支持子组件配置，则需在尾随闭包"{...}"中为组件添加子组件的UI描述。Column、Row、Stack、Grid、List等组件都是容器组件。

- 以下是简单的Column组件配置子组件的示例。

  ```ts
  Column() {
    Text('Hello')
      .fontSize(100)
    Divider()
    Text(this.myText)
      .fontSize(100)
      .fontColor(Color.Red)
  }
  ```

- 容器组件均支持子组件配置，可以实现相对复杂的多级嵌套。

  ```ts
  Column() {
    Row() {
      Image('test1.jpg')
        .width(100)
        .height(100)
      Button('click +1')
        .onClick(() => {
          console.info('+1 clicked!');
        })
    }
  }
  ```
