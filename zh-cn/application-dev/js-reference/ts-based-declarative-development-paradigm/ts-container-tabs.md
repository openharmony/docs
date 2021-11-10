# Tabs<a name="ZH-CN_TOPIC_0000001166728941"></a>

一种可以通过页签进行内容视图切换的容器组件，每个页签对应一个内容视图。

## 支持设备<a name="section322851519172"></a>

<a name="table857714145377"></a>
<table><thead align="left"><tr id="row55778146373"><th class="cellrowborder" valign="top" width="23.66106080206986%" id="mcps1.1.5.1.1"><p id="p7577141417376"><a name="p7577141417376"></a><a name="p7577141417376"></a>手机</p>
</th>
<th class="cellrowborder" valign="top" width="26.3130659767141%" id="mcps1.1.5.1.2"><p id="p487719816463"><a name="p487719816463"></a><a name="p487719816463"></a>平板</p>
</th>
<th class="cellrowborder" valign="top" width="24.63130659767141%" id="mcps1.1.5.1.3"><p id="p135771614203720"><a name="p135771614203720"></a><a name="p135771614203720"></a>智慧屏</p>
</th>
<th class="cellrowborder" valign="top" width="25.39456662354463%" id="mcps1.1.5.1.4"><p id="p25772014133712"><a name="p25772014133712"></a><a name="p25772014133712"></a>智能穿戴</p>
</th>
</tr>
</thead>
<tbody><tr id="row8578151423715"><td class="cellrowborder" valign="top" width="23.66106080206986%" headers="mcps1.1.5.1.1 "><p id="p65782014203718"><a name="p65782014203718"></a><a name="p65782014203718"></a>支持</p>
</td>
<td class="cellrowborder" valign="top" width="26.3130659767141%" headers="mcps1.1.5.1.2 "><p id="p148771182469"><a name="p148771182469"></a><a name="p148771182469"></a>支持</p>
</td>
<td class="cellrowborder" valign="top" width="24.63130659767141%" headers="mcps1.1.5.1.3 "><p id="p45783141377"><a name="p45783141377"></a><a name="p45783141377"></a>不支持</p>
</td>
<td class="cellrowborder" valign="top" width="25.39456662354463%" headers="mcps1.1.5.1.4 "><p id="p11578161443718"><a name="p11578161443718"></a><a name="p11578161443718"></a>不支持</p>
</td>
</tr>
</tbody>
</table>

## 权限列表<a name="section988262631714"></a>

无

## 子组件<a name="section5989144051714"></a>

包含子组件[TabContent](ts-container-tabcontent.md)。

## 接口说明<a name="section97451749121712"></a>

