# LazyForEach：数据懒加载


LazyForEach从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。当在滚动容器中使用了LazyForEach，框架会根据滚动容器可视区域按需创建组件，当组件滑出可视区域外时，框架会进行组件销毁回收以降低内存占用。


## 接口描述


```ts
LazyForEach(
    dataSource: IDataSource,             // 需要进行数据迭代的数据源
    itemGenerator: (item: any, index?: number) => void,  // 子组件生成函数
    keyGenerator?: (item: any, index?: number) => string // 键值生成函数
): void
```

**参数：**


| 参数名        | 参数类型                                               | 必填 | 参数描述                                                     |
| ------------- | ------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| dataSource    | [IDataSource](#idatasource类型说明)                    | 是   | LazyForEach数据源，需要开发者实现相关接口。                  |
| itemGenerator | (item:&nbsp;any， index?:number)&nbsp;=&gt;&nbsp;void  | 是   | 子组件生成函数，为数组中的每一个数据项创建一个子组件。<br/>**说明：**<br/>item是当前数据项，index是数据项索引值。<br/>itemGenerator的函数体必须使用大括号{...}。itemGenerator每次迭代只能并且必须生成一个子组件。itemGenerator中可以使用if语句，但是必须保证if语句每个分支都会创建一个相同类型的子组件。itemGenerator中不允许使用ForEach和LazyForEach语句。 |
| keyGenerator  | (item:&nbsp;any, index?:number)&nbsp;=&gt;&nbsp;string | 否   | 键值生成函数，用于给数据源中的每一个数据项生成唯一且固定的键值。当数据项在数组中的位置更改时，其键值不得更改，当数组中的数据项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则LazyForEach中的所有节点都将重建。<br/>**说明：**<br/>item是当前数据项，index是数据项索引值。<br/>数据源中的每一个数据项生成的键值不能重复。 |

## IDataSource类型说明

```ts
interface IDataSource {
    totalCount(): number; // 获得数据总数
    getData(index: number): Object; // 获取索引值对应的数据
    registerDataChangeListener(listener: DataChangeListener): void; // 注册数据改变的监听器
    unregisterDataChangeListener(listener: DataChangeListener): void; // 注销数据改变的监听器
}
```

| 接口声明                                                     | 参数类型                                          | 说明                                                        |
| ------------------------------------------------------------ | ------------------------------------------------- | ----------------------------------------------------------- |
| totalCount():&nbsp;number                                    | -                                                 | 获得数据总数。                                              |
| getData(index:&nbsp;number):&nbsp;any                        | number                                            | 获取索引值index对应的数据。<br/>index：获取数据对应的索引值。 |
| registerDataChangeListener(listener:[DataChangeListener](#datachangelistener类型说明)):&nbsp;void | [DataChangeListener](#datachangelistener类型说明) | 注册数据改变的监听器。<br/>listener：数据变化监听器         |
| unregisterDataChangeListener(listener:[DataChangeListener](#datachangelistener类型说明)):&nbsp;void | [DataChangeListener](#datachangelistener类型说明) | 注销数据改变的监听器。<br/>listener：数据变化监听器         |

## DataChangeListener类型说明

```ts
interface DataChangeListener {
    onDataReloaded(): void; // 重新加载数据时调用
    onDataAdded(index: number): void; // 添加数据时调用
    onDataMoved(from: number, to: number): void; // 数据移动起始位置与数据移动目标位置交换时调用
    onDataDeleted(index: number): void; // 删除数据时调用
    onDataChanged(index: number): void; // 改变数据时调用
    onDataAdd(index: number): void; // 添加数据时调用
    onDataMove(from: number, to: number): void; // 数据移动起始位置与数据移动目标位置交换时调用
    onDataDelete(index: number): void; // 删除数据时调用
    onDataChange(index: number): void; // 改变数据时调用
}
```

| 接口声明                                                     | 参数类型                               | 说明                                                         |
| ------------------------------------------------------------ | -------------------------------------- | ------------------------------------------------------------ |
| onDataReloaded():&nbsp;void                                  | -                                      | 通知组件重新加载所有数据。<br/>键值没有变化的数据项会使用原先的子组件，键值发生变化的会重建子组件。 |
| onDataAdd(index:&nbsp;number):&nbsp;void<sup>8+</sup>        | number                                 | 通知组件index的位置有数据添加。<br/>index：数据添加位置的索引值。 |
| onDataMove(from:&nbsp;number,&nbsp;to:&nbsp;number):&nbsp;void<sup>8+</sup> | from:&nbsp;number,<br/>to:&nbsp;number | 通知组件数据有移动。<br/>from:&nbsp;数据移动起始位置，to:&nbsp;数据移动目标位置。<br/>**说明：**<br/>数据移动前后键值要保持不变，如果键值有变化，应使用删除数据和新增数据接口。 |
| onDataDelete(index: number):void<sup>8+</sup>                | number                                 | 通知组件删除index位置的数据并刷新LazyForEach的展示内容。<br/>index：数据删除位置的索引值。<br/>**说明：** <br/>需要保证dataSource中的对应数据已经在调用onDataDelete前删除，否则页面渲染将出现未定义的行为。 |
| onDataChange(index:&nbsp;number):&nbsp;void<sup>8+</sup>     | number                                 | 通知组件index的位置有数据有变化。<br/>index：数据变化位置的索引值。 |
| onDataAdded(index:&nbsp;number):void<sup>(deprecated)</sup>  | number                                 | 通知组件index的位置有数据添加。<br/>从API 8开始，建议使用onDataAdd。<br/>index：数据添加位置的索引值。 |
| onDataMoved(from:&nbsp;number,&nbsp;to:&nbsp;number):&nbsp;void<sup>(deprecated)</sup> | from:&nbsp;number,<br/>to:&nbsp;number | 通知组件数据有移动。<br/>从API 8开始，建议使用onDataMove。<br/>from:&nbsp;数据移动起始位置，to:&nbsp;数据移动目标位置。<br/>将from和to位置的数据进行交换。<br/>**说明：**<br/>数据移动前后键值要保持不变，如果键值有变化，应使用删除数据和新增数据接口。 |
| onDataDeleted(index: number):void<sup>(deprecated)</sup>     | number                                 | 通知组件删除index位置的数据并刷新LazyForEach的展示内容。<br/>从API 8开始，建议使用onDataDelete。<br/>index：数据删除位置的索引值。 |
| onDataChanged(index:&nbsp;number):&nbsp;void<sup>(deprecated)</sup> | number                                 | 通知组件index的位置有数据有变化。<br/>从API 8开始，建议使用onDataChange。<br/>index：数据变化监听器。 |


## 使用限制

- LazyForEach必须在容器组件内使用，仅有[List](../reference/arkui-ts/ts-container-list.md)、[Grid](../reference/arkui-ts/ts-container-grid.md)、[Swiper](../reference/arkui-ts/ts-container-swiper.md)以及[WaterFlow](../reference/arkui-ts/ts-container-waterflow.md)组件支持数据懒加载（可配置cachedCount属性，即只加载可视部分以及其前后少量数据用于缓冲），其他组件仍然是一次性加载所有的数据。
- LazyForEach在每次迭代中，必须创建且只允许创建一个子组件。
- 生成的子组件必须是允许包含在LazyForEach父容器组件中的子组件。
- 允许LazyForEach包含在if/else条件渲染语句中，也允许LazyForEach中出现if/else条件渲染语句。
- 键值生成器必须针对每个数据生成唯一的值，如果键值相同，将导致键值相同的UI组件被框架忽略，从而无法在父容器内显示。
- LazyForEach必须使用DataChangeListener对象来进行更新，第一个参数dataSource使用状态变量时，状态变量改变不会触发LazyForEach的UI刷新。
- 为了高性能渲染，通过DataChangeListener对象的onDataChange方法来更新UI时，需要生成不同于原来的键值来触发组件刷新。

## 键值生成规则

在`LazyForEach`循环渲染过程中，系统会为每个item生成一个唯一且持久的键值，用于标识对应的组件。当这个键值变化时，ArkUI框架将视为该数组元素已被替换或修改，并会基于新的键值创建一个新的组件。

`LazyForEach`提供了一个名为`keyGenerator`的参数，这是一个函数，开发者可以通过它自定义键值的生成规则。如果开发者没有定义`keyGenerator`函数，则ArkUI框架会使用默认的键值生成函数，即`(item: any, index: number) => { return viewId + '-' + index.toString(); }`, viewId在编译器转换过程中生成，同一个LazyForEach组件内其viewId是一致的。

## 组件创建规则

在确定键值生成规则后，LazyForEach的第二个参数`itemGenerator`函数会根据键值生成规则为数据源的每个数组项创建组件。组件的创建包括两种情况：[LazyForEach首次渲染](#首次渲染)和[LazyForEach非首次渲染](#非首次渲染)。

### 首次渲染

- ### 生成不同键值

在LazyForEach首次渲染时，会根据上述键值生成规则为数据源的每个数组项生成唯一键值，并创建相应的组件。

```ts
// Basic implementation of IDataSource to handle data listener
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  // 该方法为框架侧调用，为LazyForEach组件向其数据源处添加listener监听
  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  // 该方法为框架侧调用，为对应的LazyForEach组件在数据源处去除listener监听
  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
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
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource();
   
  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

在上述代码中，键值生成规则是`keyGenerator`函数的返回值`item`。在`LazyForEach`循环渲染时，其为数据源数组项依次生成键值`Hello 0`、`Hello 1` ... `Hello 20`，并创建对应的`ListItem`子组件渲染到界面上。

运行效果如下图所示。

**图1**  LazyForEach正常首次渲染  
![LazyForEach-Render-DifferentKey](./figures/LazyForEach-Render-DifferentKey.gif)

- ### 键值相同时错误渲染

当不同数据项生成的键值相同时，框架的行为是不可预测的。例如，在以下代码中，`LazyForEach`渲染的数据项键值均相同，在滑动过程中，`LazyForEach`会对划入划出当前页面的子组件进行预加载，而新建的子组件和销毁的原子组件具有相同的键值，框架可能存在取用缓存错误的情况，导致子组件渲染有问题。

 ```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
      }, (item: string) => 'same key')
    }.cachedCount(5)
  }
}
 ```

运行效果如下图所示。可以看到`Hello 0`在滑动过程中被错误渲染为`Hello 13`。

**图2**  LazyForEach存在相同键值  
![LazyForEach-Render-SameKey](./figures/LazyForEach-Render-SameKey.gif)

### 非首次渲染

当`LazyForEach`数据源发生变化，需要再次渲染时，开发者应根据数据源的变化情况调用`listener`对应的接口，通知`LazyForEach`做相应的更新，各使用场景如下。

- ### 添加数据

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
        .onClick(() => {
          // 点击追加子组件
          this.data.pushData(`Hello ${this.data.totalCount()}`);
        })
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

当我们点击`LazyForEach`的子组件时，首先调用数据源`data`的`pushData`方法，该方法会在数据源末尾添加数据并调用`notifyDataAdd`方法。在`notifyDataAdd`方法内会又调用`listener.onDataAdd`方法，该方法会通知`LazyForEach`在该处有数据添加，`LazyForEach`便会在该索引处新建子组件。

运行效果如下图所示。

**图3**  LazyForEach添加数据  
![LazyForEach-Add-Data](./figures/LazyForEach-Add-Data.gif)

- ### 删除数据

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }
}

class MyDataSource extends BasicDataSource {
  dataArray: string[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
  
  public deleteData(index: number): void {
    this.dataArray.splice(index, 1);
    this.notifyDataDelete(index);
  }
}

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string, index: number) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
        .onClick(() => {
          // 点击删除子组件
          this.data.deleteData(this.data.dataArray.indexOf(item));
        })
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

当我们点击`LazyForEach`的子组件时，首先调用数据源`data`的`deleteData`方法，该方法会删除数据源对应索引处的数据并调用`notifyDatDelete`方法。在`notifyDataDelete`方法内会又调用`listener.onDataDelete`方法，该方法会通知`LazyForEach`在该处有数据删除，`LazyForEach`便会在该索引处删除对应子组件。

运行效果如下图所示。

**图4**  LazyForEach删除数据  
![LazyForEach-Delete-Data](./figures/LazyForEach-Delete-Data.gif)

- ### 改变单个数据

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
  
  public deleteData(index: number): void {
    this.dataArray.splice(index, 1);
    this.notifyDataDelete(index);
  }
  
  public changeData(index: number, data: string): void {
    this.dataArray.splice(index, 1, data);
    this.notifyDataChange(index);
  }
}

@Entry
@Component
struct MyComponent {
  private moved: number[] = [];
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }


  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string, index: number) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
        .onClick(() => {
          this.data.changeData(index, item + '00');
        })
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

当我们点击`LazyForEach`的子组件时，首先改变当前数据，然后调用数据源`data`的`changeData`方法，在该方法内会调用`notifyDataChange`方法。在`notifyDataChange`方法内会又调用`listener.onDataChange`方法，该方法通知`LazyForEach`组件该处有数据发生变化，`LazyForEach`便会在对应索引处重建子组件。

运行效果如下图所示。

**图5**  LazyForEach改变单个数据  
![LazyForEach-Change-SingleData](./figures/LazyForEach-Change-SingleData.gif)

- ### 改变多个数据

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: string[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): string {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: string[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): string {
    return this.dataArray[index];
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: string): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
  
  public deleteData(index: number): void {
    this.dataArray.splice(index, 1);
    this.notifyDataDelete(index);
  }
  
  public changeData(index: number): void {
    this.notifyDataChange(index);
  }
    
  public reloadData(): void {
    this.notifyDataReload();
  }
    
  public modifyAllData(): void {
    this.dataArray = this.dataArray.map((item: string) => {
        return item + '0';
    })
  }
}

@Entry
@Component
struct MyComponent {
  private moved: number[] = [];
  private data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(`Hello ${i}`)
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string, index: number) => {
        ListItem() {
          Row() {
            Text(item).fontSize(50)
              .onAppear(() => {
                console.info("appear:" + item)
              })
          }.margin({ left: 10, right: 10 })
        }
        .onClick(() => {
          this.data.modifyAllData();
          this.data.reloadData();
        })
      }, (item: string) => item)
    }.cachedCount(5)
  }
}
```

当我们点击`LazyForEach`的子组件时，首先调用`data`的`modifyAllData`方法改变了数据源中的所有数据，然后调用数据源的`reloadData`方法，在该方法内会调用`notifyDataReload`方法。在`notifyDataReload`方法内会又调用`listener.onDataReloaded`方法，通知`LazyForEach`需要重建所有子节点。`LazyForEach`会将原所有数据项和新所有数据项一一做键值比对，若有相同键值则使用缓存，若键值不同则重新构建。

运行效果如下图所示。

**图6**  LazyForEach改变多个数据  
![LazyForEach-Reload-Data](./figures/LazyForEach-Reload-Data.gif)

- ### 改变数据子属性

若仅靠`LazyForEach`的刷新机制，当`item`变化时若想更新子组件，需要将原来的子组件全部销毁再重新构建，在子组件结构较为复杂的情况下，靠改变键值去刷新渲染性能较低。因此框架提供了`@Observed`与@`ObjectLink`机制进行深度观测，可以做到仅刷新使用了该属性的组件，提高渲染性能。开发者可根据其自身业务特点选择使用哪种刷新方式。

```ts
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = [];
  private originDataArray: StringData[] = [];

  public totalCount(): number {
    return 0;
  }

  public getData(index: number): StringData {
    return this.originDataArray[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener');
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener');
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded();
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index);
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    })
  }
}

class MyDataSource extends BasicDataSource {
  private dataArray: StringData[] = [];

  public totalCount(): number {
    return this.dataArray.length;
  }

  public getData(index: number): StringData {
    return this.dataArray[index];
  }

  public addData(index: number, data: StringData): void {
    this.dataArray.splice(index, 0, data);
    this.notifyDataAdd(index);
  }

  public pushData(data: StringData): void {
    this.dataArray.push(data);
    this.notifyDataAdd(this.dataArray.length - 1);
  }
}

@Observed
class StringData {
  message: string;
  constructor(message: string) {
    this.message = message;
  }  
}

@Entry
@Component
struct MyComponent {
  private moved: number[] = [];
  @State data: MyDataSource = new MyDataSource();

  aboutToAppear() {
    for (let i = 0; i <= 20; i++) {
      this.data.pushData(new StringData(`Hello ${i}`));
    }
  }

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: StringData, index: number) => {
        ListItem() {
          ChildComponent({data: item})
        }
        .onClick(() => {
          item.message += '0';
        })
      }, (item: StringData, index: number) => index.toString())
    }.cachedCount(5)
  }
}

@Component
struct ChildComponent {
  @ObjectLink data: StringData
  build() {
    Row() {
      Text(this.data.message).fontSize(50)
        .onAppear(() => {
          console.info("appear:" + this.data.message)
        })
    }.margin({ left: 10, right: 10 })
  }
}
```

此时点击`LazyForEach`子组件改变`item.message`时，重渲染依赖的是`ChildComponent`的`@ObjectLink`成员变量对其子属性的监听，此时框架只会刷新`Text(this.data.message)`，不会去重建整个`ListItem`子组件。

**图7**  LazyForEach改变数据子属性  
![LazyForEach-Change-SubProperty](./figures/LazyForEach-Change-SubProperty.gif)

## 常见使用问题

- ### 渲染结果非预期

  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: string[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): string {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  }
  
  class MyDataSource extends BasicDataSource {
    private dataArray: string[] = [];
  
    public totalCount(): number {
      return this.dataArray.length;
    }
  
    public getData(index: number): string {
      return this.dataArray[index];
    }
  
    public addData(index: number, data: string): void {
      this.dataArray.splice(index, 0, data);
      this.notifyDataAdd(index);
    }
  
    public pushData(data: string): void {
      this.dataArray.push(data);
      this.notifyDataAdd(this.dataArray.length - 1);
    }
    
    public deleteData(index: number): void {
      this.dataArray.splice(index, 1);
      this.notifyDataDelete(index);
    }
  }
  
  @Entry
  @Component
  struct MyComponent {
    private data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(`Hello ${i}`)
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: string, index: number) => {
          ListItem() {
            Row() {
              Text(item).fontSize(50)
                .onAppear(() => {
                  console.info("appear:" + item)
                })
            }.margin({ left: 10, right: 10 })
          }
          .onClick(() => {
            // 点击删除子组件
            this.data.deleteData(index);
          })
        }, (item: string) => item)
      }.cachedCount(5)
    }
  }
  ```

  **图8**  LazyForEach删除数据非预期  
  ![LazyForEach-Render-Not-Expected](./figures/LazyForEach-Render-Not-Expected.gif)

  当我们多次点击子组件时，会发现删除的并不一定是我们点击的那个子组件。原因是当我们删除了某一个子组件后，位于该子组件对应的数据项之后的各数据项，其`index`均应减1，但实际上后续的数据项对应的子组件仍然使用的是最初分配的`index`，其`itemGenerator`中的`index`并没有发生变化，所以删除结果和预期不符。

  修复代码如下所示。

  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: string[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): string {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  }
  
  class MyDataSource extends BasicDataSource {
    private dataArray: string[] = [];
  
    public totalCount(): number {
      return this.dataArray.length;
    }
  
    public getData(index: number): string {
      return this.dataArray[index];
    }
  
    public addData(index: number, data: string): void {
      this.dataArray.splice(index, 0, data);
      this.notifyDataAdd(index);
    }
  
    public pushData(data: string): void {
      this.dataArray.push(data);
      this.notifyDataAdd(this.dataArray.length - 1);
    }
    
    public deleteData(index: number): void {
      this.dataArray.splice(index, 1);
      this.notifyDataDelete(index);
    }
      
    public reloadData(): void {
      this.notifyDataReload();
    }
  }
  
  @Entry
  @Component
  struct MyComponent {
    private data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(`Hello ${i}`)
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: string, index: number) => {
          ListItem() {
            Row() {
              Text(item).fontSize(50)
                .onAppear(() => {
                  console.info("appear:" + item)
                })
            }.margin({ left: 10, right: 10 })
          }
          .onClick(() => {
            // 点击删除子组件
            this.data.deleteData(index);
            // 重置所有子组件的index索引
            this.data.reloadData();
          })
        }, (item: string, index: number) => item + index.toString())
      }.cachedCount(5)
    }
  }
  ```

  在删除一个数据项后调用`reloadData`方法，重建后面的数据项，以达到更新`index`索引的目的。

  **图9**  修复LazyForEach删除数据非预期  
  ![LazyForEach-Render-Not-Expected-Repair](./figures/LazyForEach-Render-Not-Expected-Repair.gif)

