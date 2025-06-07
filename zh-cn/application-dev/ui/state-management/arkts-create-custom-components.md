# 创建自定义组件

在ArkUI中，UI显示的内容均为组件，由框架直接提供的称为系统组件，由开发者定义的称为自定义组件。进行UI界面开发时，不仅要组合使用系统组件，还需考虑代码的可复用性、业务逻辑与UI的分离，以及后续版本的演进等因素。因此，将UI和部分业务逻辑封装成自定义组件是不可或缺的能力。

自定义组件具有以下特点：

- 可组合：允许开发者组合使用系统组件、及其属性和方法。

- 可重用：自定义组件可以被其他组件重用，并作为不同的实例在不同的父组件或容器中使用。

- 数据驱动UI更新：通过状态变量的改变，来驱动UI的刷新。

## 自定义组件的基本用法

以下示例展示了自定义组件的基本用法。

```ts
@Component
struct HelloComponent {
  @State message: string = 'Hello, World!';

  build() {
    // HelloComponent自定义组件组合系统组件Row和Text
    Row() {
      Text(this.message)
        .onClick(() => {
          // 状态变量message的改变驱动UI刷新，UI从'Hello, World!'刷新为'Hello, ArkUI!'
          this.message = 'Hello, ArkUI!';
        })
    }
  }
}
```
> **注意：**
>
> 如果在其他文件中引用自定义组件，需要使用`export`关键字导出组件，并在使用的页面`import`该自定义组件。

可以在其他自定义组件的`build()`函数中多次创建`HelloComponent`，以实现自定义组件的重用。

```ts
@Entry
@Component
struct ParentComponent {
  build() {
    Column() {
      Text('ArkUI message')
      HelloComponent({ message: 'Hello World!' });
      Divider()
      HelloComponent({ message: '你好，世界!' });
    }
  }
}
```

要完全理解上面的示例，需要了解自定义组件的以下概念定义，本文将在后面的小节中介绍：

