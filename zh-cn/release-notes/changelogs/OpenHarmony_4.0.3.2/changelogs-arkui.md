# arkui子系统ChangeLog

## cl.arkui.1 getInspectorTree接口返回值从string修改为Object。

**变更影响**

4.0.3.2之前使用getInspectorTree接口的代码需要适配

**关键的接口/组件变更**

getInspectorTree接口返回值从string修改为Object

**适配指导**

将getInspectorTree返回值作为string使用的代码需要修改，比如以下示例代码：

```typescript
console.info(getInspectorTree())
```

需要修改成

```typescript
console.info(JSON.stringify(getInspectorTree())) 
```

## cl.arkui.2 废弃GridItem的forceRebuild属性

**变更影响**

无，该属性无作用

**关键的接口/组件变更**

GridItem的forceRebuild属性废弃

**适配指导**

如有使用可以直接删除，不影响GridItem功能


## cl.arkui.1 API9 router接口整改。

ohos.router中的enableAlertBeforeBackPage、enableBackPageAlert、disableAlertBeforeBackPage接口名不利于开发者理解，更改为showAlertBeforeBackPage、hideAlertBeforeBackPage。

**变更影响**

router的enableAlertBeforeBackPage、enableBackPageAlert接口需替换为showAlertBeforeBackPage；

disableAlertBeforeBackPage接口需替换为hideAlertBeforeBackPage。

**关键的接口/组件变更**

涉及router.enableAlertBeforeBackPage, router.enableBackPageAlert, router.disableAlertBeforeBackPage。

* 变更前：

```ts
router.enableAlertBeforeBackPage();
router.enableBackPageAlert()
```

* 变更后：

```ts
router.showAlertBeforeBackPage()
```

* 变更前：

```ts
router.disableAlertBeforeBackPage()
```

* 变更后：

```ts
router.hideAlertBeforeBackPage()
```

**适配指导**

将enableAlertBeforeBackPage、enableBackPageAlert替换为showAlertBeforeBackPage;

将disableAlertBeforeBackPage替换为hideAlertBeforeBackPage。
