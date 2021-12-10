# 按键事件<a name="ZH-CN_TOPIC_0000001167303697"></a>

<a name="table2154mcpsimp"></a>
<table><thead align="left"><tr id="row2160mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.5.1.1"><p id="p2164mcpsimp"><a name="p2164mcpsimp"></a><a name="p2164mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.2"><p id="p11204193417499"><a name="p11204193417499"></a><a name="p11204193417499"></a>支持冒泡</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.3"><p id="p2166mcpsimp"><a name="p2166mcpsimp"></a><a name="p2166mcpsimp"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2167mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p id="p1458682911559"><a name="p1458682911559"></a><a name="p1458682911559"></a>onKeyEvent(event: (event?: KeyEvent) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p id="p13204434194919"><a name="p13204434194919"></a><a name="p13204434194919"></a>是</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p id="p2173mcpsimp"><a name="p2173mcpsimp"></a><a name="p2173mcpsimp"></a>按键动作触发该方法调用，event参数见<a href="#section3668926124018">KeyEvent</a>介绍。</p>
</td>
</tr>
</tbody>
</table>

## KeyEvent对象说明<a name="section3668926124018"></a>

-   属性

    <a name="table53243322214"></a>
    <table><thead align="left"><tr id="row832453172215"><th class="cellrowborder" valign="top" width="33.29332933293329%" id="mcps1.1.4.1.1"><p id="p113242319226"><a name="p113242319226"></a><a name="p113242319226"></a>属性名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.26212621262126%" id="mcps1.1.4.1.2"><p id="p183242030221"><a name="p183242030221"></a><a name="p183242030221"></a>属性类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.44454445444545%" id="mcps1.1.4.1.3"><p id="p143241031224"><a name="p143241031224"></a><a name="p143241031224"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row43244322214"><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p id="p1324631229"><a name="p1324631229"></a><a name="p1324631229"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p id="p4324203182211"><a name="p4324203182211"></a><a name="p4324203182211"></a><a href="#li15552046124817">KeyType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p id="p13241232225"><a name="p13241232225"></a><a name="p13241232225"></a>按键的类型。</p>
    </td>
    </tr>
    <tr id="row9324532224"><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p id="p153241932220"><a name="p153241932220"></a><a name="p153241932220"></a>keyCode</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p id="p113244332215"><a name="p113244332215"></a><a name="p113244332215"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p id="p932412312226"><a name="p932412312226"></a><a name="p932412312226"></a>按键的键码。</p>
    </td>
    </tr>
    <tr id="row14324332229"><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p id="p332412302213"><a name="p332412302213"></a><a name="p332412302213"></a>keyText</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p id="p1232515372212"><a name="p1232515372212"></a><a name="p1232515372212"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p id="p032510312221"><a name="p032510312221"></a><a name="p032510312221"></a>按键的键值。</p>
    </td>
    </tr>
    <tr id="row1032543162211"><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p id="p932517352210"><a name="p932517352210"></a><a name="p932517352210"></a>keySource</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p id="p832533172211"><a name="p832533172211"></a><a name="p832533172211"></a><a href="#li19778175915485">KeySource</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p id="p1432563132211"><a name="p1432563132211"></a><a name="p1432563132211"></a>触发当前按键的输入设备类型。</p>
    </td>
    </tr>
    <tr id="row732533102212"><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p id="p332514311229"><a name="p332514311229"></a><a name="p332514311229"></a>deviceId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p id="p1325637223"><a name="p1325637223"></a><a name="p1325637223"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p id="p153258312221"><a name="p153258312221"></a><a name="p153258312221"></a>触发当前按键的输入设备ID。</p>
    </td>
    </tr>
    <tr id="row732523172210"><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p id="p93254332219"><a name="p93254332219"></a><a name="p93254332219"></a>metaKey</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p id="p113256392210"><a name="p113256392210"></a><a name="p113256392210"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p id="p173264317227"><a name="p173264317227"></a><a name="p173264317227"></a>按键发生时元键的状态，1表示按压态，0表示未按压态。</p>
    </td>
    </tr>
    <tr id="row19326339229"><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p id="p1532643112211"><a name="p1532643112211"></a><a name="p1532643112211"></a>timestamp</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p id="p183269319227"><a name="p183269319227"></a><a name="p183269319227"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p id="p83262322214"><a name="p83262322214"></a><a name="p83262322214"></a>按键发生时的时间戳。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   接口

    <a name="table16480191335813"></a>
    <table><thead align="left"><tr id="row948041318587"><th class="cellrowborder" valign="top" width="42.68%" id="mcps1.1.3.1.1"><p id="p3480181310588"><a name="p3480181310588"></a><a name="p3480181310588"></a>接口名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.32000000000001%" id="mcps1.1.3.1.2"><p id="p1148014131585"><a name="p1148014131585"></a><a name="p1148014131585"></a>功能描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1448011395810"><td class="cellrowborder" valign="top" width="42.68%" headers="mcps1.1.3.1.1 "><p id="p1748011130582"><a name="p1748011130582"></a><a name="p1748011130582"></a>stopPropagation(): void</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.32000000000001%" headers="mcps1.1.3.1.2 "><p id="p11480413125814"><a name="p11480413125814"></a><a name="p11480413125814"></a>阻塞事件冒泡传递。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li15552046124817"></a>KeyType枚举说明

    <a name="table12144170154116"></a>
    <table><thead align="left"><tr id="row1314430184118"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1614414014416"><a name="p1614414014416"></a><a name="p1614414014416"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1314415074113"><a name="p1314415074113"></a><a name="p1314415074113"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row61441505417"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p191443034117"><a name="p191443034117"></a><a name="p191443034117"></a>Down</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p121447017412"><a name="p121447017412"></a><a name="p121447017412"></a>按键按下。</p>
    </td>
    </tr>
    <tr id="row20144801418"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p17145110194110"><a name="p17145110194110"></a><a name="p17145110194110"></a>Up</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p171454015415"><a name="p171454015415"></a><a name="p171454015415"></a>按键松开。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li19778175915485"></a>KeySource枚举说明

    <a name="table9370949114019"></a>
    <table><thead align="left"><tr id="row1237015492406"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1637014974014"><a name="p1637014974014"></a><a name="p1637014974014"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p16370174924013"><a name="p16370174924013"></a><a name="p16370174924013"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8370749184018"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p7370114974013"><a name="p7370114974013"></a><a name="p7370114974013"></a>Unknown</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1537034917408"><a name="p1537034917408"></a><a name="p1537034917408"></a>输入设备类型未知。</p>
    </td>
    </tr>
    <tr id="row137024915409"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p19370349134011"><a name="p19370349134011"></a><a name="p19370349134011"></a>Keyboard</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p437064913405"><a name="p437064913405"></a><a name="p437064913405"></a>输入设备类型为键盘。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   常用KeyCode说明

    <a name="t2c492df6ccd147b5854b71c189da0b33"></a>
    <table><thead align="left"><tr id="r461911d4ccce42b5bee4715daf04e2f2"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.4.1.1"><p id="ae0aa377969e64f3093c9da590c028f4a"><a name="ae0aa377969e64f3093c9da590c028f4a"></a><a name="ae0aa377969e64f3093c9da590c028f4a"></a>数值</p>
    </th>
    <th class="cellrowborder" valign="top" width="20%" id="mcps1.1.4.1.2"><p id="a49107360a6c847c8949a193b78b096d5"><a name="a49107360a6c847c8949a193b78b096d5"></a><a name="a49107360a6c847c8949a193b78b096d5"></a>行为</p>
    </th>
    <th class="cellrowborder" valign="top" width="63%" id="mcps1.1.4.1.3"><p id="af9bff2c0e0b046f5be5996e347a19585"><a name="af9bff2c0e0b046f5be5996e347a19585"></a><a name="af9bff2c0e0b046f5be5996e347a19585"></a>物理按键</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="rd5955edc33f54b80b911dab12cc45b02"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p id="ade7af794b1a543a88d635a814313aa53"><a name="ade7af794b1a543a88d635a814313aa53"></a><a name="ade7af794b1a543a88d635a814313aa53"></a>19</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="a007d4aa2ac6f4721a0336db748594084"><a name="a007d4aa2ac6f4721a0336db748594084"></a><a name="a007d4aa2ac6f4721a0336db748594084"></a>上</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="a90e47b7457d945e697b75fa7f3a18c35"><a name="a90e47b7457d945e697b75fa7f3a18c35"></a><a name="a90e47b7457d945e697b75fa7f3a18c35"></a>向上方向键。</p>
    </td>
    </tr>
    <tr id="r4bc5f674a74344c8abcb362929e1005b"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p id="aff3cba4d7a9f4fa7be1e2cdf29916c3b"><a name="aff3cba4d7a9f4fa7be1e2cdf29916c3b"></a><a name="aff3cba4d7a9f4fa7be1e2cdf29916c3b"></a>20</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="af895a1908bd44341b22a809e23fa2316"><a name="af895a1908bd44341b22a809e23fa2316"></a><a name="af895a1908bd44341b22a809e23fa2316"></a>下</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="a84188d2c586243e79c6d33386f81afe3"><a name="a84188d2c586243e79c6d33386f81afe3"></a><a name="a84188d2c586243e79c6d33386f81afe3"></a>向下方向键。</p>
    </td>
    </tr>
    <tr id="rcb8ae2a1d06247c19f1658b486365c33"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p id="aece5938bafb941aea43f2023bc0d8e7b"><a name="aece5938bafb941aea43f2023bc0d8e7b"></a><a name="aece5938bafb941aea43f2023bc0d8e7b"></a>21</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="a918cde8697b642eaa17fc8bb5e159fbd"><a name="a918cde8697b642eaa17fc8bb5e159fbd"></a><a name="a918cde8697b642eaa17fc8bb5e159fbd"></a>左</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="a9285bc852f844be5b1b8c6291166cf1d"><a name="a9285bc852f844be5b1b8c6291166cf1d"></a><a name="a9285bc852f844be5b1b8c6291166cf1d"></a>向左方向键。</p>
    </td>
    </tr>
    <tr id="r8df67c24c07b428aaaeee859f1b17701"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p id="a501c6f67ac564af2a2270d3f44cacc48"><a name="a501c6f67ac564af2a2270d3f44cacc48"></a><a name="a501c6f67ac564af2a2270d3f44cacc48"></a>22</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="a45ea66b3a96f4d74b057c714b3659faa"><a name="a45ea66b3a96f4d74b057c714b3659faa"></a><a name="a45ea66b3a96f4d74b057c714b3659faa"></a>右</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="af1a6068683fe40b3a902770479a5869d"><a name="af1a6068683fe40b3a902770479a5869d"></a><a name="af1a6068683fe40b3a902770479a5869d"></a>向右方向键。</p>
    </td>
    </tr>
    <tr id="rf83f1de192fc4e43819d40cd4dd9d5c5"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p id="a357e75de4e3d4bfea63740239a91a233"><a name="a357e75de4e3d4bfea63740239a91a233"></a><a name="a357e75de4e3d4bfea63740239a91a233"></a>23</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="a156cfdca6ee24c2a831f9ed1fe750faa"><a name="a156cfdca6ee24c2a831f9ed1fe750faa"></a><a name="a156cfdca6ee24c2a831f9ed1fe750faa"></a>确定</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="a9b3f9045e7b84093b15f688654c68036"><a name="a9b3f9045e7b84093b15f688654c68036"></a><a name="a9b3f9045e7b84093b15f688654c68036"></a>遥控器的确认键。</p>
    </td>
    </tr>
    <tr id="r799b62b61f0e48b28dc378241cb1ee70"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p id="a9968d42723b14eaca3df9b5cb683ae9f"><a name="a9968d42723b14eaca3df9b5cb683ae9f"></a><a name="a9968d42723b14eaca3df9b5cb683ae9f"></a>66</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="acae4c7acd744429eb8918859ef9e8c55"><a name="acae4c7acd744429eb8918859ef9e8c55"></a><a name="acae4c7acd744429eb8918859ef9e8c55"></a>确定</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="ab0177a6dbd4c4838929efc57e77dffa8"><a name="ab0177a6dbd4c4838929efc57e77dffa8"></a><a name="ab0177a6dbd4c4838929efc57e77dffa8"></a>键盘的回车键。</p>
    </td>
    </tr>
    <tr id="rdd439f968c2c4bc394305ba7c7364203"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p id="aafaeeb563fff433e98bc2975130dded1"><a name="aafaeeb563fff433e98bc2975130dded1"></a><a name="aafaeeb563fff433e98bc2975130dded1"></a>160</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="a45250b274d6d4fccb7805084114c6d57"><a name="a45250b274d6d4fccb7805084114c6d57"></a><a name="a45250b274d6d4fccb7805084114c6d57"></a>确定</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="a90a580f492a54928a2d27bf7b9926221"><a name="a90a580f492a54928a2d27bf7b9926221"></a><a name="a90a580f492a54928a2d27bf7b9926221"></a>键盘的小键盘回车键。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section520994913452"></a>

```
@Entry
@Component
struct KeyEventExample {
  @State text: string = ''
  @State eventType: string = ''

  build() {
    Column() {
      Button('KeyEvent').backgroundColor(0x2788D9)
        .onKeyEvent((event: KeyEvent) => {
          if (event.type === KeyType.Down) {
            this.eventType = 'Down'
          }
          if (event.type === KeyType.Up) {
            this.eventType = 'Up'
          }
          console.info(this.text = 'KeyType:' + this.eventType + '\nkeyCode:' + event.keyCode + '\nkeyText:' + event.keyText)
        })
      Text(this.text).padding(15)
    }.height(300).width('100%').padding(35)
  }
}
```

![](figures/KeyEvent.gif)

