# Window Subsystem ChangeLog

## cl.window.1 Change of Window Stage Lifecycle Listener Types

Changed the enumerated listener types of the window stage lifecycle in version 3.2.10.5 and later.

**Change Impacts**

Application lifecycle listeners developed using **FOREGROUND** and **BACKGROUND** in versions earlier than 3.2.10.5 will be invalidated in version 3.2.10.5 and later.

**Key API/Component Changes**

##  WindowStageEventType<sup>9+</sup>

Before change

| Name      | Value  | Description      |
| ---------- | ---- | ---------- |
| FOREGROUND | 1    | The window stage is running in the foreground.|
| BACKGROUND | 4    | The window stage is running in the background.|

After change
| Name  | Value  | Description      |
| ------ | ---- | ---------- |
| SHOWN  | 1    | The window stage is running in the foreground.|
| HIDDEN | 4    | The window stage is running in the background.|

**Adaptation Guide**

When registering lifecycle listeners, change the foreground and background event types to **SHOWN** and **HIDDEN**, respectively.

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
