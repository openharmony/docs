# hwi

## Command Function<a name="section445335110416"></a>

This command is used to query information about interrupts.

## Syntax<a name="section1795712553416"></a>

hwi

## Parameters<a name="section92544592410"></a>

None

## Usage<a name="section104151141252"></a>

-   Run  **hwi**  to display the interrupt IDs, count of interrupts, and registered interrupt names of the system.
-   If  **LOSCFG\_CPUP\_INCLUDE\_IRQ**  is enabled, the interrupt handling time \(ATime\), CPU usage, and type of each interrupt are also displayed.

## Example<a name="section11545171957"></a>

Run  **hwi**.

## Output<a name="section075617368542"></a>

-   Interrupt information \(**LOSCFG\_CPUP\_INCLUDE\_IRQ**  disabled\):

    ```
    OHOS # hwi
     InterruptNo     Count     Name
            0:         0:
            1:   1025641:
            2:         0:
           29:    824049:
           37:         0:      rtc_alarm
           38:        24:      uart_pl011
           48:         3:      GPIO
           59:         0:
           62:       530:      MMC_IRQ
           63:        70:      MMC_IRQ
           64:       280:      ETH
           67:        58:      tde
           68:         0:      JPGE_0
           69:         0:      IVE
           70:         0:      VGS
           72:         0:      VEDU_0
           73:         0:      nnie0
           74:         0:      nnie_gdc0
           75:         0:      VPSS
           76:         0:      VI_PROC0
           77:         0:      JPEGD_0
           83:     49455:      HIFB_SOFT_INT
           87:         0:      AIO interrupt
           88:         0:      VI_CAP0
           89:         0:      MIPI_RX
           90:     49455:      VO int
           91:     49456:      HIFB Int
           96:     17601:      MMC_IRQ
          100:         0:      SPI_HI35XX
          101:         0:      SPI_HI35XX
          102:         0:      SPI_HI35XX
    ```

-   Interrupt information \(**LOSCFG\_CPUP\_INCLUDE\_IRQ**  enabled\):

    ```
    OHOS # hwi
     InterruptNo      Count  ATime(us)   CPUUSE  CPUUSE10s  CPUUSE1s   Mode Name
              0:          0          0     0.0        0.0       0.0  normal
              1:     937031          0     0.1        0.1       0.1  normal
              2:          0          0     0.0        0.0       0.0  normal
             29:     726166          5     0.54       0.57      0.59 normal
             37:          0          0     0.0        0.0       0.0  normal rtc_alarm
             38:         17          5     0.0        0.0       0.0  normal uart_pl011
             48:          3          4     0.0        0.0       0.0  normal GPIO
             59:          0          0     0.0        0.0       0.0  normal
             62:        531          1     0.0        0.0       0.0  normal MMC_IRQ
             63:         69          1     0.0        0.0       0.0  normal MMC_IRQ
             64:        292          2     0.0        0.0       0.0  normal ETH
             67:         54         76     0.0        0.0       0.0  shared tde
             68:          0          0     0.0        0.0       0.0  shared JPGE_0
             69:          0          0     0.0        0.0       0.0  shared IVE
             70:          0          0     0.0        0.0       0.0  shared VGS
             72:          0          0     0.0        0.0       0.0  shared VEDU_0
             73:          0          0     0.0        0.0       0.0  shared nnie0
             74:          0          0     0.0        0.0       0.0  shared nnie_gdc0
             75:          0          0     0.0        0.0       0.0  shared VPSS
             76:          0          0     0.0        0.0       0.0  shared VI_PROC0
             77:          0          0     0.0        0.0       0.0  shared JPEGD_0
             83:      45529          8     0.5        0.5       0.5  shared HIFB_SOFT_INT
             87:          0          0     0.0        0.0       0.0  shared AIO interrupt
             88:          0          0     0.0        0.0       0.0  shared VI_CAP0
             89:          0          0     0.0        0.0       0.0  shared MIPI_RX
             90:      45534         11     0.6        0.7       0.7  shared VO int
             91:      45533          2     0.1        0.1       0.1  shared HIFB Int
             96:      17383          2     0.0        0.0       0.0  normal MMC_IRQ
            100:          0          0     0.0        0.0       0.0  normal SPI_HI35XX
            101:          0          0     0.0        0.0       0.0  normal SPI_HI35XX
            102:          0          0     0.0        0.0       0.0  normal SPI_HI35XX
    ```

    **Table  1**  Output

    <a name="table809mcpsimp"></a>
    <table><thead align="left"><tr id="row814mcpsimp"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p816mcpsimp"><a name="p816mcpsimp"></a><a name="p816mcpsimp"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p818mcpsimp"><a name="p818mcpsimp"></a><a name="p818mcpsimp"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row20360171311398"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p172391401402"><a name="p172391401402"></a><a name="p172391401402"></a>InterruptNo</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p42381940174013"><a name="p42381940174013"></a><a name="p42381940174013"></a>Interrupt ID</p>
    </td>
    </tr>
    <tr id="row262535153913"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1823824014402"><a name="p1823824014402"></a><a name="p1823824014402"></a>Count</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p14237040144018"><a name="p14237040144018"></a><a name="p14237040144018"></a>Number of interrupts</p>
    </td>
    </tr>
    <tr id="row9683953153916"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6236124084018"><a name="p6236124084018"></a><a name="p6236124084018"></a>Name</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p18235164014401"><a name="p18235164014401"></a><a name="p18235164014401"></a>Registered interrupt name</p>
    </td>
    </tr>
    <tr id="row85721136402"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1123434017409"><a name="p1123434017409"></a><a name="p1123434017409"></a>ATime</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2023424094014"><a name="p2023424094014"></a><a name="p2023424094014"></a>Interrupt handling time</p>
    </td>
    </tr>
    <tr id="row19180126151415"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6233040164020"><a name="p6233040164020"></a><a name="p6233040164020"></a>CPUUSE</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p5232840104015"><a name="p5232840104015"></a><a name="p5232840104015"></a>CPU usage</p>
    </td>
    </tr>
    <tr id="row511517331702"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p14231040164014"><a name="p14231040164014"></a><a name="p14231040164014"></a>CPUUSE10s</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1323011409405"><a name="p1323011409405"></a><a name="p1323011409405"></a>CPU usage within the last 10 seconds</p>
    </td>
    </tr>
    <tr id="row1868124415413"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p9681144414114"><a name="p9681144414114"></a><a name="p9681144414114"></a>CPUUSE1s</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p76814443417"><a name="p76814443417"></a><a name="p76814443417"></a>CPU usage within the last 1 second</p>
    </td>
    </tr>
    <tr id="row7681164454112"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1968124412411"><a name="p1968124412411"></a><a name="p1968124412411"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p268134415419"><a name="p268134415419"></a><a name="p268134415419"></a>Interrupt type, which can be any of the following:</p>
    <a name="ul682912412419"></a><a name="ul682912412419"></a><ul id="ul682912412419"><li><strong id="b35357873733839"><a name="b35357873733839"></a><a name="b35357873733839"></a>normal</strong>: non-shared interrupt.</li><li><strong id="b209107492433839"><a name="b209107492433839"></a><a name="b209107492433839"></a>shared</strong>: shared interrupt.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>


