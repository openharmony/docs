# 通过startAbilityByType拉起垂类应用
## 使用场景
开发者可通过特定的业务类型如导航、金融、邮件等，调用startAbilityByType接口拉起对应的垂域面板，该面板将展示目标方接入的垂域应用，由用户选择打开指定应用以实现相应的垂类意图。垂域面板为调用方提供统一的安全、可信的目标方应用，同时降低调用方的接入成本。  
![](./figures/process-start-intent-panel.png)

## 接口说明



接口**startAbilityByType<sup>11+</sup>** 是[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybytype11)和[UIExtensionContentSession](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#uiextensioncontentsessionstartabilitybytype11)提供的支持基于垂域业务类型拉起垂域面板，调用方通过指定特定的垂域业务类型即可拉起对应的垂域面板，在垂域面板上将展示目标方接入的垂域应用。

### 导航类应用扩展面板参数说明

startAbilityByType接口中type字段为navigation，对应的wantParam参数：

| 属性名称             | 含义                                                         | 数据类型 | 是否必填 |
| -------------------- | ------------------------------------------------------------ | -------- | -------- |
| destinationLatitude  | 终点纬度                                                    | number   | sceneType=1或2时必填 |
| destinationLongitude | 终点经度                                                     | number   | sceneType=1或2时必填 |
| sceneType            | 意图取值 ：1：路线规划 2：导航 3： 地点搜索                                | number   | 否，缺省时默认为1   |
| destinationName      | 终点名称                                                     | string   | sceneType=3时必填   |
| originName           | 起点名称（路线规划场景有效）                                   | string   | 否   |
| originLatitude       | 起点纬度（路线规划场景有效）                                   | number   | 否   |
| originLongitude      | 起点经度（路线规划场景有效）                                   | number   | 否   |
| vehicleType          | 交通出行工具：0：驾车 1：步行 2：骑行 3：公交（路线规划场景有效） | number   | 否，缺省时由应用自行处理   |

> **说明：**
> 
> 本文中的经纬度均采用GCJ-02坐标系统。



### 邮件类应用扩展面板参数说明

startAbilityByType接口中type字段为mail，对应的wantParam参数：

| 属性名称                              | 含义                                   | 数据类型 | 是否必填                   |
| ------------------------------------- | -------------------------------------- | -------- | -------------------------- |
| email                                 | 收件人邮箱地址（支持多个且以逗号分隔） | string[ ] | 否                         |
| cc                                    | 抄收人邮箱地址（支持多个且以逗号分隔） | string[ ] | 否                         |
| bcc                                   | 密送人邮箱地址（支持多个且以逗号分隔） | string[ ] | 否                         |
| subject                               | 邮件主题                               | string   | 否                         |
| body                                  | 邮件内容                               | string   | 否                         |
| ability.params.stream                 | 邮件附件（附件的uri地址列表）          | string[ ] | 否                         |
| ability.want.params.uriPermissionFlag | 给邮件附件赋予至少读权限               | number   | 否，邮件附件存在情况下必填 |
| sceneType                             | 意图取值 ：1：发邮件                   | number   | 是                         |

> **说明：**
>
> 邮件类应用扩展面板中的string或string[ ]类型的内容都需要经过url编码，接收方收到这些参数后需要进行url解码。



## 拉起导航类应用扩展面板

### 调用方开发步骤

1. 导入ohos.app.ability.common模块。 
    ```ts
    import { common } from '@kit.AbilityKit';
    ```
2. 构造接口参数并调用startAbilityByType接口。

    ```ts
    let context = getContext(this) as common.UIAbilityContext;
    let wantParam: Record<string, Object> = {
      'sceneType': 1,
      'destinationLatitude': 32.060844,
      'destinationLongitude': 118.78315,
      'destinationName': 'xx市xx路xx号',
      'originName': 'xx市xx公园',
      'originLatitude': 31.060844,
      'originLongitude': 120.78315,
      'vehicleType': 0
    };
    let abilityStartCallback: common.AbilityStartCallback = {
      onError: (code: number, name: string, message: string) => {
        console.log(`code:` + code + `name:` + name + `message:` + message);
      }
    }
    
    context.startAbilityByType("navigation", wantParam, abilityStartCallback, (err) => {
    if (err) {
        console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
      } else {
        console.log(`success`);
      }
    });
    ```
    效果示例图：
    
    ![示例效果图](./figures/start-navigation-panel.png)

### 目标方开发步骤

1. 在module.json5中新增[linkFeature](../quick-start/module-configuration-file.md#skills标签)属性并设置声明当前应用支持的特性功能，从而系统可以从设备已安装应用中找到当前支持该特性的应用。

    ~~~json
    {
    "abilities": [
        {
        "skills": [
            {
            "uris": [
                {
                "scheme": "maps", // 这里仅示意，应用需确保这里声明的的uri能被外部正常拉起
                "host": "navigation",
                "path": "",
                "linkFeature": "Navigation" // 声明应用支持导航功能
                },
                {
                "scheme": "maps", // 这里仅示意，应用需确保这里声明的的uri能被外部正常拉起
                "host": "routePlan",
                "path": "",
                "linkFeature": "RoutePlan" // 声明应用支持路线规划功能
                },
                {
                "scheme": "maps", // 这里仅示意，应用需确保这里声明的的uri能被外部正常拉起
                "host": "search",
                "path": "",
                "linkFeature": "PlaceSearch" // 声明应用支持位置搜索功能
                }
            ]
            }
        ]
        }
    ]
    }
    ~~~

2. 解析参数并做对应处理。

    ```ts
    UIAbility::onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void
    ```

    在参数**want.parameters**中会携带Caller方传入的参数（与调用方传入的有些差异），如下表所示：

    | 属性名称             | 含义                                                         | 数据类型 | 是否必填 |
    | -------------------- | ------------------------------------------------------------ | -------- | -------- |
    | destinationLatitude  | 终点纬度                                                     | number   | sceneType=1或2时必填 |
    | destinationLongitude | 终点经度                                                     | number   | sceneType=1或2时必填 |
    | destinationName      | 终点名称                                                     | string   | sceneType=3时必填   |
    | originName           | 起点名称                                   | string   | 否，存在时可用于展示路线规划页面   |
    | originLatitude       | 起点纬度                                 | number   | 否，存在时可用于展示路线规划页面   |
    | originLongitude      | 起点经度                                  | number   | 否，存在时可用于展示路线规划页面   |
    | vehicleType          | 交通出行工具：0：驾车 1：步行 2：骑行 3：公交（路线规划场景有效） | number   | 否，缺省时由应用自行处理   |

    应用可根据[linkFeature](../quick-start/module-configuration-file.md#skills标签)中定义的特性功能，比如路线规划和导航结合接收到的参数开发不同的样式页面。

**完整示例：**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

let destinationLatitude: number;
let destinationLongitude: number;
let originLatitude: number | undefined;
let originLongitude: number | undefined;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');

    destinationLatitude = want.parameters?.destinationLatitude as number;
    destinationLongitude = want.parameters?.destinationLongitude as number;
    originLatitude = want.parameters?.originLatitude as number | undefined;
    originLongitude = want.parameters?.originLongitude as number | undefined;
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', '%{public}s', `Ability onWindowStageCreate: ${JSON.stringify(this.context)}`);

    const storage: LocalStorage = new LocalStorage({
      "destinationLatitude": destinationLatitude,
      "destinationLongitude": destinationLongitude,
      "originLatitude": originLatitude,
      "originLongitude": originLongitude
    } as Record<string, number>);

    if (originLatitude !== undefined && originLongitude !== undefined) {
      windowStage.loadContent('pages/IndexForNavigation', storage);
    } else {
      windowStage.loadContent('pages/IndexForRoutePlan', storage);
    }
  }
}
```
## 拉起邮件类应用扩展面板

### 调用方开发步骤
1. 导入ohos.app.ability.common模块。 
    ```ts
    import { common } from '@kit.AbilityKit';
    ```
2. 构造接口参数并调用startAbilityByType接口。

    ```ts
    let context = getContext(this) as common.UIAbilityContext;
    let wantParam: Record<string, Object> = {
      'sceneType': 1,
      'email': [encodeURI('xxx@example.com'),encodeURI('xxx@example.com')], // 收件人邮箱地址，多值以逗号分隔，对数组内容使用encodeURI()方法进行url编码
      'cc': [encodeURI('xxx@example.com'),encodeURI('xxx@example.com')], // 抄收人邮箱地址，多值以逗号分隔，对数组内容使用encodeURI()方法进行url编码
      'bcc': [encodeURI('xxx@example.com'),encodeURI('xxx@example.com')], // 密送人邮箱地址，多值以逗号分隔，对数组内容使用encodeURI()方法进行url编码
      'subject': encodeURI('邮件主题'), // 邮件主题，对内容使用encodeURI()方法进行url编码
      'body': encodeURI('邮件正文'), // 邮件正文，对内容使用encodeURI()方法进行url编码
      'ability.params.stream': [encodeURI('附件uri1'),encodeURI('附件uri2')], // 附件uri，多值以逗号分隔，对数组内容使用encodeURI()方法进行url编码
      'ability.want.params.uriPermissionFlag': 1
    };
    let abilityStartCallback: common.AbilityStartCallback = {
      onError: (code: number, name: string, message: string) => {
        console.log(`code:` + code + `name:` + name + `message:` + message);
      }
    }
    
    context.startAbilityByType("mail", wantParam, abilityStartCallback, (err) => {
    if (err) {
        console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
      } else {
        console.log(`success`);
      }
    });
    ```
    效果示例图：
    
    ![示例效果图](./figures/start-mail-panel.png)

### 目标方开发步骤
1. 在module.json5中新增[linkFeature](../quick-start/module-configuration-file.md#skills标签)属性并设置声明当前应用支持的特性功能，从而系统可以从设备已安装应用中找到当前支持该特性的应用。

    ~~~json
    {
    "abilities": [
        {
        "skills": [
            {
            "uris": [
                {
                "scheme": "mail", // 这里仅示意，应用需确保这里声明的的uri能被外部正常拉起
                "host": "mail",
                "path": "",
                "linkFeature": "ComposeMail" // 声明应用支持撰写邮件功能
                }
            ]
            }
        ]
        }
    ]
    }
    ~~~
    
2. 解析面板传过来的参数并做对应处理。

    ```ts
    UIAbility::onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void
    ```

    在参数**want.parameters**中会携带Caller方传入的参数（与调用方传入的有些差异），如下表所示：

    | 属性名称             | 含义                                                         | 数据类型 | 是否必填 |
    | -------------------- | ------------------------------------------------------------ | -------- | -------- |
    | email  | 收件人邮箱地址（支持多个且以逗号分隔）                                  | string[ ] | 否 |
    | cc | 抄收人邮箱地址（支持多个且以逗号分隔）                                  | string[ ] | 否 |
    | bcc    | 密送人邮箱地址（支持多个且以逗号分隔）                                  | string[ ] | 否  |
    | subject    | 邮件主题                               | string   | 否  |
    | body   | 邮件内容                             | string | 否  |
    | stream | 邮件附件列表（附件的uri地址列表）                  | string[ ] | 否  |
    
    应用可根据[linkFeature](../quick-start/module-configuration-file.md#skills标签)中定义的特性功能，比如撰写邮件结合接收到的参数开发不同的样式页面。

**完整示例：**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

let email: string[] | undefined;
let cc: string[] | undefined;
let bcc: string[] | undefined;
let subject: string | undefined;
let body: string | undefined;
let stream: string[] | undefined;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    subject = decodeURI(want.parameters?.subject as string);// 使用decodeURI()方法对邮件主题进行url解码，其他字段处理方法相同
	body = decodeURI(want.parameters?.body as string);// 使用decodeURI()方法对邮件内容进行url解码，其他字段处理方法相同
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    const storage: LocalStorage = new LocalStorage({
      "subject": subject,
      "body": body
    } as Record<string, Object>);

    windowStage.loadContent('pages/IndexForMail', storage);
  }
}
```
