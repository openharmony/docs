# Porting a Library Built Using Makefile<a name="EN-US_TOPIC_0000001154372572"></a>

The following shows how to port the yxml library.

## Source Code Acquisition<a name="section114115321416"></a>

Acquire the source code of yxml from  [the open-source repository](https://github.com/getdnsapi/yxml). The following table lists the directory structure.

**Table  1**  Directory structure of the source code

<a name="table16520154171813"></a>
<table><thead align="left"><tr id="row2052115419188"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1352111417181"><a name="p1352111417181"></a><a name="p1352111417181"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p2521541171812"><a name="p2521541171812"></a><a name="p2521541171812"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row252164101814"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p747319438225"><a name="p747319438225"></a><a name="p747319438225"></a>yxml/bench/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1852214114183"><a name="p1852214114183"></a><a name="p1852214114183"></a>Benchmark-related code</p>
</td>
</tr>
<tr id="row11402205216237"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6473134382216"><a name="p6473134382216"></a><a name="p6473134382216"></a>yxml/test/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2040355219237"><a name="p2040355219237"></a><a name="p2040355219237"></a>Input and output files as well as scripts of the test cases</p>
</td>
</tr>
<tr id="row35220418182"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1547384313229"><a name="p1547384313229"></a><a name="p1547384313229"></a>yxml/Makefile</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7522041131814"><a name="p7522041131814"></a><a name="p7522041131814"></a>File for organizing compilation</p>
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

## Cross-Compilation Settings<a name="section81263255384"></a>

The following steps show how to configure and modify the toolchains for cross-compiling the libraries built using CMake to compile executable files for the OpenHarmony platform.

1.  Configure the toolchains.

    Replace the original configuration of MakeFile \(listed in  [Table 1](#table16520154171813)\) in the root directory of the yxml library with the following clang toolchains configuration.

    clang toolchains configuration:

    ```
    # Set the cross-compilation toolchain and ensure that the path of the toolchain has been added to the PATH environment variable.
    CC:=clang
    AR:=llvm-ar
    # The --target and --sysroot flags must be specified.
    CFLAGS:=-Wall -Wextra -Wno-unused-parameter -O2 -g --target=arm-liteos -march=armv7-a --sysroot=$(OHOS_SYSROOT_PATH)
    ```

    Original configuration:

    ```
    CC:=gcc
    AR:=ar
    CFLAGS:=-Wall -Wextra -Wno-unused-parameter -O2 -g
    ```

2.  Perform the compilation.

    Run a Linux command to enter the directory \(listed in  [Table 1](#table16520154171813)\) for storing yxml source files and then run the following command:

    ```
    make test OHOS_SYSROOT_PATH=...
    ```

    **OHOS\_SYSROOT\_PATH**  specifies the absolute path of the directory where  **sysroot**  is located. For OpenHarmony, set  **OHOS\_SYSROOT\_PATH**  to the absolute path of the  **out/hispark\__xxx_/ipcamera\_hispark\__xxx_/sysroot**  directory. This directory is generated after full compilation is complete. Therefore, complete full compilation before porting.

3.  View the result.

    After step 2 is complete, a static library file and test case are generated in the  **out**  directory of the yxml library.

    **Table 2**  Directory structure of compiled files

    <a name="table3271115435618"></a>
    <table><thead align="left"><tr id="row1273454185610"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p3273154185616"><a name="p3273154185616"></a><a name="p3273154185616"></a>Directory</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p18273145445612"><a name="p18273145445612"></a><a name="p18273145445612"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1627317542567"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p13273154175620"><a name="p13273154175620"></a><a name="p13273154175620"></a>openHarmony/third_party/yxml/yxml/out/lib/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p132744541562"><a name="p132744541562"></a><a name="p132744541562"></a>Static library file</p>
    </td>
    </tr>
    <tr id="row112741554165612"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17274165475611"><a name="p17274165475611"></a><a name="p17274165475611"></a>openHarmony/third_party/yxml/yxml/out/test/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p152741354135614"><a name="p152741354135614"></a><a name="p152741354135614"></a>Test cases as well as the input and output files</p>
    </td>
    </tr>
    </tbody>
    </table>


## Library Test<a name="section1830015913391"></a>

The test procedure for the yxml library is similar to that for the double-conversion library. For details, see the procedure described in  [Porting a Library Built Using CMake](porting-thirdparty-cmake.md#section6686144293611). The following describes how to use the test cases of the yxml library.

**Table 3**  Directory structure of the test directory

<a name="table115941423164318"></a>
<table><thead align="left"><tr id="row1059515236433"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p55950233437"><a name="p55950233437"></a><a name="p55950233437"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p4595192324313"><a name="p4595192324313"></a><a name="p4595192324313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1759572304318"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17595323144319"><a name="p17595323144319"></a><a name="p17595323144319"></a>openHarmony/third_party/yxml/yxml/out/test/test.sh</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p25956235437"><a name="p25956235437"></a><a name="p25956235437"></a>Automatic test script, which cannot be used because <span id="text625264318457"><a name="text625264318457"></a><a name="text625264318457"></a>OpenHarmony</span> does not support automatic script execution. However, you can refer to this script to conduct a manual test.</p>
</td>
</tr>
<tr id="row155951823184312"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p659572313436"><a name="p659572313436"></a><a name="p659572313436"></a>openHarmony/third_party/yxml/yxml/out/test/test</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7595102314319"><a name="p7595102314319"></a><a name="p7595102314319"></a>Executable file for testing.</p>
</td>
</tr>
<tr id="row359619238437"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p205969232436"><a name="p205969232436"></a><a name="p205969232436"></a>openHarmony/third_party/yxml/yxml/out/test/*.xml</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p559662344315"><a name="p559662344315"></a><a name="p559662344315"></a>Input test file.</p>
</td>
</tr>
<tr id="row959613236439"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1159652312438"><a name="p1159652312438"></a><a name="p1159652312438"></a>openHarmony/third_party/yxml/yxml/out/test/*.out</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p18596182314318"><a name="p18596182314318"></a><a name="p18596182314318"></a>Expected output file.</p>
</td>
</tr>
</tbody>
</table>

The content of the  **test.sh**  file is as follows:

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

The shell of OpenHarmony does not support input and output redirection symbols \(< and \>\). During the test, you need to copy the content in the  **_\*_.xml**  file to the shell and press  **Enter**. The output content is displayed in the shell screen.

The following operations are performed based on the assumption that the OpenHarmony environment has been set up and the  **nfs**  directory has been mounted and accessed.

1.  Execute the following command:

    ```
    ./test
    ```

2.  Copy the content in the  **_\*_.xml**  file to shell.

    Taking the  **pi01.xml**  file in the  [test](#table115941423164318)  directory as an example, copy the following content to shell and press  **Enter**:

    ```
    <?SomePI abc?><a/>
    ```

3.  Check whether the output in the shell is the same as that of the  **_\*_.out**  file in the  [test](#table115941423164318)  directory.

    The output is as follows:

    ```
    pistart SomePI
    picontent abc
    piend
    elemstart a
    elemend
    ok
    ```

    The output is the same as the  **pi01.out**  file in the  [test](#table115941423164318)  directory. The test is passed.


## Adding the Compiled yxml Library to the OpenHarmony Project<a name="section1898016213406"></a>

The procedure for adding the yxml library is almost the same as that for adding the double-conversion library, except that the implementation of  **build.gn**  and  **config.gni**  files. For details, see the procedure described in  [Porting a Library Built Using CMake](porting-thirdparty-cmake.md#section1651053153715).

-   The implementation of the newly added  **BUILD.gn**  file in the yxml library is as follows:

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

-   The configuration of the newly added  **config.gni**  file in the yxml library is as follows:

```
TEST_ENABLE = "YES"

if (TEST_ENABLE == "YES") {
    MAKE_COMMAND = "make test OHOS_SYSROOT_PATH=${ohos_root_path}prebuilts/lite/sysroot/"
} else {
    MAKE_COMMAND = "make OHOS_SYSROOT_PATH=${ohos_root_path}prebuilts/lite/sysroot/"
}
```

-   The following table lists the directory structure of the OpenHarmony project.

**Table  4**  Directory structure of the ported library

<a name="table13265185817173"></a>
<table><thead align="left"><tr id="row92666583171"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p2266105816178"><a name="p2266105816178"></a><a name="p2266105816178"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p32661158161718"><a name="p32661158161718"></a><a name="p32661158161718"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1526655816175"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p226605811710"><a name="p226605811710"></a><a name="p226605811710"></a>openHarmony/third_party/yxml/BUILD.gn</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1626675812177"><a name="p1626675812177"></a><a name="p1626675812177"></a>GN file for adding the third-party library to the <span id="text1699851716117"><a name="text1699851716117"></a><a name="text1699851716117"></a>OpenHarmony</span> project</p>
</td>
</tr>
<tr id="row1726610589179"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12266115815170"><a name="p12266115815170"></a><a name="p12266115815170"></a>openHarmony/third_party/yxml/build_thirdparty.py</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p122661958201719"><a name="p122661958201719"></a><a name="p122661958201719"></a>Script file for GN to call the <strong id="b8482154111113"><a name="b8482154111113"></a><a name="b8482154111113"></a>shell</strong> command to convert compilation from GN to Makefile.</p>
</td>
</tr>
<tr id="row7266195891714"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p162665581170"><a name="p162665581170"></a><a name="p162665581170"></a>openHarmony/third_party/yxml/config.gni</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p626712588175"><a name="p626712588175"></a><a name="p626712588175"></a>Third-party library compilation configuration file, which can be modified to determine whether the test cases will be used during the building</p>
</td>
</tr>
<tr id="row1272420109203"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17725101052012"><a name="p17725101052012"></a><a name="p17725101052012"></a>openHarmony/third_party/yxml/yxml/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p87252109205"><a name="p87252109205"></a><a name="p87252109205"></a>Directory of the third-party library to be ported</p>
</td>
</tr>
</tbody>
</table>

