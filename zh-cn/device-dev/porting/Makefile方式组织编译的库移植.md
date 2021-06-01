# Makefile方式组织编译的库移植<a name="ZH-CN_TOPIC_0000001064218672"></a>

-   [源码获取](#section114115321416)
-   [设置交叉编译](#section81263255384)
-   [测试](#section1830015913391)
-   [将该库编译添加到OpenHarmony工程中](#section1898016213406)

以yxml库为例，其移植过程如下文所示

## 源码获取<a name="section114115321416"></a>

从仓库[获取yxml源码](https://github.com/getdnsapi/yxml)，其目录结构如下表：

**表 1**  源码目录结构

<a name="table16520154171813"></a>
<table><thead align="left"><tr id="row2052115419188"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1352111417181"><a name="p1352111417181"></a><a name="p1352111417181"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p2521541171812"><a name="p2521541171812"></a><a name="p2521541171812"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row252164101814"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p747319438225"><a name="p747319438225"></a><a name="p747319438225"></a>yxml/bench/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1852214114183"><a name="p1852214114183"></a><a name="p1852214114183"></a>benchmark相关代码</p>
</td>
</tr>
<tr id="row11402205216237"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6473134382216"><a name="p6473134382216"></a><a name="p6473134382216"></a>yxml/test/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2040355219237"><a name="p2040355219237"></a><a name="p2040355219237"></a>测试输入输出文件，及测试脚本</p>
</td>
</tr>
<tr id="row35220418182"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1547384313229"><a name="p1547384313229"></a><a name="p1547384313229"></a>yxml/Makefile</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7522041131814"><a name="p7522041131814"></a><a name="p7522041131814"></a>编译组织文件</p>
</td>
</tr>
<tr id="row17522144114180"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6473164392210"><a name="p6473164392210"></a><a name="p6473164392210"></a>yxml/.gitattributes</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p145221541151817"><a name="p145221541151817"></a><a name="p145221541151817"></a>-</p>
</td>
</tr>
<tr id="row7522941131811"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12473144312217"><a name="p12473144312217"></a><a name="p12473144312217"></a>yxml/.gitignore</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p95231141121810"><a name="p95231141121810"></a><a name="p95231141121810"></a>-</p>
</td>
</tr>
<tr id="row13523841161812"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p72441217182819"><a name="p72441217182819"></a><a name="p72441217182819"></a>yxml/COPYING</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1752319414186"><a name="p1752319414186"></a><a name="p1752319414186"></a>-</p>
</td>
</tr>
<tr id="row165231641111810"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p347304312226"><a name="p347304312226"></a><a name="p347304312226"></a>yxml/yxml.c</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p4523174113188"><a name="p4523174113188"></a><a name="p4523174113188"></a>-</p>
</td>
</tr>
<tr id="row1452344110184"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p18473643152213"><a name="p18473643152213"></a><a name="p18473643152213"></a>yxml/yxml.c.in</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1252317413187"><a name="p1252317413187"></a><a name="p1252317413187"></a>-</p>
</td>
</tr>
<tr id="row12744431142214"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p274693119222"><a name="p274693119222"></a><a name="p274693119222"></a>yxml/yxml-gen.pl</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p274753111227"><a name="p274753111227"></a><a name="p274753111227"></a>-</p>
</td>
</tr>
<tr id="row7967123412215"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1947314314225"><a name="p1947314314225"></a><a name="p1947314314225"></a>yxml/yxml.h</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p16967203462218"><a name="p16967203462218"></a><a name="p16967203462218"></a>-</p>
</td>
</tr>
<tr id="row3988153742217"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p109891737112216"><a name="p109891737112216"></a><a name="p109891737112216"></a>yxml/yxml.md</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10989123732213"><a name="p10989123732213"></a><a name="p10989123732213"></a>-</p>
</td>
</tr>
<tr id="row184521641102214"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p847314433221"><a name="p847314433221"></a><a name="p847314433221"></a>yxml/yxml-states</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p4453154111224"><a name="p4453154111224"></a><a name="p4453154111224"></a>-</p>
</td>
</tr>
</tbody>
</table>

## 设置交叉编译<a name="section81263255384"></a>

设置Makefile的交叉编译工具链，修改并编译该库，生成OpenHarmony平台的可执行文件，步骤如下：

1.  设置工具链

    将下列clang工具链配置替换掉yxml库根目录的MakeFile（即[表1中的文件](#table16520154171813)）中的原有配置。

    clang工具链配置

    ```
    #设置交叉编译工具链，确保工具链所在路径已经添加到了PATH环境变量中
    CC:=clang
    AR:=llvm-ar
    #cflags中必须要添加--target及--sysroot选项
    CFLAGS:=-Wall -Wextra -Wno-unused-parameter -O2 -g --target=arm-liteos -march=armv7-a --sysroot=$(OHOS_ROOT_PATH)prebuilts/lite/sysroot
    ```

    原有配置

    ```
    CC:=gcc
    AR:=ar
    CFLAGS:=-Wall -Wextra -Wno-unused-parameter -O2 -g
    ```

2.  执行编译

    linux命令行中进入yxml的源文件目录（即图1所示目录），执行下列命令：

    ```
    make test OHOS_SYSROOT_PATH=...
    ```

    其中OHOS\_SYSROOT\_PATH需用绝对路径指定出sysroot所在目录，以OpenHarmony为例即源码根目录prebuilts/lite/sysroot/所在的绝对路径。

3.  查看结果

    步骤2操作完成后，yxml下会生成out目录，里面有静态库文件和测试用例：

    **表 2**  yxml编译生成目录

    <a name="table3271115435618"></a>
    <table><thead align="left"><tr id="row1273454185610"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p3273154185616"><a name="p3273154185616"></a><a name="p3273154185616"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p18273145445612"><a name="p18273145445612"></a><a name="p18273145445612"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1627317542567"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p13273154175620"><a name="p13273154175620"></a><a name="p13273154175620"></a>openHarmony/third_party/yxml/yxml/out/lib/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p132744541562"><a name="p132744541562"></a><a name="p132744541562"></a>编译生成的静态库的存放目录</p>
    </td>
    </tr>
    <tr id="row112741554165612"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17274165475611"><a name="p17274165475611"></a><a name="p17274165475611"></a>openHarmony/third_party/yxml/yxml/out/test/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p152741354135614"><a name="p152741354135614"></a><a name="p152741354135614"></a>编译生成的测试用例及其输入输出等文件的存放目录</p>
    </td>
    </tr>
    </tbody>
    </table>


## 测试<a name="section1830015913391"></a>

yxml库测试步骤与double-conversion库基本一致，可参考[CMake方式组织编译的库移植](CMake方式组织编译的库移植.md#section6686144293611)的测试过程，以下内容介绍yxml库测试用例的使用方法：

**表 3**  生成的test目录结构示意

<a name="table115941423164318"></a>
<table><thead align="left"><tr id="row1059515236433"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p55950233437"><a name="p55950233437"></a><a name="p55950233437"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p4595192324313"><a name="p4595192324313"></a><a name="p4595192324313"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1759572304318"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17595323144319"><a name="p17595323144319"></a><a name="p17595323144319"></a>openHarmony/third_party/yxml/yxml/out/test/test.sh</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p25956235437"><a name="p25956235437"></a><a name="p25956235437"></a>自动化测试脚本，由于<span id="text625264318457"><a name="text625264318457"></a><a name="text625264318457"></a>OpenHarmony</span>不支持脚本运行，因此无法使用，可参考其内容手动测试</p>
</td>
</tr>
<tr id="row155951823184312"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p659572313436"><a name="p659572313436"></a><a name="p659572313436"></a>openHarmony/third_party/yxml/yxml/out/test/test</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7595102314319"><a name="p7595102314319"></a><a name="p7595102314319"></a>用于测试的可执行文件</p>
</td>
</tr>
<tr id="row359619238437"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p205969232436"><a name="p205969232436"></a><a name="p205969232436"></a>openHarmony/third_party/yxml/yxml/out/test/*.xml</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p559662344315"><a name="p559662344315"></a><a name="p559662344315"></a>测试输入文件</p>
</td>
</tr>
<tr id="row959613236439"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1159652312438"><a name="p1159652312438"></a><a name="p1159652312438"></a>openHarmony/third_party/yxml/yxml/out/test/*.out</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p18596182314318"><a name="p18596182314318"></a><a name="p18596182314318"></a>期望的输出文件</p>
</td>
</tr>
</tbody>
</table>

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

由于OpenHarmony的shell中暂不支持输入输出重定向（<和\>），所以测试时需要将输入\*.xml文件内容直接复制进shell后回车，输出内容会直接展示在shell窗口。过程如下：

下列操作假定已按照2.4节的步骤搭建OpenHarmony，挂载并进入nfs目录：

1.  执行下列命令

    ```
    ./test
    ```

2.  复制\*.xml内容到shell

    以[test目录](#table115941423164318)下pi01.xml为例，内容如下，输入到shell并回车：

    ```
    <?SomePI abc?><a/>
    ```

3.  比较shell中输出的内容与[test目录](#table115941423164318)中对应的\*.out文件是否一致

    输出结果如下：

    ```
    pistart SomePI
    picontent abc
    piend
    elemstart a
    elemend
    ok
    ```

    经比较与[test目录](#table115941423164318)下pi01.out内容一致，测试通过。


## 将该库编译添加到OpenHarmony工程中<a name="section1898016213406"></a>

yxml库添加的过程除了适配文件build.gn和config.gni有些许变化外，其他和double-conversion库完全一致，参考[CMake方式组织编译的库移植](CMake方式组织编译的库移植.md#section1651053153715)的配置过程。要修改的适配文件及添加后的目录结构如下：

-   yxml库新增的BUILD.gn实现如下：

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

-   yxml库新增的config.gni配置如下：

```
TEST_ENABLE = "YES"

if (TEST_ENABLE == "YES") {
    MAKE_COMMAND = "make test OHOS_SYSROOT_PATH=${ohos_root_path}prebuilts/lite/sysroot/"
} else {
    MAKE_COMMAND = "make OHOS_SYSROOT_PATH=${ohos_root_path}prebuilts/lite/sysroot/"
}
```

-   添加完成后目录结构示意：

**表 4**  添加到工程后的目录结构

<a name="table13265185817173"></a>
<table><thead align="left"><tr id="row92666583171"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p2266105816178"><a name="p2266105816178"></a><a name="p2266105816178"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p32661158161718"><a name="p32661158161718"></a><a name="p32661158161718"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1526655816175"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p226605811710"><a name="p226605811710"></a><a name="p226605811710"></a>openHarmony/third_party/yxml/BUILD.gn</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1626675812177"><a name="p1626675812177"></a><a name="p1626675812177"></a>将三方库加入工程的gn适配文件</p>
</td>
</tr>
<tr id="row1726610589179"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12266115815170"><a name="p12266115815170"></a><a name="p12266115815170"></a>openHarmony/third_party/yxml/build_thirdpaty.py</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p122661958201719"><a name="p122661958201719"></a><a name="p122661958201719"></a>GN调用shell命令脚本文件，由上面GN文件将相关命令传入，实现GN转Makefile</p>
</td>
</tr>
<tr id="row7266195891714"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p162665581170"><a name="p162665581170"></a><a name="p162665581170"></a>openHarmony/third_party/yxml/config.gni</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p626712588175"><a name="p626712588175"></a><a name="p626712588175"></a>三方库编译配置文件，可修改该文件来配置用例是否参与构建等</p>
</td>
</tr>
<tr id="row1272420109203"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17725101052012"><a name="p17725101052012"></a><a name="p17725101052012"></a>openHarmony/third_party/yxml/yxml/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p87252109205"><a name="p87252109205"></a><a name="p87252109205"></a>要移植的三方库目录</p>
</td>
</tr>
</tbody>
</table>

