# Z-order Control<a name="EN-US_TOPIC_0000001237475083"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## Attributes<a name="section6820191711316"></a>

<a name="table3548mcpsimp"></a>
<table><thead align="left"><tr id="row3556mcpsimp"><th class="cellrowborder" valign="top" width="15.120000000000001%" id="mcps1.1.5.1.1"><p id="p3558mcpsimp"><a name="p3558mcpsimp"></a><a name="p3558mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.829999999999998%" id="mcps1.1.5.1.2"><p id="p3560mcpsimp"><a name="p3560mcpsimp"></a><a name="p3560mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.39%" id="mcps1.1.5.1.3"><p id="p3562mcpsimp"><a name="p3562mcpsimp"></a><a name="p3562mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="58.660000000000004%" id="mcps1.1.5.1.4"><p id="p3566mcpsimp"><a name="p3566mcpsimp"></a><a name="p3566mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3567mcpsimp"><td class="cellrowborder" valign="top" width="15.120000000000001%" headers="mcps1.1.5.1.1 "><p id="p3569mcpsimp"><a name="p3569mcpsimp"></a><a name="p3569mcpsimp"></a>zIndex</p>
</td>
<td class="cellrowborder" valign="top" width="14.829999999999998%" headers="mcps1.1.5.1.2 "><p id="p3571mcpsimp"><a name="p3571mcpsimp"></a><a name="p3571mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.39%" headers="mcps1.1.5.1.3 "><p id="p3573mcpsimp"><a name="p3573mcpsimp"></a><a name="p3573mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="58.660000000000004%" headers="mcps1.1.5.1.4 "><p id="p3577mcpsimp"><a name="p3577mcpsimp"></a><a name="p3577mcpsimp"></a>Hierarchy of sibling components in a container. A larger z-order value indicates a higher display level.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section4278134412416"></a>

```
@Entry
@Component
struct ZIndexExample {
  build() {
    Column() {
      Stack() {
        // Components are stacked. By default, the component defined later is on the top.
        Text('first child, zIndex(2)')
          .size({width: '40%', height: '30%'}).backgroundColor(0xbbb2cb)
          .zIndex(2)
        // The default value is 0.
        Text('second child, default zIndex(0)')
          .size({width: '90%', height: '80%'}).backgroundColor(0xd2cab3).align(Alignment.TopStart)
        Text('third child, zIndex(1)')
          .size({width: '70%', height: '50%'}).backgroundColor(0xc1cbac).align(Alignment.TopStart)
          .zIndex(1)
      }
    }.width('100%').height(200)
  }
}
```

![](figures/zindex.png)

