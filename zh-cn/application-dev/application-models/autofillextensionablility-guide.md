# AutoFillExtensionAbility

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45; @Luobniz21-->
<!--SE: @ccllee1-->
<!--TSE: @lixueqing513-->

## 概述

[AutoFillExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md)是AUTO_FILL_PASSWORD/AUTO_FILL_SMART类型的[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)组件，提供自动填充能力。

自动填充能力根据自动填充控件内容的不同分为账号密码自动填充、情景化自动填充。

- 账号密码自动填充：帮助用户自动填充已保存的账号密码，提高用户输入信息的效率。
- 情景化自动填充：根据组件的使用场景实现手机号、地址等信息的自动填充。

## 接口说明

自动填充功能主要接口如下。其他接口介绍详情参见[AutoFillRequest](../reference/apis-ability-kit/js-apis-inner-application-autoFillRequest-sys.md)、[AutoFillExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md)。

| 接口名称                                                     | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onFillRequest(session: UIExtensionContentSession, request: FillRequest, callback: FillRequestCallback): void | 当发起自动填充请求或者生成密码时触发此回调函数。             |
| onSaveRequest(session: UIExtensionContentSession, request: SaveRequest, callback: SaveRequestCallback): void | 当发起自动保存或者手动保存时触发此回调函数。                 |
| FillRequestCallback.onSuccess(response: FillResponse): void  | 自动填充或者生成密码时的回调对象，可以通过此回调通知客户端成功。 |

## 开发步骤

为了便于表述，本例中将提供[AutoFillExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md)能力的一方称为提供方，将启动AutoFillExtensionAbility的一方称为使用方。

### 开发AutoFillExtensionAbility提供方

#### 生命周期

[AutoFillExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md)提供了[onCreate](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#oncreate)、[onSessionDestroy](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#onsessiondestroy)、[onForeground](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#onforeground)、[onBackground](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#onbackground)、[onDestroy](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#ondestroy)、[onSaveRequest](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#onsaverequest)和[onFillRequest](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#onfillrequest)生命周期回调，根据需要重写对应的回调方法。

- **onCreate**：当AutoFillExtensionAbility创建时回调，执行初始化业务逻辑操作。
- **onSessionDestroy**：当AutoFillExtensionAbility界面内容对象销毁后调用。
- **onForeground**：当AutoFillExtensionAbility从后台转到前台时触发。
- **onBackground**：当AutoFillExtensionAbility从前台转到后台时触发。
- **onDestroy**：当AutoFillExtensionAbility销毁时回调，可以执行资源清理等操作。
- **onSaveRequest**：表单中有数据存在并且切换页面时，会触发自动保存的生命周期回调。
- **onFillRequest**：当fill request发送请求的时候，实现账号密码自动填充。

#### 实现账号密码自动填充功能

开发者在实现自动填充服务时，需要在DevEco Studio工程中手动新建一个AutoFillExtensionAbility。

1. 设定AutoFillExtensionAbility应用的包名。

   在AppScope/[app.json5配置文件](../quick-start/app-configuration-file.md)中把bundleName设定为："com.ohos.passwordbox"，例如：

   ```json
   "app": {
     "bundleName": "com.ohos.passwordbox",
      // ...
   }
   ```

2. 配置extensionAbilities信息。

   在entry/src/main/[module.json5配置文件](../quick-start/module-configuration-file.md)中配置AutoFillAbility，例如：

   ```json
   "extensionAbilities": [
      {
        "name": "AutoFillAbility",
        "srcEntry": "./ets/autofillability/AutoFillAbility.ets",
        // ...
        "type": "autoFill/password"
      }
   ]
   ```
   
3. 实现自动填充与自动保存。

   1. 在ets目录右键选择“New &gt; Directory”，新建一个目录并命名为autofillability。

   2. 在autofillability目录，右键选择“New &gt; File”，新建一个.ets文件并命名为AutoFillAbility.ets。例如：

      ```ts
      import { hilog } from '@kit.PerformanceAnalysisKit';
      import { AutoFillExtensionAbility, autoFillManager, UIExtensionContentSession } from '@kit.AbilityKit';

      class AutoFillAbility extends AutoFillExtensionAbility {
        // ...
        // 自动填充服务发起自动填充请求时会触发onFillRequest的生命周期
        onFillRequest(session: UIExtensionContentSession, request: autoFillManager.FillRequest, callback: autoFillManager.FillRequestCallback) {
          hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
          try {
            // 保存onFillRequest请求过来的页面数据和callback数据
            let obj: Record<string, UIExtensionContentSession | autoFillManager.FillRequestCallback | autoFillManager.ViewData> = {
              'session': session,
              'fillCallback': callback, // 自动填充处理结果通过此callback回调到客户端
              'viewData': request.viewData // 将需要回填的数据组装到viewData中，并通过callback带回到客户端
            };
            let storageFill: LocalStorage = new LocalStorage(obj);
            // 加载自动填充处理界面
            session.loadContent('autofillpages/AutoFillPassWord', storageFill);
          } catch (err) {
            hilog.error(0x0000, 'testTag', '%{public}s', 'autofill failed to load content');
          }
        }

        // 自动保存服务发起自动保存请求时会触发onSaveRequest的生命周期
        onSaveRequest(session: UIExtensionContentSession, request: autoFillManager.SaveRequest, callback: autoFillManager.SaveRequestCallback): void {
          hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onSaveRequest');
          try {
            let obj: Record<string, UIExtensionContentSession | autoFillManager.SaveRequestCallback | autoFillManager.ViewData> = {
              'session': session,
              'saveCallback': callback, // 自动保存处理结果通过此callback回调到客户端
              'viewData': request.viewData // 将需要回填的数据组装到viewData中，并通过callback带回到客户端
            }
            // 保存onSaveRequest请求过来的页面数据和callback数据
            let storageSave: LocalStorage = new LocalStorage(obj);
            // 加载自动保存处理界面
            session.loadContent('autofillpages/SavePage', storageSave);
          } catch (err) {
            hilog.error(0x0000, 'testTag', '%{public}s', 'autofill failed');
          }
        }
      }
      ```

4. 构建自动填充处理界面。

   1. 在ets目录右键选择“New &gt; Directory”，新建一个目录并命名为autofillpages。

   2. 在autofillpages目录中，右键选择“New &gt; File”，新建一个.ets文件并命名为AutoFillPassWord.ets。

   3. 当点击界面中账号或密码输入框时，自动填充框架会向自动填充服务发起自动填充请求，触发[onFillRequest](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#onfillrequest)的生命周期。在onFillRequest生命周期中拉起账号密码备选信息页面(AutoFillPassWord.ets)。

      ```ts
      import { autoFillManager } from '@kit.AbilityKit';

      // 将需要回填的数据组装到viewData中，并通过callback的onSuccess带回到客户端用于自动填充
      function successFunc(data: autoFillManager.ViewData, target: string, fillCallback?: autoFillManager.FillRequestCallback) {
        console.info(`data.pageNodeInfos.length`, data.pageNodeInfos.length);
        for (let i = 0; i < data.pageNodeInfos.length; i++) {
          console.info(`data.pageNodeInfos[i].isFocus`, data.pageNodeInfos[i].isFocus);
          if (data.pageNodeInfos[i].isFocus == true) {
            data.pageNodeInfos[i].value = target;
            break;
          }
        }
        if (fillCallback) {
          let response: autoFillManager.FillResponse = { viewData: data };
          fillCallback.onSuccess(response);
        }
      }

      function failFunc(fillCallback?: autoFillManager.FillRequestCallback) {
        if (fillCallback) {
          fillCallback.onFailure();
        }
      }

      function cancelFunc(fillContent?: string, fillCallback?: autoFillManager.FillRequestCallback) {
        if (fillCallback) {
          try {
            fillCallback.onCancel(fillContent);
          } catch (error) {
            console.error('fillContent undefined: ', JSON.stringify(error));
          }
        }
      }

      @Entry
      @Component
      struct AutoFillControl {
        storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
        fillCallback: autoFillManager.FillRequestCallback | undefined = this.storage?.get<autoFillManager.FillRequestCallback>('fillCallback');
        viewData: autoFillManager.ViewData | undefined = this.storage?.get<autoFillManager.ViewData>('viewData');

        build() {
          Column() {
            Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
              Text('选择已保存的账号密码')
                .fontWeight(500)
                .fontFamily('HarmonyHeiTi-Medium')
                .fontSize(20)
                .fontColor('#000000')
                .margin({ left: '4.4%' })
            }.margin({ top: '8.8%', left: '4.9%' }).height('7.2%')

            Row() {
              Column() {
                List({ space: 10, initialIndex: 0 }) {
                  ListItem() {
                    Text('15501212262')
                      .width('100%')
                      .height(40)
                      .fontSize(16)
                      .textAlign(TextAlign.Center)
                      .borderRadius(5)
                  }
                  .onClick(() => {
                    if (this.viewData != undefined) {
                      // 将选择的账号信息回填到客户端
                      successFunc(this.viewData, '15501212262', this.fillCallback);
                    }
                  })
                }
                // ...
                .listDirection(Axis.Vertical)
                .scrollBar(BarState.Off)
                .friction(0.6)
                .divider({ strokeWidth: 1, color: '#fff5eeee', startMargin: 20, endMargin: 20 })
                .edgeEffect(EdgeEffect.Spring)
                .onScrollIndex((firstIndex: number, lastIndex: number, centerIndex: number) => {
                  console.info('first' + firstIndex)
                  console.info('last' + lastIndex)
                  console.info('center' + centerIndex)
                })
                .onDidScroll((scrollOffset: number, scrollState: ScrollState) => {
                  console.info(`onDidScroll scrollState = ScrollState` + scrollState + `scrollOffset = ` + scrollOffset)
                })
              }
              .width('100%')
              .shadow(ShadowStyle.OUTER_FLOATING_SM)
              .margin({ top: 50 })
            }

            Row() {
              Button("Cancel")
                .onClick(() => {
                  // 放弃本次自动填充的场景触发cancelFunc()通知客户端取消自动填充
                  cancelFunc(undefined, this.fillCallback);
                })
                .margin({ top: 30, bottom: 10, left: 10, right: 10 })

              Button("Failure")
                .onClick(() => {
                  // 未获取到账号密码数据的情况下触发failFunc()通知客户端自动填充失败
                  failFunc(this.fillCallback);
                })
                .margin({ top: 30, bottom: 10, left: 10, right: 10 })
            }
            .backgroundColor('#f1f3f5').height('100%')
          }
        }
      }
      ```

5. 构建自动保存处理界面。

   1. 在autofillpages目录，右键选择“New &gt; File”，新建一个.ets文件并命名为SavePage.ets。

   2. 当TextInput中存在有信息时，页面切换(点击登录按钮)将触发[onSaveRequest](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#onsaverequest)的生命周期。在onSaveRequest中拉起保存信息处理界面(SavePage.ets)。

      ```ts
      import { autoFillManager } from '@kit.AbilityKit';
      import { hilog } from '@kit.PerformanceAnalysisKit';

      function SuccessFunc(success : boolean, saveRequestCallback?: autoFillManager.SaveRequestCallback) {
        if (saveRequestCallback) {
          if (success) {
            saveRequestCallback.onSuccess();
            return;
          }
          saveRequestCallback.onFailure();
        }
        hilog.error(0x0000, "testTag", "saveRequestCallback is nullptr!");
      }

      @Entry
      @Component
      struct SavePage {
        @State message: string = 'Save Account?'
        storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
        saveRequestCallback: autoFillManager.SaveRequestCallback | undefined = this.storage?.get<autoFillManager.SaveRequestCallback>('saveCallback');

        build() {
          Row() {
            Column() {
              Text(this.message)
                .fontSize(35)
                .fontWeight(FontWeight.Bold)
              Row() {
                // 用户保存表单数据成功，点击页面save按钮触发onSuccess()回调通知客户端保存表单数据成功
                Button("save")
                  .type(ButtonType.Capsule)
                  .fontSize(20)
                  .margin({ top: 30, right: 30 })
                  .onClick(() => {
                    SuccessFunc(true, this.saveRequestCallback);
                  })
                // 用户保存表单数据失败或放弃保存表单数据，点击页面back按钮触发onFailure()回调通知客户端保存表单数据失败
                Button("back")
                  .type(ButtonType.Capsule)
                  .fontSize(20)
                  .margin({ top: 30, left: 30 })
                  .onClick(() => {
                    SuccessFunc(false, this.saveRequestCallback);
                  })
              }
            }
            .width('100%')
          }
          .height('100%')
        }
      }
      ```

#### 实现情景化自动填充功能

情景化自动填充的具体类型可参考[自动填充类型的定义](../reference/apis-ability-kit/js-apis-inner-application-autoFillType-sys.md)。

开发者在实现情景化自动填充服务时，需要在DevEco Studio工程中手动新建一个SmartAutoFillExtensionAbility，具体步骤如下。

1. 设定AutoFillExtensionAbility应用的包名。

   在AppScope/[app.json5配置文件](../quick-start/app-configuration-file.md)中把bundleName设定为："com.ohos.textautofill"，例如：

   ```json
   "app": {
     "bundleName": "com.ohos.textautofill",
      // ...
   }
   ```

2. 配置extensionAbilities信息。

   在entry/src/main/[module.json5配置文件](../quick-start/module-configuration-file.md)中配置AutoFillAbility，例如：

   ```json
   "extensionAbilities": [
      {
         "name": "AutoFillAbility",
         "srcEntry": "./ets/autofillability/AutoFillAbility.ets",
         // ...
         "type": "autoFill/smart"
      }
   ]
   ```

3. 情景化自动填充与自动填充服务的实现基本一致。请参考[实现账号密码自动填充功能](#实现账号密码自动填充功能)。

### 开发AutoFillExtensionAbility使用方

开发者可以在主页面中通过点击自动填充组件启动[AutoFillExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md)。 如在主页面中添加如下内容：

#### 添加支持账号密码自动填充能力的组件

```ts
@Entry
@Component
struct Index {
  loginBtnColor: string = '#bfdbf9';

  build() {
    Column() {
      Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
        Text('Welcome!')
          .fontSize(24)
          .fontWeight(500)
          .fontFamily('HarmonyHeiTi-Medium')
          .fontColor('#182431')
      }.margin({ top: '32.3%' }).width('35%').height('4.1%')

      // 添加账号类型的输入框
      List() {
        ListItemGroup({ style: ListItemGroupStyle.CARD }) {
          ListItem({ style: ListItemStyle.CARD }) {
            TextInput({ placeholder: '请输入账号' })
              .type(InputType.USER_NAME)
              .fontFamily('HarmonyHeiTi')
              .fontColor('#182431')
              .fontWeight(400)
              .fontSize(16)
              .height('100%')
              .id('userName')
              .backgroundColor('#FFFFFF')
              .onChange((value: string) => {
                if (value) {
                  this.loginBtnColor = '#007DFF';
                } else {
                  this.loginBtnColor = '#bfdbf9';
                }
              })
              .enableAutoFill(true)
          }.padding(0)

          // 添加密码类型的输入框
          ListItem({ style: ListItemStyle.CARD }) {
            TextInput({ placeholder: '请输入密码' })
              .type(InputType.Password)
              .fontFamily('HarmonyHeiTi')
              .fontColor('#182431')
              .fontWeight(400)
              .fontSize(16)
              .height('100%')
              .backgroundColor('#FFFFFF')
              .id('passWord')
              .onChange((value: string) => {
                if (value) {
                  this.loginBtnColor = '#007DFF';
                } else {
                  this.loginBtnColor = '#bfdbf9';
                }
              })
              .enableAutoFill(true)
          }.padding(0)
        }
        .backgroundColor('#FFFFFF')
        .divider({ strokeWidth: 0.5, color: '#f1f3f5', startMargin: 15, endMargin: 15 })
      }
      .borderRadius(24)
      .width('93.3%')
      .height('16%')
      .margin({ top: '8.6%' })
    }
  }
}
```

#### 添加支持情景化自动填充能力的组件

```ts
@Entry
@Component
struct Index {
  @State inputTxt: string = '';

  build() {
    Column() {
      Column() {
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
          Text('情景化填充')
            .fontWeight(500)
            .fontFamily('HarmonyHeiTi-Medium')
          // ...
        }
        .margin({ top: '14.2%' }).height('7.2%')

        Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
          Column() {
            Row() {
              Text('设置类型')
                .fontColor('#99000000')
                .fontSize(14)
                .fontWeight(400)
                .textAlign(TextAlign.Start)
                .width('91%')
                .margin({ top: 5, left: -7.5 })
            }

            Row() {
              TextInput({ placeholder: 'Input content', text: this.inputTxt })
                .contentType(ContentType.FULL_PHONE_NUMBER)// 情景化自动填充类型
                .height('9.4%')
                .width('91%')
                .fontWeight(FontWeight.Bolder)
                .placeholderColor('#99000000')
                .backgroundColor('#ffffffff')
                .id('password1')
                .fontSize(16)
                .fontWeight(400)
                .borderStyle(BorderStyle.Solid)
                .enableAutoFill(true)
                .borderRadius(25)
                .margin({ top: '8vp' })
            }
          }.margin({ top: '7.1%' })
        }


        Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
          Column() {
            Row() {
              Text('设置类型为姓名')
                .fontColor('#99000000')
                .fontSize(14)
                .fontWeight(400)
                .textAlign(TextAlign.Start)
                .width('91%')
                .margin({ top: 5, left: -7.5 })
            }

            Row() {
              TextInput({ placeholder: 'Name', text: this.inputTxt })
                .contentType(ContentType.PERSON_FULL_NAME)// 情景化自动填充类型
                .height('9.4%')
                .width('91%')
                .fontWeight(FontWeight.Bold)
                .placeholderColor('#99000000')
                .backgroundColor('#ffffffff')
                .fontSize(16)
                .fontWeight(400)
                .id('password3')
                .borderStyle(BorderStyle.Solid)
                .enableAutoFill(true)
                .borderRadius(25)
                .onChange(() => {
                })
                .margin({ top: '8vp' })
            }
          }
        }
        .margin({ top: '20vp' })
      }.height('70%')
    }
    .backgroundColor('#ffffff').height('100%')
  }
}
```

