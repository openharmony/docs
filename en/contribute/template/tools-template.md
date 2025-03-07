# Debugging Tool Writing Template

## General Writing Instructions
> **NOTE**
>
> Delete all writing instructions after you finish the writing.

The introduction to the debugging tool should focus on detailed description, aiming to comprehensively demonstrate each debugging and optimization command supported by the debugging tool to developers, ensuring that no command is omitted and not briefly summarized.

# Document Title
> *Writing Instructions*
> - **Document title**: Use a scenario-based phrase of the debugging tool as the document title. Retain the original tool name for easy understanding and direct use.
> - **Heading levels**: Use the document title as the level-1 heading, which is prefixed with `#` followed by a space. Use the environment requirements, command list, specific command description, and error codes (optional) as level-2 headings, which are prefixed with `##` followed by a space.

Describe the tool, including its definition, capabilities, and use scenarios. 

**Example**: Bundle Manager (bm)

Bundle Manager (bm) is a tool for installing, uninstalling, updating, and querying bundles. It provides basic capabilities for debugging application installation packages.

## Environment Setup

> *Writing Instructions*
>
> Describe the running environment of the tool according to the actual situation.

Describe the environment requirements for using the tool.


**Example**: Environment Setup

Before using this tool, you must obtain [hdc](../../application-dev/dfx/hdc.md) and run the **hdc shell** command.


## Commands
> *Writing Instructions*
> - To obtain the command list, run the ***xx* -h** or ***xx* -help** command.
> - List each command in the return value in the table, with **help/-h** listed in the first line, and other commands arranged according to their usage frequency.

|Command|Description|
|----|--------|
|help/-h|Help command, which is used for ****.|
|...|......|


**Example**
### bm Commands
| Command| Description|
| -------- | -------- |
| help | Displays the commands supported by the bm tool.|
| install | Installs a bundle.|
| uninstall | Uninstalls a bundle.|
| dump | Displays bundle information.|
| clean | Clears the cache and data of a bundle. This command is available in the root version. It is also available in the user version with developer mode enabled. It is unavailable in other cases.|
| enable | Enables a bundle. A bundle can be used after being enabled. This command is available in the root version but not in the user version.|
|...|...|


## *ExampleCommand* Command
>*Writing requirements*
> - Command usage: Contain every parameter in the return value of ***xx xxxx* help/-h**.
> - Command parameter list: Describe each parameter supported by the current command based on the return value of ***xx xxxx* help/-h**. In addition, describe whether it is mandatory and its use scenario. Place **help/-h** at the beginning.
> - Example: Provide example commands based on the parameters in the command list, providing examples that cover as many as possible.

```bash
xx xxxx [h] [****] [****]
```
>**NOTE**: All parameters must be listed.

**Parameters of the *exampleCommand* command**
|Parameter|Description|
|----|--------|
|-h|Help information.|
|...|......|

Example:

```bash
# Scenario description
xx xxxx 
```
**Example:**
## install Command

```bash
bm install [-h] [-p filePath] [-u userId] [-r] [-w waitingTime] [-s hspDirPath]
```

  **Parameters of the install command**


| Parameter| Description|
| -------- | -------- |
| -h | Displays help information.|
| -p | Installs an HAP with other HAPs in the specified path. This parameter is mandatory.|
| -u | Installs an HAP for a given user, which is the currently active user by default. This parameter is optional.  |
| -r | Installs an HAP in overwrite mode. This parameter is optional. By default, the HAP is installed in overwrite mode.|
| -s | This parameter is mandatory only for HSP installation. Installs an HSP. Each directory can have only one HSP with the same bundle name. This parameter is mandatory only for HSP installation.|
| -w | Waits for a specified time before installing a HAP. The minimum waiting time is 5s, and the maximum waiting time is 600s. The default waiting time is 5s. This parameter is optional.|




Example
```bash
# Install an HAP.
bm install -p /data/app/ohos.app.hap
# Install an HAP in overwrite mode.
bm install -p /data/app/ohos.app.hap -r
# Install an HSP.
bm install -s xxx.hsp
# Install a HAP and its dependent HSP.
bm install -p aaa.hap -s xxx.hsp yyy.hsp
# Install a HAP for a specified user. The waiting time is 10s.
bm install -p /data/app/ohos.app.hap -u 100 -w 10s 
```

> **NOTE**
> 
> The **help** command does not have a parameter list.

<!--no_check-->
