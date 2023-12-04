# 组件复用实践

若开发者的应用中存在以下场景，并成为UI线程的帧率瓶颈，应该考虑使用组件复用机制提升应用性能：

1. 滑动场景下对同一类自定义组件的实例进行频繁的创建与销毁；
2. 反复切换条件渲染的控制分支，且控制分支中的组件子树结构比较复杂。

组件复用生效的条件是：

1. 自定义组件被@Reusable装饰器修饰，即表示其具备组件复用的能力；
2. 在一个自定义组件（父）下创建出来的具备组件复用能力的自定义组件（子），在可复用自定义组件从组件树上移除之后，会被加入到其父自定义组件的可复用组件缓存中；
3. 在一个自定义组件（父）下创建可复用的子组件时，若可复用子节点缓存中有对应类型的可复用子组件的实例，会通过更新可复用子组件的方式，快速创建可复用子组件。

## 约束限制

1. @Reusable标识自定义组件具备可复用的能力，它可以被添加到任意的自定义组件上，但是开发者需要小心处理自定义组件的**创建流程**和**更新流程**以确保自定义组件在复用之后能展示出正确的行为；
2. 可复用自定义组件的缓存和复用只能发生在同一父组件下，无法在不同的父组件下复用同一自定义组件的实例。例如，A组件是可复用组件，其也是B组件的子组件，并进入了B组件的可复用组件缓存中，但是在C组件中创建A组件时，无法使用B组件缓存的A组件；
3. 自定义组件的复用带来的性能提升主要体现在节省了自定义组件的JS对象的创建时间并复用了自定义组件的组件树结构，若应用开发者在自定义组件复用的前后使用渲染控制语法显著的改变了自定义组件的组件树结构，那么将无法享受到组件复用带来的性能提升；
4. 组件复用仅发生在存在可复用组件从组件树上移除并再次加入到组件树的场景中，若不存在上述场景，将无法触发组件复用。例如，使用ForEach渲染控制语法创建可复用的自定义组件，由于ForEach渲染控制语法的全展开属性，不能触发组件复用。

## 开发建议

1. 建议复用自定义组件时避免一切可能改变自定义组件的组件树结构和可能使可复用组件中产生重新布局的操作以将组件复用的性能提升到最高；
2. 建议列表滑动场景下组件复用能力和LazyForEach渲染控制语法搭配使用以达到性能最优效果；
3. 开发者需要区分好自定义组件的创建和更新过程中的行为，并注意到自定义组件的复用本质上是一种特殊的组件更新行为，组件创建过程中的流程与生命周期将不会在组件复用中发生，自定义组件的构造参数将通过aboutToReuse生命周期回调传递给自定义组件。例如，aboutToAppear生命周期和自定义组件的初始化传参将不会在组件复用中发生；
4. 避免在aboutToReuse生命周期回调中产生耗时操作，最佳实践是仅在aboutToReuse中做自定义组件更新所需的状态变量值的更新；
5. 无需在aboutToReuse中对@Link、@StorageLink、@ObjectLink、@Consume等自动更新值的状态变量进行更新，可能触发不必要的组件刷新。

## 生命周期

可复用组件从C++侧的组件树上移除时，自定义组件在ArkUI框架native侧的CustomNode会被挂载到其对应的JSView上。复用发生之后，CustomNode被JSView引用，并触发ViewPU上的aboutToRecycle方法，ViewPU的实例将会被RecycleManager引用。

可复用组件从RecycleManager中重新加入组件树时，会调用前端ViewPU对象上的aboutToReuse生命周期回调。

## 接口说明

组件的生命周期回调，在可复用组件从复用缓存中加入到组件树之前调用，可在其中更新组件的状态变量以展示正确的内容，入参的类型与自定义组件的构造函数入参相同。

```ts
aboutToReuse?(params: { [key: string]: unknown }): void;
```

组件的生命周期回调，在可复用组件从组件树上被加入到复用缓存之前调用。

```ts
aboutToRecycle?(): void;
```

开发者可以使用reuseId为复用组件分配复用组，相同reuseId的组件会在同一个复用组中复用。

```ts
reuseId(id: string);
```

Reusable装饰器，用于声明组件具备可复用的能力。

```ts
declare const Reusable: ClassDecorator;
```

**示例：**

