# ArkUI Changelog

## cl.arkui.1 Restrictions on Data Type Declarations of State Variables

The data types of state variables decorated by state decorators must be explicitly declared. They cannot be declared as **any**.

**Example**

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

**Change Impact**

If the data type of a state variable decorated by a state decorator is declared as **any**, the compiler reports an issue at the ERROR level (previously WARN level).

```ts
// ArkTS:ERROR Please define an explicit type, not any.
@State isLunar: any = false
```

**Key API/Component Changes**

N/A

**Adaptation Guide**

Define an explicit type for the state decorator decorated variables.


## cl.arkui.2 Initialization Rules and Restrictions of Custom Components' Member Variables

**@LocalStorageLink** and **@LocalStorageProp** decorated variables cannot be initialized from the parent component.

**Example**

```ts
let NextID: number = 0;

@Observed
class ClassA {
  public id: number;
  public c: number;

  constructor(c: number) {
    this.id = NextID++;
    this.c = c;
  }
}

@Entry
@Component
struct LocalStorageComponent {
  build() {
    Column() {
      Child({
        /* ArkTS:ERROR Property 'simpleVarName' in the custom component 'Child' cannot
          initialize here (forbidden to specify). */
        simpleVarName: 1,
        /* ArkTS:ERROR Property 'objectName' in the custom component 'Child' cannot
          initialize here (forbidden to specify). */
        objectName: new ClassA(1)
      })
    }
  }
}

@Component
struct Child {
  @LocalStorageLink("storageSimpleProp") simpleVarName: number = 0;
  @LocalStorageProp("storageObjectProp") objectName: ClassA = new ClassA(1);

  build() {
  }
}
```

**Change Impact**

If a variable decorated by **@LocalStorageLink** or **@LocalStorageProp** is initialized from the parent component, the compiler reports an issue at the ERROR level (previously WARN level).

**Key API/Component Changes**

N/A

**Adaptation Guide**

When constructing a child component, do not assign values to the variables decorated by **\@LocalStorageLink** or **\@LocalStorageProp** in the child component.

To change the values of such variables from the parent component, assign values through the API (such as the **set** method) provided by LocalStorage.



## cl.arkui.3 Support for the undefined Parameter by Universal Events

Added support for passing **undefined** as a parameter for universal events (click, touch, show/hide, key, focus, mouse, and component area change events).

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Example {
  build() {
    Button("test")
    .onClick(()=>{
      console.log("click");
    })
    .onClick(undefined)
  }
}
```

**Change Impact**

If the event callback parameter is **undefined**, the system will not respond to the configured event callback.

**Key API/Component Changes**

N/A

**Adaptation Guide**

If the event parameter is set to **undefined**, the event is disabled. Set the parameter based on the use case.


## cl.arkui.4 Initialization Requirement Change of \@Prop/\@BuilderParam Decorated Variables

**Example**

```ts
// xxx.ets
@Entry
@Component
struct Parent {
  @State message: string = 'Parent'
  build() {
    Column() {
      Child() // Compile time error.
    }
  }
}

@Component
struct Child {
  @Prop message: string
  build() {
    Column() {
      
    }
  }
}
```

**Change Impact**

If the @Prop or @BuilderParam decorated variable is not initialized locally or initialized from its parent component, a compile time error will occur.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Assign an initial value to the @Prop or @BuilderParam decorated variable or pass the value from the parent component.


## cl.arkui.5 Initial Value Requirement Change of @BuilderParam Decorated Variables

**Example**

```ts
// xxx.ets
@Builder
function builderFunction() {
  Text('Hello Builder')
}

function normal () {

}

