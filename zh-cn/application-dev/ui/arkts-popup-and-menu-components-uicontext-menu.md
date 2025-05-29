# 不依赖UI组件的全局菜单 (openMenu)

[菜单控制 (Menu)](arkts-popup-and-menu-components-menu.md)在使用时依赖绑定UI组件，否则无法使用。从API version 18开始，可以通过使用全局接口[openMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#openmenu18)的方式，在无UI组件的场景下直接或封装使用，例如在事件回调中使用或封装后对外提供能力。

## 弹出菜单

通过[openMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#openmenu18)可以弹出菜单。
   
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

### 创建ComponentContent
   
   通过调用openMenu接口弹出菜单，需要提供用于定义自定义弹出框的内容[ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md)。其中，wrapBuilder(buildText)封装自定义组件，new Params(this.message)是自定义组件的入参，可以缺省，也可以传入基础数据类型。
   
   ```ts
   private contentNode: ComponentContent<Object> = new ComponentContent(uiContext, wrapBuilder(buildText), this.message);
   ```
   
   如果在wrapBuilder中包含其他组件（例如：[Popup](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Popup.md#popup)、[Chip](../reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Chip.md#chip)组件），则[ComponentContent](../reference/apis-arkui/js-apis-arkui-ComponentContent.md#componentcontent-1)应采用带有四个参数的构造函数constructor，其中options参数应传递{ nestingBuilderSupported: true }。
   
   ```ts
   @Builder
   export function buildText(params: Params) {
     Menu({
       // 类型设置图标内容
       icon: {
         image: $r('app.media.app_icon'),
         width: 32,
         height: 32,
         fillColor: Color.White,
         borderRadius: 10
       } as MenuIconOptions,
       // 设置文字内容
       title: {
         text: `This is a Menu title 1`,
         fontSize: 20,
         fontColor: Color.Black,
         fontWeight: FontWeight.Normal
       } as MenuTextOptions,
       // 设置文字内容
       message: {
         text: `This is a Menu message 1`,
         fontSize: 15,
         fontColor: Color.Black
       } as MenuTextOptions,
       // 设置按钮内容
       buttons: [{
         text: 'confirm',
         action: () => {
           console.info('confirm button click');
         },
         fontSize: 15,
         fontColor: Color.Black,
       },
         {
           text: 'cancel',
           action: () => {
             console.info('cancel button click');
           },
           fontSize: 15,
           fontColor: Color.Black
         },] as [MenuButtonOptions?, MenuButtonOptions?]
     })
   }
   
   let contentNode: ComponentContent<Object> = new ComponentContent(uiContext, wrapBuilder(buildText), this.message, { nestingBuilderSupported: true });
   ```


### 绑定组件信息
   
   通过调用openMenu接口弹出菜单，需要提供绑定组件的信息[TargetInfo](../reference/apis-arkui/js-apis-arkui-UIContext.md#targetinfo18)。若未传入有效的target，则无法弹出菜单。
   
   ```ts
   let frameNode: FrameNode | null = this.ctx.getFrameNodeByUniqueId(this.getUniqueId());
   let targetId = frameNode?.getChild(0)?.getUniqueId();
   ```

### 设置弹出菜单样式
   
   通过调用openMenu接口弹出菜单，可以设置[MenuOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#menuoptions10)属性调整菜单样式。title属性不生效。preview参数仅支持设置MenuPreviewMode类型。
   
   ```ts
   private options: MenuOptions = { enableArrow: true, placement: Placement.Bottom };
   ```

## 更新菜单样式

通过[updateMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#updatemenu18)可以更新菜单的样式。支持全量更新和增量更新其菜单样式，不支持更新showInSubWindow、preview、previewAnimationOptions、transition、onAppear、aboutToAppear、onDisappear和aboutToDisappear。
   
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

## 关闭菜单

通过调用[closeMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#closemenu18)可以关闭菜单。
   
   ```ts
   promptAction.closeMenu(contentNode)
     .then(() => {
       console.info('openMenu success');
     })
    .catch((err: BusinessError) => {
      console.info('openMenu error: ' + err.code + ' ' + err.message);
    })
   ```

> **说明：**
>
> 由于[updateMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#updatemenu18)和[closeMenu](../reference/apis-arkui/js-apis-arkui-UIContext.md#closemenu18)依赖content来更新或者关闭指定的菜单，开发者需自行维护传入的content。

## 在HAR包中使用全局菜单

可以通过[HAR](../quick-start/har-package.md)包封装一个Menu，从而对外提供菜单的弹出、更新和关闭能力。

具体调用方式参考[在HAR包中使用全局气泡提示](./arkts-popup-and-menu-components-uicontext-popup.md#在har包中使用全局气泡提示)。
