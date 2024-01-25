# Access Control Overview


Applications can access limited system resources by default. However, to provide extended features, an application may need to access excess system data (or personal data) or functions. The system must also provide explicit APIs to share data or functions.

To prevent improper or malicious use of data or functions, the system provides a variety of access control mechanisms, including the application sandbox, application permissions, and system components.


## Application Sandbox

All applications running on the system are deployed in independent sandbox directories, which isolate the data of different applications and prevent improper application behavior, such as unauthorized data access between applications and device tampering. Each application has a unique ID ([TokenID](app-permission-mgmt-overview.md#tokenid)), which can be used to identify the application and restrict its access behavior.

The application sandbox directory specifies the data range visible to an application. For details, see [Application Sandbox](../../file-management/app-sandbox-directory.md).


## Application Permissions

The system sets process domain and data domain labels based on the [Ability Privilege Level (APL)](app-permission-mgmt-overview.md#apl) of each application, and uses the access control mechanism to restrict the data accessible to each application.

Applications of different APLs can apply for different levels of permissions, and different system resources (such as the Contacts) or system capabilities (such as the capability for accessing a camera or a microphone) are protected by different application permissions. Strict hierarchical permission protection effectively defends against malicious attacks and ensures system security and reliability.

For more information, see [Application Permission Management Overview](app-permission-mgmt-overview.md).


## System Components

The system also provides temporary authorization methods, such as system Pickers and security components, to allow applications to temporarily access restricted resources without applying for permissions from users. These easy-to-use components implement precise permission control and better protect user privacy.

- [System Pickers](use-picker.md)

  A Picker is implemented by an independent system process. It provides a safe, built-in way for users to grant your application access to only selected resources. By starting a Picker component, the application can access the resources, such as an image or a document, selected by the user using the Picker. For example, before accessing a user's image, an application normally needs to request user authorization. However, by using **PhotoViewPicker**, the application can directly access the image selected by the user.

  Currently, the system provides the following Pickers: [AudioViewPicker](use-picker.md#audioviewpicker), [PhotoViewPicker](use-picker.md#photoviewpicker), [DocumentViewPicker](use-picker.md#documentviewpicker), and [Contacts Picker](use-picker.md#contacts-picker).

- [Security components](security-component-overview.md)

  Security components are a set of button-like ArkUI components provided with certain permissions. You can integrate them to your application UI. When a security component is tapped, the application is temporarily granted with the related permission. For example, you can use the \<**LocationButton**> component for the application that needs to share location information. When this component is tapped by a user, the application is temporarily authorized with the precise location permission and can call the location service to obtain the precise location. <br>The permission, however, is temporarily granted to the application and is automatically revoked when the screen is turned off or the application switches to the background or exits.

  Currently, the following security components are available: [<**PasteButton**>](pastebutton.md), [<**SaveButton**>](savebutton.md), and [<**LocationButton**>](locationbutton.md).

