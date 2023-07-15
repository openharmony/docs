# Application Development Overview

> **NOTE**
>
> You are reading documents of OpenHarmony 3.2 Release. Obtain the [compatible SDK](../release-notes/OpenHarmony-v3.2-release.md#version-mapping) during your application development.

The application development documents provide reference for you to develop applications using the APIs provided by OpenHarmony. They walk you through how to use JavaScript APIs to develop applications on the standard system.

The documents are carefully organized as follows:

## Getting Started

[Here](quick-start/start-overview.md) you can learn how to better prepare yourself for application development.

Browse the documents on the instructions for quickly building your first application and the basics about OpenHarmony applications.

Check out the development fundamentals, which comprise descriptions of the package structure configuration file for OpenHarmony applications and the instructions for use of resource files.

## Development

To facilitate your application development, we provide development guidelines for key features.

First thing first, familiarize yourself with the two cornerstone frameworks in OpenHarmony applications:

- Application framework: [Application Models](application-models/application-model-composition.md)
- UI framework: [UI Development](ui/arkui-overview.md)

All applications should be developed on top of these frameworks.

Then, equip yourself for developing the key features, with the following guidelines:

- [Web](web/web-component-overview.md)
- [Notification](notification/notification-overview.md)
- [Window Manager](windowmanager/window-overview.md)
- [WebGL](webgl/webgl-overview.md)
- [Media](media/media-application-overview.md)
- [Security](security/userauth-overview.md)
- [Connectivity](connectivity/ipc-rpc-overview.md)
- [Telephony Service](telephony/telephony-overview.md)
- [Data Management](database/data-mgmt-overview.md)
- [File Management](file-management/file-management-overview.md)
- [Task Management](task-management/background-task-overview.md)
- [Device Management](device/usb-overview.md)
- [Device Usage Statistics](device-usage-statistics/device-usage-statistics-overview.md)
- [DFX](dfx/hiappevent-guidelines.md)
- [Internationalization](internationalization/international-overview.md)
- [Application Test](application-test/arkxtest-guidelines.md)
- [IDL Specifications and User Guide](IDL/idl-guidelines.md)
- [Using Native APIs in Application Projects](napi/napi-guidelines.md)

## Tools

DevEco Studio is a high-performance integrated development environment (IDE) recommended for developing OpenHarmony applications.
[Here](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-deveco-studio-overview-0000001263280421) you can learn everything about DevEco Studio, including how to use this tool to create a project and sign, debug, and run an application.

## Hands-On Tutorials

To make you better understand how functions work together and jumpstart your application development projects, we provide stripped-down, real-world [samples](https://gitee.com/openharmony/applications_app_samples/blob/OpenHarmony-3.2-Release/README.md) and [codelabs](https://gitee.com/openharmony/codelabs).

## API References

API references encompass all components and APIs available in OpenHarmony, helping you use and integrate APIs more effectively.

They are organized as follows:

- [ArkTS API Reference](reference/apis/development-intro.md)
- [Component Reference (TypeScript-based Declarative Development Paradigm)](reference/arkui-ts/ts-components-summary.md)
- [Component Reference (JavaScript-compatible Web-like Development Paradigm- ArkUI.Full)](reference/arkui-js/Readme-EN.md)
- [Component Reference (JavaScript-compatible Web-like Development Paradigm- ArkUI.Lite)](reference/arkui-js-lite/Readme-EN.md)
- [JavaScript Service Widget UI Component Reference](reference/js-service-widget-ui/js-service-widget-file.md)
- Native API Reference
  - [Native APIs](reference/native-apis/_o_h___native_x_component.md)
  - [Standard Libraries](reference/native-lib/third_party_libc/musl.md)
  - [Node_API](reference/native-lib/third_party_napi/napi.md)
