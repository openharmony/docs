# PageAbility的启动模式

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @lidongrui-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

启动模式对应PageAbility被启动时的行为，支持单实例模式、多实例模式两种启动模式。


  **表1** PageAbility的启动模式

| 启动模式 | 描述 | 说明 |
| -------- | -------- | -------- |
| singleton | 单实例模式 | 每次调用startAbility方法时，如果应用进程中该类型的Ability实例已经存在，则复用已有的实例，系统中只存在唯一一个实例。表现为在最近任务列表中只有一个Ability实例。<br/>典型场景：当用户打开视频播放应用并观看视频，回到桌面后，再次打开视频播放应用，应用仍为回到桌面之前正在观看的视频。 |
| multiton | 多实例模式 | 缺省启动模式。每次调用startAbility方法时，都会在应用进程中创建一个新的Ability实例。表现为在最近任务列表中可以看到有多个该类型的Ability实例。<br/>典型场景：当用户打开文档应用，选择新建文档的时候，每次点击新建文档，都会创建一个新的文档任务，在最近任务列表中可以看到多个新建的文档任务。 |


应用开发者可在config.json配置文件中通过“launchType”配置启动模式。示例如下：

```json
{
  "module": {
    ...
    "abilities": [
      {
        // singleton: 单实例模式
        // multiton: 多实例模式
        "launchType": "multiton",
        ...
      }
    ]
  }
}
```


启动PageAbility时，对于多实例模式启动，以及单实例模式进行首次启动时，[PageAbility生命周期回调](pageability-lifecycle.md)均会被触发。单实例非首次启动时不会再触发onCreate()接口，而是触发onNewWant()，onNewWant()的说明如下表2所示。


  **表2** 单实例启动模式特有的回调函数说明

| 接口名 | 接口描述 |
| -------- | -------- |
| onNewWant(want:&nbsp;Want) | 单实例启动模式，PageAbility非首次启动时调用onNewWant方法，开发者可以在该方法中获取want，进而根据want做进一步处理。例如，单实例PageAbility迁移场景，指定页面拉起PageAbility场景。 |
