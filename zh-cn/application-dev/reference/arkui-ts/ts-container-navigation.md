# Navigation<a name="ZH-CN_TOPIC_0000001193075106"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

Navigation组件一般作为Page页面的根容器，通过属性设置来展示页面的标题、工具栏、菜单。

## 权限列表<a name="section988262631714"></a>

无

## 子组件<a name="section5989144051714"></a>

可以包含子组件。

## 接口<a name="section97451749121712"></a>

Navigation\(\)

创建可以根据属性设置，自动展示导航栏、标题、工具栏的组件。

## 属性<a name="section1966485019544"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17.27%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="31.8%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="19.23%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="31.7%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p>title</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p>string | <a href="../../toctopics/zh-cn_topic_0000001237475069.md#section2538145016250">CustomBuilder</a></p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p>页面标题。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p>subtitle</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p>页面副标题。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p>menus</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p>Array&lt;<a href="#table192660141468">NavigationMenuItem</a>&gt; | <a href="../../toctopics/zh-cn_topic_0000001237475069.md#section2538145016250">CustomBuilder</a></p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p>页面右上角菜单。</p>
<p></p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p>titleMode</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p><a href="#li3339655172412">NavigationTitleMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p>NavigationTitleMode.Free</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p>页面标题栏显示模式。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p>toolBar</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p>{</p>
<p>items:[</p>
<p><a href="#table192660141468">Object</a></p>
<p>] }</p>
<p>| <a href="../../toctopics/zh-cn_topic_0000001237475069.md#section2538145016250">CustomBuilder</a></p>
<p></p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p>-</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p>设置工具栏内容。</p>
<p>items: 工具栏所有项。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p>hideToolBar</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p>设置隐藏/显示工具栏：</p>
<p>true: 隐藏工具栏。</p>
<p>false: 显示工具栏。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p>hideTitleBar</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p>隐藏标题栏。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p>hideBackButton</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p>false</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p>隐藏返回键。</p>
</td>
</tr>
</tbody>
</table>

-   NavigationMenuItem类型接口说明

    <a name="table192660141468"></a>
    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.542963397925234%" id="mcps1.1.6.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.69074182814641%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.605989430416913%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.080250538265807%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.08005480524565%" id="mcps1.1.6.1.5"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>菜单栏单个选项的显示文本。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>icon</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>菜单栏单个选项的图标资源路径。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>action</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>当前选项被选中的事件回调。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Object类型接口说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.542963397925234%" id="mcps1.1.6.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.69074182814641%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.605989430416913%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.080250538265807%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.08005480524565%" id="mcps1.1.6.1.5"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>工具栏单个选项的显示文本。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>icon</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>工具栏单个选项的图标资源路径。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p>action</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p>当前选项被选中的事件回调。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li3339655172412"></a>NavigationTitleMode枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="11.52%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="88.48%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.3.1.1 "><p>Free</p>
    </td>
    <td class="cellrowborder" valign="top" width="88.48%" headers="mcps1.1.3.1.2 "><p>当内容为可滚动组件时，标题随着内容向上滚动而缩小（子标题的大小不变、淡出）。向下滚动内容到顶时则恢复原样。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.3.1.1 "><p>Mini</p>
    </td>
    <td class="cellrowborder" valign="top" width="88.48%" headers="mcps1.1.3.1.2 "><p>固定为小标题模式（图标+主副标题）。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.3.1.1 "><p>Full</p>
    </td>
    <td class="cellrowborder" valign="top" width="88.48%" headers="mcps1.1.3.1.2 "><p>固定为大标题模式（主副标题）。</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../../public_sys-resources/icon-note.gif) **说明：** 
    >目前可滚动组件只支持List。


## 事件<a name="section992435316359"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="49.94%" id="mcps1.1.3.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50.06%" id="mcps1.1.3.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p>onTitleModeChanged(callback: (titleMode: NavigationTitleMode) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p>当titleMode为NavigationTitleMode.Free时，随着可滚动组件的滑动标题栏模式发生变化时触发此回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section4459736105512"></a>

```
/ Example 01
@Entry
@Component
struct NavigationExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State hideBar: boolean = true

  @Builder NavigationTitle() {
    Column() {
      Text('title')
        .width(80)
        .height(60)
        .fontColor(Color.Blue)
        .fontSize(30)
    }
    .onClick(() => {
      console.log("title")
    })
  }

  @Builder NavigationMenus() {
    Row() {
      Image('images/add.png')
        .width(25)
        .height(25)
      Image('comment/more.png')
        .width(25)
        .height(25)
        .margin({ left: 30 })
    }.width(100)
  }

  build() {
    Column() {
      Navigation() {
        Search({ value: '', placeholder: "" }).width('85%').margin(26)
        List({ space: 5, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('90%')
                .height(80)
                .backgroundColor('#3366CC')
                .borderRadius(15)
                .fontSize(16)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical)
        .height(300)
        .margin({ top: 10, left: 18 })
        .width('100%')

        Button(this.hideBar ? "tool bar" : "hide bar")
          .onClick(() => {
            this.hideBar = !this.hideBar
          })
          .margin({ left: 135, top: 60 })
      }
      .title(this.NavigationTitle)
      .subTitle('subtitle')
      .menus(this.NavigationMenus)
      .titleMode(NavigationTitleMode.Free)
      .hideTitleBar(false)
      .hideBackButton(false)
      .onTitleModeChanged((titleModel: NavigationTitleMode) => {
        console.log('titleMode')
      })
      .toolBar({ items: [
        { value: 'app', icon: 'images/grid.svg', action: () => {
          console.log("app")
        } },
        { value: 'add', icon: 'images/add.svg', action: () => {
          console.log("add")
        } },
        { value: 'collect', icon: 'images/collect.svg', action: () => {
          console.log("collect")
        } }] })
      .hideToolBar(this.hideBar)
    }
  }
}
```

![](figures/66666.gif)

```
// Example 02
@Entry
@Component
struct ToolbarBuilderExample {
  @State currentIndex: number = 0
  @State Build: Array<Object> = [
    {
      icon: $r('app.media.ic_public_add'),
      icon_after: $r('app.media.ic_public_addcolor'),
      text: 'add',
      num: 0
    },
    {
      icon: $r('app.media.ic_public_app'),
      icon_after: $r('app.media.ic_public_appcolor'),
      text: 'app',
      num: 1
    },
    {
      icon: $r('app.media.ic_public_collect'),
      icon_after: $r('app.media.ic_public_collectcolor'),
      text: 'collect',
      num: 2
    }
  ]

  @Builder NavigationToolbar() {
    Row() {
      ForEach(this.Build, item => {
        Column() {
          Image(this.currentIndex == item.num ? item.icon_after : item.icon)
            .width(25)
            .height(25)
          Text(item.text)
            .fontColor(this.currentIndex == item.num ? "#ff7500" : "#000000")
        }
        .onClick(() => {
          this.currentIndex = item.num
        })
        .margin({ left: 70 })
      })
    }
  }

  build() {
    Column() {
      Navigation() {
        Flex() {
        }
      }
      .toolBar(this.NavigationToolbar)
    }
  }
}
```

![](figures/duande.gif)

