#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <openssl/sha.h>
#include <sstream>
#include <string>

using namespace std;
namespace fs = std::filesystem;

string compute_sha256(const fs::path &filepath) {
  FILE *file = fopen(filepath.string().c_str(), "rb");
  if (!file) {
    cerr << "无法打开文件: " << filepath << endl;
    return "";
  }

  SHA256_CTX sha256;
  SHA256_Init(&sha256);

  unsigned char buffer[4096];
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
    SHA256_Update(&sha256, buffer, bytes_read);
  }

  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_Final(hash, &sha256);
  fclose(file);

  stringstream ss;
  ss << hex << setfill('0');
  for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
    ss << setw(2) << static_cast<int>(hash[i]);
  }

  return ss.str();
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cerr << "用法: " << argv[0] << " <输入目录> <输出文件>" << endl;
    return 1;
  }

  fs::path input_dir(argv[1]);
  fs::path output_file(argv[2]);

  if (!fs::exists(input_dir) || !fs::is_directory(input_dir)) {
    cerr << "无效的输入目录: " << input_dir << endl;
    return 1;
  }

  ofstream outfile(output_file);
  if (!outfile) {
    cerr << "无法创建输出文件: " << output_file << endl;
    return 1;
  }

  try {
    for (const auto &entry : fs::recursive_directory_iterator(input_dir)) {
      if (entry.is_regular_file()) {
        fs::path filepath = entry.path();
        string hash = compute_sha256(filepath);

        if (!hash.empty()) {
          outfile << hash << "  "
                  << filepath.lexically_relative(input_dir).string() << endl;
        }
      }
    }
  } catch (const exception &e) {
    cerr << "处理过程中发生错误: " << e.what() << endl;
    return 1;
  }

  cout << "SHA256哈希计算完成，结果已保存至: " << output_file << endl;
  return 0;
}