@Component
struct Index {
  @BuilderParam builderParam: ()=>void = builderFunction
  @BuilderParam builderParam2: ()=>void = normal // Compile time error.
  build() {
    Column() {

    }
  }
}
```

**Change Impact**

If the initial value of the @BuilderParam decorated variable is not an @Builder method, the compilation will fail.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Pass in an @Builder method as the initial value of the @BuilderParam variable.


## cl.arkui.6 Type Change of the searchButton Attribute in the \<Search> Component from SearchButtonOption to SearchButtonOptions

**Change Impact**

If the **SearchButtonOption** type is explicitly used, the compilation will fail.

**Key API/Component Changes**

The type of the **searchButton** attribute is changed from **SearchButtonOption** to **SearchButtonOptions**.

**Adaptation Guide**

Change **SearchButtonOption** to **SearchButtonOptions**.


## cl.arkui.7 Change of the ScrollState Enum Rules

The table lists the rules for the **ScrollState** enums in API version 9 and earlier versions:

| Name| Description| 
| -------- | -------- |
| Idle | Idle. The list enters this state when an API in the controller is used to scroll the list or when the scrollbar is dragged.| 
| Scroll | Scrolling. The list enters this state when the user drags the list to scroll.| 
| Fling | Inertial scrolling. The list enters this state when inertial scrolling occurs or when the list bounces back after being released from a fling.| 

The table lists the rules for the **ScrollState** enums in API version 10 and later versions:

| Name| Description| 
| -------- | -------- |
| Idle | Idle. The list enters this state when it is not scrolling or an API in the controller that does not apply an animation is called.| 
| Scroll | Scrolling. The list enters this state when the user drags the list, scrollbar, or mouse wheel to scroll the list.| 
| Fling | Inertial scrolling. The list enters this state when: inertial scrolling occurs after a fling; the list bounces back after being released from a fling; inertial scrolling occurs after quick dragging of the built-in scrollbar; scrolling occurs after an API in the controller that applies an animation is called.| 

The table below lists the changes in the **ScrollState** enums.

| Scenario| API Version 9 and Earlier| API Version 10 and Later| 
| -------- | -------- | -------- |
| Finger dragging| Scroll | Scroll | 
| Inertial scrolling| Fling | Fling | 
| Cross-boundary bouncing| Fling | Fling | 
| Scrolling by mouse wheel| Idle | Scroll | 
| Scrollbar dragging| Idle | Scroll | 
| Scrolling by the scrolling controller (with animation)| Idle | Fling | 
| Scrolling by the scrolling controller (without animation)| Idle | Idle | 

**Change Impact**

1. **ScrollState** is available since API version 7. The change is introduced in API version 10 and does not affect the use in API version 9 and earlier versions.

2. Since API version 10, the use of **ScrollState** is affected in the **onScroll** event of the **\<List>** component.

**Key API/Component Changes**

 

- [List Events](../../../application-dev/reference/arkui-ts/ts-container-list.md#events)
- [ScrollState](../../../application-dev/reference/arkui-ts/ts-container-list.md#scrollstate)

**Adaptation Guide**

When the **\<List>** component is bound to the **onScroll** event and reports the scrolling status through the event, it must comply with the new rules since API version 10.

The code snippet is as follows:

```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }
        }, item => item)
      }
      .listDirection(Axis.Vertical) // Arrangement direction
      .edgeEffect(EdgeEffect.Spring) // Set the edge scrolling effect to Spring.
      .onScroll((scrollOffset: number, scrollState: ScrollState) => {
        console.log(`onScroll scrollState = ${ScrollState[scrollState]}, scrollOffset = ${[scrollOffset]}`)
      })
      .width('90%')
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xDCDCDC)
    .padding({ top: 5 })
  }
}
```


## cl.arkui.8 Change of Use Case Restrictions of ArkUI Built-in Components

Restricted the use of ArkUI built-in components to the build methods of structs, **pageTransition** method, or @Builder decorated functions.

**Example**

```
@Entry
@Component
struct Index {
  build() {
    Row() {
    }

  }
}
// ERROR:UI component 'Text' cannot be used in this place.
Text('Hello World')
```

**Change Impact**

A build error will occur if a built-in component is not used in a build method of a struct, **pageTransition** method, or any @Builder decorated function.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Use ArkUI built-in components only in build methods of structs, **pageTransition** methods, and @Builder decorated functions.


## cl.ArkUI.9 Change from Shallow Copy to Deep Copy of Objects by @Prop

**Change Impact**

In API version 9, @Prop supports shallow copy of objects. The specific behavior is as follows:

- Object type: shallow copy of all properties returned by **Object.keys(propObj)**. That is, only the outermost object is copied, and the property in the object points to the data source of the original parent component.

- Array type: shallow copy of all array items. That is, only the outermost array is copied. Other behaviors are the same as those of the Object type.

- The prototype of the object and array is copied.

Since API version 10, @Prop supports deep copy of objects. The specific behavior is as follows:

- Object type: deep copy of all properties returned by **Object.keys(propObj)**.

- Array type: deep copy of all array items.

- The prototype of the object and array is copied.

**Adaptation Guide**

The impact of the change on UI rendering mainly lies in @ObjectLink-related scenarios, because @ObjectLink functions as a proxy for its decorated object properties.

The following shows an example:

API version 9: If @Prop objArray in the PropClassArray component changes the property of ClassA or sets a new array item, @ObjectLink obj in ObjectLinkClassA created by the parent component StateClassAArray changes.

The update is caused by the shallow copy from @State stateClassAArray in the parent component StateClassAArray to @Prop objArray in the child component PropClassAArray. The shallow copy copies only the reference of array items, and therefore the data source is changed. As @ObjectLink functions as a proxy for the properties of the data source, the update of @ObjectLink obj (constructed from the StateClassAArray component) in the ObjectLinkClassA component is triggered.

API version 10: In the preceding scenario, the copy from @State stateClassAArray in the parent component StateClassAArray to @Prop objArray in the child component PropClassAArray is a deep copy. As the object of ClassA is completely copied, the data source is not changed, and the update of @ObjectLink obj (constructed from the StateClassAArray component) in the ObjectLinkClassA component is not triggered.

![en-us_image_0000001588291546](figures/en-us_image_0000001588291546.png)

```ts
let nextId = 0;