Tabs\(value: \{barPosition?: BarPosition, index?: number, controller?:  [TabsController](#section104288910399)\}\)

-   参数

    <a name="table193606194544"></a>
    <table><thead align="left"><tr id="row536071910541"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p436112199544"><a name="p436112199544"></a><a name="p436112199544"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.3%" id="mcps1.1.6.1.2"><p id="p19361319115410"><a name="p19361319115410"></a><a name="p19361319115410"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.77%" id="mcps1.1.6.1.3"><p id="p9361201975417"><a name="p9361201975417"></a><a name="p9361201975417"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.6%" id="mcps1.1.6.1.4"><p id="p43611199542"><a name="p43611199542"></a><a name="p43611199542"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p id="p1136141975419"><a name="p1136141975419"></a><a name="p1136141975419"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10361101915545"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p1361119155417"><a name="p1361119155417"></a><a name="p1361119155417"></a>barPosition</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.1.6.1.2 "><p id="p8361181913548"><a name="p8361181913548"></a><a name="p8361181913548"></a><a href="#li15340346135115">BarPosition</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.77%" headers="mcps1.1.6.1.3 "><p id="p153611119195411"><a name="p153611119195411"></a><a name="p153611119195411"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 "><p id="p1436114193546"><a name="p1436114193546"></a><a name="p1436114193546"></a>Start</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p328155017218"><a name="p328155017218"></a><a name="p328155017218"></a>指定页签位置来创建Tabs容器组件。</p>
    </td>
    </tr>
    <tr id="row1860154012417"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p108611240343"><a name="p108611240343"></a><a name="p108611240343"></a>index</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.1.6.1.2 "><p id="p17861154015414"><a name="p17861154015414"></a><a name="p17861154015414"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.77%" headers="mcps1.1.6.1.3 "><p id="p986119408419"><a name="p986119408419"></a><a name="p986119408419"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 "><p id="p1186174019416"><a name="p1186174019416"></a><a name="p1186174019416"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p986110401845"><a name="p986110401845"></a><a name="p986110401845"></a>指定初次初始页签索引。</p>
    </td>
    </tr>
    <tr id="row1559133357"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p19591536520"><a name="p19591536520"></a><a name="p19591536520"></a>controller</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.3%" headers="mcps1.1.6.1.2 "><p id="p659116317510"><a name="p659116317510"></a><a name="p659116317510"></a><a href="#section104288910399">TabsController</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.77%" headers="mcps1.1.6.1.3 "><p id="p165912037510"><a name="p165912037510"></a><a name="p165912037510"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 ">&nbsp;&nbsp;</td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p959117310513"><a name="p959117310513"></a><a name="p959117310513"></a>设置Tabs控制器。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li15340346135115"></a>BarPosition枚举说明

    <a name="table2319185192616"></a>
    <table><thead align="left"><tr id="row2032019513262"><th class="cellrowborder" valign="top" width="28.360000000000003%" id="mcps1.1.3.1.1"><p id="p7320551132614"><a name="p7320551132614"></a><a name="p7320551132614"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="71.64%" id="mcps1.1.3.1.2"><p id="p9320951152619"><a name="p9320951152619"></a><a name="p9320951152619"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row73201351192611"><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p id="p10400151015275"><a name="p10400151015275"></a><a name="p10400151015275"></a>Start</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p id="p12320165115268"><a name="p12320165115268"></a><a name="p12320165115268"></a>vertical属性方法设置为true时，页签位于容器左侧；vertical属性方法设置为false时，页签位于容器顶部。</p>
    </td>
    </tr>
    <tr id="row58043114275"><td class="cellrowborder" valign="top" width="28.360000000000003%" headers="mcps1.1.3.1.1 "><p id="p98043182720"><a name="p98043182720"></a><a name="p98043182720"></a>End</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.64%" headers="mcps1.1.3.1.2 "><p id="p1098012362918"><a name="p1098012362918"></a><a name="p1098012362918"></a>vertical属性方法设置为true时，页签位于容器右侧；vertical属性方法设置为false时，页签位于容器底部。</p>
    </td>
    </tr>
    </tbody>
    </table>


### TabsController<a name="section104288910399"></a>

Tabs组件的控制器，用于控制Tabs组件进行页签切换。

<a name="table18201749144213"></a>
<table><thead align="left"><tr id="row122017496424"><th class="cellrowborder" valign="top" width="26.99%" id="mcps1.1.3.1.1"><p id="p132014497426"><a name="p132014497426"></a><a name="p132014497426"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="73.00999999999999%" id="mcps1.1.3.1.2"><p id="p1520111494422"><a name="p1520111494422"></a><a name="p1520111494422"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row142019496423"><td class="cellrowborder" valign="top" width="26.99%" headers="mcps1.1.3.1.1 "><p id="p19183105594516"><a name="p19183105594516"></a><a name="p19183105594516"></a>changeIndex(value: number): void</p>
</td>
<td class="cellrowborder" valign="top" width="73.00999999999999%" headers="mcps1.1.3.1.2 "><p id="p122511258467"><a name="p122511258467"></a><a name="p122511258467"></a>控制Tabs切换到指定页签，index: 页签在Tabs里的索引值，索引值从0开始。</p>
</td>
</tr>
</tbody>
</table>

## 属性<a name="section1738516911810"></a>

<a name="table1854mcpsimp"></a>
<table><thead align="left"><tr id="row1861mcpsimp"><th class="cellrowborder" valign="top" width="17.82%" id="mcps1.1.5.1.1"><p id="p1863mcpsimp"><a name="p1863mcpsimp"></a><a name="p1863mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.840000000000002%" id="mcps1.1.5.1.2"><p id="p1865mcpsimp"><a name="p1865mcpsimp"></a><a name="p1865mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="19.75%" id="mcps1.1.5.1.3"><p id="p1867mcpsimp"><a name="p1867mcpsimp"></a><a name="p1867mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="46.589999999999996%" id="mcps1.1.5.1.4"><p id="p1869mcpsimp"><a name="p1869mcpsimp"></a><a name="p1869mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1879mcpsimp"><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p id="p10537mcpsimp"><a name="p10537mcpsimp"></a><a name="p10537mcpsimp"></a>vertical</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p id="p10539mcpsimp"><a name="p10539mcpsimp"></a><a name="p10539mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p id="p10541mcpsimp"><a name="p10541mcpsimp"></a><a name="p10541mcpsimp"></a>是否为纵向Tab，默认为false。</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p id="p17139154113369"><a name="p17139154113369"></a><a name="p17139154113369"></a>是否为纵向Tab，默认为false。</p>
</td>
</tr>
<tr id="row1888mcpsimp"><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p id="p10544mcpsimp"><a name="p10544mcpsimp"></a><a name="p10544mcpsimp"></a>scrollable</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p id="p10546mcpsimp"><a name="p10546mcpsimp"></a><a name="p10546mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p id="p10548mcpsimp"><a name="p10548mcpsimp"></a><a name="p10548mcpsimp"></a>是否可以通过左右滑动进行页面切换，默认为true。</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p id="p29371214364"><a name="p29371214364"></a><a name="p29371214364"></a>是否可以通过左右滑动进行页面切换，默认为true。</p>
</td>
</tr>
<tr id="row1897mcpsimp"><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p id="p10551mcpsimp"><a name="p10551mcpsimp"></a><a name="p10551mcpsimp"></a>barMode</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p id="p10553mcpsimp"><a name="p10553mcpsimp"></a><a name="p10553mcpsimp"></a><a href="#li386615395316">BarMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p id="p10555mcpsimp"><a name="p10555mcpsimp"></a><a name="p10555mcpsimp"></a>TabBar布局模式。</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p id="p1905mcpsimp"><a name="p1905mcpsimp"></a><a name="p1905mcpsimp"></a>TabBar布局模式。</p>
</td>
</tr>
<tr id="row1906mcpsimp"><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p id="p10558mcpsimp"><a name="p10558mcpsimp"></a><a name="p10558mcpsimp"></a>barWidth</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p id="p10560mcpsimp"><a name="p10560mcpsimp"></a><a name="p10560mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p id="p10562mcpsimp"><a name="p10562mcpsimp"></a><a name="p10562mcpsimp"></a>TabBar的宽度值，不设置时使用系统主题中的默认值。</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p id="p1914mcpsimp"><a name="p1914mcpsimp"></a><a name="p1914mcpsimp"></a>TabBar的宽度值，不设置时使用系统主题中的默认值。</p>
</td>
</tr>
<tr id="row1915mcpsimp"><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p id="p10565mcpsimp"><a name="p10565mcpsimp"></a><a name="p10565mcpsimp"></a>barHeight</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p id="p10567mcpsimp"><a name="p10567mcpsimp"></a><a name="p10567mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p id="p10569mcpsimp"><a name="p10569mcpsimp"></a><a name="p10569mcpsimp"></a>TabBar的高度值，不设置时使用系统主题中的默认值。</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p id="p1923mcpsimp"><a name="p1923mcpsimp"></a><a name="p1923mcpsimp"></a>TabBar的高度值，不设置时使用系统主题中的默认值<strong id="b18699431175313"><a name="b18699431175313"></a><a name="b18699431175313"></a>。</strong></p>
</td>
</tr>
<tr id="row195881158686"><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p id="p195883581813"><a name="p195883581813"></a><a name="p195883581813"></a>animationDuration</p>
</td>
<td class="cellrowborder" valign="top" width="15.840000000000002%" headers="mcps1.1.5.1.2 "><p id="p258815586820"><a name="p258815586820"></a><a name="p258815586820"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="19.75%" headers="mcps1.1.5.1.3 "><p id="p185891858089"><a name="p185891858089"></a><a name="p185891858089"></a>200</p>
</td>
<td class="cellrowborder" valign="top" width="46.589999999999996%" headers="mcps1.1.5.1.4 "><p id="p195891558888"><a name="p195891558888"></a><a name="p195891558888"></a>TabContent滑动动画时长。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li386615395316"></a>BarMode枚举说明

    <a name="table12144170154116"></a>
    <table><thead align="left"><tr id="row1314430184118"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1614414014416"><a name="p1614414014416"></a><a name="p1614414014416"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1314415074113"><a name="p1314415074113"></a><a name="p1314415074113"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row61441505417"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p191443034117"><a name="p191443034117"></a><a name="p191443034117"></a>Scrollable</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p121447017412"><a name="p121447017412"></a><a name="p121447017412"></a>TabBar使用实际布局宽度, 超过总长度后可滑动。</p>
    </td>
    </tr>
    <tr id="row20144801418"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p17145110194110"><a name="p17145110194110"></a><a name="p17145110194110"></a>Fixed</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p171454015415"><a name="p171454015415"></a><a name="p171454015415"></a>所有TabBar平均分配宽度。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section6741113101919"></a>

<a name="table1934mcpsimp"></a>
<table><thead align="left"><tr id="row1940mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p1944mcpsimp"><a name="p1944mcpsimp"></a><a name="p1944mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p1946mcpsimp"><a name="p1946mcpsimp"></a><a name="p1946mcpsimp"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1947mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p1949mcpsimp"><a name="p1949mcpsimp"></a><a name="p1949mcpsimp"></a>onChange(callback: (index: number) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p10594mcpsimp"><a name="p10594mcpsimp"></a><a name="p10594mcpsimp"></a>Tab页签切换后触发的事件。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section1131255321814"></a>

```
@Entry
@Component
struct TabsExample {
  private controller: TabsController = new TabsController()

  build() {
    Column() {
      Tabs({ barPosition: BarPosition.Start, index: 1, controller: this.controller }) {
        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Pink)
        }.tabBar('pink')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Yellow)
        }.tabBar('yellow')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Blue)
        }.tabBar('blue')

        TabContent() {
          Column().width('100%').height('100%').backgroundColor(Color.Green)
        }.tabBar('green')
      }
      .vertical(true).scrollable(true).barMode(BarMode.Fixed)
      .barWidth(70).barHeight(150).animationDuration(400)
      .onChange((index: number) => {
        console.info(index.toString())
      })
      .width('90%').backgroundColor(0xF5F5F5)
    }.width('100%').height(150).margin({ top: 5 })
  }
}
```

![](figures/Tabs.gif)

