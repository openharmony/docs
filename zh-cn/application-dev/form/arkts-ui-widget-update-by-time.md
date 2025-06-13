# 卡片定时刷新

当前卡片框架提供了如下几种按时间刷新卡片的方式：

- 定时刷新：表示在一定时间间隔内调用[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform)的生命周期回调函数自动刷新卡片内容。可以在[form_config.json](arkts-ui-widget-configuration.md)配置文件的`updateDuration`字段中进行设置。例如，可以将`updateDuration`字段的值设置为2，表示刷新时间设置为每小时一次。

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
        ]
      }
    ]
  }
  ```
 > **说明：**
  >
  > 1. 在使用定时刷新时，需要在form_config.json配置文件中设置`updateEnabled`字段为`true`，以启用周期性刷新功能。
  >
  > 2. 为减少卡片被动周期刷新进程启动次数，降低卡片刷新功耗，应用市场在安装应用时可以为该应用配置刷新周期，
  > 也可以为已经安装的应用动态配置刷新周期，用来限制卡片刷新周期的时长，以达到降低周期刷新进程启动次数的目的。
  > <br/> ● 当配置了`updateDuration`（定时刷新）后，若应用市场动态配置了该应用的刷新周期，
  > 卡片框架会将form_config.json文件中配置的刷新周期与应用市场配置的刷新周期进行比较，取较长的刷新周期做为该卡片的定时刷新周期。
  > <br/> ● 若应用市场未动态配置该应用的刷新周期，则以form_config.json文件中配置的刷新周期为准。
  > <br/> ● 若该卡片取消定时刷新功能，该规则将无效。
  > <br/> ● 卡片定时刷新的更新周期单位为30分钟。应用市场配置的刷新周期范围是1~336，即最短为半小时(1 * 30min)刷新一次，最长为一周(336 * 30min)刷新一次。
  > <br/> ● 该规则从API11开始生效。若小于API11，则以form_config.json文件中配置的刷新周期为准。

- 下次刷新：表示指定卡片的下一次刷新时间。可以通过调用[setFormNextRefreshTime](../reference/apis-form-kit/js-apis-app-form-formProvider.md#setformnextrefreshtime)接口来实现。最短刷新时间为5分钟。例如，可以在接口调用后的5分钟内刷新卡片内容。

  ```ts
  import { FormExtensionAbility, formProvider } from '@kit.FormKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const TAG: string = 'UpdateByTimeFormAbility';
  const FIVE_MINUTE: number = 5;
  const DOMAIN_NUMBER: number = 0xFF00;
  
  export default class UpdateByTimeFormAbility extends FormExtensionAbility {
    onFormEvent(formId: string, message: string): void {
      // Called when a specified message event defined by the form provider is triggered.
      hilog.info(DOMAIN_NUMBER, TAG, `FormAbility onFormEvent, formId = ${formId}, message: ${JSON.stringify(message)}`);
      try {
        // 设置过5分钟后更新卡片内容
        formProvider.setFormNextRefreshTime(formId, FIVE_MINUTE, (err: BusinessError) => {
          if (err) {
            hilog.info(DOMAIN_NUMBER, TAG, `Failed to setFormNextRefreshTime. Code: ${err.code}, message: ${err.message}`);
            return;
          } else {
            hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in setFormNextRefreshTiming.');
          }
        });
      } catch (err) {
        hilog.info(DOMAIN_NUMBER, TAG, `Failed to setFormNextRefreshTime. Code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);
      }
    }
    // ... 
  }
  ```

在触发定时、下次刷新后，系统会调用FormExtensionAbility的[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform)生命周期回调，在回调中，可以使用[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform)进行提供方刷新卡片。`onUpdateForm`生命周期回调的使用请参见[卡片生命周期管理](./arkts-ui-widget-lifecycle.md)。

**约束限制：**
1. 定时刷新有配额限制，每张卡片每天最多通过定时方式触发刷新50次，定时刷新次数包含[卡片配置项updateDuration](arkts-ui-widget-configuration.md)和调用[setFormNextRefreshTime](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovidersetformnextrefreshtime)方法两种方式，当达到50次配额后，无法通过定时方式再次触发刷新，刷新次数会在每天的0点重置。
>
2. 当前定时刷新使用同一个计时器进行计时，因此卡片定时刷新的第一次刷新会有最多30分钟的偏差。比如第一张卡片A（每隔半小时刷新一次）在3点20分添加成功，定时器启动并每隔半小时触发一次事件，第二张卡片B(每隔半小时刷新一次)在3点40分添加成功，在3点50分定时器事件触发时，卡片A触发定时刷新，卡片B会在下次事件（4点20分）中才会触发。
>
3. 定时刷新在卡片可见情况下才会触发，在卡片不可见时仅会记录刷新动作和刷新数据，待可见时统一刷新布局。
>
4. 如果使能了卡片代理刷新，定时刷新和下次刷新不生效。
