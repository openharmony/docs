# 显式动画<a name="ZH-CN_TOPIC_0000001166728467"></a>

<a name="table1895110111017"></a>
<table><thead align="left"><tr id="row18957091013"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p78958041010"><a name="p78958041010"></a><a name="p78958041010"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p280mcpsimp"><a name="p280mcpsimp"></a><a name="p280mcpsimp"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1895900101"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p1189510011101"><a name="p1189510011101"></a><a name="p1189510011101"></a>animateTo(value: <a href="#section16458591411">AnimationOption</a>, event: ()=&gt; void) : void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p2089520101014"><a name="p2089520101014"></a><a name="p2089520101014"></a>提供全局animateTo显式动画接口来指定由于闭包代码导致的状态变化插入过渡动效。</p>
<p id="p8778777144"><a name="p8778777144"></a><a name="p8778777144"></a>event指定显示动效的闭包函数，在闭包函数中导致的状态变化系统会自动插入过渡动画。</p>
</td>
</tr>
</tbody>
</table>

## AnimationOption对象说明<a name="section16458591411"></a>

-   属性

    <a name="table2041216018129"></a>
    <table><thead align="left"><tr id="row94129081216"><th class="cellrowborder" valign="top" width="17.681768176817684%" id="mcps1.1.5.1.1"><p id="p9412502127"><a name="p9412502127"></a><a name="p9412502127"></a>属性名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.01200120012001%" id="mcps1.1.5.1.2"><p id="p1141240201211"><a name="p1141240201211"></a><a name="p1141240201211"></a>属性类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.54205420542054%" id="mcps1.1.5.1.3"><p id="p8412180191210"><a name="p8412180191210"></a><a name="p8412180191210"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.76417641764177%" id="mcps1.1.5.1.4"><p id="p194133021216"><a name="p194133021216"></a><a name="p194133021216"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16413130171215"><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p id="p1041317001217"><a name="p1041317001217"></a><a name="p1041317001217"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p id="p1441316014121"><a name="p1441316014121"></a><a name="p1441316014121"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p id="p104136081218"><a name="p104136081218"></a><a name="p104136081218"></a>1000</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p id="p1641313051217"><a name="p1641313051217"></a><a name="p1641313051217"></a>动画持续时间，单位为毫秒。</p>
    </td>
    </tr>
    <tr id="row16413503127"><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p id="p441370101211"><a name="p441370101211"></a><a name="p441370101211"></a>tempo</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p id="p13413140161214"><a name="p13413140161214"></a><a name="p13413140161214"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p id="p441380181215"><a name="p441380181215"></a><a name="p441380181215"></a>1.0</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p id="p1541370191217"><a name="p1541370191217"></a><a name="p1541370191217"></a>动画的播放速度，值越大动画播放越快，值越小播放越慢，为0时无动画效果。</p>
    </td>
    </tr>
    <tr id="row741318019128"><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p id="p134139081216"><a name="p134139081216"></a><a name="p134139081216"></a>curve</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p id="p1541319019126"><a name="p1541319019126"></a><a name="p1541319019126"></a>Curve | Curves</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p id="p4413150131213"><a name="p4413150131213"></a><a name="p4413150131213"></a>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p id="p16413009121"><a name="p16413009121"></a><a name="p16413009121"></a>动画曲线。</p>
    </td>
    </tr>
    <tr id="row9413150101218"><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p id="p24132041219"><a name="p24132041219"></a><a name="p24132041219"></a>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p id="p15413507125"><a name="p15413507125"></a><a name="p15413507125"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p id="p1741360101213"><a name="p1741360101213"></a><a name="p1741360101213"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p id="p1641317041213"><a name="p1641317041213"></a><a name="p1641317041213"></a>单位为ms(毫秒)，默认不延时播放。</p>
    </td>
    </tr>
    <tr id="row1941313011121"><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p id="p1741313071217"><a name="p1741313071217"></a><a name="p1741313071217"></a>iterations</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p id="p4413800123"><a name="p4413800123"></a><a name="p4413800123"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p id="p18413140101220"><a name="p18413140101220"></a><a name="p18413140101220"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p id="p041316011124"><a name="p041316011124"></a><a name="p041316011124"></a>默认播放一次，设置为-1时表示无限次播放。</p>
    </td>
    </tr>
    <tr id="row84132010126"><td class="cellrowborder" valign="top" width="17.681768176817684%" headers="mcps1.1.5.1.1 "><p id="p14132016128"><a name="p14132016128"></a><a name="p14132016128"></a>playMode</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.01200120012001%" headers="mcps1.1.5.1.2 "><p id="p1741315011215"><a name="p1741315011215"></a><a name="p1741315011215"></a>PlayMode</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.54205420542054%" headers="mcps1.1.5.1.3 "><p id="p841310051211"><a name="p841310051211"></a><a name="p841310051211"></a>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.76417641764177%" headers="mcps1.1.5.1.4 "><p id="p124147011212"><a name="p124147011212"></a><a name="p124147011212"></a>设置动画播放模式，默认播放完成后重头开始播放。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   接口

    <a name="table268mcpsimp"></a>
    <table><thead align="left"><tr id="row274mcpsimp"><th class="cellrowborder" valign="top" width="40.6%" id="mcps1.1.3.1.1"><p id="p276mcpsimp"><a name="p276mcpsimp"></a><a name="p276mcpsimp"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.4%" id="mcps1.1.3.1.2"><p id="p19746145373519"><a name="p19746145373519"></a><a name="p19746145373519"></a>功能描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row281mcpsimp"><td class="cellrowborder" valign="top" width="40.6%" headers="mcps1.1.3.1.1 "><p id="p283mcpsimp"><a name="p283mcpsimp"></a><a name="p283mcpsimp"></a>onFinish() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.4%" headers="mcps1.1.3.1.2 "><p id="p287mcpsimp"><a name="p287mcpsimp"></a><a name="p287mcpsimp"></a>动效播放完成回调。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section1768142514453"></a>

```
@Entry
@Component
struct AnimateToExample {
  @State widthSize: number = 200
  @State heightSize: number = 100
  private flag: boolean = true

  build() {
    Column() {
      Button('click me')
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(0x317aff)
        .onClick((event: ClickEvent) => {
          // 对Button组件的宽高属性进行动画配置
          if (this.flag) {
            animateTo({
              duration: 1000, // 动画时长
              tempo: 0.5, // 播放速率
              curve: Curve.EaseInOut, // 动画曲线
              delay: 200, // 动画延迟
              iterations: 1, // 播放次数
              playMode: PlayMode.Normal, // 动画模式
              onFinish: () => {
                console.info('play end')
              }
            }, () => {
              this.widthSize = 100
              this.heightSize = 50
            })
          } else {
            animateTo({
              duration: 200, // 动画时长
              curve: Curve.Ease, // 动画曲线
              delay: 200, // 动画延迟
              iterations: 1, // 播放次数
              playMode: PlayMode.Normal, // 动画模式
              onFinish: () => {
                console.info('play end')
              }
            }, () => {
              this.widthSize = 200
              this.heightSize = 100
            })
          }
          this.flag = !this.flag
        })
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/AnimateTo.gif)

