# 窗口子系统ChangeLog

## cl.window.1 WindowStage生命周期监听类型名称变更

WindowStage生命周期的监听类型枚举定义自3.2.10.5版本起进行了变更。

**变更影响**

3.2.10.5版本之前使用FOREGROUND/BACKGROUND类型开发的应用生命周期监听，在3.2.10.5版本之后失效。

**关键接口/组件变更**

##  WindowStageEventType<sup>9+</sup>

变更前：

| 名称       | 值   | 说明       |
| ---------- | ---- | ---------- |
| FOREGROUND | 1    | 切到前台。 |
| BACKGROUND | 4    | 切到后台。 |

变更后：
| 名称   | 值   | 说明       |
| ------ | ---- | ---------- |
| SHOWN  | 1    | 切到前台。 |
| HIDDEN | 4    | 切到后台。 |

**适配指导**

在注册生命周期监听回调时，将前后台事件类型改为SHOWN/HIDDEN：

```
import Ability from '@ohos.application.Ability';

class myAbility extends Ability {
    onWindowStageCreate(windowStage) {
        console.log('onWindowStageCreate');
        try {
            windowStage.on('windowStageEvent', (stageEventType) => {
                switch (stageEventType) {
                    case window.WindowStageEventType.SHOWN:
                        console.log("windowStage shown");
                        break;
                    case window.WindowStageEventType.ACTIVE:
                        console.log("windowStage active");
                        break;
                    case window.WindowStageEventType.INACTIVE:
                        console.log("windowStage inActive");
                        break;
                    case window.WindowStageEventType.HIDDEN:
                        console.log("windowStage hidden");
                        break;
                    default:
                        break;
                }
        	} )
        } catch (exception) {
            console.error('Failed to enable the listener for window stage event changes. Cause:' +
                JSON.stringify(exception));
        };
    }
};
```
