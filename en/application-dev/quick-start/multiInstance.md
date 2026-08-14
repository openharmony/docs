# Creating an Application Multi-Instance

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @memghaiyang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e614db0ed9ef9e65ff9f340640f4a0fd5317e78d translatedAt=2026-08-13T09:06:52.863Z pushedAt=2026-08-13T14:10:42.488Z -->

Multi-instance allows an application to run on multiple processes so that a user can log in multiple accounts and run the application at the same time without affecting each other. For example, a user can run several social accounts, or primary and secondary game accounts simultaneously without frequent log-in and log-out.

Multiple application instances on the home screen are independent in terms of the running, notification, and more. Instances share data with each other and can be switched using accounts.

Relationship between multiple application instances:

- The application icons of multiple instances are the same.

- All instances share the file data in the [application file directory](../file-management/app-sandbox-directory.md#application-file-directory-and-application-file-path).

- You can switch between accounts. A single instance supports logging in with different accounts.

## Constraints

Application multi-instance can run on only 2-in-1 devices.

## How to Develop

1. Configure the multi-instance.

    Configure the [multiAppMode](app-configuration-file.md#multiappmode) field in the **App/app.json5** configuration file in the project. The code snippet is as follows:

    <!-- @[multi_instance](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/bmsSample/Multiinstance/AppScope/app.json5)  -->

    ``` JSON5
    {
      "app": {
        // ...
        "multiAppMode": {
          "multiAppModeType": "multiInstance",
          "maxCount": 5
        }
      }
    }
    ```

2. Create a multi-instance.

- Build and package the configured project and install it on the device.

- Right-click an application icon on the home screen to open an application process. Then right-click the application icon again and choose **Open**. In this case, two application process pages of the same application are displayed on the home screen.