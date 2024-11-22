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
// 编译报错，仅用于自定义组件
 @Reusable
 @Builder
 function buildCreativeLoadingDialog(closedClick: () => void) {
   Crash()
 }

```

- ComponentContent不支持传入\@Reusable装饰器装饰的自定义组件。

```ts
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
          // ComponentContent 底层时buildNode,buildNode不支持传入@Reusable注解的自定义组件
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

- \@Reusable装饰器不支持嵌套使用。

```ts
// Parent 被标记@Reusable
@Reusable
@Component
export struct Parent{
  build() {
    Column() {
      //  问题用法，编译不报错，有时显示正常，可能导致未定义的结果，不建议使用此用法
      //  可复用的组件的子树中存在可复用的组件，可能导致未定义的结果
      HasReusableChild()
      Text("Parent")
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

//  子自定义组件被也被标记@Reusable
@Reusable
@Component
export struct HasReusableChild {
  build() {
    Column() {
      Text("hasReusableChild")
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
```

## 使用场景

- 列表滚动：当应用需要展示大量数据的列表，并且用户进行滚动操作时，频繁创建和销毁列表项的视图可能导致卡顿和性能问题。在这种情况下，使用列表组件的组件复用机制可以重用已经创建的列表项视图，提高滚动的流畅度。

- 动态布局更新：如果应用中的界面需要频繁地进行布局更新，例如根据用户的操作或数据变化动态改变视图结构和样式，重复创建和销毁视图可能导致频繁的布局计算，影响帧率。在这种情况下，使用组件复用可以避免不必要的视图创建和布局计算，提高性能。

- 频繁创建和销毁数据项的视图场景下。使用组件复用可以重用已创建的视图，只更新数据的内容，减少视图的创建和销毁，能有效提高性能。


## 使用场景举例

### 动态布局更新

- 示例代码将Child自定义组件标记为复用组件，通过Button点击更新Child,触发Child复用;
- \@Reusable：自定义组件被\@Reusable装饰器修饰，即表示其具备组件复用的能力;
- aboutToReuse：当一个可复用的自定义组件从复用缓存中重新加入到节点树时，触发aboutToReuse生命周期回调，并将组件的构造参数传递给aboutToReuse;

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
- 变量item的被\@State修饰，才能更新，非\@State修饰变量存在无法更新问题;

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
- 可以使用reuseId为复用组件分配复用组，相同reuseId的组件会在同一个复用组中复用,如果只有一个复用的组件，可以不用设置reuseId;
- 通过reuseId来标识需要复用的组件，省去重复执行if的删除重创逻辑，提高组件复用的效率和性能;

```ts
@Entry
@Component
struct withoutReuseId {
  aboutToAppear(): void {
    getFriendMomentFromRawfile();
  }
 
  build() {
    Column() {
      TopBar()
      List({ space: ListConstants.LIST_SPACE }) {
        LazyForEach(momentData, (moment: FriendMoment) => {
          ListItem() {
            OneMoment({moment: moment})
              // 使用reuseId进行组件复用的控制
              .reuseId((moment.image !== '') ? 'withImage' : 'noImage')
          }
        }, (moment: FriendMoment) => moment.id)
      }
      .cachedCount(Constants.CACHED_COUNT)
    }
  }
}
 
@Reusable
@Component
export struct OneMoment {
  @Prop moment: FriendMoment;
 
  build() {
    Column() {
      ...
      Text(this.moment.text)
 
      if (this.moment.image !== '') {
        Flex({ wrap: FlexWrap.Wrap }) {
          Image($r(this.moment.image))
          Image($r(this.moment.image))
          Image($r(this.moment.image))
          Image($r(this.moment.image))
        }
      }
      ...
    }
  }
}
```

### foreach使用场景

- 示例点击update，数据刷新成功，但是滑动列表，组件复用无法使用，foreach的折叠展开属性的原因;
- 点击clear，再次update，复用成功；符合一帧内重复创建多个已被销毁的自定义组件;

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
  @State isShow: boolean = true
  @State dataSource: ListItemObject[] = [];

  aboutToAppear() {
    for (let i = 0; i < 100; i++) {
      this.data.pushData(i.toString())
    }

    for (let i = 30; i < 80; i++) {
      this.data02.pushData(i.toString())
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
            obj.isExpand = false
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
  @State item: string = ''

  aboutToAppear(): void {
    // 点击 update，首次进入，上下滑动,由于foreach折叠展开属性，无法复用
    console.log("=====abouTo===Appear=====ListItemView==创建了==" + this.item)
  }

  aboutToReuse(params: ESObject) {
    this.item = params.item;
    // 点击 clear，再次update ,复用成功
    //符合一帧内重复创建多个已被销毁的自定义组件
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
  uuid: string = ""
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
      Image($r('app.media.icon'))
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

- WaterFlow滑动场景存在FlowItem及其子组件的频繁创建和销毁，可以将FlowItem中的组件封装成自定义组件，并使用\@Reusable装饰器修饰，使其具备组件复用能力；

```ts
  build() {
    Column({ space: 2 }) {
      WaterFlow() {
        LazyForEach(this.datasource, (item: number) => {
          FlowItem() {
            // 使用可复用自定义组件  
            ReusableFlowItem({ item: item })
          }
          .onAppear(() => {
            // 即将触底时提前增加数据  
            if (item + 20 == this.datasource.totalCount()) {
              for (let i = 0; i < 100; i++) {
                this.datasource.AddLastItem()
              }
            }
          })
          .width('100%')
          .height(this.itemHeightArray[item % 100])
          .backgroundColor(this.colors[item % 5])
        }, (item: string) => item)
      }
      .columnsTemplate("1fr 1fr")
      .columnsGap(10)
      .rowsGap(5)
      .backgroundColor(0xFAEEE0)
      .width('100%')
      .height('80%')
    }
  }
@Reusable
@Component
struct ReusableFlowItem {
  @State item: number = 0
 
  // 从复用缓存中加入到组件树之前调用，可在此处更新组件的状态变量以展示正确的内容
  aboutToReuse(params) {
    this.item = params.item;
  }
 
  build() {
    Column() {
      Text("N" + this.item).fontSize(12).height('16')
      Image('res/waterFlowTest (' + this.item % 5 + ').jpg')
        .objectFit(ImageFit.Fill)
        .width('100%')
        .layoutWeight(1)
    }
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
  ...
}

@Entry
@Component
struct Index {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i < 1000; i++) {
      this.data.pushData(i);
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
  ...
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
