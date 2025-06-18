# AutoFillExtensionAbility

## Overview

The [AutoFillExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md) is an [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) component of the AUTO_FILL_PASSWORD or AUTO_FILL_SMART type that provides the auto-fill service.

The auto-fill service can be classified as follows:

- Auto-fill for accounts and passwords: Saved accounts and passwords are automatically populated, improving the efficiency of information input.
- Scenario-specific auto-fill: Information such as the mobile number and address is automatically populated based on the usage scenario.

## Available APIs

The table below describes the main APIs related to the auto-fill service. For details about other APIs, see [AutoFillRequest](../reference/apis-ability-kit/js-apis-inner-application-autoFillRequest-sys.md) and [AutoFillExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md).

| API                                                    | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onFillRequest(session: UIExtensionContentSession, request: FillRequest, callback: FillRequestCallback): void | Called when an auto-fill request is initiated or a password is generated.            |
| onSaveRequest(session: UIExtensionContentSession, request: SaveRequest, callback: SaveRequestCallback): void | Called when an automatic or manual save request is initiated.                |
| FillRequestCallback.onSuccess(response: FillResponse): void  | Implements the callback for an auto-fill request, which is used to automatically fill in or generate a password. The callback can be used to notify the client of the success of the request.|

## How to Develop

In this example, the party that provides the [AutoFillExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md) capability is called the provider, and the party that starts the AutoFillExtensionAbility is called the client.

### Developing the AutoFillExtensionAbility Provider

#### Lifecycle

