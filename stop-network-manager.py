#!/usr/bin/env python3

import asyncio
import configparser
import os.path
import sys


async def execute(cmd):
    proc = await asyncio.create_subprocess_shell(
        cmd,
        stdout=asyncio.subprocess.PIPE,
        stderr=asyncio.subprocess.PIPE,
        stdin=None)
    print(f'{cmd}')
    stdout, stderr = await proc.communicate()
    returncode = proc.returncode
    if returncode != 0:
        print(f'{stdout}')
        print(f'{stderr}')
    out = stdout.decode('utf-8').strip()
    return (returncode, out)


async def main():
    cfg = configparser.ConfigParser()
    nm_cfg = '/etc/NetworkManager/NetworkManager.conf'
    if os.path.exists(nm_cfg):
        cfg.read(nm_cfg)
        cfg['main']['configure-and-quit'] = 'true'
        with open(nm_cfg, 'w') as config_file:
            cfg.write(config_file)

    cmds = ['systemctl stop NetworkManager.service',
            'systemctl start NetworkManager.service',
            'systemctl status NetworkManager.service']
    for cmd in cmds:
        _, out = await execute(cmd)
        print(out)
    return


if __name__ == "__main__":
    loop = asyncio.get_event_loop()
    task = loop.create_task(main())
    loop.run_until_complete(task)
    loop.close()
    sys.exit(0)


