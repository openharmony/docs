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

## 弹出框组件

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

### ActionSheet.show

ArkTS1.1接口声明：[static show(value: ActionSheetOptions)](../reference/apis-arkui/arkui-ts/ts-methods-action-sheet.md#showdeprecated)

替代的ArkTS1.2接口声明：[showActionSheet(value: ActionSheetOptions): void)](../reference/apis-arkui/js-apis-arkui-UIContext.md#showactionsheet)

适配方法如下：

ArkTS1.1

```
@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('click').onClick(() => {
        try {
          ActionSheet.show({
            title: 'ActionSheet',
            message: 'message',
            autoCancel: true,
            alignment: DialogAlignment.Bottom,
            offset: { dx: 0, dy: -20 },
            confirm: {
              value: 'button',
              action: () => {
                console.info('ActionSheet Button-clicking callback');
              }
            },
            cancel: () => {
              console.info('ActionSheet Closed callbacks');
            },
            sheets: [
            {
              title: 'apples',
              action: () => {
                console.info('ActionSheet apples')
              }
            },
            {
              title: 'bananas',
              action: () => {
                console.info('ActionSheet bananas')
              }
            },
            {
              title: 'pears',
              action: () => {
                console.info('ActionSheet pears')
              }
            }
            ],
            onDidAppear: () => {
              console.info("ActionSheet is onDidAppear!");
            },
            onDidDisappear: () => {
              console.info("ActionSheet is onDidDisappear!");
            },
            onWillAppear: () => {
              console.info("ActionSheet is onWillAppear!");
            },
            onWillDisappear: () => {
              console.info("ActionSheet is onWillDisappear!");
            }
          })
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showActionSheet args error code is ${code}, message is ${message}`);
        };
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
  build() {
    Column() {
      Button('click').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().showActionSheet({
            title: 'ActionSheet',
            message: 'message',
            autoCancel: true,
            alignment: DialogAlignment.Bottom,
            offset: { dx: 0, dy: -20 },
            confirm: {
              value: 'button',
              action: () => {
                console.info('ActionSheet Button-clicking callback');
              }
            },
            cancel: () => {
              console.info('ActionSheet Closed callbacks');
            },
            sheets: [
            {
              title: 'apples',
              action: () => {
                console.info('ActionSheet apples')
              }
            },
            {
              title: 'bananas',
              action: () => {
                console.info('ActionSheet bananas')
              }
            },
            {
              title: 'pears',
              action: () => {
                console.info('ActionSheet pears')
              }
            }
            ],
            onDidAppear: () => {
              console.info("ActionSheet is onDidAppear!");
            },
            onDidDisappear: () => {
              console.info("ActionSheet is onDidDisappear!");
            },
            onWillAppear: () => {
              console.info("ActionSheet is onWillAppear!");
            },
            onWillDisappear: () => {
              console.info("ActionSheet is onWillDisappear!");
            }
          })
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showActionSheet args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

### AlertDialog.show

ArkTS1.1接口声明：[static show(value: AlertDialogParamWithConfirm | AlertDialogParamWithButtons | AlertDialogParamWithOptions)](../reference/apis-arkui/arkui-ts/ts-methods-alert-dialog-box.md#showdeprecated)

替代的ArkTS1.2接口声明：[showAlertDialog(options: AlertDialogParamWithConfirm | AlertDialogParamWithButtons | AlertDialogParamWithOptions): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showalertdialog)

适配方法如下：

ArkTS1.1

```
@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('one button dialog').onClick(() => {
        try {
          AlertDialog.show({
            title: 'title',
            message: 'text',
            autoCancel: true,
            alignment: DialogAlignment.Bottom,
            offset: { dx: 0, dy: -20 },
            gridCount: 3,
            confirm: {
              value: 'button',
              action: () => {
                console.info('Button-clicking callback')
              }
            },
            cancel: () => {
              console.info('Closed callbacks')
            },
            onDidAppear: () => {
              console.info("AlertDialog is onDidAppear!");
            },
            onDidDisappear: () => {
              console.info("AlertDialog is onDidDisappear!");
            },
            onWillAppear: () => {
              console.info("AlertDialog is onWillAppear!");
            },
            onWillDisappear: () => {
              console.info("AlertDialog is onWillDisappear!");
            }
          })
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showAlertDialog args error code is ${code}, message is ${message}`);
        };
      })

      Button('two button dialog').onClick(() => {
        try {
          AlertDialog.show({
            title: 'title',
            message: 'text',
            autoCancel: true,
            alignment: DialogAlignment.Bottom,
            offset: { dx: 0, dy: -20 },
            gridCount: 3,
            primaryButton: {
              value: 'cancel',
              action: () => {
                console.info('Callback when the first button is clicked');
              }
            },
            secondaryButton: {
              enabled: true,
              defaultFocus: true,
              style: DialogButtonStyle.HIGHLIGHT,
              value: 'ok',
              action: () => {
                console.info('Callback when the second button is clicked');
              }
            },
            cancel: () => {
              console.info('Closed callbacks')
            },
            onDidAppear: () => {
              console.info("AlertDialog is onDidAppear!");
            },
            onDidDisappear: () => {
              console.info("AlertDialog is onDidDisappear!");
            },
            onWillAppear: () => {
              console.info("AlertDialog is onWillAppear!");
            },
            onWillDisappear: () => {
              console.info("AlertDialog is onWillDisappear!");
            }
          })
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showAlertDialog args error code is ${code}, message is ${message}`);
        };
      })

      Button('three button dialog').onClick(() => {
        try {
          AlertDialog.show({
            title: 'title',
            message: 'text',
            autoCancel: true,
            alignment: DialogAlignment.Bottom,
            offset: { dx: 0, dy: -20 },
            gridCount: 3,
            buttons: [
              {
                value: '按钮',
                action: () => {
                  console.info('Callback when button1 is clicked');
                }
              },
              {
                value: '按钮',
                action: () => {
                  console.info('Callback when button2 is clicked');
                }
              },
              {
                value: '按钮',
                enabled: true,
                defaultFocus: true,
                style: DialogButtonStyle.HIGHLIGHT,
                action: () => {
                  console.info('Callback when button3 is clicked');
                }
              },
            ],
            cancel: () => {
              console.info('Closed callbacks')
            },
            onDidAppear: () => {
              console.info("AlertDialog is onDidAppear!");
            },
            onDidDisappear: () => {
              console.info("AlertDialog is onDidDisappear!");
            },
            onWillAppear: () => {
              console.info("AlertDialog is onWillAppear!");
            },
            onWillDisappear: () => {
              console.info("AlertDialog is onWillDisappear!");
            }
          })
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showAlertDialog args error code is ${code}, message is ${message}`);
        };
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
  build() {
    Column() {
      Button('one button dialog').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().showAlertDialog({
            title: 'title',
            message: 'text',
            autoCancel: true,
            alignment: DialogAlignment.Bottom,
            offset: { dx: 0, dy: -20 },
            gridCount: 3,
            confirm: {
              value: 'button',
              action: () => {
                console.info('Button-clicking callback')
              }
            },
            cancel: () => {
              console.info('Closed callbacks')
            },
            onDidAppear: () => {
              console.info("AlertDialog is onDidAppear!");
            },
            onDidDisappear: () => {
              console.info("AlertDialog is onDidDisappear!");
            },
            onWillAppear: () => {
              console.info("AlertDialog is onWillAppear!");
            },
            onWillDisappear: () => {
              console.info("AlertDialog is onWillDisappear!");
            }
          } as AlertDialogParamWithConfirm)
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showAlertDialog args error code is ${code}, message is ${message}`);
        };
      })

      Button('two button dialog').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().showAlertDialog({
            title: 'title',
            message: 'text',
            autoCancel: true,
            alignment: DialogAlignment.Bottom,
            offset: { dx: 0, dy: -20 },
            gridCount: 3,
            primaryButton: {
              value: 'cancel',
              action: () => {
                console.info('Callback when the first button is clicked');
              }
            },
            secondaryButton: {
              enabled: true,
              defaultFocus: true,
              style: DialogButtonStyle.HIGHLIGHT,
              value: 'ok',
              action: () => {
                console.info('Callback when the second button is clicked');
              }
            },
            cancel: () => {
              console.info('Closed callbacks')
            },
            onDidAppear: () => {
              console.info("AlertDialog is onDidAppear!");
            },
            onDidDisappear: () => {
              console.info("AlertDialog is onDidDisappear!");
            },
            onWillAppear: () => {
              console.info("AlertDialog is onWillAppear!");
            },
            onWillDisappear: () => {
              console.info("AlertDialog is onWillDisappear!");
            }
          } as AlertDialogParamWithButtons)
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showAlertDialog args error code is ${code}, message is ${message}`);
        };
      })

      Button('three button dialog').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().showAlertDialog({
            title: 'title',
            message: 'text',
            autoCancel: true,
            alignment: DialogAlignment.Bottom,
            offset: { dx: 0, dy: -20 },
            gridCount: 3,
            buttons: [
              {
                value: '按钮',
                action: () => {
                  console.info('Callback when button1 is clicked');
                }
              },
              {
                value: '按钮',
                action: () => {
                  console.info('Callback when button2 is clicked');
                }
              },
              {
                value: '按钮',
                enabled: true,
                defaultFocus: true,
                style: DialogButtonStyle.HIGHLIGHT,
                action: () => {
                  console.info('Callback when button3 is clicked');
                }
              },
            ],
            cancel: () => {
              console.info('Closed callbacks')
            },
            onDidAppear: () => {
              console.info("AlertDialog is onDidAppear!");
            },
            onDidDisappear: () => {
              console.info("AlertDialog is onDidDisappear!");
            },
            onWillAppear: () => {
              console.info("AlertDialog is onWillAppear!");
            },
            onWillDisappear: () => {
              console.info("AlertDialog is onWillDisappear!");
            }
          } as AlertDialogParamWithOptions)
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showAlertDialog args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