- ### 重渲染时图片闪烁

  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: StringData[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): StringData {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  }
  
  class MyDataSource extends BasicDataSource {
    private dataArray: StringData[] = [];
  
    public totalCount(): number {
      return this.dataArray.length;
    }
  
    public getData(index: number): StringData {
      return this.dataArray[index];
    }
  
    public addData(index: number, data: StringData): void {
      this.dataArray.splice(index, 0, data);
      this.notifyDataAdd(index);
    }
  
    public pushData(data: StringData): void {
      this.dataArray.push(data);
      this.notifyDataAdd(this.dataArray.length - 1);
    }
      
    public reloadData(): void {
      this.notifyDataReload();
    }
  }
  
  class StringData {
    message: string;
    imgSrc: Resource;
    constructor(message: string, imgSrc: Resource) {
        this.message = message;
        this.imgSrc = imgSrc;
    }  
  }
  
  @Entry
  @Component
  struct MyComponent {
    private moved: number[] = [];
    private data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(new StringData(`Hello ${i}`, $r('app.media.img')));
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: StringData, index: number) => {
          ListItem() {
            Column() {
              Text(item.message).fontSize(50)
                .onAppear(() => {
                  console.info("appear:" + item.message)
                })
              Image(item.imgSrc)
                .width(500)
                .height(200)
            }.margin({ left: 10, right: 10 })
          }
          .onClick(() => {
            item.message += '00';
            this.data.reloadData();
          })
        }, (item: StringData, index: number) => JSON.stringify(item))
      }.cachedCount(5)
    }
  }
  ```

  **图10**  LazyForEach仅改变文字但是图片闪烁问题  
  ![LazyForEach-Image-Flush](./figures/LazyForEach-Image-Flush.gif)

  在我们点击`ListItem`子组件时，我们只改变了数据项的`message`属性，但是`LazyForEach`的刷新机制会导致整个`ListItem`被重建。由于`Image`组件是异步刷新，所以视觉上图片会发生闪烁。为了解决这种情况我们应该使用`@ObjectLink`和`@Observed`去单独刷新使用了`item.message`的`Text`组件。

  修复代码如下所示。

  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: StringData[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): StringData {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  }
  
  class MyDataSource extends BasicDataSource {
    private dataArray: StringData[] = [];
  
    public totalCount(): number {
      return this.dataArray.length;
    }
  
    public getData(index: number): StringData {
      return this.dataArray[index];
    }
  
    public addData(index: number, data: StringData): void {
      this.dataArray.splice(index, 0, data);
      this.notifyDataAdd(index);
    }
  
    public pushData(data: StringData): void {
      this.dataArray.push(data);
      this.notifyDataAdd(this.dataArray.length - 1);
    }
  }
  
  @Observed
  class StringData {
    message: string;
    imgSrc: Resource;
    constructor(message: string, imgSrc: Resource) {
        this.message = message;
        this.imgSrc = imgSrc;
    }  
  }
  
  @Entry
  @Component
  struct MyComponent {
    @State data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(new StringData(`Hello ${i}`, $r('app.media.img')));
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: StringData, index: number) => {
          ListItem() {
            ChildComponent({data: item})
          }
          .onClick(() => {
            item.message += '0';
          })
        }, (item: StringData, index: number) => index.toString())
      }.cachedCount(5)
    }
  }
  
  @Component
  struct ChildComponent {
    @ObjectLink data: StringData
    build() {
      Column() {
        Text(this.data.message).fontSize(50)
          .onAppear(() => {
            console.info("appear:" + this.data.message)
          })
        Image(this.data.imgSrc)
          .width(500)
          .height(200)
      }.margin({ left: 10, right: 10 })
    }
  }
  ```

  **图11**  修复LazyForEach仅改变文字但是图片闪烁问题  
  ![LazyForEach-Image-Flush-Repair](./figures/LazyForEach-Image-Flush-Repair.gif)

