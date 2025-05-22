# ArkUI Subsystem Changelog

## cl.arkui.1 Restrictions on Data Type Declarations of State Variables

1. The data types of state variables decorated by state decorators must be explicitly declared. They cannot be declared as **any**.

    Example:

    ```ts
    // xxx.ets
    @Entry
    @Component
    struct DatePickerExample {
      // Incorrect: @State isLunar: any = false
      @State isLunar: boolean = false
    
      build() {
      		...
      }
    }
    ```
    
2. The data type declaration of the **@State**, **@Provide**, **@Link**, or **@Consume** decorated state variables can consist of only one of the primitive data types or reference data types.

    The **Length**, **ResourceStr**, and **ResourceColor** types are combinations of primitive data types or reference data types. Therefore, they cannot be used by the aforementioned types of state variables.
    For details about the definitions of **Length**, **ResourceStr**, and **ResourceColor**, see [Types](../../../application-dev/reference/apis-arkui/arkui-ts/ts-types.md).

    Example:

    ```ts
    // xxx.ets
    @Entry
    @Component
    struct IndexPage {
      // Incorrect: @State message: string | Resource = 'Hello World'
      @State message: string = 'Hello World'
      // Incorrect: @State message: ResourceStr = $r('app.string.hello')
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

**Change Impacts**

1. If the data type of a state variable decorated by a state decorator is declared as **any**, a build error message will be displayed.
    ```ts
    // ArkTS:WARN Please define an explicit type, not any.
    @State isLunar: any = false
    ```
3. If the data type of a **@State**, **@Provide**, **@Link**, and or **@Consume** decorated state variable is Length, **ResourceStr**, or **ResourceColor**,
    a build error will occur.
    
    ```ts
    /* ArkTS:ERROR The state variable type here is 'ResourceStr', it contains both a simple type and an object type,
      which are not allowed to be defined for state variable of a struct.*/
    @State message: ResourceStr = $r('app.string.hello')
    ```

**Key API/Component Changes**

N/A

**Adaptation Guide**

1. Explicitly declare the data type for state variables decorated by state decorators.
3.  
    Adapt the **@State**, **@Provide**, **@Link**, and **@Consume** decorated variables based on the following code snippet so that they do not use the **Length(string|number|Resource)**, **ResourceStr(string|Resource)**, and **ResourceColor(string|number|Color|Resource)** types:
    ```ts
    // Incorrect:
    @State message: ResourceStr = $r('app.string.hello')
    // Corrected:
    @State resourceStr: Resource = $r('app.string.hello')
    ```

## cl.arkui.2 Initialization Rules and Restrictions of Custom Components' Member Variables

Comply with the following rules when using constructors to initialize member variables:

| **From the Variable in the Parent Component (Right) to the Variable in the Child Component (Below)**| **regular** | **@State** | **@Link** | **@Prop** | **@Provide** | **@Consume** | **@ObjectLink** |
| -------------------------- | ----------- | ---------- | --------- | --------- | ------------ | ------------ | --------------- |
| **regular**                | Supported         | Supported        | Supported       | Supported       | Not supported         | Not supported         | Supported             |
| **@State**                 | Supported         | Supported        | Supported       | Supported       | Supported          | Supported          | Supported             |
| **@Link**                  | Not supported        | Supported (1)     | Supported (1)    | Supported (1)    | Supported (1)       | Supported (1)       | Supported (1)          |
| **@Prop**                  | Supported         | Supported        | Supported       | Supported       | Supported          | Supported          | Supported             |
| **@Provide**               | Supported         | Supported        | Supported       | Supported       | Supported          | Supported          | Supported             |
| **@Consume**               | Not supported        | Not supported       | Not supported      | Not supported      | Not supported         | Not supported         | Not supported            |
| **@ObjectLink**            | Not supported        | Not supported       | Not supported      | Not supported      | Not supported         | Not supported         | Not supported            |

| **From the Variable in the Parent Component (Right) to the Variable in the Child Component (Below)**| **@StorageLink** | **@StorageProp** | **@LocalStorageLink** | **@LocalStorageProp** |
| -------------------------- | ---------------- | ---------------- | --------------------- | --------------------- |
| **regular**                | Supported              | Not supported             | Not supported                  | Not supported                  |
| **@State**                 | Supported              | Supported              | Supported                   | Supported                   |
| **@Link**                  | Supported (1)           | Supported (1)           | Supported (1)                | Supported (1)                |
| **@Prop**                  | Supported              | Supported              | Supported                   | Supported                   |
| **@Provide**               | Supported              | Supported              | Supported                   | Supported                   |
| **@Consume**               | Not supported             | Not supported             | Not supported                  | Not supported                  |
| **@ObjectLink**            | Not supported             | Not supported             | Not supported                  | Not supported                  |

> **NOTE**
>
> **Supported (1)**: The dollar sign ($) must be used, for example, **this.$varA**.
>
> **regular**: refers to a regular variable that is not decorated by any decorator.

**@StorageLink**, **@StorageProp**, **@LocalStorageLink**, and **@LocalStorageProp** variables cannot be initialized from the parent component.

**Change Impacts**

1. **@LocalStorageLink** and **@LocalStorageProp** variables cannot be initialized from the parent component. Otherwise, a build error message will be displayed.
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
2. The **@ObjectLink** decorated variable cannot be directly initialized from a decorated variable in the parent component. The source of the parent component must be an array item or object attribute decorated by **@State**, **@Link**, **@Provide**, **@Consume**, or **@ObjectLink**.
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

**Key API/Component Changes**

N/A

**Adaptation Guide**
1. When building a child component, do not assign values to the variables decorated by **@LocalStorageLink** and **@LocalStorageProp** in the child component.
    
    To change these variables from the parent component, use the API provided by the **LocalStorage** (such as the **set** API) to assign values to them.
    
2. For details about how to use **@ObjectLink**, see [\@Observed and \@ObjectLink Decorators: Observing Property Changes in Nested Class Objects](../../../application-dev/quick-start/arkts-observed-and-objectlink.md).

## cl.arkui.3 Change of the onScrollBegin Event of the \<List> and \<Scroll> Components

The **onScrollBegin** event of the **\<List>** and **\<Scroll>** components is renamed **onScrollFrameBegin**. In the **onScrollBegin** event, the amount to scroll by is indicated by the **dx** and **dy** parameters. In the **onScrollFrameBegin** event, it is indicated by the **offset** parameter. The **onScrollFrameBegin** event adds the **ScrollState** parameter to indicate whether the component is in the finger dragging or inertial scrolling state.

**Change Impacts**

The **onScrollBegin** event is deprecated and must be replaced with the **onScrollFrameBegin** event.

**Key API/Component Changes**

| Old Event                                   | New Event                                   |
| ---------------------------------------- | ---------------------------------------- |
| onScrollBegin(event: (dx: number, dy: number) => { dxRemain: number, dyRemain: number }) | onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number }) |

For details about the **onScrollFrameBegin** event, see the following:
- [Scroll Events](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-scroll.md#events)
- [List Events](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-list.md#events)

**Adaptation Guide**

Switch the event from **onScrollBegin** to **onScrollFrameBegin**, and use the **offset** parameter in **onScrollFrameBegin**, rather than the **dx** and **dy** parameters in **onScrollBegin**, to indicate the amount to scroll by.

Example of using the **onScrollBegin** event:
```ts
@Entry
@Component
struct NestedScroll {
  @State listPosition: number = 0; // 0 indicates scrolling to the top of the list, 1 indicates scrolling to the middle of the list, and 2 indicates scrolling to the bottom of the list.
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
Example of using the **onScrollFrameBegin** event:
```ts
@Entry
@Component
struct NestedScroll {
  @State listPosition: number = 0; // 0 indicates scrolling to the top of the list, 1 indicates scrolling to the middle of the list, and 2 indicates scrolling to the bottom of the list.
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
