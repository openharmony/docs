# Switching from Explicit Want Redirection to Linking Redirection

Since API version 12, it is not recommended that third-party applications start other applications by specifying an ability (implicit Want mode). Instead, the [linking mode](app-startup-overview.md#application-links) is recommended.

This section describes how to switch from explicit Want mode to linking mode.

## Starting the UIAbility of Another Application

1. Install the application on your device. In the [module.json5 file](../quick-start/module-configuration-file.md) of the UIAbility, configure **entities**, **actions**, and **uri** under **skills**.
    - The **actions** field must contain **ohos.want.action.viewData**.
    - The **entities** field must contain **entity.system.browsable**.
    - The **uris** field must contain an element whose **scheme** is **https**. **domainVerify** must be set to **true**. For details about the URI matching rules, see [Matching Rules of uri](explicit-implicit-want-mappings.md#matching-rules-of-uri). If **domainVerify** is set to **true**, domain name verification is enabled. In this case, the target application must pass domain name verification during App Linking. For details about how to configure the App Linking domain name, see App Linking.

    ```json
    {
      "module": {
        // ...
        "abilities": [
          {
            // ...
            "skills": [
              {
                "entities": [
                  "entity.system.browsable"
                ],
                "actions": [
                  "ohos.want.action.viewData"
                ],
                "uris": [
                  {
                    "scheme": "https",
                    "host": "www.example.com"
                  }
                ],
              "domainVerify": true
              }
            ]
          }
        ]
      }
    }
    ```

2. Call [openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12) to trigger redirection. The redirected-to link and [options](../reference/apis-ability-kit/js-apis-app-ability-openLinkOptions.md) must be passed in, but the bundle name, module name, and ability name are not required. The system matches the application that meets the skills configuration based on the link.
    - If **appLinkingOnly** in **options** is set to **true**, the target application must pass domain name verification (Internet connection required). A unique matching item or an unmatched result will be returned.
    - If **appLinkingOnly** in **options** is set to **false**, the system preferentially attempts to start the target application in App Linking mode. If no matching application is found, the system starts the application in Deep Linking mode.

    ```ts
    import { common, OpenLinkOptions } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[UIAbilityComponentsOpenLink]';
    const DOMAIN_NUMBER: number = 0xFF00;

    @Entry
    @Component
    struct Index {
      build() {
        Button('start link', { type: ButtonType.Capsule, stateEffect: true })
          .width('87%')
          .height('5%')
          .margin({ bottom: '12vp' })
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            // When using startAbility to explicitly start other UIAbilities, the openLink API is recommended.
            // let want: Want = {
            //   bundleName: "com.test.example",
            //   moduleName: "entry",
            //   abilityName: "EntryAbility"
            // };
            // try {
            //   context.startAbility(want)
            //     .then(() => {
            //       hilog.info(DOMAIN_NUMBER, TAG, 'startAbility success.');
            //     }).catch((err: BusinessError) => {
            //       hilog.error(DOMAIN_NUMBER, TAG, `startAbility failed. Code is ${err.code}, message is ${err.message}`);
            //     })
            // } catch (paramError) {
            //   hilog.error(DOMAIN_NUMBER, TAG, `Failed to startAbility. Code is ${paramError.code}, message is ${paramError.message}`);
            // }
            let link: string = "https://www.example.com";
            let openLinkOptions: OpenLinkOptions = {
              // Specify whether the matched abilities options must pass App Linking domain name verification.
              appLinkingOnly: true,
              // Same as parameter in want, which is used to transfer parameters.
              parameters: {demo_key: "demo_value"}
            };

            try {
              context.openLink(link, openLinkOptions)
                .then(() => {
                  hilog.info(DOMAIN_NUMBER, TAG, 'open link success.');
                }).catch((err: BusinessError) => {
                  hilog.error(DOMAIN_NUMBER, TAG, `open link failed. Code is ${err.code}, message is ${err.message}`);
                })
            } catch (paramError) {
              hilog.error(DOMAIN_NUMBER, TAG, `Failed to start link. Code is ${paramError.code}, message is ${paramError.message}`);
            }
          })
      }
    }
    ```

## Starting the UIAbility of Another Application and Obtaining the Return Result

1. Install the application on your device. In the [module.json5 file](../quick-start/module-configuration-file.md) of the UIAbility, configure **entities**, **actions**, and **uri** under **skills**.

    - The **actions** field must contain **ohos.want.action.viewData**.
    - The **entities** field must contain **entity.system.browsable**.
    - The **uris** field must contain an element whose **scheme** is **https**. **domainVerify** must be set to **true**. For details about the URI matching rules, see [Matching Rules of uri](explicit-implicit-want-mappings.md#matching-rules-of-uri). If **domainVerify** is set to **true**, domain name verification is enabled. In this case, the target application must pass domain name verification during App Linking. For details about how to configure the App Linking domain name, see App Linking.

    ```json
    {
      "module": {
        // ...
        "abilities": [
          {
            // ...
            "skills": [
              {
                "entities": [
                  "entity.system.browsable"
                ],
                "actions": [
                  "ohos.want.action.viewData"
                ],
                "uris": [
                  {
                    "scheme": "https",
                    "host": "www.example.com"
                  }
                ],
              "domainVerify": true
              }
            ]
          }
        ]
      }
    }
    ```

2. Call [openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12) to trigger redirection. The redirected-to link and [options](../reference/apis-ability-kit/js-apis-app-ability-openLinkOptions.md) must be passed in, but the bundle name, module name, and ability name are not required. The system matches the application that meets the skills configuration based on the link. **AbilityResult** is transferred to the callback function through input parameters and returned to the caller application when the ability is terminated. The startup success or failure result is returned through a promise.<br>
    - If **appLinkingOnly** in **options** is set to **true**, the target application must pass domain name verification (Internet connection required). A unique matching item or an unmatched result will be returned.
    - If **appLinkingOnly** in **options** is set to **false**, the system preferentially attempts to start the target application in App Linking mode. If no matching application is found, the system starts the application in Deep Linking mode.

    ```ts
    import { common, OpenLinkOptions } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[UIAbilityComponentsOpenLink]';
    const DOMAIN_NUMBER: number = 0xFF00;

    @Entry
    @Component
    struct Index {
      build() {
        Button('start link', { type: ButtonType.Capsule, stateEffect: true })
          .width('87%')
          .height('5%')
          .margin({ bottom: '12vp' })
          .onClick(() => {
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            // When using startAbility to explicitly start other UIAbilities, the openLink API is recommended.
            // let want: Want = {
            //   bundleName: "com.test.example",
            //   moduleName: "entry",
            //   abilityName: "EntryAbility"
            // };
            // try {
            //   context.startAbilityForResult(want)
            //     .then((data) => {
            //       hilog.info(DOMAIN_NUMBER, TAG, 'startAbility success. data:' + JSON.stringify(data));
            //     }).catch((err: BusinessError) => {
            //       hilog.error(DOMAIN_NUMBER, TAG, `startAbility failed. Code is ${err.code}, message is ${err.message}`);
            //     })
            // } catch (paramError) {
            //   hilog.error(DOMAIN_NUMBER, TAG, `Failed to startAbility. Code is ${paramError.code}, message is ${paramError.message}`);
            // }
            let link: string = "https://www.example.com";
            let openLinkOptions: OpenLinkOptions = {
              // Specify whether the matched abilities options must pass App Linking domain name verification.
              appLinkingOnly: true,
              // Same as parameter in want, which is used to transfer parameters.
              parameters: {demo_key: "demo_value"}
            };

            try {
              context.openLink(link, openLinkOptions, (err, data) => {
                // AbilityResult callback, which is triggered only when the started ability is terminated.
                hilog.info(DOMAIN_NUMBER, TAG, 'open link success. Callback result:' + JSON.stringify(data));
              }).then(() => {
                hilog.info(DOMAIN_NUMBER, TAG, 'open link success.');
              }).catch((err: BusinessError) => {
                hilog.error(DOMAIN_NUMBER, TAG, `open link failed. Code is ${err.code}, message is ${err.message}`);
              })
            } catch (paramError) {
              hilog.error(DOMAIN_NUMBER, TAG, `Failed to start link. Code is ${paramError.code}, message is ${paramError.message}`);
            }
          })
      }
    }
    ```
