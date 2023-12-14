# \@Observed装饰器和\@ObjectLink装饰器：嵌套类对象属性变化


上文所述的装饰器仅能观察到第一层的变化，但是在实际应用开发中，应用会根据开发需要，封装自己的数据模型。对于多层嵌套的情况，比如二维数组，或者数组项class，或者class的属性是class，他们的第二层的属性变化是无法观察到的。这就引出了\@Observed/\@ObjectLink装饰器。


> **说明：**
>
> 从API version 9开始，这两个装饰器支持在ArkTS卡片中使用。


## 概述

\@ObjectLink和\@Observed类装饰器用于在涉及嵌套对象或数组的场景中进行双向数据同步：

- 被\@Observed装饰的类，可以被观察到属性的变化；

- 子组件中\@ObjectLink装饰器装饰的状态变量用于接收\@Observed装饰的类的实例，和父组件中对应的状态变量建立双向数据绑定。这个实例可以是数组中的被\@Observed装饰的项，或者是class object中的属性，这个属性同样也需要被\@Observed装饰。

- 单独使用\@Observed是没有任何作用的，需要搭配\@ObjectLink或者[\@Prop](arkts-prop.md)使用。


## 限制条件

- 使用\@Observed装饰class会改变class原始的原型链，\@Observed和其他类装饰器装饰同一个class可能会带来问题。

- \@ObjectLink装饰器不能在\@Entry装饰的自定义组件中使用。


## 装饰器说明

| \@Observed类装饰器 | 说明                                |
| -------------- | --------------------------------- |
| 装饰器参数          | 无                                 |
| 类装饰器           | 装饰class。需要放在class的定义前，使用new创建类对象。 |

