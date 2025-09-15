# Stage模型启动FA模型PageAbility

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wkljy-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

本小节介绍[Stage模型](ability-terminology.md#stage模型)的两种应用组件如何启动[FA模型](ability-terminology.md#fa模型)的PageAbility组件。


## UIAbility启动PageAbility

  UIAbility启动PageAbility和UIAbility启动UIAbility的方式完全相同。

> **说明：**
> 需注意FA模型中abilityName由bundleName + AbilityName组成，具体见示例。

```ts
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Page_StartFAModel]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Page_StartFAModel {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      //...
      List({ initialIndex: 0 }) {
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.MainAbility'
            };
            this.context.startAbility(want).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Start Ability successfully.');
            }).catch((error: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Ability failed: ` + JSON.stringify(error));
            });
          })
        }
        //...
      }
      //...
    }
    //...
  }
}
```


## UIAbility访问PageAbility（startAbilityForResult）

startAbilityForResult和startAbility的区别是当PageAbility销毁的时候会返回执行结果。

UIAbility通过startAbilityForResult启动PageAbility与UIAbility的代码一样，没有任何区别。


```ts
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = '[Page_StartFAModel]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Page_StartFAModel {
  private context = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      //...
      List({ initialIndex: 0 }) {
        ListItem() {
          Row() {
            //...
          }
          .onClick(() => {
            let want: Want = {
              bundleName: 'com.samples.famodelabilitydevelop',
              abilityName: 'com.samples.famodelabilitydevelop.MainAbility',
            };
            this.context.startAbilityForResult(want).then((result) => {
              hilog.info(DOMAIN_NUMBER, TAG, 'Ability verify result: ' + JSON.stringify(result));
              if (result !== null) {
                this.getUIContext().getPromptAction().showToast({
                  message: JSON.stringify(result)
                });
              }
            }).catch((error: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `Ability failed: ` + JSON.stringify(error));
            });
          })
        }
        //...
      }
      //...
    }
    //...
  }
}
```


## ExtensionAbility启动PageAbility

下面以ServiceExtensionAbility为例来说明ExtensionAbility启动PageAbility。ServiceExtensionAbility启动PageAbility和ServiceExtensionAbility启动UIAbility的方式完全相同。


```ts
import { Want, ServiceExtensionAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';
import ServiceExtImpl from '../IdlServiceExt/idl_service_ext_impl';

const TAG: string = '[ServiceExtAbility]';
const DOMAIN_NUMBER: number = 0xFF00;

export default class ServiceExtAbility extends ServiceExtensionAbility {
  serviceExtImpl: ServiceExtImpl = new ServiceExtImpl('ExtImpl');

  onCreate(want: Want): void {
    let serviceExtensionContext = this.context;
    hilog.info(DOMAIN_NUMBER, TAG, `onCreate, want: ${want.abilityName}`);
  };

  onRequest(want: Want, startId: number): void {
    hilog.info(DOMAIN_NUMBER, TAG, `onRequest, want: ${want.abilityName}`);
    if (want.parameters?.key === 'ConnectFaPageAbility') {
      let wantFA: Want = {
        bundleName: 'com.samples.famodelabilitydevelop',
        abilityName: 'com.samples.famodelabilitydevelop.MainAbility',
      };
      this.context.startAbility(wantFA).then(() => {
        hilog.info(DOMAIN_NUMBER, TAG, 'Start Ability successfully.');
      }).catch((error: BusinessError) => {
        hilog.error(DOMAIN_NUMBER, TAG, `Ability failed: ${JSON.stringify(error)}`);
      });
    }
  };

  onConnect(want: Want): rpc.RemoteObject {
    hilog.info(DOMAIN_NUMBER, TAG, `onConnect, want: ${want.abilityName}`);
    // 返回ServiceExtImpl对象，客户端获取后便可以与ServiceExtensionAbility进行通信
    return this.serviceExtImpl as rpc.RemoteObject;
  };

  onDisconnect(want: Want): void {
    hilog.info(DOMAIN_NUMBER, TAG, `onDisconnect, want: ${want.abilityName}`);
  };

  onDestroy(): void {
    hilog.info(DOMAIN_NUMBER, TAG, 'onDestroy');
  };
}
```
