# arkui子系统ChangeLog

## cl.arkui.1 getInspectorTree接口返回值从string修改为Object。

**变更影响**

3.2.10.7之前使用getInspectorTree接口的代码需要适配

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