| \@ObjectLink变量装饰器 | 说明                                       |
| ----------------- | ---------------------------------------- |
| 装饰器参数             | 无                                        |
| 同步类型              | 不与父组件中的任何类型同步变量。                         |
| 允许装饰的变量类型         | 必须为被\@Observed装饰的class实例，必须指定类型。<br/>不支持简单类型，可以使用[\@Prop](arkts-prop.md)。<br/>支持继承Date或者Array的class实例，示例见[观察变化](#观察变化)。<br/>API11及以上支持\@Observed装饰类和undefined或null组成的联合类型，比如ClassA \| ClassB, ClassA \| undefined 或者 ClassA \| null, 示例见[@ObjectLink支持联合类型](#objectlink支持联合类型)。<br/>\@ObjectLink的属性是可以改变的，但是变量的分配是不允许的，也就是说这个装饰器装饰变量是只读的，不能被改变。 |
| 被装饰变量的初始值         | 不允许。                                     |

\@ObjectLink装饰的数据为可读示例。


```ts
// 允许@ObjectLink装饰的数据属性赋值
this.objLink.a= ...
// 不允许@ObjectLink装饰的数据自身赋值
this.objLink= ...
```

> **说明：**
>
> \@ObjectLink装饰的变量不能被赋值，如果要使用赋值操作，请使用[@Prop](arkts-prop.md)。
>
> - \@Prop装饰的变量和数据源的关系是是单向同步，\@Prop装饰的变量在本地拷贝了数据源，所以它允许本地更改，如果父组件中的数据源有更新，\@Prop装饰的变量本地的修改将被覆盖；
>
> - \@ObjectLink装饰的变量和数据源的关系是双向同步，\@ObjectLink装饰的变量相当于指向数据源的指针。禁止对\@ObjectLink装饰的变量赋值，如果一旦发生\@ObjectLink装饰的变量的赋值，则同步链将被打断。因为\@ObjectLink修饰的变量通过数据源（Object）引用来初始化。对于实现双向数据同步的@ObjectLink，赋值相当于更新父组件中的数组项或者class的属性，TypeScript/JavaScript不能实现，会发生运行时报错。


## 变量的传递/访问规则说明

| \@ObjectLink传递/访问 | 说明                                       |
| ----------------- | ---------------------------------------- |
| 从父组件初始化           | 必须指定。<br/>初始化\@ObjectLink装饰的变量必须同时满足以下场景：<br/>-&nbsp;类型必须是\@Observed装饰的class。<br/>-&nbsp;初始化的数值需要是数组项，或者class的属性。<br/>-&nbsp;同步源的class或者数组必须是\@State，\@Link，\@Provide，\@Consume或者\@ObjectLink装饰的数据。<br/>同步源是数组项的示例请参考[对象数组](#对象数组)。初始化的class的示例请参考[嵌套对象](#嵌套对象)。 |
| 与源对象同步            | 双向。                                      |
| 可以初始化子组件          | 允许，可用于初始化常规变量、\@State、\@Link、\@Prop、\@Provide |


  **图1** 初始化规则图示  


![zh-cn_image_0000001502255262](figures/zh-cn_image_0000001502255262.png)


## 观察变化和行为表现


### 观察变化

\@Observed装饰的类，如果其属性为非简单类型，比如class、Object或者数组，也需要被\@Observed装饰，否则将观察不到其属性的变化。


```ts
class ClassA {
  public c: number;

  constructor(c: number) {
    this.c = c;
  }
}

@Observed
class ClassB {
  public a: ClassA;
  public b: number;

  constructor(a: ClassA, b: number) {
    this.a = a;
    this.b = b;
  }
}
```

以上示例中，ClassB被\@Observed装饰，其成员变量的赋值的变化是可以被观察到的，但对于ClassA，没有被\@Observed装饰，其属性的修改不能被观察到。


```ts
@ObjectLink b: ClassB

// 赋值变化可以被观察到
this.b.a = new ClassA(5)
this.b.b = 5

// ClassA没有被@Observed装饰，其属性的变化观察不到
this.b.a.c = 5
```

\@ObjectLink：\@ObjectLink只能接收被\@Observed装饰class的实例，可以观察到：

- 其属性的数值的变化，其中属性是指Object.keys(observedObject)返回的所有属性，示例请参考[嵌套对象](#嵌套对象)。

- 如果数据源是数组，则可以观察到数组item的替换，如果数据源是class，可观察到class的属性的变化，示例请参考[对象数组](#对象数组)。

继承Date的class时，可以观察到Date整体的赋值，同时可通过调用Date的接口`setFullYear`, `setMonth`, `setDate`, `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, `setUTCFullYear`, `setUTCMonth`, `setUTCDate`, `setUTCHours`, `setUTCMinutes`, `setUTCSeconds`, `setUTCMilliseconds` 更新Date的属性。

```ts
@Observed
class DateClass extends Date {
  constructor(args: number | string) {
    super(args)
  }
}

@Observed
class ClassB {
  public a: DateClass;

  constructor(a: DateClass) {
    this.a = a;
  }
}

@Component
struct ViewA {
  label: string = 'date';
  @ObjectLink a: DateClass;

  build() {
    Column() {
      Button(`child increase the day by 1`)
        .onClick(() => {
          this.a.setDate(this.a.getDate() + 1);
        })
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.a
      })
    }
  }
}

@Entry
@Component
struct ViewB {
  @State b: ClassB = new ClassB(new DateClass('2023-1-1'));

  build() {
    Column() {
      ViewA({ label: 'date', a: this.b.a })

      Button(`parent update the new date`)
        .onClick(() => {
          this.b.a = new DateClass('2023-07-07');
        })
      Button(`ViewB: this.b = new ClassB(new DateClass('2023-08-20'))`)
        .onClick(() => {
          this.b = new ClassB(new DateClass('2023-08-20'));
        })
    }
  }
}
```


### 框架行为

1. 初始渲染：
   1. \@Observed装饰的class的实例会被不透明的代理对象包装，代理了class上的属性的setter和getter方法
   2. 子组件中\@ObjectLink装饰的从父组件初始化，接收被\@Observed装饰的class的实例，\@ObjectLink的包装类会将自己注册给\@Observed class。

2. 属性更新：当\@Observed装饰的class属性改变时，会走到代理的setter和getter，然后遍历依赖它的\@ObjectLink包装类，通知数据更新。


## 使用场景


### 嵌套对象

以下是嵌套类对象的数据结构。


```ts
// objectLinkNestedObjects.ets
let NextID: number = 1;

@Observed
class ClassA {
  public id: number;
  public c: number;

  constructor(c: number) {
    this.id = NextID++;
    this.c = c;
  }
}

@Observed
class ClassB {
  public a: ClassA;

  constructor(a: ClassA) {
    this.a = a;
  }
}

@Observed
class ClassD {
  public c: ClassC;

  constructor(c: ClassC) {
    this.c = c;
  }
}

@Observed
class ClassC extends ClassA {
  public k: number;

  constructor(k: number) {
    // 调用父类方法对k进行处理
    super(k);
    this.k = k;
  }
}
```


  以下组件层次结构呈现的是嵌套类对象的数据结构。

```ts
@Component
struct ViewC {
  label: string = 'ViewC1';
  @ObjectLink c: ClassC;

  build() {
    Row() {
      Column() {
        Text(`ViewC [${this.label}] this.a.c = ${this.c.c}`)
          .fontColor('#ffffffff')
          .backgroundColor('#ff3fc4c4')
          .height(50)
          .borderRadius(25)
        Button(`ViewC: this.c.c add 1`)
          .backgroundColor('#ff7fcf58')
          .onClick(() => {
            this.c.c += 1;
            console.log('this.c.c:' + this.c.c)
          })
      }
    .width(300)
  }
}
}

@Entry
@Component
struct ViewB {
  @State b: ClassB = new ClassB(new ClassA(0));
  @State child : ClassD = new ClassD(new ClassC(0));
  build() {
    Column() {
      ViewC({ label: 'ViewC #3', c: this.child.c})
      Button(`ViewC: this.child.c.c add 10`)
        .backgroundColor('#ff7fcf58')
        .onClick(() => {
          this.child.c.c += 10
          console.log('this.child.c.c:' + this.child.c.c)
        })
    }
  }
}
```

被@Observed装饰的ClassC类，可以观测到继承基类的属性的变化。


ViewB中的事件句柄：


- this.child.c = new ClassA(0) 和this.b = new ClassB(new ClassA(0))： 对\@State装饰的变量b和其属性的修改。

- this.child.c.c = ... ：该变化属于第二层的变化，[@State](arkts-state.md#观察变化)无法观察到第二层的变化，但是ClassA被\@Observed装饰，ClassA的属性c的变化可以被\@ObjectLink观察到。


ViewC中的事件句柄：


- this.c.c += 1：对\@ObjectLink变量a的修改，将触发Button组件的刷新。\@ObjectLink和\@Prop不同，\@ObjectLink不拷贝来自父组件的数据源，而是在本地构建了指向其数据源的引用。

- \@ObjectLink变量是只读的，this.a = new ClassA(...)是不允许的，因为一旦赋值操作发生，指向数据源的引用将被重置，同步将被打断。


### 对象数组

对象数组是一种常用的数据结构。以下示例展示了数组对象的用法。


```ts
@Component
struct ViewA {
  // 子组件ViewA的@ObjectLink的类型是ClassA
  @ObjectLink a: ClassA;
  label: string = 'ViewA1';

  build() {
    Row() {
      Button(`ViewA [${this.label}] this.a.c = ${this.a.c} +1`)
        .onClick(() => {
          this.a.c += 1;
        })
    }
  }
}

@Entry
@Component
struct ViewB {
  // ViewB中有@State装饰的ClassA[]
  @State arrA: ClassA[] = [new ClassA(0), new ClassA(0)];

  build() {
    Column() {
      ForEach(this.arrA,
        (item: ClassA) => {
          ViewA({ label: `#${item.id}`, a: item })
        },
        (item: ClassA): string => item.id.toString()
      )
      // 使用@State装饰的数组的数组项初始化@ObjectLink，其中数组项是被@Observed装饰的ClassA的实例
      ViewA({ label: `ViewA this.arrA[first]`, a: this.arrA[0] })
      ViewA({ label: `ViewA this.arrA[last]`, a: this.arrA[this.arrA.length-1] })

      Button(`ViewB: reset array`)
        .onClick(() => {
          this.arrA = [new ClassA(0), new ClassA(0)];
        })
      Button(`ViewB: push`)
        .onClick(() => {
          this.arrA.push(new ClassA(0))
        })
      Button(`ViewB: shift`)
        .onClick(() => {
          this.arrA.shift()
        })
      Button(`ViewB: chg item property in middle`)
        .onClick(() => {
          this.arrA[Math.floor(this.arrA.length / 2)].c = 10;
        })
      Button(`ViewB: chg item property in middle`)
        .onClick(() => {
          this.arrA[Math.floor(this.arrA.length / 2)] = new ClassA(11);
        })
    }
  }
}
```

- this.arrA[Math.floor(this.arrA.length/2)] = new ClassA(..) ：该状态变量的改变触发2次更新：
  1. ForEach：数组项的赋值导致ForEach的[itemGenerator](arkts-rendering-control-foreach.md#接口描述)被修改，因此数组项被识别为有更改，ForEach的item builder将执行，创建新的ViewA组件实例。
  2. ViewA({ label: `ViewA this.arrA[first]`, a: this.arrA[0] })：上述更改改变了数组中第一个元素，所以绑定this.arrA[0]的ViewA将被更新。

- this.arrA.push(new ClassA(0)) ： 将触发2次不同效果的更新：
  1. ForEach：新添加的ClassA对象对于ForEach是未知的[itemGenerator](arkts-rendering-control-foreach.md#接口描述)，ForEach的item builder将执行，创建新的ViewA组件实例。
  2. ViewA({ label: `ViewA this.arrA[last]`, a: this.arrA[this.arrA.length-1] })：数组的最后一项有更改，因此引起第二个ViewA的实例的更改。对于ViewA({ label: `ViewA this.arrA[first]`, a: this.arrA[0] })，数组的更改并没有触发一个数组项更改的改变，所以第一个ViewA不会刷新。

- this.arrA[Math.floor(this.arrA.length/2)].c：[@State](arkts-state.md#观察变化)无法观察到第二层的变化，但是ClassA被\@Observed装饰，ClassA的属性的变化将被\@ObjectLink观察到。


### 二维数组

使用\@Observed观察二维数组的变化。可以声明一个被\@Observed装饰的继承Array的子类。


```ts
@Observed
class StringArray extends Array<String> {
}
```

使用new StringArray()来构造StringArray的实例，new运算符使得\@Observed生效，\@Observed观察到StringArray的属性变化。

声明一个从Array扩展的类class StringArray extends Array&lt;String&gt; {}，并创建StringArray的实例。\@Observed装饰的类需要使用new运算符来构建class实例。


```ts
@Observed
class StringArray extends Array<String> {
}

@Component
struct ItemPage {
  @ObjectLink itemArr: StringArray;

  build() {
    Row() {
      Text('ItemPage')
        .width(100).height(100)

      ForEach(this.itemArr,
        (item: string | Resource) => {
          Text(item)
            .width(100).height(100)
        },
        (item: string) => item
      )
    }
  }
}

@Entry
@Component
struct IndexPage {
  @State arr: Array<StringArray> = [new StringArray(), new StringArray(), new StringArray()];

  build() {
    Column() {
      ItemPage({ itemArr: this.arr[0] })
      ItemPage({ itemArr: this.arr[1] })
      ItemPage({ itemArr: this.arr[2] })
      Divider()


      ForEach(this.arr,
        (itemArr: StringArray) => {
          ItemPage({ itemArr: itemArr })
        },
        (itemArr: string) => itemArr[0]
      )

      Divider()

      Button('update')
        .onClick(() => {
          console.error('Update all items in arr');
          if ((this.arr[0] as Array<String>)[0] !== undefined) {
            // 正常情况下需要有一个真实的ID来与ForEach一起使用，但此处没有
            // 因此需要确保推送的字符串是唯一的。
            this.arr[0].push(`${this.arr[0].slice(-1).pop()}${this.arr[0].slice(-1).pop()}`);
            this.arr[1].push(`${this.arr[1].slice(-1).pop()}${this.arr[1].slice(-1).pop()}`);
            this.arr[2].push(`${this.arr[2].slice(-1).pop()}${this.arr[2].slice(-1).pop()}`);
          } else {
            this.arr[0].push('Hello');
            this.arr[1].push('World');
            this.arr[2].push('!');
          }
        })
    }
  }
}
```

## ObjectLink支持联合类型

@ObjectLink支持@Observed装饰类和undefined或null组成的联合类型，在下面的示例中，count类型为ClassA | ClassB | undefined，点击父组件Page2中的Button改变count的属性或者类型，Child中也会对应刷新。

```ts
class ClassA {
  public a: number;

  constructor(a: number) {
    this.a = a;
  }
}

class ClassB {
  public b: number;

  constructor(b: number) {
    this.b = b;
  }
}

@Entry
@Component
struct Page2 {
  @State count: ClassA | ClassB | undefined = new ClassA(10)

  build() {
    Column() {
      Child({ count: this.count })

      Button('change count property')
        .onClick(() => {
          // 判断count的类型，做属性的更新
          if (this.count instanceof ClassA) {
            this.count.a += 1
          } else if (this.count instanceof ClassB) {
            this.count.b += 1
          } else {
            console.info('count is undefined, cannot change property')
          }
        })

      Button('change count to ClassA')
        .onClick(() => {
          // 赋值为ClassA的实例
          this.count = new ClassA(100)
        })

      Button('change count to ClassB')
        .onClick(() => {
          // 赋值为ClassA的实例
          this.count = new ClassB(100)
        })

      Button('change count to undefined')
        .onClick(() => {
          // 赋值为undefined
          this.count = undefined
        })
    }.width('100%')
  }
}

@Component
struct Child {
  @ObjectLink count: ClassA | ClassB | undefined

  build() {
    Column() {
      Text(`count is instanceof ${this.count instanceof ClassA ? 'ClassA' : this.count instanceof ClassB ? 'ClassB' : 'undefined'}`)
        .fontSize(30)

      Text(`count's property is  ${this.count instanceof ClassA ? this.count.a : this.count?.b}`).fontSize(15)

    }.width('100%')
  }
}
```

## 常见问题

### 在子组件中给@ObjectLink装饰的变量赋值

在子组件中给@ObjectLink装饰的变量赋值是不允许的。

【反例】

```ts
@Observed
class ClassA {
  public c: number = 0;

  constructor(c: number) {
    this.c = c;
  }
}

@Component
struct ObjectLinkChild {
  @ObjectLink testNum: ClassA;

  build() {
    Text(`ObjectLinkChild testNum ${this.testNum.c}`)
      .onClick(() => {
        // ObjectLink不能被赋值
        this.testNum = new ClassA(47);
      })
  }
}

@Entry
@Component
struct Parent {
  @State testNum: ClassA[] = [new ClassA(1)];

  build() {
    Column() {
      Text(`Parent testNum ${this.testNum[0].c}`)
        .onClick(() => {
          this.testNum[0].c += 1;
        })
        
      ObjectLinkChild({ testNum: this.testNum[0] })
    }
  }
}
```

点击ObjectLinkChild给\@ObjectLink装饰的变量赋值：

```
this.testNum = new ClassA(47); 
```

这是不允许的，对于实现双向数据同步的\@ObjectLink，赋值相当于要更新父组件中的数组项或者class的属性，这个对于 TypeScript/JavaScript是不能实现的。框架对于这种行为会发生运行时报错。

【正例】

```ts
@Observed
class ClassA {
  public c: number = 0;

  constructor(c: number) {
    this.c = c;
  }
}

@Component
struct ObjectLinkChild {
  @ObjectLink testNum: ClassA;

  build() {
    Text(`ObjectLinkChild testNum ${this.testNum.c}`)
      .onClick(() => {
        // 可以对ObjectLink装饰对象的属性赋值
        this.testNum.c = 47;
      })
  }
}

@Entry
@Component
struct Parent {
  @State testNum: ClassA[] = [new ClassA(1)];

  build() {
    Column() {
      Text(`Parent testNum ${this.testNum[0].c}`)
        .onClick(() => {
          this.testNum[0].c += 1;
        })
        
      ObjectLinkChild({ testNum: this.testNum[0] })
    }
  }
}
```

### 基础嵌套对象属性更改失效

在应用开发中，有很多嵌套对象场景，例如，开发者更新了某个属性，但UI没有进行对应的更新。

每个装饰器都有自己可以观察的能力，并不是所有的改变都可以被观察到，只有可以被观察到的变化才会进行UI更新。\@Observed装饰器可以观察到嵌套对象的属性变化，其他装饰器仅能观察到第二层的变化。

【反例】

下面的例子中，一些UI组件并不会更新。


```ts
class ClassA {
  a: number;

  constructor(a: number) {
    this.a = a;
  }

  getA(): number {
    return this.a;
  }

  setA(a: number): void {
    this.a = a;
  }
}

class ClassC {
  c: number;

  constructor(c: number) {
    this.c = c;
  }

  getC(): number {
    return this.c;
  }

  setC(c: number): void {
    this.c = c;
  }
}

class ClassB extends ClassA {
  b: number = 47;
  c: ClassC;

  constructor(a: number, b: number, c: number) {
    super(a);
    this.b = b;
    this.c = new ClassC(c);
  }

  getB(): number {
    return this.b;
  }

  setB(b: number): void {
    this.b = b;
  }

  getC(): number {
    return this.c.getC();
  }

  setC(c: number): void {
    return this.c.setC(c);
  }
}


@Entry
@Component
struct MyView {
  @State b: ClassB = new ClassB(10, 20, 30);

  build() {
    Column({ space: 10 }) {
      Text(`a: ${this.b.a}`)
      Button("Change ClassA.a")
        .onClick(() => {
          this.b.a += 1;
        })

      Text(`b: ${this.b.b}`)
      Button("Change ClassB.b")
        .onClick(() => {
          this.b.b += 1;
        })

      Text(`c: ${this.b.c.c}`)
      Button("Change ClassB.ClassC.c")
        .onClick(() => {
          // 点击时上面的Text组件不会刷新
          this.b.c.c += 1;
        })
    }
  }
}
```

- 最后一个Text组件Text('c: ${this.b.c.c}')，当点击该组件时UI不会刷新。 因为，\@State b : ClassB 只能观察到this.b属性的变化，比如this.b.a, this.b.b 和this.b.c的变化，但是无法观察嵌套在属性中的属性，即this.b.c.c（属性c是内嵌在b中的对象classC的属性）。

- 为了观察到嵌套于内部的ClassC的属性，需要做如下改变：
  - 构造一个子组件，用于单独渲染ClassC的实例。 该子组件可以使用\@ObjectLink c : ClassC或\@Prop c : ClassC。通常会使用\@ObjectLink，除非子组件需要对其ClassC对象进行本地修改。
  - 嵌套的ClassC必须用\@Observed修饰。当在ClassB中创建ClassC对象时（本示例中的ClassB(10, 20, 30）)，它将被包装在ES6代理中，当ClassC属性更改时（this.b.c.c += 1），该代码将修改通知到\@ObjectLink变量。

【正例】

以下示例使用\@Observed/\@ObjectLink来观察嵌套对象的属性更改。


```ts
class ClassA {
  a: number;
  constructor(a: number) {
    this.a = a;
  }
  getA() : number {
    return this.a; }
  setA( a: number ) : void {
    this.a = a; }
}

@Observed
class ClassC {
  c: number;
  constructor(c: number) {
    this.c = c;
  }
  getC() : number {
    return this.c; }
  setC(c : number) : void {
    this.c = c; }
}

class ClassB extends ClassA {
  b: number = 47;
  c: ClassC;

  constructor(a: number, b: number, c: number) {
    super(a);
    this.b = b;
    this.c = new ClassC(c);
  }

  getB() : number {
    return this.b; }
  setB(b : number) : void {
    this.b = b; }
  getC() : number {
    return this.c.getC(); }
  setC(c : number) : void {
    return this.c.setC(c); }
}

@Component
struct ViewClassC {

    @ObjectLink c : ClassC;
    build() {
        Column({space:10}) {
            Text(`c: ${this.c.getC()}`)
            Button("Change C")
                .onClick(() => {
                    this.c.setC(this.c.getC()+1);
                })
        }
    }
}

@Entry
@Component
struct MyView {
    @State b : ClassB = new ClassB(10, 20, 30);

    build() {
        Column({space:10}) {
            Text(`a: ${this.b.a}`)
             Button("Change ClassA.a")
            .onClick(() => {
                this.b.a +=1;
            })

            Text(`b: ${this.b.b}`)
            Button("Change ClassB.b")
            .onClick(() => {
                this.b.b += 1;
            })

            ViewClassC({c: this.b.c})   // Text(`c: ${this.b.c.c}`)的替代写法
            Button("Change ClassB.ClassC.c")
            .onClick(() => {
                this.b.c.c += 1;
            })
        }
     }
}
```

### 复杂嵌套对象属性更改失效

【反例】

以下示例创建了一个带有\@ObjectLink装饰变量的子组件，用于渲染一个含有嵌套属性的ParentCounter，用\@Observed装饰嵌套在ParentCounter中的SubCounter。


```ts
let nextId = 1;
@Observed
class SubCounter {
  counter: number;
  constructor(c: number) {
    this.counter = c;
  }
}
@Observed
class ParentCounter {
  id: number;
  counter: number;
  subCounter: SubCounter;
  incrCounter() {
    this.counter++;
  }
  incrSubCounter(c: number) {
    this.subCounter.counter += c;
  }
  setSubCounter(c: number): void {
    this.subCounter.counter = c;
  }
  constructor(c: number) {
    this.id = nextId++;
    this.counter = c;
    this.subCounter = new SubCounter(c);
  }
}
@Component
struct CounterComp {
  @ObjectLink value: ParentCounter;
  build() {
    Column({ space: 10 }) {
      Text(`${this.value.counter}`)
        .fontSize(25)
        .onClick(() => {
          this.value.incrCounter();
        })
      Text(`${this.value.subCounter.counter}`)
        .onClick(() => {
          this.value.incrSubCounter(1);
        })
      Divider().height(2)
    }
  }
}
@Entry
@Component
struct ParentComp {
  @State counter: ParentCounter[] = [new ParentCounter(1), new ParentCounter(2), new ParentCounter(3)];
  build() {
    Row() {
      Column() {
        CounterComp({ value: this.counter[0] })
        CounterComp({ value: this.counter[1] })
        CounterComp({ value: this.counter[2] })
        Divider().height(5)
        ForEach(this.counter,
          (item: ParentCounter) => {
            CounterComp({ value: item })
          },
          (item: ParentCounter) => item.id.toString()
        )
        Divider().height(5)
        // 第一个点击事件
        Text('Parent: incr counter[0].counter')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter[0].incrCounter();
            // 每次触发时自增10
            this.counter[0].incrSubCounter(10);
          })
        // 第二个点击事件
        Text('Parent: set.counter to 10')
          .fontSize(20).height(50)
          .onClick(() => {
            // 无法将value设置为10，UI不会刷新
            this.counter[0].setSubCounter(10);
          })
        Text('Parent: reset entire counter')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter = [new ParentCounter(1), new ParentCounter(2), new ParentCounter(3)];
          })
      }
    }
  }
}
```

对于Text('Parent: incr counter[0].counter')的onClick事件，this.counter[0].incrSubCounter(10)调用incrSubCounter方法使SubCounter的counter值增加10，UI同步刷新。

但是，在Text('Parent: set.counter to 10')的onClick中调用this.counter[0].setSubCounter(10)，SubCounter的counter值却无法重置为10。

incrSubCounter和setSubCounter都是同一个SubCounter的函数。在第一个点击处理时调用incrSubCounter可以正确更新UI，而第二个点击处理调用setSubCounter时却没有更新UI。实际上incrSubCounter和setSubCounter两个函数都不能触发Text('${this.value.subCounter.counter}')的更新，因为\@ObjectLink value : ParentCounter仅能观察其代理ParentCounter的属性，对于this.value.subCounter.counter是SubCounter的属性，无法观察到嵌套类的属性。

但是，第一个click事件调用this.counter[0].incrCounter()将CounterComp自定义组件中\@ObjectLink value: ParentCounter标记为已更改。此时触发Text('${this.value.subCounter.counter}')的更新。 如果在第一个点击事件中删除this.counter[0].incrCounter()，也无法更新UI。

【正例】

对于上述问题，为了直接观察SubCounter中的属性，以便this.counter[0].setSubCounter(10)操作有效，可以利用下面的方法：


```ts
@ObjectLink value：ParentCounter = new ParentCounter(0);
@ObjectLink subValue：SubCounter = new SubCounter(0);
```

该方法使得\@ObjectLink分别代理了ParentCounter和SubCounter的属性，这样对于这两个类的属性的变化都可以观察到，即都会对UI视图进行刷新。即使删除了上面所说的this.counter[0].incrCounter()，UI也会进行正确的刷新。

该方法可用于实现“两个层级”的观察，即外部对象和内部嵌套对象的观察。但是该方法只能用于\@ObjectLink装饰器，无法作用于\@Prop（\@Prop通过深拷贝传入对象）。详情参考@Prop与@ObjectLink的差异。


```ts
let nextId = 1;

