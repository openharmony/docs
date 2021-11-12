# Navigator<a name="EN-US_TOPIC_0000001111421442"></a>

The  **<Navigator\>**  component provides redirection.

## Required Permissions<a name="section1933872716571"></a>

None

## Child Components<a name="section1146935319579"></a>

This component can contain child components.

## APIs<a name="section5861121019581"></a>

Navigator\(value?: \{target: string, type?: NavigationType\}\)

Creates a navigator.

-   Parameters

    <a name="table10281697251"></a>
    <table><thead align="left"><tr id="row102818913255"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p6281197258"><a name="p6281197258"></a><a name="p6281197258"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18%" id="mcps1.1.6.1.2"><p id="p132815942510"><a name="p132815942510"></a><a name="p132815942510"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.25%" id="mcps1.1.6.1.3"><p id="p162839172514"><a name="p162839172514"></a><a name="p162839172514"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.42%" id="mcps1.1.6.1.4"><p id="p182859162519"><a name="p182859162519"></a><a name="p182859162519"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p id="p172879102514"><a name="p172879102514"></a><a name="p172879102514"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9282912251"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p112829172510"><a name="p112829172510"></a><a name="p112829172510"></a>target</p>
    </td>
    <td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.6.1.2 "><p id="p628397252"><a name="p628397252"></a><a name="p628397252"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p id="p1429694254"><a name="p1429694254"></a><a name="p1429694254"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.6.1.4 "><p id="p182914942513"><a name="p182914942513"></a><a name="p182914942513"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p12296913258"><a name="p12296913258"></a><a name="p12296913258"></a>Path of the target page to be redirected to.</p>
    </td>
    </tr>
    <tr id="row18291497259"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p529119162516"><a name="p529119162516"></a><a name="p529119162516"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="18%" headers="mcps1.1.6.1.2 "><p id="p0299910251"><a name="p0299910251"></a><a name="p0299910251"></a><a href="#table3452114216394">NavigationType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.25%" headers="mcps1.1.6.1.3 "><p id="p32918962514"><a name="p32918962514"></a><a name="p32918962514"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.42%" headers="mcps1.1.6.1.4 "><p id="p102969112514"><a name="p102969112514"></a><a name="p102969112514"></a>Push</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p132979132520"><a name="p132979132520"></a><a name="p132979132520"></a>Navigation type.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   NavigationType enums

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>Push</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>Navigates to a specified page in the application.</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>Replace</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>Replaces the current page with another one in the application and destroys the current page.</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>Back</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>Returns to the previous page or a specified page.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section187781816826"></a>

<a name="table1979mcpsimp"></a>
<table><thead align="left"><tr id="row1986mcpsimp"><th class="cellrowborder" valign="top" width="11.871187118711871%" id="mcps1.1.5.1.1"><p id="p1988mcpsimp"><a name="p1988mcpsimp"></a><a name="p1988mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.291629162916294%" id="mcps1.1.5.1.2"><p id="p1990mcpsimp"><a name="p1990mcpsimp"></a><a name="p1990mcpsimp"></a>Parameters</p>
</th>
<th class="cellrowborder" valign="top" width="12.73127312731273%" id="mcps1.1.5.1.3"><p id="p1992mcpsimp"><a name="p1992mcpsimp"></a><a name="p1992mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.10591059105911%" id="mcps1.1.5.1.4"><p id="p1994mcpsimp"><a name="p1994mcpsimp"></a><a name="p1994mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2013mcpsimp"><td class="cellrowborder" valign="top" width="11.871187118711871%" headers="mcps1.1.5.1.1 "><p id="p2015mcpsimp"><a name="p2015mcpsimp"></a><a name="p2015mcpsimp"></a>active</p>
</td>
<td class="cellrowborder" valign="top" width="16.291629162916294%" headers="mcps1.1.5.1.2 "><p id="p2017mcpsimp"><a name="p2017mcpsimp"></a><a name="p2017mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.73127312731273%" headers="mcps1.1.5.1.3 "><p id="p2019mcpsimp"><a name="p2019mcpsimp"></a><a name="p2019mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="59.10591059105911%" headers="mcps1.1.5.1.4 "><p id="p2021mcpsimp"><a name="p2021mcpsimp"></a><a name="p2021mcpsimp"></a>Whether the <strong id="b273713177519"><a name="b273713177519"></a><a name="b273713177519"></a>&lt;Navigator&gt;</strong> component is activated. If the component is activated, the corresponding navigation takes effect.</p>
</td>
</tr>
<tr id="row572015119533"><td class="cellrowborder" valign="top" width="11.871187118711871%" headers="mcps1.1.5.1.1 "><p id="p18721161185314"><a name="p18721161185314"></a><a name="p18721161185314"></a>params</p>
</td>
<td class="cellrowborder" valign="top" width="16.291629162916294%" headers="mcps1.1.5.1.2 "><p id="p107210118536"><a name="p107210118536"></a><a name="p107210118536"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="12.73127312731273%" headers="mcps1.1.5.1.3 "><p id="p187211917531"><a name="p187211917531"></a><a name="p187211917531"></a>undefined</p>
</td>
<td class="cellrowborder" valign="top" width="59.10591059105911%" headers="mcps1.1.5.1.4 "><p id="p47216118539"><a name="p47216118539"></a><a name="p47216118539"></a>Data that needs to be passed to the target page during redirection. You can use <strong id="b1860712605214"><a name="b1860712605214"></a><a name="b1860712605214"></a>router.getParams()</strong> to obtain the data on the target page.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section186436131831"></a>

```
// Navigator Page
@Entry
@Component
struct NavigatorExample {
  @State active: boolean = false
  @State Text: string = 'news'

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Navigator({ target: 'pages/container/navigator/Detail', type: NavigationType.Push }) {
        Text('Go to ' + this.Text + ' page').width('100%').textAlign(TextAlign.Center)
      }.params({ text: this.Text })

      Navigator() {
        Text('Back to previous page').width('100%').textAlign(TextAlign.Center)
      }.active(this.active)
      .onClick(() => {
        this.active = true
      })
    }.height(150).width(350).padding(35)
  }
}
```

```
// Detail Page
import router from '@system.router'

@Entry
@Component
struct DetailExample {
  @State text: string = router.getParams().text

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Navigator({ target: 'pages/container/navigator/Back', type: NavigationType.Push }) {
        Text('Go to back page').width('100%').height(20)
      }

      Text('This is ' + this.text + ' page').width('100%').textAlign(TextAlign.Center)
    }
    .width('100%').height(200).padding({ left: 35, right: 35, top: 35 })
  }
}

```

```
// Back Page
@Entry
@Component
struct BackExample {
  build() {
    Column() {
      Navigator({ target: 'pages/container/navigator/Navigator', type: NavigationType.Back }) {
        Text('Return to Navigator Page').width('100%').textAlign(TextAlign.Center)
      }
    }.width('100%').height(200).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/navigator.gif)

