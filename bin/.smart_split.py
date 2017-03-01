#!/usr/bin/env python3

import i3ipc

if __name__ == '__main__':

    conn = i3ipc.Connection()

    focused = conn.get_tree().find_focused()
    parent_layout = focused.parent.layout

    if focused.rect.width * 0.75 > focused.rect.height and parent_layout != 'splith':
        conn.command('split horizontal')
    elif focused.rect.width * 0.75 < focused.rect.height and parent_layout != 'splitv':
        conn.command('split vertical')
