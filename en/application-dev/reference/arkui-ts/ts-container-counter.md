# Counter<a name="EN-US_TOPIC_0000001193075082"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Counter\>**  component provides an operation to increase or decrease the number.

## Required Permissions<a name="section53281531154915"></a>

None

## Child Components<a name="section5989144051714"></a>

This component can contain child components.

## APIs<a name="section14196162892911"></a>

Counter\(\)

## Events<a name="section945991855410"></a>

Universal events and gestures are not supported. Only the events listed below are supported.

<a name="table644016378401"></a>
<table><thead align="left"><tr id="row544018378408"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p204408371408"><a name="p204408371408"></a><a name="p204408371408"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p64407376405"><a name="p64407376405"></a><a name="p64407376405"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row124407372409"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p18440143716402"><a name="p18440143716402"></a><a name="p18440143716402"></a>onInc(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p144407372407"><a name="p144407372407"></a><a name="p144407372407"></a>Event indicating that the number of monitored objects is increased.</p>
</td>
</tr>
<tr id="row844013754010"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p244016375402"><a name="p244016375402"></a><a name="p244016375402"></a>onDec(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1744012372402"><a name="p1744012372402"></a><a name="p1744012372402"></a>Event indicating that the number of monitored objects is decreased.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section1078035104913"></a>

```
@Entry
@Component
struct CounterExample {
  @State value: number = 0

  build() {
    Column() {
      Counter() {
        Text(this.value.toString())
      }.margin(100)
      .onInc(() => {
        this.value++
      })
      .onDec(() => {
        this.value--
      })
    }.width("100%")
  }
}
```

![](figures/counter.gif)

