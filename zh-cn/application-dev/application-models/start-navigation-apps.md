# 拉起导航类应用（startAbilityByType）


本章节介绍如何拉起导航类应用扩展面板。

## 导航类应用扩展面板参数说明

startAbilityByType接口中type字段为navigation，支持路线规划、导航、位置搜索三种意图场景，对应的wantParam参数如下：

> **说明：**
> 本文中的经纬度均采用GCJ-02坐标系统。

- 路线规划场景

    | 参数名               | 类型                   | 必填 | 说明                                                 |
    | -------------------- | ---------------------- | ---- | ---------------------------------------------------- |
    | sceneType            | number                 | 否   | 意图场景，表明本次请求对应的操作意图。默认为1，路线规划场景填1或不填。                   |
    | originName           | string                 | 否   | 起点名称。                                             |
    | originLatitude       | number                 | 否   | 起点纬度。                                             |
    | originLongitude      | number                 | 否   | 起点经度。                                             |
    | originPoiIds         | Record<number, string> | 否   | 起点POI ID列表，当前仅支持传入花瓣地图和高德地图的POI ID。|
    | destinationName      | string                 | 否   | 终点名称。                                             |
    | destinationLatitude  | number                 | 是   | 终点纬度。                                             |
    | destinationLongitude | number                 | 是   | 终点经度。                                             |
    | destinationPoiIds    | Record<number, string> | 否   | 终点POI ID列表，当前仅支持传入花瓣地图和高德地图的POI ID。|
    | vehicleType          | number                 | 否   | 交通出行工具，取值：0-驾车，1-步行，2-骑行，3-公交。 |

- 导航场景

    | 参数名               | 类型                   | 必填 | 说明              |
    | -------------------- | ---------------------- | ---- | ----------------- |
    | sceneType            | number                 | 是   | 意图场景，表明本次请求对应的操作意图。导航场景填2。 |
    | destinationName      | string                 | 否   | 终点名称。          |
    | destinationLatitude  | number                 | 是   | 终点纬度。          |
    | destinationLongitude | number                 | 是   | 终点经度。          |
    | destinationPoiIds    | Record<number, string> | 否   | 终点POI ID列表，当前仅支持传入花瓣地图和高德地图的POI ID。|

- 位置搜索场景

    | 参数名          | 类型   | 必填 | 说明                  |
    | --------------- | ------ | ---- | --------------------- |
    | sceneType       | number | 是   | 意图场景，表明本次请求对应的操作意图。位置搜索场景填3。 |
    | destinationName | string | 是   | 地点名称。              |


## 拉起方开发步骤

1. 导入相关模块。 
    ```ts
    import { common } from '@kit.AbilityKit';
    ```
2. 构造接口参数并调用startAbilityByType接口。 

   终点POI ID列表（destinationPoiIds）和起点POI ID列表（originPoiIds）需开发者自行从各地图系统中获取，并按照对应关系传参。


    ```ts
    let context = getContext(this) as common.UIAbilityContext;
    let wantParam: Record<string, Object> = {
      'sceneType': 1,
      'destinationLatitude': 32.060844,
      'destinationLongitude': 118.78315,
      'destinationName': 'xx市xx路xx号',
      'destinationPoiIds': {
          1: '1111',  // key为1代表花瓣地图，value需为花瓣地图POI
          2: '2222'   // key为2代表高德地图，value需为高德地图POI
      } as Record<number, string>,
      'originName': 'xx市xx公园',
      'originLatitude': 31.060844,
      'originLongitude': 120.78315,
      'originPoiIds': {
          1: '3333',  // key为1代表花瓣地图，value需为花瓣地图POI
          2: '4444'   // key为2代表高德地图，value需为高德地图POI
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
    UIAbility.onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void
    ```

    在参数**want.uri**中会携带目标方配置的linkFeature对应的uri。

    在参数**want.parameters**中会携带Caller方传入的参数，不同场景参数如下所示。

    - 路线规划场景
    
        | 参数名               | 类型   | 必填 | 说明                                                 |
        | -------------------- | ------ | ---- | ---------------------------------------------------- |
        | originName           | string | 否   | 起点名称。                                             |
        | originLatitude       | number | 否   | 起点纬度。                                             |
        | originLongitude      | number | 否   | 起点经度。                                             |
        | originPoiId          | string | 否   | 起点POI ID，当前仅支持花瓣地图和高德地图获取此参数。      |
        | destinationName      | string | 否   | 终点名称。                                             |
        | destinationLatitude  | number | 是   | 终点纬度。                                             |
        | destinationLongitude | number | 是   | 终点经度。                                             |
        | destinationPoiId     | string | 否   | 终点POI ID，当前仅支持花瓣地图和高德地图获取此参数。      |
        | vehicleType          | number | 否   | 交通出行工具，取值：0-驾车，1-步行，2-骑行，3-公交。 |
    
    - 导航场景
    
        | 参数名               | 类型   | 必填 | 说明       |
        | -------------------- | ------ | ---- | ---------- |
        | destinationName      | string | 否   | 终点名称。   |
        | destinationLatitude  | number | 是   | 终点纬度。   |
        | destinationLongitude | number | 是   | 终点经度。   |
        | destinationPoiId     | string | 否   | 终点POI ID，当前仅支持花瓣地图和高德地图获取此参数。|

    - 位置搜索场景
    
        | 参数名          | 类型   | 必填 | 说明     |
        | --------------- | ------ | ---- | -------- |
        | destinationName | string | 是   | 地点名称。 |

    应用可根据[linkFeature](../quick-start/module-configuration-file.md#skills标签)中定义的特性功能，比如路线规划、导航和位置搜索，结合接收到的uri和参数开发不同的样式页面。

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