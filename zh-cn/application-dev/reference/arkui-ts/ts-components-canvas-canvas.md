# Canvas<a name="ZH-CN_TOPIC_0000001237355065"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供画布组件，用于自定义绘制图形。

## 权限列表<a name="section53281531154915"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

## 接口<a name="section15647101282420"></a>

Canvas\(context: CanvasRenderingContext2D\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="12.540000000000001%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.150000000000002%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.49%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.6%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="12.540000000000001%" headers="mcps1.1.6.1.1 "><p>context</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.150000000000002%" headers="mcps1.1.6.1.2 "><p><a href="ts-canvasrenderingcontext2d.md">CanvasRenderingContext2D</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.49%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p>见<a href="ts-canvasrenderingcontext2d.md">CanvasRenderingContext2D</a>对象。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section2907183951110"></a>

支持[通用属性](ts-universal-attributes-size.md)。

## 事件<a name="section47669296127"></a>

除支持[通用事件](ts-universal-events-click.md)外，还支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="34.2%" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.470000000000002%" id="mcps1.1.4.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="49.33%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="34.2%" headers="mcps1.1.4.1.1 "><p>onReady(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" width="16.470000000000002%" headers="mcps1.1.4.1.2 "><p>无</p>
</td>
<td class="cellrowborder" valign="top" width="49.33%" headers="mcps1.1.4.1.3 "><p>画布组件的事件回调，可以在此时进行绘制。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section42931433142318"></a>

```
@Entry
@Component
struct CanvasExample {
  private settings: RenderingContextSettings = new RenderingContextSettings(true,true)
  private context: RenderingContext = new RenderingContext(this.settings)

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.fillRect(0,30,100,100)
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

