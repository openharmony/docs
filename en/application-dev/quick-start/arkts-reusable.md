# \@Reusable Decorator: Reusing Components


When the \@Reusable decorator decorates any custom component, the custom component is reusable.

> **NOTE**
>
> The \@Reusable decorator is supported since API version 10.

## Overview

- \@Reusable applies to custom components and is used together with \@Component. When a custom component marked with \@Reusable is detached from the component tree, the component and its corresponding **JSView** object are stored in the cache pool. When a custom component node is created later, nodes in the cache pool are reused, saving the time for re-creating components.

## Constraints

- The \@Reusable decorator is used only for custom components.

```ts
import { ComponentContent } from "@kit.ArkUI";

// An error is reported when @Builder is used together with @Reusable.
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
  private uicontext = this.getUIContext();

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
          let contentNode = new ComponentContent(this.uicontext, wrapBuilder(buildCreativeLoadingDialog), () => {
          });
          this.uicontext.getPromptAction().openCustomDialog(contentNode);
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

- **ComponentContent** does not support @Reusable decorated custom components.

```ts
import { ComponentContent } from "@kit.ArkUI";

@Builder
function buildCreativeLoadingDialog(closedClick: () => void) {
  Crash()
}

// If @Reusable is commented out, the dialog box displays properly; if @Reusable is added, the project crashes.
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
  private uicontext = this.getUIContext();

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
          // buildNode, the bottom layer of ComponentContent, does not support the @Reusable decorated custom component.
          let contentNode = new ComponentContent(this.uicontext, wrapBuilder(buildCreativeLoadingDialog), () => {
          });
          this.uicontext.getPromptAction().openCustomDialog(contentNode);
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

- \@Reusable decorators do not support nested use, which increases the memory and is inconvenient for maintenance.


> **NOTE**
>
> Nested use is not supported. One mark will add a cache pool and each of the cache pool has the same tree structure, leading to low reuse efficiency and increased reused memory.
> 
> After the nested use forms independent reuse cache pools, the lifecycle transfer is abnormal. Resources and variables cannot be shared, which is inconvenient for maintenance and may cause problems.
>
> In the following example, the reuse cache pool formed by **PlayButton** cannot be used in the reuse cache pool of **PlayButton02**, but the reuse cache pools formed by **PlayButton02** can be used by each other.
> The lifecycle method reused by the component cannot be called in pairs. When **PlayButton** is hidden, **aboutToRecycle** of **PlayButton02** is triggered. However, when **PlayButton02** is displayed independently, **aboutToReuse** cannot be executed.
> 
> In conclusion, nested use is not recommended.


```ts
@Entry
@Component
struct Index {
  @State isPlaying: boolean = false;
  @State isPlaying02: boolean = true;
  @State isPlaying01: boolean = false;

  build() {
    Column() {
      if (this.isPlaying02) {

        // Initial state of the button: shown
        Text("Default shown childbutton")
          .fontSize(14)
        PlayButton02({ isPlaying02: $isPlaying02 })
      }
      Text(`------------------------`)

      // Initial state of the button: hidden
      if (this.isPlaying01) {
        Text("Default hidden childbutton")
          .fontSize(14)
        PlayButton02({ isPlaying02: $isPlaying01 })
      }
      Text(`------------------------`)

      // Parent-child nesting
      if (this.isPlaying) {
        Text("Parent-child nesting")
          .fontSize(14)
        PlayButton({ buttonPlaying: $isPlaying })
      }
      Text(`------------------------`)

      // Parent-child nesting control
      Text(`Parent=child==is ${this.isPlaying ? '' : 'not'} playing`).fontSize(14)
      Button('Parent=child===controll=' + this.isPlaying)
        .margin(14)
        .onClick(() => {
          this.isPlaying = !this.isPlaying;
        })

      Text(`------------------------`)

      // Hide the button control by default.
      Text(`Hiddenchild==is ${this.isPlaying01 ? '' : 'not'} playing`).fontSize(14)
      Button('Button===hiddenchild==control==' + this.isPlaying01)
        .margin(14)
        .onClick(() => {
          this.isPlaying01 = !this.isPlaying01;
        })
      Text(`------------------------`)

      // Display the button control by default.
      Text(`shownchid==is ${this.isPlaying02 ? '' : 'not'} playing`).fontSize(14)
      Button('Button===shownchid==control==:' + this.isPlaying02)
        .margin(15)
        .onClick(() => {
          this.isPlaying02 = !this.isPlaying02;
        })
    }
  }
}

// Reuse 1
@Reusable
@Component
struct PlayButton {
  @Link buttonPlaying: boolean;

  build() {
    Column() {

      // Reuse
      PlayButton02({ isPlaying02: $buttonPlaying })
      Button(this.buttonPlaying ? 'parent_pause' : 'parent_play')
        .margin(12)
        .onClick(() => {
          this.buttonPlaying = !this.buttonPlaying;
        })
    }
  }
}

// Reuse 2: Nested use is not recommended.
@Reusable
@Component
struct PlayButton02 {
  @Link isPlaying02: boolean;

  aboutToRecycle(): void {
    console.log("=====aboutToRecycle====PlayButton02====");
  }

  aboutToReuse(params: ESObject): void {
    console.log("=====aboutToReuse====PlayButton02====");
  }

  build() {
    Column() {
      Button('===commonbutton=====')
        .margin(12)
    }
  }
}
```

