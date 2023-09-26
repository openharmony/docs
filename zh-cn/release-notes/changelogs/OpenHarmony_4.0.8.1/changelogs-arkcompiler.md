# ArkCompiler子系统ChangeLog

## cl.ArkCompiler.1 type编译模式默认使用es2abc

SDK中ArkCompiler有两个编译器支持ets/ts/js的编译，分别是ts2abc编译器和es2abc编译器。<br>
编译模式介绍：<br>
​&emsp;非type编译：ets/ts源码转化为js源码，使用ArkCompiler编译器es2abc生成字节码。<br>
​&emsp;type编译：ets/ts源码转化为ts源码，使用ArkCompiler编译器ts2abc(之前版本)/es2abc(此版本使能)生成字节码。<br>
应用工程hvigor版本信息查看：<br>
​&emsp;应用工程hvigor目录hvigor-config.json5文件中hvigorVersion字段以及dependencies中@ohos/hvigor-ohos-plugin字段。<br>
开启type编译：<br>
​&emsp;hvigor版本大于等于2.6.0-rc.9.s时默认使用type模式编译，或者应用源码(src目录)同级目录build-profile.json5文件中，buildOption标签下配置"aotCompileMode": "type"选项。<br>

当开启type编译且使用该版本的SDK时，将默认使用ArkCompiler编译器es2abc编译ts源码生成字节码，并且不推荐使用使能ts2abc的老版本SDK进行type编译。<br>

**变更影响**<br>
使用DevEco Studio进行应用开发，使能type编译模式并使用新版SDK后，由于编译模式的变更以及ArkCompiler编译器的变更，可能会出现应用编译失败，运行时Crash等。<br>

**关键的接口/组件变更**<br>
type编译模式默认使用ArkCompiler编译器es2abc<br>

**适配指导**<br>
1. hvigor版本大于等于2.6.0-rc.9.s时，切换原来的编译模式(非type)，开发者需要在build-profile.json5文件中配置"aotCompileMode":""。
