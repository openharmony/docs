# Obtaining Reasons for Abnormal Application Exits

If an application crashes and then restarts, you often need to know why it crashed and what the state was, such as the RSS and PSS values of the application memory and the time of the last exit. You can obtain the information from the **launchParam** parameter in the **OnCreate** lifecycle function of the UIAbility and UIExtensionAbility. You can use the information to analyze and improve the application experience, adjust service logic, and boost the application stability.

## Constraints

Only the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) and [UIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md) support the obtaining of the last exit reason.

## Available APIs

Read [API](../reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md#launchparam) for the API reference.

| **API** | **Description**|
| -------- | -------- |
| [LaunchParam](../reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md#launchparam)       | Parameters for starting an ability. The **lastExitReason**, **lastExitMessage**, and **lastExitDetailInfo** fields record the information about the last abnormal exit of the ability. |
| [LastExitDetailInfo](../reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md#lastexitdetailinfo18)       | Detailed information about the last exit.|

## How to Develop

1. Obtain the reason for the last exit.

    Read the last exit information of the ability from **launchParam** of the **OnCreate** lifecycle function of the UIAbility class.

    ```ts
    import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';

    const MAX_RSS_THRESHOLD: number = 100000;
    const MAX_PSS_THRESHOLD: number = 100000;

    function doSomething() {
      console.log('do Something');
    }

    function doAnotherThing() {
      console.log('do Another Thing');
    }

    class MyAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        // Obtain the exit reason.
        let reason: number = launchParam.lastExitReason;
        let subReason: number = -1;
        if (launchParam.lastExitDetailInfo) {
          subReason = launchParam.lastExitDetailInfo.exitSubReason;
        }
        let exitMsg: string = launchParam.lastExitMessage;

        if (launchParam.lastExitDetailInfo) {
          // Obtain the information about the process where the ability was running before it exited.
          let pid = launchParam.lastExitDetailInfo.pid;
          let processName: string = launchParam.lastExitDetailInfo.processName;
          let rss: number = launchParam.lastExitDetailInfo.rss;
          let pss: number = launchParam.lastExitDetailInfo.pss;
          // Obtain other information.
          let uid: number = launchParam.lastExitDetailInfo.uid;
          let timestamp: number = launchParam.lastExitDetailInfo.timestamp;
        }
      }
    }
    ```

2. Perform service processing based on the last exit information.

    - You can add different processing logic for different exit reasons. The following provides an example.
    
      ```ts
      if (reason === AbilityConstant.LastExitReason.APP_FREEZE) {
          // The ability exited last time due to no response. Add processing logic here.
          doSomething();
      } else if (reason === AbilityConstant.LastExitReason.SIGNAL && subReason === 9) {
          // The ability exited last time because the process is terminated by the kill -9 signal. Add processing logic here.
          doAnotherThing();
      } else if (reason === AbilityConstant.LastExitReason.RESOURCE_CONTROL) {
          // The ability exited last time due to RSS control last time. Implement the processing logic here. The simplest approach is to print the information.
          console.log('The ability has exit last because the rss control, the lastExitReason is '+ reason +
          ', subReason is ' + subReason + ', lastExitMessage is ' + exitMsg);
      }
      ```

    - Detect abnormal application memory usage based on process information. The following provides an example.

      ```ts
      if (rss > MAX_RSS_THRESHOLD || pss > MAX_PSS_THRESHOLD) {
          // If the RSS or PSS value is too high, the memory usage is close to or has reached the upper limit. Print a warning or add processing logic.
          console.warn('Process ' + processName + '(' + pid + ') memory usage approaches or reaches the upper limit.');
      }
      ```

    - Use the timestamp of the abnormal exit to pinpoint when the issue occurred, facilitating problem locating.

      ```ts
      console.log('App ' + uid + ' terminated at ' + timestamp);
      ```
