# Slider<a name="ZH-CN_TOPIC_0000001196785701"></a>

滑动条组件，用来快速调节设置值，如音量、亮度等。

## 子组件<a name="section53281531154915"></a>

无

## 接口<a name="section1989913519718"></a>

Slider\(value:\{value?: number, min?: number, max?: number, step?: number, style?: SliderStyle\}\)

-   参数

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.99%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.709999999999999%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.18%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.99%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.18%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>当前进度值。</p>
    </td>
    </tr>
    <tr id="row199301191726"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p0930419923"><a name="p0930419923"></a><a name="p0930419923"></a>min</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p1993071918217"><a name="p1993071918217"></a><a name="p1993071918217"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.99%" headers="mcps1.1.6.1.3 "><p id="p29309191029"><a name="p29309191029"></a><a name="p29309191029"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p id="p393019193220"><a name="p393019193220"></a><a name="p393019193220"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.18%" headers="mcps1.1.6.1.5 "><p id="p793001918220"><a name="p793001918220"></a><a name="p793001918220"></a>设置最小值。</p>
    </td>
    </tr>
    <tr id="row1272345516214"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p12723105511214"><a name="p12723105511214"></a><a name="p12723105511214"></a>max</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p172345511213"><a name="p172345511213"></a><a name="p172345511213"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.99%" headers="mcps1.1.6.1.3 "><p id="p672316554211"><a name="p672316554211"></a><a name="p672316554211"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p id="p187241455022"><a name="p187241455022"></a><a name="p187241455022"></a>100</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.18%" headers="mcps1.1.6.1.5 "><p id="p1472495511213"><a name="p1472495511213"></a><a name="p1472495511213"></a>设置最大值</p>
    </td>
    </tr>
    <tr id="row727120511728"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p1327110515216"><a name="p1327110515216"></a><a name="p1327110515216"></a>step</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p9271125114215"><a name="p9271125114215"></a><a name="p9271125114215"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.99%" headers="mcps1.1.6.1.3 "><p id="p152711751328"><a name="p152711751328"></a><a name="p152711751328"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p id="p72711251121"><a name="p72711251121"></a><a name="p72711251121"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.18%" headers="mcps1.1.6.1.5 "><p id="p11271195118217"><a name="p11271195118217"></a><a name="p11271195118217"></a>设置Slider滑动跳动值，当设置相应的step时，Slider为间歇滑动。</p>
    </td>
    </tr>
    <tr id="row153190591429"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p14319459729"><a name="p14319459729"></a><a name="p14319459729"></a>style</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p1131911595213"><a name="p1131911595213"></a><a name="p1131911595213"></a><a href="#li1754841215312">SliderStyle</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.99%" headers="mcps1.1.6.1.3 "><p id="p23195591625"><a name="p23195591625"></a><a name="p23195591625"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p id="p1031915594211"><a name="p1031915594211"></a><a name="p1031915594211"></a>Outset</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.18%" headers="mcps1.1.6.1.5 "><p id="p14319959825"><a name="p14319959825"></a><a name="p14319959825"></a>设置Slider的滑块样式。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li1754841215312"></a>SliderStyle枚举说明

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>OutSet</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>滑块在滑轨上。</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>InSet</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>滑块在滑轨内。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 属性<a name="section18430105671014"></a>