## Use Scenario

- List scrolling: When a user scrolls a list containing a large amount of data, frequently creating and destroying list item views may cause stuttering and performance problems. In this case, the reuse mechanism of the **List** component can reuse the created list view to improve the scrolling smoothness.

- Dynamic layout update: If the application UI requires frequent layout updates, for example, the view structure and style are dynamically changed based on user operations or data changes, frequent creation and destruction of views may cause frequent layout calculation, affecting the frame rate. In this case, component reuse can avoid unnecessary view creation and layout calculation, improving performance.

- In the scenario where data items are frequently created and destroyed, the component reuse mechanism can be applied to reuse created views and update only their data content, reducing view creation and destruction.


## Usage Case

### Dynamic Layout Update

- In the sample code, the child custom component is marked as a reusable component. You can update **Child** by clicking the button to trigger **Child** reuse.
- \@Reusable: The custom component to reuse is decorated by @Reusable.
- **aboutToReuse**: Invoked when a reusable custom component is re-added to the node tree from the reuse cache to receive construction parameters of the component.

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
        // If only one component to be reused, you do not need to set reuseId.
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
    console.info("Recycle ====Child==");
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

### Using List Scrolling with LazyForEach

- In the sample code, the **CardView** custom component is marked as a reusable component, and the list is scrolled up and down to trigger **CardView** reuse.
- \@State: The variable **item** can be updated only when it is decorated by \@State.

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

### if Statement

