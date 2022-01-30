# 循环渲染<a name="ZH-CN_TOPIC_0000001110788996"></a>

开发框架提供**循环渲染（**ForEach组件）来迭代数组，并为每个数组项创建相应的组件。**ForEach**定义如下：

```
ForEach(
    arr: any[], // Array to be iterated
    itemGenerator: (item: any, index?: number) => void, // child component generator
    keyGenerator?: (item: any, index?: number) => string // (optional) Unique key generator, which is recommended.
)
```

## ForEach<a name="section104571819164914"></a>

ForEach\(arr: any\[\],itemGenerator: \(item: any, index?: number\) =\> void, keyGenerator?: \(item: any, index?: number\) =\> string\):void

**表 1**  参数说明

<a name="table129678483367"></a>
<table><thead align="left"><tr id="row89671448123612"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.2.6.1.1"><p id="p1096774853618"><a name="p1096774853618"></a><a name="p1096774853618"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="26.77%" id="mcps1.2.6.1.2"><p id="p69676488369"><a name="p69676488369"></a><a name="p69676488369"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="5.99%" id="mcps1.2.6.1.3"><p id="p1296814810362"><a name="p1296814810362"></a><a name="p1296814810362"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="8.92%" id="mcps1.2.6.1.4"><p id="p5968124818361"><a name="p5968124818361"></a><a name="p5968124818361"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="42.21%" id="mcps1.2.6.1.5"><p id="p0968154863617"><a name="p0968154863617"></a><a name="p0968154863617"></a>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row9968144820368"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p id="p1860224817619"><a name="p1860224817619"></a><a name="p1860224817619"></a>arr</p>
</td>
<td class="cellrowborder" valign="top" width="26.77%" headers="mcps1.2.6.1.2 "><p id="p165351263710"><a name="p165351263710"></a><a name="p165351263710"></a>any[]</p>
</td>
<td class="cellrowborder" valign="top" width="5.99%" headers="mcps1.2.6.1.3 "><p id="p109681148183618"><a name="p109681148183618"></a><a name="p109681148183618"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.92%" headers="mcps1.2.6.1.4 "><p id="p19968184814365"><a name="p19968184814365"></a><a name="p19968184814365"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p id="p6889586376"><a name="p6889586376"></a><a name="p6889586376"></a>必须是数组，允许空数组，空数组场景下不会创建子组件。同时允许设置返回值为数组类型的函数，例如<strong id="b78819581376"><a name="b78819581376"></a><a name="b78819581376"></a>arr.slice(1, 3)</strong>，设置的函数不得改变包括数组本身在内的任何状态变量，如<strong id="b1888185873717"><a name="b1888185873717"></a><a name="b1888185873717"></a>Array.splice</strong>、<strong id="b488125811376"><a name="b488125811376"></a><a name="b488125811376"></a>Array.sort</strong>或<strong id="b1388175833715"><a name="b1388175833715"></a><a name="b1388175833715"></a>Array.reverse</strong>这些改变原数组的函数。</p>
</td>
</tr>
<tr id="row8968124863618"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p id="p522712511279"><a name="p522712511279"></a><a name="p522712511279"></a>itemGenerator</p>
</td>
<td class="cellrowborder" valign="top" width="26.77%" headers="mcps1.2.6.1.2 "><p id="p976144285"><a name="p976144285"></a><a name="p976144285"></a>(item: any, index?: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="5.99%" headers="mcps1.2.6.1.3 "><p id="p2968248103615"><a name="p2968248103615"></a><a name="p2968248103615"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.92%" headers="mcps1.2.6.1.4 "><p id="p179689488361"><a name="p179689488361"></a><a name="p179689488361"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p id="p1296854817366"><a name="p1296854817366"></a><a name="p1296854817366"></a>生成子组件的lambda函数，为给定数组项生成一个或多个子组件，单个组件和子组件列表必须括在大括号“<strong id="b1361712111814"><a name="b1361712111814"></a><a name="b1361712111814"></a>{....}</strong>”中。</p>
</td>
</tr>
<tr id="row392610546712"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.2.6.1.1 "><p id="p119275548710"><a name="p119275548710"></a><a name="p119275548710"></a>keyGenerator</p>
</td>
<td class="cellrowborder" valign="top" width="26.77%" headers="mcps1.2.6.1.2 "><p id="p1292711541079"><a name="p1292711541079"></a><a name="p1292711541079"></a>(item: any, index?: number) =&gt; string</p>
</td>
<td class="cellrowborder" valign="top" width="5.99%" headers="mcps1.2.6.1.3 "><p id="p492717546710"><a name="p492717546710"></a><a name="p492717546710"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="8.92%" headers="mcps1.2.6.1.4 "><p id="p16927254973"><a name="p16927254973"></a><a name="p16927254973"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.2.6.1.5 "><p id="p165501631133814"><a name="p165501631133814"></a><a name="p165501631133814"></a>匿名参数，用于给定数组项生成唯一且稳定的键值。当子项在数组中的位置更改时，子项的键值不得更改，当数组中的子项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则ForEach中的所有节点都将重建</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   必须在容器组件内使用；
>-   生成的子组件允许在**ForEach**的父容器组件中，允许子组件生成器函数中包含**if/else**条件渲染，同时也允许**ForEach**包含在**if/else**条件渲染语句中；
>-   子项生成器函数的调用顺序不一定和数组中的数据项相同，在开发过程中不要假设子项生成器和键值生成器函数是否执行以及执行顺序。如下示例可能无法正常工作：
>    ```
>    ForEach(anArray, item => {Text(`${++counter}. item.label`)})
>    ```
>    正确的示例如下：
>    ```
>    ForEach(anArray.map((item1, index1) => { return { i: index1 + 1, data: item1 }; }), 
>            item => Text(`${item.i}. item.data.label`),
>            item => item.data.id.toString())
>    ```

## 示例<a name="section155489126613"></a>

简单类型数组示例：

```
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

            ForEach(this.arr,                         // Parameter 1: array to be iterated
                    (item: number) => {               // Parameter 2: item generator
                        Text(`item value: ${item}`)
                        Divider()
                    },
                    (item: number) => item.toString() // Parameter 3: unique key generator, which is optional but recommended.
            )
        }
    }
}
```

复杂类型数组示例：

```
class Month {
  year: number
  month: number
  days: Array<number>

  constructor(year, month, days) {
    this.year = year;
    this.month = month;
    this.days = days;
  }
}

@Entry
@Component
struct Calendar1 {
// simulate with 6 months
  @State calendar: Month[] = [
    new Month(2020, 1, [...Array(31).keys()]),
    new Month(2020, 2, [...Array(28).keys()]),
    new Month(2020, 3, [...Array(31).keys()]),
    new Month(2020, 4, [...Array(30).keys()]),
    new Month(2020, 5, [...Array(31).keys()]),
    new Month(2020, 6, [...Array(30).keys()]),
  ]

  build() {
    Column() {
      Button('next month')
        .onClick(() => {
          this.calendar.shift()
          this.calendar.push({
            year: 2020,
            month: 7,
            days: [...Array(31)
              .keys()]
          })
        })
      ForEach(this.calendar,
        (item: Month) => {
          Text('month:' + item.month)
            .fontSize(30)
            .padding(20)
          Grid() {
            ForEach(item.days,
              (day: number) => {
                GridItem() {
                  Text((day + 1).toString())
                    .fontSize(30)
                }
              },
              (day: number) => day.toString())
          }
          .columnsTemplate('1fr 1fr 1fr 1fr 1fr 1fr 1fr')
          .rowsGap(20)
        },
        // field is used together with year and month as the unique ID of the month.
        (item: Month) => (item.year * 12 + item.month).toString())
    }
  }
}
```

