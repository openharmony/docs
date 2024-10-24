# Overview of Application Redirection

Application redirection enables users to jump from one application to another to transfer data or perform a specific action. It improves the convenience and smoothness of interaction.


## Two Types of Application Redirection

Application redirection can be categorized as follows based on whether the target application is specified:

- Starting the specified application: The caller application specifies the target application by specifying either an application link and an ability.

    - Specifying an application link (recommended): Use [openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12) or [startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability) to specify an [application link](#application-links) and start the target application page.

    - Specifying an ability (not recommended): Use [startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability) to specify an ability and explicitly start the target application page.

    > **NOTE**
    >
    > In API version 11 and earlier versions, you can use explicit Want to start other applications. Since API version 12, third-party applications cannot use explicit Want to start other applications.

- Starting an application of the specified type: The caller application starts a vertical domain panel that meets the user intent based on the business category (specified by the **type** or **feature** field). The panel displays all the vertical applications that can handle the intent, and users can choose to open one of them.

    Typical scenarios are navigation, sharing, and file opening. Redirection can be implemented in multiple modes based on the intent type.

    - [Navigation](start-intent-panel.md): supports navigation, location search, and route planning.
    - [File Opening](file-processing-apps-startup.md): opens a file of a specific type.<!--RP1-->
    <!--RP1End-->

## Application Links

### Basic URL Format

An application link is a URL that can direct users to a specific location in an application or a web page. The basic format of the URL is as follows:
```
scheme://host[:port]/path/
```

- **scheme**: scheme name, for example, http and https.
- **host**: domain name or IP address, for example, developer.huawei.com or 127.0.0.1.
- **port**: port number, for example, 80 in developer.huawei.com:80.
- **path**: directory or file path on the DNS, for example, consumer in developer.huawei.com/consumer/.

> **NOTE**
> 
> The scheme of a third-party application cannot be the same as that of a system application. Otherwise, the third-party application cannot be started using the URI.
> 
> If multiple applications are configured with the same URLs, these applications will be matched during application redirection, and a dialog box will be displayed for uses to select. For better user experience, you can use the **path** field to distinguish the application to start. For example, use **https://www.example.com/path1** to start target application 1 and use **https://www.example.com/path2** to start target application 2.

### Working Principles of Application Link Redirection

1. The target application registers its URL in the configuration file and provides the URL for external systems.
2. The caller application passes in information such as the URL of the target application to the redirection APIs.
3. After receiving the information such as the URL, the system searches for the matching application and redirects to the target application.


### Comparison Between Deep Linking and App Linking

Deep Linking enables users to jump to a specific page of an application through a link. It allows developers to define schemes in any form.

App Linking, as a specific type of Deep Linking, stipulates that the scheme must be https and adopts domain name verification to further filter the target application.

Compared with Deep Linking, App Linking has higher security, reliability, and user experience. Therefore, App Linking is recommended.

| Type| Deep Linking | App Linking |
| -------- | -------- |-------- |
| Implementation effect| - If the target application has been installed, it is started directly.<br> - If the target application is not installed, error code 16000019 is displayed.| - If the target application has been installed, it is started directly.<br> - If the target application is not installed, a browser page is opened.|
| Constraints| - The scheme in the URL can be customized.<br> - Domain name verification is not required.| - The scheme in the URL must be https.<br> - Domain name verification must be carried out on the cloud server.|
| Security| The target applications are easy to be spoofed since there is no domain name verification.| Domain name verification ensures reliable redirection to the target applications.|

## Typical Scenario: Starting a System Application

Starting a system application is a typical scenario of application redirection. The system provides some capabilities and interfaces for you to quickly implement system application redirection while ensuring access security. For details, see [Starting a System Application](system-app-startup.md).