The [AutoFillExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md) provides the lifecycle callbacks [onCreate](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#autofillextensionabilityoncreate), [onSessionDestroy](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#autofillextensionabilityonsessiondestroy), [onForeground](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#autofillextensionabilityonforeground), [onBackground](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#autofillextensionabilityonbackground), [onDestroy](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#autofillextensionabilityondestroy), [onSaveRequest](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#autofillextensionabilityonsaverequest), and [onFillRequest](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#autofillextensionabilityonfillrequest). Override them as required.

- **onCreate**: called to initialize the service logic when an AutoFillExtensionAbility is created.
- **onSessionDestroy**: called when a **UIExtensionContentSession** instance is destroyed for the AutoFillExtensionAbility.
- **onForeground**: called when the AutoFillExtensionAbility is switched from the background to the foreground.
- **onBackground**: called when the AutoFillExtensionAbility is switched from the foreground to the background.
- **onDestroy**: called to clear resources when the AutoFillExtensionAbility is destroyed.
- **onSaveRequest**: called to trigger auto-save when form data exists and the page is to be switched.
- **onFillRequest**: called to automatically fill in the account and password when a fill request is sent.

#### Implementing Auto-Fill for Accounts and Passwords

Before implementing auto-fill for accounts and passwords, manually create an AutoFillExtensionAbility in the DevEco Studio project.

1. Set the bundle name of the AutoFillExtensionAbility provider.

   In the [app.json5 file](../quick-start/app-configuration-file.md) in the **AppScope** directory, set **bundleName** to **com.ohos.passwordbox**. An example configuration is as follows:

   ```json
   "app": {
     "bundleName": "com.ohos.passwordbox",
      // ...
   }
   ```

2. Configuration information about this ExtensionAbility.

   Configure an AutoFillExtensionAbility in the [module.json5 file](../quick-start/module-configuration-file.md) in the **entry/src/main/** directory. An example configuration is as follows:

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
   
3. Implement auto-fill and auto-save.

   1. Right-click the **ets** directory, and choose **New > Directory** to create a directory named **autofillability**.

   2. Right-click the **autofillability** directory, and choose **New > File** to create a file named **AutoFillAbility.ets**. An example code snippet is as follows:

      ```ts
      import { hilog } from '@kit.PerformanceAnalysisKit';
      import { AutoFillExtensionAbility, autoFillManager, UIExtensionContentSession } from '@kit.AbilityKit';

      class AutoFillAbility extends AutoFillExtensionAbility {
        // ...
        // The onFillRequest lifecycle callback is triggered when the auto-fill service initiates an auto-fill request.
        onFillRequest(session: UIExtensionContentSession, request: autoFillManager.FillRequest, callback: autoFillManager.FillRequestCallback) {
          hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
          try {
            // Save the page data and callback data carried in onFillRequest.
            let obj: Record<string, UIExtensionContentSession | autoFillManager.FillRequestCallback | autoFillManager.ViewData> = {
              'session': session,
              'fillCallback': callback, // The auto-fill processing result is returned to the client through this callback.
              'viewData': request.viewData, // Assemble the data to be populated to viewData and return the data to the client through the callback.
            };
            let storageFill: LocalStorage = new LocalStorage(obj);
            // Load the auto-fill processing page.
            session.loadContent('autofillpages/AutoFillPassWord', storageFill);
          } catch (err) {
            hilog.error(0x0000, 'testTag', '%{public}s', 'autofill failed to load content');
          }
        }

        // The onSaveRequest lifecycle callback is triggered when the auto-save service initiates an auto-save request.
        onSaveRequest(session: UIExtensionContentSession, request: autoFillManager.SaveRequest, callback: autoFillManager.SaveRequestCallback): void {
          hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onSaveRequest');
          try {
            let obj: Record<string, UIExtensionContentSession | autoFillManager.SaveRequestCallback | autoFillManager.ViewData> = {
              'session': session,
              'saveCallback': callback, // The auto-save processing result is returned to the client through this callback.
              'viewData': request.viewData, // Assemble the data to be populated to viewData and return the data to the client through the callback.
            }
            // Save the page data and callback data carried in onSaveRequest.
            let storageSave: LocalStorage = new LocalStorage(obj);
            // Load the auto-save processing page.
            session.loadContent('autofillpages/SavePage', storageSave);
          } catch (err) {
            hilog.error(0x0000, 'testTag', '%{public}s', 'autofill failed');
          }
        }
      }
      ```

4. Build the auto-fill processing page.

   1. Right-click the **ets** directory, and choose **New > Directory** to create a directory named **autofillpages**.

   2. Right-click the **autofillpages** directory, and choose **New > File** to create a file named **AutoFillPassWord.ets**.

   3. When users touch the account or password text box on the page, the auto-fill framework sends an auto-fill request to the auto-fill service to trigger the [onFillRequest](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#autofillextensionabilityonfillrequest) lifecycle callback. In the **onFillRequest** lifecycle callback, display the page that shows the available accounts and passwords (implemented by **AutoFillPassWord.ets**).

      ```ts
      import { autoFillManager } from '@kit.AbilityKit';

      // Assemble the data to be populated to viewData and use the onSuccess callback to return the data to the client for auto-fill.
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
              Text('Select a saved account and password')
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
                      // Populate the selected account and password in the client.
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
                  // Call cancelFunc() to notify the client when auto-fill is canceled.
                  cancelFunc(undefined, this.fillCallback);
                })
                .margin({ top: 30, bottom: 10, left: 10, right: 10 })

              Button("Failure")
                .onClick(() => {
                  // Call failFunc() to notify the client that auto-fill fails when the account and password are not obtained.
                  failFunc(this.fillCallback);
                })
                .margin({ top: 30, bottom: 10, left: 10, right: 10 })
            }
            .backgroundColor('#f1f3f5').height('100%')
          }
        }
      }
      ```

5. Build the auto-save processing page.

   1. Right-click the **autofillpages** directory, and choose **New > File** to create a file named **SavePage.ets**.

   2. When information exists in the **TextInput** component, trigger the [onSaveRequest](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md#autofillextensionabilityonsaverequest) lifecycle callback during page redirection (a user touches the login button). In the **onSaveRequest** callback, display the information save processing page (implemented by **SavePage.ets**).

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
                // Call onSuccess() (upon the touch of the save button) to notify the client that the form data is saved successfully.
                Button("save")
                  .type(ButtonType.Capsule)
                  .fontSize(20)
                  .margin({ top: 30, right: 30 })
                  .onClick(() => {
                    SuccessFunc(true, this.saveRequestCallback);
                  })
                // Call onFailure() (upon the touch of the back button) to notify the client that the user cancels saving the form data or saving the form data fails.
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

#### Implementing Scenario-specific Auto-Fill

For details about the types of scenario-specific auto-fill, see [AutoFillType](../reference/apis-ability-kit/js-apis-inner-application-autoFillType-sys.md).

Before implementing scenario-specific auto-fill, you need to create a **SmartAutoFillExtensionAbility** object in the DevEco Studio project.

1. Set the bundle name of the AutoFillExtensionAbility provider.

   In the [app.json5 file](../quick-start/app-configuration-file.md) in the **AppScope** directory, set **bundleName** to **com.ohos.textautofill**. An example configuration is as follows:

   ```json
   "app": {
     "bundleName": "com.ohos.textautofill",
      // ...
   }
   ```

2. Configuration information about this ExtensionAbility.

   Configure an AutoFillExtensionAbility in the [module.json5 file](../quick-start/module-configuration-file.md) in the **entry/src/main/** directory. An example configuration is as follows:

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

3. The implementation of the scenario-specific auto-fill service is basically the same as that of auto-fill for accounts and passwords. For details, see [Implementing Auto-Fill for Accounts and Passwords](#implementing-auto-fill-for-accounts-and-passwords).

### Developing the AutoFillExtensionAbility Client

You can click the auto-fill component on the home page to start the [AutoFillExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-autoFillExtensionAbility-sys.md). For example, you can add the following component to the main page:

#### Component That Supports Auto-Fill of Accounts and Passwords

```ts
@Entry
@Component
struct Index {
  loginBtnColor: String = '#bfdbf9';

  build() {
    Column() {
      Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
        Text('Welcome!')
          .fontSize(24)
          .fontWeight(500)
          .fontFamily('HarmonyHeiTi-Medium')
          .fontColor('#182431')
      }.margin({ top: '32.3%' }).width('35%').height('4.1%')

      // Add a text box of the account type.
      List() {
        ListItemGroup({ style: ListItemGroupStyle.CARD }) {
          ListItem({ style: ListItemStyle.CARD }) {
            TextInput({placeholder: 'Enter an account.'})
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

          // Add a text box of the password type.
          ListItem({ style: ListItemStyle.CARD }) {
            TextInput({placeholder: 'Enter the password.'})
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

#### Component That Supports Scenario-Specific Auto-Fill

```ts
@Entry
@Component
struct Index {
  @State inputTxt: string = '';

  build() {
    Column() {
      Column() {
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {
          Text ('Scenario-specific population')
            .fontWeight(500)
            .fontFamily('HarmonyHeiTi-Medium')
          // ...
        }
        .margin({ top: '14.2%' }).height('7.2%')

        Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
          Column() {
            Row() {
              Text('Set the type.')
                .fontColor('#99000000')
                .fontSize(14)
                .fontWeight(400)
                .textAlign(TextAlign.Start)
                .width('91%')
                .margin({ top: 5, left: -7.5 })
            }

            Row() {
              TextInput({ placeholder: 'Input content', text: this.inputTxt })
                .contentType(ContentType.FULL_PHONE_NUMBER) // Scenario-specific automatic population
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
              Text('Set the type to name')
                .fontColor('#99000000')
                .fontSize(14)
                .fontWeight(400)
                .textAlign(TextAlign.Start)
                .width('91%')
                .margin({ top: 5, left: -7.5 })
            }

            Row() {
              TextInput({ placeholder: 'Name', text: this.inputTxt })
                .contentType(ContentType.PERSON_FULL_NAME) // Scenario-specific automatic population
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