```ts
private dataArray: string[] = [];
  private listener: DataChangeListener;

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): any {
    return this.dataArray[index];
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
  }

  public reloadListener(): void {
    this.listener.onDataReloaded();
  }

  public registerDataChangeListener(listener: DataChangeListener): void {
    this.listener = listener;
  }

  public unregisterDataChangeListener(listener: DataChangeListener): void {
    this.listener = null;
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

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          ReusableChildComponent({ item: item })
        }
      }, item => item)
    }
    .width('100%')
    .height('100%')
  }
}

@Reusable
@Component
struct ReusableChildComponent {
  @State item: string = ''

  aboutToReuse(params) {
    this.item = params.item;
  }

  build() {
    Row() {
      Text(this.item)
        .fontSize(20)
        .margin({ left: 10 })
    }.margin({ left: 10, right: 10 })
  }
}
```

## 相关实例

以下为购物示例，对比使用组件复用前后，应用侧创建自定义组件的收益以及前后的代码写法对比。

### 复用前后代码对比

**复用前：**

```ts
LazyForEach(this.GoodDataOne, (item, index) => {
  GridItem() {
    Column() {
      Image(item.img)
        .height(item.hei)
        .width('100%')
        .objectFit(ImageFit.Fill)

      Text(item.introduce)
        .fontSize(14)
        .padding({ left: 5, right: 5 })
        .margin({ top: 5 })
      Row() {
        Row() {
          Text('￥')
            .fontSize(10)
            .fontColor(Color.Red)
            .baselineOffset(-4)
          Text(item.price)
            .fontSize(16)
            .fontColor(Color.Red)
          Text(item.numb)
            .fontSize(10)
            .fontColor(Color.Gray)
            .baselineOffset(-4)
            .margin({ left: 5 })
        }

        Image($r('app.media.photo63'))
          .width(20)
          .height(10)
          .margin({ bottom: -8 })
      }
      .width('100%')
      .justifyContent(FlexAlign.SpaceBetween)
      .padding({ left: 5, right: 5 })
      .margin({ top: 15 })
    }
    .borderRadius(10)
    .backgroundColor(Color.White)
    .clip(true)
    .width('100%')
    .height(290)
  }
}, (item) => JSON.stringify(item))
```

**复用后：**

组件被复用后，ArkUI框架会将组件构造对应的参数输入给aboutToResue生命周期回调，开发者需要在aboutToReuse生命周期中对需要进行更新的状态变量进行赋值，ArkUI框架将会基于最新的状态变量值对UI进行展示。

如果同一种自定义组件的不同实例之间存在较大的结构差异，建议使用reuseId对不同的自定义组件实例分别标注复用组，以达到最佳的复用效果。

如果一个自定义组件中，持有对某个大对象或者其他非必要资源的引用，可以在aboutToRecycle生命周期中释放，以免造成内存泄漏。

```ts
LazyForEach(this.GoodDataOne, (item, index) => {
  GridItem() {
    GoodItems({
      boo:item.data.boo,
      img:item.data.img,
      webimg:item.data.webimg,
      hei:item.data.hei,
      introduce:item.data.introduce,
      price:item.data.price,
      numb:item.data.numb,
      index:index
    })
    .reuseId(this.CombineStr(item.type))
  }
}, (item) => JSON.stringify(item))


@Reusable
@Component
struct GoodItems {
  @State img: Resource = $r("app.media.photo61")
  @State webimg?: string = ''
  @State hei: number = 0
  @State introduce: string = ''
  @State price: string = ''
  @State numb: string = ''
  @LocalStorageLink('storageSimpleProp') simpleVarName: string = ''
  boo: boolean = true
  index: number = 0
  controllerVideo: VideoController = new VideoController();

  aboutToReuse(params)
  {
    this.webimg = params.webimg
    this.img = params.img
    this.hei = params.hei
    this.introduce = params.introduce
    this.price = params.price
    this.numb = params.numb
  }

  build() {
    // ...
  }
}
```

### 性能收益

通过DevEco Studio的profiler工具分析复用前后的组件创建时间，可以得到应用使能组件复用后的优化情况，组件创建的时间平均从1800us降低到了570us。

![before recycle](./figures/before-recycle.png)

![using recycle](./figures/using-recycle.png)

|                | 创建组件时间 |
| -------------- | ------------ |
| 不使能组件复用 | 1813us       |
| 使能组件复用   | 570us        |
