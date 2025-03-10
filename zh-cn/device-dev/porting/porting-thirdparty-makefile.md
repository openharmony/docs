# Makefile方式组织编译的库移植


以yxml库为例，其移植过程如下文所示。


## 源码获取

从仓库[获取yxml源码](https://github.com/getdnsapi/yxml)，其目录结构如下表：

  **表1** 源码目录结构

| 名称 | 描述 | 
| -------- | -------- |
| yxml/bench/ | benchmark相关代码。 | 
| yxml/test/ | 测试输入输出文件，及测试脚本。 | 
| yxml/Makefile | 编译组织文件。 | 
| yxml/.gitattributes | - | 
| yxml/.gitignore | - | 
| yxml/COPYING | - | 
| yxml/yxml.c | - | 
| yxml/yxml.c.in | - | 
| yxml/yxml-gen.pl | - | 
| yxml/yxml.h | - | 
| yxml/yxml.md | - | 
| yxml/yxml-states | - | 


## 设置交叉编译

设置Makefile的交叉编译工具链，修改并编译该库，生成OpenHarmony平台的可执行文件，步骤如下：

1. 设置工具链
   将下列clang工具链配置替换掉yxml库根目录的Makefile（即表1中的文件）中的原有配置。

     clang工具链配置：
     
   ```
   #设置交叉编译工具链，确保工具链所在路径已经添加到了PATH环境变量中
   CC:=clang
   AR:=llvm-ar
   #cflags中必须要添加--target及--sysroot选项
   CFLAGS:=-Wall -Wextra -Wno-unused-parameter -O2 -g --target=arm-liteos -march=armv7-a -mfloat-abi=softfp -mcpu=cortex-a7 -mfpu=neon-vfpv4 --sysroot=$(OHOS_SYSROOT_PATH)
   ```

   原有配置：

     
   ```
   CC:=gcc
   AR:=ar
   CFLAGS:=-Wall -Wextra -Wno-unused-parameter -O2 -g
   ```

2. 执行编译
   linux命令行中进入yxml的源文件目录（即图1所示目录），执行下列命令：

     
   ```
   make test OHOS_SYSROOT_PATH=...
   ```

   其中OHOS_SYSROOT_PATH需用绝对路径指定出sysroot所在目录，以OpenHarmony为例即源码根目录下out/hispark_xxx/ipcamera_hispark_xxx/sysroot目录的绝对路径。上述目录会在全量编译后生成，因此移植前先完成一次全量编译。

3. 查看结果
   步骤2操作完成后，yxml下会生成out目录，里面有静态库文件和测试用例：

     **表2** yxml编译生成目录
   
   | 名称 | 描述 | 
   | -------- | -------- |
   | OpenHarmony/third_party/yxml/yxml/out/lib/ | 编译生成的静态库的存放目录。 | 
   | OpenHarmony/third_party/yxml/yxml/out/test/ | 编译生成的测试用例及其输入输出等文件的存放目录。 | 


## 测试

yxml库测试步骤与double-conversion库基本一致，可参考[CMake方式组织编译的库移植](../porting/porting-thirdparty-cmake.md#测试)的测试过程，以下内容介绍yxml库测试用例的使用方法：

  **表3** 生成的test目录结构示意

| 名称 | 描述 | 
| -------- | -------- |
| OpenHarmony/third_party/yxml/yxml/out/test/test.sh | 自动化测试脚本，由于OpenHarmony不支持脚本运行，因此无法使用，可参考其内容手动测试。 | 
| OpenHarmony/third_party/yxml/yxml/out/test/test | 用于测试的可执行文件。 | 
| OpenHarmony/third_party/yxml/yxml/out/test/\*.xml | 测试输入文件。 | 
| OpenHarmony/third_party/yxml/yxml/out/test/\*.out | 期望的输出文件。 | 

test.sh内容如下所示：

  
```
#!/bin/sh
for i in *.xml; do
  b=`basename $i .xml`
  o=${b}.out
  t=${b}.test
  ./test <$i >$t
  if [ -n "`diff -q $o $t`" ]; then
    echo "Test failed for $i:"
    diff -u $o $t
    exit 1
  fi
done
echo "All tests completed successfully."
```

由于OpenHarmony的shell中暂不支持输入输出重定向（&lt;和&gt;），所以测试时需要将输入\*.xml文件内容直接复制进shell后回车，输出内容会直接展示在shell窗口。过程如下：

下列操作假定已按照2.4节的步骤搭建OpenHarmony，挂载并进入nfs目录：

1. 执行下列命令。
     
   ```
   ./test
   ```

2. 复制\*.xml内容到shell。
     以表3test目录下pi01.xml为例，内容如下，输入到shell并回车：
     
   ```
   <?SomePI abc?><a/>
   ```

3. 比较shell中输出的内容与表3test目录中对应的\*.out文件是否一致。
   输出结果如下：

     
   ```
   pistart SomePI
   picontent abc
   piend
   elemstart a
   elemend
   ok
   ```

   经比较与表3test目录下pi01.out内容一致，测试通过。


## 将该库编译添加到OpenHarmony工程中

yxml库添加的过程除了适配文件build.gn和config.gni有些许变化外，其他和double-conversion库完全一致，参考[CMake方式组织编译的库移植](../porting/porting-thirdparty-cmake.md#将该库编译添加到openharmony工程中)的配置过程。要修改的适配文件及添加后的目录结构如下：

- yxml库新增的BUILD.gn实现如下：

  
```
import("config.gni")
group("yxml") {
    if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
        deps = [":make"]
    }
}
if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
    action("make") {
        script = "//third_party/yxml/build_thirdparty.py"
        outputs = ["$target_out_dir/log_yxml.txt"]
        exec_path = rebase_path(rebase_path("./yxml", root_build_dir))
        command = "make clean && $MAKE_COMMAND"
        args = [
            "--path=$exec_path",
            "--command=${command}"
        ]
    }
}
```

- yxml库新增的config.gni配置如下：

  
```
TEST_ENABLE = "YES"

if (TEST_ENABLE == "YES") {
    MAKE_COMMAND = "make test OHOS_SYSROOT_PATH=${root_out_dir}sysroot/"
} else {
    MAKE_COMMAND = "make OHOS_SYSROOT_PATH=${root_out_dir}sysroot/"
}
```

- 添加完成后目录结构示意：

  **表4** 添加到工程后的目录结构

| 名称 | 描述 | 
| -------- | -------- |
| OpenHarmony/third_party/yxml/BUILD.gn | 将三方库加入工程的gn适配文件。 | 
| OpenHarmony/third_party/yxml/build_thirdparty.py | GN调用shell命令脚本文件，由上面GN文件将相关命令传入，实现GN转Makefile。 | 
| OpenHarmony/third_party/yxml/config.gni | 三方库编译配置文件，可修改该文件来配置用例是否参与构建等。 | 
| OpenHarmony/third_party/yxml/yxml/ | 要移植的三方库目录。 | 
