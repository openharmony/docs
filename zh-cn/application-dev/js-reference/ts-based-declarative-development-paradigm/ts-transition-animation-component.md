# 组件内转场<a name="ZH-CN_TOPIC_0000001119768666"></a>

组件转场主要通过transition属性进行配置转场参数，在组件插入和删除时进行过渡动效，主要用于容器组件子组件插入删除时提升用户体验（需要配合animateTo才能生效，动效时长、曲线、延时跟随animateTo中的配置）。

## 属性<a name="section96162324014"></a>

<a name="table16771718327"></a>
<table><thead align="left"><tr id="row77752182218"><th class="cellrowborder" valign="top" width="16.36%" id="mcps1.1.5.1.1"><p id="p13775141819212"><a name="p13775141819212"></a><a name="p13775141819212"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.64%" id="mcps1.1.5.1.2"><p id="p77758188212"><a name="p77758188212"></a><a name="p77758188212"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="13.200000000000001%" id="mcps1.1.5.1.3"><p id="p2077510181622"><a name="p2077510181622"></a><a name="p2077510181622"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="54.800000000000004%" id="mcps1.1.5.1.4"><p id="p877513181526"><a name="p877513181526"></a><a name="p877513181526"></a>参数描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1477516181921"><td class="cellrowborder" valign="top" width="16.36%" headers="mcps1.1.5.1.1 "><p id="p1477512187213"><a name="p1477512187213"></a><a name="p1477512187213"></a>transition</p>
</td>
<td class="cellrowborder" valign="top" width="15.64%" headers="mcps1.1.5.1.2 "><p id="p1980112523116"><a name="p1980112523116"></a><a name="p1980112523116"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="13.200000000000001%" headers="mcps1.1.5.1.3 "><p id="p1477611180220"><a name="p1477611180220"></a><a name="p1477611180220"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="54.800000000000004%" headers="mcps1.1.5.1.4 "><p id="p8776171815211"><a name="p8776171815211"></a><a name="p8776171815211"></a>所有参数均为可选参数，详细描述见<a href="#li735275511597">transition入参说明</a>。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li735275511597"></a>transition入参说明

    <a name="table569010183219"></a>
    <table><thead align="left"><tr id="row137762181329"><th class="cellrowborder" valign="top" width="18.11%" id="mcps1.1.6.1.1"><p id="p277615181212"><a name="p277615181212"></a><a name="p277615181212"></a>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.830000000000002%" id="mcps1.1.6.1.2"><p id="p57761418722"><a name="p57761418722"></a><a name="p57761418722"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.690000000000001%" id="mcps1.1.6.1.3"><p id="p47761018125"><a name="p47761018125"></a><a name="p47761018125"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.68%" id="mcps1.1.6.1.4"><p id="p177761318321"><a name="p177761318321"></a><a name="p177761318321"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="35.69%" id="mcps1.1.6.1.5"><p id="p3776181817215"><a name="p3776181817215"></a><a name="p3776181817215"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row137768181212"><td class="cellrowborder" valign="top" width="18.11%" headers="mcps1.1.6.1.1 "><p id="p14776161815219"><a name="p14776161815219"></a><a name="p14776161815219"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.830000000000002%" headers="mcps1.1.6.1.2 "><p id="p77768181021"><a name="p77768181021"></a><a name="p77768181021"></a><a href="#li15581632802">TransitionType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.1.6.1.3 "><p id="p377612186218"><a name="p377612186218"></a><a name="p377612186218"></a>All</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.68%" headers="mcps1.1.6.1.4 "><p id="p2077615181324"><a name="p2077615181324"></a><a name="p2077615181324"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.6.1.5 "><p id="p177681812218"><a name="p177681812218"></a><a name="p177681812218"></a>默认包括组件新增和删除。</p>
    <div class="note" id="note18696315103317"><a name="note18696315103317"></a><a name="note18696315103317"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p206961915123311"><a name="p206961915123311"></a><a name="p206961915123311"></a>不指定Type时说明插入删除使用同一种效果。</p>
    </div></div>
    </td>
    </tr>
    <tr id="row87771318422"><td class="cellrowborder" valign="top" width="18.11%" headers="mcps1.1.6.1.1 "><p id="p5777181810216"><a name="p5777181810216"></a><a name="p5777181810216"></a>opacity</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.830000000000002%" headers="mcps1.1.6.1.2 "><p id="p187773181623"><a name="p187773181623"></a><a name="p187773181623"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.1.6.1.3 "><p id="p0777818521"><a name="p0777818521"></a><a name="p0777818521"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.68%" headers="mcps1.1.6.1.4 "><p id="p1777711187211"><a name="p1777711187211"></a><a name="p1777711187211"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.6.1.5 "><p id="p2777418321"><a name="p2777418321"></a><a name="p2777418321"></a>设置组件转场时的透明度效果，为插入时起点和删除时终点的值。</p>
    </td>
    </tr>
    <tr id="row167774181721"><td class="cellrowborder" valign="top" width="18.11%" headers="mcps1.1.6.1.1 "><p id="p17777201815217"><a name="p17777201815217"></a><a name="p17777201815217"></a>translate</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.830000000000002%" headers="mcps1.1.6.1.2 "><p id="p191388322174"><a name="p191388322174"></a><a name="p191388322174"></a>{</p>
    <p id="p126201424151718"><a name="p126201424151718"></a><a name="p126201424151718"></a>x? : number,</p>
    <p id="p285632617179"><a name="p285632617179"></a><a name="p285632617179"></a>y? : number,</p>
    <p id="p16524428111714"><a name="p16524428111714"></a><a name="p16524428111714"></a>z? : number</p>
    <p id="p14777818824"><a name="p14777818824"></a><a name="p14777818824"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.1.6.1.3 "><p id="p6777151817215"><a name="p6777151817215"></a><a name="p6777151817215"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.68%" headers="mcps1.1.6.1.4 "><p id="p0777161816218"><a name="p0777161816218"></a><a name="p0777161816218"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.6.1.5 "><p id="p97774181927"><a name="p97774181927"></a><a name="p97774181927"></a>设置组件转场时的平移效果，为插入时起点和删除时终点的值。</p>
    </td>
    </tr>
    <tr id="row177714181221"><td class="cellrowborder" valign="top" width="18.11%" headers="mcps1.1.6.1.1 "><p id="p277716188211"><a name="p277716188211"></a><a name="p277716188211"></a>scale</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.830000000000002%" headers="mcps1.1.6.1.2 "><p id="p172107302174"><a name="p172107302174"></a><a name="p172107302174"></a>{</p>
    <p id="p11917173317171"><a name="p11917173317171"></a><a name="p11917173317171"></a>x? : number,</p>
    <p id="p18653235191715"><a name="p18653235191715"></a><a name="p18653235191715"></a>y? : number,</p>
    <p id="p913018403171"><a name="p913018403171"></a><a name="p913018403171"></a>z? : number,</p>
    <p id="p324984481710"><a name="p324984481710"></a><a name="p324984481710"></a>centerX? : number,</p>
    <p id="p09912451173"><a name="p09912451173"></a><a name="p09912451173"></a>centerY? : number</p>
    <p id="p17770181124"><a name="p17770181124"></a><a name="p17770181124"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.1.6.1.3 "><p id="p147771185213"><a name="p147771185213"></a><a name="p147771185213"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.68%" headers="mcps1.1.6.1.4 "><p id="p47773184215"><a name="p47773184215"></a><a name="p47773184215"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.6.1.5 "><p id="p977713181926"><a name="p977713181926"></a><a name="p977713181926"></a>设置组件转场时的缩放效果，为插入时起点和删除时终点的值。</p>
    </td>
    </tr>
    <tr id="row87779183210"><td class="cellrowborder" valign="top" width="18.11%" headers="mcps1.1.6.1.1 "><p id="p1277715181827"><a name="p1277715181827"></a><a name="p1277715181827"></a>rotate</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.830000000000002%" headers="mcps1.1.6.1.2 "><p id="p1740524821716"><a name="p1740524821716"></a><a name="p1740524821716"></a>{</p>
    <p id="p173632508173"><a name="p173632508173"></a><a name="p173632508173"></a>x?: number,</p>
    <p id="p1654155216170"><a name="p1654155216170"></a><a name="p1654155216170"></a>y?: number,</p>
    <p id="p9193555181713"><a name="p9193555181713"></a><a name="p9193555181713"></a>z?: number,</p>
    <p id="p146481157121711"><a name="p146481157121711"></a><a name="p146481157121711"></a>angle?: Angle,</p>
    <p id="p496511181818"><a name="p496511181818"></a><a name="p496511181818"></a>centerX?: Length,</p>
    <p id="p36951551188"><a name="p36951551188"></a><a name="p36951551188"></a>centerY?: Length</p>
    <p id="p777721816211"><a name="p777721816211"></a><a name="p777721816211"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.690000000000001%" headers="mcps1.1.6.1.3 "><p id="p977716181210"><a name="p977716181210"></a><a name="p977716181210"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.68%" headers="mcps1.1.6.1.4 "><p id="p157770181529"><a name="p157770181529"></a><a name="p157770181529"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="35.69%" headers="mcps1.1.6.1.5 "><p id="p6777018123"><a name="p6777018123"></a><a name="p6777018123"></a>设置组件转场时的旋转效果，为插入时起点和删除时终点的值。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li15581632802"></a>TransitionType枚举说明

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>All</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>指定当前的Transition动效生效在组件的所有变化场景。</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>Insert</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p94521233195915"><a name="p94521233195915"></a><a name="p94521233195915"></a>指定当前的Transition动效生效在组件的插入场景。</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>Delete</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>指定当前的Transition动效生效在组件的删除场景。</p>
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

