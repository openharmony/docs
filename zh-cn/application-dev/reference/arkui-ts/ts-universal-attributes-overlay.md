# 浮层<a name="ZH-CN_TOPIC_0000001237355073"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 属性<a name="section6820191711316"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="15.120000000000001%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="35.94%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="25.4%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="23.54%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="15.120000000000001%" headers="mcps1.1.5.1.1 "><p>overlay</p>
</td>
<td class="cellrowborder" valign="top" width="35.94%" headers="mcps1.1.5.1.2 "><p>title: string,</p>
<p>options: {</p>
<p>align?: <a href="ts-appendix-enums.md#section1145418513159">Alignment</a>,</p>
<p>offset?: {x: number, y: number}</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="25.4%" headers="mcps1.1.5.1.3 "><p>{</p>
<p>align: Alignment.Center,</p>
<p>offset: {0, 0}</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="23.54%" headers="mcps1.1.5.1.4 "><p>在当前组件上，增加遮罩文本，布局与当前组件相同。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section4278134412416"></a>

```
@Entry
@Component
struct OverlayExample {
  build() {
    Column() {
      Column() {
        Text('floating layer')
          .fontSize(12).fontColor(0xCCCCCC).maxLines(1)
        Column() {
          Image($r('app.media.img'))
            .width(240).height(240)
            .overlay("Winter is a beautiful season, especially when it snows", { align: Alignment.Bottom, offset: { x: 0, y: -15 } })
        }.border({ color: Color.Black, width: 2 })
      }.width('100%')
    }.padding({ top: 20 })
  }
}
```

![](figures/overlay.png)

