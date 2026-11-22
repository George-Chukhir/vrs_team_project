# Hardware configuration (CubeMX, LL)

Target board: **NUCLEO-F303K8** (STM32F303K8T6, LQFP32, Arduino Nano layout).
All peripherals are generated with **LL drivers**.

## Pin map

| Function | Peripheral / mode | Pin (Nucleo label) | User label | Settings |
|---|---|---|---|---|
| UART to PC | USART2 async | PA2 TX, PA15 RX (ST-LINK VCP) | – | 115200 8N1, RX interrupt |
| M24SR SCL | I2C1 | PB6 (D5) | – | 100 kHz Standard (400 kHz later), analog filter on |
| M24SR SDA | I2C1 | PB7 (D4) | – | 7-bit address 0x56 (0xAC write) |
| M24SR GPO | GPIO_EXTI8 | PA8 (D9) | `NFC_GPO` | Falling edge, pull-up (open-drain, active low) |
| M24SR RF_DISABLE | GPIO_Output | PA7 (A6) | `RF_DISABLE` | Push-pull, initial Low (RF on), optional |
| Servo cell 1 | TIM3_CH1 PWM | PB4 (D12) | – | See [TIM3](#tim3--sg90-servos-50-hz-pwm) |
| Servo cell 2 | TIM3_CH2 PWM | PB5 (D11) | – | See [TIM3](#tim3--sg90-servos-50-hz-pwm) |
| IR cell 1 – sensor A | GPIO_Input | PA0 (A0) | `IR1_A` | Pull-up |
| IR cell 1 – sensor B | GPIO_Input | PA1 (A1) | `IR1_B` | Pull-up |
| IR cell 2 – sensor A | GPIO_Input | PA3 (A2) | `IR2_A` | Pull-up |
| IR cell 2 – sensor B | GPIO_Input | PA4 (A3) | `IR2_B` | Pull-up |
| Reed switch cell 1 | GPIO_Input (or EXTI11) | PA11 (D10) | `REED1` | Pull-up, switch to GND |
| Reed switch cell 2 | GPIO_Input (or EXTI12) | PA12 (D2) | `REED2` | Pull-up, switch to GND |
| LED cell 1 – green | GPIO_Output | PA9 (D1) | `LED1_G` | Push-pull, low speed |
| LED cell 1 – red | GPIO_Output | PA10 (D0) | `LED1_R` | Push-pull, low speed |
| LED cell 2 – green | GPIO_Output | PB0 (D3) | `LED2_G` | Push-pull, low speed |
| LED cell 2 – red | GPIO_Output | PB1 (D6) | `LED2_R` | Push-pull, low speed |
| Status / heartbeat | GPIO_Output | PB3 (on-board LD3) | `STATUS` | Optional |
| Debug | SYS Serial Wire | PA13 SWDIO, PA14 SWCLK | – | Reserved |

IR sensors use A0–A3 so they can be switched to ADC inputs later without rewiring.

### Pins that must stay unconfigured

- **PA5, PA6 (A4/A5)**: shorted to PB7/PB6 by solder bridges SB16/SB18 on the Nucleo-32. Using them would break I2C.
- **PF0, PF1 (D7/D8)**: tied to the ST-LINK MCO / oscillator.

## Clock (RCC)

- HSI 8 MHz → PLL source HSI/2 → ×16 → **SYSCLK 64 MHz**
- AHB /1, **APB1 /2** (32 MHz, max 36 MHz), APB2 /1
- APB1 timer clock = 64 MHz
- I2C1 clock source: HSI or SYSCLK (CubeMX computes the TIMING value)

## TIM3 – SG90 servos (50 Hz PWM)

| Parameter | Value |
|---|---|
| Clock source | Internal (64 MHz) |
| Prescaler | 63 → 1 MHz tick (1 µs) |
| Counter period (ARR) | 19999 → 20 ms / 50 Hz |
| auto-reload preload | Enable |
| CH1, CH2 mode | PWM mode 1, OC preload Enable |
| Initial pulse | 1500 (centre) |

Angle is set by the compare value, ~1000–2000 µs (some SG90 need 500–2500).

## TIM6 – 1 ms tick (optional)

Prescaler 63, Period 999, update interrupt enabled. Used for reed switch debouncing,
IR sampling/filtering and I2C timeouts.

## NVIC priorities

| Interrupt | Source | Priority |
|---|---|---|
| USART2 global | PC commands (RX) | 1 |
| EXTI9_5 | M24SR GPO (PA8) | 2 |
| TIM6_DAC | 1 ms tick | 3 |
| EXTI15_10 | Reed switches (only if EXTI used) | 3 |

I2C1 interrupts stay disabled – M24SR communication is done by polling.

## Wiring notes

- **IR modules → 3.3 V supply, not 5 V.** PA0, PA1, PA3 are not 5 V tolerant; a 5 V-powered module
  would drive 5 V into them. FC-51 style modules work at 3.3 V.
- **SG90 servos → separate 5 V supply** (up to ~0.7 A stall each), **common GND** with the Nucleo.
  3.3 V PWM signal is normally sufficient.
- **I2C pull-ups:** if the MB1161 board has none on SDA/SCL, add 4.7 kΩ to 3.3 V.
- **M24SR board on breadboard:** connect 3V3, GND, SDA, SCL, GPO, RF_DIS (optional).
- **Reed switches:** one side to the MCU pin, the other to GND (internal pull-up → closed door reads Low).
- **LEDs:** MCU pin → 150–510 Ω resistor → LED anode, cathode to GND.

Unconnected parts are harmless: inputs read High thanks to pull-ups, PWM outputs run with nothing attached.
