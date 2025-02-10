# 1. 参考

https://blog.csdn.net/zjuwwj/article/details/145497957

# 2. 导出已安装插件列表

```bash
code --list-extensions > extensions.txt
```

# 3. 在另一台设备上安装这些插件

```
# 在 macOS/Linux 系统上
cat extensions.txt | xargs -L 1 code --install-extension

# 在 Windows PowerShell 上
Get-Content extensions.txt | ForEach-Object { code --install-extension $_ }
```
