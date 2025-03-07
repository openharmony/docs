# 卡片条件刷新

当前卡片框架提供了如下按条件刷新卡片的方式：
 
- 网络刷新：表示在网络变化的场景下调用[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform)的生命周期回调函数自动刷新卡片内容。可以在[form_config.json](arkts-ui-widget-configuration.md)配置文件的`conditionUpdate`字段中进行设置，设置字段为network。
 
> **说明：**
> 1. 当从无网络到有网络连接时会触发刷新。而网络间切换（例如：WiFi间切换，WiFi到流量，流量到WiFi），或从有网络连接到无网络连接时不会触发刷新。
>
> 2. 为减少卡片在频繁开关网络场景进程启动次数，无网判定需要网络连续断开十分钟后，才会认为无网，下次联网后触发网络刷新。
>
> 3. 仅对系统应用的卡片生效。
 

  ```json
  {
    "forms": [
      {
        "name": "UpdateDuration",
        "description": "$string:widget_updateduration_desc",
        "src": "./ets/updateduration/pages/UpdateDurationCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "colorMode": "auto",
        "isDefault": true,
        "updateEnabled": true,
        "scheduledUpdateTime": "10:30",
        "updateDuration": 2,
        "defaultDimension": "2*2",
        "supportDimensions": [
          "2*2"
        ],
        "conditionUpdate": [
          "network"
        ]
      }
    ]
  }
  ```