# \@Param：组件外部输入


为了增强子组件接受外部参数输入的能力，开发者可以使用\@Param装饰器。


\@Param不仅可以接受组件外部输入，还可以接受\@Local的同步变化。在阅读本文档前，建议提前阅读：[\@Local](./arkts-new-local.md)。

> **说明：**
>
> 从API version 12开始，在\@ComponentV2装饰的自定义组件中支持使用\@Param装饰器。
>

## 概述

\@Param表示组件从外部传入的状态，使得父子组件之间的数据能够进行同步：

- \@Param装饰的变量支持本地初始化，但是不允许在组件内部直接修改变量本身。

- 被\@Param装饰的变量能够在初始化自定义组件时从外部传入，当数据源也是状态变量时，数据源的修改会同步给\@Param。
- \@Param可以接受任意类型的数据源，包括普通变量、状态变量、常量、函数返回值等。
- \@Param装饰的变量变化时，会刷新该变量关联的组件。
- \@Param支持观测number、boolean、string、Object、class等基本类型以及Array、Set、Map、Date等内嵌类型。
- 对于复杂类型如类对象，\@Param会接受数据源的引用。在组件内可以修改类对象中的属性，该修改会同步到数据源。
- \@Param的观测能力仅限于被装饰的变量本身。当装饰简单类型时，对变量的整体改变能够观测到；当装饰对象类型时，仅能观测对象整体的改变；当装饰数组类型时，能观测到数组整体以及数组元素项的改变；当装饰Array、Set、Map、Date等内嵌类型时，可以观测到通过API调用带来的变化。详见[观察变化](#观察变化)。
- \@Param支持null、undefined以及联合类型。


## 状态管理V1版本接受外部传入的装饰器的局限性
状态管理V1存在多种可接受外部传入的装饰器，常用的有\@State、\@Prop、\@Link、\@ObjectLink。这些装饰器使用各有限制，不易区分，当使用不当时，还会导致性能问题。

```ts
@Observed
class Region {
  x: number;
  y: number;
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}
@Observed
class Info {
  region: Region;
  constructor(x: number, y: number) {
    this.region = new Region(x, y);
  }
}
@Entry
@Component
struct Index {
  @State info: Info = new Info(0, 0);
  
  build() {
    Column() {
      Button("change Info")
        .onClick(() => {
          this.info = new Info(100, 100);
      })
      Child({
        region: this.info.region,
        regionProp: this.info.region,
        infoProp: this.info,
        infoLink: this.info,
        infoState: this.info
      })
    }
  }
}
@Component
struct Child {
  @ObjectLink region: Region;
  @Prop regionProp: Region;
  @Prop infoProp: Info;
  @Link infoLink: Info;
  @State infoState: Info = new Info(1, 1);
  build() {
    Column() {
      Text(`ObjectLink region: ${this.region.x}-${this.region.y}`)
      Text(`Prop regionProp: ${this.regionProp.x}-${this.regionProp.y}`)
    }
  }
}
```

在上面的示例中，\@State仅能在初始化时获得info的引用，当改变info之后，无法进行同步。\@Prop虽然能够进行单向同步，但是对于较复杂的类型来说，深拷贝性能较差。\@Link能够接受传入的引用进行双向同步，但它必须要求数据源也是状态变量，因此无法接受info中的成员属性region。\@ObjectLink能够接受类成员属性，但是要求该属性类型必须为\@Observed装饰的类。装饰器的不同限制使得父子组件之间传值规则十分复杂，不易使用。因此推出\@Param装饰器表示组件从外部传入的状态。

## 装饰器说明

| \@Param变量装饰器  | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| 装饰器参数         | 无。                                                         |
| 能否本地修改       | 否，修改值需使用\@Event装饰器的能力。                        |
| 同步类型           | 由父到子单向同步。                                           |
| 允许装饰的变量类型 | Object、class、string、number、boolean、enum等基本类型以及Array、Date、Map、Set等内嵌类型。支持null、undefined以及联合类型。 |
| 被装饰变量的初始值 | 允许本地初始化，若不在本地初始化，则需要和\@Require装饰器一起使用，要求必须从外部传入初始化。 |

## 变量传递

| 传递规则       | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| 从父组件初始化 | \@Param装饰的变量允许本地初始化，若无本地初始化则必须从外部传入初始化。当同时存在本地初始值与外部传入值时，会优先使用外部传入值进行初始化。 |
| 初始化子组件   | \@Param装饰的变量可以初始化子组件中\@Param装饰的变量。       |
| 同步           | \@Param可以和父组件传入的状态变量数据源（即\@Local或\@Param装饰的变量）进行同步，当数据源发生变化时，会将修改同步给子组件的\@Param。 |

## 观察变化

使用\@Param装饰的变量具有被观测变化的能力。当装饰的变量发生变化时，会触发该变量绑定的UI组件刷新。

- 当装饰的变量类型为boolean、string、number类型时，可以观察来自数据源同步的变化。

  ```ts
  @Entry
  @ComponentV2
  struct Index {
    @Local count: number = 0;
    @Local message: string = "Hello";
    @Local flag: boolean = false;
    build() {
      Column() {
        Text(`Local ${this.count}`)
        Text(`Local ${this.message}`)
        Text(`Local ${this.flag}`)
        Button("change Local")
          .onClick(()=>{
            // 对数据源的更改会同步给子组件
            this.count++;
            this.message += " World";
            this.flag = !this.flag;
        })
        Child({
          count: this.count,
          message: this.message,
          flag: this.flag
        })
      }
    }
  }
  @ComponentV2
  struct Child {
    @Require @Param count: number;
    @Require @Param message: string;
    @Require @Param flag: boolean;
    build() {
      Column() {
        Text(`Param ${this.count}`)
        Text(`Param ${this.message}`)
        Text(`Param ${this.flag}`)
      }
    }
  }
  ```

- 当装饰的变量类型为类对象时，仅可以观察到对类对象整体赋值的变化，无法直接观察到对类成员属性赋值的变化,对类成员属性的观察依赖\@ObservedV2和\@Trace装饰器。

  ```ts
  class RawObject {
    name: string;
    constructor(name: string) {
      this.name = name;
    }
  }
  @ObservedV2
  class ObservedObject {
    @Trace name: string;
    constructor(name: string) {
      this.name = name;
    }
  }
  @Entry
  @ComponentV2
  struct Index {
    @Local rawObject: RawObject = new RawObject("rawObject");
    @Local observedObject: ObservedObject = new ObservedObject("observedObject");
    build() {
      Column() {
        Text(`${this.rawObject.name}`)
        Text(`${this.observedObject.name}`)
        Button("change object")
          .onClick(() => {
            // 对类对象整体的修改均能观察到
            this.rawObject = new RawObject("new rawObject");
            this.observedObject = new ObservedObject("new observedObject");
        })
        Button("change name")
          .onClick(() => {
            // @Local与@Param均不具备观察类对象属性的能力，因此对rawObject.name的修改无法观察到
            this.rawObject.name = "new rawObject name";
            // 由于ObservedObject的name属性被@Trace装饰，因此对observedObject.name的修改能被观察到
            this.observedObject.name = "new observedObject name";
        })
        Child({
          rawObject: this.rawObject,
          observedObject: this.observedObject
        })
      }
    }
  }
  @ComponentV2
  struct Child {
    @Require @Param rawObject: RawObject;
    @Require @Param observedObject: ObservedObject;
    build() {
      Column() {
        Text(`${this.rawObject.name}`)
        Text(`${this.observedObject.name}`)
      }
    }
    
  }
  ```

- 当装饰的变量类型为简单类型的数组时，可以观察到数组整体或数组项的变化。

  ```ts
  @Entry
  @ComponentV2
  struct Index {
    @Local numArr: number[] = [1,2,3,4,5];
    @Local dimensionTwo: number[][] = [[1,2,3],[4,5,6]];
    
    build() {
      Column() {
        Text(`${this.numArr[0]}`)
        Text(`${this.numArr[1]}`)
        Text(`${this.numArr[2]}`)
        Text(`${this.dimensionTwo[0][0]}`)
        Text(`${this.dimensionTwo[1][1]}`)
        Button("change array item")
          .onClick(() => {
            this.numArr[0]++;
            this.numArr[1] += 2;
            this.dimensionTwo[0][0] = 0;
            this.dimensionTwo[1][1] = 0;
          })
        Button("change whole array")
          .onClick(() => {
            this.numArr = [5,4,3,2,1];
            this.dimensionTwo = [[7,8,9],[0,1,2]];
          })
        Child({
          numArr: this.numArr,
          dimensionTwo: this.dimensionTwo
        })
      }
    }
  }
  @ComponentV2
  struct Child {
    @Require @Param numArr: number[];
    @Require @Param dimensionTwo: number[][];
    
    build() {
      Column() {
        Text(`${this.numArr[0]}`)
        Text(`${this.numArr[1]}`)
        Text(`${this.numArr[2]}`)
        Text(`${this.dimensionTwo[0][0]}`)
        Text(`${this.dimensionTwo[1][1]}`)
      }
    }
  }
  ```

- 当装饰的变量是嵌套类或对象数组时，\@Param无法观察深层对象属性的变化。对深层对象属性的观测依赖\@ObservedV2与\@Trace装饰器。

  ```ts
  @ObservedV2
  class Region {
    @Trace x: number;
    @Trace y: number;
    constructor(x: number, y: number) {
      this.x = x;
      this.y = y;
    }
  }
  @ObservedV2
  class Info {
    @Trace region: Region;
    @Trace name: string;
    constructor(name: string, x: number, y: number) {
      this.name = name;
      this.region = new Region(x, y);
    }
  }
  @Entry
  @ComponentV2
  struct Index {
    @Local infoArr: Info[] = [new Info("Ocean", 28, 120), new Info("Mountain", 26, 20)];
    @Local originInfo: Info = new Info("Origin", 0, 0);
    build() {
      Column() {
        ForEach(this.infoArr, (info: Info) => {
          Row() {
            Text(`name: ${info.name}`)
            Text(`region: ${info.region.x}-${info.region.y}`)
          }
        })
        Row() {
          Text(`Origin name: ${this.originInfo.name}`)
          Text(`Origin region: ${this.originInfo.region.x}-${this.originInfo.region.y}`)
        }
        Button("change infoArr item")
          .onClick(() => {
            // 由于属性name被@Trace装饰，所以能够观察到
            this.infoArr[0].name = "Win";
          })
        Button("change originInfo")
          .onClick(() => {
            // 由于变量originInfo被@Local装饰，所以能够观察到
            this.originInfo = new Info("Origin", 100, 100);
          })
        Button("change originInfo region")
          .onClick(() => {
            // 由于属性x、y被@Trace装饰，所以能够观察到
            this.originInfo.region.x = 25;
            this.originInfo.region.y = 25;
          })
      }
    }
  }
  @ComponentV2
  struct Child {
    @Param infoArr: Info[] = [];
    @Param originInfo: Info = new Info("O", 0, 0);
  
    build() {
      Column() {
        ForEach(this.infoArr, (info: Info) => {
          Row() {
            Text(`name: ${info.name}`)
            Text(`region: ${info.region.x}-${info.region.y}`)
          }
        })
        Row() {
          Text(`Origin name: ${this.originInfo.name}`)
          Text(`Origin region: ${this.originInfo.region.x}-${this.originInfo.region.y}`)
        }
      }
    }
  }
  ```

- 当装饰的变量类型是内置类型时，可以观察到变量整体赋值以及通过API调用带来的变化。

  | 类型  | 可观测变化的API                                              |
  | ----- | ------------------------------------------------------------ |
  | Array | push、pop、shift、unshift、splice、copyWithin、fill、reverse、sort |
  | Date  | setFullYear, setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setUTCFullYear, setUTCMonth, setUTCDate, setUTCHours, setUTCMinutes, setUTCSeconds, setUTCMilliseconds |
  | Map   | set, clear, delete                                           |
  | Set   | add, clear, delete                                           |

## 限制条件

\@Param装饰器存在以下使用限制：

- \@Param装饰器只能在\@ComponentV2装饰器的自定义组件中使用。

  ```ts
  @ComponentV2
  struct MyComponent {
    @Param message: string = "Hello World"; // 正确用法
    build() {
    }
  }
  @Component
  struct TestComponent {
    @Param message: string = "Hello World"; // 错误用法，编译时报错
    build() {
    }
  }
  ```

- \@Param装饰的变量表示组件外部输入，需要被初始化。支持使用本地初始值做初始化。当存在外部传入值时，将优先使用外部传入的值初始化。既不使用本地初始值，也不使用外部传入值是不允许的。

  ```ts
  @ComponentV2
  struct ChildComponent {
    @Param param1: string = "Initialize local";
    @Param param2: string = "Initialize local and put in";
    @Require @Param param3: string;
    @Param param4: string; // 错误用法，外部未传入初始化且本地也无初始值，编译报错
    build() {
      Column() {
        Text(`${this.param1}`) // 本地初始化，显示Initialize local
        Text(`${this.param2}`) // 外部传入初始化，显示Put in
        Text(`${this.param3}`) // 外部传入初始化，显示Put in
      }
    }
  }
  @Entry
  @ComponentV2
  struct MyComponent {
    @Local message: string = "Put in";
    build() {
      Column() {
        ChildComponent({
          param2: this.message,
          param3: this.message
        })
      }
    }
  }
  ```

- \@Param装饰的变量在子组件中无法进行修改。但当装饰的变量类型为对象时，在子组件中修改对象中属性是允许的。

  ```ts
  @ObservedV2
  class Info {
    @Trace name: string;
    constructor(name: string) {
      this.name = name;
    }
  }
  @Entry
  @ComponentV2
  struct Index {
    @Local info: Info = new Info("Tom");
    build() {
      Column() {
        Text(`Parent info.name ${this.info.name}`)
        Button("Parent change info")
          .onClick(() => {
            this.info = new Info("Lucy"); // 父组件更改@Local变量，会同步子组件对应@Param变量
        })
        Child({ info: this.info })
      }
    }
  }
  @ComponentV2
  struct Child {
    @Require @Param info: Info;
    build() {
      Column() {
        Text(`info.name: ${this.info.name}`)
        Button("change info")
          .onClick(() => {
            this.info = new Info("Jack"); //错误用法，不允许在子组件更改@Param变量，编译时报错
          })
        Button("Child change info.name")
          .onClick(() => {
            this.info.name = "Jack"; // 允许在子组件中更改对象中属性
          })
      }
    }
  }
  ```

## 使用场景

### 从父组件到子组件变量传递与同步

\@Param能够接受父组件\@Local或\@Param传递的数据并与之变化同步。

```ts
@ObservedV2
class Region {
  @Trace x: number;
  @Trace y: number;
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  }
}
@ObservedV2
class Info {
  @Trace name: string;
  @Trace age: number;
  @Trace region: Region;
  constructor(name: string, age: number, x: number, y: number) {
    this.name = name;
    this.age = age;
    this.region = new Region(x, y);
  }
}
@Entry
@ComponentV2
struct Index {
  @Local infoList: Info[] = [new Info("Alice", 8, 0, 0), new Info("Barry", 10, 1, 20), new Info("Cindy", 18, 24, 40)];
  build() {
    Column() {
      ForEach(this.infoList, (info: Info) => {
        MiddleComponent({ info: info })
      })
      Button("change")
        .onClick(() => {
          this.infoList[0] = new Info("Atom", 40, 27, 90);
          this.infoList[1].name = "Bob";
          this.infoList[2].region = new Region(7, 9);
        })
    }
  }
}
@ComponentV2
struct MiddleComponent {
  @Require @Param info: Info;
  build() {
    Column() {
      Text(`name: ${this.info.name}`)
      Text(`age: ${this.info.age}`)
      SubComponent({ region: this.info.region })
    }
  }
}
@ComponentV2
struct SubComponent {
  @Require @Param region: Region;
  build() {
    Column() {
      Text(`region: ${this.region.x}-${this.region.y}`)
    }
  }
}
```

### 装饰Date类型变量

\@Param装饰Date类型变量，可以观察到数据源对Date整体的赋值，以及调用Date的接口`setFullYear`, `setMonth`, `setDate`, `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, `setUTCFullYear`, `setUTCMonth`, `setUTCDate`, `setUTCHours`, `setUTCMinutes`, `setUTCSeconds`, `setUTCMilliseconds` 带来的变化。

```ts
@ComponentV2
struct DateComponent {
  @Param selectedDate: Date = new Date('2024-01-01');

  build() {
    Column() {
      DatePicker({
        start: new Date('1970-1-1'),
        end: new Date('2100-1-1'),
        selected: this.selectedDate
      })
    }
  }
}

@Entry
@ComponentV2
struct ParentComponent {
  @Local parentSelectedDate: Date = new Date('2021-08-08');

  build() {
    Column() {
      Button('parent update the new date')
        .margin(10)
        .onClick(() => {
          this.parentSelectedDate = new Date('2023-07-07')
        })
      Button('increase the year by 1')
        .margin(10)
        .onClick(() => {
        this.parentSelectedDate.setFullYear(this.parentSelectedDate.getFullYear() + 1)
        })
      Button('increase the month by 1')
        .margin(10)
        .onClick(() => {
        this.parentSelectedDate.setMonth(this.parentSelectedDate.getMonth() + 1)
        })
      Button('parent increase the day by 1')
        .margin(10)
        .onClick(() => {
   this.parentSelectedDate.setDate(this.parentSelectedDate.getDate() + 1)
        })
      DateComponent({ selectedDate: this.parentSelectedDate })
    }
  }
}
```

### 装饰Map类型变量

\@Param装饰Map类型变量，可以观察到数据源对Map整体的赋值，以及调用Map的接口 set、clear、delete带来的变化。

```ts
@ComponentV2
struct Child {
  @Param value: Map<number, string> = new Map()

  build() {
    Column() {
      ForEach(Array.from(this.value.entries()), (item: [number, string]) => {
        Text(`${item[0]}`).fontSize(30)
        Text(`${item[1]}`).fontSize(30)
        Divider()
      })
    }
  }
}
@Entry
@ComponentV2
struct MapSample2 {
  @Local message: Map<number, string> = new Map([[0, "a"], [1, "b"], [3, "c"]])

  build() {
    Row() {
      Column() {
        Child({ value: this.message })
        Button('init map').onClick(() => {
          this.message = new Map([[0, "a"], [1, "b"], [3, "c"]])
        })
        Button('set new one').onClick(() => {
          this.message.set(4, "d")
        })
        Button('clear').onClick(() => {
          this.message.clear()
        })
        Button('replace the first one').onClick(() => {
          this.message.set(0, "aa")
        })
        Button('delete the first one').onClick(() => {
          this.message.delete(0)
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### 装饰Set类型变量

\@Param装饰Set类型变量，可以观察到数据源对Set整体的赋值，以及调用Set的接口 add、clear、delete带来的变化。

```ts
@ComponentV2
struct Child {
  @Param message: Set<number> = new Set()

  build() {
    Column() {
      ForEach(Array.from(this.message.entries()), (item: [number, string]) => {
        Text(`${item[0]}`).fontSize(30)
        Divider()
      })
    }
    .width('100%')
  }
}
@Entry
@ComponentV2
struct SetSample11 {
  @Local message: Set<number> = new Set([0, 1, 2, 3, 4])

  build() {
    Row() {
      Column() {
        Child({ message: this.message })
        Button('init set').onClick(() => {
          this.message = new Set([0, 1, 2, 3, 4])
        })
        Button('set new one').onClick(() => {
          this.message.add(5)
        })
        Button('clear').onClick(() => {
          this.message.clear()
        })
        Button('delete the first one').onClick(() => {
          this.message.delete(0)
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### 联合类型

\@Param支持null、undefined以及联合类型。在下面的示例中，count类型为number | undefined，点击改变count的类型，UI会随之刷新。

```ts
@Entry
@ComponentV2
struct Index {
  @Local count: number | undefined = 0;

  build() {
    Column() {
      MyComponent({ count: this.count })
      Button('change')
        .onClick(() => {
          this.count = undefined;
        })
    }
  }
}

@ComponentV2
struct MyComponent {
  @Param count: number | undefined = 0;

  build() {
    Column() {
      Text(`count(${this.count})`)
    }
  }
}
```