# Using the Project Wizard to Create a Project<a name="EN-US_TOPIC_0000001176969367"></a>

-   [Prerequisites](#section13642104391619)
-   [Procedure](#section132671712101714)

If you are using DevEco Studio 2.2 Beta1 or later, you can use the project wizard to create a project. If you are using DevEco Studio 2.1 Release, create a project by following instructions in  [Importing a Sample to Create a Project](import-sample-to-create-project.md).

## Prerequisites<a name="section13642104391619"></a>

The OpenHarmony SDK has been installed. For details, see  [Configuring the OpenHarmony SDK](configuring-openharmony-sdk.md).

## Procedure<a name="section132671712101714"></a>

1.  Open the project wizard using either of the following methods:
    -   If no project is open, select  **Create Project**  on the welcome page.
    -   If a project is already open, choose  **File**  \>  **New**  \>  **New Project**  on the menu bar.

2.  Select the  **\[Standard\]Empty Ability**  template and click  **Next**.

    ![](figures/en-us_image_0000001162463400.png)

3.  Click  **Next**  and configure the project.
    -   **Project name**: customized project name.
    -   **Project type**: project type, which can be an  [atomic service](https://developer.harmonyos.com/en/docs/documentation/doc-guides/atomic-service-definition-0000001090840664)  or an ordinary app that requires download before use.

        >![](../public_sys-resources/icon-note.gif) **NOTE:** 
        >If you're creating an atomic service:
        >-   There is no app icon on the home screen while running or debugging an atomic service. Use the debugging and running functions of DevEco Studio as an alternative.
        >-   Atomic services are installation free. This is done by automatically adding the  **installationFree**  field to the  **config.json**  file, with its value set to  **true**.
        >-   If the value of the  **installationFree**  field of the entry module is set to  **true**, the value of the  **installationFree**  field of all the related HAP modules is  **true**  by default. If the** installationFree field**  of the entry module is set to  **false**, the  **installationFree**  field of all the related HAP modules can be set to  **true**  or  **false**.
        >-   When compiling and building an app, make sure that the size of each HAP package does not exceed 10 MB.

    -   **Bundle name**: bundle name. By default, this name will also be used as your app ID. Your app must have a unique ID to be released. If  **Project type**  is set to  **Atomic service**, the  **Bundle name**  must end with  **.hmservice**.
    -   **Save location**: local path for storing the project file.
    -   **Development mode**: development mode. The  **Super Visual**  option is available if the project template supports low-code development.
    -   **Language**: supported programming language.
    -   **Compatible API version**: earliest SDK version compatible with your app.

        >![](../public_sys-resources/icon-note.gif) **NOTE:** 
        >If  **compileSdkVersion 7**  or later is configured for the OpenHarmony project, the corresponding module will be compiled using ArkCompiler by default. To use a compiler other than ArkCompiler, add the  **arkEnable false**  field to the  **ohos**  closure in the module-level  **build.gradle**  file.

    -   **Device Type**: device type supported by the project template.

        ![](figures/en-us_image_0000001196050928.png)

4.  Click  **Finish**. DevEco Studio will automatically generate the sample code and resources that match your project type. Wait until the project is created.

