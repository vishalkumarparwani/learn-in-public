import asyncio

async def task(name):
    print(f"{name} started")
    await asyncio.sleep(1)
    print(f"{name} finished")

async def main():
    await asyncio.gather(task("A"), task("B"))

asyncio.run(main())