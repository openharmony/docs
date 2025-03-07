# API Switching Overview


Due to the differences in the thread model and process model, certain APIs can be used only in the FA model. They are marked with **FAModelOnly** in the SDK. When switching an application from the FA model to the stage model, replace the APIs marked with **FAModelOnly** in the application with the APIs supported in the stage model. This topic uses the switching of **startAbility()** as an example.

![api-switch-overview](figures/api-switch-overview.png)

 

- Sample code of **startAbility()** in the FA model:

  ```ts
  import featureAbility from '@ohos.ability.featureAbility';
  import Want from '@ohos.app.ability.Want';
  import hilog from '@ohos.hilog';
  
  const TAG: string = 'PagePageAbilityFirst';
  const domain: number = 0xFF00;
  
  @Entry
  @Component
  struct PagePageAbilityFirst {
    
    build() {
      Column() {
        List({ initialIndex: 0 }) {
          ListItem() {
            Flex({ justifyContent: FlexAlign.SpaceBetween, alignContent: FlexAlign.Center }) {
              //...
            }
            .onClick(() => {
              (async (): Promise<void> => {
                try {
                  hilog.info(domain, TAG, 'Begin to start ability');
                  let want: Want = {
                    bundleName: 'com.samples.famodelabilitydevelop',
                    moduleName: 'entry',
                    abilityName: 'com.samples.famodelabilitydevelop.PageAbilitySingleton'
                  };
                  await featureAbility.startAbility({ want: want });
                  hilog.info(domain, TAG, `Start ability succeed`);
                }
                catch (error) {
                  hilog.error(domain, TAG, 'Start ability failed with ' + error);
                }
              })()
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

- Sample code of **startAbility()** in the stage model:

  ```ts
  import hilog from '@ohos.hilog';
  import Want from '@ohos.app.ability.Want';
  import common from '@ohos.app.ability.common';
  import { BusinessError } from '@ohos.base';
  import { Caller } from '@ohos.app.ability.UIAbility';

  const TAG: string = '[Page_UIAbilityComponentsInteractive]';
  const DOMAIN_NUMBER: number = 0xFF00;
  
  @Entry
  @Component
  struct Page_UIAbilityComponentsInteractive {
    private context = getContext(this) as common.UIAbilityContext;
    caller: Caller | undefined = undefined;
    build() {
      Column() {
        //...
        List({ initialIndex: 0 }) {
          ListItem() {
            Row() {
              //...
            }
            .onClick(() => {
              // Context is a member of the ability object and is required for invoking inside a non-ability object.
              // Pass in the Context object.
              let wantInfo: Want = {
                deviceId: '', // An empty deviceId indicates the local device.
                bundleName: 'com.samples.stagemodelabilitydevelop',
                moduleName: 'entry', // moduleName is optional.
                abilityName: 'FuncAbilityA',
                parameters: { // Custom information.
                  info: 'From the UIAbilityComponentsInteractive page of EntryAbility',
                },
              };
              // context is the UIAbilityContext of the initiator UIAbility.
              this.context.startAbility(wantInfo).then(() => {
                hilog.info(DOMAIN_NUMBER, TAG, 'startAbility success.');
              }).catch((error: BusinessError) => {
                hilog.error(DOMAIN_NUMBER, TAG, 'startAbility failed.');
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
