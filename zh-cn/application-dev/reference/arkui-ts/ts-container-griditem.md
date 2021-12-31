# GridItem<a name="ZH-CN_TOPIC_0000001237715083"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

网格容器中单项内容容器。

## 权限列表<a name="section14336424193517"></a>

无

## 子组件<a name="section12191193463511"></a>

可以包含子组件。

## 接口<a name="section158081656113510"></a>

GridItem\(\)

## 属性<a name="section4907201336"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.09%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.600000000000001%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.920000000000001%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="61.39%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p>rowStart</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p>用于指定当前元素起始行号。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p>rowEnd</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p>用于指定当前元素终点行号。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p>columnStart</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p>用于指定当前元素起始列号。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p>columnEnd</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p>用于指定当前元素终点列号。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p>forceRebuild</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="7.920000000000001%" headers="mcps1.1.5.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p>用于设置在触发组件build时是否重新创建此节点。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section8900105010439"></a>

```
@Entry
@Component
struct GridItemExample {
  @State numbers: string[] = Array.apply(null, Array(16)).map(function (item, i) { return i.toString() })

  build() {
    Column() {
      Grid() {
        GridItem() {
          Text('4')
            .fontSize(16).backgroundColor(0xFAEEE0)
            .width('100%').height('100%').textAlign(TextAlign.Center)
        }.rowStart(1).rowEnd(4)

        ForEach(this.numbers, (item) => {
          GridItem() {
            Text(item)
              .fontSize(16).backgroundColor(0xF9CF93)
              .width('100%').height('100%').textAlign(TextAlign.Center)
          }.forceRebuild(false)
        }, item => item)

        GridItem() {
          Text('5')
            .fontSize(16).backgroundColor(0xDBD0C0)
            .width('100%').height('100%').textAlign(TextAlign.Center)
        }.columnStart(1).columnEnd(5)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .width('90%').height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/griditem.gif)

