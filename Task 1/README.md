# Task 1

## Problem Statement

Write a program for a server and a client in python with the following features:

1. The server is able to handle multiple concurrent connections. It should be able to print any message that comes from any one of its clients.
2. The client is able to log the messages recieved from the server and send a message with the time taken to recieve one block of arbitary number of messages to the server.

## Solution

The ```server.py``` is the code for the server. The features implemented in the server are:

1. Handle concurrent connections.
2. Send randomised user information using ```Faker``` and random arrays using ```numpy```.
3. Recieve messages from connected clients and print them on the console.
4. Clients disconnecting from the server is detected and a message is printed on the console.
5. Smooth stopping of server without throwing any errors.

The ```client.py``` is the code for the client. The features implemented in the client are:

1. Recieve a particular message from the server. (The client can either recieve the user information or the numpy array or both from the server).
2. Log the messages recieved along with the timestamp into the console.
3. Send message to the server with the time taken for recieving 1 block of 5 messages.
4. Reconnect back to the server incase the server stops for any reason.
5. Smoothly disconnect from the server.

## User Guide

Since this task uses the ```Faker```,  ```datetime``` and ```numpy``` modules, we need to install them by ruuning these commands in the terminal:

```bash
pip install Faker
pip install numpy
pip install datetime
```

Open a terminal and navigate to the Task 1 directory in the repo. First, start the server by running the following command in the terminal:

```bash
python3 server.py
```

Then in a new terminal start the client by running the following command in the terminal:

```bash
python3 client.py
```

## Modules Used

### websockets
Used for socket programming

### asyncio
Used for asynchronous operations.

### time
Used for calculating the time taken for recieving blocks of messages.

### Faker
Used for generating random user information in server for sending it to client.

### numpy
Used for generating random integer arrays.

### datetime
Used for getting the current time for the timestamp in the log output

## Approach

The server and client programs uses concurrent communication. This is done by using the function ```asycnio.gather()```. The reconnecting mechanism in the client is done by using ```try``` and ```except``` statements. When the client gets disconneted, it will go into a loop till it reconnects back to the server. ```KeyboardInterrupt``` is handelled for smooth stopping of both client and server.

## Output

https://user-images.githubusercontent.com/97270737/215691106-2e92ca30-a7ae-4b1f-b16f-66c6e10b1028.mp4
