# 窗口子系统ChangeLog

## cl.window.1 setWindowPrivacyMode接口错误码返回值变更

**访问级别**

公开接口。

**变更原因**

setWindowPrivacyMode的API文档上注明接口调用需要ohos.permission.PRIVACY_WINDOW权限，但是在未添加该权限时，接口调用结果中没有正确返回错误码201。

**变更影响**

该变更为非兼容性变更。当应用使用setWindowPrivacyMode接口但未添加权限ohos.permission.PRIVACY_WINDOW时，将返回错误码201，需要开发者及时处理此结果。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony SDK 4.1.6.5开始。

**变更的接口/组件**

变更之前，未配置权限ohos.permission.PRIVACY_WINDOW时调用setWindowPrivacyMode接口，不会返回权限校验失败的错误码，但是实际未设置成功。

变更之后，未配置权限ohos.permission.PRIVACY_WINDOW时调用setWindowPrivacyMode接口，会返回错误码权限校验失败的错误码201，表示设置失败。

**适配指导**

调用setWindowPrivacyMode接口时如果未添加权限ohos.permission.PRIVACY_WINDOW，可以在回调中获取到错误码201，并及时处理。

```
import { UIAbility }from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage): void {
        console.log('onWindowStageCreate');
        let promise = windowStage.getMainWindow();
        promise.then((windowClass: window.Window)=>{
            windowClass.setWindowPrivacyMode(true, (err: BusinessError)=> {
                if (err.code) {
                    console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in setting the window to privacy mode.');
            });
        }).catch((err: BusinessError)=>{
            console.log("Failed to get main window. Cause:" + JSON.stringify(err));
        })
    }
};
```
