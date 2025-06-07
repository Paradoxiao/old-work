#include <iostream>
#include <string>
#include <windows.h>
int main() {
  std::cout
      << "我是 "
         "DeepSeek，很高兴见到你！\n我可以帮你写代码、读文件、写作各种创意内容"
         "，请把你的任务交给我吧~\n";
  std::string str;
  std::cin >> str;
  std::cout << "思考中……\n";
  Sleep(10000);
  std::cout << "已深度思考（用时10秒）\n服务器繁忙，请稍后再试。";
  return 0;
}