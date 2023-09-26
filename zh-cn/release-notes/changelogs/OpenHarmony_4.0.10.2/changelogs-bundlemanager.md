# 包管理子系统ChangeLog

## cl.bundlemanager.1 底层能力变更，hap不解压特性兼容SDK9。

使用API version 9或更早版本的SDK编译HAP时，安装HAP后会将HAP的资源文件解压。
使用API version 10或更新版本的SDK编译HAP时，安装HAP后HAP的资源文件不再解压。

**变更影响**<br>
使用API version 9或更早版本的SDK，应用无需适配。
使用API version 10或更新版本的SDK，应用如果使用拼接路径的方式访问资源文件，需要适配，否则无需适配。

**关键的接口/组件变更**<br>
不涉及接口及组件变更。

**适配指导**<br>
资源管理子系统提供Js接口访问资源文件。参考[访问资源文件](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-resource-manager.md#getrawfilecontent9)