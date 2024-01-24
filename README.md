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

Start the server :

```shell
./server //Start the server
```
The server is showing its PID, so you need to use it to send a message to the server from the client like this :
```shell
./client serverPID "Your message" //Start the client
```
