# 创建PageAbility


开发者需要重写app.js/app.ets中的生命周期回调函数，开发者通过DevEco Studio开发平台创建PageAbility时，DevEco Studio会在app.js/app.ets中默认生成onCreate()和onDestroy()方法，其他方法需要开发者自行实现。接口说明参见前述章节，创建PageAbility示例如下：

```ts
export default {
  onCreate() {
    console.info('Application onCreate')
  },
  onDestroy() {
    console.info('Application onDestroy')
  },
  onShow() {
    console.info('Application onShow')
  },
  onHide() {
    console.info('Application onHide')
  },
  onActive() {
    console.info('Application onActive')
  },
  onInactive() {
    console.info('Application onInactive')
  },
  onNewWant() {
    console.info('Application onNewWant')
  },
}
```


PageAbility创建成功后，其abilities相关的配置项在config.json中体现，一个名字为MainAbility的config.json配置文件示例如下：

```json
{
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
      "visible": true,
      "srcPath": "MainAbility",
      "name": ".MainAbility",
      "srcLanguage": "ets",
      "icon": "$media:icon",
      "description": "$string:MainAbility_desc",
      "formsEnabled": false,
      "label": "$string:MainAbility_label",
      "type": "page",
      "launchType": "singleton"
    }
  ]
}
```


FA模型中，可以通过featureAbility的getContext接口获取应用上下文，进而使用上下文提供的能力。


  **表1** featureAbility接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| getContext() | 获取应用上下文。 |


通过getContext获取应用上下文并获取分布式目录的示例如下：

```ts
import featureAbility from '@ohos.ability.featureAbility'
import fileIo from '@ohos.fileio'

(async () => {
  let dir: string
  try {
    console.info('Begin to getOrCreateDistributedDir')
    dir = await featureAbility.getContext().getOrCreateDistributedDir()
    console.info('distribute dir is ' + dir)
  } catch (error) {
    console.error('getOrCreateDistributedDir failed with ' + error)
  }

  let fd: number;
  let path = dir + "/a.txt";
  fd = fileIo.openSync(path, 0o2 | 0o100, 0o666);
  fileIo.close(fd);
})()
```
