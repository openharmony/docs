# Scroll<a name="ZH-CN_TOPIC_0000001192595158"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

可滚动的容器组件，当子组件的布局尺寸超过父组件的视口时，内容可以滚动。

## 权限列表<a name="section1073795814133"></a>

无

## 子组件<a name="section152511941148"></a>

支持单个子组件。

## 接口<a name="section13412231148"></a>

Scroll\(scroller?: Scroller\)

## 属性<a name="section186841370012"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.81188118811881%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="18.801880188018803%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.861486148614864%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="47.52475247524753%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.5.1.1 "><p>scrollable</p>
</td>
<td class="cellrowborder" valign="top" width="18.801880188018803%" headers="mcps1.1.5.1.2 "><p><a href="#li1464044171913">ScrollDirection</a></p>
</td>
<td class="cellrowborder" valign="top" width="14.861486148614864%" headers="mcps1.1.5.1.3 "><p>Vertical</p>
</td>
<td class="cellrowborder" valign="top" width="47.52475247524753%" headers="mcps1.1.5.1.4 "><p>设置滚动方法。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.5.1.1 "><p>scrollBar</p>
</td>
<td class="cellrowborder" valign="top" width="18.801880188018803%" headers="mcps1.1.5.1.2 "><p><a href="ts-appendix-enums.md#section122549529179">BarState</a></p>
</td>
<td class="cellrowborder" valign="top" width="14.861486148614864%" headers="mcps1.1.5.1.3 "><p>Auto</p>
</td>
<td class="cellrowborder" valign="top" width="47.52475247524753%" headers="mcps1.1.5.1.4 "><p>设置滚动条状态。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.5.1.1 "><p>scrollBarColor</p>
</td>
<td class="cellrowborder" valign="top" width="18.801880188018803%" headers="mcps1.1.5.1.2 "><p>Color</p>
</td>
<td class="cellrowborder" valign="top" width="14.861486148614864%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.52475247524753%" headers="mcps1.1.5.1.4 "><p>设置滚动条的颜色。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.5.1.1 "><p>scrollBarWidth</p>
</td>
<td class="cellrowborder" valign="top" width="18.801880188018803%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="14.861486148614864%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.52475247524753%" headers="mcps1.1.5.1.4 "><p>设置滚动条的宽度。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li1464044171913"></a>ScrollDirection枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Horizontal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>仅支持水平方向滚动。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Vertical</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>仅支持竖直方向滚动。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>不可滚动。</p>
    </td>
    </tr>
    </tbody>
    </table>


## Scroller<a name="section123902548458"></a>

可滚动容器组件的控制器，可以将此组件绑定至容器组件，然后通过它控制容器组件的滚动，目前支持绑定到List和Scroll组件上。

### 创建对象<a name="section1241383014362"></a>

```
scroller: Scroller = new Scroller()
```

### scroller.scrollTo<a name="section15413203010365"></a>

scrollTo\(value: \{ xOffset: number | string, yOffset: number | string, animation?: \{ duration: number, curve: Curve \} \}\): void

滑动到指定位置。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.43%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.08%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>xOffset</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.43%" headers="mcps1.1.6.1.2 "><p>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.08%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>水平滑动偏移。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>yOffset</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.43%" headers="mcps1.1.6.1.2 "><p>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.08%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>竖直滑动偏移。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>animation</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.43%" headers="mcps1.1.6.1.2 "><p>{</p>
    <p>duration: number,</p>
    <p>curve: <a href="ts-animatorproperty.md#li16621545614">Curve</a> | CubicBezier | SpringCurve</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.08%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>动画配置：</p>
    <ul><li>duration: 滚动时长设置。</li><li>curve: 滚动曲线设置。</li></ul>
    </td>
    </tr>
    </tbody>
    </table>


### scroller.scrollEdge<a name="section1441583018367"></a>

scrollEdge\(value: Edge\): void

滚动到容器边缘。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>Edge</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>滚动到的边缘位置。</p>
    </td>
    </tr>
    </tbody>
    </table>


### scroller.scrollPage<a name="section2416163018368"></a>

scrollPage\(value: \{ next: boolean \}\): void

滚动到下一页或者上一页。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>next</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>是否向下翻页。true表示向下翻页，false表示向上翻页。</p>
    </td>
    </tr>
    </tbody>
    </table>


### scroller.currentOffset<a name="section041711305362"></a>

scroller.currentOffset\(\): Object

返回当前的滚动偏移量。

-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>{</p>
    <p>xOffset: number,</p>
    <p>yOffset: number</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>xOffset: 水平滑动偏移;</p>
    <p>yOffset: 竖直滑动偏移。</p>
    </td>
    </tr>
    </tbody>
    </table>


### scroller.scrollToIndex<a name="section10417103010368"></a>

scroller.scrollToIndex\(value: number\): void

滑动到指定Index。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>仅支持list组件。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>要滑动到的列表项在列表中的索引值。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section142174333711"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onScroll(xOffset: number, yOffset: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>滚动事件回调, 返回滚动时水平、竖直方向偏移量。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onScrollEdge(side: Edge) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>滚动到边缘事件回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onScrollEnd() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>滚动停止事件回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section11271205310156"></a>

```
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller()
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item) => {
            Text(item.toString())
              .width('90%').height(150).backgroundColor(0xFFFFFF)
              .borderRadius(15).fontSize(16).textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, item => item)
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical).scrollBar(BarState.On)
      .scrollBarColor(Color.Gray).scrollBarWidth(30)
      .onScroll((xOffset: number, yOffset: number) => {
        console.info(xOffset + ' ' + yOffset)
      })
      .onScrollEdge((side: Edge) => {
        console.info('To the edge')
      })
      .onScrollEnd(() => {
        console.info('Scroll Stop')
      })

      Button('scroll 100')
        .onClick(() => { // 点击后下滑100.0距离
          this.scroller.scrollTo({ xOffset: 0, yOffset: this.scroller.currentOffset().yOffset + 100 })
        })
        .margin({ top: 10, left: 20 })
      Button('back top')
        .onClick(() => { // 点击后回到顶部
          this.scroller.scrollEdge(Edge.Top)
        })
        .margin({ top: 60, left: 20 })
      Button('next page')
        .onClick(() => { // 点击后下滑到底部
          this.scroller.scrollPage({ next: true })
        })
        .margin({ top: 110, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

![](figures/scroll.gif)

