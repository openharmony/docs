# Creating a Project and Obtaining Source Code


When creating an OpenHarmony project, DevEco Device Tool automatically downloads the source code in one of the supported types.

Source code of an OpenHarmony stable version is downloaded from a mirror site. The following versions are available: OpenHarmony-v3.0.3-LTS, OpenHarmony-v3.1-Release, OpenHarmony-v3.2-Beta3, OpenHarmony-v3.2-Beta4, OpenHarmony-v3.2-Beta5, and OpenHarmony-v3.2-Release.

The source code from a mirror site is generally what's available when the stable version is released. Therefore, it may be out of date. To acquire the latest source code of a version, follow the instructions in [Acquiring Source Code from the Gitee Code Repository](../get-code/sourcecode-acquire.md). After acquiring the source code, import it to DevEco Device Tool by following the instructions in [Importing OpenHarmony Source Code](https://device.harmonyos.com/en/docs/documentation/guide/open_project-0000001071680043).

The following describes how to download source code of the **OpenHarmony Stable Version** type. For details about how to download source code of other types, see [HUAWEI DevEco Device Tool User Guide](https://device.harmonyos.com/en/docs/documentation/guide/service_introduction-0000001050166905).


## Prerequisites

A remote connection from the Windows environment to the Ubuntu environment has been set up through Remote SSH. For details, see [Setting Up the Development Environment](quickstart-ide-env-win.md).

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> If a remote connection from Windows to Ubuntu is not available, the **New Project** function is restricted to HiSilicon enterprise users.


## Procedure

1. Open DevEco Device Tool, go to the home page, and click **New Project**.

   ![en-us_image_0000001272258726](figures/en-us_image_0000001272258726.png)

2. On the project configuration wizard page, configure the project settings.
   - **OpenHarmony Source Code**: OpenHarmony version of the source code to download. Select a version under **OpenHarmony Stable Version**, such as OpenHarmony-v3.0.3-LTS, OpenHarmony-v3.1-Release, OpenHarmony-v3.2-Beta3, OpenHarmony-v3.2-Beta4, OpenHarmony-v3.2-Beta5, and OpenHarmony-v3.2-Release.
   - **Project Name**: project name.
   - **Project Path**: path for storing the project files.
   - **SOC**: supported SoC.
   - **Board**: development board.
   - **Product**: supported product.

   ![en-us_image_0000001338187673](figures/en-us_image_0000001338187673.png)

3. Click **Confirm** to save the settings. DevEco Device Tool automatically starts to download the OpenHarmony source code. Considering the large size of the source package, the download process may take some time.

   ![en-us_image_0000001338536201](figures/en-us_image_0000001338536201.png)
