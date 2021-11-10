# 共享元素转场<a name="ZH-CN_TOPIC_0000001166727423"></a>

共享元素转场支持页面间的转场，如当前页面的图片转场至下一页面中。

## 属性<a name="section35901546194017"></a>

<a name="table10667105011521"></a>
<table><thead align="left"><tr id="row373545015217"><th class="cellrowborder" valign="top" width="17.24%" id="mcps1.1.5.1.1"><p id="p19735175011522"><a name="p19735175011522"></a><a name="p19735175011522"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.880000000000003%" id="mcps1.1.5.1.2"><p id="p7735175085210"><a name="p7735175085210"></a><a name="p7735175085210"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="9.91%" id="mcps1.1.5.1.3"><p id="p2735350115217"><a name="p2735350115217"></a><a name="p2735350115217"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="51.970000000000006%" id="mcps1.1.5.1.4"><p id="p10735135018523"><a name="p10735135018523"></a><a name="p10735135018523"></a>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row8735115014526"><td class="cellrowborder" valign="top" width="17.24%" headers="mcps1.1.5.1.1 "><p id="p77355509528"><a name="p77355509528"></a><a name="p77355509528"></a>sharedTransition</p>
</td>
<td class="cellrowborder" valign="top" width="20.880000000000003%" headers="mcps1.1.5.1.2 "><p id="p0573102927"><a name="p0573102927"></a><a name="p0573102927"></a>id: string,</p>
<p id="p1536984417195"><a name="p1536984417195"></a><a name="p1536984417195"></a><a href="#li12109141415716">options</a>?: Object</p>
</td>
<td class="cellrowborder" valign="top" width="9.91%" headers="mcps1.1.5.1.3 "><p id="p1373516508529"><a name="p1373516508529"></a><a name="p1373516508529"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.1.5.1.4 "><p id="p6735650155210"><a name="p6735650155210"></a><a name="p6735650155210"></a>两个页面的组件配置为同一个id，则转场过程中会进行共享元素转场，配置为空字符串时不会有共享元素转场效果。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li12109141415716"></a>options参数说明

    <a name="table46771650145219"></a>
    <table><thead align="left"><tr id="row13735125055220"><th class="cellrowborder" valign="top" width="13.309999999999999%" id="mcps1.1.6.1.1"><p id="p273585095220"><a name="p273585095220"></a><a name="p273585095220"></a>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.59%" id="mcps1.1.6.1.2"><p id="p773525012528"><a name="p773525012528"></a><a name="p773525012528"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.99%" id="mcps1.1.6.1.3"><p id="p11735205035220"><a name="p11735205035220"></a><a name="p11735205035220"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.340000000000001%" id="mcps1.1.6.1.4"><p id="p137357503523"><a name="p137357503523"></a><a name="p137357503523"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.769999999999996%" id="mcps1.1.6.1.5"><p id="p9736250195214"><a name="p9736250195214"></a><a name="p9736250195214"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1736115045217"><td class="cellrowborder" valign="top" width="13.309999999999999%" headers="mcps1.1.6.1.1 "><p id="p117364507524"><a name="p117364507524"></a><a name="p117364507524"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.59%" headers="mcps1.1.6.1.2 "><p id="p17736950105212"><a name="p17736950105212"></a><a name="p17736950105212"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.6.1.3 "><p id="p473616508525"><a name="p473616508525"></a><a name="p473616508525"></a>1000</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.340000000000001%" headers="mcps1.1.6.1.4 "><p id="p17361250135213"><a name="p17361250135213"></a><a name="p17361250135213"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.769999999999996%" headers="mcps1.1.6.1.5 "><p id="p57361506525"><a name="p57361506525"></a><a name="p57361506525"></a>单位为毫秒，默认动画时长为1000毫秒。</p>
    </td>
    </tr>
    <tr id="row873625025217"><td class="cellrowborder" valign="top" width="13.309999999999999%" headers="mcps1.1.6.1.1 "><p id="p4736165095217"><a name="p4736165095217"></a><a name="p4736165095217"></a>curve</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.59%" headers="mcps1.1.6.1.2 "><p id="p1973614508526"><a name="p1973614508526"></a><a name="p1973614508526"></a>Curve | Curves</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.6.1.3 "><p id="p1773617505529"><a name="p1773617505529"></a><a name="p1773617505529"></a>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.340000000000001%" headers="mcps1.1.6.1.4 "><p id="p27361050135213"><a name="p27361050135213"></a><a name="p27361050135213"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.769999999999996%" headers="mcps1.1.6.1.5 "><p id="p7736175016521"><a name="p7736175016521"></a><a name="p7736175016521"></a>默认曲线为线性，有效值参见Curve说明。</p>
    </td>
    </tr>
    <tr id="row1473615015525"><td class="cellrowborder" valign="top" width="13.309999999999999%" headers="mcps1.1.6.1.1 "><p id="p19736250175212"><a name="p19736250175212"></a><a name="p19736250175212"></a>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.59%" headers="mcps1.1.6.1.2 "><p id="p07361950105215"><a name="p07361950105215"></a><a name="p07361950105215"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.6.1.3 "><p id="p9736950185217"><a name="p9736950185217"></a><a name="p9736950185217"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.340000000000001%" headers="mcps1.1.6.1.4 "><p id="p1473618508529"><a name="p1473618508529"></a><a name="p1473618508529"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.769999999999996%" headers="mcps1.1.6.1.5 "><p id="p1173645085210"><a name="p1173645085210"></a><a name="p1173645085210"></a>单位为毫秒，默认不延时播放。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section34004854112"></a>

示例功能为两个页面，共享元素转场页面图片点击后转场至页面B的图片。

```
@Entry
@Component
struct SharedTransitionExample {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false

  build() {
    List() {
      ListItem() {
        Row() {
          Navigator({ target: 'pages/common/Animation/transAnimation/PageB', type: NavigationType.Push }) {
            Image($r('app.media.ic_health_heart')).width(50).height(50)
              .sharedTransition('sharedImage1', { duration: 800, curve: Curve.Linear, delay: 100 })
          }.padding({ left: 10 })
          .onClick(() => {
            this.active = true
          })

          Text('SharedTransition').width(80).height(80).textAlign(TextAlign.Center)
        }
      }
    }
  }
}
```

```
// PageB
@Entry
@Component
struct BExample {
  build() {
    Stack() {
      Image($r('app.media.ic_health_heart')).width(150).height(150).sharedTransition('sharedImage1')
    }.width('100%').height(400)
  }
}
```

![](figures/SharedTransition.gif)