@Observed
class ClassA  {
  id : number;
  a : number;
  constructor(a : number = 0) {
    this.id = nextId++;
    this.a = a;
  }
}

@Component
struct ObjectLinkClassA {
  @ObjectLink obj : ClassA;

  build() {
    Row() {
      Text(`ObjectLink: obj: ${this.obj.a}`)
        .height(100)
        .onClick(() => {
          this.obj.a += 1;
          console.info(`ObjectLink onClick ClassA property changed to  ${this.obj.a}`)
        })
    }.border({width: 3, color: Color.Red})
  }
}

@Component
struct PropClassAArray {
  @Prop objArray : Array<ClassA> = [];

  build() {
    Column() {
      Text(`green box: @Prop : Array<ObjectClassA> item [0] + [1]`)
      Row() {
        ObjectLinkClassA({ obj:  this.objArray[0] })
        Text("[0] Assign new ClassA")
          .height(100)
          .onClick(() => {
            this.objArray[0] = new ClassA();
            console.info(`PropClassAArray[0] onClick ClassA object assign ${this.objArray[0].a}`)
          })
        Text("Change ClassA property")
          .height(100)
          .onClick(() => {
            this.objArray[0].a += 1;
            console.info(`PropClassAArray[1] onClick ClassA property change  ${this.objArray[1].a}`)
          })
      }
    }.border({width: 3, color: Color.Green})
  }
}

@Entry
@Component
struct StateClassAArray {
  @State stateClassAArray : Array<ClassA> = [ new ClassA(), new ClassA() ];

  build() {
    Column() {
      Column() {
        Text("Red box: @ObjectLink from @State array item[0]")
        Row() {
          ObjectLinkClassA({obj : this.stateClassAArray[0] })
          Text("Assign new ClassA")
            .height(100)
            .onClick(() => {
              this.stateClassAArray[0] = new ClassA();
              console.info(`StateClassAArray[0] onClick ClassA object assign ${this.stateClassAArray[0].a}`)
            })
          Text("Change ClassA property")
            .height(100)
            .onClick(() => {
              this.stateClassAArray[0].a += 1;
              console.info(`StateClassAArray onClick stateClassAArray[0] changed to  ${this.stateClassAArray[0].a}`)
            })
        }

      }.border({width: 3, color: Color.Blue})

      Divider().height(5)

      // Shallow copy in API version 9: Only the reference pointing to the source array item is copied, and the ClassA instance itself is not copied.
      // Deep copy in API version 10: The this.stateClassAArray instance is completely copied, including its array items.
      PropClassAArray({ objArray: this.stateClassAArray })
    }
  }
}
```


## cl.arkui.10 Reporting of Unexpected Number of @Extend/@AnimatableExtend Parameters

The @Extend and @AnimatableExtend decorators allow for only one parameter.

**Change Impact**

When there are multiple parameters for the @Extend/@AnimatableExtend decorator, a compilation error is reported.

**Example (Incorrect)**

```ts
// xxx.ets

@Extend(Text, Button)  // Compilation error: @Extend should have one and only one parameter.
function fancy() {
  .width(100)
}

@AnimatableExtend(Text, Polyline)  //Compilation error: @AnimatableExtend should have one and only one parameter.
function fancy2() {
  .height(100)
}

@Entry
@Component
struct Example {
  build() {
    Column() {
      Text('text')
        .fancy()
        .fancy2()
    }
  }
}
```

**Key API/Component Changes**

N/A

**Adaptation Guide**

Make sure the @Extend and @AnimatableExtend decorators contain only one parameter.

The code snippet is as follows:

```ts
// xxx.ets

@Extend(Text)
function fancy() {
  .width(100)
}

@AnimatableExtend(Text)
function fancy2() {
  .height(100)
}

@Entry
@Component
struct Example {
  build() {
    Column() {
      Text('text')
        .fancy()
        .fancy2()
    }
  }
}
```


## cl.arkui.11 Reporting of @Link/@ObjectLink Member Variables Not Being Configured from Parent Components

The value of an @Link or @ObjectLink decorated member variable in a component must be from the parent component.

**Change Impact**

When the value of an @Link/@ObjectLink decorated member variable in a component is not configured from the parent component, a compilation error is reported.

**Example (Incorrect)**

```ts
// xxx.ets

@Observed
class Count {
  message: string = 'count'
}

