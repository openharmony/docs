# GridCol

栅格子组件，必须作为栅格容器组件([GridRow](ts-container-gridrow.md))的子组件使用。

>  **说明：**
>
> 该组件从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。  

## 子组件

可以包含单个子组件。
## 接口

GridCol(option?:{span?: number | GridColColumnOption, offset?: number | GridColColumnOption, order?: number | GridColColumnOption})

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名 | 类型                                                  | 必填 | 说明                                                         |
| ------ | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| span   | number \| [GridColColumnOption](#gridcolcolumnoption) | 否   | 占用列数。span为0表示该元素不参与布局计算，即不会被渲染。<br/>默认值：1。 |
| offset | number \| [GridColColumnOption](#gridcolcolumnoption) | 否   | 相对于前一个栅格子组件偏移的列数。<br/>默认值：0。           |
| order  | number \| [GridColColumnOption](#gridcolcolumnoption) | 否   | 元素的序号，根据栅格子组件的序号，从小到大对栅格子组件做排序。<br/>默认值：0。 |

## 属性

| 参数名 | 类型                          | 必填 | 说明                                                         |
| ------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| span   | number \| GridColColumnOption | 否   | 占用列数。span为0，意味着该元素不参与布局计算，即不会被渲染。<br/>默认值：1。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| gridColOffset | number \| GridColColumnOption | 否   | 相对于前一个栅格子组件偏移的列数。<br/>默认值：0。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| order  | number \| GridColColumnOption | 否   | 元素的序号，根据栅格子组件的序号，从小到大对栅格子组件做排序。<br/>默认值：0。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |

## GridColColumnOption

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 参数名   | 参数类型   | 必填   | 参数描述                                     |
| ----- | ------ | ---- | ---------------------------------------- |
| xs  | number | 否    | 最小宽度类型设备。    |
| sm  | number | 否    | 小宽度类型设备。      |
| md  | number | 否    | 中等宽度类型设备。    |
| lg  | number | 否    | 大宽度类型设备。      |
| xl  | number | 否    | 特大宽度类型设备。    |
| xxl | number | 否    | 超大宽度类型设备。    |

`span`、`offset`、`order`属性按照`xs`、`sm`、`md`、`lg`、`xl`、`xxl`的顺序具有“继承性”，未设置值的断点将会从前一个断点取值。

|参数\断点 |xs|sm|md|lg|xl|xxl|
|---|---|---|---|---|---|---|
|span   |2  |2  |3  |3  |4  |4  |
|offset |2  |2  |3  |5  |5  |5  |
|order  |20 |20 |20 |3  |3  |3  |

## 示例
请参考栅格容器示例代码([GridRow](ts-container-gridrow.md#示例))