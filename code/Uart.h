#include <reg51.h>

void UART_Init() {
    SCON = 0x50;
    TMOD = 0x20;
    TH1 = 0xFD;
    TR1 = 1;
}

void UART_SendChar(char c) {
    SBUF = c;
    while (!TI);
    TI = 0;
}

char UART_ReceiveChar() {
    while (!RI);
    RI = 0;
    return SBUF;
}

void UART_SendString(char *str) {
    while (*str) UART_SendChar(*str++);
}

unsigned int UART_ReceiveUInt() {
    unsigned int value = 0;
    char c;
    while (1) {
        c = UART_ReceiveChar();
        UART_SendChar(c);
        if (c == '\r') break;  // End input on Enter key
        value = value * 10 + (c - '0');
    }
    return value;
}

void UART_SendUInt(unsigned int num) {
    char buffer[6];
    int i = 0;

    if (num == 0) {
        UART_SendChar('0');
        return;
    }

    while (num) {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i--) UART_SendChar(buffer[i]);
}
