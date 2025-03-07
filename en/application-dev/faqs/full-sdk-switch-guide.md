# Switching to Full SDK

Both the public SDK and full SDK are toolkits for application development. <br>The public SDK is intended for application developers and provided as standard in DevEco Studio. It does not contain system APIs – APIs required by system applications.

The full SDK is intended for original equipment manufacturers (OEMs) and provided separately. It contains system APIs.

The SDK of API version 8 provided in DevEco Studio is a public SDK. If your project depends on any system API, such as the **animator** component, **xcomponent** component, or APIs in **@ohos.app.ability.abilityManager.d.ts**, **@ohos.app.form.formInfo.d.ts**, or **@ohos.bluetooth.d.ts**, switch to the full SDK by performing the following steps.

> **NOTE**
>
> The screenshots in this document are for reference only.

## Downloading the Full SDK

Manually download the system-specific full SDK package from the mirror. For details, see [Release Notes](../../release-notes/OpenHarmony-v3.2-beta2.md).

## Checking the Local SDK Location

In this example, an ArkTS project is used. For a JS project, replace **ets** with **js**.


In DevEco Studio, choose **Tools** > **OpenHarmony SDK Manager** to check the location of the local SDK.

![](figures/en-us_image_0000001655128939.png)

![image-20220613160524053](figures/en-us_image_0000001655128998.png)


## Replacing the SDK

1. Make sure the downloaded SDK is a full SDK.

   a. Verify that the name of the downloaded file contains **sdk-full**.

   ![image-20220613220702504](figures/en-us_image_0000001655129232.png)

   b. Verify that the SDK contains system APIs, including the APIs in **@ohos.app.ability.abilityManager.d.ts**, **@ohos.app.form.formInfo.d.ts**, and **@ohos.bluetooth.d.ts**.

   Note: The criteria for identifying system APIs are subject to the official API documentation.

   

2. Replace the SDK. The following uses public-SDK-3.x.x.x for Windows as an example.

    

   a. Decompress the downloaded full SDK file: **ets-windows-3.x.x.x-Release.zip**

   ![image-20220613165018184](figures/en-us_image_0000001655129264.png)

   b. Replace the SDK files.

   Back up the local SDK files. (Copy and rename the version directory in the **ets** directory, or copy the entire **ets** directory to another local path.)

   Go to the obtained location of the local installed SDK and back up the files therein.

   ![image-20220613161352157](figures/en-us_image_0000001655129041.png)

   Note: The name of the backup version directory must be different from the value of the **version** field in the **oh-uni-package.json** file. In the example below, the name of the backup version directory is **3.1.6.6_backup**.

   ![image-20220613165018184](figures/en-us_image_0000001655129398.png)

   The configuration in the **oh-uni-package.json** file is as follows, where the value of **apiVersion** is subject to the API version of the SDK, and the value of **version** is subject to the version number in the SDK file.

   ```json
   {
     "apiVersion": "X",
     "displayName": "Ets",
     "meta": {
       "metaVersion": "3.0.0"
     },
     "path": "ets",
     "releaseType": "Release",
     "version": "3.x.x.x"
   }
   ```
   

   **Delete all files in the original SDK (3.x.x.x) directory.** Failure to do so may result in some files being unable to be overwritten.

   

   Copy the full SDK to the location of the local SDK.

   Copy all files in the **ets** directory in the full SDK to the **ets\3.x.x.x** directory in the location of the local SDK.

   Change the value of **version** in the **oh-uni-package.json** file to the current SDK version number.

   In the ***.x.x.x*\build-tools\ets-loader** directory, open the **cmd/powerShell** window and run the **npm install** command to download the **node_modules** dependency package.

   Verify the SDK version to switch to. The SDKs (4.x.x.x) using API version 10 or later contain the **node_modules** dependency. For these SDKs, you do not need to run the **npm install** command.

   ![image-20220613171111405](figures/en-us_image_0000001655129333.png)

   

   c. Check for system APIs.

   ![image-20220613213038104](figures/en-us_image_0000001655129372.png)

## Appendix: macOS Security Alarm Handling

After the SDK is switched to the full SDK in DevEco Studio on macOS, an alarm is generated when the Previewer is opened.

![alarm](figures/alarm.png)

To clear the alarm, perform the following steps:

1. Start the Terminal application.

2. In Terminal, run **sudo spctl -- master - disable**.

3. In **System Preferences**, choose **Security & Privacy**, click the **General** tab and select **Anywhere** under **Allow apps downloaded from**.

![alarmHand](figures/alarmHand.png)

Now, applications downloaded from third-party sources will not be blocked, meaning that you can open the Previewer. For security purposes, change the **Allow apps downloaded from** settings back to the original option when the Previewer is not in use.
