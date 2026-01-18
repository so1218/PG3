#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <thread>
#include <atomic>

enum TileType
{
    EMPTY = 0,
    BLOCK = 1,
};

class MapLoader
{
public:
    MapLoader() : isFinished_(false) {}

    ~MapLoader()
    {
        if (worker_.joinable()) 
        {
            worker_.join();
        }
    }

    void StartLoad(const std::string& filename)
    {
        worker_ = std::thread(&MapLoader::LoadCsvAsync, this, filename);
    }

    bool IsFinished() const 
    {
        return isFinished_;
    }

    void Draw()
    {
        if (worker_.joinable())
        {
            worker_.join();
        }

        for (const auto& row : mapData_) 
        {
            for (int tileID : row) 
            {
                switch (tileID)
                {
                case BLOCK:  std::cout << "■ "; break;
                default:     std::cout << "□ "; break;
                }
            }
            std::cout << "\n";
        }
    }

private:
    void LoadCsvAsync(std::string filename) 
    {
        std::ifstream file(filename);
        if (!file.is_open()) 
        {
            isFinished_ = true; 
            return;
        }

        std::string line;
        while (std::getline(file, line)) 
        {
            std::vector<int> row;
            std::stringstream ss(line);
            std::string cell;

            while (std::getline(ss, cell, ','))
            {
                try 
                {
                    row.push_back(std::stoi(cell));
                }
                catch (...)
                {
                   
                    row.push_back(EMPTY);
                }
            }
            mapData_.push_back(row);
        }

        file.close();
        isFinished_ = true;
    }

private:
    std::vector<std::vector<int>> mapData_;
    std::thread worker_;
    std::atomic<bool> isFinished_;
};

int main() 
{
    MapLoader loader;

    loader.StartLoad("blocks.csv");

    while (!loader.IsFinished()) 
    {
    }

    loader.Draw();

    return 0;
}