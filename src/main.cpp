#include <algorithm>
#include <ios>
#include <iostream>
#include <fmt/core.h>
#include <fmt/format.h>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

// First time renaming  a namesapce... neat :)
namespace fs = std::filesystem;

// Current path, refrence to total count , rererence to list of ignores
void get_count(std::string path,int *count, std::vector<char*> *ignores)
{
    
    for (auto i : *ignores)
    {
        // if no no's appear in path. reject
        if (path.find(i) != std::string::npos)
        {
            fmt::println("Skipping {}",i );
            return;
        }
    }

    // Got a folder 
    if (fs::is_directory(path)){

        for (const auto& entry : fs::directory_iterator(path)) {
            get_count(std::string(path).append("/").append(entry.path().filename()), count,ignores);
            continue;
        }
    }
    // Got a file
    else{
        // Doesn't need to be a pointer but i am too afraid to touch it now  
        std::fstream *current_file = new std::fstream();

        current_file->open(path,std::ios_base::in);

        if (!current_file->is_open())
        {
            fmt::println("{}: {}", "Failed to open file",path);
            return;
        }
        std::string line = "";

        int file_line_count = 0;

        while(std::getline(*current_file,line))
        {
            // If it's not move than four it doesn't count
            if (line.size() < 4)
                continue;
            file_line_count += 1;
        }
        *count += file_line_count;
        fmt::println("{} = {}",path,file_line_count);
        //std::cout << path <<  " = "<< file_line_count<<std::endl;
        
        current_file->close(); // Don't forget to close the file
        delete current_file; // Cleanup ;)
    }
}
int main(int argv, char** argc ) {
    // Total number of lines
    int line_count = 0;
    // Files /Folders to ignore
    std::vector<char*> ignores;
    // Skip over the executable call then store all ignorable directory
    for (int i = 1; i < argv;i++)
    {
        ignores.push_back(*(argc + i));
    }
    
    fmt::println("ignoring paths that include [{}]",fmt::join(ignores,","));

    // Get current directory
    std::string directoryPath = fs::current_path();


    try {
        // Recursive funtion starting from the current directory
        get_count(directoryPath, &line_count,&ignores);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Nice
    std::cout << "Total line count" <<  " = "<< line_count <<std::endl;
    return 0;
}
