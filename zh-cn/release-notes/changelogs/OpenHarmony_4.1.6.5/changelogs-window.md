# 窗口子系统ChangeLog

## cl.window.1 setWindowPrivacyMode接口错误码返回值变更

setWindowPrivacyMode自3.2.10.5版本起补全权限校验失败结果的错误码返回。

**变更影响**
当应用使用setWindowPrivacyMode接口但未添加权限ohos.permission.PRIVACY_WINDOW时，将返回错误码201，需要应用及时处理此结果。

**适配指导**

调用setWindowPrivacyMode接口时可以通过callback或promise.catch捕获错误码，并进行判断处理

```
import Ability from '@ohos.application.Ability';
import { BusinessError } from '@ohos.base';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        let promise = windowStage.getMainWindow();
        promise.then((windowClass: window.Window)=>{
            windowClass.setWindowPrivacyMode(true, (err)=> {
                if (err.code != 0) {
                    console.error('Failed to set the window to privacy mode. Cause:' + JSON.stringify(err));
                    return;
                }
                console.info('Succeeded in setting the window to privacy mode.');
            });

            // or...
            let promise = windowClass.setWindowPrivacyMode(isPrivacyMode);
            promise.then(() => {
                console.info('Succeeded in setting the window to privacy mode.');
            }).catch((err: BusinessError) => {
                console.error('Failed to set the window to privacy mode. Cause: ' + JSON.stringify(err));
            });
        }).catch((err)=>{
            console.log("Failed to get main window. Cause:" + JSON.stringify(err));
        })
    }
};
```
