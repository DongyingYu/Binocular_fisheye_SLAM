/**
 * @file config_parse.cc
 * @author Dongying (yudong2817@sina.com)
 * @brief
 * @version 1.0
 * @date 2022-04-27
 * @copyright Copyright (c) 2022
 *
 */

#include <config_parse.h>
#include <yaml-cpp/yaml.h>
#include <iostream>

template <typename T>
static void getValue(const YAML::Node &node, const std::string &key, T &value){
    if(!node){
        std::cout << "[ERROR]: input node is empty. " << std::endl;
    }
    if(!node[key]){
        // runtime_error为一个标准的异常处理类
        throw std::runtime_error("could not find key in node: " + key);
    }
    value = node[key].as<T>();
}


ConfigParse::ConfigParse(const std::string &config_yaml){
    YAML::Node node = YAML::LoadFile(config_yaml);
    if(!node){
        throw std::runtime_error("open yaml failed: " + config_yaml);
    }

    getValue<std::string>(node,"path", path_);
    getValue<std::string>(node,"file_name", file_name_);
}
