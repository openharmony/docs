# IDE Usage

## What should I do if the error message "npm ERR! code SELF_SIGNED_CERT_IN_CHAIN" is displayed?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

1. Run **npm config set strict-ssl=false** on the DevEco Studio terminal.

2. Run **npm install** on the DevEco Studio terminal.

## After manual updating of a DevEco Studio SDK, the error message "Cannot find module 'xxx\ets\x.x.x.x\build-tools\ArkTS-loader\node_modules\webpack\bin\webpack.js'" is displayed during HAP building. What should I do?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

1. Run **npm install** in the **ets\x.x.x.x\build-tools\ets-loader** directory of the SDK.

2. Run **npm install** in the **js\x.x.x.x\build-tools\ace-loader** directory of the SDK. Perform HAP building again.

## How do I pack a HAP file through the command line?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Method 1: Run **hvigor assembleHap**.

Method 2: In **scripts** of the project **package.json** file, define the build task script and run **npm buildOhosHaps**. The **buildOhosHaps** field can be customized.


```
"scripts": {
  "buildOhosHaps": "hvigor assembleHap"
},
```

## How do I select API version 9 when creating a project in DevEco Studio?

Applicable to: DevEco Studio 3.0 Beta4 3.0.0.993(B06)

When creating a project in DevEco Studio, make sure you are on the **OpenHarmony** tab page.

## What should I do if no callback is received and no error code is returned for downloads?

Applicable to: all versions

1. Re-install hdc_std and set up the device connection again.
2. Run **hdc_std shell hilog -Q pidoff** to disable log log flow control.

## What should I do if the "error: unknow option. usage: aa start \<options>" message is displayed after I click Run in DevEco Studio?

Applicable to: OpenHarmony SDK 3.2.5.6, stage model of API version 9

This issue occurs when the parameter in the **aa** command is invalid and therefore the target application fails to be opened.

To fix this issue, use either of the following methods:

1. Make sure the SDK version and the OS version are the same.

2. Touch the application icon on the device to manually open the application.

## What should I do if "The hdc_std version of the SDK does not match the hdcd version of the device." message is displayed when I run an application in DevEco Studio?

Applicable to: OpenHarmony SDK 3.2.5.6, stage model of API version 9

This issue occurs when the hdc and hdcd versions do not match. Update Dev Eco Studio to 3.0.1.993 or later.

After the update, Dev Eco Studio will still indicate the version mismatch, but will not block the running.

## How do I add a custom .d.ts file to the OpenHarmony SDK?

Applicable to: OpenHarmony SDK 3.1.7.7, FA model of API version 8

Name the .d.ts file **@ohos.xxxx.d.ts**, save it to the SDK path, and restart Dev Eco Studio.

A code notification is displayed when the file is imported.

## How do I switch to the full SDK?

Applicable to: OpenHarmony SDK 3.2.7.5

Follow the instructions in [Guide to Switching to Full SDK](../quick-start/full-sdk-switch-guide.md).
