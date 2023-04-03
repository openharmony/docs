# hwi


## Command Function

This command is used to query information about interrupts.


## Syntax

hwi


## Parameters

None.


## Usage Guidelines

- Run **hwi** to display the interrupt IDs, count of interrupts, and registered interrupt names of the system.

- If **LOSCFG_CPUP_INCLUDE_IRQ** is enabled, the interrupt handling time (ATime), CPU usage, and type of each interrupt are also displayed.


## Example

Run **hwi**.


## Output

- Interrupt information (**LOSCFG_CPUP_INCLUDE_IRQ** disabled):
  
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

- Interrupt information (**LOSCFG_CPUP_INCLUDE_IRQ** enabled):
  
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

**Table 1** Output description

| Parameter| Description|
| -------- | -------- |
| InterruptNo | Interrupt number.|
| Count | Number of interrupts.|
| Name | Registered interrupt name.|
| ATime | Interrupt handling time.|
| CPUUSE | CPU usage.|
| CPUUSE10s | CPU usage in the last 10s.|
| CPUUSE1s | CPU usage in the last 1s.|
| mode | Interrupt type, which can be any of the following:<br>- **normal**:   non-shared interrupt.<br>- **shared**: shared interrupt.|
