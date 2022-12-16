# AppVersionInfo

The **AppVersionInfo** module defines the application version information.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name         | Type    | Readable  | Writable  | Description     |
| ----------- | ------ | ---- | ---- | ------- |
| appName     | string | Yes   | No   | Module name.  |
| versionCode | number | Yes   | No   | Module description.|
| versionName | string | Yes   | No   | Module description ID.|

**Example**
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
