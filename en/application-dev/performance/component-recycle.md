# Best Practices for Component Reuse

Component reuse is a useful tool in the following scenarios for removing the frame rate bottleneck in the UI thread:

1. Scrolling scenarios where instances of the same type of custom components are frequently created and destroyed
2. Scenarios where branches of conditional rendering are switched repeatedly, and the component subtree structure in the branches is complex

For component reuse to take effect, the following conditions must be met:

1. The custom component to reuse is decorated by the @Reusable decorator.
2. The reusable custom component (child) created under a custom component (parent) is added to the reuse cache of the parent after being is removed from the component tree.
3. In attempts to create a reusable child component under a custom component (parent), the child is quickly created by updating the reusable component instance of the corresponding type, if any, in the reuse cache of the parent.

## Constraints

1. @Reusable indicates that a custom component can be reused. While it can be used to decorate any custom component, take notes of the creation and update processes of the custom component to ensure that the component behaves correctly after being reused.
2. The cache and reuse of reusable custom components can occur only under the same parent component. This means that instances of the same custom component cannot be reused under different parent components. For example, component A is a reusable component, which is also a child component of component B and in the reuse cache of component B. When component A is created in component C, component A cached in component B cannot be used in component C.
3. To reuse a subtree, you only need to decorate its root node with @Reusable. For example, if custom component A has custom child component B, then to reuse the subtree of A and B, you only need to add the @Reusable decorator to A.
4. When a custom component is nested within a reusable custom component, to update the content of the nested component, you must implement the **aboutToReuse** lifecycle callback in the component.
5. The performance benefits of component reuse mainly result from its reducing the time for creating JS objects and reusing the component tree structure. As such, if the component tree structure of custom components is significantly changed due to conditional rendering before or after the reuse, you will not be able to reap the performance benefits of component reuse.
6. Component reuse occurs only when a reusable component is removed from the component tree and then added to the component tree again. For example, if **ForEach** is used to create a reusable custom component, component reuse cannot be triggered due to the full expansion attribute of **ForEach**.
7. Reusable components cannot be nested. That is, if a reusable component exists in the subtree of another reusable component, undefined results may occur.

## Lifecycle

When a reusable component is removed from the component tree in C++ code, the **CustomNode** instance of the component on the native side of the ArkUI framework is mounted to the corresponding JSView. When reuse occurs, **CustomNode** is referenced by JSView and the **aboutToRecycle** callback on **ViewPU** is triggered. The **ViewPU** instance is referenced by **RecycleManager**.

When the reusable component is re-added to the component tree from **RecycleManager**, the **aboutToReuse** callback on the frontend **ViewPU** instance is called.

## Available APIs

Called when this reusable component is about to be added from the reuse cache to the component tree. The component's state variables can be updated in this callback. The argument type is the same as the constructor parameter type of the custom component.

```ts
aboutToReuse?(params: { [key: string]: unknown }): void;
```

Called when this reusable component is about to be added from the component tree to the reuse cache.

```ts
aboutToRecycle?(): void;
```

Adds this reusable component to a reuse group. Components with the same **reuseId** value are reused in the same reuse group.

```ts
reuseId(id: string);
```

Declares that a component is reusable.

```ts
declare const Reusable: ClassDecorator;
```

**Example**

