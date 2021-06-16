# Importing an OpenHarmony Project<a name="EN-US_TOPIC_0000001163914943"></a>

After the OpenHarmony SDK is configured, you can start developing your app only by  **importing a sample project**  to begin with.

Sample projects for OpenHarmony app development are supported. Import a sample project with the following description:  **This sample is intended for novices at developing OpenHarmony applications.**. For example, the  **JsHelloWorld**  sample in the  **common**  category.

![](figures/en-us_image_0000001165463605.png)

1.  On the DevEco Studio welcome page, go to  **Configure**  \(or  ![](figures/en-us_image_0000001118018452.png)  icon\) \>  **Settings**  \>  **Version Control**  \>  **Git**  and click  **Test**  to check whether the Git tool is installed.
    -   If the tool has been installed, import a sample by referring to  [2](#li5947194711181).

        ![](figures/en-us_image_0000001118018088.png)

    -   If the tool hasn't been installed, click  **Download and Install**. DevEco Studio will automatically download and install it. Then import a sample by referring to  [2](#li5947194711181).

        ![](figures/en-us_image_0000001164498191.png)


2.  <a name="li5947194711181"></a>On the DevEco Studio welcome page, click  **Import HarmonyOS Sample**  to import a sample project.

    ![](figures/en-us_image_0000001163835551.png)

3.  Go to  **common**  \>  **JsHelloWorld**  \>  **Next**.

    ![](figures/en-us_image_0000001118201202.png)

4.  Configure  **App Name**  and  **Project Location**  and click  **Finish**. Wait until the sample project is imported.

    ![](figures/en-us_image_0000001163915521.png)

5.  Open the  **build.gradle**  file in the project and change the version number of the HAP plugin to  **2.4.4.3-RC**.

    ![](figures/en-us_image_0000001117475776.png)

6.  Click  ![](figures/en-us_image_0000001163835553.png)  under  **Gradle**  in the upper right corner to sync the project again.

    ![](figures/en-us_image_0000001117635680.png)

7.  When the project is successfully synced, you can develop your OpenHarmony app.

    ![](figures/en-us_image_0000001163915523.png)


