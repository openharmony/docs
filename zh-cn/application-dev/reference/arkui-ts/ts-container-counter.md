# Counter<a name="ZH-CN_TOPIC_0000001193075082"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

计数器组件，提供相应的增加或者减少的计数操作。

## 权限列表<a name="section53281531154915"></a>

无

## 子组件<a name="section5989144051714"></a>

可以包含子组件。

## 接口<a name="section14196162892911"></a>

Counter\(\)

## 事件<a name="section945991855410"></a>

不支持通用事件和手势， 仅支持如下事件：

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onInc(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>监听数值增加事件。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onDec(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>监听数值减少事件。</p>
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

