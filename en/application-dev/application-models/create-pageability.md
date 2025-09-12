# Creating a PageAbility

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @lidongrui-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

When you create a PageAbility in DevEco Studio, DevEco Studio automatically generates the **onCreate()** and **onDestroy()** callbacks in **app.js** and **app.ets**. You need to implement the other lifecycle callbacks in **app.js** and **app.ets**. For details about the callbacks, see [PageAbility Lifecycle](pageability-lifecycle.md). The following code snippet shows how to create a PageAbility:

```ts
import featureAbility from '@ohos.ability.featureAbility';
import hilog from '@ohos.hilog';

const TAG: string = 'MainAbility';
const domain: number = 0xFF00;

class MainAbility {
  onCreate() {
    // Obtain the context and call related APIs.
    let context = featureAbility.getContext();
    context.getBundleName((data, bundleName) => {
      hilog.info(domain, TAG, 'ability bundleName:' ,bundleName);
    });
    hilog.info(domain, TAG, 'Application onCreate');
  }

  onDestroy() {
    hilog.info(domain, TAG, 'Application onDestroy');
  }

  onShow(): void {
    hilog.info(domain, TAG, 'Application onShow');
  }

  onHide(): void {
    hilog.info(domain, TAG, 'Application onHide');
  }

  onActive(): void {
    hilog.info(domain, TAG, 'Application onActive');
  }

  onInactive(): void {
    hilog.info(domain, TAG, 'Application onInactive');
  }

  onNewWant() {
    hilog.info(domain, TAG, 'Application onNewWant');
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
import hilog from '@ohos.hilog';

const TAG: string = 'PagePageAbilityFirst';
const domain: number = 0xFF00;
```
```ts
(async (): Promise<void> => {
  let dir: string;
  try {
    hilog.info(domain, TAG, 'Begin to getOrCreateDistributedDir');
    dir = await featureAbility.getContext().getOrCreateDistributedDir();
    promptAction.showToast({
      message: dir
    });
    hilog.info(domain, TAG, 'distribute dir is ' + dir);
    let fd: number;
    let path = dir + '/a.txt';
    fd = fs.openSync(path, fs.OpenMode.READ_WRITE).fd;
    fs.close(fd);
  } catch (error) {
    hilog.error(domain, TAG, 'getOrCreateDistributedDir failed with : ' + error);
  }
})()
```
