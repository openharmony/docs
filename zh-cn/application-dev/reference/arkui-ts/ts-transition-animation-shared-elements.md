# 共享元素转场<a name="ZH-CN_TOPIC_0000001193075084"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

共享元素转场支持页面间的转场，如当前页面的图片转场至下一页面中。

## 属性<a name="section35901546194017"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.24%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.880000000000003%" id="mcps1.1.5.1.2"><p>参数</p>
</th>
<th class="cellrowborder" valign="top" width="9.91%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="51.970000000000006%" id="mcps1.1.5.1.4"><p>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17.24%" headers="mcps1.1.5.1.1 "><p>sharedTransition</p>
</td>
<td class="cellrowborder" valign="top" width="20.880000000000003%" headers="mcps1.1.5.1.2 "><p>id: string,</p>
<p><a href="#li12109141415716">options</a>?: Object</p>
</td>
<td class="cellrowborder" valign="top" width="9.91%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="51.970000000000006%" headers="mcps1.1.5.1.4 "><p>两个页面的组件配置为同一个id，则转场过程中会进行共享元素转场，配置为空字符串时不会有共享元素转场效果。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li12109141415716"></a>options参数说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="13.309999999999999%" id="mcps1.1.6.1.1"><p>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.59%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.99%" id="mcps1.1.6.1.3"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.340000000000001%" id="mcps1.1.6.1.4"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.769999999999996%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="13.309999999999999%" headers="mcps1.1.6.1.1 "><p>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.59%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.6.1.3 "><p>1000</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.340000000000001%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.769999999999996%" headers="mcps1.1.6.1.5 "><p>单位为毫秒，默认动画时长为1000毫秒。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.309999999999999%" headers="mcps1.1.6.1.1 "><p>curve</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.59%" headers="mcps1.1.6.1.2 "><p>Curve | Curves</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.6.1.3 "><p>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.340000000000001%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.769999999999996%" headers="mcps1.1.6.1.5 "><p>默认曲线为线性，有效值参见Curve说明。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="13.309999999999999%" headers="mcps1.1.6.1.1 "><p>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.59%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.6.1.3 "><p>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.340000000000001%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.769999999999996%" headers="mcps1.1.6.1.5 "><p>单位为毫秒，默认不延时播放。</p>
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

