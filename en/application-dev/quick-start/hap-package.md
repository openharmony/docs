# HAP

The Harmony Ability Package (HAP) is the basic unit for installing and running applications. An HAP is a module package consisting of code, resource files, third-party libraries, and an application configuration file. There are two types of HAPs: entry and feature.

- entry: main module of and entry to an application, providing the basic application functionality.
- feature: dynamic feature module of an application, extending the application functionality. This type of HAP can be installed based on user needs and device types.

An application package can contain either only one entry HAP or one entry HAP plus one or more feature HAPs.

## When to Use

- Single HAP: If your application only uses the UIAbility (that is, no ExtensionAbility is required), a single HAP (entry HAP) is recommended. While an HAP can contain one or more UIAbilities, adopt the "one UIAbility + multiple pages" mode to avoid unnecessary resource loading.

- Multi-HAP: If your application needs to use ExtensionAbilities, develop multiple HAPs (one entry HAP and one or more feature HAPs) for it, with each HAP containing one UIAbility or one ExtensionAbility. Note that repeated packaging may arise if these HAPs reference the same library file.


## Constraints

- APIs and ArkUI components cannot be exported from the HAP to other modules.

- In an App Pack that contains multiple HAPs, each type of device supports only one entry HAP and zero, one, or more feature HAPs.

- If an application has multiple HAPs, the settings of the following parameters must be consistent across the configuration files of these HAPs: **bundleName**, **versionCode**, **versionName**, **minCompatibleVersionCode**, **debug**, **minAPIVersion**, **targetAPIVersion**, and **apiReleaseType**. The value of **moduleName** for any HAP of the same device type must be unique. The IDE validates the settings of these parameters when packaging the HAPs into an App Pack.

- If an application has multiple HAPs, the signing certificates of all HAPs and HSPs of this application must be the same. Applications are released to the application market in the form of App Pack after being signed. Before distribution, the application market splits an App Pack into HAPs and resigns them to ensure the consistency of HAP signing certificates. Before installing HAPs on a device through the CLI or DevEco Studio for debugging purposes, ensure that their signing certificates are the same. Otherwise, the installation will fail.

## Creating an HAP

To create an HAP in DevEco Studio:

1. Create a project to build the first ArkTS application.
2. Right-click the project directory and choose **New** > **Module** from the shortcut menu.
3. In the dialog box displayed, select **Empty Ability** as the template and click **Next**.
   
4. On the module configuration page, set **Module name**, **Module Type**, and **Device Type**, and click **Next**.

5. On the ability configuration page, set **Ability name** and click **Finish**.

## Developing an HAP

- You can add a UIAbility or ExtensionAbility to an HAP. For details, see <!--RP1-->[Adding an Ability to a Module](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-add-new-ability-V5)<!--RP1End-->.

- You can also configure an HAP to reference a HAR or HSP. For details, see [Using an HAR](./har-package.md#using-an-har) and [Using an HSP](./in-app-hsp.md#using-an-hsp).

## Debugging an HAP

After building code into one or more HAPs and installing or updating these HAPs, you can debug them. For details about how to build the same HAP into different versions based on the deployment environment, target user group, and running environment, see <!--RP2-->[Introduction](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-customized-multi-targets-and-products-guides-V5)<!--RP2End-->.

To debug an HAP, use either of the following tools:

- **Method 1**: Use DevEco Studio for debugging. For details, see <!--RP3-->[Setting Running/Debugging Configuration](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-run-debug-configurations-V5)<!--RP3End-->.

- Method 2: Use <!--Del-->[<!--DelEnd-->hdc<!--Del-->](https://gitee.com/openharmony/docs/blob/master/en/device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd--> (obtained from the **toolchains** directory in the OpenHarmony SDK) for debugging.

   Before debugging an HAP, install or update it using either of the methods:

   - Use hdc to install and update the HAP.

      When specifying the HAP, use the path to it on the operating system. In the following example, the operating system is Windows:

      ```shell
      // Installation and update: Multiple file paths can be specified.
      hdc install entry.hap feature.hap
      // Execution result
      install bundle successfully.
      // Uninstall
      hdc uninstall com.example.myapplication
      // Execution result
      uninstall bundle successfully.
      ```

   - Run the hdc shell command, and then use the Bundle Manager (bm) tool to install and update the HAP.

      When specifying the HAP, use the path to it on the real device. The sample code is as follows:

      ```shell
      // Run the hdc shell command before using the bm tool.
      hdc shell
      // Installation and update: Multiple file paths can be specified.
      bm install -p /data/app/entry.hap /data/app/feature.hap
      // Execution result
      install bundle successfully.
      // Uninstall
      bm uninstall -n com.example.myapplication
      // Execution result
      uninstall bundle successfully.
      ```

   After the HAP is installed or updated, you can debug it by following the instructions in [Ability Assistant](../tools/aa-tool.md).

<!--RP4-->
<!--RP4End-->