@Observed
class SubCounter {
  counter: number;

  constructor(c: number) {
    this.counter = c;
  }
}

@Observed
class ParentCounter {
  id: number;
  counter: number;
  subCounter: SubCounter;

  incrCounter() {
    this.counter++;
  }

  incrSubCounter(c: number) {
    this.subCounter.counter += c;
  }

  setSubCounter(c: number): void {
    this.subCounter.counter = c;
  }

  constructor(c: number) {
    this.id = nextId++;
    this.counter = c;
    this.subCounter = new SubCounter(c);
  }
}

@Component
struct CounterComp {
  @ObjectLink value: ParentCounter;

  build() {
    Column({ space: 10 }) {
      Text(`${this.value.counter}`)
        .fontSize(25)
        .onClick(() => {
          this.value.incrCounter();
        })
      CounterChild({ subValue: this.value.subCounter })
      Divider().height(2)
    }
  }
}

@Component
struct CounterChild {
  @ObjectLink subValue: SubCounter;

  build() {
    Text(`${this.subValue.counter}`)
      .onClick(() => {
        this.subValue.counter += 1;
      })
  }
}

@Entry
@Component
struct ParentComp {
  @State counter: ParentCounter[] = [new ParentCounter(1), new ParentCounter(2), new ParentCounter(3)];

