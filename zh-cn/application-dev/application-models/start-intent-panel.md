# 通过startAbilityByType拉起垂类应用
## 使用场景
开发者可通过特定的业务类型如导航、金融等，调用startAbilityByType接口拉起对应的垂域面板，该面板将展示目标方接入的垂域应用，由用户选择打开指定应用以实现相应的垂类意图。垂域面板为调用方提供统一的安全、可信的目标方应用，同时降低调用方的接入成本。  
![](./figures/process-start-intent-panel.png)

## 接口说明
接口**startAbilityByType<sup>11+</sup>** 是[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybytype11)和[UIExtensionContentSession](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#uiextensioncontentsessionstartabilitybytype11)提供的支持基于垂域业务类型拉起垂域面板，调用方通过指定特定的垂域业务类型即可拉起对应的垂域面板，在垂域面板上将展示目标方接入的垂域应用。

**type为navigation导航对应的wantParam:**

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


## 接入步骤
### 调用方接入步骤

1. 导入ohos.app.ability.common模块。 
    ```ts
    import { common } from '@kit.AbilityKit';
    ```
2. 构造接口参数并调用startAbilityByType接口。

    ```ts
    import { common } from '@kit.AbilityKit';

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

### 目标方接入步骤

1. 导入ohos.app.ability.UIAbility模块。
    ```ts
    import { UIAbility } from '@kit.AbilityKit';
    ```
2. 在module.json5中新增[linkFeature](../quick-start/module-configuration-file.md#skills标签)属性并设置声明当前应用支持的特性功能，从而系统可以从设备已安装应用中找到当前支持该特性的应用。

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

3. 解析参数并做对应处理。

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

**示例：**

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
