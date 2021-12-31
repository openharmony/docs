# List<a name="ZH-CN_TOPIC_0000001237555113"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

列表包含一系列相同宽度的列表项。适合连续、多行呈现同类数据，例如图片和文本。

## 权限列表<a name="section0178213104516"></a>

无

## 子组件<a name="section872315253456"></a>

包含[ListItem](ts-container-listitem.md)子组件。

## 接口<a name="section297911264713"></a>

List\(value:\{space?: number, initialIndex?: number\}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.959999999999999%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.04%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.88%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>space</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>列表项间距。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>initialIndex</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>设置当前List初次加载时视口起始位置显示的item，即显示第一个item，如设置的序号超过了最后一个item的序号，则设置不生效。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section10148192384712"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.08%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="25.46%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="15.790000000000001%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="44.67%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p>listDirection</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p><a href="ts-appendix-enums.md#section1397918486200">Axis</a></p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p>Vertical</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p>设置List组件排列方向参照<a href="#li7849892417">Axis</a>枚举说明。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p>divider</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>strokeWidth: Length,</p>
<p>color?:Color,</p>
<p>startMargin?: Length,</p>
<p>endMargin?: Length</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p>用于设置ListItem分割线样式，默认无分割线。</p>
<p>strokeWidth: 分割线的线宽。</p>
<p>color: 分割线的颜色。</p>
<p>startMargin： 分割线距离列表侧边起始端的距离。</p>
<p>endMargin: 分割线距离列表侧边结束端的距离。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p>editMode</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p>声明当前List组件是否处于可编辑模式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p>edgeEffect</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p><a href="#li13407161352416">EdgeEffect</a></p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p>Spring</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p>滑动效果，目前支持的滑动效果参见<a href="#li13407161352416">EdgeEffect</a>的枚举说明。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="14.08%" headers="mcps1.1.5.1.1 "><p>chainAnimation</p>
</td>
<td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="15.790000000000001%" headers="mcps1.1.5.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="44.67%" headers="mcps1.1.5.1.4 "><p>用于设置当前list是否启用链式联动动效，开启后列表滑动以及顶部和底部拖拽时会有链式联动的效果。链式联动效果：list内的list-item间隔一定距离，在基本的滑动交互行为下，主动对象驱动从动对象进行联动，驱动效果遵循弹簧物理动效。</p>
<ul><li>false：不启用链式联动。</li><li>true：启用链式联动。</li></ul>
</td>
</tr>
</tbody>
</table>

-   <a name="li13407161352416"></a>EdgeEffect枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Spring</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>弹性物理动效，滑动到边缘后可以根据初始速度或通过触摸事件继续滑动一段距离，松手后回弹。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>滑动到边缘后无效果。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section5672149135016"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="52.07000000000001%" id="mcps1.1.3.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="47.93%" id="mcps1.1.3.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p>onItemDelete(index: number) =&gt; boolean</p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p>列表项删除时触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p>onScrollIndex(firstIndex: number, lastIndex: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p>当前列表显示的起始位置和终止位置发生变化时触发。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p>onItemDragEnter(callback: (event: <a href="#li2640114814351">ItemDragInfo</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p>绑定后，拖拽在可放置组件范围内移动时，触发回调。</p>
<ul><li>itemIndex: 当前被拖拽的ListItem原本的索引。</li><li>insertIndex: 拖动当前ListItem插入List后的索引。</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>当监听了onDrop事件时，此事件才有效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p>onItemDragMove(callback: (event: <a href="#li2640114814351">ItemDragInfo</a>, itemIndex: number, insertIndex: number) =&gt; void)</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p>绑定后，拖拽在可放置组件范围内移动时，触发回调。</p>
<ul><li>itemIndex: 当前被拖拽的ListItem原本的索引。</li><li>insertIndex: 拖动当前ListItem插入List后的索引。</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>当监听了onDrop事件时，此事件才有效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p>onItemDragLeave(callback: (event: <a href="#li2640114814351">ItemDragInfo</a>, itemIndex: number) =&gt; void)</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p>绑定后，拖拽离开组件范围内时，触发回调。</p>
<ul><li>itemIndex: 当前被拖拽的ListItem原本的索引。</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>当监听了onDrop事件时，此事件才有效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p>onItemDragStart(callback: (event: <a href="#li2640114814351">ItemDragInfo</a>, itemIndex: number)  =&gt; <a href="../../toctopics/zh-cn_topic_0000001237475069.md#section2538145016250">CustomBuilder</a>)</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p>绑定后，第一次拖拽ListItem时，触发回调。</p>
<ul><li>itemIndex: 当前被拖拽的ListItem原本的索引。</li><li>返回值：被拖拽ListItem的浮动UI布局。</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>当监听了onDrop事件时，此事件才有效。</p>
</div></div>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="52.07000000000001%" headers="mcps1.1.3.1.1 "><p>onItemDrop(callback: (event: <a href="#li2640114814351">ItemDragInfo</a>, itemIndex: number, insertIndex: number，isSuccess: boolean) =&gt; void)</p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="47.93%" headers="mcps1.1.3.1.2 "><p>绑定此事件的组件可作为拖拽释放目标，当在本组件范围内停止拖拽行为时，触发此回调。</p>
<ul><li>itemIndex: 当前被拖拽的ListItem原本的索引。</li><li>insertIndex: 拖动当前ListItem插入List后的索引。</li><li>isSuccess: 拖拽释放时插入是否成功。</li></ul>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>当监听了onDrop事件时，此事件才有效。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>List使能可编辑模式需配合onItemDelete事件和ListItem的editable属性，即可编辑模式实现删除列表项功能，需满足以下条件：
>-   editMode属性设置为true。
>-   绑定onItemDelete事件，且事件回调返回true。
>-   ListItem的editable属性设置为true。
>实现ListItem拖拽，需满足以下条件：
>-   editMode属性设置为true。
>-   绑定onItemDragStart事件，且事件回调中返回浮动UI布局。

-   <a name="li2640114814351"></a>ItemDragInfo对象说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.09%" id="mcps1.1.4.1.1"><p>属性名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.22%" id="mcps1.1.4.1.2"><p>属性类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.69%" id="mcps1.1.4.1.3"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.22%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.69%" headers="mcps1.1.4.1.3 "><p>拖拽点的横坐标。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.22%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.69%" headers="mcps1.1.4.1.3 "><p>拖拽点的纵坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section02653368513"></a>

```
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column() {
        List({ space: 20, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical) // 排列方向
        .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // 每行之间的分界线
        .edgeEffect(EdgeEffect.None) // 滑动到边缘无效果
        .chainAnimation(false) // 联动特效关闭
        .onScrollIndex((firstIndex: number, lastIndex: number) => {
          console.info('first' + firstIndex)
          console.info('last' + lastIndex)
        })
        .editMode(this.editFlag)
        .onItemDelete((index: number) => {
          console.info(this.arr[index] + 'Delete')
          this.arr.splice(index, 1)
          console.info(JSON.stringify(this.arr))
          this.editFlag = false
          return true
        }).width('90%')
      }.width('100%')

      Button('edit list')
        .onClick(() => {
          this.editFlag = !this.editFlag
        }).margin({ top: 5, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![](figures/list.gif)

```
@Entry
@Component
struct DragListExample {
  @State number1: string[] = ['0', '1', '2']
  @State number2: string[] = ['one', 'two', 'three']
  @State text: string = ''
  @State bool1: boolean = false
  @State bool2: boolean = false

  @Builder pixelMapBuilder() {
    Text('-1')
      .width('100%').height(100).fontSize(16)
      .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
  }

  build() {
    Column() {
      List() {
        ForEach(this.number1, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xF666FF)
          }
        }, item => item)
      }
      .editMode(true)
      .width('90%').divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 })
      .onItemDelete((index: number) => {
        console.info(this.Number1[index] + 'Delete')
        this.Number1.splice(index, 1)
        console.info(JSON.stringify(this.Number1))
        return true
      })
      .onItemDragStart((event: ItemDragInfo, itemIndex: number) => {
        this.bool1 = true
        this.text = this.number1[itemIndex]
        console.log("List1 onItemDragStart, itemIndex:" + itemIndex + ",  ItemDragInfo:"+`${JSON.stringify(event)}`)
        return this.pixelMapBuilder
      })
      .onItemDragEnter((event: ItemDragInfo) => {
        console.log("List1 onItemDragEnter")
      })
      .onItemDragMove((event: ItemDragInfo, itemIndex: number, insertIndex: number) => {
        console.log("List1 onItemDragMove, itemIndex:" + itemIndex + ", insertIndex:" + insertIndex)
      })
      .onItemDragLeave((event: ItemDragInfo, itemIndex: number) => {
        console.log("List1 onItemDragLeave, itemIndex:" + itemIndex)
      })
      .onItemDrop((event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => {
        if (isSuccess) {
          if (this.bool2) {
            this.number2.splice(itemIndex, 1)
            this.number1.splice(insertIndex, 0, this.text)
            this.bool1 = false
            this.bool2 = false
          } else if (this.bool1) {
            this.number1.splice(itemIndex, 1)
            this.number1.splice(insertIndex, 0, this.text)
            this.bool1 = false
            this.bool2 = false
          }
        }
        console.log("List1 onItemDrop, itemIndex:" + itemIndex + ", insertIndex:" + insertIndex + ", isSuccess:" + isSuccess)
      })
      Divider().strokeWidth(5).color(0x2788D9).lineCap(LineCapStyle.Round).margin(20)
      List() {
        ForEach(this.Number2, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFF888)
          }
        }, item => item)
      }
      .edgeEffect(EdgeEffect.None)
      .width('90%')
      .editMode(true)
      .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 })
      .onItemDragStart((event: ItemDragInfo, itemIndex: number) => {
        this.bool2 = true
        this.text = this.number2[itemIndex]
        console.log("List2 onItemDragStart, itemIndex:" + itemIndex)
        return this.pixelMapBuilder
      })
      .onItemDragEnter((event: ItemDragInfo) => {
        console.log("List2 onItemDragEnter")
      })
      .onItemDragMove((event: ItemDragInfo, itemIndex: number, insertIndex: number) => {
        console.log("List2 onItemDragMove, itemIndex:" + itemIndex + ", insertIndex:" + insertIndex)
      })
      .onItemDragLeave((event: ItemDragInfo, itemIndex: number) => {
        console.log("List2 onItemDragLeave, itemIndex:" + itemIndex)
      })
      .onItemDrop((event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => {
        if (isSuccess) {
          if (this.bool1) {
            this.number1.splice(itemIndex, 1)
            this.number2.splice(insertIndex, 0, this.text)
            this.bool1 = false
            this.bool2 = false
          } else if (this.bool2) {
            this.number2.splice(itemIndex, 1)
            this.number2.splice(insertIndex, 0, this.text)
            this.bool1 = false
            this.bool2 = false
          }
        }
        console.log("List2 onItemDrop, itemIndex:" + itemIndex + ", insertIndex:" + insertIndex + ", isSuccess:" + isSuccess)
      })
    }.width('100%').height('100%').backgroundColor(0xE600000).padding({ top: 25 })
  }
}
```

![](figures/GIF-4.gif)