  build() {
    Row() {
      Column() {
        CounterComp({ value: this.counter[0] })
        CounterComp({ value: this.counter[1] })
        CounterComp({ value: this.counter[2] })
        Divider().height(5)
        ForEach(this.counter,
          (item: ParentCounter) => {
            CounterComp({ value: item })
          },
          (item: ParentCounter) => item.id.toString()
        )
        Divider().height(5)
        Text('Parent: reset entire counter')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter = [new ParentCounter(1), new ParentCounter(2), new ParentCounter(3)];
          })
        Text('Parent: incr counter[0].counter')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter[0].incrCounter();
            this.counter[0].incrSubCounter(10);
          })
        Text('Parent: set.counter to 10')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter[0].setSubCounter(10);
          })
      }
    }
  }
}
```

### \@Prop与\@ObjectLink的差异

在下面的示例代码中，\@ObjectLink修饰的变量是对数据源的引用，即在this.value.subValue和this.subValue都是同一个对象的不同引用，所以在点击CounterComp的click handler，改变this.value.subCounter.counter，this.subValue.counter也会改变，对应的组件Text(`this.subValue.counter: ${this.subValue.counter}`)会刷新。


```ts
let nextId = 1;

@Observed
class SubCounter {
  counter: number;

  constructor(c: number) {
    this.counter = c;
  }
}

