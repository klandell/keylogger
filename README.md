# Yet Another OS X Key Logger

## Disclaimer
This key logger is for educational purposes only and should not be used with malicious intent.

## Notes
This key logger is designed to run once.  When execution starts, it will automatically remove its own executable.  Shutting down the computer or killing the process will stop key logging.  Additionally, this key logger can't be used to log keystrokes for password fields.

## Usage
```bash
$ git clone https://github.com/klandell/keylogger && cd keylogger
$ make
$ nohup `sudo ./keylogger` &
```
## Shutdown
```bash
$ sudo pkill -f keylogger
```
