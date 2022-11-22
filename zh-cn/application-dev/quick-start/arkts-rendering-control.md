# 渲染控制

ArkTS也提供了渲染控制的能力。条件渲染可根据应用的不同状态，渲染对应状态下的UI内容。循环渲染可从数据源中迭代获取数据，并在每次迭代过程中创建相应的组件。

## 条件渲染

使用if/else进行条件渲染。


> **说明：**
>
> - if/else条件语句可以使用状态变量。
>
> - 使用if/else可以使子组件的渲染依赖条件语句。
>
> - 必须在容器组件内使用。
>
> - 某些容器组件限制子组件的类型或数量，将if/else用于这些组件内时，这些限制将同样应用于if/else语句内创建的组件。例如，Grid容器组件的子组件仅支持GridItem组件，在Grid内使用if/else时，则if/else语句内也仅允许使用GridItem组件。


```ts
Column() {
  if (this.count < 0) {
    Text('count is negative').fontSize(14)
  } else if (this.count % 2 === 0) {
    Text('count is even').fontSize(14)
  } else {
    Text('count is odd').fontSize(14)
  }
}
```

## 循环渲染

通过循环渲染（ForEach）从数组中获取数据，并为每个数据项创建相应的组件，可减少代码复杂度。

```
ForEach(
  arr: any[], 
  itemGenerator: (item: any, index?: number) => void,
  keyGenerator?: (item: any, index?: number) => string 
)
```

**参数：**

| 参数名        | 参数类型                              | 必填 | 参数描述                                                     |
| ------------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| arr           | any[]                                 | 是   | 必须是数组，允许设置为空数组，空数组场景下将不会创建子组件。同时允许设置返回值为数组类型的函数，例如arr.slice(1, 3)，设置的函数不得改变包括数组本身在内的任何状态变量，如Array.splice、Array.sort或Array.reverse这些改变原数组的函数。 |
| itemGenerator | (item: any, index?: number) => void   | 是   | 生成子组件的lambda函数，为数组中的每一个数据项创建一个或多个子组件，单个子组件或子组件列表必须包括在大括号“{...}”中。 |
| keyGenerator  | (item: any, index?: number) => string | 否   | 匿名函数，用于给数组中的每一个数据项生成唯一且固定的键值。当数据项在数组中的位置更改时，其键值不得更改，当数组中的数据项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则ForEach中的所有节点都将重建。 |

> **说明：**
>
> - ForEach必须在容器组件内使用。
>
> - 生成的子组件应当是允许包含在ForEach父容器组件中的子组件。
>
> - 允许子组件生成器函数中包含if/else条件渲染，同时也允许ForEach包含在if/else条件渲染语句中。
>
> - itemGenerator函数的调用顺序不一定和数组中的数据项相同，在开发过程中不要假设itemGenerator和keyGenerator函数是否执行及其执行顺序。例如，以下示例可能无法正常工作：
>
>   ```ts
>   ForEach(anArray.map((item1, index1) => { return { i: index1 + 1, data: item1 }; }), 
>     item => Text(`${item.i}. item.data.label`),
>     item => item.data.id.toString())
>   ```

## 示例

```ts
// xxx.ets
@Entry
@Component
struct MyComponent {
  @State arr: number[] = [10, 20, 30]

  build() {
    Column({ space: 5 }) {
      Button('Reverse Array')
        .onClick(() => {
          this.arr.reverse()
        })

      ForEach(this.arr, (item: number) => {
        Text(`item value: ${item}`).fontSize(18)
        Divider().strokeWidth(2)
      }, (item: number) => item.toString())
    }
  }
}
```

![forEach1](figures/forEach1.gif)

## 数据懒加载

通过数据懒加载（LazyForEach）从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。

```ts
LazyForEach(
  dataSource: IDataSource,             
  itemGenerator: (item: any) => void,  
  keyGenerator?: (item: any) => string 
): void

interface IDataSource {
  totalCount(): number;                                           
  getData(index: number): any;                                   
  registerDataChangeListener(listener: DataChangeListener): void;   
  unregisterDataChangeListener(listener: DataChangeListener): void;
}

interface DataChangeListener {
  onDataReloaded(): void;                      
  onDataAdd(index: number): void;            
  onDataMove(from: number, to: number): void; 
  onDataDelete(index: number): void;         
  onDataChange(index: number): void;          
}
```

**参数：**

| 参数名        | 参数类型              | 必填 | 参数描述                                                     |
| ------------- | --------------------- | ---- | ------------------------------------------------------------ |
| dataSource    | IDataSource           | 是   | 实现IDataSource接口的对象，需要开发者实现相关接口。          |
| itemGenerator | (item: any, index?: number) => void   | 是   | 生成子组件的lambda函数，为数组中的每一个数据项创建一个或多个子组件，单个子组件或子组件列表必须包括在大括号“{...}”中。 |
| keyGenerator  | (item: any, index?: number) => string | 否   | 匿名函数，用于给数组中的每一个数据项生成唯一且固定的键值。当数据项在数组中的位置更改时，其键值不得更改，当数组中的数据项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则LazyForEach中的所有节点都将重建。 |

