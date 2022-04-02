# CMake方式组织编译的库移植<a name="ZH-CN_TOPIC_0000001063033549"></a>

-   [源码获取](#section1771132116245)
-   [移植思路](#section9737174410328)
-   [交叉编译](#section38205577332)
    -   [编译参考](#section1088111263418)
    -   [设置执行交叉编译](#section8168182883515)

-   [测试](#section6686144293611)
-   [将该库编译添加到OpenHarmony工程中](#section1651053153715)

以double-conversion库为例，其移植过程如下文所示

## 源码获取<a name="section1771132116245"></a>

从仓库[获取double-conversion源码](https://github.com/google/double-conversion)，其目录结构如下表：

**表 1**  源码目录结构

<a name="table824211132418"></a>
<table><thead align="left"><tr id="row524220131043"><th class="cellrowborder" valign="top" width="49.95%" id="mcps1.2.3.1.1"><p id="p22421213442"><a name="p22421213442"></a><a name="p22421213442"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50.05%" id="mcps1.2.3.1.2"><p id="p132427131241"><a name="p132427131241"></a><a name="p132427131241"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1335114463010"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p3354144414307"><a name="p3354144414307"></a><a name="p3354144414307"></a>double-conversion/cmake/</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p1235564417307"><a name="p1235564417307"></a><a name="p1235564417307"></a>CMake组织编译使用到的模板</p>
</td>
</tr>
<tr id="row1024211133411"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p12423137414"><a name="p12423137414"></a><a name="p12423137414"></a>double-conversion/double-conversion/</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p824221314420"><a name="p824221314420"></a><a name="p824221314420"></a>源文件目录</p>
</td>
</tr>
<tr id="row1242813545"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p424213131343"><a name="p424213131343"></a><a name="p424213131343"></a>double-conversion/msvc/</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p172429139418"><a name="p172429139418"></a><a name="p172429139418"></a>-</p>
</td>
</tr>
<tr id="row20242513641"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p2024210139412"><a name="p2024210139412"></a><a name="p2024210139412"></a>double-conversion/test/</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p7242713241"><a name="p7242713241"></a><a name="p7242713241"></a>测试用例源文件</p>
</td>
</tr>
<tr id="row12242191314413"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p172420131646"><a name="p172420131646"></a><a name="p172420131646"></a>double-conversion/.gitignore</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p112426131843"><a name="p112426131843"></a><a name="p112426131843"></a>-</p>
</td>
</tr>
<tr id="row1484211616360"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p1384206143617"><a name="p1384206143617"></a><a name="p1384206143617"></a>double-conversion/AUTHORS</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p384310614366"><a name="p384310614366"></a><a name="p384310614366"></a>-</p>
</td>
</tr>
<tr id="row1290331063610"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p18903410183613"><a name="p18903410183613"></a><a name="p18903410183613"></a>double-conversion/BUILD</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p1990491033617"><a name="p1990491033617"></a><a name="p1990491033617"></a>-</p>
</td>
</tr>
<tr id="row5967101420368"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p696710141361"><a name="p696710141361"></a><a name="p696710141361"></a>double-conversion/CMakeLists.txt</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p1196714147366"><a name="p1196714147366"></a><a name="p1196714147366"></a>CMake方式顶层编译组织文件</p>
</td>
</tr>
<tr id="row19372034133612"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p1596214484473"><a name="p1596214484473"></a><a name="p1596214484473"></a>double-conversion/COPYING</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p163811348364"><a name="p163811348364"></a><a name="p163811348364"></a>-</p>
</td>
</tr>
<tr id="row0184133717364"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p1166255034715"><a name="p1166255034715"></a><a name="p1166255034715"></a>double-conversion/Changelog</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p151851337193617"><a name="p151851337193617"></a><a name="p151851337193617"></a>-</p>
</td>
</tr>
<tr id="row173871412369"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p411055217475"><a name="p411055217475"></a><a name="p411055217475"></a>double-conversion/LICENSE</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p9387641173617"><a name="p9387641173617"></a><a name="p9387641173617"></a>-</p>
</td>
</tr>
<tr id="row534170185015"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p035703507"><a name="p035703507"></a><a name="p035703507"></a>double-conversion/Makefile</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p6367075019"><a name="p6367075019"></a><a name="p6367075019"></a>-</p>
</td>
</tr>
<tr id="row1367804175011"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p1246133725014"><a name="p1246133725014"></a><a name="p1246133725014"></a>double-conversion/README.md</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p136796410508"><a name="p136796410508"></a><a name="p136796410508"></a>-</p>
</td>
</tr>
<tr id="row2070619141508"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p1963193815509"><a name="p1963193815509"></a><a name="p1963193815509"></a>double-conversion/SConstruct</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p570691485015"><a name="p570691485015"></a><a name="p570691485015"></a>-</p>
</td>
</tr>
<tr id="row186521925020"><td class="cellrowborder" valign="top" width="49.95%" headers="mcps1.2.3.1.1 "><p id="p152191040155012"><a name="p152191040155012"></a><a name="p152191040155012"></a>double-conversion/WORKSPACE</p>
</td>
<td class="cellrowborder" valign="top" width="50.05%" headers="mcps1.2.3.1.2 "><p id="p4661119175014"><a name="p4661119175014"></a><a name="p4661119175014"></a>-</p>
</td>
</tr>
</tbody>
</table>

## 移植思路<a name="section9737174410328"></a>

移植思路：通过修改工具链，交叉编译该三方库，生成OpenHarmony平台的可执行文件，最后再通过GN调用CMake的方式添加到OpenHarmony工程中。

## 交叉编译<a name="section38205577332"></a>

### 编译参考<a name="section1088111263418"></a>

代码仓库的[README.md](https://github.com/google/double-conversion/blob/master/README.md)中详细介绍了使用CMake编译double-conversion库的步骤，以及测试方法。本文参考该指导设置该库的编译配置，并完成测试。若开发人员在移植过程中对该库的编译选项配置有疑惑的地方，可参考该指导。对于其他使用CMake可独立编译的三方库，在移植时可以参考其自带的编译指导。

### 设置执行交叉编译<a name="section8168182883515"></a>

CMake方式可通过指定工具链进行交叉编译，修改并编译该库，生成OpenHarmony平台的可执行文件，步骤如下：

1.  设置工具链

    将下列clang工具链配置添加到该工程的顶层CMakeLists.txt（即[表1中的该文件](#table824211132418)）中即可。

    ```
    set(CMAKE_CROSSCOMPILING TRUE)
    set(CMAKE_SYSTEM_NAME Generic)
    set(CMAKE_CXX_COMPILER_ID Clang)
    set(CMAKE_TOOLCHAIN_PREFIX llvm-)
    #指定c编译工具（确保工具链所在路径已经添加到了PATH环境变量中）和编译标志，使用clang编译时标志中必须指定--target，否则无法交叉编译。
    set(CMAKE_C_COMPILER clang)
    set(CMAKE_C_FLAGS "--target=arm-liteos -D__clang__ -march=armv7-a -w")
    #指定c++编译工具（确保工具链所在路径已经添加到了PATH环境变量中）和编译标志，必须指定--target，否则无法交叉编译。
    set(CMAKE_CXX_COMPILER clang++) 
    set(CMAKE_CXX_FLAGS "--target=arm-liteos -D__clang__ -march=armv7-a -w")
    #指定链接工具和链接标志，必须指定--target和--sysroot，其中OHOS_ROOT_PATH可通过cmake命令后缀参数来指定。
    set(MY_LINK_FLAGS "--target=arm-liteos --sysroot=${OHOS_SYSROOT_PATH}")
    set(CMAKE_LINKER clang)
    set(CMAKE_CXX_LINKER clang++)
    set(CMAKE_C_LINKER clang)
    set(CMAKE_C_LINK_EXECUTABLE
        "${CMAKE_C_LINKER} ${MY_LINK_FLAGS} <FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
    set(CMAKE_CXX_LINK_EXECUTABLE
        "${CMAKE_CXX_LINKER} ${MY_LINK_FLAGS} <FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
    #指定链接库的查找路径。
    set(CMAKE_SYSROOT ${OHOS_SYSROOT_PATH})
    ```

2.  执行编译

    linux命令行中进入double-conversion的源文件目录（即[表1所示目录](#table824211132418)），执行下列命令：

    ```
    mkdir build && cd build
    cmake .. -DBUILD_TESTING=ON -DOHOS_SYSROOT_PATH="..."
    make -j
    ```

    其中OHOS\_SYSROOT\_PATH需用绝对路径指定出sysroot目录的位置，以OpenHarmony为例即目录out/hispark\_xxx/ipcamera\_hispark\_xxx/sysroot的绝对路径。上述目录会在全量编译后生成，因此移植前先完成一次全量编译。

3.  <a name="li15717101715249"></a>查看结果

    步骤2操作完成后，build目录下会生成静态库文件和测试用例：

    **表 2**  编译生成文件目录结构

    <a name="table1452412391911"></a>
    <table><thead align="left"><tr id="row15259397114"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p084365219116"><a name="p084365219116"></a><a name="p084365219116"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p118435524118"><a name="p118435524118"></a><a name="p118435524118"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17861750780"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p208014918411"><a name="p208014918411"></a><a name="p208014918411"></a>double-conversion/build/libdouble-conversion.a</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p155272391619"><a name="p155272391619"></a><a name="p155272391619"></a>生成的静态库文件</p>
    </td>
    </tr>
    <tr id="row141820612910"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1941811618918"><a name="p1941811618918"></a><a name="p1941811618918"></a>double-conversion/build/test/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p64181761995"><a name="p64181761995"></a><a name="p64181761995"></a>目录下存放生成的测试用例和相关CMake缓存文件</p>
    </td>
    </tr>
    <tr id="row19525239815"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p452512394117"><a name="p452512394117"></a><a name="p452512394117"></a>double-conversion/build/CMakeCache.txt</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p652615391617"><a name="p652615391617"></a><a name="p652615391617"></a>CMake构建过程中的缓存文件</p>
    </td>
    </tr>
    <tr id="row1526839312"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p28017499413"><a name="p28017499413"></a><a name="p28017499413"></a>double-conversion/build/CMakeFiles/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p25261439314"><a name="p25261439314"></a><a name="p25261439314"></a>-</p>
    </td>
    </tr>
    <tr id="row15269396111"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p138014494415"><a name="p138014494415"></a><a name="p138014494415"></a>double-conversion/build/cmake_install.cmake</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p75268391519"><a name="p75268391519"></a><a name="p75268391519"></a>-</p>
    </td>
    </tr>
    <tr id="row185265399113"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p78054914419"><a name="p78054914419"></a><a name="p78054914419"></a>double-conversion/build/CTestTestfile.cmake</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p65261039218"><a name="p65261039218"></a><a name="p65261039218"></a>-</p>
    </td>
    </tr>
    <tr id="row125261139115"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p158064916419"><a name="p158064916419"></a><a name="p158064916419"></a>double-conversion/build/DartConfiguration.tcl</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p20526939118"><a name="p20526939118"></a><a name="p20526939118"></a>-</p>
    </td>
    </tr>
    <tr id="row2526839712"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6803491043"><a name="p6803491043"></a><a name="p6803491043"></a>double-conversion/build/generated/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p115269395113"><a name="p115269395113"></a><a name="p115269395113"></a>-</p>
    </td>
    </tr>
    <tr id="row173131653454"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7803493412"><a name="p7803493412"></a><a name="p7803493412"></a>double-conversion/build/Makefile</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p19316135318512"><a name="p19316135318512"></a><a name="p19316135318512"></a>-</p>
    </td>
    </tr>
    <tr id="row4380879618"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p10381478619"><a name="p10381478619"></a><a name="p10381478619"></a>double-conversion/build/Testing/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17381679610"><a name="p17381679610"></a><a name="p17381679610"></a>-</p>
    </td>
    </tr>
    </tbody>
    </table>


## 测试<a name="section6686144293611"></a>

1.  搭建OpenHarmony环境

    以hi3516ev300为例，编译出OpenHarmony镜像，烧写到开发板，参考[开发Hi3516第一个示例程序](../quick-start/quickstart-ide-lite-steps-hi3516-running.md)。

    进入系统如下所示：

    **图 1**  OpenHarmony启动成功界面<a name="fig13279524162418"></a>  
    ![](figure/OpenHarmony启动成功界面.png "OpenHarmony启动成功界面")

2.  挂载nfs目录，将[表2](#table1452412391911)中test目录下cctest可执行文件放入nfs目录
3.  执行用例

    该库采用非交叉编译时用例是通过make test执行，CMake会有相关的执行结果统计；交叉编译时无法使用该方法，因此可直接执行生成的测试文件完成测试。

    -   挂载成功后执行下列命令可列出用例所有条目：

    ```
    cd nfs
    ./cctest --list
    ```

    上述命令执行结果部分展示：

    ```
    test-bignum/Assign<
    test-bignum/ShiftLeft<
    test-bignum/AddUInt64<
    test-bignum/AddBignum<
    test-bignum/SubtractBignum<
    test-bignum/MultiplyUInt32<
    test-bignum/MultiplyUInt64<
    test-bignum/MultiplyPowerOfTen<
    test-bignum/DivideModuloIntBignum<
    test-bignum/Compare<
    test-bignum/PlusCompare<
    test-bignum/Square<
    test-bignum/AssignPowerUInt16<
    test-bignum-dtoa/BignumDtoaVariousDoubles<
    test-bignum-dtoa/BignumDtoaShortestVariousFloats<
    test-bignum-dtoa/BignumDtoaGayShortest<
    test-bignum-dtoa/BignumDtoaGayShortestSingle<
    test-bignum-dtoa/BignumDtoaGayFixed<
    test-bignum-dtoa/BignumDtoaGayPrecision<
    test-conversions/DoubleToShortest<
    test-conversions/DoubleToShortestSingle<
    ...
    ```

    -   以test-bignum条目为例，执行下列命令开始测试：

    ```
    ./cctest test-bignum
    ```

    测试结果如下则表示通过：

    ```
    Ran 13 tests.
    ```


## 将该库编译添加到OpenHarmony工程中<a name="section1651053153715"></a>

1.  复制库到OpenHarmony工程中

    拷贝已经能够成功交叉编译的库到OpenHarmony的third\_party目录，为了不修改要移植的三方库目录下的BUILD.gn文件，再添加一层目录放置新增的gn转CMake编译适配文件，新增的文件有BUILD.gn、build\_thirdparty.py、 config.gni，新增后的目录结构如下所示。

    **表 3**  添加到工程后的目录结构

    <a name="table13265185817173"></a>
    <table><thead align="left"><tr id="row92666583171"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p2266105816178"><a name="p2266105816178"></a><a name="p2266105816178"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p32661158161718"><a name="p32661158161718"></a><a name="p32661158161718"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1526655816175"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p226605811710"><a name="p226605811710"></a><a name="p226605811710"></a>openHarmony/third_party/double-conversion/BUILD.gn</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1626675812177"><a name="p1626675812177"></a><a name="p1626675812177"></a>将三方库加入工程的gn适配文件</p>
    </td>
    </tr>
    <tr id="row1726610589179"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12266115815170"><a name="p12266115815170"></a><a name="p12266115815170"></a>openHarmony/third_party/double-conversion/build_thirdparty.py</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p122661958201719"><a name="p122661958201719"></a><a name="p122661958201719"></a>GN调用shell命令脚本文件，由上面GN文件将相关命令传入，实现GN转CMake</p>
    </td>
    </tr>
    <tr id="row7266195891714"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p162665581170"><a name="p162665581170"></a><a name="p162665581170"></a>openHarmony/third_party/double-conversion/config.gni</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p626712588175"><a name="p626712588175"></a><a name="p626712588175"></a>三方库编译配置文件，可修改该文件来配置用例是否参与构建等</p>
    </td>
    </tr>
    <tr id="row1272420109203"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17725101052012"><a name="p17725101052012"></a><a name="p17725101052012"></a>openHarmony/third_party/double-conversion/double-conversion/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p87252109205"><a name="p87252109205"></a><a name="p87252109205"></a>要移植的三方库目录</p>
    </td>
    </tr>
    </tbody>
    </table>

2.  添加gn到CMake适配文件

    -   **新增的BUILD.gn文件实现如下，其他采用CMake方式可独立编译的三方库移植到OpenHarmony平台时只需修改路径即可**。

    ```
    import("config.gni")
    group("double-conversion") {
        if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
            deps = [":make"]
        }
    }
    if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
        action("make") {
            script = "//third_party/double-conversion/build_thirdparty.py"
            outputs = ["$root_out_dir/log_dc.txt"]
            exec_path = rebase_path(rebase_path("./build", ohos_third_party_dir))
            command = "rm * .* -rf && $CMAKE_TOOLS_PATH/cmake .. $CMAKE_FLAG $CMAKE_TOOLCHAIN_FLAG && make -j"
            args = [
                "--path=$exec_path",
                "--command=${command}"
            ]
        }
    }
    ```

    -   **新增的config.gni用于配置该库，实现如下，其他采用CMake方式可独立编译的三方库移植到OpenHarmony时只需修改CMAKE\_FLAG的配置即可。**

    ```
    #CMAKE_FLAG: config compile feature
    CMAKE_FLAG = "-DBUILD_TESTING=ON -DCMAKE_CXX_STANDARD=11"
    
    #toolchain：follow up-layer，depend on $ohos_build_compiler
    if (ohos_build_compiler == "clang") {
        CMAKE_TOOLCHAIN_FLAG = "-DOHOS_SYSROOT_PATH=${ohos_root_path}prebuilts/lite/sysroot/"
    } else {
        CMAKE_TOOLCHAIN_FLAG = ""
    }
    
    #CMake tools path,no need setting if this path already joined to $PATH.
    CMAKE_TOOLS_PATH = "setting CMake tools path..."
    ```

    -   **新增的build\_thirdparty.py实现如下，其他采用CMake方式可独立编译的三方库移植到OpenHarmony时无需修改即可使用。**

    ```
    import os
    import sys
    from subprocess import Popen
    import argparse
    import shlex
    
    def cmd_exec(command):
        cmd = shlex.split(command)
        proc = Popen(cmd)
        proc.wait()
        ret_code = proc.returncode
        if ret_code != 0:
            raise Exception("{} failed, return code is {}".format(cmd, ret_code))
    
    def main():
        parser = argparse.ArgumentParser()
        parser.add_argument('--path', help='Build path.')
        parser.add_argument('--command', help='Build command.')
        parser.add_argument('--enable', help='enable python.', nargs='*')
        args = parser.parse_args()
    
        if args.enable:
            if args.enable[0] == 'false':
                return
    
        if args.path:
            curr_dir = os.getcwd()
            os.chdir(args.path)
            if args.command:
                if '&&' in args.command:
                    command = args.command.split('&&')
                    for data in command:
                        cmd_exec(data)
                else:
                    cmd_exec(args.command)
            os.chdir(curr_dir)
    
    if __name__ == '__main__':
        sys.exit(main())
    ```

    -   在配置文件中添加开关控制该库编译，默认设为关闭

    在//build/lite/ohos\_var.gni文件中添加下列配置：

    ```
    declare_args() {
        ohos_build_thirdparty_migrated_from_fuchisa = true
    }
    ```

3.  编译构建

    -   手动单独构建：

    执行下列命令

    ```
    hb build -T //third_party/double-conversion:double-conversion
    ```

    编译成功则[build](#li15717101715249)目录下会生成静态库文件和测试用例


