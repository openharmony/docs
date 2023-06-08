# 包管理子系统ChangeLog

## cl.bundlemanager.1 底层能力变更，安装hap时，hap中的文件不再解压到安装目录。

安装hap后，安装目录下只会存在hap文件，应用不能再使用拼接路径访问解压后的资源文件，应用想要访问资源文件，需要使用标准的资源管理接口。

**变更影响**<br>
如果应用使用拼接路径的形式访问资源文件，会访问失败。需要修改成使用资源管理接口访问资源文件。

**关键的接口/组件变更**<br>
不涉及接口及组件变更

**适配指导**<br>
资源管理子系统提供Js接口访问资源文件。参考[访问资源文件](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-resource-manager.md#getrawfilecontent9)