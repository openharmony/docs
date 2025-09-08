# \@Reusable Decorator: Reusing Components
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @liyujie43-->
<!--Designer: @lizhan-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

The \@Reusable decorator enables reuse of view nodes, component instances, and state contexts for custom components, eliminating redundant creation and destruction to enhance performance.

## Overview

When applied to a custom component, the \@Reusable decorator marks the component as reusable. Used in conjunction with the [\@Component decorator](arkts-create-custom-components.md#component), components decorated with \@Reusable are moved to a reuse cache (along with its corresponding JS object) when removed from the component tree. Subsequent component creation will reuse cached nodes, significantly reducing instantiation time.

> **NOTE**
>
> The \@Reusable decorator is supported since API version 10 and can be used in ArkTS.
>
> For details about the principles, optimization methods, and use scenarios of component reuse, see [Component Reuse](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-component-reuse).
>
> When a component is decorated with \@Reusable, the ArkUI framework calls the component's [aboutToReuse](../../../application-dev/reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttoreuse10) and [aboutToRecycle](../../../application-dev/reference/apis-arkui/arkui-ts/ts-custom-component-lifecycle.md#abouttorecycle10) APIs when the component is added to or removed from the tree. Therefore, you should implement most reuse logic within these APIs.
>
> For components containing multiple reusable child components, use [reuseId](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-reuse-id.md) to distinguish between different reusable structures.
>

## Constraints

- The \@Reusable decorator only applies to custom components.

```ts
import { ComponentContent } from "@kit.ArkUI";

// Adding @Reusable to @Builder causes a compilation error (not applicable to builders).
// @Reusable
@Builder
function buildCreativeLoadingDialog(closedClick: () => void) {
  Crash()
}

@Component
export struct Crash {
  build() {
    Column() {
      Text("Crash")
        .fontSize(12)
        .lineHeight(18)
        .fontColor(Color.Blue)
        .margin({
          left: 6
        })
    }.width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  private uiContext = this.getUIContext();

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('Index')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          let contentNode = new ComponentContent(this.uiContext, wrapBuilder(buildCreativeLoadingDialog), () => {
          });
          this.uiContext.getPromptAction().openCustomDialog(contentNode);
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

- When an @Reusable decorated custom component is reused, the **aboutToReuse** API is invoked recursively for the component and all its child components. Avoid modifying state variables of the parent component in its child component's **aboutToReuse** API. Such modification will not take effect. To update the parent component's state variables, use **setTimeout** to delay execution, moving the task outside the scope of component reuse.


  **Incorrect Usage**

  Modifying a parent component's state variable in its child component's **aboutToReuse** API:

  ```ts
  class BasicDataSource implements IDataSource {
    private listener: DataChangeListener | undefined = undefined;
    public dataArray: number[] = [];

    totalCount(): number {
      return this.dataArray.length;
    }

    getData(index: number): number {
      return this.dataArray[index];
    }

    registerDataChangeListener(listener: DataChangeListener): void {
      this.listener = listener;
    }

    unregisterDataChangeListener(listener: DataChangeListener): void {
      this.listener = undefined;
    }
  }

  @Entry
  @Component
  struct Index {
    private data: BasicDataSource = new BasicDataSource();

    aboutToAppear(): void {
      for (let index = 1; index < 20; index++) {
        this.data.dataArray.push(index);
      }
    }

    build() {
      List() {
        LazyForEach(this.data, (item: number, index: number) => {
          ListItem() {
            ReuseComponent({ num: item })
          }
        }, (item: number, index: number) => index.toString())
      }.cachedCount(0)
    }
  }

  @Reusable
  @Component
  struct ReuseComponent {
    @State num: number = 0;

    aboutToReuse(params: ESObject): void {
      this.num = params.num;
    }

    build() {
      Column() {
        Text('ReuseComponent num:' + this.num.toString())
        ReuseComponentChild({ num: this.num })
        Button('plus')
          .onClick(() => {
            this.num += 10;
          })
      }
      .height(200)
    }
  }

  @Component
  struct ReuseComponentChild {
    @Link num: number;

    aboutToReuse(params: ESObject): void {
      this.num = -1 * params.num;
    }

    build() {
      Text('ReuseComponentChild num:' + this.num.toString())
    }
  }
  ```

  **Correct Usage**

  To modify a parent component's state variable in a child component's **aboutToReuse** API, use **setTimeout** to move the modification outside the scope of component reuse:

  ```ts
  class BasicDataSource implements IDataSource {
    private listener: DataChangeListener | undefined = undefined;
    public dataArray: number[] = [];

    totalCount(): number {
      return this.dataArray.length;
    }

    getData(index: number): number {
      return this.dataArray[index];
    }

    registerDataChangeListener(listener: DataChangeListener): void {
      this.listener = listener;
    }

    unregisterDataChangeListener(listener: DataChangeListener): void {
      this.listener = undefined;
    }
  }

  @Entry
  @Component
  struct Index {
    private data: BasicDataSource = new BasicDataSource();

    aboutToAppear(): void {
      for (let index = 1; index < 20; index++) {
        this.data.dataArray.push(index);
      }
    }

    build() {
      List() {
        LazyForEach(this.data, (item: number, index: number) => {
          ListItem() {
            ReuseComponent({ num: item })
          }
        }, (item: number, index: number) => index.toString())
      }.cachedCount(0)
    }
  }

  @Reusable
  @Component
  struct ReuseComponent {
    @State num: number = 0;

    aboutToReuse(params: ESObject): void {
      this.num = params.num;
    }

    build() {
      Column() {
        Text('ReuseComponent num:' + this.num.toString())
        ReuseComponentChild({ num: this.num })
        Button('plus')
          .onClick(() => {
            this.num += 10;
          })
      }
      .height(200)
    }
  }

  @Component
  struct ReuseComponentChild {
    @Link num: number;

    aboutToReuse(params: ESObject): void {
      setTimeout(() => {
        this.num = -1 * params.num;
      }, 1)
    }

    build() {
      Text('ReuseComponentChild num:' + this.num.toString())
    }
  }
  ```

- **ComponentContent** does not support passing \@Reusable decorated custom components.

```ts
import { ComponentContent } from "@kit.ArkUI";

@Builder
function buildCreativeLoadingDialog(closedClick: () => void) {
  Crash()
}

// The dialog box pops up correctly if @Reusable is commented out; it crashes when @Reusable is added.
@Reusable
@Component
export struct Crash {
  build() {
    Column() {
      Text("Crash")
        .fontSize(12)
        .lineHeight(18)
        .fontColor(Color.Blue)
        .margin({
          left: 6
        })
    }.width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
  }
}

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  private uiContext = this.getUIContext();

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('Index')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          // ComponentContent is based on BuilderNode, which does not support @Reusable decorated custom components.
          let contentNode = new ComponentContent(this.uiContext, wrapBuilder(buildCreativeLoadingDialog), () => {
          });
          this.uiContext.getPromptAction().openCustomDialog(contentNode);
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

- Nesting \@Reusable decorators is not recommended, as it increases memory usage, reduces reuse efficiency, and complicates maintenance. Nested usage creates additional cache pools with identical tree structures, leading to low reuse efficiency. In addition, it complicates lifecycle management and makes resource and variable sharing difficult.


## Use Scenarios

### Dynamic Layout Update

Repeatedly creating and removing views can trigger frequent layout calculations, which may affect frame rates. Component reuse avoids unnecessary view creation and layout recalculations, improving performance.
In the following example, the **Child** custom component is marked as reusable. Clicking the button updates **Child**, triggering reuse.

```ts
// xxx.ets
export class Message {
  value: string | undefined;

  constructor(value: string) {
    this.value = value;
  }
}

@Entry
@Component
struct Index {
  @State switch: boolean = true;

  build() {
    Column() {
      Button('Hello')
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .onClick(() => {
          this.switch = !this.switch;
        })
      if (this.switch) {
        // If only one reusable component is used, reuseId is optional.
        Child({ message: new Message('Child') })
          .reuseId('Child')
      }
    }
    .height("100%")
    .width('100%')
  }
}

@Reusable
@Component
struct Child {
  @State message: Message = new Message('AboutToReuse');

  aboutToReuse(params: Record<string, ESObject>) {
    console.info("Recycle====Child==");
    this.message = params.message as Message;
  }

  build() {
    Column() {
      Text(this.message.value)
        .fontSize(30)
    }
    .borderWidth(1)
    .height(100)
  }
}
```

### List Scrolling with LazyForEach

- When a user scrolls a list containing a large amount of data, frequent creation and destruction of list items can cause lag and performance issues. The reuse mechanism of the **List** component can reuse the existing list items to improve the scrolling smoothness.

- In the following example, the **CardView** custom component is marked as reusable. Scrolling the list up or down triggers reuse of **CardView**.

```ts
class MyDataSource implements IDataSource {
  private dataArray: string[] = [];
  private listener: DataChangeListener | undefined;

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
  }

  public reloadListener(): void {
    this.listener?.onDataReloaded();
  }

  public registerDataChangeListener(listener: DataChangeListener): void {
    this.listener = listener;
  }

  public unregisterDataChangeListener(listener: DataChangeListener): void {
    this.listener = undefined;
  }
}

@Entry
@Component
struct ReuseDemo {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 1; i < 1000; i++) {
      this.data.pushData(i + "");
    }
  }

  // ...
  build() {
    Column() {
      List() {
        LazyForEach(this.data, (item: string) => {
          ListItem() {
            CardView({ item: item })
          }
        }, (item: string) => item)
      }
    }
  }
}

// Reusable component
@Reusable
@Component
export struct CardView {
  // Variables decorated with @State will update; others will not.
  @State item: string = '';

  aboutToReuse(params: Record<string, Object>): void {
    this.item = params.item as string;
  }

  build() {
    Column() {
      Text(this.item)
        .fontSize(30)
    }
    .borderWidth(1)
    .height(100)
  }
}
```

### List Scrolling with if Statements

In the following example, the **OneMoment** custom component is marked as reusable. Scrolling the list up or down triggers reuse of **OneMoment**. **reuseId** can be used to assign a reuse group for reusable components. Components with the same **reuseId** are reused within the same reuse group. A single reusable component does not require **reuseId**. Using **reuseId** to identify reusable components avoids repeated deletion and re-creation logic in **if** statements, improving reuse efficiency and performance.

```ts
@Entry
@Component
struct Index {
  private dataSource = new MyDataSource<FriendMoment>();

  aboutToAppear(): void {
    for (let i = 0; i < 20; i++) {
      let title = i + 1 + "test_if";
      this.dataSource.pushData(new FriendMoment(i.toString(), title, 'app.media.app_icon'));
    }

    for (let i = 0; i < 50; i++) {
      let title = i + 1 + "test_if";
      this.dataSource.pushData(new FriendMoment(i.toString(), title, ''));
    }
  }

  build() {
    Column() {
      // TopBar()
      List({ space: 3 }) {
        LazyForEach(this.dataSource, (moment: FriendMoment) => {
          ListItem() {
            // Use reuseId to control component reuse.
            OneMoment({ moment: moment })
              .reuseId((moment.image !== '') ? 'withImage' : 'noImage')
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(0)
    }
  }
}

class FriendMoment {
  id: string = '';
  text: string = '';
  title: string = '';
  image: string = '';
  answers: Array<ResourceStr> = [];

  constructor(id: string, title: string, image: string) {
    this.text = id;
    this.title = title;
    this.image = image;
  }
}

@Reusable
@Component
export struct OneMoment {
  @Prop moment: FriendMoment;

  // Only components with the same reuseId trigger reuse.
  aboutToReuse(params: ESObject): void {
    console.log("=====aboutToReuse====OneMoment==reused==" + this.moment.text);
  }

  build() {
    Column() {
      Text(this.moment.text)
      // Conditional rendering with if
      if (this.moment.image !== '') {
        Flex({ wrap: FlexWrap.Wrap }) {
          Image($r(this.moment.image)).height(50).width(50)
          Image($r(this.moment.image)).height(50).width(50)
          Image($r(this.moment.image)).height(50).width(50)
          Image($r(this.moment.image)).height(50).width(50)
        }
      }
    }
  }
}

class BasicDataSource<T> implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: T[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): T {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }
}

export class MyDataSource<T> extends BasicDataSource<T> {
  private dataArray: T[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): T {
    return this.dataArray[index];
  }

  public pushData(data: T): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}
```

### List Scrolling with ForEach

When the **ForEach** rendering control syntax is used to create reusable custom components, the full-expansion behavior of **ForEach** prevents component reuse. In the example: Clicking **update** successfully refreshes data, but **ListItemView** cannot be reused during list scrolling; clicking **clear** and then **update** allows **ListItemView** to be reused, as this triggers re-creation of multiple destroyed custom components within a single frame.

```ts
// xxx.ets
class MyDataSource implements IDataSource {
  private dataArray: string[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
  }

  public registerDataChangeListener(listener: DataChangeListener): void {
  }

  public unregisterDataChangeListener(listener: DataChangeListener): void {
  }
}

@Entry
@Component
struct Index {
  private data: MyDataSource = new MyDataSource();
  private data02: MyDataSource = new MyDataSource();
  @State isShow: boolean = true;
  @State dataSource: ListItemObject[] = [];

  aboutToAppear() {
    for (let i = 0; i < 100; i++) {
      this.data.pushData(i.toString());
    }

    for (let i = 30; i < 80; i++) {
      this.data02.pushData(i.toString());
    }
  }

  build() {
    Column() {
      Row() {
        Button('clear').onClick(() => {
          for (let i = 1; i < 50; i++) {
            this.dataSource.pop();
          }
        }).height(40)

        Button('update').onClick(() => {
          for (let i = 1; i < 50; i++) {
            let obj = new ListItemObject();
            obj.id = i;
            obj.uuid = Math.random().toString();
            obj.isExpand = false;
            this.dataSource.push(obj);
          }
        }).height(40)
      }

      List({ space: 10 }) {
        ForEach(this.dataSource, (item: ListItemObject) => {
          ListItem() {
            ListItemView({
              obj: item
            })
          }
        }, (item: ListItemObject) => {
          return item.uuid.toString();
        })

      }.cachedCount(0)
      .width('100%')
      .height('100%')
    }
  }
}

@Reusable
@Component
struct ListItemView {
  @ObjectLink obj: ListItemObject;
  @State item: string = '';

  aboutToAppear(): void {
    // On first update click, scrolling fails to trigger reuse due to the full-expansion behavior of ForEach.
    console.log("=====aboutToAppear=====ListItemView==created==" + this.item);
  }

  aboutToReuse(params: ESObject) {
    this.item = params.item;
    // Reuse succeeds after clear and update are clicked
    // (which recreates destroyed components in one frame).
    console.log("=====aboutToReuse====ListItemView==reused==" + this.item);
  }

  build() {
    Column({ space: 10 }) {
      Text(`${this.obj.id}.Title`)
        .fontSize(16)
        .fontColor('#000000')
        .padding({
          top: 20,
          bottom: 20,
        })

      if (this.obj.isExpand) {
        Text('')
          .fontSize(14)
          .fontColor('#999999')
      }
    }
    .width('100%')
    .borderRadius(10)
    .backgroundColor(Color.White)
    .padding(15)
    .onClick(() => {
      this.obj.isExpand = !this.obj.isExpand;
    })
  }
}

@Observed
class ListItemObject {
  uuid: string = "";
  id: number = 0;
  isExpand: boolean = false;
}
```

### Grid

In the following example, the @Reusable decorator is used to decorate the custom component **ReusableChildComponent** in **GridItem**, indicating that the component can be reused.
The **aboutToReuse** API is triggered when the component is obtained from the reuse cache and added to the component tree during grid scrolling. This allows you to update the component's state variables to display correct content.
Note: There is no need to update state variables that automatically synchronize values (such as variables decorated with [\@Link](arkts-link.md), [\@StorageLink](arkts-appstorage.md#storagelink), [\@ObjectLink](arkts-observed-and-objectlink.md), or [\@Consume](arkts-provide-and-consume.md)) in **aboutToReuse**, as this may trigger unnecessary component re-renders.

```ts
// Class MyDataSource implements the IDataSource API.
class MyDataSource implements IDataSource {
  private dataArray: number[] = [];

  public pushData(data: number): void {
    this.dataArray.push(data);
  }

  // Total number of items in the data source.
  public totalCount(): number {
    return this.dataArray.length;
  }

  // Return data at the specified index.
  public getData(index: number): number {
    return this.dataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
  }
}

@Entry
@Component
struct MyComponent {
  // Data source.
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 1; i < 1000; i++) {
      this.data.pushData(i);
    }
  }

  build() {
    Column({ space: 5 }) {
      Grid() {
        LazyForEach(this.data, (item: number) => {
          GridItem() {
            // Use the reusable custom component.
            ReusableChildComponent({ item: item })
          }
        }, (item: string) => item)
      }
      .cachedCount(2) // Set the number of cached GridItem components.
      .columnsTemplate('1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .margin(10)
      .height(500)
      .backgroundColor(0xFAEEE0)
    }
  }
}

@Reusable
@Component
struct ReusableChildComponent {
  @State item: number = 0;

  // Called before the component is added to the component tree from the reuse cache. The component's state variable can be updated here to display the correct content.
  // Parameter type: Record<string, number> (explicit type instead of any).
  aboutToReuse(params: Record<string, number>) {
    this.item = params.item;
  }

  build() {
    Column() {
      // Ensure that the app.media.app_icon file is added to src/main/resources/base/media. Missing this file will trigger a runtime error.
      Image($r('app.media.app_icon'))
        .objectFit(ImageFit.Fill)
        .layoutWeight(1)
      Text(`Image${this.item}`)
        .fontSize(16)
        .textAlign(TextAlign.Center)
    }
    .width('100%')
    .height(120)
    .backgroundColor(0xF9CF93)
  }
}
```

### WaterFlow

- For **WaterFlow** scrolling scenarios where **FlowItem** and its child components are frequently created and destroyed, you can encapsulate components in **FlowItem** into a custom component and decorate it with \@Reusable to implement component reuse.

```ts
class WaterFlowDataSource implements IDataSource {
  private dataArray: number[] = [];
  private listeners: DataChangeListener[] = [];

  constructor() {
    for (let i = 0; i <= 60; i++) {
      this.dataArray.push(i);
    }
  }

  // Obtain data at the specified index.
  public getData(index: number): number {
    return this.dataArray[index];
  }

  // Notify listeners of new data addition.
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  // Obtain the total number of data items.
  public totalCount(): number {
    return this.dataArray.length;
  }

  // Register a data change listener.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  // Unregister the data change listener.
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  // Add an item to the end of the data array.
  public addLastItem(): void {
    this.dataArray.splice(this.dataArray.length, 0, this.dataArray.length);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Reusable
@Component
struct ReusableFlowItem {
  @State item: number = 0;

  // Called before the component is added to the component tree from the reuse cache. The component's state variable can be updated here to display the correct content.
  aboutToReuse(params: ESObject) {
    this.item = params.item;
    console.log("=====aboutToReuse====FlowItem==reused==" + this.item);
  }

  aboutToRecycle(): void {
    console.log("=====aboutToRecycle====FlowItem==recycled==" + this.item);
  }

  build() {
    // Ensure that the app.media.app_icon file is added to src/main/resources/base/media. Missing this file will trigger a runtime error.
    Column() {
      Text("N" + this.item).fontSize(24).height('26').margin(10)
      Image($r('app.media.app_icon'))
        .objectFit(ImageFit.Cover)
        .width(50)
        .height(50)
    }
  }
}

@Entry
@Component
struct Index {
  @State minSize: number = 50;
  @State maxSize: number = 80;
  @State fontSize: number = 24;
  @State colors: number[] = [0xFFC0CB, 0xDA70D6, 0x6B8E23, 0x6A5ACD, 0x00FFFF, 0x00FF7F];
  scroller: Scroller = new Scroller();
  dataSource: WaterFlowDataSource = new WaterFlowDataSource();
  private itemWidthArray: number[] = [];
  private itemHeightArray: number[] = [];

  // Calculate random size for flow items.
  getSize() {
    let ret = Math.floor(Math.random() * this.maxSize);
    return (ret > this.minSize ? ret : this.minSize);
  }

  // Generate size arrays for flow items.
  getItemSizeArray() {
    for (let i = 0; i < 100; i++) {
      this.itemWidthArray.push(this.getSize());
      this.itemHeightArray.push(this.getSize());
    }
  }

  aboutToAppear() {
    this.getItemSizeArray();
  }

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column({ space: 2 }) {
        Button('back top')
          .height('5%')
          .onClick(() => { 
            
            // Scroll to top when the component is clicked.
            this.scroller.scrollEdge(Edge.Top);
          })
        WaterFlow({ scroller: this.scroller }) {
          LazyForEach(this.dataSource, (item: number) => {
            FlowItem() {
              ReusableFlowItem({ item: item })
            }.onAppear(() => {
              if (item + 20 == this.dataSource.totalCount()) {
                for (let i = 0; i < 50; i++) {
                  this.dataSource.addLastItem();
                }
              }
            })

          })
        }
      }
    }
  }
}
```

### Swiper

- For **Swiper** scrolling scenarios where child components are frequently created and destroyed, you can encapsulate the child components into a custom component and decorate it with \@Reusable to implement component reuse.

```ts
@Entry
@Component
struct Index {
  private dataSource = new MyDataSource<Question>();

  aboutToAppear(): void {
    for (let i = 0; i < 1000; i++) {
      let title = i + 1 + "test_swiper";
      let answers = ["test1", "test2", "test3",
        "test4"];
      // Ensure that the app.media.app_icon file is added to src/main/resources/base/media. Missing this file will trigger a runtime error.
      this.dataSource.pushData(new Question(i.toString(), title, $r('app.media.app_icon'), answers));
    }
  }

  build() {
    Column({ space: 5 }) {
      Swiper() {
        LazyForEach(this.dataSource, (item: Question) => {
          QuestionSwiperItem({ itemData: item })
        }, (item: Question) => item.id)
      }
    }
    .width('100%')
    .margin({ top: 5 })
  }
}

class Question {
  id: string = '';
  title: ResourceStr = '';
  image: ResourceStr = '';
  answers: Array<ResourceStr> = [];

  constructor(id: string, title: ResourceStr, image: ResourceStr, answers: Array<ResourceStr>) {
    this.id = id;
    this.title = title;
    this.image = image;
    this.answers = answers;
  }
}

@Reusable
@Component
struct QuestionSwiperItem {
  @State itemData: Question | null = null;

  aboutToReuse(params: Record<string, Object>): void {
    this.itemData = params.itemData as Question;
    console.info("===aboutToReuse====QuestionSwiperItem==");
  }

  build() {
    Column() {
      Text(this.itemData?.title)
        .fontSize(18)
        .fontColor($r('sys.color.ohos_id_color_primary'))
        .alignSelf(ItemAlign.Start)
        .margin({
          top: 10,
          bottom: 16
        })
      Image(this.itemData?.image)
        .width('100%')
        .borderRadius(12)
        .objectFit(ImageFit.Contain)
        .margin({
          bottom: 16
        })
        .height(80)
        .width(80)

      Column({ space: 16 }) {
        ForEach(this.itemData?.answers, (item: Resource) => {
          Text(item)
            .fontSize(16)
            .fontColor($r('sys.color.ohos_id_color_primary'))
        }, (item: ResourceStr) => JSON.stringify(item))
      }
      .width('100%')
      .alignItems(HorizontalAlign.Start)
    }
    .width('100%')
    .padding({
      left: 16,
      right: 16
    })
  }
}

class BasicDataSource<T> implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: T[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): T {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }
}

export class MyDataSource<T> extends BasicDataSource<T> {
  private dataArray: T[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): T {
    return this.dataArray[index];
  }

  public pushData(data: T): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}
```

### List Scrolling with ListItemGroup

- For list scrolling scenarios where the **ListItemGroup** component is used, you can encapsulate child components in **ListItem** that need to be destroyed and re-created into a custom component and decorate it with \@Reusable to implement component reuse.

```ts
@Entry
@Component
struct ListItemGroupAndReusable {
  data: DataSrc2 = new DataSrc2();

  @Builder
  itemHead(text: string) {
    Text(text)
      .fontSize(20)
      .backgroundColor(0xAABBCC)
      .width('100%')
      .padding(10)
  }

  aboutToAppear() {
    for (let i = 0; i < 10000; i++) {
      let data_1 = new DataSrc1();
      for (let j = 0; j < 12; j++) {
        data_1.Data.push(`Test item data: ${i} - ${j}`);
      }
      this.data.Data.push(data_1);
    }
  }

  build() {
    Stack() {
      List() {
        LazyForEach(this.data, (item: DataSrc1, index: number) => {
          ListItemGroup({ header: this.itemHead(index.toString()) }) {
            LazyForEach(item, (ii: string, index: number) => {
              ListItem() {
                Inner({ str: ii })
              }
            })
          }
          .width('100%')
          .height('60vp')
        })
      }
    }
    .width('100%')
    .height('100%')
  }
}

@Reusable
@Component
struct Inner {
  @State str: string = '';

  aboutToReuse(param: ESObject) {
    this.str = param.str;
  }

  build() {
    Text(this.str)
  }
}

class DataSrc1 implements IDataSource {
  listeners: DataChangeListener[] = [];
  Data: string[] = [];

  public totalCount(): number {
    return this.Data.length;
  }

  public getData(index: number): string {
    return this.Data[index];
  }

  // Called by the framework to add a listener to the data source for LazyForEach.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  // Called by the framework to remove the listener from the data source for the corresponding LazyForEach component.
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  // Notify LazyForEach that all child components need to be reloaded.
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    });
  }

  // Notify LazyForEach that a child component needs to be added at the specified index.
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  // Notify LazyForEach that the data item at the specified index has changed and the child component needs to be rebuilt.
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    });
  }

  // Notify LazyForEach that the child component at the specified index needs to be deleted.
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    });
  }

  // Notify LazyForEach that data needs to be swapped between the from and to positions.
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    });
  }
}

class DataSrc2 implements IDataSource {
  listeners: DataChangeListener[] = [];
  Data: DataSrc1[] = [];

  public totalCount(): number {
    return this.Data.length;
  }

  public getData(index: number): DataSrc1 {
    return this.Data[index];
  }

  // Called by the framework to add a listener to the data source for LazyForEach.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  // Called by the framework to remove the listener from the data source for the corresponding LazyForEach component.
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  // Notify LazyForEach that all child components need to be reloaded.
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    });
  }

  // Notify LazyForEach that a child component needs to be added at the specified index.
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  // Notify LazyForEach that the data item at the specified index has changed and the child component needs to be rebuilt.
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    });
  }

  // Notify LazyForEach that the child component at the specified index needs to be deleted.
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    });
  }

  // Notify LazyForEach that data needs to be swapped between the from and to positions.
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    });
  }
}
```


### Scenarios Involving Multiple Item Types

**Standard**

Reusable components have the same layout. For implementation examples, see the description in the list scrolling sections.

**Limited Variation**

There are differences between reusable components, but the number of types is limited. For example, reuse can be achieved by explicitly setting two **reuseId** values or using two custom components.

```ts
class MyDataSource implements IDataSource {
  private dataArray: string[] = [];
  private listener: DataChangeListener | undefined;

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
  }

  public reloadListener(): void {
    this.listener?.onDataReloaded();
  }

  public registerDataChangeListener(listener: DataChangeListener): void {
    this.listener = listener;
  }

  public unregisterDataChangeListener(listener: DataChangeListener): void {
    this.listener = undefined;
  }
}

@Entry
@Component
struct Index {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i < 1000; i++) {
      this.data.pushData(i + "");
    }
  }

  build() {
    Column() {
      List({ space: 10 }) {
        LazyForEach(this.data, (item: number) => {
          ListItem() {
            ReusableComponent({ item: item })
              // Set two reuseId values with limited variations.
              .reuseId(item % 2 === 0 ? 'ReusableComponentOne' : 'ReusableComponentTwo')
          }
          .backgroundColor(Color.Orange)
          .width('100%')
        }, (item: number) => item.toString())
      }
      .cachedCount(2)
    }
  }
}

@Reusable
@Component
struct ReusableComponent {
  @State item: number = 0;

  aboutToReuse(params: ESObject) {
    this.item = params.item;
  }

  build() {
    Column() {
      // Render according to type differences inside the component.
      if (this.item % 2 === 0) {
        Text(`Item ${this.item} ReusableComponentOne`)
          .fontSize(20)
          .margin({ left: 10 })
      } else {
        Text(`Item ${this.item} ReusableComponentTwo`)
          .fontSize(20)
          .margin({ left: 10 })
      }
    }.margin({ left: 10, right: 10 })
  }
}
```

**Composite**

There are multiple differences between reusable components, but they usually share common child components. In the example, after three reusable components are converted into **Builder** functions in a combined manner, the internal shared child components will be uniformly placed under the parent component **MyComponent**. The reuse cache is shared at the parent component level for child component reuse, reducing resource consumption during component creation.

```ts
class MyDataSource implements IDataSource {
  private dataArray: string[] = [];
  private listener: DataChangeListener | undefined;

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
  }

  public reloadListener(): void {
    this.listener?.onDataReloaded();
  }

  public registerDataChangeListener(listener: DataChangeListener): void {
    this.listener = listener;
  }

  public unregisterDataChangeListener(listener: DataChangeListener): void {
    this.listener = undefined;
  }
}

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i < 1000; i++) {
      this.data.pushData(i.toString());
    }
  }

  // The reusable component implementation of itemBuilderOne is not shown. Below is the Builder version after conversion.
  @Builder
  itemBuilderOne(item: string) {
    Column() {
      ChildComponentA({ item: item })
      ChildComponentB({ item: item })
      ChildComponentC({ item: item })
    }
  }

  // Builder version of itemBuilderTwo after conversion.
  @Builder
  itemBuilderTwo(item: string) {
    Column() {
      ChildComponentA({ item: item })
      ChildComponentC({ item: item })
      ChildComponentD({ item: item })
    }
  }

  // Builder version of itemBuilderThree after conversion.
  @Builder
  itemBuilderThree(item: string) {
    Column() {
      ChildComponentA({ item: item })
      ChildComponentB({ item: item })
      ChildComponentD({ item: item })
    }
  }

  build() {
    List({ space: 40 }) {
      LazyForEach(this.data, (item: string, index: number) => {
        ListItem() {
          if (index % 3 === 0) {
            this.itemBuilderOne(item)
          } else if (index % 5 === 0) {
            this.itemBuilderTwo(item)
          } else {
            this.itemBuilderThree(item)
          }
        }
        .backgroundColor('#cccccc')
        .width('100%')
        .onAppear(() => {
          console.log(`ListItem ${index} onAppear`);
        })
      }, (item: number) => item.toString())
    }
    .width('100%')
    .height('100%')
    .cachedCount(0)
  }
}

@Reusable
@Component
struct ChildComponentA {
  @State item: string = '';

  aboutToReuse(params: ESObject) {
    console.log(`ChildComponentA ${params.item} Reuse ${this.item}`);
    this.item = params.item;
  }

  aboutToRecycle(): void {
    console.log(`ChildComponentA ${this.item} Recycle`);
  }

  build() {
    Column() {
      Text(`Item ${this.item} Child Component A`)
        .fontSize(20)
        .margin({ left: 10 })
        .fontColor(Color.Blue)
      Grid() {
        ForEach((new Array(20)).fill(''), (item: string, index: number) => {
          GridItem() {
            // Ensure that the app.media.startIcon file is added to src/main/resources/base/media. Missing this file will trigger a runtime error.
            Image($r('app.media.startIcon'))
              .height(20)
          }
        })
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .width('90%')
      .height(160)
    }
    .margin({ left: 10, right: 10 })
    .backgroundColor(0xFAEEE0)
  }
}

@Reusable
@Component
struct ChildComponentB {
  @State item: string = '';

  aboutToReuse(params: ESObject) {
    this.item = params.item;
  }

  build() {
    Row() {
      Text(`Item ${this.item} Child Component B`)
        .fontSize(20)
        .margin({ left: 10 })
        .fontColor(Color.Red)
    }.margin({ left: 10, right: 10 })
  }
}

@Reusable
@Component
struct ChildComponentC {
  @State item: string = '';

  aboutToReuse(params: ESObject) {
    this.item = params.item;
  }

  build() {
    Row() {
      Text(`Item ${this.item} Child Component C`)
        .fontSize(20)
        .margin({ left: 10 })
        .fontColor(Color.Green)
    }.margin({ left: 10, right: 10 })
  }
}

@Reusable
@Component
struct ChildComponentD {
  @State item: string = '';

  aboutToReuse(params: ESObject) {
    this.item = params.item;
  }

  build() {
    Row() {
      Text(`Item ${this.item} Child Component D`)
        .fontSize(20)
        .margin({ left: 10 })
        .fontColor(Color.Orange)
    }.margin({ left: 10, right: 10 })
  }
}
```
