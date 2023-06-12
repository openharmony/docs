# arkui子系统ChangeLog

## cl.arkui.1 状态变量数据类型声明使用限制。

1. 所有的状态装饰器变量需要显式声明变量类型，不允许声明any。

    示例：

    ```ts
    // xxx.ets
    @Entry
    @Component
    struct DatePickerExample {
      // 错误写法: @State isLunar: any = false
      @State isLunar: boolean = false
    
      build() {
   		...
      }
    }
    ```
    
2. @State、@Provide、 @Link和@Consume四种状态变量的数据类型声明只能由简单数据类型或引用数据类型的其中一种构成。

    类型定义中的Length、ResourceStr、ResourceColor三个类型是简单数据类型或引用数据类型的组合，所以不能被以上四种状态装饰器变量使用。
    Length、ResourceStr、ResourceColor的定义请看文档[arkui-ts类型定义](../../../application-dev/reference/arkui-ts/ts-types.md)。

    示例：

    ```ts
    // xxx.ets
    @Entry
    @Component
    struct IndexPage {
      // 错误写法: @State message: string | Resource = 'Hello World'
      @State message: string = 'Hello World'
      // 错误写法: @State message: ResourceStr = $r('app.string.hello')
      @State resourceStr: Resource = $r('app.string.hello')

      build() {
        Row() {
          Column() {
            Text(`${this.message}`)
              .fontSize(50)
              .fontWeight(FontWeight.Bold)
          }
          .width('100%')
        }
        .height('100%')
      }
    }
    ```

    ![hello](../../../application-dev/quick-start/figures/hello.PNG)

**变更影响**

1. 如果状态装饰器变量没有显式声明变量类型，声明any，编译拦截会出现警告；
    ```ts
    // ArkTS:WARN Please define an explicit type, not any.
    @State isLunar: any = false
    ```
3. @State、@Provide、 @Link和@Consume四种状态变量使用框架提供的Length、ResourceStr、ResourceColor，
    编译拦截报错。
    
    ```ts
    /* ArkTS:ERROR The state variable type here is 'ResourceStr', it contains both a simple type and an object type,
      which are not allowed to be defined for state variable of a struct.*/
    @State message: ResourceStr = $r('app.string.hello')
    ```

**关键的接口/组件变更**

不涉及。

**适配指导**

1. 状态装饰器变量声明具体的变量类型替代any;
3. 因为Length(string|number|Resource), ResourceStr(string|Resource), ResourceColor(string|number|Color|Resource)
    的三个类型是简单数据类型或引用数据类型的组合，使用@State、@Provide、 @Link和@Consume四种状态变量场景参考以下修改：
    ```ts
    // 错误写法:
    @State message: ResourceStr = $r('app.string.hello')
    // 修正后的写法：
    @State resourceStr: Resource = $r('app.string.hello')
    ```

## cl.arkui.2 自定义组件成员变量初始化的规则与约束。

通过构造函数方法初始化成员变量，需要遵循如下规则：

| **从父组件中的变量(右)到子组件中的变量(下)** | **regular** | **@State** | **@Link** | **@Prop** | **@Provide** | **@Consume** | **@ObjectLink** |
| -------------------------- | ----------- | ---------- | --------- | --------- | ------------ | ------------ | --------------- |
| **regular**                | 支持          | 支持         | 支持        | 支持        | 不支持          | 不支持          | 支持              |
| **@State**                 | 支持          | 支持         | 支持        | 支持        | 支持           | 支持           | 支持              |
| **@Link**                  | 不支持         | 支持(1)      | 支持(1)     | 支持(1)     | 支持(1)        | 支持(1)        | 支持(1)           |
| **@Prop**                  | 支持          | 支持         | 支持        | 支持        | 支持           | 支持           | 支持              |
| **@Provide**               | 支持          | 支持         | 支持        | 支持        | 支持           | 支持           | 支持              |
| **@Consume**               | 不支持         | 不支持        | 不支持       | 不支持       | 不支持          | 不支持          | 不支持             |
| **@ObjectLink**            | 不支持         | 不支持        | 不支持       | 不支持       | 不支持          | 不支持          | 不支持             |

