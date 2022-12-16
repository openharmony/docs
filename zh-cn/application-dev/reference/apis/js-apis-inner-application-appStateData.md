# AppStateData

定义应用状态信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**系统API**：该接口为系统接口，三方应用不支持调用。

| 名称        | 类型                 | 必填 | 说明                                                         |
| ----------- | -------- | ---- | ------------------------------------------------------------ |
| bundleName<sup>8+</sup>     | string               | 否   | 包名。                                |
| uid<sup>8+</sup>   | number               | 否   | 用户ID。 |
| state<sup>8+</sup>  | number               | 否   | 应用状态。 |

**示例：**
```ts
import appManager from "@ohos.application.appManager"

appManager.getForegroundApplications((error, data) => {
    for(let i=0; i<data.length; i++) {
        let appStateData = data[i];
        console.info('appStateData.bundleName: ' + appStateData.bundleName);
        console.info('appStateData.uid: ' + appStateData.uid);
        console.info('appStateData.state: ' + appStateData.state);
    }
});
```