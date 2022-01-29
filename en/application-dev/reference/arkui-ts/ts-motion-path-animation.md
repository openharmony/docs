# Motion Path Animation<a name="EN-US_TOPIC_0000001193075092"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The attributes described in this topic are used to set the motion path of the component in a translation animation.

## Attributes<a name="section1944320255912"></a>

<a name="table372mcpsimp"></a>
<table><thead align="left"><tr id="row379mcpsimp"><th class="cellrowborder" valign="top" width="14.06%" id="mcps1.1.5.1.1"><p id="p381mcpsimp"><a name="p381mcpsimp"></a><a name="p381mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="33.61%" id="mcps1.1.5.1.2"><p id="p383mcpsimp"><a name="p383mcpsimp"></a><a name="p383mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.16%" id="mcps1.1.5.1.3"><p id="p385mcpsimp"><a name="p385mcpsimp"></a><a name="p385mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="42.17%" id="mcps1.1.5.1.4"><p id="p387mcpsimp"><a name="p387mcpsimp"></a><a name="p387mcpsimp"></a>Description</p>
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
<div class="note" id="note11586162314318"><a name="note11586162314318"></a><a name="note11586162314318"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p18761128184314"><a name="p18761128184314"></a><a name="p18761128184314"></a>In a path, <strong id="b9143801828"><a name="b9143801828"></a><a name="b9143801828"></a>start</strong> and <strong id="b165901821023"><a name="b165901821023"></a><a name="b165901821023"></a>end</strong> can be used to replace the start point and end point. Example:</p>
<p id="p18761628194312"><a name="p18761628194312"></a><a name="p18761628194312"></a>'Mstart.x start.y L50 50 Lend.x end.y Z'</p>
</div></div>
</td>
<td class="cellrowborder" valign="top" width="10.16%" headers="mcps1.1.5.1.3 "><p id="p13559292229"><a name="p13559292229"></a><a name="p13559292229"></a>{</p>
<p id="p211519113229"><a name="p211519113229"></a><a name="p211519113229"></a>"",</p>
<p id="p14647151352215"><a name="p14647151352215"></a><a name="p14647151352215"></a>0.0,</p>
<p id="p3601175613423"><a name="p3601175613423"></a><a name="p3601175613423"></a>1.0,</p>
<p id="p11188815192218"><a name="p11188815192218"></a><a name="p11188815192218"></a>false</p>
<p id="p394mcpsimp"><a name="p394mcpsimp"></a><a name="p394mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="42.17%" headers="mcps1.1.5.1.4 "><p id="p396mcpsimp"><a name="p396mcpsimp"></a><a name="p396mcpsimp"></a>Motion path of the component. The input parameters are described as follows:</p>
<a name="ul1443318326611"></a><a name="ul1443318326611"></a><ul id="ul1443318326611"><li><strong id="b3296105661213"><a name="b3296105661213"></a><a name="b3296105661213"></a>path</strong>: motion path of the translation animation. The <strong id="b336094713123"><a name="b336094713123"></a><a name="b336094713123"></a>svg</strong> path string is used.</li><li><strong id="b10207259181210"><a name="b10207259181210"></a><a name="b10207259181210"></a>from</strong>: start point of the motion path. The default value is <strong id="b13975130201314"><a name="b13975130201314"></a><a name="b13975130201314"></a>0.0</strong>.</li><li><strong id="b579283151316"><a name="b579283151316"></a><a name="b579283151316"></a>to</strong>: end point of the motion path. The default value is <strong id="b135114617132"><a name="b135114617132"></a><a name="b135114617132"></a>1.0</strong>.</li><li><strong id="b88061611181311"><a name="b88061611181311"></a><a name="b88061611181311"></a>rotatable</strong>: whether to rotate along the path.</li></ul>
</td>
</tr>
</tbody>
</table>

## Example<a name="section4278134412416"></a>

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

