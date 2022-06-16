/**
 * @file frame.h
 * @author Dongying (yudong2817@sina.com)
 * @brief
 * @version 1.0
 * @date 2022-04-26
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>
#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <opencv2/core/core.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

class Frame
{
public:
    using Ptr = std::shared_ptr<Frame>;

    Frame();
};
