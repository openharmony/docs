# 循环渲染

开发框架提供循环渲染（ForEach组件）来迭代数组，并为每个数组项创建相应的组件。ForEach定义如下：


```
ForEach(
    arr: any[], // Array to be iterated
    itemGenerator: (item: any, index?: number) => void, // child component generator
    keyGenerator?: (item: any, index?: number) => string // (optional) Unique key generator, which is recommended.
)
```


## ForEach


ForEach(arr: any[],itemGenerator: (item: any, index?: number) =&gt; void, keyGenerator?: (item: any, index?: number) =&gt; string):void


表1 参数说明

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 | 
| -------- | -------- | -------- | -------- | -------- |
| arr | any[] | 是 | - | 必须是数组，允许空数组，空数组场景下不会创建子组件。同时允许设置返回值为数组类型的函数，例如arr.slice(1,&nbsp;3)，设置的函数不得改变包括数组本身在内的任何状态变量，如Array.splice、Array.sort或Array.reverse这些改变原数组的函数。 | 
| itemGenerator | (item:&nbsp;any,&nbsp;index?:&nbsp;number)&nbsp;=&gt;&nbsp;void | 是 | - | 生成子组件的lambda函数，为给定数组项生成一个或多个子组件，单个组件和子组件列表必须括在大括号“{....}”中。 | 
| keyGenerator | (item:&nbsp;any,&nbsp;index?:&nbsp;number)&nbsp;=&gt;&nbsp;string | 否 | - | 匿名参数，用于给定数组项生成唯一且稳定的键值。当子项在数组中的位置更改时，子项的键值不得更改，当数组中的子项被新项替换时，被替换项的键值和新项的键值必须不同。键值生成器的功能是可选的，但是，为了使开发框架能够更好地识别数组更改，提高性能，建议提供。如将数组反向时，如果没有提供键值生成器，则ForEach中的所有节点都将重建。 | 


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 必须在容器组件内使用；
> 
> - 生成的子组件允许在ForEach的父容器组件中，允许子组件生成器函数中包含if/else条件渲染，同时也允许ForEach包含在if/else条件渲染语句中；


## 示例

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