### showActionMenu

ArkTS1.1接口声明：

[showActionMenu(options: promptAction.ActionMenuOptions, callback: promptAction.ActionMenuSuccessResponse): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showactionmenudeprecated)

替代的ArkTS1.2接口声明：

[showActionMenu(options: promptAction.ActionMenuOptions, callback: AsyncCallback<promptAction.ActionMenuSuccessResponse>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showactionmenu11)

适配方法如下：

ArkTS1.1

```
@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('click').onClick(() => {
        try {
          this.getUIContext().getPromptAction().showActionMenu({
            title: 'Title Info',
            buttons: [
              {
                text: 'item1',
                color: '#666666'
              },
              {
                text: 'item2',
                color: '#000000'
              }
            ]
          }, (err, data) => {
            if (err) {
              console.error('showActionMenu err: ' + err);
              return;
            }
            console.info('showActionMenu success callback, click button: ' + data.index);
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showActionMenu args error code is ${code}, message is ${message}`);
        };
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
  build() {
    Column() {
      Button('click').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().getPromptAction().showActionMenu({
            title: 'Title Info',
            buttons: [
              {
                text: 'item1',
                color: '#666666'
              },
              {
                text: 'item2',
                color: '#000000'
              }
            ] as promptAction.PromptActionDoubleButtons
          }, (err: BusinessError|null, data: promptAction.ActionMenuSuccessResponse|undefined) => {
            if (err) {
              console.error('showActionMenu err: ' + err);
              return;
            }
            if (data) {
              console.info('showActionMenu success callback, click button: ' + data.index);
            }
          });
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showActionMenu args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

### showActionMenu

由@ohos.prompt、@ohos.promptAction提供的showActionMenu接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

ArkTS1.1接口声明：

引用@ohos.prompt的[showActionMenu(options: ActionMenuOptions, callback: AsyncCallback<ActionMenuSuccessResponse>): void](../reference/apis-arkui/js-apis-prompt.md#promptshowactionmenu)

引用@ohos.promptAction的[showActionMenu(options: ActionMenuOptions, callback: AsyncCallback<ActionMenuSuccessResponse>): void](../reference/apis-arkui/js-apis-promptAction.md#promptactionshowactionmenudeprecated)

替代的ArkTS1.2接口声明：

引用@ohos.arkui.UIContext的[showActionMenu(options: promptAction.ActionMenuOptions, callback: AsyncCallback<promptAction.ActionMenuSuccessResponse>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showactionmenu11)

适配方法如下：

ArkTS1.1

引用@ohos.prompt的showActionMenu。

```
import prompt from '@ohos.prompt';

@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('click').onClick(() => {
        try {
          prompt.showActionMenu({
            title: 'Title Info',
            buttons: [
              {
                text: 'item1',
                color: '#666666'
              },
              {
                text: 'item2',
                color: '#000000'
              }
            ]
          }, (err, data) => {
            if (err) {
              console.error('showActionMenu err: ' + err);
              return;
            }
            console.info('showActionMenu success callback, click button: ' + data.index);
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showActionMenu args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

引用@ohos.promptAction的showActionMenu。

```
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('click').onClick(() => {
        try {
          promptAction.showActionMenu({
            title: 'Title Info',
            buttons: [
              {
                text: 'item1',
                color: '#666666'
              },
              {
                text: 'item2',
                color: '#000000'
              }
            ]
          }, (err, data) => {
            if (err) {
              console.error('showActionMenu err: ' + err);
              return;
            }
            console.info('showActionMenu success callback, click button: ' + data.index);
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showActionMenu args error code is ${code}, message is ${message}`);
        };
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
  build() {
    Column() {
      Button('click').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().getPromptAction().showActionMenu({
            title: 'Title Info',
            buttons: [
              {
                text: 'item1',
                color: '#666666'
              },
              {
                text: 'item2',
                color: '#000000'
              }
            ] as promptAction.PromptActionDoubleButtons
          }, (err: BusinessError|null, data: promptAction.ActionMenuSuccessResponse|undefined) => {
            if (err) {
              console.error('showActionMenu err: ' + err);
              return;
            }
            if (data) {
              console.info('showActionMenu success callback, click button: ' + data.index);
            }
          });
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showActionMenu args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

### showActionMenu

由@ohos.prompt、@ohos.promptAction提供的showActionMenu接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

ArkTS1.1接口声明：

引用@ohos.prompt的[showActionMenu(options: ActionMenuOptions): Promise<ActionMenuSuccessResponse>](../reference/apis-arkui/js-apis-prompt.md#promptshowactionmenu-1)

引用@ohos.promptAction的[showActionMenu(options: ActionMenuOptions): Promise<ActionMenuSuccessResponse>](../reference/apis-arkui/js-apis-promptAction.md#promptactionshowactionmenudeprecated-1)

替代的ArkTS1.2接口声明：

引用@ohos.arkui.UIContext的[showActionMenu(options: promptAction.ActionMenuOptions): Promise<promptAction.ActionMenuSuccessResponse>](../reference/apis-arkui/js-apis-arkui-UIContext.md#showactionmenu)

适配方法如下：

ArkTS1.1

引用@ohos.prompt的showActionMenu。

```
import prompt from '@ohos.prompt';

@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('click').onClick(() => {
        try {
          prompt.showActionMenu({
            title: 'Title Info',
            buttons: [
              {
                text: 'item1',
                color: '#666666'
              },
              {
                text: 'item2',
                color: '#000000'
              }
            ]
          }).then((data) => {
            console.info('showActionMenu success callback, click button: ' + data.index);
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showActionMenu args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

引用@ohos.promptAction的showActionMenu。

```
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('click').onClick(() => {
        try {
          promptAction.showActionMenu({
            title: 'Title Info',
            buttons: [
              {
                text: 'item1',
                color: '#666666'
              },
              {
                text: 'item2',
                color: '#000000'
              }
            ]
          }).then((data) => {
            console.info('showActionMenu success callback, click button: ' + data.index);
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showActionMenu args error code is ${code}, message is ${message}`);
        };
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
  build() {
    Column() {
      Button('click').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().getPromptAction().showActionMenu({
            title: 'Title Info',
            buttons: [
              {
                text: 'item1',
                color: '#666666'
              },
              {
                text: 'item2',
                color: '#000000'
              }
            ] as promptAction.PromptActionDoubleButtons
          }).then((data: promptAction.ActionMenuSuccessResponse) => {
            console.info('showActionMenu success callback, click button: ' + data.index);
          });
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showActionMenu args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

### showDialog

由@ohos.prompt、@ohos.promptAction提供的showDialog接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

ArkTS1.1接口声明：

引用@ohos.prompt的[showDialog(options: ShowDialogOptions, callback: AsyncCallback<ShowDialogSuccessResponse>)](../reference/apis-arkui/js-apis-prompt.md#promptshowdialog-1)

引用@ohos.promptAction的[showDialog(options: ShowDialogOptions, callback: AsyncCallback<ShowDialogSuccessResponse>)](../reference/apis-arkui/js-apis-promptAction.md#promptactionshowdialogdeprecated-1)

替代的ArkTS1.2接口声明：

引用@ohos.arkui.UIContext的[showDialog(options: promptAction.ShowDialogOptions, callback: AsyncCallback<promptAction.ShowDialogSuccessResponse>): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#showdialog)

适配方法如下：

ArkTS1.1

引用@ohos.prompt的showDialog。

```
import prompt from '@ohos.prompt';

@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('click').onClick(() => {
        try {
          prompt.showDialog({
            title: 'showDialog Title Info',
            message: 'Message Info',
            buttons: [
              {
                text: 'button1',
                color: '#000000'
              },
              {
                text: 'button2',
                color: '#000000'
              }
            ]
          }, (err, data) => {
            if (err) {
              console.error('showDialog err: ' + err);
              return;
            }
            console.info('showDialog success callback, click button: ' + data.index);
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showDialog args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

引用@ohos.promptAction的showDialog。

```
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('click').onClick(() => {
        try {
          promptAction.showDialog({
            title: 'showDialog Title Info',
            message: 'Message Info',
            buttons: [
              {
                text: 'button1',
                color: '#000000'
              },
              {
                text: 'button2',
                color: '#000000'
              }
            ]
          }, (err, data) => {
            if (err) {
              console.error('showDialog err: ' + err);
              return;
            }
            console.info('showDialog success callback, click button: ' + data.index);
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showDialog args error code is ${code}, message is ${message}`);
        };
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
  build() {
    Column() {
      Button('click').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().getPromptAction().showDialog({
            title: 'showDialog Title Info',
            message: 'Message Info',
            buttons: [
              {
                text: 'button1',
                color: '#000000'
              },
              {
                text: 'button2',
                color: '#000000'
              }
            ]
          }, (err: BusinessError|null, data: promptAction.ShowDialogSuccessResponse|undefined) => {
            if (err) {
              console.error('showDialog err: ' + err);
              return;
            }
            if (data) {
              console.info('showDialog success callback, click button: ' + data.index);
            }
          });
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showDialog args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

### showDialog

由@ohos.prompt、@ohos.promptAction提供的showDialog接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

ArkTS1.1接口声明：

引用@ohos.prompt的[showDialog(options: ShowDialogOptions): Promise<ShowDialogSuccessResponse>](../reference/apis-arkui/js-apis-prompt.md#promptshowdialog)

引用@ohos.promptAction的[showDialog(options: ShowDialogOptions): Promise<ShowDialogSuccessResponse>](../reference/apis-arkui/js-apis-promptAction.md#promptactionshowdialogdeprecated)

替代的ArkTS1.2接口声明：

引用@ohos.arkui.UIContext的[showDialog(options: promptAction.ShowDialogOptions): Promise<promptAction.ShowDialogSuccessResponse>](../reference/apis-arkui/js-apis-arkui-UIContext.md#showdialog-1)

适配方法如下：

ArkTS1.1

引用@ohos.prompt的showActionMenu。

```
import prompt from '@ohos.prompt';

@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('click').onClick(() => {
        try {
          prompt.showDialog({
            title: 'showDialog Title Info',
            message: 'Message Info',
            buttons: [
              {
                text: 'button1',
                color: '#000000'
              },
              {
                text: 'button2',
                color: '#000000'
              }
            ]
          }).then((data) => {
            console.info('showDialog success callback, click button: ' + data.index);
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showDialog args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

引用@ohos.promptAction的showActionMenu。

```
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct Example {
  build() {
    Column() {
      Button('click').onClick(() => {
        try {
          promptAction.showDialog({
            title: 'showDialog Title Info',
            message: 'Message Info',
            buttons: [
              {
                text: 'button1',
                color: '#000000'
              },
              {
                text: 'button2',
                color: '#000000'
              }
            ]
          }).then((data) => {
            console.info('showDialog success callback, click button: ' + data.index);
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showDialog args error code is ${code}, message is ${message}`);
        };
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
  build() {
    Column() {
      Button('click').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().getPromptAction().showDialog({
            title: 'showDialog Title Info',
            message: 'Message Info',
            buttons: [
              {
                text: 'button1',
                color: '#000000'
              },
              {
                text: 'button2',
                color: '#000000'
              }
            ]
          }).then((data: promptAction.ShowDialogSuccessResponse) => {
            console.info('showDialog success callback, click button: ' + data.index);
          });
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`showDialog args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

### openCustomDialog

由@ohos.promptAction提供的openCustomDialog接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

ArkTS1.1接口声明：

引用@ohos.promptAction的[openCustomDialog(options: CustomDialogOptions): Promise<number>](../reference/apis-arkui/js-apis-promptAction.md#promptactionopencustomdialogdeprecated)

替代的ArkTS1.2接口声明：

引用@ohos.arkui.UIContext的[openCustomDialog(options: promptAction.CustomDialogOptions): Promise<number>](../reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialog12-1)

适配方法如下：

ArkTS1.1

引用@ohos.promptAction的openCustomDialog。

```
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct Example {
  private customDialogComponentId: number = 0
  @Builder customDialogComponent() {
    Column() {
      Text('Dialog').fontSize(30)
      Button('Close').onClick(() => {
        try {
          this.getUIContext().getPromptAction().closeCustomDialog(this.customDialogComponentId)
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`closeCustomDialog error code is ${code}, message is ${message}`);
        }
      })
    }
  }

  build() {
    Column() {
      Button('click').onClick((e: ClickEvent) => {
        try {
          promptAction.openCustomDialog({
            builder: () => {
              this.customDialogComponent()
            },
          }).then((dialogId: number) => {
            this.customDialogComponentId = dialogId;
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`openCustomDialog args error code is ${code}, message is ${message}`);
        };
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
  private customDialogComponentId: number = 0
  @Builder customDialogComponent() {
    Column() {
      Text('Dialog').fontSize(30)
      Button('Close').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().getPromptAction().closeCustomDialog(this.customDialogComponentId)
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`closeCustomDialog error code is ${code}, message is ${message}`);
        }
      })
    }
  }

  build() {
    Column() {
      Button('click').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().getPromptAction().openCustomDialog({
            builder: this.customDialogComponent,
          } as promptAction.CustomDialogOptions
          ).then((dialogId: number) => {
            this.customDialogComponentId = dialogId;
          });
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`openCustomDialog args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```

### closeCustomDialog

由@ohos.promptAction提供的closeCustomDialog接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

ArkTS1.1接口声明：

引用@ohos.promptAction的[closeCustomDialog(dialogId: number): void](../reference/apis-arkui/js-apis-promptAction.md#promptactionclosecustomdialogdeprecated)

替代的ArkTS1.2接口声明：

引用@ohos.arkui.UIContext的[closeCustomDialog(dialogId: number): void](../reference/apis-arkui/js-apis-arkui-UIContext.md#closecustomdialog12-1)

适配方法如下：

ArkTS1.1

引用@ohos.promptAction的closeCustomDialog。

```
import promptAction from '@ohos.promptAction';

@Entry
@Component
struct Example {
  private customDialogComponentId: number = 0
  @Builder customDialogComponent() {
    Column() {
      Text('Dialog').fontSize(30)
      Button('Close').onClick(() => {
        try {
          this.getUIContext().getPromptAction().closeCustomDialog(this.customDialogComponentId)
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`closeCustomDialog error code is ${code}, message is ${message}`);
        }
      })
    }
  }

  build() {
    Column() {
      Button('click').onClick((e: ClickEvent) => {
        try {
          promptAction.openCustomDialog({
            builder: () => {
              this.customDialogComponent()
            },
          }).then((dialogId: number) => {
            this.customDialogComponentId = dialogId;
          });
        } catch (error) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`openCustomDialog args error code is ${code}, message is ${message}`);
        };
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
  private customDialogComponentId: number = 0
  @Builder customDialogComponent() {
    Column() {
      Text('Dialog').fontSize(30)
      Button('Close').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().getPromptAction().closeCustomDialog(this.customDialogComponentId)
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`closeCustomDialog error code is ${code}, message is ${message}`);
        }
      })
    }
  }

  build() {
    Column() {
      Button('click').onClick((e: ClickEvent) => {
        try {
          this.getUIContext().getPromptAction().openCustomDialog({
            builder: this.customDialogComponent,
          } as promptAction.CustomDialogOptions
          ).then((dialogId: number) => {
            this.customDialogComponentId = dialogId;
          });
        } catch (error: BusinessError) {
          let message = (error as BusinessError).message;
          let code = (error as BusinessError).code;
          console.error(`openCustomDialog args error code is ${code}, message is ${message}`);
        };
      })
    }
  }
}
```
