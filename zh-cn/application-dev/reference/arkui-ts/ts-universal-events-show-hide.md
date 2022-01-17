# 挂载卸载事件<a name="ZH-CN_TOPIC_0000001192595164"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 事件<a name="section12538399584"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.2"><p>支持冒泡</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.3"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p>onAppear(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p>组件挂载显示时触发此回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p>onDisappear(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p>否</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p>组件卸载消失时触发此回调。</p>
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

