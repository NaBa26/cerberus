# Cerberus: Secure Bootloader & Threat Validation

An industrial-grade secure bootloader implementation and validation suite for the **STM32F401RE**. 

Built on **Zephyr RTOS** and **MCUboot**, Cerberus is designed to establish a hardware root of trust and actively validate system resilience against downgrade attacks, memory boundary breaches, and physical-layer power tearing.

## 🎯 Core Objectives
This repository is divided into two phases: Integration and Validation.

1. **Hardware Root of Trust:** Implementing ECDSA-P256 cryptographic signature verification.
2. **Anti-Rollback Validation:** Scripting downgrade attacks to verify MCUboot security counters.
3. **Power-Tear Resilience:** Validating successful image fallback during 10%, 50%, and 90% simulated power loss during flash sector swapping.
4. **Boundary Isolation:** Proving the application layer cannot overwrite Bootloader flash sectors (Sector 0-3) via MPU/WRP hardware faults.

## 🛠️ Hardware & Tech Stack
* **Microcontroller:** STM32F401RE (Nucleo-F401RE)
* **Operating System:** Zephyr RTOS
* **Bootloader:** MCUboot
* **Cryptography:** tinycrypt / mbedTLS (ECDSA-P256, SHA-256)
* **Toolchain:** GCC ARM Embedded (Zephyr SDK), CMake, Ninja, Python (imgtool)

## 📁 Repository Structure

```text
cerberus_secure_boot/
├── sysbuild/                # Meta-build configurations for compiling MCUboot alongside the app
├── keys/                    # (Generated locally) ECDSA-P256 private/public keypairs
├── src/                     # Main application and fault-injection payloads
│   └── main.c
├── app.overlay              # Hardware Device Tree: STM32 physical flash sector mapping
├── prj.conf                 # Kconfig: Zephyr OS subsystem switches
├── sysbuild.conf            # Sysbuild toggle for MCUboot
└── README.md
```

## 🚀 Phase 1: Toolchain & Environment Setup

This project requires a Linux environment (Ubuntu or WSL2). Do not build natively on Windows.

### 1. System Dependencies
```bash
sudo apt update
sudo apt install --no-install-recommends git device-tree-compiler wget xz-utils file make gcc g++
pip install cmake ninja west imgtool
```

### 2. Initialize the Workspace
This project is built out-of-tree. Initialize Zephyr and pull the cryptographic dependencies:
```bash
west init -l cerberus_secure_boot
west update
west zephyr-export
pip install -r ../zephyr/scripts/requirements.txt
```

### 3. Install Zephyr SDK (ARM Cross-Compiler)
Download and configure the Zephyr SDK (`v0.16.5-1` or latest) in your home directory:
```bash
cd ~
wget [https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.5-1/zephyr-sdk-0.16.5-1_linux-x86_64.tar.xz](https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.5-1/zephyr-sdk-0.16.5-1_linux-x86_64.tar.xz)
tar xvf zephyr-sdk-0.16.5-1_linux-x86_64.tar.xz
cd zephyr-sdk-0.16.5-1
./setup.sh
```

## 🚧 Phase 2: Build & Validation (In Progress)
*Documentation for compiling, generating keys, flashing via sysbuild, and executing the automated fault-injection Python scripts will be added here upon completion of Phase 1.*
