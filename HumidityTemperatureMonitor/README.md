# Module: Humidity Temperature Monitor

## STM32F103C8T6

### The Minist System Board

![STM32F103C8T6 Minist System Board IO](../.fig/STM32F103C8T6MinistSystemBoardIOFig.jpg "STM32F103C8T6 Minist System Board IO")

- [STM32F103C8T6 Schemat](../Doc/STM32F103C8T6Schemat.pdf)

## SHT3x

### IIC Address

| SHT3x-DIS | I2C Address | Conditon |
| :------: | :------: | :-----: |
| Address A | 0x44 (default) | ADDR connected to VSS |
| Address B | 0x45 | ADDR connected to VDD |

### SHT30

#### Humidity Formula

Relative humidity conversion formula:

$$
RH(\%) = 100 \times \frac{S_{RH}}{2^{16} - 1}
$$

#### Temperature Formula

Temperature conversion formula:

$$
T(\degree C) = -45 + 175 \times \frac{S_T}{2^{16} - 1}
$$

$$
T(\degree F) = -49 + 315 \times \frac{S_T}{2^{16} - 1}
$$

## Reference

- [*STM32F103C8T6套装入门手册_V0.1*](../Doc/STM32F103C8T6套装入门手册_V0.1.pdf)
- [*SHT30-DIS datasheet*](https://sensirion.com/cn/products/product-catalog/SHT30-DIS-B)