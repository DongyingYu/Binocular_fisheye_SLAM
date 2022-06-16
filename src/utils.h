/**
 * @file utils.h
 * @author Dongying (yudong2817@sina.com)
 * @brief 工具函数
 * @version 1.0
 * @date 2022-04-27
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

void loadImages(const std::string &path, const std::string &file_name, std::vector<std::string> &left_image_path,
                std::vector<std::string> &right_image_path, std::vector<double> &timestamps);