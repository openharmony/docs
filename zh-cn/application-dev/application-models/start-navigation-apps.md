# 拉起导航类应用


本章节介绍如何拉起导航类应用扩展面板。


## 导航类应用扩展面板参数说明

startAbilityByType接口中type字段为navigation，对应的wantParam参数：

| 属性名称             | 含义                                                         | 数据类型 | 是否必填 |
| -------------------- | ------------------------------------------------------------ | -------- | -------- |
| destinationLatitude  | 终点纬度                                                    | number   | sceneType=1或2时必填 |
| destinationLongitude | 终点经度                                                     | number   | sceneType=1或2时必填 |
| sceneType            | 意图取值 ：1：路线规划 2：导航 3： 地点搜索                                | number   | 否，缺省时默认为1   |
| destinationName      | 终点名称                                                     | string   | sceneType=3时必填   |
| destinationPoiIds      | 终点POI ID列表（路线规划或导航场景有效）                                                       | Record<number, string>   | 否   |
| originName           | 起点名称（路线规划场景有效）                                   | string   | 否   |
| originLatitude       | 起点纬度（路线规划场景有效）                                   | number   | 否   |
| originLongitude      | 起点经度（路线规划场景有效）                                   | number   | 否   |
| originPoiIds      | 起点POI ID列表（路线规划场景有效）                                                      | Record<number, string>   | 否   |
| vehicleType          | 交通出行工具：0：驾车 1：步行 2：骑行 3：公交（路线规划场景有效） | number   | 否，缺省时由应用自行处理   |

> **说明：**
> 
> * 本文中的经纬度均采用GCJ-02坐标系统。
> 
> * 终点POI ID和起点POI ID需开发者自行从各地图系统中获取，并按照以下对应关系传参。

```ts
let wantParam: Record<string, Object> = {
      // 其他参数
      ...,
      'destinationPoiIds': {
          1: '1111',  // key为1代表花瓣地图，value需为花瓣地图POI
          2: '2222'   // key为2代表高德地图，value需为高德地图POI
      } as Record<number, string>,
      'originPoiIds': {
          1: '3333',  // key为1代表花瓣地图，value需为花瓣地图POI
          2: '4444'   // key为2代表高德地图，value需为高德地图POI
      } as Record<number, string>
    };
```

