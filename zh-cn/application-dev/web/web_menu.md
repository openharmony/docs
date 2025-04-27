# Web菜单相关功能

Web组件菜单分为文本选中菜单和上下文菜单。
文本选中菜单在用户手势长按选中文本后或编辑态长按出现单手柄后出现。菜单项横向排列，系统提供默认的菜单实现。
上下文菜单在手势长按富文本或鼠标右键点击时出现。菜单项竖向排列，系统不提供默认实现如开发者为实现则不弹出菜单。


## 文本选中菜单

应用可通过[editmenuoptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#editmenuoptions12)或者[selectionmenuoptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#selectionmenuoptionsdeprecated)(不建议，该接口将在API20废弃)对文本选中菜单进行自定义操作

### 通过editmenuoptions自定义文本选中菜单

**示例：**

  ```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  onCreateMenu(menuItems: Array<TextMenuItem>): Array<TextMenuItem> {
    let items = menuItems.filter((menuItem) => {
      // 过滤用户需要的系统按键
      return (
        menuItem.id.equals(TextMenuItemId.CUT) ||
        menuItem.id.equals(TextMenuItemId.COPY) ||
        menuItem.id.equals((TextMenuItemId.PASTE))
      )
    });
    let customItem1: TextMenuItem = {
      content: 'customItem1',
      id: TextMenuItemId.of('customItem1'),
      icon: $r('app.media.icon')
    };
    let customItem2: TextMenuItem = {
      content: $r('app.string.customItem2'),
      id: TextMenuItemId.of('customItem2'),
      icon: $r('app.media.icon')
    };
    items.push(customItem1);// 在选项列表后添加新选项
    items.unshift(customItem2);// 在选项列表前添加选项
    return items;
  }

  onMenuItemClick(menuItem: TextMenuItem, textRange: TextRange): boolean {
    if (menuItem.id.equals(TextMenuItemId.CUT)) {
      // 用户自定义行为
      console.log("拦截 id：CUT")
      return true; // 返回true不执行系统回调
    } else if (menuItem.id.equals(TextMenuItemId.COPY)) {
      // 用户自定义行为
      console.log("不拦截 id：COPY")
      return false; // 返回false执行系统回调
    } else if (menuItem.id.equals(TextMenuItemId.of('customItem1'))) {
      // 用户自定义行为
      console.log("拦截 id：customItem1")
      return true;// 用户自定义菜单选项返回true时点击后不关闭菜单，返回false时关闭菜单
    } else if (menuItem.id.equals((TextMenuItemId.of($r('app.string.customItem2'))))){
      // 用户自定义行为
      console.log("拦截 id：app.string.customItem2")
      return true;
    }
    return false;// 返回默认值false
  }

  @State EditMenuOptions: EditMenuOptions = { onCreateMenu: this.onCreateMenu, onMenuItemClick: this.onMenuItemClick }

  build() {
    Column() {
      Web({ src: $rawfile("index.html"), controller: this.controller })
        .editMenuOptions(this.EditMenuOptions)
    }
  }
}
  ```
  
  ```html
<!--index.html-->
<!DOCTYPE html>
<html>
  <head>
      <title>测试网页</title>
  </head>
  <body>
    <h1>editMenuOptions Demo</h1>
    <span>edit menu options</span>
  </body>
</html>
  ```
#### 实现说明
1. 通过onCreateMenu方法自定义菜单项，通过处理Array<[TextMenuItem](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md)>数组可对显示菜单项进行增减操作，在[TextMenuItem](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md)中可定义菜单项名称，图标等内容。
2. 通过onMenuItemClick方法对菜单项点击事件进行处理，可通过返回值定义是否系统默认菜单项行为。
3. 创建EditMenuOptions实例，通过editMenuOptions将菜单与Web组件绑定。

### 通过selectionmenuoptions自定义文本选中菜单(不推荐)

**示例：**

  ```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
controller: webview.WebviewController = new webview.WebviewController();
@State menuOptionArray: Array<ExpandedMenuItemOptions> = [
    {content: 'Apple', startIcon: $r('app.media.icon'), action: (selectedText) => {
    console.info('select info ' + selectedText.toString());
    }},
    {content: '香蕉', startIcon: $r('app.media.icon'), action: (selectedText) => {
    console.info('select info ' + selectedText.toString());
    }}
];

build() {
    Column() {
    Web({ src: $rawfile("index.html"), controller: this.controller })
    .selectionMenuOptions(this.menuOptionArray)
    }
}
}
  ```
  ```html
<!--index.html-->
<!DOCTYPE html>
<html>
<head>
  <title>测试网页</title>
</head>
<body>
  <h1>selectionMenuOptions Demo</h1>
  <span>selection menu options</span>
</body>
</html>
  ```
#### 实现说明
1. 定义一个Array<ExpandedMenuItemOptions>数组，通过[ExpandedMenuItemOptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#expandedmenuitemoptions12)实现每个菜单项的行为
2. 通过selectionMenuOptions将menuOptionArray与Web绑定

### 常见问题

#### 如何实现长按文本时菜单隐藏
```ts
  onCreateMenu(menuItems: Array<TextMenuItem>): Array<TextMenuItem> {
    let items = menuItems.filter((menuItem) => {
      // 过滤用户需要的系统按键
      return false;
    });
    return items;
  }
```
在onCreateMenu方法中把菜单数组置空

#### 通过JS设置选区手柄菜单不显示
目前Web菜单与手柄绑定，通过JS设置选区时不会显示手柄，导致菜单也不会显示。

## 上下文菜单
上下文菜单需要开发者通过[Menu](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menu.md#menu)组件创建一个菜单子窗口与Web绑定，通过菜单弹出时的[onContextMenuShow](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#oncontextmenushow)接口获取到上下文菜单详细信息，包含点击位置的HTML元素信息，点击位置信息等。

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { pasteboard } from '@kit.BasicServicesKit';

const TAG = 'ContextMenu';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  private result: WebContextMenuResult | undefined = undefined;
  @State linkUrl: string = '';
  @State offsetX: number = 0;
  @State offsetY: number = 0;
  @State showMenu: boolean = false;

  @Builder
  // 构建自定义菜单及触发功能接口
  MenuBuilder() {
    // 以垂直列表形式显示的菜单。
    Menu() {
      // 展示菜单Menu中具体的item菜单项。
      MenuItem({
        content: '复制图片',
      })
        .width(100)
        .height(50)
        .onClick(() => {
          this.result?.copyImage();
          this.showMenu = false;
        })
      MenuItem({
        content: '剪切',
      })
        .width(100)
        .height(50)
        .onClick(() => {
          this.result?.cut();
          this.showMenu = false;
        })
      MenuItem({
        content: '复制',
      })
        .width(100)
        .height(50)
        .onClick(() => {
          this.result?.copy();
          this.showMenu = false;
        })
      MenuItem({
        content: '粘贴',
      })
        .width(100)
        .height(50)
        .onClick(() => {
          this.result?.paste();
          this.showMenu = false;
        })
      MenuItem({
        content: '复制链接',
      })
        .width(100)
        .height(50)
        .onClick(() => {
          let pasteData = pasteboard.createData('text/plain', this.linkUrl);
          pasteboard.getSystemPasteboard().setData(pasteData, (error) => {
            if (error) {
              return;
            }
          })
          this.showMenu = false;
        })
      MenuItem({
        content: '全选',
      })
        .width(100)
        .height(50)
        .onClick(() => {
          this.result?.selectAll();
          this.showMenu = false;
        })
    }
    .width(150)
    .height(300)
  }

  build() {
    Column() {
      Web({ src: $rawfile("index.html"), controller: this.controller })
        // 触发自定义弹窗
        .onContextMenuShow((event) => {
          if (event) {
            this.result = event.result
            console.info("x coord = " + event.param.x());
            console.info("link url = " + event.param.getLinkUrl());
            this.linkUrl = event.param.getLinkUrl();
          }
          console.info(TAG, `x: ${this.offsetX}, y: ${this.offsetY}`);
          this.showMenu = true;
          this.offsetX = 0;
          this.offsetY = Math.max(px2vp(event?.param.y() ?? 0) - 0, 0);
          return true;
        })
        .bindPopup(this.showMenu,
          {
            builder: this.MenuBuilder(),
            enableArrow: false,
            placement: Placement.LeftTop,
            offset: { x: this.offsetX, y: this.offsetY },
            mask: false,
            onStateChange: (e) => {
              if (!e.isVisible) {
                this.showMenu = false;
                this.result!.closeContextMenu();
              }
            }
          })
    }
  }
}
```
```html
<!-- index.html -->
<!DOCTYPE html>
<html lang="en">
<body>
  <h1>onContextMenuShow</h1>
  <a href="http://www.example.com" style="font-size:27px">链接www.example.com</a>
  // rawfile下放任意一张图片命名为example.png
  <div><img src="example.png"></div>
  <p>选中文字鼠标右键弹出菜单</p>
</body>
</html>
```
### 实现说明
1. 创建一个[Menu](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menu.md#menu)组件作为弹出的菜单，包含所有菜单项与菜单的行为与样式。
2. 通过bindPopup将Menu组件与Web绑定，上下文菜单弹出时将弹出创建的Menu组件。
3. 在OnContextMenuShow回调中获取菜单事件信息，[OnContextMenuShowEvent](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#oncontextmenushowevent12)。其中param为[WebContextMenuParam](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#webcontextmenuparam9)类型包括点击位置对应HTML元素信息和位置信息，result为[WebContextMenuParam](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#webcontextmenuresult9)提供常见的菜单能力。
