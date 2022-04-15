# HPM Part Reference


This section describes the HPM Part division rules, HPM Part types, HPM Part composition, metadata fields, and common CLI commands.


### HPM Part Division Rules

In principle, HPM Parts should be grouped at a fine-grained granularity to achieve maximum reuse. The following factors are taken into account:

- Independence: HPM Parts provide relatively independent features and can be independently built. Each HPM Part is capable of providing its own APIs and services for external systems.

- Coupling: If an HPM Part must depend on another one to provide services, they can be coupled to one HPM Part.

- Correlation: If a group of HPM Parts jointly implement a feature, and if other HPM Parts never depend on them, the group of HPM Parts can be combined into one HPM Part.


### HPM Part Type

HPM Parts are introduced for reuse purposes.

  **Table 1** HPM Part types

| Item| Description| 
| -------- | -------- |
| source | Distributed in the form of source code. It is depended by the target project, and can be compiled independently.| 
| binary | Distributed in binary mode. It does not contain source code, such as build tools.| 
| code-segment | Distributed in the form of code snippets and cannot be compiled independently. After the installation, it is restored to the specified directory and participates in other code build in the target project.| 
| distribution | Distributed as a distribution and dependent on other HPM Parts. It does not contain source code (except build scripts). The build output is system images.| 
| template | Distributed as a template and used by the **hpm init** command to create a template.| 
| plugin | Distributed as a plugin of hpm-cli to provide more functions.| 


### HPM Part Composition

An HPM Part contains the following:

- **src** directory for storing code files or code library of the HPM Part.

- **ohos_bundles** folder for storing dependent HPM Parts. The folder is automatically generated during HPM Part installation and does not need to be committed to the code library.

- **README.md** file for describing the HPM Part.

- **bundle.json** file for declaring metadata of the HPM Part.

- LICENSE file for open-source code.
    
  ```
  my-bundle
     |_ohos_bundles
     |_headers
     |_src
     |_bundle.json
     |_README.md
     |_LICENSE
  ```


### src Source Code

HPM Part code files are the same as those in a common code directory. The only difference lies in the open APIs (declared in header files) provided by HPM Parts, which will be referenced by other HPM Parts and must be declared in **dirs** of **bundle.json**.


### README File

