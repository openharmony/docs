# 包管理变更说明
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

## cl.bundlemanager.3 底层能力变更，hap不解压特性兼容SDK9。

使用API version 9或更早版本的SDK编译HAP时，安装HAP后会将HAP的资源文件解压。
使用API version 10或更新版本的SDK编译HAP时，安装HAP后HAP的资源文件不再解压。

**变更影响**<br>
使用API version 9或更早版本的SDK，应用无需适配。
使用API version 10或更新版本的SDK，应用如果使用拼接路径的方式访问资源文件，需要适配，否则无需适配。

**关键的接口/组件变更**<br>
不涉及接口及组件变更。

**适配指导**<br>
资源管理子系统提供Js接口访问资源文件。参考[访问资源文件](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-resource-manager.md#getrawfilecontent9)。


## cl.bundlemanager.4 module.json配置文件中distroFilter修改为distributionFilter
配置文件module.json中[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)标签修改为distributionFilter。

**变更影响**<br>
该变更为兼容性变更。配置文件module.json中[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)标签已废弃，IDE编译不会报错，编辑器中会有波浪线提示。

**适配指导**<br>
删除module.json中[distroFilter](../../../application-dev/quick-start/module-configuration-file.md)标签，使用distributionFilter替代。