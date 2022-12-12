# 基本UI描述

ArkTS通过装饰器@Component和@Entry装饰struct关键字声明的数据结构，构成一个自定义组件。自定义组件中提供了一个build函数，开发者需在该函数内以链式调用的方式进行基本的UI描述，UI描述的方法请参考[UI描述规范](#ui描述规范)。

## 基本概念

- struct：自定义组件可以基于struct实现，不能有继承关系，对于struct的实例化，可以省略new。

- 装饰器：装饰器给被装饰的对象赋予某一种能力，其不仅可以装饰类或结构体，还可以装饰类的属性。多个装饰器可以叠加到目标元素上，定义在同一行中或者分开多行，推荐分开多行定义。

  ```ts
  @Entry
  @Component
  struct MyComponent {
  }
  ```

- build函数：自定义组件必须定义build函数，并且禁止自定义构造函数。build函数满足Builder构造器接口定义，用于定义组件的声明式UI描述。

  ```ts
  interface Builder {
      build: () => void
  }
  ```

- @Component：装饰struct，结构体在装饰后具有基于组件的能力，需要实现build方法来创建UI。

- @Entry： 装饰struct，组件被装饰后作为页面的入口，页面加载时将被渲染显示。

- @Preview：装饰struct， 用@Preview装饰的自定义组件可以在DevEco Studio的预览器上进行实时预览，加载页面时，将创建并显示@Preview装饰的自定义组件。

  > **说明：** 在单个源文件中，最多可以使用10个@Preview装饰自定义组件，更多说明请参考[查看ArkTS组件预览效果](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-previewing-app-service-0000001218760596#section146052489820)。

- 链式调用：以 "." 链式调用的方式配置UI组件的属性方法、事件方法等。

## UI描述规范

### 无参数构造配置

如果组件的接口定义中不包含必选构造参数，组件后面的“()”中不需要配置任何内容。例如，Divider组件不包含构造参数： 

```ts
Column() {
    Text('item 1')
    Divider()
    Text('item 2')
}
```

### 必选参数构造配置

如果组件的接口定义中包含必选构造参数，则在组件后面的“()”中必须配置相应参数，参数可以使用常量进行赋值。

例如：

- Image组件的必选参数src：

  ```ts
  Image('https://xyz/test.jpg')
  ```

- Text组件的必选参数content：

  ```ts
  Text('test')
  ```

变量或表达式也可以用于参数赋值，其中表达式返回的结果类型必须满足参数类型要求，变量的定义详见[页面级变量的状态管理](arkts-state-mgmt-page-level.md)与[应用级变量的状态管理](arkts-state-mgmt-application-level.md)。例如，设置变量或表达式来构造Image和Text组件的参数：

```ts
Image(this.imagePath)
Image('https://' + this.imageUrl)
Text(`count: ${this.count}`)
```

### 属性配置

使用属性方法配置组件的属性，属性方法紧随组件，并用"."运算符连接。

- 配置Text组件的字体大小属性：

  ```ts
  Text('test')
    .fontSize(12)
  ```

- 使用"."运算符进行链式调用并同时配置组件的多个属性，如下所示：

  ```ts
  Image('test.jpg')
    .alt('error.jpg')    
    .width(100)    
    .height(100)
  ```

- 除了直接传递常量参数外，还可以传递变量或表达式，如下所示：

  ```ts
  Text('hello')
    .fontSize(this.size)
  Image('test.jpg')
    .width(this.count % 2 === 0 ? 100 : 200)    
    .height(this.offset + 100)
  ```

-  对于系统内置组件，框架还为其属性预定义了一些[枚举类型](../reference/arkui-ts/ts-appendix-enums.md)供开发人员调用，枚举类型可以作为参数传递，且必须满足参数类型要求。例如，可以按以下方式配置Text组件的颜色和字体属性： 

  ```ts
  Text('hello')
    .fontSize(20)
    .fontColor(Color.Red)
    .fontWeight(FontWeight.Bold)
  ```

### 事件配置

通过事件方法可以配置组件支持的事件，事件方法紧随组件，并用"."运算符连接。

- 使用lambda表达式配置组件的事件方法：

  ```ts
  Button('add counter')
      .onClick(() => {
          this.counter += 2
      })
  ```

- 使用匿名函数表达式配置组件的事件方法，要求使用bind，以确保函数体中的this引用包含的组件：

  ```ts
  Button('add counter')
      .onClick(function () {
          this.counter += 2
      }.bind(this))
  ```

- 使用组件的成员函数配置组件的事件方法：

  ```ts
  myClickHandler(): void {
    this.counter += 2
  }
  
  ...

  Button('add counter')
    .onClick(this.myClickHandler.bind(this))
  ```

### 子组件配置

对于支持子组件配置的组件，例如容器组件，在"{ ... }"里为组件添加子组件的UI描述。Column、Row、Stack、Grid、List等组件都是容器组件。

- 以下是简单的Column示例：

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

- 容器组件之间也可以互相嵌套，实现相对复杂的多级嵌套效果：

  ```ts
  Column() {
    Row() {
      Image('test1.jpg')
        .width(100)
        .height(100)
      Button('click +1')
        .onClick(() => {
          console.info('+1 clicked!')
        })
    }

    Divider()
    Row() {
      Image('test2.jpg')
        .width(100)
        .height(100)
      Button('click +2')
        .onClick(() => {
          console.info('+2 clicked!')
        })
    }

    Divider()
    Row() {
      Image('test3.jpg')
        .width(100)
        .height(100)
      Button('click +3')
        .onClick(() => {
          console.info('+3 clicked!')
        })
    }
  }
  ```