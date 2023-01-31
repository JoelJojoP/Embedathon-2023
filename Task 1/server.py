import asyncio
import websockets
import faker 
import numpy as np

async def send_messages(websocket):
    while True:
        arr = np.random.randint(0, 100, 100)
        n = np.random.randint(0, 2)
        if n == 0:
            mes = str(arr)
        else:
            info = []
            info.append(faker.Faker().name())
            info.append(faker.Faker().address())
            info.append(faker.Faker().email())
            mes = str(info)
        await websocket.send(mes)
        await asyncio.sleep(1)

async def receive_messages(websocket):
    while True:
        message = await websocket.recv()
        print(f"{message}")

async def server(websocket, path):
    try:
        send_task = asyncio.create_task(send_messages(websocket))
        receive_task = asyncio.create_task(receive_messages(websocket))
        await asyncio.gather(send_task, receive_task)
    except websockets.exceptions.ConnectionClosedOK:
        print("A client has disconnected")

async def main():
    async with websockets.serve(server, "localhost", 8000):
        await asyncio.Future()

try:
    asyncio.run(main())
except KeyboardInterrupt:
    print("\nClosing Server...")