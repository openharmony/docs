# Global Menus Independent of UI Components (openMenu)

The [Menu](arkts-popup-and-menu-components-menu.md) component is a great option for creating menus, but it relies on a bound UI component to work. Since API version 18, however, the global API [openMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#openmenu18) offers a more flexible solution. This API can be used directly or encapsulated in scenarios where no bound UI components are available, making it ideal for use cases such as event callbacks or when integrating with external systems.

## Displaying a Menu

To display a menu, call the [openMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#openmenu18) API. Here's a basic example:
   
   ```ts
   promptAction.openMenu(contentNode, { id: targetId }, {
     enableArrow: true
   })
     .then(() => {
       console.info('openMenu success');
     })
     .catch((err: BusinessError) => {
       console.info('openMenu error: ' + err.code + ' ' + err.message);
     })
   ```

### Creating a ComponentContent Instance
   
   When using **openMenu**, you need to provide a [ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md) instance to define the menu content. **wrapBuilder(buildText)** encapsulates the custom component, and **new Params(this.message)** is the input parameter for the custom component. This parameter is optional and can be a basic data type.
   
   ```ts
   private contentNode: ComponentContent<Object> = new ComponentContent(uiContext, wrapBuilder(buildText), this.message);
   ```
   
   If your **wrapBuilder** includes other components (such as [Popup](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Popup.md#popup) or [Chip](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Chip.md#chip)), the [ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md#componentcontent-1) constructor must include four parameters, and the **options** parameter must be **{ nestingBuilderSupported: true }**.
   
   ```ts
   @Builder
   export function buildText(params: Params) {
     Menu({
       // Set the icon for the menu.
       icon: {
         image: $r('app.media.app_icon'),
         width: 32,
         height: 32,
         fillColor: Color.White,
         borderRadius: 10
       } as MenuIconOptions,
       // Set the text content.
       title: {
         text: `This is a Menu title 1`,
         fontSize: 20,
         fontColor: Color.Black,
         fontWeight: FontWeight.Normal
       } as MenuTextOptions,
       // Set the text content.
       message: {
         text: `This is a Menu message 1`,
         fontSize: 15,
         fontColor: Color.Black
       } as MenuTextOptions,
       // Set the buttons.
       buttons: [{
         text: 'confirm',
         action: () => {
           console.info('confirm button click')
         },
         fontSize: 15,
         fontColor: Color.Black,
       },
         {
           text: 'cancel',
           action: () => {
             console.info('cancel button click')
           },
           fontSize: 15,
           fontColor: Color.Black
         },] as [MenuButtonOptions?, MenuButtonOptions?]
     })
   }
   
   let contentNode: ComponentContent<Object> = new ComponentContent(uiContext, wrapBuilder(buildText), this.message, { nestingBuilderSupported: true });
   ```


### Providing Bound Component Information
   
   When calling **openMenu**, you must provide the [TargetInfo](../reference/apis-arkui/js-apis-arkui-UIContext.md#targetinfo18) of the bound component. Without a valid target, the menu won't display.
   
   ```ts
   let frameNode: FrameNode | null = this.ctx.getFrameNodeByUniqueId(this.getUniqueId());
   let targetId = frameNode?.getChild(0)?.getUniqueId();
   ```

### Customizing the Menu Style
   
   When calling **openMenu**, you can customize the menu style using [MenuOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#menuoptions10). Note that the **title** property is not effective, and the **preview** parameter supports only the **MenuPreviewMode** type.
   
   ```ts
   private options: MenuOptions = { enableArrow: true, placement: Placement.Bottom };
   ```

## Updating the Menu Style

To update the menu style, use the [updateMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#updatemenu18) API. You can update the style fully or incrementally. However, certain properties, including **showInSubWindow**, **preview**, **previewAnimationOptions**, **transition**, **onAppear**, **aboutToAppear**, **onDisappear**, and **aboutToDisappear**, cannot be updated.
   
   ```ts
   promptAction.updateMenu(contentNode, {
     enableArrow: false
   }, true)
     .then(() => {
       console.info('updateMenu success');
     })
     .catch((err: BusinessError) => {
       console.info('updateMenu error: ' + err.code + ' ' + err.message);
     })
   ```

## Closing the Menu

To close the menu, call the [closeMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#closemenu18) API.
   
   ```ts
   promptAction.closeMenu(contentNode)
     .then(() => {
       console.info('openMenu success');
     })
    .catch((err: BusinessError) => {
      console.info('openMenu error: ' + err.code + ' ' + err.message);
    })
   ```

> **NOTE**
>
> The [updateMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#updatemenu18) and [closeMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#closemenu18) APIs rely on the content to identify the menu. Therefore, you must maintain the content instance throughout the menu's lifecycle.

## Using the Global Menu in HAR Packages

You can encapsulate a menu using the [HAR](../quick-start/har-package.md) package to provide display, update, and close capabilities.

For details about how to invoke these capabilities, see [Using the Global Popup in HAR Packages](./arkts-popup-and-menu-components-uicontext-popup.md#using-the-global-popup-in-har-packages).
