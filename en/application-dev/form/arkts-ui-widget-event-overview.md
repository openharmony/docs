# Overview of ArkTS Widget Page Interaction

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=a08d450b4f575e3d4749ddeef9dd32275ec0a19e translatedAt=2026-08-03T02:24:44.767Z pushedAt=2026-08-03T06:40:57.541Z -->

ArkTS widgets provide page interaction capabilities, including page redirection between widgets and widget providers (such as applications), process startup of widget providers, and message transfer between widgets and widget providers. You can call [postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction-1) to implement a [dynamic widget](arkts-form-overview.md#dynamic-widget) and use [FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md) to implement page interaction of a [static widget](arkts-form-overview.md#static-widget). Both **postCardAction** and **FormLink** support router, message, and call events. The usage scenarios are as follows:

- [router event](arkts-ui-widget-event-router.md): used to redirect to a specified UIAbility, enabling the functionality of navigating from a widget to an internal application page after a widget is touched. For non-system applications, this redirection is limited to their own UIAbilities.

- [call event](arkts-ui-widget-event-call.md): used to launch a specified UIAbility to the background, after which the UIAbility can request the corresponding background continuous task to complete functionalities such as music playback.

- [message event](arkts-ui-widget-event-formextensionability.md): used to launch the [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md), which then notifies the application via the [onFormEvent](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonformevent) API callback, thereby fulfilling the functionality of passing messages to the application after a widget is touched.