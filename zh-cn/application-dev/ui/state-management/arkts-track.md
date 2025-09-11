# \@Track装饰器：class对象属性级更新
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->


\@Track应用于class对象的属性级更新。\@Track装饰的属性变化时，只会触发该属性关联的UI更新。


在阅读本文档之前，建议开发者对状态管理基本观察能力有基本的了解。建议提前阅读：[\@State](./arkts-state.md)。

> **说明：**
>
> 从API version 11开始，该装饰器支持在ArkTS卡片中使用。
>
> 从API version 12开始，该装饰器支持在原子化服务中使用。


## 概述

\@Track是class对象的属性装饰器。当一个class对象是状态变量时，\@Track装饰的属性发生变化，只会触发该属性关联的UI更新；如果class类中使用了\@Track装饰器，则未被\@Track装饰器装饰的属性不能在UI中使用，如果使用，会发生运行时报错。

## class属性级更新说明

状态管理V1中\@State等装饰器默认支持观察第一层属性的变化，第一层属性的变化虽然可以触发更新，但无法做到类属性级的观察，下面的例子就展示了这一限制：

```ts
class Info {
  name: string = 'Jack';
  age: number = 12;
}

@Entry
@Component
struct Index {
  @State info: Info = new Info();

  // 借助getFontSize的日志打印，可以分辨哪个组件触发了渲染
  getFontSize(id: number): number {
    console.info(`Component ${id} render`);
    return 30;
  }

  build() {
    Column() {
      Text(`name: ${this.info.name}`)
        .fontSize(this.getFontSize(1))
      Text(`age: ${this.info.age}`)
        .fontSize(this.getFontSize(2))

      // 点击当前Button，可以发现当前虽然仅改变了name属性
      // 但是依旧会触发两个Text的刷新
      // Text(`age: ${this.info.age}`)是冗余刷新
      Button('change name').onClick(() => {
        this.info.name = 'Jane';
      })

      // 点击当前Button，可以发现当前虽然仅改变了age属性
      // 但是依旧会触发两个Text的刷新
      // Text(`name: ${this.info.name}`)是冗余刷新
      Button('change age').onClick(() => {
        this.info.age++;
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

> **说明：**
>
> 当UI刷新时，会执行组件的属性设置方法，利用这一机制可以通过观察`getFontSize`方法是否被调用来判断当前组件是否刷新。

- UI首次渲染完成，观察到输出如下日志：
```
Component 1 render
Component 2 render
```
- 当点击`Button('change name')`时，即使只修改了`info.name`，观察日志发现两个Text组件仍会重新渲染。组件```Text(`age: ${this.info.age}`)```并未使用`name`属性，但仍因为`info.name`的改变而刷新，因此这次刷新是冗余的。日志输出如下：
```
Component 1 render
Component 2 render
```
-  同理，点击`Button('change age')`，也会触发```Text(`name: ${this.info.name}`)```的刷新。日志输出如下：
```
Component 1 render
Component 2 render
```

造成上述冗余刷新的根本原因是：状态管理V1中\@State等装饰器无法精准观察类属性的访问与变更。为了实现类对象属性的精准观察，引入\@Track装饰器。


## 装饰器说明

| \@Track变量装饰器  | 说明                  |
| ------------------ | -------------------- |
| 装饰器参数   | 无 |
| 可装饰的变量 | class对象的非静态成员属性。 |



## 观察变化和行为表现

当一个class对象是状态变量时，\@Track装饰的属性发生变化，该属性关联的UI触发更新。

> **说明：**
>
> 当class对象中没有一个属性被标记\@Track，行为与原先保持不变。\@Track没有深度观测的功能。

使用\@Track装饰器可以避免冗余刷新。

```ts
class LogTrack {
  @Track str1: string;
  @Track str2: string;

  constructor(str1: string) {
    this.str1 = str1;
    this.str2 = 'World';
  }
}

class LogNotTrack {
  str1: string;
  str2: string;

  constructor(str1: string) {
    this.str1 = str1;
    this.str2 = '世界';
  }
}

@Entry
@Component
struct AddLog {
  @State logTrack: LogTrack = new LogTrack('Hello');
  @State logNotTrack: LogNotTrack = new LogNotTrack('你好');

  isRender(index: number) {
    console.log(`Text ${index} is rendered`);
    return 50;
  }

