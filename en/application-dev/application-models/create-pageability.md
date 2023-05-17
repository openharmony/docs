# Creating a PageAbility


When you create a PageAbility on DevEco Studio, DevEco Studio automatically generates the **onCreate()** and **onDestroy()** callbacks in **app.js** and **app.ets**. You need to implement the other lifecycle callbacks in **app.js** and **app.ets**. The following code snippet shows how to create a PageAbility:

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


After the PageAbility is created, its abilities-related configuration items are displayed in the **config.json** file. The following is an example **config.json** file of an ability named EntryAbility:

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
      "srcPath": "EntryAbility",
      "name": ".EntryAbility",
      "srcLanguage": "ets",
      "icon": "$media:icon",
      "description": "$string:EntryAbility_desc",
      "formsEnabled": false,
      "label": "$string:EntryAbility_label",
      "type": "page",
      "launchType": "singleton"
    }
  ]
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

(async () => {
  let dir: string;
  try {
    console.info('Begin to getOrCreateDistributedDir');
    dir = await featureAbility.getContext().getOrCreateDistributedDir();
    console.info('distribute dir is ' + dir)
  } catch (error) {
    console.error('getOrCreateDistributedDir failed with ' + error);
  }

  let fd: number;
  let path = dir + "/a.txt";
  fd = fs.openSync(path, fs.OpenMode.READ_WRITE).fd;
  fs.close(fd);
})()
```
