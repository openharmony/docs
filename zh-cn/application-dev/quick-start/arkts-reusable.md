# \@Reusable装饰器：组件复用


\@Reusable装饰器装饰任意自定义组件时，表示该自定义组件可以复用。

> **说明：**
>
> 从API version 10开始，对\@Reusable进行支持，支持在ArkTS中使用。



## 概述

- \@Reusable适用自定义组件，与\@Component结合使用，标记为\@Reusable的自定义组件从组件树上被移除时，组件和其对应的JSView对象都会被放入复用缓存中，后续创建新自定义组件节点时，会复用缓存区中的节点，节约组件重新创建的时间。

## 限制条件

- \@Reusable装饰器仅用于自定义组件。

```ts
import { ComponentContent } from "@kit.ArkUI";

// @Builder加上@Reusable编译报错,不适用于builder
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
  private uicontext = this.getUIContext()

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

- ComponentContent不支持传入\@Reusable装饰器装饰的自定义组件。

```ts
import { ComponentContent } from "@kit.ArkUI";
@Builder
function buildCreativeLoadingDialog(closedClick: () => void) {
  Crash()
}

// 如果注释掉就可以正常弹出弹窗，如果加上@Reusable就直接crash
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
  private uicontext = this.getUIContext()

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
          // ComponentContent底层是buildNode，buildNode不支持传入@Reusable注解的自定义组件
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

- \@Reusable装饰器不支持嵌套使用，存在增加内存和不方便维护的问题；


> **说明：**
>
> 不支持嵌套使用，只是标记，会多增加一个缓存池，各自的复用缓存池存在相同树状结构，复用效率低，引发复用内存增加;
> 
> 嵌套使用形成各自独立的复用缓存池之后，生命周期的传递存在问题，资源和变量管理无法共享，并不方便维护，容易引发问题;
>
> 示例中PlayButton形成的复用缓存池，并不能在PlayButton02的复用缓存池使用，但PlayButton02自己形成复用缓存相互可以使用；
> 在PlayButton隐藏时已经触发PlayButton02的aboutToRecycle，但是在PlayButton02单独显示时却无法执行aboutToReuse，组件复用的生命周期方法存在无法成对调用问题；
> 
> 综上，不建议嵌套使用。


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

        // 初始态是显示的按钮
        Text("Default shown childbutton")
          .fontSize(14)
        PlayButton02({ isPlaying02: $isPlaying02 })
      }
      Text(`==================`).fontSize(14)

      // 初始态是显示的按钮
      if (this.isPlaying01) {
        Text("Default hiden childbutton")
          .fontSize(14)
        PlayButton02({ isPlaying02: $isPlaying01 })
      }
      Text(`==================`).fontSize(14)

      // 父子嵌套
      if (this.isPlaying) {
        Text("parent child 嵌套")
          .fontSize(14)
        PlayButton({ buttonPlaying: $isPlaying })
      }
      Text(`==================`).fontSize(14);

      // 父子嵌套控制
      Text(`Parent=child==is ${this.isPlaying ? '' : 'not'} playing`).fontSize(14)
      Button('Parent=child===controll=' + this.isPlaying)
        .margin(14)
        .onClick(() => {
          this.isPlaying = !this.isPlaying;
        })

      Text(`==================`).fontSize(14);

      //  默认隐藏按钮控制
      Text(`hidedchild==is ${this.isPlaying01 ? '' : 'not'} playing`).fontSize(14)
      Button('Button===hidedchild==control==' + this.isPlaying01)
        .margin(14)
        .onClick(() => {
          this.isPlaying01 = !this.isPlaying01;
        })
      Text(`==================`).fontSize(14);

      // 默认显示按钮控制
      Text(`shownchid==is ${this.isPlaying02 ? '' : 'not'} playing`).fontSize(14)
      Button('Button===shownchid==control==:' + this.isPlaying02)
        .margin(15)
        .onClick(() => {
          this.isPlaying02 = !this.isPlaying02;
        })
    }
  }
}

// 复用1
@Reusable
@Component
struct PlayButton {
  @Link buttonPlaying: boolean;

