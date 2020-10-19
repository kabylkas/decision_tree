#include "csv_ir.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

csv_ir::csv_ir(std::string csv_file_path) {
    std::ifstream in_csv(csv_file_path);
    if (!in_csv.is_open()) {
        throw std::runtime_error("Failed to open the file");
    }

    // read first line: col names
    std::string line, value;
    if (in_csv.good()) {
        std::getline(in_csv, line);
        std::stringstream col_ss(line);
        for (uint32_t i=0; std::getline(col_ss, value, ';'); ++i) {
            std::stringstream feat_ss(value);
            std::string col_name, col_category;
            std::getline(feat_ss, col_name, ':');
            std::getline(feat_ss, col_category, ':');

            this->feature_meta_data[i];
            this->feature_meta_data[i] = feature_meta_t(col_category, col_name);
        }
    }

    // read the data
    while (in_csv.good()) {
        std::getline(in_csv, line);
        std::stringstream col_ss(line);
        for (uint32_t i=0; std::getline(col_ss, value, ';'); ++i) {
            std::stringstream feat_ss(value);
            if (this->feature_meta_data[i].type == feature_t::CATEGORICAL) {
                this->int_to_categ[i];
                auto& categs = int_to_categ[i];
                if (this->int_to_categ[i].find())
            }
        }
    }
}

std::string csv_ir::get_cols() {
    std::stringstream ss;
    for (auto [num, feat] : this->feature_meta_data) {
        ss << num << " -> [" << feat.name << "]\n";
    }
    return ss.str();
}