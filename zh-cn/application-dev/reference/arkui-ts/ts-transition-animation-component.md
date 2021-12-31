# 组件内转场<a name="ZH-CN_TOPIC_0000001237715077"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

组件转场主要通过transition属性进行配置转场参数，在组件插入和删除时进行过渡动效，主要用于容器组件子组件插入删除时提升用户体验（需要配合animateTo才能生效，动效时长、曲线、延时跟随animateTo中的配置）。

## 属性<a name="section96162324014"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.36%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.64%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.200000000000001%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="54.800000000000004%" id="mcps1.1.5.1.4"><p>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.5.1.1 "><p>transition</p>
</td>
<td class="cellrowborder" valign="top" width="15.64%" headers="mcps1.1.5.1.2 "><p>Object</p>
</td>
<td class="cellrowborder" valign="top" width="13.200000000000001%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="54.800000000000004%" headers="mcps1.1.5.1.4 "><p>所有参数均为可选参数，详细描述见<a href="#li735275511597">transition入参说明</a>。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li735275511597"></a>transition入参说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="18.11%" id="mcps1.1.6.1.1"><p>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.830000000000002%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.690000000000001%" id="mcps1.1.6.1.3"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.68%" id="mcps1.1.6.1.4"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.69%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="18.11%" headers="mcps1.1.6.1.1 "><p>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.830000000000002%" headers="mcps1.1.6.1.2 "><p><a href="#li15581632802">TransitionType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.1.6.1.3 "><p>All</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.68%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.6.1.5 "><p>默认包括组件新增和删除。</p>
    <div class="note"><span class="notetitle"> 说明： </span><div class="notebody"><p>不指定Type时说明插入删除使用同一种效果。</p>
    </div></div>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="18.11%" headers="mcps1.1.6.1.1 "><p>opacity</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.830000000000002%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.1.6.1.3 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.68%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.6.1.5 "><p>设置组件转场时的透明度效果，为插入时起点和删除时终点的值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="18.11%" headers="mcps1.1.6.1.1 "><p>translate</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.830000000000002%" headers="mcps1.1.6.1.2 "><p>{</p>
    <p>x? : number,</p>
    <p>y? : number,</p>
    <p>z? : number</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.1.6.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.68%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.6.1.5 "><p>设置组件转场时的平移效果，为插入时起点和删除时终点的值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="18.11%" headers="mcps1.1.6.1.1 "><p>scale</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.830000000000002%" headers="mcps1.1.6.1.2 "><p>{</p>
    <p>x? : number,</p>
    <p>y? : number,</p>
    <p>z? : number,</p>
    <p>centerX? : number,</p>
    <p>centerY? : number</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.1.6.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.68%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.6.1.5 "><p>设置组件转场时的缩放效果，为插入时起点和删除时终点的值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="18.11%" headers="mcps1.1.6.1.1 "><p>rotate</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.830000000000002%" headers="mcps1.1.6.1.2 "><p>{</p>
    <p>x?: number,</p>
    <p>y?: number,</p>
    <p>z?: number,</p>
    <p>angle?: Angle,</p>
    <p>centerX?: Length,</p>
    <p>centerY?: Length</p>
    <p>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.1.6.1.3 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.68%" headers="mcps1.1.6.1.4 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.6.1.5 "><p>设置组件转场时的旋转效果，为插入时起点和删除时终点的值。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li15581632802"></a>TransitionType枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>All</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>指定当前的Transition动效生效在组件的所有变化场景。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Insert</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>指定当前的Transition动效生效在组件的插入场景。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Delete</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>指定当前的Transition动效生效在组件的删除场景。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section1137330124017"></a>

示例功能通过一个Button控制第二个Button的出现和消失，并通过transition配置第二个Button出现和消失的过场动画。

```
@Entry
@Component
struct TransitionExample {
  @State btn1: boolean = false
  @State show: string = "show"
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center,}) {
      Button(this.show).width(80).height(30).backgroundColor(0x317aff).margin({bottom:50})
        .onClick(() => {
          animateTo({ duration: 1000 }, () => {
            this.btn1 = !this.btn1
            if(this.btn1){
              this.show = "hide"
            }else{
              this.show = "show"
            }
          })
        })
      if (this.btn1) {
        // 插入和删除配置为不同的过渡效果
        Button() {
          Image($r('app.media.bg1')).width("80%").height(300)
        }.transition({ type: TransitionType.Insert, scale : {x:0,y:1.0} })
        .transition({ type: TransitionType.Delete, scale: { x: 1.0, y: 0.0 } })
      }
    }.height(400).width("100%").padding({top:100})
  }
}
```

![](figures/Transition.gif)

