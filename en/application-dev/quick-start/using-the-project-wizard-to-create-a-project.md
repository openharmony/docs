# Using the Project Wizard to Create a Project<a name="EN-US_TOPIC_0000001176969367"></a>

-   [Prerequisites](#section13642104391619)
-   [Procedure](#section132671712101714)

If you are using DevEco Studio 2.2 Beta1 or later, you can use the project wizard to create a project. If you are using DevEco Studio 2.1 Release, create a project by following instructions in  [Importing a Sample to Create a Project](importing-a-sample-to-create-a-project.md).

## Prerequisites<a name="section13642104391619"></a>

The OpenHarmony SDK has been installed. For details, see  [Configuring the OpenHarmony SDK](configuring-the-openharmony-sdk.md).

## Procedure<a name="section132671712101714"></a>

1.  Open the project wizard using either of the following methods:
    -   If no project is open, select  **Create HarmonyOS Project**  on the welcome page.
    -   If a project is already open, choose  **File**  \>  **New**  \>  **New Project**  on the menu bar.

2.  Select the  **\[Standard\]Empty Ability\(JS\)**  template and click  **Next**.

    ![](figures/en-us_image_0000001177051523.png)

3.  Click  **Next**  and configure the project.
    -   **Project Name**: customized project name.
    -   **Project Type**: project type , which can be an  [atomic service](https://developer.harmonyos.com/en/docs/documentation/doc-guides/atomic-service-definition-0000001090840664)  or an ordinary app that requires download before use.

        >![](public_sys-resources/icon-note.gif) **NOTE:** 
        >If you're creating an atomic service:
        >-   There is no app icon on the home screen while running or debugging an atomic service. Use the debugging and running functions of DevEco Studio as an alternative.
        >-   Atomic services are installation free. This is done by automatically adding the  **installationFree**  field to the  **config.json**  file, with its value set to  **true**.
        >-   If the value of the  **installationFree**  field of the entry module is set to  **true**, the value of the  **installationFree**  field of all the related HAP modules is  **true**  by default. If the** installationFree field**  of the entry module is set to  **false**, the  **installationFree**  field of all the related HAP modules can be set to  **true**  or  **false**.
        >-   When compiling and building an app, make sure that the size of each HAP package does not exceed 10 MB.

    -   **Package Name**: software package name. By default, this name will also be used as your app ID. Assign a unique package name because your app must have a unique ID to be released.
    -   **Save Location**: local path for storing the project file.
    -   **Compatible API Version**: earliest SDK version compatible with your app.
    -   **Device Type**: device type supported by the project template.

        ![](figures/en-us_image_0000001130932554.png)

4.  Click  **Finish**. DevEco Studio will automatically generate the sample code and resources that match your project type. Wait until the project is created.

