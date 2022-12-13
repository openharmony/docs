# AppVersionInfo

定义应用版本信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称          | 类型     | 可读   | 可写   | 说明      |
| ----------- | ------ | ---- | ---- | ------- |
| appName     | string | 是    | 否    | 模块名称。   |
| versionCode | number | 是    | 否    | 模块描述信息。 |
| versionName | string | 是    | 否    | 描述信息ID。 |

**示例：**
```ts
let appName;
let versionCode;
let versionName;
this.context.getAppVersionInfo((error, data) => {
    console.info('getAppVersionInfo data is:' + JSON.stringify(data));
    appName = data.appName;
    versionCode = data.versionCode;
    versionName = data.versionName;
});
```