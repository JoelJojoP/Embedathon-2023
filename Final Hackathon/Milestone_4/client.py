import asyncio
import websockets
import keyboard
import mouse

async def client():
    while True:
        try:
            async with websockets.connect("ws://192.168.36.211:80") as websocket:
                while True:
                    info = await websocket.recv()
                    print(info)
                    if info == 'Button Pressed':
                        mouse.click()
                        print("Clicked")
                    else:
                        info = info.split(',')
                        x = info[0].split(':')
                        y = info[1].split(':')
                        z = info[2].split(':')
                        x = float(x[1])
                        y = float(y[1])
                        z = float(z[1])
                        if x > 30:
                            keyboard.press_and_release('d')
                        elif x < -30:
                            keyboard.press_and_release('a')
                        if y > 30:
                            keyboard.press_and_release('w')
                        elif y < -30:
                            keyboard.press_and_release('s')
        except websockets.exceptions.ConnectionClosedError:
            print("....")
            await asyncio.sleep(0.1)

try:
    asyncio.run(client())
except KeyboardInterrupt:
    print("Client Disconnected")