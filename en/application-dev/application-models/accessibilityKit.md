# Introduction to Accessibility Kit

Accessibility is about giving equal access to everyone so that they can access and use information equally and conveniently under any circumstances. It helps narrow the digital divide between people of different classes, regions, ages, and health status in terms of information understanding, information exchange, and information utilization, so that they can participate in social life more conveniently and enjoy the benefits of technological advances.

Accessibility Kit provides capabilities and APIs for you to develop your own extension services or adapt your application to extension services to deliver a better experience for users with disabilities or physical limitations. For example, you can develop a screen reader for users with vision impairments.

## Available Capabilities

1. Enables third-party applications to obtain the extension services list, check the enabled status of extension services, and send accessibility events.

2. Provides an extension service framework for extension services and allows third parties to develop their own extension services.

## Working Principles

Accessibility Kit provides a standard mechanism for exchanging information between applications and extension services. The extension service sends a query or operation request to AAMS through AAkit. AAMS then responds as requested and returns the result to the extension service.

![AccessibilityFramework](figures/AccessibilityFramework.png)

1. Accessibility application: extension service developed based on the accessibility extension service framework, for example, a screen reader application.
2. Tartget application: third-party application assisted by the accessibility app.
3. AccessibilityAbilityManagerService (AAMS): main service of the AccessibilityExtensionAbility framework, which is used to manage the lifecycle of accessibility apps and provide a bridge for information exchange between accessibility apps and target apps.
4. AccessibilityAbility (AAkit): ability that is used by the accessibility application to build an operating environment for the extension service ability and that provides interfaces for the accessibility application to query and operate the target application, including performing click/long press operations.
5. AccessibilitySystemAbilityClient (ASACkit): used by the target application to send accessibility events, such as content change events, to AAMS, and to respond to the instructions (such as performing click/long press operations) sent by the accessibility application through AAMS.