To help consumers find your HPM Part on [DevEco Marketplace](https://repo.harmonyos.com) and use it more conveniently, include a **README.md** file in the root directory of the HPM Part.

**README.md** is a file written using the markdown syntax.

The **README.md** file may include instructions on how to install, configure, and use the sample code in the HPM Part, as well as any other information helpful to the consumers.

The Readme file will be displayed on the homepage of the HPM Part on [DevEco Marketplace](https://repo.harmonyos.com).


## bundle.json File

The **bundle.json** file describes the metadata of an HPM Part. Each HPM Part has its own **bundle.json** file. The file content is as follows:

  
```
{
  "name": "@myorg/demo-bundle",
  "version": "1.0.0",
  "license": "MIT",
  "description": "bundle description",
  "keywords": ["hos"],
  "tags": ["applications", "drivers"],
  "author": {"name":"","email":"","url":""},
  "contributors":[{"name":"","email":"","url":""},{"name":"","email":"","url":""}],
  "homepage": "http://www.foo.bar.com",
  "repository": "https://git@gitee.com:foo/bar.git",
  "private": false,
  "publishAs": "code-segment",
  "segment":{
     "destPath":"/the/dest/path"
  },
  "dirs": {
    "src": ["src/**/*.c"],
    "headers": ["headers/**/*.h"],
    "bin": ["bin/**/*.o"]
  },
  "scripts": {
    "build": "make"
  },
  "envs": {},
  "ohos": {
    "os": "2.0.0",
    "board": "hi3516",
    "kernel": "liteos-a"
  },
 "rom": "10240",
 "ram": "1024",
 "dependencies": {
    "@myorg/net":"1.0.0"
 }
}
```

Each **bundle.json** file has the following fields:

- **name**: an HPM Part name, which starts with the at sign (@) and is separated with the organization name by the slash (/), for example, **\@myorg/mybundle**.

- **version**: version of the HPM Part, for example, 1.0.0. The version must comply with the Semantic Versioning Specification (SemVer) standards.

- **description**: a brief description of the HPM Part.

- **dependencies**: dependent HPM Parts.

- **envs**: parameters required for building the HPM Part, including global parameters and dependency parameters.

- **scripts**: commands executable to the HPM Part, such as commands for compiling, building, testing, and burning.

- **publishAs**: HPM Part publishing type, which can be **source**, **binary**, **distribution**, or **code-segment**.

- **segment**: destination path of the code-segment HPM Part, that is, the destination path of the files contained in the HPM Part after the HPM Part is installed.

- **dirs**: directory structure (such as the header file) generated for publishing.

- **ram** and **rom**: statistical information about the estimated read-only memory (ROM) and random access memory (RAM) usage.

- **ohos**: mappings among OpenHarmony versions, development boards, and kernels, separated by commas (,).

- Extended information: author, home page, code repository, license, tags, and keywords.

- For a distribution-level HPM Part, you can define the inheritance relationship and use the **base** field to describe the basic distribution and version that are inherited from.

- **private**: indicates whether an HPM Part is private. A private HPM Part cannot be found by other organizations. The default value is **false**.


## HPM CLI Commands

You can use the hpm-cli tool to manage the lifecycle of an HPM Part. The following table describes available hpm-cli commands. You can run the **hpm -h** command to get the command details.

  **Table 2** Commands available on hpm-cli

| Command Type| Command Line| Description| 
| -------- | -------- | -------- |
| Querying version information| **hpm -V** or **hpm --version**| Displays the version of the hpm-cli tool.| 
| Querying help information| **hpm -h** or **hpm --version**| Displays the command list and help information.| 
|| hpm&nbsp;-h | Displays command help information.| 
| Creating a project| hpm&nbsp;init&nbsp;bundle | Creates an HPM Part project.| 
|| hpm&nbsp;init&nbsp;-t&nbsp;template | Creates a scaffolding project from a template.| 
| Installing HPM Parts| **hpm install** or **hpm i**| Installs dependent HPM Parts in the bundle.json file.| 
|| hpm&nbsp;install&nbsp;bundle\@version | Installs HPM Parts of a specified version.| 
| Uninstalling HPM Parts| hpm&nbsp;uninstall&nbsp;bundle | Uninstalls dependent HPM Parts.| 
|| **hpm remove** or **hpm rm bundlename**| Uninstalls dependent HPM Parts.| 
| Viewing information| **hpm list** or **hpm ls**| Displays the dependency tree of the HPM part.| 
|| hpm&nbsp;dependencies | Generates the dependency relationship data of the HPM Part. (This command is also integrated in the **hpm ui** command. After you run the hpm ui command, a hpm UI is displayed with the dependencies.)| 
| Searching for HPM Parts| hpm&nbsp;search&nbsp;name | Searches for HPM Parts. **--json** is used to specify the search result in JSON format, and **-type** is used to set the target type, which can be **part**, **distribution**, or **code-segment**.| 
| Setting HPM configuration items| hpm&nbsp;config&nbsp;set&nbsp;key&nbsp;value | Sets configuration items, such as the server address and network proxy.| 
|| hpm&nbsp;config&nbsp;delete&nbsp;key | Deletes configurations.| 
| Updating HPM Part versions| hpm&nbsp;update | Updates the versions of dependent HPM Parts.| 
|| hpm&nbsp;check-update | Checks whether version updates are available to dependent HPM Parts.| 
| Building| hpm&nbsp;build | Builds an HPM Part.| 
|| hpm&nbsp;dist | Builds a distribution. The build depends on the **dist** script in **scripts** of **bundle.json**.| 
| Packing | hpm&nbsp;pack | Packs dependencies of local HPM Parts.| 
| Burning| hpm&nbsp;run&nbsp;flash | Burns the firmware. The firmware burning depends on the **flash** script in **scripts** of **bundle.json**.| 
| Publishing| hpm&nbsp;publish | Publishes an HPM Part, which must be unique in the repository and has a unique version. (An account is required for login.)| 
| Running of extended commands| hpm&nbsp;run | Runs the commands in **scripts** defined in **bundle.json**. Multiple commands can be executed at a time by using **&&**.| 
| Decompressing| hpm&nbsp;extract | Decompresses files in zip, tar, tgz, or .tar.gz format.| 
| Starting UI| hpm&nbsp;ui | Starts the hpm UI locally. You can use the **-p** parameter to specify a port. On the Windows platform, the default browser is used to open the HPM UI.| 
| Changing language| hpm&nbsp;lang | Alternates between Chinese and English on the CLI and UI.| 
| Converting to HPM format| hpm&nbsp;x2h | Converts a Maven or npm package to an HPM Part and publishes it on the HPM platform.| 
| Code segment restoration or cleanup| hpm&nbsp;code&nbsp;clean\|restore | Clears or restores the dependent code segment, which is equivalent to copying or deleting the code segment based on **segment.destPath**.| 
| Generating a key| hpm&nbsp;gen-keys | Generates a public-private key pair and configures the public key on [DevEco Marketplace](https://repo.harmonyos.com), which enables password-free hpm-cli login for HPM Part publishing.| 
| Generation of the third-party open source notice| hpm&nbsp;gen-notice | Generates a file providing the notice on third-party open source by combining the description of each HPM Part.| 


## About Dependency

HPM Part dependencies are classified as mandatory and optional dependencies.

- Mandatory dependency: If HPM Part A must depend on HPM Part B to implement a feature (the APIs or services specific to HPM Part B must be called), HPM Part B is a mandatory dependency of HPM Part A.

- Optional dependency: If either HPM Part C or D is required for HPM Part A to implement a feature, and if HPM Parts C and D are interchangeable, HPM Parts C and D are optional dependencies of HPM Part A.

  
```
"dependencies": {
    "@myorg/core":"1.0.0",
    "?@myorg/plugin1":"1.0.0",
    "?@myorg/plugin2":"1.1.0"
 }
```

HPM Part dependencies can also be classified as compilation and development dependencies.

- Compilation dependency: dependency required for runtime.

- Development dependency: dependency required in non-runtime scenarios, such as static check, build, packing, test, and formatting tools.

  
```
"dependencies": {
    "@myorg/core":"1.0.0"
 },
"devDependencies": {
    "@myorg/tool":"1.0.0"
 }
```

  Tags can be defined to group dependent HPM Parts. You can obtain the path of a group of dependent HPM Parts based on their tag. A tag starts with a number sign (#) and is defined as follows:
  
```
{
    "dependencies": {
        "#tool": {
            "first_bundle": "1.0.0",
            "second_bundle": "1.0.0"
        },
        "#drivers": {
            "xx_bundle": "1.0.0",
            "yy_bundle": "1.0.0"
        }
    }
}
```

HPM Part dependencies (including indirect dependencies) can be displayed by running the **hpm list** command or on the hpm UI, which is started by running the **hpm ui** command.

  
```
$ hpm list
+--demo@1.0.0
| +--@example/media@1.0.2
| +--@demo/sport_hi3518ev300_liteos_a@1.0.0
| | +--@demo/app@4.0.1
| | | +--@demo/build@4.0.1
| | | +--@demo/arm_harmonyeabi_gcc@4.0.0   
| | +--@demo/liteos_a@4.0.0
| | | +--@demo/third_party_fatfs@4.0.0     
| | | +--@demo/arm_harmonyeabi_gcc@4.0.0   
| | +--@demo/init@4.0.0
| | +--@demo/dist_tools@4.0.0
```


## About Environment Variables

During HPM Part building, system-provided environment variables are required to define the output and link the required binary files.

These variables are injected into the context for executing scripts based on service requirements.

Therefore, their values can be directly obtained from the scripts. The following environment variables are available:

**Built-in environment variables**

- **DEP_OHOS_BUNDLES**: path of the **ohos_bundles** folder

- **DEP_BUNDLE_BASE**: path of the outermost HPM Part

**Global environment variables**

Global environment variables are defined by the **envs** attribute in **bundle.json**. You can obtain the values of global environment variables from all independent HPM Parts.

  
```
{
    "envs": {
        "compileEnv": "arm"
    }
}
```

Different parameters can be passed to HPM Parts when introducing dependencies so that the compilation of dependent HPM Parts can meet the requirements of the current HPM Part. The parameters defined in the dependencies can be obtained from the context for executing the corresponding scripts.

  
```
{
    "dependencies": {
        "my-bundle": {
            "version": "1.0.0",
            "mode": "debug"
        }
    }
}
```

When linking to a binary file, the HPM Part needs to know the file path regarding the dependencies. Therefore, you need to pass the path as an environment variable to the HPM Part for building.

The passed environment variable is in **DEP\_BundleName** format, where **BundleName** indicates the name of the dependent HPM Part, for example, **DEP\_first\_bundle**.


## About Naming and Version Number

1. The name must be lowercase letters or digits and can be separated by underscores (\_), for example, **bundle**, **my\_bundle**, and **json2**.

2. Name of an HPM Part published to [DevEco Marketplace](https://repo.harmonyos.com) must start with the at sign (@) and is separated with the organization name by a slash (/), for example, **@my_org/part_name**.

3. The organization name and part name must be unique and distinguishably different with other names.

4. Names should be easy to understand.

5. An HPM Part version must be in the format of ***majorVersion***.***minorVersion***.***revisionVersion*** or ***majorVersion***.***minorVersion***.***revisionVersion***-***pre-releaseVersion***, for example, **1.0.0** and **1.0.0-beta**. For details, see [https://semver.org](https://semver.org/).
