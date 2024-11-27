# \@Track装饰器：class对象属性级更新


\@Track应用于class对象的属性级更新。\@Track装饰的属性变化时，只会触发该属性关联的UI更新。


> **说明：**
>
> 从API version 11开始，该装饰器支持在ArkTS卡片中使用。


## 概述

\@Track是class对象的属性装饰器。当一个class对象是状态变量时，\@Track装饰的属性发生变化，只会触发该属性关联的UI更新；如果class类中使用了\@Track装饰器，则未被\@Track装饰器装饰的属性不能在UI中使用，如果使用，会发生运行时报错。


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

- 如果class类中使用了\@Track装饰器，那么该class类中非\@Track装饰的属性不能在UI中使用，包括不能绑定在组件上、不能用于初始化子组件，错误的使用将导致运行时报错，详见[在UI中使用非\@Track装饰的属性发生运行时报错](#在ui中使用非track装饰的属性发生运行时报错)；可以在非UI中使用非\@Track装饰的属性，如事件回调函数中、生命周期函数中等。

- 建议开发者不要混用包含\@Track的class对象和不包含\@Track的class对象，如联合类型中、类继承中等。


## 使用场景

### \@Track和自定义组件更新

以下示例展示组件更新和\@Track的处理步骤。对象log是\@State装饰的状态变量，logInfo是\@Track的成员属性，其余成员属性都是非\@Track装饰的，而且也不准备在UI中更新它们的值。


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