  build() {
    Row() {
      Column() {
        Text(this.logTrack.str1) // Text1
          .fontSize(this.isRender(1))
          .fontWeight(FontWeight.Bold)
        Text(this.logTrack.str2) // Text2
          .fontSize(this.isRender(2))
          .fontWeight(FontWeight.Bold)
        Button('change logTrack.str1')
          .onClick(() => {
            this.logTrack.str1 = 'Bye';
          })
        Text(this.logNotTrack.str1) // Text3
          .fontSize(this.isRender(3))
          .fontWeight(FontWeight.Bold)
        Text(this.logNotTrack.str2) // Text4
          .fontSize(this.isRender(4))
          .fontWeight(FontWeight.Bold)
        Button('change logNotTrack.str1')
          .onClick(() => {
            this.logNotTrack.str1 = '再见';
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

在上面的示例中：

1. 类LogTrack中的属性均被\@Track装饰器装饰，点击按钮"change logTrack.str1"，此时Text1刷新，Text2不刷新，只有一条日志输出，避免了冗余刷新。
    ```ts
    Text 1 is rendered
    ```

2. 类logNotTrack中的属性均未被\@Track装饰器装饰，点击按钮"change logNotTrack.str1"，此时Text3、Text4均会刷新，有两条日志输出，存在冗余刷新。
    ```ts
    Text 3 is rendered
    Text 4 is rendered
    ```

## 限制条件

- 如果class类中使用了\@Track装饰器，那么该class类中非\@Track装饰的属性不能在\@Component UI中使用，包括不能绑定在组件上、不能用于初始化子组件，错误的使用将导致运行时报错，详见[在UI中使用非\@Track装饰的属性发生运行时报错](#在ui中使用非track装饰的属性发生运行时报错)；可以在非UI中使用非\@Track装饰的属性，如事件回调函数中、生命周期函数中等。

- API version 19及以后，\@Track使用在[\@ComponentV2](./arkts-new-componentV2.md)的UI中，不会引起运行时报错，但依旧不会刷新，详见[常见场景](./arkts-v1-v2-mixusage.md#observed装饰的class)。

- 建议开发者不要混用包含\@Track的class对象和不包含\@Track的class对象，如联合类型中、类继承中等。


## 使用场景

### \@Track和自定义组件更新

以下示例展示组件更新和\@Track的处理步骤。对象log是\@State装饰的状态变量，logInfo是\@Track装饰的成员属性，其余成员属性都是非\@Track装饰的，而且也不准备在UI中更新它们的值。


```ts
class Log {
  @Track logInfo: string;
  owner: string;
  id: number;
  time: Date;
  location: string;
  reason: string;

  constructor(logInfo: string) {
    this.logInfo = logInfo;
    this.owner = 'OH';
    this.id = 0;
    this.time = new Date();
    this.location = 'CN';
    this.reason = 'NULL';
  }
}

@Entry
@Component
struct AddLog {
  @State log: Log = new Log('origin info.');

  build() {
    Row() {
      Column() {
        Text(this.log.logInfo)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .onClick(() => {
            // 没有被@Track装饰的属性可以在点击事件中使用。
            console.log('owner: ' + this.log.owner +
              ' id: ' + this.log.id +
              ' time: ' + this.log.time +
              ' location: ' + this.log.location +
              ' reason: ' + this.log.reason);
            this.log.time = new Date();
            this.log.id++;

            this.log.logInfo += ' info.';
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

处理步骤：

1. AddLog自定义组件的Text.onClick点击事件自增字符串' info.'。

2. 由于\@State log变量的\@Track属性logInfo更改，Text重新渲染。

## 常见问题

### 在UI中使用非\@Track装饰的属性发生运行时报错

在UI中使用非\@Track装饰的属性，运行时会报错。

```ts
class Person {
  // id被@Track装饰
  @Track id: number;
  // age未被@Track装饰
  age: number;

  constructor(id: number, age: number) {
    this.id = id;
    this.age = age;
  }
}

@Entry
@Component
struct Parent {
  @State parent: Person = new Person(2, 30);

  build() {
    // 没有被@Track装饰的属性不可以在UI中使用，运行时会报错
    Text(`Parent id is: ${this.parent.id} and Parent age is: ${this.parent.age}`)
  }
}
```
