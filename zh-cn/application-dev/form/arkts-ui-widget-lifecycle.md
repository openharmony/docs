# 卡片生命周期管理


创建ArkTS卡片，需实现[FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)生命周期接口。

1. 在EntryFormAbility.ets中，导入相关模块。
```ts
  import { formBindingData, FormExtensionAbility, formInfo, formProvider } from '@kit.FormKit';
  import { Configuration, Want } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import type Base from '@ohos.base';
  import type common from '@ohos.app.ability.common';
  import dataPreferences from '@ohos.data.preferences';
  import hilog from '@ohos.hilog';
```

2. 在EntryFormAbility.ets中，实现[FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)生命周期接口，其中在onAddForm的入参want中可以通过[FormParam](../reference/apis-form-kit/js-apis-app-form-formInfo.md#formparam)取出卡片的相关信息。
   
```ts
   const TAG: string = 'JsCardFormAbility';
   const DOMAIN_NUMBER: number = 0xFF00;
   
   export default class JsCardFormAbility extends FormExtensionAbility {
     onAddForm(want: Want): formBindingData.FormBindingData {
       hilog.info(DOMAIN_NUMBER, TAG, '[JsCardFormAbility] onAddForm');
   
       // ...
       // 使用方创建卡片时触发，提供方需要返回卡片数据绑定类
       let obj: Record<string, string> = {
         title: 'titleOnCreate',
         detail: 'detailOnCreate'
       };
       let formData: formBindingData.FormBindingData = formBindingData.createFormBindingData(obj);
       return formData;
     }
   
     onCastToNormalForm(formId: string): void {
       // 使用方将临时卡片转换为常态卡片触发，提供方需要做相应的处理
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onCastToNormalForm');
     }
   
     onUpdateForm(formId: string): void {
       // 若卡片支持定时更新/定点更新/卡片使用方主动请求更新功能，则提供方需要重写该方法以支持数据更新
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onUpdateForm');
       let obj: Record<string, string> = {
         title: 'titleOnUpdate',
         detail: 'detailOnUpdate'
       };
       let formData: formBindingData.FormBindingData = formBindingData.createFormBindingData(obj);
       formProvider.updateForm(formId, formData).catch((error: Base.BusinessError) => {
         hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] updateForm, error:' + JSON.stringify(error));
       });
     }
   
     onChangeFormVisibility(newStatus: Record<string, number>): void {
       // 使用方发起可见或者不可见通知触发，提供方需要做相应的处理，仅系统应用生效
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onChangeFormVisibility');
     }
   
     onFormEvent(formId: string, message: string): void {
       // 若卡片支持触发事件，则需要重写该方法并实现对事件的触发
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onFormEvent');
       // ...
     }
   
     onRemoveForm(formId: string): void {
       // 删除卡片实例数据
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onRemoveForm');
       // 删除之前持久化的卡片实例数据
       // 此接口请根据实际情况实现，具体请参考：FormExtAbility Stage模型卡片实例
       deleteFormInfo(formId, this.context);
     }
   
     onConfigurationUpdate(config: Configuration) {
       // 当前formExtensionAbility存活时更新系统配置信息时触发的回调。
       // 需注意：formExtensionAbility创建后5秒内无操作将会被清理。
       hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onConfigurationUpdate:' + JSON.stringify(config));
     }
   
     onAcquireFormState(want: Want) {
       // 卡片提供方接收查询卡片状态通知接口，默认返回卡片初始状态。
       return formInfo.FormState.READY;
     }
   }
```


> **说明：**
>
> FormExtensionAbility进程不能常驻后台，即在卡片生命周期回调函数中无法处理长时间的任务，在生命周期调度完成后会继续存在5秒，如5秒内没有新的生命周期回调触发则进程自动退出。针对可能需要5秒以上才能完成的业务逻辑，建议[拉起主应用](arkts-ui-widget-event-uiability.md)进行处理，处理完成后使用[updateForm()](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform)通知卡片进行刷新。
