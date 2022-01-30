# 数据懒加载<a name="ZH-CN_TOPIC_0000001136122422"></a>

开发框架提供**数据懒加载**（LazyForEach组件）从提供的数据源中按需迭代数据，并在每次迭代过程中创建相应的组件。**LazyForEach**定义如下：

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

## 接口<a name="section104571819164914"></a>

### LazyForEach<a name="section2886192313102"></a>

LazyForEach\(dataSource: IDataSource, itemGenerator: \(item: any\) =\> void, keyGenerator?: \(item: any\) =\> string\):void

**表 1**  参数说明

<a name="table129678483367"></a>
<table><thead align="left"><tr id="row89671448123612"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.2.6.1.1"><p id="p1096774853618"><a name="p1096774853618"></a><a name="p1096774853618"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="17.32%" id="mcps1.2.6.1.2"><p id="p69676488369"><a name="p69676488369"></a><a name="p69676488369"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.18%" id="mcps1.2.6.1.3"><p id="p1296814810362"><a name="p1296814810362"></a><a name="p1296814810362"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="5.7299999999999995%" id="mcps1.2.6.1.4"><p id="p5968124818361"><a name="p5968124818361"></a><a name="p5968124818361"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="49.66%" id="mcps1.2.6.1.5"><p id="p0968154863617"><a name="p0968154863617"></a><a name="p0968154863617"></a>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row9968144820368"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p id="p1860224817619"><a name="p1860224817619"></a><a name="p1860224817619"></a>dataSource</p>
</td>
<td class="cellrowborder" valign="top" width="17.32%" headers="mcps1.2.6.1.2 "><p id="p39682483368"><a name="p39682483368"></a><a name="p39682483368"></a><a href="#table7164721191320">IDataSource</a></p>
</td>
<td class="cellrowborder" valign="top" width="11.18%" headers="mcps1.2.6.1.3 "><p id="p109681148183618"><a name="p109681148183618"></a><a name="p109681148183618"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="5.7299999999999995%" headers="mcps1.2.6.1.4 "><p id="p19968184814365"><a name="p19968184814365"></a><a name="p19968184814365"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="49.66%" headers="mcps1.2.6.1.5 "><p id="p096894833619"><a name="p096894833619"></a><a name="p096894833619"></a>实现IDataSource接口的对象，需要开发者实现相关接口。</p>
</td>
</tr>
<tr id="row8968124863618"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p id="p522712511279"><a name="p522712511279"></a><a name="p522712511279"></a>itemGenerator</p>
</td>
<td class="cellrowborder" valign="top" width="17.32%" headers="mcps1.2.6.1.2 "><p id="p976144285"><a name="p976144285"></a><a name="p976144285"></a>(item: any) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="11.18%" headers="mcps1.2.6.1.3 "><p id="p2968248103615"><a name="p2968248103615"></a><a name="p2968248103615"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="5.7299999999999995%" headers="mcps1.2.6.1.4 "><p id="p179689488361"><a name="p179689488361"></a><a name="p179689488361"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="49.66%" headers="mcps1.2.6.1.5 "><p id="p1296854817366"><a name="p1296854817366"></a><a name="p1296854817366"></a>生成子组件的lambda函数，为给定数组项生成一个或多个子组件，单个组件和子组件列表必须括在大括号“<strong id="b1361712111814"><a name="b1361712111814"></a><a name="b1361712111814"></a>{....}</strong>”中。</p>
</td>
</tr>
<tr id="row392610546712"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p id="p119275548710"><a name="p119275548710"></a><a name="p119275548710"></a>keyGenerator</p>
</td>
<td class="cellrowborder" valign="top" width="17.32%" headers="mcps1.2.6.1.2 "><p id="p1292711541079"><a name="p1292711541079"></a><a name="p1292711541079"></a>(item: any) =&gt; string</p>
</td>
<td class="cellrowborder" valign="top" width="11.18%" headers="mcps1.2.6.1.3 "><p id="p492717546710"><a name="p492717546710"></a><a name="p492717546710"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="5.7299999999999995%" headers="mcps1.2.6.1.4 "><p id="p16927254973"><a name="p16927254973"></a><a name="p16927254973"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="49.66%" headers="mcps1.2.6.1.5 "><p id="p092795418711"><a name="p092795418711"></a><a name="p092795418711"></a>匿名函数，用于键值生成，为给定数组项生成唯一且稳定的键值。当子项在数组中的位置更改时，子项的键值不得更改，当数组中的子项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则LazyForEach中的所有节点都将重建。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  IDataSource类型说明