  build() {
    Column() {

      // 复用
      PlayButton02({ isPlaying02: $buttonPlaying })
      Button(this.buttonPlaying ? 'parent_pause' : 'parent_play')
        .margin(12)
        .onClick(() => {
          this.buttonPlaying = !this.buttonPlaying;
        })
    }
  }
}

//  复用2 不建议嵌套使用
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

## 使用场景

- 列表滚动：当应用需要展示大量数据的列表，并且用户进行滚动操作时，频繁创建和销毁列表项的视图可能导致卡顿和性能问题。在这种情况下，使用列表组件的组件复用机制可以重用已经创建的列表项视图，提高滚动的流畅度。

- 动态布局更新：如果应用中的界面需要频繁地进行布局更新，例如根据用户的操作或数据变化动态改变视图结构和样式，重复创建和销毁视图可能导致频繁的布局计算，影响帧率。在这种情况下，使用组件复用可以避免不必要的视图创建和布局计算，提高性能。

- 频繁创建和销毁数据项的视图场景下。使用组件复用可以重用已创建的视图，只更新数据的内容，减少视图的创建和销毁，能有效提高性能。


## 使用场景举例

### 动态布局更新

- 示例代码将Child自定义组件标记为复用组件，通过Button点击更新Child，触发Child复用;
- \@Reusable：自定义组件被\@Reusable装饰器修饰，即表示其具备组件复用的能力;
- aboutToReuse：当一个可复用的自定义组件从复用缓存中重新加入到节点树时，触发aboutToReuse生命周期回调，并将组件的构造参数传递给aboutToReuse。

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
        Child({ message: new Message('Child') })
          // 如果只有一个复用的组件，可以不用设置reuseId
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

### 列表滚动配合LazyForEach使用

- 示例代码将CardView自定义组件标记为复用组件，List上下滑动，触发CardView复用;
- \@Reusable：自定义组件被@Reusable装饰器修饰，即表示其具备组件复用的能力;
- 变量item的被\@State修饰，才能更新，非\@State修饰变量存在无法更新问题。

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
      this.data.pushData(i+"");
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

// 复用组件
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

### if使用场景

- 示例代码将OneMoment自定义组件标记为复用组件，List上下滑动，触发OneMoment复用;
- 可以使用reuseId为复用组件分配复用组，相同reuseId的组件会在同一个复用组中复用，如果只有一个复用的组件，可以不用设置reuseId;
- 通过reuseId来标识需要复用的组件，省去重复执行if的删除重创逻辑，提高组件复用的效率和性能。

```ts
@Entry
@Component
struct Index {
  private dataSource = new MyDataSource<FriendMoment>();

  aboutToAppear(): void {
    for (let i = 0; i < 20; i++) {
      let title = i + 1 + "test_if";
      this.dataSource.pushData(new FriendMoment(i.toString(), title, 'app.media.app_icon'))
    }

    for (let i = 0; i < 50; i++) {
      let title = i + 1 + "test_if";
      this.dataSource.pushData(new FriendMoment(i.toString(), title, ''))
    }
  }

  build() {
    Column() {
      // TopBar()
      List({ space: 3 }) {
        LazyForEach(this.dataSource, (moment: FriendMoment) => {
          ListItem() {
            OneMoment({ moment: moment })// 使用reuseId进行组件复用的控制
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

  // 复用id相同的同才能触发复用
  aboutToReuse(params: ESObject): void {
    console.log("=====aboutToReuse====OneMoment==复用了==" + this.moment.text);
  }

  build() {
    Column() {
      Text(this.moment.text)
      // if分支判断
      if (this.moment.image !== '') {
        Flex({ wrap: FlexWrap.Wrap }) {
          Image($r(this.moment.image)).height(50).width(50);
          Image($r(this.moment.image)).height(50).width(50);
          Image($r(this.moment.image)).height(50).width(50);
          Image($r(this.moment.image)).height(50).width(50);
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
    })
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

### Foreach使用场景

- 示例点击update，数据刷新成功，但是滑动列表，组件复用无法使用，Foreach的折叠展开属性的原因;
- 点击clear，再次update，复用成功；符合一帧内重复创建多个已被销毁的自定义组件。

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
            obj.isExpand = false
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
          return item.uuid.toString()
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
    // 点击 update，首次进入，上下滑动，由于Foreach折叠展开属性，无法复用
    console.log("=====abouTo===Appear=====ListItemView==创建了==" + this.item)
  }

  aboutToReuse(params: ESObject) {
    this.item = params.item;
    // 点击 clear，再次update，复用成功
    // 符合一帧内重复创建多个已被销毁的自定义组件
    console.log("=====aboutTo===Reuse====ListItemView==复用了==" + this.item)
  }

  build() {
    Column({ space: 10 }) {
      Text(`${this.obj.id}.标题`)
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

### Grid使用场景

- 示例中使用\@Reusable装饰器修饰GridItem中的自定义组件ReusableChildComponent，即表示其具备组件复用的能力;
- 使用aboutToReuse是为了让Grid在滑动时从复用缓存中加入到组件树之前触发，用于更新组件的状态变量以展示正确的内容;
- 需要注意的是无需在aboutToReuse中对\@Link、\@StorageLink、\@ObjectLink、\@Consume等自动更新值的状态变量进行更新，可能触发不必要的组件刷新。

```ts
// MyDataSource类实现IDataSource接口
class MyDataSource implements IDataSource {
  private dataArray: number[] = [];

