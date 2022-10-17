# 渲染控制

ArkTS也提供了渲染控制的能力。条件渲染可根据应用的不同状态，渲染对应状态下的部分内容。循环渲染可从数据源中迭代获取数据，并在每次迭代过程中创建相应的组件。

## 条件渲染

使用if/else进行条件渲染。


> **说明：**
>
> - if条件语句可以使用状态变量。
>
> - 使用if可以使子组件的渲染依赖条件语句。
>
> - 必须在容器组件内使用。
>
> - 某些容器组件限制子组件的类型或数量。将if放置在这些组件内时，这些限制将应用于if和else语句内创建的组件。例如，Grid组件的子组件仅支持GridItem组件，在Grid组件内使用if时，则if条件语句内仅允许使用GridItem组件。


```ts
Column() {
    if (this.count < 0) {
        Text('count is negative')
    } else if (this.count % 2 === 0) {
        Divider()
        Text('even')
    } else {
        Divider()
        Text('odd')
    }
}
```

## 循环渲染

通过循环渲染（ForEach组件）来迭代数组，并为每个数组项创建相应的组件，可减少代码复杂度。

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
| arr           | any[]                                 | 是   | 必须是数组，允许空数组，空数组场景下不会创建子组件。同时允许设置返回值为数组类型的函数，例如arr.slice(1, 3)，设置的函数不得改变包括数组本身在内的任何状态变量，如Array.splice、Array.sort或Array.reverse这些改变原数组的函数。 |
| itemGenerator | (item: any, index?: number) => void   | 是   | 生成子组件的lambda函数，为给定数组项生成一个或多个子组件，单个组件和子组件列表必须括在大括号“{....}”中。 |
| keyGenerator  | (item: any, index?: number) => string | 否   | 匿名参数，用于给定数组项生成唯一且稳定的键值。当子项在数组中的位置更改时，子项的键值不得更改，当数组中的子项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则ForEach中的所有节点都将重建。 |

> **说明：**
>
> - ForEach组件必须在容器组件内使用；
>
> - 生成的子组件允许在ForEach的父容器组件中，允许子组件生成器函数中包含if/else条件渲染，同时也允许ForEach包含在if/else条件渲染语句中；
>
> - 子项生成器函数的调用顺序不一定和数组中的数据项相同，在开发过程中不要假设子项生成器和键值生成器函数是否执行以及执行顺序。如下示例可能无法正常工作：
>
>   ```
>   ForEach(anArray.map((item1, index1) => { return { i: index1 + 1, data: item1 }; }), 
>           item => Text(`${item.i}. item.data.label`),
>           item => item.data.id.toString())
>   ```

## 示例

```ts
// xxx.ets
@Entry
@Component
struct MyComponent {
  @State arr: number[] = [10, 20, 30]

  build() {
    Column() {
      Button() {
        Text('Reverse Array')
      }.onClick(() => {
        this.arr.reverse()
      })

      ForEach(this.arr,
        (item: number) => {
          Text(`item value: ${item}`)
          Divider()
        },
        (item: number) => item.toString()
      )
    }
  }
}
```

## 数据懒加载

通过数据懒加载（LazyForEach组件）从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。

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
| itemGenerator | (item: any) => void   | 是   | 生成子组件的lambda函数，为给定数组项生成一个或多个子组件，单个组件和子组件列表必须括在大括号“{....}”中。 |
| keyGenerator  | (item: any) => string | 否   | 匿名函数，用于键值生成，为给定数组项生成唯一且稳定的键值。当子项在数组中的位置更改时，子项的键值不得更改，当数组中的子项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则LazyForEach中的所有节点都将重建。 |

表2 IDataSource类型说明

| 名称                                                         | 描述                   |
| ------------------------------------------------------------ | ---------------------- |
| totalCount(): number                                         | 获取数据总数。         |
| getData(index: number): any                                  | 获取索引对应的数据。   |
| registerDataChangeListener(listener:DataChangeListener): void | 注册改变数据的控制器。 |
| unregisterDataChangeListener(listener:DataChangeListener): void | 注销改变数据的控制器。 |

表3 DataChangeListener类型说明

| 名称                                                     | 描述                                   |
| -------------------------------------------------------- | -------------------------------------- |
| onDataReloaded(): void                                   | 重新加载所有数据。                     |
| onDataAdded(index: number): void (deprecated)            | 通知组件index的位置有数据添加。        |
| onDataMoved(from: number, to: number): void (deprecated) | 通知组件数据从from的位置移到to的位置。 |
| onDataDeleted(index: number): void (deprecated)          | 通知组件index的位置有数据删除。        |
| onDataChanged(index: number): void (deprecated)          | 通知组件index的位置有数据变化。        |
| onDataAdd(index: number): void 8+                        | 通知组件index的位置有数据添加。        |
| onDataMove(from: number, to: number): void 8+            | 通知组件数据从from的位置移到to的位置。 |
| onDataDelete(index: number): void 8+                     | 通知组件index的位置有数据删除。        |
| onDataChange(index: number): void 8+                     | 通知组件index的位置有数据变化。        |

## 示例

```ts
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
    private dataArray: string[] = ['/path/image0', '/path/image1', '/path/image2', '/path/image3']

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
        List({space: 3}) {
            LazyForEach(this.data, (item: string) => {
                ListItem() {
                    Row() {
                        Image(item).width("30%").height(50)
                        Text(item).fontSize(20).margin({left:10})
                    }.margin({left: 10, right: 10})
                }
                .onClick(()=>{
                    this.data.pushData('/path/image' + this.data.totalCount())
                })
            }, item => item)
        }
    }
}
```

> **说明：**
>
> - 数据懒加载必须在容器组件内使用，且仅有List、Grid以及Swiper组件支持数据的懒加载（即只加载可视部分以及其前后少量数据用于缓冲），其他组件仍然是一次加载所有的数据；
>
> - LazyForEach在每次迭代中，必须且只允许创建一个子组件；
>
> - 生成的子组件必须允许在LazyForEach的父容器组件中；
>
> - 允许LazyForEach包含在if/else条件渲染语句中，不允许LazyForEach中出现if/else条件渲染语句；
>
> - 为了高性能渲染，通过DataChangeListener对象的onDataChange方法来更新UI时，仅itemGenerator中的UI描述的组件内使用了状态变量时，才会触发组件刷新；
>
> - 子项生成器函数的调用顺序不一定和数据源中的数据项相同，在开发过程中不要假设子项生成器和键值生成器函数是否执行以及执行顺序。如下示例可能无法正常工作：
>
>   ```ts
>   LazyForEach(dataSource, 
>           item => Text(`${item.i}. item.data.label`)),
>           item => item.data.id.toString())
>   ```