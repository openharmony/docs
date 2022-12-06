# AbilityStateData

定义Ability状态信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                     | 类型     | 可读 | 可写 | 说明                       |
| ----------------------- | ---------| ---- | ---- | ------------------------- |
| pid<sup>8+</sup>                     | number   | 是   | 否   | 进程ID。                    |
| bundleName<sup>8+</sup>              | string   | 是   | 否  | 应用包名。                  |
| abilityName<sup>8+</sup>             | string   | 是   | 否   | Ability名称。               |
| uid<sup>8+</sup>                     | number   | 是   | 否   | 用户ID。                  |
| state<sup>8+</sup>                   | number   | 是   | 否   | Ability状态。                |
| moduleName<sup>9+</sup> | string   | 是   | 否   | Ability所属的HAP包的名称。    |
| abilityType<sup>8+</sup> | string   | 是   | 否   | 能力类型、页面或服务等。    |

**示例：**
```ts
import appManager from "@ohos.application.appManager"

appManager.getForegroundApplications((error, data) => {
    for(let i=0; i<data.length; i++) {
        let appStateData = data[i];
        console.info('appStateData.pid: ' + appStateData.pid);
        console.info('appStateData.bundleName: ' + appStateData.bundleName);
        console.info('appStateData.abilityName: ' + appStateData.abilityName);
        console.info('appStateData.uid: ' + appStateData.uid);
        console.info('appStateData.state: ' + appStateData.state);
        console.info('appStateData.moduleName: ' + appStateData.moduleName);
        console.info('appStateData.abilityType: ' + appStateData.abilityType);
    }
});
```