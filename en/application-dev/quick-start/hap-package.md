# HAP
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The Harmony Ability Package (HAP) is the basic unit for installing and running applications. A HAP is a module package consisting of code, resource files, third-party libraries, and an application configuration file. There are two types of HAPs: entry and feature.

- entry: main module of and entry to an application, providing the basic application functionality.
- feature: dynamic feature module of an application, extending the application functionality. This type of HAP can be installed based on user needs and device types.

An application package can contain either only one entry HAP or one entry HAP plus one or more feature HAPs.

## When to Use

- Single HAP: If your application only uses the UIAbility (that is, no ExtensionAbility is required), a single HAP (entry HAP) is recommended. While a HAP can contain one or more UIAbilities, adopt the "one UIAbility + multiple pages" mode to avoid unnecessary resource loading.

- Multi-HAP: If your application needs to use ExtensionAbilities, develop multiple HAPs (one entry HAP and one or more feature HAPs) for it, with each HAP containing one UIAbility or one ExtensionAbility. In this scenario, multiple HAPs reference the same library file, which may cause repeated packaging.


## Constraints

- APIs and ArkUI components cannot be exported from the HAP to other modules.

- In an App Pack that contains multiple HAPs, each type of device supports zero or one entry HAP and zero, one, or more feature HAPs.

- If an application has multiple HAPs, the HAP consistency verification is performed during installation or update. For details, see [Consistency Verification for Application Installation and Update](multi_module_installation_update_consistency_verification.md). When a packing tool is used to package an App Pack, validity verification is performed. For details, see [Packing Tool](../../application-dev/tools/packing-tool.md#app-packing-command).

- If an application has multiple HAPs, the signing certificates of all HAPs and HSPs of this application must be the same. Applications are released to the AppGallery in the form of App Pack after being signed. Before distribution, the AppGallery splits an App Pack into HAPs and resigns them to ensure the consistency of HAP signing certificates. In the debugging phase, ensure that all HAP signing certificates are the same when you install HAP on the device using the CLI or DevEco Studio. Otherwise, the installation may fail. For details about the signing operations, see [Configuring a Debug Signature](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing).

## Creating a HAP

To create a HAP in DevEco Studio:

1. Create a project to build the first ArkTS application.
2. Right-click the project directory and choose **New** > **Module** from the shortcut menu.
3. In the dialog box displayed, select **Empty Ability** as the template and click **Next**.
   
4. On the module configuration page, set **Module name**, **Module Type**, and **Device Type**, and click **Next**.

5. On the ability configuration page, set **Ability name** and click **Finish**.

## Developing a HAP

- You can add a UIAbility, an ExtensionAbility, or a page to a HAP. For details, see [Adding an Ability to a Module](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-add-new-ability) and [Adding a Page](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-add-page).

- You can also configure a HAP to reference a HAR or HSP. For details, see [Using a HAR](./har-package.md#using-a-har) and [Using an HSP](./in-app-hsp.md#using-an-hsp).

## Debugging a HAP

After building code into one or more HAPs and installing or updating these HAPs, you can debug them. For details about how to compile the same HAP into different versions based on the deployment environment, target user group, and running environment, see [Customizing Multi-Target Builds](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-customized-multi-targets-and-products-guides#section1011341611469).

To debug a HAP, use either of the following tools:

- **Method 1**: Use DevEco Studio for debugging. For details, see [Running/Debugging Configuration](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-run-debug-configurations).

- **Method 2**: Use [hdc](../dfx/hdc.md) for debugging.

   Before debugging a HAP, install or update it using either of the methods:

   - Use hdc to install and update the HAP.

      When specifying the HAP, use the path to it on the operating system. In the following example, the operating system is Windows:

      ```shell
      # Install and update. Multiple file paths can be specified for multiple HAPs.
      hdc install entry.hap feature.hap
      # Review the execution result.
      install bundle successfully.
      # Uninstall.
      hdc uninstall com.example.myapplication
      # Review the execution result.
      uninstall bundle successfully.
      ```

   - Run the **hdc shell** command, and then use the Bundle Manager (bm) tool to install and update the HAP.

      When specifying the HAP, use the path to it on the real device. The sample code is as follows:

      ```shell
      # Run the hdc shell command before using the bm tool.
      hdc shell
      # Install and update. Multiple file paths can be specified for multiple HAPs.
      bm install -p /data/app/entry.hap /data/app/feature.hap
      # Review the execution result.
      install bundle successfully.
      # Uninstall.
      bm uninstall -n com.example.myapplication
      # Review the execution result.
      uninstall bundle successfully.
      ```

   After the HAP is installed or updated, you can debug it using the [attach](../tools/aa-tool.md#attach) command.

<!--RP4-->
<!--RP4End-->
