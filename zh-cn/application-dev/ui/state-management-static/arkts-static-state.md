# \@State装饰器：组件内状态

被状态变量装饰器装饰的变量称为状态变量。状态变量的修改会引起关联UI组件的刷新。@State是最基础的状态变量装饰器，用于将自定义组件内的普通变量转变为状态变量，管理组件内UI刷新。

## 概述

\@State装饰的变量是私有的，只能从组件内部访问。声明时必须指定其类型并定义本地默认值。若需从父组件初始化，可使用命名参数机制赋值。

\@State装饰的变量拥有以下特点：

- @State装饰的变量与子组件中的[@PropRef](arkts-static-propref.md)装饰变量建立单向数据同步，与@Link、@ObjectLink装饰变量建立双向数据同步。

- \@State装饰的变量生命周期与其所属自定义组件的生命周期相同。

在静态语言上下文中使用时，需要导入装饰器：

```ts
import { State } from '@ohos.arkui.stateManagement';
```

## 装饰器说明

| \@State变量装饰器  | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| 装饰器参数         | 无                                                           |
| 允许装饰的变量类型 | Object、class、string、number、boolean、enum、interface等基本类型以及Array、Date、Map、Set等内嵌类型。支持null、undefined以及联合类型。 |
| 初始化规则         | 必须定义本地默认值。<br/>可以从父组件传入非undefined类型变量，此时使用该传入变量进行初始化。<br/>父组件未传入或传入undefined类型变量时，使用本地默认值进行初始化。 |
| 同步规则           | **在子组件使用时：**<br>不与父组件中的任何类型变量同步。<br/>父组件传入的外部变量对\@State初始化时，仅作为初始值，后续变量的变化不会同步至\@State。<br/>**在父组件使用时：**<br/>可以初始化子组件的常规变量、\@State、\@Link、\@PropRef、[\@Provide](arkts-static-provide-and-consume.md)。<br/>\@State变量的变化会同步给子组件的\@Link、\@PropRef变量。 |

## 观察变化和行为表现

状态变量的更改只有在被框架观察到时才会引起UI刷新。

### 观察变化

- 当装饰的数据类型为boolean、string、number类型时，可以观察到数值的变化。

  ```ts
  // 简单类型
  @State count: number = 0;
  // 可以观察到值的变化
  this.count = 1;
  ```

- 当装饰class类型时，需要借助@Observed与@Track观测类属性，单独的@State仅能观测类整体的赋值。

- 当装饰数组时，可以观察到数组本身的赋值、添加、删除和更新。例子如下。
  声明Model类。

  ```ts
  class Model {
    public value: number;
    constructor(value: number) {
      this.value = value;
    }
  }
  ```

  \@State装饰的对象为Model类型数组时。

  ```ts
  // 数组类型
  @State title: Model[] = [new Model(11), new Model(1)];
  ```

  数组自身的赋值可以观察到。

  ```ts
  // 数组赋值
  this.title = [new Model(2)];
  ```

  数组项的赋值可以观察到。

  ```ts
  // 数组项赋值
  this.title[0] = new Model(2);
  ```

  删除数组项可以观察到。

  ```ts
  // 数组项更改
  this.title.pop();
  ```

  新增数组项可以观察到。

  ```ts
  // 数组项更改
  this.title.push(new Model(12));
  ```

  数组项中属性的赋值观察不到。

  ```ts
  // 嵌套的属性赋值观察不到
  this.title[0].value = 6;
  ```

- 当装饰Date时，可以观察到Date的赋值，并通过调用`setFullYear`、`setMonth`、`setDate`、`setHours`、`setMinutes`、`setSeconds`、`setMilliseconds`、`setTime`、`setUTCFullYear`、`setUTCMonth`、`setUTCDate`、`setUTCHours`、`setUTCMinutes`、`setUTCSeconds`、`setUTCMilliseconds`接口更新Date的属性。

  ```ts
  import { Entry, Component, Column, Button, ClickEvent, Text } from '@ohos.arkui.component';
  import { State } from '@ohos.arkui.stateManagement';
  @Entry
  @Component
  struct DateExample {
    @State selectedDate: Date = new Date('2021-08-08');
  
    build() {
      Column() {
        Text(`${this.selectedDate}`)
        Button('set selectedDate to 2023-07-08')
          .margin(10)
          .onClick((e: ClickEvent) => {
            this.selectedDate = new Date('2023-07-08');
          })
        Button('increase the year by 1')
          .margin(10)
          .onClick((e: ClickEvent) => {
            this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1);
          })
        Button('increase the month by 1')
          .margin(10)
          .onClick((e: ClickEvent) => {
            this.selectedDate.setMonth(this.selectedDate.getMonth() + 1);
          })
        Button('increase the day by 1')
          .margin(10)
          .onClick((e: ClickEvent) => {
            this.selectedDate.setDate(this.selectedDate.getDate() + 1);
          })
      }.width('100%')
    }
  }
  ```

