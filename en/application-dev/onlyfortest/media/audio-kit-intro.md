# Delete a tag.

 **1. Delete the link and link content.** 

Components that support the drag-out capability by default (data can be dragged from components): Search, TextInput, TextArea, RichEditor, Text, Image, <!--Del-->[FormComponent](), and UIExtensionComponent<!--DelEnd-->Hyperlink

Sets the number of preloaded ListItems/ListItemGroups in a list. This parameter takes effect only in LazyForEach. ListItemGroup is calculated as a whole, and all ListItems in ListItemGroup are loaded at a time. <!--Del-->For details, see [Description of Reducing Application White Blocks] (). <!--DelEnd-->

 **2. Delete a paragraph (mainly the list)** 

One:
<!--Del-->
- External storage directory
- Docs Directory<!--DelEnd-->
- Download directory
- Desktop directory
- Documents directory
- Share shared disk directory

Two:
- Card provider: provides applications for card display content and controls card display content, control layout, and control click events.
- Card management service: It is used to manage the resident agent service of cards added in the management system. It provides the interface capabilities of formProvider and formHost, manages and uses card objects, and periodically refreshes cards. <!--Del-->
- Card rendering service: manages card rendering instances. Render instances are bound to card components on the card user. The card rendering service runs the card page code widgets.abc for rendering, and sends the rendered data to the card component corresponding to the card user. <!--DelEnd-->

Three:
3. (Verify whether the sequence numbers can be properly combined after deletion.)
1. Use the DocumentViewPicker interface to select or save a file. The URI of the selected or saved file is returned. <!--Del-->
2. Use the AudioViewPicker interface to select or save a file. The URI of the selected or saved file is returned. <!--DelEnd-->
3. Use the PhotoViewPicker.save interface to save the file and return the URI of the saved file.

**3. Delete section and subsection** 

<!--Del-->
## Create a user album (open to system applications only).

Create a user album through the MediaAlbumChangeRequest.createAlbumRequest and PhotoAccessHelper.applyChanges interfaces.

The specifications of the name of the album to be created are as follows:

- The album name contains 1 to 255 characters.
- Invalid English characters, including <br>.\ /: *? "'`< > | {} []
- English characters are case insensitive.
- The album name must be unique.

**Prerequisites**

- Obtains the photoAccessHelper instance of the album management module.
- Apply for the album management module permission'ohos.permission.WRITE_IMAGEVIDEO'.

The following describes how to create a user album.
<!--DelEnd-->

 **4. Table** 

One:
<!--Del-->
| Task | Introduction | Related Guidance |
| -------- | -------- | -------- |
| Application Component Development | This section describes how to use the UIAbility and ExtensionAbility components of the Stage model to develop applications. | Component Startup Rule |
| Understand the process model. | This section describes the process model of the stage model and several common inter-process communication modes. | Process Model Overview |
| Understand the thread model. | This section describes the thread model of the stage model and several common inter-thread communication modes. | Thread Model Overview |
<!--DelEnd-->

Two:
| Task | Introduction | Related Guidance |
| -------- | -------- | -------- |
| <!--DelRow-->Application Component Development | This section describes how to use the UIAbility and ExtensionAbility components of the stage model to develop applications. | Component Startup Rule |
| Understand the process model. | This section describes the process model of the stage model and several common inter-process communication modes. | Process Model Overview |
| Understand the thread model. | This section describes the thread model of the stage model and several common inter-thread communication modes. | Thread Model Overview |

Three:
| Task | <!--DelCol2-->Introduction | Related Instructions |
| -------- | -------- | -------- |
| Application Component Development | This section describes how to use the UIAbility and ExtensionAbility components of the Stage model to develop applications. | Component Startup Rule |
| Understand the process model. | This section describes the process model of the stage model and several common inter-process communication modes. | Process Model Overview |
| Understand the thread model. | This section describes the thread model of the stage model and several common inter-thread communication modes. | Thread Model Overview |

Four:
| Algorithm | Supported Key Length | API Level | <!--DelCol4--> Mandatory Specification |
| -------- | -------- | -------- | -------- |
| AES | 128, 192, 256 | 8 + | Yes |<!--Del-->
| RSA | 512, 768, 1024 | 8 + | No |<!--DelEnd-->
| RSA | 2048, 3072, 4096 | 8 + | Yes |
| HMAC | 8 to 1024 (inclusive). The value must be a multiple of 8. | 8 + | Yes |<!--Del-->
| ECC | 224 | 8+ | No |<!--DelEnd-->
| SM4 | 128 | 9+ | Yes |

 **5. Description** 

> **NOTE:**
>
> Description First line
>
> <!--Del-->Describe the second line<!--DelEnd-->
>
> Description 3rd line
>
> <!--Del-->Description 4th line <!--DelEnd-->

**6、website**
- [postCardAction]()
    <!--Del-->
    - [@ohos.arkui.drawableDescriptor (DrawableDescriptor)]()
    - [@ohos.arkui.performanceMonitor ]()  
    - [@ohos.arkui.uiExtension (uiExtension)]()
    <!--DelEnd-->
    - [@ohos.deviceStatus.dragInteraction]()
    - [@ohos.pluginComponent (PluginComponentManager)]()
    - [@ohos.uiAppearance]()
    - [@ohos.uiExtensionHost]()