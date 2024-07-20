# Installing Tools Specially Required by the Hi3861 Development Board


In addition to the general [libraries and tools](quickstart-pkg-install-package.md) and [compilation tools](quickstart-pkg-install-tool.md), the Hi3861 development board requires the tools listed in this topic for source code building.


## Required Tools

  **Table 1** Tools required by the Hi3861 WLAN module

| Tool| Function| 
| -------- | -------- |
| SCons3.0.4+ | Executes script compilation.| 
| Python modules: setuptools, Kconfiglib, PyCryptodome, six, and ecdsa| Executes script compilation.| 
| gcc riscv32 | Executes script compilation.| 


## Procedure

Perform the following steps in Ubuntu.


### Installing Scons

1. Run the following command to install the SCons installation package:
   
   ```
   python3 -m pip install scons
   ```

2. Run the following command to check whether SCons is successfully installed. If the installation is successful, the query result as shown below is displayed.
   
   ```
   scons -v
   ```

     **Figure 1** Successful SCons installation (the version must be 3.0.4 or later) 

   ![hi3861-scons-install-success](figures/hi3861-scons-install-success.png)


### Installing Python Modules

1. Install setuptools.
   
   ```
   pip3 install setuptools
   ```

2. Install the GUI menuconfig tool (Kconfiglib). You are advised to install Kconfiglib 13.2.0 or later.

   - **Command line:**
     
      ```
      sudo pip3 install kconfiglib
      ```
   - **Installation package:**
      1. Download the .whl file, for example, **kconfiglib-13.2.0-py2.py3-none-any.whl**.
          Download path: [https://pypi.org/project/kconfiglib#files](https://pypi.org/project/kconfiglib#files)
      2. Install the .whl file.
         
          ```
          sudo pip3 install kconfiglib-13.2.0-py2.py3-none-any.whl
          ```

3. Install PyCryptodome using either of the following methods:
     
   Install the Python component packages on which the file signature depends, including **PyCryptodome**, **six**, and **ecdsa**. As the installation of **ecdsa** depends on that of **six**, install **six** first.
   - **Command line:**
     
     ```
     sudo pip3 install pycryptodome
     ```
   
   - **Installation package:**
     1. Download the .whl file, for example, **pycryptodome-3.9.9-cp38-cp38-manylinux1_x86_64.whl**.
         Download path: [https://pypi.org/project/pycryptodome/#files](https://pypi.org/project/pycryptodome/#files)
     2. Install the .whl file.
        
         ```
         sudo pip3 install pycryptodome-3.9.9-cp38-cp38-manylinux1_x86_64.whl
         ```

4. Install **six** using either of the following methods:
   - **Command line:**
     
      ```
      sudo pip3 install six --upgrade --ignore-installed six
      ```
   - **Installation package:**
      1. Download the .whl file, for example, **six-1.12.0-py2.py3-none-any.whl**.
          Download path: [https://pypi.org/project/six/#files](https://pypi.org/project/six/#files)
      2. Install the .whl file.
         
          ```
          sudo pip3 install six-1.12.0-py2.py3-none-any.whl
          ```

5. Install **ecdsa** using either of the following methods:
   - **Command line:**
     
      ```
      sudo pip3 install ecdsa
      ```
   - **Installation package:**
      1. Download the .whl file, for example, **ecdsa-0.14.1-py2.py3-none-any.whl**.
          Download path: [https://pypi.org/project/ecdsa/#files](https://pypi.org/project/ecdsa/#files)
      2. Install the .whl file.
         
          ```
          sudo pip3 install ecdsa-0.14.1-py2.py3-none-any.whl
          ```


### Installing gcc_riscv32 (Compiler Toolchain for the WLAN Module)

> ![icon-notice.gif](public_sys-resources/icon-notice.gif) **NOTICE**
> - Hi3861 supports only the static link of the libgcc library. The dynamic link is not recommended because version 3 of the GNU General Public License (GPLv3) will be polluted during commercial distribution.
> 
> - Steps 2 to 14 of the following procedure are used to build the **gcc_riscv32** image. You can directly [download the image](https://repo.huaweicloud.com/harmonyos/compiler/gcc_riscv32/7.3.0/linux/gcc_riscv32-linux-7.3.0.tar.gz) and skip these steps.

1. Start the Linux server.

2. Download the **RISC-V GNU** toolchain.
   
   ```
   git clone --recursive https://gitee.com/mirrors/riscv-gnu-toolchain.git
   ```

3. Open the **riscv-gnu-toolchain** folder and delete empty folders to prevent conflicts during the download of Newlib, Binutils, and GCC.
   
   ```
   cd riscv-gnu-toolchain && rm -rf riscv-newlib && rm -rf riscv-binutils && rm -rf riscv-gcc
   ```

4. Download RISC-V Newlib 3.0.0.
   
   ```
   git clone -b riscv-newlib-3.0.0 https://github.com/riscv/riscv-newlib.git
   ```

5. Download RISC-V Binutils 2.31.1.
   
   ```
   git clone -b riscv-binutils-2.31.1 https://github.com/riscv/riscv-binutils-gdb.git
   ```

6. Download RISC-V GCC 7.3.0.
   
   ```
   git clone -b riscv-gcc-7.3.0 https://github.com/riscv/riscv-gcc
   ```

7. Add the RISC-V GCC 7.3.0 patch.
   
   Visit the GCC official patch links [89411](https://gcc.gnu.org/git/?p=gcc.git;a=commitdiff;h=026216a753ef0a757a9e368a59fa667ea422cf09;hp=2a23a1c39fb33df0277abd4486a3da64ae5e62c2) and [86724](https://gcc.gnu.org/git/?p=gcc.git;a=blobdiff;f=gcc/graphite.h;h=be0a22b38942850d88feb159603bb846a8607539;hp=4e0e58c60ab83f1b8acf576e83330466775fac17;hb=b1761565882ed6a171136c2c89e597bc4dd5b6bf;hpb=fbd5f023a03f9f60c6ae36133703af5a711842a3), and manually add the changes to the .c and .h files based on the requirements in the patch links. Note that the number of rows may not match because of the differences in the patch and GCC versions. If this is the case, search for the keyword in the patch to locate the corresponding row.

8. Download, decompress, and install [GMP 6.1.2](https://gmplib.org/download/gmp/gmp-6.1.2.tar.bz2).
   
   ```
   tar -xvf gmp-6.1.2.tar.bz2 && mkdir build_gmp && cd build_gmp && ../gmp-6.1.2/configure --prefix=/usr/local/gmp-6.1.2 --disable-shared --enable-cxx && make && make install
   ```

9. Download, decompress, and install [mpfr-4.0.2](https://www.mpfr.org/mpfr-4.0.2/mpfr-4.0.2.tar.gz).
   
   ```
   tar -xvf mpfr-4.0.2.tar.gz && mkdir build_mpfr && cd build_mpfr && ../mpfr-4.0.2/configure --prefix=/usr/local/mpfr-4.0.2 --with-gmp=/usr/local/gmp-6.1.2 --disable-shared && make && make install
   ```

10. Download, decompress, and install [mpc-1.1.0](https://ftp.gnu.org/gnu/mpc/mpc-1.1.0.tar.gz).
    
    ```
    tar -xvf mpc-1.1.0.tar.gz && mkdir build_mpc && cd build_mpc && ../mpc-1.1.0/configure --prefix=/usr/local/mpc-1.1.0 --with-gmp=/usr/local/gmp-6.1.2 --with-mpfr=/usr/local/mpfr-4.0.2 --disable-shared && make && make install
    ```

11. Open the **riscv-gnu-toolchain** folder and create a directory for toolchain output.
    
    ```
    cd /opt && mkdir gcc_riscv32
    ```

12. Build Binutils.
    
    ```
    mkdir build_binutils && cd build_binutils && ../riscv-binutils-gdb/configure --prefix=/opt/gcc_riscv32 --target=riscv32-unknown-elf --with-arch=rv32imc --with-abi=ilp32 --disable-__cxa_atexit --disable-libgomp --disable-libmudflap --enable-libssp --disable-libstdcxx-pch --disable-nls --disable-shared --disable-threads --disable-multilib --enable-poison-system-directories --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --with-system-zlib CFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" CFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" --bindir=/opt/gcc_riscv32/bin --libexecdir=/opt/gcc_riscv32/riscv32 --libdir=/opt/gcc_riscv32 --includedir=/opt/gcc_riscv32 && make -j16 && make install && cd ..
    ```

13. Build Newlib.
    
    ```
    mkdir build_newlib && cd build_newlib && ../riscv-newlib/configure --prefix=/opt/gcc_riscv32 --target=riscv32-unknown-elf --with-arch=rv32imc --with-abi=ilp32 --disable-__cxa_atexit --disable-libgomp --disable-libmudflap --enable-libssp --disable-libstdcxx-pch --disable-nls --disable-shared --disable-threads --disable-multilib --enable-poison-system-directories --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --with-system-zlib CFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" \CXXFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" CFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" --bindir=/opt/gcc_riscv32/bin --libexecdir=/opt/gcc_riscv32 --libdir=/opt/gcc_riscv32 --includedir=/opt/gcc_riscv32 && make -j16 && make install && cd ..
    ```

14. Build GCC.
    
    ```
    mkdir build_gcc && cd build_gcc && ../riscv-gcc/configure --prefix=/opt/gcc_riscv32 --target=riscv32-unknown-elf --with-arch=rv32imc --with-abi=ilp32 --disable-__cxa_atexit --disable-libgomp --disable-libmudflap --enable-libssp --disable-libstdcxx-pch --disable-nls --disable-shared --disable-threads --disable-multilib --enable-poison-system-directories --enable-languages=c,c++ --with-gnu-as --with-gnu-ld --with-newlib --with-system-zlib CFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" CXXFLAGS="-fstack-protector-strong -O2 -D_FORTIFY_SOURCE=2 -Wl,-z,relro,-z,now,-z,noexecstack -fPIE" LDFLAGS="-Wl,-z,relro,-z,now,-z,noexecstack" CXXFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" CFLAGS_FOR_TARGET="-Os -mcmodel=medlow -Wall -fstack-protector-strong -Wl,-z,relro,-z,now,-z,noexecstack -Wtrampolines -fno-short-enums -fno-short-wchar" --with-headers="/opt/gcc-riscv32/riscv32-unknown-elf/include" --with-mpc=/usr/local/mpc-1.1.0 --with-gmp=/usr/local/gmp-6.1.2 --with-mpfr=/usr/local/mpfr-4.0.2 && make -j16 && make install
    ```

15. Set an environment variable.

    > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
    >   
    > If you are using the riscv32 gcc package, run the following command to decompress the package to the root directory:
    >   
    >  ```
    >  tar -xvf gcc_riscv32-linux-7.3.0.tar.gz -C ~
    >  ```
    > Note that the path used for setting the environment variables is the root directory.

    Open the .bashrc file.
    
    ```
    vim /opt/.bashrc
    ```

    Copy the following command to the last line of the file, save the file, and exit.
    
    ```
    export PATH=/opt/gcc_riscv32/bin:$PATH
    ```

16. Validate the environment variable.
    
    ```
    source /opt/.bashrc
    ```

17. Check whether the compiler is successfully installed. If the compiler version number is correctly displayed, the installation is successful.
     
    ```
    riscv32-unknown-elf-gcc -v
    ```
<!--no_check-->