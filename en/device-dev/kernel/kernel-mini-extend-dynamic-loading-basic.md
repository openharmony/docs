# Basic Concepts<a name="EN-US_TOPIC_0000001136130422"></a>

-   [Working Principles](#section139861939219)
    -   [Exporting the Symbol Table](#section15414650102716)
    -   [Loading an ELF File](#section5221181562810)
    -   [ELF File Link](#section68441639182817)

-   [ELF Specifications](#section187315541916)
    -   [ELF Type](#section1701552268)
    -   [Options for Linking](#section17292133274)


In small devices with limited hardware resources, dynamic algorithm deployment capability is required to solve the problem that multiple algorithms cannot be deployed at the same time. The LiteOS-M kernel uses the Executable and Linkable Format \(ELF\) because it is easy to use and compatible with a wide variety of platforms. The LiteOS-M provides APIs similar to  **dlopen**  and  **dlsym**. Apps can load and unload required algorithm libraries by using the APIs provided by the dynamic loading module. As shown in the following figure, the app obtains the corresponding information output through the API required by the third-party algorithm library. The third-party algorithm library depends on the basic APIs provided by the kernel, such as  **malloc**. After the app loads the API and relocates undefined symbols, it can call the API to complete the function. The dynamic loading component supports only the Arm architecture.In addition, the shared library to be loaded needs signature verification or source restriction to ensure the security of the system.

**Figure  1**  LiteOS-M kernel dynamic loading architecture<a name="fig3662173651419"></a>  
![](figure/liteos-m-kernel-dynamic-loading-architecture.png "liteos-m-kernel-dynamic-loading-architecture")

## Working Principles<a name="section139861939219"></a>

### Exporting the Symbol Table<a name="section15414650102716"></a>

The kernel needs to proactively expose the API required by the dynamic library when the shared library calls a kernel API, as shown in the following figure. This mechanism compiles the symbol information to the specified section and calls the  **SYM\_EXPORT**  macro to export information of the specified symbol. The symbol information is described in the structure  **SymInfo**. Its members include the symbol name and symbol address information. The macro  **SYM\_EXPORT**  imports the symbol information to the  **.sym.\***  section by using the  **\_\_attribute\_\_**  compilation attribute.

```
typedef struct {
  CHAR    *name;
  UINTPTR addr;
} SymInfo;

#define SYM_EXPORT(func)                                            \
const SymInfo sym_##func __attribute__((section(".sym."#func))) = { \
    .name = #func,                                                  \
    .addr = (UINTPTR)func                                           \
};
```

**Figure  2**  Exported symbol table information<a name="fig1024363510159"></a>  
![](figure/exported-symbol-table-information.png "exported-symbol-table-information")

### Loading an ELF File<a name="section5221181562810"></a>

During the loading process, the LOAD section to be loaded to the memory is obtained based on the ELF file handle and the section offset of the program header table. Generally, there are two sections: read-only section and read-write section. You can run the  **readelf -l**  command to view the LOAD section information of the ELF file. The physical memory is requested according to the related alignment attributes. Then, a code section or a data segment is written into the memory based on the loading base address and an offset of each section.

```
$ readelf -l lib.so

Elf file type is DYN (Shared object file)
Entry point 0x5b4
There are 4 program headers, starting at offset 52

Program Headers:
  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align
  EXIDX          0x000760 0x00000760 0x00000760 0x00008 0x00008 R   0x4
  LOAD           0x000000 0x00000000 0x00000000 0x0076c 0x0076c R E 0x10000
  LOAD           0x00076c 0x0001076c 0x0001076c 0x0010c 0x00128 RW  0x10000
  DYNAMIC        0x000774 0x00010774 0x00010774 0x000c8 0x000c8 RW  0x4

 Section to Segment mapping:
  Segment Sections...
   00     .ARM.exidx
   01     .hash .dynsym .dynstr .rel.dyn .rel.plt .init .plt .text .fini .ARM.exidx .eh_frame
   02     .init_array .fini_array .dynamic .got .data .bss
   03     .dynamic
```

**Figure  3**  Process of loading an ELF file<a name="fig15547494157"></a>  
![](figure/process-of-loading-an-elf-file.png "process-of-loading-an-elf-file")

### ELF File Link<a name="section68441639182817"></a>

A relocation table is obtained by using a  **.dynamic**  section of the ELF file. Each entry that needs to be relocated in the table is traversed. Then, the symbol is searched, based on the symbol name that needs to be relocated, in the shared library and the exported symbol table provided by the kernel. The relocation information is updated based on the symbol found.

**Figure  4**  ELF file linking process<a name="fig968155141613"></a>  
![](figure/elf-file-linking-process.png "elf-file-linking-process")

## ELF Specifications<a name="section187315541916"></a>

### ELF Type<a name="section1701552268"></a>

When compiling a shared library, you can add  **-fPIC**  \(a compilation option\) to compile location-independent code. The shared library file type is  **ET\_DYN**, which can be loaded to any valid address range.

Example:  **arm-none-eabi-gcc -fPIC –shared –o lib.so lib.c**

### Options for Linking<a name="section17292133274"></a>

1.  **-nostdlib**: Do not use the lib library in the compiler when linking.
2.  **-nostartfiles**: Do not use the startup files in the compiler when linking.
3.  **-fPIC**: compiles location-independent shared libraries.
4.  **-z max-page-size=4**: sets the number of alignment bytes of the loadable sections in the binary file to  **4**. This setting saves memory and can be used for a dynamic library.
5.  **-mcpu=**  specifies the CPU architecture.

