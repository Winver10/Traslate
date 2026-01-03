# Traslate - 待办事项管理器

一个简单的命令行待办事项管理应用程序，支持添加、编辑、删除和查看待办事项。

## 功能特性

- 添加待办事项
- 编辑现有待办事项
- 删除待办事项
- 查看待办事项列表
- 数据持久化保存到文件

## 构建说明

### Windows
使用Visual Studio打开 `Traslate.sln` 解决方案文件。

### Linux/macOS
使用以下命令编译：
```bash
make
```
或
```bash
g++ -std=c++11 Source.cpp comandProcesser.cpp -o traslate
```

## 使用方法

运行程序后，您可以使用以下命令：

- `add [内容]` - 添加新的待办事项
- `edit [编号] [新内容]` - 编辑指定编号的待办事项
- `del [编号]` - 删除指定编号的待办事项
- `exit` - 退出程序

## 文件结构

- `Source.cpp` - 主程序文件，包含主要逻辑
- `comandProcesser.cpp` - 命令处理逻辑
- `getInput.hxx` - 输入处理函数声明
- `Makefile` - 构建脚本（Linux/macOS）

## 技术特点

- 面向对象设计
- 跨平台支持
- 数据持久化
- 错误处理机制