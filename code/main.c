#include <reg51.h>
#include "uart.h"
#include "rsa.h"

void main() {
    unsigned int p, q, n, phi, e, d, M, C;
    char choice;

    UART_Init();
    UART_SendString("\r\n========== RSA Cryptography System ==========\r\n");

    while (1) {
        // Input and Test for p
        do {
            UART_SendString("\r\nEnter value of p: ");
            p = UART_ReceiveUInt();
            if (!is_prime(p, 5)) {
                UART_SendString("\r\nResult: p is Composite. Please enter a prime number.\r\n");
            }
        } while (!is_prime(p, 5));
        UART_SendString("\r\nResult: p is Prime\r\n");

        // Input and Test for q
        do {
            UART_SendString("\r\nEnter value of q: ");
            q = UART_ReceiveUInt();
            if (!is_prime(q, 5)) {
                UART_SendString("\r\nResult: q is Composite. Please enter a prime number.\r\n");
            }
        } while (!is_prime(q, 5));
        UART_SendString("\r\nResult: q is Prime\r\n");

        // Compute n and phi(n)
        n = p * q;
        phi = compute_phi(p, q);
        UART_SendString("\r\nn: ");
        UART_SendUInt(n);
        UART_SendString("\r\nphi(n): ");
        UART_SendUInt(phi);

        // Find and display e
        e = find_e(phi);
        if (e != 0) {
            UART_SendString("\r\nChosen e: ");
            UART_SendUInt(e);
        } else {
            UART_SendString("\r\nError: No valid e found.\r\n");
        }

        // Calculate and display d (private key)
        d = mod_inverse(e, phi);
        UART_SendString("\r\nPrivate key d: ");
        UART_SendUInt(d);

        // Main loop to choose encryption or decryption
            UART_SendString("\r\n========== Choose Operation ==========\r\n");
            UART_SendString("1: Encrypt\r\n");
            UART_SendString("2: Decrypt\r\n");
            UART_SendString("Choice: ");
            choice = UART_ReceiveChar();
            UART_SendChar(choice); // Echo choice

            if (choice == '1') {
                // Encryption
                UART_SendString("\r\nEnter plaintext M (0 to n-1): ");
                M = UART_ReceiveUInt();
                if (M < n) {
                    C = mod_exp(M, e, n);
                    UART_SendString("\r\nCiphertext C: ");
                    UART_SendUInt(C);
                } else {
                    UART_SendString("\r\nError: M is too large for n.\r\n");
                }
            } else if (choice == '2') {
               // Decryption by CRT
									UART_SendString("\r\nEnter ciphertext C: ");
									C = UART_ReceiveUInt();
									M = decrypt_crt(C, d, p, q);
									UART_SendString("\r\nDecrypted plaintext M: ");
									UART_SendUInt(M);
            } else {
                UART_SendString("\r\nInvalid choice. Returning to main menu.\r\n");
                break; // Exit back to input new p and q
            }
		   					UART_SendString("\r\n=========================================");
		}
    }