### IDataSource类型说明

| 名称                                                         | 描述                   |
| ------------------------------------------------------------ | ---------------------- |
| totalCount(): number                                         | 获取数据总数。         |
| getData(index: number): any                                  | 获取索引值index对应的数据。   |
| registerDataChangeListener(listener:DataChangeListener): void | 注册数据改变的监听器。 |
| unregisterDataChangeListener(listener:DataChangeListener): void | 注销数据改变的监听器。 |

### DataChangeListener类型说明

| 名称                                                     | 描述                                   |
| -------------------------------------------------------- | -------------------------------------- |
| onDataReloaded(): void                                   | 重新加载所有数据。                     |
| onDataAdded(index: number): void<sup>deprecated</sup>           | 通知组件index的位置有数据添加。从API Version 8开始废弃，建议使用onDataAdd。       |
| onDataMoved(from: number, to: number): void<sup>deprecated</sup> | 通知组件数据从from的位置移到to的位置。从API Version 8开始废弃，建议使用onDataMove。 |
| onDataDeleted(index: number): void<sup>deprecated</sup>         | 通知组件index的位置有数据删除。从API Version 8开始废弃，建议使用onDataDelete。        |
| onDataChanged(index: number): void<sup>deprecated</sup>          | 通知组件index的位置有数据变化。 从API Version 8开始废弃，建议使用onDataChange。       |
| onDataAdd(index: number): void<sup>8+</sup>                     | 通知组件index的位置有数据添加。        |
| onDataMove(from: number, to: number): void<sup>8+</sup>           | 通知组件数据从from的位置移到to的位置。 |
| onDataDelete(index: number): void<sup>8+</sup>                     | 通知组件index的位置有数据删除。        |
| onDataChange(index: number): void<sup>8+</sup>                     | 通知组件index的位置有数据变化。        |

## 示例

```ts
// xxx.ets
class BasicDataSource implements IDataSource {
  private listeners: DataChangeListener[] = []

  public totalCount(): number {
    return 0
  }

  public getData(index: number): any {
    return undefined
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      console.info('add listener')
      this.listeners.push(listener)
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      console.info('remove listener')
      this.listeners.splice(pos, 1)
    }
  }

  notifyDataReload(): void {
    this.listeners.forEach(listener => {
      listener.onDataReloaded()
    })
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index)
    })
  }

  notifyDataChange(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataChange(index)
    })
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index)
    })
  }

  notifyDataMove(from: number, to: number): void {
    this.listeners.forEach(listener => {
      listener.onDataMove(from, to)
    })
  }
}

class MyDataSource extends BasicDataSource {
  // 初始化数据列表
  private dataArray: string[] = ['/path/image0.png', '/path/image1.png', '/path/image2.png', '/path/image3.png']

  public totalCount(): number {
    return this.dataArray.length
  }

  public getData(index: number): any {
    return this.dataArray[index]
  }

  public addData(index: number, data: string): void {
    this.dataArray.splice(index, 0, data)
    this.notifyDataAdd(index)
  }

  public pushData(data: string): void {
    this.dataArray.push(data)
    this.notifyDataAdd(this.dataArray.length - 1)
  }
}

@Entry
@Component
struct MyComponent {
  private data: MyDataSource = new MyDataSource()

  build() {
    List({ space: 3 }) {
      LazyForEach(this.data, (item: string) => {
        ListItem() {
          Row() {
            Image(item).width(50).height(50)
            Text(item).fontSize(20).margin({ left: 10 })
          }.margin({ left: 10, right: 10 })
        }
        .onClick(() => {
          // 每点击一次列表项，数据增加一项
          this.data.pushData('/path/image' + this.data.totalCount() + '.png')
        })
      }, item => item)
    }
  }
}
```

> **说明：**
>
> - LazyForEach必须在容器组件内使用，目前仅有List、Grid以及Swiper组件支持数据懒加载（即只加载可视部分以及其前后少量数据用于缓冲），其他组件仍然是一次性加载所有的数据。
>
> - LazyForEach在每次迭代中，必须创建且只允许创建一个子组件。
>
> - 生成的子组件必须是允许包含在LazyForEach父容器组件中的子组件。
>
> - 允许LazyForEach包含在if/else条件渲染语句中，但不允许LazyForEach中出现if/else条件渲染语句。
>
> - 为了高性能渲染，通过DataChangeListener对象的onDataChange方法来更新UI时，仅当itemGenerator中创建的子组件内使用了状态变量时，才会触发组件刷新。
>
> - itemGenerator函数的调用顺序不一定和数据源中的数据项相同，在开发过程中不要假设itemGenerator和keyGenerator函数是否执行及其执行顺序。例如，以下示例可能无法正常工作：
>
>   ```ts
>   LazyForEach(dataSource, 
>     item => Text(`${item.i}. item.data.label`)),
>     item => item.data.id.toString())
>   ```

![lazyForEach](figures/lazyForEach.gif)