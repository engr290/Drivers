# USART
USART is a point-to-point communication protocol where two devices first establish a communication rate before transmitting data byte by byte.
The ATmega328P features dedicated USART hardware, eliminating the need for timers to configure the baud rate.
# USART Registers
- UBRR0H
- UBRR0L
- UCSR0A
- UCSR0B
- UCSR0C
- UDR0

# UBRR0H and UBRR0L
These registers set the baud rate (communication speed) for UART.
Calculation formula:

$$
UBRR = \left( \frac{16\ \text{MHz}}{16 \times \text{baudrate}} \right) - 1
$$

# UCSR0A

| Bit | Description | Name |
| --- | ----------- | ---- |
| 7 | RX Complete	| RXC0 |
| 6 | TX Complete	| TXC0 |
| 5 | Data Register Empty	| UDRE0 |
| 4 | Frame Error	| FE0 |
| 3 | Data Overrun | DOR0 | 
| 2 | Parity Error | UPE0 |
| 1 | Double Speed Mode	| U2X0 |
| 0 | Multi-Processor Mode | MPCM0 |

- RX Complete: 1 when new byte is received **Must be checked before reading UDR0**
- TX Complete: 1 when data is sent
- Data Register Empty: 1 when UDR0 is empty and ready for new data. 

# UDR0 (USART Data Register)
Used to send and receive data. One byte can be written or read from it at a time.

**Before reading wait for RXC0 to be 1.**

**Before writing wait for UDRE0 to be 1.**

# UCSR0B

| Bit | Description | Name |
| --- | ----------- | ---- |
| 7 | RX Interrupt Enable | RXCIE0 |
| 6 | TX Interrupt Enable | TXCIE0 |
| 5 | Data Register Empty Interrupt | UDRIE0 |
| 4 | Receiver Enable | RXEN0 |
| 3 | Transmitter Enable | TXEN0 |
| 2 | Character Size Bit 2 | UCSZ02 |
| 1 | RX 9th Bit | RXB80 |
| 0 | TX 9th Bit | TXB80 |  

# UCSR0C

| Bit | Description | Name |
| --- | ----------- | ---- |
| 7-6 | Mode Select	| UMSEL0 |
| 5-4 | Parity Mode	| UPM0 |
| 3 | Stop Bit Select | USBS0 | 
| 2-1 | Character Size | UCSZ0 |
| 0 | Clock Polarity | UCPOL0 |


