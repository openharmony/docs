# Multi-HAP Development, Debugging, Release, and Deployment Process

Below is the process of developing, debugging, releasing, and deploying multiple HAP files.

**Figure 1** Process of developing, debugging, releasing, and deploying multiple HAP files
![hap-release](figures/hap-release.png)

## Development
You can use [DevEco Studio](https://developer.harmonyos.com/en/develop/deveco-studio) to create multiple modules as needed and develop services in respective modules.

## Debugging
After building code into one or more HAP files and installing or updating these HAP files, you can debug them. You can leverage a single set of code and files to build multiple target editions for different audiences, deployment environments, operating environments, and more. For details, see [Customizing Multi-Target and Multi-Product Builds](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/customized-multi-targets-and-products-0000001430013853-V3?catalogVersion=V3).

You can debug HAP files using the methods:
* Using DevEco Studio for debugging

   Follow the instructions in [Debugging Configuration](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-debugging-and-running-0000001263040487#section10491183521520).

* Using [hdc](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md) (which can be obtained in the **toolchains** directory of the OpenHarmony SDK) for debugging
   
   Before debugging HAP files, install or update them using either of the methods:

 1. Use hdc to install and update the HAP files.

    When specifying the HAP files, use the paths of the files on the operating system, for example, Windows.

    ```
    // Installation and update: Multiple file paths can be specified.
    hdc install C:\entry.hap C:\feature.hap
    // The execution result is as follows:
    install bundle successfully.
    // Uninstall
    hdc uninstall com.example.myapplication
    // The execution result is as follows:
    uninstall bundle successfully.
    ```
 
 2. Run the hdc shell command, and then use the Bundle Manager (bm) tool to install and update the HAP files.

    When specifying the HAP files, use the paths of the files on the real device. The sample code is as follows:
    
    ```
    // Run the hdc shell command before using the bm tool.
    hdc shell
    // Installation and update: Multiple file paths can be specified.
    bm install -p /data/app/entry.hap /data/app/feature.hap
    // The execution result is as follows:
    install bundle successfully.
    // Uninstall
    bm uninstall -n com.example.myapplication
    // The execution result is as follows:
    uninstall bundle successfully.
    ```
    After the HAP files are installed or updated, you can debug them by following the instructions in [Ability Assistant](../tools/aa-tool.md).

## Release
When your application package meets the release requirements, you can package and build it into an App Pack and release it to the application market on the cloud. The application market verifies the signature of the App Pack. If the signature verification is successful, the application market obtains the HAP files from the App Pack, signs them, and distributes the signed HAP files.

## Deployment
The application market on the cloud distributes the applications to application market clients. These applications can contain one or more HAP files. After the user selects an application to download, the application market downloads all the HAP files contained in this application.

## Installation on a Device
After the download is complete, the application market client calls the installation API of the bundle manager service in the system to install the downloaded HAP files. The bundle manager service deploys HAP files by application in the specified directory to complete the application installation.
