# Creating an Application Multi-Instance
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

Multi-instance allows an application to run on multiple pages so that a user can log in multiple accounts and run the application at the same time without affecting each other. For example, a user can run several social accounts, or primary and secondary game accounts simultaneously without frequent log-in and log-out.

Multiple application process pages on the home screen are independent in terms of the running, notification, and more. Instances share data with each other and can be switched using accounts.

Relationship between multiple application instances:
- The application icons of multiple instances are the same.
- Instances share data and can be switched using accounts.

## Constraints

Application multi-instance can run on only 2-in-1 devices.

## How to Develop
1. Configure the multi-instance.

    Configure the [multiAppMode](app-configuration-file.md#multiappmode) field in the **App/app.json5** configuration file in the project. The code snippet is as follows:
    ```json
    {
      "app": {
        //  ...
        "multiAppMode": {
          "multiAppModeType": "multiInstance",
          "maxCount": 5
        }
      }
    }
    ```

2. Create a multi-instance.

- Build and package the configured project and install it on the device.
- Right-click an application icon on the home screen to open an application process. Then right-click the application icon again and choose **Open**.
In this case, two application process pages of the same application are displayed on the home screen.
