# \@Link装饰器：父子双向同步

@Link装饰的变量与外部传入的状态变量数据源建立双向同步。

## 概述

\@Link获取外部传入状态变量数据源的引用，当数据源改变时，@Link能够感知到变化，触发绑定的UI组件刷新。同时，@Link修改时，数据源处也能感知到变化，触发数据源绑定的UI组件刷新。

在静态语言上下文中使用时，需要导入装饰器：

```ts
import { Link } from '@ohos.arkui.stateManagement';
```

## 装饰器说明

| \@Link变量装饰器   | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| 装饰器参数         | 无。                                                         |
| 允许装饰的变量类型  | 支持Object、class、string、number、boolean、enum、interface等基本类型。<br/>支持Array、Date、Map、Set等内嵌类型。<br/>支持null、undefined以及联合类型。 |
| 初始化规则         | 禁止本地初始化。使用父组件传入的变量进行初始化。                                         |
| 同步规则           | **在子组件使用时：**<br/>与父组件\@State、\@Link、\@PropRef、\@Provide、\@Consume、\@ObjectLink、\@StorageLink、\@StoragePropRef、\@LocalStorageLink和\@LocalStoragePropRef建立双向绑定。允许父组件中\@State、\@Link、\@PropRef、\@Provide、\@Consume、\@ObjectLink、\@StorageLink、\@StoragePropRef、\@LocalStorageLink和\@LocalStoragePropRef装饰变量初始化子组件\@Link。<br/>**在父组件使用时：**<br/>可用于初始化常规变量、\@State、\@Link、\@PropRef、\@Provide。 |

## 观察变化和行为表现

