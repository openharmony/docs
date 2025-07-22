# PageAbility Launch Type


Depending on the launch type, the action performed when the PageAbility starts differs, as described in the table below.

**Table 1** PageAbility launch types

| Launch Type| Meaning| Description|
| -------- | -------- | -------- |
| singleton | Singleton mode| Each time **startAbility()** is called, if an ability instance of this type already exists in the application process, the instance is reused. There is only one ability instance of this type in the recent task list.<br>A typical scenario is as follows: When a user opens a video playback application and watches a video, returns to the home screen, and opens the video playback application again, the video that the user watched before returning to the home screen is still played.|
| multiton | Multiton mode| Default type. Each time **startAbility()** is called, a new ability instance is created in the application process. Multiple ability instances of this type are displayed in the recent task list.<br>A typical scenario is as follows: When a user opens a document application and touches **New**, a new document task is created. Multiple new document missions are displayed in the recent task list.|


You can set **launchType** in the **config.json** file to configure the launch type. The sample code is as follows:

```json
{
  "module": {
    ...
    "abilities": [
      {
        // singleton means the singleton mode.
        // multiton means the multiton mode.
        "launchType": "multiton",
        ...
      }
    ]
  }
}
```


When the PageAbility is started in multiton mode or it is started in singleton mode for the first time, the [PageAbility lifecycle callbacks](pageability-lifecycle.md) are triggered. When it is not started for the first time in singleton mode, the **onNewWant()** callback (as described in the table below) is triggered, but the **onCreate()** callback is not.


**Table 2** Callbacks specific to the singleton mode

| API| Description|
| -------- | -------- |
| onNewWant(want: Want) | **onNewWant()** is triggered when the PageAbility is not started for the first time in singleton mode. You can obtain Want from this callback and perform further processing based on Want. For example, in the singleton PageAbility migration scenario, you can specify a page to start the PageAbility.|
