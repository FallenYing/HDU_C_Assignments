# 翻译代码

- 完成《C Primer Plus》前九章的学习或其他方式的知识等价学习。

1. 完成 squares.c 中的任务，其中步骤 1-4 已经完成，通过阅读注释，完成各个函数的编写。

2. 我们提供了 squares_test.o，它有一个主函数该函数接受四个命令行参数 (size1,x_offset,y_offset,size2)。并使用这些参数调用你的 squares 函数，你可以编译你的代码并使其与这个对象文件连接起来以制作程序。

   ```bash
	gcc -o squares -Wall -Werror -std=gnu99 -pedantic squares.c squares_test.o
   ```

3. 然后你可以像这样运行它`./squares 4 1 2 3`这将会调用你的 square 函数，其中`size1=4`、`x_offset=1`、`y_offset=2`、`size2=3`。

4. 应该会产生类似的输出

   ```txt
      ####
      #  #
      #***
      #*#*
       ***
   ```

5. 我们提供了三个文件，显示三个输入的正确结果。文件以 ans\_开头 (然后在其名称中包含参数值。用\_分隔)

> For windows
>
> 请使用文件 main.o 而不是 squares_test.o
>
> gcc -o squares.exe -Wall -Werror -std=gnu99 -pedantic squares.c main.o
>
> 在命令行中使用.\squares.exe 4 1 2 3 即可
