# \@Provide装饰器和\@Consume装饰器：与后代组件双向同步

\@Provide和\@Consume用于与后代组件的双向数据同步和跨层级传递。

其中，\@Provide装饰的变量定义在祖先组件中，可以理解为被“提供”给后代的状态变量。\@Consume装饰的变量定义在后代组件中，去“消费（绑定）”祖先组件提供的变量。

## 概述

\@Provide/\@Consume装饰的状态变量有以下特性：

- \@Provide装饰的状态变量自动对其所有后代组件可用，即该变量被提供给他的后代组件。这使开发者无需在组件间多次传递变量。

- 后代组件通过使用\@Consume获取\@Provide提供的变量，建立\@Provide和\@Consume之间的双向数据同步。与[\@State](arkts-static-state.md)/\@Link不同，\@Provide和\@Consume可以在多层级的父子组件之间传递。

- \@Provide和\@Consume可以通过相同的变量名或者相同的变量别名绑定，要求类型相同，否则会发生运行时异常。

```ts
// 通过相同的变量名绑定
@Provide age: number = 0;
@Consume age: number;

// 通过相同的变量别名绑定
@Provide({ alias: 'a' }) id: number = 0;
@Consume('a') age: number;
@Consume({ alias: 'a' }) count: number;
```

\@Provide和\@Consume通过相同的变量名或别名绑定时，\@Provide装饰的变量和\@Consume装饰的变量是一对多的关系。当未设置[allowOverride](#provide支持allowoverride参数)参数为true时，不允许在同一个自定义组件内及其子组件中声明多个同名或者同别名的\@Provide装饰的变量。\@Provide的属性名或别名必须唯一且确定，否则会发生运行时报错。

在静态上下文中使用时，需导入装饰器：

```ts
import { Provide, Consume } from '@ohos.arkui.stateManagement';
```

## 装饰器说明

| \@Provide变量装饰器 | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| 装饰器参数          | alias：别名，常量字符串，可选。<br/>如果指定了别名，则通过别名来绑定变量；如果未指定别名，则通过变量名绑定变量。<br/>指定别名方法为：\@Provide({ alias: 'aliasName' })。<br/>allowOverride：是否允许重写，boolean类型，可选。<br/>如果指定allowOverride为true，则别名与属性名可以被重写，即可以存在同名的\@Provide变量。<br/>未指定时使用默认值false。示例见[\@Provide支持allowOverride参数](#provide支持allowoverride参数)。 |
| 允许装饰的变量类型  | Object、class、string、number、boolean、enum、interface等基本类型以及Array、Date、Map、Set等内嵌类型。支持null、undefined以及联合类型。 |
| 初始化规则          | 必须定义本地默认值。<br/>可以从父组件传入非undefined类型变量，此时使用该传入变量进行初始化。<br/>父组件未传入或传入undefined类型变量时，使用本地默认值进行初始化。 |
| 同步规则            | **在子组件使用时：**<br>不与父组件中的任何类型变量同步。<br/>父组件传入的外部变量对\@Provide初始化时，仅作为初始值，后续变量的变化不会同步至\@Provide。<br/>**在父组件使用时：**<br/>可以初始化子组件的常规变量、\@State、\@Link、\@PropRef、\@Provide。<br/>\@Provide变量的变化会同步给子组件的\@Link、\@PropRef变量。<br/>与后代子组件中别名匹配的\@Consume变量双向同步 |

| \@Consume变量装饰器 | 说明                                                         |
| ------------------- | ------------------------------------------------------------ |
| 装饰器参数          | alias：别名，常量字符串，可选。<br/>如果提供了别名，则必须存在\@Provide变量与其有相同的别名；否则，则需要变量名相同。<br/>指定别名方法为：\@Consume({ alias: 'aliasName' })或\@Consume('aliasName')。 |
| 允许装饰的变量类型  | Object、class、string、number、boolean、enum、interface等基本类型以及Array、Date、Map、Set等内嵌类型。支持null、undefined以及联合类型。 |
| 初始化规则          | 不支持本地设置默认值。<br/>禁止外部传入初始化 。<br>通过别名/变量名寻找匹配的\@Provide变量，并与之双向同步。 |
| 同步规则            | **在子组件使用时：**<br/>与祖先组件匹配的\@Provide变量双向同步。<br/>**在父组件使用时：**<br/>可以初始化子组件的常规变量、\@State、\@Link、\@PropRef、\@Provide。<br/>\@Consume变量的变化会同步给子组件的\@Link、\@PropRef变量。 |

## 观察变化和行为表现

### 观察变化

- 当装饰的数据类型为boolean、string、number类型时，可以观察到数值的变化。

- 当装饰class类型时，需要借助@Observed与@Track观测类属性，单独的\@Provide/\@Consume仅能观测类整体的赋值。

- 当装饰数组时，可以观察到数组本身的赋值、添加、删除和更新。

- 当装饰Date时，可以观察到Date整体的赋值，并通过调用Date的接口`setFullYear`, `setMonth`, `setDate`, `setHours`, `setMinutes`, `setSeconds`, `setMilliseconds`, `setTime`, `setUTCFullYear`, `setUTCMonth`, `setUTCDate`, `setUTCHours`, `setUTCMinutes`, `setUTCSeconds`, `setUTCMilliseconds` 更新Date的属性。

  ```ts
  import { Entry, Component, Column, Button, ClickEvent, Text } from '@ohos.arkui.component';
  import { Provide, Consume } from '@ohos.arkui.stateManagement';
  @Component
  struct Child {
    @Consume selectedDate: Date;

    build() {
      Column() {
        Text(`Provide: ${this.selectedDate}`)
        Button('child increase the day by 1')
          .onClick((e: ClickEvent) => {
            this.selectedDate.setDate(this.selectedDate.getDate() + 1);
          })
        Button('child update the new date')
          .margin(10)
          .onClick((e: ClickEvent) => {
            this.selectedDate = new Date('2023-09-09');
          })
      }
    }
  }

  @Entry
  @Component
  struct Parent {
    @Provide selectedDate: Date = new Date('2021-08-08');

    build() {
      Column() {
        Text(`Provide: ${this.selectedDate}`)
        Button('parent increase the day by 1')
          .margin(10)
          .onClick((e: ClickEvent) => {
            this.selectedDate.setDate(this.selectedDate.getDate() + 1);
          })
        Button('parent update the new date')
          .margin(10)
          .onClick((e: ClickEvent) => {
            this.selectedDate = new Date('2023-07-07');
          })
        Child()
      }
    }
  }
  ```

- 当装饰的变量是Map时，可以观察到Map整体的赋值，同时可通过调用Map的接口`set`, `clear`, `delete`更新Map的值。详见[装饰Map类型变量](#装饰map类型变量)。

- 当装饰的变量是Set时，可以观察到Set整体的赋值，同时可通过调用Set的接口`add`, `clear`, `delete`更新Set的值。详见[装饰Set类型变量](#装饰set类型变量)。

- 当装饰的变量是interface字面量类型时，可以观察到字面量整体以及属性的变化。

  ```ts
  import { Entry, Component, Column, Text, ClickEvent } from '@ohos.arkui.component';
  import { Provide, Consume } from '@ohos.arkui.stateManagement';
  interface Info {
    name: string;
    age: number;
  }
  @Entry
  @Component
  struct Index {
    // 装饰字面量
    @Provide info: Info = { name: 'Jack', age: 25} as Info;
    build() {
      Column() {
        Text(`info.name: ${this.info.name}`)
          .onClick((e: ClickEvent) => {
            this.info.name = 'Tom'; // 变化可观察
          })
        Child()
      }
    }
  }
  @Component
  struct Child {
    @Consume info: Info;
    build() {
      Column() {
        Text(`info.name: ${this.info.name}`)
          .onClick((e: ClickEvent) => {
            this.info.name = 'Lucy'; // 变化可观察
          })
      }
    }
  }
  ```

## 限制条件

1. \@Provide/\@Consume的参数alias必须为string类型，否则编译期会报错。

   ```ts
   // 错误写法，编译报错
   @Provide({ alias: 10 }) message: string = 'Hello';

   // 正确写法
   @Provide({ alias: 'aliasName' }) provide: string = 'Hello';
   ```

2. \@Consume装饰的变量禁止外部传入初始化，仅能通过别名来匹配对应的\@Provide变量。

   【反例】

   ```ts
   import { Entry, Component, Column, Text } from '@ohos.arkui.component';
   import { Provide, Consume } from '@ohos.arkui.stateManagement';
   @Component
   struct Child {
     @Consume message: string;

     build() {
       Text(this.message)
     }
   }

   @Entry
   @Component
   struct Parent {
     @Provide message: string = 'Hello';

     build() {
       Column() {
         // 错误用法，禁止外部传入初始化
         Child({message: 'Hello'})
       }
     }
   }
   ```

   【正例】

   ```ts
   import { Entry, Component, Column, Text } from '@ohos.arkui.component';
   import { Provide, Consume } from '@ohos.arkui.stateManagement';
   @Component
   struct Child {
     @Consume num: number;

     build() {
       Column() {
         Text(`num的值: ${this.num}`)
       }
     }
   }

   @Entry
   @Component
   struct Parent {
     @Provide num: number = 10;

     build() {
       Column() {
         Text(`num的值: ${this.num}`)
         Child()
       }
     }
   }
   ```

3. 当\@Provide的别名被重复定义时，框架会抛出运行时错误，提醒开发者存在重复定义的别名。如果需要使用重复别名，开发者可以使用[allowOverride](#provide支持allowoverride参数)参数。

   ```ts
   // 错误写法，a重复定义
   @Provide({ alias: 'a' }) count: number = 10;
   @Provide({ alias: 'a' }) num: number = 10;
   
   // 正确用法
   @Provide({ alias: 'a' }) count: number = 10;
   @Provide({ alias: 'b' }) num: number = 10;
   ```

## 使用场景

以下示例是@Provide变量与后代组件中@Consume变量进行双向同步的场景。当分别点击Index和ContentComponent组件内的Button时，count的更改会在Index和ContentComponent中双向同步。

```ts
import { Entry, Component, Column, Text, Button, ClickEvent, Row } from '@ohos.arkui.component';
import { Provide, Consume } from '@ohos.arkui.stateManagement';
@Component
struct ContentComponent {
  // @Consume装饰的变量通过相同的属性名绑定其祖先组件Index内的@Provide装饰的变量
  @Consume count: number;

  build() {
    Column() {
      Text(`count(${this.count})`)
      Button(`count(${this.count}), count + 1`)
        .onClick((e: ClickEvent) => {
          this.count += 1;
        })
    }
    .width('50%')
  }
}

@Component
struct ListComponent {
  build() {
    Row() {
      ContentComponent()
      ContentComponent()
    }
  }
}

@Entry
@Component
struct Index {
  // @Provide装饰的变量count由入口组件Index提供其后代组件
  @Provide count: number = 0;

  build() {
    Column() {
      Button(`count(${this.count}), count + 1`)
        .onClick((e: ClickEvent) => {
          this.count += 1;
        })
      ListComponent()
    }
  }
}
```

### 装饰Map类型变量

以下示例中，message类型为Map\<number, string\>，点击Button改变message的值，视图会随之刷新。

```ts
import { Entry, Component, Column, Text, Button, ClickEvent, Row, Divider, ForEach } from '@ohos.arkui.component';
import { Provide, Consume } from '@ohos.arkui.stateManagement';
@Component
struct Child {
  @Consume message: Map<number, string>;

  build() {
    Column() {
      ForEach(Array.from(this.message.entries()), (item: [number, string]) => {
        Text(`${item[0]}`).fontSize(30)
        Text(`${item[1]}`).fontSize(30)
        Divider()
      })
      Button('Consume init Map').onClick((e: ClickEvent) => {
        this.message = new Map<number, string>([[0, 'a'], [1, 'b'], [3, 'c']]);
      })
      Button('Consume set new one').onClick((e: ClickEvent) => {
        this.message.set(4, 'd');
      })
      Button('Consume clear').onClick((e: ClickEvent) => {
        this.message.clear();
      })
      Button('Consume replace the first item').onClick((e: ClickEvent) => {
        this.message.set(0, 'aa');
      })
      Button('Consume delete the first item').onClick((e: ClickEvent) => {
        this.message.delete(0);
      })
    }
  }
}


@Entry
@Component
struct MapSample {
  @Provide message: Map<number, string> = new Map<number, string>([[0, 'a'], [1, 'b'], [3, 'c']]);

  build() {
    Row() {
      Column() {
        Button('Provide init Map').onClick((e: ClickEvent) => {
          this.message = new Map<number, string>([[0, 'a'], [1, 'b'], [3, 'c'], [4, 'd']]);
        })
        Child()
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### 装饰Set类型变量

以下示例中，message类型为Set\<number\>，点击Button改变message的值，视图会随之刷新。

```ts
import { Entry, Component, Column, Text, Button, ClickEvent, Row, Divider, ForEach } from '@ohos.arkui.component';
import { Provide, Consume } from '@ohos.arkui.stateManagement';
@Component
struct Child {
  @Consume message: Set<number>;

  build() {
    Column() {
      ForEach(Array.from(this.message.entries()), (item: [number, number]) => {
        Text(`${item[0]}`).fontSize(30)
        Divider()
      })
      Button('Consume init set').onClick((e: ClickEvent) => {
        this.message = new Set<number>([0, 1, 2, 3, 4]);
      })
      Button('Consume set new one').onClick((e: ClickEvent) => {
        this.message.add(5);
      })
      Button('Consume clear').onClick((e: ClickEvent) => {
        this.message.clear();
      })
      Button('Consume delete the first one').onClick((e: ClickEvent) => {
        this.message.delete(0);
      })
    }
    .width('100%')
  }
}


@Entry
@Component
struct SetSample {
  @Provide message: Set<number> = new Set<number>([0, 1, 2, 3, 4]);

  build() {
    Row() {
      Column() {
        Button('Provide init set').onClick((e: ClickEvent) => {
          this.message = new Set<number>([0, 1, 2, 3, 4, 5]);
        })
        Child()
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

### Provide和Consume支持联合类型实例

@Provide和@Consume支持联合类型（包括undefined和null）。以下示例中，count类型为`string | undefined`，当点击Ancestors组件中的Button改变count的属性或类型时，Child组件也会对应刷新。

```ts
import { Entry, Component, Column, Text, Button, ClickEvent, Row } from '@ohos.arkui.component';
import { Provide, Consume } from '@ohos.arkui.stateManagement';
@Component
struct Child {
  // @Consume装饰的变量通过相同的属性名绑定其祖先组件Ancestors内@Provide装饰的变量
  @Consume count: string | undefined;

  build() {
    Column() {
      Text(`count(${this.count})`)
      Button(`count(${this.count}), Child`)
        .onClick((e: ClickEvent) => {
          this.count = 'Ancestors';
        })
    }
    .width('50%')
  }
}

@Component
struct Parent {
  build() {
    Row() {
      Child()
    }
  }
}

@Entry
@Component
struct Ancestors {
  // @Provide装饰的联合类型count由入口组件Ancestors提供其后代组件
  @Provide count: string | undefined = 'Child';

  build() {
    Column() {
      Button(`count(${this.count}), Child`)
        .onClick((e: ClickEvent) => {
          this.count = undefined;
        })
      Parent()
    }
  }
}
```

### @Provide支持allowOverride参数

allowOverride：是否允许@Provide重写。

| 名称          | 类型    | 必填 | 说明                                                         |
| ------------- | ------- | ---- | ------------------------------------------------------------ |
| allowOverride | boolean | 否   | 是否允许@Provide重写。允许在同一组件树下通过allowOverride重写同名的@Provide。如果开发者未写allowOverride，定义同名的@Provide，运行时会报错。 |

```ts
@Component
struct MyComponent {
  @Provide({ allowOverride: true }) reviewVotes: number = 10;
}
```

完整示例如下：

```ts
import { Entry, Component, Column, Text, Button, ClickEvent, Row } from '@ohos.arkui.component';
import { Provide, Consume } from '@ohos.arkui.stateManagement';
@Component
struct GrandSon {
  // @Consume装饰的变量通过相同的属性名绑定其祖先内的@Provide装饰的变量
  @Consume('reviewVotes') reviewVotes: number;

  build() {
    Column() {
      Text(`reviewVotes(${this.reviewVotes})`) // Text显示10
      Button(`reviewVotes(${this.reviewVotes}), give +1`)
        .onClick((e: ClickEvent) => {
          this.reviewVotes += 1;
        })
    }
    .width('50%')
  }
}

@Component
struct Child {
  @Provide({ allowOverride: true }) reviewVotes: number = 10;

  build() {
    Row() {
      GrandSon()
    }
  }
}

@Component
struct Parent {
  @Provide({ allowOverride: true }) reviewVotes: number = 20;

  build() {
    Child()
  }
}

@Entry
@Component
struct GrandParent {
  @Provide({ alias: 'reviewVotes' }) reviewVotes: number = 40;

  build() {
    Column() {
      Button(`reviewVotes(${this.reviewVotes}), give +1`)
        .onClick((e: ClickEvent) => {
          this.reviewVotes += 1;
        })
      Parent()
    }
  }
}
```

在上面的示例中：

- GrandParent声明了`@Provide({ alias: 'reviewVotes' }) reviewVotes: number = 40`。
- Parent是GrandParent的子组件，声明@Provide为allowOverride，重写父组件GrandParent的`@Provide({ alias: 'reviewVotes' }) reviewVotes: number = 40`。如果不设置allowOverride，则会抛出运行时报错，Child同理。
- GrandSon在初始化@Consume时，通过相同的属性名绑定最近祖先的@Provide变量。
- GrandSon查找到相同属性名的@Provide在祖先Child中，所以`@Consume('reviewVotes') reviewVotes: number`初始化数值为10。如果Child中没有定义与@Consume同名的@Provide，则继续向上寻找Parent中的同名@Provide，其值为20，以此类推。
- 如果查找到根节点仍没有找到别名对应的@Provide，则会报错，提示初始化@Consume时找不到@Provide。
