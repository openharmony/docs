# Setting Up the Environment<a name="EN-US_TOPIC_0000001105989316"></a>

-   [Environment Requirements](#section466851916410)
    -   [Hardware](#section19202111020215)
    -   [Software](#section727451210318)

-   [Install Linux Build Tools](#section497484245614)
    -   [Installing Basic Software Used for Compilation and Building \(Required Only for Ubuntu 20+\)](#section45512412251)
    -   [Installing Scons](#section7438245172514)
    -   [Installing Python Modules](#section88701892341)
    -   [Installing gcc\_riscv32 \(Compilation Toolchain for WLAN Module\)](#section34435451256)

-   [Installing the USB-to-Serial Driver](#section1027732411513)

## Environment Requirements<a name="section466851916410"></a>

### Hardware<a name="section19202111020215"></a>

-   Linux compile server
-   Windows workstation \(host computer\)
-   Hi3861 WLAN module
-   USB Type-C cable used to connect the Windows workstation to Hi3861 WLAN module

The following figure shows the hardware connections.

**Figure  1**  Hardware connections<a name="fig12122108211"></a>  
![](figures/hardware-connections.png "hardware-connections")

### Software<a name="section727451210318"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>The following part describes how to install tools using installation packages. If you use Docker to set up the build environment, you only need to install the Windows workstation described in  [Table 1](#table6299192712513).

The following table lists the tools required for the Hi3861 development board.

**Table  1**  Required tools

<a name="table6299192712513"></a>
<table><thead align="left"><tr id="row122993276512"><th class="cellrowborder" valign="top" width="17.54%" id="mcps1.2.5.1.1"><p id="p162491657102110"><a name="p162491657102110"></a><a name="p162491657102110"></a>Platform</p>
</th>
<th class="cellrowborder" valign="top" width="19.89%" id="mcps1.2.5.1.2"><p id="p1829914271858"><a name="p1829914271858"></a><a name="p1829914271858"></a>Development Tool</p>
</th>
<th class="cellrowborder" valign="top" width="26.279999999999998%" id="mcps1.2.5.1.3"><p id="p429918274517"><a name="p429918274517"></a><a name="p429918274517"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="36.29%" id="mcps1.2.5.1.4"><p id="p12997271757"><a name="p12997271757"></a><a name="p12997271757"></a>How to Obtain</p>
</th>
</tr>
</thead>
<tbody><tr id="row935218593572"><td class="cellrowborder" valign="top" width="17.54%" headers="mcps1.2.5.1.1 "><p id="p105554418586"><a name="p105554418586"></a><a name="p105554418586"></a>Linux server</p>
</td>
<td class="cellrowborder" valign="top" width="19.89%" headers="mcps1.2.5.1.2 "><p id="p45551740589"><a name="p45551740589"></a><a name="p45551740589"></a>Basic software package for compilation and building (required only for Ubuntu 20+)</p>
</td>
<td class="cellrowborder" valign="top" width="26.279999999999998%" headers="mcps1.2.5.1.3 "><p id="p655594115814"><a name="p655594115814"></a><a name="p655594115814"></a>Provides a basic software package for compilation and building.</p>
</td>
<td class="cellrowborder" valign="top" width="36.29%" headers="mcps1.2.5.1.4 "><p id="p165558415589"><a name="p165558415589"></a><a name="p165558415589"></a>Internet</p>
</td>
</tr>
<tr id="row1397335913612"><td class="cellrowborder" valign="top" width="17.54%" headers="mcps1.2.5.1.1 "><p id="p3711468218"><a name="p3711468218"></a><a name="p3711468218"></a>Linux server</p>
</td>
<td class="cellrowborder" valign="top" width="19.89%" headers="mcps1.2.5.1.2 "><p id="p097355911620"><a name="p097355911620"></a><a name="p097355911620"></a>SCons 3.0.4+</p>
</td>
<td class="cellrowborder" valign="top" width="26.279999999999998%" headers="mcps1.2.5.1.3 "><p id="p1973195917619"><a name="p1973195917619"></a><a name="p1973195917619"></a>Executes script compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="36.29%" headers="mcps1.2.5.1.4 "><p id="p1722663441514"><a name="p1722663441514"></a><a name="p1722663441514"></a>Internet</p>
</td>
</tr>
<tr id="row1968013216717"><td class="cellrowborder" valign="top" width="17.54%" headers="mcps1.2.5.1.1 "><p id="p2681632977"><a name="p2681632977"></a><a name="p2681632977"></a>Linux server</p>
</td>
<td class="cellrowborder" valign="top" width="19.89%" headers="mcps1.2.5.1.2 "><p id="p1991501391312"><a name="p1991501391312"></a><a name="p1991501391312"></a>Python modules: setuptools, Kconfiglib, PyCryptodome, six, and ecdsa</p>
</td>
<td class="cellrowborder" valign="top" width="26.279999999999998%" headers="mcps1.2.5.1.3 "><p id="p968120325715"><a name="p968120325715"></a><a name="p968120325715"></a>Executes script compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="36.29%" headers="mcps1.2.5.1.4 "><p id="p268116326711"><a name="p268116326711"></a><a name="p268116326711"></a>Internet</p>
</td>
</tr>
<tr id="row020914491313"><td class="cellrowborder" valign="top" width="17.54%" headers="mcps1.2.5.1.1 "><p id="p20209749103116"><a name="p20209749103116"></a><a name="p20209749103116"></a>Linux server</p>
</td>
<td class="cellrowborder" valign="top" width="19.89%" headers="mcps1.2.5.1.2 "><p id="p7209104910317"><a name="p7209104910317"></a><a name="p7209104910317"></a>gcc riscv32</p>
</td>
<td class="cellrowborder" valign="top" width="26.279999999999998%" headers="mcps1.2.5.1.3 "><p id="p102093498311"><a name="p102093498311"></a><a name="p102093498311"></a>Executes script compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="36.29%" headers="mcps1.2.5.1.4 "><p id="p321054953116"><a name="p321054953116"></a><a name="p321054953116"></a>Internet</p>
</td>
</tr>
<tr id="row1596703610215"><td class="cellrowborder" valign="top" width="17.54%" headers="mcps1.2.5.1.1 "><p id="p071946112113"><a name="p071946112113"></a><a name="p071946112113"></a>Windows workstation</p>
</td>
<td class="cellrowborder" valign="top" width="19.89%" headers="mcps1.2.5.1.2 "><p id="p1044974291416"><a name="p1044974291416"></a><a name="p1044974291416"></a>CH341SER.EXE</p>
</td>
<td class="cellrowborder" valign="top" width="26.279999999999998%" headers="mcps1.2.5.1.3 "><p id="p94491342131413"><a name="p94491342131413"></a><a name="p94491342131413"></a>USB-to-Serial adapter driver</p>
</td>
<td class="cellrowborder" valign="top" width="36.29%" headers="mcps1.2.5.1.4 "><p id="p6449184214148"><a name="p6449184214148"></a><a name="p6449184214148"></a><a href="http://www.wch-ic.com/search?t=downloads&amp;q=ch340g" target="_blank" rel="noopener noreferrer">http://www.wch-ic.com/search?t=downloads&amp;q=ch340g</a></p>
</td>
</tr>
</tbody>
</table>

## Install Linux Build Tools<a name="section497484245614"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   If you acquire the source code using an HPM component or HPM CLI tool, you do not need to install  **gcc\_riscv32**.
>-   \(Recommended\) If you obtain the source code via the mirror site or code repository, install  **gcc\_riscv32**. When installing the compilation tool, ensure that its environment variable path is unique.

### Installing Basic Software Used for Compilation and Building \(Required Only for Ubuntu 20+\)<a name="section45512412251"></a>

Install the software.

```
sudo apt-get install build-essential && sudo apt-get install gcc && sudo apt-get install g++ && sudo apt-get install make && sudo apt-get install zlib* && sudo apt-get install libffi-dev
```

### Installing Scons<a name="section7438245172514"></a>

1.  Start a Linux server.
2.  Install the SCons installation package.

    ```
    python3 -m pip install scons
    ```

3.  Check whether the installation is successful.

    ```
    scons -v
    ```

    **Figure  2**  Successful installation \(SCons version requirement: 3.0.4 or later\)<a name="fig235815252492"></a>  
    ![](figures/successful-installation-(scons-version-requirement-3-0-4-or-later).png "successful-installation-(scons-version-requirement-3-0-4-or-later)")


### Installing Python Modules<a name="section88701892341"></a>

1.  Install setuptools.

    ```
    pip3 install setuptools
    ```

2.  Install the GUI menuconfig tool \(Kconfiglib\). You are advised to install Kconfiglib 13.2.0 or later.
    -   **Command line:**

        ```
        sudo pip3 install kconfiglib
        ```


    -   **Installation package:**
        1.  Download the  **.whl**  file \(for example,  **kconfiglib-13.2.0-py2.py3-none-any.whl**\).

            Download path:  [https://pypi.org/project/kconfiglib\#files](https://pypi.org/project/kconfiglib#files)


        1.  Install the  **.whl**  file.

            ```
            sudo pip3 install kconfiglib-13.2.0-py2.py3-none-any.whl
            ```



3.  Install  **PyCryptodome**  using either of the following methods:

    Install the Python component packages on which the file signature depends, including PyCryptodome, six, and ecdsa. As the installation of  **ecdsa**  depends on that of  **six**, install  **six**  first.

    -   **Command line:**

        ```
        sudo pip3 install pycryptodome
        ```

    -   **Installation package:**
        1.  Download the  **.whl**  file \(for example,  **pycryptodome-3.9.9-cp38-cp38-manylinux1\_x86\_64.whl**\).

            Download path:  [https://pypi.org/project/pycryptodome/\#files](https://pypi.org/project/pycryptodome/#files)


        1.  Install the  **.whl**  file.

            ```
            sudo pip3 install pycryptodome-3.9.9-cp38-cp38-manylinux1_x86_64.whl
            ```



4.  Install  **six**  using either of the following methods:
    -   **Command line:**

        ```
        sudo pip3 install six --upgrade --ignore-installed six
        ```


    -   **Installation package:**
        1.  Download the  **.whl**  file, for example,  **six-1.12.0-py2.py3-none-any.whl**.

            Download path:  [https://pypi.org/project/six/\#files](https://pypi.org/project/six/#files)


        1.  Install the  **.whl**  file.

            ```
            sudo pip3 install six-1.12.0-py2.py3-none-any.whl
            ```



5.  Install  **ecdsa**  using either of the following methods:
    -   **Command line:**

        ```
        sudo pip3 install ecdsa
        ```

    -   **Installation package:**
        1.  Download the  **.whl**  file, for example,  **ecdsa-0.14.1-py2.py3-none-any.whl**.

            Download path:  [https://pypi.org/project/ecdsa/\#files](https://pypi.org/project/ecdsa/#files)


        1.  Install the  **.whl**  file.

            ```
            sudo pip3 install ecdsa-0.14.1-py2.py3-none-any.whl
            ```




### Installing gcc\_riscv32 \(Compilation Toolchain for WLAN Module\)<a name="section34435451256"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   The Hi3861 platform supports only the static link of the libgcc library. The dynamic link is not recommended because version 3 of the GNU General Public License \(GPLv3\) will be polluted during commercial distribution.
>-   Steps 2 to 15 of the following procedure are used to build the  **gcc\_riscv32**  image. You can simply  [download the image](https://repo.huaweicloud.com/harmonyos/compiler/gcc_riscv32/7.3.0/linux/gcc_riscv32-linux-7.3.0.tar.gz)  and skip these steps.

1.  Start a Linux server.
2.  Install the  **GCC**,  **G++**,  **Bison**,  **Flex**,  **Makeinfo**  tools to ensure that the toolchain can be correctly compiled.

    ```
    sudo apt-get install gcc && sudo apt-get install g++ && sudo apt-get install flex bison && sudo apt-get install texinfo
    ```

3.  Download the RISC-V GNU toolchain.

    ```
    git clone --recursive https://gitee.com/mirrors/riscv-gnu-toolchain.git
    ```

4.  Open the  **riscv-gnu-toolchain**  folder and delete empty folders to prevent conflicts during the download of  **Newlib**,  **Binutils**, and  **GCC**.

    ```
    cd riscv-gnu-toolchain && rm -rf riscv-newlib && rm -rf riscv-binutils && rm -rf riscv-gcc
    ```

5.  Download RISC-V Newlib 3.0.0.

    ```
    git clone -b riscv-newlib-3.0.0 https://github.com/riscv/riscv-newlib.git
    ```

6.  Download RISC-V Binutils 2.31.1.

    ```
    git clone -b riscv-binutils-2.31.1 https://github.com/riscv/riscv-binutils-gdb.git
    ```

7.  Download RISC-V GCC 7.3.0.

    ```
    git clone -b riscv-gcc-7.3.0 https://github.com/riscv/riscv-gcc
    ```

8.  Add the RISC-V GCC 7.3.0 patch.

    Visit the GCC official patch links  [89411](https://gcc.gnu.org/git/?p=gcc.git;a=commitdiff;h=026216a753ef0a757a9e368a59fa667ea422cf09;hp=2a23a1c39fb33df0277abd4486a3da64ae5e62c2)  and  [86724](https://gcc.gnu.org/git/?p=gcc.git;a=blobdiff;f=gcc/graphite.h;h=be0a22b38942850d88feb159603bb846a8607539;hp=4e0e58c60ab83f1b8acf576e83330466775fac17;hb=b1761565882ed6a171136c2c89e597bc4dd5b6bf;hpb=fbd5f023a03f9f60c6ae36133703af5a711842a3), and manually add the changes to the .c and .h files based on the requirements in the patch links. Note that the number of rows may not match because of different versions of the patch and GCC. You need to search for the keyword in the patch to locate the corresponding row.

9.  Download, decompress, and install  [GMP 6.1.2](https://gmplib.org/download/gmp/gmp-6.1.2.tar.bz2).

    ```
    tar -xvf gmp-6.1.2.tar.bz2 && mkdir build_gmp && cd build_gmp && ../gmp-6.1.2/configure --prefix=/usr/local/gmp-6.1.2 --disable-shared --enable-cxx && make && make install
    ```

10. Download, decompress, and install  [mpfr-4.0.2](https://www.mpfr.org/mpfr-4.0.2/mpfr-4.0.2.tar.gz).

    ```
    tar -xvf mpfr-4.0.2.tar.gz && mkdir build_mpfr && cd build_mpfr && ../mpfr-4.0.2/configure --prefix=/usr/local/mpfr-4.0.2 --with-gmp=/usr/local/gmp-6.1.2 --disable-shared && make && make install
    ```

11. Download, decompress, and install  [mpc-1.1.0](https://ftp.gnu.org/gnu/mpc/mpc-1.1.0.tar.gz).

    ```
    tar -xvf mpc-1.1.0.tar.gz && mkdir build_mpc && cd build_mpc && ../mpc-1.1.0/configure --prefix=/usr/local/mpc-1.1.0 --with-gmp=/usr/local/gmp-6.1.2 --with-mpfr=/usr/local/mpfr-4.0.2 --disable-shared && make && make install
    ```

12. Open the  **riscv-gnu-toolchain**  folder and create a directory for toolchain output.

    ```
    cd /opt && mkdir gcc_riscv32
    ```

13. Compile  **binutils**.

    ```
    mkdir build_binutils && cd build_binutils && ../riscv-binutils-gdb/configure --prefix=/opt/gcc_riscv32 --target=riscv32-unknown-elf --with-arch=rv32imc --with-abi=ilp32 --disable-__cxa_atexit --disable-libgomp --disable-libmudflap --enable-libssp --disable-libstdcxx-pch --disable-nls --disable-shared --disable-threads --disable-multilib --enable-poison-system-directories --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --with-system-zlib CFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" CFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" --bindir=/opt/gcc_riscv32/bin --libexecdir=/opt/gcc_riscv32/riscv32 --libdir=/opt/gcc_riscv32 --includedir=/opt/gcc_riscv32 && make -j16 && make install && cd ..
    ```

14. Build  **Newlib**.

    ```
    mkdir build_newlib && cd build_newlib && ../riscv-newlib/configure --prefix=/opt/gcc_riscv32 --target=riscv32-unknown-elf --with-arch=rv32imc --with-abi=ilp32 --disable-__cxa_atexit --disable-libgomp --disable-libmudflap --enable-libssp --disable-libstdcxx-pch --disable-nls --disable-shared --disable-threads --disable-multilib --enable-poison-system-directories --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --with-system-zlib CFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" \CXXFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" CFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" --bindir=/opt/gcc_riscv32/bin --libexecdir=/opt/gcc_riscv32 --libdir=/opt/gcc_riscv32 --includedir=/opt/gcc_riscv32 && make -j16 && make install && cd ..
    ```

15. Build  **GCC**.

    ```
    mkdir build_gcc && cd build_gcc && ../riscv-gcc/configure --prefix=/opt/gcc_riscv32 --target=riscv32-unknown-elf --with-arch=rv32imc --with-abi=ilp32 --disable-__cxa_atexit --disable-libgomp --disable-libmudflap --enable-libssp --disable-libstdcxx-pch --disable-nls --disable-shared --disable-threads --disable-multilib --enable-poison-system-directories --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --with-system-zlib CFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" LDFLAGS="-Wl,-z,relro,-z,now,-z,noexecstack" CXXFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" CFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" --with-headers="/opt/gcc-riscv32/riscv32-unknown-elf/include" --with-mpc=/usr/local/mpc-1.1.0 --with-gmp=/usr/local/gmp-6.1.2 --with-mpfr=/usr/local/mpfr-4.0.2 && make -j16 && make install
    ```

16. Set an environment variable.

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >If you use the compiled  **riscv32 gcc**  package, perform the following steps to set environment variables:
    >1.  Decompress the package to the root directory.
    >    ```
    >    tar -xvf gcc_riscv32-linux-7.3.0.tar.gz -C /opt
    >    ```
    >2.  Set an environment variable.
    >    ```
    >    vim ~/.bashrc
    >    ```
    >3.  Copy the following command to the last line of the  **.bashrc**  file, save the file, and exit.
    >    ```
    >    export PATH=/opt/gcc_riscv32/bin:$PATH
    >    ```

    ```
    vim ~/.bashrc
    ```

    Copy the following command to the last line of the  **.bashrc**  file, save the file, and exit.

    ```
    export PATH=/opt/gcc_riscv32/bin:$PATH
    ```

17. Validate the environment variable.

    ```
    source ~/.bashrc
    ```

18. Check whether the compiler is successfully installed. If the compiler version number is correctly displayed, the installation is successful.

    ```
    riscv32-unknown-elf-gcc -v
    ```


## Installing the USB-to-Serial Driver<a name="section1027732411513"></a>

Perform the following operations on the Windows station.

1.  Download the USB-to-serial driver:  [CH341SER USB-to-serial driver](http://www.wch-ic.com/search?t=all&q=CH340g).
2.  Install the driver.
3.  After the driver is installed, remove and then insert the USB cable. The serial port entry should be displayed as shown in the following figure.

    ![](figures/en-us_image_0000001057235392.png)


