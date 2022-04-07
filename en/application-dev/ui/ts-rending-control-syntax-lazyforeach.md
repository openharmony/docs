# LazyForEach


The development framework provides LazyForEach to iterate data from provided data sources and create corresponding components during each iteration. LazyForEach is defined as follows:



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
    onDataAdded(index: number): void;            // Called while single data added
    onDataMoved(from: number, to: number): void; // Called while single data moved
    onDataDeleted(index: number): void;          // Called while single data deleted
    onDataChanged(index: number): void;          // Called while single data changed
}
```


## APIs


### LazyForEach

LazyForEach(dataSource: IDataSource, itemGenerator: (item: any) => void, keyGenerator?: (item: any) => string):void

  Table1 Parameters

| Name | Type | Mandatory | Default Value | Description |
| -------- | -------- | -------- | -------- | -------- |
| dataSource | IDataSource | Yes | - | Object used to implement the IDataSource API. You need to implement related APIs. |
| itemGenerator | (item: any) => void | Yes | - | Used to generate the lambda function of the child components. It generates one or more child components for a given array item. A single component and its child component list must be contained in the braces ({...}) |
| keyGenerator | (item: any) => string | No | - | Used as an anonymous parameter for generating a unique and stable key value for a given array item. When the position of a subitem in the array is changed, the key value of the subitem cannot be changed. When a subitem in the array is replaced with a new item, the key value of the current item must be different from that of the new item. This key-value generator is optional. However, for performance reasons, it is strongly recommended that the key-value generator be provided, so that the development framework can better identify array changes. If the array is reversed while no key-value generator is provided, all nodes in LazyForEach will be rebuilt. |


  Table2 Description of IDataSource

| Name | Description |
| -------- | -------- |
| totalCount(): number | Obtains the total number of data records. |
| getData(index: number): any | Obtains the data corresponding to the specified index. |
| registerDataChangeListener(listener: DataChangeListener): void | Registers the data change listener. |
| unregisterDataChangeListener(listener: DataChangeListener): void | Unregisters the data change listener. |


  Table3 Description of DataChangeListener

| Name | Description | 
| -------- | -------- |
| onDataReloaded(): void | Reloads all data. | 
| onDataAdded(index: number): void | Notifies the component that data is added to the position indicated by the specified index. | 
| onDataMoved(from: number, to: number): void | Notifies the component that data is moved from the from position to the to position. | 
| onDataDeleted(index: number): void | Notifies the component that data is deleted from the position indicated by the specified index. | 
| onDataChanged(index: number): void | Notifies the component that data in the position indicated by the specified index is changed. | 


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**:
> - LazyForEach must be used in the container component. Only the &lt;List&gt;, &lt;Grid&gt;, and &lt;Swiper&gt; components support LazyForEach (that is, only the visible part and a small amount of data before and after the visible part are loaded for caching). For other components, all data is loaded at a time.
> 
> - LazyForEach must create one and only one child component in each iteration.
> 
> - The generated child component must be in the parent container component of LazyForEach.
> 
> - LazyForEach can be included in an if/else conditional statement, but cannot contain an if/else conditional statement.
> 
> - For the purpose of high-performance rendering, when the onDataChanged method of the DataChangeListener object is used to update the UI, the component update is triggered only when the state variable is used in the component specified in the UI description of itemGenerator.
> 
> - The calling sequence of the subitem generator function may be different from that of the data items in the data source. During the development, do not assume whether the subitem generator and key value generator functions are executed and the execution sequence. The following is an example of incorrect usage:
>     
>   ```
>   LazyForEach(dataSource, item => {Text(`${++counter}. item.label`)})
>   ```
> 
>   Below is an example of correct usage:
> 
>     
>   ```
>   LazyForEach(dataSource, 
>           item => Text(`${item.i}. item.data.label`)),
>           item => item.data.id.toString())
>   ```


## Example


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