@Entry
@Component
struct Parent {
  @State state1: string = 'state1';
  @State state2: Count = new Count();
  build() {
    Column() {
      Child()  // Compilation error: Property 'link' in the custom component 'Child' is missing (mandatory to specify).
               // Compilation error: Property 'objectLink' in the custom component 'Child' is missing (mandatory to specify).
    }
  }
}

@Component
struct Child {
  @Link link: string;
  @ObjectLink objectLink: Count;
  build() {
    Column() {
      Text(this.link)
        .fontSize(50)
      Text(this.objectLink.message)
        .fontSize(50)
    }
  }
}
```

**Key API/Component Changes**

N/A

**Adaptation Guide**

The value of an @Link or @ObjectLink decorated member variable in a component must be from the parent component.

The code snippet is as follows:

```ts
// xxx.ets

@Observed
class Count {
  message: string = 'count'
}

@Entry
@Component
struct Parent {
  @State state1: string = 'state1';
  @State state2: Count = new Count();
  build() {
    Column() {
      Child({link: $state1, objectLink: this.state2})
    }
  }
}

@Component
struct Child {
  @Link link: string;
  @ObjectLink objectLink: Count;
  build() {
    Column() {
      Text(this.link)
        .fontSize(50)
      Text(this.objectLink.message)
        .fontSize(50)
    }
  }
}
```


## cl.arkui.12 Behavior Change of the onReady Event for \<Canvas>

**NOTE**

The **onReady** event is triggered when the component is ready or when the component size changes. After it is triggered, the canvas is cleared.

**Example**

```ts
@Entry
@Component
struct OnReadyDiff {
  @State message: string = 'init '
  @State isShow: boolean = false
  @State myHeight: number = 300
  private settings: RenderingContextSettings = new RenderingContextSettings(true);
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings);

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        Button('ChangePosition')
          .onClick(()=>{
            this.isShow = !this.isShow
          })
        if (this.isShow) {
          Button('new button')
            .height(200)
        }
        Button('ChangeHeight')
          .onClick(()=>{
            this.myHeight = this.myHeight==300?500:300
          })

        Canvas(this.context)
          .width(300)
          .height(this.myHeight)
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.fillRect(0, 0, 100, 100)
            this.message += 'a '
          })
        Button('draw another')
          .onClick(()=>{
            this.context.fillRect(100, 100, 100, 100)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

API version 9: The **onReady** event is triggered when the component is ready, when the component location changes, or when the component size changes.

![stack](figures/api9onReady.gif)

API version 10 and later: The **onReady** event is triggered when the component is ready or when the component size changes. It is not triggered when the component location changes.

![stack](figures/api10onReady.gif)

**Change Impact**

When the component location changes, the **onReady** event is triggered in API version 9 and earlier versions, but not in API version 10 and later versions.


## cl.arkui.13 Visibility Change of the menus Attribute in \<Navigation>

**Change Impact**

The **value** sub-attribute of the **menus** attribute is not displayed. To display the value, you can use a custom builder.

**Example**

```ts
@Entry
@Component
struct Index {
  build() {
    Column() {
      Navigation() {
        Text('Navigation')
      }.title("Navigation Menu")
      .menus([
        {icon: 'common/image/icon.png', value: 'menu1'},
        {icon: 'common/image/icon.png', value: 'menu2'},
        {icon: 'common/image/icon.png', value: 'menu3'}
      ])
    }
  }
}
```

In API version 9, the **value** sub-attribute of the **menus** attribute is displayed.

![Navigation](figures/navigation_menu_api9.png)

In API version 10, the **value** sub-attribute of the **menus** attribute is not displayed.

![Navigation](figures/navigation_menu_api10.png)


## cl.arkui.14 Change of the Default Display Position for Free Mode of the titleMode Attribute in \<Navigation>

**Change Impact**

1. In the **\<Navigation>** component, the display position of a custom title with **titleMode** set to **Full** is the same as that with **titleMode** set to **Free**.

2. If a custom title is used with a label in Free mode, the label is deviated rightwards.

**Example**

```ts
@Entry
@Component
struct Index {
  @Builder NavigationTile() {
    Column() {
      Text('title').fontColor('#182431').fontSize(30).lineHeight(41)
      Text('subTitle').fontColor('#182431').fontSize(14).lineHeight(19).margin(top:2, bottom: 20)
    }
  }

  build() {
    Column() {
      Navigation() {
        Text('Navigation')
      }.title(this.NavigationTitle)
       .titleMode(NavigationTitleMode.Free)
       .menus([
        {icon: 'common/image/icon.png', value: 'menu1'}
       ])
    }
  }
}
```

Display position in Free mode in API version 9

![Navigation](figures/navigation_title_mode_free_sdk9.png)

Display position in Free mode in API version 10, which is the same as that in Full mode

![Navigation](figures/navigation_title_mode_free_sdk10.png)