```ts
// xxx.ets
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

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          ReusableChildComponent({ item: item })
        }
      }, (item: string) => item)
    }
    .width('100%')
    .height('100%')
  }
}

@Reusable
@Component
struct ReusableChildComponent {
  @State item: string = ''

  aboutToReuse(params: ESObject) {
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

## Samples

The following is the sample code of shopping snippets. Compare the benefits of creating customized components on the application side before and after component reuse and the code writing methods before and after component reuse.

### Code Before and After Component Reuse

**Before Component Reuse**

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

**After Component Reuse**

When the component is reused, the ArkUI framework passes to the **aboutToReuse** lifecycle callback the constructor parameters of the component. Assign values to the state variables to be updated in **aboutToReuse**, and the ArkUI framework will display the UI with the latest state variable values.

If the instances of a custom component vary greatly, use **reuseId** to assign these instances to different reuse groups to achieve the optimal effect.

If a custom component has a reference to a large object or other unnecessary resources, release the reference in the **aboutToRecycle** lifecycle callback to avoid memory leak.

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

### Performance Benefit

Analysis results from the profiler tool in DevEco Studio show that, with component reuse, the average component creation time is reduced from 1800 μs to 570 μs.

![before reuse](./figures/before-recycle.png)

![using reuse](./figures/using-recycle.png)

|                | Component Creation Time |
| -------------- | ------------ |
| Component reuse disabled | 1813 μs      |
| Component reuse enabled  | 570 μs       |

## Developer's Tips

1. When reusing a user-defined component, you are advised to avoid any operations that may change the component tree structure of the user-defined component and re-lay out reusable components to maximize the component reuse performance.

2. It is recommended that the component reuse capability be used together with the LazyForEach rendering control syntax in the list sliding scenario to achieve optimal performance.

3. Developers need to distinguish the behavior during the creation and update of customized components. Note that the reuse of customized components is essentially a special component update behavior. The process and lifecycle during component creation will not occur during component reuse, the construction parameters of the custom component are transferred to the custom component through the aboutToReuse lifecycle callback. In other words, the **aboutToAppear** lifecycle and initialization parameter input of the custom component will not occur during component reuse.

4. To avoid time-consuming operations during the aboutToReuse lifecycle callback, the best practice is to update the status variable values required for updating custom components only in aboutToReuse.

5. Do not update status variables such as @Link, @StorageLink, @ObjectLink, and @Consume in aboutToReuse. Otherwise, unnecessary component updates may be triggered.

6. Do not use functions as input parameters for creating reused customized components.

In the component reuse scenario, the data object associated with the component needs to be re-created each time the component is reused. As a result, the function in the input parameter is repeatedly executed to obtain the input parameter result. If time-consuming operations exist in the function, the performance will be severely affected. The following is an example:

[Incorrect Usage]

```ts
//BasicDateSource is the class that implements the IDataSource API. For details, see the LazyForEach usage guide.
//This is a reused customized component.
@Reusable
@Component
struct ChildComponent {
  @State desc: string = '';
  @State sum: number = 0;

  aboutToReuse(params: Record<string, Object>): void {
    this.desc = params.desc as string;
    this.sum = params.sum as number;
  }

  build() {
    Column() {
      Text ('subcomponent' + this.desc)
        .fontSize(30)
        .fontWeight(30)
      Text ('result' + this.sum)
        .fontSize(30)
        .fontWeight(30)
    }
  }
}

@Entry
@Component
struct Reuse {
  private data: BasicDateSource = new BasicDateSource();

  aboutToAppear(): void {
    for (let index = 0; index < 20; index++) {
      this.data.pushData(index.toString())
    }
  }
    
  //Unknown time-consuming operation logic may exist in functions in real scenarios. In this example, a loop function is used to simulate time-consuming operations.
  count(): number {
    let temp: number = 0;
    for (let index = 0; index < 10000; index++) {
      temp += index;
    }
    return temp;
  }

  build() {
    Column() {
      List() {
        LazyForEach(this.data, (item: string) => {
          ListItem() {
            //The sum parameter is obtained by a function. In actual development scenarios, time-consuming operations that may occur in the function cannot be predicted. Each time a component is reused, the function is repeatedly called.
            ChildComponent({ desc: item, sum: this.count() })
          }
          .width('100%')
          .height(100)
        }, (item: string) => item)
      }
    }
  }
}
```

In the preceding negative example, the reused subcomponent parameter sum is generated by using a time-consuming function. This function needs to be executed each time a component is reused, which causes performance problems and even frame freezing and loss during list sliding.

[Correct Usage]

```ts
//BasicDateSource is the class that implements the IDataSource API. For details, see the LazyForEach usage guide.
//This is a reused customized component.
@Reusable
@Component
struct ChildComponent {
  @State desc: string = '';
  @State sum: number = 0;

  aboutToReuse(params: Record<string, Object>): void {
    this.desc = params.desc as string;
    this.sum = params.sum as number;
  }

  build() {
    Column() {
      Text ('subcomponent' + this.desc)
        .fontSize(30)
        .fontWeight(30)
      Text ('result' + this.sum)
        .fontSize(30)
        .fontWeight(30)
    }
  }
}

@Entry
@Component
struct Reuse {
  private data: BasicDateSource = new BasicDateSource();
  @State sum: number = 0;

  aboutToAppear(): void {
    for (let index = 0; index < 20; index++) {
      this.data.pushData(index.toString())
    }
    //Execute the asynchronous function.
    this.count();
  }

  //Simulate the time-consuming operation logic.
  async count() {
    let temp: number = 0;
    for (let index = 0; index < 10000; index++) {
      temp += index;
    }
    //Put the result into the state variable.
    this.sum = temp;
  }

  build() {
    Column() {
      List() {
        LazyForEach(this.data, (item: string) => {
          ListItem() {
            //The parameters of the subcomponent are transferred through the status variable.
            ChildComponent({ desc: item, sum: this.sum })
          }
          .width('100%')
          .height(100)
        }, (item: string) => item)
      }
    }
  }
}
```

In the preceding positive example operation, the result generated by using the time-consuming function count remains unchanged. You can execute the result during initial page rendering and assign the result to this.sum. This.sum is used to transfer parameters of reused components.