- 当装饰的数据类型为boolean、string、number时，可以同步观察到数值的变化，示例请参考[装饰简单类型变量](#装饰简单类型变量)。

- 当装饰的数据类型为class或者Object时，对对象属性的观测需要借助\@Observed与\@Track实现，单独的\@Link无法再观测对象的属性变化，仅能观测对象整体的赋值。

- 当装饰的对象是Array时，可以观察到数组添加、删除、更新数组单元的变化，示例请参考[装饰数组类型变量](#装饰数组类型变量)。

- 当装饰的对象是Date时，可以观察到Date的整体赋值，以及通过调用`setFullYear`, `setMonth`, `setDate`, `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, `setUTCFullYear`, `setUTCMonth`, `setUTCDate`, `setUTCHours`, `setUTCMinutes`, `setUTCSeconds`, `setUTCMilliseconds`方法更新其属性。

  ```ts
  import { Entry, Component, Column, Button, ClickEvent, Text } from '@ohos.arkui.component';
  import { State, Link } from '@ohos.arkui.stateManagement';
  
  @Component
  struct DateComponent {
    @Link selectedDate: Date;
  
    build() {
      Column() {
        Text(`${this.selectedDate}`)
        Button('child increase the year by 1')
          .onClick((e: ClickEvent) => {
            this.selectedDate.setFullYear(this.selectedDate.getFullYear() + 1);
          })
        Button('child increace the day by 1')
          .onClick((e: ClickEvent) => {
            this.selectedDate.setDate(this.selectedDate.getDate() + 1);
          })
        Button('child update the new date')
          .onClick((e: ClickEvent) => {
            this.selectedDate = new Date('2023-09-09');
          })
      }
    }
  }
  @Entry
  @Component
  struct ParentComponent {
    @State parentSelectedDate: Date = new Date('2021-08-08');
  
    build() {
      Column() {
        Text(`${this.parentSelectedDate}`)
        Button('parent increase the month by 1')
          .onClick((e: ClickEvent) => {
            this.parentSelectedDate.setMonth(this.parentSelectedDate.getMonth() + 1);
          })
        Button('parent update the new date')
          .onClick((e: ClickEvent) => {
            this.parentSelectedDate = new Date('2023-07-07');
          })
        DateComponent({ selectedDate:this.parentSelectedDate })
      }
    }
  }
  ```

- 当装饰的变量是Map时，可以观察到Map整体的赋值，以及通过调用Map的`set`、`clear`、`delete`接口更新Map的值。详见[装饰Map类型变量](#装饰map类型变量)。

- 当装饰的变量是Set时，可以观察Set整体的赋值，以及通过调用Set的`add`、`clear`、`delete`接口更新其值。详见[装饰Set类型变量](#装饰set类型变量)。

- 当装饰interface字面量类型时，可以观察到字面量整体及其属性的变化。

  ```ts
  import { Entry, Component, Column, Text, ClickEvent } from '@ohos.arkui.component';
  import { State, Link } from '@ohos.arkui.stateManagement';
  
  interface Info {
    name: string;
    age: number;
  }
  
  @Component
  struct Child {
    @Link info: Info;
    build() {
      Column() {
        Text(`Child info.name: ${this.info.name}`)
          .onClick((e: ClickEvent) => {
            this.info.name = 'Jerry';
          })
      }
    }
  }
  
  @Entry
  @Component
  struct Parent {
    // 装饰字面量
    @State info: Info = { name: 'Bob', age: 22 } as Info;
    build() {
      Column() {
        Text(`Parent info.name: ${this.info.name}`)
          .onClick((e: ClickEvent) => {
            this.info.name = 'Tom';
          })
        Child({info: this.info})
      }
    }
  }
  ```
  
## 限制条件

1. \@Link装饰器不能在\@Entry装饰的自定义组件中使用。
2. \@Link装饰的变量禁止在本地初始化，否则编译期会报错。

    ```ts
    // 错误写法，编译报错
    @Link count: number = 10;
    
    // 正确写法
    @Link count: number;
    ```

3. \@Link装饰的状态变量的类型要和数据源的类型保持一致，否则编译期会报错。

    【反例】

    ```ts
    import { Entry, Component, Column, Text } from '@ohos.arkui.component';
    import { State, Link } from '@ohos.arkui.stateManagement';
    
    class Info {
      info: string = 'Hello';
    }
    
    class Cousin {
      name: string = 'Hello';
    }
    
    @Component
    struct Child {
      // 错误写法，@Link与@State数据源类型不一致
      @Link test: Cousin;
    
      build() {
        Text(this.test.name)
      }
    }
    
    @Entry
    @Component
    struct LinkExample {
      @State info: Info = new Info();
    
      build() {
        Column() {
          // 错误写法，@Link与@State数据源类型不一致
          Child({test: this.info})
        }
      }
    }
    ```

    【正例】

    ```ts
    import { Entry, Component, Column, Text } from '@ohos.arkui.component';
    import { State, Link } from '@ohos.arkui.stateManagement';
    
    class Info {
      info: string = 'Hello';
    }
    
    @Component
    struct Child {
      // 正确写法
      @Link test: Info;
    
      build() {
        Text(this.test.info)
      }
    }
    
    @Entry
    @Component
    struct LinkExample {
      @State info: Info = new Info();
    
      build() {
        Column() {
          // 正确写法
          Child({test: this.info})
        }
      }
    }
    ```

4. \@Link装饰的状态变量仅能被状态变量初始化，不能使用常规变量初始化，否则编译期会给出告警，并在运行时崩溃。

    【反例】
  
    ```ts
    import { Entry, Component, Column, Text } from '@ohos.arkui.component';
    import { State, Link } from '@ohos.arkui.stateManagement';
    
    class Info {
      info: string = 'Hello';
    }
    
    @Component
    struct Child {
      @Link msg: string;
      @Link info: string;
    
      build() {
        Text(this.msg + this.info)
      }
    }
    
    @Entry
    @Component
    struct LinkExample {
      @State message: string = 'Hello';
      @State info: Info = new Info();
    
      build() {
        Column() {
          // 错误写法，常规变量不能初始化@Link
          Child({msg: 'World', info: this.info.info})
        }
      }
    }
    ```
    
    【正例】
    
    ```ts
    import { Entry, Component, Column, Text } from '@ohos.arkui.component';
    import { State, Link } from '@ohos.arkui.stateManagement';
    
    class Info {
      info: string = 'Hello';
    }
    
    @Component
    struct Child {
      @Link msg: string;
      @Link info: Info;
    
      build() {
        Text(this.msg + this.info.info)
      }
    }
    
    @Entry
    @Component
    struct LinkExample {
      @State message: string = 'Hello';
      @State info: Info = new Info();
    
      build() {
        Column() {
          // 正确写法
          Child({msg: this.message, info: this.info})
        }
      }
    }
    ```
    
## 使用场景

### 装饰简单类型变量

当装饰的数据类型为boolean、string、number时，可以同步观察到数值的变化。

```ts
import { Entry, Component, Column, Button, ClickEvent, Text } from '@ohos.arkui.component';
import { State, Link } from '@ohos.arkui.stateManagement';

@Component
struct Child {
  @Link count: number;
  @Link str: string;
  @Link flag: boolean;

  build() {
    Column() {
      Text(`${this.count}`)
      Text(`${this.str}`)
      Text(`${this.flag}`)
      Button('Child change count').onClick((e: ClickEvent) => {
        this.count += 2;
      })
      Button('Child change str').onClick((e: ClickEvent) => {
        this.str += '*';
      })
      Button('Child change flag').onClick((e: ClickEvent) => {
        this.flag = !this.flag;
      })
    }
  }
}

@Entry
@Component
struct Index {
  @State count: number = 0;
  @State str: string = 'Tom';
  @State flag: boolean = true;

  build() {
    Column() {
      Child({count: this.count, str: this.str, flag: this.flag})
      Button('Parent change count').onClick((e: ClickEvent) => {
        this.count++;
      })
      Button('Parent change str').onClick((e: ClickEvent) => {
        this.str += '~';
      })
      Button('Parent change flag').onClick((e: ClickEvent) => {
        this.flag = !this.flag;
      })
    }
  }
}
```

### 装饰数组类型变量

当装饰数组时，可以观察到数组整体和数组项的变化，同时可以通过调用Array的接口 `push`、`pop`、`shift`、`unshift`、`splice`、`copyWithin`、`fill`、`reverse`、`sort`更新Array的数据。

```ts
import { Entry, Component, Column, Button, ClickEvent, ForEach, Text } from '@ohos.arkui.component';
import { State, Link } from '@ohos.arkui.stateManagement';
@Component
struct Child {
  @Link items: number[];

  build() {
    Column() {
      Button(`Button1: push`)
        .onClick((e: ClickEvent) => {
          this.items.push(this.items.length + 1);
        })
      Button(`Button2: replace whole item`)
        .onClick((e: ClickEvent) => {
          this.items = [100, 200, 300];
        })
    }
  }
}

@Entry
@Component
struct Parent {
  @State arr: number[] = [1.0, 2.0, 3.0];

  build() {
    Column() {
      Child({ items: this.arr })
      ForEach(this.arr,
        (item: number) => {
          Text(`${item}`)
        })
    }
  }
}
```

### 装饰Map类型变量

在下面的示例中，message类型为Map\<number, string\>，点击Button改变message的值，视图会随之刷新。

```ts
import { Entry, Component, Row, Column, Button, ClickEvent, ForEach, Text, Divider } from '@ohos.arkui.component';
import { State, Link } from '@ohos.arkui.stateManagement';
@Component
struct Child {
  @Link value: Map<number, string>;

  build() {
    Column() {
      ForEach(Array.from(this.value.entries()), (item: [number, string]) => {
        Text(`${item[0]}`).fontSize(30)
        Text(`${item[1]}`).fontSize(30)
        Divider()
      })
      Button('child replace the first one').onClick((e: ClickEvent) => {
        this.value.set(0, 'aa');
      })
      Button('child delete the first one').onClick((e: ClickEvent) => {
        this.value.delete(0);
      })
    }
  }
}

@Entry
@Component
struct MapSample {
  @State message: Map<number, string> = new Map<number, string>([[0, 'a'], [1, 'b'], [2, 'c']]);

  build() {
    Row() {
      Column() {
        Child({ value: this.message })
        Button('parent init one').onClick((e: ClickEvent) => {
          this.message = new Map<number, string>([[0, 'a'], [1, 'b'], [2, 'c']]);
        })
        Button('parent set new one').onClick((e: ClickEvent) => {
          this.message.set(3, 'd');
        })
        Button('parent clear').onClick((e: ClickEvent) => {
          this.message.clear();
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### 装饰Set类型变量

在下面的示例中，message类型为Set\<number\>，点击Button改变message的值，视图会随之刷新。

```ts
import { Entry, Component, Row, Column, Button, ClickEvent, ForEach, Text, Divider } from '@ohos.arkui.component';
import { State, Link } from '@ohos.arkui.stateManagement';

@Component
struct Child {
  @Link message: Set<number>;

  build() {
    Column() {
      ForEach(Array.from(this.message.entries()), (item: [number, number]) => {
        Text(`${item[0]}`).fontSize(30)
        Divider()
      })
      Button('child init set').onClick((e: ClickEvent) => {
        this.message = new Set<number>([0, 1, 2, 3, 4]);
      })
      Button('child set new one').onClick((e: ClickEvent) => {
        this.message.add(5);
      })
    }
    .width('100%')
  }
}

@Entry
@Component
struct SetSample {
  @State message: Set<number> = new Set<number>([0, 1, 2, 3, 4]);

  build() {
    Row() {
      Column() {
        Child({ message: this.message })
        Button('parent clear').onClick((e: ClickEvent) => {
          this.message.clear();
        })
        Button('parent delete the first one').onClick((e: ClickEvent) => {
          this.message.delete(0);
        })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### 使用双向同步机制更改本地其他变量

通过\@Watch可以在双向同步时更改本地变量。

以下示例中，在\@Link的\@Watch回调中修改\@State装饰的状态变量memberMessage，实现父子组件间的变量同步。但是在本地修改\@State装饰的变量memberMessage不会影响到父组件中的变量改变。

```ts
import { Entry, Component, Column, Button, ClickEvent, Text } from '@ohos.arkui.component';
import { State, Link, Watch } from '@ohos.arkui.stateManagement';

@Entry
@Component
struct Parent {
  @State sourceNumber: number = 0;

  build() {
    Column() {
      Text(`父组件的sourceNumber：` + this.sourceNumber)
      Child({ sourceNumber: this.sourceNumber })
      Button('父组件更改sourceNumber')
        .onClick((e: ClickEvent) => {
          this.sourceNumber++;
        })
    }
    .width('100%')
    .height('100%')
  }
}

@Component
struct Child {
  @State memberMessage: string = 'Hello World';
  @Link @Watch('onSourceChange') sourceNumber: number;

  onSourceChange(propertyName: string) {
    this.memberMessage = this.sourceNumber.toString();
  }

  build() {
    Column() {
      Text(this.memberMessage)
      Text(`子组件的sourceNumber：` + this.sourceNumber.toString())
      Button('子组件更改memberMessage')
        .onClick((e: ClickEvent) => {
          this.memberMessage = 'Hello memberMessage';
        })
    }
  }
}
```

### \@Link支持联合类型

`@Link`支持联合类型、`undefined`和`null`。在以下示例中，`name`类型为`string | undefined`。点击父组件`Index`中的按钮可以改变`name`的属性或类型，`Child`组件也会相应刷新。

```ts
import { Entry, Component, Column, Button, ClickEvent, Text } from '@ohos.arkui.component';
import { State, Link } from '@ohos.arkui.stateManagement';

@Component
struct Child {
  @Link name: string | undefined;

  build() {
    Column() {
      Button('Child change name to Bob')
        .onClick((e: ClickEvent) => {
          this.name = 'Bob';
        })
      Button('Child change name to undefined')
        .onClick((e: ClickEvent) => {
          this.name = undefined;
        })
    }.width('100%')
  }
}

@Entry
@Component
struct Index {
  @State name: string | undefined = 'Mary';

  build() {
    Column() {
      Text(`The name is  ${this.name}`).fontSize(30)
      Child({ name: this.name })
      Button('Parents change name to Peter')
        .onClick((e: ClickEvent) => {
          this.name = 'Peter';
        })
      Button('Parents change name to undefined')
        .onClick((e: ClickEvent) => {
          this.name = undefined;
        })
    }
  }
}
```

<!--no_check-->