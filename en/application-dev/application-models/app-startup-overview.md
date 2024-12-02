# Overview of Starting a Specified Application

This section describes how to start a specified application in linking mode.

> **NOTE**
> 
> Since API version 12, third-party applications cannot start other applications by specifying an ability (implicit Want mode). For details about how to switch from the implicit Want mode to the linking mode, see [Switching from Explicit Want Redirection to Linking Redirection](uiability-startup-adjust.md).


## Application Links

An application link is a URL that can direct users to a specific location in an application or a web page. For details about the link format and field meanings, see [Application Link Description](app-uri-config.md). The common format is as follows:

```
scheme://host[:port]/path
```


## Working Principles

1. The target application registers its URL in the configuration file and provides the URL for external systems.
2. The caller application passes in information such as the URL of the target application to the redirection APIs.
3. After receiving the information such as the URL, the system searches for the matching application and redirects to the target application.


## Linking Category

There are two types of linking: Deep Linking and App Linking, which vary in the scheme configuration and verification mechanism.

- Deep Linking enables users to jump to a specific page of an application through a link. It allows developers to define schemes in any form. The target applications are easy to be spoofed since there is no domain name verification.

- App Linking stipulates that the scheme must be https and adopts domain name verification to further filter the target application.


Compared with Deep Linking, App Linking has higher security, reliability, and user experience. Therefore, App Linking is recommended.

| Item| App Linking (Recommended)| Deep Linking |
| -------- | -------- |-------- |
| Implementation| The target application must declare its link in the **module.json5** file. It must also register a domain name with the system and pass domain name authentication.|  The target application must declare its link in the **module.json5** file.|
| Format| The value of **scheme** must be **https**.| **scheme** can be customized. Generally, it cannot be **https**, **http**, or **file**. Otherwise, the default system browser is started.|
| Capable of sharing or directly accessible on web pages| Yes| No. The function must be called in the code.|
| Able to directly start the target application| Yes| Yes. However, this mode is not recommended due to spoofing risks.|

Both Deep Linking and App Linking can be implemented using [openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12). The redirection effect under different conditions is as follows:

> **NOTE**
> 
> The **appLinkingOnly** field in the API specifies whether to start the UIAbility in App Linking mode. The default value is **false**. Generally, **appLinkingOnly** is set to **true** for browser applications.


| Scenario| App Linking (Recommended)| Deep Linking |
| -------- | -------- |-------- |
| The value of **appLinkingOnly** is **false** and the target application is installed.| Directly redirect to and start the target application.| Redirect to the target application. (If there are multiple applications that meet the conditions, a dialog box for selecting an application is displayed.)|
| The value of **appLinkingOnly** is **false** and the target application is not installed.| Redirect to the default browser to open a web page.|A failure message is returned, no redirection is performed, and the application is responsible for handling the request. Currently, a dialog box is displayed, indicating that the link cannot be opened.|
| The value of **appLinkingOnly** is **true** and the target application is installed.| Directly redirect to and start the target application.|A failure message is returned, no redirection is performed, and the application is responsible for handling the request.|
| The value of **appLinkingOnly** is **true** and the target application is not installed.| A failure message is returned, no redirection is performed, and the application is responsible for handling the request.| A failure message is returned, no redirection is performed, and the application is responsible for handling the request.|