- ### @ObjectLink属性变化UI未更新

  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: StringData[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): StringData {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  }
  
  class MyDataSource extends BasicDataSource {
    private dataArray: StringData[] = [];
  
    public totalCount(): number {
      return this.dataArray.length;
    }
  
    public getData(index: number): StringData {
      return this.dataArray[index];
    }
  
    public addData(index: number, data: StringData): void {
      this.dataArray.splice(index, 0, data);
      this.notifyDataAdd(index);
    }
  
    public pushData(data: StringData): void {
      this.dataArray.push(data);
      this.notifyDataAdd(this.dataArray.length - 1);
    }
  }
  
  @Observed
  class StringData {
    message: NestedString;
    constructor(message: NestedString) {
      this.message = message;
    }  
  }
  
  @Observed
  class NestedString {
    message: string;
    constructor(message: string) {
      this.message = message;
    }  
  }
  
  @Entry
  @Component
  struct MyComponent {
    private moved: number[] = [];
    @State data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(new StringData(new NestedString(`Hello ${i}`)));
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: StringData, index: number) => {
          ListItem() {
            ChildComponent({data: item})
          }
          .onClick(() => {
            item.message.message += '0';
          })
        }, (item: StringData, index: number) => item.toString() + index.toString())
      }.cachedCount(5)
    }
  }
  
  @Component
  struct ChildComponent {
    @ObjectLink data: StringData
    build() {
      Row() {
        Text(this.data.message.message).fontSize(50)
          .onAppear(() => {
            console.info("appear:" + this.data.message.message)
          })
      }.margin({ left: 10, right: 10 })
    }
  }
  ```

  **图12**  ObjectLink属性变化后UI未更新  
  ![LazyForEach-ObjectLink-NotRenderUI](./figures/LazyForEach-ObjectLink-NotRenderUI.gif)
  
  @ObjectLink装饰的成员变量仅能监听到其子属性的变化，再深入嵌套的属性便无法观测到了，因此我们只能改变它的子属性去通知对应组件重新渲染，具体[请查看@ObjectLink与@Observed的详细使用方法和限制条件](./arkts-observed-and-objectlink.md)。
  
  修复代码如下所示。
  
  ```ts
  class BasicDataSource implements IDataSource {
    private listeners: DataChangeListener[] = [];
    private originDataArray: StringData[] = [];
  
    public totalCount(): number {
      return 0;
    }
  
    public getData(index: number): StringData {
      return this.originDataArray[index];
    }
  
    registerDataChangeListener(listener: DataChangeListener): void {
      if (this.listeners.indexOf(listener) < 0) {
        console.info('add listener');
        this.listeners.push(listener);
      }
    }
  
    unregisterDataChangeListener(listener: DataChangeListener): void {
      const pos = this.listeners.indexOf(listener);
      if (pos >= 0) {
        console.info('remove listener');
        this.listeners.splice(pos, 1);
      }
    }
  
    notifyDataReload(): void {
      this.listeners.forEach(listener => {
        listener.onDataReloaded();
      })
    }
  
    notifyDataAdd(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataAdd(index);
      })
    }
  
    notifyDataChange(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataChange(index);
      })
    }
  
    notifyDataDelete(index: number): void {
      this.listeners.forEach(listener => {
        listener.onDataDelete(index);
      })
    }
  }
  
  class MyDataSource extends BasicDataSource {
    private dataArray: StringData[] = [];
  
    public totalCount(): number {
      return this.dataArray.length;
    }
  
    public getData(index: number): StringData {
      return this.dataArray[index];
    }
  
    public addData(index: number, data: StringData): void {
      this.dataArray.splice(index, 0, data);
      this.notifyDataAdd(index);
    }
  
    public pushData(data: StringData): void {
      this.dataArray.push(data);
      this.notifyDataAdd(this.dataArray.length - 1);
    }
  }
  
  @Observed
  class StringData {
    message: NestedString;
    constructor(message: NestedString) {
      this.message = message;
    }  
  }
  
  @Observed
  class NestedString {
    message: string;
    constructor(message: string) {
      this.message = message;
    }  
  }
  
  @Entry
  @Component
  struct MyComponent {
    private moved: number[] = [];
    @State data: MyDataSource = new MyDataSource();
  
    aboutToAppear() {
      for (let i = 0; i <= 20; i++) {
        this.data.pushData(new StringData(new NestedString(`Hello ${i}`)));
      }
    }
  
    build() {
      List({ space: 3 }) {
        LazyForEach(this.data, (item: StringData, index: number) => {
          ListItem() {
            ChildComponent({data: item})
          }
          .onClick(() => {
            item.message = new NestedString(item.message.message + '0');
          })
        }, (item: StringData, index: number) => item.toString() + index.toString())
      }.cachedCount(5)
    }
  }
  
  @Component
  struct ChildComponent {
    @ObjectLink data: StringData
    build() {
      Row() {
        Text(this.data.message.message).fontSize(50)
          .onAppear(() => {
            console.info("appear:" + this.data.message.message)
          })
      }.margin({ left: 10, right: 10 })
    }
  }
  ```
  
  **图13**  修复ObjectLink属性变化后UI更新  
  ![LazyForEach-ObjectLink-NotRenderUI-Repair](./figures/LazyForEach-ObjectLink-NotRenderUI-Repair.gif)
