/**
 * @file config_parse.h
 * @author Dongying (yudong2817@sina.com)
 * @brief
 * @version 1.0
 * @date 2022-04-27
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <string>

class ConfigParse
{
public:
    ConfigParse(const std::string &config_yaml);

public:
    std::string path_;
    std::string file_name_;
};