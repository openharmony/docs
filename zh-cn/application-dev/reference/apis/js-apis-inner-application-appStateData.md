# AppStateData

定义应用状态信息，可以通过[getForegroundApplications](js-apis-app-ability-appManager.md#appmanagergetforegroundapplications)获取当前应用的相关信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：本模块被标记为@systemapi，对三方应用隐藏

| 名称                      | 类型   | 必填  | 说明       |
| ------------------------- | ------ | ---- | --------- |
| bundleName<sup>8+</sup>   | string | 否   | Bundle名称。 |
| uid<sup>8+</sup>          | number | 否   | 应用程序的uid。   |
| state<sup>8+</sup>        | number | 否   | 应用状态。<br>0：初始化状态，应用正在初始化<br>1：就绪状态，应用已初始化完毕<br>2：前台状态，应用位于前台<br>3：获焦状态。（预留状态，当前暂不支持）<br>4：后台状态，应用位于后台<br>5：退出状态，应用已退出 |

**示例：**

```ts
import appManager from "@ohos.app.ability.appManager"

function getForegroundAppInfos() {
    appManager.getForegroundApplications((error, data) => {
        if (error && error.code) {
            console.log('getForegroundApplications failed, error.code: ' + JSON.stringify(error.code) +
            ' error.message: ' + JSON.stringify(error.message));
            return;
        }
        for (let i = 0; i < data.length; i++) {
            let appStateData = data[i];
            console.log('appStateData.bundleName: ' + appStateData.bundleName);
            console.log('appStateData.uid: ' + appStateData.uid);
            console.log('appStateData.state: ' + appStateData.state);
        }
    });
}
```