| **从父组件中的变量(右)到子组件中的变量(下)** | **@StorageLink** | **@StorageProp** | **@LocalStorageLink** | **@LocalStorageProp** |
| -------------------------- | ---------------- | ---------------- | --------------------- | --------------------- |
| **regular**                | 支持               | 不支持              | 不支持                   | 不支持                   |
| **@State**                 | 支持               | 支持               | 支持                    | 支持                    |
| **@Link**                  | 支持(1)            | 支持(1)            | 支持(1)                 | 支持(1)                 |
| **@Prop**                  | 支持               | 支持               | 支持                    | 支持                    |
| **@Provide**               | 支持               | 支持               | 支持                    | 支持                    |
| **@Consume**               | 不支持              | 不支持              | 不支持                   | 不支持                   |
| **@ObjectLink**            | 不支持              | 不支持              | 不支持                   | 不支持                   |

> **说明**
>
> **支持(1)**：必须使用`$`, 例如 `this.$varA`。  
> **regular**：未加修饰的常规变量。

不允许从父组件初始化`@StorageLink`, `@StorageProp`, `@LocalStorageLink`, `@LocalStorageProp`修饰的变量。

**变更影响**

1. 不允许从父组件初始化`@LocalStorageLink`, `@LocalStorageProp`修饰的变量，编译出现警告。
    ```ts
    @Entry
    @Component
    struct LocalStorageComponent {
        build() {
            Column() {
                Child({
                  /* ArkTS:WARN Property 'simpleVarName' in the custom component 'Child' cannot
                    initialize here (forbidden to specify). */
                  simpleVarName: 1,
                  /* ArkTS:WARN Property 'objectName' in the custom component 'Child' cannot
                    initialize here (forbidden to specify). */
                  objectName: new ClassA("x")
                })
            }
        }
    }
    @Component
    struct Child {
        @LocalStorageLink("storageSimpleProp") simpleVarName: number = 0;
        @LocalStorageProp("storageObjectProp") objectName: ClassA = new ClassA("x");
        build() {}
    }
    ```
2. 子组件的@ObjectLink变量不支持父组件装饰器变量的直接赋值，其父组件的源必须是数组的项或对象的属性，该数组或对象必现用`@State`、`@Link`、`@Provide`、`@Consume`或`@ObjectLink`装饰器修饰。
    ```ts
    let NextID : number = 0;

    @Observed class ClassA {
      public id : number;
      public c: number;
      constructor(c: number) {
        this.id = NextID++;
        this.c = c;
      }
    }

    @Component
    struct Child {
      @ObjectLink varA : ClassA;
      build() {
        Row() {
          Text('ViewA-' + this.varA.id)
        }
      }
    }

    @Component
    struct Parent {
      @Link linkValue: ClassA
      build() {
        Column() {
          /* ArkTS:ERROR The @Link property 'linkValue' cannot be assigned to
            the @ObjectLink property 'varA'.*/
          Child({ varA: this.linkValue })
        }
      }
    }
    ```

**关键的接口/组件变更**

不涉及。

**适配指导**
1. 构造子组件时，不对子组件的`@LocalStorageLink`, `@LocalStorageProp`修饰的变量进行。
    如果需要在父组件中修改子组件的`@LocalStorageLink`, `@LocalStorageProp`修饰的变量，则使用LocalStorage提供的API接口方法(比如set方法)赋值。
2. @ObjectLink的使用指导请参考文档[@ObjectLink使用指导](../../../application-dev/quick-start/arkts-observed-and-objectlink.md)。

## cl.arkui.3 List组件和Scroll组件onScrollBegin事件变更

List组件和Scroll组件onScrollBegin事件更名为onScrollFrameBegin事件，onScrollBegin事件中dx和dy参数分别表示X轴和Y轴方向滚动偏移量，更变为onScrollFrameBegin事件后使用offset参数表示滚动偏移量。onScrollFrameBegin事件新增ScrollState参数，用于表示当前时手指拖动滑动状态还是惯性滑动状态。

**变更影响**

onScrollBegin事件不能再使用，需要使用onScrollFrameBegin事件。

**关键接口/组件变更**

| 旧事件定义                                    | 新事件定义                                    |
| ---------------------------------------- | ---------------------------------------- |
| onScrollBegin(event: (dx: number, dy: number) => { dxRemain: number, dyRemain: number }) | onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number }) |