- 当装饰Map时，可以观察到Map整体的赋值，以及通过调用Map的接口`set`, `clear`, `delete`来更新Map的值。详见[装饰Map类型变量](#装饰map类型变量)。

- 当装饰Set时，可以观察到Set整体的赋值，以及通过调用Set的接口`add`, `clear`, `delete`来更新Set的值。详见[装饰Set类型变量](#装饰set类型变量)。

- 当装饰interface字面量类型时，可以观察到字面量整体以及属性的变化。

  ```ts
  import { Entry, Component, Column, Text, ClickEvent } from '@ohos.arkui.component';
  import { State } from '@ohos.arkui.stateManagement';
  interface Info {
    name: string;
    age: number;
  }
  @Entry
  @Component
  struct Index {
    // 装饰字面量
    @State info: Info = { name: 'Jack', age: 25 } as Info;
    build() {
      Column() {
        Text(`info.name: ${this.info.name}`)
          .onClick((e: ClickEvent) => {
            this.info.name = 'Tom'; // 变化可观察
          })
      }
    }
  }
  ```

### 框架行为

- 状态变量改变时，查询依赖该状态变量的组件。

- 执行依赖该状态变量的组件更新方法，实现组件的更新渲染。

## 限制条件

\@State装饰的变量必须定义本地默认值，否则编译期会报错。

```ts
// 错误写法，编译报错
@State count: number;

// 正确写法
@State count: number = 10;
```

## 使用场景

### 装饰简单类型的变量

以下示例展示了如何使用\@State装饰器来装饰一个简单类型的变量。在这个例子中，count被\@State装饰成为状态变量，其改变会触发Button组件的刷新：

- 当状态变量count改变时，仅能查询到与之关联的Button组件。
- 仅Button组件执行更新方法，实现按需刷新。

```ts
import { Entry, Component, Button, ClickEvent } from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';
@Entry
@Component
struct MyComponent {
  @State count: number = 0;

  build() {
    Button(`click times: ${this.count}`)
      .onClick((e: ClickEvent) => {
        this.count += 1;
      })
  }
}
```

### 装饰Map类型变量

在下面的示例中，message类型为Map\<number, string\>，点击Button改变其值，视图随之刷新。

```ts
import { Entry, Component, Column, ForEach, Divider, Text, Button, ClickEvent, Row } from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';
@Entry
@Component
struct MapSample {
  @State message: Map<number, string> = new Map<number, string>([[0.0, 'a'], [1.0, 'b'], [3.0, 'c']]);

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.message.entries()), (item: [number, string], index: number) => {
          Text(`${item[0]}`).fontSize(30)
          Text(`${item[1]}`).fontSize(30)
          Divider()
        })
        Button('init map').onClick((e: ClickEvent) => {
          this.message = new Map<number, string>([[0.0, 'a'], [1.0, 'b'], [3.0, 'c']]);
        })
        Button('set new one').onClick((e: ClickEvent) => {
          this.message.set(4.0, 'd');
        })
        Button('clear').onClick((e: ClickEvent) => {
          this.message.clear();
        })
        Button('replace the first one').onClick((e: ClickEvent) => {
          this.message.set(0.0, 'aa' );
        })
        Button('delete the first one').onClick((e: ClickEvent) => {
          this.message.delete(0.0);
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### 装饰Set类型变量

在下面的示例中，message类型为Set\<number\>，点击Button改变其值，视图随之刷新。

```ts
import { Entry, Component, Row, Column, ForEach, Divider, Text, Button, ClickEvent } from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';
@Entry
@Component
struct SetSample {
  @State message: Set<number> = new Set<number>([0.0, 1.0, 2.0, 3.0, 4.0]);

  build() {
    Row() {
      Column() {
        ForEach(Array.from(this.message.entries()), (item: [number, number], index: number) => {
          Text(`${item[0]}`).fontSize(30)
          Divider()
        })
        Button('init set').onClick((e: ClickEvent) => {
          this.message = new Set<number>([0.0, 1.0, 2.0, 3.0, 4.0]);
        })
        Button('set new one').onClick((e: ClickEvent) => {
          this.message.add(5.0);
        })
        Button('clear').onClick((e: ClickEvent) => {
          this.message.clear();
        })
        Button('delete the first one').onClick((e: ClickEvent) => {
          this.message.delete(0.0);
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## State支持联合类型实例

\@State支持联合类型（包括undefined和null）。在下面的示例中，count类型为number | undefined，点击Button改变count的值或类型，视图会随之刷新。

```ts
import { Entry, Component, Column, Text, Button, ClickEvent } from '@ohos.arkui.component';
import { State } from '@ohos.arkui.stateManagement';
@Entry
@Component
struct MyComponent {
  @State count: number | undefined = 0;

  build() {
    Column() {
      Text(`count(${this.count})`)
      Button('change')
        .onClick((e: ClickEvent) => {
          this.count = undefined;
        })
    }
  }
}
```

