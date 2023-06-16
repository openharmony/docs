# 创建自定义组件


在ArkUI中，UI显示的内容均为组件，由框架直接提供的称为系统组件，由开发者定义的称为自定义组件。在进行 UI 界面开发时，通常不是简单的将系统组件进行组合使用，而是需要考虑代码可复用性、业务逻辑与UI分离，后续版本演进等因素。因此，将UI和部分业务逻辑封装成自定义组件是不可或缺的能力。


自定义组件具有以下特点：


- 可组合：允许开发者组合使用系统组件、及其属性和方法。

- 可重用：自定义组件可以被其他组件重用，并作为不同的实例在不同的父组件或容器中使用。

- 数据驱动UI更新：通过状态变量的改变，来驱动UI的刷新。


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


HelloComponent可以在其他自定义组件中的build()函数中多次创建，实现自定义组件的重用。



```ts
@Entry
@Component
struct ParentComponent {
  build() {
    Column() {
      Text('ArkUI message')
      HelloComponent({ message: 'Hello, World!' });
      Divider()
      HelloComponent({ message: '你好!' });
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

- [自定义属性方法](#自定义属性方法)


## 自定义组件的基本结构

- struct：自定义组件基于struct实现，struct + 自定义组件名 + {...}的组合构成自定义组件，不能有继承关系。对于struct的实例化，可以省略new。
  > **说明：**
  >
  > 自定义组件名、类名、函数名不能和系统组件名相同。

- \@Component：\@Component装饰器仅能装饰struct关键字声明的数据结构。struct被\@Component装饰后具备组件化的能力，需要实现build方法描述UI，一个struct只能被一个\@Component装饰。
  > **说明：**
  >
  > 从API version 9开始，该装饰器支持在ArkTS卡片中使用。

  ```ts
  @Component
  struct MyComponent {
  }
  ```

- build()函数：build()函数用于定义自定义组件的声明式UI描述，自定义组件必须定义build()函数。

  ```ts
  @Component
  struct MyComponent {
    build() {
    }
  }
  ```

- \@Entry：\@Entry装饰的自定义组件将作为UI页面的入口。在单个UI页面中，最多可以使用\@Entry装饰一个自定义组件。\@Entry可以接受一个可选的[LocalStorage](arkts-localstorage.md)的参数。

  > **说明：**
  >
  > 从API version 9开始，该装饰器支持在ArkTS卡片中使用。
  >
  > 从API version 10开始，\@Entry可以接受一个可选的[LocalStorage](arkts-localstorage.md)的参数或者一个可选的[EntryOptions](#entryOptions)参数。

  ```ts
  @Entry
  @Component
  struct MyComponent {
  }
  ```

  ### EntryOptions<sup>10+</sup>

  命名路由跳转选项。

  | 名称   | 类型   | 必填 | 说明                                                         |
  | ------ | ------ | ---- | ------------------------------------------------------------ |
  | routeName | string | 否 | 表示作为命名路由页面的名字。 |
  | storage | [LocalStorage](arkts-localstorage.md) | 否 | 页面级的UI状态存储。 |

  ```ts
  @Entry({ routeName : 'myPage' })
  @Component
  struct MyComponent {
  }
  ```


- \@Recycle：\@Recycle装饰的自定义组件具备可复用能力

  > **说明：**
  >
  > 从API version 10开始，该装饰器支持在ArkTS卡片中使用。

  ```ts
  @Recycle
  @Component
  struct MyComponent {
  }
  ```


## 成员函数/变量

自定义组件除了必须要实现build()函数外，还可以实现其他成员函数，成员函数具有以下约束：


- 不支持静态函数。

- 成员函数的访问始终是私有的。


自定义组件可以包含成员变量，成员变量具有以下约束：


- 不支持静态成员变量。

- 所有成员变量都是私有的，变量的访问规则与成员函数的访问规则相同。

- 自定义组件的成员变量本地初始化有些是可选的，有些是必选的。具体是否需要本地初始化，是否需要从父组件通过参数传递初始化子组件的成员变量，请参考[状态管理](arkts-state-management-overview.md)。


## 自定义组件的参数规定

从上文的示例中，我们已经了解到，可以在build方法或者[@Builder](arkts-builder.md)装饰的函数里创建自定义组件，在创建的过程中，参数可以被提供给组件。


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


## build()函数

所有声明在build()函数的语言，我们统称为UI描述语言，UI描述语言需要遵循以下规则：

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
    let a: number = 1;
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
      ...
    }
  }
  ```

- 不允许调用除了被\@Builder装饰以外的方法，允许系统组件的参数是TS方法的返回值。

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

- 不允许switch语法，如果需要使用条件判断，请使用if。反例如下。

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
    }
  }
  ```

- 不允许使用表达式，反例如下。

  ```ts
  build() {
    Column() {
      // 反例：不允许使用表达式
      (this.aVar > 10) ? Text('...') : Image('...')
    }
  }
  ```


## 自定义组件通用样式

自定义组件通过“.”链式调用的形式设置通用样式。


```ts
@Component
struct MyComponent2 {
  build() {
    Button(`Hello World`)
  }
}

@Entry
@Component
struct MyComponent {
  build() {
    Row() {
      MyComponent2()
        .width(200)
        .height(300)
        .backgroundColor(Color.Red)
    }
  }
}
```

> **说明：**
>
> ArkUI给自定义组件设置样式时，相当于给MyComponent2套了一个不可见的容器组件，而这些样式是设置在容器组件上的，而非直接设置给MyComponent2的Button组件。通过渲染结果我们可以很清楚的看到，背景颜色红色并没有直接生效在Button上，而是生效在Button所处的开发者不可见的容器组件上。


## 自定义属性方法

自定义组件不支持提供自定义属性方法，可以借助类似Controller控制器能力，提供自定义接口。


```ts
// 自定义controller
export class MyComponentController {
  item: MyComponent = null;

  setItem(item: MyComponent) {
    this.item = item;
  }

  changeText(value: string) {
    this.item.value = value;
  }
}

// 自定义组件
@Component
export default struct MyComponent {
  public controller: MyComponentController = null;
  @State value: string = 'Hello World';

  build() {
    Column() {
      Text(this.value)
        .fontSize(50)
    }
  }

  aboutToAppear() {
    if (this.controller)
      this.controller.setItem(this); // 绑定controller
  }
}

// 使用处逻辑
@Entry
@Component
struct StyleExample {
  controller = new MyComponentController();

  build() {
    Column() {
      MyComponent({ controller: this.controller })
    }
    .onClick(() => {
      this.controller.changeText('Text');
    })
  }
}
```

在上面的示例中：

1. 通过子组件MyComponent的aboutToAppear方法，把当前的this指针传递给MyComponentController的item成员变量。

2. 在StyleExample父组件中持有controller实例，调用controller的changeText方法，即相当于通过controller持有的MyComponent子组件的this指针，改变MyComponent的状态变量value的值。

通过controller的封装，MyComponent对外暴露了changeText的接口，所有持有controller的实例都可以通过调用changeText接口，改变MyComponent的状态变量value的值。

<!--no_check-->
