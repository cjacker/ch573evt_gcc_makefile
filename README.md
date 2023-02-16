# ch57x riscv ble evt with gcc and makefile support

This is pre-converted ch57x riscv ble evt firmware library with gcc and makefile support from WCH official CH573EVT.ZIP. 

It is converted by [ch5xx_riscv_ble_evt_makefile_gcc_project_template](https://github.com/cjacker/ch5xx_riscv_ble_evt_makefile_gcc_project_template)

This firmware library support below parts from WCH:

- ch573
- ch571

The default part is set to 'ch573', you can change it with `./setpart.sh <part>`. the corresponding 'Link.ld' will update automatically from the template.

The default 'User' codes is not BLE related, just blink a LED on [WeAct ch5xx ble board](https://github.com/WeActStudio/WeActStudio.WCH-BLE-Core). all evt examples shipped in original EVT package provided in 'Examples' dir.

To build the project, type `make`.
