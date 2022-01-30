# Show/Hide Event<a name="EN-US_TOPIC_0000001192595164"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## Events<a name="section12538399584"></a>

<a name="table16415124565812"></a>
<table><thead align="left"><tr id="row441584595812"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.5.1.1"><p id="p13416845125811"><a name="p13416845125811"></a><a name="p13416845125811"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.2"><p id="p154161545155815"><a name="p154161545155815"></a><a name="p154161545155815"></a>Bubble Supported</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.3"><p id="p24161645165818"><a name="p24161645165818"></a><a name="p24161645165818"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row6416164515584"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p id="p2416154545811"><a name="p2416154545811"></a><a name="p2416154545811"></a>onAppear(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p id="p7416204565810"><a name="p7416204565810"></a><a name="p7416204565810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p id="p14161645135813"><a name="p14161645135813"></a><a name="p14161645135813"></a>Called when the component is displayed.</p>
</td>
</tr>
<tr id="row124161145145820"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p id="p941664515582"><a name="p941664515582"></a><a name="p941664515582"></a>onDisappear(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p id="p2416045145816"><a name="p2416045145816"></a><a name="p2416045145816"></a>No</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p id="p1541634516585"><a name="p1541634516585"></a><a name="p1541634516585"></a>Called when the component disappears.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section13817013123017"></a>

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

