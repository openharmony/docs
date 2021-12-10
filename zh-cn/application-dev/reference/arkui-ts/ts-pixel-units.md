# 像素单位<a name="ZH-CN_TOPIC_0000001111581268"></a>

为开发者提供4种像素单位，框架采用vp为基准数据单位。

<a name="table230mcpsimp"></a>
<table><thead align="left"><tr id="row235mcpsimp"><th class="cellrowborder" valign="top" width="13%" id="mcps1.1.3.1.1"><p id="p237mcpsimp"><a name="p237mcpsimp"></a><a name="p237mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="87%" id="mcps1.1.3.1.2"><p id="p239mcpsimp"><a name="p239mcpsimp"></a><a name="p239mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row240mcpsimp"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.3.1.1 "><p id="p242mcpsimp"><a name="p242mcpsimp"></a><a name="p242mcpsimp"></a>px</p>
</td>
<td class="cellrowborder" valign="top" width="87%" headers="mcps1.1.3.1.2 "><p id="p244mcpsimp"><a name="p244mcpsimp"></a><a name="p244mcpsimp"></a>屏幕物理像素单位。</p>
</td>
</tr>
<tr id="row245mcpsimp"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.3.1.1 "><p id="p247mcpsimp"><a name="p247mcpsimp"></a><a name="p247mcpsimp"></a>vp</p>
</td>
<td class="cellrowborder" valign="top" width="87%" headers="mcps1.1.3.1.2 "><p id="p249mcpsimp"><a name="p249mcpsimp"></a><a name="p249mcpsimp"></a>屏幕密度相关像素，根据屏幕像素密度转换为屏幕物理像素。</p>
</td>
</tr>
<tr id="row250mcpsimp"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.3.1.1 "><p id="p252mcpsimp"><a name="p252mcpsimp"></a><a name="p252mcpsimp"></a>fp</p>
</td>
<td class="cellrowborder" valign="top" width="87%" headers="mcps1.1.3.1.2 "><p id="p254mcpsimp"><a name="p254mcpsimp"></a><a name="p254mcpsimp"></a>字体像素，与vp类似适用屏幕密度变化，随系统字体大小设置变化。</p>
</td>
</tr>
<tr id="row920003123018"><td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.3.1.1 "><p id="p1020016393011"><a name="p1020016393011"></a><a name="p1020016393011"></a>lpx</p>
</td>
<td class="cellrowborder" valign="top" width="87%" headers="mcps1.1.3.1.2 "><p id="p1120043183010"><a name="p1120043183010"></a><a name="p1120043183010"></a>视窗逻辑像素单位，lpx单位为实际屏幕宽度与逻辑宽度（通过<a href="ts-framework-js-tag.md#table12744175911317">designWidth</a>配置）的比值。如配置designWidth为720时，在实际宽度为1440物理像素的屏幕上，1lpx为2px大小。</p>
</td>
</tr>
</tbody>
</table>

## 像素单位转换<a name="section43478451141"></a>

提供其他单位与px单位互相转换的方法。

<a name="table16548143615916"></a>
<table><thead align="left"><tr id="row175481036794"><th class="cellrowborder" valign="top" width="35.69%" id="mcps1.1.3.1.1"><p id="p14548123614910"><a name="p14548123614910"></a><a name="p14548123614910"></a>接口</p>
</th>
<th class="cellrowborder" valign="top" width="64.31%" id="mcps1.1.3.1.2"><p id="p11548183618912"><a name="p11548183618912"></a><a name="p11548183618912"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row75487361090"><td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.3.1.1 "><p id="p05483367914"><a name="p05483367914"></a><a name="p05483367914"></a>vp2px(value : number) : number</p>
</td>
<td class="cellrowborder" valign="top" width="64.31%" headers="mcps1.1.3.1.2 "><p id="p6239203321019"><a name="p6239203321019"></a><a name="p6239203321019"></a>将vp单位的数值转换为以px为单位的数值。</p>
</td>
</tr>
<tr id="row0770112219335"><td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.3.1.1 "><p id="p177017220331"><a name="p177017220331"></a><a name="p177017220331"></a>px2vp(value : number) : number</p>
</td>
<td class="cellrowborder" valign="top" width="64.31%" headers="mcps1.1.3.1.2 "><p id="p8770192212335"><a name="p8770192212335"></a><a name="p8770192212335"></a>将px单位的数值转换为以vp为单位的数值。</p>
</td>
</tr>
<tr id="row15951172693314"><td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.3.1.1 "><p id="p15951102643316"><a name="p15951102643316"></a><a name="p15951102643316"></a>fp2px(value : number) : number</p>
</td>
<td class="cellrowborder" valign="top" width="64.31%" headers="mcps1.1.3.1.2 "><p id="p995152643319"><a name="p995152643319"></a><a name="p995152643319"></a>将fp单位的数值转换为以px为单位的数值。</p>
</td>
</tr>
<tr id="row83152033153314"><td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.3.1.1 "><p id="p231503317331"><a name="p231503317331"></a><a name="p231503317331"></a>px2fp(value : number) : number</p>
</td>
<td class="cellrowborder" valign="top" width="64.31%" headers="mcps1.1.3.1.2 "><p id="p143158337338"><a name="p143158337338"></a><a name="p143158337338"></a>将px单位的数值转换为以fp为单位的数值。</p>
</td>
</tr>
<tr id="row1619816394331"><td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.3.1.1 "><p id="p121981939173310"><a name="p121981939173310"></a><a name="p121981939173310"></a>lpx2px(value : number) : number</p>
</td>
<td class="cellrowborder" valign="top" width="64.31%" headers="mcps1.1.3.1.2 "><p id="p819843963311"><a name="p819843963311"></a><a name="p819843963311"></a>将lpx单位的数值转换为以px为单位的数值。</p>
</td>
</tr>
<tr id="row955964320338"><td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.3.1.1 "><p id="p35591243143310"><a name="p35591243143310"></a><a name="p35591243143310"></a>px2lpx(value : number) : number</p>
</td>
<td class="cellrowborder" valign="top" width="64.31%" headers="mcps1.1.3.1.2 "><p id="p14559343153314"><a name="p14559343153314"></a><a name="p14559343153314"></a>将px单位的数值转换为以lpx为单位的数值。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section208264919153"></a>

```
@Entry
@Component
struct Example {
  build() {
    Column() {
      Flex({ wrap: FlexWrap.Wrap }) {
        Column() {
          Text("width(220)")
            .width(220).height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White).fontSize('12vp')
        }.margin(5)
        Column() {
          Text("width('220px')")
            .width('220px').height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White)
        }.margin(5)
        Column() {
          Text("width('220vp')")
            .width('220vp').height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White).fontSize('12vp')
        }.margin(5)
        Column() {
          Text("width('220lpx') designWidth:720")
            .width('220lpx').height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White).fontSize('12vp')
        }.margin(5)
        Column() {
          Text("width(vp2px(220) + 'px')")
            .width(vp2px(220) + 'px').height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White).fontSize('12vp')
        }.margin(5)
        Column() {
          Text("fontSize('12fp')")
            .width(220).height(40).backgroundColor(0xF9CF93)
            .textAlign(TextAlign.Center).fontColor(Color.White).fontSize('12fp')
        }.margin(5)
      }.width('100%')
    }
  }
}
```

![](figures/像素单位.gif)

