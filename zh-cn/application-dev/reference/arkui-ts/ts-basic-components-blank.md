# Blank<a name="ZH-CN_TOPIC_0000001169482471"></a>

空白填充组件，在容器主轴方向上，空白填充组件具有自动填充容器空余部分的能力。

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   仅当父组件为Row/Column时生效。

## 权限列表<a name="section781125411508"></a>

无

## 子组件<a name="section171053164519"></a>

无

## 接口<a name="section314622835214"></a>

Blank\(min?:  Length\)

-   参数

    <a name="table51331156183410"></a>
    <table><thead align="left"><tr id="row111341565346"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p6134195615345"><a name="p6134195615345"></a><a name="p6134195615345"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.959999999999999%" id="mcps1.1.6.1.2"><p id="p1113435614341"><a name="p1113435614341"></a><a name="p1113435614341"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.04%" id="mcps1.1.6.1.3"><p id="p213410561340"><a name="p213410561340"></a><a name="p213410561340"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.83%" id="mcps1.1.6.1.4"><p id="p71341656103410"><a name="p71341656103410"></a><a name="p71341656103410"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.06%" id="mcps1.1.6.1.5"><p id="p1913475613348"><a name="p1913475613348"></a><a name="p1913475613348"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1513415615348"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p19134165610345"><a name="p19134165610345"></a><a name="p19134165610345"></a>min</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p id="p16134135612342"><a name="p16134135612342"></a><a name="p16134135612342"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p id="p1313417561349"><a name="p1313417561349"></a><a name="p1313417561349"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.83%" headers="mcps1.1.6.1.4 "><p id="p81354564345"><a name="p81354564345"></a><a name="p81354564345"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.06%" headers="mcps1.1.6.1.5 "><p id="p15135856173410"><a name="p15135856173410"></a><a name="p15135856173410"></a>空白填充组件在容器主轴上的最小大小。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section135766153337"></a>

<a name="table1088mcpsimp"></a>
<table><thead align="left"><tr id="row1095mcpsimp"><th class="cellrowborder" valign="top" width="13.389999999999999%" id="mcps1.1.5.1.1"><p id="p1097mcpsimp"><a name="p1097mcpsimp"></a><a name="p1097mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.430000000000001%" id="mcps1.1.5.1.2"><p id="p1099mcpsimp"><a name="p1099mcpsimp"></a><a name="p1099mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="22.36%" id="mcps1.1.5.1.3"><p id="p1101mcpsimp"><a name="p1101mcpsimp"></a><a name="p1101mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="49.82%" id="mcps1.1.5.1.4"><p id="p1103mcpsimp"><a name="p1103mcpsimp"></a><a name="p1103mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1104mcpsimp"><td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.1 "><p id="p1106mcpsimp"><a name="p1106mcpsimp"></a><a name="p1106mcpsimp"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="14.430000000000001%" headers="mcps1.1.5.1.2 "><p id="p0229681416"><a name="p0229681416"></a><a name="p0229681416"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="22.36%" headers="mcps1.1.5.1.3 "><p id="p1110mcpsimp"><a name="p1110mcpsimp"></a><a name="p1110mcpsimp"></a>0x00000000</p>
</td>
<td class="cellrowborder" valign="top" width="49.82%" headers="mcps1.1.5.1.4 "><p id="p1112mcpsimp"><a name="p1112mcpsimp"></a><a name="p1112mcpsimp"></a>设置空白填充的填充颜色。</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   不支持通用属性方法。

## 示例<a name="section18551123820541"></a>

```
@Entry
@Component
struct BlankExample {
  build() {
    Column() {
      Row() {
        Text('Bluetooth').fontSize(18)
        Blank()
        Text('on/off').fontSize(18).height(60)
      }.width('100%').backgroundColor(0xFFFFFF).borderRadius(15).padding(12)
    }.backgroundColor(0xEFEFEF).padding(20)
  }
}
```

竖屏状态

![](figures/blank_v.gif)

横屏状态

![](figures/blank_h.gif)

