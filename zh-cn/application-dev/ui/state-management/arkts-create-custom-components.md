# 创建自定义组件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926; @xin11112-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

在ArkUI中，UI显示的内容均为组件，由框架直接提供的称为系统组件，由开发者定义的称为自定义组件。进行UI界面开发时，不仅要组合使用系统组件，还需考虑代码的可复用性、业务逻辑与UI的分离，以及后续版本的演进等因素。因此，将UI和部分业务逻辑封装成自定义组件是不可或缺的能力。

自定义组件具有以下特点：

- 可组合：允许开发者组合使用系统组件及其属性和方法。

- 可重用：自定义组件可以被其他组件重用，并作为不同的实例在不同的父组件或容器中使用。

- 数据驱动UI更新：通过状态变量的改变，来驱动UI的刷新。

>**说明：**
>
>从API version 24开始，可通过在应用工程的[module.json5配置文件](./../../quick-start/module-configuration-file.md)中配置[metadata标签](./../../quick-start/module-configuration-file.md#metadata标签)来使能自定义组件支持跨[Ability](../../reference/apis-ability-kit/js-apis-app-ability-ability.md)迁移。具体配置方式为：新增[name](./../../quick-start/module-configuration-file.md#metadata标签)为`"enableCustomComponentCrossAbility"`，[value](./../../quick-start/module-configuration-file.md#metadata标签)为`"true"`。因为自定义组件提供的是UI能力，所以这里的Ability也特指[UIAbility](../../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)。具体示例参考[自定义组件支持跨Ability迁移](#自定义组件支持跨ability迁移)。


## 自定义组件的基本用法

以下示例展示了自定义组件的基本用法。

<!-- @[HelloComponent_Hello](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/ParentComponent.ets) -->  

``` TypeScript
@Component
struct HelloComponent {
  @State message: string = 'Hello, World!';

  build() {
    // HelloComponent自定义组件组合系统组件Row和Text
    Row() {
      Text(this.message)
        .fontSize(20)
        .margin(10)
        .onClick(() => {
          // 状态变量message的改变驱动UI刷新，UI从'Hello, World!'刷新为'Hello, ArkUI!'
          this.message = 'Hello, ArkUI!';
        })
    }
    .height('100%')
  }
}
```

> **注意：**
>
> 如果在其他文件中引用自定义组件，需要使用`export`关键字导出组件，并在使用的页面`import`该自定义组件。

可以在其他自定义组件的`build()`函数中多次创建`HelloComponent`，以实现自定义组件的重用。

<!-- @[ArkUI_message](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/ParentComponent.ets) -->   

``` TypeScript
@Entry
@Component
struct ParentComponent {
  build() {
    Column() {
      // 多次创建HelloComponent，实现自定义组件的重用
      Text('ArkUI message')
        .fontSize(20)
        .margin(10)
      HelloComponent({ message: 'Hello World!' })
      Divider()
      HelloComponent({ message: 'Hello ArkTS!' })
    }
    .width('100%')
  }
}
```

![arkts-create-custom-components-0](../figures/arkts-create-custom-components-0.gif)

要完全理解上面的示例，需要了解自定义组件的以下概念定义，本文将在后面的小节中介绍：

- [自定义组件的基本结构](#自定义组件的基本结构)

- [成员函数/变量](#成员函数变量)

- [自定义组件的参数规定](#自定义组件的参数规定)

- [build()函数实现规则](#build函数实现规则)

- [自定义组件通用样式](#自定义组件通用样式)


## 自定义组件的基本结构

### struct

自定义组件基于struct实现，struct + 自定义组件名 + {...}的组合构成自定义组件，不能有继承关系。对于struct的实例化，可以省略new。

  > **说明：**
  >
  > 自定义组件名、类名、函数名不得与系统组件名重复。

### \@Entry

[\@Entry](../../reference/apis-arkui/arkui-ts/ts-universal-entry.md#entry)装饰的自定义组件将作为[UI页面](../arkts-router-to-navigation.md#页面结构)的入口。在单个UI页面中，仅允许存在一个由@Entry装饰的自定义组件作为页面的入口。

  > **说明：**
  >
  > 从API version 9开始，该装饰器支持在ArkTS卡片中使用。
  >
  > 从API version 10开始，\@Entry可以接受一个可选的[LocalStorage](../../reference/apis-arkui/arkui-ts/ts-state-management.md#localstorage9)参数或者一个可选的EntryOptions<sup>10+</sup>参数。
  >
  > 从API version 11开始，该装饰器支持在原子化服务中使用。

  <!-- @[Entry_UI_page](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/Entry.ets) -->  
  
  ``` TypeScript
  @Entry
  @Component
  struct MyComponent {
    // ...
  }
  ```

**EntryOptions<sup>10+</sup>**

  命名路由跳转选项。
  
  <!--Table: 20%; 20%; 10%; 10%; 40%-->
  | 名称   | 类型   | 只读 | 可选 | 说明                                                         |
  | ------ | ------ | ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | routeName | string | 否 | 是 | 表示作为命名路由页面的名字。 |
  | storage | [LocalStorage](arkts-localstorage.md) | 否 | 是 | 页面级的UI状态存储。当未传入时，框架会创建一个新的LocalStorage实例作为默认值。 |
  | useSharedStorage<sup>12+</sup> | boolean | 否 | 是 | 是否使用[loadContent](../../reference/apis-arkui/arkts-apis-window-WindowStage.md#loadcontent9)传入的LocalStorage实例对象。默认值false。值为true时：若loadContent传入了LocalStorage实例，则使用该LocalStorage实例对象，否则会新建一个LocalStorage实例。值为false时：不使用共享的LocalStorage实例对象。 |

  > **说明：**
  >
  > 当useSharedStorage设置为true且storage已赋值时，useSharedStorage的优先级高于storage参数，此时无论loadContent中是否传入LocalStorage实例，都不会使用传入的storage参数。

  <!-- @[routeName_myPage](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/RouteName.ets) -->  
  
  ``` TypeScript
  @Entry({ routeName: 'myPage' })
  @Component
  struct MyComponent {
    // ...
  }
  ```

### \@Component

[@Component](../../reference/apis-arkui/arkui-ts/ts-custom-component-decorator-component.md#component)装饰的struct为V1自定义组件，可以使用[状态管理V1版本](./arkts-state-management-overview.md#状态管理v1)装饰器的能力。

  > **说明：**
  >
  > 从API version 9开始，该装饰器支持在ArkTS卡片中使用。
  > 
  > 从API version 11开始，\@Component可以接受一个[ComponentOptions参数](../../reference/apis-arkui/arkui-ts/ts-custom-component-parameter.md#componentoptions)。
  >
  > 从API version 11开始，该装饰器支持在原子化服务中使用。

  <!-- @[Component_data_structure](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/Component.ets) -->   
  
  ``` TypeScript
  @Component
  struct MyComponent {
    // ...
  }
  ```

### \@ComponentV2

[@ComponentV2](../../reference/apis-arkui/arkui-ts/ts-custom-component-decorator-componentv2.md#componentv2)装饰的struct为V2自定义组件，可以使用[状态管理V2版本](./arkts-state-management-overview.md#状态管理v2)装饰器的能力。
>  **说明：**
>
> \@ComponentV2装饰器从API version 12开始支持。
>
> 从API version 12开始，该装饰器支持在原子化服务中使用。
>
> 从API version 23开始，该装饰器支持在ArkTS卡片中使用。

和[\@Component装饰器](#component)一样，\@ComponentV2装饰器用于装饰自定义组件：

- 在\@ComponentV2装饰的自定义组件中，开发者仅可以使用全新的状态变量装饰器，包括[\@Local](arkts-new-local.md)、[\@Param](arkts-new-param.md)、[\@Once](arkts-new-once.md)、[\@Event](arkts-new-event.md)、[\@Provider](arkts-new-provider-and-consumer.md)、[\@Consumer](arkts-new-provider-and-consumer.md)等。
- \@ComponentV2装饰的自定义组件暂不支持[LocalStorage](arkts-localstorage.md)等现有自定义组件的能力。
- 无法同时使用\@ComponentV2与\@Component装饰同一个struct结构。
- \@ComponentV2支持一个可选的[ComponentOptions参数](../../reference/apis-arkui/arkui-ts/ts-custom-component-parameter.md#componentoptions)，来实现[组件冻结功能](arkts-custom-components-freezeV2.md)。

- 一个简单的\@ComponentV2装饰的自定义组件应具有以下部分：

    <!-- @[ComponentV2_page_componentV2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/wrapbuilder/entry/src/main/ets/pages/PageComponentV2.ets) -->  
    
    ``` TypeScript
    @Entry
    @ComponentV2 // 装饰器
    struct ComponentV2Test { // struct声明的数据结构
      @Local message: string = 'Hello World';
      build() { // build定义的UI
        RelativeContainer() {
          Text(this.message)
            .id('HelloWorld')
            // $r('app.float.page_text_font_size')需要替换为开发者所需的资源文件;
            .fontSize($r('app.float.page_text_font_size'))
            .fontWeight(FontWeight.Bold)
            .alignRules({
              center: { anchor: '__container__', align: VerticalAlign.Center },
              middle: { anchor: '__container__', align: HorizontalAlign.Center }
            })
            .onClick(() => {
              this.message = 'Welcome';
            })
        }
        .height('100%')
        .width('100%')
      }
    }
    ```

    ![arkts-create-custom-components-1](../figures/arkts-create-custom-components-1.gif)

除非特别说明，\@ComponentV2装饰的自定义组件将与\@Component装饰的自定义组件保持相同的行为。

### build()函数

build()函数用于定义自定义组件的声明式UI描述，自定义组件必须定义build()函数。

  <!-- @[Declarative_UI_description](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/BuildFunction.ets) -->   
  
  ``` TypeScript
  @Component
  struct MyComponent {
    build() {
      // ...
    }
  }
  ```

### \@Reusable

\@Reusable装饰V1自定义组件，使得该自定义组件具有被复用的能力。详细请参考：[\@Reusable装饰器：组件复用](./arkts-reusable.md#使用场景)。

  > **说明：**
  >
  > 从API version 10开始，该装饰器支持在ArkTS卡片中使用。

  <!-- @[Reusable_MyComponent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/Reusable.ets) --> 
  
  ``` TypeScript
  @Reusable
  @Component
  struct MyComponent {
    // ...
  }
  ```

### \@ReusableV2

\@ReusableV2装饰V2自定义组件，使得该自定义组件具有被复用的能力。详细请参考：[\@ReusableV2装饰器：V2组件复用](./arkts-new-reusableV2.md#使用场景)。

  > **说明：**
  >
  > 从API version 18开始，该装饰器支持在原子化服务中使用。

  ``` TypeScript
  @ReusableV2
  @ComponentV2
  struct MyComponent {
    // ...
  }
  ```

## 成员函数/变量

自定义组件除了必须要实现build()函数外，还可以实现其他成员函数，成员函数具有以下约束：

- 自定义组件的成员函数仅能从组件内部访问，且不建议声明为静态函数。

自定义组件可以包含成员变量，成员变量具有以下约束：

- 自定义组件的成员变量仅能从组件内部访问，且不建议声明为静态变量。

- 自定义组件的成员变量本地初始化有些是可选的，有些是必选的。具体是否需要本地初始化，是否需要从父组件通过参数传递初始化子组件的成员变量，请参考[状态管理](arkts-state-management-overview.md)。


## 自定义组件的参数规定

自定义组件的成员变量根据装饰器不同，初始化规则不同，各装饰器规则如下表所示。

**\@Component成员变量初始化规则**

| 变量类型 | 本地初始化 | 从父组件传入 |
|---------|-----------|-------------|
| 普通变量 | 必选 | 可选，传入非undefined值时使用传入值，否则使用本地默认值。 |
| [@State](arkts-state.md) | 必选 | 可选，传入非undefined值时使用传入值，否则使用本地默认值。 |
| [@Prop](arkts-prop.md) | 可选 | 可选，无本地默认值时必选，传入非undefined值时使用传入值，否则使用本地默认值。 |
| [@Link](arkts-link.md) | 不支持 | 必选，需传入状态变量。 |
| [@ObjectLink](arkts-observed-and-objectlink.md) | 不支持 | 必选，需传入[@Observed](arkts-observed-and-objectlink.md)装饰的class实例（API version 19起可传入复杂类型）。 |
| [@Provide](arkts-provide-and-consume.md) | 必选 | 可选，传入非undefined值时使用传入值，否则使用本地默认值。 |
| [@Consume](arkts-provide-and-consume.md) | 不支持（API version 20起可选） | 不支持，通过别名/变量名匹配\@Provide初始化。 |
| [@StorageProp](arkts-appstorage.md) | 必选 | 不支持，通过[AppStorage](arkts-appstorage.md)对应key初始化。 |
| [@StorageLink](arkts-appstorage.md) | 必选 | 不支持，通过[AppStorage](arkts-appstorage.md)对应key初始化。 |
| [@LocalStorageProp](arkts-localstorage.md) | 必选 | 不支持，通过[LocalStorage](arkts-localstorage.md)对应key初始化。 |
| [@LocalStorageLink](arkts-localstorage.md) | 必选 | 不支持，通过[LocalStorage](arkts-localstorage.md)对应key初始化。 |

**\@ComponentV2成员变量初始化规则**

| 变量类型 | 本地初始化 | 从父组件传入 |
|---------|-----------|-------------|
| 普通变量 | 必选 | 不支持。 |
| [@Local](arkts-new-local.md) | 必选 | 不支持。 |
| [@Param](arkts-new-param.md) | 可选 | 可选，无本地默认值时必选，有传入值时使用传入值，否则使用本地默认值。 |
| [@Event](arkts-new-event.md) | 可选 | 可选，无本地默认值且未从父组件传入时，自动生成空函数作为默认回调。 |
| [@Provider](arkts-new-provider-and-consumer.md) | 必选 | 不支持。 |
| [@Consumer](arkts-new-provider-and-consumer.md) | 必选 | 不支持，通过别名/变量名匹配\@Provider初始化。 |

下面以普通变量为例，展示如何在build方法中初始化自定义组件的参数。其余装饰器的使用示例，可参考各文档。

<!-- @[Parameter_specification](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/ParameterSpecification.ets) -->  

``` TypeScript
@Component
struct MyComponent {
  countDownFrom: number = 0;
  color: Color = Color.Blue;

  build() {
    Column() {
      Text(`${this.countDownFrom}`)
        .fontSize(20)
        .margin(10)
        .backgroundColor(this.color)
    }
    .width('100%')
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
    .width('100%')
  }
}
```

![arkts-create-custom-components-2](../figures/arkts-create-custom-components-2.png)

以下示例代码将父组件中的函数传递给子组件，并在子组件中调用。

<!-- @[Function_passing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/ParentFunction.ets)  --> 

``` TypeScript
@Entry
@Component
struct Parent {
  @State cnt: number = 0;
  submit: () => void = () => {
    this.cnt++;
  };

  build() {
    Column() {
      Text(`${this.cnt}`)
        .fontSize(20)
        .margin(10)
      // 父组件中的函数传递给子组件
      Son({ submitArrow: this.submit })
    }
    .width('100%')
  }
}

@Component
struct Son {
  submitArrow?: () => void;

  build() {
    Row() {
      Button('add')
        .width(300)
        .margin(10)
        .onClick(() => {
          if (this.submitArrow) {
            this.submitArrow()
          }
        })
    }
    .height('100%')
  }
}
```

![arkts-create-custom-components-3](../figures/arkts-create-custom-components-3.gif)

## build()函数实现规则

所有在build()函数中声明的语句统称为UI描述，UI描述需要遵循以下规则：

- \@Entry装饰的自定义组件，其build()函数下的根节点唯一且必要，且必须为容器组件，其中ForEach禁止作为根节点。\@Component装饰的自定义组件，其build()函数下的根节点唯一且必要，可以为非容器组件，其中ForEach禁止作为根节点。

  <!-- @[build_function](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/MyComponentBuild.ets) --> 
  
  ``` TypeScript
  @Entry
  @Component
  struct MyComponent {
    build() {
      // 根节点唯一且必要，必须为容器组件
      Row() {
        ChildComponent()
      }
      .height('100%')
    }
  }
  
  @Component
  struct ChildComponent {
    build() {
      // 根节点唯一且必要，可为非容器组件
      // 请将$r('app.media.startIcon')替换为实际资源文件
      Image($r('app.media.startIcon'))
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

- 不允许调用非\@Builder装饰的方法。但允许将此类方法的返回值作为系统组件的参数使用。示例如下。

  ```ts
  @Component
  struct ParentComponent {
    doSomeCalculations() {
    }
    build() {
      Column() {
        // 反例：不能调用没有用@Builder装饰的方法
        this.doSomeCalculations();
      }
    }
  }
  ```
  <!-- @[Builder_decoration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/BuilderMethod.ets) -->  
  
  ``` TypeScript
  @Component
  struct ParentComponent {
    calcTextValue(): string {
      return 'Hello World';
    }
  
    @Builder
    doSomeRender() {
      Text(`Hello World`)
        .fontSize(20)
        .margin(10)
    }

    build() {
      Column() {
        // 正例：可以调用
        this.doSomeRender()
        // 正例：参数可以为调用TS方法的返回值
        Text(this.calcTextValue())
          .fontSize(20)
          .margin(10)
      }
      .width('100%')
    }
  }
  ```


- 不允许使用switch语法，当需要使用条件判断时，请使用[if](../rendering-control/arkts-rendering-control-ifelse.md)。示例如下。

  ```ts
  build() {
    Column() {
      // 反例：不允许使用switch语法
      switch (expression) {
        case 1:
          Text('...')
            .fontSize(20)
            .margin(10)
          break;
        case 2:
          Image('...')
          break;
        default:
          Text('...')
            .fontSize(20)
            .margin(10)
          break;
      }
    }
    .width('100%')
  }
  ```
  <!-- @[switch_syntax](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/If.ets) -->  
  
  ``` TypeScript
  build() {
    Column() {
      // 正例：使用if
      if (this.expression == 1) {
        Text('...')
      } else if (this.expression == 2) {
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
    }
  }
  ```
  <!-- @[if_component](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/ModuleComponent.ets) -->  
  
  ``` TypeScript
  build() {
    Column() {
      // 正例：使用if判断
      if (this.aVar > 10) {
        Text('...')
      } else {
        Image('...')
      }
    }
  }
  ```


- 不允许直接改变状态变量，反例如下。

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

  ![zh-cn_image_0000001651365257](figures/State-UI-function.png)

  所以，不能在自定义组件的`build()`或\@Builder方法里直接改变状态变量，这可能会造成循环渲染的风险。``Text(`${this.count++}`)``在全量更新或最小化更新会产生不同的影响：

  - 全量更新（API8及以前版本）：ArkUI可能会陷入一个无限的重渲染的循环里，因为Text组件的每一次渲染都会改变应用的状态，就会再引起下一轮渲染的开启。 当`this.columnColor`更改时，都会执行整个`build()`构建函数，因此，``Text(`${this.count++}`)``绑定的文本也会更改，每次重新渲染``Text(`${this.count++}`)``，又会使`this.count`状态变量更新，导致新一轮的`build()`执行，从而陷入无限循环。
  - 最小化更新（API9及以上版本）：当`this.columnColor`更新时，仅Column组件更新，Text组件不会更新。只有当`this.textColor`更改时，会去更新整个Text组件，其所有属性函数都会执行，所以会看到``Text(`${this.count++}`)``自增。因为目前UI以组件为单位进行更新，如果组件上某一个属性发生改变，会更新整个的组件。所以整体的更新链路是：`this.textColor = Color.Pink` -&gt; Text组件整个更新 -&gt; `this.count++` -&gt; Text组件整个更新。值得注意的是，这种写法在初次渲染时会导致Text组件渲染两次，影响性能。
  
  `build()`函数中更改应用状态的行为可能比上面的示例更加隐蔽，例如：

  - 在\@Builder，[\@Extend](arkts-extend.md)或[\@Styles](arkts-style.md)方法内改变状态变量。

  - 在计算参数时调用函数中改变应用状态变量，例如 ``Text(`${this.calcLabel()}`)``。

  - 对当前数组做出修改，`sort()`改变了数组`this.arr`，随后的`filter()`方法会返回一个新的数组。

    ```ts
    // 反例
    @State arr : Array<...> = [ ... ];
    ForEach(this.arr.sort().filter(...), 
      item => { 
      // ...
    })
    ```
    
    ``` TypeScript
    // 正确的执行方式为：filter返回一个新数组，后面的sort方法才不会改变原数组this.arr
    ForEach(this.arr.filter((item, index) => index >= 2).sort(),
      (item: number) => {
        // ...
      });
    ```
  
  该问题可以参考[常见问题：build函数中更改状态变量导致appfreeze](./arkts-state-management-faq-inner-component.md#build函数中更改状态变量导致appfreeze)。

## 自定义组件通用样式

自定义组件通过“.”链式调用设置通用样式。

<!-- @[Custom_style](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/MyComponentStyle.ets) -->   

``` TypeScript
@Component
struct ChildComponent {
  build() {
    Button(`Hello World`)
      .width('90%')
      .margin(10)
  }
}

@Entry
@Component
struct MyComponent {
  build() {
    Row() {
      // 属性设置给ChildComponent而不是ChildComponent中的Button
      ChildComponent()
        .width(300)
        .height(300)
        .backgroundColor(Color.Pink)
    }
    .height('100%')
  }
}
```

![arkts-create-custom-components-4](../figures/arkts-create-custom-components-4.png)

> **说明：**
>
> ArkUI给自定义组件设置样式时，相当于给ChildComponent套了一个不可见的容器组件，这些样式是设置在容器组件上，而非直接设置给ChildComponent的Button组件。渲染结果显示，背景颜色粉红色并没有直接设置到Button上，而是设置在Button所在的不可见容器组件上。

## 自定义组件支持跨Ability迁移

API version 24前，自定义组件不支持跨Ability迁移，自定义组件实例在跨Ability后，改变自定义组件的状态变量将无法触发UI组件刷新。需要注意，在系统升级API version 24之前，即使在module.json5配置了```"enableCustomComponentCrossAbility"```为```"true"```，该能力也不会生效。

API version 24开始，可在应用工程的module.json5配置文件中配置metadata标签来使能自定义组件支持跨Ability迁移。具体配置方式如下。

<!-- @[EnableCustomComponentCrossAbility_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnableCustomComponentCrossAbility/entry/src/main/module.json5) -->  

``` JSON5
"metadata": [
  {
    "name": "enableCustomComponentCrossAbility",
    "value": "true"
  }
]
```

需要注意：
1. 不建议在原Ability的onBackground阶段异步修改迁移组件中的状态变量，此时状态变量可以被赋值，但无法触发关联组件的刷新。
2. 仅支持组件树上的自定义组件迁移。对于未挂载在组件树上的自定义组件将不支持迁移。例如使用[OH_ArkUI_GetNodeHandleFromNapiValue](../../reference/apis-arkui/capi-native-node-napi-h.md#oh_arkui_getnodehandlefromnapivalue)获取[ArkUI_NodeHandle](../../reference/apis-arkui/capi-arkui-nativemodule-arkui-node8h.md)场景中，如果OH_ArkUI_GetNodeHandleFromNapiValue接收的参数为[ComponentContent](../../reference/apis-arkui/js-apis-arkui-ComponentContent.md)，获取到的ArkUI_NodeHandle为ComponentContent下子树的第一个[FrameNode](../../reference/apis-arkui/js-apis-arkui-frameNode.md)节点，中间跳过的自定义组件将不会在组件树上，不支持迁移。

<!-- @[EnableCustomComponentCrossAbility_EntryAbility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnableCustomComponentCrossAbility/entry/src/main/ets/entryability/EntryAbility.ets) -->  

``` TypeScript
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(DOMAIN, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      hilog.info(DOMAIN, 'testTag', 'Succeeded in loading the content.');
    });
  }

  onBackground(): void {
    // 不建议在onBackground阶段异步修改迁移组件中的状态变量
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onBackground');
  }
}
```
在下面的示例中：
1. 点击```Button('add node to tree')```，创建BuilderNode节点挂载到`NodeContainer`下。
2. 点击```Button('remove node from tree')```，将BuilderNode节点从`NodeContainer`上移除。
3. 点击```Button('start new ability')```，拉起`ExtraAbility`。
4. 点击`ExtraIndex`内的```Button('add node to tree')```，将BuilderNode节点重新挂载到`ExtraIndex`内的`NodeContainer`下。
   - 自定义组件`ComponentUnderBuilderNode`在被挂载到新的Ability下时，会通知切换Ability的自定义组件更新其所属的Ability实例ID。
   - 点击自定义组件`ComponentUnderBuilderNode`内```Button('change message')```，改变状态变量`message`的值，触发```@Watch('messageUpdate') ```回调和UI刷新。

下面的示例包含了创建新的Ability流程，具体示例可参考[startAbility](../../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability)。

<!-- @[EnableCustomComponentCrossAbility_Index](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnableCustomComponentCrossAbility/entry/src/main/ets/pages/Index.ets) -->  

``` TypeScript
import { MyNodeController } from './MyNodeController';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

const DOMAIN = 0x0000;

@Entry
@Component
struct Index {
  private nodeController: MyNodeController = new MyNodeController();

  startNewAbility() {
    const want: Want = {
      bundleName: 'com.example.enablecustomcomponentcrossability',
      abilityName: 'ExtraAbility'
    };

    try {
      const context = this.getUIContext()?.getHostContext() as common.UIAbilityContext;
      context.startAbility(want, (err: BusinessError) => {
        if (err.code) {
          hilog.error(DOMAIN, 'testTag', `startAbility failed, code is ${err.code}, message is ${err.message}`);
          return;
        }
        hilog.info(DOMAIN, 'testTag', 'startAbility succeed');
      });
    } catch (err) {
      hilog.error(DOMAIN, 'testTag',
        `startAbility failed, code is ${(err as BusinessError).code}, message is ${(err as BusinessError).message}`);
    }
  }

  build() {
    Column({ space: 10 }) {
      Text('Index')
      // 创建globalBuilderNode，并将globalBuilderNode下的节点挂在NodeContainer的占位节点下
      Button('add node to tree').width(200).onClick(() => {
        this.nodeController.addBuilderNode();
      })
      // 从NodeContainer的占位节点下移除globalBuilderNode下的节点
      Button('remove node from tree').width(200).onClick(() => {
        this.nodeController.removeBuilderNode();
      })
      // 拉起新的Ability
      Button('start new ability').width(200).onClick(() => {
        this.startNewAbility();
      })
      NodeContainer(this.nodeController).backgroundColor('#FFEEF0')
    }
    .width('100%')
    .height('100%')
  }
}
```

<!-- @[EnableCustomComponentCrossAbility_MyNodeController](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnableCustomComponentCrossAbility/entry/src/main/ets/pages/MyNodeController.ets) -->  

``` TypeScript
import { BuilderNode, FrameNode, NodeController } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

let globalBuilderNode: BuilderNode<[]> | undefined = undefined;

export class MyNodeController extends NodeController {
  private rootNode: FrameNode | null = null;
  private uiContext: UIContext | null = null;

  makeNode(uiContext: UIContext): FrameNode | null {
    this.rootNode = new FrameNode(uiContext);
    this.uiContext = uiContext;
    return this.rootNode;
  }

  addBuilderNode(): void {
    if (!globalBuilderNode && this.uiContext) {
      globalBuilderNode = new BuilderNode(this.uiContext);
      globalBuilderNode.build(wrapBuilder<[]>(buildComponent), undefined);
    }
    if (this.rootNode && globalBuilderNode) {
      this.rootNode.appendChild(globalBuilderNode.getFrameNode());
    }
  }

  removeBuilderNode(): void {
    if (this.rootNode && globalBuilderNode) {
      this.rootNode.removeChild(globalBuilderNode.getFrameNode());
    }
  }

  disposeNode(): void {
    if (this.rootNode && globalBuilderNode) {
      globalBuilderNode.dispose();
      globalBuilderNode = undefined;
    }
  }
}

@Builder
function buildComponent() {
  Column() {
    ComponentUnderBuilderNode()
  }
}

@Component
struct ComponentUnderBuilderNode {
  @State @Watch('messageUpdate') message: string = 'hello';

  messageUpdate() {
    hilog.info(DOMAIN, 'testTag', `ComponentUnderBuilderNode message change ${this.message}`);
  }

  build() {
    Column() {
      Text(`message: ${this.message}`)
      // 改变message的值，触发@Watch('messageUpdate')回调和Text组件的刷新
      Button('change message').onClick(() => {
        this.message += ' world';
      })
    }
  }
}
```

<!-- @[EnableCustomComponentCrossAbility_ExtraAbility](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnableCustomComponentCrossAbility/entry/src/main/ets/extraability/ExtraAbility.ets) -->   

``` TypeScript
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;

export default class ExtraAbility extends UIAbility {

  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/ExtraIndex', (err) => {
      if (err.code) {
        // ExtraIndex加载失败，输出报错信息
        hilog.error(DOMAIN, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      hilog.info(DOMAIN, 'testTag', 'Succeeded in loading the content.');
    });
  }
}
```

<!-- @[EnableCustomComponentCrossAbility_ExtraIndex](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnableCustomComponentCrossAbility/entry/src/main/ets/pages/ExtraIndex.ets) -->  

``` TypeScript
import { MyNodeController } from './MyNodeController';

@Entry
@Component
struct ExtraIndex {
  private nodeController: MyNodeController = new MyNodeController();

  build() {
    Column({ space: 10 }) {
      Text('ExtraIndex')
      // 将globalBuilderNode下的节点挂在NodeContainer的占位节点下
      Button('add node to tree').width(200).onClick(() => {
        this.nodeController.addBuilderNode();
      })
      // 从NodeContainer的占位节点下移除globalBuilderNode下的节点
      Button('remove node from tree').width(200).onClick(() => {
        this.nodeController.removeBuilderNode();
      })
      // 销毁globalBuilderNode下的节点
      Button('dispose node').width(200).onClick(() => {
        this.nodeController.disposeNode();
      })
      NodeContainer(this.nodeController).backgroundColor('#FFEEF0')
    }
    .width('100%')
    .height('100%')
  }
}
```

![customcomponent-cross-ability](./figures/component-cross-ability.gif)

## 限制条件

### V1自定义组件不支持静态代码块

静态代码块用于初始化静态属性。
- 在\@Component或\@CustomDialog装饰的自定义组件中编写静态代码块时，该代码不会被执行。从API version 22开始，添加对静态代码块的校验，编译期告警提示静态代码块不生效。

  <!-- @[Static_code_V1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/StaticCodeV1.ets) -->   
  
  ``` TypeScript
  @Component
  struct MyComponent {
    static a: string = '';
    // 静态代码块不生效，a的值仍为空字符串''
    static {
      this.a = 'hello world';
    }
    // ...
  }
  ```


- 在\@ComponentV2装饰的自定义组件中支持使用。

  <!-- @[Static_code_V2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/createCustomComponents/entry/src/main/ets/component/StaticCodeV2.ets) -->   
  
  ``` TypeScript
  @ComponentV2
  struct MyComponent {
    static a: string = '';
    // 静态代码块生效，a的值变为'hello world'
    static {
      this.a = 'hello world';
    }
    // ...
  }
  ```

### \@Component与\@ComponentV2混用

在将\@Component装饰的自定义组件与\@ComponentV2装饰的自定义组件混合使用时，<!--RP1-->可参考[状态管理V1和V2混用场景](./arkts-v1-v2-mixusage-before-api-version.md)<!--RP1End-->。
