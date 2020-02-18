#!/usr/bin/env python3

import asyncio
import signal
import sys

class Capture:

    def __init__(self, intfs):
        self.intfs = intfs

    # Need to handle namespaces
    async def create_capture_process(self, intf, pcap):
        proc = await asyncio.create_subprocess_exec(
            'tcpdump', '-Q', 'in', '-p', '-i', intf, '-w', pcap,
            stdout=asyncio.subprocess.DEVNULL,
            stderr=asyncio.subprocess.DEVNULL,
        )
        return proc

    async def start(self):
        self.procs = [ await self.create_capture_process(
            intf,
            f'/tmp/{intf}.pcap'
        ) for intf in self.intfs]
        return

    async def stop(self):
        for proc in self.procs:
            proc.terminate()
        for proc in self.procs:
            await proc.wait()
        return


async def main():
    capture = Capture(['wlp3s0', 'enp0s25'])
    await capture.start()
    await asyncio.sleep(5)
    await capture.stop()
    return


if __name__ == "__main__":
    loop = asyncio.get_event_loop()
    task = loop.create_task(main())
    loop.run_until_complete(task)
    loop.close()
    sys.exit(0)


