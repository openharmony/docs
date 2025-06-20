# 菜单控制（Menu）
Menu是菜单接口，一般用于鼠标右键弹窗、点击弹窗等。具体用法请参考[菜单控制](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md)。

使用[bindContextMenu](../reference//apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu12)并设置预览图，菜单弹出时有蒙层，此时为模态。

使用[bindMenu](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu11)或bindContextMenu未设置预览图时，菜单弹出无蒙层，此时为非模态。

## 生命周期

| 名称| 类型 | 说明 |
| --- | --- | --- |
| aboutToAppear  | () =>  void | 菜单显示动效前的事件回调。 |
| onAppear | () =>  void | 菜单弹出时的事件回调。 |
| aboutToDisappear | () =>  void | 菜单退出动效前的事件回调。 |
| onDisappear  | () =>  void | 菜单消失时的事件回调。 |



## 创建默认样式的菜单

菜单需要调用bindMenu接口来实现。bindMenu响应绑定组件的点击事件，绑定组件后手势点击对应组件后即可弹出。

```ts
Button('click for Menu')
  .bindMenu([
    {
      value: 'Menu1',
      action: () => {
        console.info('handle Menu1 select');
      }
    }
  ])
```

![zh-cn_image_0000001562940565](figures/zh-cn_image_0000001562940565.png)

## 创建自定义样式的菜单

当默认样式不满足开发需求时，可使用[@Builder](../../application-dev/ui/state-management/arkts-builder.md)自定义菜单内容，通过bindMenu接口进行菜单的自定义。

### 使用@Builder自定义菜单内容

```ts
class Tmp {
  iconStr2: ResourceStr = $r("app.media.view_list_filled");

  set(val: Resource) {
    this.iconStr2 = val;
  }
}

@Entry
@Component
struct menuExample {
  @State select: boolean = true;
  private iconStr: ResourceStr = $r("app.media.view_list_filled");
  private iconStr2: ResourceStr = $r("app.media.view_list_filled");

  @Builder
  SubMenu() {
    Menu() {
      MenuItem({ content: "复制", labelInfo: "Ctrl+C" })
      MenuItem({ content: "粘贴", labelInfo: "Ctrl+V" })
    }
  }

  @Builder
  MyMenu() {
    Menu() {
      MenuItem({ startIcon: $r("app.media.icon"), content: "菜单选项" })
      MenuItem({ startIcon: $r("app.media.icon"), content: "菜单选项" }).enabled(false)
      MenuItem({
        startIcon: this.iconStr,
        content: "菜单选项",
        endIcon: $r("app.media.arrow_right_filled"),
        // 当builder参数进行配置时，表示与menuItem项绑定了子菜单。鼠标hover在该菜单项时，会显示子菜单。
        builder: this.SubMenu
      })
      MenuItemGroup({ header: '小标题' }) {
        MenuItem({ content: "菜单选项" })
          .selectIcon(true)
          .selected(this.select)
          .onChange((selected) => {
            console.info("menuItem select" + selected);
            let Str: Tmp = new Tmp();
            Str.set($r("app.media.icon"));
          })
        MenuItem({
          startIcon: $r("app.media.view_list_filled"),
          content: "菜单选项",
          endIcon: $r("app.media.arrow_right_filled"),
          builder: this.SubMenu
        })
      }

      MenuItem({
        startIcon: this.iconStr2,
        content: "菜单选项",
        endIcon: $r("app.media.arrow_right_filled")
      })
    }
  }

  build() {
    // ...
  }
}

```

### 使用bindMenu属性绑定组件

```ts
Button('click for Menu')
  .bindMenu(this.MyMenu)
```

![zh-cn_image_0000001511580924](figures/zh-cn_image_0000001511580924.png)

## 创建支持右键或长按的菜单

通过bindContextMenu接口自定义菜单，设置菜单弹出的触发方式，触发方式为右键或长按。使用bindContextMenu弹出的菜单项是在独立子窗口内的，可显示在应用窗口外部。

- 使用@Builder自定义菜单内容，与上文写法相同。
- 确认菜单的弹出方式，并使用bindContextMenu属性绑定组件。示例中为右键弹出菜单。
  
  ```ts
  Button('click for Menu')
    .bindContextMenu(this.MyMenu, ResponseType.RightClick)
  ```

## 菜单弹出时振动效果

菜单从API version 18开始支持振动效果。菜单弹出时，默认不振动。若希望菜单弹出时有振动效果，可以通过[ContextMenuOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#contextmenuoptions10)的hapticFeedbackMode属性，设置菜单弹出时的振动模式。

- 只有一级菜单可配置弹出时振动效果。
- 仅当应用具备ohos.permission.VIBRATE权限，且用户启用了触感反馈时才会生效。开启触控反馈时，需要在工程的module.json5中配置[声明权限](../security/AccessToken/declare-permissions.md#声明权限)的requestPermissions字段开启振动权限，配置如下：

  ```json
  "requestPermissions": [
    {
      "name": "ohos.permission.VIBRATE",
    }
  ]
  ```

```ts
  Button('click for Menu')
    .bindContextMenu(this.MyMenu, ResponseType.RightClick, { hapticFeedbackMode: HapticFeedbackMode.ENABLED })
```

## 菜单支持避让中轴

从API version 18起，菜单支持中轴避让功能。从API version 20开始，在2in1设备上默认启用（仅在窗口处于瀑布模式时产生避让）。开发者可通过[ContextMenuOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#contextmenuoptions10)中的enableHoverMode属性，控制菜单是否启用中轴避让。

> **说明：**
> - 如果菜单的点击位置在中轴区域，则菜单不会避让。
> - 2in1设备上需同时满足窗口处于瀑布模式才会产生避让。

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World';
  private iconStr: Resource = $r('app.media.startIcon');
  @State index: number = 0;
  @State arrayStr: Array<string> = ['上半屏', '中轴', '下半屏'];
  @State enableHoverMode: boolean | undefined = true;
  @State showInSubwindow: boolean = false;
  @State placement: Placement | undefined = undefined;

  @Builder
  MyMenu1() {
    Menu() {
      MenuItem({ startIcon: this.iconStr, content: '菜单选项' })
      MenuItem({ startIcon: this.iconStr, content: '菜单选项' })
      MenuItem({ startIcon: this.iconStr, content: '菜单选项' })
      MenuItem({ startIcon: this.iconStr, content: '菜单选项' })
    }
  }

  @State isShow: boolean = false;

  build() {
    RelativeContainer() {
      Column() {
        Button('区域:' + this.arrayStr[this.index])
          .onClick(() => {
            if (this.index < 2) {
              this.index++
            } else {
              this.index = 0
            }
          })

        Button('hoverMode开启:' + this.enableHoverMode)
          .onClick(() => {
            if (this.enableHoverMode == undefined) {
              this.enableHoverMode = true
            } else if (this.enableHoverMode == true) {
              this.enableHoverMode = false
            } else {
              this.enableHoverMode = undefined
            }
          })

        Button('MenuPlacement:' + this.placement)
          .onClick(() => {
            if (this.placement == undefined) {
              this.placement = Placement.Bottom
            } else if (this.placement == Placement.Bottom) {
              this.placement = Placement.Top
            } else {
              this.placement = undefined
            }
          })
      }

      Row() {
        Button('Menu')
          .fontWeight(FontWeight.Bold)
          .bindMenu(this.MyMenu1(), {
            enableHoverMode: this.enableHoverMode,
            showInSubWindow: this.showInSubwindow,
            placement: this.placement
          })

        Select([{ value: 'text1' }, { value: 'text2' }, { value: 'text3' }, { value: 'text4' }, { value: 'text5' },
          { value: 'text6' }, { value: 'text7' }, { value: 'text8' }, { value: 'text9' }, { value: 'text10' }, { value: 'text11' },
          { value: 'text12' }])
          .value("Select")

      }
      .alignRules({
        center: { anchor: '__container__', align: VerticalAlign.Center },
        middle: { anchor: '__container__', align: HorizontalAlign.Center }
      })
      .margin({
        top: this.index == 2 ? 330 : this.index == 1 ? 50 : 0,
        bottom: this.index == 0 ? 330 : 0
      })
    }
    .height('100%')
    .width('100%')
  }
}

```

## 控制子窗菜单的事件透传

当菜单在子窗口中弹出时，默认情况下，菜单周围的事件会传递至所在窗口。从API version 20开始，开发者可通过[ContextMenuOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#contextmenuoptions10)的modalMode属性设置子菜单弹出时的模态模式，以控制菜单周围事件是否传递。将modalMode设置为ModalMode.TARGET_WINDOW时，菜单周围的事件将不再传递，菜单下方的控件也不会响应事件。

```ts
@Entry
@Component
struct Index2 {
  build() {
    Column() {
    }
    .bindContextMenu(this.contextMenuBuilder, ResponseType.RightClick, {
      modalMode: ModalMode.TARGET_WINDOW
    })
    .onClick(() => {
      this.getUIContext().getPromptAction().showToast({
        message: 'Clicked!'
      })
    })
    .width('100%')
    .height('100%')
  }

  @Builder
  bindMenuBuilder() {
    Menu() {
      MenuItem({ content: 'bindMenu item' }) {

      }
    }
  }

  @Builder
  contextMenuBuilder() {
    Menu() {
      MenuItem({ content: 'contextMenu item' }) {

      }
    }
  }
}

```