# 包管理子系统Changelog

## cl.bundlemanager.1 install接口安装系统应用前，若对应的预置版本应用已卸载，会先安装预置版本应用

**访问级别**

系统接口

**变更原因**

原先可以直接安装任意版本的系统应用，导致小于或等于预置版本的应用也能成功安装。更改后，当重新安装已卸载的预置系统应用时，如果存在预置版本，会先安装预置版本，然后再安装目标版本。若目标版本号小于或等于预置版本号，则目标版本安装失败，从而避免安装小于或等于预置版本的系统应用。此外，目标版本应用能够继承预置版本的预置属性。

**变更影响**

此变更涉及应用适配。

变更前：安装一个任意版本的系统应用，能够直接安装成功。

变更后：安装一个系统应用，若存在预置版本且已被卸载，会先进行预置版本应用的安装，再安装目标版本应用。如果目标版本号高于预置版本，可以安装成功，否则会安装预置版本应用成功但安装目标版本应用失败。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.1.0.52 版本开始。

**变更的接口/组件**

bundle.installer.d.ts中如下接口：

1. install(hapFilePaths: Array\<string\>, installParam: InstallParam, callback: AsyncCallback\<void\>)
2. install(hapFilePaths: Array\<string\>, callback: AsyncCallback\<void\>)
3. install(hapFilePaths: Array\<string\>, installParam?: InstallParam): Promise\<void\>

**适配指导**

开发者在安装预置系统应用场景，若出现安装失败但预置版本应用安装成功，检查并确保待安装应用版本号大于对应的预置版本号，再重新安装指定应用。