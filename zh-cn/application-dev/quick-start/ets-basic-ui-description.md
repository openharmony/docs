# 基本UI描述

eTS通过装饰器@Component和@Entry装饰struct关键字声明的数据结构，构成一个自定义组件。自定义组件中提供了一个build函数，开发者需在该函数内以链式调用的方式进行基本的UI描述，UI描述的方法请参考[UI描述规范](#ui描述规范)。

## 基本概念

- struct：组件可以基于struct实现，不能有继承关系，对于struct的实例化，可以省略new。

- 装饰器：装饰器给被装饰的对象赋予某一种能力，其不仅可以装饰类或结构体，还可以装饰类的属性。多个装饰器可以叠加到目标元素，定义在同一行上或者多行上，推荐定义在多行上。

  ```ts
  @Entry
  @Component
  struct MyComponent {
  }
  ```

- build函数：自定义组件必须定义build函数，并且自定义组件禁止自定义构造函数。build函数满足Builder构造器接口定义，用于定义组件的声明式UI描述。

  ```ts
  interface Builder {
      build: () => void
  }
  ```

- @Component：装饰struct，结构体在装饰后具有基于组件的能力，需要实现build方法来更新UI。

- @Entry： 装饰struct，组件被装饰后作为页面的入口，页面加载时将被渲染显示。

- @Preview：装饰struct， 用@Preview装饰的自定义组件可以在DevEco Studio的预览器上进行实时预览，加载页面时，将创建并呈现@Preview装饰的自定义组件。 

  > **说明：** 在单个源文件中，最多可以使用10个@Preview装饰自定义组件，更多说明请参考[查看eTS组件预览效果](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-previewing-app-service-0000001218760596#section146052489820)。

- 链式调用：以 "." 链式调用的方式配置UI结构及其属性、事件等。

## UI描述规范

### 无参数构造配置

组件的接口定义不包含必选构造参数，组件后面的“()”中不需要配置任何内容。例如，Divider组件不包含构造参数： 

```ts
Column() {
    Text('item 1')
    Divider()
    Text('item 2')
}
```

### 必选参数构造配置

如果组件的接口定义中包含必选构造参数，则在组件后面的“()”中必须配置参数，参数可以使用常量进行赋值。

例如：

- Image组件的必选参数src：

  ```ts
  Image('http://xyz/a.jpg')
  ```

- Text组件的必选参数content：

  ```ts
  Text('123')
  ```

变量或表达式也可以用于参数赋值，其中表达式返回的结果类型必须满足参数类型要求。例如，传递变量或表达式来构造Image和Text组件的参数：

```ts
Image(this.imagePath)
Image('http://' + this.imageUrl)
Text(`count: ${this.count}`)
```

### 属性配置

使用属性方法配置组件的属性，属性方法紧随组件，并用"."运算符连接。

- 配置Text组件的字体大小属性：

  ```ts
  Text('123')
      .fontSize(12)
  ```

- 使用"."操作进行链式调用并同时配置组件的多个属性，如下所示：

  ```ts
  Image('a.jpg')
      .alt('error.jpg')    
      .width(100)    
      .height(100)
  ```

- 除了直接传递常量参数外，还可以传递变量或表达式，如下所示：

  ```ts
  Text('hello')
      .fontSize(this.size)
  Image('a.jpg')
      .width(this.count % 2 === 0 ? 100 : 200)    
      .height(this.offset + 100)
  ```

-  对于系统内置组件，框架还为其属性预定义了一些[枚举类型](../reference/arkui-ts/ts-appendix-enums.md)供开发人员调用，枚举类型必须满足参数类型要求，枚举值可以作为参数传递。可以按以下方式配置Text组件的颜色和字体属性： 

  ```ts
  Text('hello')
      .fontSize(20)
      .fontColor(Color.Red)
      .fontWeight(FontWeight.Bold)
  ```

### 事件配置

通过事件方法可以配置组件支持的事件。

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
    
  }
  
  ...
  
  Button('add counter')
    .onClick(this.myClickHandler)
  ```

### 子组件配置

对于支持子组件配置的组件，例如容器组件，在"{ ... }"里为组件添加子组件的UI描述。Column、Row、Stack、Button、Grid和List组件都是容器组件。

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

- 可以嵌套多个子组件：

  ```ts
  Column() {
      Column() {
          Button() {
              Text('+ 1')
          }.type(ButtonType.Capsule)
          .onClick(() => console.log ('+1 clicked!'))
          Image('1.jpg')
      }
      Divider()
      Column() {
          Button() {
              Text('+ 2')
          }.type(ButtonType.Capsule)
          .onClick(() => console.log ('+2 clicked!'))
          Image('2.jpg')
      }
      Divider()
      Column() {
          Button() {
              Text('+ 3')
          }.type(ButtonType.Capsule)
          .onClick(() => console.log('+3 clicked!'))
          Image('3.jpg')
      }
  }.alignItems(HorizontalAlign.Center) 
  ```