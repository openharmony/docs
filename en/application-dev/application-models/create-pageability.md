# Creating a PageAbility


When you create a PageAbility on DevEco Studio, DevEco Studio automatically generates the **onCreate()** and **onDestroy()** callbacks in **app.js** and **app.ets**. You need to implement the other lifecycle callbacks in **app.js** and **app.ets**. The following code snippet shows how to create a PageAbility:

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Logger from '../utils/Logger';

const TAG: string = 'MainAbility';

class MainAbility {
  onCreate() {
    // Obtain the context and call related APIs.
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


After the PageAbility is created, its abilities-related configuration items are displayed in the **config.json** file. The following is an example **config.json** file of an ability named EntryAbility:

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


In the FA model, you can call **getContext** of **featureAbility** to obtain the application context and then use the capabilities provided by the context.


  **Table 1** featureAbility APIs

| API| Description|
| -------- | -------- |
| getContext() | Obtains the application context.|


The following code snippet shows how to use **getContext()** to obtain the application context and distributed directory:

```ts
import featureAbility from '@ohos.ability.featureAbility';
import fs from '@ohos.file.fs';
import promptAction from '@ohos.promptAction';
import Logger from '../../utils/Logger';

const TAG: string = 'PagePageAbilityFirst';
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