- [自定义组件的基本结构](#自定义组件的基本结构)

- [成员函数/变量](#成员函数变量)

- [自定义组件的参数规定](#自定义组件的参数规定)

- [build()函数](#build函数)

- [自定义组件通用样式](#自定义组件通用样式)


## 自定义组件的基本结构

### struct

自定义组件基于struct实现，struct + 自定义组件名 + {...}的组合构成自定义组件，不能有继承关系。对于struct的实例化，可以省略new。

  > **说明：**
  >
  > 自定义组件名、类名、函数名不得与系统组件名重复。
  
### \@Component

\@Component装饰器仅能装饰struct关键字声明的数据结构。struct被\@Component装饰后具备组件化的能力，需要实现build方法描述UI，一个struct只能被一个\@Component装饰。\@Component可以接受一个可选的boolean类型参数。

  > **说明：**
  >
  > 从API version 9开始，该装饰器支持在ArkTS卡片中使用。
  > 
  > 从API version 11开始，\@Component可以接受一个可选的boolean类型参数。

  ```ts
  @Component
  struct MyComponent {
  }
  ```

 #### freezeWhenInactive<sup>11+</sup>
  [组件冻结](arkts-custom-components-freeze.md)选项。

  | 名称   | 类型   | 必填 | 说明                                                         |
  | ------ | ------ | ---- | ------------------------------------------------------------ |
  | freezeWhenInactive | boolean | 否 | 是否开启组件冻结。默认值false。true：开启组件冻结，false：不开启组件冻结。 |

  ```ts
  @Component({ freezeWhenInactive: true })
  struct MyComponent {
  }
  ```

### build()函数

build()函数用于定义自定义组件的声明式UI描述，自定义组件必须定义build()函数。

  ```ts
  @Component
  struct MyComponent {
    build() {
    }
  }
  ```

### \@Entry

\@Entry装饰的自定义组件将作为UI页面的入口。在单个UI页面中，最多可以使用\@Entry装饰一个自定义组件。\@Entry可以接受一个可选的[LocalStorage](arkts-localstorage.md)的参数。

  > **说明：**
  >
  > 从API version 9开始，该装饰器支持在ArkTS卡片中使用。
  >
  > 从API version 10开始，\@Entry可以接受一个可选的[LocalStorage](arkts-localstorage.md)的参数或者一个可选的[EntryOptions](#entryoptions10)参数。
  >
  > 从API version 11开始，该装饰器支持在原子化服务中使用。

  ```ts
  @Entry
  @Component
  struct MyComponent {
  }
  ```

#### EntryOptions<sup>10+</sup>

  命名路由跳转选项。

  | 名称   | 类型   | 必填 | 说明                                                         |
  | ------ | ------ | ---- | ------------------------------------------------------------ |
  | routeName | string | 否 | 表示作为命名路由页面的名字。 |
  | storage | [LocalStorage](arkts-localstorage.md) | 否 | 页面级的UI状态存储。 |
  | useSharedStorage<sup>12+</sup> | boolean | 否 | 是否使用LocalStorage.getShared()接口返回的共享的[LocalStorage](arkts-localstorage.md)实例对象。默认值false。true：使用共享的[LocalStorage](arkts-localstorage.md)实例对象。false：不使用共享的[LocalStorage](arkts-localstorage.md)实例对象。 |

  > **说明：**
  >
  > 当useSharedStorage设置为true，并且storage也被赋值时，useSharedStorage的值优先级更高。

  ```ts
  @Entry({ routeName : 'myPage' })
  @Component
  struct MyComponent {
  }
  ```

### \@Reusable

\@Reusable装饰的自定义组件具备可复用能力。详细请参考：[\@Reusable装饰器：组件复用](./arkts-reusable.md#使用场景)。

  > **说明：**
  >
  > 从API version 10开始，该装饰器支持在ArkTS卡片中使用。

  ```ts
  @Reusable
  @Component
  struct MyComponent {
  }
  ```

## 成员函数/变量

自定义组件除了必须要实现build()函数外，还可以实现其他成员函数，成员函数具有以下约束：

- 自定义组件的成员函数为私有的，且不建议声明为静态函数。

自定义组件可以包含成员变量，成员变量具有以下约束：

- 自定义组件的成员变量为私有的，且不建议声明成静态变量。

- 自定义组件的成员变量本地初始化有些是可选的，有些是必选的。具体是否需要本地初始化，是否需要从父组件通过参数传递初始化子组件的成员变量，请参考[状态管理](arkts-state-management-overview.md)。


## 自定义组件的参数规定

以上示例中，可以在build方法里创建自定义组件，同时在创建自定义组件的过程中，根据装饰器的规则来初始化自定义组件的参数。

```ts
@Component
struct MyComponent {
  private countDownFrom: number = 0;
  private color: Color = Color.Blue;

  build() {
  }
}

@Entry
@Component
struct ParentComponent {
  private someColor: Color = Color.Pink;

  build() {
    Column() {
      // 创建MyComponent实例，并将创建MyComponent成员变量countDownFrom初始化为10，将成员变量color初始化为this.someColor
      MyComponent({ countDownFrom: 10, color: this.someColor })
    }
  }
}
```

以下示例代码将父组件中的函数传递给子组件，并在子组件中调用。

```ts
@Entry
@Component
struct Parent {
  @State cnt: number = 0
  submit: () => void = () => {
    this.cnt++;
  }

  build() {
    Column() {
      Text(`${this.cnt}`)
      Son({ submitArrow: this.submit })
    }
  }
}

@Component
struct Son {
  submitArrow?: () => void

  build() {
    Row() {
      Button('add')
        .width(80)
        .onClick(() => {
          if (this.submitArrow) {
            this.submitArrow()
          }
        })
    }
    .height(56)
  }
}
```

## build()函数

所有在build()函数中声明的语句统称为UI描述，UI描述需要遵循以下规则：

- \@Entry装饰的自定义组件，其build()函数下的根节点唯一且必要，且必须为容器组件，其中ForEach禁止作为根节点。
  \@Component装饰的自定义组件，其build()函数下的根节点唯一且必要，可以为非容器组件，其中ForEach禁止作为根节点。

  ```ts
  @Entry
  @Component
  struct MyComponent {
    build() {
      // 根节点唯一且必要，必须为容器组件
      Row() {
        ChildComponent() 
      }
    }
  }
  
  @Component
  struct ChildComponent {
    build() {
      // 根节点唯一且必要，可为非容器组件
      Image('test.jpg')
    }
  }
  ```

- 不允许声明本地变量，反例如下。

  ```ts
  build() {
    // 反例：不允许声明本地变量
    let num: number = 1;
  }
  ```

- 不允许在UI描述里直接使用console.info，但允许在方法或者函数里使用，反例如下。

  ```ts
  build() {
    // 反例：不允许console.info
    console.info('print debug log');
  }
  ```

- 不允许创建本地的作用域，反例如下。

  ```ts
  build() {
    // 反例：不允许本地作用域
    {
      // ...
    }
  }
  ```

- 不允许调用没有用\@Builder装饰的方法，允许系统组件的参数是TS方法的返回值。

  ```ts
  @Component
  struct ParentComponent {
    doSomeCalculations() {
    }

    calcTextValue(): string {
      return 'Hello World';
    }

    @Builder doSomeRender() {
      Text(`Hello World`)
    }

    build() {
      Column() {
        // 反例：不能调用没有用@Builder装饰的方法
        this.doSomeCalculations();
        // 正例：可以调用
        this.doSomeRender();
        // 正例：参数可以为调用TS方法的返回值
        Text(this.calcTextValue())
      }
    }
  }
  ```

- 不允许使用switch语法，当需要使用条件判断时，请使用[if](./arkts-rendering-control-ifelse.md)。示例如下。

  ```ts
  build() {
    Column() {
      // 反例：不允许使用switch语法
      switch (expression) {
        case 1:
          Text('...')
          break;
        case 2:
          Image('...')
          break;
        default:
          Text('...')
          break;
      }
      // 正例：使用if
      if(expression == 1) {
        Text('...')
      } else if(expression == 2) {
        Image('...')
      } else {
        Text('...')
      }
    }
  }
  ```

- 不允许使用表达式，请使用if组件，示例如下。

  ```ts
  build() {
    Column() {
      // 反例：不允许使用表达式
      (this.aVar > 10) ? Text('...') : Image('...')

      // 正例：使用if判断
      if(this.aVar > 10) {
        Text('...')
      } else {
        Image('...')
      }
    }
  }
  ```

- 不允许直接改变状态变量，反例如下。详细分析见[\@State常见问题：不允许在build里改状态变量](./arkts-state.md#不允许在build里改状态变量)。

  ```ts
  @Component
  struct MyComponent {
    @State textColor: Color = Color.Yellow;
    @State columnColor: Color = Color.Green;
    @State count: number = 1;
    build() {
      Column() {
        // 应避免直接在Text组件内改变count的值
        Text(`${this.count++}`)
          .width(50)
          .height(50)
          .fontColor(this.textColor)
          .onClick(() => {
            this.columnColor = Color.Red;
          })
        Button("change textColor").onClick(() =>{
          this.textColor = Color.Pink;
        })
      }
      .backgroundColor(this.columnColor)
    }
  }
  ```

  在ArkUI状态管理中，状态驱动UI更新。

  ![zh-cn_image_0000001651365257](figures/zh-cn_image_0000001651365257.png)

  所以，不能在自定义组件的build()或\@Builder方法里直接改变状态变量，这可能会造成循环渲染的风险。Text('${this.count++}')在全量更新或最小化更新会产生不同的影响：

  - 全量更新（API8及以前版本）： ArkUI可能会陷入一个无限的重渲染的循环里，因为Text组件的每一次渲染都会改变应用的状态，就会再引起下一轮渲染的开启。 当 this.columnColor 更改时，都会执行整个build构建函数，因此，Text(`${this.count++}`)绑定的文本也会更改，每次重新渲染Text(`${this.count++}`)，又会使this.count状态变量更新，导致新一轮的build执行，从而陷入无限循环。
  - 最小化更新（API9-至今版本）：当this.columnColor更改时，只有Column组件会更新，Text组件不会更改。只有当this.textColor更改时，会去更新整个Text组件，其所有属性函数都会执行，所以会看到Text(`${this.count++}`)自增。因为目前UI以组件为单位进行更新，如果组件上某一个属性发生改变，会更新整体的组件。所以整体的更新链路是：this.textColor = Color.Pink -&gt;Text组件整体更新-&gt;this.count++ -&gt;Text组件整体更新。值得注意的是，这种写法在初次渲染时会导致Text组件渲染两次，从而影响性能。

  build函数中更改应用状态的行为可能会比上面的示例更加隐蔽，比如：

  - 在\@Builder，\@Extend或\@Styles方法内改变状态变量 。

  - 在计算参数时调用函数中改变应用状态变量，例如 Text('${this.calcLabel()}')。

  - 对当前数组做出修改，sort()改变了数组this.arr，随后的filter方法会返回一个新的数组。

    ```ts
    // 反例
    @State arr : Array<...> = [ ... ];
    ForEach(this.arr.sort().filter(...), 
      item => { 
      // ...
    })
    // 正确的执行方式为：filter返回一个新数组，后面的sort方法才不会改变原数组this.arr
    ForEach(this.arr.filter(...).sort(), 
      item => { 
      // ...
    })
    ```

## 自定义组件通用样式

自定义组件通过“.”链式调用设置通用样式。

```ts
@Component
struct ChildComponent {
  build() {
    Button(`Hello World`)
  }
}

@Entry
@Component
struct MyComponent {
  build() {
    Row() {
      ChildComponent()
        .width(200)
        .height(300)
        .backgroundColor(Color.Red)
    }
  }
}
```

> **说明：**
>
> ArkUI给自定义组件设置样式时，相当于给ChildComponent套了一个不可见的容器组件，这些样式是设置在容器组件上，而非直接设置给ChildComponent的Button组件。渲染结果显示，背景颜色红色并没有直接设置到Button上，而是设置在Button所在的不可见容器组件上。
<!--no_check-->