  public pushData(data: number): void {
    this.dataArray.push(data);
  }

  // 数据源的数据总量
  public totalCount(): number {
    return this.dataArray.length;
  }

  // 返回指定索引位置的数据
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
  // 数据源
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
            // 使用可复用自定义组件
            ReusableChildComponent({ item: item })
          }
        }, (item: string) => item)
      }
      .cachedCount(2) // 设置GridItem的缓存数量
      .columnsTemplate('1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .margin(10)
      .height(500)
      .backgroundColor(0xFAEEE0)
    }
  }
}

// 自定义组件被@Reusable装饰器修饰，即标志其具备组件复用的能力
@Reusable
@Component
struct ReusableChildComponent {
  @State item: number = 0;

  // aboutToReuse从复用缓存中加入到组件树之前调用，可在此处更新组件的状态变量以展示正确的内容
  // aboutToReuse参数类型已不支持any，这里使用Record指定明确的数据类型。Record用于构造一个对象类型，其属性键为Keys，属性值为Type
  aboutToReuse(params: Record<string, number>) {
    this.item = params.item;
  }

  build() {
    Column() {
      // 请开发者自行在src/main/resources/base/media路径下添加app.media.app_icon图片，否则运行时会因资源缺失而报错
      Image($r('app.media.app_icon'))
        .objectFit(ImageFit.Fill)
        .layoutWeight(1)
      Text(`图片${this.item}`)
        .fontSize(16)
        .textAlign(TextAlign.Center)
    }
    .width('100%')
    .height(120)
    .backgroundColor(0xF9CF93)
  }
}
```

### WaterFlow使用场景

- WaterFlow滑动场景存在FlowItem及其子组件的频繁创建和销毁，可以将FlowItem中的组件封装成自定义组件，并使用\@Reusable装饰器修饰，使其具备组件复用能力。

```ts
class WaterFlowDataSource implements IDataSource {
  private dataArray: number[] = [];
  private listeners: DataChangeListener[] = [];

  constructor() {
    for (let i = 0; i <= 60; i++) {
      this.dataArray.push(i);
    }
  }

  // 获取索引对应的数据
  public getData(index: number): number {
    return this.dataArray[index];
  }

  // 通知控制器增加数据
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  // 获取数据总数
  public totalCount(): number {
    return this.dataArray.length;
  }

