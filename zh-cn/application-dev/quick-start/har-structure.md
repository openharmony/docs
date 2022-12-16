# HAR包结构


HAR（Harmony Ability Resources）包用于实现多个模块或多个工程间的代码共享。HAR包不同于HAP，不能独立安装运行在设备上，只能作为应用模块的依赖项被引用。


HAR包对应DevEco Studio工程中的“Library”类型的[Module](https://developer.harmonyos.com/cn/docs/documentation/doc-guides-V3/ohos-adding-deleting-module-0000001218760594-V3)。


OpenHarmony的HAR包复用标准的[npm包](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-development-npm-package-0000001222578434)发布方式，会打包成tar包（后缀为.tgz）。打包后的HAR包中包含源代码、资源文件、module.json文件（Stage模型）或config.json文件（FA模型）等。
