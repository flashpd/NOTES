建议使用`python -m`安装，而不是`apt install`

```bash
sudo python3 -m pip install --upgrade --force-reinstall pip
```

这样在终端就能使用`pip3`指令，如果是使用`apt`指令进行安装，则安装的是低版本的，再次升级后，`pip3`指令可能会找不到（变成`pip`指令了）