@Observed
class ParentCounter {
  id: number;
  counter: number;
  subCounter: SubCounter;

  incrCounter() {
    this.counter++;
  }

  incrSubCounter(c: number) {
    this.subCounter.counter += c;
  }

  setSubCounter(c: number): void {
    this.subCounter.counter = c;
  }

  constructor(c: number) {
    this.id = nextId++;
    this.counter = c;
    this.subCounter = new SubCounter(c);
  }
}

@Component
struct CounterComp {
  @ObjectLink value: ParentCounter;

  build() {
    Column({ space: 10 }) {
      CountChild({ subValue: this.value.subCounter })
      Text(`this.value.counter：increase 7 `)
        .fontSize(30)
        .onClick(() => {
          // click handler, Text(`this.subValue.counter: ${this.subValue.counter}`) will update
          this.value.incrSubCounter(7);
        })
      Divider().height(2)
    }
  }
}

@Component
struct CountChild {
  @ObjectLink subValue: SubCounter;

  build() {
    Text(`this.subValue.counter: ${this.subValue.counter}`)
      .fontSize(30)
  }
}

@Entry
@Component
struct ParentComp {
  @State counter: ParentCounter[] = [new ParentCounter(1), new ParentCounter(2), new ParentCounter(3)];

  build() {
    Row() {
      Column() {
        CounterComp({ value: this.counter[0] })
        CounterComp({ value: this.counter[1] })
        CounterComp({ value: this.counter[2] })
        Divider().height(5)
        ForEach(this.counter,
          (item: ParentCounter) => {
            CounterComp({ value: item })
          },
          (item: ParentCounter) => item.id.toString()
        )
        Divider().height(5)
        Text('Parent: reset entire counter')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter = [new ParentCounter(1), new ParentCounter(2), new ParentCounter(3)];
          })
        Text('Parent: incr counter[0].counter')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter[0].incrCounter();
            this.counter[0].incrSubCounter(10);
          })
        Text('Parent: set.counter to 10')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter[0].setSubCounter(10);
          })
      }
    }
  }
}
```

\@ObjectLink图示如下：

![zh-cn_image_0000001651665921](figures/zh-cn_image_0000001651665921.png)

【反例】

如果用\@Prop替代\@ObjectLink。点击第一个click handler，UI刷新正常。但是点击第二个onClick事件，\@Prop 对变量做了一个本地拷贝，CounterComp的第一个Text并不会刷新。

  this.value.subCounter和this.subValue并不是同一个对象。所以this.value.subCounter的改变，并没有改变this.subValue的拷贝对象，Text(`this.subValue.counter: ${this.subValue.counter}`)不会刷新。

```ts
@Component
struct CounterComp {
  @Prop value: ParentCounter = new ParentCounter(0);
  @Prop subValue: SubCounter = new SubCounter(0);
  build() {
    Column({ space: 10 }) {
      Text(`this.subValue.counter: ${this.subValue.counter}`)
        .fontSize(20)
        .onClick(() => {
          // 1st click handler
          this.subValue.counter += 7;
        })
      Text(`this.value.counter：increase 7 `)
        .fontSize(20)
        .onClick(() => {
          // 2nd click handler
          this.value.incrSubCounter(7);
        })
      Divider().height(2)
    }
  }
}
```

\@Prop拷贝的关系图示如下：

![zh-cn_image_0000001602146116](figures/zh-cn_image_0000001602146116.png)

【正例】

可以通过从ParentComp到CounterComp仅拷贝一份\@Prop value: ParentCounter，同时必须避免再多拷贝一份SubCounter。

- 在CounterComp组件中只使用一个\@Prop counter：Counter。

- 添加另一个子组件SubCounterComp，其中包含\@ObjectLink subCounter: SubCounter。此\@ObjectLink可确保观察到SubCounter对象属性更改，并且UI更新正常。

- \@ObjectLink subCounter: SubCounter与CounterComp中的\@Prop counter：Counter的this.counter.subCounter共享相同的SubCounter对象。

  

```ts
let nextId = 1;