- In the sample code, the **OneMoment** custom component is marked as a reusable component, and the list is scrolled up and down to trigger **OneMoment** reuse.
- You can use **reuseId** to assign reuse groups to reusable components. Components with the same **reuseId** will be reused in the same reuse group. If there is only one reusable component, you do not need to set **reuseId**.
- The **reuseId** is used to identify the component to be reused and omit the deletion and re-creation logic executed by **if**, improving the efficiency and performance of component reuse.

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

  // The reuse can be triggered only when the reuse ID is the same.
  aboutToReuse(params: ESObject): void {
    console.log("=====aboutToReuse====OneMoment==reused==" + this.moment.text);
  }

  build() {
    Column() {
      Text(this.moment.text)
      // if branch judgment
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

### Foreach

- When **Foreach** is used to create a reusable custom component, component reuse cannot be triggered due to the full expansion attribute of **Foreach**. In the following example, after **update** is clicked, the data is refreshed successfully, but **ListItemView** cannot be reused.
- Click **clear** and then click **update** again. **ListItemView** is successfully reused because multiple destroyed custom components are repeatedly created in a frame.

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
            let obj = new ListItemObject();
            obj.id = i;
            obj.uuid = Math.random().toString();
            obj.isExpand = false;
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
    // Click update and scroll the list. The components cannot be reused because of the full expansion attribute of Foreach.
    console.log("=====aboutToAppear=====ListItemView==created==" + this.item);
  }

  aboutToReuse(params: ESObject) {
    this.item = params.item;
    // Click clear and update and the reuse is successful,
    // because multiple destroyed custom components are repeatedly created in a frame.
    console.log("=====aboutToReuse====ListItemView==reused==" + this.item);
  }

  build() {
    Column({ space: 10 }) {
      Text('${this.obj.id}.Title')
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

- In the following example, the @Reusable decorator is used to decorate the custom component **ReusableChildComponent** in **GridItem**, indicating that the component can be reused.
- **aboutToReuse** is used to trigger **Grid** before it is added from the reuse cache to the component tree during scrolling and update the component state variable to display the correct content.
- Note that you do not need to update the state variables decorated by \@Link, \@StorageLink, \@ObjectLink, and \@Consume in **aboutToReuse**. These state variables are automatically updated, and manual update may trigger unnecessary component re-renders.

```ts
// Class MyDataSource implements the IDataSource API.
class MyDataSource implements IDataSource {
  private dataArray: number[] = [];

  public pushData(data: number): void {
    this.dataArray.push(data);
  }

  // Total data amount of the data source
  public totalCount(): number {
    return this.dataArray.length;
  }

  // Return the data with the specified index.
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
  // Data source
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
            // Use reusable custom components.
            ReusableChildComponent({ item: item })
          }
        }, (item: string) => item)
      }
      .cachedCount(2) // Set the number of cached GridItems.
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

  // aboutToReuse is called when a reusable custom component is added to the component tree from the reuse cache. The component's state variables can be updated here to display the correct content.
  // The aboutToReuse parameter does not support any and Record is used to specify a data type. Record is used to create an object type, of which the attribute key is Keys and the attribute value is Type.
  aboutToReuse(params: Record<string, number>) {
    this.item = params.item;
  }

  build() {
    Column() {
      // Add the app.media.app_icon image to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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

- In the **WaterFlow** scrolling scenario, **FlowItem** and its child components are frequently created and destroyed. You can encapsulate the components in **FlowItem** into custom components and decorate them using \@Reusable so that these components can be reused.

```ts
class WaterFlowDataSource implements IDataSource {
  private dataArray: number[] = [];
  private listeners: DataChangeListener[] = [];

  constructor() {
    for (let i = 0; i <= 60; i++) {
      this.dataArray.push(i);
    }
  }

  // Obtain the data corresponding to the specified index.
  public getData(index: number): number {
    return this.dataArray[index];
  }

  // Notify the controller to add data.
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  // Obtain the total number of data records.
  public totalCount(): number {
    return this.dataArray.length;
  }

  // Register the data change listener.
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

  // Add an item to the end of the data.
  public addLastItem(): void {
    this.dataArray.splice(this.dataArray.length, 0, this.dataArray.length);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Reusable
@Component
struct ReusableFlowItem {
  @State item: number = 0;

  // Invoked when a reusable custom component is added to the component tree from the reuse cache. The component's state variable can be updated here to display the correct content.
  aboutToReuse(params: ESObject) {
    this.item = params.item;
    console.log("=====aboutToReuse====FlowItem==reused==" + this.item);
  }

  aboutToRecycle(): void {
    console.log("=====aboutToRecycle====FlowItem==recycled==" + this.item);
  }

  build() {
    // Add the app.media.app_icon image to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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

  // Calculate the width and height of the flow item.
  getSize() {
    let ret = Math.floor(Math.random() * this.maxSize);
    return (ret > this.minSize ? ret : this.minSize);
  }

  // Save the width and height of the flow item.
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
          .onClick(() => { // Back to the top once clicked.
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

  @Builder
  itemFoot() {
    Column() {
      Text(`Footer`)
        .fontSize(10)
        .backgroundColor(Color.Red)
        .width(50)
        .height(50)
        .align(Alignment.Center)
        .margin({ top: 2 })
    }
  }
}
```

### Swiper

- In the **Swiper** scrolling scenario, child components are frequently created and destroyed in an item. You can encapsulate the child components in the item into custom components and use \@Reusable to decorate the custom components so that they can be reused.

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
      // Add the app.media.app_icon image to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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
    console.info("===test===aboutToReuse====QuestionSwiperItem==");
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

### ListItemGroup

- This case can be regarded as a special **List** scrolling scenario. Encapsulate the child component of **ListItem** that needs to be destroyed and re-created into a custom component and use \@Reusable to decorate the custom component so that the custom component can be reused.

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
        data_1.Data.push('Test item data: ${i} - ${j}');
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

  // This method is called by the framework to register a listener to the LazyForEach data source.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  // This method is called by the framework to unregister the listener from the LazyForEach data source.
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

  // Notify LazyForEach that a child component needs to be added for the data item with the specified index.
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  // Notify LazyForEach that the data item with the specified index has changed and the child component needs to be rebuilt.
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    });
  }

  // Notify LazyForEach that the child component needs to be deleted from the data item with the specified index.
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

  // This method is called by the framework to register a listener to the LazyForEach data source.
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  // This method is called by the framework to unregister the listener from the LazyForEach data source.
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

  // Notify LazyForEach that a child component needs to be added for the data item with the specified index.
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  // Notify LazyForEach that the data item with the specified index has changed and the child component needs to be rebuilt.
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    });
  }

  // Notify LazyForEach that the child component needs to be deleted from the data item with the specified index.
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


### Multiple Item Types

#### Standard

- Reusable components have the same layouts.
- For the sample code of this type, see section "List Scrolling Used with LazyForEach".

#### Limited

- Types of different reusable components are limited.
- In the following example, two reuse IDs are explicitly set for reusing two custom components.

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

#### Composite

- Different reusable components have common child components.
- Based on the composite component reuse, after the three reusable components are converted into the **Builder** function, the common child components are under the same parent component **MyComponent**.
- When you reuse these child components, their cache pools are also shared in the parent component, reducing the consumption during component creation.

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

  // Convert itemBuilderOne to Builder.
  @Builder
  itemBuilderOne(item: string) {
    Column() {
      ChildComponentA({ item: item })
      ChildComponentB({ item: item })
      ChildComponentC({ item: item })
    }
  }

  // Convert itemBuilderTwo to Builder.
  @Builder
  itemBuilderTwo(item: string) {
    Column() {
      ChildComponentA({ item: item })
      ChildComponentC({ item: item })
      ChildComponentD({ item: item })
    }
  }

  // Convert itemBuilderThree to Builder.
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
            // Add the app.media.startIcon image to the src/main/resources/base/media directory. Otherwise, an error will be reported due to missing resources.
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
