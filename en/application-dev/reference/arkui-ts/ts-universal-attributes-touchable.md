# Click Control<a name="EN-US_TOPIC_0000001192595170"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This attribute is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## Attributes<a name="section6820191711316"></a>

<a name="table1857494275915"></a>
<table><thead align="left"><tr id="row1865613421594"><th class="cellrowborder" valign="top" width="25.46%" id="mcps1.1.5.1.1"><p id="p265614255916"><a name="p265614255916"></a><a name="p265614255916"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="18.19%" id="mcps1.1.5.1.2"><p id="p1865714425594"><a name="p1865714425594"></a><a name="p1865714425594"></a><strong id="b14692493144"><a name="b14692493144"></a><a name="b14692493144"></a>Type</strong></p>
</th>
<th class="cellrowborder" valign="top" width="12.120000000000001%" id="mcps1.1.5.1.3"><p id="p46572426593"><a name="p46572426593"></a><a name="p46572426593"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="44.230000000000004%" id="mcps1.1.5.1.4"><p id="p17657942185915"><a name="p17657942185915"></a><a name="p17657942185915"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2657242115920"><td class="cellrowborder" valign="top" width="25.46%" headers="mcps1.1.5.1.1 "><p id="p565719424599"><a name="p565719424599"></a><a name="p565719424599"></a>touchable</p>
</td>
<td class="cellrowborder" valign="top" width="18.19%" headers="mcps1.1.5.1.2 "><p id="p136577426594"><a name="p136577426594"></a><a name="p136577426594"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.120000000000001%" headers="mcps1.1.5.1.3 "><p id="p365774245912"><a name="p365774245912"></a><a name="p365774245912"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="44.230000000000004%" headers="mcps1.1.5.1.4 "><p id="p116579424595"><a name="p116579424595"></a><a name="p116579424595"></a>Whether the current component is touchable.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section1693524132311"></a>

```
@Entry
@Component
struct TouchAbleExample {
  @State text1: string = ''
  @State text2: string = ''

  build() {
    Stack() {
      Rect()
        .fill(Color.Gray).width(150).height(150)
        .onClick(() => {
          console.info(this.text1 = 'Rect Clicked')
        })
        .overlay(this.text1, { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      Ellipse()
        .fill(Color.Pink).width(150).height(80)
        .touchable(false) // When the Ellipse area is touched, the message "Ellipse Clicked" is not displayed.
        .onClick(() => {
          console.info(this.text2 = 'Ellipse Clicked')
        })
        .overlay(this.text2, { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
    }.margin(100)
  }
}
```

![](figures/gif2.gif)

