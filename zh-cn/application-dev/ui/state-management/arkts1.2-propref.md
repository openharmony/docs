# @PropRef装饰器：父子单向同步

\@PropRef装饰的变量可以和父组件建立单向同步。\@PropRef装饰的变量允许在本地修改，但修改后的变化不会同步回父组件中。

> **说明：**
>
> 从API version 20开始，该装饰器仅支持在ArkTS 1.2上使用。

## 概述

\@PropRef提供了对标ArkTS 1.1上\@Prop的单向同步的能力。相比\@Prop，\@PropRef移除了自动深拷贝的功能，仅直接获得数据源的单向引用。该单向引用含义为：

- \@PropRef装饰的变量允许本地修改，该修改不会同步回父组件。由于获得了数据源的引用，当数据源为对象类型时，修改\@PropRef装饰对象的属性仍会在父组件中体现。
- 当数据源更改时，\@PropRef装饰的变量会被数据源更新，本地所做的修改会被覆盖为数据源的最新值。

## 装饰器说明

| \@PropRef变量装饰器 | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| 装饰器参数          | 无。                                                         |
| 能否本地修改        | 能，且本地修改不会同步回父组件。                             |
| 同步类型            | 由父组件到子组件单向同步。                                   |
| 允许装饰的变量类型  | Object、class、string、number、boolean、enum、interface等基本类型以及[Array](#装饰array类型)、[Date](#装饰date类型)、[Map](#装饰map类型)、[Set](#装饰Set类型)等内嵌类型。支持null、undefined以及联合类型。 |
| 被装饰变量的初始值  | 允许本地初始化，也可以从外部传入。                           |

## 变量传递

| 传递规则       | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| 从父组件初始化 | \@PropRef装饰的变量允许本地初始化，若无本地初始化则必须从外部传入初始化。当同时存在本地初始值与外部传入值时，优先使用外部传入值进行初始化。 |
| 初始化子组件   | \@PropRef装饰的变量可以初始化子组件中\@State/\@PropRef/\@Link/\@Provide装饰的变量。 |
| 同步           | \@PropRef与父组件的状态变量数据源同步，数据源变化时会更新子组件的\@PropRef。 |

## 观察变化

使用\@PropRef装饰的变量具有被观测变化的能力。当这些变量发生变化时，会触发绑定到该变量的UI组件刷新。

- 当装饰的变量为boolean、string、number等类型时，数据源的变化可以被同步观察到。

  ```ts
  import { Entry, Component, Column, Text, Button, ClickEvent } from '@ohos.arkui.component';
  import { State, PropRef } from '@ohos.arkui.stateManagement';
  @Entry
  @Component
  struct Index {
    @State count: number = 0;
    @State message: string = 'Hello';
    @State flag: boolean = false;
    build() {
      Column() {
        Text(`State ${this.count}`)
        Text(`State ${this.message}`)
        Text(`State ${this.flag}`)
        Button('change State')
          .onClick((e: ClickEvent) => {
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
  @Component
  struct Child {
    @PropRef count: number;
    @PropRef message: string;
    @PropRef flag: boolean;
    build() {
      Column() {
        Text(`PropRef ${this.count}`)
        Text(`PropRef ${this.message}`)
        Text(`PropRef ${this.flag}`)
        Button('change PropRef')
          .onClick((e: ClickEvent) => {
            this.count++;
            this.message += '!';
            this.flag = !this.flag;
          })
      }
    }
  }
  ```

- 装饰的变量为内置类型时，可观察变量整体赋值和API调用的变化。

  | 类型  | 可观测变化的API                                              |
  | ----- | ------------------------------------------------------------ |
  | Array | push、pop、shift、unshift、splice、copyWithin、fill、reverse、sort |
  | Date  | setFullYear, setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setUTCFullYear, setUTCMonth, setUTCDate, setUTCHours, setUTCMinutes, setUTCSeconds, setUTCMilliseconds |
  | Map   | set, clear, delete                                           |
  | Set   | add, clear, delete                                           |

## 限制条件

\@PropRef接收外部传入时，不能接收undefined类型：

- 若初始化时传入undefined类型，该值将不会生效，而是使用本地的默认值。
- 若从数据源更新时传入undefined，则本次从数据源的更新不会生效。

## 使用场景

### 从父组件到子组件变量变化单向同步

\@PropRef能够接收父组件传递的数据源，并与之单向同步变化。

```ts
import { Entry, Component, Column, Text, Button, ClickEvent } from '@ohos.arkui.component';
import { State, PropRef } from '@ohos.arkui.stateManagement';
@Entry
@Component
struct Index {
  @State count: number = 0;
  @State message: string = 'Hello';
  @State flag: boolean = false;
  build() {
    Column() {
      Text(`State ${this.count}`)
      Text(`State ${this.message}`)
      Text(`State ${this.flag}`)
      Button('change State')
        .onClick((e: ClickEvent) => {
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
@Component
struct Child {
  @PropRef count: number;
  @PropRef message: string;
  @PropRef flag: boolean;
  build() {
    Column() {
      Text(`PropRef ${this.count}`)
      Text(`PropRef ${this.message}`)
      Text(`PropRef ${this.flag}`)
      Button('change PropRef')
        .onClick((e: ClickEvent) => {
          this.count++;
          this.message += '!';
          this.flag = !this.flag;
        })
    }
  }
}
```

### 装饰Array类型

当使用\@PropRef装饰数组类型时，可以观察到数组整体及其元素的变化。通过API操作更改数组内容也能被观测到。

```ts
import { Entry, Component, Column, Text, Button, ClickEvent } from '@ohos.arkui.component';
import { State, PropRef } from '@ohos.arkui.stateManagement';
@Entry
@Component
struct Index {
  @State arr: int[] = [0, 1, 2];
  build() {
    Column() {
      Child({ arr: this.arr })
    }
  }
}
@Component
struct Child {
  @PropRef arr: int[];
  build() {
    Column() {
      Text(`${this.arr}`)
      Button(`change arr[0]: ${this.arr[0]}`).onClick((e: ClickEvent) => {
          this.arr[0]++;
      })
      Button(`push item: ${this.arr.length}`).onClick((e: ClickEvent) => {
          this.arr.push(this.arr.length);
      })
    }
  }
}
```

### 装饰Map类型

使用\@PropRef装饰Map类型时，可以观察到Map整体及其API操作带来的变化。

```ts
import { Entry, Component, Column, Text, Button, ClickEvent } from '@ohos.arkui.component';
import { State, PropRef } from '@ohos.arkui.stateManagement';
@Entry
@Component
struct Index {
  @State map: Map<int, int> = new Map<int, int>([[0, 0], [1, 1], [2, 2]]);
  build() {
    Column() {
      Child({ map: this.map })
    }
  }
}
@Component
struct Child {
  @PropRef map: Map<int, int>;
  build() {
    Column() {
      Text(`${this.map}`)
      Button(`change map[0]: ${this.arr.get(0)}`).onClick((e: ClickEvent) => {
          this.arr[0]++;
      })
      Button(`add item: ${this.map.size}`).onClick((e: ClickEvent) => {
          this.arr.set(this.map.size, this.map.size);
      })
    }
  }
}
```

### 装饰Set类型

使用\@PropRef装饰Set类型时，可以观察到Set整体以及API操作带来的变化。

```ts
import { Entry, Component, Column, Text, Button, ClickEvent } from '@ohos.arkui.component';
import { State, PropRef } from '@ohos.arkui.stateManagement';
@Entry
@Component
struct Index {
  @State set: Set<int> = new Set<int>([0, 1, 2, 3, 4]);
  build() {
    Column() {
      Child({ set: this.set })
    }
  }
}
@Component
struct Child {
  @PropRef set: Set<int>;
  build() {
    Column() {
      Text(`${this.set}`)
      Button('init set').onClick((e: ClickEvent) => {
        this.set = new Set([0, 1, 2, 3, 4]);
      })
      Button('set new one').onClick((e: ClickEvent) => {
        this.set.add(5);
      })
      Button('clear').onClick((e: ClickEvent) => {
        this.set.clear();
      })
      Button('delete the first one').onClick((e: ClickEvent) => {
        this.set.delete(0);
      })
    }
  }
}
```

### 装饰Date类型

使用\@PropRef装饰Date类型时，可以观察到Date整体及其API操作的变化。

```ts
import { Entry, Component, Column, Text, Button, ClickEvent } from '@ohos.arkui.component';
import { State, PropRef } from '@ohos.arkui.stateManagement';
@Entry
@Component
struct Index {
  @State date: Date = new Date('2021-08-08');
  build() {
    Column() {
      Child({ date: this.date })
    }
  }
}
@Component
struct Child {
  @PropRef date: Date;
  build() {
    Column() {
      Text(`${this.date}`)
      Button(`change update`).onClick((e: ClickEvent) => {
        this.date = new Date('2023-09-09');
      })
      Button('increase the year by 1').onClick((e: ClickEvent) => {
        this.date.setFullYear(this.date.getFullYear() + 1);
      })
      Button('increase the month by 1').onClick((e: ClickEvent) => {
        this.date.setMonth(this.date.getMonth() + 1);
      })
      Button('parent increase the day by 1').onClick((e: ClickEvent) => {
        this.date.setDate(this.date.getDate() + 1);
      })
    }
  }
}
```