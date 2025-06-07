// 数字宏定义
// 定义中文数字对应的数值
#define 零 0
#define 壹 1
#define 贰 2
#define 叁 3
#define 肆 4
#define 伍 5
#define 陆 6
#define 柒 7
#define 捌 8
#define 玖 9
#define 拾 10
#define 佰 100
#define 仟 1000
#define 万 10000

// 运算符宏定义
// 定义中文运算符对应的符号
#define 加 +
#define 加等于 +=
#define 减 -
#define 减等于 -=
#define 乘 *
#define 乘等于 *=
#define 除 /
#define 除等于 /=
#define 模 %
#define 逻辑非 ~
#define 逻辑与 &
#define 逻辑与等于 &=
#define 逻辑或 |
#define 逻辑或等于 |=
#define 逻辑异或 ^
#define 逻辑异或等于 ^=
#define 逻辑左移 <<
#define 逻辑左移等于 <<=
#define 逻辑右移 >>
#define 逻辑右移等于 >>=
#define 非 !
#define 与 &&
#define 或 ||
#define 等于 ==
#define 不等于 !=
#define 大于 >
#define 大于等于 >=
#define 小于 <
#define 小于等于 <=

// 赋值宏定义
// 定义中文赋值操作符
#define 赋值 =
#define 自增 ++
#define 自减 --

// 标点符号宏定义
// 定义中文标点符号对应的符号
#define 逗号 ,
#define 分号 ;
#define 冒号 :
#define 左大括号 {
#define 右大括号 }
#define 左小括号 (
#define 右小括号 )
#define 左中括号 [
#define 右中括号 ]

// 关键字宏定义
// 定义中文关键字对应的C++关键字
#define 类 class
#define 结构体 struct
#define 公有 public
#define 私有 private
#define 保护 protected
#define 静态 static
#define 友元 friend
#define 常量 const
#define 空 void
#define 新的 new
#define 删除 delete
#define 返回 return
#define 如果 if
#define 否则 else
#define 否则如果 else if
#define 循环 for
#define 使用 using
#define 命名空间 namespace
#define 主函数 main

// 类型宏定义
// 定义中文类型对应的C++类型
#define 整型 int
#define 短 short
#define 长 long
#define 长长 long long
#define 浮点 float
#define 双浮点 double
#define 长双浮点 long double
#define 无符号 unsigned
#define 字符串 std::string
#define 真假 bool

// 指针和引用宏定义
// 定义中文指针和引用操作符
#define 指针 *
#define 指针符号 *
#define 引用符号 &
#define 空指针 nullptr
#define 解引用 *
#define 遍历 :
#define 的 .
#define 运算符解引用 operator*
#define 运算符自增 operator++

// 杂项宏定义
// 定义其他常用的中文宏
#define 输出 std::cout
#define 输出流 <<
#define 输入 std::cin
#define 输入流 >>
#define 标准 std
#define 换行 std::endl
#define 结束 end
#define 开始 begin
#define 箭头 ->
#define 这个 this
#define 真 true
#define 空格 " "
#define 逻辑非等于 ~ =
#define 运算符不等于 operator!=
#include <iostream>
结构体 点 左大括号
  无符号 长长 数据 分号
  点 指针 下一个 分号
  点 左小括号 无符号 长长 数据 右小括号 遍历 数据 左小括号 数据 右小括号 逗号 下一个 左小括号 空指针 右小括号 左大括号 右大括号 
右大括号 分号

类 链表 左大括号
  私有 冒号
    点 指针 头 分号
    点 指针 尾 分号
  公有 冒号
    链表 左小括号  右小括号  冒号 头 左小括号 空指针 右小括号 逗号 尾 左小括号 空指针 右小括号  左大括号 右大括号
    空 添加 左小括号 无符号 长长 数据 右小括号  左大括号
      点 指针 新节点 赋值 新的 点 左小括号 数据 右小括号 分号
      如果  左小括号 头 等于 空指针 右小括号  左大括号
        头 赋值 新节点 分号
        尾 赋值 新节点 分号
        返回 分号
      右大括号
      尾 箭头 下一个 赋值 新节点 分号
      尾 赋值 新节点 分号
    右大括号
    空 删除点 左小括号  右小括号  左大括号
      点 指针 临时 赋值 头 分号
      如果  左小括号 头 不等于 空指针 右小括号  左大括号
        头 赋值 头 箭头 下一个 分号
        删除 临时 分号
        临时 赋值 头 分号
      右大括号
    右大括号
    类 迭代器 左大括号
      私有 冒号
        点 指针 数据 分号
      公有 冒号
        迭代器 左小括号 点 指针 数据 右小括号  遍历 数据 左小括号 数据 右小括号  左大括号 右大括号
        真假 运算符不等于 左小括号 迭代器 其他 右小括号  左大括号 返回 数据 不等于 其他 的 数据 分号 右大括号
        迭代器 运算符自增 左小括号  右小括号  左大括号
          数据 赋值 数据 箭头 下一个 分号
          返回 解引用 这个 分号
        右大括号
        无符号 长长 运算符解引用 左小括号  右小括号  左大括号 返回 数据 箭头 数据 分号 右大括号
    右大括号 分号
    迭代器 开始 左小括号  右小括号  左大括号 返回 迭代器 左小括号 头 右小括号  分号 右大括号
    迭代器 结束 左小括号  右小括号  左大括号 返回 迭代器 左小括号 空指针 右小括号  分号 右大括号
右大括号 分号
整型 主函数 左小括号  右小括号  左大括号
  链表 甲 分号
  循环  左小括号 无符号 长长 某 赋值 零 分号 某 小于 仟 分号 某 自增 右小括号 
    甲.添加 左小括号 某 右小括号  分号
  循环  左小括号 无符号 长长 某 遍历 甲 右小括号 
    输出 输出流 某 输出流  空格  分号
  返回 零 分号
右大括号