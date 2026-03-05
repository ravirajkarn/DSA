#ifndef _SELECTION_SORT_
#define _SELECTION_SORT_

#include <vector>

std::vector<int> secsort(std::vector<int> &rawData){
    bool isSorted = false;
    // while(!isSorted){
    for (int i = 0, small_value; i < rawData.size(); i++)
    {
        // int i = 0, 
        small_value = i;
        for (int j = 0; j < rawData.size(); j++)
        {
            if (rawData.at(small_value) > rawData.at(j))
            {
                isSorted = false;
                small_value = j;
            }
            else if (i == rawData.size() && j == rawData.size() && isSorted == false)
                isSorted = false;
            
        }

        rawData.at(small_value) = rawData.at(small_value) + rawData.at(i);
        rawData.at(i) = rawData.at(small_value) - rawData.at(i);
        rawData.at(small_value) = rawData.at(small_value) - rawData.at(i); 
    }
    
    // fmt::print("unordered list: ");
    // for (const auto& element : rawData)
    // {
    //     fmt::print(" {} ", element);
    // }
    
    return rawData;
}


#endif
