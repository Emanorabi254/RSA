# 🔐 RSA Cryptosystem with CRT and UART Communication 🚀

Welcome to the **RSA Cryptosystem** project! This project demonstrates a basic implementation of the RSA encryption and decryption algorithm using **C programming**, optimized with the **Chinese Remainder Theorem (CRT)** for efficient decryption. Additionally, it integrates **UART communication** for sending and receiving encrypted data, making it practical for embedded systems.

---

## 📂 Included Files

1. **`main.c`**  
   The main program that demonstrates the encryption, decryption (using CRT), and UART communication.  
2. **`rsa.h`**  
   A header file containing the RSA functions for key generation, encryption, and CRT-based decryption.  
3. **`uart.h`**  
   A header file for configuring and handling UART communication.  
4. **Proteus Project File**  
   A Proteus simulation demonstrating the RSA system in action, including hardware integration for testing.  

---

## 🛠️ Features

- **RSA Encryption and Decryption** 🔒  
  Securely encrypt and decrypt messages using the RSA algorithm.  

- **CRT Optimization** ⚡  
  Fast decryption process using the Chinese Remainder Theorem.  

- **UART Integration** 📡  
  Send and receive encrypted messages over UART communication.  

- **Proteus Simulation** 🛠️  
  Visualize and test the project in a real-world simulation environment.  

---

## 🌟 How It Works

1. **Key Generation** 🔑  
   The program generates public and private keys for RSA encryption.  

2. **Encryption** ✉️  
   Messages are encrypted using the RSA public key and sent via UART.  

3. **Decryption (with CRT)** 📥  
   Received messages are decrypted using the RSA private key with CRT for better efficiency.  

4. **Simulation** ⚙️  
   Test the project in Proteus, showcasing encryption, decryption, and UART communication in action.  

---

## ⚠️ Challenges in RSA Implementation on 8051

1. **Limited Memory**  
   The 8051 microcontroller has very limited RAM and program memory, which makes handling large numbers required in RSA operations challenging.

2. **Processing Power**  
   RSA computations, especially modular exponentiation and key generation, require significant processing power. The 8051's low clock speed makes these operations slower.

3. **Handling Large Integers**  
   The 8051 doesn't natively support large integers (e.g., 1024-bit or 2048-bit), so custom libraries or algorithms for arbitrary precision arithmetic are needed.

4. **UART Communication**  
   Efficiently managing the encryption/decryption process alongside UART communication requires careful timing and resource management to avoid bottlenecks.

5. **Optimization with CRT**  
   Using the **Chinese Remainder Theorem (CRT)** for decryption improves performance but requires additional programming complexity and memory resources.

6. **Debugging on Embedded Systems**  
   Debugging cryptographic algorithms on a hardware-constrained platform like the 8051 can be tricky, as errors are harder to trace due to limited debugging tools and unclear outputs.

---

## 🎯 Purpose

This project is created for educational purposes, providing a practical demonstration of:  
- Cryptographic principles with RSA.  
- Efficiency improvements using CRT.  
- UART communication for data exchange in embedded systems.  

---

## 📬 Contact  

Feel free to reach out for any questions or feedback!  

💻 **Author**: *Eman Orabi*  
📧 **Email**:  [Emanorabi254@gmail.com]  
🌐 **LinkedIn**:  [www.linkedin.com/in/eman-orabi254]  

---

✨ *Secure your communications, one byte at a time!* ✨