<a name="table181736291110"></a>
<table><thead align="left"><tr id="row1117442161117"><th class="cellrowborder" valign="top" width="18.72%" id="mcps1.1.5.1.1"><p id="p2017411217117"><a name="p2017411217117"></a><a name="p2017411217117"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.33%" id="mcps1.1.5.1.2"><p id="p1517432171118"><a name="p1517432171118"></a><a name="p1517432171118"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="17.62%" id="mcps1.1.5.1.3"><p id="p11174326110"><a name="p11174326110"></a><a name="p11174326110"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="47.33%" id="mcps1.1.5.1.4"><p id="p20174826118"><a name="p20174826118"></a><a name="p20174826118"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1007mcpsimp"><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p id="p1009mcpsimp"><a name="p1009mcpsimp"></a><a name="p1009mcpsimp"></a>blockColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p id="p1011mcpsimp"><a name="p1011mcpsimp"></a><a name="p1011mcpsimp"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p id="p1013mcpsimp"><a name="p1013mcpsimp"></a><a name="p1013mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p id="p218541705511"><a name="p218541705511"></a><a name="p218541705511"></a>设置滑块的颜色。</p>
</td>
</tr>
<tr id="row173321411165311"><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p id="p1332201195316"><a name="p1332201195316"></a><a name="p1332201195316"></a>trackColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p id="p43327112538"><a name="p43327112538"></a><a name="p43327112538"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p id="p193322011185315"><a name="p193322011185315"></a><a name="p193322011185315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p id="p68256235554"><a name="p68256235554"></a><a name="p68256235554"></a>设置滑轨的背景颜色。</p>
</td>
</tr>
<tr id="row4821201513537"><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p id="p2822615195315"><a name="p2822615195315"></a><a name="p2822615195315"></a>selectedColor</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p id="p198221415155318"><a name="p198221415155318"></a><a name="p198221415155318"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p id="p19822191511533"><a name="p19822191511533"></a><a name="p19822191511533"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p id="p12822151515311"><a name="p12822151515311"></a><a name="p12822151515311"></a>设置滑轨的已滑动颜色。</p>
</td>
</tr>
<tr id="row752815895218"><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p id="p185284589526"><a name="p185284589526"></a><a name="p185284589526"></a>showSteps</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p id="p752814585523"><a name="p752814585523"></a><a name="p752814585523"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p id="p452918585527"><a name="p452918585527"></a><a name="p452918585527"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p id="p16529858195210"><a name="p16529858195210"></a><a name="p16529858195210"></a>设置当前是否显示步长刻度值。</p>
</td>
</tr>
<tr id="row15632175145210"><td class="cellrowborder" valign="top" width="18.72%" headers="mcps1.1.5.1.1 "><p id="p1863395113526"><a name="p1863395113526"></a><a name="p1863395113526"></a>showTips</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.5.1.2 "><p id="p10633165175217"><a name="p10633165175217"></a><a name="p10633165175217"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="17.62%" headers="mcps1.1.5.1.3 "><p id="p2633125175210"><a name="p2633125175210"></a><a name="p2633125175210"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="47.33%" headers="mcps1.1.5.1.4 "><p id="p9634125116523"><a name="p9634125116523"></a><a name="p9634125116523"></a>设置滑动时是否显示气泡提示百分比。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section449664852016"></a>

通用事件仅支持：OnAppear，OnDisAppear。

<a name="table952mcpsimp"></a>
<table><thead align="left"><tr id="row959mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p963mcpsimp"><a name="p963mcpsimp"></a><a name="p963mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p967mcpsimp"><a name="p967mcpsimp"></a><a name="p967mcpsimp"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row163041291058"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p1352619001912"><a name="p1352619001912"></a><a name="p1352619001912"></a>onChange(callback: (value: number, mode: <a href="#li164030311374">SliderChangeMode</a>) =&gt; void）</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p18583122017217"><a name="p18583122017217"></a><a name="p18583122017217"></a>Slider滑动时触发事件回调。</p>
<p id="p167349586143"><a name="p167349586143"></a><a name="p167349586143"></a>value：当前进度值。</p>
<p id="p971045311329"><a name="p971045311329"></a><a name="p971045311329"></a>mode：拖动状态。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li164030311374"></a>SliderChangeMode枚举说明

    <a name="table1256714217311"></a>
    <table><thead align="left"><tr id="row356762110317"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1056719211930"><a name="p1056719211930"></a><a name="p1056719211930"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p18567221931"><a name="p18567221931"></a><a name="p18567221931"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1356772112319"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p756720210315"><a name="p756720210315"></a><a name="p756720210315"></a>Begin</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p3567142116311"><a name="p3567142116311"></a><a name="p3567142116311"></a>用户开始拖动滑块。</p>
    </td>
    </tr>
    <tr id="row14567102116319"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1156732110311"><a name="p1156732110311"></a><a name="p1156732110311"></a>Moving</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p356716211030"><a name="p356716211030"></a><a name="p356716211030"></a>用户拖动滑块中。</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>End</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>用户结束拖动滑块。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section13800193662114"></a>

```
@Entry
@Component
struct SliderExample {
  @State outSetValue: number = 40
  @State inSetValue: number = 40

  build() {
    Column({ space: 5 }) {
      Text('slider out set').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row() {
        Slider({
          value: this.outSetValue,
          min: 0,
          max: 100,
          step: 1,
          style: SliderStyle.OutSet
        })
        .blockColor(Color.Blue)
        .trackColor(Color.Gray)
        .selectedColor(Color.Blue)
        .showSteps(true)
        .showTips(true)
        .onChange((value: number, mode: SliderChangeMode) => {
          this.outSetValue = value
          console.info('value:' + value + 'mode:' + mode.toString())
        })
        Text(this.outSetValue.toFixed(0)).fontSize(16)
      }
      .padding({ top: 50 })
      .width('80%')

      Text('slider in set').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row() {
        Slider({
          value: this.inSetValue,
          min: 0,
          max: 100,
          step: 1,
          style: SliderStyle.InSet
        })
        .blockColor(0xCCCCCC)
        .trackColor(Color.Black)
        .selectedColor(0xCCCCCC)
        .showSteps(false)
        .showTips(false)
        .onChange((value: number, mode: SliderChangeMode) => {
          this.inSetValue = value
          console.info('value:' + value + 'mode:' + mode.toString())
        })
        Text(this.inSetValue.toFixed(0)).fontSize(16)
      }
      .width('80%')
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/sider.gif)