<a name="table7164721191320"></a>
<table><thead align="left"><tr id="row316482117139"><th class="cellrowborder" valign="top" width="47.65%" id="mcps1.2.3.1.1"><p id="p15655530161413"><a name="p15655530161413"></a><a name="p15655530161413"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="52.349999999999994%" id="mcps1.2.3.1.2"><p id="p816432113137"><a name="p816432113137"></a><a name="p816432113137"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row216413217134"><td class="cellrowborder" valign="top" width="47.65%" headers="mcps1.2.3.1.1 "><p id="p323916238142"><a name="p323916238142"></a><a name="p323916238142"></a>totalCount(): number</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.2.3.1.2 "><p id="p397813172018"><a name="p397813172018"></a><a name="p397813172018"></a>获取数据总数。</p>
</td>
</tr>
<tr id="row1016442119133"><td class="cellrowborder" valign="top" width="47.65%" headers="mcps1.2.3.1.1 "><p id="p20462047181413"><a name="p20462047181413"></a><a name="p20462047181413"></a>getData(index: number): any</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.2.3.1.2 "><p id="p118759369197"><a name="p118759369197"></a><a name="p118759369197"></a>获取索引对应的数据。</p>
</td>
</tr>
<tr id="row61643218130"><td class="cellrowborder" valign="top" width="47.65%" headers="mcps1.2.3.1.1 "><p id="p19680251214"><a name="p19680251214"></a><a name="p19680251214"></a>registerDataChangeListener(listener: <a href="#table37910215164">DataChangeListener</a>): void</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.2.3.1.2 "><p id="p860484711206"><a name="p860484711206"></a><a name="p860484711206"></a>注册改变数据的控制器。</p>
</td>
</tr>
<tr id="row1450485961410"><td class="cellrowborder" valign="top" width="47.65%" headers="mcps1.2.3.1.1 "><p id="p1750413590148"><a name="p1750413590148"></a><a name="p1750413590148"></a>unregisterDataChangeListener(listener: <a href="#table37910215164">DataChangeListener</a>): void</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.2.3.1.2 "><p id="p4504105914148"><a name="p4504105914148"></a><a name="p4504105914148"></a>注销改变数据的控制器。</p>
</td>
</tr>
</tbody>
</table>

**表 3**  DataChangeListener类型说明

<a name="table37910215164"></a>
<table><thead align="left"><tr id="row167912215162"><th class="cellrowborder" valign="top" width="47.65%" id="mcps1.2.3.1.1"><p id="p879102171616"><a name="p879102171616"></a><a name="p879102171616"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="52.349999999999994%" id="mcps1.2.3.1.2"><p id="p17791172112167"><a name="p17791172112167"></a><a name="p17791172112167"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row14791202116167"><td class="cellrowborder" valign="top" width="47.65%" headers="mcps1.2.3.1.1 "><p id="p18501181761718"><a name="p18501181761718"></a><a name="p18501181761718"></a>onDataReloaded(): void</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.2.3.1.2 "><p id="p17791192181613"><a name="p17791192181613"></a><a name="p17791192181613"></a>重新加载所有数据。</p>
</td>
</tr>
<tr id="row6791202113162"><td class="cellrowborder" valign="top" width="47.65%" headers="mcps1.2.3.1.1 "><p id="p62443559167"><a name="p62443559167"></a><a name="p62443559167"></a>onDataAdded(index: number): void</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.2.3.1.2 "><p id="p14791192120160"><a name="p14791192120160"></a><a name="p14791192120160"></a>通知组件index的位置有数据添加。</p>
</td>
</tr>
<tr id="row1879102111612"><td class="cellrowborder" valign="top" width="47.65%" headers="mcps1.2.3.1.1 "><p id="p1845623111716"><a name="p1845623111716"></a><a name="p1845623111716"></a>onDataMoved(from: number, to: number): void</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.2.3.1.2 "><p id="p1579119215163"><a name="p1579119215163"></a><a name="p1579119215163"></a>通知组件数据从from的位置移到to的位置。</p>
</td>
</tr>
<tr id="row1379192116163"><td class="cellrowborder" valign="top" width="47.65%" headers="mcps1.2.3.1.1 "><p id="p187812571171"><a name="p187812571171"></a><a name="p187812571171"></a>onDataDeleted(index: number): void</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.2.3.1.2 "><p id="p13791102121616"><a name="p13791102121616"></a><a name="p13791102121616"></a>通知组件index的位置有数据删除。</p>
</td>
</tr>
<tr id="row924750111810"><td class="cellrowborder" valign="top" width="47.65%" headers="mcps1.2.3.1.1 "><p id="p8247190201816"><a name="p8247190201816"></a><a name="p8247190201816"></a>onDataChanged(index: number): void</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.2.3.1.2 "><p id="p1247110141818"><a name="p1247110141818"></a><a name="p1247110141818"></a>通知组件index的位置有数据变化。</p>
</td>
</tr>
</tbody>
</table>

>![icon-note.gif](public_sys-resources/icon-note.gif) **说明：** 
>-   数据懒加载必须在容器组件内使用，且仅有List、Grid以及Swiper组件支持数据的懒加载（即只加载可视部分以及其前后少量数据用于缓冲），其他组件仍然是一次加载所有的数据；
>-   **LazyForEach**在每次迭代中，必须且只允许创建一个子组件；
>-   生成的子组件必须允许在**LazyForEach**的父容器组件中；
>-   允许**LazyForEach**包含在**if/else**条件渲染语句中，不允许**LazyForEach**中出现**if/else**条件渲染语句；
>-   为了高性能渲染，通过DataChangeListener对象的onDataChanged方法来更新UI时，仅itemGenerator中的UI描述的组件内使用了状态变量时，才会触发组件刷新；
>-   子项生成器函数的调用顺序不一定和数据源中的数据项相同，在开发过程中不要假设子项生成器和键值生成器函数是否执行以及执行顺序。如下示例可能无法正常工作：
>    ```
>    LazyForEach(dataSource, item => {Text(`${++counter}. item.label`)})
>    ```
>    正确的示例如下：
>    ```
>    LazyForEach(dataSource, 
>            item => Text(`${item.i}. item.data.label`)),
>            item => item.data.id.toString())
>    ```

## 示例<a name="section155489126613"></a>

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

