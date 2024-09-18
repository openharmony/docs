# Using Deep Linking for Application Redirection

In Deep Linking, the system, based on the passed-in URI and [URI matching rules](explicit-implicit-want-mappings.md#matching-rules-of-uri), searches for the application that meets the URL skills configuration from the locally installed applications and starts that application. If multiple applications are matched, a dialog box is displayed for users to select one of them.

## Working Principles

Deep Linking searches for an application based on the URI matching rules in implicit Want mechanism and starts the matching application. For details about the URI matching rules of implicit Want, see [Matching Rules of uri](explicit-implicit-want-mappings.md#matching-rules-of-uri).


## Declaring the URL Skills in the Configuration File (Required for the Target Application)

To be accessed by other applications, an application must declare the URL skills in the [module.json5 file](../quick-start/module-configuration-file.md). The value of **scheme** under **uri** can be customized. It can be any string that does not contain special characters or start with **ohos**.

A configuration example is as follows:

```json
{
  "module": {
    // ...
    "abilities": [
      {
        // ...
        "skills": [
          {
            "uris": [
              {
                // scheme is mandatory and can be customized. The following uses link as an example. Replace it with the actual scheme.
                "scheme": "link",
                // host is mandatory. Configure the domain name to be matched.
                "host": "www.example.com",
                // path is optional. To distinguish between applications that are associated with the same domain name, you are advised to configure this field.
                "path": "path1"
              }
            ]
          }
        ]
      }
    ]
  }
}
```


## Implementing Application Redirection (Required for the Caller Application)

The following uses two cases to describe how to use [openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12) and [startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability) to implement application redirection.

### Using openLink() to Open a Browser Page

Pass in the URL of the target application into **link** of [openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12), and set **appLinkingOnly** in the **options** field to **false**.


The sample code is as follows:

```ts
import { common } from '@kit.AbilityKit';
import OpenLinkOptions from '@ohos.app.ability.OpenLinkOptions';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

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
        let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext;
        let link: string = "link://www.example.com";
        let openLinkOptions: OpenLinkOptions = {
          appLinkingOnly: false
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

### Using startAbility() to Implement Application Redirection

Pass in the target application's link into **want** of [startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability), which then uses [implicit Want](explicit-implicit-want-mappings.md#matching-rules-of-implicit-want) to trigger application redirection. In addition, you must pass in the **action** and **entity** fields to be matched.


The sample code is as follows:

```ts
import { common, Want } from '@kit.AbilityKit';
import OpenLinkOptions from '@ohos.app.ability.OpenLinkOptions';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

const TAG: string = '[UIAbilityComponentsOpenLink]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Index {
  build() {
    Button('start ability', { type: ButtonType.Capsule, stateEffect: true })
      .width('87%')
      .height('5%')
      .margin({ bottom: '12vp' })
      .onClick(() => {
        let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext;
        let want: Want = {
            uri: "link://www.example.com"
        };

        try {
          context.startAbility(want).then(() => {
            hilog.info(DOMAIN_NUMBER, TAG, 'start ability success.');
          }).catch((err: BusinessError) => {
            hilog.error(DOMAIN_NUMBER, TAG, `start ability failed. Code is ${err.code}, message is ${err.message}`);
          })
        } catch (paramError) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${paramError.code}, message is ${paramError.message}`);
        }
      })
  }
}
```
