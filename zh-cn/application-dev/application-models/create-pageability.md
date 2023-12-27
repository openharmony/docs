# 创建PageAbility


开发者需要重写app.js/app.ets中的生命周期回调函数，开发者通过DevEco Studio开发平台创建PageAbility时，DevEco Studio会在app.js/app.ets中默认生成onCreate()和onDestroy()方法，其他方法需要开发者自行实现。接口说明参见前述章节，创建PageAbility示例如下：

```ts
class MainAbility {
  onCreate() {
    // 获取context并调用相关方法
    let context = featureAbility.getContext();
    context.getBundleName((data, bundleName) => {
      Logger.info(TAG, 'ability bundleName:' + bundleName);
    });
    Logger.info(TAG, 'Application onCreate');
  }

  onDestroy() {
    Logger.info(TAG, 'Application onDestroy');
  }

  onShow(): void {
    Logger.info(TAG, 'Application onShow');
  }

  onHide(): void {
    Logger.info(TAG, 'Application onHide');
  }

  onActive(): void {
    Logger.info(TAG, 'Application onActive');
  }

  onInactive(): void {
    Logger.info(TAG, 'Application onInactive');
  }

  onNewWant() {
    Logger.info(TAG, 'Application onNewWant');
  }
}

export default new MainAbility();
```


PageAbility创建成功后，其abilities相关的配置项在config.json中体现，一个名字为EntryAbility的config.json配置文件示例如下：

```json
{
  ...
  "module": {
    ...
    "abilities": [
      {
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ],
        "orientation": "unspecified",
        "formsEnabled": false,
        "name": ".MainAbility",
        "srcLanguage": "ets",
        "srcPath": "MainAbility",
        "icon": "$media:icon",
        "description": "$string:MainAbility_desc",
        "label": "$string:MainAbility_label",
        "type": "page",
        "visible": true,
        "launchType": "singleton"
      },
      ...
    ]
    ...
  }
}
```


FA模型中，可以通过featureAbility的getContext接口获取应用上下文，进而使用上下文提供的能力。


  **表1** featureAbility接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| getContext() | 获取应用上下文。 |


通过getContext获取应用上下文并获取分布式目录的示例如下：

```ts
import featureAbility from '@ohos.ability.featureAbility';
import fs from '@ohos.file.fs';
```
```ts
(async (): Promise<void> => {
  let dir: string;
  try {
    Logger.info(TAG, 'Begin to getOrCreateDistributedDir');
    dir = await featureAbility.getContext().getOrCreateDistributedDir();
    promptAction.showToast({
      message: dir
    });
    Logger.info(TAG, 'distribute dir is ' + dir);
    let fd: number;
    let path = dir + '/a.txt';
    fd = fs.openSync(path, fs.OpenMode.READ_WRITE).fd;
    fs.close(fd);
  } catch (error) {
    Logger.error(TAG, `getOrCreateDistributedDir failed with : ${error}`);
  }
})()
```