## 拉起方开发步骤

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
      'destinationPoiIds': {
          1: "111111111111",
          2: "222222222222"
      } as Record<number, string>,
      'originName': 'xx市xx公园',
      'originLatitude': 31.060844,
      'originLongitude': 120.78315,
      'originPoiIds': {
          1: "333333333333",  
          2: "444444444444"
      } as Record<number, string>,
      'vehicleType': 0
    };
    let abilityStartCallback: common.AbilityStartCallback = {
      onError: (code: number, name: string, message: string) => {
        console.log(`onError code ${code} name: ${name} message: ${message}`);
      },
      onResult: (result)=>{
        console.log(`onResult result: ${JSON.stringify(result)}`);
      }
    }
    
    context.startAbilityByType("navigation", wantParam, abilityStartCallback, 
        (err) => {
            if (err) {
                console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
            } else {
                console.log(`success`);
            }
    });
    ```
    效果示例图：

    ![效果示例图](./figures/start-navigation-panel.png)

## 目标方开发步骤

1. 在module.json5中配置[uris](../quick-start/module-configuration-file.md#skills标签)，步骤如下：
    1. 设置linkFeature属性以声明当前应用支持的特性功能，从而系统可以从设备已安装应用中找到当前支持该特性的应用，取值范围如下：
        | 取值           | 含义                         |
        | -------------- | ---------------------------- |
        | Navigation     | 声明应用支持导航功能 		|
        | RoutePlan      | 声明应用支持路线规划功能		|
        | PlaceSearch    | 声明应用支持位置搜索功能     |
    2. 设置scheme、host、port、path/pathStartWith属性，与Want中URI相匹配，以便区分不同功能。
    ```json
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
    ```

2. 解析参数并做对应处理。

    ```ts
    UIAbility::onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void
    ```

    在参数**want.uri**中会携带目标方配置的linkFeature对应的uri;

    在参数**want.parameters**中会携带Caller方传入的参数（与调用方传入的有些差异），如下表所示：

    | 属性名称             | 含义                                                         | 数据类型 | 是否必填 |
    | -------------------- | ------------------------------------------------------------ | -------- | -------- |
    | destinationLatitude  | 终点纬度                                                     | number   | 路径规划或导航场景必填 |
    | destinationLongitude | 终点经度                                                     | number   | 路径规划或导航场景必填 |
    | destinationName      | 终点名称                                                     | string   | 位置搜索场景必填   |
    | destinationPoiId      | 终点POI ID                                                     | string   | 否，存在时可用于展示路线规划或导航页面   |
    | originName           | 起点名称                                   | string   | 否，存在时可用于展示路线规划页面   |
    | originLatitude       | 起点纬度                                 | number   | 否，存在时可用于展示路线规划页面   |
    | originLongitude      | 起点经度                                  | number   | 否，存在时可用于展示路线规划页面   |
    | originPoiId      | 起点POI ID                                                     | string   | 否，存在时可用于展示路线规划页面   |
    | vehicleType          | 交通出行工具：0：驾车 1：步行 2：骑行 3：公交（路线规划场景有效） | number   | 否，缺省时由应用自行处理   |

    应用可根据[linkFeature](../quick-start/module-configuration-file.md#skills标签)中定义的特性功能，比如路线规划、导航和位置搜索，结合接收到的uri开发不同的样式页面。

**完整示例：**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const TAG = 'EntryAbility'

export default class EntryAbility extends UIAbility {
    windowStage: window.WindowStage | null = null;

    uri?: string;
    destinationLatitude?: number;
    destinationLongitude?: number;
    destinationName?: string;
    originName?: string;
    originLatitude?: number;
    originLongitude?: number;
    vehicleType?: number;
    destinationPoiId?: string;
    originPoiId?: string;

    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(0x0000, TAG, `onCreate, want=${JSON.stringify(want)}`);
        super.onCreate(want, launchParam);
        this.parseWant(want);
    }

    onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(0x0000, TAG, `onNewWant, want=${JSON.stringify(want)}`);
        super.onNewWant(want, launchParam);
        this.parseWant(want);
        if (!this.windowStage) {
            hilog.error(0x0000, TAG, 'windowStage is null');
            this.context.terminateSelf();
            return;
        }
        this.loadPage(this.windowStage);
    }

    private parseWant(want: Want): void {
        this.uri = want.uri as string | undefined;
        this.destinationLatitude = want.parameters?.destinationLatitude as number | undefined;
        this.destinationLongitude = want.parameters?.destinationLongitude as number | undefined;
        this.destinationName = want.parameters?.destinationName as string | undefined;
        this.originName = want.parameters?.originName as string | undefined;
        this.originLatitude = want.parameters?.originLatitude as number | undefined;
        this.originLongitude = want.parameters?.originLongitude as number | undefined;
        this.vehicleType = want.parameters?.vehicleType as number | undefined;
        this.destinationPoiId = want.parameters?.destinationPoiId as string | undefined;
        this.originPoiId = want.parameters?.originPoiId as string | undefined;
    }

    private loadPage(windowStage: window.WindowStage): void {
        hilog.info(0x0000, TAG, `loadPage, uri=${this.uri}`);
        if (this.uri === 'maps://navigation') {
            // 构建导航场景参数
            const storage: LocalStorage = new LocalStorage({
                "destinationLatitude": this.destinationLatitude,
                "destinationLongitude": this.destinationLongitude,
                "destinationPoiId": this.destinationPoiId
            } as Record<string, Object>);
            // 拉起导航页面
            windowStage.loadContent('pages/NavigationPage', storage)
        } else if (this.uri === 'maps://routePlan') {
            // 构建路径规划场景参数
            const storage: LocalStorage = new LocalStorage({
                "destinationLatitude": this.destinationLatitude,
                "destinationLongitude": this.destinationLongitude,
                "destinationName": this.destinationName,
                "originName": this.originName,
                "originLatitude": this.originLatitude,
                "originLongitude": this.originLongitude,
                "vehicleType": this.vehicleType,
                "destinationPoiId": this.destinationPoiId,
                "originPoiId": this.originPoiId
            } as Record<string, Object>);
            // 拉起路径规划页面
            windowStage.loadContent('pages/RoutePlanPage', storage)
        }  else if (this.uri === 'maps://search') {
            // 构建位置搜索场景参数
            const storage: LocalStorage = new LocalStorage({
                "destinationName": this.destinationName
            } as Record<string, Object>);
            // 拉起位置搜索页面
            windowStage.loadContent('pages/PlaceSearchPage', storage)
        } else {
            // 默认拉起首页
            windowStage.loadContent('pages/Index', (err) => {
                if (err.code) {
                    hilog.error(0x0000, TAG, 'Failed to load the content. Cause: %{public}s',
                        JSON.stringify(err) ?? '');
                    return;
                }
                hilog.info(0x0000, TAG, 'Succeeded in loading the content.');
            });
        }
    }

    onDestroy(): void {
        hilog.info(0x0000, TAG, `onDestroy`);
    }

    onWindowStageCreate(windowStage: window.WindowStage): void {
        hilog.info(0x0000, TAG, `onWindowStageCreate`);
        this.windowStage = windowStage;
        this.loadPage(this.windowStage);
    }

    onWindowStageDestroy(): void {
        hilog.info(0x0000, TAG, '%{public}s', 'Ability onWindowStageDestroy');
    }

    onForeground(): void {
        hilog.info(0x0000, TAG, '%{public}s', 'Ability onForeground');
    }

    onBackground(): void {
        hilog.info(0x0000, TAG, '%{public}s', 'Ability onBackground');
    }
}
```