/**
 * @file system.h
 * @author Dongying (yudong2817@sina.com)
 * @brief
 * @version 1.0
 * @date 2022-04-26
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <chrono>
#include <list>
#include <mutex>
#include <thread>
#include "frame.h"

class System
{
public:
    using Ptr = std::shared_ptr<System>;

    System();

    void insertNewImages(const cv::Mat &img_left, const cv::Mat &img_right);

    void run();
};
