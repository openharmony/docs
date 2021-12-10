# 路径动画<a name="ZH-CN_TOPIC_0000001172422155"></a>

设置组件进行位移动画时的运动路径。

## 属性<a name="section1944320255912"></a>

<a name="table372mcpsimp"></a>
<table><thead align="left"><tr id="row379mcpsimp"><th class="cellrowborder" valign="top" width="14.06%" id="mcps1.1.5.1.1"><p id="p381mcpsimp"><a name="p381mcpsimp"></a><a name="p381mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.61%" id="mcps1.1.5.1.2"><p id="p383mcpsimp"><a name="p383mcpsimp"></a><a name="p383mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.16%" id="mcps1.1.5.1.3"><p id="p385mcpsimp"><a name="p385mcpsimp"></a><a name="p385mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="42.17%" id="mcps1.1.5.1.4"><p id="p387mcpsimp"><a name="p387mcpsimp"></a><a name="p387mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row388mcpsimp"><td class="cellrowborder" valign="top" width="14.06%" headers="mcps1.1.5.1.1 "><p id="p390mcpsimp"><a name="p390mcpsimp"></a><a name="p390mcpsimp"></a>motionPath</p>
</td>
<td class="cellrowborder" valign="top" width="33.61%" headers="mcps1.1.5.1.2 "><p id="p54191452102110"><a name="p54191452102110"></a><a name="p54191452102110"></a>{</p>
<p id="p54155512115"><a name="p54155512115"></a><a name="p54155512115"></a>path: string,</p>
<p id="p56745722113"><a name="p56745722113"></a><a name="p56745722113"></a>from?: number,</p>
<p id="p16961559162118"><a name="p16961559162118"></a><a name="p16961559162118"></a>to?: number,</p>
<p id="p3796549229"><a name="p3796549229"></a><a name="p3796549229"></a>rotatable?: boolean</p>
<p id="p167364437214"><a name="p167364437214"></a><a name="p167364437214"></a>}</p>
<div class="note" id="note11586162314318"><a name="note11586162314318"></a><a name="note11586162314318"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p18761128184314"><a name="p18761128184314"></a><a name="p18761128184314"></a>path中支持通过start和end进行起点和终点的替代，如：</p>
<p id="p18761628194312"><a name="p18761628194312"></a><a name="p18761628194312"></a>'Mstart.x start.y L50 50 Lend.x end.y Z'。</p>
</div></div>
</td>
<td class="cellrowborder" valign="top" width="10.16%" headers="mcps1.1.5.1.3 "><p id="p13559292229"><a name="p13559292229"></a><a name="p13559292229"></a>{</p>
<p id="p211519113229"><a name="p211519113229"></a><a name="p211519113229"></a>"",</p>
<p id="p14647151352215"><a name="p14647151352215"></a><a name="p14647151352215"></a>0.0,</p>
<p id="p3601175613423"><a name="p3601175613423"></a><a name="p3601175613423"></a>1.0,</p>
<p id="p11188815192218"><a name="p11188815192218"></a><a name="p11188815192218"></a>false</p>
<p id="p394mcpsimp"><a name="p394mcpsimp"></a><a name="p394mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="42.17%" headers="mcps1.1.5.1.4 "><p id="p396mcpsimp"><a name="p396mcpsimp"></a><a name="p396mcpsimp"></a>设置组件的运动路径，入参说明如下：</p>
<a name="ul1443318326611"></a><a name="ul1443318326611"></a><ul id="ul1443318326611"><li>path：位移动画的运动路径，使用svg路径字符串。</li><li>from：运动路径的起点，默认为0.0。</li><li>to：运动路径的终点，默认为1.0。</li><li>rotatable：是否跟随路径进行旋转。</li></ul>
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

