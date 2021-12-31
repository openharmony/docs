# ListItem<a name="ZH-CN_TOPIC_0000001192595148"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

用来展示列表具体item，宽度默认充满List组件，必须配合List来使用。

## 权限列表<a name="section19446161017538"></a>

无

## 子组件<a name="section3767111810531"></a>

可以包含单个子组件。

## 接口<a name="section36922294535"></a>

ListItem\(\)

## 属性<a name="section83861522436"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.32%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.41%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.1 "><p>sticky</p>
</td>
<td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p><a href="#li66453411182">Sticky</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.3 "><p>None</p>
</td>
<td class="cellrowborder" valign="top" width="59.41%" headers="mcps1.1.5.1.4 "><p>设置ListItem吸顶效果，参见Sticky枚举描述。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.5.1.1 "><p>editable</p>
</td>
<td class="cellrowborder" valign="top" width="14.32%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="59.41%" headers="mcps1.1.5.1.4 "><p>声明当前ListItem元素是否可编辑，进入编辑模式后可删除。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li66453411182"></a>Sticky枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>无吸顶效果。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>当前item吸顶，滑动消失。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section559995265311"></a>

```
@Entry
@Component
struct ListItemExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ListItem() {
          Text('sticky:Normal , click me edit list')
            .width('100%').height(40).fontSize(12).fontColor(0xFFFFFF)
            .textAlign(TextAlign.Center).backgroundColor(0x696969)
            .onClick(() => {
              this.editFlag = !this.editFlag
            })
        }.sticky(Sticky.Normal)

        ForEach(this.arr, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }.editable(this.editFlag)
        }, item => item)
      }
      .editMode(true)
      .onItemDelete((index: number) => {
        console.info(this.arr[index - 1] + 'Delete')
        this.arr.splice(index - 1,1)
        this.editFlag = false
        return true
      }).width('90%')
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![](figures/ListItem.gif)

