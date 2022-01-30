# Menu Control<a name="EN-US_TOPIC_0000001237715095"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## Attributes<a name="section6820191711316"></a>

<a name="table1037313227139"></a>
<table><thead align="left"><tr id="row53744222138"><th class="cellrowborder" valign="top" width="15.17%" id="mcps1.1.5.1.1"><p id="p13749220130"><a name="p13749220130"></a><a name="p13749220130"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.81%" id="mcps1.1.5.1.2"><p id="p337419226138"><a name="p337419226138"></a><a name="p337419226138"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.01%" id="mcps1.1.5.1.3"><p id="p937472215137"><a name="p937472215137"></a><a name="p937472215137"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="56.010000000000005%" id="mcps1.1.5.1.4"><p id="p1537402221310"><a name="p1537402221310"></a><a name="p1537402221310"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row10374102221314"><td class="cellrowborder" valign="top" width="15.17%" headers="mcps1.1.5.1.1 "><p id="p137482215136"><a name="p137482215136"></a><a name="p137482215136"></a>bindMenu</p>
</td>
<td class="cellrowborder" valign="top" width="16.81%" headers="mcps1.1.5.1.2 "><p id="p776415035912"><a name="p776415035912"></a><a name="p776415035912"></a>Array&lt;<a href="#li430441812114">MenuItem</a>&gt; | <a href="../../toctopics/en-us_topic_0000001237475069.md#section2538145016250">CustomBuilder</a><sup id="sup0854523143811"><a name="sup0854523143811"></a><a name="sup0854523143811"></a>8+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.01%" headers="mcps1.1.5.1.3 "><p id="p237452201312"><a name="p237452201312"></a><a name="p237452201312"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="56.010000000000005%" headers="mcps1.1.5.1.4 "><p id="p18374322121319"><a name="p18374322121319"></a><a name="p18374322121319"></a>Binds the menu to a component. If you click a component bound to the menu, the menu is displayed. The menu can be in text or custom type.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li430441812114"></a>MenuItem

    <a name="table1424519622612"></a>
    <table><thead align="left"><tr id="row824556182616"><th class="cellrowborder" valign="top" width="12.379999999999999%" id="mcps1.1.4.1.1"><p id="p424619682616"><a name="p424619682616"></a><a name="p424619682616"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.189999999999998%" id="mcps1.1.4.1.2"><p id="p491774216268"><a name="p491774216268"></a><a name="p491774216268"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="71.43%" id="mcps1.1.4.1.3"><p id="p1024619613263"><a name="p1024619613263"></a><a name="p1024619613263"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1024614617263"><td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.4.1.1 "><p id="p1124613612610"><a name="p1124613612610"></a><a name="p1124613612610"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.189999999999998%" headers="mcps1.1.4.1.2 "><p id="p17917642122615"><a name="p17917642122615"></a><a name="p17917642122615"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.43%" headers="mcps1.1.4.1.3 "><p id="p424676152618"><a name="p424676152618"></a><a name="p424676152618"></a>Indicates the menu item text.</p>
    </td>
    </tr>
    <tr id="row29191330182615"><td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.4.1.1 "><p id="p163703358267"><a name="p163703358267"></a><a name="p163703358267"></a>action</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.189999999999998%" headers="mcps1.1.4.1.2 "><p id="p10914145432618"><a name="p10914145432618"></a><a name="p10914145432618"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="71.43%" headers="mcps1.1.4.1.3 "><p id="p11311360277"><a name="p11311360277"></a><a name="p11311360277"></a>Indicates the action triggered when a menu item is clicked.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section3505155091512"></a>

```
@Entry
@Component
struct MenuExample {
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

```
import router from '@system.router';

@Entry
@Component
struct MenuExample {
  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text('text1')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)

      Divider().height(10)

      Text('text2')
        .fontSize(20)
        .width(100)
        .height(50)
        .textAlign(TextAlign.Center)

      Divider().height(10)

      Button('Next')
        .fontSize(20)
        .width(100)
        .height(50)
        .onClick(() => {
          router.push({ uri: 'pages/details' })
        })

    }.width(100)
  }

  build() {
    Column() {
      Text('click for menu')
    }
    .width('100%')
    .margin({ top: 5 })
    .bindMenu(this.MenuBuilder)
  }
}
```

![](figures/gif.gif)

