# 弹窗类组件

## Popup控制

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

### placementOnTop

ArkTS1.1接口声明：[placementOnTop?: boolean](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#popupoptions类型说明)

替代的ArkTS1.2接口声明：[placement?: Placement](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#popupoptions类型说明)

适配方法如下：

ArkTS1.1

```
@Entry
@Component
struct Example {
    @State handlePopup: boolean = false;
    build() {
        Column() {
            Button('click').onClick((e: ClickEvent) => {
                this.handlePopup = !this.handlePopup;
            }).bindPopup(this.handlePopup, {message: 'test', placementOnTop: true}).position({x:0, y: 300})
        }
    }
}
```

ArkTS1.2

```
@Entry
@Component
struct Example {
    @State handlePopup: boolean = false;
    build() {
        Column() {
            Button('click').onClick((e: ClickEvent) => {
                this.handlePopup = !this.handlePopup;
            }).bindPopup(this.handlePopup, {message: 'test', placement: Placement.Top}).position({x:0, y: 300})
        }
    }
}
```

### maskColor

ArkTS1.1接口声明：[maskColor?: Resource | string | number | Color](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#custompopupoptions8类型说明)

替代的ArkTS1.2接口声明：[mask?: boolean | PopupMaskType](../reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#custompopupoptions8类型说明)

适配方法如下：

ArkTS1.1

```
@Entry
@Component
struct Example {
    @State customPopup: boolean = false;
    
    @Builder popupBuilder() {
        Row() {
            Text('Custom Popup')
        }
    }

    build() {
        Column() {
            Button('click').onClick((e: ClickEvent) => {
                this.customPopup = !this.customPopup;
            }).bindPopup(this.customPopup, {builder: this.popupBuilder, maskColor: Color.Red})
        }
    }
}

```

ArkTS1.2

```
@Entry
@Component
struct Example {
    @State customPopup: boolean = false;

    @Builder popupBuilder() {
        Row() {
            Text('Custom Popup')
        }
    }

    build() {
        Column() {
            Button('click').onClick((e: ClickEvent) => {
                this.customPopup = !this.customPopup;
            }).bindPopup(this.customPopup, {builder: this.popupBuilder, mask: { color: Color.Red } as PopupMaskType})
        }
    }
}
```

## 菜单组件

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

### fontSize

ArkTS1.1接口声明：[fontSize(value: Length)](../reference/apis-arkui/arkui-ts/ts-basic-components-menu.md#fontsizedeprecated)

替代的ArkTS1.2接口声明：[font(value: Font)](../reference/apis-arkui/arkui-ts/ts-basic-components-menu.md#font10)

适配方法如下：

ArkTS1.1

```
@Entry
@Component
struct Example {
    private iconStr: ResourceStr = $r('app.media.icon');

    @Builder
    MyMenu() {
        Menu() {
            MenuItem({startIcon: this.iconStr, content: '菜单选项'})
        }.fontSize(40)
    }

    build() {
        Column() {
            Text('preview-menu').bindContextMenu(this.MyMenu, ResponseType.LongPress, {
                preview: MenuPreviewMode.IMAGE
            })
        }
    }
}
```

ArkTS1.2

```
@Entry
@Component
struct Example {
    private iconStr: ResourceStr = $r('app.media.icon');

    @Builder
    MyMenu() {
        Menu() {
            MenuItem({startIcon: this.iconStr, content: '菜单选项'})
        }.font({
            size: 40
        })
    }

    build() {
        Column() {
            Text('preview-menu').bindContextMenu(this.MyMenu, ResponseType.LongPress, {
                preview: MenuPreviewMode.IMAGE
            })
        }
    }
}
```

## Toast组件（即时反馈）

### showToast

由@ohos.prompt、@system.prompt、@ohos.promptAction提供的showToast接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

ArkTS1.1接口声明：

[引用@ohos.prompt的showToast(options: ShowToastOptions): void](../reference/apis-arkui/js-apis-prompt.md#promptshowtoast)

[引用@system.prompt的showToast(options: ShowToastOptions): void](../reference/apis-arkui/js-apis-system-prompt.md#promptshowtoast)

[引用@ohos.promptAction的showToast(options: ShowToastOptions): void](../reference/apis-arkui/js-apis-promptAction.md#promptactionshowtoastdeprecated)

替代的ArkTS1.2接口声明：

[引用@ohos.arkui.UIContext的showToast(options: promptAction.ShowToastOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showtoast)

适配方法如下：

ArkTS1.1

引用@ohos.prompt的showToast

```
import prompt from '@ohos.prompt'
@Entry
@Component
struct Example {
    build() {
        Column() {
           Button('show toast from ohos.prompt').onClick((e: ClickEvent) => {
                prompt.showToast({
                    message: 'test',
                    duration: 2000
                })
           })
        }
    }
}
```

引用@system.prompt的showToast

```
import prompt from '@system.prompt'
@Entry
@Component
struct Example {
    build() {
        Column() {
           Button('show toast from system.prompt').onClick((e: ClickEvent) => {
                prompt.showToast({
                    message: 'test',
                    duration: 2000
                })
           })
        }
    }
}
```

引用@ohos.promptAction的showToast

```
import promptAction from '@ohos.promptAction'
@Entry
@Component
struct Example {
    build() {
        Column() {
           Button('show toast from ohos.promptAction').onClick((e: ClickEvent) => {
                promptAction.showToast({
                    message: 'test',
                    duration: 2000
                })
           })
        }
    }
}
```


ArkTS1.2

改用UIContext下的showToast方法

```
@Entry
@Component
struct Example {
    uiContext: UIContext = this.getUIContext();

    build() {
        Column() {
            Button('show toast from uicontext').onClick((e: ClickEvent) => {
                this.uiContext.getPromptAction().showToast({
                    message: 'test',
                    duration: 2000
                })
           })
        }
    }
}
```
