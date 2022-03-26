# 数据懒加载

开发框架提供数据懒加载（LazyForEach组件）从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。LazyForEach定义如下：


```
LazyForEach(
    dataSource: IDataSource,             // Data source to be iterated 
    itemGenerator: (item: any) => void,  // child component generator
    keyGenerator?: (item: any) => string // (optional) Unique key generator, which is recommended.
): void

interface IDataSource {
    totalCount(): number;                                             // Get total count of data
    getData(index: number): any;                                      // Get single data by index
    registerDataChangeListener(listener: DataChangeListener): void;   // Register listener to listening data changes
    unregisterDataChangeListener(listener: DataChangeListener): void; // Unregister listener
}

interface DataChangeListener {
    onDataReloaded(): void;                      // Called while data reloaded
    onDataAdd(index: number): void;            // Called while single data added
    onDataMove(from: number, to: number): void; // Called while single data moved
    onDataDelete(index: number): void;          // Called while single data deleted
    onDataChange(index: number): void;          // Called while single data changed
}
```


## 接口


### LazyForEach

LazyForEach(dataSource: IDataSource, itemGenerator: (item: any) =&gt; void, keyGenerator?: (item: any) =&gt; string):void

表1 参数说明

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
| -------- | -------- | -------- | -------- | -------- |
| dataSource | IDataSource | 是 | - | 实现IDataSource接口的对象，需要开发者实现相关接口。 |
| itemGenerator | (item:&nbsp;any)&nbsp;=&gt;&nbsp;void | 是 | - | 生成子组件的lambda函数，为给定数组项生成一个或多个子组件，单个组件和子组件列表必须括在大括号“{....}”中。 |
| keyGenerator | (item:&nbsp;any)&nbsp;=&gt;&nbsp;string | 否 | - | 匿名函数，用于键值生成，为给定数组项生成唯一且稳定的键值。当子项在数组中的位置更改时，子项的键值不得更改，当数组中的子项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则LazyForEach中的所有节点都将重建。 |


表2 IDataSource类型说明

| 名称 | 描述 |
| -------- | -------- |
| totalCount():&nbsp;number | 获取数据总数。 |
| getData(index:&nbsp;number):&nbsp;any | 获取索引对应的数据。 |
| registerDataChangeListener(listener:DataChangeListener):&nbsp;void | 注册改变数据的控制器。 |
| unregisterDataChangeListener(listener:DataChangeListener):&nbsp;void | 注销改变数据的控制器。 |


表3 DataChangeListener类型说明

| 名称 | 描述 |
| -------- | -------- |
| onDataReloaded():&nbsp;void | 重新加载所有数据。 |
| onDataAdded(index:&nbsp;number):&nbsp;void <sup>(deprecated) </sup>| 通知组件index的位置有数据添加。 |
| onDataMoved(from:&nbsp;number,&nbsp;to:&nbsp;number):&nbsp;void <sup>(deprecated) </sup>| 通知组件数据从from的位置移到to的位置。 |
| onDataDeleted(index:&nbsp;number):&nbsp;void <sup>(deprecated) </sup>| 通知组件index的位置有数据删除。 |
| onDataChanged(index:&nbsp;number):&nbsp;void <sup>(deprecated) </sup>| 通知组件index的位置有数据变化。 |
| onDataAdd(index:&nbsp;number):&nbsp;void <sup>8+</sup> | 通知组件index的位置有数据添加。 |
| onDataMove(from:&nbsp;number,&nbsp;to:&nbsp;number):&nbsp;void <sup>8+</sup> | 通知组件数据从from的位置移到to的位置。 |
| onDataDelete(index:&nbsp;number):&nbsp;void <sup>8+</sup> | 通知组件index的位置有数据删除。 |
| onDataChange(index:&nbsp;number):&nbsp;void <sup>8+</sup> | 通知组件index的位置有数据变化。 |


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
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
>   ```
>   LazyForEach(dataSource, item => {Text(`${++counter}. item.label`)})
>   ```
> 
>   正确的示例如下：
> 
>   ```
>   LazyForEach(dataSource, 
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
