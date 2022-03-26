# 属性配置


使用属性方法配置组件的属性，属性方法紧随组件，并用“.”运算符连接。


- 配置Text组件的字体大小属性：
  ```
  Text('123')
      .fontSize(12)
  ```


- 使用“.”操作进行链式调用并同时配置组件的多个属性，如下所示：
  ```
  Image('a.jpg')
      .alt('error.jpg')    
      .width(100)    
      .height(100)
  ```


- 除了直接传递常量参数外，还可以传递变量或表达式，如下所示：
  ```
  // Size, count, and offset are private variables defined in the component.
  Text('hello')
      .fontSize(this.size)
  Image('a.jpg')
      .width(this.count % 2 === 0 ? 100 : 200)    
      .height(this.offset + 100)
  ```


- 对于内置组件，框架还为其属性预定义了一些枚举类型，供开发人员调用，枚举值可以作为参数传递。枚举类型必须满足参数类型要求，有关特定属性的枚举类型定义的详细信息。可以按以下方式配置Text组件的颜色和字体属性：
  ```
  Text('hello')
      .fontSize(20)
      .fontColor(Color.Red)
      .fontWeight(FontWeight.Bold)
  ```
