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

## 基于绑定组件弹出菜单

菜单从API version 20开始支持基于绑定组件在指定位置弹出菜单。通过设定水平与垂直偏移量，控制菜单相对于绑定组件左上角的弹出位置，与单独使用offset接口不同的是可以覆盖显示在绑定组件上。需要指定弹出位置时，可以通过[ContextMenuOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#contextmenuoptions10)的anchorPosition属性进行设置。

说明：
- 当菜单处于预览状态时，设定的定位偏移量将无法生效。
- 预设的placement对齐参数将不再生效。
- 叠加offset参数的偏移量，最终确定菜单的精确显示位置。
- 当水平与垂直偏移量均设为负值时，菜单以绑定组件左下角为基准点进行显示。
- 当水平或垂直偏移量存在负值时，组件将以绑定组件的左上角为定位基准点，通过叠加偏移量参数实现反向偏移。

示例
```ts
@Entry
@Component
struct DirectiveMenuExample {
  @Builder
  MenuBuilder() {
    Column() {
      Text('Options')
      Divider().strokeWidth(2).margin(5).color('#F0F0F0')
      Text('Hide')
      Divider().strokeWidth(2).margin(5).color('#F0F0F0')
      Text('Exit')
    }
    .width(100)
  }

  build() {
    Column() {
      Text("bindContextMenu")
        .id("bindContextMenuAnchorPosition")
        .width(200)
        .height(100)
        .backgroundColor('#F0F0F0')
        .margin({ top: 50, left: 150 })
        .bindContextMenu(this.MenuBuilder, ResponseType.RightClick, {
          anchorPosition: { x: 10, y: 20 },
        })
    }
    .alignItems(HorizontalAlign.Start)
    .width('100%')
    .height('100%')
  }
}
```

