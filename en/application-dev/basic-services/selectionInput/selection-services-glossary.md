# Selection Service Terminology

<!--Kit: Basic Services Kit-->
<!--Subsystem: SelectionInput-->
<!--Owner: @no86-->
<!--Designer: @mmwwbb-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=ca6c65f8737127ab246f15bde19a1474d8a76b90 translatedAt=2026-07-28T07:31:47.717Z pushedAt=2026-07-30T12:29:34.186Z -->

## S

### Selected Application

The source app where text is selected by the user. The selection service extracts the selected text from it through the system copy mechanism, requiring no additional adaptation by the app. Apps that do not support system-level copying (such as controlled WebViews or sandboxed apps) cannot work with this feature.

### Selection Application

An app that implements the Selection ExtensionAbility. After being launched by the selection service, this type of app can listen for the selection completion event to obtain the text selected by the user, and then execute subsequent business logic such as translation, summarization, and expansion.

### Selection ExtensionAbility

A type of ExtensionAbility component. It allows an app to obtain the selected text after the user makes a selection and manages the lifecycle of the selection panel, thereby facilitating the implementation of business logic such as translation, summarization, and expansion.