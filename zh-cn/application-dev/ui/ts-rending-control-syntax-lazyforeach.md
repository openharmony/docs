# 数据懒加载

开发框架提供**LazyForEach**组件按需迭代数据，并在每次迭代过程中创建相应的组件。**LazyForEach**定义如下：


```
interface DataChangeListener {
    onDataReloaded(): void;                      // Called while data reloaded
    onDataAdded(index: number): void;            // Called while single data added
    onDataMoved(from: number, to: number): void; // Called while single data moved
    onDataDeleted(index: number): void;          // Called while single data deleted
    onDataChanged(index: number): void;          // Called while single data changed
}
interface IDataSource {
    totalCount(): number;                                             // Get total count of data
    getData(index: number): any;                                      // Get single data by index
    registerDataChangeListener(listener: DataChangeListener): void;   // Register listener to listening data changes
    unregisterDataChangeListener(listener: DataChangeListener): void; // Unregister listener
}
LazyForEach(
    dataSource: IDataSource,             // Data source to be iterated 
    itemGenerator: (item: any) => void,  // child component generator
    keyGenerator?: (item: any) => string // (optional) Unique key generator, which is recommended.
): void
```


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 通过LazyForEach的onDataChanged更新数据时，如果itemGenerator里面包含一个全静态（此view中不包含状态变量）的view，此view将不会更新
> 
> - 数据懒加载组件使用LazyForEach从提供的数据源中自动生成子组件；
> 
> - 必须在容器组件内使用，且仅有List、Grid以及Swiper组件支持数据的按需加载（即只加载可视部分以及其前后少量数据用于缓冲），其他组件仍然是一次加载所有数据；
> 
> - 第一个参数必须是继承自IDataSource的对象，需要开发者实现相关接口；
> 
> - 第二个参数用于生成子组件的lambda函数。它为给定数组项生成一个或多个子组件。单个组件和子组件列表必须括在大括号“**{....}**”中；
> 
> - 可选的第三个参数是用于键值生成的匿名函数。它为给定数组项生成唯一且稳定的键值。当子项在数组中的位置更改时，子项的键值不得更改，当数组中的子项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的。但是，出于性能原因，强烈建议提供，这使开发框架能够更好地识别数组更改。如单击进行数组反向时，如果没有提供键值生成器，则ForEach中的所有节点都将重建。
> 
> - 生成的子组件必须允许在**LazyForEach**的父容器组件中，允许**LazyForEach**包含在**if/else**条件渲染语句中。
> 
> - **LazyForEach**在每次迭代中，必须创建一个且只允许创建一个子组件。
> 
> - **ForEach**不允许作为**LazyForEach**的子组件，**LazyForEach**也不支持嵌套。
> 
> - **LazyForEach**中不允许出现**if/else**条件渲染语句。
> 
> - 子项生成器函数的调用顺序不一定和数据源中的数据项相同，在开发过程中不要假设子项生成器和键值生成器函数是否执行以及执行顺序。如下示例可能无法正常工作：
>   ```
>   ForEach(dataSource, item => {Text(`${++counter}. item.label`)})
>   ```
> 
>   正确的示例如下：
> 
>   ```
>   ForEach(dataSource, 
>           item => Text(`${item.i}. item.data.label`)),
>           item => item.data.id.toString())
>   ```


## 示例

```
// Basic implementation of IDataSource to handle data listener
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
            listener.onDataAdded(index)
        })
    }
    notifyDataChange(index: number): void {
        this.listeners.forEach(listener => {
            listener.onDataChanged(index)
        })
    }
    notifyDataDelete(index: number): void {
        this.listeners.forEach(listener => {
            listener.onDataDeleted(index)
        })
    }
    notifyDataMove(from: number, to: number): void {
        this.listeners.forEach(listener => {
            listener.onDataMoved(from, to)
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
