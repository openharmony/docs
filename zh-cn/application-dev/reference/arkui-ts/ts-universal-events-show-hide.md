# 挂载卸载事件<a name="ZH-CN_TOPIC_0000001112981806"></a>

<a name="table2154mcpsimp"></a>
<table><thead align="left"><tr id="row2160mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.5.1.1"><p id="p2164mcpsimp"><a name="p2164mcpsimp"></a><a name="p2164mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.2"><p id="p1037419419496"><a name="p1037419419496"></a><a name="p1037419419496"></a>支持冒泡</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.3"><p id="p2166mcpsimp"><a name="p2166mcpsimp"></a><a name="p2166mcpsimp"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2167mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p id="p2169mcpsimp"><a name="p2169mcpsimp"></a><a name="p2169mcpsimp"></a>onAppear(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p id="p1437415424917"><a name="p1437415424917"></a><a name="p1437415424917"></a>否</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p id="p2173mcpsimp"><a name="p2173mcpsimp"></a><a name="p2173mcpsimp"></a>组件挂载显示时触发此回调。</p>
</td>
</tr>
<tr id="row1357111982818"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p id="p3571101917283"><a name="p3571101917283"></a><a name="p3571101917283"></a>onDisappear(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p id="p1937434144915"><a name="p1937434144915"></a><a name="p1937434144915"></a>否</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p id="p5571319112811"><a name="p5571319112811"></a><a name="p5571319112811"></a>组件卸载消失时触发此回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section13817013123017"></a>

```
import prompt from '@system.prompt'

@Entry
@Component
struct AppearExample {
  @State isShow: boolean = true
  private myText: string = 'Text for onAppear'
  private changeAppear: string = 'Hide Text'

  build() {
    Column() {
      Button(this.changeAppear)
        .onClick(() => {
          this.isShow = !this.isShow
        }).margin(3).backgroundColor(0x2788D9)
      if (this.isShow) {
        Text(this.myText)
          .onAppear(() => {
            this.changeAppear = 'Show Text'
            prompt.showToast({ message: 'The text is shown', duration: 2000 })
          })
          .onDisAppear(() => {
            this.changeAppear = 'Hide Text'
            prompt.showToast({ message: 'The text is hidden', duration: 2000 })
          })
      }
    }.padding(30).width('100%')
  }
}
```

![](figures/appear.gif)

