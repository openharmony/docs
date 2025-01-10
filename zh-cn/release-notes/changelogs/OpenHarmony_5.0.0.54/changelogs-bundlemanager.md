# 包管理子系统Changelog

## cl.bundlemanager.1 安装的应用是已卸载的预置应用时校验签名是否一致

**访问级别**

公开接口

**变更原因**

预置应用被卸载后可以安装一个bundleName相同、签名不同的hap仿冒，有安全风险。

**变更影响**

该变更为不兼容变更。

变更前：预置应用被卸载后安装一个bundleName相同、签名不同的hap会安装成功。

变更后：预置应用被卸载后安装一个bundleName相同、签名不同的hap会安装失败。

**起始API Level**

API 7

**变更发生版本**

从OpenHarmony 5.0.0.54 版本开始。

**变更的接口/组件**

[bm工具](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/tools/bm-tool.md#%E5%AE%89%E8%A3%85%E5%91%BD%E4%BB%A4)安装命令。

**适配指导**

预置应用使用hdc命令安装时，安装hap的签名应该与预置hap的签名一致。