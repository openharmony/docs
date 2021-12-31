# 路径动画<a name="ZH-CN_TOPIC_0000001193075092"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

设置组件进行位移动画时的运动路径。

## 属性<a name="section1944320255912"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.06%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.61%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.16%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="42.17%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="14.06%" headers="mcps1.1.5.1.1 "><p>motionPath</p>
</td>
<td class="cellrowborder" valign="top" width="33.61%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>path: string,</p>
<p>from?: number,</p>
<p>to?: number,</p>
<p>rotatable?: boolean</p>
<p>}</p>
<div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>path中支持通过start和end进行起点和终点的替代，如：</p>
<p>'Mstart.x start.y L50 50 Lend.x end.y Z'。</p>
</div></div>
</td>
<td class="cellrowborder" valign="top" width="10.16%" headers="mcps1.1.5.1.3 "><p>{</p>
<p>"",</p>
<p>0.0,</p>
<p>1.0,</p>
<p>false</p>
<p>}</p>
</td>
<td class="cellrowborder" valign="top" width="42.17%" headers="mcps1.1.5.1.4 "><p>设置组件的运动路径，入参说明如下：</p>
<ul><li>path：位移动画的运动路径，使用svg路径字符串。</li><li>from：运动路径的起点，默认为0.0。</li><li>to：运动路径的终点，默认为1.0。</li><li>rotatable：是否跟随路径进行旋转。</li></ul>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section4278134412416"></a>

```
@Entry
@Component
struct MotionPathExample {
  @State offsetX: number = 0
  @State offsetY: number = 0
  @State toggle: boolean = true

  build() {
    Column() {
      Button('click me')
        .motionPath({ path: 'Mstart.x start.y L300 200 L300 500 Lend.x end.y', from: 0.0, to: 1.0, rotatable: true })
        .onClick((event: ClickEvent) => {
          animateTo({ duration: 4000, curve: Curve.Linear }, () => {
            this.toggle = !this.toggle;
          })
        }).backgroundColor(0x317aff)
    }.width('100%').height('100%').alignItems(this.toggle ? HorizontalAlign.Start : HorizontalAlign.Center)
  }
}
```

![](figures/motion.gif)

