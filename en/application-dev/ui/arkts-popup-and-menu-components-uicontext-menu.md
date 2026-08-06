# Global Menu Independent of UI Components (openMenu)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @H-xinwei-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

The [Menu](arkts-popup-and-menu-components-menu.md) component is a great option for creating menus, but it relies on a bound UI component to work. Since API version 18, however, the global API [openMenu](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#openmenu18) offers a more flexible solution. This API can be used directly or encapsulated in scenarios where no bound UI components are available, making it ideal for use cases such as event callbacks or when integrating with external systems.

## Displaying a Menu

To display a menu, call the [openMenu](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#openmenu18). The following is a basic example:
   
 <!-- @[open_menu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/Menu/globalmenusindependentofuicomponents/GlobalOpenMenu.ets) -->
 
 ``` TypeScript
 this.getUIContext().getPromptAction()
   .openMenu(this.contentNode, { id: targetId }, {
     enableArrow: true
   })
   .then(() => {
     hilog.info(0xFF00, 'globalOpenMenu', 'openMenu success');
   })
   .catch((err: BusinessError) => {
     hilog.error(0xFF00, 'globalOpenMenu', 'openMenu error: ' + err.code + ' ' + err.message);
   });
 ```
 
 <!--Del-->![openMenu]  (figures/openMenu.gif)<!--DelEnd-->

### Creating a ComponentContent Instance
   
   Use the **openMenu** API to display a menu and define **ComponentContent** to customize the menu content. For details about the specifications, see [ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md).
   
  <!-- @[content_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/Menu/globalmenusindependentofuicomponents/GlobalOpenMenu.ets) -->
  
  ``` TypeScript
  private contentNode: ComponentContent<Object> =
    new ComponentContent(this.getUIContext(), wrapBuilder(buildText), this.message, { nestingBuilderSupported: true });
  ```
   
   If **wrapBuilder** contains other components (such as [Popup](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Popup.md) and [Chip](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Chip.md)), you need to set [nestingBuilderSupported](../reference/apis-arkui/js-apis-arkui-builderNode.md#buildoptions12) to **true** when creating a **ComponentContent**.
   
 <!-- @[build_text](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/Menu/globalmenusindependentofuicomponents/GlobalOpenMenu.ets) -->
 
 ``` TypeScript
 @Builder
 export function buildText(params: Params) {
   Popup({
     // Set the icon content.
     icon: {
       // Replace $r('app.media.app_icon') with the actual resource file.
       image: $r('app.media.app_icon'),
       width: 32,
       height: 32,
       fillColor: Color.White,
       borderRadius: 10
     } as PopupIconOptions,
     // Set the text content.
     title: {
       text: `This is a Popup title 1`,
       fontSize: 20,
       fontColor: Color.Black,
       fontWeight: FontWeight.Normal
     } as PopupTextOptions,
     // Set the message content.
     message: {
       text: `This is a Popup message 1`,
       fontSize: 15,
       fontColor: Color.Black
     } as PopupTextOptions,
     // Set the buttons.
     buttons: [{
       text: 'confirm',
       action: () => {
         hilog.info(0xFF00, 'globalOpenMenu', 'confirm button click');
       },
       fontSize: 15,
       fontColor: Color.Black,
     },
       {
         text: 'cancel',
         action: () => {
           hilog.info(0xFF00, 'globalOpenMenu', 'cancel button click');
         },
         fontSize: 15,
         fontColor: Color.Black
       },] as [PopupButtonOptions?, PopupButtonOptions?]
   })
 }
 
 let contentNode: ComponentContent<Object> =
   new ComponentContent(uiContext, wrapBuilder(buildText), message, { nestingBuilderSupported: true });
 ```
 
 


### Providing Bound Component Information
   
   When calling **openMenu**, you must provide the [TargetInfo](../reference/apis-arkui/arkts-apis-uicontext-i.md#targetinfo18) of the bound component. If no valid target is passed, the menu cannot be displayed.
   
   Currently, there are two ways to set the target node:
   
- If **id** is a number, you should set it to the component's **UniqueID**, whose uniqueness is guaranteed by the system.
   
   <!-- @[frame_node](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/Menu/globalmenusindependentofuicomponents/GlobalOpenMenu.ets) -->
   
   ``` TypeScript
   let frameNode: FrameNode | null = this.getUIContext().getFrameNodeByUniqueId(this.getUniqueId());
   let targetId = frameNode?.getChild(0)?.getUniqueId();
   ```
   
- If **id** is a string, you should set it to the component's universal attribute [id](../reference/apis-arkui/arkui-ts/ts-universal-attributes-component-id.md#id). If the uniqueness of the ID cannot be ensured due to multiple-team development or reused custom component, you can set the **componentId** attribute to specify the ID range to accurately specify the target node. In this case, the **componentId** attribute can be set to the parent component or the **UniqueID** of the custom component.
   
   <!-- @[openMenuWithTargetIdString](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/Menu/globalmenusindependentofuicomponents/OpenMenuWithTargetIdString.ets) -->
   
   ``` TypeScript
   build() {
     NavDestination() {
       Column() {
         Row() {
           Button('button1')
             .id(this.targetIdString)
         }
   
         Row() {
           Button('button2')
             .id(this.targetIdString)
         }
   
         Button('openMenu')
           .onClick(() => {
             let frameNode: FrameNode | null = this.uiContext.getFrameNodeByUniqueId(this.getUniqueId());
             let componentId = frameNode?.getChild(1)?.getChild(0)?.getChild(1)?.getUniqueId();
             if (componentId == undefined) {
               this.componentId = 0;
             } else {
               this.componentId = componentId;
             }
             this.promptAction.openMenu(this.contentNode, { id: this.targetIdString, componentId: this.componentId }, {
               enableArrow: true
             })
               .then(() => {
                 hilog.info(0x0000, 'openMenuWithTargetIdString', 'openMenu success');
               })
               .catch((err: BusinessError) => {
                 hilog.error(0x0000, 'openMenuWithTargetIdString', 'openMenu error: ' + err.code + ' ' + err.message);
               });
           })
       }
     }
   }
   ```
   

### Customizing the Menu Style
   
   When calling **openMenu**, you can customize the menu style using [MenuOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#menuoptions10). Note that the **title** property is not effective, and the **preview** parameter supports only the [MenuPreviewMode](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#menupreviewmode11) type.
   
  <!-- @[menu_options](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/Menu/globalmenusindependentofuicomponents/GlobalOpenMenu.ets) -->
  
  ``` TypeScript
  private options: MenuOptions = { enableArrow: true, placement: Placement.Bottom };
  ```

## Updating the Menu Style

To update the menu style, use the [updateMenu](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#updatemenu18) API, supported since API version 18. You can update the style fully or incrementally. However, the following properties cannot be updated: **showInSubWindow** in [MenuOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#menuoptions10), **preview**, **previewAnimationOptions**, **transition**, **onAppear**, **aboutToAppear**, **onDisappear**, **aboutToDisappear**, **onWillAppear**, **onDidAppear**, **onWillDisappear**, and **onDidDisappear**.
   
<!-- @[update_menu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/Menu/globalmenusindependentofuicomponents/GlobalOpenMenu.ets) -->

``` TypeScript
this.getUIContext().getPromptAction()
  .updateMenu(this.contentNode, {
    enableArrow: false
  }, true)
  .then(() => {
    hilog.info(0xFF00, 'globalOpenMenu', 'updateMenu success');
  })
  .catch((err: BusinessError) => {
    hilog.error(0xFF00, 'globalOpenMenu', 'updateMenu error: ' + err.code + ' ' + err.message);
  });
```
   
   <!--Del-->![openMenu] (figures/openMenu.gif)<!--DelEnd-->

## Closing the Menu

To close the menu, use the [closeMenu](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#closemenu18) API, supported since API version 18.
   
<!-- @[close_menu](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/DialogProject/entry/src/main/ets/pages/Menu/globalmenusindependentofuicomponents/GlobalOpenMenu.ets) --> 

``` TypeScript
this.getUIContext().getPromptAction()
  .closeMenu(this.contentNode)
  .then(() => {
    hilog.info(0xFF00, 'globalOpenMenu', 'closeMenu success');
  })
  .catch((err: BusinessError) => {
    hilog.error(0xFF00, 'globalOpenMenu', 'closeMenu error: ' + err.code + ' ' + err.message);
  });
```
   
<!--Del-->![openMenu]  (figures/openMenu.gif)<!--DelEnd-->

> **NOTE**
>
> The [updateMenu](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#updatemenu18) and [closeMenu](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#closemenu18) APIs rely on the content to identify the menu. Therefore, you must maintain the content instance throughout the menu's lifecycle.

## Using the Global Menu in HAR Packages

You can encapsulate a menu using the [HAR](../quick-start/har-package.md) package to provide display, update, and close capabilities.

For details about how to invoke these capabilities, see [Using the Global Popup in HAR Packages](./arkts-popup-and-menu-components-uicontext-popup.md#using-the-global-popup-in-har-packages).
