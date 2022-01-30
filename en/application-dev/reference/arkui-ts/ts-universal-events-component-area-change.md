# Component Area Change Event<a name="EN-US_TOPIC_0000001237475071"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This event is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## Events<a name="section7486701018"></a>

<a name="table268mcpsimp"></a>
<table><thead align="left"><tr id="row274mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.5.1.1"><p id="p278mcpsimp"><a name="p278mcpsimp"></a><a name="p278mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.2"><p id="p240018113020"><a name="p240018113020"></a><a name="p240018113020"></a>Bubble Supported</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.3"><p id="p280mcpsimp"><a name="p280mcpsimp"></a><a name="p280mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row281mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p id="p15453115275010"><a name="p15453115275010"></a><a name="p15453115275010"></a>onAreaChange(event: (oldValue: Area, newValue: Area) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p id="p240119143012"><a name="p240119143012"></a><a name="p240119143012"></a>No</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p id="p287mcpsimp"><a name="p287mcpsimp"></a><a name="p287mcpsimp"></a>Triggered when the component area changes. For details about the <strong id="b419315131717"><a name="b419315131717"></a><a name="b419315131717"></a>Area</strong> type, see the description of the <a href="ts-universal-events-click.md#li3196948121214">Area object</a>.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section16900453182718"></a>

```
@Entry
@Component
struct AreaExample {
  @State value: string = 'Text'
  @State size: string = ''

  build() {
    Column() {
      Text(this.value)
        .backgroundColor(Color.Green).margin(30).fontSize(20)
        .onClick(() => {
          this.value = this.value + 'Text'
        })
        .onAreaChange((oldValue: Area, newValue: Area) => {
          console.info(`Ace: on area change, oldValue is ${JSON.stringify(oldValue)} value is ${JSON.stringify(newValue)}`)
          this.size = JSON.stringify(newValue)
        })
      Text('new area is: \n' + this.size).margin({ right: 30, left: 30 })
    }
    .width('100%').height('100%').margin({ top: 30 })
  }
}
```

![](figures/gif4.gif)