  // 注册改变数据的控制器
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  // 注销改变数据的控制器
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  // 在数据尾部增加一个元素
  public addLastItem(): void {
    this.dataArray.splice(this.dataArray.length, 0, this.dataArray.length);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Reusable
@Component
struct ReusableFlowItem {
  @State item: number = 0;

  // 从复用缓存中加入到组件树之前调用，可在此处更新组件的状态变量以展示正确的内容
  aboutToReuse(params: ESObject) {
    this.item = params.item;
    console.log("=====aboutToReuse====FlowItem==复用了==" + this.item);
  }

  aboutToRecycle(): void {
    console.log("=====aboutToRecycle====FlowItem==回收了==" + this.item);
  }

  build() {
    // 请开发者自行在src/main/resources/base/media路径下添加app.media.app_icon图片，否则运行时会因资源缺失而报错
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

  // 计算flow item宽/高
  getSize() {
    let ret = Math.floor(Math.random() * this.maxSize);
    return (ret > this.minSize ? ret : this.minSize);
  }

  // 保存flow item宽/高
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
          .onClick(() => { // 点击后回到顶部
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

### Swiper使用场景

- Swiper滑动场景，条目中存在子组件的频繁创建和销毁，可以将条目中的子组件封装成自定义组件，并使用\@Reusable装饰器修饰，使其具备组件复用能力。

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
      // 请开发者自行在src/main/resources/base/media路径下添加app.media.app_icon图片，否则运行时会因资源缺失而报错
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
    })
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

### ListItemGroup使用场景

- 可以视作特殊List滑动场景，将ListItem需要销毁重建的子组件封装成自定义组件，并使用\@Reusable装饰器修饰，使其具备组件复用能力。

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
        data_1.Data.push(`测试条目数据: ${i} - ${j}`);
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
                Inner({ str: ii });
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
  @State str: string = ''

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

  // 该方法为框架侧调用，为LazyForEach组件向其数据源处添加listener监听
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  // 该方法为框架侧调用，为对应的LazyForEach组件在数据源处去除listener监听
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  // 通知LazyForEach组件需要重载所有子组件
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  // 通知LazyForEach组件需要在index对应索引处添加子组件
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  // 通知LazyForEach组件在index对应索引处数据有变化，需要重建该子组件
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  // 通知LazyForEach组件需要在index对应索引处删除该子组件
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

  // 通知LazyForEach组件将from索引和to索引处的子组件进行交换
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    })
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

  // 该方法为框架侧调用，为LazyForEach组件向其数据源处添加listener监听
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  // 该方法为框架侧调用，为对应的LazyForEach组件在数据源处去除listener监听
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  // 通知LazyForEach组件需要重载所有子组件
  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  // 通知LazyForEach组件需要在index对应索引处添加子组件
  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  // 通知LazyForEach组件在index对应索引处数据有变化，需要重建该子组件
  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  // 通知LazyForEach组件需要在index对应索引处删除该子组件
  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }

  // 通知LazyForEach组件将from索引和to索引处的子组件进行交换
  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to);
    })
  }
}
```


### 多种条目类型使用场景

#### 标准型

- 复用组件之间布局完全相同;
- 示例同列表滚动中描述;

#### 有限变化型

- 复用组件之间有不同，但是类型有限;
- 示例为复用组件显式设置两个reuseId与使用两个自定义组件进行复用;

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
      this.data.pushData(i+"");
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

#### 组合型

- 复用组件之间有不同，情况非常多，但是拥有共同的子组件;
- 示例按照组合型的组件复用方式，将上述示例中的三种复用组件转变为Builder函数后，内部共同的子组件就处于同一个父组件MyComponent下;
- 对这些子组件使用组件复用时，它们的缓存池也会在父组件上共享，节省组件创建时的消耗。

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
      this.data.pushData(i.toString())
    }
  }

  @Builder
  itemBuilderOne(item: string) {
    Column() {
      ChildComponentA({ item: item })
      ChildComponentB({ item: item })
      ChildComponentC({ item: item })
    }
  }

  @Builder
  itemBuilderTwo(item: string) {
    Column() {
      ChildComponentA({ item: item })
      ChildComponentC({ item: item })
      ChildComponentD({ item: item })
    }
  }

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
        ForEach((new Array(20)).fill(''), (item: string,index: number) => {
          GridItem() {
            // 请开发者自行在src/main/resources/base/media路径下添加app.media.startIcon图片，否则运行时会因资源缺失而报错
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
