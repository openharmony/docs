# 拉起航班类应用（startAbilityByType）


本章节介绍如何拉起航班类应用扩展面板。适用于已获取航班号等信息时，可通过航班类应用扩展面板，并传递指定参数，将设备上所有符合对应航班类功能的应用匹配出来，并展示在面板上。

## 航班类应用扩展面板参数说明

startAbilityByType接口中type字段为flight，支持按航班号查询、按起降地查询两种意图场景，对应的wantParam参数如下：

- 按航班号查询场景

    | 参数名        | 类型   | 必填 | 说明                                                         |
    | ------------- | ------ | ---- | ------------------------------------------------------------ |
    | sceneType     | number | 否   | 意图，默认为1，按航班号查询场景填1或不填                     |
    | flightNo      | string | 是   | 航班号，航司二位代码+数字。 |
    | departureDate | string | 否   | 航班出发时间：YYYY-MM-DD                                     |

- 按起降地查询场景

    | 参数名               | 类型                   | 必填 | 说明                                                     |
    | -------------------- | ---------------------- | ---- | -------------------------------------------------------- |
    | sceneType            | number                 | 是   | 意图，按起降地查询场景填2                                        |
    | originLocation      | string                 | 是   | 出发地                                                 |
    | destinationLocation  | number                 | 是   | 目的地                                                 |
    | departureDate | number                 | 否   | 航班出发时间：YYYY-MM-DD                                                 |


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
      'flightNo': 'ZH1509',
      'departureDate': '2024-10-01'
    };
    let abilityStartCallback: common.AbilityStartCallback = {
      onError: (code: number, name: string, message: string) => {
        console.log(`onError code ${code} name: ${name} message: ${message}`);
      },
      onResult: (result)=>{
        console.log(`onResult result: ${JSON.stringify(result)}`);
      }
    }
    
    context.startAbilityByType("flight", wantParam, abilityStartCallback, 
        (err) => {
            if (err) {
                console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
            } else {
                console.log(`success`);
            }
    });
    ```
    效果示例图：    
    ![效果示例图](./figures/start-flight-panel.png)

## 目标方开发步骤

1. 在module.json5中配置[uris](../quick-start/module-configuration-file.md#skills标签)，步骤如下：
    1. 设置linkFeature属性以声明当前应用支持的特性功能，从而系统可以从设备已安装应用中找到当前支持该特性的应用，取值范围如下：
        | 取值        | 含义                     |
        | ----------- | ------------------------ |
        | QueryByFlightNo  | 声明应用支持按航班号查询航班     |
        | QueryByLocation   | 声明应用支持按起降地查询航班 |
    2. 设置scheme、host、port、path/pathStartWith属性，与Want中URI相匹配，以便区分不同功能。
        ```json
        {
            "abilities": [
                {
                    "skills": [
                        {
                            "uris": [
                                {
                                    "scheme": "flight",
                                    "host": "queryByFlightNo",
                                    "path": "",
                                    "linkFeature": "QueryByFlightNo"
                                },
                                {
                                    "scheme": "flight",
                                    "host": "queryByLocation",
                                    "path": "",
                                    "linkFeature": "QueryByLocation"
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

    在参数**want.parameters**中会携带Caller方传入的参数，不同场景参数如下所示

    - 按航班号查询场景
    
        | 参数名               | 类型   | 必填 | 说明                                                 |
        | -------------------- | ------ | ---- | ---------------------------------------------------- |
        | flightNo           | string | 是   | 航班号，航司二位代码+数字。                                             |
        | departureDate       | string | 否   | 航班出发时间：YYYY-MM-DD。不填时，Target可按当天处理。                                             |
    
    - 按起降地查询场景
    
        | 参数名               | 类型   | 必填 | 说明                                               |
        | -------------------- | ------ | ---- | -------------------------------------------------- |
        | originLocation      | string | 是   | 出发地                                           |
        | destinationLocation  | number | 是   | 目的地                                           |
        | departureDate | number | 否   | 航班出发时间：YYYY-MM-DD。不填时，Target可按当天处理。    |

    应用可根据[linkFeature](../quick-start/module-configuration-file.md#skills标签)中定义的特性功能，比如按航班号查询和按起降地查询，结合接收到的uri和参数开发不同的样式页面。

**完整示例：**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const TAG = 'EntryAbility'

export default class EntryAbility extends UIAbility {
    windowStage: window.WindowStage | null = null;

    uri?: string;
    flightNo?: string;
    departureDate?: string;
    originLocation?: string;
    destinationLocation?: string;

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
        this.flightNo = want.parameters?.flightNo as string | undefined;
        this.departureDate = want.parameters?.departureDate as string | undefined;
        this.originLocation = want.parameters?.originLocation as string | undefined;
        this.destinationLocation = want.parameters?.destinationLocation as string | undefined;
    }

    private loadPage(windowStage: window.WindowStage): void {
        hilog.info(0x0000, TAG, `loadPage, uri=${this.uri}`);
        if (this.uri === 'flight://queryByFlightNo') {
            // 构建按航班号查询场景参数
            const storage: LocalStorage = new LocalStorage({
                "flightNo": this.flightNo,
                "departureDate": this.departureDate
            } as Record<string, Object>);
            // 拉起按航班号查询页面
            windowStage.loadContent('pages/QueryByFlightNoPage', storage)
        } else if (this.uri === 'flight://queryByLocation') {
            // 构建按起降地查询场景参数
            const storage: LocalStorage = new LocalStorage({
                "originLocation": this.originLocation,
                "destinationLocation": this.destinationLocation,
                "departureDate": this.departureDate
            } as Record<string, Object>);
            // 拉起按起降地查询页面
            windowStage.loadContent('pages/QueryByLocationPage', storage)
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