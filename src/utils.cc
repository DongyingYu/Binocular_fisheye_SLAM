/**
 * @file utils.cc
 * @author Dongying (yudong2817@sina.com)
 * @brief
 * @version 1.0
 * @date 2022-04-27
 * @copyright Copyright (c) 2022
 *
 */

#include "utils.h"

/**
 * @brief 加载图像信息
 * @param[in] 图像文件夹路径
 * @param[in] 图像数据及检索文件
 * @param[out] 左目图像存储容器
 * @param[out] 右目图像存储容器
 * @param[out] 时间戳储容器
 */
void loadImages(const std::string &path, const std::string &file_name, std::vector<std::string> &left_image_path,
                std::vector<std::string> &right_image_path, std::vector<double> &timestamps)
{
    std::ifstream image_index;
    std::cout << "[INFO]: The address of path : " << path << std::endl;
    std::cout << "[INFO]: The name of index file : " << file_name << std::endl;

    // 因为open()成员函数是一个char*类型的参数，故需要将string转换为char
    image_index.open(file_name.c_str());
    left_image_path.reserve(6000);
    right_image_path.reserve(6000);
    timestamps.reserve(6000);

    while (!image_index.eof())
    {
        std::string str;
        std::string str_temp;
        // 读取这一行的数据，以换行标志为结束符进行读取，可以手动指定
        getline(image_index, str);
        if (!str.empty())
        {
            // std::cout << "[INFO]: The value of s : " << str << std::endl;
            std::stringstream ss;
            ss << str;
            // std::cout << "[INFO]: The value of ss : " << ss.str() << std::endl;
            if(ss.str()[0] == '#'){
                std::cout << "[INFO]: skip current time. " << std::endl;
                std::cout << "[INFO]: The value of ss : " << ss.str() << std::endl;
                continue;
            }

            ss >> str_temp;
            int pos = str_temp.find_last_of(',');
            std::string dir = str_temp.substr(0, pos);
            // std::cout << "[INFO]: The value of str_temp : " << dir << std::endl;
            left_image_path.push_back(path + "/cam0/data/" + dir + ".png");
            right_image_path.push_back(path + "/cam1/data/" + dir + ".png");
            double t = std::stof(dir);
            timestamps.push_back(t / 1e9);
        }
    }
    std::cout << "[INFO]: Path value : " << left_image_path[0] << std::endl;
    std::cout.precision(16);
    std::cout << "[INFO]: The value of timestamps : " << timestamps[0] << std::endl;
}