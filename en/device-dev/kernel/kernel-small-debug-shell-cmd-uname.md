# uname<a name="EN-US_TOPIC_0000001179965843"></a>

## Command Function<a name="section107697383115"></a>

This command is used to display the name, version creation time, system name, and version information of the current OS.

## Syntax<a name="section162824341116"></a>

uname \[_-a | -s | -t | -v | --help_\]

**Table  1**  Parameters

<a name="table909mcpsimp"></a>
<table><thead align="left"><tr id="row914mcpsimp"><th class="cellrowborder" valign="top" width="33.989999999999995%" id="mcps1.2.3.1.1"><p id="p916mcpsimp"><a name="p916mcpsimp"></a><a name="p916mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="66.01%" id="mcps1.2.3.1.2"><p id="p918mcpsimp"><a name="p918mcpsimp"></a><a name="p918mcpsimp"></a>Parameters</p>
</th>
</tr>
</thead>
<tbody><tr id="row119816412718"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p1384693214813"><a name="p1384693214813"></a><a name="p1384693214813"></a>No parameter</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p18199114113719"><a name="p18199114113719"></a><a name="p18199114113719"></a>Displays the OS name by default.</p>
</td>
</tr>
<tr id="row919mcpsimp"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p921mcpsimp"><a name="p921mcpsimp"></a><a name="p921mcpsimp"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p923mcpsimp"><a name="p923mcpsimp"></a><a name="p923mcpsimp"></a>Displays all information.</p>
</td>
</tr>
<tr id="row924mcpsimp"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p926mcpsimp"><a name="p926mcpsimp"></a><a name="p926mcpsimp"></a>-t</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p928mcpsimp"><a name="p928mcpsimp"></a><a name="p928mcpsimp"></a>Displays the time when the version was created.</p>
</td>
</tr>
<tr id="row929mcpsimp"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p931mcpsimp"><a name="p931mcpsimp"></a><a name="p931mcpsimp"></a>-s</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p933mcpsimp"><a name="p933mcpsimp"></a><a name="p933mcpsimp"></a>Displays the OS name.</p>
</td>
</tr>
<tr id="row934mcpsimp"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p936mcpsimp"><a name="p936mcpsimp"></a><a name="p936mcpsimp"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p938mcpsimp"><a name="p938mcpsimp"></a><a name="p938mcpsimp"></a>Displays the version information.</p>
</td>
</tr>
<tr id="row944mcpsimp"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p946mcpsimp"><a name="p946mcpsimp"></a><a name="p946mcpsimp"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p948mcpsimp"><a name="p948mcpsimp"></a><a name="p948mcpsimp"></a>Displays the help information.</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section2652124861114"></a>

The  **uname**  command displays the name of the current OS by default. The  **uname -a | -t| -s| -v**  command displays the name of the in-use OS in the standard output. These parameters are mutually exclusive.

## Example<a name="section0107995132"></a>

Run  **uname -a**.

## Output<a name="section1215113245511"></a>

Querying system information

![](figure/en-us_image_0000001179967909.png)

