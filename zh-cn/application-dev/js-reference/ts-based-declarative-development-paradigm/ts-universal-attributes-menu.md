# Menu控制<a name="ZH-CN_TOPIC_0000001162350678"></a>

<a name="table1037313227139"></a>
<table><thead align="left"><tr id="row53744222138"><th class="cellrowborder" valign="top" width="15.17%" id="mcps1.1.5.1.1"><p id="p13749220130"><a name="p13749220130"></a><a name="p13749220130"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="19.950000000000003%" id="mcps1.1.5.1.2"><p id="p337419226138"><a name="p337419226138"></a><a name="p337419226138"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.709999999999999%" id="mcps1.1.5.1.3"><p id="p937472215137"><a name="p937472215137"></a><a name="p937472215137"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="56.169999999999995%" id="mcps1.1.5.1.4"><p id="p1537402221310"><a name="p1537402221310"></a><a name="p1537402221310"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row10374102221314"><td class="cellrowborder" valign="top" width="15.17%" headers="mcps1.1.5.1.1 "><p id="p137482215136"><a name="p137482215136"></a><a name="p137482215136"></a>bindMenu</p>
</td>
<td class="cellrowborder" valign="top" width="19.950000000000003%" headers="mcps1.1.5.1.2 "><p id="p776415035912"><a name="p776415035912"></a><a name="p776415035912"></a>Array&lt;<a href="#li430441812114">MenuItem</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.709999999999999%" headers="mcps1.1.5.1.3 "><p id="p237452201312"><a name="p237452201312"></a><a name="p237452201312"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.169999999999995%" headers="mcps1.1.5.1.4 "><p id="p18374322121319"><a name="p18374322121319"></a><a name="p18374322121319"></a>给组件绑定菜单，点击后弹出菜单。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li430441812114"></a>MenuItem

    <a name="table1424519622612"></a>
    <table><thead align="left"><tr id="row824556182616"><th class="cellrowborder" valign="top" width="12.379999999999999%" id="mcps1.1.4.1.1"><p id="p424619682616"><a name="p424619682616"></a><a name="p424619682616"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.189999999999998%" id="mcps1.1.4.1.2"><p id="p491774216268"><a name="p491774216268"></a><a name="p491774216268"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="71.43%" id="mcps1.1.4.1.3"><p id="p1024619613263"><a name="p1024619613263"></a><a name="p1024619613263"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1024614617263"><td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.4.1.1 "><p id="p1124613612610"><a name="p1124613612610"></a><a name="p1124613612610"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.189999999999998%" headers="mcps1.1.4.1.2 "><p id="p17917642122615"><a name="p17917642122615"></a><a name="p17917642122615"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.43%" headers="mcps1.1.4.1.3 "><p id="p424676152618"><a name="p424676152618"></a><a name="p424676152618"></a>菜单项文本。</p>
    </td>
    </tr>
    <tr id="row29191330182615"><td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.4.1.1 "><p id="p163703358267"><a name="p163703358267"></a><a name="p163703358267"></a>action</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.189999999999998%" headers="mcps1.1.4.1.2 "><p id="p10914145432618"><a name="p10914145432618"></a><a name="p10914145432618"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.43%" headers="mcps1.1.4.1.3 "><p id="p11311360277"><a name="p11311360277"></a><a name="p11311360277"></a>点击菜单项的事件回调。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section3505155091512"></a>

```
@Entry
@Component
struct menuExample {
  build() {
    Column() {
      Text('click for Menu')
    }
    .width('100%')
    .margin({ top: 5 })
    .bindMenu([
      {
        value: 'Menu1',
        action: () => {
          console.info('handle Menu1 select')
        }
      },
      {
        value: 'Menu2',
        action: () => {
          console.info('handle Menu2 select')
        }
      },
    ])
  }
}
```

![](figures/menu.gif)

