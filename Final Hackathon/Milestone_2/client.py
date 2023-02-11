import asyncio
import websockets

async def client():
    async with websockets.connect("ws://192.168.36.211:80") as websocket:
        while True:
            greeting = await websocket.recv()
            print(greeting)

asyncio.run(client())