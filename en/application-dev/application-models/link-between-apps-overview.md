# Overview of Application Redirection

Application redirection enables users to jump from one application to another to transfer data or perform a specific action. It improves the convenience and smoothness of user interactions.

## Use Cases
Application redirection is widely used in social media sharing and marketing promotions. Examples are as follows:

- **Social media sharing**: In social apps, sharing links like location details, food recommendations, shopping deals, or game invites allows for a quick redirection to the relevant navigation, food, shopping, or gaming applications through these links.
- **Marketing promotions**: On platforms like video applications, social media applications, and web browsers, embedding links to applications being promoted (presented as text, widgets, or videos) enables users to navigate directly to specific pages within the target application. Additionally, including these promotional links in SMS messages or emails allows users to access specific pages within the target application directly through the provided links.


## Two Types of Application Redirection


- [Starting a Specified Application](app-startup-overview.md): The caller application specifies the target application by specifying either an application link and an ability.

    > **NOTE**
    >
    > Since API version 12, it is not recommended that third-party applications start other applications by specifying an ability (implicit Want mode). For details about how to switch from the implicit Want mode to the [linking mode](app-startup-overview.md#application-links), see [Switching from Explicit Want Redirection to Linking Redirection](uiability-startup-adjust.md).

    - Specifying an application link (recommended): Use [openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#openlink12) or [startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability) to specify an [application link](app-startup-overview.md#application-links) and start the target application page.

    - Specifying an ability (not recommended): Use [startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability) to specify an ability and explicitly start the target application page. This is the explicit Want mode.


- [Starting an Application of the Specified Type](start-intent-panel.md): The caller application starts a vertical domain panel based on the specified application type. The panel displays all the vertical applications that can handle the intent, and users can choose to open one of them.


## Typical Scenario: Starting a System Application

Starting a system application is a typical scenario of application redirection. The system provides some capabilities and interfaces for you to quickly implement system application redirection while ensuring access security. For details, see [Starting a System Application](system-app-startup.md).
