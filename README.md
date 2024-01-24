<h1 align="center">
	✏️ minitalk
</h1>

## 💡 About the project

> This project is using UNIX signals to make 2 programs communicate.

## 🛠️ Usage

### Requirements

The project is written in the C language and requires the **`gcc` compiler** and the standard **C libraries** to run.

### Instructions

**1. Compiling minitalk**

To compile, go to the project folder and run :

```shell
$ make
```

**2. Using it**

To use minitalk :

```C
./server //Start the server
```
The server is showing its PID.
```C
./client serverPID "Your message" //Start the client
```
