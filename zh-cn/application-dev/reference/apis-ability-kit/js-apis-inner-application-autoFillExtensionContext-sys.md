# AutoFillExtensionContext (系统接口) 

AutoFillExtensionContext模块是AutoFillExtensionAbility的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。  
> 本模块接口为系统接口。

## 使用说明

在使用AutoFillExtensionContext的功能前，需要通过AutoFillExtensionAbility子类实例获取。

```ts
import { AutoFillExtensionAbility } from '@kit.AbilityKit';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
  onCreate() {
    let AutoFillExtensionContext = this.context;
  }
}
```

## AutoFillExtensionContext

### reloadInModal<sup>13+</sup>

reloadInModal(customData: CustomData): Promise\<void>

拉起模态页面。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                         |
| ---------- | --------------------------------------------------------- | ---- | ---------------------------- |
| customData | [CustomData](js-apis-inner-application-customData-sys.md) | 是   | 拉起模态页面时的自定义信息。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Not System App. Interface caller is not a system app.        |
| 401      | If the input parameter is not valid parameter.               |
| 16000011 | The context does not exist.                                  |
| 16000050 | Internal error.                                              |

**示例：**

通过点击账号密码输入框触发自动填充服务时，在[AutoFillExtensionAbility](js-apis-app-ability-autoFillExtensionAbility-sys.md)的onFillRequest生命周期中拉起账号选择界面。

当点击账号选择界面选择任意账号时，调用reloadInModal接口再次触发自动填充服务时，在AutoFillExtensionAbility的onFillRequest生命周期中拉起模态页面。

```ts
// AutoFillAbility.ts
import { AutoFillExtensionAbility, autoFillManager, UIExtensionContentSession } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class AutoFillAbility extends AutoFillExtensionAbility {
  // ...
  onFillRequest(session: UIExtensionContentSession,
    request: autoFillManager.FillRequest,
    callback: autoFillManager.FillRequestCallback) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'autofill onFillRequest');
    try {
      let storage_fill: LocalStorage = new LocalStorage(
        {
          'session': session,
          'message': "AutoFill Page",
          'fillCallback': callback,
          'viewData': request.viewData,
          'autoFillExtensionContext': this.context,
          'customData': request.customData
        } as Record<string, Object>);
      if (request.customData == undefined) {
        // 加载自动填充处理界面
        session.loadContent('pages/AccountPage', storage_fill);
      } else {
        // 拉起模态页面
        session.loadContent('pages/ReloadInModal', storage_fill);
      }
    } catch (err) {
      hilog.error(0x0000, 'testTag', '%{public}s', 'autofill failed to load content');
    }
  }
}
```

当点击账号选择界面选择任意账号时，调用reloadInModal接口。

```ts
// AccountPage.ets
import { autoFillManager, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct AccountPage {
  storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  viewData: autoFillManager.ViewData | undefined = this.storage?.get<autoFillManager.ViewData>('viewData');
  context: common.AutoFillExtensionContext | undefined = this.storage?.get<common.AutoFillExtensionContext>('autoFillExtensionContext');


  build() {
    Row() {
      Column() {
        List({ space: 10, initialIndex: 0 }) {
          ListItem() {
            Text('HelloWorld789456')
              .width('100%')
              .height(40)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(5)
          }
          .onClick(() => {
            if (this.viewData != undefined) {
              if (this.context != undefined) {
                this.context.reloadInModal({ data: { viewData: 20, text: 'HelloWorld789456' } }).then(() => {
                  console.info('reloadInModal successfully.')
                }).catch((err: BusinessError) => {
                  console.error('reloadInModal failed.')
                })
              }
            }
          })
        }
        // ...
      }
      .width('100%')
      .shadow(ShadowStyle.OUTER_FLOATING_SM)
    }
    .height('100%')
    .shadow(ShadowStyle.OUTER_FLOATING_SM)
  }
}
```
