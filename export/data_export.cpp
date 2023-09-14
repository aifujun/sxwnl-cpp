
#include <ctime>
#include <iostream>
#include <array>
#include <chrono>
#include <fstream>
#include <windows.h>

#include "../mylib/tool.h"
#include "../lunar/lunar.h"
#include "../lunar/lunar_ssq.h"
#include "../eph/eph_show.h"
#include "../eph/eph0.h"
#include "../eph/eph.h"
#include "../mylib/lat_lon_data.h"
#include "../mylib/tool.h"
#include "../mylib/math_patch.h"
#include "../mylib/mystl/static_array.h"
#include "../mylib/mystl/map.h"

#define MAP_H 18
#define MAP_W  7
std::array<std::array<mystl::string,MAP_W>,MAP_H> strmap;


void initialize() {
//    SetConsoleOutputCP(CP_UTF8);
    system("@chcp 65001");

    // 农历基础
    init_ob();
}


int export_data(const std:: string &export_file) {
    std::ofstream stream;
    stream.open(export_file, std::ofstream::app);

    for (int i = -4712; i <= 0; i++) {
        stream << "year: ";
        stream << (i - 1);
        stream << std::endl;
        stream << export_nian_li(i);
    }

    stream << "-------------------------";
    stream << std::endl;

    for (int i = 1; i <= 10000; i++) {
        stream << "year: ";
        stream << i;
        stream << std::endl;
        stream << export_nian_li(i);
    }

    stream.close();
    return 0;
}


void test(int year = 2023) {
    std::cout << "\033[31m" << "year: " << year << "\033[0m" << std::endl;

    std::cout << export_nian_li(year) << std::endl;
    std::cout << nianLiSTR(year) << std::endl;

}


int main(int argc, char **argv) {

    initialize();

    std::string path = __FILE__;
    std::string export_file = path.substr(0, path.find_last_of('/')).append("/lunar_data.txt");

    std::cout << "Export file: " << export_file << std::endl;

    export_data(export_file);

    test(2023);

    path.clear();
    export_file.clear();
    return 0;
}

