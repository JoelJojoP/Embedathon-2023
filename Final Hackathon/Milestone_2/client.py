import asyncio
import websockets

async def client():
    async with websockets.connect("") as websocket:
        while True:
            greeting = await websocket.recv()
            print(greeting)

asyncio.run(client())