@Observed
class SubCounter {
  counter: number;
  constructor(c: number) {
    this.counter = c;
  }
}

@Observed
class ParentCounter {
  id: number;
  counter: number;
  subCounter: SubCounter;
  incrCounter() {
    this.counter++;
  }
  incrSubCounter(c: number) {
    this.subCounter.counter += c;
  }
  setSubCounter(c: number): void {
    this.subCounter.counter = c;
  }
  constructor(c: number) {
    this.id = nextId++;
    this.counter = c;
    this.subCounter = new SubCounter(c);
  }
}

@Component
struct SubCounterComp {
  @ObjectLink subValue: SubCounter;
  build() {
    Text(`SubCounterComp: this.subValue.counter: ${this.subValue.counter}`)
      .onClick(() => {
        // 2nd click handler
        this.subValue.counter = 7;
      })
  }
}
@Component
struct CounterComp {
  @Prop value: ParentCounter;
  build() {
    Column({ space: 10 }) {
      Text(`this.value.incrCounter(): this.value.counter: ${this.value.counter}`)
        .fontSize(20)
        .onClick(() => {
          // 1st click handler
          this.value.incrCounter();
        })
      SubCounterComp({ subValue: this.value.subCounter })
      Text(`this.value.incrSubCounter()`)
        .onClick(() => {
          // 3rd click handler
          this.value.incrSubCounter(77);
        })
      Divider().height(2)
    }
  }
}
@Entry
@Component
struct ParentComp {
  @State counter: ParentCounter[] = [new ParentCounter(1), new ParentCounter(2), new ParentCounter(3)];
  build() {
    Row() {
      Column() {
        CounterComp({ value: this.counter[0] })
        CounterComp({ value: this.counter[1] })
        CounterComp({ value: this.counter[2] })
        Divider().height(5)
        ForEach(this.counter,
          (item: ParentCounter) => {
            CounterComp({ value: item })
          },
          (item: ParentCounter) => item.id.toString()
        )
        Divider().height(5)
        Text('Parent: reset entire counter')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter = [new ParentCounter(1), new ParentCounter(2), new ParentCounter(3)];
          })
        Text('Parent: incr counter[0].counter')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter[0].incrCounter();
            this.counter[0].incrSubCounter(10);
          })
        Text('Parent: set.counter to 10')
          .fontSize(20).height(50)
          .onClick(() => {
            this.counter[0].setSubCounter(10);
          })
      }
    }
  }
}
```


拷贝关系图示如下：


![zh-cn_image_0000001653949465](figures/zh-cn_image_0000001653949465.png)