onScrollFrameBegin事件说明参考API接口文档：
- [Scroll组件事件](../../../application-dev/reference/arkui-ts/ts-container-scroll.md#事件)
- [List组件事件](../../../application-dev/reference/arkui-ts/ts-container-list.md#事件)

**适配指导**

onScrollBegin改成使用onScrollFrameBegin事件，onScrollBegin事件的dx/dy参数改成onScrollFrameBegin事件的offset参数。原本需要更滚动组件的滚动轴来确定是使用dx还dy参数，使用onScrollFrameBegin事件后，只需要直接使用offset参数。

onScrollBegin事件典型使用示例：
```ts
@Entry
@Component
struct NestedScroll {
  @State listPosition: number = 0; // 0代表滚动到List顶部，1代表中间值，2代表滚动到List底部。
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  private scrollerForScroll: Scroller = new Scroller()
  private scrollerForList: Scroller = new Scroller()

  build() {
    Flex() {
      Scroll(this.scrollerForScroll) {
        Column() {
          Text("Scroll Area")
            .width("100%").height("40%").backgroundColor(0X330000FF)
            .fontSize(16).textAlign(TextAlign.Center)
            .onClick(() => {
              this.scrollerForList.scrollToIndex(5)
            })

          List({ space: 20, scroller: this.scrollerForList }) {
            ForEach(this.arr, (item) => {
              ListItem() {
                Text("ListItem" + item)
                  .width("100%").height("100%").borderRadius(15)
                  .fontSize(16).textAlign(TextAlign.Center).backgroundColor(Color.White)
              }.width("100%").height(100)
            }, item => item)
          }
          .width("100%")
          .height("50%")
          .edgeEffect(EdgeEffect.None)
          .onReachStart(() => {
            this.listPosition = 0
          })
          .onReachEnd(() => {
            this.listPosition = 2
          })
          .onScrollBegin((dx: number, dy: number) => {
            if ((this.listPosition == 0 && dy >= 0) || (this.listPosition == 2 && dy <= 0)) {
              this.scrollerForScroll.scrollBy(0, -dy)
              return { dxRemain: dx, dyRemain: 0 }
            }
            this.listPosition = 1
            return { dxRemain: dx, dyRemain: dy };
          })

          Text("Scroll Area")
            .width("100%").height("40%").backgroundColor(0X330000FF)
            .fontSize(16).textAlign(TextAlign.Center)
        }
      }
      .width("100%").height("100%")
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding(20)
  }
}
```
改成onScrollFrameBegin事件参考代码如下：
```ts
@Entry
@Component
struct NestedScroll {
  @State listPosition: number = 0; // 0代表滚动到List顶部，1代表中间值，2代表滚动到List底部。
  private arr: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  private scrollerForScroll: Scroller = new Scroller()
  private scrollerForList: Scroller = new Scroller()

  build() {
    Flex() {
      Scroll(this.scrollerForScroll) {
        Column() {
          Text("Scroll Area")
            .width("100%").height("40%").backgroundColor(0X330000FF)
            .fontSize(16).textAlign(TextAlign.Center)
            .onClick(() => {
              this.scrollerForList.scrollToIndex(5)
            })

          List({ space: 20, scroller: this.scrollerForList }) {
            ForEach(this.arr, (item) => {
              ListItem() {
                Text("ListItem" + item)
                  .width("100%").height("100%").borderRadius(15)
                  .fontSize(16).textAlign(TextAlign.Center).backgroundColor(Color.White)
              }.width("100%").height(100)
            }, item => item)
          }
          .width("100%")
          .height("50%")
          .edgeEffect(EdgeEffect.None)
          .onReachStart(() => {
            this.listPosition = 0
          })
          .onReachEnd(() => {
            this.listPosition = 2
          })
          .onScrollFrameBegin((offset: number, state: ScrollState) => {
            if ((this.listPosition == 0 && offset >= 0) || (this.listPosition == 2 && offset <= 0)) {
              this.scrollerForScroll.scrollBy(0, -offset)
              return { offsetRemain: 0 }
            }
            this.listPosition = 1
            return { offsetRemain: offset };
          })

          Text("Scroll Area")
            .width("100%").height("40%").backgroundColor(0X330000FF)
            .fontSize(16).textAlign(TextAlign.Center)
        }
      }
      .width("100%").height("100%")
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding(20)
  }
}
```