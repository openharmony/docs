# LazyForEach<a name="EN-US_TOPIC_0000001136122422"></a>

The development framework provides the  **LazyForEach**  component to iterate data as required and create corresponding components during each iteration.  **LazyForEach**  is defined as follows:

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

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   When data is updated through  **onDataChanged**  of  **LazyForEach**, if  **itemGenerator**  contains a fully static view \(that is, the view does not contain state variables\), the view will not be updated.
>-   **LazyForEach**  is used to automatically generate child components from the provided data source.
>-   **LazyForEach**  must be used in the container component. Only the  **<List\>**,  **<Grid\>**, and  **<Swiper\>**  components support on-demand data loading \(that is, only the visible part and a small amount of data before and after the visible part are loaded for caching\). For other components, all data is loaded at a time.
>-   The first parameter must be an object inherited from  **IDataSource**. You need to implement related APIs.
>-   The second parameter is used to generate the lambda function of the child components. It generates one or more child components for a given array item. A single component and its child component list must be contained in the braces \(\{...\}\).
>-   The third parameter is optional and used as an anonymous function for key value generation. It generates a unique and stable key value for a given array item. When the position of a subitem in the array is changed, the key value of the subitem cannot be changed. When a subitem in the array is replaced with a new item, the key value of the current item must be different from the key value of the new item. The key-value generator is optional. However, for performance reasons, it is strongly recommended that the generator be provided, so that the development framework can better identify array changes. If the array is reversed while no key-value generator is provided, all nodes in  **ForEach**  will be rebuilt.
>-   The generated child component must be allowed in the parent container component of  **LazyForEach**, so that  **LazyForEach**  can be included in the  **if/else**  conditional statement.
>-   **LazyForEach**  must create one and only one child component in each iteration.
>-   **ForEach**  cannot be used as a child component of  **LazyForEach**, and  **LazyForEach**  does not support nesting.
>-   The  **if/else**  conditional statement is not allowed in  **LazyForEach**.
>-   The calling sequence of the subitem generator function may be different from that of the data items in the data source. During the development, do not assume whether the subitem generator and key value generator functions are executed and the execution sequence. The following is an example of incorrect usage:
>    ```
>    ForEach(dataSource, item => {Text(`${++counter}. item.label`)})
>    ```
>    Below is an example of correct usage:
>    ```
>    ForEach(dataSource, 
>            item => Text(`${item.i}. item.data.label`)),
>            item => item.data.id.toString())
>    ```

## Example<a name="section155489126613"></a>

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

