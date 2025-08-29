# Creating an Application Clone
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

Application clone supports users to install multiple identical applications on one device, allowing several accounts to log into and run the applications at the same time without affecting each other. When users log in with two different accounts to a social media or a game application simultaneously, they do not have to switch accounts, reducing frequent logins.

After an application is cloned, multiple applications with the same icon are displayed on the home screen. An application with a lower corner mark is a cloned application.

Relationship between the main application and the cloned application:
- These two applications share the same program. For example, when the main application is updated, the cloned one is synchronously updated, including icon, label, and new features.
- Both applications are independent of each other in terms of feature enabling, related configurations, and data.
- When the main application is uninstalled, all cloned applications will also be uninstalled. However, uninstalling a cloned application does not affect the main application.

The following figure shows the effect of cloned applications.

![Figure 1](figures/app-clone1.png)

## Constraints
The input method application cannot create an application clone.

## How to Develop

1.  Configure the [multiAppMode](app-configuration-file.md#multiappmode) field in the **AppScope/application.json5** configuration file in the project. The code snippet is as follows:
    ```json
    {
      "app": {
        "multiAppMode": {
          "multiAppModeType": "appClone",
          "maxCount": 2
        }
      }
    }
    ```

2. Clone an application.

    - Build and package the configured project and install it on the device.

      ![Figure 2](figures/app-clone4.png)

    - Choose **Settings** > **System** > **App Clone**, and tap **Create**.

      ![Figure 3](figures/app-clone5.png)

      ![Figure 4](figures/app-clone3.png)

    - Return to the home screen and check whether the application is cloned.

      ![Figure 1](figures/app-clone1.png)

      The three cloned applications in the figure are independent of each other in terms of running, data, and notification.
