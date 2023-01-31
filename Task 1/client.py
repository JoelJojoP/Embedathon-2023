import asyncio
import websockets
import time
import datetime

async def send_messages(websocket):
    global t_init
    global numbering
    while True:
        if numbering == 5:
            t_curr = time.time()
            await websocket.send(f"Client Recieved 5 messages in {t_curr - t_init}s time")
            numbering = 0
            t_init = time.time()
        await asyncio.sleep(0.5)

async def receive_messages(websocket):
    global numbering
    global choice
    while True:
        message = await websocket.recv()
        if message[1] == "\'" and choice == 1 or choice == 3:
            t = datetime.datetime.now().time()
            print(f"{t} -> {message}")
            numbering += 1
        elif message[1] != "\'" and choice == 2 or choice == 3:
            t = datetime.datetime.now().time()
            print(f"{t} -> {message}")
            numbering += 1

async def client():
    global t_init
    t_init = time.time()
    global numbering
    numbering = 0
    while True:
        try:
            async with websockets.connect("ws://localhost:8000") as websocket:
                send_task = asyncio.create_task(send_messages(websocket))
                receive_task = asyncio.create_task(receive_messages(websocket))
                await asyncio.gather(send_task, receive_task)
        except (websockets.exceptions.ConnectionClosed, ConnectionRefusedError):
            print("Reconnecting to Server...")
            await asyncio.sleep(1)

try:
    print("Starting Client...")
    print("Choose type of data to recieve:")
    print("1. User Data")
    print("2. Numpy Array")
    print("3. User Data + Numpy Array")
    global choice
    choice = int(input("Enter your choice: "))
    asyncio.run(client())
except KeyboardInterrupt:
    print("\nClosing Client...")