#include <fstream>
#include <sstream>
#include <iomanip>
#include "src/generated/cpp/SearchRequest.pb.h"
#include "src/generated/cpp/MyMessage.pb.h"

int main(int, char *[])
{
    std::string query("hello");

    SearchRequest *sr = new SearchRequest();
    sr->set_corpus(SearchRequest_Corpus_UNIVERSAL);
    sr->set_query(query);
    sr->set_page_number(2);
    sr->set_result_per_page(1);
    sr->set_i(MyMessage1_EnumAllowingAlias_UNKNOWN);

    std::string s = "中文";
    std::cout << s << std::endl;


    std::ofstream ofs("/tmp/sensor.data", std::ios_base::out | std::ios_base::binary);
    sr->SerializeToOstream(&ofs);

    std::string bytes = sr->SerializeAsString();
    const char *array = bytes.data();
    int size = bytes.size();

    for (int i = 0; i < size; ++i)
    {
        std::cout << std::setw(5) << std::setfill(' ') << array[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << std::setw(5) << std::hex << std::setfill(' ')  << (int) array[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << std::setw(5) << std::dec << std::setfill(' ')  << (int) array[i];
    }
    std::cout << std::endl;
    ofs.close();

}