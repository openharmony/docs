# HAR File Structure


The OpenHarmony Archive (HAR) file enables code to be shared among multiple modules or projects. Unlike a Harmony Ability Package (HAP) file, a HAR file cannot be independently installed on a device. Instead, it can only be referenced as the dependency of an application module.


A HAR file is the build product of a [module](https://developer.harmonyos.com/en/docs/documentation/doc-guides-V3/ohos-adding-deleting-module-0000001218760594-V3) of the Library type in a DevEco Studio project.


As a static shared package in OpenHarmony, the [HAR file](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-development-npm-package-0000001222578434) can contain the source code, C++ libraries, resource files, and the **module.json** file (in stage model) or **config.json** file (in FA model).
