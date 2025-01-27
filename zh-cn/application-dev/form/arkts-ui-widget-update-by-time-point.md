# 卡片定点刷新

当前卡片框架提供了如下两种定点刷新卡片的方式：

- 单定点刷新：表示在每天的某个特定时间点自动刷新卡片内容。可以在form_config.json配置文件中的`scheduledUpdateTime`字段中进行设置。例如，可以将刷新时间设置为每天的上午10点30分。
 
  
  ```json
  {
    "forms": [
      {
        "name": "ScheduledUpdateTime",
        "description": "$string:widget_scheupdatetime_desc",
        "src": "./ets/scheduledupdatetime/pages/ScheduledUpdateTimeCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "colorMode": "auto",
        "isDefault": true,
        "updateEnabled": true,
        "scheduledUpdateTime": "10:30",
        "updateDuration": 0,
        "defaultDimension": "2*2",
        "supportDimensions": [
          "2*2"
        ]
      }
    ]
  }
  ```

- 多定点刷新：表示在每天的多个特定时间点自动刷新卡片内容。可以在form_config.json配置文件中的`multiScheduledUpdateTime`字段中进行设置，例如，可以将刷新时间设置为每天的上午11点30分和下午4点30分。
  ```json
  {
    "forms": [
    {
        "name": "ScheduledUpdateTime",
        "description": "$string:widget_scheupdatetime_desc",
        "src": "./ets/scheduledupdatetime/pages/ScheduledUpdateTimeCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "colorMode": "auto",
        "isDefault": true,
        "updateEnabled": true,
        "scheduledUpdateTime": "10:30",
        "multiScheduledUpdateTime": "11:30,16:30,",
        "updateDuration": 0,
        "defaultDimension": "2*2",
        "supportDimensions": [
          "2*2"
        ]
      }
    ]
  }
  ```

在触发定点刷新后，系统会调用FormExtensionAbility的[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform)生命周期回调，在回调中，可以使用[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform)进行提供方刷新卡片。`onUpdateForm`生命周期回调的使用请参见[卡片生命周期管理](./arkts-ui-widget-lifecycle.md)。

> **说明：**
> 1. 当同时配置了定时刷新`updateDuration`和定点刷新`scheduledUpdateTime`时，定时刷新的优先级更高且定点刷新不会执行。如果想要配置定点刷新，则需要将`updateDuration`配置为0。
> 2. `multiScheduledUpdateTime`的配置最多可设置24个时间。
> 3. 同时配置了单定点和多定点刷新，多定点刷新配置生效，单定点刷新配置不生效。
> 4. 考虑到向前兼容的问题，尽量保留`scheduledUpdateTime`字段，不要直接删除。

**约束限制：**
1. 定点刷新在卡片可见情况下才会触发，在卡片不可见时仅会记录刷新动作和刷新数据，待可见时统一刷新布局。