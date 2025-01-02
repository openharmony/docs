# Customizing Ark Bytecode During Compilation

If you want to customize the content of the Ark bytecode file, you can use the ArkTS compilation toolchain to customize the Ark bytecode file.

## Capability Configuration Description

Prepare a dynamic library file for operating the ARK bytecode file. In the build-profile.json5 configuration file of the project, configure the [compilation option transformLib](arkoptions-guide.md) and set the option value to the path of the dynamic library, the compiler loads the dynamic library at the specified time and executes the specific Transform method in the library.

## Capability execution mechanism

If the transformLib option is not configured in the build-profile.json5 file of the project, the compiler directly generates the ARK bytecode file to the default location. If transformLib is configured and the corresponding dynamic library file can be correctly loaded, the compiler generates an ARK bytecode file to the default destination location, calls the Transform method in the dynamic library, and transfers the path of the ARK bytecode file as a parameter. The Transform method is used to customize the logic for regenerating the ARK bytecode file.

The following development example is a dynamic library template. You need to implement the specific logic of Transform based on your requirements.

## How to Develop

1. Create the source code for modifying the dynamic library.

   ```
   /**
    * @brief Entry method for modifying the ARK bytecode file
    * @param abc_path Path for storing the ARK bytecode file to be processed.
    */
   extern "C" int Transform(const char *abc_path)
   {
       // You can read the ARK bytecode file corresponding to ${abc_path}, modify related data based on the ARK bytecode format, and generate a new ARK bytecode file.
       return 0;
   }
   ```

2. Use the C language compilation tool (G++) to compile the link library file of the corresponding platform.

   Windows

   ```
   g++ --share -o example.dll example.cpp
   ```

   Linux

   ```
   g++ --share -o example.so example.cpp
   ```

   Mac platform:

   ```
   g++ --shared -o example.so example.cpp
   ```

3. Configure the transformLib option in the build-profile.json5 file in the IDE. The following uses the Windows environment as an example.

   The path configured in the option is the path of the link library file generated in step 2 in the project (in this example, the path is in the dll directory).

   !image_0000002079773605](figures/image_0000002079773605.png)

4. Recompile the project to customize the Ark bytecode.
