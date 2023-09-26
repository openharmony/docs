# 包管理子系统ChangeLog
## cl.bundlemanager.1 ExtensionAbilityType定义变更，删除APP_ACCOUNT_AUTHORIZATION

从当前版本开始，删除此枚举类型中的APP_ACCOUNT_AUTHORIZATION。

开发者需要根据以下说明对应用进行适配。

**变更影响**

该接口删除无法再使用，请进行适配更新，否则会影响原有功能。

- 涉及接口

```js
  export enum ExtensionAbilityType
```

- 变更前：

```js
  export enum ExtensionAbilityType {
    FORM = 0,
    WORK_SCHEDULER = 1,
    INPUT_METHOD = 2,
    SERVICE = 3,
    ACCESSIBILITY = 4,
    DATA_SHARE = 5,
    FILE_SHARE = 6,
    STATIC_SUBSCRIBER = 7,
    WALLPAPER = 8,
    BACKUP = 9,
    WINDOW = 10,
    ENTERPRISE_ADMIN = 11,
    THUMBNAIL = 13,
    PREVIEW = 14,
    PRINT = 15,
    PUSH = 17,
    DRIVER = 18,
    APP_ACCOUNT_AUTHORIZATION = 19,
    UNSPECIFIED = 255
  }
```

- 变更后：
```js
  export enum ExtensionAbilityType {
    FORM = 0,
    WORK_SCHEDULER = 1,
    INPUT_METHOD = 2,
    SERVICE = 3,
    ACCESSIBILITY = 4,
    DATA_SHARE = 5,
    FILE_SHARE = 6,
    STATIC_SUBSCRIBER = 7,
    WALLPAPER = 8,
    BACKUP = 9,
    WINDOW = 10,
    ENTERPRISE_ADMIN = 11,
    THUMBNAIL = 13,
    PREVIEW = 14,
    PRINT = 15,
    PUSH = 17,
    DRIVER = 18,
    UNSPECIFIED = 255
  }
```
删除APP_ACCOUNT_AUTHORIZATION定义。


**适配指导**

该接口删除后无法再使用，请适配更新。

## cl.bundlemanager.2 结构体BusinessAbilityInfo文件路径变更，从bundleManager文件夹移动至application文件夹下

结构体BusinessAbilityInfo文件路径变更，从bundleManager文件夹移动至application文件夹下。


**变更影响**

二级模块文件路径变更，对开发者无影响。

**关键的接口/组件变更**

结构体BusinessAbilityInfo修改文件路径，由bundleManager/BusinessAbilityInfo修改为application/BusinessAbilityInfo。

**适配指导**

无
