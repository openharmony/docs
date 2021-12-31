# 插值计算<a name="ZH-CN_TOPIC_0000001237475061"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块<a name="section377963175114"></a>

```
import curves from '@ohos.curves'
```

## 权限<a name="section1455919446525"></a>

无

## curves.init<a name="section10551016104218"></a>

init\(curve?: Curve\): Object

插值曲线的初始化函数，可以根据入参创建一个插值曲线对象。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.71%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.469999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.68%" id="mcps1.1.6.1.5"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>curve</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>Curve</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>曲线对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    曲线对象Object。


## curves.steps<a name="section14558238104310"></a>

steps\(count: number, end: boolean\): Object

构造阶梯曲线对象。

-   参数：

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.71%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.469999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.68%" id="mcps1.1.6.1.5"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>count</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>阶梯的数量，需要为正整数。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.71%" headers="mcps1.1.6.1.1 "><p>end</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.469999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.68%" headers="mcps1.1.6.1.5 "><p>在每个间隔的起点或是终点发生阶跃变化 ，默认值为true，即在终点发生阶跃变化。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    曲线对象Object。


## curves.cubicBezier<a name="section548233515442"></a>

cubicBezier\(x1: number, y1: number, x2: number, y2: number\): Object

构造三阶贝塞尔曲线对象，曲线的值必须处于0-1之间。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>x1</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>确定贝塞尔曲线第一点横坐标。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>y1</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>确定贝塞尔曲线第一点纵坐标。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>x2</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>确定贝塞尔曲线第二点横坐标。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>y2</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>确定贝塞尔曲线第二点纵坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    曲线对象Object。


## curves.spring<a name="section185801926114514"></a>

spring\(velocity: number, mass: number, stiffness: number, damping: number\): Object

构造弹簧曲线对象。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>velocity</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>初始速度。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>mass</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>质量。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>stiffness</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>刚度。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p>damping</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p>阻尼。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    曲线对象Object。


## 示例<a name="section75051320581"></a>

```
import Curves from '@ohos.curves'
let curve1 = Curves.init() // 创建一个默认线性插值曲线
let curve2 = Curves.init(Curve.EaseIn) // 创建一个默认先慢后快插值曲线
let curve3 = Curves.spring(100, 1, 228, 30) // 创建一个弹簧插值曲线
let curve3 = Curves.cubicBezier(0.1, 0.0, 0.1, 1.0) // 创建一个三阶贝塞尔曲线
```

曲线对象只能通过上面的接口创建。

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="39.26%" id="mcps1.1.3.1.1"><p>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="60.74%" id="mcps1.1.3.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="39.26%" headers="mcps1.1.3.1.1 "><p>interpolate(time: number): number</p>
</td>
<td class="cellrowborder" valign="top" width="60.74%" headers="mcps1.1.3.1.2 "><p>插值曲线的插值计算函数，可以通过传入的归一化时间参数返回当前的插值。</p>
<p>time: 当前的归一化时间参数，有效值范围0到1。</p>
<p>返回归一化time时间点对应的曲线插值。</p>
</td>
</tr>
</tbody>
</table>

-   示例

    ```
    import Curves from '@ohos.curves'
    let curve = Curves.init(Curve.EaseIn) // 创建一个默认先慢后快插值曲线
    let value: number = curve.interpolate(0.5) // 计算得到时间到一半时的插值
    ```


## 整体示例<a name="section839432815193"></a>

```
import Curves from '@ohos.curves'
@Entry
@Component
struct ImageComponent {
  @State widthSize: number = 200
  @State heightSize: number = 200
  build() {
    Column() {
      Text()
        .margin({top:100})
        .width(this.widthSize)
        .height(this.heightSize)
        .backgroundColor(Color.Red)
        .onClick(()=> {
          let curve = Curves.cubicBezier(0.25, 0.1, 0.25, 1.0);
          this.widthSize = curve.interpolate(0.5) * this.widthSize;
          this.heightSize = curve.interpolate(0.5) * this.heightSize;
        })
        .animation({duration: 2000 , curve: Curves.spring(0.25, 0.1, 0.25, 1.0)})
    }.width("100%").height("100%")
  }
}
```

![](figures/5.gif)

