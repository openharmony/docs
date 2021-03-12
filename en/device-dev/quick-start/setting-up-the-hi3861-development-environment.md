# Setting Up the Hi3861 Development Environment<a name="EN-US_TOPIC_0000001054781998"></a>

-   [Prerequisites](#section2074878255)
-   [Requirements Specific to the Hi3861 Development Environment](#section466851916410)
-   [Installing the Linux Compilation Environment](#section497484245614)
    -   [Installing Scons](#section13515123015279)
    -   [Installing gcc\_riscv32 \(Compilation Toolchain for WLAN Module\)](#section1842910288284)


>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>This section describes how to use an installation package to set up the compilation and building environment. If you are going to use Docker to set up the environment, the Linux server-related tools SCons 3.0.4+ and build-essential are not required, and you only need to install the Windows workstation.

## Prerequisites<a name="section2074878255"></a>

You must complete the settings in  [Basic OS Environment Setup](basic-os-environment-setup.md).

## Requirements Specific to the Hi3861 Development Environment<a name="section466851916410"></a>

The following table describes the environment configuration requirements specific to the Hi3861 development board.

**Table  1**  Hi3861 development environment-specific requirements

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
<tbody><tr id="row1397335913612"><td class="cellrowborder" valign="top" width="17.54%" headers="mcps1.2.5.1.1 "><p id="p3711468218"><a name="p3711468218"></a><a name="p3711468218"></a>Linux server</p>
</td>
<td class="cellrowborder" valign="top" width="19.89%" headers="mcps1.2.5.1.2 "><p id="p097355911620"><a name="p097355911620"></a><a name="p097355911620"></a>SCons 3.0.4+</p>
</td>
<td class="cellrowborder" valign="top" width="26.279999999999998%" headers="mcps1.2.5.1.3 "><p id="p1973195917619"><a name="p1973195917619"></a><a name="p1973195917619"></a>Executes script compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="36.29%" headers="mcps1.2.5.1.4 "><p id="p1722663441514"><a name="p1722663441514"></a><a name="p1722663441514"></a>Internet</p>
</td>
</tr>
<tr id="row1463517494402"><td class="cellrowborder" valign="top" width="17.54%" headers="mcps1.2.5.1.1 "><p id="p137174662119"><a name="p137174662119"></a><a name="p137174662119"></a>Linux server</p>
</td>
<td class="cellrowborder" valign="top" width="19.89%" headers="mcps1.2.5.1.2 "><p id="p258814561424"><a name="p258814561424"></a><a name="p258814561424"></a>build-essential</p>
</td>
<td class="cellrowborder" valign="top" width="26.279999999999998%" headers="mcps1.2.5.1.3 "><p id="p1749611716181"><a name="p1749611716181"></a><a name="p1749611716181"></a>Provides basic software package for compilation.</p>
</td>
<td class="cellrowborder" valign="top" width="36.29%" headers="mcps1.2.5.1.4 "><p id="p8635174916403"><a name="p8635174916403"></a><a name="p8635174916403"></a>Internet</p>
</td>
</tr>
<tr id="row1596703610215"><td class="cellrowborder" valign="top" width="17.54%" headers="mcps1.2.5.1.1 "><p id="p071946112113"><a name="p071946112113"></a><a name="p071946112113"></a>Windows workstation</p>
</td>
<td class="cellrowborder" valign="top" width="19.89%" headers="mcps1.2.5.1.2 "><p id="p1044974291416"><a name="p1044974291416"></a><a name="p1044974291416"></a>CH341SER.EXE</p>
</td>
<td class="cellrowborder" valign="top" width="26.279999999999998%" headers="mcps1.2.5.1.3 "><p id="p94491342131413"><a name="p94491342131413"></a><a name="p94491342131413"></a>USB-to-Serial adapter driver</p>
</td>
<td class="cellrowborder" valign="top" width="36.29%" headers="mcps1.2.5.1.4 "><p id="p6449184214148"><a name="p6449184214148"></a><a name="p6449184214148"></a><a href="http://www.wch-ic.com/downloads/CH341SER_EXE.html" target="_blank" rel="noopener noreferrer">http://www.wch-ic.com/downloads/CH341SER_EXE.html</a></p>
</td>
</tr>
</tbody>
</table>

## Installing the Linux Compilation Environment<a name="section497484245614"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>-   If you acquire the source code using an HPM component or HPM CLI tool,  **gcc\_riscv32**  is not required.
>-   \(Recommended\) If you obtain the source code via the mirror site or code repository, install  **gcc\_riscv32**. When installing  **gcc\_riscv32**, ensure that the environment variable paths of the compilation tools are unique.

### Installing Scons<a name="section13515123015279"></a>

1.  Start a Linux server.
2.  Install the SCons installation package.

    ```
    sudo apt-get install scons -y
    ```

    If the installation package cannot be found in the software source, do as follows:

    1.  Download the source code package from  [https://scons.org/pages/download.html](https://scons.org/pages/download.html). The recommended SCons version is 3.0.4 or later.
    2.  Decompress the source code package to any directory, for example, scons-3.1.2.

        ```
        tar -xvf scons-3.1.2.tar.gz
        ```

    3.  Go to the source code directory and run the following command to install the source code package:

        ```
        sudo python3 setup.py install
        ```


3.  Check whether the installation is successful.

    ```
    scons -v
    ```

    **Figure  1**  Successful installation<a name="fig235815252492"></a>  
    ![](figures/successful-installation.png "successful-installation")


### Installing gcc\_riscv32 \(Compilation Toolchain for WLAN Module\)<a name="section1842910288284"></a>

>![](public_sys-resources/icon-notice.gif) **NOTICE:** 
>The Hi3861 platform supports only the static link of the libgcc library. The dynamic link is not recommended because version 3 of the GNU General Public License \(GPLv3\) will be polluted during commercial distribution.

1.  Start a Linux server.
2.  Install the  **GCC**,  **G++**,  **Bison**,  **Flex**,  **Makeinfo**  tools to ensure that the toolchain can be correctly compiled.

    ```
    sudo apt-get install gcc && sudo apt-get install g++ && sudo apt-get install flex bison && sudo apt-get install texinfo
    ```

3.  Download the RISC-V GNU toolchain.

    ```
    git clone --recursive https://github.com/riscv/riscv-gnu-toolchain
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

13. Build  **Bintutils**.

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


