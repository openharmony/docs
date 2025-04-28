# Web组件菜单开发指导

Web组件菜单分为文本选中菜单、上下文菜单和自定义菜单。
用户手势长按选中文本后或编辑态长按出现单手柄时，将显示横向排列的文本选中菜单。系统提供默认的菜单实现。
用户长按富文本或鼠标右键点击时，将显示竖向排列的上下文菜单。系统不提供默认实现，若开发者未实现，则不弹出菜单。

## 文本选中菜单

应用可通过[editmenuoptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#editmenuoptions12)或者[selectionmenuoptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#selectionmenuoptionsdeprecated)(不建议，editmenuoptions接口功能可以完全覆盖selectionmenuoptions，该接口将在API20废弃)对文本选中菜单进行自定义操作。当两个接口同时使用时，selectionmenuoptions接口不生效。

### 通过editmenuoptions自定义文本选中菜单

#### 规格说明
应用需要创建一个EditMenuOptions对象，通过Web组件的editMenuOptions方法与Web组件绑定，对象包含onCreateMenu和onMenuItemClick两个方法，onCreateMenu通过处理Array<[TextMenuItem](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md)>数组控制菜单项信息，onMenuItemClick通过传入的TextMenuItem理对应菜单项点击事件。
onCreateMenu处理菜单项信息，菜单项由Array<[TextMenuItem](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md)>数组控制，通过操作Array<[TextMenuItem](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md)>数组可对显示菜单项进行增减操作。[TextMenuItem](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md)中可定义菜单项名称，图标，ID等内容。
onMenuItemClick处理菜单项点击事件，当返回false时会执行系统默认逻辑。方法入参为[TextMenuItem](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-text-common.md#textmenuitem12%E5%AF%B9%E8%B1%A1%E8%AF%B4%E6%98%8E)菜单项信息和[TextRange](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-text-common.md#textrange12)选中文本信息。
本接口在与[selectionmenuoptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#selectionmenuoptionsdeprecated)同时使用时，会使selectionmenuoptions接口不生效。
 
#### 代码示例
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
1. 通过onCreateMenu方法自定义菜单项，通过操作Array<[TextMenuItem](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md)>数组可对显示菜单项进行增减操作，在TextMenuItem中定义菜单项名称、图标等内容。
2. 通过onMenuItemClick方法处理菜单项点击事件，当返回false时会执行系统默认逻辑。
3. 创建一个EditMenuOptions对象，通过Web组件的editMenuOptions方法与Web组件绑定。

### 通过selectionmenuoptions自定义文本选中菜单

#### 规格说明
1. 从API version 12开始支持，从API version 20开始废弃。建议使用[editMenuOptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#editmenuoptions12)替代。
2. Web组件自定义菜单扩展项接口，允许设置文本内容、图标和回调方法。
3. 该接口只支持选中纯文本，当选中内容包含图片及其他非文本内容时，action信息中会显示乱码。
4. 需定义[ExpandedMenuItemOptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#expandedmenuitemoptions12)数组作为菜单项，通过Web组件的selectionMenuOptions方法绑定。
5. 与[editMenuOptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#editmenuoptions12)同时使用时，该接口不生效。

#### 代码示例
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
1. 定义一个Array<[ExpandedMenuItemOptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#expandedmenuitemoptions12)>数组。通过ExpandedMenuItemOptions实现每个菜单项的行为。
2. 通过Web组件的[selectionmenuoptions](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#selectionmenuoptionsdeprecated)方法将menuOptionArray与Web组件绑定。

## 上下文菜单

### 规格说明
长按特定元素（例如图片，链接）或鼠标右键，跳出菜单。菜单项竖向排列，上下文菜单需要开发者通过[Menu](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menu.md#menu)组件创建一个菜单子窗口与Web绑定，通过菜单弹出时的[onContextMenuShow](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#oncontextmenushow)接口获取到上下文菜单详细信息，包含点击位置的HTML元素信息，点击位置信息等。
 
### 代码示例
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
1. 创建一个[Menu](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menu.md#menu)组件作为弹出的菜单，包含所有菜单项与菜单的行为与样式。
2. 使用bindPopup方法将Menu组件与Web组件绑定，当上下文菜单弹出时，将弹出创建的Menu组件。
3. 在onContextMenuShow回调中获取菜单事件信息，[onContextMenuShowEvent](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#oncontextmenushowevent12)。其中param为[WebContextMenuParam](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#webcontextmenuparam9)类型包括点击位置对应HTML元素信息和位置信息，result为[WebContextMenuResult](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#webcontextmenuresult9)提供常见的菜单能力。

## 自定义菜单

### 规格说明
自定义菜单允许应用通过[bindselectionmenu](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#bindselectionmenu13)根据事件类型与元素类型弹出自定义菜单，目前支持响应长按图片。
[bindselectionmenu]入参和说明：
|  参数名  | 类型  |  必填  |  说明  |
|  ----  | ----  | ----  | ----  |
| elementType  | (WebElementType)[https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#webelementtype13%E6%9E%9A%E4%B8%BE%E8%AF%B4%E6%98%8E] |  是  |  网页元素信息  |
| content  | (CustomBuilder)[https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-types.md#custombuilder8] |  是  |  菜单弹窗  |
| responseType  | (WebResponseType)[https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#webresponsetype13%E6%9E%9A%E4%B8%BE%E8%AF%B4%E6%98%8E] |  是  |  菜单的响应事件类型  |
| options  | (SelectionMenuOptionsExt)[https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#selectionmenuoptionsext13] |  是  |  自定义菜单扩展项  |

### 代码示例
```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

interface PreviewBuilderParam {
  previewImage: Resource | string | undefined;
  width: number;
  height: number;
}

@Builder function PreviewBuilderGlobal($$: PreviewBuilderParam) {
  Column() {
    Image($$.previewImage)
      .objectFit(ImageFit.Fill)
      .autoResize(true)
  }.width($$.width).height($$.height)
}

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  private result: WebContextMenuResult | undefined = undefined;
  @State previewImage: Resource | string | undefined = undefined;
  @State previewWidth: number = 0;
  @State previewHeight: number = 0;

  @Builder
  MenuBuilder() {
    Menu() {
      MenuItem({ content: '复制', })
        .onClick(() => {
          this.result?.copy();
          this.result?.closeContextMenu();
        })
      MenuItem({ content: '全选', })
        .onClick(() => {
          this.result?.selectAll();
          this.result?.closeContextMenu();
        })
    }
  }
  build() {
    Column() {
      Web({ src: $rawfile("index.html"), controller: this.controller })
        .bindSelectionMenu(WebElementType.IMAGE, this.MenuBuilder, WebResponseType.LONG_PRESS,
          {
            onAppear: () => {},
            onDisappear: () => {
              this.result?.closeContextMenu();
            },
            preview: PreviewBuilderGlobal({
              previewImage: this.previewImage,
              width: this.previewWidth,
              height: this.previewHeight
            }),
            menuType: MenuType.PREVIEW_MENU
          })
        .onContextMenuShow((event) => {
            if (event) {
              this.result = event.result;
              if (event.param.getLinkUrl()) {
                return false;
              }
              this.previewWidth = px2vp(event.param.getPreviewWidth());
              this.previewHeight = px2vp(event.param.getPreviewHeight());
              if (event.param.getSourceUrl().indexOf("resource://rawfile/") == 0) {
                this.previewImage = $rawfile(event.param.getSourceUrl().substr(19));
              } else {
                this.previewImage = event.param.getSourceUrl();
              }
              return true;
            }
            return false;
          })
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
    <h1>bindSelectionMenu Demo</h1>
    <img src="./img.png" >
  </body>
</html>
```
1. 创建[Menu](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menu.md#menu)组件作为菜单弹窗
2. 通过Web组件的[bindselectionmenu](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-arkweb/ts-basic-components-web.md#bindselectionmenu13)方法绑定MenuBuilder菜单弹窗。
   将 elementType 设置为 WebElementType.IMAGE，responseType 设置为 WebResponseType.LONG_PRESS。长按图片时弹出菜单。
   在 options 中定义菜单显示回调 onAppear、菜单消失回调 onDisappear、预览窗口 preview 和菜单类型 menuType。

## 常见问题
### 如何禁用长按选择时弹出菜单
```ts
  onCreateMenu(menuItems: Array<TextMenuItem>): Array<TextMenuItem> {
    let items = menuItems.filter((menuItem) => {
      // 过滤用户需要的系统按键
      return false;
    });
    return items;
  }
```
在onCreateMenu方法中将菜单数组置空。

### 长按出现选区时手柄菜单不显示
Web组件菜单与手柄绑定，当JS设置选区时，不会显示手柄和菜单。
