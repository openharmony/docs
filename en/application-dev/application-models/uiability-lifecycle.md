# UIAbility Component Lifecycle


## Overview

When a user opens, switches, and returns to an application, the UIAbility instances in the application transit in their different states. The UIAbility class provides a series of callbacks. Through these callbacks, you can know the state changes of the UIAbility instance, for example, being created or destroyed, or running in the foreground or background.

The lifecycle of UIAbility has four states: **Create**, **Foreground**, **Background**, and **Destroy**, as shown in the figure below.

**Figure 1** UIAbility lifecycle states
![Ability-Life-Cycle](figures/Ability-Life-Cycle.png)  


## Description of Lifecycle States


### Create

The **Create** state is triggered when the UIAbility instance is created during application loading. The system invokes the **onCreate()** callback. In this callback, you can perform application initialization operations, for example, defining variables or loading resources.


```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
  onCreate(want, launchParam) {
    // Initialize the application.
  }
  ...
}
```

> **NOTE**
>
> [Want](../reference/apis/js-apis-app-ability-want.md) is used as the carrier to transfer information between application components. For details, see [Want](want-overview.md).

### WindowStageCreate and WindowStageDestory

After the UIAbility instance is created but before it enters the **Foreground** state, the system creates a WindowStage instance and triggers the **onWindowStageCreate()** callback. You can set UI loading and WindowStage event subscription in the callback.

**Figure 2** WindowStageCreate and WindowStageDestory 
![Ability-Life-Cycle-WindowStage](figures/Ability-Life-Cycle-WindowStage.png)  

In the **onWindowStageCreate()** callback, use [loadContent()](../reference/apis/js-apis-window.md#loadcontent9-2) to set the page to be loaded, and call [on('windowStageEvent')](../reference/apis/js-apis-window.md#onwindowstageevent9) to subscribe to [WindowStage events](../reference/apis/js-apis-window.md#windowstageeventtype9), for example, having or losing focus, or becoming visible or invisible.

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    // Subscribe to the WindowStage events (having or losing focus, or becoming visible or invisible).
    try {
      windowStage.on('windowStageEvent', (data) => {
        let stageEventType: window.WindowStageEventType = data;
        switch (stageEventType) {
          case window.WindowStageEventType.SHOWN: // Switch to the foreground.
            console.info('windowStage foreground.');
            break;
          case window.WindowStageEventType.ACTIVE: // Gain focus.
            console.info('windowStage active.');
            break;
          case window.WindowStageEventType.INACTIVE: // Lose focus.
            console.info('windowStage inactive.');
            break;
          case window.WindowStageEventType.HIDDEN: // Switch to the background.
            console.info('windowStage background.');
            break;
          default:
            break;
        }
      });
    } catch (exception) {
      console.error('Failed to enable the listener for window stage event changes. Cause:' +
      JSON.stringify(exception));
    }

    // Set UI loading.
    windowStage.loadContent('pages/Index', (err, data) => {
      ...
    });
  }
}
```

> **NOTE**
>
> For details about how to use WindowStage, see [Window Development](../windowmanager/application-window-stage.md).

Before the UIAbility instance is destroyed, the **onWindowStageDestroy()** callback is invoked to release UI resources. In this callback, you can unsubscribe from the WindowStage events.


```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

export default class EntryAbility extends UIAbility {
  windowStage: window.WindowStage;
  ...

  onWindowStageCreate(windowStage: window.WindowStage) {
    this.windowStage = windowStage;
    ...
  }

  onWindowStageDestroy() {
    // Release UIresources.
    // Unsubscribe from the WindowStage events such as having or losing focus in the onWindowStageDestroy() callback.
    try {
      this.windowStage.off('windowStageEvent');
    } catch (err) {
      console.error(`Failed to disable the listener for window stage event changes. Code is ${err.code}, message is ${err.message}`);
    };
  }
}
```


### Foreground and Background

The **Foreground** and **Background** states are triggered when the UIAbility instance is switched to the foreground and background respectively. They correspond to the **onForeground()** and **onBackground()** callbacks.

The **onForeground()** callback is triggered before the UI of the UIAbility instance becomes visible, for example, when the UIAbility instance is switched to the foreground. In this callback, you can apply for resources required by the system or re-apply for resources that have been released in the **onBackground()** callback.

The **onBackground()** callback is triggered after the UI of the UIAbility component is completely invisible, for example, when the UIAbility instance is switched to the background. In this callback, you can release useless resources or perform time-consuming operations such as saving the status.

For example, an application needs to use positioning, and the application has requested the positioning permission from the user. Before the UI is displayed, you can enable positioning in the **onForeground()** callback to obtain the location information.

When the application is switched to the background, you can disable positioning in the **onBackground()** callback to reduce system resource consumption.


```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
  ...

  onForeground() {
    // Apply for the resources required by the system or re-apply for the resources released in onBackground().
  }

  onBackground() {
    // Release useless resources when the UI is invisible, or perform time-consuming operations in this callback,
    // for example, saving the status.
  }
}
```


### Destroy

The **Destroy** state is triggered when the UIAbility instance is destroyed. You can perform operations such as releasing system resources and saving data in the **onDestroy()** callback.

The UIAbility instance is destroyed when **terminateSelf()** is called or the user closes the instance in **Recents**.

```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class EntryAbility extends UIAbility {
  ...

  onDestroy() {
    // Release system resources and save data.
  }
}
```
