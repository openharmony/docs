# js-rawheap-translator

<!--Kit: ArkWeb-->
<!--Subsystem: ArkCompiler-->
<!--Owner: @sunzibo-->
<!--Designer: @sunzibo-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=084bf627297e60b1f406ce34f5b473174466f7b3 translatedAt=2026-07-14T07:16:09.357Z pushedAt=2026-07-14T07:57:36.710Z -->

## When to Use

To help you locate issues, the app automatically performs a Heap Dump when a JS heap OOM (Out of Memory) occurs in ArkWeb or JSVM. This operation saves all object information currently on the virtual machine heap into a binary file with the .rawheap extension. You can use the js_rawheap_translator tool to parse the .rawheap file and generate a .heapsnapshot file. This file can be imported and viewed through DevEco Studio's [Heap Snapshot offline import](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-snapshot-basic-operations#section6760173514388) or the memory tool in Chrome DevTools.

## Usage

### Tool Acquisition

This tool supports Windows, Linux, and macOS platforms. The acquisition methods are as follows:

- Obtain from the SDK: sdk/default/openharmony/toolchains/js_rawheap_translator, applicable to all platforms.

### Environment Configuration

It is recommended to configure the path where the js_rawheap_translator tool is located as a system environment variable. This allows you to use the tool directly in the terminal without specifying the path each time.

The configuration method for environment variables varies across different systems. The following provides some configuration examples for your reference.

- Windows (using Windows 10 as an example)

  1. Right-click **This PC** and choose **Properties**.

  2. In the pop-up window, click **Advanced system settings**.

  3. In the pop-up window, click the **Environment Variables** button on the **Advanced** tab page.

   4. In the pop-up window, double-click the **Path** variable under **System variables**.

  5. In the pop-up window, click **New**.

  6. Enter the file path where the js_rawheap_translator tool is stored locally into the newly created text box.

  7. Click **OK** to close all pop-up windows.

  8. Restart the terminal.

- macOS (using macOS 15 as an example)

  1. Open the terminal tool and execute the following command.

      ```bash
      echo $SHELL
      ```

  2. Perform the corresponding actions based on the result returned in step 1.

      a. If the return result is `/bin/bash`, run the following command:

      ```bash
      echo 'export PATH=$PATH:/path/to/your/js_rawheap_translator' >> ~/.bash_profile
      source ~/.bash_profile
      ```

      b. If the return result is `/bin/zsh`, run the following command:

      ```bash
      echo 'export PATH=$PATH:/path/to/your/js_rawheap_translator' >> ~/.zshrc
      source ~/.zshrc
      ```

- Linux

  1. Open the terminal tool and run the following command to check the current shell.

      ```bash
      echo $SHELL
      ```

  2. Based on the return result from step 1, perform the corresponding action as follows.

      a. If the returned result is `/bin/bash`, run the following command:

      ```bash
      echo 'export PATH=$PATH:/path/to/your/js_rawheap_translator' >> ~/.bash_profile
      source ~/.bash_profile
      ```

      b. If the returned result is `/bin/zsh`, run the following command:

      ```bash
      echo 'export PATH=$PATH:/path/to/your/js_rawheap_translator' >> ~/.zshrc
      source ~/.zshrc
      ```

## How to Use

### Parse Command

```bash
js_rawheap_translator --translate <input.rawheap> [--translate-out <output.heapsnapshot>] [v8 flags]
```

### Parameter List

| Option | Required | Description |
| -------- | --- | ----------------- |
| --translate <input.rawheap> | Yes | Path to the .rawheap file generated during JS heap OOM that needs to be parsed. |
| --translate-out <output.heapsnapshot> | No | Path to the heapsnapshot file generated after parsing. The path must have read and write permissions.<br>When this parameter is omitted, the default is the current command execution path.<br>When this parameter is specified, the file extension must be heapsnapshot. |
| [v8 flags] | No | Additional v8-related command line parameters can be appended. |

## Parsing Command Example

### Parsing Example

Windows

Open cmd, navigate to the rawheap file path, and invoke the parser tool command to generate a heapsnapshot file in the current path.

```bash
> js_rawheap_translator.exe --translate test.rawheap --translate-out test.heapsnapshot
```

Linux

Navigate to the rawheap file path, and invoke the parser tool command to generate a heapsnapshot file in the current path.

```bash
> ./js_rawheap_translator --translate test.rawheap --translate-out test.heapsnapshot
```

macOS

Open the terminal and navigate to the rawheap file path. Invoke the parser tool command and specify to generate the heapsnapshot file in the current path.

```bash
> js_rawheap_translator --translate test.rawheap --translate-out test.heapsnapshot
```

Example of specifying only the input file and using the default output path

```bash
> js_rawheap_translator --translate test.rawheap
```

Reference output

```bash
binary reader file size:xxxxx
[HeapDump]print header_: magic_: 0x56384844, dump_format_version_: 1, flags_: 0xf37 {...}, ... v8_version: 14.4.258.16, ...
[HeapDump][HeapDump]elapsed time: xxx.xxxxx ms
[HeapDump]fd closed
```

## File Reference Specifications

The size and generation time of a rawheap file are strongly positively correlated with the current JS heap memory size and the number of live objects. When the JS heap memory usage is high and the number of live objects is large, the generated rawheap file will be larger and the generation will take longer.

## FAQs

### Tool Version Mismatch

**Symptom**<br>
A version mismatch error is prompted during tool parsing.<br>
**Cause**<br>
The current tool version is lower than the rawheap file version.<br>
**Solution**<br>
Upgrade the tool to a matching version to resolve this issue.

### Unable to Open the File

**Symptom**<br>
During tool parsing, the following message appears: open file failed<br>
**Cause**<br>
The specified input file does not exist, or the output file path does not have write permission.<br>
**Solution**<br>
Verify that the input file path is correct, or change to a path with write permission.

### Incorrect Parameter Format

**Symptom**<br>
During tool parsing, a parameter error message is displayed.<br>
**Cause**<br>
The command parameter format is incorrect.<br>
**Solution**<br>
Use `js_rawheap_translator --help` to view the correct parameter format.