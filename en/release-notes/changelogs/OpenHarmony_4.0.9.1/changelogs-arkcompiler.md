# Arkcompiler Subsystem Changelog

## cl.arkcompiler.1 -- Removing of ts2abc compiler in sdk

The composition of Arkcompiler in sdk was ts2abc compiler and es2abc compiler, supporting compilation of ets/js files. The ts2abc compiler has been removed from sdk since this version, thus it can't be used for abc file generation. Developers can view the corresponding changes in directory ets\build-tools\ets-loader\bin and directory js\build-tools\ets-loader\bin of sdk as presented in the picture below.

![stack](figures/api10_sdk_arkcompiler_component_change.png)

**Change Impacts**
After updating the sdk, developing through DevEco will not be influenced. However, if developing scripts to use ts2abc compiler for abc file generation, one should switch to es2abc compiler

**Key API/Component Changes**
The ts2abc compiler related components are removed from sdk

**Adaptation Guide**
1. For developers using DevEco for application developing, the removing of ts2abc compiler has no influence.
2. For developers writing scripts to use ts2abc compiler need to switch to es2abc compiler. Details of usage of es2abc compiler and the comparison between es2abc and ts2abc can be referred at[usage guideline of es2abc and comparison between es2abc and ts2abc](https://gitee.com/openharmony/arkcompiler_ets_frontend#%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E). Assuming a.js as the target js file for compilation. For the scenario of abc generation, which is of the highest frequency, comparison of using es2abc compiler and ts2abc are present as below:
    - script mode
        1. es2abc: es2abc a.js --output a.abc
        2. ts2abc: node --expose-gc pathToIndex/index.js a.js --output a.abc
    - module mode
        1. es2abc: es2abc a.js --module --output a.abc
        2. ts2abc: node --expose-gc pathToIndex/index.js a.js --module --output a.abc