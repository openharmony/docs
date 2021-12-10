# Counter<a name="ZH-CN_TOPIC_0000001169265275"></a>

计数器组件，提供相应的增加或者减少的计数操作。

## 子组件<a name="section5989144051714"></a>

可以包含子组件。

## 接口<a name="section14196162892911"></a>

Counter\(\)

## 事件<a name="section945991855410"></a>

不支持通用事件和手势， 仅支持如下事件：

<a name="table644016378401"></a>
<table><thead align="left"><tr id="row544018378408"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p204408371408"><a name="p204408371408"></a><a name="p204408371408"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p64407376405"><a name="p64407376405"></a><a name="p64407376405"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row124407372409"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p18440143716402"><a name="p18440143716402"></a><a name="p18440143716402"></a>onInc(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p144407372407"><a name="p144407372407"></a><a name="p144407372407"></a>监听数值增加事件。</p>
</td>
</tr>
<tr id="row844013754010"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p244016375402"><a name="p244016375402"></a><a name="p244016375402"></a>onDec(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1744012372402"><a name="p1744012372402"></a><a name="p1744012372402"></a>监听数值减少事件。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section1078035104913"></a>

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

![](figures/Counter.gif)

