# 点击事件<a name="ZH-CN_TOPIC_0000001111581270"></a>

<a name="table268mcpsimp"></a>
<table><thead align="left"><tr id="row274mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.5.1.1"><p id="p278mcpsimp"><a name="p278mcpsimp"></a><a name="p278mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.2"><p id="p240018113020"><a name="p240018113020"></a><a name="p240018113020"></a>支持冒泡</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.3"><p id="p280mcpsimp"><a name="p280mcpsimp"></a><a name="p280mcpsimp"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row281mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p id="p283mcpsimp"><a name="p283mcpsimp"></a><a name="p283mcpsimp"></a>onClick(callback: (event?: ClickEvent) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p id="p240119143012"><a name="p240119143012"></a><a name="p240119143012"></a>否</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p id="p287mcpsimp"><a name="p287mcpsimp"></a><a name="p287mcpsimp"></a>点击动作触发该方法调用，event参数见<a href="#li155675712535">ClickEvent</a>介绍。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li155675712535"></a>ClickEvent对象说明

    <a name="table150414419378"></a>
    <table><thead align="left"><tr id="row250434411379"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p17251053163714"><a name="p17251053163714"></a><a name="p17251053163714"></a>属性名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p125175313377"><a name="p125175313377"></a><a name="p125175313377"></a>属性类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p152518539379"><a name="p152518539379"></a><a name="p152518539379"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row25047446377"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p625120539377"><a name="p625120539377"></a><a name="p625120539377"></a>screenX</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p7251105311371"><a name="p7251105311371"></a><a name="p7251105311371"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p62511553103710"><a name="p62511553103710"></a><a name="p62511553103710"></a>点击点相对于设备屏幕左边沿的X坐标。</p>
    </td>
    </tr>
    <tr id="row16504744143718"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p3251353193710"><a name="p3251353193710"></a><a name="p3251353193710"></a>screenY</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p14252175323715"><a name="p14252175323715"></a><a name="p14252175323715"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p225275353713"><a name="p225275353713"></a><a name="p225275353713"></a>点击点相对于设备屏幕上边沿的Y坐标。</p>
    </td>
    </tr>
    <tr id="row750454419376"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p11252195317371"><a name="p11252195317371"></a><a name="p11252195317371"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p025215313716"><a name="p025215313716"></a><a name="p025215313716"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p10252195316373"><a name="p10252195316373"></a><a name="p10252195316373"></a>点击点相对于被点击元素左边沿的X坐标。</p>
    </td>
    </tr>
    <tr id="row19505244163715"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p6252195312377"><a name="p6252195312377"></a><a name="p6252195312377"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p92521553113719"><a name="p92521553113719"></a><a name="p92521553113719"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1925216537376"><a name="p1925216537376"></a><a name="p1925216537376"></a>点击点相对于被点击元素上边沿的Y坐标。</p>
    </td>
    </tr>
    <tr id="row7505194418373"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p3252155316378"><a name="p3252155316378"></a><a name="p3252155316378"></a>timestamp</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p16252453163717"><a name="p16252453163717"></a><a name="p16252453163717"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p13252115333711"><a name="p13252115333711"></a><a name="p13252115333711"></a>事件时间戳。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section16900453182718"></a>

```
@Entry
@Component
struct ClickExample {
  @State text: string = ''

  build() {
    Column() {
      Button('Click').backgroundColor(0x2788D9)
        .onClick((event: ClickEvent) => {
          console.info(this.text = 'Button clicked!\n X:' + event.x + '\n' + ' Y:' + event.y)
        })
      Text(this.text).padding(15)
    }.height(300).width('100%').padding(35)
  }
}
```

![](figures/Click.gif)

