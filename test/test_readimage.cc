#include <chrono>
#include <list>
#include <mutex>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/opencv.hpp>

#include "utils.h"

int main(int argc, char** argv){
    std::string path = "/media/bruce/Documents/Ubuntu_ROS_files/文件资料/数据集/TUM_VI/dataset-corridor1_512_16/mav0";
    std::string file_name = "/media/bruce/Documents/Ubuntu_ROS_files/文件资料/数据集/TUM_VI/dataset-corridor1_512_16/mav0/cam0/data.csv";

    std::vector<std::string> left_img_path_vec;
    std::vector<std::string> right_img_path_vec;
    std::vector<double> timestamp_vec;

    loadImages(path, file_name, left_img_path_vec,right_img_path_vec,timestamp_vec);

    int vec_size = left_img_path_vec.size();
    for(int i=0; i< vec_size; ++i){
        cv::Mat left_img = cv::imread(left_img_path_vec[i]);
        cv::Mat right_img = cv::imread(right_img_path_vec[i]);
        cv::Mat result;
        // 将两幅图像横向拼接
        cv::hconcat(left_img,right_img,result);

        cv::resize(result, result, {0, 0}, 0.5, 0.5);
        cv::imshow("result",result);
        cv::waitKey();
    }

    return 0; 
}