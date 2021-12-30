# GridContainer<a name="ZH-CN_TOPIC_0000001192755112"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

纵向排布栅格布局容器，仅在栅格布局场景中使用。

## 权限列表<a name="section53281531154915"></a>

无

## 子组件<a name="section5989144051714"></a>

可以包含子组件。

## 接口<a name="section1643325819470"></a>

GridContainer\(options?: \{ columns?: number | 'auto', sizeType?: SizeType, gutter?: Length, margin?: Length\}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.71%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.469999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.380000000000003%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.82%" id="mcps1.1.6.1.5"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>columns</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.380000000000003%" headers="mcps1.1.6.1.4 "><p>'auto'</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.82%" headers="mcps1.1.6.1.5 "><p>设置当前布局总列数。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>sizeType</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p><a href="#li126518511237">SizeType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.380000000000003%" headers="mcps1.1.6.1.4 "><p>Auto</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.82%" headers="mcps1.1.6.1.5 "><p>选用设备宽度类型。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>gutter</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.380000000000003%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.82%" headers="mcps1.1.6.1.5 "><p>栅格布局列间距。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>margin</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.380000000000003%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.82%" headers="mcps1.1.6.1.5 "><p>栅格布局两侧间距。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li126518511237"></a>SizeType枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>XS</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>最小宽度类型设备。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>SM</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>小宽度类型设备。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>MD</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>中等宽度类型设备。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>LG</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>大宽度类型设备。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Auto</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>根据设备类型进行选择。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section1131219513263"></a>

支持通用属性和Column组件的[属性方法](ts-container-column.md#section358284262918)。

## 事件<a name="section6359753182615"></a>

支持通用事件。

## 示例<a name="section1078035104913"></a>

```
@Entry
@Component
struct GridContainerExample {
  @State sizeType: SizeType = SizeType.XS

  build() {
    Column({ space: 5 }) {
      GridContainer({ columns: 12, sizeType: this.sizeType, gutter: 10, margin: 20 }) {
        Row() {
          Text('1')
            .useSizeType({
              xs: { span: 6, offset: 0 },
              sm: { span: 2, offset: 0 },
              md: { span: 2, offset: 0 },
              lg: { span: 2, offset: 0 }
            })
            .height(50).backgroundColor(0x4682B4).textAlign(TextAlign.Center)
          Text('2')
            .useSizeType({
              xs: { span: 2, offset: 6 },
              sm: { span: 6, offset: 2 },
              md: { span: 2, offset: 2 },
              lg: { span: 2, offset: 2 }
            })
            .height(50).backgroundColor(0x00BFFF).textAlign(TextAlign.Center)
          Text('3')
            .useSizeType({
              xs: { span: 2, offset: 8 },
              sm: { span: 2, offset: 8 },
              md: { span: 6, offset: 4 },
              lg: { span: 2, offset: 4 }
            })
            .height(50).backgroundColor(0x4682B4).textAlign(TextAlign.Center)
          Text('4')
            .useSizeType({
              xs: { span: 2, offset: 10 },
              sm: { span: 2, offset: 10 },
              md: { span: 2, offset: 10 },
              lg: { span: 6, offset: 6 }
            })
            .height(50).backgroundColor(0x00BFFF).textAlign(TextAlign.Center)
        }
      }.width('90%')

      Text('Click Simulate to change the device width').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row() {
        Button('XS')
          .onClick(() => {
            this.sizeType = SizeType.XS
          }).backgroundColor(0x317aff)
        Button('SM')
          .onClick(() => {
            this.sizeType = SizeType.SM
          }).backgroundColor(0x317aff)
        Button('MD')
          .onClick(() => {
            this.sizeType = SizeType.MD
          }).backgroundColor(0x317aff)
        Button('LG')
          .onClick(() => {
            this.sizeType = SizeType.LG
          }).backgroundColor(0x317aff)
      }
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/grid.gif)

